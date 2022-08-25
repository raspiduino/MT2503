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
 * BTMMIHIDScr.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MMI screen of bluetooth HID application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* RHR ADD */
#include "MMI_features.h"
/* RHR ADD end */

//#include "MMI_include.h"
#if defined(__MMI_HIDD_SUPPORT__)
#include "CommonScreens.h"
#include "ProfilesSrvGprot.h"
#include "Conversions.h"
#include "GpioSrvGprot.h"
#include "custom_events_notify.h"

//#include "ConnectivityResDef.h"
//#include "BtcmCuiGprot.h"
#include "BTMMIScrGprots.h"
#include "BtcmSrvGprot.h"
#include "BTMMIScr.h"

#include "BTMMIHidScr.h"
#include "BTMMIHiddGprots.h"
#include "BTMMIHidd.h"

#ifdef HID_SUPPORT_MENU_CUI
#include "MenuCuiGprot.h"
#endif

/* RHR ADD */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_panel.h"
#include "GlobalConstants.h"
#include "string.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "NotificationGprot.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_conn_app_trc.h"
#include "kal_trace.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "wgui_categories_list.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_popup.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
/* RHR ADD end */

/***************************************************************************** 
* Internal Interface
*****************************************************************************/
static MMI_BOOL mmi_hid_active_app(mmi_scenario_id id, void *para);

static void mmi_hid_connect_last_dev(void);
static void mmi_hid_no_last_dev_info(void);

static void mmi_hid_show_app_select(MMI_ID gid);
static void mmi_hid_show_unplug_confirm(MMI_ID gid);
static void mmi_hid_show_disc_confirm(void);
static void mmi_hid_show_progress(MMI_ID gid, U8 prog_type);
static void mmi_hid_show_result(U32 result);
static void mmi_hid_show_popup(U32 result);

static void mmi_hid_app_select_hdlr(void);
static void mmi_hid_app_select_hilite_hdlr(S32 idx);
static void mmi_hid_disc_confirm_lsk(void);
static void mmi_hid_disc_confirm_rsk(void);

static MMI_RET mmi_hid_group_proc(mmi_event_struct *post_evt);
static MMI_RET mmi_hid_scrn_proc(mmi_event_struct *post_evt);

static MMI_RET mmi_hid_entry_app_select(mmi_scrn_essential_struct *info);
static MMI_RET mmi_hid_entry_desktop(mmi_scrn_essential_struct *info);
static MMI_RET mmi_hid_entry_unplug_confirm(mmi_scrn_essential_struct *info);
static MMI_RET mmi_hid_entry_media_player(mmi_scrn_essential_struct *info);
#ifdef __MMI_HID_PRESENTER__
static MMI_RET mmi_hid_entry_presenter(mmi_scrn_essential_struct *info);
#endif /*__MMI_HID_PRESENTER__*/
#ifdef __MMI_HID_KEYBOARD__
static MMI_RET mmi_hid_entry_keyboard(mmi_scrn_essential_struct *info);
#endif /*__MMI_HID_KEYBOARD__*/
static MMI_RET mmi_hid_entry_disc_confirm(mmi_scrn_essential_struct *info);
static MMI_RET mmi_hid_entry_connecting(mmi_scrn_essential_struct *info);
static MMI_RET mmi_hid_entry_disconnecting(mmi_scrn_essential_struct *info);

static void mmi_hid_desktop_key_up_event_callback(void);
static void mmi_hid_desktop_key_repeat_event_callback(void);
static void mmi_hid_media_player_key_up_event_callback(void);
static void mmi_hid_media_player_key_repeat_event_callback(void);
#ifdef __MMI_HID_PRESENTER__
static void mmi_hid_presenter_key_up_event_callback(void);
static void mmi_hid_presenter_key_repeat_event_callback(void);
#endif /*__MMI_HID_PRESENTER__*/
static void mmi_hid_set_element_enable(U8 type, wgui_cat95_panel_element_struct *element, U8 count);
#ifdef __MMI_HID_KEYBOARD__
static void mmi_hid_keyboard_send_cmd(void);
#endif /*__MMI_HID_KEYBOARD__*/

#ifdef HID_SUPPORT_MENU_CUI
static void mmi_hid_menu_hdlr(cui_menu_event_struct *evt);
static void mmi_hid_on_menu_entry(MMI_ID menu);
static void mmi_hid_on_menu_select(MMI_ID menu, MMI_MENU_ID item);
#endif

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern U8 g_enable_pts_test;

/***************************************************************************** 
* External functions
*****************************************************************************/
/***************************************************************************** 
* Global Variable
*****************************************************************************/
static mmi_bt_hid_scr_cntx_struct g_hid_scrn_cntx;
static U8 delay_repeat_event = 0;
#ifdef __MMI_HID_KEYBOARD__
static U8 hid_key_cmd[HID_MAX_CTRL_DATA_LENGTH]={0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#endif /*__MMI_HID_KEYBOARD__*/
const mmi_bt_hid_key_control_data_struct hid_control_data_desktop[HID_NUM_OF_CTRL_DATA] =
{
 { KEY_1,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_2,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_3,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_4,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_5,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_6,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_7,           KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_8,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_9,           KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x04, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_STAR,        KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_0,           KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_POUND,       KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_UP_ARROW,    KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00} },//F6
 { KEY_DOWN_ARROW,  KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00} },//0A
 { KEY_LEFT_ARROW,  KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },//F6
 { KEY_RIGHT_ARROW, KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },//0A
 { KEY_UP_ARROW,    KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_DOWN_ARROW,  KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_LEFT_ARROW,  KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_RIGHT_ARROW, KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }
 
};

const mmi_bt_hid_key_control_data_struct hid_control_data_media_player[HID_NUM_OF_CTRL_DATA] =
{
 { KEY_1,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_2,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_3,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_4,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x03, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_5,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },//E9
 { KEY_6,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x03, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },//FC-home
 { KEY_7,			KEY_EVENT_UP, HID_ACTIVE_BTN, {0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_8,			KEY_EVENT_UP, HID_ACTIVE_BTN, {0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_9,           KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0xF1, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_STAR,        KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_0,           KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_POUND,       KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_UP_ARROW,    KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_DOWN_ARROW,  KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_LEFT_ARROW,  KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_RIGHT_ARROW, KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_UP_ARROW,    KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_DOWN_ARROW,  KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_LEFT_ARROW,  KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_RIGHT_ARROW, KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }
 
 
};
#ifdef __MMI_HID_PRESENTER__
const mmi_bt_hid_key_control_data_struct hid_control_data_presenter[HID_NUM_OF_CTRL_DATA] =
{
 { KEY_1,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_2,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_3,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_4,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_5,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_6,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x02, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_7,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x02, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_8,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_9,           KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_STAR,        KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00} }, 
 { KEY_0,           KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_POUND,       KEY_EVENT_UP, HID_INACTV_BTN, {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_UP_ARROW,    KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x4B, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_DOWN_ARROW,  KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x4E, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_LEFT_ARROW,  KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_RIGHT_ARROW, KEY_EVENT_UP, HID_ACTIVE_BTN, {0x01, 0x00, 0x00, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_2,           KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_4,           KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0xE5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_5,           KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00} },
 { KEY_6,           KEY_REPEAT,   HID_ACTIVE_BTN, {0x02, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }
 
};
#endif /*__MMI_HID_PRESENTER__*/

#if defined(__MMI_MAINLCD_96X64__)
const S32 hid_icon_pos[17][4] = {
                    {  5,  48, 39 , 15},
                    { 45,  48, 39 , 15},
                    { 83,  48, 39 , 15},
                    {  5,  62, 39 , 15},
                    { 45,  62, 39 , 15},
                    { 83,  62, 39 , 15},
                    {  5,  77, 39 , 15},
                    { 45,  77, 39 , 15},
                    { 83,  77, 39 , 15},
                    {  5,  92, 39 , 15},
                    { 45,  92, 39 , 15},
                    { 83,  92, 39 , 15},
                    { 42,  15, 43, 16},
                    { 42,  31, 43, 16},
                    { 23,  19, 20, 23},
                    { 85,  19, 20, 23},
                    { 42,  31, 43, 16}};

#elif defined(__MMI_MAINLCD_128X128__)
const S32 hid_icon_pos[17][4] = {
                    {  5,  48, 39 , 15},
                    { 45,  48, 39 , 15},
                    { 83,  48, 39 , 15},
                    {  5,  62, 39 , 15},
                    { 45,  62, 39 , 15},
                    { 83,  62, 39 , 15},
                    {  5,  77, 39 , 15},
                    { 45,  77, 39 , 15},
                    { 83,  77, 39 , 15},
                    {  5,  92, 39 , 15},
                    { 45,  92, 39 , 15},
                    { 83,  92, 39 , 15},
                    { 42,  15, 43, 16},
                    { 42,  31, 43, 16},
                    { 23,  19, 20, 23},
                    { 85,  19, 20, 23},
                    { 42,  31, 43, 16}};
#elif defined(__MMI_MAINLCD_128X160__)
const S32 hid_icon_pos[17][4] = {
                    {  5,  66, 39 , 18},
                    { 44,  66, 39 , 18},
                    { 83,  66, 39 , 18},
                    {  5,  84, 39 , 18},
                    { 44,  84, 39 , 18},
                    { 83,  84, 39 , 18},
                    {  5, 103, 39 , 18},
                    { 44, 103, 39 , 18},
                    { 83, 103, 39 , 18},
                    {  5, 121, 39 , 18},
                    { 44, 121, 39 , 18},
                    { 83, 121, 39 , 18},
                    { 42,  23, 43, 14},
                    { 42,  50, 43, 14},
                    { 21,  27, 20, 33},
                    { 85,  27, 20, 33},
                    { 42,  37, 43, 13}};
#elif defined(__MMI_MAINLCD_176X220__)
const S32 hid_icon_pos[17][4] = {
                    { 38,  98, 32 , 22},
                    { 73,  98, 32 , 22},
                    {108,  98, 32 , 22},
                    { 38, 122, 32 , 22},
                    { 73, 122, 32 , 22},
                    {108, 122, 32 , 22},
                    { 38, 146, 32 , 22},
                    { 73, 146, 32 , 22},
                    {108, 146, 32 , 22},
                    { 38, 170, 32 , 22},
                    { 73, 170, 32 , 22},
                    {108, 170, 32 , 22},
                    { 78,  24, 24, 23},
                    { 78,  71, 24, 23},
                    { 55,  47, 23, 24},
                    {102,  47, 23, 24},
                    { 78,  47, 24, 24}};
#elif defined(__MMI_MAINLCD_240X320__)
#ifdef __MMI_FTE_SUPPORT__
const S32 hid_icon_pos[17][4] = {
                    {  5, 137, 75 , 34},
                    { 82, 137, 75 , 34},
                    {160, 137, 75 , 34},
                    {  5, 173, 75 , 34},
                    { 82, 173, 75 , 33},
                    {160, 173, 75 , 34},
                    {  5, 209, 75 , 34},
                    { 82, 209, 75 , 34},
                    {160, 209, 75 , 34},
                    {  5, 245, 75 , 34},
                    { 82, 245, 75 , 34},
                    {160, 245, 75 , 34},
                    { 82,  35, 75 , 34},
                    { 82, 104, 75 , 34},
                    {  5,  64, 78 , 40},
                    {157,  64, 78 , 40},
                    { 83,  64, 74,  40}};
#else
const S32 hid_icon_pos[17][4] = {
                    { 56, 144, 40 , 33},
                    {101, 144, 40 , 33},
                    {146, 144, 40 , 33},
                    { 56, 180, 40 , 33},
                    {101, 180, 40 , 33},
                    {146, 180, 40 , 33},
                    { 56, 216, 40 , 33},
                    {101, 216, 40 , 33},
                    {146, 216, 40 , 33},
                    { 56, 252, 40 , 33},
                    {101, 252, 40 , 33},
                    {146, 252, 40 , 33},
                    {107,  42, 33, 29},
                    {107, 108, 33, 29},
                    { 74,  73, 31, 33},
                    {141,  73, 31, 33},
                    {106,  73, 33, 33}};
#endif                    
#elif defined(__MMI_MAINLCD_320X240__)
const S32 hid_icon_pos[17][4] = {
                    { 41, 104, 77 , 27},
                    {125, 104, 77 , 27},
                    {209, 104, 77 , 27},
                    { 41, 130, 77 , 27},
                    {125, 130, 77 , 27},
                    {209, 130, 77 , 27},
                    { 41, 158, 77 , 27},
                    {125, 158, 77 , 27},
                    {209, 158, 77 , 27},
                    { 41, 184, 77 , 27},
                    {125, 184, 77 , 27},
                    {209, 184, 77 , 27},
                    {125,  37, 74, 24},
                    {125, 78, 74, 24},
                    { 82,  48, 39, 47},
                    {203,  48, 39, 47},
                    {149,  62, 19, 15}};
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
#ifdef __MMI_FTE_SUPPORT__
const S32 hid_icon_pos[17][4] = {
                    { 9,  227, 99, 46},
                    {111, 227, 99, 46},
                    {212, 227, 99, 46},
                    { 9,  276, 99, 46},
                    {111, 276, 99, 46},
                    {212, 276, 99, 46},
                    { 9,  325, 99, 46},
                    {111, 325, 99, 46},
                    {212, 325, 99, 46},
                    { 9,  374, 99, 46},
                    {111, 374, 99, 46},
                    {212, 374, 99, 46},
                    {111,  77, 98, 46},
                    {111, 173, 98, 46},
                    { 9,  122, 102,52},
                    {209, 122, 102,52},
                    {111, 123, 98, 50}};
#else
const S32 hid_icon_pos[17][4] = {
                    { 6,  216, 99, 51},
                    {111, 216, 99, 51},
                    {216, 216, 99, 51},
                    { 6,  273, 99, 51},
                    {111, 273, 99, 51},
                    {216, 273, 99, 51},
                    { 6,  330, 99, 51},
                    {111, 330, 99, 51},
                    {216, 330, 99, 51},
                    { 6,  387, 99, 51},
                    {111, 387, 99, 51},
                    {216, 387, 99, 51},
                    {114,  80, 92, 37},
                    {114, 161, 92, 37},
                    { 56, 111, 49, 55},
                    {216, 111, 49, 55},
                    {114, 120, 92, 37}};
#endif                    
#elif defined(__MMI_MAINLCD_240X400__)
#ifdef __MMI_FTE_SUPPORT__
const S32 hid_icon_pos[17][4] = {  
                    { 5, 181, 75 , 41},
                    {82, 181, 75 , 41},
                    {160,181, 75 , 41},
                    { 5, 224, 75 , 41},
                    {82, 224, 75 , 41},
                    {160,224, 75 , 41},
                    { 5, 267, 75 , 41},
                    {82, 267, 75 , 41},
                    {160,267, 75 , 41},
                    { 5, 310, 75 , 41},
                    {82, 310, 75 , 41},
                    {160,310, 75 , 41},
                    {82,  65, 76, 33},
                    {82, 148, 76, 33},
                    { 5,  98, 78, 45},
                    {157, 98, 78, 45},
                    { 83, 98, 74, 45}};
#else
const S32 hid_icon_pos[17][4] = {  
                    { 4, 192, 76 , 44},
                    {82, 192, 76 , 44},
                    {160,192, 76 , 44},
                    { 4, 236, 76 , 44},
                    {82, 236, 76 , 44},
                    {160,236, 76 , 44},
                    { 4, 280, 76 , 44},
                    {82, 280, 76 , 44},
                    {160,280, 76 , 44},
                    { 4, 324, 76 , 44},
                    {82, 324, 76 , 44},
                    {160,324, 76 , 44},
                    {81,  71, 78, 36},
                    {81, 148, 78, 36},
                    { 22,  107, 59, 41},
                    {159,  107, 59, 41},
                    {81,  107, 78, 41}};
#endif
#endif

#ifdef HID_SUPPORT_MENU_CUI
typedef struct {
    MMI_MENU_ID id;
    MMI_STR_ID  text;
    MMI_IMG_ID  img;
    mmi_scrn_func entry;
} hid_menu_item_struct;

enum {
    MENU_DESKTOP = 0,
    MENU_MEDIA_PLAY,
 #ifdef __MMI_HID_PRESENTER__
    MENU_PRESENTER,
 #endif
 #ifdef __MMI_HID_KEYBOARD__
    MENU_KEYBOARD,
 #endif
    MENU_COUNT
};

static const hid_menu_item_struct g_hid_menu_tab[MENU_COUNT] = {
                {MENU_DESKTOP, STR_BT_REMOTE_CTRL_DESKTOP, 
                    0, mmi_hid_entry_desktop},
                {MENU_MEDIA_PLAY, STR_BT_REMOTE_CTRL_MEDIA_PLAYER, 
                    0, mmi_hid_entry_media_player}
               #ifdef __MMI_HID_PRESENTER__
                , {MENU_PRESENTER, STR_BT_REMOTE_CTRL_PRESENTER, 
                    0, mmi_hid_entry_presenter}
               #endif  /*__MMI_HID_PRESENTER__*/
			   #ifdef __MMI_HID_KEYBOARD__
                , {MENU_KEYBOARD, STR_BT_REMOTE_CTRL_KEYBOARD, \
                    0, mmi_hid_entry_keyboard}
			   #endif  /*__MMI_HID_KEYBOARD__*/
			   };
#endif                

/***************************************************************************** 
* Functions
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hid_scr_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_hid_scr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_hid_scrn_cntx, 0, sizeof(g_hid_scrn_cntx));
    g_hid_scrn_cntx.gid = GRP_ID_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_remote_control_hilight_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_remote_control_menu_hilight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    SetLeftSoftkeyFunction(mmi_bt_entry_remote_control, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_entry_remote_control, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

    g_hid_scrn_cntx.base_scrn = mmi_frm_scrn_get_active_id();
}

extern srv_bt_cm_dev_struct g_connected_dev_info[BT_DEVICE_LINK_NUM];
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_remote_control_menu_hint_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  index       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_remote_control_menu_hint_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr *addr;
    U8 i;
	U8 j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* BT address: NAP, UAP, LAP */
#ifdef __MMI_BT_DIALER_SUPPORT__
		for(i = 0; i < BT_DEVICE_LINK_NUM; i++ )
		{
			if (!HIDD_INVALID_DEVICE(g_connected_dev_info[i].bd_addr) 
				&& mmi_bt_dialer_app_is_connected_ex(&g_connected_dev_info[i].bd_addr))
			{	
				srv_bt_cm_dev_struct* dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&g_connected_dev_info[i].bd_addr);
	
				j++;
	
				kal_prompt_trace(MOD_MMI, "[HID]mmi_bt_entry_remote_control i = %d j = %d", i, j);
				if(srv_bt_cm_dev_is_support_hid(dev_p))
				{
					kal_prompt_trace(MOD_MMI, "[HID]mmi_bt_entry_remote_control device %d is support=", i);
					g_hidd_cntx.last_device = g_connected_dev_info[i].bd_addr;
					break;
				}
			}
		}
		if(j == 0)
		{
			kal_prompt_trace(MOD_MMI, "[HID]mmi_bt_entry_remote_control j==0");
			addr = srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HID);
			if (addr)
				g_hidd_cntx.last_device = *addr;
			else
				mmi_bth_hidd_clear_last_dev_info();
		}
		else if(i == BT_DEVICE_LINK_NUM)
		{
			kal_prompt_trace(MOD_MMI, "[HID]mmi_bt_entry_remote_control i=BT_DEVICE_LINK_NUM");
			mmi_bth_hidd_clear_last_dev_info();
		}
#else /* __MMI_BT_DIALER_SUPPORT__*/
		addr = srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HID);
		if (addr)
			g_hidd_cntx.last_device = *addr;
		else
			mmi_bth_hidd_clear_last_dev_info();
	
#endif /* __MMI_BT_DIALER_SUPPORT__*/
    
    if (HIDD_INVALID_DEVICE(g_hidd_cntx.last_device))
    {
        hintData[index][0] = hintData[index][1] = '\0';
    }
    else
    {        
        U8 *buff = (U8 *)get_ctrl_buffer(BT_HIDD_MAX_DEV_NAME_LEN);

        srv_bt_cm_get_dev_name(&g_hidd_cntx.last_device, BT_HIDD_MAX_DEV_NAME_LEN, buff);
        
        mmi_chset_utf8_to_ucs2_string(
            hintData[index], 
            sizeof(hintData[index]),
            buff);
        
        free_ctrl_buffer(buff);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buff    [IN]    buff for saving the string
 *  size    [IN]    the buff byte count
 *  
 * Returns
 *  
 ******************************************************************************/
void mmi_bt_get_remote_control_menu_hint_string(WCHAR* buff, U32 size)
{
    if (HIDD_INVALID_DEVICE(g_hidd_cntx.last_device))
    {
        buff[0] = 0;
    }
    else
    {        
        U8* tmp_buff = (U8*)get_ctrl_buffer(SRV_BT_CM_BD_FNAME_LEN);

        srv_bt_cm_get_dev_name(&g_hidd_cntx.last_device, SRV_BT_CM_BD_FNAME_LEN, tmp_buff);
        mmi_chset_utf8_to_ucs2_string((U8*)buff, size, tmp_buff);

        free_ctrl_buffer(tmp_buff);
    }
}


static void mmi_hid_start_app(void)
{
    HID_FLAG_RESET(MASK_UNPLUG);

    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_PROGRESS,
        mmi_hid_active_app,
        0);
}

static void mmi_hid_stop_app(void)
{
    HID_FLAG_RESET(MASK_CONNECTED);    
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_DEFAULT,
        mmi_hid_active_app,
        0);

    if (g_hid_scrn_cntx.gid != GRP_ID_INVALID) {
        mmi_frm_scrn_set_leave_proc(
            g_hid_scrn_cntx.gid,
            SCR_BT_REMOTE_CTRL_APP_SELECT,
            NULL);
        mmi_frm_scrn_set_leave_proc(
            g_hid_scrn_cntx.gid,
            SCR_BT_REMOTE_CTRL_PROGRESS,
            NULL);
        mmi_frm_group_close(g_hid_scrn_cntx.gid);
        g_hid_scrn_cntx.gid = GRP_ID_INVALID;
    }
}

static MMI_BOOL mmi_hid_active_app(mmi_scenario_id id, void *para)
{
    g_hid_scrn_cntx.gid = mmi_frm_group_create(
                    GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_hid_group_proc, NULL);
    MMI_ASSERT(g_hid_scrn_cntx.gid != GRP_ID_INVALID);
    
    mmi_frm_group_enter(g_hid_scrn_cntx.gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    return MMI_TRUE;
}

static MMI_RET mmi_hid_group_proc(mmi_event_struct *post_evt)
{
    mmi_scenario_evt_struct *evt = 
        (mmi_scenario_evt_struct *)post_evt;

    switch (evt->evt_id) {
    case EVT_ID_GROUP_ENTER:
        
        if (HID_FLAG_ON(MASK_CONNECTED)) {
            if (HID_FLAG_ON(MASK_UNPLUG))
                mmi_hid_show_unplug_confirm(evt->targ_group);
            mmi_hid_show_app_select(evt->targ_group);
            HID_FLAG_RESET(MASK_CONNECTED);
        }
        else
            mmi_hid_show_progress(evt->targ_group, HID_PROG_CONN);
        
        break;

    case EVT_ID_GROUP_DEINIT:
        
        g_hid_scrn_cntx.gid = GRP_ID_INVALID;
        
        break;

#ifdef HID_SUPPPORT_MENU_CUI
    case EVT_ID_CUI_MENU_LIST_ENTRY:
    case EVT_ID_CUI_MENU_LIST_EXIT:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_hid_menu_hdlr((cui_menu_event_struct *)post_evt);
        break;
#endif
    }

    return MMI_RET_OK;
}

static MMI_RET mmi_hid_scrn_proc(mmi_event_struct *post_evt)
{
    mmi_scenario_evt_struct *evt = (mmi_scenario_evt_struct *)post_evt;

    switch (evt->evt_id) {
    case EVT_ID_SCRN_GOBACK:
    case EVT_ID_SCRN_DELETE_REQ:
    case EVT_ID_SCRN_GOBACK_IN_END_KEY:
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:

        if (evt->targ_scrn == SCR_BT_REMOTE_CTRL_APP_SELECT ||
            evt->targ_scrn == SCR_BT_REMOTE_CTRL_PROGRESS) {
            mmi_hidd_disconnect();
        }

        break;
    }

    return MMI_RET_OK;
}

#ifdef HID_SUPPORT_MENU_CUI
static void mmi_hid_menu_hdlr(cui_menu_event_struct * evt)
{
    switch (evt->evt_id) {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_hid_on_menu_entry(evt->sender_id);
        break;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        mmi_hid_on_menu_select(evt->sender_id, evt->highlighted_menu_id);
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_hid_show_disc_confirm();
//        cui_menu_close(evt->sender_id);
        break;
    }
}
#endif

void mmi_hid_scrn_notify(U32 evt, U32 result)
{
    switch (evt) {
    case HID_EVT_AUTH_IND:
        MMI_HID_LOG(MMI_BT_HID_ACCEPT_FILE_RECV);
        g_hid_scrn_cntx.base_scrn = 0;
        mmi_hid_start_app();
        break;

    case HID_EVT_CONN_IND:
        if (mmi_frm_group_is_present(g_hid_scrn_cntx.gid))
            mmi_hid_show_app_select(g_hid_scrn_cntx.gid);
        else
            HID_FLAG_SET(MASK_CONNECTED);
        break;

    case HID_EVT_UNPLUG_IND:
        if (HID_FLAG_ON(MASK_UNPLUG))
            break;
        if (mmi_frm_group_is_present(g_hid_scrn_cntx.gid))
        {
        	if (HID_RESULT_PENDING == mmi_hidd_disconnect())
				mmi_hid_show_progress(g_hid_scrn_cntx.gid, HID_PROG_DISC);
			else
				mmi_hid_show_result(HID_E_DISC_SUCC);
        }
        else
            HID_FLAG_SET(MASK_UNPLUG);
        break;

    case HID_EVT_CONN_FAIL:
    case HID_EVT_DISC_IND:
        mmi_hid_show_result(result);
        break;
    }
}

#ifdef HID_SUPPORT_MENU_CUI
static void mmi_hid_on_menu_entry(MMI_ID menu)
{
    MMI_MENU_ID IDs[] = {MENU_DESKTOP,
                         MENU_MEDIA_PLAY
                        #ifdef __MMI_HID_PRESENTER__
                         ,MENU_PRESENTER
                        #endif  /*__MMI_HID_PRESENTER__*/
						#ifdef __MMI_HID_KEYBOARD__
                         ,MENU_KEYBOARD
                        #endif  /*__MMI_HID_KEYBOARD__*/
						};
    U32 i;
    
    cui_menu_set_currlist(menu, MENU_COUNT, IDs);

    for (i = 0; i < MENU_COUNT; i++) {
        cui_menu_set_item_string(
            menu, 
            g_hid_menu_tab[i].id, 
            (WCHAR *)GetString(g_hid_menu_tab[i].text));
        cui_menu_set_item_image(
            menu,
            g_hid_menu_tab[i].id,
            gIndexIconsImageList[i]);
    }

    if (!g_enable_pts_test)
    {
     #ifdef __MMI_HID_PRESENTER__
    	cui_menu_set_item_hidden(menu, MENU_PRESENTER, MMI_TRUE);
	 #endif /*__MMI_HID_PRESENTER__*/
	 #ifdef __MMI_HID_KEYBOARD__
        cui_menu_set_item_hidden(menu, MENU_KEYBOARD, MMI_TRUE);
	 #endif /*__MMI_HID_KEYBOARD__*/
    }
}

static void mmi_hid_on_menu_select(MMI_ID menu, MMI_MENU_ID item)
{
    mmi_bt_hid_scr_cntx_struct *cntx = &g_hid_scrn_cntx;
    U32 i;

    for (i = 0; i < MENU_COUNT; i++) {
        if (g_hid_menu_tab[i].id == item) {
            mmi_frm_scrn_first_enter(
                cntx->gid, 
                SCR_BT_REMOTE_CTRL_APP,
                (FuncPtr)g_hid_menu_tab[i].entry,
                NULL);
            break;
        }
    }
}
#endif

static void mmi_hid_show_popup(U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *s1 = NULL, *s2 = NULL;
    WCHAR output[64];
    mmi_event_notify_enum popup_class;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result) {
    case HID_E_CONN_FAIL:
        s1 = GetString(STR_BT_REMOTE_CTRL_CONN_FAIL);
        popup_class = MMI_EVENT_FAILURE;
        break;

    case HID_E_DISC_IND:
        s1 = GetString(STR_BT_PROF_HID);
        s2 = GetString(STR_BT_DISCON_ED);
        popup_class = MMI_EVENT_FAILURE;
        break;
        
    case HID_E_DISC_SUCC:
        s1 = GetString(STR_BT_PROF_HID);
        s2 = GetString(STR_BT_DISCON_ED);
        popup_class = MMI_EVENT_SUCCESS;
        break;

    case HID_E_DISC_FAIL:
        s1 = GetString(STR_GLOBAL_DISCONNECT);
        s2 = GetString(STR_BT_FAILED);
        popup_class = MMI_EVENT_FAILURE;
        break;

    case HID_E_BUSY:
        s1 = GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
        popup_class = MMI_EVENT_FAILURE;
        break;

    case HID_E_NOT_ALLOW:
        mmi_bt_popup_operation_not_allowed();

    default:
        return;
    }

    mmi_ucs2cpy((S8 *)output, s1);
    if (s2 != NULL)
    {
		mmi_ucs2cat((S8 *)output, (S8 *) L" ");
		mmi_ucs2cat((S8 *)output, s2);
	}
    
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, popup_class, output);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hid_show_result
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  para [IN] 
 * RETURNS
 *  U8
 *****************************************************************************/
static void mmi_hid_show_result(U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We don't show popup in voluntary disconnect case */
    if (result != HID_E_DISC_SUCC)
    {
        mmi_hid_show_popup(result);
    }

    if (result == HID_E_DISC_SUCC ||
        result == HID_E_DISC_IND)
    {
        HID_FLAG_RESET(MASK_UNPLUG);
    }

    mmi_hid_stop_app();
}
extern srv_bt_cm_dev_struct g_connected_dev_info[BT_DEVICE_LINK_NUM];
/*****************************************************************************
* FUNCTION
*  mmi_bt_entry_remote_control
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_entry_remote_control(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr *addr;
	U8 i;
	U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef _MMI_BT_ULTRA_SLIM_
	
	MMI_BT_RESET_FLAG(MMI_BT_CONFIRM_SET);
	if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        MMI_BT_SET_FLAG(MMI_BT_CONFIRM_SET);
        mmi_bt_display_power_on_confirm(g_mmi_bt_scr_cntx.main_gid);
        return;
    }
#endif /*_MMI_BT_ULTRA_SLIM_*/
#if 0
/* under construction !*/
#ifdef __MMI_SIMAP_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
	for(i = 0; i < BT_DEVICE_LINK_NUM; i++ )
	{
		if (!HIDD_INVALID_DEVICE(g_connected_dev_info[i].bd_addr) 
			&& mmi_bt_dialer_app_is_connected_ex(&g_connected_dev_info[i].bd_addr))
		{	
			srv_bt_cm_dev_struct* dev_p = (srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&g_connected_dev_info[i].bd_addr);

			j++;

			kal_prompt_trace(MOD_MMI, "[HID]mmi_bt_entry_remote_control i = %d j = %d", i, j);
			if(srv_bt_cm_dev_is_support_hid(dev_p))
			{
				kal_prompt_trace(MOD_MMI, "[HID]mmi_bt_entry_remote_control device %d is support=", i);
				g_hidd_cntx.last_device = g_connected_dev_info[i].bd_addr;
				break;
			}
		}
	}
	if(j == 0)
	{
		kal_prompt_trace(MOD_MMI, "[HID]mmi_bt_entry_remote_control j==0");
		addr = srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HID);
		if (addr)
			g_hidd_cntx.last_device = *addr;
		else
			mmi_bth_hidd_clear_last_dev_info();
	}
	else if(i == BT_DEVICE_LINK_NUM)
    {
    	kal_prompt_trace(MOD_MMI, "[HID]mmi_bt_entry_remote_control i=BT_DEVICE_LINK_NUM");
    	mmi_bth_hidd_clear_last_dev_info();
	}
#else /* __MMI_BT_DIALER_SUPPORT__*/
	addr = srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HID);
	if (addr)
		g_hidd_cntx.last_device = *addr;
	else
		mmi_bth_hidd_clear_last_dev_info();

#endif /* __MMI_BT_DIALER_SUPPORT__*/

    if (HIDD_INVALID_DEVICE(g_hidd_cntx.last_device))
    {
        mmi_hid_no_last_dev_info();
    }
#ifdef __MMI_BT_AUTHORIZE__
    else if (srv_bt_cm_dev_property_check(&g_hidd_cntx.last_device, SRV_BT_CM_DEV_PROPERTY_BLOCK))
    {
        mmi_bt_popup_prohibited_by_blocked_device();
    }
#endif
    else if (!mmi_bt_is_permission(MMI_FALSE) || 
             (g_hidd_cntx.state != MMI_BTH_HIDD_STAT_ACTIVATED))
    {
        mmi_hid_show_popup(HID_E_BUSY);
    }
    else
    {
        mmi_hid_connect_last_dev();
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_entry_remote_control_ext
* DESCRIPTION
*  This function is to
* PARAMETERS
*  dev_addr
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_entry_remote_control_ext(srv_bt_cm_bt_addr* dev_addr)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (!mmi_bt_dialer_app_is_connected_ex(dev_addr) 
		&& (srv_bt_cm_get_linked_dev_list_idx() == BT_DEVICE_LINK_NUM))
	{
		mmi_bt_popup_display(
			STR_BT_RELEASE_CONN_PROMPT,
			MMI_EVENT_FAILURE,
			NULL);
		return;
	}
#if 0
/* under construction !*/
#ifdef __MMI_SIMAP_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    if (dev_addr)
        g_hidd_cntx.last_device = *dev_addr;
    else
        mmi_bth_hidd_clear_last_dev_info();

    if (HIDD_INVALID_DEVICE(g_hidd_cntx.last_device))
    {
        mmi_hid_no_last_dev_info();
    }
#ifdef __MMI_BT_AUTHORIZE__
    else if (srv_bt_cm_dev_property_check(&g_hidd_cntx.last_device, SRV_BT_CM_DEV_PROPERTY_BLOCK))
    {
        mmi_bt_popup_prohibited_by_blocked_device();
    }
#endif
    else if (!mmi_bt_is_permission(MMI_FALSE) || 
             (g_hidd_cntx.state != MMI_BTH_HIDD_STAT_ACTIVATED))
    {
        mmi_hid_show_popup(HID_E_BUSY);
    }
    else
    {
        mmi_hid_connect_last_dev();
    }

}
/*****************************************************************************
* FUNCTION
*  mmi_hid_connect_last_dev
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_connect_last_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HIDResult result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_hidd_connect_last_dev();
    if (HID_RESULT_PENDING == result)
    {
        mmi_hid_start_app();
    }
    else if (HID_RESULT_FAIL == result)
    {
        mmi_hid_show_result(HID_E_BUSY);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_hid_no_last_dev_info
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_no_last_dev_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display(
        (WCHAR *)GetString(STR_BT_REMOTE_CTRL_NO_LAST_DEV_INFO),
        MMI_EVENT_FAILURE,
        NULL);
}

static void mmi_hid_show_progress(MMI_ID gid, U8 prog_type)
{
    FuncPtr entry;
    MMI_ID scrn_id = SCR_BT_REMOTE_CTRL_PROGRESS;

    if (prog_type == HID_PROG_CONN)
        entry = (FuncPtr)mmi_hid_entry_connecting;
    else
        entry = (FuncPtr)mmi_hid_entry_disconnecting;
    
    mmi_frm_scrn_first_enter(gid, scrn_id, entry, NULL);
    
    mmi_frm_scrn_set_leave_proc(gid, scrn_id, mmi_hid_scrn_proc);
}

/*****************************************************************************
* FUNCTION
*  mmi_hid_show_app_select
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_show_app_select(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct in;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef HID_SUPPORT_MENU_CUI
    MMI_ID cui_id = cui_menu_create(
                        gid, 
                        CUI_MENU_SRC_TYPE_APPCREATE,
                        CUI_MENU_TYPE_APPSUB,
                        0, 0, NULL);

    cui_menu_set_default_title(cui_id, 
        (WCHAR *)GetString(STR_BT_REMOTE_CONTROL),
        GetImage(GetRootTitleIcon(MENU_CONN_BT_MAIN)));

    cui_menu_run(cui_id);

    mmi_frm_scrn_set_leave_proc(
        g_hid_scrn_cntx.gid,
        SCR_BT_REMOTE_CTRL_PROGRESS,
        NULL);
    mmi_frm_scrn_close(gid, SCR_BT_REMOTE_CTRL_PROGRESS);

#else
    mmi_frm_scrn_set_leave_proc(
        g_hid_scrn_cntx.gid,
        SCR_BT_REMOTE_CTRL_PROGRESS,
        NULL);

    in.id = SCR_BT_REMOTE_CTRL_APP_SELECT;
    in.entry_proc = (mmi_proc_func)mmi_hid_entry_app_select;
    in.user_data = NULL;

    if (mmi_frm_scrn_is_present(gid, 
            SCR_BT_REMOTE_CTRL_PROGRESS, 
            MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)) 
    {
        mmi_frm_scrn_replace(gid, SCR_BT_REMOTE_CTRL_PROGRESS, &in);
    }
    else if (mmi_frm_scrn_is_present(gid, 
                SCR_BT_REMOTE_CTRL_UNPLUG_CONFIRM,
                MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_insert(gid, SCR_BT_REMOTE_CTRL_UNPLUG_CONFIRM, &in, MMI_FRM_NODE_BEFORE_FLAG);
    }
    else 
    {
        mmi_frm_scrn_first_enter(
            gid, in.id, (FuncPtr)mmi_hid_entry_app_select, NULL);
        mmi_frm_scrn_close(gid, SCR_BT_REMOTE_CTRL_PROGRESS);
    }

    mmi_frm_scrn_set_leave_proc(gid, in.id, mmi_hid_scrn_proc);
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_hid_entry_app_select
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_hid_entry_app_select(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U8 *scrn_his;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id, 
            info->scrn_id, 
            NULL,
            (FuncPtr)mmi_hid_entry_app_select,
            MMI_FRM_FULL_SCRN))
            return MMI_RET_ERR;
    
    scrn_his = mmi_frm_scrn_get_gui_buf(info->group_id, info->scrn_id);

    if (!g_enable_pts_test)
    {
        nItems = 2;
        ItemList[0] = (U8*)GetString(STR_BT_REMOTE_CTRL_DESKTOP);
        ItemList[1] = (U8*)GetString(STR_BT_REMOTE_CTRL_MEDIA_PLAYER);
    }
    else
    {
        nItems = 2;
        ItemList[0] = (U8*)GetString(STR_BT_REMOTE_CTRL_DESKTOP);
        ItemList[1] = (U8*)GetString(STR_BT_REMOTE_CTRL_MEDIA_PLAYER);
#ifdef __MMI_HID_PRESENTER__
		nItems++;
        ItemList[2] = (U8*)GetString(STR_BT_REMOTE_CTRL_PRESENTER);
#endif
#ifdef __MMI_HID_KEYBOARD__
		nItems++;
        ItemList[3] = (U8*)GetString(STR_BT_REMOTE_CTRL_KEYBOARD);
#endif
    }

    RegisterHighlightHandler(mmi_hid_app_select_hilite_hdlr);

    wgui_list_menu_enable_access_by_shortcut();
    ShowCategory53Screen(
        STR_BT_REMOTE_CONTROL,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (U16 *)gIndexIconsImageList,
        NULL, 
        0,
        0,
        scrn_his);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    SetLeftSoftkeyFunction(mmi_hid_app_select_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_hid_app_select_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_hid_show_disc_confirm, KEY_EVENT_UP);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    return MMI_RET_OK;
}

static void mmi_hid_app_select_hdlr(void)
{
    mmi_bt_hid_scr_cntx_struct *cntx = &g_hid_scrn_cntx;
    mmi_scrn_func proc[] = {
                     mmi_hid_entry_desktop,
                     mmi_hid_entry_media_player
                #ifdef __MMI_HID_PRESENTER__
                     , mmi_hid_entry_presenter
                #endif /*__MMI_HID_PRESENTER__*/
				#ifdef __MMI_HID_KEYBOARD__
                     ,mmi_hid_entry_keyboard
				#endif /*__MMI_HID_KEYBOARD__*/
				};
                    
    switch (cntx->sel_idx) {
    case 0: 
	case 1:
#if (defined(__MMI_HID_PRESENTER__) || defined(__MMI_HID_KEYBOARD__))		
	case 2:
#endif /*defined(__MMI_HID_PRESENTER__) && defined(__MMI_HID_KEYBOARD__)*/

#if (defined(__MMI_HID_PRESENTER__) && defined(__MMI_HID_KEYBOARD__))
	case 3:
#endif /*defined(__MMI_HID_PRESENTER__) && defined(__MMI_HID_KEYBOARD__)*/
        mmi_frm_scrn_first_enter(
            g_hid_scrn_cntx.gid, 
            SCR_BT_REMOTE_CTRL_APP,
            (FuncPtr)proc[cntx->sel_idx],
            NULL);
        break;

    default:
        break;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_hid_app_select_hilite_hdlr
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_app_select_hilite_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SCR_HIGHLIGHT_ITEM, idx);

    g_hid_scrn_cntx.sel_idx = idx;
}

/*****************************************************************************
* FUNCTION
*  mmi_hid_show_unplug_confirm
* DESCRIPTION
*  This function is the entry function of Unplug confirm.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_show_unplug_confirm(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        gid, 
        SCR_BT_REMOTE_CTRL_UNPLUG_CONFIRM,
        (FuncPtr)mmi_hid_entry_unplug_confirm,
        NULL);
    
    srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_INFO), NULL);
}

/*****************************************************************************
* FUNCTION
*  mmi_hid_entry_unplug_confirm
* DESCRIPTION
*  This function is the entry function of Unplug confirm.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_hid_entry_unplug_confirm(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *scrn_his;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)mmi_hid_entry_unplug_confirm,
            MMI_FRM_SMALL_SCRN))
            return MMI_RET_ERR;
            
    scrn_his = mmi_frm_scrn_get_gui_buf(info->group_id, info->scrn_id);

    ShowCategory165Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0, 0,
        (UI_string_type)GetString(STR_BT_REMOTE_CTRL_UNPLUG_CONFIRM),
        mmi_get_event_based_image(MMI_EVENT_INFO),
        scrn_his);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_hid_disc_confirm_lsk, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_hid_disc_confirm_lsk, KEY_EVENT_UP);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hid_show_disc_confirm
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hid_show_disc_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        g_hid_scrn_cntx.gid, 
        SCR_BT_REMOTE_CTRL_DISC_CONFIRM, 
        (FuncPtr)mmi_hid_entry_disc_confirm,
        NULL);
    
    srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_QUERY), NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_hid_entry_disc_confirm
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_RET mmi_hid_entry_disc_confirm(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *scrn_his;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)mmi_hid_entry_disc_confirm,
            MMI_FRM_FULL_SCRN))
            return MMI_RET_ERR;
    
    scrn_his = mmi_frm_scrn_get_gui_buf(info->group_id, info->scrn_id);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)GetString(STR_BT_REMOTE_CTRL_DISC_CONFIRM),
        mmi_get_event_based_image(MMI_EVENT_QUERY),
        scrn_his);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    SetLeftSoftkeyFunction(mmi_hid_disc_confirm_lsk, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_hid_disc_confirm_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_hid_disc_confirm_rsk, KEY_EVENT_UP);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hid_disc_confirm_rsk
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hid_disc_confirm_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(g_hid_scrn_cntx.gid, SCR_BT_REMOTE_CTRL_DISC_CONFIRM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hid_disc_confirm_lsk
 * DESCRIPTION
 *  This function is the LSK handler of disconnect confirm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hid_disc_confirm_lsk(void)
{
    if (HID_RESULT_PENDING == mmi_hidd_disconnect())
        mmi_hid_show_progress(g_hid_scrn_cntx.gid, HID_PROG_DISC);
    else
        mmi_hid_show_result(HID_E_DISC_SUCC);
}


/*****************************************************************************
* FUNCTION
*  mmi_hid_desktop_key_up_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_desktop_key_up_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    MMI_HID_LOG2(DESKTOPX_KEY_UP_EVENT_CALLBACK,keycode,keytype);
    
    delay_repeat_event = 0;

    
    for (key_idx=0; key_idx < HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
        if (hid_control_data_desktop[key_idx].key_code == keycode &&
            hid_control_data_desktop[key_idx].key_type == keytype )
        {
            break;
        }
    }

    if (key_idx >= HID_NUM_OF_CTRL_DATA)
    {
        return;
    }

    if(hid_control_data_desktop[key_idx].ctrl_data[0] == 0x02)
    {
        data_len = 4;
    }
    else
    {
        data_len = 9;
    }
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_desktop[key_idx].ctrl_data);
}


/*****************************************************************************
* FUNCTION
*  mmi_hid_desktop_key_repeat_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_desktop_key_repeat_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    for (key_idx=0; key_idx < HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
        if (keycode >= KEY_UP_ARROW && keycode <= KEY_RIGHT_ARROW)
        {
            if (hid_control_data_desktop[key_idx].key_code == keycode &&
                hid_control_data_desktop[key_idx].key_type == KEY_EVENT_UP )
            {
                break;
            }
        }
        else
        {
            if (hid_control_data_desktop[key_idx].key_code == keycode &&
                hid_control_data_desktop[key_idx].key_type == KEY_EVENT_UP )
            {
                break;
            }
        }
    }

    if (key_idx >= HID_NUM_OF_CTRL_DATA)
    {
        return;
    }

    if (!(keycode >= KEY_UP_ARROW && keycode <= KEY_RIGHT_ARROW))
    {
        if (delay_repeat_event > HID_KEY_DELAY_REPEAT_PERIOD)
        {   
            delay_repeat_event = 0;
        }
        else
        {

            delay_repeat_event++;
            return;
        }
    }

    if(hid_control_data_desktop[key_idx].ctrl_data[0] == 0x02)
    {
        data_len = 4;
    }
    else
    {
        data_len = 9;
    }
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_desktop[key_idx].ctrl_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_hid_desktop
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_hid_entry_desktop(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined( __MMI_BT_BTBOX_NOLCD__)

    U8 *scrn_his;
    wgui_cat95_panel_element_struct element[17];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)mmi_hid_entry_desktop,
            MMI_FRM_FULL_SCRN))
            return MMI_RET_ERR;

    scrn_his = mmi_frm_scrn_get_gui_buf(info->group_id, info->scrn_id);

    for(i = 0; i < 6; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_1+i;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_hid_desktop_key_up_event_callback;
        element[i].repeat_event_callback = mmi_hid_desktop_key_repeat_event_callback;
        element[i].disable_imageid = DESKTOP_IMG_01_DISALBE+i*4;
        element[i].off_imageid = DESKTOP_IMG_01_OFF+i*4;
        element[i].on_imageid = DESKTOP_IMG_01_ON+i*4;
        element[i].down_imageid = DESKTOP_IMG_01_DOWN+i*4;
    }
    for(i = 6; i < 12; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_1+i;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_hid_desktop_key_up_event_callback;
        element[i].repeat_event_callback = mmi_hid_desktop_key_repeat_event_callback;
        element[i].disable_imageid = DESKTOP_IMG_12_DISALBE;
        element[i].off_imageid = DESKTOP_IMG_12_OFF;
        element[i].on_imageid = DESKTOP_IMG_12_ON;
        element[i].down_imageid = DESKTOP_IMG_12_DOWN;
    }

	i= 7;
	element[i].x = hid_icon_pos[i][0];
	element[i].y = hid_icon_pos[i][1];
	element[i].width = hid_icon_pos[i][2];
	element[i].height = hid_icon_pos[i][3];
	element[i].keycode = KEY_1+i;
	element[i].down_event_callback = NULL; 
	element[i].up_event_callback = mmi_hid_desktop_key_up_event_callback;
	element[i].repeat_event_callback = mmi_hid_desktop_key_repeat_event_callback;
	element[i].disable_imageid = DESKTOP_IMG_08_DISALBE;
	element[i].off_imageid = DESKTOP_IMG_08_OFF;
	element[i].on_imageid = DESKTOP_IMG_08_ON;
	element[i].down_imageid = DESKTOP_IMG_08_DOWN;
    element[9].keycode = KEY_STAR;
    element[10].keycode = KEY_0;
    element[11].keycode = KEY_POUND;

    
    for(i = 12; i < 16; i++)//up, donw, left, right
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_UP_ARROW+i-12;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_hid_desktop_key_up_event_callback;
        element[i].repeat_event_callback = mmi_hid_desktop_key_repeat_event_callback;
        element[i].disable_imageid = MOUSE_IMG_UP_DISALBE+(i-12)*4;
        element[i].off_imageid = MOUSE_IMG_UP_OFF+(i-12)*4;
        element[i].on_imageid = MOUSE_IMG_UP_ON+(i-12)*4;
        element[i].down_imageid = MOUSE_IMG_UP_DOWN+(i-12)*4;
    }
    
    //center key for displaing mouse only, no key handler
    element[16].x = hid_icon_pos[16][0];
    element[16].y = hid_icon_pos[16][1];
    element[16].width = hid_icon_pos[16][2];
    element[16].height = hid_icon_pos[16][3];
    element[16].keycode = KEY_INVALID;
    element[16].down_event_callback = NULL; 
    element[16].up_event_callback = mmi_hid_desktop_key_up_event_callback;
    element[16].repeat_event_callback = mmi_hid_desktop_key_repeat_event_callback;
#if !defined(__MMI_MAINLCD_128X128__)
    element[16].disable_imageid = MOUSE_IMG_COMMON;
    element[16].off_imageid = MOUSE_IMG_COMMON;
    element[16].on_imageid = MOUSE_IMG_COMMON;
    element[16].down_imageid = MOUSE_IMG_COMMON;
#endif /*(__MMI_MAINLCD_128X128__)*/

    mmi_hid_set_element_enable(HID_ELEMENT_DESKTOP, element, 17);
    
    ShowCategory95Screen(
        (U8 *)GetString(STR_BT_REMOTE_CTRL_DESKTOP), 
        (U16)NULL, 
        (U16)NULL, 
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        HID_IMG_BG, 
        element, 
        17, 
        0, 
        HID_KEY_REPEAT_PERIOD,
        scrn_his);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif /* __MMI_BT_BTBOX_NOLCD__*/
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_hid_media_player_key_up_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_media_player_key_up_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    MMI_HID_LOG2(MEDIA_PLAYER_KEY_UP_EVENT_CALLBACK,keycode,keytype);
    
    delay_repeat_event = 0;
   
    for (key_idx=0; key_idx < HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
        if (hid_control_data_media_player[key_idx].key_code == keycode &&
            hid_control_data_media_player[key_idx].key_type == keytype )
        {
            break;
        }
    }

    if (key_idx >= HID_NUM_OF_CTRL_DATA)
    {
        return;
    }

    if(hid_control_data_media_player[key_idx].ctrl_data[0] == 0x02)
    {
        data_len = 4;
    }
    else
    {
        data_len = 9;
    }
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_media_player[key_idx].ctrl_data);
}


/*****************************************************************************
* FUNCTION
*  mmi_hid_media_player_key_repeat_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_media_player_key_repeat_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    for (key_idx=0; key_idx < HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
        if (keycode >= KEY_UP_ARROW && keycode <= KEY_RIGHT_ARROW)
        {
            if (hid_control_data_media_player[key_idx].key_code == keycode &&
                hid_control_data_media_player[key_idx].key_type == KEY_EVENT_UP )
            {
                break;
            }
        }
        else
        {
            if (hid_control_data_media_player[key_idx].key_code == keycode &&
                hid_control_data_media_player[key_idx].key_type == KEY_EVENT_UP )
            {
                break;
            }
        }
    }

    if (key_idx >= HID_NUM_OF_CTRL_DATA)
    {
        return;
    }

    if (!(keycode >= KEY_UP_ARROW && keycode <= KEY_RIGHT_ARROW))
    {
        if (delay_repeat_event > HID_KEY_DELAY_REPEAT_PERIOD)
        {   
            delay_repeat_event = 0;
        }
        else
        {

            delay_repeat_event++;
            return;
        }
    }


    if(hid_control_data_media_player[key_idx].ctrl_data[0] == 0x02)
    {
        data_len = 4;
    }
    else
    {
        data_len = 9;
    }
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_media_player[key_idx].ctrl_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_hid_media_player
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_hid_entry_media_player(mmi_scrn_essential_struct *info)
{
#if !defined( __MMI_BT_BTBOX_NOLCD__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *scrn_his;
    wgui_cat95_panel_element_struct element[17];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)mmi_hid_entry_media_player,
            MMI_FRM_FULL_SCRN))
            return MMI_RET_ERR;

    scrn_his = mmi_frm_scrn_get_gui_buf(info->group_id, info->scrn_id);

    for(i = 0; i < 8; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_1+i;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_hid_media_player_key_up_event_callback;
        element[i].repeat_event_callback = mmi_hid_media_player_key_repeat_event_callback;
        element[i].disable_imageid = MEDIA_PLAYER_IMG_01_DISALBE+i*4;
        element[i].off_imageid = MEDIA_PLAYER_IMG_01_OFF+i*4;
        element[i].on_imageid = MEDIA_PLAYER_IMG_01_ON+i*4;
        element[i].down_imageid = MEDIA_PLAYER_IMG_01_DOWN+i*4;
    }
	

	element[6].disable_imageid = MEDIA_PLAYER_IMG_10_DISALBE;
	element[6].off_imageid = MEDIA_PLAYER_IMG_10_OFF;
	element[6].on_imageid = MEDIA_PLAYER_IMG_10_ON;
	element[6].down_imageid = MEDIA_PLAYER_IMG_10_DOWN;
	element[7].disable_imageid = MEDIA_PLAYER_IMG_11_DISALBE;
	element[7].off_imageid = MEDIA_PLAYER_IMG_11_OFF;
	element[7].on_imageid = MEDIA_PLAYER_IMG_11_ON;
	element[7].down_imageid = MEDIA_PLAYER_IMG_11_DOWN;

	for(i = 8; i < 12; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_1+i;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_hid_media_player_key_up_event_callback;
        element[i].repeat_event_callback = mmi_hid_media_player_key_repeat_event_callback;
        element[i].disable_imageid = MEDIA_PLAYER_IMG_12_DISALBE;
        element[i].off_imageid = MEDIA_PLAYER_IMG_12_OFF;
        element[i].on_imageid = MEDIA_PLAYER_IMG_12_ON;
        element[i].down_imageid = MEDIA_PLAYER_IMG_12_DOWN;
    }
    element[9].keycode = KEY_STAR;
    element[10].keycode = KEY_0;
    element[11].keycode = KEY_POUND;

    
    for(i = 12; i < 16; i++)//up, donw, left, right
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_UP_ARROW+i-12;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_hid_media_player_key_up_event_callback;
        element[i].repeat_event_callback = mmi_hid_media_player_key_repeat_event_callback;
        element[i].disable_imageid = MOUSE_IMG_UP_DISALBE+(i-12)*4;
        element[i].off_imageid = MOUSE_IMG_UP_OFF+(i-12)*4;
        element[i].on_imageid = MOUSE_IMG_UP_ON+(i-12)*4;
        element[i].down_imageid = MOUSE_IMG_UP_DOWN+(i-12)*4;
    }
    
    //center key for displaing mouse only, no key handler
    element[16].x = hid_icon_pos[16][0];
    element[16].y = hid_icon_pos[16][1];
    element[16].width = hid_icon_pos[16][2];
    element[16].height = hid_icon_pos[16][3];
    element[16].keycode = KEY_INVALID;
    element[16].down_event_callback = NULL; 
    element[16].up_event_callback = mmi_hid_media_player_key_up_event_callback;
    element[16].repeat_event_callback = mmi_hid_media_player_key_repeat_event_callback;
#if !defined(__MMI_MAINLCD_128X128__)
    element[16].disable_imageid = MOUSE_IMG_COMMON;
    element[16].off_imageid = MOUSE_IMG_COMMON;
    element[16].on_imageid = MOUSE_IMG_COMMON;
    element[16].down_imageid = MOUSE_IMG_COMMON;
#endif /*(__MMI_MAINLCD_128X128__)*/

    mmi_hid_set_element_enable(HID_ELEMENT_MEDIAPLAYER, element, 17);
    
    ShowCategory95Screen(
        (U8 *)GetString(STR_BT_REMOTE_CTRL_MEDIA_PLAYER), 
        (U16)NULL, 
        (U16)NULL, 
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        HID_IMG_BG, 
        element, 
        17, 
        0, 
        HID_KEY_REPEAT_PERIOD,
        scrn_his);
 
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif /*!defined( __MMI_BT_BTBOX_NOLCD__)*/
    return MMI_RET_OK;
}

#ifdef __MMI_HID_PRESENTER__
/*****************************************************************************
* FUNCTION
*  mmi_hid_presenter_key_up_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_presenter_key_up_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    MMI_HID_LOG2(PRESENTER_KEY_UP_EVENT_CALLBACK,keycode,keytype);
    
    delay_repeat_event = 0;

    
    for (key_idx=0; key_idx < HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
        if (hid_control_data_presenter[key_idx].key_code == keycode &&
            hid_control_data_presenter[key_idx].key_type == keytype )
        {
            break;
        }
    }

    if (key_idx >= HID_NUM_OF_CTRL_DATA)
    {
        return;
    }

    if(hid_control_data_presenter[key_idx].ctrl_data[0] == 0x02)
    {
        data_len = 4;
    }
    else
    {
        data_len = 9;
    }
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_presenter[key_idx].ctrl_data);
}
/*****************************************************************************
* FUNCTION
*  mmi_hid_presenter_key_repeat_event_callback
* DESCRIPTION
*  This function is to
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_hid_presenter_key_repeat_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    U8 data_len;
    U32 key_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    for (key_idx=0; key_idx < HID_NUM_OF_CTRL_DATA; key_idx++ )
    {
        if (keycode == KEY_2 || keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6)
        {
            if (hid_control_data_presenter[key_idx].key_code == keycode &&
                hid_control_data_presenter[key_idx].key_type == KEY_EVENT_UP )
            {
                break;
            }
        }
        else
        {
            if (hid_control_data_presenter[key_idx].key_code == keycode &&
                hid_control_data_presenter[key_idx].key_type == KEY_EVENT_UP )
            {
                break;
            }
        }
    
    }

    if (key_idx >= HID_NUM_OF_CTRL_DATA)
        return;

    if (!(keycode == KEY_2 || keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6))
    {
        if (delay_repeat_event > HID_KEY_DELAY_REPEAT_PERIOD)
            delay_repeat_event = 0;
        else
        {
            delay_repeat_event++;
            return;
        }
    }

    if(hid_control_data_presenter[key_idx].ctrl_data[0] == 0x02)
        data_len = 4;
    else
        data_len = 9;
    
    mmi_bth_hidd_interrupt_data_req_hdler(data_len, (U8 *)hid_control_data_presenter[key_idx].ctrl_data);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_hid_presenter
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_hid_entry_presenter(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *scrn_his;
    wgui_cat95_panel_element_struct element[17];
    S32 i;
#if !defined( __MMI_BT_BTBOX_NOLCD__)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)mmi_hid_entry_presenter,
            MMI_FRM_FULL_SCRN))
            return MMI_RET_ERR;

    scrn_his = mmi_frm_scrn_get_gui_buf(info->group_id, info->scrn_id);

    for(i = 0; i < 12; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_1+i;
        element[i].down_event_callback = NULL;        
        element[i].up_event_callback = mmi_hid_presenter_key_up_event_callback;
        element[i].repeat_event_callback = mmi_hid_presenter_key_repeat_event_callback;
        element[i].disable_imageid = PRESENTER_IMG_01_DISALBE+i*4;
        element[i].off_imageid = PRESENTER_IMG_01_OFF+i*4;
        element[i].on_imageid = PRESENTER_IMG_01_ON+i*4;
        element[i].down_imageid = PRESENTER_IMG_01_DOWN+i*4;
    }
    element[9].keycode = KEY_STAR;
    element[10].keycode = KEY_0;
    element[11].keycode = KEY_POUND;

    
    for(i = 12; i < 16; i++)//up, donw, left, right
    {
        element[i].x = hid_icon_pos[i][0];
        element[i].y = hid_icon_pos[i][1];
        element[i].width = hid_icon_pos[i][2];
        element[i].height = hid_icon_pos[i][3];
        element[i].keycode = KEY_UP_ARROW+i-12;
        element[i].down_event_callback = NULL; 
        element[i].up_event_callback = mmi_hid_presenter_key_up_event_callback;
        element[i].repeat_event_callback = mmi_hid_presenter_key_repeat_event_callback;
        element[i].disable_imageid = PRESENTER_MOUSE_IMG_UP_DISALBE+(i-12)*4;
        element[i].off_imageid = PRESENTER_MOUSE_IMG_UP_OFF+(i-12)*4;
        element[i].on_imageid = PRESENTER_MOUSE_IMG_UP_ON+(i-12)*4;
        element[i].down_imageid = PRESENTER_MOUSE_IMG_UP_DOWN+(i-12)*4;
    }

    mmi_hid_set_element_enable(HID_ELEMENT_PRESENTER, element, 17);
    
    ShowCategory95Screen(
        (U8 *)GetString(STR_BT_REMOTE_CTRL_PRESENTER), 
        (U16)NULL, 
        (U16)NULL, 
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        HID_IMG_BG, 
        element, 
        16, 
        0, 
        HID_KEY_REPEAT_PERIOD,
        scrn_his);
 
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif /*!defined( __MMI_BT_BTBOX_NOLCD__)*/
    return MMI_RET_OK;
}
#endif

#ifdef __MMI_HID_KEYBOARD__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_hid_keyboard
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_hid_entry_keyboard(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *scrn_his;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)mmi_hid_entry_keyboard,
            MMI_FRM_FULL_SCRN))
            return MMI_RET_ERR;

    scrn_his = mmi_frm_scrn_get_gui_buf(info->group_id, info->scrn_id);

    if (scrn_his == NULL)
        memset(g_hid_scrn_cntx.key_cmd, 0, sizeof(g_hid_scrn_cntx.key_cmd));

    ShowCategory5Screen_ext(
        STR_BT_REMOTE_CTRL_KEYBOARD,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        IMM_INPUT_TYPE_ENGLISH_SENTENCE,
        (U8 *)g_hid_scrn_cntx.key_cmd,
        2,
        scrn_his,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL);

    SetLeftSoftkeyFunction(mmi_hid_keyboard_send_cmd, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_frm_scrn_close_active_id);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_hid_keyboard_send_cmd, KEY_EVENT_UP);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hid_keyboard_send_cmd
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hid_keyboard_send_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_hid_scr_cntx_struct *cntx = &g_hid_scrn_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_wcslen(cntx->key_cmd) == 0)
    {
        mmi_popup_display(
            (WCHAR *)GetString(STR_BT_UNSUPPORTED_KEY_CMD),
            MMI_EVENT_FAILURE,
            NULL);
    }
    else
    {   
        /* the key cmd is defined in the keyboard/keypad page section of the HID Usage Table(HUT) specification */
        if (cntx->key_cmd[0] >= 'a' && cntx->key_cmd[0] <= 'z') 
        {
            hid_key_cmd[3] = cntx->key_cmd[0] - 0x61 + 0x04;
        }
        else if(cntx->key_cmd[0] >= 'A' && cntx->key_cmd[0] <= 'Z')
        {
            hid_key_cmd[3] = cntx->key_cmd[0] - 0x41 + 0x04;
        }
        else if(cntx->key_cmd[0] > '0' && cntx->key_cmd[0] <= '9')
        {
            hid_key_cmd[3] = cntx->key_cmd[0] - 0x31 + 0x1E;
        }
        else if (cntx->key_cmd[0] == '0')
        {
            hid_key_cmd[3] = 0x27;
        }
        else
        {
            mmi_popup_display(
                (WCHAR *)GetString(STR_BT_UNSUPPORTED_KEY_CMD),
                MMI_EVENT_FAILURE,
                NULL);
            return;
        }
        
        /* send this kbd cmd to remote device */
        mmi_bth_hidd_interrupt_data_req_hdler(sizeof(hid_key_cmd), hid_key_cmd);

    }
}

#endif /*__MMI_HID_KEYBOARD__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_hid_entry_connecting
 * DESCRIPTION
 *  This function is the entry function of connecting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_hid_entry_connecting(mmi_scrn_essential_struct *info)
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
            (FuncPtr)mmi_hid_entry_connecting,
            MMI_FRM_FULL_SCRN))
            return MMI_RET_ERR;

    ShowCategory66Screen(
        STR_GLOBAL_CONNECTING, 
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0, 0, 0, 0,
        (U8*)GetString(STR_GLOBAL_CONNECTING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hid_entry_disconnecting
 * DESCRIPTION
 *  This function is the entry function of disconnecting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_hid_entry_disconnecting(mmi_scrn_essential_struct *info)
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
            (FuncPtr)mmi_hid_entry_disconnecting,
            MMI_FRM_FULL_SCRN))
            return MMI_RET_ERR;

    ShowCategory66Screen(
        STR_GLOBAL_DISCONNECTING, 
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0, 0, 0, 0,
        (U8*)GetString(STR_GLOBAL_DISCONNECTING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hid_set_element_enable
 * DESCRIPTION
 *  This function is to decide whether enable or disable HID elements
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hid_set_element_enable(U8 type, wgui_cat95_panel_element_struct *element, U8 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    const mmi_bt_hid_key_control_data_struct *data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type < HID_ELEMENT_COUNT);

    switch (type)
    {
    case HID_ELEMENT_DESKTOP:
        data = hid_control_data_desktop;
        break;
    case HID_ELEMENT_MEDIAPLAYER:
        data = hid_control_data_media_player;
        break;
#ifdef __MMI_HID_PRESENTER__
    case HID_ELEMENT_PRESENTER:
        data = hid_control_data_presenter;
        break;
#endif /*__MMI_HID_PRESENTER__*/
    default:
        return;
    }
    
    for (i = 0; i < count; i++)
    {
        if (element[i].keycode == KEY_INVALID)
        {
            element[i].enabled = MMI_FALSE;
            continue;
        }
        
        for (j = 0; j < HID_NUM_OF_CTRL_DATA; j++)
        {
            if (data[j].key_code == element[i].keycode)
            {
                if (data[j].status == HID_ACTIVE_BTN)
                {
                    element[i].enabled = MMI_TRUE;
                }
                else
                {
                    element[i].enabled = MMI_FALSE;
                }
                break;
            }
        }
        if (j == HID_NUM_OF_CTRL_DATA)
        {
            element[i].enabled = MMI_FALSE;
        }
    }
}

#endif /* __MMI_HIDD_SUPPORT__ */

