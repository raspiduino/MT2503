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
 * PushMsgUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination User interface display of service messages.
 *
 * Author:
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#include "MMI_include.h"
    #include "MMI_features.h"
    #include "WAPPushSrvTypes.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
#ifdef __WAP_PUSH_SUPPORT__



#include "MessagesMiscell.h"
#include "IdleNotificationManagerGprot.h"
#include"mmi_rp_srv_status_icons_def.h"
#include "WAPProfileSrvType.h"

#ifdef __MMI_OP12_TOOLBAR__
#include "IdleToolbarGprot.h"
#endif
#include "DateTimeGprot.h"
#include "SmsAppGprot.h"
//#include "app_url.h"
//#include "SettingProfile.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "IdleGprot.h"
#include "IdleAppProt.h"
//#include "time.h"
#include "CommonScreens.h"
#include "SMSGuiInterfaceProt.h"

//#include "ProfileGprots.h"
//#include "GpioSrvGprot.h"
//#include "SimDetectionGprot.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif

//#if defined(__MMI_WLAN_FEATURES__)
//#include "NetworkSetupDefs.h"
//#endif

//#include "Mmsadp.h"
//#include "MessagesResourceData.h"
#include "WAPPushUIProts.h"
#include "BookmarkCuiGprot.h"
#include "servicemsgcuigprot.h"
#include "ModeSwitchSrvGprot.h"

    #include "mmi_frm_scenario_gprot.h"
    #include "WAPPushUITypes.h"
    #include "mmi_res_range_def.h"
    #include "WAPPushResDef.h"
    #include "gui_typedef.h"
    #include "CustMenuRes.h"
    #include "NetSetSrvGprot.h"
    #include "NetSetAppGprot.h"
    #include "WAPPushSrvProts.h"
    #include "mms_api.h"
    #include "pmg_struct.h"
    #include "mmi_rp_app_mmi_wap_push_def.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "MMI_inet_app_trc.h"
    #include "mmi_frm_history_gprot.h"
    #include "WAPPushScreenHdlr.h"
    #include "GlobalResDef.h"
    #include "kal_public_api.h"
    #include "InlineCuiGprot.h"
    #include "wgui_categories_util.h"
    #include "wgui_inline_edit.h"
    #include "GlobalConstants.h"
    #include "GlobalMenuItems.h"
    #include "wap_adp.h"
    #include "string.h"
    #include "Unicodexdcl.h"
    #include "UmSrvStruct.h"
    #include "mmi_frm_queue_gprot.h"
    #include "app_ltlcom.h"
    #include "UmSrvDefs.h"
    #include "stack_msgs.h"
    #include "mmi_frm_events_gprot.h"
    #include "menucuigprot.h"
    #include "mmi_frm_mem_gprot.h"
    #include "common_nvram_editor_data_item.h"
    #include "CustDataRes.h"
    #include "NotificationGprot.h"
    #include "browser_api.h"
    #include "custom_phb_config.h"
//   #if defined(__VODAFONE_R12_LIVE__)  
 //   #include "op_custom_wap_config.h"
// #endif /* defined(__VODAFONE_R12_LIVE__) */

    #include "WAPPushCntrlr.h"
    #include "mmi_rp_app_sms_def.h"
    #include "wgui_categories.h"
    #include "WAPPushDMgr.h"
    #include "UMGProt.h"
    #include "ProfilesSrvGprot.h"
    #include "gui_data_types.h"
    #include "gui.h"
    #include "ps_public_enum.h"
    #include "WAPProfileSrvType.h"
    #include "IdleAppDef.h"
    #include "GpioSrvGprot.h"
    #include "MsgViewerCuiGProt.h"
    #include "WAPPushSrvGprots.h"
    #include "mmi_frm_nvram_gprot.h"
     #include "gui_effect_oem.h"
    #include "wgui_categories_list.h"
    #include "wgui_fixed_menus.h"
    #include "gui_fixed_menus.h"
  
    #include "UMDefs.h"
    #include "mmiapi_dm_struct.h"
    #include "dmuigprot.h"
    #include "SimCtrlSrvGprot.h"
    #include "NwUsabSrvGprot.h"
	#include "vsrv_ncenter.h"
    #include "NotificationSettingSrvGprot.h" //for NSS



extern mmi_id menu_id_new;
void mmi_wap_push_nss_alert_sia ();
void mmi_wap_push_nss_alert_unknown();
void mmi_wap_push_handle_sl_on_non_idle (srv_wap_push_handle_sl_on_non_idle_struct *evt);
void mmi_wap_push_handle_sl_on_idle (srv_wap_push_handle_sl_on_idle_struct *evt);
mmi_ret mmi_wap_push_display_msg(U16 grp_id);
void mmi_wap_push_launch_sl (U32 message_id, S8 *message_url, U32 sim_id);
#ifdef __MMI_PUSH_IN_MSG__
mmi_ret mmi_wap_push_nss_unread_popup(mmi_event_struct *evt);
#endif
#ifdef __MMI_NCENTER_SUPPORT__
 mmi_ret mmi_wap_push_ncenter_msg_queue_handler(mmi_event_struct *evt);
 #ifdef __MMI_PUSH_IN_MSG__
 void mmi_wap_push_ncenter_unread_messages();
 vsrv_notification_handle nhandle_unread;
 #endif
MMI_BOOL nshow=MMI_TRUE;
MMI_BOOL mshow=MMI_TRUE;
vsrv_notification_handle nhandle_dlg;

#endif
U32 g_nmgr_handle;

MMI_BOOL mmi_wap_push_is_push_scr_is_current_active_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*To be implemented*/
    if (mmi_frm_group_is_in_top_scope (g_push_cntxt->scr_grp_id))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void mmi_wap_push_delete_screen_if_present (U16 screen_id)
{
    mmi_id group_id;
    mmi_ret result;

    for (group_id = (MMI_WAP_PUSH_BASE + 1); group_id < GRP_ID_BRW_PUSH_END; group_id++)
    {
        if (mmi_frm_group_is_present (group_id))
        {
            result = mmi_frm_scrn_close(group_id, screen_id);
            if (MMI_RET_OK == result)
            {
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_adjust_hide_highlight_menu_item
 * DESCRIPTION
 *      adjust the highlight and menu item.
 * PARAMETERS
 *  show_flag        [IN] : hide or unhide menu item
 *  child_item_id    [IN] : the child menu item
 *  parent_item_id   [IN] : the parent menu item
 *  gui_buffer       [IN] : the current gui buffer
 *  screen_id        [IN] :
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_adjust_hide_highlight_menu_item(MMI_BOOL show_flag, U16 child_item_id, U16 parent_item_id, U8* gui_buffer, U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    list_menu_category_history *h = (list_menu_category_history*)gui_buffer;
	U16 highlight_item_id = 0;
	S16 gui_hiliteitem = 0;
    S16 new_highlight_index;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First entry main message menu */
    if (mmi_wap_push_is_screen_present(screen_id) == MMI_FALSE)
    {
        if (show_flag == MMI_TRUE)
        {
            mmi_frm_unhide_menu_item(child_item_id);
        }
        else
        {
            mmi_frm_hide_menu_item(child_item_id);
        }
        return;
    }

    /* Goback history to adjust the highlight and menu item */
    /* get the current highlight menu item id */
    if (gui_buffer != NULL)
    {
		gui_hiliteitem = h->highlighted_item;
		highlight_item_id = GetSeqItemId_Ext(parent_item_id, gui_hiliteitem);
	}

    /* hide/unhide the menu item */
    if (show_flag == MMI_TRUE)
    {
        mmi_frm_unhide_menu_item(child_item_id);
    }
    else
    {
        mmi_frm_hide_menu_item(child_item_id);
    }

    /* reset the highlight index by current highlight menu item */
    if (gui_buffer != NULL)
    {
		new_highlight_index = GetIndexOfStringId_Ext(parent_item_id, highlight_item_id);

		if (new_highlight_index != gui_hiliteitem)
		{
			h->highlighted_item = new_highlight_index;
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_send_proc_default
 * DESCRIPTION
 *  Use to handle default case of proc functions
 * PARAMETERS
 *  EVT  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_send_proc_default(mmi_event_struct *evt)
{
	
              if (evt->user_data)
                {
					mmi_wap_push_screenDB_struct *scrDB = evt->user_data;
					if (NULL != scrDB->screen)
					{

						cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

						if (((mmi_wap_push_scrhdlr_static_screen_struct *)scrDB->screen)->leaf_node_hdlr)
						{
							((mmi_wap_push_scrhdlr_static_screen_struct *)scrDB->screen)->leaf_node_hdlr(evt);
						}
						if (menu_evt->evt_id == EVT_ID_CUI_MENU_CLOSE_REQUEST)
						{
							OslMfree(scrDB->screen);
							scrDB->screen = NULL;
						}
					}
                }
}
#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_hide_send_by
 * DESCRIPTION
 *  Use to decide whether to hide send by or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if needed to hide otherwise FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_hide_send_by (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
        #if defined (__FLIGHT_MODE_SUPPORT__)
                (!srv_mode_switch_is_network_service_available()) ||
        #endif 
        (!srv_sim_ctrl_get_one_available_sim()))
	{
    #if defined(MMS_SUPPORT)
        if (!mms_is_ready())
        {
        #if  defined(__MMI_EMAIL__)
            if (!mmi_email_is_email_can_forward())
	        {
		        return MMI_FALSE;
	        }
	        else
	        {
		        return MMI_TRUE;
	        }
        #endif /* __MMI_EMAIL__ */ 
        }
        else
        {
            return MMI_TRUE;
        }

    #endif /* defined(MMS_SUPPORT) */ 
	}
    else
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_display_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_msg        [IN]
 *  url            [IN]
 *  read_from_um   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_handle_display_msg (pmg_detailed_msg_struct *new_msg, S8 *url, MMI_BOOL read_from_um)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
    {
        g_srv_wap_push_cntxt->read_from_um = read_from_um;

		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_DISPLAY_MESSAGE);
		srv_wap_push_copy_data_to_selected_message(new_msg, url);
		srv_wap_push_update_service_msg_req(new_msg->msg_id);
		srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXIT_DISPLAY_MESSAGE);
        mmi_wap_push_display_msg( g_push_cntxt->scr_grp_id);

        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
    }
    else
    {
        if (mmi_wap_push_is_screen_present (SCR_ID_PUSH_GENERIC_PROCESSING))
        {
            mmi_frm_node_struct new_node;
            MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_PROGRESSING_SCREEN_IN_HISTORY);
            g_srv_wap_push_cntxt->read_from_um = read_from_um;
            srv_wap_push_copy_data_to_selected_message(new_msg, url);
            srv_wap_push_update_service_msg_req(new_msg->msg_id);
          //  HistoryReplace (SCR_ID_PUSH_GENERIC_PROCESSING, SCR_ID_BRW_READ_SERVICE_MESSAGE, mmi_wap_push_scrhdlr_entry_message_display);
           
            new_node.id= SCR_ID_BRW_READ_SERVICE_MESSAGE;
            new_node.entry_proc= (mmi_proc_func)mmi_wap_push_scrhdlr_entry_message_display;
            new_node.user_data=NULL;
            mmi_frm_scrn_replace( GRP_ID_BRW_PUSH_BODY, SCR_ID_PUSH_GENERIC_PROCESSING ,&new_node);
            srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_read_message
 * DESCRIPTION
 *  open the message.
 * PARAMETERS
 *  msg_id        [IN]
 *  read_from_um  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_read_message (U32 msg_id, MMI_BOOL read_from_um)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 trans_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (read_from_um)
    {
        trans_id = PUSH_GET_MSG_TO_DISPLAY_FROM_UM_TRANS_ID;
    }
    else
    {
        trans_id = PUSH_GET_MSG_TO_DISPLAY_TRANS_ID;
    }
    srv_wap_push_get_full_message (msg_id, trans_id);
    mmi_wap_push_scrhdlr_entry_generic_processing();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_add_bkm_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_handle_add_bkm_rsp (srv_wap_push_add_bkm_error  ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HANDLE_ADD_BKM_RSP, (U16)ret_code);
    switch (ret_code)
    {
    case SRV_WAP_PUSH_ADD_BKM_ERROR_SUCCESS:
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_SUCCESS, STR_GLOBAL_SAVED);
        break;
    case SRV_WAP_PUSH_ADD_BKM_ERROR_INVALID_TITLE:
        /*TODO: Lookup for the error string */
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_INVALID_FILENAME);
        break;
    case SRV_WAP_PUSH_ADD_BKM_ERROR_INVALID_URL:
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_INVALID_URL);
        break;
    case SRV_WAP_PUSH_ADD_BKM_ERROR_PROCESSING:
        if (mmi_frm_scrn_get_active_id() != SCR_ID_PUSH_GENERIC_PROCESSING)
        {
            mmi_wap_push_scrhdlr_entry_generic_processing();
        }
        break;
    case SRV_WAP_PUSH_ADD_BKM_ERROR_BOOKMARK_FULL:
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_ID_PUSH_BKM_LIST_FULL);
        break;
    case SRV_WAP_PUSH_ADD_BKM_ERROR_EMPTY_TITLE:
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_PLEASE_INPUT_THE_FILENAME);
        break;
    case SRV_WAP_PUSH_ADD_BKM_ERROR_CURRENTLY_NOT_AVAILABLE:
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_ID_PUSH_BKM_NOT_AVAILABLE);
        break;
    case SRV_WAP_PUSH_ADD_BKM_TITLE_URL_LONG_ERROR:
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_ID_PUSH_TITLE_URL_TOO_LONG);
        break;
    default:
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE);
        break;
    }
    if (ret_code != SRV_WAP_PUSH_ADD_BKM_ERROR_PROCESSING)
    {
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
    }
    if (ret_code == SRV_WAP_PUSH_ADD_BKM_ERROR_SUCCESS)
    {
        mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_PUSH_ADD_BOOKMARK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_go_back_two_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_go_back_two_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_push_cntxt->inline_gid != GRP_ID_INVALID);
    cui_inline_close(g_push_cntxt->inline_gid);
    g_push_cntxt->inline_gid = GRP_ID_INVALID;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_full_screen_edit
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_full_screen_edit (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(SERVICES_WAP_MENU_ID));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_exit_add_bookmark
 * DESCRIPTION
 *  Exit function for Add bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_exit_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


void mmi_wap_push_invoke_add_bkm_cui (U8 *url)
{
#ifdef BROWSER_SUPPORT
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__ 
    mmi_id group_id;
    group_id = cui_bkm_add_bkm_create (g_push_cntxt->scr_grp_id);
    if(group_id==GRP_ID_INVALID)
         return;
    cui_bkm_add_bkm_run (group_id, (U8*)url);
 #endif 
#else
    mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE);
#endif /* BROWSER_SUPPORT */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_pre_entry_add_bookmark
 * DESCRIPTION
 *  Pre Entry function for Add bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_pre_entry_add_bookmark (S8 *title, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 added_utf8_url[WAP_MAX_URL_LENGTH + 1] = {'\0','\0', };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_push_cntxt->add_bkm.title, 0, ((MMI_BRW_PUSH_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH));
    memset(g_push_cntxt->add_bkm.url, 0, ((WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH));
    if (title != NULL)
    {
        mmi_asc_n_to_ucs2(g_push_cntxt->add_bkm.title, title, MMI_BRW_PUSH_MAX_TITLE_LENGTH);
    }
    if (url != NULL)
    {
        mmi_asc_n_to_ucs2(g_push_cntxt->add_bkm.url, url, WAP_MAX_URL_LENGTH);
    }
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)added_utf8_url, WAP_MAX_URL_LENGTH + 1, (kal_uint8 *)g_push_cntxt->add_bkm.url);
    mmi_wap_push_invoke_add_bkm_cui ((U8*) added_utf8_url);
}


#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_add_msg_deleted_screen_in_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_add_msg_deleted_screen_in_history (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history hist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_wap_push_is_push_screen_active())
    {
        mmi_wap_push_update_inbox_selected_index (-1);
		mmi_frm_group_close (GRP_ID_BRW_PUSH_FROM_IDLE);
		mmi_frm_group_close (GRP_ID_BRW_PUSH_BODY);
		mmi_frm_group_close (GRP_ID_BRW_PUSH_POPUP);
		mmi_frm_group_close (GRP_ID_BRW_PUSH_POPUP_CONFIRM);
        mmi_wap_push_scrhdlr_entry_msg_deleted_screen();
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ADDED_MESSAGE_DELETED_SCR_IN_HIST);
    }
}
#endif /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */

/************************************************************************************************/
/*******************************  Start inbox related functions definations  ********************/
/************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_clear_inbox_history
 * DESCRIPTION
 *  Clear the highlighted index of inbox screen.
 * PARAMETERS
 *  void.
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_clear_inbox_history (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_CLEAR_INBOX_HISTORY_POINTER);

    mmi_frm_scrn_clean_gui_buf (GRP_ID_BRW_PUSH_INBOX, SCR_ID_PUSH_INBOX);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_update_inbox_selected_index
 * DESCRIPTION
 *  Update the selected index of inbox message and set the status as refresh.
 * PARAMETERS
 *  factor           [IN]
 * RETURNS
 *  true if updated otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_update_inbox_selected_index (S16 factor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_wap_push_is_screen_present (SCR_ID_PUSH_INBOX)) || (SCR_ID_PUSH_INBOX == mmi_frm_scrn_get_active_id ()))
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_UPDATE_INBOX_STATUS, factor);
        /* Need to set state even for zero also for replaced messages */
        g_push_inbox_ctxt->num_of_messages += factor;
        g_push_inbox_ctxt->inbox_state = SRV_WAP_PUSH_INBOX_NEED_REFRESH;

        if (factor > 0)
        {
            g_push_inbox_ctxt->sel_idx = g_push_inbox_ctxt->sel_idx + (factor);
            return MMI_TRUE;
        }
        else if (factor < 0)
        {
            if (g_push_inbox_ctxt->sel_idx != 0)
            {
                g_push_inbox_ctxt->sel_idx = g_push_inbox_ctxt->sel_idx + (factor);
            }
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_read_selected_message
 * DESCRIPTION
 *  read the selected message in the inbox.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_read_selected_message (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = g_push_inbox_ctxt->sel_idx - g_push_inbox_ctxt->start_index;

    g_srv_wap_push_cntxt->selected_message.msg_type = WAP_PMG_MSGTYPE_NULL;
    g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
    g_srv_wap_push_cntxt->selected_message_id = g_push_inbox_ctxt->list_item[count].msg_id;
    mmi_wap_push_scrhdlr_entry_message_display_group(g_push_cntxt->scr_grp_id);
    g_push_inbox_ctxt->list_item[count].read = 1; /* Updating the display buffer for Icon */
      #ifdef __MMI_NCENTER_SUPPORT__
             #ifdef __MMI_PUSH_IN_MSG__
                mmi_wap_push_ncenter_unread_messages();
              #endif
       #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_display_async_loading_screen
 * DESCRIPTION
 *  Display please wait screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_display_async_loading_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() != SCR_ID_PUSH_ASYNC_PROCESSING)
    {
        mmi_wap_push_scrhdlr_entry_async_processing();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_set_highlighted_index_item
 * DESCRIPTION
 *  Highlight handler of selected Item list
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_set_highlighted_index_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_inbox_ctxt->sel_idx = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_cancel_pending_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_cancel_pending_events (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PUSH_IN_UM__
	srv_um_cancel_new_msg_ind_struct *um_local_data = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_all_queue_entry();
#ifdef __MMI_PUSH_IN_UM__
    um_local_data = (srv_um_cancel_new_msg_ind_struct*) OslConstructDataPtr(sizeof(srv_um_cancel_new_msg_ind_struct));

	um_local_data->msg_type = SRV_UM_MSG_WAP_PUSH;
	um_local_data->msg_box_type = SRV_UM_MSG_BOX_INBOX;
    srv_wap_push_send_msg_to_mmi (MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND, (void*)um_local_data);
#endif /* __MMI_PUSH_IN_UM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_notify_category
 * DESCRIPTION
 * 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_notify_category (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
    if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_ASYNC_PROCESSING)
    {
        mmi_frm_scrn_close_active_id();
    }
    else if (!gui_screen_smooth_scrolling_in_freerun())
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_INBOX)
        {
            mmi_cat_refresh_asyncdynamic_list(
                MMI_fixed_list_menu.n_items, 
                MMI_fixed_list_menu.highlighted_item, 
                mmi_wap_push_get_async_items,
                NULL);
        }
    }
    else
    {
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_ASYNC_PROCESSING);
    }
#else /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
    if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_ASYNC_PROCESSING)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_ASYNC_PROCESSING);
    }
#endif /* __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_add_to_msg_list
 * DESCRIPTION
 * This API add the messages into message list. 
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_add_to_msg_list (wps_pmg_msg_list_cnf_struct **msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_msg_list_cnf_struct *msg_list =  *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy (&g_push_inbox_ctxt->list_item[g_push_inbox_ctxt->curr_index], 
        msg_list->msg_list_data, 
        (sizeof (pmg_msg_list_struct) * msg_list->size));

    g_push_inbox_ctxt->curr_index += msg_list->size;

    if (msg_list->size_remain)
    {
        srv_wap_push_get_list_from_service_layer ((g_push_inbox_ctxt->read_index + g_push_inbox_ctxt->curr_index), 
			msg_list->size_remain, 
			PUSH_MSG_LIST_INBOX_DSPLY_TRANS_ID,
			WAP_PMG_PARAM_NOT_SPECIFIED);
    }
    else
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ADD_LIST_COMPLETED, g_push_inbox_ctxt->inbox_state);
        if (SRV_WAP_PUSH_INBOX_STATE_LOADING == g_push_inbox_ctxt->inbox_state) 
        {
            g_push_inbox_ctxt->inbox_state = SRV_WAP_PUSH_INBOX_LIST_READY;
            g_push_inbox_ctxt->start_index = g_push_inbox_ctxt->read_index;
            g_push_inbox_ctxt->end_index = g_push_inbox_ctxt->read_index + g_push_inbox_ctxt->curr_index;
            g_push_inbox_ctxt->curr_index = 0;
            mmi_wap_push_notify_category();
        }
        else if (g_push_inbox_ctxt->inbox_state == SRV_WAP_PUSH_INBOX_NEED_REFRESH)
        {
            mmi_wap_push_notify_category();
        }
        else if (g_push_inbox_ctxt->inbox_state == SRV_WAP_PUSH_INBOX_STATE_IDLE) 
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_PROCESSING)
            {
                g_push_inbox_ctxt->end_index = g_push_inbox_ctxt->curr_index - 1;
                g_push_inbox_ctxt->curr_index = 0;
                g_push_inbox_ctxt->inbox_state = SRV_WAP_PUSH_INBOX_LIST_READY;
                mmi_wap_push_setting_entry_service_inbox ();
            }
            else if (mmi_wap_push_is_screen_present (SCR_ID_PUSH_PROCESSING))
            {
                // HistoryReplace (SCR_ID_PUSH_PROCESSING, SCR_ID_PUSH_INBOX, mmi_wap_push_setting_entry_service_inbox);
                mmi_frm_node_struct new_node;
                new_node.id= SCR_ID_PUSH_INBOX;
                new_node.entry_proc= (mmi_proc_func)mmi_wap_push_setting_entry_service_inbox;
                new_node.user_data=NULL;
                mmi_frm_scrn_replace( GRP_ID_WAP_PUSH_SERVICE_MSG_MAIN, SCR_ID_PUSH_PROCESSING ,&new_node);
            }
        }
        else
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_PROCESSING)
            {
               // ClearExitHandler();
                mmi_frm_scrn_close_active_id ();
            }
            else if (mmi_wap_push_is_screen_present (SCR_ID_PUSH_PROCESSING))
            {
                //DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);
                mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_PROCESSING);
                mmi_brw_push_pre_entry_inbox_validation ();
            }            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_display_inbox
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_display_inbox (S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = SRV_WAP_PUSH_TOTAL_PUSH_LIST;
    U16 cntr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NEED_TO_DISPLAY_INBOX_FOR, num);
    g_push_inbox_ctxt->num_of_messages = num;

    if ((mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_PROCESSING) || mmi_wap_push_is_screen_present (SCR_ID_PUSH_PROCESSING))
    {
        if (!g_push_inbox_ctxt->num_of_messages)
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_PROCESSING)
            {
                mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_EMPTY);
            }
            //mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_PROCESSING);
            mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_PROCESSING);
            return;
        }
        else
        {
            if (g_push_inbox_ctxt->num_of_messages <= SRV_WAP_PUSH_TOTAL_PUSH_LIST)
            {
                count = g_push_inbox_ctxt->num_of_messages;
            }
            for (cntr = 0; cntr < count; cntr++)
            {
                memset (&g_push_inbox_ctxt->list_item[cntr], 0, sizeof (pmg_msg_list_struct));
            }
            srv_wap_push_get_list_from_service_layer (g_push_inbox_ctxt->curr_index, 
				count,
				PUSH_MSG_LIST_INBOX_DSPLY_TRANS_ID, 
				WAP_PMG_PARAM_NOT_SPECIFIED);
        }
    } 
    else
    {
        /* User press back or End key */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_display_progressing_screen
 * DESCRIPTION
 *  Display please wait screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_display_progressing_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_scrhdlr_entry_inbox_processing();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_pre_entry_inbox_validation
 * DESCRIPTION
 * This API display the service message inbox to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_pre_entry_inbox_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_push_delete_previous_instance_of_push();
    g_push_inbox_ctxt->start_index = 0;
    g_push_inbox_ctxt->end_index = 0;
    g_push_inbox_ctxt->curr_index = 0;
    g_push_inbox_ctxt->sel_idx = 0;
    g_push_inbox_ctxt->inbox_state = SRV_WAP_PUSH_INBOX_STATE_IDLE;
    mmi_wap_push_display_progressing_screen ();

    srv_wap_push_get_msg_count (WAP_PMG_PARAM_NOT_SPECIFIED, PUSH_DISPLAY_INBOX_COUNT_TRANS_ID);
}

mmi_ret mmi_push_message_display_group_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
        case EVT_ID_GROUP_FOCUSED:
            g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_BODY;
        break;
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            mmi_frm_group_close (GRP_ID_BRW_PUSH_BODY);
            break;
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
        case EVT_ID_CUI_BKM_ADD_BKM_CLOSE:
            cui_bkm_add_bkm_close (((cui_bkm_add_bkm_result_evt_struct*)evt)->sender_id);
            break;
#endif
        default:
            {
				mmi_wap_push_send_proc_default(evt);
            }
            break;

    }

    return MMI_RET_OK;
}
void mmi_wap_push_scrhdlr_entry_message_display_group (MMI_ID caller_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_BRW_PUSH_BODY))
    {
        mmi_frm_group_create(caller_grp_id, GRP_ID_BRW_PUSH_BODY, mmi_push_message_display_group_proc, NULL);
       // mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BRW_PUSH_BODY, mmi_push_message_display_group_proc, NULL);
        mmi_frm_group_enter(GRP_ID_BRW_PUSH_BODY, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        //mmi_frm_group_set_caller (GRP_ID_BRW_PUSH_BODY, caller_grp_id);
        g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_BODY;
    }
    

    mmi_wap_push_scrhdlr_entry_message_display();
	
}


mmi_ret mmi_push_inbox_group_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
        case EVT_ID_GROUP_FOCUSED:
            g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_INBOX;
        break;
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            mmi_frm_group_close (GRP_ID_BRW_PUSH_INBOX);
            //g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        default:
            {
    			mmi_wap_push_send_proc_default(evt);
            }
            break;

    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_open_service_inbox
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_brw_push_open_service_inbox (U16 title_icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BRW_PUSH_INBOX, mmi_push_inbox_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_BRW_PUSH_INBOX, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //mmi_frm_group_set_caller (GRP_ID_BRW_PUSH_INBOX, /*browser grp id*/);
    g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_INBOX;

    g_push_inbox_ctxt->title_icon_id = title_icon_id;
    mmi_brw_push_pre_entry_inbox_validation();   /* start screen */

    return GRP_ID_BRW_PUSH_INBOX;           /* return gid */


    //g_push_inbox_ctxt->title_icon_id = title_icon_id;
    //mmi_brw_push_pre_entry_inbox_validation();
}

/************************************************************************************************/
/******************************* END inbox related functions definations ************************/
/************************************************************************************************/




/************************************************************************************************/
/******************** Start of service dialogue request related functions ***********************/
/************************************************************************************************/
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
void mmi_wap_push_unknown_sia_req_common()
  {
	OslMfree(g_srv_wap_push_cntxt->curr_dlg);
	g_srv_wap_push_cntxt->curr_dlg = NULL;


    #ifdef __MMI_NCENTER_SUPPORT__
	vsrv_ncenter_close_notification(nhandle_dlg);
    nshow=MMI_TRUE;
	if(g_srv_wap_push_cntxt->dlg_front)
				{		
					srv_wap_push_get_dlg_data_req(g_srv_wap_push_cntxt->dlg_front->trans_id);
				 } 
    #endif
}
#endif
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_accept_and_add_wl_unknwn_addr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_accept_and_add_wl_unknwn_addr_req(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ACCEPT_ADD_UNKNWN_ADDR);
	//mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_DISPALY_SIA_CNF);
	srv_wap_push_send_unknwn_addr_cnf(TRUE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
	srv_wap_push_add_unknwn_addr_to_list(SRV_WAP_PUSH_WHITE_LIST);
	//mmi_frm_scrn_close_active_id();
    mmi_frm_group_close (GRP_ID_BRW_PUSH_FROM_IDLE);
	mmi_wap_push_unknown_sia_req_common();
    #ifdef __MMI_NCENTER_SUPPORT__
        if(g_push_cntxt->inline_gid != GRP_ID_INVALID)
            {
				mmi_frm_group_close(GRP_ID_BRW_PUSH_SETTING_LIST);
            }  
    #endif
}


#ifdef __MMI_WAP_PUSH_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_reject_and_add_bl_unknwn_addr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_reject_and_add_bl_unknwn_addr_req(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_REJECT_ADD_UNKNWN_ADDR);
	//mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_DISPALY_SIA_CNF);
	srv_wap_push_send_unknwn_addr_cnf(FALSE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
	srv_wap_push_add_unknwn_addr_to_list(SRV_WAP_PUSH_BLACK_LIST);


	//mmi_frm_scrn_close_active_id();
    mmi_frm_group_close (GRP_ID_BRW_PUSH_FROM_IDLE);
	mmi_wap_push_unknown_sia_req_common();
     #ifdef __MMI_NCENTER_SUPPORT__
      	if(g_push_cntxt->inline_gid != GRP_ID_INVALID)
            {
				mmi_frm_group_close(GRP_ID_BRW_PUSH_SETTING_LIST);
             }  
    #endif
}
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_reject_unknwn_addr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_reject_unknwn_addr_req(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_REJECT_UNKNWN_ADDR);
	//mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_DISPALY_SIA_CNF);
	srv_wap_push_send_unknwn_addr_cnf(FALSE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
	//mmi_frm_scrn_close_active_id();
    mmi_frm_group_close (GRP_ID_BRW_PUSH_FROM_IDLE);
	mmi_wap_push_unknown_sia_req_common();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_accept_unknwn_addr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_accept_unknwn_addr_req(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ACCEPT_UNKNWN_ADDR);
	//mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_DISPALY_SIA_CNF);
	srv_wap_push_send_unknwn_addr_cnf(TRUE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
	//mmi_frm_scrn_close_active_id();
    mmi_frm_group_close (GRP_ID_BRW_PUSH_FROM_IDLE);
	mmi_wap_push_unknown_sia_req_common();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_go_back_unknwn_addr_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_go_back_unknwn_addr_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_GO_BACK_UNKNWN_ADDR);
	srv_wap_push_send_unknwn_addr_cnf(FALSE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
    mmi_frm_group_close (GRP_ID_BRW_PUSH_FROM_IDLE);
	//mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_DISPALY_SIA_CNF);
	//mmi_frm_scrn_close_active_id();
	mmi_wap_push_unknown_sia_req_common();

}



#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifndef __MMI_WAP_PUSH_SIA_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_go_back_sia_req_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_go_back_sia_req_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_REJECT_SIA);
	srv_wap_push_send_sia_cnf(FALSE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.sia.trans_id);
	mmi_frm_scrn_close_active_id();
	mmi_wap_push_unknown_sia_req_common();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_sia_req_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_sia_req_accept(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ACCEPT_SIA);
	srv_wap_push_send_sia_cnf(TRUE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.sia.trans_id);
	mmi_frm_scrn_close_active_id();
	mmi_wap_push_unknown_sia_req_common();

}
#endif



/************************************************************************************************/
/********************* END of service dialogue request related functions ************************/
/************************************************************************************************/





/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_process_delete_all_msg_rsp
 * DESCRIPTION
 * Delete All response from service layer. 
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_process_delete_all_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_delete_all_cnf_struct *delete_all_data = (wps_pmg_delete_all_cnf_struct*) msg;
    S16 num = (S16) g_push_inbox_ctxt->num_of_messages;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HDL_PMG_DEL_ALL_RSP, delete_all_data->status);
    srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    if (delete_all_data->status == WAP_PMG_STATUS_OK)
    {
        if (delete_all_data->trans_id == PUSH_DELETE_ALL_FROM_MESSAGE_OPTIONS)
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
            {
                mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED, STR_GLOBAL_DELETED);
            }
            //DeleteScreenIfPresent(SCR_ID_PUSH_GENERIC_PROCESSING);
            mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);

            mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE);
            mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
            mmi_wap_push_update_inbox_selected_index ((S16)(-num));
        }
    #ifdef __DM_LAWMO_SUPPORT__
        else if (delete_all_data->trans_id == PUSH_DELETE_ALL_FOR_LAWMO)
        {
            srv_wap_push_handle_del_all_rsp_for_lawmo(MMI_TRUE);
        }
    #endif /* __DM_LAWMO_SUPPORT__ */
    }
    else
    {
    #ifdef __DM_LAWMO_SUPPORT__
        if (delete_all_data->trans_id == PUSH_DELETE_ALL_FOR_LAWMO)
        {
            srv_wap_push_handle_del_all_rsp_for_lawmo(MMI_FALSE);
        }
    #endif /* __DM_LAWMO_SUPPORT__ */
		if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
		{
            mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_ERROR);
			//DeleteScreenIfPresent(SCR_ID_PUSH_GENERIC_PROCESSING);
            mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
		}
		else
		{
			//DeleteScreenIfPresent(SCR_ID_PUSH_GENERIC_PROCESSING);
            mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_process_delete_msg_rsp
 * DESCRIPTION
 *  Delete message response from service layer.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_process_delete_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_delete_msg_cnf_struct *delete_msg_rsp = (wps_pmg_delete_msg_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HDL_PMG_DEL_RSP, delete_msg_rsp->trans_id, delete_msg_rsp->status);
    srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
	switch (delete_msg_rsp->trans_id)
	{
	case PUSH_DEL_MESSAGE_GENERIC_TRANS_ID:
		if (delete_msg_rsp->status == WAP_PMG_STATUS_OK)
		{
		#ifdef __MMI_PUSH_IN_UM__
			srv_wap_push_send_um_refresh_ind(delete_msg_rsp->msg_id,SRV_UM_REFRESH_MSG_DELETED,NULL);
		#endif
			if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
			{
            #if (!(defined __MMI_PUSH_IN_UM__) || !(defined __MMI_UM_ITERATOR_VIEWER__))
				mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED, STR_GLOBAL_DELETED);
				mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
                mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
                mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE);
            #else
        #ifdef __MMI_PUSH_IN_UM__
				mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED, STR_GLOBAL_DELETED);
				mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
            if (!mmi_wap_push_launch_next_viewer())
            {
                if (!mmi_wap_push_launch_prev_viewer())
                {
						//mmi_wap_push_event_based_display_popup(MMI_WAP_PUSH_EVENT_EXPLICITLY_DELETED, STR_GLOBAL_DELETED);
                }
            }

            mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
            mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE);
        #endif /* __MMI_PUSH_IN_UM__ */
            #endif /* __MMI_UM_ITERATOR_VIEWER__ */
			}
		}
		else
		{
			if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
			{
                mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_ERROR);
			}

            mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
            mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE);
			mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
		}
		break;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_display_error_dlg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_display_error_dlg(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_pmg_error_dlg_struct *message = (wps_pmg_error_dlg_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, (U16)message->str_id);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_ui_init
 * DESCRIPTION
 * This API Initialize the inbox UI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_ui_init (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_inbox_ctxt = (srv_wap_push_msg_inbox_struct*) srv_wap_push_malloc(sizeof(srv_wap_push_msg_inbox_struct));
    if (g_push_inbox_ctxt == NULL)
    {
        ASSERT(0);
    }
    memset (g_push_inbox_ctxt, 0, sizeof(srv_wap_push_msg_inbox_struct));
    g_push_inbox_ctxt->title_icon_id = 0;

    SetProtocolEventHandler(mmi_wap_push_display_error_dlg, MSG_ID_WPS_PMG_ERROR_DLG_IND);
    SetProtocolEventHandler(mmi_wap_push_process_delete_msg_rsp, MSG_ID_WPS_PMG_DELETE_MSG_CNF);
    SetProtocolEventHandler(mmi_wap_push_process_delete_all_msg_rsp, MSG_ID_WPS_PMG_DELETE_ALL_CNF);
}










/**********************************************************************************************************/
/*                                       Unified push code started                                        */
#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_hide_handler_send_by
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_hide_handler_send_by (void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
        
        #if defined (__FLIGHT_MODE_SUPPORT__)
        (!srv_mode_switch_is_network_service_available()) ||
        #endif 
        (!srv_sim_ctrl_get_one_available_sim()))
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_FALSE, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY_SMS, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY, 
            gui_buffer, 
            SCR_ID_BRW_SEND_BY_OPTIONS);

        /* mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_SMS); */
    }
    else
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_TRUE, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY_SMS, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY, 
            gui_buffer, 
            SCR_ID_BRW_SEND_BY_OPTIONS);

        /* mmi_frm_unhide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_SMS); */
    }

#if defined(MMS_SUPPORT)
    if (!mms_is_ready())
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_FALSE, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY, 
            gui_buffer, 
            SCR_ID_BRW_SEND_BY_OPTIONS);
        /* mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS); */
    }
    else
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_TRUE, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY, 
            gui_buffer, 
            SCR_ID_BRW_SEND_BY_OPTIONS);

        /* mmi_frm_unhide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS); */
    }
#else
    mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS);
#endif /* defined(MMS_SUPPORT) */ 

#if  defined(__MMI_EMAIL__)
    if (!mmi_email_is_email_can_forward())
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_FALSE, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY, 
            gui_buffer, 
            SCR_ID_BRW_SEND_BY_OPTIONS);

        /* mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL);  */
    }
    else
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_TRUE, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY, 
            gui_buffer, 
            SCR_ID_BRW_SEND_BY_OPTIONS);

        /* mmi_frm_unhide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL); */
    }
#else
    mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL);
#endif /* __MMI_EMAIL__ */ 
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_hide_handler_message_option
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_hide_handler_message_option (void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Hiding delete all option from UM and IDLE */
    if (!mmi_wap_push_is_screen_present (SCR_ID_PUSH_INBOX))
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_FALSE, 
            MENU_ID_PUSH_SERVICE_MSG_DELETE_ALL, 
            MENU_ID_PUSH_MSG_OPTION, 
            gui_buffer, 
            SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);

        /* mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_DELETE_ALL); */
    }
    else
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_TRUE, 
            MENU_ID_PUSH_SERVICE_MSG_DELETE_ALL, 
            MENU_ID_PUSH_MSG_OPTION, 
            gui_buffer, 
            SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);

        /* mmi_frm_unhide_menu_item(MENU_ID_PUSH_SERVICE_MSG_DELETE_ALL); */
    }
#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
    /* Hiding Send by option */
    if (!mmi_wap_push_hide_send_by())
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_FALSE, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY, 
            MENU_ID_PUSH_MSG_OPTION, 
            gui_buffer, 
            SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);

        /* mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY); */
    }
    else
    {
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_TRUE, 
            MENU_ID_PUSH_SERVICE_MSG_SEND_BY, 
            MENU_ID_PUSH_MSG_OPTION, 
            gui_buffer, 
            SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);

        /* mmi_frm_unhide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY); */
    }
#endif
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
#if (MMI_MAX_SIM_NUM == 2)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WAP_DUAL_SIM__ */
/* under construction !*/
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_hide_handler_unknwn_addr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_hide_handler_unknwn_addr (void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
	if(g_push_set_p->general_set.enable_white_list == WAP_PMG_WL_DISABLED)
	{
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_FALSE, 
            MENU_ID_PUSH_UNKNOWN_ADDR_ACCEPT_AND_ADD_TO_WL, 
            MENU_ID_PUSH_UNKNOWN_ADDR_OPTIONS, 
            gui_buffer, 
            SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS);

		/* mmi_frm_hide_menu_item(MENU_ID_PUSH_UNKNOWN_ADDR_ACCEPT_AND_ADD_TO_WL); */
	}
	else
	{
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_TRUE, 
            MENU_ID_PUSH_UNKNOWN_ADDR_ACCEPT_AND_ADD_TO_WL, 
            MENU_ID_PUSH_UNKNOWN_ADDR_OPTIONS, 
            gui_buffer, 
            SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS);

		/* mmi_frm_unhide_menu_item(MENU_ID_PUSH_UNKNOWN_ADDR_ACCEPT_AND_ADD_TO_WL); */
	}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
	if(g_push_set_p->general_set.enable_black_list == WAP_PMG_BL_DISABLED)
	{
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_FALSE, 
            MENU_ID_PUSH_UNKNOWN_ADDR_REJECT_AND_ADD_TO_BL, 
            MENU_ID_PUSH_UNKNOWN_ADDR_OPTIONS, 
            gui_buffer, 
            SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS);

		/* mmi_frm_hide_menu_item(MENU_ID_PUSH_UNKNOWN_ADDR_REJECT_AND_ADD_TO_BL); */
	}
	else
	{
        mmi_wap_push_adjust_hide_highlight_menu_item(
            MMI_TRUE, 
            MENU_ID_PUSH_UNKNOWN_ADDR_REJECT_AND_ADD_TO_BL, 
            MENU_ID_PUSH_UNKNOWN_ADDR_OPTIONS, 
            gui_buffer, 
            SCR_ID_PUSH_UNKNWN_ADDR_OPTIONS);

		/* mmi_frm_unhide_menu_item(MENU_ID_PUSH_UNKNOWN_ADDR_REJECT_AND_ADD_TO_BL); */
	}
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
}


/**********************************************************************************************************/
/*                                       Unified push code Ends                                           */
/**********************************************************************************************************/






/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_delete_push_screens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_delete_push_screens (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_PROCESSING);
    mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE);
    mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
    mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
    mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_SEND_BY_OPTIONS);
    mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_POPUP_SCREEN);
    mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_PUSH_CONNECT_SIM_OPTIONS);
    mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_PUSH_MSG_DELETED);
    mmi_ime_delete_editor_common_scr(SCR_ID_BRW_PUSH_ADD_BOOKMARK);
    mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_PUSH_ADD_BOOKMARK);

    mmi_frm_group_close(GRP_ID_BRW_PUSH_BODY);
    mmi_frm_group_close(GRP_ID_BRW_PUSH_FROM_IDLE);
    mmi_frm_group_close(GRP_ID_BRW_PUSH_POPUP);
    mmi_frm_group_close(GRP_ID_BRW_PUSH_INLINE);
    mmi_frm_group_close(GRP_ID_BRW_PUSH_POPUP_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_previous_instance_of_push
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_previous_instance_of_push (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_delete_push_screens();
    mmi_wap_push_delete_previous_push_setting_instance_if_present();
    //DeleteScreenIfPresent(SCR_ID_PUSH_ASYNC_PROCESSING);
    mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_ASYNC_PROCESSING);
    mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_INBOX);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_exit_new_msg_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_exit_new_msg_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_push_cntxt->is_popup_scr_active = MMI_FALSE;
    mmi_frm_end_scenario(MMI_SCENARIO_ID_WAP_PUSH);
    /*
    if (g_push_cntxt->popup_tone)
    {
        stopRequestedTone(g_push_cntxt->popup_tone);
    }
    GoBackSubLCDHistory();	
    */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_is_new_msg_popup_scr_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if POPUP screen is active.
 *****************************************************************************/
MMI_BOOL mmi_brw_push_is_new_msg_popup_scr_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((g_push_cntxt->is_popup_scr_active == MMI_TRUE) && (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_POPUP_SCREEN))
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_display_new_msg_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_id      [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_display_new_msg_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntxt->msg_str_id = str_id;
    evt_type = MMI_EVENT_MMS;
#if	defined(__OP01__) || defined(__OP02__)
	if ( 
             #ifdef __MMI_WAP_PUSH_WHITE_LIST__
            (str_id == STR_ID_PUSH_NEW_UNKNOWN_MSG) || 
             #endif
            (str_id == STR_ID_BRW_NEW_PUSH_MESSAGE) 
          )
	{
		evt_type = MMI_EVENT_UNKNOWN_WAP_PUSH;
	}
#endif
   // mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_WAP_PUSH, evt_type, (WCHAR *)GetString (str_id));
          {
        WCHAR preview_text[100];
        mmi_frm_nmgr_alert_struct alert_info;
        memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   
        /*fill in app id for NSS query*/
        alert_info.app_id = APP_MMI_WAP_PUSH; //your app id
        /*fill in the basic info*/
        alert_info.scen_id = MMI_SCENARIO_ID_WAP_PUSH; // your scenario ID
        alert_info.event_type = evt_type; // your event id
        mmi_ucs2cpy((CHAR *)preview_text, (const CHAR *)GetString(str_id));
        alert_info.status_bar_para.display_string = preview_text; /* fill text preview data */
         alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
         alert_info.status_bar_para.image.id = IMG_SI_WAP;
      #ifdef __MMI_PUSH_IN_UM__
        mmi_um_alert_um_inbox_alert(&alert_info);
      #else
		{
            WCHAR popup_text[100];
			 alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
             alert_info.behavior_mask = PREFER_STATUS_BAR; 
             alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;

		/*fill in the popup information*/    
	     alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;

            
            mmi_wsprintf(
                popup_text, 
                100, 
                STR_ID_WAP_PUSH_UNREAD_MSG_NUMBER_ID, 
                g_srv_wap_push_cntxt->unread_msgs_count);


        alert_info.popup_para.popup_string =popup_text ;
        alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);

        alert_info.app_proc_para.scrn_group_proc= &mmi_wap_push_nss_unread_popup;
        alert_info.app_proc_para.user_data = NULL;	
        alert_info.app_proc_para.data_size = 0;
        mmi_frm_nmgr_alert(&alert_info); 

		}
   #endif
       } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_is_push_screen_active
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  True if any push related screen is active or in history otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_wap_push_is_push_screen_active (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 act_scr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    act_scr = mmi_frm_scrn_get_active_id();
    if ((SCR_ID_PUSH_INBOX == act_scr)||
        (mmi_wap_push_is_screen_present(SCR_ID_PUSH_INBOX)) ||
        (mmi_wap_push_is_screen_present(SCR_ID_BRW_READ_SERVICE_MESSAGE))||
        (act_scr == SCR_ID_BRW_READ_SERVICE_MESSAGE)
        )
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


void mmi_wap_push_handle_deleted_on_keypad_locked (void)
{
    if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_NEW_PUSH_MESSAGE_IND) /* When keypad is locked and message got deleted by server*/
    {
        mmi_frm_scrn_close_active_id();
    }
}

#if 0
#if (MMI_MAX_SIM_NUM == 2)
#ifdef BROWSER_SUPPORT
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
#if (MMI_MAX_SIM_NUM == 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_WAP_DUAL_SIM__ */
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
#endif /* BROWSER_SUPPORT */
#endif /* __MMI_WAP_DUAL_SIM__ */
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_load_service_message_url
 * DESCRIPTION
 *  This function Launch the service message.
 * PARAMETERS
 *  url         [IN]
 *  sim_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_load_service_message_url (U8 *url, U32 sim_id, U16 message_type, U32 message_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U16 size=0;
        S8 *ucs2_url;
         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
       size=strlen((S8*)url);
       ucs2_url=(S8*)OslMalloc((size+1)*ENCODING_LENGTH);
       
	mmi_asc_to_ucs2 ((S8*)ucs2_url, (S8*)url);
        #ifdef BROWSER_SUPPORT
	wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)ucs2_url);
        #endif /* BROWSER_SUPPORT */
        OslMfree(ucs2_url);
#ifdef  __MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT__
    if (message_type == WAP_PMG_MSGTYPE_SL)
    {
        srv_wap_push_send_del_req_to_pmg (message_id, PUSH_DEL_SL_AFTER_LOAD_TRANS_ID);
        mmi_wap_push_update_inbox_selected_index (-1);
        mmi_wap_push_delete_push_screens();
    }
#else
    if (message_type == WAP_PMG_MSGTYPE_SL)
    {
        srv_wap_push_update_service_msg_req(message_id);
        srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    }
#endif /* __MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT__ */
	return;
}

#if 0
#ifdef __MMI_OP12_TOOLBAR__
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
#endif /* __MMI_OP12_TOOLBAR__ */
/* under construction !*/
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_delete_all_from_msg_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_delete_all_from_msg_option (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_event_based_confirm (
        STR_ID_PUSH_DELETE_ALL_INBOX_MSG,
        srv_wap_push_delete_all_messages,
        mmi_push_close_active_screen,
		NULL);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_delete_selected_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_delete_selected_msg (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_message_generic (g_srv_wap_push_cntxt->selected_message.msg_id);
    mmi_wap_push_update_inbox_selected_index (0);
    if (g_push_inbox_ctxt->num_of_messages > 0)
    {
        g_push_inbox_ctxt->num_of_messages--;
    }
	  #ifdef __MMI_NCENTER_SUPPORT__
             #ifdef __MMI_PUSH_IN_MSG__
                mmi_wap_push_ncenter_unread_messages();
              #endif
       #endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_delete_from_msg_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_delete_from_msg_option (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_event_based_confirm (
        STR_ID_BRW_PUSH_DELETE_CONFIRM,
        mmi_wap_push_delete_selected_msg,
        mmi_push_close_active_screen,
		mmi_wap_push_delete_selected_msg);
}

#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__  
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_add_to_bookmark_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_add_to_bookmark_list (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_ADD_TO_BKM);
    mmi_wap_push_pre_entry_add_bookmark (NULL, g_srv_wap_push_cntxt->selected_message.url);
}

#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_push_close_push_inbox_screens
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE.
 *****************************************************************************/
MMI_BOOL mmi_push_close_push_inbox_screens (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_push_delete_previous_instance_of_push();
    return MMI_TRUE;
}



#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_add_to_validation_list_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_add_to_validation_list_confirm (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 ascii_addr[NVRAM_PUSH_SENDER_ADDR_LEN_MAX] = {'\0',};
	S8 sep[2] = {WAP_PMG_ADDR_PHONE_SEP,'\0'};
    pBOOL dup = FALSE;
    srv_wap_push_selected_msg_struct *temp = &(g_srv_wap_push_cntxt->selected_message);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

	switch (temp->from.addr_type)
	{
	case WAP_PMG_ADDR_PHONE:
		strcpy((S8*) ascii_addr, (S8*) temp->from.addr);
		strcat((S8*)ascii_addr,(S8*)sep);
		strcat((S8*) ascii_addr, (S8*) temp->smsc.addr);
		strcat((S8*)ascii_addr,(S8*)sep);
		break;
	case WAP_PMG_ADDR_IP:
		strcat((S8*) ascii_addr, (S8*) temp->from.addr);
		break;
	default:
		break;
	}

    dup = srv_wap_push_check_duplicate_entry(
    (U16)g_srv_wap_push_cntxt->add_list_type, 
    temp->from.addr_type, 
    ascii_addr);
    if(dup)
    {
		mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_ID_PUSH_SAME_ITEM_EXIST);
		return;
    }
    if (g_srv_wap_push_cntxt->add_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        if(g_push_set_p->total_wl_entry >= NVRAM_PUSH_MAX_NUM_WHITE_LIST)
        {
            mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_ID_PUSH_TRUST_LIST_FULL);
		    return;
        }
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        if(g_push_set_p->total_bl_entry >= NVRAM_PUSH_MAX_NUM_BLACK_LIST)
        {
            mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_ID_PUSH_BLACK_LIST_FULL);
		    return;
        }
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

    mmi_wap_push_event_based_confirm (
        STR_ID_BRW_PUSH_CONFIRM_LIST_MODIFY,
        srv_wap_push_add_to_validation_list,
        mmi_push_close_active_screen,
		srv_wap_push_add_to_validation_list);
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_load_selected_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_load_selected_message (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_LOAD_URL);
    mmi_wap_push_load_service_message_url (
        (U8*)g_srv_wap_push_cntxt->selected_message.url,
        g_srv_wap_push_cntxt->selected_message.sim_id,
        g_srv_wap_push_cntxt->selected_message.msg_type,
        g_srv_wap_push_cntxt->selected_message.msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_launch_selected_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_launch_selected_message (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_srv_wap_push_cntxt->selected_message.expired) && 
        (g_srv_wap_push_cntxt->selected_message.expired <= (U32) srv_wap_push_get_current_utc_time()))
    {
        mmi_wap_push_event_based_confirm (
            STR_ID_BRW_PUSH_MESSAGE_EXPIRED,
            mmi_wap_push_load_selected_message,
            mmi_push_close_active_screen,
			mmi_wap_push_load_selected_message);
    }
    else
    {
    #ifdef __MMI_BRW_PUSH_CONNECT_CONF__
        mmi_wap_push_event_based_confirm (
            STR_ID_PUSH_CONNECT_ASK,
            mmi_wap_push_load_selected_message,
            mmi_push_close_active_screen,
			mmi_wap_push_load_selected_message);
    #else /* __MMI_BRW_PUSH_CONNECT_CONF__ */
        mmi_wap_push_load_selected_message();
    #endif /* __MMI_BRW_PUSH_CONNECT_CONF__ */
    }
}



/***********************************  STARTED DEFINATION OF HIGHLIGHT HANDLERS *****************************************/


/***********************************  END OF DEFINATION OF HIGHLIGHT HANDLERS ******************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_if_draw_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  screen_id      [U16]
 * RETURNS
 *  void.
 *****************************************************************************/
srv_wap_push_result_enum mmi_wap_push_if_draw_screen(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_set_cntrlr_DB_id(scr_id);
    mmi_wap_push_set_scrhdlr_DB_id(scr_id);
    mmi_wap_push_set_rc_DB_id(scr_id);

    return mmi_wap_push_invoke_cntrlr(scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_start_msg_sub_anm
 * DESCRIPTION
 *  Start sub-LCD msg animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_start_msg_sub_anm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
    {
        ExecSubLCDCurrExitHandler();
        if (GetMessagesCurrScrnID() == SCR_ID_MSG_MSG_WAITING_IND)
        {
            ShowCategory304Screen(IMG_NEW_VOICEMAIL_PIC_SUBLCD_MSG, NULL);
        }
        else
        {
            ShowCategory304Screen(IMG_NEW_SMS_PIC_SUBLCD_MSG, NULL);
        }
        SetSubLCDExitHandler(mmi_msg_callback_msg_sub_anm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_confirm_delete_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_confirm_delete_list(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_event_based_confirm (
        STR_ID_BRW_PUSH_DELETE_CONFIRM,
        srv_wap_push_delete_list_entry,
        mmi_push_close_active_screen,
		srv_wap_push_delete_list_entry);
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_modify_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_modify_pre_entry(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rec_index = 0;
    U16 index = 0;
    nvram_push_addr_struct *curr_item = NULL;
    S8 ascii_sender[MAX_PUSH_PHN_NUM_LEN] = { '\0', };
    S8 ascii_smsc[MAX_PUSH_PHN_NUM_LEN] = { '\0', };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_EDIT;
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
    {
        srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_wl_entry);
        curr_item = &g_push_set_p->white_list[rec_index].white_list[index];
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    else
    {
        srv_wap_push_get_record_and_index(&rec_index, &index, g_push_set_p->selected_bl_entry);
        curr_item = &g_push_set_p->black_list[rec_index].black_list[index];
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    if (curr_item->addr_type == SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER)
    {
        srv_wap_push_parse_ph_num(ascii_sender, ascii_smsc, (S8*) curr_item->addr);
        mmi_asc_to_ucs2(g_push_set_p->smsc_address, ascii_smsc);
        mmi_asc_to_ucs2(g_push_set_p->sender_address, ascii_sender);
        if (mmi_frm_group_is_present(GRP_ID_BRW_PUSH_INLINE))
            ASSERT(0);

        mmi_frm_group_create(g_push_cntxt->scr_grp_id, GRP_ID_BRW_PUSH_INLINE, mmi_wap_push_inline_group_proc, NULL);
        mmi_frm_group_enter(GRP_ID_BRW_PUSH_INLINE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_wap_push_scrhdlr_entry_add_new_ph_num();
    }
    else
    {
        strcpy(g_push_set_p->ip_addr, (S8*) curr_item->addr);
        if (mmi_frm_group_is_present(GRP_ID_BRW_PUSH_INLINE))
            ASSERT(0);

        mmi_frm_group_create(g_push_cntxt->scr_grp_id, GRP_ID_BRW_PUSH_INLINE, mmi_wap_push_inline_group_proc, NULL);
        mmi_frm_group_enter(GRP_ID_BRW_PUSH_INLINE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_wap_push_scrhdlr_entry_add_new_ip();
    }
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


mmi_ret mmi_wap_push_inline_group_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wap_push_screenDB_struct *scrDB = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   scrDB = (mmi_wap_push_screenDB_struct *)evt->user_data;
   switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
            //g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_INBOX;
        break;
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
			if (scrDB && (NULL != scrDB->screen))
            {
                OslMfree(scrDB->screen);
            }
            scrDB->screen = NULL;
            mmi_frm_group_close (GRP_ID_BRW_PUSH_INLINE);
            //g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
    /* Add code for  event which  you want to handle.  */
        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        {
            /* Do something you want */
            cui_inline_close(g_push_cntxt->inline_gid);
            g_push_cntxt->inline_gid = GRP_ID_INVALID;
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            /* Do something you want */
            cui_inline_close(g_push_cntxt->inline_gid);
            g_push_cntxt->inline_gid = GRP_ID_INVALID;
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        { 
        #ifdef __MMI_WAP_PUSH_WHITE_LIST__
            if (scrDB && (scrDB->scrn_id == SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM))
            {
                cui_inline_get_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_PH_NUM_SENDER_EDIT, (void *)g_push_set_p->sender_address);
                cui_inline_get_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_PH_NUM_SMSC_EDIT, (void *)g_push_set_p->smsc_address);
                mmi_wap_push_confirm_modify_add_trust_list();
            }
            else if (scrDB && (scrDB->scrn_id == SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR))
            {
                cui_inline_item_ip4_struct temp_data;
                cui_inline_get_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_IP_NUM_EDIT, (void *)(&temp_data));
                /*
                g_push_set_p->IP1 = temp_data.b1;
                g_push_set_p->IP2 = temp_data.b2;
                g_push_set_p->IP3 = temp_data.b3;
                g_push_set_p->IP4 = temp_data.b4;
                */
                ReturnThreeDigitString((U8*) g_push_set_p->IP1, (U8) temp_data.b1);
                ReturnThreeDigitString((U8*) g_push_set_p->IP2, (U8) temp_data.b2);
                ReturnThreeDigitString((U8*) g_push_set_p->IP3, (U8) temp_data.b3);
                ReturnThreeDigitString((U8*) g_push_set_p->IP4, (U8) temp_data.b4);

                mmi_wap_push_confirm_ip_add_modify();

            }
        #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
            /* Do something you want */
            if (scrDB && (NULL != scrDB->screen))
            {
                OslMfree(scrDB->screen);
            }
            scrDB->screen = NULL;

            //cui_inline_close(g_push_cntxt->inline_gid);
            //g_push_cntxt->inline_gid = GRP_ID_INVALID;
            break;
        }

      case EVT_ID_CUI_INLINE_CSK_PRESS:
          { 
             #ifdef __MMI_WAP_PUSH_WHITE_LIST__
     //       if (scrDB && (scrDB->scrn_id == SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM))
        //    {
         //       cui_inline_get_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_PH_NUM_SENDER_EDIT, (void *)g_push_set_p->sender_address);
         //       cui_inline_get_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_PH_NUM_SMSC_EDIT, (void *)g_push_set_p->smsc_address);
         //       mmi_wap_push_confirm_modify_add_trust_list();
         //   }
       //     else
                if (scrDB && (scrDB->scrn_id == SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR))
            {
                cui_inline_item_ip4_struct temp_data;
                cui_inline_get_value(g_push_cntxt->inline_gid, MMI_BRW_PUSH_IP_NUM_EDIT, (void *)(&temp_data));
                /*
                g_push_set_p->IP1 = temp_data.b1;
                g_push_set_p->IP2 = temp_data.b2;
                g_push_set_p->IP3 = temp_data.b3;
                g_push_set_p->IP4 = temp_data.b4;
                */
                ReturnThreeDigitString((U8*) g_push_set_p->IP1, (U8) temp_data.b1);
                ReturnThreeDigitString((U8*) g_push_set_p->IP2, (U8) temp_data.b2);
                ReturnThreeDigitString((U8*) g_push_set_p->IP3, (U8) temp_data.b3);
                ReturnThreeDigitString((U8*) g_push_set_p->IP4, (U8) temp_data.b4);

                mmi_wap_push_confirm_ip_add_modify();

            }
        #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
            /* Do something you want */
            if (scrDB && (NULL != scrDB->screen))
            {
                OslMfree(scrDB->screen);
            }
            scrDB->screen = NULL;

            //cui_inline_close(g_push_cntxt->inline_gid);
            //g_push_cntxt->inline_gid = GRP_ID_INVALID;
            break;
        }

        default:
            break;

    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_add_new_ph_no_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_add_new_ph_no_pre_entry(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_BRW_PUSH_INLINE))
        ASSERT(0);

    mmi_frm_group_create(g_push_cntxt->scr_grp_id, GRP_ID_BRW_PUSH_INLINE, mmi_wap_push_inline_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_BRW_PUSH_INLINE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_ADD_NEW;
    memset(g_push_set_p->smsc_address, 0, sizeof(g_push_set_p->smsc_address));
    memset(g_push_set_p->sender_address, 0, sizeof(g_push_set_p->sender_address));
    mmi_wap_push_scrhdlr_entry_add_new_ph_num();
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_add_new_ip_addr_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_add_new_ip_addr_pre_entry(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (mmi_frm_group_is_present(GRP_ID_BRW_PUSH_INLINE))
        ASSERT(0);

    mmi_frm_group_create(g_push_cntxt->scr_grp_id, GRP_ID_BRW_PUSH_INLINE, mmi_wap_push_inline_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_BRW_PUSH_INLINE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
   g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_ADD_NEW;
    memset(g_push_set_p->ip_addr, 0, sizeof(g_push_set_p->ip_addr));
    mmi_wap_push_scrhdlr_entry_add_new_ip();
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_setting_confirm_delete_all_list_entry
 * DESCRIPTION
 *  This function confirm delete all selected list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_setting_confirm_delete_all_list_entry(void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_event_based_confirm (
        STR_ID_BRW_PUSH_DELETE_ALL_CONFIRM,
        srv_wap_push_setting_delete_all_list_entry,
        mmi_push_close_active_screen,
		srv_wap_push_setting_delete_all_list_entry);
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_delete_previous_push_setting_instance_if_present
 * DESCRIPTION
 *  Delete all the push related screens from the history if any is present.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_delete_previous_push_setting_instance_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    g_push_set_p->slected_opr_type = SRV_WAP_PUSH_OPR_TOTAL;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    if (mmi_wap_push_is_screen_present(SCR_ID_PUSH_SETTING))
    {
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_SETTING);
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_ENABLE_PUSH);
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_SL_SETTING);
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_ENABLE_WL_SETTING);
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_ENABLE_BL_SETTING);

        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_WHITE_LIST_ADD_NEW);
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_WHITE_LIST_ADD_NEW_PHONE_NUM);
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_WHITE_LIST_ADD_NEW_IP_ADDR);
    }
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    if (mmi_wap_push_is_screen_present(SCR_ID_PUSH_WHITE_LIST) || mmi_wap_push_is_screen_present(SCR_ID_PUSH_BLACK_LIST))
    {
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_WHITE_LIST);
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_BLACK_LIST);
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_WHITE_LIST_OPTIONS);
        if (g_push_set_p->slected_opr_type == SRV_WAP_PUSH_OPR_ADD_OTA)
        {
        #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
            srv_wap_push_ota_add_trustlist_result_callback(SRV_WAP_PUSH_ERROR_SCREEN_DELETED);
        #endif 
        }
    }
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    mmi_frm_group_close(GRP_ID_BRW_PUSH_SETTING);
    mmi_frm_group_close(GRP_ID_BRW_PUSH_SETTING_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_push_pre_entry_push_setting_ex
 * DESCRIPTION
 *  call mmi_push_pre_entry_push_setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_pre_entry_push_setting_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_push_pre_entry_push_setting();
}

mmi_ret mmi_push_setting_group_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
        case EVT_ID_GROUP_FOCUSED:
            g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_SETTING;
        break;
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            mmi_frm_group_close (GRP_ID_BRW_PUSH_SETTING);
            //g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        default:
             {
              mmi_wap_push_send_proc_default(evt);
            }
           break;

    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_push_pre_entry_push_setting
 * DESCRIPTION
 *  Pre entry to the service message setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_push_pre_entry_push_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_delete_previous_push_setting_instance_if_present();

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BRW_PUSH_SETTING, mmi_push_setting_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_BRW_PUSH_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    //mmi_frm_group_set_caller (GRP_ID_BRW_PUSH_SETTING, /*browser grp id*/);
    g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_SETTING;

    mmi_wap_push_setting_entry_main_menu();    /* start screen */

    return GRP_ID_BRW_PUSH_SETTING;           /* return gid */

    //mmi_wap_push_setting_entry_main_menu();
}


void mmi_push_open_service_message_setting (U16 title_icon_id)
{
    g_push_inbox_ctxt->title_icon_id = title_icon_id;
    mmi_push_pre_entry_push_setting();
}

/*****************************************************************************/
/******************  Start of UI Highlight handler registration **************/
/*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_enable_push_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 string id for enable push setting setting.
 *****************************************************************************/
U16 mmi_wap_push_get_enable_push_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_push_set_p->general_set.enable_push)
    {
        case WAP_PMG_RETR_ACCEPT_ALL:
            return STR_ID_PUSH_ENABLE_SETTING_ACCEPT_ALL;
            
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        case WAP_PMG_RETR_ACCEPT_AUTH_OR_TRUSTED:
            return STR_ID_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED;
            
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
        case WAP_PMG_RETR_DISABLED:
            return STR_ID_PUSH_DISABLE;
            
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_enable_push_hint_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_enable_push_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_wap_push_get_enable_push_string();
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy((PS8) hintData[(index)], (PS8) GetString(str_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_sl_setting_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 string id for sl setting setting.
 *****************************************************************************/
U16 mmi_wap_push_get_sl_setting_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_push_set_p->general_set.sl_setting)
    {
        case SRV_WAP_PUSH_SL_SETTING_PROMPT:
            return STR_ID_PUSH_SL_SETTING_PROMPT;
            
        case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
            return STR_ID_PUSH_SL_SETTING_AUTO_LAUNCH;
            
        case SRV_WAP_PUSH_SL_SETTING_DISABLED:
            return STR_ID_PUSH_DISABLE;
            
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_sl_setting_hint_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_sl_setting_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_wap_push_get_sl_setting_string();
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy((PS8) hintData[(index)], (PS8) GetString(str_id));
}


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_enable_wl_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 string id for enable white list setting.
 *****************************************************************************/
U16 mmi_wap_push_get_enable_wl_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_push_set_p->general_set.enable_white_list)
    {
        case WAP_PMG_WL_ACTION_DISCARD:
            return STR_ID_PUSH_WL_SETTING_DISCARD;
            break;
        case WAP_PMG_WL_ACTION_NOTIFY:
            return STR_ID_PUSH_WL_SETTING_NOTIFY;
            break;
        case WAP_PMG_WL_DISABLED:
            return STR_ID_PUSH_DISABLE;
            break;
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_enable_wl_hint_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_enable_wl_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_wap_push_get_enable_wl_string();
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy((PS8) hintData[(index)], (PS8) GetString(str_id));
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


#ifdef __MMI_WAP_PUSH_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_enable_bl_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 string id for enable black list setting.
 *****************************************************************************/
U16 mmi_wap_push_get_enable_bl_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_push_set_p->general_set.enable_black_list)
    {
        case WAP_PMG_BL_ACTION_NOTIFY:
            return STR_ID_PUSH_WL_SETTING_NOTIFY;
            break;
        case WAP_PMG_BL_DISABLED:
            return STR_ID_PUSH_DISABLE;
            break;
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_enable_bl_hint_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_enable_bl_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_wap_push_get_enable_bl_string();
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy((PS8) hintData[(index)], (PS8) GetString(str_id));
}
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

/*****************************************************************************/
/******************  END of UI Highlight handler registration  ***************/
/*****************************************************************************/





/**********************************************************************************************************/
/*                                       Unified push code started                                        */
/**********************************************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_hilited_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_id        [IN]        
 * RETURNS
 *  return index to be highlighted.
 *****************************************************************************/
U16 mmi_wap_push_get_hilited_index (U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (screen_id)
    {
    case SCR_ID_PUSH_ENABLE_PUSH:
        type = PUSH_SETTING_ENABLE;
        break;
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    case SCR_ID_PUSH_ENABLE_BL_SETTING:
        type = PUSH_SETTING_ENABLE_BLACK_LIST;
        break;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    case SCR_ID_PUSH_ENABLE_WL_SETTING:
        type = PUSH_SETTING_ENABLE_WHITE_LIST;
        break;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    case SCR_ID_PUSH_SL_SETTING:
        type = PUSH_SETTING_ENABLE_SL;
        break;
    default:
        break;
    }
    return srv_wap_push_get_setting_index (type);
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
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
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
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
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
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
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
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_add_new_ph_num_image_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list        [IN]        
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_add_new_ph_num_image_icon (U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_list[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SENDER_ADDR_CAPTION] = gIndexIconsImageList[count];
	image_list[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SMSC_ADDR_CAPTION] = gIndexIconsImageList[++count];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fill_inline_item_for_add_new_ph_num
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_fill_inline_item_for_add_new_ph_num (void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_fill_add_ph_no_screen_data();
    return;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_add_new_ip_image_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_list        [IN]        
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_get_add_new_ip_image_icon (U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_list[MMI_BRW_PUSH_ADD_NEW_PH_NUM_SENDER_ADDR_CAPTION] = gIndexIconsImageList[0];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fill_inline_item_for_add_new_ip
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_wap_push_fill_inline_item_for_add_new_ip (void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_fill_ip_addr_inline_struct();
    return;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_number_of_white_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  number of white list.
 *****************************************************************************/
U16 mmi_wap_push_get_number_of_white_list (void)
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num = g_push_set_p->total_wl_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num < NVRAM_PUSH_MAX_NUM_WHITE_LIST)
    {
        num++;
    }
    return num;
#else
	return 0;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_number_of_black_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  number of black list.
 *****************************************************************************/
U16 mmi_wap_push_get_number_of_black_list (void)
{
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num = g_push_set_p->total_bl_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num < NVRAM_PUSH_MAX_NUM_BLACK_LIST)
    {
        num++;
    }
    return num;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
    return 0;
}


/*****************************************************************************/
/******************  Start code for NMGR  ************************************/
/*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_nmgr_send_new_event_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id         [IN]
 *  is_high        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_nmgr_send_new_event_notify(S16 sim_id, MMI_BOOL is_high)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//MMI_BOOL processed = MMI_FALSE;
    mmi_event_notify_enum evt_type;
    U16 str_id = STR_ID_BRW_NEW_PUSH_MESSAGE;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NMGR_SEND_NOTIFY);
    srv_wap_push_set_nmgr_answer_flag (sim_id, is_high);
    /* <xd> need to review carefully!! */
    evt_type = MMI_EVENT_MMS;
	if (sim_id == WAP_PMG_SIM1)
	{
#if (MMI_MAX_SIM_NUM >= 2)
    str_id = STR_ID_BRW_PUSH_NEW_SIM1_PUSH_MESSAGE;
#endif
	}
    if (sim_id == WAP_PMG_SIM2)
    {
        evt_type = MMI_EVENT_SLAVE_MMS;
#if (MMI_MAX_SIM_NUM >= 2)
        str_id = STR_ID_BRW_PUSH_NEW_SIM2_PUSH_MESSAGE;
    #endif
    }

    if (sim_id == WAP_PMG_SIM3)
    {
        evt_type = MMI_EVENT_SLAVE_MMS;
#if (MMI_MAX_SIM_NUM >= 3)
        str_id = STR_ID_BRW_PUSH_NEW_SIM3_PUSH_MESSAGE;
    #endif
    }

	    if (sim_id == WAP_PMG_SIM4)
    {
        evt_type = MMI_EVENT_SLAVE_MMS;
	#if (MMI_MAX_SIM_NUM >= 4)
        str_id = STR_ID_BRW_PUSH_NEW_SIM4_PUSH_MESSAGE;
    #endif
    }
 //   mmi_frm_nmgr_notify_by_idle(MMI_SCENARIO_ID_WAP_PUSH, evt_type, (WCHAR *)GetString (str_id));
      {
        WCHAR preview_text[100];
        mmi_frm_nmgr_alert_struct alert_info;
        memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   
        /*fill in app id for NSS query*/
        alert_info.app_id = APP_MMI_WAP_PUSH; //your app id
        /*fill in the basic info*/
        alert_info.scen_id = MMI_SCENARIO_ID_WAP_PUSH; // your scenario ID
        alert_info.event_type = evt_type; // your event id
        mmi_ucs2cpy((CHAR *)preview_text, (const CHAR *)GetString(str_id));
        alert_info.status_bar_para.display_string = preview_text; /* fill text preview data */
         alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
         alert_info.status_bar_para.image.id = IMG_SI_WAP;
      #ifdef __MMI_PUSH_IN_UM__
        mmi_um_alert_um_inbox_alert(&alert_info);
      #else
		{
            WCHAR popup_text[100];
			 alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
             alert_info.behavior_mask = PREFER_STATUS_BAR; 
             alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
              //alert_info.status_bar_icon_para.icon_id = STATUS_ICON_WAP;
             //	 alert_info.popup_para.image.nt.img_id = STATUS_ICON_WAP;
			/*fill in the popup information*/    
			 alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
			/*the image icon is used for popup, can be different from text preview*/
			// alert_info.popup_para.app_type = NATIVE_APP_TYPE;
			//	 alert_info.popup_para.image.nt.img_id = STATUS_ICON_WAP;
            
            mmi_wsprintf(
                popup_text, 
                100, 
                STR_ID_WAP_PUSH_UNREAD_MSG_NUMBER_ID, 
                g_srv_wap_push_cntxt->unread_msgs_count);


        alert_info.popup_para.popup_string =popup_text ;
        alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);

        alert_info.app_proc_para.scrn_group_proc= &mmi_wap_push_nss_unread_popup;
        alert_info.app_proc_para.user_data = NULL;	
        alert_info.app_proc_para.data_size = 0;
        mmi_frm_nmgr_alert(&alert_info); 

		}
   #endif
       }


    if ((SCR_ID_PUSH_INBOX == mmi_frm_scrn_get_active_id())|| (SCR_ID_BRW_PUSH_DUMMY_SCREEN == mmi_frm_scrn_get_active_id()))
    {
        /* To refresh the service inbox screen */
        mmi_wap_push_draw_dummy_screen(MMI_FALSE);
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_nmgr_get_unread_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_nmgr_get_unread_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 trans_id = PUSH_NMGR_UNREAD_MSG_CNT_TRANS_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NMGR_REQ_UNREAD);

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    mmi_nmgr_answer(
        MMI_NMGR_APP_WAP_PUSH,           /* menu data type */
        MMI_NMGR_RESULT_NOT_READY,       /* result ok */
        NULL,                            /* array of unread Push events */
        NULL);
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

    if (srv_wap_push_is_service_ready())
    {
		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NMGR_GET_UNREAD_FRM_PMG);
   #if (MMI_MAX_SIM_NUM >= 2)
//        if (g_push_cntxt->notify_nmgr == SRV_WAP_PUSH_NOTIFY_NMGR_SIM2 || g_push_cntxt->notify_nmgr == SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM2)
        if (srv_wap_push_get_notify_nmgr_flag() == SRV_WAP_PUSH_NOTIFY_NMGR_SIM2 || 
            srv_wap_push_get_notify_nmgr_flag() == SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM2)
        {
            trans_id = PUSH_NMGR_UNREAD_COUNT_FOR_SIM2_TRANS_ID;
        }
    #endif /* __MMI_WAP_DUAL_SIM__ */
	#if (MMI_MAX_SIM_NUM >= 3)
        if (srv_wap_push_get_notify_nmgr_flag() == SRV_WAP_PUSH_NOTIFY_NMGR_SIM3 || 
            srv_wap_push_get_notify_nmgr_flag() == SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM3)
        {
            trans_id = PUSH_NMGR_UNREAD_COUNT_FOR_SIM3_TRANS_ID;
        }
	 #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (srv_wap_push_get_notify_nmgr_flag() == SRV_WAP_PUSH_NOTIFY_NMGR_SIM4 || 
            srv_wap_push_get_notify_nmgr_flag() == SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM4)
        {
            trans_id = PUSH_NMGR_UNREAD_COUNT_FOR_SIM4_TRANS_ID;
        }
	 #endif
    
        srv_wap_push_get_msg_count (WAP_PMG_PARAM_NO, trans_id);
    }
}


#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_nmgr_cancel_unread_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_nmgr_cancel_unread_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PUSH_IN_UM__
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NMGR_SEND_UM_CANCEL_IND);
    mmi_um_nmgr_new_msg_cancel(SRV_UM_MSG_WAP_PUSH);
#endif /* __MMI_PUSH_IN_UM__ */
    srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY);
//    g_push_cntxt->notify_nmgr = MMI_BRW_PUSH_NOTIFY_NMGR_NOT_NOTIFY;
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_new_push_handle_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_new_push_handle_notification(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PUSH_IN_UM__
    mmi_brw_push_pre_entry_inbox_validation();
#endif
}


#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_nmgr_send_answer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  unread_count     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_nmgr_send_answer(S32 unread_count, U16 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 idle_buffer[100];
    S8 idle_buffer1[100];
    S8 tmp_str[10] = {'\0','\0', };
    U16 tone_id = MESSAGE_TONE;
	mmi_nmgr_info_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NMGR_ANSWER, unread_count);
    if (unread_count)
    {
        info.total_num = unread_count;
        info.image = IMG_NEW_MESSAGE_NOTIFICATION_MSG;

  //  #if(defined(__GEMINI__)) || (defined(GEMINI_PLUS) && (GEMINI_PLUS == 2))
  #if (MMI_MAX_SIM_NUM >= 2)
        if (sim_id == WAP_PMG_SIM2)
        {
		    mmi_ucs2cpy((S8*) idle_buffer, (S8*) GetString(STR_ID_BRW_PUSH_NEW_SIM2_PUSH_MESSAGE));
		    info.idle_text1 = idle_buffer;
       // #ifdef __MMI_DUAL_PROFILE_SUPPORT__
            tone_id = CARD2_MESSAGE_TONE;
       // #endif /* __MMI_DUAL_PROFILE_SUPPORT__ */
        }
         if (sim_id == WAP_PMG_SIM1)
        {
		    mmi_ucs2cpy((S8*) idle_buffer, (S8*) GetString(STR_ID_BRW_PUSH_NEW_SIM1_PUSH_MESSAGE));
		    info.idle_text1 = idle_buffer;
        }
	 #if (MMI_MAX_SIM_NUM >= 3)
	  if (sim_id == WAP_PMG_SIM3)
        {
		    mmi_ucs2cpy((S8*) idle_buffer, (S8*) GetString(STR_ID_BRW_PUSH_NEW_SIM3_PUSH_MESSAGE));
		    info.idle_text1 = idle_buffer;
        }
      #endif
	  #if (MMI_MAX_SIM_NUM >= 4)
	   if (sim_id == WAP_PMG_SIM4)
        {
		    mmi_ucs2cpy((S8*) idle_buffer, (S8*) GetString(STR_ID_BRW_PUSH_NEW_SIM4_PUSH_MESSAGE));
		    info.idle_text1 = idle_buffer;
        }
	   #endif
    #else /* __MMI_WAP_DUAL_SIM__ */
		mmi_ucs2cpy((S8*) idle_buffer, (S8*) GetString(STR_ID_PUSH_SERVICE_MESSAGE_RCVD));
		info.idle_text1 = idle_buffer;
    #endif /* __MMI_WAP_DUAL_SIM__ */

		gui_itoa(unread_count, (UI_string_type) tmp_str, 10);
		mmi_ucs2cpy((S8*) idle_buffer1, (S8*) tmp_str);
		mmi_ucs2cat((S8*) idle_buffer1, (S8*) L" ");
        mmi_ucs2cat((S8*) idle_buffer1, (S8*) GetString(STR_ID_BRW_PUSH_UNREAD));
		info.idle_text2 = idle_buffer1;

        info.image = IMG_NEW_MESSAGE_NOTIFICATION_MSG;

		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NMGR_SEND_ANSWER);
        mmi_nmgr_answer(
            MMI_NMGR_APP_WAP_PUSH,       /* menu data type */
            MMI_NMGR_RESULT_UPDATE,      /* result ok */
            &info,                       /* array of unread Push events */
            mmi_wap_new_push_handle_notification);
    }
    else
    {
		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NMGR_SEND_ANSWER_NOT_READY);
        mmi_nmgr_answer(
            MMI_NMGR_APP_WAP_PUSH,           /* menu data type */
            MMI_NMGR_RESULT_UPDATE,       /* result ok */
            NULL,                            /* array of unread push events */
            NULL);

    }
}


U16 mmi_wap_push_nmgr_active_on_idle (void)
{
    return (U16) mmi_nmgr_is_active_on_idle();
}

void mmi_wap_push_send_nmgr_refresh (void)
{
    mmi_nmgr_refresh(MMI_NMGR_APP_WAP_PUSH, MMI_NMGR_OPTION_USE_DEFAULT);
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

void mmi_wap_push_entry_idle_screen (void)
{
    mmi_idle_display();
}

#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_send_by_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_send_by_sms (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_write_msg_para_struct smsData;
	S8 *ucs2_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_SEND_BY_SMS);
    ucs2_data = srv_wap_push_construct_data();
    if (!ucs2_data)
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
        return;
    }
    memset(&smsData, 0, sizeof(mmi_sms_write_msg_para_struct));
    smsData.dcs = SMSAL_UCS2_DCS;
	smsData.string = ucs2_data;
    smsData.stringlength = mmi_ucs2strlen(ucs2_data);
    smsData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    smsData.ascii_addr = NULL;
    mmi_sms_write_msg_lanch(0, &smsData);
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SMS_ACTIVATED);
    srv_wap_push_mfree (ucs2_data);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_push_get_wap_prof_sim_id_for_push_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]
 * RETURNS
 *  profile sim id.
 *****************************************************************************/
U16 mmi_push_get_wap_prof_sim_id_for_push_sim_id (U16 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
    case WAP_PMG_SIM2:
    #if (MMI_MAX_SIM_NUM >= 2)
        return SRV_WAP_PROF_SIMID_SIM2;
    #endif
        
    default:
        break;
        
    }
    return SRV_WAP_PROF_SIMID_SIM1;
}





/*****************************************************************************/
/******************  END code for NMGR    ************************************/
/*****************************************************************************/


#ifdef __MMI_OP12_TOOLBAR__
/*****************************************************************************/
/******************  Code section for Toobar *********************************/
/*****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_msg_for_toolbar
 * DESCRIPTION
 *  This function handles the message response got toolbar event handling
 * PARAMETERS
 *  msg            [IN]
 *  url            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_handle_msg_for_toolbar (pmg_detailed_msg_struct *msg, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_scr_id = 0;
    mmi_ucm_make_call_para_struct make_call_para = {0,};
    S8 ucs2_phone_number[MAX_PUSH_PHN_NUM_LEN*ENCODING_LENGTH + 2] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_GOT_MSG_FRM_PMG, g_push_cntxt->tb_selected_opr);
    active_scr_id = mmi_frm_scrn_get_active_id();
    switch(g_push_cntxt->tb_selected_opr)
    {
    case MENU_ID_PUSH_TB_VIEW:
	case MENU_ID_PUSH_TB_VIEW_IN_CALL:
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_ENTER_VIEW, msg->msg_id);
		mmi_wap_push_handle_display_msg(msg, url, MMI_FALSE);
        break;
    case MENU_ID_PUSH_TB_DELETE:
	case MENU_ID_PUSH_TB_DELETE_IN_CALL:
        break;
	case MENU_ID_PUSH_TB_CALL:
		if((msg->from.addr_type == WAP_PMG_ADDR_PHONE) && 
			(strlen((S8*)msg->from.addr)) &&
			(srv_wap_push_check_valid_number((S8*)msg->from.addr)))
		{
            if (SCR_ID_PUSH_GENERIC_PROCESSING == mmi_frm_scrn_get_active_id())
            {
			    memset(ucs2_phone_number, '\0', MAX_PUSH_PHN_NUM_LEN);
			    mmi_asc_n_to_ucs2((S8*)ucs2_phone_number, (S8*) msg->from.addr, MAX_PUSH_PHN_NUM_LEN);

                mmi_ucm_init_call_para(&make_call_para);
                make_call_para.adv_para.after_make_call_callback = NULL; 
                make_call_para.dial_type = SRV_UCM_CALL_TYPE_ALL;
                make_call_para.ucs2_num_uri = (U16*)ucs2_phone_number;
                mmi_ucm_call_launch(0, &make_call_para);

			    /* MakeCall((S8*) (ucs2_phone_number));  This API is replaced by abouve 5 lines */
            }
		}
		else
		{
			MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_SHOW_INVALID_POPUP);
			if (active_scr_id == SCR_ID_PUSH_GENERIC_PROCESSING)
			{
				mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_INVALID_NUMBER);
			}
		}
		if (SCR_ID_PUSH_GENERIC_PROCESSING != mmi_frm_scrn_get_active_id())
		{
			//DeleteScreenIfPresent(SCR_ID_PUSH_GENERIC_PROCESSING);
            mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
		}
		else
		{
			ClearExitHandler();
		}
		break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_msg_detail_for_tb_opr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_get_msg_detail_for_tb_opr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_wap_push_scrhdlr_entry_generic_processing();
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_ASK_MSG_FRM_PMG, PUSH_GET_MSG_DATA_FOR_TB_TRANS_ID);
	srv_wap_push_get_full_message(g_push_cntxt->tb_current_msg_id, PUSH_GET_MSG_DATA_FOR_TB_TRANS_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_delete_msg_from_tb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_delete_msg_from_tb (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_SEND_DEL_REQ_FOR_MSG_ID, g_push_cntxt->tb_current_msg_id);
	srv_wap_push_delete_message_generic (g_push_cntxt->tb_current_msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_list_for_toolbar
 * DESCRIPTION
 * This API handle the message list for toolbar reply. 
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_handle_list_for_toolbar (wps_pmg_msg_list_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL need_more = MMI_TRUE;
	U16 incr;
	static U16 index = 0;
    wps_pmg_msg_list_cnf_struct *msg_list =  msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_GOT_MSG_LIST_FROM_PMG, index);
	if(msg_list->size == 0)
	{
		mmi_tb_evnt_answer(
			MMI_TB_EVNT_NEW_WAP_PUSH,
			MMI_TB_RESULT_UPDATE,
			(S32) 0,
			(S32) 0,
		     NULL,
			mmi_wap_push_set_key_hndlr_for_push_view_from_tb,
			mmi_wap_push_set_key_hndlr_for_multi_hndlr_for_tb);
		return;
	}

	if (g_push_cntxt->tb_data == NULL)
	{
		g_push_cntxt->tb_data = (mmi_tb_evnt_struct*) srv_wap_push_malloc((MMI_TB_MAX_NEW_MESSAGE_NUM * sizeof(mmi_tb_evnt_struct)));
		if (g_push_cntxt->tb_data == NULL)
		{
            /* Condition should not arises as Toolbar need data only after Push message queue got processed */
			MMI_ASSERT(g_push_cntxt->tb_data);
		}
		memset (g_push_cntxt->tb_data, 0, (MMI_TB_MAX_NEW_MESSAGE_NUM * sizeof(mmi_tb_evnt_struct)));
	}
	for (incr = 0; incr < msg_list->size; incr++)
	{
		if(msg_list->msg_list_data[incr].read == 0)
		{
			if((index < g_push_cntxt->tb_num_of_req) && (index < MMI_TB_MAX_NEW_MESSAGE_NUM))
			{				
				g_push_cntxt->tb_data[index].subject = (S8*)srv_wap_push_malloc(MMI_BRW_PUSH_MAX_TB_SUB_LEN);
				if (g_push_cntxt->tb_data[index].subject == NULL)
				{
                    /* Condition should not arises as Toolbar need data only after Push message queue got processed */
					MMI_ASSERT(g_push_cntxt->tb_data[index].subject);
				}
				memset(g_push_cntxt->tb_data[index].subject, 0, MMI_BRW_PUSH_MAX_TB_SUB_LEN);

				MMI_PRINT(
					SRV_WAP_PUSH_TRACE_MOD_INET_APP,
					SRV_INET_TRC_G4_PUSH,
					"[PUSH] Sending message Id to Toolbar for %dth message = %d", 
					index,
					(U32) msg_list->msg_list_data[incr].msg_id);

				g_push_cntxt->tb_user_data[index] = msg_list->msg_list_data[incr].msg_id;
				g_push_cntxt->tb_data[index].user_data = (void*)(&(g_push_cntxt->tb_user_data[index]));
				g_push_cntxt->tb_data[index].is_time_present = MMI_TRUE;

				if (msg_list->msg_list_data[incr].expired == 0 ||
					msg_list->msg_list_data[incr].expired > (U32) srv_wap_push_get_current_utc_time())
				{
					g_push_cntxt->tb_data[index].icon = IMG_ID_BRW_PUSH_UNREAD;
				}
				else
				{
					g_push_cntxt->tb_data[index].icon = IMG_ID_BRW_PUSH_EXPIRED_UNREAD;
				}

				/*Started copying subject */
				if (msg_list->msg_list_data[incr].text[0] != '\0')
				{
					if (msg_list->msg_list_data[incr].text_type == WAP_PMG_STRTYPE_ASCII)
					{
						mmi_asc_n_to_ucs2(
							(S8*) g_push_cntxt->tb_data[index].subject, 
							(S8*) msg_list->msg_list_data[incr].text,
							MAX_SUBMENU_CHARACTERS);
					}
					else if((msg_list->msg_list_data[incr].text_type == WAP_PMG_STRTYPE_UCS2))
					{
						mmi_ucs2ncpy(
							(S8*) g_push_cntxt->tb_data[index].subject, 
							(S8*) msg_list->msg_list_data[incr].text, 
							MAX_SUBMENU_CHARACTERS);
					}
				}
				else
				{
			    #ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
					mmi_asc_n_to_ucs2(
						(S8*) g_push_cntxt->tb_data[index].subject, 
						(S8*) msg_list->msg_list_data[incr].href,
						MAX_SUBMENU_CHARACTERS);
				#else
					mmi_ucs2cpy((S8*) g_push_cntxt->tb_data[index].subject, (S8*) GetString(STR_ID_PUSH_NO_SUBJECT));
				#endif /* __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__ */
				}
				/*Subject have been copied*/

				mmi_dt_utc_sec_2_mytime(
					(U32) msg_list->msg_list_data[incr].created, 
					&(g_push_cntxt->tb_data[index].time),
					MMI_TRUE);
				index++;
			}
			else
			{
				need_more = MMI_FALSE;
				break;
			}
		}
	}
	if(need_more)
	{
		if (msg_list->more != 0)
		{
			MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_ASK_MORE_MSG_LIST_FROM_PMG, index);			
			srv_wap_push_get_list_from_service_layer(msg_list->more, 
				msg_list->size_remain,
				PUSH_TB_UNREAD_MSG_LIST_TRANS_ID, 
				WAP_PMG_PARAM_NO);
			return;
		}
		else
		{
			MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_ANSWER_TOOLBAR);
            MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_TOOLBAR_ANSWERED, g_push_cntxt->tb_total_num_unread, index);
			mmi_tb_evnt_answer(
				MMI_TB_EVNT_NEW_WAP_PUSH,
				MMI_TB_RESULT_UPDATE,
				(S32) g_push_cntxt->tb_total_num_unread,
				(S32) index,
				g_push_cntxt->tb_data,
				mmi_wap_push_set_key_hndlr_for_push_view_from_tb,
				mmi_wap_push_set_key_hndlr_for_multi_hndlr_for_tb);

		}
	}
	else
	{
		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_TOOLBAR_ANSWERED, g_push_cntxt->tb_total_num_unread, index);
		mmi_tb_evnt_answer(
			MMI_TB_EVNT_NEW_WAP_PUSH,
			MMI_TB_RESULT_UPDATE,
			(S32) g_push_cntxt->tb_total_num_unread,
			(S32) index,
			g_push_cntxt->tb_data,
			mmi_wap_push_set_key_hndlr_for_push_view_from_tb,
			mmi_wap_push_set_key_hndlr_for_multi_hndlr_for_tb);

	}

	
	for (incr = 0; incr < index; incr++)
	{
		if(g_push_cntxt->tb_data[incr].subject)
		{
			srv_wap_push_mfree(g_push_cntxt->tb_data[incr].subject);
			g_push_cntxt->tb_data[incr].subject = NULL;
		}
		if(MMI_TB_MAX_NEW_MESSAGE_NUM <= incr)
		{
			break;
		}
	}
	srv_wap_push_mfree(g_push_cntxt->tb_data);
	g_push_cntxt->tb_data = NULL;
	index = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_count_rsp_for_tb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_handle_count_rsp_for_tb (U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_tb_evnt_struct tb_event_struct = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(num == 0)
	{
		mmi_tb_evnt_answer(MMI_TB_EVNT_NEW_WAP_PUSH, MMI_TB_RESULT_UPDATE, 0, 0, &tb_event_struct, NULL, NULL);
	}
	else
	{
		g_push_cntxt->tb_total_num_unread = num;
		if (g_push_cntxt->tb_total_num_unread >= WAP_PMG_MAX_PUSH_MESSAGES)
		{
			MMI_ASSERT (g_push_cntxt->tb_total_num_unread <= WAP_PMG_MAX_PUSH_MESSAGES);
		}
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_ASK_MSG_LIST_FROM_PMG, PUSH_TB_UNREAD_MSG_LIST_TRANS_ID);
		srv_wap_push_get_list_from_service_layer(g_push_cntxt->tb_start_index, 
			g_push_cntxt->tb_total_num_unread, 
			PUSH_TB_UNREAD_MSG_LIST_TRANS_ID, 
			WAP_PMG_PARAM_NO);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_tb_evnt_query_push
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_tb_evnt_query_push(S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_tb_evnt_struct tb_event_struct = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_QUERY, num);
    g_push_cntxt->tb_num_of_req = (U32) num;
    g_push_cntxt->is_tb_active = MMI_TRUE;
    g_push_cntxt->tb_start_index = 0;
	g_push_cntxt->tb_total_num_unread = 0;
    if (srv_wap_push_is_service_ready())
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_ASK_UNREAD_COUNT_FROM_PMG, PUSH_TB_UNREAD_MSG_CNT_TRANS_ID);
        srv_wap_push_get_msg_count (WAP_PMG_PARAM_NO, PUSH_TB_UNREAD_MSG_CNT_TRANS_ID);
    }
    else
    {
		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_RSP_NOT_READY);
        mmi_tb_evnt_answer(MMI_TB_EVNT_NEW_WAP_PUSH, MMI_TB_RESULT_NOT_READY, 0, 0, &tb_event_struct, NULL, NULL);
    }
}

/*****************************************************************************/
/******************  END Code section for Toobar *****************************/
/*****************************************************************************/
#endif /* __MMI_OP12_TOOLBAR__ */


U16 mmi_wap_push_is_in_idle_state (void)
{
    return (U16) (IsMMIInIdleState());
}

U16 mmi_wap_push_get_intermidiate_marker_scr_id (void)
{
#ifdef __MMI_BACKGROUND_CALL__
    return mmi_ucm_app_get_intermediate_marker_scrn_id();
#endif /* __MMI_BACKGROUND_CALL__ */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_get_call_marker_screen_id
 * DESCRIPTION
 *  Returns call marker screen id.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_wap_push_get_call_marker_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__

    return mmi_wap_push_get_intermidiate_marker_scr_id();

#else /* __MMI_BACKGROUND_CALL__ */ 

    return mmi_ucm_get_marker_scrn_id();

#endif /* __MMI_BACKGROUND_CALL__ */ 
}


void mmi_wap_push_turn_on_back_light (void)
{
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}

#if defined (__MMI_FTE_SUPPORT__ ) && defined (__MMI_ICON_BAR_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_push_uiplugin_handle_fte_tb_event_on_viewer
 * DESCRIPTION
 * 
 * PARAMETERS
 *  index      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_uiplugin_handle_fte_tb_event_on_viewer (S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    case PUSH_VIWER_SCR_FTE_TB_OPT_GOTO:
        mmi_wap_push_launch_selected_message();
        break;
    case PUSH_VIWER_SCR_FTE_TB_OPT_DELETE:
        mmi_wap_push_delete_from_msg_option();
        break;
    default:
        /* error */
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_push_uiplugin_init_viewer_fte_data
 * DESCRIPTION
 * 
 * PARAMETERS
 *  fte_data       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_uiplugin_init_viewer_fte_data(mmi_push_scrhdlr_viewer_fte_tb_struct *fte_data, U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
    case SCR_ID_BRW_READ_SERVICE_MESSAGE:
        (*fte_data).item_count = PUSH_VIWER_SCR_FTE_TB_OPT_TOTAL;

        (*fte_data).content_icon[PUSH_VIWER_SCR_FTE_TB_OPT_GOTO] = get_image(IMG_ID_BRW_PUSH_TOOLBAR_GOTO);
        (*fte_data).content_icon[PUSH_VIWER_SCR_FTE_TB_OPT_DELETE] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);

        (*fte_data).disabled_content_icon[PUSH_VIWER_SCR_FTE_TB_OPT_GOTO] = get_image(IMG_ID_BRW_PUSH_TOOLBAR_GOTO_DISABLED);
        (*fte_data).disabled_content_icon[PUSH_VIWER_SCR_FTE_TB_OPT_DELETE] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);

        (*fte_data).string[PUSH_VIWER_SCR_FTE_TB_OPT_GOTO] = (PU8) GetString (STR_GLOBAL_GO_TO);
        (*fte_data).string[PUSH_VIWER_SCR_FTE_TB_OPT_DELETE] = (PU8) GetString (STR_GLOBAL_DELETE);

        (*fte_data).callback = mmi_push_uiplugin_handle_fte_tb_event_on_viewer;
        break;
    default:
        (*fte_data).item_count = 0;
        break;
    }
}
#endif /* __MMI_FTE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_push_close_active_screen
 * DESCRIPTION
 * 
 * PARAMETERS
 *  fte_data       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_close_active_screen(void)
{
    mmi_frm_scrn_close_active_id ();
}

mmi_ret mmi_wap_push_idle_callback_group_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
        case EVT_ID_GROUP_FOCUSED:
            g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_FROM_IDLE;
        break;
        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            mmi_frm_group_close (GRP_ID_BRW_PUSH_FROM_IDLE);
            g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
            break;
        default:
            {
			 mmi_wap_push_send_proc_default(evt);
            }
            break;

    }

    return MMI_RET_OK;
}
void mmi_wap_push_create_idle_callback_group(void)
{

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BRW_PUSH_FROM_IDLE, mmi_wap_push_idle_callback_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_BRW_PUSH_FROM_IDLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_FROM_IDLE;

}


MMI_BOOL mmi_wap_push_is_screen_present(MMI_ID scrn_id)
{
    mmi_id group_id;
    MMI_BOOL result = MMI_FALSE;
    for (group_id = (MMI_WAP_PUSH_BASE + 1); group_id < GRP_ID_BRW_PUSH_END; group_id++)
    {
        if (mmi_frm_group_is_present (group_id))
        {
            result = mmi_frm_scrn_is_present (group_id, scrn_id, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG);
            if (result)
            {
                break;
            }
        }
    }
    return result;
}


#ifdef __MMI_PUSH_IN_UM__
#ifdef __MMI_UM_ITERATOR_VIEWER__
void mmi_push_uiplugin_get_slide_buttons_data(mmi_push_scrhdlr_viewer_slide_buttons_struct *slide_buttons_data, U16 scr_id)
{
    switch (scr_id)
    {
    case SCR_ID_BRW_READ_SERVICE_MESSAGE:
        (*slide_buttons_data).left_button_string = NULL;
        (*slide_buttons_data).left_button_down_img = NULL;
        (*slide_buttons_data).left_button_up_img = NULL;
        if (mmi_dmgr_if_lnk_available ())
        {
            (*slide_buttons_data).left_button_func = mmi_wap_push_hanndle_lnk_on_viewer;
        }
        else
        {
            (*slide_buttons_data).left_button_func = NULL;
        }

        (*slide_buttons_data).right_button_string = NULL;
        (*slide_buttons_data).right_button_down_img = NULL;
        (*slide_buttons_data).right_button_up_img = NULL;
        if (mmi_dmgr_if_rnk_available ())
        {
            (*slide_buttons_data).right_button_func = mmi_wap_push_hanndle_rnk_on_viewer;
        }
        else
        {
            (*slide_buttons_data).right_button_func = NULL;
        }

        mmi_push_dmgr_get_slide_buttons_middle_string ((*slide_buttons_data).middle_string);
        break;
    default:
        (*slide_buttons_data).left_button_func = NULL;
        break;
    }
}
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif /* __MMI_PUSH_IN_UM__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_service_msg_setting_send_result
 * DESCRIPTION
 *  To send result for service message settings
 * PARAMETERS
 *  result        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_service_msg_setting_send_result (cui_service_msg_evt_enum result)
{
    cui_service_msg_setting_evt_struct evt;

    MMI_FRM_INIT_EVENT(&evt, result);

    evt.sender_id = g_push_cntxt->service_msg_setting_cid;

    mmi_frm_group_send_to_caller(g_push_cntxt->service_msg_setting_cid, (mmi_group_event_struct*) &evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_service_msg_setting_proc
 * DESCRIPTION
 *  Proc funtion for service message settings
 * PARAMETERS
 *  evt            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_wap_push_service_msg_setting_proc (mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
        case EVT_ID_GROUP_FOCUSED:
            g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_SETTING;
        break;
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            //cui_service_msg_setting_close (g_push_cntxt->service_msg_setting_cid);
            break;
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            cui_service_msg_setting_close (g_push_cntxt->service_msg_setting_cid);
            break;
        case EVT_ID_GROUP_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            cui_service_msg_setting_close (g_push_cntxt->service_msg_setting_cid);
            break;
        default:
             {
				 mmi_wap_push_send_proc_default(evt);
            }
           break;
    }
    return MMI_RET_OK;
}


void cui_wap_push_service_msg_setting_launch (mmi_id parent_gid)
{
    mmi_id group_id;
    group_id = cui_service_msg_setting_create (parent_gid);
    if (group_id != GRP_ID_INVALID)
    {
        cui_service_msg_setting_run (group_id);
    }
    else
    {
        mmi_wap_push_event_based_display_popup(MMI_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE);
    }
}


#ifdef __MMI_PUSH_IN_MSG__

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_service_msg_main_manu_proc
 * DESCRIPTION
 *  Proc funtion for service message settings
 * PARAMETERS
 *  evt            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_wap_push_service_msg_main_manu_proc (mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE :
        case EVT_ID_GROUP_FOCUSED:
            g_push_cntxt->scr_grp_id = GRP_ID_WAP_PUSH_SERVICE_MSG_MAIN;
        break;
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            //cui_service_msg_menu_close (g_push_cntxt->service_msg_cid);
            break;
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            cui_service_msg_menu_close (g_push_cntxt->service_msg_cid);
            break;
        case EVT_ID_GROUP_EXIT:
            break;
        case EVT_ID_GROUP_DEINIT:
            cui_service_msg_menu_close (g_push_cntxt->service_msg_cid);
            break;
        default:
             {
				 mmi_wap_push_send_proc_default(evt);
            }
           break;
    }
    return MMI_RET_OK;
}


void cui_wap_push_service_msg_main_menu_launch (mmi_id parent_gid)
{
    mmi_id group_id;
    group_id = cui_service_msg_menu_create (parent_gid);
    if (group_id != GRP_ID_INVALID)
    {
        cui_service_msg_menu_run (group_id);
    }
    else
    {
        mmi_wap_push_event_based_display_popup(MMI_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE);
    }
}
#endif /* __MMI_PUSH_IN_MSG__ */


#ifdef __UM_SUPPORT__
void mmi_wap_push_if_launch_viewer (mmi_id parent_grp_id, U32 msg_id, void *user_data, cui_msg_viewer_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
	{
		case CUI_MSG_VIEWER_TYPE_NORMAL:
            g_srv_wap_push_cntxt->selected_message.msg_type = WAP_PMG_MSGTYPE_NULL;
            g_srv_wap_push_cntxt->selected_message_id = msg_id;
            mmi_wap_push_scrhdlr_entry_message_display_group(parent_grp_id);
			break;
#ifdef __MMI_PUSH_IN_UM__
	#ifdef __MMI_UM_ITERATOR_VIEWER__	
		case CUI_MSG_VIEWER_TYPE_ITERATOR:
            {
	            mmi_um_entry_msg_struct entry_msg_param;
	            entry_msg_param.user_data = user_data;
	            entry_msg_param.key_code = MMI_UM_UI_ENTRY_KEY_CSK;
	            entry_msg_param.msg_id = msg_id;
	            entry_msg_param.parent_grp_id = parent_grp_id;
                mmi_wap_push_dummy_screen(parent_grp_id);
                mmi_push_handle_entry_msg_wap_push (&entry_msg_param);
                mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE);
                mmi_frm_group_close(GRP_ID_BRW_PUSH_DUMMY);
            }
            break;
	#else /*__MMI_UM_ITERATOR_VIEWER__*/
		case CUI_MSG_VIEWER_TYPE_ITERATOR:
			ASSERT(0);
	#endif /*__MMI_UM_ITERATOR_VIEWER__*/
#endif /* __MMI_PUSH_IN_UM__ */
	}
}
#endif

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    
void mmi_wap_push_setting_modify_or_add_common()
   {
    cui_inline_close(g_push_cntxt->inline_gid);
    g_push_cntxt->inline_gid = GRP_ID_INVALID;
    if (g_push_set_p->selected_list_type == SRV_WAP_PUSH_WHITE_LIST)
		{
		//	if(g_push_set_p->total_wl_entry >=NVRAM_PUSH_MAX_NUM_WHITE_LIST)
               			  cui_menu_close(menu_id_new);

		}

   #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        else
        {
            
          //  if(g_push_set_p->total_bl_entry >=NVRAM_PUSH_MAX_NUM_BLACK_LIST)
                 cui_menu_close(menu_id_new);
           
        }
	#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
}

void mmi_wap_push_setting_modify_or_add_list()
{
    
    ASSERT(g_push_cntxt->inline_gid != GRP_ID_INVALID);
	if(SRV_WAP_PUSH_ERROR_SUCCESS==srv_wap_push_setting_modify_or_add_list())
			  mmi_wap_push_setting_modify_or_add_common();

		}

void mmi_wap_push_setting_modify_or_add_ip_addr()
        {
            
    ASSERT(g_push_cntxt->inline_gid != GRP_ID_INVALID);
	if(SRV_WAP_PUSH_ERROR_SUCCESS==srv_wap_push_setting_modify_or_add_ip_addr())
		  mmi_wap_push_setting_modify_or_add_common();
           
        }
#endif /*  __MMI_WAP_PUSH_WHITE_LIST__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_progres_evt
 * DESCRIPTION
 *  handles progress event from call back manager
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_progress_evt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_progress_event_struct *evt_progress = (srv_wap_push_progress_event_struct*)evt; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt_progress->evt_id == EVT_ID_SRV_PUSH_SHOW_PROGRESS);
    mmi_wap_push_scrhdlr_entry_generic_processing();
 	 #ifdef __MMI_NCENTER_SUPPORT__
             #ifdef __MMI_PUSH_IN_MSG__
                mmi_wap_push_ncenter_unread_messages();
             #endif
     #endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_popup_evt
 * DESCRIPTION
 *  handles pop-up event from call back manager
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_popup_evt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_popup_event_struct *evt_popup = (srv_wap_push_popup_event_struct*)evt; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt_popup->evt_id == EVT_ID_SRV_PUSH_SHOW_POPUP);
    mmi_wap_push_event_based_display_popup(evt_popup->evt_notify, evt_popup->str_notify);
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_new_service_msg
 * DESCRIPTION
 *  handles new service messages
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_new_service_msg(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_NCENTER_SUPPORT__
    MMI_BOOL  is_on_idle = MMI_FALSE;
    #endif
    srv_wap_push_handle_new_service_msg_struct* evt_new_msg = (srv_wap_push_handle_new_service_msg_struct*)evt;
      #ifndef __MMI_NCENTER_SUPPORT__
	 srv_wap_push_handle_sl_on_idle_struct  evt_sl_idle;
	 srv_wap_push_handle_sl_on_non_idle_struct  evt_sl_non_idle;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_HANDLE_NEW_SERVICE_MSG);
    if (evt_new_msg->enable_push != WAP_PMG_RETR_DISABLED)
    {
		#ifndef __MMI_NCENTER_SUPPORT__
        is_on_idle = (MMI_BOOL)mmi_wap_push_is_in_idle_state();
        #endif
        switch(evt_new_msg->new_msg->msg_type)
        {
        case WAP_PMG_MSGTYPE_SL:
			#ifndef __MMI_NCENTER_SUPPORT__
            if (is_on_idle)
            {
               	evt_sl_idle.message_id = evt_new_msg->new_msg->msg_id;
				evt_sl_idle.timestamp = evt_new_msg->new_msg->created;
				evt_sl_idle.url = evt_new_msg->url;
				evt_sl_idle.sim_id = evt_new_msg->new_msg->sim_id;
				evt_sl_idle.sl_setting = g_push_set_p->general_set.sl_setting;
				evt_sl_idle.addr[0]='\0';
				strcpy((S8*) evt_sl_idle.addr, (S8*) evt_new_msg->new_msg->from.addr);
             //   evt_sl_idle.addr=evt_new_msg->new_msg->from.addr;
				mmi_wap_push_handle_sl_on_idle (&evt_sl_idle);
            }
            else
            {
                evt_sl_non_idle.message_id = evt_new_msg->new_msg->msg_id;
				evt_sl_non_idle.timestamp = evt_new_msg->new_msg->created;
				evt_sl_non_idle.sim_id = evt_new_msg->new_msg->sim_id;
				evt_sl_non_idle.sl_setting = g_push_set_p->general_set.sl_setting;
				evt_sl_non_idle.addr[0]='\0';
				strcpy((S8*) evt_sl_non_idle.addr, (S8*) evt_new_msg->new_msg->from.addr);
               // evt_sl_non_idle.addr=evt_new_msg->new_msg->from.addr;
				mmi_wap_push_handle_sl_on_non_idle (&evt_sl_non_idle);
            }
            break;
          #else
			{
             switch(g_push_set_p->general_set.sl_setting)
				 {
					 case SRV_WAP_PUSH_SL_SETTING_DISABLED:
							 srv_wap_push_send_del_req_to_pmg (evt_new_msg->new_msg->msg_id, PUSH_NEW_MSG_DEL_TRANS_ID);
							 break;
					  case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
                                {

								  if (!srv_wap_push_enque_msg_ex (evt_new_msg->new_msg->msg_id, WAP_PMG_MSGTYPE_SL,(CHAR*)evt_new_msg->new_msg->from.addr))
									  {
                                        
									    mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
												 srv_wap_push_send_del_req_to_pmg (evt_new_msg->new_msg->msg_id, PUSH_NEW_MSG_DEL_TRANS_ID);
									  }
                                    else if(mshow)
									  {
                                          
										mshow=MMI_FALSE;
										  mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_MMS, mmi_wap_push_ncenter_msg_queue_handler, (void *)NULL);

									   	#ifdef __MMI_PUSH_IN_UM__
								//		 srv_wap_push_send_um_new_msg_ind(evt_new_msg->new_msg->msg_id, evt_new_msg->new_msg->created, (U16)evt_new_msg->new_msg->sim_id);//TK Refresh
                                                                                 srv_wap_push_send_um_refresh_ind(evt_new_msg->new_msg->msg_id,SRV_UM_REFRESH_NEW_INCOMING_MSG ,&(evt_new_msg->new_msg->from));
										#endif /* __MMI_PUSH_IN_UM__ */
										
									 }
									
							      }
							
									 

						 break;
        
						case SRV_WAP_PUSH_SL_SETTING_PROMPT:
                            {
							 #ifdef __MMI_PUSH_IN_UM__
							 srv_wap_push_send_um_new_msg_ind(evt_new_msg->new_msg->msg_id, evt_new_msg->new_msg->created, (U16)evt_new_msg->new_msg->sim_id);
							 #endif /* __MMI_PUSH_IN_UM__ */
							  mmi_wap_push_nmgr_send_new_event_notify((S16)evt_new_msg->new_msg->sim_id, MMI_FALSE);
                            }
							 break;
						  }
					}
			   break;
             #endif
        case WAP_PMG_MSGTYPE_SI:
            MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_NEW_SI_MESSAGES, evt_new_msg->new_msg->msg_id);
			switch (evt_new_msg->new_msg->priority)
			{
			case WAP_PMG_MSGPRIO_HIGH:
				#ifndef __MMI_NCENTER_SUPPORT__
                if (is_on_idle)
                {
                    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SI_HIGH_MESSAGES_ON_IDLE, evt_new_msg->new_msg->msg_id);
                    if (IsKeyPadLockState() != 0)
                    {
                        if (!srv_wap_push_enque_msg_ex(evt_new_msg->new_msg->msg_id, WAP_PMG_MSGTYPE_SI,(CHAR*)evt_new_msg->new_msg->from.addr))
                        {
                            mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
                            srv_wap_push_send_del_req_to_pmg (evt_new_msg->new_msg->msg_id, PUSH_NEW_MSG_DEL_TRANS_ID);
                        }
                        else
                        {
                            mmi_wap_push_nmgr_send_new_event_notify((S16)evt_new_msg->new_msg->sim_id, MMI_TRUE);
                          
                            return MMI_RET_OK;
                        }
                    }
                    else
                    {
                        g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
						mmi_wap_push_nmgr_send_new_event_notify((S16)evt_new_msg->new_msg->sim_id, MMI_TRUE);
						
						MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_DISPLAY_MESSAGE);
						srv_wap_push_copy_data_to_selected_message(evt_new_msg->new_msg, evt_new_msg->url);
						srv_wap_push_update_service_msg_req(evt_new_msg->new_msg->msg_id);
						srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
						MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXIT_DISPLAY_MESSAGE);
                        mmi_wap_push_display_msg (GRP_ID_ROOT);
                    }
                }
                else
                {
                    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SI_HIGH_MESSAGES_ON_NON_IDLE, evt_new_msg->new_msg->msg_id);
                    if (srv_wap_push_enque_msg_ex(evt_new_msg->new_msg->msg_id, WAP_PMG_MSGTYPE_SI,(CHAR*)evt_new_msg->new_msg->from.addr))
                    {
                        mmi_wap_push_update_inbox_selected_index (1);
                        mmi_wap_push_nmgr_send_new_event_notify((S16)evt_new_msg->new_msg->sim_id, MMI_TRUE);
                    #ifdef __MMI_PUSH_IN_UM__
                        srv_wap_push_send_um_new_msg_ind(evt_new_msg->new_msg->msg_id, evt_new_msg->new_msg->created, (U16)evt_new_msg->new_msg->sim_id);
                    #endif
                    }
                    else
                    {
                        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
                        srv_wap_push_send_del_req_to_pmg (evt_new_msg->new_msg->msg_id, PUSH_NEW_MSG_DEL_TRANS_ID);
                    }
                }
             #else
                         
					if (!srv_wap_push_enque_msg_ex(evt_new_msg->new_msg->msg_id, WAP_PMG_MSGTYPE_SI,(CHAR*)evt_new_msg->new_msg->from.addr))
						  {
							  mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
							  srv_wap_push_send_del_req_to_pmg (evt_new_msg->new_msg->msg_id, PUSH_NEW_MSG_DEL_TRANS_ID);
						  }
				else
				  {
							   if(mshow)
					  {
					                    mshow=MMI_FALSE;
									    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_MMS, mmi_wap_push_ncenter_msg_queue_handler, (void *)NULL);
								  #ifdef __MMI_PUSH_IN_UM__
								//   srv_wap_push_send_um_new_msg_ind(evt_new_msg->new_msg->msg_id, evt_new_msg->new_msg->created, (U16)evt_new_msg->new_msg->sim_id);//TK Refresh
                                     srv_wap_push_send_um_refresh_ind(evt_new_msg->new_msg->msg_id,SRV_UM_REFRESH_NEW_INCOMING_MSG ,&(evt_new_msg->new_msg->from));
										#endif /* __MMI_PUSH_IN_UM__ */
							   }
						     }
						

				 
					

				 

			 #endif

				break;
            case WAP_PMG_MSGPRIO_MEDIUM: 
            #ifdef __MMI_PUSH_IN_UM__
                srv_wap_push_send_um_new_msg_ind(evt_new_msg->new_msg->msg_id, evt_new_msg->new_msg->created, (U16)evt_new_msg->new_msg->sim_id);
            #endif /* __MMI_PUSH_IN_UM__ */
                mmi_wap_push_update_inbox_selected_index (1);
                
                mmi_wap_push_nmgr_send_new_event_notify((S16)evt_new_msg->new_msg->sim_id, MMI_FALSE);
               
                break;
 	    case WAP_PMG_MSGPRIO_LOW:
            {
               #ifndef __MMI_NCENTER_SUPPORT__
                mmi_wap_push_turn_on_back_light();
              #endif

            #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
                if (mmi_wap_push_nmgr_active_on_idle())
                {
                    mmi_wap_push_send_nmgr_refresh();
                }
            #endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/
       
	        #ifdef __MMI_OP12_TOOLBAR__
                else if (mmi_wap_push_is_in_idle_state())
                {
                    srv_wap_push_tb_evnt_query_push(MMI_TB_MAX_NEW_MESSAGE_NUM);
                }
	        #endif /* __MMI_OP12_TOOLBAR__ */
            #ifdef __MMI_PUSH_IN_UM__
                srv_wap_push_send_um_refresh_ind(evt_new_msg->new_msg->msg_id,SRV_UM_REFRESH_NEW_INCOMING_MSG ,&(evt_new_msg->new_msg->from));
            #endif
                mmi_wap_push_update_inbox_selected_index (1);
                if ((SCR_ID_PUSH_INBOX == mmi_frm_scrn_get_active_id())|| (SCR_ID_BRW_PUSH_DUMMY_SCREEN == mmi_frm_scrn_get_active_id()))
                {
                    /* To refresh the service inbox screen */
                    mmi_wap_push_draw_dummy_screen(MMI_FALSE);
                    mmi_frm_scrn_close_active_id();
                }
             }
                break;
            }
            break;
        }
    }
    else
    {
        srv_wap_push_send_del_req_to_pmg (evt_new_msg->new_msg->msg_id, PUSH_NEW_MSG_DEL_TRANS_ID);
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_msg_deleted_by_server_ind_evt
 * DESCRIPTION
 *  handles msg del ind from service
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_msg_deleted_by_server_ind_evt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_msg_deleted_by_server_ind_struct *evt_msg_del = (srv_wap_push_msg_deleted_by_server_ind_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_MSG_DELETED_BY_SERVER_IND);
    mmi_wap_push_update_inbox_selected_index ((S16)((evt_msg_del->count) * (-1)));

#ifdef __MMI_PUSH_IN_UM__
    srv_wap_push_send_um_refresh_ind(evt_msg_del->msg_id,SRV_UM_REFRESH_MSG_DELETED ,NULL);
#endif

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    if (mmi_wap_push_nmgr_active_on_idle())
    {
        mmi_wap_push_send_nmgr_refresh();
    }
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#ifdef __MMI_OP12_TOOLBAR__
    else if (mmi_wap_push_is_in_idle_state())
    {
        srv_wap_push_tb_evnt_query_push(MMI_TB_MAX_NEW_MESSAGE_NUM);
    }
#endif /* __MMI_OP12_TOOLBAR__ */
    
    if (mmi_wap_push_is_push_screen_active())
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_INFO, STR_ID_PUSH_INBOX_MODIFIED);
		mmi_frm_group_close (GRP_ID_BRW_PUSH_FROM_IDLE);
		mmi_frm_group_close (GRP_ID_BRW_PUSH_BODY);
		mmi_frm_group_close (GRP_ID_BRW_PUSH_POPUP);
		mmi_frm_group_close (GRP_ID_BRW_PUSH_POPUP_CONFIRM);
        return MMI_RET_OK; 
    }
    mmi_wap_push_handle_deleted_on_keypad_locked ();
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_del_push_setting_evt
 * DESCRIPTION
 *  Delete Push setting screens
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_del_push_setting_evt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_DELETE_PUSH_SETTING);
    mmi_wap_push_delete_previous_push_setting_instance_if_present();
    return MMI_RET_OK;
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_ota_list_entry_evt
 * DESCRIPTION
 *  OTA entry
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_ota_list_entry_evt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_OTA_LIST_ENTRY);
    if(!mmi_wap_push_is_screen_present(SCR_ID_PUSH_INBOX))
    {
	    g_push_inbox_ctxt->title_icon_id = 0;
    }
    g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_OPTION;
    mmi_wap_push_entry_list_screen();
    return MMI_RET_OK;
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_msg_on_idle
 * DESCRIPTION
 *  This function handles the message response got for IDLE screen pending event handling
 * PARAMETERS
 *  new_msg        [IN]
 *  url            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_handle_msg_on_idle (pmg_detailed_msg_struct *new_msg, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_scr_id = mmi_frm_scrn_get_active_id();
    #ifdef __MMI_NCENTER_SUPPORT__
	mshow=MMI_TRUE;
    #endif
    switch(new_msg->msg_type)
    {
    case WAP_PMG_MSGTYPE_SL:
#ifndef __MMI_NCENTER_SUPPORT__
        if (active_scr_id == SCR_ID_BRW_PUSH_DUMMY_SCREEN)
#endif
        {
            srv_wap_push_delete_from_msg_queue(new_msg->msg_id);
            mmi_wap_push_launch_sl (new_msg->msg_id, url, new_msg->sim_id);
        }

        break;
    case WAP_PMG_MSGTYPE_SI:

       #ifndef __MMI_NCENTER_SUPPORT__
        if (active_scr_id == SCR_ID_BRW_PUSH_DUMMY_SCREEN)
	   #endif
        {
            g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;

			MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_ENTER_DISPLAY_MESSAGE);
			srv_wap_push_copy_data_to_selected_message(new_msg, url);
			srv_wap_push_update_service_msg_req(new_msg->msg_id);
			srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
			MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_EXIT_DISPLAY_MESSAGE);
       #ifndef __MMI_NCENTER_SUPPORT__
            mmi_wap_push_display_msg (GRP_ID_BRW_PUSH_FROM_IDLE /*g_push_cntxt->scr_grp_id*/);
#else
            mmi_wap_push_display_msg (GRP_ID_ROOT/*GRP_ID_BRW_PUSH_FROM_IDLE g_push_cntxt->scr_grp_id*/);
#endif

            srv_wap_push_delete_from_msg_queue(new_msg->msg_id);
        }

        break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_full_msg_evt
 * DESCRIPTION
 *  handles full message
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_full_msg_evt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_handle_msg_struct *evt_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_HANDLE_FULL_MSG);
    evt_msg = (srv_wap_push_handle_msg_struct*)evt;
    if(evt_msg->status == WAP_PMG_STATUS_OK)
    {
        switch(evt_msg->trans_id)
        {
            case PUSH_GET_MSG_ON_IDLE_TRANS_ID:
                mmi_wap_push_handle_msg_on_idle(evt_msg->new_msg, evt_msg->url);
                break;
            case PUSH_GET_MSG_TO_DISPLAY_TRANS_ID:
                mmi_wap_push_handle_display_msg (evt_msg->new_msg, evt_msg->url, MMI_FALSE);
                  #ifdef __MMI_NCENTER_SUPPORT__
                    #ifdef __MMI_PUSH_IN_MSG__
                mmi_wap_push_ncenter_unread_messages();
                    #endif
                  #endif
                break;
            case PUSH_GET_MSG_TO_DISPLAY_FROM_UM_TRANS_ID:
            #ifdef __MMI_PUSH_IN_UM__
                mmi_wap_push_handle_msg_display_from_um (evt_msg->new_msg, evt_msg->url, MMI_TRUE);
            #endif /* __MMI_PUSH_IN_UM__ */
             #ifdef __MMI_NCENTER_SUPPORT__
                    #ifdef __MMI_PUSH_IN_UM__
                       srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    				   srv_wap_push_send_um_refresh_ind(evt_msg->new_msg->msg_id,SRV_UM_REFRESH_MSG_STATUS_CHANGED ,NULL);
                     #endif /* __MMI_PUSH_IN_UM__ */
              #endif

                break;
            #ifdef __MMI_OP12_TOOLBAR__
            case PUSH_GET_MSG_DATA_FOR_TB_TRANS_ID:
	            mmi_wap_push_handle_msg_for_toolbar(evt_msg->new_msg, evt_msg->url);
	            break;
            #endif /* __MMI_OP12_TOOLBAR__ */
            
            default:
                MMI_ASSERT(0);
        }
    }
    else
    {
        if (evt_msg->trans_id == PUSH_GET_MSG_ON_IDLE_TRANS_ID)
        {
            srv_wap_push_idle_messge_queue_struct *message = NULL;
            message = srv_wap_push_get_first_msg ();
            srv_wap_push_delete_from_msg_queue(message->message_id);
            mmi_wap_push_entry_idle_screen();
        }
        else
        {
            mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE);
            mmi_wap_push_delete_screen_if_present(SCR_ID_PUSH_GENERIC_PROCESSING);
        }
    }
    return MMI_RET_OK;
}

/* To be combined into 1 event */
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_full_msg_evt
 * DESCRIPTION
 *  handles full message
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_wap_push_launch_sl (U32 message_id, S8 *message_url, U32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_LAUNCHING_SL_MESSAGES_MESSAGE_ID, message_id);
    mmi_wap_push_load_service_message_url ((U8 *) message_url,  sim_id, WAP_PMG_MSGTYPE_SL,  message_id);
	#ifdef __MMI_NCENTER_SUPPORT__
	//srv_wap_push_delete_from_msg_queue(message_id);
	if(g_srv_wap_push_cntxt->message_queue_front != NULL)
    {
      mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_MMS, mmi_wap_push_ncenter_msg_queue_handler, (void *)NULL);

    }
    #endif
	

    

	
}

void mmi_wap_push_handle_sl_on_non_idle (srv_wap_push_handle_sl_on_non_idle_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_handle_sl_on_non_idle_struct* evt_sl_non_idle = evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SL_MESSAGES_ON_NON_IDLE, evt_sl_non_idle->message_id);
    switch(evt_sl_non_idle->sl_setting)
    {
    case SRV_WAP_PUSH_SL_SETTING_DISABLED:
        srv_wap_push_send_del_req_to_pmg (evt_sl_non_idle->message_id, PUSH_NEW_MSG_DEL_TRANS_ID);
        break;
    case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
        if (srv_wap_push_enque_msg_ex (evt_sl_non_idle->message_id, WAP_PMG_MSGTYPE_SL,(S8 *)evt_sl_non_idle->addr))
        {
            mmi_wap_push_update_inbox_selected_index (1);
            mmi_wap_push_nmgr_send_new_event_notify((S16)evt_sl_non_idle->sim_id, MMI_TRUE);
        #ifdef __MMI_PUSH_IN_UM__
            srv_wap_push_send_um_new_msg_ind(
                evt_sl_non_idle->message_id, 
                evt_sl_non_idle->timestamp, 
                (U16)evt_sl_non_idle->sim_id);
        #endif
        }
        else
        {
            mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
            srv_wap_push_send_del_req_to_pmg (evt_sl_non_idle->message_id, PUSH_NEW_MSG_DEL_TRANS_ID);
        }
        break;
    case SRV_WAP_PUSH_SL_SETTING_PROMPT:
        mmi_wap_push_update_inbox_selected_index (1);
        mmi_wap_push_nmgr_send_new_event_notify((S16)evt_sl_non_idle->sim_id, MMI_FALSE);
    #ifdef __MMI_PUSH_IN_UM__
        srv_wap_push_send_um_new_msg_ind(evt_sl_non_idle->message_id, evt_sl_non_idle->timestamp, (U16)evt_sl_non_idle->sim_id);
    #endif
        
        break;
    }
}


void mmi_wap_push_handle_sl_on_idle (srv_wap_push_handle_sl_on_idle_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 message_url [WAP_PMG_MAX_MSG_HREF_CHARS + 1] = {'\0',};
    srv_wap_push_handle_sl_on_idle_struct* evt_sl_idle = evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SL_MESSAGES_ON_IDLE, evt_sl_idle->message_id);
    switch(evt_sl_idle->sl_setting)
    {
    case SRV_WAP_PUSH_SL_SETTING_DISABLED:
        srv_wap_push_send_del_req_to_pmg (evt_sl_idle->message_id, PUSH_NEW_MSG_DEL_TRANS_ID);
        break;
    case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
        if (IsKeyPadLockState() != 0)
        {
            if (!srv_wap_push_enque_msg_ex (evt_sl_idle->message_id, WAP_PMG_MSGTYPE_SL,(S8 *)evt_sl_idle->addr))
            {
                mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
                srv_wap_push_send_del_req_to_pmg (evt_sl_idle->message_id, PUSH_NEW_MSG_DEL_TRANS_ID);
            }
            else
            {
                mmi_wap_push_nmgr_send_new_event_notify((S16)evt_sl_idle->sim_id, MMI_TRUE);
                return;
            }
        }
        else
        {
			mmi_wap_push_nmgr_send_new_event_notify((S16)evt_sl_idle->sim_id, MMI_TRUE);
            if ((evt_sl_idle->url != NULL) && (strlen (evt_sl_idle->url) != 0))
            {
                strncpy (message_url, evt_sl_idle->url, WAP_PMG_MAX_MSG_HREF_CHARS);
            }
            mmi_wap_push_launch_sl (evt_sl_idle->message_id, message_url, evt_sl_idle->sim_id);
        }
        break;
    case SRV_WAP_PUSH_SL_SETTING_PROMPT:
    #ifdef __MMI_PUSH_IN_UM__
        srv_wap_push_send_um_new_msg_ind(evt_sl_idle->message_id, evt_sl_idle->timestamp, (U16)evt_sl_idle->sim_id);
    #endif /* __MMI_PUSH_IN_UM__ */
	    mmi_wap_push_nmgr_send_new_event_notify((S16)evt_sl_idle->sim_id, MMI_FALSE);
        break;
    }
}
/* Handle of combining into 1 event */


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_msg_list_reply
 * DESCRIPTION
 *  handles reply response
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_msg_list_reply(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_msg_list_reply_struct *evt_msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_MSG_LIST_REPLY);
    evt_msg_list = (srv_wap_push_msg_list_reply_struct*)evt;
    switch (evt_msg_list->trans_id)
    {
        case PUSH_MSG_LIST_INBOX_DSPLY_TRANS_ID:
            mmi_wap_push_add_to_msg_list (&(evt_msg_list->msg_list));
            break;
    #ifdef __MMI_OP12_TOOLBAR__
        case PUSH_TB_UNREAD_MSG_LIST_TRANS_ID:
            mmi_wap_push_handle_list_for_toolbar(*(evt_msg_list->msg_list));
            break;
    #endif /* __MMI_OP12_TOOLBAR__ */
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_msg_cnt_rsp
 * DESCRIPTION
 *  handles msg count response
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_msg_cnt_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_msg_count_rsp_struct *evt_msg_cnt;
    U16 total_message = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt_msg_cnt = (srv_wap_push_msg_count_rsp_struct *)evt;
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_MSG_COUNT_RSP);
    total_message = (evt_msg_cnt->msg_rsp)->msg_count_sim1;
#if (MMI_MAX_SIM_NUM >= 2)
    total_message += (evt_msg_cnt->msg_rsp)->msg_count_sim2;
//    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_RECV_MSG_CNT_SIM2, (U16)msg_rsp->msg_count_sim2);
	#if(MMI_MAX_SIM_NUM >= 3)
    total_message += (evt_msg_cnt->msg_rsp)->msg_count_sim3;
   #endif
	#if(MMI_MAX_SIM_NUM >= 4)
	  total_message += (evt_msg_cnt->msg_rsp)->msg_count_sim4;

  #endif
#endif /* __MMI_WAP_DUAL_SIM__ */
    switch (evt_msg_cnt->trans_id)
    {
	    case PUSH_UPDATE_ICON_AND_TB_STATUS_AT_BOOT_TRANS_ID:
		    srv_wap_push_update_status_icon_default_sim (total_message);
          
	        #ifdef __MMI_OP12_TOOLBAR__
		    if (g_push_cntxt->is_tb_active)
            {
                g_push_cntxt->is_tb_active = MMI_FALSE;
		        srv_wap_push_tb_evnt_query_push((S32)g_push_cntxt->tb_num_of_req);
		    }
	        #endif /* __MMI_OP12_TOOLBAR__ */
		    break;
        case PUSH_UPDATE_ICON_TRANS_ID:
            srv_wap_push_update_status_icon_default_sim (total_message);
        
            break;
    #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
       #if (MMI_MAX_SIM_NUM >= 2)
        case PUSH_NMGR_UNREAD_MSG_CNT_TRANS_ID:
            mmi_wap_push_nmgr_send_answer(total_message, WAP_PMG_SIM1);
            break;
	#if (MMI_MAX_SIM_NUM >= 3)
	    case PUSH_NMGR_UNREAD_COUNT_FOR_SIM3_TRANS_ID:
            mmi_wap_push_nmgr_send_answer(total_message, WAP_PMG_SIM3);
            break;
	 #endif
	#if (MMI_MAX_SIM_NUM >= 4)
	     case PUSH_NMGR_UNREAD_COUNT_FOR_SIM4_TRANS_ID:
            mmi_wap_push_nmgr_send_answer(total_message, WAP_PMG_SIM4);
            break;
			#endif
        case PUSH_NMGR_UNREAD_COUNT_FOR_SIM2_TRANS_ID:
            mmi_wap_push_nmgr_send_answer(total_message, WAP_PMG_SIM2);
            break;
        #else /* __MMI_WAP_DUAL_SIM__ */
        case PUSH_NMGR_UNREAD_MSG_CNT_TRANS_ID:
            mmi_wap_push_nmgr_send_answer(total_message, WAP_PMG_SIM_DEFAULT);
            break;
        #endif /* __MMI_WAP_DUAL_SIM__ */

        #endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

        case PUSH_DISPLAY_INBOX_COUNT_TRANS_ID:
            mmi_wap_push_display_inbox (total_message);
            break;
	    #ifdef __MMI_OP12_TOOLBAR__
        case PUSH_TB_UNREAD_MSG_CNT_TRANS_ID:
            MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_TB_GOT_UNREAD_COUNT_FROM_PMG, total_message);
            mmi_wap_push_handle_count_rsp_for_tb(total_message);
		    break;
        #endif /* __MMI_OP12_TOOLBAR__ */
    }    
#ifdef __MMI_NCENTER_SUPPORT__
   #ifdef __MMI_PUSH_IN_MSG__
         mmi_wap_push_ncenter_unread_messages();
   #endif
#endif
    return MMI_RET_OK;
}

#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_draw_unknown_scren
 * DESCRIPTION
 *  draw unknown screen
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_draw_unknown_scren(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_DRAW_UNKNOWN);
    mmi_wap_push_scrhdlr_entry_sia_dlg_display();
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_draw_sia_scren
 * DESCRIPTION
 *  draw sia screen
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_draw_sia_scren(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_wap_push_scrhdlr_entry_sia_dlg_display();
    return MMI_RET_OK;
}
#endif
#ifndef __MMI_WAP_PUSH_SIA_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_service_initiation_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_service_initiation_req(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifndef __MMI_NCENTER_SUPPORT__
    srv_wap_push_service_init_struct *evt_init = (srv_wap_push_service_init_struct*)evt;
	wps_pmg_dlg_sia_confirm_req_struct *data = (wps_pmg_dlg_sia_confirm_req_struct*) (evt_init->msg);
    #else
    srv_wap_push_service_init_struct *nevt= (srv_wap_push_service_init_struct*)evt;
	wps_pmg_dlg_sia_confirm_req_struct *data = (wps_pmg_dlg_sia_confirm_req_struct*) (nevt->msg);
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_UNKNOWN_DILOGUE_REQ_FOR_TRANS_ID, data->trans_id);
	#ifndef __MMI_NCENTER_SUPPORT__
    mmi_wap_push_turn_on_back_light();

	if (mmi_wap_push_is_in_idle_state() || (SCR_ID_BRW_PUSH_DUMMY_SCREEN == mmi_frm_scrn_get_active_id()))
	{
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SIA_RECEIVED_ON_IDLE);
		srv_wap_push_initialize_curr_dlg_data((void*)data, WAP_PMG_DLG_SIA_CONFIRM);
        if (IsKeyPadLockState() == 0)
        {
          //  mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_MMS, mmi_wap_push_draw_sia_scren, (void *)NULL);
			 mmi_wap_push_nss_alert_sia();
        }
        else
        {
		    if (srv_wap_push_enque_dialogue(data->trans_id, WAP_PMG_DLG_SIA_CONFIRM))
            {
                mmi_wap_push_nmgr_send_new_event_notify((S16)WAP_PMG_SIM_DEFAULT, MMI_TRUE); /* Vikas -- Need recheck */
                return;
            }
            else
            {
                mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
                srv_wap_push_send_sia_cnf(FALSE, data->trans_id);
            }
        }
	}
	else
	{
		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SIA_REQ_QUEUED);
		if (srv_wap_push_enque_dialogue(data->trans_id, WAP_PMG_DLG_SIA_CONFIRM))
        {
            mmi_wap_push_display_new_msg_popup(STR_ID_BRW_NEW_PUSH_MESSAGE);
        }
        else
        {
            mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
            srv_wap_push_send_sia_cnf(FALSE, data->trans_id);
        }
	}
    #else
	       
   
			
		mmi_wap_push_update_ncenter_sia((mmi_event_struct*)data);
							if(g_srv_wap_push_cntxt->curr_dlg)
		             	             mmi_wap_push_nss_alert_sia();
		                    

		 
   #endif
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_dlg_data_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_dlg_data_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_NCENTER_SUPPORT__
    srv_wap_push_handle_dlg_data_rsp_struct *evt_dlg_data = (srv_wap_push_handle_dlg_data_rsp_struct*)evt;
    wps_pmg_dlg_query_cnf_struct *data = (wps_pmg_dlg_query_cnf_struct*) evt_dlg_data->msg;
    #else
		srv_wap_push_handle_dlg_data_rsp_struct *nevt = (srv_wap_push_handle_dlg_data_rsp_struct*)evt;
        wps_pmg_dlg_query_cnf_struct *data = (wps_pmg_dlg_query_cnf_struct*) nevt->msg;
    #endif
    
    mmi_group_node_struct node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_HANDLE_DLG_DATA_RSP);
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_GOT_DLG_DATA_RSP);
	#ifndef __MMI_NCENTER_SUPPORT__
	if (mmi_frm_group_get_info (GRP_ID_BRW_PUSH_FROM_IDLE, &node_info)!= MMI_RET_ERR)
    {
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_GOT_DLG_DATA_RSP_ON_DUMMY);

    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        if (data->dlg_type == WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM)
        {
	        srv_wap_push_initialize_curr_dlg_data((void*)(&(data->dlg_data_union.msg)), WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM);
	        mmi_wap_push_scrhdlr_entry_sia_dlg_display(); 
        }
        else if (data->dlg_type == WAP_PMG_DLG_SIA_CONFIRM)
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
        {
	        srv_wap_push_initialize_curr_dlg_data((void*)(&(data->dlg_data_union.sia)), WAP_PMG_DLG_SIA_CONFIRM);
	        mmi_wap_push_scrhdlr_entry_sia_dlg_display(); 
        }
        srv_wap_push_delete_from_dlg_queue(data->dlg_trans_id);
    }
    
#else 
      #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        if (data->dlg_type == WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM)
        {
	       
			mmi_wap_push_update_ncenter_unknown((mmi_event_struct*)&(data->dlg_data_union.msg));

        }
		 else if (data->dlg_type == WAP_PMG_DLG_SIA_CONFIRM)
		 #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
        {
	       
			mmi_wap_push_update_ncenter_sia((mmi_event_struct*)&(data->dlg_data_union.sia));
        }
        
#endif
	
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_storage_full_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_storage_full_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
    srv_wap_push_handle_storage_full_ind_struct *evt_storage_full = (srv_wap_push_handle_storage_full_ind_struct*)evt;
    wps_pmg_delete_ind_struct *delete_msg_ind = evt_storage_full->msg;
#endif /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
    if (delete_msg_ind->msgs[0].msg_id == 0)
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_INFO, STR_ID_PUSH_STORAGE_FULL); 
        return MMI_RET_OK;
    }
    srv_wap_push_delete_from_msg_queue(delete_msg_ind->msgs[0].msg_id);
    mmi_wap_push_add_msg_deleted_screen_in_history();
#else /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */
	mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_INFO, STR_ID_PUSH_STORAGE_FULL); 
#endif /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_delete_folder_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_delete_folder_ind(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_folder_ind_struct *evt_del_folder = (srv_wap_push_delete_folder_ind_struct*)evt;    
	wps_pmg_delete_folder_ind_struct *MsgData = evt_del_folder->msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_HANDLE_DELETE_FOLDER_IND);
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_RECEIVE_DEL_FOLDER_IND, MsgData->folder);
    if (MsgData->folder == WAP_PMG_FOLDER_INBOX)
    {
        srv_wap_push_delete_all_queue_entry();
        mmi_brw_push_delete_previous_instance_of_push();
        srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_pendig_event_on_idle
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_pendig_event_on_idle(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    srv_wap_push_handle_pendig_event_on_idle_struct* evt_pendig = (srv_wap_push_handle_pendig_event_on_idle_struct*)evt;
    srv_wap_push_idle_messge_queue_struct *message = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_create_idle_callback_group();
    if (IsKeyPadLockState() == 0)
    {
        if (g_srv_wap_push_cntxt->message_queue_front != NULL)
        {
            mmi_wap_push_draw_dummy_screen(MMI_TRUE);
            message = srv_wap_push_get_first_msg ();
            MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_IDLE_FOUND_PENDING_MESSAGE, message->message_id);
            srv_wap_push_get_full_message (message->message_id, PUSH_GET_MSG_ON_IDLE_TRANS_ID);
        #ifdef __MMI_PUSH_IN_UM__
            g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
        #endif /* __MMI_PUSH_IN_UM__ */
        }
        else
        {
            ASSERT(0);
        }
    }
    else    /* keypad is locked */
    {
        mmi_wap_push_scrhdlr_entry_new_msg_ind_screen();
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fetch_dlg_from_queue
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_fetch_dlg_from_queue(mmi_event_struct *evt)
{
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_wap_push_create_idle_callback_group();
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HDL_IDLE_CALLBACK_FOR_DLG_REQ);
    if (IsKeyPadLockState() == 0)
    {
        mmi_wap_push_draw_dummy_screen(MMI_TRUE);
        srv_wap_push_get_dlg_data_req(g_srv_wap_push_cntxt->dlg_front->trans_id);
    }
    else
    {
        mmi_wap_push_scrhdlr_entry_new_msg_ind_screen();
    }
  #endif
return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fetch_dlg_from_queue
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_inbox_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_INBOX_INIT);
    g_push_cntxt = (mmi_wap_push_context_struct*) srv_wap_push_malloc(sizeof(mmi_wap_push_context_struct));
    if (g_push_cntxt == NULL)
    {
        ASSERT(0);
    }
    memset (g_push_cntxt, 0, sizeof(mmi_wap_push_context_struct));
//    g_push_cntxt->notify_nmgr = MMI_BRW_PUSH_NOTIFY_NMGR_NOT_NOTIFY;
    srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY);
    g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
    g_push_cntxt->inline_gid = GRP_ID_INVALID;

	srv_wap_push_init_service_interface();
	srv_wap_push_setting_init();
    mmi_wap_push_ui_init();
#if 0
#ifdef __MMI_PUSH_IN_UM__
/* under construction !*/
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_PUSH_IN_UM__ */
#endif /*0 */
#ifdef __MMI_NCENTER_SUPPORT__
    #ifdef __MMI_PUSH_IN_MSG__
        mmi_wap_push_nmgr_get_unread_msg();
    #endif
#endif

#ifdef __DM_LAWMO_SUPPORT__ 
    if (mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_PUSH, MMI_DMUI_MO_TYPE_LAWMO_WIPE, srv_wap_push_handle_lawmo_request) < 0)
    {
        /* error handling or assert */
        ASSERT(0);
    }
#endif /* __DM_LAWMO_SUPPORT__ */
return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fetch_dlg_from_queue
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_display_msg(U16 grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_wap_push_scrhdlr_entry_message_display_group(grp_id);
    return MMI_RET_OK;
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_service_unknown_addr_req
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wap_push_service_unknown_addr_req(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifndef __MMI_NCENTER_SUPPORT__
    srv_wap_push_service_unknown_addr_req_struct* evt_unknown_addr 
        = (srv_wap_push_service_unknown_addr_req_struct*)evt;
	wps_pmg_dlg_unknown_addr_req_struct *data = evt_unknown_addr->msg;
    #else
	srv_wap_push_service_unknown_addr_req_struct *nevt
		=(srv_wap_push_service_unknown_addr_req_struct*)evt;
	wps_pmg_dlg_unknown_addr_req_struct *data = nevt->msg;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_UNKNOWN_ADDR_REQ);
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_SIA_REQ_FOR_TRANS_ID, data->trans_id);
	#ifndef __MMI_NCENTER_SUPPORT__
    mmi_wap_push_turn_on_back_light();
	if (mmi_wap_push_is_in_idle_state() || (SCR_ID_BRW_PUSH_DUMMY_SCREEN == mmi_frm_scrn_get_active_id()))
	{
        MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_UNKNWN_DLG_RECEIVED_ON_IDLE);
		srv_wap_push_initialize_curr_dlg_data((void*)evt_unknown_addr->msg, WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM);
        if (IsKeyPadLockState() == 0)
        {

			  mmi_wap_push_nss_alert_unknown();
        }
        else
        {
		    if (srv_wap_push_enque_dialogue(data->trans_id, WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM))
            {
                mmi_wap_push_nmgr_send_new_event_notify((S16)WAP_PMG_SIM_DEFAULT, MMI_TRUE); /* Vikas -- Need recheck */
                return;
            }
            else
            {
                mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
                srv_wap_push_send_unknwn_addr_cnf(FALSE, data->trans_id);
            }
        }
	}
	else
	{
		MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_UNKNOWN_DILOGUE_REQ_QUEUED);
		if (srv_wap_push_enque_dialogue(data->trans_id, WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM))
        {
            mmi_wap_push_display_new_msg_popup(STR_ID_PUSH_NEW_UNKNOWN_MSG);
        }
        else
        {
            mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_PROPLEM, STR_GLOBAL_MEMORY_FULL);
            srv_wap_push_send_unknwn_addr_cnf(FALSE, data->trans_id);
        }
	}
    #else
	    mmi_wap_push_update_ncenter_unknown((mmi_event_struct*)data);
	    if(g_srv_wap_push_cntxt->curr_dlg) 
	            mmi_wap_push_nss_alert_unknown();
	    
	  
	  
	#endif
    return MMI_RET_OK;
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_mode_finish_switch_event_hdlr
 * DESCRIPTION
 *  handles mode switch
 * PARAMETERS
 *  mmi_event_struct        
 * RETURNS
 *  MMIRESULTENUM
 *****************************************************************************/
mmi_ret mmi_wap_push_mode_finish_switch_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *switch_notify = (srv_mode_switch_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	

    if(!srv_get_push_unread_count())
    {
            #ifndef __MMI_PUSH_IN_UM__
      //  wgui_status_icon_bar_hide_icon(STATUS_ICON_WAP);
                if(srv_wap_push_get_nmgr_unread_handler())
		mmi_frm_nmgr_alert_cancel (srv_wap_push_get_nmgr_unread_handler());
            #endif
    }

    return MMI_OK;
}

#ifdef __SIM_HOT_SWAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_if_sim_event_detected_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  0.
 *****************************************************************************/
mmi_ret mmi_wap_push_if_sim_event_detected_proc(mmi_event_struct *evt)
{
		
        if(srv_get_push_unread_count())
		 {

			 #ifndef __MMI_PUSH_IN_UM__
         // ShowStatusIcon(STATUS_ICON_WAP);
			  U32 handler;
			  mmi_frm_nmgr_alert_struct alert_info;
			  memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   
				/*fill in app id for NSS query*/
               alert_info.app_id = APP_MMI_WAP_PUSH; //your app id
                /*fill in the basic info*/
             alert_info.scen_id = MMI_SCENARIO_ID_WAP_PUSH; // your scenario ID
             alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
             alert_info.status_bar_icon_para.icon_id = STATUS_ICON_WAP;
             alert_info.behavior_mask = FORCE_ICON_ONLY;
             alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE| MMI_FRM_NMGR_DISABLE_VIB;
             handler=mmi_frm_nmgr_alert(&alert_info); 
			 srv_wap_push_set_nmgr_unread_handler(handler);
             #endif

		} 
	
        else  
		{
         // HideStatusIcon(STATUS_ICON_WAP);
		  	#ifndef __MMI_PUSH_IN_UM__
			if(srv_wap_push_get_nmgr_unread_handler())
              mmi_frm_nmgr_alert_cancel (srv_wap_push_get_nmgr_unread_handler());
            #endif
		}
 //   }
 //   UpdateStatusIcons();
    return MMI_RET_OK;
}
#endif
/**********************************************************************************************************/
/*                                       Unified push code Ends                                           */
/**********************************************************************************************************/
#ifdef __MMI_PUSH_IN_MSG__
mmi_ret mmi_wap_push_nss_unread_popup(mmi_event_struct *evt)
{

    switch(evt->evt_id)
	 {
	 case EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH :
		 
	 case EVT_ID_NMGR_POPUP_APP_LAUNCH :
		 mmi_brw_push_pre_entry_inbox_validation();
         break;
	 case EVT_ID_NMGR_ALERT_END :
		 
		break;
	 default:
		 break;
	 }
   return MMI_RET_OK;
}
#endif
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
mmi_ret mmi_wap_push_sia_dlg_func(mmi_event_struct *evt)
    {
     #ifdef __MMI_NCENTER_SUPPORT__
     if(!nshow)
	  {
     #endif
     switch(evt->evt_id)
	 {
	 case EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH :
		 
	 case EVT_ID_NMGR_POPUP_APP_LAUNCH :
		{
		 mmi_wap_push_scrhdlr_entry_sia_dlg_display();
		 if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_SIA_CONFIRM)	
		         srv_wap_push_delete_from_dlg_queue(g_srv_wap_push_cntxt->curr_dlg->dlg_data.sia.trans_id);
	         if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM) 
		         srv_wap_push_delete_from_dlg_queue(g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
                 #ifdef __MMI_NCENTER_SUPPORT__
                    vsrv_ncenter_close_notification(nhandle_dlg);
                  #endif
                  break;
		 }
	 case EVT_ID_NMGR_ALERT_END :
		break;
	 default:
		 break;
	 }
	   #ifdef __MMI_NCENTER_SUPPORT__
	    }
     #endif
	 return MMI_RET_OK;
  }

void mmi_wap_push_nss_alert_sia()
{     
		                   WCHAR preview_text[100];
							  mmi_frm_nmgr_alert_struct alert_info;
                              memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   
                              /*fill in app id for NSS query*/
                               alert_info.app_id = APP_MMI_WAP_PUSH; //your app id
                              /*fill in the basic info*/
                              alert_info.scen_id = MMI_SCENARIO_ID_WAP_PUSH; // your scenario ID
                              alert_info.event_type = MMI_EVENT_MMS; // your event id
                              mmi_ucs2cpy((CHAR *)preview_text, (const CHAR *)GetString(STR_ID_PUSH_SIA_NOTIFICATION));
                              alert_info.status_bar_para.display_string = preview_text; /* fill text preview data */
	
          
                              alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
                              alert_info.behavior_mask = PREFER_STATUS_BAR; 
                              alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
                              alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
                              alert_info.status_bar_para.image.id = IMG_SI_WAP;
                            
							 alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
							 alert_info.popup_para.popup_string = (WCHAR*)GetString(STR_ID_PUSH_SIA_NOTIFICATION);
							 alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);
                              alert_info.app_proc_para.scrn_group_proc= &mmi_wap_push_sia_dlg_func;
                             alert_info.app_proc_para.user_data = NULL;	
                             alert_info.app_proc_para.data_size = 0;
                             g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);	
				
             
  }
void mmi_wap_push_nss_alert_unknown()
{                
	         #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                              WCHAR preview_text[100];
							  mmi_frm_nmgr_alert_struct alert_info;
                              memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   
                              /*fill in app id for NSS query*/
                               alert_info.app_id = APP_MMI_WAP_PUSH; //your app id
                              /*fill in the basic info*/
                              alert_info.scen_id = MMI_SCENARIO_ID_WAP_PUSH; // your scenario ID
                              alert_info.event_type = MMI_EVENT_MMS; // your event id
                              mmi_ucs2cpy((CHAR *)preview_text, (const CHAR *)GetString(STR_ID_PUSH_UNMATCHED_ADDR_NOTIFICATION));
                              alert_info.status_bar_para.display_string = preview_text; /* fill text preview data */

  
                              alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
                              alert_info.behavior_mask = PREFER_STATUS_BAR; 
                              alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
                               alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
                              alert_info.status_bar_para.image.id = IMG_SI_WAP;
                          
							       
							 alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
							 alert_info.popup_para.popup_string = (WCHAR*)GetString(STR_ID_PUSH_UNMATCHED_ADDR_NOTIFICATION);
							 alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);

                             alert_info.app_proc_para.scrn_group_proc= &mmi_wap_push_sia_dlg_func;
                             alert_info.app_proc_para.user_data = NULL;	
                             alert_info.app_proc_para.data_size = 0;
                             g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);	
             #endif

}
#endif
#ifdef __MMI_NCENTER_SUPPORT__

#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 	
void mmi_wap_push_intent_callback_unknown_sia(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
  {
      switch(intent.type)
	  {
	   case VSRV_NINTENT_TYPE_LAUNCH :

	   case VSRV_NINTENT_TYPE_TAP :
		 {
                               mmi_wap_push_scrhdlr_entry_sia_dlg_display();
           if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM)	
			 srv_wap_push_delete_from_dlg_queue(g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
            if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_SIA_CONFIRM)	
                        srv_wap_push_delete_from_dlg_queue(g_srv_wap_push_cntxt->curr_dlg->dlg_data.sia.trans_id);
             break;
        }
             
	   case  VSRV_NINTENT_TYPE_LANGUAGE_CHANGED:
               {
                    vsrv_ngroup_handle message_group = NULL;
                   WCHAR ctext[100];
                   message_group = vsrv_ncenter_query_ngroup(APP_UNIFIEDMESSAGE);
		           if (NULL == message_group)
                         message_group = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UNIFIEDMESSAGE);
	             
                    mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_PUSH_MAIN_MENU_MESSAGES_TEXT));    
                    vsrv_ncenter_set_ngroup_title_str(message_group, ctext);
                        
                   mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_WAP_PUSH_UNREAD_MSG));
                   vsrv_ncenter_set_notification_maintext_str(nhandle_dlg, ctext);
                   if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_SIA_CONFIRM)
                         mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_BRW_PUSH_SIA_REQ_TITLE));
                   #ifdef __MMI_WAP_PUSH_WHITE_LIST__     
                    if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM)          
                        mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_BRW_PUSH_UNMATCHED_ADDRESS));
                   #endif
                   vsrv_ncenter_set_notification_subtext_str(nhandle_dlg, ctext); 
                   vsrv_ncenter_notify_notification(nhandle_dlg); 
              }
	           break;
	   case VSRV_NINTENT_TYPE_CLEAR:
		   {
		     if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM) 
		           srv_wap_push_delete_from_dlg_queue(g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
			 if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_SIA_CONFIRM)
		               srv_wap_push_delete_from_dlg_queue(g_srv_wap_push_cntxt->curr_dlg->dlg_data.sia.trans_id);
				   mmi_wap_push_handle_rsk_on_sia_dlg_screen();
				   break;
		   }
	   default:
		   break;
        }
}

void mmi_wap_push_create_notification_unknown_sia()
                {
                         vsrv_ngroup_handle message_group = NULL;
		
                         WCHAR ctext[100];
                         message_group = vsrv_ncenter_query_ngroup(APP_UNIFIEDMESSAGE);
                        if (NULL == message_group)
                             message_group = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UNIFIEDMESSAGE);
		nhandle_dlg = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, message_group, EVT_ID_SRV_PUSH_UNKNOWN_ADDR_REQ);
		nshow= MMI_FALSE;
                        mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_PUSH_MAIN_MENU_MESSAGES_TEXT));    
                        vsrv_ncenter_set_ngroup_title_str(message_group, ctext);
                        
                        mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_WAP_PUSH_UNREAD_MSG));
                        vsrv_ncenter_set_notification_maintext_str(nhandle_dlg, ctext);
                       
       if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_SIA_CONFIRM)
                        mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_BRW_PUSH_SIA_REQ_TITLE));

       #ifdef __MMI_WAP_PUSH_WHITE_LIST__ 
       if(g_srv_wap_push_cntxt->curr_dlg->dlg_type==WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM)
              mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_BRW_PUSH_UNMATCHED_ADDRESS));
       #endif
       vsrv_ncenter_set_notification_subtext_str(nhandle_dlg, ctext);
		           
      	
     
}

mmi_ret mmi_wap_push_update_ncenter_unknown(mmi_event_struct *evt)
{
    wps_pmg_dlg_unknown_addr_req_struct *push_evt = (wps_pmg_dlg_unknown_addr_req_struct*) evt;
   

    if(nshow)
		{
         
		srv_wap_push_initialize_curr_dlg_data((void*)push_evt, WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM);
			 mmi_wap_push_create_notification_unknown_sia();	 
			 vsrv_ncenter_set_notification_intent_callback(nhandle_dlg, mmi_wap_push_intent_callback_unknown_sia, (void *)(push_evt), sizeof(push_evt));
        vsrv_ncenter_notify_notification(nhandle_dlg); 
                     
	  }

	else 
	{
		#ifdef __MMI_WAP_PUSH_WHITE_LIST__
		 if(!srv_wap_push_enque_dialogue(push_evt->trans_id, WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM))
			 srv_wap_push_send_unknwn_addr_cnf(FALSE, push_evt->trans_id);
		 #endif 

			 
	} 
		return MMI_RET_OK;
}




mmi_ret mmi_wap_push_update_ncenter_sia(mmi_event_struct *evt)
{
    wps_pmg_dlg_sia_confirm_req_struct *push_evt = (wps_pmg_dlg_sia_confirm_req_struct*) evt;
   

    
        if(nshow)
		{
		srv_wap_push_initialize_curr_dlg_data((void*)push_evt, WAP_PMG_DLG_SIA_CONFIRM);
			 mmi_wap_push_create_notification_unknown_sia();
			 vsrv_ncenter_set_notification_intent_callback(nhandle_dlg, mmi_wap_push_intent_callback_unknown_sia, (void *)(push_evt), sizeof(push_evt));
        vsrv_ncenter_notify_notification(nhandle_dlg); 

		 
		}
		else
		{
		 
		 if(!srv_wap_push_enque_dialogue(push_evt->trans_id, WAP_PMG_DLG_SIA_CONFIRM))
			   srv_wap_push_send_sia_cnf(FALSE, push_evt->trans_id);
	   }



		return MMI_RET_OK;
}
#endif

mmi_ret mmi_wap_push_ncenter_msg_queue_handler(mmi_event_struct *evt)
{
	
	    
	srv_wap_push_idle_messge_queue_struct *message = NULL;
	mshow=MMI_TRUE;

        if (g_srv_wap_push_cntxt->message_queue_front != NULL)
        {
        
            message = srv_wap_push_get_first_msg ();
            srv_wap_push_get_full_message (message->message_id, PUSH_GET_MSG_ON_IDLE_TRANS_ID);
        #ifdef __MMI_PUSH_IN_UM__
            g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
        #endif /* __MMI_PUSH_IN_UM__ */
          mshow=MMI_FALSE;
        }
        
       return MMI_RET_OK;
 

}
#ifdef __MMI_PUSH_IN_MSG__

void  mmi_wap_push_intent_callback_unread(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
	 
     switch(intent.type)
     {
	 case VSRV_NINTENT_TYPE_LAUNCH :
         
	 case VSRV_NINTENT_TYPE_TAP :
							{
        mmi_brw_push_pre_entry_inbox_validation();
        mmi_wap_push_ncenter_unread_messages();
      						}
							break;
      	
	 case VSRV_NINTENT_TYPE_LANGUAGE_CHANGED :
                                  break;
	 default :
		 break;
     }

}

void mmi_wap_push_ncenter_unread_messages()
{
     
     if(g_srv_wap_push_cntxt->unread_msgs_count)
      {
        
        mmi_event_struct evt = {0,}; 
        vsrv_ngroup_handle message_group = NULL;
         
       // mmi_image_src_struct push_icon;       
       
        WCHAR ctext[100];
        WCHAR sub_text[100];
	    
        
        message_group = vsrv_ncenter_query_ngroup(APP_UNIFIEDMESSAGE);
        if (NULL == message_group)
                message_group = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UNIFIEDMESSAGE);
        nhandle_unread = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, message_group, EVT_ID_SRV_PUSH_SHOW_PROGRESS);
	    evt.evt_id=EVT_ID_SRV_PUSH_SHOW_PROGRESS;
        evt.size=sizeof(EVT_ID_SRV_PUSH_SHOW_PROGRESS);
        evt.user_data=NULL;
        mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_PUSH_MAIN_MENU_MESSAGES_TEXT));    
        vsrv_ncenter_set_ngroup_title_str(message_group, ctext);
                        
        mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_WAP_PUSH_UNREAD_MSG));
        vsrv_ncenter_set_notification_maintext_str(nhandle_unread, ctext);
        
       // push_icon.type=MMI_IMAGE_SRC_TYPE_RES_ID;
	   // push_icon.data.res_id=IMG_ID_BRW_PUSH_MESSAGE_ICON;
                       
       // vsrv_ncenter_set_notification_icon(  nhandle_unread, push_icon);                    
        mmi_wsprintf(
                sub_text, 
                100, 
                STR_ID_WAP_PUSH_UNREAD_MSG_NUMBER_ID, 
                g_srv_wap_push_cntxt->unread_msgs_count);
        vsrv_ncenter_set_notification_subtext_str(nhandle_unread, sub_text);
		

        vsrv_ncenter_set_notification_intent_callback(nhandle_unread, mmi_wap_push_intent_callback_unread, (void *)(&evt), sizeof(&evt));

	

        vsrv_ncenter_notify_notification(nhandle_unread); 
     } 	

	 else 
        vsrv_ncenter_close_notification(nhandle_unread);

}
#endif /* __MMI_PUSH_IN_MSG__*/

#endif /* __MMI_NCENTER_SUPPORT__ */

#endif /* WAP_SUPPORT */
