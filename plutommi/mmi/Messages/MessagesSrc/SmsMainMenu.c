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
 * SmsMainMenu.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for message menu handling when UM is turned off.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#ifndef __UM_SUPPORT__
#ifdef __MMI_TELEPHONY_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "ps_public_struct.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "nvram_common_defs.h"
#include "SmsAppGprot.h"
#include "GpioSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "NotificationGprot.h"
#include "l4c2smsal_struct.h"
#include "SmsSrvGprot.h"
#include "SmsAppResDef.h"
#include "SmsAppType.h"
#include "PhbSrvGprot.h"
#include "wgui_categories_email.h"
#include "SmsAppProt.h"
#include "AlertScreen.h"
#include "wgui_categories_list.h"
#include "wgui_categories_popup.h"

typedef struct
{
    srv_sms_box_enum msg_box_type;
} mmi_sms_del_folder_struct;

static void mmi_sms_enter_message_list(srv_sms_box_enum msg_box, MMI_ID parent_id);
static void mmi_sms_delete_folder_callback(srv_sms_callback_struct* callback_data);
static void mmi_sms_delete_folder_req(void);
static void mmi_sms_delete_all(void);
static void mmi_sms_alert_inbox_refresh(void);


mmi_sms_list_data_struct *g_sms_list_struct;
srv_sms_box_enum current_box;
SMS_HANDLE delete_handle;


#define MMI_SMS_UI_MAX_LEN_TIME_STR  (15 + 1 + 10 + 1) /* Date string + 1 space + Time string + NULL terminator*/

static MMI_BOOL mmi_sms_is_on_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID group_id,scrn_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
	if(scrn_id == SCR_ID_SMS_LIST)
		return MMI_TRUE;
	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_group_proc
 * DESCRIPTION
 * group proc for the list sceen
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_sms_list_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_GROUP_DEINIT:
			OslMfree(g_sms_list_struct);
			break;
			
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_list_highlight_handler
 * DESCRIPTION
 * highlight handler for the sms list screen
 * PARAMETERS
 *  srv_sms_box_enum
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_list_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	char address[(SRV_SMS_MAX_ADDR_LEN+1)*ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_sms_list_struct->highlighted_item = index;
	g_sms_list_struct->curr_msg_id = srv_sms_get_msg_id(g_sms_list_struct->curr_box, g_sms_list_struct->highlighted_item);
	srv_sms_get_msg_address(g_sms_list_struct->curr_msg_id, address);
	mmi_sms_set_hilite_msg_addr(address);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_list_async_item
 * DESCRIPTION
 * entry function for the message list
 * PARAMETERS
 *  srv_sms_box_enum
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_sms_get_list_async_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_of_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i, msg_id, copy_len;
	mmi_sms_msg_info_struct msg_detail_info;
	UI_character_type msg_time[MMI_SMS_UI_MAX_LEN_TIME_STR];
	UI_character_type str[MMI_SMS_UI_MAX_LEN_TIME_STR];    
    MYTIME time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i = 0; i < num_of_item; i++)
	{
		msg_id = srv_sms_get_msg_id(g_sms_list_struct->curr_box, (start_index + i));
		mmi_sms_get_msg_info_content(&msg_detail_info, msg_id, g_sms_list_struct->curr_box);

		#ifndef __MMI_BT_MAP_CLIENT__
            copy_len = MAX_SUBMENU_CHARACTERS;
            
            if (msg_detail_info.subject_length < MAX_SUBMENU_CHARACTERS)
            {
                copy_len = msg_detail_info.subject_length;
            }

            if (copy_len == 0)
            {
                mmi_ucs2ncpy(
                    (CHAR*) menu_data[i].item_list[0],
                    (CHAR*) GetString(STR_UM_EMPTY_SUBJECT_ID),
                    MMI_SMS_MAX_SUBJECT_LEN);
            }
            else
            {
                mmi_ucs2ncpy(
                    (CHAR*) menu_data[i].item_list[0],
                    (CHAR*) msg_detail_info.subject,
                    copy_len);
            }
        #else
			if (msg_detail_info.address_length == 0)
	        {
	            mmi_ucs2ncpy(
	                (S8*) menu_data[i].item_list[0],
	                (S8*) GetString(STR_GLOBAL_NO_NUMBER),
	                MMI_SMS_MAX_SUBJECT_LEN);
	        }
	        else
	        {
	            copy_len = MAX_SUBMENU_CHARACTERS - 1;
	            if (msg_detail_info.address_length < MAX_SUBMENU_CHARACTERS)
	            {
	                copy_len = msg_detail_info.address_length;
	            }

	            /* Lookup name first if it is phone number */
	            
	            
	                srv_phb_get_name_by_number((U16 *)msg_detail_info.address, 
	                                           (U16 *)menu_data[i].item_list[0], 
	                                           MAX_SUBMENU_CHARACTERS - 1);
	                if (0 == mmi_ucs2strlen((S8*)menu_data[i].item_list[0]))
	                {
	                    mmi_ucs2ncpy((S8*) menu_data[i].item_list[0], 
	                             (S8*) msg_detail_info.address, 
	                             copy_len);
	                }
	        }
		#endif

		/*Timestamp*/
        memset((CHAR*)str, 0, sizeof(str));
        memset((CHAR*)msg_time, 0, sizeof(msg_time));

        copy_len = MAX_SUBMENU_CHARACTERS;
        if (MMI_SMS_UI_MAX_LEN_TIME_STR < MAX_SUBMENU_CHARACTERS)
        {
            copy_len = MMI_SMS_UI_MAX_LEN_TIME_STR;
        }


        if (msg_detail_info.timestamp != 0)
        {
            U32 local_sec = 0;

            memset(&time, 0, sizeof(MYTIME));
            local_sec = applib_dt_sec_utc_to_local(msg_detail_info.timestamp);
            mmi_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);
            /* Normal time display as IDLE */
            date_string(&time, str, DT_IDLE_SCREEN);
            mmi_ucs2ncpy((S8*) msg_time, (S8*) str, (MMI_SMS_UI_MAX_LEN_TIME_STR - 1));
            mmi_ucs2ncat((S8*) msg_time, (S8*) " ", 1);

            time_string(&time, str, DT_IDLE_SCREEN);
            mmi_ucs2ncat((S8*) msg_time, (S8*) str, (MMI_SMS_UI_MAX_LEN_TIME_STR - 1));
		}
		mmi_ucs2ncpy(
            (S8*) menu_data[i].item_list[1],
            (S8*) msg_time,
            copy_len);

		// address
		if (msg_detail_info.address_length == 0)
		{
			mmi_ucs2ncpy(
				(S8*) menu_data[i].item_list[2],
				(S8*) GetString(STR_GLOBAL_NO_NUMBER),
				MMI_SMS_MAX_SUBJECT_LEN);
		}
		else
		{
			copy_len = MAX_SUBMENU_CHARACTERS - 1;
			if (msg_detail_info.address_length < MAX_SUBMENU_CHARACTERS)
			{
				copy_len = msg_detail_info.address_length;
			}

			/* Lookup name first if it is phone number */
				srv_phb_get_name_by_number((U16 *)msg_detail_info.address, 
										   (U16 *)menu_data[i].item_list[2], 
										   MAX_SUBMENU_CHARACTERS - 1);
				if (0 == mmi_ucs2strlen((S8*)menu_data[i].item_list[2]))
				{
					mmi_ucs2ncpy((S8*) menu_data[i].item_list[2], 
							 (S8*) msg_detail_info.address, 
							 copy_len);
				}
		}

		//image
		menu_data[i].image_list[0] = (PU8) GetImage(msg_detail_info.icon_id);


		#if (MMI_MAX_SIM_NUM >= 2)
        if (msg_detail_info.sim_id == SRV_SMS_SIM_1)
        {
            menu_data[i].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM1);  
        }
        else if (msg_detail_info.sim_id == SRV_SMS_SIM_2)
        {
            menu_data[i].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM2);  
        }
    #if (MMI_MAX_SIM_NUM >= 3) 
        else if (msg_detail_info.sim_id == SRV_SMS_SIM_3)
        {
            menu_data[i].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM3);  
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)    
        else if (msg_detail_info.sim_id == SRV_SMS_SIM_4)
        {
            menu_data[i].image_list[1] = (PU8) GetImage(IMG_GLOBAL_SIM4);  
        }
    #endif
        else
        {
            menu_data[i].image_list[1] = NULL;
        }
    #endif
	
	}
	return i;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_str_id_by_folder
 * DESCRIPTION
 * to return the string id for the title of message list
 * PARAMETERS
 *  srv_sms_box_enum
 * RETURNS
 *  U16
 *****************************************************************************/
 static U16 mmi_sms_get_str_id_by_folder(srv_sms_box_enum msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(msg_box)
	{
		case SRV_SMS_BOX_INBOX:
			str_id = STR_GLOBAL_INBOX;
			break;
		case SRV_SMS_BOX_OUTBOX:
			str_id = STR_UM_SENT_ID;
			break;
		case SRV_SMS_BOX_DRAFTS:
			str_id = STR_GLOBAL_DRAFTS;
			break;
		case SRV_SMS_BOX_UNSENT:
			str_id = STR_GLOBAL_OUTBOX;
			break;
	}
	return str_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_enter_msg_viewer
 * DESCRIPTION
 * function to launch the message viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_sms_enter_msg_viewer(MMI_ID parent_id, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_sms_cntx.is_from_hs = MMI_FALSE;
    mmi_sms_um_set_sms_context(msg_id);

    mmi_sms_group_entry(parent_id);
    mmi_sms_view_curr_msg();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_view_msg
 * DESCRIPTION
 * LSK/CSK handler for the message view screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_sms_view_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	mmi_sms_enter_msg_viewer(GRP_ID_SMS_LIST, g_sms_list_struct->curr_msg_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_enter_message_list
 * DESCRIPTION
 * entry function for the message list
 * PARAMETERS
 *  srv_sms_box_enum
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_enter_message_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 lsk_str_id = 0;
	U16 title_id = 0;
	S32 error_flag;
	U16 box_size = srv_sms_get_list_size(g_sms_list_struct->curr_box);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_frm_scrn_enter( GRP_ID_SMS_LIST, SCR_ID_SMS_LIST , NULL, mmi_sms_enter_message_list_screen, MMI_FRM_FULL_SCRN);
	title_id = mmi_sms_get_str_id_by_folder(g_sms_list_struct->curr_box);

	if(box_size > 0)
	{
		lsk_str_id = STR_GLOBAL_VIEW;
	}
	else
	{
		g_sms_list_struct->curr_msg_id = SRV_SMS_INVALID_MSG_ID; // set message id as invalid if there is no message in the list
	}


	wgui_cat_set_list_menu_empty_lable(get_string(STR_UM_EMPTY_MSG_ID));
	RegisterHighlightHandler(mmi_sms_list_highlight_handler);
	
#if !(defined (__MMI_MAINLCD_96X64__) || defined (__MMI_SMS_SLIM__))	
	ShowCategory263Screen(
		(U8*)get_string(title_id),
		0,
		lsk_str_id,
		IMG_GLOBAL_OPTIONS,
		STR_GLOBAL_BACK,
		IMG_GLOBAL_BACK,
		box_size,
		mmi_sms_get_list_async_item,
		NULL,
		g_sms_list_struct->highlighted_item,
		IMG_MESSAGE_READ,
		NULL,
		&error_flag);
#else
	wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
	wgui_cat1032_show(
        (WCHAR*) get_string(title_id),
        0,
        (WCHAR*) GetString(lsk_str_id),
        (PU8) IMG_GLOBAL_OPTIONS,
        (WCHAR*) GetString(STR_GLOBAL_BACK),
        (PU8) IMG_GLOBAL_BACK,
        box_size,
        mmi_sms_get_list_async_item,
        NULL,
        g_sms_list_struct->highlighted_item,
		0,
        IMG_MESSAGE_READ,   /* for icon position used */
		0,
        NULL,
        &error_flag);
	wgui_restore_list_menu_slim_style();
#endif

	if(box_size > 0)
	{
		SetLeftSoftkeyFunction(mmi_sms_view_msg, KEY_EVENT_DOWN);
		SetCenterSoftkeyFunction(mmi_sms_view_msg, KEY_EVENT_DOWN);
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_enter_message_list
 * DESCRIPTION
 * entry function for the message list
 * PARAMETERS
 *  srv_sms_box_enum
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_enter_message_list(srv_sms_box_enum msg_box, MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_create_ex(parent_id, GRP_ID_SMS_LIST, mmi_sms_list_group_proc ,NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	g_sms_list_struct = OslMalloc(sizeof(mmi_sms_list_data_struct));
	memset(g_sms_list_struct, 0x00, sizeof(mmi_sms_list_data_struct));

	g_sms_list_struct->curr_box = msg_box;
	mmi_sms_enter_message_list_screen();
	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_group_proc
 * DESCRIPTION
 * group proc for the SMS main menu
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mmi_sms_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_GROUP_DEINIT:
			if(delete_handle)
				srv_sms_abort(delete_handle, NULL, NULL);
			break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
			switch(menu_evt->highlighted_menu_id)
			{
				case MENU_ID_UM_WRITE_MSG:
					mmi_sms_enter_write_msg();
					break;
				case MENU_ID_SMS_INBOX:
					mmi_sms_enter_message_list(SRV_SMS_BOX_INBOX, GRP_ID_SMS_MAIN);
					break;
				case MENU_ID_SMS_DRAFTS:
					mmi_sms_enter_message_list(SRV_SMS_BOX_DRAFTS, GRP_ID_SMS_MAIN);
					break;
				case MENU_ID_SMS_OUTBOX:
					mmi_sms_enter_message_list(SRV_SMS_BOX_UNSENT, GRP_ID_SMS_MAIN);
					break;
				case MENU_ID_SMS_SENTBOX:
					mmi_sms_enter_message_list(SRV_SMS_BOX_OUTBOX, GRP_ID_SMS_MAIN);
					break;
			#ifdef __MMI_CBS_SUPPORT__
				case MENU_ID_SMS_CB_MAIN:
					 cui_sms_cbs_launch(GRP_ID_SMS_MAIN);			
					break;					
			#endif
				case MENU_ID_SMS_SETTING:
					cui_sms_setting_launch(mmi_frm_group_get_active_id());
					break;
				case MENU_ID_SMS_DELETE_MSG_FOLDER_INBOX:
					current_box = SRV_SMS_BOX_INBOX;
					mmi_sms_delete_all();
					break;
				case MENU_ID_SMS_DELETE_MSG_FOLDER_UNSENT:
					current_box = SRV_SMS_BOX_UNSENT;
					mmi_sms_delete_all();
					break;
				case MENU_ID_SMS_DELETE_MSG_FOLDER_SENT:
					current_box = SRV_SMS_BOX_OUTBOX;
					mmi_sms_delete_all();
					break;
				case MENU_ID_SMS_DELETE_MSG_FOLDER_DRAFTS:
					current_box = SRV_SMS_BOX_DRAFTS;
					mmi_sms_delete_all();
					break;
			}		
			break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(menu_evt->sender_id);
			break;
			
	}
	return MMI_RET_OK;

	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_enter_main_menu
 * DESCRIPTION
 *  function to run the SMS main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_enter_main_menu(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID menu_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	menu_id = cui_menu_create(
						parent_id,
						CUI_MENU_SRC_TYPE_RESOURCE,
						CUI_MENU_TYPE_APPMAIN,
						MAIN_MENU_MESSAGES_MENUID,
						MMI_FALSE,
						(void*) (U32)MAIN_MENU_MESSAGES_MENUID);
	cui_menu_run(menu_id);	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_main_message_menu
 * DESCRIPTION
 *  Entry function for the SMS main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_sms_entry_main_message_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!srv_sms_is_sms_ready())
	{
		mmi_popup_display_simple(
	            (WCHAR *)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), 
	            MMI_EVENT_FAILURE, 
	            GRP_ID_ROOT, 
	            NULL);
	}
	else
	{
		mmi_frm_group_create_ex(GRP_ID_ROOT , GRP_ID_SMS_MAIN , mmi_sms_group_proc ,NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		mmi_sms_enter_main_menu(GRP_ID_SMS_MAIN);		
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_enter_write_msg
 * DESCRIPTION
 *  Entry function for the write message option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_sms_enter_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if 0
/* under construction !*/
	#else
	mmi_msg_pre_entry_write_new_msg();
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_srv_ind
 * DESCRIPTION
 *  handler for the events sent by SMS service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 MMI_RET mmi_sms_handle_srv_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
	srv_sms_event_add_struct *event_info = (srv_sms_event_add_struct*)event_data->event_info;
	srv_sms_event_update_struct *update_info= (srv_sms_event_update_struct*)event_data->event_info;
	U16 msg_id;
	srv_sms_box_enum msg_box_type = SRV_SMS_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_sms_alert_inbox_refresh();	
	switch(evt->evt_id)
	{
		case EVT_ID_SRV_SMS_NEW_MSG:
			break;
			
		case EVT_ID_SRV_SMS_ADD_MSG:
			if(mmi_frm_scrn_is_present(GRP_ID_SMS_LIST, SCR_ID_SMS_LIST, MMI_FRM_NODE_ALL_FLAG))
			{
				msg_box_type = srv_sms_get_list_type(
									event_info->msg_info.status,
									event_info->msg_info.storage_type,
									event_info->msg_info.folder_id);
				/*
					Need to set the highlighted item only if the 3 conditions are met
					1. On the list screen
					2. Added message is in the current list only
					3. There is already some message present in the list
				*/
				if(msg_box_type == g_sms_list_struct->curr_box)
				{
					if(g_sms_list_struct->curr_msg_id != SRV_SMS_INVALID_MSG_ID)
						g_sms_list_struct->highlighted_item = srv_sms_get_msg_list_index(
																	&g_sms_list_struct->curr_box, 
																	g_sms_list_struct->curr_msg_id);
					if(mmi_sms_is_on_list_screen())
					{
						#if 0
/* under construction !*/
						#else
						mmi_frm_display_dummy_screen();
						mmi_frm_scrn_close(GRP_ID_SMS_LIST, SCR_ID_DUMMY);
						#endif
					}
				}
			}
			break;
			
		case EVT_ID_SRV_SMS_DEL_MSG:
			if(mmi_sms_is_on_list_screen())
			{
				msg_box_type = srv_sms_get_list_type(
									event_info->msg_info.status,
									event_info->msg_info.storage_type,
									event_info->msg_info.folder_id);
				
				if(msg_box_type == g_sms_list_struct->curr_box)
				{
					/*
					The check is added for the replacement message scenario when we dont 
					want to udpate the highlighted item in case the current highlighted message is being replaced
					The condition will only be met in the case of replacement message only
					*/
					if(g_sms_list_struct->curr_msg_id == event_info->msg_id)
						break;
					msg_id = srv_sms_get_msg_id(g_sms_list_struct->curr_box , g_sms_list_struct->highlighted_item + 1);
					if(msg_id == SRV_SMS_INVALID_MSG_ID)
					{
						/* 
						set the highlighter to the first item in the list in case the last message is deleted
						The delete message event is recieved after the list screen has been shown
						so we need to use a dummy screen to update the highlighted item
						*/
						g_sms_list_struct->highlighted_item = 0;
						mmi_frm_display_dummy_screen();
						mmi_frm_scrn_close(GRP_ID_SMS_LIST, SCR_ID_DUMMY);
					}
				}
			}
			break;
		case EVT_ID_SRV_SMS_UPDATE_MSG:
			if(mmi_sms_is_on_list_screen())
			{
				msg_box_type = srv_sms_get_list_type(
									update_info->new_msg_info.status,
									update_info->new_msg_info.storage_type,
									update_info->new_msg_info.folder_id);
				// show please wait pop-up only in case message content is updated
				if((msg_box_type == g_sms_list_struct->curr_box) && (update_info->change_para_flag & SRV_SMS_PARA_CONTENT_BUFF) )
					mmi_popup_display_ext( STR_GLOBAL_LOADING, MMI_EVENT_INFO,NULL);			
			}
			break;
	}

	
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_all
 * DESCRIPTION
 * function for the delete all query entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_sms_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_sms_entry_confirm_generic(STR_GLOBAL_DELETE_ALL_ASK, mmi_sms_delete_folder_req, mmi_frm_scrn_close_active_id);
}

	
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_delete_processing_screen
 * DESCRIPTION
 * entry for the delete folder processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_sms_entry_delete_processing_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 process_image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_scrn_enter(
			GRP_ID_SMS_MAIN,
			SCR_ID_SMS_PROCESSING,
			NULL,
			mmi_sms_entry_delete_processing_screen,
			MMI_FRM_FULL_SCRN))
	{
		process_image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
		ShowCategory8Screen(
            0,
            0,
            0,
            0,
            0,
            0,
            STR_GLOBAL_DELETING,
            process_image_id,
            NULL);
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_folder_req
 * DESCRIPTION
 * API to handle the delete message folder req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_sms_delete_folder_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sms_del_folder_struct *delete_context;
	srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if (MMI_MAX_SIM_NUM >= 2)
	sim_id |=SRV_SMS_SIM_2;
	#endif
	delete_context = OslMalloc(sizeof(mmi_sms_del_folder_struct ));
	delete_context->msg_box_type = current_box;
	//mmi_sms_set_and_entry_processing_sg(GRP_ID_SMS_MAIN, STR_GLOBAL_DELETING, STR_GLOBAL_CANCEL);
	mmi_sms_entry_delete_processing_screen();
	delete_handle = srv_sms_delete_msg_list_ex
						(
						current_box,
						sim_id,
						mmi_sms_delete_folder_callback,
						delete_context);
	

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_delete_folder_callback
 * DESCRIPTION
 * callback for the SMS delete all folder request
 * PARAMETERS
 *  srv_sms_callback_struct
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_sms_delete_folder_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sms_del_folder_struct *delete_context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	delete_context = (mmi_sms_del_folder_struct*)callback_data->user_data;
	mmi_frm_scrn_close(GRP_ID_SMS_MAIN,SCR_ID_SMS_PROCESSING);	
	OslMfree(delete_context);

}

/********************** Idle handling starts *************************/

#define MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN (48)   /* the maximum length of unread message string */

static NMGR_HANDLE g_new_msg_handle;
static MMI_BOOL g_is_new_msg_icon_only;

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_nmgr_proc
 * DESCRIPTION
 * proc function for the NMGR alert
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
 static mmi_ret mmi_sms_nmgr_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH:
		case EVT_ID_NMGR_POPUP_APP_LAUNCH:
			mmi_sms_enter_message_list(SRV_SMS_BOX_INBOX, GRP_ID_ROOT);
			
	    case EVT_ID_NMGR_ALERT_END:	
			g_is_new_msg_icon_only = MMI_TRUE;
			break;
	}
    return MMI_OK;
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_prepare_alert_info
 * DESCRIPTION
 * function to create info for the NMGR alert
 * PARAMETERS
 *  mmi_frm_nmgr_alert_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_prepare_alert_info(mmi_frm_nmgr_alert_struct *alert_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 unread_num;
	static WCHAR main_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN * 2 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_wcscpy(main_text, (WCHAR *)GetString(STR_UM_UNREAD_MSG));
	unread_num = srv_sms_get_unread_sms_num();

	if (srv_sms_is_sms_ready())
	{
		if(unread_num)
		{
			MMI_ID unread_string = STR_UM_UNREAD_MSGS_WITH_NUMBER;
			WCHAR sub_text[MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN + 1];

			if (unread_num == 1)
			{
				unread_string = STR_UM_UNREAD_MSG_WITH_NUMBER;
			}
			mmi_wsprintf(
				sub_text, 
				MMI_UM_UI_MAX_IDLE_UNREAD_STRING_LEN, 
				unread_string, 
				unread_num);

			mmi_ucs2cat((CHAR *)main_text, (const CHAR *)L"\n");
			mmi_ucs2cat((CHAR *)main_text, (const CHAR *)sub_text);
		}
	}
	alert_info->popup_para.popup_string = main_text;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_inbox_alert
 * DESCRIPTION
 * alert for the new message
 * PARAMETERS
 *  mmi_frm_nmgr_alert_struct
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_sms_inbox_alert(mmi_frm_nmgr_alert_struct *alert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_frm_nmgr_alert_struct *alert_info = (mmi_frm_nmgr_alert_struct *)alert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	mmi_sms_prepare_alert_info(alert_info);
	
		/*fill in app id for NSS query*/
	alert_info->app_id = APP_SMS; //your app id

	alert_info->ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|
						  MMI_FRM_NMGR_UI_STATUS_BAR_MASK|
						  MMI_FRM_NMGR_UI_POPUP_MASK;
	/*Once the NSS is not support , NMGR will take the behavior mask as its behavior guildline*/
	alert_info->behavior_mask = PREFER_STATUS_BAR; // or PREFER_STATUS_BAR. PREFER_ICON_ONLY

	/*fill in the status bar information*/
	alert_info->status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
	/*the image icon is used for text preview, can be different from popup*/
	/*fill in the status bar icon information*/
	alert_info->status_bar_icon_para.icon_id = STATUS_ICON_INCOMING_SMS; 				
	 

	/*fill in the popup information*/	 
	alert_info->popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
	/*the image icon is used for popup, can be different from text preview*/
	alert_info->popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);
	alert_info->popup_para.popup_button_str_id=STR_GLOBAL_VIEW;

	/*fill in the app launch callback*/
	alert_info->app_proc_para.scrn_group_proc = mmi_sms_nmgr_proc;
	alert_info->app_proc_para.user_data= NULL;
	g_new_msg_handle = mmi_frm_nmgr_alert(alert_info);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_alert_inbox_update_icon_only
 * DESCRIPTION
 * to update only the icon for the new message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_sms_alert_inbox_update_icon_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_frm_nmgr_alert_struct alert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&alert_info, 0, sizeof(alert_info));
	alert_info.event_type = MMI_EVENT_INFO;
	alert_info.scen_id = MMI_SCENARIO_ID_GENERAL;
	alert_info.app_id = APP_SMS; //your app id

	alert_info.alert_option = MMI_FRM_NMGR_DISABLE_PREVIEW |
								MMI_FRM_NMGR_DISABLE_TONE |
								MMI_FRM_NMGR_DISABLE_VIB |
								MMI_FRM_NMGR_DISABLE_POPUP; /* set status icon */
	
	alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
		/*fill in the status bar information*/
	alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
	/*the image icon is used for text preview, can be different from popup*/
	/*fill in the status bar icon information*/
	alert_info.status_bar_icon_para.icon_id = STATUS_ICON_INCOMING_SMS;	
	g_new_msg_handle = mmi_frm_nmgr_alert(&alert_info);
	g_is_new_msg_icon_only = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_alert_inbox_refresh
 * DESCRIPTION
 * function to refresh NMGR whenever a new event is recieved
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_sms_alert_inbox_refresh(void)
{
	if (g_new_msg_handle != NULL)
	{
		if( srv_sms_get_unread_sms_num() == 0)
		{
		    mmi_frm_nmgr_alert_cancel(g_new_msg_handle);
			g_new_msg_handle = NULL;
			return;
		}
	
		if ((MMI_FALSE == g_is_new_msg_icon_only))
		{		
			mmi_frm_nmgr_alert_struct alert_info;

			mmi_sms_prepare_alert_info(&alert_info);
			alert_info.app_id = APP_SMS; //your app id
			alert_info.alert_option = MMI_FRM_NMGR_DISABLE_PREVIEW |
											MMI_FRM_NMGR_DISABLE_TONE |
											MMI_FRM_NMGR_DISABLE_VIB;
	        alert_info.status_bar_icon_para.icon_id = STATUS_ICON_INCOMING_SMS;
			g_new_msg_handle = mmi_frm_nmgr_alert(&alert_info);
			
			g_is_new_msg_icon_only = MMI_FALSE;
		}
	}
	#ifndef __MMI_NCENTER_SUPPORT__
	/* if ncenter is enabled, the icon is only set by ecenter entry */
	else
	{
		if(srv_sms_get_unread_sms_num())
		{
			mmi_sms_alert_inbox_update_icon_only();
		}
	}
	#endif
   
}

/********************** Idle handling finish*************************/


#endif /* __MMI_TELEPHONY_SUPPORT__*/

#endif /* __UM_FOLDER__*/
