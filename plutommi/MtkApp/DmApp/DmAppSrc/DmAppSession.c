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
 *  DmAppSession.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM application session screens
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#include "MMIDataType.h"
#include "NotificationGprot.h"
#include "Wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "AlertScreen.h"
#include "DmAppSession.h"
#include "DmSrvIprot.h"
#include "mmi_rp_srv_dm_def.h"
#include "TimerEvents.h"
#include "custom_events_notify.h"

/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Static Variable
*****************************************************************************/

/****************************************************************************
* Local Function
*****************************************************************************/

void mmi_dm_session_notification_srv_cb_hdlr(dm_ui_mode_enum ui_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ui_mode)
    {
        case DM_UI_MODE_BACKGROUND:
            break;

        case DM_UI_MODE_INFORMATION:
        {
            mmi_dm_session_notification_display_info();
            break;
        }

        case DM_UI_MODE_USERINTERACTION:
        {
            mmi_dm_session_notification_display_cnf_via_nmgr();
            break;
        }

        default:
            break;
    }
}


void mmi_dm_session_notification_display_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_popup(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_INFO,
        (WCHAR*)GetString(STR_ID_DM_SESSION_NOTIFICATION_INFO));
}


void mmi_dm_session_notification_display_cnf_via_nmgr(void)
{
    if (MMI_TRUE == mmi_frm_nmgr_is_scenario_deferred(
                        MMI_SCENARIO_ID_DM,
                        mmi_dm_session_notification_display_cnf_nmgr_hdlr,
                        NULL))
    {
        return;
    }

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_DEFAULT,
        mmi_dm_session_notification_display_cnf_nmgr_hdlr,
        NULL);
}


MMI_BOOL mmi_dm_session_notification_display_cnf_nmgr_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsMyTimerExist(TIMER_ID_DM_SRV_NOTIFICATION_CNF_USER_INTERACTION))
    {
        StartTimer(
            TIMER_ID_DM_SRV_NOTIFICATION_CNF_USER_INTERACTION,
            SRV_DM_TIME_NOTIFICATION_CNF_USER_INTERACTION,
            mmi_dm_session_notification_cnf_user_interaction_timeout_hdlr);
    }
    else    /* timer is running and user no response */
    {
        return MMI_TRUE;
    }

    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        NULL,
        NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dm_session_notification_display_cnf();
    return MMI_TRUE;
}


void mmi_dm_session_notification_display_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DM_NOTIFICATION_CNF,
                        NULL,
                        (FuncPtr)mmi_dm_session_notification_display_cnf, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DM_NOTIFICATION_CNF,
            mmi_dm_session_notification_cnf_leave_proc);

        ShowCategory165Screen(
            STR_GLOBAL_CONFIRM,
            IMG_GLOBAL_OK,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            (UI_string_type)GetString(STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION),
            mmi_get_event_based_image(MMI_EVENT_QUERY),
            gui_buffer);
        SetLeftSoftkeyFunction(mmi_dm_session_notification_cnf_lsk_hdlr, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dm_session_notification_cnf_csk_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_dm_session_notification_cnf_rsk_hdlr, KEY_EVENT_UP);
    }
}


void mmi_dm_session_notification_cnf_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_session_notification_app_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
    mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
}


void mmi_dm_session_notification_cnf_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_session_notification_cnf_lsk_hdlr();
}


void mmi_dm_session_notification_cnf_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_session_notification_app_rsp(DM_UI_INTERACTION_ACTION_REJECT);
    mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
}


mmi_ret mmi_dm_session_notification_cnf_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //TODO: notify service defer
    
    StopTimer(TIMER_ID_DM_SRV_NOTIFICATION_CNF_USER_INTERACTION);

    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        srv_dm_session_notification_app_rsp(DM_UI_INTERACTION_ACTION_DEFER);
    }

    return MMI_RET_ALLOW_CLOSE;
}


void mmi_dm_session_notification_cnf_user_interaction_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DM_NOTIFICATION_CNF);
    srv_dm_session_notification_app_rsp(DM_UI_INTERACTION_ACTION_CANCEL);
}


void mmi_dm_session_alert_srv_cb_hdlr(dm_alert_type_enum alert_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (alert_type)
    {
        case DM_UI_INTERACTION_DISPLAY:
        {
            mmi_dm_session_alert_display_info_via_nmgr();
            break;
        }

        case DM_UI_INTERACTION_CONFIRM:
        {
            mmi_dm_session_alert_display_cnf_via_nmgr();
            break;
        }

        default:
            break;
    }
}


void mmi_dm_session_alert_display_info_via_nmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 min_dt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_dm_session_alert_get_option_val(DM_ALERT_MINDT_MASK, &min_dt))
    {
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_INFO,
            mmi_dm_session_alert_display_info_nmgr_hdlr,
            NULL);
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DM,
            MMI_EVENT_INFO,
            srv_dm_session_alert_get_display_str_ptr());
    }
}


MMI_BOOL mmi_dm_session_alert_display_info_nmgr_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        NULL,
        NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dm_session_alert_display_info();
    return MMI_TRUE;
}


void mmi_dm_session_alert_display_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    dm_alert_rsp_struct alert_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    if (MMI_FALSE == srv_dm_session_alert_get_option_val(
                        DM_ALERT_MINDT_MASK,
                        &arg.duration))
    {
        arg.duration = SRV_DM_TIME_ALERT_DEFAULT_MINDT;
    }
    arg.parent_id = GRP_ID_DMAPP_GLOBAL;

    mmi_popup_display(
        srv_dm_session_alert_get_display_str_ptr(),
        MMI_EVENT_INFO,
        &arg);

    alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
    srv_dm_session_alert_app_rsp(&alert_rsp);
}


void mmi_dm_session_alert_display_cnf_via_nmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_nmgr_is_scenario_deferred(
                        MMI_SCENARIO_ID_DM,
                        mmi_dm_session_alert_display_cnf_nmgr_hdlr,
                        NULL))
    {
        return;
    }

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DM,
        MMI_EVENT_DEFAULT,
        mmi_dm_session_alert_display_cnf_nmgr_hdlr,
        NULL);
}


MMI_BOOL mmi_dm_session_alert_display_cnf_nmgr_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == srv_dm_session_alert_get_option_val(
                        DM_ALERT_MAXDT_MASK,
                        &duration_time))
    {
        duration_time = SRV_DM_TIME_ALERT_DEFAULT_MAXDT;
    }

    if (!IsMyTimerExist(TIMER_ID_DM_SRV_ALERT_CNF_USER_INTERACTION))
    {
        StartTimer(
            TIMER_ID_DM_SRV_ALERT_CNF_USER_INTERACTION,
            duration_time,
            mmi_dm_session_alert_cnf_user_interaction_timeout_hdlr);
    }
    else    /* timer is running and user no response */
    {
        return MMI_TRUE;
    }

    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_DMAPP_GLOBAL,
        NULL,
        NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_GLOBAL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_dm_session_alert_display_cnf();
    return MMI_TRUE;
}


void mmi_dm_session_alert_display_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_GLOBAL, 
                        SCR_ID_DM_ALERT_CNF,
                        NULL,
                        (FuncPtr)mmi_dm_session_alert_display_cnf, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_GLOBAL,
            SCR_ID_DM_ALERT_CNF,
            mmi_dm_session_alert_cnf_leave_proc);

        ShowCategory165Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_NO,
            (UI_string_type)srv_dm_session_alert_get_display_str_ptr(),
            mmi_get_event_based_image(MMI_EVENT_QUERY),
            gui_buffer);
        
        SetLeftSoftkeyFunction(mmi_dm_session_alert_cnf_lsk_hdlr, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dm_session_alert_cnf_csk_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_dm_session_alert_cnf_rsk_hdlr, KEY_EVENT_UP);
    }
}


void mmi_dm_session_alert_cnf_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct alert_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
    srv_dm_session_alert_app_rsp(&alert_rsp);
    mmi_frm_scrn_close_active_id();
}


void mmi_dm_session_alert_cnf_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dm_session_alert_cnf_lsk_hdlr();
}


void mmi_dm_session_alert_cnf_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct alert_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_REJECT;
    srv_dm_session_alert_app_rsp(&alert_rsp);
    mmi_frm_scrn_close_active_id();
}


mmi_ret mmi_dm_session_alert_cnf_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct alert_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TIMER_ID_DM_SRV_ALERT_CNF_USER_INTERACTION);

    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_DEFER;
        srv_dm_session_alert_app_rsp(&alert_rsp);
    }

    return MMI_RET_ALLOW_CLOSE;
}


void mmi_dm_session_alert_cnf_user_interaction_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct alert_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_DMAPP_GLOBAL, SCR_ID_DM_ALERT_CNF);
    alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;
    srv_dm_session_alert_app_rsp(&alert_rsp);
}


void mmi_dm_session_display_ending_msg(srv_dm_app_adp_session_ending_msg_enum ending_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ending_msg)
    {
        case SRV_DM_APP_ADP_SESSION_ENDING_MSG_NONE:
            break;

        case SRV_DM_APP_ADP_SESSION_ENDING_MSG_SESSION_FAIL:
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_SESSION_FAILURE));
            break;
        }

        case SRV_DM_APP_ADP_SESSION_ENDING_MSG_NO_MEM:
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
            break;
        }

        case SRV_DM_APP_ADP_SESSION_ENDING_MSG_TIMEOUT:
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DM,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_ID_DMUI_TIMEOUT_POPUP));
            break;
        }

        default:
            break;
    }
}


void mmi_dm_session_abort_srv_cb_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_DMAPP_GLOBAL);
}
