/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * avk_pluto_timer.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implement the function to test pluto timer
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
extern "C"
{
#include "timerevents.h"
#include "mmi_frm_timer_gprot.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
}

/****************************************************************************
 * Define
 ****************************************************************************/
#define AVK_PLUTO_TIMER_TIMEOUT_MS_100		100
#define AVK_PLUTO_TIMER_TIMEOUT_MS_200		200
#define AVK_PLUTO_TIMER_TIMEOUT_MS_500		500
#define AVK_PLUTO_TIMER_TIMEOUT_MS_1000		1000
#define AVK_PLUTO_TIMER_TIMEOUT_MS_1500		1500
#define AVK_PLUTO_TIMER_TIMEOUT_MS_2000		2000

#define AVK_PLUTO_TIMER_MS_TO_TICK(milli_secs) \
    (kal_secs_to_ticks((milli_secs) / 1000) + kal_milli_secs_to_ticks((milli_secs) % 1000))

typedef enum
{
	AVK_PLUTO_TIMER_TEST_FUNCTION,
	AVK_PLUTO_TIMER_TEST_EXIST,
	AVK_PLUTO_TIMER_TEST_START,
	AVK_PLUTO_TIMER_TEST_STOP,
	AVK_PLUTO_TIMER_TEST_STOP_DO,
	AVK_PLUTO_TIMER_TEST_STOP_CHECK,
	AVK_PLUTO_TIMER_TEST_SUSPEND_RESUME,
	AVK_PLUTO_TIMER_TEST_SUSPEND_DO,
	AVK_PLUTO_TIMER_TEST_RESUME_DO,	
	
	AVK_PLUTO_TIMER_TEST_END_OF_ENUM
} avk_pluto_timer_test_index;

typedef struct
{
	U32 start_time;             /* start timer time; unit is tick */
    U16 excute_count;           /* test timer excute counter */
    U16 excute_count_backup;    /* backup timer excute counter used to check */
    U32 suspend_time;           /* suspend timers time; unit is tick */
    U32 resume_time;            /* resume timers time; unit is tick */
} avk_pluto_timer_context;

/*****************************************************************************
 * Local Variable                                                              
 *****************************************************************************/
static avk_pluto_timer_context g_avk_pluto_timer_ctx;

/*****************************************************************************
 * Local Function Declaration                                                      
 *****************************************************************************/
static void avk_pluto_timer_test_func(void *data);

/*****************************************************************************
 * Local Function                                                              
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_timer_test_func
 * DESCRIPTION
 *  timer callback function
 * PARAMETERS
 *  data		:[IN]		user data
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_timer_test_func(void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index;
	U32 callback_time;
    U32 duration;
    U32 suspend_duration;
    MMI_RET ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	index = (U32)data;
    MMI_ASSERT(index < AVK_PLUTO_TIMER_TEST_END_OF_ENUM);
	switch (index)
	{
		case AVK_PLUTO_TIMER_TEST_START:
            /*
             * compute the duration from StartTimer to call test timer's callback function 
             * the duration must be no less than the test timer's expiry
             */
            kal_get_time((kal_uint32 *)&callback_time);
            duration = callback_time - g_avk_pluto_timer_ctx.start_time;
            MMI_ASSERT(duration >= AVK_PLUTO_TIMER_MS_TO_TICK(AVK_PLUTO_TIMER_TIMEOUT_MS_100));
            StopTimer(AVK_PLUTO_TIMER_TEST_BASE);
            AVK_LOG(AVK_PLUTO_TIMER_TEST_START);
            AVK_CASE_RESULT(AVK_PASS);
            AVK_ASYN_DONE();
			break;

        case AVK_PLUTO_TIMER_TEST_STOP:
            /* increase the counter and restart the test timer periodicly */
            g_avk_pluto_timer_ctx.excute_count++;
            StartTimerEx(AVK_PLUTO_TIMER_TEST_BASE,
                AVK_PLUTO_TIMER_TIMEOUT_MS_100,
                avk_pluto_timer_test_func,
                (void *)AVK_PLUTO_TIMER_TEST_STOP);
            break;

        case AVK_PLUTO_TIMER_TEST_STOP_DO:
            /* 
             * record the counter and do StopTimer 
             * start another timer with expiry 500ms to check whether the test one stop 
             */
            g_avk_pluto_timer_ctx.excute_count_backup = g_avk_pluto_timer_ctx.excute_count;
            StopTimer(AVK_PLUTO_TIMER_TEST_BASE);
            StartTimerEx(AVK_PLUTO_TIMER_TEST_BASE + 1,
                AVK_PLUTO_TIMER_TIMEOUT_MS_500,
                avk_pluto_timer_test_func,
                (void *)AVK_PLUTO_TIMER_TEST_STOP_CHECK);
            AVK_LOG(AVK_PLUTO_TIMER_TEST_STOP_DO);
            break;

        case AVK_PLUTO_TIMER_TEST_STOP_CHECK:
            /*
             * if the test timer stop, the counter must be the same with the recorded one when stop timer
             */
            MMI_ASSERT(g_avk_pluto_timer_ctx.excute_count == g_avk_pluto_timer_ctx.excute_count_backup);
            AVK_LOG(AVK_PLUTO_TIMER_TEST_STOP_CHECK);
            AVK_CASE_RESULT(AVK_PASS);
            AVK_ASYN_DONE();
            break;

        case AVK_PLUTO_TIMER_TEST_SUSPEND_DO:
            /*
             * suspend aligned timers
             * start a non-aligned timer with expiry 1500ms to resume aligned timers 
             */
            mmi_frm_suspend_timers(TIMER_IS_ALIGNMENT);
            kal_get_time((kal_uint32 *)&g_avk_pluto_timer_ctx.suspend_time);
            ret = IsMyTimerExist(AVK_PLUTO_TIMER_TEST_BASE);
            MMI_ASSERT(ret == MMI_TRUE);
            StartNonAlignTimerEx(AVK_PLUTO_TIMER_TEST_BASE + 1,
                AVK_PLUTO_TIMER_TIMEOUT_MS_1500,
                avk_pluto_timer_test_func,
                (void *)AVK_PLUTO_TIMER_TEST_RESUME_DO);
            AVK_LOG(AVK_PLUTO_TIMER_TEST_SUSPEND_DO);
            break;
            
        case AVK_PLUTO_TIMER_TEST_RESUME_DO:
            /* resume aligned timers */
            ret = IsMyTimerExist(AVK_PLUTO_TIMER_TEST_BASE);
            MMI_ASSERT(ret == MMI_TRUE);
            kal_get_time((kal_uint32 *)&g_avk_pluto_timer_ctx.resume_time);
            mmi_frm_resume_timers(TIMER_IS_ALIGNMENT);
            AVK_LOG(AVK_PLUTO_TIMER_TEST_RESUME_DO);
            break;

        case AVK_PLUTO_TIMER_TEST_SUSPEND_RESUME:
            /*
             * compute the duration from StartTimer to call test timer's callback function
             * and suspend duration from suspend_timers to resume_timers;
             * the test timer duration must be no less than test timer's expiry plus the suspended duration
             */
            kal_get_time((kal_uint32 *)&callback_time);
            duration = callback_time - g_avk_pluto_timer_ctx.start_time;
            suspend_duration = g_avk_pluto_timer_ctx.resume_time - g_avk_pluto_timer_ctx.suspend_time;
            MMI_ASSERT((duration - suspend_duration) >= AVK_PLUTO_TIMER_MS_TO_TICK(AVK_PLUTO_TIMER_TIMEOUT_MS_1000));
            AVK_LOG(AVK_PLUTO_TIMER_TEST_SUSPEND_RESUME);
            AVK_CASE_RESULT(AVK_PASS);
            AVK_ASYN_DONE();
            break;
            
        default:
			break;
	}
}

/*****************************************************************************
 * Extern Global Function                                                      
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  avk_pluto_timer_case_test_start
 * DESCRIPTION
 *  Test StartTimer Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_TIMER_CASE_TEST_START, AVK_PLUTO_TIMER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	kal_get_time((kal_uint32 *)&g_avk_pluto_timer_ctx.start_time);
	StartTimerEx(AVK_PLUTO_TIMER_TEST_BASE,
		AVK_PLUTO_TIMER_TIMEOUT_MS_100,
		avk_pluto_timer_test_func,
		(void *)AVK_PLUTO_TIMER_TEST_START);
	AVK_LOG_FUN_ASYN(StartTimerEx);  

}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_timer_case_test_stop
 * DESCRIPTION
 *  Test StopTimer Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_TIMER_CASE_TEST_STOP, AVK_PLUTO_TIMER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    StartTimerEx(AVK_PLUTO_TIMER_TEST_BASE,
        AVK_PLUTO_TIMER_TIMEOUT_MS_100,
        avk_pluto_timer_test_func,
        (void *)AVK_PLUTO_TIMER_TEST_STOP);
    StartTimerEx(AVK_PLUTO_TIMER_TEST_BASE + 1,
        AVK_PLUTO_TIMER_TIMEOUT_MS_1000,
        avk_pluto_timer_test_func,
        (void *)AVK_PLUTO_TIMER_TEST_STOP_DO);
    AVK_LOG_FUN_ASYN(StopTimer);
    
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_timer_case_test_exist
 * DESCRIPTION
 *  Test IsMyTimerExist function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_TIMER_CASE_TEST_EXIST, AVK_PLUTO_TIMER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	ret = IsMyTimerExist(AVK_PLUTO_TIMER_TEST_BASE);
	MMI_ASSERT(ret == MMI_FALSE);
	StartTimerEx(AVK_PLUTO_TIMER_TEST_BASE, 
		AVK_PLUTO_TIMER_TIMEOUT_MS_2000, 
		avk_pluto_timer_test_func,
		(void *)AVK_PLUTO_TIMER_TEST_EXIST);
	ret = IsMyTimerExist(AVK_PLUTO_TIMER_TEST_BASE);
	MMI_ASSERT(ret == MMI_TRUE);
	StopTimer(AVK_PLUTO_TIMER_TEST_BASE);
    ret = IsMyTimerExist(AVK_PLUTO_TIMER_TEST_BASE);
	MMI_ASSERT(ret == MMI_FALSE);
	AVK_LOG_FUN(IsMyTimerExist, AVK_PASS);
    
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_timer_case_test_suspend_resume
 * DESCRIPTION
 *  Test suspend / resume timer function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_TIMER_CASE_TEST_SUSPEND_RESUME, AVK_PLUTO_TIMER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_get_time((kal_uint32 *)&g_avk_pluto_timer_ctx.start_time);
    StartTimerEx(AVK_PLUTO_TIMER_TEST_BASE,
        AVK_PLUTO_TIMER_TIMEOUT_MS_1000,
        avk_pluto_timer_test_func,
        (void *)AVK_PLUTO_TIMER_TEST_SUSPEND_RESUME);
    StartTimerEx(AVK_PLUTO_TIMER_TEST_BASE + 1,
        AVK_PLUTO_TIMER_TIMEOUT_MS_200,
        avk_pluto_timer_test_func,
        (void *)AVK_PLUTO_TIMER_TEST_SUSPEND_DO);
    /* 
     * the name of test_suspend_resume_timer is a dummy function name
     * just use this name to indicate test suspend / resume timer
     */
    AVK_LOG_FUN_ASYN(test_suspend_resume_timer);
    
}


/***********************************************************************/
/*     Test MMI Timer emit expanstion event                            */
/***********************************************************************/
typedef void (*avk_mytimer_proc)(void *param);
typedef event_scheduler avk_mytimer_base_struct;
typedef eventid avk_mytimer_id;

extern avk_mytimer_id avk_mytimer_start_timer(avk_mytimer_proc expiry_proc, U32 milli_secs, void *param);

extern S32 avk_mytimer_stop_timer(avk_mytimer_id mytimer);

static void avk_mytimer_test_proc(void *param);

#define AVK_MYTIMER_TEST_START          1
#define AVK_MYTIMER_TEST_STOP           2
#define AVK_MYTIMER_TEST_STOP_DO        3
#define AVK_MYTIMER_TEST_STOP_CHECK     4

static avk_mytimer_base_struct *g_mytimer_base_cntx;

static avk_mytimer_id g_mytimer_test;


/*****************************************************************************
 * FUNCTION
 *  avk_mytimer_init
 * DESCRIPTION
 *  mytimer proc for EVT_ID_MMI_TIMER_INIT_EXT
 * PARAMETERS
 *  evt : [IN] mmi timer event pointer in fact
 * RETURNS
 *  0 : callback manager will continue to deliver this event
 *  non-zero : callback manager will stop deliver this event
 *****************************************************************************/
extern "C" mmi_ret avk_mytimer_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mytimer_base_cntx = (avk_mytimer_base_struct *)evshed_create("MyTimerDemo", MOD_MMI, 0, 0);
    evshed_set_index(g_mytimer_base_cntx, AVK_MYTIMER_BASE_ID);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_mytimer_expiry_handler
 * DESCRIPTION
 *  mytimer proc for EVT_ID_MMI_TIMER_EXPIRY_PROC_EXT
 * PARAMETERS
 *  evt : [IN] mmi timer event pointer in fact
 * RETURNS
 *  0 : callback manager will continue to deliver this event
 *  non-zero : callback manager will stop deliver this event
 *****************************************************************************/
extern "C" mmi_ret avk_mytimer_expiry_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_timer_event_struct *timer_event;
    ilm_struct *ilm;
    kal_uint16 timer_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timer_event = (mmi_timer_event_struct *)evt;
    ilm = (ilm_struct *)timer_event->expiry_msg;
    timer_index = evshed_get_index(ilm);
    if (AVK_MYTIMER_BASE_ID == timer_index)
    {
        evshed_timer_handler((event_scheduler *)g_mytimer_base_cntx);
        /* my timer expiry msg, return non-zero to stop deliver timer event */
        return 1;
    }
    /* not my timer expiry msg, return 0 to continue to deliver timer event for other listeners */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_mytimer_start_timer
 * DESCRIPTION
 *  start a mytimer
 * PARAMETERS
 *  expiry_proc : [IN] proc for mytimer expiry
 *  milli_secs  : [IN] milliseconds for expiry
 *  param       : [IN] user data
 * RETURNS
 *  NULL            :  fail to start timer
 *  avk_mytimer_id  :  mytimer id
 *****************************************************************************/
avk_mytimer_id avk_mytimer_start_timer(avk_mytimer_proc expiry_proc, U32 milli_secs, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ticks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (expiry_proc == NULL)
    {
        return NULL;
    }
    ticks = kal_milli_secs_to_ticks(milli_secs);
    if (ticks == 0)
    {
        ticks = 1;
    }
    return (avk_mytimer_id)evshed_set_event((event_scheduler *)g_mytimer_base_cntx, 
            (kal_timer_func_ptr)expiry_proc,
            param,
            ticks);
}


/*****************************************************************************
 * FUNCTION
 *  avk_mytimer_stop_timer
 * DESCRIPTION
 *  stop a mytimer
 * PARAMETERS
 *  mytimer : [IN] mytimer id
 * RETURNS
 *  -1 : fail to stop timer
 *  n  : left time util expiry
 *****************************************************************************/
S32 avk_mytimer_stop_timer(avk_mytimer_id mytimer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    eventid timerid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timerid = (eventid)mytimer;
    return (S32)evshed_cancel_event((event_scheduler *)g_mytimer_base_cntx,&timerid);
}


/*****************************************************************************
 * FUNCTION
 *  avk_mytimer_test_proc
 * DESCRIPTION
 *  mytimer proc for expiry
 * PARAMETERS
 *  param : [IN] user data
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_mytimer_test_proc(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 exe_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = (U32)param;
    switch (index)
    {
        case AVK_MYTIMER_TEST_START:
            kal_get_time(&exe_time);
            MMI_ASSERT(exe_time - g_avk_pluto_timer_ctx.start_time >= kal_milli_secs_to_ticks(AVK_PLUTO_TIMER_TIMEOUT_MS_100));
            AVK_CASE_RESULT(MMI_TRUE);
            AVK_ASYN_DONE();
            break;
            
        case AVK_MYTIMER_TEST_STOP:
            g_avk_pluto_timer_ctx.excute_count++;
            g_mytimer_test = avk_mytimer_start_timer(avk_mytimer_test_proc, AVK_PLUTO_TIMER_TIMEOUT_MS_100, (void *)AVK_MYTIMER_TEST_STOP);
            break;

        case AVK_MYTIMER_TEST_STOP_DO:
            g_avk_pluto_timer_ctx.excute_count_backup = g_avk_pluto_timer_ctx.excute_count;
            avk_mytimer_stop_timer(g_mytimer_test);
            g_mytimer_test = NULL;
            avk_mytimer_start_timer(avk_mytimer_test_proc, AVK_PLUTO_TIMER_TIMEOUT_MS_200, (void *)AVK_MYTIMER_TEST_STOP_CHECK);
            break;

        case AVK_MYTIMER_TEST_STOP_CHECK:
            MMI_ASSERT(g_mytimer_test == NULL && g_avk_pluto_timer_ctx.excute_count_backup == g_avk_pluto_timer_ctx.excute_count);
            AVK_CASE_RESULT(MMI_TRUE);
            AVK_ASYN_DONE();
            break;
            
        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_timer_case_test_mytimer_start
 * DESCRIPTION
 *  test mytimer start function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_TIMER_CASE_TEST_MYTIMER_START, AVK_PLUTO_TIMER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&g_avk_pluto_timer_ctx.start_time);
    avk_mytimer_start_timer(avk_mytimer_test_proc, AVK_PLUTO_TIMER_TIMEOUT_MS_100, (void *)AVK_MYTIMER_TEST_START);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_timer_case_test_mytimer_stop
 * DESCRIPTION
 *  test mytimer stop function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_TIMER_CASE_TEST_MYTIMER_STOP, AVK_PLUTO_TIMER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_avk_pluto_timer_ctx.excute_count = 0;
    g_mytimer_test = avk_mytimer_start_timer(avk_mytimer_test_proc, AVK_PLUTO_TIMER_TIMEOUT_MS_100, (void *)AVK_MYTIMER_TEST_STOP);
    avk_mytimer_start_timer(avk_mytimer_test_proc, AVK_PLUTO_TIMER_TIMEOUT_MS_1000, (void *)AVK_MYTIMER_TEST_STOP_DO);
}

