#include <test.h>

START_TEST (test_real_store_idx_strings){
	ssize_t  ret;
	
	hash_t     *c_idx = configs_file_parse("test_99_real_idx_str.conf");
		fail_unless(c_idx != NULL, "chain 'real_store_idx_str' config parse failed");
	ret = backend_bulk_new(c_idx);
		fail_unless(ret == 0,      "chain 'real_store_idx_str' backends create failed");
	hash_free(c_idx);
	
	data_t     n_idx = DATA_STRING("be_file"), n_dat = DATA_STRING("be_file_dat");
	backend_t *b_idx = backend_find(&n_idx);
	backend_t *b_dat = backend_find(&n_dat);
	
	off_t  data_ptrs[6];
	char  *data_array[] = {
		"http://google.ru/",
		"http://yandex.ru/",
		"http://bing.com/",
		"http://rambler.ru/",
		"http://aport.ru/",
		"http://hell.com/"
	};
	
	// write array to file
	int      i;
	
	for(i=0; i < sizeof(data_array) / sizeof(char *); i++){
		request_t r_write[] = {
			{ "action",  DATA_INT32 (ACTION_CRWD_WRITE)                           },
			{ "key_out", DATA_PTR_OFFT   (&data_ptrs[i])                          },
			{ "buffer",  DATA_PTR_STRING (data_array[i], strlen(data_array[i])+1) },
			hash_end
		};
		ret = backend_query(b_idx, r_write);
			fail_unless(ret > 0,    "chain 'real_store_idx_str': write array failed");
		
		//printf("writing: ret: %x, ptr: %d, str: %s\n", ret, (unsigned int)data_ptrs[i], data_array[i]);
	}
	
	// check
	char data_read[1024], data_last[1024];
	
	memset(data_last, 0, 1024);
	for(i=0; i < sizeof(data_array) / sizeof(char *); i++){
		memset(data_read, 0, 1024);
		
		request_t r_read[] = {
			{ "action", DATA_INT32(ACTION_CRWD_READ)      },
			{ "key",    DATA_OFFT(i)                      },
			{ "buffer", DATA_PTR_STRING(&data_read, 1024) },
			hash_end
		};
		ret = backend_query(b_idx, r_read);
			fail_unless(ret > 0,                                "chain 'real_store_idx_str': read array failed");
			fail_unless(memcmp(data_read, data_last, 1024) > 0, "chain 'real_store_idx_str': sort array failed");
		
		//printf("reading: ret: %x, ptr: %d, str: %s\n", ret, i, data_read);
		
		memcpy(data_last, data_read, 1024);
	}
	
	backend_destroy(b_idx);
	backend_destroy(b_dat);
}
END_TEST
REGISTER_TEST(core, test_real_store_idx_strings)