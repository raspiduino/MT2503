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
 * BTMMIScr.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MMI screen of bluetooth application.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "GlobalResDef.h"
#include "CommonScreens.h"
#include "mmi_rp_app_bluetooth_def.h"
/* for pts V2.1.0.4 */
/* cannot update indicators to remote bluetooth headset while HFP is connected */
/* indicators shall be retrieved by remote HF AT+CIND? */
/* so for pts V2.1.0.4, host will not udpate indicators while HFP is just connected */
U8 g_enable_pts_test=0;  /* 0: disable, 1: enable */

#include "MMIDataType.h"
#ifdef __MMI_BT_SUPPORT__
#include "wgui_categories_util.h"
#include "wgui_categories.h"
#include "ProfilesSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "bluetooth_bm_struct.h"

/* for get sound/image id */
#include "Custom_events_notify.h"

/***************************/
/* for MTK bluetooh       */
/***************************/
#ifdef __MMI_BT_AUDIO_SUPPORT__
#include "BTMMIScoPathGprots.h"
#endif

#include "BTMMIHfpGprots.h"
#include "BthfSrvGprot.h"

#include "BTMMISpp.h"
#include "BTMMISppGprots.h"
#include "BTMMIDunGprots.h"

#ifdef __MMI_SIMAP_SUPPORT__
#include "BTMMISimapGprots.h"
#endif

#ifdef __MMI_FAX_SUPPORT__
#include "BTMMIFaxGprots.h"
#endif

#if defined(__MMI_HIDD_SUPPORT__)
#include "BTMMIHiddGprots.h"
#include "BTMMIHidScr.h"
#endif /*defined(__MMI_HIDD_SUPPORT__)*/

#include "BTMMIObexGprots.h"

#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIOppGprots.h"
#endif
#ifdef __MMI_BT_MAP_CLIENT__
#include "MapSrvGprot.h"
#endif 
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
#include "BTMMIFtpGprots.h"
#endif

#ifdef __MMI_BIP_SUPPORT__
#include "BTMMIBipGprot.h"
#endif 

#ifdef __MMI_BPP_SUPPORT__
#include "BppMmiGprot.h"
#endif

#if defined(__MMI_PBAP_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)
#include "BTMMIPbapGprots.h"
#endif
#ifdef __MMI_BT_PBAP_CLIENT__
#include "PbapSrvGprot.h"
#endif

#ifdef __MMI_BT_DIALER_SUPPORT__
#include "BTDialerSrvGprot.h"
#include "mmi_rp_app_bt_dialer_def.h"
#endif



/***************************/
/* bluetooh common files   */
/***************************/

#include "BTMMIScrGprots.h"
#include "BTMMIScr.h"
#include "BtcmCuiGprot.h"
#include "BtcmSrvGprot.h"

/* UCM */
#include "UcmSrvGProt.h"
#include "UCMGProt.h"

#include "ModeSwitchSrvGprot.h"

#ifdef __MMI_A2DP_SUPPORT__
#include "BTMMIA2DP.h"
#include "av_bt.h"
#include "A2dpSrvGprot.h"
#endif

#if defined(__MMI_SYNCML_DEVICE_SYNC__)||defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) 
#include "SyncMLGprot.h"
#endif

#include "conversions.h"

#include "GpioSrvGprot.h" /*isEarphonePlugged*/

#ifdef __MMI_FTE_SUPPORT__ 
#include "wgui_touch_screen.h"
#endif
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#endif

#include "MenuCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "BthSCOPathSrvGProt.h"

#ifdef __BT_AUTO_DETECT_SUPPORT__
#include "ShortcutsGprots.h"
#endif
#include "bluetooth_struct.h"

#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "l4c_nw_cmd.h"
#include "string.h"
//#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_typedef.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "CommonScreensResDef.h"
#include "BTMMIA2DPScr.h"
#include "mmi_frm_input_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_list.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "BTMMISendGprots.h"
#include "wgui_inputs.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "NotificationGprot.h"
#include "mmi_msg_struct.h"
#include "app_ltlcom.h"
#include "mmi_cb_mgr_gprot.h"
#include "GpioSrvGprot.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_config.h"
#include "bluetooth_a2dp_struct.h"
#include "l1audio.h"
#include "BtAudioSrvGprot.h"
#include "NetSetAppGprot.h"
#ifdef MMI_TEST_MAP_CODE
#include "Tst_def.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"
#endif 
#if defined(_MMI_BWUI_BT_SLIM_)
#include "mmi_rp_app_uiframework_def.h"
#endif

#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
#include "BTMMIAntilostScr.h"
#endif
#include "nvram_common_defs.h"

#if defined( __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) && defined(__MMI_WEARABLE_DEVICE__)
#include "ScrLockerGprot.h"
#include "Mmi_rp_app_scr_locker_def.h"
#endif

#ifdef __MMI_BTBOX_NOLCD__
#include "BTB.h"
#endif  //__MMI_BTBOX_NOLCD__

/***************************************************************************** 
 * External Variable
 *****************************************************************************/

/***************************************************************************** 
 * External functions
 *****************************************************************************/
extern void srv_bt_cm_copy_addr(void *dest,void *src);
extern kal_int8 *app_ucs2_strcpy(U8 *strDestination, const kal_int8 *strSource);
extern kal_int32 app_ucs2_strlen(const kal_int8 *arrOut);
extern kal_int8 *app_ucs2_strcat(U8 *strDestination, const kal_int8 *strSource);
static mmi_ret mmi_bt_dummy_group_proc(mmi_event_struct *param);
#ifdef __MTK_TARGET__
extern kal_bool BT_PcmLoopbackTest(void);
#endif

#ifdef __MMI_ENGINEER_MODE__
extern void EmBTNotifyLoopbackDoneCnf(MMI_BOOL result);
#endif

#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
extern void mmi_bt_avrcp_init(void);
#endif /* defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__) */


#ifdef __BT_AUTO_DETECT_SUPPORT__
static void mmi_bt_chip_status_ind(void *para);
#endif

static srv_bt_cm_dev_struct* mmi_bt_get_matched_dev(U32 item_index, U32 specific_cod, U32 service_id);
static void mmi_bt_get_display_bt_address(WCHAR *display_buffer, const srv_bt_cm_bt_addr *dev_addr_p);
#ifdef __MMI_SIMAP_SUPPORT__
static void mmi_bt_set_simap_complete(srv_bt_cm_set_simap_struct* para);
#endif  // __MMI_SIMAP_SUPPORT__
static S32 mmi_bt_get_discovered_list_item(S32 start_index, gui_iconlist_menu_item* menu_data, S32 num_items);

static mmi_ret mmi_bt_entry_power_on_confirm_leave_proc(mmi_event_struct *evt);
static void mmi_bt_inquiry(mmi_id group_id, U32 cod, U16 title_str_id, void (*callback) (void));
//static void mmi_bt_passkey_input_scr_del_cb(void);
static void mmi_bt_reject_passkey(void);
#ifdef __MMI_BT_DIALER_SUPPORT__
static void mmi_bt_inq_cancel_bonding(void);
#endif
/*******************************/
/* my device */
/*******************************/
static void mmi_bt_show_mydev_screen(void);
#ifdef __MMI_FTC_SUPPORT__
static void mmi_bt_entry_mydev_conn_ftp(void);
#endif 

#ifdef __MMI_BT_SIMPLE_PAIR__
static mmi_ret mmi_bt_entry_passkey_notify_group_proc(mmi_event_struct *param);
static void mmi_bt_security_passkey_notify(void* para);
//static void mmi_bt_pre_entry_security_passkey_screen(void);
static void mmi_bt_entry_security_passkey_screen(void);
static void mmi_bt_exit_security_passkey_screen(void);
static MMI_BOOL mmi_bt_security_passkey_hdlr(mmi_scenario_id scen_id, void *arg);
//static void mmi_bt_passkey_notify_scr_del_cb(void);
static mmi_ret mmi_bt_passkey_notify_scr_leave_proc(mmi_event_struct *evt);

static mmi_ret mmi_bt_entry_security_user_confirm_group_proc(mmi_event_struct *param);
static void mmi_bt_security_user_confirm_notify(void *para);
static MMI_BOOL mmi_bt_security_user_confirm_hdlr(mmi_scenario_id scen_id, void *arg);
static void mmi_bt_pre_entry_security_user_confirm_screen(void);
static void mmi_bt_entry_security_user_confirm_screen(void);
static void mmi_bt_exit_security_user_confirm_screen(void);
static mmi_ret mmi_bt_security_user_confirm_scr_leave_proc(mmi_event_struct *evt);
//static void mmi_bt_security_user_confirm_scr_del_cb(void);
static void mmi_bt_security_user_confirm_yes(void);
static void mmi_bt_security_user_confirm_no(void);

static void mmi_bt_entry_security_keypress_notify(void* para);
static void mmi_bt_keypress_notify_cancel(void);
#endif  // __MMI_BT_SIMPLE_PAIR__

#ifdef __MMI_BT_TEMP_VISIBILITY__
static void mmi_bt_entry_set_vis_select(mmi_menu_id highlighted_menu_id);
static mmi_ret mmi_bt_entry_set_vis_group_proc(mmi_event_struct* evt);
#endif  // __MMI_BT_TEMP_VISIBILITY__


static mmi_ret mmi_bt_power_progress_leave_proc(mmi_event_struct *evt);
#ifdef __MMI_HF_SUPPORT__
extern void srv_bt_dialer_init(void);
extern void srv_bt_dialer_deinit(void);
#endif

#ifdef __MMI_A2DP_SUPPORT__
#ifdef __BT_SPEAKER_SUPPORT__
#ifdef __MMI_BT_SPEAKER_SUPPORT__
extern void aud_send_bt_close_sink_codec_req(module_type src_mod_id);
#endif /*__MMI_BT_SPEAKER_SUPPORT__*/
#endif //__MMI_A2DP_SUPPORT__
#endif //__BT_SPEAKER_SUPPORT__



/*******************************/
/* set menu => set audio path  */
/*******************************/
#ifndef _MMI_BT_ULTRA_SLIM_
static void mmi_bt_set_audio_pth_select(mmi_menu_id highlighted_menu_id);
static WCHAR* mmi_bt_get_audio_pth(void);
static void mmi_bt_entry_set_audio_pth_menu(void);
static mmi_ret mmi_bt_entry_set_audio_pth_group_proc(mmi_event_struct* evt);
#endif
//#define __MMI_BT_ALLOW_DELETE_POWER_PROGRESS_SCREEN__

/***************************************************************************** 
 * Globol Variable
 *****************************************************************************/
#ifdef __MMI_BT_DIALER_SUPPORT__
static S32 g_bt_mmi_menu_num;
static MMI_BOOL g_bt_paired_from_dialer = MMI_FALSE;
static MMI_BOOL g_bt_headset_conn_reject = MMI_FALSE;
static MMI_BOOL g_bt_pair_from_search = MMI_FALSE;
static MMI_BOOL g_bt_search_cancel = MMI_FALSE;
void mmi_bt_dialer_set_menu_num(S32 index);

#endif
mmi_bt_scr_cntx_struct g_mmi_bt_scr_cntx;
#ifdef __MMI_BT_DIALER_SUPPORT__

void mmi_bt_dialer_set_menu_num(S32 index)
{
  g_bt_mmi_menu_num = index;
}
S32 mmi_bt_dialer_get_menu_num(void)
{
  return g_bt_mmi_menu_num;
}
#endif
static const mmi_bt_func_ptr cm_profile_init_tbl[] =
{
    srv_bt_cm_init,
    mmi_bt_common_init,
#ifdef __MMI_HFP_SUPPORT__
    mmi_btaud_init,
#endif
#ifdef __MMI_SPP_SUPPORT__
    mmi_bt_spp_init,
#endif
#ifdef __MMI_DUN_SUPPORT__
    mmi_bth_dun_init,
#endif
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
    //mmi_bt_obex_event_hdlr_init,
#endif
#ifdef __MMI_OPP_SUPPORT__
    mmi_bt_opp_init,
#endif
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
    mmi_bt_ftp_init,
#endif
#ifdef __MMI_A2DP_SUPPORT__
    mmi_bt_a2dp_init,
#endif
#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
    mmi_bt_avrcp_init,
#endif
#ifdef __MMI_BPP_SUPPORT__
    mmi_bt_bpp_app_init,
#endif
#ifdef __MMI_SIMAP_SUPPORT__
    mmi_bth_simap_init,
#endif
#ifdef __MMI_FAX_SUPPORT__
    mmi_bth_fax_init,
#endif
#if defined(__MMI_HIDD_SUPPORT__)
    mmi_bth_hidd_init,
#endif
#ifdef __MMI_BIP_SUPPORT__
    mmi_bt_bip_init,
#endif
#ifdef __MMI_PBAP_SUPPORT__
    mmi_bt_pbap_init,
#endif
#ifdef __MMI_BT_PBAP_CLIENT__
	srv_pbapc_init,
#endif
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    mmi_syncml_device_bt_init,
#endif

#ifdef __MMI_HF_SUPPORT__
    srv_bt_dialer_init,
#endif

#ifdef __MMI_BT_MAP_CLIENT__
		srv_bt_mapc_init,
#endif 
    NULL
};

static const mmi_bt_func_ptr cm_profile_deinit_tbl[] =
{

#ifdef __MMI_HFP_SUPPORT__
    mmi_btaud_deinit,
#endif
#ifdef __MMI_OPP_SUPPORT__
    mmi_bt_opp_deinit,
#endif

#if defined (__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
    mmi_bt_ftp_deinit,
#endif

#ifdef __MMI_BIP_SUPPORT__
    mmi_bt_bip_deinit,
#endif

#ifdef __MMI_PBAP_SUPPORT__
    mmi_bt_pbap_deinit,
#endif

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    mmi_syncml_device_bt_deinit,
#endif

#ifdef __MMI_HF_SUPPORT__
	srv_bt_dialer_deinit,
#endif
#ifdef __MMI_BT_MAP_CLIENT__
	srv_bt_mapc_deinit,
#endif 

    NULL
};

static const U16 profile_str_id_map[ ][2] =
{
#if defined(__MMI_SPP_SUPPORT__) || defined(__MMI_BT_SPP_CLIENT_SUPPORT__)
    {SRV_BT_CM_SPP_PROFILE_UUID, STR_BT_PROF_SPP},
#endif
#ifdef __MMI_DUN_SUPPORT__
    {SRV_BT_CM_DUN_PROFILE_UUID, STR_BT_PROF_DUN},
#endif
#ifdef __MMI_FAX_SUPPORT__
    {SRV_BT_CM_FAX_PROFILE_UUID, STR_BT_PROF_FAX},
#endif
#ifdef __MMI_SIMAP_SUPPORT__
    {SRV_BT_CM_SIM_ACCESS_PROFILE_UUID, STR_BT_PROF_SAP},
#endif
#ifdef __MMI_OPP_SUPPORT__
    {SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID, STR_BT_PROF_OPP},
#endif
#if defined(__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__)
    {SRV_BT_CM_OBEX_FILE_TRANSFER_UUID, STR_BT_PROF_FTP},
#endif
#ifdef __MMI_HFP_SUPPORT__
    {SRV_BT_CM_HS_PROFILE_UUID, STR_BT_PROF_HS},
    {SRV_BT_CM_HEADSET_AG_SERVICE_UUID, STR_BT_PROF_HS},
#endif

#ifdef __MMI_HFP_SUPPORT__
    {SRV_BT_CM_HF_PROFILE_UUID, STR_BT_PROF_HF},
    {SRV_BT_CM_HFG_PROFILE_UUID, STR_BT_PROF_HF},
#endif

    /* for pts V2.1.0.4 */
#ifdef __MMI_A2DP_SUPPORT__
    {SRV_BT_CM_AUDIO_SOURCE_UUID, STR_BT_PROF_A2DP},
    {SRV_BT_CM_AUDIO_SINK_UUID, STR_BT_PROF_A2DP},
    {SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID, STR_BT_PROF_A2DP},
#endif
#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
    {SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID, STR_BT_PROF_AVRCP},
    {SRV_BT_CM_AV_REMOTE_CONTROL_UUID, STR_BT_PROF_AVRCP},
#endif
#ifdef __MMI_BPP_SUPPORT__
    {SRV_BT_CM_BASIC_PRINTING, STR_BT_PROF_BASIC_PRINTING},
    {SRV_BT_CM_OBEX_BPPS_PROFILE_UUID, STR_BT_PROF_BASIC_PRINTING},
#endif
#ifdef __MMI_HIDD_SUPPORT__
    {SRV_BT_CM_HID_PROFILE_UUID, STR_BT_PROF_HID},
#endif
#if defined(__MMI_PBAP_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__) // this macro is for pbap server not cleint as i remember and map doesnt have any 
    {SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID, STR_BT_PROF_PBAP},
    {SRV_BT_CM_OBEX_PBA_PROFILE_UUID, STR_BT_PROF_PBAP},
#endif
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    {SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, STR_BT_SRV_SYNCML},
    {SRV_BT_CM_OBEX_IR_MC_SYNC_SERVICE_UUID, STR_BT_PROF_SYNC},
#endif
#ifdef __MMI_BT_MAP_CLIENT__
    {SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID, STR_BT_PROF_MAP},

#endif

    {SRV_BT_CM_MAX_PROFILE_UUID, STR_BT_PROF_UNKNOWN}
};

#ifdef __TC01__
/* under construction !*/
#endif

#define MMI_BT_SCO_IND          1
#define MMI_BT_CONNECT_IND      0
#define MMI_BT_SCO_FAR_LP_TESTING   2
#define MMI_BT_DONT_SKIP_CALLBACK   0
#define MMI_BT_SKIP_CALLBACK        1
/*****************************************************************************
 * Functions
 *****************************************************************************/
void MMI_BT_SET_FLAG(U32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_BT_SET_SCR_FLAG,
        g_mmi_bt_scr_cntx.flag,
        (g_mmi_bt_scr_cntx.flag | x));
    g_mmi_bt_scr_cntx.flag |=  x ;
}


void MMI_BT_RESET_FLAG(U32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_BT_RESET_SCR_FLAG,
        g_mmi_bt_scr_cntx.flag,
        ((g_mmi_bt_scr_cntx.flag)&(~x)));
    g_mmi_bt_scr_cntx.flag &= ~x;
}


static void MMI_BT_SET_HILIGHT_ITEM(U32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_BT_SET_HILIGHT_ITEM,
        x);
    g_mmi_bt_scr_cntx.hilight_item = x;
}


static void mmi_bt_refresh_screen(void)
{
    mmi_frm_display_dummy_screen();
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_deinit
 * DESCRIPTION
 *  This function is to deinit all profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_DEINIT);

    for (i = 0; i < (sizeof(cm_profile_deinit_tbl) / sizeof(mmi_bt_func_ptr)); i++)
    {
        if (cm_profile_deinit_tbl[i])
        {
            (*cm_profile_deinit_tbl[i])();
        }
    }

    srv_bt_cm_reset_notify(g_mmi_bt_scr_cntx.handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init
 * DESCRIPTION
 *  This function is to initialize Bluetooth profiles
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_INIT);

    for (i = 0; i < (sizeof(cm_profile_init_tbl) / sizeof(mmi_bt_func_ptr)); i++)
    {
        if (cm_profile_init_tbl[i])
        {
            (*cm_profile_init_tbl[i])();
        }
    }

    /* init loopack test msg handler from At command */
	#ifdef __MMI_EM_BT_GENERAL_TEST__
    SetProtocolEventHandler(mmi_bt_loopback_req_ind_hdler, MSG_ID_MMI_L4_BT_LOOPBACK_TEST_REQ_IND);
	#endif
    /* V33 test mode support */
#ifdef __TC01__
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
#endif


    /* init bt scr context */
    /* mmi_bt_scr_init shall be called after mmi_init */
    /* because mmi_bt_scr_init will reg scr callback to context */
    mmi_bt_scr_init();
#ifdef __MMI_BT_DIALER_SUPPORT__
	mmi_bt_dialer_enhanced_init();
#endif
#ifdef __MMI_BTBOX_NOLCD__
    btb_init();
#endif  //__MMI_BTBOX_NOLCD__
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init_power
 * DESCRIPTION
 *  This function is to execute the bt power on when phone power on
 *     mmi_event_struct *evt
 * PARAMETERS
 *  mmi_event_struct *evt
 *
 *
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
MMI_RET mmi_bt_init_power(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // not in flight mode, bt on, then power on
#if !defined(__MMI_BT_DIALER_SUPPORT__ ) || defined(__MMI_TELEPHONY_SUPPORT__)
    if (srv_mode_switch_is_network_service_available())
    {
        if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_MASK_ON)
        {
            srv_bt_cm_switch_on();
        }
    }
	#else
    {
        if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_MASK_ON)
        {
            srv_bt_cm_switch_on();
        }
    }
    #endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_scr_init
 * DESCRIPTION
 *  This function is to
 *      1. reset bt screen context
 *      2. init stack cb of scr context
 *      3. init scr cb of core context
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_scr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_mask;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SCR_INIT);
    //memset(&g_mmi_bt_scr_cntx, 0, sizeof(mmi_bt_scr_cntx_struct));
    event_mask = SRV_BT_CM_EVENT_ACTIVATE |
                 SRV_BT_CM_EVENT_DEACTIVATE  |
                 SRV_BT_CM_EVENT_INQUIRY_IND |
                 SRV_BT_CM_EVENT_INQUIRY_COMPLETE |
                 SRV_BT_CM_EVENT_PAIR_IND |
                 SRV_BT_CM_EVENT_BOND_RES|
                 SRV_BT_CM_EVENT_PAIR_RES |
                 SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM |
                 SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY |
                 SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY |
                 SRV_BT_CM_EVENT_CONNECT_RES |
                 SRV_BT_CM_EVENT_DISCONNECT_IND |
                 SRV_BT_CM_EVENT_RELEASE_ALL_CONN |
#if !defined(__MMI_BT_SLIM__)
                 SRV_BT_CM_EVENT_REFRESH_PROFILE |
#endif  // !defined(__MMI_BT_SLIM__)
#ifdef __MMI_BT_AUTHORIZE__
                 SRV_BT_CM_EVENT_SET_AUTHORIZE |
                 SRV_BT_CM_EVENT_UNBLOCK |
#endif  // __MMI_BT_AUTHORIZE__
// #ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
//                  SRV_BT_CM_EVENT_SET_LIMIT_DISCOVERABLE_MODE |
// #endif  // __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
#ifdef __MMI_SIMAP_SUPPORT__
                 SRV_BT_CM_EVENT_SET_SIMAP |
#endif  // __MMI_SIMAP_SUPPORT__
#ifdef __BT_AUTO_DETECT_SUPPORT__
                 SRV_BT_CM_EVENT_CHIP_DETECT |
#endif  // __BT_AUTO_DETECT_SUPPORT__
                 SRV_BT_CM_EVENT_MYDEV_DEL |
                 SRV_BT_CM_EVENT_SET_VISIBILITY |
                 SRV_BT_CM_EVENT_SET_NAME |
                 SRV_BT_CM_EVENT_SCO_IND |
                 SRV_BT_CM_EVENT_PANIC_IND |
                 SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME |
                 SRV_BT_CM_EVENT_BEGIN_ACTIVATE |
                 
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
                 SRV_BT_CM_EVENT_FAIL_CONN_TO |
#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
                 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;

    g_mmi_bt_scr_cntx.handle = srv_bt_cm_set_notify((srv_bt_cm_notifier)mmi_bt_event_notify_handle, event_mask, NULL);
    ReadValueSlim(NVRAM_BT_POWER_STATUS, &(g_mmi_bt_scr_cntx.sys_flag), DS_BYTE);
    g_mmi_bt_scr_cntx.sys_flag &= MMI_BT_MASK_ON;

#if defined(__MMI_HIDD_SUPPORT__)
    mmi_bt_hid_scr_init();
#endif
#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    mmi_bt_anti_lost_init();
#endif
}


static void mmi_bt_begin_power_on_ind(void* para)
{
//     mmi_frm_scrn_close(GRP_ID_BT_CM_POWER_ON_CNF, SCR_BT_POWER_ON_CNF);
//     mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_POWER_ON_CNF);
//     mmi_frm_scrn_close(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_POWER_ON_CNF);
}


static void mmi_bt_begin_power_off_ind(void* para)
{
    mmi_frm_group_close(g_mmi_bt_scr_cntx.mydev_gid);

    mmi_frm_close_to_root_screen(g_mmi_bt_scr_cntx.main_gid);
    if (mmi_frm_group_is_present(GRP_ID_BT_CM_AUTH))
    {
        mmi_frm_group_close(GRP_ID_BT_CM_AUTH);
    }
    if(mmi_frm_group_is_present(GRP_ID_BT_CM_SECURITY_CNF))
    {
	mmi_frm_group_close(GRP_ID_BT_CM_SECURITY_CNF); 
    }
	if(mmi_frm_group_is_present(GRP_ID_BT_CM_PASSKEY_INPUT))
    {
	   mmi_frm_group_close(GRP_ID_BT_CM_PASSKEY_INPUT); 
    }
}

#if defined( __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) && defined(__MMI_WEARABLE_DEVICE__)
mmi_ret mmi_bt_notify_screen_lock_hdlr(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
			if(g_mmi_bt_scr_cntx.flag & MMI_BT_INQUIRY)
			{
				mmi_scr_locker_pre_lock_evt_struct* lock_event = (mmi_scr_locker_pre_lock_evt_struct*)evt;

				if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
				{
					return MMI_RET_OK;
				}
				else if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
				{
					return MMI_RET_ERR;
				}
			}
			  break;
	   default:
			return MMI_RET_OK;
	}
	return MMI_RET_OK;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_event_notify_handle
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_event_notify_handle(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (srv_hd == g_mmi_bt_scr_cntx.handle)
    {
        switch (event)
        {
            case SRV_BT_CM_EVENT_ACTIVATE:
                mmi_bt_power_switch_on_complete(para);
                break;

            case SRV_BT_CM_EVENT_DEACTIVATE:
                mmi_bt_power_switch_off_complete(para);
                break;

            case SRV_BT_CM_EVENT_INQUIRY_IND:
                mmi_bt_inq_result_notify(para);
                break;

            case SRV_BT_CM_EVENT_INQUIRY_COMPLETE:
                mmi_bt_inq_complete(para);
                break;

            case SRV_BT_CM_EVENT_PAIR_IND:
                mmi_bt_passkey_input_notify(para);
                break;

            case SRV_BT_CM_EVENT_PAIR_RES:
                mmi_bt_entry_pair_result(para);
                break;

            case SRV_BT_CM_EVENT_BOND_RES:
                mmi_bt_entry_bond_result(para);
                break;

#ifdef __MMI_BT_SIMPLE_PAIR__
            case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
                #if !defined(__MMI_BTBOX_NOLCD__)
                mmi_bt_security_user_confirm_notify(para);
                #endif  //!defined(__MMI_BTBOX_NOLCD__)
                break;

            case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
                mmi_bt_security_passkey_notify(para);
                break;

            case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
                mmi_bt_entry_security_keypress_notify(para);
                break;
#endif

            case SRV_BT_CM_EVENT_CONNECT_RES:
                mmi_bt_connect_complete(para);
                break;

            case SRV_BT_CM_EVENT_DISCONNECT_IND:
                mmi_bt_disconnect_complete(para);
                break;

            case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
                mmi_bt_release_conn_complete(para);
                break;

#if !defined(__MMI_BT_SLIM__)
            case SRV_BT_CM_EVENT_REFRESH_PROFILE:
                mmi_bt_refresh_prof_complete(para);
                break;
#endif

            case SRV_BT_CM_EVENT_MYDEV_DEL:
                mmi_bt_mydev_del_complete(para);
                break;

#ifdef __MMI_BT_AUTHORIZE__
            case SRV_BT_CM_EVENT_SET_AUTHORIZE:
                mmi_bt_set_authorize_complete(para);
                break;

            case SRV_BT_CM_EVENT_UNBLOCK:
                mmi_bt_unblock_complete(para);
                break;
#endif

            case SRV_BT_CM_EVENT_SET_VISIBILITY:
                #if !defined(__MMI_BTBOX_NOLCD__)
                mmi_bt_set_vis_complete(para);
                #endif  //!defined(__MMI_BTBOX_NOLCD__)
                break;

            case SRV_BT_CM_EVENT_SET_NAME:
                mmi_bt_set_name_complete(para);
                break;

#ifdef __MMI_SIMAP_SUPPORT__
            case SRV_BT_CM_EVENT_SET_SIMAP:
                mmi_bt_set_simap_complete((srv_bt_cm_set_simap_struct*)para);
                break;
#endif

            case SRV_BT_CM_EVENT_SCO_IND:
                mmi_bt_sco_ind(para);
                break;

            case SRV_BT_CM_EVENT_PANIC_IND:
                mmi_bt_panic_ind_pre_process();
                break;



#ifdef __BT_AUTO_DETECT_SUPPORT__
            case SRV_BT_CM_EVENT_CHIP_DETECT:
                mmi_bt_chip_status_ind(para);
                break;
#endif

            case SRV_BT_CM_EVENT_BEGIN_ACTIVATE:
                mmi_bt_begin_power_on_ind(para);
                break;
                
            case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
                mmi_bt_begin_power_off_ind(para);
                break;
#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
            case SRV_BT_CM_EVENT_FAIL_CONN_TO:
                mmi_bt_dialer_auto_reconn_and_to_ind(para);
                break;
#endif
            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_register_power_on_callback_with_result
 * DESCRIPTION
 *  This function is register the callback. CM will invoke the callback while finished power switching.
 * PARAMETERS
 *  power_on_cb_func_ptr     Application's callback.
 *                            TRUE means switching power to be ON successfuly.
 *                            FALSE means switching power failed.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_register_power_on_callback_with_result(void (*power_on_cb_func_ptr) (MMI_BOOL))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_REGISTER_PWR_ON_CALLBACK_WITH_RESULT, power_on_cb_func_ptr);
    g_mmi_bt_scr_cntx.pwr_on_cb_with_result = (void (*)(MMI_BOOL))power_on_cb_func_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_switch_flight_mode
 * DESCRIPTION
 *  This function is to turn on BT power in flight mode
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_bt_switch_flight_mode(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *mode_switch = (srv_mode_switch_notify_struct *)evt;
	srv_bt_cm_power_status_enum pwstatus;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_SWITCH_FLIGHT_MODE,
        mode_switch->select_flight_mode);
	pwstatus=srv_bt_cm_get_power_status();
    if (EVT_ID_SRV_MODE_SWITCH_SWITCH_OTHER_NOTIFY == evt->evt_id)
    {
        // flight_mode
        if (mode_switch->select_flight_mode == SRV_MODE_SWITCH_ON)
        {
            g_mmi_bt_scr_cntx.is_switching_to_flight_mode = 1;
            
            switch (pwstatus)
            {
                case SRV_BT_CM_POWER_ON:
                    g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
					#if 0
					#ifdef __MMI_BT_DIALER_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
					#endif /*__MMI_BT_DIALER_SUPPORT__*/
					#endif
                    srv_bt_cm_switch_off();
                    break;

                case SRV_BT_CM_POWER_OFF:
                #if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
                    srv_mode_switch_update_cb_func();
#endif  // __FLIGHT_MODE_SUPPORT__
                    break;

                case SRV_BT_CM_POWER_SWITCHING_ON:
                    g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
                    break;

                case SRV_BT_CM_POWER_SWITCHING_OFF:
                    g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE;
                    break;
            }
        
            /* hide status icon */

            if (!srv_earphone_is_plug_in())
            {
                wgui_status_icon_bar_reset_icon_display(STATUS_ICON_EARPHONE_INDICATOR);
            }
#ifndef __MMI_BT_IN_FLIGHT_MODE__
            if (g_mmi_bt_scr_cntx.prog_scr.gid != GRP_ID_INVALID)
            {
                mmi_frm_scrn_set_leave_proc(
                    g_mmi_bt_scr_cntx.prog_scr.gid,
                    SCR_BT_POWER_PRO,
                    NULL);
            }
            mmi_frm_group_close(g_mmi_bt_scr_cntx.main_gid);
#endif
        }
        // normal mode
        else if (mode_switch->select_flight_mode == SRV_MODE_SWITCH_OFF)
        {
            switch (pwstatus)
            {
            case SRV_BT_CM_POWER_ON:
                g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_ON_BY_FLIGHT_MODE;
                srv_bt_cm_activate_profile();
                break;

            case SRV_BT_CM_POWER_OFF:
                if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_MASK_ON)
                {
                    g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_ON_BY_FLIGHT_MODE;
                    srv_bt_cm_switch_on();
                }
                else
                {
                #if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
                    srv_mode_switch_update_cb_func();
#endif  //__FLIGHT_MODE_SUPPORT__

                }
                break;

            case SRV_BT_CM_POWER_SWITCHING_ON:
                g_mmi_bt_scr_cntx.sys_flag &= ~MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
                g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_ON_BY_FLIGHT_MODE;
                break;

            case SRV_BT_CM_POWER_SWITCHING_OFF:
                g_mmi_bt_scr_cntx.sys_flag &= ~MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
                g_mmi_bt_scr_cntx.sys_flag &= ~MMI_BT_MASK_ON_BY_FLIGHT_MODE;
                g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE;
                break;
            }
        }
    }
    else if (EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY == evt->evt_id)
    {
        g_mmi_bt_scr_cntx.is_switching_to_flight_mode = 0;
    }

    return MMI_RET_OK;
}

MMI_BOOL mmi_bt_flag_check()
{
	U32 Checkflag;
	Checkflag=MMI_BT_CONFIRM_SWITCH_POWER_OFF|MMI_BT_CONFIRM_INQ_AUDIO_DEV|
			  MMI_BT_CONFIRM_PAIRED_DEV_OPT|MMI_BT_CONFIRM_PAIRED_DEV_DEL|
			  MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL|MMI_BT_CONFIRM_INQ_ALL_DEV|
			  MMI_BT_CONFIRM_SET|MMI_BT_CONFIRM_SET_DEV_NAME|
			  MMI_BT_SET_AUDIO_PATH|MMI_BT_CONFIRM_SET_VISIBILITY|
#ifdef __MMI_BT_AUTHORIZE__
			  MMI_BT_CONFIRM_UNBLOCK|MMI_BT_CONFIRM_AUTHORIZE_REJECT|
#endif
			  MMI_BT_CONFIRM_SPECIFIC_DEV|MMI_BT_CONFIRM_CONNECT_AUDIO|
			  MMI_BT_RELEASE_AUDIO_DEV_BEFORE_CONNECT;
	if(g_mmi_bt_scr_cntx.flag & Checkflag)
		return MMI_TRUE;
	return MMI_FALSE;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_bt
 * DESCRIPTION
 *  This function is to turn on BT without showing progressing screen and popup,
 *  it is used by shell app now
 * PARAMETERS
 *  power_on_cb_func_ptr    [IN]    power on callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_bt(void (*power_on_cb_func_ptr) (MMI_BOOL))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_register_power_on_callback_with_result(power_on_cb_func_ptr);

    if (srv_bt_cm_switch_on() != SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_off_bt
 * DESCRIPTION
 *  This function is to turn off BT without showing progressing screen and popup,\
 *  it is used by shell app now
 * PARAMETERS
 *  power_off_cb_func_ptr   [IN]    power off callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_off_bt(void (*power_off_cb_func_ptr) (MMI_BOOL))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.pwr_off_cb_with_result = (void (*)(MMI_BOOL))power_off_cb_func_ptr;
	#ifdef __MMI_BT_DIALER_SUPPORT__
	if( srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_MAPC_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION) ||
        srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION)
		)
	{
		mmi_bt_dialor_disconnect(&(g_mmi_bt_scr_cntx.conn_dev_add));
	}
	#endif /*__MMI_BT_DIALER_SUPPORT__*/
    if (srv_bt_cm_get_existed_conn_num())
    {
        if (g_mmi_bt_scr_cntx.pwr_off_cb_with_result)
        {
            g_mmi_bt_scr_cntx.popup_string = STR_BT_DISCONN_ALL_CONN;

            (*g_mmi_bt_scr_cntx.pwr_off_cb_with_result)(MMI_FALSE);
            g_mmi_bt_scr_cntx.pwr_off_cb_with_result = NULL;
        }
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SCR_PWROFF);
    srv_bt_cm_switch_off();
}


#ifdef __MMI_BT_AUTO_POWER_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_auto_on
 * DESCRIPTION
 *  This function is to power on Bluetooth automatically
 * PARAMETERS
 *  profile_id        [IN] to indicate that which profile needs to auto power on BT. And CM cannot power off BT before this profile invokes mmi_bt_auto_off
 *                         although other profile wants to auto power off BT. So profiles shall invoke mmi_bt_auto_on and mmi_bt_auto_off paired.
 * RETURNS
 *  MMI_BOOL TRUE: continue to power on BT automatically
 *             FALSE: not allow to do auto power on now. Will display "Not Allowed".
 *****************************************************************************/
MMI_BOOL mmi_bt_auto_on(U32 profile_id, mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PROFILE_UUID, profile_id);

    switch (profile_id)
    {
        case SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID:
            MMI_BT_SET_FLAG(MMI_BT_OPP_CLIENT_AUTO_ON);
            break;

        case SRV_BT_CM_OBEX_IMAGING_UUID:
            MMI_BT_SET_FLAG(MMI_BT_BIP_CLIENT_AUTO_ON);
            break;

        case SRV_BT_CM_BASIC_PRINTING:
            MMI_BT_SET_FLAG(MMI_BT_BPP_CLIENT_AUTO_ON);
            break;

        default:
            break;
    }

    /* shall not check MMI_BT_EXT_CONFIRM_POWER_ON flag because profiles will mask this flag before invoking mmi_bt_auto_on */
    if (mmi_bt_flag_check()||
        mmi_frm_scrn_is_present(GRP_ID_BT_CM_POWER_ON_CNF, SCR_BT_POWER_ON_CNF, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)||
        mmi_frm_scrn_is_present(g_mmi_bt_scr_cntx.main_gid,
                    SCR_BT_POWER_ON_CNF,
                    MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
        return MMI_FALSE;
    }

    /* check if power is on, if not, turn it on */
    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        group_id = mmi_frm_group_create_ex(
            parent_gid,
            GRP_ID_BT_CM_POWER_ON_CNF,
            mmi_bt_main_group_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

        MMI_BT_SET_FLAG(MMI_BT_AUTO_ON);

#ifdef __MMI_BT_IN_FLIGHT_MODE__
        /* need to ask user to activate BT under flight mode */
    #ifdef __MMI_TELEPHONY_SUPPORT__
        if (!srv_mode_switch_is_network_service_available())
        {
            mmi_bt_display_power_on_confirm(group_id);
        }
        else
    #endif
#endif /*__MMI_BT_IN_FLIGHT_MODE__*/

        {
            mmi_bt_power_switching(group_id);
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_auto_off
 * DESCRIPTION
 *  This function is to power off Bluetooth automatically
 * PARAMETERS
 *  profile_id        [IN] to indicate that which profile needs to auto power of BT. And CM cannot power off BT before this profile invokes mmi_bt_auto_off
 *                         although other profile wants to auto power off BT. So profiles shall invoke mmi_bt_auto_on and mmi_bt_auto_off paired.
 * RETURNS
 *  MMI_BOOL TRUE: continue to power off BT automatically
 *             FALSE: not allow to do auto power off now. CM will retry later.
 *****************************************************************************/
MMI_BOOL mmi_bt_auto_off(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PROFILE_UUID, profile_id);

    switch (profile_id)
    {
        case SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID:
            MMI_BT_RESET_FLAG(MMI_BT_OPP_CLIENT_AUTO_ON);
            break;

        case SRV_BT_CM_OBEX_IMAGING_UUID:
            MMI_BT_RESET_FLAG(MMI_BT_BIP_CLIENT_AUTO_ON);
            break;

        case SRV_BT_CM_BASIC_PRINTING:
            MMI_BT_RESET_FLAG(MMI_BT_BPP_CLIENT_AUTO_ON);
            break;

        default:
            break;
    }

    /* check if auto power switching, if yes, turn it off, if power on is not auto, will not off it */
    if ((g_mmi_bt_scr_cntx.flag & MMI_BT_AUTO_ON) &&
        !(g_mmi_bt_scr_cntx.flag & MMI_BT_OPP_CLIENT_AUTO_ON) &&
        !(g_mmi_bt_scr_cntx.flag & MMI_BT_BIP_CLIENT_AUTO_ON) &&
        !(g_mmi_bt_scr_cntx.flag & MMI_BT_BPP_CLIENT_AUTO_ON))
    {
        MMI_BT_RESET_FLAG(MMI_BT_AUTO_ON);
        if (!srv_bt_cm_get_existed_conn_num())
        {
            srv_bt_cm_switch_off();
            result = MMI_TRUE;
        }
    }

    return result;
}
#endif /*__MMI_BT_AUTO_POWER_SWITCH__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_display_power_on_confirm
 * DESCRIPTION
 *  This function is display power on confirm screen
 * PARAMETERS
 *  flag         [IN]            screen flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_display_power_on_confirm(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_DISPLAY_CONFIRM_SCR, g_mmi_bt_scr_cntx.flag);

    mmi_frm_scrn_first_enter(
        group_id,
        SCR_BT_POWER_ON_CNF,
        (FuncPtr) mmi_bt_entry_power_on_confirm,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_on_confirm
 * DESCRIPTION
 *  This function is to entry power on confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_power_on_confirm(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_POWER_ON_CONFIRM);

    if (mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            (FuncPtr) NULL,
            (FuncPtr) mmi_bt_entry_power_on_confirm,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
#ifndef __MMI_BT_DIALER_SUPPORT__
    string = mmi_bt_is_bt_in_flight_mode() ?
        STR_BT_POWER_ON_IN_FLIGHT_MODE_CNF :
        STR_BT_PWR_ON_CNF;
#else
		string = STR_BT_PWR_ON_CNF;
#endif
#ifndef __MMI_BT_DIALER_SUPPORT__
    ShowCategory66Screen(
        STR_GLOBAL_BLUETOOTH,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*)GetString(string),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);
#else
    ShowCategory163Screen(
        (UI_string_type) GetString(STR_GLOBAL_YES),
        (PU8)GetImage(IMG_GLOBAL_YES),
        (UI_string_type) GetString(STR_GLOBAL_NO),
        (PU8)GetImage(IMG_GLOBAL_NO),
        (UI_string_type)GetString(string),
        NULL,
        NULL);
#endif

    SetLeftSoftkeyFunction(mmi_bt_entry_power_switch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_entry_power_on_confirm_rsk_hdler, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mmi_bt_entry_power_switch, KEY_EVENT_UP);
#ifdef _MMI_BWUI_BT_SLIM_
		redraw_left_softkey();
		redraw_right_softkey();
#endif 
    mmi_frm_scrn_set_leave_proc(
        info->group_id,
        SCR_BT_POWER_ON_CNF,
        (mmi_proc_func)mmi_bt_entry_power_on_confirm_leave_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_on_confirm_leave_proc
 * DESCRIPTION
 *  This function is proc function of delete callback of power on confirm screen
 * PARAMETERS
 *  NULL         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bt_entry_power_on_confirm_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            mmi_bt_entry_power_on_confirm_del_cb();
            break;

        case EVT_ID_SCRN_DEINIT:
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_on_confirm_del_cb
 * DESCRIPTION
 *  This function is delete callback of power on confirm screen
 * PARAMETERS
 *  NULL         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_entry_power_on_confirm_del_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_ENTRY_POWER_ON_CONFIRM_DEL_CB,
        g_mmi_bt_scr_cntx.flag,
        g_mmi_bt_scr_cntx.pwr_on_cb_with_result);

    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_INQ_AUDIO_DEV);
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_OPT);
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_INQ_ALL_DEV);
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET);
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET_DEV_NAME);
    MMI_BT_RESET_FLAG(MMI_BT_SET_AUDIO_PATH);
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET_VISIBILITY);
#ifdef __MMI_BT_AUTHORIZE__
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_UNBLOCK);
#endif /* __MMI_BT_AUTHORIZE__ */
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_CONNECT_AUDIO);
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SPECIFIC_DEV);
#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && !defined(__MMI_BT_BTBOX_NOLCD__)
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_ANTILOST_SET);
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ && !__MMI_BT_BTBOX_NOLCD__ */

    /*it is for auto power on, it is not CUI*/
    if (g_mmi_bt_scr_cntx.pwr_on_cb_with_result)
    {
        g_mmi_bt_scr_cntx.popup_string = STR_BT_POWER;
        (*g_mmi_bt_scr_cntx.pwr_on_cb_with_result)(MMI_FALSE);
        mmi_bt_register_power_on_callback_with_result(NULL);
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_on_confirm_rsk_hdler
 * DESCRIPTION
 *  This function is RSK handler of power on confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_power_on_confirm_rsk_hdler(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_POWER_ON_CONFIRM_RSK_HDLER);
    /* reset confirm flag */
    /* only one confirm flag is set at one time */
    if (g_mmi_bt_scr_cntx.pwr_cnf_cui_state == MMI_TRUE)
    {
        cui_bt_power_on_result_hdlr(MMI_FALSE);
        //g_mmi_bt_scr_cntx.pwf_cnf_cui_notify_flag = MMI_TRUE;
    }
    else if (g_mmi_bt_scr_cntx.device_select_cui_state == MMI_TRUE)
    {
        cui_bt_device_select_hdlr(MMI_FALSE, 0, 0, 0);
        //g_mmi_bt_scr_cntx.pwf_cnf_cui_notify_flag = MMI_TRUE;
    }
    else
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_INQ_AUDIO_DEV);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_OPT);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_INQ_ALL_DEV);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET);
        MMI_BT_RESET_FLAG(MMI_BT_SET_AUDIO_PATH);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET_DEV_NAME);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET_VISIBILITY);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SPECIFIC_DEV);
#ifdef __MMI_BT_AUTHORIZE__
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_UNBLOCK);
#endif /* __MMI_BT_AUTHORIZE__ */
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_CONNECT_AUDIO);
        MMI_BT_RESET_FLAG(MMI_BT_AUTO_ON);
#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && !defined(__MMI_BT_BTBOX_NOLCD__)
	MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_ANTILOST_SET);
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ && !__MMI_BT_BTBOX_NOLCD__ */
        if (g_mmi_bt_scr_cntx.pwr_on_cb_with_result)
        {
            g_mmi_bt_scr_cntx.popup_string = STR_BT_POWER;
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_BT_G7_BT_INVOKE_PWR_ON_CALLBACK_WITH_RESULT,
                g_mmi_bt_scr_cntx.pwr_on_cb_with_result,
                MMI_FALSE);
            (*g_mmi_bt_scr_cntx.pwr_on_cb_with_result)(MMI_FALSE);
            mmi_bt_register_power_on_callback_with_result(NULL);
        }
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_switch
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_power_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_POWER_SWITCH);

    group_id = mmi_frm_group_get_active_id();
    if (group_id < GRP_ID_BT_CM || group_id > GRP_ID_BT_CM_PROGRESS)
    {
        group_id = mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_BT_CM_POWER_ON_CNF,
            mmi_bt_main_group_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    mmi_bt_power_switching(group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_power_switch
 * DESCRIPTION
 *  This function is to activate or deactivate bt function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_switching(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_POWER_SWITCHING);

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
    {
        /******************************/
        /* Switch power off */
        /******************************/
        if (srv_bt_cm_get_existed_conn_num() > 0)
        {
#ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
            mmi_bt_display_release_connection_confirm(group_id, MMI_BT_RELEASE_ALL_CONNECTION);
            MMI_BT_SET_FLAG(MMI_BT_CONFIRM_SWITCH_POWER_OFF);

#else
            mmi_popup_display_ext(
                STR_BT_DISCONN_ALL_CONN,
                MMI_EVENT_FAILURE,
                NULL);
#endif
            return;
        }

#if defined(__MMI_A2DP_SUPPORT__)
        mmi_a2dp_bt_power_off_callback(MMI_TRUE);
#endif

        srv_bt_cm_switch_off();

        if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
        {
            MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SWITCH_POWER_OFF);
            MMI_BT_SET_FLAG(MMI_BT_POWER_SWITCH);
            return;
        }

        mmi_bt_show_progress_scr(
            group_id,
            SCR_BT_POWER_PRO,
            STR_BT_POWER,
            STR_BT_SWITCHING,
            NULL);
        mmi_frm_scrn_set_leave_proc(
            group_id,
            SCR_BT_POWER_PRO,
            mmi_bt_power_progress_leave_proc);
        MMI_BT_SET_FLAG(MMI_BT_POWER_SWITCH);
    }
    else
    {
        /******************************/
        /* Switch power on */
        /******************************/
        if (srv_bt_cm_switch_on() == SRV_BT_CM_RESULT_SUCCESS)
        {
            MMI_BT_SET_FLAG(MMI_BT_POWER_SWITCH);
           
            mmi_bt_show_progress_scr(
                group_id,
                SCR_BT_POWER_PRO,
                STR_BT_POWER,
                STR_BT_SWITCHING,
                NULL);
            mmi_frm_scrn_set_leave_proc(
                group_id,
                SCR_BT_POWER_PRO,
                mmi_bt_power_progress_leave_proc);
        }
        else
        {
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
        }

        mmi_frm_scrn_set_leave_proc(group_id, SCR_BT_POWER_ON_CNF, NULL);
        mmi_frm_scrn_close(group_id, SCR_BT_POWER_ON_CNF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_switch_on_complete
 * DESCRIPTION
 *  This function is to handle power switch on complete
 * PARAMETERS
 *  result      [IN]            result of power switch on
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_switch_on_complete(void *para)   /* power switch rsp */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_activate_struct *event = (srv_bt_cm_activate_struct *)para;
    
    mmi_id group_id = g_mmi_bt_scr_cntx.prog_scr.gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_POWER_SWITCH_ON_COMPLETE, g_mmi_bt_scr_cntx.flag);


#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_op11_hs32_cnx_bt_update();
#endif

    mmi_bt_update_status_icon();
    if (g_mmi_bt_scr_cntx.main_menu_gid == mmi_frm_group_get_active_id())
    {
            mmi_bt_refresh_screen();
    }

    if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_MASK_OFF_BY_FLIGHT_MODE)
    {
        srv_bt_cm_switch_off();
        g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_ON;
    }
    else if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_MASK_ON_BY_FLIGHT_MODE)
    {
        g_mmi_bt_scr_cntx.sys_flag &= ~MMI_BT_MASK_ON_BY_FLIGHT_MODE;

    #if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
        srv_mode_switch_update_cb_func();
#endif  // __FLIGHT_MODE_SUPPORT__
        /* deal with the case:
         * 1. power on BT
         * 2. swith from flight mode to normal mode
         * so, to ensure all the profiles(like DUN, fax that will not be activated in flight mode) 
         */
        srv_bt_cm_activate_profile();
    }
    else
    {
        if (event->result)
        {
            g_mmi_bt_scr_cntx.sys_flag |= MMI_BT_MASK_ON;
        }

        if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE)
        {
            g_mmi_bt_scr_cntx.sys_flag &= ~MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE;
        #if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
            srv_mode_switch_update_cb_func();
#endif  // __FLIGHT_MODE_SUPPORT__
        }
    }

    WriteValueSlim(NVRAM_BT_POWER_STATUS, &(g_mmi_bt_scr_cntx.sys_flag), DS_BYTE);

    if (g_mmi_bt_scr_cntx.pwr_cnf_cui_state == MMI_TRUE)
    {
        cui_bt_power_on_result_hdlr(event->result);
        mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.main_gid, SCR_BT_POWER_PRO);
        return;
    }

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
#ifdef __MMI_HFP_SUPPORT__
        mmi_btaud_attach(GRP_ID_INVALID, &(g_mmi_bt_scr_cntx.far_end_dev_add));
#endif  // __MMI_HFP_SUPPORT__
        return;
    }


    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_ALL_DEV)
    {
        mmi_bt_inquiry_dev();
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT)
    {
        mmi_bt_stop_progress_scr(group_id, SCR_BT_POWER_PRO);
         #ifndef __MMI_BT_DIALER_SUPPORT__
        mmi_bt_entry_mydev_opt();
        #else
        if(MMI_TRUE == mmi_bt_dialer_get_cent_flag())
        {
            mmi_bt_dialer_cent();
             mmi_bt_dialer_set_cent_flag(MMI_FALSE);
        }
        else
        {
            mmi_bt_entry_mydev_opt();
        }
       #endif
    }
#ifndef  _MMI_BT_ULTRA_SLIM_
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET)
    {
        mmi_bt_entry_set_menu();
    }

	if (g_mmi_bt_scr_cntx.flag & MMI_BT_SET_AUDIO_PATH)
    {
        mmi_bt_entry_set_audio_pth_menu();
    }

if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV)
    {
        mmi_bt_inquiry_aud_dev();
    }
#else /*_MMI_BT_ULTRA_SLIM_*/
		
	#if defined(__MMI_HIDD_SUPPORT__)
	else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET)
	{
		mmi_bt_entry_remote_control();
	}
	#endif  /*defined(__MMI_HIDD_SUPPORT__)*/

#endif
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET_DEV_NAME)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET_DEV_NAME);
        mmi_bt_entry_set_name();
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET_VISIBILITY)
    {
        mmi_bt_entry_set_vis();
    }
#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && !defined(__MMI_BT_BTBOX_NOLCD__)
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_ANTILOST_SET)
    {
        mmi_bt_entry_anti_lost_setting();
    }
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ && !__MMI_BT_BTBOX_NOLCD__ */
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV)
    {
        mmi_bt_entry_mydev_menu();
    }
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_CONNECT_AUDIO)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_CONNECT_AUDIO);
        mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.mydev_gid);
    }
#ifdef __MMI_BT_AUTHORIZE__
    else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_UNBLOCK)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_UNBLOCK);
        if (g_mmi_bt_scr_cntx.mydev_gid != GRP_ID_INVALID)
        {
            mmi_bt_entry_mydev_unblock();
        }
    }
#endif /*__MMI_BT_AUTHORIZE__*/
    else if (g_mmi_bt_scr_cntx.pwr_on_cb_with_result)
    {
        mmi_bt_power_on_callback();
    }
    else
    {
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_POWER_SWITCH)
        {
            if (!(event->result))
            {
                mmi_frm_nmgr_popup(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_FAILURE,
                    (WCHAR*)GetString(STR_GLOBAL_ERROR));
            }

            MMI_BT_RESET_FLAG(MMI_BT_POWER_SWITCH);
        }
    }

    mmi_bt_stop_progress_scr(group_id, SCR_BT_POWER_PRO);
    mmi_frm_scrn_close(GRP_ID_BT_CM_POWER_ON_CNF, SCR_BT_POWER_ON_CNF);
    mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_POWER_ON_CNF);
    mmi_frm_scrn_close(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_POWER_ON_CNF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_switch_off_complete
 * DESCRIPTION
 *  This function is to handle power switch off complete
 * PARAMETERS
 *  result      [IN]           result of power switch off
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_switch_off_complete(void *para)  /* power switch rsp */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_deactivate_struct *event = (srv_bt_cm_deactivate_struct *)para;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_POWER_SWITCH_OFF_COMPLETE, event->result);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SCR_STATUS, g_mmi_bt_scr_cntx.flag);

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_op11_hs32_cnx_bt_update();
#endif

#if defined(__MMI_A2DP_SUPPORT__)
    mmi_a2dp_bt_power_off_callback(event->result);
#endif

    mmi_bt_update_status_icon();
    if (g_mmi_bt_scr_cntx.main_menu_gid == mmi_frm_group_get_active_id())
    {
            mmi_bt_refresh_screen();
    }


    mmi_bt_register_power_on_callback_with_result(NULL);

    if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_MASK_OFF_BY_FLIGHT_MODE)
    {
        g_mmi_bt_scr_cntx.sys_flag &= ~MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
    #if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
        srv_mode_switch_update_cb_func();
#endif  // __FLIGHT_MODE_SUPPORT__
    }
    else
    {
        if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE)
        {
            g_mmi_bt_scr_cntx.sys_flag &= ~MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE;
        #if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
            srv_mode_switch_update_cb_func();
#endif  // __FLIGHT_MODE_SUPPORT__
        }

        g_mmi_bt_scr_cntx.sys_flag &= ~MMI_BT_MASK_ON;
    }

    WriteValueSlim(NVRAM_BT_POWER_STATUS, &(g_mmi_bt_scr_cntx.sys_flag), DS_BYTE);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        srv_bt_cm_antenna_off();
        MMI_BT_RESET_FLAG(MMI_BT_SCO_FAR_END_LP_TESTING);
        return;
    }

    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.prog_scr.gid, SCR_BT_POWER_PRO);

    if (g_mmi_bt_scr_cntx.pwr_off_cb_with_result)
    {
        g_mmi_bt_scr_cntx.popup_string = STR_BT_POWER;
        (*g_mmi_bt_scr_cntx.pwr_off_cb_with_result)(event->result);
        g_mmi_bt_scr_cntx.pwr_off_cb_with_result = NULL;
        return;
    }

    if (event->result)
    {
        MMI_BT_RESET_FLAG(MMI_BT_POWER_SWITCH);
        mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_AUTH_CONFIRM);
    }
#ifdef __MMI_BT_DIALER_SUPPORT__
	mmi_bt_dialer_app_emit_event(EVT_ID_DIALER_DISCONN_EVENT_ID, NULL, MMI_TRUE);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_callback
 * DESCRIPTION
 *  This function is for power on callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.pwr_on_cb_with_result)
    {
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            MMI_BT_G7_BT_INVOKE_PWR_ON_CALLBACK_WITH_RESULT,
            g_mmi_bt_scr_cntx.pwr_on_cb_with_result,
            MMI_TRUE);
        (*g_mmi_bt_scr_cntx.pwr_on_cb_with_result)(MMI_TRUE);
        mmi_bt_register_power_on_callback_with_result(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_main_hilight_handler
 * DESCRIPTION
 *  This function is Bluetooth main highiight handler
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_main_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_MAIN_HILIGHT_HANDLER);
#ifndef __MMI_BTBOX_NOLCD__
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#endif
    SetLeftSoftkeyFunction(mmi_bt_entry_main_menu, KEY_EVENT_UP);

   
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mmi_bt_entry_main_menu, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_main_menu
 * DESCRIPTION
 *  This function is Main menu entry function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MAIN_MENU);

#ifdef __FLIGHT_MODE_SUPPORT__
#ifndef __MMI_BT_IN_FLIGHT_MODE__
  #ifdef __MMI_TELEPHONY_SUPPORT__
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        /* prevent from entry BT main menu from shortcut */
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
        return;
    }
  #endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif /*__MMI_BT_IN_FLIGHT_MODE__*/
#endif
    switch (srv_bt_cm_get_power_status())
    {
        case SRV_BT_CM_POWER_SWITCHING_ON:
            mmi_popup_display_ext(
                STR_BT_NOT_READY,
                MMI_EVENT_FAILURE,
                NULL);
            return;

        case SRV_BT_CM_POWER_SWITCHING_OFF:
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
            return;

        default:
            break;
    }
    
    if ((g_mmi_bt_scr_cntx.flag & MMI_BT_OPP_CLIENT_AUTO_ON) ||
        (g_mmi_bt_scr_cntx.flag & MMI_BT_BIP_CLIENT_AUTO_ON) ||
        (g_mmi_bt_scr_cntx.flag & MMI_BT_BPP_CLIENT_AUTO_ON))
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
        return;
    }

    g_mmi_bt_scr_cntx.main_gid = mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BT_CM,
        mmi_bt_main_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_mmi_bt_scr_cntx.main_menu_gid = cui_menu_create_and_run(
        g_mmi_bt_scr_cntx.main_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_CONN_BT_MAIN,
        MMI_FALSE,
        (void*)MENU_CONN_BT_MAIN);
}


MMI_ID mmi_bt_launch_bt(void* param, U32 param_size)
{
    mmi_bt_entry_main_menu();
    return g_mmi_bt_scr_cntx.main_menu_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_main_menu_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_main_menu_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    srv_bt_cm_power_status_enum status = srv_bt_cm_get_power_status();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(
                menu_evt->sender_id,
                CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

            if ((status == SRV_BT_CM_POWER_ON) || (status == SRV_BT_CM_POWER_SWITCHING_OFF))
            {
                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_CONN_BT_POWER,
                    (WCHAR*)GetString(STR_GLOBAL_ON));
            }
            else
            {
                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_CONN_BT_POWER,
                    (WCHAR*)GetString(STR_GLOBAL_OFF));
            }
 
#ifndef     _MMI_BT_ULTRA_SLIM_
			 cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_CONN_BT_SET_AUDIO_PATH,
                mmi_bt_get_audio_pth());
			 {
			  srv_bt_cm_dev_struct *dev_p;
                dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_host_dev_info();

                mmi_bt_get_display_bt_address(
                    g_mmi_bt_scr_cntx.ui_buf,
                    &(dev_p->bd_addr));

                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_DEV_ADDR,
                    (WCHAR*)g_mmi_bt_scr_cntx.ui_buf);
			}
#endif 
#ifndef __MMI_BT_TEMP_VISIBILITY__
            switch (srv_bt_cm_get_visibility())
            {
                case SRV_BT_CM_VISIBILITY_ON:
                    cui_menu_set_item_hint(
                        menu_evt->sender_id,
                        MENU_CONN_BT_SET_VIS,
                        (WCHAR*)GetString(STR_GLOBAL_ON));
                    break;

                case SRV_BT_CM_VISIBILITY_OFF:
                    cui_menu_set_item_hint(
                        menu_evt->sender_id,
                        MENU_CONN_BT_SET_VIS,
                        (WCHAR*)GetString(STR_GLOBAL_OFF));
                    break;
            }
                    
#else /*!defined(__MMI_BT_TEMP_VISIBILITY__)*/

            {
                U16 hintStr;
                switch (srv_bt_cm_get_visibility())
                {
                    case SRV_BT_CM_VISIBILITY_ON:
                        hintStr = STR_BT_DEV_SET_VIS_PERMANENT_ON;;
                        break;

                    case SRV_BT_CM_VISIBILITY_TEMPORARY_ON:
                        hintStr = STR_BT_DEV_SET_VIS_TEMPORARY_ON;
                        break;

                    case SRV_BT_CM_VISIBILITY_OFF:
                    default:
                        hintStr = STR_GLOBAL_OFF;
                        break;
                }

                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_VIS,
                    (WCHAR*)GetString(hintStr));
            }
#endif /*!defined(__MMI_BT_TEMP_VISIBILITY__)*/

            {
                srv_bt_cm_dev_struct *host_dev_p;

                host_dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_host_dev_info();

                mmi_chset_utf8_to_ucs2_string(
                    (U8 *)g_mmi_bt_scr_cntx.ui_buf,
                    SRV_BT_CM_BD_NAME_UCS2_LEN,
                    host_dev_p->name);

                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_NAME,
                    (WCHAR*)g_mmi_bt_scr_cntx.ui_buf);
            }

        #if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && !defined(__MMI_BT_BTBOX_NOLCD__)
            {
		/*if(srv_bt_cm_get_existed_conn_num() == 0) 
		 {
			cui_menu_set_item_hint(
				menu_evt->sender_id,
				MENU_CONN_BT_SET_ANTI_LOST,
				(WCHAR*)GetString(STR_BT_ANTI_LOST_PRE_ENTRY));
		  }
		else*/
		  {
			if(mmi_bt_anti_lost_get_status() == MMI_BT_ANTI_LOST_ON) //if init
				  cui_menu_set_item_hint(
					menu_evt->sender_id,
					MENU_CONN_BT_SET_ANTI_LOST,
					(WCHAR*)GetString(STR_GLOBAL_ON));
			 else
				  cui_menu_set_item_hint(
				        menu_evt->sender_id,
				        MENU_CONN_BT_SET_ANTI_LOST,
					(WCHAR*)GetString(STR_GLOBAL_OFF));
                }
            }
        #endif /*__MMI_BT_ANTI_LOST_BY_RSSI__ && !__MMI_BT_BTBOX_NOLCD__ */
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
                    if ((SRV_BT_CM_POWER_SWITCHING_ON == status) ||
                        (SRV_BT_CM_POWER_SWITCHING_OFF == status))
                    {
                        mmi_popup_display_ext(
                            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                            MMI_EVENT_FAILURE,
                            NULL);
                        break;
                    }

            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_CONN_BT_POWER:
                {
#ifndef __MMI_BT_DIALER_SUPPORT__

                    if (mmi_bt_is_bt_in_flight_mode())
                    {
                 
                        if (SRV_BT_CM_POWER_OFF == status)
                        {
                            mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.main_gid);
                        }
                        else				
                        {
                            mmi_bt_power_switching(g_mmi_bt_scr_cntx.main_gid);
                        }
                    }
                    else
                    {
                        mmi_bt_power_switching(g_mmi_bt_scr_cntx.main_gid);
                    }

#else
                    if (srv_bt_cm_get_busy_dev() != NULL || srv_bt_cm_is_profile_connecting())
					{
						mmi_frm_nmgr_popup(
							MMI_SCENARIO_ID_DEFAULT,
							MMI_EVENT_FAILURE,
						   (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));
					}      
					else
					{
						mmi_bt_power_switching(g_mmi_bt_scr_cntx.main_gid);
					}      
#endif
                }
                break;

                case MENU_CONN_BT_SET_VIS:
                    mmi_bt_entry_set_vis();
                    break;
#ifndef __MMI_BT_DIALER_SUPPORT__
                case MENU_CONN_BT_MYDEV:
                    mmi_bt_pre_entry_mydev_menu();
                    break;
#endif
#ifndef _MMI_BT_ULTRA_SLIM_
                case MENU_CONN_BT_SCH_AUDIO_DEV:
                    mmi_bt_inquiry_aud_dev();
                    break;
#endif 

                case MENU_CONN_BT_SET_NAME:
                    if (status == SRV_BT_CM_POWER_OFF)
                    {
                        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_SET_DEV_NAME);
                        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.main_gid);
                    }
                    else
                    {
                        mmi_bt_entry_set_name();
                    }
                    break;

#ifndef _MMI_BT_ULTRA_SLIM_
                case MENU_CONN_BT_SET:
                    mmi_bt_entry_set_menu();
                    break;
#else /*_MMI_BT_ULTRA_SLIM_*/
	
#if defined(__MMI_HIDD_SUPPORT__)
				case MENU_CONN_BT_REMOTE_CONTROL:
					mmi_bt_entry_remote_control();
					break;
#endif  /*defined(__MMI_HIDD_SUPPORT__)*/
#endif 

#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        #if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && !defined(__MMI_BT_BTBOX_NOLCD__)
		case MENU_CONN_BT_SET_ANTI_LOST:
			#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
		    {
			mmi_bt_entry_anti_lost_setting();
		    }
		break;
        #endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ && !__MMI_BT_BTBOX_NOLCD__ */

                default:
                    break;
            }
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_CONN_BT_POWER:
                {
                    if ((status == SRV_BT_CM_POWER_ON) || (status == SRV_BT_CM_POWER_SWITCHING_OFF))
                    {
                        cui_menu_change_left_softkey_string(
                            menu_evt->sender_id,
                            (WCHAR*)GetString(STR_GLOBAL_OFF));
                    }
                    else
                    {
                        cui_menu_change_left_softkey_string(
                            menu_evt->sender_id,
                            (WCHAR*)GetString(STR_GLOBAL_ON));
                    }
                }
                break;

                case MENU_CONN_BT_SET_VIS:
                {
#ifndef __MMI_BT_TEMP_VISIBILITY__
                    switch (srv_bt_cm_get_visibility())
                    {
                        case SRV_BT_CM_VISIBILITY_ON:
                            cui_menu_change_left_softkey_string(
                                menu_evt->sender_id,
                                (WCHAR*)GetString(STR_GLOBAL_OFF));
                            break;

                        case SRV_BT_CM_VISIBILITY_OFF:
                            cui_menu_change_left_softkey_string(
                                menu_evt->sender_id,
                                (WCHAR*)GetString(STR_GLOBAL_ON));
                            break;
                    }
                    
#else /*!defined(__MMI_BT_TEMP_VISIBILITY__)*/
                    {
                        cui_menu_change_left_softkey_string(
                            menu_evt->sender_id,
                            (WCHAR*)GetString(STR_GLOBAL_OK));
                    }
                    
#endif /*!defined(__MMI_BT_TEMP_VISIBILITY__)*/
                }
                break;

#ifndef _MMI_BT_ULTRA_SLIM_
				case MENU_CONN_BT_SET_DEV_ADDR:
                {
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        NULL);
                    cui_menu_change_center_softkey_content(
                        menu_evt->sender_id,
                        (WCHAR*)NULL,
                        (UI_image_type)NULL);
                }
				break;
#endif 
				case MENU_CONN_BT_SET_NAME:
                    #ifndef __MMI_BT_DIALER_SUPPORT__
                case MENU_CONN_BT_MYDEV:
                    #endif
#ifndef _MMI_BT_ULTRA_SLIM_
                case MENU_CONN_BT_SCH_AUDIO_DEV:
                case MENU_CONN_BT_SET:
#endif
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        (WCHAR*)GetString(STR_GLOBAL_OK));
                    break;

            #if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && !defined(__MMI_BT_BTBOX_NOLCD__)
		case MENU_CONN_BT_SET_ANTI_LOST:
                   cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        (WCHAR*)GetString(STR_GLOBAL_OK));
                    break;
            #endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ && !__MMI_BT_BTBOX_NOLCD__ */

                default:
                    break;
            }
        }
        break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_main_menu_leave_proc
 * DESCRIPTION
 *  This function is Main menu leave proc
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
// mmi_ret mmi_bt_main_menu_leave_proc(mmi_event_struct *evt)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     switch (evt->evt_id)
//     {
//         case EVT_ID_SCRN_GOBACK:
//         case EVT_ID_SCRN_GOBACK_IN_END_KEY:
//         case EVT_ID_SCRN_DELETE_REQ:
//         case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
//             break;
//         case EVT_ID_SCRN_DEINIT:
//         default:
//             break;
//     }
//     return MMI_RET_OK;
// }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_main_group_proc
 * DESCRIPTION
 *  This function is BT CM Main screen group proc function
 *  It will handle all event on the screen group
 * PARAMETERS
 *  param       [IN]        MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_main_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            g_mmi_bt_scr_cntx.main_gid = GRP_ID_BT_CM;
            break;

        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:
            g_mmi_bt_scr_cntx.main_gid = 0;
			#ifdef __MMI_BT_DIALER_SUPPORT__
				srv_bt_cm_set_btdialor_app_mode(MMI_FALSE);
			#endif //__MMI_BT_DIALER_SUPPORT__

            MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SWITCH_POWER_OFF);
            MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_DEL);
            MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL);
            // #ifdef __MMI_SIMAP_SUPPORT__
            //             MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SIMAP_SET);
            // #endif  // __MMI_SIMAP_SUPPORT__
            MMI_BT_RESET_FLAG(MMI_BT_RELEASE_AUDIO_DEV_BEFORE_CONNECT);

#ifdef __MMI_BT_AUTHORIZE__
            MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_AUTHORIZE_REJECT);
#endif /* __MMI_BT_AUTHORIZE__ */
            break;

        case EVT_ID_POPUP_QUIT:
            break;

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
      #ifdef __MMI_BT_DIALER_SUPPORT__
			mmi_btdialer_cm_app_exit_func();
			#endif //__MMI_BT_DIALER_SUPPORT__
            break;

        /* menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            mmi_bt_menu_cui_proc(param);
            break;

        /* editor CUI related events*/
        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_DEINIT:
            mmi_bt_editor_cui_proc(param);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_menu_cui_proc
 * DESCRIPTION
 *  This function is BT CM menu CUI proc function
 *  It is responsible for handling menu CUI related events
 * PARAMETERS
 *  param       [IN]        MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_menu_cui_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)param;
    U32 user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_default_title_image(
                menu_evt->sender_id,
                get_image(GetRootTitleIcon(MENU_CONN_BT_MAIN)));
      	   #ifdef __MMI_BTD_BOX_UI_STYLE__
	    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_CONN_BT_SET_NAME, MMI_TRUE);
	   #endif/*__MMI_BTD_BOX_UI_STYLE__*/

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_evt->parent_menu_id)
            {
                case MENU_CONN_BT_MAIN:
                    return mmi_bt_main_menu_group_proc(param);

            #ifdef __MMI_BT_TEMP_VISIBILITY__
                case MENU_CONN_BT_SET_VIS:
                    return mmi_bt_entry_set_vis_group_proc(param);
            #endif


                case SCR_BT_MYDEV_OPT:
            #ifdef __MMI_BT_DIALER_SUPPORT__
				if(srv_bt_cm_get_btdialor_app_mode() != MMI_TRUE)
					{
                    return mmi_bt_entry_mydev_opt_group_proc(param);
					}
					else
					{
						return mmi_bt_entry_dialor_mydev_opt_group_proc(param);
					}
            #else
                   return mmi_bt_entry_mydev_opt_group_proc(param);
            #endif
            #if 0
/* under construction !*/
/* under construction !*/
            #endif

            #ifdef __MMI_BT_DEF_SEND_DEVICE__
                case SCR_BT_SEND_DEVICE_OPTION:
                    return mmi_bt_entry_dev_select_opt_group_proc(param);
            #endif
			#ifndef _MMI_BT_ULTRA_SLIM_
                case MENU_CONN_BT_SET:
                    return mmi_bt_set_menu_group_proc(param);
			#endif 

            #ifdef __MMI_BT_AUTHORIZE__
                case MENU_CONN_BT_MYDEV_AUTHORIZE:
                    return mmi_bt_entry_mydev_authorize_group_proc(param);
            #endif

            #if !defined(__MMI_BT_SLIM__)
                case SCR_BT_MYDEV_SUP_PROFILE:
                    return mmi_bt_entry_mydev_servic_list_group_proc(param);
            #endif
			#ifndef _MMI_BT_ULTRA_SLIM_
                case MENU_CONN_BT_SET_AUDIO_PATH:
                    return mmi_bt_entry_set_audio_pth_group_proc(param);
			#endif 
                default:
                    return MMI_RET_OK;
            }

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                switch (menu_evt->parent_menu_id)
                {
                    case MENU_CONN_BT_MAIN:
                        return mmi_bt_main_menu_group_proc(param);

                #ifdef __MMI_BT_TEMP_VISIBILITY__
                    case MENU_CONN_BT_SET_VIS:
                        return mmi_bt_entry_set_vis_group_proc(param);
                #endif

                    //case SCR_BT_MYDEV:
                    //    return mmi_bt_entry_mydev_menu_group_proc(param);

                #if 0
/* under construction !*/
/* under construction !*/
                #endif
#ifndef _MMI_BT_ULTRA_SLIM_
                    case MENU_CONN_BT_SET:
                        return mmi_bt_set_menu_group_proc(param);
#endif

                #ifdef __MMI_BT_AUTHORIZE__
                    case MENU_CONN_BT_MYDEV_AUTHORIZE:
                        return mmi_bt_entry_mydev_authorize_group_proc(param);
                #endif
#ifndef _MMI_BT_ULTRA_SLIM_
                    case MENU_CONN_BT_SET_AUDIO_PATH:
                        return mmi_bt_entry_set_audio_pth_group_proc(param);
#endif 
                    default:
                        return MMI_RET_OK;
                }
            }

            //case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            //mmi_bt_entry_mydev_menu_group_proc(param);
            //break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            user_data = (U32)menu_evt->app_data;
            switch (user_data)
            {
                case MENU_CONN_BT_MAIN:
                    cui_menu_close(menu_evt->sender_id);
                    g_mmi_bt_scr_cntx.main_menu_gid = 0;
                    return MMI_RET_OK;

                //case SCR_BT_MYDEV:
                //    return mmi_bt_entry_mydev_menu_group_proc(param);

                case SCR_BT_MYDEV_OPT:
                    cui_menu_close(menu_evt->sender_id);
                    g_mmi_bt_scr_cntx.mydev_opt_menu_gid = 0;
                    return MMI_RET_OK;

                default:
                    cui_menu_close(menu_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_editor_cui_proc
 * DESCRIPTION
 *  This function is BT CM menu CUI proc function
 *  It is responsible for handling menu CUI related events
 * PARAMETERS
 *  param       [IN]        MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_editor_cui_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        /* when user finish edit */
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            scr_id = cui_fseditor_get_parent_data(g_mmi_bt_scr_cntx.fseditor_gid);
            cui_fseditor_get_text(
                g_mmi_bt_scr_cntx.fseditor_gid,
                g_mmi_bt_scr_cntx.scr_buf,
                MMI_BT_SCR_BUF_SIZE);

            switch (scr_id)
            {
                case SCR_BT_MYDEV_REN:
                    mmi_bt_entry_mydev_ren_proc();
                    break;

                case SCR_BT_SET_NAME:
                    mmi_bt_entry_set_name_proc();
                    break;

                default:
                    break;
            }
        }
        break;

        /* when user cancel edit */
        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(g_mmi_bt_scr_cntx.fseditor_gid);
            g_mmi_bt_scr_cntx.fseditor_gid = 0;
            break;

        case EVT_ID_CUI_FSEDITOR_DEINIT:
            g_mmi_bt_scr_cntx.fseditor_gid = 0;
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry_dev
 * DESCRIPTION
 *  This function is to entry My device search
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inquiry_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cod;
    U16 title_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the twice inquiry operation while bt is just on and wanna do the inquiry */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_SCH);
		#ifdef __BT_VER_PRE21_SINGLE_LINK__
		if(srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION)||
			srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)||
			srv_bt_cm_is_profile_connected(SRV_BT_CM_OPP_CONNECTION))
			{
				 mmi_bt_popup_display(
                        STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                        MMI_EVENT_FAILURE,
                        g_mmi_bt_scr_cntx.mydev_gid);
				return;
			}
		#endif 
    //if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_ALL_DEV)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_INQ_ALL_DEV);
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_INQ_ALL_DEV);
        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.mydev_gid);
        return;
    }

    if (g_mmi_bt_scr_cntx.mydev_gid != GRP_ID_INVALID)
    {
        if (mmi_frm_scrn_is_present(
                g_mmi_bt_scr_cntx.mydev_gid,
                SCR_BT_SCH_DISCONNECT_SCO,
                MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_SCH_DISCONNECT_SCO);
        }

        title_str_id = STR_BT_SCH_ALL_DEV;
        cod = g_mmi_bt_scr_cntx.dev_cod_mask;

        MMI_BT_SET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);
        mmi_bt_inquiry(g_mmi_bt_scr_cntx.mydev_gid, cod, title_str_id, mmi_bt_inquiry_dev);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry_aud_dev
 * DESCRIPTION
 *  This function is to inquiry audio device
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef _MMI_BT_ULTRA_SLIM_
void mmi_bt_inquiry_aud_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cod;
    U16 title_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to avoid the twice inquiry operation while bt is just on and wanna do the inquiry */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_INQ_AUD_DEV);

    //if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_INQ_AUDIO_DEV)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_INQ_AUDIO_DEV);
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_INQ_AUDIO_DEV);
        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.main_gid);
        return;
    }

    if (g_mmi_bt_scr_cntx.main_gid != GRP_ID_INVALID)
    {
        if (mmi_frm_scrn_is_present(
                g_mmi_bt_scr_cntx.main_gid,
                SCR_BT_SCH_DISCONNECT_SCO,
                MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.main_gid, SCR_BT_SCH_DISCONNECT_SCO);
        }

        title_str_id = STR_BT_SCH_AUD_DEV;
        cod = MMI_BT_AUDIO_MAJOR_SERVICE_MASK;

        MMI_BT_SET_FLAG(MMI_BT_INQ_TYPE_AUDIO);

        mmi_bt_inquiry(g_mmi_bt_scr_cntx.main_gid, cod, title_str_id, mmi_bt_inquiry_aud_dev);
    }
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry
 * DESCRIPTION
 *  This function is to do inquiry process
 * PARAMETERS
 *  max_response        [IN]        max response number of device
 *  timeout             [IN]        timeout timer
 *  cod                 [IN]        class of device
 *  name_discovery      [IN]        to do name discovery or not
 *  title_str_id        [IN]        title string id
 *  inquiry_type        [IN]        inquiry type
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_inquiry(mmi_id group_id, U32 cod, U16 title_str_id, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_INQUIRY, group_id);
/*#ifdef __BT_SPEAKER_SUPPORT__
#ifdef __MMI_BT_SPEAKER_SUPPORT__
#if defined(__MMI_A2DP_SUPPORT__)
	if(
		srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_MAPC_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) 
	)
	{
	mmi_bt_popup_display(
								STR_BT_DISCONN_AUD_DEV_CONN_CNF,
								MMI_EVENT_FAILURE,
								NULL);
	return;
	}
#endif //__MMI_A2DP_SUPPORT__
#endif //__MMI_BT_SPEAKER_SUPPORT__
#endif //__BT_SPEAKER_SUPPORT__*/
#ifdef __MMI_BT_DIALER_SUPPORT__
    if (srv_bt_cm_get_linked_dev_list_idx() >= BT_DEVICE_LINK_NUM)
    {
		mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, 
			MMI_EVENT_FAILURE, 
			(WCHAR*)GetString(STR_BT_RELEASE_CONN_PROMPT));
		return;

	}
	if (MMI_TRUE == srv_bt_cm_get_auto_reconn_flag(NULL))
    {
		mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, 
			MMI_EVENT_FAILURE, 
			(WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
		return;

	}
	
#endif

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    {
        srv_btsco_inquiry_result_enum result = srv_btsco_inquiry_start_callback(callback);

        switch (result)
        {
            case SRV_BT_SCO_INQ_SCO_CONNECTED_DISCONNECTABLE:
                mmi_bt_show_progress_scr(
                    group_id,
                    SCR_BT_SCH_DISCONNECT_SCO,
                    title_str_id,
                    STR_GLOBAL_PLEASE_WAIT,
                    NULL);
                mmi_frm_scrn_set_leave_proc(
                    group_id,
                    SCR_BT_SCH_DISCONNECT_SCO,
                    (mmi_proc_func)mmi_bt_remove_disconnect_sco_screen_leave_proc);
                return;

            case SRV_BT_SCO_INQ_SCO_CONNECTED_IN_CALL:
                mmi_bt_popup_operation_not_allowed();
                return;

            default:
                break;
        }
    }
#endif

#ifdef __MMI_A2DP_SUPPORT__
    av_bt_inquiry_start_callback();
#endif //__MMI_A2DP_SUPPORT__
    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_search(
            SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST,
            MMI_BT_INQUIRY_TIMEOUT_DURATION,
            cod,
            MMI_TRUE))
    {
        MMI_BT_SET_FLAG(MMI_BT_INQUIRY);

        g_mmi_bt_scr_cntx.inq_gid = mmi_frm_group_create_ex(
            group_id,
            GRP_ID_BT_CM_INQUIRY_DEVICE,
            mmi_bt_inquiry_group_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_bt_show_progress_scr(
            g_mmi_bt_scr_cntx.inq_gid,
            SCR_BT_SCH_PRO,
            title_str_id,
            STR_GLOBAL_SEARCHING,
            mmi_bt_inq_result_cancel);
        mmi_frm_scrn_set_leave_proc(
            g_mmi_bt_scr_cntx.inq_gid,
            SCR_BT_SCH_PRO,
            mmi_bt_inq_progress_leave_proc);
    }
    else
    {
#ifdef __MMI_A2DP_SUPPORT__
        av_bt_inquiry_stop_callback();
#endif

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
        srv_btsco_inquiry_stop_callback();
#endif

        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
        MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);
        MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inquiry_group_proc
 * DESCRIPTION
 *  This function is BT CM inquiry screen group proc function
 *  It will handle all event on the screen group
 * PARAMETERS
 *  param       [IN]        MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_inquiry_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:
            g_mmi_bt_scr_cntx.inq_gid = 0;
            MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_progress_leave_proc
 * DESCRIPTION
 *  This function is the leave proc of inquiry progress delete callback
 * PARAMETERS
 *  evt         [IN]    MMI event stucture
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_inq_progress_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        // case EVT_ID_SCRN_GOBACK:
        // case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        // case EVT_ID_SCRN_DELETE_REQ:
        // case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        //     mmi_bt_inq_progress_del_cb();
        //     break;

        case EVT_ID_SCRN_DEINIT:
            srv_bt_cm_search_abort();
            MMI_BT_RESET_FLAG(MMI_BT_INQUIRY);
            MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
            MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_progress_del_cb
 * DESCRIPTION
 *  This function is inquiry progress delete callback
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
// U8 mmi_bt_inq_progress_del_cb(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SCR_INQ_PROGRESS_DEL_CB);
//     srv_bt_cm_search_abort();
//     MMI_BT_RESET_FLAG(MMI_BT_INQUIRY);
//     MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
//     MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);
//     //MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_SPEC_COD_DEV);
//     return MMI_FALSE;
// }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_inq_result
 * DESCRIPTION
 *  This function is to entry the inquiry result screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_result_notify(void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 discov_dev_counter = 0;
    MMI_ID currScreen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_INQ_RESULT);

    discov_dev_counter = srv_bt_cm_get_searched_dev_num();
    /* display first found entry or finish inquiry action */
    if (discov_dev_counter == 1)
    {
        mmi_bt_entry_inq_result();
        mmi_frm_scrn_set_leave_proc(
            g_mmi_bt_scr_cntx.inq_gid,
            SCR_BT_SCH_RES,
            (mmi_proc_func)mmi_bt_inq_result_leave_proc);

        mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_PRO);
    }
    else
    {
        currScreen = mmi_frm_scrn_get_active_id();
        if ((currScreen == SCR_BT_SCH_PRO) ||
            (currScreen == SCR_BT_SCH_RES))
        {
            //wgui_cat184_refresh_list(discov_dev_counter, (S32) g_mmi_bt_scr_cntx.hilight_item);
            wgui_cat1032_refresh_list(
                discov_dev_counter,
                (S32)g_mmi_bt_scr_cntx.hilight_item,
                mmi_bt_get_discovered_list_item,
                mmi_bt_get_discovered_item_hint);
        }
    }
}

#ifdef __MMI_BT_DIALER_SUPPORT__
static void mmi_bt_inq_cancel_bonding(void)
{
g_bt_pair_from_search = MMI_TRUE;
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G_DIALER_PAIR_FROM_SEARCH, g_bt_pair_from_search);
	mmi_bt_inq_result_cancel();

}
static void mmi_bt_dialer_inq_cancel_time_out_hdlr(void)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G_DIALER_SEARCH_CANCEL, g_bt_search_cancel);

    if(g_bt_search_cancel)
    {
	    g_bt_search_cancel = MMI_FALSE;
	}
	else
	{
		mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_CANCEL_PRO);
		if(g_bt_pair_from_search)
		{
		    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G_DIALER_PAIR_FROM_SEARCH, g_bt_pair_from_search);
			mmi_bt_entry_bonding();
			g_bt_pair_from_search = MMI_FALSE;
		}

	}
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_inq_result
 * DESCRIPTION
 *  This function is to entry the inquiry result screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_inq_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rsk_str;
    U8 *guiBuffer;
    U8 discov_dev_counter = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_INQ_RESULT);

    /* Display inquiry result */
    if (mmi_frm_scrn_enter(
            g_mmi_bt_scr_cntx.inq_gid,
            SCR_BT_SCH_RES,
            (FuncPtr) mmi_bt_exit_inq_result,
            (FuncPtr) mmi_bt_entry_inq_result,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    discov_dev_counter = srv_bt_cm_get_searched_dev_num();
#ifndef _MMI_BT_ULTRA_SLIM_
    SetParentHandler(MENU_CONN_BT_SCH_AUDIO_DEV);
#endif 

    RegisterHighlightHandler(mmi_bt_inq_result_hilite_hdlr);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQUIRY)
    {
        rsk_str = STR_GLOBAL_CANCEL;
    }
    else
    {
        rsk_str = STR_GLOBAL_BACK;
    }

    // ShowCategory184Screen(
    //     STR_BT_SCH_RESULT,
    //     IMG_BT_SCH_TITLE,
    //     0,
    //     0,
    //     rsk_str,
    //     IMG_GLOBAL_OK,
    //     discov_dev_counter,
    //     mmi_bt_get_discovered_item,
    //     mmi_bt_get_discovered_item_hint,
    //     (S32) g_mmi_bt_scr_cntx.hilight_item,
    //     guiBuffer);
#ifndef __MMI_BT_DIALER_SUPPORT__
    wgui_cat1032_show(
        (WCHAR*)GetString(STR_BT_SCH_RESULT),
#ifndef _MMI_BT_ULTRA_SLIM_
        (PU8)GetImage(IMG_BT_SCH_TITLE),
#else
				(PU8)NULL,
#endif
        0,
        0,
        (WCHAR*)GetString(rsk_str),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        discov_dev_counter,
        mmi_bt_get_discovered_list_item,
        mmi_bt_get_discovered_item_hint,
        0,
        0,
        IMG_BT_DEV_OTHER,
        0,
        guiBuffer,
        NULL);
#else
    wgui_cat1032_show(
        (WCHAR*)GetString(STR_BT_SCH_RESULT),
#ifndef _MMI_BT_ULTRA_SLIM_
        (PU8)GetImage(IMG_BT_SCH_TITLE),
#else
				(PU8)NULL,
#endif
        (WCHAR*)GetString(STR_BT_PAIR_REQ),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        (WCHAR*)GetString(rsk_str),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        discov_dev_counter,
        mmi_bt_get_discovered_list_item,
        mmi_bt_get_discovered_item_hint,
        0,
        0,
        IMG_BT_DEV_OTHER,
        0,
        guiBuffer,
        NULL);

// add pairing process
SetLeftSoftkeyFunction(mmi_bt_inq_cancel_bonding, KEY_EVENT_UP);
SetCenterSoftkeyFunction(mmi_bt_inq_cancel_bonding, KEY_EVENT_UP);
#endif
    if (!(g_mmi_bt_scr_cntx.flag & MMI_BT_INQUIRY))
    {
#ifndef __MMI_BTBOX_NOLCD__
        ChangeLeftSoftkey(STR_BT_PAIR_REQ, 0);
#endif
        SetLeftSoftkeyFunction(mmi_bt_entry_bonding, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
        SetCenterSoftkeyFunction(mmi_bt_entry_bonding, KEY_EVENT_UP);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
        wgui_stop_title_animation();
#endif 
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_inq_result
 * DESCRIPTION
 *  This function is to exit inquiry result screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_inq_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_EXIT_INQ_RESULT);
	#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    wgui_stop_title_animation();
	#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_hilite_hdlr
 * DESCRIPTION
 *  This function is inquiry result highlight handler
 * PARAMETERS
 *  idx         [IN]
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_result_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_INQ_RESULT_HILITE_HDLR, idx);
    MMI_BT_SET_HILIGHT_ITEM(idx);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQUIRY)
    {
        SetRightSoftkeyFunction(mmi_bt_inq_result_cancel,KEY_EVENT_UP);
    }
    else
    {
        SetRightSoftkeyFunction(mmi_bt_inq_result_goback,KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_leave_proc
 * DESCRIPTION
 *  This function is inquiry result delete callback
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_inq_result_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        // case EVT_ID_SCRN_GOBACK:
        // case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        // case EVT_ID_SCRN_DELETE_REQ:
        // case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        //     mmi_bt_inq_result_del_cb();
        //     break;

        case EVT_ID_SCRN_DEINIT:
            if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQUIRY)
            {
                srv_bt_cm_search_abort();
                MMI_BT_RESET_FLAG(MMI_BT_INQUIRY);
            }

            MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
            MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);
            //MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_SPEC_COD_DEV);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_del_cb
 * DESCRIPTION
 *  This function is inquiry result delete callback
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
// U8 mmi_bt_inq_result_del_cb(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SCR_STATUS, g_mmi_bt_scr_cntx.flag);
//     mmi_frm_scrn_set_leave_proc(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_RES, NULL);
//     mmi_frm_scrn_set_leave_proc(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_PRO, NULL);
//     if (g_mmi_bt_scr_cntx.flag & MMI_BT_INQUIRY)
//     {
//         srv_bt_cm_search_abort();
//         MMI_BT_RESET_FLAG(MMI_BT_INQUIRY);
//     }
//     MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
//     MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);
//     //MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_SPEC_COD_DEV);
//     return MMI_FALSE;
// }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_cancel
 * DESCRIPTION
 *  This function is to handle cancel the inquiry process
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_result_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_INQ_RESULT_CANCEL);
#ifdef __MMI_BT_DIALER_SUPPORT__
	g_bt_search_cancel = MMI_TRUE;
#endif

    MMI_BT_RESET_FLAG(MMI_BT_INQUIRY);

    if (srv_bt_cm_search_abort() == SRV_BT_CM_RESULT_SUCCESS) {

        mmi_bt_show_progress_scr(
            g_mmi_bt_scr_cntx.inq_gid,
            SCR_BT_SCH_CANCEL_PRO,
            0,
            STR_BT_INQUIRY_STOPPING,
            NULL);
    }

    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_PRO);
#ifdef __MMI_BT_DIALER_SUPPORT__

	StartTimer(BT_DIALER_SEARCH_CANCEL_SCREEN_SHOW_TIMER,500,mmi_bt_dialer_inq_cancel_time_out_hdlr);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_result_goback
 * DESCRIPTION
 *  This function is goback handler of inquiry result
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_result_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_INQ_RESULT_GOBACK);

    mmi_frm_scrn_set_leave_proc(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_RES, NULL);

    MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
    MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);
    mmi_frm_scrn_close(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_RES);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_complete
 * DESCRIPTION
 *  This function is to handle inquiry complete
 * PARAMETERS
 *  result      [IN]            the result of inquiry
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_inq_complete(void *para)   /* discov cfm or discov-cancel cfm */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 discov_dev_number;
    srv_bt_cm_inquiry_complete_struct *event = (srv_bt_cm_inquiry_complete_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_INQ_COMPLETE, event->result);

    MMI_BT_RESET_FLAG(MMI_BT_INQUIRY);
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    wgui_stop_title_animation();
#endif 

    discov_dev_number = srv_bt_cm_get_searched_dev_num();
    if (discov_dev_number == 0)
    {
        if (SCR_BT_SCH_PRO == mmi_frm_scrn_get_active_id())
        {
            switch (event->result)
            {
                case BTBM_ADP_SUCCESS:
                case BTBM_ADP_FAILED:
                    /* List Empty */
                    mmi_bt_popup_display(
                        STR_GLOBAL_EMPTY,
                        MMI_EVENT_FAILURE,
                        g_mmi_bt_scr_cntx.inq_gid);
                    break;

                case BTBM_ADP_FAIL_BUSY:
                case BTBM_ADP_FAIL_NOT_ALLOW:
                default:
                    /* Service unavailable */
                    mmi_bt_popup_display(
                        STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                        MMI_EVENT_FAILURE,
                        g_mmi_bt_scr_cntx.inq_gid);
                    break;
            }
        }

        mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_PRO);

        MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);
        MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
    }
    else
    {
         if (SCR_BT_SCH_RES == mmi_frm_scrn_get_active_id())
         {
            if (!(g_mmi_bt_scr_cntx.flag & MMI_BT_INQUIRY))
            {
#ifndef __MMI_BTBOX_NOLCD__
                ChangeLeftSoftkey(STR_BT_PAIR_REQ, 0);
                ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#endif
                SetLeftSoftkeyFunction(mmi_bt_entry_bonding, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
                SetCenterSoftkeyFunction(mmi_bt_entry_bonding, KEY_EVENT_UP);

                
                SetRightSoftkeyFunction(mmi_bt_inq_result_goback, KEY_EVENT_UP);
            }
         }
    }
	#ifdef __MMI_BT_DIALER_SUPPORT__

		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G_DIALER_SEARCH_CANCEL, g_bt_search_cancel);
		if(g_bt_search_cancel)
		{
			g_bt_search_cancel = MMI_FALSE;

		}
		else
		{
			mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_CANCEL_PRO);

			if(g_bt_pair_from_search)
			{
			    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G_DIALER_PAIR_FROM_SEARCH, g_bt_pair_from_search);
				mmi_bt_entry_bonding();
				g_bt_pair_from_search = MMI_FALSE;
			}

		}
	#else
	mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_CANCEL_PRO);
	#endif

    /* notify bt AV that inquiry is stopped */
#if defined(__MMI_A2DP_SUPPORT__)
    av_bt_inquiry_stop_callback();
#endif

    /* to notify bt profile that inquiry is stopped */
#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    srv_btsco_inquiry_stop_callback();
#endif


}


void* mmi_bt_get_device_image(U32 cod)
{

#if defined(_MMI_BWUI_BT_SLIM_)
		return( NULL );
#else
    if (cod & SRV_BT_PHONE_MAJOR_DEVICE_MASK)
    {
        return (void*)GetImage((U16)IMG_BT_DEV_MOB);
    }
#if !defined(_MMI_BT_ULTRA_SLIM_) || defined (__MMI_BT_DIALER_SUPPORT__)
    else if (cod & SRV_BT_COMPUTER_MAJOR_DEVICE_MASK)
    {
        return (void*)GetImage((U16)IMG_BT_DEV_LAP);
    }

    else if (cod & SRV_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)
    {
        return (void*)GetImage((U16)IMG_BT_DEV_PRT);
    }
#endif

    else if (cod & SRV_BT_AUDIO_MAJOR_SERVICE_MASK) //MMI_BT_AV_MAJOR_DEVICE_MASK
    {
        return (void*)GetImage((U16)IMG_BT_DEV_EAR);
    }
    else
    {
        return (void*)GetImage((U16)IMG_BT_DEV_OTHER);
    }
 #endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_discovered_item
 * DESCRIPTION
 *  This function is to get discovered item name and icon to show the dynamic list
 * PARAMETERS
 *  item_index      [IN]        item index
 *  str_buff        [OUT]       string buffer for item string
 *  img_buff_p      [OUT]       image buffer for item icon
 *  str_img_mask    [IN]
 * RETURNS
 *  pBOOL            TRUE : return the item successfully
 *                  FALSE : didn't find the item
 *****************************************************************************/
pBOOL mmi_bt_get_discovered_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *discov_dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_GET_DISCOVERED_ITEM, item_index);
    if (item_index > srv_bt_cm_get_searched_dev_num())
    {
        return MMI_FALSE;
    }

    discov_dev_p = srv_bt_cm_get_searched_dev_info((U8) item_index);
    mmi_chset_utf8_to_ucs2_string(
        (U8 *)str_buff,
        SRV_BT_CM_BD_NAME_UCS2_LEN,
        discov_dev_p->name);

    *img_buff_p = (PU8)mmi_bt_get_device_image(discov_dev_p->cod);

    return MMI_TRUE;
}


static S32 mmi_bt_get_discovered_list_item(S32 start_index, gui_iconlist_menu_item* menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_items; ++i)
    {
        mmi_bt_get_discovered_item((i + start_index), menu_data[i].item_list[0], &menu_data[i].image_list[0], 0);
    }

    return num_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_discovered_item_hint
 * DESCRIPTION
 *  This function is to get the hint list of discovered item
 * PARAMETERS
 *  item_index      [IN]    item index
 *  hint_array      [IN]    hint array
 *
 * RETURNS
 *  S32         TRUE : get the hint of the item successfully
                    FALSE : didn't find the item
 *****************************************************************************/
S32 mmi_bt_get_discovered_item_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *discov_dev_p;
    U8 discov_dev_counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_GET_DISCOVERED_ITEM_HINT, item_index);

    discov_dev_counter = srv_bt_cm_get_searched_dev_num();
    if (item_index > discov_dev_counter)
    {
        return MMI_FALSE;
    }

    discov_dev_p = srv_bt_cm_get_searched_dev_info((U16) item_index);
    mmi_bt_get_display_bt_address((U16*) hint_array[0], &(discov_dev_p->bd_addr));

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_bonding
 * DESCRIPTION
 *  This function is Entry function of bonding
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_bonding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 paired_dev_num;
    srv_bt_cm_dev_struct *discov_dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_BONDING);
#ifdef __MMI_BT_DIALER_SUPPORT__
	if (srv_bt_cm_get_linked_dev_list_idx() >= BT_DEVICE_LINK_NUM)
	{
		mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, 
			MMI_EVENT_FAILURE, 
			(WCHAR*)GetString(STR_BT_RELEASE_CONN_PROMPT));
		return;

	}
	
	if (MMI_TRUE == srv_bt_cm_get_auto_reconn_flag(NULL))
    {
		mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, 
			MMI_EVENT_FAILURE, 
			(WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
		return;

	}
#endif

    mmi_frm_scrn_set_leave_proc(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_RES, NULL);

    discov_dev_p = srv_bt_cm_get_searched_dev_info((U8)(g_mmi_bt_scr_cntx.hilight_item));
    #ifdef __MMI_BT_DIALER_SUPPORT__
    g_bt_paired_from_dialer = MMI_TRUE;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_PAIRED_FLAG, g_bt_paired_from_dialer);
    #endif

    /* check if device is blocked */
#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_get_authorize(&(discov_dev_p->bd_addr)) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
    {
        mmi_bt_popup_prohibited_by_blocked_device();
        return;
    }
#endif /* __MMI_BT_AUTHORIZE__ */

    if (srv_bt_cm_is_dev_conn_active(&(discov_dev_p->bd_addr)))
    {
        mmi_bt_popup_display(STR_BT_DEVICE_BEING_CONNECTED, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.inq_gid);
        return;
    }

    paired_dev_num = srv_bt_cm_get_paired_dev_num();

    if (paired_dev_num >= SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
        !srv_bt_cm_get_dev_info_by_addr((const srv_bt_cm_bt_addr *)&(discov_dev_p->bd_addr), SRV_BT_CM_PAIRED_DEV))
    {
        mmi_bt_popup_display(STR_BT_PAIRED_DEV_FULL, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.inq_gid);

        MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
        MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_ALL_DEV);

        mmi_frm_scrn_close(g_mmi_bt_scr_cntx.inq_gid,SCR_BT_SCH_RES);
        return;
    }

#if defined(__MMI_A2DP_SUPPORT__)
    av_bt_inquiry_start_callback();
#endif

    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_bond((U32)(g_mmi_bt_scr_cntx.hilight_item)))
    {
        mmi_bt_show_progress_scr(
            g_mmi_bt_scr_cntx.inq_gid,
            SCR_BT_PAIR_PRO,
            STR_BT_START_PAIRING,
            STR_BT_START_PAIRING,
            NULL);
    }
    else
    {
        mmi_bt_popup_display(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            g_mmi_bt_scr_cntx.inq_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_input_notify
 * DESCRIPTION
 *  This function is to entry passkey input screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_passkey_input_notify(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_pin_buf[32] = {0};
    srv_bt_cm_pair_ind_struct *event = (srv_bt_cm_pair_ind_struct *)para;
	#ifdef __BT_JUST_WORK_SUPPORT__
	  kal_uint8 pin_size=0;
	  kal_uint8 *pin_code = NULL;
  	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_PASSKEY_INPUT);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        srv_bt_cm_send_passkey(
            &(g_mmi_bt_scr_cntx.far_end_dev_add),
            g_mmi_bt_scr_cntx.far_end_dev_pin,
            MMI_TRUE);
        return;
    }

    if (srv_bt_cm_get_paired_dev_num() >= SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
        !srv_bt_cm_get_dev_info_by_addr((const srv_bt_cm_bt_addr *)&(event->dev_addr), SRV_BT_CM_PAIRED_DEV))
    {
        srv_bt_cm_send_passkey(&(event->dev_addr), asc_pin_buf, MMI_FALSE);
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_BT_REACH_MAX_PAIR_NUM));
        return;
    }

    /* reject the pairing while being at del/del all/activate simap/authoriz confirmation screens */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL ||
        // #ifdef __MMI_SIMAP_SUPPORT__
        //         g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET ||
        // #endif  // __MMI_SIMAP_SUPPORT__
#ifdef __MMI_BT_AUTHORIZE__
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_AUTHORIZE_REJECT ||
#endif /* __MMI_BT_AUTHORIZE__ */
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
    {
        /* from bonding process or remote device send passkey ind */
        srv_bt_cm_send_passkey(&(event->dev_addr), asc_pin_buf, MMI_FALSE);
        return;
    }

    g_mmi_bt_scr_cntx.selct_dev_addr = event->dev_addr;
    g_mmi_bt_scr_cntx.enable_16digits_pin_code = event->enable_16digits_pin_code;
    //memcpy(g_mmi_bt_scr_cntx.dev_name, event->dev_name, SRV_BT_CM_BD_FNAME_LEN);

    if (mmi_frm_scrn_is_present(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_CM_PASSKEY_INPUT,SCR_BT_PIN_INPUT);
    }

#ifdef __BT_JUST_WORK_SUPPORT__
if(Custom_BTPairing_AutoAccept_Support()==KAL_TRUE)
{
	U8 pin_code_str[10];
	pin_code = Custom_BTPairing_AutoAccept_Pincode(&pin_size);
	memcpy(pin_code_str, pin_code, pin_size+1);
	pin_code_str[pin_size] = 0;
	srv_bt_cm_send_passkey(&event->dev_addr,pin_code_str, MMI_TRUE);

        return;
}
#endif
    #ifdef __BT_PAIRING_FIXED_PIN_CODE_ONLY__
    if(BTParing_Fixed_PinCode_Only_Support()==KAL_TRUE)
    {
	      kal_uint8 pin_size=0;
	      U8 pin_code_str[10];

	      U8* pin_code = (U8*)Custom_BTPairing_AutoAccept_Pincode(&pin_size);
	      memcpy(pin_code_str, pin_code, pin_size+1);
	      pin_code_str[pin_size] = 0;
        srv_bt_cm_send_passkey(&event->dev_addr,pin_code_str, MMI_TRUE);
    }
    else
  	#endif
    {
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_BT_ACCESS_REQ,
        MMI_EVENT_DEFAULT,
        mmi_bt_passkey_input_scr_hdlr,
        NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_input_scr_hdlr
 * DESCRIPTION
 *  This function is to handle passkey input screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_passkey_input_scr_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_entry_passkey_input_scr_hdlr();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 * mmi_bt_entry_passkey_input_scr_hdlr(void)
 * DESCRIPTION
 *  This function is to show passkey input screen
 *  It will create the screen group first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_passkey_input_scr_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BT_CM_PASSKEY_INPUT,
        mmi_bt_entry_passkey_input_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_bt_entry_passkey_input_screen();
}


/*****************************************************************************
 * FUNCTION
 * mmi_bt_entry_passkey_input_screen(void)
 * DESCRIPTION
 *  This function is to show passkey input screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_passkey_input_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SHOW_PASSKEY_INPUT_SCREEN);

    if (mmi_frm_scrn_enter(
            GRP_ID_BT_CM_PASSKEY_INPUT,
            SCR_BT_PIN_INPUT,
            (FuncPtr) mmi_bt_exit_passkey_input_screen,
            (FuncPtr) mmi_bt_entry_passkey_input_screen,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8 *)mmi_frm_scrn_get_active_input_buf();

    if (inputBuffer == NULL)
    {
     
        g_mmi_bt_scr_cntx.pin_scr_buf[0] = 0;

        srv_bt_cm_get_dev_ucs2_name(
            &(g_mmi_bt_scr_cntx.selct_dev_addr),
            SRV_BT_CM_BD_UCS2_NAME_LEN,
            g_mmi_bt_scr_cntx.scr_buf);

        /* STR_BT_ENTER_PASSCODE string */
        mmi_wcscpy(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *) GetString(STR_BT_ENTER_PASSCODE));
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)L"(");
        /* Device name */
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)g_mmi_bt_scr_cntx.scr_buf);
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)L")");
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)L":");
    }
    else
    {
        mmi_wcscpy(g_mmi_bt_scr_cntx.pin_scr_buf, (WCHAR *) inputBuffer);
        /* donot need to update ui_buffer */
    }

    RegisterInputBoxValidationFunction(mmi_bt_passkey_validation_func);

    if (guiBuffer == NULL)
    {
        mmi_imm_set_app_desired_input_mode(IMM_INPUT_MODE_123_SYMBOLS);
    }

    /* SAP-16 */
    if (g_mmi_bt_scr_cntx.enable_16digits_pin_code)
    {
        ShowCategory111Screen_ext(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8 *) g_mmi_bt_scr_cntx.ui_buf,  /* STR_BT_ENTER_PASSCODE */
            IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
            (U8*) (g_mmi_bt_scr_cntx.pin_scr_buf),
            MMI_BT_MAX_PASSKEY_LENGHT,
            (U8*)GetString(STR_BT_16_DIGITS_PASSKEY),
            0,
            guiBuffer);
    }
    else
    {
        ShowCategory111Screen_ext(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8 *) g_mmi_bt_scr_cntx.ui_buf,   /* STR_BT_ENTER_PASSCODE */
            IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
            (U8*) (g_mmi_bt_scr_cntx.pin_scr_buf),
            MMI_BT_MAX_PASSKEY_LENGHT,
            NULL,
            0,
            guiBuffer);
    }

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_BT_CM_PASSKEY_INPUT,
        SCR_BT_PIN_INPUT,
        (mmi_proc_func)mmi_bt_passkey_input_scr_leave_proc);

    SetCategory111RightSoftkeyFunction(mmi_bt_reject_passkey, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 * mmi_bt_entry_passkey_input_group_proc(void)
 * DESCRIPTION
 *  This function is passkey input group proc function
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_entry_passkey_input_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            break;

        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:
            mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
            break;

        case EVT_ID_POPUP_QUIT:
            break;

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_passkey_input_screen
 * DESCRIPTION
 *  This function is to exit passkey input screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_passkey_input_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to hold the history data */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_EXIT_PASSKEY_INPUT);

    mmi_frm_scrn_set_active_input_buf_ptr((WCHAR *)g_mmi_bt_scr_cntx.pin_scr_buf);

    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_validation_func
 * DESCRIPTION
 *  This function is to validate the passkey
 * PARAMETERS
 *  text        [IN]
 *  cursor      [IN]
 *  length      [IN]
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_passkey_validation_func(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int passkey_maxlen=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SAP-16 */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PASSKEY_VALIDATION_FUNC);
    if (g_mmi_bt_scr_cntx.enable_16digits_pin_code)
    {
		g_mmi_bt_scr_cntx.enable_16digits_pin_code = 0;
		passkey_maxlen=16;

        }
        else
        {
		passkey_maxlen=1;
    }

    if ((length) < passkey_maxlen)
        {
#ifndef __MMI_BTBOX_NOLCD__
            ChangeLeftSoftkey(0, 0);
#endif
            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
            ChangeCenterSoftkey(0, 0);
#endif 
            SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
        }
        else
        {
#ifndef __MMI_BTBOX_NOLCD__
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
#endif
            SetLeftSoftkeyFunction(mmi_bt_send_passkey, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
            SetCenterSoftkeyFunction(mmi_bt_send_passkey, KEY_EVENT_UP);
        }
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_input_scr_leave_proc
 * DESCRIPTION
 *  This function is proc function screen delete callback of passkey input screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_passkey_input_scr_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        // case EVT_ID_SCRN_GOBACK:
        // case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        // case EVT_ID_SCRN_DELETE_REQ:
        // case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        //     mmi_bt_passkey_input_scr_del_cb();
        //     break;

        case EVT_ID_SCRN_DEINIT:
        {
            U8 asc_pin_buf[6];
            asc_pin_buf[0] = 0;
            srv_bt_cm_send_passkey(&(g_mmi_bt_scr_cntx.selct_dev_addr), asc_pin_buf, MMI_FALSE);            
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_input_scr_del_cb
 * DESCRIPTION
 *  This function is screen delete callback of passkey input screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  U8
 *****************************************************************************/
// static void mmi_bt_passkey_input_scr_del_cb(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     U8 asc_pin_buf[32];
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_PASSKEY_INPUT_SCR_DEL_CB);
//     asc_pin_buf[0] = 0;
//     srv_bt_cm_send_passkey(&(g_mmi_bt_scr_cntx.selct_dev_addr), asc_pin_buf, MMI_FALSE);
// }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_reject_passkey
 * DESCRIPTION
 *  This function is to goback the passkey input screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_reject_passkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_pin_buf[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PASSKEY_INPUT_GOBACK);

    asc_pin_buf[0] = 0;
    srv_bt_cm_send_passkey(&(g_mmi_bt_scr_cntx.selct_dev_addr), asc_pin_buf, MMI_FALSE);

    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT, NULL);
    mmi_frm_scrn_close(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT);
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_send_passkey
 * DESCRIPTION
 *  This function is to send passkey request
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_send_passkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_pin_buf[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.pin_scr_buf[MMI_BT_PIN_SCR_BUF_SIZE - 1] = '\0';
    mmi_ucs2_to_asc((CHAR*)asc_pin_buf, (CHAR*)g_mmi_bt_scr_cntx.pin_scr_buf);

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_SEND_PASSKEY,
        asc_pin_buf[0],
        asc_pin_buf[1],
        asc_pin_buf[2],
        asc_pin_buf[3],
        asc_pin_buf[4],
        asc_pin_buf[5],
        asc_pin_buf[6],
        asc_pin_buf[7]);

    srv_bt_cm_send_passkey(&(g_mmi_bt_scr_cntx.selct_dev_addr), asc_pin_buf, MMI_TRUE);

    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT, NULL);
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT);
    mmi_frm_scrn_close(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_reject_passkey_ind
 * DESCRIPTION
 *  This function is reject passkey indication
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : there is PIN INPUT screen
 *                  FALSE : otherwise
 *****************************************************************************/
MMI_BOOL mmi_bt_reject_passkey_ind(U32 lap, U8 uap, U16 nap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_bt_scr_cntx.selct_dev_addr.lap == lap) &&
        (g_mmi_bt_scr_cntx.selct_dev_addr.uap == uap) &&
        (g_mmi_bt_scr_cntx.selct_dev_addr.nap == nap))
    {
        mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT);
        mmi_frm_scrn_close(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT);
        result = MMI_TRUE;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_REJECT_PASSKEY_IND, lap, uap, nap, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_pair_result
 * DESCRIPTION
 *  This function is to handle the entry pair result
 * PARAMETERS
 *  res         [IN]           the pair result
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_pair_result(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_pair_res_struct *event = (srv_bt_cm_pair_res_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_PAIR_RESULT, event->result);

    mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ, mmi_bt_passkey_input_scr_hdlr, NULL);
#ifdef __MMI_BT_SIMPLE_PAIR__
    mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ, mmi_bt_security_user_confirm_hdlr, NULL);
    mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ, mmi_bt_security_passkey_hdlr, NULL);
#endif

    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
    
#ifdef __MMI_BT_AUTHORIZE__
    g_mmi_bt_scr_cntx.first_pair = (event->result == SRV_BT_CM_RESULT_SUCCESS) ?
        event->is_first_pair :
        MMI_FALSE;
#endif  // __MMI_BT_AUTHORIZE__

    if (mmi_frm_scrn_get_active_id() == SCR_BT_MYDEV)
    {
        mmi_bt_refresh_screen();
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT, NULL);
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT);
    mmi_frm_scrn_close(GRP_ID_BT_CM_PASSKEY_INPUT, SCR_BT_PIN_INPUT);

#ifdef __MMI_BT_SIMPLE_PAIR__
    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_CM_SECURITY_CNF, SCR_BT_NUMERIC_CONFIRM, NULL);
    mmi_frm_scrn_close(GRP_ID_BT_CM_SECURITY_CNF, SCR_BT_NUMERIC_CONFIRM);

    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_CM_PASSKEY_NOTIFY, SCR_BT_PASSKEY_NOTIFY, NULL);
    mmi_frm_scrn_close(GRP_ID_BT_CM_PASSKEY_NOTIFY, SCR_BT_PASSKEY_NOTIFY);
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
		if((event->result != SRV_BT_CM_RESULT_SUCCESS) && srv_bt_cm_is_dev_busy(&event->dev_addr))
		{
			mmi_bt_dialer_set_time_out_flag(MMI_TRUE);

		}
#endif/*__MMI_BT_DIALER_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_bond_result
 * DESCRIPTION
 *  This function is to handle the entry bonding result
 * PARAMETERS
 *  res         [IN]            the bond result
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_bond_result(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev_p;
    srv_bt_cm_bond_res_struct *event = (srv_bt_cm_bond_res_struct *)para;
    U32 i;
    U32 conning_profile_id = 0xffff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_BOND_RESULT, event->result);

    /* notify bt AV that bonding is stopped */
#if defined(__MMI_A2DP_SUPPORT__)
    av_bt_inquiry_stop_callback();
#endif

    if (event->result == SRV_BT_CM_RESULT_SUCCESS)
    {
        U32 flag = g_mmi_bt_scr_cntx.flag;
        mmi_frm_scrn_set_leave_proc(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_RES, NULL);
        mmi_frm_scrn_close(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_SCH_RES);
        mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.inq_gid, SCR_BT_PAIR_PRO);
        dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&(event->dev_addr));
#ifdef __MMI_BT_DIALER_SUPPORT__
        if((g_bt_paired_from_dialer) && (MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK != g_mmi_bt_scr_cntx.dev_cod_mask))// after paried and auto connecting
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_PAIRED_FLAG, g_bt_paired_from_dialer);
            if (srv_bt_cm_get_linked_dev_list_idx() < BT_DEVICE_LINK_NUM)
            {
				#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
				mmi_bt_dialer_auto_reconn_reset();
                #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
		        if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
				{
					if(!srv_bt_cm_is_headset_connected_ex() && !mmi_bt_dialer_app_is_connected_ex(&g_mmi_bt_scr_cntx.conn_dev_add))
					{
						memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(event->dev_addr), sizeof(srv_bt_cm_bt_addr));
						StartTimer(BT_AUTO_CONN_HEADSET_AFTER_PAIRED_TIMER,1000,mmi_bt_entry_connecting_time_out_hdlr);
					}
			        g_bt_paired_from_dialer = MMI_FALSE;
				}
				else
				{
				    if(!srv_bt_cm_is_headset_connected_ex())
					{
						memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(event->dev_addr), sizeof(srv_bt_cm_bt_addr));
				        mmi_bt_dialor_connect(&(event->dev_addr));
				        g_bt_paired_from_dialer = MMI_FALSE;
				        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_PAIRED_FLAG, g_bt_paired_from_dialer);
				    }
				}
            }
        }
#endif
#ifdef __MMI_BT_AUTHORIZE__
        if (g_mmi_bt_scr_cntx.first_pair)
        {
            /* if
               1. it's authorized device,
               2. it's handsfree device
               we won't prompt the confirm screen */
            g_mmi_bt_scr_cntx.selct_dev_addr = event->dev_addr;

            if (//!(srv_bt_cm_get_authorize(&event->dev_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT) &&
                !(flag & MMI_BT_INQ_TYPE_AUDIO) &&
                !(mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_RENDERING_MAJOR_SERVICE_MASK | MMI_BT_AV_MAJOR_DEVICE_MASK))))
            {
                mmi_frm_nmgr_notify_by_app(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_DEFAULT,
                        mmi_bt_authorize_confirm_hdlr,
                        NULL);
                return;
            }
        }
#endif /*__MMI_BT_AUTHORIZE__*/

        /* search audio device, if bond success, will display connect confirm screen */
        if (flag & MMI_BT_INQ_TYPE_AUDIO)
        {
            memcpy(&(g_mmi_bt_scr_cntx.conn_dev_add), &(event->dev_addr), sizeof(srv_bt_cm_bt_addr));

            for (i = 0; i < dev_p->service_list_num; ++i)
            {
                if ((dev_p->service_list[i] == SRV_BT_CM_HF_PROFILE_UUID) ||
                    (dev_p->service_list[i] == SRV_BT_CM_HS_PROFILE_UUID) ||
                    (dev_p->service_list[i] == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID))
                {
                    conning_profile_id = dev_p->service_list[i];
                    break;
                }
            }

            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_CONN_PROFILE_ID, conning_profile_id);

            if (conning_profile_id == SRV_BT_CM_HS_PROFILE_UUID ||
                conning_profile_id == SRV_BT_CM_HF_PROFILE_UUID ||
                conning_profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
            {
                mmi_bt_display_connect_confirm(g_mmi_bt_scr_cntx.main_gid, MMI_TRUE);
            }
            // else
            // {
            // #ifdef __MMI_BT_AUTHORIZE__
            //     mmi_bt_display_connect_confirm(g_mmi_bt_scr_cntx.main_gid, MMI_FALSE);
            // #else
            //     mmi_frm_nmgr_popup(
            //         MMI_SCENARIO_ID_DEFAULT,
            //         MMI_EVENT_FAILURE,
            //         (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
            // #endif
            // }
        }
    }
    else
    {
        if (event->result == SRV_BT_CM_BTBM_NOT_ALLOW)
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_BT_DEVICE_BEING_CONNECTED));
        }
        //else if (event->result == SRV_BT_CM_BTBM_DEVICE_FULL)
        //{
        //    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_BT_PAIRED_DEV_FULL));
        //}
        else if (event->result != SRV_BT_CM_BTBM_SUCCESS)
        {
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)GetString(STR_BT_PAIR_FAILED));
        }

        mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.inq_gid,SCR_BT_PAIR_PRO);
    }
}
static mmi_ret mmi_bt_dummy_group_proc(mmi_event_struct *param)
{
    return MMI_RET_OK;
}

#ifdef __MMI_BT_SIMPLE_PAIR__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_security_user_confirm_notify
 * DESCRIPTION
 *  This function is to handle numeric comparison
 * PARAMETERS
 *  device_name        [IN]  device name
 *  uap                [IN]  device address
 *  lap                [IN]  device address
 *  nap                [IN]  device address
 *  display_numeric       [IN]
 *  passcode        [IN]  passcode for end user to do numeric comparison
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_security_user_confirm_notify(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_security_user_confirm_struct *event = (srv_bt_cm_security_user_confirm_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_BT_SECURITY_USER_CONFIRM,
        event->dev_addr.lap,
        event->dev_addr.uap,
        event->dev_addr.nap);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        srv_bt_cm_security_numeric_confirm(&(g_mmi_bt_scr_cntx.far_end_dev_add), MMI_TRUE);
        return;
    }

    if (srv_bt_cm_get_paired_dev_num() == SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
        !srv_bt_cm_get_dev_info_by_addr(&(event->dev_addr), SRV_BT_CM_PAIRED_DEV))
    {
        srv_bt_cm_security_numeric_confirm(&(event->dev_addr), MMI_FALSE);
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_BT_REACH_MAX_PAIR_NUM));
        return;
    }

    /* reject the pairing while being at del/del all/activate simap/authoriz confirmation screens */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL ||
        // #ifdef __MMI_SIMAP_SUPPORT__
        //         g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET ||
        // #endif  // __MMI_SIMAP_SUPPORT__
#ifdef __MMI_BT_AUTHORIZE__
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_AUTHORIZE_REJECT ||
#endif /* __MMI_BT_AUTHORIZE__ */
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
    {
        srv_bt_cm_security_numeric_confirm(&(event->dev_addr), MMI_FALSE);
        return;
    }

    memcpy(g_mmi_bt_scr_cntx.security_passkey, event->passcode, MMI_BT_MAX_SECURITY_PASSKEY_LENGTH);
    g_mmi_bt_scr_cntx.security_passkey[MMI_BT_MAX_SECURITY_PASSKEY_LENGTH] = 0;
    g_mmi_bt_scr_cntx.display_numeric = event->display_numeric;
    g_mmi_bt_scr_cntx.selct_dev_addr = event->dev_addr;

    if (mmi_frm_scrn_is_present(GRP_ID_BT_CM_SECURITY_CNF, SCR_BT_NUMERIC_CONFIRM, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_CM_SECURITY_CNF, SCR_BT_NUMERIC_CONFIRM);
    }

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_BT_ACCESS_REQ,
        MMI_EVENT_DEFAULT,
        mmi_bt_security_user_confirm_hdlr,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_security_user_confirm_hdlr
 * DESCRIPTION
 *  This function is to handle numeric comparison
 * PARAMETERS
 *  scen_id        [IN]  scenario_id
 *  arg                [IN]user data
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_bt_security_user_confirm_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __BT_JUST_WORK_SUPPORT__
	if(Custom_BTPairing_AutoAccept_Support()==KAL_TRUE)
		{
		mmi_bt_security_user_confirm_yes();
		}
	else
	#endif
		{
    mmi_bt_pre_entry_security_user_confirm_screen();
		}
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_security_user_confirm_scr_hdlr
 * DESCRIPTION
 *  This function is to handle entry security user confirm
 *  It will create the screen group first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_pre_entry_security_user_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BT_CM_SECURITY_CNF,
        mmi_bt_entry_security_user_confirm_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_bt_entry_security_user_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_security_user_confirm_screen
 * DESCRIPTION
 *  This function is to handle entry security user confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_entry_security_user_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ENTRY_SECURITY_USER_CONFIRM_SCREEN);

    if (mmi_frm_scrn_enter(
            GRP_ID_BT_CM_SECURITY_CNF,
            SCR_BT_NUMERIC_CONFIRM,
            (FuncPtr) mmi_bt_exit_security_user_confirm_screen,
            (FuncPtr) mmi_bt_entry_security_user_confirm_screen,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();


    /* donot need to show the passcode to end user if display_numeric == 0 */
    if (g_mmi_bt_scr_cntx.display_numeric)
    {
        mmi_wcscpy(g_mmi_bt_scr_cntx.scr_buf, (WCHAR *) GetString(STR_BT_NUMERIC_COMPARISON));

        srv_bt_cm_get_dev_ucs2_name(
            &(g_mmi_bt_scr_cntx.selct_dev_addr),
            SRV_BT_CM_BD_UCS2_NAME_LEN,
            g_mmi_bt_scr_cntx.ui_buf);

        /* passcode string */
        mmi_asc_to_ucs2((CHAR*)g_mmi_bt_scr_cntx.pin_scr_buf, (CHAR*)g_mmi_bt_scr_cntx.security_passkey);
#ifndef WGUI_REMOVE_CAT113_TO_SLIM
        ShowCategory113Screen(
            (UI_string_type)GetString(STR_BT_PAIR_REQ),
            (PU8)GetImage(GetRootTitleIcon(MENU_CONN_BT_MAIN)),
            (UI_string_type)GetString(STR_GLOBAL_YES),
            (PU8)GetImage(IMG_GLOBAL_YES),
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO),
            (UI_string_type)g_mmi_bt_scr_cntx.scr_buf, /* string 1, Passcode matched? */
            (UI_string_type)g_mmi_bt_scr_cntx.pin_scr_buf, /* string 3, passcode */
            (UI_string_type)g_mmi_bt_scr_cntx.ui_buf, /* string 2, device name */
            0,
            0,
            guiBuffer);

        /* Passcode matched? */
        /*     123456        */
        /*       xxx         */
#else
		{
			static U8 buf[MMI_BT_SCR_BUF_SIZE+MMI_BT_PIN_SCR_BUF_SIZE+MMI_BT_UI_BUF_SIZE];
			int len;
			app_ucs2_strcpy(buf,(const kal_int8 *)g_mmi_bt_scr_cntx.scr_buf);
			app_ucs2_strcat(buf,"\n");
			app_ucs2_strcat(buf,(const kal_int8 *)g_mmi_bt_scr_cntx.pin_scr_buf);
			app_ucs2_strcat(buf,"\n");
			app_ucs2_strcat(buf,(const kal_int8 *)g_mmi_bt_scr_cntx.ui_buf);
			len=app_ucs2_strlen((const kal_int8 *)buf);
		ShowCategory74Screen(
            STR_BT_PAIR_REQ,
            MENU_CONN_BT_MAIN,
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            buf,
			len,
            guiBuffer);

		}
#endif 
    }
    else
    {
        srv_bt_cm_get_dev_ucs2_name(
            &(g_mmi_bt_scr_cntx.selct_dev_addr),
            SRV_BT_CM_BD_UCS2_NAME_LEN,
            g_mmi_bt_scr_cntx.scr_buf);

        /* STR_BT_ACCEPT_PAIRING string */
        mmi_wcscpy(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *) GetString(STR_BT_ACCEPT_PAIRING));
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)L" ");

        /* Device name */
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, g_mmi_bt_scr_cntx.scr_buf);

        /* STR_BT_QUESTION_MARK string */
        mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)GetString(STR_BT_QUESTION_MARK));

        ShowCategory7Screen(
            STR_BT_PAIR_REQ,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8*) g_mmi_bt_scr_cntx.ui_buf,
            guiBuffer);

        /*  Accept pairing from xxx?  */
    }

    SetLeftSoftkeyFunction(mmi_bt_security_user_confirm_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_security_user_confirm_no, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mmi_bt_security_user_confirm_yes, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_BT_CM_SECURITY_CNF,
        SCR_BT_NUMERIC_CONFIRM,
        (mmi_proc_func)mmi_bt_security_user_confirm_scr_leave_proc);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_security_user_confirm_group_proc
 * DESCRIPTION
 *  This function is to group proc handle entry security user confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bt_entry_security_user_confirm_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return mmi_bt_dummy_group_proc(param);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_security_user_confirm_screen
 * DESCRIPTION
 *  This function is exit the  numeric comparison screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_exit_security_user_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_security_user_confirm_scr_leave_proc
 * DESCRIPTION
 *  This function is to complete the numeric comparison process before screen deleted
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_bt_security_user_confirm_scr_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            srv_bt_cm_security_numeric_confirm(&(g_mmi_bt_scr_cntx.selct_dev_addr), MMI_FALSE);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_numeric_confirm_scr_del_cb
 * DESCRIPTION
 *  This function is to complete the numeric comparison process before screen deleted
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
// static void mmi_bt_security_user_confirm_scr_del_cb(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_NEMERIC_CONFIRM_SCR_DEL_CB);
//     srv_bt_cm_security_numeric_confirm(&(g_mmi_bt_scr_cntx.selct_dev_addr), MMI_FALSE);
// }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_numeric_confirm_yes
 * DESCRIPTION
 *  This function is to accept the numeric comparison
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_security_user_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_NEMERIC_CONFIRM_YES);

    srv_bt_cm_security_numeric_confirm(&(g_mmi_bt_scr_cntx.selct_dev_addr), MMI_TRUE);

    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_CM_SECURITY_CNF, SCR_BT_NUMERIC_CONFIRM, NULL);
    mmi_frm_scrn_close(GRP_ID_BT_CM_SECURITY_CNF, SCR_BT_NUMERIC_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_numeric_confirm_no
 * DESCRIPTION
 *  This function is to reject the numeric comparison
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_security_user_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_NEMERIC_CONFIRM_NO);
#ifdef __MMI_BT_DIALER_SUPPORT__
    g_bt_paired_from_dialer = MMI_FALSE;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_PAIRED_FLAG, g_bt_paired_from_dialer);
#endif
    srv_bt_cm_security_numeric_confirm(&(g_mmi_bt_scr_cntx.selct_dev_addr),MMI_FALSE);

    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_CM_SECURITY_CNF, SCR_BT_NUMERIC_CONFIRM, NULL);
    mmi_frm_scrn_close(GRP_ID_BT_CM_SECURITY_CNF, SCR_BT_NUMERIC_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_security_passkey_notify
 * DESCRIPTION
 *  This function is to handle passkey notify for passkey entry procedure
 * PARAMETERS
 *  device_name        [IN]  device name
 *  uap                [IN]  device address
 *  lap                [IN]  device address
 *  nap                [IN]  device address
 *  passcode        [IN]  passcode for end user to do numeric comparison
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_security_passkey_notify(void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_security_passkey_struct *event = (srv_bt_cm_security_passkey_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_BT_SECURITY_PASSKEY_NOTIFY,
        event->dev_addr.lap,
        event->dev_addr.uap,
        event->dev_addr.nap);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        return;
    }

    if (srv_bt_cm_get_paired_dev_num() >= SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
        !srv_bt_cm_get_dev_info_by_addr((const srv_bt_cm_bt_addr*)&(event->dev_addr), SRV_BT_CM_PAIRED_DEV))
    {
        srv_bt_cm_security_keypress_notify_cancel(&(event->dev_addr));
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_BT_REACH_MAX_PAIR_NUM));
        return;
    }

    /* reject the pairing while being at del/del all/activate simap/authoriz confirmation screens */
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL ||
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL ||
        // #ifdef __MMI_SIMAP_SUPPORT__
        //         g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET ||
        // #endif  // __MMI_SIMAP_SUPPORT__
#ifdef __MMI_BT_AUTHORIZE__
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_AUTHORIZE_REJECT ||
#endif /* __MMI_BT_AUTHORIZE__ */
        g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
    {
        srv_bt_cm_security_keypress_notify_cancel(&(event->dev_addr));
        return;
    }

    memcpy(g_mmi_bt_scr_cntx.security_passkey, event->passcode, MMI_BT_MAX_SECURITY_PASSKEY_LENGTH);
    g_mmi_bt_scr_cntx.security_passkey[MMI_BT_MAX_SECURITY_PASSKEY_LENGTH] = 0;
    g_mmi_bt_scr_cntx.selct_dev_addr = event->dev_addr;
    //memcpy(g_mmi_bt_scr_cntx.dev_name, event->dev_name, SRV_BT_CM_BD_FNAME_LEN);

    if (mmi_frm_scrn_is_present(GRP_ID_BT_CM_PASSKEY_NOTIFY, SCR_BT_PASSKEY_NOTIFY, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_CM_PASSKEY_NOTIFY, SCR_BT_PASSKEY_NOTIFY);
    }

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_BT_ACCESS_REQ,
        MMI_EVENT_DEFAULT,
        mmi_bt_security_passkey_hdlr,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_security_passkey_hdlr
 * DESCRIPTION
 *  This function is to handle numeric comparison
 * PARAMETERS
 *  scen_id        [IN]  scenario_id
 *  arg                [IN]user data
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_bt_security_passkey_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BT_CM_PASSKEY_NOTIFY,
        mmi_bt_entry_passkey_notify_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_bt_entry_security_passkey_screen();

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_security_passkey_scr_hdlr
 * DESCRIPTION
 *  This function is to handle passkey notify for passkey entry procedure
 *  It will create the group first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
// static void mmi_bt_pre_entry_security_passkey_screen(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     mmi_frm_group_create_ex(
//         GRP_ID_ROOT,
//         GRP_ID_BT_CM_PASSKEY_NOTIFY,
//         mmi_bt_entry_passkey_notify_group_proc,
//         NULL,
//         MMI_FRM_NODE_SMART_CLOSE_FLAG);
//     mmi_bt_entry_security_passkey_screen();
// }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_security_passkey_screen
 * DESCRIPTION
 *  This function is to handle passkey notify for passkey entry procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_entry_security_passkey_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_SECURITY_PASSKEY_NOTIFY);

    if (mmi_frm_scrn_enter(
            GRP_ID_BT_CM_PASSKEY_NOTIFY,
            SCR_BT_PASSKEY_NOTIFY,
            (FuncPtr) mmi_bt_exit_security_passkey_screen,
            (FuncPtr) mmi_bt_entry_security_passkey_screen,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    srv_bt_cm_get_dev_ucs2_name(
        &(g_mmi_bt_scr_cntx.selct_dev_addr),
        SRV_BT_CM_BD_UCS2_NAME_LEN,
        g_mmi_bt_scr_cntx.scr_buf);
    /* passcode string */
    mmi_asc_to_ucs2((CHAR*)g_mmi_bt_scr_cntx.pin_scr_buf, (CHAR*)g_mmi_bt_scr_cntx.security_passkey);

    /* STR_BT_FROM string */
    mmi_wcscpy(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)GetString(STR_BT_FROM));
    mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)L" ");

    /* Device name */
    mmi_wcscat(g_mmi_bt_scr_cntx.ui_buf, (WCHAR *)g_mmi_bt_scr_cntx.scr_buf);
#ifndef WGUI_REMOVE_CAT113_TO_SLIM
    ShowCategory113Screen(
        (UI_string_type)GetString(STR_BT_PAIR_REQ),
        (PU8)GetImage(GetRootTitleIcon(MENU_CONN_BT_MAIN)),
        0,
        0,
        (UI_string_type)GetString(STR_GLOBAL_CANCEL),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        (UI_string_type)GetString(STR_BT_INPUT_PASSCODE),/*L"Input password",*/
        (UI_string_type)g_mmi_bt_scr_cntx.pin_scr_buf,
        (UI_string_type)g_mmi_bt_scr_cntx.ui_buf,
        0,
        0,
        guiBuffer);
#else
	{
			U8 buf[MMI_BT_SCR_BUF_SIZE+MMI_BT_PIN_SCR_BUF_SIZE+MMI_BT_UI_BUF_SIZE];
			int len;
			app_ucs2_strcpy(buf,(const kal_int8 *)GetString(STR_BT_INPUT_PASSCODE));
			app_ucs2_strcat(buf,"\n");
			app_ucs2_strcat(buf,(const kal_int8 *)g_mmi_bt_scr_cntx.pin_scr_buf);
			app_ucs2_strcat(buf,"\n");
			app_ucs2_strcat(buf,(const kal_int8 *)g_mmi_bt_scr_cntx.ui_buf);
			len=app_ucs2_strlen((const kal_int8 *)buf);
		ShowCategory74Screen(
            STR_BT_PAIR_REQ,
            MENU_CONN_BT_MAIN,
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            buf,
			len,
            guiBuffer);
	}

#endif 

    /* Input passcode */
    /*    123456      */
    /*   from XXX     */

    SetRightSoftkeyFunction(mmi_bt_keypress_notify_cancel, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_BT_CM_PASSKEY_NOTIFY,
        SCR_BT_PASSKEY_NOTIFY,
        mmi_bt_passkey_notify_scr_leave_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_passkey_notify_group_proc
 * DESCRIPTION
 *  This function is to handle passkey notify for passkey entry procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bt_entry_passkey_notify_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return mmi_bt_dummy_group_proc(param);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_security_user_confirm_screen
 * DESCRIPTION
 *  This function is exit the  numeric comparison screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_exit_security_passkey_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_notify_scr_leave_proc
 * DESCRIPTION
 *  This function is to cancel the passkey-entry procedure(cancel keypress notify)
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bt_passkey_notify_scr_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            srv_bt_cm_security_keypress_notify_cancel(&(g_mmi_bt_scr_cntx.selct_dev_addr));
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_passkey_notify_scr_del_cb
 * DESCRIPTION
 *  This function is to cancel the passkey-entry procedure(cancel keypress notify)
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
// static void mmi_bt_passkey_notify_scr_del_cb(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PASSKEY_NOTIFY_SCR_DEL_CB);
//     srv_bt_cm_security_keypress_notify_cancel(&(g_mmi_bt_scr_cntx.selct_dev_addr));
// }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_keypress_notify_cancel
 * DESCRIPTION
 *  This function is to cancel the passkey-entry procedure(cancel keypress notify)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_keypress_notify_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_KEYPRESS_NOTIFY_CANCEL);
    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_CM_PASSKEY_NOTIFY, SCR_BT_PASSKEY_NOTIFY, NULL);

    mmi_frm_scrn_close(GRP_ID_BT_CM_PASSKEY_NOTIFY, SCR_BT_PASSKEY_NOTIFY);

    srv_bt_cm_security_keypress_notify_cancel(&(g_mmi_bt_scr_cntx.selct_dev_addr));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_security_passkey_notify
 * DESCRIPTION
 *  This function is to handle passkey notify for passkey entry procedure
 * PARAMETERS
 *  uap                [IN]  device address
 *  lap                [IN]  device address
 *  nap                [IN]  device address
 *  num_digit        [IN]  number of digits that remote device inputted
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_entry_security_keypress_notify(void* para)
{
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
#endif
}
#endif /* __MMI_BT_SIMPLE_PAIR__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pre_entry_mydev_menu
 * DESCRIPTION
 *  This function is to entry My Device menu
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_pre_entry_mydev_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_MENU);

    g_mmi_bt_scr_cntx.mydev_gid = cui_bt_device_select_screen_create(g_mmi_bt_scr_cntx.main_gid);

    if (g_mmi_bt_scr_cntx.mydev_gid == GRP_ID_INVALID)
    {
        return;
    }

#ifdef __MMI_BT_DIALER_SUPPORT__
	if(srv_bt_cm_get_btdialor_app_mode() == MMI_TRUE)
	{
		S32 cod  =MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK|MMI_BT_TELEPHONY_MAJOR_SERVICE_MASK;
		S32 serv =0;
		cui_bt_device_select_screen_set_mask(
				g_mmi_bt_scr_cntx.mydev_gid,
				cod,
				serv);
	}
	else
#endif //__BT_DIALER_SUPPORT__


	{
    cui_bt_device_select_screen_set_mask(
        g_mmi_bt_scr_cntx.mydev_gid,
        MMI_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK,
        0);
	}
    cui_bt_device_select_screen_set_option_flag(g_mmi_bt_scr_cntx.mydev_gid, CUI_BT_CM_DEVICE_SELECT_OPTION_NORMAL);

    cui_bt_device_select_screen_run(g_mmi_bt_scr_cntx.mydev_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_my_specific_dev_menu
 * DESCRIPTION
 *  This function is to entry My specific device menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_BT_ENTRY_MY_SPEC_DEV_MENU,
        g_mmi_bt_scr_cntx.dev_cod_mask,
        g_mmi_bt_scr_cntx.dev_service_id);

    if (g_mmi_bt_scr_cntx.device_select_cui_state == MMI_TRUE)
    {
        /* to avoid the twice operation while bt is just on and wanna enter specific dev menu */
        //if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SPECIFIC_DEV)
        {
            MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SPECIFIC_DEV);
            //StopTimer(BT_POPUP_TIMER);
        }

#ifdef __MMI_BT_AUDIO_SUPPORT__
        if (srv_btsco_is_sco_open() && srv_ucm_is_any_call())
        {
            mmi_popup_display_ext(
                STR_BT_OPERATION_NOT_ALLOWED_DIS_HFP_FIRST,
                MMI_EVENT_FAILURE,
                NULL);
            return;
        }
#endif


        if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
        {
            MMI_BT_SET_FLAG(MMI_BT_CONFIRM_SPECIFIC_DEV);
            mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.mydev_gid);
            return;
        }
    }

    if (g_mmi_bt_scr_cntx.mydev_gid != GRP_ID_INVALID)
    {
        mmi_bt_show_mydev_screen();
    }
}


static void mmi_bt_mydev_csk_connect_hdlr(void)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_MYDEV_CSK_HDLR_FUNC);
	#ifdef __MMI_BT_DIALER_SUPPORT__
	if(srv_bt_cm_get_busy_dev() == NULL && srv_bt_cm_get_linked_dev_list_idx() != BT_DEVICE_LINK_NUM)
	{
        mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.mydev_gid);
    }
    else
	{
	  mmi_frm_nmgr_popup(
	                 MMI_SCENARIO_ID_DEFAULT,
	                 MMI_EVENT_FAILURE,
	                (WCHAR*)GetString(STR_BT_RELEASE_CONN_PROMPT));

	}
	#else
    mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.mydev_gid);
	#endif
}


static void mmi_bt_mydev_highlight_hdlr(S32 idx)
{
    if (idx == 0)
    {
#ifndef __MMI_BTBOX_NOLCD__
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
#endif
        SetLeftSoftkeyFunction(mmi_bt_inquiry_dev, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
        SetCenterSoftkeyFunction(mmi_bt_inquiry_dev, KEY_EVENT_UP);
    }
    else
    {
        const srv_bt_cm_dev_struct* dev_p;

        --idx;

        if (g_enable_pts_test)
        {
            dev_p = srv_bt_cm_get_dev_info_by_index(idx, SRV_BT_CM_PAIRED_DEV);
        }
        else
        {
            dev_p = mmi_bt_get_matched_dev(
                idx,
                g_mmi_bt_scr_cntx.dev_cod_mask,
                g_mmi_bt_scr_cntx.dev_service_id);
        }

        if (dev_p)
        {
            MMI_BT_SET_HILIGHT_ITEM(idx);
            memcpy(&g_mmi_bt_scr_cntx.conn_dev_add, &dev_p->bd_addr, sizeof(srv_bt_cm_bt_addr));

            if (g_mmi_bt_scr_cntx.dev_select_option_flag == CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT)
            {
#ifndef __MMI_BTBOX_NOLCD__
                ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
#endif
                SetLeftSoftkeyFunction(mmi_bt_entry_dev_select, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
                SetCenterSoftkeyFunction(mmi_bt_entry_dev_select, KEY_EVENT_UP);
            }
#ifdef __MMI_BT_DEF_SEND_DEVICE__
            else if (g_mmi_bt_scr_cntx.dev_select_option_flag ==
                     (CUI_BT_CM_DEVICE_SELECT_OPTION_SET_DEFAULT |
                      CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT))
            {
#ifndef __MMI_BTBOX_NOLCD__
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
#endif
                SetLeftSoftkeyFunction(mmi_bt_entry_dev_select, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
                SetCenterSoftkeyFunction(mmi_bt_entry_dev_select, KEY_EVENT_UP);
            }
#endif  // __MMI_BT_DEF_SEND_DEVICE__
            else
            {
#ifdef __MMI_BT_AUTHORIZE__
                if (srv_bt_cm_get_authorize(&dev_p->bd_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
                {
#ifndef __MMI_BTBOX_NOLCD__
                    ChangeLeftSoftkey(STR_BT_LSK_UNBLOCK, IMG_GLOBAL_OK);
#endif
                    SetLeftSoftkeyFunction(mmi_bt_entry_mydev_unblock, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
                    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
                    SetCenterSoftkeyFunction(mmi_bt_entry_mydev_unblock, KEY_EVENT_UP);
                }
                else
#endif  // __MMI_BT_AUTHORIZE__
                {
                		srv_bt_cm_dev_struct* bd_addr_p=(srv_bt_cm_dev_struct*)dev_p;
#ifndef __MMI_BTBOX_NOLCD__
                    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
#endif
                    SetLeftSoftkeyFunction(mmi_bt_entry_mydev_opt, KEY_EVENT_UP);
                    #ifndef __MMI_BT_DIALER_SUPPORT__

                    if ((srv_bt_cm_check_dev_profile_support_status(&(bd_addr_p->bd_addr), SRV_BT_CM_HFG_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(bd_addr_p->bd_addr), SRV_BT_CM_HS_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(bd_addr_p->bd_addr), SRV_BT_CM_HF_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(bd_addr_p->bd_addr), SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)) &&
                        !(srv_bt_cm_is_headset_connected(&bd_addr_p->bd_addr)))
                    #else
						
					if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) &&
                        !(srv_bt_cm_is_headset_connected(&bd_addr_p->bd_addr)) )
				    #endif/*__MMI_BT_DIALER_SUPPORT__*/
                    {
						#ifndef __MMI_WGUI_DISABLE_CSK__
                        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
						#endif 
                        SetCenterSoftkeyFunction(mmi_bt_mydev_csk_connect_hdlr, KEY_EVENT_UP);
                    }
                    else
                    {
						#ifndef __MMI_WGUI_DISABLE_CSK__
                        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
						#endif 
						#ifndef __MMI_BT_DIALER_SUPPORT__
                        SetCenterSoftkeyFunction(mmi_bt_entry_mydev_opt, KEY_EVENT_UP);
                        #else      
                        SetCenterSoftkeyFunction(mmi_bt_dialer_cent, KEY_EVENT_UP);
                        #endif/*__MMI_BT_DIALER_SUPPORT__*/
                    }
                }
            }
        }
    }
}


static S32 mmi_bt_get_mydev_item(S32 start_index, gui_iconlist_menu_item* menu_data, S32 num_items)
{
    U32 i, idx;

    for (i = 0; i < num_items; ++i)
    {
        idx = start_index + i;
        if (idx == 0)
        {
            kal_wsprintf(
                menu_data[i].item_list[0],
                "%w",
                (U16*)GetString(STR_BT_SCH_ALL_DEV));
			
			#if defined(_MMI_BWUI_BT_SLIM_)|| (defined(_MMI_BT_ULTRA_SLIM_)&&!defined(__MMI_BT_DIALER_SUPPORT__))
				menu_data[i].image_list[0] = NULL; //(PU8)GetImage(IMG_BT_MENU_TITLE);
			#else
            menu_data[i].image_list[0] = (PU8)GetImage(IMG_BT_MENU_TITLE);
			#endif
        }
        else
        {
            const srv_bt_cm_dev_struct* dev_p;

            --idx;
            if (g_enable_pts_test)
            {
                dev_p = srv_bt_cm_get_dev_info_by_index(idx, SRV_BT_CM_PAIRED_DEV);
            }
            else
            {
                dev_p = mmi_bt_get_matched_dev(
                    idx,
                    g_mmi_bt_scr_cntx.dev_cod_mask,
                    g_mmi_bt_scr_cntx.dev_service_id);
            }

            if (dev_p)
            {
                srv_bt_cm_get_dev_ucs2_name(
                    &dev_p->bd_addr,
                    SRV_BT_CM_BD_UCS2_NAME_LEN,
                    menu_data[i].item_list[0]);

                menu_data[i].image_list[0] = (PU8)mmi_bt_get_device_image(dev_p->cod);

                if (g_mmi_bt_scr_cntx.device_select_cui_state == MMI_FALSE)
                {
                    if (srv_bt_cm_is_dev_conn_active((srv_bt_cm_bt_addr*)&dev_p->bd_addr))
                    {
                    		#if defined(_MMI_BWUI_BT_SLIM_)
								menu_data[i].image_list[1] = (PU8)GetImage(CHECKBOX_ON_IMAGE_ID); //(PU8)GetImage(IMG_BT_CONNECTION_DATA);
							#else
                        menu_data[i].image_list[1] = (PU8)GetImage(IMG_BT_CONNECTION_DATA);
							#endif
                            #ifdef __MMI_BT_DIALER_SUPPORT__
                            mmi_bt_dialer_set_menu_num(idx);
                            #endif
                    }
                }
            }
        }
    }

    return num_items;
}

static S32 mmi_bt_get_mydev_item_hint(S32 item_index, UI_string_type *hint_array)
{
    if (item_index > 0)
    {
        const srv_bt_cm_dev_struct* dev_p;

        --item_index;
        if (g_enable_pts_test)
        {
            dev_p = srv_bt_cm_get_dev_info_by_index(item_index, SRV_BT_CM_PAIRED_DEV);
        }
        else
        {
            dev_p = mmi_bt_get_matched_dev(
                item_index,
                g_mmi_bt_scr_cntx.dev_cod_mask,
                g_mmi_bt_scr_cntx.dev_service_id);
        }
        
        if (dev_p)
        {
            mmi_bt_get_display_bt_address((WCHAR*)hint_array[0], &dev_p->bd_addr);
        }

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


static void mmi_bt_show_mydev_screen(void)
{
    U8* guiBuffer;
    U32 i, paired_dev_num;

    if (mmi_frm_scrn_enter(
            g_mmi_bt_scr_cntx.mydev_gid,
            SCR_BT_MYDEV,
            NULL,
            mmi_bt_show_mydev_screen,
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(mmi_bt_mydev_highlight_hdlr);
        //wgui_list_menu_disable_access_by_shortcut();

        paired_dev_num = srv_bt_cm_get_dev_num(SRV_BT_CM_PAIRED_DEV);
        if (g_enable_pts_test)
        {
            i = paired_dev_num;
        }
        else
        {
            for (i = 0; i < paired_dev_num; ++i)
            {
                if (!mmi_bt_get_matched_dev(
                        i,
                        g_mmi_bt_scr_cntx.dev_cod_mask,
                        g_mmi_bt_scr_cntx.dev_service_id))
                {
                    break;
                }
            }
        }
#ifndef _MMI_BT_ULTRA_SLIM_
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_fixed_list_register_get_flags_handler(mmi_bt_entry_device_list_seperate_line);
#endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#endif 
        wgui_cat1032_show(
            (WCHAR*)GetString(STR_BT_MYDEVICE),
            get_image(GetRootTitleIcon(MENU_CONN_BT_MAIN)),
            0,
            0,
            (WCHAR*)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            i + 1,
            mmi_bt_get_mydev_item,
            mmi_bt_get_mydev_item_hint,
            0,
            0,
            IMG_BT_DEV_OTHER,
            IMG_BT_CONNECTION_DATA,
            guiBuffer,
            NULL);
#ifndef __MMI_BTBOX_NOLCD__
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#endif
        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#ifndef _MMI_BT_ULTRA_SLIM_
        wgui_register_tap_callback(mmi_bt_mydev_menu_tap_callback);
#endif 
#endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)

    }
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
                #ifdef __MMI_BT_SLIM__
/* under construction !*/
                #endif
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
#ifndef _MMI_BT_ULTRA_SLIM_
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifndef _MMI_BT_ULTRA_SLIM_
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifndef _MMI_BT_ULTRA_SLIM_
            #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
/* under construction !*/
            #endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
#endif 
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
                    #ifdef __MMI_BT_AUTHORIZE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #endif /* __MMI_BT_AUTHORIZE__ */
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
                #ifdef __MMI_BT_AUTHORIZE__
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
                #endif /* __MMI_BT_AUTHORIZE__ */
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
#ifdef __MMI_BT_AUTHORIZE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BT_AUTHORIZE__ */
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
#endif  // #if 0

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_opt
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->My Dev->Option
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_OPT);

    /* to avoid the twice operation while bt is just on and wanna enter mydev option menu */
    //if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_OPT)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_OPT);
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_OPT);
        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.mydev_gid);
        return;
    }

    if (g_mmi_bt_scr_cntx.mydev_gid != GRP_ID_INVALID)
    {
        g_mmi_bt_scr_cntx.mydev_opt_menu_gid = cui_menu_create_and_run(
            g_mmi_bt_scr_cntx.mydev_gid,
            CUI_MENU_SRC_TYPE_APPCREATE,
            CUI_MENU_TYPE_OPTION,
            SCR_BT_MYDEV_OPT,
            MMI_FALSE,
            (void*)SCR_BT_MYDEV_OPT);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_opt_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_entry_mydev_opt_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    srv_bt_cm_dev_struct* dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);
    U16 nItems = 0;
#ifdef	__MMI_BT_DEFAULT_HEADSET__
#ifdef __MMI_HFP_SUPPORT__
    srv_bt_cm_bt_addr *bd_addr = NULL;
#endif
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        /* CUI Menu show event sent to APP before entering list menu screen */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == SCR_BT_MYDEV_OPT)
            {
                mmi_menu_id root_ids[MMI_BT_MYDEV_OPT_LAST];

#ifdef __MMI_FTC_SUPPORT__
                if (srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_OBEX_FILE_TRANSFER_UUID))
                {
                    root_ids[nItems++] = MMI_BT_MYDEV_OPT_FTP;
                }
#endif  // __MMI_FTC_SUPPORT__

#if defined(__MMI_HFP_SUPPORT__)
                if (!(srv_bt_cm_is_headset_connected(&dev_p->bd_addr)) &&
                   ((srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_HFG_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_HS_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_HF_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID))||
						mmi_bt_is_dev_cod_match(dev_p->cod,MMI_BT_AUDIO_MAJOR_SERVICE_MASK)))
                {
                    root_ids[nItems++] = MMI_BT_MYDEV_OPT_CONN;
                }
#endif /* defined(__MMI_HFP_SUPPORT__) */

                if (srv_bt_cm_is_dev_conn_active(&dev_p->bd_addr))
                {
                    root_ids[nItems++] = MMI_BT_MYDEV_OPT_DISCONN;
                }

#if MMI_MAX_SIM_NUM > 1
                {
                    mmi_bt_sim_list *list = mydev_init_sim_list(NULL);
                  	 if (list->count > 1 && srv_btaud_is_audio_device(&dev_p->bd_addr)&&!(srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION)||srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION)
                    	||srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
                        root_ids[nItems++] = MMI_BT_MYDEV_OPT_SIM;
                }
#endif

#ifdef __MMI_BT_DEFAULT_HEADSET__
            #ifdef __MMI_HFP_SUPPORT__
                if (srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_HS_PROFILE_UUID) ||
                    srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_HF_PROFILE_UUID) ||
                    srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID))
                {
                    root_ids[nItems++] = MMI_BT_MYDEV_OPT_SET_DEFAULT_HS;
                }
            #endif
#endif

#if !defined(__MMI_BT_SLIM__)
                root_ids[nItems++] = MMI_BT_MYDEV_OPT_SUP_SERV;
#endif

                root_ids[nItems++] = MMI_BT_MYDEV_OPT_REN;

#ifdef __MMI_BT_AUTHORIZE__
                root_ids[nItems++] = MMI_BT_MYDEV_OPT_AUTHOR;
#endif

                root_ids[nItems++] = MMI_BT_MYDEV_OPT_DEL;

	

                root_ids[nItems++] = MMI_BT_MYDEV_OPT_DEL_ALL;
#if defined(__MMI_HIDD_SUPPORT__)
				if(srv_bt_cm_dev_is_support_hid(dev_p))
				{
					root_ids[nItems++] = MMI_BT_MYDEV_OPT_REMOTE_CTRL;
				}
#endif /*defined(__MMI_HIDD_SUPPORT__)*/

                cui_menu_set_currlist(
                    menu_evt->sender_id,
                    nItems,
                    root_ids);

            #ifdef __MMI_FTC_SUPPORT__
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_FTP,
                    (WCHAR*)GetString(STR_BT_TRANSFER_FILES));
            #endif
            #ifdef __MMI_HFP_SUPPORT__
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_CONN,
                    (WCHAR*)GetString(STR_GLOBAL_CONNECT));
            #endif
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_DISCONN,
                    (WCHAR*)GetString(STR_GLOBAL_DISCONNECT));
            #if MMI_MAX_SIM_NUM > 1
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_SIM,
                    (WCHAR*)GetString(STR_BT_MYDEV_OPT_SIM));
            #endif
                
#ifdef __MMI_BT_DEFAULT_HEADSET__
            #ifdef __MMI_HFP_SUPPORT__
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_SET_DEFAULT_HS,
                    (WCHAR*)GetString(STR_BT_SET_DEFAULT_HEADSET));
            #endif
#endif
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_REN,
                    (WCHAR*)GetString(STR_GLOBAL_RENAME));
            #if !defined(__MMI_BT_SLIM__)
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_SUP_SERV,
                    (WCHAR*)GetString(STR_BT_MYDEV_OPT_SUP_SER));
            #endif

            #ifdef __MMI_BT_AUTHORIZE__
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_AUTHOR,
                    (WCHAR*)GetString(STR_BT_MYDEV_OPT_AUTHORIZE));
            #endif

                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_DEL,
                    (WCHAR*)GetString(STR_GLOBAL_DELETE));
#ifdef __MMI_BT_DIALER_SUPPORT__
				cui_menu_set_item_string(
								   menu_evt->sender_id,
								   MMI_BT_MYDEV_CONNECT,
								   (WCHAR*)GetString(STR_GLOBAL_CONNECTING));			
				cui_menu_set_item_string(
								   menu_evt->sender_id,
								   MMI_BT_MYDEV_DISCONNECT,
                    (WCHAR*)GetString(STR_GLOBAL_DISCONNECTING));
				
				cui_menu_set_item_string(
								   menu_evt->sender_id,
								   MMI_BT_MYDEV_HELP,
								   (WCHAR*)GetString(STR_GLOBAL_HELP));			
#endif 
			
#if defined(__MMI_HIDD_SUPPORT__)			
				cui_menu_set_item_string(
								   menu_evt->sender_id,
								   MMI_BT_MYDEV_OPT_REMOTE_CTRL,
								   (WCHAR*)GetString(STR_BT_REMOTE_CONTROL));
#endif /*defined(__MMI_HIDD_SUPPORT__)*/
#ifndef __MMI_BT_AUTO_RELEASE_CONNECTION__
                if (srv_bt_cm_is_dev_conn_active(&dev_p->bd_addr))
                {
                    cui_menu_set_item_disabled(
                        menu_evt->sender_id,
                        MMI_BT_MYDEV_OPT_DEL,
                        MMI_TRUE);
                }
                else
                {
                    cui_menu_set_item_disabled(
                        menu_evt->sender_id,
                        MMI_BT_MYDEV_OPT_DEL,
                        MMI_FALSE);
                }
#endif

                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_MYDEV_OPT_DEL_ALL,
                    (WCHAR*)GetString(STR_GLOBAL_DELETE_ALL));
#ifndef __MMI_BT_AUTO_RELEASE_CONNECTION__
                if (srv_bt_cm_get_existed_conn_num()>0)
                {
                    cui_menu_set_item_disabled(
                        menu_evt->sender_id,
                        MMI_BT_MYDEV_OPT_DEL_ALL,
                        MMI_TRUE);
                }
                else
                {
                    cui_menu_set_item_disabled(
                        menu_evt->sender_id,
                        MMI_BT_MYDEV_OPT_DEL_ALL,
                        MMI_FALSE);
                }
#endif


                cui_menu_set_default_title_string(
                    menu_evt->sender_id,
                    (WCHAR*)GetString(STR_GLOBAL_OPTIONS));

#ifdef __MMI_BT_DEFAULT_HEADSET__
            #ifdef __MMI_HFP_SUPPORT__
                bd_addr = (srv_bt_cm_bt_addr*)srv_bthf_read_config(BTHF_CFG_DEF_DEVICE);
                if (bd_addr != NULL)
                {
                    if (srv_bt_cm_is_dev_addr_equal(bd_addr, &dev_p->bd_addr))
                    {
                        cui_menu_set_item_disabled(
                            menu_evt->sender_id,
                            MMI_BT_MYDEV_OPT_SET_DEFAULT_HS,
                            MMI_TRUE);
                    }
                }
            #endif
#endif
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
            #ifdef __MMI_FTC_SUPPORT__
                case MMI_BT_MYDEV_OPT_FTP:
                {
                    mmi_bt_entry_mydev_conn_ftp();
                    break;
                }
            #endif

            #ifdef __MMI_HFP_SUPPORT__
                case MMI_BT_MYDEV_OPT_CONN:
                {
					if(srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_HFG_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_HS_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_HF_PROFILE_UUID)||
						srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID))
                    {
                        mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.mydev_gid);
                    }
                    break;
                }
            #endif

            #if MMI_MAX_SIM_NUM > 1
                case MMI_BT_MYDEV_OPT_SIM:

                    mmi_bt_mydev_show_sim_setting(&dev_p->bd_addr);
                    
                    break;
            #endif

            #if !defined(__MMI_BT_SLIM__)
                case MMI_BT_MYDEV_OPT_SUP_SERV:
                {
                    if (dev_p->service_list_num == 0)
                    {
                        mmi_bt_mydev_refresh_service();
                    }
                    else
                    {
                        mmi_bt_entry_mydev_service_list();
                    }
                    break;
                }
            #endif

                case MMI_BT_MYDEV_OPT_DISCONN:
                {
                    #ifdef __MMI_BT_DIALER_SUPPORT__
                    mmi_bt_dialer_set_disconn_req(MMI_TRUE);
                    #endif
                    mmi_bt_entry_release_device_connections(g_mmi_bt_scr_cntx.mydev_gid);
                    break;
                }

            #ifdef __MMI_BT_AUTHORIZE__
                case MMI_BT_MYDEV_OPT_AUTHOR:
                {
                    mmi_bt_entry_mydev_authorize();
                    break;
                }
            #endif

                case MMI_BT_MYDEV_OPT_REN:
                {
                    mmi_bt_entry_mydev_ren();
                    break;
                }

                case MMI_BT_MYDEV_OPT_DEL:
                {

                   mmi_bt_entry_mydev_delete_confirm(MMI_BT_DELETE_DEV_CONFIRM);

                    break;
                }
#ifdef __MMI_BT_DIALER_SUPPORT__
        
				case MMI_BT_MYDEV_CONNECT:
				{
					#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__
					mmi_bt_dialer_auto_reconn_reset();
                    #endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/
					if (mmi_bt_is_dev_cod_match(dev_p->cod, (MMI_BT_AUDIO_MAJOR_SERVICE_MASK|MMI_BT_AV_MAJOR_DEVICE_MASK)) )
					{
							mmi_bt_entry_connecting(g_mmi_bt_scr_cntx.mydev_gid);
					}
					else
					{
					mmi_bt_dialor_connect(&(dev_p->bd_addr));
					}
                    break;
                }
				case MMI_BT_MYDEV_DISCONNECT:
				{
					mmi_bt_dialor_disconnect(&(dev_p->bd_addr));
                    break;
                }
        
				case MMI_BT_MYDEV_HELP:
                {
					 mmi_bt_show_dialor_help(dev_p);
                    break;
                }

                
			
#endif 
                case MMI_BT_MYDEV_OPT_DEL_ALL:
                {

                    mmi_bt_entry_mydev_delete_confirm(MMI_BT_DELETE_DEV_ALL_CONFIRM);
		
                    break;
                }

#ifdef __MMI_BT_DEFAULT_HEADSET__
            #ifdef __MMI_HFP_SUPPORT__
                case MMI_BT_MYDEV_OPT_SET_DEFAULT_HS:
                {
                    mmi_bt_entry_mydev_set_default_hs();
                    break;
                }
            #endif
#endif
#ifdef __MMI_HIDD_SUPPORT__											
				case MMI_BT_MYDEV_OPT_REMOTE_CTRL:
                {
					mmi_bt_entry_remote_control_ext(&(dev_p->bd_addr));	
					break;
                }
#endif
                default:
                    break;
            }

         default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_dev_select
 * DESCRIPTION
 *  This function is select my specific devcie
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_dev_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SELECT_MY_SPEC_DEV);

    dev_p = mmi_bt_get_matched_dev(
        g_mmi_bt_scr_cntx.hilight_item,
        g_mmi_bt_scr_cntx.dev_cod_mask,
        g_mmi_bt_scr_cntx.dev_service_id);

    /* check if device is blocked */
#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_get_authorize(&(dev_p->bd_addr)) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
    {
        mmi_bt_popup_prohibited_by_blocked_device();
        return;
    }
#endif /* __MMI_BT_AUTHORIZE__ */

    /* store specific device */
    memcpy(&(g_mmi_bt_scr_cntx.selected_spec_dev), dev_p, sizeof(srv_bt_cm_dev_struct));

    if (g_mmi_bt_scr_cntx.dev_select_option_flag == CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT)
    {
        cui_bt_device_select_hdlr(MMI_TRUE, dev_p->bd_addr.lap, dev_p->bd_addr.uap, dev_p->bd_addr.nap);
        //g_mmi_bt_scr_cntx.dev_select_cui_notify_flag = MMI_TRUE;
    }
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    else
    {
        mmi_bt_entry_dev_select_opt();
    }
#endif
}


#ifdef __MMI_BT_DEF_SEND_DEVICE__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_dev_select_opt
 * DESCRIPTION
 *  This function is to entry device select option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_dev_select_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.mydev_opt_menu_gid = cui_menu_create_and_run(
        g_mmi_bt_scr_cntx.mydev_gid,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_OPTION,
        SCR_BT_SEND_DEVICE_OPTION,
        MMI_FALSE,
        (void*)SCR_BT_SEND_DEVICE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_dev_select_opt_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_entry_dev_select_opt_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    S32 nItems = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == SCR_BT_SEND_DEVICE_OPTION)
            {
                mmi_menu_id root_ids[MMI_BT_DEVICE_SELECT_OPT_TOTAL];

                root_ids[nItems++] = MMI_BT_DEVICE_SELECT_OPT_SEND;

                if (!(srv_bt_cm_is_dev_addr_equal(
                          &g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr,
                          &g_mmi_bt_scr_cntx.specific_hilight_dev)))
                {
                    root_ids[nItems++] = MMI_BT_DEVICE_SELECT_OPT_SETDEF;
                }

                if (g_mmi_bt_scr_cntx.specific_hilight_dev.lap != 0 ||
                    g_mmi_bt_scr_cntx.specific_hilight_dev.uap != 0 ||
                    g_mmi_bt_scr_cntx.specific_hilight_dev.nap != 0)
                {
                    root_ids[nItems++] = MMI_BT_DEVICE_SELECT_OPT_CLEARDEF;
                }

                cui_menu_set_currlist(menu_evt->sender_id, nItems, root_ids);

                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_DEVICE_SELECT_OPT_SEND,
                    (WCHAR*)GetString(STR_GLOBAL_SEND));
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_DEVICE_SELECT_OPT_SETDEF,
                    (WCHAR*)GetString(STR_BT_SEND_OPTION_SETDEF));
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MMI_BT_DEVICE_SELECT_OPT_CLEARDEF,
                    (WCHAR*)GetString(STR_BT_SEND_OPTION_CLEARDEF));
                cui_menu_set_default_title_string(
                    menu_evt->sender_id,
                    (WCHAR*)GetString(STR_GLOBAL_OPTIONS));
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case MMI_BT_DEVICE_SELECT_OPT_SEND:
                {
                    mmi_bt_dev_select_to_send();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }
                case MMI_BT_DEVICE_SELECT_OPT_SETDEF:
                {
                    mmi_bt_dev_select_set_default();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }
                case MMI_BT_DEVICE_SELECT_OPT_CLEARDEF:
                {
                    mmi_bt_dev_select_clear_default();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                }
                default:
                    break;
            }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dev_select_to_send
 * DESCRIPTION
 *  This function is to select deice to send
 *  It invoke common UI API to return the result to parent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dev_select_to_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_bt_device_select_hdlr(
        MMI_TRUE,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.lap,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.uap,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.nap);

    //g_mmi_bt_scr_cntx.pwf_cnf_cui_notify_flag = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dev_select_set_default
 * DESCRIPTION
 *  This function is to set device as default
 *  It invoke common UI API to return the result to parent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dev_select_set_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_bt_device_set_default_hdlr(
        MMI_TRUE,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.lap,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.uap,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.nap);

    mmi_frm_scrn_close(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_SEND_DEVICE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dev_select_clear_default
 * DESCRIPTION
 *  This function is to clear default device
 *  It invoke common UI API to return the result to parent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_dev_select_clear_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_bt_device_set_default_hdlr(
        MMI_FALSE,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.lap,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.uap,
        g_mmi_bt_scr_cntx.selected_spec_dev.bd_addr.nap);

    mmi_frm_scrn_close(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_SEND_DEVICE_OPTION);
}
#endif  // __MMI_BT_DEF_SEND_DEVICE__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_vis
 * DESCRIPTION
 *  This function is to entry Settings -> visibility
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_vis(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_visibility_type visibility_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET_VISIBILITY)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET_VISIBILITY);
        //StopTimer(BT_POPUP_TIMER);
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_SET_VISIBILITY);
        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.main_gid);
        return;
    }

    /* prohibit visibility setting while a2dp is active */
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION))
    {
        mmi_bt_popup_display(
            STR_BT_PROHIBIT_VIS_BY_A2DP,
            MMI_EVENT_FAILURE,
            g_mmi_bt_scr_cntx.main_gid);
        return;
    }
	#ifdef __MMI_BT_DIALER_SUPPORT__
	if (srv_bt_cm_get_busy_dev()!= NULL)
    {
		mmi_bt_popup_display(
			   STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
			   MMI_EVENT_FAILURE,
			   g_mmi_bt_scr_cntx.main_gid);

	}
	#endif
#ifndef __MMI_BT_TEMP_VISIBILITY__
    if (g_mmi_bt_scr_cntx.main_gid != GRP_ID_INVALID)
    {
        if (srv_bt_cm_get_visibility() == SRV_BT_CM_VISIBILITY_ON)
        {
            visibility_type = SRV_BT_CM_VISIBILITY_OFF;
        }
        else
        {
            visibility_type = SRV_BT_CM_VISIBILITY_ON;
        }

        if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_set_visibility(visibility_type))
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    	#endif
        }
        else
        {
            mmi_bt_popup_display(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                g_mmi_bt_scr_cntx.main_gid);
        }
    }
#else  // __MMI_BT_TEMP_VISIBILITY__
    if (g_mmi_bt_scr_cntx.main_gid != GRP_ID_INVALID)
    {
        cui_menu_create_and_run(
            g_mmi_bt_scr_cntx.main_gid,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_FROM_RESOURCE,
            MENU_CONN_BT_SET_VIS,
            MMI_FALSE,
            (void*)MENU_CONN_BT_SET_VIS);
    }
#endif  // __MMI_BT_TEMP_VISIBILITY__

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_SET_VIS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_vis_complete
 * DESCRIPTION
 *  This is UI screen function for setting vis completely
 * PARAMETERS
 *  result      [IN]            the setting visibility result
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_vis_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_visibility_struct *event = (srv_bt_cm_set_visibility_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_VIS_COMPLETE);

    //mmi_bt_update_status_icon();

    if (event->is_from_mmi)
    {
        if (!(event->result))
        {
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
        }

        mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.main_gid, SCR_BT_SET_VIS);
    }

    if (g_mmi_bt_scr_cntx.main_menu_gid > 0)
    {
        if (g_mmi_bt_scr_cntx.main_menu_gid == mmi_frm_group_get_active_id())
        {
            mmi_bt_refresh_screen();
        }
    }
#if defined(__MMI_BT_DIALER_SUPPORT__) && !defined(__MMI_BTBOX_NOLCD__)
    {
		mmi_bt_dialer_conn_set_vis_state();
    }
	#endif
}


#ifdef __MMI_BT_TEMP_VISIBILITY__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_vis_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bt_entry_set_vis_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_menu_id hightlighted_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(
                menu_evt->sender_id,
                CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
            {
                switch (srv_bt_cm_get_visibility())
                {
                    case SRV_BT_CM_VISIBILITY_ON:
                        hightlighted_menu = MENU_CONN_BT_SET_VIS_PERMANENT_ON;
                        break;

                    case SRV_BT_CM_VISIBILITY_TEMPORARY_ON:
                        hightlighted_menu = MENU_CONN_BT_SET_VIS_TEMPORARY_ON;
                        break;

                    default:
                        hightlighted_menu = MENU_CONN_BT_SET_VIS_OFF;
                        break;
                }

                cui_menu_set_radio_list_item(
                    menu_evt->sender_id,
                    hightlighted_menu);
            }
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_bt_entry_set_vis_select(menu_evt->highlighted_menu_id);
            cui_menu_close(menu_evt->sender_id);
            break;

        // case EVT_ID_CUI_MENU_ITEM_HILITE:
        // {
        //     switch (menu_evt->highlighted_menu_id)
        //     {
        //         case MENU_CONN_BT_SET_VIS_PERMANENT_ON:
        //             MMI_BT_SET_HILIGHT_ITEM(MMI_BT_VISIBILITY_PERMANENT_ON);
        //             break;
        //         case MENU_CONN_BT_SET_VIS_TEMPORARY_ON:
        //             MMI_BT_SET_HILIGHT_ITEM(MMI_BT_VISIBILITY_TEMPORARY_ON);
        //             break;
        //         case MENU_CONN_BT_SET_VIS_OFF:
        //             MMI_BT_SET_HILIGHT_ITEM(MMI_BT_VISIBILITY_OFF);
        //             break;
        //         default:
        //             break;
        //     }
        // }
        // break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_vis_select
 * DESCRIPTION
 *  This function is to configure visibility
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_entry_set_vis_select(mmi_menu_id highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_visibility_type type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_VIS_PROC);

    /* prohibit visibility setting while a2dp is active */
#ifdef __MMI_A2DP_SUPPORT__
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION))
    {
        mmi_bt_popup_display(
            STR_BT_PROHIBIT_VIS_BY_A2DP,
            MMI_EVENT_FAILURE,
            g_mmi_bt_scr_cntx.main_gid);
        return;
    }
#endif  // __MMI_A2DP_SUPPORT__

    switch (highlighted_menu_id)
    {
        case MENU_CONN_BT_SET_VIS_PERMANENT_ON:
            type = SRV_BT_CM_VISIBILITY_ON;
            break;

        case MENU_CONN_BT_SET_VIS_TEMPORARY_ON:
            type = SRV_BT_CM_VISIBILITY_TEMPORARY_ON;
            break;

        default:
            type = SRV_BT_CM_VISIBILITY_OFF;
            break;
    }

    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_set_visibility(type))
    {
    	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    	#endif
    }
    else
    {
        mmi_bt_popup_display(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            g_mmi_bt_scr_cntx.main_gid);
    }
}
#endif /*__MMI_BT_TEMP_VISIBILITY__*/


#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_limit_vis
 * DESCRIPTION
 *  This function is entry function of set limited discoverable mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_limit_vis(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL visibility;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_SET_LIMIT_VIS);

    /* prohibit visibility setting while a2dp is active */
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION))
    {
        mmi_popup_display_ext(
            STR_BT_PROHIBIT_VIS_BY_A2DP,
            MMI_EVENT_FAILURE,
            NULL);
        return;
    }

    /* if it's in limited discovery mode, set the state as SRV_BT_CM_STATE_RESETTING_LIMIT_VISIBILITY */
    /* then invoke mmi_bt_set_limit_vis_req(MMI_FALSE)*/
    /* change state -> link allow req */
    if (srv_bt_cm_is_limit_vis())
    {
        visibility = MMI_FALSE;
    }
    else
    /* if it's not in limited discovery mode, set the state as SRV_BT_CM_STATE_SETTING_LIMIT_VISIBILITY */
    /* then invoke mmi_bt_link_disallow_req*/
    /* link disallow req -> change state */
    {
        visibility = MMI_TRUE;
    }

    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_set_limit_vis(visibility))
    {
        mmi_bt_show_progress_scr(
            g_mmi_bt_scr_cntx.main_gid,
            SCR_BT_SWITCH_LIMIT_DISCOVER_MODE,
            STR_GLOBAL_BLUETOOTH,
            STR_GLOBAL_PLEASE_WAIT,
            NULL);
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_temp_vis_complete
 * DESCRIPTION
 *  This function is to handle the screen when set limit visibility complete
 * PARAMETERS
 *  result    [IN]    the result of set limit discovery mode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_limit_vis_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_limit_discoverable_mode_struct *event = (srv_bt_cm_set_limit_discoverable_mode_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_stop_progress_scr(
        g_mmi_bt_scr_cntx.main_gid,
        SCR_BT_SWITCH_LIMIT_DISCOVER_MODE);

    switch (event->result)
    {
        case BTBM_ADP_SUCCESS:
            if (srv_bt_cm_is_limit_vis())
            {
                /* if set limit discovery mode succeed, show a progress screen to notify user */
                mmi_bt_show_progress_scr(
                    g_mmi_bt_scr_cntx.main_gid,
                    SCR_BT_LIMIT_DISCOVER_MODE,
                    STR_GLOBAL_BLUETOOTH,
                    STR_BT_IN_LIMIT_DISCOVERABLE_MODE,
                    mmi_bt_entry_set_limit_vis);
                srv_bt_cm_set_limit_vis(MMI_FALSE);
                return;
            }

            //mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR *)GetString(STR_GLOBAL_DONE));
            break;

        case BTBM_ADP_FAIL_BUSY:
        case BTBM_ADP_FAIL_NOT_ALLOW:
        default:
            /* Service unavailable */
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTSetLimitedDiscoverabeMode
 * DESCRIPTION
 *  This function is highlight function of BT limited discoverable mode in engineer mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmBTSetLimitedDiscoverabeMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) ||
        (!srv_bt_cm_is_limit_vis()))
    {
#ifndef __MMI_BTBOX_NOLCD__
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
#endif
        Category52ChangeItemDescription((S32)index, (U8*)GetString(STR_GLOBAL_OFF));
    }
    else // limit visibility
    {
#ifndef __MMI_BTBOX_NOLCD__
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
#endif 
        Category52ChangeItemDescription((S32)index, (U8*)GetString(STR_GLOBAL_ON));
    }
#ifndef __MMI_BTBOX_NOLCD__
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#endif
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_bt_entry_set_limit_vis, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mmi_bt_entry_set_limit_vis, KEY_EVENT_UP);
}
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/


#ifdef __MMI_BT_AUTHORIZE__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_confirm_hdlr
 * DESCRIPTION
 *  This function is to show the confirm dialog to do the authorization
 *  It will create a screen first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_authorize_confirm_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_entry_authorize_confirm_scr_hdlr();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_authorize_confirm_scr_hdlr
 * DESCRIPTION
 *  This function is to show the confirm dialog to do the authorization
 *  It will create a screen first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_authorize_confirm_scr_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if has already exist, and active screen is just the screen, don't show the screen */
    if (mmi_frm_scrn_is_present(GRP_ID_BT_CM_AUTH, SCR_BT_AUTH_CONFIRM, MMI_FRM_NODE_ALL_FLAG))
    {
        if (mmi_frm_scrn_get_active_id() != SCR_BT_AUTH_CONFIRM)
        {
            mmi_frm_scrn_close(GRP_ID_BT_CM_AUTH, SCR_BT_AUTH_CONFIRM);
        }
    }

        /* re-entry problem */
    if (!mmi_frm_group_is_present(GRP_ID_BT_CM_AUTH))
    {
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_BT_CM_AUTH,
            mmi_bt_authorize_confirm_group_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    mmi_bt_entry_authorize_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_authorize_confirm_screen
 * DESCRIPTION
 *  This function is to show the confirm dialog to do the authorization
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_authorize_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_AUTH_CONFIRM);

    if (mmi_frm_scrn_enter(
            GRP_ID_BT_CM_AUTH,
            SCR_BT_AUTH_CONFIRM,
            (FuncPtr) NULL,
            (FuncPtr) mmi_bt_entry_authorize_confirm_screen,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory2Screen(
        STR_GLOBAL_AUTHENTICATION,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_BT_ALWAYS_ACCEPT_CONNECTION,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_bt_authorize_alway_connect, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mmi_bt_authorize_alway_connect, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_confirm_group_proc
 * DESCRIPTION
 *  This function is BT CM authentication group proc function
 * PARAMETERS
 *  param       [IN]        MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_authorize_confirm_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            break;

        case EVT_ID_GROUP_INACTIVE:
            break;

        case EVT_ID_GROUP_DEINIT:
            break;

        case EVT_ID_POPUP_QUIT:
            break;

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            mmi_frm_end_scenario(MMI_SCENARIO_ID_DEFAULT);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_alway_connect
 * DESCRIPTION
 *  This function is to do the authorization, show the popup, and the delete the screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_authorize_alway_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_AUTH_DEV_HDLER);
    MMI_BT_SET_FLAG(MMI_BT_SET_ALWAYS_CONNECT_BY_PAIR);
    if (srv_bt_cm_set_authorize(&(g_mmi_bt_scr_cntx.selct_dev_addr), SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT) != SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
    else
    {
        mmi_frm_scrn_close(GRP_ID_BT_CM_AUTH, SCR_BT_AUTH_CONFIRM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_authorize
 * DESCRIPTION
 *  This function is the entry function for Bluetooth->My Dev->Option->Authorize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_authorize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_AUTHORIZE);

    g_mmi_bt_scr_cntx.authorize_menu_gid = cui_menu_create_and_run(
        g_mmi_bt_scr_cntx.mydev_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_CONN_BT_MYDEV_AUTHORIZE,
        MMI_FALSE,
        (void*)MENU_CONN_BT_MYDEV_AUTHORIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_authorize_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_entry_mydev_authorize_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    srv_bt_cm_dev_struct * dev_p;
    U16 hightlighted_menu = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(
                menu_evt->sender_id,
                CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
            {
                dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);

                switch (srv_bt_cm_get_authorize(&dev_p->bd_addr))
                {
                    case SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT:
                        hightlighted_menu = MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_CONNECT;
                        break;

                    case SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT:
                        hightlighted_menu = MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_REJECT;
                        break;

                    default:
                        hightlighted_menu = MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_ASK;
                        break;
                }

                cui_menu_set_radio_list_item(
                    menu_evt->sender_id,
                    hightlighted_menu);
            }
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            srv_bt_cm_authorize_type type;

            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_ASK:
                    type = SRV_BT_CM_AUTHORIZE_ALWAYS_ASK;
                    break;

                case MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_CONNECT:
                    type = SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT;
                    break;

                case MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_REJECT:
                default:
                    type = SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT;
                    break;
            }

            mmi_bt_entry_mydev_authorize_select(type);
        }
        break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_authorize_select
 * DESCRIPTION
 *  This function is the exit function for Bluetooth->My Dev->Option->Authorize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_authorize_select(srv_bt_cm_authorize_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_AUTHORIZE_PROC);
    /* to avoid the twice operation*/
#ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_AUTHORIZE_REJECT)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_AUTHORIZE_REJECT);
        //StopTimer(BT_POPUP_TIMER);
    }
#endif  //__MMI_BT_AUTO_RELEASE_CONNECTION__

    dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);

    g_mmi_bt_scr_cntx.selct_dev_addr = dev_p->bd_addr;

    switch (type)
    {
        case SRV_BT_CM_AUTHORIZE_ALWAYS_ASK:
        case SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT:
            if (srv_bt_cm_set_authorize(&(dev_p->bd_addr), type) != SRV_BT_CM_RESULT_SUCCESS)
            {
                mmi_popup_display_ext(
                    STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                    MMI_EVENT_FAILURE,
                    NULL);
            }
            break;

        case SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT:
            /* ask if release all active connections */
            if (srv_bt_cm_is_dev_conn_active(&(dev_p->bd_addr)))
            {
            #ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
                mmi_bt_display_release_connection_confirm(g_mmi_bt_scr_cntx.mydev_gid, MMI_BT_RELEASE_DEVICE_CONNECTION);
                MMI_BT_SET_FLAG(MMI_BT_CONFIRM_AUTHORIZE_REJECT);
            #else
                mmi_bt_popup_display(STR_BT_DISCONN_DEV_CONN, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.mydev_gid);
            #endif
            }
            else
            {
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_a2dp_bt_delete_device_callback(&(dev_p->bd_addr));
            #endif
            #ifdef __MMI_BPP_SUPPORT__
                mmi_bt_bpp_delete_device_callback((const srv_bt_cm_bt_addr *)&(dev_p->bd_addr));
            #endif
            #ifdef __MMI_BT_DEF_SEND_DEVICE__
                mmi_btsend_delete_device_callback(&(dev_p->bd_addr));
            #endif

                if (srv_bt_cm_set_authorize(&(dev_p->bd_addr), type) != SRV_BT_CM_RESULT_SUCCESS)
                {
                    mmi_popup_display_ext(
                        STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                        MMI_EVENT_FAILURE,
                        NULL);
                }
            }
            return;

        default:
            //if (srv_bt_cm_set_authorize(&(dev_p->bd_addr), SRV_BT_CM_AUTHORIZE_ALWAYS_ASK)!= SRV_BT_CM_RESULT_SUCCESS)
            //{
            //    mmi_popup_display_ext(
            //        STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            //        MMI_EVENT_FAILURE,
            //        NULL);
            //}
            //else
            //{
            //    mmi_bt_popup_display(GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, g_mmi_bt_scr_cntx.mydev_gid);
            //}
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_as_default_authorize_dev
 * DESCRIPTION
 *  This function is to set as default authorize device
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_as_always_connect_hf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_set_authorize(&(g_mmi_bt_scr_cntx.conn_dev_add), SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT) != SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
    else
    {
        mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_RELEASE_AUD_CONN_CNF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_authorize_complete
 * DESCRIPTION
 *  This function is to display the result of blocking request
 * PARAMETERS
 *  result   [IN] blocking result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_authorize_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev_p;
    srv_bt_cm_set_authorize_struct *event = (srv_bt_cm_set_authorize_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_BLOCK_COMPLETE, event->result);
    if ((MMI_BT_INQ_TYPE_AUDIO & g_mmi_bt_scr_cntx.flag) ||
        (MMI_BT_SET_ALWAYS_CONNECT_BY_PAIR & g_mmi_bt_scr_cntx.flag))
    {
        MMI_BT_RESET_FLAG(MMI_BT_INQ_TYPE_AUDIO);
        mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_CONNECT_CNF);

        MMI_BT_RESET_FLAG(MMI_BT_SET_ALWAYS_CONNECT_BY_PAIR);
    }
    //else
    //{
    //    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)GetString(STR_GLOBAL_DONE));
    //}

    if (mmi_frm_group_is_present(g_mmi_bt_scr_cntx.authorize_menu_gid) ||
#if !defined(__MMI_BT_SLIM__)
        mmi_frm_group_is_present(g_mmi_bt_scr_cntx.srv_list_menu_gid) ||
#endif
        mmi_frm_group_is_present(g_mmi_bt_scr_cntx.fseditor_gid))
    {
        //if (g_mmi_bt_scr_cntx.hilight_item >= 0)
        {
            dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);

            if (srv_bt_cm_is_dev_addr_equal(&dev_p->bd_addr, &g_mmi_bt_scr_cntx.selct_dev_addr))
            {
                if (mmi_frm_group_is_present(g_mmi_bt_scr_cntx.authorize_menu_gid))
                {
                    cui_menu_close(g_mmi_bt_scr_cntx.authorize_menu_gid);
                    g_mmi_bt_scr_cntx.authorize_menu_gid = 0;
                }
#if !defined(__MMI_BT_SLIM__)
                else if (mmi_frm_group_is_present(g_mmi_bt_scr_cntx.srv_list_menu_gid))
                {
                    cui_menu_close(g_mmi_bt_scr_cntx.srv_list_menu_gid);
                    g_mmi_bt_scr_cntx.srv_list_menu_gid = 0;
                }
#endif
                else
                {
                    if (cui_fseditor_get_parent_data(g_mmi_bt_scr_cntx.fseditor_gid) == SCR_BT_MYDEV_REN)
                    {
                        cui_fseditor_close(g_mmi_bt_scr_cntx.fseditor_gid);
                        g_mmi_bt_scr_cntx.fseditor_gid = 0;
                    }
                }
            }
        }
    }

    mmi_frm_group_close(GRP_ID_BT_CM_BLOCK_CNF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_unblock
 * DESCRIPTION
 *  This function is unblock the paired device
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_unblock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_UNBLOCK);

    //if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_UNBLOCK)
    //{
    //    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_UNBLOCK);
    //}

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_UNBLOCK);
        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.mydev_gid);
        return;
    }

    if (srv_bt_cm_unblock(&(g_mmi_bt_scr_cntx.conn_dev_add)) != SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_unblock_complete
 * DESCRIPTION
 *  This function is to display the result of unblocking request
 * PARAMETERS
 *  result   [IN] unblocking result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_unblock_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_unblock_struct *event = (srv_bt_cm_unblock_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_UNBLOCK_COMPLETE, event->result);
    if (g_mmi_bt_scr_cntx.mydev_gid)
    {
        mmi_bt_refresh_screen();
    }
    //mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)GetString(STR_GLOBAL_DONE));
}
#endif /* __MMI_BT_AUTHORIZE__ */

void mmi_bt_entry_set_name_ext(mmi_id grp_id,srv_bt_cm_dev_struct *dev_p,U16 title,U32 parent_screen)
{
	if (grp_id != GRP_ID_INVALID)
    {
        g_mmi_bt_scr_cntx.fseditor_gid = cui_fseditor_create(grp_id);

        if (g_mmi_bt_scr_cntx.fseditor_gid != GRP_ID_INVALID)
        {
            mmi_chset_utf8_to_ucs2_string(
                (U8*)g_mmi_bt_scr_cntx.scr_buf,
                SRV_BT_CM_BD_NAME_UCS2_LEN,
                dev_p->name);

            cui_fseditor_set_title(
                g_mmi_bt_scr_cntx.fseditor_gid,
                title,
                GetRootTitleIcon(MENU_CONN_BT_MAIN));
            cui_fseditor_set_buffer(
                g_mmi_bt_scr_cntx.fseditor_gid,
                (WCHAR*) g_mmi_bt_scr_cntx.scr_buf,
                (SRV_BT_CM_BD_NAME_UCS2_LEN / ENCODING_LENGTH),
                ((SRV_BT_CM_BD_FNAME_LEN-2)/3));
            cui_fseditor_set_input_method(
                g_mmi_bt_scr_cntx.fseditor_gid,
                IMM_INPUT_TYPE_SENTENCE,
                NULL,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            cui_fseditor_set_parent_data(g_mmi_bt_scr_cntx.fseditor_gid, parent_screen);
            cui_fseditor_run(g_mmi_bt_scr_cntx.fseditor_gid);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_name
 * DESCRIPTION
 *  This function is to entry settings -> set name
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_SET_NAME);
	dev_p = (srv_bt_cm_dev_struct*)srv_bt_cm_get_host_dev_info();

	mmi_bt_entry_set_name_ext(g_mmi_bt_scr_cntx.main_gid,dev_p,STR_BT_DEV_SET_NAME,SCR_BT_SET_NAME);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_name_proc
 * DESCRIPTION
 *  This function is to process setting -> set name
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_name_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 name_convert[SRV_BT_CM_BD_FNAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_NAME_PROC);

    mmi_chset_ucs2_to_utf8_string(
        (kal_uint8*) name_convert,
        SRV_BT_CM_BD_FNAME_LEN,
        (kal_uint8*) (g_mmi_bt_scr_cntx.scr_buf));

    /* Donot show set-name progresssing screen */
    /* because the response is back right away */
    if (srv_bt_cm_set_host_dev_name((U8*) name_convert) != SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_name_complete
 * DESCRIPTION
 *  This function is to handle set name complete
 * PARAMETERS
 *  result      [IN]            set name result
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_name_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_name_struct *event = (srv_bt_cm_set_name_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Donot show set-name progresssing screen */
    /* because the response is back right away. */
    /* It is not required to stop progressing screen here */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_NAME_PROC_COMPLETE, event->result);
	if(event->result!=BTBM_ADP_SUCCESS)
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
    mmi_frm_scrn_close(g_mmi_bt_scr_cntx.main_gid, SCR_BT_SET_NAME);

    cui_fseditor_close(g_mmi_bt_scr_cntx.fseditor_gid);
    g_mmi_bt_scr_cntx.fseditor_gid = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_menu
 * DESCRIPTION
 *  This function is to entry setting menu
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef _MMI_BT_ULTRA_SLIM_
void mmi_bt_entry_set_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_SET_MENU);
    /* to avoid the twice operation while bt is just on and wanna enter setting menu */
    //if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SET)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET);
        //StopTimer(BT_POPUP_TIMER);
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_SET);
        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.main_gid);
        return;
    }

    if (g_mmi_bt_scr_cntx.main_gid != GRP_ID_INVALID)
    {
        g_mmi_bt_scr_cntx.advance_menu_gid = cui_menu_create_and_run(
            g_mmi_bt_scr_cntx.main_gid,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_FROM_RESOURCE,
            MENU_CONN_BT_SET,
            MMI_FALSE,
            (void*)MENU_CONN_BT_SET);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_menu_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_set_menu_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
#ifndef _MMI_BT_ULTRA_SLIM_
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_CONN_BT_SET_AUDIO_PATH,
                mmi_bt_get_audio_pth());
#endif 

#if defined(__MMI_FTS_SUPPORT__)
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_CONN_BT_SET_PERMISSION,
                mmi_bt_get_permission_setting_string());
#endif

#if defined(__MMI_HIDD_SUPPORT__)
            {
                WCHAR* buff = NULL;
                U32 size;

                size = (SRV_BT_CM_BD_FNAME_LEN / 3) * 2 + 2;
                buff = (WCHAR*)get_ctrl_buffer(size);
                mmi_bt_get_remote_control_menu_hint_string(buff, size);

                if (buff[0] != 0)
                {
                    cui_menu_set_item_hint(
                        menu_evt->sender_id,
                        MENU_CONN_BT_REMOTE_CONTROL,
                        (WCHAR*)buff);
                }

                free_ctrl_buffer(buff);
            }
#endif

#ifdef __MMI_SIMAP_SUPPORT__
            /* hide SAP menu when it's in flight mode */
            if (mmi_bt_is_bt_in_flight_mode())
            {
                // cui_menu_set_item_hidden(
                //     menu_evt->sender_id,
                //     MENU_CONN_BT_SET_SIMAP,
                //     MMI_TRUE);
                cui_menu_set_item_disabled(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_SIMAP,
                    MMI_TRUE);
            }
        #ifdef __MMI_TELEPHONY_SUPPORT__
            else if (srv_sim_ctrl_any_sim_is_available() || mmi_bt_is_simap_activate())
            {
                MMI_TRACE(
                    MMI_CONN_TRC_G7_BT,
                    MMI_BT_SET_MENU_GROUP_PROC_1,
                    g_mmi_bt_scr_cntx.flag);
                // cui_menu_set_item_hidden(
                //     menu_evt->sender_id,
                //     MENU_CONN_BT_SET_SIMAP,
                //     MMI_FALSE);
                cui_menu_set_item_disabled(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_SIMAP,
                    MMI_FALSE);
                if (mmi_bt_is_simap_activate())
                {
                    cui_menu_set_item_hint(
                        menu_evt->sender_id,
                        MENU_CONN_BT_SET_SIMAP,
                        (WCHAR*)GetString(STR_GLOBAL_ON));
                }
                else
                {
                    cui_menu_set_item_hint(
                        menu_evt->sender_id,
                        MENU_CONN_BT_SET_SIMAP,
                        (WCHAR*)GetString(STR_GLOBAL_OFF));
                }
            }
        #endif /* __MMI_TELEPHONY_SUPPORT__ */
            else
            {
                MMI_TRACE(
                    MMI_CONN_TRC_G7_BT,
                    MMI_BT_SET_MENU_GROUP_PROC_2,
                    g_mmi_bt_scr_cntx.flag);
                // cui_menu_set_item_hidden(
                //     menu_evt->sender_id,
                //     MENU_CONN_BT_SET_SIMAP,
                //     MMI_TRUE);
                cui_menu_set_item_disabled(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_SIMAP,
                    MMI_TRUE);
            }
#endif /*defined(__MMI_SIMAP_SUPPORT__)*/

#if defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
            if (mmi_bt_storage_available())
            {
                cui_menu_set_item_hidden(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_STORAGE,
                    MMI_FALSE);
                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_STORAGE,
                    mmi_bt_get_storage_setting_string());

            }
            else
            {
                cui_menu_set_item_hidden(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_STORAGE,
                    MMI_TRUE);
            }
#endif  // defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)

            {
                srv_bt_cm_dev_struct *dev_p;
                dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_host_dev_info();

                mmi_bt_get_display_bt_address(
                    g_mmi_bt_scr_cntx.ui_buf,
                    &(dev_p->bd_addr));

                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_CONN_BT_SET_DEV_ADDR,
                    (WCHAR*)g_mmi_bt_scr_cntx.ui_buf);
            }

            cui_menu_set_currlist_flags(
                menu_evt->sender_id,
                CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
#ifndef _MMI_BT_ULTRA_SLIM_
                case MENU_CONN_BT_SET_AUDIO_PATH:
                    mmi_bt_entry_set_audio_pth_menu();
                    break;
#endif 

#if defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
                case MENU_CONN_BT_SET_STORAGE:
                    mmi_bt_entry_storage_setting(menu_evt->sender_id);
                    break;
#endif  // defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)

#if defined(__MMI_FTS_SUPPORT__)
                case MENU_CONN_BT_SET_PERMISSION:
                    mmi_bt_entry_permission_setting(menu_evt->sender_id);
                    break;
#elif defined (__BIP_PULL_SUPPORT__)
                case MENU_CONN_BT_SET_IMAGE_FOLDER:
                    mmi_bt_entry_set_menu();
                    break;
#endif

#if defined(__MMI_HIDD_SUPPORT__)
                case MENU_CONN_BT_REMOTE_CONTROL:
                    mmi_bt_entry_remote_control();
                    break;
#endif

#ifdef __MMI_SIMAP_SUPPORT__
                case MENU_CONN_BT_SET_SIMAP:
                    mmi_bt_entry_set_simap();
                    break;
#endif

                default:
                    break;
            }
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_CONN_BT_SET_AUDIO_PATH:
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        (WCHAR*)GetString(STR_GLOBAL_OK));
                    break;

#if defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
                case MENU_CONN_BT_SET_STORAGE:
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        (WCHAR*)GetString(STR_GLOBAL_OK));
                    break;
#endif  // defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)

#if defined(__MMI_FTS_SUPPORT__)
                case MENU_CONN_BT_SET_PERMISSION:
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        (WCHAR*)GetString(STR_GLOBAL_OK));
                    break;
#elif defined (__BIP_PULL_SUPPORT__)
                case MENU_CONN_BT_SET_IMAGE_FOLDER:
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        (WCHAR*)GetString(STR_GLOBAL_OK));
                    break;
#endif

#if defined(__MMI_HIDD_SUPPORT__)
                case MENU_CONN_BT_REMOTE_CONTROL:
                {
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        (WCHAR*)GetString(STR_GLOBAL_OK));
                }
                break;
#endif

#ifdef __MMI_SIMAP_SUPPORT__
                case MENU_CONN_BT_SET_SIMAP:
                    if (mmi_bt_is_simap_activate())
                    {
                        cui_menu_change_left_softkey_string(
                            menu_evt->sender_id,
                            (WCHAR*)GetString(STR_GLOBAL_OFF));
                    }
                    else
                    {
                        cui_menu_change_left_softkey_string(
                            menu_evt->sender_id,
                            (WCHAR*)GetString(STR_GLOBAL_ON));
                    }
                    break;
#endif  // __MMI_SIMAP_SUPPORT__

                case MENU_CONN_BT_SET_DEV_ADDR:
                {
                    cui_menu_change_left_softkey_string(
                        menu_evt->sender_id,
                        NULL);
                    cui_menu_change_center_softkey_content(
                        menu_evt->sender_id,
                        (WCHAR*)NULL,
                        (UI_image_type)NULL);
                }
                break;

                default:
                    break;
            }
        }
        break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_audio_pth_menu
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->Setting->Path
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_entry_set_audio_pth_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_SET_AUDIO_PTH_MENU);

    cui_menu_create_and_run(
        g_mmi_bt_scr_cntx.main_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_CONN_BT_SET_AUDIO_PATH,
        MMI_FALSE,
        (void*)MENU_CONN_BT_SET_AUDIO_PATH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_audio_pth_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bt_entry_set_audio_pth_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_menu_id highlight_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(
                menu_evt->sender_id,
                CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
            {
                if (srv_bt_cm_is_audio_path_to_headset())
                {
                    highlight_item = MENU_CONN_BT_SET_AUDIO_PATH_HF;
                }
                else
                {
                    highlight_item = MENU_CONN_BT_SET_AUDIO_PATH_PHONE;
                }

                cui_menu_set_radio_list_item(menu_evt->sender_id, highlight_item);
            }
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_bt_set_audio_pth_select(menu_evt->highlighted_menu_id);
            cui_menu_close(menu_evt->sender_id);
        }
        break;

        // case EVT_ID_CUI_MENU_ITEM_HILITE:
        // {
        //     switch (menu_evt->highlighted_menu_id)
        //     {
        //         case MENU_CONN_BT_SET_AUDIO_PATH_PHONE:
        //             MMI_BT_SET_HILIGHT_ITEM(0);
        //             break;
        //         case MENU_CONN_BT_SET_AUDIO_PATH_HF:
        //             MMI_BT_SET_HILIGHT_ITEM(1);
        //             break;
        //         default:
        //             break;
        //     }
        // }
        // break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_audio_pth_select
 * DESCRIPTION
 *  This function is to set the audio path
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_set_audio_pth_select(mmi_menu_id highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mode;
#if defined (__MMI_HFP_SUPPORT__) && defined (__MMI_A2DP_HIDE_BT_SETTINGS__)
    MMI_BOOL on_off;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_AUDIO_PTH_PROC);
#ifdef __MMI_HFP_SUPPORT__
    if (highlighted_menu_id == MENU_CONN_BT_SET_AUDIO_PATH_PHONE)
    {
        mode = BTHF_AUD_LOCAL;
#ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
        on_off = MMI_FALSE;
#endif
    }
    else
    {
        mode = BTHF_AUD_REMOTE;
#ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
        on_off = MMI_TRUE;
#endif
    }

    srv_bthf_save_config(BTHF_CFG_AUDIO_PATH, &mode);
#ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
    mmi_a2dp_bt_output_change_callback(on_off);
#endif

#if defined(__MMI_BT_AUDIO_SUPPORT__)
    if (srv_bthf_get_status() > BTHF_STATUS_DETACH)
    {
        if (mode == BTHF_AUD_LOCAL)
        {
            srv_btsco_close_stream_req();
        }
        else
        {
            //srv_btsco_open_stream_req();
            srv_btsco_switch_profile_path(MMI_TRUE);
        }
    }
#endif
#endif /* __MMI_HFP_SUPPORT__ */

    //mmi_bt_popup_display(GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, g_mmi_bt_scr_cntx.main_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_audio_pth
 * DESCRIPTION
 *  This function is to set the audio path
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static WCHAR* mmi_bt_get_audio_pth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    {
        U32* mode;
        
        mode = srv_bthf_read_config(BTHF_CFG_AUDIO_PATH);
        if (*mode == BTHF_AUD_REMOTE)
        {
            result = MMI_TRUE;
        }
    }
#endif /* __MMI_HFP_SUPPORT__ */

    return (WCHAR*)GetString(
        result ?
        STR_BT_DEV_SET_AUDIO_PATH_HF :
        STR_BT_DEV_SET_AUDIO_PATH_PHONE);
}

#endif 
#ifdef __MMI_SIMAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_set_simap
 * DESCRIPTION
 *  This function is to entry Settings -> SIMAP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_set_simap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_SET_SIMAP);

    if (!mmi_bt_is_simap_activate())
    {
        if (mmi_bt_simap_activate())
        {
            // if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET)
            // {
            //     MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SIMAP_SET);
            // }
            // else
            {
                mmi_bt_show_progress_scr(
                    g_mmi_bt_scr_cntx.main_gid,
                    SCR_BT_SET_SIMAP,
                    STR_BT_DEV_SET_SIMAP,
                    STR_GLOBAL_PLEASE_WAIT,
                    NULL);
            }
        }
        else
        {
            mmi_bt_popup_display(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                g_mmi_bt_scr_cntx.main_gid);
        }
    }
    else
    {
        // if (srv_bt_cm_is_profile_connected(SRV_BT_CM_SIMAP_CONNECTION))
        // {
        // #ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
        //     mmi_bt_entry_deactivate_simap_confirm();
        // #else
        //     mmi_bt_popup_display(STR_BT_DISCONN_ALL_CONN, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.main_gid);
        // #endif
        // }
        // else
        {
            mmi_bt_simap_deactivate();
            mmi_bt_show_progress_scr(
                g_mmi_bt_scr_cntx.main_gid,
                SCR_BT_SET_SIMAP,
                STR_BT_DEV_SET_SIMAP,
                STR_GLOBAL_PLEASE_WAIT,
                NULL);
        }
    }
}


#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
mmi_ret mmi_bt_sim_hot_swap_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *event = (srv_sim_ctrl_event_detected_evt_struct *)para;
    U16 i;
    srv_bt_cm_connect_struct *conn_info = NULL;
    srv_bt_cm_dev_struct *sap_dev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_SIM_HOT_SWAP_HDLR,
        event->type,
        g_mmi_bt_scr_cntx.flag,
        g_mmi_bt_scr_cntx.advance_menu_gid,
        mmi_frm_group_get_active_id());

    mmi_bt_simap_hotswap_handlr((U8)event->sim);

    if (event->type == SRV_SIM_CTRL_EVENT_DET_REMOVED ||
        event->type == SRV_SIM_CTRL_EVENT_DET_RECOVERY_START)
    {
        if (g_mmi_bt_scr_cntx.advance_menu_gid > 0)
        {
            if (g_mmi_bt_scr_cntx.advance_menu_gid == mmi_frm_group_get_active_id())
            {
            #ifdef __MMI_TELEPHONY_SUPPORT__
                if (!srv_sim_ctrl_any_sim_is_available() && !mmi_bt_is_simap_activate()) {
                    cui_menu_set_item_disabled(
                        g_mmi_bt_scr_cntx.advance_menu_gid,
                        MENU_CONN_BT_SET_SIMAP,
                        MMI_TRUE);
                }
            #endif /* __MMI_TELEPHONY_SUPPORT__ */
            }
        }
            {
                MMI_ID sid = mmi_frm_scrn_get_active_id();
                if (sid == SCR_BT_MYDEV_SIM_CNF ||
                    sid == SCR_BT_MYDEV_SIM_SEL)
                    mmi_frm_scrn_close_active_id();
            }
    }
    else if (event->type == SRV_SIM_CTRL_EVENT_DET_INSERTED ||
             event->type == SRV_SIM_CTRL_EVENT_DET_RECOVERY_END)
    {
        if (g_mmi_bt_scr_cntx.advance_menu_gid > 0)
        {
            if (g_mmi_bt_scr_cntx.advance_menu_gid == mmi_frm_group_get_active_id())
            {
                if (!mmi_bt_is_simap_activate())
                {
                    cui_menu_set_item_disabled(
                        g_mmi_bt_scr_cntx.advance_menu_gid,
                        MENU_CONN_BT_SET_SIMAP,
                        MMI_FALSE);
                }
            }
        }
            {
                MMI_ID sid = mmi_frm_scrn_get_active_id();
                if (sid == SCR_BT_MYDEV_SIM_CNF ||
                    sid == SCR_BT_MYDEV_SIM_SEL)
                    mmi_frm_scrn_close_active_id();
            }
    }

    return MMI_RET_OK;
}
#endif

mmi_ret mmi_bt_sim_event_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (para->evt_id)
    {
        case EVT_ID_SRV_SIM_CTRL_AVAILABLE:
        {
            srv_sim_ctrl_available_evt_struct* msg = (srv_sim_ctrl_available_evt_struct*)para;
			#if !defined( _MMI_BT_ULTRA_SLIM_) || defined(__MMI_BT_APPLICATION_BQB__)
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_BT_SIM_EVENT_HDLR,
                msg->sim,
                g_mmi_bt_scr_cntx.advance_menu_gid,
                mmi_frm_group_get_active_id());

            if (g_mmi_bt_scr_cntx.advance_menu_gid == mmi_frm_group_get_active_id())
            {
                cui_menu_refresh_currlist(g_mmi_bt_scr_cntx.advance_menu_gid);
            }
			#endif
        }
        break;

        case EVT_ID_SRV_SIM_CTRL_UNAVAILABLE:
        {
            srv_sim_ctrl_unavailable_evt_struct* msg = (srv_sim_ctrl_unavailable_evt_struct*)para;
			#if !defined( _MMI_BT_ULTRA_SLIM_) || defined(__MMI_BT_APPLICATION_BQB__)
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_BT_SIM_EVENT_HDLR,
                msg->sim,
                g_mmi_bt_scr_cntx.advance_menu_gid,
                mmi_frm_group_get_active_id());

            if (g_mmi_bt_scr_cntx.advance_menu_gid == mmi_frm_group_get_active_id())
            {
                cui_menu_refresh_currlist(g_mmi_bt_scr_cntx.advance_menu_gid);
            }
			#endif
        }
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_set_simap_complete
 * DESCRIPTION
 *  This function is to notify if setting simap successfully or not
 * PARAMETERS
 *  result      [IN]            result of setting SIMAP
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_set_simap_complete(srv_bt_cm_set_simap_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_bt_cm_set_simap_struct *event = (srv_bt_cm_set_simap_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_SIMAP_COMPLETE, para->result);
    // if (para->result)
    // {
    //     if (mmi_frm_scrn_get_active_id() == SCR_BT_SET_SIMAP)
    //     {
    //         mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR *)GetString(STR_GLOBAL_DONE));
    //     }
    // }

    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.main_gid, SCR_BT_SET_SIMAP);
}
#endif  // __MMI_SIMAP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_display_connect_confirm
 * DESCRIPTION
 *  This function is display power on confirm screen
 * PARAMETERS
 *  flag         [IN]            screen flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_display_connect_confirm(mmi_id group_id, MMI_BOOL supported_hf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_DISPLAY_CONFIRM_SCR, g_mmi_bt_scr_cntx.flag);

    mmi_frm_scrn_first_enter(
        group_id,
        SCR_BT_CONNECT_CNF,
        (FuncPtr) mmi_bt_entry_connect_confirm,
        (void *)supported_hf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connect_confirm
 * DESCRIPTION
 *  This function is to entry connection profile connection confirm screen
 * PARAMETERS
 *  NULL         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_connect_confirm(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string = 0;
    MMI_BOOL supported_hf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_CONNECT_PROFILE_CONNECTION_CONFIRM);

	if(info->user_data)
		supported_hf=MMI_TRUE;
	else
		supported_hf=MMI_FALSE;

    if (mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            (FuncPtr) NULL,
            (FuncPtr) mmi_bt_entry_connect_confirm,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

#ifdef __MMI_BT_AUTHORIZE__
    if (supported_hf)
    {
        string = STR_BT_CONNECT_AND_SET_AS_DEFAULT_HF;
    }
    else
    {
        string = STR_BT_SET_AS_DEFAULT_HF;
    }
#else
    string = STR_BT_CONNECT_CONFIRM;
#endif  // __MMI_BT_AUTHORIZE__

#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_96X64__) ||defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)
    ShowCategory66Screen(
        STR_GLOBAL_BLUETOOTH,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*)GetString(string),
        NULL,
        NULL);
#else
    ShowCategory66Screen(
        STR_GLOBAL_BLUETOOTH,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*)GetString(string),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);
#endif
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 

    if (supported_hf)
    {
        SetLeftSoftkeyFunction(mmi_bt_connect_confirm_lsk, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_bt_connect_confirm_lsk, KEY_EVENT_UP);
    }
#ifdef __MMI_BT_AUTHORIZE__
    else
    {
        SetLeftSoftkeyFunction(mmi_bt_set_as_always_connect_hf, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_bt_set_as_always_connect_hf, KEY_EVENT_UP);
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_confirm_lsk
 * DESCRIPTION
 *  This function is to handle entry connecting process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_confirm_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_get_active_id();

#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_set_authorize(&(g_mmi_bt_scr_cntx.conn_dev_add), SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT) == SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_bt_entry_connecting(group_id);
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
#else
    mmi_bt_entry_connecting(group_id);
#endif  // MMI_BT_AUTHORIZE_

    mmi_frm_scrn_close(group_id, SCR_BT_CONNECT_CNF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_connecting
 * DESCRIPTION
 *  This function is to handle entry connecting process
 * PARAMETERS
 *  group_id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_connecting(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_CONNECTING);

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_RELEASE_AUDIO_DEV_BEFORE_CONNECT)
    {
        MMI_BT_RESET_FLAG(MMI_BT_RELEASE_AUDIO_DEV_BEFORE_CONNECT);
    }


    if (group_id == GRP_ID_INVALID)
    {
        return;
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_CONNECT_AUDIO);
        mmi_bt_display_power_on_confirm(group_id);
        return;
    }


#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_get_authorize(&(g_mmi_bt_scr_cntx.conn_dev_add)) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
    {
        mmi_bt_popup_prohibited_by_blocked_device();
        return;
    }
#endif /* __MMI_BT_AUTHORIZE__ */
#ifdef __MMI_BT_DIALER_SUPPORT__
#ifdef __MMI_HFP_SUPPORT__
    mmi_bt_connecting(&(g_mmi_bt_scr_cntx.conn_dev_add), group_id);
#else
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_A2DP_SRC_FUNC);
#ifdef __MMI_A2DP_SUPPORT__
#ifdef __MMI_BT_SPEAKER_SUPPORT__

    mmi_bt_dialer_connect_a2dp_src(&(g_mmi_bt_scr_cntx.conn_dev_add), group_id);
#endif /*__MMI_A2DP_SUPPORT__*/
#endif/*__MMI_BT_SPEAKER_SUPPORT__*/
#endif/*__MMI_HF_SUPPORT__*/
#else
    mmi_bt_connecting(&(g_mmi_bt_scr_cntx.conn_dev_add), group_id);

#endif/*__MMI_BT_DIALER_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_conn
 * DESCRIPTION
 *  This function is to entry My device connection screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
static void mmi_bt_entry_mydev_conn_ftp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_ENTRY_MYDEV_CONN_FTP);

    mmi_bt_ftpc_connect_server(g_mmi_bt_scr_cntx.conn_dev_add);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connecting
 * DESCRIPTION
 *  This function is to handle the connecting process
 * PARAMETERS
 *  dev_addr        [IN]             device address
 *  pro_uuid        [IN]            profile UUID
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connecting(srv_bt_cm_bt_addr *dev_addr, mmi_id group_id)
{
    btaud_device_info devInfo;
    MMI_BOOL result = MMI_TRUE;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_CONNECTING);
#ifdef __MMI_BT_AUDIO_SUPPORT__
    result = srv_btaud_get_active_device(BTAUD_CHNL_ANY, &devInfo);
#endif

    if (!result || srv_bt_cm_is_dev_addr_equal((srv_bt_cm_bt_addr*)&devInfo.addr, dev_addr))
    {
#ifdef __MMI_HFP_SUPPORT__
        mmi_btaud_attach(group_id, dev_addr);
#endif  // __MMI_HFP_SUPPORT__
    }
    else
    {
        //MMI_BT_SET_FLAG(MMI_BT_RELEASE_AUDIO_DEV_BEFORE_CONNECT);
        mmi_bt_display_release_connection_confirm(group_id, MMI_BT_RELEASE_AUDIO_CONNECITON);
    }
}

static void mmi_bt_sco_ind_l4_module(MMI_BOOL result)
{
	if (g_mmi_bt_scr_cntx.test_by_at)
    {
        mmi_at_general_res_req_struct *res_p;

        res_p = construct_local_para(sizeof(mmi_at_general_res_req_struct), TD_UL);
        res_p->result = result;
        mmi_frm_send_ilm(MOD_L4C,MSG_ID_MMI_AT_GENERAL_RES_REQ,(oslParaType *)res_p,NULL);
        g_mmi_bt_scr_cntx.test_by_at = 0;
    }
    else
    {
        if (g_mmi_bt_scr_cntx.test_by_em)
        {
            /* call back engineering... */
        #ifdef __MMI_ENGINEER_MODE__
            EmBTNotifyLoopbackDoneCnf(result);
        #endif
            g_mmi_bt_scr_cntx.test_by_em = 0;
        }
    }

    srv_bt_cm_dev_remove(&(g_mmi_bt_scr_cntx.far_end_dev_add));

}

static void mmi_bt_update_connect_ind()
{
    mmi_bt_update_status_icon();
    if (g_mmi_bt_scr_cntx.mydev_opt_menu_gid > 0)
    {
        if (mmi_frm_group_get_active_id() == g_mmi_bt_scr_cntx.mydev_opt_menu_gid)
        {
            cui_menu_close(g_mmi_bt_scr_cntx.mydev_opt_menu_gid);
            g_mmi_bt_scr_cntx.mydev_opt_menu_gid = 0;
        }
    }

    if (mmi_frm_scrn_get_active_id() == SCR_BT_MYDEV)
    {
        mmi_bt_refresh_screen();
    }

}

/*
*
* IN ORDER TO SLIM BT CODE 
*/
static void mmi_bt_sco_ind_ext(void *para, int mode)
{
		srv_bt_cm_sco_ind_struct *event = (srv_bt_cm_sco_ind_struct *)para;
		srv_bt_cm_conn_res_struct *event_conn = (srv_bt_cm_conn_res_struct *)para;

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        if (mode==MMI_BT_SCO_IND && event->result)
        {
            StartTimer(BT_LP2_DELAY_TIMER, MMI_BT_BT_LP2_DELAY_TIMER_DUR, mmi_bt_loopback_delay_timeout_hdler);
        }
		else if(mode== MMI_BT_CONNECT_IND && event_conn->result == SRV_BT_CM_BTBM_SUCCESS)  /* for sco indication part*/
		{    mmi_bt_hfp_sco_link_connect_req();
        }
        else
        {
                /* indicate L4 AT module succeeded or failed */
			mmi_bt_sco_ind_l4_module(MMI_FALSE);
            if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
            {
				srv_bt_cm_switch_off();
            }
			else if(mode == MMI_BT_SCO_FAR_LP_TESTING) 
            {
				MMI_BT_RESET_FLAG(MMI_BT_SCO_FAR_END_LP_TESTING);
                }
            }

        return;
    }
	if(mode==MMI_BT_SCO_IND)
		mmi_bt_stop_progress_scr(GRP_ID_BT_CM_PROGRESS, SCR_BT_SWITCH_SPEECH_PATH);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_connect_complete
 * DESCRIPTION
 *  This function is to handle connection process complete
 * PARAMETERS
 *  connection_type     [IN]            connection type
 *  result              [IN]            the result of connection
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_connect_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_BT_DIALER_SUPPORT__
		srv_bt_cm_conn_res_struct *event_conn = (srv_bt_cm_conn_res_struct *)para;
   
    kal_prompt_trace(MOD_MMI_CONN_APP,"[btconn]mmi_bt_connect_complete ");
 
    if (event_conn->profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
    {
    #ifdef __MMI_A2DP_SUPPORT__
        kal_prompt_trace(MOD_MMI_CONN_APP,"[btconn]SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID event_conn->profile_id = %d", event_conn->profile_id);

        if(srv_a2dp_get_role(event_conn->dev_addr) == BT_A2DP_SOURCE)
        {
            mmi_bt_dialer_set_headset_flag(MMI_TRUE);
            kal_prompt_trace(MOD_MMI_CONN_APP,"[btconn]srv_a2dp_get_role(event_conn->dev_addr) == BT_A2DP_SOURCE");
        }
    #endif
    }


	#ifdef __MMI_BT_DIALER_AUTO_RECONN_SUPPORT__	
		mmi_bt_dialer_auto_reconn_reset();
	#endif/*__MMI_BT_DIALER_AUTO_RECONN_SUPPORT__*/

	srv_bt_cm_set_dev_link_state(event_conn->dev_addr,MMI_TRUE);
#endif/*__MMI_BT_DIALER_SUPPORT__*/
    mmi_bt_update_connect_ind();
    mmi_bt_sco_ind_ext(para,MMI_BT_CONNECT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_disconnect_complete
 * DESCRIPTION
 *  This function is to handle disconnect complete
 * PARAMETERS
 *  connection_type     [IN]            connection type
 *  result              [IN]            disconnect result
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_disconnect_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U32 i;
    //srv_bt_cm_dev_struct *dev_info = NULL;
#ifdef __MMI_BT_DIALER_SUPPORT__
    WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
#endif
    srv_bt_cm_disconnect_ind_struct *event = (srv_bt_cm_disconnect_ind_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_SCR_PROF_DISCON_IND,
        event->profile_id,
        mmi_frm_group_get_active_id(),
        g_mmi_bt_scr_cntx.mydev_gid,
        g_mmi_bt_scr_cntx.mydev_gid);

    mmi_bt_update_connect_ind();

    if (event->profile_id == SRV_BT_CM_HFG_PROFILE_UUID)
    {
        mmi_bt_stop_progress_scr(GRP_ID_BT_CM_PROGRESS, SCR_BT_SWITCH_SPEECH_PATH);
    }
#ifdef __MMI_SIMAP_SUPPORT__
#if !defined( _MMI_BT_ULTRA_SLIM_) || defined(__MMI_BT_APPLICATION_BQB__)

    if ((event->profile_id == SRV_BT_CM_SIM_ACCESS_PROFILE_UUID) &&
    #ifdef __MMI_TELEPHONY_SUPPORT__
        !srv_sim_ctrl_any_sim_is_available() &&
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
        (g_mmi_bt_scr_cntx.advance_menu_gid == mmi_frm_group_get_active_id()))
    {
        cui_menu_refresh_currlist(g_mmi_bt_scr_cntx.advance_menu_gid);
    }
#endif
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
    if(!mmi_bt_dialer_app_is_connected_ex(event->dev_addr) && !g_bt_headset_conn_reject)
    {
        if (mmi_bt_dialer_get_headset_flag())
        {
            srv_bt_cm_dev_struct* dev_p ;
            mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_BT_DIALER_DISCONNECT_ASK);
            
            dev_p = (srv_bt_cm_dev_struct*)srv_bt_cm_get_dev_info_by_addr(event->dev_addr, SRV_BT_CM_ALL_DEV);
        #ifndef __MMI_BT_BTBOX_NOLCD__
        #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
            mmi_bt_anti_lost_close_scr(&dev_p->bd_addr);
            mmi_bt_anti_lost_clean_addr(&dev_p->bd_addr);//clean the device in anti-lost list.
        #endif/*__MMI_BT_ANTI_LOST_BY_RSSI__*/
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*)string,
                (SRV_BT_CM_BD_UCS2_NAME_LEN * 2),
                (kal_uint8*)dev_p->name);
            mmi_wcscat((WCHAR*)string, (WCHAR*)GetString(STR_BT_DISCONN_POP));
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_FAILURE,
                (WCHAR*)string);
        #endif /* __MMI_BT_BTBOX_NOLCD__ */

            mmi_bt_dialer_app_emit_event(EVT_ID_DIALER_DISCONN_EVENT_ID, (void*)dev_p, MMI_FALSE);
            mmi_bt_dialer_set_headset_flag(MMI_FALSE);
            if (event->profile_id == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
            {
                srv_bt_cm_set_dev_busy_state(&dev_p->bd_addr, SRV_BT_CM_A2DP_CONNECTION, MMI_FALSE);
            }
            srv_bt_cm_set_dev_link_state(&dev_p->bd_addr,MMI_FALSE);
        }
    }
    if(g_bt_headset_conn_reject)
    {
        g_bt_headset_conn_reject = MMI_FALSE;
    }
#endif/*__MMI_BT_DIALER_SUPPORT__*/
}


#if MMI_MAX_SIM_NUM > 1 
/*****************************************************************************
 * FUNCTION
 *  mydev_sim_hilight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index     [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mydev_sim_hilight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sid = mmi_frm_scrn_get_active_id();
    MMI_ID gid = g_mmi_bt_scr_cntx.mydev_gid;
    mmi_bt_sim_list *list = (mmi_bt_sim_list *)mmi_frm_scrn_get_user_data(gid, sid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list->selected = (S16)index;
}


/*****************************************************************************
 * FUNCTION
 *  mydev_sim_sel_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mydev_sim_sel_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sid = mmi_frm_scrn_get_active_id();
    MMI_ID gid = g_mmi_bt_scr_cntx.mydev_gid;
    mmi_bt_sim_list *list = (mmi_bt_sim_list *)mmi_frm_scrn_get_user_data(gid, sid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_set_prefer_sim(list->device, list->info[list->selected].id);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mydev_enter_sim_sel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info            [IN]       
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mydev_enter_sim_sel(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buff;
    S32 i;
    mmi_bt_sim_list *list = (mmi_bt_sim_list *)info->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)mydev_enter_sim_sel,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_RET_ERR;
    }

    gui_buff = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mydev_sim_hilight_hdlr);

    for (i = 0; i < list->count; i++)
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        WCHAR *name = mmi_netset_get_sim_name(list->info[i].id);
        if (name && mmi_wcslen(name) > 0)
            mmi_wsprintf_ex((WCHAR *)subMenuData[i], sizeof(subMenuData[i]), 
                L"%S(%w)", list->info[i].text, name);
        else
#endif            
            mmi_wcscpy((WCHAR *)subMenuData[i], (WCHAR *)GetString(list->info[i].text));
        subMenuDataPtrs[i] = subMenuData[i];
    }

    ShowCategory36Screen(
        STR_BT_MYDEV_OPT_SIM,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        list->count,
        subMenuDataPtrs,
        list->selected,
        gui_buff);

    SetLeftSoftkeyFunction(mydev_sim_sel_lsk_hdlr, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mydev_sim_sel_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mydev_sim_list_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mydev_sim_list_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sid = mmi_frm_scrn_get_active_id();
    MMI_ID gid = g_mmi_bt_scr_cntx.mydev_gid;
    mmi_bt_sim_list *list = (mmi_bt_sim_list *)mmi_frm_scrn_get_user_data(gid, sid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list->selected = 0;
    mmi_frm_scrn_first_enter(gid, SCR_BT_MYDEV_SIM_SEL,
        (FuncPtr)mydev_enter_sim_sel, list);

    mmi_frm_scrn_close(gid, sid);
}


/*****************************************************************************
 * FUNCTION
 *  mydev_enter_sim_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info 
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
static MMI_RET mydev_enter_sim_cnf(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)mydev_enter_sim_cnf,
            MMI_FRM_FULL_SCRN))
    {
        return MMI_RET_ERR;
    }

    ShowCategory66Screen(
        STR_BT_MYDEV_OPT_SIM,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*)GetString(STR_BT_SIM_QUERY),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        NULL);

    SetLeftSoftkeyFunction(mydev_sim_list_lsk_hdlr, KEY_EVENT_UP);
	#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	#endif 
    SetCenterSoftkeyFunction(mydev_sim_list_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mydev_init_sim_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addr 
 * RETURNS
 *  mmi_bt_sim_list*
 *****************************************************************************/
static mmi_bt_sim_list *mydev_init_sim_list(srv_bt_cm_bt_addr *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_bt_sim_list *list = &g_mmi_bt_scr_cntx.sim_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list->device = addr;
    list->count = 0;
    list->selected = -1;

    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        if (srv_sim_ctrl_is_available(MMI_SIM1 << i))
        {
            list->info[list->count].id = MMI_SIM1 << i;
            /* string ID for SIMs not continous, here is trick solution */
            if (i < 2)
                list->info[list->count].text = STR_GLOBAL_SIM_1+i;
            else
                list->info[list->count].text = STR_GLOBAL_SIM_3+i-2;
            if (list->selected < 0 && 
                srv_bt_cm_get_prefer_sim(addr) == list->info[list->count].id)
                list->selected = (S16)list->count;
            list->count++;
        }
    }

    return list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_show_sim_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addr 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_show_sim_setting(srv_bt_cm_bt_addr *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_sim_list *list = mydev_init_sim_list(addr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->selected < 0)
    {
        mmi_frm_scrn_first_enter(
            g_mmi_bt_scr_cntx.mydev_gid,
            SCR_BT_MYDEV_SIM_CNF, 
            (FuncPtr)mydev_enter_sim_cnf, list);
    }
    else
    {
        mmi_frm_scrn_first_enter(
            g_mmi_bt_scr_cntx.mydev_gid,
            SCR_BT_MYDEV_SIM_SEL,
            (FuncPtr)mydev_enter_sim_sel, list);
    }
}
#endif


#if !defined(__MMI_BT_SLIM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_service_list
 * DESCRIPTION
 *  This function is to entry My device -> Support Service
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_service_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_SUP_SER);

    g_mmi_bt_scr_cntx.srv_list_menu_gid = cui_menu_create(
        g_mmi_bt_scr_cntx.mydev_gid,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_APPSUB,
        SCR_BT_MYDEV_SUP_PROFILE,
        MMI_FALSE,
        (void*)SCR_BT_MYDEV_SUP_PROFILE);

    cui_menu_set_default_left_softkey(
        g_mmi_bt_scr_cntx.srv_list_menu_gid,
        (WCHAR*)GetString(STR_GLOBAL_REFRESH));

    cui_menu_run(g_mmi_bt_scr_cntx.srv_list_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_servic_list_group_proc
 * DESCRIPTION
 *  This function is the screen group proc function of my device option menu
 *  It is responsible for handling the event of screen group.
 * PARAMETERS
 *  evt         [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_entry_mydev_servic_list_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    U8 *ItemList[SRV_BT_CM_NUM_OF_PROFILE_UUID];
    srv_bt_cm_dev_struct * dev_p;
    S32 nItems = 0;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == SCR_BT_MYDEV_SUP_PROFILE)
            {
                mmi_menu_id root_ids[SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE];

                nItems = 0;

                dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);

                if (dev_p->service_list_num == 0)
                {
                    root_ids[nItems] = nItems;
                    nItems++;
                }
                else
                {
                    for (i = 0; i < dev_p->service_list_num; i++)
                    {
                        mmi_bt_get_profile_str_id((U16) dev_p->service_list[i], &(ItemList[nItems]));
                        root_ids[nItems] = nItems;
                        nItems++;
                    }
                }

                cui_menu_set_currlist(menu_evt->sender_id, nItems, root_ids);

                if (dev_p->service_list_num == 0)
                {
                    cui_menu_set_item_string(
                        menu_evt->sender_id,
                        0,
                        (WCHAR*)GetString(STR_BT_NO_SUPPORTED_PROFILE));
                }
                else
                {
                    for (i = 0; i < dev_p->service_list_num; i++)
                    {
                        cui_menu_set_item_string(
                            menu_evt->sender_id,
                            i,
                            (WCHAR*)ItemList[i]);
                    }
                }
                cui_menu_set_currlist_flags(
                        menu_evt->sender_id,
                        CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS);

                cui_menu_set_default_title(
                    menu_evt->sender_id,
                    (WCHAR*)GetString(STR_BT_MYDEV_OPT_SUP_SER),
                    get_image(GetRootTitleIcon(MENU_CONN_BT_MAIN)));
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_bt_mydev_refresh_service();
            cui_menu_close(menu_evt->sender_id);
            g_mmi_bt_scr_cntx.srv_list_menu_gid = 0;
        }
        break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_refresh_service
 * DESCRIPTION
 *  This function is to refresh profile list in support service screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_refresh_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SUP_SER_REFRESH_PROF_LIST);

    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_refresh_service_list(&(g_mmi_bt_scr_cntx.conn_dev_add)))
    {
        mmi_bt_show_progress_scr(
            g_mmi_bt_scr_cntx.mydev_gid,
            SCR_BT_REFREAH_PROFILE,
            STR_BT_REFRESHING,
            STR_BT_REFRESHING,
            NULL);
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }

    mmi_frm_scrn_close(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_MYDEV_SUP_PROFILE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_refresh_prof_complete
 * DESCRIPTION
 *  This function is to handle complete of refresh profile screen
 * PARAMETERS
 *  result      [IN]            the result of refresh profile
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_refresh_prof_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_refresh_service_list_struct *event = (srv_bt_cm_refresh_service_list_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_REFRESH_PROF_COMPLETE, event->result);
    switch (event->result)
    {
        case BTBM_ADP_SUCCESS:
        case BTBM_ADP_FAILED:
            if (mmi_frm_scrn_is_present(
                    g_mmi_bt_scr_cntx.mydev_gid,
                    SCR_BT_REFREAH_PROFILE,
                    MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_bt_entry_mydev_service_list();
            }
            break;

        case BTBM_ADP_FAIL_BUSY:
        case BTBM_ADP_FAIL_NOT_ALLOW:
        default:
            mmi_frm_nmgr_popup(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_FAILURE,
                (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
            break;
    }

    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_REFREAH_PROFILE);
}
#endif  // !defined(__MMI_BT_SLIM__)


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_set_default_hs
 * DESCRIPTION
 *  This function is to entry My device set default headset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_set_default_hs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_SET_DEFAULT_HS);

    dev = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);

#ifdef __MMI_HFP_SUPPORT__
    if (srv_bthf_save_config(BTHF_CFG_DEF_DEVICE, &dev->bd_addr) == BTHF_RESULT_SUCC)
    {
        //mmi_bt_popup_display(GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, g_mmi_bt_scr_cntx.mydev_gid);
    }
    else
#endif  /* __MMI_HFP_SUPPORT__ */
    {
        mmi_bt_popup_display(STR_GLOBAL_DONE, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.mydev_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_ren
 * DESCRIPTION
 *  This function is to entry My device rename
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_ren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SCR_REN);

            dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);
	mmi_bt_entry_set_name_ext(g_mmi_bt_scr_cntx.mydev_gid,dev_p,STR_GLOBAL_RENAME,SCR_BT_MYDEV_REN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_ren_proc
 * DESCRIPTION
 *  This function is to do the rename process
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_ren_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev_p;
    U8 name_convert[SRV_BT_CM_BD_FNAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_REN_PROC);

    dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);

    mmi_chset_ucs2_to_utf8_string(
        name_convert,
        SRV_BT_CM_BD_FNAME_LEN,
        (kal_uint8*) g_mmi_bt_scr_cntx.scr_buf);

    srv_bt_cm_set_dev_name(&dev_p->bd_addr, name_convert);

    cui_fseditor_close(g_mmi_bt_scr_cntx.fseditor_gid);
    g_mmi_bt_scr_cntx.fseditor_gid = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_delete_confirm
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  NULL         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_delete_confirm(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    WCHAR string[20];
	#ifdef __MMI_BT_DIALER_SUPPORT__
	srv_bt_cm_dev_struct* dev_p = srv_bt_cm_get_paired_dev_info(g_mmi_bt_scr_cntx.hilight_item);
	#endif /*__MMI_BT_DIALER_SUPPORT__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_DELETE_CONFIRM);
	#ifdef __MMI_BT_DIALER_SUPPORT__
	if( srv_bt_cm_is_dev_conn_active(&(dev_p->bd_addr)) &&
		(
		srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_MAPC_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION) 
	)
	)
	{
				mmi_bt_popup_display(
				STR_BT_RELEASE_CONN_PROMPT,
				MMI_EVENT_FAILURE,
				NULL);
				return;
	}
	#endif /*__MMI_BT_DIALER_SUPPORT__*/
    kal_wsprintf(
        string,
        "%w%w",
        (U16*)GetString(
            (type == MMI_BT_DELETE_DEV_CONFIRM) ?
            STR_GLOBAL_DELETE :
            STR_GLOBAL_DELETE_ALL),
        (U16*)GetString(STR_BT_QUESTION_MARK));
    MMI_BT_RESET_FLAG((MMI_BT_DELETE_DEV_ALL_CONFIRM | MMI_BT_DELETE_DEV_CONFIRM));
    MMI_BT_SET_FLAG(type);
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    arg.parent_id = g_mmi_bt_scr_cntx.mydev_gid;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    arg.callback = (mmi_proc_func)mmi_bt_entry_mydev_delete_confirm_proc;
    mmi_confirm_display(
        (WCHAR*)string,
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_delete_confirm_proc
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  mmi_event_struct         [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_entry_mydev_delete_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    if (g_mmi_bt_scr_cntx.flag & MMI_BT_DELETE_DEV_CONFIRM)
                    {
                        mmi_bt_entry_mydev_del();
                        MMI_BT_RESET_FLAG(MMI_BT_DELETE_DEV_CONFIRM);
                    }
                    else
                    {
                        mmi_bt_entry_mydev_del_all();
                        MMI_BT_RESET_FLAG(MMI_BT_DELETE_DEV_ALL_CONFIRM);
                    }
                    break;

                case MMI_ALERT_CNFM_NO:
                    break;
            }
        }
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_del
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->My Dev->Option->Delete
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SCR_DEL_TR);

    if (srv_bt_cm_is_dev_conn_active(&(g_mmi_bt_scr_cntx.conn_dev_add)))
    {
    #ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
        mmi_bt_display_release_connection_confirm(g_mmi_bt_scr_cntx.mydev_gid, MMI_BT_RELEASE_DEVICE_CONNECTION);
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_DEL);
    #else
        mmi_bt_popup_display(STR_BT_DISCONN_DEV_CONN, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.mydev_gid);
    #endif
        return;
    }

#if defined(__MMI_A2DP_SUPPORT__)
    mmi_a2dp_bt_delete_device_callback(&(g_mmi_bt_scr_cntx.conn_dev_add));
#endif

#ifdef __MMI_BPP_SUPPORT__
    mmi_bt_bpp_delete_device_callback(&(g_mmi_bt_scr_cntx.conn_dev_add));
#endif

#ifdef __MMI_BT_DEF_SEND_DEVICE__
    mmi_btsend_delete_device_callback(&g_mmi_bt_scr_cntx.conn_dev_add);
#endif

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_DEL);
    }

    if (srv_bt_cm_dev_del(&(g_mmi_bt_scr_cntx.conn_dev_add)) != SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_bt_popup_display(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.mydev_gid);
    }
    else
    {
        mmi_bt_show_progress_scr(
            g_mmi_bt_scr_cntx.mydev_gid,
            SCR_BT_MYDEV_DEL,
            STR_GLOBAL_DELETE,
            STR_GLOBAL_DELETING,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_mydev_del_all
 * DESCRIPTION
 *  This function is to entry My device delete all
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_mydev_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_MYDEV_DELETE_ALL);

    if (srv_bt_cm_get_existed_conn_num())
    {
    #ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
        mmi_bt_display_release_connection_confirm(g_mmi_bt_scr_cntx.mydev_gid,MMI_BT_RELEASE_ALL_CONNECTION);
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL);
    #else
        mmi_bt_popup_display(STR_BT_DISCONN_ALL_CONN, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.mydev_gid);
    #endif
        return;
    }

#if defined(__MMI_A2DP_SUPPORT__)
    mmi_a2dp_bt_delete_device_callback(NULL);
#endif

#ifdef __MMI_BPP_SUPPORT__
    mmi_bt_bpp_delete_device_callback(NULL);
#endif

#ifdef __MMI_BT_DEF_SEND_DEVICE__
    mmi_btsend_delete_device_callback(NULL);
#endif

    if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL)
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL);
    }

    if (srv_bt_cm_dev_del_all() != SRV_BT_CM_RESULT_SUCCESS)
    {
        mmi_bt_popup_display(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, g_mmi_bt_scr_cntx.mydev_gid);
    }
    else
    {
        mmi_bt_show_progress_scr(
            g_mmi_bt_scr_cntx.mydev_gid,
            SCR_BT_MYDEV_DEL_ALL,
            STR_GLOBAL_DELETE,
            STR_GLOBAL_DELETING,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_del_complete
 * DESCRIPTION
 *  This function is complete My device Delete operation
 * PARAMETERS
 *  res         [IN]            the delete result
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_del_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_mydev_del_struct *event = (srv_bt_cm_mydev_del_struct *)para;
#ifdef __MMI_BT_DIALER_SUPPORT__
    srv_bt_cm_dev_struct* dev_info = (srv_bt_cm_dev_struct *)event->del_dev;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SCR_DEL_TR_RES, event->result);

    if (!(event->result))
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_ERROR));
    }

    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_MYDEV_DEL);
    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_MYDEV_DEL_ALL);
#ifdef __MMI_BT_DIALER_SUPPORT__
    mmi_bt_dialer_clean_connected_dev_info(dev_info);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_about
 * DESCRIPTION
 *  This function is to Entry function for Extra->Bluetooth->About
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_about(void)
{
#if defined(__MTK_INTERNAL__)
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
        	#ifdef __MMI_BT_DIALER_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_PBAP_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__) 
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SPP_SUPPORT__
/* under construction !*/
#endif
#ifdef __MMI_DUN_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_BT_DIALER_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
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
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_display_release_all_connection_confirm
 * DESCRIPTION
 *  This function is to display release all connection confirm screen
 * PARAMETERS
 *  flag         [IN]        screen flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_display_release_connection_confirm(mmi_id group_id, mmi_bt_release_connection_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_data;
    MMI_ID scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_DISPLAY_CONFIRM_SCR, g_mmi_bt_scr_cntx.flag);

    /* not allow to re-entry mmi_bt_show_confirm_scr because only store one cnf scr id and string id */
    if (mmi_bt_flag_check())
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
        return;
    }

    user_data = type;

    if (type == MMI_BT_RELEASE_DEVICE_CONNECTION)
    {
        scrn_id = SCR_BT_RELEASE_DEV_CONN_CNF;
    }
#ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
    else if (type == MMI_BT_RELEASE_ALL_CONNECTION)
    {
        scrn_id = SCR_BT_RELEASE_ALL_CONN_CNF;
    }
#endif  // __MMI_BT_AUTO_RELEASE_CONNECTION__
    else
    {
        scrn_id = SCR_BT_RELEASE_AUD_CONN_CNF;
    }

#ifndef __MMI_BT_DIALER_SUPPORT__
    mmi_frm_scrn_first_enter(
        group_id,
        scrn_id,
        (FuncPtr) mmi_bt_entry_release_connection_confirm,
        (void *)user_data);
#else       
									  mmi_frm_nmgr_popup(
						 MMI_SCENARIO_ID_DEFAULT,
						 MMI_EVENT_FAILURE,
						(WCHAR*)GetString(STR_BT_RELEASE_CONN_PROMPT));
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_all_connection_confirm
 * DESCRIPTION
 *  This function is to entry release all connections confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_connection_confirm(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    U16 image_id = 0;
    U32 type = (U32)(info->user_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_RELEASE_ALL_CONNTION_CONFIRM);

    if (mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            (FuncPtr) NULL,
            (FuncPtr) mmi_bt_entry_release_connection_confirm,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    g_mmi_bt_scr_cntx.release_type = type;

    if (type == MMI_BT_RELEASE_DEVICE_CONNECTION)
    {
        string_id = STR_BT_DISCONN_DEV_CONN_CNF;
        image_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
        
    }
#ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
#ifndef __MMI_BT_DIALER_SUPPORT__
    else if (type == MMI_BT_RELEASE_ALL_CONNECTION)
    {
        string_id = STR_BT_DISCONN_ALL_CONN_CNF;
        image_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
    }
    #endif
#endif  // __MMI_BT_AUTO_RELEASE_CONNECTION__
    else
    {
        string_id = STR_BT_DISCONN_AUD_DEV_CONN_CNF;
#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_96X64__) ||defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)
        image_id = NULL;
#else
        image_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
#endif
    }

    ShowCategory66Screen(
        STR_GLOBAL_BLUETOOTH,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*)GetString(string_id),
        image_id,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_entry_release_connection_confirm_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_entry_release_connection_confirm_rsk, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mmi_bt_entry_release_connection_confirm_lsk, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_connection_confirm_rsk
 * DESCRIPTION
 *  This function is RSK handler of release all connection confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_connection_confirm_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_get_active_id();

    mmi_frm_scrn_set_leave_proc(group_id, SCR_BT_RELEASE_AUD_CONN_CNF, NULL);
	#ifdef __MMI_BT_DIALER_SUPPORT__
	if( srv_bt_cm_is_profile_connected(SRV_BT_CM_PBAPC_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_MAPC_CONNECTION) ||
		srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION) ||
       	srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION)
		)
	{
		mmi_bt_dialor_disconnect(&(g_mmi_bt_scr_cntx.conn_dev_add));
		mmi_frm_scrn_close(group_id, SCR_BT_RELEASE_AUD_CONN_CNF);
  		mmi_frm_scrn_close(group_id, SCR_BT_RELEASE_ALL_CONN_CNF);
   	    mmi_frm_scrn_close(group_id, SCR_BT_RELEASE_DEV_CONN_CNF);
		return;
	}
	#endif /*__MMI_BT_DIALER_SUPPORT__*/
    if (g_mmi_bt_scr_cntx.release_type == MMI_BT_RELEASE_DEVICE_CONNECTION)
    {
        mmi_bt_entry_release_device_connections(group_id);
    }
#ifdef __MMI_BT_AUTO_RELEASE_CONNECTION__
    else if (g_mmi_bt_scr_cntx.release_type == MMI_BT_RELEASE_ALL_CONNECTION)
    {
        mmi_bt_entry_release_all_connections(group_id);
    }
#endif  // __MMI_BT_AUTO_RELEASE_CONNECTION__
    else
    {
        //mmi_bt_entry_release_profile_connection(group_id);
#ifdef __MMI_HFP_SUPPORT__
        mmi_btaud_attach(group_id, &(g_mmi_bt_scr_cntx.conn_dev_add));
#endif  // __MMI_HFP_SUPPORT__
    }

    mmi_frm_scrn_close(group_id, SCR_BT_RELEASE_AUD_CONN_CNF);
    mmi_frm_scrn_close(group_id, SCR_BT_RELEASE_ALL_CONN_CNF);
    mmi_frm_scrn_close(group_id, SCR_BT_RELEASE_DEV_CONN_CNF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_connection_confirm_rsk
 * DESCRIPTION
 *  This function is RSK handler of release all connection confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_connection_confirm_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SWITCH_POWER_OFF);
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL);

    MMI_BT_RESET_FLAG(MMI_BT_RELEASE_AUDIO_DEV_BEFORE_CONNECT);

    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_DEL);

#if defined(__MMI_BT_AUTHORIZE__) && defined(__MMI_BT_AUTO_RELEASE_CONNECTION__)
    MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_AUTHORIZE_REJECT);
#endif

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_all_connections
 * DESCRIPTION
 *  This function is to entry the release all connections screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_all_connections(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_RELEASE_ALL_CONNECTIONS);
    if (srv_bt_cm_release_all_conn() == SRV_BT_CM_RESULT_NO_CONNECTION)
    {
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL)
        {
             mmi_bt_entry_mydev_del_all();
        }
        // #ifdef __MMI_SIMAP_SUPPORT__
        //         else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SIMAP_SET)
        //         {
        //             mmi_bt_entry_set_simap();
        //         }
        // #endif
        else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
        {
            mmi_bt_power_switching(g_mmi_bt_scr_cntx.main_gid);
        }
        //else
        //{
        //    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)GetString(STR_BT_CON_RELEASED));
        //}
    }
    else
    {
        MMI_BT_SET_FLAG(MMI_BT_RElEASE_CONNECT);
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
        {
            mmi_bt_show_progress_scr(
                g_mmi_bt_scr_cntx.main_gid,
                SCR_BT_POWER_PRO,
                STR_BT_POWER,
                STR_BT_SWITCHING,
                NULL);
            mmi_frm_scrn_set_leave_proc(
                g_mmi_bt_scr_cntx.main_gid,
                SCR_BT_POWER_PRO,
                mmi_bt_power_progress_leave_proc);
        }
        else
        {
            mmi_bt_show_progress_scr(
                group_id,
                SCR_BT_REL_ALL_CONN_PRO,
                STR_BT_RELEASE_ALL_CONN,
                STR_BT_RELEASING,
                NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_release_device_connections
 * DESCRIPTION
 *  This function is to entry the release device connections screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_release_device_connections(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_RELEASE_DEVICE_CONNECTIONS);

    if (srv_bt_cm_release_dev_conn(&(g_mmi_bt_scr_cntx.conn_dev_add)) == SRV_BT_CM_RESULT_NO_CONNECTION)
    {
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL)
        {
            mmi_bt_entry_mydev_del();
        }
#if defined(__MMI_BT_AUTHORIZE__) && defined(__MMI_BT_AUTO_RELEASE_CONNECTION__)
        else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_AUTHORIZE_REJECT)
        {
            mmi_bt_entry_mydev_authorize_select(SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT);
        }
#endif
    }
    else
    {
        MMI_BT_SET_FLAG(MMI_BT_RElEASE_CONNECT);
        #ifndef __MMI_BT_DIALER_SUPPORT__
            mmi_bt_show_progress_scr(
                group_id,
                SCR_BT_REL_DEV_CONN_PRO,
                STR_BT_RELEASE_DEV_CONN,
                STR_BT_RELEASING,
                NULL);
		#else

		mmi_bt_show_progress_scr(
			group_id,
			SCR_BT_REL_DEV_CONN_PRO,
			STR_BT_RELEASE_DEV_CONN,
			STR_GLOBAL_DISCONNECTING,
			NULL);

		
		#endif
        }
    }




/*****************************************************************************
 * FUNCTION
 *  mmi_bt_release_conn_complete
 * DESCRIPTION
 *  This function is to handle when release all connections complete
 * PARAMETERS
 *  result      [IN]            the result of release all connections
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_release_conn_complete(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_release_all_struct *event = (srv_bt_cm_release_all_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_RELEASE_ALL_CONN_COMPLETE, event->result);

    mmi_bt_update_status_icon();

    if (!(g_mmi_bt_scr_cntx.flag & MMI_BT_RElEASE_CONNECT))
    {
        return;
    }

    MMI_BT_RESET_FLAG(MMI_BT_RElEASE_CONNECT);

    if (event->result)
    {
        if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_SWITCH_POWER_OFF)
        {
            mmi_bt_power_switching(g_mmi_bt_scr_cntx.main_gid);
        }
        else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL)
        {
            mmi_bt_entry_mydev_del();
        }
        else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_PAIRED_DEV_DEL_ALL)
        {
            mmi_bt_entry_mydev_del_all();
        }
#if defined(__MMI_BT_AUTHORIZE__) && defined(__MMI_BT_AUTO_RELEASE_CONNECTION__)
        else if (g_mmi_bt_scr_cntx.flag & MMI_BT_CONFIRM_AUTHORIZE_REJECT)
        {
            mmi_bt_entry_mydev_authorize_select(SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT);
        }
#endif

    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_GLOBAL_ERROR));
    }

    /*the progress maybe in mydev_gid, or in main_gid*/
    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_REL_ALL_CONN_PRO);
    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.mydev_gid, SCR_BT_REL_DEV_CONN_PRO);

    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.main_gid, SCR_BT_REL_ALL_CONN_PRO);
    mmi_bt_stop_progress_scr(g_mmi_bt_scr_cntx.main_gid, SCR_BT_REL_DEV_CONN_PRO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_ind_notify
 * DESCRIPTION
 *  This function is to handle connect accept confirm request
 * PARAMETERS
 *  name_p              [IN]          device name
 *  uap                 [IN]          device address
 *  lap                 [IN]          device address
 *  nap                 [IN]          device address
 *  conn_id             [IN]          connection id
 *  prof_id             [IN]          profile id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_authorize_ind_notify(U8* dev_name, srv_bt_cm_bt_addr *dev_addr, U32 profile_id, void *callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_authorize_callback authorize_callback =(mmi_bt_authorize_callback)callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_CONNECT_ACCEPT_REQ,
              profile_id, dev_addr->nap, dev_addr->uap, dev_addr->lap);

#ifndef __MMI_BT_AUTHORIZE__
    if (g_enable_pts_test)
    {
        (*authorize_callback)(dev_addr, profile_id, MMI_TRUE);
        return;
    }
#endif

#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_get_authorize(dev_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
    {
        (*authorize_callback)(dev_addr, profile_id, MMI_FALSE);
        return;
    }

    if (srv_bt_cm_get_authorize(dev_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT)
    {
		mmi_bt_refresh_screen();
        (*authorize_callback)(dev_addr, profile_id, MMI_TRUE);
        return;
    }
#endif

     /* save the name, bd_addr, profile id */
    mmi_bt_add_connect_accept_stack(dev_addr, profile_id, callback);
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_BT_ACCESS_REQ,
        MMI_EVENT_INFO,
        mmi_bt_authorize_ind_scr_hdlr,
        (void*)profile_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_ind_scr_hdlr
 * DESCRIPTION
 *  This function is to handle entry connect accept confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_authorize_ind_scr_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_scr_authorize_struct *authorize_ptr = NULL;
    U32 prof_id = (U32)arg;
    mmi_id gid;
    U16 scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    authorize_ptr = mmi_bt_get_connect_accept_stack(prof_id);

    if (authorize_ptr == NULL)
    {
        return MMI_TRUE;
    }

    gid = mmi_bt_get_connect_cnf_gid(prof_id);

    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        gid,
        mmi_bt_authorize_ind_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    scrn_id = mmi_bt_get_connect_cnf_scr_id(authorize_ptr->prof_id);

    mmi_frm_scrn_first_enter(
        gid,
        scrn_id,
        (FuncPtr) mmi_bt_entry_authorize_ind_screen,
        (void *)authorize_ptr);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_ind_group_proc
 * DESCRIPTION
 *  This function is to group proc of handle entry connect accept confirm
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_authorize_ind_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return mmi_bt_dummy_group_proc(param);
}

static void mmi_bt_authorize_handle_ext(mmi_bt_scr_authorize_struct *auth_ptr, mmi_id gid,U16 scr_id,int skipcb,MMI_BOOL val)
    {

		U16 timerid;
		mmi_bt_authorize_callback  authorize_callback;
		if(auth_ptr==NULL)
			return;
		if(skipcb==MMI_BT_DONT_SKIP_CALLBACK)
		{
			authorize_callback =(mmi_bt_authorize_callback)auth_ptr->callback;
			(*authorize_callback)(&(auth_ptr->dev_add), auth_ptr->prof_id,val);
    }
        timerid = mmi_bt_get_connect_cnf_timer(auth_ptr->prof_id);
       StopTimer(timerid);

		mmi_bt_clear_connect_accept_stack(auth_ptr->prof_id);
       mmi_frm_scrn_set_leave_proc(gid, scr_id, NULL);
       mmi_frm_scrn_close(gid, scr_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_screen_close
 * DESCRIPTION
 *  This function is to cancel authorize screen for profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_bt_authorize_screen_close(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;
    mmi_id gid;
    mmi_bt_scr_authorize_struct *authorize_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_BT_ACCESS_REQ,
        mmi_bt_authorize_ind_scr_hdlr,
        (void *)profile_id);

   authorize_ptr = mmi_bt_get_connect_accept_stack(profile_id);
       scr_id = mmi_bt_get_connect_cnf_scr_id(profile_id);
       gid = mmi_bt_get_connect_cnf_gid(profile_id);
	   mmi_bt_authorize_handle_ext(authorize_ptr,gid,scr_id,MMI_BT_SKIP_CALLBACK,MMI_FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_authorize_ind_screen
 * DESCRIPTION
 *  This function is to handle entry connect accept confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_authorize_ind_screen(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_scr_authorize_struct *authorize_ptr = (mmi_bt_scr_authorize_struct *)info->user_data;
    U16 timerid;
    U8 *str_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_ENTRY_CONNECT_ACCEPT_CNF);

    if (authorize_ptr == NULL)
    {
        return;
    }

    if (mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            (FuncPtr) mmi_bt_exit_authorize_ind_screen,
            (FuncPtr) mmi_bt_entry_authorize_ind_screen,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);


    srv_bt_cm_get_dev_ucs2_name(
        &(authorize_ptr->dev_add),
        SRV_BT_CM_BD_UCS2_NAME_LEN,
        g_mmi_bt_scr_cntx.scr_buf);
    mmi_bt_get_profile_str_id((U16) authorize_ptr->prof_id, &(str_p));
    mmi_wsprintf(
        g_mmi_bt_scr_cntx.ui_buf,
        MMI_BT_UI_BUF_SIZE,
        STR_BT_ACCEPT_CONNECT_FROM,
        str_p,
        g_mmi_bt_scr_cntx.scr_buf);

    ShowCategory7Screen(
        STR_GLOBAL_BLUETOOTH,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*) g_mmi_bt_scr_cntx.ui_buf,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_authorize_ind_accepted, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_authorize_ind_rejected, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
    SetCenterSoftkeyFunction(mmi_bt_authorize_ind_accepted, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(
        info->group_id,
        info->scrn_id,
        mmi_bt_authorize_screen_leave_proc);

    timerid = mmi_bt_get_connect_cnf_timer(authorize_ptr->prof_id);
    StartTimerEx(timerid, MMI_BT_CONNECT_ACCEPT_CNF_TIMER_DUR, mmi_bt_authorize_screen_timeout, (void*)authorize_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_authorize_ind_screen
 * DESCRIPTION
 *  This function is to handle exit connect accept confirm
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_exit_authorize_ind_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_EXIT_CONNECT_ACCEPT_CNF);
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_screen_timeout
 * DESCRIPTION
 *  This function is handler the timeout in connnect accept confirm screen
 *  It will reject the connection request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_authorize_screen_timeout(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;
    mmi_id gid;
    mmi_bt_scr_authorize_struct *authorize_ptr = (mmi_bt_scr_authorize_struct *)arg;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_CONNECT_ACCEPT_CNF_TIMEOUT);
        gid = mmi_bt_get_connect_cnf_gid(authorize_ptr->prof_id);
        scr_id = mmi_bt_get_connect_cnf_scr_id(authorize_ptr->prof_id);
	mmi_bt_authorize_handle_ext(authorize_ptr,gid,scr_id,MMI_BT_DONT_SKIP_CALLBACK,MMI_FALSE);// for issue fixed.
	#ifdef __MMI_BT_DIALER_SUPPORT__
	g_bt_headset_conn_reject = MMI_TRUE;
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_screen_leave_proc
 * DESCRIPTION
 *  This function is to handle exit connect accept confirm
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_authorize_screen_leave_proc(mmi_event_struct *post_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct *)post_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (post_evt->evt_id)
    {
        // case EVT_ID_SCRN_GOBACK:
        // case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        // case EVT_ID_SCRN_DELETE_REQ:
        // case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        //     mmi_bt_authorize_screen_del_cb(post_evt->user_data);
        //     break;

        case EVT_ID_SCRN_DEINIT:
            mmi_bt_authorize_screen_del_cb(post_evt->user_data);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_screen_del_cb
 * DESCRIPTION
 *  This function is connect accept confirm screen delete callback function
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_authorize_screen_del_cb(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_scr_authorize_struct *authorize_ptr = (mmi_bt_scr_authorize_struct *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_CONNECT_ACCEPT_CNF_SCR_DEL_CALLBACK);
	#ifdef __MMI_BT_DIALER_SUPPORT__
	g_bt_headset_conn_reject = MMI_TRUE;
	#endif
	mmi_bt_authorize_handle_ext(authorize_ptr,NULL,NULL,MMI_BT_DONT_SKIP_CALLBACK,MMI_FALSE);
    return MMI_FALSE;
}

static void mmi_bt_authorize_ind_handle(MMI_BOOL val)
    {
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_bt_scr_authorize_struct *authorize_ptr;
    U16 scr_id;
    mmi_id gid;
    gid = mmi_frm_group_get_active_id();
    scr_id = mmi_frm_scrn_get_active_id();

    authorize_ptr = (mmi_bt_scr_authorize_struct *)mmi_frm_scrn_get_user_data(gid, scr_id);
	mmi_bt_authorize_handle_ext(authorize_ptr,gid,scr_id,MMI_BT_DONT_SKIP_CALLBACK,val);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_ind_accepted
 * DESCRIPTION
 *  This function is to handle accept request in connect accept confirm screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_authorize_ind_accepted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    

#if defined(_MMI_BT_ULTRA_SLIM_)&&!defined(__MMI_SIMAP_SUPPORT__)
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_CONNECT_ACCEPT_CNF_ACCEPTED);
	mmi_bt_authorize_ind_handle(MMI_TRUE);
#else
    mmi_bt_scr_authorize_struct *authorize_ptr;
    U16 scr_id;
    mmi_id gid;
    U16 timerid;
    mmi_bt_authorize_callback authorize_callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_CONNECT_ACCEPT_CNF_ACCEPTED);
    gid = mmi_frm_group_get_active_id();
    scr_id = mmi_frm_scrn_get_active_id();

    authorize_ptr = (mmi_bt_scr_authorize_struct *)mmi_frm_scrn_get_user_data(gid, scr_id);

    if (authorize_ptr == NULL)
    {
        return;
    }

    authorize_callback = (mmi_bt_authorize_callback)authorize_ptr->callback;

    timerid = mmi_bt_get_connect_cnf_timer(authorize_ptr->prof_id);
    StopTimer(timerid);

    mmi_frm_scrn_set_leave_proc(gid, scr_id, NULL);

#ifdef __MMI_SIMAP_SUPPORT__
    if (srv_ucm_is_any_call() &&
        (authorize_ptr->prof_id == SRV_BT_CM_SIM_ACCESS_PROFILE_UUID))
    {
        (*authorize_callback)(&(authorize_ptr->dev_add), authorize_ptr->prof_id, MMI_FALSE);
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
            MMI_EVENT_FAILURE,
            NULL);
    }
    else
#endif  // __MMI_SIMAP_SUPPORT__
    {
        (*authorize_callback)(&(authorize_ptr->dev_add), authorize_ptr->prof_id,MMI_TRUE);
    }

    mmi_bt_clear_connect_accept_stack(authorize_ptr->prof_id);

    mmi_frm_scrn_close(gid, scr_id);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authorize_ind_rejected
 * DESCRIPTION
 *  This function is to handle reject request in connect accept confirm screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_authorize_ind_rejected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_BT_DIALER_SUPPORT__
	g_bt_headset_conn_reject = MMI_TRUE;
	#endif
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_CONNECT_ACCEPT_CNF_REJECTED);
	mmi_bt_authorize_ind_handle(MMI_FALSE);

    }
  


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_show_progress_scr
 * DESCRIPTION
 *  This function is to show progressing screen
 * PARAMETERS
 *  scrid           [IN]        screen id
 *  title           [IN]        title
 *  context_id      [IN]        context id
 *  context_str     [IN]        context string id
 *  cancel_key      [IN]        can be cancelled or not
 *  fp              [IN]        function pointer
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_show_progress_scr(mmi_id group_id, U16 scrid, U16 title, U16 context_id, FuncPtr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_SCR_SHOW_PROGRESSING,
        scrid,
        group_id,
        title,
        context_id);

    /* to keep the original title string while input argument, title, is 0 */
    if (title != 0)
    {
        g_mmi_bt_scr_cntx.prog_scr.title_str_id = title;
    }
        #ifdef __MMI_BT_DIALER_SUPPORT__

    if (mmi_frm_scrn_is_present(g_mmi_bt_scr_cntx.prog_scr.gid,  g_mmi_bt_scr_cntx.prog_scr.scr_id, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_mmi_bt_scr_cntx.prog_scr.gid, g_mmi_bt_scr_cntx.prog_scr.scr_id);
    }
#endif
    g_mmi_bt_scr_cntx.prog_scr.fp = (void*)fp;
    g_mmi_bt_scr_cntx.prog_scr.gid = group_id;
    g_mmi_bt_scr_cntx.prog_scr.scr_id = scrid;

    if (context_id)
    {
        mmi_wcscpy(g_mmi_bt_scr_cntx.prog_scr.context_str, (WCHAR*)GetString(context_id));
    }

    /* keep backlight on while processing */
    //srv_backlight_turn_on(0);

    mmi_bt_entry_progress_scr();

    // if (scrid == SCR_BT_SCH_PRO)
    // {
    //     mmi_frm_scrn_set_leave_proc(
    //         g_mmi_bt_scr_cntx.inq_gid,
    //         SCR_BT_SCH_PRO,
    //         mmi_bt_inq_progress_leave_proc);
    // }
    // else if (scrid == SCR_BT_POWER_PRO)
    // {
    //     mmi_frm_scrn_set_leave_proc(
    //         group_id,
    //         scrid,
    //         mmi_bt_power_progress_leave_proc);
    // }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_progress_scr
 * DESCRIPTION
 *  This function is to entry progressing screen
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_entry_progress_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_SCR_ENTRY_PROGRESSING,
        g_mmi_bt_scr_cntx.prog_scr.scr_id,
        g_mmi_bt_scr_cntx.prog_scr.gid);

    if (mmi_frm_scrn_enter(
            g_mmi_bt_scr_cntx.prog_scr.gid,
            g_mmi_bt_scr_cntx.prog_scr.scr_id,
            (FuncPtr) NULL,
            (FuncPtr) mmi_bt_entry_progress_scr,
            MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

    /* Command does not support abort */
    if (g_mmi_bt_scr_cntx.prog_scr.fp)
    {
    #ifndef __MMI_BT_DIALER_SUPPORT__
        ShowCategory66Screen(
            (g_mmi_bt_scr_cntx.prog_scr.title_str_id),
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            (U8*) (g_mmi_bt_scr_cntx.prog_scr.context_str),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);
    #else
        ShowCategory163Screen(
            NULL,
            NULL,
            (UI_string_type) GetString(STR_GLOBAL_CANCEL),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            (UI_string_type) (g_mmi_bt_scr_cntx.prog_scr.context_str),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);

    #endif
        SetRightSoftkeyFunction((FuncPtr) (g_mmi_bt_scr_cntx.prog_scr.fp), KEY_EVENT_UP);
    }
    else
    {
    #ifndef __MMI_BT_DIALER_SUPPORT__
        ShowCategory66Screen(
            (g_mmi_bt_scr_cntx.prog_scr.title_str_id),
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            0,
            0,
            (U8*) (g_mmi_bt_scr_cntx.prog_scr.context_str),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);
    #else
        ShowCategory163Screen(
            0,
            0,
            0,
            0,
            (UI_string_type)(g_mmi_bt_scr_cntx.prog_scr.context_str),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_stop_progress_scr
 * DESCRIPTION
 *  This function is to stop progressing screen
 * PARAMETERS
 *  is_goback       [IN]            need goback history or not
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_stop_progress_scr(mmi_id group_id, U16 scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SCR_STOP_PROGRESS, scrid, group_id);
    if (group_id)
    {
        mmi_frm_scrn_set_leave_proc(group_id, scrid, NULL);
        mmi_frm_scrn_close(group_id, scrid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_inq_progress_leave_proc
 * DESCRIPTION
 *  This function is the leave proc of inquiry progress delete callback
 * PARAMETERS
 *  evt         [IN]    MMI event stucture
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bt_power_progress_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_ALLOW_DELETE_POWER_PROGRESS_SCREEN__
    {
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_INQ_AUDIO_DEV);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_PAIRED_DEV_OPT);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_INQ_ALL_DEV);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET_DEV_NAME);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET_VISIBILITY);
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SPECIFIC_DEV);
#ifdef __MMI_BT_AUTHORIZE__
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_UNBLOCK);
#endif  // __MMI_BT_AUTHORIZE__
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_CONNECT_AUDIO);
        MMI_BT_RESET_FLAG(MMI_BT_AUTO_ON);
#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
        MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_ANTILOST_SET);
#endif
        return MMI_RET_OK;
    }
    
#else  // __MMI_BT_ALLOW_DELETE_POWER_PROGRESS_SCREEN__

    return MMI_RET_ERR;

#endif  // __MMI_BT_ALLOW_DELETE_POWER_PROGRESS_SCREEN__
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ps_stack_and_hw_init
 * DESCRIPTION
 *  This function is to inform bt stack and hw to start initialize or not
 * PARAMETERS
 *  flight_mode         [IN]            if it's in flight mode
 *  sim_inserted        [IN]            if SIM card is inserted
 *
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
// MMI_BOOL mmi_bt_ps_stack_and_hw_init(MMI_BOOL flight_mode, MMI_BOOL sim_inserted)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PS_HW_INIT,
//               flight_mode, sim_inserted, srv_bt_cm_is_activated());
//     if (!flight_mode)
//     {
//         if (g_mmi_bt_scr_cntx.sys_flag & MMI_BT_POWER_ON)
//         {
//             srv_bt_cm_switch_on();
//         }
//     }
//     return MMI_TRUE;
// }


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_panic_ind_pre_process
 * DESCRIPTION
 *  This function is to pre process of panic indication
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_panic_ind_pre_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* re-init A2DP */
    /* re-init BT profile */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PANIC_IND_PRE_PROCESS);
#ifdef __MMI_BT_AUDIO_SUPPORT__

#ifdef __MMI_A2DP_SUPPORT__
    mmi_a2dp_bt_power_off_callback(MMI_TRUE);
#endif
    srv_btsco_reset(mmi_bt_panic_ind_post_process);

#else
    mmi_bt_panic_ind_post_process();
#endif
}


void mmi_bt_panic_ind_post_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_PANIC_IND_POST_PROCESS);

    //StopTimer(BT_RELEASE_ALL_CON_GUARD_TIMER);
    //StopTimer(BT_POPUP_TIMER);

    srv_bt_cm_recover_panic_req();

    if (g_mmi_bt_scr_cntx.prog_scr.gid != GRP_ID_INVALID)
    {
        mmi_frm_scrn_set_leave_proc(
            g_mmi_bt_scr_cntx.prog_scr.gid,
            SCR_BT_POWER_PRO,
            NULL);
    }

    mmi_frm_group_close(g_mmi_bt_scr_cntx.main_gid);

    mmi_bt_deinit();

    mmi_bt_init();

    mmi_bt_update_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_dev_select
 * DESCRIPTION
 *  This function is select my specific devcie
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_bt_cm_dev_struct* mmi_bt_get_matched_dev(U32 item_index, U32 specific_cod, U32 service_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct* dev_p;
    U32 i, j, paired_dev_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_GET_MATCHED_DEV, item_index, specific_cod, service_id);

    paired_dev_num = srv_bt_cm_get_paired_dev_num();
    for (i = 0, j = 0; i < paired_dev_num; ++i)
    {
        dev_p = srv_bt_cm_get_paired_dev_info((U16)i);
        if (mmi_bt_is_dev_cod_match(dev_p->cod, specific_cod) ||
            srv_bt_cm_check_dev_profile_support_status(&(dev_p->bd_addr), service_id))
        {
            if (j++ == item_index)
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_GET_MATCHED_DEV_EXT,j);
                return dev_p;
            }
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_active_signal_connection_id
 * DESCRIPTION
 *  This function is to get signal connection id
 * PARAMETERS
 *  profile_uuid        [IN]            profile id
 *
 *
 * RETURNS
 *  S32         connction id
 *****************************************************************************/
S32 mmi_bt_get_active_signal_connection_id(U32 profile_uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* if a2dp signal connection is not existed, return -1 */
    S32 conn_id = -1;
    U32 i = 0;
    U8 act_con_num;
    srv_bt_cm_connect_struct *conn_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    act_con_num = srv_bt_cm_get_existed_conn_num();

    for (i = 0; i < act_con_num; i++)
    {
        conn_p = srv_bt_cm_get_existed_conn_info((U16) i);
        /* assume that there is only one profile_uuid(A2DP/HFP) connection at one time */

        switch (srv_bt_cm_get_conn_type(conn_p->profile_id))
        {
            case SRV_BT_CM_A2DP_CONNECTION:
                if (conn_p->active == MMI_TRUE && profile_uuid == SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID)
                {
                    conn_id = (S32) conn_p->conn_id;
                }
                break;

            case SRV_BT_CM_HFP_CONNECTION:
            case SRV_BT_CM_HSP_CONNECTION:
                if (conn_p->active == MMI_TRUE &&
                    (profile_uuid == SRV_BT_CM_HFG_PROFILE_UUID || profile_uuid == SRV_BT_CM_HEADSET_AG_SERVICE_UUID))
                {
                    conn_id = (S32) conn_p->conn_id;
                }
                break;

            default:
                break;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_GET_ACTIVE_SIGNAL_CONNECTION_ID, profile_uuid, conn_id);
    return conn_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_profile_str_id
 * DESCRIPTION
 *  This function is to get profile str id for UI display
 * PARAMETERS
 *  profile_uuid        [IN]            profile ID
 *  str                 [OUT]           profile string ID
 *
 *
 * RETURNS
 *  MMI_BOOL        TRUE : the profile is found
 *                  FALSE : the profile is not found
 *****************************************************************************/
MMI_BOOL mmi_bt_get_profile_str_id(U16 profile_uuid, U8 **str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (profile_str_id_map[i][0] != SRV_BT_CM_MAX_PROFILE_UUID)
    {
        if (profile_str_id_map[i][0] == profile_uuid)
        {
            break;
        }
        i++;
    }

    if (profile_str_id_map[i][0] == SRV_BT_CM_MAX_PROFILE_UUID)
    {
        *str = (U8*) GetString((U16) STR_BT_PROF_UNKNOWN);
    }
    else
    {
        result = MMI_TRUE;
        *str = (U8*) GetString((U16) profile_str_id_map[i][1]);
    }
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_GET_PROFILE_STR_ID, profile_uuid, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_connect_accept_stack
 * DESCRIPTION
 *  This function is to set specific connect accept structure of stack as zero
 * PARAMETERS
 *  prof_id : profile ID
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bt_scr_authorize_struct *mmi_bt_get_connect_accept_stack(U32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = SRV_BT_CM_MAX_CONNECTION - 1; i >= 0 ; i--)
    {
        if (g_mmi_bt_scr_cntx.authorize_ptr[i].prof_id == prof_id)
        {
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_BT_G7_SCR_POP_CONNECT_ACCEPT_STACK,
                i,
                g_mmi_bt_scr_cntx.authorize_ptr[i].prof_id);
            return &(g_mmi_bt_scr_cntx.authorize_ptr[i]);
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_SCR_POP_CONNECT_ACCEPT_STACK_NOT_FOUND);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_connect_cnf_scr_id
 * DESCRIPTION
 *  This function is to get connect confirm screen id of certain profile
 * PARAMETERS
 *  U32 prof_id     profile ID
 * RETURNS
 *  U16             screen id
 *****************************************************************************/
U16 mmi_bt_get_connect_cnf_scr_id(U32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (prof_id)
    {
        case SRV_BT_CM_HF_PROFILE_UUID:
        case SRV_BT_CM_HFG_PROFILE_UUID:
#ifdef __MMI_BT_MAP_CLIENT__
		case SRV_BT_CM_MESSAGE_ACCESS_PROFILE_SERVER_UUID:
#endif
            return SCR_BT_CONNECT_ACCEPT_CNF_HFP;

        case SRV_BT_CM_HS_PROFILE_UUID:
        case SRV_BT_CM_HEADSET_AG_SERVICE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_HSP;

#ifdef __MMI_DUN_SUPPORT__
        case SRV_BT_CM_DUN_PROFILE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_DUN;
#endif

#ifdef __MMI_SPP_SUPPORT__
        case SRV_BT_CM_SPP_PROFILE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_SPP;
#endif

#ifdef __MMI_OPP_SUPPORT__
        case SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_OPP;
#endif

#ifdef __MMI_FTS_SUPPORT__
        case SRV_BT_CM_OBEX_FILE_TRANSFER_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_FTP;
#endif

#ifdef __MMI_FAX_SUPPORT__
        case SRV_BT_CM_FAX_PROFILE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_FAX;
#endif

#ifdef __MMI_BIP_SUPPORT__
        case SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_BIP;
#endif

#ifdef __MMI_HIDD_SUPPORT__
        case SRV_BT_CM_HID_PROFILE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_HID;
#endif

#ifdef __MMI_SIMAP_SUPPORT__
        case SRV_BT_CM_SIM_ACCESS_PROFILE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_SAP;
#endif

#ifdef __MMI_PBAP_SUPPORT__ || defined(__MMI_BT_PBAP_CLIENT__)
        case SRV_BT_CM_OBEX_PBA_PROFILE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_PBAP;
#endif

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) 
        case SRV_BT_CM_SYNCML_DEV_PROFILE_UUID:
            return SCR_BT_CONNECT_ACCEPT_CNF_SYNC;
#endif
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_connect_cnf_gid
 * DESCRIPTION
 *  This function is to get connect confirm screen timer
 * PARAMETERS
 *  U32 prof_id     profile ID
 * RETURNS
 *  U16             screen id
 *****************************************************************************/
U16 mmi_bt_get_connect_cnf_timer(U32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (prof_id)
    {
        case SRV_BT_CM_HF_PROFILE_UUID:
        case SRV_BT_CM_HFG_PROFILE_UUID:
            return BT_AUTHORIZE_SCREEN_HFP_TIMER;

        case SRV_BT_CM_HS_PROFILE_UUID:
        case SRV_BT_CM_HEADSET_AG_SERVICE_UUID:
            return BT_AUTHORIZE_SCREEN_HSP_TIMER;

#ifdef __MMI_DUN_SUPPORT__
        case SRV_BT_CM_DUN_PROFILE_UUID:
            return BT_AUTHORIZE_SCREEN_DUN_TIMER;
#endif

#ifdef __MMI_SPP_SUPPORT__
        case SRV_BT_CM_SPP_PROFILE_UUID:
            return BT_AUTHORIZE_SCREEN_SPP_TIMER;
#endif

#ifdef __MMI_OPP_SUPPORT__
        case SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID:
            return BT_AUTHORIZE_SCREEN_OPP_TIMER;
#endif

#ifdef __MMI_FTS_SUPPORT__
        case SRV_BT_CM_OBEX_FILE_TRANSFER_UUID:
            return BT_AUTHORIZE_SCREEN_FTP_TIMER;
#endif

#ifdef __MMI_FAX_SUPPORT__
        case SRV_BT_CM_FAX_PROFILE_UUID:
            return BT_AUTHORIZE_SCREEN_FAX_TIMER;
#endif

#ifdef __MMI_BIP_SUPPORT__
        case SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID:
            return BT_AUTHORIZE_SCREEN_BIP_TIMER;
#endif

#ifdef __MMI_HIDD_SUPPORT__
        case SRV_BT_CM_HID_PROFILE_UUID:
            return BT_AUTHORIZE_HID_TIMER;
#endif

#ifdef __MMI_SIMAP_SUPPORT__
        case SRV_BT_CM_SIM_ACCESS_PROFILE_UUID:
            return BT_AUTHORIZE_SCREEN_SIMAP_TIMER;
#endif

#ifdef __MMI_PBAP_SUPPORT__
        case SRV_BT_CM_OBEX_PBA_PROFILE_UUID:
            return BT_AUTHORIZE_SCREEN_PBAP_TIMER;
#endif

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) 
        case SRV_BT_CM_SYNCML_DEV_PROFILE_UUID:
            return BT_AUTHORIZE_SCREEN_SYNC_TIMER;
#endif

        default:
            return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_connect_cnf_gid
 * DESCRIPTION
 *  This function is to get connect confirm screen id of certain profile
 * PARAMETERS
 *  U32 prof_id     profile ID
 * RETURNS
 *  U16             screen id
 *****************************************************************************/
mmi_id mmi_bt_get_connect_cnf_gid(U32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (prof_id)
    {
        case SRV_BT_CM_HF_PROFILE_UUID:
        case SRV_BT_CM_HFG_PROFILE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_HFP;

        case SRV_BT_CM_HS_PROFILE_UUID:
        case SRV_BT_CM_HEADSET_AG_SERVICE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_HSP;

#ifdef __MMI_DUN_SUPPORT__
        case SRV_BT_CM_DUN_PROFILE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_DUN;
#endif

#ifdef __MMI_SPP_SUPPORT__
        case SRV_BT_CM_SPP_PROFILE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_SPP;
#endif

#ifdef __MMI_OPP_SUPPORT__
        case SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_OPP;
#endif

#ifdef __MMI_FTS_SUPPORT__
        case SRV_BT_CM_OBEX_FILE_TRANSFER_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_FTP;
#endif

#ifdef __MMI_FAX_SUPPORT__
        case SRV_BT_CM_FAX_PROFILE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_FAX;
#endif

#ifdef __MMI_BIP_SUPPORT__
        case SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_BIP;
#endif

#ifdef __MMI_HIDD_SUPPORT__
        case SRV_BT_CM_HID_PROFILE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_HID;
#endif

#ifdef __MMI_SIMAP_SUPPORT__
        case SRV_BT_CM_SIM_ACCESS_PROFILE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_SAP;
#endif

#ifdef __MMI_PBAP_SUPPORT__
        case SRV_BT_CM_OBEX_PBA_PROFILE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_PBAP;
#endif

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) 
        case SRV_BT_CM_SYNCML_DEV_PROFILE_UUID:
            return GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_SYNC;
#endif

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_popup_string
 * DESCRIPTION
 *  This function is to tell shell the popup string
 * PARAMETERS
 *  void
 * RETURNS
 *  U16             string_id
 *****************************************************************************/
U16 mmi_bt_get_popup_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bt_scr_cntx.popup_string;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_get_display_bt_address
 * DESCRIPTION
 *  This function is to convert bt address to display
 * PARAMETERS
 *  void
 * RETURNS
 *  U16             string_id
 *****************************************************************************/
void mmi_bt_get_display_bt_address(WCHAR *display_buffer, const srv_bt_cm_bt_addr *bd_addr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        display_buffer,
        "%02x:%02x:%02x:%02x:%02x:%02x",
        ((bd_addr_p->nap & 0xff00) >> 8),
        (bd_addr_p->nap & 0x00ff),
        (bd_addr_p->uap),
        ((bd_addr_p->lap & 0xff0000) >> 16),
        ((bd_addr_p->lap & 0x00ff00) >> 8),
        (bd_addr_p->lap & 0x0000ff));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_add_connect_accept_stack
 * DESCRIPTION
 *  This function is to push connect accept structure into stack
 * PARAMETERS
 *  name_p              [IN]          device name
 *  uap                 [IN]          device address
 *  lap                 [IN]          device address
 *  nap                 [IN]          device address
 *  prof_id             [IN]          profile id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_add_connect_accept_stack(srv_bt_cm_bt_addr *dev_add, U32 prof_id, void *callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION ; i++)
    {
        if (g_mmi_bt_scr_cntx.authorize_ptr[i].prof_id == 0)
        {
			
			srv_bt_cm_copy_addr(&g_mmi_bt_scr_cntx.authorize_ptr[i].dev_add,dev_add);
            g_mmi_bt_scr_cntx.authorize_ptr[i].prof_id = prof_id;
            g_mmi_bt_scr_cntx.authorize_ptr[i].callback = callback;
            mmi_bt_echo_stack_info();
            return;
        }
    }

    MMI_ASSERT(i < SRV_BT_CM_MAX_CONNECTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_clear_connect_accept_stack
 * DESCRIPTION
 *  This function is to set specific connect accept structure of stack as zero
 * PARAMETERS
 *  prof_id : profile ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_clear_connect_accept_stack(U32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = SRV_BT_CM_MAX_CONNECTION - 1; i >= 0 ; i--)
    {
        if (g_mmi_bt_scr_cntx.authorize_ptr[i].prof_id == prof_id)
        {
            memset(
                &g_mmi_bt_scr_cntx.authorize_ptr[i],
                0,
                sizeof(mmi_bt_scr_authorize_struct));
            break;
        }
    }

    mmi_bt_echo_stack_info();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_echo_stack_info
 * DESCRIPTION
 *  This function is to echo the authorize_ptr stack info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_echo_stack_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 5 ; i++)
    {
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            MMI_BT_G7_BT_STACK_INFO,
            i,
            g_mmi_bt_scr_cntx.authorize_ptr[i].prof_id,
            g_mmi_bt_scr_cntx.authorize_ptr[i].dev_add.lap,
            g_mmi_bt_scr_cntx.authorize_ptr[i].dev_add.uap,
            g_mmi_bt_scr_cntx.authorize_ptr[i].dev_add.nap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_update_status_icon
 * DESCRIPTION
 *  This function is to update status icon
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_update_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_power_status_enum pwrstatus;
	U8 conn_num;
	MMI_BOOL is_a2dp_conn;
	MMI_BOOL is_hfp_conn;
	MMI_BOOL is_hsp_conn,earphone_plug_in;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	pwrstatus=srv_bt_cm_get_power_status();
	conn_num=srv_bt_cm_get_existed_conn_num();
	is_a2dp_conn=srv_bt_cm_is_profile_connected(SRV_BT_CM_A2DP_CONNECTION);
	is_hfp_conn=   srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION);
	is_hsp_conn = srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION);
	earphone_plug_in= srv_earphone_is_plug_in();
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_GEN_UPDATE_STATUS_ICON,
        pwrstatus,
        conn_num,
        is_a2dp_conn,
       	is_hfp_conn|| is_hsp_conn,earphone_plug_in);

    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_BT);
    #ifndef _MMI_BWUI_BT_SLIM_
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_BT_CON);
		#endif
    if (pwrstatus == SRV_BT_CM_POWER_ON ||
        pwrstatus == SRV_BT_CM_POWER_SWITCHING_OFF)
    {

        /* update headset icon in idle screen */
        if (is_a2dp_conn ||
            is_hfp_conn ||
            is_hsp_conn)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_EARPHONE_INDICATOR);
        }
        else
        {
            if (!earphone_plug_in)
            {
                wgui_status_icon_bar_reset_icon_display(STATUS_ICON_EARPHONE_INDICATOR);
            }
        }
        if (pwrstatus == SRV_BT_CM_POWER_ON)
        {
            if (conn_num)
            {
            	#ifndef _MMI_BWUI_BT_SLIM_
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_BT_CON);
              #endif
            }
            else
            {
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_BT);
            }
        }
    }

    else
    {
        if (!earphone_plug_in)
        {
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_EARPHONE_INDICATOR);
        }
    }

    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_permission
 * DESCRIPTION
 *  This function is to check if Bluetooth is permissible to access now
 * PARAMETERS
 *  is_popup        [IN]            if it's not permissilbe to access Bluetooth, whether to popup or not
 *
 *
 * RETURNS
 *  MMI_BOOL        TRUE : Bluetooth is permissible
 *                  FALSE : Bluetooth is not permissible
 *****************************************************************************/
MMI_BOOL mmi_bt_is_permission(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_TRUE;
	srv_bt_cm_power_status_enum pwrstatus;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	pwrstatus=srv_bt_cm_get_power_status();
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_SCR_PERMISSION_STATUS,
        pwrstatus);
    if (pwrstatus == SRV_BT_CM_POWER_SWITCHING_ON)
    {
        if (is_popup)
        {
            mmi_popup_display_ext(
                STR_BT_NOT_READY,
                MMI_EVENT_FAILURE,
                NULL);
        }

        res = MMI_FALSE;
    }
    else if (pwrstatus == SRV_BT_CM_POWER_SWITCHING_OFF)
    {
        if (is_popup)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
        }

        res = MMI_FALSE;
    }
#if defined(__MMI_HIDD_SUPPORT__)
    else if (mmi_bt_hid_is_busy())
    {
        if (is_popup)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
        }

        res = MMI_FALSE;
    }
#endif /* defined(__MMI_HIDD_SUPPORT__)*/
#ifdef __DM_LAWMO_SUPPORT__
    else if (srv_bt_cm_get_flag(SRV_BT_CM_MASK_DM_RESET))
    {
        if (is_popup)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
        }

        res = MMI_FALSE;
    }
#endif

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_power_on
 * DESCRIPTION
 *  This function is to check if Bluetooth is power on
 * PARAMETERS
 *  is_popup        [IN]            if Bluetooth is not power on, whether to show the power on confirm
 * RETURNS
 *  MMI_BOOL        TRUE : Bluetooth is power on
 *                  FALSE : Bluetooth is not power on
 *****************************************************************************/
MMI_BOOL mmi_bt_is_power_on(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_BT_CM_POWER_ON == srv_bt_cm_get_power_status())
    {
        res = MMI_TRUE;
    }

    if (is_popup)
    {
        if (mmi_frm_scrn_is_present(g_mmi_bt_scr_cntx.main_gid, SCR_BT_POWER_ON_CNF, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
        }
    }
    return res;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_power_on_with_power_on_confirm
 * DESCRIPTION
 *  This function is to check if Bluetooth is power on
 * PARAMETERS
 *  is_popup        [IN]            if Bluetooth is not power on, whether to show the power on confirm
 * RETURNS
 *  MMI_BOOL        TRUE : Bluetooth is power on
 *                  FALSE : Bluetooth is not power on
 *****************************************************************************/
MMI_BOOL mmi_bt_is_power_on_with_power_on_confirm(MMI_BOOL is_popup, void (*power_on_cb_func_ptr) (MMI_BOOL))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_BT_CM_POWER_ON == srv_bt_cm_get_power_status())
    {
        res = MMI_TRUE;
    }
    else if (SRV_BT_CM_POWER_OFF == srv_bt_cm_get_power_status())
    {
        if (is_popup)
        {
            /* not need to keep confirm screen in history while interrupted by other screen */
            if (!(mmi_bt_flag_check()||
                  mmi_frm_scrn_is_present(g_mmi_bt_scr_cntx.main_gid, SCR_BT_POWER_ON_CNF, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)
                    ))
            {
                mmi_bt_register_power_on_callback_with_result(power_on_cb_func_ptr);
            }
        }

        //res = MMI_FALSE;
    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_hw_ready
 * DESCRIPTION
 *  This function is to check if Bluetooth hardware is reayd
 * PARAMETERS
 *  is_popup        [IN]            if Bluetooth hardware is not ready, whether to prompt popup or not
 *
 *
 * RETURNS
 *  MMI_BOOL            TRUE : Bluetooth hardware is ready
 *                      FALSE : Bluetooth hardware is not ready
 *****************************************************************************/
MMI_BOOL mmi_bt_is_hw_ready(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_SWITCHING_ON)
    {
        if (is_popup)
        {
            mmi_popup_display_ext(
                STR_BT_NOT_READY,
                MMI_EVENT_FAILURE,
                NULL);
        }

        res = MMI_FALSE;
    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_to_display_bt_menu
 * DESCRIPTION
 *  This function is to decide to show BT menu or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : show BT menu
 *                  FALSE : don't show BT menu
 *****************************************************************************/
MMI_BOOL mmi_bt_is_to_display_bt_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __BT_AUTO_DETECT_SUPPORT__
    if (!srv_bt_chip_available())
    {
        result = MMI_FALSE;
    }
#endif

#ifndef __MMI_BT_IN_FLIGHT_MODE__
  #ifdef __MMI_TELEPHONY_SUPPORT__
    if (!srv_mode_switch_is_network_service_available() || g_mmi_bt_scr_cntx.is_switching_to_flight_mode)
    {
        result = MMI_FALSE;
    }
  #endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif  // __MMI_BT_IN_FLIGHT_MODE__

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_IS_TO_DISPLAY_BT_MENU, result);

    return result;
}


#ifdef __BT_AUTO_DETECT_SUPPORT__
static void mmi_bt_chip_status_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_chip_detect_struct *chip_detect = (srv_bt_cm_chip_detect_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __DISABLE_SHORTCUTS_IMPL__
    if (!chip_detect->result)
        mmi_shct_dynamic_register(MENU_CONN_BT_MAIN, MMI_FALSE);
#endif  // __DISABLE_SHORTCUTS_IMPL__
}
#endif  // __BT_AUTO_DETECT_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_bt_in_flight_mode
 * DESCRIPTION
 *  This function is to check if __MMI_BT_IN_FLIGHT_MODE__ is on and it's in flight mode now
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : __MMI_BT_IN_FLIGHT_MODE__ is on and it's in flight mode now
 *                  FALSE : otherwise
 *****************************************************************************/
MMI_BOOL mmi_bt_is_bt_in_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_IN_FLIGHT_MODE__
  #ifdef __MMI_TELEPHONY_SUPPORT__
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        result = MMI_TRUE;
    }
  #endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif  // __MMI_BT_IN_FLIGHT_MODE__

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_IS_BT_IN_FLIGHT_MODE, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 * mmi_bt_is_dev_cod_match
 * DESCRIPTION
 *  This function is to check the matchness of cod mask
 *  For the device cod, it should be exactly match
 * PARAMETERS
 *  device_cod    the cod of the device
 *  specific_cod  the cod mask set
 * RETURNS
 *  MMI_BOOL      MMI_TRUE  the cod mask match
 *                MMI_FALSE otherwise
 *****************************************************************************/
MMI_BOOL mmi_bt_is_dev_cod_match(U32 device_cod, U32 specific_cod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL match = MMI_FALSE;
    U32 major_service = 0, major_device = 0, minor_device = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (specific_cod == 0xFFFFFFFF)
    {
        match = MMI_TRUE;
    }
    else if (specific_cod == MMI_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK)
    {
        match = MMI_TRUE;
    }
    else
    {
        major_service = 0x00FFE000 & specific_cod;
        major_device = 0x00001F00 & specific_cod;
        minor_device = 0x000000FC & specific_cod;
        if ((major_service & device_cod) != 0)
        {
            if ((major_device == 0) && (minor_device == 0))
            {
                match = MMI_TRUE;
            }
            else if (((device_cod & 0x1F00) == major_device) && ((minor_device == 0) || ((device_cod & 0xFF) == minor_device)))
            {
                match = MMI_TRUE;
            }
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_DEV_COD_MATCH, device_cod, specific_cod, match);
    return match;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_hf_car_kit_connected
 * DESCRIPTION
 *  This function is to check if the cod of connected handsfree profile is car-kit
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : car kit connected
 *                  FALSE : no car kit connected
 *****************************************************************************/
MMI_BOOL mmi_bt_is_hf_car_kit_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    if (srv_bthf_get_status() > BTHF_STATUS_DETACH)
    {
        U32 dev_id;
        bthf_dev_info_struct info;

        srv_bthf_list_device(&dev_id, 1);
        srv_bthf_get_device_info(dev_id, &info);

        if (info.dev_class == BTHF_DEV_CARKIT)
            result = MMI_TRUE;
    }
#endif  //__MMI_HFP_SUPPORT__

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_IS_HF_CAR_KIT_CONNECTED, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_is_doing_far_end_loopback_test
 * DESCRIPTION
 *  This function is to check if bt is doing far end LP test
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    TRUE : bt is doing far end LP test
                FALSE : bt is not doing far end LP test
 *****************************************************************************/
MMI_BOOL mmi_bt_is_doing_far_end_loopback_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_scr_cntx.flag & MMI_BT_SCO_FAR_END_LP_TESTING)
    {
        result = MMI_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ower_off_pre_process
 * DESCRIPTION
 *  This function is pre process of host device power off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_bt_power_off_pre_process(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_power_off_pre_process");
	#ifdef __MMI_A2DP_SUPPORT__
	#ifdef __BT_SPEAKER_SUPPORT__
	#ifdef __MMI_BT_SPEAKER_SUPPORT__
	if(aud_bt_a2dp_is_codec_opened() == KAL_TRUE)
	aud_send_bt_close_sink_codec_req(MOD_MMI);
        #endif /*__MMI_BT_SPEAKER_SUPPORT__*/
	#endif //__MMI_A2DP_SUPPORT__
	#endif //__BT_SPEAKER_SUPPORT__
    return MMI_RET_OK;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_bt_test_UCS2
 * DESCRIPTION
 *  check if 2-byte UCS2 char existed
 * PARAMETERS
 *  buf         [IN]
 *  charNum     [IN]        number of char in buffer
 * RETURNS
 *  return true if 2-byte UCS2 char existed, else return false
 *****************************************************************************/
MMI_BOOL mmi_bt_test_ucs2(U16 *buf, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < char_num)
    {
        /* if ch is larger than 128, then the byte count of UTF8 encoding is 2*/
        if (0xff80 & buf[count])
        {
            result = MMI_TRUE;
            break;
        }

        count++;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_TEST_UCS2, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_truncate_ucs2_string
 * DESCRIPTION
 *  to truncate ucs2 string to compromise the size of utf8 string buffer in bt core
 * PARAMETERS
 *  buf         [IN]
 *  charNum     [IN]        number of char in buffer
 *  truncate_char_num     [IN]        min number of char in input string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_truncate_ucs2_string(U16 *buf, U16 char_num, U16 truncate_char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U8 truncate_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_TRUNCATE_UCS2_STRING);
    while (count < char_num)
    {
        /* if ch is larger than 128, then the byte count of UTF8 encoding is 2*/
        if (0xff80 & buf[count])
        {
            truncate_flag = 1;
        }

        if (truncate_flag && (count >= truncate_char_num))
        {
            buf[count] = 0;
            break;
        }

        count++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_popup_display
 * DESCRIPTION
 *  This function is to popup currently not available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_popup_display(U16 string_id, U32 event, mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_id)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(string_id),
            (mmi_event_notify_enum)event,
            group_id,
            NULL);
    }
    else
    {
        mmi_popup_display(
            (WCHAR*)GetString(string_id),
            (mmi_event_notify_enum)event,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_popup_operation_not_allowed
 * DESCRIPTION
 *  to popup operation not allowed information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_popup_operation_not_allowed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(
        STR_BT_OPERATION_NOT_ALLOWED_DIS_HFP_FIRST,
        MMI_EVENT_FAILURE,
        NULL);
}




#ifdef __MMI_BT_AUTHORIZE__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_popup_prohibited_by_blocked_device
 * DESCRIPTION
 *  before initiating the outgoing connection(FTPC, OPPC, HID, BIP-I, BPP), check if this device is blocked or not
 *  If device is blocked, then invoke this function to popup information to end user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_popup_prohibited_by_blocked_device(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(
        STR_BT_DEVICE_BLOCKED,
        MMI_EVENT_FAILURE,
        NULL);
}
#endif /* __MMI_BT_AUTHORIZE__ */


#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_remove_disconnect_sco_screen_leave_proc
 * DESCRIPTION
 *  This function is the leave proc of search progressing screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bt_remove_disconnect_sco_screen_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            srv_btsco_inquiry_stop_callback();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

#endif /*defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)*/


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hfp_sco_link_connect_req
 * DESCRIPTION
 *  This function is Handsfree profile SCO link connect request
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hfp_sco_link_connect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_HFP_SCO_LINK_CONNECT_REQ);
#ifdef __MMI_BT_AUDIO_SUPPORT__
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) ||
        srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION))
    {
        srv_btsco_open_stream_req();
    }
#endif  // __MMI_BT_AUDIO_SUPPORT__
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hfp_sco_link_disconnect_req
 * DESCRIPTION
 *  This function is Handsfree SCO link disconnect request
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hfp_sco_link_disconnect_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_HFP_SCO_LINK_DISCONNECT_REQ);
#ifdef __MMI_BT_AUDIO_SUPPORT__
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) ||
        srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION))
    {
        srv_btsco_close_stream_req();
    }
#endif  // __MMI_BT_AUDIO_SUPPORT__
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hfp_set_speaker_vol
 * DESCRIPTION
 *  This function is to set remote headset speaker volume
 * PARAMETERS
 *  volume_gain     [IN] the gain shall be >= 0 and <= 15.
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hfp_set_speaker_vol(U32 volume_gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    U32 dev_id;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_SPK_VOLUME_REQ, volume_gain);
    if (srv_bthf_list_device(&dev_id, 1))
    {
        srv_bthf_change_volume(0, dev_id, (U8)volume_gain);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_switch_voice_path_incall
 * DESCRIPTION
 *  This function is to switch voice path incall
 * PARAMETERS
 *  is_on       [IN]
 * RETURNS
 *  MMI_BOOL          TRUE : SCO link is on
 *                    FALSE : SCO link is off
 *****************************************************************************/
MMI_BOOL mmi_bt_switch_voice_path_incall(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_SWITCH_VOICE_PATH_INCALL, is_on) ;

    if (!(srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) ||
         srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
    {
        mmi_popup_display_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE,
            NULL);
        return MMI_FALSE;
    }

    group_id = mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_BT_CM_PROGRESS,
        mmi_bt_main_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (is_on)
    {
        if (srv_bt_cm_get_sco_status() != MMI_TRUE)
        {
#ifdef __MMI_BT_AUDIO_SUPPORT__
            if (srv_btsco_is_sco_connect_allowed())
            {
                srv_btsco_open_stream_req();
                mmi_bt_show_progress_scr(
                    group_id,
                    SCR_BT_SWITCH_SPEECH_PATH,
                    STR_BT_DEV_SET_AUDIO_PATH,
                    STR_BT_CM_SETPATH,
                    NULL);
            }
            else
            {
                mmi_popup_display_ext(
                    STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                    MMI_EVENT_FAILURE,
                    NULL);
            }
#endif /*defined(__MMI_BT_AUDIO_SUPPORT__)*/

            return MMI_TRUE;
        }
        else
        {
            mmi_popup_display_ext(
                STR_GLOBAL_UNFINISHED,
                MMI_EVENT_FAILURE,
                NULL);
            return MMI_FALSE;
        }
    }
    else
    {
        if (srv_bt_cm_get_sco_status())
        {
#ifdef __MMI_BT_AUDIO_SUPPORT__
            srv_btsco_close_stream_req();
            mmi_bt_show_progress_scr(
                group_id,
                SCR_BT_SWITCH_SPEECH_PATH,
                STR_BT_DEV_SET_AUDIO_PATH,
                STR_BT_CM_SETPATH,
                NULL);
#endif

            return MMI_TRUE;
        }
        else
        {
            mmi_popup_display_ext(
                STR_GLOBAL_UNFINISHED,
                MMI_EVENT_FAILURE,
                NULL);
            return MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_ind
 * DESCRIPTION
 *  This function is to handle SCO indication
 * PARAMETERS
 *  res         [IN]            SCO is connected or disconnected
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sco_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
	mmi_bt_sco_ind_ext(para,MMI_BT_SCO_IND);

}
    
#ifdef __MMI_EM_BT_GENERAL_TEST__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_far_end_loopback_test
 * DESCRIPTION
 *  This function is to do far end loopback test
 * PARAMETERS
 *  lap             [IN]        bluetooth address
 *  uap             [IN]        bluetooth address
 *  nap             [IN]        bluetooth address
 *  pin_code        [IN]         pin code of remote bt headset, max number of PIN is 16 digits
 *  size_of_pin     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sco_far_end_loopback_test(U32 lap, U8 uap, U16 nap, U8 *pin_code /* ascii encoding */ , U8 size_of_pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *res_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_BT_G7_LP_TEST,
        g_mmi_bt_scr_cntx.test_by_at,
        lap,
        uap,
        nap,
        pin_code[0],
        pin_code[1],
        pin_code[2],
        pin_code[3]);

    if (g_mmi_bt_scr_cntx.test_by_at == 0)
    {
        g_mmi_bt_scr_cntx.test_by_em = 1;
    }

    /* store testin device bt address */
    g_mmi_bt_scr_cntx.far_end_dev_add.lap = lap;
    g_mmi_bt_scr_cntx.far_end_dev_add.uap = uap;
    g_mmi_bt_scr_cntx.far_end_dev_add.nap = nap;

    /* store pin code */
    /* strlen will not count the NULL terminate byte */
    if (strlen((const char*)pin_code) > MMI_BT_MAX_PASSKEY_LENGHT)
    {
        memcpy(g_mmi_bt_scr_cntx.far_end_dev_pin, pin_code, MMI_BT_MAX_PASSKEY_LENGHT);
        g_mmi_bt_scr_cntx.far_end_dev_pin[MMI_BT_MAX_PASSKEY_LENGHT] = 0;
    }
    else
    {
        memcpy(g_mmi_bt_scr_cntx.far_end_dev_pin, pin_code, size_of_pin);
        g_mmi_bt_scr_cntx.far_end_dev_pin[size_of_pin] = 0;
    }

    if (g_mmi_bt_scr_cntx.test_by_at)
    {
        res_p = construct_local_para(sizeof(mmi_at_general_res_req_struct), TD_UL);

        res_p->result = MMI_FALSE;

        mmi_frm_send_ilm(MOD_L4C,MSG_ID_MMI_AT_GENERAL_RES_REQ,(oslParaType *)res_p,NULL);
        g_mmi_bt_scr_cntx.test_by_at = 0;
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_SWITCHING_ON ||
        srv_bt_cm_get_existed_conn_num())
    {
        if (g_mmi_bt_scr_cntx.test_by_em)
        {
            /* call back engineering...failed */
        #ifdef __MMI_ENGINEER_MODE__
            EmBTNotifyLoopbackDoneCnf(MMI_FALSE);
        #endif
            g_mmi_bt_scr_cntx.test_by_em = 0;
        }

        return;
    }
    else
    {
        MMI_BT_SET_FLAG(MMI_BT_SCO_FAR_END_LP_TESTING);

        /* store device infor to paired dev */
        srv_bt_cm_dev_add(&(g_mmi_bt_scr_cntx.far_end_dev_add));

        if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
        {
        #ifdef __MMI_HFP_SUPPORT__
            mmi_btaud_attach(GRP_ID_INVALID, &(g_mmi_bt_scr_cntx.far_end_dev_add));
        #else
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
        #endif
        }
        else
        {
            srv_bt_cm_switch_on();
        }
    }

    StartTimer(BT_LP2_TESTING_TIMER, MMI_BT_BT_LP2_GUARD_TIMER_DUR, mmi_bt_loopback_test_timeout_hdler);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_far_end_loopback_cancel_test
 * DESCRIPTION
 *  This function is to do far end loopback cancel test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_sco_far_end_loopback_cancel_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_remove(&(g_mmi_bt_scr_cntx.far_end_dev_add));

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
    {
        srv_bt_cm_switch_off();
    }
    else
    {
        MMI_BT_RESET_FLAG(MMI_BT_SCO_FAR_END_LP_TESTING);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_loopback_req_ind_hdler
 * DESCRIPTION
 *  This function is the handler for loopback req ind from L4
 * PARAMETERS
 *  msg_ptr     [IN]     message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_loopback_req_ind_hdler(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr dev_add_p;
    mmi_l4_bt_loopback_test_req_ind_struct *lp_test_p = (mmi_l4_bt_loopback_test_req_ind_struct*) msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_scr_cntx.test_by_at = 1;

    dev_add_p.nap = ((U16)((lp_test_p->bd_addr[3]) << 8)) | ((U16)(lp_test_p->bd_addr[4]));
    dev_add_p.uap = (U8)(lp_test_p->bd_addr[5]);
    dev_add_p.lap = ((U32)((lp_test_p->bd_addr[0]) << 16)) | ((U32)((lp_test_p->bd_addr[1]) << 8)) | ((U32)(lp_test_p->bd_addr[2]));
    mmi_bt_sco_far_end_loopback_test(
        dev_add_p.lap,
        dev_add_p.uap,
        dev_add_p.nap,
        lp_test_p->pin_code,
        (U8) strlen((const char*)lp_test_p->pin_code));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_loopback_test_timeout_hdler
 * DESCRIPTION
 *  This function is the handler for loopback testing timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_loopback_test_timeout_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_sco_ind_ext(NULL,MMI_BT_SCO_FAR_LP_TESTING);
        }

    
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_loopback_delay_timeout_hdler
 * DESCRIPTION
 *  This function is the handler for loopback testing timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_loopback_delay_timeout_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* callback dsp api */
#ifdef __MTK_TARGET__
    result = BT_PcmLoopbackTest();
#else
    result = MMI_FALSE;
#endif

    mmi_bt_hfp_sco_link_disconnect_req();

#ifdef __MMI_BT_AUDIO_SUPPORT__
    srv_prof_bt_disconnected_hdlr(SRV_PROF_BT_HFP_ACL, SRV_PROF_BT_IND);
#endif
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_LP_TEST_RESULT, result);
	mmi_bt_sco_ind_l4_module(result);
    srv_bt_cm_switch_off();

}


/* V33 test mode support */
#ifdef __TC01__
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
#ifdef __GEMINI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __GEMINI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#if 1
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#if 1
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
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
#endif  //  __TC01__


/* for pts V2.1.0.4 */
/* cannot update indicators to remote bluetooth headset while HFP is connected */
/* indicators shall be retrieved by remote HF AT+CIND? */
/* so for pts V2.1.0.4, host will not udpate indicators while HFP is just connected */
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_enable_pts_test
 * DESCRIPTION
 *  to enable the global variable to indicate that pts testing is active
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_enable_pts_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_enable_pts_test = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_disable_pts_test
 * DESCRIPTION
 *  to disable the global variable to indicate that pts testing is off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_disable_pts_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_enable_pts_test = 0;
}

#ifndef _MMI_BT_ULTRA_SLIM_
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_device_list_seperate_line
 * DESCRIPTION
 *
 * PARAMETERS
 *  index       [IN]
 *  flag        [?]
 *  flag_ex     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_entry_device_list_seperate_line(S32 index, U32 *flag, U32 *flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_mydev_menu_tap_callback
 * DESCRIPTION
 *  This function is to my device menu tap behavior callback
 * PARAMETERS
 *  tap_type        tap type
 *  index           highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_mydev_menu_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_dev_struct *dev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        if (index == 0)
        {
            mmi_bt_inquiry_dev();
        }
        else
        {
            --index;
            dev_p = mmi_bt_get_matched_dev(
                index,
                g_mmi_bt_scr_cntx.dev_cod_mask,
                g_mmi_bt_scr_cntx.dev_service_id);

            if (dev_p)
            {
                memcpy(&g_mmi_bt_scr_cntx.conn_dev_add, &dev_p->bd_addr, sizeof(srv_bt_cm_bt_addr));

                if (g_mmi_bt_scr_cntx.dev_select_option_flag == CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT)
                {
                    mmi_bt_entry_dev_select();
                }
#ifdef __MMI_BT_DEF_SEND_DEVICE__
                else if (g_mmi_bt_scr_cntx.dev_select_option_flag == CUI_BT_CM_DEVICE_SELECT_OPTION_SET_DEFAULT)
                {
                }
#endif  // __MMI_BT_DEF_SEND_DEVICE__
                else
                {
#ifdef __MMI_BT_AUTHORIZE__
                    if (srv_bt_cm_get_authorize(&dev_p->bd_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
                    {
                        mmi_bt_entry_mydev_unblock();
                    }
#endif  //__MMI_BT_AUTHORIZE__
                }
            }
        }
    }
}
#endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#endif //_MMI_BT_ULTRA_SLIM_//

#else  // __MMI_BT_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_main_hilight_handler
 * DESCRIPTION
 *  This function is Bluetooth highlight handler
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_main_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BTBOX_NOLCD__
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#endif
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_init
 * DESCRIPTION
 *  This function is to init Bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif  /*__MMI_BT_SUPPORT__*/
