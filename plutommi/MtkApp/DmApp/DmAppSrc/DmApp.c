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
 *  DmApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM application main.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifdef SYNCML_DM_SUPPORT
/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMIDataType.h"
#include "BootupSrvGprot.h"
#include "NotificationGprot.h"
#include "DmSrvIprot.h"
#include "DmApp.h"
#include "DmAppSession.h"
#include "DmAppDl.h"
#include "DmAppFota.h"
#include "DmAppOtap.h"

/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/

/****************************************************************************
 * Local Function
 ****************************************************************************/

mmi_ret mmi_dm_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_BOOTUP_NORMAL_INIT)
    {
        srv_dm_app_adp_reg_cb(mmi_dm_srv_app_adp_evt_cb_hdlr);
    }
    return MMI_RET_OK;
}


void mmi_dm_srv_app_adp_evt_cb_hdlr(srv_dm_app_adp_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case SRV_DM_APP_ADP_EVT_DISPLAY_NOTIFICATION:
        {
            srv_dm_app_adp_evt_display_notification_struct *notification_evt =
                (srv_dm_app_adp_evt_display_notification_struct*)evt->arg;
            mmi_dm_session_notification_srv_cb_hdlr(notification_evt->ui_mode);
            break;
        }

        case SRV_DM_APP_ADP_EVT_DISPLAY_ALERT:
        {
            srv_dm_app_adp_evt_display_alert_struct *alert_evt =
                (srv_dm_app_adp_evt_display_alert_struct*)evt->arg;
            mmi_dm_session_alert_srv_cb_hdlr(alert_evt->alert->alert_type);
            break;
        }

        case SRV_DM_APP_ADP_EVT_SESSION_ABORT:
        {
            mmi_dm_session_abort_srv_cb_hdlr();
            break;
        }

        case SRV_DM_APP_ADP_EVT_DISPLAY_ENDING_MSG:
        {
            srv_dm_app_adp_evt_display_ending_msg_struct *ending_msg_evt =
                (srv_dm_app_adp_evt_display_ending_msg_struct*)evt->arg;
            mmi_dm_session_display_ending_msg(ending_msg_evt->ending_msg);
            break;
        }

        case SRV_DM_APP_ADP_EVT_DL_START:
        {
            srv_dm_app_adp_evt_dl_start_struct *dl_start_evt =
                (srv_dm_app_adp_evt_dl_start_struct*)evt->arg;
            mmi_dm_dl_start_evt_hdlr(
                dl_start_evt->is_resume,
                dl_start_evt->auto_resume);
            break;
        }

        case SRV_DM_APP_ADP_EVT_DL_PROGRESS:
        {
            srv_dm_app_adp_evt_dl_progress_struct *dl_progress_evt =
                (srv_dm_app_adp_evt_dl_progress_struct*)evt->arg;
            mmi_dm_dl_progress_hdlr(
                dl_progress_evt->acc_size,
                dl_progress_evt->total_size);
            break;
        }

        case SRV_DM_APP_ADP_EVT_DL_FINISH:
        {
            srv_dm_app_adp_evt_dl_finish_struct *dl_finish_evt =
                (srv_dm_app_adp_evt_dl_finish_struct*)evt->arg;
            mmi_dm_dl_finish_hdlr(dl_finish_evt->cause);
            break;
        }

    #ifdef __DM_FOTA_SUPPORT__
        case SRV_DM_APP_ADP_EVT_FOTA_UPDATE_RESULT:
        {
            srv_dm_app_adp_evt_fota_update_result_struct *fota_update_result_evt =
                (srv_dm_app_adp_evt_fota_update_result_struct*)evt->arg;
            mmi_dm_fota_display_fota_update_result_via_nmgr(fota_update_result_evt->result);
            break;
        }

        case SRV_DM_APP_ADP_EVT_FOTA_DISPLAY_UPDATE:
        {
            srv_dm_app_adp_evt_fota_display_update_struct *fota_display_update_evt =
                (srv_dm_app_adp_evt_fota_display_update_struct*)evt->arg;
            mmi_dm_fota_display_update_cnf_via_nmgr(fota_display_update_evt->ui_mode);
            break;
        }
    #endif /* __DM_FOTA_SUPPORT__ */

    #ifdef __MMI_CCA_SUPPORT__
        case SRV_DM_APP_ADP_EVT_OTAP_INSTALL_PROF:
        {
            mmi_dm_otap_entry_installation_pre();
            break;
        }
    #endif /* __MMI_CCA_SUPPORT__ */

        case SRV_DM_APP_ADP_EVT_DISPLAY_NMGR_POPUP:
        {
            srv_dm_app_adp_evt_display_nmgr_popup_struct *display_nmgr_popup_evt =
                (srv_dm_app_adp_evt_display_nmgr_popup_struct*)evt->arg;
            mmi_dm_display_nmgr_popup(
                display_nmgr_popup_evt->scenario_id,
                display_nmgr_popup_evt->type,
                display_nmgr_popup_evt->string);
            break;
        }

        default:
            break;
    }
}


void mmi_dm_display_nmgr_popup(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_popup(
        scenario_id,
        type,
        string);
}

#endif /* SYNCML_DM_SUPPORT */
