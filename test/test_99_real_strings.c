
START_TEST (test_real_store_strings){
	hash_t config[] = {
                { 0, DATA_HASHT(
                        { HK(class),     DATA_STRING("file")                        },
                        { HK(filename),  DATA_STRING("data_real_store_strings.dat") },
                        hash_end
                )},
		hash_end
	};
	
	machine_t  *machine = machine_new(config);
	
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
	ssize_t  ret;
	
	for(i=0; i < sizeof(data_array) / sizeof(char *); i++){
		request_t r_write[] = {
			{ HK(action),     DATA_UINT32T(ACTION_CREATE)                          },
			{ HK(offset_out), DATA_PTR_OFFT(&data_ptrs[i])                              },
			{ HK(buffer),     DATA_PTR_STRING(data_array[i])                            },
			{ HK(size),       DATA_UINT32T(strlen(data_array[i])+1)                     },
			{ HK(ret),        DATA_PTR_SIZET(&ret)                                      },
                        hash_end
		};
		machine_query(machine, r_write);
			fail_unless(ret == 0, "machine real_store_strings: write array failed");
	}
	
	// check
	char data_read[1024];
	for(i=0; i < sizeof(data_array) / sizeof(char *); i++){
		request_t r_read[] = {
			{ HK(action), DATA_UINT32T(ACTION_READ)    },
			{ HK(offset), DATA_OFFT(data_ptrs[i])           },
			{ HK(buffer), DATA_RAW(&data_read, 1024)        },
			{ HK(ret),    DATA_PTR_SIZET(&ret)              },
                        hash_end
		};
		machine_query(machine, r_read);
			fail_unless(ret == 0,                              "machine real_store_strings: read array failed");
			fail_unless(strcmp(data_read, data_array[i]) == 0, "machine real_store_strings: read array data failed");
	}
	
	machine_destroy(machine);
}
END_TEST
REGISTER_TEST(core, test_real_store_strings)

