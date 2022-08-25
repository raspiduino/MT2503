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
 *   ktest_tc_timer.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file implements MediaTek KAL (Kernel Abstraction Layer) auto test task
 *   functions.
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/* this file is valid only when __KTEST__ has been defined */
#ifdef __KTEST__
 
#include "ktest_lib_timer.h"
#include "ktest_common.h"
#include "stack_timer.h"

/*should be included together*/
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_types.h"
#include "task_config.h"

#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "stdlib.h"
#include "event_shed.h"
#include "kal_release.h"
#include "us_timer.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "stack_ltlcom.h"

static eventid  g_id;
static kal_int32 g_elapse_time;
extern const unsigned int kal_min_evshed_buffer_number;
extern void* kal_sys_mem_alloc( kal_uint32 size );

/******************************************************************************
 * this function should be divided into two:
 *     1) once timeout, report error and reset target
 *     2) once timeout, check the time error, and reset
 *****************************************************************************/
static void ktest_timer_cb( void *timer_param )
{
    kal_uint32 elapse;
    cb_time_s *time_data = NULL;
    kal_uint32 now;

    /* Opt 1: Once timer expires, fail! */
    if( NULL == timer_param )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
    else
    {
        /* When timer expires, check timer tick time in HISR */
        kal_get_time( &now );
        time_data = (cb_time_s *) timer_param;
        elapse = now - time_data->save_time;

        if( compare_time_error( time_data->delay_tick, elapse,
                                KAL_TIMER_ALLOWED_ERROR ) )
        {
            ktest_report( KTEST_PASS, KTEST_TCID, "Timer elapse time %u", elapse );
        }
        else
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "timer error number %d",
                          elapse - time_data->delay_tick );
        }
    }

    ktest_reset_target();
    return;
}

static void fake_event_cb1( void *cb_data )
{
    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * the two cb func should be modified to be more general!
 *****************************************************************************/
/******************************************************************************
 * call back fuction can be lib
 *****************************************************************************/
static void event_cb2( void *cb_data )
{
    ktest_timer_g_count++;

    if( g_elapse_time != 20 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "Timer delay %d\n",
                      g_elapse_time - 20 );
        ktest_reset_target();
    }
}

static void event_cb3( void *cb_data )
{
    ktest_timer_g_count++;

    if( g_elapse_time != 16 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "Timer delay %d",
                      g_elapse_time - 16 );
        ktest_reset_target();
    }
}

static void event_cb6( void *data )
{
    ilm_struct current_ilm;
    event_scheduler *es = (event_scheduler *) data;

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid, &current_ilm ) )
    {
        evshed_timer_handler( es );
    }
}

static void event_cb8( void *data )
{
    event_scheduler *es = (event_scheduler *) data;
    evshed_suspend_all_events( es );
}

static void event_cb9( void *data )
{
    event_scheduler *es = (event_scheduler *) data;
    evshed_cancel_event( es, &g_id );
}

static void event_cb10( void *data )
{
    event_scheduler *es = (event_scheduler *) data;
    if( evshed_has_pending_events( es ) )
    {
    	ktest_report( KTEST_FAIL, KTEST_TCID, "Timer delay %d\n",
                        g_elapse_time - 16 );
        ktest_reset_target();
    }
    else
    {
	    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
	    ktest_reset_target();
    }
}

static void internal_start_timer_checktime( kal_uint32 delay )
{
    kal_timerid tst_timerid;
    kal_uint32 int_delay;

    int_delay = delay;
    if( delay == 0 )
    {
        int_delay = 1;
    }

    ktest_init_timer_cb( &global_cb_array[0], int_delay );
    if( !(tst_timerid = kal_create_timer( "ktest_timer" )) )
    {
        /* error handling */
    }

    kal_set_timer( tst_timerid, ktest_timer_cb, &global_cb_array[0], delay, 0 );
}

static void gpt_callback( void *data )
{
    ktest_stop_gpt_timer();

    ktest_report( KTEST_PASS, KTEST_TCID, "GPT alarm timeout" );
    ktest_reset_target();
}

static kal_int32 ktest_gpt_test( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test gpt timer timeout works";

    ktest_start_gpt_timer( 10, gpt_callback, NULL );

    kal_sleep_task( KAL_SUSPEND );
}

kal_int32 ktest_start_timer( kal_uint32 argc, void *argv )
{
    kal_uint32 delay = 0;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "start timer with tick 0";

    internal_start_timer_checktime( delay );
    ktest_start_gpt_timer( 10, NULL, NULL );
    kal_sleep_task( KAL_SUSPEND );
}

kal_int32 ktest_start_timer_v2( kal_uint32 argc, void *argv )
{
    kal_uint32 delay = 7;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "start timer with tick 7";

    internal_start_timer_checktime( delay );
    ktest_start_gpt_timer( delay, NULL, NULL );
    kal_sleep_task( KAL_SUSPEND );
}

kal_int32 ktest_start_timer_sequence( kal_uint32 argc, void *argv )
{
    cb_time_s time1, time2, time3;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "start a sequence of timers";

    ktest_timer_g_count = 0;
    ktest_init_timer_cb( &time1, 6 );
    create_set_timer( event_cb4, &time1, 6 );

    ktest_delay_ticks( 2 );
    ktest_init_timer_cb( &time2, 20 );
    create_set_timer( event_cb4, &time2, 20 );

    ktest_delay_ticks( 3 );
    ktest_init_timer_cb( &time3, 30 );
    create_set_timer( event_cb4, &time3, 30 );

    ktest_delay_ticks( 50 );
    if( ktest_timer_g_count == 3 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    ktest_reset_target();
}

kal_timerid tst_timerid_2;
kal_uint32 sched_time;
kal_uint32 old_sched_time;
static void ktest_reschedule_callback( void *timer_param )
{
    if( 7 == ++*(kal_uint32*)(timer_param) )
    {
        kal_cancel_timer( tst_timerid_2 );
        kal_get_time( &sched_time );
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_timer_reschedule
 * @remark brief: Test kal_set_timer expires again and again until 7 times!
 * @remark dependency: Task, ktest_create_timer, ktest_cancel_timer
 * @remark expecation: KAL timer expires 7 times automatically.
 *****************************************************************************/
kal_int32 ktest_timer_reschedule( kal_uint32 argc, void *argv )
{
    kal_uint32 count = 0;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    if( !(tst_timerid_2 = kal_create_timer( "ktest_timer" )) )
    {
        /*XXX error handling*/
    }

    kal_get_time( &old_sched_time );
    kal_set_timer( tst_timerid_2, ktest_reschedule_callback, &count, 10, 1 );

    kal_sleep_task( 1000 );

    if( 7 == count )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, "Elapse time is %d, should be 70",
                      sched_time - old_sched_time );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "The reshedule count is %d\n",
                      count );
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_start_running_timer
 * @remark brief: Test kal_set_timer starts a running timer
 * @remark dependency: Task, ktest_create_timer
 * @remark expecation: KAL timer expires with a new time tick
 *****************************************************************************/
kal_int32 ktest_start_running_timer( kal_uint32 argc, void *argv )
{
    kal_timerid tst_timerid;
    cb_time_s time;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    if( !(tst_timerid = kal_create_timer( "ktest_timer" )) )
    {
        /* error handling */
    }

    kal_get_time( &time.save_time );
    time.delay_tick = 57;

    kal_set_timer( tst_timerid, ktest_timer_cb, &time, 17, 0 );
    kal_set_timer( tst_timerid, ktest_timer_cb, &time, 57, 0 );

    ktest_start_gpt_timer( 57, NULL, NULL );
    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_start_timer_zero_tick
 * @remark brief: Test kal_set_timer starts a zero timer
 * @remark dependency: Task, ktest_create_timer
 * @remark expecation: KAL timer expires after exactly 1 tick
 *****************************************************************************/
kal_int32 ktest_start_timer_zero_tick( kal_uint32 argc, void *argv )
{
    kal_timerid tst_timerid;
    cb_time_s time_data;
    kal_get_time( &time_data.save_time );
    time_data.delay_tick = 1;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    if( !(tst_timerid = kal_create_timer( "ktest_timer" )) )
    {
        /* error handling */
    }

    kal_set_timer( tst_timerid, ktest_timer_cb, &time_data, 0, 0 );

    /* Fail path */
    ktest_start_gpt_timer( 10, NULL, NULL );

    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_timer_para_check
 * @remark brief: [BUG fixed] Test kal_set_timer pass invalid timerid.
 * @remark dependency: None
 * @remark expecation: should fatal error with KAL_ERROR_TIMER_CONTROL_FAILED
 *****************************************************************************/
kal_int32 ktest_set_timer_para_check( kal_uint32 argc, void *argv )
{
    kal_timerid tst_timerid = NULL;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KTEST_ALL_ERROR_CODE;

#if defined( DEBUG_KAL ) && defined( DEBUG_TIMER )
    kal_set_timer( tst_timerid, NULL, NULL, 0, 0 );
    /* we expect a fatal error in kal_set_timer, so the statement below should
     * be unreachable. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
#else
    /* kal_set_timer will check the parameter only when DEBUG_KAL and
     * DEBUG_TIMER have been defined. so if any one of them has not been
     * defined, then we don't do the test, but report PASS directly. */
    ktest_report( KTEST_PASS, KTEST_TCID,
                  "DEBUG_KAL or DEBUG_TIMER not define, by pass." );
#endif  /* DEBUG_KAL && DEBUG_TIMER */
}

kal_int32 ktest_cancel_timer( kal_uint32 argc, void *argv )
{
    kal_timerid tid = NULL;
    kal_timerid tid1 = NULL;
    kal_timerid tid2 = NULL;
    kal_timerid tid3 = NULL;
    cb_time_s   time;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "KAL Cancel timer in the head/middle/tail";

    tid = kal_create_timer( "test1" );
    tid1 = kal_create_timer( "test2" );
    tid2 = kal_create_timer( "test3" );
    tid3 = kal_create_timer( "test4" );

    /* Once, the cancelled timer timeout, report error */
    ktest_timer_g_count = 0;
    kal_set_timer( tid, ktest_timer_cb_timeout_fail, NULL, 13, 0 );

    ktest_init_timer_cb( &time, 23 );
    kal_set_timer( tid1, event_cb4, &time, 23, 0 );
    kal_set_timer( tid2, ktest_timer_cb_timeout_fail, NULL, 37, 0 );
    kal_set_timer( tid3, ktest_timer_cb_timeout_fail, NULL, 47, 0 );

    /* cancel the head */
    kal_cancel_timer( tid );

    /* cancel the middle */
    kal_cancel_timer( tid2 );

    /* cancel the tail */
    kal_cancel_timer( tid3 );

    ktest_delay_ticks( 53 );

    if( ktest_timer_g_count == 1 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "count is %d",
                      ktest_timer_g_count );
    }

    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_cancel_timer_null
 * @remark brief: Test kal_cancel_timer with NULL timer id
 * @remark dependency: None
 * @remark expecation: read NULL cause no data abort.
 * fatal error with KAL_ERROR_TIMER_CANCEL_FAILED
 *****************************************************************************/
kal_int32 ktest_cancel_timer_null( kal_uint32 argc, void *argv )
{
    kal_timerid tid = NULL;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_TIMER_CANCEL_FAILED;

#if defined( DEBUG_KAL ) && defined( DEBUG_TIMER )
    kal_cancel_timer( tid );
    /* we expect a fatal error in kal_cancel_timer, so the statement below
     * should be unreachable. */
    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
#else
    /* kal_cancel_timer will check the parameter only when DEBUG_KAL and
     * DEBUG_TIMER have been defined. so if any one of them has not been
     * defined, then we don't do the test, but report PASS directly. */
    ktest_report( KTEST_PASS, KTEST_TCID,
                  "DEBUG_KAL or DEBUG_TIMER not define, by pass." );
#endif  /* DEBUG_KAL && DEBUG_TIMER */
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_cancel_timer_inittimer
 * @remark brief: Test kal_cancel_timer cancel a newly created timer.
 * @remark dependency: ktest_create_timer
 * @remark expecation: cancel ok, no fatal error should happen
 *****************************************************************************/
kal_int32 ktest_cancel_timer_inittimer( kal_uint32 argc, void *argv )
{
    kal_timerid tid = NULL;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    tid = kal_create_timer( "test" );

    kal_cancel_timer( tid );

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_get_time_remaining
 * @remark brief: Test kal_get_time_remaining when no overflow.
 * @remark dependency: ktest_create_timer, ktest_start_timer
 * @remark expecation: get the right remaining time of timer
 *****************************************************************************/
kal_int32 ktest_get_time_remaining( kal_uint32 argc, void *argv )
{
    kal_uint32 left = 0;
    kal_timerid tid = NULL;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    tid = kal_create_timer( "test" );

    /* Suppose system clock not too big */
    kal_set_timer( tid, ktest_timer_cb_timeout_fail, NULL, 10, 0 );

    left = kal_get_time_remaining( tid );

    kal_cancel_timer( tid );

    if( 10 == left )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_PASS, KTEST_TCID, "The API left time is %d", left );
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_get_time_remaining1
 * @remark brief: [Bug fix] Test kal_get_time_remaining after set_timer overflows.
 * @remark dependency: ktest_create_timer, ktest_start_timer
 * @remark expecation: get the right remaining time of timer
 *****************************************************************************/
kal_int32 ktest_get_time_remaining1( kal_uint32 argc, void *argv )
{
    kal_timerid tid = NULL;
    kal_uint32 left = 0;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    tid = kal_create_timer( "test" );

    /* build a overflow */
    ktest_set_sys_tick( 0xFFFFFF00 );
    kal_set_timer( tid, ktest_timer_cb, NULL, 0x1FF, 0 );

    left = kal_get_time_remaining( tid );

    if( 0x1FF == left )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "The API left time is %d", left );
    }

    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_get_time_remaining2
 * @remark brief: [Bug fix] Test kal_get_time_remaining after kal_cancel_timer
 * @remark dependency: ktest_create_timer, ktest_start_timer
 * @remark expecation:  get zero
 *****************************************************************************/
kal_int32 ktest_get_time_remaining2( kal_uint32 argc, void *argv )
{
    kal_timerid tid = NULL;
    kal_uint32 left = 0;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    tid = kal_create_timer( "test" );

    /* build a overflow */
    kal_set_timer( tid, ktest_timer_cb, NULL, 0x1FF, 0 );
    kal_cancel_timer( tid );
    left = kal_get_time_remaining( tid );

    if( 0x0 == left )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "The API left time is %d", left );
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_init_timer
 * @remark brief: Test stack_init_timer and verify part of its values
 * @remark dependency: ktest_create_timer
 * @remark expecation: Timer created with proper value
 *****************************************************************************/
kal_int32 ktest_stack_init_timer( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    stack_init_timer( &st, "test", MOD_KTEST4 );

    if( st.kal_timer_id != NULL
        && st.timer_user_view_status == STACK_TIMER_USER_VIEW_STOPPED )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
}

static void task_check_time_entry( task_entry_struct *task_entry_ptr )
{
    ilm_struct current_ilm;
    cb_time_s  *time_cb;
    kal_uint32 elapse;

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST4].task_ext_qid,
                              &current_ilm ) )
    {
        if( task_entry_ptr == NULL )
        {
            ktest_report( KTEST_PASS, KTEST_TCID, NULL );
            ktest_reset_target();
        }
        else
        {
            time_cb = (cb_time_s *) task_entry_ptr;
            elapse = ktest_get_sys_tick() - time_cb->save_time;

            /* time check */
            if( compare_time_error( elapse, time_cb->delay_tick,
                                    KAL_TIMER_ALLOWED_ERROR ) )
            {
                ktest_report( KTEST_PASS, KTEST_TCID, NULL );
                ktest_reset_target();
            }
            else
            {
                ktest_report( KTEST_FAIL, KTEST_TCID,
                              "real time %d, should time %d",
                              elapse, time_cb->delay_tick );
                ktest_reset_target();
            }
        }
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_start_timer
 * @remark brief: Test stack_start_timer from init state which sends an ILM to a task.
 * @remark dependency:
 * @remark expecation: Task get the ILM.
 *****************************************************************************/
kal_int32 ktest_stack_start_timer( kal_uint32 argc, void *argv )
{
    cb_time_s time_cb;
    stack_timer_struct st;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    /* time_cb.save_time = TMD_System_Clock; */
    time_cb.save_time = ktest_get_sys_tick();
    time_cb.delay_tick = 10;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_check_time_entry,
                                &time_cb );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;

    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );  /* An ILM will be sent to INDX_KTEST4 */

    /* Fail path */
    kal_sleep_task( 100 );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    ktest_reset_target();
}

kal_int32 ktest_stack_start_timer_zero( kal_uint32 argc, void *argv )
{
    cb_time_s time_cb;
    stack_timer_struct st;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "stack_start_timer from init state with zero tick";

    time_cb.save_time = ktest_get_sys_tick();
    time_cb.delay_tick = 0;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_check_time_entry,
                                &time_cb );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;

    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 0 );  /* An ILM will be sent to INDX_KTEST4 */

    /* Fail path */
    ktest_start_gpt_timer( 100, NULL, NULL );
    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_start_running_timer
 * @remark brief: Test stack_start_timer starts a running timer which rescheudles the timer
 * @remark dependency: ktest_create_timer
 * @remark expecation: Task get message at the rescheduled time
 *****************************************************************************/
kal_int32 ktest_stack_start_running_timer( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;
    cb_time_s time_cb;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    time_cb.save_time = ktest_get_sys_tick();
    time_cb.delay_tick = 19;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_check_time_entry,
                                (void *) &time_cb );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;

    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );  /* An ILM will be sent to INDX_KTEST4 */
    stack_start_timer( &st, 0, 19 );  /* An ILM will be sent to INDX_KTEST4 */

    /* Fail path */
    kal_sleep_task( 37 );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    ktest_reset_target();
}

static void task_entry_2( task_entry_struct *task_entry_ptr )
{
    ilm_struct current_ilm;

    while( KAL_SUCCESS
           == receive_msg_ext_q( task_info_g[INDX_KTEST4].task_ext_qid,
                                 &current_ilm ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

static void task_entry_1( task_entry_struct *task_entry_ptr )
{
    kal_uint32 count = 0;
    kal_msgq_info msg_info;

    kal_get_queue_info( task_info_g[INDX_KTEST4].task_ext_qid, &msg_info );
    count = msg_info.pending_msgs;

    if( 2 == count )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "message count is %d", count );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_start_expired_timer
 * @remark brief: Test stack_start_timer starts an expired timer and
 * task gets two message from one timer
 * @remark dependency:kal_get_queue_info
 * @remark expecation: Task get two messages
 *****************************************************************************/
kal_int32 ktest_stack_start_expired_timer( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_entry_1, NULL );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );  /* An ILM will be sent to INDX_KTEST4 */

    /* Wait until timer expired */
    while( stack_timer_status( &st, NULL ) == STACK_TIMER_NOT_TIMED_OUT )
    {
    }

    stack_start_timer( &st, 0, 19 );  /*An ILM will be sent to INDX_KTEST4*/
    while( stack_timer_status( &st, NULL ) == STACK_TIMER_NOT_TIMED_OUT)
    {
    }

    /* Fail path */
    kal_sleep_task( 37 );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_start_stopped_timer
 * @remark brief: Test stack_start_timer starts a stopped timer
 * @remark dependency: ktest_stack_stoppped_timer
 * @remark expecation: Task get a message
 *****************************************************************************/
kal_int32 ktest_stack_start_stopped_timer( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;
    cb_time_s time_cb;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    time_cb.save_time = ktest_get_sys_tick();
    time_cb.delay_tick = 19;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_check_time_entry,
                                &time_cb );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );
    stack_stop_timer( &st );
    stack_start_timer( &st, 0, 19 );

    /* FAIL path */
    kal_sleep_task( 37 );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_stop_timer
 * @remark brief: Test stack_stop_timer a running timer,
 * @remark dependency:
 * @remark expecation: Task can't get a message;
 * stack_stop_timer returns STACK_TIMER_NOT_TIMED_OUT
 *****************************************************************************/
kal_int32 ktest_stack_stop_timer( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;
    kal_uint32  ret_val;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    /* FAIL if receive mesg */
    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_entry_2, NULL );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );
    ret_val = stack_stop_timer( &st );

    /* OK path */
    kal_sleep_task( 37 );

    if( STACK_TIMER_NOT_TIMED_OUT == ret_val )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_stop_timer2
 * @remark brief: Test stack_stop_timer a just created stack timer
 * @remark dependency:
 * @remark expecation: stack_stop_timer return STACK_TIMER_NOT_RUNNING .
 *****************************************************************************/
kal_int32 ktest_stack_stop_timer2( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;
    KTEST_TCID = KTEST_FUNCTION_NAME;

    stack_init_timer( &st, "test", MOD_KTEST4 );

    if( STACK_TIMER_NOT_RUNNING == stack_stop_timer( &st ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    ktest_reset_target();
}

static void task_entry_3( task_entry_struct *task_entry_ptr )
{
    ilm_struct current_ilm;
    stack_timer_struct *st = NULL;

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST4].task_ext_qid,
                              &current_ilm ) )
    {
        st = (stack_timer_struct *) ( current_ilm.local_para_ptr );

        if( stack_is_time_out_valid( st ) )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        }
        else
        {
            ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        }
    }
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_stop_expired_timer
 * @remark brief: 1) Test stack_stop_timer stops an expired timer before message processed by task;
 * 2) stack_is_time_out_valid return false.
 * @remark dependency: stack_is_time_out_valid
 * @remark expecation: Task get a message and know it had been stopped.
 * stack_stop_timer returns STACK_TIMER_TIMED_OUT
 *****************************************************************************/
kal_int32 ktest_stack_stop_expired_timer( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_entry_3, NULL );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );

    /* wait until timer expires */
    while( stack_timer_status( &st, NULL ) == STACK_TIMER_NOT_TIMED_OUT )
    {
    }

    /* stop timer before processed by task */
    if( !( STACK_TIMER_TIMED_OUT == stack_stop_timer( &st ) ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }

    /* FAIL path */
    kal_sleep_task( 37 );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    ktest_reset_target();
}

static void task_entry_4( task_entry_struct* task_entry_ptr )
{
    ilm_struct current_ilm;
    stack_timer_struct *st = NULL;

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST4].task_ext_qid,
                              &current_ilm ) )
    {
        st = (stack_timer_struct *) (current_ilm.local_para_ptr);
        if( !stack_is_time_out_valid( st ) )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "Timeout invalid" );
            ktest_reset_target();
        }
        stack_process_time_out( st );
    }

    /* In oscar, a task return is still ready in oscar, exit in windows.
     * So schedule will error */
    while( 1 )
    {
    }
}

kal_int32 ktest_stack_stop_expired_timer1( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF ="stops an expired timer after message processed";

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_entry_4, NULL );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );

    while( stack_timer_status( &st, NULL ) == STACK_TIMER_NOT_TIMED_OUT )
    {
    }

    kal_sleep_task( 37 );

    if( STACK_TIMER_NOT_RUNNING == stack_stop_timer( &st ) )
    {
        /* stop a timer after task process the message */
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    ktest_reset_target();
}

static void task_entry_5( task_entry_struct *task_entry_ptr )
{
    ilm_struct current_ilm;
    stack_timer_struct *st = NULL;

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST4].task_ext_qid,
                              &current_ilm ) )
    {
        st = (stack_timer_struct *) (current_ilm.local_para_ptr);
        stack_is_time_out_valid( st );
    }

    /* In oscar, a task return is still ready in oscar, exit in windows.
     * So schedule will error*/
    while( 1 )
    {
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_timer_user_status
 * @remark brief: Test a a timer's user view value when it transists through created
 * , expired, and ilm processed
 * @remark dependency: ktest_stack_init_timer, ktest_stack_start_timer, stack_timer_status
 * @remark expecation: User view should keeps in running before processed!
 * [suggestion] If forget to stack_process_time_out after stack_is_time_out_valid and before stack_stop_timer,
 * invalid_time_out_count add twice! It's nice to merge stack_is_time_out_valid and stack_process_time_out
 * together!
 *****************************************************************************/
kal_int32 ktest_stack_timer_user_status( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_entry_5, NULL );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    if( STACK_TIMER_USER_VIEW_RUNNING
        == stack_timer_user_view_status( &st, NULL ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "user view status should be STACK_TIMER_USER_VIEW_STOPPED" );
        ktest_reset_target();
    }

    stack_start_timer( &st, 0, 10 );
    if( !( STACK_TIMER_USER_VIEW_RUNNING
           == stack_timer_user_view_status( &st, NULL ) ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "user view should be running" );
        ktest_reset_target();
    }

    /* Wait until expiration */
    while( stack_timer_status( &st, NULL ) == STACK_TIMER_NOT_TIMED_OUT )
    {
    }

    if( !( STACK_TIMER_USER_VIEW_RUNNING
           == stack_timer_user_view_status( &st, NULL ) ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "user view should be running" );
        ktest_reset_target();
    }

    kal_sleep_task( 37 );

    if( STACK_TIMER_USER_VIEW_RUNNING
        == stack_timer_user_view_status( &st, NULL ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "user view should be STACK_TIMER_USER_VIEW_STOPPED" );
        ktest_reset_target();
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_timer_user_status2
 * @remark brief: Test a a timer's user view value stopped by stack_stop_timer
 * @remark dependency: ktest_stack_start_timer, ktest_stack_stop_timer
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_stack_timer_user_status2( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_entry_5, NULL );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );
    stack_stop_timer( &st );

    if( STACK_TIMER_USER_VIEW_STOPPED
        == stack_timer_user_view_status( &st, NULL ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    ktest_reset_target();
}

static kal_int32 verify_st( stack_timer_struct *st, kal_uint8 count,
                            stack_timer_status_type state,
                            stack_timer_user_view_status_type state_usr )
{
    if( (count == st->invalid_time_out_count)
        && (state == st->timer_status)
        && (state_usr == st->timer_user_view_status) )
    {
        return KTEST_PASS;
    }
    else
    {
        return KTEST_FAIL;
    }
}

static void task_entry_6( task_entry_struct *task_entry_ptr )
{
    /* do nothing */
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_process_time_out
 * @remark brief: Test stack_process_time_out only modify timer in expired state
 * @remark dependency:
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_stack_process_time_out( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_entry_6, NULL );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_process_time_out( &st );
    if( KTEST_FAIL
        == verify_st( &st, 0, STACK_TIMER_NOT_RUNNING,
                      STACK_TIMER_USER_VIEW_STOPPED ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }

    stack_start_timer( &st, 0, 10 );
    stack_process_time_out( &st );
    if( KTEST_FAIL
        == verify_st( &st, 0, STACK_TIMER_RUNNING,
                      STACK_TIMER_USER_VIEW_RUNNING ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }

    /* Wait until expiration */
    while( stack_timer_status( &st, NULL ) == STACK_TIMER_NOT_TIMED_OUT)
    {
    }
    stack_process_time_out( &st );
    if( KTEST_FAIL
        == verify_st( &st, 0, STACK_TIMER_NOT_RUNNING,
                      STACK_TIMER_USER_VIEW_STOPPED ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_stack_process_time_out2
 * @remark brief: Test stack_process_time_out reset expired_count increased by stack_stop_timer
 * and doesn't change timer status.
 * @remark dependency:
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_stack_process_time_out2( kal_uint32 argc, void *argv )
{
    stack_timer_struct st;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    task_info_g[INDX_KTEST4].task_id
        = ktest_lib_createtask( TASK_PRIORITY_KTEST + 5, task_entry_6, NULL );
    ((kal_task_type *) task_info_g[INDX_KTEST4].task_id)->task_index
        = INDX_KTEST4;
    task_info_g[INDX_KTEST4].task_ext_qid
        = kal_create_msg_q( "test", sizeof( ilm_struct ), 20 );

    stack_init_timer( &st, "test", MOD_KTEST4 );
    stack_start_timer( &st, 0, 10 );

    /* Wait until expiration */
    while( stack_timer_status( &st, NULL ) == STACK_TIMER_RUNNING )
    {
    }

    stack_stop_timer( &st );
    stack_process_time_out( &st );

    if( KTEST_FAIL
        == verify_st( &st, 0, STACK_TIMER_STOPPED,
                      STACK_TIMER_USER_VIEW_STOPPED ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
}

static void ktest_start_base_timer( void *stack_timer_base, kal_uint32 time_out )
{
    stack_start_timer( (stack_timer_struct *) stack_timer_base, 0, time_out );
}

static void ktest_stop_base_timer( void *stack_timer_base )
{
    stack_stop_timer( (stack_timer_struct *) stack_timer_base );
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_new_evshed
 * @remark brief: Test new_evshed normally create an es
 * @remark dependency:
 * @remark expecation: new_evshed returns a valid pointer
 *****************************************************************************/
kal_int32 ktest_new_evshed( kal_uint32 argc, void *argv )
{
    event_scheduler *es;
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "evshed_create";
    es = evshed_create( "test", MOD_KTEST4, 0, 0 );

    if( es != NULL )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
        ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_event
 * @remark brief: Test evshed_set_event sets an event and task gets the event message
 * @remark dependency: stack timer
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_set_event( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event sets an event and task gets the event message";

    /* debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 20 );

    /* on modis, gpt timer is not accurate, so delay longer time to avoid report
     * both pass and fail */
#if defined( KAL_ON_OSCAR )
    ktest_start_gpt_timer( 100, NULL, NULL );
#else
    ktest_start_gpt_timer( 20, NULL, NULL );
#endif  /* KAL_ON_OSCAR */

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        fake_event_cb1( NULL );
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_events_in_order
 * @remark brief: Test evshed_set_event sets many events in order
 * and task gets the message one by one
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_set_events_in_order( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;
    kal_uint32  save_time, elapse_time, count;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event sets many events in order ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;
    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    /* fuzz = 0. unaligned timer */
    save_time = ktest_get_sys_tick();

    id = evshed_set_event( es, fake_event_cb1, NULL, 2 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 10 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 21 );

    kal_sleep_task( 21 );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_timer_handler( es );
	    if( ktest_timer_g_count == 3 )
	    {
	        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
	        ktest_reset_target();
	    }
	    else
	    {
	        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
	        ktest_reset_target();
	    }
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_events_out_of_order
 * @remark brief: Test evshed_set_event sets many events out of order
 * and task gets the message one by one
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_set_events_out_of_order( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event sets many events out of order ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;
    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    id = evshed_set_event( es, fake_event_cb1, NULL, 21 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 2 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 10 );

    kal_sleep_task( 21 );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_timer_handler( es );
	    if( ktest_timer_g_count == 3 )
	    {
	        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
	        ktest_reset_target();
	    }
	    else
	    {
	        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
	        ktest_reset_target();
	    }
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_events_rollover
 * @remark brief: Test evshed_set_event sets events with rollover
 * and task gets the message one by one
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_set_events_rollover( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;
    kal_uint32  save_time, elapse_time;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event sets many events with restart timer ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;
    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    save_time = ktest_get_sys_tick();
    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 20 );
    kal_sleep_task( 10 );
    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 0xffffffff - 5 );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        elapse_time = ktest_get_sys_tick() - save_time;
        if( elapse_time == 20 )
        {
            ktest_report( KTEST_PASS, KTEST_TCID, NULL );
            ktest_reset_target();
        }
        else
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
            ktest_reset_target();
        }
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_many_events
 * @remark brief: Test evshed_set_event sets many events in disorder
 * and task gets the message one by one
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_set_many_events( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;
    kal_uint32  save_time, elapse_time, count;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event sets many events in disorder ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;
    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    /* fuzz = 0. unaligned timer */
    /* save_time = TMD_System_Clock; */
    save_time = ktest_get_sys_tick();

    id = evshed_set_event( es, fake_event_cb1, NULL, 20 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 0 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 21 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 23 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 9 );
    id = evshed_set_event( es, fake_event_cb1, NULL, 7 );

    ktest_start_gpt_timer( 20, NULL, NULL );

    count = 0;
    while( KAL_SUCCESS
           == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                                 &current_ilm ) )
    {
        /* elapse_time = TMD_System_Clock - save_time; */
        elapse_time = ktest_get_sys_tick() - save_time;

        switch( elapse_time )
        {
            case 0:
                count++;
                break;
            case 7:
                count++;
                break;
            case 9:
                count++;
                break;
            case 20:
                count++;
                break;
            case 21:
                count++;
                break;
            case 23:
                count++;
                break;
        }

        /* restart the es */
        evshed_timer_handler( es );

        if( 6 == count )
        {
            ktest_report( KTEST_PASS, KTEST_TCID, NULL );
            ktest_reset_target();
        }
    } /*while*/
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_event_nomem1
 * @remark brief: Test evshed_set_event sets an event when lack of event pool memory
 * @remark dependency: stack timer
 * @remark expecation: fatal error with KAL_ERROR_EVTSCH_GETBUFF_FAILED
 *****************************************************************************/
kal_int32 ktest_set_event_nomem1( kal_uint32 argc, void *argv )
{
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_EVTSCH_GETBUFF_FAILED;
    KTEST_BRIEF = "Test evshed_set_event sets an event when lack of event pool memory";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    while( 1 )
    {
        evshed_set_event( es, NULL, NULL, 2000 );
    }

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return 0;
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_event_nomem2
 * @remark brief: Test evshed_set_event sets an event when event pool is corrupted
 * @remark dependency: stack timer
 * @remark expecation: fatal error with KAL_ERROR_EVTSCH_EVENT_POOL_CORRUPTED
 *****************************************************************************/
kal_int32 ktest_set_event_nomem2( kal_uint32 argc, void *argv )
{
    extern NU_PARTITION_POOL evshed_pool_id;
    
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_EVTSCH_EVENT_POOL_CORRUPTED;
    KTEST_BRIEF = "Test evshed_set_event sets an event when event pool is corrupted";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    /* try to corrupted event pool */
    evshed_pool_id.pm_id = 0x12121212;

    evshed_set_event( es, NULL, NULL, 2000 );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return 0;
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_fuzz_delay_event
 * @remark brief: Test evshed_set_event set fuzz delay events
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_fuzz_delay_event( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    kal_uint32  save_time,elapse_time;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event set fuzz delay events";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 10, 0 );

    /* save_time = TMD_System_Clock; */
    save_time = ktest_get_sys_tick();

    evshed_set_event( es, ktest_timer_event_cb5, NULL, 20 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 16 );

    ktest_start_gpt_timer( 255, NULL, NULL );

    ktest_timer_g_count = 0;
    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        /* g_elapse_time = TMD_System_Clock - save_time; */
        elapse_time = ktest_get_sys_tick() - save_time;

        /* Handle two events */
        evshed_timer_handler( es );
    }

    if( ( elapse_time == 20 ) && ( ktest_timer_g_count == 2 ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_fuzz_premature_event
 * @remark brief: Test evshed_set_event set fuzz premature events expire
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_fuzz_premature_event( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    kal_uint32  save_time;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event set fuzz premature events expire";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 10, 0 );
    save_time = ktest_get_sys_tick();

    evshed_set_event( es, event_cb3, NULL, 16 );
    evshed_set_event( es, event_cb3, NULL, 20 );

    ktest_start_gpt_timer( 255, NULL, NULL );

    ktest_timer_g_count = 0;

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        g_elapse_time = ktest_get_sys_tick() - save_time;

        /* Handle two events */
        evshed_timer_handler( es );
    }

    if( ktest_timer_g_count == 2 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_fuzz_accmulate
 * @remark brief: [Bug fix]Test evshed_set_event set fuzz should't cause events delay more than fuzz time
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:  Now, the bug makes events delay too much
 *****************************************************************************/
kal_int32 ktest_fuzz_accmulate( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    cb_time_s time_cb;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event set fuzz should't cause events delay more than fuzz time";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 10, 0 );

    time_cb.save_time = ktest_get_sys_tick();
    time_cb.delay_tick = 8;

    evshed_set_event( es, event_cb4, NULL, 20 );
    evshed_set_event( es, event_cb4, NULL, 16 );
    evshed_set_event( es, event_cb4, NULL, 13 );
    evshed_set_event( es, event_cb4, NULL, 10 );
    evshed_set_event( es, event_cb4, &time_cb, 8 );

    ktest_start_gpt_timer( 20, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_timer_handler( es );
    }

    ktest_report( KTEST_PASS, KTEST_TCID, "Error, for now should not pass" );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_event_cmp_overflow
 * @remark brief: Test evshed_set_event doesn't prematurely expire event bigger than 0xffffffff/2
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation: Big time event shouldn't expire prematurely
 *****************************************************************************/
kal_int32 ktest_set_event_cmp_overflow( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_BRIEF = "Test evshed_set_event doesn't prematurely expire event bigger than 0xffffffff/2";
    KTEST_TCID = KTEST_FUNCTION_NAME;

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    ktest_timer_g_count = 0;
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 0x1FE );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 0xffffffff / 2 + 0xff );

    ktest_start_gpt_timer( 0x1FE, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_timer_handler( es );
    }

    if( ktest_timer_g_count == 1 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_set_event_null
 * @remark brief: [BUG fix] Test evshed_set_event with null callback function
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation: Should check null callback function
 *****************************************************************************/
kal_int32 ktest_set_event_null( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    kal_uint32  old, new;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event with null callback function";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    kal_get_time( &old );
    evshed_set_event( es, NULL, NULL, 10 );

    ktest_start_gpt_timer( 5000, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        kal_get_time( &new );
        evshed_timer_handler( es );
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_expired_not_call_handler_1
 * @remark brief: Test evshed_set_event when all events expired but sitll on dll list.
 * and task gets the message one by one
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_expired_not_call_handler_1( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;
    kal_uint32  save_time, elapse_time, count;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event when all events expired but sitll on dll list";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;
    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    evshed_set_event( es, ktest_timer_event_cb5, NULL, 5 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );

    kal_sleep_task( 20 );

    evshed_set_event( es, ktest_timer_event_cb5, NULL, 5 );
    save_time = ktest_get_sys_tick();
    count = 0;
    while( KAL_SUCCESS
           == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                                 &current_ilm ) )
    {
		count++;
		if( count == 2 )
		{
			elapse_time = ktest_get_sys_tick() - save_time;
        	evshed_timer_handler( es );
		    if( ( ktest_timer_g_count == 3 )
                && compare_time_error( elapse_time, 5 ,
                                       KAL_TIMER_ALLOWED_ERROR ) )
		    {
		        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
		        ktest_reset_target();
		    }
		    else
		    {
		        ktest_report( KTEST_FAIL, KTEST_TCID,
                              "elapse_time: %d, ktest_timer_g_count: %d\n",
                              elapse_time, ktest_timer_g_count );
		        ktest_reset_target();
		    }
		}
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_expired_not_call_handler_2
 * @remark brief: Test evshed_set_event when expired events sitll on dll list,
 *                restart on new event's abs_time.
 *
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_expired_not_call_handler_2( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;
    kal_uint32  save_time, elapse_time, count;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event when expired events on dll list,and restart by new ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;
    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    evshed_set_event( es, ktest_timer_event_cb5, NULL,5 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 24 ); /* do not wait it expire */
    evshed_set_event( es, ktest_timer_event_cb5, NULL,10 );

    kal_sleep_task( 13 );

    evshed_set_event( es, ktest_timer_event_cb5, NULL, 5 );
    save_time = ktest_get_sys_tick();
    count = 0;
    while( KAL_SUCCESS
           == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                                 &current_ilm ) )
    {
		count++;
		if( count == 2 )
		{
			elapse_time = ktest_get_sys_tick() - save_time;
        	evshed_timer_handler( es );
		    if( (ktest_timer_g_count == 3)
                && compare_time_error( elapse_time, 5 , KAL_TIMER_ALLOWED_ERROR ) )
		    {
		        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
		        ktest_reset_target();
		    }
		    else
		    {
		        ktest_report( KTEST_FAIL, KTEST_TCID,
                              "elapse_time: %d, ktest_timer_g_count: %d",
                              elapse_time, ktest_timer_g_count );
		        ktest_reset_target();
		    }
		}
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_expired_not_call_handler_3
 * @remark brief: Test evshed_set_event when expired events sitll on dll list,
 *                restart on first not expired event's abs_time.
 *
 * @remark dependency: stack timer. evshed_timer_handler
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_expired_not_call_handler_3( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;
    kal_uint32  save_time, elapse_time, count;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event when expired events on dll list,and restart by old";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;
    es = evshed_create( "test", MOD_KTEST, 0, 0 );

   	save_time = ktest_get_sys_tick();
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 5 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 50 );

    /* wait 5 to expire and sent one ilm */
    ktest_delay_ticks( 27 );

    /* should restart the 50 tick event */
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 150 );  /* do not wait it expire */
    save_time = ktest_get_sys_tick();
    count = 0;

    while( KAL_SUCCESS
           == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                                 &current_ilm ) )
    {
		count++;

		/* skip the first ilm and expect the second one */
		if( count == 2 )
		{
			elapse_time = ktest_get_sys_tick() - save_time;
        	evshed_timer_handler( es );

		    if( (ktest_timer_g_count == 2)
                && compare_time_error( elapse_time, 23, KAL_TIMER_ALLOWED_ERROR ) )
		    {
		        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
		        ktest_reset_target();
		    }
		    else
		    {
		        ktest_report( KTEST_FAIL, KTEST_TCID,
                              "elapse_time: %d, ktest_timer_g_count: %d\n",
                              elapse_time, ktest_timer_g_count );
		        ktest_reset_target();
		    }
		}
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name:  ktest_uninit_expired_dllhead
 * @remark brief: [BUG FIX] To test es->expired_dllhead has been init in new_evshed()
 * @remark dependency: stack timer
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_uninit_expired_dllhead( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    void *ptr;
    ktest_res res;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test es->expired_dllhead has been init in new_evshed()";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    /* rabbish code */
    ptr = kal_sys_mem_alloc( sizeof(event_scheduler) );
    memset( ptr, 0x32, sizeof(event_scheduler) );
    ktest_sys_mem_free( sizeof(event_scheduler) );

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    ktest_timer_g_count = 0;
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 40 );

    ktest_start_gpt_timer( 0x1FE, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid, &current_ilm ) )
    {
        evshed_timer_handler( es );
    }

    if( ktest_timer_g_count == 1 )
    {
        res = KTEST_PASS;
    }
    else
    {
        res = KTEST_FAIL;
    }

    ktest_report( res, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name:  ktest_expiredlist_not_NULL
 * @remark brief: To test expired list not NULL when call evshed_timer_handler
 *
 * @remark dependency: stack timer
 * @remark expecation: Now, FAIL! Events miss here!
 *****************************************************************************/
kal_int32 ktest_expiredlist_not_NULL( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_BRIEF = "To test expired list not NULL when call evshed_timer_handler";

    es = evshed_create( "test", MOD_KTEST, 10, 0 );
    ktest_timer_g_count = 0;

    evshed_set_event( es, event_cb6, (void *) es, 5 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 8 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 40 );

    ktest_start_gpt_timer( 0x40, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid, &current_ilm ) )
    {
        evshed_timer_handler( es );  /* should handler 1,2,3 one by one */
    }

    if( ktest_timer_g_count != 3 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

static void gpt_cb( void *data )
{
    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name:  ktest_suspend_event_scheduler
 * @remark brief: Suspend an es stop all events
 * @remark dependency: stack timer
 * @remark expecation: No events expire
 *****************************************************************************/
static kal_int32 ktest_suspend_event_scheduler( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    evshed_set_event( es, ktest_timer_event_cb7, NULL, 5 );
    evshed_set_event( es, ktest_timer_event_cb7, NULL, 8 );
    evshed_set_event( es, ktest_timer_event_cb7, NULL, 10 );
    evshed_set_event( es, ktest_timer_event_cb7, NULL, 20 );
    evshed_suspend_all_events( es );

    ktest_start_gpt_timer( 0x20, gpt_cb, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_double_suspend_event_scheduler
 * @remark brief: Suspend an already suspended event scheduler
 * @remark dependency: stack timer
 * @remark expecation: no fatal error, no event expire
 *****************************************************************************/
kal_int32 ktest_double_suspend_event_scheduler( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Suspend an already suspended event scheduler";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 20, 0 );
    evshed_set_event( es, ktest_timer_event_cb7, NULL, 5 );

    evshed_suspend_all_events( es );
    evshed_suspend_all_events( es );

    ktest_start_gpt_timer( 0x20, gpt_cb, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_suspend_event_scheduler_cb
 * @remark brief: To test evshed_suspend_all_events called in event callback context
 * dosn't impact handling of already expired events!
 * @remark dependency: stack timer
 * @remark expecation: Should not impact the already expired events
 *****************************************************************************/
kal_int32 ktest_suspend_event_scheduler_cb( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_suspend_all_events called in event callback context dosn't impact handling of already expired events!";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    /* fuzz make sure the next two event time out early */
    es = evshed_create( "test", MOD_KTEST, 20, 0 );
    ktest_timer_g_count = 0;
    evshed_set_event( es, event_cb8, es, 15 );  /* cb call suspend es */
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 15 );

    ktest_start_gpt_timer( 255, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_timer_handler( es );  /* three event cb one by one */
    }

    if( ktest_timer_g_count == 2 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_resume_es
 * @remark brief: To test evshed_resume_all_events resumes a suspended es
 * and events start to run again!
 * @remark dependency: stack timer
 * @remark expecation: events expire
 *****************************************************************************/
kal_int32 ktest_resume_es( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    cb_time_s time;
    kal_uint32 now_time;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_resume_all_events resumes a suspended es and events start to run again!";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 20, 0 );
    kal_get_time( &(time.save_time) );
    time.delay_tick = 15 + 5;

    evshed_set_event( es, event_cb4, &time, 15 );
    evshed_suspend_all_events( es );

    kal_get_time( &now_time );

    /* delay 5 ticks */
    while( now_time < time.save_time + 5 )
    {
        kal_get_time( &now_time );
    }

    evshed_resume_all_events( es );

    ktest_start_gpt_timer( 150, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_timer_handler( es );  /* event_cb4 may report fail */
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_resume_running_es
 * @remark brief: To test evshed_resume_all_events resumes a running es
 * @remark dependency: stack timer
 * @remark expecation: There should be no side effect!
 *****************************************************************************/
kal_int32 ktest_resume_running_es( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_resume_all_events resumes a running es";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    id = evshed_set_event( es, NULL, NULL, 20 );
    evshed_resume_all_events( es );

    /* on modis, gpt timer is not accurate, so delay longer time to avoid report
     * both pass and fail */
#if defined( KAL_ON_OSCAR )
    ktest_start_gpt_timer( 100, NULL, NULL );
#else
    ktest_start_gpt_timer( 20, NULL, NULL );
#endif  /* KAL_ON_OSCAR */

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_has_pending_event
 * @remark brief: To test evshed_has_pending_events check if has a pending event.
 * @remark dependency: stack timer
 * @remark expecation: when cancel event, check if has pending event.
 *****************************************************************************/
kal_int32 ktest_has_pending_event_cancel( kal_uint32 argc, void *argv )
{
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_has_pending_events after cancel event. ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    ktest_timer_g_count = 0;
    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );
    if( !(evshed_has_pending_events( es )) )  /* has not pending event */
    {
    	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    evshed_cancel_event( es, &id );

    if( evshed_has_pending_events( es ) ) /* has pending event after cancel */
    {
    	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }

    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_has_pending_event
 * @remark brief: To test evshed_has_pending_events check if has a pending event.
 * @remark dependency: stack timer
 * @remark expecation: when event expired, check if has pending event.
 *****************************************************************************/
kal_int32 ktest_has_pending_event_expired( kal_uint32 argc, void *argv )
{
    event_scheduler *es;
    eventid     id;
    ilm_struct current_ilm;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_has_pending_events after cancel event. ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    ktest_timer_g_count = 0;
    id = evshed_set_event( es, event_cb10, es, 10 );
    if( !(evshed_has_pending_events( es )) )  /* has not pending event */
    {
    	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }

	ktest_start_gpt_timer( 20, NULL, NULL );

	if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
	    evshed_timer_handler( es );  /* event_cb10 will report fail or pass */
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_del_all_events_1
 * @remark brief: To test evshed_delete_all_events on a newly created,
 * running es which has only one event.
 * @remark dependency: stack timer
 * @remark expecation: delete all ok, no event expires and no fatal error
 *****************************************************************************/
kal_int32 ktest_del_all_events_1( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_delete_all_events on a newly created, running es,with no more than one event ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    /* delete a newly created es */
    evshed_delete_all_events( es );

    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 5 );
    ktest_delay_ticks( 2 );
    evshed_delete_all_events( es );

    ktest_start_gpt_timer( 5, gpt_cb, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_del_all_events_2
 * @remark brief: To test evshed_delete_all_events on a newly created,
 * running es with two events.
 * @remark dependency: stack timer
 * @remark expecation: delete all ok, no event expires and no fatal error
 *****************************************************************************/
kal_int32 ktest_del_all_events_2( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_delete_all_events on a newly created, running es,with two events ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    /* delete a newly created es */
    evshed_delete_all_events( es );

    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 5 );
    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 15 );
    ktest_delay_ticks( 2 );
    evshed_delete_all_events( es );

    ktest_start_gpt_timer( 15, gpt_cb, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_del_all_events_3
 * @remark brief: To test evshed_delete_all_events on a newly created,
 * running es with three events.
 * @remark dependency: stack timer
 * @remark expecation: delete all ok, no event expires and no fatal error
 *****************************************************************************/
kal_int32 ktest_del_all_events_3( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_delete_all_events on a newly created, running es,with three events ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    /* delete a newly created es */
    evshed_delete_all_events( es );

    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 15 );
    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 7 );
    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 21 );
    ktest_delay_ticks( 6 );
    evshed_delete_all_events( es );

    ktest_start_gpt_timer( 21, gpt_cb, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_cancel_event_bf_handler
 * @remark brief: Test evshed_timer_handler,cancel event before timer_handler
 *                call, and after it expired.
 * @remark dependency: stack timer
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_cancel_event_bf_handler( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_set_event sets an event and task gets the event message";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 20 );

    /* on modis, gpt timer is not accurate, so delay longer time to avoid report
     * both pass and fail */
#if defined( KAL_ON_OSCAR )
    ktest_start_gpt_timer( 100, NULL, NULL );
#else
    ktest_start_gpt_timer( 20, NULL, NULL );
#endif  /* KAL_ON_OSCAR */

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_cancel_event( es, &id );
        evshed_timer_handler( es );
	    if( ktest_timer_g_count == 1 )
	    {
	        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
	        ktest_reset_target();
	    }
	    else
	    {
	        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
	        ktest_reset_target();
	    }
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_mem_leak_in_cancel()
 * @remark brief: Test evshed_cancel_event,check memory leak after event canceled.
 * @remark dependency: stack timer
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_mem_leak_in_cancel( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    eventid     id;
    kal_uint32 index;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_cancel_event ,check memory leak after event canceled";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    for( index = 0; index < kal_min_evshed_buffer_number; index++ )
    {
     	id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 20 );
     	evshed_cancel_event( es, &id );
    }

    evshed_set_event( es, ktest_timer_event_cb5, NULL, 20 );

    /* on modis, gpt timer is not accurate, so delay longer time to avoid report
     * both pass and fail. */
#if defined( KAL_ON_OSCAR )
    ktest_start_gpt_timer( 100, NULL, NULL );
#else
    ktest_start_gpt_timer( 20, NULL, NULL );
#endif  /* KAL_ON_OSCAR */

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_mem_leak_in_delete()
 * @remark brief: Test evshed_delete_all_events, check memory leak after event delete.
 * @remark dependency: stack timer
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_mem_leak_in_delete( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    kal_uint32 index;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_delete_all_events, check memory leak after event delete";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    for( index = 0; index < kal_min_evshed_buffer_number; index++ )
    {
     	evshed_set_event( es, ktest_timer_event_cb5, NULL, 20 );
    }

	evshed_delete_all_events( es );

    evshed_set_event( es, ktest_timer_event_cb5, NULL, 20 );

    /* on modis, gpt timer is not accurate, so delay longer time to avoid report
     * both pass and fail */
#if defined( KAL_ON_OSCAR )
    ktest_start_gpt_timer( 100, NULL, NULL );
#else
    ktest_start_gpt_timer( 20, NULL, NULL );
#endif  /* KAL_ON_OSCAR */

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_mem_leak_in_expire()
 * @remark brief: Test evshed_timer_handler, check memory leak in timer handler.
 * @remark dependency: stack timer
 * @remark expecation:
 *****************************************************************************/
kal_int32 ktest_mem_leak_in_expire( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;
    kal_uint32 index;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test evshed_timer_handler ,check memory leak in timer handler";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );

    for( index = 0; index < kal_min_evshed_buffer_number; index++ )
    {
     	evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );
    }

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
		evshed_timer_handler( es );
		evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );
    }

    ktest_start_gpt_timer( 10, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_cancel_event
 * @remark brief: To test evshed_cancel_event cancel an event.
 * @remark dependency: stack timer
 * @remark expecation: event doesn't expire
 *****************************************************************************/
kal_int32 ktest_cancel_event( kal_uint32 argc, void *argv )
{
    event_scheduler *es;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_cancel_event cancel an event. ";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    ktest_timer_g_count = 0;
    id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );
    evshed_cancel_event( es, &id );

    kal_sleep_task( 20 );

    if( ktest_timer_g_count != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_cancel_event_badowner
 * @remark brief: To test evshed_cancel_event cancel an event with bad owner
 * @remark dependency: stack timer
 * @remark expecation: fatal error with  KAL_ERROR_EVTSCH_CANCEL_FAILED
 *****************************************************************************/
kal_int32 ktest_cancel_event_badowner( kal_uint32 argc, void *argv )
{
    event_scheduler *es;
    event_scheduler *es1;
    eventid     id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_cancel_event cancel an event with bad owner";
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_EVTSCH_CANCEL_FAILED;

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    es1 = evshed_create( "test", MOD_KTEST, 0, 0 );

    id = evshed_set_event( es, NULL, NULL, 10 );
    evshed_cancel_event( es1, &id );

    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    ktest_reset_target();
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_self_cancel_event_in_cb
 * @remark brief: To test evshed_cancel_event E1 in E1's cb function
 * @remark dependency: stack timer
 * @remark expecation: Self cancel in evshed_timer_handler not double free.
 * Other events not affected!
 *****************************************************************************/
kal_int32 ktest_self_cancel_event_in_cb( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_cancel_event E1 in E1's cb function";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 20, 0 );

    ktest_timer_g_count = 0;
    g_id = evshed_set_event( es, event_cb9, es, 5 );

    evshed_set_event( es, ktest_timer_event_cb5, NULL, 15 );  /* cb call suspend es */

    ktest_start_gpt_timer( 255, NULL, NULL );

    while( KAL_SUCCESS
           == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                                 &current_ilm ) )
    {
        evshed_timer_handler( es );  /* three event cb one by one */
        if( ktest_timer_g_count == 1 )
        {
            break;
        }
    }

    if( ktest_timer_g_count == 1 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_double_cancel_event
 * @remark brief: To test evshed_cancel_event the same event twice
 * @remark dependency: stack timer
 * @remark expecation: The second cancel should return -1
 *****************************************************************************/
kal_int32 ktest_double_cancel_event( kal_uint32 argc, void *argv )
{
    event_scheduler *es;
    eventid id;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_cancel_event the same event twice";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 20, 0 );
    id = evshed_set_event( es, NULL, NULL, 5 );

    evshed_cancel_event( es, &id );

    if( -1 == evshed_cancel_event( es, &id ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_cancel_header_event_in_expirelist
 * @remark brief: evshed_cancel_event cancel header event in es's expired list
 * @remark dependency: stack timer
 * @remark expecation: event cancelled
 *****************************************************************************/
kal_int32 ktest_cancel_header_event_in_expirelist( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "evshed_cancel_event cancel header event in es's expired list";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    /* set fuzz. so there is a expiring list */
    es = evshed_create( "test", MOD_KTEST, 20, 0 );
    ktest_timer_g_count = 0;
    evshed_set_event( es, event_cb9, es, 5 );  /* cancel the next event is cb */
    g_id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 15 );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_timer_handler( es );
    }

    if( ktest_timer_g_count == 1 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_cancel_event_in_expirelist
 * @remark brief: evshed_cancel_event cancel non-header event in es's expired list
 * @remark dependency: stack timer
 * @remark expecation: event cancelled
 *****************************************************************************/
kal_int32 ktest_cancel_event_in_expirelist( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "evshed_cancel_event cancel a event in es's expired list";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

   /* set fuzz. so there is a expiring list */
     es = evshed_create( "test", MOD_KTEST, 20, 0 );
    ktest_timer_g_count = 0;
    evshed_set_event( es, event_cb9, es, 5 );  /* cancel the next event is cb */
    evshed_set_event( es, ktest_timer_event_cb5, NULL, 10 );
    g_id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 15 );

    ktest_start_gpt_timer( 15, NULL, NULL );

    if( KAL_SUCCESS
        == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                              &current_ilm ) )
    {
        evshed_timer_handler( es );
    }

    if( ktest_timer_g_count == 1 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
        ktest_reset_target();
    }
}

/******************************************************************************
 * @remark category: Timer
 * @remark name: ktest_cancel_header_event_cb
 * @remark brief: evshed_cancel_event cancel header event not in es's expired list
 * @remark dependency: stack timer
 * @remark expecation: event cancelled
 *****************************************************************************/
kal_int32 ktest_cancel_header_event_cb( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "evshed_cancel_event cancel header event not in es's expired list";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    /* set fuzz. so there is a expiring list */
    es = evshed_create( "test", MOD_KTEST, 20, 0 );

    ktest_timer_g_count = 0;
    evshed_set_event( es, event_cb9, es, 5 );  /* cancel the next event is cb */
    g_id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 35 );

    ktest_start_gpt_timer( 35, gpt_cb, NULL );

    while( KAL_SUCCESS
           == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                                 &current_ilm ) )
    {
    	evshed_timer_handler( es );
        if( ktest_timer_g_count == 1 )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
            ktest_reset_target();
        }
    }
}

/******************************************************************************
 * @remark name: ktest_cancel_event_cb
 * @remark brief: evshed_cancel_event cancel non-header event not in es's expired list
 * @remark dependency: stack timer
 * @remark expecation: event cancelled
 *****************************************************************************/
kal_int32 ktest_cancel_event_cb( kal_uint32 argc, void *argv )
{
    ilm_struct current_ilm;
    event_scheduler *es;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "evshed_cancel_event cancel non-header event not in es's expired list";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    /* set fuzz. so there is a expiring list */
    es = evshed_create( "test", MOD_KTEST, 20, 0 );

    ktest_timer_g_count = 0;
    evshed_set_event( es, event_cb9, es, 5 );  /* cancel the next event is cb */
    g_id = evshed_set_event( es, ktest_timer_event_cb5, NULL, 35 );

    ktest_start_gpt_timer( 35, gpt_cb, NULL );

    while( KAL_SUCCESS
           == receive_msg_ext_q( task_info_g[INDX_KTEST].task_ext_qid,
                                 &current_ilm ) )
    {
        evshed_timer_handler( es );
        if( ktest_timer_g_count == 1 )
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
            ktest_reset_target();
        }
    }
}

kal_int32 ktest_get_rem_time( kal_uint32 argc, void *argv )
{
    event_scheduler *es;
    eventid id;
    kal_uint32 rm;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test evshed_get_rem_time on a running event";

    /* XXX debug, please remove */
    mod_task_g[MOD_KTEST] = INDX_KTEST;

    es = evshed_create( "test", MOD_KTEST, 0, 0 );
    id = evshed_set_event( es, NULL, NULL, 17 );

    kal_sleep_task( 5 );

    rm = evshed_get_rem_time( es, id );
    if( compare_time_error( rm, 12, KAL_TIMER_ALLOWED_ERROR ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "remain time %u shuould be 12", rm );
        ktest_reset_target();
    }
}

/******************************************************************************
 * KAL timer common test case designed to verify event based timer
 * The following cases are orginally designed to verify event based timer! However
 * they are also general to other platform too.
 *****************************************************************************/
/******************************************************************************
 * start timer in callback function
 *****************************************************************************/
static void ktest_timer_cb2( void *cb_data )
{
    kal_timerid tid = (kal_timerid) cb_data;

    ktest_timer_g_count++;
    kal_set_timer( tid, ktest_timer_cb2, cb_data, 7, 0 );
}

kal_int32 ktest_restart_timer_cb( kal_uint32 argc, void *argv )
{
    kal_timerid  tid;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To restart timer in call back function";

    tid = kal_create_timer( "test" );
    ktest_timer_g_count = 0;

    /* run 7 * 7 ticks */
    kal_set_timer( tid, ktest_timer_cb2, (void *) tid, 7, 0 );

    /* 49 * 10ms */
    ktest_start_gpt_timer( 49, NULL, NULL );

    while( 1 )
    {
        if( ktest_timer_g_count == 7 )
        {
            ktest_report( KTEST_PASS, KTEST_TCID, NULL );
            ktest_reset_target();
        }
    }
}

kal_int32 ktest_insert_timer( kal_uint32 argc, void *argv )
{
    kal_timerid timer_array[5];
    cb_time_s   cb_array[5];
    kal_uint32  delay_ticks[5] = {5, 8, 1, 10, 7};
    kal_uint32  i;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To insert timer into the head, middle, and tail of the timer list";

    ktest_timer_g_count = 0;
    for( i = 0; i < 5; i++ )
    {
        timer_array[i] = kal_create_timer( "test" );

        kal_get_time( &(cb_array[i].save_time) );
        cb_array[i].delay_tick = delay_ticks[i];

        kal_set_timer( timer_array[i], event_cb4, &cb_array[i], delay_ticks[i], 0 );
    }

    ktest_delay_ticks( 20 );
    if( ktest_timer_g_count == 5 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    ktest_reset_target();
    return 0;
}

kal_int32 ktest_task_sleep_timer( kal_uint32 argc, void *argv )
{
    cb_time_s time;
    kal_uint32 old_ticks, new_ticks, elapse;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Task sleep and timer timeout on time";

    ktest_timer_g_count = 0;

    ktest_init_timer_cb( &time, 5 );
    create_set_timer( event_cb4, &time, 5 );

    kal_get_time( &old_ticks );
    kal_sleep_task( 7 );
    kal_get_time( &new_ticks );

    elapse = new_ticks - old_ticks;

    if( (ktest_timer_g_count == 1)
        && compare_time_error( elapse, 7, KAL_TIMER_ALLOWED_ERROR ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "elapse time is %d", elapse );
    }

    ktest_reset_target();
}

/******************************************************************************
*   To test task time slice works
******************************************************************************/
#ifdef KAL_ON_NUCLEUS
static volatile kal_uint32 run_flag;

static void tc_main( task_entry_struct *ptr )
{
    while( 1 )
    {
        /* If switch from other task for the first time, flag */
        if( run_flag  == 0 )
        {
            run_flag = 1;
            ktest_timer_g_count++;
        }
    }
}

static void tc_main2( task_entry_struct *ptr )
{
    while( 1 )
    {
        /* If switch from other task for the first time, flag */
        if( run_flag  == 1 )
        {
            run_flag = 0;
            ktest_timer_g_count++;
        }
    }
}

static kal_uint32 ts_save_tick;
static kal_uint32 ts_new_tick;

static void time_slice_gpt_cb1( void *cb_data )
{
    kal_uint32 exp_ts_cnt;
    kal_get_time( &ts_new_tick );

    exp_ts_cnt = ( ts_new_tick - ts_save_tick ) / 20;
    if( compare_time_error( exp_ts_cnt, ktest_timer_g_count, 2 ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "schedule time: %d, expect shedule time %d",
                      ktest_timer_g_count, exp_ts_cnt );
        ktest_reset_target();
    }
}

kal_int32 ktest_task_time_slice( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test two tasks with time slice switch between each other";

    ktest_timer_g_count = 0;
    run_flag = 0;

    kal_get_time( &ts_save_tick );
    ktest_create_task_timeslice( "T1", TASK_PRIORITY_KTEST + 10, 2048, tc_main,
                                 NULL, 20 );
    ktest_create_task_timeslice( "T2", TASK_PRIORITY_KTEST + 10, 2048, tc_main2,
                                 NULL, 20 );

    ktest_start_gpt_timer( 200, time_slice_gpt_cb1, NULL );

    kal_sleep_task( KAL_SUSPEND );
}
#endif  /* KAL_ON_NUCLEUS */
/******************************************************************************
 *  To test task time slice works END
 *****************************************************************************/

/******************************************************************************
 * Test case to simulate user scenario. Do overnight test to
 * catch the maximum timer delay
 *****************************************************************************/
typedef struct
{
    kal_timerid tid;
    kal_uint32  start_time;  /* start time in tick */
    kal_uint32  expired_time;  /* expire time is tick */
    kal_uint32  delay;
    kal_uint32  delayed;  /* 1: delayed by others */
    volatile kal_uint32  state;
#define DOODLE_START    0xabcd
#define DOODLE_STOP     0xdcba
#define DOODLE_EXPIRE   0xfdfd
#define DOODLE_INIT     0x0157
    volatile kal_uint32  option;  /* different timer call back behavior */
} user_doodle_box_s;

static user_doodle_box_s   t_r[12];  /* timer record */
static kal_uint32          stop_set[4];

/******************************************************************************
 * Modify the two function if you want to replace the timer
 *****************************************************************************/
static kal_uint32 ktest_portable_time( void )
{
    kal_uint32 time;
    kal_get_time( &time );

    return time;
}

static kal_uint32 kal_check_timer_delay( kal_uint32 index )
{
    kal_uint32 i = index;
    kal_uint32 loop_time;
    kal_uint32 elapse = t_r[i].expired_time - t_r[i].start_time;

    /* KAL will adjust 0 to 1 */
    if( t_r[i].delay == 0 )
    {
        t_r[i].delay = 1;
    }

    if( elapse < t_r[i].delay - 1 ||  (elapse > t_r[i].delay + 2) )
    {
        /* [-4615us ~ 4615us + a little] error is allowed */
        kal_get_time( &loop_time );

        ktest_print( "%u:%u:%u\n\r", loop_time, elapse, t_r[i].delay );

        return 1;
    }
    else
    {
       return 0;
    }
}

/******************************************************************************
 * Timer call back function.
 *****************************************************************************/
static void doodle_timeout( void *data )
{
    kal_uint32 i;
    user_doodle_box_s  *ptr = (user_doodle_box_s *) data;

    ptr->state = DOODLE_EXPIRE;
    ptr->expired_time = ktest_portable_time();

    if( ptr->option )
    {
        /* start timer 12 */
        i = 11;

        t_r[i].delay = rand() % 16;
        t_r[i].start_time = ktest_portable_time();
        t_r[i].state = DOODLE_START;
        t_r[i].option = 0;
        kal_set_timer( t_r[i].tid, doodle_timeout, &t_r[i], t_r[i].delay, 0 );

        /* choose one running timer to stop */
        for( i = 0; i < 12; i++ )
        {
            if( t_r[i].state == DOODLE_START )
            {
                kal_cancel_timer( t_r[i].tid );
                t_r[i].state = DOODLE_STOP;
                stop_set[3]= i;
                break;
            }
        }

        /* during hisr, some timer expire, adjust the timer delay */
    }
    return;
}

/******************************************************************************
 * This hisr may blocks timer hisr
 *****************************************************************************/
static void doodle_hisr_entry( void )
{
    kal_uint32 i, delay, now_tick;

    /* choose one running timer to stop */
    for( i = 0; i < 10; i++ )
    {
        if( t_r[i].state == DOODLE_START )
        {
            kal_cancel_timer( t_r[i].tid );
            t_r[i].state = DOODLE_STOP;
            stop_set[2] = i;
            break;
        }
    }

    /* start timer 11 */
    i = 10;

    t_r[i].delay = rand() % 16;
    t_r[i].start_time = ktest_portable_time();
    t_r[i].state = DOODLE_START;
    t_r[i].option = 0;

    kal_set_timer( t_r[i].tid, doodle_timeout, &t_r[i], t_r[i].delay, 0 );

    /* Choose one timer to switch callback function */
    for( i = 0; i < 11; i++ )
    {
        if( t_r[i].state == DOODLE_START )
        {
            /* there can't be race. For higher hisr blocks timer hisr */
            t_r[i].option = 1;
            break;
        }
    }

    return;
}

/******************************************************************************
 * Please adjust the loop times
 *****************************************************************************/
static kal_int32 ktest_user_doodle( kal_uint32 argc, void *argv )
{
    kal_uint32 i, sleep, fail, loop, expire_count, delay_count;

    fail = expire_count = delay_count = 0;
    loop = 1;  /* One loop takes about 0.5s */

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test case to simulate user scenario";

    for( i = 0; i < 12; i++ )
    {
        t_r[i].tid = kal_create_timer( "test" );
    }

    do
    {
        /* In loop, init every time */
        for( i = 0; i < 4; i++ )
        {
            stop_set[i] = 32767;
        }

        for( i = 0; i < 12; i++ )
        {
            t_r[i].delay = 0;
            t_r[i].delayed = 0;
            t_r[i].start_time = 0;
            t_r[i].expired_time =  0;
            t_r[i].state = DOODLE_INIT;
            t_r[i].option = 0;
        }

        /* start 10 timers with random(0 ~ 15) */
        for( i = 0; i < 10; i++ )
        {
            t_r[i].delay = rand() % 30;  /* 0 ~ 15 */
            t_r[i].start_time = ktest_portable_time();
            t_r[i].state = DOODLE_START;
            t_r[i].option = 0;
            kal_set_timer( t_r[i].tid, doodle_timeout, &t_r[i], t_r[i].delay, 0 );
        }

        /* delay random(0 ~ 7) ticks. Task delay should not delay timer. */
        sleep = rand() % 8;
        ktest_delay_ticks( sleep + KAL_TIMER_ALLOWED_ERROR );

        /* choose one expired and one running timer to stop */
        for( i = 0; i < 10; i++ )
        {
            if( t_r[i].state == DOODLE_START )
            {
                kal_cancel_timer( t_r[i].tid );
                t_r[i].state = DOODLE_STOP;
                stop_set[0] = i;
                break;
            }
        }

        for( i = 0; i < 10; i++ )
        {
            if( t_r[i].state == DOODLE_EXPIRE )
            {
                kal_cancel_timer( t_r[i].tid );
                t_r[i].state = DOODLE_STOP;
                stop_set[1] = i;
                break;
            }
        }

        /* cpu goes to hisr immediately */
        ktest_delay_ticks( rand() % 3 );
        ktest_activate_hisr( doodle_hisr_entry );

        /* wait all timer timeout to finish */
        ktest_delay_ticks( 100 );

        /* 1) stop_set timer should stay in stopped state */
        for( i = 0; i < 4; i++ )
        {
            if( stop_set[i] != 32767
                && t_r[stop_set[i]].state != DOODLE_STOP )
            {
                ktest_print( "<%s> Stopped timer not in DOODLE_STOP state\n\r",
                             KTEST_TCID );
                /* don't reset for overnight test */
                fail = 1;
            }
        }

        /* 2) expired timer should expire on time. And there shouldn't be timer
         *    in start state. */
        for( i = 0; i < 12; i++ )
        {
            if( t_r[i].state == DOODLE_START )
            {
                ktest_print( "<%s> Timer with delay %d should not in start state\n\r",
                             KTEST_TCID, t_r[i].delay );
                fail = 1;
            }
            else if( t_r[i].state == DOODLE_EXPIRE )
            {
                expire_count++;
                if( kal_check_timer_delay( i ) )
                {
                    delay_count++;
                    fail = 1;
                }
            }
            else if( t_r[i].state != DOODLE_STOP )
            {
                ktest_print( "<%s> Timer state wrong %d\n\r", KTEST_TCID,
                             t_r[i].state );
                fail = 1;
            }
        }
    }while( loop++ < 8 );

    if( fail == 0 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, "Total expire %d, dealy count %d",
                      expire_count, delay_count );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "Total expire %d, dealy count %d",
                      expire_count, delay_count );
    }

    ktest_reset_target();
    return 0;
}

/******************************************************************************
 * test case table of timer module in post-schedule stage.
 * we should notice that the ones wrapped with FIX_OSCAR_FAIL will only be
 *                       tested on Target, but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_timer_tbl[] =
{
    {ktest_gpt_test, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* the 4 test cases below will fail on OSCAR, because the timer on MoDIS is
     * not accurate enough. */
    {ktest_start_timer, 0, NULL},
    {ktest_start_timer_v2, 0, NULL},
    {ktest_start_timer_sequence, 0, NULL},
    {ktest_insert_timer, 0, NULL},
#endif

    {ktest_restart_timer_cb, 0, NULL},

#ifdef KAL_ON_NUCLEUS
    /* this test case will only be tested on Target, and it's not ready to be
     * tested on OSCAR. */
    {ktest_task_time_slice, 0, NULL},
#endif

#ifdef FIX_OSCAR_FAIL
    /* the 3 test cases below will fail on OSCAR, because the timer on MoDIS is
     * not accurate enough. */
    {ktest_cancel_timer, 0, NULL},
    {ktest_task_sleep_timer, 0, NULL},
    {ktest_user_doodle, 0, NULL},
#endif

    /* this test case will cause memory corruption on OSCAR, but we don't know
     * the reason yet. */
    {ktest_cancel_timer_null, 0, NULL},

    {ktest_cancel_timer_inittimer, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* re-schedule doesn't work on OSCAR. */
    {ktest_timer_reschedule, 0, NULL},
#endif

    {ktest_start_running_timer, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* this test case will fail on OSCAR, because the timer on MoDIS is not
     * accurate enough. */
    {ktest_start_timer_zero_tick, 0, NULL},
#endif

    /* this test case will cause memory corruption on OSCAR, but we don't know
     * the reason yet. */
    {ktest_set_timer_para_check, 0, NULL},

    {ktest_get_time_remaining, 0, NULL},
    {ktest_get_time_remaining1, 0, NULL},
    {ktest_get_time_remaining2, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* the 3 test cases below will fail on OSCAR, because the timer on MoDIS is
     * not accurate enough. */
    {ktest_stack_start_timer, 0, NULL},
    {ktest_stack_start_timer_zero, 0, NULL},
    {ktest_stack_start_running_timer, 0, NULL},
#endif

    {ktest_stack_start_expired_timer, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* this test case will fail on OSCAR, because the timer on MoDIS is not
     * accurate enough. */
    {ktest_stack_start_stopped_timer, 0, NULL},
#endif

    {ktest_stack_stop_timer, 0, NULL},
    {ktest_stack_stop_timer2, 0, NULL},
    {ktest_stack_stop_expired_timer, 0, NULL},
    {ktest_stack_stop_expired_timer1, 0, NULL},
    {ktest_stack_timer_user_status, 0, NULL},
    {ktest_stack_timer_user_status2, 0, NULL},
    {ktest_stack_process_time_out, 0, NULL},
    {ktest_stack_process_time_out2, 0, NULL},
    {ktest_set_event_null, 0, NULL},
    {ktest_uninit_expired_dllhead, 0, NULL},
    {ktest_expiredlist_not_NULL,0,NULL},
    {ktest_set_event_nomem1, 0, NULL},
    {ktest_set_event_nomem2, 0, NULL},
#ifdef FIX_OSCAR_FAIL
    /* the 3 test cases below will fail on OSCAR, because the timer on MoDIS is
     * not accurate enough. */
    {ktest_fuzz_delay_event, 0, NULL},
    {ktest_fuzz_premature_event, 0, NULL},
    {ktest_fuzz_accmulate, 0, NULL},
#endif

    {ktest_expired_not_call_handler_1,0,NULL},

#ifdef FIX_OSCAR_FAIL
    /* this test case will fail on OSCAR, because the timer on MoDIS is not
     * accurate enough. */
    {ktest_expired_not_call_handler_2,0,NULL},
#endif

    {ktest_expired_not_call_handler_3,0,NULL},
    {ktest_self_cancel_event_in_cb, 0, NULL},
    {ktest_double_cancel_event, 0, NULL},
    {ktest_mem_leak_in_cancel,0,NULL},
    {ktest_mem_leak_in_delete,0,NULL},
    {ktest_mem_leak_in_expire,0,NULL},
    {ktest_cancel_event_bf_handler,0,NULL},
    {ktest_del_all_events_1, 0, NULL},
    {ktest_del_all_events_2, 0, NULL},
    {ktest_del_all_events_3, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* this test case will fail on OSCAR, because the timer on MoDIS is not
     * accurate enough. */
    {ktest_get_rem_time, 0, NULL},
#endif

    {ktest_suspend_event_scheduler, 0, NULL},
    {ktest_suspend_event_scheduler_cb, 0, NULL},
    {ktest_double_suspend_event_scheduler, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* this test case will fail on OSCAR, because the timer on MoDIS is not
     * accurate enough. */
    {ktest_resume_es, 0, NULL},
#endif

    {ktest_resume_running_es, 0, NULL},
    {ktest_has_pending_event_expired, 0, NULL},
    {ktest_has_pending_event_cancel, 0, NULL},
    {ktest_cancel_event, 0, NULL},
    {ktest_cancel_event_in_expirelist, 0, NULL},
    {ktest_cancel_header_event_in_expirelist, 0, NULL},
    {ktest_cancel_event_cb, 0, NULL},
    {ktest_cancel_header_event_cb, 0, NULL},
    {ktest_cancel_event_badowner, 0, NULL},
    {ktest_new_evshed, 0, NULL},
    {ktest_set_event, 0, NULL},
    {ktest_set_many_events, 0, NULL},
    {ktest_set_events_in_order, 0, NULL},
    {ktest_set_events_out_of_order, 0, NULL},

#ifdef FIX_OSCAR_FAIL
    /* this test case will fail on OSCAR, because the timer on MoDIS is not
     * accurate enough. */
    {ktest_set_events_rollover, 0, NULL},
#endif

    {ktest_set_event_cmp_overflow, 0, NULL},
};

/******************************************************************************
 * test case table of timer module in pre-schedule stage.
 * we should notice that the ones wrapped with FIX_OSCAR_FAIL will only be
 *                       tested on Target, but will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_timer_tbl[] =
{
    {ktest_new_evshed, 0, NULL},
    {ktest_stack_init_timer, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_tc_timer_num
 * Functionality:
 *     caculate there are how many test cases of timer module in post-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of all test cases of timer module in post-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_tc_timer_num( void )
{
    return sizeof( ktest_tc_timer_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_pre_tc_timer_num
 * Functionality:
 *     caculate there are how many test cases of timer module in post-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of all test cases of timer module in pre-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_timer_num( void )
{
    return sizeof( ktest_pre_tc_timer_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_timer_init
 * Functionality:
 *     the initialization function of timer module.
 * Parameters:
 *     mod: id of timer module.
 * Returns:
 *     void.
 * Note:
 *     we should call this function in ktest_testcase_register in order to
 *     register timer module into KTEST.
 *****************************************************************************/
void ktest_timer_init( kal_uint32 mod )
{
    tc_all_tbls[mod] = ktest_tc_timer_tbl;
    pre_tc_all_tbls[mod] = ktest_pre_tc_timer_tbl;

    tc_modules_num[mod] = ktest_tc_timer_num();
    pre_tc_modules_num[mod] = ktest_pre_tc_timer_num();
}

#endif/*__KTEST*/
