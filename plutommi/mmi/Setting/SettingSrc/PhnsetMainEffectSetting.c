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
 * PhnsetMainEffectSetting.c
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

#if (defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
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
#include "mmi_rp_app_setting_menu_effect_def.h"
/*TEMP imgage resource.*/
#include "PhoneSetupGprots.h"
#include "PhoneSetup.h"
#include "mmi_rp_vcp_page_menu_transition_def.h"
#include "MMI_ap_dcm_config.h"
/* Device headers */

/***************************************************************************** 
* Local Functions
*****************************************************************************/
static MMI_RET mmi_phnset_menu_effect_proc(mmi_event_struct *event);
static void mmi_phnset_menu_effect_init_menu_list(void);
static void mmi_phnset_menu_effect_set(U8 hlite);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/***************************************************************************** 
* local define
*****************************************************************************/
#define MAX_PHNSET_MENU_EFFECT_NUM MMI_PHNSET_VCP_PAGE_MENU_TRANSITION_TYPE_NUM


/***************************************************************************** 
* Local Varibles
*****************************************************************************/
U8  selected_menu_effect;

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
void mmi_phnset_menu_effect_launch(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_id,
        GRP_ID_PHNSET_VUI_MAINMENU_EFFECT,
        MENU_ID_VUI_PHNSET_MAINMENU_EFFECT,
        mmi_phnset_menu_effect_proc);

	
}
/*****************************************************************************
* FUNCTION
*  mmi_phnset_shortcut_manager_proc
* DESCRIPTION
*  short cut manager menu proc function
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_phnset_menu_effect_proc(mmi_event_struct *event)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	cui_menu_event_struct *evt = (cui_menu_event_struct*)event;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch (evt->evt_id)
		{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
			mmi_phnset_menu_effect_init_menu_list();
			break;

		case EVT_ID_CUI_MENU_ITEM_SELECT:
		case EVT_ID_CUI_MENU_ITEM_TAP:
			mmi_phnset_menu_effect_set((U8)evt->highlighted_menu_id);
			/*if (mmi_frm_group_is_present(GRP_ID_MENU_EFFECT_PREVIEW))
			{
		    	mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
	        	break;
			}
			mmi_frm_group_create_ex(
		        GRP_ID_PHNSET_VUI_MAINMENU_EFFECT,
		        GRP_ID_MENU_EFFECT_PREVIEW,
		        NULL,
		        NULL,
		        MMI_FRM_NODE_SMART_CLOSE_FLAG);
			mmi_phnset_menu_effect_entry_preview();*/
			break;
			
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
			cui_menu_close(mmi_frm_group_get_active_id());
			break;
			
		case EVT_ID_GROUP_DEINIT:
			break;
		default:
			break;
		}
		return MMI_RET_OK; 

}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_menu_effect_init_menu_list
* DESCRIPTION
* main menu init radio button list
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_menu_effect_init_menu_list(void)
{
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	phnset_radio_button_menu_data_struct radio_button_menu;
	U8 nNumofItem = MAX_PHNSET_MENU_EFFECT_NUM;
	int i;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

    for (i = 0; i < MAX_PHNSET_MENU_EFFECT_NUM; i++)
    {
		subMenuDataPtrs[i + 1] = GetString(STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL + i);
    }
	subMenuDataPtrs[0] = GetString(STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_SHUFFLE);

	radio_button_menu.group_id = GRP_ID_PHNSET_VUI_MAINMENU_EFFECT;
	radio_button_menu.menu_title_str_id = STR_ID_VUI_PHNSET_KEY_LAUNCHER_MAINMENU_EFFECT;
	radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
	radio_button_menu.menu_item_num = nNumofItem;
	radio_button_menu.menu_item_str_list = subMenuDataPtrs;
	radio_button_menu.menu_item_str_id_list = NULL;
	radio_button_menu.highlighted_item_idx = selected_menu_effect;

	mmi_phnset_init_radio_button_menu(&radio_button_menu);

}
/*****************************************************************************
* FUNCTION
*  mmi_phnset_menu_effect_entry_preview
* DESCRIPTION
* main menu effect preview.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_phnset_menu_effect_type_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phnset_menu_transition_type_enum type;
	U16 strID;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	type = mmi_phnset_menu_effect_get_menu_transition_type();
	if(type == MMI_PHNSET_VCP_PAGE_MENU_TRANSITION_TYPE_SHUFFLE)
	{
		strID = STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_SHUFFLE;
	}
	else
	{
		strID = STR_ID_VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL + type - 1;
	}
	cui_menu_set_item_hint(
		mmi_frm_group_get_active_id(),
        MENU_ID_VUI_PHNSET_MAINMENU_EFFECT,
        (WCHAR*)GetString(strID));

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
#if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
#endif 
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
#endif

/*****************************************************************************
* FUNCTION
*  mmi_phnset_menu_effect_set
* DESCRIPTION
* main menu effect set to nvram.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_phnset_menu_effect_set(U8 hlite)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 Err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	selected_menu_effect = hlite;
	WriteValue(NVRAM_MAIN_MENU_EFFECT_CURR_SELECTED, &selected_menu_effect, DS_BYTE, &Err);
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
	//mmi_phnset_menu_effect_exit_preview();
	mmi_frm_group_close(GRP_ID_PHNSET_VUI_MAINMENU_EFFECT);

}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_menu_effect_init
* DESCRIPTION
* main menu effect init function in bootup.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_phnset_menu_effect_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 Err;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_MAIN_MENU_EFFECT_CURR_SELECTED, &selected_menu_effect, DS_BYTE, &Err);
	return;
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif

/*****************************************************************************
* FUNCTION
*  mmi_phnset_menu_effect_get_menu_transition_type
* DESCRIPTION
* api for app to get menu effect settings.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
mmi_phnset_menu_transition_type_enum mmi_phnset_menu_effect_get_menu_transition_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 Err;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_MAIN_MENU_EFFECT_CURR_SELECTED, &selected_menu_effect, DS_BYTE, &Err);
	return (mmi_phnset_menu_transition_type_enum)selected_menu_effect;
}

/*****************************************************************************
* FUNCTION
*  mmi_phnset_menu_effect_set_menu_transition_type
* DESCRIPTION
* api for app to set menu effect settings.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_phnset_menu_effect_set_menu_transition_type(mmi_phnset_menu_transition_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 Err;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	WriteValue(NVRAM_MAIN_MENU_EFFECT_CURR_SELECTED, &type, DS_BYTE, &Err);
	selected_menu_effect = (U8)type;
}

#endif

