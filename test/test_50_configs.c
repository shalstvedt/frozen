
START_TEST (test_configs){
	hash_t *hash, *key1, *key2, *key3, *key4, *subhash;
	
	char   test1[] = "key1 = 'hello1', key2 : \"hello2\", key3 => 'hello3'";
	hash = configs_string_parse(test1);
		if(hash == NULL){
			fail("configs test1 failed");
			return;
		}
	
	fail_unless( (key1 = hash_find(hash, HK(key1))) != NULL, "hash not found existing entry");
	fail_unless( (key2 = hash_find(hash, HK(key2))) != NULL, "hash not found existing entry");
	fail_unless( (key3 = hash_find(hash, HK(key3))) != NULL, "hash not found existing entry");
	fail_unless( (hash_find(hash, 7777)) == NULL,      "hash found not existing entry");
	
	//fail_unless(strcmp(key1->data.ptr, "hello1") == 0, "hash found wrong entry");
	//fail_unless(strcmp(key2->data.ptr, "hello2") == 0, "hash found wrong entry");
	//fail_unless(strcmp(key3->data.ptr, "hello3") == 0, "hash found wrong entry");
	
	hash_free(hash);
	
	char   test2[] = "key1 => { key3 => 'hello1', key4 => \"hello2\"}, key2 => 'hello3'";
	hash = configs_string_parse(test2);
		if(hash == NULL){
			fail("configs test1 failed");
			return;
		}
	
	fail_unless( (key1 = hash_find(hash, HK(key1))) != NULL, "hash not found existing entry");
	fail_unless( (key2 = hash_find(hash, HK(key2))) != NULL, "hash not found existing entry");
	
	subhash = (hash_t *)key1->data.ptr;
	fail_unless( (key3 = hash_find(subhash, HK(key3))) != NULL, "hash not found existing entry");
	fail_unless( (key4 = hash_find(subhash, HK(key4))) != NULL, "hash not found existing entry");
	fail_unless( (hash_find(subhash, 7777))      == NULL, "hash found not existing entry");
	
	//fail_unless(strcmp(key2->data.ptr, "hello3") == 0, "hash found wrong entry");
	//fail_unless(strcmp(key3->data.ptr, "hello1") == 0, "hash found wrong entry");
	//fail_unless(strcmp(key4->data.ptr, "hello2") == 0, "hash found wrong entry");
	
	hash_free(hash);
}
END_TEST
REGISTER_TEST(core, test_configs)

