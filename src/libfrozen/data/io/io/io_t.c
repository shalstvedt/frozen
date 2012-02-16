#include <libfrozen.h>
#include <io_t.h>

static ssize_t data_io_t_handler (data_t *data, fastcall_header *hargs){ // {{{
	io_t                  *fdata             = (io_t *)data->ptr;
	
	switch(hargs->action){
		case ACTION_COPY:;
			fastcall_copy *fargs = (fastcall_copy *)hargs;
			
			if(fargs->dest == NULL)
				return -EINVAL;
			
			if( (fargs->dest->ptr = memdup(fdata, sizeof(io_t))) == NULL)
				return -ENOMEM;
			
			fargs->dest->type = data->type;
			break;
		case ACTION_FREE:
			if(data->ptr)
				free(data->ptr);
			return 0;
		default:
			return fdata->handler(data, fdata->ud, hargs);
	};
	return -ENOSYS;
} // }}}

data_proto_t io_t_proto = {
	.type                   = TYPE_IOT,
	.type_str               = "io_t",
	.api_type               = API_DEFAULT_HANDLER,
	.handler_default        = (f_data_func)&data_io_t_handler
};
