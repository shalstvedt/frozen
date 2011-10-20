#ifndef HASH_H
#define HASH_H

#include <hashkeys.h>

struct hash_t {
	hash_key_t      key;
	data_t          data;
};

typedef enum hash_iter_flags {
	HASH_ITER_NULL = 1,
	HASH_ITER_END  = 2
} hash_iter_flags;

typedef ssize_t  (*hash_iterator)(hash_t *, void *);

#define hash_ptr_null     (hash_key_t)-1
#define hash_ptr_end      (hash_key_t)-2 
#define hash_ptr_inline   (hash_key_t)-3

#define hash_null         {hash_ptr_null,    {0, NULL}}
#define hash_inline(hash) {hash_ptr_inline,  DATA_PTR_HASHT(hash)}
#define hash_next(hash)   {hash_ptr_end,     {0, (void *)hash}} // TODO deprecate
#define hash_end          hash_next(NULL)
#define HK(value)         HASH_KEY_##value

// allocated hash functions
API hash_t *           hash_new                     (size_t nelements);
API hash_t *           hash_copy                    (hash_t *hash);
API void               hash_free                    (hash_t *hash);

// general functions
API hash_t *           hash_find                    (hash_t *hash, hash_key_t key);
API ssize_t            hash_iter                    (hash_t *hash, hash_iterator func, void *arg1, hash_iter_flags flags);
API size_t             hash_nelements               (hash_t *hash);

_inline
API hash_key_t         hash_item_key                (hash_t *hash){ return hash->key; }
_inline
API size_t             hash_item_is_null            (hash_t *hash){ return (hash->key == hash_ptr_null); }
_inline
API data_t *           hash_item_data               (hash_t *hash){ return &(hash->data); }
_inline
API data_t *           hash_data_find               (hash_t *hash, hash_key_t key){
	hash_t *temp;
	return ((temp = hash_find(hash, key)) == NULL) ?
		NULL : hash_item_data(temp);
}

#define hash_data_copy(_ret,_type,_dt,_hash,_key){                  \
	data_get(_ret,                                              \
		_type,                                              \
		_dt,                                                \
		hash_data_find(_hash,_key)                          \
	);                                                          \
	(void)_ret;                                                 \
};

#define hash_assign_hash_t(_dst, _src) {        \
	memcpy((_dst), (_src), sizeof(hash_t)); \
}
#define hash_assign_hash_null(_dst) {  \
	(_dst)->key = hash_ptr_null;   \
	(_dst)->data.type = TYPE_VOIDT;\
	(_dst)->data.ptr = NULL;       \
}
#define hash_assign_hash_end(_dst) {  \
	(_dst)->key = hash_ptr_end;   \
	(_dst)->data.ptr = NULL;      \
}


#ifdef DEBUG
API void               hash_dump                    (hash_t *hash);
#endif

#endif // HASH_H
