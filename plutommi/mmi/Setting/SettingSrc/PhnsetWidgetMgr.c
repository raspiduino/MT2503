/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * PhnsetWidgetMgr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Widget manager setting Menus
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
/* MMI standard headers */
#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_VUI_LAUNCHER_KEY__

/* nvram access */
#include "custom_mmi_default_value.h" 

/* Others */
#include "custom_equipment.h"

#include "mmi_frm_nvram_gprot.h"
#include "device.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories.h"
#include "nvram_common_defs.h"
#include "mmi_rp_app_mainmenu_def.h"

#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "Unicodexdcl.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
/* UI */
#include "menucuigprot.h"
#include "BootupSrvGprot.h"
#include "PhnsetWidgetMgrGprot.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "PhoneSetup.h"
/*TEMP imgage resource.*/
#include "mmi_rp_app_profiles_def.h"
#include "vapp_launcher_key_gprot.h"
#include "MMI_ap_dcm_config.h"
/* Device headers */

/***************************************************************************** 
* Local Functions
*****************************************************************************/
static MMI_RET mmi_phnset_widget_manager_proc(mmi_event_struct *event);
static void mmi_phnset_widget_entry_order_setting_view(void);
static void mmi_phnset_widget_manager_order_list_view(void);
static void	mmi_phnset_widget_order_lsk_handler(void);
static void	mmi_phnset_widget_order_unk_handler(void);
static void	mmi_phnset_widget_order_dnk_handler(void);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void	mmi_phnset_widget_order_tap_handler(mmi_tap_type_enum tap_type, S32 index);
#endif
static void mmi_phnset_widget_entry_display_setting(void);
static void mmi_phnset_widget_disp_setting_highlight_hdlr(S32 item_idx);
static void mmi_phnset_widget_disp_setting_lsk_hdlr(void);
static S32 mmi_phnset_widget_disp_setting_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
//static void mmi_phnset_widget_manager_init(void);

/***************************************************************************** 
* Local Varibles
*****************************************************************************/
static mmi_phnset_widget_manager_cntx_struct phnset_widget_cntx;
static U8 order_hilite_idx;
static U8 order_update_status;
static U8 disp_hilite_idx;
static U8 disp_selected_items;
static U8 sel_widget_order_idx[MAX_PHNSET_WIDGETS_NUM];

/***************************************************************************** 
* Global Varibles
*****************************************************************************/
    
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_widget_manager_launch
 * DESCRIPTION
 *  phone setting widget manager lanuch function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_widget_manager_launch(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 cnt = vapp_keylauncher_get_widget_total_num();
	mmi_proc_func proc_func;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_group_is_present(GRP_ID_PHNSET_WIDGET_MGR))
	{	
		mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
		return;
	}
	
	mmi_phnset_widget_manager_init();
	
	if (cnt <= MIN_PHNSET_WIDGETS_NUM)
	{
		proc_func = NULL;
	}
	else
	{
		proc_func = mmi_phnset_widget_manager_proc;
	}
	
	mmi_frm_group_create_ex(parent_id, 
			GRP_ID_PHNSET_WIDGET_MGR, 
			proc_func, 
			NULL, 
			MMI_FRM_NODE_SMART_CLOSE_FLAG);

	if (cnt <= MIN_PHNSET_WIDGETS_NUM)
	{
	
		mmi_phnset_widget_manager_init();
		mmi_phnset_widget_entry_order_setting_view();
	}
	else
	{
	    cui_menu_create_and_run(GRP_ID_PHNSET_WIDGET_MGR,
				CUI_MENU_SRC_TYPE_RESOURCE,
				CUI_MENU_TYPE_FROM_RESOURCE, 
				MENU_ID_KEY_LAUNGCHER_WGTMGR, 
				MMI_FALSE,
				NULL);
	}
	
}
/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_manager_proc
* DESCRIPTION
*  widget manger proc function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_phnset_widget_manager_proc(mmi_event_struct *event)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	cui_menu_event_struct *evt = (cui_menu_event_struct*)event;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:		
			cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);		
    	case EVT_ID_CUI_MENU_ITEM_SELECT:
    	case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
			switch(evt->highlighted_menu_id)
			{
				case MENU_ID_KEY_LAUNGCHER_WGTMGR_ORDER_SETTINGS:
					mmi_phnset_widget_manager_init();
					mmi_phnset_widget_entry_order_setting_view();
					break;
				case MENU_ID_KEY_LAUNGCHER_WGTMGR_DISP_SETTINGS:
					mmi_phnset_widget_entry_display_setting();
					break;
				default:
					break;
			}
			break;
			
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(evt->sender_id);
			mmi_frm_group_close(GRP_ID_PHNSET_WIDGET_MGR);
			break;
			
		default:
			break;		
	}			
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_entry_order_setting_view
* DESCRIPTION
*  widget manger entry order list setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_widget_entry_order_setting_view(void)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    MMI_ID new_scrn_id = 0;
    MMI_ID group_id = GRP_ID_PHNSET_WIDGET_MGR;
    MMI_ID curr_scrn_id = mmi_frm_scrn_get_active_id();
    MMI_BOOL close_scrn_flag = MMI_FALSE;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    if (curr_scrn_id == SCR_ID_PHNSET_WIDGET_MGR_ORDER_SETTINGS || curr_scrn_id == SCR_ID_PHNSET_WIDGET_MGR_ORDER_SETTINGS_2)
	{
        close_scrn_flag = MMI_TRUE;
        new_scrn_id = (curr_scrn_id == SCR_ID_PHNSET_WIDGET_MGR_ORDER_SETTINGS) ? SCR_ID_PHNSET_WIDGET_MGR_ORDER_SETTINGS_2 : SCR_ID_PHNSET_WIDGET_MGR_ORDER_SETTINGS;
	}
    /* First enter this screen */
    else
    {
        new_scrn_id = SCR_ID_PHNSET_WIDGET_MGR_ORDER_SETTINGS;
    }
	
	if (mmi_frm_is_in_backward_scenario())
    {
	    mmi_frm_scrn_enter(group_id, curr_scrn_id, NULL, mmi_phnset_widget_entry_order_setting_view, MMI_FRM_UNKNOW_SCRN);
	}
    else
    {
        mmi_frm_scrn_enter(group_id, new_scrn_id, NULL, mmi_phnset_widget_entry_order_setting_view, MMI_FRM_UNKNOW_SCRN);
        if (close_scrn_flag)
    	{
    	    mmi_frm_scrn_close(group_id, curr_scrn_id);
    	}
	}
	mmi_phnset_widget_manager_order_list_view();
}


/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_manager_order_list_view
* DESCRIPTION
*  widget manger entry order list update function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_widget_manager_order_list_view(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
	int i;
	S32 cnt;
	U16 lsk_strID;
	mmi_vapp_widget_name_struct name_array[MAX_PHNSET_WIDGETS_NUM];
	int j = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_PHNSET_WIDGET_MGR, mmi_frm_scrn_get_active_id());
	cnt = vapp_keylauncher_get_widget_total_num();

	vapp_keylauncher_get_widget_name_list_by_ids(name_array, phnset_widget_cntx.widget_name_list, cnt);
	
	for(i = 0; i < cnt; i++)
	{
		if(phnset_widget_cntx.widget_mark_flag[i] == 1)
		{
			memcpy(subMenuData[j], (U8*)name_array[i], MAX_SUB_MENU_SIZE);
			sel_widget_order_idx[j] = i;
			j++;
		}
	}
	
	
	if(order_update_status == PHNSET_WIDGET_MGR_ORDER_MOVE)
	{
		lsk_strID = STR_GLOBAL_OK;
	}
	else
	{
		lsk_strID = STR_GLOBAL_MOVE;
	}
	
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory353Screen(
        (U8*)GetString(STR_ID_KEY_LAUNGCHER_WGTMGR_ORDER_SETTINGS),
        0,
        lsk_strID,
        0,
        STR_GLOBAL_BACK,
        0,
        disp_selected_items, 	/* can only set selected widget order */
        (U8**)subMenuDataPtrs,
        NULL,
        NULL,
        0,
        order_hilite_idx,
        gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phnset_widget_order_tap_handler);
#endif
    SetLeftSoftkeyFunction(mmi_phnset_widget_order_lsk_handler, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_phnset_widget_order_lsk_handler, KEY_EVENT_UP);
	SetKeyHandler(mmi_phnset_widget_order_unk_handler, KEY_UP_ARROW, KEY_EVENT_UP);	
	SetKeyHandler(mmi_phnset_widget_order_dnk_handler, KEY_DOWN_ARROW, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_order_list_update
* DESCRIPTION
*  widget manger entry order setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void	mmi_phnset_widget_order_list_update(S32 from_idx, S32 to_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 tmp_name;
	U8	tmp_mark_id;
	S32 *widget_name_list = phnset_widget_cntx.widget_name_list;
	U8	*widget_mark_list = phnset_widget_cntx.widget_mark_flag;
	int i, j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	tmp_name = widget_name_list[from_idx];
	//tmp_mark_id = widget_mark_list[from_idx];
	if(from_idx < to_idx)
	{
		
		for (i = from_idx; i < to_idx; i++)
		{
			if(widget_mark_list[i])
			{
				for(j = i + 1; j <= to_idx; j++)
				{
					if(widget_mark_list[j])
					{
						widget_name_list[i] = widget_name_list[j];
						break;
					}
					//i++;
				}
			}
		}
	}
	else
	{
		for (i = from_idx; i > to_idx; i--)
		{
			if(widget_mark_list[i])
			{
				for(j = i - 1; j >= to_idx; j--)
				{
					if(widget_mark_list[j])
					{
						widget_name_list[i] = widget_name_list[j];
						break;
		            }
					//i--;
	            }
			}
		}
	}
	widget_name_list[to_idx] = tmp_name;	
	//widget_mark_list[to_idx] = tmp_mark_id;	

}


/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_order_lsk_handler
* DESCRIPTION
*  widget manger entry order setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void	mmi_phnset_widget_order_lsk_handler(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 pError;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(order_update_status == PHNSET_WIDGET_MGR_ORDER_NONE)
	{
		order_update_status = PHNSET_WIDGET_MGR_ORDER_MOVE;
	}
	else if(order_update_status == PHNSET_WIDGET_MGR_ORDER_MOVE)
	{
		order_update_status = PHNSET_WIDGET_MGR_ORDER_NONE;
		WriteRecord(NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID, 1, &phnset_widget_cntx, sizeof(mmi_phnset_widget_manager_cntx_struct), &pError);
	}
	else
	{
		MMI_ASSERT(0);
	}
	mmi_phnset_widget_entry_order_setting_view();
}


/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_order_unk_handler
* DESCRIPTION
*  widget manger entry order setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void	mmi_phnset_widget_order_unk_handler(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 cnt = disp_selected_items;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(order_hilite_idx == 0)
	{
		order_hilite_idx = cnt - 1;
	}
	else
	{
		order_hilite_idx --;
	}
	
	if(order_update_status == PHNSET_WIDGET_MGR_ORDER_MOVE)
	{
	
		if(order_hilite_idx == cnt - 1)
		{
			mmi_phnset_widget_order_list_update(sel_widget_order_idx[0], sel_widget_order_idx[order_hilite_idx]);
		}
		else
		{
			mmi_phnset_widget_order_list_update(sel_widget_order_idx[order_hilite_idx + 1], sel_widget_order_idx[order_hilite_idx]);
		}
		mmi_phnset_widget_entry_order_setting_view();
	}
	

}


/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_order_dnk_handler
* DESCRIPTION
*  widget manger entry order setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void	mmi_phnset_widget_order_dnk_handler(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 cnt = disp_selected_items;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if(order_hilite_idx == cnt - 1)
	{
		order_hilite_idx = 0;
	}
	else
	{
		order_hilite_idx++;
	}
	if(order_update_status == PHNSET_WIDGET_MGR_ORDER_MOVE)
	{
		if(order_hilite_idx == 0)
		{
			mmi_phnset_widget_order_list_update(sel_widget_order_idx[cnt - 1], sel_widget_order_idx[0]);
		}
		else
		{
			mmi_phnset_widget_order_list_update(sel_widget_order_idx[order_hilite_idx - 1], sel_widget_order_idx[order_hilite_idx]);
		}
		mmi_phnset_widget_entry_order_setting_view();
	}
	

}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_order_tap_handler
* DESCRIPTION
*  widget manger tap order setting handler function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void	mmi_phnset_widget_order_tap_handler(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
	{
		order_update_status = PHNSET_WIDGET_MGR_ORDER_MOVE;	
	}
	else if(order_update_status == PHNSET_WIDGET_MGR_ORDER_MOVE)
	{
		mmi_phnset_widget_order_list_update(sel_widget_order_idx[order_hilite_idx], sel_widget_order_idx[index]);
	}
	order_hilite_idx = index;
	mmi_phnset_widget_entry_order_setting_view();
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_entry_display_setting
* DESCRIPTION
*  widget manger entry order setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_widget_entry_display_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
	S32 highlighted_item = 0;
	U16 left_key_string;
	S32 cnt = vapp_keylauncher_get_widget_total_num();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_scrn_enter(
		GRP_ID_PHNSET_WIDGET_MGR, 
		SCR_ID_PHNSET_WIDGET_MGR_DISP_SETTINGS, 
		NULL, 
		(FuncPtr)mmi_phnset_widget_entry_display_setting, 
		MMI_FRM_UNKNOW_SCRN))
    {
		//mmi_phnset_widget_manager_init();
		gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_PHNSET_WIDGET_MGR, SCR_ID_PHNSET_WIDGET_MGR_DISP_SETTINGS);
				
		
		/* register highlight handler */
		RegisterHighlightHandler(mmi_phnset_widget_disp_setting_highlight_hdlr);
		if(phnset_widget_cntx.widget_mark_flag[disp_hilite_idx])
		{
			left_key_string = STR_GLOBAL_OFF;
		}
		else
		{
			left_key_string = STR_PHNSET_WIDGET_ON;
		}
		
		EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		    /* show category */
	    wgui_cat1032_show(
	        (WCHAR*) get_string(STR_ID_KEY_LAUNGCHER_WGTMGR_DISP_SETTINGS),
	        NULL,
	        (WCHAR*) get_string(left_key_string),
	        NULL,              				/* left_softkey_icon */
	        (WCHAR*) get_string(STR_GLOBAL_BACK),
	        NULL,              				/* right_softkey_icon */
	        cnt, 							/* number_of_items */
	        mmi_phnset_widget_disp_setting_get_async_items,
	        NULL,              				/* get hint callback */
	        highlighted_item,           	/* highlighted_item */
	        0,  							/* highlighted_tab */
	        NULL,
	        IMG_ID_PROF_ACTIVATED,
	        gui_buffer,
	        NULL);
		SetLeftSoftkeyFunction(mmi_phnset_widget_disp_setting_lsk_hdlr, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_phnset_widget_disp_setting_lsk_hdlr, KEY_EVENT_UP);
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_disp_setting_lsk_hdlr
* DESCRIPTION
*  widget manger entry order setting lsk handler
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_widget_disp_setting_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 pError;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(!phnset_widget_cntx.widget_mark_flag[disp_hilite_idx])
	{
		ChangeLeftSoftkey(STR_GLOBAL_OFF, NULL);
		phnset_widget_cntx.widget_mark_flag[disp_hilite_idx] = !phnset_widget_cntx.widget_mark_flag[disp_hilite_idx];
		disp_selected_items++;
	}
	else if(disp_selected_items <= MIN_PHNSET_WIDGETS_NUM)
	{
		mmi_popup_display_simple_ext(STR_ID_WIDGET_FAIL_TO_DISABLE, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	}
	else
	{
		ChangeLeftSoftkey(STR_PHNSET_WIDGET_ON, NULL);		
		phnset_widget_cntx.widget_mark_flag[disp_hilite_idx] = !phnset_widget_cntx.widget_mark_flag[disp_hilite_idx];
		disp_selected_items--;
	}
	wgui_cat1032_refresh_list(vapp_keylauncher_get_widget_total_num(), disp_hilite_idx, mmi_phnset_widget_disp_setting_get_async_items, NULL);
	WriteRecord(NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID, 1, &phnset_widget_cntx, sizeof(mmi_phnset_widget_manager_cntx_struct), &pError);

}
/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_disp_setting_highlight_hdlr
* DESCRIPTION
*  widget manger entry order setting highlight handler
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_widget_disp_setting_highlight_hdlr(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	disp_hilite_idx = item_idx;
	
	if(phnset_widget_cntx.widget_mark_flag[disp_hilite_idx])
	{
		ChangeLeftSoftkey(STR_GLOBAL_OFF, NULL);
	}
	else
	{
		ChangeLeftSoftkey(STR_PHNSET_WIDGET_ON, NULL);
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_widget_disp_setting_get_async_items
 * DESCRIPTION
 *  This function is to get phone widget info asynchronously
 * PARAMETERS
 *  start_indx:[IN] the first item to get 
 *  menuData:  [OUT] an array to store the widget info
 *  num_item:  [IN] number of items to get
 * RETURNS
 *  number of items gotten
 *****************************************************************************/
static S32 mmi_phnset_widget_disp_setting_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;
	mmi_vapp_widget_name_struct name_array[MAX_PHNSET_WIDGETS_NUM];
	S32 cnt = vapp_keylauncher_get_widget_total_num();
	int items = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	vapp_keylauncher_get_widget_name_list_by_ids(name_array, phnset_widget_cntx.widget_name_list, cnt);

	
    for (i = start_indx; items < num_item && i < cnt; i++, items++)
	{
		mmi_ucs2cpy((CHAR*) menuData[items].item_list[0], (CHAR*)name_array[i]);
		mmi_ucs2cpy((CHAR*) menuData[items].item_list[1], NULL); 
		mmi_ucs2cpy((CHAR*) menuData[items].item_list[2], NULL); 
		if (phnset_widget_cntx.widget_mark_flag[i])
		{
			menuData[items].image_list[1] = get_image(IMG_ID_PROF_ACTIVATED);//TODO
		}
		else
		{
			menuData[items].image_list[1] = get_image(IMG_NONE);
		}
	}
	return num_item;

}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_manager_init
* DESCRIPTION
*  widget manger entry order setting function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_phnset_widget_manager_init(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;
	S16 pError;
	S32 cnt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	order_hilite_idx = 0;
	order_update_status = PHNSET_WIDGET_MGR_ORDER_NONE;
	
	ReadRecord(NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID, 1, &phnset_widget_cntx, sizeof(mmi_phnset_widget_manager_cntx_struct), &pError);

	cnt = vapp_keylauncher_get_widget_total_num();
	
	if(phnset_widget_cntx.widget_name_list[0] == 0xffffffff)
	{
		if(cnt)
		{
			vapp_keylauncher_get_widget_ids(phnset_widget_cntx.widget_name_list);
		}
	}
	disp_selected_items = 0;
	for(i = 0; i < cnt; i++)
	{
		if(phnset_widget_cntx.widget_mark_flag[i])
		{
			phnset_widget_cntx.widget_mark_flag[i] = 1;
			sel_widget_order_idx[disp_selected_items] = i;
			disp_selected_items++;
		}	
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_get_widget_num
* DESCRIPTION
*  widget manger for get widget number
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
S32 mmi_phnset_widget_get_widget_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	mmi_phnset_widget_manager_init();
	return disp_selected_items;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_get_widget_name_id_list
* DESCRIPTION
*  widget manger for get widget id name list.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
void  mmi_phnset_widget_get_widget_ids_list(S32* id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i, j = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	mmi_phnset_widget_manager_init();

	for(i = 0; i < MAX_PHNSET_WIDGETS_NUM; i++)
	{
		if(phnset_widget_cntx.widget_mark_flag[i])
		{
			id[j] = phnset_widget_cntx.widget_name_list[i];
			j++;
			if(j >= disp_selected_items)
			{
				break;
			}
		}
	}

}

#endif

