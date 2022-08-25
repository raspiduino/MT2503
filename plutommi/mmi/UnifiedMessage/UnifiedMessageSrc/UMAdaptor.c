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
 * UMSInterface.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __UM_SUPPORT__
#include "UMDefs.h"
#include "UMProt.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "UMSrvGprot.h"
#include "SmsAppGprot.h"
#include "SmsSrvGprot.h"
#include "Mms_api.h"
#include "Push_inbox_api.h"
#ifdef __MMI_BROWSER_2__
#include "BrowserGprots.h"
#endif /* __MMI_BROWSER_2__ */


#ifdef __MMI_MMS_IN_UM__
#include "MmsSrvGprot.h"            /* FTE checking API */
#include "MMSAppCommonGprot.h"  /* FTE activating API */
#endif /* __MMI_MMS_IN_UM__ */

#ifdef __MMI_PUSH_IN_UM__
#include "WAPPushGprots.h"
#include "WAPPushSrvGprots.h"
#endif /* __MMI_PUSH_IN_UM__ */
#ifdef WAP_SUPPORT
#include "servicemsgcuigprot.h"
#endif /* WAP_SUPPORT */

#ifdef __MMI_PROV_IN_UM__
#include "ProvBoxAPPGProt.h"
#endif /* __MMI_PROV_IN_UM__ */

#ifdef __MMI_IMPS__
/* under construction !*/
#endif /* __MMI_IMPS__ */

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif /* __MMI_EMAIL__ */
#include "MsgViewerCuiGProt.h"
#include "MMIDataType.h"
#include "UMGProt.h"
#include "UmSrvDefs.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CbsAppGProt.h"
#if defined (__MMI_MMS_IN_UM__)
#if defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
#include "MMSAppInterfaceGprot.h"
#else
#include "UcCuiGprot.h"
#endif
#endif /* __MMI_MMS_IN_UM__ */
#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)
#include "ProvBoxAppGProt.h"
#endif /* defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) */
#if !defined(__MMI_PUSH_IN_UM__) && defined(BROWSER_SUPPORT)
#include "WAPPushGprots.h"
#endif /* !__MMI_PUSH_IN_UM__ && BROWSER_SUPPORT */

#ifdef __MMI_APP_MANAGER_SUPPORT__
#include "NativeAppFactorySrvGprot.h"
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
#ifdef __MMI_NCENTER_SUPPORT__
#include "umncentergprot.h"
#include "NotificationSettingSrvGprot.h"

static void mmi_um_ui_update_ncenter(mmi_event_struct *evt);
void mmi_um_ui_invoke_an_ncenter_entry(S32 entry_id, 
										WCHAR *main_text, 
										WCHAR *sub_text, 
										vsrv_nitent_funcptr intent_handler,
										MMI_ID image_id);
void mmi_um_ui_dismiss_an_ncenter_entry(S32 entry_id);
static void  mmi_um_ui_update_ncenter_send_failed(mmi_event_struct *evt);
static void mmi_um_ui_update_ncenter_unread(mmi_event_struct *evt);
#endif /* __MMI_NCENTER_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_entry_msg
 * DESCRIPTION
 *  It used to entry the specified message content or option menu.
 *
 * PARAMETERS
 *  msg_type                [IN]: the message type of selected message
 *  para                    [IN]: The paramenter of entry message
 *
 * RETURNS
 *  MMI_TRUE:   It has screen displayed
 *  MMI_FALSE:  It does not display any screen.
 *****************************************************************************/
MMI_ID mmi_um_ui_adp_entry_msg(srv_um_msg_enum msg_type, mmi_um_entry_msg_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = GRP_ID_INVALID;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_ENTRY_MSG, msg_type, para->msg_id);
    
    switch (msg_type)
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        case SRV_UM_MSG_SMS:
        {
            grp_id = mmi_sms_um_entry_msg(para);
            break;
        }
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            grp_id = (MMI_BOOL)mms_um_entry_msg(para);
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            grp_id = mmi_push_handle_entry_msg_wap_push(para);
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            grp_id = mmi_provbox_um_enter_msg(para);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
    #ifdef __SRV_UM_UT__
        case SRV_UM_MSG_UT:
        {
            break;
        }
    #endif
        default:
        {
            MMI_ASSERT(0);
        }
    }

    return grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_reentry
 * DESCRIPTION
 *  When end user wants to re-entry UM screen, UM needs to check could each 
 *  message application re-entry. If one of message application could not be 
 *  re-entry, UM should display a popup
 *
 * PARAMETERS
 *  msg_type                [IN]: the message type of selected message
 *
 * RETURNS
 *  MMI_TRUE: it can be re-entry
 *  MMI_FALSE: it can not be re-entry
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_reentry(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            if (!mmi_sms_is_allow_reentry())
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_REENTRY, msg_type, MMI_FALSE);
                return MMI_FALSE;
            }
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_REENTRY, msg_type, MMI_TRUE);
        #endif /* __MMI_TELEPHONY_SUPPORT__ */
            break;
        }
        case SRV_UM_MSG_MMS:
        case SRV_UM_MSG_WAP_PUSH:
        {
        #ifdef __MMI_MMS_IN_UM__
            if (!mms_is_reentrant())
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_REENTRY, msg_type, MMI_FALSE);
                return MMI_FALSE;
            }
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_REENTRY, msg_type, MMI_TRUE);
        #endif /* __MMI_MMS_IN_UM__ */
            break;
        }
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            /* No need to check */
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
    #ifdef __SRV_UM_UT__
        case SRV_UM_MSG_UT:
        {
            break;
        }
    #endif
        default:
        {
            MMI_ASSERT(0);
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_pending_action
 * DESCRIPTION
 *  Check the pending action corresponding to the messsage type
 *
 * PARAMETERS
 *  msg_type                [IN]: the message type of selected message
 *
 * RETURNS
 *  MMI_TRUE: It has pending action
 *  MMI_FALSE: It does not have any pending action
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_pending_action(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_FALSE;
    
    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            /*********************************************
             * If SMS is not ready yet, the 
             * mmi_frm_sms_check_action_pending may 
             * return TRUE. it will cause some issues.
             * Power on => message => not available => 
             * empty 
             ********************************************/
            if (!srv_um_check_ready_type(SRV_UM_MSG_SMS))
            {
                result = MMI_FALSE;
            }
            break;
        }
        case SRV_UM_MSG_MMS:
        {
            result = MMI_FALSE;
            break;
        }
        case SRV_UM_MSG_WAP_PUSH:
        {
            result = MMI_FALSE;
            break;
        }
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            result = MMI_FALSE;
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
    #ifdef __SRV_UM_UT__
        case SRV_UM_MSG_UT:
        {
            result = MMI_FALSE;
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_PENDING_ACTION, msg_type, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_receive_event
 * DESCRIPTION
 *  Receive the event from the Service level.
 *
 * PARAMETERS
 *  event                   [IN]: the message type of selected message
 *  arg                     [IN]: Argument of event
 *
 * RETURNS
 *  Handleing result
 *****************************************************************************/
mmi_ret mmi_um_ui_adp_receive_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
#ifdef __MMI_NCENTER_SUPPORT__
    U8 yesORno_unread=0;
    U8 yesORno_failed=0;
    S16 error;
#endif
#ifdef __MMI_APP_MANAGER_SUPPORT__
    mmi_app_package_char *package_name = "native.mtk.messaging";
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_UM_NOTIFY_READY:
        {
            srv_um_notify_ready_evt_struct *ready_evt = (srv_um_notify_ready_evt_struct *)evt;

            if (ready_evt->result == MMI_TRUE)
            {
                mmi_um_ui_cc_send_event(0, MMI_UM_UI_EVENT_READY, NULL);
            }
            else
            {
                mmi_um_ui_cc_send_event(0, MMI_UM_UI_EVENT_UNREADY, NULL);
            }
        #ifdef __MMI_APP_MANAGER_SUPPORT__
            srv_appmgr_update_app_info((mmi_app_package_char*)package_name, 
                    EVT_ID_SRV_APPMGR_UPDATE_BADGE);
        #endif
			mmi_um_alert_um_inbox_alert_refresh();
#ifndef __MMI_UM_ULTRA_SLIM__
			mmi_um_alert_um_outbox_alert_refresh();
#endif
		#ifdef __MMI_NCENTER_SUPPORT__
			ReadValue(NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_UNREAD, &yesORno_unread, DS_BYTE, &error);
            ReadValue(NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_FAILED, &yesORno_failed, DS_BYTE, &error);
            if((yesORno_unread == 1) && (yesORno_failed == 1))
            {
			mmi_um_ui_update_ncenter(evt);
            }
            else if((yesORno_unread == 0) && (yesORno_failed == 1)) 
            {
                mmi_um_ui_update_ncenter_send_failed(evt);
            }
            else if((yesORno_unread == 1) && (yesORno_failed == 0))
            {
                mmi_um_ui_update_ncenter_unread(evt);
            } 
		#endif
            break;
        }
        case EVT_ID_SRV_UM_NOTIFY_HIGHLIGHT_MSG:
        {
            srv_um_notify_highlight_msg_evt_struct *hilite_evt = (srv_um_notify_highlight_msg_evt_struct *)evt;
            mmi_um_ui_sh_hilite_folder_info_struct hilite_folder;

            hilite_folder.folder_info.msg_box_type = hilite_evt->msg_box_type;
            hilite_folder.hilite_info.msg_id = hilite_evt->msg_id;
            hilite_folder.hilite_info.msg_type = hilite_evt->msg_type;
            hilite_folder.hilite_info.index = 0;

            mmi_um_ui_cc_send_event(0, MMI_UM_UI_EVENT_HIGHLIGHT_CHANGE, (void *)&hilite_folder);
            break;
        }
        case EVT_ID_SRV_UM_NOTIFY_REFRESH:
        {
            srv_um_notify_refresh_evt_struct *refresh_srv_evt = (srv_um_notify_refresh_evt_struct *)evt;
            srv_um_msg_box_enum msg_box;
#ifdef __MMI_NCENTER_SUPPORT__
            U8 yesORno_unread=1;
            U8 yesORno_failed=1;
            S16 error;
#endif
        #ifdef __MMI_UM_ITERATOR_VIEWER__
            mmi_um_refresh_evt_struct refresh_evt;
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */

            msg_box = refresh_srv_evt->msg_box_type;
            mmi_um_ui_cc_send_event(0, MMI_UM_UI_EVENT_REFRESH, &msg_box);
        #ifdef __MMI_UM_ITERATOR_VIEWER__
            /* receive the event, it should notify other message ap */
            MMI_FRM_INIT_EVENT(&refresh_evt, EVT_ID_MMI_UM_REFRESH);
            refresh_evt.msg_type = refresh_srv_evt->msg_type;
            refresh_evt.msg_box = refresh_srv_evt->msg_box_type;
            MMI_FRM_CB_EMIT_POST_EVENT(&refresh_evt);
        #endif /* __MMI_UM_ITERATOR_VIEWER__ */
        #ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
            mmi_um_ui_sms_content_manager_refresh_handler(refresh_srv_evt);
        #endif
        #ifdef __MMI_APP_MANAGER_SUPPORT__
            srv_appmgr_update_app_info((mmi_app_package_char*)package_name, 
                    EVT_ID_SRV_APPMGR_UPDATE_BADGE);
        #endif
			mmi_um_alert_um_inbox_alert_refresh();
#ifndef __MMI_UM_ULTRA_SLIM__
			mmi_um_alert_um_outbox_alert_refresh();
#endif
        #ifdef __MMI_NCENTER_SUPPORT__
            if((refresh_srv_evt->refresh_type==SRV_UM_REFRESH_NEW_INCOMING_MSG) && (refresh_srv_evt->msg_box_type == SRV_UM_MSG_BOX_INBOX ))
                WriteValue(NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_UNREAD, &yesORno_unread, DS_BYTE, &error);
            if((refresh_srv_evt->refresh_type==SRV_UM_REFRESH_NONE) && (refresh_srv_evt->msg_box_type == SRV_UM_MSG_BOX_UNSENT ))
                WriteValue(NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_FAILED, &yesORno_failed, DS_BYTE, &error);      
            mmi_um_ui_update_ncenter(evt);
        #endif
            break;
        }
        case EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS:
#ifdef __MMI_MMS_IN_UM__
		case EVT_ID_SRV_MMS_UPDATE_STATUS:
#endif
        {
#ifdef __MMI_NCENTER_SUPPORT__
            mmi_um_ui_update_ncenter_send_failed(evt);
#endif
#ifndef __MMI_UM_ULTRA_SLIM__			
			mmi_um_alert_um_outbox_alert_refresh();
#endif
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}


#ifdef __MMI_NCENTER_SUPPORT__
static void mmi_um_ui_unread_intent_handler(vsrv_notification_handle noti, 
                                            vsrv_nintent intent, 
                                            void* userData, 
                                            U32 userDataSize)
{
    switch(intent.type)
    {
    case VSRV_NINTENT_TYPE_TAP:
    case VSRV_NINTENT_TYPE_LAUNCH:
    {
        mmi_um_nmgr_lsk_handler(NULL);
        mmi_um_nmgr_unread_cancel();
        break;
    }

	case VSRV_NINTENT_TYPE_CLEAR:
    {
#ifdef __MMI_NCENTER_SUPPORT__
        U8 yesORno=0;
        S16 error;
        WriteValue(NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_UNREAD, &yesORno, DS_BYTE, &error);
#endif
        mmi_um_nmgr_unread_cancel();
        /* Make code for entry in NVRAM that Notification is cleared ***/
        break;
    }
	case VSRV_NINTENT_TYPE_CLOSE:
	{
		mmi_um_nmgr_unread_cancel();

        break;
	}

    case VSRV_NINTENT_TYPE_LANGUAGE_CHANGED:
        {
            vsrv_ngroup_handle message_group = NULL;
            WCHAR ctext[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            WCHAR main_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            WCHAR sub_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            srv_um_get_msg_num_result data;
            MMI_ID unread_string = STR_UM_UNREAD_MSGS_WITH_NUMBER;
            message_group = vsrv_ncenter_query_ngroup(APP_UNIFIEDMESSAGE);
            if (NULL == message_group)
                message_group = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UNIFIEDMESSAGE);
            mmi_wcscpy(ctext, (WCHAR *)GetString(MAIN_MENU_MESSAGES_TEXT));    
            vsrv_ncenter_set_ngroup_title_str(message_group, ctext);
            srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data);
            mmi_wcscpy(main_text, (WCHAR *)GetString(STR_UM_UNREAD_MSG));
            if (data.inbox_unread_msg_number == 1)
            {
                unread_string = STR_UM_UNREAD_MSG_WITH_NUMBER;
            }
            mmi_wsprintf(
                sub_text, 
                MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
                unread_string, 
                data.inbox_unread_msg_number);
            vsrv_ncenter_set_notification_maintext_str(noti,main_text);
            vsrv_ncenter_set_notification_subtext_str(noti,sub_text);
            vsrv_ncenter_notify_notification(noti);
            break;
        }
    default:
        break;
    }
}


static void mmi_um_ui_send_failed_intent_handler(vsrv_notification_handle noti, 
                                                vsrv_nintent intent, 
                                                void* userData, 
                                                U32 userDataSize)
{
    switch(intent.type)
    {
    case VSRV_NINTENT_TYPE_TAP:
    case VSRV_NINTENT_TYPE_LAUNCH:
    {
        mmi_um_send_failed_entry(NULL);
		mmi_um_nmgr_send_failed_cancel();
            break;
    } 
	case VSRV_NINTENT_TYPE_CLEAR:
    {
#ifdef __MMI_NCENTER_SUPPORT__
        U8 yesORno=0;
        S16 error;
        WriteValue(NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_FAILED, &yesORno, DS_BYTE, &error);
#endif
        mmi_um_nmgr_send_failed_cancel();
        break;
    }
	case VSRV_NINTENT_TYPE_CLOSE:
	{
		mmi_um_nmgr_send_failed_cancel();
        break;
	}


    case VSRV_NINTENT_TYPE_LANGUAGE_CHANGED:
        {
            vsrv_ngroup_handle message_group = NULL;
            WCHAR ctext[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            WCHAR main_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            WCHAR sub_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            S32 count = 0;
            S32 result;
            MMI_ID string = STR_UM_SEND_FAILED_MSGS_NUMBER;
            if (srv_um_check_ready())
            {
                /* sms part */
                {   
                    U16 index;
                    U16 msg_list_size;
                    U16 msg_id;

                    msg_list_size = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);

                    for (index = 0; index < msg_list_size; index++)
                    {
                        msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_UNSENT, index);

                        if (srv_sms_get_unsent_msg_status(msg_id) == SRV_SMS_SEND_FAIL)
                        {
                            count++;
                        }
                    }
                }
#ifdef __MMI_MMS_IN_UM__
                /* mms part */
                {
                    srv_mms_get_msg_count_struct msg_count_req;
                    S32 mms_count = 0;

                    U16 requestSim = SRV_MMS_QUERY_TOTAL_OUTBOX_SIM1;
                    U16 index = 0;

                    memset(&msg_count_req, 0, sizeof(srv_mms_get_msg_count_struct));
                    msg_count_req.count = MMI_MAX_SIM_NUM;

                    for (index = 0; index < MMI_MAX_SIM_NUM ; index++, requestSim++)
                    {
                        msg_count_req.count++;
                        msg_count_req.req_tb[index] = requestSim;
                    }
                    result = srv_mms_get_msg_count(&msg_count_req);

                    if (SRV_MMS_RESULT_OK == result)
                    {
                        for (index = 0 ; index < MMI_MAX_SIM_NUM ; index++)
                        {
                            mms_count += msg_count_req.rsp_tb[index];
                        }
                        if (0 < count)
                        {
                            if (MMI_TRUE == srv_mms_has_sending_mms())
                            {
                                /* one is sending, decrese it */
                                mms_count--;
                            }
                            if (MMI_TRUE == srv_mms_has_waiting_mms())
                            {
                                S32 waitingCount = 0;
                                waitingCount = srv_mms_get_waiting_mms_count();
                                if (count >= waitingCount)
                                {
                                    mms_count -= waitingCount;
                                }
                                else
                                {
                                    mms_count = 0;
                                }
                            }
                        }
                    }
                    count += mms_count;
                }
#endif          
            }
            message_group = vsrv_ncenter_query_ngroup(APP_UNIFIEDMESSAGE);
            if (NULL == message_group)
                message_group = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UNIFIEDMESSAGE);
            mmi_wcscpy(ctext, (WCHAR *)GetString(MAIN_MENU_MESSAGES_TEXT));    
            vsrv_ncenter_set_ngroup_title_str(message_group, ctext);
            mmi_wcscpy(main_text, (WCHAR *)GetString(STR_UM_SEND_FAILED_MSG));
            if (count == 1)
            {
                string = STR_UM_SEND_FAILED_MSG_NUMBER;
            }
            mmi_wsprintf(
                sub_text, 
                MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
                string, 
                count);
            vsrv_ncenter_set_notification_maintext_str(noti,main_text);
            vsrv_ncenter_set_notification_subtext_str(noti,sub_text);
            vsrv_ncenter_notify_notification(noti);

            break;
        }
    default:
        break;
    }
}


#if 0
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
 *  mmi_um_ui_invoke_an_ncenter_entry
 * DESCRIPTION
 *  Add an NCenter Item with a special entry id and description
 *
 * PARAMETERS
 *  entry_id                   [IN]: entry id to be added
 *  main_text                  [IN]: main text
 *  sub_text                   [IN]: sub text
 * RETURNS
 *    void
 *****************************************************************************/
void mmi_um_ui_invoke_an_ncenter_entry(S32 entry_id, 
										WCHAR *main_text, 
										WCHAR *sub_text, 
										vsrv_nitent_funcptr intent_handler,
										MMI_ID image_id)
{
    vsrv_ngroup_handle ghandle = NULL;
    vsrv_notification_handle nhandle = NULL;
	mmi_image_src_struct image;
    applib_time_struct timestamp;

    /* get a group */
    ghandle = mmi_um_query_ncenter_group();
    if (NULL == ghandle)
    {
        ghandle = mmi_um_create_ncenter_group();
    }

    /* get a notification */
    nhandle = vsrv_ncenter_query_notification(ghandle, entry_id);
    if (NULL == nhandle)
    {
        nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, ghandle, entry_id);
        vsrv_ncenter_set_notification_intent_callback(nhandle, intent_handler, NULL, 0);
    }

    vsrv_ncenter_set_notification_maintext_str(nhandle, main_text);
	image.type = MMI_IMAGE_SRC_TYPE_RES_ID;
	image.data.res_id = image_id;
    vsrv_ncenter_set_notification_icon(nhandle, image);
    /* set a notification sub text, xxx unread*/
    vsrv_ncenter_set_notification_subtext_str(nhandle, sub_text);
    /* notify and update */

    GetDateTime(&timestamp);
    vsrv_ncenter_set_notification_timestamp(nhandle, &timestamp);

    vsrv_ncenter_notify_notification(nhandle); 
}



/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_invoke_an_ncenter_entry
 * DESCRIPTION
 *  Add an NCenter Item with a special entry id and description
 *
 * PARAMETERS
 *  entry_id                   [IN]: entry id to be added
 *  main_text                  [IN]: main text
 *  sub_text                   [IN]: sub text
 * RETURNS
 *    void
 *****************************************************************************/
void mmi_um_ui_refresh_an_existing_ncenter_entry(S32 entry_id, 
											WCHAR *main_text, 
											WCHAR *sub_text, 
											vsrv_nitent_funcptr intent_handler,
											MMI_ID image_id)
{
    vsrv_ngroup_handle ghandle = NULL;
    vsrv_notification_handle nhandle = NULL;
	mmi_image_src_struct image;
    applib_time_struct timestamp;
    /* get a group */
    ghandle = mmi_um_query_ncenter_group();
    if (NULL != ghandle)
    {
        nhandle = vsrv_ncenter_query_notification(ghandle, entry_id);
    }

    if (NULL == nhandle)
    {
        return;
    }

    vsrv_ncenter_set_notification_maintext_str(nhandle, main_text);
	image.type = MMI_IMAGE_SRC_TYPE_RES_ID;
	image.data.res_id = image_id;
    vsrv_ncenter_set_notification_icon(nhandle, image);
    /* set a notification sub text, xxx unread*/
    vsrv_ncenter_set_notification_subtext_str(nhandle, sub_text);
    /* notify and update */

    GetDateTime(&timestamp);
    vsrv_ncenter_set_notification_timestamp(nhandle, &timestamp);

    vsrv_ncenter_notify_notification(nhandle); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_update_ncenter
 * DESCRIPTION
 *  Dismiss an NCenter Item with a special entry id
 *
 * PARAMETERS
 *  entry_id                   [IN]: entry id to be added
 * RETURNS
 *    void
 *****************************************************************************/
void mmi_um_ui_dismiss_an_ncenter_entry(S32 entry_id)
{
    
    vsrv_ngroup_handle ghandle = NULL;
    vsrv_notification_handle nhandle = NULL;
    /* get a group */
    ghandle = mmi_um_query_ncenter_group();
    if (NULL != ghandle)
    {
        nhandle = vsrv_ncenter_query_notification(ghandle, entry_id);
    }
    if (NULL != nhandle)
    {
        vsrv_ncenter_close_notification(nhandle);
    }
}

static void  mmi_um_ui_update_ncenter_unread(mmi_event_struct *evt)
{
    srv_um_get_msg_num_result data;
    MMI_BOOL need_notify_unread = MMI_FALSE;
    MMI_BOOL force_create_unread = MMI_FALSE;
    
    /* check new message? */
    if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
    {
        if(data.inbox_unread_msg_number)
        {
            MMI_ID unread_string = STR_UM_UNREAD_MSGS_WITH_NUMBER;
            WCHAR main_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            WCHAR sub_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            
            mmi_wcscpy(main_text, (WCHAR *)GetString(STR_UM_UNREAD_MSG));

            if (data.inbox_unread_msg_number == 1)
            {
                unread_string = STR_UM_UNREAD_MSG_WITH_NUMBER;
            }
            mmi_wsprintf(
                sub_text, 
                MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
                unread_string, 
                data.inbox_unread_msg_number);
            {
                /* check if need to show new indication */
                switch (evt->evt_id)
                {
                    case EVT_ID_SRV_UM_NOTIFY_REFRESH:
                    {
                        srv_um_notify_refresh_evt_struct *refresh;
                        refresh = (srv_um_notify_refresh_evt_struct *)evt;
                        if ((SRV_UM_MSG_BOX_INBOX & refresh->msg_box_type) &&
                            (SRV_UM_REFRESH_NEW_INCOMING_MSG == refresh->refresh_type))
                        {
                            force_create_unread = MMI_TRUE;
                        }
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_UM_MSG_BOX_ALL & refresh->msg_box_type) &&
                            (SRV_UM_REFRESH_NONE == refresh->refresh_type) && (refresh->msg_type == SRV_UM_MSG_SMS))
                        {
                            U8 yesORno_unread=1;
                            S16 error;
                            ReadValue(NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_UNREAD, &yesORno_unread, DS_BYTE, &error);
                            if(yesORno_unread ==1)
                            force_create_unread = MMI_TRUE;
                        }
#endif
                        if (SRV_UM_MSG_BOX_INBOX  == (SRV_UM_MSG_BOX_INBOX & refresh->msg_box_type))
                        {
                            /* check if copy the unread message into inbox, if yes, treate as new msg */
                            MMI_BOOL isRead = MMI_TRUE;
                            if (0 != refresh->msg_id &&
                                SRV_UM_REFRESH_NONE != refresh->refresh_type)
                            {
                                switch (refresh->msg_type)
                                {
                                    case SRV_UM_MSG_SMS:
                                        if (SRV_SMS_STATUS_UNREAD & srv_sms_get_msg_status(refresh->msg_id))
                                        {
                                            isRead = MMI_FALSE;
                                        }
                                        break;
                        
                                #ifdef __MMI_MMS_IN_UM__
                                    case SRV_UM_MSG_MMS:
                                        if (MMI_FALSE == srv_mms_mma_get_mms_read_status(refresh->msg_id))
                                        {
                                            isRead = MMI_FALSE;
                                        }
                                        break;
                                #endif /* __MMI_MMS_IN_UM__ */
                        
                                #ifdef __MMI_PUSH_IN_UM__
                                    case SRV_UM_MSG_WAP_PUSH:
                                        if (MMI_FALSE == srv_wap_push_msg_read_status(refresh->msg_id))
                                        {
                                            isRead = MMI_FALSE;
                                        }
                                        break;
                                #endif /* __MMI_PUSH_IN_UM__ */
                        
                                #ifdef __MMI_PROV_IN_UM__
                                    case SRV_UM_MSG_PROV:
                                        if (SRV_PROVBOX_MSG_READ_STATUS_UNREAD == srv_provbox_get_msg_status(refresh->msg_id))
                                        {
                                            isRead = MMI_FALSE;
                                        }
                                        break;
                                #endif /* __MMI_PROV_IN_UM__ */
                        
                                    default:
                                        break;
                                }
                        
                                if (MMI_FALSE != isRead)
                                {
                                    force_create_unread = MMI_TRUE;
                                }
                            }
                        }
                        break;
                    }
                    case EVT_ID_SRV_UM_NOTIFY_READY:
                    {
                        force_create_unread = MMI_TRUE;
                    }
                }
            }
            if (force_create_unread)
            {
                mmi_um_ui_invoke_an_ncenter_entry(
                            MMI_UI_UM_NCENTER_UNREAD_MESSAGE, 
                            (WCHAR *)main_text, 
                            (WCHAR *)sub_text,
                            mmi_um_ui_unread_intent_handler, 
                            IMG_UM_UNREAD_ICON);
				mmi_um_alert_um_inbox_alert_set_icon_only();
            }
            else
            {
                mmi_um_ui_refresh_an_existing_ncenter_entry(
                            MMI_UI_UM_NCENTER_UNREAD_MESSAGE, 
                            (WCHAR *)main_text, 
                            (WCHAR *)sub_text,
                            mmi_um_ui_unread_intent_handler,
                            IMG_UM_UNREAD_ICON);
            }
            need_notify_unread = MMI_TRUE;
        }
        
    }
    
    if (!need_notify_unread)
    {
	    mmi_um_ui_dismiss_an_ncenter_entry(MMI_UI_UM_NCENTER_UNREAD_MESSAGE);
		/* unread icon will be dismissed when this cell is dismissed in its intent hanlder*/
    }
}

static void  mmi_um_ui_update_ncenter_send_failed(mmi_event_struct *evt)
{
    MMI_BOOL need_notify_send_failed = MMI_FALSE;
    MMI_BOOL force_create_send_failed = MMI_FALSE;
    if (srv_um_check_ready())
    {
    	S32 count = mmi_um_ui_get_send_failed_count();
        if (count)
        {
            MMI_ID string  = STR_UM_SEND_FAILED_MSGS_NUMBER;
            WCHAR main_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            WCHAR sub_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];
            
            mmi_wcscpy(main_text, (WCHAR *)GetString(STR_UM_SEND_FAILED_MSG));
            if (count == 1)
            {
               string = STR_UM_SEND_FAILED_MSG_NUMBER;
            }
            mmi_wsprintf(
                sub_text, 
                MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
                string, 
                count);
            
            {
                /* check if need to show new indication */
                switch (evt->evt_id)
                {
                    case EVT_ID_SRV_UM_NOTIFY_READY:
                    {
                        force_create_send_failed = MMI_TRUE;
                        break;
                    }
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                    case EVT_ID_SRV_UM_NOTIFY_REFRESH:
                    {
                        srv_um_notify_refresh_evt_struct *refresh;
                        refresh = (srv_um_notify_refresh_evt_struct *)evt;
                        if ((SRV_UM_MSG_BOX_ALL & refresh->msg_box_type) &&
                            (SRV_UM_REFRESH_NONE == refresh->refresh_type) && (refresh->msg_type == SRV_UM_MSG_SMS))
                        {
                            U8 yesORno_send_failed=1;
                            S16 error;
                            ReadValue(NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_FAILED, &yesORno_send_failed, DS_BYTE, &error);
                            if(yesORno_send_failed ==1)
                            force_create_send_failed = MMI_TRUE;
                        }
                        break;
                    }
#endif
                    case EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS:
                    {
                        srv_sms_event_struct *smsEvt;
                        srv_sms_event_update_unsent_msg_status_struct *smsUnsent;
                        smsEvt = (srv_sms_event_struct *)evt;
                        smsUnsent = (srv_sms_event_update_unsent_msg_status_struct *)smsEvt->event_info;
                        if (SRV_SMS_SEND_FAIL == smsUnsent->status)
                        {
                            force_create_send_failed = MMI_TRUE;
                        }
                    }
                #ifdef __MMI_MMS_IN_UM__
                    case EVT_ID_SRV_MMS_UPDATE_STATUS:
                    {
                        srv_mms_base_event_struct *mmsEvt;
                        srv_mms_update_status_struct *mmsUnsent;
                        mmsEvt = (srv_mms_base_event_struct *)evt;
                        mmsUnsent = (srv_mms_update_status_struct *)mmsEvt->sender_data;
                        
                        if (SRV_MMS_MSG_STATUS_SENDING_FAILED == mmsUnsent->status)
                        {
                            force_create_send_failed = MMI_TRUE;
                        }
                        break;
                    }
                #endif
                }
            }
            if (force_create_send_failed)
            {
                mmi_um_ui_invoke_an_ncenter_entry(
                    MMI_UI_UM_NCENTER_SENDFAILED_MESSAGE, 
                    (WCHAR*)main_text, 
                    (WCHAR*)sub_text,
                    mmi_um_ui_send_failed_intent_handler,
                    IMG_UM_SEND_FAILED_ICON);
				mmi_um_alert_um_outbox_alert_set_icon_only();
            }
            else
            {
                mmi_um_ui_refresh_an_existing_ncenter_entry(
                    MMI_UI_UM_NCENTER_SENDFAILED_MESSAGE, 
                    (WCHAR*)main_text, 
                    (WCHAR*)sub_text,
                    mmi_um_ui_send_failed_intent_handler,
                    IMG_UM_SEND_FAILED_ICON);
            }
            need_notify_send_failed = MMI_TRUE;
        }
    }
    if (!need_notify_send_failed)
    {
        mmi_um_ui_dismiss_an_ncenter_entry(MMI_UI_UM_NCENTER_SENDFAILED_MESSAGE);
		/* send failed icon will be dismissed when this cell is dismissed in its intent hanlder*/
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_update_ncenter
 * DESCRIPTION
 *  Update All NCenter Items of UM
 *
 * PARAMETERS
 *
 * RETURNS
 *    void
 *****************************************************************************/
static void mmi_um_ui_update_ncenter(mmi_event_struct *evt)
{
    mmi_um_ui_update_ncenter_unread(evt);
    mmi_um_ui_update_ncenter_send_failed(evt);
}
#endif


#if !defined (__MMI_UM_ULTRA_SLIM__) || defined(__MMI_NCENTER_SUPPORT__ )
S32 mmi_um_ui_get_send_failed_count(void)
{
	S32 count = 0;
	S32 result;

	/* sms part */
	{	
		U16 index;
		U16 msg_list_size;
		U16 msg_id;

		msg_list_size = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);

		for (index = 0; index < msg_list_size; index++)
		{
			msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_UNSENT, index);

			if (srv_sms_get_unsent_msg_status(msg_id) == SRV_SMS_SEND_FAIL)
			{
				count++;
			}
		}
	}
	
#ifdef __MMI_MMS_IN_UM__
	/* mms part */
	{
		srv_mms_get_msg_count_struct msg_count_req;
		S32 mms_count = 0;

		U16 requestSim = SRV_MMS_QUERY_TOTAL_OUTBOX_SIM1;
		U16 index = 0;

		memset(&msg_count_req, 0, sizeof(srv_mms_get_msg_count_struct));
		msg_count_req.count = MMI_MAX_SIM_NUM;

		for (index = 0; index < MMI_MAX_SIM_NUM ; index++, requestSim++)
		{
			msg_count_req.count++;
			msg_count_req.req_tb[index] = requestSim;
		}
		result = srv_mms_get_msg_count(&msg_count_req);
		
		if (SRV_MMS_RESULT_OK == result)
		{
			for (index = 0 ; index < MMI_MAX_SIM_NUM ; index++)
			{
				mms_count += msg_count_req.rsp_tb[index];
			}
            if(0 < mms_count)
			{
				if (MMI_TRUE == srv_mms_has_sending_mms())
				{
                    S32 mms_fail_count = 0;
                    mms_fail_count=srv_mms_get_send_failed_count();
                    if(mms_fail_count != mms_count)
					    mms_count--;
				}
				if (MMI_TRUE == srv_mms_has_waiting_mms())
				{
					S32 waitingCount = 0;
					waitingCount = srv_mms_get_waiting_mms_count();
					if (mms_count >= waitingCount)
					{
						mms_count -= waitingCount;
					}
					else
					{
						mms_count = 0;
					}
				}
			}
		}
		count += mms_count;
	}
#endif /* __MMI_MMS_IN_UM__ */
	return count;
}

#endif
#ifdef __MMI_APP_MANAGER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_package_proc
 * DESCRIPTION
 *  Provide badge with unread message number.
 *
 * PARAMETERS
 *  event                   [IN]: event from App manager
 *
 * RETURNS
 *  Handleing result
 *****************************************************************************/
mmi_ret mmi_um_package_proc (mmi_event_struct *evt)
{
    switch (evt->evt_id) 
    {
        case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE:
        {    
            srv_um_get_msg_num_result data;
            const S32 MAX_NUMBER = 999;
            if (srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data) == SRV_UM_RESULT_OK)
            {
                if (data.inbox_unread_msg_number > 0)
                {
                    if (MAX_NUMBER >= data.inbox_unread_msg_number)
                    {
                        mmi_wsprintf_ex(
                            ((srv_nativeappfactory_query_app_badge_evt_struct*)evt)->badge,
                            (SRV_APPMGR_BADGE_MAX_LEN + 1) * sizeof(WCHAR),
                            (WCHAR*)L"%d",
                            (data.inbox_unread_msg_number));
                    }
                    else
                    {
                            mmi_ucs2cpy((CHAR*)((srv_nativeappfactory_query_app_badge_evt_struct*)evt)->badge, (const CHAR *)L"...");
                    }
                }
                return MMI_RET_OK;
            }
        }
         default:
            return MMI_RET_DONT_CARE;
    }
}
#endif /* __MMI_APP_MANAGER_SUPPORT__ */

#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_reply_msg
 * DESCRIPTION
 *  Check if this message could be replied or not.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_reply_msg(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_ACTION, MMI_UM_UI_TB_ACTION_REPLY, msg_type, msg_id);
    result = MMI_FALSE;

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            result = mmi_sms_um_check_reply(msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            result = srv_mms_is_reply_on(msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            result = mmi_provbox_um_reply_check(msg_type, msg_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_forward_msg
 * DESCRIPTION
 *  Check if this message could be forwarded or not.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_forward_msg(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_ACTION, MMI_UM_UI_TB_ACTION_FORWARD, msg_type, msg_id);
    result = MMI_FALSE;

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            result = mmi_sms_um_check_forward(msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            result = srv_mms_is_forward_on(msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            result = mmi_provbox_um_forward_check(msg_type, msg_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_send_msg
 * DESCRIPTION
 *  Check if this message could be sent or not.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_send_msg(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_ACTION, MMI_UM_UI_TB_ACTION_SEND, msg_type, msg_id);
    result = MMI_FALSE;

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            result = mmi_sms_um_check_send(msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            result = srv_mms_is_send_on(msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            result = mmi_provbox_um_send_check(msg_type, msg_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_resend_msg
 * DESCRIPTION
 *  Check if this message could be resent or not.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_resend_msg(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_ACTION, MMI_UM_UI_TB_ACTION_RESEND, msg_type, msg_id);
    result = MMI_FALSE;

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            result = mmi_sms_um_check_resend(msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            result = srv_mms_is_resend_on(msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            result = mmi_provbox_um_resend_check(msg_type, msg_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_edit_msg
 * DESCRIPTION
 *  Check if this message could be edited or not.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_edit_msg(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_ACTION, MMI_UM_UI_TB_ACTION_EDIT, msg_type, msg_id);
    result = MMI_FALSE;

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            result = mmi_sms_um_check_edit(msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            result = srv_mms_is_edit_on(msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            result = mmi_provbox_um_edit_check(msg_type, msg_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_delete_msg
 * DESCRIPTION
 *  Check if this message could be deleted or not.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_delete_msg(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_ACTION, MMI_UM_UI_TB_ACTION_DELETE, msg_type, msg_id);
    result = MMI_FALSE;

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            result = mmi_sms_um_check_delete(msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            result = srv_mms_is_delete_on(msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            result = srv_push_check_um_delete(msg_type, msg_id);
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            result = mmi_provbox_um_delete_check(msg_type, msg_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_copy_msg
 * DESCRIPTION
 *  Check if this message could be copied or not.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_copy_msg(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_ACTION, MMI_UM_UI_TB_ACTION_COPY, msg_type, msg_id);
    result = MMI_FALSE;

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            result = mmi_sms_um_check_copy(msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_check_move_msg
 * DESCRIPTION
 *  Check if this message could be moved or not.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_um_ui_adp_check_move_msg(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CHECK_ACTION, MMI_UM_UI_TB_ACTION_MOVE, msg_type, msg_id);
    result = MMI_FALSE;

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            result = mmi_sms_um_check_move(msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_reply_msg
 * DESCRIPTION
 *  Reply the specified message.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *  parent_grp_id           [IN]: Parent Group id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_adp_reply_msg(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPERATE_ACTION, MMI_UM_UI_TB_ACTION_REPLY, msg_type, msg_id);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            mmi_sms_um_activate_reply(parent_grp_id, msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            mmi_umms_app_if_reply_mms(parent_grp_id, msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            mmi_provbox_um_activate_reply(msg_type, msg_id, parent_grp_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_forward_msg
 * DESCRIPTION
 *  Forward the specified message.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *  parent_grp_id           [IN]: Parent Group id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_adp_forward_msg(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPERATE_ACTION, MMI_UM_UI_TB_ACTION_FORWARD, msg_type, msg_id);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            mmi_sms_um_activate_forward(parent_grp_id, msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            mmi_umms_app_if_forward_mms(parent_grp_id, msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            mmi_provbox_um_activate_forward(msg_type, msg_id, parent_grp_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_send_msg
 * DESCRIPTION
 *  Send the specified message.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *  parent_grp_id           [IN]: Parent Group id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_adp_send_msg(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPERATE_ACTION, MMI_UM_UI_TB_ACTION_SEND, msg_type, msg_id);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            mmi_sms_um_activate_send(parent_grp_id, msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            mmi_umms_app_if_send_mms(parent_grp_id, msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            mmi_provbox_um_activate_send(msg_type, msg_id, parent_grp_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_resend_msg
 * DESCRIPTION
 *  Resend the specified message.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *  parent_grp_id           [IN]: Parent Group id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_adp_resend_msg(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPERATE_ACTION, MMI_UM_UI_TB_ACTION_RESEND, msg_type, msg_id);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            mmi_sms_um_activate_resend(parent_grp_id, msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            mmi_umms_app_if_resend_mms(parent_grp_id, msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            mmi_provbox_um_activate_resend(msg_type, msg_id, parent_grp_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_edit_msg
 * DESCRIPTION
 *  Edit the specified message.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *  parent_grp_id           [IN]: Parent Group id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_adp_edit_msg(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPERATE_ACTION, MMI_UM_UI_TB_ACTION_EDIT, msg_type, msg_id);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            mmi_sms_um_activate_edit(parent_grp_id, msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            mmi_umms_app_if_edit_mms(parent_grp_id, msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            mmi_provbox_um_activate_edit(msg_type, msg_id, parent_grp_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_delete_msg
 * DESCRIPTION
 *  Delete the specified message.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *  parent_grp_id           [IN]: Parent Group id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_adp_delete_msg(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPERATE_ACTION, MMI_UM_UI_TB_ACTION_DELETE, msg_type, msg_id);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            mmi_sms_um_activate_delete(parent_grp_id, msg_type, msg_id);
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
        #ifdef __MMI_MMS_2__
            mmi_umms_app_if_delete_mms(parent_grp_id, msg_id);
        #endif /* __MMI_MMS_2__ */
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            srv_push_activated_um_delete(parent_grp_id, msg_type, msg_id);
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            mmi_provbox_um_activate_delete(msg_type, msg_id, parent_grp_id);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_copy_msg
 * DESCRIPTION
 *  Copy the specified message.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *  parent_grp_id           [IN]: Parent Group id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_adp_copy_msg(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPERATE_ACTION, MMI_UM_UI_TB_ACTION_COPY, msg_type, msg_id);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            mmi_sms_um_activate_copy(parent_grp_id, msg_type, msg_id);
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_move_msg
 * DESCRIPTION
 *  Move the specified message.
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *  msg_id                  [IN]: The specified message id
 *  parent_grp_id           [IN]: Parent Group id
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ui_adp_move_msg(srv_um_msg_enum msg_type, U32 msg_id, MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPERATE_ACTION, MMI_UM_UI_TB_ACTION_MOVE, msg_type, msg_id);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            mmi_sms_um_activate_move(parent_grp_id, msg_type, msg_id);
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */


#ifdef __MMI_UM_ITERATOR_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_get_viewer_ptr
 * DESCRIPTION
 *  Get the launch viewer of messages
 *
 * PARAMETERS
 *  msg_type                [IN]: The specified message type
 *
 * RETURNS
 *  The launch viewer function pointer
 *****************************************************************************/
cui_msg_viewer_launch_ptr mmi_um_ui_adp_get_viewer_ptr(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_msg_viewer_launch_ptr func_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_GET_VIEWER_PTR, msg_type);

    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            func_ptr = mmi_sms_launch_viewer;
            break;
        }
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            func_ptr = mmi_umms_app_if_start_viewer;
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            func_ptr = mmi_wap_push_if_launch_viewer;
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            func_ptr = mmi_provbox_um_iter_launch_viewer;
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            break;
        }
    }

    return func_ptr;
}
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

#ifndef __MMI_SMS_SLIM__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_get_opt_menu_id
 * DESCRIPTION
 *  It is used to query the option menu id from each message application.
 *
 * PARAMETERS
 *  msg_type                [IN]: Message type
 *  msg_id                  [IN]: Message id
 *
 * RETURNS
 *  Menu id value
 *****************************************************************************/
MMI_MENU_ID mmi_um_ui_adp_get_opt_menu_id(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID opt_menu_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_GET_OPT_MENU_ID, msg_type, msg_id);
    opt_menu_id = MENU_ID_UM_OPT;

    switch (msg_type)
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        case SRV_UM_MSG_SMS:
        {
            opt_menu_id = mmi_sms_get_list_opt_menu_id(msg_id);
            break;
        }
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            opt_menu_id = umms_menu_query_function(msg_id);
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            opt_menu_id = mmi_wap_push_get_um_option_menu_id();
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            opt_menu_id = mmi_provbox_um_get_option_menu_id();
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
        }
    }

    return opt_menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_opt_cb
 * DESCRIPTION
 *  The callback function provided by message application. It is used to 
 *  handle the menu cui event.
 *
 * PARAMETERS
 *  evt                     [IN]: Menu cui event
 *  msg_type                [IN]: Message type
 *  para                    [IN]: Parameter
 *
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_um_ui_adp_opt_cb(mmi_event_struct *evt, srv_um_msg_enum msg_type, mmi_um_opt_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_OPT_CB, msg_type, para->msg_id);
    ret = MMI_RET_OK;

    switch (msg_type)
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        case SRV_UM_MSG_SMS:
        {
            ret = mmi_sms_um_list_opt_cb_hdlr(evt, para);
            break;
        }
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            ret = umms_cb_hdlr(evt, para);
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            ret = mmi_push_option_cb_hdlr(evt, para);
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
        {
            ret = mmi_provbox_um_menu_cui_proc(evt, para);
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return ret;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_cui_launch_by_menu_id
 * DESCRIPTION
 *  Launch the cui_xxx_launch by menu id and group id.
 *
 * PARAMETERS
 *  parent_grp_id           [IN]: Parent gruod id. (ususally is UM's group)
 *  menu_id                 [IN]: Selected menu id
 *
 * RETURNS
 *  The message ap's group id;
 *****************************************************************************/
MMI_ID mmi_um_ui_adp_cui_launch_by_menu_id(MMI_ID parent_grp_id, MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_CUI_LAUNCH_MENU_ID, parent_grp_id, menu_id);

    switch (menu_id)
    {
        case MENU_ID_UM_WRITE_MSG_SMS:
        {
            cui_sms_write_launch(parent_grp_id);
            break;
        }
        case MENU_ID_UM_WRITE_MSG:
    #ifdef __MMI_MMS_IN_UM__
        case MENU_ID_UM_WRITE_MSG_MMS:
        {
            cui_uc_write_msg_launch(parent_grp_id);
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #if defined(MMS_SUPPORT) && !defined(__UM_FOLDER__)
        case MENU_ID_UM_MMS_V01_MAIN:
        {
            break;
        }
    #endif /* MMS_SUPPORT & !__UM_FOLDER__ */
    #if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) && !defined(__MMI_APP_MANAGER_SUPPORT__)
        case MENU_ID_UM_PBOX_MAIN:
        {
            mmi_provbox_pre_entry_from_message(parent_grp_id);
            break;
        }
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ & !__MMI_PROV_IN_UM__ */
    #ifdef __MMI_EMAIL__
        case MENU_ID_UM_EMAIL_MAIN:
        {
            mmi_email_main_pre_entry_from_message(parent_grp_id);
            break;
        }
    #endif /* __MMI_EMAIL__ */
    #ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_IMPS__ */
    #ifdef __MMI_CBS_SUPPORT__
        case MENU_ID_UM_CB_MAIN:
        {
            cui_sms_cbs_launch(parent_grp_id);
            break;
        }
    #endif
   #if !defined(__MMI_PUSH_IN_UM__) && defined(BROWSER_SUPPORT) && defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
        case MENU_ID_UM_WAP_PUSH_MSG_MAIN:
        {
            cui_wap_push_service_msg_main_menu_launch(parent_grp_id);
            break;
        }
    #endif /* !__MMI_PUSH_IN_UM__ && BROWSER_SUPPORT */
    #ifdef __MMI_MESSAGES_TEMPLATE__
        case MENU_ID_UM_TEMPLATE_SMS:
    #ifndef __UM_FOLDER__
        case MENU_ID_UM_TEMPLATE_SMS_ONLY:
    #endif /* __UM_FOLDER__ */
        {
            cui_sms_templates_launch(parent_grp_id);
            break;
        }
    #endif /* __MMI_MESSAGES_TEMPLATE__ */
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MENU_ID_UM_TEMPLATE_MMS:
        {
            cui_umms_mms_templates_launch(parent_grp_id);
            break;
        }
    #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */
        case MENU_ID_UM_SETTING_SMS:
    #ifndef __UM_FOLDER__
    #if ((defined(__MMI_BT_MAP_CLIENT__) && defined(__MMI_TELEPHONY_SUPPORT__)) || (!defined(__MMI_BT_MAP_CLIENT__)))
        case MENU_ID_UM_SETTING_SMS_ONLY:
    #endif
    #endif /* __UM_FOLDER__ */
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            cui_sms_setting_launch(parent_grp_id);
            break;
        #endif /*__MMI_TELEPHONY_SUPPORT__*/
        }
    #ifdef __MMI_MMS_IN_UM__
        case MENU_ID_UM_SETTING_MMS:
        {
            cui_umms_mms_settings_launch(parent_grp_id);
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case MENU_ID_UM_SETTING_PUSH:
        {
            cui_wap_push_service_msg_setting_launch(parent_grp_id);
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_get_msg_box
 * DESCRIPTION
 *  It used to get the message box type for specified message id.
 *
 * PARAMETERS
 *  msg_type                [IN]: the message type of selected message
 *  id                      [IN]: the message id of selected message
 *
 * RETURNS
 *  The message box type of this message
 *****************************************************************************/
srv_um_msg_box_enum mmi_um_ui_adp_get_msg_box(srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_box_enum box_type = SRV_UM_MSG_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UM_UI_ADP_GET_MSG_BOX, msg_type, msg_id);

    switch (msg_type)
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        case SRV_UM_MSG_SMS:
        {
            box_type = mmi_sms_query_um_msg_box(msg_id);
            break;
        }
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            box_type = (srv_um_msg_box_enum) mmi_umms_app_if_get_um_box_type_from_msg_id(msg_id);
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */
    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
        {
            box_type = SRV_UM_MSG_BOX_INBOX;
            break;
        }
    #endif /* __MMI_PUSH_IN_UM__ */
	#if (defined(__MMI_PROV_MESSAGE_SUPPORT__)) || (!defined(__MMI_PROV_IN_UM__) && !defined(__MMI_APP_MANAGER_SUPPORT__))        
		case SRV_UM_MSG_PROV:
        {
            box_type = SRV_UM_MSG_BOX_INBOX;
            break;
        }
    #endif /* __MMI_PROV_IN_UM__ */
        default:
        {
            MMI_ASSERT(0);
        }
    }

    return box_type;
}
#ifdef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_ui_adp_cui_msg_delete_launch
 * DESCRIPTION
 *  It used to launch the cui to launch delete message folder (Inbox/Outbox etc).
 *
 * PARAMETERS
 *  parent_grp_id           [IN]: Parent group id. (ususally is UM's group)
 *  menu_id                 [IN]: Selected menu id
 *
 * RETURNS
 *  The message ap's group id
 *****************************************************************************/
MMI_ID mmi_um_ui_adp_cui_msg_delete_launch(MMI_ID parent_grp_id, MMI_MENU_ID menu_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	MMI_ID cui_menu_id = GRP_ID_INVALID;
	MMI_ID opt_grp_id;
	mmi_um_ui_cc_scrn_cntx_struct *scrn_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	scrn_cntx = mmi_um_ui_sh_get_active_user_data();
    CHECK_SCRN_CNTX_PARA_VALID(scrn_cntx);

	opt_grp_id = mmi_frm_group_create(
                            parent_grp_id, 
                            GRP_ID_AUTO_GEN, 
                            mmi_um_ui_sh_general_folder_opt_proc, 
                            (void*) scrn_cntx);
    mmi_frm_group_enter(opt_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	cui_menu_id = cui_menu_create(
                            opt_grp_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPMAIN, 
                            menu_id, 
                            MMI_TRUE, 
                            NULL);

	/* Set default string/icon */
    cui_menu_set_default_title(
            cui_menu_id, 
            (WCHAR*)GetString(STR_UM_DELETE_FOLDER_ID), 
            (UI_image_type)GetImage(IMG_UM_ENTRY_SCRN_CAPTION));

    cui_menu_run(cui_menu_id);
}
#endif
#endif /* __UM_SUPPORT__ */
