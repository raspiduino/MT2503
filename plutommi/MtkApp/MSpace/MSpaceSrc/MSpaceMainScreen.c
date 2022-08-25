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
 *   MSpaceMainScreen.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   M Space Src
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "mmi_features.h" 
#ifdef __MMI_MRE_MSPACE__

/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "MMIDataType.h"
#include "MenuCuiGprot.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "MMI_mre_trc.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "stdio.h"
#include "gui.h"
#include "gdi_include.h"
#include "gdi_const.h"
	
#include "vmopt.h"
#include "MRESrvGProt.h"
#include "MREAppMgrSrvGprot.h"
#include "Conversions.h"
	
#include "vmio.h"
#include "vmcert_sdk.h"
#include "vmgettag_sdk.h"
#include "app_str.h"
#include "GlobalConstants.h"
	
#include "MASSrvGprot.h"

#include "MSpaceDef.h"	
#include "MSpaceGprot.h"
#include "MSpaceMainScreen.h"
#include "MSpaceAppScreen.h"
	
#include "mmi_rp_app_mspace_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "liblist.h"


/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
extern mmi_mspace_ms_struct g_mspace_cntx;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Extern Function
*****************************************************************************/

extern void mmi_mspace_get_date_string(WCHAR *date_buff, U32 nYear, U32 nMonth, U32 nDay);


static S32 mmi_mspace_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U16 offset = 0;
	srv_as_app_node_t *app_static_info_list = NULL;	
	srv_as_app_info_t * app_dynamic_info_list = NULL;	
	srv_as_app_node_t *app_static_info_ptr = NULL;
	srv_as_app_info_t *app_dynamic_info_ptr = NULL;	
	kal_wchar wchar_buf[MAX_SUBMENU_CHARACTERS];
	S32 ret;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	app_static_info_list = kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, sizeof(srv_as_app_node_t) * data_size, __FILE__, __LINE__);
	if (app_static_info_list == NULL)
	{
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_STAT_LIST_MEM_FAIL, start_index, data_size);
		return MMI_FALSE;
	}
	app_dynamic_info_list = kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, sizeof(srv_as_app_info_t) * data_size, __FILE__, __LINE__);
	if (app_dynamic_info_list == NULL)
	{	
		kal_adm_free(g_mspace_cntx.adm_pool_id, app_static_info_list);
		app_static_info_list = NULL;
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_DYNM_LIST_MEM_FAIL, start_index, data_size);
		return MMI_FALSE;
	}

	ret = srv_as_list_get_info(start_index, data_size, app_static_info_list, app_dynamic_info_list);
	if (ret < 0)
	{
		kal_adm_free(g_mspace_cntx.adm_pool_id, app_static_info_list);
		kal_adm_free(g_mspace_cntx.adm_pool_id, app_dynamic_info_list);
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_LIST_INFO_FAIL, start_index, data_size, ret);
		return MMI_FALSE;
	}


    for (i = 0; i < data_size; i++)
    {
        S16 index = (S16)(start_index + i);

        if (index < g_mspace_cntx.app_num)
        {
			app_static_info_ptr = app_static_info_list + i;
			app_dynamic_info_ptr = app_dynamic_info_list + i;

			mmi_wcsncpy(menu_data[i].item_list[0], (app_static_info_ptr->dis_name), MAX_SUBMENU_CHARACTERS);

			mmi_mspace_get_date_string(wchar_buf, app_static_info_ptr->year, app_static_info_ptr->month, app_static_info_ptr->day);
			mmi_wcsncpy(menu_data[i].item_list[1], wchar_buf, MAX_SUBMENU_CHARACTERS);
			
			menu_data[i].image_list[0] = get_image(0);


			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GI_APP_STATUS, app_dynamic_info_ptr->status);

			switch ( app_dynamic_info_ptr->status )
			{
				case SRV_AS_APP_STATUS_AVAIL_UPDATE:			
					menu_data[i].image_list[1] = get_image(IMG_ID_MSPACE_APP_STATUS_UPDATE_ICON);
					break;
				case SRV_AS_APP_STATUS_NO_AVAIL_UPDATE:			
					menu_data[i].image_list[1] = get_image(IMG_ID_MSPACE_APP_STATUS_INSTALLED_ICON);
					break;
				case SRV_AS_APP_STATUS_NEW:			
					menu_data[i].image_list[1] = get_image(0);
					break;
				case SRV_AS_APP_STATUS_GONE:			
					menu_data[i].image_list[1] = get_image(IMG_ID_MSPACE_APP_STATUS_INSTALLED_ICON);
					break;
				default:
					menu_data[i].image_list[1] = get_image(0);
					break;
			}
        }
		else
		{
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_INVALID_ITEM_INDEX, index, g_mspace_cntx.app_num);
		}
    }

	kal_adm_free(g_mspace_cntx.adm_pool_id, app_static_info_list);
	kal_adm_free(g_mspace_cntx.adm_pool_id, app_dynamic_info_list);

    return i;
}

void mmi_mspace_get_menuitem_info(S32 item_idx, wgui_thumbnail_info_struct *menuitem_data)
{
	switch (item_idx)
	{
		default:
			menuitem_data->is_show_thumb = MMI_TRUE;
			break;
	}
}


MMI_BOOL mmi_mspace_get_image_info(S32 index, wgui_thumbnail_img_info_struct* image_info)
{
	S32 ret;
	
	if (g_mspace_cntx.get_app_static_info == NULL)
	{
		g_mspace_cntx.get_app_static_info = kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, sizeof(srv_as_app_node_t), __FILE__, __LINE__);
		if (g_mspace_cntx.get_app_static_info == NULL)
		{
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_IMG_STAT_INFO_MEM_FAIL, index);
			return MMI_FALSE;
		}
	}
	
	ret = srv_as_list_get_info(index, 1, g_mspace_cntx.get_app_static_info, NULL);
	if (ret < 0)
	{
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_IMG_APP_INFO_FAIL, ret, index);
		return MMI_FALSE;	
	}	

	if (g_mspace_cntx.get_app_icon== NULL)
	{
		g_mspace_cntx.get_app_icon = kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, g_mspace_cntx.get_app_static_info->icon_size, __FILE__, __LINE__);
		if (g_mspace_cntx.get_app_icon == NULL)
		{
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_IMG_APP_ICON_MEM_FAIL, index, g_mspace_cntx.get_app_static_info->icon_size);
			return MMI_FALSE;
		}
		g_mspace_cntx.get_app_icon_max_size = g_mspace_cntx.get_app_static_info->icon_size;
	}
	else
	{
		if (g_mspace_cntx.get_app_static_info->icon_size > g_mspace_cntx.get_app_icon_max_size)
		{
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_IMG_NEW_MAX_SIZE, g_mspace_cntx.get_app_static_info->icon_size, g_mspace_cntx.get_app_icon_max_size);
		
			if (g_mspace_cntx.get_app_icon != NULL)
				kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.get_app_icon);

			g_mspace_cntx.get_app_icon = kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, g_mspace_cntx.get_app_static_info->icon_size, __FILE__, __LINE__);
			if (g_mspace_cntx.get_app_icon == NULL)
			{
				MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_IMG_APP_ICON_MEM_FAIL, index, g_mspace_cntx.get_app_static_info->icon_size);
				return MMI_FALSE;
			}

			g_mspace_cntx.get_app_icon_max_size = g_mspace_cntx.get_app_static_info->icon_size;
		}
	}

	ret = srv_as_list_get_icon(index, g_mspace_cntx.get_app_icon, g_mspace_cntx.get_app_static_info->icon_size);
	if (ret < 0)
	{		
		MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_GET_IMG_ICON_INFO_FAIL, ret, index);
		return MMI_FALSE;
	}


	image_info->img_ptr = g_mspace_cntx.get_app_icon;
	image_info->img_src = WGUI_THUMBNAIL_IMG_SRC_TYPE_RESOURCE;

    return MMI_TRUE;
}


void mmi_mspace_main_scrn_lsk_hdlr(void)
{
	MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_MSLH_APP_STATUS, g_mspace_cntx.cur_app_dynamic_info->status);

	switch ( g_mspace_cntx.cur_app_dynamic_info->status )
	{
		case SRV_AS_APP_STATUS_AVAIL_UPDATE:
		{
	        g_mspace_cntx.option_gid = cui_menu_create_and_run(
	                GRP_ID_MSPACE,
	                CUI_MENU_SRC_TYPE_RESOURCE,
	                CUI_MENU_TYPE_OPTION,
	                MENU_ID_MSPACE_OPTIONS_TO_UPDATE,
	                MMI_FALSE, /* Use global resource */
	                NULL);
		}
			break;
		case SRV_AS_APP_STATUS_NEW:
		{
	        g_mspace_cntx.option_gid = cui_menu_create_and_run(
	                GRP_ID_MSPACE,
	                CUI_MENU_SRC_TYPE_RESOURCE,
	                CUI_MENU_TYPE_OPTION,
	                MENU_ID_MSPACE_OPTIONS_TO_INSTALL,
	                MMI_FALSE, /* Use global resource */
	                NULL);
		}
			break;
		case SRV_AS_APP_STATUS_NO_AVAIL_UPDATE:
		{
	        g_mspace_cntx.option_gid = cui_menu_create_and_run(
	                GRP_ID_MSPACE,
	                CUI_MENU_SRC_TYPE_RESOURCE,
	                CUI_MENU_TYPE_OPTION,
	                MENU_ID_MSPACE_OPTIONS_TO_DETAILS,
	                MMI_FALSE, /* Use global resource */
	                NULL);
		}
			break;
        case SRV_AS_APP_STATUS_GONE:
            {
                // as the same as the status of app in mainmenu
                g_mspace_cntx.option_gid = cui_menu_create_and_run(
                        GRP_ID_MSPACE,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        MENU_ID_MSPACE_OPTIONS_TO_DETAILS,
                        MMI_FALSE, /* Use global resource */
                        NULL);
            }
            break;
		default:
			break;
	}
	
}

void mmi_mspace_update_hilite_app_item(S32 index)
{
	S32 ret;
	
	if (g_mspace_cntx.hl_idx == -1 || g_mspace_cntx.hl_idx != index)
	{
		g_mspace_cntx.hl_idx = index;
	
		ret = srv_as_list_get_info(index, 1, g_mspace_cntx.cur_app_static_info, g_mspace_cntx.cur_app_dynamic_info);
		if (ret < 0)
		{
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_HILITE_APP_INFO_FAIL, ret, index);
			return;
		}

		if (g_mspace_cntx.cur_app_icon != NULL)
			kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.cur_app_icon);
		
		g_mspace_cntx.cur_app_icon = kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, g_mspace_cntx.cur_app_static_info->icon_size, __FILE__, __LINE__);
		if (g_mspace_cntx.cur_app_icon == NULL)
		{
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_HILITE_GET_ICON_MEM_FAIL, index, g_mspace_cntx.cur_app_static_info->icon_size);
			return;
		}

		ret = srv_as_list_get_icon(index, g_mspace_cntx.cur_app_icon, g_mspace_cntx.cur_app_static_info->icon_size);
		if (ret < 0)
		{		
			kal_adm_free(g_mspace_cntx.adm_pool_id, g_mspace_cntx.cur_app_icon);
			g_mspace_cntx.cur_app_icon = NULL;
			MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_HILITE_GET_ICON_INFO_FAIL, ret, index);
			return;
		}
	}
}

#if defined(__MMI_TOUCH_SCREEN__)
void mmi_mspace_main_scrn_tap_hdlr(mmi_tap_type_enum tap_type,S32 index)
{
	mmi_mspace_update_hilite_app_item(index);
    mmi_mspace_os_app_open();	
}
#endif


void mmi_mspace_main_scrn_csk_hdlr(void)
{
    mmi_mspace_os_app_open();	
}

void mmi_mspace_main_scrn_hilite_hdlr(S32 index)
{
	mmi_mspace_update_hilite_app_item(index);
}

static void mmi_mspace_eixt_main_scrn(void)
{}

void mmi_mspace_entry_main_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U16 num_of_items;
    U8 *gui_buffer;
    U16 left_softkey, left_softkey_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ENTRY_MAIN_SCRN_S);

    ret = mmi_frm_scrn_enter(GRP_ID_MSPACE, SCR_ID_MSPACE_MAIN, mmi_mspace_eixt_main_scrn, mmi_mspace_entry_main_scrn, MMI_FRM_FULL_SCRN);

    if (ret == MMI_FALSE)
    {
	    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_ENTRY_MAIN_SCRN_FAIL, ret);
        return;
    }

	RegisterHighlightHandler(mmi_mspace_main_scrn_hilite_hdlr);

	gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    wgui_thumbnail_register_get_image_info_func(mmi_mspace_get_menuitem_info);
	wgui_thumbnail_register_get_image_func(mmi_mspace_get_image_info);


	if (g_mspace_cntx.app_num == 0)
	{
		wgui_cat_set_list_menu_empty_lable(get_string(STR_ID_MSPACE_NO_APP));
	
	    wgui_cat1072_show(
	        (PU8)GetString(STR_ID_MSPACE_NAME),
	        (PU8)GetImage(0),
	        0,
	        STR_GLOBAL_EXIT,
	        0,
	        NULL,
	        0,
	        0,
	        IMG_ID_MSPACE_APP_STATUS_DEFAULT_ICON,
	        gui_buffer);		
	}
	else if (g_mspace_cntx.app_num > 0)
	{
	    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		
	    wgui_cat1072_show(
	        (PU8)GetString(STR_ID_MSPACE_NAME),
	        (PU8)GetImage(0),
	        STR_GLOBAL_OPTIONS,
	        STR_GLOBAL_EXIT,
	        g_mspace_cntx.app_num,
	        mmi_mspace_get_item,
	        0,
	        0,
	        IMG_ID_MSPACE_APP_STATUS_DEFAULT_ICON,
	        gui_buffer);

	    SetLeftSoftkeyFunction(mmi_mspace_main_scrn_lsk_hdlr, KEY_EVENT_UP);	
	    SetCenterSoftkeyFunction(mmi_mspace_main_scrn_csk_hdlr, KEY_EVENT_UP);

#if defined(__MMI_TOUCH_SCREEN__)
	    wgui_register_tap_callback(mmi_mspace_main_scrn_tap_hdlr);
#endif
	}
	else
	{
		wgui_cat_set_list_menu_empty_lable(get_string(STR_ID_MSPACE_NO_APP));
	
	    wgui_cat1072_show(
	        (PU8)GetString(STR_ID_MSPACE_NAME),
	        (PU8)GetImage(0),
	        0,
	        STR_GLOBAL_EXIT,
	        0,
	        NULL,
	        0,
	        0,
	        IMG_ID_MSPACE_APP_STATUS_DEFAULT_ICON,
	        gui_buffer);		
	}	// error handling
		

}


#endif /* __MMI_MRE_MSPACE__ */ 

