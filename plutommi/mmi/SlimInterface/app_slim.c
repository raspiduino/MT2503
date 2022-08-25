/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  App_Slim.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the main component of the idle application.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "BootupSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "PhbSrvGprot.h"
#include "CallSetSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "GpioSrvGprot.h"


#include "IdleObject.h"
#include "IdleGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "IdleMain.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "mmi_rp_app_idle_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "IdleFactory.h"
#include "IdleEventCfg.h"
#include "kal_trace.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "cbm_consts.h"
#include "cbm_api.h"
#include "GlobalResDef.h"
#include "IdleAdapter.h"
#include "mmi_frm_mem_gprot.h"
#include "FactoryGprot.h"

#include "PhoneSetupGprots.h"
#include "remindersrvgprot.h"
#include "soundeffect.h"
#include "phbsrvgprot.h"
#include "generalsettingsrvgprot.h"

/*audioplayersettings*/
UI_string_type g_settings_audio_effects_inline1[NO_OF_SETTINGS_SOUND_EFFECTS];
UI_string_type g_settings_audio_effects_inline2[MAX_EQUALIZER_NUM];
audio_equalizer_struct g_settings_audio_equalizer;
/*audioplayersettings*/

U8 g_dst;

S32 g_settings_selected_audio_effect;
S32 g_settings_current_effect_index;
S32 g_settings_current_audio_effect_prev;
S32 g_settings_current_audio_effect;
U16 current_audio_equalizer_index;
U16 current_audio_reverb_index;
U16 current_audio_surround_index;

MMI_ID_TYPE idle_screen_wallpaper_ID;
MMI_ID_TYPE idle_screen_cache_id;
CHAR *idle_screen_wallpaper_name = NULL;
CHAR *idle_screen_cache_name = NULL;
CHAR *idle_screen_wallpaper_name_original = NULL;

//__MMI_BT_BOX_NONE_UI__
void highlight_mainmenu_callcenter(void){}
void highlight_mainmenu_calllog(void){}
void highlight_mainmenu_extra(void){}
void highlight_mainmenu_filemngr(void){}
void highlight_mainmenu_funandgames(void){}
void highlight_mainmenu_messages(void){}
void highlight_mainmenu_multimedia(void){}
void highlight_mainmenu_organizer(void){}
void highlight_mainmenu_phonebook(void){}
void highlight_mainmenu_profiles(void){}
void highlight_mainmenu_services(void){}
void highlight_mainmenu_settings(void){}
void highlight_mainmenu_shortcuts(void){}
void highlight_mainmenu_tools(void){}
void mmi_idle_display(void){}
MMI_BOOL mmi_idle_is_active(void){return MMI_FALSE;}
MMI_BOOL mmi_idle_update_service_area(void){return MMI_FALSE;}
void goto_main_menu(void){}
const mmi_factory_cfg_struct *mmi_idle_get_cfg_table(void){return NULL;}
mmi_id mmi_idle_get_group_id(void){return 0;}
MMI_BOOL mmi_idle_is_group_active(void){return MMI_FALSE;}
mmi_ret mmi_idle_main_evt_hdlr(mmi_event_struct *event){return 0;}
void mmi_idle_launch(mmi_id base_group_id){}
void initalize_main_menu_application(void){}
void mmi_idle_disable_lock_by_end_key(void){}


void highlight_mainmenu_bt_dialer(void){}
void highlight_mainmenu_connectivity(void){}
mmi_ret mmi_idle_classic_BT_dialer_event_handler(mmi_event_struct *event){}




U8 PhnsetGetFontSize(void)
{
    return THEME_DEFAULT;
}
void mmi_phnset_init(void){}
MMI_BOOL mmi_setting_set_language(U8 language_idx)
{ 
    return MMI_TRUE;
}
void PhnsetReinitHomeCityIdx(void){}
U8 mmi_phnset_get_language_idx(void){}
MMI_BOOL mmi_phnset_entry_group_check_ex(MMI_ID parent_gid,mmi_id group_id){}
U8 PhnsetGetDateFormat(void) {}
U8 PhnsetGetDateSeperatorFormat(void){}
U8 PhnsetGetHomeCity(void)
{ 
    return 0;
}
U8 PhnsetGetTimeFormat(void){}
MMI_BOOL PhnsetGetShowDateTimeStatus(void)
{
        return MMI_FALSE; 
}

void InitSettingNVRAM(void){}
void InitSettingApp(void){}
void EntryScrSettingMenu(void){}
void mmi_settings_audio_eq_rename_by_language(void){}
void mmi_settings_sound_effect_highlight_hdlr(void){}
void InitSoundEffect(void){}
void mmi_settings_audio_effect_write_nvram(void){}
BOOL mmi_settings_audio_eq_apply(S16 index)
{
     return MMI_FALSE;
}

void mmi_settings_turn_off_audio_effect(void){}
void mmi_phnset_view_setting_set_by_file(U8 view_type, const WCHAR* file_name, mmi_proc_func callback, void* user_data){}
void PhnsetWallpaperBadFileCallBack(U16 strID){}
U8 PhnsetGetATDisplayBound(void)
{  
    return (0);
}
void PhnsetReadWallpaper(void){}
MMI_BOOL mmi_phnset_check_themeid_wallpaper(U16 imgID)
{
        return MMI_TRUE; 
}
void DateTimerIndication(void *p){}
void SetDateTime(void *t){}
void mmi_dt_check_rtc_time(void){}

MMI_BOOL srv_reminder_cancel(srv_reminder_type type, U32 usr_data){}
void srv_reminder_notify_finish(MMI_BOOL pwr_confirm){}
srv_reminder_ret_enum srv_reminder_set(srv_reminder_type type, const MYTIME *expiry_time, U32 usr_data){}

///////////////////////////
void HighlightAlmMenu(void){}
void HighlightPhnsetDateTimeScr(void){}
void HighlightPhnsetDispScr(void){}
void HighlightPhnsetScr(void){}
void HighlightRstScr(void){}
MMI_BOOL srv_phb_get_name_by_number(U16 *number, U16 *name, U16 len){}
void srv_reminder_pwr_on_hdlr(void *msg){}
FLOAT GetTimeZone(U8 cityIndex){}
/*usbpoweron*/
void PendingAlarmReminder(void){}
void PhnsetReadGPIOSetting(void){}
MMI_BOOL PhnsetRestoreToNvramContrast(void){}
MMI_BOOL mmi_alm_is_in_alarm(void){}
mmi_id srv_reminder_init(mmi_event_struct *evt){}
void srv_setting_init_language(void){}
/*usbpoweron*/
/*custom_fdn*/
MMI_BOOL srv_phb_xmgnt_approve_fdn(
                    kal_uint8 *tel_number,
                    kal_uint8 num_length,
                    kal_uint8 sim_id,
                    l4c_operation_type_enum l4c_op,
                    kal_uint16 *cause)
{
    return MMI_FALSE;
}
/*custom_fdn*/

/*pwroncharger*/
U8 AlmIsRTCPwron(void){}
/*pwroncharger*/
/*wgui_categories_idlescreen*/
S32 PhnsetScreenSaverBadFileCallBack(U16 StrID){}

/*CharBatSrv*/
MMI_BOOL srv_reminder_is_reminder_active(void){}
/*usbsrv*/
void srv_reminder_deinit(void){}
MMI_BOOL srv_reminder_is_expiring(void){}

/*wgui_inputs_multiline*/
U32 srv_phb_convert_to_0x81(U16 *name, MMI_BOOL is_convert){}

/*usbdevice*/
MMI_BOOL mmi_phb_check_processing(void){}

/*vmsalcontact*/
MMI_BOOL srv_phb_sdk_is_phb_ready(void){}
U8 srv_phb_datamgr_get_group_list(U8* group_array, U16* group_name){}
void srv_phb_sdk_add_contact(srv_phb_sdk_add_req_struct* req_info, srv_phb_sdk_callback_type cb){}
void srv_phb_sdk_delete_contact(srv_phb_sdk_delete_req_struct* req_info, srv_phb_sdk_callback_type cb){}
S32 srv_phb_sdk_get_contact(srv_phb_sdk_get_req_struct* req_info){}
S32 srv_phb_sdk_get_total_contacts(phb_storage_enum storage){}
S32 srv_phb_sdk_get_used_contacts(srv_phb_contact_pos_struct* pos_array, phb_storage_enum storage){}
S32 srv_phb_sdk_search_contact(srv_phb_sdk_search_req_struct* req_info){}
void srv_phb_sdk_update_contact(srv_phb_sdk_update_req_struct* req_info, srv_phb_sdk_callback_type cb){}
/*vmsalcontact*/

/*BootupInitApps*/
void OrgInit(void){}
void PhnsetInitSetTimeNDateNvram(void){}
void PhnsetReadNvramScrSvrSettings(void){}
void mmi_phnset_picture_quality_init(void){}
mmi_id srv_alm_init(mmi_event_struct *evt){}
void srv_phb_init_protocol(void){}
void srv_setting_init_general_setting(void){}
void mmi_phb_init(void){}

/*BootupInitApps*/

/*vmsettings*/
srv_setting_date_format_enum srv_setting_get_date_format(void){}
srv_setting_date_seperator_enum srv_setting_get_date_seperator(void){}
srv_setting_time_format_enum srv_setting_get_time_format(void){}
/*vmsettings*/

/* FactoryModeMisc*/
void FactorySetAlarm(U8 sec){}

/* DialerCuiCommon*/
void cui_phb_save_contact_close(mmi_id phb_save_sg_id){}
mmi_id cui_phb_save_contact_create(mmi_id parent_id){}
void cui_phb_save_contact_run(mmi_id phb_save_sg_id){}
void cui_phb_save_contact_set_number(mmi_id phb_save_sg_id, U16* number){}
MMI_BOOL mmi_phb_check_ready(MMI_BOOL not_ready_popup){}
U8 mmi_phb_get_sim_entry_by_location(U16 entryNum){}
U8 mmi_phb_get_speed_dial_status(void){}
CHAR* mmi_phb_speed_dial_get_number(U16 key_id)
{
    return 0;
}

/* DialerCuiCommon*/

void mmi_phb_entry_main_menu(void){}
void EntryOrganizer(void){}

/*res define event proc*/
mmi_ret mmi_alm_nmgr_evt_tone_handlr(void *param){}
mmi_ret mmi_alm_nmgr_evt_vib_handlr(void *param){}
mmi_ret mmi_alm_remdr_notify_hdlr(mmi_event_struct *evt){}
mmi_ret mmi_alm_srv_alm_op_hdlr(mmi_event_struct *evt){}
mmi_ret mmi_phb_processing_hdlr(mmi_event_struct* para)
{
    return MMI_RET_OK;
}
mmi_ret mmi_phb_ready_hdlr(mmi_event_struct* para){}
mmi_ret mmi_phnset_gpio_set_bl_level_ncenter(mmi_event_struct *evt){}
mmi_ret mmi_phnset_view_setting_common_dev_plug_out_hdlr(mmi_event_struct *param){}
mmi_ret mmi_phnset_wp_ss_pwr_disp_ms_hdlr(mmi_event_struct *evt){}
mmi_ret mmi_remdr_ut_notify_hdlr(mmi_event_struct *evt){}
mmi_ret mmi_reminder_bootup_start(mmi_event_struct *evt){}
mmi_ret mmi_reminder_on_pwrreset_notify(mmi_event_struct *evt){}
mmi_ret srv_alm_notify_hdlr(mmi_event_struct *evt){}
mmi_ret srv_reminder_on_bootup_notify(mmi_event_struct *evt){}
mmi_ret srv_reminder_on_shutdown_notify(mmi_event_struct *evt){}
mmi_ret srv_reminder_on_time_change_notify(mmi_event_struct *evt){}
/*phbcui*/
mmi_ret mmi_phb_number_editor_proc(mmi_event_struct *evt){}

	
/*res define event proc*/
//Link error for dialer
#ifndef __MMI_DIALER_CUI_SUPPORT__
const WCHAR *mmi_dialer_get_dial_string()
{
    return 0;
} 
#endif /* __MMI_DIALER_CUI_SUPPORT__ */

#if defined(__MMI_BTBOX_NOLCD__)

#ifndef __MMI_MESSAGE_APP_SUPPORT__
#include "SmsAppGprot.h"
void mmi_um_highlight_draft(void){}
void mmi_um_highlight_inbox(void){}
void mmi_um_highlight_sent(void){}
void mmi_um_highlight_setting(void){}
void mmi_um_highlight_unsent(void){}
void mmi_um_highlight_write_msg(void){}
void mmi_um_ui_sh_main_msg_entry_del_msg_folder(void){}
void mmi_um_entry_main_message_menu(void){}
void mmi_sms_write_msg_lanch(mmi_id parent_gid, mmi_sms_write_msg_para_struct *para){}
void mmi_um_init(void){}
void srv_um_service_init(void){}
#endif /* __MMI_MESSAGE_APP_SUPPORT__ */

#ifndef __MMI_PROFILES_APP__
#include "ProfilesAppGprot.h"
void mmi_profiles_entry_main_screen(void){}
mmi_ret mmi_prof_volume_change_hdlr(mmi_event_struct *evt){}
void mmi_prof_app_filemgr_option_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo){}
void mmi_prof_app_filemgr_option_hdlr(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo){}
MMI_BOOL mmi_prof_activate_profile(mmi_prof_id_enum profile_id, MMI_BOOL need_popup){}
MMI_BOOL mmi_prof_deactivate_silent_profile(MMI_BOOL need_popup){}
mmi_ret mmi_prof_app_init(mmi_event_struct *evt){}
#endif /* __MMI_PROFILES_APP__ */

#ifndef __MMI_SCRLOCKER_APP__
mmi_ret mmi_slk_main_evt_hdlr(mmi_event_struct *event){}
MMI_BOOL mmi_scr_locker_is_locked(void){return MMI_FALSE;}
void mmi_scr_locker_launch(void){}
#endif  /* __MMI_SCRLOCKER_APP__ */

#endif /* __MMI_BTBOX_NOLCD__ */



#ifdef __MMI_BT_BOX_NO_AT_SUPPORT__
#include "rmmi_context.h"
#include "keypad_sw.h"

void rmmi_main(ilm_struct *ilm_ptr){}
void rmmi_process_one_cmd(kal_uint8 cid){}
kal_bool rmmi_root_is_uart_owner(kal_uint8 cid){}
void rmmi_process_multi_cmd(kal_uint8 cid){}
kal_uint8 rmmi_srcid_2_cid(kal_uint8 src_id){}
void check_dcs_toCscs(kal_uint8 dcs, kal_uint16 length, kal_uint8 *data, kal_uint8 *ch_str){}
void rmmi_byte_order_reverse(kal_uint8 *src, kal_uint16 length){}
kal_uint8 rmmi_cid_2_srcid(kal_uint8 cid){}
kal_uint16 rmmi_fast_string_print(kal_uint8 *buff_ptr, kal_uint8 *fmt, void *arg_list[], kal_uint8 nos_arg){}
kal_uint8 rmmi_port_2_cid(kal_uint8 port){}
void rmmi_print_ucs2(kal_uint8 *val, kal_uint8 *str){}
void rmmi_result_code_fmttr(kal_uint8 rsp_type, kal_uint16 cause){}
void rmmi_write_to_uart(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff){}
kal_bool ucs2_to_ascii(kal_wchar *ucs2_src, kal_uint8 *ascii_dest){}

void rmmi_cnvrm_error_rsp_fmttr(kal_uint16 cause){}
kal_uint16 rmmi_convert_l3_cause(kal_uint16 ps_cause){}
void rmmi_final_rsp_generator(kal_uint8 src_id, kal_bool ret_val, kal_uint8 *buffer, kal_uint16 string_length){}
void rmmi_sms_result_code_fmttr(kal_uint8 rsp_type, kal_uint16 cause, kal_bool cause_present){}
void l4c_at_general_res_req(kal_bool result, kal_uint8* string){}
void l4c_mmi_ready_notify_req(void){}
module_type RMMI_UART_GetOwnerID(UART_PORT port){}
void RMMI_UART_OpenWithPort(UART_PORT APP_port, UART_PORT new_uart_port){}
kal_bool check_language_name(kal_uint8 lan_code, kal_uint8 *lan_name){}
kal_bool convert_keypad_code(kal_uint8 keycode, kal_uint8 *key){}
void rmmi_obtain_uart_control(kal_uint8 port, kal_bool plugout){}
void rmmi_root_plugin_uart(kal_uint8 port){}
void rmmi_root_plugout_uart(kal_uint8 port){}
void rmmi_write_unsolicitedResultCode(kal_uint8 *buffer,kal_uint16 length,kal_bool stuff,kal_uint8 mode,void *buffer_ptr){}
void RMMI_UART_Close(UART_PORT port, module_type ownerid){}
void l4c_at_ready_rind(void){}
void l4c_eq_alarm_detect_rind(rtc_format_struct *rtc_time){}
void l4c_eq_battery_status_rind(kal_uint8 battery_status, kal_uint8 battery_voltage){}
void l4c_eq_gpio_detect_rind(kal_uint8 gpio_device, kal_bool on_off){}
void l4c_eq_keypad_detect_rind(kal_bool(*drv_get_key_func) (kbd_data *)){}
void l4c_get_adc_all_channel_rind(kal_int32 vbat, kal_int32 bat_temp, kal_int32 vaux, kal_int32 charge_current, kal_int32 vcharge){}
void rmmi_clear_ath_for_dialup_hdlr(void){}
void l4c_nbr_cell_info_rind(kal_uint8 rat,kal_bool is_nbr_info_valid,  kal_uint8 *cell_info, kal_uint16 length){}
void rmmi_cmd_processor(rmmi_string_struct *source_string_ptr, kal_uint16 cmd_length){}
kal_bool rmmi_open_uart_port(UART_PORT port, UART_BAUDRATE_T baud_rate){}
void l4c_eq_read_autotest_report_rrsp(kal_bool result, kal_uint16 length, kal_uint8 *data){}
void l4c_em_get_conftest_para_rrsp(kal_bool result){}
void l4c_eq_get_audio_param_rrsp(kal_bool result, audio_param_struct * audio_para){}
void l4c_eq_get_audio_profile_rrsp(kal_bool result, audio_profile_struct audio_profile){}
void l4c_eq_get_voleme_rrsp(kal_bool result, kal_uint8 vol_type, kal_uint8 vol_level){}
void l4c_eq_pmic_config_rrsp(kal_uint8 request_type, pmic_config_param_struct request){}
void l4c_eq_query_cal_data_dl_status_rrsp(kal_bool cal_data_valid){}
void l4c_general_rrsp(kal_bool result, kal_uint16 cause){}
void l4c_cfun_rrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_read_ms_sn_rrsp(l4c_result_struct result, kal_uint16 length, kal_uint8 *data){}
void l4c_eq_read_ms_sv_rrsp(l4c_result_struct result, kal_uint16 length, kal_uint8 *data){}
void l4c_eq_read_nvram_rrsp(l4c_result_struct result, kal_uint16 length, kal_uint8 *data){}
void l4c_eq_reset_nvram_rrsp(l4c_result_struct result){}
void l4c_eq_set_ms_sn_rrsp(l4c_result_struct result, kal_uint8 file_idx, kal_uint16 para){}
void l4c_eq_write_nvram_rrsp(l4c_result_struct result, kal_uint8 file_idx, kal_uint16 para){}
void  l4c_eq_get_calibration_flag_rsp(kal_uint8 cal_flag){}
#endif /* __MMI_BT_BOX_NO_AT_SUPPORT__ */
