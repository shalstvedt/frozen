#line 1 "uint_init.m4"








#line 1 "uint.h.m4"


#ifndef DATA_UINT_SIZET_H
#define DATA_UINT_SIZET_H

/** @ingroup data
 *  @addtogroup size_t size_t
 */
/** @ingroup size_t
 *  @page size_t_overview Overview
 *  
 *  This data used to hold integers of different size.
 */
/** @ingroup size_t
 *  @page size_t_define Define
 *
 *  Possible defines:
 *  @code
 *       data_t hint  = DATA_SIZET(100);
 *        
 *       size_t some  = 200;
 *       data_t hpint = DATA_PTR_SIZET(&some);
 *  @endcode
 */

#define DATA_SIZET(value) { TYPE_SIZET, (size_t []){ value } } 
#define DATA_PTR_SIZET(value) { TYPE_SIZET, value } 
#define DEREF_TYPE_SIZET(_data) *(size_t *)((_data)->ptr) 
#define REF_TYPE_SIZET(_dt) (&(_dt)) 
#define HAVEBUFF_TYPE_SIZET 1

#endif
/* vim: set filetype=m4: */
