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
 * NfcSetting.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for mmi configure NFC setting
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __NFC_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "usbsrvgprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "NotificationGprot.h"

/* auto add by kw_check begin */
#include "kal_general_types.h"
#include "menucuigprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "gui_data_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_srv_dtcnt_def.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "wndrv_cnst.h"
#include "string.h"
#include "mmi_rp_app_nfc_def.h"
#include "nvram_common_defs.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "GlobalDefs.h"
#include "mmi_rp_app_mode_switch_def.h"
#include "mtk_nfc_ext_msg.h"
#include "custom_events_notify.h"

/**********
Global variable
**********/
static U8 g_mmi_nfc_status;

void mmi_nfc_entry_main_menu(void);
void mmi_nfc_main_hilight_handler(void);
static void mmi_nfc_entry_progress_screen(void);
static mmi_ret mmi_nfc_set_nvram_status(U8 status);
static U8 mmi_nfc_get_nvram_status(void);
static void mmi_nfc_main_menu_init(mmi_id cui_id);
static mmi_ret mmi_nfc_entry_main_menu_proc(mmi_event_struct *evt);
static void mmi_nfc_lib_init_rsp(void *msg);
static void mmi_nfc_lib_deinit_rsp(void *msg);
static void mmi_nfc_lib_error_notify_rsp(void *msg);

static mmi_ret mmi_nfc_sent_msg_to_nfc_lib(U8 status);
static void mmi_nfc_update_idle_icon_status(U8 status);


/*********
local function
*********/

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_setting_init
 * DESCRIPTION
 *  nfc boot up init function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nfc_setting_init(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 status = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

		status = mmi_nfc_get_nvram_status();
	
    SetProtocolEventHandler(mmi_nfc_lib_init_rsp, MSG_ID_NFC_LIB_INIT_RSP);
    SetProtocolEventHandler(mmi_nfc_lib_deinit_rsp, MSG_ID_NFC_LIB_DEINIT_RSP);
    SetProtocolEventHandler(mmi_nfc_lib_error_notify_rsp, MSG_ID_NFC_LIB_MMI_EVENT_NOTIFY);
    if (status)
    {
	    mmi_nfc_sent_msg_to_nfc_lib(status);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_sent_msg_to_nfc_lib
 * DESCRIPTION
 *  Send nfc setting status to nfc lib module
 * PARAMETERS
 *  status
 *	0: off
 *	1: on
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_nfc_sent_msg_to_nfc_lib(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if(status)
	{
    	mmi_frm_send_ilm(MOD_NFC, MSG_ID_NFC_LIB_INIT_REQ, NULL, NULL);
	}
	else
	{
		mmi_frm_send_ilm(MOD_NFC, MSG_ID_NFC_LIB_DEINIT_REQ, NULL, NULL);
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_lib_init_rsp
 * DESCRIPTION
 *  This function to process response from module NFC
 * PARAMETERS
 *  msg
 *	nfc_init_init_rsp_struct
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nfc_lib_init_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nfc_init_deinit_rsp_struct *msg_info =  (nfc_init_deinit_rsp_struct *)msg;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_group_is_present(GRP_ID_NFC_SETTINGS))
	{
	if(msg_info->action_result == 1)
	{
		mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
	}
	else
	{
		mmi_popup_display_simple((WCHAR*)GetString(STR_ID_NFC_ON_ERR), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	}
		mmi_frm_scrn_close(GRP_ID_NFC_SETTINGS, SCR_ID_NFC_PROGRESS);
		mmi_frm_group_close(GRP_ID_NFC_SETTINGS);
	}
	mmi_nfc_update_idle_icon_status(msg_info->action_result);
	mmi_nfc_set_nvram_status(msg_info->action_result);
	g_mmi_nfc_status = msg_info->action_result;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_lib_deinit_rsp
 * DESCRIPTION
 *  This function to process response from module NFC
 * PARAMETERS
 *  msg
 *	nfc_init_deinit_rsp_struct
 *	
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nfc_lib_deinit_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nfc_init_deinit_rsp_struct *msg_info =  (nfc_init_deinit_rsp_struct *)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_group_is_present(GRP_ID_NFC_SETTINGS))
	{
	if(msg_info->action_result == 1)
	{
		mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
	}
	else
	{
		mmi_popup_display_simple((WCHAR*)GetString(STR_ID_NFC_OFF_ERR), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	}
		mmi_frm_scrn_close(GRP_ID_NFC_SETTINGS, SCR_ID_NFC_PROGRESS);
		mmi_frm_group_close(GRP_ID_NFC_SETTINGS);
	}
	mmi_nfc_update_idle_icon_status(!msg_info->action_result);
	mmi_nfc_set_nvram_status(!msg_info->action_result);
	g_mmi_nfc_status = !msg_info->action_result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_lib_error_notify_rsp
 * DESCRIPTION
 *  This function to process error info from module NFC
 * PARAMETERS
 *  msg
 *	nfc_init_init_rsp_struct
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nfc_lib_error_notify_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nfc_mmi_notify_event_struct *msg_info =  (nfc_mmi_notify_event_struct *)msg;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(msg_info->event != NFC_MMI_NOTIFY_EVENT_RESERVE)
	{
		mmi_nfc_update_idle_icon_status(msg_info->event);
		mmi_nfc_set_nvram_status(msg_info->event);
		g_mmi_nfc_status = msg_info->event;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_update_idle_icon_status
 * DESCRIPTION
 *  This function to update icon status in idle
 * PARAMETERS
 *  status: 0 off; 1 on
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nfc_update_idle_icon_status(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(status)
	{
		wgui_status_icon_bar_show_icon(STATUS_ICON_NFC);
	}
	else
	{
		wgui_status_icon_bar_hide_icon(STATUS_ICON_NFC);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_setting_status_seclect_hdlr
 * DESCRIPTION
 *  This function is to handle menu select in nfc setting
 * PARAMETERS
 *  idx: menu index
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nfc_setting_status_seclect_hdlr(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (idx == g_mmi_nfc_status)
	{
 		mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
		mmi_frm_group_close(GRP_ID_NFC_SETTINGS);
 	}
	else
	{
		mmi_nfc_entry_progress_screen();
		mmi_nfc_sent_msg_to_nfc_lib(idx);
		//mmi_nfc_set_nvram_status(idx);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_entry_progress_screen
 * DESCRIPTION
 *  This function is to enter progress screen when nfc mode is switching
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nfc_entry_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
        GRP_ID_NFC_SETTINGS,
        SCR_ID_NFC_PROGRESS,
        NULL,
        (FuncPtr)mmi_nfc_entry_progress_screen,
        MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_UP);
    ShowCategory66Screen(
        STR_ID_NFC_SETTING,
        MAIN_MENU_CONNECTIVITY_ICON,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_NFC_PROGRESS),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);    
    //mmi_frm_scrn_set_leave_proc(GRP_ID_NFC_SETTINGS, SCR_ID_NFC_SETTINGS, mmi_flight_mode_progress_leave_proc);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_write_status
 * DESCRIPTION
 *  This function is to write nfc status to nvram
 * PARAMETERS
 *  evt
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_nfc_set_nvram_status(U8 status)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S16 pError;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	WriteRecord(NVRAM_EF_NFC_STATUS_LID, 1, &status, 1, &pError);
	return MMI_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_write_status
 * DESCRIPTION
 *  This function is to nfc status to nvram
 * PARAMETERS
 *  evt
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_nfc_get_nvram_status(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S16 pError;
	U8  status;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadRecord(NVRAM_EF_NFC_STATUS_LID, 1, &status, 1, &pError);
	g_mmi_nfc_status = status;
	return status;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_main_menu_init
 * DESCRIPTION
 *  This function is Main menu init
 * PARAMETERS
 *  evt
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nfc_main_menu_init(mmi_id cui_id)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_menu_id list_of_ids[2];
	mmi_menu_id i = 0;
	U8 hilite = 0;
    U16 nStrItemList[2] = 
    {
        STR_ID_NFC_SETTING_OFF,
        STR_ID_NFC_SETTING_ON,
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    for (i = 0; i < 2; i++) 
    {
        list_of_ids[i] = i;
    }
    
    cui_menu_set_currlist(
        cui_id, 
        2, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(cui_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
	
    cui_menu_set_currlist_title(
        cui_id, 
        (WCHAR*)get_string(STR_ID_NFC_SETTING), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_CONN_NFC_MAIN)));
	
	for (i = 0; i < 2; i++)
    {
        cui_menu_set_item_string(
            cui_id, 
            (mmi_menu_id)i,
            (WCHAR*)get_string(nStrItemList[i]));
    }
    
    cui_menu_set_currlist_left_softkey(
        cui_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));

    cui_menu_set_currlist_right_softkey(
        cui_id, 
        (WCHAR*)get_string(STR_GLOBAL_BACK));	
	
	hilite = g_mmi_nfc_status;
	if (!mmi_frm_is_in_backward_scenario())
	{
    cui_menu_set_currlist_highlighted_id(cui_id, (mmi_menu_id)hilite);
	}
	 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_entry_main_menu_proc
 * DESCRIPTION
 *  This function is Main menu proc handler
 * PARAMETERS
 *  evt
 *
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_nfc_entry_main_menu_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			mmi_nfc_main_menu_init(menu_evt->sender_id);
			break;
		case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
		case EVT_ID_CUI_MENU_ITEM_SELECT:
			mmi_nfc_setting_status_seclect_hdlr(menu_evt->highlighted_menu_id);
			break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
	        cui_menu_close(menu_evt->sender_id);
	        break;
		default:
			break;
	}
	return MMI_RET_OK;
	

}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_entry_main_menu
 * DESCRIPTION
 *  This function is Main menu hilight handler
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nfc_main_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_nfc_entry_main_menu, KEY_EVENT_UP);

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_nfc_entry_main_menu, KEY_EVENT_UP);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_nfc_entry_main_menu
 * DESCRIPTION
 *  This function is Main menu entry function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nfc_entry_main_menu(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    mmi_id cui_gid;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_frm_group_create_ex(
		GRP_ID_ROOT, 
		GRP_ID_NFC_SETTINGS, 
		mmi_nfc_entry_main_menu_proc, 
		NULL, 
		MMI_FRM_NODE_SMART_CLOSE_FLAG);


	cui_gid = cui_menu_create(
		GRP_ID_NFC_SETTINGS, 
		CUI_MENU_SRC_TYPE_APPCREATE, 
		CUI_MENU_TYPE_APPSUB, 
		MENU_CONN_NFC_MAIN, 
        MMI_FALSE, 
        NULL);
	
	cui_menu_run(cui_gid);
}

#endif /* __NFC_SUPPORT__*/
