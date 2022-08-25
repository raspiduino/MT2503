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
 * bcm_btcmCmd.h
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BT  app in BCM.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/
#ifndef __BCM_BTCM_CMD_H__
#define __BCM_BTCM_CMD_H__


extern void cmd_hdlr_bt_power_on_req(ilm_struct* msg);
extern void cmd_hdlr_bt_write_local_name_req(ilm_struct* msg);
extern void cmd_hdlr_bt_read_local_name_req(ilm_struct* msg);
extern void cmd_hdlr_bt_write_local_addr_req(ilm_struct* msg);
extern void cmd_hdlr_bt_read_local_addr_req(ilm_struct* msg);
extern void cmd_hdlr_bt_write_scan_mode_req(ilm_struct* msg);
extern void cmd_hdlr_bt_discovery_para_req(ilm_struct* msg);
extern void cmd_hdlr_bt_discover_req(ilm_struct* msg);
extern void cmd_hdlr_bt_discover_cancel_req(ilm_struct* msg);
extern void cmd_hdlr_bt_read_remote_name_req(ilm_struct* msg);
extern void cmd_hdlr_bt_bonding_req(ilm_struct* msg);
extern void cmd_hdlr_bt_bonding_rsp_req(ilm_struct* msg);
extern void cmd_hdlr_bt_service_search_req(ilm_struct* msg);
extern void cmd_hdlr_bt_write_auth_mode_req(ilm_struct* msg);
extern void cmd_hdlr_bt_read_auth_mode_req(ilm_struct* msg);
extern void cmd_hdlr_bt_dev_list_op_req(ilm_struct* msg);
extern void cmd_hdlr_bt_profile_state_query_req(ilm_struct* msg);
extern void cmd_hdlr_bt_cm_state_query_req(ilm_struct* msg);
extern void cmd_hdlr_bt_sniff_para_req(ilm_struct* msg);
extern void cmd_hdlr_bt_rssi_req(ilm_struct* msg);
extern void cmd_hdlr_bt_profile_act_req(ilm_struct* msg);
extern void cmd_hdlr_bt_profile_conn_req(ilm_struct* msg);
extern kal_bool is_bt_cmd_cm_allow(ilm_struct* msg);
extern kal_bool is_bt_cmd_profile_allow(ilm_struct* msg);
extern void cmd_hdlr_bt_power_on_cnf(kal_uint8 result);
extern void cmd_hdlr_bt_power_on_cnf(kal_uint8 result);
extern void cmd_hdlr_bt_power_on_cnf(kal_uint8 result);
extern void cmd_hdlr_bt_write_local_name_cnf(kal_uint8 result);
extern void cmd_hdlr_bt_read_local_name_cnf(kal_uint8 result,kal_uint8 *name,kal_uint8 name_len);
extern void cmd_hdlr_bt_write_local_addr_cnf(kal_uint8 result);
extern void cmd_hdlr_bt_read_local_addr_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr);
extern void cmd_hdlr_bt_write_scan_mode_cnf(kal_uint8 result);
extern void cmd_hdlr_bt_discovery_para_cnf(kal_uint8 result,kal_uint8 op);
extern void cmd_hdlr_bt_discovery_cnf(kal_uint8 result);
extern void cmd_hdlr_bt_discovery_cancel_cnf(kal_uint8 result,kal_uint8 total_number);
extern void cmd_hdlr_bt_read_remote_name_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr,kal_uint8* name, kal_uint8 name_len);
extern void cmd_hdlr_bt_bonding_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr,kal_uint8* name, kal_uint8 name_len,kal_uint8 display_numeric,kal_uint8 enable_16digits_pin_code,kal_uint8 *password,kal_uint8 password_len);
extern void cmd_hdlr_bt_bonding_rsp_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr);
extern void cmd_hdlr_bt_service_search_cnf(kal_uint8 result,srv_bt_cm_bt_addr bd_addr);
extern void cmd_hdlr_bt_write_auth_mode_cnf(kal_uint8 result,btbm_authentication_mode sec_mode,kal_uint8 enc_mode);
extern void cmd_hdlr_bt_read_auth_mode_cnf(kal_uint8 result,btbm_authentication_mode sec_mode,kal_uint8 enc_mode);
extern void cmd_hdlr_bt_dev_list_op_cnf(kal_uint8 result,kal_uint8 op,kal_uint8 list_number,srv_bt_cm_bt_addr *bd_addr);
extern void cmd_hdlr_bt_profile_state_query_cnf(kal_uint8 result,kal_uint32 profile,kal_uint8 profile_state);
extern void cmd_hdlr_bt_cm_state_query_cnf(kal_uint8 result,kal_uint8 cm_state);
extern void cmd_hdlr_bt_sniff_para_cnf(kal_uint8 result, kal_uint8 op,    kal_int8  sniff_level);
extern void cmd_hdlr_bt_rssi_cnf(kal_uint8 result, srv_bt_cm_bt_addr dev_addr,kal_int16 rssi);
extern void cmd_hdlr_bt_profile_act_cnf(kal_uint8 result,kal_bool is_act,kal_uint32 profile_id);
extern void cmd_hdlr_bt_profile_conn_cnf(kal_uint8 result,srv_bt_cm_bt_addr dev_addr,kal_uint32 profile,kal_uint8 role);

extern void bt_set_temp_visibility_timeout_bcm_adp(void *data);
extern kal_bool bt_profile_to_map(kal_bool is_add,kal_uint64 *profile_map, kal_uint32 profile_uuid);
extern kal_bool srv_bt_cm_get_profile_state(kal_uint32 profile,srv_bt_cm_bt_addr dev_addr,kal_uint8 *profile_state);
extern void bcm_set_ext_cm_state(kal_uint8 state);
extern kal_uint8 bcm_get_ext_cm_state(void);



extern void Custom_Set_BT_Sniff_Parameter(kal_int8 sniff_level);
extern kal_int8 Custom_Get_BT_Sniff_Parameter(void);

extern void bcm_bt_read_rssi_cnf(void *msg);

#if defined(__BT_HF_PROFILE__)
extern void srv_hfp_hfclcc_req(ilm_struct* msg);
extern void srv_hfp_hfclcc_cnf(kal_uint8 result);
extern void srv_hfp_hfata_req(ilm_struct* msg);
extern void srv_hfp_hfata_cnf(kal_uint8 result);
extern void srv_hfp_hfchup_req(ilm_struct* msg);
extern void srv_hfp_hfchup_cnf(kal_uint8 result);
extern void srv_hfp_hfchld_req(ilm_struct* msg);
extern void srv_hfp_hfchld_cnf(kal_uint8 result);
extern void srv_hfp_hfatd_req(ilm_struct* msg);
extern void srv_hfp_hfatd_cnf(kal_uint8 result);
extern void srv_hfp_hfvts_req(ilm_struct* msg);
extern void srv_hfp_hfvts_cnf(kal_uint8 result);
extern void srv_hfp_hfrvc_req(ilm_struct* msg);
extern void srv_hfp_hfrvc_cnf(kal_uint8 result);
extern kal_uint8 bcm_get_ext_hf_state(srv_bt_cm_bt_addr dev_addr,kal_uint8 role);

#endif/*#if defined(__BT_HF_PROFILE__)*/
#if defined(__BT_HFG_PROFILE__)
extern kal_uint8 bcm_get_ext_hfg_state(srv_bt_cm_bt_addr dev_addr,kal_uint8 role);
extern void srv_hfg_set_audio_path_req(ilm_struct* msg);
extern void srv_hfg_set_audio_path_cnf(kal_uint8 result);
extern void srv_hfg_read_audio_path_req(ilm_struct* msg);
extern void srv_hfg_read_audio_path_cnf(kal_uint8 result, kal_uint8 value);

#endif
#ifdef __BT_A2DP_PROFILE__
extern void srv_a2dp_reconfig_start_req(ilm_struct* msg);

#endif
#endif/*__BCM_BTCM_CMD_H__*/



