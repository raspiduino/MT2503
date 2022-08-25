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
 * ABM_UTIL.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the utilities functions of ABM.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _ABM_UTIL_H
#define _ABM_UTIL_H

#include "abm_api.h"
#include "abm_soc_enums.h"
#include "abm_main.h"
#include "abm2soc_struct.h"


#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "cbm_consts.h"
#include "tcm_api.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "abm_def.h"
#include "ps_public_struct.h"
#include "nvram_editor_data_item.h"
#include "cbm_api.h"
#include "mmi2abm_struct.h"

#ifdef __GAS_SUPPORT__
#include "rmmi_struct.h"

/* GAS AT command */
#define ABM_GAS_WIFI_TURN_ON_CMD        "AT+EWIFI=1"
#define ABM_GAS_WIFI_TURN_OFF_CMD       "AT+EWIFI=0"
#define ABM_GAS_WIFI_SCAN_AP_LIST_CMD   "AT+EWIFI=2"

/* GAS AT commoand response */
#define ABM_GAS_RET_OK                  "\r\nOK\r\n"
#define ABM_GAS_RET_ERROR               "\r\nERROR\r\n"
#define ABM_GAS_RET_WIFI_AP_END_INFO    "\r\n+EWIFIAP:LASTAPLAST\r\n\r\nOK\r\n"

/* GAS AT command response data format */
#define ABM_GAS_FMT_WIFI_MAC_ADDR       "\r\n+EWIFI:%s\r\n\r\nOK\r\n"
#define ABM_GAS_FMT_WIFI_AP_PRE_INFO    "\r\n+EWIFIAP:%s,%d,"
#define ABM_GAS_FMT_WIFI_AP_POST_INFO   ",%d,%d,%d\r\n"
#define ABM_GAS_FMT_WIFI_AP_END_INFO    "\r\n+EWIFIAP:LASTAPLAST\r\n\r\nOK\r\n"
#endif /* __GAS_SUPPORT__ */

extern kal_bool abm_check_msg(ilm_struct *ilm_ptr);

extern void abm_send_bearer_info_ind2mmi(
                                        kal_uint8  connect_type, cbm_bearer_enum bearer_type,
                                        kal_uint32 profile_id, cbm_bearer_state_enum  status);

extern void abm_send_bearer_info_ind2app(abm_app_id_struct *app_id,
                                         kal_uint32 account_id,
                                         kal_uint32 real_account_id,
                                         kal_uint8 qos_profile_id,
                                         cbm_bearer_state_enum state,
                                         cbm_bearer_enum bearer,
                                         kal_uint8 ip_addr[],
                                         kal_uint16 error_cause,
                                         cbm_result_error_enum error,
                                         nvram_editor_qos_struct *qos);

extern void abm_send_msg2l4c(msg_type msg_id, kal_uint8 sim_info, local_para_struct *p_local_para);

extern void abm_send_act_cnf2soc(
        module_type mod_id,
        cbm_bearer_enum bearer,
        kal_uint32 nw_acc_id,
        kal_uint32  activate_nw_acc_id,
        kal_uint8 qos_profile_id,
        kal_uint8 bearer_ctx_id,
        kal_bool qos_fulfilled,
        kal_uint8 *ip_addr,
        kal_uint8 *pri_dns_addr,
        kal_uint8 *sec_dns_addr,
        kal_uint8 *gateway,
        kal_uint8 *netmask,
        kal_uint8 *mac_addr,
        kal_uint8 dhcp_state,
        kal_uint16 mtu);

extern void abm_send_deact_cnf2soc(module_type mod_id,
                                   kal_uint32 nw_acc_id,
                                   kal_uint8 qos_profile,
                                   kal_uint8 context_id);

extern void abm_send_bearer_init_ind2mmi(abm_app_id_struct *app,
                                                  kal_uint32 state,
                                                  kal_uint32 account_id);

extern kal_int8 abm_save_temp_qos_profile(soc_abm_activate_req_struct *req);

extern void abm_send_bearer_event2app(msg_type msg_id,
                                      abm_app_id_struct *app,
                                                     cbm_app_bearer_event_enum event,
                                                     kal_uint32 account_id);

extern void abm_send_rej2soc(msg_type msg_id,
                      module_type     mod_id,
                      cbm_bearer_enum bearer,
                      kal_uint16 err_cause,
                      kal_uint16 cause,
                      kal_uint32 nw_acc_id,
                      kal_uint8 qos_profile,
                      kal_uint8 bearer_ctx,
                      kal_bool qos_fulfilled);
extern void abm_reset_app_slot(abm_app_proc_struct *app_proc, kal_uint8 acct_slot);
#ifdef  __CBM_BEARER_SWITCH__
extern kal_bool abm_check_bearer_fallback_L2(abm_app_proc_struct *app_proc, kal_uint8 acct_slot, kal_uint32 err_cause);
#endif

#ifdef __PS_SERVICE__
extern void abm_restore_sib_to_nvram(abm_nvram_lid_enum lid, kal_uint16 record_no, kal_uint8 access_id);

extern void abm_gprs_send_setup_req2l4c(kal_uint32 account_id,
                                 l4c_gprs_account_info_struct *ps_profile,
                                 nvram_ef_abm_ps_qos_profile_struct *qos_profile, 
                                 kal_uint8 profile_type, kal_uint8 sim_id, 
                                 soc_abm_activate_req_struct *req);
extern kal_bool abm_get_ps_slot(kal_uint8 state, kal_uint8 *id);
extern kal_bool abm_get_ps_slot_by_acct_id(kal_uint32 nw_acct_id,
                                             kal_uint8 qos_profile,
                                             kal_uint8 context_id,
                                             kal_uint8 *id);
extern kal_bool abm_l4c_ps_is_gprs_detached(cbm_sim_id_enum sim_id);
#endif /* __PS_SERVICE__ */

extern void abm_send_bearer_req2tcpip(kal_uint32 nw_acc_id,
                               kal_uint32 ext_if_acct_id,
                               kal_uint8 context_id,
                               cbm_bearer_enum bearer,
                               kal_uint16 mtu,
                               kal_bool is_activated,
                               kal_uint8 ip_addr[],
                               kal_uint8 netmask[],
                               kal_uint8 gateway[],
                               kal_uint8 mac_addr[],
                               kal_int32 cause);
extern abm_app_proc_struct *abm_get_app_slot(abm_app_id_struct *app_id);
extern kal_bool abm_get_app_acct_slot(
                               kal_uint32 ori_account_id,
                               kal_uint32 rel_account_id,
                               kal_uint8 qos_profile_id,
                               abm_app_proc_struct *app_proc,
                               kal_uint8 *idx);
#ifdef __APP_SECONDARY_PDP_SUPPORT__
extern kal_bool abm_find_qos_slot(kal_uint32 account_id, kal_uint8 qos_profile_id, kal_uint8 *idx);
extern kal_bool abm_find_free_acc_slot(kal_uint8 *idx);
extern void abm_copy_downlink_filter(soc_abm_dl_filter_struct* abm_filter,
                                soc_abm_dl_filter_struct* app_filter);
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */
extern kal_bool abm_get_app_and_acct_slot(kal_uint8 account_id,
                                          kal_uint8 qos_profile_id,
                                          abm_app_proc_struct *app_proc,
                                          kal_uint8 *idx);
extern abm_app_proc_struct *abm_find_app_proc(module_type mod_id, kal_uint8 app_id);
extern void abm_app_free_nwk_neg_qos(kal_uint8 idx);
extern nvram_editor_qos_struct *abm_app_get_nwk_neg_qos(kal_uint8 idx);
extern void abm_app_update_nwk_neg_qos(kal_uint8 idx,
                                       kal_uint8 account_id,
                                       kal_uint8 context_id,
                                       nvram_editor_qos_struct *qos);
extern kal_bool abm_app_find_nwk_neg_qos_slot(kal_uint8 *idx,
                                              kal_uint8 account_id,
                                              kal_uint8 context_id);
extern kal_bool abm_app_get_free_nwk_neg_qos_slot(kal_uint8 *idx);
extern kal_bool abm_app_find_free_acc_slot(abm_app_proc_struct *app_proc, 
                                            kal_uint32 account_id,
                                            kal_uint8 *idx);
extern kal_bool abm_is_app_id_valid(kal_uint8 app_id);
extern kal_int8 abm_register_app_chain_add(cbm_app_info_struct *info);
extern kal_bool abm_register_app_chain_del(kal_uint8 app_id);
extern kal_uint32 abm_cbm2abm_evt_convert(kal_uint32 evt);

extern kal_bool abm_is_app_bypass_info(kal_uint8 app_id);
extern kal_bool abm_is_mod_bypass_ip(module_type mod_id);
extern kal_bool abm_app_find_deact_acc_slot(abm_app_proc_struct *app_proc,
                                        kal_uint32 account_id,
                                        kal_uint8 qos_profile_id,
                                        kal_uint8 context_id,
                                        kal_uint8 *idx,
                                        kal_uint32 *ori_acct_id);
extern kal_bool abm_is_acct_hold(abm_app_id_struct *app, kal_uint32 ori_account_id,
                                 kal_uint32 account_id, kal_uint8 qos_profile_id, kal_uint8 context_id);
extern kal_int8 abm_set_bearer_info_event(module_type mod_id, kal_uint8 event, kal_uint8 type);
extern kal_int8 abm_get_bearer_info_event(module_type mod_id, kal_uint8 *event, kal_uint8 *type);
extern kal_bool abm_is_app_bearer_running(abm_app_proc_struct *app_proc);
extern kal_uint32 abm_state_abm2cbm_convert(kal_bool is_app_state, kal_uint32 type, kal_uint32 state);
extern kal_int8 abm_get_bearer_type(kal_uint32 account_id, cbm_bearer_enum *bearer_type);
extern void abm_get_bearer_info_from_input_msg(ilm_struct *msg, 
                                                    kal_uint32 *account_id,
                                                    kal_uint8  *qos_id,
                                                    kal_uint8  *context_id,
                                                    cbm_bearer_enum *bearer_type);
extern kal_int32 abm_get_account_profile_content(kal_uint32 account_id, 
                                                 mmi_abm_account_info_struct *profile, kal_uint8 *profile_idx);
extern kal_int8 abm_get_valid_account_id(cbm_bearer_enum bearer_type, kal_uint32 *account_id);
extern kal_bool abm_is_account_valid(kal_uint32 account_id, kal_uint32 *valid_acct_id);
extern kal_int32 abm_save_account_profile_content(kal_bool save, kal_uint32 account_id,
                                             mmi_abm_account_info_struct *profile);
extern kal_int32 abm_get_bearer_info_slot(abm_app_id_struct *app, 
                                                 kal_uint32 type);

extern kal_int8 abm_get_app_info(kal_uint8 app_id, cbm_app_info_struct *info);
extern void abm_send_share_bearer_deact_cnf_msg2mmi(kal_bool result, cbm_bearer_enum bearer);
extern void abm_send_share_bearer_act_cnf_msg2mmi(kal_bool result, cbm_bearer_enum bearer);
extern void abm_send_active_ind2dhcpd(cbm_bearer_enum bearer);
extern void abm_send_msg2extmod(msg_type msg_id, 
                                                                 module_type dst_mod_id, 
                                                                 sap_type      sap_id,
                                                                 local_para_struct *p_local_para);
extern void abm_send_activate_req2rnis(kal_uint8 context_id, kal_uint32 account_id);
extern void abm_send_net_status_ind2rndis(kal_uint32 status, kal_uint8 context_id, kal_uint32 account_id);
extern void abm_send_init_msg2hostap(void);
extern kal_int8 abm_register_app_id(cbm_app_info_struct *info,
                                                                        kal_uint8 *app_id);

extern kal_int32 abm_get_bearer_status(kal_uint32 bearer, cbm_sim_id_enum sim_id);
extern kal_int32 abm_get_bearer_status_by_account(kal_uint32 account_id);
extern kal_int32 abm_get_bearer_status_by_ap(kal_uint8 app_id, kal_uint32 bearer, cbm_sim_id_enum sim_id);

extern void abm_send_bearer_connect_result_ind2mmi(
                kal_bool result, cbm_bearer_enum bearer_type, kal_int32 cause);

extern abm_dialup_info_struct *abm_get_dialup_slot(mmi_abm_dialup_struct *info);
extern abm_dialup_info_struct *abm_update_dialup_info(
                                mmi_abm_dialup_struct *info,
                                cbm_bearer_state_enum state,
                                kal_uint32 app_state);

extern void abm_send_bearer_disconnect_cnf(kal_uint32 bearer, cbm_sim_id_enum sim_id, kal_bool result);
extern void abm_send_bearer_status_ind(cbm_bearer_enum bearer, cbm_sim_id_enum sim_id, kal_uint32 status);

extern module_type abm_sim2mod_convert(cbm_sim_id_enum sim_id);
extern cbm_sim_id_enum abm_mod2sim_convert(module_type mod_id);

#ifdef __GAS_SUPPORT__
extern void abm_gas_data_ind_hdlr(gas_data_ind_struct *ind);
extern void abm_send_gas_data_cnf(gas_data_req_struct *cnf);
#endif /* __GAS_SUPPORT__ */

#endif /* _ABM_UTIL_H */ 

