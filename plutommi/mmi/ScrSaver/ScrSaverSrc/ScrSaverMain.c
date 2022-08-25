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
 *  ScrSaverMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the main component of the screen saver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SCREEN_SAVER__)
#include "IdleGprot.h"
#include "ScrLockerGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "GpioSrvGprot.h"
#include "WPSSProtos.h"
#include "ScrSaverObject.h"
#include "MMIDataType.h"
#include "PhoneSetup.h"
#include "ScrSaverMain.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "ScrSaverGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_rp_app_scr_saver_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "ScrSaverFactory.h"
#include "mmi_rp_app_idle_def.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_mem_gprot.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

/* Context structure of the screen saver. */
typedef struct
{
    mmi_ssv_obj_struct *obj;
} mmi_ssv_cntx_struct;


/****************************************************************************
 * Global variable
 ****************************************************************************/

/* Screen saver global context. */
static mmi_ssv_cntx_struct g_mmi_ssv_cntx;


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_auto_launch_get_time
 * DESCRIPTION
 *  This function gets the screen saver auto. launch time in msec.
 * PARAMETERS
 *  void
 * RETURNS
 *  Time in msec.
 *****************************************************************************/
static U32 mmi_ssv_auto_launch_get_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_auto_launch_timeout_hdlr
 * DESCRIPTION
 *  This function is the timeout handler for the screen saver.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_auto_launch_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_scr_saver_is_active())
    {
        MMI_SSV_LOG((TRC_MMI_SSV_AUTO_LAUNCH_TIMEOUT_HDLR, 500));
        return; /* fail-safe */
    }

    MMI_SSV_LOG((TRC_MMI_SSV_AUTO_LAUNCH_TIMEOUT_HDLR, 200));

    mmi_scr_saver_launch();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_emit_enter
 * DESCRIPTION
 *  This function posts the screen saver enter event.
 * PARAMETERS
 *  obj         : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_emit_enter(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scr_saver_enter_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_EMIT_ENTER, 200));

    MMI_ASSERT(obj);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCR_SAVER_ENTER);
    evt.type = obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_emit_exit
 * DESCRIPTION
 *  This function posts the screen saver exit event.
 * PARAMETERS
 *  obj         : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_emit_exit(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scr_saver_exit_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_EMIT_EXIT, 200));

    MMI_ASSERT(obj);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCR_SAVER_EXIT);
    evt.type = obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_bootup_early_init
 * DESCRIPTION
 *  This function initializes the context of the screen saver.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_bootup_early_init(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_mmi_ssv_cntx, 0, sizeof(mmi_ssv_cntx_struct));

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_shutdown_deinit
 * DESCRIPTION
 *  This function stops the screen saver when the handset shutdowns.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_shutdown_deinit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_SHUTDOWN_DEINIT, 200));

    mmi_scr_saver_stop_timer();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_idle_group_enter
 * DESCRIPTION
 *  This function handles the idle group enter event.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_idle_group_enter(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_IDLE_ENTER, 200));
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_idle_group_exit
 * DESCRIPTION
 *  This function handles the group exit event.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_idle_group_exit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_IDLE_GROUP_EXIT, 200));

    mmi_scr_saver_stop_timer();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_pre_key_routing
 * DESCRIPTION
 *  This function restarts the screen saver after the user's inputs.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_pre_key_routing(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_PRE_KEY_ROUTING, 200));
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_pre_touch_routing
 * DESCRIPTION
 *  This function restarts the screen saver after the user's touch inputs.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_pre_touch_routing(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_PRE_TOUCH_ROUTING, 200));
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_scr_locker_locked
 * DESCRIPTION
 *  This function handles the screen locker locked event.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_scr_locker_locked(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_struct *obj = g_mmi_ssv_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_SCR_LOCKER_LOCKED, 200));

    if (mmi_scr_saver_is_active())
    {
        MMI_ASSERT(obj && obj->on_scr_locker_locked);
        obj->on_scr_locker_locked(obj);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_gpio_lcd_sleep_in
 * DESCRIPTION
 *  This function handles the LCD sleep-in event.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_gpio_lcd_sleep_in(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_struct *obj = g_mmi_ssv_cntx.obj;
    mmi_scr_saver_type_enum favorite_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_GPIO_LCD_SLEEP_IN, 200));

    if (mmi_scr_saver_is_active())
    {
        MMI_ASSERT(obj && obj->on_backlight_changed);
        obj->on_backlight_changed(obj, MMI_FALSE);
    }
    else
    {
        favorite_type = mmi_factory_get_favorite_type(mmi_ssv_get_cfg_table()); 

        if (favorite_type == MMI_SCR_SAVER_TYPE_TIME)
        {
            mmi_scr_saver_launch_ex(favorite_type);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_gpio_lcd_sleep_out
 * DESCRIPTION
 *  This function handles the LCD sleep-out event.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_gpio_lcd_sleep_out(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_struct *obj = g_mmi_ssv_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_GPIO_LCD_SLEEP_OUT, 200));

    if (mmi_scr_saver_is_active())
    {
        MMI_ASSERT(obj && obj->on_backlight_changed);
        obj->on_backlight_changed(obj, MMI_TRUE);
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_ssv_handle_gpio_lcd_backlight_dimming(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status, time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_GPIO_BACKLIGHT_DIMMING, 200));
    PhnsetGetScrSvrSetings(&status, &time);
    if (status == SET_SS_STATUS_ON)
    {
        mmi_scr_saver_start_timer();
    }
    return MMI_RET_OK;
}


#if defined(__MMI_CLAMSHELL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_gpio_clam_open
 * DESCRIPTION
 *  This function handles the clam open event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_gpio_clam_open(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_GPIO_CLAM_OPEN, 200));

//#if defined(__MMI_CLAMOPEN_STOP_SCRSAVER__)
    if (mmi_scr_saver_is_active())
    {
        mmi_scr_saver_close();
    }
//#endif /* __MMI_CLAMOPEN_STOP_SCRSAVER__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_gpio_clam_close
 * DESCRIPTION
 *  This function handles the clam close event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_gpio_clam_close(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_GPIO_CLAM_CLOSE, 200));
    return MMI_RET_OK;
}
#endif /* defined(__MMI_CLAMSHELL__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_ssv_obj_close_req
 * DESCRIPTION
 *  This function handles the object close request.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_ssv_obj_close_req(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_SSV_OBJ_CLOSE_REQ, 200));

    mmi_scr_saver_close();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_handle_ssv_obj_closed_ind
 * DESCRIPTION
 *  This function handles the object closed indication.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_handle_ssv_obj_closed_ind(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_HANDLE_SSV_OBJ_CLOSED_IND, 200));
    g_mmi_ssv_cntx.obj = NULL;

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_main_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler of screen saver.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ssv_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
            ret = mmi_ssv_handle_bootup_early_init(event);
            break;

        case EVT_ID_SRV_SHUTDOWN_DEINIT:
            ret = mmi_ssv_handle_shutdown_deinit(event);
            break;

        case EVT_ID_IDLE_GROUP_ENTER:
            ret = mmi_ssv_handle_idle_group_enter(event);
            break;

        case EVT_ID_IDLE_GROUP_EXIT:
            ret = mmi_ssv_handle_idle_group_exit(event);
            break;

        case EVT_ID_PRE_KEY_EVT_ROUTING:
            ret = mmi_ssv_handle_pre_key_routing(event);
            break;

        case EVT_ID_PRE_TOUCH_EVT_ROUTING:
            ret = mmi_ssv_handle_pre_touch_routing(event);
            break;
            
        case EVT_ID_SCR_LOCKER_LOCKED:
            ret = mmi_ssv_handle_scr_locker_locked(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_IN:
            ret = mmi_ssv_handle_gpio_lcd_sleep_in(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_OUT:
            ret = mmi_ssv_handle_gpio_lcd_sleep_out(event);
            break;

        case EVT_ID_GPIO_BACKLIGHT_DIMMING:
            ret = mmi_ssv_handle_gpio_lcd_backlight_dimming(event);
            break;

    #if defined(__MMI_CLAMSHELL__)
        case EVT_ID_GPIO_CLAM_OPEN:
            ret = mmi_ssv_handle_gpio_clam_open(event);
            break;

        case EVT_ID_GPIO_CLAM_CLOSE:
            ret = mmi_ssv_handle_gpio_clam_close(event);
            break;
    #endif /* defined(__MMI_CLAMSHELL__) */

        case EVT_ID_SSV_OBJ_CLOSE_REQ:
            ret = mmi_ssv_handle_ssv_obj_close_req(event);
            break;

        case EVT_ID_SSV_OBJ_CLOSED_IND:
            ret = mmi_ssv_handle_ssv_obj_closed_ind(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/* For the detail information, please refer to the ScrSaverGprot.h */
void mmi_scr_saver_start_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsMyTimerExist(SCREENSAVER_TIMER) || mmi_scr_saver_is_active())
    {
        MMI_SSV_LOG((TRC_MMI_SSV_START_TIMER, 500));
        return; /* fail-safe */
    }

    MMI_SSV_LOG((TRC_MMI_SSV_START_TIMER, 200));

    time = MMI_SCREEN_SAVER_TIMER_FROM_DIMMING * 1000; 
    StartTimer(SCREENSAVER_TIMER, time, mmi_ssv_auto_launch_timeout_hdlr);
}


/* For the detail information, please refer to the ScrSaverGprot.h */
void mmi_scr_saver_restart_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_RESTART_TIMER, 200));

    if (IsMyTimerExist(SCREENSAVER_TIMER))
    {
        StopTimer(SCREENSAVER_TIMER);
        mmi_scr_saver_start_timer();
    }
}


/* For the detail information, please refer to the ScrSaverGprot.h */
void mmi_scr_saver_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_STOP_TIMER, 200));

    StopTimer(SCREENSAVER_TIMER);
}


/* For the detail information, please refer to the ScrSaverGprot.h */
MMI_BOOL mmi_scr_saver_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = (g_mmi_ssv_cntx.obj ? MMI_TRUE : MMI_FALSE);

    MMI_SSV_LOG((TRC_MMI_SSV_IS_ACTIVE, 200, ret));

    return ret;
}


/* For the detail information, please refer to the ScrSaverGprot.h */
void mmi_scr_saver_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_LAUNCH, 200));

    mmi_scr_saver_launch_ex(MMI_SCR_SAVER_TYPE_UNSPECIFIED);
}


/* For the detail information, please refer to the ScrSaverGprot.h */
void mmi_scr_saver_launch_ex(mmi_scr_saver_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Do not launch screen saver again if it is running.
     */
    if (mmi_scr_saver_is_active())
    {
        MMI_SSV_LOG((TRC_MMI_SSV_LAUNCH_EX, 500, type));
        return; /* fail-safe */
    }

    /*
     * Cannot launch screen saver if idle group is not active.
     */
    if (!mmi_idle_is_group_active())
    {
        MMI_SSV_LOG((TRC_MMI_SSV_LAUNCH_EX, 501, type));
        return;
    }

    /*
     * For UE behavior. If the handset is locked by LAWMO, only emergency call
     * is allowable. Do not display screen saver here.
     */
    if (mmi_scr_locker_get_type() == MMI_SCR_LOCKER_TYPE_LAWMO)
    {
        MMI_SSV_LOG((TRC_MMI_SSV_LAUNCH_EX, 502, type));
        return;
    }

    if(type == MMI_SCR_SAVER_TYPE_UNSPECIFIED)
    {
        obj = (mmi_ssv_obj_struct *)mmi_factory_new_obj(mmi_ssv_get_cfg_table(), mmi_ssv_buffer_malloc);
    }
    else
    {
        obj = (mmi_ssv_obj_struct *)mmi_factory_new_obj_ex(type, mmi_ssv_get_cfg_table(), mmi_ssv_buffer_malloc);
    }
    if (!obj)
    {
        MMI_SSV_LOG((TRC_MMI_SSV_LAUNCH_EX, 501, type));
        return;
    }

    /*
     * Ready to launch screen saver.
     */
    MMI_SSV_LOG((TRC_MMI_SSV_LAUNCH_EX, 200, type));

    /*
     * CR: [MAUI_02322951] 
     * Cause:In obj->on_run, category224 will callback PhnsetScreenSaverBadFileCallBack 
     * if file access error, it will delete screen saver group as well as context.
     * In previous version,screen saver will set obj pointer after obj->on_run, 
     * It is wrong because screen saver context will be set again after delete during obj->on_run
     *
     * Solution: move g_mmi_ssv_cntx.obj = obj above obj->on_create
     */
    MMI_ASSERT(g_mmi_ssv_cntx.obj == NULL);
    g_mmi_ssv_cntx.obj = obj;
    
    MMI_ASSERT(obj->on_create);
    obj->on_create(obj, mmi_ssv_main_evt_hdlr);

    MMI_ASSERT(obj->on_run);
    obj->on_run(obj);

    /* APP can call this API to launch the saver directly. Always stop timer
       to avoid the complications. */
    mmi_scr_saver_stop_timer();
}


/* For the detail information, please refer to the ScrSaverGprot.h */
void mmi_scr_saver_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_struct *obj = g_mmi_ssv_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_CLOSE, 200));

    if (mmi_scr_saver_is_active())
    {
        MMI_ASSERT(obj && obj->on_close);
        obj->on_close(obj);
    }
}


/* For the detail information, please refer to the ScrSaverGprot.h */
void mmi_scr_saver_date_time_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_struct *obj = g_mmi_ssv_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SSV_LOG((TRC_MMI_SSV_DATE_TIME_IND_HDLR, 200));

    if (mmi_scr_saver_is_active())
    {
        MMI_ASSERT(obj && obj->on_time_changed);
        obj->on_time_changed(obj);
    }
}
#endif /* defined(__MMI_SCREEN_SAVER__) */
