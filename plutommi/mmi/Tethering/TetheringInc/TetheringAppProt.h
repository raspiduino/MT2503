/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * TetheringAppProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Tethering application internal prototypes.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *
 *****************************************************************************/
#ifndef _TETHERING_APP_PROT_H
#define _TETHERING_APP_PROT_H
#include "mmi_features.h"

#ifdef __MMI_TETHERING__
#include "MMIDataType.h"
#include "TetheringSrvIprot.h"
#include "TetheringSrvGprot.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern mmi_ret mmi_tethering_scr_group_proc(mmi_event_struct *evt);
extern void mmi_tethering_highlight_main(void);
extern void mmi_tethering_launch(void);
extern void mmi_tethering_entry_main(void);
extern void mmi_tethering_entry_wifi(void);
extern void mmi_tethering_entry_data_account(void);
extern void mmi_tethering_entry_conn_info(void);
extern void mmi_tethering_entry_proxy(void);
extern void mmi_tethering_entry_help(void);
extern void mmi_tehering_wifi_hs_get_value_from_settings_inline(void);
extern void mmi_tethering_wifi_hs_settings_save_hdlr(void);
extern void mmi_tethering_wifi_hs_save_settings(void);
extern void mmi_tethering_wifi_hs_switch_hdlr(srv_tethering_type_enum tethering_type, MMI_BOOL result, srv_tethering_status_enum des_status, void *user_data);
extern void mmi_tethering_switch_on(srv_tethering_type_enum tethering_type);
extern void mmi_tethering_entry_switch_on_cnf_popup(void);
extern mmi_ret mmi_tethering_switch_on_cnf_hdlr(mmi_event_struct *evt);
extern void mmi_tethering_wifi_entry_turn_off_wlan_cnf_popup(void);
extern mmi_ret mmi_tethering_wifi_turn_off_wlan_cnf_hdlr(mmi_event_struct *evt);
extern void mmi_tethering_display_waiting_screen(MMI_ID parent_id);
extern mmi_ret mmi_tethering_display_waiting_screen_cb(mmi_event_struct *evt);
extern void mmi_tethering_save_dtcnt_evt_hdlr(void);
extern void mmi_tethering_display_update_settings_cnf_scr(void);
extern mmi_ret mmi_tethering_update_settings_cnf_cb(mmi_event_struct *evt);
extern void mmi_tethering_conn_info_notify_hdlr(srv_tethering_type_enum tethering_type, void *info_data, void *user_data);
extern void mmi_tethering_disconnect_notify_hdlr(srv_tethering_type_enum tethering_type, srv_tethering_disconn_cause_enum cause, void *user_data);
extern void mmi_tethering_avail_status_change_cb_hdlr(MMI_BOOL enable_flag, void *user_data);
extern void mmi_tethering_display_popup(srv_tethering_launch_result_enum result);
extern void mmi_tethering_reactivate_demand_hdlr(srv_tethering_type_enum tethering_type);
extern U32 mmi_tethering_get_curr_sim_match_acct(void);
extern void mmi_tethering_wifi_entry_ssid_editor(void);
extern void mmi_tethering_wifi_ssid_entry_full_editor_option(void);
extern void mmi_tethering_wifi_ssid_full_editor_option_done_hdlr(void);

#ifdef __MMI_TETHERING_WIFI__
extern MMI_BOOL mmi_tethering_wifi_hs_reconnect(mmi_scenario_id scen_id, void *arg);
extern void mmi_tethering_wifi_hs_reconnect_confirm(void);
extern void mmi_tethering_wifi_hs_cancel_reconnect(void);
extern mmi_ret mmi_tethering_wifi_hs_reconnect_screen_leave_proc(mmi_event_struct *para);
extern void mmi_tethering_wifi_hs_reconnect_hdlr(srv_tethering_type_enum tethering_type, MMI_BOOL result, srv_tethering_status_enum des_status, void *user_data);
#endif

// USB_TETHERING
#ifdef __USB_TETHERING__
extern mmi_ret mmi_tethering_usb_scr_group_proc(mmi_event_struct *evt);
extern void mmi_tethering_usb_launch(void);
extern void mmi_tethering_usb_entry_confirm(void);
extern MMI_BOOL mmi_tethering_usb_reconnect(mmi_scenario_id scen_id, void *arg);
extern void mmi_tethering_usb_reconnect_confirm(void);
extern void mmi_tethering_usb_cancel_reconnect(void);
extern mmi_ret mmi_tethering_usb_reconnect_screen_leave_proc(mmi_event_struct *para);
extern void mmi_tethering_usb_turn_on(void);
extern void mmi_tethering_usb_switch_hdlr(srv_tethering_type_enum tethering_type, MMI_BOOL result, srv_tethering_status_enum des_status, void *user_data);
extern void mmi_tethering_usb_group_close(void);
#endif
#endif /* __MMI_TETHERING__ */
#endif /* _TETHERING_APP_PROT_H */ 

