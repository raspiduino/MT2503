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
 *     kal_autotest.c
 *
 * Project:
 * --------
 *     Maui_Software
 *
 * Description:
 * ------------
 *     This file exposes the KTEST framework
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* this file is valid only when __KTEST__ has been defined */
#ifdef __KTEST__
 
#include "kal_release.h"
#include "syscomp_config.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "task_config.h"
#include "ktest_common.h"
#include "rtc_sw.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "hisr_config.h"
#ifdef __MTK_TARGET__
#include "dcl.h"
#endif
#include "ktest_interface.h"
#include "stdlib.h"

/******************************************************************************
 * external APIs and variables that will be used in this file.
 *****************************************************************************/
extern void TCT_Schedule( void );
extern void *kal_create_thread_stack( kal_uint32 stack_size,
                                      kal_bool in_intsram,
                                      kal_uint32 *real_size );
extern kal_taskid kal_create_task( kal_char* task_name, kal_uint8 priority,
                                   void *stack_addr, kal_uint32 stack_size,
                                   kal_task_func_ptr entry_func,
                                   void *entry_param, kal_uint8 options );
extern void* kal_sys_mem_alloc( kal_uint32 size );
extern void mm_enable_power( kal_uint32 module );

#if defined( KAL_ON_NUCLEUS )
extern TC_HCB *TMD_HISR_Ptr;
extern void TMC_Timer_HISR( void );
#endif  /* KAL_ON_NUCLEUS */

#if defined( KAL_ON_OSCAR )
extern osc_struct_thread *g_osc_Timer_HISR;
extern void OSC_Timer_HISR( void );
#endif  /* KAL_ON_OSCAR */

/******************************************************************************
 * ktest internal use
 *     kal_task_func_ptr: a pointer to a function prototype which is the entry
 *                        function of a KAL task.
 *****************************************************************************/
typedef void (*kal_task_func_ptr)( task_entry_struct *task_entry_ptr );

/******************************************************************************
 * Global variables:
 *     KTEST_TCID: name of test case in KTEST.
 *         It must be assigned KTEST_FUNCTION_NAME when writing a test case.
 *     KTEST_BRIEF: basic description of test case.
 *         It's sugguested to assign a suitable value to it when writing a test
 *         case.
 *     KTEST_EXPECT_ERR_CODE: it indicates which fatal error is expected.
 *         If the fatal error occurs in test case is just the one we expected,
 *         then ktest will report this case passed.
 *         Else, it will report this case failed.
 *     KTEST_EXP_ASSERT_STR: it indicates which assert string is expected.
 *         If the assert string occurs in test case is just the one expected,
 *         then ktest will report this case passed.
 *         Else, it will report this case failed.
 *****************************************************************************/
const kal_char *KTEST_TCID;
const kal_char *KTEST_BRIEF;
kal_uint32 KTEST_EXPECT_ERR_CODE;
kal_char *KTEST_EXP_ASSERT_STR;

/******************************************************************************
 * There are three steps to add a module into KTEST
 * 1) add test case module's init function declaration here
 * 2) declare an enum in ktest_tc_modules
 * 3) invoke the init function in ktest_testcase_register
 *****************************************************************************/
/******************************************************************************
 * 1st step to add a module into KTEST:
 *     add the init function declaration below.
 *     note that the order of init functions does not matter.
 *****************************************************************************/
extern void ktest_task_init( kal_uint32 );
extern void ktest_mm_ctrlbuf_init( kal_uint32 );
extern void ktest_fsm_init( kal_uint32 );
extern void ktest_mm_adm_init( kal_uint32 );
extern void ktest_mm_afm_init( kal_uint32 mod );
extern void ktest_ipc_init( kal_uint32 );
extern void ktest_timer_init( kal_uint32 );
extern void ktest_utl_init( kal_uint32 );
extern void ktest_mlib_init( kal_uint32 );
extern void ktest_sandbox_init( kal_uint32 );
extern void ktest_timer_nu_event_timer_init( kal_uint32 );

/******************************************************************************
 * 2nd step to add a module into KTEST:
 *     add a enum into ktest_tc_modules.
 * Note: the order by which test cases runs is determined by the order of enums
 *       declaration in ktest_tc_modules.
 *****************************************************************************/
typedef enum {
    TC_MOD_TASK = 0,
    TC_MOD_MM_CTRLBUF,
    TC_MOD_FSM,
    TC_MOD_MM_ADM,
    TC_MOD_MM_AFM,
    TC_MOD_IPC,
    TC_MOD_TIMER,
    TC_MOD_NU_EVENT_TIMER,
    TC_MOD_UTL,
    TC_MOD_MLIB,
    TC_MOD_SANDBOX,
    TC_MOD_MAX_NUM,
} ktest_tc_modules;

/******************************************************************************
 * 3rd step to add a module into KTEST:
 *     invoke the init function of the module than you want to added in.
 *     note that the order of them does not matter.
 * Note: if you don't want a module to run, just comment it out here.
 *****************************************************************************/
static kal_bool ktest_testcase_register( void )
{
    ktest_task_init( TC_MOD_TASK );
    ktest_mm_ctrlbuf_init( TC_MOD_MM_CTRLBUF );
    /* gprs load has no fsm lib */
#ifdef __UMTS_RAT__
/* under construction !*/
#endif
    ktest_mm_adm_init( TC_MOD_MM_ADM );
    ktest_mm_afm_init( TC_MOD_MM_AFM );
    ktest_ipc_init( TC_MOD_IPC );
    ktest_timer_init( TC_MOD_TIMER );
#if defined( KAL_ON_NUCLEUS ) && defined( __EVENT_BASED_TIMER__ ) \
        && defined( __NUCLEUS_VERSION_2__ )
    ktest_timer_nu_event_timer_init( TC_MOD_NU_EVENT_TIMER );
#endif
    ktest_utl_init( TC_MOD_UTL );
	ktest_mlib_init( TC_MOD_MLIB );
    ktest_sandbox_init( TC_MOD_SANDBOX );

    /* it always return KAL_TRUE */
    return KAL_TRUE;
}

/******************************************************************************
 * Global variables:
 *     tc_all_tbls: it contains all modules (post-schedule stage) in KTEST.
 *     pre_tc_all_tbls: it contains all modules (pre-schedule stage) in KTEST.
 *     tc_modules_num: each element in it is the total number of test cases (in
 *         post-schedule stage) in corresponding module.
 *     pre_tc_modules_num: each element in it is the total number of test cases
 *         (in pre-schedule stage) in corresponding module.
 *****************************************************************************/
ktest_tc_struct const* tc_all_tbls[TC_MOD_MAX_NUM];
ktest_tc_struct const* pre_tc_all_tbls[TC_MOD_MAX_NUM];
kal_uint32 tc_modules_num[TC_MOD_MAX_NUM];
kal_uint32 pre_tc_modules_num[TC_MOD_MAX_NUM];

/******************************************************************************
 * Name:
 *     ktest_module_tc_num
 * Functionality:
 *     It gets the total number of test cases in a module which indicated by
 *     the parameter "tc_id".
 * Parameters:
 *     tc_id: test case label. It indicates the module and stage (pre-schedule
 *         or post-schedule).
 * Returns:
 *     the total number of test cases in a module (pre-schedule/post-schedule).
 *****************************************************************************/
static kal_uint32 ktest_module_tc_num( const ktest_tc_label *tc_id )
{
    if( tc_id->stage == TC_PRE_SCHEDULE )
    {
        /* pre-schedule stage */
        return pre_tc_modules_num[tc_id->module];
    }
    else
    {
        /* post-schedule stage */
        return tc_modules_num[tc_id->module];
    }
}

/******************************************************************************
 * Name:
 *     total_testcases
 * Functionality:
 *     It caculates the total number of test cases in all modules (include both
 *     pre-schedule stage and post-schedule stage).
 * Parameters:
 *     void.
 * Returns:
 *     the total number of all test cases in KTEST.
 *****************************************************************************/
static kal_uint32 total_testcases( void )
{
    kal_uint32 i, total;
    total = 0;

    for( i = 0; i < TC_MOD_MAX_NUM; i++ )
    {
        total += pre_tc_modules_num[i];
        total += tc_modules_num[i];
    }

    return total;
}

/******************************************************************************
 * Name:
 *     ktest_is_mod_last_tc
 * Functionality:
 *     check whether the test case indicated by tc_id is the last one in its
 *     module.
 * Parameters:
 *     tc_id: test case label. It indicates the (stage, moduel, index_of_case).
 * Returns:
 *     If it's the last one in its module, return KAL_TRUE.
 *     Else, return KAL_FALSE.
 *****************************************************************************/
static kal_bool ktest_is_mod_last_tc( const ktest_tc_label *tc_id )
{
    if( ktest_module_tc_num( tc_id ) == 0 ||
            tc_id->index == ktest_module_tc_num(tc_id) - 1 )
    {
        /* the last test case in its module */
        return KAL_TRUE;
    }
    else
    {
        /* not the last test case in its module */
        return KAL_FALSE;
    }
}

/******************************************************************************
 * Name:
 *     ktest_is_last_tc
 * Functionality:
 *     check whether the test case indicated by tc_id is the last one of all
 *     test cases in pre-schedule stage or post-schedule stage.
 * Parameters:
 *     tc_id: test case label. It indicates the (stage, module, index_of_case).
 * Returns:
 *     If it's the last one of all test cases in all module, return KAL_TRUE.
 *     Else, return KAL_FALSE.
 *****************************************************************************/
static kal_bool ktest_is_last_tc( const ktest_tc_label *tc_id )
{
    /* if it's the last test case in the last module, that means it's the last
     * one of all test cases. */
    if( (tc_id->module == TC_MOD_MAX_NUM -1) && ktest_is_mod_last_tc( tc_id ) )
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/******************************************************************************
 * Name:
 *     ktest_is_init_stage
 * Functionality:
 *     check whether KTEST is in pre-schedule stage.
 * Parameters:
 *     tc_id: test case label. It's format is (stage, module, index_of_case).
 * Returns:
 *     If KTEST is in pre-schedule stage, return KAL_TRUE.
 *     Else, return KAL_FALSE.
 *****************************************************************************/
static kal_bool ktest_is_init_stage( const ktest_tc_label *tc_id )
{
    return ( tc_id->stage == TC_PRE_SCHEDULE ) ? KAL_TRUE : KAL_FALSE;
}

/******************************************************************************
 * Name:
 *     ktest_next_tc
 * Functionality:
 *     It will find out the next test case.
 * Parameters:
 *     tc_id: test case label. It's format is (stage, module, index_of_case).
 *         when this function starts running, tc_id indicates the current test
 *         case. when this function ends, tc_id indicates the next test case to
 *         run.
 * Returns:
 *     If we find the next test case, return KAL_TRUE.
 *     Else, return KAL_FALSE.
 *****************************************************************************/
static kal_bool ktest_next_tc( ktest_tc_label *tc_id )
{
    /* if the test case indicated by tc_id is the last one in pre-schedule or
     * post-schedule stage */
    if( (tc_id->module == TC_MOD_MAX_NUM -1) && ktest_is_mod_last_tc( tc_id ) )
    {
        /* it's the last test case in pre-schedule stage, so KTEST need to
         * across stage: from pre-schedule to post-schedule */
        if( tc_id->stage == TC_PRE_SCHEDULE )
        {
            tc_id->stage = TC_POST_SCHEDULE;
            tc_id->module = 0;
            tc_id->index = 0;
            return KAL_TRUE;
        }
        else
        {
            /* it's the last test case in post-schedule stage, so there is no
             * next test case to run. */
            return KAL_FALSE;
        }
    }

    /* we can come here because the test case indicated by tc_id is not the
     * last one of all modules. */
    if( ktest_is_mod_last_tc( tc_id ) )
    {
        /* if it's the last test case of a module, then KTEST need to across
         * module. */
        tc_id->module++;
        tc_id->index = 0;
    }
    else
    {
        /* if it's not the last test case of a module, then we let tc_id points
         * to the next test case. */
        tc_id->index++;
    }

    /* we have found the next test case */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_run_tc
 * Functionality:
 *     run the test case indicated by tc_ptr.
 * Parameters:
 *     tc_ptr: test case label, and it indicates the test case to run.
 * Returns:
 *     If no test case to run, return KAL_TRUE.
 *     Else, return the result of test case's main function.
 *****************************************************************************/
static kal_uint32 ktest_run_tc( const ktest_tc_label *tc_ptr )
{

    kal_uint32 	argc;
    kal_uint8 	*argv;
    kal_uint8 module = tc_ptr->module;
    kal_uint8 index = tc_ptr->index;
    kal_uint32 tc_no = ktest_module_tc_num( tc_ptr );

    /* if there is no test case to run, return KAL_TRUE. */
    if( 0 == tc_no || index > tc_no - 1 )
    {
        return KAL_TRUE;
    }

    /* initialize the value of global variables below, and we must note that
     * these values may be changed in test case's main function. */
    KTEST_EXPECT_ERR_CODE = 0;
    KTEST_EXP_ASSERT_STR = NULL;
    KTEST_TCID = "ktest name not initialized";
    KTEST_BRIEF = NULL;

    /* run the test case. */
    if( tc_ptr->stage == TC_POST_SCHEDULE )
    {
        /* in post-schedule stage */
        argc = tc_all_tbls[module][index].argc;
        argv = tc_all_tbls[module][index].argv;
        return tc_all_tbls[module][index].tc_main_fn( argc, argv );
    }
    else
    {
        /* in pre-schedule stage */
        argc = pre_tc_all_tbls[module][index].argc;
        argv = pre_tc_all_tbls[module][index].argv;
        return pre_tc_all_tbls[module][index].tc_main_fn( argc, argv );
    }

    /* will this statement be executed ever ??? */
    return (kal_uint32) KAL_FALSE;
}

/******************************************************************************
 * Name:
 *     ktest_destroy_tc_label
 * Functionality:
 *     It make the test case label invalid by writing rabish data to test case
 *     label's head and tail.
 * Parameters:
 *     void.
 * Returns:
 *     If the test case label can be destroyed, return KAL_TRUE.
 *     Else, return KAL_FALSE.
 *****************************************************************************/
static kal_bool ktest_destory_tc_label( void )
{
    ktest_tc_label tc;

    /* change the head of test case label from "KTESTz" to "RABISH" */
    ktest_strncpy( tc.magic, KTEST_TC_MAGIC_TRASH, KTEST_TC_MAGIC_LEN );

    /* change the stage of test case label to "TC_STAGE_OVER" */
    tc.stage = TC_STAGE_OVER;
    tc.module = 0;
    tc.index = 0;

    /* change the tail of test case label from "jmf" to "xnd" */
    ktest_strncpy( tc.tail, KTEST_TC_TAIL_TRASH, KTEST_TC_TAIL_LEN );

    /* all of the above operations are intended to mark the test case label as
     * invalid, and we need to write these changed values to test case label
     * permanently. */
    return ktest_write_tc_label( &tc );
}

/******************************************************************************
 * Name:
 *     ktest_main
 * Functionality:
 *     main function of KTEST framework task.
 * Parameters:
 *     task_entry_ptr: a pointer to task_entry_struct, but not used here.
 * Returns:
 *     void.
 *****************************************************************************/
static void ktest_main( task_entry_struct *task_entry_ptr )
{
    /* ktest_engine is the real control flow of KTEST framework */
    ktest_engine();
}

/******************************************************************************
 * Name:
 *     ktest_create_framework_task
 * Functionality:
 *     create a task that run KTEST framework.
 * Parameters:
 *     void.
 * Returns:
 *     If the task was created successfully, return KAL_TRUE.
 *     Else, a fatal error will occurs.
 *****************************************************************************/
static kal_bool ktest_create_framework_task( void )
{
    kal_uint32 task_index = INDX_KTEST;
    task_entry_struct *task_entry_para_ptr;

    /* step 1. create thread stack */
    void *stack_addr;
    kal_uint32 real_stack_size;

    stack_addr =
        (void *) kal_create_thread_stack( 4096, KAL_TRUE, &real_stack_size );

    /* step 2. create a task */
    task_entry_para_ptr =
        (task_entry_struct *) kal_sys_mem_alloc( sizeof(*task_entry_para_ptr) );
    task_entry_para_ptr->task_indx = INDX_KTEST;

    task_info_g[task_index].task_id =
        kal_create_task( "ktest", TASK_PRIORITY_KTEST, stack_addr,
                         real_stack_size, ktest_main,
                         (void *) task_entry_para_ptr, KAL_TRUE );

    ((kal_task_type *) task_info_g[task_index].task_id)->task_index = task_index;

    /* step 3. create an external queue for the task just created */
    task_info_g[INDX_KTEST].task_ext_qid =
        kal_create_msg_q( "test", sizeof(ilm_struct), 20 );

    /* if we can come here, that means we have created the task successfully */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_engine
 * Functionality:
 *     main control flow of KTEST framework
 * Parameters:
 *     void.
 * Retruns:
 *     void.
 *****************************************************************************/
static void ktest_engine( void )
{
    ktest_tc_label tc_id;
    ktest_tc_label *tc_ptr = &tc_id;
    while( 1 )
    {
        /* check whether there is enough system memory */
        if( !ktest_sys_check() )
        {
            ktest_reset_target();
        }

        /* read test case label from permanent storage, note that the current
         * label indicates the test case which has just been executed. */
        if( !ktest_read_tc_label( tc_ptr ) )
        {
            /* we need to add error handler here */
        }

        if( kal_query_systemInit() )
        {
            /* we come here because target is in initialization stage */
            if( !ktest_is_init_stage( tc_ptr ) )
            {
                /* target is in init stage, but KTEST is not in pre-schedule
                 * stage. This means KTEST is handling the situation below:
                 *     post-schedule -> reset_target -> system init
                 *                   -> post-schedule */
                ktest_create_framework_task();

                /* go to schedule */
                return;
            }
            else
            {
                /* if we come here, because target is in init stage, and KTEST
                 * is in pre-schedule stage.
                 * So we need to find the next test case to run */
            }
        }
        else
        {
            /* we come here because target is not in initialization stage */
            if( tc_ptr->stage == TC_POST_SCHEDULE
                && ktest_is_last_tc( tc_ptr ) )
            {
                /* KTEST is in post-schedule stage, and the last test case
                 * has been executed. */
                ktest_destory_tc_label();
                ktest_print( "Done! Check there should be %d cases\n\r",
                             total_testcases() );
                ktest_flush();
                break;
            }
            else
            {
                /* Not all test cases run over, so we need to find the next
                 * test case to run */
            }
        }

        /* find the next test case to run */
        if( !ktest_next_tc( tc_ptr ) )
        {
            /* we need to add error handler here */
        }

        /* the checking below is for the first time to across stage:
         *     pre-schedule -> post-schedule */
        if( kal_query_systemInit() )
        {
            if( !ktest_is_init_stage( tc_ptr ) )
            {
                ktest_create_framework_task();
                return;		/*TCT_Schedule*/
            }
        }

        /* ok, we have found the next test case to run, write the test case
         * label to permanent storage before running it */
        ktest_write_tc_label( tc_ptr );

        /* run the test case */
        ktest_run_tc( tc_ptr );
    }/*while*/
}

/******************************************************************************
 * Name:
 *     ktest_sys_check
 * Functionality:
 *     check whether there is enough system memory.
 * Parameters:
 *     void.
 * Returns:
 *     if system memory is enough, return KAL_TRUE.
 *     else, return KAL_FALSE.
 *****************************************************************************/
static kal_bool ktest_sys_check( void )
{
    if( kal_sys_mem_query_freesize() < KTEST_SYS_MEM_WATERMARK )
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

/******************************************************************************
 * Global variable:
 *     ktest_mod_task_g: it will be copied to mod_task_g when ktest bootup
 *****************************************************************************/
static ktest_task_index ktest_mod_task_g[KTEST_MOD_NUM] =
{
    INDX_KTEST_0,
    INDX_KTEST,
    INDX_KTEST1,
    INDX_KTEST1,
    INDX_KTEST2,
    INDX_KTEST2,
    INDX_KTEST3,
    INDX_KTEST3,
    INDX_KTEST4,
    INDX_KTEST5,
    INDX_KTEST6,
    INDX_KTEST7,
};

/******************************************************************************
 * Name:
 *     ktest_stack_init
 * Functionality:
 *     initialization routine of KTEST
 * Parameters:
 *     void.
 * Returns:
 *     If KTEST was initialized successfully, return KAL_TRUE.
 *     Else, return KAL_FALSE.
 *****************************************************************************/
kal_bool ktest_stack_init( void )
{
    kal_bool  ret_val = KAL_FALSE;
    kal_uint32 seed = 0;
    kal_uint32 ticks = 0;
    kal_uint32 second = 0;
    kal_uint16 milli_sec = 0;
    kal_internal_hisrid tmd_hisr_ptr;

#define nvram_get_imei()	(0)

    /* initialize all tasks configuration info for main and init functions */
    ret_val = stack_init_comp_info();
    if( ret_val == KAL_FALSE )
    {
        system_print(
            "Warning: stack_init() Error in stack_init_task_config_info.\n" );
        return KAL_FALSE;
    }

#ifdef __MTK_TARGET__
    tmd_hisr_ptr = (kal_internal_hisrid) kal_init_hisr( TIMER_HISR );
#if defined(DEBUG_KAL)
    TMD_HISR_Ptr = (TC_HCB *) (&(tmd_hisr_ptr->hisr_id));
#else
    TMD_HISR_Ptr = (TC_HCB *) (tmd_hisr_ptr);
#endif /* DEBUG_KAL */
    {
        DCL_HANDLE rtc_handler;
        RTC_CTRL_GET_TIME_T rtc_time;
        DCL_STATUS_T sts;
        rtc_handler = DclRTC_Open( DCL_RTC,FLAGS_NONE );
        sts = DclRTC_Control( rtc_handler, RTC_CMD_GET_TIME,
                              (DCL_CTRL_DATA_T *) &rtc_time );

        if( sts == STATUS_OK )
        {
            seed = ((rtc_time.u1Day + rtc_time.u1Hour + rtc_time.u1Min +
                     rtc_time.u1Mon + rtc_time.u1Sec + rtc_time.u1WDay +
                     rtc_time.u1Year) << 16) | nvram_get_imei();
        }
        else
        {
            seed = INT_GetCurrentTime() | nvram_get_imei();
        }
    }
#else  /* __MTK_TARGET__ not defined */
    tmd_hisr_ptr = (kal_internal_hisrid ) kal_init_hisr( TIMER_HISR );
#if defined(DEBUG_KAL)
    g_osc_Timer_HISR = (osc_struct_thread *) (&(tmd_hisr_ptr->hisr_id));
#else
    g_osc_Timer_HISR = (osc_struct_thread *) (tmd_hisr_ptr);
#endif /* DEBUG_KAL */

    kal_get_time( &ticks );

    second = ticks / KAL_TICKS_1_SEC;
    milli_sec = (ticks % KAL_TICKS_1_SEC) * 10 / KAL_TICKS_10_MSEC;
    seed = second * 1000 + milli_sec;

#endif /* __MTK_TARGET__ */

    /* set the seed for rand function */
    srand( seed );

    /* register test cases into KTEST */
    ktest_testcase_register();

    /* copy information from ktest_mod_task_g to mod_task_g */
    kal_mem_cpy( mod_task_g, ktest_mod_task_g, sizeof(ktest_mod_task_g) );

    /* initialize environment for KTEST */
    ktest_init_env();

    /* if test case label isn't valid, then we need to initialize it */
    if( !ktest_init_tc_label() )
    {
        /* if we can't initialize the test case label, then KTEST can not run.
         * So we need to add error handler here and terminate KTEST */
    }

    /* come into the main control flow of KTEST */
    ktest_engine();

    /* In oscar, the init process is in MtkWinMainStart This is for not start
     * MoDIS UI */
#ifdef KAL_ON_OSCAR
    ktest_schedule();
#endif /* KAL_ON_OSCAR */

    return KAL_TRUE;
}

#endif /*__KTEST__*/
