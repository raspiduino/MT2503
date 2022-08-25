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
 * BrowserUIDraw.c
 *
 * Project:
 * --------
 *   MAUI
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPUIDRAW_C
#define MMI_BROWSERAPPUIDRAW_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppTypes.h"
#include "BrowserAppScrDB.h"
#include "BrowserAppMain.h"
#include "BrowserAppUICallback.h"
#include "BrowserAppDmgr.h"

#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_browser_def.h"
#include "GlobalMenuItems.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
#include "GlobalConstants.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "wgui_categories_search.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "wgui_categories_multimedia.h"
#include "BrowserResDef.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_text_viewer.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "BrowserSrvConfig.h"
#include "BrowserSrvProts.h"
#include "Unicodexdcl.h"
/* RHR activity */


static FuncPtr lsk_hdlr;
static FuncPtr rsk_hdlr;

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_dynamic_list_screen_func
 * DESCRIPTION
 *  This function is to draw the dynamic list menu screen (for category 184)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_ui_draw_dynamic_list_screen_func(U16 scr_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
	mmi_brw_app_screenDB_struct *scrDB = NULL;
	mmi_brw_app_resourceDB_struct *resourceDB = NULL;
	mmi_brw_app_scrhdlr_dynamic_screen_struct *screen = NULL;
	U16 title_id;
    MMI_ID grp_id;
    S32 highlighted_item = 0;
    U16 title_icon;
	S32 category_error_flag;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* implement category 184 */
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;
    screen = scrDB->screen;
    grp_id = mmi_brw_app_get_grp_id_by_scrn_id(scrDB->scrn_id);

    if(mmi_frm_scrn_enter(
        grp_id, 
        scrDB->scrn_id, 
        scrDB->exit_screen, 
        scrDB->entry_screen, 
        MMI_FRM_FULL_SCRN))
    {

        //EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, scrDB->entry_screen,  NULL);

        //gui_buffer = GetCurrGuiBuffer(scrDB->scrn_id);
        mmi_frm_scrn_set_user_data(grp_id, scrDB->scrn_id, (void *)scrDB);
	    
        gui_buffer = mmi_frm_scrn_get_gui_buf(grp_id, scrDB->scrn_id);


    SetParentHandler(0);
	if(resourceDB->title_str_id)
	{
		title_id = resourceDB->title_str_id;
	}
	else
	{
		title_id = mmi_brw_app_get_title_string_id(scrDB->scrn_id);
	}
    if(scrDB->hilite_handler)
    {
        RegisterHighlightHandler(scrDB->hilite_handler);
    }

#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
#ifdef __MMI_ICON_BAR_SUPPORT__
    if (screen->show_toolbar_func != NULL)
    {
        screen->show_toolbar_func();
    }
#endif
#endif /* #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */
    highlighted_item = mmi_brw_app_set_dynamic_list_highlighted_item(scr_id, &gui_buffer);

#ifndef __MMI_WGUI_DISABLE_CSK__ 
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
    if(scr_id != SCR_ID_BRW_SELECT_BOOKMARK)
        title_icon = mmi_brw_app_get_title_icon(resourceDB->title_icon_id);
    else
#endif
        title_icon = GetRootTitleIcon(SERVICES_WAP_MENU_ID);

#ifndef __MMI_BRW_IMG_RES_SLIM__
    ShowCategory284Screen(
        title_id,
        title_icon,
        resourceDB->lsk_str_id,
        0,
        resourceDB->rsk_str_id,
        0,
        screen->number_of_items,
        mmi_brw_app_get_dynamic_list_callback_func(scrDB->scrn_id),
        NULL,
        highlighted_item,
        gui_buffer);
#else
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);
    wgui_cat1043_show(
        title_id,
        title_icon,
        resourceDB->lsk_str_id,
        resourceDB->rsk_str_id,
        screen->number_of_items,
        screen->dynamic_list_handler,
        NULL,
        highlighted_item,
        0,
        0,
        0,
        gui_buffer,
        &category_error_flag);
    wgui_restore_list_menu_slim_style();
#endif

	if (scrDB->delete_screen_handler != NULL)
	{
		    //mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
            mmi_frm_scrn_set_leave_proc(grp_id, scrDB->scrn_id, scrDB->delete_screen_handler);
	}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    if (screen->tap_callback_func != NULL)
    {
        wgui_register_tap_callback (screen->tap_callback_func);
    }
#endif /* __MMI_FTE_SUPPORT__ */

	if(!(screen->number_of_items))
	{
    #ifndef __MMI_WGUI_DISABLE_CSK__ 
		ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    #endif
		SetCenterSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
	}
    if (scrDB->lsk_func)
    {
        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
    }

    if (scrDB->rsk_func)
    {
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
    }
    else
    {
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
    }   
    return MMI_BRW_TRUE;
}


#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_enter_url_editor_screen_func
 * DESCRIPTION
 *  This function is to draw the auto URL completion editor screen 
 * (for category 103)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_ui_draw_enter_url_editor_screen_func(U16 scr_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 matched_items = 0;
    mmi_brw_app_screenDB_struct *scrDB = NULL;
    mmi_brw_app_resourceDB_struct *resourceDB = NULL;
    mmi_brw_app_scrhdlr_enter_url_screen_struct* url_scr = NULL;
    U32 input_type = IMM_INPUT_TYPE_URL;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* implement 103 category */
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;
    url_scr = (mmi_brw_app_scrhdlr_enter_url_screen_struct*)scrDB->screen;

	if(scrDB == NULL || url_scr == NULL || resourceDB == NULL)
    {
		MMI_ASSERT(0);
	}
	if(scrDB->entry_screen == NULL)
	{
		MMI_ASSERT(0);
	}
	else
    {
        if(mmi_frm_scrn_enter(
            g_brw_app_cntx.brw_scr_group_id, 
            scrDB->scrn_id, 
            scrDB->exit_screen, 
            scrDB->entry_screen, 
            MMI_FRM_FULL_SCRN))
        {

            mmi_frm_scrn_set_user_data(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, (void *)scrDB);
	        
            guiBuffer = mmi_frm_scrn_get_gui_buf(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id);

            wgui_cat103_register_highlight_handler(scrDB->hilite_handler);

            if (url_scr->get_number_of_matched_items_func)
            {
                matched_items = url_scr->get_number_of_matched_items_func();
            }
            input_type = IMM_INPUT_TYPE_SENTENCE;
            ShowCategory103Screen(
                (UI_string_type) GetString(resourceDB->title_str_id),
                get_image(mmi_brw_app_get_title_icon(resourceDB->title_icon_id)),
                (UI_string_type) GetString(resourceDB->lsk_str_id),
                get_image(resourceDB->lsk_icon_id),
                (UI_string_type) GetString(resourceDB->rsk_str_id),
                get_image(resourceDB->rsk_icon_id),
                matched_items,
                url_scr->hilighted_item,
                url_scr->get_matched_item_func,
                url_scr->get_hint_func,
                url_scr->search_func,
                (U8*) url_scr->buffer,
                url_scr->buffer_length,
                input_type,
                guiBuffer);

            #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
                wgui_register_tap_callback(mmi_brw_app_ui_callback_enter_url_tap);
            #endif

	        if (scrDB->delete_screen_handler != NULL)
	        {
		        //mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
                mmi_frm_scrn_set_leave_proc(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, scrDB->delete_screen_handler);
	        }
	        if(scrDB->lsk_func != NULL)
	        {
		        SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
	        }
	        if(scrDB->rsk_func != NULL)
	        {
                wgui_cat103_set_right_softkey_function(scrDB->rsk_func, KEY_EVENT_UP);
	        }
        #ifndef __MMI_WGUI_DISABLE_CSK__ 
            ChangeCenterSoftkey(0, IMG_GLOBAL_WEB_BROWSER_CSK);
        #endif
            SetCenterSoftkeyFunction(mmi_brw_app_dmgr_add_search_or_input_url_item, KEY_EVENT_UP);
        }
    }
    return MMI_BRW_TRUE;
}
#endif /* __MMI_BRW_URL_AUTO_COMPLETION__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_splash_screen_func
 * DESCRIPTION
 *  This function is to draw the image screen small screen(for category 132)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_ui_draw_splash_screen_func(U16 scr_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    mmi_brw_app_screenDB_struct *scrDB = NULL;
	mmi_brw_app_resourceDB_struct *resourceDB = NULL;
	mmi_brw_app_scrhdlr_img_screen_struct* img_scr = NULL;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* implement 132 category */
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;
    img_scr = (mmi_brw_app_scrhdlr_img_screen_struct*)scrDB->screen;

	if(scrDB == NULL || img_scr == NULL || resourceDB == NULL)
    {
		MMI_ASSERT(0);
	}
	if(scrDB->entry_screen == NULL)
	{
		MMI_ASSERT(0);
	}
	else
    {
        if(mmi_frm_scrn_enter(
            g_brw_app_cntx.brw_scr_group_id, 
            scrDB->scrn_id, 
            scrDB->exit_screen, 
            scrDB->entry_screen, 
            MMI_FRM_FULL_SCRN))
        {

		    //EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, NULL, NULL);

            //guiBuffer = GetCurrGuiBuffer(scrDB->scrn_id);
            mmi_frm_scrn_set_user_data(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, (void *)scrDB);
	        
            guiBuffer = mmi_frm_scrn_get_gui_buf(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id);

        #ifdef __OP02__
            wgui_title_set_in_wap(MMI_TRUE);
            wgui_cat154_set_owner_draw_softkey( MMI_TRUE);
            ShowCategory154Screen(
                resourceDB->title_str_id,
                resourceDB->title_icon_id,
                resourceDB->lsk_str_id,
                resourceDB->lsk_icon_id,
                resourceDB->rsk_str_id,
                resourceDB->rsk_icon_id,
                (U8*)GetString(STR_ID_BRW_SPLASH_CONNECTING),
                NULL,
                img_scr->img_id, 
                guiBuffer);
        #else /* __OP02__ */
                if (img_scr->enable_full_screen_check_func)
                {
                    if(img_scr->enable_full_screen_check_func())
                    {
                        wgui_cat132_enable_fullscreen();
                    }
                }
                /* add the internet services string and default wap icon in the resource database */
                /* Run the timer in the post function of this screen handler  */
                ShowCategory132Screen(
                    (U8*)GetString(resourceDB->title_str_id),
                    resourceDB->title_icon_id,
                    resourceDB->lsk_str_id,
                    resourceDB->lsk_icon_id,
                    resourceDB->rsk_str_id,
                    resourceDB->rsk_icon_id,
                    img_scr->img_id, 
                    guiBuffer);
        #endif /* __OP02__ */

			if (scrDB->delete_screen_handler != NULL)
			{
						//mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
						mmi_frm_scrn_set_leave_proc(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, scrDB->delete_screen_handler);
			}
			if(scrDB->lsk_func != NULL)
			{
				SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
			}
			if(scrDB->rsk_func != NULL)
			{
				SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
			}
        }
    }
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_rendered_page_screen_func
 * DESCRIPTION
 *  This function is to draw the rendered page screen (for category 431)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_ui_draw_rendered_page_screen_func(U16 scr_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    mmi_brw_app_screenDB_struct *scrDB = NULL;
	mmi_brw_app_resourceDB_struct *resourceDB = NULL;
	mmi_brw_app_scrhdlr_rendered_page_screen_struct* ren_page_scr = NULL;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* implement 431 category */
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;
    ren_page_scr = (mmi_brw_app_scrhdlr_rendered_page_screen_struct*)scrDB->screen;

	if(scrDB == NULL || ren_page_scr == NULL || resourceDB == NULL)
    {
		MMI_ASSERT(0);
	}
	if(scrDB->entry_screen == NULL)
	{
		MMI_ASSERT(0);
	}
	else
    {
        if(mmi_frm_scrn_enter(
            BRW_RENDERED_PAGE_GRP_ID, 
            scrDB->scrn_id, 
            scrDB->exit_screen, 
            scrDB->entry_screen, 
            MMI_FRM_FULL_SCRN))
        {

            mmi_frm_scrn_set_user_data(BRW_RENDERED_PAGE_GRP_ID, scrDB->scrn_id, (void *)scrDB);
	        
            guiBuffer = mmi_frm_scrn_get_gui_buf(BRW_RENDERED_PAGE_GRP_ID, scrDB->scrn_id);

		#ifdef __MMI_FTE_SUPPORT__
        #ifdef __MMI_ICON_BAR_SUPPORT__
			if (ren_page_scr->show_toolbar_func != NULL)
			{
				ren_page_scr->show_toolbar_func();
			}
        #endif
		#endif /* __MMI_FTE_SUPPORT__ */
        #ifdef __OP02__
            wgui_title_set_in_wap(MMI_TRUE);
        #endif /* __OP02__ */

			/* Perform the task to notify BAM and other things in post func of screen database */
			ShowCategory431Screen(
				(U8*) ren_page_scr->title_str_buffer,
				ren_page_scr->title_icon,
				ren_page_scr->security_icon,
				0,
				0,
				0,
				0,
				ren_page_scr->pen_handler_func,
				ren_page_scr->screen_size_status,
				ren_page_scr->percentage,
				ren_page_scr->display_str,
				guiBuffer);

			if (scrDB->delete_screen_handler != NULL)
			{
				//mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
				mmi_frm_scrn_set_leave_proc(BRW_RENDERED_PAGE_GRP_ID, scrDB->scrn_id, scrDB->delete_screen_handler);
			}
			if(scrDB->lsk_func != NULL)
			{
				SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
			}
			if(scrDB->rsk_func != NULL)
			{
				SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
			}
        }
    }
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_progressing_screen_func
 * DESCRIPTION
 *  This function is to draw the progressing small screen (for category 66)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_ui_draw_progressing_screen_func(U16 scr_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    mmi_brw_app_screenDB_struct *scrDB = NULL;
	mmi_brw_app_resourceDB_struct *resourceDB = NULL;
	mmi_brw_app_scrhdlr_small_screen_struct* progress_scr = NULL;
    mmi_frm_scrn_type_enum scrn_type = MMI_FRM_FULL_SCRN;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* implement 66 category */
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;
    progress_scr = (mmi_brw_app_scrhdlr_small_screen_struct*)scrDB->screen;

	if(scrDB == NULL || progress_scr == NULL || resourceDB == NULL)
    {
		MMI_ASSERT(0);
	}
	if(scrDB->entry_screen == NULL && scrDB->exit_screen == NULL)
	{
		MMI_ASSERT(0);
	}
	else
    {
        if(scr_id == SCR_ID_BRW_TEMP_BUSY_SCREEN)
        {
            scrn_type = MMI_FRM_FG_ONLY_SCRN;
        }
        if(mmi_frm_scrn_enter(
            g_brw_app_cntx.brw_scr_group_id, 
            scrDB->scrn_id, 
            scrDB->exit_screen, 
            scrDB->entry_screen, 
            scrn_type))
        {
			//EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, NULL, NULL);
			mmi_frm_scrn_set_user_data(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, (void *)scrDB);
			
			//guiBuffer = GetCurrGuiBuffer(scrDB->scrn_id);
			guiBuffer = mmi_frm_scrn_get_gui_buf(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id);

			/* clear all the key handlers in post function  */
			ShowCategory66Screen(
				progress_scr->title_str_id,
				mmi_brw_app_get_title_icon(resourceDB->title_icon_id),
				0,
				0,
				0,
				0,
				(U8*) GetString(progress_scr->display_msg_str_id),
				progress_scr->msg_img_id,
				guiBuffer);

			if (scrDB->delete_screen_handler != NULL)
			{
				//mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
				mmi_frm_scrn_set_leave_proc(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, scrDB->delete_screen_handler);
			}
			if(scrDB->lsk_func != NULL)
			{
				SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
			}
			if(scrDB->rsk_func != NULL)
			{
				SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
			}
        }
    }
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_viewer_screen_func
 * DESCRIPTION
 *  This function is to draw the view content screen (for category 74)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_ui_draw_viewer_screen_func(U16 scr_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    mmi_brw_app_screenDB_struct *scrDB = NULL;
	mmi_brw_app_resourceDB_struct *resourceDB = NULL;
	mmi_brw_app_scrhdlr_view_screen_struct* view_scr = NULL;
    mmi_id screen_group_id = GRP_ID_ROOT;
    U16 title_str_id;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* implement 66 category */
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;
    view_scr = (mmi_brw_app_scrhdlr_view_screen_struct*)scrDB->screen;

	if(scrDB == NULL || view_scr == NULL || resourceDB == NULL)
    {
		MMI_ASSERT(0);
	}
	if(scrDB->entry_screen == NULL)
	{
		MMI_ASSERT(0);
	}
	else
    {
        if (scrDB->scrn_id != SCR_ID_BRW_POST_SESSION_INFO)
        {
            screen_group_id = g_brw_app_cntx.brw_scr_group_id;
        }
        if(mmi_frm_scrn_enter(
            screen_group_id, 
            scrDB->scrn_id, 
            scrDB->exit_screen, 
            scrDB->entry_screen, 
            MMI_FRM_FULL_SCRN))
        {
		//EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, NULL, NULL);
	
        // guiBuffer = GetCurrGuiBuffer(scrDB->scrn_id);
            mmi_frm_scrn_set_user_data(screen_group_id, scrDB->scrn_id, (void *)scrDB);
	        
            guiBuffer = mmi_frm_scrn_get_gui_buf(screen_group_id, scrDB->scrn_id);

    if(resourceDB->title_str_id)
    {
        title_str_id = resourceDB->title_str_id;
    }
    else
    {
        title_str_id = mmi_brw_app_get_title_string_id(scrDB->scrn_id);
    }
    /* clear all the key handlers in post function  */
    ShowCategory74Screen(
        title_str_id,
        mmi_brw_app_get_title_icon(resourceDB->title_icon_id),//GetRootTitleIcon(resourceDB->title_icon_id),
        resourceDB->lsk_str_id,
        resourceDB->lsk_icon_id,
        resourceDB->rsk_str_id,
        resourceDB->rsk_icon_id,        
        (PU8) mmi_brw_app_construct_view_data(scr_id),
        mmi_brw_app_get_viewer_buffer_length(scr_id),
        guiBuffer);

	if (scrDB->delete_screen_handler != NULL)
	{
		        //mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
                mmi_frm_scrn_set_leave_proc(screen_group_id, scrDB->scrn_id, scrDB->delete_screen_handler);
	}
	if(scrDB->lsk_func != NULL)
	{
		SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
	}
	if(scrDB->rsk_func != NULL)
	{
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
	}
        }
    }
    return MMI_BRW_TRUE;
}

//TODO remove
mmi_brw_app_result_enum mmi_brw_app_ui_draw_editor_option_screen_func(U16 scr_id)
{
    /* implement 159 category */
    /* No need i think it will get handled by the Editor CUI */
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_confirmation_screen_func
 * DESCRIPTION
 *  This function is to draw the small screen confirmation popup screen
 *  (for category 165)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_ui_draw_confirmation_screen_func(U16 scr_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    mmi_brw_app_screenDB_struct *scrDB = NULL;
	mmi_brw_app_resourceDB_struct *resourceDB = NULL;
	mmi_brw_app_confirm_screen_struct* confirm_scr = NULL;
    mmi_frm_scrn_type_enum scrn_type = MMI_FRM_SMALL_SCRN;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* implement 165 category */
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;
    confirm_scr = (mmi_brw_app_confirm_screen_struct*)scrDB->screen;

	if(scrDB == NULL || confirm_scr == NULL || resourceDB == NULL)
    {
		MMI_ASSERT(0);
	}
	if(scrDB->entry_screen == NULL)
	{
		MMI_ASSERT(0);
	}
	else
    {
    #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
        if(scr_id == SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN)
        {
            scrn_type = MMI_FRM_FG_ONLY_SCRN;
        }
    #endif
        if(mmi_frm_scrn_enter(
            g_brw_app_cntx.brw_scr_group_id, 
            scrDB->scrn_id, 
            scrDB->exit_screen, 
            scrDB->entry_screen, 
            scrn_type))
        {

		//EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, NULL, NULL);
	
    //guiBuffer = GetCurrGuiBuffer(scrDB->scrn_id);
            mmi_frm_scrn_set_user_data(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, (void *)scrDB);
	        
            guiBuffer = mmi_frm_scrn_get_gui_buf(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id);

#ifndef __MMI_WGUI_DISABLE_CSK__ 
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    /* Check where and how to turn the backlight */
    ShowCategory165Screen(
        confirm_scr->lsk_str_id,
        confirm_scr->lsk_img_id,
        confirm_scr->rsk_str_id,
        confirm_scr->rsk_img_id,
        (UI_string_type)confirm_scr->display_msg,
        confirm_scr->msg_img_id,
        NULL);
    if(!guiBuffer)
    {
        mmi_brw_play_tone(confirm_scr->tone_id);
    }
        
	if (scrDB->delete_screen_handler != NULL)
	{
		//mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
        mmi_frm_scrn_set_leave_proc(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, scrDB->delete_screen_handler);
	}
	if(scrDB->lsk_func != NULL)
	{
		SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
	}
	if(scrDB->rsk_func != NULL)
	{
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
	}
        }
    else
    {
	    if (scrDB->delete_screen_handler != NULL)
	    {
		    //mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
            mmi_frm_scrn_set_user_data(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, (void *)scrDB);
            mmi_frm_scrn_set_leave_proc(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, scrDB->delete_screen_handler);
    }

    }
    }
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_upload_progress_screen_func
 * DESCRIPTION
 *  This function is to draw the upload progress screen (for category 412)
 * PARAMETERS
 *  screen_id      [IN]
 * RETURNS
 *  TRUE if success otherwise FALSE.
 *****************************************************************************/
mmi_brw_app_result_enum mmi_brw_app_ui_draw_upload_progress_screen_func(U16 scr_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    mmi_brw_app_screenDB_struct *scrDB = NULL;
	mmi_brw_app_resourceDB_struct *resourceDB = NULL;
	mmi_brw_app_scrhdlr_upload_screen_struct* upload_scr = NULL;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* implement 412 category */
	scrDB = mmi_brw_app_get_curr_screenDB();
    resourceDB = scrDB->rcDB;
    upload_scr = (mmi_brw_app_scrhdlr_upload_screen_struct*)scrDB->screen;

	if(scrDB == NULL || upload_scr == NULL || resourceDB == NULL)
    {
		MMI_ASSERT(0);
	}
	if(scrDB->entry_screen == NULL)
	{
		MMI_ASSERT(0);
	}
	else
    {
        if(mmi_frm_scrn_enter(
            g_brw_app_cntx.brw_scr_group_id, 
            scrDB->scrn_id, 
            scrDB->exit_screen, 
            scrDB->entry_screen, 
            MMI_FRM_FULL_SCRN))
        {

		        //EntryNewScreen(scrDB->scrn_id, scrDB->exit_screen, NULL, NULL);
	        
            //guiBuffer = GetCurrGuiBuffer(scrDB->scrn_id);
            mmi_frm_scrn_set_user_data(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, (void *)scrDB);
	        
            guiBuffer = mmi_frm_scrn_get_gui_buf(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id);

    ShowCategory412Screen(
        (UI_string_type) GetString(resourceDB->title_str_id),
        (PU8) get_image(mmi_brw_app_get_title_icon(resourceDB->title_icon_id)),
        (UI_string_type) GetString(resourceDB->lsk_str_id),
        get_image(resourceDB->lsk_icon_id),
        (UI_string_type) GetString(upload_scr->rsk_str_id),
        get_image(upload_scr->rsk_icon_id),
        (PU8) GetImage(upload_scr->progress_img_id),
        (UI_string_type) GetString(upload_scr->message_str_id),
        upload_scr->percentage_value,
        upload_scr->message_count,
        (UI_string_type*)upload_scr->display_str,
        guiBuffer);

	if (scrDB->delete_screen_handler != NULL)
	{
		        //mmi_frm_set_destroy_scrn_callback(scrDB->scrn_id, scrDB->delete_screen_handler);
                mmi_frm_scrn_set_leave_proc(g_brw_app_cntx.brw_scr_group_id, scrDB->scrn_id, scrDB->delete_screen_handler);
	}
	if(scrDB->lsk_func != NULL)
	{
		SetLeftSoftkeyFunction(scrDB->lsk_func, KEY_EVENT_UP);
	}
	if(scrDB->rsk_func != NULL)
	{
        SetRightSoftkeyFunction(scrDB->rsk_func, KEY_EVENT_UP);
	}
        }
    }
    return MMI_BRW_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_display_popup
 * DESCRIPTION
 *  Function to display the popup screen
 * PARAMETERS
 *  string          The string to be displayed in popup
 *  event_id        The type of the popup event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_draw_display_popup(U8 *string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID popup_id = GRP_ID_ROOT;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)string,event_id,popup_id,NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_display_popup
 * DESCRIPTION
 *  Function to display the popup screen
 * PARAMETERS
 *  string          The string to be displayed in popup
 *  event_id        The type of the popup event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_draw_display_popup_ext(MMI_STR_ID string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID popup_id = GRP_ID_ROOT;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(string,event_id,popup_id,NULL);
}
mmi_ret mmi_brw_app_ui_display_confirm_callback (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT :
		{
			mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;

			switch(alert->result)
			{
				case MMI_ALERT_CNFM_YES:
					(lsk_hdlr)();
					break;
				case MMI_ALERT_CNFM_NO:
					(rsk_hdlr)();
					break;
			}
		}
	}
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_display_confirm_with_sg
 * DESCRIPTION
 *  Function to display the Confirmation screen in a particular screen group
 * PARAMETERS
 *  message     The message to be displayed on the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_draw_display_confirm_with_sg(UI_string_type message, FuncPtr lsk, FuncPtr rsk, MMI_BOOL need_csk_disabled, MMI_ID scrn_group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_popup;
    mmi_confirm_property_init(&confirm_popup,CNFM_TYPE_YESNO);

    lsk_hdlr = lsk;
    rsk_hdlr = rsk;
	if(need_csk_disabled)
	{
		confirm_popup.f_auto_map_empty_softkey = MMI_FALSE;
	}
    //confirm_popup.user_tag = (void*)message;
    if (scrn_group != GRP_ID_INVALID)
    {
        confirm_popup.parent_id = scrn_group;
    }

    confirm_popup.callback = mmi_brw_app_ui_display_confirm_callback;
    mmi_confirm_display(message, MMI_EVENT_QUERY, &confirm_popup);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_display_confirm
 * DESCRIPTION
 *  Function to display the Confirmation screen
 * PARAMETERS
 *  message     The message to be displayed on the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_draw_display_confirm(UI_string_type message, FuncPtr lsk, FuncPtr rsk, MMI_BOOL need_csk_disabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_ui_draw_display_confirm_with_sg(message, lsk, rsk, need_csk_disabled, g_brw_app_cntx.brw_scr_group_id);
}


#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_ren_page_progressive_bar
 * DESCRIPTION
 *  This function is to display the rendered page Page fetching progress bar
 * PARAMETERS
 *  percentage          [IN]        The percentage of the progress bar that is filled
 *  display_string      [IN]        The String to be displayed on the progress bar
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_draw_ren_page_progressive_bar(S32 percentage, S8 *display_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    if (mmi_brw_app_is_browser_first_accessed_page() || mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
#else /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
    if (mmi_frm_scrn_get_active_id() != SCR_ID_BRW_BROWSER_MAIN)
#endif /* __MMI_BRW_SPLASH_SCREEN_SUPPORT__ */
    {
        return;
    }

    wgui_cat431_display_progressive_bar(percentage, display_string);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_disable_ren_page_progressive_bar
 * DESCRIPTION
 *  This function is to disable the progress bar being displayed on the rendered
 * page screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_draw_disable_ren_page_progressive_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat431_disable_progressive_bar();
}

#endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */


#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_draw_update_upload_status
 * DESCRIPTION
 *  This function is for updating the Upload status in the Upload Progress
 *  screen(cat412screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_draw_update_upload_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_value;
    U32 bytes_sent;
    U32 bytes_total;
    UI_string_type display_str[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bytes_sent = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent;
    bytes_total = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total;

    /* Find the upload percentage */
    percentage_value = (U8) (((float)bytes_sent / bytes_total) * 100);
    /* Call function mmi_brw_format_size_total to get the 
       formatted upload bytes string to display on the screen */
    mmi_brw_app_format_size_total(bytes_sent, bytes_total);
    display_str[0] = (UI_string_type) (subMenuData) + MAX_SUB_MENU_SIZE * 2;
    mmi_asc_to_ucs2((S8*) display_str[0], (S8*) subMenuData[1]);

    Cat412UpdateList((UI_string_type) NULL, percentage_value, 1, display_str);
}
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPUIDRAW_C */
