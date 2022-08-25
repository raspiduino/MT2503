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
 * EmailAppAccount.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email account function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__

#include "FileMgrCuiGprot.h"
#include "Inlinecuigprot.h"
#include "Menucuigprot.h"
#include "Fseditorcuigprot.h"
#ifdef __MMI_IMAGE_VIEWER__
#include "Imageviewcuigprot.h"
#endif /* __MMI_IMAGE_VIEWER__ */
#include "CommonScreens.h"
#include "Phbcuigprot.h"
#include "Phbsrvgprot.h"
#include "Conversions.h"
#include "mmi_rp_app_email_def.h"
#include "EmailAppProt.h"
#include "EmailSrvGprot.h"
#include "EmailAppCore.h"
#include "EmailAppAccount.h"
#include "app_crc.h"
#include "App_mine.h"
#include "RightsMgrGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ImeGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "gui_data_types.h"
#include "AlertScreen.h"
#include "DataAccountCuiGprot.h"
#include "CbmCuiGprot.h"
#include "gui_typedef.h"
#include "fs_type.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "mmi_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_public_api.h"
#include "customer_ps_inc.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_categories_list.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_uiframework_def.h"
#include "GlobalConstants.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "CommonScreensResDef.h"
#include "DataAccountGProt.h"
#include "wgui_categories_inputs.h"
#include "DtcntSrvGprot.h"
#include "wgui_categories_text_viewer.h"
#include "custom_data_account.h"
#include "gui.h"
#include "CbmSrvGprot.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_email.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "mmi_frm_input_gprot.h"

#include "SimCtrlSrvGprot.h"

#include "EmailAppDtcnt.h"
#include "EmailAppStateMgr.h"
#include "EmailAppAccountData.h"
#include "EmailAppNetwork.h"
#include "EmailAppLib.h"
#include "EmailAppSso.h"


#if (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__))
#ifndef __MMI_EMAIL_EMN__
#define __MMI_EMAIL_EMN__
#endif /* __MMI_EMAIL_EMN__ */
#endif /* (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)) */


/* function declaration */
static MMI_BOOL mmi_email_check_account_id_validity(
                    EMAIL_ACCT_ID test_account_id,
                    EMAIL_ACCT_ID *p_account_id_array,
                    S32 account_id_array_length);

static void mmi_email_account_init_inline_item_struct(
                cui_inline_set_item_struct *p_inline_item,
                U16 item_id,
                U32 item_flag,
                U16 image_id,
                void *item_data);
static void mmi_email_account_init_fullscreen_edit_struct(
                cui_inline_item_fullscreen_edit_struct *p_fullscreen_item,
                U16 string_id,
                U16 default_text_id,
                U16 title,
                U16 title_icon,
                S16 input_extended_type,
                U32 input_type,
                S32 buffer_size,  
                mmi_imm_input_mode_enum *required_input_mode_set);
static void mmi_email_account_init_select_struct(
                cui_inline_item_select_struct *p_select_item,
                U8 n_items,
                U8 highlighted_item,
                U16 *list_of_item_id);
static void mmi_email_account_init_text_edit_struct(
                cui_inline_item_text_edit_struct *p_text_edit_item,
                U16 string_id,
                U16 default_text_id,
                U32 buffer_size,
                U32 input_type,
                S16 input_extended_type,
                mmi_imm_input_mode_enum *required_input_mode_set);
static srv_email_result_enum mmi_email_get_total_account_info(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_entry_account_list_proc(mmi_event_struct *p_event);
static void mmi_email_entry_account_list_screen_highlight_handler(S32 index);
static mmi_ret mmi_email_entry_account_list_screen(mmi_scrn_essential_struct* p_screen_data);
static pBOOL mmi_email_get_account_name(S32 account_index, UI_string_type account_name, PU8 *account_image, U8 str_img_mask);
static void mmi_email_account_set_menu_screen(mmi_id screen_id, mmi_email_menu_screen_struct *p_menu_screen_struct, U16 StringId);
static void mmi_email_account_list_have_account_csk_handler(void);
static void mmi_email_entry_account_list_option(void);
static void mmi_email_entry_account_list_proc_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_account_list_proc_handle_cui_menu_item_select_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_account_list_proc_handle_cui_menu_item_close_request_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_account_list_proc_handle_cui_inline_submit_message(cui_event_inline_submit_struct *p_event);
static void mmi_email_entry_account_list_proc_handle_cui_fseditor_abort_message(cui_fseditor_evt_struct *p_event);
static mmi_ret mmi_email_wizard_new_account_launch_confirm_callback(mmi_event_struct *event);

static void mmi_email_wizard_new_account_launch_lsk(void);
static void mmi_email_wizard_new_account_launch_rsk(void);
static void mmi_email_entry_new_account_with_template_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_new_account_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_template_list_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_wizard_entry_template_list_proc(mmi_event_struct *p_event);
static void mmi_email_wizard_entry_template_list_proc_handle_cui_inline_submit_message(cui_event_inline_submit_struct *p_event);
static void mmi_email_wizard_entry_template_list_proc_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_event);
static mmi_ret mmi_email_wizard_entry_template_list_screen(mmi_scrn_essential_struct* p_screen_data);
static mmi_ret mmi_email_wizard_entry_template_list_screen_leave_proc(mmi_event_struct *p_event);
static void mmi_email_wizard_entry_template_list_highlight_handler(S32 item_index);
static void mmi_email_wizard_entry_template_list_lsk(void);
static void mmi_email_wizard_entry_template_list_rsk(void);
static void mmi_email_wizard_entry_edit_template_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_edit_template_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_email_addr_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_email_addr_search_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_email_addr_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_protocol_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_wizard_entry_protocol_proc(mmi_event_struct *p_event);
static void mmi_email_wizard_entry_protocol_proc_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_event);
static void mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_select_message(cui_menu_event_struct *p_event);
static void mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_close_message(cui_menu_event_struct *p_event);
static void mmi_email_wizard_entry_protocol_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_data_account_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_entry_new_account_proc(mmi_event_struct *p_event);
static void mmi_email_entry_new_account_proc_handle_cui_menu_item_close_request_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_new_account_proc_handle_cui_fseditor_abort_message(cui_fseditor_evt_struct *p_event);
static void mmi_email_entry_new_account_proc_handle_cui_fseditor_empty_message(cui_fseditor_evt_struct *p_event);
static void mmi_email_entry_new_account_proc_handle_cui_fseditor_menu_select_message(cui_fseditor_custom_menu_select_evt_struct *p_event);
static void mmi_email_entry_new_account_proc_handle_cui_fseditor_not_empty_message(cui_fseditor_evt_struct *p_event);
static void mmi_email_entry_new_account_proc_handle_phb_select_contact_message(cui_phb_select_contact_result_struct *p_event);
static void mmi_email_entry_new_account_proc_handle_phb_select_contact_cancel_message(cui_phb_select_contact_result_struct *p_event);
static void mmi_email_entry_new_account_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);
static mmi_ret mmi_email_wizard_entry_data_account_proc(mmi_event_struct *p_event);
static void mmi_email_wizard_entry_data_account_proc_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_event);
static void mmi_email_wizard_entry_data_account_proc_handle_cui_menu_item_select_message(cui_menu_event_struct *p_event);
static void mmi_email_wizard_entry_data_account_proc_handle_cui_menu_item_close_message(cui_menu_event_struct *p_event);

static void mmi_email_data_account_cui_dtcnt_select_ok_message(cui_dtcnt_select_event_any_sim_selected_struct* p_event);
static void mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_done_message(cui_dtcnt_select_event_struct *p_event);
static void mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_cancel_message(cui_dtcnt_select_event_struct *p_event);
static void mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_close_message(cui_dtcnt_select_event_struct *p_event);
static mmi_ret mmi_email_wizard_entry_data_account_screen(mmi_scrn_essential_struct *p_screen_data);
static void mmi_email_wizard_entry_data_account_option(void);
static void mmi_email_wizard_entry_data_account_csk_handler(void);
static void mmi_email_wizard_entry_data_account_previous_process(void);
static void mmi_email_wizard_entry_incoming_server_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_incoming_server_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_incoming_server_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_outgoing_server_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_outgoing_server_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_outgoing_server_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_user_name_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_user_name_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_user_name_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_password_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_password_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_password_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_account_name_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_account_name_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_account_name_done_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_cancel_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_entry_cancel_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_wizard_cancel_operation(void);
static void mmi_email_wizard_get_default_acct_name(mmi_email_account_list_cntx_struct *p_account_list_cntx);

static void mmi_email_entry_edit_account_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);

static mmi_ret mmi_email_entry_edit_account_proc(mmi_event_struct *p_event);
static void mmi_email_entry_edit_account_proc_handle_group_deinit_message(mmi_event_struct *p_event);
static void mmi_email_entry_edit_account_proc_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_event);
static void mmi_email_entry_edit_account_proc_handle_cui_menu_item_close_request_message(cui_menu_event_struct *p_event);

static mmi_email_account_check_interval_enum mmi_email_entry_edit_account_convert_check_interval_value(U32 interval_value);
static void mmi_email_entry_edit_account_entry_main_setting_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_entry_edit_account_entry_main_setting_proc(mmi_event_struct *p_event);
static void mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_setkey_message(cui_event_inline_set_key_struct *p_event);
static void mmi_email_entry_edit_account_main_setting_proc_handle_inline_submit_message(cui_event_inline_submit_struct *p_event);
static void mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_event);
static void mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_deinit_message(cui_event_inline_common_struct *p_event);
static void mmi_email_entry_edit_account_main_setting_proc_handle_list_entry_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_main_setting_proc_handle_list_select_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_main_setting_proc_handle_close_request_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_main_setting_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);
static void mmi_email_entry_edit_account_entry_main_setting_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_advance_setting(void);


static void mmi_email_entry_edit_account_entry_account_setting_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_entry_edit_account_entry_account_setting_proc(mmi_event_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_notify_message(cui_event_inline_notify_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_setkey_message(cui_event_inline_set_key_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_submit_message(cui_event_inline_submit_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_abort_message(cui_event_inline_abort_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_deinit_message(cui_event_inline_common_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_sub_message(cui_fseditor_evt_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_abort_message(cui_fseditor_evt_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_empty_message(cui_fseditor_evt_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_no_message(cui_fseditor_evt_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_sel_message(cui_fseditor_custom_menu_select_evt_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_phb_select_message(cui_phb_select_contact_result_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_phb_sel_cancel_message(cui_phb_select_contact_result_struct *p_event);
static void mmi_email_entry_edit_account_account_setting_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);
static void mmi_email_entry_edit_account_entry_account_setting_reply_addr_lsk(void);
static void mmi_email_entry_edit_account_entry_account_setting_sel_dtcnt_lsk(void);
static void mmi_email_entry_edit_account_entry_account_setting_chk_interval_lsk(void);
#ifdef __MMI_EMAIL_EMN__
static void mmi_email_entry_edit_account_entry_account_setting_emn_lsk(void);
#endif /* __MMI_EMAIL_EMN__ */
static void mmi_email_entry_edit_account_entry_account_setting_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_save_account_setting_lsk(void);
static void mmi_email_entry_edit_account_save_account_setting_rsk(void);


static void mmi_email_entry_edit_account_save_main_account_setting_lsk(void);
static void mmi_email_entry_edit_account_save_main_account_setting_rsk(void);


static void mmi_email_entry_edit_account_entry_outgoing_server_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_entry_edit_account_entry_outgoing_server_proc(mmi_event_struct *p_event);
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_notify_message(cui_event_inline_notify_struct *p_event);
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_submit_message(cui_event_inline_submit_struct *p_event);
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_abort_message(cui_event_inline_abort_struct *p_event);
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_deinit_message(cui_event_inline_common_struct *p_event);
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_group_deinit_message(mmi_event_struct *p_event);
static void mmi_email_entry_edit_account_entry_outgoing_server_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_entry_outgoing_server_auth_process(void);
static void mmi_email_entry_edit_account_entry_outgoing_server_auth_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_save_outgoing_server(void);
static void mmi_email_entry_edit_account_save_outgoing_server_lsk(void);
static void mmi_email_entry_edit_account_save_outgoing_server_rsk(void);
static void mmi_email_entry_edit_account_outgoing_auth_opt(void);
static void mmi_email_entry_edit_account_outgoing_auth_menu_select(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_outgoing_auth_menu_close(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_setkey(cui_event_inline_set_key_struct *p_event);

static void mmi_email_entry_edit_account_entry_incoming_server_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_entry_edit_account_entry_incoming_server_proc(mmi_event_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_inline_notify_message(cui_event_inline_notify_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_inline_setkey_message(cui_event_inline_set_key_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_csk(S16 item_id);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_inline_abort_message(cui_event_inline_abort_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_inline_deinit_message(cui_event_inline_common_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_menu_entry_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_menu_select_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_menu_close_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_cbm_cui_message(cui_evt_cbm_bearer_select_struct *p_event);
static void mmi_email_entry_edit_account_incoming_server_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);
static void mmi_email_entry_edit_account_entry_incoming_server_pop3_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_entry_incoming_server_imap_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_folder(void);
static mmi_ret mmi_email_entry_edit_account_entry_incoming_server_imap_remote_wait_screen(mmi_scrn_essential_struct* p_screen_data);
static void mmi_email_entry_edit_account_entry_incoming_server_remote_cancel(void);
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_callback(
                srv_email_result_struct *p_result,
                EMAIL_REQ_ID req_id,
                void *p_user_data);
static mmi_ret mmi_email_entry_edit_account_entry_incoming_server_imap_subscibe_wait_screen(mmi_scrn_essential_struct* p_screen_data);
static void mmi_email_entry_edit_account_entry_incoming_server_subscribe_cancel(void);
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_process(srv_email_nwk_proc_struct *data);
static mmi_ret mmi_email_entry_edit_account_entry_incoming_server_imap_remote_list_screen(mmi_scrn_essential_struct* p_screen_data);
static void mmi_email_entry_edit_account_imap_remote_list_screen_highlight_handler(S32 index);
static S32 mmi_email_entry_edit_account_entry_incoming_server_imap_get_remote(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_lsk(void);
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_rsk(void);
static void mmi_email_entry_edit_account_save_incoming_server_lsk(void);
static void mmi_email_entry_edit_account_save_incoming_server_rsk(void);
static WCHAR *mmi_email_get_remote_folder_name(WCHAR *p_full_path_name, WCHAR seprator);
static srv_email_result_enum mmi_email_subscribe_remote_folder(
                                mmi_email_account_list_cntx_struct *p_account_list_cntx,
                                MMI_BOOL subscribe);

static void mmi_email_entry_edit_account_entry_signature_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_entry_edit_account_entry_signature_proc(mmi_event_struct *param);
static void mmi_email_entry_edit_account_signature_proc_handle_cui_inline_notify_message(cui_event_inline_notify_struct *p_event);
static void mmi_email_entry_edit_account_signature_save(void);
static void mmi_email_entry_edit_signature_account_proc_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_event);
static void mmi_email_entry_edit_signature_account_proc_handle_cui_inline_deinit_message(cui_event_inline_common_struct *p_event);
static void mmi_email_entry_edit_account_signature_proc_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_select_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_close_message(cui_menu_event_struct *p_event);
static void mmi_email_entry_edit_account_signature_proc_handle_cui_file_selector_message(cui_file_selector_result_event_struct *p_event);
static void mmi_email_entry_edit_account_signature_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);

static void mmi_email_entry_edit_account_signature_img_csk_hdlr(S16 item_id);

#ifdef __MMI_IMAGE_VIEWER__
static void mmi_email_entry_edit_account_signature_view_img(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_signature_proc_handle_cui_imageview_close_message(mmi_group_event_struct *p_event);
#endif /* __MMI_IMAGE_VIEWER__ */

#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
static void mmi_email_entry_edit_account_signature_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* #if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__) */

static void mmi_email_entry_edit_account_entry_signature_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_signature_select_options(void);
static void mmi_email_entry_edit_account_signature_select_options_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_entry_edit_account_save_signature_lsk_handler(void);
static mmi_ret mmi_email_entry_edit_account_save_signature_screen(mmi_scrn_essential_struct *p_screen_data);
static void mmi_email_entry_edit_account_save_signature_rsk_handler(void);
static void mmi_email_entry_edit_account_edit_signature_image_callback(
                S32 edit_image_result, 
                void *p_user_data);
static void mmi_email_entry_edit_account_signature_opt_select_file(mmi_email_account_list_cntx_struct *p_account_list_cntx);

static void mmi_email_entry_delete_account_process(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static mmi_ret mmi_email_entry_delete_account_proc(mmi_event_struct *p_event);
static void mmi_email_entry_delete_account_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);
static void mmi_email_entry_delete_account_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx);
static void mmi_email_delete_account_operation(void);
static mmi_ret mmi_email_delete_account_progress_screen(mmi_scrn_essential_struct *p_screen_data);
static void mmi_email_cancel_delete_account_progress(void);

static MMI_BOOL mmi_email_entry_edit_account_read_account_extra_info(
                    EMAIL_ACCT_ID account_id, 
                    mmi_email_account_extra_info_struct *p_extra_info,
                    S32 *p_fs_error);
static MMI_BOOL mmi_email_entry_edit_account_write_account_extra_info(
                    EMAIL_ACCT_ID account_id, 
                    mmi_email_account_extra_info_struct *p_extra_info,
                    S32 *p_fs_error);
static MMI_BOOL mmi_email_entry_edit_account_list_account_extra_info_id(
                    EMAIL_ACCT_ID *p_account_id_array, 
                    U16 *account_id_num,
                    S32 *p_fs_error);
static srv_email_result_enum mmi_email_entry_edit_account_save_account_info(
                                EMAIL_SRV_HANDLE srv_handle,
                                EMAIL_ACCT_HANDLE *p_acct_handle,
                                EMAIL_ACCT_ID acct_id,
                                srv_email_acct_info_struct *p_acct_info);
static MMI_BOOL mmi_email_entry_edit_account_check_validity_of_extra_info_file(mmi_email_account_extra_info_file *p_extra_info_file);
static void mmi_email_entry_edit_account_reset_extra_info_file(FS_HANDLE file_handle, mmi_email_account_extra_info_file *p_extra_info_file);
static void mmi_email_entry_edit_account_cacl_extra_info_file_check_sum(mmi_email_account_extra_info_file *p_extra_info_file);
static void mmi_email_auto_check_notify_callback(EMAIL_ACCT_ID account_id);
static mmi_email_operate_result_enum mmi_email_edit_account_create_new_account(
                                        EMAIL_SRV_HANDLE srv_handle, 
                                        srv_email_acct_info_struct *p_current_account,
                                        void *p_error);
static void mmi_email_install_pre_defined_accounts(void);
static void mmi_email_get_pre_defined_account_info(mmi_email_pre_defined_account_struct *p_pre_defined_account);
static void mmi_email_async_save_acct_callback(srv_email_result_enum result, void *user_data);
static mmi_ret mmi_email_entry_async_create_account_wait_screen(mmi_scrn_essential_struct* p_screen_data);
static mmi_ret mmi_email_entry_async_create_account_wait_screen_key_proc(mmi_event_struct *p_event);
static void mmi_email_find_redundent_account_algo(
                EMAIL_ACCT_ID *p_service_account_id_array,
                U32 service_account_num,
                EMAIL_ACCT_ID *p_verify_account_id_array,
                U32 verify_account_num,
                EMAIL_ACCT_ID *p_redundant_account_id_array,
                S32 *p_redundant_account_num);
static mmi_ret mmi_email_wizard_entry_recognize_screen(mmi_scrn_essential_struct* p_screen_data);
static void mmi_email_wizard_entry_recognize_screen_lsk(void);
static void mmi_email_wizard_entry_recognize_screen_rsk(void);

#ifdef __OP12__
static MMI_BOOL mmi_email_wizard_match_acct_with_template(
                WCHAR *p_email_addr,
                S32 *acct_template_index);
#endif /* __OP12__ */

/* variable defination */
static mmi_email_account_list_cntx_struct g_mmi_email_account_list_cntx;
static mmi_email_account_list_cntx_struct * const mmi_email_account_list_p = &g_mmi_email_account_list_cntx;

static mmi_email_asyc_create_account_struct g_mmi_email_asyn_create_account_cntx;
static mmi_email_asyc_create_account_struct * const mmi_email_asyn_create_account_p = &g_mmi_email_asyn_create_account_cntx;

static mmi_menu_id mmi_email_wizard_email_addr_menu_id_search[] = {
                    MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_SEARCH,
                    MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_CANCEL};
                    
static mmi_menu_id mmi_email_wizard_email_addr_menu_id_next[] = {
                    MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_NEXT,
                    MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_CANCEL};
                    
static mmi_menu_id mmi_email_wizard_incoming_server_menu_id_normal[] = {
                    MENU_ID_EMAIL_WIZARD_IN_SERVER_NEXT,
                    MENU_ID_EMAIL_WIZARD_IN_SERVER_CANCEL};
                    
static mmi_menu_id mmi_email_wizard_incoming_server_menu_id_empty[] = {
                    MENU_ID_EMAIL_WIZARD_IN_SERVER_CANCEL};

static mmi_menu_id mmi_email_wizard_outgoing_server_menu_id_normal[] = {
                    MENU_ID_EMAIL_WIZARD_OUT_SERVER_NEXT,
                    MENU_ID_EMAIL_WIZARD_OUT_SERVER_CANCEL};
                    
static mmi_menu_id mmi_email_wizard_outgoing_server_menu_id_empty[] = {
                    MENU_ID_EMAIL_WIZARD_OUT_SERVER_CANCEL};

static mmi_menu_id mmi_email_wizard_user_name_menu_id_normal[] = {
                    MENU_ID_EMAIL_WIZARD_USER_NAME_NEXT,
                    MENU_ID_EMAIL_WIZARD_USER_NAME_CANCEL};
                    
static mmi_menu_id mmi_email_wizard_user_name_menu_id_empty[] = {
                    MENU_ID_EMAIL_WIZARD_USER_NAME_CANCEL};

static mmi_menu_id mmi_email_wizard_password_menu_id_normal[] = {
                    MENU_ID_EMAIL_WIZARD_PASSWORD_NEXT,
                    MENU_ID_EMAIL_WIZARD_PASSWORD_CANCEL};

static mmi_menu_id mmi_email_wizard_password_menu_id_empty[] = {
                    MENU_ID_EMAIL_WIZARD_PASSWORD_NEXT,
                    MENU_ID_EMAIL_WIZARD_PASSWORD_CANCEL};

static mmi_menu_id mmi_email_wizard_account_name_menu_id_normal[] = {
                    MENU_ID_EMAIL_WIZARD_ACCT_NAME_DONE,
                    MENU_ID_EMAIL_WIZARD_ACCT_NAME_CANCEL};

static mmi_menu_id mmi_email_wizard_account_name_menu_id_empty[] = {
                    MENU_ID_EMAIL_WIZARD_ACCT_NAME_CANCEL};

static mmi_menu_id mmi_email_account_reply_addr_menu_id_search[] = {
                    MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_SEARCH,
                    MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_DONE};

static mmi_menu_id mmi_email_account_reply_addr_menu_id_done[] = {
                    MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_DONE};


/*****************************************************************************
* FUNCTION
*  mmi_email_check_account_id_validity
* DESCRIPTION
*  To check whether conflict with data account
* PARAMETERS
*  
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_email_check_account_id_validity(
                    EMAIL_ACCT_ID test_account_id,
                    EMAIL_ACCT_ID *p_account_id_array,
                    S32 account_id_array_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_value = MMI_FALSE;
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CHECK_ACCOUNT_ID_VALIDITY, __LINE__);

    for (i = 0; i < account_id_array_length; i++)
    {
        if (test_account_id == p_account_id_array[i])
        {
            ret_value = MMI_TRUE;
            break;
        }
    }
    return ret_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_init_inline_item_struct
* DESCRIPTION
*  Initialize the cui_inline_set_item_struct
* PARAMETERS
*  p_inline_item [IN]
*  item_id       [IN]
*  item_flag     [IN]
*  image_id      [IN]
*  item_data     [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_account_init_inline_item_struct(
                cui_inline_set_item_struct *p_inline_item,
                U16 item_id,
                U32 item_flag,
                U16 image_id,
                void *item_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCOUNT_INIT_INLINE_ITEM_STRUCT, __LINE__);

    p_inline_item->item_id = item_id;
    p_inline_item->item_flag = item_flag;
    p_inline_item->image_id = image_id;
    p_inline_item->item_data = item_data;
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_init_fullscreen_edit_struct
* DESCRIPTION
*  Initialize the cui_inline_item_fullscreen_edit_struct
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_account_init_fullscreen_edit_struct(
                cui_inline_item_fullscreen_edit_struct *p_fullscreen_item,
                U16 string_id,
                U16 default_text_id,
                U16 title,
                U16 title_icon,
                S16 input_extended_type,
                U32 input_type,
                S32 buffer_size,  
                mmi_imm_input_mode_enum *required_input_mode_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCOUNT_INIT_FULLSCREEN_EDIT_STRUCT, __LINE__);

    p_fullscreen_item->string_id = string_id;
    p_fullscreen_item->default_text_id = default_text_id;
    p_fullscreen_item->title = title;
    p_fullscreen_item->title_icon = title_icon;
    p_fullscreen_item->input_extended_type = input_extended_type;
    p_fullscreen_item->input_type = input_type;
    p_fullscreen_item->buffer_size = buffer_size;
    p_fullscreen_item->required_input_mode_set = required_input_mode_set;
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_init_inline_item_struct
* DESCRIPTION
*  Initialize the cui_inline_set_item_struct
* PARAMETERS
*  p_inline_item [IN]
*  item_id       [IN]
*  item_flag     [IN]
*  image_id      [IN]
*  item_data     [IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_account_init_select_struct(
                cui_inline_item_select_struct *p_select_item,
                U8 n_items,
                U8 highlighted_item,
                U16 *list_of_item_id) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCOUNT_INIT_SELECT_STRUCT, __LINE__);

    p_select_item->n_items = n_items;
    p_select_item->highlighted_item = highlighted_item;
    p_select_item->list_of_item_id = list_of_item_id;
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_init_text_edit_struct
* DESCRIPTION
*  Initialize the cui_inline_item_text_edit_struct
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_account_init_text_edit_struct(
                cui_inline_item_text_edit_struct *p_text_edit_item,
                U16 string_id,
                U16 default_text_id,
                U32 buffer_size,
                U32 input_type,
                S16 input_extended_type,
                mmi_imm_input_mode_enum *required_input_mode_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCOUNT_INIT_TEXT_EDIT_STRUCT, __LINE__);

    p_text_edit_item->string_id = string_id;
    p_text_edit_item->default_text_id = default_text_id;
    p_text_edit_item->buffer_size = buffer_size;
    p_text_edit_item->input_type = input_type;
    p_text_edit_item->input_extended_type = input_extended_type;
    p_text_edit_item->required_input_mode_set = required_input_mode_set;
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_get_total_account_info
* DESCRIPTION
*  Get the total account information
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static srv_email_result_enum mmi_email_get_total_account_info(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result;
    U32 account_num = 0;
    S32 i = 0;
    S32 account_count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_GET_TOTAL_ACCOUNT_INFO, __LINE__);

    srv_op_result = srv_email_acct_get_num(&account_num);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_GET_TOTAL_ACCOUNT_INFO_LOG1, account_num, srv_op_result);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        goto MMI_EMAIL_GET_TOTAL_ACCOUNT_INFO_END;
    }

    if (account_num > 0)
    {
        account_count = account_num;
        srv_op_result = srv_email_acct_get_acct_id(0, &account_count, p_account_list_cntx->account_id_array);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_GET_TOTAL_ACCOUNT_INFO_LOG2, srv_op_result);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            goto MMI_EMAIL_GET_TOTAL_ACCOUNT_INFO_END;
        }

        p_account_list_cntx->account_num = account_count;
        for (i = 0; i < account_count; i++)
        {
            srv_email_acct_info_cache_struct acct_info_cache;
            memset(&acct_info_cache, 0, sizeof(srv_email_acct_info_cache_struct));
            srv_email_acct_cache_get(p_account_list_cntx->account_id_array[i], &acct_info_cache);
            mmi_wcsncpy(p_account_list_cntx->account_name[i], 
                acct_info_cache.acct_name,
                SRV_EMAIL_MAX_ACCT_NAME_LEN);
        }
    }
    else
    {
        p_account_list_cntx->account_num = 0;
    }
MMI_EMAIL_GET_TOTAL_ACCOUNT_INFO_END:
    return srv_op_result;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_list_init
* DESCRIPTION
*  Initialize account list application
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_account_list_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT);
    memset(mmi_email_account_list_p, 0, sizeof(mmi_email_account_list_cntx_struct));
    mmi_email_account_list_p->group_id = GRP_ID_EMAIL_ACCOUNT_LIST;
    mmi_email_account_list_p->new_account_group_id = GPR_ID_EMAIL_ACCOUNT_NEW;
    mmi_email_account_list_p->edit_account_group_id = GPR_ID_EMAIL_ACCOUNT_EDIT;
    mmi_email_account_list_p->delete_account_group_id = GRP_ID_EMAIL_ACCOUNT_DELETE;
    mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;
    mmi_email_account_list_p->first_new_account = MMI_FALSE;
    mmi_email_account_list_p->current_account_handle = EMAIL_ACCT_INVALID_HANDLE;
    mmi_email_account_list_p->current_edit_account_id = EMAIL_ACCT_INVALID_ID;
    mmi_email_account_list_p->current_account_id = EMAIL_ACCT_INVALID_ID;
    kal_wsprintf(mmi_email_account_list_p->account_file_path, "%s%s", srv_email_get_root_path(), "account_extra_info.txt");
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_list_init_wait_app_core_ready
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_account_list_init_wait_app_core_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_APP_CORE_READY_LOG1);
    mmi_email_account_start_auto_check_service();
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_list_init_wait_service_ready
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_account_list_init_wait_service_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 account_num = 0;
    mmi_email_app_core_result_enum app_core_op_result = MMI_EMAIL_FAIL;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    EMAIL_ACCT_ID account_id_array[MMI_EMAIL_MAX_ACCTS];
    EMAIL_ACCT_ID *p_verify_account_id = NULL;
    U16 verify_account_id_num = MMI_EMAIL_MAX_ACCTS;
    S32 i = 0;
    EMAIL_ACCT_ID *p_redundant_account_id = NULL;
    S32 redundant_account_num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG1);
    srv_op_result = srv_email_acct_get_num(&account_num);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG2, srv_op_result, account_num);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        goto MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_END;
    }

    if (account_num > 0)
    {
        srv_op_result = srv_email_acct_get_acct_id(0, (S32*)&account_num, account_id_array);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG3, srv_op_result);
            goto MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_END;
        }
    }

    p_verify_account_id = OslMalloc(sizeof(EMAIL_ACCT_ID) * MMI_EMAIL_MAX_ACCTS);
    p_redundant_account_id = OslMalloc(sizeof(EMAIL_ACCT_ID) * MMI_EMAIL_MAX_ACCTS * 3);
    
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    app_core_op_result = mmi_email_auto_check_list_acct_id(p_verify_account_id, &verify_account_id_num);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG4, app_core_op_result, verify_account_id_num);
    if (MMI_EMAIL_SUCCESS == app_core_op_result)
    {
        for (i = 0; i < verify_account_id_num; i++)
        {
            if (MMI_FALSE == mmi_email_check_account_id_validity(
                                p_verify_account_id[i], 
                                account_id_array, 
                                account_num))
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG5, i, p_verify_account_id[i]);
                mmi_email_auto_check_delete_acct(p_verify_account_id[i], MMI_TRUE);
            }
        }
        mmi_email_find_redundent_account_algo(
            account_id_array, 
            account_num, 
            p_verify_account_id, 
            verify_account_id_num, 
            p_redundant_account_id, 
            &redundant_account_num);
    }
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

    verify_account_id_num = MMI_EMAIL_MAX_ACCTS;
    app_core_op_result = mmi_email_sig_list_acct_id(p_verify_account_id, &verify_account_id_num);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG6, app_core_op_result, verify_account_id_num);
    if (MMI_EMAIL_SUCCESS == app_core_op_result)
    {
        for (i = 0; i < verify_account_id_num; i++)
        {
            if (MMI_FALSE == mmi_email_check_account_id_validity(
                                p_verify_account_id[i], 
                                account_id_array, 
                                account_num))
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG7, i, p_verify_account_id[i]);
                mmi_email_sig_delete_acct(p_verify_account_id[i], MMI_TRUE);
            }
        }
        mmi_email_find_redundent_account_algo(
            account_id_array, 
            account_num, 
            p_verify_account_id, 
            verify_account_id_num, 
            p_redundant_account_id, 
            &redundant_account_num);
    }

    verify_account_id_num = MMI_EMAIL_MAX_ACCTS;
    if (MMI_TRUE == mmi_email_entry_edit_account_list_account_extra_info_id(
                        p_verify_account_id, 
                        &verify_account_id_num, 
                        NULL))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG8, verify_account_id_num);
        for (i = 0; i < verify_account_id_num; i++)
        {
            if (MMI_FALSE == mmi_email_check_account_id_validity(
                                p_verify_account_id[i], 
                                account_id_array, 
                                account_num))
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG9, i, p_verify_account_id[i]);
                mmi_email_entry_edit_account_delete_account_extra_info(p_verify_account_id[i], NULL);
            }
        }
        mmi_email_find_redundent_account_algo(
            account_id_array, 
            account_num, 
            p_verify_account_id, 
            verify_account_id_num, 
            p_redundant_account_id, 
            &redundant_account_num);
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG11, redundant_account_num);
    for (i = 0; i < redundant_account_num; i++)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG12, i, p_redundant_account_id[i]);
        mmi_email_auto_check_delete_acct(p_redundant_account_id[i], MMI_TRUE);
        mmi_email_sig_delete_acct(p_redundant_account_id[i], MMI_TRUE);
        mmi_email_entry_edit_account_delete_account_extra_info(p_redundant_account_id[i], NULL);
        srv_email_acct_delete(p_redundant_account_id[i]);
    }
    
MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_END:
    mmi_email_install_pre_defined_accounts();
    if (NULL != p_verify_account_id)
    {
        OslMfree(p_verify_account_id);
        p_verify_account_id = NULL;
    }
    if (NULL != p_redundant_account_id)
    {
        OslMfree(p_redundant_account_id);
        p_redundant_account_id = NULL;
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_LIST_INIT_WAIT_SERVICE_READY_LOG10);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_launch
* DESCRIPTION
*  Entry account list
* PARAMETERS
*  parent_id  [IN] The parent id of GRP_ID_EMAIL_ACCOUNT_LIST
* RETURNS
*  void
*****************************************************************************/
void mmi_email_entry_account_list_launch(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_ACCOUNT_LIST_LAUNCH, parent_id, GRP_ID_EMAIL_ACCOUNT_LIST);
    mmi_email_account_list_p->group_id = GRP_ID_EMAIL_ACCOUNT_LIST;
    mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;
    mmi_frm_group_create(parent_id, mmi_email_account_list_p->group_id, mmi_email_entry_account_list_proc, mmi_email_account_list_p);
    mmi_frm_group_enter(mmi_email_account_list_p->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(
            mmi_email_account_list_p->group_id, 
            SCR_ID_EMAIL_PROF, 
            (FuncPtr)mmi_email_entry_account_list_screen, 
            mmi_email_account_list_p);

    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_proc
* DESCRIPTION
*  The procedure function of GRP_ID_EMAIL_ACCOUNT_LIST
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_account_list_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_ACCOUNT_LIST_PROC, p_event->evt_id);
    switch (p_event->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_email_entry_account_list_proc_handle_cui_menu_list_entry_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_LIST_EXIT:
        break;

    case EVT_ID_CUI_MENU_ITEM_HILITE:
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        mmi_email_entry_account_list_proc_handle_cui_menu_item_select_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_email_entry_account_list_proc_handle_cui_menu_item_close_request_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_SUBMIT:
        mmi_email_entry_account_list_proc_handle_cui_inline_submit_message((cui_event_inline_submit_struct*)p_event);
        break;

    case EVT_ID_CUI_FSEDITOR_ABORT:
        mmi_email_entry_account_list_proc_handle_cui_fseditor_abort_message((cui_fseditor_evt_struct*)p_event);
        break;

    case EVT_ID_GROUP_FOCUSED:
        mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->group_id);
        break;

    default:
        break;

    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_screen_highlight_handler
* DESCRIPTION
*  The highlight handler of account list menuitem
* PARAMETERS
*  index  [IN] The index of menuitem
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_account_list_screen_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_p->current_account_id = mmi_email_account_list_p->account_id_array[index];
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_ACCOUNT_LIST_SCREEN_HILIGHT, index, mmi_email_account_list_p->current_account_id);
    return;
}

#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
static void mmi_email_acct_edit_list_sel_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_email_account_list_have_account_csk_handler();
    }
}
#endif /* #if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__) */

/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_screen
* DESCRIPTION
*  Entry the account list display screen
* PARAMETERS
*  p_screen_data  [IN] The screen data
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_account_list_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    srv_email_result_enum result;
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_ACCOUNT_LIST_SCREEN, __LINE__);
    if (MMI_TRUE == mmi_frm_scrn_enter(
                    p_screen_data->group_id, 
                    p_screen_data->scrn_id, 
                    NULL, 
                    (FuncPtr)mmi_email_entry_account_list_screen, 
                    MMI_FRM_FULL_SCRN))
    {
        p_account_list_cntx = p_screen_data->user_data;

        if ((result = mmi_email_get_total_account_info(p_account_list_cntx)) == SRV_EMAIL_RESULT_SUCC)
        {
            guiBuffer = mmi_frm_scrn_get_active_gui_buf();
            RegisterHighlightHandler(mmi_email_entry_account_list_screen_highlight_handler);
            if (0 == p_account_list_cntx->account_num)
            {
                EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
            }
            else
            {
                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            }
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_ACCOUNT_LIST_SCREEN, __LINE__);

            ShowCategory184Screen(
                STR_EMAIL_EMAIL_ACCTS_ID, 
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN), 
                STR_GLOBAL_OPTIONS, 
                IMG_GLOBAL_OPTIONS, 
                STR_GLOBAL_BACK, 
                IMG_GLOBAL_BACK, 
                p_account_list_cntx->account_num, 
                mmi_email_get_account_name, 
                NULL, 
                0, 
                guiBuffer);

            SetLeftSoftkeyFunction(mmi_email_entry_account_list_option, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
            if (0 == p_account_list_cntx->account_num)
            {
                SetCenterSoftkeyFunction(mmi_email_entry_account_list_option, KEY_EVENT_UP);
            }
            else
            {
                SetCenterSoftkeyFunction(mmi_email_account_list_have_account_csk_handler, KEY_EVENT_UP);
            }
            
        #if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
            wgui_register_tap_callback(mmi_email_acct_edit_list_sel_tap_callback);
        #endif /* __MMI_FTE_SUPPORT__ */
        }
        else
        {
            mmi_email_util_display_error_popup(p_screen_data->group_id, result);
            mmi_frm_scrn_close(p_screen_data->group_id, p_screen_data->scrn_id);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_get_account_name
 * DESCRIPTION
 *  Call back to get the book mark names
 * PARAMETERS
 *  account_index       [IN]        
 *  account_name        [OUT]        
 *  account_image       [OUT]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static pBOOL mmi_email_get_account_name(S32 account_index, UI_string_type account_name, PU8 *account_image, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_GET_ACCOUNT_NAME, __LINE__);

    mmi_wcsncpy(account_name, email_mmi_account_data_get_name(account_index), MAX_SUBMENU_CHARACTERS);
    *account_image = get_image(email_mmi_account_data_get_icon1(account_index));

    return TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_set_menu_screen
* DESCRIPTION
*  Set the menu screen
* PARAMETERS
*  screen_id  [IN] The screen's id
*  p_menu_screen_struct [IN] The structure of menu screen
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_account_set_menu_screen(mmi_id screen_id, mmi_email_menu_screen_struct *p_menu_screen_struct, U16 StringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCOUNT_SET_MENU_SCREEN, __LINE__);

    cui_menu_set_currlist_left_softkey(screen_id, (WCHAR*)GetString(StringId));
    cui_menu_set_currlist_title(screen_id, (WCHAR*)GetString(p_menu_screen_struct->title_string_id), (UI_image_type)GetImage(p_menu_screen_struct->title_icon_id));
    cui_menu_set_currlist(screen_id, p_menu_screen_struct->menu_item_number, p_menu_screen_struct->menu_id_array);
    for (i = 0; i < p_menu_screen_struct->menu_item_number; i++)
    {
        cui_menu_set_item_string(screen_id, p_menu_screen_struct->menu_id_array[i], (WCHAR*)GetString(p_menu_screen_struct->menu_id_string_array[i]));
        cui_menu_set_item_image(screen_id, p_menu_screen_struct->menu_id_array[i], p_menu_screen_struct->menu_id_image_array[i]);
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_list_have_account_csk_handler
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_account_list_have_account_csk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCOUNT_LIST_HAVE_ACCOUNT_CSK_HANDLER, __LINE__);
    mmi_email_entry_edit_account_process(mmi_email_account_list_p);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_option
* DESCRIPTION
*  The left softkey handler of account list screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_account_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id option_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_ACCOUNT_LIST_OPTION, __LINE__);
    option_id = cui_menu_create(
                    mmi_email_account_list_p->group_id, 
                    CUI_MENU_SRC_TYPE_APPCREATE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_EMAIL_PROF_OPT, 
                    MMI_FALSE, 
                    mmi_email_account_list_p);
    cui_menu_run(option_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_proc_handle_cui_menu_list_entry_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_LIST_ENTRY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_LIST_ENTRY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_account_list_proc_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_ACCOUNT_LIST_PROC_HANDLE_CUI_MENU_LIST_ENTRY_MESSAGE, __LINE__);

    switch (p_event->parent_menu_id)
    {
        case MENU_ID_EMAIL_PROF_OPT:
        {
            mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
            EMAIL_ACCT_ID default_account_id = EMAIL_ACCT_INVALID_ID;
            
            mmi_menu_id option_normal_menu_id_array[] = {MENU_ID_EMAIL_PROF_EDIT, MENU_ID_EMAIL_ACCT_NEW, MENU_ID_EMAIL_ACCT_DELETE};
            U16 option_normal_menu_id_string_array[] = {STR_GLOBAL_EDIT, STR_EMAIL_NEW_ACCT_ID, STR_GLOBAL_DELETE, STR_GLOBAL_STORAGE};

            mmi_menu_id option_full_menu_id_array[] = {MENU_ID_EMAIL_PROF_EDIT, MENU_ID_EMAIL_ACCT_DELETE};
            U16 option_full_menu_id_string_array[] = {STR_GLOBAL_EDIT, STR_GLOBAL_DELETE};
            
            mmi_menu_id option_empty_menu_id_array[] = {MENU_ID_EMAIL_ACCT_NEW};
            U16 option_empty_menu_id_string_array[] = {STR_EMAIL_NEW_ACCT_ID};

            mmi_email_menu_screen_struct menu_screen;

            p_account_list_cntx = p_event->user_data;

            srv_email_acct_get_default(&default_account_id);
            
            menu_screen.title_string_id = STR_GLOBAL_OPTIONS;
            menu_screen.title_icon_id = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
            if (MMI_EMAIL_MAX_ACCTS == p_account_list_cntx->account_num)
            {
                menu_screen.menu_item_number = sizeof(option_full_menu_id_array) / sizeof(mmi_menu_id);
                menu_screen.menu_id_array = option_full_menu_id_array;
                menu_screen.menu_id_string_array = option_full_menu_id_string_array;
            }
            else if (0 == p_account_list_cntx->account_num)
            {
                menu_screen.menu_item_number = sizeof(option_empty_menu_id_array) / sizeof(mmi_menu_id);
                menu_screen.menu_id_array = option_empty_menu_id_array;
                menu_screen.menu_id_string_array = option_empty_menu_id_string_array;
            }
            else
            {
                menu_screen.menu_item_number = sizeof(option_normal_menu_id_array) / sizeof(mmi_menu_id);
                menu_screen.menu_id_array = option_normal_menu_id_array;
                menu_screen.menu_id_string_array = option_normal_menu_id_string_array;
            }
            menu_screen.menu_id_image_array = (U16*)gIndexIconsImageList;
            mmi_email_account_set_menu_screen(p_event->sender_id, &menu_screen, STR_GLOBAL_SELECT);

            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_proc_handle_cui_menu_item_select_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_ITEM_SELECT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_ITEM_SELECT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_account_list_proc_handle_cui_menu_item_select_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_ACCOUNT_LIST_PROC_HANDLE_CUI_MENU_ITEM_SELECT_MESSAGE, __LINE__);

    /* Get the account list context */
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    if (MENU_ID_EMAIL_PROF_OPT == p_event->parent_menu_id)
    {
        switch (p_event->highlighted_menu_id)
        {
        case MENU_ID_EMAIL_PROF_EDIT:
            mmi_email_entry_edit_account_process(p_account_list_cntx);
            break;

        case MENU_ID_EMAIL_ACCT_NEW:
            mmi_email_entry_new_account_with_template_process(p_account_list_cntx);
            break;

        case MENU_ID_EMAIL_ACCT_DELETE:
            mmi_email_entry_delete_account_process(p_account_list_cntx);
            break;

        default:
            break;
        }
    }

    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_proc_handle_cui_menu_item_close_request_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_CLOSE_REQUEST
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_CLOSE_REQUEST event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_account_list_proc_handle_cui_menu_item_close_request_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_ACCOUNT_LIST_PROC_HANDLE_CUI_MENU_ITEM_CLOSE_REQUEST_MESSAGE, __LINE__);

    cui_menu_close(p_event->sender_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_proc_handle_cui_inline_submit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SUBMIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SUBMIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_account_list_proc_handle_cui_inline_submit_message(cui_event_inline_submit_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_ACCOUNT_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE, __LINE__);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_account_list_proc_handle_cui_fseditor_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_account_list_proc_handle_cui_fseditor_abort_message(cui_fseditor_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_ACCOUNT_LIST_PROC_HANDLE_CUI_FSEDITOR_ABORT_MESSAGE, __LINE__);

    cui_fseditor_close(p_event->sender_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_new_account_launch_confirm_callback
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_wizard_new_account_launch_confirm_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;
    mmi_alert_result_evt_struct *p_event = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_NEW_ACCOUNT_LAUNCH_CONFIRM_CALLBACK, __LINE__);

    p_event = (mmi_alert_result_evt_struct*)event;
    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
        case MMI_EMAIL_ACCOUNT_ALERT_NEW_ACCOUNT_LAUNCH:
        {
            if (MMI_ALERT_CNFM_YES == p_event->result)
            {
                mmi_email_wizard_new_account_launch_lsk();
            }
            else if (MMI_ALERT_CNFM_NO == p_event->result)
            {
                mmi_email_wizard_new_account_launch_rsk();
            }
            else if (MMI_ALERT_INTERRUPT_EXIT == p_event->result)
            {
                mmi_email_acct_setting_evt_struct setting_event;
                mmi_group_node_struct group_info;
                
                if (MMI_RET_OK == mmi_frm_group_get_info(mmi_email_get_main_group_id(), &group_info))
                {
                    MMI_FRM_INIT_GROUP_EVENT(&setting_event, EVT_ID_ACCT_SETTING_EXIT, GRP_ID_EMAIL_ACCOUNT_WIZARD);
                    MMI_FRM_POST_EVENT(&setting_event, group_info.proc, NULL);
                }
            }
        }
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_new_account_launch
* DESCRIPTION
*  New a account wizard
* PARAMETERS
*  parent_id  [IN] The parent id
* RETURNS
*  void
*****************************************************************************/
void mmi_email_wizard_new_account_launch(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_NEW_ACCOUNT_LAUNCH, parent_id, GRP_ID_EMAIL_ACCOUNT_WIZARD);
    mmi_email_account_list_p->group_id = GRP_ID_EMAIL_ACCOUNT_WIZARD;
    mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;
    mmi_frm_group_create(
        parent_id,
        mmi_email_account_list_p->group_id, 
        NULL, 
        mmi_email_account_list_p);
    mmi_frm_group_enter(mmi_email_account_list_p->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = mmi_email_account_list_p->group_id;
    confirm_struct.user_tag = (void*)MMI_EMAIL_ACCOUNT_ALERT_NEW_ACCOUNT_LAUNCH;
    confirm_struct.callback = mmi_email_wizard_new_account_launch_confirm_callback;
    mmi_confirm_display((WCHAR*)GetString(STR_EMAIL_START_CREATE_ACCT_ID), MMI_EVENT_QUERY, &confirm_struct);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_new_account_launch_lsk
* DESCRIPTION
*  New a account wizard lsk
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_new_account_launch_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_NEW_ACCOUNT_LAUNCH_LSK, __LINE__);

    mmi_email_entry_new_account_with_template_process(mmi_email_account_list_p);
    return;       
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_new_account_launch_lsk
* DESCRIPTION
*  New a account wizard lsk
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_new_account_launch_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_NEW_ACCOUNT_LAUNCH_RSK, __LINE__);

    mmi_frm_scrn_close_active_id();
    return;       
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_with_template_process
* DESCRIPTION
*  New a account with template
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_with_template_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_core_result_enum app_core_op_result = MMI_EMAIL_FAIL;
    U32 account_num = 0;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_WITH_TEMPLATE_PROCESS, __LINE__);

    srv_op_result = srv_email_acct_get_num(&account_num);
    if ((SRV_EMAIL_RESULT_SUCC == srv_op_result) && (0 == account_num))
    {
        mmi_email_account_list_p->first_new_account = MMI_TRUE;
    }
    app_core_op_result = mmi_email_acct_temp_get_num(&(p_account_list_cntx->template_num));
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_NEW_ACCOUNT_WITH_TEMPLATE_PROCESS, app_core_op_result, mmi_email_account_list_p->template_num);
    if ((mmi_email_account_list_p->template_num > 0) && (MMI_EMAIL_SUCCESS == app_core_op_result))
    {   //  entry screen of account creation from template
        mmi_email_wizard_entry_template_list_process(p_account_list_cntx);
    }
    else
    {
        mmi_email_entry_new_account_process(p_account_list_cntx);
    }
    
    return;       
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_process
* DESCRIPTION
*  New a account
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROCESS, __LINE__);
    mmi_frm_group_create(
        p_account_list_cntx->group_id, 
        p_account_list_cntx->new_account_group_id, 
        mmi_email_entry_new_account_proc, 
        p_account_list_cntx);

    mmi_frm_group_enter(p_account_list_cntx->new_account_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    srv_op_result = srv_email_acct_init_acct_info(&(p_account_list_cntx->current_account));
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        mmi_email_util_display_error_popup(p_account_list_cntx->new_account_group_id, srv_op_result);
        goto MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROCESS_END;
    }

#ifdef __OP12__
    memcpy(
        p_account_list_cntx->current_account.email_addr.email_addr,
        p_account_list_cntx->input_template.email_addr,
        (SRV_EMAIL_MAX_ADDR_LEN + 1) * sizeof(WCHAR));
    memcpy(
        p_account_list_cntx->current_account.in_auth.username,
        p_account_list_cntx->input_template.in_auth.username,
        (SRV_EMAIL_MAX_USERNAME_LEN + 1) * sizeof(WCHAR));
    memcpy(
        p_account_list_cntx->current_account.in_auth.password,
        p_account_list_cntx->input_template.in_auth.password,
        (SRV_EMAIL_MAX_PASSWORD_LEN + 1) * sizeof(WCHAR));
#endif /* __OP12__ */

    mmi_email_wizard_entry_email_addr_process(p_account_list_cntx);

MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROCESS_END:
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROCESS, srv_op_result);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc
* DESCRIPTION
*  The procedure function of GPR_ID_EMAIL_ACCOUNT_NEW
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_new_account_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, p_event->evt_id);
    switch (p_event->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_EXIT:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            cui_fseditor_custom_menu_select_evt_struct* pe = (cui_fseditor_custom_menu_select_evt_struct*)p_event;
            if (pe->menu_id == MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_SEARCH)
            {
                cui_menu_enable_center_softkey(pe->sender_id, 0, IMG_GLOBAL_SEARCH_CSK);
            }
            else
            {
                cui_menu_enable_center_softkey(pe->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
            }                
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_entry_new_account_proc_handle_cui_menu_item_close_request_message((cui_menu_event_struct*)p_event);            
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_entry_new_account_proc_handle_cui_fseditor_abort_message((cui_fseditor_evt_struct*)p_event);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_EMPTY:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_entry_new_account_proc_handle_cui_fseditor_empty_message((cui_fseditor_evt_struct*)p_event);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_entry_new_account_proc_handle_cui_fseditor_not_empty_message((cui_fseditor_evt_struct*)p_event);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_entry_new_account_proc_handle_cui_fseditor_menu_select_message((cui_fseditor_custom_menu_select_evt_struct*)p_event);
            break;
        }
        case EVT_ID_PHB_SELECT_CONTACT:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_entry_new_account_proc_handle_phb_select_contact_message((cui_phb_select_contact_result_struct*)p_event);
            break;
        }
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_entry_new_account_proc_handle_phb_select_contact_cancel_message((cui_phb_select_contact_result_struct*)p_event);
            break;
        }
        case EVT_ID_GROUP_FOCUSED:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->new_account_group_id);
            break;
        }
        case EVT_ID_ALERT_QUIT:
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC, __LINE__);
        {
            mmi_email_entry_new_account_proc_handle_alert_quit_message((mmi_alert_result_evt_struct*)p_event);
            break;
        }
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc_handle_cui_menu_item_close_request_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_CLOSE_REQUEST
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_CLOSE_REQUEST event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_proc_handle_cui_menu_item_close_request_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get the account list context */
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC_HANDLE_CUI_MENU_ITEM_CLOSE_REQUEST_MESSAGE, __LINE__);

    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    if (MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_PROTOCOL == p_account_list_cntx->state)
    {
        mmi_email_wizard_entry_email_addr_process(p_account_list_cntx);
    }
    cui_menu_close(p_event->sender_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc_handle_cui_fseditor_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_proc_handle_cui_fseditor_abort_message(cui_fseditor_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC_HANDLE_CUI_FSEDITOR_ABORT_MESSAGE, __LINE__);

    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    switch (p_account_list_cntx->state)
    {
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_INCOMING_SERVER:
        {
            mmi_email_wizard_entry_data_account_process(p_account_list_cntx);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_OUTGOING_SERVER:
        {
            mmi_email_wizard_entry_incoming_server_process(p_account_list_cntx);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_USER_NAME:
        {
            mmi_email_wizard_entry_outgoing_server_process(p_account_list_cntx);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_PASSWORD:
        {
            mmi_email_wizard_entry_user_name_process(p_account_list_cntx);
            break;

        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_ACCOUNT_NAME:
        {
            mmi_email_wizard_entry_password_process(p_account_list_cntx);
            break;
        }
        default:
        {
            break;
        }
    }

    cui_fseditor_close(p_event->sender_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc_handle_cui_fseditor_empty_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_EMPTY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_EMPTY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_proc_handle_cui_fseditor_empty_message(cui_fseditor_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC_HANDLE_CUI_FSEDITOR_EMPTY_MESSAGE, __LINE__);

    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    switch (p_account_list_cntx->state)
    {
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_EMAIL_ADDR:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_email_addr_menu_id_search, 
                (sizeof(mmi_email_wizard_email_addr_menu_id_search) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_INCOMING_SERVER:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_incoming_server_menu_id_empty, 
                (sizeof(mmi_email_wizard_incoming_server_menu_id_empty) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_OUTGOING_SERVER:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_outgoing_server_menu_id_empty, 
                (sizeof(mmi_email_wizard_outgoing_server_menu_id_empty) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_USER_NAME:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_user_name_menu_id_empty, 
                (sizeof(mmi_email_wizard_user_name_menu_id_empty) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_PASSWORD:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_password_menu_id_empty, 
                (sizeof(mmi_email_wizard_password_menu_id_empty) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_ACCOUNT_NAME:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_account_name_menu_id_empty, 
                (sizeof(mmi_email_wizard_account_name_menu_id_empty) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc_handle_cui_fseditor_menu_select_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_proc_handle_cui_fseditor_menu_select_message(cui_fseditor_custom_menu_select_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get the account list context */
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC_HANDLE_CUI_FSEDITOR_MENU_SELECT_MESSAGE, __LINE__);

    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)p_event->user_data;

    switch (p_event->menu_id)
    {
        case MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_SEARCH:
        {
            mmi_email_wizard_email_addr_search_handler(p_event->sender_id, p_account_list_cntx);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_NEXT:
        {
            mmi_email_wizard_email_addr_next_handler(p_event->sender_id, p_account_list_cntx);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_IN_SERVER_NEXT:
        {
            mmi_email_wizard_incoming_server_next_handler(p_event->sender_id, p_account_list_cntx);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_OUT_SERVER_NEXT:
        {
            mmi_email_wizard_outgoing_server_next_handler(p_event->sender_id, p_account_list_cntx);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_USER_NAME_NEXT:
        {
            mmi_email_wizard_user_name_next_handler(p_event->sender_id, p_account_list_cntx);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_PASSWORD_NEXT:
        {
            mmi_email_wizard_password_next_handler(p_event->sender_id, p_account_list_cntx);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_CANCEL:
        case MENU_ID_EMAIL_WIZARD_PROTOCOL_CANCEL:
        case MENU_ID_EMAIL_WIZARD_DATA_ACCT_CANCEL:
        case MENU_ID_EMAIL_WIZARD_IN_SERVER_CANCEL:
        case MENU_ID_EMAIL_WIZARD_OUT_SERVER_CANCEL:
        case MENU_ID_EMAIL_WIZARD_USER_NAME_CANCEL:
        case MENU_ID_EMAIL_WIZARD_PASSWORD_CANCEL:
        case MENU_ID_EMAIL_WIZARD_ACCT_NAME_CANCEL:
        {
            mmi_email_wizard_entry_cancel_process(p_account_list_cntx);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_ACCT_NAME_DONE:
        {
            mmi_email_wizard_account_name_done_handler(p_event->sender_id, p_account_list_cntx);
            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc_handle_cui_fseditor_not_empty_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_NOT_EMPTY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_NOT_EMPTY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_proc_handle_cui_fseditor_not_empty_message(cui_fseditor_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC_HANDLE_CUI_FSEDITOR_NOT_EMPTY_MESSAGE, __LINE__);

    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    switch (p_account_list_cntx->state)
    {
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_EMAIL_ADDR:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_email_addr_menu_id_next, 
                (sizeof(mmi_email_wizard_email_addr_menu_id_next) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_INCOMING_SERVER:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_incoming_server_menu_id_normal, 
                (sizeof(mmi_email_wizard_incoming_server_menu_id_normal) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_OUTGOING_SERVER:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_outgoing_server_menu_id_normal, 
                (sizeof(mmi_email_wizard_outgoing_server_menu_id_normal) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_USER_NAME:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_user_name_menu_id_normal, 
                (sizeof(mmi_email_wizard_user_name_menu_id_normal) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_PASSWORD:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_password_menu_id_normal, 
                (sizeof(mmi_email_wizard_password_menu_id_normal) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        case MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_ACCOUNT_NAME:
        {
            cui_fseditor_set_custom_options_menu(
                p_event->sender_id, 
                MMI_TRUE, 
                mmi_email_wizard_account_name_menu_id_normal, 
                (sizeof(mmi_email_wizard_account_name_menu_id_normal) / sizeof(mmi_menu_id)));
            cui_fseditor_disable_cancel_options_item(p_event->sender_id, MMI_TRUE);
            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc_handle_phb_select_contact_message
* DESCRIPTION
*  The handle function of EVT_ID_PHB_SELECT_CONTACT
* PARAMETERS
*  p_event   [IN] EVT_ID_PHB_SELECT_CONTACT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_proc_handle_phb_select_contact_message(cui_phb_select_contact_result_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC_HANDLE_PHB_SELECT_CONTACT_MESSAGE, __LINE__);

    p_account_list_cntx = p_event->user_data;
    p_account_list_cntx->select_email_addr_from_phb.select_from_phb = MMI_TRUE;

    mmi_wcsncpy(
        p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_name,
        p_event->name,
        SRV_EMAIL_MAX_DISP_NAME_LEN);
    p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_name_len = mmi_wcslen(p_event->name);
    p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_charset = MMI_CHSET_UCS2;

    mmi_wcsncpy(
        p_account_list_cntx->select_email_addr_from_phb.email_addr.email_addr, 
        p_event->select_data, 
        SRV_EMAIL_MAX_ADDR_LEN);
    
    cui_fseditor_set_text(
        p_account_list_cntx->current_fseditor_id, 
        p_account_list_cntx->select_email_addr_from_phb.email_addr.email_addr, 
        sizeof(p_account_list_cntx->select_email_addr_from_phb.email_addr.email_addr), 
        SRV_EMAIL_MAX_ADDR_LEN);

    p_account_list_cntx->current_fseditor_id = GRP_ID_INVALID;
    
    cui_phb_list_select_contact_close(p_event->sender_id);
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc_handle_phb_select_contact_cancel_message
* DESCRIPTION
*  The handle function of EVT_ID_PHB_SELECT_CONTACT_CANCEL
* PARAMETERS
*  p_event   [IN] EVT_ID_PHB_SELECT_CONTACT_CANCEL event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_proc_handle_phb_select_contact_cancel_message(cui_phb_select_contact_result_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC_HANDLE_PHB_SELECT_CONTACT_CANCEL_MESSAGE, __LINE__);

    p_account_list_cntx = p_event->user_data;
    p_account_list_cntx->current_fseditor_id = GRP_ID_INVALID;

    cui_phb_list_select_contact_close(p_event->sender_id);
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_new_account_proc_handle_alert_quit_message
* DESCRIPTION
*  The handle function of EVT_ID_ALERT_QUIT
* PARAMETERS
*  p_event   [IN] EVT_ID_ALERT_QUIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_new_account_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_NEW_ACCOUNT_PROC_HANDLE_ALERT_QUIT_MESSAGE, __LINE__);

    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
        case MMI_EMAIL_ACCOUNT_ALERT_WIZARD_CANCEL:
        {
            if (MMI_ALERT_CNFM_YES == p_event->result)
            {
                mmi_email_wizard_cancel_operation();
            }
            else if (MMI_ALERT_CNFM_NO == p_event->result)
            {
                mmi_frm_scrn_close_active_id();
            }
        }
        default:
        {
            break;
        }
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_process
* DESCRIPTION
*  Entry the template screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_template_list_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROCESS, __LINE__);

    p_account_list_cntx->highlight_template_index = 0;
    p_account_list_cntx->new_account_template_group_id = mmi_frm_group_create(
                                                            p_account_list_cntx->group_id, 
                                                            GRP_ID_AUTO_GEN, 
                                                            mmi_email_wizard_entry_template_list_proc, 
                                                            p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->new_account_template_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        p_account_list_cntx->new_account_template_group_id, 
        SCR_ID_EMAIL_WIZARD_TEMPLATE_SELECT, 
        (FuncPtr)mmi_email_wizard_entry_template_list_screen, 
        p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_proc
* DESCRIPTION
*  The procedure function of protocol group
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_wizard_entry_template_list_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC, __LINE__);
    switch (p_event->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            mmi_email_wizard_entry_template_list_proc_handle_cui_inline_submit_message((cui_event_inline_submit_struct*)p_event);
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            mmi_email_wizard_entry_template_list_proc_handle_cui_inline_abort_message((cui_event_inline_abort_struct*)p_event);
            break;
        }
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_proc_handle_cui_inline_submit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SUBMIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SUBMIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_template_list_proc_handle_cui_inline_submit_message(cui_event_inline_submit_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *p_email_addr = NULL;
    WCHAR *p_password = NULL;
    mmi_email_acct_temp_struct *p_acct_temp_struct = NULL;
    mmi_email_account_list_cntx_struct * p_account_list_cntx = NULL;
    
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    EMAIL_ACCT_HANDLE account_handle = EMAIL_ACCT_INVALID_HANDLE;
    mmi_email_app_core_result_enum app_core_result = MMI_EMAIL_SUCCESS;
    mmi_email_operate_result_enum create_result = MMI_EMAIL_OPERATE_RESULT_SUCCESS;

    mmi_email_account_error_code_struct error_info;
    S32 highlight_template_index = 0;
    U32 user_name_length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	p_account_list_cntx = p_event->user_data;

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_SUBMIT_LOG1, p_account_list_cntx->highlight_template_index);
 
    p_email_addr = OslMalloc((SRV_EMAIL_MAX_ADDR_LEN + 1) * sizeof(WCHAR));
    // get Email address
    cui_inline_get_value(p_event->sender_id, MMI_EMAIL_TEMPLATE_EDIT_EMAIL_ADDRESS_CONTENT_ID, p_email_addr);
    if (0 == mmi_wcslen((const WCHAR*)p_email_addr))
    {   
        // address not valid
        mmi_email_lib_error_popup(STR_EMAIL_EMAIL_ADDRESS_EMPTY);
        goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END;
    }
    else if (!mmi_email_util_chk_addr(p_email_addr))
    {
        mmi_email_lib_error_popup(STR_GLOBAL_INVALID_EMAIL_ADDRESS);
        goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END;
    }
    // get Email password
    p_password = OslMalloc((SRV_EMAIL_MAX_PASSWORD_LEN + 1) * sizeof(WCHAR));
    cui_inline_get_value(p_event->sender_id, MMI_EMAIL_TEMPLATE_EDIT_USER_PASSWORD_CONTENT_ID, p_password);
    if (0 == mmi_wcslen((const WCHAR*)p_password))
    {
        mmi_email_lib_error_popup(STR_EMAIL_PASSWORD_EMPTY_ID);
        goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END;
    }

    user_name_length = (mmi_wcschr((const WCHAR*)p_email_addr, L'@') - p_email_addr);
    if (user_name_length > SRV_EMAIL_MAX_USERNAME_LEN)
    {
        user_name_length = SRV_EMAIL_MAX_USERNAME_LEN;
    }
#ifdef __OP12__
    if (MMI_TRUE == mmi_email_wizard_match_acct_with_template(
                        p_email_addr,
                        &highlight_template_index))
    {
    }
    else
    {
        mmi_frm_scrn_first_enter(
            p_account_list_cntx->new_account_template_group_id,
            SCR_ID_EMAIL_WIZARD_TEMPLATE_RECOGNIZE, 
            (FuncPtr)mmi_email_wizard_entry_recognize_screen, 
            p_account_list_cntx);
        memcpy(p_account_list_cntx->input_template.email_addr, p_email_addr, (SRV_EMAIL_MAX_ADDR_LEN + 1) * sizeof(WCHAR));
        mmi_wcsncpy(
            p_account_list_cntx->input_template.in_auth.username, 
            (const WCHAR*)p_email_addr, 
            user_name_length);
        mmi_wcsncpy(
            p_account_list_cntx->input_template.in_auth.password, 
            (const WCHAR*)p_password, 
            SRV_EMAIL_MAX_PASSWORD_LEN);
        cui_inline_close(p_event->sender_id);
        goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END;
    }
#else /* __OP12__ */
    highlight_template_index = p_account_list_cntx->highlight_template_index;
#endif /* __OP12__ */

    /* edit account info begin */   // read account template info
    p_acct_temp_struct = OslMalloc(sizeof(mmi_email_acct_temp_struct));
    app_core_result = mmi_email_acct_temp_get_acct(highlight_template_index, p_acct_temp_struct);
    if (MMI_EMAIL_SUCCESS != app_core_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_SUBMIT_LOG2, app_core_result);
        mmi_email_display_app_core_popup(p_account_list_cntx->new_account_template_group_id, app_core_result);
        cui_inline_close(p_event->sender_id);
        if (MMI_TRUE == p_account_list_cntx->first_new_account)
        {
            mmi_email_acct_setting_evt_struct setting_event;
            MMI_FRM_INIT_GROUP_EVENT(&setting_event, EVT_ID_ACCT_SETTING_EXIT, p_account_list_cntx->new_account_template_group_id);
            mmi_frm_group_send_to_parent(GRP_ID_EMAIL_ACCOUNT_WIZARD, (mmi_group_event_struct*)&setting_event);
            p_account_list_cntx->first_new_account = MMI_FALSE;
        }
        goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END;
    }
    // initialize the common account info
    srv_op_result = srv_email_acct_init_acct_info(&(p_account_list_cntx->current_account));
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_SUBMIT_LOG3, srv_op_result);
        mmi_email_util_display_error_popup(p_account_list_cntx->new_account_template_group_id, srv_op_result);
        cui_inline_close(p_event->sender_id);
        if (MMI_TRUE == p_account_list_cntx->first_new_account)
        {
            mmi_email_acct_setting_evt_struct setting_event;
            MMI_FRM_INIT_GROUP_EVENT(&setting_event, EVT_ID_ACCT_SETTING_EXIT, p_account_list_cntx->new_account_template_group_id);
            mmi_frm_group_send_to_parent(GRP_ID_EMAIL_ACCOUNT_WIZARD, (mmi_group_event_struct*)&setting_event);
            p_account_list_cntx->first_new_account = MMI_FALSE;
        }
        goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END;
    }
    p_account_list_cntx->current_account.acct_type = SRV_EMAIL_ACCT_USER_CONFIGURED;
    p_account_list_cntx->current_account.protocol = p_acct_temp_struct->protocol;
    mmi_wcscpy(
        p_account_list_cntx->current_account.email_addr.email_addr, 
        (const WCHAR*)p_email_addr);
    memcpy(
        &(p_account_list_cntx->current_account.in_server), 
        &(p_acct_temp_struct->incoming_server),
        sizeof(mmi_email_acct_server_struct));
    memcpy(
        &(p_account_list_cntx->current_account.out_server), 
        &(p_acct_temp_struct->outgoing_server),
        sizeof(mmi_email_acct_server_struct));

    if (MMI_TRUE == p_acct_temp_struct->username_format)
    {
        mmi_wcsncpy(
            p_account_list_cntx->current_account.in_auth.username,
            (const WCHAR*)p_email_addr,
            SRV_EMAIL_MAX_USERNAME_LEN);
    }
    else
    {   // find {@} and only copy the string before it. If ont found?
        mmi_wcsncpy(
            p_account_list_cntx->current_account.in_auth.username, 
            (const WCHAR*)p_email_addr, 
            user_name_length);
    }
    mmi_wcsncpy(p_account_list_cntx->current_account.in_auth.password, (const WCHAR*)p_password, SRV_EMAIL_MAX_PASSWORD_LEN);
    p_account_list_cntx->current_account.in_auth.auth_type = SRV_EMAIL_AUTH_USER;

    if (MMI_TRUE == p_acct_temp_struct->outgoing_auth)
    {
        memcpy(
            &(p_account_list_cntx->current_account.out_auth),
            &(p_account_list_cntx->current_account.in_auth),
            sizeof(srv_email_auth_struct));
    }
    else
    {
        p_account_list_cntx->current_account.out_auth.auth_type = SRV_EMAIL_AUTH_NONE;
    }
    
    mmi_wcsncpy(p_account_list_cntx->current_account.acct_name, p_account_list_cntx->current_account.email_addr.email_addr,
        SRV_EMAIL_MAX_ACCT_NAME_LEN);
    mmi_email_wizard_get_default_acct_name(p_account_list_cntx);

    mmi_email_set_acct_attribute(&(p_account_list_cntx->current_account));
    /* edit account info end */
    
    /* save account info begin*/
    mmi_email_asyn_create_account_p->type = MMI_EMAIL_ASYNC_CREATE_ACCOUNT_TYPE_FROM_TEMPLATE;
    create_result = mmi_email_edit_account_create_new_account(
                        p_account_list_cntx->srv_handle, 
                        &(p_account_list_cntx->current_account), 
                        &error_info);
    if (MMI_EMAIL_OPERATE_RESULT_FAILED == create_result)
    {
        if (MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_SERVICE == error_info.error_type)
        {
            mmi_email_util_display_error_popup(
                p_account_list_cntx->new_account_template_group_id, 
                error_info.error_code.srv_error);
        }
        else
        {
            mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        }
        cui_inline_close(p_event->sender_id);
        if (MMI_TRUE == p_account_list_cntx->first_new_account)
        {
            mmi_email_acct_setting_evt_struct setting_event;
            MMI_FRM_INIT_GROUP_EVENT(&setting_event, EVT_ID_ACCT_SETTING_EXIT, p_account_list_cntx->new_account_template_group_id);
            mmi_frm_group_send_to_parent(GRP_ID_EMAIL_ACCOUNT_WIZARD, (mmi_group_event_struct*)&setting_event);
            p_account_list_cntx->first_new_account = MMI_FALSE;
        }
        goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END;
    }
    else if (MMI_EMAIL_OPERATE_RESULT_WOULD_BLOCK == create_result)
    {
        cui_inline_close(p_event->sender_id);
        goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END;
    }
    
    mmi_email_smgr_account_add(p_account_list_cntx->current_account.acct_id);

    cui_inline_close(p_event->sender_id);
    if (MMI_TRUE == p_account_list_cntx->first_new_account)
    {
        mmi_email_acct_setting_evt_struct setting_event;
        MMI_FRM_INIT_GROUP_EVENT(&setting_event, EVT_ID_ACCT_SETTING_EXIT, p_account_list_cntx->new_account_template_group_id);
        mmi_frm_group_send_to_parent(GRP_ID_EMAIL_ACCOUNT_WIZARD, (mmi_group_event_struct*)&setting_event);
        p_account_list_cntx->first_new_account = MMI_FALSE;
        email_mmi_account_data_set_default(p_account_list_cntx->current_account.acct_id);
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_SUBMIT_LOG10, p_account_list_cntx->srv_handle, account_handle, p_account_list_cntx->current_account.acct_id);
    /* save account info end*/

MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_PROC_HANDLE_CUI_INLINE_SUBMIT_MESSAGE_END:
    if (NULL != p_email_addr)
    {
        OslMfree(p_email_addr);
        p_email_addr = NULL;
    }
    if (NULL != p_password)
    {
        OslMfree(p_password);
        p_password = NULL;
    }
    if (NULL != p_acct_temp_struct)
    {
        OslMfree(p_acct_temp_struct);
        p_acct_temp_struct = NULL;
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_proc_handle_cui_inline_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_template_list_proc_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_screen
* DESCRIPTION
*  Entry the template screen
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_wizard_entry_template_list_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_core_result_enum app_core_op_result = MMI_EMAIL_FAIL;
    mmi_email_acct_temp_struct *p_acct_temp_struct = NULL;
    S32 i = 0;
    U8 *item_string[MMI_EMAIL_ACCT_TEMP_MAX_NUMBER + 1];
    U8 *item_discription[MMI_EMAIL_ACCT_TEMP_MAX_NUMBER + 1];
    U8 *guiBuffer = NULL;
    mmi_email_account_list_cntx_struct * p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_SCREEN, __LINE__);
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id, 
                        p_screen_data->scrn_id, 
                        NULL, 
                        (FuncPtr)mmi_email_wizard_entry_template_list_screen, 
                        MMI_FRM_FULL_SCRN))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_SCREEN, __LINE__);
        p_account_list_cntx = p_screen_data->user_data;
        
        mmi_frm_scrn_set_user_data(
            p_screen_data->group_id, 
            p_screen_data->scrn_id, 
            p_account_list_cntx);
        
        mmi_frm_scrn_set_leave_proc(
            p_screen_data->group_id, 
            p_screen_data->scrn_id, 
            mmi_email_wizard_entry_template_list_screen_leave_proc);

        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        p_acct_temp_struct = OslMalloc(sizeof(mmi_email_acct_temp_struct));
        if (NULL == guiBuffer)
        {   // check whether it's the first time of screen entry
            p_account_list_cntx->p_account_temp_display_info = OslMalloc(sizeof(mmi_email_account_template_display_struct) * MMI_EMAIL_ACCT_TEMP_MAX_NUMBER);
        }
        
        for (i = 0; i < p_account_list_cntx->template_num; i++)
        {
            app_core_op_result = mmi_email_acct_temp_get_acct(i, p_acct_temp_struct);
            if (MMI_EMAIL_SUCCESS != app_core_op_result)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_SCREEN, i, app_core_op_result);
                goto MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_PROCESS_END;
            }
            mmi_wcscpy(
                p_account_list_cntx->p_account_temp_display_info[i].acct_name, 
                (const WCHAR*)p_acct_temp_struct->acct_name);
            p_account_list_cntx->p_account_temp_display_info[i].protocol = p_acct_temp_struct->protocol;
            
            item_string[i] = (U8*)p_account_list_cntx->p_account_temp_display_info[i].acct_name;
            if (SRV_EMAIL_PROT_POP3 == p_account_list_cntx->p_account_temp_display_info[i].protocol)
            {
                item_discription[i] = (U8*)GetString(STR_EMAIL_POP3_ID);
            }
            else
            {
                item_discription[i] = (U8*)GetString(STR_EMAIL_IMAP4_ID);
            }
        }
        item_string[i] = (U8*)GetString(STR_EMAIL_OTHER_EMAIL_ACCT_ID);
        item_discription[i] = NULL;

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ShowCategory53Screen(
            STR_EMAIL_SETUP_WIZARD_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            STR_GLOBAL_SELECT,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK, 
            (i + 1), 
            item_string, 
            (U16*)gIndexIconsImageList, 
            item_discription, 
            0,
            p_account_list_cntx->highlight_template_index,
            guiBuffer);

        RegisterHighlightHandler(mmi_email_wizard_entry_template_list_highlight_handler);
        SetLeftSoftkeyFunction(mmi_email_wizard_entry_template_list_lsk, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_email_wizard_entry_template_list_lsk, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_email_wizard_entry_template_list_rsk, KEY_EVENT_UP);
    MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_PROCESS_END:
        if (NULL != p_acct_temp_struct)
        {
            OslMfree(p_acct_temp_struct);
            p_acct_temp_struct = NULL;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_screen_leave_proc
* DESCRIPTION
*  
* PARAMETERS
*  p_event 
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_wizard_entry_template_list_screen_leave_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_SCREEN_LEAVE_PROC, __LINE__);

    p_account_list_cntx = p_event->user_data;
    switch (p_event->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            if (NULL != p_account_list_cntx->p_account_temp_display_info)
            {
                OslMfree(p_account_list_cntx->p_account_temp_display_info);
                p_account_list_cntx->p_account_temp_display_info = NULL;
            }
            break;
        }
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_highlight_handler
* DESCRIPTION
*  The highlight handler template screen lsk
* PARAMETERS
*  item_index 
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_template_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_HIGHLIGHT_HANDLER, item_index);
    mmi_email_account_list_p->highlight_template_index = item_index;
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_lsk
* DESCRIPTION
*  Entry the template screen lsk
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_template_list_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_LSK, mmi_email_account_list_p->highlight_template_index, mmi_email_account_list_p->template_num);
#ifndef __OP12__
    if (mmi_email_account_list_p->highlight_template_index == mmi_email_account_list_p->template_num)
    {   // normal account creation
        mmi_email_entry_new_account_process(mmi_email_account_list_p);
    }
    else
#endif /* __OP12__ */
    {
        mmi_email_wizard_entry_edit_template_process(mmi_email_account_list_p);
    }
    mmi_frm_scrn_close(mmi_email_account_list_p->new_account_template_group_id, SCR_ID_EMAIL_WIZARD_TEMPLATE_SELECT);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_template_list_rsk
* DESCRIPTION
*  Entry the template screen lsk
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_template_list_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_TEMPLATE_LIST_RSK, __LINE__);
    mmi_frm_scrn_close_active_id();
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_edit_template_process
* DESCRIPTION
*  Edit the template screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_edit_template_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_wizard_entry_edit_template_screen(p_account_list_cntx);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_edit_template_screen
* DESCRIPTION
*  Edit the template screen
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
static void mmi_email_wizard_entry_edit_template_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};
    cui_inline_set_item_struct inline_item[MMI_EMAIL_TEMPLATE_EDIT_ITEMS_NUMBER];
    cui_inline_struct inline_struct;
    cui_inline_item_caption_struct caption_struct[MMI_EMAIL_TEMPLATE_EDIT_CAPTION_ITEMS_NUMBER];
    cui_inline_item_text_edit_struct text_edit_struct[MMI_EMAIL_TEMPLATE_EDIT_TEXT_ITEMS_NUMBER];
        
    S32 inline_item_index = 0;
    S32 caption_index = 0;
    S32 text_edit_index = 0;
    
    U16 email_icon = 0;
    mmi_id inline_id = GRP_ID_INVALID;

    mmi_email_acct_temp_struct *p_acct_temp_struct = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_EDIT_TEMPLATE_SCREEN, __LINE__);

    p_acct_temp_struct = OslMalloc(sizeof(mmi_email_acct_temp_struct));

    if (MMI_EMAIL_SUCCESS != mmi_email_acct_temp_get_acct(
                                p_account_list_cntx->highlight_template_index, 
                                p_acct_temp_struct))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ENTRY_EDIT_TEMPLATE_SCREEN_LOG1, p_account_list_cntx->highlight_template_index);
        mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        goto MMI_EMAIL_WIZARD_ENTRY_EDIT_TEMPLATE_SCREEN_END;
    }

    email_icon = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
    
    /* email address part begin*/
    caption_struct[caption_index].string_id = STR_EMAIL_EMAIL_ADDRESS_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_TEMPLATE_EDIT_EMAIL_ADDRESS_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_EMAIL_ADDRESS_ID, 
        &caption_struct[caption_index++]);
    
    mmi_email_account_init_text_edit_struct(
        &text_edit_struct[text_edit_index], 
        0, 
        0, 
        (SRV_EMAIL_MAX_ADDR_LEN + 1), 
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | IMM_INPUT_TYPE_EMAIL, 
        0, 
        NULL);
    
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_TEMPLATE_EDIT_EMAIL_ADDRESS_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_TEXTEDIT_FIRST_CURSOR, 
        0, 
        &text_edit_struct[text_edit_index++]);
    /* email address part end*/

    /* passsword part begin*/
    caption_struct[caption_index].string_id = STR_GLOBAL_PASSWORD;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_TEMPLATE_EDIT_USER_PASSWORD_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_PASSWORD_ID, 
        &caption_struct[caption_index++]);
    
    mmi_email_account_init_text_edit_struct(
        &text_edit_struct[text_edit_index], 
        0, 
        0, 
        (SRV_EMAIL_MAX_PASSWORD_LEN + 1), 
        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, //INPUT_TYPE_USE_ENCODING_BASED_LENGTH
        0, 
        NULL);
    
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_TEMPLATE_EDIT_USER_PASSWORD_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 
        0, 
        &text_edit_struct[text_edit_index++]);
    /* passsword part end*/

    inline_struct.items_count = MMI_EMAIL_TEMPLATE_EDIT_ITEMS_NUMBER;
    inline_struct.title = STR_EMAIL_SETUP_WIZARD_ID;
    inline_struct.title_icon = email_icon;
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(p_account_list_cntx->new_account_template_group_id, &inline_struct);
    p_account_list_cntx->current_inline_id = inline_id;

    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_TEMPLATE_EDIT_EMAIL_ADDRESS_CONTENT_ID, 
        p_acct_temp_struct->addr);
    
    // move this line below {cui_inline_set_value}, it's a bug
    cui_inline_run(inline_id);
    // proc function {mmi_email_wizard_entry_template_list_proc_handle_cui_inline_submit_message}
    
MMI_EMAIL_WIZARD_ENTRY_EDIT_TEMPLATE_SCREEN_END:
    if (NULL != p_acct_temp_struct)
    {
        OslMfree(p_acct_temp_struct);
        p_acct_temp_struct = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_email_addr_process
* DESCRIPTION
*  Entry the email address editor
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_email_addr_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fseditor_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_EMAIL_ADDR;
    p_account_list_cntx->select_email_addr_from_phb.select_from_phb = MMI_FALSE;

    fseditor_id = cui_fseditor_create(p_account_list_cntx->new_account_group_id);
    cui_fseditor_set_title(fseditor_id, STR_EMAIL_EMAIL_ADDRESS_ID, GetRootTitleIcon(MENU_ID_EMAIL_MAIN));
    cui_fseditor_set_text(
        fseditor_id, 
        (WCHAR*)(p_account_list_cntx->current_account.email_addr.email_addr), 
        sizeof(p_account_list_cntx->current_account.email_addr.email_addr), 
        SRV_EMAIL_MAX_ADDR_LEN);
    cui_fseditor_set_input_method(
        fseditor_id, 
        IMM_INPUT_TYPE_EMAIL, 
        NULL, 
        0);
    cui_fseditor_set_title_in_header(fseditor_id, MMI_TRUE);
    cui_fseditor_run(fseditor_id);

    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_email_addr_search_handler
* DESCRIPTION
*  when add a new account, handle adding email address search
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_email_addr_search_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id phb_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx->current_fseditor_id = fseditor_id;
    phb_id = cui_phb_list_select_contact_create(p_account_list_cntx->new_account_group_id);
    cui_phb_list_select_contact_set_field_filter(phb_id, SRV_PHB_ENTRY_FIELD_EMAIL);
    cui_phb_list_select_contact_run(phb_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_email_addr_next_handler
* DESCRIPTION
*  when add a new account, handle adding email address next
* PARAMETERS
*  fseditor_id          [IN] The fseditor's id
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_email_addr_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_info_struct *p_current_account = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_EMAIL_ADDR_NEXT_HANDLER, __LINE__);

    p_current_account = &(p_account_list_cntx->current_account);
    cui_fseditor_get_text(fseditor_id, p_current_account->email_addr.email_addr, sizeof(p_current_account->email_addr.email_addr));
    
    if (!mmi_email_util_chk_addr((p_current_account->email_addr.email_addr)))
    {
        mmi_email_lib_error_popup(STR_GLOBAL_INVALID_EMAIL_ADDRESS);
    }
    else
    {
        if (MMI_TRUE == p_account_list_cntx->select_email_addr_from_phb.select_from_phb)
        {
            if (0 == mmi_wcscmp(
                        p_account_list_cntx->current_account.email_addr.email_addr, 
                        p_account_list_cntx->select_email_addr_from_phb.email_addr.email_addr))
            {
                mmi_wcscpy(
                    p_account_list_cntx->current_account.email_addr.disp_name, 
                    p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_name);
                p_account_list_cntx->current_account.email_addr.disp_charset = 
                    p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_charset;
                p_account_list_cntx->current_account.email_addr.disp_name_len = 
                    p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_name_len;
            }
            else
            {
                p_account_list_cntx->current_account.email_addr.disp_name[0] = 0;
                p_account_list_cntx->current_account.email_addr.disp_charset = MMI_CHSET_BASE;
                p_account_list_cntx->current_account.email_addr.disp_name_len = 0;
            }
        }
        mmi_email_wizard_entry_protocol_process(p_account_list_cntx);
        cui_fseditor_close(fseditor_id);
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_protocol_process
* DESCRIPTION
*  Entry the select protocol process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_protocol_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_PROTOCOL_PROCESS, __LINE__);

    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_PROTOCOL;
    p_account_list_cntx->new_account_protocol_group_id = mmi_frm_group_create(
                                                            p_account_list_cntx->new_account_group_id, 
                                                            GRP_ID_AUTO_GEN, 
                                                            mmi_email_wizard_entry_protocol_proc, 
                                                            p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->new_account_protocol_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_email_wizard_entry_protocol_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_protocol_proc
* DESCRIPTION
*  The procedure function of protocol group
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_wizard_entry_protocol_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_PROTOCOL_PROC, __LINE__);
    switch (p_event->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_email_wizard_entry_protocol_proc_handle_cui_menu_list_entry_message((cui_menu_event_struct*)p_event);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        {
            mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_select_message((cui_menu_event_struct*)p_event);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_close_message((cui_menu_event_struct*)p_event);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_select_message((cui_menu_event_struct*)p_event);
            break;
        }
        case EVT_ID_GROUP_FOCUSED:
        {
            mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->new_account_protocol_group_id);
            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_protocol_proc_handle_cui_menu_list_entry_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_LIST_ENTRY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_LIST_ENTRY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_protocol_proc_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_PROTOCOL_PROC_HANDLE_CUI_MENU_LIST_ENTRY_MESSAGE, __LINE__);
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    switch (p_event->parent_menu_id)
    {
        case MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_NEXT:
        {
            mmi_menu_id protocol_menu_id_array[] = {MENU_ID_EMAIL_WIZARD_PROTOCOL_POP3, MENU_ID_EMAIL_WIZARD_PROTOCOL_IMAP};
            U16 protocol_menu_id_string_array[] = {STR_EMAIL_POP3_ID, STR_EMAIL_IMAP4_ID};
            mmi_email_menu_screen_struct menu_screen;
            mmi_menu_id highlight_menu_id = MENU_ID_EMAIL_WIZARD_PROTOCOL_POP3;

            if (SRV_EMAIL_PROT_IMAP4 == p_account_list_cntx->current_account.protocol)
            {
                highlight_menu_id = MENU_ID_EMAIL_WIZARD_PROTOCOL_IMAP;
            }

            menu_screen.title_string_id = STR_EMAIL_PROTOCOL_ID;
            menu_screen.title_icon_id = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
            menu_screen.menu_item_number = sizeof(protocol_menu_id_array) / sizeof(mmi_menu_id);
            menu_screen.menu_id_array = protocol_menu_id_array;
            menu_screen.menu_id_string_array = protocol_menu_id_string_array;
            menu_screen.menu_id_image_array = (U16*)gIndexIconsImageList;
            
            mmi_email_account_set_menu_screen(p_event->sender_id, &menu_screen, STR_GLOBAL_SELECT);
            cui_menu_set_currlist_flags(p_event->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            cui_menu_set_radio_list_item(p_event->sender_id, highlight_menu_id);
            cui_menu_set_currlist_left_softkey(p_event->sender_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));
            cui_menu_enable_center_softkey(p_event->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
            cui_menu_enable_tap_to_highlight(p_event->sender_id);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_PROTOCOL_POP3:
        case MENU_ID_EMAIL_WIZARD_PROTOCOL_IMAP:
        {
            mmi_menu_id protocol_option_menu_id_array[] = {MENU_ID_EMAIL_WIZARD_PROTOCOL_NEXT, MENU_ID_EMAIL_WIZARD_PROTOCOL_CANCEL};
            U16 protocol_option_menu_id_string_array[] = {STR_EMAIL_NEXT_ID, STR_GLOBAL_CANCEL};
            mmi_email_menu_screen_struct menu_screen;

            menu_screen.title_string_id = STR_GLOBAL_OPTIONS;
            menu_screen.title_icon_id = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
            menu_screen.menu_item_number = sizeof(protocol_option_menu_id_array) / sizeof(mmi_menu_id);
            menu_screen.menu_id_array = protocol_option_menu_id_array;
            menu_screen.menu_id_string_array = protocol_option_menu_id_string_array;
            menu_screen.menu_id_image_array = (U16*)gIndexIconsImageList;

            mmi_email_account_set_menu_screen(p_event->sender_id, &menu_screen, STR_GLOBAL_SELECT);
            break;
        }

        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_select_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_ITEM_SELECT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_ITEM_SELECT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_select_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get the account list context */
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_PROTOCOL_PROC_HANDLE_CUI_MENU_ITEM_SELECT_MESSAGE, __LINE__);
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    switch (p_event->highlighted_menu_id)
    {
        case MENU_ID_EMAIL_WIZARD_PROTOCOL_POP3:
        case MENU_ID_EMAIL_WIZARD_PROTOCOL_IMAP:
        {
            mmi_id protocol_option_id = GRP_ID_INVALID;

            if (MENU_ID_EMAIL_WIZARD_PROTOCOL_POP3 == p_event->highlighted_menu_id)
            {
                p_account_list_cntx->current_account.protocol = SRV_EMAIL_PROT_POP3;
            }
            else
            {
                p_account_list_cntx->current_account.protocol = SRV_EMAIL_PROT_IMAP4;
            }
            if (EVT_ID_CUI_MENU_ITEM_CSK_SELECT == p_event->evt_id)
            {
                mmi_email_wizard_entry_data_account_process(p_account_list_cntx);
                mmi_frm_group_close(p_account_list_cntx->new_account_protocol_group_id);
            }
            else
            {
                protocol_option_id = cui_menu_create(
                                        p_account_list_cntx->new_account_protocol_group_id, 
                                        CUI_MENU_SRC_TYPE_APPCREATE, 
                                        CUI_MENU_TYPE_OPTION, 
                                        p_event->highlighted_menu_id, 
                                        MMI_FALSE,
                                        NULL);
                cui_menu_run(protocol_option_id);
            }
            break;
        }
        case MENU_ID_EMAIL_WIZARD_PROTOCOL_NEXT:
        {
            mmi_email_wizard_entry_data_account_process(p_account_list_cntx);
            mmi_frm_group_close(p_account_list_cntx->new_account_protocol_group_id);
            break;
        }
        case MENU_ID_EMAIL_WIZARD_PROTOCOL_CANCEL:
        {
            mmi_email_wizard_entry_cancel_process(p_account_list_cntx);
            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_close_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_CLOSE_REQUEST
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_CLOSE_REQUEST event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_protocol_proc_handle_cui_menu_item_close_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* use the app_data to distiguish whether close protocol option screen or protocol main screen */
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_PROTOCOL_PROC_HANDLE_CUI_MENU_ITEM_CLOSE_MESSAGE, __LINE__);
    if (NULL != p_event->app_data)
    {
        mmi_email_wizard_entry_email_addr_process(p_event->user_data);
    }
    
    cui_menu_close(p_event->sender_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_protocol_screen
* DESCRIPTION
*  Entry the select protocol screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  mmi_ret
*****************************************************************************/
static void mmi_email_wizard_entry_protocol_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id protocol_screen_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_PROTOCOL_SCREEN, __LINE__);
    protocol_screen_id = cui_menu_create(
                            p_account_list_cntx->new_account_protocol_group_id, 
                            CUI_MENU_SRC_TYPE_APPCREATE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_EMAIL_WIZARD_EMAIL_ADDR_NEXT, 
                            MMI_FALSE,
                            p_account_list_cntx);
    cui_menu_run(protocol_screen_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_process
* DESCRIPTION
*  Entry the select data account process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_DATA_ACCOUNT_PROCESS, __LINE__);

    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_DATA_ACCOUNT;

    p_account_list_cntx->new_account_data_account_group_id = mmi_frm_group_create(
                                                                p_account_list_cntx->new_account_group_id, 
                                                                GRP_ID_AUTO_GEN, 
                                                                mmi_email_wizard_entry_data_account_proc, 
                                                                p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->new_account_data_account_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
            p_account_list_cntx->new_account_data_account_group_id, 
            SCR_ID_EMAIL_WIZARD_DATA_ACCT, 
            (FuncPtr)mmi_email_wizard_entry_data_account_screen, 
            p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_proc
* DESCRIPTION
*  The procedure function of data account group
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_wizard_entry_data_account_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_DATA_ACCOUNT_PROC, __LINE__);
    switch (p_event->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_email_wizard_entry_data_account_proc_handle_cui_menu_list_entry_message((cui_menu_event_struct*)p_event);
            break;

        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_email_wizard_entry_data_account_proc_handle_cui_menu_item_select_message((cui_menu_event_struct*)p_event);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_email_wizard_entry_data_account_proc_handle_cui_menu_item_close_message((cui_menu_event_struct*)p_event);
            break;

        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
            mmi_email_data_account_cui_dtcnt_select_ok_message((cui_dtcnt_select_event_any_sim_selected_struct*)p_event);
            break;

        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
            mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_done_message((cui_dtcnt_select_event_struct*)p_event);
            break;

        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
            mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_cancel_message((cui_dtcnt_select_event_struct*)p_event);
            break;

        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
            break;

        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_close_message((cui_dtcnt_select_event_struct*)p_event);
            break;

        case EVT_ID_GROUP_FOCUSED:
            mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->new_account_data_account_group_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_proc_handle_cui_menu_list_entry_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_LIST_ENTRY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_LIST_ENTRY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_proc_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->parent_menu_id)
    {
        case MENU_ID_EMAIL_WIZARD_DATA_ACCT_OPT:
        {
            mmi_menu_id data_account_option_menu_id_array[] = {MENU_ID_EMAIL_WIZARD_DATA_ACCT_NEXT, MENU_ID_EMAIL_WIZARD_DATA_ACCT_EDIT, MENU_ID_EMAIL_WIZARD_DATA_ACCT_CANCEL};
            U16 data_account_option_menu_id_string_array[] = {STR_EMAIL_NEXT_ID, STR_EMAIL_CHANGE_DATA_ACCT/*STR_GLOBAL_SELECT*/, STR_GLOBAL_CANCEL};
            mmi_email_menu_screen_struct menu_screen;

            menu_screen.title_string_id = STR_GLOBAL_OPTIONS;
            menu_screen.title_icon_id = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
            menu_screen.menu_item_number = sizeof(data_account_option_menu_id_array) / sizeof(mmi_menu_id);
            menu_screen.menu_id_array = data_account_option_menu_id_array;
            menu_screen.menu_id_string_array = data_account_option_menu_id_string_array;
            menu_screen.menu_id_image_array = (U16*)gIndexIconsImageList;
            
            mmi_email_account_set_menu_screen(p_event->sender_id, &menu_screen, STR_GLOBAL_SELECT);
            break;
        }

        default:
            break;
    }
}


static void mmi_email_account_copy_dtcnt_id(U32 dst[], U32 src[])
{
    U32 i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        dst[i] = src[i];
    }
}


static mmi_id mmi_email_account_enter_dtcnt_cui(mmi_id grp_id, U32 dtcnt_id[])
{
    mmi_id data_account_id;
    cui_dtcnt_select_run_struct data_account_params;

    if (!srv_sim_ctrl_any_sim_is_available())
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            0);
        return 0;
    }

    data_account_params.bearers = DATA_ACCOUNT_BEARER_ALL;
    data_account_params.app_id = mmi_email_dtcnt_get_temp_appid();
    data_account_params.AppMenuID = 0;
    data_account_params.icon_id = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
    data_account_params.str_id = STR_GLOBAL_DATA_ACCOUNT;
    mmi_email_account_copy_dtcnt_id(data_account_params.sim_account_id, dtcnt_id);
    data_account_params.option = CUI_DTCNT_SELECT_DEFAULT;
    data_account_params.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    data_account_params.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;

    data_account_id = cui_dtcnt_select_create(grp_id);
    cui_dtcnt_select_set_param(data_account_id, &data_account_params);
    cui_dtcnt_select_run(data_account_id);

    return data_account_id;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_proc_handle_cui_menu_item_select_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_ITEM_SELECT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_ITEM_SELECT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_proc_handle_cui_menu_item_select_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->app_data);

    switch (p_event->highlighted_menu_id)
    {
        case MENU_ID_EMAIL_WIZARD_DATA_ACCT_NEXT:
            mmi_email_util_get_default_server(
                p_account_list_cntx->current_account.email_addr.email_addr, 
                p_account_list_cntx->current_account.in_server.server_name);
            mmi_email_wizard_entry_incoming_server_process(p_account_list_cntx);
            mmi_frm_group_close(p_account_list_cntx->new_account_data_account_group_id);
            break;

        case MENU_ID_EMAIL_WIZARD_DATA_ACCT_EDIT:
            mmi_email_account_enter_dtcnt_cui(
                p_account_list_cntx->new_account_data_account_group_id,
                p_account_list_cntx->current_account.in_server.data_acct);
            break;

        case MENU_ID_EMAIL_WIZARD_DATA_ACCT_CANCEL:
            mmi_email_wizard_entry_cancel_process(p_account_list_cntx);
            break;

        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_proc_handle_cui_menu_item_close_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_CLOSE_REQUEST
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_CLOSE_REQUEST event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_proc_handle_cui_menu_item_close_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(p_event->sender_id);
}


static void mmi_email_data_account_cui_dtcnt_select_ok_message(cui_dtcnt_select_event_any_sim_selected_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(evt->user_data);

    switch(evt->selectSim)
    {
    case CUI_DTCNT_SIM1:
        i = 0;
        break;

#if (MMI_MAX_SIM_NUM >= 2)
    case CUI_DTCNT_SIM2:
        i = 1;
        break;
#endif /* (MMI_MAX_SIM_NUM>=2) */

#if (MMI_MAX_SIM_NUM >= 3)
    case CUI_DTCNT_SIM3:
        i = 2;
        break;
#endif /* (MMI_MAX_SIM_NUM>=2) */

#if (MMI_MAX_SIM_NUM >= 4)
    case CUI_DTCNT_SIM4:
        i = 3;
        break;
#endif /* (MMI_MAX_SIM_NUM>=2) */

    default:
        return;
    }

    ASSERT(i < MMI_SIM_TOTAL);
    /* select data account in account setting */
    if (MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_ACCOUNT_SETTING == p_account_list_cntx->state)
    {
        p_account_list_cntx->edit_dataacct_id[i] = evt->accountId;
    }
    else
    {
        p_account_list_cntx->current_account.in_server.data_acct[i] = evt->accountId;
        p_account_list_cntx->current_account.out_server.data_acct[i] = evt->accountId;
    }
    p_account_list_cntx->dtcnt_changed = MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_done_message
* DESCRIPTION
*  The handle function of CUI_DTCNT_SELECT_EVENT_RESULT_OK
* PARAMETERS
*  p_event   [IN] CUI_DTCNT_SELECT_EVENT_RESULT_OK event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_done_message(cui_dtcnt_select_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    U8 highlight_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    if (MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_ACCOUNT_SETTING == p_account_list_cntx->state
        && p_account_list_cntx->dtcnt_changed)
    {
        MMI_BOOL conflict_dtcnt = MMI_FALSE;

        conflict_dtcnt = mmi_email_dtcnt_is_any_conflict(p_account_list_cntx->edit_dataacct_id);

        mmi_email_dtcnt_get_showname(
            p_account_list_cntx->data_account_name, 
            p_account_list_cntx->edit_dataacct_id);

        cui_inline_set_value(
            p_account_list_cntx->account_setting_id, 
            MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CONTENT_ID, 
            p_account_list_cntx->data_account_name);

        cui_inline_set_screen_attributes(
            p_account_list_cntx->account_setting_id, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_SCREEN_CHANGED);


        if (MMI_TRUE == conflict_dtcnt)
        {
        #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
            cui_inline_get_value(
                p_account_list_cntx->account_setting_id, 
                MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
                &highlight_index);
            if (0 != highlight_index)
            {
                mmi_email_lib_infor_popup(STR_EMAIL_CHK_RESET_ID);
                highlight_index = 0;
                cui_inline_set_value(
                    p_account_list_cntx->account_setting_id, 
                    MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
                    (void*)&highlight_index);
            }
            cui_inline_set_item_attributes(
                p_account_list_cntx->account_setting_id, 
                MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_ITEM_DISABLE);
        #endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

        #ifdef __MMI_EMAIL_EMN__
            cui_inline_get_value(
                p_account_list_cntx->account_setting_id, 
                MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
                &highlight_index);
            if (0 != highlight_index)
            {
                mmi_email_lib_infor_popup(STR_EMAIL_EMN_RESET_ID);
                highlight_index = 0;
                cui_inline_set_value(
                    p_account_list_cntx->account_setting_id, 
                    MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
                    (void*)&highlight_index);
            }
            cui_inline_set_item_attributes(
                p_account_list_cntx->account_setting_id, 
                MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_ITEM_DISABLE);
        #endif /* __MMI_EMAIL_EMN__ */
        }
        else
        {
        #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
            cui_inline_get_value(
                p_account_list_cntx->account_setting_id, 
                MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
                &highlight_index);
        #else /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
            highlight_index = 0;
        #endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

        #ifdef __MMI_EMAIL_EMN__
            if (0 == highlight_index)
            {
                cui_inline_set_item_attributes(
                    p_account_list_cntx->account_setting_id, 
                    MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
                    CUI_INLINE_RESET_ATTRIBUTE, 
                    CUI_INLINE_ITEM_DISABLE);
            }
            else
            {
                cui_inline_set_item_attributes(
                    p_account_list_cntx->account_setting_id, 
                    MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_ITEM_DISABLE);
            }
        #endif /* __MMI_EMAIL_EMN__ */

        #ifdef __MMI_EMAIL_EMN__
            cui_inline_get_value(
                p_account_list_cntx->account_setting_id, 
                MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
                &highlight_index);
        #else /* __MMI_EMAIL_EMN__ */
            highlight_index = 0;
        #endif /* __MMI_EMAIL_EMN__ */ 

        #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
            if (0 == highlight_index)
            {
                cui_inline_set_item_attributes(
                    p_account_list_cntx->account_setting_id, 
                    MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
                    CUI_INLINE_RESET_ATTRIBUTE, 
                    CUI_INLINE_ITEM_DISABLE);
            }
            else
            {
                cui_inline_set_item_attributes(
                    p_account_list_cntx->account_setting_id, 
                    MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
                    CUI_INLINE_SET_ATTRIBUTE, 
                    CUI_INLINE_ITEM_DISABLE);                
            }
        #endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
        }
    }

    cui_dtcnt_select_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_cancel_message
* DESCRIPTION
*  The handle function of CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL
* PARAMETERS
*  p_event   [IN] CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_cancel_message(cui_dtcnt_select_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_close_message
* DESCRIPTION
*  The handle function of CUI_DTCNT_SELECT_EVENT_CLOSE
* PARAMETERS
*  p_event   [IN] CUI_DTCNT_SELECT_EVENT_CLOSE event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_close_message(cui_dtcnt_select_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_screen
* DESCRIPTION
*  Entry the select data account screen
* PARAMETERS
*  p_screen_data  [IN] The screen data
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_wizard_entry_data_account_screen(mmi_scrn_essential_struct *p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_DATA_ACCOUNT_SCREEN, __LINE__);
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id, 
                        p_screen_data->scrn_id, 
                        NULL, 
                        (FuncPtr)mmi_email_wizard_entry_data_account_screen, 
                        MMI_FRM_FULL_SCRN))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_ENTRY_DATA_ACCOUNT_SCREEN, __LINE__);
        p_account_list_cntx = p_screen_data->user_data;

        mmi_email_dtcnt_get_showname(
            p_account_list_cntx->data_account_name, 
            p_account_list_cntx->edit_dataacct_id);

        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        ShowCategory74Screen(
            STR_GLOBAL_DATA_ACCOUNT,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*)p_account_list_cntx->data_account_name,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_email_wizard_entry_data_account_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_email_wizard_entry_data_account_previous_process, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_email_wizard_entry_data_account_csk_handler, KEY_EVENT_UP);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_option
* DESCRIPTION
*  Entry the options of select data account screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id data_account_option_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_account_option_id = cui_menu_create(
                                mmi_email_account_list_p->new_account_data_account_group_id, 
                                CUI_MENU_SRC_TYPE_APPCREATE, 
                                CUI_MENU_TYPE_OPTION, 
                                MENU_ID_EMAIL_WIZARD_DATA_ACCT_OPT, 
                                MMI_FALSE, 
                                mmi_email_account_list_p);
    cui_menu_run(data_account_option_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_data_account_previous_process
* DESCRIPTION
*  Entry the previous process of select data account screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_data_account_previous_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_wizard_entry_protocol_process(mmi_email_account_list_p);
	mmi_frm_group_close(mmi_email_account_list_p->new_account_data_account_group_id);
}

static void mmi_email_wizard_entry_data_account_csk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_get_default_server(
        mmi_email_account_list_p->current_account.email_addr.email_addr, 
        mmi_email_account_list_p->current_account.in_server.server_name);
    mmi_email_wizard_entry_incoming_server_process(mmi_email_account_list_p);
    mmi_frm_group_close(mmi_email_account_list_p->new_account_data_account_group_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_incoming_server_process
* DESCRIPTION
*  Entry the incoming server process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_incoming_server_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_INCOMING_SERVER;
    mmi_email_wizard_entry_incoming_server_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_incoming_server_screen
* DESCRIPTION
*  Entry the incoming server screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_incoming_server_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fseditor_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    fseditor_id = cui_fseditor_create(p_account_list_cntx->new_account_group_id);
    cui_fseditor_set_title(fseditor_id, STR_EMAIL_INCOMING_SERVER_ID, GetRootTitleIcon(MENU_ID_EMAIL_MAIN));
    cui_fseditor_set_text(
        fseditor_id, 
        (p_account_list_cntx->current_account.in_server.server_name), 
        sizeof(p_account_list_cntx->current_account.in_server.server_name), 
        SRV_EMAIL_MAX_SERVER_NAME_LEN);
	cui_fseditor_set_cursor_first_pos(fseditor_id, MMI_TRUE);
    cui_fseditor_set_input_method(
        fseditor_id, 
        IMM_INPUT_TYPE_EMAIL, 
        NULL, 
        0);
    cui_fseditor_set_title_in_header(fseditor_id, MMI_TRUE);
    cui_fseditor_run(fseditor_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_incoming_server_next_handler
* DESCRIPTION
*  when add a new account, handle adding incoming server next
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_incoming_server_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_get_text(
        fseditor_id, 
        p_account_list_cntx->current_account.in_server.server_name, 
        sizeof(p_account_list_cntx->current_account.in_server.server_name));

    if (!mmi_email_util_is_server_vaild((CHAR*)(p_account_list_cntx->current_account.in_server.server_name)))
    {
        mmi_email_lib_error_popup(STR_EMAIL_ERROR_CODE_INVALID_IP_ADDR_ID);
    }
    else
    {        
        mmi_email_util_get_default_server(
            p_account_list_cntx->current_account.email_addr.email_addr, 
            p_account_list_cntx->current_account.out_server.server_name);

        mmi_email_wizard_entry_outgoing_server_process(p_account_list_cntx);
        cui_fseditor_close(fseditor_id);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_outgoing_server_process
* DESCRIPTION
*  Entry the outgoing server process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_outgoing_server_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_OUTGOING_SERVER;
    mmi_email_wizard_entry_outgoing_server_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_outgoing_server_screen
* DESCRIPTION
*  Entry the outgoing server screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_outgoing_server_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fseditor_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    fseditor_id = cui_fseditor_create(p_account_list_cntx->new_account_group_id);
    cui_fseditor_set_title(fseditor_id, STR_EMAIL_OUTGOING_SERVER_ID, GetRootTitleIcon(MENU_ID_EMAIL_MAIN));
    cui_fseditor_set_text(
        fseditor_id, 
        (p_account_list_cntx->current_account.out_server.server_name), 
        sizeof(p_account_list_cntx->current_account.out_server.server_name), 
        SRV_EMAIL_MAX_SERVER_NAME_LEN);
	cui_fseditor_set_cursor_first_pos(fseditor_id, MMI_TRUE);
    cui_fseditor_set_input_method(
        fseditor_id, 
        IMM_INPUT_TYPE_EMAIL, 
        NULL, 
        0);
    cui_fseditor_set_title_in_header(fseditor_id, MMI_TRUE);
    cui_fseditor_run(fseditor_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_outgoing_server_next_handler
* DESCRIPTION
*  when add a new account, handle adding outgoing server next
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_outgoing_server_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_get_text(
        fseditor_id, 
        p_account_list_cntx->current_account.out_server.server_name, 
        sizeof(p_account_list_cntx->current_account.out_server.server_name));

    if (!mmi_email_util_is_server_vaild((CHAR*)(p_account_list_cntx->current_account.out_server.server_name)))
    {
        mmi_email_lib_error_popup(STR_EMAIL_ERROR_CODE_INVALID_IP_ADDR_ID);
    }
    else
    {
        mmi_email_util_get_default_user_name(
            p_account_list_cntx->current_account.email_addr.email_addr, 
            p_account_list_cntx->current_account.in_auth.username);
        mmi_email_wizard_entry_user_name_process(p_account_list_cntx);
        cui_fseditor_close(fseditor_id);
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_user_name_process
* DESCRIPTION
*  Entry the user name process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_user_name_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_USER_NAME;
    mmi_email_wizard_entry_user_name_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_user_name_screen
* DESCRIPTION
*  Entry the user name screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_user_name_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fseditor_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    fseditor_id = cui_fseditor_create(p_account_list_cntx->new_account_group_id);
    cui_fseditor_set_title(fseditor_id, STR_GLOBAL_USERNAME, GetRootTitleIcon(MENU_ID_EMAIL_MAIN));
    cui_fseditor_set_text(
        fseditor_id, 
        (p_account_list_cntx->current_account.in_auth.username), 
        sizeof(p_account_list_cntx->current_account.in_auth.username), 
        SRV_EMAIL_MAX_USERNAME_LEN);
    cui_fseditor_set_input_method(
        fseditor_id, 
        IMM_INPUT_TYPE_ASCII_CHAR, 
        NULL, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    cui_fseditor_set_title_in_header(fseditor_id, MMI_TRUE);
    cui_fseditor_run(fseditor_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_user_name_next_handler
* DESCRIPTION
*  when add a new account, handle adding user name next
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_user_name_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_get_text(
        fseditor_id, 
        (p_account_list_cntx->current_account.in_auth.username), 
        sizeof(p_account_list_cntx->current_account.in_auth.username));

    if (!mmi_email_util_is_username_vaild((CHAR*)(p_account_list_cntx->current_account.in_auth.username)))
    {
        mmi_email_lib_error_popup(STR_EMAIL_WRONG_USERNAME);
    }
    else
    {
        mmi_email_wizard_entry_password_process(p_account_list_cntx);
        cui_fseditor_close(fseditor_id);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_password_process
* DESCRIPTION
*  Entry the password process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_password_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_PASSWORD;
    mmi_email_wizard_entry_password_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_password_screen
* DESCRIPTION
*  Entry the password screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_password_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fseditor_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fseditor_id = cui_fseditor_create(p_account_list_cntx->new_account_group_id);
    cui_fseditor_set_title(fseditor_id, STR_GLOBAL_PASSWORD, GetRootTitleIcon(MENU_ID_EMAIL_MAIN));
    cui_fseditor_set_text(
        fseditor_id, 
        (p_account_list_cntx->current_account.in_auth.password), 
        sizeof(p_account_list_cntx->current_account.in_auth.password), 
        SRV_EMAIL_MAX_PASSWORD_LEN);
    cui_fseditor_set_input_method(
        fseditor_id, 
        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 
        NULL, 
        0);
    cui_fseditor_set_title_in_header(fseditor_id, MMI_TRUE);
    cui_fseditor_run(fseditor_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_password_next_handler
* DESCRIPTION
*  when add a new account, handle adding password next
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_password_next_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_get_text(
        fseditor_id, 
        (p_account_list_cntx->current_account.in_auth.password), 
        sizeof(p_account_list_cntx->current_account.in_auth.password));

    mmi_email_wizard_entry_account_name_process(p_account_list_cntx);
    cui_fseditor_close(fseditor_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_account_name_process
* DESCRIPTION
*  Entry the account name process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_account_name_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_ACCOUNT_NAME;
    mmi_email_wizard_entry_account_name_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_account_name_screen
* DESCRIPTION
*  Entry the account name screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_account_name_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fseditor_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcsncpy(p_account_list_cntx->current_account.acct_name, p_account_list_cntx->current_account.email_addr.email_addr,
        SRV_EMAIL_MAX_ACCT_NAME_LEN);

    mmi_email_wizard_get_default_acct_name(p_account_list_cntx);
    fseditor_id = cui_fseditor_create(p_account_list_cntx->new_account_group_id);
    cui_fseditor_set_title(fseditor_id, STR_EMAIL_ACCT_NAME_ID, GetRootTitleIcon(MENU_ID_EMAIL_MAIN));

    cui_fseditor_set_text(
        fseditor_id, 
        (p_account_list_cntx->current_account.acct_name), 
        sizeof(p_account_list_cntx->current_account.acct_name), 
        SRV_EMAIL_MAX_ACCT_NAME_LEN);
    cui_fseditor_set_input_method(
        fseditor_id, 
        IMM_INPUT_TYPE_SENTENCE, 
        NULL, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    cui_fseditor_set_title_in_header(fseditor_id, MMI_TRUE);
    cui_fseditor_run(fseditor_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_account_name_done_handler
* DESCRIPTION
*  when add a new account, handle adding account name next
* PARAMETERS
*  fseditor_id          [IN] The fseditor's id
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_account_name_done_handler(mmi_id fseditor_id, mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    EMAIL_ACCT_HANDLE account_handle = EMAIL_ACCT_INVALID_HANDLE;
    mmi_email_operate_result_enum create_result = MMI_EMAIL_OPERATE_RESULT_SUCCESS;
    mmi_email_account_error_code_struct error_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ACCOUNT_NAME_DONE_LOG1, p_account_list_cntx->srv_handle);
    cui_fseditor_get_text(
        fseditor_id, 
        p_account_list_cntx->current_account.acct_name, 
        sizeof(p_account_list_cntx->current_account.acct_name));

    /* edit the current account info begin */
    p_account_list_cntx->current_account.acct_type = SRV_EMAIL_ACCT_USER_CONFIGURED;
    
    if (SRV_EMAIL_PROT_POP3 == p_account_list_cntx->current_account.protocol)
    {
        p_account_list_cntx->current_account.in_server.port_num = MMI_EMAIL_POP3_PORT_NUMBER;
        p_account_list_cntx->current_account.in_server.sec_port_num = MMI_EMAIL_POP3_SECURITY_PORT_NUMBER;
    }
    else
    {
        p_account_list_cntx->current_account.in_server.port_num = MMI_EMAIL_IMAP_PORT_NUMBER;
        p_account_list_cntx->current_account.in_server.sec_port_num = MMI_EMAIL_IMAP_SECURITY_PORT_NUMBER;        
    }
    p_account_list_cntx->current_account.in_server.sec_mode = SRV_EMAIL_SEC_NONE;

    p_account_list_cntx->current_account.out_server.port_num = MMI_EMAIL_SMTP_PORT_NUMBER;
    p_account_list_cntx->current_account.out_server.sec_mode = SRV_EMAIL_SEC_NONE;
    p_account_list_cntx->current_account.out_server.sec_port_num = MMI_EMAIL_SMTP_SECURITY_PORT_NUMBER;

    p_account_list_cntx->current_account.in_auth.auth_type = SRV_EMAIL_AUTH_USER;
    memcpy(
        &p_account_list_cntx->current_account.out_auth,
        &p_account_list_cntx->current_account.in_auth,
        sizeof(srv_email_auth_struct));

    mmi_email_set_acct_attribute(&(p_account_list_cntx->current_account));
    /* edit the current account info end */

    mmi_email_asyn_create_account_p->type = MMI_EMAIL_ASYNC_CREATE_ACCOUNT_TYPE_FROM_WIZRAD;
    create_result = mmi_email_edit_account_create_new_account(
                        p_account_list_cntx->srv_handle, 
                        &(p_account_list_cntx->current_account), 
                        &error_info);
    if (MMI_EMAIL_OPERATE_RESULT_FAILED == create_result)
    {
        if (MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_SERVICE == error_info.error_type)
        {
            mmi_email_util_display_error_popup(
                p_account_list_cntx->new_account_group_id, 
                error_info.error_code.srv_error);
        }
        else
        {
            mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        }
        goto MMI_EMAIL_WIZARD_ACCOUNT_NAME_DONE_HANDLER_END;
    }
    else if (MMI_EMAIL_OPERATE_RESULT_WOULD_BLOCK == create_result)
    {
        goto MMI_EMAIL_WIZARD_ASYN_ACCOUNT_NAME_DONE_HANDLER_END;
    }
    
    mmi_email_smgr_account_add(p_account_list_cntx->current_account.acct_id);

MMI_EMAIL_WIZARD_ACCOUNT_NAME_DONE_HANDLER_END:
    cui_fseditor_close(fseditor_id);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_WIZARD_ACCOUNT_NAME_DONE_LOG5, account_handle, p_account_list_cntx->current_account.acct_id, srv_op_result, p_account_list_cntx->first_new_account);
    if (MMI_TRUE == p_account_list_cntx->first_new_account)
    {
        mmi_email_acct_setting_evt_struct setting_event;
        MMI_FRM_INIT_GROUP_EVENT(&setting_event, EVT_ID_ACCT_SETTING_EXIT, GRP_ID_EMAIL_ACCOUNT_WIZARD);
        mmi_frm_group_send_to_parent(GRP_ID_EMAIL_ACCOUNT_WIZARD, (mmi_group_event_struct*)&setting_event);
        p_account_list_cntx->first_new_account = MMI_FALSE;
        email_mmi_account_data_set_default(p_account_list_cntx->current_account.acct_id);
    }
MMI_EMAIL_WIZARD_ASYN_ACCOUNT_NAME_DONE_HANDLER_END:
    cui_fseditor_close(fseditor_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_cancel_process
* DESCRIPTION
*  Entry the wizard cancel process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_cancel_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_wizard_entry_cancel_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_cancel_screen
* DESCRIPTION
*  Entry the wizard cancel screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_cancel_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = p_account_list_cntx->new_account_group_id;
    confirm_struct.user_tag = (void*)MMI_EMAIL_ACCOUNT_ALERT_WIZARD_CANCEL;
    confirm_struct.f_auto_map_empty_softkey = 0;
    mmi_confirm_display((WCHAR*)GetString(STR_EMAIL_ACCT_CANCEL_WIZARD_ID), MMI_EVENT_QUERY, &confirm_struct);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_cancel_operation
* DESCRIPTION
*  Do the wizard cancel operation
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_cancel_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_WIZARD_CANCEL_OPERATION, __LINE__);

    mmi_frm_group_close(mmi_email_account_list_p->new_account_group_id);
    memset(&(mmi_email_account_list_p->current_account), 0, sizeof(mmi_email_account_list_p->current_account));
    mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_wizard_get_default_acct_name
 * DESCRIPTION
 *  get default account name
 * PARAMETERS
*   p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_wizard_get_default_acct_name(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *p_acct_name_base = NULL;
    S32 j = 0;
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_wcslen(p_account_list_cntx->current_account.acct_name) < (SRV_EMAIL_MAX_ACCT_NAME_LEN - 3)) && 
        (SRV_EMAIL_RESULT_SUCC == mmi_email_get_total_account_info(p_account_list_cntx)))
    {
        for (j = 0; j < p_account_list_cntx->account_num; j++)
        {
            if (p_account_list_cntx->current_account.acct_id == p_account_list_cntx->account_id_array[j])
            {
                continue;
            }
            
            if (0 == mmi_wcscmp(p_account_list_cntx->current_account.acct_name, p_account_list_cntx->account_name[j]))
            {
                if (p_acct_name_base == NULL)
                {
                    p_acct_name_base = p_account_list_cntx->account_name[j];
                }
                i++;
                j = -1;

                kal_wsprintf(p_account_list_cntx->current_account.acct_name, 
                    "%w%c%d%c", p_acct_name_base, '(', i, ')');
            }
        }
    }
    else
    {
    }
    
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_launch
* DESCRIPTION
*  Launch edit a coount process
* PARAMETERS
*  parent_id  [IN] The parent id
*  account_id [IN] The account id
* RETURNS
*  void
*****************************************************************************/
void mmi_email_entry_edit_account_launch(mmi_id parent_id, EMAIL_ACCT_ID account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_LAUNCH, parent_id, account_id);
    mmi_email_account_list_p->group_id = parent_id;
    mmi_email_account_list_p->current_account_id = account_id;
    mmi_email_entry_edit_account_process(mmi_email_account_list_p);
}


void mmi_email_entry_edit_account_sim_quit(void)
{
    mmi_frm_group_close(mmi_email_account_list_p->edit_account_group_id);
}


static void disconnect_confirmed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_DISCONNECT_TO_EDIT_SETTING_CONFIRM_LSK, __LINE__);

    mmi_email_app_nwk_user_disconnect(mmi_email_account_list_p->current_account_id);

    mmi_frm_group_create(
        mmi_email_account_list_p->group_id, 
        mmi_email_account_list_p->edit_account_group_id, 
        mmi_email_entry_edit_account_proc, 
        mmi_email_account_list_p);
    mmi_frm_group_enter(mmi_email_account_list_p->edit_account_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_email_app_nwk_freeze(mmi_email_account_list_p->current_account_id, TRUE);
    mmi_email_entry_edit_account_entry_main_setting_process(mmi_email_account_list_p);
}

/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_process
* DESCRIPTION
*  Edit a account
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_PROCESS, __LINE__);

    if (mmi_email_app_nwk_user_is_connected(p_account_list_cntx->current_account_id))
    {
        mmi_email_util_display_confirm(
            p_account_list_cntx->group_id,
            disconnect_confirmed,
            mmi_frm_scrn_close_active_id,
            NULL,
            TRUE,
            GetString(STR_EMAIL_EDIT_ACCT_ONLINE_ID),
            MMI_EVENT_QUERY);
    }
    else
    {
        disconnect_confirmed();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_proc
* DESCRIPTION
*  The procedure function of GPR_ID_EMAIL_ACCOUNT_EDIT
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        mmi_email_entry_edit_account_proc_handle_group_deinit_message((mmi_event_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        mmi_email_entry_edit_account_proc_handle_cui_inline_abort_message((cui_event_inline_abort_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_email_entry_edit_account_proc_handle_cui_menu_item_close_request_message((cui_menu_event_struct*)p_event);
        break;

    default:
        break;

    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_proc_handle_group_deinit_message
* DESCRIPTION
*  The handle function of EVT_ID_GROUP_DEINIT
* PARAMETERS
*  p_event   [IN] EVT_ID_GROUP_DEINIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_proc_handle_group_deinit_message(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    if (EMAIL_ACCT_INVALID_HANDLE != p_account_list_cntx->current_account_handle)
    {
        srv_email_acct_destroy(p_account_list_cntx->current_account_handle);
        p_account_list_cntx->current_account_handle = EMAIL_ACCT_INVALID_HANDLE;
    }
    mmi_email_app_nwk_freeze(p_account_list_cntx->current_edit_account_id, FALSE);
    p_account_list_cntx->current_edit_account_id = EMAIL_ACCT_INVALID_ID;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_proc_handle_cui_inline_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_proc_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_proc_handle_cui_menu_item_close_request_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_CLOSE_REQUEST
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_CLOSE_REQUEST event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_proc_handle_cui_menu_item_close_request_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_main_setting_process
* DESCRIPTION
*  Entry editing main account setting process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_main_setting_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_MAIN_SETTING_LOG1, p_account_list_cntx->srv_handle);

    srv_op_result = srv_email_acct_create(p_account_list_cntx->srv_handle, &p_account_list_cntx->current_account_handle);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_MAIN_SETTING_LOG2, srv_op_result);
        mmi_email_util_display_error_popup(p_account_list_cntx->edit_account_group_id, srv_op_result);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_MAIN_SETTING_PROCESS_END;
    }

    srv_op_result = srv_email_acct_open(p_account_list_cntx->current_account_handle, p_account_list_cntx->current_account_id);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_MAIN_SETTING_LOG3, p_account_list_cntx->current_account_handle, p_account_list_cntx->current_account_id, srv_op_result);
        mmi_email_util_display_error_popup(p_account_list_cntx->edit_account_group_id, srv_op_result);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_MAIN_SETTING_PROCESS_END;
    }

    srv_op_result = srv_email_acct_read(p_account_list_cntx->current_account_handle, &(p_account_list_cntx->current_account));
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_MAIN_SETTING_LOG4, p_account_list_cntx->current_account_handle, p_account_list_cntx->current_account_id, srv_op_result);
        mmi_email_util_display_error_popup(p_account_list_cntx->edit_account_group_id, srv_op_result);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_MAIN_SETTING_PROCESS_END;
    }

    srv_op_result = srv_email_acct_get_permission(p_account_list_cntx->current_account_handle);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        mmi_email_util_display_error_popup(p_account_list_cntx->edit_account_group_id, srv_op_result);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_MAIN_SETTING_PROCESS_END;
    }

    if (MMI_FALSE == mmi_email_entry_edit_account_read_account_extra_info(
                        p_account_list_cntx->current_account_id, 
                        &(p_account_list_cntx->current_account_extra_info), 
                        NULL))
    {
        mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_MAIN_SETTING_PROCESS_END;
    }
    /* edit the current edit account id */
    p_account_list_cntx->current_edit_account_id = p_account_list_cntx->current_account_id;
    
    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_MAIN_SCREEN;
    p_account_list_cntx->edit_account_main_setting_group_id = mmi_frm_group_create(
                                                                p_account_list_cntx->edit_account_group_id, 
                                                                GRP_ID_AUTO_GEN, 
                                                                mmi_email_entry_edit_account_entry_main_setting_proc, 
                                                                p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->edit_account_main_setting_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    // compose the account edit(setting) screen
    mmi_email_entry_edit_account_entry_main_setting_screen(p_account_list_cntx);
    return;
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_MAIN_SETTING_PROCESS_END:
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_main_setting_proc
* DESCRIPTION
*  The procedure function of edit_account_main_setting_group_id
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_entry_main_setting_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->evt_id)
    {
        case EVT_ID_CUI_INLINE_SET_KEY:
            mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_setkey_message((cui_event_inline_set_key_struct*)p_event);
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:  // when click {Done}
            mmi_email_entry_edit_account_main_setting_proc_handle_inline_submit_message((cui_event_inline_submit_struct*)p_event);
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_abort_message((cui_event_inline_abort_struct*)p_event);
            break;

        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
            mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_deinit_message((cui_event_inline_common_struct*)p_event);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            // for advanced setting
            mmi_email_entry_edit_account_main_setting_proc_handle_list_entry_message((cui_menu_event_struct*)p_event);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_email_entry_edit_account_main_setting_proc_handle_list_select_message((cui_menu_event_struct*)p_event);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_email_entry_edit_account_main_setting_proc_handle_close_request_message((cui_menu_event_struct*)p_event);
            break;

        case EVT_ID_GROUP_FOCUSED:
            mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->edit_account_main_setting_group_id);
            break;

        case EVT_ID_ALERT_QUIT: // handle the exit event (confirm)
            mmi_email_entry_edit_account_main_setting_proc_handle_alert_quit_message((mmi_alert_result_evt_struct*)p_event);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_setkey_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SET_KEY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SET_KEY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_setkey_message(cui_event_inline_set_key_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->item_id)
    {
        case MMI_EMAIL_ACCOUNT_EDIT_ADVANCE_SETTINGS_CAPTION_ID:
        {   // for advanced setting item
            //SetLeftSoftkeyFunction(mmi_email_entry_edit_account_advance_setting, KEY_EVENT_UP);
            wgui_inline_set_lsk_function(mmi_email_entry_edit_account_advance_setting);
            SetCenterSoftkeyFunction(mmi_email_entry_edit_account_advance_setting, KEY_EVENT_UP);
            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_main_setting_proc_handle_inline_submit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SUBMIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SUBMIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_main_setting_proc_handle_inline_submit_message(cui_event_inline_submit_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    mmi_confirm_property_struct confirm_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    
    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = p_account_list_cntx->edit_account_main_setting_group_id;
    confirm_struct.user_tag = (void*)MMI_EMAIL_ACCOUNT_ALERT_SAVE_MAIN_ACCOUNT_SETTING;
    mmi_confirm_display((WCHAR*)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &confirm_struct);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_deinit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_GROUP_DEINIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_GROUP_DEINIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_main_setting_proc_handle_cui_inline_deinit_message(cui_event_inline_common_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_main_setting_proc_handle_list_entry_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_LIST_ENTRY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_LIST_ENTRY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_main_setting_proc_handle_list_entry_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->parent_menu_id)
    {
        case MENU_ID_EMAIL_PROF_EDIT_OPT:
        {
            mmi_menu_id advace_setting_menu_id_array[] = {
                                                          MENU_ID_EMAIL_PROF_EDIT_OPT_SETTING, 
                                                          MENU_ID_EMAIL_PROF_EDIT_OPT_SMTP,
                                                          MENU_ID_EMAIL_PROF_EDIT_OPT_POP3_IMAP4,
                                                          MENU_ID_EMAIL_PROF_EDIT_OPT_SIG};
            U16 advace_setting_menu_id_string_array[] = {
                                                            STR_EMAIL_ACCT_SETTING_ID, 
                                                            STR_EMAIL_SMTP_SETTING_ID,
                                                            STR_EMAIL_POP3_IMAP4_SETTING_ID,
                                                            STR_EMAIL_SIGNATURE_ID};
            U16 advace_setting_menu_id_image_array[] = {
                                                        IMG_EMAIL_PROFILE_SETTING_ID,
                                                        IMG_EMAIL_SMTP_SETTING_ID,
                                                        IMG_EMAIL_IMAP_POP3_SETTING_ID,
                                                        IMG_EMAIL_SIGNATURE_SETTING_ID};
            mmi_email_menu_screen_struct menu_screen;

            menu_screen.title_string_id = STR_EMAIL_ACCT_ADVANDED_ID;
            menu_screen.title_icon_id = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
            menu_screen.menu_item_number = sizeof(advace_setting_menu_id_array) / sizeof(mmi_menu_id);
            menu_screen.menu_id_array = advace_setting_menu_id_array;
            menu_screen.menu_id_string_array = advace_setting_menu_id_string_array;
            menu_screen.menu_id_image_array = advace_setting_menu_id_image_array;
            
            mmi_email_account_set_menu_screen(p_event->sender_id, &menu_screen, STR_GLOBAL_OK);
            break;
        }
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_main_setting_proc_handle_list_select_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_ITEM_SELECT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_ITEM_SELECT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_main_setting_proc_handle_list_select_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    
    switch (p_event->highlighted_menu_id)
    {
        case MENU_ID_EMAIL_PROF_EDIT_OPT_SETTING:
            mmi_email_entry_edit_account_entry_account_setting_process(p_account_list_cntx);
            break;

        case MENU_ID_EMAIL_PROF_EDIT_OPT_SMTP:
            mmi_email_entry_edit_account_entry_outgoing_server_process(p_account_list_cntx);
            break;

        case MENU_ID_EMAIL_PROF_EDIT_OPT_POP3_IMAP4:
            mmi_email_entry_edit_account_entry_incoming_server_process(p_account_list_cntx);
            break;

        case MENU_ID_EMAIL_PROF_EDIT_OPT_SIG:
            mmi_email_entry_edit_account_entry_signature_process(p_account_list_cntx);
            break;

        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_main_setting_proc_handle_close_request_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_CLOSE_REQUEST
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_CLOSE_REQUEST event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_main_setting_proc_handle_close_request_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_main_setting_proc_handle_alert_quit_message
* DESCRIPTION
*  The handle function of EVT_ID_ALERT_QUIT
* PARAMETERS
*  p_event   [IN] EVT_ID_ALERT_QUIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_main_setting_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
    case MMI_EMAIL_ACCOUNT_ALERT_SAVE_MAIN_ACCOUNT_SETTING:
        if (MMI_ALERT_CNFM_YES == p_event->result)
        {
            mmi_email_entry_edit_account_save_main_account_setting_lsk();
        }
        else if (MMI_ALERT_CNFM_NO == p_event->result)
        {
            mmi_email_entry_edit_account_save_main_account_setting_rsk();
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_main_setting_screen
* DESCRIPTION
*  Entry editing main account setting screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_main_setting_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};
    cui_inline_set_item_struct *inline_item = NULL;
    cui_inline_struct inline_struct;
    cui_inline_item_caption_struct caption_struct[MMI_EMAIL_ACCOUNT_EDIT_CAPTION_ITEMS_NUMBER];
    cui_inline_item_fullscreen_edit_struct *fullscreen_edit_struct = NULL;
    cui_inline_item_display_only_struct display_only_struct[MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_ONLY_ITEMS_NUMBER];

    S32 inline_item_index = 0;
    S32 caption_index = 0;
    S32 fullscreen_index = 0;
    S32 display_index = 0;

    U16 email_icon = 0;
    mmi_id inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_MAIN_SETTING_SCREEN, __LINE__);

    inline_item = OslMalloc(MMI_EMAIL_ACCOUNT_EDIT_ITEMS_NUMBER * sizeof(cui_inline_set_item_struct));
    fullscreen_edit_struct = OslMalloc(MMI_EMAIL_ACCOUNT_EDIT_FULL_SCREEN_ITEMS_NUMBER * sizeof(cui_inline_item_fullscreen_edit_struct));
    
    email_icon = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);

    /* email address part begin*/
    caption_struct[caption_index].string_id = STR_EMAIL_EMAIL_ADDRESS_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_EMAIL_ADDRESS_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_EMAIL_ADDRESS_ID, 
        &caption_struct[caption_index++]);
    
    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_EMAIL_EMAIL_ADDRESS_ID, 
        email_icon, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, 
        IMM_INPUT_TYPE_EMAIL, 
        (SRV_EMAIL_MAX_ADDR_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_EMAIL_ADDRESS_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 
        0, 
        &fullscreen_edit_struct[fullscreen_index++]);
    /* email address part end*/

    /* display name part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_DISPLAY_NAME_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_NAME_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_DISPLAY_NAME_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_EMAIL_DISPLAY_NAME_ID, 
        email_icon, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, 
        IMM_INPUT_TYPE_SENTENCE, 
        (SRV_EMAIL_MAX_DISP_NAME_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_NAME_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 
        0, 
        &fullscreen_edit_struct[fullscreen_index++]);
    /* display name part end */

    /* user name part begin */
    caption_struct[caption_index].string_id = STR_GLOBAL_USERNAME;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_USER_NAME_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_USER_NAME_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_GLOBAL_USERNAME, 
        email_icon, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, 
        IMM_INPUT_TYPE_ASCII_CHAR, 
        (SRV_EMAIL_MAX_USERNAME_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_USER_NAME_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 
        0, 
        &fullscreen_edit_struct[fullscreen_index++]);
    /* user name part end */

    /* password part begin */
    caption_struct[caption_index].string_id = STR_GLOBAL_PASSWORD;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_PASSWORD_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_PASSWORD_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_GLOBAL_PASSWORD, 
        email_icon, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, 
        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 
        (SRV_EMAIL_MAX_PASSWORD_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_PASSWORD_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 
        0, 
        &fullscreen_edit_struct[fullscreen_index++]);
    /* password part end */

    /* outgoing server begin */
    caption_struct[caption_index].string_id = STR_EMAIL_OUTGOING_SERVER_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_OUTGOING_SERVER_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_EMAIL_OUTGOING_SERVER_ID, 
        email_icon, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, 
        IMM_INPUT_TYPE_EMAIL, 
        (SRV_EMAIL_MAX_SERVER_NAME_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 
        0, 
        &fullscreen_edit_struct[fullscreen_index++]);
    /* outgoing server end */

    /* incoming server begin */
    caption_struct[caption_index].string_id = STR_EMAIL_INCOMING_SERVER_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_INCOMING_SERVER_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_EMAIL_INCOMING_SERVER_ID, 
        email_icon, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, 
        IMM_INPUT_TYPE_EMAIL, 
        (SRV_EMAIL_MAX_SERVER_NAME_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 
        0, 
        &fullscreen_edit_struct[fullscreen_index++]);
    /* incoming server end */

    /* advance setting begin */
    display_only_struct[display_index].string_id = STR_EMAIL_ACCT_ADVANDED_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_EDIT_ADVANCE_SETTINGS_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 
        IMG_EMAIL_PROFILE_ADVANDED_ID, 
        &display_only_struct[display_index++]);
    /* advance setting end */
    
    inline_struct.items_count = MMI_EMAIL_ACCOUNT_EDIT_ITEMS_NUMBER;
    inline_struct.title = STR_EMAIL_ACCT_ID;
    inline_struct.title_icon = email_icon;
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(p_account_list_cntx->edit_account_main_setting_group_id, &inline_struct);
    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_ACCOUNT_EDIT_EMAIL_ADDRESS_CONTENT_ID, 
        p_account_list_cntx->current_account.email_addr.email_addr);
    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_NAME_CONTENT_ID, 
        p_account_list_cntx->current_account.email_addr.disp_name);
    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_ACCOUNT_EDIT_USER_NAME_CONTENT_ID, 
        p_account_list_cntx->current_account.in_auth.username);
    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_ACCOUNT_EDIT_PASSWORD_CONTENT_ID, 
        p_account_list_cntx->current_account.in_auth.password);
    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CONTENT_ID, 
        p_account_list_cntx->current_account.out_server.server_name);
    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CONTENT_ID, 
        p_account_list_cntx->current_account.in_server.server_name);

#ifdef __MMI_SSO__
    if (mmi_email_sso_is_cloud_account(p_account_list_cntx->current_account_id))
    {
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_ACCOUNT_EDIT_EMAIL_ADDRESS_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
        //cui_inline_set_item_attributes(inline_id, MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_NAME_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_ACCOUNT_EDIT_USER_NAME_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_ACCOUNT_EDIT_PASSWORD_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
    }
#endif /* __MMI_SSO__ */

    if (MMI_TRUE == p_account_list_cntx->current_account.read_only)
    {
        cui_inline_set_softkey_text(inline_id, MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CONTENT_ID, MMI_LEFT_SOFTKEY, 0);
        cui_inline_set_softkey_icon(inline_id, MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CONTENT_ID, MMI_LEFT_SOFTKEY, 0);

        cui_inline_set_softkey_text(inline_id, MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CONTENT_ID, MMI_LEFT_SOFTKEY, 0);
        cui_inline_set_softkey_icon(inline_id, MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CONTENT_ID, MMI_LEFT_SOFTKEY, 0);
    }

    cui_inline_set_softkey_text(inline_id, MMI_EMAIL_ACCOUNT_EDIT_ADVANCE_SETTINGS_CAPTION_ID, MMI_LEFT_SOFTKEY, STR_GLOBAL_OPEN);
    cui_inline_set_softkey_icon(inline_id, MMI_EMAIL_ACCOUNT_EDIT_ADVANCE_SETTINGS_CAPTION_ID, MMI_LEFT_SOFTKEY, IMG_GLOBAL_OK);

    cui_inline_set_softkey_icon(
        inline_id, 
        MMI_EMAIL_ACCOUNT_EDIT_ADVANCE_SETTINGS_CAPTION_ID, 
        MMI_CENTER_SOFTKEY, 
        IMG_GLOBAL_COMMON_CSK);
    
    cui_inline_run(inline_id);
    p_account_list_cntx->account_main_setting_id = inline_id;

    if (NULL != fullscreen_edit_struct)
    {
        OslMfree(fullscreen_edit_struct);
        fullscreen_edit_struct = NULL;
    }
    if (NULL != inline_item)
    {
        OslMfree(inline_item);
        inline_item = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_advance_setting
* DESCRIPTION
*  Entry advance setting screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_advance_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id edit_account_option_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    edit_account_option_id = cui_menu_create(
                                mmi_email_account_list_p->edit_account_main_setting_group_id, 
                                CUI_MENU_SRC_TYPE_APPCREATE, 
                                CUI_MENU_TYPE_APPSUB, 
                                MENU_ID_EMAIL_PROF_EDIT_OPT, 
                                MMI_FALSE, 
                                mmi_email_account_list_p);
    cui_menu_run(edit_account_option_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_convert_check_interval_value
* DESCRIPTION
*  Convert the check interval value to enum
* PARAMETERS
*  interval_value  [IN] check interval value  
* RETURNS
*  mmi_email_account_check_interval_enum
*****************************************************************************/
static mmi_email_account_check_interval_enum mmi_email_entry_edit_account_convert_check_interval_value(U32 interval_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_check_interval_enum return_value = MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_5_MIN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (interval_value <= (5 * 60))
    {
        return_value = MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_5_MIN;
    }
    else if (interval_value <= (30 * 60))
    {
        return_value = MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_30_MIN;
    }
    else if (interval_value <= (60 * 60))
    {
        return_value = MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_1_HOUR;
    }
    else
    {
        return_value = MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_2_HOUR;
    }
    
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_account_setting_process
* DESCRIPTION
*  Entry editing account setting process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_account_setting_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_ACCOUNT_SETTING_PROCESS, __LINE__);

    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_ACCOUNT_SETTING;
    p_account_list_cntx->edit_account_setting_group_id = mmi_frm_group_create(
                                                            p_account_list_cntx->edit_account_group_id, 
                                                            GRP_ID_AUTO_GEN, 
                                                            mmi_email_entry_edit_account_entry_account_setting_proc, 
                                                            p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->edit_account_setting_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_email_entry_edit_account_entry_account_setting_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_account_setting_proc
* DESCRIPTION
*  The procedure function of edit_account_setting_group_id
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_entry_account_setting_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->evt_id)
    {
        case EVT_ID_CUI_INLINE_NOTIFY:
            mmi_email_entry_edit_account_account_setting_proc_handle_inline_notify_message((cui_event_inline_notify_struct*)p_event);
            break;

        case EVT_ID_CUI_INLINE_SET_KEY:
            mmi_email_entry_edit_account_account_setting_proc_handle_inline_setkey_message((cui_event_inline_set_key_struct*)p_event);
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
            mmi_email_entry_edit_account_account_setting_proc_handle_inline_submit_message((cui_event_inline_submit_struct*)p_event);
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            mmi_email_entry_edit_account_account_setting_proc_handle_inline_abort_message((cui_event_inline_abort_struct*)p_event);
            break;

        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
            mmi_email_entry_edit_account_account_setting_proc_handle_inline_deinit_message((cui_event_inline_common_struct*)p_event);
            break;

        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_sub_message((cui_fseditor_evt_struct*)p_event);
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_abort_message((cui_fseditor_evt_struct*)p_event);
            break;

        case EVT_ID_CUI_FSEDITOR_EMPTY:
            mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_empty_message((cui_fseditor_evt_struct*)p_event);
            break;

        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
            mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_no_message((cui_fseditor_evt_struct*)p_event);
            break;

        case EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED:
            mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_sel_message((cui_fseditor_custom_menu_select_evt_struct*)p_event);
            break;

        case EVT_ID_PHB_SELECT_CONTACT:
            mmi_email_entry_edit_account_account_setting_proc_handle_phb_select_message((cui_phb_select_contact_result_struct*)p_event);
            break;

        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            mmi_email_entry_edit_account_account_setting_proc_handle_phb_sel_cancel_message((cui_phb_select_contact_result_struct*)p_event);
            break;

        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
            mmi_email_data_account_cui_dtcnt_select_ok_message((cui_dtcnt_select_event_any_sim_selected_struct*)p_event);
            break;

        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
            mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_done_message((cui_dtcnt_select_event_struct*)p_event);
            break;

        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
            mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_cancel_message((cui_dtcnt_select_event_struct*)p_event);
            break;

        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            mmi_email_wizard_entry_data_account_proc_handle_cui_dtcnt_select_close_message((cui_dtcnt_select_event_struct*)p_event);
            break;

        case EVT_ID_GROUP_FOCUSED:
            mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->edit_account_setting_group_id);
            break;

        case EVT_ID_ALERT_QUIT:
            mmi_email_entry_edit_account_account_setting_proc_handle_alert_quit_message((mmi_alert_result_evt_struct*)p_event);
            break;

        default:
            break;

    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_inline_notify_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_NOTIFY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_NOTIFY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_notify_message(cui_event_inline_notify_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    MMI_BOOL conflict_dtcnt = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    switch (p_event->event_type)
    {
        case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
        {
            conflict_dtcnt = mmi_email_dtcnt_is_any_conflict(p_account_list_cntx->edit_dataacct_id);
            
        #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
            if (MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID == p_event->item_id)
            {
            #ifdef __MMI_EMAIL_EMN__
                if ((0 == p_event->param) && (MMI_FALSE == conflict_dtcnt))
                {
                    cui_inline_set_item_attributes(
                        p_event->sender_id, 
                        MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
                        CUI_INLINE_RESET_ATTRIBUTE, 
                        CUI_INLINE_ITEM_DISABLE);
                }
                else
                {
                    cui_inline_set_item_attributes(
                        p_event->sender_id, 
                        MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
                        CUI_INLINE_SET_ATTRIBUTE, 
                        CUI_INLINE_ITEM_DISABLE);
                }
            #endif /* __MMI_EMAIL_EMN__ */
            }
        #endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
        #ifdef __MMI_EMAIL_EMN__
            if (MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID == p_event->item_id)
            {
            #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
                if ((0 == p_event->param) && (MMI_FALSE == conflict_dtcnt))
                {
                    cui_inline_set_item_attributes(
                        p_event->sender_id, 
                        MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
                        CUI_INLINE_RESET_ATTRIBUTE, 
                        CUI_INLINE_ITEM_DISABLE);
                }
                else
                {
                    cui_inline_set_item_attributes(
                        p_event->sender_id, 
                        MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
                        CUI_INLINE_SET_ATTRIBUTE, 
                        CUI_INLINE_ITEM_DISABLE);
                }
            #endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
            }
        #endif /* __MMI_EMAIL_EMN__ */
            break;
        }
        case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
        {
            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_inline_setkey_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SET_KEY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SET_KEY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_setkey_message(cui_event_inline_set_key_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->item_id)
    {
    case MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CONTENT_ID:
        //SetLeftSoftkeyFunction(mmi_email_entry_edit_account_entry_account_setting_reply_addr_lsk, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_email_entry_edit_account_entry_account_setting_reply_addr_lsk);
        SetCenterSoftkeyFunction(mmi_email_entry_edit_account_entry_account_setting_reply_addr_lsk, KEY_EVENT_UP);
        break;

    case MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CONTENT_ID :
        //SetLeftSoftkeyFunction(mmi_email_entry_edit_account_entry_account_setting_sel_dtcnt_lsk, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_email_entry_edit_account_entry_account_setting_sel_dtcnt_lsk);
        SetCenterSoftkeyFunction(mmi_email_entry_edit_account_entry_account_setting_sel_dtcnt_lsk, KEY_EVENT_UP);
        break;

    case MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID:
        SetCenterSoftkeyFunction(mmi_email_entry_edit_account_entry_account_setting_chk_interval_lsk, KEY_EVENT_UP);
        break;

#ifdef __MMI_EMAIL_EMN__
    case MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID:
        SetCenterSoftkeyFunction(mmi_email_entry_edit_account_entry_account_setting_emn_lsk, KEY_EVENT_UP);
        break;
#endif /* __MMI_EMAIL_EMN__ */

    default:
        break;
    }
}

static void mmi_email_entry_edit_account_entry_account_setting_chk_interval_lsk(void)
{
    mmi_email_entry_edit_account_account_setting_proc_handle_inline_submit_message(NULL);
}

#ifdef __MMI_EMAIL_EMN__
static void mmi_email_entry_edit_account_entry_account_setting_emn_lsk(void)
{
    mmi_email_entry_edit_account_account_setting_proc_handle_inline_submit_message(NULL);
}
#endif /* __MMI_EMAIL_EMN__ */


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_inline_submit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SUBMIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SUBMIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_submit_message(cui_event_inline_submit_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = mmi_email_account_list_p->edit_account_setting_group_id;
    confirm_struct.user_tag = (void*)MMI_EMAIL_ACCOUNT_ALERT_SAVE_ACCOUNT_SETTING;
    mmi_confirm_display((WCHAR*)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &confirm_struct);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_inline_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_abort_message(cui_event_inline_abort_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_inline_deinit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_GROUP_DEINIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_GROUP_DEINIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_inline_deinit_message(cui_event_inline_common_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_sub_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_SUBMMIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_SUBMMIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_sub_message(cui_fseditor_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_event->user_data;
    
    cui_fseditor_get_text(
        p_event->sender_id, 
        p_account_list_cntx->current_account.reply_to_addr.email_addr, 
        sizeof(p_account_list_cntx->current_account.reply_to_addr.email_addr));

    if (MMI_TRUE == p_account_list_cntx->select_email_addr_from_phb.select_from_phb)
    {
        if (0 != mmi_wcscmp(
                    p_account_list_cntx->current_account.reply_to_addr.email_addr, 
                    p_account_list_cntx->select_email_addr_from_phb.email_addr.email_addr))
        {
            memset(
                p_account_list_cntx->current_account.reply_to_addr.disp_name,
                0,
                sizeof(p_account_list_cntx->current_account.reply_to_addr.disp_name));
        }
    }
    cui_fseditor_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_abort_message(cui_fseditor_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_empty_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_EMPTY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_EMPTY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_empty_message(cui_fseditor_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_set_custom_options_menu(
        p_event->sender_id, 
        MMI_TRUE, 
        mmi_email_account_reply_addr_menu_id_search, 
        (sizeof(mmi_email_account_reply_addr_menu_id_search) / sizeof(mmi_menu_id)));
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_no_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_NOT_EMPTY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_NOT_EMPTY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_no_message(cui_fseditor_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_fseditor_set_custom_options_menu(
        p_event->sender_id, 
        MMI_TRUE, 
        mmi_email_account_reply_addr_menu_id_done, 
        (sizeof(mmi_email_account_reply_addr_menu_id_done) / sizeof(mmi_menu_id)));
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_sel_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_fseditor_sel_message(cui_fseditor_custom_menu_select_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_event->user_data;
    
    switch (p_event->menu_id)
    {
        case MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_SEARCH:
        {    
            mmi_id phb_id = GRP_ID_INVALID;
    
            p_account_list_cntx->current_fseditor_id = p_event->sender_id;
            phb_id = cui_phb_list_select_contact_create(p_account_list_cntx->edit_account_setting_group_id);
            cui_phb_list_select_contact_set_field_filter(phb_id, SRV_PHB_ENTRY_FIELD_EMAIL);
            cui_phb_list_select_contact_run(phb_id);

            break;
        }

        case MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_DONE:
            cui_fseditor_get_text(
                p_event->sender_id, 
                p_account_list_cntx->edit_reply_to_addr.email_addr, 
                sizeof(p_account_list_cntx->edit_reply_to_addr.email_addr));
            if (MMI_TRUE == p_account_list_cntx->select_email_addr_from_phb.select_from_phb)
            {
                if (0 == mmi_wcscmp(
                            p_account_list_cntx->edit_reply_to_addr.email_addr, 
                            p_account_list_cntx->select_email_addr_from_phb.email_addr.email_addr))
                {
                    mmi_wcscpy(
                        p_account_list_cntx->edit_reply_to_addr.disp_name, 
                        p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_name);
                    p_account_list_cntx->edit_reply_to_addr.disp_charset = 
                        p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_charset;
                    p_account_list_cntx->edit_reply_to_addr.disp_name_len = 
                        p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_name_len;
                }
                else
                {
                    p_account_list_cntx->edit_reply_to_addr.disp_name[0] = 0;
                    p_account_list_cntx->edit_reply_to_addr.disp_charset = MMI_CHSET_BASE;
                    p_account_list_cntx->edit_reply_to_addr.disp_name_len = 0;
                }
            }
            cui_inline_set_value(
                p_account_list_cntx->account_setting_id, 
                MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CONTENT_ID, 
                p_account_list_cntx->edit_reply_to_addr.email_addr);
            cui_inline_set_screen_attributes(
                p_account_list_cntx->account_setting_id, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
            cui_fseditor_close(p_event->sender_id);
            break;

        default:
            break;

    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_phb_select_message
* DESCRIPTION
*  The handle function of EVT_ID_PHB_SELECT_CONTACT
* PARAMETERS
*  p_event   [IN] EVT_ID_PHB_SELECT_CONTACT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_phb_select_message(cui_phb_select_contact_result_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_event->user_data;

    p_account_list_cntx->select_email_addr_from_phb.select_from_phb = MMI_TRUE;
    
    mmi_wcsncpy(
        p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_name,
        p_event->name,
        SRV_EMAIL_MAX_DISP_NAME_LEN);
    p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_name_len = mmi_wcslen(p_event->name);
    p_account_list_cntx->select_email_addr_from_phb.email_addr.disp_charset = MMI_CHSET_UCS2;

    mmi_wcsncpy(
        p_account_list_cntx->select_email_addr_from_phb.email_addr.email_addr, 
        p_event->select_data, 
        SRV_EMAIL_MAX_ADDR_LEN);
    cui_fseditor_set_text(
        p_account_list_cntx->current_fseditor_id, 
        p_account_list_cntx->select_email_addr_from_phb.email_addr.email_addr, 
        (SRV_EMAIL_MAX_ADDR_LEN + 1) * sizeof(WCHAR), 
        SRV_EMAIL_MAX_ADDR_LEN);

    p_account_list_cntx->current_fseditor_id = GRP_ID_INVALID;
    
    cui_phb_list_select_contact_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_phb_sel_cancel_message
* DESCRIPTION
*  The handle function of EVT_ID_PHB_SELECT_CONTACT_CANCEL
* PARAMETERS
*  p_event   [IN] EVT_ID_PHB_SELECT_CONTACT_CANCEL event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_phb_sel_cancel_message(cui_phb_select_contact_result_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_event->user_data;
    p_account_list_cntx->current_fseditor_id = GRP_ID_INVALID;

    cui_phb_list_select_contact_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_account_setting_proc_handle_alert_quit_message
* DESCRIPTION
*  The handle function of EVT_ID_ALERT_QUIT
* PARAMETERS
*  p_event   [IN] EVT_ID_ALERT_QUIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_account_setting_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
        case MMI_EMAIL_ACCOUNT_ALERT_SAVE_ACCOUNT_SETTING:
        {
            if (MMI_ALERT_CNFM_YES == p_event->result)
            {
                mmi_email_entry_edit_account_save_account_setting_lsk();
            }
            else if (MMI_ALERT_CNFM_NO == p_event->result)
            {
                mmi_email_entry_edit_account_save_account_setting_rsk();
            }
        }
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_account_setting_sel_dtcnt_lsk
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_account_setting_sel_dtcnt_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_p->dtcnt_changed = MMI_FALSE;
    mmi_email_account_enter_dtcnt_cui(
        mmi_email_account_list_p->edit_account_setting_group_id, 
        mmi_email_account_list_p->edit_dataacct_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_account_setting_reply_addr_lsk
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_account_setting_reply_addr_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fseditor_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_p->select_email_addr_from_phb.select_from_phb = MMI_FALSE;
    
    fseditor_id = cui_fseditor_create(mmi_email_account_list_p->edit_account_setting_group_id);
    cui_fseditor_set_title(fseditor_id, STR_EMAIL_REPLY_TO_ID, GetRootTitleIcon(MENU_ID_EMAIL_MAIN));
    cui_fseditor_set_text(
        fseditor_id, 
        (WCHAR*)(mmi_email_account_list_p->edit_reply_to_addr.email_addr), 
        sizeof(mmi_email_account_list_p->edit_reply_to_addr.email_addr), 
        SRV_EMAIL_MAX_ADDR_LEN);
    cui_fseditor_set_input_method(
        fseditor_id, 
        IMM_INPUT_TYPE_EMAIL, 
        NULL, 
        0);
    cui_fseditor_run(fseditor_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_account_setting_screen
* DESCRIPTION
*  Entry account setting screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_account_setting_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct;

    cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};
    U16 protocol_string_id_array[] = {STR_EMAIL_POP3_ID, STR_EMAIL_IMAP4_ID};
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    U16 check_interval_string_id_array[] = {STR_GLOBAL_OFF, STR_EMAIL_5_MIN_ID, STR_EMAIL_30_MIN_ID, STR_EMAIL_1_HOUR_ID, STR_EMAIL_2_HOURS_ID};
    mmi_email_auto_check_time_segment auto_check_segment;
    MMI_BOOL check_interval_open = MMI_FALSE;
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
#ifdef __MMI_EMAIL_EMN__
    U16 emn_string_id_array[] = {STR_EMAIL_EMN_DISABLED_ID, STR_EMAIL_EMN_AUTO_UPDATE_ID};
#endif /* __MMI_EMAIL_EMN__ */

    cui_inline_set_item_struct *inline_item = NULL;
    cui_inline_item_caption_struct caption_struct[MMI_EMAIL_ACCOUNT_SETTING_EDIT_CAPTION_ITEMS_NUMBER];
    cui_inline_item_fullscreen_edit_struct fullscreen_edit_struct[MMI_EMAIL_ACCOUNT_SETTING_EDIT_FULL_SCREEN_ITEMS_NUMBER];
    cui_inline_item_select_struct select_struct[MMI_EMAIL_ACCOUNT_SETTING_EDIT_SELECT_ITEMS_NUMBER];
    cui_inline_item_text_edit_struct *text_edit_struct = NULL;
    cui_inline_item_display_only_struct display_only_struct[MMI_EMAIL_ACCOUNT_SETTING_EDIT_DISPLAY_ONLY_ITEMS_NUMBER];
        
    S32 inline_item_index = 0;
    S32 caption_index = 0;
    S32 fullscreen_index = 0;
    S32 select_index = 0;
    S32 text_index = 0;
    S32 display_index = 0;
    
    U16 email_icon = 0;
    mmi_id inline_id = GRP_ID_INVALID;
    WCHAR number_string[MMI_EMAIL_MAX_DOWNLOAD_SIZE + 1];
    MMI_BOOL conflict_dtcnt = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_ACCOUNT_SETTING_SCREEN, __LINE__);

    inline_item = OslMalloc(sizeof(cui_inline_set_item_struct) * MMI_EMAIL_ACCOUNT_SETTING_EDIT_ITEMS_NUMBER);
    text_edit_struct = OslMalloc(sizeof(cui_inline_item_text_edit_struct) * MMI_EMAIL_ACCOUNT_SETTING_EDIT_TEXT_ITEMS_NUMBER);

    email_icon = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
    conflict_dtcnt = mmi_email_dtcnt_is_any_conflict(p_account_list_cntx->current_account.in_server.data_acct);

    /* account name part begin*/
    caption_struct[caption_index].string_id = STR_EMAIL_ACCT_NAME_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_ACCOUNT_NAME_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_PROFILE_NAME_ID,
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index],
        0,
        0,
        STR_EMAIL_ACCT_NAME_ID,
        email_icon,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        IMM_INPUT_TYPE_SENTENCE,
        (SRV_EMAIL_MAX_ACCT_NAME_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_ACCOUNT_NAME_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT,
        0,
        &fullscreen_edit_struct[fullscreen_index++]);
    /* account name part end*/

    /* data account part begin */
    caption_struct[caption_index].string_id = STR_GLOBAL_DATA_ACCOUNT;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_DATA_ACCOUNT_ID,
        &caption_struct[caption_index++]);

    display_only_struct[display_index].string_id = 0;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,
        0,
        &display_only_struct[display_index++]);
    /* data account part end */

    /* protocol part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_PROTOCOL_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_PROTOCOL_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_PROTOCOL_ID,
        &caption_struct[caption_index++]);
    
    if (SRV_EMAIL_PROT_POP3 == p_account_list_cntx->current_account.protocol)
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(protocol_string_id_array) / sizeof(U16), 
            0, 
            protocol_string_id_array);
    }
    else
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(protocol_string_id_array) / sizeof(U16), 
            1, 
            protocol_string_id_array);
    }
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_PROTOCOL_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* protocol part end */

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    /* check interval part begin */
    //mmi_email_auto_check_get_status(p_account_list_cntx->current_account_id, &check_interval_open);
    if (MMI_EMAIL_SUCCESS != mmi_email_auto_check_get_day_enable(
                                p_account_list_cntx->current_account_id, 
                                0, 
                                &check_interval_open))
    {
        mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_ACCOUNT_SETTING_SCREEN_END;
    }

    if (MMI_TRUE == check_interval_open)
    {
        if (MMI_EMAIL_SUCCESS != mmi_email_auto_check_get_segment(
                                    p_account_list_cntx->current_account_id, 
                                    0, 
                                    0, 
                                    &auto_check_segment))
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_EDIT_ACCOUNT_SETTING_SCREEN_LOG1);
            mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_ACCOUNT_SETTING_SCREEN_END;
        }
        p_account_list_cntx->check_interval_value = 
            mmi_email_entry_edit_account_convert_check_interval_value(
            auto_check_segment.interval);
    }
    else
    {
        p_account_list_cntx->check_interval_value = MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_OFF;
    }
    
    caption_struct[caption_index].string_id = STR_EMAIL_CHECK_INTERVAL_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_CHECK_INTERVAL_ID,
        &caption_struct[caption_index++]);

    mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(check_interval_string_id_array) / sizeof(U16), 
            (U8)(p_account_list_cntx->check_interval_value), 
            check_interval_string_id_array);

    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* check interval part end */
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

#ifdef __MMI_EMAIL_EMN__
    /* emn part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_EMN_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_EMN_SETTING_ID,
        &caption_struct[caption_index++]);

    if (SRV_EMAIL_NOTIFY_OFF == p_account_list_cntx->current_account.notify_option)
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(emn_string_id_array) / sizeof(U16), 
            0, 
            emn_string_id_array);
    }
    else
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(emn_string_id_array) / sizeof(U16), 
            1, 
            emn_string_id_array);
    }
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* emn part end */
#endif /* __MMI_EMAIL_EMN__ */

    /* download size part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_MAX_SIZE;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_DOWNLOAD_SIZE_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_DOWNLOAD_SIZE_ID,
        &caption_struct[caption_index++]);

    mmi_email_account_init_text_edit_struct(
        &text_edit_struct[text_index], 
        0, 
        0, 
        (mmi_email_util_get_num_len(MMI_EMAIL_DOWNLOAD_SIZE_MAX) + 1),
        IMM_INPUT_TYPE_NUMERIC, 
        0, 
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_DOWNLOAD_SIZE_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT,
        0,
        &text_edit_struct[text_index++]);
    /* download size part end */

    /* retrive part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_RETRIEVE_AMOUNT_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_RETRIVE_AMOUNT_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_RETRIEVE_AMOUNT_ID,
        &caption_struct[caption_index++]);

    mmi_email_account_init_text_edit_struct(
        &text_edit_struct[text_index], 
        0, 
        0, 
        (mmi_email_util_get_num_len(MMI_EMAIL_RETRIVE_AMOUNT_MAX) + 1), 
        IMM_INPUT_TYPE_NUMERIC, 
        0, 
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_RETRIVE_AMOUNT_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT,
        0,
        &text_edit_struct[text_index++]);
    /* retrive part end */

    /* reply to part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_REPLY_TO_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_REPLY_TO_ID,
        &caption_struct[caption_index++]);

    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,
        0,
        &display_only_struct[display_index++]);
    /* reply to part end */
    
    inline_struct.items_count = MMI_EMAIL_ACCOUNT_SETTING_EDIT_ITEMS_NUMBER;
    inline_struct.title = STR_EMAIL_ACCT_SETTING_ID;
    inline_struct.title_icon = email_icon;
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(p_account_list_cntx->edit_account_setting_group_id, &inline_struct);

    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_ACCOUNT_NAME_CONTENT_ID, 
        p_account_list_cntx->current_account.acct_name);

    if (SRV_EMAIL_PROT_NONE != p_account_list_cntx->current_account.protocol)
    {
        cui_inline_set_item_attributes(
            inline_id, 
            MMI_EMAIL_ACCOUNT_SETTING_EDIT_PROTOCOL_CONTENT_ID, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_DISABLE);
    }

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    if ((MMI_TRUE == conflict_dtcnt)
        #ifdef __MMI_EMAIL_EMN__
        || (SRV_EMAIL_NOTIFY_ON == p_account_list_cntx->current_account.notify_option)
        #endif /* __MMI_EMAIL_EMN__ */
        )
    {
        cui_inline_set_item_attributes(
            inline_id, 
            MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_DISABLE);
    }
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

#ifdef __MMI_EMAIL_EMN__
    if ((MMI_TRUE == conflict_dtcnt)
        #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
        || (MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_OFF != p_account_list_cntx->check_interval_value)
        #endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */ 
	   )
    {
        cui_inline_set_item_attributes(
            inline_id, 
            MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_DISABLE);
    }
#endif /* __MMI_EMAIL_EMN__ */

    {
        U32 i;
        mmi_dtcnt_acct_valid_type_enum dtcnt_valid_type;

        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            dtcnt_valid_type = mmi_dtcnt_acct_is_valid(p_account_list_cntx->current_account.in_server.data_acct[i]);
            if (dtcnt_valid_type != MMI_DTCNT_ACCT_VALID_FULL)
            {
                U32 temp_data_acct_id = 0;
                MMI_BOOL need_chg_dtct_name = MMI_FALSE;
                cbm_account_info_struct acctInfo;
                cbm_decode_data_account_id_ext(p_account_list_cntx->current_account.in_server.data_acct[i], &acctInfo);
                if (acctInfo.acct_num == 2)
                {
                    if (dtcnt_valid_type == MMI_DTCNT_ACCT_VALID_FIRST)
                    {
                        acctInfo.account[1].account_id = CBM_INVALID_NWK_ACCT_ID;
                        need_chg_dtct_name = MMI_TRUE;
                    }
                    else
                    {
                        acctInfo.account[0].account_id = CBM_INVALID_NWK_ACCT_ID;
                        need_chg_dtct_name = MMI_TRUE;
                    }
                }
                else if (acctInfo.acct_num == 1 && dtcnt_valid_type == MMI_DTCNT_ACCT_VALID_NONE)
                {
                    acctInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
                    need_chg_dtct_name = MMI_TRUE;
                }

                if (need_chg_dtct_name)
                {
                    cbm_encode_data_account_id_ext(
                        p_account_list_cntx->current_account.in_server.data_acct[i],
                        &temp_data_acct_id,
                        &acctInfo);
                    p_account_list_cntx->current_account.in_server.data_acct[i] = temp_data_acct_id;
                }
            }
        }
    }

    mmi_email_account_copy_dtcnt_id(p_account_list_cntx->edit_dataacct_id, p_account_list_cntx->current_account.in_server.data_acct);

    mmi_email_dtcnt_get_showname(p_account_list_cntx->data_account_name, p_account_list_cntx->edit_dataacct_id);
    cui_inline_set_value(inline_id, MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CONTENT_ID, p_account_list_cntx->data_account_name);

    kal_wsprintf(number_string, "%d", p_account_list_cntx->current_account.download_size);
    cui_inline_set_value(inline_id, MMI_EMAIL_ACCOUNT_SETTING_EDIT_DOWNLOAD_SIZE_CONTENT_ID, number_string);

    kal_wsprintf(number_string, "%d", p_account_list_cntx->current_account.retrieve_amount);
    cui_inline_set_value(inline_id, MMI_EMAIL_ACCOUNT_SETTING_EDIT_RETRIVE_AMOUNT_CONTENT_ID, number_string);

    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CONTENT_ID, 
        p_account_list_cntx->current_account.reply_to_addr.email_addr);
    memcpy(
        &(p_account_list_cntx->edit_reply_to_addr),
        &(p_account_list_cntx->current_account.reply_to_addr),
        sizeof(srv_email_addr_struct));

#ifdef __MMI_SSO__
    if (mmi_email_sso_is_cloud_account(mmi_email_account_list_p->current_account_id))
    {
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
#ifdef __MMI_EMAIL_EMN__
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
#endif /* __MMI_EMAIL_EMN__ */
    }
#endif /* __MMI_SSO__ */

    cui_inline_set_softkey_text(inline_id, (U16)(MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CONTENT_ID), MMI_LEFT_SOFTKEY, STR_GLOBAL_EDIT);
    cui_inline_set_softkey_icon(inline_id, (U16)(MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CONTENT_ID), MMI_LEFT_SOFTKEY, 0);
    cui_inline_set_softkey_icon(inline_id, (U16)(MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CONTENT_ID), MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);

    cui_inline_set_softkey_text(inline_id, (U16)(MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CONTENT_ID), MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
    cui_inline_set_softkey_icon(inline_id, (U16)(MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CONTENT_ID), MMI_LEFT_SOFTKEY, 0);
    cui_inline_set_softkey_icon(inline_id, (U16)(MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CONTENT_ID), MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);

    cui_inline_run(inline_id);
    p_account_list_cntx->account_setting_id = inline_id;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_ACCOUNT_SETTING_SCREEN, __LINE__);

    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_ACCOUNT_SETTING_SCREEN_END:
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_ACCOUNT_SETTING_SCREEN, __LINE__);
    if (NULL != inline_item)
    {
        OslMfree(inline_item);
        inline_item = NULL;
    }
    if (NULL != text_edit_struct)
    {
        OslMfree(text_edit_struct);
        text_edit_struct = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_account_setting_lsk
* DESCRIPTION
*  Handle the account setting submit process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_account_setting_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_info_struct *p_cuurent_account_info = NULL;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    WCHAR number_string[MMI_EMAIL_MAX_DOWNLOAD_SIZE + 1];
    WCHAR *p_popup_string = NULL;
    U8 highlight_index = 0;
    S32 count = 0;
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    mmi_email_auto_check_time_segment check_time_segment;
#endif 
    U32 boundary_number = 0;
    MMI_BOOL conflict_dtcnt = MMI_FALSE;
    mmi_email_app_core_result_enum app_core_result = MMI_EMAIL_SUCCESS;
    srv_email_acct_info_struct *p_origin_current_info = NULL;
    S32 download_size = 0;
    S32 retrieve_amount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK, __LINE__);
    p_origin_current_info = OslMalloc(sizeof(srv_email_acct_info_struct));
    p_cuurent_account_info = &(mmi_email_account_list_p->current_account);
    memcpy(p_origin_current_info, p_cuurent_account_info, sizeof(srv_email_acct_info_struct));
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_LOG1, mmi_email_account_list_p->current_account_id);

    mmi_email_account_copy_dtcnt_id(p_cuurent_account_info->in_server.data_acct, mmi_email_account_list_p->edit_dataacct_id);
    mmi_email_account_copy_dtcnt_id(p_cuurent_account_info->out_server.data_acct, mmi_email_account_list_p->edit_dataacct_id);

    conflict_dtcnt = mmi_email_dtcnt_is_any_conflict(p_cuurent_account_info->in_server.data_acct);

    /* account name begin */
    cui_inline_get_value(
        mmi_email_account_list_p->account_setting_id, 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_ACCOUNT_NAME_CONTENT_ID, 
        p_cuurent_account_info->acct_name);
    if (0 == mmi_wcslen(p_cuurent_account_info->acct_name))
    {
        mmi_email_lib_error_popup(STR_EMAIL_ACCT_NAME_EMPTY_ID);
        mmi_wcsncpy(p_cuurent_account_info->acct_name, p_origin_current_info->acct_name, SRV_EMAIL_MAX_ACCT_NAME_LEN);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
    }
    if (0 != mmi_wcscmp(
                (const WCHAR*)p_cuurent_account_info->acct_name, 
                (const WCHAR*)p_origin_current_info->acct_name))
    {
        memset(p_cuurent_account_info->provurl_hash, 0 ,sizeof(p_cuurent_account_info->provurl_hash));
        memset(p_cuurent_account_info->napid_hash, 0 ,sizeof(p_cuurent_account_info->napid_hash));   
    }
    /* account name end */

    /* download size begin */
    cui_inline_get_value(
        mmi_email_account_list_p->account_setting_id, 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_DOWNLOAD_SIZE_CONTENT_ID, 
        number_string);
    if (0 == mmi_wcslen(number_string))
    {
        mmi_email_lib_error_popup(STR_EMAIL_DOWNLOAD_SIZE_EMPTY_ID);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
    }
    download_size = gui_atoi(number_string);
    if ((download_size < MMI_EMAIL_DOWNLOAD_SIZE_MIN) || (download_size > MMI_EMAIL_DOWNLOAD_SIZE_MAX))
    {
        p_popup_string = OslMalloc((MMI_EMAIL_DOWNLOAD_SIZE_ERROR_STRING_LEN + 1) * sizeof(WCHAR));
        if (download_size < MMI_EMAIL_DOWNLOAD_SIZE_MIN)
        {
            boundary_number = (U32)MMI_EMAIL_DOWNLOAD_SIZE_MIN;
            kal_wsprintf(p_popup_string, "%w\n < %u", GetString(STR_EMAIL_MAX_SIZE), boundary_number);    
        }
        else
        {
            boundary_number = MMI_EMAIL_DOWNLOAD_SIZE_MAX;
            kal_wsprintf(p_popup_string, "%w\n > %u", GetString(STR_EMAIL_MAX_SIZE), boundary_number);
        }
        mmi_popup_display_simple(
            p_popup_string, 
            MMI_EVENT_FAILURE, 
            mmi_email_account_list_p->edit_account_setting_group_id, 
            0);
        OslMfree(p_popup_string);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
    }
    else
    {
        p_cuurent_account_info->download_size = download_size;
    }
    /* download size end */

    /* retrive part begin */
    cui_inline_get_value(
        mmi_email_account_list_p->account_setting_id, 
        MMI_EMAIL_ACCOUNT_SETTING_EDIT_RETRIVE_AMOUNT_CONTENT_ID, 
        number_string);
    if (0 == mmi_wcslen(number_string))
    {
        mmi_email_lib_error_popup(STR_EMAIL_MAIL_RETRIVE_EMPTY_ID);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
    }
    retrieve_amount = gui_atoi(number_string);
    if ((retrieve_amount < 1) || (retrieve_amount > MMI_EMAIL_RETRIVE_AMOUNT_MAX))
    {
        p_popup_string = OslMalloc((MMI_EMAIL_DOWNLOAD_SIZE_ERROR_STRING_LEN + 1) * sizeof(WCHAR));
        if (retrieve_amount < 1)
        {
            boundary_number = 1;
            kal_wsprintf(p_popup_string, "%w\n < %u", GetString(STR_EMAIL_RETRIEVE_AMOUNT_ID), boundary_number);    
        }
        else
        {
            boundary_number = MMI_EMAIL_RETRIVE_AMOUNT_MAX;
            kal_wsprintf(p_popup_string, "%w\n > %u", GetString(STR_EMAIL_RETRIEVE_AMOUNT_ID), boundary_number);
        }
        mmi_popup_display_simple(
            p_popup_string, 
            MMI_EVENT_FAILURE, 
            mmi_email_account_list_p->edit_account_setting_group_id, 
            0);
        OslMfree(p_popup_string);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
    }
    else
    {
        p_cuurent_account_info->retrieve_amount = retrieve_amount;
    }
    /* retrive part end */
    
    /* reply-to part begin */

    if ((0 != mmi_wcslen((const WCHAR*)mmi_email_account_list_p->edit_reply_to_addr.email_addr)) &&
        (!mmi_email_util_chk_addr(mmi_email_account_list_p->edit_reply_to_addr.email_addr)))
    {
        mmi_email_lib_error_popup(STR_GLOBAL_INVALID_EMAIL_ADDRESS);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
    }
    else
    {
        memcpy(
            &(p_cuurent_account_info->reply_to_addr),
            &(mmi_email_account_list_p->edit_reply_to_addr),
            sizeof(srv_email_addr_struct));
    }
    /* reply-to part end */

    /* Save account info */
    {
        /* get protocol value part begin */
        cui_inline_get_value(
            mmi_email_account_list_p->account_setting_id, 
            MMI_EMAIL_ACCOUNT_SETTING_EDIT_PROTOCOL_CONTENT_ID, 
            &highlight_index);
        if (0 == highlight_index)
        {
            p_cuurent_account_info->protocol = SRV_EMAIL_PROT_POP3;
        }
        else
        {
            p_cuurent_account_info->protocol = SRV_EMAIL_PROT_IMAP4;
        }
        /* get protocol value part end */

        /* get check interval value part begin */
    #ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
        cui_inline_get_value(
            mmi_email_account_list_p->account_setting_id, 
            MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID, 
            &highlight_index);
        if (0 == highlight_index)
        {
            for (count = MMI_EMAIL_CHECK_INTERVAL_DAY_BEGIN; count <= MMI_EMAIL_CHECK_INTERVAL_DAY_END; count++)
            {
                app_core_result = mmi_email_auto_check_set_day_enable(
                                    mmi_email_account_list_p->current_account_id, 
                                    (U16)count, 
                                    MMI_FALSE);
                if (MMI_EMAIL_SUCCESS != app_core_result)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_LOG2, app_core_result);
                    mmi_email_display_app_core_popup(
                        mmi_email_account_list_p->edit_account_setting_group_id, 
                        app_core_result);
                    cui_inline_close(mmi_email_account_list_p->account_setting_id);
                    mmi_email_account_list_p->account_setting_id = GRP_ID_INVALID;
                    memcpy(p_cuurent_account_info, p_origin_current_info, sizeof(srv_email_acct_info_struct));
                    goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
                }
            }
            app_core_result = mmi_email_auto_check_stop(mmi_email_account_list_p->current_account_id);
            if (MMI_EMAIL_SUCCESS != app_core_result)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_LOG5, app_core_result);
                mmi_email_display_app_core_popup(
                    mmi_email_account_list_p->edit_account_setting_group_id, 
                    app_core_result);
                cui_inline_close(mmi_email_account_list_p->account_setting_id);
                mmi_email_account_list_p->account_setting_id = GRP_ID_INVALID;
                memcpy(p_cuurent_account_info, p_origin_current_info, sizeof(srv_email_acct_info_struct));
                goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;   
            }

        }
        else
        {
            if (conflict_dtcnt)
            {
                mmi_email_lib_infor_popup(STR_EMAIL_CHK_RESET_ID);
                goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
            }
            check_time_segment.start_time = MMI_EMAIL_CHECK_INTERVAL_DAY_START_TIME;
            check_time_segment.stop_time = MMI_EMAIL_CHECK_INTERVAL_DAY_END_TIME;
            if (1 == highlight_index)
            {
                check_time_segment.interval = MMI_EMAIL_CHECK_INTERVAL_5_MIN_TIME;
            }
            else if (2 == highlight_index)
            {
                check_time_segment.interval = MMI_EMAIL_CHECK_INTERVAL_30_MIN_TIME;
            }
            else if (3 == highlight_index)
            {
                check_time_segment.interval = MMI_EMAIL_CHECK_INTERVAL_1_HOUR_TIME;
            }
            else
            {
                check_time_segment.interval = MMI_EMAIL_CHECK_INTERVAL_2_HOUR_TIME;
            }
            for (count = MMI_EMAIL_CHECK_INTERVAL_DAY_BEGIN; count <= MMI_EMAIL_CHECK_INTERVAL_DAY_END; count++)
            {
                app_core_result = mmi_email_auto_check_set_day_enable(
                                    mmi_email_account_list_p->current_account_id, 
                                    (U16)count, 
                                    MMI_TRUE);
                if (MMI_EMAIL_SUCCESS != app_core_result)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_LOG3, app_core_result);
                    mmi_email_display_app_core_popup(
                        mmi_email_account_list_p->edit_account_setting_group_id, 
                        app_core_result);
                    cui_inline_close(mmi_email_account_list_p->account_setting_id);
                    mmi_email_account_list_p->account_setting_id = GRP_ID_INVALID;
                    memcpy(p_cuurent_account_info, p_origin_current_info, sizeof(srv_email_acct_info_struct));
                    goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
                }
                app_core_result = mmi_email_auto_check_edit_segment(
                                            mmi_email_account_list_p->current_account_id, 
                                            (U16)count, 
                                            0, 
                                            &check_time_segment);
                if (MMI_EMAIL_SUCCESS != app_core_result)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_LOG4, app_core_result);
                    mmi_email_display_app_core_popup(
                        mmi_email_account_list_p->edit_account_setting_group_id, 
                        app_core_result);
                    cui_inline_close(mmi_email_account_list_p->account_setting_id);
                    mmi_email_account_list_p->account_setting_id = GRP_ID_INVALID;
                    memcpy(p_cuurent_account_info, p_origin_current_info, sizeof(srv_email_acct_info_struct));
                    goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
                }
            }
            app_core_result = mmi_email_auto_check_start(mmi_email_account_list_p->current_account_id);
            if (MMI_EMAIL_SUCCESS != app_core_result)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_LOG6, app_core_result);
                mmi_email_display_app_core_popup(
                    mmi_email_account_list_p->edit_account_setting_group_id, 
                    app_core_result);
                cui_inline_close(mmi_email_account_list_p->account_setting_id);
                mmi_email_account_list_p->account_setting_id = GRP_ID_INVALID;
                memcpy(p_cuurent_account_info, p_origin_current_info, sizeof(srv_email_acct_info_struct));
                goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;   
            }

        }
    #endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
        /* get check interval value part end */

        /* get emn value part begin*/
    #ifdef __MMI_EMAIL_EMN__
        cui_inline_get_value(
            mmi_email_account_list_p->account_setting_id, 
            MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID, 
            &highlight_index);
        if (0 == highlight_index)
        {
            p_cuurent_account_info->notify_option = SRV_EMAIL_NOTIFY_OFF;
        }
        else
        {
            if (conflict_dtcnt)
            {
                mmi_email_lib_infor_popup(STR_EMAIL_EMN_RESET_ID);
                goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
            }
            p_cuurent_account_info->notify_option = SRV_EMAIL_NOTIFY_ON;
        }
    #endif /* __MMI_EMAIL_EMN__ */
        /* get emn value part end*/

        srv_op_result = mmi_email_entry_edit_account_save_account_info(
                            mmi_email_account_list_p->srv_handle, 
                            &(mmi_email_account_list_p->current_account_handle), 
                            mmi_email_account_list_p->current_account_id, 
                            p_cuurent_account_info);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            mmi_email_util_display_error_popup(
                mmi_email_account_list_p->edit_account_setting_group_id, 
                srv_op_result);
            cui_inline_close(mmi_email_account_list_p->account_setting_id);
            mmi_email_account_list_p->account_setting_id = GRP_ID_INVALID;
            memcpy(p_cuurent_account_info, p_origin_current_info, sizeof(srv_email_acct_info_struct));
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END;
        }

#ifdef __MMI_EMAIL_IMAP_PUSH__
        if (conflict_dtcnt && mmi_email_account_list_p->current_account_id == email_mmi_account_data_get_push())
        {
            mmi_email_lib_infor_popup(STR_EMAIL_PSH_RESET_ID);

            mmi_email_app_network_push_stop(FALSE);
            email_mmi_account_data_set_push(EMAIL_ACCT_INVALID_ID);
        }
#endif /* __IMAP_PUSH__ */


        cui_inline_close(mmi_email_account_list_p->account_setting_id);
        mmi_email_account_list_p->account_setting_id = GRP_ID_INVALID;
    }

MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK_END:
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_SETTING_LSK, __LINE__);
    if (NULL != p_origin_current_info)
    {
        OslMfree(p_origin_current_info);
        p_origin_current_info = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_account_setting_rsk
* DESCRIPTION
*  Handle the account setting submit process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_account_setting_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(mmi_email_account_list_p->account_setting_id);
    mmi_email_account_list_p->account_setting_id = GRP_ID_INVALID;
    mmi_frm_scrn_close_active_id();
    return;
}

/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_main_account_setting_lsk
* DESCRIPTION
*  Handle the account setting submit process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_main_account_setting_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_info_struct *p_cuurent_account_info = NULL;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    WCHAR *orig_email_addr;
    WCHAR *orig_acct_name;
    MMI_BOOL is_cloud = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_MAIN_ACCOUNT_SETTING_LSK, __LINE__);


    p_cuurent_account_info = &(mmi_email_account_list_p->current_account);
    
#ifdef __MMI_SSO__
    is_cloud = mmi_email_sso_is_cloud_account(mmi_email_account_list_p->current_account_id);
#endif /* __MMI_SSO__ */

    orig_email_addr = OslMalloc(sizeof(WCHAR) * (SRV_EMAIL_MAX_ADDR_LEN + 1));
    mmi_wcscpy(orig_email_addr, p_cuurent_account_info->email_addr.email_addr);

    orig_acct_name = OslMalloc(sizeof(WCHAR) * (SRV_EMAIL_MAX_ACCT_NAME_LEN + 1));
    mmi_wcscpy(orig_acct_name, p_cuurent_account_info->acct_name);
    
    cui_inline_get_value(mmi_email_account_list_p->account_main_setting_id, MMI_EMAIL_ACCOUNT_EDIT_EMAIL_ADDRESS_CONTENT_ID, p_cuurent_account_info->email_addr.email_addr);
    if (mmi_ucs2strlen((CHAR*)(p_cuurent_account_info->email_addr.email_addr)) == 0 && !is_cloud)
    {
        mmi_email_lib_error_popup(STR_EMAIL_EMAIL_ADDRESS_EMPTY);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
    }
    else if (!mmi_email_util_chk_addr((p_cuurent_account_info->email_addr.email_addr)) && !is_cloud)
    {
        mmi_email_lib_error_popup(STR_GLOBAL_INVALID_EMAIL_ADDRESS);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
    }
    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_MAIN_ACCOUNT_SETTING_LSK, __LINE__);
    // if user changed Email Adress here, the account name should be changed too ...
    if (mmi_wcscmp(p_cuurent_account_info->email_addr.email_addr, orig_email_addr) != 0)
    {
        // if user has not custom the account name, change it to new Email address
        U32 orig_email_addr_len = mmi_wcslen(orig_email_addr);
        U32 orig_acct_name_len = mmi_wcslen(orig_acct_name);
        MMI_BOOL is_custom = MMI_TRUE;
        if (orig_email_addr_len == orig_acct_name_len ||
            (orig_email_addr_len > orig_acct_name_len && orig_acct_name_len == SRV_EMAIL_MAX_ACCT_NAME_LEN))
        {
            if (mmi_wcsncmp(orig_email_addr, orig_acct_name, orig_acct_name_len) == 0)
            {
                is_custom = MMI_FALSE;
            }
        }
        else if (orig_email_addr_len == orig_acct_name_len - 3)
        {
            if (mmi_wcsncmp(orig_email_addr, orig_acct_name, orig_email_addr_len) == 0)
            {
                if (orig_acct_name[orig_email_addr_len] == L'(' &&
                    orig_acct_name[orig_email_addr_len + 1] >= L'1' &&
                    orig_acct_name[orig_email_addr_len + 1] <= L'9' &&
                    orig_acct_name[orig_email_addr_len + 2] == L')')
                {
                    is_custom = MMI_FALSE;
                }
            }
        }

        if (!is_custom)
        {
            mmi_wcsncpy(p_cuurent_account_info->acct_name,
                p_cuurent_account_info->email_addr.email_addr, SRV_EMAIL_MAX_ACCT_NAME_LEN);
            mmi_email_wizard_get_default_acct_name(mmi_email_account_list_p);
        }
    }

    if (orig_email_addr != NULL)
    {
        OslMfree(orig_email_addr);
        orig_email_addr = NULL;
    }
    
    if (orig_acct_name != NULL)
    {
        OslMfree(orig_acct_name);
        orig_acct_name = NULL;
    }
    

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_MAIN_ACCOUNT_SETTING_LSK, __LINE__);
    /* Username */ /* From Incoming */
    cui_inline_get_value(mmi_email_account_list_p->account_main_setting_id, MMI_EMAIL_ACCOUNT_EDIT_USER_NAME_CONTENT_ID, p_cuurent_account_info->in_auth.username);
    if ((mmi_ucs2strlen((CHAR*)(p_cuurent_account_info->in_auth.username))) == 0  && !is_cloud)
    {
        mmi_email_lib_error_popup(STR_EMAIL_USER_NAME_EMPTY_ID);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
    }
    else if (!mmi_email_util_is_username_vaild((CHAR*)(p_cuurent_account_info->in_auth.username))  && !is_cloud) /* Username is empty  */
    {
        mmi_email_lib_error_popup(STR_EMAIL_WRONG_USERNAME);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_MAIN_ACCOUNT_SETTING_LSK, __LINE__);
    /* Outgoing Server */ /* From Outgoing */
    cui_inline_get_value(mmi_email_account_list_p->account_main_setting_id, MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CONTENT_ID, p_cuurent_account_info->out_server.server_name);
    if (!mmi_email_util_is_server_vaild((CHAR*)(p_cuurent_account_info->out_server.server_name)) && !is_cloud)
    {
        mmi_email_lib_error_popup(STR_EMAIL_ERROR_CODE_INVALID_IP_ADDR_ID);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
    }
    else if (mmi_ucs2strlen((CHAR*)(p_cuurent_account_info->out_server.server_name)) == 0 && !is_cloud)
    {
        mmi_email_lib_error_popup(STR_EMAIL_SERVER_EMPTY_ID);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
    }
    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_MAIN_ACCOUNT_SETTING_LSK, __LINE__);
    /* Incoming Server */ /* From Incoming */
    cui_inline_get_value(mmi_email_account_list_p->account_main_setting_id, MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CONTENT_ID, p_cuurent_account_info->in_server.server_name);
    if (!mmi_email_util_is_server_vaild((CHAR*)(p_cuurent_account_info->in_server.server_name)) && !is_cloud)
    {
        mmi_email_lib_error_popup(STR_EMAIL_ERROR_CODE_INVALID_IP_ADDR_ID);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
    }
    else if (mmi_ucs2strlen((CHAR*)(p_cuurent_account_info->in_server.server_name)) == 0 && !is_cloud)
    {
        mmi_email_lib_error_popup(STR_EMAIL_SERVER_EMPTY_ID);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_MAIN_ACCOUNT_SETTING_LSK, __LINE__);
    /* Save account info */
    {
        cui_inline_get_value(mmi_email_account_list_p->account_main_setting_id, MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_NAME_CONTENT_ID, p_cuurent_account_info->email_addr.disp_name);
        cui_inline_get_value(mmi_email_account_list_p->account_main_setting_id, MMI_EMAIL_ACCOUNT_EDIT_PASSWORD_CONTENT_ID, p_cuurent_account_info->in_auth.password);
        srv_op_result = mmi_email_entry_edit_account_save_account_info(
                            mmi_email_account_list_p->srv_handle, 
                            &(mmi_email_account_list_p->current_account_handle), 
                            mmi_email_account_list_p->current_account_id, 
                            p_cuurent_account_info);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            mmi_email_util_display_error_popup(mmi_email_account_list_p->edit_account_main_setting_group_id, srv_op_result);
            cui_inline_close(mmi_email_account_list_p->account_main_setting_id);
            mmi_email_account_list_p->account_main_setting_id = GRP_ID_INVALID;

            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END;
        }

        //mmi_email_lib_succ_popup(STR_GLOBAL_SAVED);
        cui_inline_close(mmi_email_account_list_p->account_main_setting_id);
        mmi_email_account_list_p->account_main_setting_id = GRP_ID_INVALID;
    }
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SUBMIT_ACCOUNT_SETTING_END:
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_MAIN_ACCOUNT_SETTING_LSK, __LINE__);
    if (orig_email_addr != NULL)
    {
        OslMfree(orig_email_addr);
    }
    
    if (orig_acct_name != NULL)
    {
        OslMfree(orig_acct_name);
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_main_account_setting_rsk
* DESCRIPTION
*  Do not save account setting
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_main_account_setting_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
    cui_inline_close(mmi_email_account_list_p->account_main_setting_id);
    mmi_email_account_list_p->account_main_setting_id = GRP_ID_INVALID;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_outgoing_server_process
* DESCRIPTION
*  Entry editing outgoing server process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_outgoing_server_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_OUTGOING_SERVER_PROCESS, __LINE__);

    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_OUTGOING_SERVER;
    p_account_list_cntx->edit_account_outgoing_server_group_id = mmi_frm_group_create(
                                                                    p_account_list_cntx->edit_account_group_id, 
                                                                    GRP_ID_AUTO_GEN, 
                                                                    mmi_email_entry_edit_account_entry_outgoing_server_proc, 
                                                                    p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->edit_account_outgoing_server_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    p_account_list_cntx->p_outgoing_server_auth = OslMalloc(sizeof(srv_email_auth_struct));
    memcpy(
        p_account_list_cntx->p_outgoing_server_auth, 
        &(p_account_list_cntx->current_account.out_auth),
        sizeof(srv_email_auth_struct));
    mmi_email_entry_edit_account_entry_outgoing_server_screen(p_account_list_cntx);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_outgoing_server_proc
* DESCRIPTION
*  The procedure function of edit_account_outgoing_server_group_id
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_entry_outgoing_server_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->evt_id)
    {
    case EVT_ID_CUI_INLINE_NOTIFY:
        mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_notify_message((cui_event_inline_notify_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_submit_message((cui_event_inline_submit_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_abort_message((cui_event_inline_abort_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_deinit_message((cui_event_inline_common_struct*)p_event);
        break;

    case EVT_ID_GROUP_FOCUSED:
        mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->edit_account_outgoing_server_group_id);
        break;

    case EVT_ID_ALERT_QUIT:
        mmi_email_entry_edit_account_outgoing_server_proc_handle_alert_quit_message((mmi_alert_result_evt_struct*)p_event);
        break;

    case EVT_ID_GROUP_DEINIT:
        mmi_email_entry_edit_account_outgoing_server_proc_handle_group_deinit_message((mmi_event_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_SET_KEY:
        mmi_email_entry_edit_account_outgoing_server_proc_handle_setkey((cui_event_inline_set_key_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        mmi_email_entry_edit_account_outgoing_auth_menu_select((cui_menu_event_struct*)p_event);
        //mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_select_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_email_entry_edit_account_outgoing_auth_menu_close((cui_menu_event_struct*)p_event);
        //mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_close_message((cui_menu_event_struct*)p_event);
        break;

    default:
        break;
    }
    return MMI_RET_OK;
}


static void set_outgoing_auth_key(void)
{
    S32 select_value = 0;

    cui_inline_get_value(
        mmi_email_account_list_p->account_outgoing_server_id, 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID, 
        &select_value);
    if (select_value == 0)
    {
        // LSK: SAVE
        // CSK: SAVE
        set_softkey_label((UI_string_type)GetString(STR_GLOBAL_SAVE), MMI_LEFT_SOFTKEY);
        SetLeftSoftkeyFunction(mmi_email_entry_edit_account_save_outgoing_server, KEY_EVENT_UP);

        cui_inline_set_softkey_icon(mmi_email_account_list_p->account_outgoing_server_id, 
            (U16)(MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID), 
            MMI_CENTER_SOFTKEY, 
            IMG_GLOBAL_COMMON_CSK);
        //SetCenterSoftkeyFunction(mmi_email_entry_edit_account_save_outgoing_server, KEY_EVENT_UP);
    }
    else
    {
        // LSK: Option (Edit, Save)
        // CSK: Edit
        set_softkey_label((UI_string_type)GetString(STR_GLOBAL_OPTIONS), MMI_LEFT_SOFTKEY);
        SetLeftSoftkeyFunction(mmi_email_entry_edit_account_outgoing_auth_opt, KEY_EVENT_UP);

        cui_inline_set_softkey_icon(mmi_email_account_list_p->account_outgoing_server_id, 
            (U16)(MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID), 
            MMI_CENTER_SOFTKEY, 
            IMG_GLOBAL_COMMON_CSK);
        //SetCenterSoftkeyFunction(mmi_email_entry_edit_account_save_outgoing_server, KEY_EVENT_UP);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_notify_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_NOTIFY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_NOTIFY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_notify_message(cui_event_inline_notify_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->event_type)
    {
    case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:

#ifdef __SSL_SUPPORT__
        if (MMI_EMAIL_OUTGOING_SERVER_EDIT_SECURITY_CONTENT_ID == p_event->item_id)
        {
            mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
            WCHAR port_string[MMI_EMAIL_MAX_PORT_NUMBER + 1];
            U16 port_num = 0;
            U16 sec_port_num = 0;

            p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
            if (1 == p_event->param)
            {
                if (0 == p_account_list_cntx->current_account.out_server.sec_port_num)
                {
                    sec_port_num = MMI_EMAIL_SMTP_SECURITY_PORT_NUMBER;
                }
                else
                {
                    sec_port_num = p_account_list_cntx->current_account.out_server.sec_port_num;
                }
                kal_wsprintf(port_string, "%d", sec_port_num);
            }
            else
            {
                if (0 == p_account_list_cntx->current_account.out_server.port_num)
                {
                    port_num = MMI_EMAIL_SMTP_PORT_NUMBER;
                }
                else
                {
                    port_num = p_account_list_cntx->current_account.out_server.port_num;
                }
                kal_wsprintf(port_string, "%d", port_num);
            }
            cui_inline_set_value(p_event->sender_id, MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CONTENT_ID, port_string);
        }
#endif /* __SSL_SUPPORT__ */

        if (MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID == p_event->item_id)
        {
            set_outgoing_auth_key();
            redraw_softkey(MMI_LEFT_SOFTKEY);
        }
        break;

        case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
            if (p_event->item_id == MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID)
            {
                set_outgoing_auth_key();
            }
            break;

    default:
        break;
    }
}

static void mmi_email_entry_edit_account_outgoing_server_proc_handle_setkey(cui_event_inline_set_key_struct *p_event)
{
    switch (p_event->item_id)
    {
    case MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID:
        set_outgoing_auth_key();
        break;

    default:
        break;
    }
}


static void mmi_email_entry_edit_account_outgoing_auth_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = cui_menu_create(
        mmi_email_account_list_p->edit_account_outgoing_server_group_id, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_OPTION, 
        MENU_ID_EMAIL_OUT_AUTH_OPT, 
        MMI_FALSE, 
        mmi_email_account_list_p);
    cui_menu_set_default_title(id, NULL, get_image(GetRootTitleIcon(MENU_ID_EMAIL_MAIN)));
    cui_menu_run(id);
}


static void mmi_email_entry_edit_account_outgoing_auth_menu_select(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->highlighted_menu_id)
    {
    case MENU_ID_EMAIL_OUT_AUTH_EDIT:
        mmi_email_entry_edit_account_entry_outgoing_server_auth_process();
        break;

    case MENU_ID_EMAIL_OUT_AUTH_SAVE:
        mmi_email_entry_edit_account_save_outgoing_server();
        break;

    default:
        break;
    }
}

static void mmi_email_entry_edit_account_outgoing_auth_menu_close(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(p_event->sender_id);
}


static void mmi_email_entry_edit_account_save_outgoing_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = mmi_email_account_list_p->edit_account_outgoing_server_group_id;
    confirm_struct.user_tag = (void*)MMI_EMAIL_ACCOUNT_ALERT_SAVE_OUTGOING_SERVER;
    mmi_confirm_display((WCHAR*)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &confirm_struct);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_submit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SUBMIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SUBMIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_submit_message(cui_event_inline_submit_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    srv_email_acct_info_struct *p_cuurent_account_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    p_cuurent_account_info = &(p_account_list_cntx->current_account);

    if ((p_event->item_id >= MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_USERNAME_CAPTION_ID) &&
        (p_event->item_id <= MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_PASSWORD_CONTENT_ID))
    {
        cui_inline_get_value(
            p_event->sender_id, 
            MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_USERNAME_CONTENT_ID, 
            p_account_list_cntx->p_outgoing_server_auth->username);
        if (!mmi_email_util_is_username_vaild((CHAR*)p_cuurent_account_info->out_auth.username))
        {
            mmi_email_lib_error_popup(STR_EMAIL_WRONG_USERNAME);
        }
        else
        {
            cui_inline_get_value(
                p_event->sender_id, 
                MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_PASSWORD_CONTENT_ID, 
                p_account_list_cntx->p_outgoing_server_auth->password);
            cui_inline_set_screen_attributes(
                p_account_list_cntx->account_outgoing_server_id, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
            cui_inline_close(p_event->sender_id);
        }
    }
    else if (p_event->item_id == MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID)
    {
        S32 select_value = 0;

        cui_inline_get_value(
            mmi_email_account_list_p->account_outgoing_server_id, 
            MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID, 
            &select_value);
        if (select_value == 0)
        {
            mmi_email_entry_edit_account_save_outgoing_server();
        }
        else
        {
            mmi_email_entry_edit_account_entry_outgoing_server_auth_process();
        }
    }
    else
    {
        mmi_email_entry_edit_account_save_outgoing_server();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_abort_message(cui_event_inline_abort_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_deinit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_GROUP_DEINIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_GROUP_DEINIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_inline_deinit_message(cui_event_inline_common_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_outgoing_server_proc_handle_group_deinit_message
* DESCRIPTION
*  The handle function of EVT_ID_GROUP_DEINIT
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_group_deinit_message(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_event->user_data;
    if (NULL != p_account_list_cntx->p_outgoing_server_auth)
    {
        OslMfree(p_account_list_cntx->p_outgoing_server_auth);
        p_account_list_cntx->p_outgoing_server_auth = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_outgoing_server_proc_handle_alert_quit_message
* DESCRIPTION
*  The handle function of EVT_ID_ALERT_QUIT
* PARAMETERS
*  p_event   [IN] EVT_ID_ALERT_QUIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_outgoing_server_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
        case MMI_EMAIL_ACCOUNT_ALERT_SAVE_OUTGOING_SERVER:
        {
            if (MMI_ALERT_CNFM_YES == p_event->result)
            {
                mmi_email_entry_edit_account_save_outgoing_server_lsk();
            }
            else if (MMI_ALERT_CNFM_NO == p_event->result)
            {
                mmi_email_entry_edit_account_save_outgoing_server_rsk();
            }
        }
        default:
        {
            break;
        }
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_outgoing_server_screen
* DESCRIPTION
*  Entry editing outgoing server screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_outgoing_server_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct;
    
    cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};
#ifdef __SSL_SUPPORT__
    U16 security_string_id_array[] = {STR_GLOBAL_OFF, STR_EMAIL_USING_SSL_ID, STR_EMAIL_USING_TLS_ID};
#endif /* __SSL_SUPPORT__ */
    U16 authenticate_string_id_array[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
    U16 save_mail_string_id_array[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
    
    cui_inline_set_item_struct *inline_item = NULL;
    cui_inline_item_caption_struct caption_struct[MMI_EMAIL_OUTGOING_SERVER_EDIT_CAPTION_ITEMS_NUMBER];
    cui_inline_item_select_struct select_struct[MMI_EMAIL_OUTGOING_SERVER_EDIT_SELECT_ITEMS_NUMBER];
    cui_inline_item_text_edit_struct text_edit_struct[MMI_EMAIL_OUTGOING_SERVER_EDIT_TEXT_ITEMS_NUMBER];

    S32 inline_item_index = 0;
    S32 caption_index = 0;
    S32 select_index = 0;
    S32 text_index = 0;
    
    U16 email_icon = 0;
    mmi_id inline_id = GRP_ID_INVALID;
    WCHAR port_string[MMI_EMAIL_MAX_PORT_NUMBER + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_OUTGOING_SERVER_SCREEN, __LINE__);

    inline_item = OslMalloc(sizeof(cui_inline_set_item_struct) * MMI_EMAIL_OUTGOING_SERVER_EDIT_ITEMS_NUMBER);
    
    email_icon = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);

    /* port part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_OUTGOING_PORT_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_OUTGOING_PORT_ID,
        &caption_struct[caption_index++]);

    mmi_email_account_init_text_edit_struct(
        &text_edit_struct[text_index], 
        0, 
        0, 
        (MMI_EMAIL_MAX_PORT_NUMBER + 1),
        IMM_INPUT_TYPE_NUMERIC, 
        0, 
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT,
        0,
        &text_edit_struct[text_index++]);
    /* port part end */

#ifdef __SSL_SUPPORT__
    /* security part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_SECURITY_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_SECURITY_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_SECURITY_ID,
        &caption_struct[caption_index++]);

    if (SRV_EMAIL_SEC_NONE == p_account_list_cntx->current_account.out_server.sec_mode)
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(security_string_id_array) / sizeof(U16), 
            0, 
            security_string_id_array);
    }
    else if (SRV_EMAIL_SEC_SSL_TLS == p_account_list_cntx->current_account.out_server.sec_mode)
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(security_string_id_array) / sizeof(U16), 
            1, 
            security_string_id_array);
    }
    else
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(security_string_id_array) / sizeof(U16), 
            2, 
            security_string_id_array);
    }
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_SECURITY_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* security part end */
#endif /* __SSL_SUPPORT__ */
    
    /* authentication part begin */
    caption_struct[caption_index].string_id = STR_GLOBAL_AUTHENTICATION;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_AUTH_ID,
        &caption_struct[caption_index++]);

    if (SRV_EMAIL_AUTH_NONE == p_account_list_cntx->current_account.out_auth.auth_type)
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(authenticate_string_id_array) / sizeof(U16), 
            0, 
            authenticate_string_id_array);
    }
    else
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(authenticate_string_id_array) / sizeof(U16), 
            1, 
            authenticate_string_id_array);
    }
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* authentication part end */

    /* save mail part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_SAVE_SENT_EMAILS_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_SAVE_SENT_MAILS_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_AUTH_ID,
        &caption_struct[caption_index++]);

    if (MMI_FALSE == p_account_list_cntx->current_account_extra_info.save_sent_emails)
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(save_mail_string_id_array) / sizeof(U16), 
            0, 
            save_mail_string_id_array);
    }
    else
    {
        mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(save_mail_string_id_array) / sizeof(U16), 
            1, 
            save_mail_string_id_array);
    }
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_SAVE_SENT_MAILS_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* authentication part end */

    inline_struct.items_count = MMI_EMAIL_OUTGOING_SERVER_EDIT_ITEMS_NUMBER;
    inline_struct.title = STR_EMAIL_SMTP_SETTING_ID;
    inline_struct.title_icon = email_icon;
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(p_account_list_cntx->edit_account_outgoing_server_group_id, &inline_struct);

#ifdef __SSL_SUPPORT__
    if (SRV_EMAIL_SEC_SSL_TLS == p_account_list_cntx->current_account.out_server.sec_mode)
    {
        kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.out_server.sec_port_num);
    }
    else
    {
        kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.out_server.port_num);
    }
#else /* __SSL_SUPPORT__ */
    kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.out_server.port_num);
#endif /* __SSL_SUPPORT__ */
    cui_inline_set_value(inline_id, MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CONTENT_ID, port_string);


#ifdef __MMI_SSO__
    if (mmi_email_sso_is_cloud_account(mmi_email_account_list_p->current_account_id))
    {
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
#ifdef __SSL_SUPPORT__
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_OUTGOING_SERVER_EDIT_SECURITY_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
#endif /* __SSL_SUPPORT__ */
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
    }
#endif /* __MMI_SSO__ */


    cui_inline_run(inline_id);

    p_account_list_cntx->account_outgoing_server_id = inline_id;

    if (NULL != inline_item)
    {
        OslMfree(inline_item);
        inline_item = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_outgoing_server_auth_process
* DESCRIPTION
*  Entry editing outgoing server auth process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_outgoing_server_auth_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_entry_edit_account_entry_outgoing_server_auth_screen(mmi_email_account_list_p);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_outgoing_server_auth_screen
* DESCRIPTION
*  Entry editing outgoing server auth screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_outgoing_server_auth_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct;
    
    cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};

    cui_inline_set_item_struct *inline_item = NULL;
    cui_inline_item_caption_struct caption_struct[MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_CAPTION_ITEMS_NUMBER];
    cui_inline_item_fullscreen_edit_struct fullscreen_edit_struct[MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_FULL_SCREEN_ITEMS_NUMBER];

    S32 inline_item_index = 0;
    S32 caption_index = 0;
    S32 fullscreen_index = 0;

    U16 email_icon = 0;
    mmi_id inline_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_OUTGOING_SERVER_AUTH_SCREEN, __LINE__);

    inline_item = OslMalloc(sizeof(MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_ITEMS_NUMBER) * sizeof(cui_inline_set_item_struct));

    email_icon = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);

    /* user name part begin */
    caption_struct[caption_index].string_id = STR_GLOBAL_USERNAME;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_USERNAME_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_USER_NAME_ID,
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_GLOBAL_USERNAME, 
        email_icon, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, 
        IMM_INPUT_TYPE_ASCII_CHAR, 
        (SRV_EMAIL_MAX_USERNAME_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_USERNAME_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT,
        0,
        &fullscreen_edit_struct[fullscreen_index++]);
    /* user name part end */

    /* password part begin */
    caption_struct[caption_index].string_id = STR_GLOBAL_PASSWORD;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_PASSWORD_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_PASSWORD_ID,
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_GLOBAL_PASSWORD, 
        email_icon, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, 
        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 
        (SRV_EMAIL_MAX_PASSWORD_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_PASSWORD_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT,
        0,
        &fullscreen_edit_struct[fullscreen_index++]);
    /* password part end */

    inline_struct.items_count = MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_ITEMS_NUMBER;
    inline_struct.title = STR_GLOBAL_AUTHENTICATION;
    inline_struct.title_icon = email_icon;
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(p_account_list_cntx->edit_account_outgoing_server_group_id, &inline_struct);

    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_USERNAME_CONTENT_ID, 
        p_account_list_cntx->p_outgoing_server_auth->username);

    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_PASSWORD_CONTENT_ID, 
        p_account_list_cntx->p_outgoing_server_auth->password);
    
    cui_inline_run(inline_id);

    if (NULL != inline_item)
    {
        OslMfree(inline_item);
        inline_item = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_outgoing_server_lsk
* DESCRIPTION
*  Handle the outgoing server submit process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_outgoing_server_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_info_struct *p_cuurent_account_info = NULL;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    WCHAR port_string[MMI_EMAIL_MAX_PORT_NUMBER + 1];
    U32 port_num = 0;
    S32 select_value = 0;
    srv_email_acct_info_struct *p_origin_current_info = NULL;
    MMI_BOOL ignor = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_origin_current_info = OslMalloc(sizeof(srv_email_acct_info_struct));
    p_cuurent_account_info = &(mmi_email_account_list_p->current_account);
    memcpy(p_origin_current_info, p_cuurent_account_info, sizeof(srv_email_acct_info_struct));

#ifdef __MMI_SSO__
    if (mmi_email_sso_is_cloud_account(mmi_email_account_list_p->current_account_id))
    {
        ignor = MMI_TRUE;
    }
#endif /*__MMI_SSO__ */

    if (!ignor)
    {
        cui_inline_get_value(
            mmi_email_account_list_p->account_outgoing_server_id, 
            MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CONTENT_ID, 
            port_string);

        if (0 == mmi_wcslen(port_string))
        {
            mmi_email_lib_error_popup(STR_EMAIL_PORT_NUMBER_EMPTY);
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_OUTGOING_SERVER_LSK_END;
        }

        port_num = gui_atoi(port_string);
        if ((port_num > MMI_EMAIL_MAX_PORT) || (port_num < MMI_EMAIL_MIN_PORT))
        {
            mmi_email_lib_error_popup(STR_EMAIL_PORT_NUMBER_OUTOF_RANGE);
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_OUTGOING_SERVER_LSK_END;
        }

#ifdef __SSL_SUPPORT__
        cui_inline_get_value(
            mmi_email_account_list_p->account_outgoing_server_id, 
            MMI_EMAIL_OUTGOING_SERVER_EDIT_SECURITY_CONTENT_ID, 
            &select_value);
        if (0 == select_value)
        {
            p_cuurent_account_info->out_server.sec_mode = SRV_EMAIL_SEC_NONE;
            p_cuurent_account_info->out_server.port_num = port_num;        
        }
        else if (1 == select_value)
        {
            p_cuurent_account_info->out_server.sec_mode = SRV_EMAIL_SEC_SSL_TLS;
            p_cuurent_account_info->out_server.sec_port_num = port_num;
        }
        else
        {
            p_cuurent_account_info->out_server.sec_mode = SRV_EMAIL_SEC_STARTTLS;
            p_cuurent_account_info->out_server.port_num = port_num;                
        }
#else /* __SSL_SUPPORT__ */
        {
            p_cuurent_account_info->out_server.port_num = port_num;
        }
#endif /* __SSL_SUPPORT__ */

        /* authentication part begin */
        memcpy(
            &(p_cuurent_account_info->out_auth), 
            mmi_email_account_list_p->p_outgoing_server_auth,
            sizeof(srv_email_auth_struct));
        cui_inline_get_value(
            mmi_email_account_list_p->account_outgoing_server_id, 
            MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID, 
            &select_value);
        if (0 == select_value)
        {
            p_cuurent_account_info->out_auth.auth_type = SRV_EMAIL_AUTH_NONE;
        }
        else
        {
            p_cuurent_account_info->out_auth.auth_type = SRV_EMAIL_AUTH_USER;
        }
        /* authentication part end */
    }

    /* save sent mail part begin */
    cui_inline_get_value(
        mmi_email_account_list_p->account_outgoing_server_id, 
        MMI_EMAIL_OUTGOING_SERVER_EDIT_SAVE_SENT_MAILS_CONTENT_ID, 
        &select_value);
    if (0 == select_value)
    {
        mmi_email_account_list_p->current_account_extra_info.save_sent_emails = MMI_FALSE;
    }
    else
    {
        mmi_email_account_list_p->current_account_extra_info.save_sent_emails = MMI_TRUE;
    }
    /* save sent mail part end */

    /* save account info begin*/
    srv_op_result = mmi_email_entry_edit_account_save_account_info(
                        mmi_email_account_list_p->srv_handle, 
                        &(mmi_email_account_list_p->current_account_handle), 
                        mmi_email_account_list_p->current_account_id, 
                        p_cuurent_account_info);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        mmi_email_util_display_error_popup(
            mmi_email_account_list_p->edit_account_outgoing_server_group_id,
            srv_op_result);
        cui_inline_close(mmi_email_account_list_p->account_outgoing_server_id);
        mmi_email_account_list_p->account_outgoing_server_id = GRP_ID_INVALID;
        memcpy(p_cuurent_account_info, p_origin_current_info, sizeof(srv_email_acct_info_struct));
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_OUTGOING_SERVER_LSK_END;
    }
    
    if (MMI_FALSE == mmi_email_entry_edit_account_write_account_extra_info(
                        mmi_email_account_list_p->current_account_id, 
                        &(mmi_email_account_list_p->current_account_extra_info), 
                        NULL))
    {
        mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        cui_inline_close(mmi_email_account_list_p->account_outgoing_server_id);
        mmi_email_account_list_p->account_outgoing_server_id = GRP_ID_INVALID;
        memcpy(p_cuurent_account_info, p_origin_current_info, sizeof(srv_email_acct_info_struct));
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_OUTGOING_SERVER_LSK_END;
    }

    //mmi_email_lib_succ_popup(STR_GLOBAL_SAVED);
    cui_inline_close(mmi_email_account_list_p->account_outgoing_server_id);
    mmi_email_account_list_p->account_outgoing_server_id = GRP_ID_INVALID;
    /* save account info end */
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_OUTGOING_SERVER_LSK_END:
    if (NULL != p_origin_current_info)
    {
        OslMfree(p_origin_current_info);
        p_origin_current_info = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_outgoing_server_rsk
* DESCRIPTION
*  Handle the outgoing server submit process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_outgoing_server_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(mmi_email_account_list_p->account_outgoing_server_id);
    mmi_email_account_list_p->account_outgoing_server_id = GRP_ID_INVALID;
    mmi_frm_scrn_close_active_id();
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_process
* DESCRIPTION
*  Entry editing incoming server process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_PROCESS, __LINE__);

    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_INCOMING_SERVER;
    p_account_list_cntx->edit_account_incoming_server_group_id = mmi_frm_group_create(
                                                                    p_account_list_cntx->edit_account_group_id, 
                                                                    GRP_ID_AUTO_GEN, 
                                                                    mmi_email_entry_edit_account_entry_incoming_server_proc, 
                                                                    p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->edit_account_incoming_server_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (SRV_EMAIL_PROT_POP3 == p_account_list_cntx->current_account.protocol)
    {
        mmi_email_entry_edit_account_entry_incoming_server_pop3_screen(p_account_list_cntx);
    }
    else
    {
        mmi_email_entry_edit_account_entry_incoming_server_imap_screen(p_account_list_cntx);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_proc
* DESCRIPTION
*  The procedure function of edit_account_incoming_server_group_id
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_entry_incoming_server_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->evt_id)
    {
    case EVT_ID_CUI_INLINE_NOTIFY:
        mmi_email_entry_edit_account_incoming_server_proc_handle_inline_notify_message((cui_event_inline_notify_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_SET_KEY:
        mmi_email_entry_edit_account_incoming_server_proc_handle_inline_setkey_message((cui_event_inline_set_key_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        mmi_email_entry_edit_account_incoming_server_proc_csk(((cui_event_inline_submit_struct*)p_event)->item_id);
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        mmi_email_entry_edit_account_incoming_server_proc_handle_inline_abort_message((cui_event_inline_abort_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        mmi_email_entry_edit_account_incoming_server_proc_handle_inline_deinit_message((cui_event_inline_common_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_email_entry_edit_account_incoming_server_proc_handle_menu_entry_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        mmi_email_entry_edit_account_incoming_server_proc_handle_menu_select_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_email_entry_edit_account_incoming_server_proc_handle_menu_close_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_CBM_OK:
    case EVT_ID_CUI_CBM_FAIL:
    case EVT_ID_CUI_CBM_CANCEL:
        mmi_email_entry_edit_account_incoming_server_proc_handle_cbm_cui_message((cui_evt_cbm_bearer_select_struct*)p_event);
        break;

    case EVT_ID_GROUP_FOCUSED:
        mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->edit_account_incoming_server_group_id);
        break;

    case EVT_ID_ALERT_QUIT:
        mmi_email_entry_edit_account_incoming_server_proc_handle_alert_quit_message((mmi_alert_result_evt_struct*)p_event);
        break;

    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_inline_notify_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_NOTIFY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_NOTIFY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_inline_notify_message(cui_event_inline_notify_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->event_type)
    {
        case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
        {
        #ifdef __SSL_SUPPORT__
            /* first highlight does not change the port value */
                if ((MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CONTENT_ID == p_event->item_id) ||
                    (MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SECURITY_CONTENT_ID == p_event->item_id))
                {
                    WCHAR port_string[MMI_EMAIL_MAX_PORT_NUMBER + 1];
                    U16 port_num = 0;                      
                    U16 sec_port_num = 0;
                    U16 item_id = 0;
                mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

                    if (MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CONTENT_ID == p_event->item_id)
                    {
                        item_id = MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CONTENT_ID;
                    }
                    else
                    {
                        item_id = MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CONTENT_ID;
                    }
                p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
                    port_num = p_account_list_cntx->current_account.in_server.port_num;
                    sec_port_num = p_account_list_cntx->current_account.in_server.sec_port_num;

                    if (0 == port_num)
                    {
                        if (MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CONTENT_ID == p_event->item_id)
                        {
                            port_num = MMI_EMAIL_POP3_PORT_NUMBER;
                        }
                        else
                        {
                            port_num = MMI_EMAIL_IMAP_PORT_NUMBER;
                        }
                    }

                    if (0 == sec_port_num)
                    {
                        if (MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CONTENT_ID == p_event->item_id)
                        {
                            sec_port_num = MMI_EMAIL_POP3_SECURITY_PORT_NUMBER;
                        }
                        else
                        {
                            sec_port_num = MMI_EMAIL_IMAP_SECURITY_PORT_NUMBER;
                        }
                    }
                    
                    if (1 == p_event->param)
                    {
                         kal_wsprintf(port_string, "%d", sec_port_num);
                    }
                    else
                    {
                         kal_wsprintf(port_string, "%d", port_num);
                    }
                    cui_inline_set_value(p_event->sender_id, item_id, port_string);
                }
        #endif /* __SSL_SUPPORT__ */
            
            break;
        }
        case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
        {
            break;
        }
        default:
        {
            break;
        }
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_inline_setkey_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SET_KEY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SET_KEY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_inline_setkey_message(cui_event_inline_set_key_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    switch (p_event->item_id)
    {
    #ifdef __MMI_EMAIL_REMOTE_FOLDER__
        case MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_FOLDER_SUBSCRIPTION_CAPTION_ID:
        {
            cui_inline_set_softkey_icon(
                p_account_list_cntx->account_incoming_server_id,
                p_event->item_id,
                MMI_CENTER_SOFTKEY,
                IMG_GLOBAL_COMMON_CSK);
            //SetLeftSoftkeyFunction(mmi_email_entry_edit_account_entry_incoming_server_imap_remote_folder, KEY_EVENT_UP);
            wgui_inline_set_lsk_function(mmi_email_entry_edit_account_entry_incoming_server_imap_remote_folder);
            //SetCenterSoftkeyFunction(mmi_email_entry_edit_account_entry_incoming_server_imap_remote_folder, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_EMAIL_REMOTE_FOLDER__ */
        default:
        {
            break;
        }
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_csk
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SUBMIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SUBMIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_csk(S16 item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
        confirm_struct.parent_id = mmi_email_account_list_p->edit_account_incoming_server_group_id;
        confirm_struct.user_tag = (void*)MMI_EMAIL_ACCOUNT_ALERT_SAVE_INCOMING_SERVER;
        mmi_confirm_display((WCHAR*)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &confirm_struct);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_inline_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_inline_abort_message(cui_event_inline_abort_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_inline_deinit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_GROUP_DEINIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_GROUP_DEINIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_inline_deinit_message(cui_event_inline_common_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_menu_entry_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_LIST_ENTRY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_LIST_ENTRY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_menu_entry_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_event->user_data;
    
    switch (p_event->parent_menu_id)
    {
        case MENU_ID_EMAIL_REMOTE_FOLDER_OPT:
        {
            mmi_menu_id sub_option_menu_id_array[] = {
                                                    MENU_ID_EMAIL_REMOTE_FOLDER_OPT_SUB,  
                                                    MENU_ID_EMAIL_REMOTE_FOLDER_OPT_SYNC};
            U16 sub_option_menu_id_string_array[] = {
                                                    STR_EMAIL_REMOTE_FOLDER_SUBSCRIBE_ID, 
                                                    STR_EMAIL_REMOTE_SYNC_FOLDERS_ID};
            mmi_menu_id unsub_option_menu_id_array[] = {
                                                    MENU_ID_EMAIL_REMOTE_FOLDER_OPT_UNSUB, 
                                                    MENU_ID_EMAIL_REMOTE_FOLDER_OPT_SYNC};
            U16 unsub_option_menu_id_string_array[] = {
                                                    STR_EMAIL_REMOTE_FOLDER_UNSUBSCRIBE_ID, 
                                                    STR_EMAIL_REMOTE_SYNC_FOLDERS_ID};
            srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
            mmi_email_menu_screen_struct menu_screen;
            srv_email_acct_remote_fldr_info_strcut *p_folder_info = NULL;
            U32 folder_num = 1;

            p_folder_info = OslMalloc(sizeof(srv_email_acct_remote_fldr_info_strcut));
            srv_op_result = srv_email_acct_get_remote_fldr_info(
                                p_account_list_cntx->current_account_handle, 
                                p_account_list_cntx->remote_folder_highlight_index, 
                                &folder_num, 
                                p_folder_info);
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
            }
            
            menu_screen.title_string_id = STR_GLOBAL_OPTIONS;
            menu_screen.title_icon_id = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);
            if (MMI_TRUE == p_folder_info->subscribed)
            {
                menu_screen.menu_item_number = sizeof(unsub_option_menu_id_array) / sizeof(mmi_menu_id);
                menu_screen.menu_id_array = unsub_option_menu_id_array;
                menu_screen.menu_id_string_array = unsub_option_menu_id_string_array;
            }
            else
            {
                menu_screen.menu_item_number = sizeof(sub_option_menu_id_array) / sizeof(mmi_menu_id);
                menu_screen.menu_id_array = sub_option_menu_id_array;
                menu_screen.menu_id_string_array = sub_option_menu_id_string_array;
            }
            menu_screen.menu_id_image_array = (U16*)gIndexIconsImageList;
            mmi_email_account_set_menu_screen(p_event->sender_id, &menu_screen, STR_GLOBAL_SELECT);

            if (NULL != p_folder_info)
            {
                OslMfree(p_folder_info);
                p_folder_info = NULL;
            }
            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_menu_select_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_ITEM_SELECT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_ITEM_SELECT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_menu_select_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_event->user_data;
    
    switch (p_event->highlighted_menu_id)
    {
        case MENU_ID_EMAIL_REMOTE_FOLDER_OPT_SUB:
        case MENU_ID_EMAIL_REMOTE_FOLDER_OPT_UNSUB:
        {
            MMI_BOOL subscribe = MMI_FALSE;
            srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
            
            if (MENU_ID_EMAIL_REMOTE_FOLDER_OPT_SUB == p_event->highlighted_menu_id)
            {
                subscribe = MMI_TRUE;
            }
            srv_op_result =  mmi_email_subscribe_remote_folder(p_account_list_cntx, subscribe);
            if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
            {
                mmi_email_lib_succ_popup(STR_GLOBAL_DONE);
            }
            else if (SRV_EMAIL_RESULT_WOULDBLOCK == srv_op_result)
            {
                srv_op_result = srv_email_acct_register_callback(
                                    p_account_list_cntx->current_account_handle, 
                                    mmi_email_entry_edit_account_entry_incoming_server_imap_remote_callback, 
                                    p_account_list_cntx);
                if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
                {
                    mmi_email_util_display_error_popup(p_account_list_cntx->edit_account_incoming_server_group_id, srv_op_result);
                }
                else
                {
                    mmi_frm_scrn_first_enter(
                        p_account_list_cntx->edit_account_incoming_server_group_id, 
                        SCR_ID_EMAIL_PROGRESS,
                        (FuncPtr)mmi_email_entry_edit_account_entry_incoming_server_imap_subscibe_wait_screen, 
                        p_account_list_cntx);
                }
            }
            else
            {
                mmi_email_util_display_error_popup(p_account_list_cntx->edit_account_incoming_server_group_id, srv_op_result);
            }
            break;
        }
        case MENU_ID_EMAIL_REMOTE_FOLDER_OPT_SYNC:
        {
            mmi_frm_scrn_close(p_account_list_cntx->edit_account_incoming_server_group_id, SCR_ID_EMAIL_REMOTE_FOLDER);
            mmi_email_entry_edit_account_entry_incoming_server_imap_remote_folder();
            break;
        }
        default:
        {
            break;
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_menu_close_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_CLOSE_REQUEST
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_CLOSE_REQUEST event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_menu_close_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(p_event->sender_id);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_cbm_cui_message
* DESCRIPTION
*  
* PARAMETERS
*  p_event   [IN] 
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_cbm_cui_message(cui_evt_cbm_bearer_select_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_event->user_data;
    
    if (SRV_CBM_BEARER_ALWAYS_ASK == p_account_list_cntx->cbm_bearer_query_type)
    {
        cui_cbm_always_ask_close(p_event->sender_id);
    }
    else if (SRV_CBM_BEARER_FB_L1 == p_account_list_cntx->cbm_bearer_query_type)
    {
        cui_cbm_bearer_fallback_close(p_event->sender_id);
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_incoming_server_proc_handle_alert_quit_message
* DESCRIPTION
*  
* PARAMETERS
*  p_event   [IN] 
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_incoming_server_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
        case MMI_EMAIL_ACCOUNT_ALERT_SAVE_INCOMING_SERVER:
        {
            if (MMI_ALERT_CNFM_YES == p_event->result)
            {
                mmi_email_entry_edit_account_save_incoming_server_lsk();
            }
            else if (MMI_ALERT_CNFM_NO == p_event->result)
            {
                mmi_email_entry_edit_account_save_incoming_server_rsk();
            }
        }
        default:
        {
            break;
        }
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_pop3_screen
* DESCRIPTION
*  Entry editing incoming server pop3 screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_pop3_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct;
    
    cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};

    cui_inline_set_item_struct *inline_item = NULL;
    cui_inline_item_caption_struct caption_struct[MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_CAPTION_ITEMS_NUMBER];
    cui_inline_item_text_edit_struct text_edit_struct[MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_TEXT_ITEMS_NUMBER];
    cui_inline_item_select_struct select_struct[MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SELECT_ITEMS_NUMBER];

#ifdef __SSL_SUPPORT__
    U16 security_string_id_array[] = {STR_GLOBAL_OFF, STR_EMAIL_USING_SSL_ID, STR_EMAIL_USING_TLS_ID};
#endif /* __SSL_SUPPORT__ */

    U16 apop_status_string_id_array[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
    U16 download_string_id_array[] = {STR_EMAIL_HEADER_ONLY, STR_EMAIL_DOWNLOAD_ALL};
    
    S32 inline_item_index = 0;
    S32 caption_index = 0;
    S32 text_index = 0;
    S32 select_index = 0;

    U16 email_icon = 0;
    mmi_id inline_id = GRP_ID_INVALID;
    U8 select_value = 0;
    WCHAR port_string[MMI_EMAIL_MAX_PORT_NUMBER + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_item = OslMalloc(MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_ITEMS_NUMBER * sizeof(cui_inline_set_item_struct));

    email_icon = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);

    /* port part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_INCOMING_PORT_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_INCOMING_PORT_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_text_edit_struct(
        &text_edit_struct[text_index], 
        0, 
        0, 
        (MMI_EMAIL_MAX_PORT_NUMBER + 1), 
        IMM_INPUT_TYPE_NUMERIC, 
        0, 
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 
        0, 
        &text_edit_struct[text_index++]);
    /* port part end */

#ifdef __SSL_SUPPORT__
    /* security part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_SECURITY_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_SECURITY_ID,
        &caption_struct[caption_index++]);

    if (SRV_EMAIL_SEC_NONE == p_account_list_cntx->current_account.in_server.sec_mode)
    {
        select_value = 0;
    }
    else if (SRV_EMAIL_SEC_SSL_TLS == p_account_list_cntx->current_account.in_server.sec_mode)
    {
        select_value = 1;
    }
    else
    {
        select_value = 2;
    }
    mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(security_string_id_array) / sizeof(U16), 
            select_value, 
            security_string_id_array);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* security part end */
#endif /* __SSL_SUPPORT__ */

    /* apop status part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_APOP_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_APOP_STATUS_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_APOP_ID,
        &caption_struct[caption_index++]);

    if (SRV_EMAIL_AUTH_APOP == p_account_list_cntx->current_account.in_auth.auth_type)
    {
        select_value = 1;
    }
    else
    {
        select_value = 0;
    }
    mmi_email_account_init_select_struct(
        &select_struct[select_index], 
        sizeof(apop_status_string_id_array) / sizeof(U16), 
        select_value, 
        apop_status_string_id_array);

    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_APOP_STATUS_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* apop status part end */

    /* download part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_DOWNLOAD_OPTION_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_DOWNLOAD_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_DOWNLOAD_OPTION_ID,
        &caption_struct[caption_index++]);

    if (SRV_EMAIL_DOWNLOAD_HEADER == p_account_list_cntx->current_account.download_option)
    {
        select_value = 0;
    }
    else
    {
        select_value = 1;
    }
    mmi_email_account_init_select_struct(
        &select_struct[select_index], 
        sizeof(download_string_id_array) / sizeof(U16), 
        select_value, 
        download_string_id_array);

    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_DOWNLOAD_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* download part end */

    inline_struct.items_count = MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_ITEMS_NUMBER;
    inline_struct.title = STR_EMAIL_POP3_IMAP4_SETTING_ID;
    inline_struct.title_icon = email_icon;
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(p_account_list_cntx->edit_account_incoming_server_group_id, &inline_struct);

#ifdef __SSL_SUPPORT__
    if (SRV_EMAIL_SEC_SSL_TLS == p_account_list_cntx->current_account.in_server.sec_mode)
    {
        kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.in_server.sec_port_num);
    }
    else
    {
        kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.in_server.port_num);
    }
#else /* __SSL_SUPPORT__ */
    kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.in_server.port_num);
#endif /* __SSL_SUPPORT__ */
    cui_inline_set_value(inline_id, MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CONTENT_ID, port_string);



#ifdef __MMI_SSO__
    if (mmi_email_sso_is_cloud_account(mmi_email_account_list_p->current_account_id))
    {
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
#ifdef __SSL_SUPPORT__
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
#endif /* __SSL_SUPPORT__ */
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_APOP_STATUS_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
    }
#endif /* __MMI_SSO__ */


    cui_inline_run(inline_id);
    p_account_list_cntx->account_incoming_server_id = inline_id;

    if (NULL != inline_item)
    {
        OslMfree(inline_item);
        inline_item = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_screen
* DESCRIPTION
*  Entry editing incoming server imap4 screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_imap_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct;
    
    cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};

    cui_inline_set_item_struct *inline_item = NULL;
    cui_inline_item_caption_struct caption_struct[MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_CAPTION_ITEMS_NUMBER];
    cui_inline_item_text_edit_struct text_edit_struct[MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_TEXT_ITEMS_NUMBER];
    cui_inline_item_select_struct select_struct[MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SELECT_ITEMS_NUMBER];
#ifdef __MMI_EMAIL_REMOTE_FOLDER__
    cui_inline_item_display_only_struct display_only_struct[MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_DISPLAY_ONLY_ITEMS_NUMBER];
#endif /* __MMI_EMAIL_REMOTE_FOLDER__ */
#ifdef __SSL_SUPPORT__
    U16 security_string_id_array[] = {STR_GLOBAL_OFF, STR_EMAIL_USING_SSL_ID, STR_EMAIL_USING_TLS_ID};
#endif /* __SSL_SUPPORT__ */
    U16 download_string_id_array[] = {STR_EMAIL_HEADER_ONLY, STR_EMAIL_HEADER_TEXT, STR_EMAIL_DOWNLOAD_ALL};
    
    S32 inline_item_index = 0;
    S32 caption_index = 0;
    S32 text_index = 0;
    S32 select_index = 0;
    S32 display_index = 0;

    U16 email_icon = 0;
    mmi_id inline_id = GRP_ID_INVALID;
    U8 select_value = 0;
    WCHAR port_string[MMI_EMAIL_MAX_PORT_NUMBER + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_item = OslMalloc(MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_ITEMS_NUMBER * sizeof(cui_inline_set_item_struct));
    
    email_icon = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);

    /* port part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_INCOMING_PORT_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_INCOMING_PORT_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_text_edit_struct(
        &text_edit_struct[text_index], 
        0, 
        0, 
        (MMI_EMAIL_MAX_PORT_NUMBER + 1), 
        IMM_INPUT_TYPE_NUMERIC, 
        0, 
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 
        0, 
        &text_edit_struct[text_index++]);
    /* port part end */

#ifdef __SSL_SUPPORT__
    /* security part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_SECURITY_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SECURITY_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_SECURITY_ID,
        &caption_struct[caption_index++]);

    if (SRV_EMAIL_SEC_NONE == p_account_list_cntx->current_account.in_server.sec_mode)
    {
        select_value = 0;
    }
    else if (SRV_EMAIL_SEC_SSL_TLS == p_account_list_cntx->current_account.in_server.sec_mode)
    {
        select_value = 1;
    }
    else
    {
        select_value = 2;
    }
    mmi_email_account_init_select_struct(
            &select_struct[select_index], 
            sizeof(security_string_id_array) / sizeof(U16), 
            select_value, 
            security_string_id_array);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SECURITY_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* security part end */
#endif /* __SSL_SUPPORT__ */

    /* download part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_DOWNLOAD_OPTION_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_DOWNLOAD_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_CAPTION,
        IMG_EMAIL_DOWNLOAD_OPTION_ID,
        &caption_struct[caption_index++]);

    if (SRV_EMAIL_DOWNLOAD_HEADER == p_account_list_cntx->current_account.download_option)
    {
        select_value = 0;
    }
    else if (SRV_EMAIL_DOWNLOAD_HEADER_TEXT == p_account_list_cntx->current_account.download_option)
    {
        select_value = 1;
    }
    else
    {
        select_value = 2;
    }

    mmi_email_account_init_select_struct(
        &select_struct[select_index], 
        sizeof(download_string_id_array) / sizeof(U16), 
        select_value, 
        download_string_id_array);

    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_DOWNLOAD_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_SELECT,
        0,
        &select_struct[select_index++]);
    /* download part end */

#ifdef __MMI_EMAIL_REMOTE_FOLDER__
    /* folder subscription part begin */
    display_only_struct[display_index].string_id = STR_EMAIL_REMOTE_FOLDER_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_FOLDER_SUBSCRIPTION_CAPTION_ID,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,
        IMG_EMAIL_MORE_FOLDER_ID,
        &display_only_struct[display_index++]);
    /* folder subscription part end */
#endif /* __MMI_EMAIL_REMOTE_FOLDER__ */

    inline_struct.items_count = MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_ITEMS_NUMBER;
    inline_struct.title = STR_EMAIL_POP3_IMAP4_SETTING_ID;
    inline_struct.title_icon = email_icon;
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(p_account_list_cntx->edit_account_incoming_server_group_id, &inline_struct);

#ifdef __SSL_SUPPORT__
    if (SRV_EMAIL_SEC_SSL_TLS == p_account_list_cntx->current_account.in_server.sec_mode)
    {
        kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.in_server.sec_port_num);
    }
    else
    {
        kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.in_server.port_num);
    }
#else /* __SSL_SUPPORT__ */
    kal_wsprintf(port_string, "%d", p_account_list_cntx->current_account.in_server.port_num);
#endif /* __SSL_SUPPORT__ */
    cui_inline_set_value(inline_id, MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CONTENT_ID, port_string);

#ifdef __MMI_EMAIL_REMOTE_FOLDER__
    cui_inline_set_softkey_text(inline_id, (U16)(MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_FOLDER_SUBSCRIPTION_CAPTION_ID), MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
#endif /* __MMI_EMAIL_REMOTE_FOLDER__ */


#ifdef __MMI_SSO__
    if (mmi_email_sso_is_cloud_account(mmi_email_account_list_p->current_account_id))
    {
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
#ifdef __SSL_SUPPORT__
        cui_inline_set_item_attributes(inline_id, MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SECURITY_CONTENT_ID, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
#endif /* __SSL_SUPPORT__ */
    }
#endif /* __MMI_SSO__ */


    cui_inline_run(inline_id);
    p_account_list_cntx->account_incoming_server_id = inline_id;

    if (NULL != inline_item)
    {
        OslMfree(inline_item);
        inline_item = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_remote_folder
* DESCRIPTION
*  Entry editing incoming server imap4 remote folder
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_acct_register_callback(
                        mmi_email_account_list_p->current_account_handle, 
                        mmi_email_entry_edit_account_entry_incoming_server_imap_remote_callback, 
                        mmi_email_account_list_p);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_LOG3, mmi_email_account_list_p->current_account_handle, srv_op_result);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_IMAP_REMOTE_FOLDER_END;
    }

    srv_op_result = srv_email_acct_register_proc_callback(
                        mmi_email_account_list_p->current_account_handle, 
                        mmi_email_entry_edit_account_entry_incoming_server_imap_remote_process, 
                        mmi_email_account_list_p);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_LOG3, mmi_email_account_list_p->current_account_handle, srv_op_result);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_IMAP_REMOTE_FOLDER_END;
    }
    
    srv_op_result = srv_email_acct_list_remote_fldr(
                        mmi_email_account_list_p->current_account_handle, 
                        MMI_EMAIL_IMAP_REMOTE_FOLDER_NUMBER, 
                        &(mmi_email_account_list_p->current_req_id));
    if ((SRV_EMAIL_RESULT_WOULDBLOCK != srv_op_result) && (SRV_EMAIL_RESULT_SUCC != srv_op_result))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_LOG2, mmi_email_account_list_p->current_account_handle, srv_op_result);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_IMAP_REMOTE_FOLDER_END;
    }
   
    mmi_frm_scrn_first_enter(
        mmi_email_account_list_p->edit_account_incoming_server_group_id, 
        SCR_ID_EMAIL_PROGRESS,
        (FuncPtr)mmi_email_entry_edit_account_entry_incoming_server_imap_remote_wait_screen, 
        mmi_email_account_list_p);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_LOG4, mmi_email_account_list_p->srv_handle, mmi_email_account_list_p->current_account_handle);
    return;
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_IMAP_REMOTE_FOLDER_END:
    mmi_email_util_display_error_popup(mmi_email_account_list_p->edit_account_incoming_server_group_id, srv_op_result);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_remote_wait_screen
* DESCRIPTION
*  Entry editing incoming server imap4 remote folder
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_entry_incoming_server_imap_remote_wait_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id,
                        p_screen_data->scrn_id,
                        NULL,
                        (FuncPtr)mmi_email_entry_edit_account_entry_incoming_server_imap_remote_wait_screen,
                        MMI_FRM_FULL_SCRN))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_WAIT_SCREEN);

        p_account_list_cntx = p_screen_data->user_data;
        p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_UPDATE_FOLDER_LIST;
        
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        ShowCategory66Screen(
            STR_GLOBAL_EMAIL,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*)GetString(STR_GLOBAL_CONNECTING),
            mmi_email_lib_get_progress_img_id(),
            guiBuffer);
        SetRightSoftkeyFunction(mmi_email_entry_edit_account_entry_incoming_server_remote_cancel, KEY_EVENT_UP);
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_remote_cancel
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_remote_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_EMAIL_ACCOUNT_LIST_STATE_UPDATE_FOLDER_LIST == mmi_email_account_list_p->state)
    {
        srv_op_result = srv_email_acct_abort(
                            mmi_email_account_list_p->current_account_handle, 
                            mmi_email_account_list_p->current_req_id);
        
        if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
        {
            //mmi_email_lib_succ_popup(STR_EMAIL_CANCELED_ID);
        }
        else
        {
            mmi_email_util_display_error_popup(mmi_email_account_list_p->edit_account_incoming_server_group_id, srv_op_result);
        }
        
        mmi_frm_scrn_close(mmi_email_account_list_p->edit_account_incoming_server_group_id, SCR_ID_EMAIL_PROGRESS);
        srv_email_acct_clear_callback(mmi_email_account_list_p->current_account_handle);
        mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;

        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_CANCEL, mmi_email_account_list_p->current_account_handle, mmi_email_account_list_p->current_req_id, srv_op_result);
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_remote_callback
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_callback(
                srv_email_result_struct *p_result,
                EMAIL_REQ_ID req_id,
                void *p_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_user_data;

    if (MMI_EMAIL_ACCOUNT_LIST_STATE_UPDATE_FOLDER_LIST == p_account_list_cntx->state)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_CALLBACK_LOG1, p_result->result, p_account_list_cntx->current_account_handle);

        srv_email_acct_clear_callback(p_account_list_cntx->current_account_handle);
        
        if (MMI_TRUE == p_result->result)
        {
            srv_op_result = srv_email_acct_get_remote_fldr_num(
                                p_account_list_cntx->current_account_handle, 
                                &(p_account_list_cntx->remote_folder_num));
            if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_CALLBACK_LOG2, srv_op_result);
                mmi_email_util_display_error_popup(p_account_list_cntx->edit_account_incoming_server_group_id, srv_op_result);
                goto MMI_EMAIl_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_IMAP_REMOTE_CALLBACK_END_1;
            }

            /* Set the highlight index */
            p_account_list_cntx->remote_folder_highlight_index = 0;
            mmi_frm_scrn_first_enter(
                p_account_list_cntx->edit_account_incoming_server_group_id, 
                SCR_ID_EMAIL_REMOTE_FOLDER, 
                (FuncPtr)mmi_email_entry_edit_account_entry_incoming_server_imap_remote_list_screen, 
                p_account_list_cntx);
        }
        else
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(mmi_email_util_get_err_code(p_result->major, p_result->minor)), 
                MMI_EVENT_FAILURE, 
                p_account_list_cntx->edit_account_incoming_server_group_id, 
                0);
        }

    MMI_EMAIl_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_IMAP_REMOTE_CALLBACK_END_1:

        mmi_frm_scrn_close(p_account_list_cntx->edit_account_incoming_server_group_id, SCR_ID_EMAIL_PROGRESS);
        mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;
    }

    if (MMI_EMAIL_ACCOUNT_LIST_STATE_SUBSCRIBE_FOLDER == p_account_list_cntx->state)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_CALLBACK_LOG1, p_result->result, p_account_list_cntx->current_account_handle);

        srv_email_acct_clear_callback(p_account_list_cntx->current_account_handle);
        
        if (MMI_TRUE == p_result->result)
        {
            //mmi_email_lib_succ_popup(STR_GLOBAL_OK);
        }
        else
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(mmi_email_util_get_err_code(p_result->major, p_result->minor)), 
                MMI_EVENT_FAILURE, 
                p_account_list_cntx->edit_account_incoming_server_group_id, 
                0);
        }

        mmi_frm_scrn_close(p_account_list_cntx->edit_account_incoming_server_group_id, SCR_ID_EMAIL_PROGRESS);
        mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_subscibe_wait_screen
* DESCRIPTION
*  Entry editing incoming server imap4 remote folder
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_entry_incoming_server_imap_subscibe_wait_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id,
                        p_screen_data->scrn_id,
                        NULL,
                        (FuncPtr)mmi_email_entry_edit_account_entry_incoming_server_imap_subscibe_wait_screen,
                        MMI_FRM_FULL_SCRN))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_WAIT_SCREEN);

        p_account_list_cntx = p_screen_data->user_data;
        p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_SUBSCRIBE_FOLDER;
        
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        ShowCategory66Screen(
            STR_GLOBAL_EMAIL,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
            mmi_email_lib_get_progress_img_id(),
            guiBuffer);
        SetRightSoftkeyFunction(mmi_email_entry_edit_account_entry_incoming_server_subscribe_cancel, KEY_EVENT_UP);
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_subscribe_cancel
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_subscribe_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_EMAIL_ACCOUNT_LIST_STATE_SUBSCRIBE_FOLDER == mmi_email_account_list_p->state)
    {
        srv_op_result = srv_email_acct_abort(
                            mmi_email_account_list_p->current_account_handle, 
                            mmi_email_account_list_p->current_req_id);
        
        if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
        {
            //mmi_email_lib_succ_popup(STR_EMAIL_CANCELED_ID);
        }
        else
        {
            mmi_email_util_display_error_popup(
                mmi_email_account_list_p->edit_account_incoming_server_group_id, 
                srv_op_result);
        }
        
        mmi_frm_scrn_close(mmi_email_account_list_p->edit_account_incoming_server_group_id, SCR_ID_EMAIL_PROGRESS);
        srv_email_acct_clear_callback(mmi_email_account_list_p->current_account_handle);
        mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;

        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_CANCEL, mmi_email_account_list_p->current_account_handle, mmi_email_account_list_p->current_req_id, srv_op_result);
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_remote_process
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_process(srv_email_nwk_proc_struct *p_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    WCHAR *p_display_string = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = p_data->user_data;
    
    if (MMI_EMAIL_ACCOUNT_LIST_STATE_UPDATE_FOLDER_LIST == p_account_list_cntx->state)
    {
        switch (p_data->status)
        {
            case SRV_EMAIL_NWK_CONNECTING:
            {
                p_display_string = (WCHAR*)GetString(STR_GLOBAL_CONNECTING);
                break;
            }
            case SRV_EMAIL_NWK_AUTHORIZING:
            {
                p_display_string = (WCHAR*)GetString(STR_EMAIL_AUTHORIZING_ID);
                break;
            }
            case SRV_EMAIL_NWK_CBM_QUERYING:
            {
                cui_cbm_parameter_struct cbm_param = {0};
                srv_email_cbm_querying_struct *p_cbm_query = (srv_email_cbm_querying_struct*)(p_data->status_data);
                srv_cbm_bearer_event_struct *p_cbm_data = (srv_cbm_bearer_event_struct*)(p_cbm_query->cbm_data);
                mmi_id recv_cbm_id = GRP_ID_INVALID;
                
                cbm_param.account_id = p_cbm_data->account_id;
                cbm_param.res.icon_id = IMG_EMAIL_APP1_ID;
                cbm_param.res.str_id = STR_GLOBAL_EMAIL;
                cbm_param.fb_query_type = CUI_CBM_QUERY_FB_NORM;
                if (SRV_CBM_BEARER_ALWAYS_ASK == p_cbm_data->type)
                {
                    recv_cbm_id = cui_cbm_always_ask_create(p_account_list_cntx->edit_account_incoming_server_group_id);
                    cui_cbm_bearer_fallback_set_param(recv_cbm_id, &cbm_param);
                    cui_cbm_always_ask_run(recv_cbm_id);
                }
                else if (SRV_CBM_BEARER_FB_L1 == p_cbm_data->type)
                {
                    recv_cbm_id = cui_cbm_bearer_fallback_create(p_account_list_cntx->edit_account_incoming_server_group_id);
                    cui_cbm_always_ask_set_param(recv_cbm_id, &cbm_param);
                    cui_cbm_bearer_fallback_run(recv_cbm_id);
                }
                p_account_list_cntx->cbm_bearer_query_type = p_cbm_data->type;
                break;
            }
            case SRV_EMAIL_NWK_QUERYING:
            {
                break;
            }
            case SRV_EMAIL_NWK_UPDATING:
            {
                p_display_string = (WCHAR*)GetString(STR_EMAIL_UPDATING_INFO_ID);
                break;
            }            
            case SRV_EMAIL_NWK_DISCONNECTING:
            {
                break;
            }
            case SRV_EMAIL_NWK_LISTING_FOLDER:
            {
                p_display_string = (WCHAR*)GetString(STR_EMAIL_UPDATING_INFO_ID);
                break;
            }
            default:
            {
                break;
            }
        }
    
        if (p_account_list_cntx->edit_account_incoming_server_group_id == mmi_frm_group_get_active_id())
        {
            wgui_cat_popup_update_string((UI_string_type)p_display_string);
        }
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_remote_list_screen
* DESCRIPTION
*  Entry editing incoming server imap4 remote folder
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_entry_incoming_server_imap_remote_list_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    U8 *guiBuffer = NULL;
    S32 category_error = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id, 
                        p_screen_data->scrn_id, 
                        NULL, 
                        (FuncPtr)mmi_email_entry_edit_account_entry_incoming_server_imap_remote_list_screen, 
                        MMI_FRM_FULL_SCRN))
    {
        p_account_list_cntx = p_screen_data->user_data;
        RegisterHighlightHandler(mmi_email_entry_edit_account_imap_remote_list_screen_highlight_handler);
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);

        ShowCategory261Screen(
            (U8*)GetString(STR_EMAIL_REMOTE_FOLDER_ID),
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            p_account_list_cntx->remote_folder_num,
            mmi_email_entry_edit_account_entry_incoming_server_imap_get_remote,
            NULL,
            p_account_list_cntx->remote_folder_highlight_index,
            IMG_EMAIL_READ_NORMAL_ID,
            0,
            guiBuffer,
            MMI_EMAIL_IMAP_REMOTE_FOLDER_LIST_STRING_NUMBER /* no_of_string */ ,
            MMI_EMAIL_IMAP_REMOTE_FOLDER_LIST_ICON_NUMBER /* no_of_icons */ ,
            &category_error);

        if (category_error)
        {
            mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
            mmi_frm_scrn_close(p_screen_data->group_id, p_screen_data->scrn_id);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_email_entry_edit_account_entry_incoming_server_imap_remote_lsk, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_email_entry_edit_account_entry_incoming_server_imap_remote_rsk, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_email_entry_edit_account_entry_incoming_server_imap_remote_lsk, KEY_EVENT_UP);            
        }
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_imap_remote_list_screen_highlight_handler
* DESCRIPTION
*  The highlight handler of account list menuitem
* PARAMETERS
*  index  [IN] The index of menuitem
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_imap_remote_list_screen_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_REMOTE_FOLDER_HILIGHT_HANDLER, index);
    mmi_email_account_list_p->remote_folder_highlight_index = index;
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_get_remote
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_email_entry_edit_account_entry_incoming_server_imap_get_remote(
            S32 start_index, 
            gui_iconlist_menu_item *p_menu_data, 
            S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    srv_email_acct_remote_fldr_info_strcut *p_folder_info = NULL;
    S32 index = 0;
    S32 return_value = 0;
    WCHAR *p_folder_name = NULL;
    U32 folder_num = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_folder_info = OslMalloc(sizeof(srv_email_acct_remote_fldr_info_strcut));

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_GET_REMOTE_LOG1, start_index, data_size, mmi_email_account_list_p->current_account_handle);
    for (index = start_index; index < (start_index + data_size); index++)
    {
        srv_op_result = srv_email_acct_get_remote_fldr_info(
                            mmi_email_account_list_p->current_account_handle, 
                            index, 
                            &folder_num, 
                            p_folder_info);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_IMAP_GET_REMOTE_LOG2, srv_op_result);
            return_value = 0;
            goto MMI_EMAUL_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_IMAP_GET_REMOTE_END;
        }

        p_folder_name = mmi_email_get_remote_folder_name(p_folder_info->folder_name, p_folder_info->fldr_name_separator);

        if ((NULL != p_folder_name) && (0 != *p_folder_name))
        {
            mmi_wcsncpy(p_menu_data->item_list[0], p_folder_name, MAX_SUBMENU_CHARACTERS);
        }
        else
        {
            mmi_wcsncpy(p_menu_data->item_list[0], p_folder_info->folder_name, MAX_SUBMENU_CHARACTERS);
        }
        mmi_wcsncpy(p_menu_data->item_list[1], p_folder_info->folder_name, MAX_SUBMENU_CHARACTERS);
        if (MMI_TRUE == p_folder_info->subscribed)
        {
            p_menu_data->image_list[0] = (U8*)GetImage(IMG_EMAIL_REMOTE_SUB_ID);
        }
        else
        {
            p_menu_data->image_list[0] = (U8*)GetImage(IMG_EMAIL_REMOTE_UNSUB_ID);
        }
        p_menu_data++;
        return_value++;
    }
    
MMI_EMAUL_ENTRY_EDIT_ACCOUNT_ENTRY_INCOMING_SERVER_IMAP_GET_REMOTE_END:
    if (NULL != p_folder_info)
    {
        OslMfree(p_folder_info);
        p_folder_info = NULL;
    }
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_remote_lsk
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id remote_folder_option_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    remote_folder_option_id = cui_menu_create(
                                mmi_email_account_list_p->edit_account_incoming_server_group_id, 
                                CUI_MENU_SRC_TYPE_APPCREATE, 
                                CUI_MENU_TYPE_OPTION, 
                                MENU_ID_EMAIL_REMOTE_FOLDER_OPT, 
                                MMI_FALSE, 
                                mmi_email_account_list_p);
    cui_menu_run(remote_folder_option_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_incoming_server_imap_remote_rsk
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_incoming_server_imap_remote_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_incoming_server_lsk
* DESCRIPTION
*  Handle the incoming server submit process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_incoming_server_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_info_struct *p_cuurent_account_info = NULL;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    WCHAR port_string[MMI_EMAIL_MAX_PORT_NUMBER + 1];
    S32 select_value = 0;
    
    U32 port_num = 0;
    U16 port_content_item_id = 0;
#ifdef __SSL_SUPPORT__
    U16 security_content_item_id = 0;
#endif /* __SSL_SUPPORT__ */
    U16 download_content_item_id = 0;
    MMI_BOOL ignor;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_cuurent_account_info = &(mmi_email_account_list_p->current_account);

    if (SRV_EMAIL_PROT_POP3 == p_cuurent_account_info->protocol)
    {
        port_content_item_id = MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CONTENT_ID;
    #ifdef __SSL_SUPPORT__
        security_content_item_id = MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CONTENT_ID;
    #endif /* __SSL_SUPPORT__ */
        download_content_item_id = MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_DOWNLOAD_CONTENT_ID;
    }
    else
    {
        port_content_item_id = MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CONTENT_ID;
    #ifdef __SSL_SUPPORT__
        security_content_item_id = MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SECURITY_CONTENT_ID;
    #endif /* __SSL_SUPPORT__ */
        download_content_item_id = MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_DOWNLOAD_CONTENT_ID;
    }

    ignor = MMI_FALSE;
    #ifdef __MMI_SSO__
    if (mmi_email_sso_is_cloud_account(mmi_email_account_list_p->current_account_id))
    {
        ignor = MMI_TRUE;
    }
    #endif /*__MMI_SSO__ */

    if (!ignor)
    {
        cui_inline_get_value(
            mmi_email_account_list_p->account_incoming_server_id, 
            port_content_item_id, 
            port_string);
        if (0 == mmi_wcslen(port_string))
        {
            mmi_email_lib_error_popup(STR_EMAIL_PORT_NUMBER_EMPTY);
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_INCOMING_SERVER_LSK_END;
        }

        port_num = gui_atoi(port_string);
        if ((port_num > MMI_EMAIL_MAX_PORT) || (port_num < MMI_EMAIL_MIN_PORT))
        {
            mmi_email_lib_error_popup(STR_EMAIL_PORT_NUMBER_OUTOF_RANGE);
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_INCOMING_SERVER_LSK_END;
        }

#ifdef __SSL_SUPPORT__
        cui_inline_get_value(
            mmi_email_account_list_p->account_incoming_server_id, 
            security_content_item_id, 
            &select_value);
        if (0 == select_value)
        {
            p_cuurent_account_info->in_server.sec_mode = SRV_EMAIL_SEC_NONE;
            p_cuurent_account_info->in_server.port_num = port_num;        
        }
        else if (1 == select_value)
        {
            p_cuurent_account_info->in_server.sec_mode = SRV_EMAIL_SEC_SSL_TLS;
            p_cuurent_account_info->in_server.sec_port_num = port_num;
        }
        else
        {
            p_cuurent_account_info->in_server.sec_mode = SRV_EMAIL_SEC_STARTTLS;
            p_cuurent_account_info->in_server.port_num = port_num;                
        }
#else /* __SSL_SUPPORT__ */
        {
            p_cuurent_account_info->in_server.port_num = port_num;
        }
#endif /* __SSL_SUPPORT__ */

        /* apop part begin */
        if (SRV_EMAIL_PROT_POP3 == p_cuurent_account_info->protocol)
        {
            cui_inline_get_value(
                mmi_email_account_list_p->account_incoming_server_id, 
                MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_APOP_STATUS_CONTENT_ID, 
                &select_value);
            if (0 == select_value)
            {
                p_cuurent_account_info->in_auth.auth_type = SRV_EMAIL_AUTH_USER;
            }
            else
            {
                p_cuurent_account_info->in_auth.auth_type = SRV_EMAIL_AUTH_APOP;
            }
        }
        /* apop part end */
    }

    /* download part begin */
    cui_inline_get_value(
        mmi_email_account_list_p->account_incoming_server_id, 
        download_content_item_id, 
        &select_value);
    if (SRV_EMAIL_PROT_POP3 == p_cuurent_account_info->protocol)
    {
        if (0 == select_value)
        {
            p_cuurent_account_info->download_option = SRV_EMAIL_DOWNLOAD_HEADER;
        }
        else
        {
            p_cuurent_account_info->download_option = SRV_EMAIL_DOWNLOAD_ALL;
        }
    }
    else
    {
        if (0 == select_value)
        {
            p_cuurent_account_info->download_option = SRV_EMAIL_DOWNLOAD_HEADER;
        }
        else if (1 == select_value)
        {
            p_cuurent_account_info->download_option = SRV_EMAIL_DOWNLOAD_HEADER_TEXT;
        }
        else
        {
            p_cuurent_account_info->download_option = SRV_EMAIL_DOWNLOAD_ALL;
        }

    }
    /* download part begin */


    /* save account info begin*/
    srv_op_result = mmi_email_entry_edit_account_save_account_info(
                        mmi_email_account_list_p->srv_handle, 
                        &(mmi_email_account_list_p->current_account_handle), 
                        mmi_email_account_list_p->current_account_id, 
                        p_cuurent_account_info);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        mmi_email_util_display_error_popup(
            mmi_email_account_list_p->edit_account_incoming_server_group_id,
            srv_op_result);
        cui_inline_close(mmi_email_account_list_p->account_incoming_server_id);
        mmi_email_account_list_p->account_incoming_server_id = GRP_ID_INVALID;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_INCOMING_SERVER_LSK_END;
    }
    //mmi_email_lib_succ_popup(STR_GLOBAL_SAVED);
    cui_inline_close(mmi_email_account_list_p->account_incoming_server_id);
    mmi_email_account_list_p->account_incoming_server_id = GRP_ID_INVALID;
    /* save account info end */

MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_INCOMING_SERVER_LSK_END:
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_incoming_server_rsk
* DESCRIPTION
*  Handle the incoming server submit process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_incoming_server_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(mmi_email_account_list_p->account_incoming_server_id);
    mmi_email_account_list_p->account_incoming_server_id = GRP_ID_INVALID;
    mmi_frm_scrn_close_active_id();
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_get_remote_folder_name
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static WCHAR *mmi_email_get_remote_folder_name(WCHAR *p_full_path_name, WCHAR seprator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *p_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != p_full_path_name)
    {
        for (; 0 != *p_full_path_name; p_full_path_name++)
        {
            if (seprator == *p_full_path_name)
            {
                p_name = p_full_path_name + 1;
            }
        }
    }
    return p_name; 
}


/*****************************************************************************
* FUNCTION
*  mmi_email_subscribe_remote_folder
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static srv_email_result_enum mmi_email_subscribe_remote_folder(
                                mmi_email_account_list_cntx_struct *p_account_list_cntx,
                                MMI_BOOL subscribe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_acct_subscribe_remote_fldr(
                        p_account_list_cntx->current_account_handle, 
                        p_account_list_cntx->remote_folder_highlight_index, 
                        subscribe);

    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_SUBSCRIBE_REMOTE_FOLDER_LOG1, p_account_list_cntx->current_account_handle, p_account_list_cntx->remote_folder_highlight_index, srv_op_result);
        goto MMI_EMAIL_SUBSCRIBE_REMOTE_FOLDER_END;
    }
    
    srv_op_result = srv_email_acct_remote_fldr_submit_subscribe(p_account_list_cntx->current_account_handle);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_SUBSCRIBE_REMOTE_FOLDER_LOG2, p_account_list_cntx->current_account_handle, p_account_list_cntx->remote_folder_highlight_index, srv_op_result);

MMI_EMAIL_SUBSCRIBE_REMOTE_FOLDER_END:
    return srv_op_result;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_signature_process
* DESCRIPTION
*  Entry editing signature process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_signature_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_core_result_enum op_result = MMI_EMAIL_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_SIGNATURE;
    p_account_list_cntx->edit_account_signature_group_id = 
        mmi_frm_group_create(
            p_account_list_cntx->edit_account_group_id, 
            GRP_ID_AUTO_GEN, 
            mmi_email_entry_edit_account_entry_signature_proc, 
            p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->edit_account_signature_group_id,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    op_result = mmi_email_sig_get_signature(
                    p_account_list_cntx->current_account_id, 
                    &(p_account_list_cntx->current_account_signature_info));
    if (MMI_EMAIL_SUCCESS != op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
            MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_SIGNATURE_PROCESS_ERROR_LOG1,
            p_account_list_cntx->current_account_id,
            op_result);
        mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_SIGNATURE_PROCESS_END;
    }

    mmi_wcscpy(
        p_account_list_cntx->sig_text, 
        (const WCHAR*)p_account_list_cntx->current_account_signature_info.text);

    if (p_account_list_cntx->current_account_signature_info.image_num > 0)
    {
        op_result = mmi_email_sig_get_image_path(
                        p_account_list_cntx->current_account_id, 
                        0, 
                        p_account_list_cntx->sig_file_path, 
                        (SRV_FMGR_PATH_MAX_LEN + 1));
        p_account_list_cntx->p_image_file_title = p_account_list_cntx->current_account_signature_info.image_name[0];
    }
    else
    {
        memset(p_account_list_cntx->sig_file_path, 0, sizeof(p_account_list_cntx->sig_file_path));
        p_account_list_cntx->p_image_file_title = NULL;
    }
    
    op_result = mmi_email_sig_get_status(
                    p_account_list_cntx->current_account_id, 
                    &p_account_list_cntx->current_account_signature_status);
    if (MMI_EMAIL_SUCCESS != op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL,
            MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_SIGNATURE_PROCESS_ERROR_LOG2,
            p_account_list_cntx->current_account_id,
            op_result);
        mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_SIGNATURE_PROCESS_END;
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_SIGNATURE_PROCESS_ERROR_LOG3, 
        p_account_list_cntx->current_account_id, 
        p_account_list_cntx->current_account_signature_info.image_num);
    mmi_email_entry_edit_account_entry_signature_screen(p_account_list_cntx);
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ENTRY_SIGNATURE_PROCESS_END:
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_signature_proc
* DESCRIPTION
*  The procedure function of edit_account_signature_group_id
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_entry_signature_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->evt_id)
    {
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_email_entry_edit_account_signature_tap_callback);
#endif /* #if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__) */
        break;

    case EVT_ID_CUI_INLINE_NOTIFY:
        mmi_email_entry_edit_account_signature_proc_handle_cui_inline_notify_message((cui_event_inline_notify_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        mmi_email_entry_edit_account_signature_img_csk_hdlr(((cui_event_inline_submit_struct*)p_event)->item_id);
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        mmi_email_entry_edit_signature_account_proc_handle_cui_inline_abort_message((cui_event_inline_abort_struct*)p_event);
        break;

    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        mmi_email_entry_edit_signature_account_proc_handle_cui_inline_deinit_message((cui_event_inline_common_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_email_entry_edit_account_signature_proc_handle_cui_menu_list_entry_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_select_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_close_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        mmi_email_entry_edit_account_signature_proc_handle_cui_file_selector_message((cui_file_selector_result_event_struct*)p_event);
        break;

#ifdef __MMI_IMAGE_VIEWER__
    case EVT_ID_IMGVIEW_CLOSE_GID:
        mmi_email_entry_edit_account_signature_proc_handle_cui_imageview_close_message((mmi_group_event_struct*)p_event);
        break;
#endif /*#ifdef __MMI_IMAGE_VIEWER__*/

    case EVT_ID_GROUP_FOCUSED:
        mmi_email_set_active_group_id(((mmi_email_account_list_cntx_struct*)p_event->user_data)->edit_account_signature_group_id);
        break;

    case EVT_ID_ALERT_QUIT:
        mmi_email_entry_edit_account_signature_proc_handle_alert_quit_message((mmi_alert_result_evt_struct*)p_event);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}


#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
static void mmi_email_entry_edit_account_signature_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    if (index == 3)
    {
        mmi_email_entry_edit_account_signature_img_csk_hdlr(MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID);
    }
}
#endif /* #if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_proc_handle_cui_inline_notify_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_NOTIFY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_NOTIFY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_proc_handle_cui_inline_notify_message(cui_event_inline_notify_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    switch (p_event->event_type)
    {
        case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
            if (p_event->item_id == MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID)
            {
                set_softkey_label((UI_string_type)GetString(STR_GLOBAL_OPTIONS), MMI_LEFT_SOFTKEY);
                SetLeftSoftkeyFunction(mmi_email_entry_edit_account_signature_select_options, KEY_EVENT_UP);

                cui_inline_set_softkey_icon(p_event->sender_id, (U16)(p_event->item_id), MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
                //SetCenterSoftkeyFunction(mmi_email_entry_edit_account_signature_img_csk_hdlr, KEY_EVENT_UP);
            }
            break;

        case CUI_INLINE_NOTIFY_IMAGE_TEXT_PEN_DOWN:
            if (p_event->item_id == MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID)
            {
                mmi_email_entry_edit_account_signature_img_csk_hdlr(MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID);
            }
            break;

        default:
            break;

    }

}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_save
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_SUBMIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_SUBMIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = mmi_email_account_list_p->edit_account_signature_group_id;
    confirm_struct.user_tag = (void*)MMI_EMAIL_ACCOUNT_ALERT_SAVE_SIGNATURE;
    mmi_confirm_display((WCHAR*)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &confirm_struct);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_signature_account_proc_handle_cui_inline_abort_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_ABORT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_signature_account_proc_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_signature_account_proc_handle_cui_inline_deinit_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_INLINE_GROUP_DEINIT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_INLINE_ABORT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_signature_account_proc_handle_cui_inline_deinit_message(cui_event_inline_common_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_proc_handle_cui_menu_list_entry_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_LIST_ENTRY
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_LIST_ENTRY event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_proc_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    
    switch (p_event->parent_menu_id)
    {
        case MENU_ID_EMAIL_SIG_ATTCH_OPT:
        {
            if (0 == mmi_wcslen((const WCHAR*)(p_account_list_cntx->sig_file_path)))
            {
#ifdef __MMI_IMAGE_VIEWER__
                cui_menu_set_item_hidden(p_event->sender_id, MENU_ID_EMAIL_SIG_ATTCH_OPT_VIEW, MMI_TRUE);
#endif /* __MMI_IMAGE_VIEWER__ */
                cui_menu_set_item_hidden(p_event->sender_id, MENU_ID_EMAIL_SIG_ATTCH_OPT_DEL, MMI_TRUE);
            }
            break;
        }

        default:
            break;
    }
}

void mmi_email_entry_edit_account_signature_img_csk_hdlr(S16 item_id)
{
    if (item_id == MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID)
    {
        if (mmi_wcslen(mmi_email_account_list_p->sig_file_path) > 0)
        {
#ifdef __MMI_IMAGE_VIEWER__
            mmi_email_entry_edit_account_signature_view_img(mmi_email_account_list_p);
#else /* __MMI_IMAGE_VIEWER__ */
            mmi_email_entry_edit_account_signature_opt_select_file(mmi_email_account_list_p);
#endif /* __MMI_IMAGE_VIEWER__ */
        }
        else
        {
            mmi_email_entry_edit_account_signature_opt_select_file(mmi_email_account_list_p);
        }
    }
    else
    {
        //Save
        mmi_email_entry_edit_account_signature_save();
    }
}

#ifdef __MMI_IMAGE_VIEWER__
void mmi_email_entry_edit_account_signature_view_img(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    mmi_id imageviewer_id = GRP_ID_INVALID;
    WCHAR *sig_image_path = NULL;
    FS_HANDLE fs_handle;

    fs_handle = FS_Open(p_account_list_cntx->sig_file_path, FS_READ_ONLY);
    if (fs_handle < 0)
    {
        mmi_email_util_display_popup(
            0,
            GetString((U16)srv_fmgr_fs_error_get_string(fs_handle)),
            MMI_EVENT_FAILURE);
            return;
    }
    else
    {
        FS_Close(fs_handle);
    }

    imageviewer_id = cui_imgview_create(p_account_list_cntx->edit_account_signature_group_id);

    cui_imgview_set_mode_filename(imageviewer_id, (CHAR*)p_account_list_cntx->sig_file_path);
    cui_imgview_set_title(
        imageviewer_id, 
        p_account_list_cntx->p_image_file_title, 
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN));
    cui_imgview_set_ui_direction(imageviewer_id, CUI_IMGVIEW_UI_DIRECTION_VERTICAL);
    cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_ALL, MMI_FALSE);   
    cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_ZOOM, MMI_TRUE);   
    cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_IMG_ROTATE, MMI_TRUE);   
    cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_UI_ROTATE, MMI_TRUE);   
    cui_imgview_set_display_cap(imageviewer_id, CUI_IMGVIEW_CAP_TITLE, MMI_TRUE);   

    cui_imgview_run(imageviewer_id);

    if (NULL != sig_image_path)
    {
        OslMfree(sig_image_path);
        sig_image_path = NULL;
    }
}
#endif /* __MMI_IMAGE_VIEWER__ */


static void mmi_email_entry_edit_account_signature_opt_select_file(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    FMGR_FILTER filter;
    U32 option_flag = CUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON |
        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_UNKNOWN |
        CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON;
    mmi_id file_selector_id = GRP_ID_INVALID;

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    file_selector_id = cui_file_selector_create(
        p_account_list_cntx->edit_account_signature_group_id, 
        L"root", 
        (const FMGR_FILTER*)&filter, 
        CUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
        option_flag);
    cui_file_selector_set_title(
        file_selector_id,
        0,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN));
    cui_file_selector_run(file_selector_id);
}

static void mmi_email_entry_edit_account_signature_opt_del(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    //U8 *string_array[] = {NULL, NULL};
    //S32 index = 0;
    U16 string_id = STR_EMAIL_COMMON_DELETED_ID;
    mmi_event_notify_enum notify_value = MMI_EVENT_SUCCESS;

    //if (p_account_list_cntx->current_account_signature_info.image_num > 0)
    if (p_account_list_cntx->sig_file_path[0] != 0)
    {
        cui_inline_set_value(
            p_account_list_cntx->account_signature_id, 
            MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID, 
            GetString(STR_GLOBAL_NONE));

        cui_inline_set_screen_attributes(
            p_account_list_cntx->account_signature_id, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_SCREEN_CHANGED);

        memset(&p_account_list_cntx->sig_file_info, 0, sizeof(srv_fmgr_fileinfo_struct));
        memset(p_account_list_cntx->sig_file_path, 0, sizeof(p_account_list_cntx->sig_file_path));
        p_account_list_cntx->p_image_file_title = NULL;

        mmi_popup_display_simple(
            (WCHAR*)GetString(string_id), 
            notify_value, 
            p_account_list_cntx->edit_account_signature_group_id, 
            0);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_select_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_ITEM_SELECT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_ITEM_SELECT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_select_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);
    
    switch (p_event->highlighted_menu_id)
    {
#ifdef __MMI_IMAGE_VIEWER__
        case MENU_ID_EMAIL_SIG_ATTCH_OPT_VIEW:
            mmi_email_entry_edit_account_signature_view_img(p_account_list_cntx);
            break;
#endif /* __MMI_IMAGE_VIEWER__ */

        case MENU_ID_EMAIL_SIG_ATTCH_OPT_SEL:
            mmi_email_entry_edit_account_signature_opt_select_file(p_account_list_cntx);
            break;

        case MENU_ID_EMAIL_SIG_ATTCH_OPT_DEL:
            mmi_email_entry_edit_account_signature_opt_del(p_account_list_cntx);
            break;

        case MENU_ID_EMAIL_SIG_ATTCH_OPT_SAVE:
            mmi_email_entry_edit_account_signature_save();
            break;

        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_close_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_MENU_CLOSE_REQUEST
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_MENU_CLOSE_REQUEST event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_proc_handle_cui_menu_item_close_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(p_event->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_proc_handle_cui_file_selector_message
* DESCRIPTION
*  The handle function of EVT_ID_CUI_FILE_SELECTOR_RESULT
* PARAMETERS
*  p_event   [IN] EVT_ID_CUI_FILE_SELECTOR_RESULT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_proc_handle_cui_file_selector_message(cui_file_selector_result_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    srv_fmgr_fileinfo_struct selected_file_info;
    WCHAR *p_origin_file_path = NULL;
#ifdef __DRM_SUPPORT__
    S32 mime_type = 0, mime_subtype = 0;
    S32 fwd_flag = 0;
    MMI_BOOL is_drm = MMI_FALSE;
#endif /* __DRM_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_account_list_cntx = (mmi_email_account_list_cntx_struct*)(p_event->user_data);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SIGNATURE_FILE_SELECT_RESULT, p_event->result);
    if (p_event->result > 0)
    {
        WCHAR *p_file_name = NULL;
       // U8 *string_array[] = {NULL, NULL};
       // S32 index = 0;

        p_origin_file_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
        memcpy(p_origin_file_path, p_account_list_cntx->sig_file_path, sizeof(p_account_list_cntx->sig_file_path));
    
        cui_file_selector_get_selected_filepath(
            p_event->sender_id, 
            &(p_account_list_cntx->sig_file_info), 
            p_account_list_cntx->sig_file_path, 
            sizeof(p_account_list_cntx->sig_file_path));
        p_file_name = srv_fmgr_path_get_filename_ptr(p_account_list_cntx->sig_file_path);

        /* Check whether the file size id too large */
        if (0 == srv_fmgr_fs_path_get_fileinfo(p_account_list_cntx->sig_file_path, &selected_file_info))
        {
            if (0 == selected_file_info.size)
            {
                memcpy(p_account_list_cntx->sig_file_path, p_origin_file_path, sizeof(p_account_list_cntx->sig_file_path));

                mmi_email_lib_error_popup(STR_EMAIL_EMPTY_FILE_ID);
                goto MMI_EMAIL_SIGNATURE_SELECT_FILE_RESULT_END;
            }
            if (selected_file_info.size > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
            {
                memcpy(p_account_list_cntx->sig_file_path, p_origin_file_path, sizeof(p_account_list_cntx->sig_file_path));

                /* use the p_origin_file_path to store the display info */
                kal_wsprintf(
                    p_origin_file_path,
                    "%uKB %w",
                    (U32)(MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE) / 1024,
                    (WCHAR*)GetString(STR_EMAIL_SIZE_TOO_LARGE));
                mmi_popup_display_simple(
                    p_origin_file_path, 
                    MMI_EVENT_FAILURE, 
                    p_account_list_cntx->edit_account_signature_group_id, 
                    0);
                goto MMI_EMAIL_SIGNATURE_SELECT_FILE_RESULT_END;
            }
        }
        
    #ifdef __DRM_SUPPORT__
        mmi_email_util_get_mine_type(p_account_list_cntx->sig_file_path, &mime_type, &mime_subtype);
        if (mime_subtype == MIME_SUBTYPE_DRM_MESSAGE)
        {
            is_drm = MMI_TRUE;
        }
        fwd_flag = mmi_rmgr_check_forward((U16*)p_account_list_cntx->sig_file_path);
        if (!(fwd_flag & MMI_RMGR_USAGE_SEND))
        {
            is_drm = MMI_TRUE;
        }
        if (MMI_TRUE == is_drm)
        {
            memcpy(p_account_list_cntx->sig_file_path, p_origin_file_path, sizeof(p_account_list_cntx->sig_file_path));
            mmi_email_lib_error_popup(STR_GLOBAL_DRM_PROHIBITED);
        }
        else
    #endif /* __DRM_SUPPORT__ */
        {
            cui_inline_set_value(
                p_account_list_cntx->account_signature_id, 
                MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID, 
                p_file_name);

            cui_inline_set_screen_attributes(
                p_account_list_cntx->account_signature_id, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);

            /* Change the display image file name */
            p_account_list_cntx->p_image_file_title = p_file_name;

            cui_file_selector_close(p_event->sender_id);
        }
    
    MMI_EMAIL_SIGNATURE_SELECT_FILE_RESULT_END:
        if (NULL != p_origin_file_path)
        {
            OslMfree(p_origin_file_path);
            p_origin_file_path = NULL;
        }
    }
    else if (p_event->result < 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString((U16)srv_fmgr_fs_error_get_string(p_event->result)), 
            MMI_EVENT_FAILURE, 
            p_account_list_cntx->edit_account_signature_group_id, 
            0);
        cui_file_selector_close(p_event->sender_id);
    }
    else // noting selected
    {
        cui_file_selector_close(p_event->sender_id);
    }
    return;
}

#ifdef __MMI_IMAGE_VIEWER__
/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_proc_handle_cui_imageview_close_message
* DESCRIPTION
*  The handle function of EVT_ID_IMGVIEW_CLOSE_GID
* PARAMETERS
*  p_event   [IN] EVT_ID_IMGVIEW_CLOSE_GID event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_proc_handle_cui_imageview_close_message(mmi_group_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_imgview_close(p_event->sender_id);
    return;
}
#endif /*#ifdef __MMI_IMAGE_VIEWER__*/

/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_proc_handle_alert_quit_message
* DESCRIPTION
*  The handle function of EVT_ID_ALERT_QUIT
* PARAMETERS
*  p_event   [IN] EVT_ID_ALERT_QUIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
        case MMI_EMAIL_ACCOUNT_ALERT_SAVE_SIGNATURE:
        {
            if (MMI_ALERT_CNFM_YES == p_event->result)
            {
                mmi_email_entry_edit_account_save_signature_lsk_handler();
            }
            else if (MMI_ALERT_CNFM_NO == p_event->result)
            {
                mmi_email_entry_edit_account_save_signature_rsk_handler();
            }
        }
        default:
        {
            break;
        }
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_entry_signature_screen
* DESCRIPTION
*  Entry editing signature screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_entry_signature_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_struct;

    cui_inline_item_softkey_struct softkey_struct = {{
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}};
        
    cui_inline_set_item_struct *inline_item = NULL;
    cui_inline_item_caption_struct caption_struct[MMI_EMAIL_SIGNATURE_EDIT_CAPTION_ITEMS_NUMBER];
    cui_inline_item_select_struct select_struct[MMI_EMAIL_SIGNATURE_EDIT_SELECT_ITEMS_NUMBER];
#ifdef __MMI_FTE_SUPPORT__
    cui_inline_item_display_only_struct image_item = {0};
#else /* __MMI_FTE_SUPPORT__ */
    cui_inline_item_image_text_struct image_item = {0};
#endif /* __MMI_FTE_SUPPORT__ */
    cui_inline_item_fullscreen_edit_struct fullscreen_edit_struct[MMI_EMAIL_SIGNATURE_EDIT_FULL_SCREEN_ITEMS_NUMBER];

    U16 signature_status_string_id_array[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
    CHAR* image_string = NULL;

    S32 inline_item_index = 0;
    S32 caption_index = 0;
    S32 select_index = 0;
    S32 fullscreen_index = 0;

    U16 email_icon = 0;
    mmi_id inline_id = GRP_ID_INVALID;
    U8 select_value = 0;

    //S32 string_id_array_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_item = OslMalloc(MMI_EMAIL_SIGNATURE_EDIT_ITEMS_NUMBER * sizeof(cui_inline_set_item_struct));
    
    email_icon = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);

    /* signature status part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_SIGNATURE_ON_OFF_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_SIGNATURE_EDIT_STATUS_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_STATUS, 
        &caption_struct[caption_index++]);

    if (MMI_FALSE == p_account_list_cntx->current_account_signature_status)
    {
        select_value = 0;
    }
    else
    {
        select_value = 1;
    }
    mmi_email_account_init_select_struct(
        &select_struct[select_index], 
        sizeof(signature_status_string_id_array) / sizeof(U16), 
        select_value, 
        signature_status_string_id_array);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_SIGNATURE_EDIT_STATUS_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_SELECT, 
        0, 
        &select_struct[select_index++]);

    /* signature status part end */

    /* signature image part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_SIGNATURE_IMAGE_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_SIGNATURE_IMAGE_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++],
        MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID,
        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,
        0,
        &image_item);

#ifndef __MMI_FTE_SUPPORT__
        image_item.image1_id = 0;
        if (!r2lMMIFlag)
        {
            image_item.image2_id = 0;
            image_item.image3_id = RIGHT_RED_ARROW;
        }
        else
        {
            image_item.image2_id = RIGHT_RED_ARROW;
            image_item.image3_id = 0;
        }
#endif /* __MMI_FTE_SUPPORT__ */

    /* signature image part end */
    
    /* signature text part begin */
    caption_struct[caption_index].string_id = STR_EMAIL_SIGNATURE_TEXT_ID;
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_SIGNATURE_EDIT_TEXT_CAPTION_ID, 
        CUI_INLINE_ITEM_TYPE_CAPTION, 
        IMG_EMAIL_SIGNATURE_TEXT_ID, 
        &caption_struct[caption_index++]);

    mmi_email_account_init_fullscreen_edit_struct(
        &fullscreen_edit_struct[fullscreen_index], 
        0, 
        0, 
        STR_EMAIL_SIGNATURE_TEXT_ID, 
        email_icon, 
        0, 
        IMM_INPUT_TYPE_SENTENCE, 
        (MMI_EMAIL_SIG_MAX_TEXT_LEN + 1),
        NULL);
    mmi_email_account_init_inline_item_struct(
        &inline_item[inline_item_index++], 
        MMI_EMAIL_SIGNATURE_EDIT_TEXT_CONTENT_ID, 
        CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 
        0, 
        &fullscreen_edit_struct[fullscreen_index++]);
    /* signature text part end */

    inline_struct.items_count = MMI_EMAIL_SIGNATURE_EDIT_ITEMS_NUMBER;
    inline_struct.title = STR_EMAIL_SIGNATURE_ID;
    inline_struct.title_icon = email_icon;
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE;
    inline_struct.softkey = &softkey_struct;
    inline_struct.items = inline_item;

    inline_id = cui_inline_create(p_account_list_cntx->edit_account_signature_group_id, &inline_struct);
    cui_inline_run(inline_id);

    p_account_list_cntx->account_signature_id = inline_id;

    cui_inline_set_value(inline_id, MMI_EMAIL_SIGNATURE_EDIT_TEXT_CONTENT_ID, p_account_list_cntx->sig_text);

    if (p_account_list_cntx->current_account_signature_info.image_num > 0)
    {
        image_string = (CHAR*)p_account_list_cntx->current_account_signature_info.image_name[0];
    }
    else
    {
        image_string = GetString(STR_GLOBAL_NONE);
    }
    cui_inline_set_value(
        inline_id, 
        MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID, 
        image_string);

    if (NULL != inline_item)
    {
        OslMfree(inline_item);
        inline_item = NULL;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_select_options
* DESCRIPTION
*  Entry signature select option process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_select_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_entry_edit_account_signature_select_options_screen(mmi_email_account_list_p);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_signature_select_options_screen
* DESCRIPTION
*  Entry signature select option screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_signature_select_options_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id signature_option_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    signature_option_id = cui_menu_create(
                    p_account_list_cntx->edit_account_signature_group_id, 
                    CUI_MENU_SRC_TYPE_RESOURCE,
                    CUI_MENU_TYPE_OPTION,
                    MENU_ID_EMAIL_SIG_ATTCH_OPT,
                    MMI_FALSE,
                    (void*)(p_account_list_cntx));
    cui_menu_set_default_title(signature_option_id, NULL, get_image(GetRootTitleIcon(MENU_ID_EMAIL_MAIN)));
    cui_menu_run(signature_option_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_signature_lsk_handler
* DESCRIPTION
*  Save the signature information lsk handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_signature_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *p_sig_text = NULL;
    S32 status_highlight_index = 0;
    MMI_BOOL signature_status = MMI_FALSE;
    MMI_BOOL operate_done = MMI_TRUE;
    U16 string_id = STR_GLOBAL_SAVED;
    mmi_event_notify_enum event_id = MMI_EVENT_SUCCESS;
    S32 app_core_op_result = MMI_EMAIL_FAIL;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_SCREEN_LOG1);

    /* save status */
    cui_inline_get_value(
        mmi_email_account_list_p->account_signature_id,
        MMI_EMAIL_SIGNATURE_EDIT_STATUS_CONTENT_ID, 
        &status_highlight_index);
    if (0 == status_highlight_index)
    {
        signature_status = MMI_FALSE;
    }
    else
    {
        signature_status = MMI_TRUE;
    }
    if (MMI_EMAIL_SUCCESS != mmi_email_sig_set_status(
                                mmi_email_account_list_p->current_account_id, 
                                signature_status))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_SCREEN_ERROR_LOG1, mmi_email_account_list_p->current_account_id, signature_status);
        string_id = srv_fmgr_fs_error_get_string(mmi_email_app_core_get_fs_error_detail());
        event_id = MMI_EVENT_FAILURE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_LSK_HANDLER_END;
    }
    else
    {
    }
    
    /* save text */
    p_sig_text = OslMalloc((MMI_EMAIL_SIG_MAX_TEXT_LEN + 1) * sizeof(WCHAR));
	memset(p_sig_text, 0, (MMI_EMAIL_SIG_MAX_TEXT_LEN + 1) * sizeof(WCHAR));
    cui_inline_get_value(
        mmi_email_account_list_p->account_signature_id, 
        MMI_EMAIL_SIGNATURE_EDIT_TEXT_CONTENT_ID, 
        p_sig_text);
    if (0 != mmi_wcslen(p_sig_text))
    {
        if (MMI_EMAIL_SUCCESS != mmi_email_sig_set_text(
                                    mmi_email_account_list_p->current_account_id, 
                                    p_sig_text, 
                                    (MMI_EMAIL_SIG_MAX_TEXT_LEN + 1)))
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_SCREEN_ERROR_LOG2, mmi_email_account_list_p->current_account_id);
            string_id = srv_fmgr_fs_error_get_string(mmi_email_app_core_get_fs_error_detail());;
            event_id = MMI_EVENT_FAILURE;
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_LSK_HANDLER_END;
        }
        else
        {
        }
    }
    else
    {
        if (MMI_EMAIL_SUCCESS != mmi_email_sig_clear_text(mmi_email_account_list_p->current_account_id))
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_SCREEN_ERROR_LOG5, mmi_email_account_list_p->current_account_id);
            string_id = srv_fmgr_fs_error_get_string(mmi_email_app_core_get_fs_error_detail());;
            event_id = MMI_EVENT_FAILURE;
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_LSK_HANDLER_END;
        }
        else
        {
        }
    }

    if (0 != mmi_wcslen(mmi_email_account_list_p->sig_file_path))
    {
            if (mmi_email_account_list_p->current_account_signature_info.image_num > 0)
            {
                app_core_op_result = mmi_email_sig_edit_image(
                                        mmi_email_account_list_p->current_account_id,
                                        0,
                                        mmi_email_account_list_p->sig_file_path, 
                                        mmi_email_entry_edit_account_edit_signature_image_callback, 
                                        mmi_email_account_list_p);
            }
            else
            {
                app_core_op_result = mmi_email_sig_add_image(
                                        mmi_email_account_list_p->current_account_id,
                                        mmi_email_account_list_p->sig_file_path, 
                                        mmi_email_entry_edit_account_edit_signature_image_callback, 
                                        mmi_email_account_list_p);
            }

            if ((MMI_EMAIL_SUCCESS != app_core_op_result) && (MMI_EMAIL_WOULDBLOCK != app_core_op_result))
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_SCREEN_ERROR_LOG4, mmi_email_account_list_p->current_account_id, app_core_op_result, mmi_email_account_list_p->current_account_signature_info.image_num);
                if (app_core_op_result < 0)
                {
                    string_id = srv_fmgr_fs_error_get_string(app_core_op_result);
                }
                else
                {
                    string_id = srv_fmgr_fs_error_get_string(mmi_email_app_core_get_fs_error_detail());;;
                }
                event_id = MMI_EVENT_FAILURE;
                goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_LSK_HANDLER_END;
            }
            else
            {
                if (MMI_EMAIL_WOULDBLOCK == app_core_op_result)
                {
                    mmi_frm_scrn_first_enter(
                        mmi_email_account_list_p->edit_account_signature_group_id, 
                        SCR_ID_EMAIL_PROGRESS, 
                        (FuncPtr)mmi_email_entry_edit_account_save_signature_screen, 
                        mmi_email_account_list_p);
                    operate_done = MMI_FALSE;
                }
            }
    }
    else
    {
        if (mmi_email_account_list_p->current_account_signature_info.image_num > 0)
        {
            app_core_op_result = mmi_email_sig_delete_image(mmi_email_account_list_p->current_account_id, 0);
            if (MMI_EMAIL_SUCCESS != app_core_op_result)
            {
                goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_LSK_HANDLER_END;
            }
            
            /* refresh the signature information */
            app_core_op_result = mmi_email_sig_get_signature(
                            mmi_email_account_list_p->current_account_id, 
                            &(mmi_email_account_list_p->current_account_signature_info));
            if (MMI_EMAIL_SUCCESS != app_core_op_result)
            {
                goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_LSK_HANDLER_END;
            }
        }
    }

MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_SIGNATURE_LSK_HANDLER_END:
    if (NULL != p_sig_text)
    {
        OslMfree(p_sig_text);
        p_sig_text = NULL;
    }
    if (MMI_TRUE == operate_done)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(string_id), 
            event_id, 
            mmi_email_account_list_p->edit_account_signature_group_id, 
            0);
    }
    cui_inline_close(mmi_email_account_list_p->account_signature_id);
    mmi_email_account_list_p->account_signature_id = GRP_ID_INVALID;
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_signature_screen
* DESCRIPTION
*  Entry save signature procgressing screen
* PARAMETERS
*  p_screen_data  [IN] The screen data
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_edit_account_save_signature_screen(mmi_scrn_essential_struct *p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id, 
                        p_screen_data->scrn_id, 
                        NULL, 
                        (FuncPtr)mmi_email_entry_edit_account_save_signature_screen, 
                        MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        ShowCategory66Screen(
            STR_GLOBAL_EMAIL,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            0,
            0,
            (U8*)GetString(STR_GLOBAL_SAVING),
            mmi_email_lib_get_progress_img_id(),
            guiBuffer);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_edit_signature_image_callback
* DESCRIPTION
*  The callback of editing image
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_edit_signature_image_callback(
                S32 edit_image_result, 
                void *p_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    U16 string_id = STR_GLOBAL_SAVED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_EDIT_SIGNATURE_IMAGE_CALLBACK, edit_image_result);
    p_account_list_cntx = p_user_data;
    
    if (MMI_EMAIL_SUCCESS != edit_image_result)
    {
        if (edit_image_result < 0)
        {
            string_id = srv_fmgr_fs_error_get_string(edit_image_result);
        }
        else
        {
            string_id = STR_GLOBAL_ERROR;
        }
        mmi_email_lib_error_popup(string_id);
    }

    mmi_frm_scrn_close(p_account_list_cntx->edit_account_signature_group_id, SCR_ID_EMAIL_PROGRESS);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_signature_rsk_handler
* DESCRIPTION
*  Save the signature information rsk handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_edit_account_save_signature_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(mmi_email_account_list_p->account_signature_id);
    mmi_email_account_list_p->account_signature_id = GRP_ID_INVALID;
    mmi_frm_scrn_close_active_id();
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_delete_account_process
* DESCRIPTION
*  Entry delete a account process
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_delete_account_process(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_DELETE_ACCOUNT_PROCESS);
    mmi_frm_group_create(
        p_account_list_cntx->group_id, 
        p_account_list_cntx->delete_account_group_id, 
        mmi_email_entry_delete_account_proc, 
        p_account_list_cntx);
    mmi_frm_group_enter(p_account_list_cntx->delete_account_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_email_entry_delete_account_screen(p_account_list_cntx);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_delete_account_proc
* DESCRIPTION
*  The procedure function of GPR_ID_EMAIL_ACCOUNT_DELETE
* PARAMETERS
*  p_event  [IN] The input event
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_delete_account_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_email_entry_delete_account_proc_handle_alert_quit_message((mmi_alert_result_evt_struct*)p_event);
            break;
        }
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_delete_account_proc_handle_alert_quit_message
* DESCRIPTION
*  The handle function of EVT_ID_ALERT_QUIT
* PARAMETERS
*  p_event   [IN] EVT_ID_ALERT_QUIT event structure
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_delete_account_proc_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_tag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_tag = (U32)p_event->user_tag;
    switch (user_tag)
    {
        case MMI_EMAIL_ACCOUNT_ALERT_DELETE_ACCOUNT:
        {
            if (MMI_ALERT_CNFM_YES == p_event->result)
            {
                mmi_email_delete_account_operation();
            }
            else if (MMI_ALERT_CNFM_NO == p_event->result)
            {
                mmi_frm_scrn_close_active_id();
            }
        }
        default:
        {
            break;
        }
    }
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_delete_account_screen
* DESCRIPTION
*  Entry delete a account screen
* PARAMETERS
*  p_account_list_cntx  [IN] The context of mmi_email_account_list_cntx_struct
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_entry_delete_account_screen(mmi_email_account_list_cntx_struct *p_account_list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_struct, CNFM_TYPE_YESNO);
    confirm_struct.parent_id = p_account_list_cntx->delete_account_group_id;
    confirm_struct.user_tag = (void*)MMI_EMAIL_ACCOUNT_ALERT_DELETE_ACCOUNT;
    confirm_struct.f_auto_map_empty_softkey = 0;
    mmi_confirm_display((WCHAR*)GetString(STR_EMAIL_DEL_ACCT_ID), MMI_EVENT_QUERY, &confirm_struct);

    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_delete_account_operation
* DESCRIPTION
*  Delete a account
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_delete_account_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_rsult = SRV_EMAIL_RESULT_SUCC;
    MMI_BOOL delete_result = MMI_TRUE;
    mmi_email_app_core_result_enum app_core_result = MMI_EMAIL_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_DELETE_ACCOUNT_OPERATION_LOG1, mmi_email_account_list_p->current_account_id);

    mmi_email_app_nwk_delaccount(mmi_email_account_list_p->current_account_id);
    srv_op_rsult = srv_email_acct_delete(mmi_email_account_list_p->current_account_id);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_rsult)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_DELETE_ACCOUNT_OPERATION_ERROR_LOG2, srv_op_rsult);
        delete_result = MMI_FALSE;
    }
    else
    {
        mmi_email_smgr_account_del(mmi_email_account_list_p->current_account_id);
    }

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    app_core_result = mmi_email_auto_check_delete_acct(
                        mmi_email_account_list_p->current_account_id, 
                        MMI_TRUE);
    if (MMI_EMAIL_SUCCESS != app_core_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_DELETE_ACCOUNT_OPERATION_LOG3, app_core_result);
    }
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

    app_core_result = mmi_email_sig_delete_acct(
                        mmi_email_account_list_p->current_account_id, 
                        MMI_TRUE);
    if (MMI_EMAIL_SUCCESS != app_core_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_DELETE_ACCOUNT_OPERATION_LOG4, app_core_result);
    }

    if (MMI_FALSE == mmi_email_entry_edit_account_delete_account_extra_info(
                        mmi_email_account_list_p->current_account_id, 
                        NULL))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_DELETE_ACCOUNT_OPERATION_LOG5);
    }
    
    if (MMI_FALSE == delete_result)
    {
        mmi_email_util_display_error_popup(mmi_email_account_list_p->delete_account_group_id, srv_op_rsult);
    }
    else
    {
        //mmi_email_lib_succ_popup(STR_GLOBAL_DELETED);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_delete_account_progress_screen
* DESCRIPTION
*  Delete account progress screen
* PARAMETERS
*  p_screen_data  [IN] The screen data
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_email_delete_account_progress_screen(mmi_scrn_essential_struct *p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id, 
                        p_screen_data->scrn_id, 
                        NULL, 
                        (FuncPtr)mmi_email_delete_account_progress_screen, 
                        MMI_FRM_FULL_SCRN))
    {
        p_account_list_cntx = p_screen_data->user_data;
        p_account_list_cntx->state = MMI_EMAIL_ACCOUNT_LIST_STATE_DELETE_ACCOUNT;
        
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        ShowCategory66Screen(
            STR_GLOBAL_EMAIL,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*)GetString(STR_GLOBAL_DELETING),
            mmi_email_lib_get_progress_img_id(),
            guiBuffer);
        SetRightSoftkeyFunction(mmi_email_cancel_delete_account_progress, KEY_EVENT_UP);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_DELETE_ACCOUNT_PROGRESS_SCREEN, p_account_list_cntx->state);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_cancel_delete_account_progress
* DESCRIPTION
*  Cancel delete account progress
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_cancel_delete_account_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_CANCEL_DELETE_ACCOUNT_PROGRESS_LOG1, mmi_email_account_list_p->state, mmi_email_account_list_p->current_req_id);
    if (MMI_EMAIL_ACCOUNT_LIST_STATE_DELETE_ACCOUNT == mmi_email_account_list_p->state)
    {
        srv_op_result = (srv_email_result_enum)0;//srv_email_acct_delete_abort(mmi_email_account_list_p->current_req_id);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_CANCEL_DELETE_ACCOUNT_PROGRESS_LOG2, srv_op_result);
        if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
        {
            //mmi_email_lib_succ_popup(STR_EMAIL_CANCELED_ID);
        }
        else
        {
            mmi_email_util_display_error_popup(mmi_email_account_list_p->delete_account_group_id, srv_op_result);
        }
        mmi_frm_scrn_close(mmi_email_account_list_p->delete_account_group_id, SCR_ID_EMAIL_PROGRESS);
        mmi_email_account_list_p->state = MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE;
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_add_account_extra_info
* DESCRIPTION
*  Add a account extra info
* PARAMETERS
*  p_extra_info   [IN]
*  p_fs_error     [OUT]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_email_entry_edit_account_add_account_extra_info(
            mmi_email_account_extra_info_struct *p_extra_info,
            S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = -1;
    S32 fs_error = FS_NO_ERROR;
    U32 file_size = 0;
    U32 length = 0;
    S32 count = 0;
    mmi_email_account_extra_info_file_node_struct *p_info_array = NULL;
    mmi_email_account_extra_info_file_node_struct *p_info_data = NULL;
    MMI_BOOL return_value = MMI_TRUE;
    mmi_email_account_extra_info_file *p_extra_info_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_LOG1);
    file_size = sizeof(mmi_email_account_extra_info_file);
    p_extra_info_file = OslMalloc(file_size);
    
    file_handle = FS_Open(mmi_email_account_list_p->account_file_path, FS_READ_WRITE);

    if (file_handle >= 0)
    {
        fs_error = FS_Read(file_handle, p_extra_info_file, file_size, &length);
        if (FS_NO_ERROR != fs_error)
        {
            return_value = MMI_FALSE;
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_END;
        }

        if (MMI_FALSE == mmi_email_entry_edit_account_check_validity_of_extra_info_file(p_extra_info_file))
        {
            mmi_email_entry_edit_account_reset_extra_info_file(file_handle, p_extra_info_file);
        }
        
        p_info_data = p_info_array = p_extra_info_file->extra_info_array;
        
        for (count = 0; count < MMI_EMAIL_MAX_ACCTS; count++)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_LOG2, count, p_info_data->is_valid);
            if (MMI_FALSE == p_info_data->is_valid)
            {
                p_info_data->is_valid = MMI_TRUE;
                memcpy(&p_info_data->extra_info, p_extra_info, sizeof(mmi_email_account_extra_info_struct));
                break;
            }
            p_info_data++;
        }
        
        fs_error = FS_Seek(file_handle, 0, FS_FILE_BEGIN);
        if (fs_error < 0)
        {
            return_value = MMI_FALSE;
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_END;
        }
    }
    else if (FS_FILE_NOT_FOUND == file_handle)
    {
        file_handle = FS_Open(mmi_email_account_list_p->account_file_path, FS_CREATE);
        if (file_handle < 0)
        {
            fs_error = file_handle;
            return_value = MMI_FALSE;
            goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_END;
        }
        else
        {
            p_info_data = p_info_array = p_extra_info_file->extra_info_array;
            
            for (count = 0; count < MMI_EMAIL_MAX_ACCTS; count++)
            {
                p_info_data->is_valid = MMI_FALSE;
                p_info_data++;
            }

            p_info_array->is_valid = MMI_TRUE;
            memcpy(&p_info_array->extra_info, p_extra_info, sizeof(mmi_email_account_extra_info_struct));

        }
    }
    else
    {
        fs_error = file_handle;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_END;
    }

    mmi_email_entry_edit_account_cacl_extra_info_file_check_sum(p_extra_info_file);
    fs_error = FS_Write(file_handle, p_extra_info_file, file_size, &length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_END;
    }
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_END:

    if (NULL != p_extra_info_file)
    {
        OslMfree(p_extra_info_file);
        p_extra_info_file = NULL;
    }

    if (fs_error < 0)
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        if (file_handle >= 0)
        {
            /* no need to check return value */
            FS_Close(file_handle);
        }
    }
    else
    {
        fs_error = FS_Close(file_handle);
        if (FS_NO_ERROR != fs_error)
        {
            return_value = MMI_FALSE;
            if (NULL != p_fs_error)
            {
                *p_fs_error = fs_error;
            }
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_ADD_ACCOUNT_EXTRA_INFO_LOG3, return_value);
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_delete_account_extra_info
* DESCRIPTION
*  Delete a account extra info
* PARAMETERS
*  account_id   [IN]
*  p_fs_error     [OUT]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_email_entry_edit_account_delete_account_extra_info(EMAIL_ACCT_ID account_id, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = -1;
    S32 fs_error = FS_NO_ERROR;
    U32 file_size = 0;
    U32 length = 0;
    S32 count = 0;
    mmi_email_account_extra_info_file_node_struct *p_info_data = NULL;
    MMI_BOOL return_value = MMI_TRUE;
    mmi_email_account_extra_info_file *p_extra_info_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_LOG1, account_id);
    file_size = sizeof(mmi_email_account_extra_info_file);
    p_extra_info_file = OslMalloc(file_size);
    
    file_handle = FS_Open(mmi_email_account_list_p->account_file_path, FS_READ_WRITE);

    if (file_handle < 0)
    {
        fs_error = file_handle;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_END;
    }
    
    fs_error = FS_Read(file_handle, p_extra_info_file, file_size, &length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_END;
    }

    if (MMI_FALSE == mmi_email_entry_edit_account_check_validity_of_extra_info_file(p_extra_info_file))
    {
        mmi_email_entry_edit_account_reset_extra_info_file(file_handle, p_extra_info_file);
        fs_error = FS_ERROR_RESERVED;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_END;
    }
    
    p_info_data = p_extra_info_file->extra_info_array;

    for (count = 0; count < MMI_EMAIL_MAX_ACCTS; count++)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_LOG2, count, p_info_data->extra_info.account_id, p_info_data->is_valid);
        if ((account_id == p_info_data->extra_info.account_id) && (MMI_TRUE == p_info_data->is_valid))
        {
            p_info_data->is_valid = MMI_FALSE;
            break;
        }
        p_info_data++;
    }
    
    fs_error = FS_Seek(file_handle, 0, FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_END;
    }
    
    mmi_email_entry_edit_account_cacl_extra_info_file_check_sum(p_extra_info_file);
    fs_error = FS_Write(file_handle, p_extra_info_file, file_size, &length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_END;
    }

MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_END:
    if (NULL != p_extra_info_file)
    {
        OslMfree(p_extra_info_file);
        p_extra_info_file = NULL;
    }
    
    if (fs_error < 0)
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        if (file_handle >= 0)
        {
            /* no need to check return value */
            FS_Close(file_handle);
        }
    }
    else
    {
        fs_error = FS_Close(file_handle);
        if (FS_NO_ERROR != fs_error)
        {
            return_value = MMI_FALSE;
            if (NULL != p_fs_error)
            {
                *p_fs_error = fs_error;
            }
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_DELETE_ACCOUNT_EXTRA_INFO_LOG3, return_value);
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_read_account_extra_info
* DESCRIPTION
*  Delete a account extra info
* PARAMETERS
*  account_id     [IN]
*  p_extra_info   [OUT]
*  p_fs_error     [OUT]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_email_entry_edit_account_read_account_extra_info(
                    EMAIL_ACCT_ID account_id, 
                    mmi_email_account_extra_info_struct *p_extra_info,
                    S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = -1;
    S32 fs_error = FS_NO_ERROR;
    U32 file_size = 0;
    U32 length = 0;
    S32 count = 0;
    mmi_email_account_extra_info_file_node_struct *p_info_data = NULL;
    MMI_BOOL return_value = MMI_TRUE;
    mmi_email_account_extra_info_file *p_extra_info_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_LOG1, account_id);
    file_size = sizeof(mmi_email_account_extra_info_file);
    p_extra_info_file = OslMalloc(file_size);

    file_handle = FS_Open(mmi_email_account_list_p->account_file_path, FS_READ_WRITE);

    if (file_handle < 0)
    {
        fs_error = file_handle;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_END;
    }

    fs_error = FS_Read(file_handle, p_extra_info_file, file_size, &length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_END;
    }

    if (MMI_FALSE == mmi_email_entry_edit_account_check_validity_of_extra_info_file(p_extra_info_file))
    {
        mmi_email_entry_edit_account_reset_extra_info_file(file_handle, p_extra_info_file);
        fs_error = FS_ERROR_RESERVED;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_END;
    }
    
    p_info_data = p_extra_info_file->extra_info_array;

    for (count = 0; count < MMI_EMAIL_MAX_ACCTS; count++)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_LOG2, count, p_info_data->extra_info.account_id, p_info_data->is_valid);
        if ((account_id == p_info_data->extra_info.account_id) && (MMI_TRUE == p_info_data->is_valid))
        {
            memcpy(p_extra_info, &p_info_data->extra_info, sizeof(mmi_email_account_extra_info_struct));
            break;
        }
        p_info_data++;
    }

    MMI_ASSERT(count < MMI_EMAIL_MAX_ACCTS);
    
    fs_error = FS_Seek(file_handle, 0, FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_END;
    }
    
    mmi_email_entry_edit_account_cacl_extra_info_file_check_sum(p_extra_info_file);
    fs_error = FS_Write(file_handle, p_extra_info_file, file_size, &length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_END;
    }
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_END:
    if (NULL != p_extra_info_file)
    {
        OslMfree(p_extra_info_file);
        p_extra_info_file = NULL;
    }
    
    if (fs_error < 0)
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        if (file_handle >= 0)
        {
            /* no need to check return value */
            FS_Close(file_handle);
        }
    }
    else
    {
        fs_error = FS_Close(file_handle);
        if (FS_NO_ERROR != fs_error)
        {
            return_value = MMI_FALSE;
            if (NULL != p_fs_error)
            {
                *p_fs_error = fs_error;
            }
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_READ_ACCOUNT_EXTRA_INFO_LOG3, return_value);
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_write_account_extra_info
* DESCRIPTION
*  Delete a account extra info
* PARAMETERS
*  account_id     [IN]
*  p_extra_info   [IN]
*  p_fs_error     [OUT]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_email_entry_edit_account_write_account_extra_info(
                    EMAIL_ACCT_ID account_id, 
                    mmi_email_account_extra_info_struct *p_extra_info,
                    S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = -1;
    S32 fs_error = FS_NO_ERROR;
    U32 file_size = 0;
    U32 length = 0;
    S32 count = 0;
    mmi_email_account_extra_info_file_node_struct *p_info_data = NULL;
    MMI_BOOL return_value = MMI_TRUE;
    mmi_email_account_extra_info_file *p_extra_info_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_LOG1, account_id);
    file_size = sizeof(mmi_email_account_extra_info_file);
    p_extra_info_file = OslMalloc(file_size);
    
    file_handle = FS_Open(mmi_email_account_list_p->account_file_path, FS_READ_WRITE);

    if (file_handle < 0)
    {
        fs_error = file_handle;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_END;
    }

    fs_error = FS_Read(file_handle, p_extra_info_file, file_size, &length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_END;
    }

    if (MMI_FALSE == mmi_email_entry_edit_account_check_validity_of_extra_info_file(p_extra_info_file))
    {
        mmi_email_entry_edit_account_reset_extra_info_file(file_handle, p_extra_info_file);
        fs_error = FS_ERROR_RESERVED;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_END;
    }
    
    p_info_data = p_extra_info_file->extra_info_array;

    for (count = 0; count < MMI_EMAIL_MAX_ACCTS; count++)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_LOG2, count, p_info_data->extra_info.account_id, p_info_data->is_valid);
        if ((account_id == p_info_data->extra_info.account_id) && (MMI_TRUE == p_info_data->is_valid))
        {
            memcpy(&p_info_data->extra_info, p_extra_info, sizeof(mmi_email_account_extra_info_struct));
            break;
        }
        p_info_data++;
    }

    MMI_ASSERT(count < MMI_EMAIL_MAX_ACCTS);
    
    fs_error = FS_Seek(file_handle, 0, FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_END;
    }

    mmi_email_entry_edit_account_cacl_extra_info_file_check_sum(p_extra_info_file);
    fs_error = FS_Write(file_handle, p_extra_info_file, file_size, &length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_END;
    }
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_END:
    if (NULL != p_extra_info_file)
    {
        OslMfree(p_extra_info_file);
        p_extra_info_file = NULL;
    }
    
    if (fs_error < 0)
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        if (file_handle >= 0)
        {
            /* no need to check return value */
            FS_Close(file_handle);
        }
    }
    else
    {
        fs_error = FS_Close(file_handle);
        if (FS_NO_ERROR != fs_error)
        {
            return_value = MMI_FALSE;
            if (NULL != p_fs_error)
            {
                *p_fs_error = fs_error;
            }
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_WRITE_ACCOUNT_EXTRA_INFO_LOG3, return_value);
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_list_account_extra_info_id
* DESCRIPTION
*  Delete a account extra info
* PARAMETERS
*  account_id     [IN]
*  p_extra_info   [IN]
*  p_fs_error     [OUT]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_email_entry_edit_account_list_account_extra_info_id(
                    EMAIL_ACCT_ID *p_account_id_array, 
                    U16 *account_id_num,
                    S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = -1;
    S32 fs_error = FS_NO_ERROR;
    U32 file_size = 0;
    U32 length = 0;
    S32 count = 0;
    mmi_email_account_extra_info_file_node_struct *p_info_array = NULL;
    MMI_BOOL return_value = MMI_TRUE;
    mmi_email_account_extra_info_file *p_extra_info_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *account_id_num = 0;
    file_size = sizeof(mmi_email_account_extra_info_file);
    p_extra_info_file = OslMalloc(file_size);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_LIST_ACCOUNT_EXTRA_INFO_ID_LOG1, file_size);
    
    file_handle = FS_Open(mmi_email_account_list_p->account_file_path, FS_READ_ONLY);

    if (file_handle < 0)
    {
        fs_error = file_handle;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_LIST_ACCOUNT_EXTRA_INFO_ID_END;
    }

    fs_error = FS_Read(file_handle, p_extra_info_file, file_size, &length);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_LIST_ACCOUNT_EXTRA_INFO_ID_END;
    }

    if (MMI_FALSE == mmi_email_entry_edit_account_check_validity_of_extra_info_file(p_extra_info_file))
    {
        mmi_email_entry_edit_account_reset_extra_info_file(file_handle, p_extra_info_file);
        fs_error = FS_ERROR_RESERVED;
        return_value = MMI_FALSE;
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_LIST_ACCOUNT_EXTRA_INFO_ID_END;
    }
    
    p_info_array = p_extra_info_file->extra_info_array;

    for (count = 0; count < MMI_EMAIL_MAX_ACCTS; count++)
    {
        if (MMI_TRUE == p_info_array->is_valid)
        {
            *p_account_id_array = p_info_array->extra_info.account_id;
            p_account_id_array++;
            (*account_id_num)++;
        }
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL, 
            MMI_EMAIL_ENTRY_EDIT_ACCOUNT_LIST_ACCOUNT_EXTRA_INFO_ID_LOG2,
            count,
            p_info_array->is_valid,
            p_info_array->extra_info.account_id,
            (*account_id_num));
        p_info_array++;
    }

MMI_EMAIL_ENTRY_EDIT_ACCOUNT_LIST_ACCOUNT_EXTRA_INFO_ID_END:
    if (NULL != p_extra_info_file)
    {
        OslMfree(p_extra_info_file);
        p_extra_info_file = NULL;
    }
    
    if (fs_error < 0)
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        if (file_handle >= 0)
        {
            /* no need to check return value */
            FS_Close(file_handle);
        }
    }
    else
    {
        fs_error = FS_Close(file_handle);
        if (FS_NO_ERROR != fs_error)
        {
            return_value = MMI_FALSE;
            if (NULL != p_fs_error)
            {
                *p_fs_error = fs_error;
            }
        }
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_LIST_ACCOUNT_EXTRA_INFO_ID_LOG3, return_value);
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_edit_account_save_account_info
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  srv_email_result_enum
*****************************************************************************/
static srv_email_result_enum mmi_email_entry_edit_account_save_account_info(
                                EMAIL_SRV_HANDLE srv_handle,
                                EMAIL_ACCT_HANDLE *p_acct_handle,
                                EMAIL_ACCT_ID acct_id,
                                srv_email_acct_info_struct *p_acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_INFO_LOG1, srv_handle, acct_id);

    srv_op_result = srv_email_acct_edit(*p_acct_handle, p_acct_info);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_INFO_ERROR_LOG4);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_INFO_ERROR_END;
    }
    srv_op_result = srv_email_acct_save(*p_acct_handle);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_INFO_ERROR_LOG5);
        goto MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_INFO_ERROR_END;
    }

    return srv_op_result;
    
MMI_EMAIL_ENTRY_EDIT_ACCOUNT_SAVE_ACCOUNT_INFO_ERROR_END:
    return srv_op_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_edit_account_check_validity_of_extra_info_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_email_entry_edit_account_check_validity_of_extra_info_file(mmi_email_account_extra_info_file *p_extra_info_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL return_value = MMI_FALSE;
    U32 check_sum = 0;
    U8 *p_crc_data_begin = NULL;
    U16 crc_data_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	p_crc_data_begin = (U8*)(p_extra_info_file->extra_info_array);
    crc_data_length = (U16)(sizeof(*p_extra_info_file) - (p_crc_data_begin - (U8*)(p_extra_info_file)));

    check_sum = applib_crc_update(MMI_EMAIL_ACCOUNT_EXTRA_INFO_FILE_CHECK_SUM, p_crc_data_begin, crc_data_length);
    if (check_sum == p_extra_info_file->check_sum)
    {
        return_value = MMI_TRUE;
    }
    else
    {
        return_value = MMI_FALSE;
    }
    
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_ENTRY_EDIT_ACCOUNT_CHECK_VALIDITY_OF_EXTRA_INFO_FILE_LOG1, 
        check_sum,
        p_extra_info_file->check_sum,
        return_value);
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_edit_account_reset_extra_info_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_entry_edit_account_reset_extra_info_file(FS_HANDLE file_handle, mmi_email_account_extra_info_file *p_extra_info_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(p_extra_info_file, 0, sizeof(*p_extra_info_file));
    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        p_extra_info_file->extra_info_array[i].is_valid = MMI_FALSE;
    }
    mmi_email_entry_edit_account_cacl_extra_info_file_check_sum(p_extra_info_file);
    FS_Write(file_handle, p_extra_info_file, sizeof(*p_extra_info_file), NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_edit_account_cacl_extra_info_file_check_sum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_entry_edit_account_cacl_extra_info_file_check_sum(mmi_email_account_extra_info_file *p_extra_info_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_extra_info_file->check_sum = applib_crc_update(
                                MMI_EMAIL_ACCOUNT_EXTRA_INFO_FILE_CHECK_SUM, 
                                (U8*)p_extra_info_file->extra_info_array, 
                                (U16)(sizeof(*p_extra_info_file) - ((U8*)p_extra_info_file->extra_info_array - (U8*)(p_extra_info_file))));
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_start_auto_check_service
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_account_start_auto_check_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ACCOUNT_START_AUTO_CHECK_SERVICE_LOG1);
    mmi_email_auto_check_start_service(mmi_email_auto_check_notify_callback);
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_auto_check_notify_callback
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_auto_check_notify_callback(EMAIL_ACCT_ID account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_AUTO_CHECK_NOTIFY_CALLBACK_LOG1, account_id);
   mmi_email_app_nwk_autocheck_do(account_id);
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
    return;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_receive_auto_check_result_handler
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void mmi_email_receive_auto_check_result_handler(mmi_email_batch_receive_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_RECEIVE_AUTO_CHECK_RESULT_HANDLER_LOG1, result->acct_id);

    mmi_email_auto_check_start(result->acct_id);
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_edit_account_create_new_account
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  mmi_email_operate_result_enum
*****************************************************************************/
static mmi_email_operate_result_enum mmi_email_edit_account_create_new_account(
                                        EMAIL_SRV_HANDLE srv_handle, 
                                        srv_email_acct_info_struct *p_current_account,
                                        void *p_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    EMAIL_ACCT_HANDLE account_handle;
    MMI_BOOL need_destroy_handle = MMI_TRUE;
    mmi_email_operate_result_enum return_value = MMI_EMAIL_OPERATE_RESULT_SUCCESS;
    MMI_BOOL need_delete_account = MMI_FALSE;
    MMI_ID parent_id = GRP_ID_INVALID;
    mmi_email_account_error_code_struct error_info; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&error_info, 0, sizeof(mmi_email_account_error_code_struct));
    
    srv_op_result = srv_email_acct_create(srv_handle, &account_handle);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_LOG1, srv_handle, srv_op_result);
        need_destroy_handle = MMI_FALSE;
        return_value = MMI_EMAIL_OPERATE_RESULT_FAILED;
        error_info.error_type = MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_SERVICE;
        error_info.error_code.srv_error = srv_op_result;
        goto MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_END;
    }
    // get an account id
    srv_op_result = srv_email_acct_new(account_handle, &(p_current_account->acct_id));
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_LOG2, account_handle, p_current_account->acct_id, srv_op_result);
        return_value = MMI_EMAIL_OPERATE_RESULT_FAILED;
        error_info.error_type = MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_SERVICE;
        error_info.error_code.srv_error = srv_op_result;
        goto MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_END;
    }
    // fill account info
    srv_op_result = srv_email_acct_edit(account_handle, p_current_account);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_LOG3, account_handle, p_current_account->acct_id, srv_op_result);
        need_delete_account = MMI_TRUE;
        return_value = MMI_EMAIL_OPERATE_RESULT_FAILED;
        error_info.error_type = MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_SERVICE;
        error_info.error_code.srv_error = srv_op_result;
        goto MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_END;
    }

    srv_op_result = srv_email_acct_save_async(
                        account_handle, 
                        mmi_email_async_save_acct_callback,
                        mmi_email_asyn_create_account_p);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_LOG7, srv_op_result, mmi_email_asyn_create_account_p->type);
    if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
    {
    }
    else if (SRV_EMAIL_RESULT_WOULDBLOCK == srv_op_result)
    {
        if (MMI_EMAIL_ASYNC_CREATE_ACCOUNT_TYPE_FROM_WIZRAD == mmi_email_asyn_create_account_p->type)
        {
            parent_id = mmi_email_account_list_p->new_account_group_id;
        }
        else if (MMI_EMAIL_ASYNC_CREATE_ACCOUNT_TYPE_FROM_TEMPLATE == mmi_email_asyn_create_account_p->type)
        {
            parent_id = mmi_email_account_list_p->new_account_template_group_id;
        }
        else
        {
            MMI_ASSERT(0);
        }
        mmi_email_asyn_create_account_p->account_handle = account_handle;
        mmi_email_asyn_create_account_p->p_account_list_cntx = mmi_email_account_list_p;
        mmi_frm_scrn_first_enter(   // loading popup
            parent_id, 
            SCR_ID_EMAIL_PROGRESS, 
            (FuncPtr)mmi_email_entry_async_create_account_wait_screen, 
            mmi_email_account_list_p);
        return_value = MMI_EMAIL_OPERATE_RESULT_WOULD_BLOCK;
        goto MMI_EMAIL_EDIT_ACCOUNT_ASYN_CREATE_NEW_ACCOUNT_END;
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_LOG4, account_handle, p_current_account->acct_id, srv_op_result);
        need_delete_account = MMI_TRUE;
        return_value = MMI_EMAIL_OPERATE_RESULT_FAILED;
        error_info.error_type = MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_SERVICE;
        error_info.error_code.srv_error = srv_op_result;
        goto MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_END;
    }

    if (MMI_FALSE == mmi_email_store_acct_misc_info(p_current_account->acct_id))
    {
        need_delete_account = MMI_TRUE;
        return_value = MMI_EMAIL_OPERATE_RESULT_FAILED;
        error_info.error_type = MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_MMI;
        error_info.error_code.srv_error = (srv_email_result_enum)0;
        goto MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_END;
    }

MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_END:
    if (MMI_TRUE == need_destroy_handle)
    {
        srv_op_result = srv_email_acct_destroy(account_handle);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_LOG5, account_handle, p_current_account->acct_id, srv_op_result);
            return_value = MMI_EMAIL_OPERATE_RESULT_FAILED;
            error_info.error_type = MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_SERVICE;
            error_info.error_code.srv_error = srv_op_result;
        }
    }
    if (MMI_TRUE == need_delete_account)
    {
        srv_email_acct_delete(p_current_account->acct_id);
    }
    if ((MMI_EMAIL_OPERATE_RESULT_FAILED == return_value) && (NULL != p_error))
    {
        memcpy(p_error, &error_info, sizeof(mmi_email_account_error_code_struct));
    }
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_EDIT_ACCOUNT_CREATE_NEW_ACCOUNT_LOG6, return_value);
    return return_value;
    
MMI_EMAIL_EDIT_ACCOUNT_ASYN_CREATE_NEW_ACCOUNT_END:
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_install_pre_defined_accounts
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static void mmi_email_install_pre_defined_accounts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    EMAIL_SRV_HANDLE srv_handle = EMAIL_SRV_INVALID_HANDLE;
    mmi_email_pre_defined_account_struct pre_defined_account;
    S32 i = 0;
    MMI_BOOL create_misc_info = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_acct_pre_install_open(&srv_handle);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_INSTALL_PRE_DEFINED_ACCOUNTS_LOG1, srv_op_result, srv_handle);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        goto MMI_EMAIL_INSTALL_PRE_DEFINED_ACCOUNTS_END;
    }

    mmi_email_get_pre_defined_account_info(&pre_defined_account);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_INSTALL_PRE_DEFINED_ACCOUNTS_LOG2, pre_defined_account.account_num);

    if (pre_defined_account.account_num > 0)
    {
        for (i = 0; i < pre_defined_account.account_num; i++)
        {
            srv_op_result = srv_email_acct_pre_install_create(srv_handle, &(pre_defined_account.p_account_info[i]));
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_INSTALL_PRE_DEFINED_ACCOUNTS_LOG3, i, srv_op_result);

            if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
            {
                create_misc_info = mmi_email_store_acct_misc_info(pre_defined_account.p_account_info[i].acct_id);
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_INSTALL_PRE_DEFINED_ACCOUNTS_LOG4, create_misc_info);
                if (MMI_TRUE == create_misc_info)
                {
                    mmi_email_smgr_account_add(pre_defined_account.p_account_info[i].acct_id);
                }
                else
                {
                    srv_op_result = srv_email_acct_delete(pre_defined_account.p_account_info[i].acct_id);
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_INSTALL_PRE_DEFINED_ACCOUNTS_LOG5, srv_op_result);
                }
            }
            else
            {
            }
        }
    }
    
MMI_EMAIL_INSTALL_PRE_DEFINED_ACCOUNTS_END:
    if (EMAIL_SRV_INVALID_HANDLE != srv_handle)
    {
        srv_email_acct_pre_install_close(srv_handle);
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_get_pre_defined_account_info
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static void mmi_email_get_pre_defined_account_info(mmi_email_pre_defined_account_struct *p_pre_defined_account)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef EMAIL_USE_ALL_DEFAULT_ACCT_VALUES
    static srv_email_acct_info_struct g_email_pre_defined_acct_info_config[] = 
    {
    #ifdef CUSTOM_EMAIL_PROFILES
        CUSTOM_EMAIL_PROFILES
    #else /* CUSTOM_EMAIL_PROFILES */
        {
            EMAIL_ACCT_INVALID_ID,
            SRV_EMAIL_ACCT_FACTORY_CONFIGURED,
            MMI_FALSE,
            SRV_EMAIL_PROT_IMAP4,
            {MMI_CHSET_UCS2, 10, L"test6", L"test6@iceman.com"},
            {MMI_CHSET_UCS2, 0,  0,        0},
            {L"218.249.47.81", 143, 0, SRV_EMAIL_SEC_NONE, 0x3e01},
            {L"218.249.47.81", 25,  0, SRV_EMAIL_SEC_NONE, 0x3e01},
            {L"test6", L"p@SSw0rd", SRV_EMAIL_AUTH_USER},
            {L"test6", L"p@SSw0rd", SRV_EMAIL_AUTH_USER},
            SRV_EMAIL_SEND_SEND_COPY,
            SRV_EMAIL_DOWNLOAD_HEADER,
            SRV_EMAIL_NOTIFY_OFF,
            MMI_FALSE,
            SRV_EMAIL_DELETE_PHONE_AND_SERVER,
            102400,
            10,
            "",
            "",
            L"test6.imap.SIM",
            SRV_EMAIL_ACCT_ATTR_SMTP | SRV_EMAIL_ACCT_ATTR_IMAP4,
        },
        {
            EMAIL_ACCT_INVALID_ID,
            SRV_EMAIL_ACCT_FACTORY_CONFIGURED,
            MMI_FALSE,
            SRV_EMAIL_PROT_IMAP4,
            {MMI_CHSET_UCS2, 10, L"test6", L"test6@iceman.com"},
            {MMI_CHSET_UCS2, 0,  0,        0},
            {L"172.26.129.53", 143, 0, SRV_EMAIL_SEC_NONE, 0x3e01},
            {L"172.26.129.53", 25, 0, SRV_EMAIL_SEC_NONE, 0x3e01},
            {L"test6", L"p@SSw0rd", SRV_EMAIL_AUTH_USER},
            {L"test6", L"p@SSw0rd", SRV_EMAIL_AUTH_USER},
            SRV_EMAIL_SEND_SEND_COPY,
            SRV_EMAIL_DOWNLOAD_HEADER,
            SRV_EMAIL_NOTIFY_OFF,
            MMI_FALSE,
            SRV_EMAIL_DELETE_PHONE_AND_SERVER,
            102400,
            10,
            "",
            "",
            L"test6.imap.local",
            SRV_EMAIL_ACCT_ATTR_SMTP | SRV_EMAIL_ACCT_ATTR_IMAP4,
        }
    #endif
    };
    p_pre_defined_account->account_num = sizeof(g_email_pre_defined_acct_info_config) / sizeof(srv_email_acct_info_struct);
    p_pre_defined_account->p_account_info = g_email_pre_defined_acct_info_config;
#else
    p_pre_defined_account->account_num = 0;
    p_pre_defined_account->p_account_info = NULL; 
#endif
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_is_in_edit
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_email_account_is_in_edit(EMAIL_ACCT_ID account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL return_value = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((EMAIL_ACCT_INVALID_ID != mmi_email_account_list_p->current_edit_account_id) &&
        (account_id == mmi_email_account_list_p->current_edit_account_id))
    {
        return_value = MMI_TRUE;
    }
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_account_save_sent_emails
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_email_account_save_sent_emails(EMAIL_ACCT_ID account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL read_operation_result = MMI_FALSE;
    MMI_BOOL return_value = MMI_FALSE;
    mmi_email_account_extra_info_struct account_extra_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_operation_result = mmi_email_entry_edit_account_read_account_extra_info(account_id, &account_extra_info, NULL);
    if (MMI_FALSE == read_operation_result)
    {
        return_value = MMI_FALSE;
    }
    else
    {
        return_value = account_extra_info.save_sent_emails;
    }
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_async_save_acct_callback
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static void mmi_email_async_save_acct_callback(srv_email_result_enum result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_asyc_create_account_struct *p_email_asyc_create_account_cntx = NULL;
    mmi_email_account_list_cntx_struct *p_account_list_cntx = NULL;
    MMI_ID parent_id = GRP_ID_INVALID;
    MMI_BOOL delete_account = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_email_asyc_create_account_cntx = (mmi_email_asyc_create_account_struct*)user_data;
    p_account_list_cntx = p_email_asyc_create_account_cntx->p_account_list_cntx;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_ASYNC_SAVE_ACCT_CALLBACK_LOG1, 
        result, 
        p_email_asyc_create_account_cntx->type,
        p_account_list_cntx->first_new_account);
    
    if (MMI_EMAIL_ASYNC_CREATE_ACCOUNT_TYPE_FROM_WIZRAD == p_email_asyc_create_account_cntx->type)
    {
        parent_id = p_account_list_cntx->new_account_group_id;
    }
    else 
    {
        parent_id = p_account_list_cntx->new_account_template_group_id;
    }

    if (SRV_EMAIL_RESULT_SUCC == result)
    {
        mmi_email_smgr_account_add(p_account_list_cntx->current_account.acct_id);

        if (MMI_TRUE == mmi_email_store_acct_misc_info(p_account_list_cntx->current_account.acct_id))
        {
            //mmi_email_lib_succ_popup(STR_GLOBAL_SAVED);
        }
        else
        {
            mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
            delete_account = MMI_TRUE;
        }
    }
    else
    {
        mmi_email_util_display_error_popup(parent_id, result);
        delete_account = MMI_TRUE;
    }

    if (MMI_TRUE == p_account_list_cntx->first_new_account)
    {
        mmi_email_acct_setting_evt_struct setting_event;
        MMI_FRM_INIT_GROUP_EVENT(&setting_event, EVT_ID_ACCT_SETTING_EXIT, parent_id);
        mmi_frm_group_send_to_parent(GRP_ID_EMAIL_ACCOUNT_WIZARD, (mmi_group_event_struct*)&setting_event);
        p_account_list_cntx->first_new_account = MMI_FALSE;
        email_mmi_account_data_set_default(p_account_list_cntx->current_account.acct_id);
    }
    srv_email_acct_destroy(p_email_asyc_create_account_cntx->account_handle);

    if (MMI_TRUE == delete_account)
    {
        srv_email_acct_delete(p_account_list_cntx->current_account.acct_id);
    }
    mmi_frm_scrn_close(parent_id, SCR_ID_EMAIL_PROGRESS);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_async_create_account_wait_screen
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_async_create_account_wait_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id,
                        p_screen_data->scrn_id,
                        NULL,
                        (FuncPtr)mmi_email_entry_async_create_account_wait_screen,
                        MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_key_proc(
            p_screen_data->group_id, 
            p_screen_data->scrn_id, 
            mmi_email_entry_async_create_account_wait_screen_key_proc);
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        ShowCategory66Screen(
            STR_GLOBAL_EMAIL,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            0,
            0,
            (U8*)GetString(STR_GLOBAL_SAVING),
            mmi_email_lib_get_progress_img_id(),
            guiBuffer);
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_entry_async_create_account_wait_screen_key_proc
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_entry_async_create_account_wait_screen_key_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_KEY_HANDLED;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_find_redundent_account_algo
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static void mmi_email_find_redundent_account_algo(
                EMAIL_ACCT_ID *p_service_account_id_array,
                U32 service_account_num,
                EMAIL_ACCT_ID *p_verify_account_id_array,
                U32 verify_account_num,
                EMAIL_ACCT_ID *p_redundant_account_id_array,
                S32 *p_redundant_account_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL find_redundent_account = MMI_FALSE;
    U32 i = 0;
    S32 j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_FIND_REDUNDENT_ACCOUNT_ALOG_LOG1,
        p_service_account_id_array,
        service_account_num,
        p_verify_account_id_array,
        verify_account_num,
        p_redundant_account_id_array,
        *p_redundant_account_num);
    for (i = 0; i < service_account_num; i++)
    {
        for (j = 0; j < *p_redundant_account_num; j++)
        {
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                MMI_EMAIL_FIND_REDUNDENT_ACCOUNT_ALOG_LOG2,
                j,
                p_redundant_account_id_array[j],
                i,
                p_service_account_id_array[i]);
            if (p_redundant_account_id_array[j] == p_service_account_id_array[i])
            {
                find_redundent_account = MMI_TRUE;
                break;
            }
        }
        if (MMI_TRUE == find_redundent_account)
        {
            find_redundent_account = MMI_FALSE;
        }
        else
        {
            if (MMI_FALSE == mmi_email_check_account_id_validity(
                                p_service_account_id_array[i], 
                                p_verify_account_id_array, 
                                verify_account_num))
            {
                MMI_TRACE(
                    MMI_INET_TRC_G9_EMAIL,
                    MMI_EMAIL_FIND_REDUNDENT_ACCOUNT_ALOG_LOG3,
                    i,
                    p_service_account_id_array[i]);
                p_redundant_account_id_array[*p_redundant_account_num] = p_service_account_id_array[i];
                (*p_redundant_account_num)++;
            }
        }
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_recognize_screen
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_wizard_entry_recognize_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    CHAR *p_data = GetString(STR_EMAIL_ACCT_NOT_RECOGNIZED);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id,
                        p_screen_data->scrn_id,
                        NULL,
                        (FuncPtr)mmi_email_wizard_entry_recognize_screen,
                        MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        ShowCategory74Screen(
            STR_EMAIL_SETUP_WIZARD_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8*)p_data,
            mmi_ucs2strlen(p_data),
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_email_wizard_entry_recognize_screen_lsk, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_email_wizard_entry_recognize_screen_lsk, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_email_wizard_entry_recognize_screen_rsk, KEY_EVENT_UP);
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_recognize_screen_lsk
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_recognize_screen_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_entry_new_account_process(mmi_email_account_list_p);
    mmi_frm_scrn_close(mmi_email_account_list_p->new_account_template_group_id, SCR_ID_EMAIL_WIZARD_TEMPLATE_RECOGNIZE);
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_wizard_entry_recognize_screen_rsk
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_wizard_entry_recognize_screen_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
    return;
}

#ifdef __OP12__
/*****************************************************************************
 * FUNCTION
 *  mmi_email_wizard_match_acct_with_template
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  MMI_TRUE    : Matched
 *  MMI_FALSE   : Not matched
 *****************************************************************************/
static MMI_BOOL mmi_email_wizard_match_acct_with_template(
                WCHAR *p_email_addr,
                S32 *acct_template_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *p_email_server = NULL;
    WCHAR *p_search_addr = NULL;
    mmi_email_acct_temp_struct *p_acct_temp_struct = NULL;
    S32 temp_num = 0;
    S32 i = 0;
    mmi_email_app_core_result_enum app_core_op_result = MMI_EMAIL_FAIL;
    MMI_BOOL is_matched = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_email_server = OslMalloc((SRV_EMAIL_MAX_SERVER_NAME_LEN + 1) * sizeof(WCHAR));
    p_acct_temp_struct = OslMalloc(sizeof(mmi_email_acct_temp_struct));

    mmi_email_util_get_default_server(p_email_addr, p_email_server);
    app_core_op_result = mmi_email_acct_temp_get_num(&temp_num);
    if (MMI_EMAIL_SUCCESS != app_core_op_result)
    {
        goto end;
    }
    for (i = 0; i < temp_num; i++)
    {
        app_core_op_result = mmi_email_acct_temp_get_acct(i, p_acct_temp_struct);
        if (MMI_EMAIL_SUCCESS != app_core_op_result)
        {
            goto end;
        }
        if (0 != p_acct_temp_struct->addr[0])
        {
            p_acct_temp_struct->addr[0] = L'.';
            p_search_addr = p_acct_temp_struct->addr;
        }
        else
        {
            p_search_addr = mmi_wcschr(p_acct_temp_struct->incoming_server.server_name, L'@');
            if (NULL == p_search_addr)
            {
                continue;
            }
            else
            {
                *p_search_addr = L'.';
            }
        }

        if (0 == mmi_wcsicmp(p_email_server, p_search_addr))
        {
            is_matched = MMI_TRUE;
            *acct_template_index = i;
            break;
        }
    }

end:
    if (NULL != p_email_server)
    {
        OslMfree(p_email_server);
        p_email_server = NULL;
    }
    if (NULL != p_acct_temp_struct)
    {
        OslMfree(p_acct_temp_struct);
        p_acct_temp_struct = NULL;
    }
    return is_matched;
}
#endif /* #ifdef __OP12__ */

#endif /* __MMI_EMAIL__ */

