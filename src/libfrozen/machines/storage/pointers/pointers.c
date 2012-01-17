#include <libfrozen.h>

/**
 * @ingroup machine
 * @addtogroup mod_pointers storage/pointers
 *
 * Pointers module data pointers to data instead of actual data
 */
/**
 * @ingroup mod_pointers
 * @page page_pointers_config Configuration
 * 
 * Accepted configuration:
 * @code
 * 	{
 * 	        class    = "storage/pointers",
 *              input    = "buffer",             # input data HK
 *              offset   = "offset",             # offset HK
 * 	}
 * @endcode
 */

#define EMODULE         32

typedef struct pointers_userdata {
	hashkey_t             input;
	hashkey_t             offset;
} pointers_userdata;

static int pointers_init(machine_t *machine){ // {{{
	pointers_userdata *userdata = calloc(1, sizeof(pointers_userdata));
	if(userdata == NULL)
		return error("calloc returns null");
	
	machine->userdata = userdata;
	
	userdata->input = HK(buffer);
	userdata->offset = HK(offset);
	return 0;
} // }}}
static int pointers_destroy(machine_t *machine){ // {{{
	pointers_userdata *userdata = (pointers_userdata *)machine->userdata;
	
	free(userdata);
	return 0;
} // }}}
static int pointers_configure(machine_t *machine, config_t *config){ // {{{
	ssize_t                ret;
	pointers_userdata     *userdata          = (pointers_userdata *)machine->userdata;
	
	hash_data_copy(ret, TYPE_HASHKEYT, userdata->input,  config, HK(input));
	hash_data_copy(ret, TYPE_HASHKEYT, userdata->offset, config, HK(offset));
	return 0;
} // }}}

static ssize_t pointers_handler(machine_t *machine, request_t *request){ // {{{
	ssize_t                ret;
	uint32_t               action;
	uintmax_t              offset;
	data_t                *input;
	data_t                 d_void            = DATA_VOID;
	pointers_userdata     *userdata          = (pointers_userdata *)machine->userdata;

	hash_data_copy(ret, TYPE_UINT32T, action, request, HK(action));
	if(ret != 0) return -ENOSYS;
	
	hash_data_copy(ret, TYPE_UINTT,   offset, request, userdata->offset);
	if(ret != 0) return -EINVAL; // TODO remove for ACTION_CREATE
	
	offset *= sizeof(data_t);
	
	input = hash_data_find(request, userdata->input);
	
	switch(action){
		// TODO ACTION_CREATE
		case ACTION_DELETE:
			input = &d_void;
		
		case ACTION_READ:;
		case ACTION_WRITE:;
			request_t r_next[] = {
				{ userdata->offset, DATA_PTR_UINTT(&offset)         },
				{ userdata->input,  DATA_RAW(input, sizeof(data_t)) },
				{ HK(size),         DATA_SIZET(sizeof(data_t))      }, // TODO remove size
				hash_next(request)
			};
			return machine_pass(machine, r_next);
	};
	return 0;
} // }}}

machine_t pointers_proto = {
	.class          = "storage/pointers",
	.supported_api  = API_HASH,
	.func_init      = &pointers_init,
	.func_configure = &pointers_configure,
	.func_destroy   = &pointers_destroy,
	.machine_type_hash = {
		.func_handler = &pointers_handler,
	}
};

