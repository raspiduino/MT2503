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
 * ABM_TRC.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ABM trace function.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ABM_TRC_H
#define _ABM_TRC_H

#ifndef GEN_FOR_PC
#include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "abm_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_ABM)

   /* ----------------- TRACE_STATE trace class ------------------- */
   TRC_MSG(STATE_ABM_TRANSITION, "[ABM] ret=%d, State transition! (%Mabm_account_state_enum)")
   TRC_MSG(STATE_ABM_ENTER_ACTIVE, "[ABM] State transition! (INACTIVE -> ACTIVE)")
   TRC_MSG(STATE_ABM_ENTER_INACTIVE, "[ABM] State transition! (ACTIVE -> INACTIVE)")
   TRC_MSG(STATE_ABM_APP_HDLR, "[ABM] app status hdlr=>%Mabm_app_account_state_enum")   
   TRC_MSG(STATE_ABM_BEARER_HDLR, "[ABM] bearer status hdlr=>%Mabm_account_state_enum")
    
   TRC_MSG(STATE_ABM_SOC_ACTIVE_REQ, "[ABM] Soc Active Req DA_ID = %d, sim = %d")
   TRC_MSG(STATE_ABM_SOC_DEACTIVE_REQ, "[ABM] Soc Deactive Req DA_ID = %d")
   TRC_MSG(STATE_ABM_CSD_SETUP_REQ,   "[ABM] CSD Setup BearerId = %d")
   TRC_MSG(STATE_ABM_CSD_DISC_REQ,   "[ABM] CSD Disc BearerId = %d")
   TRC_MSG(STATE_ABM_GPRS_SETUP_REQ,   "[ABM] GPRS Setup BearerId = %d")
   TRC_MSG(STATE_ABM_GPRS_DISC_REQ,   "[ABM] GPRS Disc BearerId = %d")

   TRC_MSG(STATE_ABM_L4C_GPRS_DISC_RSP,   "[ABM] GPRS Disc Rsp DA_ID = %d, Flag = %d")
   TRC_MSG(STATE_ABM_L4C_GPRS_DISC_IND,   "[ABM] GPRS Disc Ind DA_ID = %d, Flag = %d")

   TRC_MSG(STATE_ABM_L4C_CSD_SETUP_RSP,   "[ABM] CSD Setup Rsp DA_ID = %d, Flag = %Mmodule_type")
   TRC_MSG(STATE_ABM_L4C_CSD_DISC_RSP,   "[ABM] CSD Disc Rsp DA_ID = %d, Flag = %d")
   TRC_MSG(STATE_ABM_L4C_CSD_DISC_IND,   "[ABM] CSD Disc Ind DA_ID = %d, Flag = %d")

   TRC_MSG(STATE_ABM_CBM_DISC_REQ,   "[ABM_CBM] Disc Req DA_ID = %d, Connect_type = %d")
   TRC_MSG(STATE_ABM_CBM_SET_DISC_MODE,   "[ABM_CBM] Set Disc Mode DA_ID = %d, bearer = %d, disc_mode = %d, disc_flag = %d")
   TRC_MSG(STATE_ABM_CBM_GET_DISC_MODE,   "[ABM_CBM] Get Disc Mode DA_ID = %d, bearer = %d, disc_mode = %d")

   TRC_MSG(STATE_ABM_CBM_ALLOW_ACTIVATE_REQ,   "[ABM_CBM] Allow GPRS&CSD Activate Req!")
   TRC_MSG(STATE_ABM_CBM_ALLOW_ACTIVATE_RSP,   "[ABM_CBM] Allow GPRS&CSD Activate Rsp!")

   TRC_MSG(STATE_ABM_CBM_DISALLOW_ACTIVATE_REQ,   "[ABM_CBM] Disallow GPRS&CSD Activate Req!")
   TRC_MSG(STATE_ABM_CBM_DISALLOW_ACTIVATE_RSP,   "[ABM_CBM] Disallow GPRS&CSD Activate Rsp!")

   TRC_MSG(ABM_AP_ACCT_STATE, "[ABM] ret=%d, AP state=%Mabm_app_account_state_enum mod_id= %Mmodule_type ap_id= %d")

   /* ----------------- TRACE_ERROR trace class ------------------- */
   TRC_MSG(ERROR_ABM_L4C_CSD_SETUP_RSP,   "[ABM] Error CSD Setup Rsp state= %Mabm_account_state_enum")
   TRC_MSG(ERROR_ABM_MSG_1, "[ABM] Invalid message or message content: %Mmsg_type")
   TRC_MSG(ERROR_ABM_MSG_2, "[ABM] Message (%Mmsg_type) should not be received in state (%Mabm_account_state_enum)")
   TRC_MSG(ERROR_ABM_MSG_3, "[ABM] Message (%Mmsg_type) should not be received in state (%Mabm_app_account_state_enum) for app_id(%d)")
   TRC_MSG(ERROR_ABM_APP_SLOT, "[ABM] Error: Cannot find AP slot!!")
   TRC_MSG(ERROR_ABM_APP_FB_OPTION, "[ABM] Error: Fallback option is not set: %d!!")
   TRC_MSG(ERROR_ABM_INVALID_NWK_ID, "[ABM] Error: Invalid account id!!")
   TRC_MSG(ABM_GET_TIMER_PTR_FAIL, "[ABM] get timer ptr fail, timer= %Mabm_timer_enum, account_id=%d, qos_id=%d")
   TRC_MSG(ABM_NO_FREE_TIMER, "[ABM] abm_get_free_timer() failed")
   TRC_MSG(ABM_NO_FREE_APP_SLOT, "[ABM] No free application account slot, mod_id= %Mmodule_type ap_id= %d")
   TRC_MSG(ABM_INVALID_MTU_SIZE, "[ABM] receive the wrong MTU size!!!!")
   TRC_MSG(ABM_INVALID_IP_ADDR, "[ABM] receive the INVALID IP address(0.0.0.0)!!!!")
   TRC_MSG(ABM_INVALID_WIFI_PROFILE_NUM, "[ABM] invalid wifi profile num: %d")
   TRC_MSG(ABM_INVALID_WIFI_SEL_MODE, "[ABM] invalid wifi selection mode:%d")
   TRC_MSG(ABM_INVALID_CALL_NUM, "[ABM] get an invalid csd call number from L4C!!!!")
   TRC_MSG(ABM_INVALID_SIM_ID, "[ABM] get an invalid sim id got:%d my:%d")
   TRC_MSG(ABM_INVALID_UPDATE_INFO, "[ABM] %d. update account list error!!!")

   /* ----------------- TRACE_INFO trace class ------------------- */
   TRC_MSG(CON_MNG_ACCT_SLOT_RESET, "[ABM] Connection Manager reset account slot= %d account_id= %d")
   TRC_MSG(CON_MNG_ACCT_SET_SLOT, "[ABM] Connection Manager set account slot= %d account_id= %d")
   TRC_MSG(ABM_INFO_DISABLE_BEARER_INFO, "[ABM] bearer info has been disable by: mod_id=%Mmodule_type ap_id=%d option=%d")
   TRC_MSG(ABM_BYPASS_BEARER_INFO, "[ABM] bearer info is bypass: mod_id=%Mmodule_type, ap_id=%d")
   TRC_MSG(ABM_BEARER_REQ_TO_TCPIP, "[ABM]: send bearer req to tcp/ip: bearer=%Mabm_bearer_enum mtu=%d is_activate=%d IP=%u.%u.%u.%u")
   TRC_MSG(ABM_ACTIVATE_BEARER_AGAIN, "[ABM]: ABM needs to activate the bearer again!!")
   TRC_MSG(ABM_PS_TIMER_CAUSE_FB_L1, "[ABM]: GPRS timer expire causes the FB_L1: %Mmodule_type, ap_id=%d")
   TRC_MSG(ABM_ACCT_IS_HOLD, "[ABM] account:%d is hold by mod_id=%Mmodule_type, ap_id=%d")
   TRC_MSG(ABM_RESET_APP_SLOT, "[ABM] abm_reset_app_slot:%d")
   TRC_MSG(ABM_APP_FLAG_STATE, "[ABM] abm current flag: %d")
   TRC_MSG(ABM_UPDATE_BEARER_TYPE, "[ABM] abm_l4c_ps_nw_attach_ind: ori bearer:%Mcbm_bearer_enum cur_bearer:%Mcbm_bearer_enum")
   TRC_MSG(ABM_IS_INIT, "[ABM] abm_init: %d!!")
   TRC_MSG(ABM_FREE_NWK_NEG_QOS, "[ABM] abm_app_free_nwk_neg_qos: idx=%d!!")
   TRC_MSG(ABM_UPDATE_NWK_NEG_QOS, "[ABM] abm_app_update_nwk_neg_qos(%d), idx=%d, account=%d, ctx_id=%d!!")
   TRC_MSG(ABM_FIND_NWK_NEG_QOS, "[ABM] abm_app_find_nwk_neg_qos_slot(%d) idx=%d")
   TRC_MSG(ABM_NWK_PROFILE_INFO, "[ABM] opt=%d, process network profile, type=%Mcbm_bearer_enum")
   TRC_MSG(ABM_CHECK_BEARER_INFO, "[ABM] Check bearer info, index[%d], acct[0x%x], bearer[0x%x], sim[%d], type[0x%x].")

   /* ----------------- TRACE_FUNC trace class ------------------- */
   TRC_MSG(CBM_ABORT_BEARER_EVT, "[ABM] cbm_abort_app_bearer_event==> app_id=%d")
   TRC_MSG(CBM_ENCODE_APP_ID, "[ABM] cbm_set_app_id ori_account= %d app_id= %d account_id=%d")
   TRC_MSG(CBM_ENCODE_ONE_ACCT_ID, "[ABM] cbm_encode_data_account_id ori_acct_id= %d sim_id= %d ap_id= %d always_ask= %d acct_id=%d")
   TRC_MSG(CBM_DECODE_ACCT_ID, "[ABM] cbm_decode_data_account_id account= %d")
   TRC_MSG(CBM_IS_ALWAYS_ASK_ACCT_ID, "[ABM] cbm_is_always_ask_account account= %d")
   TRC_MSG(CBM_GET_SIM_ID_BY_ONE_ACCT, "[ABM] cbm_get_sim_id account= %d")
   TRC_MSG(CBM_GET_APP_ID, "[ABM] cbm_get_app_id= %d")
   TRC_MSG(CBM_GET_ONE_ACCT_ID, "[ABM] cbm_get_original_account= %d")
   TRC_MSG(CBM_REG_APP_ID, "[ABM] cbm_register_app_id: app_type=%d str_id=%d icon_id=%d ret=%d")
   TRC_MSG(CBM_ENCODE_MULTI_ACCT_ID, "[ABM] cbm_encode_data_account_id_ext: ori_acct_id=%d acct_id=%d")
   TRC_MSG(CBM_DECODE_MULTI_ACCT_ID, "[ABM] cbm_decode_data_account_id_ext: acct_id=%d, ap_id=%d, acct1=%d, %d, %d, acct2=%d, %d, %d")
   TRC_MSG(CBM_SET_FALLBACK_OPT, "[ABM] cbm_set_fallback_option: ap_id=%d, mod_id=%Mmodule_type, option=%Mcbm_app_bearer_event_enum")
   TRC_MSG(CBM_HOLD_BEARER, "[ABM] cbm_hold_bearer: ap_id=%d")
   TRC_MSG(CBM_REL_BEARER, "[ABM] cbm_release_bearer: ap_id=%d")
   TRC_MSG(CBM_OPEN_BEARER, "[ABM] cbm_open_bearer: acct_id=%d")
   TRC_MSG(CBM_CHK_VALID_ACCT, "[ABM] abm_is_account_valid:%d")
   TRC_MSG(CBM_REG_BEARER_INFO, "[ABM] cbm_register_app_bearer_info: ap_id=%d mod_id=%Mmodule_type type=%d, state=%d")
   TRC_MSG(CBM_DEREG_BEARER_INFO, "[ABM] cbm_deregister_app_bearer_info: ap_id=%d mod_id=%Mmodule_type")
   TRC_MSG(CBM_GET_REG_BEARER_INFO, "[ABM] cbm_get_app_registered_bearer_info: ap_id=%d mod_id=%Mmodule_type type=%d state=%d")
   TRC_MSG(CBM_ALLOW_NWK_SRV, "[ABM] cbm_app_allow_nwk_srv: type=%Mcbm_nwk_srv_type_enum ap_id=%d")
   TRC_MSG(CBM_DISALLOW_NWK_SRV, "[ABM] cbm_app_disallow_nwk_srv: type=%Mcbm_nwk_srv_type_enum ap_id=%d")
   TRC_MSG(CBM_GET_BEARER_STATUS_EXT, "[ABM] cbm_get_bearer_status_ext: acct_id=%d, by_app=%d, by_bearer=%d, by_sim=%d, app=%d, sim=%d, bearer=%d")

   TRC_MSG(ABM_GET_REG_APP_INFO, "[ABM] %d. abm_get_registered_app_callback_info: app_id=%d")
   TRC_MSG(ABM_REG_ACCT_SELECT_NOTIFY, "[ABM] abm_register_app_callback: type=%d, ap_id= %d, callback=%d, data=%d")
   TRC_MSG(ABM_DEREG_ACCT_SELECT_NOTIFY, "[ABM] cbm_deregister_acct_select_notify ap_id= %d")
   TRC_MSG(ABM_DEL_BEARER_STATUS_IDX, "[ABM] del bearer status index idx= %d, ap_id= %d")
   TRC_MSG(ABM_START_TIMER, "[ABM] start timer, timer type=%Mabm_timer_enum, val=%d")
   TRC_MSG(ABM_STOP_TIMER, "[ABM] stop timer, timer type=%Mabm_timer_enum")
   TRC_MSG(ABM_GET_BEARER_STATUS, "[ABM] get bearer status, app_id=%d, state=%Mcbm_bearer_state_enum")
   TRC_MSG(ABM_GET_BEARER_TYPE, "[ABM] get bearer type, app_id=%d, type=%Mcbm_bearer_enum")
   TRC_MSG(ABM_GET_PROFILE_TYPE, "[ABM] cbm_get_profile_type: nw_acc_id=%d prof_type:%Mcbm_profile_type_enum bearer_type:%Mabm_bearer_enum bearer_id:%d")
   TRC_MSG(ABM_RESET_DATA, "[ABM] abm_reset()!!")
   TRC_MSG(CBM_DEREG_APP_ID, "[ABM] cbm_deregister_app_id!! app_id=%d, result=%d")
   TRC_MSG(CBM_REG_STATIC_QOS_ID, "[ABM] cbm_register_app_static_qos_id: app_id=%d, qos_id=%d")
   TRC_MSG(CBM_DEREG_STATIC_QOS_ID, "[ABM] cbm_deregister_app_static_qos_id: app_id=%d")
   TRC_MSG(CBM_REG_DYNAMIC_QOS_ID, "[ABM] cbm_register_app_dynamic_qos_id: app_id=%d, qos_id=%d")
   TRC_MSG(CBM_DEREG_DYNAMIC_QOS_ID, "[ABM] cbm_deregister_app_dynamic_qos_id: app_id=%d")
   TRC_MSG(CBM_SET_QOS_PROFILE, "[ABM] cbm_set_qos_profile: qos_id=%d, mod_id=%Mmodule_type")

   TRC_MSG(ABM_GET_BEARER_AVAILABLE_STATUS, "[ABM] Get bearer[0x%x] available status[%d].")
   TRC_MSG(ABM_GET_SWITCHABLE_APP_ID, "[ABM] Get switchable app id, num[%d].")
   TRC_MSG(ABM_GET_BEARER_STATUS_BY_APP_TYPE, "[ABM] Get bearer status by app_type[%x], bearer[%x], sim_id[%d], status[%x].")
   TRC_MSG(ABM_CHECK_CSD_STATE, "[ABM] Check CSD state[%x]")
   TRC_MSG(ABM_DISCONNECT_CSD, "[ABM] Disconnect CSD, state[0x%x]")
   TRC_MSG(ABM_DISCONNECT_PS, "[ABM] Disconnect PS[0x%x], slot[%d], state[0x%x]")
   TRC_MSG(ABM_PS_DETACHED, "[ABM] PS is detached, sim_id[%d], status[%d].")
   TRC_MSG(ABM_PS_NOT_DETACHED, "[ABM] PS is NOT detached, sim_id[%d], status[%d].")
   TRC_MSG(ABM_CHECK_PS_STATE, "[ABM] Check PS[%d] state[%x]")
   TRC_MSG(ABM_CHECK_IS_WLAN_USED, "[ABM] Check if WLAN is used by App, ret[%d], app_acct_id[0x%x], app_str_id[%d], app_icon_id[%d]")

END_TRACE_MAP(MOD_ABM)

#endif /* ~_ABM_TRC_H */


