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
 * BrowserUICallback.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#ifndef MMI_BROWSERAPPUICALLBACK_C
#define MMI_BROWSERAPPUICALLBACK_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"      /* for the global icon list */
#include "BrowserAppTypes.h"      /* for the global context */
#include "BrowserAppMain.h"       /* for various utilityu APIs */

#include "EmailAppGprot.h"      /* for the email API mmi_email_is_email_can_forward */

#include "BrowserAppUICallback.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserSrvProts.h"
#include "DLAgentSrvDef.h"
#include "mmi_rp_app_browser_def.h"
#include "GlobalMenuItems.h"
//#include "SimDetectionGprot.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "CustMenuRes.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h"
#include "BrowserSrvConfig.h"
#include "App_ltlcom.h"
#include "bam_struct.h"
#include "BrowserSrvInterface.h"
#include "string.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "kal_public_api.h"
#include "custom_wap_config.h"
#include "DebugInitDef_Int.h"
#include "common_nvram_editor_data_item.h"
#include "CustDataRes.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "Conversions.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalResDef.h"
//#include "tcm_common.h"
#include "wgui_touch_screen.h"
#include "BrowserAppScrDB.h"
#include "SimCtrlSrvGprot.h"
#include "DLAgentSrvGprot.h"

#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
extern const custom_wap_embed_link_struct wap_embed_link_default;
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_bookmarks_list_csk_hdlr
 * DESCRIPTION
 *  Tap Callback function for bookmark list screen
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_bookmarks_list_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    if(g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].type == SRV_BRW_BKM_TYPE_FOLDER)
    {
        mmi_brw_app_dmgr_open_bookmark_folder();
    }
    else
#endif
    {
        mmi_brw_app_dmgr_launch_bookmark();
    }
}

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_bookmarks_browse_path_list_csk_hdlr
 * DESCRIPTION
 *  Tap Callback function for bookmark list screen
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_bookmarks_browse_path_list_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
    {
        mmi_brw_app_if_browse_path_open_folder();
    }
    else
    {
        mmi_brw_app_dmgr_browse_path_select_folder();
    }

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_trusted_certificate_csk_hdlr
 * DESCRIPTION
 *  Tap Callback function for trusted cert list screen
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_trusted_certificate_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_app_cntx.brw_dynamic_cntx_p->view_type = BRW_VIEW_TRUSTED_CERTIFICATE;
	mmi_brw_app_if_show_view_certificate_screen();
}


#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_shortcuts_list_csk_hdlr
 * DESCRIPTION
 *  CSK handler function for the shortcut list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_shortcuts_list_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_brw_shortcut_list_is_item_empty(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item))
    {
        mmi_brw_app_dmgr_pre_entry_add_shortcut();
    }
    else
    {
        mmi_brw_app_dmgr_launch_shortcut();
    }
}
#endif

#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_wap_scr_num_of_items
 * DESCRIPTION
 *  This function is to get the number of items in wap menu when embedded links
 * feature is enabled
 * PARAMETERS
 *  menu_id      [IN]
 * RETURNS
 *  number of items.
 *****************************************************************************/
U32 mmi_brw_app_ui_callback_get_wap_scr_num_of_items (U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_of_items = 0;
    U8 num_of_embed_links = 0;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_items = (U32)GetNumOfChild_Ext(menu_id);

    for (index = 0; index < wap_embed_link_default.max_n_embed_links; index++)
    {
        if (!wap_embed_link_default.embed_link[index].empty)
        {
            ++num_of_embed_links;
        }
    }
    return (num_of_items + num_of_embed_links);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_wap_scr_list_of_icons
 * DESCRIPTION
 *  This function is to get the list of icons for the childrens of the WAP menu
 * when embedded link is enabled.
 * PARAMETERS
 *  menu_id      [IN]
 * RETURNS
 *  number of items.
 *****************************************************************************/
U16 mmi_brw_app_ui_callback_get_wap_scr_list_of_icons(U16 menu_id, U16 *image_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_of_items = 0;
    U8 num_of_embed_links = 0;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_items = (U16)GetSequenceImageIds_Ext(menu_id, image_ids);

    for (index = 0; index < wap_embed_link_default.max_n_embed_links; index++)
    {
        if (!wap_embed_link_default.embed_link[index].empty)
        {
            image_ids[num_of_items + num_of_embed_links] = IMG_ID_BRW_BOOKMARKS;
            ++num_of_embed_links;
        }
    }
}
#endif /* __MMI_OP12_BRW_EMBEDDED_LINKS__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_wap_scr_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the internet services screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_wap_scr_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    /* if background download is not active */
    mmi_brw_app_adjust_hide_highlight_menu_item(
        //!(!g_srv_brw_cntx.download_info_p || !g_srv_brw_cntx.download_info_p->job_count),
        srv_da_get_job_count() > 0,
        MENU_ID_BRW_REN_PAGE_DOWNLOADS, 
        SERVICES_WAP_MENU_ID, 
        gui_buffer, 
        SCR_ID_BRW_INTERNET_SERVICES);
    if(!srv_da_get_job_count()
        && g_brw_app_cntx.brw_dynamic_cntx_p->wap_highlighted_menu == MENU_ID_BRW_REN_PAGE_DOWNLOADS)
    {
    #ifdef __MMI_OP12_BRW_SEARCH_MENU__
        g_brw_app_cntx.brw_dynamic_cntx_p->wap_highlighted_menu = MENU_ID_BRW_SEARCH_WEB;
    #else
        g_brw_app_cntx.brw_dynamic_cntx_p->wap_highlighted_menu = MENU_ID_BRW_HOMEPAGE;
    #endif
    }
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */ 
}


#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_wap_scr_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the internet services screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_shortcut_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_shortcut_empty;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    /* if background download is not active */
    mmi_brw_app_adjust_hide_highlight_menu_item(
        !(!g_srv_brw_cntx.download_info_p || !g_srv_brw_cntx.download_info_p->job_count), 
        MENU_ID_BRW_REN_PAGE_DOWNLOADS, 
        SERVICES_WAP_MENU_ID, 
        gui_buffer, 
        SCR_ID_BRW_INTERNET_SERVICES);
    if((!g_srv_brw_cntx.download_info_p || !g_srv_brw_cntx.download_info_p->job_count)
        && g_brw_app_cntx.brw_dynamic_cntx_p->wap_highlighted_menu == MENU_ID_BRW_REN_PAGE_DOWNLOADS)
    {
    #ifdef __MMI_OP12_BRW_SEARCH_MENU__
        g_brw_app_cntx.brw_dynamic_cntx_p->wap_highlighted_menu = MENU_ID_BRW_SEARCH_WEB;
    #else
        g_brw_app_cntx.brw_dynamic_cntx_p->wap_highlighted_menu = MENU_ID_BRW_HOMEPAGE;
    #endif
    }
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */ 
    is_shortcut_empty = srv_brw_shortcut_list_is_item_empty(g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item);
    mmi_brw_app_hide_menu_item(is_shortcut_empty, MENU_ID_BRW_LAUNCH_PAGE_GOTO);
    mmi_brw_app_hide_menu_item(is_shortcut_empty, MENU_ID_BRW_LAUNCH_PAGE_EDIT_SHORTCUT);
    mmi_brw_app_hide_menu_item(is_shortcut_empty, MENU_ID_BRW_LAUNCH_PAGE_DELETE_SHORTCUT);
    mmi_brw_app_hide_menu_item(!is_shortcut_empty, MENU_ID_BRW_LAUNCH_PAGE_ADD_SHORTCUT);
}
#endif

#ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_bookmark_options_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Bookmark list options 
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_bookmark_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_hide_menu_item(!mmi_brw_is_transferring_media_available(), MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS);

#if defined(MMS_SUPPORT)
    mmi_brw_app_hide_menu_item(!mmi_brw_app_check_mms_is_ready(), MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_MMS);
#endif /* defined(MMS_SUPPORT) */ 

    mmi_brw_app_hide_menu_item(srv_sms_is_hide_send_sms_menu_item(), MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_SMS);

    if (!mmi_bootup_is_sim_valid()
#if defined (__FLIGHT_MODE_SUPPORT__)
        || (!srv_mode_switch_is_network_service_available())
#endif 
        )
    {
    #if defined(__MMI_IRDA_SUPPORT__)
        mmi_frm_hide_menu_item(MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_INFRARED);
    #endif 
    }
    else
    {
    #if defined(__MMI_IRDA_SUPPORT__)
        mmi_frm_unhide_menu_item(MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_INFRARED);
    #endif 
    }

#if defined(__MMI_OPP_SUPPORT__)
    mmi_brw_app_hide_menu_item(!mmi_bt_is_to_display_bt_menu(), MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_BLUETOOTH);
#endif /* defined(__MMI_OPP_SUPPORT__) */ 

#if defined(__MMI_EMAIL__)
    mmi_brw_app_hide_menu_item(!mmi_email_is_email_can_forward(), MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_EMAIL);
#endif /* defined(__MMI_EMAIL__) */

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    mmi_brw_app_hide_menu_item((g_brw_bkm_cntx.sel_folder_name[0] != 0), MENU_ID_BRW_BKM_CREATE_FOLDER);
#endif
}
#endif

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_browser_path_options_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Bookmark Browser path 
 * list options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_browser_path_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
    {
        mmi_frm_hide_menu_item(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_CREATE_FOLDER);
        mmi_frm_unhide_menu_item(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_OPEN_FOLDER);
        mmi_frm_unhide_menu_item(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_SELECT);
    }
    else
    {
        mmi_brw_app_hide_menu_item(!(g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_name[0] == 0), MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_CREATE_FOLDER);
        mmi_brw_app_hide_menu_item(!g_brw_bkm_cntx.bkm_dynamic_cntx->total_folder_count, MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_SELECT);
        mmi_brw_app_hide_menu_item((g_brw_bkm_cntx.bkm_dynamic_cntx->sel_folder_name[0] == 0), MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_OPEN_FOLDER);
    }
}
#endif

#ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_send_address_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Send Address options 
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_send_address_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(MMS_SUPPORT)
    mmi_brw_app_hide_menu_item(!mmi_brw_app_check_mms_is_ready(), MENU_ID_BRW_SEND_ADDRESS_AS_MMS);
#endif /* defined(MMS_SUPPORT) */ 

    if (!mmi_bootup_is_sim_valid()
#if defined (__FLIGHT_MODE_SUPPORT__)
        || (!srv_mode_switch_is_network_service_available())
#endif 
        )
    {
    #if defined(__MMI_IRDA_SUPPORT__)
        mmi_frm_hide_menu_item(MENU_ID_BRW_SEND_ADDRESS_VIA_INFRARED);
    #endif 
    }
    else
    {
    #if defined(__MMI_IRDA_SUPPORT__)
        mmi_frm_unhide_menu_item(MENU_ID_BRW_SEND_ADDRESS_VIA_INFRARED);
    #endif 
    }

#if defined(__MMI_OPP_SUPPORT__)
    mmi_brw_app_hide_menu_item(!mmi_bt_is_to_display_bt_menu(), MENU_ID_BRW_SEND_ADDRESS_VIA_BLUETOOTH);
#endif /* defined(__MMI_OPP_SUPPORT__) */ 

#if defined(__MMI_EMAIL__)
    mmi_brw_app_hide_menu_item(!mmi_email_is_email_can_forward(), MENU_ID_BRW_SEND_ADDRESS_VIA_EMAIL);
#endif /* defined(__MMI_EMAIL__) */
}
#endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_recent_pages_options_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Recent pages list options 
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_recent_pages_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
    mmi_brw_app_hide_menu_item(g_srv_brw_cntx.sorting_method == WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST, MENU_ID_BRW_RECENT_PAGE_SORT);
#endif /* OBIGO_Q05A */
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_page_object_options_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Page Objects options 
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_page_object_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_hide_menu_item((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->selected_page_object_type == BRW_PAGE_OBJECT_TYPE_OTHERS) ||
                                  !strlen((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p->cache_file),
                                  MENU_ID_BRW_PAGE_OBJECTS_SAVE_AS);
}
#endif /* OBIGO_Q05A */
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_ren_page_options_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Rendered Page options 
 * screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_ren_page_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if hyperlink is not selected */
    mmi_brw_app_hide_menu_item(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p ||
        (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_LINK &&
         g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_SUBMIT &&
         g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_INPUT &&
         g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_BUTTON &&
         g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_DO), MENU_ID_BRW_REN_PAGE_GOTO);

    /* if edit box is not selected */
    mmi_brw_app_hide_menu_item(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p ||
        (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_TEXTINPUT &&
         g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_SELECT), MENU_ID_BRW_REN_PAGE_EDIT);

    /* if reset element is not selected */
    mmi_brw_app_hide_menu_item(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p ||
        (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_RESET), MENU_ID_BRW_REN_PAGE_RESET);
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    /* if Select File element is not selected */
    mmi_brw_app_hide_menu_item(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p ||
        (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_FILE_INPUT), MENU_ID_BRW_REN_PAGE_SELECT_FILE);
#endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    /* if background download is not active */
    mmi_brw_app_hide_menu_item(!g_srv_brw_cntx.download_info_p || !g_srv_brw_cntx.download_info_p->job_count, MENU_ID_BRW_REN_PAGE_DOWNLOADS);
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */ 

    mmi_brw_app_hide_menu_item(!srv_brw_is_forward_navigation(), MENU_ID_BRW_REN_PAGE_NAVIGATE_FORWARD);

    mmi_brw_app_hide_menu_item(!srv_brw_is_backward_navigation(), MENU_ID_BRW_REN_PAGE_NAVIGATE_BACKWARD);

#ifndef SLIM_WAP_MMS
    mmi_brw_app_hide_menu_item(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_count, MENU_ID_BRW_REN_PAGE_NAVIGATE_PAGE_ACTIONS);
#endif

#ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
    mmi_brw_app_hide_menu_item(!(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p &&
                               !(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol == WAP_BAM_PROTOCOL_FILE)),
                               MENU_ID_BRW_SEND_ADDRESS_OPTIONS);
#endif


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    mmi_brw_app_hide_menu_item(!(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p &&
                               !(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol == WAP_BAM_PROTOCOL_FILE)),
                               MENU_ID_BRW_REN_PAGE_SET_AS_HOMEPAGE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_select_mode_options_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Picture select mode 
 * options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_select_mode_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If no element is in focus */
    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p)
    {
        mmi_frm_hide_menu_item(MENU_ID_BRW_SELECT_MODE_SAVE_AS);
    #ifdef OBIGO_Q05A
        mmi_frm_hide_menu_item(MENU_ID_BRW_SELECT_MODE_PROPERTIES);
	#endif /* OBIGO_Q05A */
    }
    else /* if something is in focus */
    {
    #ifdef OBIGO_Q05A
        /* if image is not selected */
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_IMAGE)
        {
            mmi_frm_hide_menu_item(MENU_ID_BRW_SELECT_MODE_SAVE_AS);
		#ifdef OBIGO_Q05A
			mmi_frm_hide_menu_item(MENU_ID_BRW_SELECT_MODE_PROPERTIES);
		#endif /* OBIGO_Q05A */
        }
        else
    #endif /* OBIGO_Q05A */
        {
            /* if image is selected & its object file also exist */
            if (strlen((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->object_filePath))
            {
                mmi_frm_unhide_menu_item(MENU_ID_BRW_SELECT_MODE_SAVE_AS);
            }
            /* if image is selected but its object file don't exist */
            else
            {
                mmi_frm_hide_menu_item(MENU_ID_BRW_SELECT_MODE_SAVE_AS);
            }
		#ifdef OBIGO_Q05A
			mmi_frm_unhide_menu_item(MENU_ID_BRW_SELECT_MODE_PROPERTIES);
		#endif /* OBIGO_Q05A */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_advanced_options_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the advanced options menu 
 * options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_advanced_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    mmi_brw_app_hide_menu_item(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p &&
                               ((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol == WAP_BAM_PROTOCOL_FILE) ||
                               (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol == WAP_BAM_PROTOCOL_OTHER)),
                               MENU_ID_BRW_REN_PAGE_STORE_OFFLINE);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_settings_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Browser Settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_settings_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_hide_menu_item(mmi_brw_app_is_screen_present(SCR_ID_BRW_BROWSER_MAIN) || !srv_sim_ctrl_any_sim_is_available(), MENU_ID_BRW_DATA_ACCOUNT);
#ifdef __MMI_CBM_CONNECTION_MANAGER__
    mmi_brw_app_hide_menu_item(!(mmi_brw_app_is_screen_present(SCR_ID_BRW_BROWSER_MAIN)), MENU_ID_BRW_SETTINGS_CONNECTION_INFO);
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_browser_options_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Browser Options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_browser_options_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
    mmi_brw_app_hide_menu_item(!mmi_brw_app_is_screen_present(SCR_ID_BRW_BROWSER_MAIN), MENU_ID_BRW_BROWSER_OPTIONS_ENCODING);
#endif /* OBIGO_Q05A */
#ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
    mmi_brw_app_hide_menu_item(!mmi_brw_app_is_screen_present(SCR_ID_BRW_BROWSER_MAIN), MENU_ID_BRW_BROWSER_OPTIONS_9WAY);
#endif /*  #ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__*/
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    mmi_brw_app_hide_menu_item(!g_srv_brw_cntx.is_http_conn, MENU_ID_BRW_BROWSER_OPTIONS_USE_BAIDU_PROXY);
#endif //#ifdef __BAIDU_TRANSCODING_SUPPORT__
}


#ifdef WAP_SEC_SUPPORT
#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_security_settings_hide_handler
 * DESCRIPTION
 *  This function is the hide handler function for the Security Settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_security_settings_hide_handler(void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_app_hide_menu_item(!mmi_brw_app_is_screen_present(SCR_ID_BRW_BROWSER_MAIN), MENU_ID_BRW_SECURITY_SETTINGS_SESSION_INFO);
    mmi_brw_app_hide_menu_item(!mmi_brw_app_is_screen_present(SCR_ID_BRW_BROWSER_MAIN), MENU_ID_BRW_SECURITY_SETTINGS_CURRENT_CERTIFICATE);
}
#endif /* OBIGO_Q05A */
#endif


#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_number_of_addr_list_matched_items
 * DESCRIPTION
 *  This function is to get the number of matched items in the enter URL screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_brw_app_ui_callback_get_number_of_addr_list_matched_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items;
}
#endif /* __MMI_BRW_URL_AUTO_COMPLETION__ */

#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_number_of_search_list_matched_items
 * DESCRIPTION
 *  This function is to get the number of matched items in the search items list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_brw_app_ui_callback_get_number_of_search_list_matched_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_search_items;
}
#endif /* __MMI_BRW_SEARCH_HISTORY_SUPPORT__ */

#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_matched_items_count
 * DESCRIPTION
 *  This function is to get the number of matched items in the 
 * Auto completion screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_brw_app_ui_callback_get_matched_items_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    count += mmi_brw_app_ui_callback_get_number_of_search_list_matched_items();
#endif
#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    count += mmi_brw_app_ui_callback_get_number_of_addr_list_matched_items();
#endif
    return count;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ui_callback_get_full_screen_status
 * DESCRIPTION
 *  This function is to get the current Browser screen status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE if in full screen mode FALSE otherwise
 *****************************************************************************/
MMI_BOOL mmi_brw_ui_callback_get_full_screen_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_brw_cntx.screen_size_status;
}


#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_matched_address_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of address list Auto URL screen
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_matched_address_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index <= SRV_BRW_ADDRESS_LIST_MAX_ITEMS));

    /* truncate the URL to 38 charactes and append three '.'(dots) if the length of URL exceeds 
       MAX_SUBMENU_CHARACTERS charactes */
    if (strlen((S8*) srv_brw_address_list_get_matched_item(item_index)) > MAX_SUBMENU_CHARACTERS)
    {
        mmi_asc_n_to_ucs2(
            (S8*) str_buff,
            (S8*) srv_brw_address_list_get_matched_item(item_index),
            BRW_MAX_VISIBLE_URL_LENGTH);
        str_buff[BRW_MAX_VISIBLE_URL_LENGTH] = '\0';
        mmi_ucs2cat((S8*) str_buff, (S8*) BRW_MENU_ITEM_TRUNC_STR);
    }
    else
    {
        mmi_asc_to_ucs2(
            (S8*) str_buff,
            (S8*) srv_brw_address_list_get_matched_item(item_index));
    }

    *img_buff_p = get_image(IMG_ID_BRW_LIST_ICON_URL_RESULT);
    return TRUE;
}
#endif /* __MMI_BRW_URL_AUTO_COMPLETION__ */


#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_matched_search_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of address list Auto URL screen
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_matched_search_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index <= SRV_BRW_ADDRESS_LIST_MAX_ITEMS));

    /* truncate the URL to 38 charactes and append three '.'(dots) if the length of URL exceeds 
       MAX_SUBMENU_CHARACTERS charactes */
    if (strlen((S8*) srv_brw_search_list_get_matched_item(item_index)) > MAX_SUBMENU_CHARACTERS)
    {
        mmi_chset_utf8_to_ucs2_string((CHAR*)str_buff, (BRW_MAX_VISIBLE_URL_LENGTH + 1) * ENCODING_LENGTH, 
                (CHAR*)srv_brw_search_list_get_matched_item(item_index));
        str_buff[BRW_MAX_VISIBLE_URL_LENGTH] = '\0';
        mmi_ucs2cat((S8*) str_buff, (S8*) BRW_MENU_ITEM_TRUNC_STR);
    }
    else
    {
        mmi_chset_utf8_to_ucs2_string((CHAR*)str_buff, (MAX_SUBMENU_CHARACTERS) * ENCODING_LENGTH,
                (CHAR*)srv_brw_search_list_get_matched_item(item_index));
    }

    *img_buff_p = get_image(IMG_ID_BRW_LIST_ICON_SEARCH_RESULT);
    return TRUE;
}
#endif /* __MMI_BRW_SEARCH_HISTORY_SUPPORT__ */

#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_matched_item
 * DESCRIPTION
 *  Item call back function for dynamic list of address list Auto 
 * completion screen
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_matched_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 addr_list_items = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    addr_list_items = mmi_brw_app_ui_callback_get_number_of_addr_list_matched_items();
    if(item_index < addr_list_items)
    {
        return mmi_brw_app_ui_callback_get_matched_address_list_item(item_index, str_buff, img_buff_p, str_img_mask);
    }
    else
#endif
    {
    #ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        if((item_index - addr_list_items) < mmi_brw_app_ui_callback_get_number_of_search_list_matched_items())
        {
            return mmi_brw_app_ui_callback_get_matched_search_list_item(item_index - addr_list_items, str_buff, img_buff_p, str_img_mask);
        }
    #endif
    }
    MMI_ASSERT(0);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_find_entry
 * DESCRIPTION
 *  This function is to find the matched items depending on the
 * input string passed to it
 * PARAMETERS
 *  input_str       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_brw_app_ui_callback_find_entry(U8 *input_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 matched_items_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    if (!(!input_str || !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items))
    {
        mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url, (S8*) input_str);
    }
    matched_items_count +=srv_brw_search_list_find_entry(input_str);
#endif
#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    if (!(!input_str || !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items))
    {
        mmi_ucs2cpy((S8*) g_brw_app_cntx.brw_dynamic_cntx_p->user_input_url, (S8*) input_str);
    }
    matched_items_count +=srv_brw_address_list_find_entry(input_str);
#endif
    return matched_items_count;
}
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/

#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_bookmarks_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of bookmarks screen
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_bookmarks_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_types_enum file_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_index < g_brw_bkm_cntx.total_file_count);
    file_type = g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[item_index].actual_index].type;
    MMI_ASSERT(file_type != SRV_BRW_BKM_TYPE_EMPTY);

    mmi_chset_utf8_to_ucs2_string((S8*) str_buff, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH, (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[item_index].actual_index].title);
#ifndef __MMI_BRW_IMG_RES_SLIM__
    if (file_type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE)
    {
        *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_USER_FILE);
    }
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    else if (file_type == SRV_BRW_BKM_TYPE_FOLDER)
    {
        *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_FOLDER_ICON);
    }
#endif
    else if (file_type == SRV_BRW_BKM_TYPE_DEFAULT_FILE)
    {
        *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_DEFAULT_FILE);
    }
#endif
    return MMI_TRUE;
}

#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_insert_bookmarks_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of insert bookmarks screen
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_insert_bookmarks_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_types_enum file_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_index < g_brw_bkm_sel_bkm_cntx.total_file_count);
    file_type = g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_sel_bkm_cntx.bookmark_list[item_index].actual_index].type;
    MMI_ASSERT(file_type != SRV_BRW_BKM_TYPE_EMPTY);

    mmi_chset_utf8_to_ucs2_string((S8*) str_buff, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH, (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_sel_bkm_cntx.bookmark_list[item_index].actual_index].title);
#ifndef __MMI_BRW_IMG_RES_SLIM__
    if (file_type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE)
    {
        *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_USER_FILE);
    }
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    else if (file_type == SRV_BRW_BKM_TYPE_FOLDER)
    {
        *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_FOLDER_ICON);
    }
#endif
    else if (file_type == SRV_BRW_BKM_TYPE_DEFAULT_FILE)
    {
        *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_DEFAULT_FILE);
    }
    else if (file_type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE)
    {
        *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_USER_FILE);
    }
#endif
    return MMI_TRUE;
}
#endif

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_folder_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of copy/move bookmarks
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_folder_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
    if (g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
    {
        switch (item_index)
        {
            case BRW_BKM_VBOOKMARKS_MENU_ITEM_INDEX:
            {
                mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_ID_BRW_VBOOKMARKS));
             #ifndef __MMI_BRW_IMG_RES_SLIM__
                *img_buff_p = get_image(gIndexIconsImageList[BRW_BKM_VBOOKMARKS_MENU_ITEM_INDEX]);
             #endif
                break;
            }
            case BRW_BKM_EXTERNAL_MEMORY_MENU_ITEM_INDEX:
            {
                mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_ID_BRW_EXTERNAL_MEMORY));
             #ifndef __MMI_BRW_IMG_RES_SLIM__
                *img_buff_p = get_image(gIndexIconsImageList[BRW_BKM_EXTERNAL_MEMORY_MENU_ITEM_INDEX]);
             #endif
                break;
            }
        }
        return MMI_TRUE;
    }
#endif /* __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__ */ 

    if (g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_ID_BRW_VBOOKMARKS));
    #ifndef __MMI_BRW_IMG_RES_SLIM__
        *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_FOLDER_ICON);
    #endif
        return MMI_TRUE;
    }

    MMI_ASSERT(item_index < g_brw_bkm_cntx.bkm_dynamic_cntx->total_folder_count);
    MMI_ASSERT(g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bkm_dynamic_cntx->bookmark_list[item_index].actual_index].type != SRV_BRW_BKM_TYPE_EMPTY);
    mmi_chset_utf8_to_ucs2_string((S8*) str_buff, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH, (S8*) g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bkm_dynamic_cntx->bookmark_list[item_index].actual_index].title);

#ifndef __MMI_BRW_IMG_RES_SLIM__
    *img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_FOLDER_ICON);
#endif
    return MMI_TRUE;

}
#endif
#endif /* __MMI_VBOOKMARK__ */


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/***************************************RECENT PAGES START*********************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_recent_page_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of Recent Page list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_recent_page_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_utf8_to_ucs2_string(
        (U8*) str_buff,
        MAX_SUB_MENU_SIZE,
        (U8*) srv_brw_recent_pages_list_get_item(item_index));
#ifndef __MMI_BRW_IMG_RES_SLIM__
    *img_buff_p = get_image(IMG_ID_BRW_RECENT_PAGES);
#endif
    return TRUE;
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_recent_page_host_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of Recent Page Host list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_recent_page_host_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_utf8_to_ucs2_string(
        (U8*) str_buff,
        MAX_SUB_MENU_SIZE,
        (U8*) srv_brw_recent_pages_host_list_get_item(item_index));
#ifndef __MMI_BRW_IMG_RES_SLIM__
    *img_buff_p = get_image(IMG_ID_BRW_RECENT_PAGES);
#endif
    return TRUE;
}
#endif /* OBIGO_Q05A */
#endif

/***************************************RECENT PAGES END*********************************/


/***************************************STORED PAGES START*********************************/
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_stored_page_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of Stored Page list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_stored_page_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_utf8_to_ucs2_string(
        (U8*) str_buff,
        MAX_SUB_MENU_SIZE,
        (U8*) srv_brw_stored_pages_list_get_item(item_index));
    *img_buff_p = get_image(IMG_ID_BRW_STORED_PAGES);

    return TRUE;
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
/***************************************STORED PAGES END*********************************/

/***************************************RENDERED PAGE START*********************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_ren_page_pen_handler
 * DESCRIPTION
 *  This is a callback function for handling pen events on the rendered page
 *  screen
 * PARAMETERS
 *  point           [IN]        
 *  event_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_app_ui_callback_ren_page_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_handle_pen_event_req(point, event_type);
    return MMI_TRUE;
}


#ifndef SLIM_WAP_MMS
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_page_actions_list_get_item
 * DESCRIPTION
 *  This function is used for getting the string to be displayed on the page
 * actions list
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_page_actions_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    MMI_BOOL is_label_present = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_chset_utf8_strlen((U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[item_index].label) > 0)
    {
        string_id = mmi_brw_app_get_do_element_string((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[item_index].label);
        is_label_present = MMI_TRUE;
    }
    else if(mmi_chset_utf8_strlen((U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[item_index].event_type) > 0)
    {
        string_id = mmi_brw_app_get_do_element_string((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[item_index].event_type);
    }
    else
    {
        string_id = STR_ID_BRW_UNKNOWN;
    }
    if (string_id > 0)
    {
        mmi_ucs2ncpy(
            (S8*) str_buff,
            (S8*) GetString(string_id),
            MAX_SUB_MENU_SIZE);
    }
    else if (is_label_present)
    {
        mmi_chset_utf8_to_ucs2_string(
            (U8*) str_buff,
            MAX_SUB_MENU_SIZE,
            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[item_index].label);
    }
    else
    {
        mmi_chset_utf8_to_ucs2_string(
            (U8*) str_buff,
            MAX_SUB_MENU_SIZE,
            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[item_index].event_type);
    }
            
    *img_buff_p = get_image(IMG_ID_BRW_DO_ELEMENTS);

    return TRUE;
}
#endif


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_page_object_types_get_item
 * DESCRIPTION
 *  This function is used for getting an menu item on the page object
 *  types screen
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_page_object_types_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 actual_index = 0;
    U8 index = 0;
    S16 active_item_count = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[index] == MMI_TRUE)
        {
            ++active_item_count;
            if (active_item_count == item_index)
            {
                actual_index = index;
                break;
            }
        }
        ++index;
    } while (index < BRW_PAGE_OBJECT_TYPES_COUNT);

    switch (actual_index)
    {
        case BRW_PAGE_OBJECT_TYPE_IMAGE:
            mmi_ucs2cpy((S8*) str_buff, GetString(STR_ID_BRW_IMAGES));
            break;

        case BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
            mmi_ucs2cpy((S8*) str_buff, GetString(STR_ID_BRW_BG_IMAGES));
            break;

        case BRW_PAGE_OBJECT_TYPE_SOUNDS:
            mmi_ucs2cpy((S8*) str_buff, GetString(STR_ID_BRW_SOUNDS));
            break;

        case BRW_PAGE_OBJECT_TYPE_OTHERS:
            mmi_ucs2cpy((S8*) str_buff, GetString(STR_ID_BRW_OTHERS));
            break;
        default:
            str_buff = NULL;
            break;
    }
    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_page_objects_get_item
 * DESCRIPTION
 *  This function is used for getting an menu item on the page objects screen
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_page_objects_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dynamic_list_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_list_index = srv_brw_page_objects_get_actual_index(item_index);
    mmi_chset_utf8_to_ucs2_string(
                (U8*) str_buff,
                MAX_SUB_MENU_SIZE,
                (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[dynamic_list_index].name);
    *img_buff_p = get_image(IMG_ID_BRW_PAGE_OBJECTS);
    return TRUE;
}
#endif /* OBIGO_Q05A */
/***************************************RENDERED PAGE END*********************************/


/***************************************SETTINGS START*********************************/
#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_trusted_certificates_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of Trusted certificate list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_trusted_certificates_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* trusted_cert_name;
    U8 menu_item_str[MAX_SUB_MENU_SIZE + ENCODING_LENGTH];
    U8* name;
    S32 menu_item_len;
    S32 trunc_str_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    trusted_cert_name = srv_brw_trusted_certificate_list_get_item(item_index);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) menu_item_str,
        MAX_SUB_MENU_SIZE + ENCODING_LENGTH,
        (U8*) trusted_cert_name);

    if (mmi_ucs2strlen((S8*) menu_item_str) > MAX_SUBMENU_CHARACTERS)
    {
        menu_item_len = MAX_SUBMENU_CHARACTERS;
        trunc_str_len = mmi_ucs2strlen((S8*) BRW_MENU_ITEM_TRUNC_STR);
        name = (U8*)srv_brw_malloc(((menu_item_len + 1) * ENCODING_LENGTH) * sizeof(U8));
        mmi_ucs2ncpy(
            (S8*) name,
            (S8*) menu_item_str,
            menu_item_len - trunc_str_len);
        name[(menu_item_len - trunc_str_len) * ENCODING_LENGTH] = '\0';
        name[(menu_item_len - trunc_str_len) * ENCODING_LENGTH + 1] = '\0';
        mmi_ucs2cat((S8*) name, (S8*) BRW_MENU_ITEM_TRUNC_STR);
    }
    else
    {
        menu_item_len = mmi_ucs2strlen((S8*) menu_item_str);
        name = (U8*)srv_brw_malloc(((menu_item_len + 1) * ENCODING_LENGTH) * sizeof(U8));
        mmi_ucs2cpy((S8*) name, (S8*) menu_item_str);
    }

    mmi_ucs2ncpy((S8*) str_buff, (S8*) name, MAX_SUBMENU_CHARACTERS);
    *img_buff_p = get_image(IMG_ID_BRW_TRUSTED_CERTS);
    srv_brw_free(name);
    return TRUE;
}
#endif /* WAP_SEC_SUPPORT */
/***************************************SETTINGS END*********************************/

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_shortcuts_list_item
 * DESCRIPTION
 *  Item call back function for dynamic list of shortcuts list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_app_ui_callback_get_shortcuts_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index < SRV_BRW_MAX_SHORTCUTS_COUNT));

    if (srv_brw_shortcut_list_is_item_empty(item_index))
    {
        mmi_ucs2cpy((S8*) str_buff, GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_ucs2ncpy((S8*) str_buff, (S8*)srv_brw_shortcuts_list_get_title(item_index), MAX_SUB_MENU_SIZE);
    }
    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_get_dynamic_list_item
 * DESCRIPTION
 *  show the toolbar for the input address list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_brw_app_ui_callback_get_dynamic_list_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    S32 index;
	mmi_brw_app_screenDB_struct *scrDB = mmi_brw_app_get_curr_screenDB();
    GetItemFuncPtr get_data_func;
    get_data_func = mmi_brw_app_get_dynamic_list_callback_func(scrDB->scrn_id);
    for (index = 0; index < data_size; index++)
	{
	    get_data_func((start_index+index), menu_data[index].item_list[0], &menu_data[index].image_list[0], 0);
	}
	return data_size;
}

/***************************************FTE START************************************/
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_enter_url_tap
 * DESCRIPTION
 *  Tap Callback function for the enter url screen
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_enter_url_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 addr_list_items = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return ;
    }
         /* Options on LSK */ 
    else if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM )
    {
    #ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        addr_list_items = mmi_brw_app_ui_callback_get_number_of_addr_list_matched_items();
        if(index < addr_list_items)
        {
            mmi_brw_app_dmgr_add_addr_list_item();
        }
        else
    #endif
        {
        #ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
            if((index - addr_list_items) < mmi_brw_app_ui_callback_get_number_of_search_list_matched_items())
            {
                mmi_brw_app_dmgr_add_search_list_item();
            }
        #endif
        }
    }
}
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_show_bookmarks_toolbar
 * DESCRIPTION
 *  show the toolbar function for the bookmarks list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_show_bookmarks_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 item_icon[BRW_BKM_TB_ITEM_TOTAL] = {0};
    PU8 item_disabled_icon[BRW_BKM_TB_ITEM_TOTAL] = {0};
    PU8 string[BRW_BKM_TB_ITEM_TOTAL] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    item_icon[BRW_BKM_TB_ITEM_ADD_BOOKMARK] = get_image(IMG_ID_BRW_FTE_ADD_BOOKMARK_ENABLE);
    item_disabled_icon[BRW_BKM_TB_ITEM_ADD_BOOKMARK] = get_image(IMG_ID_BRW_FTE_ADD_BOOKMARK_DISABLE);
    string[BRW_BKM_TB_ITEM_ADD_BOOKMARK] = (PU8) get_string(STR_ID_BRW_ADD_BOOKMARK);
#endif

    item_icon[BRW_BKM_TB_ITEM_INPUT_ADDRESS] = get_image(IMG_ID_BRW_FTE_INPUT_ADDRESS_ENABLE);
    item_disabled_icon[BRW_BKM_TB_ITEM_INPUT_ADDRESS] = get_image(IMG_ID_BRW_FTE_INPUT_ADDRESS_DISABLE);
    string[BRW_BKM_TB_ITEM_INPUT_ADDRESS] = (PU8) get_string(STR_ID_BRW_SEARCH_OR_INPUT_URL);

    item_icon[BRW_BKM_TB_ITEM_DELETE_BOOKMARK] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);
    item_disabled_icon[BRW_BKM_TB_ITEM_DELETE_BOOKMARK] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);
    string[BRW_BKM_TB_ITEM_DELETE_BOOKMARK] = (PU8) get_string(STR_GLOBAL_DELETE);

    wgui_icon_bar_setup(
             BRW_BKM_TB_ITEM_TOTAL,
             item_icon,
             item_disabled_icon,
             string,
             mmi_brw_app_ui_callback_bookmarks_toolbar);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_bookmarks_toolbar
 * DESCRIPTION
 *  callback function that will called when toolbar icon will be pressed in
 * the bookmarks list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_bookmarks_toolbar(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_BOOKMARK ;
    switch(index)
    {
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
        case BRW_BKM_TB_ITEM_ADD_BOOKMARK:
            mmi_brw_app_dmgr_pre_entry_add_bookmark();
            break;
    #endif

        case BRW_BKM_TB_ITEM_INPUT_ADDRESS:
    #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
           mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords();
    #else
           mmi_brw_app_dmgr_pre_entry_address_list();
    #endif
            break;
        case BRW_BKM_TB_ITEM_DELETE_BOOKMARK:
            {
            #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
                if(g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].type == SRV_BRW_BKM_TYPE_FOLDER)
                {
                    mmi_brw_app_delete_folder_confirm();
                }
                else
            #endif
                {
                    mmi_brw_app_delete_bookmark_file_confirm();
                }
            }
            break;
        default :
            MMI_ASSERT(0);
    }
}
#endif // __MMI_ICON_BAR_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_bookmarks_list_tap
 * DESCRIPTION
 *  Tap Callback function for bookmark list screen
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_bookmarks_list_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
	{
        /* only change highlight.  do nothing in tap callback function */
        return;
    }
    /* ENUM_TAP_ON_HIGHLIGHTED_ITEM */
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_BOOKMARK ;
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        if (g_srv_brw_cntx.bkm_cntx_p[g_brw_bkm_cntx.bookmark_list[g_brw_bkm_cntx.sel_file_index].actual_index].type == SRV_BRW_BKM_TYPE_FOLDER)
        {
            mmi_brw_app_dmgr_open_bookmark_folder();
        }
        else 
    #endif
        {
            mmi_brw_app_dmgr_launch_bookmark();
        }
    }
    return ;
}


#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_browse_path_tap
 * DESCRIPTION
 *  Tap Callback function for the Browse path screen
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_browse_path_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_brw_bkm_cntx.bkm_dynamic_cntx->is_first_level)
    {
        mmi_brw_app_if_browse_path_open_folder();
    }
    else
    {
        if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
        {
            /* only change highlight.  do nothing in tap callback function */
            return;
        }
        else if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM )
        {
            mmi_brw_app_dmgr_browse_path_select_folder();
        }
    }
    return ;
}
#endif

#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_show_rendered_page_toolbar
 * DESCRIPTION
 *  This function fills the icons and strings for toolbar to be displayed in the
 * rendered page screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_show_rendered_page_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_count = 4;
    PU8 item_icon[4] = {NULL, };
    PU8 item_disabled_icon[4] = {NULL,};
    PU8 string[4] = {NULL, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_icon[0] = get_image(IMG_ID_BRW_FTE_INPUT_ADDRESS_ENABLE);
    item_icon[1] = get_image(IMG_ID_BRW_FTE_BACKWARD_ENABLE);
    item_icon[2] = get_image(IMG_ID_BRW_FTE_FORWARD_ENABLE);
    item_icon[3] = get_image(IMG_ID_BRW_FTE_BOOKMARKS_LIST_ENABLE);    

    item_disabled_icon[0] = get_image(IMG_ID_BRW_FTE_INPUT_ADDRESS_DISABLE);
    item_disabled_icon[1] = get_image(IMG_ID_BRW_FTE_BACKWARD_DISABLE);
    item_disabled_icon[2] = get_image(IMG_ID_BRW_FTE_FORWARD_DISABLE);
    item_disabled_icon[3] = get_image(IMG_ID_BRW_FTE_BOOKMARKS_LIST_DISABLE);

    string[0] = (PU8) get_string(STR_ID_BRW_SEARCH_OR_INPUT_URL);
    string[1] = (PU8) get_string(STR_ID_BRW_BACKWARD);
    string[2] = (PU8) get_string(STR_ID_BRW_FORWARD);
    string[3] = (PU8) get_string(STR_ID_BRW_BOOKMARKS);
    wgui_icon_bar_setup_ex( 
        item_count,
        NULL,
        NULL,
        item_icon,
        item_disabled_icon,
        string,
        mmi_brw_app_ui_callback_render_page_toolbar,
        MMI_FALSE,
    #ifdef OBIGO_Q03C_BROWSER
        MMI_FALSE
    #else /* OBIGO_Q03C_BROWSER */
        MMI_TRUE
    #endif /* OBIGO_Q03C_BROWSER */
        );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_render_page
 * DESCRIPTION
 *  callback function that will called when toolbar icon will be pressed
 * on the rendered page screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_render_page_toolbar(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_RENDER_PAGE;
    switch(index)
    {
    case 0:
        mmi_brw_app_dmgr_fte_show_address_list();
        break;
    case 1:
        {
            if (g_brw_app_cntx.brw_dynamic_cntx_p->is_navigation_req_send != MMI_TRUE)
            {
                srv_brw_navigate_req(WAP_BAM_MOVE_BACKWARD);
                g_brw_app_cntx.brw_dynamic_cntx_p->is_navigation_req_send = MMI_TRUE;
            }
        }
        break;
    case 2:
        {
            if (g_brw_app_cntx.brw_dynamic_cntx_p->is_navigation_req_send != MMI_TRUE)
            {
                srv_brw_navigate_req(WAP_BAM_MOVE_FORWARD);
                g_brw_app_cntx.brw_dynamic_cntx_p->is_navigation_req_send = MMI_TRUE;
            }
        }
        break;
    case 3:
        mmi_brw_app_dmgr_fte_show_bookmark_list();
        break;           
    default :
        MMI_ASSERT(0);
    }
}
#endif


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_show_recent_page_toolbar
 * DESCRIPTION
 *  show the toolbar fucntion for the recent pages screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_show_recent_page_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 item_icon[BRW_RPAGE_TB_ITEM_TOTAL] = {0};
    PU8 item_disabled_icon[BRW_RPAGE_TB_ITEM_TOTAL] = {0};
    PU8 string[BRW_RPAGE_TB_ITEM_TOTAL] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    item_icon[BRW_RPAGE_TB_ITEM_ADD_BOOKMARK] = get_image(IMG_ID_BRW_FTE_SAVE_BOOKMARK_ENABLE);
    item_disabled_icon[BRW_RPAGE_TB_ITEM_ADD_BOOKMARK] = get_image(IMG_ID_BRW_FTE_SAVE_BOOKMARK_DISABLE);
    string[BRW_RPAGE_TB_ITEM_ADD_BOOKMARK] = (PU8) get_string(STR_ID_BRW_ADD_TO_BOOKMARK);
#endif

    item_icon[BRW_RPAGE_TB_ITEM_INPUT_ADDRESS] = get_image(IMG_ID_BRW_FTE_INPUT_ADDRESS_ENABLE);
    item_disabled_icon[BRW_RPAGE_TB_ITEM_INPUT_ADDRESS] = get_image(IMG_ID_BRW_FTE_INPUT_ADDRESS_DISABLE);
    string[BRW_RPAGE_TB_ITEM_INPUT_ADDRESS] = (PU8) get_string(STR_ID_BRW_SEARCH_OR_INPUT_URL);

    item_icon[BRW_RPAGE_TB_ITEM_DELETE_PAGE] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);
    item_disabled_icon[BRW_RPAGE_TB_ITEM_DELETE_PAGE] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);
    string[BRW_RPAGE_TB_ITEM_DELETE_PAGE] = (PU8) get_string(STR_GLOBAL_DELETE);

    wgui_icon_bar_setup(
             BRW_RPAGE_TB_ITEM_TOTAL,
             item_icon,
             item_disabled_icon,
             string,
             mmi_brw_app_ui_callback_recent_page_toolbar);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_recent_page_toolbar
 * DESCRIPTION
 *  callback function that will called when toolbar icon will be pressed
 * in the recent pages list screen
 * PARAMETERS
 *  index      [IN]  index of icon
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_recent_page_toolbar(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(index)
    {
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    case BRW_RPAGE_TB_ITEM_ADD_BOOKMARK:
        g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_RECENT_PAGE_ADD_BKM ;
        mmi_brw_app_dmgr_pre_entry_recent_page_options();
        break;
#endif
    case BRW_RPAGE_TB_ITEM_INPUT_ADDRESS:
        g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_RECENT_PAGE_INPUT_ADDR ;
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
       mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords();
#else
       mmi_brw_app_dmgr_pre_entry_address_list();
#endif
        break;
    case BRW_RPAGE_TB_ITEM_DELETE_PAGE:
        g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_RECENT_PAGE_DELETE ;
        mmi_brw_app_delete_recent_page_item_confirm();
        break;
    default :
        MMI_ASSERT(0);
    }
}
#endif // __MMI_ICON_BAR_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_recent_page_list_tap
 * DESCRIPTION
 *  Tap Callback function for recent page list
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_recent_page_list_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM )
	{
        return ;
	}
         /* Options on LSK */ 
	if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM )
	{
        g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;
        mmi_brw_app_dmgr_launch_recent_pages_url();
	}
    return ;
}
#endif

#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_recent_page_host_list_tap
 * DESCRIPTION
 *  Tap Callback function for recent page host list
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_recent_page_host_list_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM )
	{
        return ;
	}
         /* Options on LSK */ 
	if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM )
	{
        mmi_brw_app_dmgr_open_recent_page_host();
	}
    return ;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_page_obj_list_tap
 * DESCRIPTION
 *  Tap Callback function for page object list
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_page_obj_list_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM )
    {
        return ;
    }
         /* Options on LSK */ 
    if (wgui_category_if_pop_option_menu())
    {
        mmi_brw_app_dmgr_pre_entry_page_object_options();
    }
    return ;
}

#endif /* OBIGO_Q05A */


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_trusted_certificate_tap
 * DESCRIPTION
 *  Tap Callback function for trusted cert list screen
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_trusted_certificate_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM )
    {
        return ;
    }
         /* Options on LSK */ 
    if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM )
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->view_type = BRW_VIEW_TRUSTED_CERTIFICATE;
        g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;
        mmi_brw_app_if_show_view_certificate_screen();
    }
    return ;
}
#endif /* WAP_SEC_SUPPORT */ 


#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_show_stored_pagetoolbar
 * DESCRIPTION
 *  show the toolbar for the stored pages list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_show_stored_page_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_count = 3;
    PU8 item_icon[3] = {NULL, NULL, NULL};
    PU8 item_disabled_icon[3] = {NULL, NULL, NULL};
    PU8 string[3] = {NULL, NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_icon[0] = get_image(IMG_ID_BRW_FTE_SAVE_BOOKMARK_ENABLE);
    item_icon[1] = get_image(IMG_ID_BRW_FTE_INPUT_ADDRESS_ENABLE);
    item_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE);

    item_disabled_icon[0] = get_image(IMG_ID_BRW_FTE_SAVE_BOOKMARK_DISABLE);
    item_disabled_icon[1] = get_image(IMG_ID_BRW_FTE_INPUT_ADDRESS_DISABLE);
    item_disabled_icon[2] = get_image(IMG_GLOBAL_TOOLBAR_DELETE_DISABLED);

    string[0] = (PU8) get_string(STR_ID_BRW_ADD_TO_BOOKMARK);
    string[1] = (PU8) get_string(STR_ID_BRW_SEARCH_OR_INPUT_URL);
    string[2] = (PU8) get_string(STR_GLOBAL_DELETE);
    wgui_icon_bar_setup(
             item_count,
             item_icon,
             item_disabled_icon,
             string,
             mmi_brw_app_ui_callback_stored_page_toolbar);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_stored_page_toolbar
 * DESCRIPTION
 *  callback function that will called when toolbar icon will be pressed in
 * the stored pages list screen
 * PARAMETERS
 *  index      [IN]  index of icon
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_stored_page_toolbar(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(index)
    {
    case 0:
        g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_STORED_PAGE_ADD_BKM ;
        mmi_brw_app_dmgr_pre_entry_stored_page_options();
        break;
    case 1:
        g_brw_app_cntx.brw_toolbar_launch_point = BRW_LAUNCH_FROM_STORED_PAGE_INPUT_ADDR ;
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
       mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords();
#else
       mmi_brw_app_dmgr_pre_entry_address_list();
#endif
        break;
    case 2:
        mmi_brw_app_delete_stored_page_confirm();
        break;
    default :
        MMI_ASSERT(0);
    }
}
#endif //__MMI_ICON_BAR_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_stored_page_list_tap
 * DESCRIPTION
 *  Tap Callback function for stored page list
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_stored_page_list_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM )
    {
        return ;
    }
    /* Options on LSK */ 
    if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM )
    {
        mmi_brw_app_dmgr_open_stored_page();
    }
    return ;
}

#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_shortcuts_list_tap
 * DESCRIPTION
 *  Tap Callback function for shortcuts list
 * PARAMETERS
 *  mmi_tap_type_enum       [IN]   tap type
 *  index                   [IN]    index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_shortcuts_list_tap(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM )
    {
        return ;
    }
    /* Options on LSK */ 
    if(tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM )
    {
        g_brw_app_cntx.brw_dynamic_cntx_p->index_highlighted_item = index;
        mmi_brw_app_ui_callback_shortcuts_list_csk_hdlr();
    }
    return ;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_save_bookmark_inline_tap_callback
 * DESCRIPTION
 *  Dummy function for save bookmark inline CUI tap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_save_bookmark_inline_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_ui_callback_save_bookmark_inline_tap_callback
 * DESCRIPTION
 *  Dummy function for save bookmark inline CUI tap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_app_ui_callback_add_bookmark_inline_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    if(index = (BRW_INLINE_TITLE - BRW_INLINE_TITLE_CAPTION))
    {
        mmi_brw_app_if_show_edit_bookmark_naming_rule_screen();
    }
}

#endif /*#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */ 
/***************************************FTE END************************************/


#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPUICALLBACK_C */
