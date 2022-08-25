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
 *     ktest_tc_task.c
 *
 * Project:
 * --------
 *     Maui_Software
 *
 * Description:
 * ------------
 *     The file implements MediaTek KAL (Kernel Abstraction Layer) auto test
 *     task functions.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/* this file is valid only when __KTEST__ has been defined */
#ifdef __KTEST__
 
#include "ktest_common.h"
#include "kal_release.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "hisr_config.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "stack_types.h"
#include "task_config.h"
#include "lcd_ip_cqueue.h"
#include "intrCtrl.h"
#include "custom_config.h"

/******************************************************************************
 * external KAL APIs used in this file.
 *****************************************************************************/
extern kal_uint32 kal_get_mytask_priority( void );
extern void *kal_create_thread_stack( kal_uint32 stack_size,
                                      kal_bool in_intsram,
                                      kal_uint32 *real_size );
extern kal_taskid kal_create_task( kal_char* task_name, kal_uint8 priority,
                                   void *stack_addr, kal_uint32 stack_size,
                                   kal_task_func_ptr entry_func,
                                   void *entry_param, kal_uint8 options );

/******************************************************************************
 * 4 kind of priority for tasks that will be used in test cases in task module.
 *****************************************************************************/
#define KTEST_TASK_LOW_PRIORITY_OFFSET  4
#define KTEST_TASK_MID1_PRIORITY_OFFSET 3
#define KTEST_TASK_MID2_PRIORITY_OFFSET 2
#define KTEST_TASK_HIGH_PRIORITY_OFFSET 1

#define GPT_TICKSPERSEC 100
typedef void (*gpt_timer_handler)( void * );

/******************************************************************************
 * task id or hisr id.
 *****************************************************************************/
static kal_hisrid g_ktest_task_test_hisr = NULL;
static kal_taskid g_ktest_task_test_task1 = NULL;
static kal_taskid g_ktest_task_test_task2 = NULL;

/******************************************************************************
 * each test case should return a value of kal_int32 type. but in most test
 * cases, we only call ktest_report_reset or ktest_report_reset3 at the end, and
 * these two APIs return nothing.
 * for this reason, some compiler will give errors or warnings. in order to
 * resolve this problem, we define the macro: MY_REPORT_RETURN3, it call
 * ktest_report_reset3 firstly, then return a value of kal_int32 type.
 *****************************************************************************/
#define MY_REPORT_RETURN3( code, tcname, fmt ) \
    ktest_report_reset3( code, tcname, fmt );\
    return code;

/******************************************************************************
 * main function of a LISR, and it will activate a hisr in it.
 *****************************************************************************/
static void ktest_task_test_lisr( void )
{
    kal_activate_hisr( g_ktest_task_test_hisr );
    ktest_deactive_sw_handler();
}

/******************************************************************************
 * main function of a HISR, and it will report PASS in it.
 *****************************************************************************/
static void ktest_task_test_hisr( void )
{
    ktest_report_reset( KTEST_PASS );
}

/******************************************************************************
 * main function of a task, and it will report PASS in it.
 *****************************************************************************/
static void ktest_task_test_main( void *param_ptr )
{
    ktest_report_reset( KTEST_PASS );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_task1
 * Functionality:
 *     test basic functionality of kal_create_task with stack_size as 0.
 * Results:
 *     as we expected, stack_size 0 will cause kal_create_task generate a fatal
 *     error: KAL_ERROR_TASKMNGT_CREATE_FAILED.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_task1( kal_uint32 argc, void *argv )
{
    kal_taskid test_task;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "kal_create_task check stack_size in pre-schedule stage";
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_TASKMNGT_CREATE_FAILED;

#if defined( DEBUG_KAL )
    /* test kal_create_task with parameter "stack_size" as 0. */
    test_task = kal_create_task( "TESTTASK", 100, NULL, 0,
                                 (kal_task_func_ptr) ktest_task_test_main,
                                 NULL, KAL_FALSE );

    /* as expected, a fatal error: KAL_ERROR_TASKMNGT_CREATE_FAILED will occur,
     * so the statement below will not be executed. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
#else
    /* if DEBUG_KAL is not defined, then pass this test case. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID,
                       "DEBUG_KAL not defined, by pass." );
#endif /* DEBUG_KAL */
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_task2
 * Functionality:
 *     test kal_create_task with parameter entry_func as null.
 * Results:
 *     as expected, entry_func is null will cause a fatal error occurs.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_task2( kal_uint32 argc, void *argv )
{
    kal_taskid test_task;
    void *stack_addr;
    kal_uint32 real_stack_size;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = " kal_create_task check entry_func in pre-schedule stage";
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_TASKMNGT_CREATE_FAILED;

#if defined( DEBUG_KAL )
    stack_addr = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                   &real_stack_size );
    /* as expected, entry_func is 0 will cause a fatal error occurs here.
     * and we will report PASS in the fatal error handler. */
    test_task = kal_create_task( "TESTTASK", 100, stack_addr, real_stack_size,
                                 NULL, NULL, KAL_FALSE );

    /* the statement below should be unreachable. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
#else
    /* if DEBUG_KAL is not defined, then pass this test case. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID,
                       "DEBUG_KAL not defined, by pass." );
#endif /* DEBUG_KAL */
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_task3
 * Functionality:
 *     test kal_create_task will all parameters are valid.
 * Results:
 *     if success, report PASS in the created task's entry function.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_task3( kal_uint32 argc, void *argv )
{
    kal_taskid test_task;
    void *stack_addr;
    kal_uint32 real_stack_size;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test task created in pre-schedule runs";

    stack_addr = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                   &real_stack_size );

    /* test kal_create_task with all parameters are valid.
     * if success, when the new task runs, it will report PASS in its entry
     * function: ktest_task_test_main. */
    test_task = kal_create_task( "TESTTASK",
                                 TASK_PRIORITY_KTEST - KTEST_TASK_LOW_PRIORITY_OFFSET,
                                 stack_addr, real_stack_size,
                                 (kal_task_func_ptr) ktest_task_test_main,
                                 NULL, KAL_FALSE );

    /* if not success, report FAIL. */
    if( test_task == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_task() return NULL" );
    }

    /* in order to test whether the new created task runs, we start a timer to
     * check it.
     * if the new task runs, it will report PASS in its entry function.
     * else, we will report FAIL in the timer handler. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,     /* 16 s*/
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* let the new created task run. */
    ktest_schedule();

    /* as we expected, this case will report PASS in the new task's entry
     * function, and the statement below will be unreachable. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_hisr1
 * Functionality:
 *     test basic functionality of kal_create_hisr with stack_size as 0.
 * Results:
 *     as expected, stack_size is 0 will cause a fatal error occurs.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_hisr1(kal_uint32 argc, void *argv)
{
    kal_hisrid test_hisr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "create hisr check stack_size";
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_HISRMNGT_CREATE_FAILED;

#if defined( DEBUG_KAL )
    /* test kal_create_hisr with stack_size as 0. and this will cause a fatal
     * error occurs. */
    test_hisr = kal_create_hisr( "TESTHISR", 1, 0,
                                 (kal_hisr_func_ptr) ktest_task_test_hisr,
                                 NULL );

    /* if no fatal error occurs, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
#else
    /* if DEBUG_KAL is not defined, then pass this test case. */
    ktest_report( KTEST_PASS, KTEST_TCID,
                  "DEBUG_KAL not defined, by pass." );
#endif  /* DEBUG_KAL */
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_hisr2
 * Functionality:
 *     test basic functionality of kal_create_hisr with entry_func as null.
 * Results:
 *     as expected, entry_func is null will cause a fatal error occurs.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_hisr2( kal_uint32 argc, void *argv )
{
    kal_hisrid test_hisr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_HISRMNGT_CREATE_FAILED;
    KTEST_BRIEF = "create hisr checks entry func";

#if defined( DEBUG_KAL )
    /* test kal_create_hisr with entry_func as null. and this will cause a fatal
     * error occurs. if so, we will report PASS in the fatal error handler. */
    test_hisr = kal_create_hisr( "TESTHISR", 1, 1024, NULL, NULL );

    /* a fatal error is expected above, and the statement below should be
     * unreachable. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
#else
    /* if DEBUG_KAL is not defined, then pass this test case. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID,
                       "DEBUG_KAL not defined, by pass." );
#endif  /* DEBUG_KAL */
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_hisr3
 * Functionality:
 *     test kal_create_hisr with priority larger than 2.
 * Results:
 *     as expected, priority larger than 2 will cause a fatal error occurs.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_hisr3( kal_uint32 argc, void *argv )
{
    kal_hisrid test_hisr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_HISRMNGT_CREATE_FAILED;
    KTEST_BRIEF = "create hisr check priority";

#if defined( DEBUG_KAL )
    /* test kal_create_hisr with priority larger than 2.
     * a fatal error is expected here. */
    test_hisr = kal_create_hisr( "TESTHISR", 3, 1024,
                                 (kal_hisr_func_ptr) ktest_task_test_hisr,
                                 NULL );

    /* if no fatal error occurs, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
#else
    /* if DEBUG_KAL is not defined, then pass this test case */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID,
                       "DEBUG_KAL not defined, by pass." );
#endif  /* DEBUG_KAL */
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_hisr4
 * Functionality:
 *     test basic functionality of kal_create_hisr. that is, create more that
 *     KAL_MAX_NUM_HISRS HISRs.
 * Results:
 *     as expected, a fatal error will occur when HISRs created more than
 *     KAL_MAX_NUM_HISRS.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_hisr4( kal_uint32 argc, void *argv )
{
    kal_hisrid test_hisr;
    kal_uint32 i = 0;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "check number of hisr created";
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_HISRMNGT_CREATE_TOO_MANY_HISR;

#if defined( DEBUG_KAL )
    /* create HISR for more than KAL_MAX_NUM_HISRS times. as we expected, a
     * fatal error will occur here. */
    while( i < KAL_MAX_NUM_HISRS + 1 )
    {
        test_hisr = kal_create_hisr( "TESTHISR", 1, 256,
                                     (kal_hisr_func_ptr) ktest_task_test_hisr,
                                     NULL );
        if( test_hisr == NULL )
        {
            MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                               "kal_create_hisr() return NULL" );
        }

        i++;
    }

    /* if no fatal error occurs, report FAIL. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
#else
    /* if DEBUG_KAL is not defined, then pass this test case. */
    ktest_report( KTEST_PASS, KTEST_TCID, "DEBUG_KAL not defined, by pass." );
#endif /*debug_task*/
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_hisr5
 * Functionality:
 *     test basic functionality of kal_create_hisr.
 * Results:
 *     if success, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_hisr5( kal_uint32 argc, void *argv )
{
    kal_hisrid test_hisr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;
    KTEST_BRIEF = "Test kal_create_hisr success in pre-schedule stage";

    /* create a HISR with all parameters are valid. */
    test_hisr = kal_create_hisr( "TESTHISR", 1, 1024,
                                 (kal_hisr_func_ptr) ktest_task_test_hisr,
                                 NULL );
    if( test_hisr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_hisr() return NULL" );
    }

    /* create HISR successfully, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_task4
 * Functionality:
 *     test kal_create_task after KTEST scheduling.
 * Results:
 *     if create task successfully, report PASS.
 *     else, report FAIL.
 * Note:
 *     this test case will run after KTEST scheduling.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_task4( kal_uint32 argc, void *argv )
{
    kal_taskid test_task;
    void *stack_addr;
    kal_uint32 real_stack_size;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test kal_create_task success in post-schedule stage";

    /* create a new task with all parameters are valid. */
    stack_addr = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                   &real_stack_size );
    test_task = kal_create_task( "TESTTASK", 100, stack_addr, real_stack_size,
                                 (kal_task_func_ptr) ktest_task_test_main,
                                 NULL, KAL_FALSE );

    /* if not success, report FAIL. */
    if( test_task == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_task() return NULL" );
    }

    /* the task has been created successfully, then we need to let it run, if
     * it runs successfully, then it will report PASS in its entry function.
     * otherwise, when the timer expires, it will report FAIL in the timer
     * handler. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* suspend self to let the new task run. */
    kal_sleep_task( KAL_SUSPEND );

    /* as we expected, the new task will report PASS in its entry function, and
     * the statement below will be unreachable. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_create_hisr6
 * Functionality:
 *     test basic functionality of kal_create_hisr after KTEST scheduling.
 * Results:
 *     if create HISR successfully, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_create_hisr6( kal_uint32 argc, void *argv )
{
    kal_hisrid test_hisr;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;
    KTEST_BRIEF = "Test kal_create_hisr success in post-schedule stage";

    /* create a HISR with all parameters are valid. and it will success as we
     * expected. */
    test_hisr = kal_create_hisr( "TESTHISR", 1, 1024,
                                 (kal_hisr_func_ptr) ktest_task_test_hisr,
                                 NULL );

    /* if not success, report FAIL. */
    if( test_hisr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_hisr() return NULL" );
    }

    /* we have created a HISR successfully, report PASS. */
    MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_activate_hisr
 * Functionality:
 *     create a HISR, then activate it in a LISR. test whether this can success.
 * Results:
 *     if activate the HISR successfully, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_activate_hisr( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;
    KTEST_BRIEF = "Test activate an HISR in a LISR";

    /* create a HISR. if not success, report FAIL. */
    g_ktest_task_test_hisr =
        kal_create_hisr( "TESTHISR", 1, 1024,
                         (kal_hisr_func_ptr) ktest_task_test_hisr, NULL );
    if( g_ktest_task_test_hisr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_hisr() return NULL" );
    }

    /* activate the new HISR in a LISR. */
    ktest_sw_intr_handler( ktest_task_test_lisr );
    ktest_active_sw_handler();

    /* as we expected, the HISR will be activated successfully. so it will
     * report PASS in its entry function. otherwise, the timer handler will
     * report FAIL when the timer expires. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* suspend self to let the HISR run. */
    kal_sleep_task( KAL_SUSPEND );

    /* as we expected, the HISR will be activated successfully, so the statement
     * below will have no change to run. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_if_hisr1
 * Functionality:
 *     test kal_if_hisr in a task.
 * Results:
 *     since this test case runs as a task, so kal_if_hisr will return false.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_if_hisr1( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;
    KTEST_BRIEF = "kal_if_hisr in task";

    /* since this test case runs as a task, so kal_if_hisr will return false. */
    if( kal_if_hisr() == KAL_TRUE )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_if_hisr() return wrong value" );
    }
    else
    {
        MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_test_if_hisr
 * Functionality:
 *     this function is used as the entry function of a HISR, so kal_if_hisr
 *     will return true as we expected.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 * Note:
 *     this function is a HISR's entry function, not a test case. and it will
 *     be used in ktest_task_kal_if_hisr2.
 *****************************************************************************/
static void ktest_task_test_if_hisr( void )
{
    /* since this is a HISR's entry function, so kal_if_hisr will return true
     * as we expected. */
    if( kal_if_hisr() == KAL_TRUE )
    {
        ktest_report_reset3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                             "kal_if_hisr() returns wrong value" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_if_hisr2
 * Functionality:
 *     test kal_if_hisr in a HISR.
 * Results:
 *     since we test kal_if_hisr in a HISR, so it will return true as expected.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_if_hisr2( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = 0;
    KTEST_BRIEF = "kal_if_hisr in hisr";

    /* create a HISR, and we will test kal_if_hisr in its entry function. */
    g_ktest_task_test_hisr =
        kal_create_hisr( "TESTHISR", 1, 1024,
                         (kal_hisr_func_ptr)ktest_task_test_if_hisr, NULL );
    if( g_ktest_task_test_hisr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_hisr() return NULL" );
    }

    /* activate the HISR in a LISR. */
    ktest_sw_intr_handler( ktest_task_test_lisr );
    ktest_active_sw_handler();

    /* as we expected, when the HISR runs, it will report PASS in its entry
     * function. otherwise, the timer handler will report FAIL in its timer
     * handler. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* suspend self to let the HISR run. */
    kal_sleep_task( KAL_SUSPEND );

    /* the statement below should not be executed. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_get_my_task_index
 * Functionality:
 *     test basic functionality of kal_get_my_task_index.
 * Results:
 *     if it returns a correct task index, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_get_my_task_index( kal_uint32 argc, void *argv )
{
    kal_uint32 self_index;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Get task indx in KTEST";

    /* get the index of current task.
     * as we expected, it should be INDX_KTEST. */
    kal_get_my_task_index( &self_index );
    if( self_index == INDX_KTEST )
    {
        MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "ktest_task_kal_get_my_task_index failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_get_mytask_priority1
 * Functionality:
 *     test basic functionality of kal_get_mytask_priority.
 * Results:
 *     if it returns the correct priority, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_get_mytask_priority1( kal_uint32 argc, void *argv )
{
    kal_uint32 self_priority;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Get KTEST task priority";

    /* test kal_get_mytask_priority. */
    self_priority = kal_get_mytask_priority();
    if( self_priority == TASK_PRIORITY_KTEST )
    {
        MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "ktest_task_kal_get_mytask_priority1 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_test_get_mytask_priority
 * Functionality:
 *     this is a HISR's entry function, and we will test kal_get_mytask_priority
 *     in this HSIR.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 * Note:
 *     this function is not a test case, it will be used in
 *     ktest_task_kal_get_mytask_priority2.
 *****************************************************************************/
static void ktest_task_test_get_mytask_priority( void )
{
    kal_uint32 self_priority;

    /* in that test case: ktest_task_kal_get_mytask_priority2, the HISR's
     * priority is 1. */
    self_priority = kal_get_mytask_priority();
    if( self_priority == 1 )
    {
        ktest_report_reset3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                             "ktest_task_kal_get_mytask_priority2 failed" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_get_mytask_priority2
 * Functionality:
 *     test basic functionality of kal_get_mytask_priority in a HISR.
 * Results:
 *     if kal_get_mytask_priority returns the correct priority, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_get_mytask_priority2( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Get hisr priority";

    /* create a HISR, and we will test kal_get_mytask_priority in its entry
     * function: ktest_task_test_get_mytask_priority. */
    g_ktest_task_test_hisr =
        kal_create_hisr( "TESTHISR", 1, 1024,
                         (kal_hisr_func_ptr)ktest_task_test_get_mytask_priority,
                         NULL );
    if( g_ktest_task_test_hisr == NULL )
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "kal_create_hisr() return NULL" );
    }

    /* activate the HISR. */
    ktest_sw_intr_handler( ktest_task_test_lisr );
    ktest_active_sw_handler();

    /* as we expected, this test case will report PASS in the HISR's entry
     * function. otherwise, it will report FAIL in the timer handler when the
     * timer expires. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* suspend self and let the HISR run. */
    kal_sleep_task( KAL_SUSPEND );

    /* if no error occurs, this test case will report PASS in the HISR's entry
     * function, and has no chance to run the statement below. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_get_task_self_id
 * Functionality:
 *     test basic functionality of kal_get_task_self_id.
 * Results:
 *     if kal_get_task_self_id returns the correct task id, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_get_task_self_id( kal_uint32 argc, void *argv )
{
    kal_taskid self_id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Get KTEST task id";

    /* get current task's id, then check whether it is correct. */
    self_id = kal_get_task_self_id();
    if( self_id == task_info_g[INDX_KTEST].task_id )
    {
        MY_REPORT_RETURN3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID,
                           "ktest_task_kal_get_task_self_id failed" );
    }
}

/******************************************************************************
 * these two variables will be used to control the running of two tasks:
 *     ktest_task_test_change_priority1_task1
 *     ktest_task_test_change_priority1_task2
 *****************************************************************************/
volatile static kal_bool g_ktest_task_change_priority_flag1 = KAL_FALSE;
volatile static kal_bool g_ktest_task_change_priority_flag2 = KAL_FALSE;

/******************************************************************************
 * Name:
 *     ktest_task_test_change_priority1_task1
 * Functionality:
 *     the entry function of task1 that will be used in the test case:
 *     ktest_task_kal_change_priority1.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this function is the entry function of g_ktest_task_test_task1, note that
 *     it is not a test case.
 *****************************************************************************/
static void ktest_task_test_change_priority1_task1( void *param_ptr )
{
    /* wait until g_ktest_task_test_task2 starts to run. */
	while( g_ktest_task_change_priority_flag1 == KAL_FALSE )
	{
		kal_sleep_task( 10 );
	}

    /* modify g_ktest_task_test_task2's control flag. */
	g_ktest_task_change_priority_flag2 = KAL_TRUE;

    /* change task2's priority, after that, task2's priority will be higher
     * than current task's. */
    kal_change_priority( g_ktest_task_test_task2,
                         TASK_PRIORITY_KTEST + KTEST_TASK_HIGH_PRIORITY_OFFSET );

    /* as we expected, task2's has a higher priority after the step above. so
     * task2 will have the chance to run, and the statement below will not be
     * executed. */
    ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                         "low priority task is not preempted" );
}

/******************************************************************************
 * Name:
 *     ktest_task_test_change_priority1_task2
 * Functionality:
 *     the entry function of task2 that will be used in the test case:
 *     ktest_task_kal_change_priority1.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this function is the entry function of g_ktest_task_test_task2, note that
 *     it is not a test case.
 *****************************************************************************/
static void ktest_task_test_change_priority1_task2( void *param_ptr )
{
    /* change the control flag of g_ktest_task_test_task1.
     * since g_ktest_task_test_task1 has a higher priority now, so task1 will
     * will have chance to run. */
	while( g_ktest_task_change_priority_flag2 == KAL_FALSE )
	{
		g_ktest_task_change_priority_flag1 = KAL_TRUE;
	}

    /* after g_ktest_task_test_task1 has changed task2's priority, the statement
     * below will have chance to run. it test whether kal_get_mytask_priority
     * will return the correct priority of current task. */
    if( kal_get_mytask_priority()
        == TASK_PRIORITY_KTEST + KTEST_TASK_HIGH_PRIORITY_OFFSET )
    {
        ktest_report_reset3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                             "priority is not changed correctly" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_change_priority1
 * Functionality:
 *     create task1 with higher priority and task2 with lower priority, then
 *     change task2's priority to be higher than task1's. after this, we try
 *     to get task2's priority in taks2's entry function by kal_get_priority,
 *     and test whether it returns the correct value.
 * Results:
 *     if kal_get_priority returns the correct priority of task2, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_change_priority1( kal_uint32 argc, void *argv )
{
    void *stack_addr1;
    kal_uint32 real_stack_size1;
    void *stack_addr2;
    kal_uint32 real_stack_size2;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "changed task's priority and preempts CPU to higher task";

    /* create task1 with a higher priority.
     * that is, TASK_PRIORITY_KTEST + KTEST_TASK_MID2_PRIORITY_OFFSET. */
    stack_addr1 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size1 );
    g_ktest_task_test_task1 =
        kal_create_task( "changer",
                         TASK_PRIORITY_KTEST + KTEST_TASK_MID2_PRIORITY_OFFSET,
                         stack_addr1, real_stack_size1,
                         (kal_task_func_ptr) ktest_task_test_change_priority1_task1,
                         NULL, KAL_FALSE );

    /* create task2 with a lower priority.
     * that is, TASK_PRIORITY_KTEST + KTEST_TASK_LOW_PRIORITY_OFFSET. */
    stack_addr2 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size2 );
    g_ktest_task_test_task2 =
        kal_create_task( "changer",
                         TASK_PRIORITY_KTEST + KTEST_TASK_LOW_PRIORITY_OFFSET,
                         stack_addr2, real_stack_size2,
                         (kal_task_func_ptr) ktest_task_test_change_priority1_task2,
                         NULL, KAL_FALSE );

    /* suspend self and let task1 and task2 run. */
    kal_sleep_task( KAL_SUSPEND );

    /* as we expected, this test case will report PASS in task2's entry function
     * , and the statement below should be unreachable. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * a control flag for ktest_task_test_change_priority2_task1 and
 *                    ktest_task_test_change_priority2_task2.
 *****************************************************************************/
static kal_bool g_ktest_task_change_priority = KAL_FALSE;

/******************************************************************************
 * Name:
 *     ktest_task_test_change_priority2_task1
 * Functionality:
 *     the entry function of g_ktest_task_test_task1 that will be used in the
 *     test case: ktest_task_kal_change_priority2.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this function is the entry function of g_ktest_task_test_task1, note that
 *     it is not a test case.
 *****************************************************************************/
static void ktest_task_test_change_priority2_task1( void *param_ptr )
{
    /* change g_ktest_task_test_task2's priority to be a higher one.
     * but we should notice that the new priority of task2 is still lower than
     * that of task1.
     * since task2's priority is not higher that current task's, so no
     * scheduling will occur here. */
    kal_change_priority( g_ktest_task_test_task2,
                         TASK_PRIORITY_KTEST + KTEST_TASK_MID1_PRIORITY_OFFSET );

    /* modify the control flag. */
    g_ktest_task_change_priority = KAL_TRUE;

    /* suspend self to let task2 run. */
    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * Name:
 *     ktest_task_test_change_priority2_task2
 * Functionality:
 *     the entry function of g_ktest_task_test_task2 that will be used in the
 *     test case: ktest_task_kal_change_priority2.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this is the entry function of g_ktest_task_test_task2, note that it is
 *     not a test case.
 *****************************************************************************/
static void ktest_task_test_change_priority2_task2( void *param_ptr )
{
    /* if the statement below runs, that means scheduling occurs after task1
     * changed task2's priority. but since task2's new priority is still lower
     * that task1's, so this should not happen. otherwise, report FAIL. */
    if( g_ktest_task_change_priority == KAL_FALSE )
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                             "high priority task is preempted" );
    }

    /* get self priority and test whether it is the new priority. */
    if( kal_get_mytask_priority()
        == TASK_PRIORITY_KTEST + KTEST_TASK_MID1_PRIORITY_OFFSET )
    {
        ktest_report_reset3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                             "priority is not changed correctly" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_change_priority2
 * Functionality:
 *     create task1 with a higher priority and task2 with a lower one.
 *     then change task2's priority in task1's entry function, we should notice
 *     that task2's new priority is still lower than task1's.
 * Results:
 *     if the scheduling is correct and kal_get_priority returns the correct
 *     value, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_change_priority2( kal_uint32 argc, void *argv )
{
    void *stack_addr1;
    kal_uint32 real_stack_size1;
    void *stack_addr2;
    kal_uint32 real_stack_size2;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "changed task's priority and not preempts CPU to higher task";

    /* create task1 with a higher priority.
     * that is, TASK_PRIORITY_KTEST + KTEST_TASK_MID2_PRIORITY_OFFSET. */
    stack_addr1 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size1 );
    g_ktest_task_test_task1 =
        kal_create_task( "changer",
                         TASK_PRIORITY_KTEST + KTEST_TASK_MID2_PRIORITY_OFFSET,
                         stack_addr1, real_stack_size1,
                         (kal_task_func_ptr) ktest_task_test_change_priority2_task1,
                         NULL, KAL_FALSE );

    /* create task2 with a lower priority.
     * that is, TASK_PRIORITY_KTEST + KTEST_TASK_LOW_PRIORITY_OFFSET. */
    stack_addr2 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size2 );
    g_ktest_task_test_task2 =
        kal_create_task( "bechanged",
                         TASK_PRIORITY_KTEST + KTEST_TASK_LOW_PRIORITY_OFFSET,
                         stack_addr2, real_stack_size2,
                         (kal_task_func_ptr) ktest_task_test_change_priority2_task2,
                         NULL, KAL_FALSE );

    /* suspend self to let task1 and task2 run. since task1 has a higher
     * priority, so it will run earlier than task2. */
    kal_sleep_task( KAL_SUSPEND );

    /* as we expected, this test case will report the result in task2's entry
     * function. so the statement below should not run. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * a control flag of ktest_task_test_sleep_task1 and
 *                   ktest_task_test_sleep_task2.
 *****************************************************************************/
static kal_bool g_ktest_task_sleep_task = KAL_FALSE;

/******************************************************************************
 * Name:
 *     ktest_task_test_sleep_task1
 * Functionality:
 *     the entry function of g_ktest_task_test_task1 that will be used in the
 *     test case: ktest_task_kal_sleep_task.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this is the entry function of g_ktest_task_test_task1, note that it is
 *     not a test caes.
 *****************************************************************************/
static void ktest_task_test_sleep_task1( void *param_ptr )
{
    /* sleep self for 100 ticks. */
    kal_sleep_task( 100 );

    /* the statement below will run after task2 suspend itself.
     * note that task2 will change g_ktest_task_sleep_task to KAL_TRUE before
     * it suspend it self, so PASS will be reported here. */
    if( g_ktest_task_sleep_task == KAL_TRUE )
    {
        ktest_report_reset3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID, "task is not sleep" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_test_sleep_task2
 * Functionality:
 *     the entry function of g_ktest_task_test_task2 that will be used in the
 *     test case: ktest_task_kal_sleep_task.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this is the entry function of g_ktest_task_test_task2, notice that it is
 *     not a test case.
 *****************************************************************************/
static void ktest_task_test_sleep_task2( void *param_ptr )
{
    /* this task will run after task1 sleeps. firstly, we change the control
     * flag to KAL_TRUE. */
    g_ktest_task_sleep_task = KAL_TRUE;

    /* suspend self to let task1 run. */
    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * Name:
 *     ktest_task_kal_sleep_task
 * Functionality:
 *     create task1 with a higher priority and task2 with a lower one.
 *     then test basic functionality of kal_sleep_task in the two tasks.
 * Results:
 *     if no error occurs, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_kal_sleep_task( kal_uint32 argc, void *argv )
{
    void *stack_addr1;
    kal_uint32 real_stack_size1;
    void *stack_addr2;
    kal_uint32 real_stack_size2;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Task sleeps and wakes up";

    /* create task1 with a higher priority,
     * that is, TASK_PRIORITY_KTEST + KTEST_TASK_MID2_PRIORITY_OFFSET. */
    stack_addr1 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size1 );
    g_ktest_task_test_task1 =
        kal_create_task( "sleeper",
                         TASK_PRIORITY_KTEST + KTEST_TASK_MID2_PRIORITY_OFFSET,
                         stack_addr1, real_stack_size1,
                         (kal_task_func_ptr) ktest_task_test_sleep_task1, NULL,
                         KAL_FALSE );

    /* create task2 with a lower priority,
     * that is, TASK_PRIORITY_KTEST + KTEST_TASK_LOW_PRIORITY_OFFSET. */
    stack_addr2 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size2 );
    g_ktest_task_test_task2 =
        kal_create_task( "viewer",
                         TASK_PRIORITY_KTEST + KTEST_TASK_LOW_PRIORITY_OFFSET,
                         stack_addr2, real_stack_size2,
                         (kal_task_func_ptr) ktest_task_test_sleep_task2, NULL,
                         KAL_FALSE );

    /* as we expected, this test case will report the result in task1.
     * we set this timer to check whether task1 and task2 run as we expected. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* suspend self to let task1 and task2 run. note that task1 has a higher
     * priority, so it will run earlier than task2. */
    kal_sleep_task( KAL_SUSPEND );

    /* as mentioned above, this test case will report the result in task1, so
     * the statment below should have no chance to be executed. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * Name:
 *     ktest_kal_sleep_task_init
 * Functionality:
 *     test basic functionality of kal_sleep_task at pre-schedule stage (that
 *     is, system initialization stage).
 * Results:
 *     as we know, kal_sleep_task will do nothing when it's in system
 *     initialization stage, so the task won't be suspended by kal_sleep_task.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_kal_sleep_task_init( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test kal_sleep_task at init stage";

    /* try to sleep current task, but it will do nothing in system
     * initialization stage. */
    kal_sleep_task( KAL_SUSPEND );

    /* set a timer to check whether the current task has been suspended. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* since kal_sleep_task do nothing in system initialization stage, so we
     * can come here because the current task has not been suspended at all. */
    ktest_report( KTEST_PASS, KTEST_TCID, "" );
    ktest_reset_target();
}

/******************************************************************************
 * an external variable which means exception stage when it is true.
 * it will be used in the test case: ktest_kal_sleep_task_exception.
 *****************************************************************************/
extern kal_uint32 INT_Exception_Enter;

/******************************************************************************
 * Name:
 *     ktest_kal_sleep_task_exception
 * Functionality:
 *     test basic functionality of kal_sleep_task at exception stage.
 * Results:
 *     as we know, kal_sleep_task do nothing at exception stage.
 *     if so, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_kal_sleep_task_exception( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test kal_sleep_task at exception stage";

    /* enter exception stage. */
    INT_Exception_Enter = 1;

    /* try to suspend current task. but we should notice that kal_sleep_task
     * will do nothing but return directly at exception stage. so current task
     * won't be suspended at all. */
    kal_sleep_task( KAL_SUSPEND );

    /* start a timer to check whether current task has been suspended. */
    ktest_start_gpt_timer( GPT_TICKSPERSEC * 16,
                           (gpt_timer_handler) ktest_report_reset,
                           (void *) KTEST_FAIL );

    /* since current task has not been suspended at all, so the statement below
     * can run normally. */
    ktest_report( KTEST_PASS, KTEST_TCID, "" );
    ktest_reset_target();
}

/******************************************************************************
 * Name:
 *     ktest_task_test_change_priority_by_module_ID1_task1
 * Functionality:
 *     the entry function of task: INDX_KTEST1.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this is not a test case but the entry function of task INDX_KTEST1 which
 *     will be used in ktest_task_stack_change_priority_by_module_ID1.
 *****************************************************************************/
static void ktest_task_test_change_priority_by_module_ID1_task1( void *param_ptr )
{
    /* change task INDX_KTEST2's priority by module ID. we should notice that
     * the new priority of task INDX_KTEST2 is higher than current task's. */
    stack_change_priority_by_module_ID( MOD_KTEST2_1,
                        TASK_PRIORITY_KTEST + KTEST_TASK_HIGH_PRIORITY_OFFSET );

    /* since the new priority of task INDX_KTEST2 is higher than current task's,
     * scheduling will occur after the step above. so INDX_KTEST2 will have
     * chance to run, and the statement below won't be executed at all. */
    ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                         "low priority task is not preempted" );
}

/******************************************************************************
 * Name:
 *     ktest_task_test_change_priority_by_module_ID1_task2
 * Functionality:
 *     the entry function of task INDX_KTEST2.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this is not a test case but the entry function of task INDX_KTEST2 which
 *     will be used in ktest_task_stack_change_priority_by_module_ID1.
 *****************************************************************************/
static void ktest_task_test_change_priority_by_module_ID1_task2( void *param_ptr )
{
    /* get self priority and test whether it is corret. */
    if ( kal_get_mytask_priority()
        == TASK_PRIORITY_KTEST + KTEST_TASK_HIGH_PRIORITY_OFFSET )
    {
        ktest_report_reset3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                             "priority is not changed correctly" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_stack_change_priority_by_module_ID1
 * Functionality:
 *     test basic functionality of stack_change_priority_by_module_ID.
 *     that is, create task1 with a higher priority and task2 with a lower one.
 *              then change task2's priority in task1's entry function.
 *              finally, test whether tasks'2 new priority is correct.
 * Results:
 *     if the new priority is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_stack_change_priority_by_module_ID1( kal_uint32 argc,
                                                          void *argv )
{
    void *stack_addr1;
    kal_uint32 real_stack_size1;
    void *stack_addr2;
    kal_uint32 real_stack_size2;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "changed task's priority and preempts CPU to higher task";

    /* create task1 with a higher priority. */
    stack_addr1 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size1 );
    task_info_g[INDX_KTEST1].task_id =
        kal_create_task( "changer",
                         TASK_PRIORITY_KTEST + KTEST_TASK_MID2_PRIORITY_OFFSET,
                         stack_addr1, real_stack_size1,
                         (kal_task_func_ptr) ktest_task_test_change_priority_by_module_ID1_task1,
                         NULL, KAL_FALSE );

    /* create task2 with a lower priority. */
    stack_addr2 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size2 );
    task_info_g[INDX_KTEST2].task_id =
        kal_create_task( "bechanged",
                         TASK_PRIORITY_KTEST + KTEST_TASK_LOW_PRIORITY_OFFSET,
                         stack_addr2, real_stack_size2,
                         (kal_task_func_ptr) ktest_task_test_change_priority_by_module_ID1_task2,
                         NULL, KAL_FALSE );

    /* suspend self to let task1 and task2 run. since task1's priority is higher
     * than that of task2's, so task1 will have the chance to run firstly. */
    kal_sleep_task( KAL_SUSPEND );

    /* as we expected, this test case will report the result in task2's entry
     * function, so the statement below won't have chance to run. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * a control flag for ktest_task_test_change_priority_by_module_ID2_task1 and
 *                    ktest_task_test_change_priority_by_module_ID2_task2.
 *****************************************************************************/
static kal_bool g_ktest_task_change_priority_by_module_ID = KAL_FALSE;

/******************************************************************************
 * Name:
 *     ktest_task_test_change_priority_by_module_ID2_task1
 * Functionality:
 *     the entry function of task1 that will be used in the test case:
 *     ktest_task_stack_change_priority_by_module_ID2.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this is not a test case but the entry function of task1 that will be used
 *     in the test case: ktest_task_stack_change_priority_by_module_ID2.
 *****************************************************************************/
static void ktest_task_test_change_priority_by_module_ID2_task1( void *param_ptr )
{
    /* change task2's priority to be a higher one. but we should notice that
     * the new priority of task2 is still lower than that of task1.
     * so scheduling won't happen here.*/
    stack_change_priority_by_module_ID(
        MOD_KTEST2_1, TASK_PRIORITY_KTEST + KTEST_TASK_MID1_PRIORITY_OFFSET );

    /* change the control flag. */
    g_ktest_task_change_priority_by_module_ID = KAL_TRUE;

    /* suspend self to let task2 run. */
    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * Name:
 *     ktest_task_test_change_priority_by_module_ID2_task2
 * Functionality:
 *     the entry function of task2 that will be used in the test case:
 *     ktest_task_stack_change_priority_by_module_ID2.
 * Parameters:
 *     param_ptr: not used here.
 * Returns:
 *     void.
 * Note:
 *     this is not a test case but the entry function of task2 that will be used
 *     in the following test case.
 *****************************************************************************/
static void ktest_task_test_change_priority_by_module_ID2_task2( void *param_ptr )
{
    /* in task1, we have changed task2's priority to be a higher one. but since
     * it is still lower than task1's, so scheduling won't happen there, and the
     * control flag has been modified to KAL_TRUE now. */
    if( g_ktest_task_change_priority_by_module_ID == KAL_FALSE )
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                             "high priority task is preempted" );
    }

    /* try to get self pirority and test whether it is correct. */
    if( kal_get_mytask_priority()
        == TASK_PRIORITY_KTEST + KTEST_TASK_MID1_PRIORITY_OFFSET )
    {
        ktest_report_reset3( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report_reset3( KTEST_FAIL, KTEST_TCID,
                             "priority is not changed correctly" );
    }
}

/******************************************************************************
 * Name:
 *     ktest_task_stack_change_priority_by_module_ID2
 * Functionality:
 *     test basic functionality of stack_change_priority_by_module_ID.
 *     that is, create task1 with a higher priority and task2 with a lower one.
 *              then change task2's priority a little higher in task1's entry
 *                   function, note that it's still lower than task1's.
 *              finally, test whether the new priority is correct in task2.
 * Results:
 *     if no scheduling occurs after changing task2's priority, and task2's new
 *     priority is correct, report PASS.
 *     else, report FAIL.
 *****************************************************************************/
kal_int32 ktest_task_stack_change_priority_by_module_ID2( kal_uint32 argc,
                                                          void *argv )
{
    void *stack_addr1;
    kal_uint32 real_stack_size1;
    void *stack_addr2;
    kal_uint32 real_stack_size2;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "changed task's priority and not preempts CPU to higher task";

    /* create task1 with a higher priority. */
    stack_addr1 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size1 );
    task_info_g[INDX_KTEST1].task_id =
        kal_create_task( "changer",
                         TASK_PRIORITY_KTEST + KTEST_TASK_MID2_PRIORITY_OFFSET,
                         stack_addr1, real_stack_size1,
                         (kal_task_func_ptr) ktest_task_test_change_priority_by_module_ID2_task1,
                         NULL, KAL_FALSE );

    /* create task2 with a lower priority. */
    stack_addr2 = (void *) kal_create_thread_stack( 1024, KAL_FALSE,
                                                    &real_stack_size2 );
    task_info_g[INDX_KTEST2].task_id =
        kal_create_task( "bechanged",
                         TASK_PRIORITY_KTEST + KTEST_TASK_LOW_PRIORITY_OFFSET,
                         stack_addr2, real_stack_size2,
                         (kal_task_func_ptr) ktest_task_test_change_priority_by_module_ID2_task2,
                         NULL, KAL_FALSE );

    /* suspend self to let task1 and task2 run. since task1's priority is higher
     * than task2's, so task1 will have chance to run firstly. */
    kal_sleep_task( KAL_SUSPEND );

    /* as we expected, this test case will report the result in task2's entry
     * function. so the statement below won't be executed at all. */
    MY_REPORT_RETURN3( KTEST_FAIL, KTEST_TCID, "unreachable" );
}

/******************************************************************************
 * test case table in post-schedule stage.
 * it contains all test cases of task module in post-schedule stage.
 * note that the test cases which are wrapped by FIX_OSCAR_FAIL will only be
 * tested on target, and will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_task_tbl[] =
{
    {ktest_task_kal_create_task4, 0, NULL},
    {ktest_task_kal_create_hisr6, 0, NULL},
    {ktest_task_kal_activate_hisr, 0, NULL},
    {ktest_task_kal_if_hisr1, 0, NULL},
    {ktest_task_kal_if_hisr2, 0, NULL},
    {ktest_task_kal_get_my_task_index, 0, NULL},
    {ktest_task_kal_get_mytask_priority1, 0, NULL},
    {ktest_task_kal_get_mytask_priority2, 0, NULL},
    {ktest_task_kal_get_task_self_id, 0, NULL},
    {ktest_task_kal_change_priority1, 0, NULL},
    {ktest_task_kal_change_priority2, 0, NULL},
    {ktest_task_kal_sleep_task, 0, NULL},
    {ktest_kal_sleep_task_exception, 0, NULL},
    {ktest_task_stack_change_priority_by_module_ID1, 0, NULL},
    {ktest_task_stack_change_priority_by_module_ID2, 0, NULL},
};

/******************************************************************************
 * test case table in pre-schedule stage.
 * it contains all test cases of task module in pre-schedule stage.
 * note that the test cases which are wrapped by FIX_OSCAR_FAIL will only be
 * tested on target, and will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_task_tbl[] =
{
    {ktest_task_kal_create_task1, 0, NULL},
    {ktest_task_kal_create_task2, 0, NULL},
    {ktest_task_kal_create_task3, 0, NULL},
    {ktest_task_kal_create_hisr1, 0, NULL},
    {ktest_task_kal_create_hisr2, 0, NULL},
#ifdef FIX_OSCAR_FAIL
    /* the test case will fail on OSCAR. because kal_create_hisr on OSCAR has a
     * different mechanism to check the priority. */
    {ktest_task_kal_create_hisr3, 0, NULL},
#endif
#ifdef FIX_OSCAR_FAIL
    /* the test case will fail on OSCAR. because kal_create_hisr use a global
     * variable to record how many HISRs have been created, but on OSCAR, it
     * won't increase this variable when creating a new HISR, so when we check
     * whether there are too many HISRs have been created, it doesn't work as
     * we expect. */
    {ktest_task_kal_create_hisr4, 0, NULL},
#endif
    {ktest_task_kal_create_hisr5, 0, NULL},
    {ktest_kal_sleep_task_init, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_tc_task_num
 * Functionality:
 *     caculate there are how many test cases in post-schedule stage of task
 *     module.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of all test cases in post-schedule stage of task module.
 *****************************************************************************/
kal_uint32 ktest_tc_task_num( void )
{
	return sizeof( ktest_tc_task_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_pre_tc_task_num
 * Functionality:
 *     caculate there are how many test cases in pre-schedule stage of task
 *     module.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of all test cases in pre-schedule stage of task module.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_task_num( void )
{
	return sizeof( ktest_pre_tc_task_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_task_init
 * Functionality:
 *     the initialization function of task module.
 * Parameters:
 *     mod: module ID.
 * Returns:
 *     void.
 * Note:
 *     we will call this function in ktest_testcase_register with parameter as
 *     "MOD_TASK", in order to register task module into KTEST.
 *****************************************************************************/
void ktest_task_init( kal_uint32 mod )
{
	tc_all_tbls[mod] = ktest_tc_task_tbl;
	pre_tc_all_tbls[mod] = ktest_pre_tc_task_tbl;

	tc_modules_num[mod] = ktest_tc_task_num();
	pre_tc_modules_num[mod] = ktest_pre_tc_task_num();
}

#endif  /* __KTEST__ */
