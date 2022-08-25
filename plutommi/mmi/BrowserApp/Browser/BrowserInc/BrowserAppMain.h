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
 * BrowserAppMain.h
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPMAIN_H
#define MMI_BROWSERAPPMAIN_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppTypes.h"
#include "ProfilesSrvGprot.h" /* for all tone enum */
#include "BrowserAppTypes.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "InlineCuiGprot.h"
#include "BrowserSrvGprot.h"
#include "BrowserSrvProts.h"
#include "mmi_frm_scenario_gprot.h"

extern void mmi_brw_app_ui_draw_display_popup_ext(MMI_STR_ID string, mmi_event_notify_enum event_id);
extern void mmi_brw_app_ui_draw_display_popup(U8 *string, mmi_event_notify_enum event_id);
extern void mmi_brw_app_ui_draw_display_confirm(UI_string_type message , FuncPtr lsk, FuncPtr rsk, MMI_BOOL csk_disabled);
extern void mmi_brw_app_ui_draw_display_confirm_with_sg(UI_string_type message, FuncPtr lsk, FuncPtr rsk, MMI_BOOL need_csk_disabled, MMI_ID scrn_group);

extern GetItemFuncPtr mmi_brw_app_get_dynamic_list_callback_func(U16 scr_id);
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
extern tap_cllback_func mmi_brw_app_get_tap_callback_func(U16 scr_id);
extern show_toolbar_func_ptr mmi_brw_app_get_show_toolbar_func(U16 scr_id);
#endif /* #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */

extern U16 mmi_brw_app_get_dynamic_list_number_of_items(U16 scr_id);
extern hide_hdlr_func_ptr mmi_brw_get_hide_handler_for_parent_menu_id(U16 menu_id);
extern S32 mmi_brw_app_set_dynamic_list_highlighted_item(U16 scr_id, U8** gui_buffer);

extern PU8 mmi_brw_app_construct_view_data(U16 scr_id);
extern PU8 mmi_brw_app_get_editor_buffer(U16 scr_id);
extern U32 mmi_brw_app_get_editor_input_type(U16 scr_id);
extern U32 mmi_brw_app_get_editor_buffer_length(U16 scr_id);
extern U8 mmi_brw_app_get_naming_rule_operation(U16 scr_id);
extern U16 mmi_brw_app_get_editor_title_string(U16 scr_id);
extern U8* mmi_brw_app_get_naming_rule_selected_folder_path(U16 scr_id);

extern U16 mmi_brw_app_get_viewer_buffer_length(U16 scr_id);
extern void mmi_brw_app_get_small_screen_data(U16 scr_id, U16 *msg_str, U16 *str_id, U16 *img_id, srv_prof_tone_enum *tone_id);
extern U16 mmi_brw_app_get_object_properties_count(void);
extern U16 mmi_brw_app_get_parent_menu_id(U16 scr_id);
extern browser_cui_proc mmi_brw_app_get_menu_cui_proc_func(U16 scr_id);
extern MMI_ID mmi_brw_app_get_menu_cui_group_id(U16 scr_id);
extern MMI_ID mmi_brw_app_get_grp_id_by_scrn_id(U16 scr_id);
extern browser_cui_proc mmi_brw_app_get_inline_cui_proc_func(U16 scr_id);
extern const cui_inline_struct mmi_brw_app_get_inline_cui_global_data(U16 scr_id);
extern FuncPtr mmi_brw_app_get_inline_cui_fill_func(U16 scr_id);
extern U16 mmi_brw_app_get_splash_scr_id(void);
extern U32 mmi_brw_app_get_editor_buffer_char_count(U16 scr_id);

extern void mmi_brw_app_set_all_db_index(U16 scr_id);
extern U16 mmi_brw_app_get_title_icon(U16 icon_id);
extern void mmi_brw_app_free_browser_memory(void **ptr);
extern void mmi_brw_app_encoding_methods_initialize_list(void);
extern void mmi_brw_app_cancel_browser_preferences(void);
extern void mmi_brw_app_context_init(void);
extern void mmi_brw_app_GoBackServicesMenu(void);
extern void mmi_brw_app_exit(void);
extern void mmi_brw_app_set_progress_screen_params(U16 title_id, U16 msg_id);
extern void mmi_brw_app_show_progress_screen(U16 title_id, U16 msg_id);
extern void mmi_brw_app_load_url(U8 *url_p);
extern void mmi_brw_app_create_service_instance(void);

extern void mmi_brw_app_session_init(void);
extern void mmi_brw_app_dynamic_context_init(void);
extern void mmi_brw_bookmarks_dynamic_context_init(void);
extern void mmi_brw_app_launch_if_or_insert_in_history(U16 new_scr_id, FuncPtr new_scr_if_func, mmi_id parent_group_id, mmi_proc_func proc_func);
extern MMI_BOOL mmi_brw_app_is_browser_screen(U16 screen_id);

extern MMI_BOOL mmi_brw_app_check_bam_error_code(U16 error_code);
extern MMI_BOOL mmi_brw_app_check_wps_error_code(U16 error_code);
extern void mmi_brw_app_delete_busy_screen(void);
extern kal_bool mmi_brw_is_browser_active(void);
extern void mmi_brw_delete_all_browser_screens(void);
extern void mmi_brw_app_bam_error_handler(U16 error_code);
extern void mmi_brw_app_wps_error_handler(U16 error_code);

extern MMI_BOOL mmi_brw_app_is_temp_busy_screen_active(void);
extern void mmi_brw_app_adjust_hide_highlight_menu_item(MMI_BOOL show_flag, U16 child_item_id, U16 parent_item_id, U8* gui_buffer, U16 screen_id);
extern void mmi_brw_app_hide_menu_item(MMI_BOOL hide_cond, U16 menu_id);
extern void mmi_brw_app_close_download_and_exit(void);
extern MMI_BOOL mmi_brw_app_is_rendered_page_present(void);

extern void mmi_brw_app_launch_addr_list_url(void);
extern void mmi_brw_app_addr_list_edit_item(void);
extern void mmi_brw_app_add_addr_list_entry_to_bookmark(void);

extern void mmi_brw_app_draw_ren_page_title(void);
extern void mmi_brw_app_wap_uri_scheme_launch(void);
#ifdef __MMI_URI_AGENT__
extern U16 mmi_brw_app_uri_agent_get_pb_result(S32 res);
extern U16 mmi_brw_app_uri_agent_get_tel_result(S32 res);
#endif /* __MMI_URI_AGENT__ */
extern MMI_BOOL mmi_brw_app_is_browser_first_accessed_page(void);
extern MMI_BOOL mmi_brw_is_transferring_media_available(void);
extern void mmi_brw_app_show_sec_popup(void);
extern mmi_event_notify_enum mmi_brw_app_convert_wps_dialog_type_to_mmi_event(void);
extern void mmi_brw_app_pre_entry_goto_url(void);
extern void mmi_brw_app_pre_entry_open_file(void);
extern void mmi_brw_app_set_url_as_homepage(U8 *url_p);
extern void mmi_brw_app_set_url_as_homepage_ok(void);
extern U16 mmi_brw_app_get_error_string_id(srv_brw_error_enum error_code);

extern void mmi_brw_app_file_system_error_handler(S32 error_code);
extern void mmi_brw_app_update_recent_page_sorting_method(U8 sorting_method);
extern void mmi_brw_app_clear_cache(void);
extern void mmi_brw_app_clear_cookie(void);
extern void mmi_brw_app_clear_auth(void);
extern void mmi_brw_app_clear_search_history(void);
extern void mmi_brw_app_clear_url_history(void);
extern void mmi_brw_app_set_rendering_mode(U8 rendering_mode);
extern void mmi_brw_app_set_navigation_mode(U8 navigation_mode);
extern void mmi_brw_app_set_font_size(U8 font_size);

/************************************BOOKMARK START***************************/
extern MMI_BOOL mmi_brw_app_check_available_bookmark_memory(void);
extern void mmi_brw_app_add_bookmark_confirm_GoBackHistory(void);
extern void mmi_brw_app_edit_bookmark_confirm_GoBackHistory(void);
extern void mmi_brw_app_handle_bookmark_error_code(S32 error_code);
extern void mmi_brw_app_bookmarks_context_init(void);
extern U8 mmi_brw_app_get_bookmark_items(U8* sel_folder_name, srv_brw_bkm_bookmark_list_struct* bkm_list);
extern void mmi_brw_app_create_bookmark_list(void);
extern void mmi_brw_app_create_select_bookmark_list(void);
extern U8 mmi_brw_app_get_bookmark_folder_items(srv_brw_bkm_bookmark_list_struct* bkm_list);
extern void mmi_brw_app_create_bookmark_folders_list(void);
/************************************BOOKMARK END***************************/

/*********************************RENDERED PAGE START**************************/
extern void mmi_brw_app_set_status_icon(MMI_BOOL show_icon);
extern void mmi_brw_app_set_ren_page_title_string(void);
extern U8 *mmi_brw_app_get_ren_page_title_string(void);
extern void mmi_brw_app_set_ren_page_title_icon(void);
extern U16 mmi_brw_app_get_ren_page_title_icon(void);
extern void mmi_brw_app_show_root_title_icon(void);
extern void mmi_brw_app_show_animated_title_icon(void);
extern void mmi_brw_app_show_non_animated_title_icon(void);
extern U16 mmi_brw_app_get_animated_title_icon(void);
extern U16 mmi_brw_app_get_non_animated_title_icon(void);
extern U16 mmi_brw_app_get_animated_bearer_icon(void);
extern U16 mmi_brw_app_get_non_animated_bearer_icon(void);
extern U16 mmi_brw_app_get_animated_wifi_icon(void);
extern U16 mmi_brw_app_get_non_animated_wifi_icon(void);
extern U16 mmi_brw_get_wap_icon(void);
extern void mmi_brw_app_ren_page_set_LSK(void);
extern void mmi_brw_app_ren_page_set_RSK(void);
extern void mmi_brw_app_ren_page_select_mode_rsk_exit(void);
extern void mmi_brw_app_stop_ren_page_fetching(void);
extern void mmi_brw_app_pre_exit_ren_page(void);
extern void mmi_brw_app_backward_navigation(void);
extern void mmi_brw_app_display_bkgrd_downloads_list(void);
extern void mmi_brw_app_suspend_bkgrd_downloads(void);
extern void mmi_brw_app_continue_bkgrd_downloads(void);
extern void mmi_brw_app_update_fetching_progress(void);
extern void mmi_brw_app_show_upload_progress(void);
extern void mmi_brw_app_format_size_total(U32 bytes_sent, U32 bytes_total);
extern void mmi_brw_app_util_format_size(U64 size, S8 *buffer);
extern void mmi_brw_app_remove_upload_screens(void);

extern void mmi_brw_app_stop_server_connection_timer(void);
extern void mmi_brw_app_stop_splash_screen_timer(void);

extern void mmi_brw_app_remove_loading_size_time_screens(void);
extern void mmi_brw_app_page_size_checking(void);
extern void mmi_brw_app_send_auth_dlg_ok_rsp(void);
extern void mmi_brw_app_send_auth_dlg_cancel_rsp(void);
extern void mmi_brw_wait_user_action_handler(
        int enable_positive_sk,
        const char *positive_label,
        int positive_label_len,
        int enable_negative_sk,
        const char *negative_label,
        int negative_label_len);
extern void mmi_brw_wait_user_action_positive_key_hdlr(void);
extern void mmi_brw_wait_user_action_negative_key_hdlr(void);
extern void mmi_brw_app_change_ren_page_FTE_toolbar_state(void);
extern MMI_BOOL mmi_brw_app_pre_entry_auth_dialog_screen(mmi_scenario_id scen_id, void *arg);
extern MMI_BOOL mmi_brw_app_pre_entry_sec_confirm_screen(mmi_scenario_id scen_id, void *arg);

/*********************************RENDERED PAGE END**************************/

extern void mmi_brw_app_dmgr_open_search_web(void);
extern MMI_BOOL mmi_brw_app_is_browser_launched_from_main_menu(void);
extern U16 mmi_brw_app_get_top_screen_id(void);
extern MMI_BOOL mmi_brw_app_check_mms_is_ready(void);
extern void mmi_brw_play_tone(srv_prof_tone_enum tone_id);
extern void mmi_brw_app_return_to_editor(void);
extern MMI_BOOL mmi_brw_app_is_screen_present(mmi_id scr_id);
extern void mmi_brw_app_resize_screen_req(void);
extern void mmi_brw_app_reset_object_properties(void);
extern void mmi_brw_app_free_dynamic_list_memory(U16 scr_id);
extern MMI_BOOL mmi_brw_app_is_in_usb_mode(void);
extern void mmi_brw_app_pre_entry_recent_page_list(void);

/************************************CONFIRM SCREENS***************************/
extern void mmi_brw_app_set_as_homepage_confirm(void);
extern void mmi_brw_app_delete_addr_list_item_confirm(void);
extern void mmi_brw_app_delete_all_addr_list_item_confirm(void);
extern void mmi_brw_app_delete_recent_page_item_confirm(void);
extern void mmi_brw_app_delete_all_recent_pages_confirm(void);
extern void mmi_brw_app_delete_recent_page_host_confirm(void);
extern void mmi_brw_app_suspend_bkgrd_downloads_confirm(void);
extern void mmi_brw_app_select_mode_confirm(void);
extern void mmi_brw_app_delete_trusted_certificates_confirm(void);
extern void mmi_brw_app_restore_browser_settings_confirm(void);
extern void mmi_brw_app_clear_cache_confirm(void);
extern void mmi_brw_app_clear_cookie_confirm(void);
extern void mmi_brw_app_clear_auth_confirm(void);
extern void mmi_brw_app_clear_search_history_confirm(void);
extern void mmi_brw_app_clear_url_history_confirm(void);

extern void mmi_brw_app_delete_folder_confirm(void);
extern void mmi_brw_app_delete_bookmark_file_confirm(void);
extern void mmi_brw_app_delete_all_user_files_confirm(void);
extern void mmi_brw_app_browse_path_replace_file_confirm(void);
extern void mmi_brw_app_add_bookmark_replace_file_confirm(void);
extern void mmi_brw_app_edit_bookmark_replace_file_confirm(void);

extern void mmi_brw_app_preferences_save_confirm(void);

extern void mmi_brw_app_delete_stored_page_confirm(void);
extern void mmi_brw_app_save_stored_page_confirm(void);
extern void mmi_brw_app_rename_stored_page_confirm(void);
extern U16 mmi_brw_app_get_title_string_id(U16 scr_id);

/* Inline Cui related */
extern const cui_inline_struct mmi_brw_app_get_inline_cui_global_data(U16 scr_id);
extern browser_cui_proc mmi_brw_app_get_inline_cui_proc_func(U16 scr_id);
extern FuncPtr mmi_brw_app_get_inline_cui_fill_func(U16 scr_id);
/* end of Inline CUI related */
/* CUI related */
extern MMI_ID mmi_brw_app_get_grp_id_by_scrn_id(U16 scr_id);
extern U16 mmi_brw_app_get_highlighted_menu_for_parent_menu_id(U16 menu_id);
extern mmi_proc_func mmi_brw_app_get_proc_func_for_fseditor(U16 scr_id);
/* End fo cui related */
extern void mmi_brw_app_register_for_bearer_info(void);
extern kal_int8 mmi_brw_app_open_bearer(void);
extern kal_int8 mmi_brw_app_open_bearer_ext(void);
extern void mmi_brw_app_continue_launch_browser(void);
#ifdef __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
extern void mmi_brw_app_copy_move_replace_file_confirm(void);
#endif /* __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__ */
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPMAIN_H */
