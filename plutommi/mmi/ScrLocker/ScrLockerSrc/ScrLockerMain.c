/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrLockerMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the main component of the screen locker.
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

#include <limits.h>

#include "MMI_features.h"
#include "ScrLockerProt.h"
#include "IdleGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "ScrSaverGprot.h"
#include "GpioSrvGprot.h"
#include "SmsSrvGprot.h"
#include "MMIDataType.h"
#include "ScrLockerObject.h"
#include "ScrLockerMain.h"
#include "MMI_common_app_trc.h"
#include "mmi_frm_input_gprot.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "ScrLockerGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_rp_app_idle_def.h"
#include "GlobalResDef.h"
#include "ScrLockerAdapter.h"
#include "ScrLockerFactory.h"
#include "ScrLockerLawmo.h"
#include "mmi_frm_mem_gprot.h"
#include "FactoryGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ScrlockerScreenLockKey.h"
#if defined(__MMI_SCREEN_LOCK_CLASSIC__) && defined(__MMI_NCENTER_SUPPORT__)
#include "UcmSrvGprot.h"
#endif
#include "MMI_ap_dcm_config.h"

#ifdef __MMI_LAUNCHER_APP_LIST__
#include "applistgprot.h"
#endif

#ifdef __MMI_MMS_2__
#include "mmi_rp_srv_mms_def.h"
#endif

#ifdef  __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
#include "Gui_typedef.h"
//#define __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE_APP_NO_CLOSE__
#define TIMER_WDEVICE_VALUE (15000) 
#endif
/****************************************************************************
 * Global Context
 ****************************************************************************/

/* This structure defines the context of the screen locker. */
typedef struct
{
    U8                      suspend_count;
#ifdef __MMI_TOUCH_SCREEN__
    U8                      pen_block_count;
#endif
    U8                      flag;
#ifdef __MMI_SCREEN_LOCKER_MANUAL_LOCK__
    U16                     manual_lock_key_code;
#endif
    mmi_slk_obj_struct     *obj;
} mmi_slk_cntx_struct;

/* Global context of screen locker. */
static mmi_slk_cntx_struct g_mmi_slk_cntx;
static mmi_scr_locker_locked_key_callback g_mmi_slk_locked_key_cb = NULL;

/****************************************************************************
 * Define
 ****************************************************************************/

/* Manual handset lock timeout value in msec. */
#define MMI_SLK_MANUAL_LOCK_TIMEOUT             (2000)

/* Option flag. */
#define MMI_SLK_FLAG_SELF_SUSPEND                   (1 << 0)
#define MMI_SLK_FLAG_BACKLIGHT_FIRST_ON             (1 << 1)
#define MMI_SLK_FLAG_BLOCK_POWER_KEY_UP             (1 << 4)

/* Set / Clear / Has flag. */
#define MMI_SLK_SET(_f) (g_mmi_slk_cntx.flag |= _f)
#define MMI_SLK_CLR(_f) (g_mmi_slk_cntx.flag &= ~_f)
#define MMI_SLK_HAS(_f) (((g_mmi_slk_cntx.flag & _f) == _f))


/****************************************************************************
 * Function
 ****************************************************************************/
#if defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE_APP_NO_CLOSE__)
	static void mmi_scr_locker_exit_main_in_wdevice(void);

	static void mmi_scr_locker_entry_main_in_wdevice(void);

	static mmi_ret mmi_scr_locker_main_proc_in_wdevice(mmi_event_struct *evt);

	void mmi_scr_locker_launch_in_wdevice(void);
#endif
	

/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_set_locked_key_hdlr
 * DESCRIPTION
 *  This function set key hdlr, and the callback will be called when locker is locked.
 * PARAMETERS
 *  key_code           : [IN]      key code to trigger manual lock
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_scr_locker_set_locked_key_callback(mmi_scr_locker_locked_key_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_slk_locked_key_cb = cb;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_clear_locked_key_hdlr
 * DESCRIPTION
 *  This function clear the key hdlr.
 * PARAMETERS
 *  key_code           : [IN]      key code to trigger manual lock
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_scr_locker_clear_locked_key_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_slk_locked_key_cb = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_exec_locked_key_callback
 * DESCRIPTION
 *  This function clear the key hdlr.
 * PARAMETERS
 *  key_code           : [IN]      key code to trigger manual lock
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_scr_locker_exec_locked_key_callback(mmi_frm_key_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_slk_locked_key_cb)
    {
        g_mmi_slk_locked_key_cb(evt);
    }
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_pen_block
 * DESCRIPTION
 *  This function blocks the pen. This function can only be used by screen
 *  locker module.
 *
 *  TODO: Pen block and unblock API should support a counter by framework.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_pen_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
	return;
#endif	
    if (g_mmi_slk_cntx.pen_block_count >= UCHAR_MAX)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_PEN_BLOCK, 400));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_PEN_BLOCK, 200));

    if (g_mmi_slk_cntx.pen_block_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_PEN_BLOCK, 202));

        mmi_pen_block();
    }

    ++g_mmi_slk_cntx.pen_block_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_pen_unblock
 * DESCRIPTION
 *  This function unblocks the pen. This function can only be used by screen
 *  locker module.
 *
 *  TODO: Pen block and unblock API should support a counter by framework.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_pen_unblock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
	return;
#endif
    if (g_mmi_slk_cntx.pen_block_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_PEN_UNBLOCK, 400));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_PEN_UNBLOCK, 200));

    --g_mmi_slk_cntx.pen_block_count;

    if (g_mmi_slk_cntx.pen_block_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_PEN_UNBLOCK, 202));

        mmi_pen_unblock();
    }
}
#endif /*__MMI_TOUCH_SCREEN__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_is_locked_internal
 * DESCRIPTION
 *  This function checks if the handset is locked. This API ignores the
 *  suspended state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_slk_is_locked_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = (g_mmi_slk_cntx.obj ? MMI_TRUE : MMI_FALSE);

    MMI_SLK_LOG((TRC_MMI_SLK_IS_LOCKED_INTERNAL, 200, ret));

    return ret;
}


#ifdef __MMI_SCREEN_LOCKER_MANUAL_LOCK__
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_manual_lock_is_available
 * DESCRIPTION
 *  This function checks if the manula handset lock is available.
 * PARAMETERS
 *  key                : [IN]      Key code that triggers the manual lock
 * RETURNS
 *  On available, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_slk_manual_lock_is_available(U16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = (mmi_frm_get_key_handler(key, KEY_EVENT_UP) ? MMI_FALSE : MMI_TRUE);

    MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_IS_AVAILABLE, 200, ret));

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_manual_lock_is_processing
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_slk_manual_lock_is_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.manual_lock_key_code != KEY_INVALID)
    {
        ret = MMI_TRUE;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_IS_PRCESSING, 200, ret));

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_manual_lock_stop
 * DESCRIPTION
 *  This function stops the manual lock process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_manual_lock_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_STOP, 200));

    g_mmi_slk_cntx.manual_lock_key_code = KEY_INVALID;
    StopTimer(KEYPAD_LOCK_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_manual_lock_hdlr
 * DESCRIPTION
 *  This function locks the handset.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_manual_lock_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_scr_locker_is_locked() == MMI_TRUE ||
        mmi_slk_manual_lock_is_processing() == MMI_FALSE)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_HDLR, 500));
        return; /* fail-safe */
    }

    MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_HDLR, 200));

    mmi_slk_manual_lock_stop();

    mmi_idle_display();
    mmi_scr_locker_launch();
}
#endif /*MANUAL_LOCK*/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_auto_lock_get_time
 * DESCRIPTION
 *  This function gets the auto. lock time in msec.
 * PARAMETERS
 *  void
 * RETURNS
 *  Time in msec.
 *****************************************************************************/
static U32 mmi_slk_auto_lock_get_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time_msec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_msec = (U32)mmi_slk_set_get_timeout_value_in_msec();

    MMI_SLK_LOG((TRC_MMI_SLK_AUTO_LOCK_GET_TIME, 200, time_msec));

    return time_msec;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_is_allowed_launch
 * DESCRIPTION
 *  FTE2.0 scrlock pre check if can lock screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //|| defined(__MMI_VUI_SCREEN_LOCK_KEY__)
static MMI_BOOL mmi_slk_is_allowed_launch(mmi_scr_locker_lock_mode_enum lock_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
#if !defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) 
        && !srv_sim_ctrl_any_verifying_sim()
#endif
        && !(srv_bootup_is_booting() || srv_shutdown_is_running()))
    {
        mmi_scr_locker_pre_lock_evt_struct evt;
        mmi_ret ret;
        
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING);
        evt.lock_mode = lock_mode;
        ret = MMI_FRM_CB_EMIT_EVENT(&evt);
        if (ret == MMI_RET_OK || ret == MMI_RET_ERR_NO_REG_CB)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_scr_locker_is_active
 * DESCRIPTION
 *  This function is check whether screen lock is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_scr_locker_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_frm_group_is_in_active_serial(GRP_ID_SLK_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_auto_lock_timeout_hdlr
 * DESCRIPTION
 *  This function is the timerout handler for auto. handset lock.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_auto_lock_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_scr_locker_is_locked())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_AUTO_LOCK_TIMEOUT_HDLR, 500));
        return; /* fail-safe */
    }

    MMI_SLK_LOG((TRC_MMI_SLK_AUTO_LOCK_TIMEOUT_HDLR, 200));

#if defined(__MMI_SCREEN_LOCK_CLASSIC__) && defined(__MMI_NCENTER_SUPPORT__)
    if (srv_ucm_is_any_call())
    {
        mmi_scr_locker_start_timer();
        return;
    }
#endif

#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //|| defined(__MMI_VUI_SCREEN_LOCK_KEY__)
    if (mmi_slk_is_allowed_launch(MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK))
#endif
    {
#if defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
	    if(mmi_idle_is_active())
	    {
			mmi_scr_locker_start_timer();
			return;
		}
        #if defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE_APP_NO_CLOSE__)
		
			mmi_scr_locker_launch();
			mmi_scr_locker_launch_in_wdevice();
			
		#else  /* __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE_APP_NO_CLOSE__*/
		
			mmi_frm_close_to_idle_group();
		
		#endif /* __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE_APP_NO_CLOSE__*/
		
#else  /* __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__*/		
		{
			mmi_scr_locker_launch();
		}
#endif /* __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__*/	
	
    }
#if defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) 
    else
    {
		 mmi_scr_locker_start_timer();
	}
#endif

}
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_emit_locked
 * DESCRIPTION
 *  This function posts the locked event.
 * PARAMETERS
 *  obj         : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_emit_locked(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scr_locker_locked_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_EMIT_LOCKED, 200));

    MMI_ASSERT(obj);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCR_LOCKER_LOCKED);
    evt.type = (mmi_scr_locker_type_enum)obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

#if 0 //remove event EVT_ID_SCR_LOCKER_UNLOCKED as no used
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_bootup_early_init
 * DESCRIPTION
 *  This function initializes the context of the screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_bootup_early_init(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_mmi_slk_cntx, 0, sizeof(mmi_slk_cntx_struct));
#ifdef __MMI_SCREEN_LOCKER_MANUAL_LOCK__
    g_mmi_slk_cntx.manual_lock_key_code = KEY_INVALID;
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_shutdown_deinit
 * DESCRIPTION
 *  This function stops the screen locker when the handset shutdowns.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_shutdown_deinit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_SHUTDOWN_DEINIT, 200));

    mmi_scr_locker_stop_timer();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_idle_launched
 * DESCRIPTION
 *  This function handles the Idle launched event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_idle_launched(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: create a virtual function for this event. */
#if defined(__DM_LAWMO_SUPPORT__)
    if ((ret = mmi_slk_lawmo_handle_idle_launched()) != MMI_RET_OK)
    {
        return ret;
    }
    else
#endif /* defined(__DM_LAWMO_SUPPORT__) */
    {
        return ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_idle_before_group_exit
 * DESCRIPTION
 *  This function stops the screen locker when the handset exits idle group.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_idle_before_group_exit(mmi_event_struct *event)
{
#if !defined(__MMI_SCREEN_LOCK_ANY_TIME__) && !defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //&& !defined(__MMI_VUI_SCREEN_LOCK_KEY__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_IDLE_BEFORE_GROUP_EXIT, 200));

    mmi_scr_locker_stop_timer();

    /*
     * To suspend the locker, it must be done BEFORE the idle group exits. It's
     * for the classic locker. If it is done after the idle group exits, even if
     * we unlock the softkey, the label, image, and handler will not change back
     * to the one that APP want.
     */
    if (mmi_slk_is_locked_internal())
    {
        if (!MMI_SLK_HAS(MMI_SLK_FLAG_SELF_SUSPEND))
        {
            mmi_scr_locker_suspend();
            MMI_SLK_SET(MMI_SLK_FLAG_SELF_SUSPEND);
        }
    }
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_idle_before_group_enter
 * DESCRIPTION
 *  This function handles the group enter event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_idle_before_group_enter(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_IDLE_BEFORE_GROUP_ENTER, 200));

    mmi_scr_locker_start_timer();

#if !defined(__MMI_SCREEN_LOCK_ANY_TIME__) && !defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)  // && !defined(__MMI_VUI_SCREEN_LOCK_KEY__)
    if (mmi_slk_is_locked_internal())
    {
        if (MMI_SLK_HAS(MMI_SLK_FLAG_SELF_SUSPEND))
        {
            mmi_scr_locker_resume();
            MMI_SLK_CLR(MMI_SLK_FLAG_SELF_SUSPEND);
        }
    }
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_pre_touch_routing
 * DESCRIPTION
 *  This function handles the pre-touch routing.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_pre_touch_routing(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_multi_touch_event_struct *evt;
    mmi_touch_data_struct *touch_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    evt = (mmi_multi_touch_event_struct *)event;
    touch_data = evt->touch_data;
    if(touch_data->event == MMI_PEN_EVENT_ABORT)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_TOUCH_ROUTING, 500));
        return MMI_RET_OK;
    }
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_TOUCH_ROUTING, 200));
    
#ifdef __MMI_BTD_BOX_UI_STYLE__
    if(mmi_scr_locker_is_locked() && (srv_backlight_get_lcd_state(SRV_BACKLIGHT_TYPE_MAINLCD) == 2))
    {
	  if(touch_data->event == MMI_PEN_EVENT_LONG_TAP)
	  {
                mmi_scr_locker_close(); //  long tap to unlock 
		mmi_frm_close_to_idle_group();       
	  }
	  else if(touch_data->event == MMI_PEN_EVENT_UP)
	  {
		 mmi_slk_classic_unlock_popup_bt(); 
		 srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
          }
	  else
	  {
	  }
    }
  else
#endif /*#ifndef __MMI_BTD_BOX_UI_STYLE__*/
    { 
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    mmi_scr_locker_restart_timer();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_pre_key_routing
 * DESCRIPTION
 *  This function handles the pre-key routing.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_pre_key_routing(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;
    mmi_frm_key_evt_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    evt = (mmi_frm_key_evt_struct *)event;

#if defined(__OFN_SUPPORT__)
    // [MAUI_03034331] special UE for OFN hardware
    // do not turn on backlight when backlight is OFF && key code is OFN
    if( srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE &&
        (evt->key_code == KEY_RIGHT_ARROW ||
         evt->key_code == KEY_LEFT_ARROW  ||
         evt->key_code == KEY_UP_ARROW    ||
         evt->key_code == KEY_DOWN_ARROW))
    {
        return MMI_RET_STOP_KEY_HANDLE;
    }
#endif
   
    if (mmi_scr_locker_is_active())
    {   
        //for background running app 
        mmi_scr_locker_exec_locked_key_callback(evt);

    #ifdef __MMI_VUI_SCREEN_LOCK_KEY__ 
        if (mmi_scr_locker_get_type() == MMI_SCR_LOCKER_TYPE_SCRLOCK_KEY)
        {
            //check for emergency number
            MMI_ASSERT(obj && obj->on_key);
            return obj->on_key(obj, evt);
        }
    #endif
    }

#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //|| defined(__MMI_VUI_SCREEN_LOCK_KEY__)
           
    if (evt->key_code == KEY_POWER && !srv_shutdown_is_running() && !srv_bootup_is_booting())
    {
        if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_TRUE && evt->key_type == KEY_EVENT_UP)
        {
            MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 100));
        
            if (!MMI_SLK_HAS(MMI_SLK_FLAG_BLOCK_POWER_KEY_UP))
            {
                #ifdef __MMI_WEARABLE_DEVICE__
                return MMI_RET_OK;
                #else  //__MMI_WEARABLE_DEVICE__
                if (mmi_slk_is_allowed_launch(MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY))
                {
                    if (mmi_scr_locker_is_launched())
                    {
                        srv_backlight_turn_off_ext();
                    }
                    else
                    {
                        mmi_scr_locker_launch();
                    }
                    return MMI_RET_STOP_KEY_HANDLE;
                }
                else
                {
                    srv_backlight_turn_off_ext();
                    MMI_SLK_SET(MMI_SLK_FLAG_BLOCK_POWER_KEY_UP);
                    return MMI_RET_OK;
                }
                #endif  //__MMI_WEARABLE_DEVICE__
            }
            else
            {
                MMI_SLK_CLR(MMI_SLK_FLAG_BLOCK_POWER_KEY_UP);
            }
        }
        else if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE && evt->key_type == KEY_EVENT_DOWN)
        {
            MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 110));
            
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            
            MMI_SLK_SET(MMI_SLK_FLAG_BACKLIGHT_FIRST_ON);
            MMI_SLK_SET(MMI_SLK_FLAG_BLOCK_POWER_KEY_UP);
        }
        
    }
    else
#endif  /*__MMI_SCREEN_LOCK_ANY_TIME__*/
    {
        /*
        * Only allow key action when backlight is controlled by AP.
        *
        * TODO 1: Discuss with Hua Tian why this part is put on idle screen.
        * TODO 2: Discuss with GPIO that it should block key in this case.
        */
        if (evt->key_type == KEY_EVENT_DOWN || evt->key_type == KEY_LONG_PRESS ||  evt->key_type == KEY_REPEAT)
        //if (evt->key_type == KEY_EVENT_DOWN)
        {
            MMI_BOOL isBacklightOnBefore;
        
            MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 200));

            isBacklightOnBefore = srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD);

            mmi_scr_locker_turn_on_backlight();

        #if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //|| defined(__MMI_VUI_SCREEN_LOCK_KEY__)
            if (evt->key_code != KEY_POWER)
            {
                MMI_SLK_CLR(MMI_SLK_FLAG_BLOCK_POWER_KEY_UP);
            }
        #endif

//lhm: remove for option slim
#if 0
        #ifndef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
/* under construction !*/
/* under construction !*/
        #endif
#else
        if (!isBacklightOnBefore)
        {
            /* Block key event until the key is released. */
            MMI_SLK_SET(MMI_SLK_FLAG_BACKLIGHT_FIRST_ON);
            return MMI_RET_STOP_KEY_HANDLE;
        }    
#endif
        } 
    }
       

    /* Block key event until the key is released. */
    if (MMI_SLK_HAS(MMI_SLK_FLAG_BACKLIGHT_FIRST_ON))
    {
        MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 300));

        if (evt->key_type == KEY_EVENT_UP)
        {
            MMI_SLK_CLR(MMI_SLK_FLAG_BACKLIGHT_FIRST_ON);
        }

        return MMI_RET_STOP_KEY_HANDLE;
    }

    /*
     * Process key event in the following situation. Close the screen saver
     * actively since the key is blocked by the screen saver in this case.
     *
     *  1) Handset is locked.
     *  2) Screen saver is running and it will suspend the screen locker.
     */
    if ((mmi_scr_locker_is_locked()) 
    #if defined(__MMI_SCREEN_SAVER__)
        || (mmi_slk_is_locked_internal() && mmi_scr_saver_is_active())
    #endif
    )
    {
        MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 400));
    #if defined(__MMI_SCREEN_SAVER__)
        if (evt->key_type == KEY_EVENT_DOWN && mmi_scr_saver_is_active())
        {
            mmi_scr_saver_close();
        }
    #endif

        MMI_ASSERT(obj && obj->on_key);

        return obj->on_key(obj, evt);
    }
    else if (!srv_bootup_is_booting())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 410));

#ifdef __MMI_SCREEN_LOCKER_MANUAL_LOCK__
        if ((mmi_slk_manual_lock_is_processing()) &&
            (g_mmi_slk_cntx.manual_lock_key_code != evt->key_code))
        {
            mmi_slk_manual_lock_stop();
        }
#endif

        mmi_scr_locker_restart_timer();

        return MMI_RET_OK;
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_post_key_routing
 * DESCRIPTION
 *  This function handles the post-key routing.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_post_key_routing(mmi_event_struct *event)
{
#if !defined(__MMI_VUI_SCREEN_LOCK_KEY__) //&& !defined(__MMI_VUI_SCREEN_LOCK_KEY__) 

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

#if defined(__OFN_SUPPORT__)
    // [MAUI_03034331] special UE for OFN hardware
    // do not turn on backlight when press navigation key when 
    // backlight is ON & phone in locked state
    {
        mmi_frm_key_evt_struct *evt = (mmi_frm_key_evt_struct *)event;

        if( srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_TRUE && 
        mmi_scr_locker_is_locked() &&
        (evt->key_code == KEY_RIGHT_ARROW ||
         evt->key_code == KEY_LEFT_ARROW  ||
         evt->key_code == KEY_UP_ARROW    ||
         evt->key_code == KEY_DOWN_ARROW))
        {
            return MMI_RET_OK;
        }

        // do not turn on backlight when backlight is OFF && key code is OFN
        if( srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE &&
            (evt->key_code == KEY_RIGHT_ARROW ||
             evt->key_code == KEY_LEFT_ARROW  ||
             evt->key_code == KEY_UP_ARROW    ||
             evt->key_code == KEY_DOWN_ARROW))
        {
            return MMI_RET_OK;
        }
    }
#endif

    /*
     * Turn on backlight if the handset is not shutdowning.
     */
    if (!srv_shutdown_is_running())
    {
        mmi_scr_locker_turn_on_backlight();
    }

#endif  /*!defined(__MMI_VUI_SCREEN_LOCK_KEY__) && !defined(__MMI_SCREEN_LOCK_ANY_TIME__)*/

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_lcd_sleep_in
 * DESCRIPTION
 *  This function handles the LCD sleep-in event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_lcd_sleep_in(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_GPIO_LCD_SLEEP_IN, 200));
#ifdef __MMI_TOUCH_SCREEN__
    mmi_slk_pen_block();
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_lcd_sleep_out
 * DESCRIPTION
 *  This function handles the LCD sleep-out event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_lcd_sleep_out(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_GPIO_LCD_SLEEP_OUT, 200));
#ifdef __MMI_TOUCH_SCREEN__
    mmi_slk_pen_unblock();
#endif
    return MMI_RET_OK;
}


#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //|| defined(__MMI_VUI_SCREEN_LOCK_KEY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_backlight_on
 * DESCRIPTION
 *  This function handles the backlight turn on.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_backlight_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_slk_is_locked_internal())
    {
        mmi_scr_locker_restart_timer();
    }

    return MMI_RET_OK;
}
#endif


#if defined(__MMI_CLAMSHELL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_clam_open
 * DESCRIPTION
 *  This function handles the clam open event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_clam_open(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_GPIO_CLAM_OPEN, 200));

    if (mmi_scr_locker_is_locked())
    {
        mmi_scr_locker_close();
    }
    else
    {
        mmi_scr_locker_restart_timer();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_clam_close
 * DESCRIPTION
 *  This function handles the clam close event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_clam_close(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_GPIO_CLAM_CLOSE, 200));

    mmi_scr_locker_restart_timer();

    return MMI_RET_OK;
}
#endif /* defined(__MMI_CLAMSHELL__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_msg_num_changed
 * DESCRIPTION
 *  This function handles the message number changed event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_msg_num_changed(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_scr_locker_is_locked())
    {
        MMI_ASSERT(obj && obj->on_msg_num_changed);
        obj->on_msg_num_changed(obj);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_slk_obj_close_req
 * DESCRIPTION
 *  This function closes the screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_slk_obj_close_req(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_SLK_OBJ_CLOSE_REQ, 200));

    mmi_scr_locker_close();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_slk_obj_closed_ind
 * DESCRIPTION
 *  This function closes the screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_slk_obj_closed_ind(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_SLK_OBJ_CLOSED_IND, 200));

    g_mmi_slk_cntx.obj = NULL;

    /* The lock could be closed when it is still suspended. Reset the
       counter. */
    g_mmi_slk_cntx.suspend_count = 0;
    MMI_SLK_CLR(MMI_SLK_FLAG_SELF_SUSPEND);

    /* When the handset is locked, the backlight will be in the half mode by
       force. Turn on backlight here to make sure the backlight is on after the
       handset is unlocked. */
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    /* Start the screen locker timer for the next shot. */
    mmi_scr_locker_start_timer();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_main_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler of screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_slk_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
            ret = mmi_slk_handle_bootup_early_init(event);
            break;

        case EVT_ID_SRV_SHUTDOWN_DEINIT:
            ret = mmi_slk_handle_shutdown_deinit(event);
            break;

        case EVT_ID_IDLE_LAUNCHED:
            ret = mmi_slk_handle_idle_launched(event);
            break;

        case EVT_ID_IDLE_BEFORE_GROUP_EXIT:
            ret = mmi_slk_handle_idle_before_group_exit(event);
            break;

        case EVT_ID_IDLE_BEFORE_GROUP_ENTER:
            ret = mmi_slk_handle_idle_before_group_enter(event);
            break;

        case EVT_ID_PRE_KEY_EVT_ROUTING:
            ret = mmi_slk_handle_pre_key_routing(event);
            break;

        case EVT_ID_POST_KEY_EVT_ROUTING:
            ret = mmi_slk_handle_post_key_routing(event);
            break;

        case EVT_ID_PRE_TOUCH_EVT_ROUTING:
            ret = mmi_slk_handle_pre_touch_routing(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_IN:
            ret = mmi_slk_handle_gpio_lcd_sleep_in(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_OUT:
            ret = mmi_slk_handle_gpio_lcd_sleep_out(event);
            break;

    #if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //|| defined(__MMI_VUI_SCREEN_LOCK_KEY__)
        case EVT_ID_GPIO_BACKLIGHT_ON:
            ret = mmi_slk_handle_gpio_backlight_on();
            break;
    #endif

    #if defined(__MMI_CLAMSHELL__)
        case EVT_ID_GPIO_CLAM_OPEN:
            ret = mmi_slk_handle_gpio_clam_open(event);
            break;

        case EVT_ID_GPIO_CLAM_CLOSE:
            ret = mmi_slk_handle_gpio_clam_close(event);
            break;
    #endif /* defined(__MMI_CLAMSHELL__) */

        case EVT_ID_SRV_SMS_READY:      /* Fall throught. */
        case EVT_ID_SRV_SMS_ADD_MSG:    /* Fall throught. */
        case EVT_ID_SRV_SMS_DEL_MSG:    /* Fall throught. */
        case EVT_ID_SRV_SMS_UPDATE_MSG: /* Fall throught. */
#ifdef __MMI_MMS_2__
		case EVT_ID_SRV_MMS_NMGR_ALERT:
#endif
            ret = mmi_slk_handle_msg_num_changed(event);
            break;

        case EVT_ID_SLK_OBJ_CLOSE_REQ:
            ret = mmi_slk_handle_slk_obj_close_req(event);
            break;

        case EVT_ID_SLK_OBJ_CLOSED_IND:
            ret = mmi_slk_handle_slk_obj_closed_ind(event);
        #ifdef __MMI_AP_DCM_SCRLOCK__
            mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SCRLOCK);
        #endif
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}

#ifdef __MMI_SCREEN_LOCKER_MANUAL_LOCK__
/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_start_manual_lock(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_START_MANUAL_LOCK, 200));

    if (mmi_slk_manual_lock_is_available(key_code))
    {
        g_mmi_slk_cntx.manual_lock_key_code = key_code;

        StartTimer(
            KEYPAD_LOCK_TIMER,
            MMI_SLK_MANUAL_LOCK_TIMEOUT,
            mmi_slk_manual_lock_stop);

        SetKeyUpHandler(mmi_slk_manual_lock_hdlr, key_code);
    }
}
#endif

/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_start_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check error.
     */
    if (IsMyTimerExist(IDLE_APP_AUTO_LOCK_TIMER_ID))
    {
        MMI_SLK_LOG((TRC_MMI_SLK_START_TIMER, 500));
        return;
    }

#if !defined(__MMI_SCREEN_LOCK_ANY_TIME__) && !defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //&& !defined(__MMI_VUI_SCREEN_LOCK_KEY__)
    if (g_mmi_slk_cntx.suspend_count > 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_START_TIMER, 501));
        return;
    }
#endif

    if (mmi_scr_locker_is_locked())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_START_TIMER, 502));
        return;
    }

    /*
     * Start timer.
     */
    MMI_SLK_LOG((TRC_MMI_SLK_START_TIMER, 200));

    time = mmi_slk_auto_lock_get_time();
#ifdef 	__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
    time = TIMER_WDEVICE_VALUE ;
#endif
    if (time)
    {
        StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, time, mmi_slk_auto_lock_timeout_hdlr);
    }
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_restart_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_RESTART_TIMER, 200, __FILE__, __LINE__));

#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) //|| defined(__MMI_VUI_SCREEN_LOCK_KEY__)
    mmi_scr_locker_stop_timer();
    mmi_scr_locker_start_timer();
#else
    if (IsMyTimerExist(IDLE_APP_AUTO_LOCK_TIMER_ID))
    {
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
        mmi_scr_locker_start_timer();
    }
#endif
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_STOP_TIMER, 200));

    StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_suspend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.suspend_count >= UCHAR_MAX)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_SUSPEND, 400));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_SUSPEND, 200));

    /*
     * Suspend at the first time. Stop the timer.
     */
    if (g_mmi_slk_cntx.suspend_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_SUSPEND, 202));

        mmi_scr_locker_stop_timer();

        /* Notify locker. Note that locker might be absent at present. */
        if (obj && obj->on_suspend)
        {
            obj->on_suspend(obj, MMI_FALSE);   /* on before suspend */
        }
    }

    ++g_mmi_slk_cntx.suspend_count;
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.suspend_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_RESUME, 400));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_RESUME, 200));

    --g_mmi_slk_cntx.suspend_count;

    /*
     * No one suspends the timer. Restart it.
     */
    if (g_mmi_slk_cntx.suspend_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_RESUME, 202));

        mmi_scr_locker_start_timer();

        /* Notify locker. Note that locker might be absent at present. */
        if (obj && obj->on_resume)
        {
            obj->on_resume(obj, MMI_FALSE);    /* on after resume */
        }
    }
}


MMI_BOOL mmi_scr_locker_is_launched(void)
{
    return mmi_frm_group_is_present(GRP_ID_SLK_MAIN);
}


/* For the detail information, please refer to the ScrLockerGprot.h */
MMI_BOOL mmi_scr_locker_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Someone suspends the locker temporarily.
     */

    if (g_mmi_slk_cntx.suspend_count > 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_IS_LOCKED, 201, 0));
        return MMI_FALSE;
    }

    ret = mmi_slk_is_locked_internal();

    MMI_SLK_LOG((TRC_MMI_SLK_IS_LOCKED, 200, ret));

    return ret;
}


/* For the detail information, please refer to the ScrLockerGprot.h */
mmi_scr_locker_type_enum mmi_scr_locker_get_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.obj)
    {
        return (mmi_scr_locker_type_enum)g_mmi_slk_cntx.obj->type;
    }

    return MMI_SCR_LOCKER_TYPE_INVALID;
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_LAUNCH, 200));

    #ifdef __MMI_LAUNCHER_APP_LIST__
    if (mmi_applist_is_in_edit_mode())
    {
        mmi_applist_back_key_press();
        return;
    }
    #endif

    /* disable screen locker in Swatch */
    #ifdef __MMI_WEARABLE_DEVICE__
    return;
    #endif /*__MMI_WEARABLE_DEVICE__*/
	
    mmi_scr_locker_launch_ex(MMI_SCR_LOCKER_TYPE_UNSPECIFIED);
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_launch_ex(mmi_scr_locker_type_enum type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AP_DCM_SCRLOCK__
	mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SCRLOCK);
	//kal_prompt_trace(MOD_MMI," mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SCRLOCK)");
#endif

    /*
     * Do not lock when it is already locked.
     */
    if (mmi_slk_is_locked_internal())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAUNCH_EX, 500, type));
        return; /* fail-safe */
    }

    if(type == MMI_SCR_LOCKER_TYPE_UNSPECIFIED)
    {
        obj = (mmi_slk_obj_struct *)mmi_factory_new_obj(
                                        mmi_slk_get_cfg_table(),
                                        mmi_slk_buffer_malloc);
    }
    else
    {
        obj = (mmi_slk_obj_struct *)mmi_factory_new_obj_ex(
                                        type,
                                        mmi_slk_get_cfg_table(),
                                        mmi_slk_buffer_malloc);
    }

    if (!obj)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAUNCH_EX, 501, type));
        return;
    }

    /*
     * Lock the handset.
     */
    MMI_SLK_LOG((TRC_MMI_SLK_LAUNCH_EX, 200, type));

    MMI_ASSERT(obj->on_create);
    obj->on_create(obj, mmi_slk_main_evt_hdlr);

    MMI_ASSERT(obj->on_run);
    obj->on_run(obj);

    MMI_ASSERT(g_mmi_slk_cntx.obj == NULL);
    g_mmi_slk_cntx.obj = obj;

    if (obj->on_create == NULL)
    {
        //venus screen launch fail        
        mmi_scr_locker_close();
        srv_backlight_turn_off_ext();
        
        return;
    }

    /* APP can call this API to launch the locker directly. Always stop timer
       to avoid the complications. */
    mmi_scr_locker_stop_timer();

    /*
     * At present the screen locker will only display on the idle group. If the
     * idle group is not active, suspend it; otherwise, the lock icon will be
     * shown and the keypad tone will be stopped on other APP. (MAUI_02221788)
     */
#if !defined(__MMI_SCREEN_LOCK_ANY_TIME__) && !defined(__MMI_VUI_SCREEN_LOCK_KEY__) && !defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)  
    if (!mmi_idle_is_group_active())
    {
        mmi_scr_locker_suspend();
        MMI_SLK_SET(MMI_SLK_FLAG_SELF_SUSPEND);
    }
#endif
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_CLOSE, 200));

    if (mmi_slk_is_locked_internal())
    {
        MMI_ASSERT(obj && obj->on_close);
        obj->on_close(obj);
    }
    #if  defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE_APP_NO_CLOSE__)
	   cui_swatch_close();
	#endif
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_turn_on_backlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * The backlight should keep half bright to save power if
     *
     *  1) Handset is locked.
     *  2) Screen saver is running and it will suspend the screen locker.
     *
     */
    if ((mmi_scr_locker_is_locked()) 
    #if defined(__MMI_SCREEN_SAVER__)
        || (mmi_slk_is_locked_internal() && mmi_scr_saver_is_active())
    #endif
    )
    {
        MMI_SLK_LOG((TRC_MMI_SLK_TURN_ON_BACKLIGHT, 201));
        srv_backlight_half_mode();
    }
    else
    {
        MMI_SLK_LOG((TRC_MMI_SLK_TURN_ON_BACKLIGHT, 200));
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }
}
#if  defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE_APP_NO_CLOSE__)
static void mmi_scr_locker_pen_hdlrin_wdevice(mmi_pen_point_struct pos)
{
	 mmi_scr_locker_close();
}

static void mmi_scr_locker_exit_main_in_wdevice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return;
}

static void mmi_scr_locker_entry_main_in_wdevice(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 *guiBuffer = NULL;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	guiBuffer = mmi_frm_scrn_get_active_gui_buf();
	ShowCategory74Screen(
            NULL,
            NULL,
            0,
            0,
            NULL,
            NULL,
            (U8*)L"Just for test in screen locker ",
            mmi_wcslen((const WCHAR*)L"Just for test in screen locker "),
            guiBuffer);	
	return;
}

static mmi_ret mmi_scr_locker_main_proc_in_wdevice(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
       
        default:
            break;
    }
    
    return MMI_RET_OK;
}

void mmi_scr_locker_launch_in_wdevice(void)
{// APP_SCR_LOCKER

    if(!mmi_frm_group_is_present(GRP_ID_SLK_MAIN_WDEVICE))
    {
   		 mmi_frm_group_create_ex(
	        GRP_ID_ROOT, 
	        GRP_ID_SLK_MAIN_WDEVICE, 
	        mmi_scr_locker_main_proc_in_wdevice, 
	        NULL, 
	        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }


   cui_swatch_create_and_run(GRP_ID_SLK_MAIN_WDEVICE);
#if defined(__MMI_TOUCH_SCREEN__)

   wgui_register_pen_down_handler(mmi_scr_locker_pen_hdlrin_wdevice);
   wgui_register_pen_long_tap_handler(mmi_scr_locker_pen_hdlrin_wdevice);
   wgui_register_pen_up_handler(mmi_scr_locker_pen_hdlrin_wdevice);
#endif
   wgui_status_icon_bar_show_icon(STATUS_ICON_KEYPAD_LOCK);
   wgui_status_icon_bar_update();
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}

#endif

 
