
typedef struct err_item {
        intmax_t    errnum;
        const char *errmsg;
} err_item;
static err_item errs_list[] = {
 { -200801, "src/libfrozen/backends/backend/wrapper/wrapper.c: no data in request" },
 { -200782, "src/libfrozen/backends/backend/wrapper/wrapper.c: can not create terminator backend" },
 { -200777, "src/libfrozen/backends/backend/wrapper/wrapper.c: backend config not supplied or invalid" },
 { -200751, "src/libfrozen/backends/backend/wrapper/wrapper.c: calloc failed" },
 { -196688, "src/libfrozen/data/enum/format/format_t.c: format collision" },
 { -192594, "src/libfrozen/data/enum/hashkey/hashkey_t.c: key collision" },
 { -188483, "src/libfrozen/backends/request/iterate/iterate.c: no childs" },
 { -188448, "src/libfrozen/backends/request/iterate/iterate.c: calloc returns null" },
 { -184365, "src/libfrozen/backends/sync/mutex/mutex.c: pthread_mutex_init failed" },
 { -184362, "src/libfrozen/backends/sync/mutex/mutex.c: pthread_mutexattr_settype failed" },
 { -184359, "src/libfrozen/backends/sync/mutex/mutex.c: pthread_mutexattr_init failed" },
 { -184356, "src/libfrozen/backends/sync/mutex/mutex.c: calloc failed" },
 { -180264, "src/libfrozen/backends/request/assign/assign.c: calloc returns null" },
 { -176305, "src/libfrozen/backends/io/tcp/tcp.c: pthread_setspecific error" },
 { -176298, "src/libfrozen/backends/io/tcp/tcp.c: calloc failed" },
 { -176265, "src/libfrozen/backends/io/tcp/tcp.c: backend_new error" },
 { -176262, "src/libfrozen/backends/io/tcp/tcp.c: pthread_setspecific error" },
 { -176259, "src/libfrozen/backends/io/tcp/tcp.c: pthread_setspecific error" },
 { -176256, "src/libfrozen/backends/io/tcp/tcp.c: accept error" },
 { -176225, "src/libfrozen/backends/io/tcp/tcp.c: calloc failed" },
 { -176206, "src/libfrozen/backends/io/tcp/tcp.c: listen error" },
 { -176203, "src/libfrozen/backends/io/tcp/tcp.c: bind error" },
 { -176195, "src/libfrozen/backends/io/tcp/tcp.c: socket error" },
 { -172153, "src/libfrozen/backends/daemon/thread/thread.c: calloc failed" },
 { -172129, "src/libfrozen/backends/daemon/thread/thread.c: pthread_create failed" },
 { -167975, "src/libfrozen/backends/request/emitter/emitter.c: calloc failed" },
 { -163899, "src/libfrozen/backends/data/transfer/transfer.c: source or destination backend invalid" },
 { -163876, "src/libfrozen/backends/data/transfer/transfer.c: calloc failed" },
 { -159925, "src/libfrozen/backends/io/console/console.c: input key not supplied" },
 { -159911, "src/libfrozen/backends/io/console/console.c: input key not supplied" },
 { -159897, "src/libfrozen/backends/io/console/console.c: output key not supplied" },
 { -159864, "src/libfrozen/backends/io/console/console.c: calloc failed" },
 { -155684, "src/libfrozen/backends/backend/end/end.c: calloc failed" },
 { -151600, "src/libfrozen/backends/data/convert/convert.c: calloc failed" },
 { -147546, "src/libfrozen/backends/data/split/split.c: no input string in request" },
 { -147497, "src/libfrozen/backends/data/split/split.c: calloc failed" },
 { -143427, "src/libfrozen/backends/request/implode/implode.c: calloc failed" },
 { -139321, "src/libfrozen/backends/backend/factory/factory.c: child creation error" },
 { -139294, "src/libfrozen/backends/backend/factory/factory.c: HK(config) not supplied" },
 { -139277, "src/libfrozen/backends/backend/factory/factory.c: calloc failed" },
 { -135201, "src/libfrozen/backends/storage/pointers/pointers.c: calloc returns null" },
 { -131131, "src/libfrozen/backends/index/hashtable/hashtable.c: invalid hashtable size" },
 { -131112, "src/libfrozen/backends/index/hashtable/hashtable.c: calloc failed" },
 { -127101, "src/libfrozen/backends/request/switch/switch.c: failed to configure switch" },
 { -127075, "src/libfrozen/backends/request/switch/switch.c: calloc returns null" },
 { -122956, "src/libfrozen/backends/index/fill/fill.c: supplied index backend not valid, or not found" },
 { -122934, "src/libfrozen/backends/index/fill/fill.c: calloc failed" },
 { -119407, "src/libfrozen/backends/io/fuse/fuse.c: fuse fs creation failed" },
 { -114910, "src/libfrozen/backends/data/regexp/regexp.c: can not convert data to string" },
 { -114905, "src/libfrozen/backends/data/regexp/regexp.c: no input string in request" },
 { -114806, "src/libfrozen/backends/data/regexp/regexp.c: calloc failed" },
 { -114787, "src/libfrozen/backends/data/regexp/regexp.c: can not copy marker data" },
 { -114768, "src/libfrozen/backends/data/regexp/regexp.c: invalid regexp supplied - compilation error" },
 { -106537, "src/libfrozen/backends/backend/call/call.c: calloc failed" },
 { -102657, "src/libfrozen/backends/backend/rebuild/rebuild.c: not reader supplied" },
 { -102654, "src/libfrozen/backends/backend/rebuild/rebuild.c: no reader supplied" },
 { -102632, "src/libfrozen/backends/backend/rebuild/rebuild.c: calloc failed" },
 { -102561, "src/libfrozen/backends/backend/rebuild/rebuild.c: calloc failed" },
 { -102495, "src/libfrozen/backends/backend/rebuild/rebuild.c: rebuild max rebuilds reached" },
 { -98399, "src/libfrozen/backends/hash/jenkins/jenkins.c: input key not supplied" },
 { -98377, "src/libfrozen/backends/hash/jenkins/jenkins.c: input key not supplied" },
 { -98345, "src/libfrozen/backends/hash/jenkins/jenkins.c: calloc failed" },
 { -94302, "src/libfrozen/backends/hash/murmur/murmur.c: input key not supplied" },
 { -94281, "src/libfrozen/backends/hash/murmur/murmur.c: input key not supplied" },
 { -94249, "src/libfrozen/backends/hash/murmur/murmur.c: calloc failed" },
 { -90189, "src/libfrozen/backends/index/lookup/lookup.c: supplied index backend not valid, or not found" },
 { -90166, "src/libfrozen/backends/index/lookup/lookup.c: calloc failed" },
 { -86097, "src/libfrozen/backends/backend/morph/morph.c: child creation error" },
 { -86074, "src/libfrozen/backends/backend/morph/morph.c: HK(config) not supplied" },
 { -86057, "src/libfrozen/backends/backend/morph/morph.c: calloc failed" },
 { -73860, "src/libfrozen/backends/backend/benchmark/benchmark.c: calloc failed" },
 { -69690, "src/libfrozen/backends/request/debug/debug.c: calloc failed" },
 { -65907, "src/libfrozen/backends/backend/pool/pool.c: pthread_join failed" },
 { -65903, "src/libfrozen/backends/backend/pool/pool.c: pthread_cancel failed" },
 { -65874, "src/libfrozen/backends/backend/pool/pool.c: pthread_create failed" },
 { -65864, "src/libfrozen/backends/backend/pool/pool.c: calloc failed" },
 { -61770, "src/libfrozen/backends/request/balancer/balancer.c: fork error (resume)" },
 { -61762, "src/libfrozen/backends/request/balancer/balancer.c: fork error" },
 { -61759, "src/libfrozen/backends/request/balancer/balancer.c: data_read failed" },
 { -61755, "src/libfrozen/backends/request/balancer/balancer.c: field not supplied" },
 { -61723, "src/libfrozen/backends/request/balancer/balancer.c: no childs" },
 { -61680, "src/libfrozen/backends/request/balancer/balancer.c: malloc failed" },
 { -61661, "src/libfrozen/backends/request/balancer/balancer.c: fork failed" },
 { -61633, "src/libfrozen/backends/request/balancer/balancer.c: invalid linear_len supplied" },
 { -61576, "src/libfrozen/backends/request/balancer/balancer.c: calloc returns null" },
 { -57513, "src/libfrozen/backends/rest/insert_sort/insert_sort.c: no key_out supplied" },
 { -57512, "src/libfrozen/backends/rest/insert_sort/insert_sort.c: no buffer supplied" },
 { -57501, "src/libfrozen/backends/rest/insert_sort/insert_sort.c: backend insert-sort engine not found" },
 { -57492, "src/libfrozen/backends/rest/insert_sort/insert_sort.c: backend insert-sort parameter engine not supplied" },
 { -57465, "src/libfrozen/backends/rest/insert_sort/insert_sort.c: calloc failed" },
 { -57433, "src/libfrozen/backends/rest/insert_sort/insert_sort.m4: no key_out supplied" },
 { -57432, "src/libfrozen/backends/rest/insert_sort/insert_sort.m4: no buffer supplied" },
 { -57421, "src/libfrozen/backends/rest/insert_sort/insert_sort.m4: backend insert-sort engine not found" },
 { -57412, "src/libfrozen/backends/rest/insert_sort/insert_sort.m4: backend insert-sort parameter engine not supplied" },
 { -57385, "src/libfrozen/backends/rest/insert_sort/insert_sort.m4: calloc failed" },
 { -53453, "src/libfrozen/backends/request/rewrite/rewrite.c: pass failed" },
 { -53335, "src/libfrozen/backends/request/rewrite/rewrite.c: script parse failed" },
 { -53332, "src/libfrozen/backends/request/rewrite/rewrite.c: script not supplied" },
 { -53312, "src/libfrozen/backends/request/rewrite/rewrite.c: calloc failed" },
 { -49906, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: delete not supported" },
 { -49659, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: recalc db inconsistency" },
 { -49629, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: set_g failed" },
 { -49613, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: get_g failed" },
 { -49595, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: find_edge db inconsistency" },
 { -49568, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: set_edge failed" },
 { -49541, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: get_edge failed" },
 { -49523, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: set first failed" },
 { -49508, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: get_first failed" },
 { -49490, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: new_edge_id failed" },
 { -49463, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: mphf is read-only" },
 { -49425, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: too many elements" },
 { -49393, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: backend chm_imp parameter backend_g invalid" },
 { -49334, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: v array init failed" },
 { -49330, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: g array init failed" },
 { -49295, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: g array delete failed" },
 { -49286, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: g array delete failed" },
 { -49277, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: g array delete failed" },
 { -49262, "src/libfrozen/backends/index/mphf/mphf_chm_imp.c: params write failed" },
 { -45148, "src/libfrozen/backends/index/mphf/mphf.c: calloc failed" },
 { -45128, "src/libfrozen/backends/index/mphf/mphf.c: backend mphf parameter mphf_type invalid or not supplied" },
 { -41243, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: strange error 3" },
 { -41223, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: can not write buffer to ipc memory" },
 { -41217, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: strange error" },
 { -41173, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: pthread_create failed" },
 { -41169, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: shmem_init failed" },
 { -41154, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: force_async with force_sync" },
 { -41151, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: invalid role supplied" },
 { -41148, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: shmat failed" },
 { -41145, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: shmget failed" },
 { -41134, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: no role supplied" },
 { -41133, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: no key supplied" },
 { -41115, "src/libfrozen/backends/communication/ipc/ipc_shmem.c: ipc_shmem_listen dead" },
 { -36934, "src/libfrozen/backends/communication/ipc/ipc.c: backend ipc parameter type invalid" },
 { -36914, "src/libfrozen/backends/communication/ipc/ipc.c: calloc failed" },
 { -32832, "src/libfrozen/backends/data/allocator/allocator.c: no size_old supplied" },
 { -32831, "src/libfrozen/backends/data/allocator/allocator.c: no size supplied" },
 { -32830, "src/libfrozen/backends/data/allocator/allocator.c: no offset supplied" },
 { -32793, "src/libfrozen/backends/data/allocator/allocator.c: no size supplied" },
 { -32792, "src/libfrozen/backends/data/allocator/allocator.c: no offset supplied" },
 { -28755, "src/libfrozen/backends/data/incapsulate/incapsulate.c: backend incapsulate parameter multiply invalid" },
 { -28721, "src/libfrozen/backends/data/incapsulate/incapsulate.c: calloc failed" },
 { -24727, "src/libfrozen/backends/data/structs/structs.c: struct_unpack failed" },
 { -24722, "src/libfrozen/backends/data/structs/structs.c: hash with keys not supplied" },
 { -24694, "src/libfrozen/backends/data/structs/structs.c: struct_pack failed" },
 { -24679, "src/libfrozen/backends/data/structs/structs.c: hash with keys not supplied" },
 { -24662, "src/libfrozen/backends/data/structs/structs.c: backend struct parameter structure invalid" },
 { -24660, "src/libfrozen/backends/data/structs/structs.c: backend struct parameter buffer invalid" },
 { -24633, "src/libfrozen/backends/data/structs/structs.c: calloc failed" },
 { -20677, "src/libfrozen/backends/cache/cache_append/cache_append.c: memory_size failed" },
 { -20661, "src/libfrozen/backends/cache/cache_append/cache_append.c: count failed" },
 { -20629, "src/libfrozen/backends/cache/cache_append/cache_append.c: memory_grow failed" },
 { -20626, "src/libfrozen/backends/cache/cache_append/cache_append.c: no size supplied" },
 { -20621, "src/libfrozen/backends/cache/cache_append/cache_append.c: memory_size failed" },
 { -20549, "src/libfrozen/backends/cache/cache_append/cache_append.c: count failed" },
 { -20540, "src/libfrozen/backends/cache/cache_append/cache_append.c: size too small" },
 { -20518, "src/libfrozen/backends/cache/cache_append/cache_append.c: calloc failed" },
 { -16704, "src/libfrozen/backends/cache/cache/cache.c: calloc failed" },
 { -16592, "src/libfrozen/backends/cache/cache/cache.c: memory_size failed" },
 { -16580, "src/libfrozen/backends/cache/cache/cache.c: cache delete failed" },
 { -16577, "src/libfrozen/backends/cache/cache/cache.c: size not supplied" },
 { -16576, "src/libfrozen/backends/cache/cache/cache.c: offset not supplied" },
 { -16552, "src/libfrozen/backends/cache/cache/cache.c: memory_grow failed" },
 { -16549, "src/libfrozen/backends/cache/cache/cache.c: no size supplied" },
 { -12359, "src/libfrozen/backends/data/list/list.c: no offset supplied" },
 { -12358, "src/libfrozen/backends/data/list/list.c: no size supplied" },
 { -12334, "src/libfrozen/backends/data/list/list.c: no offset supplied" },
 { -8856, "src/libfrozen/backends/storage/file/file.c: no buffer supplied" },
 { -8823, "src/libfrozen/backends/storage/file/file.c: file_update_count failed" },
 { -8820, "src/libfrozen/backends/storage/file/file.c: no buffer supplied" },
 { -8785, "src/libfrozen/backends/storage/file/file.c: io error" },
 { -8775, "src/libfrozen/backends/storage/file/file.c: malloc error" },
 { -8772, "src/libfrozen/backends/storage/file/file.c: size is null" },
 { -8749, "src/libfrozen/backends/storage/file/file.c: file_update_count failed" },
 { -8744, "src/libfrozen/backends/storage/file/file.c: offset_to not supplied" },
 { -8743, "src/libfrozen/backends/storage/file/file.c: offset_from not supplied" },
 { -8716, "src/libfrozen/backends/storage/file/file.c: can not delete not last elements" },
 { -8708, "src/libfrozen/backends/storage/file/file.c: file_update_count failed" },
 { -8701, "src/libfrozen/backends/storage/file/file.c: size not supplied" },
 { -8700, "src/libfrozen/backends/storage/file/file.c: offset not supplied" },
 { -8671, "src/libfrozen/backends/storage/file/file.c: file expand error" },
 { -8665, "src/libfrozen/backends/storage/file/file.c: size not supplied" },
 { -8661, "src/libfrozen/backends/storage/file/file.c: size not supplied" },
 { -8551, "src/libfrozen/backends/storage/file/file.c: calloc returns null" },
 { -8524, "src/libfrozen/backends/storage/file/file.c: file open() error" },
 { -8508, "src/libfrozen/backends/storage/file/file.c: filepath invalid" },
 { -8364, "src/libfrozen/backends/storage/file/file.c: resume error" },
 { -8355, "src/libfrozen/backends/storage/file/file.c: called fork_only file" },
 { -5670, "src/libfrozen/core/configs/config_parser.tab.c: wrong constant" },
 { -4627, "src/libfrozen/backends/rest/blocks_addressing/blocks_addressing.c: no block_vid supplied" },
 { -4622, "src/libfrozen/backends/rest/blocks_addressing/blocks_addressing.c: no offset supplied" },
 { -4583, "src/libfrozen/backends/rest/blocks_addressing/blocks_addressing.c: no block_size supplied" },
 { -4571, "src/libfrozen/backends/rest/blocks_addressing/blocks_addressing.c: chain blocks-address tree recalc failed" },
 { -4567, "src/libfrozen/backends/rest/blocks_addressing/blocks_addressing.c: chain blocks-address no memory" },
 { -4505, "src/libfrozen/backends/rest/blocks/blocks.c: no offset_to supplied" },
 { -4504, "src/libfrozen/backends/rest/blocks/blocks.c: no offset_from supplied" },
 { -4493, "src/libfrozen/backends/rest/blocks/blocks.c: no size supplied" },
 { -4492, "src/libfrozen/backends/rest/blocks/blocks.c: no offset supplied" },
 { -4393, "src/libfrozen/backends/rest/blocks/blocks.c: chain blocks variable 'backend' invalid" },
 { -4390, "src/libfrozen/backends/rest/blocks/blocks.c: chain blocks variable 'backend' not set" },
 { -4387, "src/libfrozen/backends/rest/blocks/blocks.c: chain blocks variable 'block_size' invalid" },
 { -4222, "src/libfrozen/backends/index/mphf/mphf_bdz_imp.c: mphf g_free" },

};
#define            errs_list_size      sizeof(errs_list[0])
#define            errs_list_nelements sizeof(errs_list) / errs_list_size
