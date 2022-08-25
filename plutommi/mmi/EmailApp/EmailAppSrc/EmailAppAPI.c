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

/*******************************************************************************
 * Filename:
 * ---------
 * EmailAPI.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implenment all the API call for other APP usage
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#include "MMIDataType.h"

#ifdef __MMI_EMAIL__

#include "mmi_rp_app_email_def.h"
#include "EmailAppMem.h"
#include "EmailAppGProt.h"
#include "EmailAppProt.h"
#include "EmailAppAccount.h"

#ifdef __MMI_EMAIL_OTAP__
#include "EmailAppOtap.h"
#endif /* __MMI_EMAIL_OTAP__ */

#include "EmailAppEMN.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __MMI_USB_SUPPORT__ */

#include "ModeSwitchSrvGprot.h"
#include "cbm_api.h"
#include "kal_general_types.h"
#include "emailsrvgprot.h"
#include "customer_ps_inc.h"
#include "GlobalResDef.h"
#include "cbm_consts.h"
#include "DataAccountGProt.h"
#include "custom_data_account.h"
#include "UriAgentSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "FileMgrSrvGProt.h"
#include "EmailAppCore.h"
#include "Unicodexdcl.h"
#include "mmi_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"

#include "EmailAppGprot.h"
#include "NwUsabSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NativeAppFactorySrvGprot.h"

#include "EmailAppLib.h"
#include "EmailAppStateMgr.h"

/************************************************************************/
/*                           Implements                                 */
/************************************************************************/
void mmi_email_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_smgr_first_init();
}


mmi_ret mmi_email_enter_usb_ms_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_smgr_usb_on();
    return MMI_RET_OK;
}


mmi_ret mmi_email_exit_usb_ms_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_smgr_usb_off();
    return MMI_RET_OK;
}

/* Used by KeyBrd.c */
U8 mmi_email_util_get_stop_cause(void)
{
    return 1;
}

/* Used by KeyBrd.c */
void mmi_email_main_goto_idle(void)
{
}

// event handle for file system formatting
mmi_ret mmi_email_fmgr_reset_status_icon(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct *format_info =
        (srv_fmgr_notification_format_event_struct*)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_FMGR_RESET_STATUS_ICON, __LINE__);
    if (format_info->state != SRV_FMGR_NOTIFICATION_STATE_AFTER)
    {
        return MMI_RET_OK;
    }

    mmi_email_smgr_fmgr_formate(format_info->drv_letter);
    return MMI_RET_OK;
}


mmi_ret mmi_email_mode_switch_event_hdlr(mmi_event_struct *evt)
{
    srv_mode_switch_notify_struct *flight_mode_evt;

    flight_mode_evt = (srv_mode_switch_notify_struct*)evt;

    if (flight_mode_evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY)
    {
        mmi_email_smgr_network_notify();
    }
    return MMI_RET_OK;
}


void mmi_email_nmgr_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_NMGR_QUERY, __LINE__);

    mmi_email_emn_nmgr_query();

#ifdef __OP12__
    mmi_email_vf_nmgr_query();
#endif /* __OP12__ */
}

void mmi_email_nmgr_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_NMGR_CANCEL, __LINE__);

    mmi_email_emn_set_new_emn_notify_flag(MMI_FALSE);

#ifdef __OP12__
    mmi_email_vf_set_flag(FALSE);
#endif
}


void mmi_email_emn_set_flightmode(void)
{
    /* Do nothing */
}

void mmi_email_emn_reset_flightmode(void)
{
    /* Do nothing */
}


// The handler of memory card pluged out
mmi_ret mmi_email_notify_unmount_memory_card_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_plug_event_struct *plug_info =
        (srv_fmgr_notification_dev_plug_event_struct*)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_NOTIFY_UNMOUNT_MEMORY_CARD_HDLR, __LINE__);
    mmi_email_smgr_tcard_out((CHAR)plug_info->drv_letters[0]);
    return MMI_RET_OK;
}

// The handler of memory card pluged in
mmi_ret mmi_email_notify_mount_memory_card_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_plug_event_struct *plug_info =
        (srv_fmgr_notification_dev_plug_event_struct*)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_NOTIFY_MOUNT_MEMORY_CARD_HDLR, __LINE__);

    mmi_email_smgr_tcard_in((CHAR)plug_info->drv_letters[0]);
    return MMI_RET_OK;
}

U8 mmi_email_check_vf_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 return_value = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CHECK_VF_LIST, __LINE__);

    return_value = mmi_email_emn_get_new_emn_notify_flag();

#ifdef __USB_IN_NORMAL_MODE__
    if (MMI_TRUE == srv_usb_is_in_mass_storage_mode())
    {
        return_value = MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

#ifdef __OP12__
    if (srv_email_get_srv_init_state() == SRV_EMAIL_INIT_STATE_READY &&
        mmi_email_vf_get_flag() &&
        mmi_email_get_unread_count())
    {
        return_value = TRUE;
    }
    else
    {
        return_value = FALSE;
    }
#endif /* __OP12__ */

    return return_value;
}


mmi_ret mmi_email_sim_ctrl_sim_ctrl_change_detected_hdlr(mmi_event_struct* para)
{
    mmi_email_smgr_network_notify();
    return MMI_RET_OK;
}


#ifdef __MMI_WLAN_FEATURES__
mmi_ret mmi_email_wlan_open_hdlr(mmi_event_struct* para)
{
    mmi_email_smgr_network_notify();
    return MMI_RET_OK;
}


mmi_ret mmi_email_wlan_close_hdlr(mmi_event_struct* para)
{
    mmi_email_smgr_network_notify();
    return MMI_RET_OK;
}
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_APP_MANAGER_SUPPORT__
mmi_ret vapp_email_package_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id) 
    {
        case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE:
            mmi_wsprintf_ex(
                ((srv_nativeappfactory_query_app_badge_evt_struct*)evt)->badge,
                (SRV_APPMGR_BADGE_MAX_LEN + 1) * sizeof(WCHAR),
                ((mmi_email_lib_get_total_unread_number() == 0) ? (WCHAR*)L"" : (WCHAR*)L"%d"),
                mmi_email_lib_get_total_unread_number());
            return MMI_RET_OK;
    }

    return MMI_RET_DONT_CARE;
}
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
#endif /* __MMI_EMAIL__ */


/*****************************************************************************
* FUNCTION
*  mmi_email_is_email_can_forward
* DESCRIPTION
*  Whether can forward data via Email
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
BOOL mmi_email_is_email_can_forward(void)
{
#ifdef __MMI_EMAIL__
    return mmi_email_smgr_could_show_ui();
#else /* __MMI_EMAIL__ */    
    return FALSE;
#endif /* __MMI_EMAIL__ */
}


#ifdef __MMI_EMAIL__
#ifdef __MMI_EMAIL_MRE_UT__
S32 mre_sample_g_req_id = 0;

void mre_sample_abort(void);
void mre_sample_callback(mmi_email_app_mre_send_error_code_enum errcode, void* user_data);

void mre_sample_send_email(void)
{
    mmi_email_app_send_addr_struct to;
    WCHAR atta1[SRV_FMGR_PATH_MAX_LEN + 1];
    WCHAR atta2[SRV_FMGR_PATH_MAX_LEN + 1];
    WCHAR *att_list[2];
    mmi_email_app_mre_send_param_struct para;
    mmi_email_app_mre_send_error_code_enum ret;

    static int i = 0;

    if (i == 0)
    {
        mre_sample_abort();
        i = !i;
        return;
    }

    /* Prepare parameter */
    to.addr_mail = (CHAR*)L"someone@mtk.com";
    to.addr_name = (CHAR*)L"Some One";

    para.from = NULL;

    para.to_num = 1;
    para.to = &to;

    para.cc_num = 0;
    para.cc = NULL;

    para.bcc_num = 0;
    para.bcc = NULL;

    para.subject = L"Subject: Hi,message from MTK email client.";
    para.content = L"Hi,message from MTK email client.";

    mmi_wcscpy(atta1, L"D:\\photos\\att1.jpg");
    mmi_wcscpy(atta2, L"D:\\photos\\att2.jpg");
    att_list[0] = atta1;
    att_list[1] = atta2;

    para.attach_file_num = 2;
    para.attch_file_list = att_list;

    para.priority = MMI_EMAIL_PRIOR_NORMAL;
    para.is_save_to_sent = MMI_TRUE;

    /* Send it */
    ret = mmi_email_app_mre_send(&para, mre_sample_callback, NULL, &mre_sample_g_req_id);
    if (ret == MMI_EMAIL_APP_MRE_ERROR_CODE_WOULDBLOCK)
    {
        /* Action taken, wait for result by mre_send_email_callback 
           or abort it by mmi_email_app_mre_send_abort */
        ret = ret;
        mre_sample_g_req_id = mre_sample_g_req_id;

    }
    else
    {
        /* Error hanlder */
        ret = ret;
    }
}

void mre_sample_abort(void)
{
    MMI_BOOL ret;

    ret = mmi_email_app_mre_send_abort(mre_sample_g_req_id);
    if (ret)
    {
        /* Abort successfully */
        mre_sample_g_req_id = 0;
    }
    else
    {
        /* Abort failed, action maybe done already or wrong id provided */
        mre_sample_g_req_id = 0;
    }

}

void mre_sample_callback(mmi_email_app_mre_send_error_code_enum errcode, void* user_data)
{
    if (errcode == MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS)
    {
        /* Send successfully */
        mre_sample_g_req_id = 0;
    }
    else
    {
        /* Send fail */
        mre_sample_g_req_id = 0;
    }
}

#endif //#ifdef __MMI_EMAIL_MRE_UT__
#endif //#ifdef __MMI_EMAIL__
