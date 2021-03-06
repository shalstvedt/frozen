#ifndef DATA_EMITTER_T
#define DATA_EMITTER_T

/** @ingroup data
 *  @addtogroup emitter_t emitter_t
 */
/** @ingroup emitter_t
 *  @page emitter_t_overview Overview
 *  
 *  This data type emits request to supplied machine when receive any data action.
 *
 */
/** @ingroup emitter_t
 *  @page emitter_t_define Define
 *
 *  Possible defines:
 *  @code
 *       data_t emitter = DATA_EMITTERT(machine, request); // emit to machine with request
 *  @endcode
 */

#define DATA_EMITTERT(_machine,_request)  {TYPE_EMITTERT, (emitter_t []){ { _machine, _request, 0 } }}
#define DATA_PTR_EMITTERT(_ptr)  {TYPE_EMITTERT, _ptr }
#define DEREF_TYPE_EMITTERT(_data) (emitter_t *)((_data)->ptr)
#define REF_TYPE_EMITTERT(_dt) _dt
#define HAVEBUFF_TYPE_EMITTERT 0

typedef struct emitter_t {
	machine_t             *machine;
	request_t             *request;
	
	// internal
	uintmax_t              allocated;
} emitter_t;

#endif
