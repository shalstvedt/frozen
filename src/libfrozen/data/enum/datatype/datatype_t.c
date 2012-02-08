#include <libfrozen.h>
#include <datatype_t.h>
#include <enum/format/format_t.h>
#include <core/void/void_t.h>

datatype_t     data_getid(char *name, ssize_t *pret){ // {{{
	uintmax_t              i;
	ssize_t                ret               = -EINVAL;
	datatype_t             type              = TYPE_VOIDT;
	data_proto_t          *proto;
	
	for(i=0; i<data_protos_nitems; i++){
		if( (proto = data_protos[i]) == NULL)
			continue;
		
		if(strcasecmp(proto->type_str, name) == 0){
			type = i;
			ret  = 0;
			break;
		}
	}
	if(pret)
		*pret = ret;
	return type;
} // }}}

static ssize_t data_datatype_t_convert_from(data_t *dst, fastcall_convert_from *fargs){ // {{{
	ssize_t                ret;
	char                   buffer[DEF_BUFFER_SIZE];
	
	if(fargs->src == NULL)
		return -EINVAL;
	
	if(dst->ptr == NULL){ // no buffer, alloc new
		if( (dst->ptr = malloc(sizeof(datatype_t))) == NULL)
			return -ENOMEM;
	}
	
	switch(fargs->format){
		case FORMAT(config):;
		case FORMAT(human):;
			fastcall_read r_read = { { 5, ACTION_READ }, 0, buffer, sizeof(buffer) - 1 };
			if(data_query(fargs->src, &r_read) < 0)
				return -EINVAL;
			
			buffer[r_read.buffer_size] = '\0';
			
			*(datatype_t *)(dst->ptr) = data_getid(buffer, &ret);
			return ret;

		default:
			break;
	};
	return -ENOSYS;
} // }}}
static ssize_t data_datatype_t_convert_to(data_t *src, fastcall_convert_to *fargs){ // {{{
	ssize_t                ret;
	datatype_t             type;
	char                  *string            = "INVALID";
	
	if(src->ptr == NULL)
		return -EINVAL;
	
	type = *(datatype_t *)(src->ptr);
	
	if(type != TYPE_INVALID && (unsigned)type < data_protos_nitems){
		string = data_protos[type]->type_str;
	}
	
	fastcall_write r_write = { { 5, ACTION_WRITE }, 0, string, strlen(string) };
	ret        = data_query(fargs->dest, &r_write);
	
	if(fargs->header.nargs >= 5)
		fargs->transfered = r_write.buffer_size;
	
	return ret;
} // }}}		
static ssize_t data_datatype_t_len(data_t *data, fastcall_length *fargs){ // {{{
	if(fargs->format == FORMAT(binary)){
		fargs->length = sizeof(datatype_t);
		return 0;
	}
	return -ENOSYS;
} // }}}

data_proto_t datatype_t_proto = {
	.type                   = TYPE_DATATYPET,
	.type_str               = "datatype_t",
	.api_type               = API_HANDLERS,
	.handlers               = {
		[ACTION_CONVERT_TO]   = (f_data_func)&data_datatype_t_convert_to,
		[ACTION_CONVERT_FROM] = (f_data_func)&data_datatype_t_convert_from,
		[ACTION_LENGTH]       = (f_data_func)&data_datatype_t_len,
	}
};
