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
 * AnswerMachineport.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for auto answer machine.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 #ifndef MMI_AUTOAM_PORT_H
 #define MMI_AUTOAM_PORT_H

 #include "MMI_features.h"
 
#ifdef __MMI_AUTO_ANSWER_MACHINE__

//#define ___AUTOAM_MY_DEBUG___
#undef ___AUTOAM_MY_DEBUG___
#include "FileMgrCUIGProt.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "AnswerMachineType.h"
 /***************************************************************************** 
* Interal Function
******************************************************************************/
extern void mmi_autoam_highlight_main(void);
extern void mmi_autoam_entry_main(void);
extern void mmi_autoam_entry_leaving_message(void);
extern void mmi_autoam_entry_setting(void);
extern void mmi_autoam_prepare_setting_inline_data(void);
extern void mmi_autoam_setting_fill_inline_item(void);
extern void mmi_autoam_main_setting_get_string(void);
extern void mmi_autoam_browse_greeting_file(cui_storage_selector_result_event_struct *);
extern void mmi_autoam_select_greeting_file_done(void *fullname, int is_short);
extern void mmi_autoam_util_get_greeting_path(UI_string_type path, U8 drv_letter);
extern void mmi_autoam_entry_choose_greeting(void);
extern void mmi_autoam_play_greeting_file(void);
extern void mmi_autoam_choose_greeting_file_done(void);
extern void mmi_autoam_get_new_file(U16 *fullname);
extern MMI_BOOL mmi_autoam_check_file_exist(UI_string_type filename);
extern void mmi_autoam_increase_file_name(UI_string_type filename);
extern void mmi_autoam_record_greeting_file(void);
extern void mmi_autoam_entry_edit_remote_setting(void);
extern void mmi_autoam_remote_setting_highlight_hdlr(S32 item_index);
extern MMI_BOOL mmi_autoam_play_greeting_bgsound_file(U16 *file_path);
extern MMI_BOOL mmi_autoam_play_greeting_bgsound_string(U8 index);
extern void mmi_autoam_set_loud_speaker(void);
extern void mmi_autoam_answer_call_by_hand(void);
extern void mmi_autoam_record_in_call(void);
extern void mmi_autoam_entry_greeting_in_call(void);
extern U8 mmi_autoam_greeting_delete_callback(void *in_param);
extern S32 mmi_autoam_file_load_single_msg(S32 fd, S32 item_index);
extern void mmi_autoam_entry_record_in_call(void);
extern void mmi_autoam_set_mute(void);
extern void mmi_autoam_set_unmute(void);
extern MMI_BOOL mmi_autoam_loud_option(void);
extern void mmi_autoam_write_message_list(void);
extern void mmi_autoam_record_duration_count(void);
extern U8 mmi_autoam_record_delete_callback(void *in_param);
extern void mmi_autoam_entry_message_list(void);
extern pBOOL mmi_autoam_message_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_autoam_message_list_item_hint(S32 item_index, UI_string_type *hint_array);
extern U16 mmi_autoam_get_message_number(S32 *num_of_item);
extern MMI_BOOL mmi_autoam_get_message_list_info(void);
extern void mmi_autoam_entry_voice_message_option(void);
extern void mmi_autoam_voice_message_highlight_hdlr(S32 index);
extern void mmi_autoam_play_voice_message(void);
extern void mmi_autoam_view_voice_message_info(void);
extern void mmi_autoam_get_voice_message_datetime(S8* buffer);
extern void mmi_autoam_get_voice_message_duration(U16* buffer);
extern void mmi_autoam_save_name_to_pbk(void);
extern void mmi_autoam_voice_message_dial(void);
extern void mmi_autoam_entry_message_detail_screen(void);
extern void mmi_autoam_exit_message_detail_screen(void);

extern U8 mmi_autoam_message_list_delete_callback(void *in_param);
void mmi_autoam_voice_message_delete(void);
void mmi_autoam_voice_message_delete_confirm(void);
void mmi_autoam_file_delete_single_update(void);
void mmi_autoam_voice_message_delete_all_confirm(void);
void mmi_autoam_voice_message_delete_all(void);
void mmi_autoam_entry_message_delete_all_animation(void);
void mmi_autoam_message_delete_all_ordinal(void);
void mmi_autoam_message_delete_all_interrupt(void);
void mmi_autoam_file_delete_all_update(void);
extern MMI_BOOL mmi_autoam_voice_message_check_list(void);
void mmi_autoam_main_setting_save_confirm(void);
void mmi_autoam_main_setting_pre_save(void);
void mmi_autoam_main_setting_save_and_set(void);
void mmi_autoam_main_setting_abort(void);
extern void mmi_autoam_get_write_nvram_pick_up(S32 index, U8* pickup);
extern void mmi_autoam_get_write_nvram_duration(S32 index, U16* duraiton);
MMI_BOOL mmi_autoam_check_pick_up_setting(U8* pickup);
MMI_BOOL mmi_autoam_check_duration_setting(U16* duration);
extern S32 mmi_autoam_get_pick_up_index(U8 pickup);
extern S32 mmi_autoam_get_duration_index(U16 duration);
extern void mmi_autoam_start_key_detection(S32 timeout);
extern void mmi_autoam_stop_key_detection(void);
extern void mmi_autoam_key_detection_callback(S16 key);
extern void mmi_autoam_check_hot_key(S16 key);
extern void mmi_autoam_check_remote_passwd(S16 key);
extern void mmi_autoam_check_operation_type(S16 key);
extern MMI_BOOL mmi_autoam_match_passwd(void);
extern void mmi_autoam_count_unread_message_number(U16* message_num, U8* digital_num);
extern MMI_ID_TYPE mmi_autoam_get_play_message_num_index(U16* message_num, U8* digital_num);
extern void mmi_autoam_repeat_play_bgsound_string(void);
extern MMI_BOOL mmi_autoam_play_bgsound_string(MMI_ID_TYPE index);
extern MMI_BOOL mmi_autoam_play_bgsound_file(U16 *file_path);
extern void mmi_autoam_entry_select_storage(void);
extern void mmi_autoam_get_drive_callback(S8 drv_letter);
extern void mmi_autoam_create_dest_folder(void);
extern void mmi_autoam_entry_message_select_drv(void);
extern void mmi_autoam_message_get_drive_callback(S8 drv_letter);
extern void mmi_autoam_voice_message_protect_change(void);
extern void mmi_autoam_check_list_num(void);
extern MMI_BOOL mmi_autoam_is_voice_message_protect(void);
//file operation
MMI_BOOL mmi_autoam_file_renew(S32 fd);
MMI_BOOL mmi_autoam_file_load_incall(S32 *file_hdlr_p, U8 *total_num);
MMI_BOOL mmi_autoam_file_check_format(S32 fd, U8 *number);
S32 mmi_autoam_file_check_unread(S32 fd, U8 total_num);

//
void mmi_autoam_record_state_switch(mmi_autoam_state_enum state);
void mmi_autoam_remote_state_switch(mmi_autoam_state_enum state);
void mmi_autoam_key_detection_timeout(void);
void mmi_autoam_play_greeting(void);
void mmi_autoam_play_prompt(void);
void mmi_autoam_play_di_tone(void);
S32 mmi_autoam_play_record_msg(void);
void mmi_autoam_reset_play_cnxt(void);
MMI_BOOL mmi_autoam_login_passwd_check(void);
MMI_BOOL mmi_autoam_play_find_next(void);
void mmi_autoam_play_msg_callback(S32 result, void *user_data);

void mmi_autoam_choose_greeting_default(void);
MMI_BOOL mmi_autoam_check_dest_folder(PU16 file_path);
void mmi_autoam_choose_play_greeting(void);
void mmi_autoam_remote_setting_done(void);
void mmi_autoam_init_setting(void);

void mmi_autoam_quit_screen(void);
void mmi_autoam_exit_msg_waiting(void);
void mmi_autoam_ignore_missed_msg(void);

void mmi_autoam_file_write_new_msg(void);
void mmi_autoam_highlight_message_delete(void);
void mmi_autoam_entry_message_delete_confirm(void);
void mmi_autoam_entry_message_delete_animation(void);
void mmi_autoam_entry_message_list_from_idle(void);
void mmi_autoam_init_language_type(void);

extern U8 IsKeyPadLockState(void);
void mmi_autoam_remote_custom_function(void);

#ifdef ___AUTOAM_MY_DEBUG___
void mmi_autoam_start_answer_incoming_test(void);
#endif /* ___AUTOAM_MY_DEBUG___ */

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_autoam_iconbar_button_hdlr(S32 index);
extern void mmi_autoam_iconbar_setup(void);
extern void mmi_autoam_set_iconbar_state(void);
#endif 
#endif /*__MMI_AUTO_ANSWER_MACHINE__*/

#endif /*MMI_AUTOAM_PORT_H*/
