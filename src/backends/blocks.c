#include <libfrozen.h>

#define BLOCKS_DBG

typedef struct block_info {
	unsigned int  real_block_off; 
	unsigned int  size;
} block_info;

typedef struct blocks_user_data {
	crwd_fastcall fc_map;
	crwd_fastcall fc_real;
	backend_t    *bk_map;
	chain_t      *ch_real;

	size_t        block_size;
	off_t         blocks_count;
	request_t    *layer_count;
	request_t    *layer_get;
	
} blocks_user_data;

// 'blocks' chain splits underlying data space into blocks.
// This is useful for reducing copy time in insert operations

static ssize_t   map_new            (blocks_user_data *data, unsigned int b_off, unsigned int b_size){ // {{{
	int      action;
	
	action = ACTION_CRWD_WRITE;
	hash_set(data->fc_map.request_create, "action",     TYPE_INT32, &action);
	hash_set(data->fc_map.request_create, "block_off",  TYPE_INT32, &b_off);
	hash_set(data->fc_map.request_create, "block_size", TYPE_INT32, &b_size);
	
	return backend_query(data->bk_map, data->fc_map.request_create, NULL);
} // }}}
static ssize_t   map_insert         (blocks_user_data *data, unsigned int b_vid, unsigned int b_off, unsigned int b_size){ // {{{
	int      action;
	
	action = ACTION_CRWD_WRITE;
	hash_set(data->fc_map.request_create, "action",     TYPE_INT32, &action);
	hash_set(data->fc_map.request_create, "block_vid",  TYPE_INT32, &b_vid);
	hash_set(data->fc_map.request_create, "block_off",  TYPE_INT32, &b_off);
	hash_set(data->fc_map.request_create, "block_size", TYPE_INT32, &b_size);
	
	return backend_query(data->bk_map, data->fc_map.request_create, NULL);
} // }}}
static ssize_t   map_resize         (blocks_user_data *data, unsigned int b_vid, unsigned int new_size){ // {{{
	hash_set(data->fc_map.request_write, "block_vid",  TYPE_INT32, &b_vid);
	hash_set(data->fc_map.request_write, "block_size", TYPE_INT32, &new_size);
	
	return backend_query(data->bk_map, data->fc_map.request_write, NULL);
} // }}}
/*static ssize_t   map_delete         (blocks_user_data *data, unsigned int b_vid){ // {{{
	hash_set(data->fc_map.request_delete, "block_vid", TYPE_INT32, &b_vid);
	
	return backend_query(data->bk_map, data->fc_map.request_delete, NULL);
} // }}}*/
static ssize_t   map_off            (blocks_user_data *data, off_t virt_off, unsigned int *block_vid, off_t *real_off){ // {{{
	ssize_t  ret;
	ssize_t  buf_ptr = 0;

	hash_set(data->fc_map.request_read, "offset", TYPE_INT64, &virt_off);
	
	ret = backend_query(data->bk_map, data->fc_map.request_read, data->fc_map.buffer_read);
	if(ret > 0){
		buf_ptr += buffer_read(data->fc_map.buffer_read, buf_ptr, real_off,  sizeof(off_t));
		buf_ptr += buffer_read(data->fc_map.buffer_read, buf_ptr, block_vid, sizeof(unsigned int));
	}
	return ret;
} // }}}
static ssize_t   map_get_block      (blocks_user_data *data, unsigned int block_vid, off_t *real_off, size_t *block_size){ // {{{
	int      action;
	ssize_t  ret     = 1;
	ssize_t  buf_ptr = 0;
	
	action = ACTION_CRWD_READ;
	hash_set(data->fc_map.request_move, "action",    TYPE_INT32, &action);
	hash_set(data->fc_map.request_move, "blocks",    TYPE_INT32, &ret);
	hash_set(data->fc_map.request_move, "block_vid", TYPE_INT32, &block_vid);
	
	ret = backend_query(data->bk_map, data->fc_map.request_move, data->fc_map.buffer_create);
	if(ret > 0){
		*real_off   = 0;
		*block_size = 0;
		
		buf_ptr += buffer_read(data->fc_map.buffer_create, buf_ptr, block_size, MIN(ret, sizeof(unsigned int)));
		buf_ptr += buffer_read(data->fc_map.buffer_create, buf_ptr, real_off,   MIN(ret, sizeof(unsigned int)));
	}
	return ret;
} // }}}
static ssize_t   map_blocks         (blocks_user_data *data){ // {{{
	ssize_t  ret = 1;
	
	data->blocks_count = 0;
	
	hash_set(data->fc_map.request_count, "blocks", TYPE_INT32, &ret);
	
	ret = backend_query(data->bk_map, data->fc_map.request_count, data->fc_map.buffer_count);
	if(ret > 0){
		buffer_read(data->fc_map.buffer_count, 0, &data->blocks_count, MIN(ret, sizeof(data->blocks_count)));
	}
	return ret;
} // }}}
static ssize_t   map_translate_key  (blocks_user_data *data, char *key_name, request_t *request, request_t *layer){ // {{{
	off_t        key_virt, key_real;
	unsigned int block_vid;
	
	// TODO remove TYPE_INT64 from code, support all
	if(hash_get_copy (request, key_name, TYPE_INT64, &key_virt, sizeof(key_virt)) != 0)
		return -EINVAL;
	
	if(map_off(data, key_virt, &block_vid, &key_real) <= 0)
		return -EINVAL;
	
	hash_set(layer, key_name, TYPE_INT64, &key_real);
	
	return 0;
} // }}}
static ssize_t   real_new           (blocks_user_data *data, off_t *real_block_off){ // {{{
	return fc_crwd_next_chain(
		&data->fc_real,
		data->ch_real,
		ACTION_CRWD_CREATE,
		(unsigned int) ( data->block_size ),
		(off_t *)      ( real_block_off   ),
		(size_t)       ( sizeof(off_t)    )
	);
} // }}}
static ssize_t   real_move          (blocks_user_data *data, off_t from, off_t to, size_t size){ // {{{
	if(from == to || size == 0)
		return 0;

	return fc_crwd_next_chain(
		&data->fc_real,
		data->ch_real,
		ACTION_CRWD_MOVE,
		(off_t)        ( from ),
		(off_t)        ( to   ),
		(unsigned int) ( size )
	);
} // }}}
static ssize_t   itms_insert_copy   (chain_t *chain, off_t src, off_t dst, size_t size){ // {{{
	off_t         src_real,      dst_real;
	unsigned int  src_block_vid, dst_block_vid;
	unsigned int  dst_block_off;
	unsigned int  new_block_vid;
	off_t         src_block_roff;
	off_t         new_block_roff;
	
	//off_t         block_roff;
	size_t        block_size;
	
	// TODO copy only data from src blocks instead of whole block
	// TODO eh.. how it works?
	// NOTE this is HELL!
	
	blocks_user_data *data = (blocks_user_data *)chain->user_data;
	
	if(map_off(data, src, &src_block_vid, &src_real) <= 0)
		return -EINVAL;
	if(map_off(data, dst, &dst_block_vid, &dst_real) <= 0)
		return -EINVAL;
	
	dst_block_off = dst_real % data->block_size;
	
	/*
	if(src_block_vid == dst_block_vid){
		if(map_get_block(data, src_block_vid, &block_roff, &block_size) <= 0)
			return -EFAULT;
		
		if(block_size + size <= data->block_size){
			if(real_move(data, src_real, dst_real + size, (block_size - dst_block_off)) != 0)
				return -EFAULT;
			if(map_resize(data, src_block_vid, block_size + size) != 0)
				return -EFAULT;
			return 0;
		}
	}*/
	
	if(dst_block_off != 0){ // inserting data in middle, we truncate block and insert data after it
		block_size = data->block_size - dst_block_off;
		
		if(real_new(data, &new_block_roff) <= 0)
			return -EFAULT;
		
		if(real_move(data, dst_real, new_block_roff, block_size) != 0)
			return -EFAULT;
		
		if(map_insert(data, dst_block_vid + 1, (unsigned int)new_block_roff, block_size) != 0)
			return -EFAULT;
		
		if(map_resize(data, dst_block_vid, dst_block_off) != 0)
			return -EFAULT;
	}
	
	if(map_off(data, src, &src_block_vid, &src_real) <= 0)
		return -EINVAL;
	
	new_block_vid = src_block_vid;
	
	goto start;
	while(size > 0){
		if(map_off(data, src, &src_block_vid, &src_real) <= 0)
			return -EINVAL;
		
	start:
		if(map_get_block(data, src_block_vid, &src_block_roff, &block_size) <= 0)
			return -EFAULT;
		
		block_size = MIN(size, block_size);
		
		if(real_new(data, &new_block_roff) <= 0)
			return -EFAULT;
		
		if(real_move(data, src_real, new_block_roff, block_size) != 0)
			return -EFAULT;
		
		if(map_insert(data, new_block_vid, (unsigned int)new_block_roff, block_size) != 0)
			return -EFAULT;
		
		src        += block_size * 2; // TODO oh my...
		size       -= block_size;
		new_block_vid++;
	}
	
	return 0;
} // }}}
static ssize_t   itms_delete        (chain_t *chain, off_t start, size_t size){ // {{{
	off_t         start_real,      end_real;
	unsigned int  start_block_off, end_block_off;
	unsigned int  start_block_vid, end_block_vid, i_vid;
	unsigned int  end_block_aoff;                          // absolute offset
	off_t         block_roff;
	size_t        block_size;
	
	blocks_user_data *data = (blocks_user_data *)chain->user_data;
	
	if(map_off(data, start,        &start_block_vid, &start_real) <= 0)
		return -EFAULT;
	if(map_off(data, start + size, &end_block_vid,   &end_real)   <= 0){
		end_block_vid = (data->blocks_count - 1);
		end_block_off = data->block_size;
	}else{
		end_block_off   = end_real   % data->block_size;
		end_block_aoff  = (end_real - end_block_off);
	}
	start_block_off = start_real % data->block_size;
	
	for(i_vid = start_block_vid; i_vid <= end_block_vid; i_vid++){
		if(i_vid == end_block_vid){
			if(map_get_block(data, end_block_vid, &block_roff, &block_size) <= 0)
				return -EFAULT;
			
			if(real_move(data, end_real, block_roff, block_size - end_block_off) != 0) // TODO WRRRRRROOOOOOOOOOOONGG
				return -EFAULT;
				
			if(map_resize(data, end_block_vid, block_size - end_block_off) != 0)
				return -EFAULT;
			
			break;
		}
		if(i_vid == start_block_vid){ // first block
			if(map_resize(data, start_block_vid, start_block_off) != 0)
				return -EFAULT;
			
			continue;
		}
		
		if(map_resize(data, i_vid, 0) != 0)
			return -EFAULT;
	}
	return 0;
} // }}}

/* init {{{ */
static int blocks_init(chain_t *chain){
	blocks_user_data *user_data = calloc(1, sizeof(blocks_user_data));
	if(user_data == NULL)
		return -ENOMEM;
	
	chain->user_data = user_data;
	
	return 0;
}

static int blocks_destroy(chain_t *chain){
	blocks_user_data *data = (blocks_user_data *)chain->user_data;
	
	fc_crwd_destory(&data->fc_map);
	fc_crwd_destory(&data->fc_real);

	if(data->layer_get   != NULL) hash_free(data->layer_get);
	if(data->layer_count != NULL) hash_free(data->layer_count);
	
	backend_destory(data->bk_map);
	free(chain->user_data);
	
	chain->user_data = NULL;
	return 0;
}

static int blocks_configure(chain_t *chain, setting_t *config){
	setting_t        *config_backend;
	char             *block_size_str;
	unsigned int      action;
	blocks_user_data *data         = (blocks_user_data *)chain->user_data;
	
	if( (block_size_str = setting_get_child_string(config, "block_size")) == NULL)
		return_error(-EINVAL, "chain 'blocks' variable 'block_size' not set\n");
	
	if( (data->block_size = strtoul(block_size_str, NULL, 10)) == 0)
		return_error(-EINVAL, "chain 'blocks' variable 'block_size' invalid\n");
	
	if( (config_backend = setting_get_child_setting(config, "backend")) == NULL)
		return_error(-EINVAL, "chain 'blocks' variable 'backend' not set\n");
	
	if( (data->bk_map = backend_new("blocks_map", config_backend)) == NULL)
		return_error(-EINVAL, "chain 'blocks' variable 'backend' invalid\n");
	
	data->ch_real = chain;
	
	if( fc_crwd_init(&data->fc_map) != 0){
		error("chain 'blocks' fastcall table map init failed\n");  goto free;
	}
	if( fc_crwd_init(&data->fc_real) != 0){
		error("chain 'blocks' fastcall table real init failed\n"); goto free1;
	}
	
	if( (data->layer_get   = hash_new()) == NULL)
		goto free2;
	
	if( (data->layer_count = hash_new()) == NULL)
		goto free3;
	
	action = ACTION_CRWD_COUNT;
	hash_set(data->layer_count, "action", TYPE_INT32, &action);
	
	map_blocks(data);
	
	return 0;

free3:  hash_free(data->layer_get);
free2:  fc_crwd_destory(&data->fc_real);
free1:  fc_crwd_destory(&data->fc_map);
free:	backend_destory(data->bk_map);
	return -ENOMEM;
}
/* }}} */

static ssize_t blocks_create(chain_t *chain, request_t *request, buffer_t *buffer){ // {{{
	unsigned int      element_size;
	
	blocks_user_data *data = (blocks_user_data *)chain->user_data;
	off_t             block_off;
	size_t            block_size;
	off_t             block_vid;
	ssize_t           ret;
	
	if(hash_get_copy (request, "size", TYPE_INT32, &element_size, sizeof(element_size)) != 0)
		return -EINVAL;
	
	if(element_size > data->block_size) // TODO make sticked blocks
		return -EINVAL;
	
	/* if file empty - create new block */
	if(data->blocks_count == 0){
		if(real_new(data, &block_off) <= 0)
			return -EFAULT;
		
		if(map_new(data, block_off, 0) != 0)
			return -EFAULT;
		
		if(map_blocks(data) <= 0)
			return -EFAULT;
	}
	
	/* try write into last block */
	block_vid = data->blocks_count - 1;
	if(map_get_block(data, block_vid, &block_off, &block_size) <= 0)
		return -EFAULT;
	
	/* if not enough space - create new one */
	if(element_size + block_size > data->block_size){
		if(real_new(data, &block_off) <= 0) // TODO get block_vid too
			return -EFAULT;
		
		if(map_new(data, block_off, 0) != 0)
			return -EFAULT;
		
		if(map_blocks(data) <= 0)
			return -EFAULT;
		
		block_vid  = data->blocks_count - 1;
		block_size = 0;
	}
	
	/* calc virt_ptr */
	hash_assign_layer  (data->layer_count, request);               // transfer query to map backend _COUNT
	ret = backend_query(data->bk_map, data->layer_count, buffer); 
	
	/* really add item */
	if(map_resize(data, block_vid, block_size + element_size) != 0)
		return -EFAULT;
	
	return ret;
} // }}}
static ssize_t blocks_setget(chain_t *chain, request_t *request, buffer_t *buffer){ // {{{
	blocks_user_data *data = (blocks_user_data *)chain->user_data;
	
	// TODO r_size > block_size
	
	hash_empty        (data->layer_get);
	hash_assign_layer (data->layer_get, request);
	
	if(map_translate_key(data, "key", request, data->layer_get) != 0)
		return -EINVAL;
	
	return chain_next_query(chain, data->layer_get, buffer);
} // }}}
static ssize_t blocks_delete(chain_t *chain, request_t *request, buffer_t *buffer){ // {{{
	off_t             r_key;
	unsigned int      r_size;
	
	if(hash_get_copy (request, "key",  TYPE_INT64, &r_key,  sizeof(r_key)) != 0)
		return -EINVAL;
	if(hash_get_copy (request, "size", TYPE_INT32, &r_size, sizeof(r_size)) != 0)
		return -EINVAL;
	
	return itms_delete(chain, r_key, r_size);
} // }}}
static ssize_t blocks_move(chain_t *chain, request_t *request, buffer_t *buffer){ // {{{
	off_t             r_from, r_to;
	unsigned int      r_size;
	
	ssize_t           move_delta;
	
	if(hash_get_copy (request, "key_from", TYPE_INT64, &r_from, sizeof(r_from)) != 0)
		return -EINVAL;
	if(hash_get_copy (request, "key_to",   TYPE_INT64, &r_to,   sizeof(r_to))   != 0)
		return -EINVAL;
	
	if(r_from == r_to)
		return 0;
	
	// manage top of move
	move_delta = (r_to - r_from);
	if(move_delta > 0){ // moving data forward
		if(itms_insert_copy(chain, r_from, r_from, move_delta) != 0)
			return -EINVAL;
	}else{ // moving data backward
		if(itms_delete(chain, r_to, -move_delta) != 0)
			return -EINVAL;
	}
	
	// manage bottom of move
	if(
		hash_get_copy (request, "size", TYPE_INT32, &r_size, sizeof(r_size)) == 0 &&
		r_size != -1
	){
		r_from += r_size;
		r_to   += r_size;
		
		if(move_delta > 0){ // moving data forward
			if(itms_delete(chain, r_from, move_delta) != 0)
				return -EINVAL;
		}else{ // moving data backward
			if(itms_insert_copy(chain, r_to, r_from, -move_delta) != 0)
				return -EINVAL;
		}
	}
	return 0;
} // }}}
static ssize_t blocks_count(chain_t *chain, request_t *request, buffer_t *buffer){ // {{{
	blocks_user_data *data = (blocks_user_data *)chain->user_data;
	
	return backend_query(data->bk_map, request, buffer);  // transfer query to map backend _COUNT
} // }}}

static chain_t chain_blocks = {
	"blocks",
	CHAIN_TYPE_CRWD,
	&blocks_init,
	&blocks_configure,
	&blocks_destroy,
	{{
		.func_create = &blocks_create,
		.func_set    = &blocks_setget,
		.func_get    = &blocks_setget,
		.func_delete = &blocks_delete,
		.func_move   = &blocks_move,
		.func_count  = &blocks_count
	}}
};
CHAIN_REGISTER(chain_blocks)

