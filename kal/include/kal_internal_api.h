/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   kal_internal_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This header file is used to define internal api, do not export!
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __KAL_INTERNAL_API__
#define __KAL_INTERNAL_API__

#include "kal_release.h"

#ifdef __cplusplus
extern "C" {
#endif

#define KAL_INTERNAL_NILTASK_ID     (kal_internal_taskid)NULL
#define KAL_INTERNAL_NILTIMER_ID    (kal_internal_timerid)NULL
#define KAL_INTERNAL_NILPOOL_ID     (kal_internal_poolid)NULL
#define KAL_INTERNAL_NILMUTEX_ID    (kal_internal_mutexid)NULL
#define KAL_INTERNAL_NILSEM_ID      (kal_internal_semid)NULL
#define KAL_INTERNAL_NILQ_ID        (kal_internal_msgqid)NULL

typedef enum {
    KAL_MUTEX_GIVEN,
    KAL_MUTEX_TAKEN
} kal_mutex_state;

typedef enum 
{
#define X_KAL_ERROR_CODE
#include "kal_error_code.h"
    KAL_ERROR_CODE_END
#undef X_KAL_ERROR_CODE
} kal_error_type;

typedef enum 
{
#define X_KAL_ERROR_STRING
#include "kal_error_code.h"
    KAL_ERROR_STRING_END
#undef X_KAL_ERROR_STRING
} kal_error_str;

typedef struct
{
    kal_uint32 param1;
    kal_uint32 param2;
    kal_uint32 param3;
    kal_uint32 param4;
    kal_uint32 param5;
    kal_uint32 param6;
    kal_uint32 param7;
    kal_uint32 param8;
} kal_error_param;

#if defined(__MTK_TARGET__)
#if defined(KAL_ON_NUCLEUS)
#if defined(__NUCLEUS_VERSION_2__)

extern void TMCT_Timer_Interrupt(int) ;
#define Kal_Timer_Interrupt() TMCT_Timer_Interrupt(0);

#else /* __NUCLEUS_VERSION_2__ */

#if defined(__EVENT_BASED_TIMER__)
extern void TMC_Timer_Interrupt(void) ;
#define Kal_Timer_Interrupt() TMC_Timer_Interrupt();
#else /* __EVENT_BASED_TIMER__ */
extern void TMT_Timer_Interrupt(void) ;
#define Kal_Timer_Interrupt() TMT_Timer_Interrupt();
#endif /* __EVENT_BASED_TIMER__ */

#endif /* __NUCLEUS_VERSION_2__ */
#elif defined(KAL_ON_THREADX)   /* KAL_ON_NUCLEUS */

extern void _tx_timer_interrupt(void);
#define Kal_Timer_Interrupt() _tx_timer_interrupt();

#else
#error "Unknown OS!"
#endif  /* KAL_ON_NUCLEUS */
#endif /* __MTK_TARGET__ */

/*******************************************************************************
 * Category 1 : StdLib-like Function (MISC.)
 *******************************************************************************/
extern char *basename(char *file);

/*******************************************************************************
 * Category 3 : LISR, HISR and TASK functions
 *******************************************************************************/
void *kal_create_thread_stack(kal_uint32 stack_size, kal_bool in_intsram, kal_uint32 *real_size);
kal_taskid kal_create_task(kal_char *task_name_ptr, kal_uint8 priority, void *stack_addr, kal_uint32 stack_size, \
                           kal_task_func_ptr entry_func_ptr, void *entry_param_ptr, kal_uint8 options);
void kal_delete_task(kal_taskid task_id);
#if !defined(__MTK_TARGET__)
kal_hisrid kal_create_hisr(kal_char* hisr_name, kal_uint8 priority, kal_uint32 stack_size, \
                           kal_hisr_func_ptr entry_func, kal_uint8 options);
#endif
extern kal_bool stack_is_task_existed(module_type module_id);
/*******************************************************************************
 * Category 4 : Message Passing and Queue
 *******************************************************************************/
void kal_delete_msg_q(kal_msgqid queue_id);

/*******************************************************************************
 * Category 5 : Synchronous Mechanism 
 *******************************************************************************/
kal_uint32 kal_take_thread_protect(void);
void kal_give_thread_protect(kal_uint32 v);

/*******************************************************************************
 * Category 6 : Application Memory Management  ADM , AFM
 *******************************************************************************/
/* obsolete API (for backward compatible only) */
extern void *kal_adm_internal_alloc(KAL_ADM_ID adm_id, kal_uint32 size, char *filename, kal_uint32 line);

/*******************************************************************************
 * Category 7 : System and Modem Memory Management 
 *******************************************************************************/
extern void *kal_sys_mem_alloc(kal_uint32 size);
extern void kal_sys_mem_free(void *ptr);
extern kal_uint32 kal_sys_mem_query_freesize(void);
extern void kal_sys_mem_sort_frags(void);
#ifdef DEBUG_KAL
extern void *kal_debug_mem_alloc(kal_uint32 size);
extern void kal_debug_mem_free(void *p);
extern kal_uint32 kal_debug_mem_query_freesize(void);
#endif

kal_poolid kal_create_buff_pool(kal_uint32 buff_size, kal_uint16 num_buffs);
void kal_delete_buff_pool(kal_poolid pool_id);
void *kal_get_buffer(kal_poolid ext_pool_id, kal_uint32  alloc_id, kal_uint32 size, 
                     kal_char* alloc_file, kal_uint32 alloc_line, kal_uint32 caller_addr);
void kal_release_buffer(void *usr_buff, kal_uint32 dealloc_id,
                        kal_char *dealloc_file, kal_uint32 dealloc_line);
kal_uint32 kal_get_num_free_buffs( kal_poolid pool_id );
kal_bool kal_query_ctrlbuf_max_consumption(kal_uint32 *ptr);

kal_uint32 kal_query_ctrlbuf_size_level(void);
kal_uint32 kal_query_ctrlbuf_size(kal_uint32 level);
kal_bool kal_query_ctrlbuf_alloc_num(kal_uint32 *ptr);
kal_bool kal_retrieve_ctrlbuf_info(kal_uint32 level, kal_uint32 index, kal_uint32 *ptr);



/*******************************************************************************
 * Category 8 : Timer Service
 *******************************************************************************/
void kal_evshed_create_pool(void);
void* kal_evshed_get_mem(kal_uint32 size);
void kal_evshed_free_mem(void* buff_ptr);

kal_uint32 kal_check_allowed_sleep_clock(kal_uint32 period_ticks);
void kal_recover_clock(kal_uint32 delayed_ticks);
void kal_invoke_expired_events(kal_uint32 delayed_ticks);
#ifdef KAL_ON_OSCAR
/* this routine adjust simulated tick time in millisecond by user */
void kal_adjust_sim_tick(kal_uint32 new_msec);
#endif

 /*******************************************************************************
 * Category 9 : Error Handling
 *******************************************************************************/
typedef void (*kal_error_func_ptr)(kal_uint32, kal_uint32);
#if defined(__KAL_ASSERT_LEVEL4__) && defined(__MTK_TARGET__)
#define kal_fatal_error_handler(code1, code2) \
    do { \
        extern void INT_ExceptionSaveCpuReg(void); \
        extern void kal_fatal_error_handler_int(kal_uint32 error_code, kal_uint32 os_error_code); \
        INT_ExceptionSaveCpuReg(); \
        kal_fatal_error_handler_int(code1, code2); \
    } while(0)
#else /* __KAL_ASSERT_LEVEL4__ */
#define kal_fatal_error_handler(code1, code2) \
    do { \
        extern void kal_fatal_error_handler_int(kal_uint32 error_code, kal_uint32 os_error_code); \
        kal_fatal_error_handler_int(code1, code2); \
    } while(0)

#endif /* __KAL_ASSERT_LEVEL4__ */
void kal_register_fatal_error_handler(kal_error_func_ptr fatal_handler_ptr);
void kal_exit(void);

extern void stack_rand_seed(kal_uint32 seed);

#if defined(KAL_ON_NUCLEUS)
#include "Nucleus.h"
#elif defined (KAL_ON_OSCAR)
#include "osc_release.h"
#elif defined(KAL_ON_THREADX)
#include "tx_api.h"
#endif

#if defined(KAL_ON_NUCLEUS)

#if KAL_CONSUME != NU_OR_CONSUME 
#error KAL_CONSUME is not equals to NU_OR_CONSUME
#endif
#if KAL_AND != NU_AND 
#error KAL_AND is not equals to NU_AND
#endif
#if KAL_AND_CONSUME !=  NU_AND_CONSUME
#error KAL_AND_CONSUME is not equals to NU_AND_CONSUME
#endif
#if KAL_OR != NU_OR 
#error KAL_OR is not equals to NU_OR
#endif
#if KAL_OR_CONSUME !=  NU_OR_CONSUME
#error KAL_OR_CONSUME is not equals to NU_OR_CONSUME
#endif
#if KAL_NO_SUSPEND != NU_NO_SUSPEND 
#error KAL_NO_SUSPEND is not equals to NU_NO_SUSPEND
#endif
#if KAL_SUSPEND != NU_SUSPEND 
#error KAL_SUSPEND is not equals to NU_SUSPEND
#endif

#elif defined (KAL_ON_OSCAR)    /* KAL_ON_NUCLEUS */    

#if KAL_CONSUME != OSC_ACTION_CLS 
#error KAL_CONSUME is not equals to NU_OR_CONSUME
#endif
#if KAL_AND != OSC_ACTION_FULL_SET 
#error KAL_AND is not equals to OSC_ACTION_FULL_SET
#endif
#if KAL_AND_CONSUME !=  (OSC_ACTION_FULL_SET | OSC_ACTION_CLS)
#error KAL_AND_CONSUME is not equals to (OSC_ACTION_FULL_SET | OSC_ACTION_CLS)
#endif
#if KAL_OR != OSC_ACTION_PART_SET 
#error KAL_OR is not equals to OSC_ACTION_PART_SET
#endif
#if KAL_OR_CONSUME != (OSC_ACTION_PART_SET | OSC_ACTION_CLS)
#error KAL_OR_CONSUME is not equals to OSC_ACTION_PART_SET | OSC_ACTION_CLS
#endif
#if KAL_NO_SUSPEND != OSC_TIMEOUT_NONE 
#error KAL_NO_SUSPEND is not equals to OSC_TIMEOUT_NONE
#endif
#if KAL_SUSPEND != OSC_TIMEOUT_FOREVER 
#error KAL_SUSPEND is not equals to OSC_TIMEOUT_FOREVER
#endif

#elif defined(KAL_ON_THREADX)   /* KAL_ON_NUCLEUS */

#if KAL_CONSUME != TX_OR_CLEAR 
#error KAL_CONSUME is not equals to TX_OR_CLEAR
#endif
#if KAL_AND != TX_AND 
#error KAL_AND is not equals to TX_AND
#endif
#if KAL_AND_CONSUME !=  TX_AND_CLEAR
#error KAL_AND_CONSUME is not equals to TX_AND_CLEAR
#endif
#if KAL_OR != TX_OR 
#error KAL_OR is not equals to TX_OR
#endif
#if KAL_OR_CONSUME !=  TX_OR_CLEAR
#error KAL_OR_CONSUME is not equals to TX_OR_CLEAR
#endif
#if KAL_NO_SUSPEND != TX_NO_WAIT 
#error KAL_NO_SUSPEND is not equals to TX_NO_WAIT
#endif
#if KAL_SUSPEND != TX_WAIT_FOREVER 
#error KAL_SUSPEND is not equals to TX_WAIT_FOREVER
#endif  

#endif  /* KAL_ON_NUCLEUS */

#if defined(KAL_ON_NUCLEUS)
#include "kal_nucleus_common_defs.h"
#include "kal_nucleus.h"
#elif defined(KAL_ON_OSCAR)
#include "kal_oscar_common_defs.h"
#include "kal_oscar.h"
#elif defined(KAL_ON_THREADX)
#include "kal_threadx.h"
#endif

#include "kal_debug_common_defs.h"

#if defined(KAL_ON_NUCLEUS)
#include "kal_debug_nucleus.h"
#elif defined(KAL_ON_OSCAR)
#include "kal_debug_oscar.h"
#endif

#include "kal_debug.h"

#if defined(__MTK_TARGET__) || defined (KAL_ON_OSCAR)
/*************************************************************************
 * Type Definitions
 *************************************************************************/
struct ptr_node {
	void* ptr;
	kal_uint32 size;
	struct ptr_node* next_ptr;
};

#if defined(DEBUG_KAL) && defined(DEBUG_BUF1)
typedef struct kal_pool_statistics_struct {
	kal_uint16 current_allocation;
	kal_uint16 max_num_allocated;
} *kal_pool_statistics;
#endif	/* defined(DEBUG_KAL) && defined(DEBUG_BUF1)  */

#if defined(DEBUG_KAL) && defined(DEBUG_BUF2)
typedef struct kal_pool_statistics_struct {
	kal_uint16 current_allocation;
	kal_uint16 max_num_allocated;
	kal_uint32 max_size_requested;/* Maximum requested size from the pool */
} *kal_pool_statistics;
#endif	/* defined(DEBUG_KAL) && defined(DEBUG_BUF2)  */


#if defined(DEBUG_KAL) && defined(DEBUG_BUF1)

typedef struct kal_int_pool_statistics_struct {
	struct kal_pool_statistics_struct   pool_info;
	kal_uint32*          buff_caller_addr;
} *kal_internal_pool_statistics, kal_pool_stat_type;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_BUF1) */


#if defined(DEBUG_KAL) && defined(DEBUG_BUF2)

typedef struct kal_buff_stats {
	kal_uint8   unused;
}* kal_buff_statistics;

typedef struct kal_int_pool_statistics_struct {
	struct kal_pool_statistics_struct   pool_info;
	struct kal_int_buff_stats*          buff_stat;
} *kal_internal_pool_statistics, kal_pool_stat_type;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_BUF2) */

typedef void(*kal_print_string_func_ptr)(kal_char*);

#if defined(DEBUG_KAL) && defined(DEBUG_TASK)
typedef struct kal_task_statistics_struct {
	kal_uint8   unused;
} *kal_task_statistics;
#endif /* defined(DEBUG_KAL) && defined(DEBUG_TASK) */

#if defined(DEBUG_KAL) && defined(DEBUG_ITC)

typedef struct kal_queue_statistics_struct {
	kal_uint8   unused;
}* kal_queue_statistics;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

#if defined(DEBUG_TIMER) && defined(DEBUG_KAL)
typedef struct kal_timer_statistics_struct {
	kal_uint8   unused;
}* kal_timer_statistics;
#endif /* defined(DEBUG_TIMER) && defined(DEBUG_KAL) */

/*************************************************************************
 * Task Management
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_TASK)


#define kal_get_task_statistics( task_id, stat_ptr ) {}
#define kal_reset_task_statistics(  task_id ) {}

#else	/* defined(DEBUG_KAL) && defined(DEBUG_TASK) */

#define kal_get_task_statistics( task_id, stat_ptr ) {}
#define kal_reset_task_statistics(  task_id ) {}

#endif /* defined(DEBUG_KAL) && defined(DEBUG_TASK) */

/*************************************************************************
 * ITC Management
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_ITC)

#define kal_get_q_statistics(queue_id, stat_ptr ) \
      kal_debug_get_q_statistics(queue_id, stat_ptr )

#define kal_reset_q_statistics(  queue_id )\
      kal_debug_reset_q_statistics(  queue_id )

void kal_debug_get_q_statistics( kal_msgqid  queue_id, kal_queue_statistics* stat_ptr );
void kal_debug_reset_q_statistics( kal_msgqid    queue_id );

#else	/* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

#define kal_get_q_statistics(queue_id, stat_ptr ) {}
#define kal_reset_q_statistics(  queue_id ) {}

#endif /* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

/*************************************************************************
 * Buffer Management
 *************************************************************************/
#if defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) )

#define KAL_GET_POOL_STATISTICS_ADDR( pool_id ) \
	(kal_pool_statistics) ((kal_internal_poolid) pool_id)->pool_stat

void kal_debug_reset_pool_statistics(kal_poolid pool_id);

#ifdef DEBUG_BUF2

#define KAL_BUFF_STAT_SET_INUSE(buff_stat_ptr) \
	(buff_stat_ptr)->owner_task = (kal_internal_taskid)((kal_uint32)(buff_stat_ptr)->owner_task | 0x01)

void kal_debug_get_buffer_statistics(void* buffer_ptr, kal_buff_statistics* stat_ptr);
void kal_debug_reset_buffer_statistics(void* buffer_ptr);

#endif

#endif /* defined(DEBUG_KAL) && ( defined(DEBUG_BUF1) || defined(DEBUG_BUF2) ) */

/*************************************************************************
 * Memory Management
  *************************************************************************/


/*************************************************************************
 * Timer Management
 *************************************************************************/
#if defined(DEBUG_TIMER) && defined(DEBUG_KAL)

void kal_debug_get_timer_statistics(kal_timerid timer_id, kal_timer_statistics* stat_ptr);
void kal_debug_reset_timer_statistics(kal_timerid timer_id );

#define kal_get_timer_statistics(  timer_id, stat_ptr ) ;\
      kal_debug_get_timer_statistics(  timer_id, stat_ptr ) ;

#define kal_reset_timer_statistics(timer_id )\
      kal_debug_reset_timer_statistics(timer_id )

#else	/* defined(DEBUG_TIMER) && defined(DEBUG_KAL) */

#define kal_get_timer_statistics(  timer_id, stat_ptr ) ; {}
#define kal_reset_timer_statistics(timer_id ) {}

#endif /* defined(DEBUG_TIMER) && defined(DEBUG_KAL) */

/*************************************************************************
 * Error Handling and Debug Management
 *************************************************************************/
/*What a pity, RVCT C doesn't support inline function*/
#ifdef __MTK_TARGET__
#define kal_get_linker_address(ret_value)\
do\
{\
    kal_uint32 link_register;\
    /* \
     * NoteXXX: retrieve link register before any function call\
     *\
     */\
    link_register = __return_address();\
    if(link_register & 0x01)\
    {\
        link_register -= 3;\
    }\
    else\
    {\
        link_register -= 4;     \
    } \
    ret_value = link_register; \
}while(0)
#else
#define kal_get_linker_address(ret_value)\
do                                       \
{                                        \
    ret_value = (kal_uint32)_ReturnAddress();                       \
}while(0)                              
#endif

#if defined(DEBUG_KAL)

#ifdef DEBUG_LEAK
void kal_settimeout(void* addr, kal_timer_func_ptr handler_func_ptr,
						  void* handler_param_ptr, kal_uint32 delay);
void kal_untimeout(void* addr);
void kal_default_timeouthandler(void*);
#endif /* DEBUG_LEAK */

void kal_debug_register_print_string_function (kal_print_string_func_ptr func_ptr);
void kal_debug_print(kal_char* string_to_be_printed);
void kal_debug_print_int(kal_int32 int_to_be_printed);
void kal_debug_print_uint(kal_uint32 int_to_be_printed);
void kal_debug_print_uint_in_hex(kal_uint32 int_to_be_printed);
void kal_debug_abort( void );
void kal_debug_reset( void );

#define kal_register_print_string_function( to_be_registered_func)\
      kal_debug_register_print_string_function( to_be_registered_func)

#define kal_print_int( int_to_be_printed )\
      kal_debug_print_int( int_to_be_printed )

#define kal_print_uint( int_to_be_printed )\
      kal_debug_print_uint( int_to_be_printed )

#define kal_print_uint_in_hex( int_to_be_printed )\
      kal_debug_print_uint_in_hex( int_to_be_printed )

#define kal_enable_debug( debug_code, flag )\
      kal_debug_enable_debug( debug_code, flag )

#define kal_abort() kal_debug_abort()

#define kal_reset() kal_debug_reset()

#else	/* defined(DEBUG_KAL) */

#define kal_register_print_string_function( to_be_registered_func) {}
#define kal_print_int( int_to_be_printed )  {}
#define kal_print_uint( int_to_be_printed )  {}
#define kal_print_uint_in_hex( int_to_be_printed )  {}
#define kal_enable_debug( debug_code, flag ) {}
#define kal_abort() {}
#define kal_reset() {}

#endif	/* defined(DEBUG_KAL) */


#if defined(__MTK_TARGET__) && defined(__KAL_STACK_SHARING__)

extern NU_PROTECT g_stack_pool_protect;
extern NU_PROTECT TCD_System_Protect;
extern void TCT_Unprotect_Specific(NU_PROTECT *protect);

#define KAL_ENTER_STACK_POOL_CS TCT_Protect(&g_stack_pool_protect)
#define KAL_LEAVE_STACK_POOL_CS TCT_Unprotect_Specific(&g_stack_pool_protect)

#define KAL_ENTER_SYSTEM_CS	TCT_Protect(&TCD_System_Protect);
#define KAL_LEAVE_SYSTEM_CS	TCT_Unprotect_Specific(&TCD_System_Protect);

#define KAL_STACK_MOVABLE_BIT			0x01
#define KAL_STACK_LOCK_SHARING_BIT		0x02

#define KAL_STACK_FLAG_INITIAL_PATTERN	0xFF00FFFF

#define SET_INI_STACK_SIZE(dst_addr,size)	do{													\
												(*dst_addr) &= 0xFFFF0000;						\
												(*dst_addr) |= ( (size) & 0x0000ffff);			\
											}while(0)
#define SET_MOVABLE_FLAG(dst_addr,flag)		do{													\
												(*dst_addr) &= 0xFF00FFFF;						\
												(*dst_addr) |= ( ((flag) << 16) & 0x00ff0000 );	\
											}while(0)
#define SET_TASK_INDEX(dst_addr,index)		do{													\
												(*dst_addr) &= 0x00FFFFFF;						\
												(*dst_addr) |= ( ((index) << 24) & 0xff000000);	\
											}while(0)

#define GET_INI_STACK_SIZE(src_word)		((src_word) & 0x0000ffff)
#define GET_MOVABLE_FLAG(src_word)			(((src_word) >> 16) & 0x000000ff)
#define GET_TASK_INDEX(src_word)			(((src_word) >> 24) & 0x000000ff)

extern void *__kal_stack_realloc(KAL_ADM_ID adm_id, void *p, kal_uint32 size, kal_uint32 *actual_size, kal_uint32 option, char *filename, kal_uint32 line);
KAL_ADM_ID kal_adm_create_for_stack(void *mem_addr, kal_uint32 size, kal_uint32 *subpool_size, kal_uint32 flags);
void *kal_adm_alloc_for_stack(KAL_ADM_ID adm_id, kal_uint32 size,kal_uint32 option);
void *kal_adm_realloc_for_stack(KAL_ADM_ID adm_id, void *p,  kal_uint32 size);
void kal_adm_free_for_stack(KAL_ADM_ID adm_id, void *mem_addr);
kal_bool kal_is_task_stack_nonshareable(kal_uint32 task_index);
/*************************************************************************
* <GROUP Functions>
* 
* FUNCTION
*  kal_check_all_task_stacks
*
* DESCRIPTION
*   This routine is to check whether the start of all task stack is corrupted.
*   If so, the system enter fatal error handling.
*
* PARAMETERS
*  N/A
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void kal_check_all_task_stacks(void);

#endif

#endif /* defined(__MTK_TARGET__) || defined (KAL_ON_OSCAR) */

/*************************************************************************
 * Types used by run-time sysmem statistic
 *************************************************************************/
#if defined(__MTK_TARGET__)
#define KAL_RT_SYSMEM_SIZE_MUTEX ( sizeof(kal_mutex_type) )
#define KAL_RT_SYSMEM_SIZE_SEM ( sizeof(kal_sem_type) )
#define KAL_RT_SYSMEM_SIZE_EVENT_GROUP ( sizeof(kal_eventgrp_type) )
#define KAL_RT_SYSMEM_SIZE_KAL_TIMER ( sizeof(kal_timer_type) ) 
#define KAL_RT_SYSMEM_SIZE_STACK_TIMER ( KAL_RT_SYSMEM_SIZE_KAL_TIMER + sizeof(stack_timer_struct) ) 
#define KAL_RT_SYSMEM_SIZE_EVSHED ( KAL_RT_SYSMEM_SIZE_STACK_TIMER + sizeof(event_scheduler_int) )
#if defined(DEBUG_KAL) && defined(KAL_ON_NUCLEUS)
#define KAL_RT_SYSMEM_SIZE_ENH_MUTEX ( sizeof(kal_internal_enhmutex_type) )
#endif
#if defined(DEBUG_KAL)
extern kal_uint8 system_resource_amount[];
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* __KAL_INTERNAL_API__ */
