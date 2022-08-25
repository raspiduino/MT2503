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
 * BrowserAppDMgr.h
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPDMGR_H
#define MMI_BROWSERAPPDMGR_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppTypes.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wps_struct.h"

extern U16 mmi_brw_dmgr_get_number_of_bookmark_list_items (void);
extern U16 mmi_brw_dmgr_get_number_of_browse_path_list_items(void);
extern U16 mmi_brw_dmgr_get_number_of_select_bookmark_list_items(void);

extern MMI_BOOL mmi_brw_app_dmgr_recent_page_list_screen_check_data_func(U16 scr_id);
extern MMI_BOOL mmi_brw_app_dmgr_recent_page_list_screen_get_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_recent_page_host_list_screen_check_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_recent_page_options_screen_get_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_stored_page_list_screen_check_data_func(U16 scr_id);
extern MMI_BOOL mmi_brw_app_dmgr_stored_page_list_screen_get_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_stored_page_options_screen_get_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_trusted_cert_list_screen_check_data_func(U16 scr_id);
extern MMI_BOOL mmi_brw_app_dmgr_trusted_cert_list_screen_get_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_trusted_cert_view_screen_check_data_func(U16 scr_id);
extern MMI_BOOL mmi_brw_app_dmgr_trusted_cert_view_screen_get_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_page_objects_type_screen_check_data_func(U16 scr_id);
extern MMI_BOOL mmi_brw_app_dmgr_page_objects_type_screen_get_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_page_objects_options_screen_get_data_func(U16 scr_id);

extern MMI_BOOL mmi_brw_app_dmgr_static_screen_check_data_func(U16 scr_id);
extern MMI_BOOL mmi_brw_app_dmgr_static_screen_get_data_func(U16 scr_id);

extern void mmi_brw_app_dmgr_get_certificate_str(U8 *msg_str, mmi_brw_certificate_content_struct *certificate);
extern void mmi_brw_app_dmgr_get_session_info_str(U8 *msg_str);
extern void mmi_brw_app_dmgr_copy_current_certificate(
                mmi_brw_certificate_content_struct *dest_p,
                wps_sec_get_current_cert_rsp_struct *src_p);

extern void mmi_brw_app_dmgr_copy_trusted_certificate(
        mmi_brw_certificate_content_struct *dest_p,
        wps_sec_cert_content_struct *src_p);

/*******************************ADDRESS LIST START**************************/
extern void mmi_brw_app_dmgr_pre_entry_address_list(void);
extern void mmi_brw_app_dmgr_pre_entry_enter_url(void);
extern void mmi_brw_app_dmgr_pre_entry_enter_url_search_keywords(void);
extern void mmi_brw_app_dmgr_launch_address_list_url(void);
extern void mmi_brw_app_dmgr_edit_address_list_item(void);
extern void mmi_brw_app_dmgr_add_addr_list_item_to_bookmark(void);
extern void mmi_brw_app_dmgr_delete_addr_list_item(void);
extern void mmi_brw_app_dmgr_delete_all_addr_list(void);
extern void mmi_brw_app_dmgr_add_addr_list_item(void);
#ifndef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
extern void mmi_brw_app_dmgr_launch_entered_url(void);
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
extern void mmi_brw_app_dmgr_add_search_list_item(void);
extern void mmi_brw_app_dmgr_set_addr_list_url_as_homepage(void);
extern void mmi_brw_app_dmgr_add_search_or_input_url_item(void);
/*******************************ADDRESS LIST START**************************/


/***********************************BOOKMARK START**************************/
extern void mmi_brw_app_dmgr_pre_entry_bookmark_list(void);
extern void mmi_brw_app_dmgr_add_to_bookmark(void);
extern void mmi_brw_app_dmgr_open_bookmark_folder(void);
extern void mmi_brw_app_dmgr_pre_entry_rename_folder(void);
extern void mmi_brw_app_dmgr_delete_bookmark_folder(void);
extern void mmi_brw_app_dmgr_launch_bookmark(void);
extern void mmi_brw_app_dmgr_pre_entry_edit_bookmark(void);
extern void mmi_brw_app_dmgr_delete_bookmark_file(void);
extern void mmi_brw_app_dmgr_delete_all_user_files(void);
extern void mmi_brw_app_dmgr_pre_entry_add_bookmark(void);
extern void mmi_brw_app_dmgr_set_bookmark_as_homepage(void);
extern void mmi_brw_app_dmgr_pre_entry_create_folder(void);
extern void mmi_brw_app_dmgr_move_bookmark_to(void);
extern void mmi_brw_app_dmgr_browse_path_select_folder(void);
extern void mmi_brw_app_dmgr_add_bookmark(void);
extern void mmi_brw_app_dmgr_add_bookmark_replace_file(void);
extern void mmi_brw_app_dmgr_edit_bookmark(void);
extern void mmi_brw_app_dmgr_edit_bookmark_replace_file(void);
extern void mmi_brw_app_dmgr_create_bookmark_folder(void);
extern void mmi_brw_app_dmgr_save_to_bookmark(void);
extern void mmi_brw_app_dmgr_pre_entry_browse_path_options(void);
extern void mmi_brw_app_dmgr_select_bookmark_open_folder(void);
extern void mmi_brw_app_dmgr_select_bookmark_done(void);
extern void mmi_brw_app_dmgr_get_bookmark_memory_status(U8* output_str);
extern mmi_brw_app_result_enum mmi_brw_app_dmgr_check_selected_bookmark_item(void);
extern void mmi_brw_app_dmgr_pre_entry_bookmark_options(void);
extern U16 mmi_brw_app_dmgr_get_bookmark_options_parent_menu(void);
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
extern void mmi_brw_app_dmgr_pre_entry_browse_path(void);
#endif /* __MMI_BRW_BKM_FOLDER_SUPPORT__ */
extern void mmi_brw_app_dmgr_get_view_bookmark_str(U8 *msg_str, U8* title, U8* url);
/***********************************BOOKMARK END*****************************/

/*******************************MISCELLANEOUS********************************/
extern void mmi_brw_app_dmgr_open_search_web(void);
extern void mmi_brw_app_dmgr_open_homepage(void);
extern void mmi_brw_app_dmgr_last_web_address(void);
extern void mmi_brw_app_dmgr_launch_embedded_link(void);
/*****************************MISCELLANEOUS END******************************/

/*****************************RECENT PAGES START*****************************/
extern void mmi_brw_app_dmgr_launch_recent_pages_url(void);
extern void mmi_brw_app_dmgr_delete_recent_page(void);
extern void mmi_brw_app_dmgr_delete_all_recent_pages(void);
extern void mmi_brw_app_dmgr_set_recent_page_url_as_homepage(void);
extern void mmi_brw_app_dmgr_add_recent_page_list_item_to_bookmark(void);
extern void mmi_brw_app_dmgr_open_recent_page_host(void);
extern void mmi_brw_app_dmgr_delete_recent_host(void);
extern void mmi_brw_app_dmgr_sort_recent_page_by_site(void);
extern void mmi_brw_app_dmgr_sort_recent_page_by_last_visited(void);
extern void mmi_brw_app_dmgr_sort_recent_page_by_most_visited(void);
extern void mmi_brw_app_dmgr_pre_entry_recent_page_options(void);
/******************************RECENT PAGES END******************************/

/****************************RENDERED PAGES START****************************/
extern void mmi_brw_app_dmgr_rendered_page_edit(void);
extern void mmi_brw_app_dmgr_rendered_page_reset(void);
extern void mmi_brw_app_dmgr_rendered_page_select_file(void);
extern void mmi_brw_app_dmgr_rendered_page_select_mode(void);
extern void mmi_brw_app_dmgr_activate_select_mode(void);
extern void mmi_brw_app_dmgr_launch_this_link(void);
extern void mmi_brw_app_dmgr_set_this_link_as_homepage(void);
extern void mmi_brw_app_dmgr_add_this_link_to_bookmark(void);
extern void mmi_brw_app_dmgr_set_this_page_as_homepage(void);
extern void mmi_brw_app_dmgr_add_this_page_to_bookmark(void);
extern void mmi_brw_app_dmgr_store_this_page(void);
extern void mmi_brw_app_dmgr_pre_entry_this_page_properties(void);
extern void mmi_brw_app_dmgr_select_mode_save_as(void);
extern void mmi_brw_app_dmgr_select_mode_exit(void);
extern void mmi_brw_app_dmgr_save_page_object(void);
extern void mmi_brw_app_dmgr_refresh_page(void);
extern void mmi_brw_app_dmgr_navigate_forward(void);
extern void mmi_brw_app_dmgr_navigate_backward(void);
extern U16 mmi_brw_app_dmgr_get_ren_page_options_parent_menu(void);
extern void mmi_brw_app_dmgr_page_objects_save_as(void);
extern void mmi_brw_app_dmgr_pre_entry_select_mode_image_properties(void);
extern void mmi_brw_app_dmgr_pre_entry_page_object_options(void);
/***************************RENDERED PAGES END***************************/

/****************************SETTINGS START******************************/
extern void mmi_brw_app_dmgr_update_thumbnail_status(void);
extern void mmi_brw_app_dmgr_update_screen_size(void);
extern void mmi_brw_app_dmgr_update_9way_mode(void);
extern void mmi_brw_app_dmgr_select_profile_setting_always_ask(void);
extern void mmi_brw_app_dmgr_select_profile_setting_sim1(void);
extern void mmi_brw_app_dmgr_select_profile_setting_sim2(void);
extern void mmi_brw_app_dmgr_select_profile_setting_wlan(void);
extern void mmi_brw_app_dmgr_rendering_modes_standard(void);
extern void mmi_brw_app_dmgr_rendering_modes_text_wrap(void);
extern void mmi_brw_app_dmgr_rendering_modes_screen_optimized(void);
extern void mmi_brw_app_dmgr_rendering_modes_text_only(void);
extern void mmi_brw_app_dmgr_navigation_modes_four_way(void);
extern void mmi_brw_app_dmgr_navigation_modes_two_way(void);
extern void mmi_brw_app_dmgr_navigation_modes_scrolling(void);
extern void mmi_brw_app_dmgr_font_size_small(void);
extern void mmi_brw_app_dmgr_font_size_medium(void);
extern void mmi_brw_app_dmgr_font_size_large(void);
extern void mmi_brw_app_dmgr_save_browser_preferences(void);
extern void mmi_brw_app_dmgr_write_browser_preferences(void);
extern void mmi_brw_app_dmgr_delete_trusted_certificate(void);
extern void mmi_brw_app_dmgr_get_trusted_certificate(void);
extern void mmi_brw_app_dmgr_get_current_certificate(void);
extern void mmi_brw_app_dmgr_get_current_session_info(void);
extern void mmi_brw_app_dmgr_update_homepage_setting(U8 homepage_setting);
extern void mmi_brw_app_dmgr_update_user_defined_homepage(void);
extern void mmi_brw_app_dmgr_pre_entry_homepage_edit(void);
extern void mmi_brw_app_dmgr_delete_trusted_certificates(void);
#ifdef __BAIDU_TRANSCODING_SUPPORT__
extern void mmi_brw_app_dmgr_update_baidu_proxy_status(void);
extern void mmi_brw_app_dmgr_switch_off_baidu_proxy(void);
#endif //__BAIDU_TRANSCODING_SUPPORT__ 
/****************************SETTINGS END*******************************/

/****************************STORED PAGES START****************************/
extern void mmi_brw_app_dmgr_delete_stored_page(void);
extern void mmi_brw_app_dmgr_delete_all_stored_pages(void);
extern void mmi_brw_app_dmgr_open_stored_page(void);
extern void mmi_brw_app_dmgr_pre_entry_stored_page_properties(void);
extern void mmi_brw_app_dmgr_set_stored_page_url_as_homepage(void);
extern void mmi_brw_app_dmgr_add_stored_pages_list_item_to_bookmark(void);
extern void mmi_brw_app_dmgr_save_stored_page(void);
extern void mmi_brw_app_dmgr_rename_stored_page(void);
extern void mmi_brw_app_dmgr_pre_entry_rename_stored_page(void);
extern void mmi_brw_app_dmgr_pre_entry_stored_pages_list(void);
extern void mmi_brw_app_dmgr_pre_entry_stored_page_options(void);

/****************************STORED PAGES END******************************/

/****************************SHORTCUTS START********************************/
extern void mmi_brw_app_dmgr_pre_entry_add_shortcut(void);
extern void mmi_brw_app_dmgr_pre_entry_edit_shortcut(void);
extern void mmi_brw_app_dmgr_save_shortcut(void);
extern void mmi_brw_app_dmgr_launch_shortcut(void);
extern void mmi_brw_app_dmgr_delete_shortcut(void);
/****************************SHORTCUTS END********************************/

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPDMGR_H */
