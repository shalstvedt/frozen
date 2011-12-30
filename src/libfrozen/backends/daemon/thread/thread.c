#include <libfrozen.h>

/**
 * @ingroup backend
 * @addtogroup mod_backend_thread daemon/thread
 */
/**
 * @ingroup mod_backend_thread
 * @page page_thread_info Description
 *
 * This backend create new thread which emit empty request to underlying backend.
 */
/**
 * @ingroup mod_backend_thread
 * @page page_thread_config Configuration
 * 
 * Accepted configuration:
 * @code
 * {
 *         class            = "daemon/thread",
 *         paused           = (uint_t)'0',               # do not start thread after configure
 *         loop             = (uint_t)'1'                # run thread in infinity loop
 *         ignore_errors    = (uint_t)'1'                # ignore errors and do not exit from loop, default 0
 *         destroy          = (uint_t)'1'                # destroy backend chain on exit from loop, default 1
 * }
 * @threadcode
 */

#define EMODULE 41

typedef struct thread_userdata {
	//api_t                apitype; // TODO api types
	uintmax_t              paused;
	uintmax_t              loop;
	uintmax_t              ignore_errors;
	uintmax_t              destroy_on_exit;
	
	uintmax_t              self_termination;
	uintmax_t              thread_running;
	pthread_t              thread;
	pthread_mutex_t        thread_mutex;
} thread_userdata;

static void *  thread_routine(backend_t *backend){ // {{{
	ssize_t                ret;
	thread_userdata       *userdata          = (thread_userdata *)backend->userdata;
	
	
	do{
	//switch(apitype){
	//     case API_HASH:;
			request_t r_request[] = {
				{ HK(ret), DATA_PTR_SIZET(&ret) },
				hash_end
			};
			if( (backend_pass(backend, r_request) < 0 || ret < 0) && userdata->ignore_errors == 0)
				break;
	//		break;
	//     case API_FAST:;
	//}
	}while(userdata->loop);
	
	pthread_mutex_lock(&destroy_mtx); // TODO remove this..
	pthread_mutex_lock(&userdata->thread_mutex);
		userdata->thread_running = 0;
		
		if(userdata->destroy_on_exit){
			userdata->self_termination = 1;
			backend_destroy(backend);
			goto self_free;
		}
	pthread_mutex_unlock(&userdata->thread_mutex);
	pthread_mutex_unlock(&destroy_mtx); // TODO remove this..
	return NULL;

self_free:
	pthread_mutex_unlock(&userdata->thread_mutex);
	pthread_mutex_unlock(&destroy_mtx);
	pthread_mutex_destroy(&userdata->thread_mutex);
	free(userdata);
	return NULL;
} // }}}
static ssize_t thread_control_start(backend_t *backend){ // {{{
	ssize_t                ret               = 0;
	pthread_attr_t         attr;
	thread_userdata       *userdata          = (thread_userdata *)backend->userdata;
	
	pthread_mutex_lock(&userdata->thread_mutex);
		if(userdata->thread_running == 0){
			userdata->thread_running = 1;
			userdata->self_termination = 0;

			pthread_attr_init(&attr);
			pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
			
			if(pthread_create(&userdata->thread, &attr, (void * (*)(void *))&thread_routine, backend) != 0)
				ret = error("pthread_create failed");
			
			pthread_attr_destroy(&attr);
		}
	pthread_mutex_unlock(&userdata->thread_mutex);
	return ret;
} // }}}
static ssize_t thread_control_stop(backend_t *backend){ // {{{
	thread_userdata       *userdata          = (thread_userdata *)backend->userdata;
	
	pthread_mutex_lock(&userdata->thread_mutex);
		if(userdata->thread_running == 1){
			userdata->thread_running = 0;
			pthread_cancel(userdata->thread);
		}
	pthread_mutex_unlock(&userdata->thread_mutex);
	return 0;
} // }}}

static int thread_init(backend_t *backend){ // {{{
	pthread_mutexattr_t    attr;
	thread_userdata       *userdata;
	
	if((userdata = backend->userdata = calloc(1, sizeof(thread_userdata))) == NULL)
		return error("calloc failed");
	
	if(pthread_mutexattr_init(&attr) != 0)
		return -EFAULT;
		
	if(pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE) != 0)
		return -EFAULT;
	
	if(pthread_mutex_init(&userdata->thread_mutex, &attr) != 0)
		return -EFAULT;
	
	pthread_mutexattr_destroy(&attr);

	userdata->destroy_on_exit = 1;
	return 0;
} // }}}
static int thread_destroy(backend_t *backend){ // {{{
	thread_userdata       *userdata          = (thread_userdata *)backend->userdata;
	
	if(userdata->self_termination == 1)
		return 0;
	
	thread_control_stop(backend);
	
	pthread_mutex_destroy(&userdata->thread_mutex);
	free(userdata);
	return 0;
} // }}}
static int thread_configure(backend_t *backend, config_t *config){ // {{{
	ssize_t                ret;
	thread_userdata       *userdata          = (thread_userdata *)backend->userdata;
	
	hash_data_copy(ret, TYPE_UINTT, userdata->paused,            config, HK(paused));
	hash_data_copy(ret, TYPE_UINTT, userdata->loop,              config, HK(loop));
	hash_data_copy(ret, TYPE_UINTT, userdata->ignore_errors,     config, HK(ignore_errors));
	hash_data_copy(ret, TYPE_UINTT, userdata->destroy_on_exit,   config, HK(destroy));
	
	if(userdata->paused == 0)
		thread_control_start(backend);
	
	return 0;
} // }}}

static ssize_t thread_fast_handler(backend_t *backend, fastcall_header *hargs){ // {{{
	switch(hargs->action){
		case ACTION_START: return thread_control_start(backend);
		case ACTION_STOP:  return thread_control_stop(backend);
		default:
			break;
	}
	return -ENOSYS;
} // }}}
static ssize_t thread_handler(backend_t *backend, request_t *request){ // {{{
	ssize_t                ret;
	uintmax_t              action;
	
	hash_data_copy(ret, TYPE_UINTT, action, request, HK(action));
	
	fastcall_header r_fast = { 2, action };
	return thread_fast_handler(backend, &r_fast);
} // }}}

backend_t thread_proto = {
	.class          = "daemon/thread",
	.supported_api  = API_HASH | API_FAST,
	.func_init      = thread_init,
	.func_destroy   = thread_destroy,
	.func_configure = thread_configure,
	.backend_type_hash = {
		.func_handler = &thread_handler
	},
	.backend_type_fast = {
		.func_handler = (f_fast_func)&thread_fast_handler
	}
};

