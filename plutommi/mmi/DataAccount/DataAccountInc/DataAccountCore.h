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

/*******************************************************************************
 * Filename:
 * ---------
 *   DataAccountCore.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for data account core
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _DATA_ACCOUNT_CORE_H
#define _DATA_ACCOUNT_CORE_H
#ifdef __MMI_WLAN_FEATURES__

/***************************************************************************** 
 * Header Files
 *****************************************************************************/
#include "GlobalConstants.h"
#include "MenuCuiGprot.h"
#include "InlineCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "GpiosrvGprot.h"
#include "NotificationGprot.h"
#include "TetheringSrvGprot.h"
#include "custom_wlan_ui_config.h"
#include "mmi_conn_app_trc.h"
#include "FileMgrGProt.h"
#include "FileMgrCUIGProt.h"
#include "mmi_frm_scenario_gprot.h"
#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif
#ifdef __MMI_OP01_WIFI__
#include "cmcc_wlan_auth_gprot.h"
#include "wndrv_ft_types.h"
#endif  /* __MMI_OP01_WIFI__ */

/*******************************************************************************
* Macro Define
*******************************************************************************/
typedef void (*mmi_wlan_action_after_logout_func_ptr) (void);

/***************************************************************************** 
 * Function Declaration
 *****************************************************************************/
// Data Account Service
extern void srv_dtcnt_wlan_auto_pw_on(void);
extern U8 srv_dtcnt_wlan_eap_types (U8 idx);
extern U8 srv_dtcnt_wlan_eap_peap_types (U8 idx);
extern U8 srv_dtcnt_wlan_eap_ttls_types (U8 idx);

// Data Account App
extern S16 mmi_dtcnt_validate_url(U8 *url_p, MMI_BOOL b_blank_url_is_valid);
extern kal_uint8 app_unicode_to_ucs2encoding(kal_wchar unicode, kal_uint8 *charLength, kal_uint8 *arrOut);

// Data Account WLAN App - EAP
void mmi_wlan_entry_user_cert_list(void);
void mmi_wlan_entry_ca_cert_list(void);
void mmi_wlan_eap_type_activate(void);
void mmi_wlan_user_info_save(void);
void mmi_wlan_save_default_eap_connect(void);

#ifndef __CERTMAN_SUPPORT__
void mmi_wlan_entry_private_key_list(void);
#endif

#ifdef WLAN_EAP_TTLS_SUPPORT
void mmi_wlan_entry_eap_ttls_settings_auth_type(void);
void mmi_wlan_eap_ttls_settings_auth_type_ok(void);
void mmi_wlan_eap_ttls_settings_save(void);
#endif

#ifdef WLAN_EAP_PEAP_SUPPORT
void mmi_wlan_entry_eap_peap_settings_eap_type(void);
void mmi_wlan_eap_peap_settings_eap_type_ok(void);
void mmi_wlan_eap_peap_settings_save(void);
#endif

#ifdef WLAN_EAP_TLS_SUPPORT
void mmi_wlan_eap_tls_settings_save(void);
#endif

// Data Account WLAN App - UI
void mmi_wlan_set_status_bar_icon(void);
void mmi_wlan_entry_confirm(U16 msg);
void mmi_wlan_entry_processing(void);
void mmi_wlan_entry_abortable_processing(void);
void mmi_wlan_entry_find_network(void);
void mmi_wlan_network_delete_yes(void);
void mmi_wlan_delete_profile(mmi_wlan_profile_struct* profile);
void mmi_wlan_network_list_change_priority(void);
void mmi_wlan_pre_entry_network_edit(void);
void mmi_wlan_store_curr_ap_into_cntx(mmi_wlan_profile_struct *active_profile);
void mmi_wlan_entry_network_add(void);
void mmi_wlan_entry_network_delete(void);
void mmi_wlan_entry_define_network(void);
void mmi_wlan_action_abort(void);
void mmi_wlan_entry_network_disconnect(void);
void mmi_wlan_entry_find_network_connect(void);
void mmi_wlan_entry_passphrase_input(void);
void mmi_wlan_pre_entry_find_network_connect(void);
void mmi_wlan_action_abort_find_network(void);
void mmi_wlan_entry_network_details(void);
void mmi_wlan_entry_settings(void);
void mmi_wlan_invalid_wep_key_hdlr(void);
MMI_BOOL mmi_wlan_wep_settings_save(void);
void mmi_wlan_wep_settings_fill_inline_struct(void);
void mmi_wlan_entry_wep_settings(void);
void mmi_wlan_exit_wep_settings(void);
void mmi_wlan_entry_wep_settings(void);
void mmi_wlan_wpa_passphrase_save(void);
void mmi_wlan_entry_wpa_passphrase(void);
void mmi_wlan_auth_mode_ok(void);
void mmi_wlan_auth_mode_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_auth_mode(void);
void mmi_wlan_pre_entry_auth_mode(void);
void mmi_wlan_network_edit_save_no(void);
void mmi_wlan_network_edit_save_yes(void);
void mmi_wlan_network_clear_history_data(void);
void mmi_wlan_network_edit_save(void);
void mmi_wlan_network_edit_fill_inline_struct(void);
void mmi_wlan_exit_network_edit(void);
void mmi_wlan_entry_network_edit(void);
void mmi_wlan_network_settings_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_network_settings(void);
void mmi_wlan_entry_conn_status(void);
MMI_BOOL mmi_wlan_tcpip_settings_save(mmi_id send_id);
void mmi_wlan_tcpip_settings_usedhcp_highlight_hdlr(S32 index);
void mmi_wlan_tcpip_settings_fill_inline_struct(void);
void mmi_wlan_entry_tcpip_settings(void);
void mmi_wlan_exit_tcpip_settings(void);
void mmi_wlan_entry_tcpip_settings(void);
void mmi_wlan_pre_entry_tcpip_settings(void);
void mmi_wlan_popup_conn_result_info(srv_dtcnt_wlan_conn_res_struct *result);
void mmi_wlan_pre_entry_advance_settings(void);
void mmi_wlan_entry_wlan_prefer_settings(void);
void mmi_wlan_get_wlan_prefer_settings(void);
void mmi_wlan_save_default_eap_to_display_cntx(void);
void mmi_wlan_invalid_passphrase_popup(U16 prompt);
void mmi_wlan_wizard_option_highlight_define_network(void);
void mmi_wlan_wizard_option_highlight_priority(void);
void mmi_wlan_close_menu_cui(mmi_id *gid);
void mmi_wlan_close_inline_cui(mmi_id *gid);
void mmi_wlan_entry_saved_profile(void);
void mmi_wlan_wep_key_string_formatter(void);
void mmi_wlan_refresh_change_priority_list(void);
void mmi_wlan_prepare_wizard_list(U8 *se_num, U8 *sa_num, U8 *se_sa_num);
void mmi_wlan_refresh_wizard_main_scrn(void);
void mmi_wlan_pre_entry_wlan_wizard(void);
void mmi_wlan_hint_power(U16 index);
void mmi_wlan_change_priority_handler(S32 index);
S32 mmi_wlan_callback_handler(mmi_event_struct* param);
MMI_BOOL mmi_wlan_is_empty_string(U8* scr);
mmi_ret mmi_wlan_searching_scr_leave_proc(mmi_event_struct* evt);
void mmi_wlan_entry_wizard_connect(void);
void mmi_wlan_wizard_option_off(void);
void mmi_wlan_wizard_option_on(void);
void mmi_wlan_show_activated_popup(void);
void mmi_wlan_update_auth_mode_setting(void);
void mmi_wlan_save_connected_ap(supc_abm_bss_info_struct *connected_ap);
mmi_wlan_profile_struct *mmi_wlan_find_profile(U32 profile_id);
void mmi_wlan_entry_default_eap_input(void);
srv_dtcnt_result_enum mmi_wlan_dtcnt_query_profile(U32 prof_id, srv_dtcnt_prof_wlan_struct *dtcnt_prof);
srv_dtcnt_result_enum mmi_wlan_dtcnt_store_profile(mmi_wlan_profile_struct *app_prof, U32 is_add, U32 fields);
extern void mmi_wlan_wizard_list_highlight_hdlr(S32 nIndex);
extern void mmi_wlan_entry_wizard_list_opt(void);
extern void mmi_wlan_enable_entry_main(void);
mmi_wlan_profile_struct* mmi_wlan_search_profile(srv_dtcnt_wlan_conn_res_struct *conn_res);
srv_dtcnt_result_enum mmi_wlan_send_connect_request(mmi_wlan_profile_struct *app_prof);
U32 mmi_wlan_send_scan_request(srv_dtcnt_wlan_scan_res_cb_func_ptr callback, void *user_data);
/* For Power Saving Mode */
void mmi_wlan_entry_power_save_mode(void);
/* For App/Srv split */
mmi_ret mmi_wlan_reg_all_event(void);
S32 mmi_wlan_callback_handler(mmi_event_struct* param);
extern mmi_ret mmi_wlan_cui_event_proc(mmi_event_struct *evt);
mmi_ret mmi_wlan_cui_entry_event_proc(mmi_event_struct *evt);
mmi_ret mmi_wlan_cui_hilite_event_proc(mmi_event_struct *evt);
mmi_ret mmi_wlan_cui_select_event_proc(mmi_event_struct *evt);
mmi_ret mmi_wlan_cui_close_event_proc(mmi_event_struct *evt);
void mmi_wlan_cui_editor_submit_evt_proc(mmi_event_struct *evt);
void mmi_wlan_cui_editor_changed_evt_proc(mmi_event_struct *evt);
void mmi_wlan_cui_editor_abort_evt_proc(mmi_event_struct *evt);
void mmi_wlan_cui_inline_submit_evt_proc(mmi_event_struct *evt);
void mmi_wlan_cui_inline_set_key_evt_proc(mmi_event_struct *evt);
void mmi_wlan_cui_inline_abort_evt_proc(mmi_event_struct *evt);
void mmi_wlan_cui_inline_screen_active_evt_proc(mmi_event_struct *evt);
void mmi_wlan_cui_inline_notify_event_proc(mmi_event_struct *evt);
MMI_BOOL mmi_wlan_check_advanced_setting(U8 use_proxy, U8* port_str);
MMI_BOOL mmi_wlan_get_advance_setting_value(cui_event_inline_submit_struct *submit_event);
MMI_BOOL mmi_wlan_is_same_ap(const mmi_wlan_profile_struct *fst, const mmi_wlan_profile_struct *snd);
void mmi_wlan_set_ui_flow(mmi_wlan_ui_flow_enum flow);
mmi_wlan_ui_flow_enum mmi_wlan_get_ui_flow(void);
void mmi_wlan_set_wapi_test_mode(MMI_BOOL wapi_test_mode);
MMI_BOOL mmi_wlan_get_wapi_test_mode(void);
void mmi_wlan_update_ap_list_after_scan(const srv_dtcnt_wlan_scan_result_struct *cnf);

/* WAPI */
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
MMI_BOOL mmi_wlan_verify_wapi_pre_shared_key(void);
void mmi_wlan_wapi_save_or_connect(void);
void mmi_wlan_entry_wapi_cert_settings(void);
void mmi_wlan_entry_wapi_psk_settings(void);
void mmi_wlan_network_edit_fill_inline_struct_wapi_test_mode(void);
void mmi_wlan_pre_entry_auth_mode_wapi_test_mode(void);
void mmi_wlan_auth_mode_ok_wapi_test_mode(void);
void mmi_wlan_entry_auth_mode_wapi_test_mode(void);
void mmi_wlan_pre_entry_auth_mode_wapi_test_mode(void);
void mmi_wlan_entry_wapi_psk_settings(void);
void mmi_wlan_wapi_select_user_cert_rsp(void *rsp);
void mmi_wlan_wapi_select_ase_cert_rsp(void *rsp);
void mmi_wlan_wapi_change_test_mode(void);
#endif /* __MMI_HIDE_WAPI__ */
#endif /* __WAPI_SUPPORT__ */
#ifdef __MMI_CCA_SUPPORT__
extern void mmi_dtcnt_prov_ind_hdlr(mmi_event_struct *param);
extern void mmi_dtcnt_prov_install_one_done(mmi_event_struct *param);
#endif /* __MMI_CCA_SUPPORT__ */
/* For WLAN Hotspot */
void mmi_wlan_display_waiting_screen(void);
mmi_ret mmi_wlan_turn_off_hotspot_confirm(mmi_alert_result_evt_struct *evt);
void mmi_wlan_turn_off_hotspot_callback(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data);
#ifdef __WPS_SUPPORT__
void mmi_wlan_wps_send_conn_req(wlan_wps_conn_type wps_conn_type);
void mmi_wlan_wps_info_ind_hdlr(mmi_event_struct* param);
void mmi_wlan_set_wps_info(U8 action, U32 value);
void mmi_wlan_entry_wps_connect_info(void);
void mmi_wlan_show_wps_connect_info_scrn(void);
mmi_ret mmi_wlan_entry_wps_conn_info_proc(mmi_event_struct *param);
mmi_ret mmi_wlan_wps_conn_info_leave_cb(mmi_event_struct* evt);
void mmi_wlan_exit_wps_info_popup(void);
void mmi_wlan_get_wps_connect_info(wlan_wps_conn_type wps_conn_type, S32 left_time, U32 pin_code);
void mmi_wlan_wps_connect_timer_start(void);
void mmi_wlan_wps_connect_timer_stop(void);
void mmi_wlan_wps_connect_timeout_cb(void);
void mmi_wlan_wps_connect_end(void);
void mmi_wlan_wps_construct_profile(mmi_wlan_profile_struct* profile, srv_dtcnt_wlan_conn_res_struct *connRes);
void mmi_wlan_wps_save_connected_ap(mmi_wlan_profile_struct* connected_ap);
mmi_wlan_profile_struct* mmi_wlan_wps_search_profile(mmi_wlan_profile_struct *profile, srv_dtcnt_wlan_conn_res_struct *conn_res);
mmi_ret mmi_wlan_cancel_wps_connect(mmi_alert_result_evt_struct *param);
void mmi_wlan_wps_close_info_popup(void);
#endif  /* __WPS_SUPPORT__ */

// Data Accunt WLAN - Utility 
extern BOOL mmi_wlan_hex_to_string(U8 *dest, U8 *src, U8 len);
extern BOOL is_valid_hexstring(U8 *src, U8 len);
extern BOOL is_valid_ascii_string(U8 *src, U8 length);
extern void mmi_wlan_convert_ucs_to_utf8(const char* pInBuffer, char* pOutBuffer, const kal_int32 length);
extern void mmi_wlan_srv2app_profile_convert(srv_dtcnt_prof_wlan_struct *srv_prof, mmi_wlan_profile_struct *app_prof, U32 to_app);
extern void mmi_wlan_fill_profile_auth_settings(const U32 ie_info_type, const char *passphrase, int keylen, const supc_ie_info_struct* supc_ie_info, mmi_wlan_profile_struct* profile);
extern void mmi_wlan_init_profile_by_bss_info(mmi_wlan_profile_struct  *profile, const supc_abm_bss_info_struct *bssinfo, const char *passphrase, int keylen);

// Data Accunt WLAN - CUI 
mmi_id cui_wlan_list_create(mmi_id parent_gid, void* parent_data);      /* Create WLAN list CUI */
void cui_wlan_list_run(mmi_id cui_gid);                                 /* Execute  WLAN CUI */
void cui_wlan_list_close(mmi_id cui_gid);                               /* Close WLAN CUI */
MMI_BOOL cui_wlan_list_nmgr_cb(mmi_scenario_id scen_id, void *arg);
void cui_wlan_connect_event_hdlr(mmi_event_struct* param);
void cui_wlan_disconnect_event_hdlr(mmi_event_struct* param);
    
#ifdef __MMI_OP01_WIFI__
void mmi_wlan_auto_search_timeout_cb(void);
void mmi_wlan_start_auto_search_timer(void);
void mmi_wlan_stop_auto_search_timer(void);
void mmi_wlan_get_auto_search_settings(void);
void mmi_wlan_exit_new_wizard_list(void);
void mmi_wlan_entry_find_specific_ap_scr(void);
void mmi_wlan_cmcc_prepare_wizard_list(U8 *se_num, U8 *sa_num, U8 *se_sa_num);
void mmi_wlan_entry_trust_list(void);
void mmi_wlan_entry_trust_list_option_full(void);
void mmi_wlan_entry_trust_list_option_empty(void);
void mmi_wlan_trust_list_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_black_list(void);
void mmi_wlan_entry_black_list_option(void);
void mmi_wlan_black_list_highlight_hdlr(S32 nIndex);
MMI_BOOL mmi_wlan_is_default_trust_ap(const mmi_wlan_profile_struct *profile);
MMI_BOOL mmi_wlan_is_black_list_ap(const mmi_wlan_profile_struct *profile);
void mmi_wlan_cmcc_entry_wizard_list(void);
void mmi_wlan_cmcc_refresh_main_screen(void);
void mmi_wlan_cmcc_entry_saved_ap_list(void);
void mmi_wlan_cmcc_saved_ap_list_highlight_hdlr(S32 nIndex);
void mmi_wlan_cmcc_saved_ap_list_options(void);
void mmi_wlan_cmcc_empty_saved_as_list_options(void);
void mmi_wlan_entry_auto_search_settings(void);
void mmi_wlan_add_into_black_list_hdlr(void);
void mmi_wlan_add_ap_into_black_list(mmi_wlan_profile_struct *profile);
void mmi_wlan_remove_cur_ap_from_bk_list(void);
void mmi_wlan_remove_all_ap_from_bk_list(void);
void mmi_wlan_entry_find_result_list(void);
void mmi_wlan_entry_find_result_list_opt(void);
void mmi_wlan_build_find_result_list_opt(cui_menu_event_struct *menu_evt);
void mmi_wlan_find_result_list_highlight_hdlr(S32 nIndex);
void mmi_wlan_entry_ap_details(void);
void mmi_wlan_update_ap_details_info(void);
void mmi_wlan_get_ap_details_info(mmi_wlan_profile_struct* profile);
void mmi_wlan_adjust_default_ap_priority(void);
void mmi_wlan_cmcc_change_priority(U8 old_priority, U8 new_priority);
void mmi_wlan_update_profile_in_db(mmi_wlan_profile_struct* app_prof);
void mmi_wlan_update_settings_in_db(void);
void mmi_wlan_storage_save_black_list(U16 recordId, void* data);
void mmi_wlan_storage_save_auto_searching_setting(U16 recordId, mmi_wlan_auto_search_struct* setting);
void mmi_wlan_storage_read_black_list(U16 recordId, mmi_wlan_black_list_struct* profile);
void mmi_wlan_storage_read_auto_searching_setting(U16 recordId);
void mmi_wlan_ip_addr_change_cnf_handler(mmi_event_struct* evt);
/* For auto conn. */
void mmi_wlan_auto_conn_prepare (void);
void mmi_wlan_auto_conn_trigger_by_init (void);
void mmi_wlan_auto_conn_trigger_by_scan (void);
void mmi_wlan_auto_conn_scan_result_cb(U32 job_id, void *user_data, srv_dtcnt_wlan_scan_result_struct *scan_res);
void mmi_wlan_auto_conn_run (void);
void mmi_wlan_auto_conn_proc(U16 index);
/* For AP Reselect */
MMI_BOOL mmi_wlan_is_allow_to_show_scrn(void);
/* For proxy exclusion list */
void mmi_wlan_entry_proxy_exclusive_list(void);
void mmi_wlan_exclusive_ip_addr_highlight_hdlr(S32 index);
void mmi_wlan_entry_exclusive_ip_addr_option_menu(void);
pBOOL mmi_wlan_get_exclusive_ip_addr_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
mmi_ret mmi_wlan_exclusive_ip_addr_group_proc(mmi_event_struct *evt);
void mmi_wlan_entry_exclusive_ip_address_screen(mmi_scrn_essential_struct *scrn_node);
void mmi_wlan_exclusive_ip_add_ip(mmi_id inline_cui_gid);
void mmi_wlan_exclusive_ip_delete_ip(mmi_id inline_cui_gid, U32 ip_addr_id);
void mmi_wlan_pre_entry_exclusive_ip_address_screen(void);
/* For portal cert. client */
void mmi_wlan_portal_cert_client_setting_entry(void);
void mmi_wlan_portal_cert_run(void);
void mmi_wlan_portal_cert_callback(cmcc_wlan_auth_ret_enum ret);
void mmi_wlan_portal_cert_login_start(void);
void mmi_wlan_portal_cert_logout_start(mmi_wlan_action_after_logout_func_ptr to_do);
void mmi_wlan_portal_cert_logout_cb(cmcc_wlan_auth_ret_enum ret);
mmi_ret mmi_wlan_portal_cert_logout_cancel(mmi_alert_result_evt_struct *evt);
void mmi_wlan_cmcc_connect_proc(void);
void mmi_wlan_cmcc_disconnect_proc(void);
void mmi_wlan_cmcc_deinit_proc(void);
srv_dtcnt_result_enum mmi_wlan_cmcc_entry_deinit(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data);
void mmi_wlan_cmcc_portal_logout_by_deinit(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data);
void mmi_wlan_cmcc_portal_logout_by_deinit_cb(cmcc_wlan_auth_ret_enum ret);
void mmi_wlan_cmcc_logout_ind_handler(mmi_event_struct* param);
void mmi_wlan_cmcc_logout_ind_cb(cmcc_wlan_auth_ret_enum ret);
void mmi_wlan_cmcc_logout_ind_inform_dtcnt_srv(srv_dtcnt_wlan_logout_rsp_enum rsp);
void mmi_wlan_cmcc_abort_cert_portal(void);
MMI_BOOL mmi_wlan_cmcc_show_portal_result(mmi_scenario_id scen_id, void *arg);
void mmi_wlan_cmcc_entry_portal_proc(void);
void mmi_wlan_cmcc_send_disc_req_after_login_failed(void);
/* Power saving mode */
extern void mmi_wlan_cmcc_entry_power_saving_mode(void);
void mmi_wlan_cmcc_entry_power_saving_mode_hilt_hdlr(S32 nIndex);
void mmi_wlan_cmcc_power_saving_mode_ok(void);
void mmi_wlan_cmcc_set_power_saving_mode(wndrv_test_pwr_mgt_enum pwr_mode);
/* WAPI Cert. Management */
void mmi_wlan_cmcc_opt_menu_load_cert(void);
void mmi_wlan_cmcc_opt_menu_unload_cert(void);
void mmi_wlan_cui_file_mgr_select_evt_proc(mmi_event_struct *evt);
#endif /* __MMI_OP01_WIFI__ */

#endif /* __MMI_WLAN_FEATURES__ */
#endif /* _DATA_ACCOUNT_CORE_H */
