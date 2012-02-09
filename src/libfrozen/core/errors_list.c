
typedef struct err_item {
        intmax_t    errnum;
        const char *errmsg;
} err_item;
static err_item errs_list[] = {
 { -225342, "src/libfrozen/machines/shop/try/try.c: shop parameter not supplied" },
 { -225321, "src/libfrozen/machines/shop/try/try.c: calloc failed" },
 { -221226, "src/libfrozen/data/storage/folder/folder_t.c: path not exist" },
 { -221220, "src/libfrozen/data/storage/folder/folder_t.c: path invalid" },
 { -221214, "src/libfrozen/data/storage/folder/folder_t.c: path not supplied" },
 { -221211, "src/libfrozen/data/storage/folder/folder_t.c: calloc returns null" },
 { -217150, "src/libfrozen/machines/data/query/query.c: data not supplied" },
 { -217129, "src/libfrozen/machines/data/query/query.c: calloc failed" },
 { -204903, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: bad underlying storage" },
 { -204896, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: bad item size" },
 { -204889, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: bad item_sample" },
 { -204883, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: no item_size nor item_sample supplied" },
 { -204876, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: invalid storage supplied" },
 { -204868, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: calloc failed" },
 { -196688, "src/libfrozen/data/enum/format/format_t.c: format collision" },
 { -192594, "src/libfrozen/data/enum/hashkey/hashkey_t.c: key collision" },
 { -184365, "src/libfrozen/machines/sync/mutex/mutex.c: pthread_mutex_init failed" },
 { -184362, "src/libfrozen/machines/sync/mutex/mutex.c: pthread_mutexattr_settype failed" },
 { -184359, "src/libfrozen/machines/sync/mutex/mutex.c: pthread_mutexattr_init failed" },
 { -184356, "src/libfrozen/machines/sync/mutex/mutex.c: calloc failed" },
 { -180266, "src/libfrozen/machines/request/assign/assign.c: calloc returns null" },
 { -176296, "src/libfrozen/machines/io/tcp/tcp.c: pthread_setspecific error" },
 { -176289, "src/libfrozen/machines/io/tcp/tcp.c: calloc failed" },
 { -176268, "src/libfrozen/machines/io/tcp/tcp.c: shop_new error" },
 { -176265, "src/libfrozen/machines/io/tcp/tcp.c: pthread_setspecific error" },
 { -176262, "src/libfrozen/machines/io/tcp/tcp.c: pthread_setspecific error" },
 { -176259, "src/libfrozen/machines/io/tcp/tcp.c: accept error" },
 { -176225, "src/libfrozen/machines/io/tcp/tcp.c: calloc failed" },
 { -176206, "src/libfrozen/machines/io/tcp/tcp.c: listen error" },
 { -176203, "src/libfrozen/machines/io/tcp/tcp.c: bind error" },
 { -176195, "src/libfrozen/machines/io/tcp/tcp.c: socket error" },
 { -172147, "src/libfrozen/machines/daemon/thread/thread.c: calloc failed" },
 { -172123, "src/libfrozen/machines/daemon/thread/thread.c: pthread_create failed" },
 { -167976, "src/libfrozen/machines/request/emitter/emitter.c: calloc failed" },
 { -163896, "src/libfrozen/machines/data/transfer/transfer.c: source or destination machine invalid" },
 { -163876, "src/libfrozen/machines/data/transfer/transfer.c: calloc failed" },
 { -159930, "src/libfrozen/machines/io/console/console.c: input key not supplied" },
 { -159916, "src/libfrozen/machines/io/console/console.c: input key not supplied" },
 { -159902, "src/libfrozen/machines/io/console/console.c: output key not supplied" },
 { -159864, "src/libfrozen/machines/io/console/console.c: calloc failed" },
 { -155684, "src/libfrozen/machines/request/end/end.c: calloc failed" },
 { -147589, "src/libfrozen/machines/data/split/split.c: no input string in request" },
 { -147533, "src/libfrozen/machines/data/split/split.c: calloc failed" },
 { -143424, "src/libfrozen/machines/request/implode/implode.c: calloc failed" },
 { -139323, "src/libfrozen/machines/machine/factory/factory.c: child creation error" },
 { -139296, "src/libfrozen/machines/machine/factory/factory.c: HK(config) not supplied" },
 { -139277, "src/libfrozen/machines/machine/factory/factory.c: calloc failed" },
 { -131131, "src/libfrozen/machines/index/hashtable/hashtable.c: invalid hashtable size" },
 { -131112, "src/libfrozen/machines/index/hashtable/hashtable.c: calloc failed" },
 { -127100, "src/libfrozen/machines/request/switch/switch.c: failed to configure switch" },
 { -127074, "src/libfrozen/machines/request/switch/switch.c: calloc returns null" },
 { -122953, "src/libfrozen/machines/index/fill/fill.c: supplied index machine not valid, or not found" },
 { -122933, "src/libfrozen/machines/index/fill/fill.c: calloc failed" },
 { -119421, "src/libfrozen/machines/io/fuse/fuse.c: fuse fs creation failed" },
 { -119417, "src/libfrozen/machines/io/fuse/fuse.c: mountpoint not supplied" },
 { -114909, "src/libfrozen/machines/data/regexp/regexp.c: can not convert data to string" },
 { -114904, "src/libfrozen/machines/data/regexp/regexp.c: no input string in request" },
 { -114806, "src/libfrozen/machines/data/regexp/regexp.c: calloc failed" },
 { -114787, "src/libfrozen/machines/data/regexp/regexp.c: can not copy marker data" },
 { -114768, "src/libfrozen/machines/data/regexp/regexp.c: invalid regexp supplied - compilation error" },
 { -110628, "src/libfrozen/machines/shop/return/return.c: calloc failed" },
 { -106558, "src/libfrozen/machines/shop/pass/pass.c: shop parameter not supplied" },
 { -106537, "src/libfrozen/machines/shop/pass/pass.c: calloc failed" },
 { -102684, "src/libfrozen/machines/machine/rebuild/rebuild.c: no writer exists" },
 { -102669, "src/libfrozen/machines/machine/rebuild/rebuild.c: no reader supplied" },
 { -102647, "src/libfrozen/machines/machine/rebuild/rebuild.c: calloc failed" },
 { -102571, "src/libfrozen/machines/machine/rebuild/rebuild.c: calloc failed" },
 { -102498, "src/libfrozen/machines/machine/rebuild/rebuild.c: rebuild max rebuilds reached" },
 { -102494, "src/libfrozen/machines/machine/rebuild/rebuild.c: not reader supplied" },
 { -98397, "src/libfrozen/machines/hash/jenkins/jenkins.c: input key not supplied" },
 { -98376, "src/libfrozen/machines/hash/jenkins/jenkins.c: input key not supplied" },
 { -98345, "src/libfrozen/machines/hash/jenkins/jenkins.c: calloc failed" },
 { -94300, "src/libfrozen/machines/hash/murmur/murmur.c: input key not supplied" },
 { -94280, "src/libfrozen/machines/hash/murmur/murmur.c: input key not supplied" },
 { -94249, "src/libfrozen/machines/hash/murmur/murmur.c: calloc failed" },
 { -90165, "src/libfrozen/machines/index/lookup/lookup.c: supplied index machine not valid, or not found" },
 { -90148, "src/libfrozen/machines/index/lookup/lookup.c: calloc failed" },
 { -86098, "src/libfrozen/machines/machine/morph/morph.c: child creation error" },
 { -86076, "src/libfrozen/machines/machine/morph/morph.c: HK(config) not supplied" },
 { -86057, "src/libfrozen/machines/machine/morph/morph.c: calloc failed" },
 { -73860, "src/libfrozen/machines/machine/benchmark/benchmark.c: calloc failed" },
 { -69690, "src/libfrozen/machines/request/debug/debug.c: calloc failed" },
 { -65904, "src/libfrozen/machines/machine/pool/pool.c: pthread_join failed" },
 { -65900, "src/libfrozen/machines/machine/pool/pool.c: pthread_cancel failed" },
 { -65871, "src/libfrozen/machines/machine/pool/pool.c: pthread_create failed" },
 { -65861, "src/libfrozen/machines/machine/pool/pool.c: calloc failed" },
 { -49807, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: delete not supported" },
 { -49748, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: mphf is read-only" },
 { -49726, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: mphf is read-only" },
 { -49568, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: recalc db inconsistency" },
 { -49538, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: set_g failed" },
 { -49522, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: get_g failed" },
 { -49504, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: find_edge db inconsistency" },
 { -49477, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: set_edge failed" },
 { -49450, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: get_edge failed" },
 { -49432, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: set first failed" },
 { -49417, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: get_first failed" },
 { -49399, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: new_edge_id failed" },
 { -49388, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: v array resize failed" },
 { -49385, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: e array resize failed" },
 { -49382, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: g array resize failed" },
 { -49332, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: too many elements" },
 { -49317, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: data chm_imp parameter data_g invalid" },
 { -49311, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: value_size is too big" },
 { -49292, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: e array init failed" },
 { -49288, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: v array init failed" },
 { -49284, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: g array init failed" },
 { -49253, "src/libfrozen/machines/index/mphf/mphf_chm_imp.c: params write failed" },
 { -45144, "src/libfrozen/machines/index/mphf/mphf.c: machine mphf parameter mphf_type invalid or not supplied" },
 { -45116, "src/libfrozen/machines/index/mphf/mphf.c: calloc failed" },
 { -41243, "src/libfrozen/machines/io/ipc/ipc_shmem.c: strange error 3" },
 { -41223, "src/libfrozen/machines/io/ipc/ipc_shmem.c: can not write buffer to ipc memory" },
 { -41217, "src/libfrozen/machines/io/ipc/ipc_shmem.c: strange error" },
 { -41173, "src/libfrozen/machines/io/ipc/ipc_shmem.c: pthread_create failed" },
 { -41169, "src/libfrozen/machines/io/ipc/ipc_shmem.c: shmem_init failed" },
 { -41154, "src/libfrozen/machines/io/ipc/ipc_shmem.c: force_async with force_sync" },
 { -41151, "src/libfrozen/machines/io/ipc/ipc_shmem.c: invalid role supplied" },
 { -41148, "src/libfrozen/machines/io/ipc/ipc_shmem.c: shmat failed" },
 { -41145, "src/libfrozen/machines/io/ipc/ipc_shmem.c: shmget failed" },
 { -41134, "src/libfrozen/machines/io/ipc/ipc_shmem.c: no role supplied" },
 { -41133, "src/libfrozen/machines/io/ipc/ipc_shmem.c: no key supplied" },
 { -41115, "src/libfrozen/machines/io/ipc/ipc_shmem.c: ipc_shmem_listen dead" },
 { -36934, "src/libfrozen/machines/io/ipc/ipc.c: machine ipc parameter type invalid" },
 { -36914, "src/libfrozen/machines/io/ipc/ipc.c: calloc failed" },
 { -24726, "src/libfrozen/machines/data/structs/structs.c: struct_unpack failed" },
 { -24721, "src/libfrozen/machines/data/structs/structs.c: hash with keys not supplied" },
 { -24695, "src/libfrozen/machines/data/structs/structs.c: struct_pack failed" },
 { -24680, "src/libfrozen/machines/data/structs/structs.c: hash with keys not supplied" },
 { -24663, "src/libfrozen/machines/data/structs/structs.c: machine struct parameter structure invalid" },
 { -24661, "src/libfrozen/machines/data/structs/structs.c: machine struct parameter buffer invalid" },
 { -24635, "src/libfrozen/machines/data/structs/structs.c: calloc failed" },
 { -16697, "src/libfrozen/machines/cache/cache/cache.c: calloc failed" },
 { -16592, "src/libfrozen/machines/cache/cache/cache.c: memory_size failed" },
 { -16580, "src/libfrozen/machines/cache/cache/cache.c: cache delete failed" },
 { -16577, "src/libfrozen/machines/cache/cache/cache.c: size not supplied" },
 { -16576, "src/libfrozen/machines/cache/cache/cache.c: offset not supplied" },
 { -16552, "src/libfrozen/machines/cache/cache/cache.c: memory_grow failed" },
 { -16549, "src/libfrozen/machines/cache/cache/cache.c: no size supplied" },
 { -8267, "src/libfrozen/data/storage/file/file_t.c: file open() error" },
 { -8250, "src/libfrozen/data/storage/file/file_t.c: filename invalid" },
 { -8242, "src/libfrozen/data/storage/file/file_t.c: filename not supplied" },
 { -8232, "src/libfrozen/data/storage/file/file_t.c: calloc returns null" },
 { -4222, "src/libfrozen/machines/index/mphf/mphf_bdz_imp.c: mphf g_free" },

};
#define            errs_list_size      sizeof(errs_list[0])
#define            errs_list_nelements sizeof(errs_list) / errs_list_size
