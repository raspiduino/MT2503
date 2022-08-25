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
 *  BootupAdp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Adaptors for bootup.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
 
#include "MMI_features.h"
#include "BootupAppProt.h"
#include "PhoneSetupGprots.h"   /* PhnsetNeedFactoryDefaultCalibration */
#include "FlightModeGProt.h"    /* mmi_flight_mode_update_status_icon, mmi_frm_power_on_init_procedure */
#include "mmi_frm_prot.h"       /* InitNvramData */
#include "gpiosrvgprot.h"       /* srv_gpio_check_pwron_ready */
#include "NwInfoSrvGprot.h"
#include "CharBatSrvGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ProcedureGprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "SimCtrlSrvGprot.h"
#include "BootupSrvIprot.h"
#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_bootup_def.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "string.h"
#include "GlobalResDef.h"
#include "device.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "mmi_rp_app_charger_def.h"
#include "wgui_categories_util.h"
#ifndef __MTK_TARGET__ /* on MODIS */
#include "w32_utility.h"
#endif


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    MMI_BOOL is_arrived;
    MMI_BOOL waiting;
    mmi_frm_proc_id_info_struct id_info;
} mmi_bootup_gpio_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static mmi_bootup_gpio_cntx_struct g_mmi_bootup_gpio_cntx =
{
    MMI_FALSE,
    MMI_FALSE
};


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_bootup_notify_gpio_arrived(void *para, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_wait_for_gpio
 * DESCRIPTION
 *  Wait for GPIO.
 * PARAMETERS
 *  arg     [IN] Unused
 *  id_info [IN] To be passed into mmi_frm_proc_notify_completed()
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bootup_wait_for_gpio(
                            void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__

    g_mmi_bootup_gpio_cntx.is_arrived = srv_gpio_check_pwron_ready(
        mmi_bootup_notify_gpio_arrived,
        &g_mmi_bootup_gpio_cntx);

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_WAIT_FOR_GPIO,
        g_mmi_bootup_gpio_cntx.is_arrived);

    if (g_mmi_bootup_gpio_cntx.is_arrived)
    {
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    g_mmi_bootup_gpio_cntx.waiting = MMI_TRUE;
    g_mmi_bootup_gpio_cntx.id_info = id_info;
    
    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    
#else /* __MTK_TARGET__ */

    /* We don't need to wait for GPIO */
    return MMI_FRM_PROC_RESULT_COMPLETED;

#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_notify_gpio_arrived
 * DESCRIPTION
 *  For GPIO module to notify GPIO required message has been arrived.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_notify_gpio_arrived(void *para, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_NOTIFY_GPIO_ARRIVED,
        g_mmi_bootup_gpio_cntx.waiting);
    
    g_mmi_bootup_gpio_cntx.is_arrived = MMI_TRUE;

    if (g_mmi_bootup_gpio_cntx.waiting)
    {
        g_mmi_bootup_gpio_cntx.waiting = MMI_FALSE;
        mmi_frm_proc_notify_completed(g_mmi_bootup_gpio_cntx.id_info);
    }
}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * [Pen calibration]
 *
 *
 *****************************************************************************/

typedef struct
{
    mmi_id grp_id;
    void (*completed_callback)(void *user_data);
    void *user_data;
} g_mmi_bootup_pen_cal_session_struct;


/*****************************************************************************
 * Global variables
 *****************************************************************************/

static struct
{
    mmi_frm_proc_id_info_struct id_info;
} g_mmi_bootup_pen_cal_cntx;


/*****************************************************************************
 * Functions
 *****************************************************************************/ 

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_needs_pen_calibration
 * DESCRIPTION
 *  To determine if it needs pen calibration.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if needed.
 *****************************************************************************/
MMI_BOOL mmi_bootup_needs_pen_calibration(void)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__

    return (PhnsetNeedFactoryDefaultCalibration() &&
            !srv_bootup_is_auto_power_on_test() &&
            !w32_modis_is_disable_touchscreencalibration());
            
#else /* __MTK_TARGET__ */

    return (PhnsetNeedFactoryDefaultCalibration() &&
            !srv_bootup_is_auto_power_on_test());
            
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_pen_calibration_complete
 * DESCRIPTION
 *  Callback for pen calibration request.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_pen_calibration_complete(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_pen_cal_session_struct *session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL && evt->user_data != NULL);
    session = (g_mmi_bootup_pen_cal_session_struct*)(evt->user_data);

    mmi_frm_scrn_set_leave_proc(
        session->grp_id,
        SCR_ID_BOOTUP_PEN_CALIBRATION_BASE,
        NULL);
    session->completed_callback(session->user_data);
    mmi_frm_scrn_close(session->grp_id, SCR_ID_BOOTUP_PEN_CALIBRATION_BASE);
    OslMfree(session);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_pen_calibration_entry_completed
 * DESCRIPTION
 *  The entry function of the base screen to detect pen-calibration completion.
 * PARAMETERS
 *  es_data     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_pen_calibration_entry_completed(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_pen_cal_session_struct *session;
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(es_data != NULL && es_data->user_data != NULL);
    session = (g_mmi_bootup_pen_cal_session_struct*)es_data->user_data;
    
    if (!mmi_frm_scrn_enter(
        session->grp_id,
        SCR_ID_BOOTUP_PEN_CALIBRATION_BASE,
        NULL,
        (FuncPtr)mmi_bootup_pen_calibration_entry_completed,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategoryDummyScreen();
    
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }
    
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    MMI_FRM_INIT_EVENT(&evt, 0);
    MMI_FRM_POST_EVENT(&evt, mmi_bootup_pen_calibration_complete, session);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_pen_calibration_leave_hdlr
 * DESCRIPTION
 *  To avoid the base screen from being closed by End key.
 * PARAMETERS
 *  evt     [IN] mmi_scenario_evt_struct*
 * RETURNS
 *  -1 for deleting events
 *****************************************************************************/
static mmi_ret mmi_bootup_pen_calibration_leave_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
         return -1; /* Forbid closing */
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_show_pen_calibration
 * DESCRIPTION
 *  Show pen calibration screen.
 * PARAMETERS
 *  grp_id                  [IN] Group ID
 *  completed_callback      [IN] Callback for completion.
 *  user_data               [IN] To be passed into completed_callback().
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_show_pen_calibration(
        mmi_id grp_id,
        void (*completed_callback)(void *user_data),
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_pen_cal_session_struct *session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(completed_callback != NULL);

    EntryPhnseFactoryDefaultCalibrationScr(GoBackHistory);
    
    session = (g_mmi_bootup_pen_cal_session_struct*)
        OslMalloc(sizeof(g_mmi_bootup_pen_cal_session_struct));
    session->grp_id = grp_id;
    session->completed_callback = completed_callback;
    session->user_data = user_data;

    /*
     * Because EntryPhnseFactoryDefaultCalibrationScr() may not callback,
     * we should detect its destroy by a base entry function.
     */
    mmi_frm_scrn_first_enter(
        grp_id,
        SCR_ID_BOOTUP_PEN_CALIBRATION_BASE,
        (FuncPtr)mmi_bootup_pen_calibration_entry_completed,
        session);

    mmi_frm_scrn_set_leave_proc(
        grp_id,
        SCR_ID_BOOTUP_PEN_CALIBRATION_BASE,
        mmi_bootup_pen_calibration_leave_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_pen_calibration_completed
 * DESCRIPTION
 *  The complete callback of pen calibration.
 *  Continue next step of bootup flow.
 * PARAMETERS
 *  user_data   [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_flow_pen_calibration_completed(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_notify_completed(g_mmi_bootup_pen_cal_cntx.id_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_pen_calibration
 * DESCRIPTION
 *  Do pen calibration if necessary.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed()
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bootup_flow_pen_calibration(
                            void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_pen_cal_cntx.id_info = id_info;
    
    if (mmi_bootup_needs_pen_calibration())
    {
        mmi_bootup_show_pen_calibration(
            GRP_ID_BOOTUP,
            mmi_bootup_flow_pen_calibration_completed,
            &(g_mmi_bootup_pen_cal_cntx));
            
        return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    }

    return MMI_FRM_PROC_RESULT_COMPLETED;
}
#endif /* __MMI_TOUCH_SCREEN__ */



/*****************************************************************************
 * [Battery (Device power)]
 *
 *
 *****************************************************************************/

/*****************************************************************************
 * Global variables
 *****************************************************************************/

static struct
{
    mmi_frm_proc_id_info_struct id_info;
} g_mmi_bootup_battery_cntx;


/*****************************************************************************
 * Functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_ultra_low_power
 * DESCRIPTION
 *  Is ultra low-power?
 *  If yes, system should be shutdown.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE is low-power.
 *****************************************************************************/
MMI_BOOL mmi_bootup_is_ultra_low_power(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL charger_disconnected;
    MMI_BOOL ultra_low_power;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    charger_disconnected =
        (MMI_BOOL) !srv_charbat_is_charging();

    if (srv_charbat_get_battery_level() == SRV_CHARBAT_BATTERY_LOW_POWEROFF)
		ultra_low_power = MMI_TRUE;
	else
		ultra_low_power = MMI_FALSE;
    
    return (MMI_BOOL) (charger_disconnected && ultra_low_power);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_low_battery_warning_proc
 * DESCRIPTION
 *  Callback for the low-battery warning popup.
 *  Continue to flow.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_low_battery_warning_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_POPUP_QUIT)
    {
        mmi_frm_proc_notify_completed(g_mmi_bootup_battery_cntx.id_info);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_battery_check
 * DESCRIPTION
 *  Battery power check.
 *  If the battery power is low, popup an warning message to user.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed().
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bootup_flow_battery_check(
                            void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_battery_cntx.id_info = id_info;
    
    if (!srv_charbat_is_charging() &&
        srv_charbat_get_battery_level() <= SRV_CHARBAT_BATTERY_LOW_WARNING)
    {
        mmi_popup_property_init(&popup_arg);
        popup_arg.parent_id = GRP_ID_BOOTUP;
        popup_arg.callback = mmi_bootup_low_battery_warning_proc;
        popup_arg.user_tag = &(g_mmi_bootup_battery_cntx);
        if (mmi_popup_display(
                get_string(STR_LOW_BATTERY),
                EVENT_BATTERY_WARNING,
                &popup_arg))
        {
            return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
        }
    }

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_set_icons
 * DESCRIPTION
 *  Set icons before entering Idle.
 *  Some applications may be their icons during booting, but flight mode may
 *  mis-checks the temporary states of booting and hides the icons. Call
 *  flight mode's update function to recover them by the final state.
 * PARAMETERS
 *  evt     [IN] srv_bootup_before_idle_evt_struct *
 * RETURNS
 *  MMI_RET_OK to continue event routing
 *****************************************************************************/
mmi_ret mmi_bootup_set_icons(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__    
    mmi_flight_mode_update_status_icon();
#endif
    return MMI_RET_OK;
}

