#include "test.h"

START_TEST (test_backend_list){
	backend_t *backend;
	
	setting_set_child_string(global_settings, "homedir", ".");
	
	setting_t *settings = setting_new();
		setting_t *s_file = setting_new();
			setting_set_child_string(s_file, "name",        "file");
			setting_set_child_string(s_file, "filename",    "data_backend_list");
	setting_t *s_list = setting_new();
			setting_set_child_string(s_list, "name",        "list");
	setting_set_child_setting(settings, s_file);
	setting_set_child_setting(settings, s_list);
	
	backend = backend_new("in_list", settings);
		fail_unless(backend != NULL, "backend creation failed");
	
	unsigned int  action;
	ssize_t       ssize;
	buffer_t     *buffer = buffer_alloc();
	hash_t       *hash   = hash_new();

	off_t         key_off;
	off_t         key_insert_off;
	char          key_data[]     = "0123456789";
	char          key_insert[]   = "a";
	char          key_inserted[] = "01a23456789";
	char          key_delete[]   = "01a3456789";
	buffer_t *    key_inserted_buff = buffer_alloc_from_bare(&key_inserted, sizeof(key_inserted));
	buffer_t *    key_delete_buff   = buffer_alloc_from_bare(&key_delete,   sizeof(key_delete));
	
	action  = ACTION_CRWD_CREATE;
	ssize   = 10;
		hash_set(hash, "action", TYPE_INT32, &action);
		hash_set(hash, "size",   TYPE_INT32,  &ssize);
		
		if( (ssize = backend_query(backend, hash, buffer)) != sizeof(off_t) )
			fail("chain in_list create failed");	
		buffer_read(buffer, 0, &key_off, MIN(ssize, sizeof(off_t)));
	
	action  = ACTION_CRWD_WRITE;
	ssize   = 10;
		hash_set(hash, "action", TYPE_INT32,  &action);
		hash_set(hash, "key",    TYPE_INT64,  &key_off);
		hash_set(hash, "size",   TYPE_INT32,  &ssize);
	 	
		buffer_write(buffer, 0, &key_data, ssize);
		
		ssize = backend_query(backend, hash, buffer);
			fail_unless(ssize == 10, "backend in_list write 1 failed");
	
	hash_empty(hash);
	
	// insert key
	key_insert_off = key_off + 2;
	ssize   = 1;
		hash_set(hash, "action", TYPE_INT32,  &action);
		hash_set(hash, "key",    TYPE_INT64,  &key_insert_off);
		hash_set(hash, "insert", TYPE_INT32,  &ssize); // = 1
		hash_set(hash, "size",   TYPE_INT32,  &ssize); // = 1
	 	
		buffer_write(buffer, 0, &key_insert, ssize);
		
		ssize = backend_query(backend, hash, buffer);
			fail_unless(ssize == 1,  "backend in_list write 2 failed");
	
	// check
	action  = ACTION_CRWD_READ;
	ssize   = 11;
		hash_set(hash, "action", TYPE_INT32,  &action);
		hash_set(hash, "key",    TYPE_INT64,  &key_off);
		hash_set(hash, "size",   TYPE_INT32,  &ssize);
		
		buffer_cleanup(buffer);
		
		ssize = backend_query(backend, hash, buffer);
			fail_unless(ssize == 11,                                "backend in_list read 1 failed");
			fail_unless(
				buffer_memcmp(buffer, 0, key_inserted_buff, 0, ssize) == 0,
				"backend in_list read 1 data failed"
			);
	// delete key
	key_insert_off = key_off + 3;
	action  = ACTION_CRWD_DELETE;
	ssize   = 1;
		hash_set(hash, "action", TYPE_INT32,  &action);
		hash_set(hash, "key",    TYPE_INT64,  &key_insert_off);
		hash_set(hash, "size",   TYPE_INT32,  &ssize); // = 1
	 	
		ssize = backend_query(backend, hash, buffer);
			fail_unless(ssize == 0,  "backend in_list delete failed");
	
	// check
	action  = ACTION_CRWD_READ;
	ssize   = 10;
		hash_set(hash, "action", TYPE_INT32,  &action);
		hash_set(hash, "key",    TYPE_INT64,  &key_off);
		hash_set(hash, "size",   TYPE_INT32,  &ssize);
		
		ssize = backend_query(backend, hash, buffer);
			fail_unless(ssize == 10,                                "backend in_list read 1 failed");
			fail_unless(
				buffer_memcmp(buffer, 0, key_delete_buff, 0, 10) == 0,
				"backend in_list read 1 data failed"
			);
	
	hash_free(hash);
	buffer_free(buffer);
	
	buffer_free(key_inserted_buff);
	buffer_free(key_delete_buff);
	
	backend_destory(backend);
	setting_destroy(settings);
}
END_TEST
REGISTER_TEST(core, test_backend_list)

