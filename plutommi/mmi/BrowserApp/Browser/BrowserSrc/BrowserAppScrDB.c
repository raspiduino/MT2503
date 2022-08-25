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
 * BrowserUIPlugIn.c
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPSCRDB_C
#define MMI_BROWSERAPPSCRDB_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppScrDB.h"
#include "BrowserAppScrHdlr.h"
#include "BrowserAppUIDraw.h"
#include "BrowserAppInterface.h"
#include "BrowserAppScrHdlr.h"
#include "BrowserAppUIPlugin.h"
#include "BrowserAppDMgr.h"

#include "MMIDataType.h"
#include "mmi_rp_app_browser_def.h"
#include "GlobalMenuItems.h"
#include "GlobalResDef.h"
#include "BrowserSrvConfig.h"
#include "kal_public_api.h"
#include "kal_general_types.h"


static U16 g_brw_app_scr_index = 0;
static U16 g_brw_app_res_index = 0;

/* TODO */
/********************Resource Database*********************/

mmi_brw_app_resourceDB_struct g_brw_app_resourceDB[] =
{
    {   
        SCR_ID_BRW_BOOKMARKS,
        STR_ID_BRW_BOOKMARKS,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	{   
        SCR_ID_BRW_RECENT_PAGES,
        STR_ID_BRW_RECENT_PAGES,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    {   
        SCR_ID_BRW_ENTER_URL,
        STR_ID_BRW_SEARCH_OR_INPUT_URL,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    {   
        SCR_ID_BRW_STORED_PAGES,
        STR_ID_BRW_STORED_PAGES,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
    {   
        SCR_ID_BRW_BROWSER_MAIN,
        STR_ID_BRW_INTERNET_SERVICES,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		0,
        0
	},
    {
        SCR_ID_BRW_MEMORY_STATUS,
        STR_GLOBAL_MEMORY_STATUS,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    {
        SCR_ID_BRW_VIEW_BOOKMARK,
        STR_GLOBAL_VIEW,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif
#ifdef WAP_SEC_SUPPORT
	{
        SCR_ID_BRW_TRUSTED_CERTIFICATES,
        STR_ID_BRW_TRUSTED_CERTIFICATES,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif /* WAP_SEC_SUPPORT */
	{
        SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE,
        0,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#ifndef SLIM_WAP_MMS
	{
        SCR_ID_BRW_PAGE_ACTIONS,
        STR_ID_BRW_PAGE_ACTIONS,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif
#ifdef OBIGO_Q05A
	{
        SCR_ID_BRW_PAGE_OBJECT_TYPES,
        STR_ID_BRW_PAGE_OBJECTS,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
	{
        SCR_ID_BRW_PAGE_OBJECTS,
        0,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif /* #ifdef OBIGO_Q05A */
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifdef OBIGO_Q05A
	{
        SCR_ID_BRW_RECENT_PAGES_HOST,
        STR_ID_BRW_RECENT_HOSTS,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif
#endif
	{
        SCR_ID_BRW_BUSY_SCREEN,
        0,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		0,
        0
	},
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
	{
        SCR_ID_BRW_BOOKMARK_BROWSE_PATH,
        0,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
	{
        SCR_ID_BRW_SELECT_BOOKMARK,
        STR_ID_BRW_BOOKMARKS,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_SELECT,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif
	{
        SCR_ID_BRW_TEMP_BUSY_SCREEN,
        0,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		0,
        0
	},
#ifdef WAP_SEC_SUPPORT
	{
        SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN,
        0,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES, 
		STR_GLOBAL_NO,
        IMG_GLOBAL_NO
	},
#endif /* WAP_SEC_SUPPORT */
	 {
        SCR_ID_BRW_OUT_OF_MEM_CONFIRMATION_SCREEN,
        0,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK, 
		0,
        0
	},
	 {
        SCR_ID_BRW_UHA_URI_SCHEME_CONFIRM_SCREEN,
        0,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES, 
		STR_GLOBAL_NO,
        IMG_GLOBAL_NO
	},
#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
	 {
        SCR_ID_BRW_PAGE_SIZE_CHECK,
        0,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES, 
		STR_GLOBAL_NO,
        IMG_GLOBAL_NO
	},
#endif
#ifdef __MMI_BRW_LOADING_TIME_CHECKING__
	 {
        SCR_ID_BRW_LOADING_TIME_CHECK,
        0,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES, 
		STR_GLOBAL_NO,
        IMG_GLOBAL_NO
	},
#endif
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
	 {
        SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN,
        STR_ID_BRW_UPLOADING,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK
	},
	 {
        SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN,
        0,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES, 
		STR_GLOBAL_NO,
        IMG_GLOBAL_NO
	},
#endif /* #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
#ifdef __MMI_BRW_POST_SESSION_INFO__
	 {
        SCR_ID_BRW_POST_SESSION_INFO,
        STR_ID_BRW_POST_SESSION_INFO,
        SERVICES_WAP_MENU_ID,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif /* __MMI_BRW_POST_SESSION_INFO__ */
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
        {   
        SCR_ID_BRW_SPLASH_SCREEN,
        STR_ID_BRW_INTERNET_SERVICES,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		0,
        0
	},
#endif
#ifdef __OP01__
    {
        SCR_ID_BRW_VIEW_URL,
        STR_ID_BRW_INTERNET_SERVICES,
        SERVICES_WAP_MENU_ID,
        0,
        0, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif /* __OP01__ */

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    {   
        SCR_ID_BRW_LAUNCH_PAGE,
        STR_ID_BRW_LAUNCH_PAGE,
        SERVICES_WAP_MENU_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK, 
		STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK
	},
#endif
    /* Please add New entry above this line */
    {0, 0, 0, 0, 0, 0, 0}
};

mmi_brw_app_screenDB_struct g_brw_app_scrDB[] =
{
    {   
		NULL,
		NULL,
	    mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_bookmarks_list_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func, //184 + 213
        mmi_brw_app_sh_bookmarks_list_exit_func,
		mmi_brw_app_if_show_bookmarks_list,
		mmi_brw_app_dmgr_pre_entry_bookmark_options,
		mmi_brw_app_sh_bookmarks_list_rsk_func,
		mmi_brw_app_ui_plugin_bookmarks_list_hilite_handler,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
       	SCR_ID_BRW_BOOKMARKS
	},
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	{   
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        NULL, //mmi_brw_app_sh_recent_pages_list_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func, //184
        NULL, //mmi_brw_app_sh_recent_pages_list_exit_func,
		mmi_brw_app_if_show_recent_pages_list,
		mmi_brw_app_dmgr_pre_entry_recent_page_options,
		mmi_brw_app_sh_generic_rsk_func,
		mmi_brw_app_ui_plugin_recent_pages_list_hilite_handler, //confirm, if generic will do
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_RECENT_PAGES
	},
#endif
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    {   
        NULL,
        NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_enter_url_pre_func,
        NULL,
        mmi_brw_app_ui_draw_enter_url_editor_screen_func,
        NULL, //mmi_brw_app_sh_enter_url_exit_func,
        mmi_brw_app_if_show_enter_url_screen,
        mmi_brw_app_if_show_editor_option,
        mmi_brw_app_sh_enter_url_rsk_func,
        mmi_brw_app_ui_plugin_matched_list_highlight_hdlr, 
        mmi_brw_app_sh_enter_url_editor_delete_scr_handler,
        SCR_ID_BRW_ENTER_URL
    },
#endif /* #if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)*/
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    {   
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func,
        NULL,
		mmi_brw_app_if_show_stored_pages_list,
		mmi_brw_app_dmgr_pre_entry_stored_page_options,
		mmi_brw_app_sh_stored_pages_list_rsk_func,
		mmi_brw_app_ui_plugin_stored_pages_list_hilite_handler, 
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_STORED_PAGES
	},
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
    {   
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_rendered_page_pre_func,
        mmi_brw_app_sh_rendered_page_post_func,
		mmi_brw_app_ui_draw_rendered_page_screen_func,
        mmi_brw_app_sh_rendered_page_exit_func,
		mmi_brw_app_if_show_rendered_page_screen,
		NULL,
		NULL,
		NULL,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_BROWSER_MAIN
	},
    {
 		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_viewer_screen_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_viewer_screen_func, //confirm
        NULL,
		mmi_brw_app_if_show_memory_status_screen,
		NULL,
		mmi_brw_app_sh_memory_status_screen_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_static_list_delete_scr_handler,
        SCR_ID_BRW_MEMORY_STATUS
	},
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    {
 		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_viewer_screen_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_viewer_screen_func, //confirm
        NULL,
		mmi_brw_app_if_show_view_bookmark_screen,
		NULL,
		mmi_brw_app_sh_generic_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_static_list_delete_scr_handler,
        SCR_ID_BRW_VIEW_BOOKMARK
	},
#endif
#ifdef WAP_SEC_SUPPORT
	{
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func,
        NULL,
		mmi_brw_app_if_show_trusted_certificates_list,
		mmi_brw_app_if_show_trusted_certificates_options_menu,
		mmi_brw_app_sh_trusted_certificates_list_rsk_func,
		mmi_brw_app_ui_plugin_trusted_certificate_list_hilite_handler,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_TRUSTED_CERTIFICATES
	},
#endif /* WAP_SEC_SUPPORT */
	{
 		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_viewer_screen_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_viewer_screen_func, //confirm
        NULL,
		mmi_brw_app_if_show_view_certificate_screen,
		NULL,
		mmi_brw_app_sh_view_certificate_screen_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_view_certificate_delete_scr_handler,
        SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE
	},
#ifndef SLIM_WAP_MMS
	{
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func,
        NULL,
		mmi_brw_app_if_show_page_actions_list,
		mmi_brw_app_sh_page_actions_list_lsk_func,
		mmi_brw_app_sh_page_actions_list_rsk_func,
		mmi_brw_app_ui_plugin_page_actions_highlight_hdlr,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_PAGE_ACTIONS
	},
#endif
#ifdef OBIGO_Q05A
	{
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func,
        NULL,
		mmi_brw_app_if_show_page_object_types,
		mmi_brw_app_sh_page_object_types_lsk_func,
		mmi_brw_app_sh_page_object_types_rsk_func,
		mmi_brw_app_ui_plugin_page_object_types_highlight_hdlr,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_PAGE_OBJECT_TYPES
	},
	{
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func,
        NULL,
		mmi_brw_app_if_show_page_objects,
		mmi_brw_app_dmgr_pre_entry_page_object_options,
		mmi_brw_app_sh_page_objects_rsk_func,
		mmi_brw_app_ui_plugin_page_objects_highlight_hdlr,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_PAGE_OBJECTS
	},
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	{
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func,
        NULL,
		mmi_brw_app_if_show_recent_pages_host_screen,
		mmi_brw_app_sh_recent_pages_host_lsk_func,
		mmi_brw_app_sh_recent_pages_host_rsk_func,
		mmi_brw_app_ui_plugin_recent_pages_host_highlight_hdlr,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_RECENT_PAGES_HOST
	},
#endif
#endif /* #ifdef OBIGO_Q05A */
	{
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_scrhdlr_pre_osl_small_screen,
        mmi_brw_app_sh_progress_screen_post_func,
		mmi_brw_app_ui_draw_progressing_screen_func,
        NULL,
		mmi_brw_app_if_show_progressing_screen,
		NULL,
		NULL,
		NULL,
		mmi_brw_app_sh_static_list_delete_scr_handler,
        SCR_ID_BRW_BUSY_SCREEN
	},
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
	{
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func,
        mmi_brw_app_sh_browse_path_exit_func,
		mmi_brw_app_if_show_bookmark_browse_path_screen,
		mmi_brw_app_sh_browse_path_lsk_func,
		mmi_brw_app_sh_bookmark_browse_path_rsk_func,
		mmi_brw_app_ui_plugin_bookmark_browse_path_hilite_handler,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_BOOKMARK_BROWSE_PATH
	},
#endif
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
	{
 		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func,
        NULL, //mmi_brw_app_sh_select_bookmark_exit_func,
		mmi_brw_app_if_show_select_bookmark_screen,
		NULL,
		mmi_brw_app_sh_select_bookmark_rsk_func,
		mmi_brw_app_ui_plugin_select_bookmark_hilite_handler,
		mmi_brw_app_sh_select_bookmark_delete_scr_handler,
        SCR_ID_BRW_SELECT_BOOKMARK
	},
#endif
	{
 		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
		mmi_brw_app_scrhdlr_pre_osl_small_screen,
        mmi_brw_app_sh_progress_screen_post_func,
		mmi_brw_app_ui_draw_progressing_screen_func,
        mmi_brw_app_sh_temp_progress_screen_exit_func,
		mmi_brw_app_if_show_temp_progressing_screen,
		NULL,
		NULL,
		NULL,
		mmi_brw_app_sh_static_list_delete_scr_handler,
        SCR_ID_BRW_TEMP_BUSY_SCREEN
	},
#ifdef WAP_SEC_SUPPORT
	{
		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_sec_confirm_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_confirmation_screen_func, //confirm
        mmi_brw_app_sh_confirm_screen_exit_func,
		mmi_brw_app_if_show_sec_confirm_screen,
		mmi_brw_app_sh_sec_confirm_lsk_func,
		mmi_brw_app_sh_sec_confirm_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_sec_confirm_dlg_delete_scr_handler,
        SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN
	},
#endif /* WAP_SEC_SUPPORT */
	{
		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_scrhdlr_pre_small_screen,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_confirmation_screen_func, //confirm
        mmi_brw_app_sh_confirm_screen_exit_func,
		mmi_brw_app_if_show_out_of_mem_confirm_screen,
		mmi_brw_app_sh_out_of_mem_confirm_lsk_func,
		NULL,
		NULL, //confirm
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_OUT_OF_MEM_CONFIRMATION_SCREEN
	},
#ifdef __MMI_URI_AGENT__
	{
		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_scrhdlr_pre_osl_small_screen,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_confirmation_screen_func, //confirm
        mmi_brw_app_sh_confirm_screen_exit_func,
		mmi_brw_app_if_show_uha_uri_scheme_confirm_screen,
		mmi_brw_app_sh_uha_uri_scheme_confirm_lsk_func,
		mmi_brw_app_sh_uha_uri_scheme_confirm_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_uha_uri_scheme_confirm_dlg_delete_scr_handler,
        SCR_ID_BRW_UHA_URI_SCHEME_CONFIRM_SCREEN
	},
#endif /* #ifdef __MMI_URI_AGENT__ */
#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
	{
		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_scrhdlr_pre_small_screen,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_confirmation_screen_func, //confirm
        NULL,
		mmi_brw_app_if_show_page_size_check_screen,
		mmi_brw_app_sh_page_size_check_lsk_func,
		mmi_brw_app_sh_page_size_check_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_PAGE_SIZE_CHECK
	},
#endif
#ifdef __MMI_BRW_LOADING_TIME_CHECKING__
	{
		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_scrhdlr_pre_small_screen,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_confirmation_screen_func, //confirm
        NULL,
		mmi_brw_app_if_show_loading_time_check_screen,
		mmi_brw_app_sh_loading_time_check_lsk_func,
		mmi_brw_app_sh_loading_time_check_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_LOADING_TIME_CHECK
	},
#endif
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
	{
		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_upload_progress_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_upload_progress_screen_func, //confirm
        NULL,
		mmi_brw_app_if_show_upload_progress_screen,
		NULL,
		mmi_brw_app_sh_upload_progress_rsk_func,
		NULL, //confirm.
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN
	},
	{
		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_scrhdlr_pre_small_screen,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_confirmation_screen_func, //confirm
        mmi_brw_app_sh_confirm_screen_exit_func,
		mmi_brw_app_if_show_upload_cancel_confirm_screen,
		mmi_brw_app_sh_upload_cancel_lsk_func,
		mmi_brw_app_sh_upload_cancel_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN
	},
#endif /* #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
#ifdef __MMI_BRW_POST_SESSION_INFO__
	{
 		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_viewer_screen_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_viewer_screen_func, //confirm
        NULL,
		mmi_brw_app_if_show_post_session_info_screen,
		NULL,
		mmi_brw_app_sh_post_session_info_screen_lsk_func,
		NULL, //confirm
		mmi_brw_app_sh_static_list_delete_scr_handler,
        SCR_ID_BRW_POST_SESSION_INFO
	},
#endif /* #ifdef __MMI_BRW_POST_SESSION_INFO__ */
#ifdef __MMI_BRW_SPLASH_SCREEN_SUPPORT__
    {   
		NULL,
		NULL,
		mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_splash_screen_pre_func,
        mmi_brw_app_sh_splash_screen_post_func,
		mmi_brw_app_ui_draw_splash_screen_func,
        NULL, //mmi_brw_app_sh_rendered_page_exit_func,
		mmi_brw_app_if_show_rendered_page_screen,
		NULL,
		NULL,
		NULL,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
        SCR_ID_BRW_SPLASH_SCREEN
	},
#endif
#ifdef __OP01__
    {
 		NULL,
		NULL,
        mmi_brw_app_sh_create_func,
        mmi_brw_app_sh_viewer_screen_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_viewer_screen_func, //confirm
        NULL,
		mmi_brw_app_if_show_view_url_screen,
		NULL,
		mmi_brw_app_sh_view_url_screen_rsk_func,
		NULL, //confirm
		mmi_brw_app_sh_static_list_delete_scr_handler,
        SCR_ID_BRW_VIEW_URL
	},
#endif /* __OP01__ */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    {   
		NULL,
		NULL,
	    mmi_brw_app_sh_create_func,
		mmi_brw_app_sh_dynamic_list_pre_func,
        mmi_brw_app_sh_generic_post_func,
		mmi_brw_app_ui_draw_dynamic_list_screen_func, //184
        NULL,
        mmi_brw_app_if_show_shortcuts_list,
		mmi_brw_app_if_show_shortcuts_list_options,
		mmi_brw_app_sh_shortcuts_list_rsk_func,
		mmi_brw_app_ui_plugin_shortcuts_list_hilite_handler,
		mmi_brw_app_sh_dynamic_list_delete_scr_handler,
       	SCR_ID_BRW_LAUNCH_PAGE
	},
#endif
    /* Please add New entry above this line */
    
};



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_scrhdlr_db_index
 * DESCRIPTION
 *  This function is to set the global index which points to the screen handler 
 * database to the index of a particular screen
 * particular screen id
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
void mmi_brw_app_set_scrhdlr_db_index(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_brw_app_scrDB[index].scrn_id != 0)
    {
        if (g_brw_app_scrDB[index].scrn_id == scr_id)
        {
            g_brw_app_scr_index = index;
            return;
        }
        index++;
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_get_curr_screenDB
 * DESCRIPTION
 *  This function is to get the screen database pointer of the screen id 
 * presently stored in the g_brw_app_scr_index
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  pointer to a particular screen database index
 *****************************************************************************/
mmi_brw_app_screenDB_struct* mmi_brw_app_get_curr_screenDB (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_brw_app_scrDB[g_brw_app_scr_index]);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_scrhdlr_get_screenDB
 * DESCRIPTION
 *  This function is to get the screen database pointer to the index of the 
 * screen id passed
 * PARAMETERS
 *  Scr_id of the screen to be searched in the screen database
 * RETURNS
 *  pointer to a particular screen database index
 *****************************************************************************/
mmi_brw_app_screenDB_struct* mmi_brw_app_scrhdlr_get_screenDB (U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_brw_app_scrDB[index].scrn_id != 0)
    {
        if (g_brw_app_scrDB[index].scrn_id == scr_id)
        {
            return &(g_brw_app_scrDB[index]);
        }
        index++;
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_set_res_db_index
 * DESCRIPTION
 *  This function is to set the global index which points to the resource 
 * database to the index of a particular screen
 * particular screen id
 * PARAMETERS
 *  Scr_id of the screen to be displayed      
 * RETURNS
 *  
 *****************************************************************************/
void mmi_brw_app_set_res_db_index(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_brw_app_resourceDB[index].scrn_id != 0)
    {
        if (g_brw_app_resourceDB[index].scrn_id == scr_id)
        {
            g_brw_app_res_index = index;
            return;
        }
        index++;
    }
    ASSERT(0);
}

mmi_brw_app_resourceDB_struct* mmi_brw_app_get_current_resDB(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_brw_app_resourceDB[g_brw_app_res_index]);
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPSCRDB_C */
