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
 *  PhoneBookApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is to provide phonebook list UI
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#include "MMIDataType.h"

#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookResDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookCore.h"
#include "PhbCuiGprot.h"
#include "MenuCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "InlineCuiGprot.h"
#include "PhbSrvGprot.h"

#include "CommonScreens.h"

#include "App_usedetails.h"

#include "mdi_datatype.h"
#include "Mdi_audio.h"

#include "SettingDefs.h"
#include "SettingGprots.h"
#include "SettingsGdcl.h"
#include "SettingsGexdcl.h"
#include "gpioInc.h"

#include "UCMGprot.h"
#include "UcmSrvGprot.h"

#include "UCMGprot.h"
#include "UcmSrvGprot.h"

#include "Browser_api.h"

#include "MessagesExDcl.h"
#ifdef __MMI_UNIFIED_COMPOSER__
#include "UMGprot.h"
#include "UcAppGprot.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

#include "MessagesMiscell.h"    /* for IsMessagesReEntering */
#include "MessagesResourceData.h"       /* for STR_SMS_MSG_NOT_READY_YET */

#include "SmsSrvGprot.h"
#include "SmsAppGprot.h"

#ifdef __MMI_MMS__
#include "Mmsadp.h"
#endif /* __MMI_MMS__ */
#if 0
#ifdef __MMI_VOIP__
/* under construction !*/
#endif
#endif

#if defined(__MMI_PHB_INFO_FIELD__)
#include "app_url.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */

#ifdef __USB_IN_NORMAL_MODE__ 
#include "USBDeviceGprot.h"
#endif /* __USB_IN_NORMAL_MODE__ */

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

#if defined(__MMI_VCARD__)
#include "vObjects.h"
#include "vcard.h"
#include "Mmi_rp_srv_vcard_def.h"
#if defined(__MMI_OPP_SUPPORT__)
#include "BTMMIScrGprots.h"
#endif
#endif /* defined(__MMI_VCARD__) */

#ifdef __MMI_UDX_VCARD_SUPPORT__
#include "UDXGprot.h"
#endif
#if 0
#ifdef __MMI_IMPS__
/* under construction !*/
#endif
#endif

#if defined(__MMI_BPP20_SUPPORT__)
#include "Conversions.h" /* for value buffer conversion */
#if 1 /* BPP split */
#include "BppCuiGprot.h"
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_BPP20_SUPPORT__ */

#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h"
#endif

#ifdef __MMI_CM_BLACK_LIST__
#include "CallSetSrvGprot.h" /* srv_callset_blacklist_add_number */
#endif

#ifdef __MMI_URI_AGENT__
#include "UriAgentSrvGprot.h"
#include "Conversions.h"
#endif
#if 0
#ifdef __MMI_VRSD_DIAL__
/* under construction !*/
#endif
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif /* __DM_LAWMO_SUPPORT__ */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
//#include "ToDoListResDef.h"
#include "mmi_rp_app_todolist_def.h"
#include "BirthdayGprot.h"
#endif
#endif

#include "simctrlsrvgprot.h"
#include "IdleGprot.h"
#include "GpioSrvGprot.h"
#include "SecSetCuiGprot.h"

/* auto add by kw_check begin */
#include "UriAgentSrvGprot.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_scenario_gprot.h"
#include "string.h"
#include "CustDataRes.h"
#include "mmi_rp_app_phonebook_def.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "custom_phb_config.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "ps_public_enum.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "mmi_frm_history_gprot.h"
#include "mms_api.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "UcSrvGprot.h"
#include "BppXhtmlGprot.h"
#include "FileMgrSrvGProt.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "fs_type.h"
#include "fs_func.h"
#include "stack_config.h"
#include "mmi_rp_srv_syncml_def.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_list.h"
#include "gpiosrvgprot.h"
/* auto add by kw_check end */
#include "Smu_common_enums.h"
#include "TimerEvents.h"
#include "NotificationGprot.h"
#ifdef __MMI_SNS_CONTACTS__
#include "SnsAppGprot.h"
#include "SnsCuiGprot.h"
#include "SnsSrvTypes.h"
#include "SnsSrvGprot.h"
#include "mmi_rp_srv_sns_def.h"
#endif
#if 0
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#ifdef __MMI_3G_SWITCH__
/* under construction !*/
#endif
#endif
#else
#if defined(__MMI_VIDEO_TELEPHONY__)
#ifdef __MMI_3G_SWITCH__
#include "NetSetSrvGprot.h"
#endif
#endif
#endif

/*----------------------------------------------------------------*/
/* Define                                                         */
/*----------------------------------------------------------------*/
#if defined(__MMI_BPP20_SUPPORT__)
#define PHB_BPP_FIELD_TITLE_BUFFER_LENGTH 60
#define PHB_BPP_FIELD_VALUE_BUFFER_LENGTH 160
#endif

#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
#define MMI_PHB_MAX_UNSAVED_DATA_NUM 5
#endif /* defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__) */

#include "ProfilesSrvGprot.h"
#include "modeSwitchSrvGprot.h"
#include "USBSrvGprot.h"
#include "NwUsabSrvGprot.h"

/*----------------------------------------------------------------*/
/* Global Variables                                               */
/*----------------------------------------------------------------*/
mmi_phb_op_cntx_struct g_mmi_phb_op_cntx;

mmi_phb_confirm_user_data_struct g_mmi_phb_confirm_user_data;

MMI_ID g_phb_view_option_gid;

#ifdef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
#if (MMI_MAX_SIM_NUM > 1) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) 
static U16 from_copy_move_menu_id;
static MMI_BOOL phb_op_all;
static mmi_id mmi_phb_from_menu_id;
static mmi_id mmi_phb_to_menu_id;
#endif
#endif

#ifdef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static WCHAR* g_mmi_phb_mess_operation_title;
#endif
#endif

#ifdef __MMI_INTELLIGENT_CALL_ALERT__
static U8 g_phb_is_speaking_name = 0;
#endif
#if 0
#if defined(__MMI_PHB_CALLER_VIDEO__)
#if defined(__MMI_SWFLASH__)
/* under construction !*/
#endif
#endif
#endif

#if defined(__MMI_PHB_MULTI_OPERATION__)   
extern mmi_phb_mark_several_pre_enum g_mmi_phb_mark_several_type;
#endif

#ifdef __MMI_MAINLCD_96X64__
extern mmi_phb_setting_cntx_struct g_phb_setting_cntx;
extern mmi_phb_setting_screen_cntx_struct *sg_setting_cntx;
#endif

#ifdef __MMI_SNS_CONTACTS__
extern mmi_phb_sns_misc_struct g_mmi_phb_sns_misc;
#endif

/*----------------------------------------------------------------*/
/* extern function                                                */
/*----------------------------------------------------------------*/
#if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
extern int mmi_postcard_forward_from_phonebook_entry(U16 store_index);
#endif
#if 0
#if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
#endif
#endif

#ifdef __MMI_CM_BLACK_LIST__
void mmi_phb_add_to_blacklist_choose_entry(MMI_ID group_id);
#ifdef __MMI_VIDEO_TELEPHONY__
void mmi_phb_add_to_video_blacklist_choose_entry(MMI_ID group_id);
#endif
#endif

void mmi_phb_entry_op_copy_menu(MMI_ID group_id, MMI_ID menu_id);

#if (MMI_MAX_SIM_NUM > 1) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
void mmi_phb_entry_op_move_menu(MMI_ID menu_id);
#endif
#if (MMI_MAX_SIM_NUM > 1)
void mmi_phb_entry_op_move_sim_confirm(MMI_ID group_id, phb_storage_enum dest_storage);
#endif

#if defined(__MMI_VCARD__)
void mmi_phb_vcard_send_select_card(mmi_vcard_build_vcard_enum type);
#endif

#if defined(__MMI_BPP20_SUPPORT__)
#if defined(MMI_ON_HARDWARE_P)
static void mmi_phb_bpp_print(void);
#endif
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
static void mmi_phb_view_contact_option_entry_send_message(MMI_ID group_id);
#else /* __MMI_UNIFIED_COMPOSER__ */
static void mmi_phb_view_contact_send_sms(MMI_ID group_id);
#ifdef __MMI_MMS__
static void mmi_phb_view_contact_send_mms(MMI_ID group_id);
#endif /* __MMI_MMS__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */

void mmi_phb_view_contact_dial(MMI_ID group_id);

#if defined(__IP_NUMBER__)
void mmi_phb_view_contact_dial_ip_call(MMI_ID group_id);
#endif

#ifdef __MMI_EMAIL__
void mmi_phb_option_op_send_email(MMI_ID group_id);
#endif

#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#endif
#endif

#ifdef BROWSER_SUPPORT
void mmi_phb_option_op_start_broswer(MMI_ID group_id, MMI_ID menu_id);
#endif



#ifdef __MMI_PHB_CALLER_VIDEO__
void mmi_phb_option_op_play_video(MMI_ID group_id);
#endif

#if  defined(__MMI_FILE_MANAGER__) && defined(__MMI_VCARD__)
static void mmi_phb_op_copy_to_file(MMI_ID group_id);
#endif

#if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
void mmi_phb_op_send_postcard(void);
#endif

/*----------------------------------------------------------------*/
/* Static function                                                */
/*----------------------------------------------------------------*/
#ifdef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
#if (MMI_MAX_SIM_NUM > 1)
static void mmi_phb_menu_create(mmi_id gid, mmi_menu_id root_menu_id, U16 str);
#endif
#endif



static void mmi_phb_option_op_view_pic(MMI_ID group_id);

static void mmi_phb_pre_entry_mark_several_copy(MMI_ID group_id);
static void mmi_phb_pre_entry_mark_several_move(MMI_ID group_id);
static void mmi_phb_pre_entry_delete_all_confirm(MMI_ID group_id);

static void mmi_phb_delete_all_pre_req_ext(MMI_ID group_id);
static void mmi_phb_delete_all_pre_req(void);
static void mmi_phb_ucm_make_call(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id);
static void mmi_phb_ucm_make_video_call(mmi_phb_op_action_cntx_struct *op_action, MMI_ID group_id);
static void mmi_phb_ucm_make_voice_call(mmi_phb_op_action_cntx_struct *op_action, MMI_ID group_id);
static void mmi_phb_entry_op_delete_confirm(MMI_ID group_id);
static void mmi_phb_op_delete_entry_req(MMI_ID group_id);
static void mmi_phb_entry_op_copy_to_phone_confirm(MMI_ID group_id, phb_storage_enum storage);
static void mmi_phb_entry_op_copy_to_sim_confirm(MMI_ID group_id, phb_storage_enum storage);
static void mmi_phb_entry_op_move_confirm(MMI_ID group_id, phb_storage_enum storage);
static void mmi_phb_op_copy_pre_req(MMI_ID group_id);
static void mmi_phb_op_move_pre_req(MMI_ID group_id);
static MMI_BOOL mmi_phb_is_start_broswer_permit(void);
static void mmi_phb_entry_move_several(void);
static void mmi_phb_entry_copy_several(void);
static void mmi_phb_multi_op_done(U16 finish_count, U16 total_count,MMI_BOOL canceled, U16 action);
static void mmi_phb_entry_delete_all(void);
#if defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)
static void mmi_phb_entry_delete_all_phone_lock(MMI_ID group_id);
static void mmi_phb_delete_all_verify_phone_lock(void);
#else
static void mmi_phb_entry_delete_all_confirm(MMI_ID group_id);
#endif /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__) */ 
static void mmi_phb_copy_all_pre_req(MMI_ID group_id);
static void mmi_phb_single_op_done_ext(S32 result, U16 store_index, mmi_phb_op_cntx_struct *op_cntx);


static void mmi_phb_op_add_more_cb(S32 result, U16 store_index, void *user_data);
static void mmi_phb_op_save_contact(void);
static void mmi_phb_op_save_contact_pre_save(MMI_ID group_id);


static void mmi_phb_dial_normal_call_ex(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id);




#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_dynamic_name_string_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_sim_dynamic_name_string_index(sim_interface_enum string_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(string_index)
    {
        case SIM1:
            result = STR_GLOBAL_SIM_1;
            break;

        case SIM2:
            result = STR_GLOBAL_SIM_2;
            break;

     #if (MMI_MAX_SIM_NUM >= 3)
         case SIM3:
            result = STR_GLOBAL_SIM_3;
            break;
     #endif
     
     #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4:
            result = STR_GLOBAL_SIM_4;
            break;
     #endif
        
        default:
            ASSERT (0);
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_dynamic_name_string_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_phb_sim_dynamic_name_string_check(U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (1 == srv_sim_ctrl_get_num_of_inserted())
    {
        switch(string_id)
        {
            case STR_ID_PHB_TO_SIM1:
            case STR_ID_PHB_TO_SIM2:
         #if (MMI_MAX_SIM_NUM >= 3)
            case STR_ID_PHB_TO_SIM3:
         #endif
         #if (MMI_MAX_SIM_NUM >= 4)
            case STR_ID_PHB_TO_SIM4:
         #endif
                result = STR_ID_PHB_TO_SIM;
                break;

            case STR_ID_PHB_FROM_SIM1:
            case STR_ID_PHB_FROM_SIM2:
         #if (MMI_MAX_SIM_NUM >= 3)
            case STR_ID_PHB_FROM_SIM3:
         #endif 
         #if (MMI_MAX_SIM_NUM >= 4)
            case STR_ID_PHB_FROM_SIM4:
         #endif
                result = STR_ID_PHB_FROM_SIM;
                break;

            case STR_GLOBAL_SIM_1:
            case STR_GLOBAL_SIM_2:
         #if (MMI_MAX_SIM_NUM >= 3)
            case STR_GLOBAL_SIM_3:
         #endif
         #if (MMI_MAX_SIM_NUM >= 4)
            case STR_GLOBAL_SIM_4:
         #endif
                result = STR_GLOBAL_SIM;
                break;
        
            default:
                break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_dynamic_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim_dynamic_name(mmi_sim_enum mmi_sim, MMI_ID inline_gid, U16 menu_id, U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[MMI_NETSET_SIM_NAME_MAX_LEN * 2]; 
    WCHAR name_total[MMI_PHB_MAX_DYNAMIC_SIM_NAME_LENGTH];
    U16 String;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_netset_get_sim_name_with_brace(mmi_sim, name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
    String = mmi_phb_sim_dynamic_name_string_check(string_id);
    if (0 == String)
    {
        String = string_id;
    }
    kal_wsprintf(name_total, "%w%w\n", (WCHAR*)GetString(String), name);
    cui_menu_set_item_string(inline_gid, menu_id, name_total);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_dynamic_name_simx_title
 * DESCRIPTION
 *  set menu cui title 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim_dynamic_name_simx_title(mmi_sim_enum mmi_sim, MMI_ID inline_gid, U16 string_id, WCHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[MMI_NETSET_SIM_NAME_MAX_LEN * 2];
    U16 String;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_netset_get_sim_name_with_brace(mmi_sim, name, MMI_NETSET_SIM_NAME_MAX_LEN * 2);
    String = mmi_phb_sim_dynamic_name_string_check(string_id);
    if (0 == String)
    {
        String = string_id;
    }
    kal_wsprintf(buffer, "%w%w\n", (WCHAR*)GetString(String), name); 
    if (inline_gid)
    {
        cui_menu_set_default_title_string(inline_gid, buffer);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_ctrl_not_available_hide_menu
 * DESCRIPTION
 *  check operation of SIM, such as move, copy, add new contact etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_sim_ctrl_not_available_hide_menu(mmi_sim_enum mmi_sim, MMI_ID inline_gid, U16 menu_id, U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_available = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (!srv_sim_ctrl_is_available(mmi_sim))
    {
        cui_menu_set_item_hidden(inline_gid, menu_id, MMI_TRUE);
    }
    else
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        mmi_phb_sim_dynamic_name(mmi_sim, inline_gid, menu_id, string_id);
    #endif
        is_available = MMI_TRUE;
    }
#endif
    return is_available;
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_memory_card_not_available_hide_menu
 * DESCRIPTION
 *  check memory card, if not available, then hide menu.
 * PARAMETERS
 *  inline_gid: inline group id, menu_id: menu id 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_memory_card_not_available_hide_menu(MMI_ID inline_gid, U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        cui_menu_set_item_hidden(inline_gid, menu_id, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(inline_gid, menu_id, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_memory_card_is_ready
 * DESCRIPTION
 *  check memory card ready.
 * PARAMETERS
 *  storage 
 * RETURNS
 *  true if ready
 *****************************************************************************/
MMI_BOOL mmi_phb_memory_card_is_ready(phb_storage_enum storage, MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (PHB_STORAGE_TCARD == storage && !srv_phb_tcard_is_ready())
    {
        if (is_popup)
        {
            mmi_phb_popup_display_ext(
                STR_ID_PHB_MEMORY_CARD_NOT_AVAILABLE,
                MMI_EVENT_FAILURE);
        }
        return MMI_FALSE;
    }

    return MMI_TRUE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_ctrl_not_insert
 * DESCRIPTION
 *  check operation of SIM, such as call, send message etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sim_ctrl_not_inserted_disable_menu(MMI_ID inline_gid, U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (0 == srv_sim_ctrl_get_num_of_inserted())
    {
        cui_menu_set_item_disabled(inline_gid, menu_id, MMI_TRUE);
    }
    else
#endif
    {
    #if (MMI_MAX_SIM_NUM == 1)
      #ifdef __MMI_TELEPHONY_SUPPORT__
        if (!srv_sim_ctrl_is_available(MMI_SIM1) || !srv_mode_switch_is_network_service_available())
      #endif
        {
            cui_menu_set_item_hidden(inline_gid, menu_id, MMI_TRUE);
        }
    #else
        if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF || !srv_sim_ctrl_any_sim_is_available())
        {
            cui_menu_set_item_hidden(inline_gid, menu_id, MMI_TRUE);
        }
    #endif
    }
}


#ifdef __MMI_UDX_VCARD_SUPPORT__
U16 phb_udx_index[MMI_PHB_ENTRIES];

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_op_build_udx_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_op_build_udx_confirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (!mmi_udx_is_busy(MMI_TRUE) && !mmi_udx_is_reentry(MMI_TRUE))
    {
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.parent_id = group_id;
        arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;

        mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
        g_mmi_phb_confirm_user_data.sg_id = group_id;
        g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_mark_several_op_build_udx;

        arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

        mmi_confirm_display(
            (WCHAR *) get_string(STR_ID_PHB_MULTI_OP_UDX_BUILD_ASK),
            MMI_EVENT_QUERY,
            &arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_op_build_udx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_op_build_udx(MMI_ID group_id)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(phb_udx_index, 0xff, MMI_PHB_ENTRIES * 2);
    count = g_mmi_phb_list_p->mark_count;
    memcpy(phb_udx_index, g_mmi_phb_list_p->mark_array, count * 2);
    
    mmi_udx_building_launch(GRP_ID_ROOT, phb_udx_index, count, UDX_TYPE_VCARD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_udx_set_processing
 * DESCRIPTION
 *  when udx is busy with phonebook, set phonebook processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_udx_set_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_udx_reset_processing
 * DESCRIPTION
 *  after udx build or parse vcard, reset phonebook processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_udx_reset_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_FALSE;
}
#endif /* __MMI_UDX_VCARD_SUPPORT__ */


#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
#define MMI_PHB_SYNC_MENU
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sync_menu
 * DESCRIPTION
 *  entry sync menu from phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sync_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_96X64__
    gid = cui_syncml_app_sync_create(GRP_ID_PHB_SETTING, MMI_SYNCML_PHB_SYNC_MENU);
#else
	gid = cui_syncml_app_sync_create(GRP_ID_PHB_MAIN, MMI_SYNCML_PHB_SYNC_MENU);
#endif
    cui_syncml_app_sync_run(gid);
}
#endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */


#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speak_name_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_speak_name_handler(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_is_speaking_name = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_speak_name
 * DESCRIPTION
 *  Speak name or number for a phonebook entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_list_speak_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 text[(MMI_PHB_NAME_LENGTH + MMI_PHB_NUMBER_LENGTH + 10)];
    U16 length = 0;
    srv_prof_volume_level value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SILENT_MEETING_PROFILE__
    if (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED)
    {
        /**
         * not to play sound
         */
        return;
    }
#endif

    if (mmi_phb_get_speak_name() &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
        (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED))
    {
    #if defined(SIMPLE_TTS) || defined(DIGIT_TONE_SUPPORT)
        srv_phb_get_name(g_mmi_phb_list_p->store_index, text, (U16)(MMI_PHB_NAME_LENGTH + MMI_PHB_NUMBER_LENGTH + 10));
        length = mmi_wcslen(text);
    #endif
    
    #ifdef DIGIT_TONE_SUPPORT
        srv_phb_get_number(g_mmi_phb_list_p->store_index, (U16*)(text + length), (MMI_PHB_NUMBER_LENGTH + 1));
        length = mmi_wcslen(text);
    #endif
    
        if (length > 0)
        {
            mdi_result result = mdi_audio_play_text_with_vol_path(
                                    (U8*) text,
                                    length,
                                    100,
                                    mmi_phb_speak_name_handler,
                                    NULL,
                                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void *)&value),
                                    MDI_DEVICE_SPEAKER2);

            if (result == MDI_AUDIO_SUCCESS)
            {
                g_phb_is_speaking_name = 1;
            }
            else
            {
                g_phb_is_speaking_name = 0;
            }
        }
    }
}

void mmi_phb_speak_name_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_LIST_SPEAK_NAME_TIMER);
    if (g_phb_is_speaking_name)
    {
        mdi_audio_stop_string();
    }

    if (mmi_phb_get_speak_name())
    {
        StartTimer(PHB_LIST_SPEAK_NAME_TIMER, UI_POPUP_NOTIFYDURATION_TIME, mmi_phb_list_speak_name);
    }

}


void mmi_phb_speak_name_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_LIST_SPEAK_NAME_TIMER);
    if (g_phb_is_speaking_name)
    {
        mdi_audio_stop_string();
        g_phb_is_speaking_name = 0;
    }

}
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 


#define MMI_PHB_MULTI_OPERATION

#if defined(__MMI_PHB_SLIM_SETTING_MESS_OPERATION__) || defined(__MMI_PHB_MULTI_OPERATION__) || defined(__DM_LAWMO_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_multi_op_done
 * DESCRIPTION
 *  displays multi op result
 * PARAMETERS
 *  finish_count         [IN]
 *  total_count          [IN]
 *  canceled             [IN]
 *  action               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_multi_op_done(U16 finish_count, U16 total_count,MMI_BOOL canceled, U16 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR outBuf[50];
    CHAR count[10], count_ucs2[20];
    U16 str_id;
    MMI_BOOL finished = MMI_FALSE;
    mmi_event_notify_enum event_type = MMI_EVENT_FAILURE;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* trace for auto test */
    MMI_TRACE(MMI_COMMON_TRC_INFO, TRC_MMI_PHB_MULTI_OP_DONE, finish_count, total_count, canceled, action, g_phb_cntx_mgr.state);
    MMI_PHB_LOG5(TRC_MMI_PHB_MULTI_OP_DONE, finish_count, total_count, canceled, action, g_phb_cntx_mgr.state);

    g_phb_cntx_mgr.processing = MMI_FALSE;
    g_phb_cntx_mgr.state = 0;

    if (!mmi_frm_scrn_is_present(g_mmi_phb_op_cntx.sg_id, SCR_COPY_ALL_PROGRESS, MMI_FRM_NODE_ALL_FLAG)
        && !mmi_frm_scrn_is_present(g_mmi_phb_op_cntx.sg_id, SCR_IN_PROGRESS_PHB, MMI_FRM_NODE_ALL_FLAG))
    {
        return;
    }
    /**
     * Turn On Back Light When done 
     */
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    
    if (finish_count == total_count)
    {
        finished = MMI_TRUE;
    }

    /* Display result */
    memset(outBuf, 0, 2);
    
    if (canceled)
    {
        mmi_ucs2cpy((CHAR*)outBuf, GetString(STR_ID_PHB_CANCELLED));
        mmi_ucs2ncat((CHAR*)outBuf, (CHAR*)L"\r\n", 2);
    }
    
    sprintf(count, "%d ", finish_count);
    mmi_asc_to_ucs2(count_ucs2, count);
    mmi_ucs2cat((CHAR*)outBuf, count_ucs2);

    switch (action)
    {
        case MMI_PHB_OP_COPY_ALL:
        case MMI_PHB_OP_MULTI_COPY:
            if (finish_count <= 1)
            {
                str_id = STR_ENTRY_COPIED;
            }
            else
            {
                str_id = STR_ENTRIES_COPIED;
            }
            break;
            
        case MMI_PHB_OP_DELETE_ALL:
        case MMI_PHB_OP_MULTI_DELETE:
            if (finish_count <= 1)
            {
                str_id = STR_ID_PHB_ENTRY_DELETED;
            }
            else
            {
                str_id = STR_ID_PHB_ENTRIES_DELETED;
            }
            break;
            
        case MMI_PHB_OP_MOVE_ALL:
        case MMI_PHB_OP_MULTI_MOVE:
            if (finish_count <= 1)
            {
                str_id = STR_ID_PHB_ENTRY_MOVED;
            }
            else
            {
                str_id = STR_ID_PHB_ENTRIES_MOVED;
            }
            break;
            
        default:
            str_id = STR_GLOBAL_DONE;
            break;
    }
    
    mmi_ucs2cat((CHAR*)outBuf, GetString(str_id));
    
    if (canceled || finished)
    {
        event_type = MMI_EVENT_SUCCESS;
    }

    if (!finished)
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, event_type,(WCHAR*)outBuf);
    }
}


void mmi_phb_multi_op_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_op_cntx.canceled = MMI_TRUE;
    g_phb_cntx_mgr.processing = MMI_FALSE;

    /**
     * Cancel current multi operation
     */
    srv_phb_oplib_cancel_multi_op();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mass_processing_abort
 * DESCRIPTION
 *  abort function of processing screen. It will set up the abort flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mass_processing_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&key_code, &key_type);

    if (key_code == KEY_END)
    {
        mmi_idle_display();
    }

    mmi_phb_multi_op_cancel();
}

#endif


#if defined(__MMI_PHB_MULTI_OPERATION__)
void mmi_phb_op_mark_several_cb(U16 *contact_array, U16 finish_count, U16 total_count, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_struct *op_cntx = (mmi_phb_op_cntx_struct *) user_data;
    U16 index = 0;
    mmi_id sg_id = op_cntx->sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_cntx_mgr_controller(op_cntx->state, MMI_FALSE, NULL))
    {
        mmi_phb_cntx_mgr_refresh(op_cntx, contact_array, finish_count, 0xffff);
        
        mmi_phb_multi_op_done(
            finish_count,
            total_count,
            op_cntx->canceled,
            (U16)op_cntx->action);
        
    #ifdef __MMI_SNS_CONTACTS__
        if (op_cntx->action == MMI_PHB_OP_DELETE_ALL || op_cntx->action == MMI_PHB_OP_MULTI_DELETE)
        {
            srv_sns_phb_stop_multi_op();
        }
    #endif

        if (mmi_frm_scrn_is_present(sg_id, SCR_ID_PHB_MULTI_OP_PHB_LIST, MMI_FRM_NODE_ALL_FLAG))
        {
            if (finish_count == total_count)
            {
                mmi_frm_group_close(sg_id);
                mmi_frm_group_close(GRP_ID_PHB_OP_ALL);
            }
            else
            {
                memset(g_mmi_phb_list_p->bitmask, 0, (MMI_PHB_ENTRIES + 7) / 8);
                while (index < total_count - finish_count)
                {
                    mmi_phb_bitmask_set_state(g_mmi_phb_list_p->bitmask, contact_array[index++], MMI_TRUE);
                }
            }
        }

        mmi_frm_scrn_close(g_mmi_phb_op_cntx.sg_id, SCR_COPY_ALL_PROGRESS);
        mmi_frm_scrn_close(g_mmi_phb_op_cntx.sg_id, SCR_IN_PROGRESS_PHB);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_pre_build_option
 * DESCRIPTION
 *  build mark several main option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_mark_several_pre_build_option(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    if (!mmi_uc_is_uc_ready())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_MESSAGE, MMI_TRUE);
    }
#else
#if defined(__MMI_MMS__) &&  defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
    if (!mms_is_ready())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_MMS, MMI_TRUE);
    }
#endif /* defined(OBIGO_Q03C_MMS_V02) &&  defined(__MMI_MMS__) */
#endif /* __MMI_UNIFIED_COMPOSER__ */

#if defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__)
    if (!mmi_bt_is_to_display_bt_menu())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_VCARD, MMI_TRUE);
    }
#endif /* defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__) */

#if defined(__MMI_MULTI_VCARD__)
    if (!srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_PRE_BACKUP, MMI_TRUE);
    }
#endif /* defined(__MMI_MULTI_VCARD__) */
}
#endif


#ifdef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
void mmi_phb_op_all_cb(U16 finish_count, U16 total_count, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_struct *op_cntx = (mmi_phb_op_cntx_struct *) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_cntx_mgr_controller(op_cntx->state, MMI_FALSE, NULL))
    {
        mmi_phb_cntx_mgr_refresh(op_cntx, NULL, 0, 0xffff);
        
        mmi_phb_multi_op_done(
            finish_count,
            total_count,
            op_cntx->canceled,
            (U16)op_cntx->action);

        mmi_frm_scrn_close(g_mmi_phb_op_cntx.sg_id, SCR_COPY_ALL_PROGRESS);
        mmi_frm_scrn_close(g_mmi_phb_op_cntx.sg_id, SCR_IN_PROGRESS_PHB);

    #ifdef __MMI_SNS_CONTACTS__
        if (op_cntx->action == MMI_PHB_OP_DELETE_ALL)
        {            
            srv_sns_phb_stop_multi_op();
        }
    #endif

        switch (op_cntx->action)
        {
            case MMI_PHB_OP_COPY_ALL:                
            case MMI_PHB_OP_MOVE_ALL:
            case MMI_PHB_OP_DELETE_ALL:
                mmi_frm_group_close(GRP_ID_PHB_OP_ALL);
                break;
                
            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_copy_several_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phb_copy_several_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if MMI_MAX_SIM_NUM > 1
    U16 str_id = 0;
#endif
    S32 result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM > 1) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) 
    if (phb_op_all != MMI_FALSE)
    {
        return MMI_RET_DONT_CARE;
    }
#endif
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
        #if (MMI_MAX_SIM_NUM == 1) && !defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
            if (menu_evt->parent_menu_id == MENU_ID_PHB_COPY_SEVERAL)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            }
        #else
            if (menu_evt->parent_menu_id == MENU_ID_PHB_FROM_SIM)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            #if (MMI_MAX_SIM_NUM >= 2)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM1, STR_ID_PHB_FROM_SIM1);
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM2, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM2, STR_ID_PHB_FROM_SIM2);
            #else
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM_CARD, STR_ID_PHB_FROM_SIM);
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM3, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM3, STR_ID_PHB_FROM_SIM3);
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM4, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM4, STR_ID_PHB_FROM_SIM4);
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                mmi_phb_memory_card_not_available_hide_menu(mmi_phb_from_menu_id, MENU_ID_PHB_FROM_MEMORY_CARD);
            #endif
            }
            else if (menu_evt->parent_menu_id == MENU_ID_PHB_TO_SIM)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            #if (MMI_MAX_SIM_NUM >= 2)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM1, STR_ID_PHB_TO_SIM1);
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM2, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM2, STR_ID_PHB_TO_SIM2);
            #else
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM_CARD, STR_ID_PHB_TO_SIM);
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM3, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM3, STR_ID_PHB_TO_SIM3);
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM4, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM4, STR_ID_PHB_TO_SIM4);
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                mmi_phb_memory_card_not_available_hide_menu(mmi_phb_to_menu_id, MENU_ID_PHB_TO_MEMORY_CARD);
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                if ((from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM1)
                    || (from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM2)
                #if (MMI_MAX_SIM_NUM >= 3)
                    || (from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM3)
                #endif
                #if (MMI_MAX_SIM_NUM >= 4)
                    || (from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM4)
                #endif
                    )
                {
                    U32 index = (from_copy_move_menu_id - MENU_ID_PHB_FROM_SIM1);

                    cui_menu_set_item_hidden(mmi_phb_to_menu_id, (MENU_ID_PHB_TO_SIM1+ index), MMI_TRUE);
                }
            #else
                if (from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM_CARD)
                {
                    cui_menu_set_item_hidden(mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM_CARD, MMI_TRUE);
                }
            #endif
            
                if (from_copy_move_menu_id == MENU_ID_PHB_FROM_PHONE)
                {
                    cui_menu_set_item_hidden(mmi_phb_to_menu_id, MENU_ID_PHB_TO_PHONE, MMI_TRUE);
                }

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                if (from_copy_move_menu_id == MENU_ID_PHB_FROM_MEMORY_CARD)
                {
                    cui_menu_set_item_hidden(mmi_phb_to_menu_id, MENU_ID_PHB_TO_MEMORY_CARD, MMI_TRUE);
                }
            #endif
            }
        #endif
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
        #if (MMI_MAX_SIM_NUM >=2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) 
            if (menu_evt->parent_menu_id == MENU_ID_PHB_FROM_SIM)
            {
                from_copy_move_menu_id = menu_evt->highlighted_menu_id;
                switch (from_copy_move_menu_id)
                {
                    case MENU_ID_PHB_FROM_PHONE:
                        str_id = STR_ID_PHB_FROM_PHONE;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_NVRAM;
                        break;
                #if (MMI_MAX_SIM_NUM >=2)
                    case MENU_ID_PHB_FROM_SIM1:
                        str_id = STR_ID_PHB_FROM_SIM1;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM;
                        break;
                    case MENU_ID_PHB_FROM_SIM2:
                        str_id = STR_ID_PHB_FROM_SIM2;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM2;
                        break;
                #else
                    case MENU_ID_PHB_FROM_SIM_CARD:
                        str_id = STR_ID_PHB_FROM_SIM;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM;
                        break;
                #endif
                #if (MMI_MAX_SIM_NUM >= 3)
                    case MENU_ID_PHB_FROM_SIM3:
                        str_id = STR_ID_PHB_FROM_SIM3;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM3;
                        break;
                #endif
                #if (MMI_MAX_SIM_NUM >= 4)
                    case MENU_ID_PHB_FROM_SIM4:
                        str_id = STR_ID_PHB_FROM_SIM4;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM4;
                        break;
                #endif
                #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                    case MENU_ID_PHB_FROM_MEMORY_CARD:
                        str_id = STR_ID_PHB_FROM_MEMORY_CARD;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_TCARD;
                        break;
                #endif
                }
                mmi_phb_menu_create(GRP_ID_PHB_OP_ALL, MENU_ID_PHB_TO_SIM, str_id);
            }
            else if (menu_evt->parent_menu_id == MENU_ID_PHB_TO_SIM)
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_PHONE)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_NVRAM;
                }
            #if (MMI_MAX_SIM_NUM >= 2)
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM1)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM;
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM2)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM2;
                }
            #else
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM_CARD)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM;
                }
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM3)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM3;
                }
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM4)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM4;
                }
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_MEMORY_CARD)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_TCARD;
                }
            #endif
                mmi_phb_pre_entry_mark_several_copy(GRP_ID_PHB_OP_ALL);
            }
        #else
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_COPY_SIMTOPHONE)
            {
                g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM;
                g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_NVRAM;
                mmi_phb_pre_entry_mark_several_copy(GRP_ID_PHB_OP_ALL);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_COPY_PHONETOSIM)
            {
                g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_NVRAM;
                g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM;
                mmi_phb_pre_entry_mark_several_copy(GRP_ID_PHB_OP_ALL);
            }
        #endif
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_move_several_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phb_move_several_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if MMI_MAX_SIM_NUM > 1
    U16 str_id = 0;
#endif
    S32 result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM > 1) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) 
    if (phb_op_all != MMI_TRUE)
    {
        return MMI_RET_DONT_CARE;
    }
#endif
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
        #if (MMI_MAX_SIM_NUM == 1) && !defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
            if (menu_evt->parent_menu_id == MENU_ID_PHB_MOVE_SEVERAL)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);    
            }
        #else
            if (menu_evt->parent_menu_id == MENU_ID_PHB_FROM_SIM)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            #if (MMI_MAX_SIM_NUM >= 2)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM1, STR_ID_PHB_FROM_SIM1);
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM2, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM2, STR_ID_PHB_FROM_SIM2);
            #else
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM_CARD, STR_ID_PHB_FROM_SIM);
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM3, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM3, STR_ID_PHB_FROM_SIM3);
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM4, mmi_phb_from_menu_id, MENU_ID_PHB_FROM_SIM4, STR_ID_PHB_FROM_SIM4);
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                mmi_phb_memory_card_not_available_hide_menu(mmi_phb_from_menu_id, MENU_ID_PHB_FROM_MEMORY_CARD);
            #endif
            }
            else if (menu_evt->parent_menu_id == MENU_ID_PHB_TO_SIM)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            #if (MMI_MAX_SIM_NUM >= 2)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM1, STR_ID_PHB_TO_SIM1);
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM2, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM2, STR_ID_PHB_TO_SIM2);
            #else
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM_CARD, STR_ID_PHB_TO_SIM);
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM3, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM3, STR_ID_PHB_TO_SIM3);
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM4, mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM4, STR_ID_PHB_TO_SIM4);
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                mmi_phb_memory_card_not_available_hide_menu(mmi_phb_to_menu_id, MENU_ID_PHB_TO_MEMORY_CARD);
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                if ((from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM1)
                    || (from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM2)
                #if (MMI_MAX_SIM_NUM >= 3)
                    || (from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM3)
                #endif
                #if (MMI_MAX_SIM_NUM >= 4)
                    || (from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM4)
                #endif
                    )
                {
                    U32 index = (from_copy_move_menu_id - MENU_ID_PHB_FROM_SIM1);

                    cui_menu_set_item_hidden(mmi_phb_to_menu_id, (MENU_ID_PHB_TO_SIM1+ index), MMI_TRUE);
                }
            #else
                if (from_copy_move_menu_id == MENU_ID_PHB_FROM_SIM_CARD)
                {
                    cui_menu_set_item_hidden(mmi_phb_to_menu_id, MENU_ID_PHB_TO_SIM_CARD, MMI_TRUE);
                }
            #endif
            
                if (from_copy_move_menu_id == MENU_ID_PHB_FROM_PHONE)
                {
                    cui_menu_set_item_hidden(mmi_phb_to_menu_id, MENU_ID_PHB_TO_PHONE, MMI_TRUE);
                }

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                if (from_copy_move_menu_id == MENU_ID_PHB_FROM_MEMORY_CARD)
                {
                    cui_menu_set_item_hidden(mmi_phb_to_menu_id, MENU_ID_PHB_TO_MEMORY_CARD, MMI_TRUE);
                }
            #endif
            }
        #endif
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
        #if (MMI_MAX_SIM_NUM >=2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
            if (menu_evt->parent_menu_id == MENU_ID_PHB_FROM_SIM)
            {
                from_copy_move_menu_id = menu_evt->highlighted_menu_id;
                switch (from_copy_move_menu_id)
                {
                    case MENU_ID_PHB_FROM_PHONE:
                        str_id = STR_ID_PHB_FROM_PHONE;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_NVRAM;
                        break;
                #if (MMI_MAX_SIM_NUM >= 2)
                    case MENU_ID_PHB_FROM_SIM1:
                        str_id = STR_ID_PHB_FROM_SIM1;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM;
                        break;
                    case MENU_ID_PHB_FROM_SIM2:
                        str_id = STR_ID_PHB_FROM_SIM2;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM2;
                        break;
                #else
                    case MENU_ID_PHB_FROM_SIM_CARD:
                        str_id = STR_ID_PHB_FROM_SIM;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM;
                        break;
                #endif
                #if (MMI_MAX_SIM_NUM >= 3)
                    case MENU_ID_PHB_FROM_SIM3:
                        str_id = STR_ID_PHB_FROM_SIM3;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM3;
                        break;
                #endif
                #if (MMI_MAX_SIM_NUM >= 4)
                    case MENU_ID_PHB_FROM_SIM4:
                        str_id = STR_ID_PHB_FROM_SIM4;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM4;
                        break;
                #endif
                #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                    case MENU_ID_PHB_FROM_MEMORY_CARD:
                        str_id = STR_ID_PHB_FROM_MEMORY_CARD;
                        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_TCARD;
                        break;
                #endif
                }
                mmi_phb_menu_create(GRP_ID_PHB_OP_ALL, MENU_ID_PHB_TO_SIM, str_id);
            }
            else if (menu_evt->parent_menu_id == MENU_ID_PHB_TO_SIM)
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_PHONE)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_NVRAM;
                }
            #if (MMI_MAX_SIM_NUM >= 2)
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM1)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM;
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM2)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM2;
                }
            #else
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM_CARD)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM;
                }
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM3)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM3;
                }
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_SIM4)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM4;
                }
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_TO_MEMORY_CARD)
                {
                    g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_TCARD;
                }
            #endif
                mmi_phb_pre_entry_mark_several_move(GRP_ID_PHB_OP_ALL);
            }
        #else
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MOVE_SIMTOPHONE)
            {
                g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM;
                g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_NVRAM;
                mmi_phb_pre_entry_mark_several_move(GRP_ID_PHB_OP_ALL);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MOVE_PHONETOSIM)
            {
                g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_NVRAM;
                g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_SIM;
                mmi_phb_pre_entry_mark_several_move(GRP_ID_PHB_OP_ALL);
            }
        #endif
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_several_menu_cui_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_phb_delete_several_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    MMI_ID menu_gid = menu_evt->sender_id;
    S32 result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_PHB_DELETE_ALL)
            {
                cui_menu_set_currlist_flags(menu_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            #if (MMI_MAX_SIM_NUM >= 2)
                mmi_phb_new_entry_choose_storage_check(menu_evt->sender_id, MENU_ID_PHB_DELETE_ALL_SIM, STR_ID_PHB_FROM_SIM1);
            #else
                mmi_phb_new_entry_choose_storage_check(menu_evt->sender_id, MENU_ID_PHB_DELETE_ALL_SIM, STR_ID_PHB_FROM_SIM);
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                mmi_phb_memory_card_not_available_hide_menu(menu_gid, MENU_ID_PHB_DELETE_ALL_MEMORY_CARD);
            #endif
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;

            switch(highlighted_menu_id)
            {
                case MENU_ID_PHB_DELETE_ALL_PHONE:
                    g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_NVRAM;
                    break;

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_ID_PHB_DELETE_ALL_MEMORY_CARD:
                    g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_TCARD;
                    break;
            #endif
                        
                case MENU_ID_PHB_DELETE_ALL_SIM:
                    g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM;
                    break;
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_PHB_DELETE_ALL_SIM2:
                    g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM2;
                    break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_PHB_DELETE_ALL_SIM3:
                 g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM3;
                    break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_PHB_DELETE_ALL_SIM4:
                    g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM4;
                    break;
            #endif
                default:
                     g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM;
                    break;
            }

        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            if (mmi_phb_memory_card_is_ready((phb_storage_enum)g_mmi_phb_op_cntx.src_storage, MMI_TRUE))
        #endif
            {
                if (srv_phb_get_used_contact(g_mmi_phb_op_cntx.src_storage))
                {
                    mmi_phb_pre_entry_delete_all_confirm(GRP_ID_PHB_OP_ALL);
                }
                else
                {
                    mmi_popup_display_simple_ext(
                        STR_ID_PHB_NO_ENTRY_TO_SELECT,
                        MMI_EVENT_FAILURE,
                        GRP_ID_PHB_OP_ALL,
                        0);
                }
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


static mmi_ret mmi_phb_op_all_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret menu_cui_proc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_proc = mmi_phb_copy_several_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }

    menu_cui_proc = mmi_phb_move_several_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }

    menu_cui_proc = mmi_phb_delete_several_menu_cui_proc(evt);
    if (menu_cui_proc == MMI_RET_OK) 
    {
        return MMI_RET_OK;
    }
    
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            if (mmi_frm_scrn_get_count(GRP_ID_PHB_OP_ALL) == 0)
            {
                mmi_frm_group_close(GRP_ID_PHB_OP_ALL);
            }
            break;
        }

    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        case EVT_ID_GROUP_DEINIT:
        {
            if (g_mmi_phb_mess_operation_title)
            {
                mmi_phb_mem_free(g_mmi_phb_mess_operation_title);
                g_mmi_phb_mess_operation_title = NULL;
            }
            break;
        }
    #endif

    #if defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)
        case EVT_ID_CUI_VERIFY_RESULT:
        {
            cui_verify_result_evt_struct *data;
            data = (cui_verify_result_evt_struct*)evt;
            if (data->success)
            {
                mmi_phb_delete_all_verify_phone_lock();
                cui_verify_close(data->sender_id);
            }
            break;
        }
        case EVT_ID_CUI_VERIFY_CANCEL:
        {
            cui_verify_cancel_evt_struct *data;
            data = (cui_verify_cancel_evt_struct*)evt;
            cui_verify_close(data->sender_id);
            break;
        }
    #endif
        default:
            break;
    }
 
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_move_several
 * DESCRIPTION
 *  Entry fuction of mark several main
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_move_several(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    mmi_id menu_gid;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    if (mmi_phb_check_storage_status(PHB_STORAGE_MAX, MMI_PHB_CHECK_STORAGE_BOTH, MMI_TRUE))
    {
        return;
    }
#if (MMI_MAX_SIM_NUM > 1)
    mmi_phb_menu_create(
                GRP_ID_PHB_OP_ALL,
                MENU_ID_PHB_FROM_SIM,
                STR_ID_PHB_MOVE_SEVERAL);
#else

    menu_gid = cui_menu_create_and_run(
               GRP_ID_PHB_OP_ALL,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_APPSUB,
               MENU_ID_PHB_MOVE_SEVERAL,
               MMI_FALSE, NULL);

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);   
#endif
}


void mmi_phb_group_move_several(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

#if (MMI_MAX_SIM_NUM >=2)
    if (!srv_phb_check_storage_accessible(PHB_STORAGE_SIM) && !srv_phb_check_storage_accessible(PHB_STORAGE_SIM2)
#if (MMI_MAX_SIM_NUM >= 3)
        && !srv_phb_check_storage_accessible(PHB_STORAGE_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
         && !srv_phb_check_storage_accessible(PHB_STORAGE_SIM4)
#endif
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
         && !srv_phb_check_storage_accessible(PHB_STORAGE_TCARD)
#endif
    )
#else
    if (!srv_phb_check_storage_accessible(PHB_STORAGE_SIM)
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        && !srv_phb_check_storage_accessible(PHB_STORAGE_TCARD)
#endif
    )
#endif
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_SETTING,
            NULL);
        return;
    }

    if (mmi_phb_op_all_check_storage_status(PHB_STORAGE_MAX, MMI_PHB_CHECK_STORAGE_BOTH, MMI_TRUE, GRP_ID_PHB_SETTING))
    {
        return;
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    g_mmi_phb_mess_operation_title = (WCHAR *)mmi_phb_mem_malloc(sizeof(WCHAR) * MMI_PHB_MAX_DYNAMIC_SIM_NAME_LENGTH, SRV_PHB_MEMORY_TYPE_CTR);
#endif

#ifndef __MMI_MAINLCD_96X64__
    mmi_frm_group_create_ex(
        GRP_ID_PHB_SETTING,
        GRP_ID_PHB_OP_ALL,
        mmi_phb_op_all_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
mmi_frm_group_create_ex(
        GRP_ID_PHB_MAIN,
        GRP_ID_PHB_OP_ALL,
        mmi_phb_op_all_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
#endif

#if (MMI_MAX_SIM_NUM > 1) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) 
    phb_op_all = MMI_TRUE;
#endif
    

    mmi_phb_entry_move_several();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_copy_several
 * DESCRIPTION
 *  Entry fuction of mark several main
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_copy_several(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    mmi_id menu_gid;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    if (mmi_phb_check_storage_status(PHB_STORAGE_MAX, MMI_PHB_CHECK_STORAGE_BOTH, MMI_TRUE))
    {
        return;
    }

#if (MMI_MAX_SIM_NUM > 1)
    mmi_phb_menu_create(
                    GRP_ID_PHB_OP_ALL,
                    MENU_ID_PHB_FROM_SIM,
                    STR_ID_PHB_COPY_SEVERAL);
#else
    	menu_gid = cui_menu_create_and_run(
               GRP_ID_PHB_OP_ALL,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_APPSUB,
               MENU_ID_PHB_COPY_SEVERAL,
               MMI_FALSE, NULL);

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);
#endif
}


#if (MMI_MAX_SIM_NUM > 1)
static void mmi_phb_menu_create(mmi_id gid, mmi_menu_id root_menu_id, U16 str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_sim_enum mmi_sim = MMI_SIM_NONE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (from_copy_move_menu_id != MENU_ID_PHB_FROM_PHONE &&
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        from_copy_move_menu_id != MENU_ID_PHB_FROM_MEMORY_CARD &&
#endif
        root_menu_id == MENU_ID_PHB_TO_SIM)
    {
         mmi_sim = MMI_SIM1 << (g_mmi_phb_op_cntx.src_storage - PHB_STORAGE_SIM);
    }
    
    menu_gid = cui_menu_create(
               gid,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_APPSUB,
               root_menu_id,
               MMI_FALSE, NULL);

    if (mmi_sim)
    {
        mmi_phb_sim_dynamic_name_simx_title(mmi_sim, menu_gid, str, g_mmi_phb_mess_operation_title);
    }
    else
    {
        cui_menu_set_default_title_by_id(menu_gid, str, IMG_SCR_PBOOK_CAPTION);
    }    
#else
    menu_gid = cui_menu_create(
               gid,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_APPSUB,
               root_menu_id,
               MMI_FALSE, NULL);

    cui_menu_set_default_title_by_id(
        menu_gid,
        str, 
        IMG_SCR_PBOOK_CAPTION);
#endif
    
    if (root_menu_id == MENU_ID_PHB_FROM_SIM)
    {
        mmi_phb_from_menu_id = menu_gid;
    }
    else if (root_menu_id == MENU_ID_PHB_TO_SIM)
    {
        mmi_phb_to_menu_id = menu_gid;
    }
    cui_menu_run(menu_gid);
}
#endif


void mmi_phb_group_copy_several(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    if (!srv_phb_check_storage_accessible(PHB_STORAGE_SIM) && !srv_phb_check_storage_accessible(PHB_STORAGE_SIM2)
#if (MMI_MAX_SIM_NUM >= 3)
        && !srv_phb_check_storage_accessible(PHB_STORAGE_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        && !srv_phb_check_storage_accessible(PHB_STORAGE_SIM4)
#endif
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        && !srv_phb_check_storage_accessible(PHB_STORAGE_TCARD)
#endif
    )
#else
    if (!srv_phb_check_storage_accessible(PHB_STORAGE_SIM)
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        && !srv_phb_check_storage_accessible(PHB_STORAGE_TCARD)
#endif
    )
#endif
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_SETTING,
            NULL);
        return;
    } 
    if (mmi_phb_op_all_check_storage_status(PHB_STORAGE_MAX, MMI_PHB_CHECK_STORAGE_BOTH, MMI_TRUE, GRP_ID_PHB_SETTING))
    {
        return;
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    g_mmi_phb_mess_operation_title = (WCHAR *)mmi_phb_mem_malloc(sizeof(WCHAR) * MMI_PHB_MAX_DYNAMIC_SIM_NAME_LENGTH, SRV_PHB_MEMORY_TYPE_CTR);
#endif
#ifndef __MMI_MAINLCD_96X64__

    mmi_frm_group_create_ex(
        GRP_ID_PHB_SETTING,
        GRP_ID_PHB_OP_ALL, 
        mmi_phb_op_all_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
mmi_frm_group_create_ex(
        GRP_ID_PHB_MAIN,
        GRP_ID_PHB_OP_ALL, 
        mmi_phb_op_all_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

#endif
#if (MMI_MAX_SIM_NUM > 1) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) 
    phb_op_all = MMI_FALSE;
#endif
    
    
    mmi_phb_entry_copy_several();
}


#if defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_all_verify_phone_lock_ext
 * DESCRIPTION
 *  Call security function to check phone lock. Also provide call back function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_delete_all_verify_phone_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_delete_all_pre_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_all_phone_lock_ext
 * DESCRIPTION
 *  check phone lock before delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_delete_all_phone_lock(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID instance_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    instance_id = cui_verify_create(group_id, CUI_VERIFY_TYPE_PHONE_PASSWORD);
    cui_verify_run(instance_id);
}
#else /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_all_confirm
 * DESCRIPTION
 *  Confirms before deleting all entries from the selected storage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_delete_all_confirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = STR_GLOBAL_DELETE_ALL_ASK;
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = group_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;
    arg.f_auto_map_empty_softkey = MMI_FALSE;

    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = group_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_delete_all_pre_req_ext;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

    mmi_confirm_display(
        (WCHAR *) get_string(str_id),
        MMI_EVENT_QUERY,
        &arg);

}
#endif /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_all_ext
 * DESCRIPTION
 *  Entry fuction of delete all contacts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_DELETE_ALL);
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
    if (srv_phb_get_used_contact(PHB_STORAGE_MAX) == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_CONTACT,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_OP_ALL,
            NULL);

        return;
    }

   menu_gid = cui_menu_create_and_run(
               GRP_ID_PHB_OP_ALL,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_APPSUB,
               MENU_ID_PHB_DELETE_ALL,
               MMI_FALSE, NULL);

    
    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_delete_all_no_sim
 * DESCRIPTION
 *  Draws the Delete All menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_delete_all_no_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_DELETE_ALL);
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
    if (srv_phb_get_used_contact(PHB_STORAGE_NVRAM))
    {
        /**
         * entry new group
         */
#ifndef __MMI_MAINLCD_96X64__
        mmi_frm_group_create_ex(
            GRP_ID_PHB_SETTING,
            GRP_ID_PHB_OP_ALL, 
            mmi_phb_op_all_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
        mmi_frm_group_create_ex(
            GRP_ID_PHB_MAIN,
            GRP_ID_PHB_OP_ALL, 
            mmi_phb_op_all_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);


#endif

        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_NVRAM;
        mmi_phb_pre_entry_delete_all_confirm(GRP_ID_PHB_OP_ALL);
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_ID_PHB_NO_CONTACT,
            MMI_EVENT_FAILURE);
    }
}


void mmi_phb_group_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_DELETE_ALL);
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
    if (srv_phb_get_used_contact(PHB_STORAGE_MAX) == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_CONTACT,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_SETTING,
            0);

        return;
    }
    
#ifndef __MMI_MAINLCD_96X64__ 
    mmi_frm_group_create_ex(
        GRP_ID_PHB_SETTING,
        GRP_ID_PHB_OP_ALL, 
        mmi_phb_op_all_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
    mmi_frm_group_create_ex(
        GRP_ID_PHB_MAIN,
        GRP_ID_PHB_OP_ALL, 
        mmi_phb_op_all_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

#endif
    
    mmi_phb_entry_delete_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_delete_all_confirm_ext
 * DESCRIPTION
 *  check before delete all confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_pre_entry_delete_all_confirm(MMI_ID group_id) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_check_storage_accessible(g_mmi_phb_op_cntx.src_storage))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_OP_ALL,
            0);
    }
    else
    {
    #if defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)
        mmi_phb_entry_delete_all_phone_lock(group_id);
    #else /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__) */ 
        mmi_phb_entry_delete_all_confirm(group_id);
    #endif /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)*/
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_mark_several_copy
 * DESCRIPTION
 *  pre Entry fuction of mark several copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_pre_entry_mark_several_copy(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                          */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_MULTI_OPERATION__)
    mmi_id new_sg_id;
    U32 handle;    
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_id sg_id = GRP_ID_PHB_OP_ALL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (!mmi_phb_memory_card_is_ready((phb_storage_enum)g_mmi_phb_op_cntx.dst_storage, MMI_TRUE) ||
        !mmi_phb_memory_card_is_ready((phb_storage_enum)g_mmi_phb_op_cntx.src_storage, MMI_TRUE)
        )
    {
        return;    
    }
#endif

    if (!srv_phb_check_storage_accessible(g_mmi_phb_op_cntx.src_storage) || !srv_phb_check_storage_accessible(g_mmi_phb_op_cntx.dst_storage))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            GRP_ID_PHB_OP_ALL,
            0);
        return;
    }

    if (mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.src_storage, MMI_PHB_CHECK_STORAGE_EMPTY, MMI_TRUE, GRP_ID_PHB_OP_ALL)
        || mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.dst_storage, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE, GRP_ID_PHB_OP_ALL))
    {
        return;
    }
    
#if defined(__MMI_PHB_MULTI_OPERATION__)
    handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_MARK_SEVERAL);
    new_sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
    mmi_phb_cntx_mgr_set_parent_id(handle, sg_id);
    list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT);
    
    list_cntx->sg_id = new_sg_id;
    list_cntx->parent_id = sg_id;
    list_cntx->storage = g_mmi_phb_op_cntx.src_storage;
    mmi_phb_cntx_mgr_set_data(handle, list_cntx);

    cui_phb_list_select_contact_set_cntx(list_cntx);
    
    mmi_frm_group_create_ex(
        sg_id,
        new_sg_id, 
        cui_phb_list_select_contact_proc,
        list_cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_phb_entry_mark_several_copy();
#else /* defined(__MMI_PHB_MULTI_OPERATION__) */
    mmi_phb_op_copy_all_confirm(group_id);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_mark_several_move
 * DESCRIPTION
 *  pre Entry fuction of mark several move
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_pre_entry_mark_several_move(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_MULTI_OPERATION__)
    mmi_id new_sg_id;
    U32 handle;    
    mmi_phb_list_cntx_struct *list_cntx;
#endif
    mmi_id sg_id = group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (!mmi_phb_memory_card_is_ready((phb_storage_enum)g_mmi_phb_op_cntx.dst_storage, MMI_TRUE) ||
        !mmi_phb_memory_card_is_ready((phb_storage_enum)g_mmi_phb_op_cntx.src_storage, MMI_TRUE)
        )
    {
        return;    
    }
#endif
    
    if (!srv_phb_check_storage_accessible(g_mmi_phb_op_cntx.src_storage) || !srv_phb_check_storage_accessible(g_mmi_phb_op_cntx.dst_storage))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            sg_id,
            NULL);
        return;
    }

    if (mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.src_storage, MMI_PHB_CHECK_STORAGE_EMPTY, MMI_TRUE, GRP_ID_PHB_OP_ALL)
        || mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.dst_storage, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE, GRP_ID_PHB_OP_ALL))
    {
        return;
    }
    
#if defined(__MMI_PHB_MULTI_OPERATION__)
    handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_MARK_SEVERAL);
    new_sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
    mmi_phb_cntx_mgr_set_parent_id(handle, sg_id);
    list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT);
    
    list_cntx->sg_id = new_sg_id;
    list_cntx->parent_id = sg_id;
    list_cntx->storage = g_mmi_phb_op_cntx.src_storage;
    mmi_phb_cntx_mgr_set_data(handle, list_cntx);

    cui_phb_list_select_contact_set_cntx(list_cntx);
    
    mmi_frm_group_create_ex(
        sg_id,
        new_sg_id, 
        cui_phb_list_select_contact_proc,
        list_cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_phb_entry_mark_several_move();
#else
    mmi_phb_op_move_all_confirm(group_id);
#endif
}


#if defined(__MMI_PHB_MULTI_OPERATION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_copy
 * DESCRIPTION
 *  Entry fuction of mark several vopy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_mark_several_build_op_func = mmi_phb_mark_several_copy_build_option;

    mmi_phb_entry_mark_several_list(
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        SCR_ID_PHB_MULTI_OP_PHB_LIST,
        mmi_phb_entry_mark_several_option,
        mmi_phb_mark_several_check,
        mmi_phb_entry_mark_several_copy);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_move
 * DESCRIPTION
 *  Entry fuction of mark several move
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_mark_several_build_op_func = mmi_phb_mark_several_move_build_option;

    mmi_phb_entry_mark_several_list(
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        SCR_ID_PHB_MULTI_OP_PHB_LIST,
        mmi_phb_entry_mark_several_option,
        mmi_phb_mark_several_check,
        mmi_phb_entry_mark_several_move);

}

#endif /* __MMI_PHB_MULTI_OPERATION__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_move_all_get_coinfirm_str
 * DESCRIPTION
 *  confirm mark several copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_op_copy_move_all_get_confirm_str(U16 dst_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (dst_storage == PHB_STORAGE_SIM)
    {
        str_id = STR_ID_PHB_TO_SIM1;
    }
    else if (dst_storage == PHB_STORAGE_SIM2)
    {
        str_id = STR_ID_PHB_TO_SIM2;
    }
#if (MMI_MAX_SIM_NUM >=3)
    else if (dst_storage == PHB_STORAGE_SIM3)
    {
        str_id = STR_ID_PHB_TO_SIM3;
    }
#endif
#if (MMI_MAX_SIM_NUM >=4)
    else if (dst_storage == PHB_STORAGE_SIM4)
    {
        str_id = STR_ID_PHB_TO_SIM4;
    }
#endif
#else 
    if (dst_storage == PHB_STORAGE_SIM)
    {
        str_id = STR_ID_PHB_TO_SIM;        
    }
#endif
    else
    {
        str_id = STR_ID_PHB_TO_PHONE;
    }

    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_copy_all_req
 * DESCRIPTION
 *  confirm mark several copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_copy_all_req(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_mass_processing(
        group_id,
        STR_GLOBAL_COPYING,
        srv_phb_get_used_contact(g_mmi_phb_op_cntx.src_storage));

    mmi_phb_copy_all_pre_req(group_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_all_coinfirm
 * DESCRIPTION
 *  confirm mark several copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_all_confirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.src_storage, MMI_PHB_CHECK_STORAGE_EMPTY, MMI_TRUE, GRP_ID_PHB_OP_ALL)
        || mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.dst_storage, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE, GRP_ID_PHB_OP_ALL))
    {
        return;
    }
    str_id = mmi_phb_op_copy_move_all_get_confirm_str(g_mmi_phb_op_cntx.dst_storage);

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = group_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;

    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = group_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_copy_all_req;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

    mmi_confirm_display(
        (WCHAR *) get_string(str_id),
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_copy_all_pre_req
 * DESCRIPTION
 *  copy all interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_copy_all_pre_req(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_COPY_MULTI;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_COPY_ALL;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_COPY_MULTI;
    g_mmi_phb_op_cntx.sg_id = group_id;
    
    srv_phb_oplib_copy_all_contact(
        g_mmi_phb_op_cntx.src_storage,
        g_mmi_phb_op_cntx.dst_storage,
        mmi_phb_op_all_cb,
        &g_mmi_phb_op_cntx);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_move_all_pre_req
 * DESCRIPTION
 *  copy all interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_move_all_pre_req(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_COPY_MULTI;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_MOVE_ALL;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_COPY_MULTI;
    g_mmi_phb_op_cntx.sg_id = group_id;

    mmi_phb_show_mass_processing(
        g_mmi_phb_op_cntx.sg_id,
        STR_GLOBAL_MOVING,
        srv_phb_get_used_contact(g_mmi_phb_op_cntx.src_storage));
    mmi_frm_scrn_close(g_mmi_phb_op_cntx.sg_id, SCR_ID_PHB_MOVE_SEVERAL);
    
    srv_phb_oplib_move_all_contact(
        g_mmi_phb_op_cntx.src_storage,
        g_mmi_phb_op_cntx.dst_storage,
        mmi_phb_op_all_cb,
        &g_mmi_phb_op_cntx);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_move_all_coinfirm
 * DESCRIPTION
 *  confirm mark several copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_move_all_confirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.src_storage, MMI_PHB_CHECK_STORAGE_EMPTY, MMI_TRUE, GRP_ID_PHB_OP_ALL)
        || mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.dst_storage, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE, GRP_ID_PHB_OP_ALL))
    {
        mmi_frm_scrn_close(group_id, SCR_ID_PHB_MOVE_SEVERAL);
        return;
    }
    str_id = mmi_phb_op_copy_move_all_get_confirm_str(g_mmi_phb_op_cntx.dst_storage);

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = group_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;

    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = group_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_move_all_pre_req;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

    mmi_confirm_display(
        (WCHAR *) get_string(str_id),
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_all_pre_req_ext
 * DESCRIPTION
 *  delete all interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_delete_all_pre_req_ext(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_DELETE_MULTI;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_DELETE_ALL;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_DELETE_MULTI;
    g_mmi_phb_op_cntx.sg_id = group_id;

    mmi_phb_show_mass_processing(
        g_mmi_phb_op_cntx.sg_id,
        STR_GLOBAL_DELETING,
        srv_phb_get_used_contact(g_mmi_phb_op_cntx.src_storage));

#ifdef __MMI_SNS_CONTACTS__
    srv_sns_phb_start_multi_op();
#endif

    srv_phb_oplib_delete_all_contact(
        g_mmi_phb_op_cntx.src_storage,
        mmi_phb_op_all_cb,
        &g_mmi_phb_op_cntx);
}


static void mmi_phb_delete_all_pre_req(void)
{
    mmi_phb_delete_all_pre_req_ext(GRP_ID_PHB_OP_ALL);
}
#endif /*__MMI_PHB_SLIM_SETTING_MESS_OPERATION__ */


#define MMI_PHB_SINGLE_OPERATION
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_main_list_menu_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_phb_main_menu_op_start(mmi_phb_op_action_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_action_cntx_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_init(&op_cntx);
    op_cntx.store_index = g_mmi_phb_list_p->store_index;
    op_cntx.op_action = op;    
    mmi_phb_op_start(&op_cntx, GRP_ID_PHB_MAIN);
}


#ifdef __MMI_SNS_CONTACTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_link_not_ready_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_sns_link_not_ready_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_ready_struct *ready = (srv_sns_evt_ready_struct *)evt;
    MMI_ID gid = (MMI_ID)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ready->is_ready)
    {
        cui_sns_friend_link_close(gid);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_link_not_ready_proc, (void *)gid);
        g_mmi_phb_sns_misc.sns_cui_link = GRP_ID_INVALID;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_filter_not_ready_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_sns_filter_not_ready_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_ready_struct *ready = (srv_sns_evt_ready_struct *)evt;
    MMI_ID gid = (MMI_ID)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ready->is_ready)
    {
        cui_sns_filter_close(gid);
        g_mmi_phb_list_p->sns_friend_list->is_valid = MMI_TRUE;
        mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_filter_not_ready_proc, (void *)gid);
        g_mmi_phb_sns_misc.sns_cui_filter = GRP_ID_INVALID;
    }

    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_main_list_menu_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
#ifndef __MMI_MAINLCD_96X64__
mmi_ret mmi_phb_main_list_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SNS_CONTACTS__
	mmi_id sns_gid;
#endif
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    S32 result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {            
            if (menu_evt->parent_menu_id == MITEM1013_PBOOK_COPY_ENTRY)
            {
                mmi_phb_entry_op_copy_menu(GRP_ID_PHB_MAIN, menu_evt->sender_id);
            }
        #ifndef LOW_COST_SUPPORT
        #if (MMI_MAX_SIM_NUM >= 2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
        #ifndef __MMI_PHB_SLIM_NEW__
            else if (menu_evt->parent_menu_id == MITEM1014_PBOOK_MOVE)
		#else
			if (menu_evt->parent_menu_id == MITEM1014_PBOOK_MOVE)
		#endif
            {
                mmi_phb_entry_op_move_menu(menu_evt->sender_id);
            }
        #endif
        #endif
		    #ifndef __MMI_PHB_SLIM_NEW__
            else if (menu_evt->parent_menu_id == MITEM101_PBOOK_VIEW_OPTIONS)
			#else
			if (menu_evt->parent_menu_id == MITEM101_PBOOK_VIEW_OPTIONS)
			#endif
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_PHB_ADD_NEW_ENTRY_SELECT, MMI_FALSE);
                cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_PHB_SETTINGS, MMI_FALSE);
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PHB_ADD_NEW_ENTRY_SELECT:
                    mmi_phb_op_add_new_entry_ext(GRP_ID_PHB_MAIN);
                    break;
                    
                case MENU_ID_PHB_VIEW_CONTACT:
                    cui_phb_view_contact(g_mmi_phb_list_p->sg_id, g_mmi_phb_list_p->store_index);
                    break;

	        #ifdef __MMI_SNS_CONTACTS__
		        case MENU_ID_PHB_SNS_LINK:
		        sns_gid = cui_sns_friend_link_create(g_mmi_phb_list_p->sg_id, g_mmi_phb_list_p->store_index);
		        if (GRP_ID_INVALID != sns_gid)
		        { 
                    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_link_not_ready_proc, (void *)sns_gid);
                    g_mmi_phb_sns_misc.sns_cui_link = sns_gid;
		            cui_sns_friend_link_run(sns_gid);
                }    
		        break;

                case MENU_ID_PHB_SNS_UNLINK:
                    mmi_phb_sns_view_unlink(g_mmi_phb_list_p->store_index, g_mmi_phb_list_p->sg_id);
                    break;

	            case MENU_ID_PHB_SNS_FRIEND_VIEW:
		            mmi_phb_sns_entry_view_member(MMI_PHB_SNS_LIST_FRIEND);
		            break;

		        case MENU_ID_PHB_SNS_FAVORITE_VIEW:
		            mmi_phb_sns_entry_view_member(MMI_PHB_SNS_LIST_FAVORITE);
		            break;

		        case MENU_ID_PHB_SNS_FRIEND_FILTER:
		            sns_gid = cui_sns_filter_create_ex(g_mmi_phb_list_p->sg_id, CUI_SNS_FILTER_FRIEND_LIST);
                    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_filter_not_ready_proc, (void *)sns_gid);
		            g_mmi_phb_list_p->sns_friend_list->is_valid = MMI_FALSE;
                    g_mmi_phb_sns_misc.sns_cui_filter = sns_gid;
		            break;

            #ifdef __MMI_SNS_MESSAGES__
        		case MENU_ID_PHB_SNS_FRIEND_DIRECT_MESSAGE:
        		    mmi_phb_sns_entry_send_msg(MMI_PHB_SNS_LIST_FRIEND);
        		    break;

        	    case MENU_ID_PHB_SNS_FAVORITE_DIRECT_MESSAGE:
        		    mmi_phb_sns_entry_send_msg(MMI_PHB_SNS_LIST_FAVORITE);
        		    break;
            #endif

        		case MENU_ID_PHB_SNS_FRIEND_ADD_FAVORITE:
        		    mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FRIEND, MMI_TRUE);
        		    cui_menu_close(menu_evt->sender_id);
        		    break;

        		case MENU_ID_PHB_SNS_FRIEND_REMOVE_FAVORITE:
        		    mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FRIEND, MMI_FALSE);
        		    cui_menu_close(menu_evt->sender_id);
        		    break;

        		case MENU_ID_PHB_SNS_FAVORITE_REMOVE:
        		    mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FAVORITE, MMI_FALSE);
        		    cui_menu_close(menu_evt->sender_id);
        		    break;
        	#endif
					
            #if defined(__MMI_VIDEO_TELEPHONY__)
                case MENU_ID_PHB_SET_VT_CALL:
                        srv_phb_set_vt_call(g_mmi_phb_list_p->store_index, MMI_TRUE);
                        cui_menu_close(menu_evt->sender_id);
                        break;
                case MENU_ID_PHB_CANCEL_VT_CALL:
                        srv_phb_set_vt_call(g_mmi_phb_list_p->store_index, MMI_FALSE);
                        cui_menu_close(menu_evt->sender_id);
                        break;
            #endif

            #ifdef __MMI_UNIFIED_COMPOSER__
                case MENU_ID_PHB_OPTION_SEND_MESSAGE:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_MSG);
                    break;
                }
            #else /* __MMI_UNIFIED_COMPOSER__ */
            
                case MENU_ID_PHB_OPTION_SEND_SMS:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_SMS);
                    break;
                }
                
            #if defined(__MMI_MMS__)&& !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
                case MENU_ID_PHB_OPTION_SEND_MMS:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_MMS);
                    break;
                }
            #endif /* __MMI_MMS__ */
            #endif /* __MMI_UNIFIED_COMPOSER__ */

                case MENU_ID_PHB_OPTION_DIAL:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_CALL);
                    break;
                }
            #if defined(__IP_NUMBER__)
                case MENU_ID_PHB_OPTION_IP_DIAL:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_IP_CALL);
                    break;
                }
            #endif
            
            #if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
                case MENU_ID_PHB_OPTION_SEND_POSTCARD:
                    mmi_phb_op_send_postcard();
                    break;
            #endif /* defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__) */
            
                case MITEM1011_PBOOK_EDIT:
					#if 0
                    #if defined(__OP12__)
/* under construction !*/
                    #else
/* under construction !*/
                    #endif
					#else
					    mmi_phb_op_edit_pre_entry_ext(GRP_ID_PHB_MAIN);
					#endif
                    break;
            #if 0
            #if defined(__OP12__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #endif
            
                case MITEM1012_PBOOK_DELETE:
                    mmi_phb_entry_op_delete_confirm(GRP_ID_PHB_MAIN);
                    break;
                    
                case MITEM1013_PBOOK_COPY_ENTRY:
                    break;

                case MENU_ID_PHB_COPY_TO_PHONE:
                    mmi_phb_entry_op_copy_to_phone_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_NVRAM);
                    break;
                    
                case MENU_ID_PHB_COPY_TO_SIM:
                    mmi_phb_entry_op_copy_to_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM);
                    break;
                    
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_PHB_COPY_TO_SIM2:
                    mmi_phb_entry_op_copy_to_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM2);
                    break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_PHB_COPY_TO_SIM3:
                    mmi_phb_entry_op_copy_to_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM3);
                    break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_PHB_COPY_TO_SIM4:
                    mmi_phb_entry_op_copy_to_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM4);
                    break;
            #endif
            
            #if  defined(__MMI_FILE_MANAGER__) && defined(__MMI_VCARD__)
                    case MENU_ID_PHB_COPY_TO_FMGR:
                    mmi_phb_op_copy_to_file(GRP_ID_PHB_MAIN);
                    break;
            #endif

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_ID_PHB_COPY_TO_MEMORY_CARD:
                    mmi_phb_entry_op_copy_to_phone_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_TCARD);
                    break;
            #endif

            #ifndef LOW_COST_SUPPORT
                case MITEM1014_PBOOK_MOVE:
                    {
                    #if (MMI_MAX_SIM_NUM >= 2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
                        ;
                    #else
                        if (srv_phb_get_storage(g_mmi_phb_list_p->store_index == PHB_STORAGE_NVRAM))
                        {
                            mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM);
                        }
                        else
                        {
                            mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_NVRAM);
                        }                    
                    #endif
                        break;
                    }
                
            #if (MMI_MAX_SIM_NUM >= 2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
                case MENU_MTPNP_PB_MOVE_PHONETOSIM1:
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOSIM1:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM);
                    break;
                    
                case MENU_MTPNP_PB_MOVE_SIM1TOPHONE:
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_SIM2TOPHONE:
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_SIM3TOPHONE:
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM4TOPHONE:
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOPHONE:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_NVRAM);
                    break;

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_PHONETOCARD:
                case MENU_MTPNP_PB_MOVE_SIM1TOCARD:
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_SIM2TOCARD:
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_MTPNP_PB_MOVE_SIM3TOCARD:
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_MTPNP_PB_MOVE_SIM4TOCARD:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_TCARD);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_PHONETOSIM2:
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOSIM2:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM2);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_PHONETOSIM3:
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOSIM3:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM3);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_PHONETOSIM4:
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOSIM4:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM4);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_SIM2TOSIM1:
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_SIM3TOSIM1:
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM4TOSIM1:
            #endif
                    mmi_phb_entry_op_move_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_SIM1TOSIM2:
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_SIM3TOSIM2:
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM4TOSIM2:
            #endif
                    mmi_phb_entry_op_move_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM2);
                    break;
            #endif
                    
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_SIM2TOSIM3:
                case MENU_PB_MOVE_SIM1TOSIM3:
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM4TOSIM3:
            #endif
                    mmi_phb_entry_op_move_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM3);
                    break;
            #endif
            
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM2TOSIM4:
                case MENU_PB_MOVE_SIM1TOSIM4:
                case MENU_PB_MOVE_SIM3TOSIM4:
                    mmi_phb_entry_op_move_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM4);
                    break;
            #endif
            #endif /* MMI_MAX_SIM_NUM >= 2 || __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
            #endif /* LOW_COST_SUPPORT */
            
            #if defined(__MMI_VCARD__)
                case MENU_ID_PHB_VCARD_SEND_ENTRY:
                    {
                         WCHAR name[MMI_PHB_NAME_LENGTH + 1];
                         srv_phb_get_name(g_mmi_phb_list_p->store_index, name, MMI_PHB_NAME_LENGTH);
                        if (!name[0])
                        {
                            mmi_phb_popup_display_ext(
                                STR_ID_VCARD_NAME_EMPTY, 
                                MMI_EVENT_FAILURE);
                        }
					#if 0	
                    #ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
                        #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/* under construction !*/
                        #endif
/* under construction !*/
                    #endif
                    #endif
                    }
                    break;
                    
            #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
                case MENU_ID_VCARD_FORWARD_SMS:
                    mmi_phb_vcard_send_select_card(MMI_VCARD_BUILD_VCARD_SEND_SMS);
                    break;
            #endif
            
            #if defined(__MMI_MMS__) && !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
                case MENU_ID_VCARD_FORWARD_MMS:
                    mmi_phb_vcard_send_select_card(MMI_VCARD_BUILD_VCARD_SEND_MMS);
                    break;
            #endif
            
            #if  defined(__MMI_EMAIL__)
                case MENU_ID_VCARD_FORWARD_EMAIL:
                    mmi_phb_vcard_send_select_card(MMI_VCARD_BUILD_VCARD_SEND_EMAIL);
                    break;
            #endif
            
            #ifdef __MMI_OPP_SUPPORT__
                case MENU_ID_VCARD_FORWARD_BT:
                    mmi_phb_vcard_send_select_card(MMI_VCARD_BUILD_VCARD_SEND_BT);
                    break;
            #endif
            #endif
            #if 0
            #if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #endif
            
            #ifdef __MMI_CM_BLACK_LIST__
                case MENU_ID_PHB_ADD_BLACK_LIST:
                    mmi_phb_add_to_blacklist_choose_entry(GRP_ID_PHB_MAIN);
                    break;
                #if defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_CM_BLACK_LIST_EXT__)
                case MENU_ID_PHB_ADD_VIDEO_BLACK_LIST:
                    mmi_phb_add_to_video_blacklist_choose_entry(GRP_ID_PHB_MAIN);
                    break;
                #endif
            #endif
            
            #ifdef __MMI_PHB_MULTI_OPERATION__
            #ifdef __MMI_UNIFIED_COMPOSER__
                case MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_MESSAGE:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_SEND_MESSAGE;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #else
                case MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_SMS:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_SEND_SMS;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #if defined(__MMI_MMS__) &&  defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
                case MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_MMS:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_SEND_MMS;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif
            #endif /* __MMI_UNIFIED_COMPOSER__ */

            #ifdef __MMI_UDX_VCARD_SUPPORT__
                case MENU_ID_PHB_MARK_SEVERAL_PRE_BUILD_UDX:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_BUILD_UDX;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif

            #if defined(__MMI_OPP_SUPPORT__) && defined(__MMI_VCARD__)
                case MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_VCARD:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_SEND_VCARD;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif

            #if defined(__MMI_MULTI_VCARD__)
                case MENU_ID_PHB_MARK_SEVERAL_PRE_BACKUP:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_BACKUP;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif

                case MENU_ID_PHB_MARK_SEVERAL_PRE_DELETE_SELECTED:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_DELETE_SELECTED;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif /* __MMI_PHB_MULTI_OPERATION__ */
            
            #ifndef __MMI_PHB_UI_IN_TABS__
            #ifdef __MMI_PHB_CALLER_GROUP__
                case MENU_ID_PHB_CALLER_GROUPS:
                    mmi_phb_entry_group_list_non_tab();
                    break;
            #endif
            #endif
            
            #if defined(__MMI_BPP20_SUPPORT__)
                case MENU_ID_PHB_PRINT:
                #if defined(MMI_ON_HARDWARE_P)
                    mmi_phb_bpp_print();
                #else
                    PopupNoSupport();
                #endif
                    break;
            #endif
            
                case MENU_ID_PHB_SETTINGS:
                {
                    mmi_phb_sg_entry_setting(GRP_ID_PHB_MAIN);
                    break;
                }

                default:
                    result = MMI_RET_DONT_CARE;
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
        #ifdef __MMI_PHB_MULTI_OPERATION__
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_PRE)
            {
                mmi_phb_mark_several_pre_build_option(menu_evt->sender_id);
                g_mmi_phb_mark_several_entry_func = mmi_phb_entry_mark_several_main;
            }
        #endif
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}

#else
mmi_ret mmi_phb_main_list_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SNS_CONTACTS__
	mmi_id sns_gid;
#endif
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    MMI_ID sender_id = menu_evt->sender_id;
	MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;
	
    S32 result = MMI_RET_OK;
    U16 prefer_storage = srv_phb_get_storage_mask();

	
 
    
    
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
	

	


    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {            
            if (menu_evt->parent_menu_id == MITEM1013_PBOOK_COPY_ENTRY)
            {
                mmi_phb_entry_op_copy_menu(GRP_ID_PHB_MAIN, menu_evt->sender_id);
            }
        #ifndef LOW_COST_SUPPORT
        #if (MMI_MAX_SIM_NUM >= 2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
            else if (menu_evt->parent_menu_id == MITEM1014_PBOOK_MOVE)
            {
                mmi_phb_entry_op_move_menu(menu_evt->sender_id);
            }
        #endif
        #endif
            else if (menu_evt->parent_menu_id == MITEM101_PBOOK_VIEW_OPTIONS)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_PHB_ADD_NEW_ENTRY_SELECT, MMI_FALSE);
                cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_PHB_ADD_NEW_ENTRY, MMI_FALSE);
                
            }
			else if (menu_evt->parent_menu_id == MENU_ID_PHB_PREFERRED_STORAGE)
            {
                MMI_BOOL is_menu_max_exist = MMI_FALSE;
            #if (MMI_MAX_SIM_NUM >= 2)
                S32 count;
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                U16 string_id;
            #endif
            #endif

                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            #if (MMI_MAX_SIM_NUM >= 2)
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_ALL, MMI_TRUE);
                for (count = 0; count < MMI_MAX_SIM_NUM; count++)
                {
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    string_id = mmi_phb_sim_dynamic_name_string_index((sim_interface_enum)count);
                    if (mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1 << count, sender_id, MENU_ID_PHB_PREFERRED_SIM + count, string_id))
                #else
                    if (mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1 << count, sender_id, MENU_ID_PHB_PREFERRED_SIM + count, 0))
                #endif
                    {
                        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_ALL, MMI_FALSE);
                        is_menu_max_exist = MMI_TRUE;
                    }
                }
            #else /* (MMI_MAX_SIM_NUM >= 2) */
                is_menu_max_exist = mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, sender_id, MENU_ID_PHB_PREFERRED_SIM, STR_GLOBAL_SIM_1);
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_ALL, (MMI_BOOL)!is_menu_max_exist);
            #endif /* (MMI_MAX_SIM_NUM >= 2) */

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_MEMORY_CARD, MMI_FALSE);    
                    if(!is_menu_max_exist)
                    {
                        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_ALL, MMI_FALSE);
                        is_menu_max_exist = MMI_TRUE;
                    }
                }
                else
                {
                    cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_PREFERRED_MEMORY_CARD, MMI_TRUE);    
                }
            #endif
            
                mmi_phb_get_preferred_storage();
            
                cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_PHONE);
            #ifdef __MMI_TELEPHONY_SUPPORT__
                if ((prefer_storage == PHB_STORAGE_SIM) && srv_sim_ctrl_is_available(MMI_SIM1))
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_SIM);
                }

            #if (MMI_MAX_SIM_NUM >= 2)
                for (count = 0; count < MMI_MAX_SIM_NUM - 1; count++)
                {
                    if (prefer_storage == PHB_STORAGE_SIM2 + count && srv_sim_ctrl_is_available(MMI_SIM2 << count))
                    {
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_SIM2 + count);
                    }
                }
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
            #endif
                if (prefer_storage == PHB_STORAGE_MAX && 
                    is_menu_max_exist)
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_ALL);
                }

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                if (prefer_storage == PHB_STORAGE_TCARD)
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_PREFERRED_MEMORY_CARD); 
                }
            #endif
            }
			#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
			else if (menu_evt->parent_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY)
            {
                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

                if (g_phb_setting_cntx.save_contact_notify == MMI_PHB_SAVE_CONTACT_NOTIFY_ON)
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_SAVE_CONTACT_NOTIFY_ON);
                }
                else
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_SAVE_CONTACT_NOTIFY_OFF);
                }
          
            }
			#endif
			#if defined(__MMI_INTELLIGENT_CALL_ALERT__) 
			else if (menu_evt->parent_menu_id == MENU_ID_PHB_SPEAK_NAME)
            {
                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

                if (g_phb_setting_cntx.speak_name == MMI_PHB_SPEAK_NAME_ON)
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_SPEAK_NAME_ON);
                    cui_menu_set_currlist_highlighted_id(sender_id, MENU_ID_PHB_SPEAK_NAME_ON);
                }
                else
                {
                    cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_SPEAK_NAME_OFF);
                    cui_menu_set_currlist_highlighted_id(sender_id, MENU_ID_PHB_SPEAK_NAME_OFF);
                }
                
            }
			#endif
            #if defined(__MMI_PHB_LAST_NAME_FIELD__)
			else if (menu_evt->parent_menu_id == MENU_ID_PHB_NAME_DISPLAY)
            {
                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

                switch(srv_phb_get_name_display_type())
                {
                    case SRV_PHB_NAME_DISPLAY_TYPE_2:
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_NAME_DISPLAY_TYPE_2);
                        break;

                    case SRV_PHB_NAME_DISPLAY_TYPE_3:
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_NAME_DISPLAY_TYPE_3);
                        break;

                    case SRV_PHB_NAME_DISPLAY_TYPE_4:
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_NAME_DISPLAY_TYPE_4);
                        break;

                    case SRV_PHB_NAME_DISPLAY_TYPE_1:
                    default:
                        cui_menu_set_radio_list_item(sender_id, MENU_ID_PHB_NAME_DISPLAY_TYPE_1);
                        break;
                }
            }
			#endif
			else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }
        

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {

			 
						 

			if (menu_evt->highlighted_menu_id >= MENU_ID_PHB_PREFERRED_SIM && 
                menu_evt->highlighted_menu_id <= MENU_ID_PHB_PREFERRED_PHONE)
            {
                mmi_phb_set_preferred_storage();
                cui_menu_close(sender_id);
            }
			 #if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
			 else if (highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY_ON)
						{
							 mmi_phb_set_save_contact_notify();
							 cui_menu_close(sender_id);
						 }
						 else if (highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY_OFF)
						 {
							 mmi_phb_set_save_contact_notify();
							 cui_menu_close(sender_id);
						 }
			#endif
			#if defined(__MMI_INTELLIGENT_CALL_ALERT__) 
			else if (highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME_ON)
            {
                mmi_phb_set_speak_name();
                cui_menu_close(sender_id);
            }
            else if (highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME_OFF)
            {
                mmi_phb_set_speak_name();
                cui_menu_close(sender_id);
            }
			#endif
			#if defined(__MMI_PHB_LAST_NAME_FIELD__)
			switch(menu_evt->highlighted_menu_id)
						{
            
							case MENU_ID_PHB_NAME_DISPLAY_TYPE_1:
								mmi_phb_set_name_display(GRP_ID_PHB_MAIN, SRV_PHB_NAME_DISPLAY_TYPE_1);
								break;
			
							case MENU_ID_PHB_NAME_DISPLAY_TYPE_2:
								mmi_phb_set_name_display(GRP_ID_PHB_MAIN, SRV_PHB_NAME_DISPLAY_TYPE_2);
								break;
			
							case MENU_ID_PHB_NAME_DISPLAY_TYPE_3:
								mmi_phb_set_name_display(GRP_ID_PHB_MAIN, SRV_PHB_NAME_DISPLAY_TYPE_3);
								break;
			
							case MENU_ID_PHB_NAME_DISPLAY_TYPE_4:
								mmi_phb_set_name_display(GRP_ID_PHB_MAIN, SRV_PHB_NAME_DISPLAY_TYPE_4);
								break;
			
			
							default:
								return;
						}
						cui_menu_close(sender_id);
			#endif
            
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PHB_ADD_NEW_ENTRY_SELECT:
                    mmi_phb_op_add_new_entry_ext(GRP_ID_PHB_MAIN);
                    break;

				case MENU_ID_PHB_ADD_NEW_ENTRY:
                    mmi_phb_op_add_new_entry_ext(GRP_ID_PHB_MAIN);
                    break;	
                    
                case MENU_ID_PHB_VIEW_CONTACT:
                    cui_phb_view_contact(g_mmi_phb_list_p->sg_id, g_mmi_phb_list_p->store_index);
                    break;

	        #ifdef __MMI_SNS_CONTACTS__
		        case MENU_ID_PHB_SNS_LINK:
		        sns_gid = cui_sns_friend_link_create(g_mmi_phb_list_p->sg_id, g_mmi_phb_list_p->store_index);
		        if (GRP_ID_INVALID != sns_gid)
		        { 
                    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_link_not_ready_proc, (void *)sns_gid);
                    g_mmi_phb_sns_misc.sns_cui_link = sns_gid;
		            cui_sns_friend_link_run(sns_gid);
                }    
		        break;

                case MENU_ID_PHB_SNS_UNLINK:
                    mmi_phb_sns_view_unlink(g_mmi_phb_list_p->store_index, g_mmi_phb_list_p->sg_id);
                    break;

	            case MENU_ID_PHB_SNS_FRIEND_VIEW:
		            mmi_phb_sns_entry_view_member(MMI_PHB_SNS_LIST_FRIEND);
		            break;

		        case MENU_ID_PHB_SNS_FAVORITE_VIEW:
		            mmi_phb_sns_entry_view_member(MMI_PHB_SNS_LIST_FAVORITE);
		            break;

		        case MENU_ID_PHB_SNS_FRIEND_FILTER:
		            sns_gid = cui_sns_filter_create_ex(g_mmi_phb_list_p->sg_id, CUI_SNS_FILTER_FRIEND_LIST);
                    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_filter_not_ready_proc, (void *)sns_gid);
		            g_mmi_phb_list_p->sns_friend_list->is_valid = MMI_FALSE;
                    g_mmi_phb_sns_misc.sns_cui_filter = sns_gid;
		            break;

            #ifdef __MMI_SNS_MESSAGES__
        		case MENU_ID_PHB_SNS_FRIEND_DIRECT_MESSAGE:
        		    mmi_phb_sns_entry_send_msg(MMI_PHB_SNS_LIST_FRIEND);
        		    break;

        	    case MENU_ID_PHB_SNS_FAVORITE_DIRECT_MESSAGE:
        		    mmi_phb_sns_entry_send_msg(MMI_PHB_SNS_LIST_FAVORITE);
        		    break;
            #endif

        		case MENU_ID_PHB_SNS_FRIEND_ADD_FAVORITE:
        		    mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FRIEND, MMI_TRUE);
        		    cui_menu_close(menu_evt->sender_id);
        		    break;

        		case MENU_ID_PHB_SNS_FRIEND_REMOVE_FAVORITE:
        		    mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FRIEND, MMI_FALSE);
        		    cui_menu_close(menu_evt->sender_id);
        		    break;

        		case MENU_ID_PHB_SNS_FAVORITE_REMOVE:
        		    mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FAVORITE, MMI_FALSE);
        		    cui_menu_close(menu_evt->sender_id);
        		    break;
        	#endif
					
            #if defined(__MMI_VIDEO_TELEPHONY__)
                case MENU_ID_PHB_SET_VT_CALL:
                        srv_phb_set_vt_call(g_mmi_phb_list_p->store_index, MMI_TRUE);
                        cui_menu_close(menu_evt->sender_id);
                        break;
                case MENU_ID_PHB_CANCEL_VT_CALL:
                        srv_phb_set_vt_call(g_mmi_phb_list_p->store_index, MMI_FALSE);
                        cui_menu_close(menu_evt->sender_id);
                        break;
            #endif

            #ifdef __MMI_UNIFIED_COMPOSER__
                case MENU_ID_PHB_OPTION_SEND_MESSAGE:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_MSG);
                    break;
                }
            #else /* __MMI_UNIFIED_COMPOSER__ */
            
                case MENU_ID_PHB_OPTION_SEND_SMS:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_SMS);
                    break;
                }
                
            #ifdef __MMI_MMS__
                case MENU_ID_PHB_OPTION_SEND_MMS:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_MMS);
                    break;
                }
            #endif /* __MMI_MMS__ */
            #endif /* __MMI_UNIFIED_COMPOSER__ */

                case MENU_ID_PHB_OPTION_DIAL:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_CALL);
                    break;
                }
            #if defined(__IP_NUMBER__)
                case MENU_ID_PHB_OPTION_IP_DIAL:
                {
                    mmi_phb_main_menu_op_start(MMI_PHB_OP_IP_CALL);
                    break;
                }
            #endif
            
            #if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
                case MENU_ID_PHB_OPTION_SEND_POSTCARD:
                    mmi_phb_op_send_postcard();
                    break;
            #endif /* defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__) */
            
                case MITEM1011_PBOOK_EDIT:
					#if 0
                    #if defined(__OP12__)
/* under construction !*/
                    #else
/* under construction !*/
                    #endif
					#else
					    mmi_phb_op_edit_pre_entry_ext(GRP_ID_PHB_MAIN);
					#endif
                    break;
            #if 0
            #if defined(__OP12__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #endif
            
                case MITEM1012_PBOOK_DELETE:
                    mmi_phb_entry_op_delete_confirm(GRP_ID_PHB_MAIN);
                    break;
                    
                case MITEM1013_PBOOK_COPY_ENTRY:
                    break;

                case MENU_ID_PHB_COPY_TO_PHONE:
                    mmi_phb_entry_op_copy_to_phone_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_NVRAM);
                    break;
                    
                case MENU_ID_PHB_COPY_TO_SIM:
                    mmi_phb_entry_op_copy_to_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM);
                    break;
                    
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_PHB_COPY_TO_SIM2:
                    mmi_phb_entry_op_copy_to_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM2);
                    break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_PHB_COPY_TO_SIM3:
                    mmi_phb_entry_op_copy_to_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM3);
                    break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_PHB_COPY_TO_SIM4:
                    mmi_phb_entry_op_copy_to_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM4);
                    break;
            #endif
            
            #if  defined(__MMI_FILE_MANAGER__) && defined(__MMI_VCARD__)
                    case MENU_ID_PHB_COPY_TO_FMGR:
                    mmi_phb_op_copy_to_file(GRP_ID_PHB_MAIN);
                    break;
            #endif

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_ID_PHB_COPY_TO_MEMORY_CARD:
                    mmi_phb_entry_op_copy_to_phone_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_TCARD);
                    break;
            #endif

            #ifndef LOW_COST_SUPPORT
                case MITEM1014_PBOOK_MOVE:
                    {
                    #if (MMI_MAX_SIM_NUM >= 2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
                        ;
                    #else
                        if (srv_phb_get_storage(g_mmi_phb_list_p->store_index == PHB_STORAGE_NVRAM))
                        {
                            mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM);
                        }
                        else
                        {
                            mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_NVRAM);
                        }                    
                    #endif
                        break;
                    }
                
            #if (MMI_MAX_SIM_NUM >= 2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
                case MENU_MTPNP_PB_MOVE_PHONETOSIM1:
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOSIM1:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM);
                    break;
                    
                case MENU_MTPNP_PB_MOVE_SIM1TOPHONE:
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_SIM2TOPHONE:
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_SIM3TOPHONE:
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM4TOPHONE:
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOPHONE:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_NVRAM);
                    break;

            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_PHONETOCARD:
                case MENU_MTPNP_PB_MOVE_SIM1TOCARD:
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_SIM2TOCARD:
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_MTPNP_PB_MOVE_SIM3TOCARD:
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_MTPNP_PB_MOVE_SIM4TOCARD:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_TCARD);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_PHONETOSIM2:
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOSIM2:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM2);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_PHONETOSIM3:
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOSIM3:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM3);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_PHONETOSIM4:
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                case MENU_MTPNP_PB_MOVE_CARDTOSIM4:
            #endif
                    mmi_phb_entry_op_move_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM4);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_SIM2TOSIM1:
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_SIM3TOSIM1:
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM4TOSIM1:
            #endif
                    mmi_phb_entry_op_move_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM);
                    break;
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_MTPNP_PB_MOVE_SIM1TOSIM2:
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_SIM3TOSIM2:
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM4TOSIM2:
            #endif
                    mmi_phb_entry_op_move_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM2);
                    break;
            #endif
                    
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_PB_MOVE_SIM2TOSIM3:
                case MENU_PB_MOVE_SIM1TOSIM3:
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM4TOSIM3:
            #endif
                    mmi_phb_entry_op_move_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM3);
                    break;
            #endif
            
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_PB_MOVE_SIM2TOSIM4:
                case MENU_PB_MOVE_SIM1TOSIM4:
                case MENU_PB_MOVE_SIM3TOSIM4:
                    mmi_phb_entry_op_move_sim_confirm(GRP_ID_PHB_MAIN, PHB_STORAGE_SIM4);
                    break;
            #endif
            #endif /* MMI_MAX_SIM_NUM >= 2 || __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
            #endif /* LOW_COST_SUPPORT */
            
            #if defined(__MMI_VCARD__)
                case MENU_ID_PHB_VCARD_SEND_ENTRY:
                    {
                         WCHAR name[MMI_PHB_NAME_LENGTH + 1];
                         srv_phb_get_name(g_mmi_phb_list_p->store_index, name, MMI_PHB_NAME_LENGTH);
                        if (!name[0])
                        {
                            mmi_phb_popup_display_ext(
                                STR_ID_VCARD_NAME_EMPTY, 
                                MMI_EVENT_FAILURE);
                        }
					#if 0	
                    #ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
                        #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/* under construction !*/
                        #endif
/* under construction !*/
                    #endif
                    #endif
                    }
                    break;
                    
            #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
                case MENU_ID_VCARD_FORWARD_SMS:
                    mmi_phb_vcard_send_select_card(MMI_VCARD_BUILD_VCARD_SEND_SMS);
                    break;
            #endif
            
            #if defined(__MMI_MMS__) && !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
                case MENU_ID_VCARD_FORWARD_MMS:
                    mmi_phb_vcard_send_select_card(MMI_VCARD_BUILD_VCARD_SEND_MMS);
                    break;
            #endif
            
            #if  defined(__MMI_EMAIL__)
                case MENU_ID_VCARD_FORWARD_EMAIL:
                    mmi_phb_vcard_send_select_card(MMI_VCARD_BUILD_VCARD_SEND_EMAIL);
                    break;
            #endif
            
            #ifdef __MMI_OPP_SUPPORT__
                case MENU_ID_VCARD_FORWARD_BT:
                    mmi_phb_vcard_send_select_card(MMI_VCARD_BUILD_VCARD_SEND_BT);
                    break;
            #endif
            #endif
            #if 0
            #if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #endif
            
            #ifdef __MMI_CM_BLACK_LIST__
                case MENU_ID_PHB_ADD_BLACK_LIST:
                    mmi_phb_add_to_blacklist_choose_entry(GRP_ID_PHB_MAIN);
                    break;
                #if defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_CM_BLACK_LIST_EXT__)
                case MENU_ID_PHB_ADD_VIDEO_BLACK_LIST:
                    mmi_phb_add_to_video_blacklist_choose_entry(GRP_ID_PHB_MAIN);
                    break;
                #endif
            #endif
            
            #ifdef __MMI_PHB_MULTI_OPERATION__
            #ifdef __MMI_UNIFIED_COMPOSER__
                case MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_MESSAGE:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_SEND_MESSAGE;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #else
                case MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_SMS:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_SEND_SMS;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #if defined(__MMI_MMS__) &&  defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
                case MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_MMS:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_SEND_MMS;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif
            #endif /* __MMI_UNIFIED_COMPOSER__ */

            #ifdef __MMI_UDX_VCARD_SUPPORT__
                case MENU_ID_PHB_MARK_SEVERAL_PRE_BUILD_UDX:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_BUILD_UDX;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif

         
			
		#if defined(__MMI_OPP_SUPPORT__) && defined(__MMI_VCARD__)

                case MENU_ID_PHB_MARK_SEVERAL_PRE_SEND_VCARD:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_SEND_VCARD;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif

            #if defined(__MMI_MULTI_VCARD__)
                case MENU_ID_PHB_MARK_SEVERAL_PRE_BACKUP:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_BACKUP;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif

                case MENU_ID_PHB_MARK_SEVERAL_PRE_DELETE_SELECTED:
                    g_mmi_phb_mark_several_type = MMI_PHB_MARK_SEVERAL_PRE_DELETE_SELECTED;
                    mmi_phb_pre_entry_mark_several_main(GRP_ID_PHB_MAIN);
                    break;
            #endif /* __MMI_PHB_MULTI_OPERATION__ */
            
            #ifndef __MMI_PHB_UI_IN_TABS__
            #ifdef __MMI_PHB_CALLER_GROUP__
                case MENU_ID_PHB_CALLER_GROUPS:
                    mmi_phb_entry_group_list_non_tab();
                    break;
            #endif
            #endif
            
            #if defined(__MMI_BPP20_SUPPORT__)
                case MENU_ID_PHB_PRINT:
                #if defined(MMI_ON_HARDWARE_P)
                    mmi_phb_bpp_print();
                #else
                    PopupNoSupport();
                #endif
                    break;
            #endif
            

                case MENU_ID_PHB_PREFERRED_STORAGE:
                    mmi_phb_entry_preferred_storage();
                    break;


            #ifdef __MMI_PHB_SPEED_DIAL__
                case MENU_ID_PHB_SPEED_DIAL:
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    if (srv_sim_ctrl_any_sim_is_available())
                    {
                        mmi_phb_entry_group_speed_dial(); 
                    }
                    else
                    {
                        mmi_phb_popup_display_ext(STR_GLOBAL_UNAVAILABLE_SIM, MMI_EVENT_INFO);
                    }
            #else
                    mmi_phb_entry_group_speed_dial();
            #endif
                    break;
            #endif
            #if 0
            #ifdef __OP01_FWPBW__
/* under construction !*/
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else
/* under construction !*/
            #endif
/* under construction !*/
            #endif
            #endif

            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                case  MENU_ID_PHB_MY_NUMBER:
                    mmi_phb_entry_group_my_number();
                    break;
            #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */

                case  MENU_ID_PHB_EXTRA_NUMBER:
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    if (mmi_phb_check_extra_number_available() && srv_sim_ctrl_any_sim_is_available())
                    {
                        mmi_phb_entry_group_extra_number(); 
                    }
                    else
                    {
                        mmi_phb_popup_display_ext(STR_GLOBAL_UNAVAILABLE_SIM, MMI_EVENT_INFO);
                    }
            #else
                    mmi_phb_entry_group_extra_number(); 
            #endif
                    break;

            #if defined(__MMI_INTELLIGENT_CALL_ALERT__)
                case  MENU_ID_PHB_SPEAK_NAME:
                    mmi_phb_entry_speak_name();
                    break;
            #endif

            #if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
                case  MENU_ID_PHB_SAVE_CONTACT_NOTIFY:
                    mmi_phb_entry_save_contact_notify();
                    break;
            #endif

                case  MENU_ID_PHB_MEMORY_STATUS:
                    mmi_phb_entry_memory_status();
                    break;

            #ifdef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
                case  MENU_ID_PHB_COPY_SEVERAL:
                    mmi_phb_group_copy_several();
                    break;
                case  MENU_ID_PHB_MOVE_SEVERAL:
                    mmi_phb_group_move_several();
                    break;
                case  MENU_ID_PHB_DELETE_ALL:
                    mmi_phb_group_delete_all();
                    break;
                case  MENU_ID_PHB_DELETE_ALL_NO_SIM:
                    mmi_phb_entry_delete_all_no_sim();
                    break;
            #endif /* __MMI_PHB_SLIM_SETTING_MESS_OPERATION__ */

            #if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
                case  MENU_ID_PHB_BACKUP:
                #ifdef __VCARD_CLOUD_SUPPORT__
                    mmi_phb_cloud_entry_cloud_backup();
                #else
				    mmi_phb_entry_backup_contact(GRP_ID_PHB_MAIN);
                #endif
                    break;
                
                case  MENU_ID_PHB_RESTORE:
                #ifdef __VCARD_CLOUD_SUPPORT__
                    mmi_phb_cloud_entry_cloud_restore();
                #else
                    mmi_phb_entry_restore_contact(GRP_ID_PHB_MAIN);
                #endif
                    break;
            #endif /* __MMI_MULTI_VCARD__  || __VCARD_CLOUD_SUPPORT__ */

            #ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
                case  MENU_ID_PHB_SYNC:
                    mmi_phb_entry_sync_menu();
                    break;
            #endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */
            #if 0
            #if defined(__MMI_OP01_SYNCML_SETTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            #endif

            #if defined(__MMI_PHB_LAST_NAME_FIELD__)
                case  MENU_ID_PHB_NAME_DISPLAY:
                    mmi_phb_entry_name_display(GRP_ID_PHB_MAIN);
                    break;
            #endif

               

                default:
                    result = MMI_RET_DONT_CARE;
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
        #ifdef __MMI_PHB_MULTI_OPERATION__
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_PRE)
            {
                mmi_phb_mark_several_pre_build_option(menu_evt->sender_id);
                g_mmi_phb_mark_several_entry_func = mmi_phb_entry_mark_several_main;
            }
        #endif
		if (menu_evt->parent_menu_id == MENU_ID_PHB_PREFERRED_STORAGE)
			{

		            phb_storage_enum temp_value = PHB_STORAGE_NVRAM;
				  
					switch(highlighted_menu_id)
					{
						case MENU_ID_PHB_PREFERRED_SIM:
							temp_value = PHB_STORAGE_SIM;
							break;
		
            #if (MMI_MAX_SIM_NUM >= 2)
						case MENU_ID_PHB_PREFERRED_SIM2:
							temp_value = PHB_STORAGE_SIM2;
							break;
            #endif
		
            #if (MMI_MAX_SIM_NUM >= 3)
						case MENU_ID_PHB_PREFERRED_SIM3:
							temp_value = PHB_STORAGE_SIM3;
							break;
            #endif
		
            #if (MMI_MAX_SIM_NUM >= 4)
						case MENU_ID_PHB_PREFERRED_SIM4:
							temp_value = PHB_STORAGE_SIM4;
							break;
            #endif
		
						case MENU_ID_PHB_PREFERRED_ALL:
							temp_value = PHB_STORAGE_MAX;
							break;
		
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
						case MENU_ID_PHB_PREFERRED_MEMORY_CARD:
							temp_value = PHB_STORAGE_TCARD;
							break;
            #endif
		
						default:
							break;
					}
					sg_setting_cntx->temp_prefer_storage = temp_value;
					
			}
		
           #if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)


            if (highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY_ON)
            {
                sg_setting_cntx->temp_save_contact_notify = MMI_PHB_SAVE_CONTACT_NOTIFY_ON;
                
            }
            if (highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY_OFF)
            {
                sg_setting_cntx->temp_save_contact_notify = MMI_PHB_SAVE_CONTACT_NOTIFY_OFF;
                
            }
            
            #endif
			#if defined(__MMI_INTELLIGENT_CALL_ALERT__) 
			
			if (highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME_ON)
						{
							sg_setting_cntx->temp_speak_name = MMI_PHB_SPEAK_NAME_ON;
							return MMI_RET_OK;
						}
						if (highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME_OFF)
						{
							sg_setting_cntx->temp_speak_name = MMI_PHB_SPEAK_NAME_OFF;
							return MMI_RET_OK;
						}
						
			#endif

		
            g_phb_setting_cntx.highlighted_menu_id = menu_evt->highlighted_menu_id;

        #if defined(__MMI_INTELLIGENT_CALL_ALERT__)
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_SPEAK_NAME)
            {
                if (g_phb_setting_cntx.speak_name)
                {
                    cui_menu_set_item_hint(sender_id, MENU_ID_PHB_SPEAK_NAME, get_string(STR_GLOBAL_ON));
                }
                else
                {
                    cui_menu_set_item_hint(sender_id, MENU_ID_PHB_SPEAK_NAME, get_string(STR_GLOBAL_OFF));
                }
            }
            else
        #endif
        #if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_SAVE_CONTACT_NOTIFY)
            {
                if (g_phb_setting_cntx.save_contact_notify == MMI_PHB_SAVE_CONTACT_NOTIFY_ON)
                {
                    cui_menu_set_item_hint(sender_id, MENU_ID_PHB_SAVE_CONTACT_NOTIFY, get_string(STR_GLOBAL_ON));
                }
                else
                {
                    cui_menu_set_item_hint(sender_id, MENU_ID_PHB_SAVE_CONTACT_NOTIFY, get_string(STR_GLOBAL_OFF));
                }
            }
            else 
        #endif
        #if defined(__MMI_PHB_LAST_NAME_FIELD__)
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_NAME_DISPLAY)
            {
                mmi_phb_set_name_display_hint(sender_id);
            }
            else
        #endif
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
            
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}



#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_option
 * DESCRIPTION
 *  phonebook list: contact option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
    U32 field_value;
#endif
    MMI_ID menu_gid;
#ifdef __MMI_SNS_CONTACTS__
    S32 result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_OP_OPTION);

    menu_gid = cui_menu_create(
               GRP_ID_PHB_MAIN,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_OPTION,
               MITEM101_PBOOK_VIEW_OPTIONS,
               MMI_FALSE, NULL);

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

#ifdef __MMI_PHB_MULTI_OPERATION__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL, MMI_TRUE);
#endif

#if defined(__MMI_VIDEO_TELEPHONY__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SET_VT_CALL, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_CANCEL_VT_CALL, MMI_TRUE);
#endif

#ifdef LOW_COST_SUPPORT
    cui_menu_set_item_hidden(menu_gid, MITEM1014_PBOOK_MOVE, MMI_TRUE);
#endif

#if defined(__MMI_VIDEO_TELEPHONY__)
    if (srv_phb_get_storage(g_mmi_phb_list_p->store_index)== PHB_STORAGE_NVRAM)
    {
        if (srv_phb_is_vt_call(g_mmi_phb_list_p->store_index))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_CANCEL_VT_CALL, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SET_VT_CALL, MMI_FALSE);
        }
    }
#endif

    if (g_mmi_phb_list_p->store_index == 0xffff)
    {
        #ifdef __MMI_MAINLCD_96X64__  
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_NEW_ENTRY_SELECT, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_NEW_ENTRY, MMI_TRUE);
        #endif
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT, MMI_TRUE);
	#ifdef __MMI_SNS_CONTACTS__
		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_LINK, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_UNLINK, MMI_TRUE);
	#endif
    #ifdef __MMI_UNIFIED_COMPOSER__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_MESSAGE, MMI_TRUE);
    #else /* __MMI_UNIFIED_COMPOSER__ */
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_SMS, MMI_TRUE);
    #if defined(__MMI_MMS__)&& !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_MMS, MMI_TRUE);
    #endif /* __MMI_MMS__ */
    #endif /* __MMI_UNIFIED_COMPOSER__ */
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_DIAL, MMI_TRUE);
    #if defined(__IP_NUMBER__)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_IP_DIAL, MMI_TRUE);
    #endif
    #if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_POSTCARD, MMI_TRUE);
    #endif /* defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__) */
        cui_menu_set_item_hidden(menu_gid, MITEM1011_PBOOK_EDIT, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MITEM1012_PBOOK_DELETE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MITEM1013_PBOOK_COPY_ENTRY, MMI_TRUE);
    #ifndef LOW_COST_SUPPORT
        cui_menu_set_item_hidden(menu_gid, MITEM1014_PBOOK_MOVE, MMI_TRUE);
    #endif
    #if defined(__MMI_VCARD__)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VCARD_SEND_ENTRY, MMI_TRUE);
    #endif
	#if 0
    #if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
    #endif
    #endif
    #ifdef __MMI_PHB_MULTI_OPERATION__
        //if (srv_phb_get_used_contact((U8)mmi_phb_get_preferred_storage()) == 0)
        if (srv_phb_get_used_contact(PHB_STORAGE_MAX) == 0)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_PRE, MMI_TRUE);
        }
    #endif
    #ifdef __MMI_CM_BLACK_LIST__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_BLACK_LIST, MMI_TRUE);
    #if defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_CM_BLACK_LIST_EXT__)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_VIDEO_BLACK_LIST, MMI_TRUE);
    #endif
    #endif
    #if defined(__MMI_BPP20_SUPPORT__)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PRINT, MMI_TRUE);
    #endif
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_NEW_ENTRY_SELECT, MMI_TRUE);
    #ifdef __MMI_MAINLCD_96X64__ 
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_NEW_ENTRY, MMI_FALSE);
    #endif

    #ifndef LOW_COST_SUPPORT
        if (!srv_sim_ctrl_any_sim_is_available()
        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            && !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV)
        #endif
            )
        {
            cui_menu_set_item_hidden(menu_gid, MITEM1014_PBOOK_MOVE, MMI_TRUE);
        }
    #endif

    #if !defined(__MMI_BT_PBAP_CLIENT__)
        mmi_phb_sim_ctrl_not_inserted_disable_menu(menu_gid, MENU_ID_PHB_OPTION_DIAL);
    #endif
    
    #if defined(__IP_NUMBER__)
        mmi_phb_sim_ctrl_not_inserted_disable_menu(menu_gid, MENU_ID_PHB_OPTION_IP_DIAL);
    #endif
    #if 0
    #if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
    #endif
    #endif
    
    #ifdef __MMI_CM_BLACK_LIST__
        mmi_phb_sim_ctrl_not_inserted_disable_menu(menu_gid, MENU_ID_PHB_ADD_BLACK_LIST);      
    #if defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_CM_BLACK_LIST_EXT__)
        mmi_phb_sim_ctrl_not_inserted_disable_menu(menu_gid, MENU_ID_PHB_ADD_VIDEO_BLACK_LIST);  
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    #endif /* __MMI_CM_BLACK_LIST__ */ 
    
    #ifdef __MMI_UNIFIED_COMPOSER__
        if (!mms_is_ready())
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_MESSAGE, MMI_TRUE);
        }
    #else /* __MMI_UNIFIED_COMPOSER__ */
    #if defined(__MMI_MMS__)&& !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
        if (!mms_is_ready())
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_MMS, MMI_TRUE);
        }
    #endif /* __MMI_MMS__ */
    #endif /* __MMI_UNIFIED_COMPOSER__ */

    #if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
        srv_phb_get_field(g_mmi_phb_list_p->store_index, &field_value);

        if (!mms_is_ready() || !((field_value & SRV_PHB_ENTRY_FIELD_NAME) || (field_value & SRV_PHB_ENTRY_FIELD_ADDRESS)))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_POSTCARD, MMI_TRUE);
        }
    #endif

    #if defined(__MMI_VCARD__)
        if (mmi_phb_send_contact_menu_check(menu_gid))
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VCARD_SEND_ENTRY, MMI_TRUE);
        }
    #endif /* defined(__MMI_VCARD__) */ 

    #if defined(__MMI_BPP20_SUPPORT__)
        if (!mmi_bt_is_to_display_bt_menu())
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PRINT, MMI_TRUE);
        }
    #endif

    #ifdef __MMI_SNS_CONTACTS__
        if (srv_phb_get_storage(g_mmi_phb_list_p->store_index)!= PHB_STORAGE_NVRAM)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_LINK, MMI_TRUE);
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_UNLINK, MMI_TRUE);
        }
        else
        {
    	    if (srv_sns_is_contact_linked(g_mmi_phb_list_p->store_index, &result))
    	    {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_LINK, MMI_TRUE);
    	    }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_UNLINK, MMI_TRUE); 
            }
        }
    #endif
    }


#ifdef __MMI_MAINLCD_96X64__ 

	{
	        #if 0
            #if defined(__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__) || !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_OP01_SYNCML_SETTING__)
/* under construction !*/
            #endif
			#else
			#if defined(__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__) || !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) 
                MMI_BOOL is_hide;
            #endif
            #endif

                cui_menu_set_currlist_flags(menu_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

            #if defined(__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__)
                if (mmi_syncml_app_sync_is_display(MMI_SYNCML_PHB_SYNC_MENU))
                {
                    is_hide = MMI_FALSE;
                }
                else
                {
                    is_hide = MMI_TRUE;
                }
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SYNC, is_hide);
            #endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */

            #if !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
                if (mmi_phb_check_extra_number_available())
                {
                    is_hide = MMI_FALSE;
                }
                else
                {
                    is_hide = MMI_TRUE;
                }
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EXTRA_NUMBER, is_hide);
            #endif
            #if 0
            #if defined(__MMI_OP01_SYNCML_SETTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_OP01_SYNCML_SETTING__ */
			#endif

            #ifdef __VCARD_CLOUD_SUPPORT__
                mmi_phb_cloud_get_provider_id(menu_gid);
            #endif

            #if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
                mmi_phb_check_backup_accessible(menu_evt);
            #endif /* defined(__MMI_MULTI_VCARD__) */

            #ifndef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MY_NUMBER, MMI_TRUE);
            #endif

            #ifndef __MMI_PHB_SLIM_SETTING_MESS_OPERATION__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DELETE_ALL, MMI_TRUE);
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_COPY_SEVERAL, MMI_TRUE);
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MOVE_SEVERAL, MMI_TRUE);
	            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DELETE_ALL_NO_SIM, MMI_TRUE);	
            #else
                mmi_phb_entry_check_mess_operation(menu_gid);
            #endif /* __MMI_PHB_SLIM_SETTING_MESS_OPERATION__ */
            }

#endif
    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);
    cui_menu_run(menu_gid);
}


#ifdef __MMI_PHB_GROUP_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_group_get_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_phb_view_group_get_offset(U32 index, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 group_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(storage)
    {
        case PHB_STORAGE_NVRAM:
            group_mask = 1 << (g_mmi_phb_view_contact_p->group_array[index]);
            break;

        case PHB_STORAGE_SIM:
            group_mask = 1 << (g_mmi_phb_view_contact_p->group_array[index] - MMI_PHB_GROUP_COUNT);
            break;

        case PHB_STORAGE_SIM2:
            group_mask = 1 << (g_mmi_phb_view_contact_p->group_array[index] - MMI_PHB_GROUP_COUNT - MMI_PHB_MAX_GAS_COUNT);
            break;

        case PHB_STORAGE_SIM3:
            group_mask = 1 << (g_mmi_phb_view_contact_p->group_array[index] - MMI_PHB_GROUP_COUNT - 2 * MMI_PHB_MAX_GAS_COUNT);
            break;

        case PHB_STORAGE_SIM4:
            group_mask = 1 << (g_mmi_phb_view_contact_p->group_array[index] - MMI_PHB_GROUP_COUNT - 3 * MMI_PHB_MAX_GAS_COUNT);
            break;

        default:
            group_mask = 0;
            ASSERT (0);
            break;  
    }

    return group_mask;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_group_info_set_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  flag        [?]         
 *  flag_ex     [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_phb_view_group_info_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_view_contact_p->group_highlight = (U8)item_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static S32 mmi_phb_view_group_info_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_count = 0;
    S32 index;
    U8 group_id_list[MMI_PHB_GROUP_COUNT];
    srv_phb_group_info_struct group_info;
    U32 group_mask;
    phb_storage_enum storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage = (phb_storage_enum)srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
    for (index = 0; index < MMI_PHB_GROUP_COUNT; index++)
    {
        group_mask = mmi_phb_view_group_get_offset(index, storage);
        if (g_mmi_phb_view_contact_p->contact->group_id & group_mask)
        {
            group_id_list[group_count] = g_mmi_phb_view_contact_p->group_array[index];
            group_count++;
        }
    }

    for (index = 0; index < data_size; index++)
    {
        if (!srv_phb_get_group_info(group_id_list[item_index + index], &group_info))
        {
            mmi_wcsncpy(menu_data[index].item_list[0], group_info.group_name, MAX_SUBMENU_CHARACTERS);
            menu_data[index].image_list[0] = get_image(gIndexIconsImageList[item_index + index]);
        }
    }

    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_group_info_set_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  flag        [?]         
 *  flag_ex     [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_phb_view_group_info_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_view_contact_p->group_array != NULL)
    {
        mmi_phb_mem_free(g_mmi_phb_view_contact_p->group_array); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_contact_view_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  flag        [?]         
 *  flag_ex     [?]         
 * RETURNS
 *  MMI_BOOL
 ****************************************************************************/
static void mmi_phb_contact_view_group_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 group_mask;
    S32 group_count = 0;
    S32 index;
    U8 *gui_buffer;
    phb_storage_enum storage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
    	g_mmi_phb_view_contact_p->sg_id,
    	SCR_ID_PHB_CONTACT_VIEW_GROUP_INFO,
    	mmi_phb_view_group_info_exit,
    	mmi_phb_contact_view_group_info,
    	MMI_FRM_UNKNOW_SCRN))
	{
        g_mmi_phb_view_contact_p->group_array = 
            (U8*)mmi_phb_mem_malloc(sizeof(U8) * MMI_PHB_GROUP_COUNT, SRV_PHB_MEMORY_TYPE_CTR);
        storage = (phb_storage_enum)srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
        srv_phb_get_group_list(g_mmi_phb_view_contact_p->group_array, NULL, storage);
    
		group_mask = g_mmi_phb_view_contact_p->contact->group_id;
	    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

		for (index = 0; index < MMI_PHB_GROUP_COUNT; index++)
		{
			if (group_mask & 1<<index)
            {
				group_count++;
            }
		}

        if (NULL == gui_buffer)
        {
        	g_mmi_phb_view_contact_p->group_highlight = 0;
        }

        RegisterHighlightHandler(mmi_phb_view_group_info_highlight_hdlr);

	    wgui_cat1032_show(
	        (WCHAR*) GetString(STR_SCR_CALLER_GROUP_CAPTION),
	        (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
	         NULL,
	         NULL,
	        (WCHAR*) GetString(STR_GLOBAL_BACK),
	        (PU8) GetImage(IMG_GLOBAL_BACK),
	         group_count,
	         mmi_phb_view_group_info_get_item,
	         NULL,
	         g_mmi_phb_view_contact_p->group_highlight,
	         0,    
	         IMG_GLOBAL_L1,
	         0,
	         gui_buffer,
	         NULL);
	}
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_contact_menu_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_view_contact_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_view_contact_cntx_struct* view_cntx = 
        (mmi_phb_view_contact_cntx_struct *)evt->user_data;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (highlighted_menu_id == MENU_ID_PHB_VIEW_CONTACT_EDIT)
            {
                mmi_phb_view_contact_op_edit_entry_ext();
            }
        #ifdef __MMI_UNIFIED_COMPOSER__
            else if (highlighted_menu_id == MENU_ID_PHB_VIEW_CONTACT_SEND_MESSAGE)
            {
                mmi_phb_view_contact_option_entry_send_message(view_cntx->sg_id);
            }
        #else /* __MMI_UNIFIED_COMPOSER__ */
            else if (highlighted_menu_id == MENU_ID_PHB_VIEW_CONTACT_SEND_SMS)
            {
                mmi_phb_view_contact_send_sms(view_cntx->sg_id);
            }
        #if defined(__MMI_MMS__)&& !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
            else if (highlighted_menu_id == MENU_ID_PHB_VIEW_CONTACT_SEND_MMS)
            {
                mmi_phb_view_contact_send_mms(view_cntx->sg_id);
            }
        #endif /* __MMI_MMS__ */
        #endif /* __MMI_UNIFIED_COMPOSER__ */
            else if (highlighted_menu_id == MENU_ID_PHB_VIEW_CONTACT_DIAL)
            {
                mmi_phb_view_contact_dial(view_cntx->sg_id);
            }
        #if defined(__IP_NUMBER__)
            else if (highlighted_menu_id == MENU_ID_PHB_VIEW_CONTACT_IP_DIAL)
            {
                mmi_phb_view_contact_dial_ip_call(view_cntx->sg_id);
            }
        #endif
        #ifdef __MMI_EMAIL__
            else if (highlighted_menu_id == MENU_ID_PHB_OPTION_SEND_EMAIL)
            {
                mmi_phb_option_op_send_email(view_cntx->sg_id);
            }
        #endif
		#if 0
        #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #endif
        #if defined(BROWSER_SUPPORT) && defined(__MMI_PHB_INFO_FIELD__)
            else if (highlighted_menu_id == MENU_ID_PHB_OPTION_START_BROWSER)
            {
                mmi_phb_option_op_start_broswer(view_cntx->sg_id, menu_evt->sender_id);
            }
        #endif
        #ifdef __MMI_PHB_CALLER_RES__
        #ifdef __MMI_PHB_CALLER_VIDEO__
            else if (highlighted_menu_id == MENU_ID_PHB_OPTION_PLAY_VIDEO)
            {
                mmi_phb_option_op_play_video(view_cntx->sg_id);
            }
        #endif
            else if (highlighted_menu_id == MENU_ID_PHB_OPTION_VIEW_PIC)
            {
                mmi_phb_option_op_view_pic(view_cntx->sg_id);
            }
        #endif /* __MMI_PHB_CALLER_RES__ */
        #ifdef __MMI_PHB_GROUP_ENHANCE__
            else if (highlighted_menu_id == MENU_ID_PHB_CONTACT_VIEW_GROUP_INFO)
            {
            	mmi_phb_contact_view_group_info();
            }
        #endif
        #ifdef __MMI_SNS_CONTACTS__
            else if (highlighted_menu_id == MENU_ID_PHB_VIEW_SNS_UNLINK)
            {
                mmi_phb_sns_view_unlink(view_cntx->store_index, view_cntx->sg_id);
            }
        #ifdef __MMI_SNS_MESSAGES__
            else if (highlighted_menu_id == MENU_ID_PHB_VIEW_SNS_DIRECT_MESSAGE)
            {
                mmi_phb_sns_view_message();
            }
        #endif
        #ifdef BROWSER_SUPPORT
            else if (highlighted_menu_id == MENU_ID_PHB_VIEW_SNS_BROWSER)
            {
                mmi_phb_sns_view_browser();
            }
        #endif
        #endif
            else
            {
                return MMI_RET_DONT_CARE;
            }
            return MMI_RET_OK;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            return MMI_RET_OK;
        }

        default:
            return MMI_RET_DONT_CARE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_view_entry_options_hide_number_related
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_entry_op_view_entry_options_hide_number_related(MMI_ID menu_gid, MMI_BOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_DIAL, value);
#if defined(__IP_NUMBER__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_IP_DIAL, value);
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_SEND_MESSAGE, value);
#else /* __MMI_UNIFIED_COMPOSER__ */
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_SEND_SMS, value);
#if defined(__MMI_MMS__)&& !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_SEND_MMS, value);
#endif /* __MMI_MMS__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_view_entry_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_op_view_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;
    mmi_phb_view_contact_cntx_struct* view_cntx = 
        (mmi_phb_view_contact_cntx_struct *)mmi_frm_group_get_user_data(g_mmi_phb_view_contact_p->sg_id);
#ifdef __MMI_SNS_CONTACTS__
    srv_sns_info_struct *sns_info;
    MMI_BOOL is_hide = MMI_FALSE;
#endif
#ifdef __MMI_PHB_GROUP_ENHANCE__
    phb_storage_enum storage;
    U32 field;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_OP_VIEW_OPTION);

    menu_gid = cui_menu_create(
               view_cntx->sg_id,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_OPTION,
               MENU_ID_PHB_ENTRY_VIEW_OPTIONS,
               MMI_FALSE,
               (void*)view_cntx);

#ifdef __MMI_PHB_GROUP_ENHANCE__
    storage = (phb_storage_enum)srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
    field = srv_phb_get_support_field(storage);
    if (!(field & MMI_PHB_CONTACT_FIELD_GROUP))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_CONTACT_VIEW_GROUP_INFO, MMI_TRUE);  
    }
#endif

    mmi_phb_entry_op_view_entry_options_hide_number_related(menu_gid, MMI_TRUE);
#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */
#endif

#ifdef __MMI_EMAIL__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_EMAIL, MMI_TRUE);
#endif

#if defined(BROWSER_SUPPORT) && defined(__MMI_PHB_INFO_FIELD__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_START_BROWSER, MMI_TRUE);
#endif

    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_VIEW_PIC, MMI_TRUE);
    
#ifdef __MMI_PHB_CALLER_VIDEO__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_PLAY_VIDEO, MMI_TRUE);
#endif
    
    switch (g_mmi_phb_view_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NAME:
    #ifdef __MMI_PHB_LAST_NAME_FIELD__  
        case MMI_PHB_FIELD_LAST_NAME:
    #endif /* __MMI_PHB_LAST_NAME_FIELD__ */
    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:
    #endif /* __MMI_PHB_LAST_NAME_FIELD__ */
        {
            mmi_phb_entry_op_view_entry_options_hide_number_related(menu_gid, MMI_FALSE);
            break;
        }
        
        case MMI_PHB_FIELD_NUMBER:
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
        case MMI_PHB_FIELD_OPT_NUM_2:
        case MMI_PHB_FIELD_OPT_NUM_3:
    #endif
        {
            if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_NUMBER)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->number;
            }    
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            else if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_1)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->opt_num[0].number;
            }
            else if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_2)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->opt_num[1].number;
            }
            else if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_3)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->opt_num[2].number;
            }        
        #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
            if (mmi_wcslen(g_mmi_phb_view_contact_p->select_data))
            {
                mmi_phb_entry_op_view_entry_options_hide_number_related(menu_gid, MMI_FALSE);
            }
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
        #endif
        #endif
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_EMAIL:
    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
        case MMI_PHB_FIELD_EMAIL2:
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */

            if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_EMAIL)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->emailAddress;
            }
            
        #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
            else
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->emailAddress2;
            }
        #endif
        
            if (mmi_ucs2strlen((CHAR*) g_mmi_phb_view_contact_p->select_data))
            {
            #ifdef __MMI_EMAIL__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_EMAIL, MMI_FALSE);
            #endif

            #ifdef __MMI_UNIFIED_COMPOSER__
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_SEND_MESSAGE, MMI_FALSE);
            #else /* __MMI_UNIFIED_COMPOSER__ */
                //mmi_frm_unhide_menu_item(MENU_ID_PHB_VIEW_CONTACT_SEND_SMS);
            #if defined(__MMI_MMS__)&& !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_SEND_MMS, MMI_FALSE);
            #endif /* __MMI_MMS__ */
            #endif /* __MMI_UNIFIED_COMPOSER__ */
            }
            break;
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */

    #ifdef __MMI_PHB_CALLER_RES__
        case MMI_PHB_FIELD_PIC:    
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_VIEW_PIC, MMI_FALSE);
            break;
    #ifdef __MMI_PHB_CALLER_VIDEO__
        case MMI_PHB_FIELD_VIDEO:
            if (g_mmi_phb_res_p->selected_video_index != 0)
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_PLAY_VIDEO, MMI_FALSE);
            }
            break;
    #endif
    #endif /* __MMI_PHB_CALLER_RES__ */
    
    #if defined(BROWSER_SUPPORT) && defined(__MMI_PHB_INFO_FIELD__)    
        case MMI_PHB_FIELD_URL:
            g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->url;
            if (mmi_ucs2strlen((CHAR*) g_mmi_phb_view_contact_p->select_data) && mmi_phb_is_start_broswer_permit())
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_START_BROWSER, MMI_FALSE);
            }
            break;
    #endif
        #if 0
        #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */
		#endif

        default:
            break;
    }

    mmi_phb_sim_ctrl_not_inserted_disable_menu(menu_gid, MENU_ID_PHB_VIEW_CONTACT_DIAL);
#if defined(__IP_NUMBER__)
    mmi_phb_sim_ctrl_not_inserted_disable_menu(menu_gid, MENU_ID_PHB_VIEW_CONTACT_IP_DIAL);
#endif /* defined(__IP_NUMBER__) */
#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */ 
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
    if (!mms_is_ready())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_SEND_MESSAGE, MMI_TRUE);
    }
#else /* __MMI_UNIFIED_COMPOSER__ */
#if defined(__MMI_MMS__)&& !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)

    if (!mms_is_ready())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_CONTACT_SEND_MMS, MMI_TRUE);
    }
#endif /* __MMI_MMS__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __MMI_EMAIL__
    if (!mmi_email_is_email_can_forward())
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_OPTION_SEND_EMAIL, MMI_TRUE);
    }
#endif

#ifdef __MMI_SNS_CONTACTS__
    if (!mmi_phb_sns_is_linked(view_cntx->store_index))
    {
        is_hide = MMI_TRUE;
    }
    else
    {
        if (srv_sns_get_item2(view_cntx->list_id, 0, (void **)&sns_info) < 0)
        {
            is_hide = MMI_TRUE;
        }
    }

    if (is_hide)
    {   
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_SNS_UNLINK, MMI_TRUE);
    #ifdef __MMI_SNS_MESSAGES__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_SNS_DIRECT_MESSAGE, MMI_TRUE);
    #endif
    #ifdef BROWSER_SUPPORT
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_SNS_BROWSER, MMI_TRUE);
    #endif
    }
    else
    {
    #ifdef BROWSER_SUPPORT
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_SNS_BROWSER, MMI_TRUE);
        if (sns_info->profile_url_len > 0 && sns_info->profile_url && mmi_phb_is_start_broswer_permit())
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_SNS_BROWSER, MMI_FALSE);
        }
    #endif /* BROWSER_SUPPORT */
    #ifdef __MMI_SNS_MESSAGES__
        if (SRV_SNS_PROVIDER_TWITTER == sns_info->user.provider)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_VIEW_SNS_DIRECT_MESSAGE, MMI_TRUE);    
        }
    #endif
    }
#endif /* __MMI_SNS_CONTACTS__ */

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

    cui_menu_run(menu_gid);
}

#define MMI_PHB_VIEW_CONTACT_PART
void mmi_phb_op_view_pre_entry(void)
{
    cui_phb_view_contact(mmi_phb_cntx_mgr_get_current_sg_id(), g_mmi_phb_list_p->store_index);
}


#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
void mmi_phb_single_op_extra_handle_bday(S32 result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
    /* update success */
        mmi_tdl_birthday_struct birthday;
        U16 name[MMI_PHB_NAME_LENGTH + 1];
        
        srv_phb_get_name(store_index, name, MMI_PHB_NAME_LENGTH);
        srv_phb_get_birthday(
            store_index,
            &(birthday.bday_year),
            &(birthday.bday_month),
            &(birthday.bday_day));
        birthday.store_idx = store_index;
        birthday.name = name;

        mmi_tdl_birthday_add_result_callback(MMI_TRUE, &birthday);
    }
    else
    {
    /* update fail or cancel */
        mmi_tdl_birthday_add_result_callback(MMI_FALSE, NULL); 
    }
}


static void mmi_phb_single_op_extra_handle(
        S32 result,
        U16 store_index,
        mmi_phb_op_cntx_struct *op_cntx,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op_cntx == NULL)
    {
        return;
    }

    switch (op_cntx->action)
    {
        case MMI_PHB_OP_ADD:
        case MMI_PHB_OP_EDIT:
        {
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        #ifdef __MMI_BIRTHDAY_REMINDER__
            mmi_phb_single_op_extra_handle_bday(result, store_index);
        #endif
        #endif
            break;
        }

        case MMI_PHB_OP_DELETE:
        {
            #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            #ifdef __MMI_BIRTHDAY_REMINDER__
            /* delete birhday reminder */
            if (op_cntx->extra_handler & 0x01)
            {
                mmi_tdl_br_delete(op_cntx->store_index);
            }
            else
            {
                mmi_tdl_br_delete_no(op_cntx->store_index);
            }
            #endif
            #endif
            
            break;
        }
        
        default:
            break;
    }
}
#endif
#endif


static void mmi_phb_single_op_done_ext(S32 result, U16 store_index, mmi_phb_op_cntx_struct *op_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum popup_type = MMI_EVENT_SUCCESS;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phb_save_contact_result_struct evt;

    evt.evt_id = EVT_ID_PHB_SAVE_CONTACT;
    evt.size = sizeof(cui_phb_save_contact_result_struct);
    evt.user_data = NULL;
    evt.sender_id = g_mmi_phb_save_contact_p->sg_id;
    evt.result = result;
    evt.store_index = store_index;
    evt.field_type = g_mmi_phb_save_contact_p->highlight_type;
            
    g_mmi_phb_save_contact_p->evt_out = MMI_TRUE;

    if (!g_mmi_phb_save_contact_p->is_popup)
    {
         mmi_phb_cntx_mgr_post_evt(
               g_mmi_phb_save_contact_p->sg_id,
               MMI_FALSE,
               (mmi_event_struct*)&evt);
     }
     else
     {
         MMI_BOOL popup_success = MMI_FALSE;

         if (result != SRV_PHB_NO_ERROR)
         {
             str_id = mmi_phb_get_error_string(result, &popup_type, store_index);   
             popup_success = mmi_phb_display_popup_cb(
                                 g_mmi_phb_save_contact_p->sg_id,
                                 (UI_string_type) GetString(str_id),
                                 popup_type,
                                 (mmi_proc_func)NULL,
                                 NULL);
         }

         if (result == SRV_PHB_NUMBER_TOO_LONG)
         {
             mmi_frm_scrn_close(op_cntx->sg_id, SCR_IN_PROGRESS_PHB);
         }
         else
         {
             mmi_phb_cntx_mgr_post_evt(g_mmi_phb_save_contact_p->sg_id, popup_success, (mmi_event_struct*)&evt);
         }
    }
}


void mmi_phb_single_op_done(S32 result, U16 store_index, mmi_phb_op_cntx_struct *op_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum popup_type = MMI_EVENT_SUCCESS;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_FALSE;

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
    mmi_phb_single_op_extra_handle(
        result,
        store_index,
        op_cntx,
        NULL);
#endif
#endif

    switch (op_cntx->action)
    {
        case MMI_PHB_OP_ADD:
        case MMI_PHB_OP_EDIT:
        {
            if ((op_cntx->end_key_press) && (result == SRV_PHB_NO_ERROR))
            {
            #ifdef __MMI_PHB_SPEED_DIAL__
                mmi_phb_contact_info_struct *contact = (mmi_phb_contact_info_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_contact_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
    			memset(contact, 0, sizeof(mmi_phb_contact_info_struct));
                mmi_phb_contact_get_contact_info(store_index, contact);
                mmi_phb_speed_dial_set_number_commit(store_index, contact);
				mmi_phb_mem_free(contact);
            #endif
                #ifdef __MMI_PHB_SPEED_DIAL__
                srv_phb_speed_dial_reload();
                #endif
                op_cntx->end_key_press = MMI_FALSE;
                break;
            }

        #ifdef __MMI_PHB_SPEED_DIAL__
            if (result == SRV_PHB_NO_ERROR)
            {
                mmi_phb_speed_dial_set_number_commit(store_index, g_mmi_phb_contact_p);
            }
        #endif
            break;
        }

        case MMI_PHB_OP_DELETE:
            if (result < 0)
            {
                str_id = mmi_phb_get_error_string(result, &popup_type, store_index);
                mmi_popup_display_simple_ext(
                    str_id,
                    popup_type,
                    op_cntx->sg_id,
                    NULL);
            }
            mmi_frm_scrn_close(op_cntx->sg_id, SCR_IN_PROGRESS_PHB);
            break;

    #ifndef LOW_COST_SUPPORT        
        case MMI_PHB_OP_MOVE:
        {
            if (result != SRV_PHB_NO_ERROR)
            {
                if (result == SRV_PHB_NAME_MODIFIED)
                {
                    str_id = STR_MOVED_NAME_MODIFIED;
                }
                else
                {
                    str_id = mmi_phb_get_error_string(result, &popup_type, store_index);
                }

                mmi_popup_display_simple_ext(
                    str_id,
                    popup_type,
                    op_cntx->sg_id,
                    NULL);
            }
            mmi_frm_scrn_close(op_cntx->sg_id, SCR_IN_PROGRESS_PHB);
            break;
        }
    #endif

        case MMI_PHB_OP_COPY:
        {
            if (result != SRV_PHB_NO_ERROR)
            {
                if (result == SRV_PHB_NAME_MODIFIED)
                {
                    str_id = STR_COPIED_NAME_MODIFIED;             
                }
                else if (result == SRV_PHB_SIM_PARTIAL_ERROR)
                {
                     str_id = STR_ID_PHB_PARTIAL_COPIED; 
                }
                else
                {
                    str_id = mmi_phb_get_error_string(result, &popup_type, store_index);           
                }
                mmi_popup_display_simple_ext(
                    str_id,
                    popup_type,
                    op_cntx->sg_id,
                    NULL);
            }
            mmi_frm_scrn_close(op_cntx->sg_id, SCR_IN_PROGRESS_PHB);
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }
}


void mmi_phb_op_single_cb(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_struct *op_cntx = (mmi_phb_op_cntx_struct *) user_data;
    U16 op_store_index = store_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_cntx_mgr_controller(op_cntx->state, MMI_FALSE, NULL))
    {
    #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
        if (op_cntx->action == MMI_PHB_OP_EDIT)
        {
            op_store_index = op_cntx->store_index;
        }
    #endif

        mmi_phb_cntx_mgr_refresh(op_cntx, NULL, 0, op_store_index);
        
        mmi_phb_single_op_done(
            result,
            op_store_index,
            op_cntx);
        switch (op_cntx->action)
        {
            case MMI_PHB_OP_ADD:
            case MMI_PHB_OP_EDIT:
                mmi_phb_single_op_done_ext(result, op_store_index, op_cntx);
                break;

            default:
                break;
        }
    }
}


static void mmi_phb_op_add_more_cb(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_struct *op_cntx = (mmi_phb_op_cntx_struct *) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_oplib_delete_contact(
        op_cntx->store_index,
        mmi_phb_op_single_cb,
        op_cntx);

    op_cntx->store_index = store_index;
}


#define MMI_PHB_OP_EDIT_PART
void mmi_phb_op_save_contact_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct* contact_info;
    U16 store_index = g_mmi_phb_save_contact_p->store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_UPDATE;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = g_mmi_phb_save_contact_p->action;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_UPDATE;
    g_mmi_phb_op_cntx.sg_id = g_mmi_phb_save_contact_p->sg_id;

    contact_info = mmi_phb_contact_build(g_mmi_phb_contact_p);
    g_mmi_phb_op_cntx.dst_storage = g_mmi_phb_save_contact_p->storage;
    g_mmi_phb_op_cntx.store_index = store_index;
    srv_phb_oplib_update_contact(
            store_index,
            contact_info,
            mmi_phb_op_single_cb,
            &g_mmi_phb_op_cntx);

    mmi_phb_get_contact_free_buffer(contact_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_save_contact
 * DESCRIPTION
 *  Sends the request to L4 to save the entry
 *  edited by the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_save_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct* contact_info;
    U32 storage = g_mmi_phb_save_contact_p->storage;
    U16 store_index = g_mmi_phb_save_contact_p->store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_UPDATE;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = g_mmi_phb_save_contact_p->action;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_UPDATE;
    g_mmi_phb_op_cntx.sg_id = g_mmi_phb_save_contact_p->sg_id;

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    if (!g_mmi_phb_save_contact_p->bday_changed &&
        mmi_ucs2cmp((CHAR*) g_mmi_phb_contact_p->bday, (CHAR*) (PU8) GetString(STR_GLOBAL_NONE)) == 0)
    {
        g_mmi_phb_contact_p->b_year[0] = 0;
        g_mmi_phb_contact_p->b_month[0] = 0;
        g_mmi_phb_contact_p->b_day[0] = 0;
    }
#endif

#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_contact_res_value_save(g_mmi_phb_contact_p, g_mmi_phb_res_p);
#endif
    contact_info = mmi_phb_contact_build(g_mmi_phb_contact_p);
    
    if (g_mmi_phb_op_cntx.action == MMI_PHB_OP_ADD)
    {
        g_mmi_phb_op_cntx.dst_storage = storage;
        
        srv_phb_oplib_add_contact(
            storage,
            SRV_PHB_INVALID_INDEX,
            contact_info,
            mmi_phb_op_single_cb,
            &g_mmi_phb_op_cntx);
    }
    else if (g_mmi_phb_op_cntx.action == MMI_PHB_OP_EDIT)
    {
        g_mmi_phb_op_cntx.store_index = store_index;
        g_mmi_phb_op_cntx.dst_storage = storage;

    #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
        if (g_mmi_phb_save_contact_p->add_more)
        {
            srv_phb_oplib_add_contact(
                storage,
                SRV_PHB_INVALID_INDEX,
                contact_info,
                mmi_phb_op_add_more_cb,
                &g_mmi_phb_op_cntx);
        }
        else
    #endif
        {
            srv_phb_oplib_update_contact(
                store_index,
                contact_info,
                mmi_phb_op_single_cb,
                &g_mmi_phb_op_cntx);
        }
    }

    mmi_phb_get_contact_free_buffer(contact_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_end_key_save_contact
 * DESCRIPTION
 *  press end key save contact when editing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_end_key_save_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_op_save_contact();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_pre_save
 * DESCRIPTION
 *  Checks if the entry can be saved
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_save_contact_pre_save(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_op_check_pre_save(g_mmi_phb_contact_p, g_mmi_phb_save_contact_p->storage, MMI_TRUE))
    {
        mmi_phb_show_in_progress(group_id, STR_GLOBAL_SAVING);

        mmi_phb_op_save_contact();
    }
}


void mmi_phb_entry_op_save_contact_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_save_contact_result_struct evt;
    MMI_ID sg_id = g_mmi_phb_save_contact_p->sg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = g_mmi_phb_save_contact_p->action;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_UPDATE;
    g_mmi_phb_op_cntx.sg_id = sg_id;

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
    mmi_phb_single_op_extra_handle(-1, 0xffff, &g_mmi_phb_op_cntx, NULL);
#endif
#endif
    
    evt.evt_id = EVT_ID_PHB_SAVE_CONTACT_CANCEL;
    evt.size = sizeof(cui_phb_save_contact_result_struct);
    evt.user_data = NULL;
    evt.sender_id = sg_id;
    evt.result = SRV_PHB_ERROR;
    evt.field_type = g_mmi_phb_save_contact_p->highlight_type;

    g_mmi_phb_save_contact_p->evt_out = MMI_TRUE;
    
    mmi_phb_cntx_mgr_post_evt(sg_id, MMI_FALSE, (mmi_event_struct*)&evt);
}

#ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
static void mmi_phb_entry_op_save_contact_cancel_ext(MMI_ID group_id)
{
    mmi_phb_entry_op_save_contact_cancel();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_save_confirm
 * DESCRIPTION
 *  Confirms before saving the entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_save_contact_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
    mmi_confirm_property_struct arg;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
    if (g_mmi_phb_save_contact_p->action == MMI_PHB_OP_EDIT
        && g_mmi_phb_save_contact_p->add_more)
    {
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.parent_id = g_mmi_phb_save_contact_p->sg_id;
        arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;

        mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
        g_mmi_phb_confirm_user_data.sg_id = g_mmi_phb_save_contact_p->sg_id;
        g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_op_save_contact_pre_save;
        g_mmi_phb_confirm_user_data.RSK_function = mmi_phb_entry_op_save_contact_cancel_ext;

        arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

        mmi_confirm_display(
            (WCHAR *) get_string(STR_ID_PHB_MOVE_FROM_SIM_TO_PHONE_QUERY),
            MMI_EVENT_QUERY,
            &arg);
    }
    else
#endif
    {
        mmi_phb_op_save_contact_pre_save(g_mmi_phb_save_contact_p->sg_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_pre_entry
 * DESCRIPTION
 *  Pre Entry function for phonebook edit.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_view_contact_op_edit_entry_ext()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id active_id = g_mmi_phb_view_contact_p->sg_id;
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_check_storage_accessible(srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index)))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            active_id,
            0);
    }
    else
    {
        sg_id = cui_phb_save_contact_create(active_id);

        cui_phb_save_contact_set_store_index(sg_id, g_mmi_phb_view_contact_p->store_index);
        cui_phb_save_contact_set_highlight_type(sg_id, g_mmi_phb_view_contact_p->highlight_type);

        g_mmi_phb_view_contact_p->child_id = sg_id;

        cui_phb_save_contact_run(sg_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_pre_entry
 * DESCRIPTION
 *  Pre Entry function for phonebook edit.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_pre_entry_ext(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_check_storage_accessible(srv_phb_get_storage(g_mmi_phb_list_p->store_index)))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
    }
    else
    {
        sg_id = cui_phb_save_contact_create(group_id);
        cui_phb_save_contact_set_store_index(sg_id, g_mmi_phb_list_p->store_index);
        g_mmi_phb_list_p->child_id = sg_id;
        cui_phb_save_contact_run(sg_id);
    }
}


#define MMI_PHB_OP_DELETE_PART
void mmi_phb_op_delete_contact(U16 store_index, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_UPDATE;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_DELETE;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_UPDATE;
    g_mmi_phb_op_cntx.store_index = store_index;
    g_mmi_phb_op_cntx.sg_id = group_id;

    srv_phb_oplib_delete_contact(
        store_index,
        mmi_phb_op_single_cb,
        &g_mmi_phb_op_cntx);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_entry_req
 * DESCRIPTION
 *  Sends the request to stack to delete
 *  a phone book entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_delete_entry_req(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(group_id, STR_GLOBAL_DELETING);

    mmi_phb_op_delete_contact(g_mmi_phb_list_p->store_index, group_id);
}

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
static void mmi_phb_op_delete_biryday_reminder_ok(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_op_cntx.extra_handler = 1;
    mmi_phb_op_delete_entry_req(group_id);
}


static void mmi_phb_op_delete_biryday_reminder_no(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_op_cntx.extra_handler = 0;
    mmi_phb_op_delete_entry_req(group_id);
}


static void mmi_phb_op_delete_birhday_reminder_confirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = group_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;
    arg.f_auto_map_empty_softkey = MMI_FALSE;

    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = group_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_op_delete_biryday_reminder_ok;
    g_mmi_phb_confirm_user_data.RSK_function = mmi_phb_op_delete_biryday_reminder_no;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

    mmi_confirm_display(
        (WCHAR *) get_string(STR_ID_BDAY_ALERT_DEL_QUERY),
        MMI_EVENT_QUERY,
        &arg);

}
#endif
#endif


static void mmi_phb_op_delete_entry_pre_req(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
    if (mmi_tdl_br_is_delete_show_confirm(g_mmi_phb_list_p->store_index))
    {
        g_mmi_phb_op_cntx.extra_handler = 1;
        mmi_phb_op_delete_birhday_reminder_confirm(group_id);    
    }
    else
#endif
#endif
    {
        /* if no confirm, then auto delete birthday reminder */
        g_mmi_phb_op_cntx.extra_handler = 0;
        mmi_phb_op_delete_entry_req(group_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_delete_confirm
 * DESCRIPTION
 *  Confirms before deleting a phone book entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_op_delete_confirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_check_storage_accessible(srv_phb_get_storage(g_mmi_phb_list_p->store_index)))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
    }
    else
    {
        mmi_confirm_property_struct arg;
        
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.parent_id = group_id;
        arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;
        arg.f_auto_map_empty_softkey = MMI_FALSE;

        mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
        g_mmi_phb_confirm_user_data.sg_id = group_id;
        g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_op_delete_entry_pre_req;

        arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

        mmi_confirm_display(
            (UI_string_type) GetString(STR_GLOBAL_DELETE_ASK),
            MMI_EVENT_QUERY,
            &arg);
    }
}


#define MMI_PHB_OP_COPY_MOVE_DUP_PART
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_copy_menu
 * DESCRIPTION
 *  entry function of copy option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_copy_menu(MMI_ID group_id, MMI_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_op_cntx.store_index = g_mmi_phb_list_p->store_index;
    
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, menu_gid, MENU_ID_PHB_COPY_TO_SIM, STR_ID_PHB_TO_SIM1);
    mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM2, menu_gid, MENU_ID_PHB_COPY_TO_SIM2, STR_ID_PHB_TO_SIM2);
#else
    mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM1, menu_gid, MENU_ID_PHB_COPY_TO_SIM, STR_ID_PHB_TO_SIM);
#endif

#if (MMI_MAX_SIM_NUM >= 3)
    mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM3, menu_gid, MENU_ID_PHB_COPY_TO_SIM3, STR_ID_PHB_TO_SIM3);
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    mmi_phb_sim_ctrl_not_available_hide_menu(MMI_SIM4, menu_gid, MENU_ID_PHB_COPY_TO_SIM4, STR_ID_PHB_TO_SIM4);
#endif

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    mmi_phb_memory_card_not_available_hide_menu(menu_gid, MENU_ID_PHB_COPY_TO_MEMORY_CARD);
#endif
#if 0
#if  defined(__MMI_FILE_MANAGER__) && defined(__MMI_VCARD__)
#ifdef __OP01_FWPBW__
/* under construction !*/
#endif
#endif
#endif
}


void mmi_phb_op_copy_contact(U16 store_index, U8 dst_storage, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_UPDATE;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_COPY;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_UPDATE;
    g_mmi_phb_op_cntx.store_index = store_index;
    g_mmi_phb_op_cntx.dst_storage = dst_storage;
    g_mmi_phb_op_cntx.sg_id = group_id;

    srv_phb_oplib_copy_contact(
        dst_storage,
        store_index,
        mmi_phb_op_single_cb,
        &g_mmi_phb_op_cntx);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_pre_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_copy_pre_req(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(group_id, STR_GLOBAL_COPYING);

    mmi_phb_op_copy_contact(g_mmi_phb_list_p->store_index, g_mmi_phb_op_cntx.dst_storage, group_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_copy_to_phone_confirm
 * DESCRIPTION
 *  Confirms before copying entry from one
 *  location to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_op_copy_to_phone_confirm(MMI_ID group_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (!mmi_phb_memory_card_is_ready(storage, MMI_TRUE))
    {
        return;    
    }
#endif
    
    if (!mmi_phb_check_storage_status(storage, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE))
    {
        g_mmi_phb_op_cntx.dst_storage = storage;
        mmi_phb_op_copy_pre_req(group_id);
    }
}





/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_copy_to_sim_confirm
 * DESCRIPTION
 *  Confirms before copying entry from one
 *  location to sim2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_op_copy_to_sim_confirm(MMI_ID group_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    U16 phb_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_check_storage_accessible(storage))
    {
        str_id = STR_ID_PHB_ADN_FORBID;
    }
    else
    {
        for(index = 0; index < MMI_PHB_NUMBER_FIELD_COUNT; index++)
        {
            srv_phb_get_number_ex(g_mmi_phb_op_cntx.store_index, index, phb_number,NULL,MMI_PHB_NUMBER_LENGTH + 1);

            if (mmi_phb_is_num_in_bcd(phb_number, 'w', (MMI_PHB_NUMBER_LENGTH + 1)))
            {
                str_id = STR_ID_PHB_COPY_NUM_WITH_W;
            }
            else if (mmi_phb_is_num_in_bcd(phb_number, '?', (MMI_PHB_NUMBER_LENGTH + 1)))
            {
                str_id = STR_ID_PHB_COPY_NUM_WITH_QUESTION_MARK;
            }
        }

        if (str_id == 0 && srv_phb_get_used_contact(storage) == srv_phb_get_total_contact(storage))
        {
            str_id = mmi_phb_get_storage_full_str_id(storage);    
        }
    }

    if (str_id)
    {
        mmi_popup_display_simple_ext(
            str_id,
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
    }
    else
    {
        g_mmi_phb_op_cntx.dst_storage = storage;
        mmi_phb_op_copy_pre_req(group_id);
    }
}


#if  defined(__MMI_FILE_MANAGER__) && defined(__MMI_VCARD__)
static void mmi_phb_op_copy_to_file(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_info_struct *contact_p;
    mmi_vcard_field_data_struct vcard_data;
    mmi_id parent_id = group_id;
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_p = mmi_phb_contact_get_contact(g_mmi_phb_list_p->store_index);

    memset(&vcard_data, 0, sizeof(mmi_vcard_field_data_struct));
    mmi_phb_contact_mmi_to_vcard(contact_p, &vcard_data);

    sg_id = cui_vcard_build_vcard_creat(parent_id);
    
    g_mmi_phb_list_p->child_id = sg_id;

    cui_vcard_build_vcard_set_data(sg_id, &vcard_data);
    cui_vcard_build_vcard_set_type(sg_id, MMI_VCARD_BUILD_VCARD_FMG);
    
    cui_vcard_build_vcard_run(sg_id);

    mmi_phb_contact_free_contact(contact_p);
}
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_VCARD__) */


#ifndef LOW_COST_SUPPORT
void mmi_phb_op_move_contact(MMI_ID group_id, U16 store_index, U8 dst_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_UPDATE;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_MOVE;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_UPDATE;
    g_mmi_phb_op_cntx.store_index = store_index;
    g_mmi_phb_op_cntx.dst_storage = dst_storage;
    g_mmi_phb_op_cntx.sg_id = group_id;

    srv_phb_oplib_move_contact(
        dst_storage,
        store_index,
        mmi_phb_op_single_cb,
        &g_mmi_phb_op_cntx);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_move_pre_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_move_pre_req(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_show_in_progress(group_id, STR_GLOBAL_MOVING);

    mmi_phb_op_move_contact(group_id, g_mmi_phb_list_p->store_index, g_mmi_phb_op_cntx.dst_storage);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_move_confirm
 * DESCRIPTION
 *  Confirms before moving the entry which
 *  the user selects from the PHB list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_op_move_confirm(MMI_ID group_id, phb_storage_enum dest_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 phb_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    U16 str_id = 0, query_str = 0;
    U8 storage;
    mmi_confirm_property_struct arg;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_op_cntx.store_index = g_mmi_phb_list_p->store_index;
    storage = srv_phb_get_storage(g_mmi_phb_op_cntx.store_index);

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (!mmi_phb_memory_card_is_ready(dest_storage, MMI_TRUE))
    {
        return;    
    }
#endif
  
    if (!srv_phb_check_storage_accessible(dest_storage) || !srv_phb_check_storage_accessible(storage))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
        return;
    }

    for(i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
    {
        srv_phb_get_number_ex(g_mmi_phb_op_cntx.store_index,i,phb_number,NULL,MMI_PHB_NUMBER_LENGTH + 1);

        if (mmi_phb_is_num_in_bcd(phb_number, 'w', (MMI_PHB_NUMBER_LENGTH + 1)))
        {
            mmi_popup_display_simple_ext(
                STR_ID_PHB_MOVE_NUM_WITH_W,
                MMI_EVENT_FAILURE,
                group_id,
                NULL);
            
            return;
        }
        else if (mmi_phb_is_num_in_bcd(phb_number, '?', (MMI_PHB_NUMBER_LENGTH + 1)))
        {
            mmi_popup_display_simple_ext(
                STR_ID_PHB_MOVE_NUM_WITH_QUESTION_MARK,
                MMI_EVENT_FAILURE,
                group_id,
                NULL);
            return;
        }
    }

    if (srv_phb_check_storage_status(dest_storage) == SRV_PHB_STORAGE_STATUS_FULL)
    {
        str_id = mmi_phb_get_storage_full_str_id(dest_storage);
        mmi_popup_display_simple_ext(
            str_id,
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
    }
    else
    {
        g_mmi_phb_op_cntx.dst_storage = dest_storage;
        if (mmi_phb_check_storage(MMI_TRUE, storage) && mmi_phb_check_storage(MMI_FALSE, dest_storage))
        {
            query_str = STR_ID_PHB_INFO_MAY_LOST_WHEN_COPY;
            mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
            arg.parent_id = group_id;
            arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;
            
            mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
            g_mmi_phb_confirm_user_data.sg_id = group_id;
            g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_op_move_pre_req;
            
            arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;
            
            mmi_confirm_display(
                (WCHAR *) get_string(query_str),
                MMI_EVENT_QUERY,
                &arg);
        }
        else
        {
            mmi_phb_op_move_pre_req(group_id);
        }
            
    }
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_move_sim_confirm
 * DESCRIPTION
 *  Confirms before moving the entry which
 *  the user selects from the PHB list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_move_sim_confirm(MMI_ID group_id, phb_storage_enum dest_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    U8 storage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage = srv_phb_get_storage(g_mmi_phb_op_cntx.store_index);
    if (!srv_phb_check_storage_accessible(storage) || !srv_phb_check_storage_accessible(dest_storage))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
        return;
    }

    if (srv_phb_check_storage_status(dest_storage) == SRV_PHB_STORAGE_STATUS_FULL)
    {
        str_id = mmi_phb_get_storage_full_str_id(dest_storage);
        mmi_popup_display_simple_ext(
            str_id,
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
    }
    else
    {
        g_mmi_phb_op_cntx.dst_storage = dest_storage;
        mmi_phb_op_move_pre_req(group_id);
    }
}
#endif


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_memory_card_available_not_hide_menu
 * DESCRIPTION
 *  check memory card, if available, enable menu.
 * PARAMETERS
 *  inline_gid: inline group id, menu_id: menu id 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_memory_card_available_not_hide_menu(MMI_ID inline_gid, U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        cui_menu_set_item_hidden(inline_gid, menu_id, MMI_FALSE);
    }
}
#endif


#if (MMI_MAX_SIM_NUM >= 2) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
void mmi_phb_entry_op_move_menu_ex(MMI_BOOL sim_status, mmi_sim_enum sim_id, mmi_id menu_gid, mmi_menu_id menu_id, U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_status)
    {
        cui_menu_set_item_hidden(menu_gid, menu_id, MMI_FALSE);
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        mmi_phb_sim_dynamic_name(sim_id, menu_gid, menu_id, string_id);
    #endif
    }
}


void mmi_phb_entry_op_move_menu(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = g_mmi_phb_list_p->store_index;
    MMI_BOOL sim1_status;
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_BOOL sim2_status;
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_BOOL sim3_status;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_BOOL sim4_status;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_op_cntx.store_index = store_index;
   
#ifdef __MMI_TELEPHONY_SUPPORT__   
    sim1_status = srv_sim_ctrl_is_available(MMI_SIM1);
#if (MMI_MAX_SIM_NUM >= 2)
    sim2_status = srv_sim_ctrl_is_available(MMI_SIM2);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    sim3_status = srv_sim_ctrl_is_available(MMI_SIM3);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    sim4_status = srv_sim_ctrl_is_available(MMI_SIM4);
#endif
#endif

#if (MMI_MAX_SIM_NUM >= 2)
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM2TOPHONE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM2TOSIM1, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM1TOSIM2, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_PHONETOSIM2, MMI_TRUE);
#endif    
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM1TOPHONE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_PHONETOSIM1, MMI_TRUE);
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_CARDTOPHONE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_PHONETOCARD, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_CARDTOSIM1, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM1TOCARD, MMI_TRUE);
#if (MMI_MAX_SIM_NUM >= 2)
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_CARDTOSIM2, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM2TOCARD, MMI_TRUE);
#endif
#endif

#if (MMI_MAX_SIM_NUM >= 3)
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_PHONETOSIM3, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM3TOPHONE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM1TOSIM3, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM3TOSIM1, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM3TOSIM2, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM2TOSIM3, MMI_TRUE);
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_CARDTOSIM3, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM3TOCARD, MMI_TRUE);
#endif
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM3TOSIM4, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM4TOSIM3, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_PHONETOSIM4, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM4TOPHONE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM1TOSIM4, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM4TOSIM1, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM2TOSIM4, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM4TOSIM2, MMI_TRUE);
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_CARDTOSIM4, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM4TOCARD, MMI_TRUE);
#endif
#endif

    if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
    {
        mmi_phb_entry_op_move_menu_ex(sim1_status, MMI_SIM1, menu_gid, MENU_MTPNP_PB_MOVE_PHONETOSIM1, STR_ID_PHB_TO_SIM1);
    #if (MMI_MAX_SIM_NUM >= 2)    
        mmi_phb_entry_op_move_menu_ex(sim2_status, MMI_SIM2, menu_gid, MENU_MTPNP_PB_MOVE_PHONETOSIM2, STR_ID_PHB_TO_SIM2);
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_phb_entry_op_move_menu_ex(sim3_status, MMI_SIM3, menu_gid, MENU_PB_MOVE_PHONETOSIM3, STR_ID_PHB_TO_SIM3);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_phb_entry_op_move_menu_ex(sim4_status, MMI_SIM4, menu_gid, MENU_PB_MOVE_PHONETOSIM4, STR_ID_PHB_TO_SIM4);
    #endif
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        mmi_phb_memory_card_available_not_hide_menu(menu_gid, MENU_MTPNP_PB_MOVE_PHONETOCARD);
    #endif
    }
    else if (srv_phb_get_storage(store_index) == PHB_STORAGE_SIM2)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM2TOPHONE, MMI_FALSE);       
        mmi_phb_entry_op_move_menu_ex(sim1_status, MMI_SIM1, menu_gid, MENU_MTPNP_PB_MOVE_SIM2TOSIM1, STR_ID_PHB_TO_SIM1);
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_phb_entry_op_move_menu_ex(sim3_status, MMI_SIM3, menu_gid, MENU_PB_MOVE_SIM2TOSIM3, STR_ID_PHB_TO_SIM3);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_phb_entry_op_move_menu_ex(sim4_status, MMI_SIM4, menu_gid, MENU_PB_MOVE_SIM2TOSIM4, STR_ID_PHB_TO_SIM4);
    #endif
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        mmi_phb_memory_card_available_not_hide_menu(menu_gid, MENU_MTPNP_PB_MOVE_SIM2TOCARD);
    #endif
    }
    else if (srv_phb_get_storage(store_index) == PHB_STORAGE_SIM)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_SIM1TOPHONE, MMI_FALSE);
        mmi_phb_entry_op_move_menu_ex(sim2_status, MMI_SIM2, menu_gid, MENU_MTPNP_PB_MOVE_SIM1TOSIM2, STR_ID_PHB_TO_SIM2);
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_phb_entry_op_move_menu_ex(sim3_status, MMI_SIM3, menu_gid, MENU_PB_MOVE_SIM1TOSIM3, STR_ID_PHB_TO_SIM3);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_phb_entry_op_move_menu_ex(sim4_status, MMI_SIM4, menu_gid, MENU_PB_MOVE_SIM1TOSIM4, STR_ID_PHB_TO_SIM4);
    #endif
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        mmi_phb_memory_card_available_not_hide_menu(menu_gid, MENU_MTPNP_PB_MOVE_SIM1TOCARD);
    #endif
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (srv_phb_get_storage(store_index) == PHB_STORAGE_SIM3)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM3TOPHONE, MMI_FALSE);
        mmi_phb_entry_op_move_menu_ex(sim1_status, MMI_SIM1, menu_gid, MENU_PB_MOVE_SIM3TOSIM1, STR_ID_PHB_TO_SIM1);
        mmi_phb_entry_op_move_menu_ex(sim2_status, MMI_SIM2, menu_gid, MENU_PB_MOVE_SIM3TOSIM2, STR_ID_PHB_TO_SIM2);
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_phb_entry_op_move_menu_ex(sim4_status, MMI_SIM4, menu_gid, MENU_PB_MOVE_SIM3TOSIM4, STR_ID_PHB_TO_SIM4);
    #endif
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        mmi_phb_memory_card_available_not_hide_menu(menu_gid, MENU_MTPNP_PB_MOVE_SIM3TOCARD);
    #endif
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (srv_phb_get_storage(store_index) == PHB_STORAGE_SIM4)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_PB_MOVE_SIM4TOPHONE, MMI_FALSE);
        mmi_phb_entry_op_move_menu_ex(sim1_status, MMI_SIM1, menu_gid, MENU_PB_MOVE_SIM4TOSIM1, STR_ID_PHB_TO_SIM1);
        mmi_phb_entry_op_move_menu_ex(sim2_status, MMI_SIM2, menu_gid, MENU_PB_MOVE_SIM4TOSIM2, STR_ID_PHB_TO_SIM2);
        mmi_phb_entry_op_move_menu_ex(sim3_status, MMI_SIM3, menu_gid, MENU_PB_MOVE_SIM4TOSIM3, STR_ID_PHB_TO_SIM3);
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        mmi_phb_memory_card_available_not_hide_menu(menu_gid, MENU_MTPNP_PB_MOVE_SIM4TOCARD);
    #endif
    }
#endif
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_MOVE_CARDTOPHONE, MMI_FALSE);
        mmi_phb_entry_op_move_menu_ex(sim1_status, MMI_SIM1, menu_gid, MENU_MTPNP_PB_MOVE_CARDTOSIM1, STR_ID_PHB_TO_SIM1);
    #if (MMI_MAX_SIM_NUM >= 2)
        mmi_phb_entry_op_move_menu_ex(sim2_status, MMI_SIM2, menu_gid, MENU_MTPNP_PB_MOVE_CARDTOSIM2, STR_ID_PHB_TO_SIM2);
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_phb_entry_op_move_menu_ex(sim3_status, MMI_SIM3, menu_gid, MENU_MTPNP_PB_MOVE_CARDTOSIM3, STR_ID_PHB_TO_SIM3);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_phb_entry_op_move_menu_ex(sim4_status, MMI_SIM4, menu_gid, MENU_MTPNP_PB_MOVE_CARDTOSIM4, STR_ID_PHB_TO_SIM4);
    #endif
    }
#endif
}
#endif
#endif /* LOW_COST_SUPPORT */


#ifdef __MMI_PHB_DEFAULT_NUMBER__
void mmi_phb_dial_default_number_and_start_browser_ex(U16 store_index, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field;
    mmi_phb_op_action_cntx_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_field(store_index, &field);

    mmi_phb_op_cntx_init(&op_cntx);
    op_cntx.store_index = store_index;
    op_cntx.op_action = MMI_PHB_OP_CALL;

    /* dial default number */
    if (field & SRV_PHB_ENTRY_FIELD_ALL_NUM)
    {
        U16 number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
        
        if (srv_phb_get_default_number(store_index, number, NULL, (U16)(MMI_PHB_NUMBER_LENGTH + 1)) && number[0])
        {
            op_cntx.data = number;
            srv_phb_get_default_number_id(store_index, (U8*) &op_cntx.data_type);

            if (op_cntx.data_type == 0xff)
            {
                op_cntx.data_type = SRV_PHB_ENTRY_FIELD_NUMBER;
            }
            
            mmi_phb_ucm_make_call(&op_cntx, group_id);
        }
        else
        {
            mmi_phb_dial_normal_call_ex(&op_cntx, group_id);
        }
    }
    /* if no number exist , press send key to start browser */
    else if (!mmi_phb_og_start_browser(store_index, group_id))
    {
        /* if no URL address , popup no number exist */
        mmi_phb_ucm_make_call(&op_cntx, group_id);
    }

}


void mmi_phb_dial_default_number_and_start_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_action_cntx_struct op_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_init(&op_cntx);
    op_cntx.store_index = g_mmi_phb_list_p->store_index;
    op_cntx.op_action = MMI_PHB_OP_CALL_SEND_KEY;

    mmi_phb_op_start(&op_cntx, mmi_frm_group_get_active_id());
}
#endif /* __MMI_PHB_DEFAULT_NUMBER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dial_ip_call
 * DESCRIPTION
 *  dial the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_dial_ip_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = mmi_phb_cntx_mgr_get_current_sg_id();
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_phb_op_action_cntx_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx = (mmi_phb_list_cntx_struct *) mmi_frm_group_get_user_data(sg_id);

    mmi_phb_op_cntx_init(&op_cntx);
    op_cntx.store_index = list_cntx->store_index;
    op_cntx.op_action = MMI_PHB_OP_IP_CALL;
    op_cntx.ip_call = MMI_TRUE;
    
    mmi_phb_op_start(&op_cntx, sg_id);
}


static void mmi_phb_choose_field_delete_scr(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(group_id, SCR_PHB_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_close(group_id, SCR_CHOOSE_NUMBER);
}


static void mmi_phb_dial_call_choose_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data;
    mmi_phb_op_action_cntx_struct op_cntx;
    U32 highlight_index = g_mmi_phb_choose_field.highlight_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data = (mmi_phb_choose_number_struct *) mmi_frm_scrn_get_user_data(mmi_phb_cntx_mgr_get_current_sg_id(), SCR_CHOOSE_NUMBER);

    mmi_phb_op_cntx_init(&op_cntx);

    op_cntx.store_index = choose_data->store_index;
    op_cntx.data = g_mmi_phb_choose_field.number_to_dial[highlight_index];
    op_cntx.data_type = g_mmi_phb_choose_field.number_type[highlight_index];
    op_cntx.ip_call = choose_data->ip_call;
    op_cntx.op_action = MMI_PHB_OP_CALL;
    
    mmi_phb_ucm_make_call(&op_cntx, mmi_phb_cntx_mgr_get_current_sg_id());

}


static void mmi_phb_dial_call(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = (mmi_phb_choose_number_struct *) scrn_data->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        scrn_data->group_id,
        choose_data->store_index,
        SRV_PHB_ENTRY_FIELD_ALL_NUM,
        (FunctionPtr)mmi_phb_dial_call,
        mmi_phb_dial_call_choose_number,
        mmi_frm_scrn_close_active_id,
        mmi_phb_dial_call_choose_number,
        MMI_FALSE,
        MMI_FALSE);
}


static void mmi_phb_dial_normal_call_ex(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = 
        (mmi_phb_choose_number_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_choose_number_struct), SRV_PHB_MEMORY_TYPE_CTR);
    mmi_id sg_id = group_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data->store_index = op_cntx->store_index;
    choose_data->ip_call = op_cntx->ip_call;

    if (sg_id == GRP_ID_INVALID)
    {
        sg_id = GRP_ID_CHOOSE_FIELD;
        
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            sg_id,
            mmi_dummy_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    mmi_frm_scrn_first_enter_ex(
        sg_id,
        SCR_CHOOSE_NUMBER,
        (FunctionPtr) mmi_phb_dial_call,
        choose_data,
        mmi_phb_choose_number_scrn_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dial_normal_call
 * DESCRIPTION
 *  dial the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_dial_normal_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_action_cntx_struct op_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_init(&op_cntx);
    op_cntx.store_index = g_mmi_phb_list_p->store_index;
    op_cntx.op_action = MMI_PHB_OP_CALL;

    mmi_phb_op_start(&op_cntx, mmi_frm_group_get_active_id());
}


static void mmi_phb_ucm_make_call_cb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_destory_cm_user_data(make_call_cb_para->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_ucm_make_call
 * DESCRIPTION
 *  Makes call to a number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_ucm_make_call(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para; 
    void *cm_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);

    make_call_para.adv_para.is_ip_dial = op_cntx->ip_call;

    mmi_phb_choose_field_delete_scr(group_id);

    cm_user_data = srv_phb_create_cm_user_data(NULL, op_cntx->data_type, op_cntx->store_index);

    /* choose right call type to make call: MAUI_02058877, MAUI_02055879 */
    if (op_cntx->data_type == SRV_PHB_ENTRY_FIELD_VOIP)
    {
        make_call_para.dial_type = SRV_UCM_VOIP_CALL_TYPE;
    }
    else
    {
        make_call_para.dial_type &= ~SRV_UCM_VOIP_CALL_TYPE;
    }
    
    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;
    make_call_para.adv_para.after_make_call_callback = mmi_phb_ucm_make_call_cb;
    make_call_para.ucs2_num_uri = op_cntx->data;
    
    mmi_ucm_call_launch(0, &make_call_para);
}


//#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#if defined(__MMI_VIDEO_TELEPHONY__)
//#ifdef __MMI_VIDEO_TELEPHONY__
static void mmi_phb_video_call_choose_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data;
    mmi_phb_op_action_cntx_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data = (mmi_phb_choose_number_struct *) mmi_frm_scrn_get_user_data(mmi_phb_cntx_mgr_get_current_sg_id(), SCR_CHOOSE_NUMBER);

    mmi_phb_op_cntx_init(&op_cntx);

    op_cntx.store_index = choose_data->store_index;
    op_cntx.data = g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index];
    op_cntx.data_type = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];
    op_cntx.ip_call = choose_data->ip_call;
    op_cntx.op_action = MMI_PHB_OP_VIDEO_CALL;
    
    mmi_phb_ucm_make_video_call(&op_cntx, mmi_phb_cntx_mgr_get_current_sg_id());
}

static void mmi_phb_video_call(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = (mmi_phb_choose_number_struct *) scrn_data->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        scrn_data->group_id,
        choose_data->store_index,
        SRV_PHB_ENTRY_FIELD_ALL_NUM,
        (FunctionPtr)mmi_phb_video_call,
        mmi_phb_video_call_choose_number,
        mmi_frm_scrn_close_active_id,
        mmi_phb_video_call_choose_number,
        MMI_FALSE,
        MMI_FALSE);
}


void mmi_phb_ucm_make_video_call_ex(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = 
        (mmi_phb_choose_number_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_choose_number_struct), SRV_PHB_MEMORY_TYPE_CTR);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data->store_index = op_cntx->store_index;
    choose_data->ip_call = op_cntx->ip_call;

    mmi_frm_scrn_first_enter_ex(
        group_id,
        SCR_CHOOSE_NUMBER,
        (FunctionPtr) mmi_phb_video_call,
        choose_data,
        mmi_phb_choose_number_scrn_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_ucm_make_call
 * DESCRIPTION
 *  Makes call to a number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_ucm_make_video_call(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para; 
    void *cm_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);

    make_call_para.adv_para.is_ip_dial = op_cntx->ip_call;

    mmi_phb_choose_field_delete_scr(group_id);

    cm_user_data = srv_phb_create_cm_user_data(NULL, op_cntx->data_type, op_cntx->store_index);

    /* choose right call type to make call: MAUI_02058877, MAUI_02055879 */
#ifdef __MMI_3G_SWITCH__
	if (srv_netset_get_3g_capacity_sim() == MMI_SIM2)
    {
    	make_call_para.dial_type = SRV_UCM_VIDEO_CALL_TYPE_SIM2;
    }
    else
    {
    	make_call_para.dial_type = SRV_UCM_VIDEO_CALL_TYPE;
    }
#else
    make_call_para.dial_type = SRV_UCM_VIDEO_CALL_TYPE;
#endif

    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;
    make_call_para.adv_para.after_make_call_callback = mmi_phb_ucm_make_call_cb;
    make_call_para.ucs2_num_uri = op_cntx->data;
    
    mmi_ucm_call_launch(0, &make_call_para);
}


static void mmi_phb_voice_call_choose_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data;
    mmi_phb_op_action_cntx_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data = (mmi_phb_choose_number_struct *) mmi_frm_scrn_get_user_data(mmi_phb_cntx_mgr_get_current_sg_id(), SCR_CHOOSE_NUMBER);

    mmi_phb_op_cntx_init(&op_cntx);

    op_cntx.store_index = choose_data->store_index;
    op_cntx.data = g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index];
    op_cntx.data_type = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];
    op_cntx.ip_call = choose_data->ip_call;
    op_cntx.op_action = MMI_PHB_OP_VOICE_CALL;
    
    mmi_phb_ucm_make_voice_call(&op_cntx, mmi_phb_cntx_mgr_get_current_sg_id());
}

static void mmi_phb_voice_call(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = (mmi_phb_choose_number_struct *) scrn_data->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        scrn_data->group_id,
        choose_data->store_index,
        SRV_PHB_ENTRY_FIELD_ALL_NUM,
        (FunctionPtr)mmi_phb_voice_call,
        mmi_phb_voice_call_choose_number,
        mmi_frm_scrn_close_active_id,
        mmi_phb_voice_call_choose_number,
        MMI_FALSE,
        MMI_FALSE);
}


void mmi_phb_ucm_make_voice_call_ex(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = 
        (mmi_phb_choose_number_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_choose_number_struct), SRV_PHB_MEMORY_TYPE_CTR);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data->store_index = op_cntx->store_index;
    choose_data->ip_call = op_cntx->ip_call;

    mmi_frm_scrn_first_enter_ex(
        group_id,
        SCR_CHOOSE_NUMBER,
        (FunctionPtr) mmi_phb_voice_call,
        choose_data,
        mmi_phb_choose_number_scrn_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_ucm_make_call
 * DESCRIPTION
 *  Makes call to a number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_ucm_make_voice_call(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para; 
    void *cm_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);

    make_call_para.adv_para.is_ip_dial = op_cntx->ip_call;

    mmi_phb_choose_field_delete_scr(group_id);

    cm_user_data = srv_phb_create_cm_user_data(NULL, op_cntx->data_type, op_cntx->store_index);

    /* choose right call type to make call: MAUI_02058877, MAUI_02055879 */
    make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
    
    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;
    make_call_para.adv_para.after_make_call_callback = mmi_phb_ucm_make_call_cb;
    make_call_para.ucs2_num_uri = op_cntx->data;
    
    mmi_ucm_call_launch(0, &make_call_para);
}

#endif /*defined(__MMI_VIDEO_TELEPHONY__) */


void mmi_phb_view_contact_dial(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_view_contact_cntx_struct * cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_phb_view_contact_cntx_struct *) mmi_frm_group_get_user_data(group_id);

    mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_CALL);
}


#if defined(__IP_NUMBER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dial_ip_call
 * DESCRIPTION
 *  dial the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_view_contact_dial_ip_call(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_view_contact_cntx_struct * cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_phb_view_contact_cntx_struct *) mmi_frm_group_get_user_data(group_id);

    mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_IP_CALL);
}
#endif /* defined(__IP_NUMBER__) */ 


#ifdef __MMI_EMAIL__
void mmi_phb_option_op_send_email(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_view_contact_cntx_struct * cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_phb_view_contact_cntx_struct *) mmi_frm_group_get_user_data(group_id);

    mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_EMAIL);
}
#endif


#ifdef BROWSER_SUPPORT
void mmi_phb_option_op_start_broswer(MMI_ID group_id, MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_og_start_browser(g_mmi_phb_view_contact_p->store_index, group_id);
    
    cui_menu_close(menu_gid);
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_phb_is_start_broswer_permit
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*
*****************************************************************************/
MMI_BOOL mmi_phb_is_start_broswer_permit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef BROWSER_SUPPORT    
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        return MMI_FALSE;
    }

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */

#if (MMI_MAX_SIM_NUM == 1)
    
    if (!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        return MMI_FALSE;
    }
    
#else
    if (!((srv_sim_ctrl_is_available(MMI_SIM1) == MMI_TRUE && srv_mode_switch_get_current_mode() != SRV_MODE_SWITCH_SIM2)
          || (srv_sim_ctrl_is_available(MMI_SIM2) == MMI_TRUE && srv_mode_switch_get_current_mode() != SRV_MODE_SWITCH_SIM1)
          )
       )
    {
        return MMI_FALSE;
    }
        
#endif

    return MMI_TRUE;
#else /* BROWSER_SUPPORT */
    return MMI_FALSE;
#endif /* BROWSER_SUPPORT */
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_og_start_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_og_start_browser(U16 store_index, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
#ifdef BROWSER_SUPPORT    
#ifdef __MMI_PHB_INFO_FIELD__
    U16 *url;
#endif /* __MMI_PHB_INFO_FIELD__ */
#endif /* BROWSER_SUPPORT */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef BROWSER_SUPPORT    
#ifdef __MMI_PHB_INFO_FIELD__
    if (mmi_phb_is_start_broswer_permit()
        && (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
        )
    {
        url = (U16 *) mmi_phb_mem_malloc(sizeof(U16) * (MMI_PHB_URL_LENGTH + 1), SRV_PHB_MEMORY_TYPE_CTR);

        srv_phb_get_url(store_index, url, MMI_PHB_URL_LENGTH);

        if (mmi_ucs2strlen((const CHAR *) url))
        {        
            wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8) url);

            mmi_phb_mem_free(url);

            return MMI_TRUE;
        }

        mmi_phb_mem_free(url);
    }
#endif /* __MMI_PHB_INFO_FIELD__ */
#endif /* BROWSER_SUPPORT */

    return MMI_FALSE;
}


#ifdef __MMI_PHB_CALLER_RES__
static void mmi_phb_option_op_view_pic(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    FuncPtr func_ptr = NULL;
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !(defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)))
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    if (g_mmi_phb_res_p->selected_pic_index == (g_mmi_phb_resource.total_image_id - 1))
    {
        func_ptr = (FuncPtr)mmi_phb_image_view_from_phb_folder;
    }
    else
    {
        func_ptr = (FuncPtr)mmi_phb_entry_image_view_default_pic_ext;
    }

    if (!mmi_phb_usb_app_unavailable_popup(0))
    {
        mmi_frm_scrn_first_enter(
            group_id,
            SCR_VIEW_PICTURE,
            func_ptr,
            NULL);
    }
#else /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */ 
    mmi_frm_scrn_first_enter(
        group_id,
        SCR_VIEW_PICTURE,
        (FunctionPtr) mmi_phb_entry_image_view_default_pic_ext,
        NULL);
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */
#endif
}


#ifdef __MMI_PHB_CALLER_VIDEO__
void mmi_phb_option_op_play_video(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 selected_video_index = g_mmi_phb_res_p->selected_video_index;
    FuncPtr func_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (selected_video_index == (g_mmi_phb_resource.total_video_id - 1)
	#if 0	
    #ifdef __MMI_SWFLASH__
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
	#endif
        )
    {
        if (!mmi_phb_usb_app_unavailable_popup(0))
        {
            func_ptr = (FuncPtr)mmi_phb_video_view_from_file;
        }
    }
    else if (selected_video_index != 0)
    {
        func_ptr = (FuncPtr)mmi_phb_video_view_from_default;
    }

    if (func_ptr != NULL)
    {
        mmi_frm_scrn_first_enter(
            group_id,
            SCR_ID_PHB_VIDEO_VIEW,
            func_ptr,
            NULL);
    }
}
#endif /* __MMI_PHB_CALLER_VIDEO__ */
#endif /* __MMI_PHB_CALLER_RES__ */


#ifdef __MMI_UNIFIED_COMPOSER__
void mmi_phb_uc_send_msg(CHAR* addr_p, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_entry_write_struct data;
    mmi_uc_addr_struct addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
    memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));
    data.addr_num = 1;
    addr.addr = (kal_uint8*) addr_p;

    if (addr_p[0] == '\0' && addr_p[1] == '\0')
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NO_NUMBER, 
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
    }
    else
    {
        if (mmi_ucs2chr(addr_p, L'@') == NULL)
        {
            addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
        }
        else
        {
            addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
        }

        addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
        data.addr = &addr;
        data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;
        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
    }
}


static void mmi_phb_uc_send_msg_choose_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_uc_send_msg((CHAR*) g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index], mmi_phb_cntx_mgr_get_current_sg_id());
    
    mmi_frm_scrn_close(mmi_phb_cntx_mgr_get_current_sg_id(), SCR_CHOOSE_NUMBER);
}

static void mmi_phb_us_send_msg_scr(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = (mmi_phb_choose_number_struct *) scrn_data->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        scrn_data->group_id,
        choose_data->store_index,
        (SRV_PHB_ENTRY_FIELD_GSM_NUM | SRV_PHB_ENTRY_FIELD_EMAIL),
        (FunctionPtr) mmi_phb_us_send_msg_scr,
        mmi_phb_uc_send_msg_choose_done,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_FALSE,
        MMI_FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_uc_send_msg_choose_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_uc_send_msg_choose_entry(U16 store_index, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = 
        (mmi_phb_choose_number_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_choose_number_struct), SRV_PHB_MEMORY_TYPE_CTR);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data->store_index = store_index;

    mmi_frm_scrn_first_enter_ex(
        group_id,
        SCR_CHOOSE_NUMBER,
        (FunctionPtr) mmi_phb_us_send_msg_scr,
        choose_data,
        mmi_phb_choose_number_scrn_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_contact_option_entry_send_message
 * DESCRIPTION
 *  Prepare data to send sms through PHB
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_view_contact_option_entry_send_message(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_view_contact_cntx_struct * cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_phb_view_contact_cntx_struct *) mmi_frm_group_get_user_data(group_id);

    mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_MSG);
}
#else /* __MMI_UNIFIED_COMPOSER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sms_send_data_for_entry
 * DESCRIPTION
 *  Sends the name & number info of the selected PHB entry to SMS
 * PARAMETERS
 *  number      [IN]        Input number string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sms_send_data_for_entry(CHAR *number, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    mmi_sms_write_msg_para_struct sendData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(number) == 0)
    {
        mmi_popup_display_simple_ext(
                STR_GLOBAL_NO_NUMBER, 
                MMI_EVENT_FAILURE,
                group_id,
                NULL);
    }
    else
    {
        memset(ascii_number, 0, sizeof(ascii_number));
        memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
        mmi_ucs2_n_to_asc(ascii_number, number, MMI_PHB_NUMBER_LENGTH + 1);

        sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
        sendData.ascii_addr = (U8*) ascii_number;

        mmi_sms_write_msg_lanch(0, &sendData);
    }

    mmi_frm_scrn_close(group_id, SCR_CHOOSE_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sms_send_data_for_entry_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sms_send_data_for_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_sms_send_data_for_entry(
        (CHAR*) g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index],
        mmi_phb_cntx_mgr_get_current_sg_id());
}


static void mmi_phb_sms_send_msg_scr(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = (mmi_phb_choose_number_struct *) scrn_data->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        scrn_data->group_id,
        choose_data->store_index,
        (SRV_PHB_ENTRY_FIELD_GSM_NUM),
        (FunctionPtr) mmi_phb_sms_send_msg_scr,
        mmi_phb_sms_send_data_for_entry_list,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_FALSE,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sms_send_data_choose_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sms_send_data_choose_entry(U16 store_index, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = 
        (mmi_phb_choose_number_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_choose_number_struct), SRV_PHB_MEMORY_TYPE_CTR);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data->store_index = store_index;

    MMI_ASSERT(group_id != GRP_ID_INVALID);

    mmi_frm_scrn_first_enter_ex(
        group_id,
        SCR_CHOOSE_NUMBER,
        (FunctionPtr) mmi_phb_sms_send_msg_scr,
        choose_data,
        mmi_phb_choose_number_scrn_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sms_pre_send_data_for_entry
 * DESCRIPTION
 *  Prepare data to send sms through PHB
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_view_contact_send_sms(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_view_contact_cntx_struct * cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_phb_view_contact_cntx_struct *) mmi_frm_group_get_user_data(group_id);

    mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_SMS);
}


/* Send MMS from phonebook entry option menu. */
#ifdef __MMI_MMS__

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mms_send_data_for_entry
 * DESCRIPTION
 *  Sends the name & number info of the selected PHB entry to SMS
 * PARAMETERS
 *  number      [IN]        Input number string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mms_send_data_for_entry(CHAR *number, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMS_SUPPORT    
    if (mmi_ucs2strlen((CHAR*) number) <= MMI_PHB_EMAIL_LENGTH)
    {
        if (mmi_ucs2strlen((CHAR*) number) == 0)
        {
            mmi_popup_display_simple_ext(
                STR_GLOBAL_NO_NUMBER, 
                MMI_EVENT_FAILURE,
                group_id,
                NULL);
        }
        else
        {
            mms_address_insert_hdlr((char*)number);
            mmi_frm_scrn_close(group_id, SCR_CHOOSE_NUMBER);
        }
    }
    else
#endif /* MMS_SUPPORT */
    {
        mmi_popup_display_simple_ext(
            STR_SMS_NUM_LEN_EXCEEDED, 
            MMI_EVENT_FAILURE,
            group_id,
            NULL);
    }

    mmi_frm_scrn_close(group_id, SCR_CHOOSE_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mms_send_data_for_entry_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_mms_send_data_for_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_mms_send_data_for_entry(
        (CHAR*) g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index],
        mmi_phb_cntx_mgr_get_current_sg_id());
}


static void mmi_phb_mms_send_msg_scr(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = (mmi_phb_choose_number_struct *) scrn_data->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        scrn_data->group_id,
        choose_data->store_index,
        (SRV_PHB_ENTRY_FIELD_MMS),
        (FunctionPtr) mmi_phb_mms_send_msg_scr,
        mmi_phb_mms_send_data_for_entry_list,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_FALSE,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mms_send_data_choose_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mms_send_data_choose_entry(U16 store_index, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_choose_number_struct *choose_data = 
        (mmi_phb_choose_number_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_choose_number_struct), SRV_PHB_MEMORY_TYPE_CTR);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    choose_data->store_index = store_index;

    mmi_frm_scrn_first_enter_ex(
        group_id,
        SCR_CHOOSE_NUMBER,
        (FunctionPtr) mmi_phb_mms_send_msg_scr,
        choose_data,
        mmi_phb_choose_number_scrn_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mms_pre_send_data_for_entry
 * DESCRIPTION
 *  Highlight handler for "Send SMS" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_view_contact_send_mms(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_view_contact_cntx_struct * cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_phb_view_contact_cntx_struct *) mmi_frm_group_get_user_data(group_id);

    mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_MMS);
}
#endif /* __MMI_MMS__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */

void mmi_phb_op_cntx_init(mmi_phb_op_action_cntx_struct *op_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(op_cntx != NULL);
    
    memset(op_cntx, 0, sizeof(mmi_phb_op_action_cntx_struct));
}


void mmi_phb_op_start(mmi_phb_op_action_cntx_struct *op_cntx, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_cntx->op_action)
    {
        case MMI_PHB_OP_CALL_SEND_KEY:
        case MMI_PHB_OP_CALL:
        {
            if (op_cntx->data)
            {
                mmi_phb_ucm_make_call(op_cntx, group_id);
            }
            else
            {
                if (op_cntx->op_action == MMI_PHB_OP_CALL_SEND_KEY)
                {
                #ifdef __MMI_PHB_DEFAULT_NUMBER__
                    mmi_phb_dial_default_number_and_start_browser_ex(op_cntx->store_index, group_id);
                #else /* __MMI_PHB_DEFAULT_NUMBER__ */
                    mmi_phb_dial_normal_call_ex(op_cntx, group_id);
                #endif /* __MMI_PHB_DEFAULT_NUMBER__ */
                }
                else
                {
                    mmi_phb_dial_normal_call_ex(op_cntx, group_id);
                }
            }
            break;
        }
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
	#if defined(__MMI_VIDEO_TELEPHONY__)
        case MMI_PHB_OP_VIDEO_CALL:
        {
            if (op_cntx->data)
            {
                mmi_phb_ucm_make_video_call(op_cntx, group_id);
            }
            else
            {
                mmi_phb_ucm_make_video_call_ex(op_cntx, group_id);
            }
            break;
        }
        case MMI_PHB_OP_VOICE_CALL:
        {
            if (op_cntx->data)
            {
                mmi_phb_ucm_make_voice_call(op_cntx, group_id);
            }
            else
            {
                mmi_phb_ucm_make_voice_call_ex(op_cntx, group_id);
            }
            break;
        }
    #endif /* defined(__MMI_VIDEO_TELEPHONY__) */
        case MMI_PHB_OP_IP_CALL:
        {
            op_cntx->ip_call = MMI_TRUE;
            
            if (op_cntx->data)
            {
                mmi_phb_ucm_make_call(op_cntx, group_id);
            }
            else
            {
                mmi_phb_dial_normal_call_ex(op_cntx, group_id);
            }
            break;
        }

    #ifdef __MMI_UNIFIED_COMPOSER__
        case MMI_PHB_OP_MSG:
        {
            if (IsMessagesReEntering())
            {
                mmi_popup_display_simple_ext(
                    STR_GLOBAL_NOT_AVAILABLE, 
                    MMI_EVENT_FAILURE,
                    group_id,
                    NULL);   
            }
            else
            {
                if (op_cntx->data)
                {
                    mmi_phb_uc_send_msg((CHAR*)op_cntx->data, group_id);
                }
                else
                {
                    mmi_phb_uc_send_msg_choose_entry(op_cntx->store_index, group_id);
                }
            }
            break;
        }

    #else

        case MMI_PHB_OP_SMS:
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            if (!mmi_sms_is_reenter_message())
            {
                if (op_cntx->data)
                {
                    mmi_phb_sms_send_data_for_entry((CHAR*) op_cntx->data, group_id);
                }
                else
                {
                    mmi_phb_sms_send_data_choose_entry(op_cntx->store_index, group_id);
                }
            }
        #endif /* __MMI_TELEPHONY_SUPPORT__ */
            break;
        }

    #ifdef __MMI_MMS__
        case MMI_PHB_OP_MMS:
        {
            if (IsMessagesReEntering())
            {
                mmi_popup_display_simple_ext(
                    STR_GLOBAL_NOT_AVAILABLE,
                    MMI_EVENT_FAILURE,
                    group_id,
                    NULL);
            }
            else
            {
                if (op_cntx->data)
                {
                    mmi_phb_mms_send_data_for_entry((CHAR*)op_cntx->data, group_id);
                }
                else
                {
                    mmi_phb_mms_send_data_choose_entry(op_cntx->store_index, group_id);
                }
            }
            break;
        }
    #endif
    #endif

    #ifdef __MMI_EMAIL__
        case MMI_PHB_OP_EMAIL:
        {
            if (op_cntx->data)
            {
                U16 name[MMI_PHB_NAME_LENGTH + 1];
                srv_phb_get_name(op_cntx->store_index, name, MMI_PHB_NAME_LENGTH);
                
                mmi_email_app_send_to_ext((CHAR*) op_cntx->data, (CHAR*) name);
            }
            else
            {
                /* not support now */
            }
            break;
        }
    #endif
    
        default:
            break;
    }
}

#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __USB_IN_NORMAL_MODE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_IMPS__ */
#endif


#if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_send_postcard
 * DESCRIPTION
 *  give the store_index to send postcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_send_postcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    mms_content_entry_struct data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_mmi_phb_list_p->store_index;

    memset(&data, 0x00, sizeof(mms_content_entry_struct));
    data.msg_type = MMS_MSG_TYPE_POSTCARD;
    mms_general_insert_hdlr(&data);
    /* should call postcard_foward after insert_hdlr */
    mmi_postcard_forward_from_phonebook_entry(store_index);
}
#endif /* defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__) */


#ifdef __MMI_CM_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_to_blacklist_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_add_to_blacklist_done(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_enum result;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = SRV_CALLSET_VOICE_CALL;
#endif
    result = srv_callset_blacklist_add_number(
                (U8)mmi_ucs2strlen((CHAR*)g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index]),
                (WCHAR*)g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index],
            #ifdef __MMI_CM_BLACK_LIST_EXT__          
                &adv_param,
            #else
                NULL,
            #endif
                NULL);

    if (result == SRV_CALLSET_RESULT_OK)
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_phb_popup_display_ext(
            srv_callset_get_result_string_id(result),
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_to_blacklist_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_add_to_blacklist_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    MMI_ID sg_id = mmi_phb_cntx_mgr_get_current_sg_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = sg_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;

    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = sg_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_add_to_blacklist_done;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

    mmi_confirm_display(
    #ifdef __MMI_CM_BLACK_LIST_EXT__
        (WCHAR *) get_string(STR_ID_PHB_ADD_TO_VOICE_BLACKLIST_QUERY),
    #else
        (WCHAR *) get_string(STR_ID_PHB_ADD_TO_BLACKLIST_QUERY),
    #endif
        MMI_EVENT_QUERY,
        &arg);

    mmi_frm_scrn_close(sg_id, SCR_CHOOSE_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_to_blacklist_choose_entry
 * DESCRIPTION
 *  add to blacklist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_add_to_blacklist_choose_entry(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        group_id,
        g_mmi_phb_list_p->store_index,
        SRV_PHB_ENTRY_FIELD_GSM_NUM,
        (FunctionPtr)mmi_phb_add_to_blacklist_choose_entry,
        mmi_phb_add_to_blacklist_pre_entry,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_FALSE,
        MMI_FALSE);
}


#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_CM_BLACK_LIST_EXT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_to_video_blacklist_done
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_add_to_video_blacklist_done(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_enum result;
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_adv_param_struct adv_param;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = SRV_CALLSET_VIDEO_CALL;
#endif
    result = srv_callset_blacklist_add_number(
                (U8)mmi_ucs2strlen((CHAR*)g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index]),
                (WCHAR*)g_mmi_phb_choose_field.number_to_dial[g_mmi_phb_choose_field.highlight_index],
            #ifdef __MMI_CM_BLACK_LIST_EXT__           
                &adv_param,
            #else
                NULL,
            #endif
                NULL);

    if (result == SRV_CALLSET_RESULT_OK)
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_phb_popup_display_ext(
            srv_callset_get_result_string_id(result),
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_to_video_blacklist_pre_entry
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_add_to_video_blacklist_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    MMI_ID sg_id = mmi_phb_cntx_mgr_get_current_sg_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = sg_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;

    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = sg_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_add_to_video_blacklist_done;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

    mmi_confirm_display(
        (WCHAR *) get_string(STR_ID_PHB_ADD_TO_VIDEO_BLACKLIST_QUERY),
        MMI_EVENT_QUERY,
        &arg);

    mmi_frm_scrn_close(sg_id, SCR_CHOOSE_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_to_video_blacklist_choose_entry
 * DESCRIPTION
 *  MTK81195 MAUI_02930560
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_add_to_video_blacklist_choose_entry(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        group_id,
        g_mmi_phb_list_p->store_index,
        SRV_PHB_ENTRY_FIELD_GSM_NUM,
        (FunctionPtr)mmi_phb_add_to_blacklist_choose_entry,
        mmi_phb_add_to_video_blacklist_pre_entry,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_FALSE,
        MMI_FALSE);
}
#endif
#endif /* __MMI_CM_BLACK_LIST__ */


#ifdef __MMI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_send_contact_menu_check
 * DESCRIPTION
 *  send vcard option menu check function
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE               :                    need hide send vcard menuy
 *  MMI_FALSE              :                    need unhide send vcard menuy
 *****************************************************************************/
MMI_BOOL mmi_phb_send_contact_menu_check(mmi_id group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_hide = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
  #ifdef __MMI_TELEPHONY_SUPPORT__
    if (srv_sms_is_hide_send_sms_menu_item() == MMI_TRUE)
    {
        cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_SMS, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_SMS, MMI_FALSE);
        is_hide = MMI_FALSE;
    }
  #else /* __MMI_TELEPHONY_SUPPORT__ */
    cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_SMS, MMI_TRUE);
  #endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif

#if defined(MMS_SUPPORT) && !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
    if (!mms_is_ready())
    {
        cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_MMS, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_MMS, MMI_FALSE);
        is_hide = MMI_FALSE;
    }
#endif

#if  defined(__MMI_EMAIL__)
    if (!mmi_email_is_email_can_forward())
    {
        cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_EMAIL, MMI_TRUE);

    }
    else
    {
        cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_EMAIL, MMI_FALSE);
        is_hide = MMI_FALSE;
    }
#endif

#if defined(__MMI_OPP_SUPPORT__)
    if (mmi_bt_is_to_display_bt_menu() == MMI_FALSE)
    {
        cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_BT, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(group_id, MENU_ID_VCARD_FORWARD_BT, MMI_FALSE);
        is_hide = MMI_FALSE;
    }
#endif
    return is_hide;
}


void mmi_phb_vcard_send_select_card(mmi_vcard_build_vcard_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_info_struct *contact_p;
    mmi_vcard_field_data_struct vcard_data;
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_p = mmi_phb_contact_get_contact(g_mmi_phb_list_p->store_index);

    memset(&vcard_data, 0, sizeof(mmi_vcard_field_data_struct));
    mmi_phb_contact_mmi_to_vcard(contact_p, &vcard_data);

    sg_id = cui_vcard_build_vcard_creat(g_mmi_phb_list_p->sg_id);

    g_mmi_phb_list_p->child_id = sg_id;
    
    cui_vcard_build_vcard_set_data(sg_id, &vcard_data);
    cui_vcard_build_vcard_set_type(sg_id, type);
    cui_vcard_build_vcard_run(sg_id);

    mmi_phb_contact_free_contact(contact_p);
}

#if defined(__MMI_OPP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_op_send_vcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_op_send_vcard(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    sg_id = cui_vcard_multi_send_creat(group_id);
    cui_vcard_multi_send_set_contact_list(sg_id, g_mmi_phb_list_p->mark_array, g_mmi_phb_list_p->mark_count);
    cui_vcard_multi_send_run(sg_id);
}
#endif /* defined(__MMI_OPP_SUPPORT__) */

#if defined(__MMI_MULTI_VCARD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_op_backup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_op_backup(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    sg_id = cui_vcard_export_vcard_creat(group_id);
    cui_vcard_export_vcard_set_contact_list(sg_id, g_mmi_phb_list_p->mark_array, g_mmi_phb_list_p->mark_count);
    cui_vcard_export_vcard_run(sg_id);
}
#endif /* defined(__MMI_MULTI_VCARD__) */

#endif /* __MMI_VCARD__ */

#if 0
#if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

#if defined(__MMI_BPP20_SUPPORT__)
typedef enum
{
    MMI_PHB_BPP_N,
    MMI_PHB_BPP_LN,
    MMI_PHB_BPP_TEL_CELL,
    MMI_PHB_BPP_TEL_HOME,
    MMI_PHB_BPP_TEL_WORK,
    MMI_PHB_BPP_TEL_FAX,
    MMI_PHB_BPP_ORG,
    MMI_PHB_BPP_EMAIL,
    MMI_PHB_BPP_EMAIL2,
    MMI_PHB_BPP_BDAY,
    MMI_PHB_BPP_TITLE,
    MMI_PHB_BPP_URL,                    
    MMI_PHB_BPP_ADR_POBOX,
    MMI_PHB_BPP_ADR_EXTENSION,
    MMI_PHB_BPP_ADR_STREET,
    MMI_PHB_BPP_ADR_CITY,
    MMI_PHB_BPP_ADR_STATE,
    MMI_PHB_BPP_ADR_POSTALCODE,
    MMI_PHB_BPP_ADR_COUNTRY,
    MMI_PHB_BPP_NOTE,
    MMI_PHB_BPP_IMPS,
    MMI_PHB_BPP_VOIP,
    MMI_PHB_BPP_FIELD_TOTAL
} mmi_phb_bpp_field_enum;

static CHAR *g_phb_bpp_field[MMI_PHB_BPP_FIELD_TOTAL] = 
{
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    "First Name",
    "Last Name",
#else
    "Name",
    "",
#endif
    "Cell Number",
    "Home Number",
    "Office Number",
    "Fax Number",
    "Company Name",
    "Email Address",
    "Email Address2",
    "Birthday",
    "Title",
    "Url",
    "P.O. Box",
    "Extension",
    "Street",
    "City",
    "State/Province",
    "Postal/ZIP Code",
    "Conutry/Region",
    "Note",
    "Imps",
    "Voip",
};


#define phb_compose_buf_size 1024

static const CHAR PhbTitle[] = "title";
static const xhtml_prop_struct PhbTitleProps[] = 
{
    {XHTML_PROP_BORDER_LEFT,    "solid 1px Gray"},
    {XHTML_PROP_BORDER_RIGHT,   "solid 1px Gray"},
    {XHTML_PROP_BORDER_TOP,     "solid 1px Gray"},
    {XHTML_PROP_BORDER_BOTTOM,  "solid 1px Gray"},
    {XHTML_PROP_COLOR,          "black"},
    {XHTML_PROP_VERTICAL_ALIGN, "middle"},
    {XHTML_PROP_TEXT_ALIGN,     XHTML_LEFT},
};

static const xhtml_rule_struct PhbTitleRule = 
{
    PhbTitle, NULL, STYLE_RULE_CLASS, PhbTitleProps, 7
};

static const CHAR PhbValue[] = "value";
static const xhtml_prop_struct PhbValueProps[] = 
{
    {XHTML_PROP_PADDING,        "2px"},
    {XHTML_PROP_BORDER_LEFT,    "solid 1px Gray"},
    {XHTML_PROP_BORDER_RIGHT,   "solid 1px Gray"},
    {XHTML_PROP_BORDER_TOP,     "solid 1px Gray"},
    {XHTML_PROP_BORDER_BOTTOM,  "solid 1px Gray"},
    {XHTML_PROP_COLOR,          "black"},
    {XHTML_PROP_VERTICAL_ALIGN, "middle"},
    {XHTML_PROP_TEXT_ALIGN,     XHTML_LEFT},
};

static const xhtml_rule_struct PhbValueRule = 
{
    PhbValue, NULL, STYLE_RULE_CLASS, PhbValueProps, 8
};


static void mmi_phb_compose_contact_image(void* handle, mmi_phb_contact_info_struct *contact_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16  img_type = 0;
    S32  img_width = 0;
    S32  img_height = 0;
    U32  image_size = 0;
    WCHAR * pbuf = mmi_phb_mem_malloc(SRV_FMGR_PATH_MAX_LEN + 1, SRV_PHB_MEMORY_TYPE_ADM);
    xhtml_img_attr_struct image;
    xhtml_attr_struct attr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    if (((img_type =gdi_image_get_type_from_file((S8 *) contact_info->picture)) == GDI_IMAGE_TYPE_JPG || img_type == GDI_IMAGE_TYPE_JPG)
        && gdi_image_get_dimension_file((S8 *) contact_info->picture, &img_width, &img_height)>=0
#ifdef __USB_IN_NORMAL_MODE__                     
        && srv_usb_is_in_mass_storage_mode()==MMI_FALSE
#endif            
        )
    {
        FS_HANDLE fh;
 
        img_width = (S32)bpp_pixel_to_mm(img_width);
        img_height = (S32)bpp_pixel_to_mm(img_height);

        mmi_wcscpy(pbuf, contact_info->picture);

        fh = FS_Open(contact_info->picture, FS_READ_ONLY);
        if(fh > 0)
        {
            FS_GetFileSize(fh, &image_size);
            FS_Close(fh);
        }
    }
    else
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */
    {
        U8* pimg_buf = NULL;
        
        gdi_image_get_dimension_id(IMG_ID_PHB_LIST_ICON1, &img_width, &img_height);
 
        img_width = (S32)bpp_pixel_to_mm(img_width);
        img_height = (S32)bpp_pixel_to_mm(img_height);

        img_type = gdi_image_get_type_from_id(IMG_ID_PHB_LIST_ICON1);
        
        if(GDI_IMAGE_TYPE_JPG==img_type)
        {
            pimg_buf = gdi_image_get_buf_ptr_from_id(IMG_ID_PHB_LIST_ICON1);
            image_size  = gdi_image_get_buf_len_from_id(IMG_ID_PHB_LIST_ICON1);
            kal_wsprintf(pbuf, "%s%d.jpg",BPP_MEM_DRV, (S32)pimg_buf);
        }
        else
        {
            pbuf[0] ='\0';
        }
    }

    bpp_xhtml_element_begin(handle, XHTML_ELE_TABLE_ROW, NULL, 0);
    
    attr.name = XHTML_ATTR_CLASS;
    attr.value = PhbTitle;
    bpp_xhtml_inline_element(handle, XHTML_ELE_TABLE_CELL, &attr, 1, "Phone");
    
    attr.value = PhbValue;
    bpp_xhtml_element_begin(handle, XHTML_ELE_TABLE_CELL, &attr, 1);

    image.width = img_width;
    image.height = img_height;
    image.size = image_size;
    image.src = pbuf;
    image.type = NULL;
    
    bpp_xhtml_image_element(handle, &image);
    
    bpp_xhtml_element_end(handle, XHTML_ELE_TABLE_CELL);
    
    bpp_xhtml_element_end(handle, XHTML_ELE_TABLE_ROW);

    mmi_phb_mem_free(pbuf);
}


static void mmi_phb_compose_contact_info(void * handle, mmi_phb_contact_info_struct *contact_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    xhtml_attr_struct attr;
    CHAR value_buffer[PHB_BPP_FIELD_VALUE_BUFFER_LENGTH];
    S32 i, number_field;
    mmi_phb_num_type_enum type;
    char * title_str = NULL;
    mmi_phb_contact_info_struct *temp_contact_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_contact_p = g_mmi_phb_contact_p;
    g_mmi_phb_contact_p = contact_info;
    
    for (i = 0; i < MMI_PHB_BPP_FIELD_TOTAL; i++)
    {
        number_field = 0;
        memset(value_buffer, 0, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
        switch (i)
        {
            case MMI_PHB_BPP_N:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->name, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                break;

        #ifdef __MMI_PHB_LAST_NAME_FIELD__
            case MMI_PHB_BPP_LN:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->last_name, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                break;
        #endif
                    
            case MMI_PHB_BPP_TEL_CELL:
                mmi_ucs2_to_asc(value_buffer, (CHAR *) contact_info->number);
                break;
                    
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            case MMI_PHB_BPP_TEL_HOME:
                mmi_ucs2_to_asc(value_buffer, (CHAR *) contact_info->opt_num[mmi_phb_edit_get_opt_number_field(0) - MMI_PHB_FIELD_OPT_NUM_1].number);
                type = contact_info->opt_num[mmi_phb_edit_get_opt_number_field(0) - MMI_PHB_FIELD_OPT_NUM_1].type;
                number_field = 1;
                break;
                    
            case MMI_PHB_BPP_TEL_WORK:
                mmi_ucs2_to_asc(value_buffer, (CHAR *) contact_info->opt_num[mmi_phb_edit_get_opt_number_field(1) - MMI_PHB_FIELD_OPT_NUM_1].number);
                type = contact_info->opt_num[mmi_phb_edit_get_opt_number_field(1) - MMI_PHB_FIELD_OPT_NUM_1].type;
                number_field = 1;
                break;
                    
            case MMI_PHB_BPP_TEL_FAX:
                mmi_ucs2_to_asc(value_buffer, (CHAR *) contact_info->opt_num[mmi_phb_edit_get_opt_number_field(2) - MMI_PHB_FIELD_OPT_NUM_1].number);
                type = contact_info->opt_num[mmi_phb_edit_get_opt_number_field(2) - MMI_PHB_FIELD_OPT_NUM_1].type;
                number_field = 1;
                break;

            case MMI_PHB_BPP_ORG:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->companyName, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                break;

            case MMI_PHB_BPP_EMAIL:
                mmi_ucs2_to_asc(value_buffer, (CHAR *) contact_info->emailAddress);
                break;

        #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
            case MMI_PHB_BPP_EMAIL2:
                mmi_ucs2_to_asc(value_buffer, (CHAR *) contact_info->emailAddress2);
                break;
        #endif
        #endif /* __MMI_PHB_OPTIONAL_FIELD__ */  

        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)                      
            case MMI_PHB_BPP_BDAY:
                mmi_ucs2_to_asc(value_buffer, (CHAR *) contact_info->bday);
                break;         
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */                
        #if defined(__MMI_PHB_INFO_FIELD__)        
            case MMI_PHB_BPP_TITLE:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->title, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                break;    
                    
            case MMI_PHB_BPP_URL:
                mmi_ucs2_to_asc(value_buffer, (CHAR *) contact_info->url);
                break;        
                    
            case MMI_PHB_BPP_ADR_POBOX:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->pobox, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                break;
                    
            case MMI_PHB_BPP_ADR_EXTENSION:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->extension, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);       
                break;
                    
            case MMI_PHB_BPP_ADR_STREET:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->street, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);      
                break;
                    
            case MMI_PHB_BPP_ADR_CITY:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->city, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                break;
                    
            case MMI_PHB_BPP_ADR_STATE:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->state, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);     
                break;
                    
            case MMI_PHB_BPP_ADR_POSTALCODE:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->postalcode, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);        
                break;
                    
            case MMI_PHB_BPP_ADR_COUNTRY:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->country, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);         
                break;
                    
            case MMI_PHB_BPP_NOTE:
                mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)contact_info->note, value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                break;
                    
        #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
        #if 0
        #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MMI_IMPS__) */
		#endif
		#if 0
        #if defined(__MMI_VOIP__)                      
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MMI_VOIP__) */
		#endif
            default:
                break;
        }
        if(value_buffer && strlen(value_buffer) != 0)
        {
            bpp_xhtml_element_begin(handle, XHTML_ELE_TABLE_ROW, NULL, 0);
            attr.name = XHTML_ATTR_CLASS;
            attr.value = PhbTitle;
            
            if (number_field)
            {
                if (type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    bpp_xhtml_inline_element(
                        handle, XHTML_ELE_TABLE_CELL, &attr, 1, g_phb_bpp_field[MMI_PHB_BPP_TEL_CELL]);
                }
                else if (type == MMI_PHB_NUM_TYPE_HOME)
                {
                    bpp_xhtml_inline_element(
                        handle, XHTML_ELE_TABLE_CELL, &attr, 1, g_phb_bpp_field[MMI_PHB_BPP_TEL_HOME]);
                }
                else if (type == MMI_PHB_NUM_TYPE_OFFICE)
                {
                    bpp_xhtml_inline_element(
                        handle, XHTML_ELE_TABLE_CELL, &attr, 1, g_phb_bpp_field[MMI_PHB_BPP_TEL_WORK]);
                }
                else if (type == MMI_PHB_NUM_TYPE_FAX)
                {
                    bpp_xhtml_inline_element(
                        handle, XHTML_ELE_TABLE_CELL, &attr, 1, g_phb_bpp_field[MMI_PHB_BPP_TEL_FAX]);
                }
                else
                {
                }
            }
            else
            {
                bpp_xhtml_inline_element(
                    handle, XHTML_ELE_TABLE_CELL, &attr, 1, g_phb_bpp_field[i]);
            }
            
            attr.value = PhbValue;
            bpp_xhtml_inline_element(
                handle, XHTML_ELE_TABLE_CELL, &attr, 1, value_buffer);
            bpp_xhtml_element_end(handle, XHTML_ELE_TABLE_ROW);
        }
    }

    g_mmi_phb_contact_p = temp_contact_p;
}


static void mmi_phb_bpp_attr_buf_malloc(xhtml_attr_struct *attribute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 5; i++)
    {
        attribute[i].name = (char *)mmi_phb_mem_malloc(PHB_BPP_FIELD_TITLE_BUFFER_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        attribute[i].value = (char *)mmi_phb_mem_malloc(PHB_BPP_FIELD_VALUE_BUFFER_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
    }
}


static void mmi_phb_compose_contact(void *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    xhtml_attr_struct attr;
    mmi_phb_contact_info_struct *contact_info = NULL;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info = mmi_phb_contact_get_contact(g_mmi_phb_list_p->store_index);

    bpp_xhtml_element_begin(handle, XHTML_ELE_BODY, NULL, 0);

    attr.name = XHTML_ATTR_ALIGN;
    attr.value = "center";
    bpp_xhtml_element_begin(handle, XHTML_ELE_DIV, &attr, 1);

    bpp_xhtml_element_begin(handle, XHTML_ELE_TABLE, NULL, 0);

    bpp_xhtml_inline_element(handle, XHTML_ELE_CAPTION, NULL, 0, "PhoneBook");

    mmi_phb_compose_contact_image(handle, contact_info);
    mmi_phb_compose_contact_info(handle, contact_info);

    bpp_xhtml_element_end(handle, XHTML_ELE_TABLE);
    
    bpp_xhtml_element_end(handle, XHTML_ELE_DIV);
    
    bpp_xhtml_element_end(handle, XHTML_ELE_BODY);

    if (contact_info != NULL)
    {
        mmi_phb_contact_free_contact(contact_info); 
    }
}

static U32 mmi_phb_bt_fill_xhtml_file(evt_bt_print_data_req_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR * version;
    xhtml_output_struct xhtml;
    void * handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    version = cui_bt_printing_xhtml_version(evt->inst);
    
    xhtml.type = XHTML_OUT_FILE;
    xhtml.u.file = evt->storage.u.file;
    
    handle = bpp_xhtml_open(version, &xhtml);

    bpp_xhtml_element_begin(handle, XHTML_ELE_HEAD, NULL, 0);
    
    bpp_xhtml_empty_element(handle, XHTML_ELE_TITLE, NULL, 0);

    bpp_xhtml_style_begin(handle, NULL);
    
    cui_bt_printing_style_rules(evt->inst, handle);

    bpp_xhtml_style_rule(handle, &PhbTitleRule, 1);
    bpp_xhtml_style_rule(handle, &PhbValueRule, 1);
    
    bpp_xhtml_style_end(handle);

    bpp_xhtml_element_end(handle, XHTML_ELE_HEAD);
    
    mmi_phb_compose_contact(handle);
    
    return bpp_xhtml_close(handle);
}


mmi_ret mmi_phb_bpp_cui_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_BT_PRINT_START:
        {
            evt_bt_print_start_struct *bt_evt = (evt_bt_print_start_struct *) evt;
            return MMI_RET_OK;
        }

        case EVT_BT_PRINT_COMPLETE:
        {
            evt_bt_print_complete_struct *bt_evt = (evt_bt_print_complete_struct *) evt;
            return MMI_RET_OK;
        }

        case EVT_BT_PRINT_DATA_REQ:
        {
            evt_bt_print_data_req_struct *bt_evt = (evt_bt_print_data_req_struct *) evt;
            bt_print_data_struct *data = &bt_evt->storage;
            data->size = mmi_phb_bt_fill_xhtml_file(bt_evt);

            if (data->size)
            {
                data->content_type = BT_PRINT_CONTENT_XHTML;
                data->more = 0;
                cui_bt_printing_set_data(bt_evt->inst, data);
            }
            return MMI_RET_OK;
        }

        default:
            return MMI_RET_DONT_CARE;
    }
}


static void mmi_phb_bpp_print(void)
{
#if 1 /* BPP split */
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    cui_bt_printing_launch(GRP_ID_PHB_MAIN, BT_PRINT_CONTACT, NULL, 0);

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __USB_IN_NORMAL_MODE__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BPP split */    
}
#endif /* defined(__MMI_BPP20_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_sim_entry_by_location
 * DESCRIPTION
 *  Return the number to idle screen for quick access
 * PARAMETERS
 *  entryNum        [IN]        Location to be search
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_phb_get_sim_entry_by_location(U16 entryNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 hasEntry = 0, storage;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return hasEntry;
    }
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
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
#else /* __MMI_DUAL_SIM__ */
  #ifdef __MMI_TELEPHONY_SUPPORT__
    if (srv_sim_ctrl_is_available(MMI_SIM1) && srv_phb_check_storage_accessible(PHB_STORAGE_SIM))
    {
        storage = PHB_STORAGE_SIM;
    }
    else
  #endif
    {
        mmi_phb_popup_display_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE);
        return hasEntry;
    }
#endif /* __MMI_DUAL_SIM__ */

    if (entryNum == 0 || entryNum > srv_phb_get_total_contact(storage))
    {
        mmi_phb_popup_display_ext(
            STR_ID_PHB_INVALID_LOCATION,
            MMI_EVENT_FAILURE);
    }
    else
    {
        srv_phb_record_index_to_store_index(storage, entryNum, &store_index);
        
        if (srv_phb_check_entry_exist(store_index))
        {
            hasEntry = 1;
            cui_phb_view_contact(GRP_ID_ROOT, store_index);
        }
        else
        {
            mmi_phb_popup_display_ext(
                STR_ID_PHB_NO_CONTACT,
                MMI_EVENT_FAILURE);
        }
    }

    return hasEntry;
}


#ifdef __MMI_URI_AGENT__
typedef struct
{
    srv_uriagent_appid_enum appid;
    srv_uriagent_uri_request_hdlr_cb cb;
    mmi_id sg_id;

    MMI_BOOL evt_out;
} mmi_phb_uriagent_info_struct;

extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);

void mmi_phb_uriagent_wtai_save_entry(srv_uriagent_appid_enum appid, char *url, char *param, srv_uriagent_options_enum options, srv_uriagent_uri_request_hdlr_cb cb);
mmi_phb_uriagent_err_enum mmi_phb_uriagent_parse_uri(U8* uri, CHAR* uc2_name, CHAR* ucs2_num);
void mmi_phb_uriagent_exec_callback(srv_uriagent_uri_request_hdlr_cb cb, srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, U32 result);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_uri_agent_registration
 * DESCRIPTION
 *  Initialize URI agent registration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init_uri_agent_registration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uriagent_err_enum err_code = SRV_URIAGENT_ERR_UNSUPPORTED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_INIT_URI_AGENT_REGISTERATION);
    
    err_code = srv_uriagent_register_hdlr_by_prefix("wtai://wp/ap", mmi_phb_uriagent_wtai_save_entry, MMI_FALSE);

    if (err_code != SRV_URIAGENT_ERR_OK)
    {
        MMI_ASSERT(0);
    }
}


static mmi_ret mmi_phb_uriagent_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_save_contact_result_struct* save_number_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_INACTIVE:
            break;
        
        case EVT_ID_GROUP_ACTIVE:
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_phb_uriagent_info_struct *uriagent_info = (mmi_phb_uriagent_info_struct *)evt->user_data;

            if (!uriagent_info->evt_out)
            {
                mmi_phb_uriagent_exec_callback(uriagent_info->cb, uriagent_info->appid, SRV_URIAGENT_APPID_PHONEBOOK, MMI_PHB_URIAGENT_ERR_PHB_WRITE_ERROR);
            }
            
            if (evt->user_data != NULL)
            {
                mmi_phb_mem_free(evt->user_data);
            }
            break;
        }
        
        case EVT_ID_PHB_SAVE_CONTACT:
        {
            U32 result = 0;
            mmi_phb_uriagent_info_struct *uriagent_info = (mmi_phb_uriagent_info_struct *)evt->user_data;
            save_number_result = (cui_phb_save_contact_result_struct*)evt;

            if (save_number_result->result >= 0)
            {
                result = 0;
            }
            else if (save_number_result->result == SRV_PHB_ADN_FORBID)
            {
                result = MMI_PHB_URIAGENT_ERR_FDN_ON_ERROR;
            }
            else if (save_number_result->result == SRV_PHB_NUMBER_TOO_LONG)
            {
                result = MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG;
            }
            else
            {
                result = MMI_PHB_URIAGENT_ERR_PHB_WRITE_ERROR;
            }
                
            mmi_phb_uriagent_exec_callback(uriagent_info->cb, uriagent_info->appid, SRV_URIAGENT_APPID_PHONEBOOK, result);
            uriagent_info->evt_out = MMI_TRUE;
            
            cui_phb_save_contact_close(uriagent_info->sg_id);
            break;
        }
        
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {            
            mmi_phb_uriagent_info_struct *uriagent_info = (mmi_phb_uriagent_info_struct *)evt->user_data;
            mmi_phb_uriagent_exec_callback(uriagent_info->cb, uriagent_info->appid, SRV_URIAGENT_APPID_PHONEBOOK, MMI_PHB_URIAGENT_ERR_PHB_WRITE_ERROR);
            uriagent_info->evt_out = MMI_TRUE;

            cui_phb_save_contact_close(uriagent_info->sg_id);
            break;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_uriagent_wtai_save_entry
 * DESCRIPTION
 *  main execute function for phb UHA
 * PARAMETERS
 *  appid
 *  url
 *  param
 *  options: here is useless in phb, because phb will always popup confirm to user to check if save?
 *  cb
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_uriagent_wtai_save_entry(
        srv_uriagent_appid_enum appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_uriagent_err_enum parse_result = MMI_PHB_URIAGENT_ERR_OK;
    U16 ucs2_num_uri[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    U16 ucs2_name_uri[MMI_PHB_NAME_FIELD_LENGTH + 1];
    mmi_phb_uriagent_info_struct *uriagent_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_URIAGENT_WTAI_SAVE_ENTRY, appid, options, cb);

    if (!srv_phb_startup_is_phb_ready() || mmi_phb_check_processing())
    {
        parse_result = MMI_PHB_URIAGENT_ERR_PHB_NOT_READY;
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        parse_result = MMI_PHB_URIAGENT_ERR_PHB_IN_SYNC;
    }
#endif /* __SYNCML_SUPPORT__ */
    else if (mmi_phb_check_storage_full(PHB_STORAGE_MAX, MMI_FALSE))
    {
        parse_result = MMI_PHB_URIAGENT_ERR_PHB_IS_FULL;
    }

    if (parse_result != MMI_PHB_URIAGENT_ERR_OK)
    {
        mmi_phb_uriagent_display_popup((U8)parse_result);
        mmi_phb_uriagent_exec_callback(cb, appid, SRV_URIAGENT_APPID_PHONEBOOK, parse_result);
        return;
    }
    
    memset(ucs2_num_uri, 0, (MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
    memset(ucs2_name_uri, 0, (MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH);
    parse_result = mmi_phb_uriagent_parse_uri((U8*)url, (CHAR*) ucs2_name_uri, (CHAR*) ucs2_num_uri);

    if (!(parse_result == MMI_PHB_URIAGENT_ERR_OK || parse_result == MMI_PHB_URIAGENT_ERR_NAME_TOO_LONG || 
        parse_result == MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG || parse_result == MMI_PHB_URIAGENT_ERR_URI_FORMAT_WRONG))
        ASSERT(0);
      
    if (parse_result != MMI_PHB_URIAGENT_ERR_OK)
    {
        mmi_phb_uriagent_display_popup((U8)parse_result);
        mmi_phb_uriagent_exec_callback(cb, appid, SRV_URIAGENT_APPID_PHONEBOOK, parse_result);
        return;
    }

    uriagent_info = (mmi_phb_uriagent_info_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_uriagent_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
    uriagent_info->cb = cb;
    uriagent_info->appid = appid;
    uriagent_info->evt_out = MMI_FALSE;

    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_PHB_URIAGENT,
        mmi_phb_uriagent_proc,
        uriagent_info,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    uriagent_info->sg_id = cui_phb_save_contact_create(GRP_ID_PHB_URIAGENT);

    cui_phb_save_contact_set_type(uriagent_info->sg_id, CUI_PHB_SAVE_CONTACT_NEW);
    cui_phb_save_contact_set_name(uriagent_info->sg_id, ucs2_name_uri, NULL);
    cui_phb_save_contact_set_number(uriagent_info->sg_id, ucs2_num_uri);

    cui_phb_save_contact_run(uriagent_info->sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_uriagent_exec_callback
 * DESCRIPTION
 *  Execute uriagent callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_uriagent_exec_callback(
           srv_uriagent_uri_request_hdlr_cb cb,
           srv_uriagent_appid_enum ura_appid,
           srv_uriagent_appid_enum uha_appid,
           U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_URIAGENT_EXEC_CALLBACK, cb, ura_appid, uha_appid, result);

    if (cb != NULL)
    {
        cb(ura_appid, uha_appid, (unsigned int)result);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_uriagent_display_popup
 * DESCRIPTION
 *  Display popup about the information of phb UHA for uriagent
 * PARAMETERS
 *  U8 result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_uriagent_display_popup(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_URIAGENT_DISPLAY_POPUP, result);

    switch ((mmi_phb_uriagent_err_enum)result)
    {
        case MMI_PHB_URIAGENT_ERR_OK:
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_SAVED,
                MMI_EVENT_SUCCESS);
            break;
        }

        case MMI_PHB_URIAGENT_ERR_PHB_NOT_READY:
        {
            mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
            break;
        }

    #ifdef __MMI_PHB_USIM_FIELD__
        case MMI_PHB_URIAGENT_ERR_PHB_PROCESS_USIM:
        {
            mmi_phb_entry_not_ready(STR_ID_PHB_PROCESSING_USIM);
            break;
        }
    #endif

    #ifdef __SYNCML_SUPPORT__
        case MMI_PHB_URIAGENT_ERR_PHB_IN_SYNC:
        {
            mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
            break;
        }
    #endif

        case MMI_PHB_URIAGENT_ERR_URI_FORMAT_WRONG:
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_INVALID_FORMAT,
                MMI_EVENT_FAILURE);
            break;
        }
        
        case MMI_PHB_URIAGENT_ERR_NAME_TOO_LONG:
        {
            mmi_phb_popup_display_ext(
                STR_ID_PHB_URIAGENT_NAME_TOO_LONG,
                MMI_EVENT_FAILURE);
            break;
        }

        case MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG:
        {
            mmi_phb_popup_display_ext(
                STR_ID_PHB_URIAGENT_NUMBER_TOO_LONG,
                MMI_EVENT_FAILURE);
            break;
        }

        case MMI_PHB_URIAGENT_ERR_PHB_WRITE_ERROR:
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_UNFINISHED,
                MMI_EVENT_FAILURE);
            break;
        }

        case MMI_PHB_URIAGENT_ERR_FDN_ON_ERROR:
        {
            mmi_phb_popup_display_ext(
                STR_ID_PHB_ADN_FORBID,
                MMI_EVENT_FAILURE);
            break;
        }

        case MMI_PHB_URIAGENT_ERR_PHB_IS_FULL:
        {
            mmi_phb_popup_display_ext(
                STR_PBOOK_FULL_MSG,
                MMI_EVENT_FAILURE);
            break;
        }

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_uriagent_parse_uri
 * DESCRIPTION
 *  Parse URL passed by uri agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_phb_uriagent_err_enum mmi_phb_uriagent_parse_uri(U8* uri, CHAR* ucs2_name, CHAR* ucs2_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* cur_pos = (CHAR*)uri;
    CHAR* num_start_pos = NULL;
    CHAR* name_start_pos = NULL;
    U16 num_len, ucs2_num_len, ucs2_name_len;
    CHAR* temp_num_buff = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_pos = strstr((CHAR*)uri, ";");

    /* number */
    if (cur_pos == NULL)
    {
        return MMI_PHB_URIAGENT_ERR_URI_FORMAT_WRONG;
    }
    else
    {
        num_start_pos = cur_pos + 1;
    }

    cur_pos = strstr(num_start_pos, ";");

    // only have number
    if (cur_pos == NULL)
    {
        temp_num_buff = num_start_pos;
        ucs2_num_len = mmi_charset_utf8_to_ucs2_length_in_bytes((const kal_uint8*)temp_num_buff);

        if (*num_start_pos == '+')
        {
            if (ucs2_num_len > ((MMI_PHB_NUMBER_LENGTH + 1) * ENCODING_LENGTH))
            {
                return MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG;
            }
            else
            {
                mmi_chset_convert(
                    MMI_CHSET_UTF8,
                    MMI_CHSET_UCS2,
                    temp_num_buff,
                    ucs2_num,
                    (MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
            }
        }
        else
        {
            if (ucs2_num_len > MMI_PHB_NUMBER_LENGTH  * ENCODING_LENGTH)
            {
                return MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG;
            }
            else
            {
                mmi_chset_convert(
                    MMI_CHSET_UTF8,
                    MMI_CHSET_UCS2,
                    temp_num_buff,
                    ucs2_num,
                    (MMI_PHB_NUMBER_LENGTH + 1) * ENCODING_LENGTH);
            }
        }

        return MMI_PHB_URIAGENT_ERR_OK;
    }
    // have name and number
    else
    {
        name_start_pos = cur_pos + 1;
        ucs2_name_len = mmi_charset_utf8_to_ucs2_length_in_bytes((const kal_uint8*)name_start_pos);

        if (ucs2_name_len > MMI_PHB_NAME_FIELD_LENGTH  * ENCODING_LENGTH)
        {
            return MMI_PHB_URIAGENT_ERR_NAME_TOO_LONG;
        }
        
        num_len = name_start_pos - num_start_pos - 1;
        temp_num_buff = mmi_phb_mem_malloc(num_len + 1, SRV_PHB_MEMORY_TYPE_CTR);
        memset(temp_num_buff, 0x00, (num_len + 1));
        memcpy(temp_num_buff, num_start_pos, num_len);
        ucs2_num_len = mmi_charset_utf8_to_ucs2_length_in_bytes((const kal_uint8*)temp_num_buff);
    }
    
    if (*num_start_pos == '+')
    {
        if (ucs2_num_len > ((MMI_PHB_NUMBER_LENGTH + 1) * ENCODING_LENGTH))
        {
            mmi_phb_mem_free(temp_num_buff);
            return MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG;
        }
        else
        {
            mmi_chset_convert(
                MMI_CHSET_UTF8,
                MMI_CHSET_UCS2,
                temp_num_buff,
                ucs2_num,
                (MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
        }
    }
    else
    {
        if (ucs2_num_len > MMI_PHB_NUMBER_LENGTH  * ENCODING_LENGTH)
        {
            mmi_phb_mem_free(temp_num_buff);
            return MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG;
        }
        else
        {
            mmi_chset_convert(
                MMI_CHSET_UTF8,
                MMI_CHSET_UCS2,
                temp_num_buff,
                ucs2_num,
                (MMI_PHB_NUMBER_LENGTH + 1) * ENCODING_LENGTH);
        }
    }

    mmi_chset_convert(
        MMI_CHSET_UTF8,
        MMI_CHSET_UCS2,
        name_start_pos,
        (char*)ucs2_name,
        (MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH);
        
    mmi_phb_mem_free(temp_num_buff);
    
    return MMI_PHB_URIAGENT_ERR_OK;
}
#endif /* __MMI_URI_AGENT__ */


void mmi_phb_unsaved_data_init(srv_phb_contact_data_struct *contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contact != NULL)
    {
        memset(contact, 0, sizeof(srv_phb_contact_data_struct));
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        contact->default_number = 0xff;
    #endif
    }
}


#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
typedef struct
{
    U8 unsaved_data_num;
    U8 unsaved_data_index;
    U8 unsaved_data_state;

    mmi_phb_unsaved_data_node_struct *unsaved_data_head;
    mmi_phb_unsaved_data_node_struct *unsaved_data_end;
} mmi_phb_save_notify_struct;

static mmi_phb_save_notify_struct g_mmi_phb_unsaved_data;

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_free_node
 * DESCRIPTION
 *  free node function for unsaved data link list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_unsaved_data_free_node(mmi_phb_unsaved_data_node_struct *data_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(data_node != NULL);
    /* free all fields in phb_data */
    if (data_node->object->phb_data->name != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->name);
    }
    if (data_node->object->phb_data->number != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->number);
    }
#if defined(__MMI_PHB_INFO_FIELD__)
    if (data_node->object->phb_data->pobox != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->pobox);
    }

    if (data_node->object->phb_data->extension != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->extension);
    }

    if (data_node->object->phb_data->street != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->street);
    }

    if (data_node->object->phb_data->city != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->city);
    }

    if (data_node->object->phb_data->state != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->state);
    }

    if (data_node->object->phb_data->postalcode != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->postalcode);
    }

    if (data_node->object->phb_data->country != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data->country);
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */
    /* free other fields */
    if (data_node->object->phb_data != NULL)
    {
        mmi_phb_mem_free(data_node->object->phb_data);
    }
    if (data_node->object != NULL)
    {
        mmi_phb_mem_free(data_node->object);
    }
    mmi_phb_mem_free(data_node);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_init_node
 * DESCRIPTION
 *  init a node function for unsaved data link list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
struct mmi_phb_unsaved_data_node_struct* mmi_phb_unsaved_data_init_node(
            U8 storage,
            U32 show_type,
            srv_phb_contact_data_struct *phb_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct mmi_phb_unsaved_data_node_struct *data_node;
    U8 number_UCS2[(MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    U8 num_plus_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_node = mmi_phb_mem_malloc(sizeof(mmi_phb_unsaved_data_node_struct), SRV_PHB_MEMORY_TYPE_ADM); 
    memset(data_node, 0x00, sizeof(mmi_phb_unsaved_data_node_struct));
    
    data_node->object = mmi_phb_mem_malloc(sizeof(mmi_phb_unsaved_data_struct), SRV_PHB_MEMORY_TYPE_ADM);
    memset(data_node->object, 0x00, sizeof(mmi_phb_unsaved_data_struct));

    data_node->object->storage = storage;
    data_node->object->field_type = show_type;
    
    data_node->object->phb_data = mmi_phb_mem_malloc(sizeof(srv_phb_contact_data_struct), SRV_PHB_MEMORY_TYPE_ADM);
    memset(data_node->object->phb_data, 0x00, sizeof(srv_phb_contact_data_struct));

    if (phb_data->name != NULL && mmi_wcslen(phb_data->name))
    {
        data_node->object->phb_data->name = mmi_phb_mem_malloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->name, phb_data->name, MMI_PHB_NAME_FIELD_LENGTH);
    }

    if (phb_data->number != NULL &&  mmi_wcslen(phb_data->number))
    {            
        mmi_phb_truncate_number_field_to_max_len((U16 *)number_UCS2, (U16 *)phb_data->number, MMI_PHB_NUMBER_LENGTH);

        data_node->object->phb_data->number = mmi_phb_mem_malloc((MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->number, (U16*) number_UCS2, MMI_PHB_NUMBER_LENGTH + 1);
    }

#if defined(__MMI_PHB_INFO_FIELD__)
    if (phb_data->pobox != NULL &&  mmi_wcslen(phb_data->pobox))
    {
        data_node->object->phb_data->pobox = mmi_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->pobox, phb_data->pobox, MMI_PHB_ADDRESS_LENGTH);
    }

    if (phb_data->extension != NULL && mmi_wcslen(phb_data->extension))
    {
        data_node->object->phb_data->extension = mmi_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->extension, phb_data->extension, MMI_PHB_ADDRESS_LENGTH);
    }

    if (phb_data->street != NULL && mmi_wcslen(phb_data->street))
    {
        data_node->object->phb_data->street = mmi_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->street, phb_data->street, MMI_PHB_ADDRESS_LENGTH);
    }

    if (phb_data->city != NULL && mmi_wcslen(phb_data->city))
    {
        data_node->object->phb_data->city = mmi_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->city, phb_data->city, MMI_PHB_ADDRESS_LENGTH);
    }

    if (phb_data->state != NULL && mmi_wcslen(phb_data->state))
    {
        data_node->object->phb_data->state = mmi_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->state, phb_data->state, MMI_PHB_ADDRESS_LENGTH);
    }

    if (phb_data->postalcode != NULL && mmi_wcslen(phb_data->postalcode))
    {
        data_node->object->phb_data->postalcode = mmi_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->postalcode, phb_data->postalcode, MMI_PHB_ADDRESS_LENGTH);
    }

    if (phb_data->country != NULL && mmi_wcslen(phb_data->country))
    {
        data_node->object->phb_data->country = mmi_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * ENCODING_LENGTH, SRV_PHB_MEMORY_TYPE_ADM);
        mmi_wcsncpy(data_node->object->phb_data->country, phb_data->country, MMI_PHB_ADDRESS_LENGTH);
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    data_node->object->phb_data->default_number = phb_data->default_number;
#endif

    return data_node;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_add_node
 * DESCRIPTION
 *  add one node to the unsaved data link list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_unsaved_data_add_node(struct mmi_phb_unsaved_data_node_struct* new_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_unsaved_data.unsaved_data_head == NULL)
    {
        g_mmi_phb_unsaved_data.unsaved_data_head = new_node;
        g_mmi_phb_unsaved_data.unsaved_data_end = new_node;
    }
    else
    {
        g_mmi_phb_unsaved_data.unsaved_data_end->next = new_node;
        g_mmi_phb_unsaved_data.unsaved_data_end = new_node;
    }

    g_mmi_phb_unsaved_data.unsaved_data_end->next = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_search_node
 * DESCRIPTION
 *  search the ith node in the unsaved data link list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
struct mmi_phb_unsaved_data_node_struct* mmi_phb_unsaved_data_search_node(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct mmi_phb_unsaved_data_node_struct *search_node;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < g_mmi_phb_unsaved_data.unsaved_data_num);
    
    search_node = g_mmi_phb_unsaved_data.unsaved_data_head;
    while(i < index)
    {
        search_node = search_node->next;
        i++;
    }

    MMI_ASSERT(search_node != NULL);
    
    return search_node;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_delete_node
 * DESCRIPTION
 *  delete the whole unsaved data link list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_unsaved_data_delete_node(struct mmi_phb_unsaved_data_node_struct* node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct mmi_phb_unsaved_data_node_struct *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev = g_mmi_phb_unsaved_data.unsaved_data_head;

    if (prev == node)
    {
        g_mmi_phb_unsaved_data.unsaved_data_head = g_mmi_phb_unsaved_data.unsaved_data_head->next;
        
        if (g_mmi_phb_unsaved_data.unsaved_data_end == node)
        {
            g_mmi_phb_unsaved_data.unsaved_data_end = NULL;
        }
        
        mmi_phb_unsaved_data_free_node(node);
    }
    else
    {
        while(prev->next != node)
        {
            prev = prev->next;
        }
        
        prev->next = prev->next->next;
        
        if (g_mmi_phb_unsaved_data.unsaved_data_end == node)
        {
            g_mmi_phb_unsaved_data.unsaved_data_end = prev;
        }
        
        mmi_phb_unsaved_data_free_node(node);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_delete_list
 * DESCRIPTION
 *  delete the whole unsaved data link list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_unsaved_data_delete_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct mmi_phb_unsaved_data_node_struct *ptr, *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_unsaved_data.unsaved_data_head == NULL)
    {
        return;
    }

    ptr = g_mmi_phb_unsaved_data.unsaved_data_head;
    
    while(ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        
        mmi_phb_unsaved_data_free_node(temp);
    }

    memset(&g_mmi_phb_unsaved_data, 0, sizeof(mmi_phb_save_notify_struct));
}
/* function of operation on unsaved data link list end */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_is_save_contact_notify_on
 * DESCRIPTION
 *  Check if the save contact notify on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_is_save_contact_notify_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_IS_SAVE_CONTACT_NOTIFY_ON, mmi_phb_get_save_contact_notify());

    if (!mmi_phb_check_ready(MMI_FALSE))
    {
        return MMI_FALSE;
    }
    if (srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
    {
        return MMI_FALSE;
    }
    return (mmi_phb_get_save_contact_notify() == MMI_PHB_SAVE_CONTACT_NOTIFY_ON ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_if_data_duplicated
 * DESCRIPTION
 *  Check if the unsaved data is duplicated in the unsaved list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_check_if_data_duplicated(U8* data, U32 data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    MMI_BOOL result = MMI_FALSE;
    mmi_phb_unsaved_data_node_struct* contact_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < g_mmi_phb_unsaved_data.unsaved_data_num; index++)
    {
        contact_node = mmi_phb_unsaved_data_search_node(index);

        if (data_type == SRV_PHB_ENTRY_FIELD_NUMBER)
        {
            if (srv_phb_compare_number((U16*)data, contact_node->object->phb_data->number))
            {
                return MMI_TRUE;
            }
        }
    }
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_CHECK_IF_DATA_DUPLICATED, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_is_num_in_phb
 * DESCRIPTION
 *  Check if the num is stored in phb or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_is_num_in_phb(U16* ucs2_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U16 number_UCS2[(MMI_PHB_NUMBER_LENGTH + 1 + 1)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_phb_get_save_contact_notify()== MMI_PHB_SAVE_CONTACT_NOTIFY_ON);

    /* check if number could be transfer to valid num (int) */
    memset(number_UCS2, 0, (MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);

    mmi_phb_truncate_number_field_to_max_len(number_UCS2, (U16 *)ucs2_num, MMI_PHB_NUMBER_LENGTH);

    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_PHB_TRACE_GROUP,"[PHB] mmi_phb_is_num_in_phb(),  number:%s", number_UCS2);

    if (!srv_phb_check_valid_number(number_UCS2))
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_IS_NUM_IN_PHB_INVALID_NUM);
        result = MMI_TRUE;
    }
    else if (srv_phb_check_number_exist(number_UCS2))
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_IS_NUM_IN_PHB_IN_PHB);
        result = MMI_TRUE;    
    }
    else if (mmi_phb_check_if_data_duplicated((U8 *) number_UCS2, SRV_PHB_ENTRY_FIELD_NUMBER) == MMI_TRUE)
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_IS_NUM_IN_PHB_IN_UNSAVED_LIST);
        result = MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_IS_NUM_IN_PHB_NOT_IN_PHB);
        result = MMI_FALSE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_data_to_unsaved_list
 * DESCRIPTION
 *  save the data to the unsaved list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_add_data_to_unsaved_list(phb_storage_enum storage, U32 show_type, srv_phb_contact_data_struct *phb_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_unsaved_data_node_struct* contact_node;
    mmi_phb_unsaved_data_node_struct* del_contact_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ADD_DATA_TO_UNSAVED_LIST);
    MMI_ASSERT(mmi_phb_get_save_contact_notify() == MMI_PHB_SAVE_CONTACT_NOTIFY_ON);

    if (storage == PHB_STORAGE_MAX)
    {
    	#ifndef __MMI_PHB_SLIM_NEW__
        storage = mmi_phb_get_preferred_storage();
		#else
		storage = PHB_STORAGE_NVRAM;
		#endif
    }
    
    contact_node = mmi_phb_unsaved_data_init_node((U8) storage, show_type, phb_data);

    if (g_mmi_phb_unsaved_data.unsaved_data_num < MMI_PHB_MAX_UNSAVED_DATA_NUM)
    {
        mmi_phb_unsaved_data_add_node(contact_node);
        g_mmi_phb_unsaved_data.unsaved_data_num++;
    }
    else
    {
        del_contact_node = mmi_phb_unsaved_data_search_node(0);
        mmi_phb_unsaved_data_delete_node(del_contact_node);
        mmi_phb_unsaved_data_add_node(contact_node);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_populate_unsaved_data_to_list
 * DESCRIPTION
 *  populate data in node
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8* mmi_phb_populate_unsaved_data_to_list(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_unsaved_data_node_struct* contact_node;
    CHAR* data_ptr = NULL;
    U32 field_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_node = mmi_phb_unsaved_data_search_node(index);
    field_type = contact_node->object->field_type;
    
    switch(field_type)
    {
        case SRV_PHB_ENTRY_FIELD_NAME:
            data_ptr = (CHAR *)contact_node->object->phb_data->name;
            break;
            
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            data_ptr = (CHAR *)contact_node->object->phb_data->number;
            break;
            
        default:
            break;
    }
    
    return (PU8) data_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_storage_type
 * DESCRIPTION
 *  get storage type for an unsaved data node
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_unsaved_data_storage_type(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_unsaved_data_node_struct* contact_node;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_node = mmi_phb_unsaved_data_search_node(index);
    storage = contact_node->object->storage;
    
    return storage;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_unsaved_data
 * DESCRIPTION
 *  delete ith node and related screen after add new or replace a contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_delete_unsaved_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_unsaved_data_node_struct* contact_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_phb_unsaved_data.unsaved_data_index < g_mmi_phb_unsaved_data.unsaved_data_num);

    contact_node = mmi_phb_unsaved_data_search_node(g_mmi_phb_unsaved_data.unsaved_data_index);
    
    mmi_phb_unsaved_data_delete_node(contact_node);
    g_mmi_phb_unsaved_data.unsaved_data_num--;
}


static mmi_ret mmi_phb_unsaved_data_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_INACTIVE:
            break;
        
        case EVT_ID_GROUP_ACTIVE:
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
            if (g_mmi_phb_unsaved_data.unsaved_data_state == MMI_PHB_UNSAVED_DATA_OP_NORMAL)
            {        
                mmi_phb_unsaved_data_delete_list();
            }
            if (g_mmi_phb_unsaved_data.unsaved_data_num == 0)
            {
                DeleteScreenIfPresent(SCR_ID_PHB_UNSAVED_DATA_CONFIRM);
            }
            break;
            
        case EVT_ID_GROUP_FOCUSED:
            break;

        case EVT_ID_PHB_SAVE_CONTACT:
            mmi_phb_delete_unsaved_data();

            if (g_mmi_phb_unsaved_data.unsaved_data_num == 0)
            {
                mmi_frm_group_close(GRP_ID_PHB_SAVE_NOTIFY);
                DeleteScreenIfPresent(SCR_ID_PHB_UNSAVED_DATA_CONFIRM);
            }
            
            cui_phb_save_contact_close(((cui_phb_save_contact_result_struct*) evt)->sender_id);
            break;
        
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            cui_phb_save_contact_close(((cui_phb_save_contact_result_struct*) evt)->sender_id);
            break;

        default:
            break;
    }
 
    return MMI_RET_OK;

}



static void mmi_phb_pre_entry_unsaved_contact_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_PHB_SAVE_NOTIFY,
        mmi_phb_unsaved_data_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_phb_entry_unsaved_contact_list();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_confirm_delete_cb
 * DESCRIPTION
 *  Delete callback of mmi_phb_entry_unsaved_data_confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_unsaved_data_confirm_delete_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_unsaved_data.unsaved_data_state == MMI_PHB_UNSAVED_DATA_OP_NORMAL)
    {
        mmi_phb_unsaved_data_delete_list();
        g_mmi_phb_unsaved_data.unsaved_data_num = 0;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_unsaved_data_confirm
 * DESCRIPTION
 *  entry function for unsaved_data_confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_unsaved_data_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *outBuf;
    CHAR count[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_UNSAVED_DATA_CONFIRM, g_mmi_phb_unsaved_data.unsaved_data_num);
    
    MMI_ASSERT(g_mmi_phb_unsaved_data.unsaved_data_num > 0);
    
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    EntryNewScreen(SCR_ID_PHB_UNSAVED_DATA_CONFIRM, NULL, mmi_phb_entry_unsaved_data_confirm, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_PHB_UNSAVED_DATA_CONFIRM, (HistoryDelCBPtr)mmi_phb_unsaved_data_confirm_delete_cb);

    g_mmi_phb_unsaved_data.unsaved_data_state = MMI_PHB_UNSAVED_DATA_OP_NORMAL;

    outBuf = mmi_phb_mem_malloc(256, SRV_PHB_MEMORY_TYPE_CTR);
    memset(outBuf, 0x00, 256);

    if (g_mmi_phb_unsaved_data.unsaved_data_num == 1)
    {
        g_mmi_phb_unsaved_data.unsaved_data_index = 0;
        
        mmi_ucs2cpy(outBuf, GetString(STR_ID_SAVE_CONTACT_SAVE));
        mmi_ucs2cat(outBuf, (CHAR*) mmi_phb_populate_unsaved_data_to_list(g_mmi_phb_unsaved_data.unsaved_data_index));
        mmi_ucs2cat(outBuf, GetString(STR_ID_SAVE_CONTACT_TO_PHB));
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        
        ShowCategory66Screen(
            STR_SCR_PBOOK_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (PU8) outBuf,
            IMG_GLOBAL_QUESTION,
            NULL);
        
        SetLeftSoftkeyFunction(mmi_phb_entry_save_contact_option, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_entry_save_contact_option, KEY_EVENT_UP);
    }
    else
    {
        sprintf(outBuf, "%d ", g_mmi_phb_unsaved_data.unsaved_data_num);
        mmi_asc_to_ucs2(count, outBuf);
        mmi_ucs2cpy(outBuf, GetString(STR_ID_SAVE_CONTACT_SAVE));
        mmi_ucs2cat(outBuf, count);
        mmi_ucs2cat(outBuf, GetString(STR_ID_SAVE_CONTACT_UNSAVED_DATA));
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory66Screen(
            STR_SCR_PBOOK_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (PU8) outBuf,
            IMG_GLOBAL_QUESTION,
            NULL);
        
        SetLeftSoftkeyFunction(mmi_phb_pre_entry_unsaved_contact_list, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_pre_entry_unsaved_contact_list, KEY_EVENT_UP);
    }
    
    mmi_phb_mem_free(outBuf);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_reentry_unsaved_data_clear_history
 * DESCRIPTION
 *  clear the history data for save contact notify related screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_reentry_unsaved_data_clear_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_PHB_UNSAVED_DATA_CONFIRM);
    mmi_frm_group_close(GRP_ID_PHB_SAVE_NOTIFY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_unsaved_data_confirm
 * DESCRIPTION
 *  pre_entry function for unsaved_data_confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_pre_entry_unsaved_data_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_PRE_ENTRY_UNSAVED_DATA_CONFIRM);

    MMI_ASSERT(mmi_phb_get_save_contact_notify() == MMI_PHB_SAVE_CONTACT_NOTIFY_ON);

    if (IsScreenPresent(SCR_ID_PHB_UNSAVED_DATA_CONFIRM) == MMI_TRUE)
    {
        g_mmi_phb_unsaved_data.unsaved_data_state = MMI_PHB_UNSAVED_DATA_OP_REENTRY;
    }
    
    mmi_phb_reentry_unsaved_data_clear_history();

    mmi_phb_entry_unsaved_data_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_unsaved_data_confirm_to_history
 * DESCRIPTION
 *  add unsaved
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_add_unsaved_data_confirm_to_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_screen_struct inserted_scrn;
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ADD_UNSAVED_DATA_CONFIRM_TO_HISTORY);
    
    MMI_ASSERT(mmi_phb_get_save_contact_notify() == MMI_PHB_SAVE_CONTACT_NOTIFY_ON);
    
    if (IsScreenPresent(SCR_ID_PHB_UNSAVED_DATA_CONFIRM) == MMI_TRUE)
    {
        g_mmi_phb_unsaved_data.unsaved_data_state = MMI_PHB_UNSAVED_DATA_OP_REENTRY;
    }
    else if (GetActiveScreenId() == SCR_ID_PHB_UNSAVED_DATA_CONFIRM)
    {
        g_mmi_phb_unsaved_data.unsaved_data_state = MMI_PHB_UNSAVED_DATA_OP_REENTRY;
        EntryNewScreen(SCR_PHB_DUMMY, NULL, NULL, 0);
        DeleteScreenIfPresent(SCR_ID_PHB_UNSAVED_DATA_CONFIRM);
        mmi_phb_entry_unsaved_data_confirm();

        return;
    }
    
    mmi_phb_reentry_unsaved_data_clear_history();

    mmi_frm_init_screen_struct(&inserted_scrn);
    inserted_scrn.scrnID = SCR_ID_PHB_UNSAVED_DATA_CONFIRM;
    inserted_scrn.isSmallScreen = 0;
    inserted_scrn.entryFuncPtr = (entry_func_ptr)mmi_phb_entry_unsaved_data_confirm;

    if (srv_ucm_is_incoming_call())
    {
        scr_id = mmi_ucm_get_marker_scrn_id();
    }
    else
    {
        scr_id = MMI_HIST_TOP_SCREEN;
    }

    mmi_frm_insert_screen(scr_id, &inserted_scrn, MMI_FRM_INSERT_AFTER_SCRN);
    SetDelScrnIDCallbackHandler(SCR_ID_PHB_UNSAVED_DATA_CONFIRM, (HistoryDelCBPtr)mmi_phb_unsaved_data_confirm_delete_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_unsaved_data_num
 * DESCRIPTION
 *  get unsaved data num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_get_unsaved_data_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_phb_unsaved_data.unsaved_data_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_option
 * DESCRIPTION
 *  entry screen of save contact option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_save_contact_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_unsaved_data_node_struct* contact_node;
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_ready(MMI_TRUE))
    {
        contact_node = mmi_phb_unsaved_data_search_node(g_mmi_phb_unsaved_data.unsaved_data_index);

        if (!mmi_frm_group_is_present(GRP_ID_PHB_SAVE_NOTIFY))
        {
            mmi_frm_group_create_ex(
                GRP_ID_ROOT,
                GRP_ID_PHB_SAVE_NOTIFY,
                mmi_phb_unsaved_data_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }
        
        sg_id = cui_phb_save_contact_create(GRP_ID_PHB_SAVE_NOTIFY);
        
        cui_phb_save_contact_set_data(sg_id, contact_node->object->phb_data);
        cui_phb_save_contact_set_storage(sg_id, mmi_phb_unsaved_data_storage_type(g_mmi_phb_unsaved_data.unsaved_data_index));

        cui_phb_save_contact_run(sg_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_get_item
 * DESCRIPTION
 *  get item function for unsaved data list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_phb_unsaved_data_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U8 *data_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
        data_buff = mmi_phb_populate_unsaved_data_to_list((U8)(item_index + index));
        mmi_ucs2cpy((CHAR*) menu_data[index].item_list[0], (CHAR*) data_buff);
        menu_data[index].image_list[0] = get_image(gIndexIconsImageList[index + item_index]);
    }
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_list_hilite_handler
 * DESCRIPTION
 *  highlight handler for unsaved data list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_unsaved_data_list_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_unsaved_data.unsaved_data_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_go_back_history_for_unsaved_contact_list
 * DESCRIPTION
 *  go back histroy function for unsaved contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_go_back_history_for_unsaved_contact_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_PHB_UNSAVED_DATA_CONFIRM);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_unsaved_contact_list
 * DESCRIPTION
 *  entry function for unsaved contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_unsaved_contact_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_ENTRY_UNSAVED_CONTACT_LIST);

    if (!mmi_frm_scrn_enter(
            GRP_ID_PHB_SAVE_NOTIFY,
            SCR_ID_PHB_UNSAVED_DATA_LIST,
            NULL,
            mmi_phb_entry_unsaved_contact_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_phb_unsaved_data_list_hilite_handler);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_cat1032_show(
        (WCHAR*) GetString(STR_ID_SAVE_CONTACT_NEW_CONTACT_LIST),
        (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
        (WCHAR*) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (WCHAR*) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        g_mmi_phb_unsaved_data.unsaved_data_num,
        mmi_phb_unsaved_data_get_item,
        NULL,
        0,
        0,
        IMG_GLOBAL_L1,
        0,
        guiBuffer,
        NULL);

    SetLeftSoftkeyFunction(mmi_phb_entry_save_contact_option, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_phb_entry_save_contact_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_history_for_unsaved_contact_list, KEY_EVENT_UP);

    return;
}
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */


#ifdef __DM_LAWMO_SUPPORT__

static srv_dm_lawmo_lock_report_cb_func_type dm_lawmo_cb = NULL;

static MMI_BOOL mmi_phb_dm_delete_all_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 delay_delete = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_cntx_mgr_controller(MMI_PHB_STATE_DM, MMI_TRUE, &delay_delete))
    {
        /* Notice: need to handle SAT state */
        (*dm_lawmo_cb)(MMI_FALSE, "Phonebook");
        dm_lawmo_cb = NULL;
        return MMI_FALSE;
    }

    if (delay_delete)
    {
        return MMI_FALSE;
    }
    
#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_syncml_abort_sync_req_ext();
    }
#endif /* __SYNCML_SUPPORT__ */ 

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dm_delete_all_call_back
 * DESCRIPTION
 *  call back function for delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_dm_delete_all_call_back(U16 finish_count, U16 total_count, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_struct *op_cntx = (mmi_phb_op_cntx_struct *) user_data;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_cntx_mgr_controller(op_cntx->state, MMI_FALSE, NULL))
    {
        g_phb_cntx_mgr.processing = MMI_FALSE;
        
        /**
         * dm callback function
         */
        if (finish_count == total_count)
        {
            result = MMI_TRUE;
        }

    }
    
    (*dm_lawmo_cb)(result, "Phonebook");
    dm_lawmo_cb = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dm_delete_all_pre_req
 * DESCRIPTION
 *  delete all interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_dm_delete_all_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx_mgr.processing = MMI_TRUE;
    g_phb_cntx_mgr.state = MMI_PHB_STATE_DM;
    
    g_mmi_phb_op_cntx.canceled = MMI_FALSE;
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_DELETE_ALL;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_DM;
    g_mmi_phb_op_cntx.sg_id = mmi_phb_cntx_mgr_get_current_sg_id();
    g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_NVRAM;

    srv_phb_oplib_delete_all_contact(
        g_mmi_phb_op_cntx.src_storage,
        mmi_phb_dm_delete_all_call_back,
        &g_mmi_phb_op_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dm_delete_all_hdlr
 * DESCRIPTION
 *  dm delete all callback
 * PARAMETERS
 *  evt                              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_dm_lawmo_wipe_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_wipe_ind_evt_struct *event = (srv_dm_lawmo_wipe_ind_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->cmd)
    {
        case SRV_DM_LAWMO_WIPE_CMD_APP_WIPE:
            dm_lawmo_cb = event->cb;
            if (mmi_phb_dm_delete_all_prepare())
            {
                mmi_phb_dm_delete_all_pre_req();
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}
#endif


#define MMI_PHB_COPY_SIM_DATA

#ifdef __MMI_PHB_STARTUP_COPY_SIM__

/*
 * Local Variable
 */
static U8 g_mmi_phb_first_startup[MMI_SIM_TOTAL] ={MMI_FALSE};
static U8 g_mmi_phb_sim_replace[MMI_SIM_TOTAL] = {MMI_FALSE};
static U8 g_mmi_phb_check_result[MMI_SIM_TOTAL] = {MMI_FALSE};

/* 
 * Local Function
 */
static void mmi_phb_get_timer_id_and_func(U32 sim_index, U16 *timer_id, FuncPtr *funcPtr);
static U16 mmi_phb_get_data_item_id(U32 sim_index);
static U8 mmi_phb_first_startup_check(U32 sim_index);
static U8 mmi_phb_sim_replace_check(U8 sim_index);
static void mmi_phb_startup_copy_sim_timeout_ext(U32 sim_index);
static U8 mmi_phb_startup_copy_sim_check_ext(U32 sim_index);
static void mmi_phb_startup_exit_copy_sim_confirm(U32 sim_index);
static void mmi_phb_startup_entry_copy_sim_confirm(void);
static void mmi_phb_startup_copy_all_sim_to_phone_pre_req(U32 sim_index);
static void mmi_phb_startup_copy_sim1_timeout(void);
static void mmi_phb_startup_exit_copy_sim1_confirm(void);
static void mmi_phb_startup_copy_all_sim1_to_phone_pre_req(void);
#if (MMI_MAX_SIM_NUM >= 2)
static void mmi_phb_startup_entry_copy_sim2_confirm(void);
static void mmi_phb_startup_copy_sim2_timeout(void);
static void mmi_phb_startup_exit_copy_sim2_confirm(void);
static void mmi_phb_startup_copy_all_sim2_to_phone_pre_req(void);
#endif /* MMI_MAX_SIM_NUM >= 2 */
#if (MMI_MAX_SIM_NUM >= 3)
static void mmi_phb_startup_entry_copy_sim3_confirm(void);
static void mmi_phb_startup_copy_sim3_timeout(void);
static void mmi_phb_startup_exit_copy_sim3_confirm(void);
static void mmi_phb_startup_copy_all_sim3_to_phone_pre_req(void);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
static void mmi_phb_startup_entry_copy_sim4_confirm(void);
static void mmi_phb_startup_copy_sim4_timeout(void);
static void mmi_phb_startup_exit_copy_sim4_confirm(void);
static void mmi_phb_startup_copy_all_sim4_to_phone_pre_req(void);
#endif

static const FuncPtr g_mmi_phb_statup_copy_confirm[] = 
{
    mmi_phb_startup_entry_copy_sim_confirm,
 #if (MMI_MAX_SIM_NUM >= 2)
    mmi_phb_startup_entry_copy_sim2_confirm,
 #endif
 #if (MMI_MAX_SIM_NUM >= 3)
    mmi_phb_startup_entry_copy_sim3_confirm,
 #endif
 #if (MMI_MAX_SIM_NUM >= 4)
    mmi_phb_startup_entry_copy_sim4_confirm
 #endif
};


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_timer_id_and_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_get_timer_id_and_func(U32 sim_index, U16 *timer_id, FuncPtr *funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sim_index)
    {
    #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4:
            *timer_id = PHB_1ST_STARTUP_ASK_TIMER_SIM4;
            *funcPtr = mmi_phb_startup_copy_sim4_timeout;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case SIM3:
            *timer_id = PHB_1ST_STARTUP_ASK_TIMER_SIM3;
            *funcPtr = mmi_phb_startup_copy_sim3_timeout;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case SIM2:
            *timer_id = PHB_1ST_STARTUP_ASK_TIMER_SIM2;
            *funcPtr = mmi_phb_startup_copy_sim2_timeout;
            break;
    #endif

        case SIM1:
        default:
            *timer_id = PHB_1ST_STARTUP_ASK_TIMER;
            *funcPtr = mmi_phb_startup_copy_sim1_timeout;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_data_item_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_phb_get_data_item_id(U32 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data_item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sim_index)
    {
    #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4:
            data_item_id = NVRAM_PHB_STARTUP_COPY_SIM4;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case SIM3:
            data_item_id = NVRAM_PHB_STARTUP_COPY_SIM3;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case SIM2:
            data_item_id = NVRAM_PHB_STARTUP_COPY_SIM2;
            break;
    #endif

        case SIM1:
        default:
            data_item_id = NVRAM_PHB_STARTUP_COPY_SIM;
            break;
    }

    return data_item_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_first_startup_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_index      [IN]        SIM1 or SIM2
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_phb_first_startup_check(U32 sim_index)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/
    U8 startup_flag;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 100);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, sim_index);

#if (MMI_MAX_SIM_NUM == 1)
    MMI_ASSERT(sim_index == SIM1);
#else
    if (sim_index != SIM1 && sim_index != SIM2
    #if (MMI_MAX_SIM_NUM >= 3)
        && sim_index != SIM3
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        && sim_index != SIM4
    #endif
        )
    {
        MMI_ASSERT(0);
    }
#endif

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_first_startup[SIM1]);
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_first_startup[SIM2]);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_first_startup[SIM3]);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_first_startup[SIM4]);
#endif

    if (g_mmi_phb_first_startup[sim_index] == MMI_FALSE)
    {
        U16 data_item_id = mmi_phb_get_data_item_id(sim_index);

        ReadValue(data_item_id, &startup_flag, DS_BYTE, &error);

        if (startup_flag == 1)
        {
            /* It is not first startup, shall not ask. */
            g_mmi_phb_first_startup[sim_index] = MMI_TRUE;

            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 101);

            return MMI_FALSE;
        }
        else
        {
            /* It is first startup, ask if user wants to copy all from SIM. */
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 102);

            return MMI_TRUE;
        }
    }

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 103);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_replace_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_index      [IN]        SIM1 or SIM2
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_phb_sim_replace_check(U8 sim_index)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 110);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, sim_index);


#if (MMI_MAX_SIM_NUM == 1)
    MMI_ASSERT(sim_index == SIM1);
#else
    if (sim_index != SIM1 && sim_index != SIM2
    #if (MMI_MAX_SIM_NUM >= 3)
        && sim_index != SIM3
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        && sim_index != SIM4
    #endif
        )
    {
        MMI_ASSERT(0);
    }
#endif

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_sim_replace[SIM1]);
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_sim_replace[SIM2]);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_sim_replace[SIM3]);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_sim_replace[SIM4]);
#endif

    if (g_mmi_phb_sim_replace[sim_index] == MMI_FALSE)
    {
    #if (MMI_MAX_SIM_NUM > 1)
        if (SRV_SIM_CTRL_CHANGE_CHECK_CHANGED == srv_sim_ctrl_get_change_check((mmi_sim_enum)(1<<sim_index)))
    #else /* MMI_MAX_SIM_NUM */
        if (SRV_SIM_CTRL_CHANGE_CHECK_CHANGED == srv_sim_ctrl_get_change_check(MMI_SIM1))
    #endif /* MMI_MAX_SIM_NUM */
        {
            /* It is SIM replace, ask if user wants to copy all from SIM. */
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 111);

            return MMI_TRUE;
        }
        else
        {
            /* It is not SIM replace, shall not ask. */
            g_mmi_phb_sim_replace[sim_index] = MMI_TRUE;

            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 112);

            return MMI_FALSE;
        }
    }

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 113);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim_timeout_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_sim_timeout_ext(U32 sim_index)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/
    U8 startup_flag;
    S16 error;
    U16 timer_id;
    FuncPtr funcPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_get_timer_id_and_func(sim_index, &timer_id, &funcPtr);

    StopTimer(timer_id);

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 120);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, sim_index);

    if (!mmi_idle_is_active())
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 121);
    }
    else if (!mmi_phb_check_ready(MMI_FALSE))   /* PHB is not ready */
    {
        StartTimer(timer_id, 1000, funcPtr);

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 122);
    }
    else
    {
        /* Don't ask if no SIM contacts */
        if (srv_phb_get_used_contact(PHB_STORAGE_SIM+sim_index) == 0
            || srv_phb_startup_get_adn_used_first(SIM1>>sim_index) == 0
            )
        {
            U16 data_item_id;
            
            startup_flag = 1;
            data_item_id = mmi_phb_get_data_item_id(sim_index);

            WriteValue(data_item_id, &startup_flag, DS_BYTE, &error);

            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 123);

            return;
        }

        mmi_idle_notify_event();

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 124);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim_check_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_phb_startup_copy_sim_check_ext(U32 sim_index)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/
    U8 startup_flag;
    S16 error;
    U16 timer_id;
    FuncPtr funcPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * It must meet with the following conditions:
     * 1, SIM is inserted & not blocked
     * 2, ADN is accessible
     * 3, PHB is ready
     * 4, PHB preferred storage is Phone or Both
     * 5, First startup or SIM replaced
     */
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 130);

    mmi_phb_get_timer_id_and_func(sim_index, &timer_id, &funcPtr);

    g_mmi_phb_check_result[sim_index] = MMI_FALSE;

    if (!mmi_phb_check_ready(MMI_FALSE))    /* PHB is not ready */
    {
        StartTimer(timer_id, 1000, funcPtr);

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 131);
    }
    else
    {
        StopTimer(timer_id);

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 132);

        if (
          #ifdef __MMI_TELEPHONY_SUPPORT__
            !srv_sim_ctrl_is_available(MMI_SIM1<<sim_index) ||                           /* SIM is blocked or not inserted */
            !srv_phb_check_storage_accessible(PHB_STORAGE_SIM+sim_index) ||   /* ADN is not accessible */
          #endif
            (mmi_phb_get_preferred_storage() != PHB_STORAGE_NVRAM &&
             mmi_phb_get_preferred_storage() != PHB_STORAGE_MAX))   /* PHB preferred storage is not Phone or Both */
        {
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 133);
        }
        else
        {
            /* First startup or SIM replaced */
            g_mmi_phb_check_result[sim_index] = mmi_phb_first_startup_check(sim_index) | mmi_phb_sim_replace_check(sim_index);

            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, g_mmi_phb_check_result[sim_index]);

            if (g_mmi_phb_check_result[sim_index])
            {
                MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 134);

                if (!mmi_phb_check_ready(MMI_FALSE))    /* PHB is not ready */
                {
                    StartTimer(timer_id, 1000, funcPtr);

                    g_mmi_phb_check_result[sim_index] = MMI_FALSE;

                    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 135);
                }
                else
                {
                    StopTimer(timer_id);

                    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 136);

                    /* Don't ask if no SIM contacts */
                    if (srv_phb_get_used_contact(PHB_STORAGE_SIM+sim_index) == 0
                        || srv_phb_startup_get_adn_used_first(sim_index) == 0)
                    {
                        U16 data_item_id;

                        startup_flag = 1;
                        data_item_id = mmi_phb_get_data_item_id(sim_index);

                        WriteValue(data_item_id, &startup_flag, DS_BYTE, &error);

                        g_mmi_phb_check_result[sim_index] = MMI_FALSE;

                        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 137);
                    }
                }
            }
        }
    }

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 138);

    return g_mmi_phb_check_result[sim_index];
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim_pre_entry_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_startup_copy_sim_pre_entry_ext(U32 sim_index)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/
    FuncPtr hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 145);

    if (g_mmi_phb_check_result[sim_index] == MMI_TRUE)
    {
        /* Ask if user wants to copy all from SIM */
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_PHB_STARTUP_COPY_SIM + sim_index);
        hdlr = g_mmi_phb_statup_copy_confirm[sim_index];
        (*hdlr)();

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 146);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_exit_copy_sim_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_exit_copy_sim_confirm(U32 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 410);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, sim_index);

    if (mmi_frm_is_in_backward_scenario()
        && (mmi_frm_scrn_get_active_id() == (SCR_ID_PHB_STARTUP_COPY_SIM + sim_index))
        )
    {
        S16 error;
        U16 data_item_id;
        U8 startup_flag;

        startup_flag = 1;
        data_item_id = mmi_phb_get_data_item_id(sim_index);

        WriteValue(data_item_id, &startup_flag, DS_BYTE, &error);
        g_mmi_phb_first_startup[sim_index] = MMI_TRUE;
        g_mmi_phb_sim_replace[sim_index] = MMI_TRUE;

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 411);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_entry_copy_sim_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_entry_copy_sim_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    FuncPtr func;
    FuncPtr exit_func;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_used_contact(PHB_STORAGE_SIM) == 0)
    {
        U16 data_item_id;
        U8 startup_flag;

        startup_flag = 1;
        data_item_id = mmi_phb_get_data_item_id(SIM1);

        WriteValue(data_item_id, &startup_flag, DS_BYTE, &error);
        mmi_idle_display();

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 161);
    }
    else
    {
        exit_func = mmi_phb_startup_exit_copy_sim1_confirm;
        func = mmi_phb_startup_copy_all_sim1_to_phone_pre_req;

        if(!mmi_frm_scrn_enter(
            mmi_idle_get_group_id(),
            SCR_ID_PHB_STARTUP_COPY_SIM,
            exit_func,
            mmi_phb_startup_entry_copy_sim_confirm,
            MMI_FRM_UNKNOW_SCRN))
        {
            return;
        }   

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    #if (MMI_MAX_SIM_NUM == 1)
        str_id = STR_ID_PHB_STARTUP_COPY_SIM_CONFIRM;
    #else
        str_id = STR_ID_PHB_STARTUP_COPY_SIM1_CONFIRM;
    #endif
        
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(str_id),
            IMG_GLOBAL_QUESTION,
            NULL);

        SetLeftSoftkeyFunction(func, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(func, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_all_sim_to_phone_pre_req
 * DESCRIPTION
 *  copy all sim contacts to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_all_sim_to_phone_pre_req(U32 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 startup_flag = 1;
    S16 error;
    U16 data_item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_ready(MMI_TRUE))
    {
        mmi_frm_group_create_ex(
            mmi_idle_get_group_id(),
            GRP_ID_PHB_COPY_SIM_DATA,
            mmi_dummy_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

        data_item_id = mmi_phb_get_data_item_id(sim_index);

        WriteValue(data_item_id, &startup_flag, DS_BYTE, &error);

        g_mmi_phb_first_startup[sim_index] = MMI_TRUE;
        g_mmi_phb_sim_replace[sim_index] = MMI_TRUE;

        g_mmi_phb_op_cntx.src_storage = PHB_STORAGE_SIM+sim_index;
        g_mmi_phb_op_cntx.dst_storage = PHB_STORAGE_NVRAM;
        mmi_phb_show_mass_processing(
            mmi_frm_group_get_active_id(),
            STR_GLOBAL_COPYING,
            srv_phb_get_used_contact(g_mmi_phb_op_cntx.src_storage));

        mmi_phb_copy_all_pre_req(GRP_ID_PHB_COPY_SIM_DATA);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim1_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_sim1_timeout(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_startup_copy_sim_timeout_ext(SIM1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim1_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_phb_startup_copy_sim_check(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_startup_copy_sim_check_ext(SIM1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_startup_copy_sim_pre_entry(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 141);

    mmi_phb_startup_copy_sim_pre_entry_ext(SIM1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_exit_copy_sim1_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_exit_copy_sim1_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 401);

    mmi_phb_startup_exit_copy_sim_confirm(SIM1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_all_sim1_to_phone_pre_req
 * DESCRIPTION
 *  copy all sim contacts to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_all_sim1_to_phone_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_PHB_STARTUP_COPY_SIM);
    mmi_phb_startup_copy_all_sim_to_phone_pre_req(SIM1);
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim2_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_sim2_timeout(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_startup_copy_sim_timeout_ext(SIM2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim2_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_phb_startup_copy_sim2_check(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  mmi_phb_startup_copy_sim_check_ext(SIM2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim2_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_startup_copy_sim2_pre_entry(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 142);

    mmi_phb_startup_copy_sim_pre_entry_ext(SIM2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_entry_copy_sim2_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_entry_copy_sim2_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    FuncPtr func;
    FuncPtr exit_func;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_used_contact(PHB_STORAGE_SIM + SIM2) == 0)
    {
        U16 data_item_id;
        U8 startup_flag;

        startup_flag = 1;
        data_item_id = mmi_phb_get_data_item_id(SIM2);

        WriteValue(data_item_id, &startup_flag, DS_BYTE, &error);
        mmi_idle_display();

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 161);
    }
    else
    {
        exit_func = mmi_phb_startup_exit_copy_sim2_confirm;
        func = mmi_phb_startup_copy_all_sim2_to_phone_pre_req;

        if(!mmi_frm_scrn_enter(
            mmi_idle_get_group_id(),
            SCR_ID_PHB_STARTUP_COPY_SIM2,
            exit_func,
            mmi_phb_startup_entry_copy_sim2_confirm,
            MMI_FRM_UNKNOW_SCRN))
        {
            return;
        }   

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    #if (MMI_MAX_SIM_NUM == 1)
        str_id = STR_ID_PHB_STARTUP_COPY_SIM_CONFIRM;
    #else
        str_id = STR_ID_PHB_STARTUP_COPY_SIM1_CONFIRM + SIM2;
    #endif
        
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(str_id),
            IMG_GLOBAL_QUESTION,
            NULL);

        SetLeftSoftkeyFunction(func, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(func, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_exit_copy_sim2_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_exit_copy_sim2_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 402);

    mmi_phb_startup_exit_copy_sim_confirm(SIM2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_all_sim2_to_phone_pre_req
 * DESCRIPTION
 *  copy all sim2 contacts to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_all_sim2_to_phone_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_PHB_STARTUP_COPY_SIM + SIM2);
    mmi_phb_startup_copy_all_sim_to_phone_pre_req(SIM2);
}
#endif /* MMI_MAX_SIM_NUM >=2 */


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim3_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_sim3_timeout(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_startup_copy_sim_timeout_ext(SIM3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim3_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_phb_startup_copy_sim3_check(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  mmi_phb_startup_copy_sim_check_ext(SIM3);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim3_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_startup_copy_sim3_pre_entry(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 143);

    mmi_phb_startup_copy_sim_pre_entry_ext(SIM3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_entry_copy_sim3_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_entry_copy_sim3_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    FuncPtr func;
    FuncPtr exit_func;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_used_contact(PHB_STORAGE_SIM + SIM3) == 0)
    {
        U16 data_item_id;
        U8 startup_flag;

        startup_flag = 1;
        data_item_id = mmi_phb_get_data_item_id(SIM3);

        WriteValue(data_item_id, &startup_flag, DS_BYTE, &error);
        mmi_idle_display();

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 161);
    }
    else
    {
        exit_func = mmi_phb_startup_exit_copy_sim3_confirm;
        func = mmi_phb_startup_copy_all_sim3_to_phone_pre_req;

        if(!mmi_frm_scrn_enter(
            mmi_idle_get_group_id(),
            SCR_ID_PHB_STARTUP_COPY_SIM3,
            exit_func,
            mmi_phb_startup_entry_copy_sim3_confirm,
            MMI_FRM_UNKNOW_SCRN))
        {
            return;
        }   

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    #if (MMI_MAX_SIM_NUM == 1)
        str_id = STR_ID_PHB_STARTUP_COPY_SIM_CONFIRM;
    #else
        str_id = STR_ID_PHB_STARTUP_COPY_SIM1_CONFIRM + SIM3;
    #endif
        
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(str_id),
            IMG_GLOBAL_QUESTION,
            NULL);

        SetLeftSoftkeyFunction(func, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(func, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_exit_copy_sim3_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_exit_copy_sim3_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 403);

    mmi_phb_startup_exit_copy_sim_confirm(SIM3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_all_sim3_to_phone_pre_req
 * DESCRIPTION
 *  copy all sim2 contacts to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_all_sim3_to_phone_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_PHB_STARTUP_COPY_SIM + SIM3);
    mmi_phb_startup_copy_all_sim_to_phone_pre_req(SIM3);
}
#endif /* MMI_MAX_SIM_NUM >= 3 */


#if (MMI_MAX_SIM_NUM >= 4)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim4_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_sim4_timeout(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_startup_copy_sim_timeout_ext(SIM4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim4_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_phb_startup_copy_sim4_check(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  mmi_phb_startup_copy_sim_check_ext(SIM4);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim4_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_startup_copy_sim4_pre_entry(void)
{
    /*-----------------------------------------------------------------*/
    /* Local Variable                                                  */
    /*-----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 144);

    mmi_phb_startup_copy_sim_pre_entry_ext(SIM4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_entry_copy_sim4_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_entry_copy_sim4_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    FuncPtr func;
    FuncPtr exit_func;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_used_contact(PHB_STORAGE_SIM + SIM4) == 0)
    {
        U16 data_item_id;
        U8 startup_flag;

        startup_flag = 1;
        data_item_id = mmi_phb_get_data_item_id(SIM4);

        WriteValue(data_item_id, &startup_flag, DS_BYTE, &error);
        mmi_idle_display();

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 161);
    }
    else
    {
        exit_func = mmi_phb_startup_exit_copy_sim4_confirm;
        func = mmi_phb_startup_copy_all_sim4_to_phone_pre_req;

        if(!mmi_frm_scrn_enter(
            mmi_idle_get_group_id(),
            SCR_ID_PHB_STARTUP_COPY_SIM4,
            exit_func,
            mmi_phb_startup_entry_copy_sim4_confirm,
            MMI_FRM_UNKNOW_SCRN))
        {
            return;
        }   

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    #if (MMI_MAX_SIM_NUM == 1)
        str_id = STR_ID_PHB_STARTUP_COPY_SIM_CONFIRM;
    #else
        str_id = STR_ID_PHB_STARTUP_COPY_SIM1_CONFIRM + SIM4;
    #endif
        
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(str_id),
            IMG_GLOBAL_QUESTION,
            NULL);

        SetLeftSoftkeyFunction(func, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(func, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_exit_copy_sim4_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_exit_copy_sim4_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SAVE_VCARD_REQ_ERROR_CODE, 154);

    mmi_phb_startup_exit_copy_sim_confirm(SIM4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_all_sim4_to_phone_pre_req
 * DESCRIPTION
 *  copy all sim2 contacts to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_startup_copy_all_sim4_to_phone_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_PHB_STARTUP_COPY_SIM + SIM4);
    mmi_phb_startup_copy_all_sim_to_phone_pre_req(SIM4);
}
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* __MMI_PHB_STARTUP_COPY_SIM__ */


mmi_ret mmi_phb_ready_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_startup_evt_struct *ready_evt = (srv_phb_startup_evt_struct*) para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ready_evt->phb_ready)
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 800);
        mmi_phb_cntx_mgr_init();
        mmi_phb_cntx_mgr_controller(MMI_PHB_STATE_IDLE, MMI_TRUE, NULL);
    }
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
    else
    {
        MMI_ID sg_id;

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 801);

        for (sg_id = GRP_ID_PHB_BEGIN; sg_id < GRP_ID_PHB_END; sg_id++)
        {
            if (MMI_TRUE == mmi_frm_group_is_in_active_serial(sg_id))
            {
                MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 802);
   
                mmi_popup_display_ext(
                    STR_GLOBAL_UPDATE,
                    MMI_EVENT_PROGRESS,
                    NULL);
                break;
            }
        }

        mmi_phb_cntx_mgr_clear_history();

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 803);
    }
#endif
    #ifndef __MMI_PHB_SLIM_NO_SAT__
    if (ready_evt->sim_refresh)
    {
        mmi_phb_cntx_mgr_sim_refresh(ready_evt->storage);
    }
	#endif
    
    return MMI_RET_OK;
}


mmi_ret mmi_phb_processing_hdlr(mmi_event_struct* para)
{
    switch (para->evt_id)
    {
        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
        case EVT_ID_GPIO_AFTER_LCD_SLEEP_IN:
            if (mmi_phb_check_processing())
            {
                return 1;
            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_tcard_ready_hdlr
 * DESCRIPTION
 *  refresh list when tcard plug in and ready
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_tcard_ready_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_tcard_ready_evt_struct *ready_evt = (srv_phb_tcard_ready_evt_struct*)para;
    MMI_ID scrn_id;
    phb_storage_enum storage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ready_evt->is_ready)
    {
        scrn_id = mmi_frm_scrn_get_active_id();
        if (scrn_id == SCR_ID_PHB_QUICK_SEARCH_LIST
            || scrn_id == SCR_PBOOK_MAIN_MENU
            || scrn_id == SCR_ID_PHB_MULTI_OP_PHB_LIST
            || scrn_id == SCR_ID_PHB_GENERIC_MULTI_SELECT
            || scrn_id == SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST
            || scrn_id == SCR_PBOOK_LIST
            || scrn_id == SCR_ID_PHB_CALLERGROUP_MEMBER_LIST
            || scrn_id == SCR_MEMORY_STATUS
            )
        {
            storage = (phb_storage_enum)mmi_phb_get_preferred_storage();
            if (storage == PHB_STORAGE_TCARD || storage == PHB_STORAGE_MAX)
            {
                MMI_ID dummy_gid = 0; 
	            dummy_gid = mmi_frm_group_create_ex(
                    GRP_ID_ROOT,
                    GRP_ID_AUTO_GEN,
                    NULL,
                    NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);
	            mmi_frm_display_dummy_screen();
	            mmi_frm_group_close(dummy_gid);       
                MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 888);      
            }
        }
    }

    return MMI_RET_OK;
}
#endif
