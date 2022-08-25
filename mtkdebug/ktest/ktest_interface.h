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
 *     ktest_interface.h
 *
 * Project:
 * --------
 *     Maui_Software
 *
 * Description:
 * ------------
 *     This file expose the API or global varibles to test case files
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __KTEST_INTERFACE_H
#define __KTEST_INTERFACE_H
 
#include "kal_release.h"
#include "syscomp_config.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "task_config.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "hisr_config.h"

/******************************************************************************
 * Macros for KTEST adaptation layer
 *****************************************************************************/
#ifdef KAL_ON_OSCAR
#define KTEST_FUNCTION_NAME		__FUNCTION__
/* On Windows, createSemaphore accepts signed int as the count */
#define KTEST_MAX_SEM_CNT       0x7FFFFFFF
#define KAL_TIMER_ALLOWED_ERROR 2
#else  /* not defined KAL_ON_OSCAR */
#define KTEST_FUNCTION_NAME		__func__
#define KTEST_MAX_SEM_CNT       0xFFFFFFFF
#define KAL_TIMER_ALLOWED_ERROR 1
#endif  /* KAL_ON_OSCAR */

/******************************************************************************
 * Macros for error handling in KTEST
 *     KTEST_ASSERT_MAGIC: if we assign KTEST_ASSERT_MAGIC to KTEST_EXP_ASSERT_
 *          STR in test case, then no matter what the real assert expression is
 *          , KTEST will report this test case passed.
 *     KTEST_ASSERT_MAGIC_FAIL: if we assign KTEST_ASSERT_MAGIC_FAIL to KTEST_
 *          EXP_ASSERT_STR in test case, then no matter what the real assert
 *          expression is, KTEST will report this test case failed.
 *     KTEST_ALL_ERROR_CODE: if we assign KTEST_ALL_ERROR_CODE to KTEST_EXPECT_
 *          FATAL_ERROR in test case, then no matter what the real fatal error
 *          is, KTEST will report this test case passed.
 *****************************************************************************/
#define KTEST_ASSERT_MAGIC		"passassert"
#define KTEST_ASSERT_MAGIC_FAIL "failassert"
#define KTEST_ALL_ERROR_CODE    0x16789afe

/******************************************************************************
 * KTEST will test KAL APIs automatically.
 * It's exlusive with all tasks.
 *****************************************************************************/
#ifdef __KTEST__
#define TASK_PRIORITY_KTEST	    KAL_PRIORITY_CLASS5
#endif

/******************************************************************************
 * Simulate module id and task index mapping for ktest
 *****************************************************************************/
typedef enum
{
    MOD_KTEST_0,
    MOD_KTEST,
    MOD_KTEST1_1,
    MOD_KTEST1_2,
    MOD_KTEST2_1,
    MOD_KTEST2_2,
    MOD_KTEST3_1,
    MOD_KTEST3_2,
    MOD_KTEST4,
    MOD_KTEST5,
    MOD_KTEST6,
    MOD_KTEST7,
    KTEST_MOD_NUM,
} ktest_module_type;

typedef enum
{
    INDX_KTEST_0,
    INDX_KTEST,
    INDX_KTEST1,
    INDX_KTEST2,
    INDX_KTEST3,
    INDX_KTEST4,
    INDX_KTEST5,
    INDX_KTEST6,
    INDX_KTEST7,
} ktest_task_index;

/******************************************************************************
 * test case's result in KTEST:
 *     KTEST_PASS: the test case passes the test.
 *     KTEST_FAIL: the test case failed in the test.
 *     KTEST_DEP_FAIL: not used now.
 *****************************************************************************/
typedef enum {
	KTEST_PASS,
	KTEST_FAIL,
	KTEST_DEP_FAIL
} ktest_res;

/******************************************************************************
 * entry sturcture for test case:
 *     argc: numbers of parameters
 *     argv: parameters
 *     tc_main_fn: entry function of each test case.
 *****************************************************************************/
typedef kal_int32 (*ktest_tc_fn_ptr)( kal_uint32 argc, void *argv );
typedef struct
{
	ktest_tc_fn_ptr		tc_main_fn;
	kal_uint32		argc;
	void			*argv;
} ktest_tc_struct;

/******************************************************************************
 * Global variables exposed to test cases.
 *****************************************************************************/
/******************************************************************************
 * variables for test case table.
 *     tc_all_tbls:
 *         an array that contains test case tables in post-schedule stage of
 *         each module.
 *     pre_tc_all_tbls:
 *         an array that contains test case tables in pre-schedule stage of
 *         each module.
 *     tc_modules_num:
 *         an array that contains test cases number in post-schedule stage of
 *         each module.
 *     pre_tc_modules_num:
 *         an array that contains test cases number in pre-schedule stage of
 *         each module.
 *****************************************************************************/
extern ktest_tc_struct const* tc_all_tbls[] ;
extern ktest_tc_struct const* pre_tc_all_tbls[];
extern kal_uint32 tc_modules_num[];
extern kal_uint32 pre_tc_modules_num[];

/******************************************************************************
 * variables for test case related information.
 *     KTEST_TCID: the function name of a test case, it must be assigned the
 *         value of KTEST_FUNCTION_NAME in each test case.
 *     KTEST_BRIEF: brief description of a test case.
 *     KTEST_EXPECT_ERR_CODE: the fatal error that we expected in a test case.
 *         after we assigned a value to it, if the fatal error occured is just
 *         the one we expected, KTEST will report pass, instead of fail.
 *     KTEST_EXP_ASSERT_STR: the assert expression that we expected in a test
 *         case. its behavior is just like that of KTEST_EXPECT_ERR_CODE.
 *****************************************************************************/
extern const kal_char *KTEST_TCID;
extern const kal_char *KTEST_BRIEF;
extern kal_uint32 KTEST_EXPECT_ERR_CODE;
extern kal_char *KTEST_EXP_ASSERT_STR;


/******************************************************************************
 * APIs exposed to test cases.
 *****************************************************************************/
/******************************************************************************
 * Name:
 *     ktest_reset_target
 * Functionality:
 *     reset the target.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 * Note:
 *     this function is designed to reset the target after a test case ends, in
 *     order to make a clean environment for next test case.
 *****************************************************************************/
extern void ktest_reset_target( void );

/******************************************************************************
 * Name:
 *     ktest_print
 * Functionality:
 *     print some information.
 * Parameters:
 *     fmt: a formatted string which determins the format of output.
 *     ...: real parameters that will be used in fmt.
 * Returns:
 *     it always be KAL_TRUE.
 * Note:
 *     this function supports variable parameter list just like printf in c
 *     standard library.
 *****************************************************************************/
extern kal_uint32 ktest_print( kal_char *fmt, ... );

/******************************************************************************
 * Name:
 *     internal_print
 * Functionality:
 *     output some messages.
 * Parameters:
 *     fmt: a formatted string that will be outputed.
 *     ap:  a pointer to the variable argument list, it contains the real
 *          arguments that will be used in fmt.
 * Returns:
 *     if successed, return 0.
 *     else, no return value.
 * Note:
 *     the return value should be re-designed in the future.
 *****************************************************************************/
extern kal_uint32 internal_print( kal_char *fmt, va_list ap );

/******************************************************************************
 * Name:
 *     ktest_flush
 * Functionality:
 *     flush test results to log file.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_flush( void );

/******************************************************************************
 * Name:
 *     ktest_report
 * Functionality:
 *     report a test case result.
 * Parameters:
 *     res: a value of KTEST_PASS, KTEST_FAIL or KTEST_DEP_FAIL.
 *     tcname: the function name of a test case.
 *     fmt: description of a test case, it's a formatted string.
 *     ...: real parameters that will be used in fmt.
 * Returns:
 *     if report successfully, return KAL_TRUE.
 *     else, return KAL_FALSE.
 * Note:
 *     you can use a variable parameter list in this function just like printf
 *     in c standard library.
 *****************************************************************************/
extern kal_uint32 ktest_report( ktest_res res, const kal_char *tcname,
                                kal_char *fmt, ... );

/******************************************************************************
 * Name:
 *     ktest_report_reset
 * Functionality:
 *     report a test case result, then reset the target.
 * Parameters:
 *     code: a value of KTEST_PASS, KTEST_FAIL or KTEST_DEP_FAIL.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_report_reset( kal_int32 code );

/******************************************************************************
 * Name:
 *     ktest_report_reset3
 * Functionality:
 *     report a test case result, then reset the target.
 * Parameters:
 *     code: a value of KTEST_PASS, KTEST_FAIL, or KTEST_DEP_FAIL.
 *     tcname: the function name of a test case.
 *     msg: the description of a test case.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_report_reset3( kal_int32 code, const kal_char *tcname,
                                 kal_char *msg );

/******************************************************************************
 * Name:
 *     ktest_get_sys_tick
 * Functionality:
 *     get current system tick.
 * Parameters:
 *     void.
 * Returns:
 *     if successful, return the system tick.
 *     else, return 0.
 *****************************************************************************/
extern kal_uint32 ktest_get_sys_tick( void );

/******************************************************************************
 * Name:
 *     ktest_set_sys_tick
 * Functionality:
 *     set current system tick.
 * Parameters:
 *     new_tick: new value that to be assigned to current system tick.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_set_sys_tick( kal_uint32 new_tick );

/******************************************************************************
 * Name:
 *     ktest_delay_ticks
 * Functionality:
 *     delay some ticks.
 * Parameters:
 *     delay: how many ticks you want to dealy.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_delay_ticks( kal_uint32 delay );

/******************************************************************************
 * Name:
 *     ktest_strncpy
 * Functionality:
 *     copy some bytes from source to destination.
 * Parameters:
 *     des: memory address of destination.
 *     src: memory address of source.
 *     len: how many bytes you want to copy.
 * Returns:
 *     void.
 * Note:
 *     its behavior is just like memcpy in c standard library, and I want to
 *     use memcpy instead of it.
 *****************************************************************************/
extern void ktest_strncpy( kal_char *des, const kal_char *src, kal_uint32 len );

/******************************************************************************
 * Name:
 *     ktest_strncmp
 * Functionality:
 *     compair a string with another one.
 * Parameters:
 *     s1: the first string to be compaired.
 *     s2: the second string to be compaired.
 *     len: how many bytes do you want to compair.
 * Returns:
 *     if s1 equals with s2, return 0.
 *     else if s1 is in front of s2 in dictionary order, return a negative value.
 *          if s2 is in front of s1 in dictionary order, return a postive value.
 * Note:
 *     its behavior is just like memcmp in c standard library, and I want to use
 *     memcmp instead of it.
 *****************************************************************************/
extern kal_int32 ktest_strncmp( kal_char *s1, kal_char *s2, kal_uint32 len );

/******************************************************************************
 * Name:
 *     ktest_strlen
 * Functionality:
 *     caculate the length of a string.
 * Parameters:
 *     str: the string whose length will be caculated.
 * Returns:
 *     length of the string.
 * Note:
 *     its behavior is just like strlen in c standard library, and I want to use
 *     strlen instead of it.
 *****************************************************************************/
extern kal_uint32 ktest_strlen( const kal_char *str );

/******************************************************************************
 * Name:
 *     ktest_strcmp
 * Functionality:
 *     compair a string with another one.
 * Parameters:
 *     s1: the first string you want to compair.
 *     s2: the second string you want to compair.
 * Returns:
 *     if s1 equals with s2, return 0.
 *     else if s1 is in front of s2 in dictionary order, return a negative value.
 *          if s2 is in front of s1 in dictionary order, return a postive value.
 * Note:
 *     its behavior is just like strcmp in c standard library, and I want to use
 *     strcmp intead of it.
 *****************************************************************************/
extern kal_int32 ktest_strcmp( const kal_char *s1, const kal_char *s2 );

/******************************************************************************
 * Name:
 *     ktest_start_gpt_timer
 * Functionality:
 *     start a gpt timer.
 * Parameters:
 *     time_count: time to expire ( in unit of 10ms ).
 *     gpttimer_func: callback function that will be called when timer expires.
 *                    if it is null, default callback function will be called,
 *                    it sends a message to host PC, then reset the target.
 *     cb_data: data that transferred to callback function.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_start_gpt_timer( kal_uint32 time_count,
                            void (*gpttimer_func)( void * ), void *cb_data );

/******************************************************************************
 * Name:
 *     ktest_stop_gpt_timer
 * Functionality:
 *     stop a gpt timer.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_stop_gpt_timer( void );

/******************************************************************************
 * Name:
 *     ktest_schedule
 * Functionality:
 *     you can call this function in pre-schedule stage in order to run the
 *     created tasks.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_schedule( void );

/******************************************************************************
 * Name:
 *     ktest_sw_intr_handler
 * Functionality:
 *     setup a handler for interrupt.
 * Parameters:
 *     reg_lisr: the interrupt handler.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_sw_intr_handler( void (*reg_lisr)( void ) );

/******************************************************************************
 * Name:
 *     ktest_active_sw_handler
 * Functionality:
 *     activate the interrupt handler
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_active_sw_handler( void );

/******************************************************************************
 * Name:
 *     ktest_deactive_sw_handler
 * Functionality:
 *     de-activate the interrupt handler.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_deactive_sw_handler( void );

/******************************************************************************
 * Name:
 *     ktest_activate_hisr
 * Functionality:
 *     activate a hisr.
 * Parameters:
 *     hisr_routine: the routine of hisr.
 * Returns:
 *     void.
 *****************************************************************************/
extern void ktest_activate_hisr( void (*hisr_routine)( void ) );

/******************************************************************************
 * Name:
 *     ktest_lib_createtask
 * Functionality:
 *     create a task in KTEST
 * Parameters:
 *     priority: the priority of task to be created.
 *     entry_func: entry function of task to be created.
 *     entry_param: parameters that will be transfered ti entry function.
 * Returns:
 *     id of the created task.
 *****************************************************************************/
extern kal_taskid ktest_lib_createtask( kal_uint8 priority,
                                        kal_task_func_ptr entry_func,
                                        void *entry_param );

/******************************************************************************
 * Name:
 *     ktest_fake_test
 * Functionality:
 *     a fake test case
 * Parameters:
 *     argc: number of parameters
 *     argv: parameters of the function
 * Returns:
 *     It always returns KAL_TRUE.
 *****************************************************************************/
extern kal_int32 ktest_fake_test( kal_uint32 argc, void *argv );

#endif  /* __KTEST_INTERFACE_H */
