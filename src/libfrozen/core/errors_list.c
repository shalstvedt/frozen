
static err_item errs_list[] = {
 { -221506, "src/libfrozen/machines/shop/try/try.c: shop parameter not supplied" },
 { -221475, "src/libfrozen/machines/shop/try/try.c: malloc failed" },
 { -221469, "src/libfrozen/machines/shop/try/try.c: malloc failed" },
 { -221462, "src/libfrozen/machines/shop/try/try.c: calloc failed" },
 { -221184, "unknown error in module shop/try" },
 { -217331, "src/libfrozen/data/storage/folder/folder_t.c: path not exist" },
 { -217325, "src/libfrozen/data/storage/folder/folder_t.c: path invalid" },
 { -217319, "src/libfrozen/data/storage/folder/folder_t.c: path not supplied" },
 { -217316, "src/libfrozen/data/storage/folder/folder_t.c: calloc returns null" },
 { -217088, "unknown error in module storage/folder" },
 { -213256, "src/libfrozen/machines/data/query/query.c: data not supplied" },
 { -213235, "src/libfrozen/machines/data/query/query.c: calloc failed" },
 { -212992, "unknown error in module data/query" },
 { -208896, "unknown error in module enum/action" },
 { -201008, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: bad underlying storage" },
 { -201001, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: bad item size" },
 { -200994, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: bad item_sample" },
 { -200988, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: no item_size nor item_sample supplied" },
 { -200981, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: invalid storage supplied" },
 { -200973, "src/libfrozen/data/allocator/fixed/allocator_fixed_t.c: calloc failed" },
 { -200704, "unknown error in module allocator/fixed" },
 { -192795, "src/libfrozen/data/enum/format/format_t.c: format collision" },
 { -192512, "unknown error in module enum/format" },
 { -188726, "src/libfrozen/data/enum/hashkey/hashkey_t.c: key collision" },
 { -188416, "unknown error in module enum/hashkey" },
 { -180470, "src/libfrozen/machines/sync/mutex/mutex.c: pthread_mutex_init failed" },
 { -180467, "src/libfrozen/machines/sync/mutex/mutex.c: pthread_mutexattr_settype failed" },
 { -180464, "src/libfrozen/machines/sync/mutex/mutex.c: pthread_mutexattr_init failed" },
 { -180461, "src/libfrozen/machines/sync/mutex/mutex.c: calloc failed" },
 { -180224, "unknown error in module sync/mutex" },
 { -176371, "src/libfrozen/machines/request/assign/assign.c: calloc returns null" },
 { -176140, "src/libfrozen/machines/request/assign/assign.c: ENOMEM in module request/assign" },
 { -176128, "unknown error in module request/assign" },
 { -172404, "src/libfrozen/machines/io/tcp/tcp.c: pthread_setspecific error" },
 { -172397, "src/libfrozen/machines/io/tcp/tcp.c: calloc failed" },
 { -172372, "src/libfrozen/machines/io/tcp/tcp.c: pthread_setspecific error" },
 { -172369, "src/libfrozen/machines/io/tcp/tcp.c: pthread_setspecific error" },
 { -172366, "src/libfrozen/machines/io/tcp/tcp.c: accept error" },
 { -172330, "src/libfrozen/machines/io/tcp/tcp.c: calloc failed" },
 { -172311, "src/libfrozen/machines/io/tcp/tcp.c: listen error" },
 { -172308, "src/libfrozen/machines/io/tcp/tcp.c: bind error" },
 { -172300, "src/libfrozen/machines/io/tcp/tcp.c: socket error" },
 { -172046, "src/libfrozen/machines/io/tcp/tcp.c: EFAULT in module io/tcp" },
 { -172032, "unknown error in module io/tcp" },
 { -168251, "src/libfrozen/machines/daemon/thread/thread.c: calloc failed" },
 { -168227, "src/libfrozen/machines/daemon/thread/thread.c: pthread_create failed" },
 { -167974, "src/libfrozen/machines/daemon/thread/thread.c: ENOSYS in module daemon/thread" },
 { -167950, "src/libfrozen/machines/daemon/thread/thread.c: EFAULT in module daemon/thread" },
 { -167936, "unknown error in module daemon/thread" },
 { -164081, "src/libfrozen/machines/request/emitter/emitter.c: calloc failed" },
 { -163840, "unknown error in module request/emitter" },
 { -156029, "src/libfrozen/machines/io/console/console.c: input key not supplied" },
 { -156015, "src/libfrozen/machines/io/console/console.c: input key not supplied" },
 { -156001, "src/libfrozen/machines/io/console/console.c: output key not supplied" },
 { -155968, "src/libfrozen/machines/io/console/console.c: calloc failed" },
 { -155686, "src/libfrozen/machines/io/console/console.c: ENOSYS in module io/console" },
 { -155648, "unknown error in module io/console" },
 { -151809, "src/libfrozen/machines/request/end/end.c: calloc failed" },
 { -151552, "unknown error in module request/end" },
 { -139504, "src/libfrozen/machines/request/implode/implode.c: calloc failed" },
 { -139264, "unknown error in module request/implode" },
 { -135401, "src/libfrozen/machines/machine/factory/factory.c: HK(config) not supplied" },
 { -135382, "src/libfrozen/machines/machine/factory/factory.c: calloc failed" },
 { -135190, "src/libfrozen/machines/machine/factory/factory.c: EINVAL in module machine/factory" },
 { -135168, "unknown error in module machine/factory" },
 { -127236, "src/libfrozen/machines/index/hashtable/hashtable.c: invalid hashtable size" },
 { -127217, "src/libfrozen/machines/index/hashtable/hashtable.c: calloc failed" },
 { -126976, "unknown error in module index/hashtable" },
 { -123205, "src/libfrozen/machines/request/switch/switch.c: failed to configure switch" },
 { -123179, "src/libfrozen/machines/request/switch/switch.c: calloc returns null" },
 { -122880, "unknown error in module request/switch" },
 { -119058, "src/libfrozen/machines/index/fill/fill.c: supplied index machine not valid, or not found" },
 { -119038, "src/libfrozen/machines/index/fill/fill.c: calloc failed" },
 { -118784, "unknown error in module index/fill" },
 { -115534, "src/libfrozen/machines/io/fuse/fuse.c: fuse items confguration failed" },
 { -115531, "src/libfrozen/machines/io/fuse/fuse.c: fuse fs creation failed" },
 { -115527, "src/libfrozen/machines/io/fuse/fuse.c: mountpoint not supplied" },
 { -114726, "src/libfrozen/machines/io/fuse/fuse.c: ENOSYS in module io/fuse" },
 { -114700, "src/libfrozen/machines/io/fuse/fuse.c: ENOMEM in module io/fuse" },
 { -114690, "src/libfrozen/machines/io/fuse/fuse.c: ENOENT in module io/fuse" },
 { -114688, "unknown error in module io/fuse" },
 { -102773, "src/libfrozen/machines/shop/pass/pass.c: no return address supplied" },
 { -102736, "src/libfrozen/machines/shop/pass/pass.c: shop parameter not supplied" },
 { -102717, "src/libfrozen/machines/shop/pass/pass.c: calloc failed" },
 { -102400, "unknown error in module shop/pass" },
 { -94502, "src/libfrozen/machines/hash/jenkins/jenkins.c: input key not supplied" },
 { -94481, "src/libfrozen/machines/hash/jenkins/jenkins.c: input key not supplied" },
 { -94450, "src/libfrozen/machines/hash/jenkins/jenkins.c: calloc failed" },
 { -94208, "unknown error in module hash/jenkins" },
 { -90405, "src/libfrozen/machines/hash/murmur/murmur.c: input key not supplied" },
 { -90385, "src/libfrozen/machines/hash/murmur/murmur.c: input key not supplied" },
 { -90354, "src/libfrozen/machines/hash/murmur/murmur.c: calloc failed" },
 { -90112, "unknown error in module hash/murmur" },
 { -86271, "src/libfrozen/machines/index/lookup/lookup.c: supplied index machine not valid, or not found" },
 { -86254, "src/libfrozen/machines/index/lookup/lookup.c: calloc failed" },
 { -86016, "unknown error in module index/lookup" },
 { -82182, "src/libfrozen/machines/machine/morph/morph.c: HK(config) not supplied" },
 { -82163, "src/libfrozen/machines/machine/morph/morph.c: calloc failed" },
 { -81920, "unknown error in module machine/morph" },
 { -73986, "src/libfrozen/machines/request/delay/delay.c: calloc failed" },
 { -73728, "unknown error in module request/delay" },
 { -69965, "src/libfrozen/machines/machine/benchmark/benchmark.c: calloc failed" },
 { -69632, "unknown error in module machine/benchmark" },
 { -65795, "src/libfrozen/machines/request/debug/debug.c: calloc failed" },
 { -65536, "unknown error in module request/debug" },
 { -62004, "src/libfrozen/machines/machine/limit/limit.c: pthread_join failed" },
 { -62000, "src/libfrozen/machines/machine/limit/limit.c: pthread_cancel failed" },
 { -61971, "src/libfrozen/machines/machine/limit/limit.c: pthread_create failed" },
 { -61961, "src/libfrozen/machines/machine/limit/limit.c: calloc failed" },
 { -61449, "src/libfrozen/machines/machine/limit/limit.c: EBADF in module machine/limit" },
 { -61440, "unknown error in module machine/limit" },
 { -57628, "src/libfrozen/machines/machine/pool/pool.c: config not supplied" },
 { -57608, "src/libfrozen/machines/machine/pool/pool.c: calloc failed" },
 { -57382, "src/libfrozen/machines/machine/pool/pool.c: ENOSYS in module machine/pool" },
 { -57344, "unknown error in module machine/pool" },
 { -37350, "src/libfrozen/machines/io/ipc/ipc_shmem.c: strange error 3" },
 { -37330, "src/libfrozen/machines/io/ipc/ipc_shmem.c: can not write buffer to ipc memory" },
 { -37324, "src/libfrozen/machines/io/ipc/ipc_shmem.c: strange error" },
 { -37280, "src/libfrozen/machines/io/ipc/ipc_shmem.c: pthread_create failed" },
 { -37276, "src/libfrozen/machines/io/ipc/ipc_shmem.c: shmem_init failed" },
 { -37261, "src/libfrozen/machines/io/ipc/ipc_shmem.c: force_async with force_sync" },
 { -37258, "src/libfrozen/machines/io/ipc/ipc_shmem.c: shmat failed" },
 { -37255, "src/libfrozen/machines/io/ipc/ipc_shmem.c: shmget failed" },
 { -37248, "src/libfrozen/machines/io/ipc/ipc_shmem.c: invalid role supplied" },
 { -37239, "src/libfrozen/machines/io/ipc/ipc_shmem.c: no role supplied" },
 { -37238, "src/libfrozen/machines/io/ipc/ipc_shmem.c: no key supplied" },
 { -37220, "src/libfrozen/machines/io/ipc/ipc_shmem.c: ipc_shmem_listen dead" },
 { -36878, "src/libfrozen/machines/io/ipc/ipc_shmem.c: EFAULT in module io/ipc" },
 { -36864, "unknown error in module io/ipc" },
 { -33041, "src/libfrozen/machines/io/ipc/ipc.c: machine ipc parameter type invalid" },
 { -33038, "src/libfrozen/machines/io/ipc/ipc.c: machine ipc type not supplied" },
 { -33019, "src/libfrozen/machines/io/ipc/ipc.c: calloc failed" },
 { -32768, "unknown error in module io/ipc" },
 { -20831, "src/libfrozen/machines/data/structs/structs.c: struct_unpack failed" },
 { -20826, "src/libfrozen/machines/data/structs/structs.c: hash with keys not supplied" },
 { -20800, "src/libfrozen/machines/data/structs/structs.c: struct_pack failed" },
 { -20785, "src/libfrozen/machines/data/structs/structs.c: hash with keys not supplied" },
 { -20768, "src/libfrozen/machines/data/structs/structs.c: machine struct parameter structure invalid" },
 { -20766, "src/libfrozen/machines/data/structs/structs.c: machine struct parameter buffer invalid" },
 { -20740, "src/libfrozen/machines/data/structs/structs.c: calloc failed" },
 { -20480, "unknown error in module data/structs" },
 { -4378, "src/libfrozen/data/storage/file/file_t.c: file open() error" },
 { -4359, "src/libfrozen/data/storage/file/file_t.c: filename invalid" },
 { -4351, "src/libfrozen/data/storage/file/file_t.c: filename not supplied" },
 { -4339, "src/libfrozen/data/storage/file/file_t.c: calloc returns null" },
 { -4096, "unknown error in module storage/file" },

};
#define            errs_list_size      sizeof(errs_list[0])
#define            errs_list_nelements sizeof(errs_list) / errs_list_size
