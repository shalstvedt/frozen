#define FUSE_USE_VERSION 26
#define _GNU_SOURCE

#include <libfrozen.h>
#include <fuse.h>
#include <string.h>
#include <time.h>

/* typedefs {{{ */
struct my_opts {
	char     *datadir;
};

typedef struct virtfs_item   virtfs_item;
typedef enum virt_type       virt_type;

enum virt_type {
	VIRTFS_DIRECTORY,
	VIRTFS_FILE,
	
	VIRTFS_INVALID = -1
};

struct virtfs_item {
	virtfs_item   *next;
	virtfs_item   *childs;
	
	virt_type      type;
	char          *name;
	char          *fullname;
	
	void          *userdata;
	
	// fs related
	struct stat    stat;
};

enum frozenfs_keys {
	KEY_HELP,
};

typedef enum frozen_type {
	CONFIG_FILE,

	BACKEND_HOLDER,
	BACKEND_IO
} frozen_type;

typedef struct frozen_userdata {
	frozen_type    type;
	backend_t     *backend;
	
	// callbacks
} frozen_userdata;

typedef struct frozen_fh {
	virtfs_item     *item;
	frozen_userdata *ud;
	char            *param;
} frozen_fh;

/* }}} */
/* global variables {{{ */
static struct my_opts opts;

backend_t     *backend, *backend2;
unsigned int   cnt_unnamed = 0;

virtfs_item  virtfs = {
	.next       = NULL,
	.childs     = NULL,
	.type       = VIRTFS_DIRECTORY,
	.name       = "",
	.fullname   = "/",
	.stat       = {
		.st_mode  = S_IFDIR | 0755,
		.st_size  = 0,
		.st_nlink = 1
	}
};

static struct fuse_opt frozenfs_opts[] = {
	FUSE_OPT_KEY("-h",             KEY_HELP),
	FUSE_OPT_KEY("--help",         KEY_HELP),
	FUSE_OPT_END
};

/* }}} */

/* virtfs {{{ */
static int            match_path(char *folderpath, char *filepath){
	char c1, c2;
	int  folder_len = 0;
	
	do{
		c1 = *folderpath++;
		c2 = *filepath++;
		
		if(c2 == 0)
			goto invalid;
		if(c1 == 0)
			goto check_slash;
		
		folder_len++;
	}while(c1 == c2);
invalid:
	return 0;

check_slash:
	if(folder_len == 1 || c2 == '/')
		return (strchr(filepath, '/') == NULL) ? 2 : 1;
	return 0;
}

static virtfs_item *  virtfs_find(char *path, size_t path_len){
	virtfs_item    *folder;
	
	if(strcmp(path, "") == 0 || strcmp(path, "/") == 0)
		return &virtfs;
	
	//printf("find: %s\n", path);
	for(folder = &virtfs; folder != NULL;){
		//printf("find: do: %s\n", folder->fullname);
		
		if(strncmp(folder->fullname, path, path_len) == 0)
			return folder;
		
		if(
			folder->type == VIRTFS_DIRECTORY &&
			match_path(folder->fullname, path) != 0
		){
			//printf("find: move into %s\n", folder->fullname);
			folder = folder->childs;
			continue;
		}
		
		folder = folder->next;
	}
	return NULL;
}

static virtfs_item *  virtfs_create(char *path, virt_type type){
	char           *name;
	size_t          path_len;
	virtfs_item    *folder, *new_item;
	
	if( (name = strrchr(path, '/')) == NULL)
		return NULL;
	name++;
	path_len = name - path - 1;
	
	if( (folder = virtfs_find(path, path_len)) == NULL)
		return NULL;
	
	if( (new_item = calloc(sizeof(virtfs_item), 1)) == NULL)
		return NULL;
	
	new_item->type         = type;
	new_item->name         = strdup(name);
	new_item->fullname     = strdup(path);
	
	mode_t new_mode;
	switch(type){
		case VIRTFS_DIRECTORY: new_mode = S_IFDIR | 0755; break;
		case VIRTFS_FILE:      new_mode = S_IFREG | 0666; break;
		case VIRTFS_INVALID:   new_mode = 0; break;
	};
	new_item->stat.st_mode  = new_mode;
	new_item->stat.st_nlink = 1;
	new_item->stat.st_uid   = getuid();
	new_item->stat.st_gid   = getgid();
	new_item->stat.st_atime = 
	new_item->stat.st_mtime =
	new_item->stat.st_ctime = time(NULL);
	
	// link it
	new_item->next = folder->childs;
	folder->childs = new_item;
	return new_item;
}
/* }}} */

/* frozen wrappers {{{ */
static virtfs_item *  wfrozen_vfs_create(char *basepath, char *itempath, virt_type vfs_type, frozen_type type, backend_t *backend){
	frozen_userdata  *ud;
	virtfs_item      *item;
	char              tmp[1024];
	
	snprintf(tmp, 1024, "%s%s", basepath, itempath);
	
	if( (item = virtfs_create(tmp, vfs_type)) == NULL)
		return NULL;
	
	if( (ud = calloc(sizeof(frozen_userdata), 1)) == NULL)
		return NULL;
	
	ud->type = type;
	ud->backend = backend;
	
	item->userdata = (void *)ud;
	
	return item;
}

static backend_t *  wfrozen_backend_new(hash_t *config){
	backend_t    *backend;
	char         *backend_name, bp[1024];
	
	if( (backend = backend_new(config)) == NULL)
		return NULL;
	
	if( (backend_name = backend_get_name(backend)) == NULL){
		snprintf(bp, 1024, "/backends/unnamed_%d", cnt_unnamed++);
	}else{
		snprintf(bp, 1024, "/backends/%s", backend_name);
	}
	
	if(wfrozen_vfs_create(bp, "",              VIRTFS_DIRECTORY, BACKEND_HOLDER,   backend) == NULL) goto cleanup;
	if(wfrozen_vfs_create(bp, "/whole",        VIRTFS_FILE,      BACKEND_IO,       backend) == NULL) goto cleanup;
	
	return backend;
	
cleanup:
	backend_destroy(backend);
	return NULL;
};

static void         wfrozen_backend_destory(backend_t *backend){
	backend_destroy(backend);
};

static void wfrozen_init(void){
	wfrozen_vfs_create("/", "backends", VIRTFS_DIRECTORY, BACKEND_HOLDER, NULL);
	wfrozen_vfs_create("/", "config",   VIRTFS_FILE,      CONFIG_FILE,    NULL);
	
	frozen_init();
	
	hash_set(global_settings, "homedir", TYPE_STRING, opts.datadir, strlen(opts.datadir) + 1);
	
	/*
	hash_t config[] = {
		{ NULL,    DATA_HASHT(
			{ NULL, DATA_HASHT(
				{ "name",      DATA_STRING("file")                 },
				{ "filename",  DATA_STRING("data_ffs_test.dat")    },
				hash_end
			)},
			{ NULL, DATA_HASHT(
				{ "name",      DATA_STRING("rewrite")              },
				{ "rules",     DATA_HASHT(
					{ NULL, DATA_HASHT(
						{ "action",     DATA_STRING("set")          },
						{ "src_config", DATA_STRING("def_goff")     },
						{ "dst_key",    DATA_STRING("goff")         },
						{ "def_goff",   DATA_OFFT(0)                },
						hash_end
					)},
					{ NULL, DATA_HASHT(
						{ "action",  DATA_STRING("data_convert")    },
						{ "src_key", DATA_STRING("param")           },
						{ "dst_key", DATA_STRING("goff")            },
						hash_end
					)},
					{ NULL, DATA_HASHT(
						{ "action",   DATA_STRING("data_arith")     },
						{ "dst_key",  DATA_STRING("key")            },
						{ "src_key",  DATA_STRING("goff")           },
						{ "operator", DATA_STRING("+")              },
						hash_end
					)},
					hash_end
				)},
				hash_end
			)},
			hash_end
		)},
		{ "name",  DATA_STRING("be_file")                         },
		hash_end
	};
	
	backend = wfrozen_backend_new(config);
	*/
	hash_t c_data[] = {
		{ NULL, DATA_HASHT(
			{ NULL, DATA_HASHT(
				{ "name",      DATA_STRING("file")                           },
				{ "filename",  DATA_STRING("data_ffs_data.dat")              },
				hash_end
			)},
			hash_end
		)},
		{ "name", DATA_STRING("b_data") },
		hash_end
	};
	backend2 = wfrozen_backend_new(c_data);
	
	hash_t c_idx[] = {
		{ NULL, DATA_HASHT(
			{ NULL, DATA_HASHT(
				{ "name",         DATA_STRING("file")                               },
				{ "filename",     DATA_STRING("data_ffs_idx.dat")                   },
				hash_end
			)},
			{ NULL, DATA_HASHT(
				{ "name",         DATA_STRING("rewrite")                            },
				{ "rules",        DATA_HASHT(
					{ NULL, DATA_HASHT( // 1
						{ "action",     DATA_STRING("data_arith")           },
						{ "operator",   DATA_STRING("*")                    },
						{ "dst_key",    DATA_STRING("key")                  },
						{ "src_config", DATA_STRING("operand")              },
						{ "operand",    DATA_OFFT(8)                        },
						{ "copy",       DATA_INT32(1)                       },
						{ "on-request", DATA_INT32(
							ACTION_CRWD_READ |
							ACTION_CRWD_WRITE |
							ACTION_CRWD_DELETE
						)},
						hash_end
					)},
					// move {{{
					{ NULL, DATA_HASHT( // 2
						{ "action",     DATA_STRING("data_arith")           },
						{ "operator",   DATA_STRING("*")                    },
						{ "dst_key",    DATA_STRING("key_from")             },
						{ "src_config", DATA_STRING("operand")              },
						{ "operand",    DATA_OFFT(8)                        },
						{ "on-request", DATA_INT32(ACTION_CRWD_MOVE)        },
						hash_end
					)},
					{ NULL, DATA_HASHT( // 3
						{ "action",     DATA_STRING("data_arith")           },
						{ "operator",   DATA_STRING("*")                    },
						{ "dst_key",    DATA_STRING("key_to")               },
						{ "src_config", DATA_STRING("operand")              },
						{ "operand",    DATA_OFFT(8)                        },
						{ "on-request", DATA_INT32(ACTION_CRWD_MOVE)        },
						hash_end
					)},
					// }}}
					// write {{{
					{ NULL, DATA_HASHT( // 4
						{ "action",        DATA_STRING("set")               },
						{ "src_key",       DATA_STRING("buffer")            },
						{ "dst_backend",   DATA_STRING("buffer")            },
						{ "dst_rule",      DATA_INT32(7)                    },
						{ "on-request",
							DATA_INT32(
								ACTION_CRWD_CREATE | ACTION_CRWD_WRITE
							)},
						hash_end
					)},
					{ NULL, DATA_HASHT( // 5
						{ "action",        DATA_STRING("data_alloca")       },
						{ "dst_type",      DATA_STRING("memory")            },
						{ "dst_size",      DATA_SIZET(8)                    },
						{ "dst_key",       DATA_STRING("buffer")            },
						{ "on-request",
							DATA_INT32(
								ACTION_CRWD_CREATE | ACTION_CRWD_WRITE
							)},
						hash_end
					)},
					{ NULL, DATA_HASHT( // 6
						{ "action",        DATA_STRING("set")               },
						{ "src_key",       DATA_STRING("buffer")            },
						{ "dst_backend",   DATA_STRING("key_out")           },
						{ "dst_rule",      DATA_INT32(7)                    },
						{ "on-request",
							DATA_INT32(
								ACTION_CRWD_CREATE | ACTION_CRWD_WRITE
							)},
						hash_end
					)},
					{ NULL, DATA_HASHT( // 7
						{ "action",          DATA_STRING("backend")         },
						{ "backend",         DATA_STRING("b_data")          },
						{ "request_proto",   DATA_HASHT(
							{ "action",  DATA_INT32(ACTION_CRWD_WRITE)  },
							hash_end
						)},
						{ "ret_override",    DATA_INT32(1)                  },
						{ "on-request",
							DATA_INT32(
								ACTION_CRWD_CREATE | ACTION_CRWD_WRITE
							)},
						hash_end
					)},
					{ NULL, DATA_HASHT( // 8
						{ "action",     DATA_STRING("data_arith")           },
						{ "operator",   DATA_STRING("/")                    },
						{ "dst_key",    DATA_STRING("key_out")              },
						{ "src_config", DATA_STRING("operand")              },
						{ "operand",    DATA_OFFT(8)                        },
						{ "after",      DATA_INT32(1)                       },
						{ "on-request", DATA_INT32(
							ACTION_CRWD_CREATE | ACTION_CRWD_WRITE)     },
						hash_end
					)},
					// }}}
					// read {{{
					{ NULL, DATA_HASHT( // 9
						{ "action",        DATA_STRING("set")               },
						{ "src_key",       DATA_STRING("buffer")            },
						{ "dst_backend",   DATA_STRING("buffer")            },
						{ "dst_rule",      DATA_INT32(12)                   },
						{ "on-request",    DATA_INT32(ACTION_CRWD_READ)     },
						hash_end
					)},
					{ NULL, DATA_HASHT( // 10
						{ "action",        DATA_STRING("data_alloca")       },
						{ "dst_type",      DATA_STRING("off_t")             },
						{ "dst_size",      DATA_SIZET(8)                    },
						{ "dst_key",       DATA_STRING("buffer")            },
						{ "on-request",    DATA_INT32(ACTION_CRWD_READ)     },
						hash_end
					)},
					{ NULL, DATA_HASHT( // 11
						{ "action",        DATA_STRING("set")               },
						{ "src_key",       DATA_STRING("buffer")            },
						{ "dst_backend",   DATA_STRING("key")               },
						{ "dst_rule",      DATA_INT32(12)                   },
						{ "on-request",    DATA_INT32(ACTION_CRWD_READ)     },
						{ "after",         DATA_INT32(1)                    },
						hash_end
					)},
					{ NULL, DATA_HASHT( // 12
						{ "action",          DATA_STRING("backend")         },
						{ "backend",         DATA_STRING("b_data")          },
						{ "request_proto",   DATA_HASHT(
							{ "action",  DATA_INT32(ACTION_CRWD_READ)   },
							hash_end
						)},
						{ "ret_override",    DATA_INT32(1)                  },
						{ "on-request",      DATA_INT32(ACTION_CRWD_READ)   },
						{ "after",           DATA_INT32(1)                  },
						hash_end
					)},
					// }}}
					// count {{{
					{ NULL, DATA_HASHT( // 13
						{ "action",     DATA_STRING("data_arith")           },
						{ "operator",   DATA_STRING("/")                    },
						{ "dst_key",    DATA_STRING("buffer")               },
						{ "src_config", DATA_STRING("operand")              },
						{ "operand",    DATA_OFFT(8)                        },
						{ "after",      DATA_INT32(1)                       },
						{ "on-request", DATA_INT32(ACTION_CRWD_COUNT)       },
						hash_end
					)},
					// }}}
					hash_end
				)},
				hash_end
			)},
			{ NULL, DATA_HASHT(
				{ "name",         DATA_STRING("list")                               },
				hash_end
			)},
			{ NULL, DATA_HASHT(
				{ "name",         DATA_STRING("insert-sort")                        },
				{ "engine",       DATA_STRING("binsearch")                          },
				hash_end
			)},
			hash_end
		)},
		{ "name", DATA_STRING("be_file") },
		hash_end
	};
	
	backend = wfrozen_backend_new(c_idx);
}

static void wfrozen_destroy(void){
	wfrozen_backend_destory(backend);
	wfrozen_backend_destory(backend2);
	
	frozen_destroy();
}
/* }}} */

/* FUSE functions {{{ */
/* private {{{ */
static int fusef_vfs_find(const char *path, virtfs_item **item, char **param){
	char        *s;
	size_t       path_len = ~0;
	
	if( (s = strchr(path, ':')) != NULL){
		path_len = s - path - 1;
		*param = s;
	}else{
		*param = NULL;
	}
	
	if( (*item = virtfs_find((char *)path, path_len)) == NULL)
		return -1;
	
	return 0;
}

/* }}} */
/* folders {{{ */
static int fusef_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t off, struct fuse_file_info *fi){
	virtfs_item *folder, *child;
	
	if( (folder = virtfs_find((char *)path, ~0)) == NULL)
		return -ENOENT;
	
	filler(buf, ".",  NULL, 0);
	filler(buf, "..", NULL, 0);
	
	child = folder->childs;
	while(child != NULL){
		filler(buf, child->name, NULL, 0);
		
		child = child->next;
	}
	return 0;
}

static int fusef_getattr(const char *path, struct stat *buf){
	virtfs_item      *item;
	frozen_userdata  *ud;
	char             *param;
	off_t             size = 0;
	
	if(fusef_vfs_find(path, &item, &param) != 0)
		return -ENOENT;
	
	// TODO move out
	//offset = (param) ? (off_t) strtoul(param, NULL, 10) : 0;
	// END TODO
	
	ud = (frozen_userdata *)item->userdata;
	if(ud && ud->type == BACKEND_IO){
		// updating size
		request_t r_count[] = {
			{ "action",  DATA_INT32(ACTION_CRWD_COUNT)       },
			{ "buffer",  DATA_PTR_OFFT(&size)                },
			hash_end
		};
		backend_query(ud->backend, r_count);
	}
	item->stat.st_size = size; //(param) ?
	//	((offset > size) ? 0 : size - offset) :
	//	size;
	
	memcpy(buf, &(item->stat), sizeof(struct stat));
	return 0;
}
/* }}} */
/* files {{{ */ 
static int fusef_open(const char *path, struct fuse_file_info *fi){
	virtfs_item *item;
	frozen_fh   *fh;
	char        *param;
	
	if(fusef_vfs_find(path, &item, &param) != 0)
		return -ENOENT;
	
	if( (fh = malloc(sizeof(frozen_fh))) == NULL)
		return -ENOMEM;
	
	fh->item  = item;
	fh->ud    = (frozen_userdata *)(item->userdata);
	fh->param = NULL;
	if(param){
		if( (fh->param = strdup(param + 1)) == NULL)
			return -ENOMEM;
	}
	
	// TODO check access
	
	fi->fh = (unsigned long) fh;
	
	// TODO lock item
	
	return 0;
}

static int fusef_read(const char *path, char *buf, size_t size, off_t off, struct fuse_file_info *fi){
	ssize_t           ret;
	frozen_fh        *fh;
	data_t            d_param = DATA_VOID;
	
	fh = (frozen_fh *)(uintptr_t)fi->fh;
	
	if(fh->param){
		data_reinit(&d_param, TYPE_STRING, fh->param, strlen(fh->param) + 1);
	}
	
	request_t r_read[] = {
		{ "action", DATA_INT32(ACTION_CRWD_READ)                    },
		{ "key",    DATA_PTR_OFFT(&off)                             },
		{ "buffer", DATA_MEM(buf, size)                             },
		
	//	{ "param",  d_param                                         },
	//	{ "path",   DATA_PTR_STRING((char *)path, strlen(path)+1)   },
		hash_end
	};
	ret = backend_query(fh->ud->backend, r_read);
	
	printf("read: %x bytes from %llx. ret: %x, data: %s\n", (int)size, off, (int)ret, buf);
	
	return (ret < 0) ? 0 : (int)ret; //(int)size;
}

static int fusef_write(const char *path, const char *buf, size_t size, off_t off, struct fuse_file_info *fi){
	ssize_t           ret;
	frozen_fh        *fh;
	data_t            d_param = DATA_VOID;
	
	fh = (frozen_fh *)(uintptr_t)fi->fh;
	
	if(fh->param){
		data_reinit(&d_param, TYPE_STRING, fh->param, strlen(fh->param) + 1);
	}
	
	request_t r_write[] = {
		{ "action",  DATA_INT32(ACTION_CRWD_WRITE)                   },
		//{ "key",     DATA_PTR_OFFT(&off)                             },
		{ "key_out", DATA_PTR_OFFT(&off)                             },
		{ "buffer",  DATA_MEM((char *)buf, size)                     },
		
	//	{ "param",   d_param                                         },
	//	{ "path",    DATA_PTR_STRING((char *)path, strlen(path)+1)   },
		hash_end
	};
	ret = backend_query(fh->ud->backend, r_write);
	
	printf("write: %x bytes from %llx. ret: %x\n", (int)size, off, (int)ret);
	
	return (ret < 0) ?
		0 :
		((ret > size) ? size : (int)ret);
}

static int fusef_release(const char *path, struct fuse_file_info *fi){
	frozen_fh        *fh;
	
	fh = (frozen_fh *)(uintptr_t)fi->fh;
	
	// TODO unlock item
	
	if(fh->param)
		free(fh->param);
	
	free(fh);
	return 0;
}
/* }}} */
/* stubs {{{
static int fusef_flush(const char *path, struct fuse_file_info *fi){
	return -ENOSYS;
}

static int fusef_statfs(const char *path, struct statvfs *stat){
	return 0;
}

static int fusef_readlink(const char *path, char *buf, size_t size){
	return -ENOSYS;
}

static int fusef_mknod(const char *path, mode_t mode, dev_t dev){
	return -ENOSYS;
}

static int fusef_mkdir(const char *path, mode_t mode){
	return -ENOSYS;
}

static int fusef_unlink(const char *path){
	return -ENOSYS;
}

static int fusef_rmdir(const char *path){
	return -ENOSYS;
}

static int fusef_symlink(const char *from, const char *to){
	return -ENOSYS;
}

static int fusef_rename(const char *from, const char *to){
	return -ENOSYS;
}

static int fusef_link(const char *from, const char *to){
	return -ENOSYS;
}

static int fusef_chmod(const char *path, mode_t mode){
	return -ENOSYS;
}

static int fusef_chown(const char *path, uid_t uid, gid_t gid){
	return -ENOSYS;
}

static int fusef_truncate(const char *path, off_t off){
	return -ENOSYS;
}

static int fusef_fsync(const char *path, int datasync, struct fuse_file_info *fi){
	return -ENOSYS;
}

static int fusef_setxattr(const char *path, const char *name, const char *value, size_t size, int pos){
	return -ENOSYS;
}

static int fusef_getxattr(const char *path, const char *name, char *value, size_t size){
	return -ENOSYS;
}

static int fusef_listxattr(const char *path, char *list, size_t size){
	return -ENOSYS;
}

static int fusef_removexattr(const char *path, const char *name){
	return -ENOSYS;
}

static int fusef_fsyncdir(const char *path, int datasync, struct fuse_file_info *fi){
	return -ENOSYS;
}

static int fusef_access(const char *path, int mask){
	return -ENOSYS;
}

static int fusef_create(const char *path, mode_t mode, struct fuse_file_info *fi){
	return -ENOSYS;
}

static int fusef_ftruncate(const char *path, off_t off, struct fuse_file_info *fi){
	return -ENOSYS;
}

static int fusef_fgetattr(const char *path, struct stat *buf, struct fuse_file_info *fi){
	return -ENOSYS;
}

static int fusef_lock(const char *path, struct fuse_file_info *fi, int cmd, struct flock *lock){
	return -ENOSYS;
}

static int fusef_utimens(const char *path, const struct timespec tv[2]){
	return -ENOSYS;
}

static int fusef_bmap(const char *path, size_t blocksize, uint64_t *idx){
	return -ENOSYS;
}

static int fusef_opendir(const char *path, struct fuse_file_info *fi){
	return 0;
}
static int fusef_releasedir(const char *path, struct fuse_file_info *fi){
	return 0;
}
 }}} */
struct fuse_operations fuse_operations = { // {{{
	/*
	.readlink = fusef_readlink,
	.mknod = fusef_mknod,
	.mkdir = fusef_mkdir,
	.unlink = fusef_unlink,
	.rmdir = fusef_rmdir,
	.symlink = fusef_symlink,
	.rename = fusef_rename,
	.link = fusef_link,
	.chmod = fusef_chmod,
	.chown = fusef_chown,
	.truncate = fusef_truncate,
	.statfs = fusef_statfs,
	.flush = fusef_flush,
	.release = fusef_release,
	.fsync = fusef_fsync,
	.setxattr = fusef_setxattr,
	.getxattr = fusef_getxattr,
	.listxattr = fusef_listxattr,
	.removexattr = fusef_removexattr,
	.opendir = fusef_opendir,
	.releasedir = fusef_releasedir,
	.fsyncdir = fusef_fsyncdir,
	.access = fusef_access,
	.create = fusef_create,
	.ftruncate = fusef_ftruncate,
	.fgetattr = fusef_fgetattr,
	.lock = fusef_lock,
	.utimens = fusef_utimens,
	.bmap = fusef_bmap
	*/
	.readdir = fusef_readdir,
	.getattr = fusef_getattr,
	.open    = fusef_open,
	.read    = fusef_read,
	.write   = fusef_write,
	.release = fusef_release,
}; // }}}
/* }}} */

/* options and usage {{{ */
static void usage(void){
	printf("usage: frozenfs datadir mountpoint [options]\n");
}

static int frozenfs_opt_proc(void *data, const char *arg, int key, struct fuse_args *outargs){
	switch(key){
		case FUSE_OPT_KEY_OPT:
			//printf("fuse: key opt: %s\n", arg);
				//tmp = g_strdup_printf("-o%s", arg);
				//ssh_add_arg(tmp);
				//g_free(tmp);
				//return 0;
			return 1;
		
		case FUSE_OPT_KEY_NONOPT:
			if(!opts.datadir){
				opts.datadir = strdup(arg);
				return 0;
			}
			return 1;
		
		case KEY_HELP:
			usage();
			fuse_opt_add_arg(outargs, "-ho");
			fuse_main(outargs->argc, outargs->argv, NULL, NULL);
			exit(1);
			
		default:
			return -1;
	};
}

int main(int argc, char *argv[]){
	int              ret;
	struct fuse_args args = FUSE_ARGS_INIT(argc, argv);
	
	if(fuse_opt_parse(&args, &opts, frozenfs_opts, frozenfs_opt_proc) == -1)
		exit(1);
	
	if(!opts.datadir){
		fprintf(stderr, "missing datadir");
		exit(1);
	}
	
	wfrozen_init();
	ret = fuse_main(args.argc, args.argv, &fuse_operations, NULL);
	wfrozen_destroy();
	return ret;
}
/* }}} */
