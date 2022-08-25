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
 * DataAccount.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#ifndef _DATA_ACCOUNT_PROT_H
#define _DATA_ACCOUNT_PROT_H

#include "wgui_inline_edit.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "DataAccountDef.h"
#include "DataAccountStruct.h"
#include "MMIDataType.h"
#include "DtcntSrvIprot.h"
#include "DataAccountEnum.h"
#include "DataAccountGProt.h"
#include "supc_abm_msgs.h"

// CSD/GPRS
#define DTCNT_DYNAMIC_SIM_NAME_MAX_LEN (30)

#if defined(__DA_SMART_SELECTION_SUPPORT__)
extern void mmi_dtcnt_xml_parse(kal_wchar *file_name); /* from xml parser */
extern U8 mmi_dtcnt_sim_match(const CHAR *operator, const CHAR *code);
extern void mmi_dtcnt_account_item_start(
                S32 bearer, 
                srv_dtcnt_prof_common_header_struct **comm_dtcnt_data, 
                U8 **acct_name, 
                U8 **addr, 
                srv_dtcnt_prof_csd_dial_type_enum **dialType, 
                srv_dtcnt_prof_csd_rate_enum **dataRate);
extern void mmi_dtcnt_account_item_end(
                S32 bearer, 
                srv_dtcnt_prof_common_header_struct *comm_dtcnt_data, 
                U8 *acct_name, 
                U8 *addr);
extern void mmi_dtcnt_account_parse_end(S32 ret);
extern S32 mmi_dtcnt_get_type(mmi_dtcnt_type_enum option, const CHAR *name);
extern void mmi_dtcnt_get_address(U8 *ip, const CHAR *data);
extern int mmi_custom_account_get_apptype(const char *name);
#endif /* __DA_SMART_SELECTION_SUPPORT__ */
extern void *custom_config_get_account(kal_int32 type);

extern void PreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);
extern void ReturnThreeDigitString(PU8 StringVal, U8 DigitVal);
extern S16 mmi_dtcnt_validate_url(U8 *url_p, MMI_BOOL b_blank_url_is_valid);
extern U32 mmi_dtcnt_get_available_sim_num(void);
extern MMI_BOOL mmi_dtcnt_is_account_in_use(U32 account_id);
extern MMI_BOOL mmi_dtcnt_get_ready_status(void);

// utils
extern U8 mmi_dtcnt_util_is_call_interrupt_allow(void);
extern MMI_BOOL mmi_dtcnt_util_hash_value_is_empty(U8* hash_value, U16 length);
extern MMI_BOOL mmi_dtcnt_util_hash_value_is_equal(U8* hash_value1, U8* hash_value2, U16 length);


#ifdef __MMI_WLAN_FEATURES__

extern mmi_wlan_profile_struct g_wlan_prof_list[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_profile_struct *g_wlan_profile[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_display_struct g_wlan_display_context;
extern mmi_wlan_setting_struct g_wlan_setting_context;

#endif /* __MMI_WLAN_FEATURES__ */ 

#ifdef __MMI_WLAN_FEATURES__
//extern void mmi_wlan_init(void);
extern void mmi_wlan_entry_eap_type(void);

extern void mmi_wlan_send_init_req(void);
extern void mmi_wlan_send_deinit_req(void);
extern void mmi_wlan_send_connect_req(mmi_wlan_profile_struct *data);
extern void mmi_wlan_send_disconnect_req(void);
extern void mmi_wlan_send_ap_list_req(void);
extern void mmi_wlan_save_blacklist_ap(supc_abm_bss_info_struct *connected_ap);

extern void mmi_wlan_abm_ipaddr_change_req_hdlr(void);
extern void mmi_wlan_abm_wifi_init_req_hdlr(void);
extern void mmi_wlan_abm_wifi_init_cnf_hdlr(void *);
extern void mmi_wlan_abm_wifi_deinit_req_hdlr(void);
extern void mmi_wlan_abm_wifi_deinit_cnf_hdlr(void *);
extern void mmi_wlan_abm_wifi_connect_req_hdlr(void *);
extern void mmi_wlan_abm_wifi_connect_cnf_hdlr(void *);
extern void mmi_wlan_abm_wifi_connect_ind_hdlr(void *);
extern void mmi_wlan_abm_wifi_disconnect_req_hdlr(void);
extern void mmi_wlan_abm_wifi_disconnect_cnf_hdlr(void *);
extern void mmi_wlan_abm_wifi_disconnect_ind_hdlr(void *);
extern void mmi_wlan_abm_wifi_ap_list_req_hdlr(void);
extern void mmi_wlan_abm_wifi_ap_list_cnf_hdlr(void *);
extern void mmi_wlan_abm_ipaddr_update_ind_hdlr(void *info);
extern void mmi_wlan_supc_mmi_wifi_curr_ap_info_ind_hdlr(void *);
extern void mmi_wlan_abm_wifi_activate_req_ind_hdlr(void *);
extern void mmi_wlan_abm_wifi_deactivate_req_ind_hdlr(void *);
extern void mmi_wlan_abm_ipaddr_conflict_ind_hdlr(void *info);
extern void mmi_wlan_redraw_conn_status_screen(void);
extern void mmi_wlan_redraw_network_settings_screen(void);
extern void mmi_wlan_fullline_edit_screen(void);
extern void mmi_wlan_entry_new_wizard_list(void);
extern void mmi_wlan_enable_entry_main(void);

extern void mmi_wlan_update_conn_status_str(void);
extern void mmi_wlan_update_signal_level_icon(void);
extern void mmi_wlan_update_status_icon(U16 image_id, BOOL animate);
extern MMI_BOOL mmi_wlan_is_profile_matched_searched(supc_abm_bss_info_struct *searched, mmi_wlan_profile_struct *saved);

extern void mmi_wlan_init_profile(mmi_wlan_profile_struct *profile);
extern void bssinfo_to_profile(
                mmi_wlan_profile_struct *prof,
                const supc_abm_bss_info_struct *bssinfo,
                const char *passphrase,
                int keylen);
extern kal_bool encode_eap_profile(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile);
extern void mmi_wlan_save_default_eap_to_profile(mmi_wlan_profile_struct *prof);
extern void mmi_wlan_save_default_eap(void);
extern void mmi_wlan_entry_define_network(void);
extern void delete_action(wlan_action_struct **handle, wlan_action_enum action);
extern void add_action(wlan_action_struct **handle, wlan_action_enum action, void *data);
extern void pbkdf2_sha1(
                const char *passphrase,
                const char *ssid,
                kal_uint16 ssid_len,
                int iterations,
                kal_uint8 *buf,
                kal_uint16 buflen);

#endif /* __MMI_WLAN_FEATURES__ */ 
#endif /* _DATA_ACCOUNT_PROT_H */ 

