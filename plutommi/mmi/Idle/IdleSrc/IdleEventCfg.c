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
 *  IdleEventCfg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file configures the event on the idle screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "CallLogGprot.h"
#include "MessagesExDcl.h"
#include "NITZ.h"
#include "PhoneBookGprot.h"
#include "NetworkSetupGProt.h"
#include "CbsAppGprot.h"
#include "IdleNotificationManager.h"
#include "NwInfoGprot.h"
#include "SimCtrlGprot.h"
#include "SmsAppGprot.h"
#include "MessagesMiscell.h"
#ifdef __J2ME__
#include "JavaAgencyGProt.h"
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxAPPGProt.h"
#endif

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif

#if 0
#ifdef __MMI_VOIP__
/* under construction !*/
#endif
#endif

#ifdef __MMI_AUTO_ANSWER_MACHINE__
#include "AnswerMachineGprot.h"
#endif

#if 0
#ifdef __MMI_IMPS__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_IRDA_SUPPORT__
/* under construction !*/
#endif
#endif

#if defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
#include "BTMMIObexGprots.h"
#endif

#ifdef __MMI_DOWNLOAD_AGENT__
#include "DLAgentSrvGProt.h"
#endif

#if defined(__SYNCML_SUPPORT__) //&& !defined(__MMI_OP01_SYNCML_SETTING__)
#include "SyncMLGProt.h"
#endif

#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif

#ifdef __DRM_SUPPORT__
#include "RightsMgrGProt.h"
#endif

#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
#include "FileMgrSrvIProt.h"
#endif

#ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__
#include "ModeSwitchAppGprot.h"
#endif

// auto add by kw_check begin
#include "IdleEventCfg.h"
#include "NotificationGprot.h"
#include "WAPPushSrvGprots.h"
// auto add by kw_check end 

/**********************************************************************
 * Configuration
 **********************************************************************/

const static mmi_idle_event_struct g_idle_event_cfg_tbl[] =
{
#ifdef __MMI_NW_INFO_INVALID_SIM_MESSAGE__
    MMI_IDLE_EVENT_ADD(
        mmi_nw_info_any_invalid_sim_msg_is_pending,
        mmi_nw_info_display_invalid_sim
    ),
#endif /* __MMI_NW_INFO_INVALID_SIM_MESSAGE__ */

#if 0
#if defined(__MMI_OP11_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_IMPS__) */
#endif

    MMI_IDLE_EVENT_ADD(
        mmi_frm_nmgr_get_defer_notification_count,
        mmi_frm_nmgr_invoke_deder_event
    ),

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    MMI_IDLE_EVENT_ADD(
        mmi_nmgr_need_notification,
        mmi_nmgr_direct_notify
    ),
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#if defined(__J2ME__)
    MMI_IDLE_EVENT_ADD(
        mmi_java_is_launch_from_idle,
        mmi_java_entry_mid_launch_from_idle
    ),
    MMI_IDLE_EVENT_ADD(
        mmi_java_timealarm_islock,
        mmi_java_timealarm_unlock
    ),
#endif /* defined(__J2ME__) */

#if 0
#if defined(__J2ME__) && defined(__DM_SCOMO_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__J2ME__) && defined(__DM_SCOMO_SUPPORT__) */
#endif

#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)
    MMI_IDLE_EVENT_ADD(
        mmi_clog_nmgr_check,
        mmi_clog_nmgr_enter
    ),
#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */

#if defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    MMI_IDLE_EVENT_ADD(
        mmi_msg_need_new_sim_msg_ind,
        mmi_msg_entry_new_sim_msg_ind
    ),
#endif /* defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) */

#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)
    MMI_IDLE_EVENT_ADD(
        mmi_provbox_idle_new_msg_check,
        mmi_provbox_idle_new_msg_ind
    ),
#endif /* defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) */
#ifdef __MMI_TELEPHONY_SUPPORT__
    MMI_IDLE_EVENT_ADD(
        mmi_msg_need_mem_exceed_ind,
        mmi_msg_entry_mem_exceed_ind
    ),

    MMI_IDLE_EVENT_ADD(
        mmi_sms_report_available,
        mmi_sms_report_ind_idle_launch
    ),
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    MMI_IDLE_EVENT_ADD(
        mmi_msg_need_waiting_ind,
        mmi_msg_entry_msg_waiting_ind
    ),
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#if defined(__MMI_EMAIL__)
    MMI_IDLE_EVENT_ADD(
        mmi_email_check_show_idle_data,
        mmi_email_show_idle_data
    ),
#endif /* defined(__MMI_EMAIL__) */

#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_VOIP__) */
#endif

#if defined(__MMI_AUTO_ANSWER_MACHINE__)
    MMI_IDLE_EVENT_ADD(
        mmi_autoam_need_msg_waiting_ind,
        mmi_autoam_entry_msg_waiting_ind
    ),
#endif /* defined(__MMI_AUTO_ANSWER_MACHINE__) */

#if 0
#if defined(__MMI_IRDA_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IRDA_SUPPORT__) */
/* under construction !*/
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) && defined(__MMI_IRDA_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) && defined(__MMI_IRDA_SUPPORT__) */
#endif

#if defined(__MMI_NITZ__)
    MMI_IDLE_EVENT_ADD(
        mmi_nitz_is_need_update,
        mmi_nitz_entry_nitz_confirm_screen
    ),
#endif /* defined(__MMI_NITZ__) */
#ifdef __MMI_CBS_SUPPORT__
    MMI_IDLE_EVENT_ADD(
        mmi_cbs_need_new_cb_ind,
        mmi_cbs_entry_new_cb_ind
    ),
#endif

#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)
    MMI_IDLE_EVENT_ADD(
        mmi_phb_init_check_sim_change,
        NULL
    ),
#endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */

#if (defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)) && !defined(__MMI_NCENTER_SUPPORT__)
    MMI_IDLE_EVENT_ADD(
        mmi_bt_recv_files_exist,
        mmi_bt_entry_idle_notify_scr
    ),
#endif /* defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__) */

#if defined(__MMI_DOWNLOAD_AGENT__)
    MMI_IDLE_EVENT_ADD(
        mmi_da_launch_ring_buffer_check,
        mmi_da_entry_new_push_ind
    ),
#endif /* defined(__MMI_DOWNLOAD_AGENT__) */

#if defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
    MMI_IDLE_EVENT_ADD(
        srv_wap_push_check_pendig_event_on_idle,
        srv_wap_push_handle_pendig_event_on_idle
    ),

    MMI_IDLE_EVENT_ADD(
        srv_wap_push_service_dlg_idle_scr_cb,
        srv_wap_push_fetch_dlg_from_queue
    ),
#endif /* defined(__WAP_PUSH_SUPPORT__) */

#if defined(__SYNCML_SUPPORT__) //&& !defined(__MMI_OP01_SYNCML_SETTING__)
    MMI_IDLE_EVENT_ADD(
        mmi_syncml_is_sync_alarm_expired,
        mmi_syncml_sync_alarm_hdlr
    ),
#endif /* defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__) */

#if 0
#if defined(__MMI_USER_CTRL_PLMN_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_USER_CTRL_PLMN_SUPPORT__) */
#endif

#if defined(__FOTA_PROPRIETARY__)
    MMI_IDLE_EVENT_ADD(
        mmi_dm_fwu_check_download_finish,
        mmi_dm_fwu_entry_download_finish_ind
    ),
#endif /* defined(__FOTA_PROPRIETARY__) */

#if defined(__CERTMAN_SUPPORT__)
    MMI_IDLE_EVENT_ADD(
        mmi_certman_idle_check,
        mmi_certman_ui_entry_idle_screen
    ),
#endif /* defined(__CERTMAN_SUPPORT__) */

#if defined(__DRM_SUPPORT__)
    MMI_IDLE_EVENT_ADD(
        mmi_rmgr_space_check,
        mmi_rmgr_entry_db_check
    ),
#endif /* defined(__DRM_SUPPORT__) */

#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP11__ */
#endif

#if defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
    MMI_IDLE_EVENT_ADD(
        srv_fmgr_default_storage_need_confirm,
        srv_fmgr_default_storage_do_confirm
    ),
#endif /* defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__) */

#if defined(__MMI_NETSET_3G_ENHANCE__)
    MMI_IDLE_EVENT_ADD(
        mmi_netset_rat_idle_notify,
        mmi_netset_rat_selection
    ),
#endif /* defined(__MMI_NETSET_3G_ENHANCE__) */

#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */

#if defined(__MMI_PHB_STARTUP_COPY_SIM__)
    MMI_IDLE_EVENT_ADD(
        mmi_phb_startup_copy_sim_check,
        mmi_phb_startup_copy_sim_pre_entry
    ),
#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_IDLE_EVENT_ADD(
        mmi_phb_startup_copy_sim3_check,
        mmi_phb_startup_copy_sim3_pre_entry
    ),
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_IDLE_EVENT_ADD(
        mmi_phb_startup_copy_sim4_check,
        mmi_phb_startup_copy_sim4_pre_entry
    ),
#endif

#endif /* defined(__MMI_PHB_STARTUP_COPY_SIM__) */

#if (MMI_MAX_SIM_NUM >= 2) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    MMI_IDLE_EVENT_ADD(NULL, NULL)
};


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_event_get_first
 * DESCRIPTION
 *  This function gets the first event configuration.
 * PARAMETERS
 *  void
 * RETURNS
 *  Event configuration.
 *****************************************************************************/
static const mmi_idle_event_struct *mmi_idle_event_get_first(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_idle_event_cfg_tbl[0].want_to_notify)
    {
        return NULL;
    }

    return &(g_idle_event_cfg_tbl[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_event_get_next
 * DESCRIPTION
 *  This function gets the next event configuration.
 * PARAMETERS
 *  event           : [IN]          Event configuration
 * RETURNS
 *  Event configuration.
 *****************************************************************************/
static const mmi_idle_event_struct *
mmi_idle_event_get_next(const mmi_idle_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!event || !event[1].want_to_notify)
    {
        return NULL;
    }

    return &(event[1]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_find_event
 * DESCRIPTION
 *  This function finds an event whick wants to display.
 * PARAMETERS
 *  void
 * RETURNS
 *  Event configuration.
 *****************************************************************************/
const mmi_idle_event_struct *mmi_idle_find_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_idle_event_struct *event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (event = mmi_idle_event_get_first();
         event != NULL;
         event = mmi_idle_event_get_next(event))
    {
        if (event->want_to_notify && event->want_to_notify())
        {
            return event;
        }
    }

    return NULL;
}

