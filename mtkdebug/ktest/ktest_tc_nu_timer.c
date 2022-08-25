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
 *   ktest_tc_nu_timer.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Write timer test case dependent on Nucleus RTOS here
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined (__KTEST__) && defined(KAL_ON_NUCLEUS) && \
            defined(__EVENT_BASED_TIMER__) && defined(__NUCLEUS_VERSION_2__)
 
#include "ktest_lib_timer.h"
#include "ostd_public.h"
#include "us_timer.h"
#include "ktest_interface.h"
#include "tc_defs.h"
#include "tm_defs.h"

/******************************************************************************
 * define some facilities function
 *****************************************************************************/
static kal_uint32 ktest_get_afn( void )
{
    OSTD_FRM_INFO_T ostd_info;
    OSTD_GetCurrFrm( &ostd_info );

#ifdef KTEST_DEBUG
    ktest_print( "[INFO] read afn is: %d\n\r", ostd_info.curr_afn );
#endif

    return ostd_info.curr_afn;
}

static kal_uint32 ktest_get_ufn( void )
{
    OSTD_FRM_INFO_T ostd_info;
    OSTD_GetCurrFrm( &ostd_info );

#ifdef KTEST_DEBUG
    ktest_print( "[INFO] read ufn is: %d\n\r", ostd_info.curr_ufn );
#endif

    return ostd_info.curr_ufn;
}

/******************************************************************************
 *  To test delays ticks and start timers in callback or hisr context
 *****************************************************************************/
static kal_timerid timer_array[3];
static void (*cb_func)( void ) = NULL;
static kal_hisrid timer_hisrid = NULL;

void cb_func_start( void )
{
    kal_uint32  delay_ticks[3] = {1, 1, 7};
    kal_uint32  i;

    ktest_delay_ticks( 3 );

    for( i = 0; i < 3; i++ )
    {
        ktest_init_timer_cb( &global_cb_array[i], delay_ticks[i] );

        kal_set_timer( timer_array[i], event_cb4,
                       (void *) &global_cb_array[i], delay_ticks[i], 0 );
    }
}

void cb_func_cancel( void )
{
   kal_cancel_timer( timer_array[0] );
   kal_cancel_timer( timer_array[1] );
   kal_cancel_timer( timer_array[2] );
}

/******************************************************************************
 * activate hisr entry point
 *****************************************************************************/
static void timer_hisr_func1( void )
{
    if( cb_func )
    {
        (*cb_func)();
    }

    return;
}

/******************************************************************************
 * lisr to activate hisr
 *****************************************************************************/
static void sw_lisr_func( void )
{
    kal_activate_hisr( timer_hisrid );
    ktest_deactive_sw_handler();

    return;
}

/******************************************************************************
 * the context is timer hisr
 *****************************************************************************/
static void timer_cb3( void *timer_param )
{
    kal_uint32 *nu_ptr = (kal_uint32 *) timer_param;

    ktest_timer_g_count++;
    if( *nu_ptr == 0 )
    {
        (*cb_func)();
    }
    else
    {
       ktest_sw_intr_handler( sw_lisr_func );
       ktest_active_sw_handler();
    }

    return;
}

static void internal_start_timer( kal_uint32 context )
{
    kal_timerid  tid, tid2;
    cb_time_s   time;
    kal_uint32 i;
    kal_uint32 ctx;

    tid = kal_create_timer( "test" );
    tid2 = kal_create_timer( "test" );

    for( i = 0; i < 3; i++ )
    {
        timer_array[i] = kal_create_timer( "test" );
    }

    ktest_timer_g_count = 0;
    ctx = context;

    /* delay 3 ticks, start timer with tick 0, 1, 7 tick */
    cb_func = &cb_func_start;

    kal_set_timer( tid, timer_cb3, (void *) &ctx, 7, 0 );

    /* this timer should not suffer delay from the hisr callback */
    ktest_init_timer_cb( &time, 12 );
    kal_set_timer( tid2, event_cb4, &time, 12, 0 );

    /* tid(7) --- delay 3 --- start timer 7 */
    /* wait not exit. or else no stack. so time corrupt */
    ktest_delay_ticks( 100 );

    if( ktest_timer_g_count == 5 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "ktest_timer_g_count is %d",
                      ktest_timer_g_count );
    }

    ktest_reset_target();
}

static kal_int32 ktest_starttimer_cb( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To delay and start timer in call back function";

    internal_start_timer( 0 );

    return 0;
}

static kal_int32 ktest_starttimer_hisr( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To delay and start timer in HISR context";

    /* can't allocate system memory in hisr context, for take mutex fail */
    timer_hisrid= kal_create_hisr( "TESTHISR", 1, 1024,
                                   (kal_hisr_func_ptr) timer_hisr_func1, NULL );
    if( timer_hisrid == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_create_hisr() return NULL" );
        ktest_reset_target();
    }

    internal_start_timer( 1 );

    return 0;
}

/*******************************************************************************
 * To test stop timer in timer callback and HISR context
 * ****************************************************************************/
static void internal_stop_timer( kal_uint32 context )
{
    kal_uint32 i;
    kal_uint32 ctx;

    for( i = 0; i < 3; i++ )
    {
        timer_array[i] = kal_create_timer( "test" );
    }

    ctx = context;

    ktest_timer_g_count = 0;
    cb_func = &cb_func_cancel;

    /* start 3 timer and cancel 2 in callback or hisr context */
    kal_set_timer( timer_array[0], timer_cb3, (void *) &ctx, 7, 0 );
    kal_set_timer( timer_array[1], ktest_timer_cb_timeout_fail, NULL, 7, 0 );
    kal_set_timer( timer_array[2], ktest_timer_cb_timeout_fail, NULL, 12, 0 );

    ktest_delay_ticks( 100 );

    if( ktest_timer_g_count == 1 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    ktest_reset_target();
}

static kal_int32 ktest_canceltimer_cb( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To stop timer in call back function";

    internal_stop_timer( 0 );
    return 0;
}

static kal_int32 ktest_canceltimer_hisr( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To stop timer in time callback -> hisr context";

    /* can't allocate system memory in hisr context, for take mutex fail */
    timer_hisrid = kal_create_hisr( "TESTHISR", 1, 1024,
                                    (kal_hisr_func_ptr) timer_hisr_func1, NULL );
    if( timer_hisrid == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "kal_create_hisr() return NULL" );
        ktest_reset_target();
    }

    internal_stop_timer( 1 );

    return 0;
}

/*******************************************************************************
 * To test AFN setting when stop the only timer with time-slice or not
 ******************************************************************************/
static kal_uint32 time_slice_stop;
static void main_timeslice( task_entry_struct *ptr )
{
    kal_timerid tid1;
    kal_uint32 afn;

    tid1 = kal_create_timer( "test" );
    kal_set_timer( tid1, ktest_timer_event_cb7, NULL, 10, 0 );

    /* stop the only timer */
    kal_cancel_timer( tid1 );

    afn = ktest_get_afn();

    if( time_slice_stop == 0 )
    {
        /* no time slice */
        if( afn == 0xFFFFFFFF )
        {
            ktest_report( KTEST_PASS, KTEST_TCID, NULL );
            ktest_reset_target();
        }
        else
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "afn is %d, time slice is %d",
                          afn, time_slice_stop );
            ktest_reset_target();
        }
    }
    else
    {
        /* have time slice */
        if( compare_time_error( afn, time_slice_stop, 2 ) )
        {
            ktest_report( KTEST_PASS, KTEST_TCID, NULL );
            ktest_reset_target();
        }
        else
        {
            ktest_report( KTEST_FAIL, KTEST_TCID, "afn is %d, time slice is %d",
                          afn, time_slice_stop );
            ktest_reset_target();
        }
    }
}

static kal_int32 ktest_stop_timer_with_timeslice( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test stop timer with timeslice";

    time_slice_stop = 256;
    ktest_create_task_timeslice( "T1", TASK_PRIORITY_KTEST + 10, 2048,
                                 main_timeslice, NULL, time_slice_stop );

    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * To test AFN setting when stop the only timer with time-slice or not
 *****************************************************************************/
static kal_int32 ktest_stop_timer_without_timeslice( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test stop timer without timeslice";

    time_slice_stop = 0;
    ktest_create_task_timeslice( "T1", TASK_PRIORITY_KTEST + 10, 2048,
                                 main_timeslice, NULL, time_slice_stop );

    kal_sleep_task( KAL_SUSPEND );
}

/****************************************************************************
 * To test start timer with time slice
 ***************************************************************************/
static kal_uint32 time_slice_start;
static void main_timeslice_2( task_entry_struct *ptr )
{
    kal_timerid tid1;
    kal_uint32 afn;
    kal_uint32 min;

    tid1 = kal_create_timer( "test" );
    kal_set_timer( tid1, ktest_timer_event_cb7, NULL, 50, 0 );

    afn = ktest_get_afn();
    min = ( time_slice_start < 50 ) ? time_slice_start : 50 ;

    if( compare_time_error( afn, min, 2 ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "afn is %d, time slice is %d",
                      afn, time_slice_start );
        ktest_reset_target();
    }
}

kal_int32 ktest_start_timer_with_bigtimeslice( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test start timer with time less than timeslice ";

    time_slice_start = 256;
    ktest_create_task_timeslice( "T1", TASK_PRIORITY_KTEST + 10, 2048,
                                 main_timeslice_2, NULL, time_slice_start );

    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * To test AFN setting when stop the only timer with time-slice or not
 *****************************************************************************/
kal_int32 ktest_start_timer_with_smalltimeslice( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test start timer with time bigger than timeslice";

    time_slice_start = 10;
    ktest_create_task_timeslice( "T1", TASK_PRIORITY_KTEST + 10, 2048,
                                 main_timeslice_2, NULL, time_slice_start );

    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * NU_Protect with timeslice and timer
 *****************************************************************************/
static kal_uint32 time_slice_protect;
static NU_PROTECT KTEST_Protect = {NULL, 0};
extern kal_hisrid g_timer_hisrid;

static void time_slice_hisr( void )
{
    kal_change_priority( task_info_g[INDX_KTEST].task_id,
                         TASK_PRIORITY_KTEST - 15 );
    return;
}

static void protect_timeslice( task_entry_struct *ptr )
{
    kal_uint32 afn, min;
    NU_Protect( &KTEST_Protect );

    /* CPU go to KTEST Now */
    /* Can't call system call when holding protect */
    ktest_activate_hisr( time_slice_hisr );

    afn = ktest_get_afn();
    min = ( time_slice_protect < 50 ) ? time_slice_protect : 50 ;

    if( compare_time_error( afn, min, 2 ) )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
        ktest_reset_target();
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "afn is %d, time slice is %d",
                      afn, time_slice_protect );
        ktest_reset_target();
    }

    return;
}

kal_int32 ktest_protect_with_smalltimeslice( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test NU_Protect timer with time bigger than timeslice";

    time_slice_protect = 10;

    g_timer_hisrid = kal_create_hisr( "TESTHISR", 0, 2048, time_slice_hisr, NULL );

    create_set_timer( ktest_timer_event_cb7, NULL, 50 );

    /* CPU to protect_timeslice now */
    ktest_create_task_timeslice( "T1", TASK_PRIORITY_KTEST - 10, 2048,
                                 protect_timeslice, NULL, time_slice_protect );

    /* CPU to protect_timeslice now */
    NU_Protect( &KTEST_Protect );
}

kal_int32 ktest_protect_with_bigtimeslice( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test NU_Protect timer with time smaller than timeslice";

    time_slice_protect = 60;

    g_timer_hisrid = kal_create_hisr( "TESTHISR", 0, 2048, time_slice_hisr, NULL );

    create_set_timer( ktest_timer_event_cb7, NULL, 50 );

    /* CPU to protect_timeslice now */
    ktest_create_task_timeslice( "T1", TASK_PRIORITY_KTEST - 10, 2048,
                                 protect_timeslice, NULL, time_slice_protect );

    /* CPU to protect_timeslice now */
    NU_Protect( &KTEST_Protect );
}

/******************************************************************************
 * TMC_Timer_HISR runs with IRQ_OSTIMER_ARM_CODE masked
 *****************************************************************************/
void check_silent_lisr( void *data )
{
    kal_uint32 old_tick = ktest_get_sys_tick();
    kal_uint32 i;

    for( i = 0; i < 3; i++ )
    {
        ktest_delay_ticks( 2 );

        if( old_tick != ktest_get_sys_tick() )
        {
            ktest_timer_g_count++;
        }
    }

    return;
}

/******************************************************************************
 * In timer call back func, check lisr silent
 *****************************************************************************/
kal_int32 ktest_hisr_mask_lisr( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "TMC_Timer_HISR runs with IRQ_OSTIMER_ARM_CODE masked";

    ktest_timer_g_count = 0;

    create_set_timer( check_silent_lisr, NULL, 7 );

    ktest_delay_ticks( 30 );

    if( ktest_timer_g_count == 0 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "Lisr comes time %d",
                      ktest_timer_g_count );
    }

    ktest_reset_target();
    return 0;
}

/******************************************************************************
 * callback time delays timer, but the error doesn't accumulate
 *****************************************************************************/
static void just_delay_cb( void *data )
{
    ktest_delay_ticks( 10 );
    return;
}

static kal_int32 ktest_callback_delay( kal_uint32 argc, void *argv )
{
    cb_time_s time1, time2;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Kal timer cb func execute too much time delays nearby timer";

    ktest_timer_g_count = 0;
    create_set_timer( just_delay_cb, NULL, 5 );

    /* should be delayed */
    ktest_init_timer_cb( &time1, 5 + 10 );
    create_set_timer( event_cb4, &time1, 5 + 7 );

    /* shouldn't be delayed */
    ktest_init_timer_cb( &time2, 5 + 13 );
    create_set_timer( event_cb4, &time2, 5 + 13 );

    ktest_delay_ticks( 30 );

    if( ktest_timer_g_count == 2 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "count is %d", ktest_timer_g_count );
    }

    ktest_reset_target();
    return 0;
}

static kal_timerid tid1;
static kal_timerid hisr_tid2;
static void hisr_routine_delay_timer( void )
{
    ktest_delay_ticks( 15 );
    ktest_init_timer_cb( &global_cb_array[0], 13 );
    kal_set_timer( hisr_tid2, event_cb4, &global_cb_array[0], 13, 0 );
    kal_cancel_timer( tid1 );
}

/******************************************************************************
 * start 3 timer. and let higher hisr blocks timer hisr
 *****************************************************************************/
static kal_int32 ktest_hisr_block( kal_uint32 argc, void *argv )
{
    cb_time_s time1, time2;
    ktest_timer_g_count = 0;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Higher priority hisr blocks timer hisr";

    tid1 = create_set_timer( ktest_timer_cb_timeout_fail, NULL, 5 );
    hisr_tid2 = kal_create_timer( "tid2" );

    /* higher hisr delays 10 ticks */
    ktest_init_timer_cb( &time1, 5 + 10 );
    create_set_timer( event_cb4, &time1, 8 );

    ktest_init_timer_cb( &time2, 20 );
    create_set_timer( event_cb4, &time2, 20 );

    /* cpu will goto hisr after this. the stack can't exit */
    ktest_activate_hisr( hisr_routine_delay_timer );

    /* wait for timer started by timer to finish */
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
    return 0;
}

/******************************************************************************
 * To test higher lisr blocks timer lisr
 *****************************************************************************/
/******************************************************************************
 * soft lisr priority higher than timer lisr?
 *****************************************************************************/
static void lisr_block_entry( void )
{
    ktest_delay_ticks( 7 );
    ktest_deactive_sw_handler();
}

static kal_int32 ktest_lisr_block( kal_uint32 argc, void *argv )
{
    cb_time_s time1, time2, time3;
    ktest_timer_g_count = 0;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Higher lisr blocks timer lisr";

    ktest_init_timer_cb( &time1, 7 );
    create_set_timer( event_cb4, &time1, 3 );

    ktest_init_timer_cb( &time2, 7 );
    create_set_timer( event_cb4, &time2, 5 );

    ktest_init_timer_cb( &time3, 11 );
    create_set_timer( event_cb4, &time3, 11 );

    /* cpu will goto lisr */
    ktest_sw_intr_handler( lisr_block_entry );
    ktest_active_sw_handler();

    /* wait for timerout */
    ktest_delay_ticks( 20 );

    /* cpu back from lisr */
    if( ktest_timer_g_count == 3 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "count is %d", ktest_timer_g_count );
    }

    ktest_reset_target();

    return 0;
}

/******************************************************************************
 * To test Timer module can handle unexpected timer interrupt
 *****************************************************************************/
extern kal_uint32 DRV_Get_Event_Time( void );
extern void DRV_Set_Event_Time( kal_uint32 afn, kal_uint32 ufn );

static kal_int32 ktest_makeup_timer_lisr( kal_uint32 argc, void *argv )
{
    cb_time_s time;
    kal_uint32 old_tick, new_tick;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Timer module can handle unexpected timer interrupt";

    ktest_timer_g_count = 0;

    ktest_init_timer_cb( &time, 10 );
    create_set_timer( event_cb4, &time, 10 );

    old_tick = ktest_get_sys_tick();
    DRV_Set_Event_Time( 2, 2 );

    /* check make up lisr ok */
    ktest_delay_ticks( 3 );
    new_tick = ktest_get_sys_tick();

    /* error. Expect AFN -> 0 and interrupt occured */
    if( old_tick == new_tick )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "makeup lisr fail.old:%d, new:%d",
                      old_tick, new_tick );
        ktest_reset_target();
    }
    else
    {
        #ifdef KTEST_DEBUG
        ktest_print( "[INFO] Makeup timer lisr OK\n\r" );
        #endif
    }

    /* wait for timerout */
    ktest_delay_ticks( 10 );

    if( ktest_timer_g_count == 1 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "ktest_timer_g_count is %d",
                      ktest_timer_g_count );
    }

    ktest_reset_target();
}

/******************************************************************************
 * To test timer expires with timeslice
 *****************************************************************************/
/******************************************************************************
 * start a timer in task. wait for its expiration, and check the afn setting
 *****************************************************************************/
static void task_expire_time_slice_entry( task_entry_struct *ptr )
{
   kal_uint32 afn;
   cb_time_s time;

   ktest_timer_g_count = 0;
   /* after the only timer timeout, afn should be time slice 256 - 10 = 246 */
   ktest_init_timer_cb( &time, 10 );
   create_set_timer( event_cb4, &time, 10 );

   while( ktest_timer_g_count == 0 );

   /* it seems, there is a bug here! TCD_current_thread is hisr in
    * TMC_Timer_Expiration which has no time slice */
   afn = ktest_get_afn();

   if( ( ktest_timer_g_count == 1 )
       && ( compare_time_error( afn, 256 - 10, 5 ) ) )
   {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
   }
   else
   {
        ktest_report( KTEST_FAIL, KTEST_TCID,
                      "ktest_timer_g_count is %d, afn is %d",
                      ktest_timer_g_count, afn );
   }

   ktest_reset_target();
}

/******************************************************************************
 * Note: timer expires without time slice has been tested in ktest_check_ticks_v2
 *****************************************************************************/
kal_int32 ktest_timer_expire_with_timeslice( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To test timer expires with timeslice";

    ktest_create_task_timeslice( "T1", TASK_PRIORITY_KTEST + 10, 2048,
                                 task_expire_time_slice_entry, NULL, 256 );

    kal_sleep_task( KAL_SUSPEND );
}

/******************************************************************************
 * To check timer interrupt knocks based on events, not on tick
 *****************************************************************************/
kal_int32 ktest_check_ticks( kal_uint32 argc, void *argv )
{
    kal_uint32 old_tick;
    kal_uint32 i;
    kal_uint32 once = 0;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To check interrupt knocks based on events, not on tick";

    old_tick = ktest_get_sys_tick();

    for( i = 0; i < 3; i++ )
    {
        ktest_delay_ticks( 2 );

        if( old_tick != ktest_get_sys_tick() )
        {
            once++;
        }
    }

    if( once == 0 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "Interrupt times %d", once );
    }

    ktest_reset_target();
    return 0;
}

kal_int32 ktest_check_ticks_v2( kal_uint32 argc, void *argv )
{
    kal_uint32 old_tick;
    kal_uint32 i;
    kal_uint32 once = 0;
    kal_uint32 once_again = 0;
    kal_timerid tid = NULL;
    kal_uint32 delay = 0x1FF;

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "To verify hardware bug:program AFN should supress the interrupt";

    tid = kal_create_timer( "test" );

    ktest_timer_g_count = 0;
    kal_set_timer( tid, ktest_timer_event_cb5, NULL, delay, 0 );

    /* during timer run, interrupt should not come */
    old_tick = ktest_get_sys_tick();
    for( i = 0; i < delay / 4; i++ )
    {
        ktest_delay_ticks( 2 );

        if( old_tick != ktest_get_sys_tick() )
        {
            once++;
        }
    }

    /* wait for expire */
    ktest_delay_ticks( delay );

    if( ktest_timer_g_count == 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "start timer not time out" );
        ktest_reset_target();
    }

    /* after expire, there should be no interrupt */
    old_tick = ktest_get_sys_tick();
    for( i = 0; i < 3; i++ )
    {
        ktest_delay_ticks( 2 );

        if( old_tick != ktest_get_sys_tick() )
        {
            once_again++;
        }
    }

    if( once == 0 && once_again == 0 )
    {
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, "Interrupt times %d:%d",
                      once, once_again );
    }

    ktest_reset_target();
    return 0;
}

/******************************************************************************
 * TMCT_Timer_Interrupt convert time in 4615us to 60000/13 us
 *****************************************************************************/
static kal_uint32 old_error_us;
void error_cb( void *data )
{
    kal_uint32 new_us = ust_get_current_time();

#ifdef KTEST_DEBUG
    /* not handler overflow */
    ktest_print( "[INFO] The time error in micro time %d",
                 new_us - old_error_us );
#endif
    ktest_reset_target();
    return;
}

/******************************************************************************
 * This test case takes about 1 minute to go.
 *****************************************************************************/
static kal_int32 ktest_handle_error_accumulate( kal_uint32 argc, void *argv )
{
    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "TMCT_Timer_Interrupt convert time in 4615us to 60000/13 us";

    old_error_us = ust_get_current_time();

    /* suppose user expect the time to be  12135 * 4615 micro second */
    create_set_timer( error_cb, NULL, 12135 );

    ktest_start_gpt_timer( 10 * 2000, NULL, NULL );

    while( 1 );
}

static kal_int32 ktest_sleep_empty( kal_uint32 argc, void *argv )
{
    Sleep_Time sleep_dur = {0, 0, 0};

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test AFN/UFN setting if no timer";

    kal_get_sleep_time( &sleep_dur );

    if( kal_is_valid_sleep_time( &sleep_dur ) == 0 )
    {
        ktest_report_reset( KTEST_FAIL );
    }

    /* check afn/ufn setting */
    if( ktest_get_afn() != (kal_uint32) MAX_SLEEP_TIME
        || ktest_get_ufn() != (kal_uint32) MAX_SLEEP_TIME )
    {
        ktest_report_reset( KTEST_FAIL );
    }

    ktest_report_reset( KTEST_PASS );

    return 0;
}

/******************************************************************************
 * T1(5)-----------------------------(45)
 *      T2(7)---------------(27)
 *            T3(9)--------------------------(68)
 *                    T(14)
 *****************************************************************************/
static kal_int32 ktest_sleep_time_cover( kal_uint32 argc, void *argv )
{
    kal_timerid tid1, tid2, tid3, tid4;
    Sleep_Time sleep_dur = {0, 0, 0};

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test AFN/UFN setting with best coverage timer setting";

    tid1 = create_set_timer( ktest_timer_event_cb7, NULL, 5 );
    ktest_set_aligned_timer( tid1, 40 );

    tid2 = create_set_timer( ktest_timer_event_cb7, NULL, 7 );
    ktest_set_aligned_timer( tid2, 20 );

    tid3 = create_set_timer( ktest_timer_event_cb7, NULL, 9 );
    ktest_set_aligned_timer( tid3, 59 );

    tid4 = create_set_timer( ktest_timer_event_cb7, NULL, 14 );

    kal_get_sleep_time( &sleep_dur );

    if( kal_is_valid_sleep_time( &sleep_dur ) == 0 )
    {
        ktest_report_reset( KTEST_FAIL );
    }

    if( ktest_get_afn() == 5 && ktest_get_ufn() == 14 )
    {
        ktest_report_reset( KTEST_PASS );
    }
    else
    {
        ktest_report_reset( KTEST_FAIL );
    }

    return 0;
}

static kal_int32 ktest_sleep_time_unlimited( kal_uint32 argc, void *argv )
{
    kal_timerid tid1, tid2;
    Sleep_Time sleep_dur = {0, 0, 0};

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test AFN/UFN setting with unlimted sleep timer";

    tid1 = create_set_timer( ktest_timer_event_cb7, NULL, 5 );
    ktest_set_aligned_timer( tid1, 255 );

    tid2 = create_set_timer( ktest_timer_event_cb7, NULL, 7 );
    ktest_set_aligned_timer( tid2, 255 );

    kal_get_sleep_time( &sleep_dur );

    if( kal_is_valid_sleep_time( &sleep_dur ) == 0 )
    {
        ktest_report_reset( KTEST_FAIL );
    }

    if( ktest_get_afn() == 5
        && ktest_get_ufn() == (kal_uint32) MAX_SLEEP_TIME )
    {
        ktest_report_reset( KTEST_PASS );
    }
    else
    {
        ktest_report_reset( KTEST_FAIL );
    }

    return 0;
}

static kal_int32 ktest_sleep_time_bound( kal_uint32 argc, void *argv )
{
    kal_timerid tid1, tid2;
    Sleep_Time sleep_dur = {0, 0, 0};

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test AFN/UFN setting with timer(2) boundary case";

    tid1 = create_set_timer( ktest_timer_event_cb7, NULL, 2 );
    ktest_set_aligned_timer( tid1, 13 );

    tid2 = create_set_timer( ktest_timer_event_cb7, NULL, 9 );
    ktest_set_aligned_timer( tid2, 5 );

    kal_get_sleep_time( &sleep_dur );

    if( kal_is_valid_sleep_time( &sleep_dur ) == 0 )
    {
        ktest_report_reset( KTEST_FAIL );
    }

    if( ktest_get_afn() == 2 && ktest_get_ufn() == 14 )
    {
        ktest_report_reset( KTEST_PASS );
    }
    else
    {
        ktest_report_reset( KTEST_FAIL );
    }

    return 0;
}

static kal_int32 ktest_sleep_time_bound_v2( kal_uint32 argc, void *argv )
{
    kal_timerid tid1;
    Sleep_Time sleep_dur = {0, 0, 0};

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test AFN/UFN setting with timer(1) boundary case";

    tid1 = create_set_timer( ktest_timer_event_cb7, NULL, 2 );
    ktest_set_aligned_timer( tid1, 13 );

    kal_get_sleep_time( &sleep_dur );

    if( kal_is_valid_sleep_time( &sleep_dur ) == 0 )
    {
        ktest_report_reset( KTEST_FAIL );
    }

    if( ktest_get_afn() == 2 && ktest_get_ufn() == 15 )
    {
        ktest_report_reset( KTEST_PASS );
    }
    else
    {
        ktest_report_reset( KTEST_FAIL );
    }

    return 0;
}

static kal_int32 ktest_sleep_time_race( kal_uint32 argc, void *argv )
{
    Sleep_Time sleep_dur = {0, 0, 0};

    KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_BRIEF = "Test sleep mode API can handle timer activity in between";

    create_set_timer( ktest_timer_event_cb7, NULL, 10 );

    kal_get_sleep_time( &sleep_dur );

    create_set_timer( ktest_timer_event_cb7, NULL, 5 );

    if( kal_is_valid_sleep_time( &sleep_dur ) != 0 )
    {
        ktest_report_reset( KTEST_FAIL );
    }

    ktest_report_reset( KTEST_PASS );

    return 0;
}

static kal_int32 ktest_timer_unlimited_sleep( kal_uint32 argc, void *argv )
{
    return 0;
}

static kal_int32 ktest_timer_little_sleep( kal_uint32 argc, void *argv )
{
    return 0;
}

/******************************************************************************
 * To test KAL timer work correctly under sleep mode
 *      1) create idle task
 *      2) set up timer, start gpt timer
 *      3) yield cpu to idle task so idle task goes to sleep mode
 *      4) timer call back function resumes KTEST task and update expiration time
 *      5) ktest checks timer accuracy.
 *          5.1: check really enter the sleep mode.
 *          5.2: wake up from sleep mode at the exact time.
 *                  1) sleep time as wished
 *                  2) some timer should be delayed. some timer should not delay
 *
 *      gpt timer call back:
 *          rely on GPT time will surely wake up the sleep mode.
 *          and resume the task.
 *****************************************************************************/
static volatile kal_uint32 wakeup;
static volatile kal_uint32 wakeup_time;
typedef struct
{
    kal_timerid id;
    kal_uint32  start_time;
    kal_uint32  delay_tick;
    kal_uint32  aligned_tick;
    kal_uint32  real_expired_us;
    kal_uint32  state;
    #define SLEEP_TIMER_EXPIRED     1
    #define SLEEP_TIMER_START       0
    #define SLEEP_TIMER_CHECKED     2
} sleep_timer_s;

#define SLEEP_NUM 17
static sleep_timer_s    sleep_timer[SLEEP_NUM];

/******************************************************************************
 * This is debug code
 *****************************************************************************/
#define MAX_DEBUG_LEN 1000

static void print_debug_info( void )
{
}

static void start_app_timer( kal_uint32 delay, kal_uint32 align,
                             kal_timer_func_ptr handler_func_ptr, void *data )
{
    sleep_timer_s *ptr = (sleep_timer_s *) data;
    kal_get_time( &(ptr->start_time) );
    ptr->delay_tick = delay;
    ptr->aligned_tick = align;
    ptr->state = SLEEP_TIMER_START;

    kal_set_timer( ptr->id, handler_func_ptr, data, delay, 0 );
    ktest_set_aligned_timer( ptr->id, align );

    return;
}

/******************************************************************************
 * Before integration with sleep, to test the code logic is right
 *****************************************************************************/
#ifdef SIMULATE_SLEEP_MODE
    kal_uint32 g_simulate_sleep_time;
#endif

static void timer_sleep_timeout( void *data )
{
    kal_internal_taskid  task_int_ptr;
    kal_uint32 ret_status;
    sleep_timer_s *time_ptr = (sleep_timer_s *) data;

#ifdef SIMULATE_SLEEP_MODE
    if( wakeup == 0 )
    {
        ktest_delay_ticks( g_simulate_sleep_time - 5 );
    }
#endif

    kal_get_time( &time_ptr->real_expired_us );
    time_ptr->state = SLEEP_TIMER_EXPIRED;

    /* sleep mode wake up -> first timer call back -> resume ktest task */
    if( wakeup == 0 )
    {
        task_int_ptr = (kal_internal_taskid) ( task_info_g[INDX_KTEST].task_id );
        wakeup = 1;
        kal_get_time( &wakeup_time );

        ret_status  = NU_Resume_Driver( &(task_int_ptr->task_id) );
        if( ret_status != NU_SUCCESS )
        {
            kal_fatal_error_handler( KAL_ERROR_ITC_MGIVE_FAILED,
                                     (kal_int32) ret_status );
        }
    }

    return;
}

static void irq_wakup_hisr_cb( void *data )
{
    kal_internal_taskid  task_int_ptr;
    kal_uint32 ret_status;

    wakeup = 1;
    task_int_ptr = (kal_internal_taskid) ( task_info_g[INDX_KTEST].task_id );
    kal_get_time( &wakeup_time );

    ret_status  = NU_Resume_Driver( &(task_int_ptr->task_id) );
    if( ret_status != NU_SUCCESS )
    {
        kal_fatal_error_handler( KAL_ERROR_ITC_MGIVE_FAILED,
                                 (kal_int32) ret_status );
    }
}

static kal_uint32 get_min_sleep_time( sleep_timer_s *timers, kal_uint32 num )
{
    kal_uint32 i;
    sleep_timer_s *ptr = &timers[0];
    kal_uint32  min = ptr->delay_tick + ptr->aligned_tick;

    for( i = 1; i < num; i++ )
    {
        ptr = &timers[i];
        if( min > ( ptr->delay_tick + ptr->aligned_tick ) )
        {
            min = ptr->delay_tick + ptr->aligned_tick;
        }
    }

    return min;
}

/******************************************************************************
 * test case table of nu_timer module of KTEST in post-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on Target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
static const ktest_tc_struct ktest_tc_tbl[] =
{
    {ktest_canceltimer_hisr, 0, NULL},
    {ktest_canceltimer_cb, 0, NULL},
    {ktest_starttimer_hisr, 0, NULL},
    {ktest_starttimer_cb, 0, NULL},
    {ktest_stop_timer_with_timeslice, 0, NULL},
    {ktest_stop_timer_without_timeslice, 0, NULL},
    {ktest_hisr_mask_lisr, 0, NULL},
    {ktest_check_ticks, 0, NULL},
    {ktest_check_ticks_v2, 0, NULL},
    {ktest_start_timer_with_bigtimeslice, 0, NULL},
    {ktest_start_timer_with_smalltimeslice, 0, NULL},
    {ktest_protect_with_smalltimeslice, 0, NULL},
    {ktest_protect_with_bigtimeslice, 0, NULL},
    {ktest_callback_delay, 0, NULL},
    {ktest_hisr_block, 0, NULL},
    {ktest_lisr_block, 0, NULL},
    {ktest_timer_expire_with_timeslice, 0, NULL},
    {ktest_makeup_timer_lisr, 0, NULL},
    {ktest_sleep_empty, 0, NULL},
    {ktest_sleep_time_cover, 0, NULL},
    {ktest_sleep_time_unlimited, 0, NULL},
    {ktest_sleep_time_bound, 0, NULL},
    {ktest_sleep_time_bound_v2, 0, NULL},
    {ktest_sleep_time_race, 0, NULL},
};

/******************************************************************************
 * test case table of nu_timer module of KTEST in pre-schedule stage.
 * note that the ones wrapped with FIX_OSCAR_FAIL will only be tested on Target,
 *           but will be ignored on OSCAR.
 *****************************************************************************/
static const ktest_tc_struct ktest_pre_tc_tbl[] =
{
    {ktest_fake_test, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_tc_num
 * Functionality:
 *     caculate there are how many test cases in nu_timer module of KTEST in
 *     post-schedule stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of nu_timer module in pre-schedule stage.
 *****************************************************************************/
static kal_uint32 ktest_tc_num( void )
{
    return sizeof( ktest_tc_tbl ) / sizeof( ktest_tc_struct );
}

kal_uint32 ktest_pre_tc_num( void )
{
    return sizeof( ktest_pre_tc_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_timer_nu_event_timer_init
 * Functionality:
 *     the initialization function of nu_timer module.
 * Parameters:
 *     mod: the id of nu_timer module.
 * Returns:
 *     void.
 * Note:
 *     we should call this function in ktest_testcase_register to register
 *     nu_timer module into KTEST.
 *****************************************************************************/
void ktest_timer_nu_event_timer_init( kal_uint32 mod )
{
    tc_all_tbls[mod] = ktest_tc_tbl;
    pre_tc_all_tbls[mod] = ktest_pre_tc_tbl;

    tc_modules_num[mod] = ktest_tc_num();
    pre_tc_modules_num[mod] = ktest_pre_tc_num();
}

#endif  /*__KTEST__*/
