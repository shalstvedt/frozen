/* Autogenerated file. Don't edit */
#ifndef MACHINE_SELECTED_H
#define MACHINE_SELECTED_H
extern machine_t cache_proto;
extern machine_t cache_append_proto;
extern machine_t kill_proto;
extern machine_t thread_proto;
extern machine_t convert_proto;
extern machine_t incapsulate_proto;
extern machine_t query_proto;
extern machine_t regexp_proto;
extern machine_t split_proto;
extern machine_t struct_pack_proto;
extern machine_t struct_unpack_proto;
extern machine_t transfer_proto;
extern machine_t jenkins32_proto;
extern machine_t jenkins64_proto;
extern machine_t murmur2_32_proto;
extern machine_t murmur2_64_proto;
extern machine_t fill_proto;
extern machine_t hashtable_proto;
extern machine_t lookup_proto;
extern machine_t mphf_proto;
extern machine_t stdin_proto;
extern machine_t stdout_proto;
extern machine_t stderr_proto;
extern machine_t fuse_proto;
extern machine_t ipc_proto;
extern machine_t tcp_proto;
extern machine_t tcp_child_proto;
extern machine_t benchmark_proto;
extern machine_t factory_proto;
extern machine_t morph_proto;
extern machine_t pool_proto;
extern machine_t rebuild_monitor_proto;
extern machine_t rebuild_reader_proto;
extern machine_t assign_proto;
extern machine_t debug_proto;
extern machine_t emitter_proto;
extern machine_t end_proto;
extern machine_t implode_proto;
extern machine_t explode_proto;
extern machine_t null_proto;
extern machine_t switch_proto;
extern machine_t pass_proto;
extern machine_t mutex_proto;
#ifdef MACHINE_C
machine_t * machine_protos[] = {
   &cache_proto,
   &cache_append_proto,
   &kill_proto,
   &thread_proto,
   &convert_proto,
   &incapsulate_proto,
   &query_proto,
   &regexp_proto,
   &split_proto,
   &struct_pack_proto,
   &struct_unpack_proto,
   &transfer_proto,
   &jenkins32_proto,
   &jenkins64_proto,
   &murmur2_32_proto,
   &murmur2_64_proto,
   &fill_proto,
   &hashtable_proto,
   &lookup_proto,
   &mphf_proto,
   &stdin_proto,
   &stdout_proto,
   &stderr_proto,
   &fuse_proto,
   &ipc_proto,
   &tcp_proto,
   &tcp_child_proto,
   &benchmark_proto,
   &factory_proto,
   &morph_proto,
   &pool_proto,
   &rebuild_monitor_proto,
   &rebuild_reader_proto,
   &assign_proto,
   &debug_proto,
   &emitter_proto,
   &end_proto,
   &implode_proto,
   &explode_proto,
   &null_proto,
   &switch_proto,
   &pass_proto,
   &mutex_proto,
};
size_t machine_protos_size = (sizeof(machine_protos)/sizeof(machine_protos[0]));
#endif
#endif
