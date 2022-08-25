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
 *  PhoneBookList.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"

#include "CommonScreens.h"

#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookResDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookCore.h"
#include "PhbCuiGprot.h"
#include "PhbSrvGprot.h"
#include "MenuCuiGprot.h"
#include "mmi_frm_scenario_gprot.h"

#include "UCMGprot.h"
#include "UcmSrvGprot.h"

#include "IdleAppDef.h"                     /* for g_idle_context */

#include "SmsSrvGprot.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UMGprot.h"
#include "UcAppGprot.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

#include "SmsGuiInterfaceProt.h"
#include "MessagesMiscell.h"                /* for IsMessagesReEntering */
#include "MessagesResourceData.h"           /* for STR_SMS_MSG_NOT_READY_YET */
#include "SmsSrvGprot.h"
#include "SmsAppGprot.h"

#ifdef __MMI_MMS__
#include "Mmsadp.h"
#include "mms_adp_struct.h"
#endif /* __MMI_MMS__ */

#include "simctrlsrvgprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "ProfilesSrvGprot.h"
#if defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__)
#include "BTMMIScrGprots.h"
#endif
#include "modeSwitchSrvGprot.h"

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_phonebook_def.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "gui_typedef.h"
#include "mmi_frm_events_gprot.h"
#include "PhbSrvIprot.h"
#include "custom_phb_config.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_list.h"
#include "wgui_inputs.h"
#include "AlertScreen.h"
#include "mmi_rp_app_uiframework_def.h"
#include "kal_public_api.h"
#include "customer_email_num.h"
#include "mmi_rp_app_sms_def.h"
#include "UcSrvGprot.h"
#include "custom_wap_config.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "gui.h"
#include "wgui_touch_screen.h"
#include "ImeGprot.h"
#include "string.h"
#include "ps_public_enum.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_cb_mgr_gprot.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "wgui_categories.h"
#include "wgui_categories_fmgr.h"
/* auto add by kw_check end */
#include "mmi_frm_utility_gprot.h"

#include "wgui_asyncdynamic_menus.h"
#include "wgui_dynamic_menus.h"
#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
#include "wgui_categories_search.h"
#include "wgui_categories_util.h"
#endif
#ifdef __MMI_SNS_CONTACTS__
#include "SnsSrvGprot.h"
#include "SnsAppGprot.h"
#include "SnsCuiGprot.h"
#include "mmi_rp_app_sns_def.h"
#include "mmi_rp_srv_sns_def.h"
#include "gui_effect_oem.h"
#include "app_mem_med.h"
#include "wgui_categories_sns.h"
#endif
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
#include "FileMgrGprot.h"
#include "FileMgrType.h"
#endif

#include "mmi_rp_app_scr_locker_def.h"  //KEYPAD_LOCK_TIMER

#if defined(__MMI_BT_PBAP_CLIENT__)
#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)
#if defined(__MMI_WEARABLE_DEVICE__)
#include "PhoneBookpbapcWearable.h"
#else
#include "PhoneBookpbapcEx.h"
#endif
#else
#include "PhoneBookpbapc.h"
#endif
#include "PhoneBookBtDailerGprot.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "phbcuigprot.h"
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

/*----------------------------------------------------------------*/
/* Macro                                                          */
/*----------------------------------------------------------------*/
#define BYTE_SIZE                      8
#define BYTE_SIZE_SHIFT_ARITHMETIC     3

/*----------------------------------------------------------------*/
/* Static Variables                                               */
/*----------------------------------------------------------------*/
#if defined(__MMI_PHB_QUICK_SEARCH__)
static U8 g_phb_quick_search_enter;
#endif

static U16 g_mmi_phb_message;
static U16 g_mmi_phb_max_op_finish_count;
static U16 g_mmi_phb_max_op_total_count;
static U16 g_phb_highlight_alpha;

#if defined(__MMI_PHB_MULTI_OPERATION__)
static U16 g_mmi_phb_temp_buffer[100];
#endif
#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
static CHAR thumbnail_bitmask[(MMI_PHB_ENTRIES + 7) / 8];
#endif

/*----------------------------------------------------------------*/
/* Global Variables                                               */
/*----------------------------------------------------------------*/

/**
 * For phb list
 */
mmi_phb_list_cntx_struct *g_mmi_phb_list_p;
mmi_phb_choose_field_struct g_mmi_phb_choose_field;
mmi_phb_contact_info_struct g_mmi_phb_field_data;

#if !defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
WCHAR g_device_name[SRV_PBAPC_LINK_NUM][SRV_BT_CM_BD_UCS2_NAME_LEN];
#endif

#ifndef __MMI_MAINLCD_96X64__
MMI_BOOL is_from_group_mark_several;
MMI_BOOL is_not_from_mark_several_main;
MMI_BOOL is_from_group_add_member;
#endif


#if defined(__MMI_PHB_MULTI_OPERATION__)
MenucuiPtr g_mmi_phb_mark_several_build_op_func;
FunctionPtr g_mmi_phb_mark_several_entry_func;   
mmi_phb_mark_several_pre_enum g_mmi_phb_mark_several_type;
#endif

extern const U8 phb_edit_field_optional[];
extern mmi_phb_confirm_user_data_struct g_mmi_phb_confirm_user_data;

extern void cui_phb_list_highlight_contact_emit(
        mmi_id parent_id,
        U16 evt_id,
        U16 store_index);
#if defined(__MMI_BT_PBAP_CLIENT__)
extern void cui_phb_pbapc_bt_send_select_result(mmi_phb_pbapc_phb_info_struct *pse_phb, S32 ret);
#endif
#ifdef __MMI_SNS_CONTACTS__
mmi_phb_sns_misc_struct g_mmi_phb_sns_misc;
#endif

/*----------------------------------------------------------------*/
/* static function                                                */
/*----------------------------------------------------------------*/


static S32 mmi_phb_get_1024_1025_async_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items);
static pBOOL mmi_phb_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2);
static S32 mmi_phb_list_get_hint(S32 item_index, UI_string_type *hint_array);
static S32 mmi_phb_list_get_hint_ext(S32 item_index, UI_string_type *hint_array);
static void mmi_phb_exit_not_ready(void);
static void mmi_phb_wait_and_go_back(void);
static void mmi_phb_entry_in_progress(mmi_scrn_essential_struct* scrn_data);
static void mmi_phb_entry_main_processing(mmi_frm_node_struct *new_node_info);
static void mmi_phb_list_alpha_index_input_callback_ext(void);
static void mmi_phb_list_alpha_index(U16 input);
static void mmi_phb_list_alpha_index_input_callback(void);
static void mmi_phb_op_mark_several_delete_coinfirm(MMI_ID group_id);
static void mmi_phb_op_mark_several_delete_pre_req(MMI_ID group_id);
static void mmi_phb_op_mark_several_copy_coinfirm(MMI_ID group_id);
static void mmi_phb_op_mark_several_copy_pre_req(MMI_ID group_id);

static void mmi_phb_op_mark_several_move_coinfirm(MMI_ID group_id);
static void mmi_phb_op_mark_several_move_pre_req(MMI_ID group_id);
static void mmi_phb_entry_mass_processing(mmi_scrn_essential_struct* scrn_data);
static S32 mmi_phb_quick_search_find_entry(U8 *keyword);
static void mmi_phb_entry_quick_search_list_tab(void);



#ifndef __MMI_PHB_QUICK_SEARCH__
static void mmi_phb_list_entry_main(void);
#else
#ifndef __MMI_PHB_UI_IN_TABS__
static void mmi_phb_entry_quick_search_list(void);
#endif
#endif
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
static void mmi_phb_two_line_send_key_handler(void);
#endif
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
static void mmi_phb_list_alpha_index_input_callback_asyc(void);
#endif
#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
static U16 mmi_phb_get_store_id_by_list_index_ext(S32 item_index);
static U16 mmi_phb_get_store_id_by_list_index(S32 item_index);
#endif

#ifdef __MMI_SNS_CONTACTS__
static void mmi_phb_sns_entry_friend_list(void);
static void mmi_phb_sns_entry_favorite_list(void);
static PU8 mmi_phb_sns_get_link_icon(S32 item_index);
static mmi_ret mmi_phb_sns_load_friend_list_callback(mmi_event_struct *param);
static mmi_ret mmi_phb_sns_load_favorite_list_callback(mmi_event_struct *param);
static S32 mmi_phb_sns_friend_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size);
static S32 mmi_phb_sns_favorite_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size);
static void mmi_phb_sns_search_favorite_handler(void);
static void mmi_phb_sns_search_friend_handler(void);
static void mmi_phb_sns_entry_friend_option(void);
static void mmi_phb_sns_entry_favorite_option(void);
static MMI_BOOL mmi_phb_sns_is_ready(void);
mmi_ret mmi_phb_sns_scrn_leave_proc(mmi_event_struct *param);
static mmi_ret mmi_phb_sns_list_not_ready_proc(mmi_event_struct *evt);
static void mmi_phb_sns_center_key_handler(void);
#endif

#ifdef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
static U16 mmi_phb_list_select_widget(void);
#endif


#define MMI_PHB_MAIN_LIST
#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_contact_list_callback
 * DESCRIPTION
 *  fte contact main list toolbar callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_contact_list_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == MMI_PHB_EDIT)
    {
        mmi_phb_op_edit_pre_entry_ext(GRP_ID_PHB_MAIN);
    }
    else
    {
        mmi_phb_op_action_cntx_struct op_cntx;

        mmi_phb_op_cntx_init(&op_cntx);
        op_cntx.store_index = g_mmi_phb_list_p->store_index;

        if (index == MMI_PHB_VOICE_CALL)
        {
        //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        #if defined(__MMI_VIDEO_TELEPHONY__)
            op_cntx.op_action = MMI_PHB_OP_VOICE_CALL;
        #else
            op_cntx.op_action = MMI_PHB_OP_CALL;
        #endif
        }
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
        else if (index == MMI_PHB_VIDEO_CALL)
        {            
            op_cntx.op_action = MMI_PHB_OP_VIDEO_CALL;
        }
    #endif /* defined(__MMI_VIDEO_TELEPHONY__) */
        else if (index == MMI_PHB_SEND_MSG)
        {            
        #ifdef __MMI_UNIFIED_COMPOSER__
            op_cntx.op_action = MMI_PHB_OP_MSG;
        #else /* __MMI_UNIFIED_COMPOSER__ */
            op_cntx.op_action = MMI_PHB_OP_SMS;
        #endif /* __MMI_UNIFIED_COMPOSER__ */
        }

        if (op_cntx.op_action)
        {
            mmi_phb_op_start(&op_cntx, GRP_ID_PHB_MAIN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_contact_list_update
 * DESCRIPTION
 *  fte contact main list toolbar update callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_contact_list_update(S32 index, MMI_BOOL set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set)
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_TRUE);
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_TRUE);
    #endif
        wgui_icon_bar_set_item_enable_state(MMI_PHB_SEND_MSG, MMI_TRUE);
        wgui_icon_bar_set_item_enable_state(MMI_PHB_EDIT, MMI_TRUE);
    }
    else
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
    #endif
        wgui_icon_bar_set_item_enable_state(MMI_PHB_SEND_MSG, MMI_FALSE);
        wgui_icon_bar_set_item_enable_state(MMI_PHB_EDIT, MMI_FALSE);
    }

#if (MMI_MAX_SIM_NUM == 1)
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {
        if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
        {
            wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
        //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        #if defined(__MMI_VIDEO_TELEPHONY__)
            wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
        #endif
        }
    }
    else
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
    #endif
    }
#else /* MMI_MAX_SIM_NUM */
    if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF || !srv_sim_ctrl_any_sim_is_available())
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
    #endif
    }
#endif /* MMI_MAX_SIM_NUM */

#ifdef __MMI_UNIFIED_COMPOSER__
    if (!mms_is_ready())
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_SEND_MSG, MMI_FALSE);
    }
#else /* __MMI_UNIFIED_COMPOSER__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */
    
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
    #endif
    }
    
    wgui_icon_bar_update();
}
#endif /* __MMI_ICON_BAR_SUPPORT__ */


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_contact_list_tap_callback
 * DESCRIPTION
 *  fte contact main list tap callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_contact_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        if (g_mmi_phb_list_p->store_index == 0xffff)
        {
            mmi_phb_op_add_new_entry_ext(GRP_ID_PHB_MAIN);
        }
        else
        {
            cui_phb_view_contact(g_mmi_phb_list_p->sg_id, g_mmi_phb_list_p->store_index);
        }
        return;
    }
    else
    {
        return;
    }
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */



void mmi_phb_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_launch();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_main_menu
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_main_menu()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_launch_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */

    StopTimer(KEYPAD_LOCK_TIMER);
#if 0
#ifdef __MMI_WGUI_MINI_TAB_BAR__
/* under construction !*/
#endif
#endif

    wgui_inputs_multitap_reset();

#if defined(__MMI_BT_PBAP_CLIENT__)

#ifndef __MMI_TELEPHONY_SUPPORT__
    mmi_phb_pbapc_exit_list();
#endif

#endif /* defined(__MMI_BT_PBAP_CLIENT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch_entry
 * DESCRIPTION
 *  Shows the Phonebook main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHB_SLIM_NEW__ 

void mmi_phb_launch_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_UI_IN_TABS__)
    mmi_frm_tab_struct tab_pages_info_array[MMI_PHB_MAIN_SCREEN_TAB_COUNT];
#endif
#if 0
#ifdef __MMI_WGUI_MINI_TAB_BAR__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_BT_PBAP_CLIENT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_PBAP_CLIENT__)
    if (mmi_pbapc_is_bqb_test())
    {
        mmi_phb_pbapc_set_list_type(0);
        mmi_pbapc_bqb_start();

        return;
    }
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

#if defined(__MMI_BT_PBAP_CLIENT__)
  //  mmi_frm_cb_reg_event(EVT_ID_DIALER_DISCONN_EVENT_ID, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);
    mmi_frm_cb_reg_event(EVT_ID_PBAP_NOTIFY, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);
#endif

    if (!srv_phb_startup_is_phb_ready())
    {
        mmi_frm_node_struct *new_node_info = (mmi_frm_node_struct*) mmi_phb_mem_malloc(sizeof(mmi_frm_node_struct), SRV_PHB_MEMORY_TYPE_ADM);
        new_node_info->id = GRP_ID_PHB_MAIN;
        new_node_info->entry_proc = (mmi_proc_func) mmi_phb_launch_entry;
        new_node_info->user_data = NULL;
        mmi_phb_entry_main_processing(new_node_info);

        return;
    }

    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
#if 0
#ifdef __MMI_WGUI_MINI_TAB_BAR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
#endif

/* Tab style */
#if defined(__MMI_PHB_UI_IN_TABS__)

#if defined(__MMI_PHB_QUICK_SEARCH__)
    tab_pages_info_array[0].screen_id = SCR_ID_PHB_QUICK_SEARCH_LIST;
    tab_pages_info_array[0].tab_entry_func = mmi_phb_entry_quick_search_list_tab;
#else
    tab_pages_info_array[0].screen_id = SCR_PBOOK_LIST;
    tab_pages_info_array[0].tab_entry_func = mmi_phb_list_entry_main;
#endif
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(IMG_ID_PHB_TAB_LIST);
    tab_pages_info_array[0].tab_string = NULL;

#ifdef __MMI_PHB_CALLER_GROUP__
    tab_pages_info_array[1].screen_id = SCR_CALLER_GROUPS;
    tab_pages_info_array[1].tab_entry_func = mmi_phb_entry_group_list_tab;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(IMG_ID_PHB_TAB_GROUP);
    tab_pages_info_array[1].tab_string = NULL;
#endif /* __MMI_PHB_CALLER_GROUP__ */

#ifdef __MMI_SNS_CONTACTS__
    tab_pages_info_array[2].screen_id = SCR_ID_PHB_SNS_TAB0;
    tab_pages_info_array[2].tab_entry_func = mmi_phb_sns_entry_friend_list;
    tab_pages_info_array[2].tab_icon = (U8*)GetImage(IMG_ID_PHB_SNS_TAB_FRIEND);
    tab_pages_info_array[2].tab_string = NULL;

    tab_pages_info_array[3].screen_id = SCR_ID_PHB_SNS_TAB1;
    tab_pages_info_array[3].tab_entry_func = mmi_phb_sns_entry_favorite_list;
    tab_pages_info_array[3].tab_icon = (U8*)GetImage(IMG_ID_PHB_SNS_TAB_FAVORITE);
    tab_pages_info_array[3].tab_string = NULL;
#endif

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_create(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        tab_pages_info_array,
        MMI_PHB_MAIN_SCREEN_TAB_COUNT,
        cui_tab_get_select_index(SCR_PBOOK_MAIN_MENU),
        NULL);
#else
    mmi_frm_scrn_tab_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        mmi_phb_launch_exit,
        mmi_phb_launch_entry,
        tab_pages_info_array,
        MMI_PHB_MAIN_SCREEN_TAB_COUNT,
        mmi_frm_scrn_tab_get_active_page_index());
#endif

#ifdef __MMI_SNS_CONTACTS__
    mmi_frm_scrn_set_leave_proc(
        GRP_ID_PHB_MAIN, 
        SCR_PBOOK_MAIN_MENU, 
        mmi_phb_sns_scrn_leave_proc);    
    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_list_not_ready_proc, NULL);
#endif

#elif defined(__MMI_PHB_QUICK_SEARCH__)
    mmi_phb_entry_quick_search_list(); /* quick search list */ 
#else
    mmi_phb_list_entry_main(); /* normal list */ 
#endif
}


#else

static void mmi_phb_pb_entry_show_processing_timer_out_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);
	
	if(mmi_frm_scrn_is_present(GRP_ID_PHB_MAIN,SCR_ID_PHB_PROCESSING,MMI_FRM_NODE_ALL_FLAG))
	{
		mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
	}
    

	 
}





static void mmi_phb_pb_processing_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
   

	kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_TRACE_GROUP, "[mmiPhb_PBAPC]mmi_phb_pbapc_processing_abort"); 

	
	
	//////need to do exit refreshging screen and do the delaunch	
	StopTimer(PHB_NOTIFYDURATION_TIMER);
	mmi_frm_scrn_close_active_id();
	if(mmi_frm_scrn_is_present(GRP_ID_PHB_MAIN,SCR_ID_PHB_PROCESSING,MMI_FRM_NODE_ALL_FLAG))
	{
		mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
	}
	
   

}





static void mmi_phb_pb_entry_show_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
 
  
	ShowCategory8Screen(
			STR_SCR_PBOOK_CAPTION,
			IMG_SCR_PBOOK_CAPTION,
			0,
			0,
			STR_GLOBAL_CANCEL,
			IMG_GLOBAL_BACK,
			STR_GLOBAL_LOADING,
			mmi_get_event_based_image(MMI_EVENT_PROGRESS),
			NULL);
	
	StartTimer(
            PHB_NOTIFYDURATION_TIMER,
            3000,//mmi_get_event_based_duration(MMI_EVENT_FAILURE),
            mmi_phb_pb_entry_show_processing_timer_out_handler);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) <= 0)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);      

        //SetKeyHandler(mmi_phb_pb_processing_abort, KEY_END, KEY_EVENT_DOWN);
		SetKeyDownHandler(mmi_phb_pb_processing_abort, KEY_END);
    }
    
    SetRightSoftkeyFunction(mmi_phb_pb_processing_abort, KEY_EVENT_UP);

	
     
}

static MMI_RET mmi_phb_pb_processing_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
		
		case EVT_ID_SCRN_ACTIVE:
			mmi_phb_pb_entry_show_processing();
		break;
		
		default:
		 break;
	}
   
    return MMI_RET_OK;
}

static void mmi_phb_pb_show_processing(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
	mmi_frm_scrn_create(parent_id, scrn_id, mmi_phb_pb_processing_scrn_proc, NULL);
}

void mmi_phb_launch_pre_entry(void)
{
    if(srv_phb_startup_is_phb_ready())
    {
#if (SRV_PBAPC_LINK_NUM >= 2) 
#if !defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)

        mmi_phb_pbapc_set_list_type(0);
#endif
#endif
        mmi_phb_launch_entry();
    }
    else
    {
	    //mmi_phb_pb_show_processing(GRP_ID_PHB_MAIN,SCR_ID_PHB_PROCESSING);
	    mmi_phb_entry_not_ready(STR_GLOBAL_LOADING);
    }  
}


#if (SRV_PBAPC_LINK_NUM >= 2) 
#if !defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
static S32 mmi_phb_pbapc_bt_get_mydev_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    U8 index, idx;
    S32 ret;
    srv_bt_cm_bt_addr addr;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx(); 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
        idx = item_index + index;

        
        ret = srv_phb_pbapc_get_btd_addr(&addr,idx);
        kal_prompt_trace(MOD_MMI, "[TEST]mmi_phb_pbapc_bt_get_mydev_item: idx = %d,  ret = %d", idx, ret);
        if (ret >= 0)
        {
            srv_bt_cm_get_dev_ucs2_name(&addr, SRV_BT_CM_BD_UCS2_NAME_LEN, g_device_name[idx]);
            srv_bt_cm_get_dev_ucs2_name(&addr, SRV_BT_CM_BD_UCS2_NAME_LEN, menu_data[idx].item_list[0]);
        }
        else
        {
            kal_wsprintf(
                menu_data[idx].item_list[0],
                "%w",
                (U16*)GetString(STR_ID_PHB_PBAPC_BT1 + idx));
            kal_wsprintf(
                g_device_name[idx],
                "%w",
            (U16*)GetString(STR_ID_PHB_PBAPC_BT1 + idx));
            
        }
    }
    
    return data_size;

}


static void mmi_phb_pbapc_bt_mydev_highlight_hdlr(S32 idx)
{

    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->higlight_item = idx;

}
static void mmi_phb_pbapc_rsk_hdlr()
{
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx(); 
    kal_prompt_trace(MOD_MMI, "[TEST]mmi_phb_pbapc_rsk_hdlr: type = %d", phb_pbapc_cntx_p->list_type);
    if (phb_pbapc_cntx_p->list_type == 0)
    {
        mmi_frm_scrn_close_active_id();
        mmi_frm_group_close(GRP_ID_PHB_MAIN);
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        cui_phb_pbapc_bt_send_select_result(NULL, 1); // select cancel
    }
}


void mmi_phb_pbapc_enter_list(void)
{

    MMI_ID parent_id;
    MMI_ID group_id;
    MMI_ID group_enter;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx(); 
    if (phb_pbapc_cntx_p->list_type == 0)
    {
        parent_id = GRP_ID_PHB_MAIN;
        group_id = GRP_ID_PHB_LIST;
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        parent_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;
        group_id = GRP_ID_PHBLIST_PBAPC_SELECT_CONTACT;

    }
    group_id = mmi_frm_group_create(parent_id, group_id, NULL, NULL);
   
    group_enter = mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    kal_prompt_trace(MOD_MMI, "[TEST]mmi_phb_pbapc_enter_list: parent_id = %d,group_enter = %d", group_id, group_enter);
    mmi_phb_pbapc_entry_list();
}


void mmi_phb_launch_entry(void)
{
    U8* guiBuffer;
    U32 i;
    MMI_ID parent_id;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx(); 
    if (phb_pbapc_cntx_p->list_type == 0)
    {
        parent_id = GRP_ID_PHB_MAIN;
    }
    else if (phb_pbapc_cntx_p->list_type == 1)
    {
        parent_id = GRP_ID_PHB_PBAPC_SELECT_CONTACT;

    }
    mmi_frm_cb_reg_event(EVT_ID_PBAP_NOTIFY, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);//register evt;
    if (mmi_frm_scrn_enter(
     parent_id,
     SCR_PBOOK_MAIN_MENU,
     NULL,
     mmi_phb_launch_entry,
     MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(mmi_phb_pbapc_bt_mydev_highlight_hdlr);
        //wgui_list_menu_disable_access_by_shortcut();
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);

        wgui_cat1032_show(
         (WCHAR*)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
         NULL,
        (WCHAR*)GetString(STR_GLOBAL_OK),
         0,
         (WCHAR*)GetString(STR_GLOBAL_BACK),
         (PU8)GetImage(IMG_GLOBAL_BACK),
         2,
         mmi_phb_pbapc_bt_get_mydev_item,
         NULL,
         0,
         0,
         NULL,
         NULL,
         guiBuffer,
         NULL);
        wgui_restore_list_menu_slim_style();

        SetRightSoftkeyFunction(mmi_phb_pbapc_rsk_hdlr, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_phb_pbapc_enter_list, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_pbapc_enter_list, KEY_EVENT_UP);    
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_pbapc_enter_list);
#endif  // defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
  
    }
}

#endif
#else /*SRV_PBAPC_LINK_NUM > = 2*/
void mmi_phb_launch_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_UI_IN_TABS__)
    mmi_frm_tab_struct tab_pages_info_array[MMI_PHB_MAIN_SCREEN_TAB_COUNT];
#endif
    S32 tab_num = 0;
    S32 ret;
    srv_bt_cm_bt_addr bt_addr;
  #if SRV_PBAPC_LINK_NUM >= 2
    S32 ret1;
  #endif
#if 0
#ifdef __MMI_WGUI_MINI_TAB_BAR__
/* under construction !*/
/* under construction !*/
#endif
#endif
     U8 i, j;
#if defined(__MMI_BT_PBAP_CLIENT__)
    // myler-btdialer
#if !defined(__MMI_PHB_UI_IN_TABS__) && defined(__MMI_TELEPHONY_SUPPORT__)
    mmi_frm_tab_struct pbap_tab_pages_info_array[MMI_PHB_MAIN_SCREEN_TAB_COUNT];
    //mmi_frm_tab_struct pbap_tab_pages_info_array[2];
#endif

#if !defined(__MMI_PHB_UI_IN_TABS__) && !defined(__MMI_TELEPHONY_SUPPORT__)
        mmi_frm_tab_struct pbap_tab_pages_info_array[SRV_PBAPC_LINK_NUM];
        //mmi_frm_tab_struct pbap_tab_pages_info_array[2];
#endif

    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 tab_index = 0;
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_PBAP_CLIENT__)
    if (mmi_pbapc_is_bqb_test())
    {
        mmi_phb_pbapc_set_list_type(0);
        mmi_pbapc_bqb_start();

        return;
    }
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

#if defined(__MMI_BT_PBAP_CLIENT__)
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    mmi_frm_cb_reg_event(EVT_ID_DIALER_DISCONN_EVENT_ID, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);
    mmi_frm_cb_reg_event(EVT_ID_DIALER_CONN_EVENT_ID, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);
    mmi_frm_cb_reg_event(EVT_ID_PBAP_NOTIFY, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);
#endif

    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
#if 0
#ifdef __MMI_WGUI_MINI_TAB_BAR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
#endif

#if defined(__MMI_BT_PBAP_CLIENT__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
    //ret = mmi_phb_pbapc_is_connect();
    srv_phb_pbapc_get_btd_addr(&bt_addr, 0);
    kal_prompt_trace(MOD_MMI, "[TEST] launch_entry -- 0: %x, %x, %x", bt_addr.lap, bt_addr.nap, bt_addr.uap);
    ret = srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &bt_addr);
#if SRV_PBAPC_LINK_NUM >= 2
    srv_phb_pbapc_get_btd_addr(&bt_addr, 1);
    kal_prompt_trace(MOD_MMI, "[TEST] launch_entry -- 1: %x, %x, %x", bt_addr.lap, bt_addr.nap, bt_addr.uap);

    ret1 = srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &bt_addr);
#endif

#endif

/* Tab style */
#if defined(__MMI_PHB_UI_IN_TABS__)

#if SRV_PBAPC_LINK_NUM >= 2

#ifdef __MMI_TELEPHONY_SUPPORT__
#if defined(__MMI_PHB_QUICK_SEARCH__)
    tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_QUICK_SEARCH_LIST;
    tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_entry_quick_search_list_tab;
#else
    tab_pages_info_array[tab_num].screen_id = SCR_PBOOK_LIST;
    tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_list_entry_main;
#endif
    tab_pages_info_array[tab_num].tab_icon = (U8*)GetImage(IMG_ID_PHB_TAB_LIST);
    tab_pages_info_array[tab_num].tab_string = NULL;

#ifdef __MMI_PHB_CALLER_GROUP__
    tab_num++;
    tab_pages_info_array[tab_num].screen_id = SCR_CALLER_GROUPS;
    tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_entry_group_list_tab;
    tab_pages_info_array[tab_num].tab_icon = (U8*)GetImage(IMG_ID_PHB_TAB_GROUP);
    tab_pages_info_array[tab_num].tab_string = NULL;
#endif /* __MMI_PHB_CALLER_GROUP__ */

#ifdef __MMI_SNS_CONTACTS__
    tab_num++;
    tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_SNS_TAB0;
    tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_sns_entry_friend_list;
    tab_pages_info_array[tab_num].tab_icon = (U8*)GetImage(IMG_ID_PHB_SNS_TAB_FRIEND);
    tab_pages_info_array[tab_num].tab_string = NULL;

    tab_num++;
    tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_SNS_TAB1;
    tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_sns_entry_favorite_list;
    tab_pages_info_array[tab_num].tab_icon = (U8*)GetImage(IMG_ID_PHB_SNS_TAB_FAVORITE);
    tab_pages_info_array[tab_num].tab_string = NULL;
#endif
    tab_num++;

#endif /*__MMI_TELEPHONY_SUPPORT__*/
#ifdef __MMI_BT_PBAP_CLIENT__

    tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_PBAP_LIST;
    tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_pbapc_entry_list_tab;
    tab_pages_info_array[tab_num].tab_icon = NULL;
    tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_BT1);
    tab_num++;
    tab_pages_info_array[tab_num].tab_icon = NULL;
    tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_BT2);
    tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_PBAP_LIST2;
    tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_pbapc_entry_list_tab;
#endif

#if defined(__MMI_BT_PBAP_CLIENT__)
    // myler-btdialer
    mmi_phb_pbapc_set_list_type(0);
    kal_prompt_trace(MOD_MMI, "[TEST]launch_entry ---ret = %d, ret1 = %d", ret, ret1);
    if(!ret && !ret1)
    {
        tab_index = 0; // disconnected hlight local
    }
    else if (!ret && ret1)
    {
        if (phb_pbapc_cntx_p->phb_list == 0)
        {
            tab_index = 1;
        }
        else if (phb_pbapc_cntx_p->phb_list == 1)
        {
            tab_index = 0;
        }
        else if (phb_pbapc_cntx_p->phb_list == 2)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 1;
        #else
            tab_index = 0;
        #endif
        }
        else if (phb_pbapc_cntx_p->phb_list == 3)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 2;
        #else
            tab_index = 1;
        #endif
        }
    }
    else
    {
        if (phb_pbapc_cntx_p->phb_list == 0)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 1;
        #else
            tab_index = 0;
        #endif
        }
        else if (phb_pbapc_cntx_p->phb_list == 1)
        {
            tab_index = 0;
        }
        else if (phb_pbapc_cntx_p->phb_list == 2)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 1;
        #else
            tab_index = 0;
        #endif
        }
        else if (phb_pbapc_cntx_p->phb_list == 3)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 2;
        #else
            tab_index = 1;
        #endif
        }

    }       


    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_launch_entry--phb_list: %d, tab: %d, connect: %d\n",
                                                            phb_pbapc_cntx_p->phb_list, tab_index, phb_pbapc_cntx_p->bt_index);


#endif



#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__

		cui_tab_create(
			GRP_ID_PHB_MAIN,
			SCR_PBOOK_MAIN_MENU,
			tab_pages_info_array,
			tab_num + 1,//MMI_PHB_MAIN_SCREEN_TAB_COUNT,
		#ifdef __MMI_BT_PBAP_CLIENT__
        	tab_index,
		#else
			cui_tab_get_select_index(SCR_PBOOK_MAIN_MENU),
		#endif
			NULL);
		
	#ifdef __MMI_SNS_CONTACTS__
	mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_list_not_ready_proc, NULL);
	#endif
	
#else  //__MMI_TAB_BAR_SUPPORT_TAB_PAGE__

    mmi_frm_scrn_tab_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        mmi_phb_launch_exit,
        mmi_phb_launch_entry,
        tab_pages_info_array,
        MMI_PHB_MAIN_SCREEN_TAB_COUNT,
#ifdef __MMI_BT_PBAP_CLIENT__
        tab_index);
#else
        mmi_frm_scrn_tab_get_active_page_index());
#endif

#ifdef __MMI_SNS_CONTACTS__
    mmi_frm_scrn_set_leave_proc(
        GRP_ID_PHB_MAIN, 
        SCR_PBOOK_MAIN_MENU, 
        mmi_phb_sns_scrn_leave_proc);    
    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_list_not_ready_proc, NULL);
#endif

#endif   //__MMI_TAB_BAR_SUPPORT_TAB_PAGE__

   

#else   //NUM   >=2

#ifndef __MMI_TELEPHONY_SUPPORT__
        mmi_phb_pbapc_set_list_type(0);
        mmi_phb_pbapc_entry_list();
#else /*__MMI_TELEPHONY_SUPPORT__*/
    
        mmi_phb_pbapc_set_list_type(0);
        phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
#ifdef __MMI_TELEPHONY_SUPPORT__
#if defined(__MMI_PHB_QUICK_SEARCH__)
        pbap_tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_QUICK_SEARCH_LIST;
        pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_entry_quick_search_list_tab;
#else
        pbap_tab_pages_info_array[tab_num].screen_id = SCR_PBOOK_LIST;
        pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_list_entry_main;
#endif
    
    
        pbap_tab_pages_info_array[tab_num].tab_icon = NULL;
        pbap_tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_LOCAL);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
        tab_num++;
     
        pbap_tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_PBAP_LIST;
        pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_pbapc_entry_list_tab;
        pbap_tab_pages_info_array[tab_num].tab_icon = NULL;
        pbap_tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_BT1);
    
    
        if(!ret )
        {
            tab_index = 0; // disconnected hlight local
        }
        else
        {
            if (phb_pbapc_cntx_p->phb_list == 0)
            {
                tab_index = 1;
            }
            else if (phb_pbapc_cntx_p->phb_list == 1)
            {
                tab_index = 0;
            }
            else if (phb_pbapc_cntx_p->phb_list == 2)
            {
                tab_index = 1;
            }
        } 
        kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_launch_entry--phb_list: %d, tab: %d, connect: %d\n",
                                                                        phb_pbapc_cntx_p->phb_list, tab_index,ret);
    
    #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    
        cui_tab_create(
            GRP_ID_PHB_MAIN,
            SCR_PBOOK_MAIN_MENU,
            pbap_tab_pages_info_array,
    #ifdef __MMI_TELEPHONY_SUPPORT__
            MMI_PHB_MAIN_SCREEN_TAB_COUNT,
    #else
            SRV_PBAPC_LINK_NUM,
    #endif
            tab_index,
            NULL);
    
    #else /*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/
    
        mmi_frm_scrn_tab_enter(
            GRP_ID_PHB_MAIN,
            SCR_PBOOK_MAIN_MENU,
            mmi_phb_launch_exit,
            mmi_phb_launch_entry,
            pbap_tab_pages_info_array,
            2,
            //mmi_frm_scrn_tab_get_active_page_index());
            tab_index);
    
    #endif /*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/
    
    #endif/*__MMI_TELEPHONY_SUPPORT__*/


#endif /* num>=2 */

    return;
#endif /*__MMI_PHB_UI_IN_TABS__*/

#ifndef __MMI_PHB_UI_IN_TABS__

#if defined(__MMI_PHB_QUICK_SEARCH__) && !defined(__MMI_BT_PBAP_CLIENT__)
    mmi_phb_entry_quick_search_list(); /* quick search list */ 
#else  //defined(__MMI_PHB_QUICK_SEARCH__) && !defined(__MMI_BT_PBAP_CLIENT__)

#if defined(__MMI_BT_PBAP_CLIENT__)
#if SRV_PBAPC_LINK_NUM >= 2
    // myler-btdialer
    mmi_phb_pbapc_set_list_type(0);
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
#ifdef __MMI_TELEPHONY_SUPPORT__
#if defined(__MMI_PHB_QUICK_SEARCH__)
    pbap_tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_QUICK_SEARCH_LIST;
    pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_entry_quick_search_list_tab;
#else
    pbap_tab_pages_info_array[tab_num].screen_id = SCR_PBOOK_LIST;
    pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_list_entry_main;
#endif


    pbap_tab_pages_info_array[tab_num].tab_icon = NULL;
    pbap_tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_LOCAL);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#ifdef __MMI_TELEPHONY_SUPPORT__ /*test*/
    tab_num++;
#endif 
    pbap_tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_PBAP_LIST;
    pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_pbapc_entry_list_tab;
    pbap_tab_pages_info_array[tab_num].tab_icon = NULL;
    pbap_tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_BT1);

#if SRV_PBAPC_LINK_NUM >= 2
    tab_num++;
    pbap_tab_pages_info_array[tab_num].tab_icon = NULL;
    pbap_tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_BT2);
    pbap_tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_PBAP_LIST2;
    pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_pbapc_entry_list_tab;
#endif
    mmi_phb_pbapc_set_list_type(0);

    if(!ret && !ret1)
    {
        tab_index = 0; // disconnected hlight local
    }
    else if (!ret && ret1)
    {
        if (phb_pbapc_cntx_p->phb_list == 0)
        {
            tab_index = 1;
        }
        else if (phb_pbapc_cntx_p->phb_list == 1)
        {
            tab_index = 0;
        }
        else if (phb_pbapc_cntx_p->phb_list == 2)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 1;
        #else
            tab_index = 0;
        #endif
        }
        else if (phb_pbapc_cntx_p->phb_list == 3)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 2;
        #else
            tab_index = 1;
        #endif
        }
    }
    else
    {
        if (phb_pbapc_cntx_p->phb_list == 0)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 1;
        #else
            tab_index = 0;
        #endif
        }
        else if (phb_pbapc_cntx_p->phb_list == 1)
        {
            tab_index = 0;
        }
        else if (phb_pbapc_cntx_p->phb_list == 2)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 1;
        #else
            tab_index = 0;
        #endif
        }
        else if (phb_pbapc_cntx_p->phb_list == 3)
        {
        #ifdef __MMI_TELEPHONY_SUPPORT__
            tab_index = 2;
        #else
            tab_index = 1;
        #endif
        }
    } 
    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_launch_entry--phb_list: %d, tab: %d, connect: %d\n",
                                                                    phb_pbapc_cntx_p->phb_list, tab_index,ret);

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__

    cui_tab_create(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        pbap_tab_pages_info_array,
    #ifdef __MMI_TELEPHONY_SUPPORT__
        MMI_PHB_MAIN_SCREEN_TAB_COUNT,
    #else
        SRV_PBAPC_LINK_NUM,
    #endif
        tab_index,
        NULL);

#else

    mmi_frm_scrn_tab_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        mmi_phb_launch_exit,
        mmi_phb_launch_entry,
        pbap_tab_pages_info_array,
        2,
        //mmi_frm_scrn_tab_get_active_page_index());
        tab_index);


#endif
#else /* NUM >=2*/
#ifndef __MMI_TELEPHONY_SUPPORT__

    mmi_phb_pbapc_set_list_type(0);
    mmi_phb_pbapc_entry_list();
#else /*__MMI_TELEPHONY_SUPPORT__*/

    mmi_phb_pbapc_set_list_type(0);
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
#ifdef __MMI_TELEPHONY_SUPPORT__
#if defined(__MMI_PHB_QUICK_SEARCH__)
    pbap_tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_QUICK_SEARCH_LIST;
    pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_entry_quick_search_list_tab;
#else
    pbap_tab_pages_info_array[tab_num].screen_id = SCR_PBOOK_LIST;
    pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_list_entry_main;
#endif


    pbap_tab_pages_info_array[tab_num].tab_icon = NULL;
    pbap_tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_LOCAL);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    tab_num++;
 
    pbap_tab_pages_info_array[tab_num].screen_id = SCR_ID_PHB_PBAP_LIST;
    pbap_tab_pages_info_array[tab_num].tab_entry_func = mmi_phb_pbapc_entry_list_tab;
    pbap_tab_pages_info_array[tab_num].tab_icon = NULL;
    pbap_tab_pages_info_array[tab_num].tab_string = GetString(STR_ID_PHB_PBAPC_BT1);


    if(!ret )
    {
        tab_index = 0; // disconnected hlight local
    }
    else
    {
        if (phb_pbapc_cntx_p->phb_list == 0)
        {
            tab_index = 1;
        }
        else if (phb_pbapc_cntx_p->phb_list == 1)
        {
            tab_index = 0;
        }
        else if (phb_pbapc_cntx_p->phb_list == 2)
        {
            tab_index = 1;
        }
    } 
    kal_wap_trace(MOD_MMI_COMMON_APP, MMI_PHB_PBAPC_TRACE_GROUP, "[MMI_PHB_PBAPC] mmi_phb_launch_entry--phb_list: %d, tab: %d, connect: %d\n",
                                                                    phb_pbapc_cntx_p->phb_list, tab_index,ret);

    #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__

    cui_tab_create(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        pbap_tab_pages_info_array,
    #ifdef __MMI_TELEPHONY_SUPPORT__
        MMI_PHB_MAIN_SCREEN_TAB_COUNT,
    #else
        SRV_PBAPC_LINK_NUM,
    #endif
        tab_index,
        NULL);

    #else /*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/

    mmi_frm_scrn_tab_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        mmi_phb_launch_exit,
        mmi_phb_launch_entry,
        pbap_tab_pages_info_array,
        2,
        //mmi_frm_scrn_tab_get_active_page_index());
        tab_index);

    #endif /*__MMI_TAB_BAR_SUPPORT_TAB_PAGE__*/

    #endif/*__MMI_TELEPHONY_SUPPORT__*/
#endif /*NUM>=2*/

#else
    mmi_phb_list_entry_main(); /* normal list */ 
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

#endif  //defined(__MMI_PHB_QUICK_SEARCH__) && !defined(__MMI_BT_PBAP_CLIENT__)
#endif  //__MMI_PHB_UI_IN_TABS__
}
#endif /*!defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)*/
#endif
static U16 mmi_phb_calc_list_index(
            mmi_phb_refresh_struct *refresh_data,
            U8 list_type,
            U16 old_list_index,
            U16 *store_index_array,
            U8* bit_mask,
            U16 contact_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index = old_list_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (refresh_data->refresh_type)
    {
        case MMI_PHB_OP_ADD:
        case MMI_PHB_OP_EDIT:
        case MMI_PHB_OP_MOVE:
        case MMI_PHB_OP_COPY:
            for (list_index = 0; list_index < contact_count; list_index++)
            {
                if (store_index_array[list_index] == refresh_data->new_store_index)
                {
                    break;
                }
            }

            if (refresh_data->sg_id == GRP_ID_PHB_MAIN || refresh_data->sg_id == APP_PHONEBOOK)
            {
                if (list_index >= contact_count)
                {
                    list_index = old_list_index;
                }
            }
            else
            {
                if (list_index <= old_list_index)
                {
                    list_index = old_list_index + 1;
                }
                else
                {
                    list_index = old_list_index;
                }
            }
            break;

        case MMI_PHB_OP_DELETE:
            list_index = --old_list_index;
            break;

    #if defined(__MMI_PHB_MULTI_OPERATION__) || defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
        case MMI_PHB_OP_COPY_ALL:
        case MMI_PHB_OP_DELETE_ALL:
        case MMI_PHB_OP_MOVE_ALL:
        case MMI_PHB_OP_MULTI_COPY:
        case MMI_PHB_OP_MULTI_DELETE:
        case MMI_PHB_OP_MULTI_MOVE:
        {
            if (list_type == MMI_PHB_LIST_TYPE_MULTI_SELECT && bit_mask)
            {
                for (list_index = 0; list_index < contact_count; list_index++)
                {
                    if (mmi_phb_bitmask_get_state(bit_mask, store_index_array[list_index]))
                    {
                        break;
                    }
                }
            }
            else if (list_type == MMI_PHB_LIST_TYPE_SINGLE_SELECT)
            {
                list_index = 0;
            }
            break;
        }
    #endif
    
        default:
            break;
    }

    if (list_index >= contact_count)
    {
        list_index--;
    }

    return list_index;
}


#ifndef __MMI_PHB_QUICK_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_entry_main_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_list_entry_main_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

    if (item_index == 0)
    {
        g_mmi_phb_list_p->list_index = 0;
        g_mmi_phb_list_p->store_index = 0xffff;
        
       
#ifndef __MMI_WGUI_DISABLE_CSK__
#ifndef __MMI_MAINLCD_96X64__
        ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_ADD);
#else
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif
        SetCenterSoftkeyFunction(mmi_phb_op_add_new_entry, KEY_EVENT_UP);
    
        //SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_UP);
		SetKeyUpHandler(NULL, KEY_SEND);
        
    #if defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__) */ 

    #ifdef __MMI_ICON_BAR_SUPPORT__
        mmi_phb_fte_contact_list_update(0,MMI_FALSE);
    #endif
        return;
    }
    else
    {
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        //SetKeyHandler(mmi_phb_dial_default_number_and_start_browser, KEY_SEND, KEY_EVENT_UP);
		SetKeyUpHandler(mmi_phb_dial_default_number_and_start_browser, KEY_SEND);
    #else
        //SetKeyHandler(mmi_phb_dial_normal_call, KEY_SEND, KEY_EVENT_UP);
		SetKeyUpHandler(mmi_phb_dial_normal_call, KEY_SEND);
    #endif
    
    #if defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__)   /* For IP Dial Key */
/* under construction !*/
/* under construction !*/
    #endif /* defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__) */ 

        g_mmi_phb_list_p->list_index = item_index;
        g_mmi_phb_list_p->store_index = g_mmi_phb_list_p->contact_array[item_index - 1];
    }

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_phb_op_view_pre_entry, KEY_EVENT_UP);

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_phb_fte_contact_list_update(0,MMI_TRUE);
#endif
    
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_start();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 
}


static S32 mmi_phb_list_entry_main_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
    //#if defined(__MMI_BT_PBAP_CLIENT__)
    #if 0
/* under construction !*/
    #else
        if ((item_index + index) == 0)
        {
            mmi_ucs2cpy((CHAR*)  menu_data[index].item_list[0], GetString(STR_ID_PHB_ADD_NEW_CONTACT));
            menu_data[index].image_list[0] = UI_NULL_IMAGE;
            menu_data[index].image_list[1] = UI_NULL_IMAGE;
        }
        else
        {
            mmi_phb_list_get_item((item_index + index - 1), menu_data[index].item_list[0], &menu_data[index].image_list[0], &menu_data[index].image_list[1]);
        }
    #endif
    }
    return data_size;
}


static S32 mmi_phb_list_entry_main_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == 0)
    {
        return 0;
    }
    else
    {
        item_index--;
    }
    
    return mmi_phb_list_get_hint_ext(item_index, hint_array);
}


static MMI_BOOL mmi_phb_list_entry_main_seperate_line(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        *flag |= UI_MENUITEM_DISABLE_ICON;
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


static void mmi_phb_list_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 contact_count;
    srv_phb_filter_struct * filter;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data;
#ifdef __MMI_ICON_BAR_SUPPORT__
    S32 item_count = MMI_PHB_TOOLBAR_ENUM_TOTAL;
    PU8 item_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL];
    PU8 item_disable_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL];
    PU8 string[MMI_PHB_TOOLBAR_ENUM_TOTAL];
#endif /* __MMI_ICON_BAR_SUPPORT__ */

#if defined(__MMI_BT_PBAP_CLIENT__)
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_UI_IN_TABS__)
    #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
        if (!cui_tab_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_LIST,
        mmi_phb_launch_exit,
        mmi_phb_list_entry_main,
        MMI_FRM_FULL_SCRN))
    #else
        if (!mmi_frm_scrn_tab_page_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        SCR_PBOOK_LIST,
        mmi_phb_launch_exit,
        mmi_phb_list_entry_main,
        MMI_FRM_TAB_PAGE
        ))
    #endif
    {
        return;
    }
#elif defined(__MMI_BT_PBAP_CLIENT__)

    #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
        if (!cui_tab_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_LIST,
        mmi_phb_launch_exit,
        mmi_phb_list_entry_main,
        MMI_FRM_FULL_SCRN))
    #else
        if (!mmi_frm_scrn_tab_page_enter(
        GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        SCR_PBOOK_LIST,
        mmi_phb_launch_exit,
        mmi_phb_list_entry_main,
        MMI_FRM_TAB_PAGE
        ))
    #endif

    {
        return;
    }

    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->phb_list = 1;
	
#else
    
	#ifndef __MMI_PHB_SLIM_NEW__
	    if (!mmi_frm_scrn_enter(
	            GRP_ID_PHB_MAIN,
	            SCR_PBOOK_LIST,
	            mmi_phb_launch_exit,
	            mmi_phb_launch_entry,
	            MMI_FRM_FULL_SCRN
	            ))
	#else
		if (!mmi_frm_scrn_enter(
	            GRP_ID_PHB_MAIN,
	            SCR_PBOOK_LIST,
	            mmi_phb_launch_exit,
	            mmi_phb_launch_pre_entry,
	            MMI_FRM_FULL_SCRN
	            ))
	#endif
    
    {
        return;
    }
#endif

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if(!gui_buffer)
	{
		 gui_buffer = (U8 *)cui_tab_get_screen_gui_buf(SCR_PBOOK_MAIN_MENU,SCR_PBOOK_LIST);
	 }
#endif

    /* refresh prefer storage */
	#ifndef __MMI_PHB_SLIM_NEW__
    if (g_mmi_phb_list_p->storage != mmi_phb_get_preferred_storage() ||
        g_mmi_phb_list_p->display_type != srv_phb_get_name_display_type())
    {
        g_mmi_phb_list_p->storage = (U8) mmi_phb_get_preferred_storage();
        g_mmi_phb_list_p->display_type = (U8) srv_phb_get_name_display_type();
        gui_buffer = NULL;
    }
	#else
    if (g_mmi_phb_list_p->storage != srv_phb_get_storage_mask() ||
        g_mmi_phb_list_p->display_type != srv_phb_get_name_display_type())
    {
        g_mmi_phb_list_p->storage = (U8) srv_phb_get_storage_mask();
        g_mmi_phb_list_p->display_type = (U8) srv_phb_get_name_display_type();
        gui_buffer = NULL;
    }
	#endif

    RegisterHighlightHandler(mmi_phb_list_entry_main_highlight_hdlr);
    
    filter = mmi_phb_list_build_filter(
                 PHB_STORAGE_MAX,
                 g_mmi_phb_list_p->filter,
                 NULL,
                 NULL,
                 0);
    
    contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
    g_mmi_phb_list_p->contact_count = contact_count;

    mmi_phb_list_free_filter(filter);

    if (gui_buffer == NULL)
    {
    //#if defined(__MMI_BT_PBAP_CLIENT__)
    #if 0
/* under construction !*/
/* under construction !*/
    #else
        g_phb_highlight_alpha = 0;
        
        if (contact_count == 0)
        {
            g_mmi_phb_list_p->list_index = 0;        
        }
        else
        {
            g_mmi_phb_list_p->list_index = 1;
        }

        contact_count++;
    #endif
    }
    else if (!mmi_is_redrawing_bk_screens())
    {
        handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
        refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);

        if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
        {
            gui_buffer = NULL;

            if (contact_count == 0)
            {
                g_mmi_phb_list_p->list_index = 0;
            }
            else
            {
                g_mmi_phb_list_p->list_index = mmi_phb_calc_list_index(
                                                refresh_data,
                                                MMI_PHB_LIST_TYPE_SINGLE_SELECT,
                                                g_mmi_phb_list_p->list_index,
                                                g_mmi_phb_list_p->contact_array,
                                                NULL,
                                                g_mmi_phb_list_p->contact_count);

                g_mmi_phb_list_p->list_index++;
            }            
            refresh_data->refresh_type = MMI_PHB_OP_NONE;
        }
        contact_count++;
    }
    
    /**
     * Always call build alpha jump function
     */
    srv_phb_oplib_build_alpha_jump_table(g_mmi_phb_list_p->contact_array, g_mmi_phb_list_p->contact_count);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_fixed_list_register_get_flags_handler(mmi_phb_list_entry_main_seperate_line);

#ifdef __MMI_ICON_BAR_SUPPORT__
    item_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL);
    item_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
    item_icon[MMI_PHB_EDIT] = get_image(IMG_GLOBAL_TOOLBAR_EDIT);
    item_disable_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
    item_disable_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
    item_disable_icon[MMI_PHB_EDIT] = get_image(IMG_GLOBAL_TOOLBAR_EDIT_DISABLED);
    string[MMI_PHB_VOICE_CALL] = (PU8)get_string(STR_GLOBAL_DIAL);
    string[MMI_PHB_SEND_MSG] = (PU8)get_string(STR_GLOBAL_SEND);
    string[MMI_PHB_EDIT] = (PU8)get_string(STR_GLOBAL_EDIT);
//#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#if defined(__MMI_VIDEO_TELEPHONY__)
    item_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_VIDEO_CALL);
    item_disable_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_VIDEO_CALL_DISABLED);
    string[MMI_PHB_VIDEO_CALL] = (PU8)get_string(STR_GLOBAL_DIAL_VIDEO_CALL);
#endif
    wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, string, (GUIIconbarItemCallback)mmi_phb_fte_contact_list_callback);
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    wgui_cat1032_show(
        (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
        (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
        (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (WCHAR*) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        contact_count,
        mmi_phb_list_entry_main_get_item,
        mmi_phb_list_entry_main_get_hint,
        g_mmi_phb_list_p->list_index,
        0,    
        IMG_STORAGE_SIM,
        IMG_GLOBAL_SIM1,
        gui_buffer,
        NULL);

    /* register multi-tap function for fast jump, for full list only */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_QWERTY);
    mmi_frm_set_app_translate_key_handler(mmi_phb_list_alpha_callback_ext);
#else
    wgui_setup_multitap_functions(WGUI_MULTITAP_TYPE_UPPERCASE_ABC, mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback_ext);
#endif

    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_contact_list_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}
#endif /* __MMI_PHB_QUICK_SEARCH__ */

#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
/* under construction !*/
    #else /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
/* under construction !*/
    #else
/* under construction !*/
    #endif
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
#endif

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_get_image_path_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_thumbnail_get_image_path_callback(U16 store_id, CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 res_type;
    U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path[0] = '\0';
    path[1] = '\0';

    srv_phb_get_image(store_id, &img_id, (U16*)path, &res_type);

    if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_set_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_thumbnail_set_displayable(U16 store_id, MMI_BOOL displayable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *mask;
    CHAR set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mask = &thumbnail_bitmask[store_id/8];
    set = 1<<store_id%8;

    if (displayable)
    {
        *mask |= set;
    }
    else
    {
        *mask ^= set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_get_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_thumbnail_get_displayable(U16 store_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (thumbnail_bitmask[store_id/8] & (1<<store_id%8))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_get_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_thumbnail_reset_displayable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(thumbnail_bitmask, 0xFF, (MMI_PHB_ENTRIES + 7) / 8);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_get_menuitem_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_thumbnail_get_menuitem_info(U16 store_id, wgui_thumbnail_info_struct *menuitem_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menuitem_data->file_icon_ptr = (PU8)GetImage(IMG_STORAGE_SIM);
    menuitem_data->is_show_thumb = MMI_FALSE;

    if(store_id != 0xffff)
    {
        if (mmi_phb_check_storage(MMI_TRUE, srv_phb_get_storage(store_id)))
        {
            U16 res_type;
            U16 img_id;
            U16 img_path[SRV_FMGR_PATH_MAX_LEN + 1];

            srv_phb_get_image(store_id, &img_id, img_path, &res_type);

            menuitem_data->file_icon_ptr = (PU8)GetImage(IMG_ID_PHB_LIST_PHOTO);

            if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
            {
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                if (srv_fmgr_fs_path_exist((WCHAR*)img_path) >= 0)
                {
                    menuitem_data->is_show_thumb = MMI_TRUE;
                }
            #endif
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_get_image_path_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_main_list_thumbnail_get_image_path_callback(S32 item_idx, CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_thumbnail_get_image_path_callback(mmi_phb_get_store_id_by_list_index_ext(item_idx), path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_set_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_main_list_thumbnail_set_displayable(S32 item_idx, MMI_BOOL displayable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_thumbnail_set_displayable(mmi_phb_get_store_id_by_list_index_ext(item_idx), displayable);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_get_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_main_list_thumbnail_get_displayable(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_thumbnail_get_displayable(mmi_phb_get_store_id_by_list_index_ext(item_idx));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_get_menuitem_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_main_list_thumbnail_get_menuitem_info(S32 item_idx, wgui_thumbnail_info_struct *menuitem_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_thumbnail_get_menuitem_info(mmi_phb_get_store_id_by_list_index_ext(item_idx), menuitem_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_list_thumbnail_get_image_path_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_generic_list_thumbnail_get_image_path_callback(S32 item_idx, CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_thumbnail_get_image_path_callback(mmi_phb_get_store_id_by_list_index(item_idx), path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_list_thumbnail_set_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_generic_list_thumbnail_set_displayable(S32 item_idx, MMI_BOOL displayable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_thumbnail_set_displayable(mmi_phb_get_store_id_by_list_index(item_idx), displayable);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_list_thumbnail_get_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_generic_list_thumbnail_get_displayable(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_thumbnail_get_displayable(mmi_phb_get_store_id_by_list_index(item_idx));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_list_thumbnail_get_menuitem_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_generic_list_thumbnail_get_menuitem_info(S32 item_idx, wgui_thumbnail_info_struct *menuitem_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_thumbnail_get_menuitem_info(mmi_phb_get_store_id_by_list_index(item_idx), menuitem_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_refresh_photo_sticker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_check_refresh_photo_sticker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scrn_id = mmi_frm_scrn_get_active_id();
	MMI_BOOL refresh = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 901);

    if (scrn_id == SCR_ID_PHB_QUICK_SEARCH_LIST
        || scrn_id == SCR_PBOOK_MAIN_MENU
        || scrn_id == SCR_ID_PHB_MULTI_OP_PHB_LIST
        || scrn_id == SCR_ID_PHB_GENERIC_MULTI_SELECT
        || scrn_id == SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST
        || scrn_id == SCR_PBOOK_LIST
        || scrn_id == SCR_ID_PHB_CALLERGROUP_MEMBER_LIST
        )
    {
        refresh = MMI_TRUE;
    }
    else if (scrn_id == SCR_ENTRY_VIEW)
    {
    	if (mmi_phb_check_storage(MMI_TRUE, srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index)))
        {
            refresh = MMI_TRUE;
    	}
	}

    return refresh;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_refresh_photo_sticker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_refresh_photo_sticker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scrn_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_READ_SPEED_DIAL_TIMER);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 903);

    if (scrn_id == SCR_ID_PHB_QUICK_SEARCH_LIST
        || scrn_id == SCR_PBOOK_MAIN_MENU
        || scrn_id == SCR_ID_PHB_MULTI_OP_PHB_LIST
        || scrn_id == SCR_ID_PHB_GENERIC_MULTI_SELECT
        || scrn_id == SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST
        || scrn_id == SCR_PBOOK_LIST
        || scrn_id == SCR_ID_PHB_CALLERGROUP_MEMBER_LIST
        )
    {
        mmi_phb_thumbnail_reset_displayable();
		RedrawCategoryFunction();
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 904);
    }
    else if (scrn_id == SCR_ENTRY_VIEW)
    {
    	if (mmi_phb_check_storage(MMI_TRUE, srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index)))
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
	    	MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 905);
    	}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_usb_ms_mode_exit_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_phb_usb_ms_mode_exit_hdlr(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 901);

	if (mmi_phb_check_refresh_photo_sticker())
    {
        StopTimer(PHB_READ_SPEED_DIAL_TIMER);
        StartTimer(PHB_READ_SPEED_DIAL_TIMER, 500, mmi_phb_refresh_photo_sticker);

        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 902);
    }

    return MMI_RET_OK;
}
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */


#define MMI_PHB_QUICKSEARCH

#if defined(__MMI_PHB_QUICK_SEARCH__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_change_input_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_change_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* refresh the quicksearch list */
    mmi_phb_cntx_mgr_input_method_change();

    /* Call srv api to make cache again */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_find_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyword     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_phb_quick_search_find_entry(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 key_length;
    S32 result_count;
    srv_phb_filter_struct *filter_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Count the input string length to decide behavior */
    key_length = (U8) mmi_ucs2strlen((CHAR*) keyword);
    result_count = 0;

    /* add new contact , so result_count++ */
#ifndef __MMI_MAINLCD_96X64__
    if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN && key_length == 0)
#else
    if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN && key_length == 0 &&g_mmi_phb_list_p->contact_count==0)
#endif
    {
        result_count++;
    }

    /* build searched contact list */

#ifndef __MMI_MAINLCD_96X64__	
	
if((MMI_TRUE==is_from_group_mark_several) || (MMI_TRUE==is_not_from_mark_several_main))
	{
		filter_ext = mmi_phb_list_build_filter(
        g_mmi_phb_list_p->storage,
        g_mmi_phb_list_p->filter,
        &g_mmi_phb_list_p->group_filter,
        (U16*)keyword,
        (U16)mmi_imm_get_curr_input_mode());
	}
	else
	{
	    filter_ext = mmi_phb_list_build_filter(
        PHB_STORAGE_MAX,
        g_mmi_phb_list_p->filter,
        &g_mmi_phb_list_p->group_filter,
        (U16*)keyword,
        (U16)mmi_imm_get_curr_input_mode());	
	}
#else
        filter_ext = mmi_phb_list_build_filter(
        PHB_STORAGE_MAX,
        g_mmi_phb_list_p->filter,
        &g_mmi_phb_list_p->group_filter,
        (U16*)keyword,
        (U16)mmi_imm_get_curr_input_mode());

#endif


		
    
    g_mmi_phb_list_p->contact_count = (U16) srv_phb_oplib_build_contact_list(filter_ext, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
#ifdef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__    
    if (g_mmi_phb_list_p->is_widget)
    {
        mmi_phb_list_select_widget();    
    }
#endif
    result_count += g_mmi_phb_list_p->contact_count;

    mmi_phb_list_free_filter(filter_ext);
  
    if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
    {
        if (result_count == 0)  /* Clear send key when no entry found */
        {
            ClearKeyHandler(KEY_SEND, KEY_EVENT_UP);
        #if defined(__MMI_INTELLIGENT_CALL_ALERT__)
            mmi_phb_speak_name_end();
        #endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 
        }
        else
        {
        #ifdef __MMI_PHB_DEFAULT_NUMBER__
            //SetKeyHandler(mmi_phb_dial_default_number_and_start_browser, KEY_SEND, KEY_EVENT_UP);
			SetKeyUpHandler(mmi_phb_dial_default_number_and_start_browser, KEY_SEND);
        #else
            //SetKeyHandler(mmi_phb_dial_normal_call, KEY_SEND, KEY_EVENT_UP);
			SetKeyUpHandler(mmi_phb_dial_normal_call, KEY_SEND);
        #endif     
        }
    }
    else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
    {
        if (result_count == 0)  /* Clear send key when no entry found */
        {
            ClearKeyHandler(KEY_SEND, KEY_EVENT_UP);
        }
    }
    else
    {
        ASSERT(0);
    }

    if (result_count == 0)
    {
        U16 cur_screen = mmi_frm_scrn_get_active_id();
        if (cur_screen == SCR_ID_PHB_GENERIC_MULTI_SELECT
            || cur_screen == SCR_ID_PHB_QUICK_SEARCH_LIST
            || cur_screen == SCR_ID_PHB_MULTI_OP_PHB_LIST
            || cur_screen == SCR_PBOOK_MAIN_MENU
            || cur_screen == SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST)
        {
            ChangeCenterSoftkey(0, 0);
			#ifdef __MMI_MAINLCD_96X64__
			ClearKeyHandler(KEY_CSK, KEY_EVENT_UP);
			#endif
        }
    }
    else
    {
        U16 cur_screen = mmi_frm_scrn_get_active_id();
        if (cur_screen == SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST)
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
    }

#ifdef __MMI_ICON_BAR_SUPPORT__
    if (result_count == 0)
    {
        mmi_phb_fte_contact_list_update(0, MMI_FALSE);
    }
#endif

    return result_count;
}


static S32 mmi_phb_quick_search_find_entry_tab(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_count = mmi_phb_quick_search_find_entry(keyword);

    if (result_count == 0)
    {
        //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
		SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
    }

    return result_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_get_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_MAINLCD_96X64__
static void mmi_phb_quick_search_get_index(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    //SetKeyHandler(mmi_phb_dial_default_number_and_start_browser, KEY_SEND, KEY_EVENT_UP);
	SetKeyUpHandler(mmi_phb_dial_default_number_and_start_browser, KEY_SEND);
#else
    //SetKeyHandler(mmi_phb_dial_normal_call, KEY_SEND, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_phb_dial_normal_call, KEY_SEND);
#endif

    if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0)
    {
        if (item_index == 0)
        {
            g_mmi_phb_list_p->list_index = 0;
            g_mmi_phb_list_p->store_index = 0xffff;
            
#ifndef __MMI_WGUI_DISABLE_CSK__           
#ifndef __MMI_MAINLCD_96X64__
            ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_ADD);
#else
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif	
#endif	

            //SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_UP);
			SetKeyUpHandler(NULL, KEY_SEND);

        #ifdef __MMI_ICON_BAR_SUPPORT__
            mmi_phb_fte_contact_list_update(0, MMI_FALSE);
        #endif
            return;
        }
        else
        {
            item_index--;
        }
    }

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    g_mmi_phb_list_p->list_index = item_index;
    g_mmi_phb_list_p->store_index = g_mmi_phb_list_p->contact_array[item_index];
    
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_start();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_phb_fte_contact_list_update(item_index, MMI_TRUE);
#endif
}

#else
static void mmi_phb_quick_search_get_index(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    //SetKeyHandler(mmi_phb_dial_default_number_and_start_browser, KEY_SEND, KEY_EVENT_UP);
	SetKeyUpHandler(mmi_phb_dial_default_number_and_start_browser, KEY_SEND);
#else
    //SetKeyHandler(mmi_phb_dial_normal_call, KEY_SEND, KEY_EVENT_UP);
	SetKeyUpHandler(mmi_phb_dial_normal_call, KEY_SEND);
#endif

    if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0 && g_mmi_phb_list_p->contact_count ==0)
    {
        if (item_index == 0)
        {
            g_mmi_phb_list_p->list_index = 0;
            g_mmi_phb_list_p->store_index = 0xffff;
            #ifndef __MMI_WGUI_DISABLE_CSK__
            
#ifndef __MMI_MAINLCD_96X64__
            ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_ADD);
#else
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
			#endif

            //SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_UP);
			SetKeyUpHandler(NULL, KEY_SEND);

        #ifdef __MMI_ICON_BAR_SUPPORT__
            mmi_phb_fte_contact_list_update(0, MMI_FALSE);
        #endif
            return;
        }
        
    }
    #ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	#endif

    g_mmi_phb_list_p->list_index = item_index;
    g_mmi_phb_list_p->store_index = g_mmi_phb_list_p->contact_array[item_index];
    
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_start();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_phb_fte_contact_list_update(item_index, MMI_TRUE);
#endif
}

#endif

static void mmi_phb_quick_search_get_index_tab(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);

    mmi_phb_quick_search_get_index(item_index);
}


static void mmi_phb_quick_search_center_key_handlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_list_p->store_index == 0xffff)
    {
        mmi_phb_op_add_new_entry_ext(GRP_ID_PHB_MAIN);
    }
    else
    {
        cui_phb_view_contact(g_mmi_phb_list_p->sg_id, g_mmi_phb_list_p->store_index);
    }
}

#ifndef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_phb_quick_search_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < data_size; ++i)
    {
        if ((item_index + i) == 0)
        {
            if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0)
            {
              mmi_ucs2cpy((CHAR*) menu_data[i].item_list[0], GetString(STR_ID_PHB_ADD_NEW_CONTACT));
              menu_data[item_index].image_list[0] = NULL;
              menu_data[item_index].image_list[1] = NULL;
            }
            else
            {
                mmi_phb_list_get_item((item_index + i), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
            }
        }
        else
        {
            if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0)
            {
                mmi_phb_list_get_item((item_index + i - 1), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
            }
            else
            {
                mmi_phb_list_get_item((item_index + i), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
            }
        }
    }
    
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_phb_quick_search_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0)
    {
        if (item_index == 0)
        {
            return 0;
        }
        else
        {
            item_index--;
        }
    }

    return mmi_phb_list_get_hint_ext(item_index, hint_array);
}
#else


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_phb_quick_search_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < data_size; ++i)
    {
       
         mmi_phb_list_get_item((item_index + i), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
         if ((item_index + i) == 0)
        {
            if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0 && g_mmi_phb_list_p->contact_count==0 )		
            {
              mmi_ucs2cpy((CHAR*) menu_data[i].item_list[0], GetString(STR_ID_PHB_ADD_NEW_CONTACT));
              menu_data[item_index].image_list[0] = NULL;
              menu_data[item_index].image_list[1] = NULL;
            }
            else
            {
                mmi_phb_list_get_item((item_index + i), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
            }
        }
        else
        {
            
            {
                mmi_phb_list_get_item((item_index + i), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
            }
        }
    }
    
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_phb_quick_search_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0 && g_mmi_phb_list_p->contact_count==0 )
	
    {
        if (item_index == 0)
        {
            return 0;
        }
       
    }

    return mmi_phb_list_get_hint_ext(item_index, hint_array);
}


#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_seperate_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_quick_search_list_seperate_line(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_96X64__
    if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0 && index == 0)
#else
    if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0 && index == 0 && g_mmi_phb_list_p->contact_count==0)
#endif
    {
        *flag |= UI_MENUITEM_DISABLE_ICON;
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_quick_search_list_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_exit_quick_search_list_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    StopTimer(KEYPAD_LOCK_TIMER);
#if 0
#if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
#endif 
#endif 

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_quick_search_list_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_quick_search_list_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 contact_count=0;
    srv_phb_filter_struct * filter;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data = NULL;
#ifdef __MMI_ICON_BAR_SUPPORT__
    S32 item_count = MMI_PHB_TOOLBAR_ENUM_TOTAL;
    PU8 item_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL];
    PU8 item_disable_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL];
    PU8 string[MMI_PHB_TOOLBAR_ENUM_TOTAL];
#endif /* __MMI_ICON_BAR_SUPPORT__ */
    U16 left_icon_id = IMG_GLOBAL_L1;
    kal_bool need_to_reflesh=MMI_FALSE;

#if defined(__MMI_BT_PBAP_CLIENT__)
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            GRP_ID_PHB_MAIN,
            SCR_ID_PHB_QUICK_SEARCH_LIST,
            mmi_phb_exit_quick_search_list_tab,
            mmi_phb_entry_quick_search_list_tab,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            GRP_ID_PHB_MAIN,
            SCR_PBOOK_MAIN_MENU,
            SCR_ID_PHB_QUICK_SEARCH_LIST,
            mmi_phb_exit_quick_search_list_tab,
            mmi_phb_entry_quick_search_list_tab,
            MMI_FRM_TAB_PAGE))
     #endif
    {
        return;
    }

#if defined(__MMI_BT_PBAP_CLIENT__)
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->phb_list = 1;
#endif

    g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_MAIN;

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
   #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!gui_buffer)
	   {
	   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_PBOOK_MAIN_MENU,SCR_ID_PHB_QUICK_SEARCH_LIST);
	   	}
   #endif	

    /* refresh prefer storage */
	#ifndef __MMI_PHB_SLIM_NEW__
    if (g_mmi_phb_list_p->storage != mmi_phb_get_preferred_storage() ||
        g_mmi_phb_list_p->display_type != srv_phb_get_name_display_type())
    {
        g_mmi_phb_list_p->storage = (U8) mmi_phb_get_preferred_storage();
        g_mmi_phb_list_p->display_type = (U8) srv_phb_get_name_display_type();
        gui_buffer = NULL;
        g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
    }
	#else
    if (g_mmi_phb_list_p->storage != srv_phb_get_storage_mask() ||
        g_mmi_phb_list_p->display_type != srv_phb_get_name_display_type())
    {
        g_mmi_phb_list_p->storage = (U8) srv_phb_get_storage_mask();
        g_mmi_phb_list_p->display_type = (U8) srv_phb_get_name_display_type();
        gui_buffer = NULL;
		g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
    }
	#endif

    RegisterHighlightHandler(mmi_phb_quick_search_get_index_tab);
    RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry_tab);

    if (gui_buffer == NULL)
    {
        filter = mmi_phb_list_build_filter(
                     PHB_STORAGE_MAX,
                     g_mmi_phb_list_p->filter,
                     &g_mmi_phb_list_p->group_filter,
                     NULL,
                     0);
        
        contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
        g_mmi_phb_list_p->contact_count = contact_count;
        mmi_phb_list_free_filter(filter);
        if (contact_count == 0)
        {
            g_mmi_phb_list_p->list_index = 0;        
        }
        else
        {
            g_mmi_phb_list_p->list_index = 1;
        }

        contact_count++;
    }
    else
    {
        if (!mmi_is_redrawing_bk_screens())
        {
            handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
            refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);
        }
        if (!mmi_is_redrawing_bk_screens() &&
            refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
        {
            gui_buffer = NULL;

            filter = mmi_phb_list_build_filter(
                         PHB_STORAGE_MAX,
                         g_mmi_phb_list_p->filter,
                         &g_mmi_phb_list_p->group_filter,
                         NULL,
                         0);
            
            contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
            g_mmi_phb_list_p->contact_count = contact_count;
            
            mmi_phb_list_free_filter(filter);

            if (contact_count == 0)
            {
                g_mmi_phb_list_p->list_index = 0;
            }
            else
            {
                g_mmi_phb_list_p->list_index = mmi_phb_calc_list_index(
                                                refresh_data,
                                                MMI_PHB_LIST_TYPE_SINGLE_SELECT,
                                                g_mmi_phb_list_p->list_index,
                                                g_mmi_phb_list_p->contact_array,
                                                NULL,
                                                g_mmi_phb_list_p->contact_count);

                g_mmi_phb_list_p->list_index++;
            }

            contact_count++;
            g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
            
            refresh_data->refresh_type = MMI_PHB_OP_NONE;
        }
        else
        {
            need_to_reflesh=MMI_TRUE; 
        }
    }
    
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    set_force_icon_on_highlight_only_in_menuitem();
#endif

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    wgui_fixed_list_register_get_flags_handler(mmi_phb_quick_search_list_seperate_line);
#ifdef __MMI_SNS_CONTACTS__
    wgui_cat199_register_get_attachment_icon_callback(mmi_phb_sns_get_link_icon);
#endif

#ifdef __MMI_ICON_BAR_SUPPORT__
    item_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL);
    item_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
    item_icon[MMI_PHB_EDIT] = get_image(IMG_GLOBAL_TOOLBAR_EDIT);
    item_disable_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
    item_disable_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
    item_disable_icon[MMI_PHB_EDIT] = get_image(IMG_GLOBAL_TOOLBAR_EDIT_DISABLED);
    string[MMI_PHB_VOICE_CALL] = (PU8)get_string(STR_GLOBAL_DIAL);
    string[MMI_PHB_SEND_MSG] = (PU8)get_string(STR_GLOBAL_SEND);
    string[MMI_PHB_EDIT] = (PU8)get_string(STR_GLOBAL_EDIT);
//#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#if defined(__MMI_VIDEO_TELEPHONY__)
    item_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_VIDEO_CALL);
    item_disable_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_VIDEO_CALL_DISABLED);
    string[MMI_PHB_VIDEO_CALL] = (PU8)get_string(STR_GLOBAL_DIAL_VIDEO_CALL);
#endif
    wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, string, (GUIIconbarItemCallback)mmi_phb_fte_contact_list_callback);
#endif /* __MMI_ICON_BAR_SUPPORT__ */

#ifndef __MMI_MAINLCD_96X64__
    wgui_cat_set_search_icon(IMG_ID_PHB_QUICK_SEARCH_FIND);
#else
    wgui_cat_set_search_icon(IMG_GLOBAL_COMMON_CSK);
#endif

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
    mmi_phb_thumbnail_reset_displayable();
    wgui_thumbnail_register_get_image_path_func(mmi_phb_main_list_thumbnail_get_image_path_callback);
    wgui_thumbnail_register_set_displayable_func(mmi_phb_main_list_thumbnail_set_displayable);
    wgui_thumbnail_register_get_displayable_func(mmi_phb_main_list_thumbnail_get_displayable);
    wgui_thumbnail_register_get_image_info_func(mmi_phb_main_list_thumbnail_get_menuitem_info);
    wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index_ext);
    left_icon_id = IMG_ID_PHB_LIST_PHOTO;
#endif

    ShowCategory199Screen_ext(
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        0,        
        (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
        NULL,
        contact_count,
        mmi_phb_quick_search_list_get_item,
        mmi_phb_quick_search_list_get_hint,
        NULL,
        NULL,
        g_mmi_phb_list_p->list_index,
        get_image(left_icon_id),
        get_image(IMG_STORAGE_SIM),
        (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);

        if(need_to_reflesh)
        {
            need_to_reflesh=KAL_FALSE;
            mmi_phb_quick_search_find_entry_tab((U8 *) g_mmi_phb_list_p->qsearch_input_buffer);
        }


#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

    SetCategory200RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    SetCategory200LeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);

    SetCenterSoftkeyFunction(mmi_phb_quick_search_center_key_handlr, KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_contact_list_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}


#ifndef __MMI_PHB_UI_IN_TABS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_quick_search_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_exit_quick_search_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(KEYPAD_LOCK_TIMER);
#if 0
#if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
#endif 
#endif 

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_quick_search_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_quick_search_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 contact_count=0;
    srv_phb_filter_struct * filter;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data = NULL;
#ifdef __MMI_ICON_BAR_SUPPORT__
    S32 item_count = MMI_PHB_TOOLBAR_ENUM_TOTAL;
    PU8 item_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL];
    PU8 item_disable_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL];
    PU8 string[MMI_PHB_TOOLBAR_ENUM_TOTAL];
#endif /* __MMI_ICON_BAR_SUPPORT__ */
    U16 left_icon_id = IMG_GLOBAL_L1;
    kal_bool need_to_reflesh=MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_PHB_MAIN,
            SCR_ID_PHB_QUICK_SEARCH_LIST,
            mmi_phb_exit_quick_search_list,
            mmi_phb_launch_entry,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    RegisterHighlightHandler(mmi_phb_quick_search_get_index);
    RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry);

    g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_MAIN;

    /* refresh prefer storage */
	#ifndef __MMI_PHB_SLIM_NEW__
    if (g_mmi_phb_list_p->storage != mmi_phb_get_preferred_storage() ||
        g_mmi_phb_list_p->display_type != srv_phb_get_name_display_type())
    {
        g_mmi_phb_list_p->storage = (U8) mmi_phb_get_preferred_storage();
        g_mmi_phb_list_p->display_type = (U8) srv_phb_get_name_display_type();
        gui_buffer = NULL;
        g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
    }
	#else
    if (g_mmi_phb_list_p->storage != srv_phb_get_storage_mask() ||
        g_mmi_phb_list_p->display_type != srv_phb_get_name_display_type())
    {
        g_mmi_phb_list_p->storage = (U8) srv_phb_get_storage_mask();
        g_mmi_phb_list_p->display_type = (U8) srv_phb_get_name_display_type();
        gui_buffer = NULL;
		g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
    }
	#endif
    
    if (gui_buffer == NULL)
    {
        filter = mmi_phb_list_build_filter(
                     PHB_STORAGE_MAX,
                     g_mmi_phb_list_p->filter,
                     NULL,
                     NULL,
                     0);
        
        contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
        g_mmi_phb_list_p->contact_count = contact_count;
        
        mmi_phb_list_free_filter(filter);
#ifndef __MMI_MAINLCD_96X64__        
        if (contact_count == 0)
        {
            g_mmi_phb_list_p->list_index = 0;        
        }
        else
        {
            g_mmi_phb_list_p->list_index = 1;
        }

        contact_count++;
#else
    g_mmi_phb_list_p->list_index = 0;
    if (contact_count == 0)
    {
        contact_count++;       
    }       
#endif

    }
    else
    {
        if (!mmi_is_redrawing_bk_screens())
        {
            handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
            refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);
        }
        if (!mmi_is_redrawing_bk_screens() &&  refresh_data != NULL )
        {
            gui_buffer = NULL;

            filter = mmi_phb_list_build_filter(
                         PHB_STORAGE_MAX,
                         g_mmi_phb_list_p->filter,
                         &g_mmi_phb_list_p->group_filter,
                         NULL,
                         0);
            
            contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
            g_mmi_phb_list_p->contact_count = contact_count;
            
            mmi_phb_list_free_filter(filter);

            if (contact_count == 0)
            {
                g_mmi_phb_list_p->list_index = 0;
                #ifdef __MMI_MAINLCD_96X64__ 
                contact_count++;
                #endif
            }
            else
            {
                g_mmi_phb_list_p->list_index = mmi_phb_calc_list_index(
                                                refresh_data,
                                                MMI_PHB_LIST_TYPE_SINGLE_SELECT,
                                                g_mmi_phb_list_p->list_index,
                                                g_mmi_phb_list_p->contact_array,
                                                NULL,
                                                g_mmi_phb_list_p->contact_count);
#ifndef __MMI_MAINLCD_96X64__
                g_mmi_phb_list_p->list_index++;
#endif
            }
#ifndef __MMI_MAINLCD_96X64__
            contact_count++;
#endif
            g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
            
            refresh_data->refresh_type = MMI_PHB_OP_NONE;
        }
        else
        {
            need_to_reflesh=MMI_TRUE;
        }
    }

    
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    set_force_icon_on_highlight_only_in_menuitem();
#endif

    mmi_imc_disable_csk();
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    wgui_fixed_list_register_get_flags_handler(mmi_phb_quick_search_list_seperate_line);
    /* when refresh the list, then set the default highlight item to index = 1 */
    wgui_cat200_set_specific_highlight();

#ifdef __MMI_ICON_BAR_SUPPORT__
    item_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL);
    item_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
    item_icon[MMI_PHB_EDIT] = get_image(IMG_GLOBAL_TOOLBAR_EDIT);
    item_disable_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
    item_disable_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
    item_disable_icon[MMI_PHB_EDIT] = get_image(IMG_GLOBAL_TOOLBAR_EDIT_DISABLED);
    string[MMI_PHB_VOICE_CALL] = (PU8)get_string(STR_GLOBAL_DIAL);
    string[MMI_PHB_SEND_MSG] = (PU8)get_string(STR_GLOBAL_SEND);
    string[MMI_PHB_EDIT] = (PU8)get_string(STR_GLOBAL_EDIT);

//#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#if defined(__MMI_VIDEO_TELEPHONY__)
    item_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_VIDEO_CALL);
    item_disable_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_VIDEO_CALL_DISABLED);
    string[MMI_PHB_VIDEO_CALL] = (PU8)get_string(STR_GLOBAL_DIAL_VIDEO_CALL);
#endif
    wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, string, (GUIIconbarItemCallback)mmi_phb_fte_contact_list_callback);
#endif /* __MMI_ICON_BAR_SUPPORT__ */

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
    mmi_phb_thumbnail_reset_displayable();
    wgui_thumbnail_register_get_image_path_func(mmi_phb_main_list_thumbnail_get_image_path_callback);
    wgui_thumbnail_register_set_displayable_func(mmi_phb_main_list_thumbnail_set_displayable);
    wgui_thumbnail_register_get_displayable_func(mmi_phb_main_list_thumbnail_get_displayable);
    wgui_thumbnail_register_get_image_info_func(mmi_phb_main_list_thumbnail_get_menuitem_info);
    wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index_ext);
    left_icon_id = IMG_ID_PHB_LIST_PHOTO;
#endif

#ifndef __MMI_MAINLCD_96X64__
#if !defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)

    ShowCategory200Screen_ext(
       (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),

        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        contact_count,
        mmi_phb_quick_search_list_get_item,
        mmi_phb_quick_search_list_get_hint,
        g_mmi_phb_list_p->list_index,
        IMG_ID_PHB_QUICK_SEARCH_FIND,
        get_image(left_icon_id),
        get_image(IMG_STORAGE_SIM),
        (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);
  #else
  ShowCategory200Screen_ext(
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        contact_count,
        mmi_phb_quick_search_list_get_item,
        mmi_phb_quick_search_list_get_hint,
        g_mmi_phb_list_p->list_index,
        IMG_ID_PHB_QUICK_SEARCH_FIND,
        get_image(left_icon_id),
        get_image(IMG_STORAGE_SIM),
        (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);
  #endif
#else
#if !defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)

      ShowCategory200Screen_ext(
       (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        contact_count,
        mmi_phb_quick_search_list_get_item,
        mmi_phb_quick_search_list_get_hint,
        g_mmi_phb_list_p->list_index,
        IMG_GLOBAL_COMMON_CSK,
        get_image(IMG_STORAGE_SIM),
        get_image(IMG_STORAGE_SIM),
        (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);
#else
        ShowCategory200Screen_ext(         
          STR_SCR_PBOOK_VIEW_CAPTION,
          IMG_SCR_PBOOK_CAPTION,
          STR_GLOBAL_OPTIONS,
          IMG_GLOBAL_OPTIONS,
          STR_GLOBAL_BACK,
          IMG_GLOBAL_BACK,
          contact_count,
          mmi_phb_quick_search_list_get_item,
          mmi_phb_quick_search_list_get_hint,
          g_mmi_phb_list_p->list_index,
          IMG_GLOBAL_COMMON_CSK,
          get_image(IMG_STORAGE_SIM),
          get_image(IMG_STORAGE_SIM),
          (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
          MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
          gui_buffer);
#endif


#endif

    if(need_to_reflesh)
    {
            need_to_reflesh=KAL_FALSE;
            mmi_phb_quick_search_find_entry((U8 *) g_mmi_phb_list_p->qsearch_input_buffer);
    }

    SetCategory200RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    SetCategory200LeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    
    SetCenterSoftkeyFunction(mmi_phb_quick_search_center_key_handlr, KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_contact_list_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_main_menu();
}

#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */


#define MMI_PHB_MULTI_SELECT

#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__) || defined(__MMI_PHB_MULTI_OPERATION__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bitmask_set_state
 * DESCRIPTION
 *  set a bit of bit_mask
 * PARAMETERS
 *  bit_mask      [IN]
 *  index         [IN]
 *  status        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_bitmask_set_state(U8* bit_mask, U16 store_index, MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status)
    {
        bit_mask[store_index >> BYTE_SIZE_SHIFT_ARITHMETIC] |= 1 << (store_index % BYTE_SIZE);
    }
    else
    {
        bit_mask[store_index >> BYTE_SIZE_SHIFT_ARITHMETIC] &= (kal_uint8)(~(1 << (store_index % BYTE_SIZE)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bitmask_get_state
 * DESCRIPTION
 *  get a bit state of bitmask
 * PARAMETERS
 *  bit_mask      [IN]
 *  index         [IN]
 * RETURNS
 *  0 is false, else is true
 *****************************************************************************/
U8 mmi_phb_bitmask_get_state(U8* bit_mask, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bit_mask[store_index >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (store_index % BYTE_SIZE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bitmask_change_state
 * DESCRIPTION
 *  change a bit of bit_mask
 * PARAMETERS
 *  bit_mask      [IN]
 *  index         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_bitmask_change_state(U8* bit_mask, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bit_mask[store_index >> BYTE_SIZE_SHIFT_ARITHMETIC] ^= (kal_uint8)(1 << (store_index % BYTE_SIZE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_count
 * DESCRIPTION
 *  caculate phonebook list multi select count
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_phb_mark_several_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 mark_count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_ENTRIES; i++)
    {
        if (mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, i))
        {
            mark_count++;
        }
    }

    return mark_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_set_state
 * DESCRIPTION
 *  set check box state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_phb_mark_several_set_state(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U16 mark_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_list_p->contact_count == 0)
    {
        return MMI_FALSE;
    }
    
    mmi_phb_bitmask_change_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[item_index]);

    if (mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[item_index]))
    {
        mark_count = mmi_phb_mark_several_count();
        
        if (mark_count > g_mmi_phb_list_p->select_count)
        {
            mmi_phb_bitmask_change_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[item_index]);
            mmi_popup_display_simple_ext(
                STR_ID_PHB_MULTI_OP_MAX_ITEM_REACH,
                MMI_EVENT_FAILURE,
                g_mmi_phb_list_p->sg_id,
                NULL);

            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_get_state
 * DESCRIPTION
 *  get check box state
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_phb_mark_several_get_state(S32 item_index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *checkbox_image = (mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[item_index])) ?
                      (PU8)GetImage(CHECKBOX_ON_IMAGE_ID) :
                      (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID) ;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_multi_select_check
 * DESCRIPTION
 *  set check box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_mark_several_set_state(g_mmi_phb_list_p->list_index) == MMI_TRUE)
    {
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_populate
 * DESCRIPTION
 *  caculate phonebook list multi select count
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_phb_mark_several_populate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 mark_count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < MMI_PHB_ENTRIES; i++)
    {
        if (mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, i))
        {
            /* i = store_index */
            g_mmi_phb_list_p->mark_array[mark_count++] = i;
        }
    }

    g_mmi_phb_list_p->mark_count = mark_count;
    
    return mark_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_star_key_pre_handler
 * DESCRIPTION
 *  register pre handler of '*' to inputmethod
 * PARAMETERS
 *  key_code
 *  key_type
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_star_key_pre_handler(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_code == KEY_STAR)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_mark_serveral_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_exit_mark_serveral_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */

#if defined(__MMI_PHB_QUICK_SEARCH__)
    mmi_imc_key_set_pre_key_handler(NULL);
#endif
	
#ifndef __MMI_MAINLCD_96X64__
    is_from_group_mark_several=MMI_FALSE;
	is_not_from_mark_several_main=MMI_FALSE;
#endif

}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_contact_list_tap_callback
 * DESCRIPTION
 *  fte contact main list tap callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_mark_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_mark_several_check();
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_highlight_hdlr
 * DESCRIPTION
 *  Highlight Handler for multi select
 * PARAMETERS
 *  item_index                   [IN]            highlight item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_mark_several_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_list_p->list_index = (U16) item_index;
    g_mmi_phb_list_p->store_index = g_mmi_phb_list_p->contact_array[item_index];

    ChangeCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_start();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_search_count
 * DESCRIPTION
 *  return mark count
 * PARAMETERS
 *  void
 * RETURNS
 *  mark_count
 *****************************************************************************/
U16 mmi_phb_mark_several_search_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for(index = 0; index < g_mmi_phb_list_p->contact_count; index++)
    {
        if (mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[index]))
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_mark_unmark
 * DESCRIPTION
 *  mark or unmark a entry in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_mark_several_mark_unmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_phb_mark_several_check();

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_unmark_all
 * DESCRIPTION
 *  Unmark All entry in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_mark_several_unmark_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for(index = 0; index < g_mmi_phb_list_p->contact_count; index++)
    {
        if (mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[index]))
        {
            mmi_phb_bitmask_set_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[index], MMI_FALSE);
        }            
    }
    
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_mark_all
 * DESCRIPTION
 *  mark All entry in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_mark_several_mark_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for(index = 0; index < g_mmi_phb_list_p->contact_count; index++)
    {
        if (!mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[index]))
        {
            mmi_phb_bitmask_set_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->contact_array[index], MMI_TRUE);
        }            
    }
    
    mmi_frm_scrn_close_active_id();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_continue_send_multi_message_confirm
 * DESCRIPTION
 *  confirm mark several copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_continue_send_multi_message_confirm(U16 max_count, MenucuiPtr lsk_ptr, MenucuiPtr rsk_ptr, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 outBuf[50];
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (max_count > 1)
    {
        kal_wsprintf(
            outBuf, 
            "%w %d %w",
            GetString(STR_ID_PHB_SEND_MULTI_MESSAGE_QUERY_1),
            max_count,
            GetString(STR_ID_PHB_SEND_MULTI_MESSAGE_QUERY_2));
    }
    else
    {
        kal_wsprintf(
            outBuf, 
            "%w %d %w",
            GetString(STR_ID_PHB_SEND_MULTI_MESSAGE_QUERY_1),
            max_count,
            GetString(STR_ID_PHB_SEND_MULTI_MESSAGE_QUERY_3));
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = group_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;

    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = group_id;
    g_mmi_phb_confirm_user_data.LSK_function = lsk_ptr;
    g_mmi_phb_confirm_user_data.RSK_function = rsk_ptr;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

    mmi_confirm_display(
        (WCHAR *) outBuf,
        MMI_EVENT_QUERY,
        &arg);
}


#if defined(__MMI_PHB_MULTI_OPERATION__)

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_main_build_option
 * DESCRIPTION
 *  build mark several main option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_main_build_option(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_list_p->mark_count > 0)
    {
    #ifdef __MMI_UNIFIED_COMPOSER__
        if (mmi_uc_is_uc_ready() && g_mmi_phb_mark_several_type == MMI_PHB_MARK_SEVERAL_PRE_SEND_MESSAGE)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_SEND_MESSAGE, MMI_FALSE);
        }
    #else
        if (g_mmi_phb_mark_several_type == MMI_PHB_MARK_SEVERAL_PRE_SEND_SMS)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_SEND_SMS, MMI_FALSE);
        }
    #if defined(__MMI_MMS__) &&  defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
        if (mms_is_ready() && g_mmi_phb_mark_several_type == MMI_PHB_MARK_SEVERAL_PRE_SEND_MMS)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_SEND_MMS, MMI_FALSE);
        }
    #endif /* defined(OBIGO_Q03C_MMS_V02) &&  defined(__MMI_MMS__) */
    #endif /* __MMI_UNIFIED_COMPOSER__ */
        if (g_mmi_phb_mark_several_type == MMI_PHB_MARK_SEVERAL_PRE_DELETE_SELECTED)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_DELETE_SELECTED, MMI_FALSE);
        }
    #ifdef __MMI_UDX_VCARD_SUPPORT__
        if (g_mmi_phb_mark_several_type == MMI_PHB_MARK_SEVERAL_PRE_BUILD_UDX)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_BUILD_UDX, MMI_FALSE);
        }
    #endif
    #if defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__)
        if (mmi_bt_is_to_display_bt_menu() && g_mmi_phb_mark_several_type == MMI_PHB_MARK_SEVERAL_PRE_SEND_VCARD)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_SEND_VCARD, MMI_FALSE);
        }
    #endif /* defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__) */
    #if defined(__MMI_MULTI_VCARD__)
        if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)) && 
            g_mmi_phb_mark_several_type == MMI_PHB_MARK_SEVERAL_PRE_BACKUP)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_BACKUP, MMI_FALSE);
        }
    #endif /* defined(__MMI_MULTI_VCARD__) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_copy_build_option
 * DESCRIPTION
 *  build mark several copy option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_copy_build_option(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_phb_list_p->mark_count > 0)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_COPY_SELECTED, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_move_build_option
 * DESCRIPTION
 *  build mark several move option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_move_build_option(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_phb_list_p->mark_count > 0)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_MOVE_SELECTED, MMI_FALSE);
    }
}

#define MARK_SEVERAL_OPTION


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_send_message_go_back_histoty
 * DESCRIPTION
 *  Go back screen after change input method.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_message_go_back_histoty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_PHB_MARK_SEVERAL, SCR_ID_PHB_MULTI_OP_OPTION);
    mmi_frm_scrn_close_active_id();
}


void mmi_phb_mark_several_send_message_go_back_histoty_ext(MMI_ID group_id)
{
    mmi_phb_mark_several_send_message_go_back_histoty();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_get_address_callback
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8* mmi_phb_mark_several_get_address_callback(U16 index, U16* type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_phb_list_p->mark_field[index])
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case (U8)SRV_PHB_ENTRY_FIELD_EMAIL1:
            *type = MMI_PHB_ADDRESS_TYPE_EMAIL;
            srv_phb_get_email_address(
                g_mmi_phb_list_p->mark_array[index],
                g_mmi_phb_temp_buffer,
                MMI_PHB_EMAIL_LENGTH);
            return (U8*)g_mmi_phb_temp_buffer;
            
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) 
        case (U8)SRV_PHB_ENTRY_FIELD_EMAIL2:
            *type = MMI_PHB_ADDRESS_TYPE_EMAIL;
            srv_phb_get_email_address2(
                g_mmi_phb_list_p->mark_array[index],
                g_mmi_phb_temp_buffer,
                MMI_PHB_EMAIL_LENGTH);
            return (U8*)g_mmi_phb_temp_buffer;
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    #endif
        case (U8)SRV_PHB_ENTRY_FIELD_NUMBER:
            num_index = 0;
            break;
            
        case (U8)SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            num_index = 1;
            break;
            
        case (U8)SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            num_index = 2;
            break;
            
        case (U8)SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            num_index = 3;
            break;
            
        default:
            break;
    }

    *type = MMI_PHB_ADDRESS_TYPE_NUMBER;
    srv_phb_get_number_ex(
        g_mmi_phb_list_p->mark_array[index],
        num_index,
        g_mmi_phb_temp_buffer,
        NULL,
        MMI_PHB_NUMBER_PLUS_LENGTH);
    return (U8*)g_mmi_phb_temp_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_filter_for_send_message
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_phb_mark_several_filter_for_send_message(U16 max_count, U16 filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, store_index;
    U16 end;
    U16 tmp;
    U32 contact_filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    end = g_mmi_phb_list_p->mark_count;
    for (i = 0; i < end;)
    {
        if (i >= max_count)
        {
            g_mmi_phb_op_cntx.total_count = max_count;
            return MMI_TRUE;
        }
        store_index = g_mmi_phb_list_p->mark_array[i];
        srv_phb_get_field(store_index, &contact_filter);
        
        if (!(contact_filter & srv_phb_convert_field_filter(filter)))
        {
            end--;
            tmp = g_mmi_phb_list_p->mark_array[i];
            g_mmi_phb_list_p->mark_array[i] = g_mmi_phb_list_p->mark_array[end];
            g_mmi_phb_list_p->mark_array[end] = tmp;
        }
        else
        {
            i++;
        }
    }
    
    g_mmi_phb_op_cntx.total_count = end;
    return MMI_FALSE;
}


#ifdef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_send_mms_choose_address_more
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_uc_choose_address_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_list_p->mark_field[g_mmi_phb_op_cntx.active_index++] = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];
    mmi_frm_display_dummy_screen();
    mmi_frm_scrn_close(GRP_ID_PHB_MARK_SEVERAL, SCR_CHOOSE_NUMBER);

    if (g_mmi_phb_op_cntx.active_index < g_mmi_phb_op_cntx.total_count)
    {
        mmi_phb_entry_mark_several_send_uc_choose_address();
    }
    else
    {
        mmi_phb_entry_mark_several_send_uc();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_send_mms_choose_address
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_send_uc_choose_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        g_mmi_phb_list_p->sg_id,
        g_mmi_phb_list_p->mark_array[g_mmi_phb_op_cntx.active_index],
        SRV_PHB_ENTRY_FIELD_MMS,
        mmi_phb_entry_mark_several_send_uc_choose_address,
        mmi_phb_mark_several_send_uc_choose_address_more,
        mmi_phb_mark_several_send_message_go_back_histoty,
        NULL,
        MMI_FALSE,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_send_mms
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_uc_choose_address(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_op_cntx.total_count)
    {
        g_mmi_phb_op_cntx.active_index = 0;
        mmi_phb_entry_mark_several_send_uc_choose_address();
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);

        mmi_frm_group_close(GRP_ID_PHB_MARK_SEVERAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_send_message
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_send_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_entry_write_struct data = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.addr_num = (U8)g_mmi_phb_op_cntx.total_count;
    data.get_address_callback = (uc_func_ptr_general_insert_get_addr_fn)mmi_phb_mark_several_get_address_callback;
    data.addr = NULL;
    data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;
    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);

    mmi_frm_group_close(GRP_ID_PHB_MARK_SEVERAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_mark_several_send_uc
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_pre_entry_mark_several_send_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsMessagesReEntering())
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);

        mmi_frm_group_close(GRP_ID_PHB_MARK_SEVERAL);
    }
    else 
    {
        max_count = wap_custom_get_max_mms_address();
        if (mmi_phb_mark_several_filter_for_send_message(max_count, SRV_PHB_ENTRY_FIELD_MMS))
        {
            mmi_phb_continue_send_multi_message_confirm(
                max_count,
                mmi_phb_mark_several_send_uc_choose_address,
                mmi_phb_mark_several_send_message_go_back_histoty_ext,
                GRP_ID_PHB_MARK_SEVERAL);
        }
        else
        {
            mmi_phb_mark_several_send_uc_choose_address(GRP_ID_PHB_MARK_SEVERAL);
        }
    }
}


#else /*__MMI_UNIFIED_COMPOSER__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_send_sms
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_send_sms(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_op_cntx.total_count)
    {
        mmi_sms_entry_write_msg_from_phb(
            g_mmi_phb_op_cntx.total_count,
            (void*)mmi_phb_mark_several_get_address_callback);
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
    }

    mmi_frm_group_close(GRP_ID_PHB_MARK_SEVERAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_send_mms_choose_address_more
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_sms_choose_address_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_list_p->mark_field[g_mmi_phb_op_cntx.active_index++] = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];
    mmi_frm_display_dummy_screen();
    mmi_frm_scrn_close(GRP_ID_PHB_MARK_SEVERAL, SCR_CHOOSE_NUMBER);

    if (g_mmi_phb_op_cntx.active_index < g_mmi_phb_op_cntx.total_count)
    {
        mmi_phb_entry_mark_several_send_sms_choose_address();
    }
    else
    {
        mmi_phb_entry_mark_several_send_sms(GRP_ID_PHB_MARK_SEVERAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_send_mms_choose_address
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_send_sms_choose_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        g_mmi_phb_list_p->sg_id,
        g_mmi_phb_list_p->mark_array[g_mmi_phb_op_cntx.active_index],
        SRV_PHB_ENTRY_FIELD_GSM_NUM,
        mmi_phb_entry_mark_several_send_sms_choose_address,
        mmi_phb_mark_several_send_sms_choose_address_more,
        mmi_phb_mark_several_send_message_go_back_histoty,
        NULL,
        MMI_FALSE,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_send_mms
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_sms_choose_address(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_op_cntx.total_count)
    {
        g_mmi_phb_op_cntx.active_index = 0;
        mmi_phb_entry_mark_several_send_sms_choose_address();
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
        
        mmi_frm_group_close(GRP_ID_PHB_MARK_SEVERAL);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_mark_several_send_sms
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_pre_entry_mark_several_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_count;
    mmi_id sg_id = GRP_ID_PHB_MARK_SEVERAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_is_reenter_message())
    {
        mmi_frm_scrn_close(sg_id, SCR_ID_PHB_MULTI_OP_PHB_LIST);
        return;
    }

    max_count = mmi_sms_get_max_recipient_num();
    if (mmi_phb_mark_several_filter_for_send_message(max_count, SRV_PHB_ENTRY_FIELD_GSM_NUM))
    {
        mmi_phb_continue_send_multi_message_confirm(
            max_count,
            mmi_phb_entry_mark_several_send_sms,
            mmi_phb_mark_several_send_message_go_back_histoty_ext,
            GRP_ID_PHB_MARK_SEVERAL);
    }
    else
    {
        mmi_phb_mark_several_send_sms_choose_address(GRP_ID_PHB_MARK_SEVERAL);
    }
}


#if defined(__MMI_MMS__) &&  defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_send_mms_rsp
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_mms_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_rsp_struct *local_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_buffer = (mms_multi_object_insert_rsp_struct *)info;
    if (local_buffer->result && g_mmi_phb_op_cntx.active_index < g_mmi_phb_op_cntx.total_count)
    {
        mmi_phb_mark_several_send_mms_insert_more_ind(local_buffer->request_id);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_PHB_MARK_SEVERAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_send_mms_req
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_mms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_req_struct *local_buffer;
    peer_buff_struct *peer_buffer;
    U16 start_index, end_index;
    U8 *peer_pdu;
    U16 peer_pdu_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_buffer = (mms_multi_object_insert_req_struct*) OslConstructDataPtr(sizeof(mms_multi_object_insert_req_struct));

    local_buffer->request_id = mma_get_request_id();
    start_index = 0;
    end_index = start_index +  MAX_MMS_OBJECT;
    if (end_index  < g_mmi_phb_op_cntx.total_count)
    {
        local_buffer->more = MMI_TRUE;
    }
    else
    {
        local_buffer->more = MMI_FALSE;
        end_index = g_mmi_phb_op_cntx.total_count;
    }
    local_buffer->num_of_object = end_index - start_index;
    g_mmi_phb_op_cntx.active_index = end_index;

    peer_pdu_len = local_buffer->num_of_object * sizeof(mms_multi_object_struct);
    peer_buffer = construct_peer_buff(peer_pdu_len, 0, 0, TD_CTRL);
    peer_pdu = (U8*) get_peer_buff_pdu(peer_buffer, &peer_pdu_len);

    mmi_phb_mark_several_send_mms_prepare_buffer(
            start_index,
            end_index,
            peer_pdu);

    SetProtocolEventHandler(mmi_phb_mark_several_send_mms_rsp, MSG_ID_MMS_MULTI_OBJECT_INSERT_RSP);
    mmi_frm_send_ilm(
        mms_get_service_module(MSG_ID_MMS_MULTI_OBJECT_INSERT_REQ),
        MSG_ID_MMS_MULTI_OBJECT_INSERT_REQ,
        (oslParaType*)local_buffer,
        (peer_buff_struct*)peer_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_send_mms_insert_more_ind
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_mms_insert_more_ind(U32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_continue_ind_struct *local_buffer;
    peer_buff_struct *peer_buffer;
    U16 start_index, end_index;
    U8 *peer_pdu;
    U16 peer_pdu_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_buffer = (mms_multi_object_insert_continue_ind_struct*) OslConstructDataPtr(sizeof(mms_multi_object_insert_continue_ind_struct));

    local_buffer->request_id = req_id;
    local_buffer->is_aborted = MMI_FALSE;
    
    start_index = g_mmi_phb_op_cntx.active_index;
    end_index = start_index +  MAX_MMS_OBJECT;
    if (end_index  < g_mmi_phb_op_cntx.total_count)
    {
        local_buffer->more = MMI_TRUE;
    }
    else
    {
        local_buffer->more = MMI_FALSE;
        end_index = g_mmi_phb_op_cntx.total_count;
    }
    local_buffer->num_of_object = end_index - start_index;
    g_mmi_phb_op_cntx.active_index = end_index;

    peer_pdu_len = local_buffer->num_of_object * sizeof(mms_multi_object_struct);
    peer_buffer = construct_peer_buff(peer_pdu_len, 0, 0, TD_CTRL);
    peer_pdu = (U8*) get_peer_buff_pdu(peer_buffer, &peer_pdu_len);

    mmi_phb_mark_several_send_mms_prepare_buffer(
            start_index,
            end_index,
            peer_pdu);
    
    SetProtocolEventHandler(mmi_phb_mark_several_send_mms_rsp, MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_RES);
    mmi_frm_send_ilm(
        mms_get_service_module(MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_IND),
        MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_IND,
        (oslParaType*) local_buffer,
        (peer_buff_struct*)peer_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_send_mms_pre_req
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_mark_several_send_mms_prepare_buffer(
        U16 start_index,
        U16 end_index,
        void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 j = 0;
    U8* ucs2_address;
    mms_multi_object_struct *peer_buffer;
    U16 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    peer_buffer = (mms_multi_object_struct*)buffer;
    for(i = start_index; i < end_index; i++)
    {
        ucs2_address = mmi_phb_mark_several_get_address_callback(i, &type);
        peer_buffer[j].type = (U32)type;
        mmi_ucs2_to_asc((CHAR*)(peer_buffer[j++].object), (CHAR*)ucs2_address);
    }
    return end_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_send_mms_choose_address_more
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_mms_choose_address_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_list_p->mark_field[g_mmi_phb_op_cntx.active_index++] = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];
    mmi_frm_display_dummy_screen();
    mmi_frm_scrn_close(GRP_ID_PHB_MARK_SEVERAL, SCR_CHOOSE_NUMBER);

    if (g_mmi_phb_op_cntx.active_index < g_mmi_phb_op_cntx.total_count)
    {
        mmi_phb_entry_mark_several_send_mms_choose_address();
    }
    else
    {
        mmi_phb_mark_several_send_mms_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_send_mms_choose_address
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_send_mms_choose_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        g_mmi_phb_list_p->sg_id,
        g_mmi_phb_list_p->mark_array[g_mmi_phb_op_cntx.active_index],
        SRV_PHB_ENTRY_FIELD_MMS,
        mmi_phb_entry_mark_several_send_mms_choose_address,
        mmi_phb_mark_several_send_mms_choose_address_more,
        mmi_phb_mark_several_send_message_go_back_histoty,
        NULL,
        MMI_FALSE,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_send_mms
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_send_mms_choose_address(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_op_cntx.total_count)
    {
        g_mmi_phb_op_cntx.active_index = 0;
        mmi_phb_entry_mark_several_send_mms_choose_address();
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
        
        mmi_frm_group_close(GRP_ID_PHB_MARK_SEVERAL);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_mark_several_send_mms
 * DESCRIPTION
 *  Highlight handler for "send message" in PHB -> mark several -> Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_pre_entry_mark_several_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsMessagesReEntering())
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);

        mmi_frm_group_close(GRP_ID_PHB_MARK_SEVERAL);
    }
    else
    {
        max_count = wap_custom_get_max_mms_address();
        if (mmi_phb_mark_several_filter_for_send_message(max_count, SRV_PHB_ENTRY_FIELD_MMS))
        {
            mmi_phb_continue_send_multi_message_confirm(
                max_count,
                mmi_phb_mark_several_send_mms_choose_address,
                mmi_phb_mark_several_send_message_go_back_histoty_ext,
                GRP_ID_PHB_MARK_SEVERAL);
        }
        else
        {
            mmi_phb_mark_several_send_mms_choose_address(GRP_ID_PHB_MARK_SEVERAL);
        }
    }
}
#endif /* defined(OBIGO_Q03C_MMS_V02) &&  defined(__MMI_MMS__) */
#endif /* __MMI_UNIFIED_COMPOSER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_move_pre_req
 * DESCRIPTION
 *  move several interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_mark_several_move_pre_req(MMI_ID group_id)
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
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_MULTI_MOVE;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_COPY_MULTI;
    g_mmi_phb_op_cntx.sg_id = group_id;

    mmi_frm_scrn_close(group_id, SCR_ID_PHB_MOVE_SEVERAL);

    mmi_phb_show_mass_processing(
        g_mmi_phb_op_cntx.sg_id,
        STR_GLOBAL_MOVING,
        g_mmi_phb_list_p->mark_count);
    
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_OP_MOVE_ALL_PRE_REQ, g_mmi_phb_op_cntx.dst_storage, g_mmi_phb_op_cntx.total_count);

    srv_phb_oplib_move_several_contact(
        g_mmi_phb_list_p->mark_array,
        g_mmi_phb_list_p->mark_count,
        g_mmi_phb_op_cntx.dst_storage,
        mmi_phb_op_mark_several_cb,
        &g_mmi_phb_op_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_move_coinfirm
 * DESCRIPTION
 *  confirm mark several move
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_mark_several_move_coinfirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.src_storage, MMI_PHB_CHECK_STORAGE_EMPTY, MMI_TRUE, group_id)
        || mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.dst_storage, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE, group_id))
    {
        return;
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = group_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;
        
    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = group_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_op_mark_several_move_pre_req;
        
    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;
        
    mmi_confirm_display(
        (WCHAR *) get_string(STR_ID_PHB_MULTI_OP_MOVE_SELECTED_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_copy_pre_req
 * DESCRIPTION
 *  copy several interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_mark_several_copy_pre_req(MMI_ID group_id)
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
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_MULTI_COPY;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_COPY_MULTI;
    g_mmi_phb_op_cntx.sg_id = group_id;

    mmi_phb_show_mass_processing(
        g_mmi_phb_op_cntx.sg_id,
        STR_GLOBAL_COPYING,
        g_mmi_phb_list_p->mark_count);
   
    srv_phb_oplib_copy_several_contact(
        g_mmi_phb_list_p->mark_array,
        g_mmi_phb_list_p->mark_count,
        g_mmi_phb_op_cntx.dst_storage,
        mmi_phb_op_mark_several_cb,
        &g_mmi_phb_op_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_copy_coinfirm
 * DESCRIPTION
 *  confirm mark several copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_mark_several_copy_coinfirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.src_storage, MMI_PHB_CHECK_STORAGE_EMPTY, MMI_TRUE, group_id)
        || mmi_phb_op_all_check_storage_status(g_mmi_phb_op_cntx.dst_storage, MMI_PHB_CHECK_STORAGE_FULL, MMI_TRUE, group_id))
    {
        return;
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = group_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;
        
    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = group_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_op_mark_several_copy_pre_req;
        
    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;
        
    mmi_confirm_display(
        (WCHAR *) get_string(STR_ID_PHB_MULTI_OP_COPY_SELECTED_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_delete_pre_req
 * DESCRIPTION
 *  delete several interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_mark_several_delete_pre_req(MMI_ID group_id)
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
    g_mmi_phb_op_cntx.action = MMI_PHB_OP_MULTI_DELETE;
    g_mmi_phb_op_cntx.state = MMI_PHB_STATE_DELETE_MULTI;
    g_mmi_phb_op_cntx.sg_id = group_id;

    mmi_phb_show_mass_processing(
        g_mmi_phb_op_cntx.sg_id,
        STR_GLOBAL_DELETING,
        g_mmi_phb_list_p->mark_count);
    
#ifdef __MMI_SNS_CONTACTS__
    srv_sns_phb_start_multi_op();
#endif

    srv_phb_oplib_delete_several_contact(
        g_mmi_phb_list_p->mark_array,
        g_mmi_phb_list_p->mark_count,
        mmi_phb_op_mark_several_cb,
        &g_mmi_phb_op_cntx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_mark_several_delete_coinfirm
 * DESCRIPTION
 *  confirm mark several delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_op_mark_several_delete_coinfirm(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                          */
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
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_op_mark_several_delete_pre_req;
        
    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;
        
    mmi_confirm_display(
        (WCHAR *) get_string(STR_ID_PHB_MULTI_OP_DELETE_SELECTED_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


mmi_ret mmi_phb_mark_several_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_MARK_ALL)
            {
                mmi_phb_op_mark_several_mark_all();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_UNMARK_ALL)
            {
                mmi_phb_op_mark_several_unmark_all();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_MARK)
            {
                mmi_phb_op_mark_several_mark_unmark();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_UNMARK)
            {
                mmi_phb_op_mark_several_mark_unmark();
            }
        #ifdef __MMI_UNIFIED_COMPOSER__
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_SEND_MESSAGE)
            {
                mmi_phb_pre_entry_mark_several_send_uc();
            }
        #else /* __MMI_UNIFIED_COMPOSER__ */
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_SEND_SMS)
            {
                mmi_phb_pre_entry_mark_several_send_sms();
            }
        #if defined(__MMI_MMS__) &&  defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_SEND_MMS)
            {
                mmi_phb_pre_entry_mark_several_send_mms();
            }
        #endif /* defined(OBIGO_Q03C_MMS_V02) &&  defined(__MMI_MMS__) */
        #endif /* __MMI_UNIFIED_COMPOSER__ */
        #ifdef __MMI_UDX_VCARD_SUPPORT__
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_BUILD_UDX)
            {
                mmi_phb_mark_several_op_build_udx_confirm(g_mmi_phb_list_p->sg_id);
            }
        #endif
        #if defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__)
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_SEND_VCARD)
            {
                mmi_phb_mark_several_op_send_vcard(g_mmi_phb_list_p->sg_id);
            }
        #endif /* defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__) */
        #if defined(__MMI_MULTI_VCARD__)
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_BACKUP)
            {
                mmi_phb_mark_several_op_backup(g_mmi_phb_list_p->sg_id);
            }
        #endif /* defined(__MMI_MULTI_VCARD__) */
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_DELETE_SELECTED)
            {
                mmi_phb_op_mark_several_delete_coinfirm(g_mmi_phb_list_p->sg_id);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_COPY_SELECTED)
            {
                mmi_phb_op_mark_several_copy_coinfirm(g_mmi_phb_list_p->sg_id);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_MARK_SEVERAL_OP_MOVE_SELECTED)
            {
                mmi_phb_op_mark_several_move_coinfirm(g_mmi_phb_list_p->sg_id);
            }
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
 *  mmi_phb_entry_mark_several_option
 * DESCRIPTION
 *  Entry mark several Options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_mark_several_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_mark_several_populate();

    menu_gid = cui_menu_create(
               GRP_ID_PHB_MARK_SEVERAL,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_OPTION,
               MENU_ID_PHB_MARK_SEVERAL_OP,
               MMI_FALSE, NULL);

    if (mmi_phb_bitmask_get_state(g_mmi_phb_list_p->bitmask, g_mmi_phb_list_p->store_index))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_MARK, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_UNMARK, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_MARK, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_UNMARK, MMI_TRUE);
    } 

    #ifdef __MMI_UNIFIED_COMPOSER__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_SEND_MESSAGE, MMI_TRUE);
    #else
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_SEND_SMS, MMI_TRUE);
    #if defined(__MMI_MMS__) &&  defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_SEND_MMS, MMI_TRUE);
    #endif /* defined(OBIGO_Q03C_MMS_V02) &&  defined(__MMI_MMS__) */
    #endif /* __MMI_UNIFIED_COMPOSER__ */

    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_DELETE_SELECTED, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_COPY_SELECTED, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_MOVE_SELECTED, MMI_TRUE);
#ifdef __MMI_UDX_VCARD_SUPPORT__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_BUILD_UDX, MMI_TRUE);
#endif
#if defined(__MMI_VCARD__) && defined(__MMI_OPP_SUPPORT__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_SEND_VCARD, MMI_TRUE);
#endif
#if defined(__MMI_MULTI_VCARD__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_BACKUP, MMI_TRUE);
#endif

    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_MARK_ALL, MMI_FALSE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_UNMARK_ALL, MMI_FALSE);
    
    if (mmi_phb_mark_several_search_count() == 0)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_UNMARK_ALL, MMI_TRUE);
    }
    else if (mmi_phb_mark_several_search_count() == g_mmi_phb_list_p->contact_count)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_MARK_SEVERAL_OP_MARK_ALL, MMI_TRUE);
    }

    g_mmi_phb_mark_several_build_op_func(menu_gid);

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_list
 * DESCRIPTION
 *  Entry fuction of mark several list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_list(
        U16 str_title,
        U16 img_title,
        U16 str_lsk,
        U16 img_lsk,
        U16 scr_id,
        FunctionPtr lsk_ptr,
        FunctionPtr csk_ptr,
        FunctionPtr entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 entry_count;
    srv_phb_filter_struct *filter;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data;
    U16 left_icon_id = IMG_GLOBAL_L1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

#ifndef __MMI_MAINLCD_96X64__	
	
 if(entry_ptr!=mmi_phb_entry_mark_several_main)
    {
    filter = mmi_phb_list_build_filter(
             g_mmi_phb_list_p->storage, 
             SRV_PHB_ENTRY_FIELD_ALL,
             NULL,
             NULL,
             0); 
	is_not_from_mark_several_main=MMI_TRUE;
    }
	else
	{
	filter = mmi_phb_list_build_filter(
             PHB_STORAGE_MAX, 
             SRV_PHB_ENTRY_FIELD_ALL,
             NULL,
             NULL,
             0);
	is_not_from_mark_several_main=MMI_FALSE;
	}
#else
    filter = mmi_phb_list_build_filter(
             PHB_STORAGE_MAX,
             SRV_PHB_ENTRY_FIELD_ALL,
             NULL,
             NULL,
             0);
#endif
   
    
    entry_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
    g_mmi_phb_list_p->contact_count = entry_count;
    
    mmi_phb_list_free_filter(filter);

    if (g_mmi_phb_list_p->contact_count == 0)
    {        
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_ENTRY_TO_SELECT,
            MMI_EVENT_FAILURE,
            g_mmi_phb_list_p->sg_id,
            NULL);

        return;
    }

    if (mmi_frm_scrn_enter(
            g_mmi_phb_list_p->sg_id,
            scr_id,
            mmi_phb_exit_mark_serveral_list,
            entry_ptr,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        
        RegisterHighlightHandler(mmi_phb_mark_several_highlight_hdlr);

    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_icon_on_highlight_only_in_menuitem();
    #endif

        EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

        if (!mmi_is_redrawing_bk_screens())
        {
            handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
            refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);

            if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
            {
                gui_buffer = NULL;
            #if defined(__MMI_PHB_QUICK_SEARCH__)
                g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
            #endif

                g_mmi_phb_list_p->list_index = mmi_phb_calc_list_index(
                                                refresh_data,
                                                MMI_PHB_LIST_TYPE_MULTI_SELECT,
                                                g_mmi_phb_list_p->list_index,
                                                g_mmi_phb_list_p->contact_array,
                                                g_mmi_phb_list_p->bitmask,
                                                g_mmi_phb_list_p->contact_count);
                
                refresh_data->refresh_type = MMI_PHB_OP_NONE;
            }
        }
    #if defined(__MMI_PHB_QUICK_SEARCH__)

        RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry);
        g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_GENERIC;
        
        if (gui_buffer != NULL)
        {
            entry_count = (U16) mmi_phb_quick_search_find_entry((U8 *) g_mmi_phb_list_p->qsearch_input_buffer);
        }

    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_generic_list_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_generic_list_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_generic_list_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_generic_list_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index);
        left_icon_id = IMG_ID_PHB_LIST_PHOTO;
    #endif

#ifndef __MMI_MAINLCD_96X64__

        ShowCategory202Screen_ext(
            str_title,
            img_title,
            str_lsk,
            img_lsk,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            NULL,
            entry_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            g_mmi_phb_list_p->list_index,
            IMG_ID_PHB_QUICK_SEARCH_FIND,
            get_image(left_icon_id),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);

       
		
   
#else
           ShowCategory202Screen_ext(
            str_title,
            img_title,
            str_lsk,
            img_lsk,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            NULL,
            entry_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            g_mmi_phb_list_p->list_index,
            IMG_GLOBAL_COMMON_CSK,
            get_image(IMG_STORAGE_SIM),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);
#endif

        SetLeftSoftkeyFunction(lsk_ptr, KEY_EVENT_UP);
        SetCategory200LeftSoftkeyFunction(lsk_ptr, KEY_EVENT_UP);
        SetCategory200RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
                
    #else

        wgui_cat1024_show(
            (WCHAR*) GetString(str_title),
            (PU8)GetImage(img_title),
            (WCHAR*) GetString(str_lsk),
            (PU8) GetImage(img_lsk),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            NULL,
            g_mmi_phb_list_p->contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            IMG_STORAGE_SIM,
            IMG_GLOBAL_SIM1,
            g_mmi_phb_list_p->list_index,
            gui_buffer);
    
        SetLeftSoftkeyFunction(lsk_ptr, KEY_EVENT_UP);
    #endif

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif

        SetCenterSoftkeyFunction(csk_ptr, KEY_EVENT_UP);

        mmi_imc_key_set_pre_key_handler(mmi_phb_star_key_pre_handler);

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_fte_mark_list_tap_callback);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mark_several_main
 * DESCRIPTION
 *  Entry fuction of mark several main
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_mark_several_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_mark_several_build_op_func = mmi_phb_mark_several_main_build_option;

    mmi_phb_entry_mark_several_list(
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        SCR_ID_PHB_MULTI_OP_PHB_LIST,
        mmi_phb_entry_mark_several_option,
        mmi_phb_mark_several_check,
        mmi_phb_entry_mark_several_main);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_mark_several_main
 * DESCRIPTION
 *  pre Entry fuction of mark several main
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_pre_entry_mark_several_main(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = group_id;
    mmi_id new_sg_id;
    U32 handle;    
    mmi_phb_list_cntx_struct *list_cntx;
    mmi_phb_list_cntx_struct *parent_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = mmi_phb_cntx_mgr_create_handle(MMI_PHB_SG_MARK_SEVERAL);
    new_sg_id = mmi_phb_cntx_mgr_get_sg_id(handle);
    mmi_phb_cntx_mgr_set_parent_id(handle, sg_id);
    list_cntx = cui_phb_list_select_contact_create_cntx(MMI_PHB_LIST_TYPE_MULTI_SELECT);
    
    list_cntx->sg_id = new_sg_id;
    list_cntx->parent_id = sg_id;

    if (sg_id == GRP_ID_PHB_MAIN)
    {
        parent_data = (mmi_phb_list_cntx_struct *) mmi_frm_group_get_user_data(sg_id);
        list_cntx->list_index = parent_data->list_index;
    }
    
    mmi_phb_cntx_mgr_set_data(handle, list_cntx);

    cui_phb_list_select_contact_set_cntx(list_cntx);

    mmi_frm_group_create_ex(
        sg_id,
        new_sg_id,
        cui_phb_list_select_contact_proc,
        list_cntx,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    g_mmi_phb_mark_several_entry_func();
}
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */


#define MMI_PHB_LIST_MULTI_SELECT
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_list
 * DESCRIPTION
 *  Entry fuction of mark several list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_mark_several_list(
        FunctionPtr lsk_ptr,
        FunctionPtr csk_ptr,
        FunctionPtr entry_ptr,
        U8 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 storage_mask;
    U16 entry_count;
    U32 handle;
    U32 i;
    mmi_phb_refresh_struct *refresh_data;
    srv_phb_contact_filter filter;
    srv_phb_query_req_struct req;
    srv_phb_query_handle query_handle;
    U32 field;
    U16 left_icon_id = IMG_GLOBAL_L1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
    #ifndef __MMI_MAINLCD_96X64__
    is_from_group_mark_several=MMI_TRUE;
    #endif
    
    filter = srv_phb_create_contact_filter();
    field = srv_phb_convert_field_filter(g_mmi_phb_list_p->filter);
    srv_phb_contact_filter_set_field(filter, field);
    if (g_mmi_phb_list_p->storage == PHB_STORAGE_MAX)
    {
        storage_mask = SRV_PHB_STORAGE_MASK_ALL;
    }
    else
    {
        storage_mask = 1 << g_mmi_phb_list_p->storage;
    }
    srv_phb_contact_filter_set_storage(filter, storage_mask);
#ifdef __MMI_PHB_CALLER_GROUP__
    srv_phb_contact_filter_set_group(filter, group_id, g_mmi_phb_list_p->group_filter.is_equal);
#endif
    req.filter = filter;
    req.align_field = MMI_PHB_CONTACT_FIELD_NAME;
    query_handle = srv_phb_query(&req, NULL);
    entry_count = (U16)srv_phb_query_get_count(query_handle);
    g_mmi_phb_list_p->contact_count = entry_count;
    for (i = 0; i < entry_count; i++)
    {
        g_mmi_phb_list_p->contact_array[i] = srv_phb_query_get_contact_id(query_handle, i);
    }
    srv_phb_free_contact_filter(filter);
    srv_phb_free_query_handle(query_handle);

    if (g_mmi_phb_list_p->contact_count == 0)
    {        
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_ENTRY_TO_SELECT,
            MMI_EVENT_FAILURE,
            g_mmi_phb_list_p->sg_id,
            NULL);

        return;
    }

    if (mmi_frm_scrn_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_MULTI_OP_PHB_LIST,
            mmi_phb_exit_mark_serveral_list,
            entry_ptr,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        
        RegisterHighlightHandler(mmi_phb_mark_several_highlight_hdlr);

    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_icon_on_highlight_only_in_menuitem();
    #endif

        EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

        if (!mmi_is_redrawing_bk_screens())
        {
            handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
            refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);

            if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
            {
                gui_buffer = NULL;
                g_mmi_phb_list_p->list_index = mmi_phb_calc_list_index(
                                                refresh_data,
                                                MMI_PHB_LIST_TYPE_MULTI_SELECT,
                                                g_mmi_phb_list_p->list_index,
                                                g_mmi_phb_list_p->contact_array,
                                                g_mmi_phb_list_p->bitmask,
                                                g_mmi_phb_list_p->contact_count);
                
                refresh_data->refresh_type = MMI_PHB_OP_NONE;
            }
        }

        
    #if defined(__MMI_PHB_QUICK_SEARCH__)        
        RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry);
        g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_GENERIC;
            
        if (gui_buffer != NULL)
        {
            entry_count = (U16) mmi_phb_quick_search_find_entry((U8 *) g_mmi_phb_list_p->qsearch_input_buffer);
        }
        
    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_generic_list_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_generic_list_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_generic_list_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_generic_list_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index);
        left_icon_id = IMG_ID_PHB_LIST_PHOTO;
    #endif
        
#ifndef __MMI_MAINLCD_96X64__
        ShowCategory202Screen_ext(
            STR_SCR_PBOOK_VIEW_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            NULL,
            entry_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            g_mmi_phb_list_p->list_index,
            IMG_ID_PHB_QUICK_SEARCH_FIND,
            get_image(left_icon_id),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);
	#else

          ShowCategory202Screen_ext(
            STR_SCR_PBOOK_VIEW_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            NULL,
            entry_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            g_mmi_phb_list_p->list_index,
            IMG_GLOBAL_COMMON_CSK,
            get_image(IMG_STORAGE_SIM),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);
	#endif
        
        SetLeftSoftkeyFunction(lsk_ptr, KEY_EVENT_UP);
        SetCategory200LeftSoftkeyFunction(lsk_ptr, KEY_EVENT_UP);
        SetCategory200RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
                    
    #else
        wgui_cat1024_show(
            (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8)GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            NULL,
            g_mmi_phb_list_p->contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            IMG_STORAGE_SIM,
            IMG_GLOBAL_SIM1,
            g_mmi_phb_list_p->list_index,
            gui_buffer);
    
        SetLeftSoftkeyFunction(lsk_ptr, KEY_EVENT_UP);
    #endif
        
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif
        SetCenterSoftkeyFunction(csk_ptr, KEY_EVENT_UP);
        mmi_imc_key_set_pre_key_handler(mmi_phb_star_key_pre_handler);
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_fte_mark_list_tap_callback);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_list_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_ASSERT(item_index < g_mmi_phb_list_p->contact_count);

    g_mmi_phb_list_p->list_index = (U16) item_index;
    g_mmi_phb_list_p->store_index = g_mmi_phb_list_p->contact_array[item_index];
    
    ChangeCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_start();
#endif
}


void mmi_phb_search_contact_pre_run(void)
{
    U16 entry_count;
    cui_phb_search_contact_result_struct evt;
    srv_phb_filter_struct filter;
    srv_phb_name_filter_struct name_filter;
    
    evt.evt_id = EVT_ID_PHB_SEARCH_CONTACT_PRE_RUN;
    evt.num_count = 0;
    evt.size = sizeof(cui_phb_search_contact_result_struct);
    evt.sender_id = g_mmi_phb_list_p->sg_id;

    // phonebook not ready, send cancel event to caller
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        evt.evt_id = EVT_ID_PHB_CONTACT_NOT_READY;
        evt.count = 0;
        // post the pre-run event to parent
        mmi_frm_group_post_to_parent(g_mmi_phb_list_p->sg_id, (mmi_group_event_struct *)&evt);
        
        return;
    }

    // search contact
    memset(&filter, 0, sizeof(srv_phb_filter_struct));
    filter.storage = g_mmi_phb_list_p->storage;
    filter.field_filter = g_mmi_phb_list_p->filter;
    filter.name_filter = &name_filter;
    name_filter.key_word = g_mmi_phb_list_p->qsearch_input_buffer;
    name_filter.key_len = mmi_wcslen(g_mmi_phb_list_p->qsearch_input_buffer);
    
    entry_count = (U16) srv_phb_oplib_build_contact_list(&filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
    g_mmi_phb_list_p->contact_count = entry_count;

    evt.count = entry_count;
    
    if (entry_count == 1)
    {
        // only have one contact, check if should show choose number screen
        U32 field;
        U8 field_count = 0;
        srv_phb_get_field(g_mmi_phb_list_p->contact_array[0], &field);
        
        // now, only check number field and email field
        if (g_mmi_phb_list_p->filter & field & MMI_PHB_CONTACT_FIELD_NUMBER)
        {
            field_count += srv_phb_get_num_count(g_mmi_phb_list_p->contact_array[0]);
            if (field_count == 1)
            {
                U32 i;
                U16 number[MMI_PHB_NUMBER_LENGTH + 1];
                U8 type;
                for(i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i ++)
                {
                    srv_phb_get_number_ex(
                        g_mmi_phb_list_p->contact_array[0],
                        i,
                        number,
                        &type,
                        MMI_PHB_NUMBER_LENGTH);
                    if (number[0] != 0)
                    {
                        break;
                    }
                }
                field = SRV_PHB_ENTRY_FIELD_NUMBER << i;
            }
        }
        if (g_mmi_phb_list_p->filter & field & MMI_PHB_CONTACT_FIELD_EMAIL)
        {
            field_count += srv_phb_get_email_count(g_mmi_phb_list_p->contact_array[0]);
        }

        evt.field_type = g_mmi_phb_list_p->filter & field; // Li, need modify
        evt.id = g_mmi_phb_list_p->contact_array[0];
        evt.num_count = field_count;
    }

    // post the pre-run event to parent
    mmi_frm_group_post_to_parent(g_mmi_phb_list_p->sg_id, (mmi_group_event_struct *)&evt);
}


static void mmi_phb_search_contact_choose_field(mmi_scrn_essential_struct* scrn_data);


void mmi_phb_search_contact_continue(MMI_ID group_id)
{
    if (mmi_frm_group_is_present(group_id))
    {
        mmi_phb_list_cntx_struct *list = (mmi_phb_list_cntx_struct*)mmi_frm_group_get_user_data(group_id);
        // handle next contact
        list->mark_index++;
        // avoid go back to pre-screen
        mmi_frm_display_dummy_screen();
        mmi_frm_scrn_close(list->sg_id, SCR_CHOOSE_NUMBER);

        mmi_frm_scrn_first_enter(
            list->sg_id,
            SCR_CHOOSE_NUMBER,
            (FuncPtr) mmi_phb_search_contact_choose_field,
            list);
    }
}


static void mmi_phb_search_contact_choose_select(void)
{
    cui_phb_search_contact_result_struct evt;

    // post the contact info to parent
    evt.evt_id = EVT_ID_PHB_SEARCH_CONTACT;
    evt.count = g_mmi_phb_list_p->mark_count - g_mmi_phb_list_p->mark_index - 1;
    evt.id = g_mmi_phb_list_p->mark_array[g_mmi_phb_list_p->mark_index];
    evt.num_count = 1;
    evt.field_type = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];
    evt.size = sizeof(cui_phb_search_contact_result_struct);
    evt.sender_id = g_mmi_phb_list_p->sg_id;

    mmi_frm_group_post_to_parent(g_mmi_phb_list_p->sg_id, (mmi_group_event_struct *)&evt);
}


static void mmi_phb_search_contact_choose_back(void)
{
    cui_phb_search_contact_result_struct evt;
    evt.evt_id = EVT_ID_PHB_SEARCH_CONTACT;
    evt.count = 0;
    evt.num_count = 0;
    evt.size = sizeof(cui_phb_search_contact_result_struct);
    evt.sender_id = g_mmi_phb_list_p->sg_id;
    g_mmi_phb_list_p->evt_out = MMI_TRUE;

    mmi_frm_group_post_to_parent(g_mmi_phb_list_p->sg_id, (mmi_group_event_struct *)&evt);
}


static void mmi_phb_search_contact_choose_field(mmi_scrn_essential_struct* scrn_data)
{
    mmi_phb_list_cntx_struct* list = (mmi_phb_list_cntx_struct *) scrn_data->user_data;

    mmi_phb_entry_choose_field(
        scrn_data->group_id,
        list->mark_array[list->mark_index],
        list->filter,
        (FunctionPtr) mmi_phb_search_contact_choose_field,
        mmi_phb_search_contact_choose_select,
        mmi_phb_search_contact_choose_back,
        NULL,
        MMI_FALSE,
        MMI_FALSE);
}


static void mmi_phb_search_contact_back(void)
{
    cui_phb_search_contact_result_struct evt;
    evt.evt_id = EVT_ID_PHB_SEARCH_CONTACT_CANCEL;
    evt.size = sizeof(cui_phb_search_contact_result_struct);
    evt.sender_id = g_mmi_phb_list_p->sg_id;

    g_mmi_phb_list_p->evt_out = MMI_TRUE;

    mmi_frm_group_post_to_parent(g_mmi_phb_list_p->sg_id, (mmi_group_event_struct *)&evt);
}


static void mmi_phb_search_contact_done(void)
{
    U16 mark_count;
    mark_count = mmi_phb_mark_several_populate();

    if (mark_count == 0)
    {
        g_mmi_phb_list_p->mark_array[0] = g_mmi_phb_list_p->contact_array[g_mmi_phb_list_p->list_index];
        g_mmi_phb_list_p->mark_count = 1;
    }

    {
        // show choose number screen
        g_mmi_phb_list_p->mark_index = 0;
        
        mmi_frm_scrn_first_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_CHOOSE_NUMBER,
            (FuncPtr) mmi_phb_search_contact_choose_field,
            g_mmi_phb_list_p);
    }
}



static void mmi_phb_search_contact_mark_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_QUICK_SEARCH__)
    mmi_imc_key_set_pre_key_handler(NULL);
#endif

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_contact_list_tap_callback
 * DESCRIPTION
 *  fte contact main list tap callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_mark_generic_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_mark_several_check();
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


static void mmi_phb_search_contact_mark()
{
    U8 *gui_buffer;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data;
    U16 left_icon_id = IMG_STORAGE_SIM;

    if (mmi_frm_scrn_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_GENERIC_MULTI_SELECT,
            mmi_phb_search_contact_mark_exit,
            mmi_phb_search_contact_run,
            MMI_FRM_FULL_SCRN))
    {            
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        RegisterHighlightHandler(mmi_phb_mark_several_list_highlight_handler);

        if (gui_buffer == NULL)
        {
            g_mmi_phb_list_p->list_index = 0;
        }
        else        
        {
            if (!mmi_is_redrawing_bk_screens())
            {
                handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
                refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);
                
                if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
                {
                    gui_buffer = NULL;
                    g_mmi_phb_list_p->list_index = 0;
                    
                    memset(g_mmi_phb_list_p->bitmask, 0, (MMI_PHB_ENTRIES + 7) / 8);

                    refresh_data->refresh_type = MMI_PHB_OP_NONE;
                }
            }
        }
        
    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_icon_on_highlight_only_in_menuitem();
    #endif

        EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_generic_list_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_generic_list_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_generic_list_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_generic_list_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index);
        left_icon_id = IMG_ID_PHB_LIST_PHOTO;
    
         wgui_cat1026_show(
            (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8)GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_ADD),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            NULL,
            g_mmi_phb_list_p->contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            left_icon_id,
            IMG_GLOBAL_SIM1,
            0,
            gui_buffer);

    #else
        wgui_cat1024_show(
            (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8)GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_ADD),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            NULL,
            g_mmi_phb_list_p->contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            left_icon_id,
            IMG_GLOBAL_SIM1,
            0,
            gui_buffer);
    #endif
    
        SetLeftSoftkeyFunction(mmi_phb_search_contact_done, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_phb_search_contact_back, KEY_EVENT_UP);
    
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif

        SetCenterSoftkeyFunction(mmi_phb_mark_several_check, KEY_EVENT_UP);
    
        mmi_imc_key_set_pre_key_handler(mmi_phb_star_key_pre_handler);

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_fte_mark_generic_list_tap_callback);
    #endif
    }
}


void mmi_phb_search_contact_run(void)
{
    U16 entry_count;
    srv_phb_filter_struct filter;
    srv_phb_name_filter_struct name_filter;
    
    // phonebook not ready, send cancel event to caller
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    // search contact
    memset(&filter, 0, sizeof(srv_phb_filter_struct));
    filter.storage = g_mmi_phb_list_p->storage;
    filter.field_filter = g_mmi_phb_list_p->filter;
    filter.name_filter = &name_filter;
    name_filter.key_word = g_mmi_phb_list_p->qsearch_input_buffer;
    name_filter.key_len = mmi_wcslen(g_mmi_phb_list_p->qsearch_input_buffer);
    
    entry_count = (U16) srv_phb_oplib_build_contact_list(&filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
    g_mmi_phb_list_p->contact_count = entry_count;

    // show multi select screen
    if (entry_count > 1)
    {
        mmi_phb_search_contact_mark();
    }
    else if (entry_count == 1)
    {
        // show choose number screen
        g_mmi_phb_list_p->mark_index = 0;
        g_mmi_phb_list_p->mark_array[0] = g_mmi_phb_list_p->contact_array[0];
        g_mmi_phb_list_p->mark_count = 1;
        
        mmi_frm_scrn_first_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_CHOOSE_NUMBER,
            (FuncPtr) mmi_phb_search_contact_choose_field,
            g_mmi_phb_list_p);        
    }
    else
    {
        // no contact searched, post cancel event to parent
        cui_phb_search_contact_result_struct evt;
        
        evt.evt_id = EVT_ID_PHB_SEARCH_CONTACT_CANCEL;
        evt.size = sizeof(cui_phb_search_contact_result_struct);
        evt.sender_id = g_mmi_phb_list_p->sg_id;

        g_mmi_phb_list_p->evt_out = MMI_TRUE;
        mmi_frm_group_post_to_parent(g_mmi_phb_list_p->sg_id, (mmi_group_event_struct *)&evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_for_msg_get_number
 * DESCRIPTION
 *  Get entry function of mark several list used for message (SMS, MMS...)
 * PARAMETERS
 *  dest            [IN]        Dest buffer
 *  max_dest_len    [IN]        Size of dest buffer in bytes
 *  PhbIndex        [IN]        Phb store index
 *  num_type        [IN]        Number type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_for_msg_get_number(U8 *dest, U8 max_dest_len, U16 PhbIndex, U8 num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (num_type)
    {
        case MMI_PHB_NUMBER_TYPE_NUMBER:
        case MMI_PHB_NUMBER_TYPE_HOME_NUMBER:
        case MMI_PHB_NUMBER_TYPE_OFFICE_NUMBER:
        case MMI_PHB_NUMBER_TYPE_FAX_NUMBER:
        {
            U16 number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
            srv_phb_get_number_ex(PhbIndex, num_type - MMI_PHB_NUMBER_TYPE_NUMBER, number, NULL, MMI_PHB_NUMBER_LENGTH + 1);
            mmi_phb_truncate_number_field_to_max_len((U16 *) dest, number, max_dest_len);
            break;
        }
        
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_NUMBER_TYPE_EMAIL_ADDRESS:
        {
            U16 email[MMI_PHB_EMAIL_LENGTH + 1];
            srv_phb_get_email_address(PhbIndex, email, MMI_PHB_EMAIL_LENGTH);
            mmi_ucs2ncpy((CHAR *) dest, (CHAR *) email, max_dest_len);
            break;
        }
    #endif
    
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_NUMBER_TYPE_EMAIL_ADDRESS_2:
        {
            U16 email[MMI_PHB_EMAIL_LENGTH + 1];
            srv_phb_get_email_address2(PhbIndex, email, MMI_PHB_EMAIL_LENGTH);
            mmi_ucs2ncpy((CHAR *) dest, (CHAR *) email, max_dest_len);
            break;
        }
    #endif
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

        default:
            break;
    }
}


void mmi_phb_generic_mark_several_select_number_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}

void mmi_phb_generic_mark_several_select_number_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = mmi_phb_cntx_mgr_get_current_sg_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* since it is a timeout function, so check if the sg exist */
    if (sg_id == GRP_ID_INVALID)
    {
        return;
    }
    
    switch (g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index])
    {
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            g_mmi_phb_list_p->mark_field[g_mmi_phb_list_p->list_index] = MMI_PHB_NUMBER_TYPE_NUMBER;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            g_mmi_phb_list_p->mark_field[g_mmi_phb_list_p->list_index] = MMI_PHB_NUMBER_TYPE_HOME_NUMBER;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            g_mmi_phb_list_p->mark_field[g_mmi_phb_list_p->list_index] = MMI_PHB_NUMBER_TYPE_OFFICE_NUMBER;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            g_mmi_phb_list_p->mark_field[g_mmi_phb_list_p->list_index] = MMI_PHB_NUMBER_TYPE_FAX_NUMBER;
            break;
            
        case SRV_PHB_ENTRY_FIELD_EMAIL1:
            g_mmi_phb_list_p->mark_field[g_mmi_phb_list_p->list_index] = MMI_PHB_NUMBER_TYPE_EMAIL_ADDRESS;
            break;
            
        case SRV_PHB_ENTRY_FIELD_EMAIL2:
            g_mmi_phb_list_p->mark_field[g_mmi_phb_list_p->list_index] = MMI_PHB_NUMBER_TYPE_EMAIL_ADDRESS_2;
            break;
            
        default:
            break;
    }

    g_mmi_phb_list_p->list_index++;
    
    mmi_frm_display_dummy_screen();
    mmi_frm_scrn_close(mmi_phb_cntx_mgr_get_current_sg_id(), SCR_CHOOSE_NUMBER);

    if (g_mmi_phb_list_p->list_index < g_mmi_phb_list_p->mark_count)
    {
        mmi_phb_generic_mark_several_select_number_pre_entry();
    }
    else
    {
        g_mmi_phb_list_p->evt_out = MMI_TRUE;
        cui_phb_list_multi_select_contact_emit(
            g_mmi_phb_list_p->sg_id,
            EVT_ID_PHB_SELECT_MULTI_CONTACT,
            g_mmi_phb_list_p->mark_count,
            g_mmi_phb_list_p->mark_array,
            g_mmi_phb_list_p->mark_field,
            MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_mark_several_select_number_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_generic_mark_several_select_number_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_choose_field(
        g_mmi_phb_list_p->sg_id,
        g_mmi_phb_list_p->mark_array[g_mmi_phb_list_p->list_index],
        g_mmi_phb_list_p->filter,
        mmi_phb_generic_mark_several_select_number_pre_entry,
        mmi_phb_generic_mark_several_select_number_more,
        mmi_phb_generic_mark_several_select_number_back,
        NULL,
        MMI_FALSE,
        MMI_TRUE);
}


#if defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_mark_several_list_done_for_group
 * DESCRIPTION
 *  Sends the names & numbers info of the selected
 *  caller group to SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_generic_mark_several_list_done_for_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage_mask;
    U16 entry_count;
    U32 i;
    srv_phb_contact_filter filter;
    srv_phb_query_req_struct req;
    srv_phb_query_handle query_handle;
    U32 field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clear key immediately to avoid user press twice. */
    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);

    filter = srv_phb_create_contact_filter();
    field = srv_phb_convert_field_filter(g_mmi_phb_list_p->filter);
    srv_phb_contact_filter_set_field(filter, field);
    if (g_mmi_phb_list_p->storage == PHB_STORAGE_MAX)
    {
        storage_mask = SRV_PHB_STORAGE_MASK_ALL;
    }
    else
    {
        storage_mask = 1 << g_mmi_phb_list_p->storage;
    }
    srv_phb_contact_filter_set_storage(filter, storage_mask);
#ifdef __MMI_PHB_CALLER_GROUP__
    srv_phb_contact_filter_set_group(filter, g_mmi_phb_list_p->group_id, MMI_TRUE);
#endif
    req.filter = filter;
    req.align_field = MMI_PHB_CONTACT_FIELD_NAME;
    query_handle = srv_phb_query(&req, NULL);
    entry_count = srv_phb_query_get_count(query_handle);
    g_mmi_phb_list_p->mark_count  = entry_count;
    for (i = 0; i < entry_count; i++)
    {
        g_mmi_phb_list_p->mark_array[i] = srv_phb_query_get_contact_id(query_handle, i);
    }
    srv_phb_free_contact_filter(filter);
    srv_phb_free_query_handle(query_handle);
}


void mmi_frm_scrn_close_active_id_ext(MMI_ID group_id)
{
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_mark_several_list_add_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_generic_mark_several_list_add_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_generic_mark_several_list_done_for_group();
    
    if (g_mmi_phb_list_p->mark_count == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_ENTRY_TO_SELECT,
            MMI_EVENT_FAILURE,
            g_mmi_phb_list_p->sg_id,
            NULL);

        return;
    }
    
    if (g_mmi_phb_list_p->mark_count <= g_mmi_phb_list_p->select_count)
    {
        mmi_phb_mark_several_select_field(GRP_ID_PHB_MARK_SEVERAL);
        return;
    }

    g_mmi_phb_list_p->mark_count = g_mmi_phb_list_p->select_count;
    
    mmi_phb_continue_send_multi_message_confirm(
        g_mmi_phb_list_p->select_count,
        mmi_phb_mark_several_select_field,
        mmi_frm_scrn_close_active_id_ext,
        g_mmi_phb_list_p->sg_id);
}
#endif /* defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 


static void mmi_phb_mark_several_list_highlight_handler_tab(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_phb_mark_several_list_highlight_handler(item_index);

    //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); 
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_list_done
 * DESCRIPTION
 *  set check box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_mark_several_list_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 mark_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mark_count = mmi_phb_mark_several_populate();

    /* if not select any one, then use the highlight one */
    if (mark_count == 0)
    {
        mark_count = 1;
        g_mmi_phb_list_p->mark_array[0] = g_mmi_phb_list_p->contact_array[g_mmi_phb_list_p->list_index];
    }

    g_mmi_phb_list_p->evt_out = MMI_TRUE;
    cui_phb_list_multi_select_contact_emit(
        g_mmi_phb_list_p->sg_id,
        EVT_ID_PHB_SELECT_MULTI_CONTACT,
        mark_count,
        g_mmi_phb_list_p->mark_array,
        NULL,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_go_back_history
 * DESCRIPTION
 *  go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_generic_mark_several_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_generic_mark_several
 * DESCRIPTION
 *  Exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_generic_mark_several(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_QUICK_SEARCH__)
    mmi_imc_key_set_pre_key_handler(NULL);
#endif

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_generic_multi_select_list
 * DESCRIPTION
 *  entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_generic_mark_several(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage_mask;
    U8 *gui_buffer;
    U16 entry_count;
    U32 i;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data;
    U16 left_icon_id = IMG_GLOBAL_L1;
    srv_phb_contact_filter filter;
    srv_phb_query_req_struct req;
    srv_phb_query_handle query_handle;
    U32 field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    filter = srv_phb_create_contact_filter();
    field = srv_phb_convert_field_filter(g_mmi_phb_list_p->filter);
    srv_phb_contact_filter_set_field(filter, field);
    if (g_mmi_phb_list_p->storage == PHB_STORAGE_MAX)
    {
        storage_mask = SRV_PHB_STORAGE_MASK_ALL;
    }
    else
    {
        storage_mask = 1 << g_mmi_phb_list_p->storage;
    }
    srv_phb_contact_filter_set_storage(filter, storage_mask);
#ifdef __MMI_PHB_CALLER_GROUP__
    if (g_mmi_phb_list_p->group_filter.group_mask != 0xffff)
    {
        srv_phb_contact_filter_set_group(filter, g_mmi_phb_list_p->group_id, g_mmi_phb_list_p->group_filter.is_equal);
    }
#endif
    req.filter = filter;
    req.align_field = MMI_PHB_CONTACT_FIELD_NAME;
    query_handle = srv_phb_query(&req, NULL);
    entry_count = srv_phb_query_get_count(query_handle);
    g_mmi_phb_list_p->contact_count = entry_count;
    for (i = 0; i < entry_count; i++)
    {
        g_mmi_phb_list_p->contact_array[i] = srv_phb_query_get_contact_id(query_handle, i);
    }
    srv_phb_free_contact_filter(filter);
    srv_phb_free_query_handle(query_handle);

    if (entry_count == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_ENTRY_TO_SELECT,
            MMI_EVENT_FAILURE,
            g_mmi_phb_list_p->sg_id,
            NULL);

        return;
    }
    if (mmi_frm_scrn_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_GENERIC_MULTI_SELECT,
            mmi_phb_exit_generic_mark_several,
            mmi_phb_entry_generic_mark_several,
            MMI_FRM_FULL_SCRN))
    {            
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        RegisterHighlightHandler(mmi_phb_mark_several_list_highlight_handler);

        if (gui_buffer == NULL)
        {
            g_mmi_phb_list_p->list_index = 0;
        }
        else        
        {
            if (!mmi_is_redrawing_bk_screens())
            {
                handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
                refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);
                
                if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
                {
                    gui_buffer = NULL;
                    g_mmi_phb_list_p->list_index = 0;
                    
                #if defined(__MMI_PHB_QUICK_SEARCH__)
                    g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
                #endif
                    memset(g_mmi_phb_list_p->bitmask, 0, (MMI_PHB_ENTRIES + 7) / 8);

                    refresh_data->refresh_type = MMI_PHB_OP_NONE;
                }
            }
        }
        
    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_icon_on_highlight_only_in_menuitem();
    #endif

        EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
    
    #if defined(__MMI_PHB_QUICK_SEARCH__)
    
        RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry);
        g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_GENERIC;
        
        if (gui_buffer != NULL)
        {
            entry_count = (U16) mmi_phb_quick_search_find_entry((U8 *) g_mmi_phb_list_p->qsearch_input_buffer);
        }
    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_generic_list_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_generic_list_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_generic_list_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_generic_list_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index);
        left_icon_id = IMG_ID_PHB_LIST_PHOTO;
    #endif

#ifndef __MMI_MAINLCD_96X64__

        ShowCategory202Screen_ext(
            STR_SCR_PBOOK_VIEW_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_ADD,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            NULL,
            entry_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            g_mmi_phb_list_p->list_index,
            IMG_ID_PHB_QUICK_SEARCH_FIND,
            get_image(left_icon_id),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);
#else
        ShowCategory202Screen_ext(
            STR_SCR_PBOOK_VIEW_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_ADD,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            NULL,
            entry_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            g_mmi_phb_list_p->list_index,
            IMG_GLOBAL_COMMON_CSK,
            get_image(IMG_STORAGE_SIM),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);
#endif
        
        SetLeftSoftkeyFunction(mmi_phb_mark_several_list_done, KEY_EVENT_UP);
        SetCategory200LeftSoftkeyFunction(mmi_phb_mark_several_list_done, KEY_EVENT_UP);
        SetCategory200RightSoftkeyFunction(mmi_phb_generic_mark_several_go_back_history, KEY_EVENT_UP);
    #else
        
        wgui_cat1024_show(
            (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8)GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_ADD),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            NULL,
            entry_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint_ext,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            IMG_STORAGE_SIM,
            IMG_GLOBAL_SIM1,
            0,
            gui_buffer);
    
    
        SetLeftSoftkeyFunction(mmi_phb_mark_several_list_done, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_phb_generic_mark_several_go_back_history, KEY_EVENT_UP);
    #endif
    
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif

        SetCenterSoftkeyFunction(mmi_phb_mark_several_check, KEY_EVENT_UP);
    
        mmi_imc_key_set_pre_key_handler(mmi_phb_star_key_pre_handler);

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_fte_mark_generic_list_tap_callback);
    #endif
    }
}

void mmi_phb_mark_several_select_field(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_phb_list_p->filter)
    {
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            for (i = 0; i < g_mmi_phb_list_p->mark_count; i++)
            {
                g_mmi_phb_list_p->mark_field[i] = MMI_PHB_NUMBER_TYPE_NUMBER;
            }

            g_mmi_phb_list_p->evt_out = MMI_TRUE;
            cui_phb_list_multi_select_contact_emit(
                g_mmi_phb_list_p->sg_id,
                EVT_ID_PHB_SELECT_MULTI_CONTACT,
                g_mmi_phb_list_p->mark_count,
                g_mmi_phb_list_p->mark_array,
                g_mmi_phb_list_p->mark_field,
                MMI_FALSE);
            break;
            
    #if !defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case SRV_PHB_ENTRY_FIELD_EMAIL:
            for (i = 0; i < g_mmi_phb_list_p->mark_count; i++)
            {
                g_mmi_phb_list_p->mark_field[i] = MMI_PHB_NUMBER_TYPE_EMAIL_ADDRESS;
            }

            g_mmi_phb_list_p->evt_out = MMI_TRUE;           
            cui_phb_list_multi_select_contact_emit(
                g_mmi_phb_list_p->sg_id,
                EVT_ID_PHB_SELECT_MULTI_CONTACT,
                g_mmi_phb_list_p->mark_count,
                g_mmi_phb_list_p->mark_array,
                g_mmi_phb_list_p->mark_field,
                MMI_FALSE);
            break;
    #endif

    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case SRV_PHB_ENTRY_FIELD_EMAIL:
    #endif
        case SRV_PHB_ENTRY_FIELD_NUMBER | SRV_PHB_ENTRY_FIELD_EMAIL:
        default:
            /**
             * use list highlight index to build field array
             */
            g_mmi_phb_list_p->list_index = 0;
            mmi_phb_generic_mark_several_select_number_pre_entry();
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_tab_done
 * DESCRIPTION
 *  set check box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_mark_several_tab_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_list_p->mark_count = mmi_phb_mark_several_populate();

    /* if not select any one, then use the highlight one */
    if (g_mmi_phb_list_p->mark_count == 0)
    {
        g_mmi_phb_list_p->mark_count = 1;
        g_mmi_phb_list_p->mark_array[0] = g_mmi_phb_list_p->contact_array[g_mmi_phb_list_p->list_index];
    }

    mmi_phb_mark_several_select_field(GRP_ID_PHB_MARK_SEVERAL);
}


#ifdef __MMI_PHB_CALLER_GROUP__
static S32 mmi_phb_mark_several_group_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Index used to fill menu data should be in range 0 to (data_size - 1) */
    for (index = 0; index < data_size; index++)
    {
        srv_phb_get_group_name(g_mmi_phb_list_p->group_array[index + item_index], (U16*)menu_data[index].item_list[0], MAX_SUBMENU_CHARACTERS);
        menu_data[index].image_list[0] = get_image(gIndexIconsImageList[index + item_index]);
    }
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mark_several_group_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mark_several_group_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mmi_phb_list_p->group_id = g_mmi_phb_list_p->group_array[index];

    //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); 
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


#ifndef __MMI_MAINLCD_96X64__



static void mmi_phb_exit_generic_mark_several_tab0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_generic_mark_several_tab0
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_generic_mark_several_tab0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data;
    U16 left_icon_id = IMG_GLOBAL_L1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_MARK_SEVERAL_TAB_0,
            mmi_phb_exit_generic_mark_several_tab0,
            mmi_phb_entry_generic_mark_several_tab0,
            MMI_FRM_FULL_SCRN))
	#else
    if (mmi_frm_scrn_tab_page_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_GENERIC_MULTI_SELECT,
            SCR_ID_PHB_MARK_SEVERAL_TAB_0,
            mmi_phb_exit_generic_mark_several_tab0,
            mmi_phb_entry_generic_mark_several_tab0,
            MMI_FRM_TAB_PAGE))
    #endif
    {        
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
		#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
		   if(!gui_buffer)
		   {
		   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_ID_PHB_GENERIC_MULTI_SELECT,SCR_ID_PHB_MARK_SEVERAL_TAB_0);
		   	}
	   #endif
        RegisterHighlightHandler(mmi_phb_mark_several_list_highlight_handler_tab);

        if (gui_buffer == NULL)
        {
            g_mmi_phb_list_p->list_index = 0;
        }
        else        
        {
            if (!mmi_is_redrawing_bk_screens())
            {
                handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
                refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);
                
                if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
                {
                    gui_buffer = NULL;
                    g_mmi_phb_list_p->list_index = 0;
                    
                #if defined(__MMI_PHB_QUICK_SEARCH__)
                    g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
                #endif
                    memset(g_mmi_phb_list_p->bitmask, 0, (MMI_PHB_ENTRIES + 7) / 8);

                    refresh_data->refresh_type = MMI_PHB_OP_NONE;
                }
            }
        }
        
        EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
		

    #if defined(__MMI_PHB_QUICK_SEARCH__)
        RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry_tab);
        g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_GENERIC;

    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_generic_list_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_generic_list_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_generic_list_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_generic_list_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index);
        left_icon_id = IMG_ID_PHB_LIST_PHOTO;
    #endif

#ifndef __MMI_MAINLCD_96X64__
        wgui_cat_set_search_icon(IMG_ID_PHB_QUICK_SEARCH_FIND);
#else
        wgui_cat_set_search_icon(IMG_GLOBAL_COMMON_CSK);
#endif

        ShowCategory199Screen_ext(
            (UI_string_type) GetString(STR_GLOBAL_ADD),
            NULL,
            (UI_string_type) GetString(STR_GLOBAL_BACK),
            NULL,
            0,
            (UI_string_type) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            NULL,
            g_mmi_phb_list_p->contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            g_mmi_phb_list_p->list_index,
            get_image(left_icon_id),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);
        
        SetLeftSoftkeyFunction(mmi_phb_mark_several_tab_done, KEY_EVENT_UP);
        SetCategory200LeftSoftkeyFunction(mmi_phb_mark_several_tab_done, KEY_EVENT_UP);
        SetCategory200RightSoftkeyFunction(mmi_phb_generic_mark_several_go_back_history, KEY_EVENT_UP);
    #else

        wgui_cat1025_show(
            (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_ADD),
            NULL,
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            NULL,
            NULL,
            (S32) g_mmi_phb_list_p->contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            IMG_STORAGE_SIM,
            IMG_GLOBAL_SIM1,
            g_mmi_phb_list_p->list_index,
            0,
            gui_buffer);
    
        SetLeftSoftkeyFunction(mmi_phb_mark_several_tab_done, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_phb_generic_mark_several_go_back_history, KEY_EVENT_UP);
    #endif

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
    #endif /* __MMI_TOUCH_SCREEN__ */
        
        SetCenterSoftkeyFunction(mmi_phb_mark_several_check, KEY_EVENT_UP);
		

        mmi_imc_key_set_pre_key_handler(mmi_phb_star_key_pre_handler);

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_fte_mark_generic_list_tap_callback);
    #endif
    }
}



#else

#ifdef __MMI_PHB_CALLER_GROUP__


static void mmi_phb_exit_generic_mark_several_tab0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_generic_mark_several_tab0
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_generic_mark_several_tab0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data;
    U16 left_icon_id = IMG_GLOBAL_L1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_MARK_SEVERAL_TAB_0,
            mmi_phb_exit_generic_mark_several_tab0,
            mmi_phb_entry_generic_mark_several_tab0,
            MMI_FRM_FULL_SCRN))
	#else
    if (mmi_frm_scrn_tab_page_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_GENERIC_MULTI_SELECT,
            SCR_ID_PHB_MARK_SEVERAL_TAB_0,
            mmi_phb_exit_generic_mark_several_tab0,
            mmi_phb_entry_generic_mark_several_tab0,
            MMI_FRM_TAB_PAGE))
     #endif
    {        
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	   #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
		   if(!gui_buffer)
		   {
		   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_ID_PHB_GENERIC_MULTI_SELECT,SCR_ID_PHB_MARK_SEVERAL_TAB_0);
		   	}
	   #endif
        RegisterHighlightHandler(mmi_phb_mark_several_list_highlight_handler_tab);

        if (gui_buffer == NULL)
        {
            g_mmi_phb_list_p->list_index = 0;
        }
        else        
        {
            if (!mmi_is_redrawing_bk_screens())
            {
                handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
                refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);
                
                if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
                {
                    gui_buffer = NULL;
                    g_mmi_phb_list_p->list_index = 0;
                    
                #if defined(__MMI_PHB_QUICK_SEARCH__)
                    g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
                #endif
                    memset(g_mmi_phb_list_p->bitmask, 0, (MMI_PHB_ENTRIES + 7) / 8);

                    refresh_data->refresh_type = MMI_PHB_OP_NONE;
                }
            }
        }

        EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

    #if defined(__MMI_PHB_QUICK_SEARCH__)
        RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry_tab);
        g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_GENERIC;

    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_generic_list_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_generic_list_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_generic_list_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_generic_list_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index);
        left_icon_id = IMG_ID_PHB_LIST_PHOTO;
    #endif
#ifndef __MMI_MAINLCD_96X64__
        wgui_cat_set_search_icon(IMG_ID_PHB_QUICK_SEARCH_FIND);
#else
        wgui_cat_set_search_icon(IMG_GLOBAL_COMMON_CSK);
#endif

        ShowCategory199Screen_ext(
            (UI_string_type) GetString(STR_GLOBAL_ADD),
            NULL,
            (UI_string_type) GetString(STR_GLOBAL_BACK),
            NULL,
            0,
            (UI_string_type) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            NULL,
            g_mmi_phb_list_p->contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            g_mmi_phb_list_p->list_index,
            get_image(left_icon_id),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);
        
        SetLeftSoftkeyFunction(mmi_phb_mark_several_tab_done, KEY_EVENT_UP);
        SetCategory200LeftSoftkeyFunction(mmi_phb_mark_several_tab_done, KEY_EVENT_UP);
        SetCategory200RightSoftkeyFunction(mmi_phb_generic_mark_several_go_back_history, KEY_EVENT_UP);
    #else

        wgui_cat1025_show(
            (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_ADD),
            NULL,
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            NULL,
            NULL,
            (S32) g_mmi_phb_list_p->contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint,
            mmi_phb_mark_several_get_state,
            mmi_phb_mark_several_set_state,
            IMG_STORAGE_SIM,
            IMG_GLOBAL_SIM1,
            g_mmi_phb_list_p->list_index,
            0,
            gui_buffer);
    
        SetLeftSoftkeyFunction(mmi_phb_mark_several_tab_done, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_phb_generic_mark_several_go_back_history, KEY_EVENT_UP);
    #endif

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
    #endif /* __MMI_TOUCH_SCREEN__ */

        SetCenterSoftkeyFunction(mmi_phb_mark_several_check, KEY_EVENT_UP);

        mmi_imc_key_set_pre_key_handler(mmi_phb_star_key_pre_handler);

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_fte_mark_generic_list_tap_callback);
    #endif
    }
}

#endif
#endif


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_generic_mark_several_tab1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_generic_mark_several_tab1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 group_count = 0;
    U16 str_id = STR_ID_PHB_NO_GROUP;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_MARK_SEVERAL_TAB_1,
            NULL,
            mmi_phb_entry_generic_mark_several_tab1,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_GENERIC_MULTI_SELECT,
            SCR_ID_PHB_MARK_SEVERAL_TAB_1,
            NULL,
            mmi_phb_entry_generic_mark_several_tab1,
            MMI_FRM_TAB_PAGE))
     #endif
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!gui_buffer)
	   {
	   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_ID_PHB_GENERIC_MULTI_SELECT,SCR_ID_PHB_MARK_SEVERAL_TAB_1);
	   	}
   #endif
    RegisterHighlightHandler(mmi_phb_mark_several_group_highlight_hdlr);

#if defined(__MMI_PHB_USIM_GROUP_SUPPORT__) || defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
    group_count = srv_phb_get_group_list(g_mmi_phb_list_p->group_array, NULL, (phb_storage_enum)g_mmi_phb_list_p->storage);
#else
    group_count = srv_phb_get_group_list(g_mmi_phb_list_p->group_array, NULL, PHB_STORAGE_NVRAM);
#endif

#ifndef __MMI_PHB_USIM_GROUP_SUPPORT__
    if (g_mmi_phb_list_p->storage == PHB_STORAGE_SIM || g_mmi_phb_list_p->storage == PHB_STORAGE_SIM2 ||
        g_mmi_phb_list_p->storage == PHB_STORAGE_SIM3 || g_mmi_phb_list_p->storage == PHB_STORAGE_SIM4)
    {
        str_id = STR_ID_PHB_NO_GROUP_INFO;
    }
#endif

    if (group_count > 0)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
        wgui_cat1032_show(
        (WCHAR*) GetString(STR_SCR_CALLER_GROUP_CAPTION),
        (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
        (WCHAR*) GetString(STR_GLOBAL_ADD),
        NULL,
        (WCHAR*) GetString(STR_GLOBAL_BACK),
        NULL,
        group_count,
        mmi_phb_mark_several_group_get_item,
        NULL,
        0,
        1,    
        IMG_GLOBAL_L1,
        IMG_GLOBAL_SIM1,
        gui_buffer,
        NULL);
        
    #if defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)
        SetLeftSoftkeyFunction(mmi_phb_generic_mark_several_list_add_confirm, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_generic_mark_several_list_add_confirm, KEY_EVENT_UP);
    #endif
    }
    else
    {
        wgui_cat3001_show(
            get_string(STR_SCR_CALLER_GROUP_CAPTION),
            0,
            0,
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK),
            (S8)1,
            MMI_TRUE,
            (U8*) GetString(str_id),
            100,
            gui_buffer);
    }
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

    SetRightSoftkeyFunction(mmi_phb_generic_mark_several_go_back_history, KEY_EVENT_UP);

    /* register arrow key, because FW2.0 restrict */
    //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); 
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


#ifndef __MMI_MAINLCD_96X64__
static void mmi_phb_exit_generic_mark_several_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_set_pre_key_handler(NULL);

#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
    mmi_msg_exit_generic();
#endif 
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_generic_mark_several_tab
 * DESCRIPTION
 *  tab entry function of mark several list 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_generic_mark_several_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_filter_struct * filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    filter = mmi_phb_list_build_filter(
                 PHB_STORAGE_MAX,
                 g_mmi_phb_list_p->filter,
                 &g_mmi_phb_list_p->group_filter,
                 NULL,
                 0);
    
    g_mmi_phb_list_p->contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);

    mmi_phb_list_free_filter(filter);

    if (g_mmi_phb_list_p->contact_count == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_ENTRY_TO_SELECT,
            MMI_EVENT_FAILURE,
            g_mmi_phb_list_p->sg_id,
            NULL);
    }
    else
    {
        mmi_frm_tab_struct tab_pages_info_array[2];
        U8 tab_id = 0;

        tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_MARK_SEVERAL_TAB_0;
        tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_generic_mark_several_tab0;
        tab_pages_info_array[tab_id].tab_icon = (U8*) GetImage(IMG_ID_PHB_TAB_LIST);
        tab_pages_info_array[tab_id++].tab_string = NULL;

    #ifdef __MMI_PHB_CALLER_GROUP__
    #if defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)
        tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_MARK_SEVERAL_TAB_1;
        tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_generic_mark_several_tab1;
        tab_pages_info_array[tab_id].tab_icon = (U8*) GetImage(IMG_ID_PHB_TAB_GROUP);
        tab_pages_info_array[tab_id++].tab_string = NULL;
    #endif /* defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__) */
    #endif /* __MMI_PHB_CALLER_GROUP__ */

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
			cui_tab_create(
				g_mmi_phb_list_p->sg_id,
				SCR_ID_PHB_GENERIC_MULTI_SELECT,
				tab_pages_info_array,
				tab_id,
				cui_tab_get_select_index(SCR_ID_PHB_GENERIC_MULTI_SELECT),
				NULL);	
#else
        mmi_frm_scrn_tab_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_GENERIC_MULTI_SELECT,
            mmi_phb_exit_generic_mark_several_tab,
            mmi_phb_entry_generic_mark_several_tab,
            tab_pages_info_array,
            tab_id,
            mmi_frm_scrn_tab_get_active_page_index());
#endif
    }
}

#else

#ifdef __MMI_PHB_CALLER_GROUP__

static void mmi_phb_exit_generic_mark_several_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_set_pre_key_handler(NULL);

#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
    mmi_msg_exit_generic();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_generic_mark_several_tab
 * DESCRIPTION
 *  tab entry function of mark several list 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_generic_mark_several_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_filter_struct * filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    filter = mmi_phb_list_build_filter(
                 PHB_STORAGE_MAX,
                 g_mmi_phb_list_p->filter,
                 &g_mmi_phb_list_p->group_filter,
                 NULL,
                 0);
    
    g_mmi_phb_list_p->contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);

    mmi_phb_list_free_filter(filter);

    if (g_mmi_phb_list_p->contact_count == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_ENTRY_TO_SELECT,
            MMI_EVENT_FAILURE,
            g_mmi_phb_list_p->sg_id,
            NULL);
    }
    else
    {
        mmi_frm_tab_struct tab_pages_info_array[2];
        U8 tab_id = 0;

        tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_MARK_SEVERAL_TAB_0;
        tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_generic_mark_several_tab0;
        tab_pages_info_array[tab_id].tab_icon = (U8*) GetImage(IMG_ID_PHB_TAB_LIST);
        tab_pages_info_array[tab_id++].tab_string = NULL;

    #ifdef __MMI_PHB_CALLER_GROUP__
    #if defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)
        tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_MARK_SEVERAL_TAB_1;
        tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_generic_mark_several_tab1;
        tab_pages_info_array[tab_id].tab_icon = (U8*) GetImage(IMG_ID_PHB_TAB_GROUP);
        tab_pages_info_array[tab_id++].tab_string = NULL;
    #endif /* defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__) */
    #endif /* __MMI_PHB_CALLER_GROUP__ */

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
			cui_tab_create(
				g_mmi_phb_list_p->sg_id,
				SCR_ID_PHB_GENERIC_MULTI_SELECT,
				tab_pages_info_array,
				tab_id,
				cui_tab_get_select_index(SCR_ID_PHB_GENERIC_MULTI_SELECT),
				NULL);	
#else
        mmi_frm_scrn_tab_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_GENERIC_MULTI_SELECT,
            mmi_phb_exit_generic_mark_several_tab,
            mmi_phb_entry_generic_mark_several_tab,
            tab_pages_info_array,
            tab_id,
            mmi_frm_scrn_tab_get_active_page_index());
#endif
    }
}
#endif
#endif
#endif /* defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */

#define MMI_PHB_LIST_SINGLE_SELECT
static void mmi_phb_list_select_field_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name = NULL;
    U16 *select_data = NULL;
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_phb_num_type_enum type;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name = (U16 *) mmi_phb_mem_malloc(sizeof(U16) * (MMI_PHB_NAME_LENGTH + 1), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_get_name(g_mmi_phb_list_p->store_index, name, (MMI_PHB_NAME_LENGTH + 1));

    select_data = (U16 *) mmi_phb_mem_malloc(sizeof(U16) * (MMI_PHB_EMAIL_LENGTH + 1), SRV_PHB_MEMORY_TYPE_CTR);

    switch (g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index])
    {
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            srv_phb_get_number(g_mmi_phb_list_p->store_index, select_data, MMI_PHB_NUMBER_LENGTH + 1);
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            srv_phb_get_optional_number(
                g_mmi_phb_list_p->store_index,
                g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index],
                select_data,
                &type,
                MMI_PHB_NUMBER_LENGTH + 1);
            break;
            
        case SRV_PHB_ENTRY_FIELD_EMAIL1:
            srv_phb_get_email_address(g_mmi_phb_list_p->store_index, select_data, MMI_PHB_EMAIL_LENGTH);
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
        case SRV_PHB_ENTRY_FIELD_EMAIL2:
            srv_phb_get_email_address2(g_mmi_phb_list_p->store_index, select_data, MMI_PHB_EMAIL_LENGTH);
            break;
    #endif
    #endif
    #if 0
    #ifdef __MMI_VOIP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif
    
        default:
            break;
    }

    g_mmi_phb_list_p->evt_out = MMI_TRUE;
    
    cui_phb_list_select_contact_emit(
        g_mmi_phb_list_p->sg_id,
        EVT_ID_PHB_SELECT_CONTACT,
        name,
        select_data,
        g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index],
        g_mmi_phb_list_p->store_index);

    mmi_phb_mem_free(name);    
    mmi_phb_mem_free(select_data);
#ifdef __MMI_PHONEBOOK_MEM_SLIM__		
		if (g_phonebook_memory_pool_ptr)
			{
				mmi_phonebook_app_mem_pool_free(g_phonebook_memory_pool_ptr);
				kal_prompt_trace(MOD_MMI,"[phonebook]mmi_phb_list_select_field_done free");
				g_phonebook_memory_pool_ptr = NULL;
			}
#endif
}

static void mmi_phb_list_select_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    switch (g_mmi_phb_list_p->filter)
    {
        case SRV_PHB_ENTRY_FIELD_NAME:
        case SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_ADDRESS:
        case MMI_PHB_LIST_DFAULT_FILTER:
        {
            U16 *name = NULL;
            U16 *select_data = NULL;

            name = (U16 *) mmi_phb_mem_malloc(sizeof(U16) * (MMI_PHB_NAME_LENGTH + 1), SRV_PHB_MEMORY_TYPE_CTR);
            srv_phb_get_name(g_mmi_phb_list_p->store_index, name, (MMI_PHB_NAME_LENGTH + 1));
            g_mmi_phb_list_p->evt_out = MMI_TRUE;
            
            cui_phb_list_select_contact_emit(
                g_mmi_phb_list_p->sg_id,
                EVT_ID_PHB_SELECT_CONTACT,
                name,
                select_data,
                0,
                g_mmi_phb_list_p->store_index);
            
            mmi_phb_mem_free(name);
            break;
        }
        
        default:
        {
            mmi_phb_entry_choose_field(
                g_mmi_phb_list_p->sg_id,
                g_mmi_phb_list_p->store_index,
                g_mmi_phb_list_p->filter,
                mmi_phb_list_select_done,
                mmi_phb_list_select_field_done,
                mmi_frm_scrn_close_active_id,
                NULL,
                MMI_FALSE,
                MMI_TRUE);
            break;
        }
    }
}


static void mmi_phb_list_select_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
#ifdef __MMI_PHONEBOOK_MEM_SLIM__		
		if (g_phonebook_memory_pool_ptr)
			{
				mmi_phonebook_app_mem_pool_free(g_phonebook_memory_pool_ptr);
				kal_prompt_trace(MOD_MMI,"[phonebook]mmi_phb_list_select_goback free");
				g_phonebook_memory_pool_ptr = NULL;
			}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_select_exit
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_select_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif

    wgui_reset_multitap();

#ifndef __MMI_MAINLCD_96X64__
    is_from_group_add_member=MMI_FALSE;
#endif

}


#ifdef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_select_widget
 * DESCRIPTION
 *  show list for widget
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_phb_list_select_widget(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 contact_filter;
    U16 widget_index = 0;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < g_mmi_phb_list_p->contact_count; i++)
    { 
        store_index = g_mmi_phb_list_p->contact_array[i];
        srv_phb_get_field(store_index, &contact_filter);
        if (contact_filter & MMI_PHB_CONTACT_FIELD_NUMBER)
        {
            g_mmi_phb_list_p->contact_array[widget_index] = store_index;
            widget_index++;
        }
    }
    g_mmi_phb_list_p->contact_count = widget_index;

    return widget_index;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_select_entry
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_select_entry(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 contact_count;
    U8 *gui_buffer;
    srv_phb_filter_struct * filter;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data;
    U16 left_icon_id = IMG_GLOBAL_L1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }
    
    
#ifndef __MMI_MAINLCD_96X64__

	if(MMI_TRUE==is_from_group_add_member)
	{
	filter = mmi_phb_list_build_filter(
                 g_mmi_phb_list_p->storage,
                 g_mmi_phb_list_p->filter,
                 &g_mmi_phb_list_p->group_filter,
                 NULL,
                 0);

	}
	else
	{
    filter = mmi_phb_list_build_filter(
                 PHB_STORAGE_MAX,
                 g_mmi_phb_list_p->filter,
                 &g_mmi_phb_list_p->group_filter,
                 NULL,
                 0);

	}
#else
    filter = mmi_phb_list_build_filter(
                 PHB_STORAGE_MAX,
                 g_mmi_phb_list_p->filter,
                 &g_mmi_phb_list_p->group_filter,
                 NULL,
                 0);

#endif
    
    contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
    g_mmi_phb_list_p->contact_count = contact_count;
#ifdef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
    if (g_mmi_phb_list_p->is_widget)
    {
        contact_count = mmi_phb_list_select_widget();
    }
#endif 
    mmi_phb_list_free_filter(filter);

    if (contact_count == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_ENTRY_TO_SELECT,
            MMI_EVENT_FAILURE,
            g_mmi_phb_list_p->sg_id,
            NULL);
	#ifdef __MMI_PHONEBOOK_MEM_SLIM__		
		if (g_phonebook_memory_pool_ptr)
			{
				mmi_phonebook_app_mem_pool_free(g_phonebook_memory_pool_ptr);
				kal_prompt_trace(MOD_MMI,"[phonebook]mmi_phb_list_select_entry free contact == 0");
				g_phonebook_memory_pool_ptr = NULL;
			}
    #endif

        return;
    }
    
    if (mmi_frm_scrn_enter(
            g_mmi_phb_list_p->sg_id,
            SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST,
            mmi_phb_list_select_exit,
            mmi_phb_list_select_entry,
            MMI_FRM_FULL_SCRN))
    {

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(mmi_phb_list_highlight_handler);

        
    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_icon_on_highlight_only_in_menuitem();
    #endif

        if (gui_buffer != NULL)
        {
            if (!mmi_is_redrawing_bk_screens())
            {
                handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
                refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);
                
                if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
                {
                    gui_buffer = NULL;
                    g_mmi_phb_list_p->list_index = 0;
                    
                #if defined(__MMI_PHB_QUICK_SEARCH__)
                    g_mmi_phb_list_p->qsearch_input_buffer[0] = 0;
                #endif

                    refresh_data->refresh_type = MMI_PHB_OP_NONE;
                }
            }
        }
        
    #if defined(__MMI_PHB_QUICK_SEARCH__)
        RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry);
        
        g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_GENERIC;

        if (gui_buffer != NULL)
        {
            contact_count = (U16) mmi_phb_quick_search_find_entry((U8 *) g_mmi_phb_list_p->qsearch_input_buffer);
        }

    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_generic_list_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_generic_list_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_generic_list_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_generic_list_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index);
        left_icon_id = IMG_ID_PHB_LIST_PHOTO;
    #endif

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

#ifndef __MMI_MAINLCD_96X64__
#if !defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
        ShowCategory200Screen_ext(
        (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        contact_count,
        mmi_phb_get_1024_1025_async_items,
        mmi_phb_list_get_hint,
        g_mmi_phb_list_p->list_index,
        IMG_ID_PHB_QUICK_SEARCH_FIND,
        get_image(left_icon_id),
        get_image(IMG_STORAGE_SIM),
        (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);
#else
        ShowCategory200Screen_ext(        
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        contact_count,
        mmi_phb_get_1024_1025_async_items,
        mmi_phb_list_get_hint,
        g_mmi_phb_list_p->list_index,
        IMG_ID_PHB_QUICK_SEARCH_FIND,
        get_image(left_icon_id),
        get_image(IMG_STORAGE_SIM),
        (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        gui_buffer);

#endif

#else

#if !defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
         ShowCategory200Screen_ext(
            (UI_string_type)GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint,
            g_mmi_phb_list_p->list_index,
            IMG_GLOBAL_COMMON_CSK,
            get_image(IMG_STORAGE_SIM),
            get_image(IMG_STORAGE_SIM),
            (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
            MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
            gui_buffer);
#else
          ShowCategory200Screen_ext(
             STR_SCR_PBOOK_VIEW_CAPTION,
             IMG_SCR_PBOOK_CAPTION,
             STR_GLOBAL_OK,
             IMG_GLOBAL_OK,
             STR_GLOBAL_BACK,
             IMG_GLOBAL_BACK,
             contact_count,
             mmi_phb_get_1024_1025_async_items,
             mmi_phb_list_get_hint,
             g_mmi_phb_list_p->list_index,
             IMG_GLOBAL_COMMON_CSK,
             get_image(IMG_STORAGE_SIM),
             get_image(IMG_STORAGE_SIM),
             (U8*) g_mmi_phb_list_p->qsearch_input_buffer,
             MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
             gui_buffer);


#endif


#endif
        
        SetCategory200LeftSoftkeyFunction(mmi_phb_list_select_done, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_phb_list_select_done, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(mmi_phb_list_select_done, KEY_EVENT_UP);

        SetCategory200RightSoftkeyFunction(mmi_phb_list_select_goback, KEY_EVENT_UP);
    #else

        if (gui_buffer == NULL)
        {
            g_phb_highlight_alpha = 0;
        }
        
        srv_phb_oplib_build_alpha_jump_table(g_mmi_phb_list_p->contact_array, g_mmi_phb_list_p->contact_count);

        wgui_cat1032_show(
            (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
            (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_OK),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            contact_count,
            mmi_phb_get_1024_1025_async_items,
            mmi_phb_list_get_hint,
            g_mmi_phb_list_p->list_index,
            0,    
            IMG_STORAGE_SIM,
            IMG_GLOBAL_SIM1,
            gui_buffer,
            NULL);
        
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        mmi_frm_set_keypad_mode(KEYPAD_1KEY_QWERTY);
        mmi_frm_set_app_translate_key_handler(mmi_phb_list_alpha_callback_ext);
    #else
        wgui_setup_multitap_functions(WGUI_MULTITAP_TYPE_UPPERCASE_ABC, mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback_asyc);
    #endif
        
        SetLeftSoftkeyFunction(mmi_phb_list_select_done, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_phb_list_select_goback, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_list_select_done, KEY_EVENT_UP);
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_index_nlf
 * DESCRIPTION
 *  Gets the index of the currently highlighted item in Phonebook menu list
 *  when name_list_filter opening
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /** 
     * for cancel multitap timer to avoid jump after press array key
     */
    wgui_stop_multitap();
    
    g_mmi_phb_list_p->list_index = item_index;
    g_mmi_phb_list_p->store_index = g_mmi_phb_list_p->contact_array[item_index];

    cui_phb_list_highlight_contact_emit(
        g_mmi_phb_list_p->sg_id,
        EVT_ID_PHB_LIST_CONTACT_HIGHLIGHT,
        g_mmi_phb_list_p->store_index);

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_start();
#endif
}

#define MMI_PHB_COMMON_SCR
#ifndef __MMI_PHB_SLIM_NEW__
static void mmi_phb_entry_main_processing_timer_out_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);
}


static void mmi_phb_exit_main_processing_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);
}


mmi_ret mmi_phb_main_processing_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, mmi_phb_main_processing_scrn_proc, NULL);

            if (param->user_data != NULL)
            {
                mmi_phb_mem_free(param->user_data);
                param->user_data = NULL;
            }
            break;
        }
        
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready_evt = (srv_phb_startup_evt_struct*) param;
            
            if (ready_evt->phb_ready)
            {
                if (mmi_frm_scrn_get_active_id() == SCR_ID_PHB_PROCESSING)
                {
                    mmi_frm_node_struct *new_node_info = (mmi_frm_node_struct*) mmi_frm_scrn_get_user_data(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
                    ((FunctionPtr)(new_node_info->entry_proc))();

                    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
                }
            }
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_not_ready
 * DESCRIPTION
 *  Displays Phobebook not ready screen
 * PARAMETERS
 *  str_id        [IN]   String id for display     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_main_processing_scr(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_startup_is_phb_ready())
    {
        mmi_frm_node_struct *new_node_info = (mmi_frm_node_struct*) mmi_frm_scrn_get_user_data(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
        ((FunctionPtr)(new_node_info->entry_proc))();

        mmi_frm_scrn_close(scrn_data->group_id, SCR_ID_PHB_PROCESSING);

        return;
    }
    
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            SCR_ID_PHB_PROCESSING,
            mmi_phb_exit_main_processing_scr,
            (FunctionPtr) mmi_phb_entry_main_processing_scr,
            MMI_FRM_FULL_SCRN))
    {
        StartTimer(
            PHB_NOTIFYDURATION_TIMER,
            mmi_get_event_based_duration(MMI_EVENT_FAILURE),
            mmi_phb_entry_main_processing_timer_out_handler);
        
        ShowCategory66Screen(
            STR_SCR_PBOOK_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            0,
            0,
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
            IMG_GLOBAL_PROGRESS,
            NULL);
    }
}


static void mmi_phb_entry_main_processing(mmi_frm_node_struct *new_node_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_scrn_first_enter(
        new_node_info->id,
        SCR_ID_PHB_PROCESSING,
        (FunctionPtr) mmi_phb_entry_main_processing_scr,
        new_node_info);
    
    mmi_frm_scrn_set_leave_proc(
        new_node_info->id,
        SCR_ID_PHB_PROCESSING,
        mmi_phb_main_processing_scrn_proc);

    mmi_frm_cb_reg_event(EVT_ID_PHB_READY, mmi_phb_main_processing_scrn_proc, NULL);
}

#endif
static void mmi_phb_entry_not_ready_scr(U16 str_id, mmi_id sg_id)
{
    mmi_frm_scrn_enter(sg_id, SCR_PHB_DUMMY, mmi_phb_exit_not_ready, NULL, MMI_FRM_FULL_SCRN);

    StartTimer(PHB_NOTIFYDURATION_TIMER, mmi_get_event_based_duration(MMI_EVENT_FAILURE), mmi_phb_wait_and_go_back);
    
    srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE), NULL);

    ShowCategory66Screen(
        STR_SCR_PBOOK_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        0,
        0,
        0,
        0,
        (PU8) GetString(str_id),
        mmi_get_event_based_image(MMI_EVENT_FAILURE),
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_not_ready
 * DESCRIPTION
 *  Displays Phobebook not ready screen
 * PARAMETERS
 *  str_id        [IN]   String id for display     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_not_ready(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = mmi_phb_cntx_mgr_get_current_sg_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sg_id == GRP_ID_INVALID)
    {
        sg_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    mmi_phb_entry_not_ready_scr(str_id, sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_not_ready
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_not_ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_exit_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);

    srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_wait_and_go_back
 * DESCRIPTION
 *  Goes back to history after timer expires
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_wait_and_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);
    
    srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE));

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_show_in_progress
 * DESCRIPTION
 *  To display work-in-progress status
 * PARAMETERS
 *  msg         [IN]        
 *  msgIcon     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_show_in_progress(mmi_id sg_id, U16 msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_message = msg;
    mmi_frm_scrn_first_enter(sg_id, SCR_IN_PROGRESS_PHB, (FuncPtr)mmi_phb_entry_in_progress, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_in_progress
 * DESCRIPTION
 *  Draws the in-progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_in_progress(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            NULL,
            (FuncPtr)mmi_phb_entry_in_progress,
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
#endif

    /* passing 0xffff for Title string and Title icon for the disbling the status bar and title display. */
    ShowCategory8Screen(
        0xffff,
        0xffff,
        0,
        0,
        0,
        0,
        g_mmi_phb_message,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


static mmi_ret mmi_phb_mass_processing_set_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        
            
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        #if defined(__MMI_PHB_SLIM_SETTING_MESS_OPERATION__) || defined(__MMI_PHB_MULTI_OPERATION__) || defined(__DM_LAWMO_SUPPORT__)
            mmi_phb_multi_op_cancel();
        #endif
            break;
            
        case EVT_ID_SCRN_DELETE_REQ:
            if (g_phb_cntx_mgr.processing & (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0))  /* if phonebook still copying or deleting, do not deleted this screen */
            {
                return -1;
            }        
            break;
             
        default:
            break;
    }

    return MMI_RET_OK;
}

#ifndef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_show_mass_processing
 * DESCRIPTION
 *  To display work-in-progress status for mass operation
 * PARAMETERS
 *  msg         [IN]        
 *  msgIcon     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_MULTI_VCARD__)||defined(__MMI_PHB_SLIM_SETTING_MESS_OPERATION__)||defined(__MMI_PHB_STARTUP_COPY_SIM__)||defined(__MMI_PHB_MULTI_OPERATION__)
void mmi_phb_show_mass_processing(mmi_id sg_id, U16 msg, U16 total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_message = msg;
    g_mmi_phb_max_op_finish_count = 0;
    g_mmi_phb_max_op_total_count = total_count;
    mmi_frm_scrn_first_enter(sg_id, SCR_COPY_ALL_PROGRESS, (FuncPtr)mmi_phb_entry_mass_processing, NULL);

    mmi_frm_scrn_set_leave_proc(
        sg_id,
        SCR_COPY_ALL_PROGRESS,
        mmi_phb_mass_processing_set_scrn_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mass_processing
 * DESCRIPTION
 *  Draws the in-progress screen for mass operation. (This screen has abort function.)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_mass_processing(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR string[14];
    U16 percentage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            NULL,
            (FuncPtr)mmi_phb_entry_mass_processing,
            MMI_FRM_UNKNOW_SCRN))
    {
        kal_wsprintf(string, "%d/%d", g_mmi_phb_max_op_finish_count, g_mmi_phb_max_op_total_count);
        percentage = (g_mmi_phb_max_op_finish_count * 100) / g_mmi_phb_max_op_total_count;
        ShowCategory402Screen(
                (U8*) GetString(STR_SCR_PBOOK_CAPTION),
                IMG_SCR_PBOOK_CAPTION,
                0,
                0,
                STR_GLOBAL_CANCEL,
                IMG_COPY_ALL_ABORT,
                (U8*)GetString(g_mmi_phb_message),
                percentage,
                (U8*)string);

        /* If this screen is deleted, call back function. */

        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
        {
            ClearInputEventHandler(MMI_DEVICE_KEY);
        }
    #if defined(__MMI_PHB_SLIM_SETTING_MESS_OPERATION__) || defined(__MMI_PHB_MULTI_OPERATION__) || defined(__DM_LAWMO_SUPPORT__)
        SetRightSoftkeyFunction(mmi_phb_mass_processing_abort, KEY_EVENT_UP);
    #endif
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_update_mass_processing
 * DESCRIPTION
 *  delete all interfce
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_update_mass_processing(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_frm_scrn_get_active_id() == SCR_COPY_ALL_PROGRESS)
    {
        U16 percentage;
        WCHAR string[14];
        srv_phb_multi_op_status_evt_struct* evt = (srv_phb_multi_op_status_evt_struct*)param;
        g_mmi_phb_max_op_finish_count = evt->finish_count;
        percentage = (evt->finish_count * 100) / evt->total_count;
        kal_wsprintf(string, "%d/%d", evt->finish_count, evt->total_count);
        UpdateCategory402Value(percentage, (U8*)string);
    }
    return MMI_RET_OK;
}
#else

void mmi_phb_show_mass_processing(mmi_id sg_id, U16 msg, U16 total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_message = msg;
    g_mmi_phb_max_op_finish_count = 0;
    g_mmi_phb_max_op_total_count = total_count;
	
    mmi_frm_scrn_first_enter(sg_id, SCR_COPY_ALL_PROGRESS, (FuncPtr)mmi_phb_entry_mass_processing, NULL);

    mmi_frm_scrn_set_leave_proc(
        sg_id,
        SCR_COPY_ALL_PROGRESS,
        mmi_phb_mass_processing_set_scrn_proc);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_mass_processing
 * DESCRIPTION
 *  Draws the in-progress screen for mass operation. (This screen has abort function.)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_mass_processing(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   


	 if (mmi_frm_scrn_enter(
				scrn_data->group_id,
				scrn_data->scrn_id,
				NULL,
				(FuncPtr)mmi_phb_entry_mass_processing,
				MMI_FRM_UNKNOW_SCRN))
		{
			
		
			ShowCategory8Screen(
			0xffff,
			0xffff,
			0,
			0,
			STR_GLOBAL_ABORT,
            IMG_COPY_ALL_ABORT,
			g_mmi_phb_message,
			mmi_get_event_based_image(MMI_EVENT_PROGRESS),
			NULL);
	 
			/* If this screen is deleted, call back function. */
	 
			if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
			{
				ClearInputEventHandler(MMI_DEVICE_KEY);
			}
   #if defined(__MMI_PHB_SLIM_SETTING_MESS_OPERATION__) || defined(__MMI_PHB_MULTI_OPERATION__) || defined(__DM_LAWMO_SUPPORT__)
			SetRightSoftkeyFunction(mmi_phb_mass_processing_abort, KEY_EVENT_UP);
   #endif
		}

}


#endif



#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
static S32 phb_numbers[MMI_PHB_MAX_NUMBER_COUNT];
static S32 phb_total_number_present;
static U8 current_highligted_item = 0;
MMI_BOOL g_phb_two_line_number_refresh = MMI_FALSE;
U16 g_mmi_phb_list_img_path[SRV_FMGR_PATH_MAX_LEN + 1];

#ifdef __MMI_PHB_DEFAULT_NUMBER__
static U8 default_highlighted_item = 0;
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_display_style
 * DESCRIPTION
 *  Returns the display style for the phonebook list(will return INLINE SELECT style always)
 * PARAMETERS
 *  item_index      [IN]        Actual index of the menuitem in the list
 * RETURNS
 *  U8 display style     TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT
 *****************************************************************************/
U8 mmi_phb_inline_display_style(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_default_value
 * DESCRIPTION
 *  Returns the default inline item to be shown with the entry(Only phone
 *  numbers to be considered)
 * PARAMETERS
 *  item_index      [IN]        Actual index of the menuitem in the list
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_phb_inline_default_value(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_two_line_number_refresh)
    {
        g_phb_two_line_number_refresh = MMI_FALSE;
        
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        current_highligted_item = default_highlighted_item;
    #else
        current_highligted_item = 0;
    #endif
    }
    
    return (current_highligted_item < phb_total_number_present) ? current_highligted_item : (phb_total_number_present - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_two_line_send_key_handler
 * DESCRIPTION
 *  This is the send key handler in case of two line menu item in phone book
 * PARAMETERS
 *  void
 *  Input: NONE(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_two_line_send_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U8 number_to_dial = 0;
    U16 dialing_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    mmi_phb_op_action_cntx_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_mmi_phb_list_p->store_index;

    while (phb_numbers[number_to_dial] != current_highligted_item + 1 && number_to_dial <= MMI_PHB_MAX_NUMBER_COUNT)
    {
        ++number_to_dial;
    }

    mmi_phb_op_cntx_init(&op_cntx);
    op_cntx.store_index = store_index;
    op_cntx.op_action = MMI_PHB_OP_CALL;

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    if (phb_total_number_present == 0)
    {
        if (!mmi_phb_og_start_browser(store_index, mmi_phb_cntx_mgr_get_current_sg_id()))
        {
            mmi_phb_op_start(&op_cntx, g_mmi_phb_list_p->sg_id);
        }
        return;
    }
#endif

    switch (number_to_dial)
    {
        case MMI_PHB_MOBILE_NUMBER:
            srv_phb_get_number(store_index, dialing_number, (U16)(MMI_PHB_NUMBER_LENGTH + 1));
            op_cntx.data = dialing_number;
            op_cntx.data_type = SRV_PHB_ENTRY_FIELD_NUMBER;
            break;
        
        case MMI_PHB_OPTION_NUMBER_1:
        case MMI_PHB_OPTION_NUMBER_2:
        case MMI_PHB_OPTION_NUMBER_3:
            op_cntx.data = dialing_number;
            op_cntx.data_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << (number_to_dial - 1);
            srv_phb_get_optional_number(
                store_index,
                op_cntx.data_type,
                dialing_number,
                NULL,
                MMI_PHB_NUMBER_PLUS_LENGTH);
            break;
            
        default:
            if (store_index >= MMI_PHB_PHONE_ENTRIES)    /* Entry in SIM */
            {
                srv_phb_get_number(store_index, dialing_number, (U16)(MMI_PHB_NUMBER_LENGTH + 1));
                op_cntx.data = dialing_number;
                op_cntx.data_type = SRV_PHB_ENTRY_FIELD_NUMBER;
            }
            break;
    }

    mmi_phb_op_start(&op_cntx, g_mmi_phb_list_p->sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_select_data
 * DESCRIPTION
 *  This function sets the relevant data for the phonebook entry
 * PARAMETERS
 *  item_index              [IN]        Menuitem index
 *  inline_item_index       [IN]        Inline item index
 *  str_buff                [IN]        Inline Item String to be shown
 *  img_buff_p              [?]         Image to be shown with the inline item
 *  thumbnail               [?]         Thumbnail picture to be shown with the inline item
 * RETURNS
 *  S32
 *****************************************************************************/
pBOOL mmi_phb_inline_select_data(
        S32 item_index,
        S32 inline_item_index,
        UI_string_type str_buff,
        PU8 *img_buff_p,
        wgui_thumbnail_image_union *thumbnail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S16 next_phb_number_index = 0;
    pBOOL val = FALSE;
    U16 img_id;
    mmi_phb_num_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_mmi_phb_list_p->contact_array[item_index];

    if (!phb_total_number_present)
    {
        next_phb_number_index = -1;
    }
    else
    {
        current_highligted_item = inline_item_index;
        while (phb_numbers[next_phb_number_index] != (inline_item_index + 1) &&
               next_phb_number_index <= MMI_PHB_MAX_NUMBER_COUNT)
        {
            next_phb_number_index++;
        }
    }    

    switch (next_phb_number_index)
    {
        case MMI_PHB_MOBILE_NUMBER:
            srv_phb_get_number(store_index, (U16*) str_buff, (U16)(MMI_PHB_NUMBER_LENGTH + 1));
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            *img_buff_p = get_image((U16) (IMG_MOBILE_NUMBER));
			#else
			*img_buff_p = 0;
			#endif
            val = TRUE;
            break;
            
        case MMI_PHB_OPTION_NUMBER_1:
        case MMI_PHB_OPTION_NUMBER_2:
        case MMI_PHB_OPTION_NUMBER_3:
            srv_phb_get_optional_number(
                store_index,
                SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << (next_phb_number_index - 1),
                (U16*) str_buff,
                &type,
                MMI_PHB_NUMBER_PLUS_LENGTH);
            *img_buff_p = get_image(mmi_phb_get_img_by_number_type(type));
            val = TRUE;
            break;

        default:
            *img_buff_p = get_image((U16) UI_NULL_IMAGE);
            mmi_asc_to_ucs2((CHAR*) str_buff, (CHAR*) "");
            val = TRUE;
            break;
    }

    if (store_index < srv_phb_get_total_contact(PHB_STORAGE_NVRAM)) /* in NVRAM */
    {
        U16 res_type;
        srv_phb_get_image(store_index, &img_id, g_mmi_phb_list_img_path, &res_type);

        if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
        {
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            if (!srv_fmgr_fs_path_exist(g_mmi_phb_list_img_path))
            {
                thumbnail->path = (CHAR*)g_mmi_phb_list_img_path;
            }
            else
        #endif
            {
                thumbnail->id = IMG_PHB_DEFAULT;
            }
        }
        else if (img_id)
        {
            thumbnail->id = img_id & 0x3fff;
        }
        else
        {
            thumbnail->id = IMG_PHB_DEFAULT;
        }
    }
    else
    {
        thumbnail->id = IMG_ID_PHB_LIST_ICON1;
    }
    return val;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_select_done
 * DESCRIPTION
 *  Sets highlighted item to zero always
 * PARAMETERS
 *  menuitem_index      [IN]        Actual index of the menuitem in the list
 *  selected_index      [IN]        Inline item currently selected
 *****************************************************************************/
void mmi_phb_inline_select_done(S32 menuitem_index, S32 selected_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    current_highligted_item = default_highlighted_item;
#else
    current_highligted_item = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_menuitem_properties
 * DESCRIPTION
 *  This function is used to get the properties of the selected menu item
 * PARAMETERS
 *  index                           [IN]        Menu item index
 *  current_menuitem_properties     [?]         Structure to be filled for menuitem properties
 * RETURNS
 *  U8(?)
 *****************************************************************************/
void mmi_phb_inline_menuitem_properties(int index, wgui_two_line_menuitem_struct *current_menuitem_properties)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S16 number_count = 0;
    S16 entry_count = 0;
    U16 img_id;
    U16 res_type;
    WCHAR temp[2];    
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    U8 default_nubmer_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_mmi_phb_list_p->contact_array[index];
    
    current_menuitem_properties->image_flags = UI_TWO_LINE_MENUITEM_NO_THUMBNAIL;
    current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_LEFT_ALIGN_THUMBNAIL;

    if (store_index < srv_phb_get_total_contact(PHB_STORAGE_NVRAM)) /* in NVRAM */
    {
        mmi_phb_build_image_list();
        srv_phb_get_image(store_index, &img_id, g_mmi_phb_list_img_path, &res_type);

        if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
        {
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            if (!srv_fmgr_fs_path_exist(g_mmi_phb_list_img_path))
            {
                current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_FILE;
            }
            else
        #endif
            {
                current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_ID;
            }
        }
        else if (img_id)
        {
            current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_ID;
        }
        else
        {
            current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_ID;
        }
    }
    else
    {
        current_menuitem_properties->image_flags |= UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_ID;
    }

    memset(phb_numbers, 0, sizeof(phb_numbers));

    /* entry_count signifies the array entry,number_count corresponds to the index of the phone number */
    srv_phb_get_number(store_index, temp, 1);
    if (temp[0])
    {
        number_count++;
        phb_numbers[entry_count] = number_count;

    }

    if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
    {
        U8 number_order[MMI_PHB_OPT_NUM_COUNT];
        S32 i;

        srv_phb_get_optional_number_order(store_index, number_order);

        for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
        {
            srv_phb_get_optional_number(store_index, number_order[i], temp, NULL, 1);
            if (temp[0])
            {
                number_count++;
                switch (number_order[i])
                {
                    case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
                        phb_numbers[MMI_PHB_OPTION_NUMBER_1] = number_count;
                        break;
                        
                    case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
                        phb_numbers[MMI_PHB_OPTION_NUMBER_2] = number_count;
                        break;
                        
                    case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
                        phb_numbers[MMI_PHB_OPTION_NUMBER_3] = number_count;
                        break;
                        
                    default:
                        break;
                }
            }
            else
            {
                break;
            }
        }
    }

#ifdef __MMI_PHB_DEFAULT_NUMBER__
    srv_phb_get_default_number_id(store_index, &default_nubmer_id);

    switch (default_nubmer_id)
    {
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:   //home
            if (phb_numbers[MMI_PHB_OPTION_NUMBER_1])
            {
                default_highlighted_item = phb_numbers[MMI_PHB_OPTION_NUMBER_1] - 1;
            }
            else
            {
                default_highlighted_item = 0;
            }
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:  //office
            if (phb_numbers[MMI_PHB_OPTION_NUMBER_2])
            {
                default_highlighted_item = phb_numbers[MMI_PHB_OPTION_NUMBER_2] - 1;
            }
            else
            {
                default_highlighted_item = 0;
            }
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:      //fax
            if (phb_numbers[MMI_PHB_OPTION_NUMBER_3])
            {
             default_highlighted_item = phb_numbers[MMI_PHB_OPTION_NUMBER_3] - 1;
            }
            else
            {
            default_highlighted_item = 0;
            }
            break;

        case SRV_PHB_ENTRY_FIELD_NUMBER:    //mobile
        case 0xff:                          //default value
        case 0xfe:                          //has been canceled
        default:
            default_highlighted_item = 0;
            break;
    }
#endif

    phb_total_number_present = number_count;
    current_menuitem_properties->num_of_items = phb_total_number_present;
    current_menuitem_properties->defualt_value_callback = mmi_phb_inline_default_value;
    current_menuitem_properties->complete_callback = mmi_phb_inline_select_done;
    current_menuitem_properties->two_line_data_callback.get_data_for_horizontal_select = mmi_phb_inline_select_data;
}
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 

#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
/* under construction !*/
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0    
#if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
#endif
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
	#ifndef __MMI_PHB_SLIM_NEW__
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
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif 
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
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/* under construction !*/
    #ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
/* under construction !*/
    #else
/* under construction !*/
    #endif
    #else
    #ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
/* under construction !*/
    #else
/* under construction !*/
    #endif
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
#if defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__)   /* For IP Dial Key */
/* under construction !*/
/* under construction !*/
#endif /* defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__) */ 
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_list_ext
 * DESCRIPTION
 *  This function is for entering phonebook entry List
 * PARAMETERS
 *  entry_count         [IN]        
 *  str_title           [IN]        
 *  img_title           [IN]        
 *  str_lsk             [IN]        
 *  img_lsk             [IN]
 *  scr_id              [IN]
 *  highlight_ptr       [IN]        
 *  lsk_ptr             [IN]
 *  csk_ptr             [IN]
 *  send_key_ptr        [IN]
 *  ip_key_ptr          [IN]
 *  item_ptr            [IN]        
 *  hint_ptr            [IN]        
 *  entry_ptr           [IN]
 *  exit_ptr            [IN]
 *  alpha_index         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_list_ext(
        mmi_id sg_id,
        U16 entry_count,
        U16 str_title,
        U16 img_title,
        U16 str_lsk,
        U16 img_lsk,
        U16 scr_id,
        U16 img_csk,
        HighlightPtr highlight_ptr,
        FunctionPtr lsk_ptr,
        FunctionPtr csk_ptr,
        FunctionPtr send_key_ptr,
        FunctionPtr ip_key_ptr,
        GetAsyncItemFuncPtr item_ptr,
        GetAsyncHintFuncPtr hint_ptr,
        FunctionPtr entry_ptr,
        FunctionPtr exit_ptr,
        MMI_BOOL alpha_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U32 handle;
    mmi_phb_refresh_struct *refresh_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    if (entry_count == 0)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_ENTRY_TO_SELECT,
            MMI_EVENT_FAILURE,
            sg_id,
            NULL);
        return;
    }

    if (!mmi_frm_scrn_enter(
            sg_id,
            scr_id,
            exit_ptr,
            entry_ptr,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(highlight_ptr);
    
    if (gui_buffer == NULL)
    {
        if (alpha_index)
        {
            g_phb_highlight_alpha = 0;
        }
    }
    else
    {
        if (!mmi_is_redrawing_bk_screens())
        {
            handle = mmi_phb_cntx_mgr_get_handle_by_sg_id(mmi_phb_cntx_mgr_get_current_sg_id());
            refresh_data = mmi_phb_cntx_mgr_get_refresh_data(handle);
        
            if (refresh_data != NULL && refresh_data->refresh_type != MMI_PHB_OP_NONE)
            {
                gui_buffer = NULL;
        
                if (entry_count == 0)
                {
                    g_mmi_phb_list_p->list_index = 0;
                }
                else
                {
                    g_mmi_phb_list_p->list_index = mmi_phb_calc_list_index(
                                                    refresh_data,
                                                    MMI_PHB_LIST_TYPE_SINGLE_SELECT,
                                                    g_mmi_phb_list_p->list_index,
                                                    g_mmi_phb_list_p->contact_array,
                                                    NULL,
                                                    g_mmi_phb_list_p->contact_count);
                }
                
                refresh_data->refresh_type = MMI_PHB_OP_NONE;
            }
        }
    }
    
    if (alpha_index)
    {
        srv_phb_oplib_build_alpha_jump_table(g_mmi_phb_list_p->contact_array, g_mmi_phb_list_p->contact_count);
    }
    
    if (csk_ptr)
    {
        EnableCenterSoftkey(0, img_csk);
    }

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
    mmi_phb_thumbnail_reset_displayable();
    wgui_thumbnail_register_get_image_path_func(mmi_phb_generic_list_thumbnail_get_image_path_callback);
    wgui_thumbnail_register_set_displayable_func(mmi_phb_generic_list_thumbnail_set_displayable);
    wgui_thumbnail_register_get_displayable_func(mmi_phb_generic_list_thumbnail_get_displayable);
    wgui_thumbnail_register_get_image_info_func(mmi_phb_generic_list_thumbnail_get_menuitem_info);
    wgui_thumbnail_register_get_store_id_func(mmi_phb_get_store_id_by_list_index);
#endif

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
    wgui_cat1034_show(
            (WCHAR*) GetString(str_title),
            (PU8) GetImage(img_title),
            (WCHAR*) GetString(str_lsk),
            (PU8) GetImage(img_lsk),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            entry_count,
            item_ptr,
            hint_ptr,
            g_mmi_phb_list_p->list_index,
            0,    
            IMG_ID_PHB_LIST_PHOTO,
            IMG_GLOBAL_SIM1,
            gui_buffer,
            NULL);
#else
    wgui_cat1032_show(
            (WCHAR*) GetString(str_title),
            (PU8) GetImage(img_title),
            (WCHAR*) GetString(str_lsk),
            (PU8) GetImage(img_lsk),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            entry_count,
            item_ptr,
            hint_ptr,
            g_mmi_phb_list_p->list_index,
            0,    
            IMG_STORAGE_SIM,
            IMG_GLOBAL_SIM1,
            gui_buffer,
            NULL);
#endif

    /* register multi-tap function for fast jump, for full list only */
    if (alpha_index)
    {
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        mmi_frm_set_keypad_mode(KEYPAD_1KEY_QWERTY);
        mmi_frm_set_app_translate_key_handler(mmi_phb_list_alpha_callback_replace_existing);
    #else
        wgui_setup_multitap_functions(WGUI_MULTITAP_TYPE_UPPERCASE_ABC, mmi_phb_list_alpha_index, mmi_phb_list_alpha_index_input_callback_asyc);
    #endif
    }

    SetLeftSoftkeyFunction(lsk_ptr, KEY_EVENT_UP);

    if (csk_ptr)
    {   
        SetCenterSoftkeyFunction(csk_ptr, KEY_EVENT_UP);
    }

    //SetKeyHandler(send_key_ptr, KEY_SEND, KEY_EVENT_UP);
	SetKeyUpHandler(send_key_ptr, KEY_SEND);
#if defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__)   /* For IP Dial Key */
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_field_list_highlight_handler
 * DESCRIPTION
 *  Gets the index of the currently highlighted item in Phonebook menu list.
 * PARAMETERS
 *  nIndex      [IN]        Highlight index position
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_field_list_highlight_handler(S32 field_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for cancel multitap timer to avoid jump after press array key */
    wgui_stop_multitap();
    g_mmi_phb_choose_field.highlight_index = (U8) field_index;
}


mmi_ret mmi_phb_choose_number_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            if (param->user_data != NULL)
            {
                mmi_phb_mem_free(param->user_data);
                param->user_data = NULL;
            }
            mmi_frm_group_close(GRP_ID_CHOOSE_FIELD);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


#ifdef __MMI_PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_usim_detail_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL mmi_phb_check_usim_detail_ex(phb_storage_enum storage, U8 occr, phb_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((srv_phb_get_usim_field_total(storage, occr, type)) && 
        (srv_phb_get_usim_field_used(storage, occr, type) != 
            srv_phb_get_usim_field_total(storage, occr, type)))
    {   
        flag = MMI_TRUE;
    }
    
    return flag;
}

 #ifdef __MMI_PHB_OPTIONAL_FIELD__
 /*****************************************************************************
  * FUNCTION
  *  mmi_phb_get_usim_number_type
  * DESCRIPTION
  *  
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/

 U8 mmi_phb_get_usim_number_type(U32 field_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_mask;
    U8 i = 0;
    U8 field_type = MMI_PHB_USIM_FIELD_TOTAL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        temp_mask = g_mmi_phb_contact_p->opt_order[i];
        if((field_mask & temp_mask) != temp_mask)
        {
            field_type = mmi_phb_get_usim_field_mask_by_field_mask(temp_mask,MMI_TRUE);
            break;
        }
    }
    
    return field_type;
}
 #endif
 /*****************************************************************************
  * FUNCTION
  *  mmi_phb_prepare_usim_detail
  * DESCRIPTION
  *  
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
U8 mmi_phb_prepare_usim_detail(const U8* select_type,U16* img_list,U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0,index = 0,field_type = 0;
    U8 j;
    U32 field;
    MMI_BOOL aas_flag = MMI_FALSE;
    MMI_BOOL choose_type = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 type_array[MMI_PHB_FIELD_LABEL_COUNT];
    memset(type_array,0XFF,MMI_PHB_FIELD_LABEL_COUNT);

    srv_phb_get_field_type_list(type_array, MMI_PHB_CONTACT_FIELD_ID_NUMBER, (phb_storage_enum)storage);

    while (select_type[index] != MMI_PHB_USIM_FIELD_TOTAL)
    {
        field_type = select_type[index];
        field = mmi_phb_get_usim_field_mask_by_field_type(field_type,MMI_FALSE);
        
        switch (field)
        {
            case SRV_PHB_ENTRY_FIELD_NICK:
                if((g_mmi_phb_save_contact_p->field_mask & field) != field) /*if no SNE*/
                {
                    if(mmi_phb_check_usim_detail_ex((phb_storage_enum)storage, 0, PHB_SNE))
                    {
                        g_mmi_phb_choose_field.number_to_dial[i] = (U16 *)GetString(STR_ID_PHB_NICK_NAME);
                        g_mmi_phb_choose_field.number_type[i] = (U32)field_type;
                        img_list[i++] = mmi_phb_get_img_by_field_type(field_type);
                    }
                }
                choose_type = MMI_FALSE;
                break;

        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
                
                if (aas_flag || ((g_mmi_phb_save_contact_p->field_mask & field) && !choose_type))
                {
                    break;
                }
                for (j = 0; j < MMI_PHB_OPT_NUM_COUNT; j++)
                {
                    if (g_mmi_phb_contact_p->opt_order[j] == field)
                    {
                        break;
                    }
                }
                field_type = MMI_PHB_FIELD_NUMBER;
                
                if (mmi_phb_check_usim_detail_ex((phb_storage_enum)storage, j, PHB_ANR))
                {
                    g_mmi_phb_choose_field.number_to_dial[i] = (U16 *)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    g_mmi_phb_choose_field.number_type[i] = mmi_phb_get_usim_number_type(g_mmi_phb_save_contact_p->field_mask);
                    img_list[i++] = mmi_phb_get_img_by_field_type(field_type);

                    for(j = 0;j < MMI_PHB_FIELD_LABEL_COUNT; j++)
                    {
                        if(type_array[j] == 0xFF)
                            continue;
                        
                        g_mmi_phb_choose_field.number_to_dial[i] =
                            (U16 *)srv_phb_get_field_type_label(type_array[j], MMI_PHB_CONTACT_FIELD_ID_NUMBER, (phb_storage_enum)storage);
                        
                        g_mmi_phb_choose_field.number_type[i] = 
                            mmi_phb_get_usim_number_type(g_mmi_phb_save_contact_p->field_mask);
                        
                        img_list[i++] = mmi_phb_get_img_by_field_type(field_type);
                    }
                    aas_flag = MMI_TRUE;
                }
                break;
    #endif

            default:
                break;
        }
        index++;
    }

    return i;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_choose_field_ex
 * DESCRIPTION
 *  Allows the user to choose one number to some action  if the entry has more than one number
 * PARAMETERS
 *  sg_id                  [IN]
 *  store_index         [IN]        
 *  EntryFunc           [IN]        
 *  RSKFunc             [IN]        
 *  ActionFunc          [IN]        
 *  empty_str_id        [IN]        
 *  dial_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_choose_field_ex(
        mmi_id sg_id,
        WCHAR *name,
        U8 storage,
        const U8* select_type,
        U32 field_mask,
        FunctionPtr entry_func,
        FunctionPtr lsk_func,
        FunctionPtr rsk_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 field_type = 0, i = 0, index = 0;
    U8 *gui_buffer;
    U16 img_list[MMI_PHB_FIELD_TOTAL];
    U16 title_str[MMI_PHB_NAME_LENGTH + 1];
    U32 field;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_phb_check_storage(MMI_TRUE, storage))
    {
        while (select_type[index] != MMI_PHB_FIELD_TOTAL)
        {
            field_type = select_type[index];
            field = mmi_phb_get_field_mask_by_field_type(field_type);
            if (field  && ((field & field_mask) != field))
            {
                g_mmi_phb_choose_field.number_to_dial[i] = (U16 *)GetString(mmi_phb_get_str_by_field_type(field_type, PHB_STORAGE_NVRAM));
                g_mmi_phb_choose_field.number_type[i] = (U32)field_type;
                img_list[i++] = mmi_phb_get_img_by_field_type(field_type);
            }
            index++;
        }
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    else /*for USIM add detail*/
    {
        i = mmi_phb_prepare_usim_detail(select_type,img_list,storage);
    }
#endif

    if (!mmi_frm_scrn_enter(
            sg_id, 
            SCR_CHOOSE_NUMBER,
            NULL,
            entry_func,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_phb_field_list_highlight_handler);

    if (gui_buffer == NULL)
    {
        g_mmi_phb_choose_field.highlight_index = 0;
    }

    if (name[0])
    {
        mmi_wcsncpy(title_str, name, MMI_PHB_NAME_LENGTH);
    }
    else
    {
        mmi_wcsncpy(title_str, (WCHAR*) GetString(STR_ID_PHB_UNNAMED), MMI_PHB_NAME_LENGTH);
    }
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory353Screen(
        (U8*)title_str,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        i,
        (U8**)g_mmi_phb_choose_field.number_to_dial,
        img_list,
        NULL,
        0,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(lsk_func, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(lsk_func, KEY_EVENT_UP);
    SetRightSoftkeyFunction(rsk_func, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_choose_field
 * DESCRIPTION
 *  Allows the user to choose one number to some action  if the entry has more than one number
 * PARAMETERS
 *  sg_id                  [IN]
 *  store_index         [IN]        
 *  EntryFunc           [IN]        
 *  RSKFunc             [IN]        
 *  ActionFunc          [IN]        
 *  empty_str_id        [IN]        
 *  dial_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_choose_field(
        mmi_id sg_id,
        U16 store_index,
        U32 field_type,
        FunctionPtr entry_func,
        FunctionPtr lsk_func,
        FunctionPtr rsk_func,
        FunctionPtr send_key_func,
        MMI_BOOL show_if_empty,
        MMI_BOOL start_primitive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 *gui_buffer;
    U16 number_type_image_list[7];
    U8  *title_string;
    srv_phb_contact_info_struct* contact_info;
    MMI_BOOL new_num = MMI_FALSE;
    U32 new_filed = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info = mmi_phb_get_contact_build_buffer(&g_mmi_phb_field_data);
    contact_info->field_mask = field_type;
    srv_phb_oplib_get_contact_info(store_index, contact_info);
    mmi_phb_get_contact_free_buffer(contact_info);

    if (field_type & SRV_PHB_ENTRY_FIELD_NUMBER)
    {
        if (g_mmi_phb_field_data.number[0])
        {
            g_mmi_phb_choose_field.number_to_dial[i] = g_mmi_phb_field_data.number;
            g_mmi_phb_choose_field.number_type[i] = SRV_PHB_ENTRY_FIELD_NUMBER;
            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            number_type_image_list[i++] = IMG_MOBILE_NUMBER;
			#else
			number_type_image_list[i++] = 0;
			#endif
        }
        else if (show_if_empty)
        {
            new_num = MMI_TRUE;
            new_filed = 0;
        }
    }

    if (field_type & SRV_PHB_ENTRY_FIELD_OPTIONAL)
    {
    #if !defined(__MMI_PHB_USIM_SUPPORT__)
        if (srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
    #endif
        {
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            S32 j, temp_index;
            U8 index;
            for (j = 0; j < MMI_PHB_OPT_NUM_COUNT; j++)
            {
                temp_index = (U32)(g_mmi_phb_field_data.opt_order[j]);

                if (field_type & temp_index)
                {
                    index = mmi_phb_get_field_type_by_field_mask(temp_index) - MMI_PHB_FIELD_OPT_NUM_1;
                    if (g_mmi_phb_field_data.opt_num[index].number[0])
                    {
                        g_mmi_phb_choose_field.number_to_dial[i] = g_mmi_phb_field_data.opt_num[index].number;
                        g_mmi_phb_choose_field.number_type[i] = temp_index;
                    #ifdef __MMI_PHB_USIM_SUPPORT__
                        if (srv_phb_get_storage(store_index) != PHB_STORAGE_NVRAM)
                        {                  
                            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                            number_type_image_list[i++] = IMG_MOBILE_NUMBER;
			                #else
			                number_type_image_list[i++] = 0;
			                #endif
                        }
                        else
                    #endif
                        {                  
                            number_type_image_list[i++] = mmi_phb_get_img_by_number_type(g_mmi_phb_field_data.opt_num[mmi_phb_get_field_type_by_field_mask(temp_index) - MMI_PHB_FIELD_OPT_NUM_1].type);
                        }
                    }
                    else if (show_if_empty
                        #if defined(__MMI_PHB_USIM_SUPPORT__)
                            && ((srv_phb_get_storage(store_index) == PHB_STORAGE_NVRAM)
                            || (srv_phb_get_support_field_count(srv_phb_get_storage(store_index), MMI_PHB_CONTACT_FIELD_ID_NUMBER) > i))
                        #endif
                            )
                    {
                        new_num = MMI_TRUE;
                        new_filed = SRV_PHB_ENTRY_FIELD_ALL;
                    }
                }
            }

            if (field_type & SRV_PHB_ENTRY_FIELD_EMAIL)
            {
                if (g_mmi_phb_field_data.emailAddress[0])
                {
                    g_mmi_phb_choose_field.number_to_dial[i] = g_mmi_phb_field_data.emailAddress;
                    g_mmi_phb_choose_field.number_type[i] = SRV_PHB_ENTRY_FIELD_EMAIL1;
                #if 0
                #ifndef __OP01__
/* under construction !*/
                #else
/* under construction !*/
                #endif
				#else
				    number_type_image_list[i++] = IMG_EMAIL_ADDRESS;
                #endif
                }
            #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
                if (g_mmi_phb_field_data.emailAddress2[0])
                {
                    g_mmi_phb_choose_field.number_to_dial[i] = g_mmi_phb_field_data.emailAddress2;
                    g_mmi_phb_choose_field.number_type[i] = SRV_PHB_ENTRY_FIELD_EMAIL2;
                    number_type_image_list[i++] = IMG_EMAIL_ADDRESS;
                }
            #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
            }
        #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 
        }
    }

    if (new_num)
    {
        g_mmi_phb_choose_field.number_to_dial[i] = (U16 *)GetString(STR_ID_PHB_ADD_MORE_NUMBER);
        g_mmi_phb_choose_field.number_type[i] = new_filed;
        number_type_image_list[i++] = IMG_ID_PHB_NEW_NUMBER;
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
#endif /* __MMI_VOIP__ */
#endif

    if (!i)
    {
        MMI_BOOL ret;
        /* leave no number to dial to popup by ucm for unified behavior, so aribitrary send a zero length num to ucm */
        g_mmi_phb_choose_field.highlight_index = 0;

        memset(g_mmi_phb_field_data.number, 0x00, ENCODING_LENGTH);
        g_mmi_phb_choose_field.number_to_dial[0] = g_mmi_phb_field_data.number;

        ret = mmi_frm_scrn_enter(
            sg_id, 
            SCR_CHOOSE_NUMBER,
            NULL,
            NULL,
            MMI_FRM_FULL_SCRN);
        if (ret == MMI_TRUE)
        {
            ShowCategoryDummyScreen();
        }
        if (start_primitive)
        {
            StartTimer(PHB_CHOOSE_FIELD_TIMER, 0, lsk_func);
        }
        else
        {
            lsk_func();
        }
    }
    else if (i == 1 && !new_num)
    {
        MMI_BOOL ret;
        g_mmi_phb_choose_field.highlight_index = 0;
        ret = mmi_frm_scrn_enter(
            sg_id, 
            SCR_CHOOSE_NUMBER,
            NULL,
            NULL,
            MMI_FRM_FULL_SCRN);
        if (ret == MMI_TRUE)
        {
            ShowCategoryDummyScreen();
        }
        if (start_primitive)
        {
            StartTimer(PHB_CHOOSE_FIELD_TIMER, 0, lsk_func);
        }
        else
        {
            lsk_func();
        }
    }
    else if (mmi_frm_scrn_enter(
                sg_id, 
                SCR_CHOOSE_NUMBER,
                NULL,
                (FunctionPtr)entry_func,
                MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        RegisterHighlightHandler(mmi_phb_field_list_highlight_handler);

        if (gui_buffer == NULL)
        {
            g_mmi_phb_choose_field.highlight_index = 0;
        }

        srv_phb_get_name(store_index, g_mmi_phb_field_data.name, (U16)(MMI_PHB_NAME_LENGTH + 1));

        if (g_mmi_phb_field_data.name[0])
        {
            title_string = (U8 *) g_mmi_phb_field_data.name;
        }
        else
        {
            title_string = (U8*)GetString(STR_ID_PHB_UNNAMED);
        }

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory353Screen(
            title_string,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            i,
            (U8**)g_mmi_phb_choose_field.number_to_dial,
            number_type_image_list,
            NULL,
            0,
            0,
            gui_buffer);

        SetLeftSoftkeyFunction(lsk_func, KEY_EVENT_UP);
        //SetKeyHandler(send_key_func, KEY_SEND, KEY_EVENT_DOWN);
		SetKeyDownHandler(send_key_func, KEY_SEND);
        SetCenterSoftkeyFunction(lsk_func, KEY_EVENT_UP);
        SetRightSoftkeyFunction(rsk_func, KEY_EVENT_UP);
    }
}

#define MMI_PHB_LIST_UTIL
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_callback
 * DESCRIPTION
 *  jump to the item by input char
 * PARAMETERS
 *  key_code            [IN]     
 *  key_type            [IN]
 *  ucs2_value          [IN]
 *  key_flag              [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_list_alpha_callback(S16 key_code, S16 key_type, U16 ucs2_value, U32 key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((key_code >= KEY_A && key_code <= KEY_Z) && (key_type == KEY_EVENT_DOWN))
    {        
        g_phb_highlight_alpha = srv_phb_oplib_get_alpha_index((U16) key_code);

        mmi_phb_list_alpha_index_input_callback();

        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_callback_ext
 * DESCRIPTION
 *  jump to the item by input char
 * PARAMETERS
 *  key_code            [IN]     
 *  key_type            [IN]
 *  ucs2_value          [IN]
 *  key_flag              [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_list_alpha_callback_ext(S16 key_code, S16 key_type, U16 ucs2_value, U32 key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((key_code >= KEY_A && key_code <= KEY_Z) && (key_type == KEY_EVENT_DOWN))
    {        
        g_phb_highlight_alpha = srv_phb_oplib_get_alpha_index(ucs2_value);

        mmi_phb_list_alpha_index_input_callback_ext();

        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_callback_ext
 * DESCRIPTION
 *  jump to the item by input char
 * PARAMETERS
 *  key_code            [IN]     
 *  key_type            [IN]
 *  ucs2_value          [IN]
 *  key_flag              [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_list_alpha_callback_replace_existing(S16 key_code, S16 key_type, U16 ucs2_value, U32 key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((key_code >= KEY_A && key_code <= KEY_Z) && (key_type == KEY_EVENT_DOWN))
    {        
        g_phb_highlight_alpha = srv_phb_oplib_get_alpha_index(ucs2_value);

        asyncdynamic_list_goto_item((S32)(g_phb_highlight_alpha));  

        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_index
 * DESCRIPTION
 *  This function calculates the index of the entry to be highlighted, if the user jumps to some
 *  entry using multi-tap on PHB list screen.
 * PARAMETERS
 *  input       [IN]        Input character
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_list_alpha_index(U16 input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input >= 'A' && input <= 'Z')
    {
        g_phb_highlight_alpha = srv_phb_oplib_get_alpha_index((U16) input);
    }
}

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_index_input_callback_asyc
 * DESCRIPTION
 *  Jumps to the hilited entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_list_alpha_index_input_callback_asyc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 for Add new contact */
    asyncdynamic_list_goto_item((S32)g_phb_highlight_alpha);  /* Use Async dynamic List */
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_index_input_callback_ext
 * DESCRIPTION
 *  Jumps to the hilited entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_list_alpha_index_input_callback_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 for Add new contact */
    asyncdynamic_list_goto_item((S32)(g_phb_highlight_alpha + 1));  /* Use Async dynamic List */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_alpha_index_input_callback
 * DESCRIPTION
 *  Jumps to the hilited entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_list_alpha_index_input_callback(void)
{
#if defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_device_height == 220 && UI_device_width == 176)
    {
        Cat212ShortCutHdlr(g_phb_highlight_alpha);  /* For image list fast jump */
    }
    else
#endif /* defined(__MMI_FILE_MANAGER__) */ 
    asyncdynamic_list_goto_item((S32)(g_phb_highlight_alpha));  /* Use Async dynamic List */
}

srv_phb_filter_struct *mmi_phb_list_build_filter(
                           U8 storage,
                           U32 field_filter,
                           srv_phb_group_filter_struct* group_filter,
                           U16* key_word,
                           U16 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_filter_struct *filter;
    srv_phb_qsearch_filter_struct *search_filter = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter = (srv_phb_filter_struct *) mmi_phb_mem_malloc(sizeof(srv_phb_filter_struct), SRV_PHB_MEMORY_TYPE_CTR);

    filter->storage= storage;
    filter->field_filter = field_filter;
    filter->name_filter = NULL;

    if (group_filter != NULL && group_filter->group_mask != 0xffff)
    {
        filter->group_filter = group_filter;
    }
    else
    {
        filter->group_filter = NULL;
    }
    #ifdef __MMI_PHB_QUICK_SEARCH__
    if (key_word)
    {
        search_filter = (srv_phb_qsearch_filter_struct *) mmi_phb_mem_malloc(sizeof(srv_phb_qsearch_filter_struct), SRV_PHB_MEMORY_TYPE_CTR);

        search_filter->key_len = mmi_wcslen(key_word);
        search_filter->key_word = key_word;
        search_filter->input_mode = input_mode;
    }

    filter->qsearch_filter = search_filter;
	#else
	filter->qsearch_filter = NULL;
    #endif
    return filter;
}

void mmi_phb_list_free_filter(srv_phb_filter_struct *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filter)
    {
        #ifdef __MMI_PHB_QUICK_SEARCH__
        if (filter->qsearch_filter)
        {
            mmi_phb_mem_free(filter->qsearch_filter);
            filter->qsearch_filter = NULL;
        }
		#else
		filter->qsearch_filter = NULL;
        #endif

        mmi_phb_mem_free(filter);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_1024_1025_async_items
 * DESCRIPTION
 *  Gets the async items for the Phonelist.
 * PARAMETERS
 *  start_index     [IN]
 *  *menu_data      [OUT]
 *  num_items       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_phb_get_1024_1025_async_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_items; i++)
    {
        mmi_phb_list_get_item((i + start_index), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
    }
    return num_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_get_item
 * DESCRIPTION
 *  Getting the items for phone list screen
 * PARAMETERS
 *  item_index     [IN]
 *  str_buff       [OUT]
 *  *img_buff_p1   [OUT]
 *  *img_buff_p2   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_phb_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_name(g_mmi_phb_list_p->contact_array[item_index], str_buff, 2 * MMI_PHB_NAME_FIELD_LENGTH + 1);

    if (str_buff[0] == 0)
    {
        mmi_ucs2ncpy((CHAR*) str_buff, GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
    }

    mmi_phb_contact_get_item_image(g_mmi_phb_list_p->contact_array[item_index], img_buff_p1, img_buff_p2);

    return TRUE;
}


static S32 mmi_phb_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index > g_mmi_phb_list_p->contact_count - 1)
    {
        return 0;
    }
    
    store_index = g_mmi_phb_list_p->contact_array[item_index];
    
    if (g_mmi_phb_list_p->filter & SRV_PHB_ENTRY_FIELD_NUMBER)
    {
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        srv_phb_get_default_number(store_index, (U16*)hint_array[0], NULL, (MMI_PHB_NUMBER_LENGTH + 1));
        if (hint_array[0][0] == 0)
        {
            srv_phb_get_number(store_index, (U16*)hint_array[0], MAX_SUBMENU_CHARACTERS);
        }
    #else /* __MMI_PHB_DEFAULT_NUMBER__ */
        srv_phb_get_number(store_index, (U16*)hint_array[0], MAX_SUBMENU_CHARACTERS);
    #endif /* __MMI_PHB_DEFAULT_NUMBER__ */

        if (hint_array[0][0] != 0)
        {
            return 1;
        }
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (g_mmi_phb_list_p->filter & SRV_PHB_ENTRY_FIELD_EMAIL)
    {
        if (srv_phb_get_storage(store_index) != PHB_STORAGE_NVRAM)
        {
            return 0;
        }

        if (srv_phb_get_email_address(store_index, (U16*) hint_array[0], MAX_SUBMENU_CHARACTERS))
        {
            if (hint_array[0][0] != 0)
            {
                return 1;
            }
        }
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        if (srv_phb_get_email_address2(store_index, (U16*) hint_array[0], MAX_SUBMENU_CHARACTERS))
        {
            if (hint_array[0][0] != 0)
            {
                return 1;
            }
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

#if defined(__MMI_PHB_INFO_FIELD__)
    if (g_mmi_phb_list_p->filter & SRV_PHB_ENTRY_FIELD_ADDRESS)
    {
        if (srv_phb_get_storage(store_index) != PHB_STORAGE_NVRAM)
        {
            return 0;
        }

        if (srv_phb_get_address(
                store_index,
                NULL,
                NULL,
                (U16*) hint_array[0],
                NULL,
                NULL,
                NULL,
                NULL))
        {
            if (hint_array[0][0] != 0)
            {
                return 1;
            }
        }
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

    /* If not select any field type, default type is number */
    if (srv_phb_get_number(store_index, (U16*) hint_array[0], MAX_SUBMENU_CHARACTERS))
    {
        if (hint_array[0][0] != 0)
        {
            return 1;
        }
    }

    return 0;
}

static S32 mmi_phb_list_get_hint_ext(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index <= g_mmi_phb_list_p->contact_count)
    {
        store_index = g_mmi_phb_list_p->contact_array[item_index];
        
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        srv_phb_get_default_number(store_index, (U16*)hint_array[0], NULL, (MMI_PHB_NUMBER_LENGTH + 1));

        if (hint_array[0][0] == 0)
        {
            srv_phb_get_number(store_index, (U16*)hint_array[0], MAX_SUBMENU_CHARACTERS);
        }
    #else /* __MMI_PHB_DEFAULT_NUMBER__ */
        srv_phb_get_number(store_index, (U16*)hint_array[0], MAX_SUBMENU_CHARACTERS);
    #endif /* __MMI_PHB_DEFAULT_NUMBER__ */

        if (hint_array[0][0] != 0)
        {
            result = 1; /* One hint data only, can be more hints. */
        }
    }

    return result;
}


#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_store_id_by_list_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index            [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_phb_get_store_id_by_list_index(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_index < g_mmi_phb_list_p->contact_count);

    return (g_mmi_phb_list_p->contact_array[item_index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_store_id_by_list_index_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index            [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_phb_get_store_id_by_list_index_ext(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == 0)
    {
        if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0)
        {
            return 0xffff;
        }
        else
        {
            return g_mmi_phb_list_p->contact_array[item_index];
        }
    }
    else
    {
        if (g_mmi_phb_list_p->qsearch_input_buffer[0] == 0)
        {
            return g_mmi_phb_list_p->contact_array[item_index - 1];
        }
        else
        {
            return g_mmi_phb_list_p->contact_array[item_index];
        }
    }
}
#endif


#ifdef __MMI_SNS_CONTACTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_is_scrn_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_sns_is_scrn_active(const MMI_ID group_id, const MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid, sid;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&gid, &sid);

    if (group_id == gid && scrn_id == sid)
    {
        ret = MMI_TRUE;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_sns_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sns_is_ready())
    {
        ret = MMI_FALSE;
    }
    
    if (!srv_sns_is_any_login_acocunt())
    {
        ret = MMI_FALSE;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_list_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_sns_is_linked(U16 contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_storage((mmi_phb_contact_id)contact) == PHB_STORAGE_NVRAM)
    {
        if (srv_sns_is_contact_linked(contact, &result))
        {
            ret = MMI_TRUE;
        }
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_list_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_sns_list_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_friend->is_valid && list_favorite->is_valid)
    {
        ret = MMI_TRUE;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_is_progress
 * DESCRIPTION
 *  To display work-in-progress status
 * PARAMETERS
 *  msg         [IN]        
 *  msgIcon     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sns_is_progress(mmi_id sg_id, U16 msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_message = msg;
    mmi_frm_scrn_first_enter(sg_id, SCR_ID_PHB_SNS_PROGRESS, (FuncPtr)mmi_phb_entry_in_progress, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_gui_buffer_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_gui_buffer_clear(mmi_phb_sns_list_enum list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list; 
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == MMI_PHB_SNS_LIST_FRIEND)
    {
        list_friend->is_clear = MMI_TRUE;
        list_friend->highlight_index = 0;
    }
    else if (list_type == MMI_PHB_SNS_LIST_FAVORITE)
    { 
        list_favorite->is_clear = MMI_TRUE;
        list_favorite->highlight_index = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_search_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_search_clear(mmi_phb_sns_list_enum list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list; 
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == MMI_PHB_SNS_LIST_FRIEND)
    {
        list_friend->is_search = MMI_FALSE;
        memset(list_friend->search_buffer, 0, sizeof(WCHAR) * SRV_SNS_MAX_LEN_NAME);
        memset(list_friend->search_temp_buffer, 0, sizeof(WCHAR) * SRV_SNS_MAX_LEN_NAME);
        mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FRIEND);
    }
    else if (list_type == MMI_PHB_SNS_LIST_FAVORITE)
    {
        list_favorite->is_search = MMI_FALSE;
        memset(list_favorite->search_buffer, 0, sizeof(WCHAR) * SRV_SNS_MAX_LEN_NAME);
        memset(list_favorite->search_temp_buffer, 0, sizeof(WCHAR) * SRV_SNS_MAX_LEN_NAME);
        mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FAVORITE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_search_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_search_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_friend->is_group)
    {
        list_friend->list_id = srv_sns_get_friends_by_group(SRV_SNS_SELECTED_FRIENDS_GROUP_ID);        
    }
    else if (list_friend->provider)
    {
        list_friend->list_id = srv_sns_get_friends_by_provider(list_friend->provider);                  
    }
    else
    {
        list_friend->list_id = srv_sns_get_all_friends();
    }
}


#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_set_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_thumbnail_set_displayable(S32 item_index, MMI_BOOL displayable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_thumbnail_set_displayable(item_index, displayable);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_thumbnail_get_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_sns_thumbnail_get_displayable(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_thumbnail_get_displayable(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_store_id_by_list_index_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index            [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_phb_sns_thumbnail_get_store_id(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return item_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_thumbnail_get_image_path_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_phb_sns_thumbnail_get_image_path(S32 item_index, CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;
    srv_sns_friend_struct *friend;
    MMI_BOOL is_get_data = MMI_FALSE;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_sns_list_ready())
    {
        return ret;
    }
    
    if (mmi_phb_sns_is_scrn_active(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_TAB0))
    {
    	if (srv_sns_get_item2(list_friend->list_id, item_index, (void **)&friend) >= 0)
        {
            is_get_data = MMI_TRUE;
        }
    }
    else if (mmi_phb_sns_is_scrn_active(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_TAB1))
    {
        if(srv_sns_get_item2(list_favorite->list_id, item_index, (void **)&friend) >= 0)
        {
            is_get_data = MMI_TRUE;
        }
    }

    if (is_get_data)
    {
        if (friend->user.user_pic && friend->user.user_pic_len > 0)
        {
            if (FS_GetAttributes((PU16)friend->user.user_pic) >= 0)
            {
                mmi_ucs2cpy(path, (CHAR*)friend->user.user_pic);     
                ret = MMI_TRUE;
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_thumbnail_get_menuitem_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_thumbnail_get_menuitem_info(S32 item_idx, wgui_thumbnail_info_struct *menuitem_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_sns_list_ready())
    {
        menuitem_data->is_show_thumb = MMI_FALSE;
    }
    else
    {
        menuitem_data->is_show_thumb = MMI_TRUE;
    }
}
#endif


#ifdef __MMI_SNS_MESSAGES__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_entry_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_entry_send_msg(mmi_phb_sns_list_enum type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phb_sns_friend_list_struct *friend_list = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *favorite_list = g_mmi_phb_list_p->sns_favorite_list;
	srv_sns_friend_struct *friend;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (type == MMI_PHB_SNS_LIST_FRIEND)
	{
		if (srv_sns_get_item2(friend_list->list_id, (S16)friend_list->highlight_index, (void **)&friend) >= 0)
        {
            mmi_sns_new_direct_msg_launch(g_mmi_phb_list_p->sg_id, friend);    
        }
	}
	else if (type == MMI_PHB_SNS_LIST_FAVORITE)
	{
		if (srv_sns_get_item2(favorite_list->list_id, (S16)favorite_list->highlight_index, (void **)&friend) >= 0)
        {
            mmi_sns_new_direct_msg_launch(g_mmi_phb_list_p->sg_id, friend);   
        }
	}
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_entry_view_member
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_entry_view_member(mmi_phb_sns_list_enum list_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;
	srv_sns_friend_struct *friend;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_PHB_SNS_LIST_FRIEND == list_type)
	{
		if (srv_sns_get_item2(list_friend->list_id, (S16)list_friend->highlight_index, (void **)&friend) >= 0)
        {
            mmi_sns_friend_profile_launch(g_mmi_phb_list_p->sg_id, &(friend->user));
        }
	}
	else
	{
		if (srv_sns_get_item2(list_favorite->list_id, (S16)list_favorite->highlight_index, (void **)&friend) >= 0)
        {
            mmi_sns_friend_profile_launch(g_mmi_phb_list_p->sg_id, &(friend->user));
        }
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_entry_set_favorite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_sns_entry_set_favorite(CHAR *user, MMI_BOOL is_add, U32 len)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR user_id[SRV_SNS_MAX_LEN_ID] = {0};
	U32 i;
	CHAR *bitmask;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == len)
    {
        memcpy(user_id, user, SRV_SNS_MAX_LEN_ID);
    }
    else
    {
        memcpy(user_id, user, len);
    }
  
	if(is_add)
	{   /* check already exist*/
		for (i = 0; i < MMI_PHB_SNS_FAVORITE_MAX_NUM; i++) 
		{
			bitmask = g_mmi_phb_list_p->sns_favorite[i];
			if (*bitmask && !mmi_ucs2cmp(user_id, bitmask))
			{
			    return MMI_FALSE;
			}
		}
	
		for (i = 0; i < MMI_PHB_SNS_FAVORITE_MAX_NUM; i++)
		{
		    bitmask = g_mmi_phb_list_p->sns_favorite[i];
			if (0 == *bitmask)
			{
			    memcpy(bitmask, user_id, SRV_SNS_MAX_LEN_ID);
			    break;
			}
		}
	}
	else
	{
		for (i = 0; i < MMI_PHB_SNS_FAVORITE_MAX_NUM; i++)
		{
			bitmask = g_mmi_phb_list_p->sns_favorite[i];
			if (*bitmask && !mmi_ucs2cmp(user_id, bitmask))
			{
                             *bitmask = 0;
			      break;
			}
		}
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_enrty_get_favorite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_sns_enrty_get_favorite(S32 list_id, S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sns_friend_struct *friend;
	CHAR user_id[SRV_SNS_MAX_LEN_ID] = {0};
	U32 i;
	CHAR *bitmask;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sns_get_item2(list_id, (S16)index, (void **)&friend) >= 0)
    {
        memcpy(user_id, (CHAR*)friend->user.user_id, (U32)friend->user.user_id_len);
	    for (i = 0; i < MMI_PHB_SNS_FAVORITE_MAX_NUM; i++)
	    {
		    bitmask = g_mmi_phb_list_p->sns_favorite[i];
		    if (*bitmask && !mmi_ucs2cmp(user_id, bitmask))
		    {
			    return MMI_TRUE;
		    }
	    }
    }
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_enrty_get_favorite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_enrty_reset_favorite(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < list_favorite->favorite_count; i++)
    {
        memset(g_mmi_phb_list_p->sns_favorite[i], 0, sizeof(CHAR) * SRV_SNS_MAX_LEN_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_favorite_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_favorite_op(mmi_phb_sns_list_enum list_type, MMI_BOOL is_add)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sns_user_list_struct *user_list;
	mmi_phb_sns_friend_list_struct *friend_list = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *favorite_list = g_mmi_phb_list_p->sns_favorite_list;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (favorite_list->favorite_count == MMI_PHB_SNS_FAVORITE_MAX_NUM && is_add)
    {
        mmi_phb_popup_display_ext(
            STR_ID_PHB_SNS_FAVORITE_FULL,
            MMI_EVENT_FAILURE);
        return;
    }
    
	user_list = (srv_sns_user_list_struct *)mmi_phb_mem_malloc(sizeof(srv_sns_user_list_struct), SRV_PHB_MEMORY_TYPE_CTR);
    memset(user_list, 0, sizeof(srv_sns_user_list_struct));
	if (MMI_PHB_SNS_LIST_FRIEND == list_type)
	{
		srv_sns_edit_user_list(user_list, 1, friend_list->list_id, friend_list->highlight_index, MMI_TRUE);
		friend_list->user = user_list;
		srv_sns_release_list(favorite_list->list_id, MMI_FALSE);
		if (MMI_TRUE == is_add)
		{
		    friend_list->state = MMI_PHB_SNS_STATE_ADD;	
            srv_sns_modify_group_member(SRV_SNS_SELECTED_FRIENDS_GROUP_ID, user_list, 1, MMI_TRUE, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_ADD);
		}
		else
		{
			friend_list->state = MMI_PHB_SNS_STATE_REMOVE;
			srv_sns_modify_group_member(SRV_SNS_SELECTED_FRIENDS_GROUP_ID, user_list, 1, MMI_FALSE, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_REMOVE);
		}
	}
	else
	{
		srv_sns_edit_user_list(user_list, 1, favorite_list->list_id, favorite_list->highlight_index, MMI_TRUE);
		favorite_list->user = user_list;
		favorite_list->state = MMI_PHB_SNS_STATE_REMOVE;
		srv_sns_release_list(favorite_list->list_id, MMI_FALSE);
		srv_sns_modify_group_member(SRV_SNS_SELECTED_FRIENDS_GROUP_ID, user_list, 1, MMI_FALSE, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_REMOVE);
	}
	mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
}


#if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_friend_list_bar_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_friend_list_bar_callback(S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phb_sns_friend_list_struct *list_info = g_mmi_phb_list_p->sns_friend_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
        case MMI_PHB_SNS_FAVORITE:
			if (mmi_phb_sns_enrty_get_favorite(list_info->list_id, list_info->highlight_index))
			{
				/* remove favorite */
				mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FRIEND, MMI_FALSE);
			}
			else
			{
				/* add favorite */
				mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FRIEND, MMI_TRUE);
			}
			break;
			
		case MMI_PHB_SNS_MESSAGE:
			mmi_phb_sns_entry_send_msg(MMI_PHB_SNS_LIST_FRIEND);
			break;
			
		default:
			MMI_ASSERT(0);
			break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_favorite_list_bar_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_favorite_list_bar_callback(S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
        case MMI_PHB_SNS_FAVORITE:
			/* remove favorite */
			mmi_phb_sns_favorite_op(MMI_PHB_SNS_LIST_FAVORITE, MMI_FALSE);
			break;
			
		case MMI_PHB_SNS_MESSAGE:
			mmi_phb_sns_entry_send_msg(MMI_PHB_SNS_LIST_FAVORITE);
			break;
			
		default:
			MMI_ASSERT(0);
			break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_list_bar_twitter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_list_bar_twitter(mmi_phb_sns_list_enum list_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
	/*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;
    srv_sns_friend_struct *friend;
    MMI_BOOL is_get_data = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_PHB_SNS_LIST_FRIEND == list_type)
	{
        if (srv_sns_get_item2(list_friend->list_id, (S16)list_friend->highlight_index, (void **)&friend) >= 0)
        {
            is_get_data = MMI_TRUE;    
        }  
	}
    else if (MMI_PHB_SNS_LIST_FAVORITE == list_type)
    {  
        if (srv_sns_get_item2(list_favorite->list_id, (S16)list_favorite->highlight_index, (void **)&friend) >= 0)
        {
            is_get_data = MMI_TRUE; 
        }                 
    }

    if (is_get_data)
    {
        if (SRV_SNS_PROVIDER_TWITTER == friend->user.provider)
        {
            wgui_icon_bar_set_item_enable_state(MMI_PHB_SNS_MESSAGE, MMI_FALSE);        
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_list_bar_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_list_bar_update(MMI_BOOL displayable, mmi_phb_sns_list_enum list_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
	/*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_FALSE == displayable)
	{
		wgui_icon_bar_set_item_enable_state(MMI_PHB_SNS_FAVORITE, MMI_FALSE);
    	wgui_icon_bar_set_item_enable_state(MMI_PHB_SNS_MESSAGE, MMI_FALSE);
	}
    else
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_SNS_FAVORITE, MMI_TRUE);
        wgui_icon_bar_set_item_enable_state(MMI_PHB_SNS_MESSAGE, MMI_TRUE);
        mmi_phb_sns_list_bar_twitter(list_type);                
    }
	wgui_icon_bar_update();
}
#endif


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_list_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
    	if (mmi_phb_sns_is_scrn_active(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_TAB0))
    	{
    		/* view friend item */
    		mmi_phb_sns_entry_view_member(MMI_PHB_SNS_LIST_FRIEND);
    	}
    	else if (mmi_phb_sns_is_scrn_active(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_TAB1))
    	{
    		/* view favorite item */
    		mmi_phb_sns_entry_view_member(MMI_PHB_SNS_LIST_FAVORITE);
    	}
    }
}
#endif


#ifndef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_friend_find_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_friend_find_entry(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (!mmi_phb_sns_list_ready())
	{
		if (0 == list_friend->search_buffer[0])
		{
			ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_DOWN);
		}
		return;
	}
	
    if (0 == list_friend->search_buffer[0])
    {   
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
		SetLeftSoftkeyFunction(mmi_phb_sns_entry_friend_option, KEY_EVENT_UP);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_DOWN);
		
        if (list_friend->is_search == MMI_TRUE)
        {
            list_friend->is_search = MMI_FALSE;
			list_friend->search_temp_buffer[0] = 0;
            mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
            srv_sns_release_list(list_friend->list_id, MMI_FALSE);
            mmi_phb_sns_search_filter();
            srv_sns_load_list(list_friend->list_id, 0, mmi_phb_sns_load_friend_list_callback, (void *)MMI_PHB_SNS_STATE_READY);
            mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FRIEND);
        }
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
        SetLeftSoftkeyFunction(mmi_phb_sns_search_friend_handler, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_favorite_find_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_favorite_find_entry(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (!mmi_phb_sns_list_ready())
	{
		if (0 == list_favorite->search_buffer[0])
		{
			ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_DOWN);
		}
		return;
	}
	
    if (0 == list_favorite->search_buffer[0])
    { 
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
		SetLeftSoftkeyFunction(mmi_phb_sns_entry_favorite_option, KEY_EVENT_UP);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_DOWN);
		
        if (list_favorite->is_search == MMI_TRUE)
        {
            list_favorite->is_search = MMI_FALSE;
			list_favorite->search_temp_buffer[0] = 0;
            mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
            srv_sns_release_list(list_favorite->list_id, MMI_FALSE);
            list_favorite->list_id = srv_sns_get_friends_by_group(SRV_SNS_SELECTED_FRIENDS_GROUP_ID);
            srv_sns_load_list(list_favorite->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_READY); 
			mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FAVORITE);
        }
    }
	else
	{
    	ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
    	SetLeftSoftkeyFunction(mmi_phb_sns_search_favorite_handler, KEY_EVENT_UP);
	}
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_get_link_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static PU8 mmi_phb_sns_get_link_icon(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 ret = NULL;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_sns_is_ready())
    {
    #if defined(__MMI_PHB_QUICK_SEARCH__)
        if (g_mmi_phb_list_p->qsearch_input_buffer[0])     
        {
            if (mmi_phb_sns_is_linked(g_mmi_phb_list_p->contact_array[item_index]))
            {
                ret = (PU8)GetImage(IMG_ID_PHB_SNS_MARK_LINK);
            }
        }
        else
    #endif
        {
            if (item_index > 0 && mmi_phb_sns_is_linked(g_mmi_phb_list_p->contact_array[item_index - 1]))
            {
                ret = (PU8)GetImage(IMG_ID_PHB_SNS_MARK_LINK);
            }
        }
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_get_favorite_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static PU8 mmi_phb_sns_get_favorite_icon(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_info = g_mmi_phb_list_p->sns_friend_list;
    PU8 ret = NULL;
    S16 check_start_index, check_end_index;
    U16 check_total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_sns_list_ready()
        && srv_sns_check_list(list_info->list_id, &check_start_index, &check_end_index, &check_total)
        )
    {  
        if (mmi_phb_sns_enrty_get_favorite(list_info->list_id, item_index))
        {
            ret = (PU8)GetImage(IMG_ID_SNS_FAVORITE_MARK);
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_friend_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_phb_sns_friend_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
    S16 index;
	mmi_phb_sns_friend_list_struct *list_info = g_mmi_phb_list_p->sns_friend_list;
    srv_sns_friend_struct *friend;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < data_size; i++)
    {
    	index = (S16)(item_index + i);
        
    	if(srv_sns_get_item2(list_info->list_id, index, (void **)&friend) >=0)
		{
        	mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[0], (CHAR*)friend->user.user_name, MAX_SUBMENU_CHARACTERS);
            menu_data[i].image_list[0] = (PU8)get_image(IMG_ID_PHB_SNS_DEFAULT);
		}
		else
    	{
        	mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[0], (CHAR*)GetString(STR_GLOBAL_LOADING), MAX_SUBMENU_CHARACTERS);
			menu_data[i].image_list[0] = NULL;
            if (MMI_PHB_SNS_STATE_IDLE == list_info->state 
                && mmi_phb_sns_list_ready()
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                && !gui_screen_smooth_scrolling_moved_by_pen()
            #endif 
                )
            {
                list_info->state = MMI_PHB_SNS_STATE_RELOAD;
                srv_sns_load_list(list_info->list_id, index, mmi_phb_sns_load_friend_list_callback, (void *)MMI_PHB_SNS_STATE_RELOAD);
	        }
    	}	
    }

    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_favorite_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_phb_sns_favorite_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S16 index;
    mmi_phb_sns_favorite_list_struct *list_info = g_mmi_phb_list_p->sns_favorite_list;
    srv_sns_friend_struct *friend;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < data_size; i++)
    {
    	index = (S16)(item_index + i);
	
    	if (srv_sns_get_item2(list_info->list_id, index, (void **)&friend) >= 0)
	    {
            mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[0], (CHAR*)friend->user.user_name, MAX_SUBMENU_CHARACTERS);
	        menu_data[i].image_list[0] = (PU8)get_image(IMG_ID_PHB_SNS_DEFAULT);
	    }
	    else
    	{
            mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[0], (CHAR*)GetString(STR_GLOBAL_LOADING), MAX_SUBMENU_CHARACTERS);
	        menu_data[i].image_list[0] = NULL;
            if (MMI_PHB_SNS_STATE_IDLE == list_info->state 
                && mmi_phb_sns_list_ready()
            #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
                && !gui_screen_smooth_scrolling_moved_by_pen()
            #endif 
                )
            {
                list_info->state = MMI_PHB_SNS_STATE_RELOAD;
                srv_sns_load_list(list_info->list_id, index, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_RELOAD);
	        }   
    	}
    }
	
    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_check_friend_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_check_friend_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
	mmi_phb_sns_friend_list_struct *list_info = g_mmi_phb_list_p->sns_friend_list;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
	if (!list_info->search_buffer[0])
	{
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_sns_entry_friend_option, KEY_EVENT_UP);
	}
	else
	{
		ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
        SetLeftSoftkeyFunction(mmi_phb_sns_search_friend_handler, KEY_EVENT_UP);
	}
#else
	ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(mmi_phb_sns_entry_friend_option, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_check_favorite_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_check_favorite_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
	mmi_phb_sns_favorite_list_struct *list_info = g_mmi_phb_list_p->sns_favorite_list;
#endif
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
	if (!list_info->search_buffer[0])
	{
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_sns_entry_favorite_option, KEY_EVENT_UP);
	}
	else
	{
		ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
        SetLeftSoftkeyFunction(mmi_phb_sns_search_favorite_handler, KEY_EVENT_UP);
	}
#else
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(mmi_phb_sns_entry_favorite_option, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_highlight_friend_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_highlight_friend_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_info = g_mmi_phb_list_p->sns_friend_list;
    srv_sns_friend_struct *friend;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_info->highlight_index = item_index;

    if (!mmi_phb_sns_list_ready())
    {
    #if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
        mmi_phb_sns_list_bar_update(MMI_FALSE, MMI_PHB_SNS_LIST_FRIEND);
    #endif
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0); 
    }
    else if (srv_sns_get_item2(list_info->list_id, (S16)item_index, (void **)&friend) < 0)
    {
    #if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
	    mmi_phb_sns_list_bar_update(MMI_FALSE, MMI_PHB_SNS_LIST_FRIEND);
    #endif
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0); 
    }
    else
    {
    #if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
        mmi_phb_sns_list_bar_update(MMI_TRUE, MMI_PHB_SNS_LIST_FRIEND);
    #endif
		mmi_phb_sns_check_friend_softkey();
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_sns_center_key_handler, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_highlight_favorite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_highlight_favorite_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_favorite_list_struct *list_info = g_mmi_phb_list_p->sns_favorite_list;
    srv_sns_friend_struct *friend;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_info->highlight_index = item_index;

    if (!mmi_phb_sns_list_ready())
    {
    #if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
        mmi_phb_sns_list_bar_update(MMI_FALSE, MMI_PHB_SNS_LIST_FAVORITE);
    #endif
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0); 
    }
    else if (srv_sns_get_item2(list_info->list_id, (S16)item_index, (void **)&friend) < 0)
    {
    #if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
	    mmi_phb_sns_list_bar_update(MMI_FALSE, MMI_PHB_SNS_LIST_FAVORITE);
    #endif
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0); 
    }
    else
    {
    #if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
        mmi_phb_sns_list_bar_update(MMI_TRUE, MMI_PHB_SNS_LIST_FAVORITE);
    #endif
		mmi_phb_sns_check_favorite_softkey();
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_sns_center_key_handler, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_center_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_center_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *friend_list = g_mmi_phb_list_p->sns_friend_list;
    mmi_phb_sns_favorite_list_struct *favorite_list = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_sns_is_scrn_active(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_TAB0))
    {
    #ifndef __MMI_TOUCH_SCREEN__
        if (friend_list->search_buffer[0])
        {
            mmi_phb_sns_search_friend_handler();
        }
        else
    #endif
        {
            if (friend_list->is_group && !friend_list->total)
            {
                mmi_phb_sns_entry_friend_option();        
            }
            else
            {
                mmi_phb_sns_entry_view_member(MMI_PHB_SNS_LIST_FRIEND);
            }
        }
    }
    else if (mmi_phb_sns_is_scrn_active(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_TAB1))
    {
    #ifndef __MMI_TOUCH_SCREEN__
        if (favorite_list->search_buffer[0])
        {
            mmi_phb_sns_search_favorite_handler();
        }
        else
    #endif
        {
	        mmi_phb_sns_entry_view_member(MMI_PHB_SNS_LIST_FAVORITE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_search_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_search_friend_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_sns_list_ready())
    {
        if (0 != list_friend->search_buffer[0] && list_friend->is_search == MMI_FALSE && list_friend->total)
        {
            list_friend->is_search = MMI_TRUE;
            mmi_wcscpy(list_friend->search_temp_buffer, list_friend->search_buffer);
            mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
            srv_sns_search_friends(list_friend->list_id, list_friend->search_buffer, (void*)MMI_PHB_SNS_STATE_SEARCH);
            mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FRIEND);
        }
        else if (0 == list_friend->search_buffer[0] && list_friend->is_search == MMI_TRUE)
        {
            list_friend->is_search = MMI_FALSE;
            list_friend->search_temp_buffer[0] = 0;
            mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
            srv_sns_release_list(list_friend->list_id, MMI_FALSE);
            mmi_phb_sns_search_filter();
            srv_sns_load_list(list_friend->list_id, 0, mmi_phb_sns_load_friend_list_callback, (void *)MMI_PHB_SNS_STATE_READY);
            mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FRIEND);
        }
        else if (mmi_wcscmp(list_friend->search_buffer, list_friend->search_temp_buffer) && list_friend->is_search == MMI_TRUE)
        {
            mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
            mmi_wcscpy(list_friend->search_temp_buffer, list_friend->search_buffer);
            srv_sns_release_list(list_friend->list_id, MMI_FALSE);
            mmi_phb_sns_search_filter();
            srv_sns_load_list(list_friend->list_id, 0, mmi_phb_sns_load_friend_list_callback, (void *)MMI_PHB_SNS_STATE_RESEARCH);
            mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FRIEND);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_search_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_search_favorite_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_sns_list_ready())
    {
        if (0 != list_favorite->search_buffer[0] && list_favorite->is_search == MMI_FALSE && list_favorite->total)
        {
            list_favorite->is_search = MMI_TRUE;
            mmi_wcscpy(list_favorite->search_temp_buffer, list_favorite->search_buffer);
            mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
            srv_sns_search_friends(list_favorite->list_id, list_favorite->search_buffer, (void*)MMI_PHB_SNS_STATE_SEARCH);
            mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FAVORITE);
        }
        else if (0 == list_favorite->search_buffer[0] && list_favorite->is_search == MMI_TRUE)
        {
            list_favorite->is_search = MMI_FALSE;
            list_favorite->search_temp_buffer[0] = 0;
            mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
            srv_sns_release_list(list_favorite->list_id, MMI_FALSE);
            list_favorite->list_id = srv_sns_get_friends_by_group(SRV_SNS_SELECTED_FRIENDS_GROUP_ID);
            srv_sns_load_list(list_favorite->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_READY);
            mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FAVORITE);
        }
        else if (mmi_wcscmp(list_favorite->search_buffer, list_favorite->search_temp_buffer) && list_favorite->is_search == MMI_TRUE)
        {
            mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
            mmi_wcscpy(list_favorite->search_temp_buffer, list_favorite->search_buffer);
            srv_sns_release_list(list_favorite->list_id, MMI_FALSE);
            list_favorite->list_id = srv_sns_get_friends_by_group(SRV_SNS_SELECTED_FRIENDS_GROUP_ID);
            srv_sns_load_list(list_favorite->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_RESEARCH);
            mmi_phb_sns_gui_buffer_clear(MMI_PHB_SNS_LIST_FAVORITE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_entry_friend_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_entry_friend_option(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID menu_gid;
	mmi_phb_sns_friend_list_struct *list_info = g_mmi_phb_list_p->sns_friend_list;
#ifdef __MMI_SNS_MESSAGES__
    srv_sns_friend_struct *friend;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
    	GRP_ID_PHB_MAIN,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_PHB_SNS_FRIEND_OPTION,
        MMI_FALSE, NULL);

    if (list_info->is_group && !list_info->total)
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_FRIEND_ADD_FAVORITE, MMI_TRUE); 	
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_FRIEND_REMOVE_FAVORITE, MMI_TRUE); 	
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_FRIEND_VIEW, MMI_TRUE);
    #ifdef __MMI_SNS_MESSAGES__
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_FRIEND_DIRECT_MESSAGE, MMI_TRUE);
    #endif
    }
    else
    {
    	if (mmi_phb_sns_enrty_get_favorite(list_info->list_id, list_info->highlight_index))
    	{
    		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_FRIEND_ADD_FAVORITE, MMI_TRUE); 	
    	}
    	else
    	{
    		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_FRIEND_REMOVE_FAVORITE, MMI_TRUE); 	
    	}

    #ifdef __MMI_SNS_MESSAGES__
        if (srv_sns_get_item2(list_info->list_id, (S16)list_info->highlight_index, (void **)&friend) >= 0)
        {
            if (SRV_SNS_PROVIDER_TWITTER == friend->user.provider)
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_FRIEND_DIRECT_MESSAGE, MMI_TRUE);
            }
        }
    #endif
    }

	cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_entry_favorite_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_entry_favorite_option(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID menu_gid;
#ifdef __MMI_SNS_MESSAGES__
    mmi_phb_sns_favorite_list_struct *list_info = g_mmi_phb_list_p->sns_favorite_list;
    srv_sns_friend_struct *friend;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
	menu_gid = cui_menu_create(
    	GRP_ID_PHB_MAIN,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_PHB_SNS_FAVORITE_OPTION,
        MMI_FALSE, NULL);

#ifdef __MMI_SNS_MESSAGES__
    if (srv_sns_get_item2(list_info->list_id, (S16)list_info->highlight_index, (void **)&friend) >= 0)
    {
        if (SRV_SNS_PROVIDER_TWITTER == friend->user.provider)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SNS_FAVORITE_DIRECT_MESSAGE, MMI_TRUE);
        }
    }
#endif
    
	cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_set_friend_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_set_list_cntx(srv_sns_evt_list_updated_struct *evt, mmi_phb_sns_list_enum list)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_PHB_SNS_LIST_FRIEND == list)
	{
		list_friend->list_id = evt->list_id;
		list_friend->start_index = evt->start_index;
		list_friend->end_index = evt->end_index;
		list_friend->total = evt->total;
	}
	else
	{
		list_favorite->list_id = evt->list_id;
		list_favorite->start_index = evt->start_index;
		list_favorite->end_index = evt->end_index;
		list_favorite->total = evt->total;
	}
}


void mmi_phb_sns_entry_list_refresh(mmi_phb_sns_state_enum state, mmi_phb_sns_list_enum type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (state)
	{
		case MMI_PHB_SNS_STATE_RELOAD:
    #ifdef __MMI_UI_LIST_SMOOTH_SCROLLING_BY_PEN__
            if (!gui_screen_smooth_scrolling_moved_by_pen())
    #endif 
            {
                RedrawCategoryFunction();
            }
            if (MMI_PHB_SNS_LIST_FRIEND == type)
            {
                list_friend->state = MMI_PHB_SNS_STATE_IDLE;
            }
            else if (MMI_PHB_SNS_LIST_FAVORITE == type)
            {  
                list_favorite->state = MMI_PHB_SNS_STATE_IDLE;
            }
            break;
            
        case MMI_PHB_SNS_STATE_SEARCH:
            mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_PROGRESS);
            break;
            
		case MMI_PHB_SNS_STATE_ADD:
	 	case MMI_PHB_SNS_STATE_REMOVE:
            if (list_friend->is_group)
            {
                if (mmi_phb_sns_list_ready())
                {
                    mmi_phb_sns_search_clear(MMI_PHB_SNS_LIST_FRIEND);
                    mmi_phb_sns_search_clear(MMI_PHB_SNS_LIST_FAVORITE);
			        mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_PROGRESS);
                }
            }
            else
            {
                mmi_phb_sns_search_clear(MMI_PHB_SNS_LIST_FAVORITE);
                mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_PROGRESS);    
            }
			break;

		default:
			break;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_logout_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_sns_logout_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_account_logged_out_struct *list_invalid_evt = (srv_sns_evt_account_logged_out_struct *)evt;
    mmi_sns_account_logout_struct account;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    account.gid = GRP_ID_PHB_MAIN;
    account.provider = list_invalid_evt->provider;
    account.lsk = mmi_frm_scrn_close_active_id;

    mmi_sns_misc_account_logout_scrn(&account);

    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_list_not_ready_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_sns_list_not_ready_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_ready_struct *ready = (srv_sns_evt_ready_struct *)evt;
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ready->is_ready)
    {
        if (list_friend)
        {
            srv_sns_release_list(list_friend->list_id, MMI_TRUE);
            list_friend->list_id = 0;
            list_friend->is_valid = MMI_FALSE;
            list_friend->state = MMI_PHB_SNS_STATE_IDLE;
        }
        if (list_favorite)
        {
            srv_sns_release_list(list_favorite->list_id, MMI_TRUE);
            list_favorite->list_id = 0;
            list_favorite->is_valid = MMI_FALSE;
            list_favorite->state = MMI_PHB_SNS_STATE_IDLE;
            mmi_phb_sns_enrty_reset_favorite();
        }
        mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_PROGRESS);
        mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_QUERY);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_unload_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_sns_unload_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_plugins_unloaded_struct *unload = (srv_sns_evt_plugins_unloaded_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_SNS_OK == unload->result)
    {
        mmi_frm_group_close(GRP_ID_PHB_MAIN);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_list_image_updated_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_phb_sns_image_updated_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;   
    srv_sns_evt_item_updated_struct *item_updated = (srv_sns_evt_item_updated_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_sns_list_ready()) 
    {
        if (mmi_phb_sns_is_scrn_active(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_TAB0) 
            && item_updated->pic_state != SRV_SNS_PIC_DOWNLOADING
            && list_friend->list_id == item_updated->list_id
            )
        {
            if (item_updated->index == list_friend->start_index ||
                item_updated->index == list_friend->end_index ||
                item_updated->index % 5 == 0)
            {
                mmi_phb_sns_entry_list_refresh(MMI_PHB_SNS_STATE_RELOAD, MMI_PHB_SNS_LIST_FRIEND);
            }
        }
        else if (mmi_phb_sns_is_scrn_active(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_TAB1) 
            && item_updated->pic_state != SRV_SNS_PIC_DOWNLOADING
            && list_favorite->list_id == item_updated->list_id
            )
        {
            if (item_updated->index == list_favorite->start_index ||
                item_updated->index == list_favorite->end_index ||
                item_updated->index % 5 == 0)
            {
                mmi_phb_sns_entry_list_refresh(MMI_PHB_SNS_STATE_RELOAD, MMI_PHB_SNS_LIST_FAVORITE);   
            }
        }
    }
    
    return MMI_RET_OK;
}


static void mmi_phb_sns_exit_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sns_util_logout_event_registry(MMI_FALSE, mmi_phb_sns_logout_proc, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_ITEM_UPDATED, mmi_phb_sns_image_updated_proc, NULL);
}


mmi_ret mmi_phb_sns_scrn_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_list_not_ready_proc, NULL);
            if(g_mmi_phb_sns_misc.sns_cui_link)
            {
                mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_link_not_ready_proc, (void *)g_mmi_phb_sns_misc.sns_cui_link);
                g_mmi_phb_sns_misc.sns_cui_link = GRP_ID_INVALID;
            }
            if(g_mmi_phb_sns_misc.sns_cui_filter)
            {
                mmi_frm_cb_dereg_event(EVT_ID_SRV_SNS_READY, mmi_phb_sns_filter_not_ready_proc, (void *)g_mmi_phb_sns_misc.sns_cui_filter); 
                g_mmi_phb_sns_misc.sns_cui_filter = GRP_ID_INVALID;
            }

            if (g_mmi_phb_sns_misc.is_parse_image[0])
            {
                if (g_mmi_phb_sns_misc.image_buffer[0].buf_ptr)
                {
                    applib_asm_free_anonymous(g_mmi_phb_sns_misc.image_buffer[0].buf_ptr);    
                }
                g_mmi_phb_sns_misc.image_buffer[0].buf_ptr = NULL;
                g_mmi_phb_sns_misc.is_parse_image[0] = MMI_FALSE;
            }

            if (g_mmi_phb_sns_misc.is_parse_image[1])
            {
                if (g_mmi_phb_sns_misc.image_buffer[1].buf_ptr)
                {
                    applib_asm_free_anonymous(g_mmi_phb_sns_misc.image_buffer[1].buf_ptr);    
                }
                g_mmi_phb_sns_misc.image_buffer[1].buf_ptr = NULL;
                g_mmi_phb_sns_misc.is_parse_image[1] = MMI_FALSE;
            }

            if (g_mmi_phb_sns_misc.is_parse_image[2])
            {
                if (g_mmi_phb_sns_misc.image_buffer[2].buf_ptr)
                {
                    applib_asm_free_anonymous(g_mmi_phb_sns_misc.image_buffer[2].buf_ptr);    
                }
                g_mmi_phb_sns_misc.image_buffer[2].buf_ptr = NULL;               
                g_mmi_phb_sns_misc.is_parse_image[2] = MMI_FALSE;
            }
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_set_friend_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_set_friend_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
	mmi_phb_sns_friend_list_struct *list_info = g_mmi_phb_list_p->sns_friend_list;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
	if (mmi_phb_sns_list_ready())
	{
		if (list_info->search_buffer[0])
		{
			ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
			SetLeftSoftkeyFunction(mmi_phb_sns_search_friend_handler, KEY_EVENT_UP);
		}
		else
		{
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
			SetLeftSoftkeyFunction(mmi_phb_sns_entry_friend_option, KEY_EVENT_UP);
		}
		SetCenterSoftkeyFunction(mmi_phb_sns_center_key_handler, KEY_EVENT_UP);
	}
	else
	{
		ChangeLeftSoftkey(0, 0);
		ChangeCenterSoftkey(0, 0); 
	}
#else
	SetLeftSoftkeyFunction(mmi_phb_sns_entry_friend_option, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_phb_sns_center_key_handler, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_set_favorite_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_set_favorite_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
	mmi_phb_sns_favorite_list_struct *list_info = g_mmi_phb_list_p->sns_favorite_list;
#endif
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
	if (mmi_phb_sns_list_ready())
	{
		if (list_info->search_buffer[0])
		{
			ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
			SetLeftSoftkeyFunction(mmi_phb_sns_search_favorite_handler, KEY_EVENT_UP);
		}
		else
		{
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
			SetLeftSoftkeyFunction(mmi_phb_sns_entry_favorite_option, KEY_EVENT_UP);
		}
		SetCenterSoftkeyFunction(mmi_phb_sns_center_key_handler, KEY_EVENT_UP);
	}
	else
	{
		ChangeLeftSoftkey(0, 0);
		ChangeCenterSoftkey(0, 0); 
	}
#else
	SetLeftSoftkeyFunction(mmi_phb_sns_entry_favorite_option, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_phb_sns_center_key_handler, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_show_sns_friend_list_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_show_friend_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    mmi_phb_sns_friend_list_struct *list_info = g_mmi_phb_list_p->sns_friend_list;
#if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
	S32 item_count = MMI_PHB_SNS_TAB_TOOLBAR_ENUM_TOTAL;
    PU8 item_icon[MMI_PHB_SNS_TAB_TOOLBAR_ENUM_TOTAL];
    PU8 item_disable_icon[MMI_PHB_SNS_TAB_TOOLBAR_ENUM_TOTAL];
    PU8 string[MMI_PHB_SNS_TAB_TOOLBAR_ENUM_TOTAL];
#endif
    U8 tab_index = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            GRP_ID_PHB_MAIN,
            SCR_ID_PHB_SNS_TAB0,
            mmi_phb_sns_exit_list,
            mmi_phb_sns_entry_friend_list,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
		GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        SCR_ID_PHB_SNS_TAB0,
 		mmi_phb_sns_exit_list,
        mmi_phb_sns_entry_friend_list,
        MMI_FRM_TAB_PAGE))
    #endif
    {
    	return;
    }

    mmi_sns_util_logout_event_registry(MMI_TRUE, mmi_phb_sns_logout_proc, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_ITEM_UPDATED, mmi_phb_sns_image_updated_proc, NULL);

	gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!gui_buffer)
	   {
	   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_PBOOK_MAIN_MENU,SCR_ID_PHB_SNS_TAB0);
	   	}
   #endif
	RegisterHighlightHandler(mmi_phb_sns_highlight_friend_handler);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat199_setup_search_button(get_image(IMG_ID_PHB_SNS_SEARCH), get_image(IMG_ID_PHB_SNS_SEARCH_PRESSED), mmi_phb_sns_search_friend_handler);   
#endif
	if (gui_buffer == NULL)
	{
		list_info->highlight_index = 0;
	}
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	wgui_cat199_register_get_attachment_icon_callback(mmi_phb_sns_get_favorite_icon);
    wgui_cat199_register_get_attachment_icon_filepath_callback(mmi_phb_sns_friend_get_provider_image);

#if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
	item_icon[MMI_PHB_SNS_FAVORITE] = get_image(IMG_ID_PHB_SNS_TOOLBAR_FAVORITE);
	item_icon[MMI_PHB_SNS_MESSAGE] = get_image(IMG_ID_PHB_SNS_TOOLBAR_SEND_MESSAGE);
	item_disable_icon[MMI_PHB_SNS_FAVORITE] = get_image(IMG_ID_PHB_SNS_TOOLBAR_FAVORITE_DIS);
	item_disable_icon[MMI_PHB_SNS_MESSAGE] = get_image(IMG_ID_PHB_SNS_TOOLBAR_SEND_MESSAGE_DIS);
	string[MMI_PHB_SNS_FAVORITE] = (PU8)get_string(STR_ID_PHB_SNS_FAVORITE);
	string[MMI_PHB_SNS_MESSAGE] = (PU8)get_string(STR_ID_SNS_DM);
	wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, string, (GUIIconbarItemCallback)mmi_phb_sns_friend_list_bar_callback);
    if (list_info->total)
    {
        mmi_phb_sns_list_bar_update(MMI_TRUE, MMI_PHB_SNS_LIST_FRIEND);
    }
    else
    {
        mmi_phb_sns_list_bar_update(MMI_FALSE, MMI_PHB_SNS_LIST_FRIEND);
    }
#endif

    if (list_info->is_clear)
    {
        gui_buffer = NULL;
        list_info->is_clear = MMI_FALSE;
    }

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
	mmi_phb_thumbnail_reset_displayable();
	wgui_thumbnail_register_get_image_path_func(mmi_phb_sns_thumbnail_get_image_path);
	wgui_thumbnail_register_set_displayable_func(mmi_phb_sns_thumbnail_set_displayable);
	wgui_thumbnail_register_get_displayable_func(mmi_phb_sns_thumbnail_get_displayable);
	wgui_thumbnail_register_get_image_info_func(mmi_phb_sns_thumbnail_get_menuitem_info);
	wgui_thumbnail_register_get_store_id_func(mmi_phb_sns_thumbnail_get_store_id);
#endif

    wgui_cat199_register_get_attachment_icon_buffer_callback(mmi_phb_sns_friend_cache_provider_image);
#ifdef __MMI_PHB_CALLER_GROUP__
	tab_index = 2;
#else
	tab_index = 1;
#endif

	wgui_cat1061_show(
		(UI_string_type)GetString(STR_GLOBAL_OPTIONS),
	    (UI_string_type)GetString(STR_GLOBAL_BACK),
		//2,   
		tab_index,
	    (UI_string_type)GetString(STR_ID_PHB_SNS_FRIEND_CAPTION),
	    NULL,
	    list_info->total,
	   	mmi_phb_sns_friend_list_get_item,
	    NULL,
	    NULL,
	    NULL,
	    list_info->highlight_index,
	    get_image(IMG_ID_PHB_SNS_DEFAULT),
	    get_image(IMG_STORAGE_SIM),
	    (U8*)list_info->search_buffer,
	    SRV_SNS_MAX_LEN_NAME,
	    gui_buffer);
      
#ifdef __MMI_TOUCH_SCREEN__
	wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
    wgui_inputs_register_empty_func(mmi_phb_sns_search_friend_handler);
#else
    wgui_inputs_sl_register_input_callback(mmi_phb_sns_friend_find_entry);    
#endif /* __MMI_TOUCH_SCREEN__ */

	mmi_phb_sns_set_friend_softkey();
	
    if (0 == list_info->total)
    {
        if (!list_info->is_group)
        {
            ChangeLeftSoftkey(0, 0);
            ChangeCenterSoftkey(0, 0); 
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);    
        }
    }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
	wgui_register_tap_callback(mmi_phb_sns_list_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
	//SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_show_favorite_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_show_favorite_list(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
#if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
	S32 item_count = MMI_PHB_SNS_TAB_TOOLBAR_ENUM_TOTAL;
    PU8 item_icon[MMI_PHB_SNS_TAB_TOOLBAR_ENUM_TOTAL];
    PU8 item_disable_icon[MMI_PHB_SNS_TAB_TOOLBAR_ENUM_TOTAL];
    PU8 string[MMI_PHB_SNS_TAB_TOOLBAR_ENUM_TOTAL];
#endif
	mmi_phb_sns_favorite_list_struct *list_info = g_mmi_phb_list_p->sns_favorite_list;
	U8 tab_index = 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            GRP_ID_PHB_MAIN,
            SCR_ID_PHB_SNS_TAB1,
            mmi_phb_sns_exit_list,
            mmi_phb_sns_entry_favorite_list,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
    	GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        SCR_ID_PHB_SNS_TAB1,
        mmi_phb_sns_exit_list,
        mmi_phb_sns_entry_favorite_list,
        MMI_FRM_TAB_PAGE))
    #endif
    {
    	return;
    }

    mmi_sns_util_logout_event_registry(MMI_TRUE, mmi_phb_sns_logout_proc, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_ITEM_UPDATED, mmi_phb_sns_image_updated_proc, NULL);

	gui_buffer = mmi_frm_scrn_get_active_gui_buf();
  #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!gui_buffer)
	   {
	   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_PBOOK_MAIN_MENU,SCR_ID_PHB_SNS_TAB1);
	   	}
   #endif
	RegisterHighlightHandler(mmi_phb_sns_highlight_favorite_handler);
#ifdef __MMI_TOUCH_SCREEN__
	wgui_cat199_setup_search_button(get_image(IMG_ID_PHB_SNS_SEARCH), get_image(IMG_ID_PHB_SNS_SEARCH_PRESSED), mmi_phb_sns_search_favorite_handler);
#endif
	if (gui_buffer == NULL)
	{
		list_info->highlight_index = 0;
	}	
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    wgui_cat199_register_get_attachment_icon_filepath_callback(mmi_phb_sns_friend_get_provider_image);

#if defined(__MMI_ICON_BAR_SUPPORT__) && defined(__MMI_SNS_MESSAGES__)
	item_icon[MMI_PHB_SNS_FAVORITE] = get_image( IMG_ID_PHB_SNS_TOOLBAR_REMOVE_FAVORITE);
	item_icon[MMI_PHB_SNS_MESSAGE] = get_image(IMG_ID_PHB_SNS_TOOLBAR_SEND_MESSAGE);
	item_disable_icon[MMI_PHB_SNS_FAVORITE] = get_image(IMG_ID_PHB_SNS_TOOLBAR_REMOVE_FAVORITE_DIS);
	item_disable_icon[MMI_PHB_SNS_MESSAGE] = get_image(IMG_ID_PHB_SNS_TOOLBAR_SEND_MESSAGE_DIS);
	string[MMI_PHB_SNS_FAVORITE] = (PU8)get_string(STR_ID_PHB_SNS_REMOVE_FAVORITE);
	string[MMI_PHB_SNS_MESSAGE] = (PU8)get_string(STR_ID_SNS_DM);
	wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, string, (GUIIconbarItemCallback)mmi_phb_sns_favorite_list_bar_callback);
    if (list_info->total)
    {
        mmi_phb_sns_list_bar_update(MMI_TRUE, MMI_PHB_SNS_LIST_FAVORITE);
    }
    else
    {
        mmi_phb_sns_list_bar_update(MMI_FALSE, MMI_PHB_SNS_LIST_FAVORITE);
    }
#endif

    if (list_info->is_clear)
    {
        gui_buffer = NULL;
        list_info->is_clear = MMI_FALSE;
    }

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
	mmi_phb_thumbnail_reset_displayable();
	wgui_thumbnail_register_get_image_path_func(mmi_phb_sns_thumbnail_get_image_path);
	wgui_thumbnail_register_set_displayable_func(mmi_phb_sns_thumbnail_set_displayable);
	wgui_thumbnail_register_get_displayable_func(mmi_phb_sns_thumbnail_get_displayable);
	wgui_thumbnail_register_get_image_info_func(mmi_phb_sns_thumbnail_get_menuitem_info);
	wgui_thumbnail_register_get_store_id_func(mmi_phb_sns_thumbnail_get_store_id);
#endif

    wgui_cat199_register_get_attachment_icon_buffer_callback(mmi_phb_sns_friend_cache_provider_image);

#ifdef __MMI_PHB_CALLER_GROUP__
	tab_index = 3;
#else
	tab_index = 2;
#endif
	wgui_cat1061_show(
		(UI_string_type)GetString(STR_GLOBAL_OPTIONS),
	    (UI_string_type)GetString(STR_GLOBAL_BACK),
		//3,   
		tab_index,
	    (UI_string_type)GetString(STR_ID_PHB_SNS_FAVORITE_CAPTION),
	    NULL,
	    list_info->total,
	    mmi_phb_sns_favorite_list_get_item,
	    NULL,
	    NULL,
	    NULL,
	    list_info->highlight_index,
	    get_image(IMG_ID_PHB_SNS_DEFAULT),
	    get_image(IMG_STORAGE_SIM),
	    (U8*) list_info->search_buffer,
	    SRV_SNS_MAX_LEN_NAME,
	    gui_buffer);

#ifdef __MMI_TOUCH_SCREEN__
	wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
    wgui_inputs_register_empty_func(mmi_phb_sns_search_favorite_handler);
#else
    wgui_inputs_sl_register_input_callback(mmi_phb_sns_favorite_find_entry);
#endif /* __MMI_TOUCH_SCREEN__ */

	mmi_phb_sns_set_favorite_softkey();

    if (0 == list_info->total)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0); 
    }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_sns_list_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
	//SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	//SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_callback_state_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_callback_state_refresh(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sns_evt_list_updated_struct *evt;
	mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
	evt = (srv_sns_evt_list_updated_struct *)param;
    
	if (list_friend->state == MMI_PHB_SNS_STATE_ADD)
	{
		list_favorite->favorite_count++;
	    mmi_phb_sns_entry_set_favorite(list_friend->user->user_id, MMI_TRUE, 0);
	    mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FAVORITE);
		mmi_phb_mem_free(list_friend->user);
		list_friend->state = MMI_PHB_SNS_STATE_IDLE;
	}
	else if (list_friend->state == MMI_PHB_SNS_STATE_REMOVE)
	{
		list_favorite->favorite_count--;
		mmi_phb_sns_entry_set_favorite(list_friend->user->user_id, MMI_FALSE, 0);
		mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FAVORITE);
		mmi_phb_mem_free(list_friend->user);
		list_friend->state = MMI_PHB_SNS_STATE_IDLE;
	}	
	else if (list_favorite->state == MMI_PHB_SNS_STATE_REMOVE)
	{
		list_favorite->favorite_count--;
	    mmi_phb_sns_entry_set_favorite(list_favorite->user->user_id, MMI_FALSE, 0);
		mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FAVORITE);
		mmi_phb_mem_free(list_favorite->user);
		list_favorite->state = MMI_PHB_SNS_STATE_IDLE;
	}

    list_favorite->is_valid = MMI_TRUE;
    mmi_phb_sns_entry_list_refresh(MMI_PHB_SNS_STATE_ADD, MMI_PHB_SNS_LIST_FAVORITE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_callback_state_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_callback_state_prepare(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sns_evt_list_updated_struct *evt;
	srv_sns_friend_struct *friend;
	S32 index;
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
	evt = (srv_sns_evt_list_updated_struct *)param;
	list_favorite->favorite_count = evt->total;
	if (evt->count > 0)
	{
		for (index = evt->start_index; index <= evt->end_index; ++index)
    	{
        	srv_sns_get_item2(evt->list_id, index, (void **)&friend);
			mmi_phb_sns_entry_set_favorite(friend->user.user_id, MMI_TRUE, (U32)friend->user.user_id_len);
    	}
		if ((U16)evt->end_index + 1 < evt->total)
		{
    		srv_sns_load_list(evt->list_id, evt->end_index + 1, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_PREPARE);
		}
		else
		{
			srv_sns_load_list(evt->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_READY);
		}
	}
	else
	{
		srv_sns_load_list(evt->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_READY);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_load_friend_list_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_phb_sns_load_friend_list_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sns_evt_list_updated_struct *evt;
	mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_sns_evt_list_updated_struct *)param;

    if (evt->result == SRV_SNS_CANCELLED)
    {
        return MMI_RET_OK;
    }
    
    switch ((U8)param->user_data)
    {
        case MMI_PHB_SNS_STATE_READY:
	    mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FRIEND);
	    list_friend->is_valid = MMI_TRUE;
			
	    if (list_favorite->is_valid)
	    {
            mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_PROGRESS);
	    }
	    break;

	    case MMI_PHB_SNS_STATE_RELOAD:
	        mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FRIEND);
	        mmi_phb_sns_entry_list_refresh(MMI_PHB_SNS_STATE_RELOAD, MMI_PHB_SNS_LIST_FRIEND);
	    break;

        case MMI_PHB_SNS_STATE_SEARCH:
            mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FRIEND);
		    mmi_phb_sns_entry_list_refresh(MMI_PHB_SNS_STATE_SEARCH, MMI_PHB_SNS_LIST_FRIEND);
            break;

        case MMI_PHB_SNS_STATE_RESEARCH:
            srv_sns_search_friends(list_friend->list_id, list_friend->search_buffer, (void*)MMI_PHB_SNS_STATE_SEARCH);
            break;

        case MMI_PHB_SNS_STATE_REFRESH:
            mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FRIEND);
            list_friend->is_valid = MMI_TRUE;
    	    mmi_phb_sns_entry_list_refresh(MMI_PHB_SNS_STATE_ADD, MMI_PHB_SNS_LIST_FRIEND);
    	    break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_load_favorite_list_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_phb_sns_load_favorite_list_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sns_evt_list_updated_struct *evt;
	mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_sns_evt_list_updated_struct *)param;

    if (evt->result == SRV_SNS_CANCELLED)
    {
        return MMI_RET_OK;
    }
    
    switch ((U8)param->user_data)
    {
        case MMI_PHB_SNS_STATE_PREPARE:
	        mmi_phb_sns_callback_state_prepare(param);
	        break;

	    case MMI_PHB_SNS_STATE_READY:
	        mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FAVORITE);
	        list_favorite->is_valid = MMI_TRUE;

	        if (list_friend->is_valid)
	        {
                mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_PROGRESS);
	        }
	        break;

    	case MMI_PHB_SNS_STATE_REFRESH:
    	    mmi_phb_sns_callback_state_refresh(param);
    	    break;

    	case MMI_PHB_SNS_STATE_ADD:
    	case MMI_PHB_SNS_STATE_REMOVE:
            list_favorite->is_valid = MMI_FALSE;
    	    list_favorite->list_id = srv_sns_get_friends_by_group(SRV_SNS_SELECTED_FRIENDS_GROUP_ID);
            srv_sns_load_list(list_favorite->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void*)MMI_PHB_SNS_STATE_REFRESH);
            if (list_friend->is_group)
            {
                list_friend->is_valid = MMI_FALSE;
                srv_sns_release_list(list_friend->list_id, MMI_FALSE);
                list_friend->list_id = srv_sns_get_friends_by_group(SRV_SNS_SELECTED_FRIENDS_GROUP_ID);
                srv_sns_load_list(list_friend->list_id, 0, mmi_phb_sns_load_friend_list_callback, (void*)MMI_PHB_SNS_STATE_REFRESH);    
            }
            break;

    	case MMI_PHB_SNS_STATE_SEARCH:
            mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FAVORITE);
    		mmi_phb_sns_entry_list_refresh(MMI_PHB_SNS_STATE_SEARCH, MMI_PHB_SNS_LIST_FAVORITE);
            break;

        case MMI_PHB_SNS_STATE_RESEARCH:
            srv_sns_search_friends(list_favorite->list_id, list_favorite->search_buffer, (void*)MMI_PHB_SNS_STATE_SEARCH);
            break;

        case MMI_PHB_SNS_STATE_RELOAD:
            mmi_phb_sns_set_list_cntx(evt, MMI_PHB_SNS_LIST_FAVORITE);
            mmi_phb_sns_entry_list_refresh(MMI_PHB_SNS_STATE_RELOAD, MMI_PHB_SNS_LIST_FAVORITE);
            break;

		default:
			break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_unavailable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_show_friend_unavailable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer;
    U8* string = NULL;
	U8 tab_index = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            GRP_ID_PHB_MAIN,
            SCR_ID_PHB_SNS_TAB0,
            NULL,
            mmi_phb_sns_entry_friend_list,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
		GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        SCR_ID_PHB_SNS_TAB0,
 		NULL,
        mmi_phb_sns_entry_friend_list,
        MMI_FRM_TAB_PAGE))
    #endif
    {
    	return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!gui_buffer)
	   {
	   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_PBOOK_MAIN_MENU,SCR_ID_PHB_SNS_TAB0);
	   	}
   #endif
    if (g_mmi_phb_sns_misc.sns_error_type == MMI_PHB_SNS_NO_READY)
    {
        string = (U8*)GetString(srv_sns_get_error_string((S16)srv_sns_get_ready()));
    }
    else if (g_mmi_phb_sns_misc.sns_error_type == MMI_PHB_SNS_NO_ACCOUNT)
    {
        string = (U8*)GetString(STR_ID_SNS_NO_ACCOUNT);
    }

	#ifdef __MMI_PHB_CALLER_GROUP__
	tab_index = 2;
	#else
	tab_index = 1;
	#endif
    wgui_cat3001_show(
        get_string(STR_ID_PHB_SNS_FRIEND_CAPTION),
        0,
        0,
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        //(S8)2,
        tab_index,
        MMI_TRUE,
        string,
        100,
        gui_buffer);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif
    //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_unavailable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_show_favorite_unavailable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer;
    U8* string = NULL;
	U8 tab_index = 2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            GRP_ID_PHB_MAIN,
            SCR_ID_PHB_SNS_TAB1,
            NULL,
            mmi_phb_sns_entry_favorite_list,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
		GRP_ID_PHB_MAIN,
        SCR_PBOOK_MAIN_MENU,
        SCR_ID_PHB_SNS_TAB1,
 		NULL,
        mmi_phb_sns_entry_favorite_list,
        MMI_FRM_TAB_PAGE))
     #endif
    {
    	return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!gui_buffer)
	   {
	   		gui_buffer = cui_tab_get_screen_gui_buf(SCR_PBOOK_MAIN_MENU,SCR_ID_PHB_SNS_TAB1);
	   	}
   #endif
    if (g_mmi_phb_sns_misc.sns_error_type == MMI_PHB_SNS_NO_READY)
    {
        string = (U8*)GetString(srv_sns_get_error_string((S16)srv_sns_get_ready()));
    }
    else if (g_mmi_phb_sns_misc.sns_error_type == MMI_PHB_SNS_NO_ACCOUNT)
    {
        string = (U8*)GetString(STR_ID_SNS_NO_ACCOUNT);
    }
	
#ifdef __MMI_PHB_CALLER_GROUP__
	tab_index = 3;
#else
	tab_index = 2;
#endif

    wgui_cat3001_show(
        get_string(STR_ID_PHB_SNS_FAVORITE_CAPTION),
        0,
        0,
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        //(S8)3,
        tab_index,
        MMI_TRUE,
        string,
        100,
        gui_buffer);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif
    //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
}


static void mmi_phb_sns_load_friends(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
    srv_sns_load_list(list_friend->list_id, 0, mmi_phb_sns_load_friend_list_callback, (void *)MMI_PHB_SNS_STATE_READY);
    srv_sns_load_list(list_favorite->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_PREPARE);
}


static void mmi_phb_sns_sync_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sns_cancel_sync_friends();
    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_PROGRESS);
    mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
    srv_sns_load_list(list_friend->list_id, 0, mmi_phb_sns_load_friend_list_callback, (void *)MMI_PHB_SNS_STATE_READY);
    srv_sns_load_list(list_favorite->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_PREPARE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_sync_progress
 * DESCRIPTION
 *  sync sns friends 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sns_sync_progress(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            NULL,
            (FuncPtr)mmi_phb_sns_sync_progress,
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    ShowCategory8Screen(
        0,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        STR_ID_PHB_SNS_SYNCING,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    SetRightSoftkeyFunction(mmi_phb_sns_sync_cancel, KEY_EVENT_UP);
}


static void mmi_phb_sns_sync_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_QUERY);
    mmi_frm_scrn_first_enter_ex(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_PROGRESS, (FuncPtr)mmi_phb_sns_sync_progress, NULL, NULL);
    srv_sns_sync_unsynced_friends();
    srv_sns_load_list(list_friend->list_id, 0, mmi_phb_sns_load_friend_list_callback, (void *)MMI_PHB_SNS_STATE_READY);
    srv_sns_load_list(list_favorite->list_id, 0, mmi_phb_sns_load_favorite_list_callback, (void *)MMI_PHB_SNS_STATE_PREPARE);
}


static void mmi_phb_sns_sync_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_QUERY);
    mmi_phb_sns_load_friends();
}


void mmi_phb_sns_sync_query(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            NULL,
            (FuncPtr)mmi_phb_sns_sync_query,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ClearHighlightHandler();

    ShowCategory66Screen(
        0,
        0,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8*)get_string(STR_ID_PHB_SNS_SYNC),
        mmi_get_event_based_image(MMI_EVENT_INFO),
        NULL);

    SetLeftSoftkeyFunction(mmi_phb_sns_sync_lsk, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_phb_sns_sync_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_sns_sync_rsk, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_entry_sns_friend_list_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_entry_friend_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
	mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sns_is_ready())
    {
        g_mmi_phb_sns_misc.sns_error_type = MMI_PHB_SNS_NO_READY;
        mmi_phb_sns_show_friend_unavailable();
        return;
    }

    if (!srv_sns_is_any_login_acocunt())
    {
        g_mmi_phb_sns_misc.sns_error_type = MMI_PHB_SNS_NO_ACCOUNT;
        mmi_phb_sns_show_friend_unavailable();
        return;
    }

    mmi_phb_sns_show_friend_list();

    if (!list_friend->list_id)
    {
        list_friend->list_id = srv_sns_get_all_friends();
        list_favorite->list_id = srv_sns_get_friends_by_group(SRV_SNS_SELECTED_FRIENDS_GROUP_ID);

        if (srv_sns_need_to_sync_friends(list_friend->list_id))
        {        
            mmi_frm_scrn_first_enter(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_QUERY, (FuncPtr)mmi_phb_sns_sync_query, NULL);
        }
        else
        {
            mmi_phb_sns_load_friends();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_entry_favorite_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_sns_entry_favorite_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
    mmi_phb_sns_favorite_list_struct *list_favorite = g_mmi_phb_list_p->sns_favorite_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sns_is_ready())
    {
        g_mmi_phb_sns_misc.sns_error_type = MMI_PHB_SNS_NO_READY;
        mmi_phb_sns_show_favorite_unavailable();
        return;
    }

    if (!srv_sns_is_any_login_acocunt())
    {
        g_mmi_phb_sns_misc.sns_error_type = MMI_PHB_SNS_NO_ACCOUNT;
        mmi_phb_sns_show_favorite_unavailable();
        return;
    }

    mmi_phb_sns_show_favorite_list();

    if (!list_favorite->list_id)
    {
        list_friend->list_id = srv_sns_get_all_friends();
        list_favorite->list_id = srv_sns_get_friends_by_group(SRV_SNS_SELECTED_FRIENDS_GROUP_ID);

        if (srv_sns_need_to_sync_friends(list_friend->list_id))
        {        
            mmi_frm_scrn_first_enter(GRP_ID_PHB_MAIN, SCR_ID_PHB_SNS_QUERY, (FuncPtr)mmi_phb_sns_sync_query, NULL);           
        }
        else
        {
            mmi_phb_sns_load_friends();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_entry_contact_link
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_entry_contact_link(cui_sns_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CUI_SNS_RESULT_ERROR == result)
    {
	    mmi_phb_popup_display_ext(
	        STR_ID_PHB_SNS_ERROR,
	        MMI_EVENT_FAILURE);  
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_entry_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_entry_filter(cui_sns_result_enum result, S32 list_id, MMI_BOOL is_group, S32 provider)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_phb_sns_friend_list_struct *list_friend = g_mmi_phb_list_p->sns_friend_list;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch (result)
	{
		case CUI_SNS_RESULT_OK:
			if (MMI_FALSE == list_friend->is_valid)
			{
			    srv_sns_release_list(list_friend->list_id, MMI_FALSE);
                if (is_group)
                {
                    list_friend->is_group = MMI_TRUE;
                }
                else
                {
                    list_friend->is_group = MMI_FALSE;
                    list_friend->provider = provider;
                }
                mmi_phb_sns_search_clear(MMI_PHB_SNS_LIST_FRIEND);
				srv_sns_load_list(list_id, 0, mmi_phb_sns_load_friend_list_callback, (void *)MMI_PHB_SNS_STATE_READY);	
			}
			mmi_phb_sns_is_progress(GRP_ID_PHB_MAIN, STR_GLOBAL_PLEASE_WAIT);
			break;
			
		case CUI_SNS_RESULT_ABORT:
			if (MMI_FALSE == list_friend->is_valid)
			{
				list_friend->is_valid = MMI_TRUE;
			}
			break;
			
		default:
			if (MMI_FALSE == list_friend->is_valid)
			{
				list_friend->is_valid = MMI_TRUE;
			}
			mmi_phb_popup_display_ext(
				STR_ID_PHB_SNS_ERROR,
				MMI_EVENT_FAILURE); 
			break;
	}
}
#endif
