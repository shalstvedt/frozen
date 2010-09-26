#include <libfrozen.h>
#include <backend.h>

// TODO remake init()

list   chains;
list   backends;

/* chains - private {{{1 */
static void __attribute__ ((constructor)) __chain_init(){
	list_init(&chains);
	list_init(&backends);
}

static int chain_find_by_name(void *p_chain, void *p_name, void *p_chain_t){
	if(strcmp(((chain_t *)p_chain)->name, p_name) == 0){
		*(chain_t **)p_chain_t = (chain_t *)p_chain;
		return ITER_BREAK;
	}
	return ITER_CONTINUE;
}
/* }}}1 */
/* chains - public {{{1 */
chain_t * chain_new(char *name){
	int      ret;
	chain_t *chain;
	chain_t *chain_proto = NULL;
	
	list_iter(&chains, (iter_callback)&chain_find_by_name, name, &chain_proto);
	if(chain_proto == NULL)
		return NULL;
	
	chain = (chain_t *)malloc(sizeof(chain_t));
	if(chain == NULL)
		return NULL;
	
	memcpy(chain, chain_proto, sizeof(chain_t));
	
	chain->next = NULL;
	
	ret = chain->func_init(chain);
	if(ret != 0){
		free(chain);
		return NULL;
	}
	
	return chain;
}

inline int chain_configure(chain_t *chain, setting_t *setting){
	return chain->func_configure(chain, setting);
}

inline int chain_crwd_create (chain_t *chain, void *key, size_t value_size){
	return chain->chain_type_crwd.func_create(chain, key, value_size);
}
inline int chain_crwd_set    (chain_t *chain, void *key, void *value, size_t value_size){
	return chain->chain_type_crwd.func_set(chain, key, value, value_size);
}
inline int chain_crwd_get    (chain_t *chain, void *key, void *value, size_t value_size){
	return chain->chain_type_crwd.func_get(chain, key, value, value_size);
}
inline int chain_crwd_delete (chain_t *chain, void *key, size_t value_size){
	return chain->chain_type_crwd.func_delete(chain, key, value_size);
}

void chain_destroy(chain_t *chain){
	if(chain == NULL)
		return;

	chain->func_destroy(chain);
	
	free(chain);
}
/* }}}1 */

/* backends - private {{{1 */
static int backend_iter_chain_init(void *p_setting, void *p_backend, void *p_chain){
	int        ret;
	chain_t   *chain;
	char      *chain_name;
	setting_t *setting = (setting_t *)p_setting;
	
	chain_name = setting_get_child_string(setting, "name");
	if(chain_name == NULL)
		return ITER_BREAK;
	
	chain = chain_new(chain_name);
	if(chain == NULL)
		return ITER_BREAK;
	
	ret = chain_configure(chain, setting);
	if(ret != 0)
		goto cleanup;
	
	chain->next = *(chain_t **)p_chain;
	
	*(chain_t **)p_chain = chain;

	return ITER_CONTINUE;

cleanup:	
	chain_destroy(chain);
	return ITER_BREAK;
}
static int backend_iter_find(void *p_backend, void *p_name, void *p_backend_t){
	backend_t *backend = (backend_t *)p_backend;
	if(strcmp(backend->name, p_name) == 0){
		*(backend_t **)p_backend_t = backend;
		return ITER_BREAK;
	}
	return ITER_CONTINUE;
}
/* }}}1 */
/* backends - public {{{1 */
backend_t *  backend_new      (char *name, setting_t *setting){
	int ret;
	
	if(name == NULL || setting == NULL)
		return NULL;	
	
	backend_t *backend = (backend_t *)malloc(sizeof(backend_t));
	if(backend == NULL)
		return NULL;
	
	backend->name  = strdup(name);
	backend->chain = NULL;
	
	ret = setting_iter_child(setting, (iter_callback)&backend_iter_chain_init, backend, &backend->chain);
	if(ret == ITER_BROKEN){
		backend_destory(backend);
		return NULL;
	}
	
	list_push(&backends, backend);
	
	return backend;
}

backend_t *  backend_find_by_name(char *name){
	backend_t *backend = NULL;
	
	list_iter(&backends, (iter_callback)&backend_iter_find, name, &backend);
	
	return backend;
}

void         backend_destory  (backend_t *backend){
	if(backend == NULL)
		return;
	
	list_unlink(&backends, backend); 
	
	chain_t *chain_curr = backend->chain;
	chain_t *chain_next;
	
	while(chain_curr != NULL){
		chain_next = chain_curr->next;
		chain_destroy(chain_curr);
		chain_curr = chain_next;
	}
	
	free(backend->name);
	free(backend);
}
/* }}}1 */
