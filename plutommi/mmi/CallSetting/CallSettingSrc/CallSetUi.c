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
 *  CallSetUi.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting application user interface
 *
 * Author:
 * -------
 * 
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
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "CommonScreens.h" /* gIndexIconsImageList */
#include "menucuigprot.h"
#include "CallSetProt.h"
#include "CallSetSrvIprot.h"
#include "CallSetSrvGprot.h"
#include "..\CallSettingCore\CallSetCore.h"
#include "mmi_rp_app_callset_def.h"

#include "CallSetSrvGprot.h"
#include "SsSrvGprot.h"

#include "UcmSrvGprot.h" /* SRV_UCM_MAX_NUM_URI_LEN, srv_ucm_is_background_call */

#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_xxx */
#include "NwUsabSrvGprot.h" /* srv_nw_usab_is_any_network_available */

#ifdef __MMI_CM_WHITE_LIST__
#include "SettingDefs.h" /* MIN_PASSWORD_LENGTH */
#ifdef __MMI_CM_WHITE_LIST__
#include "SecSetCuiGprot.h" /* cui_verify_xxx */
#endif /* __MMI_CM_WHITE_LIST__ */
#endif /* __MMI_CM_WHITE_LIST__ */
#include "FSEditorCuiGprot.h"
#include "InlineCuiGprot.h"
#include "app_str.h" /* app_ucs2_itoa, app_ucs2_atoi */
#include "SmsSrvGprot.h" /* srv_sms_get_mailbox_setting */
#include "PhbCuiGprot.h"
#include "BGSoundProt.h" /* mmi_bgsnd_pre_entry_call_setup */
#ifdef __MMI_VIDEO_TELEPHONY__
#include "UcmGprot.h" /* mmi_ucm_vt_app_launch */
#endif /* __MMI_VIDEO_TELEPHONY__ */
#include "CallLogGprot.h"
#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_get_current_mode, srv_mode_switch_is_network_service_available */

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "string.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "PhbSrvGprot.h"
#include "Unicodexdcl.h"
#include "wgui_categories_list.h"
#include "wgui_inputs.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "wgui_categories.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "wgui_touch_screen.h"
#include "IdleGprot.h"
#ifdef __VOICE_CHANGER_SUPPORT__
#include "mdi_audio.h"
#endif /* __VOICE_CHANGER_SUPPORT__ */


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_callset_tap_cb(mmi_tap_type_enum tap_type,S32 index);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static void mmi_callset_set_sim_item_string(mmi_id owner_gid);
static void mmi_callset_change_sim_setting_title(mmi_id owner_gid);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
//static MMI_RET mmi_callset_hdlr_sim_availability_changed(mmi_event_struct *info);
static mmi_ret mmi_callset_proc_common(mmi_event_struct *evt);
static mmi_ret mmi_callset_proc_cf(mmi_event_struct *evt);
static mmi_ret mmi_callset_proc_cb(mmi_event_struct *evt);
static mmi_ret mmi_callset_proc_common_scrn(mmi_event_struct *evt);
static mmi_ret mmi_callset_post_event_hdlr(mmi_event_struct *evt);
static void mmi_callset_common_create_cui(MMI_ID parent_gid, mmi_menu_id menu_id, mmi_menu_id title_id);
static void mmi_callset_common_launch(mmi_menu_id root_menu_id);
#if (MMI_MAX_SIM_NUM >= 2)
static void mmi_callset_call_setting_sim_common_launch(mmi_sim_enum sim_id);
#endif /* MMI_MAX_SIM_NUM >= 2 */
static void mmi_callset_display_error_popup_by_result(srv_ss_result_enum result);
static void mmi_callset_display_popup_by_cause(srv_callset_result_enum cause);
static void mmi_callset_display_error_popup(MMI_STR_ID title);
static void mmi_callset_entry_call_center(mmi_id menu_gid);
static void mmi_callset_entry_call_setting(mmi_id menu_gid);
static void mmi_callset_sel_edit_empty(mmi_id gid);
static void mmi_callset_sel_edit_not_empty(mmi_id gid);
static void mmi_callset_close_fseditor(mmi_id gid);
static void mmi_callset_close_menu(MMI_ID menu_gid, void *app_data);
static void mmi_callset_close_all(void);
static void mmi_callset_reset_fseditor(void);
static void mmi_callset_hilite_common(mmi_id menu_gid, mmi_callset_op_enum op);
static void mmi_callset_hide_common(MMI_ID menu_gid, mmi_callset_op_enum op);
static void mmi_callset_hide_ss_operation(MMI_ID menu_gid, U8 num, mmi_callst_ss_operation_data_struct *data_p);
static void mmi_callset_send_ss_req_common(srv_ss_act_enum act_op, void *act_data, mmi_proc_func callback, void *user_data);
// Call waiting
static void mmi_callset_hide_cw(mmi_id menu_gid);
static void mmi_callset_create_cw_opt(mmi_id parent_gid);
static void mmi_callset_sel_cw_opt(void *info);
static mmi_ret mmi_callset_sel_cw_opt_cb(mmi_event_struct *info);
// Call forward
//static MMI_RET mmi_callset_hdlr_cfu_status_ind(mmi_event_struct *info);
static mmi_ret mmi_callset_sel_cf_opt_cb(mmi_event_struct *info);
static void mmi_callset_hide_cf(MMI_ID menu_gid);
static void mmi_callset_create_cf_opt(mmi_menu_id menu_id);
static void mmi_callset_entry_cf_opt(srv_ss_call_forward_type_enum cf_type, srv_ss_call_type_enum call_type);
static void mmi_callset_sel_cf_opt(void *info);
static void mmi_callset_sel_cf_cancelall(void *info);
static void mmi_callset_entry_cf_activate(MMI_ID menu_gid);
static void mmi_callset_sel_cf_activate(void *info);
static void mmi_callset_entry_cf_num_edit(mmi_id gid);
static void mmi_callset_sel_cf_num_edit_empty(MMI_ID gid);
static void mmi_callset_sel_cf_num_edit_not_empty(MMI_ID gid);
static void mmi_callset_sel_cf_num_edit_done(void *info);
static void mmi_callset_entry_cf_num_edit_from_phb(mmi_id gid);
static void mmi_callset_sel_cf_num_edit_from_phb_done(void *info);
static void mmi_callset_sel_cf_to_vm(void);
static void mmi_callset_create_cfnry_time_opt(mmi_id parent_gid);
static void mmi_callset_sel_cfnry_time_opt(void *info);
// Call barring
#ifdef __MMI_CALLSET_CALL_BARRING__
static mmi_ret mmi_callset_sel_cb_opt_cb(mmi_event_struct *info);
static mmi_ret mmi_callset_proc_cb_passwd(mmi_event_struct *evt);
static void mmi_callset_hide_cb(MMI_ID menu_gid);
static void mmi_callset_create_cb_opt(mmi_menu_id menu_id);
static void mmi_callset_hide_cb_opt(MMI_ID menu_gid);
static void mmi_callset_entry_cb_opt(srv_ss_call_bar_type_enum cb_type, srv_ss_call_type_enum call_type);
static void mmi_callset_sel_cb_opt(void *info);
static void mmi_callset_sel_cb_cancelall(void *info);
static void mmi_callset_sel_cb_operation(mmi_callset_cb_operation_enum cb_op);
static void mmi_callset_sel_cb_change_passwd(void *info);
static void mmi_callset_entry_cb_passwd(mmi_scrn_essential_struct *data);
static WCHAR *mmi_callset_cb_get_passwd_buf(void);
static U16 mmi_callset_cb_get_passwd_title(void);
static void mmi_callset_cb_passwd_check(U8 *text, U8 *cursor, S32 length);
static void mmi_callset_sel_cb_passwd_next(void);
static void mmi_callset_sel_cb_passwd_done(void);
#endif /*__MMI_CALLSET_CALL_BARRING__*/

// Caller ID
#ifdef __MMI_CALLSET_CALLER_ID__
static void mmi_callset_hide_cid(mmi_id menu_gid);
static void mmi_callset_hilite_cid(mmi_id menu_gid);
static void mmi_callset_create_cid_mode(mmi_id parent_gid);
static void mmi_callset_entry_cid_mode(MMI_ID menu_gid);
static void mmi_callset_sel_cid_mode(void *info);
static mmi_ret mmi_callset_sel_cid_mode_cb(mmi_event_struct *info);
#endif /* __MMI_CALLSET_CALLER_ID__ */
// Closed user group
#ifdef __MMI_CALLSET_CUG__
static mmi_ret mmi_callset_proc_cug_list(mmi_event_struct *evt);
static void mmi_callset_hide_cug(mmi_id menu_gid);
static void mmi_callset_entry_cug(void);
static void mmi_callset_hilite_cug(S32 index);
static void mmi_callset_create_cug_opt(void);
static void mmi_callset_entry_cug_opt(MMI_ID menu_gid);
static void mmi_callset_sel_cug_opt(void *info);
static void mmi_callset_hdlr_cug_add(void);
static void mmi_callset_hdlr_cug_name_edit(void);
static void mmi_callset_entry_cug_name_edit(void);
static void mmi_callset_sel_cug_name_edit_done(mmi_id gid);
static void mmi_callset_entry_cug_id_edit(void);
static void mmi_callset_sel_cug_id_edit_done(mmi_id gid);
static void mmi_callset_hdlr_cug_activate(void);
static void mmi_callset_sel_cug_activate(void);
static mmi_ret mmi_callset_sel_cug_activate_cb(mmi_event_struct *info);
static void mmi_callset_sel_cug_deactivate(void);
static mmi_ret mmi_callset_sel_cug_deactivate_cb(mmi_event_struct *info);
static void mmi_callset_sel_cug_delete(void);
#endif /* __MMI_CALLSET_CUG__ */
// auto redial
#ifdef __MMI_CALLSET_AUTO_REDIAL__
static void mmi_callset_hilite_auto_redial(mmi_id menu_gid);
static void mmi_callset_create_auto_redial_mode(mmi_id parent_gid);
static void mmi_callset_entry_auto_redial_mode(mmi_id menu_gid);
static void mmi_callset_sel_auto_redial_mode(void *info);
#endif /* __MMI_CALLSET_AUTO_REDIAL__ */
// call time display
#ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
static void mmi_callset_hilite_ctd(mmi_id menu_gid);
static void mmi_callset_create_ctd_mode(mmi_id parent_gid);
static void mmi_callset_entry_ctd_mode(mmi_id menu_gid);
static void mmi_callset_sel_ctd_mode(void *info);
#endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */
// call time reminder
#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
static mmi_ret mmi_callset_proc_ctr(mmi_event_struct *evt);
static mmi_ret mmi_callset_proc_ctr_time(mmi_event_struct *evt);
static void mmi_callset_hilite_ctr(MMI_ID menu_gid);
static void mmi_callset_create_ctr_mode(void);
static void mmi_callset_entry_ctr_mode(MMI_ID menu_gid);
static void mmi_callset_entry_ctr_time(mmi_scrn_essential_struct *data);
static void mmi_callset_sel_ctr_mode(void *info);
static void mmi_callset_sel_ctr_edit_done(void);
#endif /* __MMI_CALLSET_CALLTIME_REMINDER__ */
// answer mode
static void mmi_callset_create_ans_mode_opt(MMI_ID parent_gid);
static void mmi_callset_entry_ans_mode_opt(MMI_ID menu_gid);
static void mmi_callset_sel_ans_mode_opt(void *info);
// reject by SMS
#ifdef __MMI_UCM_REJECT_BY_SMS__
static void mmi_callset_hilite_rej_by_sms(mmi_id menu_gid);
static void mmi_callset_create_rej_by_sms_mode(mmi_id parent_gid);
static void mmi_callset_entry_rej_by_sms_mode(mmi_id menu_gid);
static void mmi_callset_sel_rej_by_sms_mode(void *info);
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
// Connect Notice
#ifdef __MMI_CONNECT_NOTICE__
static void mmi_callset_hilite_connect_notice(mmi_id menu_gid);
static void mmi_callset_create_connect_notice_mode(mmi_id parent_gid);
static void mmi_callset_entry_connect_notice_mode(mmi_id menu_gid);
static void mmi_callset_sel_connect_notice_mode(void *info);
#endif /* __MMI_CONNECT_NOTICE__ */
// Line Switch
#ifdef __MMI_CALLSET_LINE_SWITCHING__
//static MMI_RET mmi_callset_hdlr_lsw_ind(mmi_event_struct *info);
static mmi_ret mmi_callset_sel_lsw_mode_cb(mmi_event_struct *info);
static void mmi_callset_hide_lsw(mmi_id menu_gid);
static void mmi_callset_hilite_lsw(mmi_id menu_gid);
static void mmi_callset_create_lsw_mode(mmi_id parent_gid);
static void mmi_callset_entry_lsw_mode(mmi_id menu_gid);
static void mmi_callset_sel_lsw_mode(void *info);
#endif /*__MMI_CALLSET_LINE_SWITCHING__*/
// IP Number
#ifdef __IP_NUMBER__
static mmi_ret mmi_callset_proc_ip_num_list(mmi_event_struct *evt);
static void mmi_callset_hilite_ip_number_list(S32 index);
static void mmi_callset_create_ip_number_list_opt(void);
static void mmi_callset_first_entry_ip_number_list(void);
static void mmi_callset_entry_ip_number_list(mmi_scrn_essential_struct *data);
static void mmi_callset_entry_ip_number_list_opt(mmi_id menu_gid);
static void mmi_callset_sel_ip_number_list_opt(void *info);
static void mmi_callset_entry_ip_number_list_sub_opt(MMI_ID menu_gid);
static void mmi_callset_sel_ip_number_list_sub_opt(void *info);
static void mmi_callset_entry_ip_number_list_edit(void);
static void mmi_callset_sel_ip_number_list_edit_done(mmi_id gid);
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static MMI_BOOL mmi_callset_get_only_inserted_sim(mmi_sim_enum *sim);
static void mmi_callset_set_ip_item_string(mmi_id owner_gid);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
#endif /* __IP_NUMBER__ */
// Black list
#ifdef __MMI_CM_BLACK_LIST__
static void mmi_callset_hilite_bl_from_list(mmi_id menu_gid);
static void mmi_callset_create_bl_from_list_mode(mmi_id parent_gid);
static void mmi_callset_entry_bl_from_list_mode(mmi_id menu_gid);
static void mmi_callset_sel_bl_from_list_mode(void *info);
#ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
static void mmi_callset_hilite_bl_rej_unknown_num(mmi_id menu_gid);
static void mmi_callset_create_bl_rej_unknown_num_mode(mmi_id parent_gid);
static void mmi_callset_entry_bl_rej_unknown_num_mode(mmi_id menu_gid);
static void mmi_callset_sel_bl_rej_unknown_num_mode(void *info);
#endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
static mmi_ret mmi_callset_proc_bl(mmi_event_struct *evt);
static void mmi_callset_entry_bl_num(void);
static void mmi_callset_hilite_bl_num(S32 index);
static void mmi_callset_entry_bl_num_edit(void);
static void mmi_callset_sel_bl_num_edit_done(mmi_id gid);
#endif /* __MMI_CM_BLACK_LIST__ */
// white list
#ifdef __MMI_CM_WHITE_LIST__
static mmi_ret mmi_callset_proc_wl(mmi_event_struct *evt);
static void mmi_callset_hilite_wl_from_list(mmi_id menu_gid);
static void mmi_callset_create_wl_from_list_mode(mmi_id parent_gid);
static void mmi_callset_entry_wl_from_list_mode(mmi_id menu_gid);
static void mmi_callset_sel_wl_from_list_mode(void *info);
static void mmi_callset_entry_wl_num(void);
static void mmi_callset_hilite_wl_num(S32 index);
static void mmi_callset_entry_wl_num_edit(void);
static void mmi_callset_sel_wl_num_edit_done(mmi_id gid);
static void mmi_callset_wl_passwd_verify_suc(void);
#endif /* __MMI_CM_WHITE_LIST__ */
// auto quick end
#ifdef __MMI_CH_QUICK_END__
static void mmi_callset_hilite_auto_quick_end(mmi_id menu_gid);
static void mmi_callset_entry_auto_quick_end(void);
static void mmi_callset_sel_quick_end_edit_done(mmi_id gid);
#endif /* __MMI_CH_QUICK_END__ */
// ctm
#ifdef __CTM_SUPPORT__
static void mmi_callset_hilite_ctm_mode(MMI_ID menu_gid);
static void mmi_callset_create_ctm_mode_opt(MMI_ID parent_gid);
static void mmi_callset_entry_ctm_mode_opt(MMI_ID menu_gid);
static void mmi_callset_sel_ctm_mode_opt(void *info);
static void mmi_callset_create_ctm_setting_opt(MMI_ID parent_gid);
static void mmi_callset_entry_ctm_setting_opt(MMI_ID menu_gid);
static void mmi_callset_sel_ctm_setting_opt(void *info);
static mmi_ret mmi_callset_hdlr_ctm_setting_changed(mmi_event_struct *evt);
#endif /* __CTM_SUPPORT__ */
// delay dial
#if 0
#ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP01_FWPBW__ */
#endif
// Magic voice
#ifdef __VOICE_CHANGER_SUPPORT__
static mmi_ret mmi_callset_proc_magic_voice(mmi_event_struct *evt);
static void mmi_callset_hilite_magic_voice(MMI_ID menu_gid);
static void mmi_callset_entry_magic_voice_mode(MMI_ID menu_gid);
static void mmi_callset_sel_magic_voice_mode(void *info);
#endif /* __VOICE_CHANGER_SUPPORT__ */


/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
#ifdef __MMI_AP_DCM_CALLSET__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

static const mmi_callst_ss_operation_data_struct g_callset_ss_op_data[] = {
    {SRV_SS_ACT_CALL_WAIT, 0, SRV_SS_ALL_CALL, MENU_ID_CALLSET_CALL_WAIT},
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFALL, SRV_SS_ALL_CALL, MENU_ID_CALLSET_CALL_FWD},
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFU, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CFU_VOICE},
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFNRC, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CFNRC_VOICE},
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFNRY, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CFNRY_VOICE},
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFB, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CFB_VOICE},
#ifdef __MMI_VIDEO_TELEPHONY__
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFU, MENU_ID_CALLSET_CFU_VIDEO, SRV_SS_VIDEO_CALL},
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFNRC, MENU_ID_CALLSET_CFNRC_VIDEO, SRV_SS_VIDEO_CALL},
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFNRY, MENU_ID_CALLSET_CFNRY_VIDEO, SRV_SS_VIDEO_CALL},
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFB, MENU_ID_CALLSET_CFB_VIDEO, SRV_SS_VIDEO_CALL},
#endif /* __MMI_VIDEO_TELEPHONY__ */
    {SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFB, SRV_SS_DATA_CALL, MENU_ID_CALLSET_CFU_DATA},
#ifdef __MMI_CALLSET_CALL_BARRING__
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAC, SRV_SS_ALL_CALL, MENU_ID_CALLSET_CALL_BAR},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BOC, SRV_SS_ALL_CALL, MENU_ID_CALLSET_CB_OUT},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BIC, SRV_SS_ALL_CALL, MENU_ID_CALLSET_CB_IN},
#endif
};
#ifdef __MMI_CALLSET_CALL_BARRING__
static const mmi_callst_ss_operation_data_struct g_callset_cb_data[] = {
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAOC, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CB_OUT_BAOC_VOICE},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BOIC, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CB_OUT_BOIC_VOICE},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BOICEXHC, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CB_OUT_BOICEXHC_VOICE},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAIC, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CB_IN_BAIC_VOICE},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAICROAM, SRV_SS_VOICE_CALL, MENU_ID_CALLSET_CB_IN_BAICROAM_VOICE},
#ifdef __MMI_VIDEO_TELEPHONY__
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAOC, SRV_SS_VIDEO_CALL, MENU_ID_CALLSET_CB_OUT_BAOC_VIDEO},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BOIC, SRV_SS_VIDEO_CALL, MENU_ID_CALLSET_CB_OUT_BOIC_VIDEO},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BOICEXHC, SRV_SS_VIDEO_CALL, MENU_ID_CALLSET_CB_OUT_BOICEXHC_VIDEO},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAIC, SRV_SS_VIDEO_CALL, MENU_ID_CALLSET_CB_IN_BAIC_VIDEO},
    {SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAICROAM, SRV_SS_VIDEO_CALL, MENU_ID_CALLSET_CB_IN_BAICROAM_VIDEO},
#endif /* __MMI_VIDEO_TELEPHONY__ */
};
#endif

static const U16 g_cf_num_edit_menu[] = {MENU_ID_CALLSET_CF_NUM_EDIT_FROM_PHB};
static const U8 g_cf_num_edit_menu_count = 1;

#ifdef __MMI_AP_DCM_CALLSET__
#pragma arm section rodata , code
#endif


/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hdlr_sim_availability_changed
 * DESCRIPTION
 *  handler for sim availability changed event
 * PARAMETERS
 *  info    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_callset_hdlr_sim_availability_changed(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *evt = (srv_sim_ctrl_availability_changed_evt_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->is_available_before == evt->is_available_now)
    {
        return MMI_RET_OK;
    }

    if (!evt->is_available_now)
    {
        mmi_callset_evt_post_close_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_CALLSET_POST_CLOSE);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_callset_post_event_hdlr, NULL);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_post_event_hdlr
 * DESCRIPTION
 *  Post close event handler
 * PARAMETERS
 *  evt    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_callset_post_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (EVT_ID_CALLSET_POST_CLOSE == evt->evt_id)
    {
        mmi_frm_group_close(GRP_ID_CALLSET_COMMON);
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hdlr_lsw_ind
 * DESCRIPTION
 *  handler for line switch indication
 * PARAMETERS
 *  info    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_callset_hdlr_lsw_ind(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_util_lsw_update_status_icon(
        ((srv_callset_line_switched_evt_struct*)info)->sim, 
        ((srv_callset_line_switched_evt_struct*)info)->active_line);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hdlr_cfu_status_ind
 * DESCRIPTION
 *  handler for cfu status indication
 * PARAMETERS
 *  info    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_callset_hdlr_cfu_status_ind(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_util_cf_update_status_icon(
        ((srv_callset_cfu_status_evt_struct*)info)->sim, 
        ((srv_callset_cfu_status_evt_struct*)info)->status);

    return MMI_RET_OK;
}


#ifdef __MMI_AP_DCM_CALLSET__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hide_ss_operation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_gid    [IN]    menu id
 *  num    [IN]    menu item number
 *  data_p    [IN]    menu item info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hide_ss_operation(MMI_ID menu_gid, U8 num, mmi_callst_ss_operation_data_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL pre_check;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pre_check = srv_callset_is_available(mmi_callset_sim_p->sim);

    /* callset is vailable, continue to check the sub-menus */
    for (i = 0; i < num; i++)
    {
    #if defined(__MMI_VIDEO_TELEPHONY__) && !defined(__MMI_3G_SWITCH__)
        if (SRV_SS_VIDEO_CALL == data_p[i].call_type &&
            data_p->sim != MMI_SIM1)
        {
            cui_menu_set_item_hidden(menu_gid, data_p[i].menu_id, MMI_TRUE);
        }
        else
    #endif /* defined(__MMI_VIDEO_TELEPHONY__) && !defined(__MMI_3G_SWITCH__) */
        {
            if (pre_check &&
                srv_ss_check_capability(mmi_callset_sim_p->sim, data_p[i].op, (U8)data_p[i].type, data_p[i].call_type))
            {
                cui_menu_set_item_hidden(menu_gid, data_p[i].menu_id, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, data_p[i].menu_id, MMI_TRUE);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_display_error_popup_by_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result    [IN]    error result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_display_error_popup_by_result(srv_ss_result_enum result)
{
    if (result != SRV_SS_RESULT_OK)
    {
        mmi_popup_display_simple_ext(
            srv_ss_get_result_string(result),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_display_popup_by_cause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result    [IN]    error result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_display_popup_by_cause(srv_callset_result_enum cause)
{
    if (cause == SRV_CALLSET_RESULT_OK)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS,
            GRP_ID_ROOT,
            NULL);
    }
    else /* fail */
    {
        mmi_popup_display_simple_ext(
            srv_callset_get_result_string_id(cause),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_display_error_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result    [IN]    error string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_display_error_popup(MMI_STR_ID title)
{
    mmi_popup_display_simple_ext(
        title,
        MMI_EVENT_FAILURE,
        GRP_ID_ROOT,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_common_create_cui
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid    [IN]    parent id
 *  menu_id    [IN]    menu id
 *  title_id    [IN]    title icon id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_common_create_cui(MMI_ID parent_gid, mmi_menu_id menu_id, mmi_menu_id title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    menu_gid = cui_menu_create(
                parent_gid,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                menu_id,
                MMI_FALSE,
                NULL);

    cui_menu_set_default_title_image_by_id(menu_gid, GetRootTitleIcon(title_id));

    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_common_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  root_menu_id    [IN]    root menu id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_common_launch(mmi_menu_id root_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 itemId = root_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_CALLSET_COMMON))
    {
        mmi_frm_group_close(GRP_ID_CALLSET_COMMON);
    }

    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_CALLSET_COMMON, mmi_callset_proc_common, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (root_menu_id != MENU_ID_CALLSET_CALL_CENTER)
    {
        itemId = MENU_ID_CALLSET_CALL_SETTING;
    }

    mmi_callset_common_create_cui(GRP_ID_CALLSET_COMMON, root_menu_id, itemId);
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim_common_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id    [IN]    sim id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_call_setting_sim_common_launch(mmi_sim_enum sim_id)
{
    if (!srv_callset_is_available(sim_id))
    {
        mmi_callset_display_error_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);

    #if defined (__MMI_AP_DCM_CALLSET__)
        if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
            mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
    #endif
    
        return;
    }

    mmi_callset_common_launch((mmi_menu_id)(MENU_ID_CALLSET_CALL_SETTING_SIM1 + mmi_frm_sim_to_index(sim_id)));
}
#endif /* MMI_MAX_SIM_NUM >= 2 */


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_common
 * DESCRIPTION
 *  process for call setting common screen group (GRP_ID_CALLSET_COMMON)
 * PARAMETERS
 *  index       [IN]     highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_callset_proc_common(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;
    U32 i;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_callset_evt_update_struct *update_evt = (mmi_callset_evt_update_struct*)evt;
#if defined(__MMI_CALLSET_CUG__) || defined(__IP_NUMBER__) || defined(__MMI_CM_BLACK_LIST__) || defined(__MMI_CM_BLACK_LIST__)
    cui_fseditor_evt_struct *fsedit_evt = (cui_fseditor_evt_struct*)evt;
#endif /* (__MMI_CALLSET_CUG__) || (__IP_NUMBER__) || (__MMI_CM_BLACK_LIST__) || (__MMI_CM_BLACK_LIST__) */
#ifdef __MMI_CH_QUICK_END__
    mmi_group_event_struct *inline_evt = (mmi_group_event_struct*)evt;
#endif /* __MMI_CH_QUICK_END__ */
#ifdef __MMI_CM_WHITE_LIST__
    cui_verify_result_evt_struct *verify_evt = (cui_verify_result_evt_struct*)evt;
#endif /* __MMI_CM_WHITE_LIST__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* menu event */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            switch(menu_evt->parent_menu_id)
            {
                case MENU_ID_CALLSET_CALL_CENTER:
                    mmi_callset_entry_call_center(menu_evt->sender_id);
                    break;

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_CALLSET_CALL_SETTING_SIM1:
                case MENU_ID_CALLSET_CALL_SETTING_SIM2:
            #if (MMI_MAX_SIM_NUM>=3)
                case MENU_ID_CALLSET_CALL_SETTING_SIM3:
            #if (MMI_MAX_SIM_NUM>=4)
                case MENU_ID_CALLSET_CALL_SETTING_SIM4:
            #endif /* MMI_MAX_SIM_NUM>=4*/
            #endif /* MMI_MAX_SIM_NUM>=3*/
                {
                    sim_id = (mmi_sim_enum)(1 << (menu_evt->parent_menu_id - MENU_ID_CALLSET_CALL_SETTING_SIM1));
                    mmi_callset_sim_cntx_reset_ptr();
                    mmi_callset_sim_cntx_set_ptr(sim_id);
                    mmi_callset_p->target_sim = sim_id;
                    mmi_callset_entry_call_setting(menu_evt->sender_id);
                    break;
                }
        #endif /*  (MMI_MAX_SIM_NUM >= 2) */

                case MENU_ID_CALLSET_CALL_SETTING:
                {
            #if (MMI_MAX_SIM_NUM >= 2)   /*amit plz add here for sim3 and sim4*/
                    for (i=0; i<MMI_MAX_SIM_NUM; i++)
                    {
                        sim_id = (mmi_sim_enum)(1 << i);
                        
                        if (!srv_callset_is_available(sim_id))
                        {
                            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_CALLSET_CALL_SETTING_SIM1+i, MMI_TRUE);
                        }
                        else
                        {
                            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_CALLSET_CALL_SETTING_SIM1+i, MMI_FALSE);
                        }
                    }

                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    mmi_callset_set_sim_item_string(menu_evt->sender_id);
                #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            #else /*  (MMI_MAX_SIM_NUM >= 2) */
                    mmi_callset_sim_cntx_reset_ptr();
                    mmi_callset_sim_cntx_set_ptr(MMI_SIM1);
                    mmi_callset_p->target_sim = MMI_SIM1;
                    mmi_callset_entry_call_setting(menu_evt->sender_id);
            #endif /*  (MMI_MAX_SIM_NUM >= 2) */
                    break;
                }

                case MENU_ID_CALLSET_MORE:
                {
                    mmi_callset_sim_cntx_reset_ptr();
                    mmi_callset_p->target_sim = MMI_SIM_NONE;
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    for (i=MMI_CALLSET_OP_START+1; i<MMI_CALLSET_OP_TOTAL; i++)
                    {
                        mmi_callset_hilite_common(menu_evt->sender_id, (mmi_callset_op_enum)i);
                    }
                    break;
                }

            #ifdef __MMI_CALLSET_CALLER_ID__
                case MENU_ID_CALLSET_CID_MODE:
                {
                    mmi_callset_entry_cid_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
            #endif /* __MMI_CALLSET_CALLER_ID__ */
 
                case MENU_ID_CALLSET_CALL_WAIT_OPT:
                case MENU_ID_CALLSET_CALL_FWD:
	#ifdef __MMI_CALLSET_CALL_BARRING__
                case MENU_ID_CALLSET_CALL_BAR:
	#endif /* __MMI_CALLSET_CALL_BARRING__*/
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    break;
                }
 	#ifdef __MMI_CALLSET_LINE_SWITCHING__
                case MENU_ID_CALLSET_LINE_SWITCH_MODE:
                {
                    mmi_callset_entry_lsw_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
            #endif /* __MMI_CALLSET_LINE_SWITCHING__*/	  
            #ifdef __MMI_CALLSET_AUTO_REDIAL__
                case MENU_ID_CALLSET_AUTOREDIAL_MODE:
                {
                    mmi_callset_entry_auto_redial_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
            #endif /* __MMI_CALLSET_AUTO_REDIAL__ */
            
            #ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
                case MENU_ID_CALLSET_CTD_MODE:
                {
                    mmi_callset_entry_ctd_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
            #endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */

            #ifdef __MMI_UCM_REJECT_BY_SMS__
                case MENU_ID_CALLSET_REJ_BY_SMS_MODE:
                {
                    mmi_callset_entry_rej_by_sms_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
            #endif /* __MMI_UCM_REJECT_BY_SMS__ */

            #ifdef __MMI_CONNECT_NOTICE__
                case MENU_ID_CALLSET_CONNECT_NOTICE_MODE:
                {
                    mmi_callset_entry_connect_notice_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
            #endif /* __MMI_CONNECT_NOTICE__ */

            #ifdef __MMI_CM_BLACK_LIST__
                case MENU_ID_CALLSET_BLACKLIST:
                {
                    mmi_callset_sim_cntx_reset_ptr();
                    mmi_callset_p->target_sim = MMI_SIM_NONE;
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    mmi_callset_hilite_common(menu_evt->sender_id, MMI_CALLSET_OP_BL_FROM_LIST);
                #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
                    mmi_callset_hilite_common(menu_evt->sender_id, MMI_CALLSET_OP_BL_REJ_UNKNOWN_NUM);
                #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
                #ifdef __MMI_CM_BLACK_LIST_EXT__
                    mmi_callset_p->bl_call_type = SRV_CALLSET_VOICE_CALL;
                #endif /* __MMI_CM_BLACK_LIST_EXT__ */
                    break;
                }

                case MENU_ID_CALLSET_BL_FROM_LIST_MODE:
                {
                    mmi_callset_entry_bl_from_list_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }

            #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
                case MENU_ID_CALLSET_BL_REJ_UNKNOWN_NUM_MODE:
                {
                    mmi_callset_entry_bl_rej_unknown_num_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
            #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */

            #if (defined(__MMI_CM_BLACK_LIST_EXT__) && defined (__MMI_VIDEO_TELEPHONY__))
                case MENU_ID_CALLSET_BLACKLIST_VOICE:
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    mmi_callset_hilite_common(menu_evt->sender_id, MMI_CALLSET_OP_BL_FROM_LIST);
                #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
                    mmi_callset_hilite_common(menu_evt->sender_id, MMI_CALLSET_OP_BL_REJ_UNKNOWN_NUM);
                #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
                    mmi_callset_p->bl_call_type = SRV_CALLSET_VOICE_CALL;
                    break;
                }

                case MENU_ID_CALLSET_BLACKLIST_VIDEO:
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    mmi_callset_hilite_common(menu_evt->sender_id, MMI_CALLSET_OP_BL_FROM_LIST);
                #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
                    mmi_callset_hilite_common(menu_evt->sender_id, MMI_CALLSET_OP_BL_REJ_UNKNOWN_NUM);
                #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
                    mmi_callset_p->bl_call_type = SRV_CALLSET_VIDEO_CALL;
                    break;
                }
            #endif /* (defined(__MMI_CM_BLACK_LIST_EXT__) && defined (__MMI_VIDEO_TELEPHONY__)) */
            #endif /* __MMI_CM_BLACK_LIST__ */

            #ifdef __MMI_CM_WHITE_LIST__
                case MENU_ID_CALLSET_WL_FROM_LIST_MODE:
                {
                    mmi_callset_entry_wl_from_list_mode(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
                case MENU_ID_CALLSET_WHITELIST:
            #if (defined(__MMI_CM_WHITE_LIST_EXT__) && defined (__MMI_VIDEO_TELEPHONY__))
                case MENU_ID_CALLSET_WHITELIST_VOICE:
                case MENU_ID_CALLSET_WHITELIST_VIDEO:
            #endif /* (defined(__MMI_CM_WHITE_LIST_EXT__) && defined (__MMI_VIDEO_TELEPHONY__)) */
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    mmi_callset_hilite_common(menu_evt->sender_id, MMI_CALLSET_OP_WL_FROM_LIST);
                    break;
                }
            #endif /* __MMI_CM_WHITE_LIST__ */

        #if 0
        #if (defined(__CTM_SUPPORT__) && defined (__OP01_FWPBW__))
            #ifdef __CTM_SUPPORT__
/* under construction !*/
/* under construction !*/
            #endif /* __CTM_SUPPORT__ */
            #ifdef __OP01_FWPBW__
/* under construction !*/
            #endif /* __OP01_FWPBW__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __CTM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __CTM_SUPPORT__ */
        #endif /* ((__CTM_SUPPORT__) && (__OP01_FWPBW__)) */
        #else
          #ifdef __CTM_SUPPORT__
                case MENU_ID_CALLSET_CTM_MODE_OPT:
                case MENU_ID_CALLSET_CTM_SET_OPT:
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    break;
                }
                case MENU_ID_CALLSET_CTM:
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    mmi_callset_hilite_common(menu_evt->sender_id, MMI_CALLSET_OP_CTM);
                    break;
                }
          #endif /* __CTM_SUPPORT__ */
        #endif

        #ifdef __IP_NUMBER__
                case MENU_ID_CALLSET_IP_NUMBER_OPT:
                {
                    mmi_callset_entry_ip_number_list_opt(menu_evt->sender_id);
                    break;
                }
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_CALLSET_IP_ACTIVATE:
                case MENU_ID_CALLSET_IP_DEACTIVATE:
                {
                    mmi_callset_entry_ip_number_list_sub_opt(menu_evt->sender_id);
                    break;
                }
            #endif
        #endif /* __IP_NUMBER__ */

            #ifdef __MMI_CALLSET_CUG__
                case MENU_ID_CALLSET_CUG_OPT:
                {
                    mmi_callset_entry_cug_opt(menu_evt->sender_id);
                    break;
                }
            #endif /* __MMI_CALLSET_CUG__ */

                case MENU_ID_CALLSET_ANS_MODE_OPT:
                {
                    mmi_callset_entry_ans_mode_opt(menu_evt->sender_id);
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_CHECK_BOX_LIST);
                    break;
                }

            #ifdef __VOICE_CHANGER_SUPPORT__
                case MENU_ID_CALLSET_MAGIC_VOICE_OPTION:
                {
                    mmi_callset_hilite_magic_voice(menu_evt->sender_id);
                    break;
                }
            #endif /* __VOICE_CHANGER_SUPPORT__ */
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
            #if (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)) && defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_MRE_MAIN_MENU__)
                case MENU_ID_CALLSET_PHONEBOOK:
                {
                    mmi_phb_launch();
                    break;
                }
            #endif

                case MENU_ID_CALLSET_CALL_LOG:
                {
                    mmi_clog_launch();        
                    break;
                }

        #if 0
        #ifdef __MMI_VOIP__
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
            #endif /* __MMI_VOIP__ */
            #endif

            #ifdef __MMI_VIDEO_TELEPHONY__
                case MENU_ID_UCM_VT_MAIN:
                {
                    mmi_ucm_vt_app_launch();
                    break;
                }
            #endif /* __MMI_VIDEO_TELEPHONY__ */

            #ifdef __MMI_CALLSET_CALLER_ID__
                case MENU_ID_CALLSET_CID:
                {
                    mmi_callset_create_cid_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }
            #endif /* __MMI_CALLSET_CALLER_ID__ */

                case MENU_ID_CALLSET_CALL_WAIT:
                {
                    mmi_callset_create_cw_opt(GRP_ID_CALLSET_COMMON);
                    break;
                }

                case MENU_ID_CALLSET_CFU_VOICE:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFU_VOICE_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CFNRC_VOICE:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFNRC_VOICE_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CFNRY_VOICE:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFNRY_VOICE_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CFB_VOICE:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFB_VOICE_OPT);
                    break;
                }

            #ifdef __MMI_VIDEO_TELEPHONY__
                case MENU_ID_CALLSET_CFU_VIDEO:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFU_VIDEO_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CFNRC_VIDEO:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFNRC_VIDEO_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CFNRY_VIDEO:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFNRY_VIDEO_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CFB_VIDEO:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFB_VIDEO_OPT);
                    break;
                }
            #endif /* __MMI_VIDEO_TELEPHONY__ */

                case MENU_ID_CALLSET_CFU_DATA:
                {
                    mmi_callset_create_cf_opt(MENU_ID_CALLSET_CFU_DATA_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CALLFWD_CANCELALL:
                {
                    mmi_callset_sel_cf_cancelall(menu_evt);
                    break;
                }

            #ifdef __MMI_CALLSET_CALL_BARRING__
                case MENU_ID_CALLSET_CB_OUT:
                {
                    mmi_callset_create_cb_opt(MENU_ID_CALLSET_CB_OUT_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CB_IN:
                {
                    mmi_callset_create_cb_opt(MENU_ID_CALLSET_CB_IN_OPT);
                    break;
                }

                case MENU_ID_CALLSET_CB_CANCELALL:
                {
                    mmi_callset_sel_cb_cancelall(menu_evt);
                    break;
                }

                case MENU_ID_CALLSET_CB_CHANGEPASS:
                {
                    mmi_callset_sel_cb_change_passwd(menu_evt);
                    break;
                }
              #endif /* __MMI_CALLSET_CALL_BARRING__*/

            #ifdef __MMI_CALLSET_CUG__
                case MENU_ID_CALLSET_CUG:
                {
                    mmi_callset_entry_cug();
                    break;
                }
            #endif /* __MMI_CALLSET_CUG__ */

            #ifdef __MMI_BG_SOUND_EFFECT__
                case MENU_ID_CALLSET_BGS:
                {
                    mmi_bgsnd_pre_entry_call_setup();
                    break;
                }
            #endif /* __MMI_BG_SOUND_EFFECT__ */

           #ifdef __MMI_CALLSET_AUTO_REDIAL__
                case MENU_ID_CALLSET_AUTOREDIAL:
                {
                    /* select auto redial leaf */
                    mmi_callset_create_auto_redial_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }
            #endif /* __MMI_CALLSET_AUTO_REDIAL__ */

            #ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
                case MENU_ID_CALLSET_CTD:
                {
                    /* select ctd leaf */
                    mmi_callset_create_ctd_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }
            #endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */

		#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
                case MENU_ID_CALLSET_CTR:
                {
                    mmi_callset_create_ctr_mode();
                    break;
                }
	       #endif /*__MMI_CALLSET_CALLTIME_REMINDER__*/

                case MENU_ID_CALLSET_ANS_MODE:
                {
                    mmi_callset_create_ans_mode_opt(GRP_ID_CALLSET_COMMON);
                    break;
                }

            #ifdef __MMI_UCM_REJECT_BY_SMS__
                case MENU_ID_CALLSET_REJ_BY_SMS:
                {
                    /* select reject by sms leaf */
                    mmi_callset_create_rej_by_sms_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }
            #endif /* __MMI_UCM_REJECT_BY_SMS__ */

            #ifdef __MMI_CONNECT_NOTICE__
                case MENU_ID_CALLSET_CONNECT_NOTICE:
                {
                    mmi_callset_create_connect_notice_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }
            #endif /* __MMI_CONNECT_NOTICE__ */

	  #ifdef __MMI_CALLSET_LINE_SWITCHING__
                case MENU_ID_CALLSET_LINE_SWITCH:
                {
                    /* select auto redial leaf */
                    mmi_callset_create_lsw_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }
 	#endif /*__MMI_CALLSET_LINE_SWITCHING__*/

            #ifdef __IP_NUMBER__
                case MENU_ID_CALLSET_IP_NUMBER:
                {
                    mmi_callset_first_entry_ip_number_list();
                    break;
                }
            #endif /* __IP_NUMBER__ */

            #ifdef __MMI_CM_BLACK_LIST__
                case MENU_ID_CALLSET_BL_FROM_LIST:
                {
                    mmi_callset_create_bl_from_list_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }

              #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
                case MENU_ID_CALLSET_BL_REJ_UNKNOWN_NUM:
                {
                    mmi_callset_create_bl_rej_unknown_num_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }
              #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */

                case MENU_ID_CALLSET_BL_NUM:
                {
                    mmi_callset_entry_bl_num();
                    break;
                }
            #endif /* __MMI_CM_BLACK_LIST__ */

            #ifdef __MMI_CM_WHITE_LIST__
                case MENU_ID_CALLSET_WL_FROM_LIST:
                {
                    mmi_callset_create_wl_from_list_mode(GRP_ID_CALLSET_COMMON);
                    break;
                }

                case MENU_ID_CALLSET_WL_NUM:
                {
                    mmi_callset_entry_wl_num();
                    break;
                }
            #endif /* __MMI_CM_WHITE_LIST__ */

            #ifdef __MMI_CH_QUICK_END__
                case MENU_ID_CALLSET_QUICK_END:
                {
                    mmi_callset_entry_auto_quick_end();
                    break;
                }
            #endif /* __MMI_CH_QUICK_END__ */

            #ifdef __CTM_SUPPORT__
                case MENU_ID_CALLSET_CTM_MODE:
                {
                    mmi_callset_create_ctm_mode_opt(GRP_ID_CALLSET_COMMON);
                    break;
                }

                case MENU_ID_CALLSET_CTM_SETTING:
                {
                    mmi_callset_create_ctm_setting_opt(GRP_ID_CALLSET_COMMON);
                    break;
                }
            #endif /* __CTM_SUPPORT__ */

            #if 0
            #ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __OP01_FWPBW__ */
            #endif

            #ifdef __VOICE_CHANGER_SUPPORT__
                case MENU_ID_CALLSET_MAGIC_VOICE:
                {
                    mmi_callset_magic_voice_launch();
                    break;
                }
            #endif /* __VOICE_CHANGER_SUPPORT__ */

                default:
                {
                    switch(menu_evt->parent_menu_id)
                    {
                    #ifdef __MMI_CALLSET_CALLER_ID__
                        case MENU_ID_CALLSET_CID_MODE:
                        {
                            mmi_callset_sel_cid_mode(menu_evt);
                            break;
                        }
                    #endif /* __MMI_CALLSET_CALLER_ID__ */

                        case MENU_ID_CALLSET_CALL_WAIT_OPT:
                        {
                            mmi_callset_sel_cw_opt(menu_evt);
                            break;
                        }

                    #ifdef __MMI_CALLSET_CUG__	
                        case MENU_ID_CALLSET_CUG_OPT:
                        {
                            mmi_callset_sel_cug_opt(menu_evt);
                            break;
                        }
                    #endif /* __MMI_CALLSET_CUG__ */

                    #ifdef __MMI_CALLSET_AUTO_REDIAL__
                        case MENU_ID_CALLSET_AUTOREDIAL_MODE:
                        {
                            mmi_callset_sel_auto_redial_mode(menu_evt);
                            break;
                        }
                   #endif /* __MMI_CALLSET_AUTO_REDIAL__ */

                    #ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
                        case MENU_ID_CALLSET_CTD_MODE:
                        {
                            mmi_callset_sel_ctd_mode(menu_evt);
                            break;
                        }
                    #endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */

                        case MENU_ID_CALLSET_ANS_MODE_OPT:
                        {
                            mmi_callset_sel_ans_mode_opt(menu_evt);
                            break;
                        }

                    #ifdef __MMI_UCM_REJECT_BY_SMS__
                        case MENU_ID_CALLSET_REJ_BY_SMS_MODE:
                        {
                            mmi_callset_sel_rej_by_sms_mode(menu_evt);
                            break;
                        }
                    #endif /* __MMI_UCM_REJECT_BY_SMS__ */

                    #ifdef __MMI_CONNECT_NOTICE__
                        case MENU_ID_CALLSET_CONNECT_NOTICE_MODE:
                        {
                            mmi_callset_sel_connect_notice_mode(menu_evt);
                            break;
                        }
                    #endif /* __MMI_CONNECT_NOTICE__ */

		      #ifdef __MMI_CALLSET_LINE_SWITCHING__
                        case MENU_ID_CALLSET_LINE_SWITCH_MODE:
                        {
                            mmi_callset_sel_lsw_mode(menu_evt);
                            break;
                        }
			#endif /*__MMI_CALLSET_LINE_SWITCHING__*/

                    #ifdef __IP_NUMBER__
                        case MENU_ID_CALLSET_IP_NUMBER_OPT:
                        {
                            mmi_callset_sel_ip_number_list_opt(menu_evt);
                            break;
                        }

                      #if (MMI_MAX_SIM_NUM >= 2)
                        case MENU_ID_CALLSET_IP_ACTIVATE:
                        case MENU_ID_CALLSET_IP_DEACTIVATE:
                        {
                            mmi_callset_sel_ip_number_list_sub_opt(menu_evt);
                            break;
                        }
                      #endif
                    #endif /* __IP_NUMBER__ */

                    #ifdef __MMI_CM_BLACK_LIST__
                        case MENU_ID_CALLSET_BL_FROM_LIST_MODE:
                        {
                            mmi_callset_sel_bl_from_list_mode(menu_evt);
                            break;
                        }

                      #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
                        case MENU_ID_CALLSET_BL_REJ_UNKNOWN_NUM_MODE:
                        {
                            mmi_callset_sel_bl_rej_unknown_num_mode(menu_evt);
                            break;
                        }
                      #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
                    #endif /* __MMI_CM_BLACK_LIST__ */

                    #ifdef __MMI_CM_WHITE_LIST__
                        case MENU_ID_CALLSET_WL_FROM_LIST_MODE:
                        {
                            mmi_callset_sel_wl_from_list_mode(menu_evt);
                            break;
                        }
                    #endif /* __MMI_CM_WHITE_LIST__ */

                    #ifdef __CTM_SUPPORT__
                        case MENU_ID_CALLSET_CTM_MODE_OPT:
                        {
                            mmi_callset_sel_ctm_mode_opt(menu_evt);
                            break;
                        }

                        case MENU_ID_CALLSET_CTM_SET_OPT:
                        {
                            mmi_callset_sel_ctm_setting_opt(menu_evt);
                            break;
                        }
                    #endif /* __CTM_SUPPORT__ */

                    #if 0
                    #ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #endif /* __OP01_FWPBW__ */
                    #endif
                    }
                break;
                }				
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
            break;

        /* FS editor event */
    #ifdef __MMI_CALLSET_CUG__
        case EVT_ID_CUI_FSEDITOR_EMPTY:
            if (MMI_FALSE
                || (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2) || (mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && (fsedit_evt->sender_id == mmi_callset_sim_p->cug_name_edit_gid))
                || (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2) || (mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && (fsedit_evt->sender_id == mmi_callset_sim_p->cug_id_edit_gid))
                )
            {
//                mmi_callset_sel_edit_empty(fsedit_evt->sender_id);
                cui_fseditor_set_custom_options_menu(fsedit_evt->sender_id, MMI_TRUE, NULL, 0);
            }
            break;

        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
            if (MMI_FALSE
                || (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2) || (mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && (fsedit_evt->sender_id == mmi_callset_sim_p->cug_name_edit_gid))
                || (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2) || (mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && (fsedit_evt->sender_id == mmi_callset_sim_p->cug_id_edit_gid))
                )
            {
//                mmi_callset_sel_edit_not_empty(fsedit_evt->sender_id);
                cui_fseditor_set_custom_options_menu(fsedit_evt->sender_id, MMI_FALSE, NULL, 0);
            }
            break;
    #endif /* __MMI_CALLSET_CUG__ */

    #if defined(__MMI_CALLSET_CUG__) || defined(__IP_NUMBER__) || defined(__MMI_CM_BLACK_LIST__) || defined(__MMI_CM_WHITE_LIST__)
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            if (MMI_FALSE)
            {
            }
        #ifdef __MMI_CALLSET_CUG__
            else if (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2) || (mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && (fsedit_evt->sender_id == mmi_callset_sim_p->cug_name_edit_gid))
            {
                mmi_callset_sel_cug_name_edit_done(fsedit_evt->sender_id);
            }
            else if (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2) || (mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && (fsedit_evt->sender_id == mmi_callset_sim_p->cug_id_edit_gid))
            {
                mmi_callset_sel_cug_id_edit_done(fsedit_evt->sender_id);
            }
        #endif /* __MMI_CALLSET_CUG__ */
        #ifdef __IP_NUMBER__
            else if (fsedit_evt->sender_id == mmi_callset_p->ip_number_edit_gid)
            {
                mmi_callset_sel_ip_number_list_edit_done(fsedit_evt->sender_id);
            }
        #endif /* __IP_NUMBER__ */
        #ifdef __MMI_CM_BLACK_LIST__
            else if (fsedit_evt->sender_id == mmi_callset_p->blacklist_edit_gid)
            {
                mmi_callset_sel_bl_num_edit_done(fsedit_evt->sender_id);
            }
        #endif /* __MMI_CM_BLACK_LIST__ */
        #ifdef __MMI_CM_WHITE_LIST__
            else if (fsedit_evt->sender_id == mmi_callset_p->whitelist_edit_gid)
            {
                mmi_callset_sel_wl_num_edit_done(fsedit_evt->sender_id);
            }
        #endif /* __MMI_CM_WHITE_LIST__ */
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FSEDITOR_DEINIT:
            mmi_callset_close_fseditor(fsedit_evt->sender_id);
            break;
    #endif /* __MMI_CALLSET_CUG__ || __IP_NUMBER__ || __MMI_CM_BLACK_LIST__ || __MMI_CM_WHITE_LIST__ */

    #ifdef __MMI_CH_QUICK_END__
        /* inline editor event */
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            if (inline_evt->sender_id == mmi_callset_p->quick_end_edit_gid)
            {
                mmi_callset_sel_quick_end_edit_done(inline_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            if (inline_evt->sender_id == mmi_callset_p->quick_end_edit_gid)
            {
                cui_inline_close(inline_evt->sender_id);
                mmi_callset_p->quick_end_edit_gid = 0;
            }
            break;
        #endif /* __MMI_CH_QUICK_END__ */

    #ifdef __MMI_CM_WHITE_LIST__
        /* phone password verify event */
        case EVT_ID_CUI_VERIFY_RESULT:
            if (verify_evt->success)
            {
                mmi_callset_wl_passwd_verify_suc();
            }
        case EVT_ID_CUI_VERIFY_CANCEL:
            cui_verify_close(verify_evt->sender_id);
            break;
    #endif /* __MMI_CM_WHITE_LIST__ */

        /* internal event */
        case EVT_ID_CALLSET_UPDATE:
            mmi_callset_hilite_common(update_evt->sender_id, update_evt->op);
            break;

        case EVT_ID_GROUP_DEINIT:
            /* Work around: For issue not clear mmi_callset_sim_p->cug_name_edit_gid.
            There is a issue in FSeditor.
            When two FSeditor exist, only the first FSeditor can recieve EVT_ID_CUI_FSEDITOR_DEINIT */
            mmi_callset_reset_fseditor();

        #if defined (__MMI_AP_DCM_CALLSET__)
            if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
                mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
        #endif
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_cf
 * DESCRIPTION
 *  process for call setting common screen group (GRP_ID_CALLSET_CF)
 * PARAMETERS
 *  index       [IN]     highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_callset_proc_cf(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    cui_fseditor_evt_struct *fsedit_evt = (cui_fseditor_evt_struct*)evt;
    cui_fseditor_custom_menu_select_evt_struct *fsedit_custom_evt = (cui_fseditor_custom_menu_select_evt_struct*)evt; 
    cui_phb_select_contact_result_struct *phb_evt = (cui_phb_select_contact_result_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* menu event */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            switch (menu_evt->parent_menu_id)
            {
                case MENU_ID_CALLSET_CFU_VOICE_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFU, SRV_SS_VOICE_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CFNRC_VOICE_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFNRC, SRV_SS_VOICE_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CFNRY_VOICE_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFNRY, SRV_SS_VOICE_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CFB_VOICE_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFB, SRV_SS_VOICE_CALL);
                    break;
                }
            #ifdef __MMI_VIDEO_TELEPHONY__
                case MENU_ID_CALLSET_CFU_VIDEO_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFU, SRV_SS_VIDEO_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CFNRC_VIDEO_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFNRC, SRV_SS_VIDEO_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CFNRY_VIDEO_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFNRY, SRV_SS_VIDEO_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CFB_VIDEO_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFB, SRV_SS_VIDEO_CALL);
                    break;
                }
            #endif /* __MMI_VIDEO_TELEPHONY__ */
                case MENU_ID_CALLSET_CFU_DATA_OPT:
                {
                    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFU, SRV_SS_DATA_CALL);
                    break;
                }
                case MENU_ID_CALLSET_ACTIVATE_CF:
                {
                    mmi_callset_entry_cf_activate(menu_evt->sender_id);
                    break;
                }
                case MENU_ID_CALLSET_CFNRY_TIME_OPT:
                {
                    break;
                }
                default:
                    return MMI_RET_OK;
            }

            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        }

//        case EVT_ID_CUI_MENU_ITEM_HILITE:
//            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->parent_menu_id == MENU_ID_CALLSET_ACTIVATE_CF)
            {
                mmi_callset_sel_cf_activate(menu_evt);
            }
            else if (menu_evt->parent_menu_id == MENU_ID_CALLSET_CFNRY_TIME_OPT)
            {
                mmi_callset_sel_cfnry_time_opt(menu_evt);
            }
            else if ((menu_evt->highlighted_menu_id == MENU_ID_CALLSET_DEACTIVATE) ||
                        (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_QUERY))
            {
                mmi_callset_sel_cf_opt(menu_evt);
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
            break;

        /* FS editor event, CF number editor */
        case EVT_ID_CUI_FSEDITOR_EMPTY:
//            mmi_callset_sel_cf_num_edit_empty(fsedit_evt->sender_id);
            cui_fseditor_set_custom_options_menu(fsedit_evt->sender_id, MMI_TRUE, (PU16)g_cf_num_edit_menu, (U8)g_cf_num_edit_menu_count);
            break;
        
        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
//            mmi_callset_sel_cf_num_edit_not_empty(fsedit_evt->sender_id);
            cui_fseditor_set_custom_options_menu(fsedit_evt->sender_id, MMI_FALSE, (PU16)g_cf_num_edit_menu, (U8)g_cf_num_edit_menu_count);
            break;

        case EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED:
            if (fsedit_custom_evt->menu_id == MENU_ID_CALLSET_CF_NUM_EDIT_FROM_PHB)
            {
                mmi_callset_entry_cf_num_edit_from_phb(GRP_ID_CALLSET_CF);
            }
            break;
        
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            mmi_callset_sel_cf_num_edit_done(fsedit_evt);
            break;
        
        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FSEDITOR_DEINIT:
            mmi_callset_close_fseditor(fsedit_evt->sender_id);
            break;

        /* phb event */
        case EVT_ID_PHB_SELECT_CONTACT:
            mmi_callset_sel_cf_num_edit_from_phb_done((void*)phb_evt);
            break;

        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            cui_phb_list_select_contact_close(phb_evt->sender_id);
            break;
    }

    return MMI_RET_OK;
}

#ifdef __MMI_CALLSET_CALL_BARRING__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_cb
 * DESCRIPTION
 *  process for call setting common screen group (GRP_ID_CALLSET_CB)
 * PARAMETERS
 *  index       [IN]     highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_callset_proc_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* menu event */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            switch (menu_evt->parent_menu_id )
            {
                case MENU_ID_CALLSET_CB_OUT_OPT:
                case MENU_ID_CALLSET_CB_IN_OPT:
                {
                    mmi_callset_hide_ss_operation(menu_evt->sender_id, MMI_CALLSET_CB_ITEM_NUM, (mmi_callst_ss_operation_data_struct *)g_callset_cb_data);
                    break;
                }
                case MENU_ID_CALLSET_CB_OUT_BAOC_VOICE:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAOC, SRV_SS_VOICE_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CB_OUT_BOIC_VOICE:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BOIC, SRV_SS_VOICE_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CB_OUT_BOICEXHC_VOICE:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BOICEXHC, SRV_SS_VOICE_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CB_IN_BAIC_VOICE:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAIC, SRV_SS_VOICE_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CB_IN_BAICROAM_VOICE:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAICROAM, SRV_SS_VOICE_CALL);
                    break;
                }
            #ifdef __MMI_VIDEO_TELEPHONY__
                case MENU_ID_CALLSET_CB_OUT_BAOC_VIDEO:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAOC, SRV_SS_VIDEO_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CB_OUT_BOIC_VIDEO:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BOIC, SRV_SS_VIDEO_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CB_OUT_BOICEXHC_VIDEO:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BOICEXHC, SRV_SS_VIDEO_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CB_IN_BAIC_VIDEO:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAIC, SRV_SS_VIDEO_CALL);
                    break;
                }
                case MENU_ID_CALLSET_CB_IN_BAICROAM_VIDEO:
                {
                    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAICROAM, SRV_SS_VIDEO_CALL);
                    break;
                }
            #endif /* __MMI_VIDEO_TELEPHONY__ */
                default:
                {
                    break;
                }
            }

            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        }

//        case EVT_ID_CUI_MENU_ITEM_HILITE:
//            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_callset_sel_cb_opt(menu_evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
            break;
    }

    return MMI_RET_OK;
}
#endif /*__MMI_CALLSET_CALL_BARRING__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_send_ss_req_common
 * DESCRIPTION
 *  to request the ss action
 * PARAMETERS
 *  act_op : [IN] action operation code
 *  act_data : [IN] action parameters
 *  callback : [IN] callback to notify the result, srv_ss_rsp_evt_struct, can be NULL
 *  user_data : [IN] user data, can be NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_send_ss_req_common(srv_ss_act_enum act_op, void *act_data, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_ss_act_req(act_op, act_data, callback, user_data);
    mmi_callset_display_error_popup_by_result(result);
}


#ifndef __MMI_MAINLCD_96X64__
#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_ctr
 * DESCRIPTION
 *  process for call setting common screen group (GRP_ID_CALLSET_CTR)
 * PARAMETERS
 *  index       [IN]     highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_callset_proc_ctr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* menu event */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == MENU_ID_CALLSET_CTR_MODE)
            {
                mmi_callset_entry_ctr_mode(menu_evt->sender_id);
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            }
            break;

//        case EVT_ID_CUI_MENU_ITEM_HILITE:
//            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->parent_menu_id == MENU_ID_CALLSET_CTR_MODE)
            {
                mmi_callset_sel_ctr_mode(menu_evt);
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
            break;
    }

    return MMI_RET_OK;
}
#endif /*__MMI_CALLSET_CALLTIME_REMINDER__*/
#endif /* __MMI_MAINLCD_96X64__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_common_scrn
 * DESCRIPTION
 *  process for common screen
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_callset_proc_common_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            if (evt->user_data)
            {
                OslMfree(evt->user_data);
            }
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}

#ifdef __MMI_AP_DCM_CALLSET__
#pragma arm section rodata , code
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_center_launch
 * DESCRIPTION
 *  launch call center
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_call_center_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__MMI_AP_DCM_CALLSET__)
    if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
        mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    mmi_callset_common_launch(MENU_ID_CALLSET_CALL_CENTER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_launch
 * DESCRIPTION
 *  launch call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_call_setting_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__MMI_AP_DCM_CALLSET__)
    if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
        mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    if (!srv_mode_switch_is_network_service_available())
    {
        mmi_callset_display_error_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);

    #if defined (__MMI_AP_DCM_CALLSET__)
        if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
            mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
    #endif

        return; 
    }

    mmi_callset_common_launch(MENU_ID_CALLSET_CALL_SETTING);
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim1_launch
 * DESCRIPTION
 *  launch sim1 call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_call_setting_sim1_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__MMI_AP_DCM_CALLSET__)
    if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
        mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    mmi_callset_call_setting_sim_common_launch(MMI_SIM1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim2_launch
 * DESCRIPTION
 *  launch sim2 call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_call_setting_sim2_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__MMI_AP_DCM_CALLSET__)
    if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
        mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    mmi_callset_call_setting_sim_common_launch(MMI_SIM2);
}


#if (MMI_MAX_SIM_NUM>=3)
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim3_launch
 * DESCRIPTION
 *  launch sim2 call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_call_setting_sim3_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__MMI_AP_DCM_CALLSET__)
    if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
        mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    mmi_callset_call_setting_sim_common_launch(MMI_SIM3);
}

#if (MMI_MAX_SIM_NUM>=4)
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim4_launch
 * DESCRIPTION
 *  launch sim2 call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_call_setting_sim4_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (__MMI_AP_DCM_CALLSET__)
    if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
        mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    mmi_callset_call_setting_sim_common_launch(MMI_SIM4);
}
#endif
#endif
#endif /*  (MMI_MAX_SIM_NUM >= 2) */


#ifdef __MMI_AP_DCM_CALLSET__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_callset_entry_call_center(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VIDEO_TELEPHONY__
    if (!mmi_ucm_vt_check_launch_capability())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_UCM_VT_MAIN, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_UCM_VT_MAIN, MMI_FALSE);
    }
#endif/* __MMI_VIDEO_TELEPHONY__ */

#if 0
#ifdef __MMI_VOIP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VOIP__ */
#endif 

#if (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)) && defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_MRE_MAIN_MENU__)
    if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) != MMI_IDLE_TYPE_CLASSIC)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_PHONEBOOK, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_PHONEBOOK, MMI_FALSE);
    }
#endif
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_set_sim_item_string
 * DESCRIPTION
 *  Set menu item string with SIM name
 * PARAMETERS
 *  owner_gid       [IN]    Menu GID from cui_menu_create
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_set_sim_item_string(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    WCHAR *sim_name;    
    WCHAR menu_str[MAX_SUBMENU_CHARACTERS];
    U16 menu_string[] = {
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_CALLSET_SIM1_CALL_SETTING,
        STR_ID_CALLSET_SIM2_CALL_SETTING,
    #if (MMI_MAX_SIM_NUM>=3)
        STR_ID_CALLSET_SIM3_CALL_SETTING,
    #if (MMI_MAX_SIM_NUM>=4)
        STR_ID_CALLSET_SIM4_CALL_SETTING,
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        };
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        sim_name = mmi_netset_get_sim_name(sim_id);

        if(1 == srv_sim_ctrl_get_num_of_inserted())
        {
            if (srv_sim_ctrl_is_inserted(sim_id))
            {
                if (sim_name)
                {
                    kal_wsprintf(menu_str, "%w(%w)", GetString(STR_ID_CALLSET_SIM_CALL_SETTING), sim_name);
                    cui_menu_set_item_string(owner_gid, MENU_ID_CALLSET_CALL_SETTING_SIM1 + i, menu_str);
                }
                else
                {
                    cui_menu_set_item_string(owner_gid, MENU_ID_CALLSET_CALL_SETTING_SIM1 + i, (WCHAR *)GetString(STR_ID_CALLSET_SIM_CALL_SETTING));
                }
                break;
            }
        }
        else
        {
            if (sim_name)
            {
                kal_wsprintf(menu_str, "%w(%w)", GetString(menu_string[i]), sim_name);
                cui_menu_set_item_string(owner_gid, MENU_ID_CALLSET_CALL_SETTING_SIM1 + i, menu_str);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_change_sim_setting_title
 * DESCRIPTION
 *  Change the title of sim setting screen
 * PARAMETERS
 *  owner_gid       [IN]    Menu GID from cui_menu_create
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_change_sim_setting_title(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_image_type img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(1 == srv_sim_ctrl_get_num_of_inserted())
    {
        cui_menu_get_default_title_image(owner_gid, &img);
        cui_menu_set_currlist_title(owner_gid, (WCHAR* )GetString(STR_ID_CALLSET_SIM_CALL_SETTING), img);
    }
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_callset_entry_call_setting(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CALLSET_CALLER_ID__
    mmi_callset_hide_common(menu_gid, MMI_CALLSET_OP_CID);
    mmi_callset_hilite_common(menu_gid, MMI_CALLSET_OP_CID);
#endif /* __MMI_CALLSET_CALLER_ID__ */

    mmi_callset_hide_ss_operation(menu_gid, MMI_CALLSET_SS_ITEM_NUM, (mmi_callst_ss_operation_data_struct *)g_callset_ss_op_data);

#ifdef __MMI_CALLSET_LINE_SWITCHING__
    mmi_callset_hide_common(menu_gid, MMI_CALLSET_OP_LINE_SWITCH);
    mmi_callset_hilite_common(menu_gid, MMI_CALLSET_OP_LINE_SWITCH);
#endif /*__MMI_CALLSET_LINE_SWITCHING__*/
    
#ifdef __MMI_CALLSET_CUG__
    mmi_callset_hide_common(menu_gid, MMI_CALLSET_OP_CUG);
#endif /* __MMI_CALLSET_CUG__ */

    cui_menu_set_currlist_flags(menu_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_callset_change_sim_setting_title(menu_gid);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_close_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_gid      [IN]    target group id
 *  app_data        [IN]    app_data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_close_menu(MMI_ID menu_gid, void *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_menu_close(menu_gid);
    
    if (app_data)
    {
        OslMfree(app_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hide_common
 * DESCRIPTION
 *  the handler for check menu id display or not
 * PARAMETERS
 *  menu_gid      [IN]    target group id
 *  op        [IN]    operation id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hide_common(MMI_ID menu_gid, mmi_callset_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op)
    {
    #ifdef __MMI_CALLSET_CALLER_ID__
        case MMI_CALLSET_OP_CID:
            mmi_callset_hide_cid(menu_gid);
            break;
    #endif /* __MMI_CALLSET_CALLER_ID__ */

    #ifdef __MMI_CALLSET_LINE_SWITCHING__
        case MMI_CALLSET_OP_LINE_SWITCH:
            mmi_callset_hide_lsw(menu_gid);
            break;
    #endif /*__MMI_CALLSET_LINE_SWITCHING__*/

    #ifdef __MMI_CALLSET_CUG__
        case MMI_CALLSET_OP_CUG:
            mmi_callset_hide_cug(menu_gid);
            break;
    #endif /* __MMI_CALLSET_CUG__ */

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_common
 * DESCRIPTION
 *  the handler for update event which is used to update the display
 * PARAMETERS
 *  menu_gid      [IN]    target group id
 *  op        [IN]    operation id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_common(MMI_ID menu_gid, mmi_callset_op_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op)
    {
    #ifdef __MMI_CALLSET_CALLER_ID__
        case MMI_CALLSET_OP_CID:
            mmi_callset_hilite_cid(menu_gid);
            break;
    #endif /* __MMI_CALLSET_CALLER_ID__ */

    #ifdef __MMI_CALLSET_LINE_SWITCHING__
        case MMI_CALLSET_OP_LINE_SWITCH:
            mmi_callset_hilite_lsw(menu_gid);
            break;
    #endif /* __MMI_CALLSET_LINE_SWITCHING__*/
            
    #ifdef __MMI_CALLSET_AUTO_REDIAL__
        case MMI_CALLSET_OP_AUTOREDIAL:
            mmi_callset_hilite_auto_redial(menu_gid);
            break;
    #endif /*__MMI_CALLSET_AUTO_REDIAL__*/
    #ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
        case MMI_CALLSET_OP_CTD:
            mmi_callset_hilite_ctd(menu_gid);
            break;
    #endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */

    #ifdef __MMI_UCM_REJECT_BY_SMS__
        case MMI_CALLSET_OP_REJ_BY_SMS:
            mmi_callset_hilite_rej_by_sms(menu_gid);
            break;
    #endif /* __MMI_UCM_REJECT_BY_SMS__ */

    #ifdef __MMI_CONNECT_NOTICE__
        case MMI_CALLSET_OP_CONNECT_NOTICE:
            mmi_callset_hilite_connect_notice(menu_gid);
            break;
    #endif /* __MMI_CONNECT_NOTICE__ */
    
    #if 0
    #ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __OP01_FWPBW__ */
    #endif
    
    #ifdef __MMI_CH_QUICK_END__
        case MMI_CALLSET_OP_CH_QUICK_END:
            mmi_callset_hilite_auto_quick_end(menu_gid);
            break;
    #endif /* __MMI_CH_QUICK_END__ */
    
    #ifdef __MMI_CALLSET_CALLTIME_REMINDER__
        case MMI_CALLSET_OP_CTR:
            mmi_callset_hilite_ctr(menu_gid);
        break;
    #endif /* __MMI_CALLSET_CALLTIME_REMINDER__*/

    #ifdef __MMI_CM_BLACK_LIST__
        case MMI_CALLSET_OP_BL_FROM_LIST:
            mmi_callset_hilite_bl_from_list(menu_gid);
        break;
    #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
        case MMI_CALLSET_OP_BL_REJ_UNKNOWN_NUM:
            mmi_callset_hilite_bl_rej_unknown_num(menu_gid);
        break;
    #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
    #endif /* __MMI_CM_BLACK_LIST__ */

    #ifdef __MMI_CM_WHITE_LIST__
        case MMI_CALLSET_OP_WL_FROM_LIST:
            mmi_callset_hilite_wl_from_list(menu_gid);
        break;
    #endif /* __MMI_CM_WHITE_LIST__ */

    #ifdef __CTM_SUPPORT__
        case MMI_CALLSET_OP_CTM:
            mmi_callset_hilite_ctm_mode(menu_gid);
            break;
    #endif /* __CTM_SUPPORT__ */

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_close_fseditor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    full screen editor group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_close_fseditor(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_callset_p->fs_edit_processing)
    {
        return;
    }
    else
    {
        mmi_callset_p->fs_edit_processing = MMI_TRUE;
    }

    if (cui_fseditor_get_parent_data(gid))
    {
        OslMfree((void*)cui_fseditor_get_parent_data(gid));
    }
    
    cui_fseditor_close(gid);

    if (MMI_FALSE)
    {
    }
    else if (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2) ||
		(mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && 
             (gid == mmi_callset_sim_p->cf_num_edit_gid))
    {
        mmi_callset_sim_p->cf_num_edit_gid = 0;
    }
#ifdef __MMI_CALLSET_CUG__
    else if (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2)||
		(mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && 
             (gid == mmi_callset_sim_p->cug_name_edit_gid))
    {
        mmi_callset_sim_p->cug_name_edit_gid = 0;
    }
    else if (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2)||
		(mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) && 
             (gid == mmi_callset_sim_p->cug_id_edit_gid))
    {
        mmi_callset_sim_p->cug_id_edit_gid = 0;
    }
#endif /* __MMI_CALLSET_CUG__ */
#ifdef __IP_NUMBER__
    else if (gid == mmi_callset_p->ip_number_edit_gid)
    {
        mmi_callset_p->ip_number_edit_gid = 0;
    }
#endif /* __IP_NUMBER__ */
#ifdef __MMI_CM_BLACK_LIST__
    else if (gid == mmi_callset_p->blacklist_edit_gid)
    {
        mmi_callset_p->blacklist_edit_gid = 0;
    }
#endif /* __MMI_CM_BLACK_LIST__ */
#ifdef __MMI_CM_WHITE_LIST__
    else if (gid == mmi_callset_p->whitelist_edit_gid)
    {
        mmi_callset_p->whitelist_edit_gid = 0;
    }
#endif /* __MMI_CM_WHITE_LIST__ */

    mmi_callset_p->fs_edit_processing = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_reset_fseditor
 * DESCRIPTION
 *  Reset fseditoer cui id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_reset_fseditor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((mmi_callset_p->target_sim == MMI_SIM1) || (mmi_callset_p->target_sim == MMI_SIM2) ||
        (mmi_callset_p->target_sim == MMI_SIM3) || (mmi_callset_p->target_sim == MMI_SIM4)) &&
        (mmi_callset_sim_p != NULL))
    {
        mmi_callset_sim_p->cf_num_edit_gid = 0;
    #ifdef __MMI_CALLSET_CUG__
        mmi_callset_sim_p->cug_name_edit_gid = 0;
        mmi_callset_sim_p->cug_id_edit_gid = 0;
    #endif /* __MMI_CALLSET_CUG__ */
    }

#ifdef __IP_NUMBER__
    mmi_callset_p->ip_number_edit_gid = 0;
#endif /* __IP_NUMBER__ */

#ifdef __MMI_CM_BLACK_LIST__
    mmi_callset_p->blacklist_edit_gid = 0;
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __MMI_CM_WHITE_LIST__
    mmi_callset_p->whitelist_edit_gid = 0;
#endif /* __MMI_CM_WHITE_LIST__ */
}


#ifdef __MMI_NCENTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_close_all
 * DESCRIPTION
 *  Close all call setting screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_close_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_close(GRP_ID_CALLSET_COMMON);
    mmi_frm_group_close(GRP_ID_CALLSET_CF);
    mmi_frm_group_close(GRP_ID_CALLSET_CB);
#ifndef __MMI_MAINLCD_96X64__
#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
    mmi_frm_group_close(GRP_ID_CALLSET_CTR);
#endif /*__MMI_CALLSET_CALLTIME_REMINDER__*/
#endif /* __MMI_MAINLCD_96X64__ */
}
#endif /* __MMI_NCENTER_SUPPORT__ */


#ifdef __MMI_CALLSET_CALLER_ID__
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_callset_hide_cid(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_is_available(mmi_callset_sim_p->sim) &&
        srv_callset_is_caller_id_supported(mmi_callset_sim_p->sim))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CID, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CID, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_cid
 * DESCRIPTION
 *  highlight handler for caller id menu item
 * PARAMETERS
 *  menu_gid         [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_cid(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (srv_callset_caller_id_get_mode(mmi_callset_sim_p->sim))
    {
        case SRV_CALLSET_CALLER_ID_HIDE:
            cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CID, get_string(STR_ID_CALLSET_CID_HIDE));
            break;

        case SRV_CALLSET_CALLER_ID_SHOW:
            cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CID, get_string(STR_ID_CALLSET_CID_SEND));
            break;

        case SRV_CALLSET_CALLER_ID_BY_NETWORK:
            cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CID, get_string(STR_ID_CALLSET_CID_AUTO));
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_cid_mode
 * DESCRIPTION
 *  create caller id mode menu
 * PARAMETERS
 *  parent_gid         [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_cid_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_CID_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cid_mode
 * DESCRIPTION
 *  entry handler for caller id mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cid_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (srv_callset_caller_id_get_mode(mmi_callset_sim_p->sim))
    {
        case SRV_CALLSET_CALLER_ID_HIDE:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CID_HIDE);
            break;

        case SRV_CALLSET_CALLER_ID_SHOW:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CID_SEND);
            break;

        case SRV_CALLSET_CALLER_ID_BY_NETWORK:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CID_AUTO);
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cid_mode
 * DESCRIPTION
 *  select handler for caller id mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cid_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_callset_cid_set_mode_struct mode;
    MMI_ID *menu_gid_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&mode, 0, sizeof(srv_callset_cid_set_mode_struct));
    mode.sim = mmi_callset_sim_p->sim;

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_CID_AUTO:
            mode.mode = SRV_CALLSET_CALLER_ID_BY_NETWORK;
            break;

        case MENU_ID_CALLSET_CID_HIDE:
            mode.mode = SRV_CALLSET_CALLER_ID_HIDE;
            break;

        case MENU_ID_CALLSET_CID_SEND:
            mode.mode = SRV_CALLSET_CALLER_ID_SHOW;
            break;

        default:
            return;
    }

    menu_gid_p = OslMalloc(sizeof(MMI_ID));
    memcpy(menu_gid_p, &(menu_evt->sender_id), sizeof(MMI_ID));

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyDownHandler(0, KEY_END);

    srv_callset_caller_id_set_mode(&mode, mmi_callset_sel_cid_mode_cb, menu_gid_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cid_mode_cb
 * DESCRIPTION
 *  callback handler for set cid result
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_callset_sel_cid_mode_cb(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_struct *data = (srv_callset_result_struct*)(((srv_callset_rsp_evt_struct*)info)->data);
    MMI_ID *menu_gid_p = (MMI_ID*)(info->user_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(data && menu_gid_p);

    mmi_callset_display_popup_by_cause(data->result);

    if (mmi_frm_group_is_present(*menu_gid_p))
    {
        mmi_callset_close_menu(*menu_gid_p, cui_menu_get_app_parent_data(*menu_gid_p));
    }

    OslMfree(menu_gid_p);

    return MMI_RET_OK;
}
#endif /* __MMI_CALLSET_CALLER_ID__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hide_cw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  
 *****************************************************************************/
void mmi_callset_hide_cw(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_is_available(mmi_callset_sim_p->sim) &&
        srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_WAIT, 0, SRV_SS_ALL_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CALL_WAIT, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CALL_WAIT, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_cw_opt
 * DESCRIPTION
 *  create call wait option menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_cw_opt(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_CALL_WAIT_OPT, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cw_opt
 * DESCRIPTION
 *  select handler for call wait option menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cw_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_ss_call_wait_req_struct req;
    MMI_ID *menu_gid_p;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&req, 0, sizeof(srv_ss_call_wait_req_struct));
    req.sim = mmi_callset_p->target_sim;

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_ACTIVATE:
    {
        req.action = SRV_SS_ACTION_TYPE_ACTIVATE;
            break;
        }
        case MENU_ID_CALLSET_DEACTIVATE:
        {
            req.action = SRV_SS_ACTION_TYPE_DEACTIVATE;
            break;
        }
        case MENU_ID_CALLSET_QUERY:
        {
            req.action = SRV_SS_ACTION_TYPE_QUERY;
            break;
        }
        default:
        {
        return;
    }
    }

    menu_gid_p = OslMalloc(sizeof(MMI_ID));
    memcpy(menu_gid_p, &(menu_evt->sender_id), sizeof(MMI_ID));

    result = srv_ss_act_req(SRV_SS_ACT_CALL_WAIT, &req, mmi_callset_sel_cw_opt_cb, menu_gid_p);
    mmi_callset_display_error_popup_by_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cw_opt_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_callset_sel_cw_opt_cb(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID *menu_gid_p = info->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(menu_gid_p);

    if (mmi_frm_group_is_present(*menu_gid_p))
    {
        mmi_callset_close_menu(*menu_gid_p, cui_menu_get_app_parent_data(*menu_gid_p));
    }

    OslMfree(menu_gid_p);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_callset_hide_cf(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_is_available(mmi_callset_sim_p->sim) &&
        srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFALL, SRV_SS_ALL_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CALL_FWD, MMI_FALSE);
        /* continue to check the sub-menus */
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CALL_FWD, MMI_TRUE);
        /* don't care the sub-menus */
        return;
    }

    /* CF is vailable and supported, continue to check the sub-menus */

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFU, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFU_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFU_VOICE, MMI_TRUE);
    }

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFNRC, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRC_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRC_VOICE, MMI_TRUE);
    }

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFNRY, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRY_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRY_VOICE, MMI_TRUE);
    }

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFB, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFB_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFB_VOICE, MMI_TRUE);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
#if !defined(__MMI_3G_SWITCH__)
    if (mmi_callset_sim_p->sim != MMI_SIM1)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFU_VIDEO, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRC_VIDEO, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRY_VIDEO, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFB_VIDEO, MMI_TRUE);
    }
    else
#endif /* __MMI_3G_SWITCH__ */
    {
        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFU, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFU_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFU_VIDEO, MMI_TRUE);
        }

        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFNRC, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRC_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRC_VIDEO, MMI_TRUE);
        }

        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFNRY, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRY_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFNRY_VIDEO, MMI_TRUE);
        }

        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFB, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFB_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFB_VIDEO, MMI_TRUE);
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_FORWARD, (U8)SRV_SS_CALL_FORWARD_CFU, SRV_SS_DATA_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFU_DATA, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CFU_DATA, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cf_cancelall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cf_cancelall(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_entry_cf_opt(SRV_SS_CALL_FORWARD_CFALL, SRV_SS_ALL_CALL);
    mmi_callset_sim_p->cf_info.action = SRV_SS_ACTION_TYPE_DEACTIVATE;

    result = srv_ss_act_req(SRV_SS_ACT_CALL_FORWARD, &(mmi_callset_sim_p->cf_info), NULL, NULL);
    mmi_callset_display_error_popup_by_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_cfu_voice_opt
 * DESCRIPTION
 *  create call wait option menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_cf_opt(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create_ex(GRP_ID_CALLSET_COMMON, GRP_ID_CALLSET_CF, mmi_callset_proc_cf, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_callset_common_create_cui(GRP_ID_CALLSET_CF, menu_id, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cfu_voice_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cf_opt(srv_ss_call_forward_type_enum cf_type, srv_ss_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(mmi_callset_sim_p->cf_info), 0, sizeof(srv_ss_call_forward_req_struct));
    mmi_callset_sim_p->cf_info.sim = mmi_callset_sim_p->sim;
    mmi_callset_sim_p->cf_info.type = cf_type;
    mmi_callset_sim_p->cf_info.call_type = call_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cf_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cf_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_DEACTIVATE:
        {
            mmi_callset_sim_p->cf_info.action = SRV_SS_ACTION_TYPE_DEACTIVATE;
            break;
        }
        case MENU_ID_CALLSET_QUERY:
        {
            mmi_callset_sim_p->cf_info.action = SRV_SS_ACTION_TYPE_QUERY;
            break;
        }
        default:
        {
            return;
        }
    }

    result = srv_ss_act_req(SRV_SS_ACT_CALL_FORWARD, &(mmi_callset_sim_p->cf_info), mmi_callset_sel_cf_opt_cb, NULL);

    mmi_callset_display_error_popup_by_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cfu_voice_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cf_activate(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((mmi_callset_sim_p->cf_info.call_type == SRV_SS_DATA_CALL) ||
        (mmi_callset_sim_p->cf_info.call_type == SRV_SS_VIDEO_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CF_TO_VM, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cf_activate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cf_activate(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_sim_p->cf_info.action = SRV_SS_ACTION_TYPE_ACTIVATE;

    switch(menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_CF_TO_NEW:
        {
            mmi_callset_entry_cf_num_edit(GRP_ID_CALLSET_CF);
            break;
        }
        case MENU_ID_CALLSET_CF_TO_VM:
        {
            mmi_callset_sel_cf_to_vm();
            break;
        }
        default:
        {
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cf_num_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cf_num_edit(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID fseditor_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fseditor_gid = cui_fseditor_create(gid);
    mmi_callset_sim_p->cf_num_edit_gid = fseditor_gid;

    cui_fseditor_set_text(fseditor_gid, NULL, 0, SRV_SS_MAX_FWD_ADDR_LEN - 1);
    cui_fseditor_set_title(fseditor_gid, STR_ID_CALLSET_CALLFWD_TO_NUM, GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
    cui_fseditor_set_input_method(fseditor_gid, INPUT_TYPE_PLUS_CHARACTER_HANDLING|IMM_INPUT_TYPE_SIM_NUMERIC, NULL, INPUT_TYPE_EXT_SIM_NUMERIC);
    cui_fseditor_set_custom_options_menu(fseditor_gid, MMI_FALSE, (PU16)g_cf_num_edit_menu, g_cf_num_edit_menu_count);
    cui_fseditor_run(fseditor_gid);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    FS editor group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cf_num_edit_empty(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_fseditor_set_custom_options_menu(gid, MMI_TRUE, (PU16)g_cf_num_edit_menu, (U8)g_cf_num_edit_menu_count);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    FS editor group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cf_num_edit_not_empty(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_fseditor_set_custom_options_menu(gid, MMI_FALSE, (PU16)g_cf_num_edit_menu, (U8)g_cf_num_edit_menu_count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cf_num_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cf_num_edit_done(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct *fsedit_evt = (cui_fseditor_evt_struct*)info;
    S32 len;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    len = cui_fseditor_get_text(fsedit_evt->sender_id, mmi_callset_sim_p->cf_info.forward_number, sizeof(mmi_callset_sim_p->cf_info.forward_number));

    MMI_ASSERT(len);

    /* check number by callset app to support going back to editor when the number is invalid
     * (if the number is checked and rejected by ss srv, the editor is closed)
     */
    if (!srv_ss_is_valid_call_forward_number(
            mmi_callset_sim_p->sim,
            (U8)len,
            mmi_callset_sim_p->cf_info.forward_number))
    {
        mmi_callset_display_error_popup(STR_GLOBAL_INVALID_NUMBER);
    }
    else if (mmi_callset_sim_p->cf_info.type != SRV_SS_CALL_FORWARD_CFNRY)
    {
        result = srv_ss_act_req(SRV_SS_ACT_CALL_FORWARD, &(mmi_callset_sim_p->cf_info), mmi_callset_sel_cf_opt_cb, NULL);
        mmi_callset_display_error_popup_by_result(result);
    }
    else
    {
        mmi_callset_create_cfnry_time_opt(GRP_ID_CALLSET_CF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cf_num_edit_from_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cf_num_edit_from_phb(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID phb_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    phb_gid = cui_phb_list_select_contact_create(gid);
    cui_phb_list_select_contact_set_field_filter(phb_gid, SRV_PHB_ENTRY_FIELD_GSM_NUM);
    cui_phb_list_select_contact_run(phb_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cf_num_edit_from_phb_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cf_num_edit_from_phb_done(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_select_contact_result_struct *evt = (cui_phb_select_contact_result_struct*)info;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    len = mmi_ucs2strlen((CHAR*)evt->select_data);

    if (srv_ss_is_valid_call_forward_number(
            mmi_callset_sim_p->sim,
            (U8)len,
            evt->select_data))
    {
        cui_fseditor_set_text(mmi_callset_sim_p->cf_num_edit_gid, 
            evt->select_data, 
            (SRV_SS_MAX_FWD_ADDR_LEN + 1) * ENCODING_LENGTH, 
            SRV_SS_MAX_FWD_ADDR_LEN - 1);

        cui_phb_list_select_contact_close(evt->sender_id);
    }
    else
    {
        if ((*(evt->select_data) == L'+' &&
                len > SRV_SS_MAX_FWD_ADDR_LEN) || 
            (*(evt->select_data) != L'+' &&
                len > (SRV_SS_MAX_FWD_ADDR_LEN - 1)))
        {
            mmi_callset_display_error_popup(STR_ID_CALLSET_NUMBER_TOO_LONG);
        }
        else
        {
            mmi_callset_display_error_popup(STR_GLOBAL_INVALID_NUMBER);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cf_to_vm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cf_to_vm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const srv_sms_mailbox_struct *sms_info = NULL;
    U32 i;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mmi_callset_sim_p->sim)
    {
        case MMI_SIM1:
            sms_info = srv_sms_get_mailbox_setting(SRV_SMS_SIM_1);
            break;
#if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            sms_info = srv_sms_get_mailbox_setting(SRV_SMS_SIM_2);
            break;
    #if (MMI_MAX_SIM_NUM>=3)
	/*need to add for Gemini Plus SIM3 and SIM4*/
        case MMI_SIM3:
            sms_info = srv_sms_get_mailbox_setting(SRV_SMS_SIM_3); /*need to update later SRV SMS SIM ENUM*/
            break;
    #if (MMI_MAX_SIM_NUM>=4)
        case MMI_SIM4:
            sms_info = srv_sms_get_mailbox_setting(SRV_SMS_SIM_4); /*need to update later SRV SMS SIM ENUM*/
            break;
    #endif /* MMI_MAX_SIM_NUM>=4*/
    #endif /* MMI_MAX_SIM_NUM>=3*/
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
        default:
            return;
    }

    for (i = 0; i < sms_info->mailbox_number; i++)
    {
        /* use the first non-empty number */
        if (*(sms_info->p_mailbox_number[i]) != 0)
        {
            if (srv_ss_is_valid_call_forward_number(mmi_callset_sim_p->sim, 
                    (U8)mmi_ucs2strlen((CHAR*)sms_info->p_mailbox_number[i]),
                    (WCHAR*)(sms_info->p_mailbox_number[i])))
            {
                mmi_ucs2cpy((CHAR*)mmi_callset_sim_p->cf_info.forward_number, (CHAR*)(sms_info->p_mailbox_number[i]));

                if (mmi_callset_sim_p->cf_info.type != SRV_SS_CALL_FORWARD_CFNRY)
                {
                    result = srv_ss_act_req(SRV_SS_ACT_CALL_FORWARD, &(mmi_callset_sim_p->cf_info), mmi_callset_sel_cf_opt_cb, NULL);
                    mmi_callset_display_error_popup_by_result(result);
                        /* user data is handled and freed in the rsp cb */
                }
                else
                {
                    mmi_callset_create_cfnry_time_opt(GRP_ID_CALLSET_CF);
                }
                return;
            }
            else
            {
                mmi_callset_display_error_popup(STR_GLOBAL_INVALID_NUMBER);
                mmi_frm_group_close(GRP_ID_CALLSET_CF);
                return;
            }
        } 
    }

    /* no number to use */
    mmi_callset_display_error_popup(STR_GLOBAL_EMPTY);

    mmi_frm_group_close(GRP_ID_CALLSET_CF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cf_opt_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_callset_sel_cf_opt_cb(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_group_is_present(GRP_ID_CALLSET_CF))
    {
        mmi_frm_group_close(GRP_ID_CALLSET_CF);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_cfnry_time_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_cfnry_time_opt(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_CFNRY_TIME_OPT, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cfnry_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cfnry_time_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_CFNRY_5_SEC:
            mmi_callset_sim_p->cf_info.no_reply_timer = 5;
            break;
        case MENU_ID_CALLSET_CFNRY_10_SEC:
            mmi_callset_sim_p->cf_info.no_reply_timer = 10;
            break;
        case MENU_ID_CALLSET_CFNRY_15_SEC:
            mmi_callset_sim_p->cf_info.no_reply_timer = 15;
            break;
        case MENU_ID_CALLSET_CFNRY_20_SEC:
            mmi_callset_sim_p->cf_info.no_reply_timer = 20;
            break;
        case MENU_ID_CALLSET_CFNRY_25_SEC:
            mmi_callset_sim_p->cf_info.no_reply_timer = 25;
            break;
        case MENU_ID_CALLSET_CFNRY_30_SEC:
            mmi_callset_sim_p->cf_info.no_reply_timer = 30;
            break;
        default:
            return;
    }
   
    result = srv_ss_act_req(SRV_SS_ACT_CALL_FORWARD, &(mmi_callset_sim_p->cf_info), mmi_callset_sel_cf_opt_cb, NULL);

    mmi_callset_display_error_popup_by_result(result);
}


#ifdef __MMI_CALLSET_CALL_BARRING__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hide_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_callset_hide_cb(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_is_available(mmi_callset_sim_p->sim) &&
        srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BAC, SRV_SS_ALL_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CALL_BAR, MMI_FALSE);

        /* continue to check the sub-menus */
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CALL_BAR, MMI_TRUE);

        /* don't care the sub-menus */
        return;
    }

    /* CB is vailable and supported, continue to check the sub-menus */

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BOC, SRV_SS_ALL_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT, MMI_TRUE);
    }

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BIC, SRV_SS_ALL_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cb_operation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cb_operation(mmi_callset_cb_operation_enum cb_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_app_callset_scr_enum scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAC, SRV_SS_ALL_CALL);

    switch (cb_op)
    {
        case MMI_CALLSET_CB_CANCELALL:
            mmi_callset_sim_p->cb_info.action = SRV_SS_ACTION_TYPE_DEACTIVATE;
            mmi_callset_sim_p->cb_state = 0;
            scr_id = SCR_ID_CALLSET_CB_PASSWD;
            break;

        case MMI_CALLSET_CB_CHANGE_PWD:
            mmi_callset_sim_p->cb_info.action = SRV_SS_ACTION_TYPE_CHANGE_PASSWD;
            mmi_callset_sim_p->cb_state = 1;
            scr_id = SCR_ID_CALLSET_CB_PASSWD_OLD;
            break;

        default:
            return;
    }

    mmi_frm_group_create_ex(GRP_ID_CALLSET_COMMON, GRP_ID_CALLSET_CB, mmi_callset_proc_cb, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_CALLSET_CB, 
        scr_id, 
        (FuncPtr)mmi_callset_entry_cb_passwd, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cb_cancelall(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAC, SRV_SS_ALL_CALL);
    mmi_callset_sim_p->cb_info.action = SRV_SS_ACTION_TYPE_DEACTIVATE;
    mmi_callset_sim_p->cb_state = 0;

    mmi_frm_group_create_ex(GRP_ID_CALLSET_COMMON, GRP_ID_CALLSET_CB, mmi_callset_proc_cb, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_CALLSET_CB, 
        SCR_ID_CALLSET_CB_PASSWD, 
        (FuncPtr)mmi_callset_entry_cb_passwd, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cb_change_passwd(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_entry_cb_opt(SRV_SS_CALL_BAR_BAC, SRV_SS_ALL_CALL);
    mmi_callset_sim_p->cb_info.action = SRV_SS_ACTION_TYPE_CHANGE_PASSWD;
    mmi_callset_sim_p->cb_state = 1;

    mmi_frm_group_create_ex(GRP_ID_CALLSET_COMMON, GRP_ID_CALLSET_CB, mmi_callset_proc_cb, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_CALLSET_CB, 
        SCR_ID_CALLSET_CB_PASSWD_OLD, 
        (FuncPtr)mmi_callset_entry_cb_passwd, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_cb_opt(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create_ex(GRP_ID_CALLSET_COMMON, GRP_ID_CALLSET_CB, mmi_callset_proc_cb, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_callset_common_create_cui(GRP_ID_CALLSET_CB, menu_id, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hide_cb_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hide_cb_opt(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* entry CB opt menu, hide menu items */
    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BAOC, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BAOC_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BAOC_VOICE, MMI_TRUE);
    }

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BOIC, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOIC_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOIC_VOICE, MMI_TRUE);
    }

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BOICEXHC, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOICEXHC_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOICEXHC_VOICE, MMI_TRUE);
    }

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BAIC, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAIC_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAIC_VOICE, MMI_TRUE);
    }

    if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BAICROAM, SRV_SS_VOICE_CALL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAICROAM_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAICROAM_VOICE, MMI_TRUE);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
#if !defined(__MMI_3G_SWITCH__)
    if (mmi_callset_sim_p->sim != MMI_SIM1)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BAOC_VIDEO, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOIC_VIDEO, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOICEXHC_VIDEO, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAIC_VIDEO, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAICROAM_VIDEO, MMI_TRUE);
    }
    else
#endif /* __MMI_3G_SWITCH__ */
    {
        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BAOC, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BAOC_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BAOC_VIDEO, MMI_TRUE);
        }

        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BOIC, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOIC_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOIC_VIDEO, MMI_TRUE);
        }

        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BOICEXHC, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOICEXHC_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_OUT_BOICEXHC_VIDEO, MMI_TRUE);
        }

        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BAIC, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAIC_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAIC_VIDEO, MMI_TRUE);
        }

        if (srv_ss_check_capability(mmi_callset_sim_p->sim, SRV_SS_ACT_CALL_BAR, (U8)SRV_SS_CALL_BAR_BAICROAM, SRV_SS_VIDEO_CALL))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAICROAM_VIDEO, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CB_IN_BAICROAM_VIDEO, MMI_TRUE);
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cfu_voice_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cb_opt(srv_ss_call_bar_type_enum cb_type, srv_ss_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(mmi_callset_sim_p->cb_info), 0, sizeof(srv_ss_call_bar_req_struct));
    mmi_callset_sim_p->cb_info.sim = mmi_callset_sim_p->sim;
    mmi_callset_sim_p->cb_info.type = cb_type;
    mmi_callset_sim_p->cb_info.call_type= call_type;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cb_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_ACTIVATE:
            mmi_callset_sim_p->cb_info.action = SRV_SS_ACTION_TYPE_ACTIVATE;
            mmi_callset_sim_p->cb_state = 0;
            mmi_frm_scrn_first_enter(
                GRP_ID_CALLSET_CB, 
                SCR_ID_CALLSET_CB_PASSWD, 
                (FuncPtr)mmi_callset_entry_cb_passwd, 
                0);
            break;
    
        case MENU_ID_CALLSET_DEACTIVATE:
            mmi_callset_sim_p->cb_info.action = SRV_SS_ACTION_TYPE_DEACTIVATE;
            mmi_callset_sim_p->cb_state = 0;
            mmi_frm_scrn_first_enter(
                GRP_ID_CALLSET_CB, 
                SCR_ID_CALLSET_CB_PASSWD, 
                (FuncPtr)mmi_callset_entry_cb_passwd, 
                0);
            break;

        case MENU_ID_CALLSET_QUERY:
            mmi_callset_sim_p->cb_info.action = SRV_SS_ACTION_TYPE_QUERY;
            result = srv_ss_act_req(SRV_SS_ACT_CALL_BAR, &(mmi_callset_sim_p->cb_info), mmi_callset_sel_cb_opt_cb, 0);
            mmi_callset_display_error_popup_by_result(result);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_cb_passwd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_callset_proc_cb_passwd(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            memset(mmi_callset_cb_get_passwd_buf(), 0, sizeof((SRV_SS_PASSWORD_MAX_LENTH + 1) * ENCODING_LENGTH));
            if (mmi_frm_is_in_backward_scenario())
            {
                mmi_callset_sim_p->cb_state -= 1;
            }
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cb_passwd(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    WCHAR *buf;
    U16 title_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
        data->group_id, 
        data->scrn_id, 
        NULL, 
        (FuncPtr)mmi_callset_entry_cb_passwd, 
        MMI_FRM_UNKNOW_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_callset_proc_cb_passwd);
        return;
    }

    mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_callset_proc_cb_passwd);

    buf = mmi_callset_cb_get_passwd_buf();
    title_id = mmi_callset_cb_get_passwd_title();
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterInputBoxValidationFunction(mmi_callset_cb_passwd_check);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        title_id,
        IMM_INPUT_TYPE_NUMERIC_PASSWORD,
        (PU8)buf,
        SRV_SS_PASSWORD_MAX_LENTH + 1,
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR *mmi_callset_cb_get_passwd_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mmi_callset_sim_p->cb_state)
    {
        case 0:
            return mmi_callset_sim_p->cb_info.password_old;

        case 1:
            return mmi_callset_sim_p->cb_info.password_old;

        case 2:
            return mmi_callset_sim_p->cb_info.password_new;

        case 3:
            return mmi_callset_sim_p->cb_info.password_cnf;

        default:
            MMI_ASSERT(0);
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_callset_cb_get_passwd_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mmi_callset_sim_p->cb_state)
    {
    #ifdef __MMI_MAINLCD_96X64__
        case 0:
            return STR_ID_CALLSET_CB_PASSWD_BWUI;
        case 1:
            return STR_ID_CALLSET_CB_PASSWD_OLD_BWUI;
        case 2:
            return STR_ID_CALLSET_CB_PASSWD_NEW_BWUI;
        case 3:
            return STR_ID_CALLSET_CB_PASSWD_CNF_BWUI;
    #else
        case 0:
            return STR_ID_CALLSET_CB_PASSWD;
        case 1:
            return STR_ID_CALLSET_CB_PASSWD_OLD;
        case 2:
            return STR_ID_CALLSET_CB_PASSWD_NEW;
        case 3:
            return STR_ID_CALLSET_CB_PASSWD_CNF;
    #endif
        default:
            MMI_ASSERT(0);
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 * 
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_cb_passwd_check(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (length < SRV_SS_PASSWORD_MAX_LENTH)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
        SetKeyUpHandler(NULL, KEY_POUND);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        /* check the screen from which validation came */
        switch (mmi_callset_sim_p->cb_state)
        {
            /* if the call barring options is selected */
            case 0:
            /* if the call barring options is selected */
            case 3:
                SetLeftSoftkeyFunction(mmi_callset_sel_cb_passwd_done, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_callset_sel_cb_passwd_done, KEY_EVENT_UP);
                SetKeyUpHandler(mmi_callset_sel_cb_passwd_done, KEY_POUND);
                break;

            /* if the flow is from call barring new passwords screen */
            case 1:
            /* if the flow is from confirmation screen of call barring password screen */
            case 2:
                SetLeftSoftkeyFunction(mmi_callset_sel_cb_passwd_next, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmi_callset_sel_cb_passwd_next, KEY_EVENT_UP);
                SetKeyUpHandler(mmi_callset_sel_cb_passwd_next, KEY_POUND);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cb_passwd_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_callset_sim_p->cb_state == 1)
    {
        scrn_id = SCR_ID_CALLSET_CB_PASSWD_NEW;
    }
    else if (mmi_callset_sim_p->cb_state == 2)
    {
        scrn_id = SCR_ID_CALLSET_CB_PASSWD_CNF;
    }
    else
    {
        MMI_ASSERT(0);
    }

    mmi_callset_sim_p->cb_state += 1;

    mmi_frm_scrn_first_enter(
        GRP_ID_CALLSET_CB, 
        scrn_id, 
        (FuncPtr)mmi_callset_entry_cb_passwd, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cb_passwd_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_ss_act_req(SRV_SS_ACT_CALL_BAR, &(mmi_callset_sim_p->cb_info), mmi_callset_sel_cb_opt_cb, NULL);
    mmi_callset_display_error_popup_by_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_callset_sel_cb_opt_cb(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_group_is_present(GRP_ID_CALLSET_CB))
    {
        mmi_frm_group_close(GRP_ID_CALLSET_CB);
    }

    return MMI_RET_OK;
}
#endif  /*__MMI_CALLSET_CALL_BARRING__*/



/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_edit_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    FS editor group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_edit_empty(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_fseditor_set_custom_options_menu(gid, MMI_TRUE, NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_ussr_edit_not_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    FS editor group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_edit_not_empty(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_fseditor_set_custom_options_menu(gid, MMI_FALSE, NULL, 0);
}


#ifdef __MMI_CALLSET_CUG__
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_callset_hide_cug(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_is_available(mmi_callset_sim_p->sim) &&
        srv_callset_is_cug_supported(mmi_callset_sim_p->sim))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CUG, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CUG, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cug
 * DESCRIPTION
 *  entry function for cug
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cug(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer;
    U16 highlite = 0;
    PU8 icon_list[SRV_CALLSET_CUG_MAX_GROUP_NUM];
    PU8 string_list[SRV_CALLSET_CUG_MAX_GROUP_NUM];
    srv_callset_cug_get_item_struct item;
    CHAR ch[5];
    WCHAR w_ch[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
        GRP_ID_CALLSET_COMMON, 
        SCR_ID_CALLSET_CUG_LIST, 
        NULL, 
        mmi_callset_entry_cug, 
        MMI_FRM_UNKNOW_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_CUG_LIST, mmi_callset_proc_cug_list);
        return;
    }

    if (!mmi_callset_sim_p->cug_list)
    {
        mmi_callset_sim_p->cug_list = (mmi_callset_cug_list_struct*)OslMalloc(sizeof(mmi_callset_cug_list_struct));
        mmi_frm_scrn_set_user_data(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_CUG_LIST, mmi_callset_sim_p->cug_list);
        mmi_frm_scrn_set_leave_proc(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_CUG_LIST, mmi_callset_proc_cug_list);
    }

    memset(mmi_callset_sim_p->cug_list, 0, sizeof(mmi_callset_cug_list_struct));
    memset(icon_list, 0, sizeof(icon_list));
    mmi_callset_sim_p->cug_count = 0;
    for (i = 0; i < SRV_CALLSET_CUG_MAX_GROUP_NUM; i++)
    {
        if ((srv_callset_cug_get_item(mmi_callset_sim_p->sim, i, &item) == SRV_CALLSET_RESULT_OK) &&
            (mmi_ucs2strlen((CHAR*)item.name) > 0))
        {
            mmi_ucs2cpy((CHAR*)(mmi_callset_sim_p->cug_list->item[mmi_callset_sim_p->cug_count]), (CHAR*)(item.name));
            mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_count] = i;
            sprintf(ch, " [%d]", i);
            mmi_asc_n_to_ucs2((CHAR*)w_ch, (CHAR*)ch, 4);
            mmi_ucs2ncat((CHAR*)(mmi_callset_sim_p->cug_list->item[mmi_callset_sim_p->cug_count]), (CHAR*)w_ch, 4);

            string_list[mmi_callset_sim_p->cug_count] = (PU8)(mmi_callset_sim_p->cug_list->item[mmi_callset_sim_p->cug_count]);

            if (item.status == SRV_CALLSET_CUG_ACTIVATED)
            {
                icon_list[mmi_callset_sim_p->cug_count] = (PU8)GetImage(IMG_VICON);
            }

            mmi_callset_sim_p->cug_count++;
        }
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    highlite = (mmi_callset_sim_p->cug_input == 0xff) ? (mmi_callset_sim_p->cug_count - 1) : mmi_callset_sim_p->cug_input;
    RegisterHighlightHandler(mmi_callset_hilite_cug);

    if (mmi_callset_sim_p->cug_count == 0)
    {
        /* if the list is empty show empty list */
        string_list[0] = (PU8)GetString(STR_GLOBAL_EMPTY_LIST);
        ShowCategory174Screen(
            (PU8)GetString(STR_ID_CALLSET_CUG),
            (PU8)GetImage(GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING)),
            (PU8)GetString(STR_GLOBAL_ADD),
            (PU8)GetImage(IMG_GLOBAL_OK),
            (PU8)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            1,
            (U8**)string_list,
            (U8**)icon_list,
            NULL,
            0,
            highlite,
            guiBuffer);

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        mmi_callset_p->tap_cb = mmi_callset_hdlr_cug_add;
        wgui_register_tap_callback(mmi_callset_tap_cb);
    #endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
        
        SetLeftSoftkeyFunction(mmi_callset_hdlr_cug_add, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_callset_hdlr_cug_add, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory174Screen(
            (PU8)GetString(STR_ID_CALLSET_CUG),
            (PU8)GetImage(GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING)),
            (PU8)GetString(STR_GLOBAL_OPTIONS),
            (PU8)GetImage(IMG_GLOBAL_OPTIONS),
            (PU8)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            mmi_callset_sim_p->cug_count,
            (U8 **)string_list,
            (U8 **)icon_list,
            NULL,
            0,
            highlite,
            guiBuffer);

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        mmi_callset_p->tap_cb = mmi_callset_hdlr_cug_name_edit;
        wgui_register_tap_callback(mmi_callset_tap_cb);
    #endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

        SetLeftSoftkeyFunction(mmi_callset_create_cug_opt, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_callset_hdlr_cug_name_edit, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_cug_list
 * DESCRIPTION
 *  proc of SCR_ID_CALLSET_CUG_LIST
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_callset_proc_cug_list(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            mmi_callset_sim_p->cug_input = 0;
            mmi_callset_sim_p->cug_list = NULL;
            MMI_ASSERT(evt->user_data);
            OslMfree(evt->user_data);
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_cug
 * DESCRIPTION
 *  highlight handler for cug
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_cug(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_sim_p->cug_input = (U8)index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_cug_opt
 * DESCRIPTION
 *  create the option menu of cug
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_cug_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(GRP_ID_CALLSET_COMMON, MENU_ID_CALLSET_CUG_OPT, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cug_opt(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_cug_get_item_struct item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_callset_sim_p->cug_count >= SRV_CALLSET_CUG_MAX_GROUP_NUM)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CUG_ADD, MMI_TRUE);
    }
    if (srv_callset_cug_get_item(
            mmi_callset_sim_p->sim, 
            mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input],
            &item) == SRV_CALLSET_RESULT_OK)
    {
        if (!mmi_ucs2strlen((CHAR*)item.name))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CUG_ACTIVATE, MMI_TRUE);
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CUG_DEACTIVATE, MMI_TRUE);
        }
        else if (item.status == SRV_CALLSET_CUG_ACTIVATED)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CUG_ACTIVATE, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_CUG_DEACTIVATE, MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cug_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cug_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_CUG_EDIT:
            mmi_callset_entry_cug_name_edit();
            break;

        case MENU_ID_CALLSET_CUG_ADD:
            mmi_callset_sim_p->cug_input = 0xff;
            mmi_callset_entry_cug_name_edit();
            break;

        case MENU_ID_CALLSET_CUG_ACTIVATE:
            mmi_callset_sel_cug_activate();
            break;

        case MENU_ID_CALLSET_CUG_DEACTIVATE:
            mmi_callset_sel_cug_deactivate();
            break;

        case MENU_ID_CALLSET_CUG_DELETE:
            mmi_callset_sel_cug_delete();
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hdlr_cug_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hdlr_cug_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_sim_p->cug_input = 0xff;
    mmi_callset_entry_cug_name_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cug_name_edit
 * DESCRIPTION
 *  entry function for cug name edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hdlr_cug_name_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_entry_cug_name_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cug_name_edit
 * DESCRIPTION
 *  entry function for cug name edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cug_name_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    srv_callset_cug_get_item_struct item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gid = cui_fseditor_create(GRP_ID_CALLSET_COMMON);
    mmi_callset_sim_p->cug_name_edit_gid = gid;

    memset(&item, 0, sizeof(item));
    if (mmi_callset_sim_p->cug_input != 0xff)
    {
        MMI_ASSERT(mmi_callset_sim_p->cug_input < mmi_callset_sim_p->cug_count);
        srv_callset_cug_get_item(
            mmi_callset_sim_p->sim, 
            mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input], 
            &item);
    }
    
    cui_fseditor_set_text(gid, item.name, sizeof(item.name), SRV_CALLSET_CUG_MAX_NAME_LENGTH);
    cui_fseditor_set_title(gid, STR_GLOBAL_EDIT, GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
    cui_fseditor_set_input_method(gid, IMM_INPUT_TYPE_SENTENCE, NULL, 0);
    cui_fseditor_run(gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cug_num_edit_done
 * DESCRIPTION
 *  entry function for cug edit done screen
 * PARAMETERS
 *  gid     [IN]    editor gid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cug_name_edit_done(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_entry_cug_id_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cug_id_edit
 * DESCRIPTION
 *  entry function for cug id edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_cug_id_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    WCHAR cug_id_str[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gid = cui_fseditor_create(GRP_ID_CALLSET_COMMON);
    mmi_callset_sim_p->cug_id_edit_gid = gid;

    memset(cug_id_str, 0, sizeof(cug_id_str));
    if (mmi_callset_sim_p->cug_input != 0xff)
    {
        MMI_ASSERT(mmi_callset_sim_p->cug_input < mmi_callset_sim_p->cug_count);
        app_ucs2_itoa((S32)mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input], (kal_int8*)cug_id_str, 10);
    }
    
    cui_fseditor_set_text(gid, cug_id_str, sizeof(cug_id_str), 1);
    cui_fseditor_set_title(gid, STR_ID_CALLSET_CUG_EDIT_INDEX, GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
    cui_fseditor_set_input_method(gid, IMM_INPUT_TYPE_NUMERIC, NULL, 0);
    cui_fseditor_run(gid);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cug_id_edit_done
 * DESCRIPTION
 *  entry function for cug edit done screen
 * PARAMETERS
 *  gid     [IN]    editor gid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cug_id_edit_done(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_cug_get_item_struct get_item;
    srv_callset_cug_set_item_struct set_item;
    WCHAR cui_id_str[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&get_item, 0, sizeof(srv_callset_cug_get_item_struct));
    memset(&set_item, 0, sizeof(srv_callset_cug_set_item_struct));
    memset(cui_id_str, 0, sizeof(cui_id_str));

    cui_fseditor_get_text(gid, cui_id_str, sizeof(cui_id_str));
    set_item.cug_id = (U8)app_ucs2_atoi((kal_int8*)cui_id_str);

    if (mmi_callset_sim_p->cug_input == 0xff)
    {
        /* add */
        if ((set_item.cug_id >= SRV_CALLSET_CUG_MAX_GROUP_NUM) ||
            (srv_callset_cug_get_item(mmi_callset_sim_p->sim, set_item.cug_id, &get_item) != SRV_CALLSET_RESULT_OK))
        {
            mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
            return;
        }

        if (mmi_ucs2strlen((CHAR*)get_item.name) || (get_item.status != SRV_CALLSET_CUG_DEACTIVATED))
        {
            mmi_callset_display_error_popup(STR_ID_CALLSET_CUG_INDEX_IN_USE);
            return;
        }

        cui_fseditor_get_text(mmi_callset_sim_p->cug_name_edit_gid, set_item.name, sizeof(set_item.name));
        if (srv_callset_cug_set_item(mmi_callset_sim_p->sim, &set_item) != SRV_CALLSET_RESULT_OK)
        {
            mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
        }
        else
        {
            mmi_popup_display_simple_ext(
                STR_GLOBAL_SAVED, 
                MMI_EVENT_SUCCESS,
                GRP_ID_ROOT,
                NULL);
            mmi_callset_close_fseditor(mmi_callset_sim_p->cug_name_edit_gid);
            mmi_callset_close_fseditor(gid);
        }
    }
    else
    {
        /* modify */
        if (set_item.cug_id == mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input])
        {
            /* cug id is not changed */
            cui_fseditor_get_text(mmi_callset_sim_p->cug_name_edit_gid, set_item.name, sizeof(set_item.name));
            if (srv_callset_cug_set_item(mmi_callset_sim_p->sim, &set_item) != SRV_CALLSET_RESULT_OK)
            {
                mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
            }
            else
            {
                mmi_popup_display_simple_ext(
                    STR_GLOBAL_SAVED,
                    MMI_EVENT_SUCCESS,
                    GRP_ID_ROOT,
                    NULL);
                mmi_callset_close_fseditor(mmi_callset_sim_p->cug_name_edit_gid);
                mmi_callset_close_fseditor(gid);
            }
        }
        else
        {
            /* cug id is changed */
            /* check the original item */
            set_item.cug_id = mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input];
            if (srv_callset_cug_get_item(
                    mmi_callset_sim_p->sim, 
                    set_item.cug_id, 
                    &get_item) != SRV_CALLSET_RESULT_OK)
            {
                mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
                return;
            }
            if (get_item.status != SRV_CALLSET_CUG_DEACTIVATED)
            {
                mmi_callset_display_error_popup(STR_ID_CALLSET_CUG_DEACT_FIRST);
                return;
            }

            /* check the target item */
            set_item.cug_id = (U8)app_ucs2_atoi((kal_int8*)cui_id_str);
            if ((set_item.cug_id >= SRV_CALLSET_CUG_MAX_GROUP_NUM) ||
                (srv_callset_cug_get_item(mmi_callset_sim_p->sim, set_item.cug_id, &get_item) != SRV_CALLSET_RESULT_OK))
            {
                mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
                return;
            }
            if (mmi_ucs2strlen((CHAR*)get_item.name) || (get_item.status != SRV_CALLSET_CUG_DEACTIVATED))
            {
                mmi_callset_display_error_popup(STR_ID_CALLSET_CUG_INDEX_IN_USE);
                return;
            }

            /* reset the original item */
            set_item.cug_id = mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input];
            memset(set_item.name, 0, sizeof(set_item.name));
            if (srv_callset_cug_set_item(mmi_callset_sim_p->sim, &set_item) != SRV_CALLSET_RESULT_OK)
            {
                mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
                return;
            }

            /* set the target item */
            set_item.cug_id = (U8)app_ucs2_atoi((kal_int8*)cui_id_str);
            cui_fseditor_get_text(mmi_callset_sim_p->cug_name_edit_gid, set_item.name, sizeof(set_item.name));
            if (srv_callset_cug_set_item(mmi_callset_sim_p->sim, &set_item) != SRV_CALLSET_RESULT_OK)
            {
                mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
            }
            else
            {
                mmi_popup_display_simple_ext(
                    STR_GLOBAL_SAVED, 
                    MMI_EVENT_SUCCESS,
                    GRP_ID_ROOT,
                    NULL);
                mmi_callset_close_fseditor(mmi_callset_sim_p->cug_name_edit_gid);
                mmi_callset_close_fseditor(gid);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_cug_name_edit
 * DESCRIPTION
 *  entry function for cug name edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hdlr_cug_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_sel_cug_activate();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cug_activate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cug_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_cug_activate_struct act_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyDownHandler(0, KEY_END);

    act_info.sim = mmi_callset_sim_p->sim;
    act_info.cug_id = mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input];
    
    srv_callset_cug_activate(&act_info, mmi_callset_sel_cug_activate_cb, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cug_activate_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_callset_sel_cug_activate_cb(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_struct *data = (srv_callset_result_struct*)(((srv_callset_rsp_evt_struct*)info)->data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data->result == SRV_CALLSET_RESULT_OK)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_ACTIVATED, 
            MMI_EVENT_SUCCESS,
            GRP_ID_ROOT,
            NULL);
    }
    else /* fail */
    {
        mmi_popup_display_simple_ext(
            srv_callset_get_result_string_id(data->result),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cug_deactivate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cug_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_cug_deactivate_struct act_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyDownHandler(0, KEY_END);

    act_info.sim = mmi_callset_sim_p->sim;
    act_info.cug_id = mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input];
    
    srv_callset_cug_deactivate(&act_info, mmi_callset_sel_cug_deactivate_cb, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cug_deactivate_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_callset_sel_cug_deactivate_cb(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_struct *data = (srv_callset_result_struct*)(((srv_callset_rsp_evt_struct*)info)->data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data->result == SRV_CALLSET_RESULT_OK)
    {
        mmi_popup_display_simple_ext(
            STR_ID_CALLSET_DEACTIVATED, 
            MMI_EVENT_SUCCESS,
            GRP_ID_ROOT,
            NULL);
    }
    else /* fail */
    {
        mmi_popup_display_simple_ext(
            srv_callset_get_result_string_id(data->result),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_cug_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_cug_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_cug_get_item_struct get_item;
    srv_callset_cug_set_item_struct set_item;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_cug_get_item(
            mmi_callset_sim_p->sim, 
            mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input], 
            &get_item) != SRV_CALLSET_RESULT_OK)
    {
        mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
        return;
    }
    
    if (get_item.status != SRV_CALLSET_CUG_DEACTIVATED)
    {
        mmi_callset_display_error_popup(STR_ID_CALLSET_CUG_DEACT_FIRST);
        return;
    }
    
    set_item.cug_id = mmi_callset_sim_p->cug_map[mmi_callset_sim_p->cug_input];
    memset(set_item.name, 0, sizeof(set_item.name));
    
    if (srv_callset_cug_set_item(mmi_callset_sim_p->sim, &set_item) != SRV_CALLSET_RESULT_OK)
    {
        mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_DELETED, 
            MMI_EVENT_SUCCESS,
            GRP_ID_ROOT,
            NULL);
        
        for (i = (mmi_callset_sim_p->cug_input); i < SRV_CALLSET_CUG_MAX_GROUP_NUM; i++)
        {
            mmi_callset_sim_p->cug_map[i] = mmi_callset_sim_p->cug_map[i + 1];
            if (mmi_callset_sim_p->cug_map[i] == 0xff)
            {
                break;
            }
        }
        
        mmi_callset_sim_p->cug_count--;
    }
}
#endif /* __MMI_CALLSET_CUG__ */


#ifdef __MMI_CALLSET_AUTO_REDIAL__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_auto_redial
 * DESCRIPTION
 *  highlight handler for auto redial menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_auto_redial(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_auto_redial_get_mode())
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_AUTOREDIAL, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_AUTOREDIAL, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_auto_redial_mode
 * DESCRIPTION
 *  start auto redial mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_auto_redial_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_AUTOREDIAL_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_auto_redial_mode
 * DESCRIPTION
 *  entry handler for auto redial mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_auto_redial_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_auto_redial_get_mode())
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_auto_redial_mode
 * DESCRIPTION
 *  select handler for auto redial mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_auto_redial_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_ON)
    {
        srv_callset_auto_redial_set_mode(MMI_TRUE);
    }
    else if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_OFF)
    {
        srv_callset_auto_redial_set_mode(MMI_FALSE);
    }

    mmi_callset_display_popup_by_cause(SRV_CALLSET_RESULT_OK);
    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}
#endif /* __MMI_CALLSET_AUTO_REDIAL__ */


#ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_ctd
 * DESCRIPTION
 *  highlight handler for call time display menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_ctd(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_call_time_display_get_mode())
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CTD, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CTD, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_ctd_mode
 * DESCRIPTION
 *  create call time display mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_ctd_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_CTD_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_ctd_mode
 * DESCRIPTION
 *  entry handler for call time display mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ctd_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_call_time_display_get_mode())
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_ctd_mode
 * DESCRIPTION
 *  select handler for call time display mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_ctd_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_ON)
    {
        srv_callset_call_time_display_set_mode(MMI_TRUE);
    }
    else if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_OFF)
    {
        srv_callset_call_time_display_set_mode(MMI_FALSE);
    }

    mmi_callset_display_popup_by_cause(SRV_CALLSET_RESULT_OK);
    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}
#endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */


#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_ctr
 * DESCRIPTION
 *  highlight handler for call time reminder menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_ctr(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ctr_struct setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (SRV_CALLSET_RESULT_OK == srv_callset_ctr_get_mode(&setting))
    {
        switch (setting.mode)
        {
            case SRV_CALLSET_CTR_MODE_OFF:
                cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CTR, get_string(STR_GLOBAL_OFF));
                break;

            case SRV_CALLSET_CTR_MODE_SINGLE:
                cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CTR, get_string(STR_ID_CALLSET_CTR_SING));
                break;

            case SRV_CALLSET_CTR_MODE_PERIODIC:
                cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CTR, get_string(STR_ID_CALLSET_CTR_PERIOD));
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_ctr_mode
 * DESCRIPTION
 *  create call time reminder mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_ctr_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create_ex(GRP_ID_CALLSET_COMMON, GRP_ID_CALLSET_CTR, mmi_callset_proc_ctr, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_callset_common_create_cui(GRP_ID_CALLSET_CTR, MENU_ID_CALLSET_CTR_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_ctr_mode
 * DESCRIPTION
 *  entry handler for call time reminder mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ctr_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ctr_struct ctr_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_p->ctr_mode_input = (srv_callset_ctr_mode_enum)0xff;

    memset(&ctr_info, 0, sizeof(ctr_info));
    srv_callset_ctr_get_mode(&ctr_info);

    switch(ctr_info.mode)
    {
        case SRV_CALLSET_CTR_MODE_SINGLE:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CTR_SINGLE);
            break;
        case SRV_CALLSET_CTR_MODE_PERIODIC:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CTR_PERIODIC);
            break;
        default:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_ctr_mode
 * DESCRIPTION
 *  select handler for call time reminder mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_ctr_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_callset_ctr_struct ctr_info;
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_OFF:
            mmi_callset_p->ctr_mode_input = SRV_CALLSET_CTR_MODE_OFF;
            break;
        case MENU_ID_CALLSET_CTR_SINGLE:
            mmi_callset_p->ctr_mode_input = SRV_CALLSET_CTR_MODE_SINGLE;
            break;
        case MENU_ID_CALLSET_CTR_PERIODIC:
            mmi_callset_p->ctr_mode_input = SRV_CALLSET_CTR_MODE_PERIODIC;
            break;
        default:
            break;
    }

    if (mmi_callset_p->ctr_mode_input == SRV_CALLSET_CTR_MODE_OFF)
    {
        memset(&ctr_info, 0, sizeof(ctr_info));
        ctr_info.mode = mmi_callset_p->ctr_mode_input;

        result = srv_callset_ctr_set_mode(&ctr_info);
        mmi_callset_display_popup_by_cause(result);
        mmi_frm_group_close(GRP_ID_CALLSET_CTR);
    }
    else
    {
        /* init ctr_time_input before first enter */
        if (srv_callset_ctr_get_mode(&ctr_info) != SRV_CALLSET_RESULT_OK)
        {
            memset(&ctr_info, 0, sizeof(ctr_info));
            ctr_info.mode = SRV_CALLSET_CTR_MODE_OFF;
        }

        if ((ctr_info.time) &&
            (ctr_info.mode == mmi_callset_p->ctr_mode_input))
        {
            app_ucs2_itoa((S32)(ctr_info.time), (kal_int8*)(mmi_callset_p->ctr_time_input), 10);
        }

        mmi_frm_scrn_first_enter(
            GRP_ID_CALLSET_CTR, 
            SCR_ID_CALLSET_CTR_TIME, 
            (FuncPtr)mmi_callset_entry_ctr_time, 
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_ctr_time
 * DESCRIPTION
 *  proc of SCR_ID_CALLSET_WL_PHN_PASSWD
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_callset_proc_ctr_time(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            memset(mmi_callset_p->ctr_time_input, 0, sizeof(mmi_callset_p->ctr_time_input));
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_ctr_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ctr_time(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U16 message_id = STR_ID_CALLSET_CTR_RANGE_PERIODIC;
    S32 buffer_size = 3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
        data->group_id, 
        data->scrn_id, 
        NULL, 
        (FuncPtr)mmi_callset_entry_ctr_time, 
        MMI_FRM_UNKNOW_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_callset_proc_ctr_time);
        return;
    }

    mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_callset_proc_ctr_time);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if ((mmi_callset_p->ctr_mode_input) == SRV_CALLSET_CTR_MODE_SINGLE)
    {
        message_id = STR_ID_CALLSET_CTR_RANGE_SING;
        buffer_size = 5;
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
#else
    ShowCategory111Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            STR_ID_CALLSET_CTR_TIME,
            IMM_INPUT_TYPE_NUMERIC,
            (PU8)(mmi_callset_p->ctr_time_input),
            buffer_size,
            (PU8)GetString(message_id),
            guiBuffer);
#endif

    SetLeftSoftkeyFunction(mmi_callset_sel_ctr_edit_done, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_callset_sel_ctr_edit_done, KEY_EVENT_UP);
    SetCategory69RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_ctr_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_ctr_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL err = MMI_FALSE;
    srv_callset_ctr_struct req;
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_callset_p->ctr_mode_input == SRV_CALLSET_CTR_MODE_SINGLE)
    {
        if (app_ucs2_atoi((kal_int8*)(mmi_callset_p->ctr_time_input)) < SRV_CALLSET_CTR_MIN_SINGLE_TIME ||
            app_ucs2_atoi((kal_int8*)(mmi_callset_p->ctr_time_input)) > SRV_CALLSET_CTR_MAX_SINGLE_TIME)
        {
            err = MMI_TRUE;
        }
    }
    else if(mmi_callset_p->ctr_mode_input == SRV_CALLSET_CTR_MODE_PERIODIC)
    {
        if (app_ucs2_atoi((kal_int8*)(mmi_callset_p->ctr_time_input)) < SRV_CALLSET_CTR_MIN_PERIODIC_TIME ||
            app_ucs2_atoi((kal_int8*)(mmi_callset_p->ctr_time_input)) > SRV_CALLSET_CTR_MAX_PERIODIC_TIME)
        {
            err = MMI_TRUE;
        }
    }

    if (!mmi_ucs2strlen((CHAR*)(mmi_callset_p->ctr_time_input)))
    {
        err = MMI_TRUE;
    }

    if (err)
    {
        mmi_callset_display_error_popup(STR_GLOBAL_INVALID);
        mmi_frm_scrn_clean_gui_buf(GRP_ID_CALLSET_CTR, SCR_ID_CALLSET_CTR_TIME);
        mmi_frm_scrn_clean_input_buf(GRP_ID_CALLSET_CTR, SCR_ID_CALLSET_CTR_TIME);
    }
    else
    {
        memset(&req, 0, sizeof(req));
        req.mode = mmi_callset_p->ctr_mode_input;
        req.time = app_ucs2_atoi((kal_int8*)(mmi_callset_p->ctr_time_input));

        result = srv_callset_ctr_set_mode(&req);
        mmi_callset_display_popup_by_cause(result);
        mmi_frm_group_close(GRP_ID_CALLSET_CTR);
    }
}
#endif /*__MMI_CALLSET_CALLTIME_REMINDER__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_ans_mode_opt
 * DESCRIPTION
 *  create answer mode option menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_ans_mode_opt(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_ANS_MODE_OPT, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_ans_mode_opt
 * DESCRIPTION
 *  entry handler for answer mode option menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ans_mode_opt(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_answer_mode_enum mode;
    U8 state[3];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(state, 0, sizeof(state));
    mode = srv_callset_answer_mode_get_mode();

#ifdef __MMI_CLAMSHELL__
    if (mode & SRV_CALLSET_ANSWER_MODE_CLAMSHELL)
    {
        index = cui_menu_get_index_in_currlist_from_menu_id(menu_gid, MENU_ID_CALLSET_ANS_MODE_CLAMSHELL);
        MMI_ASSERT(index <= 3);
        state[index] = 1;
    }
#endif /* __MMI_CLAMSHELL__ */

    if (mode & SRV_CALLSET_ANSWER_MODE_ANYKEY)
    {
        index = cui_menu_get_index_in_currlist_from_menu_id(menu_gid, MENU_ID_CALLSET_ANS_MODE_ANYKEY);
        MMI_ASSERT(index <= 3);
        state[index] = 1;
    }

#if 0
#if !defined(__OP01_FWPBW__) && !defined(__MMI_MAINLCD_96X64__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP01_FWPBW__ */
#else
  #ifndef __MMI_MAINLCD_96X64__
    if (mode & SRV_CALLSET_ANSWER_MODE_AUTO)
    {
        index = cui_menu_get_index_in_currlist_from_menu_id(menu_gid, MENU_ID_CALLSET_ANS_MODE_AUTO);
        MMI_ASSERT(index <= 3);
        state[index] = 1;
    }
  #endif /* __MMI_MAINLCD_96X64__ */
#endif

    cui_menu_set_checkbox_state(menu_gid, state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_ans_mode_opt
 * DESCRIPTION
 *  select handler for answer mode option menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_ans_mode_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    S32 index;
    U8 state[3];
    srv_callset_answer_mode_enum mode = SRV_CALLSET_ANSWER_MODE_OFF;
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(cui_menu_get_currlist_item_count(menu_evt->sender_id) <= 3);

    memset(state, 0, sizeof(state));
    cui_menu_get_checkbox_state(menu_evt->sender_id, state);

#ifdef __MMI_CLAMSHELL__
    index = cui_menu_get_index_in_currlist_from_menu_id(menu_evt->sender_id, MENU_ID_CALLSET_ANS_MODE_CLAMSHELL);
    MMI_ASSERT(index <= 3);
    if (state[index])
    {
        mode |= SRV_CALLSET_ANSWER_MODE_CLAMSHELL;
    }
#endif /* __MMI_CLAMSHELL__ */

    index = cui_menu_get_index_in_currlist_from_menu_id(menu_evt->sender_id, MENU_ID_CALLSET_ANS_MODE_ANYKEY);
    MMI_ASSERT(index <= 3);
    if (state[index])
    {
        mode |= SRV_CALLSET_ANSWER_MODE_ANYKEY;
    }

#if 0
#if !defined(__OP01_FWPBW__) && !defined(__MMI_MAINLCD_96X64__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP01_FWPBW__ */
#else
  #ifndef __MMI_MAINLCD_96X64__
    index = cui_menu_get_index_in_currlist_from_menu_id(menu_evt->sender_id, MENU_ID_CALLSET_ANS_MODE_AUTO);
    MMI_ASSERT(index <= 3);
    if (state[index])
    {
        mode |= SRV_CALLSET_ANSWER_MODE_AUTO;
    }
  #endif /* __MMI_MAINLCD_96X64__ */
#endif

    result = srv_callset_answer_mode_set_mode(mode);
    mmi_callset_display_popup_by_cause(result);
    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}


#ifdef __MMI_UCM_REJECT_BY_SMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_rej_by_sms
 * DESCRIPTION
 *  highlight handler for reject by sms menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_rej_by_sms(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_reject_by_sms_get_mode())
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_REJ_BY_SMS, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_REJ_BY_SMS, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_rej_by_sms_mode
 * DESCRIPTION
 *  create reject by sms mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_rej_by_sms_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_REJ_BY_SMS_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_rej_by_sms_mode
 * DESCRIPTION
 *  entry handler for reject by sms mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_rej_by_sms_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_reject_by_sms_get_mode())
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_rej_by_sms_mode
 * DESCRIPTION
 *  select handler for reject by sms mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_rej_by_sms_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_ON)
    {
        srv_callset_reject_by_sms_set_mode(MMI_TRUE);
    }
    else if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_OFF)
    {
        srv_callset_reject_by_sms_set_mode(MMI_FALSE);
    }

    mmi_callset_display_popup_by_cause(SRV_CALLSET_RESULT_OK);

    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


#ifdef __MMI_CONNECT_NOTICE__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_connect_notice
 * DESCRIPTION
 *  highlight handler for connect notice menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_connect_notice(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_connect_notice_get_mode())
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CONNECT_NOTICE, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CONNECT_NOTICE, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_connect_notice_mode
 * DESCRIPTION
 *  create connect notice mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_connect_notice_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_CONNECT_NOTICE_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_connect_notice_mode
 * DESCRIPTION
 *  entry handler for connect notice mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_connect_notice_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_connect_notice_get_mode())
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_connect_notice_mode
 * DESCRIPTION
 *  select handler for connect notice mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_connect_notice_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_ON)
    {
        srv_callset_connect_notice_set_mode(MMI_TRUE);
    }
    else if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_OFF)
    {
        srv_callset_connect_notice_set_mode(MMI_FALSE);
    }

    mmi_callset_display_popup_by_cause(SRV_CALLSET_RESULT_OK);

    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}
#endif /* __MMI_CONNECT_NOTICE__ */


#ifdef __MMI_CALLSET_LINE_SWITCHING__
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_callset_hide_lsw(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_is_available(mmi_callset_sim_p->sim) &&
        srv_callset_is_line_switch_supported(mmi_callset_sim_p->sim))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_LINE_SWITCH, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_LINE_SWITCH, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_lsw
 * DESCRIPTION
 *  highlight handler for line switch menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_lsw(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (SRV_CALLSET_LINE1 == srv_callset_line_switch_get_id(mmi_callset_p->target_sim))
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_LINE_SWITCH, get_string(STR_ID_CALLSET_LSW_LINE1));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_LINE_SWITCH, get_string(STR_ID_CALLSET_LSW_LINE2));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_lsw_mode
 * DESCRIPTION
 *  create line switch mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_lsw_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_LINE_SWITCH_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_lsw_mode
 * DESCRIPTION
 *  entry handler for line switch mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_lsw_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_line_switch_get_id(mmi_callset_p->target_sim) == SRV_CALLSET_LINE1)
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_LSW_LINE1);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_LSW_LINE2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_lsw_mode
 * DESCRIPTION
 *  select handler for line switch mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_lsw_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_callset_line_switch_struct line_info;
    MMI_ID *menu_gid_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&line_info, 0, sizeof(srv_callset_line_switch_struct));
    line_info.sim = mmi_callset_p->target_sim;
    
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_LSW_LINE1:
            line_info.line_id = SRV_CALLSET_LINE1;
            break;
        case MENU_ID_CALLSET_LSW_LINE2:
            line_info.line_id = SRV_CALLSET_LINE2;
            break;
        default:
            return;
    }

    menu_gid_p = OslMalloc(sizeof(MMI_ID));
    memcpy(menu_gid_p, &(menu_evt->sender_id), sizeof(MMI_ID));

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyDownHandler(0, KEY_END);

    srv_callset_line_switch_set_id(&line_info, mmi_callset_sel_lsw_mode_cb, menu_gid_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_lsw_mode_cb
 * DESCRIPTION
 *  callback handler for line switch result
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_callset_sel_lsw_mode_cb(mmi_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_struct *data = (srv_callset_result_struct*)(((srv_callset_rsp_evt_struct*)info)->data);
    MMI_ID *menu_gid_p = (MMI_ID*)(info->user_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(menu_gid_p);

    mmi_callset_display_popup_by_cause(data->result);

    if (mmi_frm_group_is_present(*menu_gid_p))
    {
        mmi_callset_close_menu(*menu_gid_p, cui_menu_get_app_parent_data(*menu_gid_p));
    }

    OslMfree(menu_gid_p);

    return MMI_RET_OK;
}
#endif /* __MMI_CALLSET_LINE_SWITCHING__*/


#ifdef __MMI_NCENTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_mode_switch_hdlr
 * DESCRIPTION
 *  handler for mode switch indication
 * PARAMETERS
 *  evt    [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_callset_mode_switch_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *mode_status = (srv_mode_switch_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY == evt->evt_id)
    {
        if (SRV_MODE_SWITCH_ON == mode_status->select_flight_mode)
        {
            mmi_callset_close_all();
        }
    }

    return MMI_RET_OK;
}
#endif /* __MMI_NCENTER_SUPPORT__ */


#ifdef __IP_NUMBER__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_ip_num_list
 * DESCRIPTION
 *  proc of SCR_ID_CALLSET_IP_NUMBER
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_callset_proc_ip_num_list(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            mmi_callset_p->ip_number_input = 0;
            MMI_ASSERT(evt->user_data);
            OslMfree(evt->user_data);
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_first_entry_ip_number_list
 * DESCRIPTION
 *  first entry function for ip number list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_first_entry_ip_number_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_callset_ip_number_list_struct *ip_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ip_num = (mmi_callset_ip_number_list_struct*)OslMalloc(sizeof(mmi_callset_ip_number_list_struct));

    mmi_frm_scrn_first_enter(
        GRP_ID_CALLSET_COMMON, 
        SCR_ID_CALLSET_IP_NUMBER, 
        (FuncPtr)mmi_callset_entry_ip_number_list, 
        ip_num);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_ip_number_list
 * DESCRIPTION
 *  entry function for ip number list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ip_number_list(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 highlite = 0;
    U8 *guiBuffer;
    mmi_callset_ip_number_list_struct *ip_num;
    PU8 icon_list[SRV_CALLSET_MAX_IP_NUMBER];
    PU8 string_list[SRV_CALLSET_MAX_IP_NUMBER];

#if (MMI_MAX_SIM_NUM >= 2)
    U8 array_index;
    srv_mode_switch_type_enum usable_side;
    U16 icon_array[] ={0,IMG_ID_CALLSET_VICON_SIM1,IMG_ID_CALLSET_VICON_SIM2,IMG_ID_CALLSET_VICON_BOTH
                    #if (MMI_MAX_SIM_NUM>=3)
                        ,IMG_ID_CALLSET_VICON_SIM3,IMG_ID_CALLSET_VICON_SIM1_SIM3,
                        IMG_ID_CALLSET_VICON_SIM2_SIM3,IMG_ID_CALLSET_VICON_SIM1_SIM2_SIM3
                    #if (MMI_MAX_SIM_NUM>=4) 
                        ,IMG_ID_CALLSET_VICON_SIM4,IMG_ID_CALLSET_VICON_SIM1_SIM4,IMG_ID_CALLSET_VICON_SIM2_SIM4,IMG_ID_CALLSET_VICON_SIM1_SIM2_SIM4,
                        IMG_ID_CALLSET_VICON_SIM3_SIM4,IMG_ID_CALLSET_VICON_SIM1_SIM3_SIM4,IMG_ID_CALLSET_VICON_SIM2_SIM3_SIM4,IMG_ID_CALLSET_VICON_SIM1_SIM2_SIM3_SIM4
                    #endif
                    #endif
                    }; 
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
        data->group_id, 
        data->scrn_id, 
        NULL, 
        (FuncPtr)mmi_callset_entry_ip_number_list, 
        MMI_FRM_UNKNOW_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_callset_proc_ip_num_list);
        return;
    }

    mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_callset_proc_ip_num_list);

    MMI_ASSERT(data->user_data);

    ip_num = (mmi_callset_ip_number_list_struct*)(data->user_data);
    memset(ip_num, 0, sizeof(mmi_callset_ip_number_list_struct));

    memset(icon_list, 0, sizeof(icon_list));

    for (i = 0; i < SRV_CALLSET_MAX_IP_NUMBER; i++)
    {
        srv_callset_ip_number_get_item(i, &(ip_num->setting[i]));

        if (mmi_ucs2strlen((CHAR*)(ip_num->setting[i].number)))
        {
            string_list[i] = (PU8)(ip_num->setting[i].number);
        }
        else
        {
            string_list[i] = (PU8)GetString(STR_GLOBAL_EMPTY_LIST);
        }

    #if (MMI_MAX_SIM_NUM >= 2)
        usable_side = srv_mode_switch_get_current_mode();
        array_index = (usable_side & ip_num->setting[i].status);
        icon_list[i] = (PU8)GetImage(icon_array[array_index]);
    #else /*  (MMI_MAX_SIM_NUM >= 2)*/
        if (ip_num->setting[i].status & SRV_CALLSET_IP_NUMBER_SIM1_ACTIVATED)
        {
            icon_list[i] = (PU8)GetImage(IMG_VICON);
        }
    #endif /*  (MMI_MAX_SIM_NUM >= 2) */
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    highlite = mmi_callset_p->ip_number_input;
    RegisterHighlightHandler(mmi_callset_hilite_ip_number_list);
    
    ShowCategory174Screen(
        (PU8)GetString(STR_ID_CALLSET_IP_NUMBER),
        (PU8)GetImage(GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING)),
        (PU8)GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (PU8)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        SRV_CALLSET_MAX_IP_NUMBER,
        (U8 **)string_list,
        (U8 **)icon_list,
        NULL,
        0,
        highlite,
        guiBuffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_callset_p->tap_cb = mmi_callset_entry_ip_number_list_edit;
    wgui_register_tap_callback(mmi_callset_tap_cb);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    SetLeftSoftkeyFunction(mmi_callset_create_ip_number_list_opt, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    SetCenterSoftkeyFunction(mmi_callset_create_ip_number_list_opt, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_ip_number_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_ip_number_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_p->ip_number_input = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_ip_number_list_opt
 * DESCRIPTION
 *  create the option menu of ip number list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_ip_number_list_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(GRP_ID_CALLSET_COMMON, MENU_ID_CALLSET_IP_NUMBER_OPT, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_ip_number_list_opt
 * DESCRIPTION
 *  entry function of the ip number list option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ip_number_list_opt(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ip_number_item_struct item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check sim mode */
    if (!srv_mode_switch_is_network_service_available() ||
		!srv_mode_switch_get_current_mode())
    {
	#if  (MMI_MAX_SIM_NUM < 2)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_ACTIVATE_SIM1, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_DEACTIVATE_SIM1, MMI_TRUE);
	#else
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_ACTIVATE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_DEACTIVATE, MMI_TRUE);
    #endif /*  (MMI_MAX_SIM_NUM >= 2) */
    }

#if  (MMI_MAX_SIM_NUM < 2)
	if (!srv_sim_ctrl_is_inserted(MMI_SIM1))
	{
		cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_ACTIVATE_SIM1, MMI_TRUE);
		cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_DEACTIVATE_SIM1, MMI_TRUE);
	}
#endif

    /* check if the number is empty */
    if ((srv_callset_ip_number_get_item((U8)(mmi_callset_p->ip_number_input), &item) != SRV_CALLSET_RESULT_OK) ||
        !mmi_ucs2strlen((CHAR*)(item.number)))
    {
#if (MMI_MAX_SIM_NUM >= 2)
		cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_ACTIVATE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_DEACTIVATE, MMI_TRUE);
#else
		cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_ACTIVATE_SIM1, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_DEACTIVATE_SIM1, MMI_TRUE);
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (1 == srv_sim_ctrl_get_num_of_inserted())
    {
        cui_menu_set_non_leaf_item(menu_gid, MENU_ID_CALLSET_IP_ACTIVATE, MMI_FALSE);
        cui_menu_set_non_leaf_item(menu_gid, MENU_ID_CALLSET_IP_DEACTIVATE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_non_leaf_item(menu_gid, MENU_ID_CALLSET_IP_ACTIVATE, MMI_TRUE);
        cui_menu_set_non_leaf_item(menu_gid, MENU_ID_CALLSET_IP_DEACTIVATE, MMI_TRUE);
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
}


void mmi_callset_entry_ip_number_list_sub_opt(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if (MMI_MAX_SIM_NUM >= 2)
	srv_mode_switch_type_enum usable_side;
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (MMI_MAX_SIM_NUM >= 2)
	usable_side = srv_mode_switch_get_current_mode();
    
    if(!(usable_side & MMI_SIM1))
	{
        cui_menu_set_item_hidden(menu_gid,MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM1 , MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid,MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM1 , MMI_TRUE);
	}           

    if(!(usable_side & MMI_SIM2))
	{
        cui_menu_set_item_hidden(menu_gid,MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM2 , MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid,MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM2 , MMI_TRUE);
	}
#if (MMI_MAX_SIM_NUM>=3)
    if(!(usable_side & MMI_SIM3))
	{
		cui_menu_set_item_hidden(menu_gid,MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM3 , MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid,MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM3 , MMI_TRUE);
	}
#if (MMI_MAX_SIM_NUM>=4)
	if(!(usable_side & MMI_SIM4))
	{
		cui_menu_set_item_hidden(menu_gid,MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM4 , MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid,MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM4 , MMI_TRUE);
	}
#endif
#endif
#endif /*  (MMI_MAX_SIM_NUM >= 2) */


#if (MMI_MAX_SIM_NUM >= 2)
    if (!srv_sim_ctrl_is_inserted(MMI_SIM2))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM2, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM2, MMI_TRUE);
    }
#endif /*  (MMI_MAX_SIM_NUM >= 2) */

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_callset_set_ip_item_string(menu_gid);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
}


/*****************************************************************************
 * FUNCTION
 *  ActivateIPNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_ip_number_list_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_sim_enum sim_id = MMI_SIM1;
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_p->target_sim = MMI_SIM_NONE;

    switch (menu_evt->highlighted_menu_id)
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        case MENU_ID_CALLSET_IP_ACTIVATE:
            if (mmi_callset_get_only_inserted_sim(&sim_id))
            {
                mmi_callset_p->target_sim = sim_id;
                mmi_callset_util_ip_number_activate();
                mmi_callset_p->target_sim = MMI_SIM_NONE; 
            }
            break;

        case MENU_ID_CALLSET_IP_DEACTIVATE:
            if (mmi_callset_get_only_inserted_sim(&sim_id))
            {
                mmi_callset_p->target_sim = sim_id;
                mmi_callset_util_ip_number_deactivate();
                mmi_callset_p->target_sim = MMI_SIM_NONE;
            }
            break;
    #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    #if  (MMI_MAX_SIM_NUM < 2)
        case MENU_ID_CALLSET_IP_ACTIVATE_SIM1:
            mmi_callset_p->target_sim = MMI_SIM1;
            mmi_callset_util_ip_number_activate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;

        case MENU_ID_CALLSET_IP_DEACTIVATE_SIM1:
            mmi_callset_p->target_sim = MMI_SIM1;
            mmi_callset_util_ip_number_deactivate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;
    #endif
        case MENU_ID_CALLSET_IP_EDIT:
            mmi_callset_entry_ip_number_list_edit();
            break;

        default:
            break;
    }
}


void mmi_callset_sel_ip_number_list_sub_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_p->target_sim = MMI_SIM_NONE;

    switch (menu_evt->highlighted_menu_id)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        case MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM1:
            mmi_callset_p->target_sim = MMI_SIM1;
            mmi_callset_util_ip_number_activate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;

        case MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM1:
            mmi_callset_p->target_sim = MMI_SIM1;
            mmi_callset_util_ip_number_deactivate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;

        case MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM2:
            mmi_callset_p->target_sim = MMI_SIM2;
            mmi_callset_util_ip_number_activate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;

        case MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM2:
            mmi_callset_p->target_sim = MMI_SIM2;
            mmi_callset_util_ip_number_deactivate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;
#if (MMI_MAX_SIM_NUM>=3)
        case MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM3:
            mmi_callset_p->target_sim = MMI_SIM3;
            mmi_callset_util_ip_number_activate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;
		
        case MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM3:
            mmi_callset_p->target_sim = MMI_SIM3;
            mmi_callset_util_ip_number_deactivate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;
#if (MMI_MAX_SIM_NUM>=4)
        case MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM4:
            mmi_callset_p->target_sim = MMI_SIM4;
            mmi_callset_util_ip_number_activate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;

        case MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM4:
            mmi_callset_p->target_sim = MMI_SIM4;
            mmi_callset_util_ip_number_deactivate();
            mmi_callset_p->target_sim = MMI_SIM_NONE;
            break;
#endif
#endif
#endif

        case MENU_ID_CALLSET_IP_EDIT:
            mmi_callset_entry_ip_number_list_edit();
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_ip_number_list_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  caller_gid  [IN]    caller gid (edit option menu gid)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ip_number_list_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    srv_callset_ip_number_item_struct item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gid = cui_fseditor_create(GRP_ID_CALLSET_COMMON);
    mmi_callset_p->ip_number_edit_gid = gid;

    srv_callset_ip_number_get_item((U8)(mmi_callset_p->ip_number_input), &item);

    cui_fseditor_set_text(gid, item.number, sizeof(item.number), SRV_CALLSET_MAX_IP_NUMBER_LEN);
    cui_fseditor_set_title(gid, STR_GLOBAL_EDIT, GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
    cui_fseditor_set_input_method(gid, IMM_INPUT_TYPE_PHONE_NUMBER, NULL, 0);
    cui_fseditor_run(gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_ip_number_list_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_ip_number_list_edit_done(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ip_number_item_struct item;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_callset_ip_number_get_item((U8)(mmi_callset_p->ip_number_input), &item);

    /* allow to set to empty string if it is not activated */
    len = cui_fseditor_get_text(gid, item.number, sizeof(item.number));

    if (!len && item.status)
    {
        mmi_callset_display_error_popup(STR_GLOBAL_EMPTY);
    }
    else if (srv_callset_ip_number_set_number((U8)(mmi_callset_p->ip_number_input), (U8)len, item.number) != SRV_CALLSET_RESULT_OK)
    {
        mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_SAVED, 
            MMI_EVENT_SUCCESS,
            GRP_ID_ROOT,
            NULL);
        mmi_callset_close_fseditor(gid);
    }
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_get_only_inserted_sim
 * DESCRIPTION
 *  Get the only one inserted sim
 * PARAMETERS
 *  sim          [OUT]    only one inserted sim
 * RETURNS
 *  MMI_TRUE means only insert one sim; otherwise insert not one sim.
 *****************************************************************************/
MMI_BOOL mmi_callset_get_only_inserted_sim(mmi_sim_enum *sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (1 == srv_sim_ctrl_get_num_of_inserted())
    {
        for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
        {
            if (srv_sim_ctrl_is_inserted(sim_id))
            {
                *sim = sim_id;
                break;
            }
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_set_ip_item_string
 * DESCRIPTION
 *  Set ip menu item string with SIM name
 * PARAMETERS
 *  owner_gid       [IN]    Menu GID from cui_menu_create
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_set_ip_item_string(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id;
	WCHAR menu_str[MAX_SUBMENU_CHARACTERS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (0 == mmi_netset_get_sim_name_with_simx_and_brace(sim_id, menu_str, MAX_SUBMENU_CHARACTERS))
        {
            cui_menu_set_item_string(owner_gid, MENU_ID_CALLSET_IP_ACTIVATE_CLUB_SIM1 + i, menu_str);
            cui_menu_set_item_string(owner_gid, MENU_ID_CALLSET_IP_DEACTIVATE_CLUB_SIM1 + i, menu_str);
        }
    }
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
#endif /* __IP_NUMBER__ */


#ifdef __MMI_CM_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_blacklist_launch
 * DESCRIPTION
 *  launch blacklist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_blacklist_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_group_is_present(GRP_ID_CALLSET_COMMON))
    {
        mmi_frm_group_close(GRP_ID_CALLSET_COMMON);
    }

    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_CALLSET_COMMON, mmi_callset_proc_common, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_callset_common_create_cui(GRP_ID_CALLSET_COMMON, MENU_ID_CALLSET_BLACKLIST, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_bl_from_list
 * DESCRIPTION
 *  highlight handler for blacklist - reject from list menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_bl_from_list(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = mmi_callset_p->bl_call_type;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    if (srv_callset_blacklist_get_mode(
    #ifdef __MMI_CM_BLACK_LIST_EXT__
            &adv_param
    #else /* __MMI_CM_BLACK_LIST_EXT__ */
            NULL
    #endif /* __MMI_CM_BLACK_LIST_EXT__ */
        )
         & SRV_CALLSET_BLACKLIST_FROM_LIST)
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_BL_FROM_LIST, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_BL_FROM_LIST, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_bl_from_list_mode
 * DESCRIPTION
 *  create blacklist - reject from list mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_bl_from_list_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_BL_FROM_LIST_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_bl_from_list_mode
 * DESCRIPTION
 *  entry handler for blacklist - reject from list mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_bl_from_list_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = mmi_callset_p->bl_call_type;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    if (srv_callset_blacklist_get_mode(
    #ifdef __MMI_CM_BLACK_LIST_EXT__
            &adv_param
    #else /* __MMI_CM_BLACK_LIST_EXT__ */
            NULL
    #endif /* __MMI_CM_BLACK_LIST_EXT__ */
        ) & SRV_CALLSET_BLACKLIST_FROM_LIST) 
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_bl_from_list_mode
 * DESCRIPTION
 *  select handler for blacklist - reject from list mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_bl_from_list_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_callset_result_enum result;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = mmi_callset_p->bl_call_type;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_ON)
    {
        result = srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_FROM_LIST, MMI_TRUE, 
                #ifdef __MMI_CM_BLACK_LIST_EXT__
                    &adv_param
                #else /* __MMI_CM_BLACK_LIST_EXT__ */
                    NULL
                #endif /* __MMI_CM_BLACK_LIST_EXT__ */
                    );
    }
    else if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_OFF)
    {
        result = srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_FROM_LIST, MMI_FALSE, 
                #ifdef __MMI_CM_BLACK_LIST_EXT__
                    &adv_param
                #else /* __MMI_CM_BLACK_LIST_EXT__ */
                    NULL
                #endif /* __MMI_CM_BLACK_LIST_EXT__ */
                    );
    }
    else
    {
        result = SRV_CALLSET_RESULT_INVALID_INPUT;
    }

    mmi_callset_display_popup_by_cause(result);    

    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}


#ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_bl_rej_unknown_num
 * DESCRIPTION
 *  highlight handler for blacklist - reject unknown number menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_bl_rej_unknown_num(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = mmi_callset_p->bl_call_type;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    if (srv_callset_blacklist_get_mode(
        #ifdef __MMI_CM_BLACK_LIST_EXT__
            &adv_param
        #else /* __MMI_CM_BLACK_LIST_EXT__ */
            NULL
        #endif /* __MMI_CM_BLACK_LIST_EXT__ */
            ) & SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER)
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_BL_REJ_UNKNOWN_NUM, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_BL_REJ_UNKNOWN_NUM, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_bl_rej_unknown_num_mode
 * DESCRIPTION
 *  create blacklist - reject unknown number mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_bl_rej_unknown_num_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_BL_REJ_UNKNOWN_NUM_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_bl_rej_unknown_num_mode
 * DESCRIPTION
 *  entry handler for blacklist - reject unknown number mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_bl_rej_unknown_num_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = mmi_callset_p->bl_call_type;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    if (srv_callset_blacklist_get_mode(
        #ifdef __MMI_CM_BLACK_LIST_EXT__
            &adv_param
        #else /* __MMI_CM_BLACK_LIST_EXT__ */
            NULL
        #endif /* __MMI_CM_BLACK_LIST_EXT__ */
            ) & SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER)
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_bl_rej_unknown_num_mode
 * DESCRIPTION
 *  select handler for blacklist - reject unknown number mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_bl_rej_unknown_num_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_callset_result_enum result = SRV_CALLSET_RESULT_UNKNOWN_ERROR;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = mmi_callset_p->bl_call_type;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_ON)
    {
        result = srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER, MMI_TRUE, 
                #ifdef __MMI_CM_BLACK_LIST_EXT__
                    &adv_param
                #else /* __MMI_CM_BLACK_LIST_EXT__ */
                    NULL
                #endif /* __MMI_CM_BLACK_LIST_EXT__ */
                    );
    }
    else if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_OFF)
    {
        result = srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER, MMI_FALSE, 
                #ifdef __MMI_CM_BLACK_LIST_EXT__
                    &adv_param
                #else /* __MMI_CM_BLACK_LIST_EXT__ */
                    NULL
                #endif /* __MMI_CM_BLACK_LIST_EXT__ */
                    );
    }

    mmi_callset_display_popup_by_cause(result); 

    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}
#endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_bl
 * DESCRIPTION
 *  proc of SCR_ID_CALLSET_BL_NUM_LIST
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_callset_proc_bl(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            mmi_callset_p->blacklist_input = 0;
            mmi_callset_p->bl_list = NULL;
            MMI_ASSERT(evt->user_data);
            OslMfree(evt->user_data);
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_bl_num
 * DESCRIPTION
 *  entry function for blacklist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_bl_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer;
    PU8 string_list[SRV_CALLSET_BLACKLIST_MAX_ITEM];
    srv_callset_bl_item_struct item;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
        GRP_ID_CALLSET_COMMON, 
        SCR_ID_CALLSET_BL_NUM_LIST, 
        NULL, 
        mmi_callset_entry_bl_num, 
        MMI_FRM_UNKNOW_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_BL_NUM_LIST, mmi_callset_proc_bl);
        return;
    }

    if (!mmi_callset_p->bl_list)
    {
        mmi_callset_p->bl_list = OslMalloc(sizeof(mmi_callset_bl_num_list_struct));
        mmi_frm_scrn_set_user_data(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_BL_NUM_LIST, mmi_callset_p->bl_list);
        mmi_frm_scrn_set_leave_proc(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_BL_NUM_LIST, mmi_callset_proc_bl);
    }

    memset(mmi_callset_p->bl_list, 0, sizeof(mmi_callset_bl_num_list_struct));
    memset(string_list, 0, sizeof(string_list));

    for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
    {
        item.index = i;
    #ifdef __MMI_CM_BLACK_LIST_EXT__
        srv_callset_blacklist_init_advanced_param(&adv_param);
        adv_param.call_type = mmi_callset_p->bl_call_type;
        item.adv_param = &adv_param;
    #else /* __MMI_CM_BLACK_LIST_EXT__ */
        item.adv_param = NULL;
    #endif /* __MMI_CM_BLACK_LIST_EXT__ */
        srv_callset_blacklist_get_item(&item);
        memcpy(mmi_callset_p->bl_list->number[i], item.number, sizeof(item.number));
        string_list[i] = (PU8)(mmi_callset_p->bl_list->number[i]);
    }
    
    RegisterHighlightHandler(mmi_callset_hilite_bl_num);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory84Screen(
        STR_ID_CALLSET_BLACKLIST_NUM,
        GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        SRV_CALLSET_BLACKLIST_MAX_ITEM,
        string_list,
        (U16*)gIndexIconsImageList,
        0,
        mmi_callset_p->blacklist_input,
        guiBuffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_callset_p->tap_cb = mmi_callset_entry_bl_num_edit;
    wgui_register_tap_callback(mmi_callset_tap_cb);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    
    SetLeftSoftkeyFunction(mmi_callset_entry_bl_num_edit, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_callset_entry_bl_num_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_bl_num
 * DESCRIPTION
 *  highlight handler for blacklist number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_bl_num(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_p->blacklist_input = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_bl_num_edit
 * DESCRIPTION
 *  entry function for blacklist edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_bl_num_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    srv_callset_bl_item_struct item;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gid = cui_fseditor_create(GRP_ID_CALLSET_COMMON);
    mmi_callset_p->blacklist_edit_gid = gid;

    item.index = (U8)mmi_callset_p->blacklist_input;

#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = mmi_callset_p->bl_call_type;
    item.adv_param = &adv_param;
#else /* __MMI_CM_BLACK_LIST_EXT__ */
    item.adv_param = NULL;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    if (srv_callset_blacklist_get_item(&item) != SRV_CALLSET_RESULT_OK)
    {
        memset(item.number, 0, sizeof(item.number));
    }

    cui_fseditor_set_text(gid, item.number, sizeof(item.number), SRV_UCM_MAX_NUM_URI_LEN - 1);
    cui_fseditor_set_title(gid, STR_GLOBAL_EDIT, GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
    cui_fseditor_set_input_method(gid, INPUT_TYPE_PLUS_CHARACTER_HANDLING|IMM_INPUT_TYPE_PHONE_NUMBER, NULL, 0);
    cui_fseditor_run(gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_bl_num_edit_done
 * DESCRIPTION
 *  entry function for blacklist edit done screen
 * PARAMETERS
 *  gid     [IN]    editor gid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_bl_num_edit_done(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_bl_item_struct item;
    srv_callset_result_enum result;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(item.number, 0, sizeof(item.number));
    cui_fseditor_get_text(gid, item.number, sizeof(item.number));
    item.index = mmi_callset_p->blacklist_input;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = mmi_callset_p->bl_call_type;
    item.adv_param = &adv_param;
#else /* __MMI_CM_BLACK_LIST_EXT__ */
    item.adv_param = NULL;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */

    result = srv_callset_blacklist_set_number(&item);

    if (result != SRV_CALLSET_RESULT_OK && result != SRV_CALLSET_RESULT_DUPLICATE)
    {
        mmi_callset_display_popup_by_cause(result);
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_SAVED,
            MMI_EVENT_SUCCESS,
            GRP_ID_ROOT,
            NULL);
        mmi_callset_close_fseditor(gid);
    }
}
#endif /* __MMI_CM_BLACK_LIST__ */


#ifdef __MMI_CM_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_wl_from_list
 * DESCRIPTION
 *  highlight handler for whitelist - reject from list menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_wl_from_list(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_whitelist_get_mode(NULL) & SRV_CALLSET_WHITELIST_FROM_LIST)
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_WL_FROM_LIST, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_WL_FROM_LIST, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_wl_from_list_mode
 * DESCRIPTION
 *  create whitelist - reject from list mode menu
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_wl_from_list_mode(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_WL_FROM_LIST_MODE, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_wl_from_list_mode
 * DESCRIPTION
 *  entry handler for whitelist - reject from list mode menu item
 * PARAMETERS
 *  menu_gid    [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_wl_from_list_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_whitelist_get_mode(NULL) & SRV_CALLSET_WHITELIST_FROM_LIST)
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_wl_from_list_mode
 * DESCRIPTION
 *  select handler for whitelist - reject from list mode menu item
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_wl_from_list_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_ON)
    {
        result = srv_callset_whitelist_switch_mode(SRV_CALLSET_WHITELIST_FROM_LIST, MMI_TRUE, NULL);
    }
    else
    {
        result = srv_callset_whitelist_switch_mode(SRV_CALLSET_WHITELIST_FROM_LIST, MMI_FALSE, NULL);
    }

    mmi_callset_display_popup_by_cause(result); 

    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_wl
 * DESCRIPTION
 *  proc of SCR_ID_CALLSET_WL_NUM_LIST
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_callset_proc_wl(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            mmi_callset_p->whitelist_input = 0;
            mmi_callset_p->wl_list = NULL;
            MMI_ASSERT(evt->user_data);
            OslMfree(evt->user_data);
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_wl_num
 * DESCRIPTION
 *  entry function for whitelist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_wl_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer;
    PU8 string_list[SRV_CALLSET_WHITELIST_MAX_ITEM];
    srv_callset_wl_item_struct item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
        GRP_ID_CALLSET_COMMON, 
        SCR_ID_CALLSET_WL_NUM_LIST, 
        NULL, 
        mmi_callset_entry_wl_num, 
        MMI_FRM_UNKNOW_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_WL_NUM_LIST, mmi_callset_proc_wl);
        return;
    }

    if (!mmi_callset_p->wl_list)
    {
        mmi_callset_p->wl_list = OslMalloc(sizeof(mmi_callset_wl_num_list_struct));
        mmi_frm_scrn_set_user_data(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_WL_NUM_LIST, mmi_callset_p->wl_list);
        mmi_frm_scrn_set_leave_proc(GRP_ID_CALLSET_COMMON, SCR_ID_CALLSET_WL_NUM_LIST, mmi_callset_proc_wl);
    }

    memset(mmi_callset_p->wl_list, 0, sizeof(mmi_callset_wl_num_list_struct));
    memset(string_list, 0, sizeof(string_list));
    item.adv_param = NULL;

    for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
    {
        item.index = i;
        srv_callset_whitelist_get_item(&item);
        memcpy(mmi_callset_p->wl_list->number[i], item.number, sizeof(item.number));
        string_list[i] = (PU8)(mmi_callset_p->wl_list->number[i]);
    }
    
    RegisterHighlightHandler(mmi_callset_hilite_wl_num);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory84Screen(
        STR_ID_CALLSET_WHITELIST_NUM,
        GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        SRV_CALLSET_WHITELIST_MAX_ITEM,
        string_list,
        (U16*)gIndexIconsImageList,
        0,
        mmi_callset_p->whitelist_input,
        guiBuffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_callset_p->tap_cb = mmi_callset_entry_wl_num_edit;
    wgui_register_tap_callback(mmi_callset_tap_cb);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    
    SetLeftSoftkeyFunction(mmi_callset_entry_wl_num_edit, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_callset_entry_wl_num_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_wl_num
 * DESCRIPTION
 *  highlight handler for whitelist number
 * PARAMETERS
 *  index   [IN]    highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_wl_num(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_p->whitelist_input = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_wl_num_edit
 * DESCRIPTION
 *  entry function for whitelist edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_wl_num_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    srv_callset_wl_item_struct item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gid = cui_fseditor_create(GRP_ID_CALLSET_COMMON);
    mmi_callset_p->whitelist_edit_gid = gid;

    item.index = (U8)mmi_callset_p->whitelist_input;
    item.adv_param = NULL;
    if (srv_callset_whitelist_get_item(&item) != SRV_CALLSET_RESULT_OK)
    {
        memset(item.number, 0, sizeof(item.number));
    }

    cui_fseditor_set_text(gid, item.number, sizeof(item.number), SRV_UCM_MAX_NUM_URI_LEN - 1);
    cui_fseditor_set_title(gid, STR_GLOBAL_EDIT, GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
    cui_fseditor_set_input_method(gid, INPUT_TYPE_PLUS_CHARACTER_HANDLING|IMM_INPUT_TYPE_PHONE_NUMBER, NULL, 0);
    cui_fseditor_run(gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_wl_num_edit_done
 * DESCRIPTION
 *  entry function for whitelist edit done screen
 * PARAMETERS
 *  gid     [IN]    editor gid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_wl_num_edit_done(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR ucs2_num[SRV_UCM_MAX_NUM_URI_LEN + 1];
    CHAR asc_num[SRV_UCM_MAX_NUM_URI_LEN + 1];
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    len = cui_fseditor_get_text(gid, ucs2_num, sizeof(ucs2_num));
    memset(asc_num, 0, sizeof(asc_num));
    mmi_ucs2_n_to_asc((CHAR*)asc_num, (CHAR*)ucs2_num, (U32)(len * ENCODING_LENGTH));

    if (len && !srv_ucm_is_valid_number((srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, (PU8)asc_num))
    {
        mmi_callset_display_error_popup(STR_GLOBAL_INVALID_NUMBER);
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)mmi_callset_p->whitelist_num, (CHAR*)ucs2_num, len);

        cui_verify_run(
            cui_verify_create(GRP_ID_CALLSET_COMMON, CUI_VERIFY_TYPE_PHONE_PASSWORD));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_wl_passwd_verify_suc
 * DESCRIPTION
 *  verify password successfully
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_wl_passwd_verify_suc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_wl_item_struct item;
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    item.index = (U8)(mmi_callset_p->whitelist_input);
    mmi_ucs2cpy((CHAR*)(item.number), (CHAR*)(mmi_callset_p->whitelist_num));
    item.adv_param = NULL;

    result = srv_callset_whitelist_set_number(&item);
    
    if (result != SRV_CALLSET_RESULT_OK && result != SRV_CALLSET_RESULT_DUPLICATE)
    {
        mmi_callset_display_popup_by_cause(result);
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_SAVED, 
            MMI_EVENT_SUCCESS,
            GRP_ID_ROOT,
            NULL);
        mmi_callset_close_fseditor(mmi_callset_p->whitelist_edit_gid);
    }
}
#endif /* __MMI_CM_WHITE_LIST__ */


#ifdef __MMI_CH_QUICK_END__
static const cui_inline_item_caption_struct sel_caption = {STR_GLOBAL_SETTINGS};
static const U16 sel_list[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const cui_inline_item_select_struct selector_option = {2, 0, (U16*)sel_list}; 
static const cui_inline_item_caption_struct text_caption = {STR_ID_CALLSET_QUICK_END_DURATION};
static const cui_inline_item_text_edit_struct textedit_name = {
                                                0, 
                                                0, 
                                                5,
                                                IMM_INPUT_TYPE_NUMERIC, 
                                                0,
                                                NULL};
static const cui_inline_set_item_struct inline_item[] =
{
    {MMI_CALLSET_INLINE_QUICK_END_SEL_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_STATUS, (void*)&sel_caption},
    {MMI_CALLSET_INLINE_QUICK_END_SEL, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&selector_option},
    {MMI_CALLSET_INLINE_QUICK_END_TEXT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_TIME, (void*)&text_caption},
    {MMI_CALLSET_INLINE_QUICK_END_TEXTEDIT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO, 0, (void*)&textedit_name},
};

static const cui_inline_struct g_callset_inline_data = 
{
    4,   /* item count */
    STR_ID_CALLSET_QUICK_END,  /* screen title string id */
    0, /* screen title icon id */
    CUI_INLINE_SCREEN_DISABLE_DONE,  
    NULL,
    (cui_inline_set_item_struct*)inline_item
};


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_auto_quick_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_gid  [in]   menu id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_auto_quick_end(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL mode;
    U16 time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_auto_quick_end_get_mode(&mode, &time) != SRV_CALLSET_RESULT_OK)
    {
        return;
    }

    if (mode)
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_QUICK_END, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_QUICK_END, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_auto_quick_end
 * DESCRIPTION
 *  Entry function for set quick end time screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_auto_quick_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL mode;
    U8 mode2;
    U16 time;
    WCHAR input[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_p->quick_end_edit_gid = cui_inline_create(GRP_ID_CALLSET_COMMON, &g_callset_inline_data);

    if (srv_callset_auto_quick_end_get_mode(&mode, &time) != SRV_CALLSET_RESULT_OK)
    {
        mode = MMI_FALSE;
        time = 0;
    }

    app_ucs2_itoa((S32)time, (kal_int8*)input, 10);
    mode2 = mode ? 0x01 : 0x00;
    cui_inline_set_value(mmi_callset_p->quick_end_edit_gid, MMI_CALLSET_INLINE_QUICK_END_SEL, (void*)mode2);
    if (time)
    {
        cui_inline_set_value(mmi_callset_p->quick_end_edit_gid, MMI_CALLSET_INLINE_QUICK_END_TEXTEDIT, &input);
    }

    cui_inline_set_title_icon(mmi_callset_p->quick_end_edit_gid, GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
    cui_inline_run(mmi_callset_p->quick_end_edit_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_quick_end_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    editor gid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_quick_end_edit_done(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode;
    U16 time;
    WCHAR input[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_inline_get_value(gid, MMI_CALLSET_INLINE_QUICK_END_SEL, &mode);
    cui_inline_get_value(gid, MMI_CALLSET_INLINE_QUICK_END_TEXTEDIT, &input);

    if (!mmi_ucs2strlen((CHAR*)input))
    {
        time = 0;
    }
    else
    {
        time = (U16)app_ucs2_atoi((kal_int8*)input);
    }
    
    if (!time || (time > SRV_CALLSET_AUTO_QUICK_END_MAX))
    {
        mmi_callset_display_error_popup(STR_GLOBAL_INVALID);
    }
    else if (srv_callset_auto_quick_end_set_mode((MMI_BOOL)mode, time) != SRV_CALLSET_RESULT_OK)
    {
        mmi_callset_display_error_popup(STR_GLOBAL_ERROR);
    }
    else
    {
        mmi_callset_display_popup_by_cause(SRV_CALLSET_RESULT_OK);

        cui_inline_close(gid);
        mmi_callset_p->quick_end_edit_gid = 0;
    }
}

#endif /* __MMI_CH_QUICK_END__ */


#ifdef __CTM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_ctm_setting_launch
 * DESCRIPTION
 *  launch CTM setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_ctm_setting_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_nw_usab_is_any_network_available() ||
        srv_callset_ctm_permit_switch_setting() != SRV_CALLSET_RESULT_OK)
    {
        mmi_callset_display_error_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
        return; 
    }

    if (mmi_frm_group_is_present(GRP_ID_CALLSET_COMMON))
    {
        mmi_frm_group_close(GRP_ID_CALLSET_COMMON);
    }

    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_CALLSET_COMMON, mmi_callset_proc_common, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_callset_create_ctm_setting_opt(GRP_ID_CALLSET_COMMON);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_ctm_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_gid  [IN]    menu group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_ctm_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_ctm_get_mode())
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CTM_MODE, get_string(STR_GLOBAL_ON));
    }
    else
    {
        cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_CTM_MODE, get_string(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_ctm_mode_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_ctm_mode_opt(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_CTM_MODE_OPT, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_ctm_mode_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_gid    [IN]    menu id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ctm_mode_opt(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_ctm_get_mode())
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_OFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_ctm_mode_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_ctm_mode_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_callset_ctm_setting_struct set;
    srv_callset_result_enum result = SRV_CALLSET_RESULT_INVALID_INPUT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_entry_error_message();
        mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    set.setting = srv_callset_ctm_get_setting();

    if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_ON)
    {
        set.mode = MMI_TRUE;
        result = srv_callset_ctm_set_mode(&set);
    }
    else if (menu_evt->highlighted_menu_id == MENU_ID_CALLSET_OFF)
    {
        set.mode = MMI_FALSE;
        result = srv_callset_ctm_set_mode(&set);
    }

    mmi_callset_display_popup_by_cause(result);

    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_callset_create_ctm_setting_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid  [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_create_ctm_setting_opt(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_callset_common_create_cui(parent_gid, MENU_ID_CALLSET_CTM_SET_OPT, MENU_ID_CALLSET_CALL_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_ctm_setting_opt(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (srv_callset_ctm_get_setting())
    {
        case SRV_CALLSET_CTM_SETTING_BAUDOT:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CTM_BAUDOT);
            break;

        case SRV_CALLSET_CTM_SETTING_HCO:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CTM_HCO);
            break;

        case SRV_CALLSET_CTM_SETTING_VCO:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CTM_VCO);
            break;

        case SRV_CALLSET_CTM_SETTING_MANUAL_DIRECT:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CTM_MANUAL_DIRECT);
            break;

        default:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_CTM_AUTO_DIRECT);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_ctm_setting_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    input information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_ctm_setting_opt(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    srv_callset_ctm_setting_struct set;
    srv_callset_result_enum result = SRV_CALLSET_RESULT_INVALID_INPUT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    set.mode = srv_callset_ctm_get_mode();

    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_CTM_BAUDOT:
            set.setting = SRV_CALLSET_CTM_SETTING_BAUDOT;
            result = srv_callset_ctm_set_mode(&set);
            break;

        case MENU_ID_CALLSET_CTM_HCO:
            set.setting = SRV_CALLSET_CTM_SETTING_HCO;
            result = srv_callset_ctm_set_mode(&set);
            break;

        case MENU_ID_CALLSET_CTM_VCO:
            set.setting = SRV_CALLSET_CTM_SETTING_VCO;
            result = srv_callset_ctm_set_mode(&set);
            break;

        case MENU_ID_CALLSET_CTM_MANUAL_DIRECT:
            set.setting = SRV_CALLSET_CTM_SETTING_MANUAL_DIRECT;
            result = srv_callset_ctm_set_mode(&set);
            break;

        case MENU_ID_CALLSET_CTM_AUTO_DIRECT:
            set.setting = SRV_CALLSET_CTM_SETTING_AUTO_DIRECT;
            result = srv_callset_ctm_set_mode(&set);
            break;

        default:
            break;
    }

    mmi_callset_display_popup_by_cause(result);

    mmi_callset_close_menu(menu_evt->sender_id, menu_evt->app_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hdlr_ctm_setting_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_callset_hdlr_ctm_setting_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_ctm_get_mode())
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_TTY_INDICATOR);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_TTY_INDICATOR);
    }

    return MMI_RET_OK;
}
#endif /* __CTM_SUPPORT__ */


#if 0
#ifdef __OP01_FWPBW__
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
#endif /* __OP01_FWPBW__ */
#endif


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_tap_cb
 * DESCRIPTION
 *  call back function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_tap_cb(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM) 
    {
        mmi_callset_p->tap_cb();
    }

}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

#ifdef __MMI_AP_DCM_CALLSET__
#pragma arm section rodata , code
#endif


#ifdef __VOICE_CHANGER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_magic_voice_launch
 * DESCRIPTION
 *  interface to launch magic voice setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_magic_voice_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_CALLSET_MAGIC_VOICE))
    {
        mmi_frm_group_close(GRP_ID_CALLSET_MAGIC_VOICE);
    }
        
    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_CALLSET_MAGIC_VOICE, mmi_callset_proc_magic_voice, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    menu_gid = cui_menu_create(
                GRP_ID_CALLSET_MAGIC_VOICE,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                MENU_ID_CALLSET_MAGIC_VOICE_OPTION,
                MMI_FALSE,
                NULL);

    cui_menu_set_default_title_image_by_id(menu_gid, GetRootTitleIcon(MENU_ID_CALLSET_CALL_SETTING));
    cui_menu_set_currlist_flags(menu_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_proc_magic_voice
 * DESCRIPTION
 *  proc handle of magic voice setting menu
 * PARAMETERS
 *  evt  [IN]    event handle
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_callset_proc_magic_voice(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        /* menu event */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_callset_entry_magic_voice_mode(menu_evt->sender_id);
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            break;
    
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_callset_sel_magic_voice_mode(menu_evt);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);

            if (menu_evt->app_data)
            {
                OslMfree(menu_evt->app_data);
            }
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_hilite_magic_voice
 * DESCRIPTION
 *  hilite handle of magic voice list menu
 * PARAMETERS
 *  menu_gid  [IN]   hilited menu id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_hilite_magic_voice(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SPH_VOICE_CHANGER_MODE setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting = mdi_audio_get_voice_changer_mode();

    switch (setting)
    {
        case SPH_VC_NORMAL:
            cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_MAGIC_VOICE, get_string(STR_ID_CALLSET_MGV_NONE));
            break;

        case SPH_VC_MAN:
            cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_MAGIC_VOICE, get_string(STR_ID_CALLSET_MGV_MEN));
            break;

        case SPH_VC_WOMAN:
            cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_MAGIC_VOICE, get_string(STR_ID_CALLSET_MGV_WOMEN));
            break;

        case SPH_VC_CHILD:
            cui_menu_set_item_hint(menu_gid, MENU_ID_CALLSET_MAGIC_VOICE, get_string(STR_ID_CALLSET_MGV_CHILD));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_entry_magic_voice_mode
 * DESCRIPTION
 *  entey handle of magic voice list menu
 * PARAMETERS
 *  menu_gid  [IN]   hilited menu id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_entry_magic_voice_mode(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SPH_VOICE_CHANGER_MODE setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting = mdi_audio_get_voice_changer_mode();

    switch (setting)
    {
        case SPH_VC_NORMAL:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_MGV_NONE);
            break;

        case SPH_VC_MAN:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_MGV_MEN);
            break;

        case SPH_VC_WOMAN:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_MGV_WOMEN);
            break;

        case SPH_VC_CHILD:
            cui_menu_set_radio_list_item(menu_gid, MENU_ID_CALLSET_MGV_CHILD);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_magic_voice_mode
 * DESCRIPTION
 *  select handle of magic voice list menu
 * PARAMETERS
 *  info  [IN]   menu info of selected one
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sel_magic_voice_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)info;
    SPH_VOICE_CHANGER_MODE setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_CALLSET_MGV_NONE:
            setting = SPH_VC_NORMAL;
            break;
        case MENU_ID_CALLSET_MGV_MEN:
            setting = SPH_VC_MAN;
            break;
        case MENU_ID_CALLSET_MGV_WOMEN:
            setting = SPH_VC_WOMAN;
            break;
        case MENU_ID_CALLSET_MGV_CHILD:
            setting = SPH_VC_CHILD;
            break;
        default:
            return;
    }

    if (mdi_audio_set_voice_changer_mode(setting))
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS,
            GRP_ID_ROOT,
            NULL);

        mmi_frm_group_close(GRP_ID_CALLSET_MAGIC_VOICE);
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }
}
#endif /* __VOICE_CHANGER_SUPPORT__ */
