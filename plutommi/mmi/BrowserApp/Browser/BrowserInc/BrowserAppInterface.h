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
 * BrowserAppInteface.h
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPINTERFACE_H
#define MMI_BROWSERAPPINTERFACE_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "UriAgentSrvGprot.h"      /* for the Uri agent enum */
#include "Mmi_frm_mem_gprot.h"  /* for mmi_frm_appmem_evt_struct */
#include "BookmarkCuiGprot.h"
#include "Browser_api.h"
#include "MMIDataType.h"
#include "WAPProfileSrvType.h"
#include "kal_general_types.h"

extern S32 mmi_brw_get_asm_memory_pool_size(void);
extern void mmi_brw_open_file_from_fmgr(void *fullname, int is_short);
extern void mmi_brw_app_if_show_internet_services_menu(void);
extern MMI_ID mmi_brw_app_common_gateway(void);
extern void mmi_brw_app_asm_success_callback(void);
extern void mmi_brw_app_asm_cancel_callback(mmi_frm_appmem_evt_struct *cancel_event);

/******************Bookmarks****************************/
extern void mmi_brw_app_if_show_bookmarks_list(void);
extern void mmi_brw_app_if_show_bookmark_options_menu(void);
extern void mmi_brw_app_if_show_edit_bookmark_screen(void);
extern void mmi_brw_app_if_show_add_bookmark_screen(void);
extern void mmi_brw_app_if_show_bookmark_browse_path_options(void);
extern void mmi_brw_app_if_show_bookmark_open_from_fmgr_screen(void);
extern void mmi_brw_app_if_show_bookmark_browse_path_screen(void);
extern void mmi_brw_app_if_show_select_bookmark_screen(void);
extern void mmi_brw_app_if_show_memory_status_screen(void);
extern void mmi_brw_app_if_show_view_bookmark_screen(void);
extern void mmi_brw_app_if_show_save_to_bookmark_screen(void);
extern void mmi_brw_app_if_show_bookmarks_create_folder(void);

/******************Bookmarks****************************/

extern void mmi_brw_app_if_show_recent_page_options_menu(void);
extern void mmi_brw_app_if_show_page_objects_options(void);
extern void mmi_brw_app_if_show_trusted_certificates_options_menu(void);

/******************Stored Pages****************************/
extern void mmi_brw_app_if_show_stored_page_options_menu(void);
extern void mmi_brw_app_if_show_stored_pages_list(void);
extern void mmi_brw_app_if_show_stored_page_rename_screen(void);

/******************Stored Pages****************************/

extern void mmi_brw_app_if_show_auth_dlg(void);
extern void mmi_brw_app_if_show_progressing_screen(void);
extern void mmi_brw_app_if_show_temp_progressing_screen(void);

extern void mmi_brw_app_if_show_loading_time_check_screen(void);
extern void mmi_brw_app_if_show_page_size_check_screen(void);

extern void mmi_brw_app_if_show_uha_uri_scheme_confirm_screen(void);
extern void mmi_brw_app_if_show_upload_cancel_confirm_screen(void);
extern void mmi_brw_app_if_show_sec_confirm_screen(void);
extern void mmi_brw_app_if_show_out_of_mem_confirm_screen(void);


extern void mmi_brw_app_if_show_recent_pages_host_options_screen(void);
extern void mmi_brw_app_if_show_page_actions_list(void);
extern void mmi_brw_app_if_show_page_object_types(void);
extern void mmi_brw_app_if_show_page_objects(void);
extern void mmi_brw_app_if_show_trusted_certificates_list(void);

extern void mmi_brw_app_if_show_address_list(void);
extern void mmi_brw_app_if_show_settings_menu(void);
extern void mmi_brw_app_if_show_browser_options_menu(void);
extern void mmi_brw_app_if_show_ren_page_this_page_screen(void);
extern void mmi_brw_app_if_show_ren_page_this_link_screen(void);
extern void mmi_brw_app_if_show_rendered_page_options_menu(void);
extern mmi_ret mmi_brw_rendered_page_options_group_proc(mmi_event_struct *evt);
extern void mmi_brw_app_if_show_rendering_modes_screen(void);
extern void mmi_brw_app_if_show_navigation_modes_screen(void);
extern void mmi_brw_app_if_show_font_size_menu(void);
extern void mmi_brw_app_if_show_view_certificate_screen(void);
extern void mmi_brw_app_if_show_browser_preferences_screen(void);
extern void mmi_brw_app_if_show_encoding_methods_screen(void);
extern mmi_ret mmi_brw_rendered_page_group_proc(mmi_event_struct *evt);
extern void mmi_brw_app_if_show_post_session_info_screen(void);
extern void mmi_brw_app_if_show_upload_progress_screen(void);
extern void mmi_brw_app_pre_entry_render_page(void);
extern void mmi_brw_app_if_show_rendered_page_screen(void);
extern void mmi_brw_app_if_show_browser_dummy_screen(void);
extern void mmi_brw_app_if_show_recent_pages_list(void);
extern void mmi_brw_app_if_show_enter_url_screen(void);
extern void mmi_brw_app_if_show_edit_url_screen(void);
extern void mmi_brw_app_if_show_enter_address_options_menu(void);
extern void mmi_brw_app_if_show_send_address_options_menu(void);
extern void mmi_brw_app_if_show_edit_store_offline_screen(void);
extern void mmi_brw_app_if_show_recent_pages_host_screen(void);
extern void mmi_brw_app_if_show_object_properties_screen(void);
extern void mmi_brw_app_if_show_edit_url(void);
extern void mmi_brw_app_if_show_editor_option(void);
extern void mmi_brw_app_if_show_edit_homepage(void);

extern void mmi_brw_app_if_show_shortcuts_list(void);
extern void mmi_brw_app_if_show_shortcuts_list_options(void);
extern void mmi_brw_app_if_show_edit_shortcut(void);

/* Browser Interfaces registered with other application/modules 
   or called by other aplication modules */
extern void mmi_brw_app_deinit(void);
extern mmi_ret mmi_brw_app_if_browser_app_init(mmi_event_struct *evt);
extern void mmi_brw_app_if_asm_stop_callback(void);
extern void mmi_brw_app_if_uri_scheme_handler(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb uri_agent_cb);

extern void mmi_brw_app_open_service_inbox(void);
extern void mmi_brw_app_if_open_file(void);
extern void mmi_brw_app_if_open_file_callback(void *fullname, int is_short);

extern void mmi_brw_app_if_uri_callback(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, S32 result);
extern void mmi_brw_app_if_open_service_inbox(void);
extern void mmi_brw_app_if_send_addr_text_msg(void);
extern mmi_ret mmi_brw_app_if_send_addr_via_bt_proc(mmi_event_struct *evt);
extern void mmi_brw_app_if_send_addr_via_bluetooth(void);
extern void mmi_brw_app_if_send_addr_via_email(void);
extern void mmi_brw_app_if_show_profile_list(void);
extern void mmi_brw_app_if_restore_browser_settings(void);
extern void mmi_brw_app_if_sim1_profile_list(void);
extern void mmi_brw_app_if_sim2_profile_list(void);
extern void mmi_brw_app_if_wlan_profile_list(void);
extern void mmi_brw_app_if_show_connection_info(void);

extern void mmi_brw_app_if_copy_bookmark_to(void);
extern void mmi_brw_app_if_move_bookmark_to(void);
extern void mmi_brw_app_if_copy_move_bkm_to_destination(U8 *src_file_path, U8 *dest_file_path);
extern mmi_ret mmi_brw_app_if_copy_move_bookmark_file_rsp(mmi_event_struct *info);
extern void mmi_brw_app_if_browse_path_replace_file(void);
extern void mmi_brw_app_if_browse_path_open_folder(void);
extern void mmi_brw_app_if_copy_move_boookmark(void);
extern void mmi_brw_app_if_copy_move_replace_file(void);
extern mmi_ret mmi_brw_app_if_send_bookmark_as_sms_proc(mmi_event_struct *evt);
extern void mmi_brw_app_if_send_bookmark_as_sms(void);
extern void mmi_brw_app_if_send_bookmark_as_mms(void);
extern void mmi_brw_app_if_send_bookmark_via_email(void);
extern void mmi_brw_app_if_recv_file_save_to_fmgr_callback(void *fullname);
extern void mmi_brw_app_if_copy_recv_file_to_dest(U8 *src_file_path, U8 *dest_file_path);
extern void mmi_brw_app_if_copy_recv_file_to_dest_callback(void *info);

extern void mmi_brw_app_if_server_connection_timer_callback(void);
extern void mmi_brw_app_if_splash_screen_timer_callback(void);
extern void mmi_brw_app_if_loading_time_check_timer_callback(void);
extern void mmi_brw_app_if_upload_completed_timer_callback(void);

extern void mmi_brw_app_if_configure_data_acc_callback(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id, U8 profile_index, srv_wap_prof_result_enum result);
extern void mmi_brw_load_service_message (kal_uint8 *url, kal_bool is_from_inbox, kal_uint16 sim_id);
extern U16 mmi_brw_get_screen_id (void);
extern void mmi_brw_start_browser_action(U8 option, U8 *url);
extern void mmi_brw_app_if_launch_homepage(void);
extern void mmi_brw_app_if_launch_operator_homepage(void);
extern void mmi_brw_app_if_launch_background_url(U8 *url_p);
extern void mmi_brw_app_if_launch_url(U8 *url_p);
extern U16 mmi_brw_get_select_bookmark_screen_id(void);
extern MMI_BOOL mmi_brw_is_rendered_page_present(void);
extern MMI_BOOL mmi_brw_is_temp_busy_screen_active(void);
extern void mmi_brw_paint_outside_look(void);
extern void mmi_brw_active_profile_homepage_change (U8 *ascii_url, srv_wap_prof_sim_id_enum sim_id);
extern kal_bool mmi_brw_is_active_profile_in_use(mmi_brw_sim_id_enum sim_id);
extern U16 mmi_brw_get_error_string_id(void);
extern void mmi_brw_bookmarks_goto_from_fmgr(void *fullname, int is_short);
extern void mmi_brw_bookmarks_open_from_fmgr(void *fullname);
extern void mmi_brw_deinit_browser(void);
extern void mmi_brw_show_bookmarks_list(void);
extern mmi_ret mmi_brw_app_if_bearer_status_proc(mmi_event_struct* event);
extern mmi_ret mmi_brw_app_if_wifi_bearer_status_proc(mmi_event_struct* event);
extern void mmi_brw_app_if_configure_data_acc(void);
#ifdef __OP01__ 
extern void mmi_brw_app_if_show_view_url_screen(void);
#endif //__OP01__ 
/*NEERAJ*/
extern mmi_ret mmi_brw_internet_service_screen_proc(mmi_event_struct *evt);
/* Select Bookmark , Add Bookmark CUI APIs */
extern mmi_id cui_bkm_sel_bkm_create(mmi_id parent_gid);
extern void cui_bkm_sel_bkm_run(mmi_id cui_gid);
extern void cui_bkm_sel_bkm_close(mmi_id cui_gid);
extern void mmi_brw_sel_bkm_send_result(cui_bkm_evt_enum result, U8 * url, U8* title);
extern mmi_ret mmi_brw_bkm_sel_bookmark_proc(mmi_event_struct *evt);
extern mmi_id cui_bkm_add_bkm_create(mmi_id parent_gid);
extern void cui_bkm_add_bkm_run(mmi_id cui_gid, const U8 * added_utf8_url);
extern void cui_bkm_add_bkm_close(mmi_id cui_gid);
extern void mmi_brw_add_bkm_send_result(cui_bkm_evt_enum result);
extern mmi_ret mmi_brw_bkm_add_bookmark_proc(mmi_event_struct *evt);
/* End of Select Bookmark and Add Bookmark*/
extern void mmi_brw_app_if_show_edit_bookmark_naming_rule_screen(void);
extern mmi_ret mmi_brw_app_open_file_proc(mmi_event_struct *evt);
/*NEERAJ*/
#ifdef OBIGO_Q03C_BROWSER
extern void mmi_brw_app_if_reload_req_processed(void);
#endif
extern mmi_ret mmi_brw_app_if_bearer_switch_hdlr(mmi_event_struct *param);
extern MMI_BOOL mmi_brw_app_is_any_network_available(void);

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPINTERFACE_H */
