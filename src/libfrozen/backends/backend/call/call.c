#include <libfrozen.h>

#define EMODULE 25

typedef struct call_userdata {
	hash_key_t             hk_backend;
} call_userdata;

static int call_init(backend_t *backend){ // {{{
	if((backend->userdata = calloc(1, sizeof(call_userdata))) == NULL)
		return error("calloc failed");
	
	return 0;
} // }}}
static int call_destroy(backend_t *backend){ // {{{
	call_userdata      *userdata = (call_userdata *)backend->userdata;
	
	free(userdata);
	return 0;
} // }}}
static int call_configure(backend_t *backend, config_t *config){ // {{{
	ssize_t                ret;
	char                  *hk_backend_str    = "backend";
	call_userdata         *userdata          = (call_userdata *)backend->userdata;
	
	hash_data_copy(ret, TYPE_STRINGT, hk_backend_str, config, HK(input));
	userdata->hk_backend = hash_string_to_key(hk_backend_str);
	return 0;
} // }}}

static ssize_t call_handler(backend_t *backend, request_t *request){ // {{{
	ssize_t                ret;
	backend_t             *call_to           = NULL;
	call_userdata         *userdata          = (call_userdata *)backend->userdata;
	
	hash_data_copy(ret, TYPE_BACKENDT, call_to, request, userdata->hk_backend);
	if(ret == 0 && call_to != NULL)
		return ( (ret = backend_pass(call_to, request)) < 0 ) ? ret : -EEXIST;
	
	return error("backend to call not supplied in request");
} // }}}

backend_t call_proto = {
	.class          = "backend/call",
	.supported_api  = API_HASH,
	.func_init      = &call_init,
	.func_destroy   = &call_destroy,
	.func_configure = &call_configure,
	.backend_type_hash = {
		.func_handler = &call_handler
	}
};

