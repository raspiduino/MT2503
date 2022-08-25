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
 *     ktest_adaptation_oscar.c
 *
 * Project:
 * --------
 *     Maui_Software
 *
 * Description:
 * ------------
 *     This file implements the adaptation layer of KTEST framework.
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

/* this file is valid only when __KTEST__ and KAL_ON_OSCAR are defined. */
#if defined( __KTEST__ ) && defined( KAL_ON_OSCAR )
 
#include "ktest_common.h"
#include "app_buff_alloc.h"
#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include <process.h>

/******************************************************************************
 * external APIs and Variables that will be used in this file.
 *****************************************************************************/
extern osc_type_u32 g_osc_system_initialized;

/******************************************************************************
 * Macros:
 *     KTEST_TC_LABEL_PATH: name of the file that stores test case label.
 *     KTEST_LOG_PATH: name of the file that stores test result.
 *     IRQ_SW_SRC_CODE: the code of interrupt.
 *     TARGET_RESOLUTION: timer resolution.
 *****************************************************************************/
#define KTEST_TC_LABEL_PATH		".\\ktest_tc_label.txt"
#define KTEST_LOG_PATH			".\\ktest_log.txt"
#define IRQ_SW_SRC_CODE         OSC_ISR_SRC_CUSTOM10
#define TARGET_RESOLUTION       1

/******************************************************************************
 * global variables:
 *     ktest_tc_label_file_stream: a file on Windows to store test case label
 *                                 permanently.
 *     ktest_log_file_stream: a file on Windows to store the result of all test
 *                            cases.
 *     reset_handle: used for the Reset program ( it can run all test cases
 *                   one-by-one, so we don't need to run one case each time ).
 *     gpt_timer_resolution: timer resolution that we used.
 *     gpt_timerid: id of GPT timer in OSCAR.
 *****************************************************************************/
FILE *ktest_tc_label_file_stream;
FILE *ktest_log_file_stream;
HANDLE reset_handle;
kal_uint32 gpt_timer_resolution;
kal_uint32 gpt_timerid = 0;

/******************************************************************************
 * Name:
 *     ktest_init_tc_label
 * Functionality:
 *     initialize the test case label.
 * Parameters:
 *     void.
 * Returns:
 *     if initialization ends successfully, return KAL_TRUE.
 *     else, return KAL_FALSE.
 *****************************************************************************/
kal_bool ktest_init_tc_label()
{
    ktest_tc_label tc;

    /* open the file that contains test case label. */
    if( (ktest_tc_label_file_stream = fopen( KTEST_TC_LABEL_PATH,"rb+" ))
        == NULL )
    {
        kal_print( "Create ktest tc lable file for the first time!\n" );
        if( (ktest_tc_label_file_stream = fopen( KTEST_TC_LABEL_PATH,"wb+" ))
            == NULL )
        {
            kal_print( "Cannot open ktest tc lable file!\n" );
            return KAL_FALSE;
        }
    }

    /* read test case label */
    ktest_read_tc_label( &tc );

    /* if the label is not valid, we try to initialize it. */
    if( ktest_strncmp( tc.magic, KTEST_TC_LABEL_MAGIC, KTEST_TC_MAGIC_LEN ) != 0
        || ktest_strncmp( tc.tail, KTEST_TC_LABEL_TAIL, KTEST_TC_TAIL_LEN ) != 0 )
    {
        /* initialize the head of test case label */
        ktest_strncpy( tc.magic, KTEST_TC_LABEL_MAGIC, KTEST_TC_MAGIC_LEN );

        /* initialize the (stage, module, index), note that the index must
         * starts from -1, then it will be added by one before the first test
         * case to run. */
        tc.stage = TC_PRE_SCHEDULE;
        tc.module = 0;
        tc.index = -1;

        /* initialize the tail of test case label */
        ktest_strncpy( tc.tail, KTEST_TC_LABEL_TAIL, KTEST_TC_TAIL_LEN );

        /* write the new value of label permanently */
        return ktest_write_tc_label( &tc );
    }

    /* the label is valid, just return from here. */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_read_tc_label
 * Functionality:
 *     read the test case label from a Windows file.
 * Parameters:
 *     tc_id: a pointer to the test case label.
 * Returns:
 *     if we read it successfully, return KAL_TURE.
 *     else, return KAL_FALSE.
 *****************************************************************************/
kal_bool ktest_read_tc_label( ktest_tc_label *tc_id )
{
    /* we should read from the beginning of the file */
    fseek( ktest_tc_label_file_stream, 0, SEEK_SET );

    /* if we can't read it, output messages. */
    if( fread( tc_id, sizeof(ktest_tc_label), 1, ktest_tc_label_file_stream )
        != 1 )
    {
        kal_print( "Read KTEST label file fail\n" );
        return KAL_FALSE;
    }

    /* ok, we have read it successfully. */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_flush
 * Functionality:
 *     flush the test result to log file.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_flush( void )
{
    fflush( ktest_log_file_stream );
}

/******************************************************************************
 * Name:
 *     ktest_write_tc_label
 * Functionality:
 *     write the test case label permanently.
 * Parameters:
 *     tc_id: a pointer to the new value of test case label.
 * Returns:
 *     if write successfully, return KAL_TRUE.
 *     else, return KAL_FALSE.
 *****************************************************************************/
kal_bool ktest_write_tc_label( const ktest_tc_label *tc_id )
{
    /* we should write the new value of test case label from the beginning of
     * the file. */
    fseek( ktest_tc_label_file_stream, 0, SEEK_SET );

    /* if we can't write it successfully, output messages and return. */
    if( fwrite( tc_id, sizeof(ktest_tc_label), 1, ktest_tc_label_file_stream )
        != 1 )
    {
        kal_print( "Write KTEST label file fail\n" );
        return KAL_FALSE;
    }

    /* ok, we have written it successfully. */
    ktest_flush();
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     internal_print
 * Functionality:
 *     output some messages to log file.
 * Parameters:
 *     fmt: a formatted string, used to support variable argument list.
 *     ap:  a pointer to variable argument list.
 * Returns:
 *     if error occurs, return KAL_FALSE.
 *     else, no return value.
 * Note:
 *     I want to use different return values to indicate different situations.
 *     eg. if output successfully, return the number of outputed characters.
 *         else, return an error code (such as -1).
 *****************************************************************************/
kal_uint32 internal_print( kal_char *fmt, va_list ap )
{

    kal_int32 rc;
    kal_char buf[1024];

    /* store the message into buffer */
    rc = (kal_int32) _vsnprintf( buf, sizeof(buf), fmt, ap );
    if( rc < sizeof(buf) )
    {
        /* output messages */
        kal_print( "%s", (kal_uint8 *) buf );
        if( fwrite( buf, strlen(buf), 1, ktest_log_file_stream ) != 1 )
        {
            kal_print( "Write KTEST log file fail\n" );
            return KAL_FALSE;
        }
    }
    else
    {
        /* we should add overflow handler here. */
    }

    /* Note: we should use different return values to indicate different cases
     *       so the return value maybe changed in the future. */
}

/******************************************************************************
 * Name:
 *     ktest_report
 * Functionality:
 *     report a test result.
 * Parameters:
 *     res: a value of KTEST_PASS, KTEST_FAIL or KTEST_DEP_FAIL.
 *     tc_name: function name of a test case.
 *     fmt: a formatted string, it always means some description of a test case.
 *     ...: real arguments that will be used in fmt.
 * Returns:
 *     if successful, return KAL_TURE.
 *     else, no return value.
 * Note:
 *     we should re-design the return values in the future.
 *****************************************************************************/
kal_uint32 ktest_report( ktest_res res, const kal_char* tc_name,
                         kal_char *fmt, ... )
{
    kal_char log_buf[1024];
    va_list ap;

    /* check if the name of test case is valid */
    if( strlen( tc_name ) == 0 )
    {
        return 0;
    }

    /* output test result */
    if ( KTEST_PASS == res )
    {
        kal_print( "^^%s::Pass", tc_name );
        kal_snprintf( log_buf, sizeof log_buf, "^^%s::Pass", tc_name );
        fwrite( log_buf, strlen( log_buf ), 1, ktest_log_file_stream );
    }
    else
    {
        kal_print( "^^%s::Fail", tc_name );
        kal_snprintf( log_buf, sizeof log_buf, "^^%s::Fail", tc_name );
        fwrite( log_buf, strlen( log_buf ), 1, ktest_log_file_stream );
    }

    /* output brife description of the test case */
    if ( NULL != KTEST_BRIEF )
    {
        kal_print( "::%s", KTEST_BRIEF );

        kal_snprintf( log_buf, sizeof log_buf, "::%s", KTEST_BRIEF );
        fwrite( log_buf, strlen( log_buf ), 1, ktest_log_file_stream );
    }

    /* output description of the test result */
    if ( NULL != fmt && strlen( fmt ) != 0 )
    {
        kal_print( "::" );
        kal_snprintf( log_buf, sizeof log_buf, "::" );
        fwrite( log_buf, strlen( log_buf ), 1, ktest_log_file_stream );

        va_start( ap, fmt );
        internal_print( fmt, ap );
        va_end( ap );
    }

    kal_print( "&&\r\n" );
    kal_snprintf( log_buf, sizeof log_buf, "&&\r\n" );
    fwrite( log_buf, strlen( log_buf ), 1, ktest_log_file_stream );

    /* ok, report test result successfully. */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_reset_target
 * Functionality:
 *     reset the target.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_reset_target( void )
{
    kal_print( "ktest_reset_target...\n" );

    /* close all files we have already opened. */
    fclose( ktest_tc_label_file_stream );
    fclose( ktest_log_file_stream );

    /* set an event, in order to let the "Reset" program knows that. */
    SetEvent( reset_handle );

    /* exit from OSCAR */
    exit( 0 );
}

/******************************************************************************
 * Name:
 *     ktest_schedule
 * Functionality:
 *     this function can be called in pre-schedule stage to let the created
 *     tasks run.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_schedule( void )
{
    kal_int32 ret;
    g_osc_system_initialized = 1;

    /* wait for schedule */
    ret = osc_platform_thread_suspend( NULL, OSC_TIMEOUT_FOREVER,
                                       OSC_BOOL_TRUE );
    if( ret < OSC_NO_ERROR )
    {
        kal_print( "ktest_schedule fail:%d\n", ret );
    }
}

/******************************************************************************
 * Name:
 *     ktest_sw_intr_handler
 * Functionality:
 *     register a interrupt handler.
 * Parameters:
 *     reg_lisr: the interrupt handler.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_sw_intr_handler( void (*reg_lisr)( void ) )
{
    OSC_Register_ISR( IRQ_SW_SRC_CODE, reg_lisr );
}

/******************************************************************************
 * Name:
 *     ktest_active_sw_handler
 * Functionality:
 *     activate the interrupt handler.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_active_sw_handler( void )
{
    OSC_Activate_ISR( IRQ_SW_SRC_CODE );
}

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
void ktest_deactive_sw_handler( void )
{
    /* just return ? */
    return;
}

/******************************************************************************
 * Name:
 *     ktest_init_gpt_timer
 * Functionality:
 *     initialize GPT timer.
 * Parameters:
 *     void.
 * Returns:
 *     if initialization ends successfully, return KAL_TRUE.
 *     else, return KAL_FALSE.
 * Note:
 *     we use windows timer to simulate GPT timer in OSCAR.
 *****************************************************************************/
static kal_int32 ktest_init_gpt_timer( void )
{
    kal_uint8 ev_name[32];
    TIMECAPS tc;

    /* get timer resolution that Windows can support */
    if( timeGetDevCaps( &tc, sizeof(TIMECAPS) ) != TIMERR_NOERROR )
    {
         return KAL_FALSE;
    }

    /* This is the highest timer resolution Windows can support.
     * The higher resolution, the higher the overhead. */
    gpt_timer_resolution = min( max( tc.wPeriodMin, TARGET_RESOLUTION ),
                                tc.wPeriodMax );
    timeBeginPeriod( gpt_timer_resolution );

    /* ok, GPT timer initialize successfully. */
    return KAL_TRUE;
}

/******************************************************************************
 * Name:
 *     ktest_stop_gpt_timer
 * Functionality:
 *     stop the GPT timer.
 * Parameters:
 *     void.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_stop_gpt_timer( void )
{
    timeKillEvent( gpt_timerid );
}

/******************************************************************************
 * Name:
 *     gpt_callback
 * Functionality:
 *     the default callback funtion of GPT timer.
 * Parameters:
 *     I don't quite understand yet.
 * Returns:
 *     void.
 *****************************************************************************/
static void CALLBACK gpt_callback( kal_int32 wTimerID, kal_int32 msg,
                                   kal_int32 dwUser, kal_int32 dw1,
                                   kal_int32 dw2 )
{
    ktest_report( KTEST_FAIL, KTEST_TCID, "GPT alarm timeout" );
    ktest_stop_gpt_timer();
    ktest_reset_target();
}

/******************************************************************************
 * Name:
 *     gpt_callback_wraper
 * Functionality:
 *     a wraper of callback funtion that user provided.
 * Parameters:
 *     I don't quite understand yet.
 * Returns:
 *     void.
 *****************************************************************************/
static void CALLBACK gpt_callback_wraper( kal_int32 wTimerID, kal_int32 msg,
                                          kal_int32 dwUser, kal_int32 dw1,
                                          kal_int32 dw2 )
{
    kal_internal_timerid timer_id = (kal_internal_timerid) dwUser;
    (*(timer_id->func_ptr))( timer_id->timer_param_ptr );
    free_ctrl_buffer( timer_id );
}

/* @Discription:
 * Provide basic timer facility API. If no callback function, default behavior
 * is when expire, a fail message sent to host pc and target reset. The caller
 * should setup KTEST_TCID properly. User can override this behavior by provi-
 * ding callback function
 *
 *  @Input
 *  time_count: expire time in unit of 10ms
 *  gptimer_func: call back function
 *  cb_data: call back data passed to callback function
 * */
/******************************************************************************
 * Name:
 *     ktest_start_gpt_timer
 * Functionality:
 *     start the GPT timer.
 * Parameters:
 *     time_count: time to expire ( in unit of 10ms ).
 *     gptimer_func: callback function used when the timer expires.
 *     cb_data: arguments for gptimer_func.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_start_gpt_timer( kal_uint32 time_count,
                            void (*gptimer_func)( void * ), void *cb_data )
{
    kal_internal_timerid timer_id;
    kal_uint32 actual_time_count = time_count * 10;

    timer_id = get_ctrl_buffer( sizeof(kal_timer_type) );

    /* start the GPT timer. if user doesn't provide a callback function, then
     * use the default one instead. */
    if( NULL == gptimer_func )
    {
        gpt_timerid =
            (kal_uint32) timeSetEvent( actual_time_count, gpt_timer_resolution,
                                       (LPTIMECALLBACK) gpt_callback, 0,
                                       TIME_ONESHOT | TIME_CALLBACK_FUNCTION );
    }
    else
    {
        timer_id->func_ptr = gptimer_func;
        timer_id->timer_param_ptr = cb_data;
        gpt_timerid =
            (kal_uint32) timeSetEvent( actual_time_count, gpt_timer_resolution,
                                       (LPTIMECALLBACK) gpt_callback_wraper,
                                       timer_id,
                                       TIME_ONESHOT | TIME_CALLBACK_FUNCTION );
    }
}

/******************************************************************************
 * Name:
 *     ktest_get_sys_tick
 * Functionality:
 *     get system ticks now.
 * Parameters:
 *     void.
 * Returns:
 *     the system ticks now.
 *****************************************************************************/
kal_uint32 ktest_get_sys_tick( void )
{
    kal_uint32 current_tick;
    OSC_Get_Current_Tick( &current_tick );
    return current_tick;
}

/******************************************************************************
 * Name:
 *     ktest_set_sys_tick
 * Functionality:
 *     set system ticks now.
 * Parameters:
 *     new_tick: new value of system ticks.
 * Returns:
 *     void.
 *****************************************************************************/
void ktest_set_sys_tick( kal_uint32 new_tick )
{
    kal_int32 delta;
    kal_uint32 current_tick;

    /* get current tick */
    OSC_Get_Current_Tick(&current_tick);

    /* caculate the new_tick and adjust system tick */
    delta = new_tick - current_tick;
    OSC_Adjust_Tick_Time(delta);
}

/******************************************************************************
 * Name:
 *     ktest_init_env
 * Functionality:
 *     initialize the environment for KTEST framework on OSCAR.
 * Parameters:
 *     void.
 * Returns:
 *     if the initialization succeed, return KAL_TURE.
 *     else, return KAL_FALSE.
 *****************************************************************************/
kal_uint32 ktest_init_env( void )
{
    kal_uint32 ret_val;

    /* initialize the GPT timer */
    ret_val = ktest_init_gpt_timer();
    if( ret_val == KAL_FALSE )
    {
        system_print( "Warning: stack_init() Error in ktest_init_gpt_timer.\n" );
        return KAL_FALSE;
    }

    /* set an event for the "Reset" tool */
    reset_handle = CreateEvent( NULL, FALSE, FALSE, "KTEST_Event" );
    if( !reset_handle )
    {
        printf( "Create KTEST Event error: %d!\n", GetLastError() );
        return KAL_FALSE;
    }

    /* open the log file */
    if( (ktest_log_file_stream = fopen(KTEST_LOG_PATH,"a+") ) == NULL )
    {
        kal_print( "Cannot open ktest log file!\n" );
        return KAL_FALSE;
    }

    /* initialization succeed. */
    return ret_val;
}

#endif  /* __KTEST__ && KAL_ON_OSCAR */
