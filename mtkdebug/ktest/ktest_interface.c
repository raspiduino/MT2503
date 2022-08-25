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
 *     kal_interface.c
 *
 * Project:
 * --------
 *     Maui_Software
 *
 * Description:
 * ------------
 *     This file implements the APIs that exposed to test case files
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
 
#include "ktest_common.h"
#include "ktest_interface.h"
#include <stdarg.h>

/******************************************************************************
 * external APIs and variables that will be used in this file.
 *****************************************************************************/
extern void *kal_sys_mem_alloc( kal_uint32 size );
extern void *kal_create_thread_stack( kal_uint32 stack_size,
                                      kal_bool in_intsram,
                                      kal_uint32 *real_size );
extern kal_taskid kal_create_task( kal_char* task_name, kal_uint8 priority,
                                   void *stack_addr, kal_uint32 stack_size,
                                   kal_task_func_ptr entry_func,
                                   void *entry_param, kal_uint8 options );
extern task_info_struct    *task_info_g;



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
kal_int32 ktest_fake_test( kal_uint32 argc, void *argv )
{
    /* just some meaningless values */
    kal_int32 testf = 0xfabc;
    kal_uint32 testu = 123;

    /* KTEST_TCID must be assigned a correct value. */
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE =  0;

    /* report the test result */
    ktest_report( KTEST_PASS, KTEST_TCID, "%d %x %u", __LINE__, testf, testu );

    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_print
 * Functionality:
 *     it's behavior just likes that of printf in C standard library.
 * Parameters:
 *     variable parameters, just like the parameters in printf (c std library).
 *     fmt: the format string to print.
 *     ...: values that needed in fmt.
 * Returns:
 *     It always return KAL_TRUE.
 *****************************************************************************/
kal_uint32 ktest_print( kal_char *fmt, ... )
{
    va_list ap;
    va_start( ap, fmt );
    internal_print( fmt, ap );
    va_end( ap );

    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_report_reset
 * Functionality:
 *     report the test result, then reset target.
 * Parameters:
 *     code: KTEST_PASS / KTEST_FAIL / KTEST_DEP_FAIL.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_report_reset( kal_int32 code )
{
    /* we use KTEST_TCID to output the test case's function name here, so we
     * need to assign a correct value (KTEST_FUNCTION_NAME) to KTEST_TCID when
     * writing a test case. */
    ktest_report( code, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * Name:
 *     ktest_report_reset3
 * Functionality:
 *     report the test result, then reset target.
 * Parameters:
 *     code: KTEST_PASS / KTEST_FAIL / KTEST_DEP_FAIL.
 *     tcname: name of test case (it's remommented that using function name).
 *     msg: messages you want to report, it can be a variable parameter list.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_report_reset3( kal_int32 code, const kal_char *tcname,
                          kal_char *msg )
{
    ktest_report( code, tcname, msg );
    ktest_reset_target();
}

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
kal_taskid ktest_lib_createtask( kal_uint8 priority,
                                 kal_task_func_ptr entry_func,
                                 void *entry_param )
{
    kal_taskid task_id;
    static kal_uint32 task_index = 0 ;
    void *stack_addr;
    kal_uint32 real_stack_size;

    /* step1. create thread stack */
    stack_addr = (void *) kal_create_thread_stack( 4096, KAL_FALSE,
                                                   &real_stack_size );

    /* step2. create a task */
    task_id = kal_create_task( "ktest_task", priority, stack_addr,
                               real_stack_size, entry_func, entry_param,
                               KAL_FALSE );
    ((kal_task_type *)task_id)->task_index = task_index;
    task_info_g[task_index].task_id  = task_id;
    task_info_g[task_index].task_priority = priority;

    task_index++;
    if( task_index == INDX_KTEST )
    {
        task_index = INDX_KTEST7 + 1;
    }

    return task_id;
}

/******************************************************************************
 * Name:
 *     ktest_strncmp
 * Functionality:
 *     its behavior is like that of memcmp.
 * Parameters:
 *     sl: the 1st string to be comapred.
 *     s2: the 2nd string to be compared.
 *     len: it indicates how many characters to be compared.
 * Returns:
 *     if s1 or s2 is NULL, return -1.
 *     else if s1 equals with s2, return 0.
 *          if s1 < s2 in dictionary sequence, return a negative value.
 *          if s1 > s2 in dictionary sequence, return a postive value.
 * Note:
 *     when s1 < s2, the return value maybe -1, and this will be confused with
 *     the return value when s1 or s2 is NULL (also return -1).
 *     And I think we can use memcmp of C std lib to instead of this function.
 *****************************************************************************/
kal_int32 ktest_strncmp( kal_char *s1, kal_char *s2, kal_uint32 len )
{
    kal_uint32 i;

    /* check whether the parameters are valid */
    if( (NULL == s1) || (NULL == s2) )
        return -1;

    /* compare characters in s1 and s2 by sequence */
    for( i = 0; i < len; i++ )
    {
        if( s1[i] != s2[i] )
        {
            return s1[i] - s2[i];
        }
    }

    /* if we come here, that means s1 equals with s2 */
    return 0;
}


/******************************************************************************
 * Name:
 *     ktest_delay_ticks
 * Functionality:
 *     delay some ticks.
 * Parameters:
 *     delay: how many ticks you want to delay.
 * Returns:
 *     void.
 * Note:
 *     This function should not rely on timer.
 *****************************************************************************/
void ktest_delay_ticks( kal_uint32 delay )
{
    kal_uint32 old_tick, new_tick;
    kal_get_time( &old_tick );

    while( 1 )
    {
        kal_get_time( &new_tick );
        if( new_tick - old_tick >= delay )
        {
            return;
        }
    }
}

/******************************************************************************
 * Name:
 *     ktest_strncpy
 * Functionality:
 *     copy a string to another.
 * Parameters:
 *     des: destination string, it indicates where to store the string.
 *     src: source string, it indicates where the string comes from.
 *     len: length to copy.
 * Returns:
 *     void.
 * Note:
 *     I hope we can use memcpy of C std lib to instead of this function.
 *****************************************************************************/
void ktest_strncpy( kal_char *des, const kal_char *src, kal_uint32 len )
{
    /* check whether the parameters are valid */
    if( (NULL == des) || (NULL == src) )
    {
        return;
    }

    /* copy characters from src to des one by one */
    while( len )
    {
        *(des++) = *(src++);
        len--;
    }
}

/******************************************************************************
 * Name:
 *     ktest_strcmp
 * Functionality:
 *     compaire two strings.
 * Parameters:
 *     s1: the 1st string to be compared.
 *     s2: the 2nd string to be compared.
 * Returns:
 *     if s1 or s2 is NULL, return -1.
 *     else, if s1 equals with s2, return 0.
 *           if s1 < s2 in dictionary sequence, return a negative value.
 *           if s1 > s2 in dictionary sequence, return a postive value.
 * Note:
 *     I hope we can use strcmp or memcmp to instead of this function.
 *****************************************************************************/
kal_int32 ktest_strcmp( const kal_char *s1, const kal_char *s2 )
{
    if( NULL == s1 || NULL == s2 )
        return -1;

    for( ; *s1 == *s2; ++s1, ++s2 )
    {
        if( *s1 == 0 )
        {
            return 0;
        }
        else
        {
            return *(kal_uint8 *) s1 - *(kal_uint8 *) s2;
        }
    }
}

/******************************************************************************
 * Name:
 *     ktest_strlen
 * Functionality:
 *     caculate the length of a string.
 * Parameters:
 *     str: the string whose length you want to get.
 * Returns:
 *     the length (in bytes) of string.
 * Note:
 *     I hope we can use strlen of C std lib to instead of this function.
 *****************************************************************************/
kal_uint32 ktest_strlen( const kal_char *str )
{
    kal_uint32 len = 0;

    while( *str++ )
    {
        len++;
    }

    return len;
}

/******************************************************************************
 * I don't quite understand the functions below.
 * So I don't modify the comments here.
 ******************************************************************************
 * To note g_timer_hisrid is global. The three api are os-dependent
 *****************************************************************************/
kal_hisrid g_timer_hisrid = NULL;
static void lisr_func( void )
{
    kal_activate_hisr( g_timer_hisrid );
    ktest_deactive_sw_handler();
}

/*note, this function can't be called in hisr context*/
void ktest_activate_hisr( void (*hisr_routine)( void ) )
{
    if( g_timer_hisrid == NULL )
    {
        g_timer_hisrid = kal_create_hisr( "TESTHISR", 0, 2048, hisr_routine,
                                          NULL );
        ktest_sw_intr_handler( lisr_func );
    }

    ktest_active_sw_handler();
}
#endif  /*__KTEST__*/
