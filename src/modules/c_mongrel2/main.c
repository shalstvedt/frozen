#include <libfrozen.h>

/**
 * @ingroup backend
 * @addtogroup mod_backend_mongrel2 module/c_mongrel2
 */
/**
 * @ingroup mod_backend_mongrel2
 * @page page_mongrel2_info Description
 *
 * This module implement Mongrel2 protocol parsers. It works in pair with ZeroMQ module. c_mongrel2_parse parse mongrel2 request
 * and emit it to underlying backends. c_mongrel2_reply consturct reply for mongrel server and pass it to underlying backned.
 */
/**
 * @ingroup mod_backend_mongrel2
 * @page page_mongrel2_config Configuration
 *  
 * Accepted configuration for parser backend:
 * @code
 * {
 *              class                   = "modules/c_mongrel2_parse"
 * }
 * @endcode
 * 
 * Accepted configuration for reply backend
 * @code
 * {
 *              class                   = "modules/c_mongrel2_reply",
 *              buffer                  = (hashkey_t)'buffer',                 # output buffer hashkey name, default "buffer"
 *              body                    = (hashkey_t)'body',                   # input http request body hashkey name, default "body"
 *              close                   = (uint_t)'0'                          # close connection after reply, default 1
 * }
 * @endcode
 */
/**
 * @ingroup mod_backend_mongrel2
 * @page page_mongrel2_io Input and output
 * 
 * c_mongrel2_parse expect fast ACTION_WRITE request as input and emit following hash request on output:
 * @code
 * {
 *              action                  = (action_t)"write",
 *              uuid                    = (raw_t)"<server uuid>",              # server uuid, use it for reply
 *              clientid                = (raw_t)"<clientid>",                 # mongrel client connection id
 *              path                    = (raw_t)"/",                          # request url
 *              headers                 = (raw_t)"{<json headers>}",           # request headers in form of json string, not parsed
 *              body                    = (raw_t)"<body>"                      # request body
 * }
 * @endcode
 *
 * c_mongrel2_reply expect following minimum request for input:
 * @code
 * {
 *              uuid                    = (raw_t)"<server uuid>",              # server uuid to reply for
 *              clinetid                = (raw_t)"<clientid>",                 # mongrel client connection id, or list of id's
 *             [config->body]           =                                      # reply for client
 *                                        (raw_t)"<body>"                      # - full request body, including "HTTP/1.1 ..."
 *                                        (void_t)""                           # - ask mongrel to close connection
 * } 
 * @endcode
 * c_mongrel2_reply emit following request:
 * @code
 * {
 *             [config->buffer]         = (struct_t)"",                        # constructed reply
 *             ...
 * }
 * @endcode
 */

#define EMODULE 102

typedef struct mongrel2_userdata {
	hashkey_t              buffer;
	hashkey_t              body;
	uintmax_t              close_conn;
} mongrel2_userdata;

static int mongrel2_init(backend_t *backend){ // {{{
	mongrel2_userdata     *userdata;
	
	if((userdata = backend->userdata = calloc(1, sizeof(mongrel2_userdata))) == NULL)
		return error("calloc failed");
	
	userdata->buffer     = HK(buffer);
	userdata->body       = HK(body);
	userdata->close_conn = 1;
	return 0;
} // }}}
static int mongrel2_destroy(backend_t *backend){ // {{{
	mongrel2_userdata     *userdata          = (mongrel2_userdata *)backend->userdata;
	
	free(userdata);
	return 0;
} // }}}
static int mongrel2_configure(backend_t *backend, config_t *config){ // {{{
	ssize_t                ret;
	mongrel2_userdata     *userdata          = (mongrel2_userdata *)backend->userdata;
	
	hash_data_copy(ret, TYPE_HASHKEYT, userdata->buffer,     config, HK(buffer));
	hash_data_copy(ret, TYPE_HASHKEYT, userdata->body,       config, HK(body));
	hash_data_copy(ret, TYPE_UINTT,    userdata->close_conn, config, HK(close));
	return 0;
} // }}}

static ssize_t mongrel2_reply_handler(backend_t *backend, request_t *request){ // {{{
	ssize_t                ret;
	mongrel2_userdata     *userdata          = (mongrel2_userdata *)backend->userdata;
	
	hash_t reply_struct[] = {
		{ HK(uuid), DATA_HASHT(
			{ HK(format),  DATA_FORMATT(FORMAT(clean))     },
			hash_end
		)},
		{ 0, DATA_HASHT(
			{ HK(format),  DATA_FORMATT(FORMAT(clean))     },
			{ HK(default), DATA_STRING(" ")                },
			hash_end
		)},
		{ HK(clientid), DATA_HASHT(
			{ HK(format),  DATA_FORMATT(FORMAT(netstring)) },
			hash_end
		)},
		{ 0, DATA_HASHT(
			{ HK(format),  DATA_FORMATT(FORMAT(clean))     },
			{ HK(default), DATA_STRING(" ")                },
			hash_end
		)},
		{ userdata->body, DATA_HASHT(
			{ HK(format),  DATA_FORMATT(FORMAT(clean))     },
			hash_end
		)},
		hash_end
	};
	
	request_t r_reply[] = {
		{ userdata->buffer, DATA_STRUCTT(reply_struct, request) },
		hash_inline(request),
		hash_end
	};
	if( (ret = backend_pass(backend, r_reply)) < 0 )
		return ret;
	
	if(userdata->close_conn == 1){
		request_t r_voidbody[] = {
			{ userdata->body, DATA_VOID },
			hash_inline(request),
			hash_end
		};
		
		request_t r_close[] = {
			{ userdata->buffer, DATA_STRUCTT(reply_struct, r_voidbody) },
			hash_inline(r_voidbody),
			hash_end
		};
		if( (ret = backend_pass(backend, r_close)) < 0 )
			return ret;
	}
	return -EEXIST;
} // }}}

static backend_t mongrel2_reply_proto = {
	.class          = "modules/c_mongrel2_reply",
	.supported_api  = API_HASH,
	.func_init      = &mongrel2_init,
	.func_destroy   = &mongrel2_destroy,
	.func_configure = &mongrel2_configure,
	.backend_type_hash = {
		.func_handler = &mongrel2_reply_handler
	},
};

static ssize_t mongrel2_parse_handler(backend_t *backend, fastcall_header *hargs){ // {{{
	ssize_t                ret;
	char                  *p, *uuid_p, *connid_p, *path_p, *header_p, *body_p, *e;
	uintmax_t                  uuid_l,  connid_l,  path_l,  header_l,  body_l;
	fastcall_write        *wargs             = (fastcall_write *)hargs;
	
	if(hargs->action != ACTION_WRITE)
		return -ENOSYS;
	
	p = wargs->buffer;
	e = wargs->buffer + wargs->buffer_size;
	
	     uuid_p   = p;
	if( (connid_p = memchr(p, ' ', (e-p))) == NULL) return -EINVAL; uuid_l   = connid_p - uuid_p;   p = ++connid_p;
	if( (path_p   = memchr(p, ' ', (e-p))) == NULL) return -EINVAL; connid_l = path_p   - connid_p; p = ++path_p;
	if( (header_p = memchr(p, ' ', (e-p))) == NULL) return -EINVAL; path_l   = header_p - path_p;
	
	header_p++;
	header_l = 0; sscanf(header_p, "%" SCNuMAX, &header_l);
	if( (header_p = memchr(header_p, ':', (e-header_p))) == NULL) return -EINVAL; header_p++;
	if(header_l >= (e-header_p)) return -EINVAL;
	
	body_p = header_p + header_l + 1;
	body_l   = 0; sscanf(body_p,   "%" SCNuMAX, &body_l);
	if( (body_p   = memchr(body_p,   ':', (e-body_p))) == NULL) return -EINVAL; body_p++;
	if(body_l >= (e-body_p)) return -EINVAL;
	
	request_t request[] = {
		{ HK(uuid),     DATA_RAW(uuid_p,   uuid_l)   },
		{ HK(clientid), DATA_RAW(connid_p, connid_l) },
		{ HK(path),     DATA_RAW(path_p,   path_l)   },
		{ HK(headers),  DATA_RAW(header_p, header_l) },
		{ HK(body),     DATA_RAW(body_p,   body_l)   },
		
		{ HK(action),   DATA_UINTT(ACTION_WRITE)     },
		hash_end
	};
	
	return ( (ret = (backend_pass(backend, request)) < 0) ) ? ret : -EEXIST;
} // }}}

static backend_t mongrel2_parse_proto = {
	.class          = "modules/c_mongrel2_parse",
	.supported_api  = API_FAST,
	.backend_type_fast = {
		.func_handler = (f_fast_func)&mongrel2_parse_handler
	},
};

int main(void){
	class_register(&mongrel2_reply_proto);
	class_register(&mongrel2_parse_proto);
	return 0;
}
