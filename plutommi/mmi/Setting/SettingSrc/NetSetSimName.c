/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  NetSetSimName.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "Inlinecuigprot.h"
#include "MenuCuiGprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_rp_app_mode_switch_def.h"
#include "modeswitchsrvgprot.h"
#include "ModeSwitchAppProt.h"
#include "ModeSwitchAppGprot.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "AlarmFrameworkProt.h"
#include "nvram_common_defs.h"
#include "mmi_frm_events_gprot.h"
#include "SimCtrlSrvGprot.h"
#include "NetsetAppGprot.h"
#include "UcmGProt.h"
#include "UcmSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "AlarmProt.h"      
/***************************************************************************** 
* Local define
*****************************************************************************/

#define ITEM_NETSET_SIM_NAME_CAPTION CUI_INLINE_ITEM_ID_BASE + 1
#define ITEM_NETSET_SIM_NAME_EDIT_TEXT CUI_INLINE_ITEM_ID_BASE + 2
#define ITEM_NETSET_SIM_STATUS_CAPTION CUI_INLINE_ITEM_ID_BASE + 3
#define ITEM_NETSET_SIM_STATUS_SELECT CUI_INLINE_ITEM_ID_BASE + 4


/***************************************************************************** 
* Global Variable
*****************************************************************************/
static WCHAR netset_sim_name[MMI_SIM_TOTAL][MMI_NETSET_SIM_NAME_MAX_LEN];  

static U8 sub_sim_menu_idx;
static U8 sim_available_flag;

static srv_mode_switch_type_enum g_mode_switch_original_mode;

static PU8 net_sim_status_ptr[2];

static const cui_inline_item_caption_struct g_netset_sim_name_caption = {STR_ID_NETSET_SETTING_SIM_NAME};
static const cui_inline_item_caption_struct g_netset_sim_status_caption = {STR_GLOBAL_STATUS};
static const cui_inline_item_text_edit_struct g_netset_sim_name_text_edit = {
    0,
    0,
    MMI_NETSET_SIM_NAME_MAX_LEN, 
    IMM_INPUT_TYPE_MULTITAP_SENTENCE,
    0,
    NULL
};

static cui_inline_set_item_struct g_netset_sim_name_status_edit_data[] =
{
	{ITEM_NETSET_SIM_NAME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_netset_sim_name_caption},
	{ITEM_NETSET_SIM_NAME_EDIT_TEXT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_netset_sim_name_text_edit},
	{ITEM_NETSET_SIM_STATUS_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_netset_sim_status_caption},
	{ITEM_NETSET_SIM_STATUS_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
};

static const cui_inline_struct g_netset_sim_name_status_setting_data =
{
	sizeof(g_netset_sim_name_status_edit_data) / sizeof(cui_inline_set_item_struct),
	0,
	0,
	CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
	NULL,
	g_netset_sim_name_status_edit_data
};


/***************************************************************************** 
* Local function
*****************************************************************************/
static mmi_ret mmi_netset_sim_name_setting_proc(mmi_event_struct * evt);
static void mmi_netset_sim_name_setting_menu_init(MMI_ID owner_id);
static void mmi_netset_sim_name_status_entry_edit(U32 sim_idx);
static mmi_ret mmi_netset_sim_name_status_edit_proc(mmi_event_struct * evt);
static void mmi_netset_sim_name_status_save(MMI_ID owner_id);
static void mmi_netset_sim_name_entry_mode_switch(MMI_ID owner_id, U8 hilite_idx);
static MMI_RET mmi_netset_sim_name_mode_switch_rsp(mmi_event_struct *evt);
static void mmi_netset_sim_name_init(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_setting_launch
 * DESCRIPTION
 *    Entry network setting manu.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
void mmi_netset_sim_name_setting_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_group_is_present(GRP_ID_MODE_SWITCH_SETTING))
	{
		mmi_frm_group_close(GRP_ID_MODE_SWITCH_SETTING);
	}
	
	mmi_frm_group_create_ex(GRP_ID_SETTING_MAIN_MENU, 
			GRP_ID_MODE_SWITCH_SETTING, 
			mmi_netset_sim_name_setting_proc, 
			NULL, 
			MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	cui_menu_create_and_run(GRP_ID_MODE_SWITCH_SETTING,
			CUI_MENU_SRC_TYPE_RESOURCE,
			CUI_MENU_TYPE_APPMAIN,
			MENU_ID_MODE_SWITCH_SIM_NAME,
			MMI_FALSE,
			NULL);
	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_setting_proc
 * DESCRIPTION
 *    Entry network setting manu process function.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
static mmi_ret mmi_netset_sim_name_setting_proc(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_menu_event_struct *event = (cui_menu_event_struct*)evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(event->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			mmi_netset_sim_name_setting_menu_init(event->sender_id);
			break;
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_TAP:
			if(event->parent_menu_id == MENU_ID_MODE_SWITCH_SIM_NAME)
			{
				mmi_netset_sim_name_status_entry_edit((U32)(event->highlighted_menu_id - MENU_ID_NETSET_SIM_NAME1));
			}
			break;
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			mmi_frm_group_close(event->sender_id);
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_setting_menu_init
 * DESCRIPTION
 *    Entry screen to init sim name setting menu.
 * PARAMETERS
 *  	Input owner id
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_sim_name_setting_menu_init(MMI_ID owner_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 string_id;
	U32 i;
	WCHAR *hint;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	string_id = mmi_mode_switch_get_setting_title_string();
	cui_menu_set_currlist_title_by_id(owner_id, string_id, 0);
	
	for(i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
		hint =  mmi_netset_get_sim_name(mmi_frm_index_to_sim(i));
		if(hint)
		{
			cui_menu_set_item_hint(owner_id, MENU_ID_NETSET_SIM_NAME1 + i, hint);
		}
		cui_menu_set_item_hidden(owner_id, MENU_ID_NETSET_SIM_NAME1 + i, (MMI_BOOL)(!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i))));
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_status_entry_edit
 * DESCRIPTION
 *    Entry screen to edit sim name and status.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_sim_name_status_entry_edit(U32 sim_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id inline_id;
	srv_mode_switch_state_enum sim_status;
	U16 sim_string[] = {
		STR_GLOBAL_SIM_1,
#if (MMI_MAX_SIM_NUM >= 2)
		STR_GLOBAL_SIM_2,
#if (MMI_MAX_SIM_NUM >= 3)
		STR_GLOBAL_SIM_3,	
#if (MMI_MAX_SIM_NUM >= 4)
		STR_GLOBAL_SIM_4,
#endif
#endif
#endif
	};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if(mmi_frm_group_is_present(GRP_ID_NETSET_SIM_NAME_EDIT))
	{
		mmi_frm_group_close(GRP_ID_NETSET_SIM_NAME_EDIT);
	}
	
	mmi_frm_group_create_ex(GRP_ID_MODE_SWITCH_SETTING,
		GRP_ID_NETSET_SIM_NAME_EDIT, 
		mmi_netset_sim_name_status_edit_proc, 
		NULL, 
		MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	inline_id = cui_inline_create(GRP_ID_NETSET_SIM_NAME_EDIT, &g_netset_sim_name_status_setting_data);

	sub_sim_menu_idx = sim_idx;
	cui_inline_set_title(inline_id, sim_string[sim_idx], 0);
	sim_status = srv_mode_switch_get_network_mode(mmi_frm_index_to_sim(sim_idx));
	
	net_sim_status_ptr[0] = (PU8)GetString(STR_GLOBAL_OFF);
	net_sim_status_ptr[1] = (PU8)GetString(STR_GLOBAL_ON);
	cui_inline_set_item_select(inline_id, 
		ITEM_NETSET_SIM_STATUS_SELECT, 
		2, 
		net_sim_status_ptr,
		(U8)sim_status);
	cui_inline_set_value(inline_id, ITEM_NETSET_SIM_NAME_EDIT_TEXT, netset_sim_name[sub_sim_menu_idx]);
	cui_inline_run(inline_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_status_edit_proc
 * DESCRIPTION
 *    Entry network setting sim name status and name edit.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
static mmi_ret mmi_netset_sim_name_status_edit_proc(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_CUI_INLINE_CSK_PRESS:
		case EVT_ID_CUI_INLINE_SUBMIT:
			mmi_netset_sim_name_status_save(notify_evt->sender_id);
			break;
		case EVT_ID_CUI_INLINE_ABORT:
			mmi_frm_group_close(notify_evt->sender_id);
			break;
		case EVT_ID_CUI_INLINE_NOTIFY:
			switch(notify_evt->event_type)
			{
				case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
					cui_inline_set_softkey_text(
						notify_evt->sender_id, 
						notify_evt->item_id,
						MMI_LEFT_SOFTKEY,
						STR_GLOBAL_SAVE);
					break;
				case CUI_INLINE_NOTIFY_ITEM_CHANGED:
				{
					cui_event_inline_notify_struct fail_evt;
					if(notify_evt->item_id == ITEM_NETSET_SIM_STATUS_SELECT)
					{
					#ifdef __MMI_BACKGROUND_CALL__
						if (srv_ucm_is_background_call())
						{
							
							MMI_FRM_INIT_EVENT(&fail_evt, EVT_ID_MODE_SWITCH_FAIL);
							fail_evt.sender_id = notify_evt->sender_id;
							MMI_FRM_CB_EMIT_POST_EVENT(&fail_evt);
							
							break;
						}
					#endif
					}
					break;
				}
				default:
					break;
			}
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_status_save
 * DESCRIPTION
 *    Save network setting sim name status and name.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_sim_name_status_save(MMI_ID owner_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 pError;
	srv_mode_switch_type_enum sel_mode;
	U8 highlight_id;
	WCHAR sim_name[MMI_NETSET_SIM_NAME_MAX_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	memset(sim_name, 0, MMI_NETSET_SIM_NAME_MAX_LEN*2);
	cui_inline_get_value(owner_id, ITEM_NETSET_SIM_NAME_EDIT_TEXT, sim_name);
		memcpy(netset_sim_name[sub_sim_menu_idx], sim_name, MMI_NETSET_SIM_NAME_MAX_LEN*2);
	    WriteRecord(NVRAM_EF_NETSET_SIM_NAME_LID, sub_sim_menu_idx + 1, netset_sim_name[sub_sim_menu_idx], MMI_NETSET_SIM_NAME_MAX_LEN*2, &pError);
	
	cui_inline_get_value(owner_id, ITEM_NETSET_SIM_STATUS_SELECT, (void*)&highlight_id);
	
	g_mode_switch_original_mode = srv_mode_switch_get_current_mode();
	sel_mode = g_mode_switch_original_mode;
	if(IsBitSet(sel_mode, sub_sim_menu_idx) == highlight_id)
	{
		mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
		mmi_frm_group_close(GRP_ID_NETSET_SIM_NAME_EDIT);
	}
	else
	{
		mmi_netset_sim_name_entry_mode_switch(owner_id, highlight_id);
	}
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_entry_mode_switch
 * DESCRIPTION
 *    mode switch setting.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_sim_name_entry_mode_switch(MMI_ID owner_id, U8 hilite_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mode_switch_type_enum sel_mode;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sel_mode = g_mode_switch_original_mode;
	mmi_mode_switch_switch_progress();
	/* disable alarm expiry handler */
	AlmDisableExpiryHandler();
	if(hilite_idx)
	{
		SetBit(sel_mode, sub_sim_menu_idx);
	}
	else
	{
		ResetBit(sel_mode, sub_sim_menu_idx);
	}
		
	srv_mode_switch_switch_rf_mode(sel_mode, mmi_netset_sim_name_mode_switch_rsp, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_mode_switch_rsp
 * DESCRIPTION
 *    mode switch setting response.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
static MMI_RET mmi_netset_sim_name_mode_switch_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    mmi_frm_scrn_set_leave_proc(GRP_ID_MODE_SWITCH_SETTING, SCR_ID_MODE_SWITCH_SWITCH_PROGRESS, NULL);
    mmi_frm_scrn_close(GRP_ID_MODE_SWITCH_SETTING, SCR_ID_MODE_SWITCH_SWITCH_PROGRESS);
	if (((srv_mode_switch_rsp_event_struct*)evt)->result)
	{
		mmi_mode_switch_switch_success();
		//AlmEnableExpiryHandler();
		srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL,MMI_TRUE);

        if (srv_mode_switch_get_switch_type() == SRV_MODE_SWITCH_DYNAMIC_MODE)
    	{
            srv_mode_switch_type_enum mode = (srv_mode_switch_type_enum)(srv_mode_switch_get_current_mode() & ~g_mode_switch_original_mode);
            U8 i;
            for (i = 0; i < MMI_SIM_TOTAL; i++)
        	{
                mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        		if (mode & sim)
            	{
            	    mmi_mode_switch_query_enable_check_service(sim);
                    mode &= ~sim;
            	}
        	}
    	}
	}
	else
	{
		mmi_mode_switch_switch_failed();
	}
	
	mmi_frm_group_close(GRP_ID_NETSET_SIM_NAME_EDIT);
#if 0
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
/* under construction !*/
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
#endif
	//mmi_frm_group_close(GRP_ID_NETSET_SIM_NAME_EDIT);
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_sim_name
 * DESCRIPTION
 *    EX user define sim 1 as CMCC. just return CMCC.
 * PARAMETERS
 *  	sim id
 * RETURNS
 *   sim name string
 *****************************************************************************/
WCHAR* mmi_netset_get_sim_name(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 sim_idx;
	WCHAR * ret = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_netset_sim_name_init();
	sim_idx = mmi_frm_sim_to_index(sim_id);
	if(srv_sim_ctrl_get_num_of_inserted() >= 2 && IsBitSet(sim_available_flag, sim_idx)) 
	{
		if(netset_sim_name[sim_idx][0])
		{
		ret = netset_sim_name[sim_idx];
	}
	}
	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_sim_name_user_define
 * DESCRIPTION
 *    Get sim name for app Example: 
 *	SIM name is CMCC. return:  (CMCC)
 * PARAMETERS
 *  	Void
 * RETURNS
 *  0 get sim name ok. -1 buffer is too short.
 *****************************************************************************/

S32 mmi_netset_get_sim_name_with_brace(mmi_sim_enum sim_id, WCHAR* buffer, U32 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 sim_idx;
	S32 ret = 0;
	U32 sim_name_len;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_netset_sim_name_init();
	
	memset(buffer, 0, buff_len);
	sim_idx = mmi_frm_sim_to_index(sim_id);
	sim_name_len = mmi_ucs2strlen((CHAR*)L"(") +
				mmi_ucs2strlen((CHAR*)netset_sim_name[sim_idx]) +
				mmi_ucs2strlen((CHAR*)L"(");
	if (buff_len < sim_name_len)
	{
		ret = -1;
	}
	if(srv_sim_ctrl_get_num_of_inserted() >= 2 && IsBitSet(sim_available_flag, sim_idx)) 
	{
		if(netset_sim_name[sim_idx][0])
		{
			mmi_ucs2cat((CHAR*)buffer, (CHAR*)L"(");
			mmi_ucs2cat((CHAR*)buffer, (CHAR*)netset_sim_name[sim_idx]);
			mmi_ucs2cat((CHAR*)buffer, (CHAR*)L")");
		}
	}
	return ret;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_sim_name_with_simx_and_brace
 * DESCRIPTION
 *    Get sim name for app Example: 
 *	SIM 1 name is CMCC. return: SIM 1 (CMCC)
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static -1 buffer len is two short. 0 result ok.
 *****************************************************************************/

S32 mmi_netset_get_sim_name_with_simx_and_brace(mmi_sim_enum sim_id, WCHAR* buffer, U32 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 sim_idx;
	U32 sim_name_len;
	U16 sim_string[] = {
		STR_GLOBAL_SIM_1,
#if (MMI_MAX_SIM_NUM >= 2)
		STR_GLOBAL_SIM_2,
#if (MMI_MAX_SIM_NUM >= 3)
		STR_GLOBAL_SIM_3,	
#if (MMI_MAX_SIM_NUM >= 4)
		STR_GLOBAL_SIM_4,
#endif
#endif
#endif
	};
	S32 ret = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_netset_sim_name_init();
	memset(buffer, 0, buff_len);
	sim_idx = mmi_frm_sim_to_index(sim_id);
	sim_name_len = mmi_ucs2strlen((CHAR*)GetString(sim_string[sim_idx])) + 
				mmi_ucs2strlen((CHAR*)L"(") +
				mmi_ucs2strlen((CHAR*)netset_sim_name[sim_idx]) +
				mmi_ucs2strlen((CHAR*)L"(");
	mmi_ucs2cpy((CHAR*)buffer, (CHAR*)GetString(sim_string[sim_idx]));
	if (buff_len < sim_name_len)
	{
		ret = -1;
	}
	else if(srv_sim_ctrl_get_num_of_inserted() >= 2 && IsBitSet(sim_available_flag, sim_idx)) 
	{
		if(netset_sim_name[sim_idx][0])
		{
			mmi_ucs2cat((CHAR*)buffer, (CHAR*)L"(");
			mmi_ucs2cat((CHAR*)buffer, (CHAR*)netset_sim_name[sim_idx]);
			mmi_ucs2cat((CHAR*)buffer, (CHAR*)L")");
		}
	}
	return ret;
		
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_sim_avaliable_hdlr
 * DESCRIPTION
 *    Get sim name for app to display.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
MMI_RET mmi_netset_sim_name_sim_avaliable_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 pError;
	U32 sim_idx = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_SRV_SIM_CTRL_AVAILABLE:
			{
				srv_sim_ctrl_available_evt_struct* ava_evt = (srv_sim_ctrl_available_evt_struct*)evt;
				SetBit(sim_available_flag, mmi_frm_sim_to_index(ava_evt->sim));
				break;
			}
		
		case EVT_ID_SRV_SIM_CTRL_UNAVAILABLE:
			{
				srv_sim_ctrl_unavailable_evt_struct* unava_evt = (srv_sim_ctrl_unavailable_evt_struct*)evt;
				if(srv_sim_ctrl_get_unavailable_cause(unava_evt->sim) == SRV_SIM_CTRL_UA_CAUSE_INITIALIZING)
				{
				    ResetBit(sim_available_flag, mmi_frm_sim_to_index(unava_evt->sim));
				}
				else
				{
					SetBit(sim_available_flag, mmi_frm_sim_to_index(unava_evt->sim));
				}
				break;
			}
			
		case EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED:	
			{
				srv_sim_ctrl_event_detected_evt_struct *detect_evt = (srv_sim_ctrl_event_detected_evt_struct *)evt;
				sim_idx = mmi_frm_sim_to_index(detect_evt->sim);
				if(detect_evt->change_check == SRV_SIM_CTRL_CHANGE_CHECK_CHANGED)
				{
					memset(netset_sim_name[sim_idx], 0, MMI_NETSET_SIM_NAME_MAX_LEN*2);
					WriteRecord(NVRAM_EF_NETSET_SIM_NAME_LID, sim_idx + 1, netset_sim_name[sim_idx], MMI_NETSET_SIM_NAME_MAX_LEN*2, &pError);
				}
				break;
			}

#ifdef __MMI_BACKGROUND_CALL__
		case EVT_ID_MODE_SWITCH_FAIL:
		{
			cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;		
			U32 sim_mode = (U32)srv_mode_switch_get_network_mode(mmi_frm_index_to_sim(sub_sim_menu_idx));
			if (srv_ucm_is_background_call())
			{
				mmi_ucm_app_entry_error_message();				
				cui_inline_set_value(notify_evt->sender_id, 
					ITEM_NETSET_SIM_STATUS_SELECT, 
					(void *)(sim_mode));
			}
			break;
		}
#endif
		default:
			break;
	}
	return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_init
 * DESCRIPTION
 *    Get sim name from nvram.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netset_sim_name_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 pError;
	U32 i;
	static int is_init = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(is_init)
	{
		return;
	}
	is_init = 1;
	
	for(i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
		ReadRecord(NVRAM_EF_NETSET_SIM_NAME_LID, i + 1, netset_sim_name[i], MMI_NETSET_SIM_NAME_MAX_LEN*2, &pError);
	}
}

#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

