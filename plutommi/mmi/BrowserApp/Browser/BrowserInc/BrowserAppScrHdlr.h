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
 * BrowserAppScrHdlr.h
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPSCRHDLR_H
#define MMI_BROWSERAPPSCRHDLR_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppTypes.h"
#include "MMIDataType.h"

extern void mmi_brw_app_sh_display_menu_cui(U16 screen_id);
extern void mmi_brw_app_sh_display_inline_cui(U16 screen_id, mmi_id parent_group_id);
extern void mmi_brw_app_sh_display_fseditor_cui(U16 screen_id);
extern void mmi_brw_app_sh_display_naming_rule_cui(U16 screen_id);

extern mmi_brw_app_result_enum mmi_brw_app_sh_init_function(U16 scr_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_create_func(U16 scr_id);
extern void mmi_brw_app_sh_rendered_page_exit_func(void);
extern void mmi_brw_app_sh_temp_progress_screen_exit_func(void);
extern void mmi_brw_app_sh_address_list_exit_func(void);
extern void mmi_brw_app_sh_confirm_screen_exit_func(void);
extern mmi_ret mmi_brw_app_sh_static_list_delete_scr_handler(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_sh_recent_pages_delete_scr_handler(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_sh_view_certificate_delete_scr_handler(mmi_event_struct *evt);
extern mmi_brw_app_result_enum mmi_brw_app_sh_dynamic_list_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_bookmarks_list_post_func(U16 scr_id);
extern void mmi_brw_app_sh_bookmarks_list_exit_func(void);
extern void mmi_brw_app_sh_browse_path_lsk_func(void);
extern void mmi_brw_app_sh_browse_path_exit_func(void);
extern void mmi_brw_app_sh_bookmarks_list_rsk_func(void);
extern void mmi_brw_app_sh_select_bookmark_rsk_func(void);
extern mmi_brw_app_result_enum mmi_brw_app_sh_inline_screen_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_viewer_screen_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_scrhdlr_pre_small_screen (U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_scrhdlr_pre_osl_small_screen (U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_sec_confirm_pre_func (U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_bookmark_options_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_add_bookmark_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_address_list_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_enter_url_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_bookmark_browse_path_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_upload_progress_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_rendered_page_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_splash_screen_pre_func(U16 screen_id);

extern mmi_brw_app_result_enum mmi_brw_app_sh_edit_bookmark_pre_func(U16 screen_id);

extern void mmi_brw_app_sh_dummy_history_func(void *arg);

extern mmi_ret mmi_brw_app_sh_dynamic_list_delete_scr_handler(mmi_event_struct *evt);

extern void mmi_brw_app_sh_address_list_lsk_func(void);
extern void mmi_brw_app_sh_address_list_rsk_func(void);
extern mmi_ret mmi_brw_app_sh_enter_url_editor_delete_scr_handler(mmi_event_struct *evt);
extern void mmi_brw_app_sh_enter_url_rsk_func(void);
extern void mmi_brw_app_sh_enter_url_lsk_func(void);
extern mmi_brw_app_result_enum mmi_brw_app_sh_generic_post_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_progress_screen_post_func(U16 screen_id);
extern void mmi_brw_app_sh_browser_options_rsk_func(void);
extern void mmi_brw_app_sh_stored_pages_list_lsk_func(void);
extern void mmi_brw_app_sh_stored_pages_list_rsk_func(void);
extern void mmi_brw_app_sh_security_settings_rsk_func(void);
extern mmi_brw_app_result_enum mmi_brw_app_sh_rendered_page_pre_func(U16 screen_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_rendered_page_post_func(U16 scr_id);
extern mmi_brw_app_result_enum mmi_brw_app_sh_splash_screen_post_func(U16 scr_id);
#ifdef __OP01__ 
extern void mmi_brw_app_sh_view_url_screen_rsk_func(void);
#endif /* __OP01__  */
extern void mmi_brw_app_sh_ren_page_this_page_rsk_func(void);
extern void mmi_brw_app_sh_memory_status_screen_rsk_func(void);
extern void mmi_brw_app_sh_trusted_certificates_list_lsk_func(void);
extern void mmi_brw_app_sh_trusted_certificates_list_rsk_func(void);
extern void mmi_brw_app_sh_view_certificate_screen_rsk_func(void);
extern void mmi_brw_app_sh_navigate_rsk_func(void);
extern void mmi_brw_app_sh_page_actions_list_lsk_func(void);
extern void mmi_brw_app_sh_page_actions_list_rsk_func(void);
extern void mmi_brw_app_sh_page_actions_list_rsk_func(void);
extern void mmi_brw_app_sh_page_object_types_lsk_func(void);
extern void mmi_brw_app_sh_page_object_types_rsk_func(void);
extern void mmi_brw_app_sh_recent_pages_host_lsk_func(void);
extern void mmi_brw_app_sh_recent_pages_host_rsk_func(void);
extern void mmi_brw_app_sh_bookmark_browse_path_rsk_func(void);
extern void mmi_brw_app_sh_bookmark_send_bookmark_options_rsk_func(void);
extern void mmi_brw_app_sh_save_to_bookmark_lsk_func(void);
extern void mmi_brw_app_sh_select_bookmark_rsk_func(void);
extern void mmi_brw_app_sh_sec_confirm_lsk_func(void);
extern void mmi_brw_app_sh_sec_confirm_rsk_func(void);
extern void mmi_brw_app_sh_out_of_mem_confirm_lsk_func(void);
extern void mmi_brw_app_sh_uha_uri_scheme_confirm_lsk_func(void);
extern void mmi_brw_app_sh_uha_uri_scheme_confirm_rsk_func(void);
extern void mmi_brw_app_sh_page_size_check_lsk_func(void);
extern void mmi_brw_app_sh_page_size_check_rsk_func(void);
extern void mmi_brw_app_sh_loading_time_check_lsk_func(void);
extern void mmi_brw_app_sh_loading_time_check_rsk_func(void);
extern void mmi_brw_app_sh_upload_progress_rsk_func(void);
extern void mmi_brw_app_sh_upload_cancel_lsk_func(void);
extern void mmi_brw_app_sh_upload_cancel_rsk_func(void);
extern void mmi_brw_app_sh_post_session_info_screen_lsk_func(void);
extern void mmi_brw_app_sh_settings_select_profile_rsk_func(void);

extern void mmi_brw_app_sh_ren_page_this_link_rsk_func(void);
extern mmi_ret mmi_brw_app_sh_select_bookmark_delete_scr_handler(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_sh_sec_confirm_dlg_delete_scr_handler(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_sh_sec_confirm_dlg_delete_scr_handler(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_sh_uha_uri_scheme_confirm_dlg_delete_scr_handler(mmi_event_struct *evt);

extern void mmi_brw_app_sh_encoding_methods_lsk_func(void);
extern void mmi_brw_app_sh_page_objects_lsk_func(void);
extern void mmi_brw_app_sh_page_objects_rsk_func(void);
extern void mmi_brw_app_sh_generic_rsk_func(void);
extern void mmi_brw_app_sh_bookmark_browse_path_rsk_func(void);
extern void mmi_brw_app_sh_shortcuts_list_rsk_func(void);

extern mmi_ret mmi_brw_app_auth_sec_group_proc(mmi_event_struct *evt);

//NEERAJ
/* Menu CUI procs */
extern mmi_ret mmi_brw_app_internet_service_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_shortcut_options_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_bookmarks_options_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_browse_path_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_input_address_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_enter_url_editor_options_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_recent_page_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_stored_page_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_render_page_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_settings_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_encoding_methods_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_settings_trusted_certificate_options_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_bookmark_in_fmgr_menu_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_objects_options_menu_cui_proc(mmi_event_struct *evt);

/* End of Menu CUI procs */
/* Inline cui Procs */
extern mmi_ret mmi_brw_bkm_view_bookmark_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_bkm_save_bookmark_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_bkm_add_bookmark_inline_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_settings_pref_inline_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_authentication_inline_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_edit_shortcut_inline_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_properties_proc(mmi_event_struct *evt);
extern void mmi_brw_settings_pref_inline_cui_fill_data(void);
extern void mmi_brw_view_bookmark_inline_cui_fill_data(void);
extern void mmi_brw_add_bookmark_inline_cui_fill_data(void);
extern void mmi_brw_authentication_inline_cui_fill_data(void);
extern void mmi_brw_properties_inline_cui_fill_data(void);
extern void mmi_brw_edit_shortcut_inline_cui_fill_data(void);
extern void mmi_brw_properties_inline_cui_update_item_icon(void);

/* End of Inline CUI procs*/
/* File naming rule cui */
extern mmi_ret mmi_brw_app_file_naming_rule_cui_proc(mmi_event_struct *evt);
/* End of file naming rule cui */

/* FS editor procs */
extern mmi_ret mmi_brw_app_stored_page_rename_fseditor_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_store_offline_fseditor_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_edit_url_fseditor_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_enter_url_fseditor_cui_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_edit_homepage_fseditor_cui_proc(mmi_event_struct *evt);

/* File MGR cui procs */
extern mmi_ret mmi_brw_app_browse_path_open_folder_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_recv_file_open_folder_proc(mmi_event_struct *evt);
extern mmi_ret mmi_brw_app_browse_path_open_folder_proc(mmi_event_struct *evt);

/* End of File MGR cui procs */
extern void  mmi_brw_app_notify_wap_close(void);
extern mmi_ret mmi_brw_close_group_proc(mmi_event_struct *evt);

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPSCRHDLR_H */
