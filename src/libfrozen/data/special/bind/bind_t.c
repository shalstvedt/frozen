#include <libfrozen.h>

#include <enum/format/format_t.h>
#include <core/hash/hash_t.h>
#include <numeric/uint/uint_t.h>

#include <bind_t.h>

ssize_t           bind_t_sync(bind_t *fdata){ // {{{
	fastcall_convert_to r_convert = { { 5, ACTION_CONVERT_TO }, &fdata->slave, fdata->format };
	return data_query(&fdata->data, &r_convert);
} // }}}
bind_t *          bind_t_alloc(data_t *data, data_t *slave, format_t format, uintmax_t fatal, uintmax_t sync){ // {{{
	bind_t                 *fdata;
	
	if( (fdata = malloc(sizeof(bind_t))) == NULL )
		return NULL;
	
	fdata->data    = *data;
	fdata->slave     = *slave;
	fdata->format    = format;
	fdata->sync      = sync;
	fdata->sync_curr = sync;
	
	fastcall_convert_from r_convert = { { 5, ACTION_CONVERT_FROM }, &fdata->slave, format };
	if(data_query(&fdata->data, &r_convert) < 0 && fatal != 0){
		free(fdata);
		return NULL;
	}
	return fdata;
} // }}}
void              bind_t_destroy(data_t *data){ // {{{
	bind_t                *fdata             = (bind_t *)data->ptr;

	if(fdata){
		bind_t_sync(fdata);
		data_free(&fdata->data);
		data_free(&fdata->slave);
	}
	data_set_void(data);
} // }}}

static ssize_t data_bind_t_handler(data_t *data, fastcall_header *hargs){ // {{{
	bind_t                *fdata             = (bind_t *)data->ptr;
	
	if(fdata->sync){
		if(--fdata->sync_curr == 0){
			fdata->sync_curr = fdata->sync;
			
			bind_t_sync(fdata);
		}
	}
	return data_query(&fdata->data, hargs);
} // }}}
static ssize_t data_bind_t_convert_from(data_t *dst, fastcall_convert_from *fargs){ // {{{
	ssize_t                ret;
	
	if(dst->ptr != NULL)
		return data_bind_t_handler(dst, (fastcall_header *)fargs); // pass to data data
	
	switch(fargs->format){
		case FORMAT(hash):;
			hash_t                *config;
			data_t                 data;
			data_t                 slave;
			format_t               format              = FORMAT(packed);
			uintmax_t              fatal               = 0;
			uintmax_t              sync                = 0;

			data_get(ret, TYPE_HASHT, config, fargs->src);
			if(ret != 0)
				return -EINVAL;
			
			hash_data_get(ret, TYPE_FORMATT, format, config, HK(format));
			hash_data_get(ret, TYPE_UINTT,   fatal,  config, HK(fatal));
			hash_data_get(ret, TYPE_UINTT,   sync,   config, HK(sync));
			
			hash_holder_consume(ret, data, config, HK(data));
			if(ret != 0){
				return -EINVAL;
			}
			
			hash_holder_consume(ret, slave,  config, HK(slave));
			if(ret != 0){
				data_free(&data)
				return -EINVAL;
			}
			
			if( (dst->ptr = bind_t_alloc(&data, &slave, format, fatal, sync)) == NULL ){
				data_free(&data);
				data_free(&slave);
				return -EFAULT;
			}
			return 0;
			
		default:
			break;
	}
	return -ENOSYS;
} // }}}
static ssize_t data_bind_t_free(data_t *data, fastcall_free *hargs){ // {{{
	bind_t_destroy(data);
	return 0;
} // }}}
static ssize_t data_bind_t_control(data_t *data, fastcall_control *fargs){ // {{{
	bind_t               *fdata             = (bind_t *)data->ptr;
	
	switch(fargs->function){
		case HK(data):;
			helper_control_data_t r_internal[] = {
				{ HK(data),  &fdata->data      },
				{ HK(slave), &fdata->slave       },
				{ 0, NULL }
			};
			return helper_control_data(data, fargs, r_internal);
			
		default:
			break;
	}
	return data_default_control(data, fargs);
} // }}}

data_proto_t bind_t_proto = {
	.type_str               = "bind_t",
	.api_type               = API_HANDLERS,
	.properties             = DATA_PROXY,
	.handler_default        = (f_data_func)&data_bind_t_handler,
	.handlers               = {
		[ACTION_CONVERT_FROM] = (f_data_func)&data_bind_t_convert_from,
		[ACTION_FREE]         = (f_data_func)&data_bind_t_free,
		[ACTION_CONTROL]      = (f_data_func)&data_bind_t_control,
	}
};
