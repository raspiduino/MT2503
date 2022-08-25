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
 * PhnsetShortcutSetting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Shortcut manager setting Menu
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_VUI_LAUNCHER_KEY__
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories.h"
#include "nvram_common_defs.h"
#include "mmi_rp_app_mainmenu_def.h"

#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
/* UI */
#include "menucuigprot.h"
#include "mmi_rp_app_phonesetting_new_def.h"

/*TEMP imgage resource.*/
#include "mmi_rp_app_profiles_def.h"
#include "AppMgrSrvGprot.h"
#include "PhoneSetupGprots.h"
#include "GlobalConstants.h"
#include "imeGprotEnums.h"
#include "PhbSrvGprot.h"
#include "SSCStringTable.h"
#include "Phonesetup.h"
#include "GlobalConstants.h"
#include "MMI_ap_dcm_config.h"
/* Device headers */

/***************************************************************************** 
* Local Functions
*****************************************************************************/
static U32 mmi_phnset_shortcut_manager_is_app_marked(U32 sel_idx);
static void mmi_phnset_shortcut_manager_select_app_save(U32 sel_idx, U8 save_flag);
static MMI_RET mmi_phnset_shcut_manager_del_shcut(mmi_event_struct *event);
static void mmi_phnset_shortcut_manager_setting_lsk_hdlr(void);
static U32 mmi_phnset_shortcut_manager_get_app_package_num(void);
static U32 mmi_phnset_shortcut_manager_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array);
static S32 mmi_phnset_shortcut_manager_setting_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
static void mmi_phnset_shortcut_manager_setting_highlight_hdlr(S32 item_idx);
static void mmi_phnset_shortcut_manager_setting_view(void);
static void mmi_phnset_shortcut_manager_setting_exit(void);

/***************************************************************************** 
* local define
*****************************************************************************/
#ifdef __MMI_MAINLCD_320X240__
#define MAX_PHNSET_SHORTCUT_NUM 5
#else
#define MAX_PHNSET_SHORTCUT_NUM 4
#endif

/***************************************************************************** 
* Local Varibles
*****************************************************************************/
static mmi_app_package_name_struct selected_shcut_app[MAX_PHNSET_SHORTCUT_NUM];
static U8 selected_shcut_num;

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
static U8 disp_hilite_idx;
static mmi_app_package_name_struct* total_shcut_list_ptr = NULL;
static U8 total_shcut_num;
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

/***************************************************************************** 
* Global Varibles
*****************************************************************************/

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_shortcut_mananger_launch
 * DESCRIPTION
 *  phone setting shortcut manager lanuch function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_shortcut_mananger_launch(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_group_is_present(GRP_ID_PHNSET_SHORT_CUT))
	{	
		mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
		return;
	}
	mmi_frm_group_create_ex(parent_id, 
			GRP_ID_PHNSET_SHORT_CUT, 
			NULL, 
			NULL, 
			MMI_FRM_NODE_SMART_CLOSE_FLAG);

	disp_hilite_idx = 0;
	mmi_phnset_shortcut_manager_init();
	mmi_phnset_shortcut_manager_setting_view();
	
}


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
static void mmi_phnset_shortcut_manager_setting_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
	U16 left_key_string;
	U32 total_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_scrn_enter(
		GRP_ID_PHNSET_SHORT_CUT, 
		SCR_ID_PHNSET_SHORT_CUT, 
		(FuncPtr)mmi_phnset_shortcut_manager_setting_exit, 
		(FuncPtr)mmi_phnset_shortcut_manager_setting_view, 
		MMI_FRM_UNKNOW_SCRN))
    {
		total_count = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
		if(total_shcut_list_ptr == NULL)
		{
    		total_shcut_list_ptr = mmi_frm_scrmem_alloc(total_count*sizeof(mmi_app_package_name_struct));
		}	
    	total_shcut_num = mmi_phnset_shortcut_manager_get_app_package_num();
		//mmi_phnset_widget_manager_init();
		gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_PHNSET_SHORT_CUT, SCR_ID_PHNSET_SHORT_CUT);
				
		
		/* register highlight handler */
		RegisterHighlightHandler(mmi_phnset_shortcut_manager_setting_highlight_hdlr);
		if(mmi_phnset_shortcut_manager_is_app_marked(disp_hilite_idx))
		{
			left_key_string = STR_GLOBAL_OFF;
		}
		else
		{
			left_key_string = STR_GLOBAL_ON;
		}
		
		EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		    /* show category */
	    wgui_cat1032_show(
	        (WCHAR*) get_string(STR_ID_FTE_LAUNGCHER_SHORTCUT),
	        NULL,
	        (WCHAR*) get_string(left_key_string),
	        NULL,              				/* left_softkey_icon */
	        (WCHAR*) get_string(STR_GLOBAL_BACK),
	        NULL,              				/* right_softkey_icon */
	        total_shcut_num, 							/* number_of_items */
	        mmi_phnset_shortcut_manager_setting_get_async_items,
	        NULL,              				/* get hint callback */
	        disp_hilite_idx,           		/* highlighted_item */
	        0,  							/* highlighted_tab */
	        NULL,
	        IMG_ID_PROF_ACTIVATED,
	        gui_buffer,
				NULL);
		SetLeftSoftkeyFunction(mmi_phnset_shortcut_manager_setting_lsk_hdlr, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_phnset_shortcut_manager_setting_lsk_hdlr, KEY_EVENT_UP);
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_setting_exit
* DESCRIPTION
*  widget manger entry shortcut setting exit function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_shortcut_manager_setting_exit(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(total_shcut_list_ptr)
	{
		mmi_frm_scrmem_free(total_shcut_list_ptr);
		total_shcut_list_ptr = NULL;
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_setting_highlight_hdlr
* DESCRIPTION
*  widget manger entry shortcut setting highlight handler
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_shortcut_manager_setting_highlight_hdlr(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	disp_hilite_idx = item_idx;
	
	if(mmi_phnset_shortcut_manager_is_app_marked(item_idx))
	{
		ChangeLeftSoftkey(STR_GLOBAL_OFF, NULL);
	}
	else
	{
		ChangeLeftSoftkey(STR_GLOBAL_ON, NULL);
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_widget_disp_setting_get_async_items
 * DESCRIPTION
 *  This function is to get phone shorcut info asynchronously
 * PARAMETERS
 *  start_indx:[IN] the first item to get 
 *  menuData:  [OUT] an array to store the widget info
 *  num_item:  [IN] number of items to get
 * RETURNS
 *  number of items gotten
 *****************************************************************************/
static S32 mmi_phnset_shortcut_manager_setting_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
	S32 items = 0;
	//mmi_app_package_name_struct name_array[128];/* max number 128 */
	WCHAR app_name[MMI_APP_NAME_MAX_LEN+1];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

	
    for (i = start_indx; items < num_item && i < (S32)total_shcut_num; i++, items++)
	{
		srv_appmgr_get_app_package_name(total_shcut_list_ptr[i], app_name);
		mmi_ucs2ncpy((CHAR*) menuData[items].item_list[0], (CHAR*)app_name, MAX_SUBMENU_CHARACTERS);
		mmi_ucs2cpy((CHAR*) menuData[items].item_list[1], NULL); 
		mmi_ucs2cpy((CHAR*) menuData[items].item_list[2], NULL); 
		if (mmi_phnset_shortcut_manager_is_app_marked(i))
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


/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_get_app_package_list
* DESCRIPTION
*  short cut manager get app package list string.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  Shortcut number.
*****************************************************************************/
	
static U32 mmi_phnset_shortcut_manager_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 count = srv_appmgr_get_app_package_num(flag);
	const char app_desktop[] = "native.mtk.desktop";
	const char app_drawer[] = "native.mtk.drawer";
	U32 i , j = 0, del_cnt;
	mmi_app_package_name_struct tmp;
	
	WCHAR app_name[2][MMI_APP_NAME_MAX_LEN+1];
	WCHAR app_sc_name[2][MMI_APP_NAME_MAX_LEN+1];
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	srv_appmgr_get_app_package_list(flag, name_array, count);

	for (i = 0; i < count; i++)
    {
		if(strcmp(name_array[i], app_desktop) == 0 || strcmp(name_array[i], app_drawer) == 0)
		{
			for(del_cnt = i; del_cnt < count - 1; del_cnt++)
			{
				strcpy(name_array[del_cnt], name_array[del_cnt+1]); /* hide desk top */
			}
			memset(name_array[count - 1], 0, sizeof(mmi_app_package_name_struct));
			i--;
			count--;
		}
}
	
	if(!strcmp((CHAR*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH) ||
			!strcmp((CHAR*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE))
	{
	    for (i = 0; i < count; i++)
	    {
		    for(j = 0; j < count-i-1; j++)
		    {
			    srv_appmgr_get_app_package_name(name_array[j], (WCHAR*)app_name[0]);		
			    srv_appmgr_get_app_package_name(name_array[j+1], (WCHAR*)app_name[1]);
				if(!strcmp((CHAR*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE))
				{
					srv_phb_convert_to_pinyin((WCHAR*)app_name[0], (WCHAR*)app_sc_name[0], 2*(MMI_APP_NAME_MAX_LEN + 1));
					srv_phb_convert_to_pinyin((WCHAR*)app_name[1], (WCHAR*)app_sc_name[1], 2*(MMI_APP_NAME_MAX_LEN +1 ));	
					mmi_ucs2ncpy((CHAR*)app_name[0], (CHAR*)app_sc_name[0], 2*(MMI_APP_NAME_MAX_LEN + 1));
					mmi_ucs2ncpy((CHAR*)app_name[1], (CHAR*)app_sc_name[1], 2*(MMI_APP_NAME_MAX_LEN + 1));
				}
			    if(mmi_ucs2cmp((CHAR*)app_name[0], (CHAR*)app_name[1]) > 0)
			    {
				    strcpy(tmp, name_array[j]);
				    strcpy(name_array[j], name_array[j+1]);
				    strcpy(name_array[j+1], tmp);
			    }
		    }
	    }
	}
	return count;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_get_app_package_num
* DESCRIPTION
*  short cut manager get app package list item number.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static U32 mmi_phnset_shortcut_manager_get_app_package_num(void)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	return mmi_phnset_shortcut_manager_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, total_shcut_list_ptr);
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_setting_lsk_hdlr
* DESCRIPTION
*  widget manger entry short cut manager lsk handler
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_shortcut_manager_setting_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(mmi_phnset_shortcut_manager_is_app_marked(disp_hilite_idx))
	{
		ChangeLeftSoftkey(STR_GLOBAL_ON, NULL);
		mmi_phnset_shortcut_manager_select_app_save(disp_hilite_idx, 0);	
	}
	else if(selected_shcut_num >= MAX_PHNSET_SHORTCUT_NUM)
	{
		mmi_popup_display_simple_ext(STR_ID_FAIL_TO_ADD, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	}
	else
	{
		ChangeLeftSoftkey(STR_GLOBAL_OFF, NULL);		
		mmi_phnset_shortcut_manager_select_app_save(disp_hilite_idx, 1);
	}

}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_is_app_marked
* DESCRIPTION
*  shortcut manger init function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/

static U32 mmi_phnset_shortcut_manager_is_app_marked(U32 sel_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;
	U32 ret = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i = 0; i < MAX_PHNSET_SHORTCUT_NUM; i++)
	{
		if(!strcmp((CHAR*)(selected_shcut_app + i), (CHAR*)total_shcut_list_ptr[sel_idx]))
		{
			ret = i +1;
			break;
		}
	}
	return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_select_app_save
* DESCRIPTION
*  shortcut manger init function
* PARAMETERS
*  evt        [IN] package_name: app name. save_flag 0: delete. 1: add.
* RETURNS
*  void
*****************************************************************************/

static void mmi_phnset_shortcut_manager_select_app_save(U32 sel_idx, U8 save_flag)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 idx;
	S16 pError;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(save_flag == 0) /* for delete a short cut */
	{
		idx = mmi_phnset_shortcut_manager_is_app_marked(sel_idx);
		if(idx && idx <= MAX_PHNSET_SHORTCUT_NUM)
		{
			selected_shcut_num--;
			memset(selected_shcut_app[idx - 1], 0, MMI_APP_NAME_MAX_LEN);
		}
	}
	else if(save_flag == 1) /* for add a short cut */
	{
		for(idx = 0; idx <  MAX_PHNSET_SHORTCUT_NUM; idx++)
		{
			if(!selected_shcut_app[idx][0])
			{
				memcpy(selected_shcut_app[idx], total_shcut_list_ptr[sel_idx], MMI_APP_NAME_MAX_LEN);
				selected_shcut_num++;
				break;
			}
		}
	}	
	if(mmi_frm_scrn_is_present(GRP_ID_PHNSET_SHORT_CUT, SCR_ID_PHNSET_SHORT_CUT, MMI_FRM_NODE_ALL_FLAG))
	{
		wgui_cat1032_refresh_list(total_shcut_num, disp_hilite_idx, mmi_phnset_shortcut_manager_setting_get_async_items, NULL);
	}
	WriteRecord(NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID, 1, selected_shcut_app[0], sizeof(mmi_app_package_name_struct)*MAX_PHNSET_SHORTCUT_NUM, &pError);
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_init
* DESCRIPTION
*  shortcut manger init function
* PARAMETERS
*  evt        [IN] package_name: app name. save_flag 0: delete. 1: add.
* RETURNS
*  void
*****************************************************************************/
void  mmi_phnset_shortcut_manager_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 pError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadRecord(NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID, 1, selected_shcut_app[0], sizeof(mmi_app_package_name_struct)*MAX_PHNSET_SHORTCUT_NUM, &pError);
	mmi_phnset_shortcut_manager_get_shortcut_number();
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_get_shortcut_number
* DESCRIPTION
*  shortcut manger get shortcut number
* PARAMETERS
*  evt        [IN] package_name: app name. save_flag 0: delete. 1: add.
* RETURNS
*  void
*****************************************************************************/
U32 mmi_phnset_shortcut_manager_get_shortcut_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	U32 num = 0;
	srv_app_info_struct info;
	S16 pError;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i = 0; i < MAX_PHNSET_SHORTCUT_NUM; i++)
	{
		if(selected_shcut_app[i][0])
		{
			/*if(MMI_RET_ERR == srv_appmgr_get_app_package_info(selected_shcut_app[i], &info))
			{
				memset(selected_shcut_app[i], 0, sizeof(mmi_app_package_name_struct));
				WriteRecord(NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID, 1, selected_shcut_app[0], sizeof(mmi_app_package_name_struct)*MAX_PHNSET_SHORTCUT_NUM, &pError);
			}
			else
			{*/
		        num++;
		    //}
	    }
	}
	selected_shcut_num = num;
	return num;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_get_shortcut_number
* DESCRIPTION
*  shortcut manger get shortcut number
* PARAMETERS
*  evt        [IN] package_name: app name. save_flag 0: delete. 1: add.
* RETURNS
*  void
*****************************************************************************/
void mmi_phnset_shortcut_manager_get_shortcut_list(mmi_app_package_name_struct *package_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 idx;
	U32 out_idx = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_phnset_shortcut_manager_init();
	for(idx = 0; idx <	MAX_PHNSET_SHORTCUT_NUM; idx++)
	{
		if(selected_shcut_app[idx][0])
		{
			memcpy(package_list[out_idx], selected_shcut_app[idx], sizeof(mmi_app_package_name_struct));
			out_idx++;
		}
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_get_shortcut_number
* DESCRIPTION
*  shortcut manger get shortcut number
* PARAMETERS
*  evt        [IN] package_name: app name. save_flag 0: delete. 1: add.
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_phnset_shcut_manager_del_shcut(mmi_event_struct *event)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	U32 i;
	srv_appmgr_update_event_struct *evt = (srv_appmgr_update_event_struct *)event;
	S16 pError;
	srv_app_info_struct info;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i = 0; i < MAX_PHNSET_SHORTCUT_NUM; i++)
	{
		if(selected_shcut_app[i][0])
		{
			if(MMI_RET_ERR == srv_appmgr_get_app_package_info(selected_shcut_app[i], &info))
		{		
				memset(selected_shcut_app[i], 0, sizeof(mmi_app_package_name_struct));
			    selected_shcut_num--;
			    WriteRecord(NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID, 1, selected_shcut_app[0], sizeof(mmi_app_package_name_struct)*MAX_PHNSET_SHORTCUT_NUM, &pError);
			}
		}			
	}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_get_shortcut_number
* DESCRIPTION
*  shortcut manger get shortcut number
* PARAMETERS
*  evt        [IN] package_name: app name. save_flag 0: delete. 1: add.
* RETURNS
*  void
*****************************************************************************/
MMI_RET mmi_phnset_shcut_appmgr_uninstall_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
		case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
			{		
				mmi_phnset_shcut_manager_del_shcut(event);			
            	break;
        	}
            
        default:
            break;
    }

    return MMI_RET_OK;

}

#endif

