#define FORMAT_C
#include <libfrozen.h>
#include <enum/format/format_t.h>

#define ERRORS_MODULE_ID 47
#define ERRORS_MODULE_NAME "enum/format"

#if defined DYNAMIC_KEYS_CHECK || defined RESOLVE_DYNAMIC_KEYS
static list                    dynamic_formats   = LIST_INITIALIZER;
#endif

static ssize_t data_format_t_convert_from(data_t *dst, fastcall_convert_from *fargs){ // {{{
	char                   buffer[DEF_BUFFER_SIZE];
	keypair_t             *kp;
	format_t               key_val;
	uintmax_t              transfered        = 0;
	
	if(fargs->src == NULL)
		return -EINVAL;
	
	if(dst->ptr == NULL){ // no buffer, alloc new
		if( (dst->ptr = malloc(sizeof(format_t))) == NULL)
			return -ENOMEM;
	}
	
	switch(fargs->format){
		case FORMAT(packed):;
		case FORMAT(config):;
		case FORMAT(human):;
			fastcall_read r_read = { { 5, ACTION_READ }, 0, &buffer, sizeof(buffer) - 1 };
			if(data_query(fargs->src, &r_read) != 0)
				return -EFAULT;
			
			buffer[r_read.buffer_size] = '\0';
			
			key_val    = portable_hash(buffer);
			transfered = strlen(buffer);
	
	#ifdef COLLISION_CHECK
		#ifdef STATIC_KEYS_CHECK
			// find collisions
			for(kp = &formats[0]; kp->key_str != NULL; kp++){
				if(kp->key_val == key_val && strcmp(kp->key_str, buffer) != 0)
					goto collision;
			}
		#endif
		#ifdef DYNAMIC_KEYS_CHECK
			void                  *iter              = NULL;
			
			list_rdlock(&dynamic_formats);
			while( (kp = list_iter_next(&dynamic_formats, &iter)) != NULL){
				if(kp->key_val == key_val && strcmp(kp->key_str, buffer) != 0){
					list_unlock(&dynamic_formats);
					goto collision;
				}
			}
			list_unlock(&dynamic_formats);
		#endif
	#endif
		#if defined DYNAMIC_KEYS_CHECK || defined RESOLVE_DYNAMIC_KEYS
			keypair_t             *newkey            = malloc(sizeof(keypair_t));
			
			newkey->key_str = strdup(buffer);
			newkey->key_val = key_val;
			list_add(&dynamic_formats, newkey);
		#endif
	
			*(format_t *)(dst->ptr) = key_val;
			break;
		
		default:
			return -ENOSYS;
	}
	if(fargs->header.nargs >= 5)
		fargs->transfered = transfered;
	
	return 0;
	goto collision; // dummy

collision:
	// report collision
	fprintf(stderr, "format collision: %s <=> %s\n", kp->key_str, buffer);
	return error("format collision");
} // }}}
static ssize_t data_format_t_convert_to(data_t *src, fastcall_convert_to *fargs){ // {{{
	ssize_t                ret;
	format_t               value;
	uintmax_t              transfered;
	keypair_t             *kp;
	void                  *iter              = NULL;
	char                  *string            = "(unknown)";
	
	if(fargs->dest == NULL || src->ptr == NULL)
		return -EINVAL;
	
	value = *(format_t *)src->ptr;
	
	switch(fargs->format){
		case FORMAT(packed):;
		case FORMAT(config):;
		case FORMAT(native):;
		case FORMAT(human):;
			// find in static keys first
			for(kp = &formats[0]; kp->key_str != NULL; kp++){
				if(kp->key_val == value){
					string = kp->key_str;
					goto found;
				}
			}
			
		#ifdef RESOLVE_DYNAMIC_KEYS
			// find in dynamic keys
			list_rdlock(&dynamic_formats);
			while( (kp = list_iter_next(&dynamic_formats, &iter)) != NULL){
				if(kp->key_val == value){
					string = kp->key_str;
					list_unlock(&dynamic_formats);
					goto found;
				}
			}
			list_unlock(&dynamic_formats);
		#endif
		
		found:;
			fastcall_write r_write = { { 5, ACTION_WRITE }, 0, string, strlen(string) };
			ret        = data_query(fargs->dest, &r_write);
			transfered = r_write.buffer_size;
			break;
		
		default:
			return -ENOSYS;
	}
	if(fargs->header.nargs >= 5)
		fargs->transfered = transfered;
	
	return ret;
} // }}}		
static ssize_t data_format_t_len(data_t *data, fastcall_length *fargs){ // {{{
	if(fargs->format == FORMAT(packed)){
		fargs->length = sizeof(format_t);
		return 0;
	}
	return -ENOSYS;
} // }}}

data_proto_t format_t_proto = {
	.type_str               = "format_t",
	.api_type               = API_HANDLERS,
	.properties             = DATA_ENDPOINT,
	.handlers               = {
		[ACTION_CONVERT_TO]   = (f_data_func)&data_format_t_convert_to,
		[ACTION_CONVERT_FROM] = (f_data_func)&data_format_t_convert_from,
		[ACTION_LENGTH]       = (f_data_func)&data_format_t_len,
	}
};
