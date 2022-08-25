/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE: BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES:
*  EXPRESS OR IMPLIED: INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY: FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY: INCORPORATED IN: OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE: AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE:
*  AT MEDIATEK'S OPTION: TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE:
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA: USA: EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES: CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO: CA: UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bcm_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for bcm task msg handler
 *   entry point.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 27 2017 hongjian.zhao
 * removed!
 * new feature for get BLE Random Addr.
 *
 * 02 17 2017 hongjian.zhao
 * removed!
 *
 * 	add adv interval and connection interval API.
 *
 * 02 13 2017 hongjian.zhao
 * removed!
 *
 * 02 13 2017 hongjian.zhao
 * removed!
 *
 * 01 23 2017 hongjian.zhao
 * removed!
 * BLE porting to BCM module.
 *
 * 03 09 2015 zhen.tian
 * removed!
 * .
 *
 * 03 06 2015 zhen.tian
 * removed!
 * .for build error
 *
 * 03 04 2015 xiaowei.wang
 * removed!
 * .
 *
 * 03 04 2015 xiaowei.wang
 * removed!
 * .
 *
 * 01 27 2015 zhen.tian
 * removed!
 * .
 *
 * 10 30 2014 yuhua.lv
 * removed!
 * 	.
 *
 * 04 09 2014 hujin.hu
 * removed!
 * [M2M]HFP checkin.
 *
 * 03 21 2014 yinling.he
 * removed!
 * [M2M] check in OPP & PBAPC code.
 *
 * 03 18 2014 guoqing.ren
 * removed!
 * fix build error.
 *
 *------------------------------------------------------------------------------
 * Upper this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __BCM_SUPPORT__

/*****************
Include Statements
******************/
//#include "kal_release.h"      	/* Basic data type */

//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */

//#include "stacklib.h"        	/* Basic type for dll: evshed: stacktimer */

//#include "event_shed.h"       	/* Event scheduler */

//#include "stack_timer.h"      	/* Stack timer */
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "Bcm_btcmSrvProt.h"
#ifdef __BT_SPP_PROFILE__
#include "BcmSppSrv.h"
#endif
#ifdef __BT_OPP_PROFILE__
#include "bcm_OppGprots.h"
#endif

#ifdef __BT_PBAP_CLIENT__
#include "bcm_PbapSrvGprot.h"
#endif
#ifdef __BT_PBAP_CLIENT__
#include "bcm_pbapGprot.h"
#endif
#include "bcm_trc.h"
#include "Bcm_btcmUtility.h"
#include "bcm_btcmCmd.h"
#include "bcm_event_handler.h"

#ifdef __BT_GATTS_PROFILE__
#include "bcm_GattsGprot.h"
#endif
#ifdef __BT_GATTC_PROFILE__
#include "bcm_GattcGprot.h"
#endif
#if defined(__MMI_BT_AUDIO_SUPPORT__) && (defined(__BT_HF_PROFILE__) || defined(__BT_HFG_PROFILE__))
#include "bcm_mdi_audio.h"
#endif
#if defined(__BT_HF_PROFILE__)
#include "bcm_BTDialerSrv.h"
#endif /*#if defined(__BT_HF_PROFILE__)*/

#if defined(__BT_HFG_PROFILE__)
#include "bcm_BthfSrv.h"
#endif /*#if defined(__BT_HFG_PROFILE__)*/
extern track_ble_response_data_handle(ilm_struct* msg);
typedef void (*bcm_func_ptr)(ilm_struct *msg);

typedef struct
{
    kal_uint32 msg_id;
    bcm_func_ptr msg_hdlr;
} cmd_map_to_hdlr_struct;
typedef void (*protocol_event_func_ptr)(void *msg);

typedef struct
{
    kal_uint32 msg_id;
    protocol_event_func_ptr msg_hdlr;
} bcm_protocol_event_map_struct;


const cmd_map_to_hdlr_struct cmd_map_to_hdlr[] =
{
    {MSG_ID_BCM_POWER_ONOFF_REQ, cmd_hdlr_bt_power_on_req}, //0
    {MSG_ID_BCM_WRITE_LOCAL_NAME_REQ, cmd_hdlr_bt_write_local_name_req},
    {MSG_ID_BCM_READ_LOCAL_NAME_REQ, cmd_hdlr_bt_read_local_name_req},
    {MSG_ID_BCM_WRITE_LOCAL_ADDR_REQ, cmd_hdlr_bt_write_local_addr_req},
    {MSG_ID_BCM_READ_LOCAL_ADDR_REQ, cmd_hdlr_bt_read_local_addr_req},
    {MSG_ID_BCM_WRITE_SCANENABLE_MODE_REQ, cmd_hdlr_bt_write_scan_mode_req}, //5
    {MSG_ID_BCM_DISCOVERY_PARA_REQ, cmd_hdlr_bt_discovery_para_req},
    {MSG_ID_BCM_DISCOVERY_REQ, cmd_hdlr_bt_discover_req},
    {MSG_ID_BCM_DISCOVERY_CANCEL_REQ, cmd_hdlr_bt_discover_cancel_req},
    {MSG_ID_BCM_READ_REMOTE_NAME_REQ, cmd_hdlr_bt_read_remote_name_req},
    {MSG_ID_BCM_BONDING_REQ, cmd_hdlr_bt_bonding_req},
    {MSG_ID_BCM_BONDING_RSP_REQ, cmd_hdlr_bt_bonding_rsp_req},
    {MSG_ID_BCM_SERVICE_SEARCH_REQ, cmd_hdlr_bt_service_search_req},
    {MSG_ID_BCM_WRITE_AUTHENTICATION_MODE_REQ, cmd_hdlr_bt_write_auth_mode_req},
    {MSG_ID_BCM_READ_AUTHENTICATION_MODE_REQ, cmd_hdlr_bt_read_auth_mode_req},
    {MSG_ID_BCM_DEV_LIST_OP_REQ, cmd_hdlr_bt_dev_list_op_req},
    {MSG_ID_BCM_PROFILE_STATE_QUERY_REQ, cmd_hdlr_bt_profile_state_query_req},
    {MSG_ID_BCM_CM_STATE_QUERY_REQ, cmd_hdlr_bt_cm_state_query_req},
    {MSG_ID_BCM_SNIFF_PARA_REQ, cmd_hdlr_bt_sniff_para_req},
    {MSG_ID_BCM_RSSI_REQ, cmd_hdlr_bt_rssi_req},
    {MSG_ID_BCM_PROFILE_ACT_REQ, cmd_hdlr_bt_profile_act_req},
    {MSG_ID_BCM_PROFILE_CONN_REQ, cmd_hdlr_bt_profile_conn_req}, // 21
#ifdef __BT_OPP_PROFILE__
    {MSG_ID_BCM_OPP_PUSH_OBJ_REQ, bcm_opp_push_obj_req_handler},
    {MSG_ID_BCM_OPP_ABORT_REQ, bcm_opp_abort_req_handler},
    {MSG_ID_BCM_OPP_RECV_OBJ_RES, bcm_opp_recv_obj_res_handler},
#endif /*__BT_OPP_PROFILE__*/
#ifdef __BT_PBAP_CLIENT__
    {MSG_ID_BCM_PBAP_GET_LIST_REQ, bcm_pbapc_get_list_req_handler},
    {MSG_ID_BCM_PBAP_PULL_ENTRY_REQ, bcm_pbapc_pull_entry_req_handler},
    {MSG_ID_BCM_PBAP_DL_CH_REQ, bcm_pbapc_dl_ch_req_handler},
#endif /*__BT_PBAP_CLIENT__*/
#if defined(__BT_HF_PROFILE__)
    {MSG_ID_BCM_HF_CLCC_REQ, srv_hfp_hfclcc_req},
    {MSG_ID_BCM_HF_ATA_REQ, srv_hfp_hfata_req},
    {MSG_ID_BCM_HF_CHUP_REQ, srv_hfp_hfchup_req},
    {MSG_ID_BCM_HF_CHLD_REQ, srv_hfp_hfchld_req},
    {MSG_ID_BCM_HF_ATD_REQ, srv_hfp_hfatd_req},
    {MSG_ID_BCM_HF_VTS_REQ, srv_hfp_hfvts_req},
    {MSG_ID_BCM_HF_RAV_REQ, srv_hfp_hfrvc_req},
#ifdef __MMI_BT_AUDIO_SUPPORT__
    {MSG_ID_MMI_MDI_BT_OPEN_STREAM_REQ, mdi_audio_bt_open_stream_req},
#endif/*#ifdef __MMI_BT_AUDIO_SUPPORT__*/
#endif/*#if defined(__BT_HF_PROFILE__)*/
#if defined(__BT_HFG_PROFILE__) && defined(__MESSAGE_BASED_AT_SUPPORT__)
    {MSG_ID_RMMI_REGISTER_CHANNEL_CNF, bthf_at_cmd_msg_hdlr},
    {MSG_ID_RMMI_EXE_AT_CNF, bthf_at_cmd_msg_hdlr},
    {MSG_ID_RMMI_RESPONSE_AT_IND, bthf_at_cmd_msg_hdlr},
    {MSG_ID_RMMI_URC_AT_IND, bthf_at_cmd_msg_hdlr},
    {MSG_ID_BCM_HFG_SET_AUDIO_PATH_REQ, srv_hfg_set_audio_path_req},
    {MSG_ID_BCM_HFG_READ_AUDIO_PATH_REQ, srv_hfg_read_audio_path_req},
#endif
#ifdef __BT_A2DP_PROFILE__
    {MSG_ID_BCM_A2DP_RECONFIG_START_REQ, srv_a2dp_reconfig_start_req},
#endif
#ifdef __BT_GATTS_PROFILE__
    {MSG_ID_BCM_GATTS_REGISTER_REQ, bcm_gatts_register_req_handler},
    {MSG_ID_BCM_GATTS_DEREGISTER_REQ, bcm_gatts_deregister_req_handler},
    {MSG_ID_BCM_GATTS_CONNECT_REQ, bcm_gatts_connect_req_handler},
    {MSG_ID_BCM_GATTS_DISCONNECT_REQ, bcm_gatts_disconnect_req_handler},
    {MSG_ID_BCM_GATTS_ADD_SERVICE_REQ, bcm_gatts_add_service_req_handler},
    {MSG_ID_BCM_GATTS_DELETE_SERVICE_REQ, bcm_gatts_delete_service_req_handler},
    {MSG_ID_BCM_GATTS_ADD_INCL_SERVICE_REQ, bcm_gatts_add_include_service_req_handler},
    {MSG_ID_BCM_GATTS_ADD_CHAR_REQ, bcm_gatts_add_char_req_handler},
    {MSG_ID_BCM_GATTS_ADD_DESCR_REQ, bcm_gatts_add_descriptor_req_handler},
    {MSG_ID_BCM_GATTS_START_SERVICE_REQ, bcm_gatts_start_service_req_handler},
    {MSG_ID_BCM_GATTS_STOP_SERVICE_REQ, bcm_gatts_stop_service_req_handler},

    {MSG_ID_BCM_GATTS_SEND_INDICATION_REQ, bcm_gatts_send_indication_req_handler},
    {MSG_ID_BCM_GATTS_SEND_RESPONSE_REQ, bcm_gatts_send_response_req_handler},
    {MSG_ID_BCM_GATTS_LISTEN_REQ, bcm_gatts_listen_req_handler},
    {MSG_ID_BCM_FMPS_REGISTER_REQ, bcm_fmps_register_req_handler},
    {MSG_ID_BCM_FMPS_DEREGISTER_REQ, bcm_fmps_deregister_req_handler},
    {MSG_ID_BCM_PXPS_REGISTER_REQ, bcm_pxps_register_req_handler},
    {MSG_ID_BCM_PXPS_DEREGISTER_REQ, bcm_pxps_deregister_req_handler},
    {MSG_ID_BCM_GATT_READ_LOCAL_ADDR_REQ, bcm_gatt_read_local_addr_req_handler},
#endif

#ifdef __BT_GATTC_PROFILE__
    {MSG_ID_BCM_GATT_SET_ADV_PARAM_REQ, bcm_gatt_set_adv_param_req_handler}, //41
    {MSG_ID_BCM_GATT_CONN_PARAM_UPDATE_REQ, bcm_gatt_conn_param_update_req_handler},
#endif

#if defined (__BLE_GATT__)
    {MSG_ID_BCM_TRACK_BLE_SWITCH_REQ, track_bcm_gatt_switch_req_handler},/*BLE开关切换。MMI通过消息通知BCM开关BLE*/
#endif /* __BLE_GATT__ */
#if defined(__BLE_N07__)
	{MSG_ID_BCM_TRACK_BLE_WRITE_REQ, track_ble_response_data_handle},//7号蓝牙回复数据
#endif


};
const char* cmd_map_to_hdlr_string[] =
{
    {"MSG_ID_BCM_POWER_ONOFF_REQ"},
    {"MSG_ID_BCM_WRITE_LOCAL_NAME_REQ"},
    {"MSG_ID_BCM_READ_LOCAL_NAME_REQ"},
    {"MSG_ID_BCM_WRITE_LOCAL_ADDR_REQ"},
    {"MSG_ID_BCM_READ_LOCAL_ADDR_REQ"},
    {"MSG_ID_BCM_WRITE_SCANENABLE_MODE_REQ"},
    {"MSG_ID_BCM_DISCOVERY_PARA_REQ"},
    {"MSG_ID_BCM_DISCOVERY_REQ"},
    {"MSG_ID_BCM_DISCOVERY_CANCEL_REQ"},
    {"MSG_ID_BCM_READ_REMOTE_NAME_REQ"},
    {"MSG_ID_BCM_BONDING_REQ"},
    {"MSG_ID_BCM_BONDING_RSP_REQ"},
    {"MSG_ID_BCM_SERVICE_SEARCH_REQ"},
    {"MSG_ID_BCM_WRITE_AUTHENTICATION_MODE_REQ"},
    {"MSG_ID_BCM_READ_AUTHENTICATION_MODE_REQ"},
    {"MSG_ID_BCM_DEV_LIST_OP_REQ"},
    {"MSG_ID_BCM_PROFILE_STATE_QUERY_REQ"},
    {"MSG_ID_BCM_CM_STATE_QUERY_REQ"},
    {"MSG_ID_BCM_SNIFF_PARA_REQ"},
    {"MSG_ID_BCM_RSSI_REQ"},
    {"MSG_ID_BCM_PROFILE_ACT_REQ"},
    {"MSG_ID_BCM_PROFILE_CONN_REQ"},
#ifdef __BT_OPP_PROFILE__
    {"MSG_ID_BCM_OPP_PUSH_OBJ_REQ"},
    {"MSG_ID_BCM_OPP_ABORT_REQ"},
    {"MSG_ID_BCM_OPP_RECV_OBJ_RES"},
#endif /*__BT_OPP_PROFILE__*/
#ifdef __BT_PBAP_CLIENT__
    {"MSG_ID_BCM_PBAP_GET_LIST_REQ"},
    {"MSG_ID_BCM_PBAP_PULL_ENTRY_REQ"},
    {"MSG_ID_BCM_PBAP_DL_CH_REQ"},
#endif /*__BT_PBAP_CLIENT__*/
#if defined(__BT_HF_PROFILE__)
    {"MSG_ID_BCM_HF_CLCC_REQ"},
    {"MSG_ID_BCM_HF_ATA_REQ"},
    {"MSG_ID_BCM_HF_CHUP_REQ"},
    {"MSG_ID_BCM_HF_CHLD_REQ"},
    {"MSG_ID_BCM_HF_ATD_REQ"},
    {"MSG_ID_BCM_HF_VTS_REQ"},
    {"MSG_ID_BCM_HF_RAV_REQ"},
#ifdef __MMI_BT_AUDIO_SUPPORT__
    {"MSG_ID_MMI_MDI_BT_OPEN_STREAM_REQ"},
#endif/*#ifdef __MMI_BT_AUDIO_SUPPORT__*/
#endif/*#if defined(__BT_HF_PROFILE__)*/
#if defined(__BT_HFG_PROFILE__) && defined(__MESSAGE_BASED_AT_SUPPORT__)
    {"MSG_ID_RMMI_REGISTER_CHANNEL_CNF"},
    {"MSG_ID_RMMI_EXE_AT_CNF"},
    {"MSG_ID_RMMI_RESPONSE_AT_IND"},
    {"MSG_ID_RMMI_URC_AT_IND"},
    {"MSG_ID_BCM_HFG_SET_AUDIO_PATH_REQ"},
    {"MSG_ID_BCM_HFG_READ_AUDIO_PATH_REQ"},
#endif
#ifdef __BT_A2DP_PROFILE__
    {"MSG_ID_BCM_A2DP_RECONFIG_START_REQ"},
#endif
#ifdef __BT_GATTS_PROFILE__
    {"MSG_ID_BCM_GATTS_REGISTER_REQ"},
    {"MSG_ID_BCM_GATTS_DEREGISTER_REQ"},
    {"MSG_ID_BCM_GATTS_CONNECT_REQ"},
    {"MSG_ID_BCM_GATTS_DISCONNECT_REQ"},
    {"MSG_ID_BCM_GATTS_ADD_SERVICE_REQ"},
    {"MSG_ID_BCM_GATTS_DELETE_SERVICE_REQ"},
    {"MSG_ID_BCM_GATTS_ADD_INCL_SERVICE_REQ"},
    {"MSG_ID_BCM_GATTS_ADD_CHAR_REQ"},
    {"MSG_ID_BCM_GATTS_ADD_DESCR_REQ"},
    {"MSG_ID_BCM_GATTS_START_SERVICE_REQ"},
    {"MSG_ID_BCM_GATTS_STOP_SERVICE_REQ"},

    {"MSG_ID_BCM_GATTS_SEND_INDICATION_REQ"},
    {"MSG_ID_BCM_GATTS_SEND_RESPONSE_REQ"},
    {"MSG_ID_BCM_GATTS_LISTEN_REQ"},
    {"MSG_ID_BCM_FMPS_REGISTER_REQ"},
    {"MSG_ID_BCM_FMPS_DEREGISTER_REQ"},
    {"MSG_ID_BCM_PXPS_REGISTER_REQ"},
    {"MSG_ID_BCM_PXPS_DEREGISTER_REQ"},
    {"MSG_ID_BCM_GATT_READ_LOCAL_ADDR_REQ"},
#endif

#ifdef __BT_GATTC_PROFILE__
    {"MSG_ID_BCM_GATT_SET_ADV_PARAM_REQ"},
    {"MSG_ID_BCM_GATT_CONN_PARAM_UPDATE_REQ"},
#endif

#if defined (__BLE_GATT__)
    {"MSG_ID_BCM_TRACK_BLE_SWITCH_REQ"},
#endif /* __BLE_GATT__ */

};
const bcm_protocol_event_map_struct bcm_protocol_event_map[] =
{
    {MSG_ID_BT_READ_RSSI_CNF, bcm_bt_read_rssi_cnf}, //0
    {MSG_ID_BT_POWERON_CNF, srv_bt_cm_antenna_on_rsp_hdler},
    {MSG_ID_BT_POWEROFF_CNF, srv_bt_cm_antenna_off_rsp_hdler},
#if 0
    /* under construction !*/
#endif
    {MSG_ID_BT_BM_LINK_ALLOW_CNF, srv_bt_cm_allow_acl_link_establishment_cnf_hdler},
    {MSG_ID_BT_BM_LINK_DISALLOW_CNF, srv_bt_cm_disallow_acl_link_establishment_cnf_hdler},
    {MSG_ID_BT_RESET_REQ_IND, srv_bt_cm_restart_req_ind_hdler}, //5
    {MSG_ID_BT_MMI_RESET_CNF, srv_bt_cm_restart_rsp_hdler},
    {MSG_ID_BT_BM_DISCOVERY_RESULT_IND, srv_bt_cm_discovery_result_ind_hdler},
    {MSG_ID_BT_BM_DISCOVERY_UPDATE_IND, srv_bt_cm_discovery_result_ind_hdler},
    {MSG_ID_BT_BM_DISCOVERY_CNF, srv_bt_cm_discovery_cnf_hdler},
    {MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF, srv_bt_cm_cancel_discovery_cnf_hdler}, //10
    {MSG_ID_BT_BM_WRITE_LOCAL_NAME_CNF, srv_bt_cm_set_local_name_cnf_hdler},
    {MSG_ID_BT_BM_READ_LOCAL_ADDR_CNF, srv_bt_cm_read_local_bd_addr_cnf_hdler},
    {MSG_ID_BT_BM_READ_REMOTE_NAME_CNF, srv_bt_cm_read_remote_name_cnf_hdler},
    {MSG_ID_BT_BM_SERVICE_SEARCH_RESULT_IND, srv_bt_cm_sdc_search_ind_hdler},
    {MSG_ID_BT_BM_SERVICE_SEARCH_CNF, srv_bt_cm_sdc_search_cnf_hdler}, //15
    {MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_IND, srv_bt_cm_link_connect_accept_ind_hdler},
    {MSG_ID_BT_BM_BONDING_RESULT_IND, srv_bt_cm_bond_ind_hdler},
    {MSG_ID_BT_BM_BONDING_CNF, srv_bt_cm_bond_cnf_hdler},
    {MSG_ID_BT_BM_DELETE_TRUST_CNF, srv_bt_cm_debond_cnf_hdler},
    {MSG_ID_BT_BM_PIN_CODE_IND, srv_bt_cm_passkey_ind_hdler}, //20
    {MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_CNF, srv_bt_cm_security_level_cnf_hdler},
    {MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_CNF, srv_bt_cm_write_scanenable_mode_cnf_hdler},
    {MSG_ID_BT_BM_LINK_STATE_IND, srv_bt_cm_link_state_ind_hdler}, //23
#ifdef __MMI_BT_SIMPLE_PAIR__
    {MSG_ID_BT_BM_SECURITY_USER_CONFIRM_IND, srv_bt_cm_security_user_confirm_ind_hdler},
    {MSG_ID_BT_BM_SECURITY_PASSKEY_NOTIFY_IND, srv_bt_cm_security_passkey_notify_ind_hdler},
    {MSG_ID_BT_BM_SECURITY_KEYPRESS_NOTIFY_IND, srv_bt_cm_security_keypress_notify_ind_hdler},
#endif /* __MMI_BT_SIMPLE_PAIR__ */
#ifdef __MMI_BT_AUTHORIZE__
    {MSG_ID_BT_BM_BLOCK_ACTIVE_LINK_CNF, srv_bt_cm_block_active_link_cnf_hdler},
    {MSG_ID_BT_BM_BLOCK_LIST_UPDATE_CNF, srv_bt_cm_block_list_update_cnf_hdler},
#endif /* __MMI_BT_AUTHORIZE__ */
#ifdef __BT_BOND_CANCEL__
    {MSG_ID_BT_BM_BONDING_CANCEL_CNF, srv_bt_cm_bond_cancel_cnf_hdler},
#endif
#ifdef __BT_SPP_PROFILE__
    {MSG_ID_BT_SPP_ACTIVATE_CNF, srv_spp_port_activate_cnf},
    {MSG_ID_BT_SPP_DEACTIVATE_CNF, srv_spp_port_deactivate_cnf},
    {MSG_ID_BT_SPP_CONNECT_IND_REQ, srv_spp_authorize_ind},
    {MSG_ID_BT_SPP_CONNECT_IND, srv_spp_connect_ind},
    {MSG_ID_BT_SPP_CONNECT_CNF, srv_spp_connect_cnf},
    {MSG_ID_BT_SPP_DISCONNECT_CNF, srv_spp_disconnect_ind},
    {MSG_ID_BT_SPP_DISCONNECT_IND, srv_spp_disconnect_ind},
    {MSG_ID_UART_READY_TO_READ_IND, srv_spp_uart_ready_to_read_ind},
    {MSG_ID_UART_READY_TO_WRITE_IND, srv_spp_uart_ready_to_write_ind},
    {MSG_ID_UART_PLUGOUT_IND, srv_spp_uart_plugout_ind},
    {MSG_ID_BT_SPP_UART_OWNER_IND, srv_spp_uart_set_owner_ind},
#ifdef __MMI_SPP_SCO_SUPPORT__
    {MSG_ID_BT_SPP_AUDIO_CONNECT_CNF, srv_spp_audio_connect_cnf},
    {MSG_ID_BT_SPP_AUDIO_CONNECT_IND, srv_spp_audio_connect_ind},
    {MSG_ID_BT_SPP_AUDIO_DISCONNECT_CNF, srv_spp_audio_disconnect_cnf},
    {MSG_ID_BT_SPP_AUDIO_DISCONNECT_IND, srv_spp_audio_disconnect_ind},
#endif /*__MMI_SPP_SCO_SUPPORT__*/
#endif /* __BT_SPP_PROFILE__ */

#if defined(__BT_HF_PROFILE__)
    {MSG_ID_BT_HF_ACTIVATE_CNF, srv_bt_dialer_activate_cnf_hdlr},
    {MSG_ID_BT_HF_CONNECT_IND_REQ, srv_bt_dialer_connect_ind},
    {MSG_ID_BT_HF_DISCONNECT_IND, srv_bt_dialer_disconnect_ind},
    {MSG_ID_BT_HF_VGS_IND, srv_bt_dialer_vgs_ind},
    {MSG_ID_BT_HF_RING_IND, srv_bt_dialer_ring_ind_hdlr},
    {MSG_ID_BT_HF_CIEV_CALL_IND, srv_bt_dialer_ciev_call_ind},
    {MSG_ID_BT_HF_CIEV_CALLSETUP_IND, srv_bt_dialer_callsetup_ind},
    {MSG_ID_BT_HF_CIEV_CALLHELD_IND, srv_bt_dialer_callheld_ind},
    {MSG_ID_BT_HF_CLIP_IND, srv_bt_dialer_clip_ind},
    {MSG_ID_BT_HF_CCWA_IND, srv_bt_dialer_ccwa_ind},
    {MSG_ID_BT_HF_CONNECT_CNF, srv_bt_dialer_connect_cnf_hdlr},
#ifndef __MMI_BTBOX_NOLCD__
    {MSG_ID_BT_HF_BSIR_IND, srv_bt_dialer_bsir_ind},
    {MSG_ID_BT_HF_VGM_CNF, srv_bt_dialer_vgm_cnf_hdlr},
    {MSG_ID_BT_HF_VGM_IND, srv_bt_dialer_vgm_ind_hdlr},
    {MSG_ID_BT_HF_CIEV_SERVICE_IND, srv_bt_dialer_ciev_service_ind},
    {MSG_ID_BT_HF_CIEV_SIGNAL_IND, srv_bt_dialer_ciev_signal_ind},
    {MSG_ID_BT_HF_CIEV_ROAM_IND, srv_bt_dialer_ciev_roam_ind},
    {MSG_ID_BT_HF_CIEV_BATTCHG_IND, srv_bt_dialer_ciev_battchg_ind},
    {MSG_ID_BT_HF_BVRA_IND, srv_bt_dialer_bvra_ind},
    {MSG_ID_BT_HF_BTRH_IND, srv_bt_dialer_btrh_ind},
#endif /* __MMI_BTBOX_NOLCD__ */
    {MSG_ID_BT_HF_CLCC_CNF, srv_bt_dialer_atclcc_cnf_hdlr},
    {MSG_ID_BT_HF_DEACTIVATE_CNF, srv_bt_dialer_deactivate_cnf_hdlr},
    {MSG_ID_BT_HF_DISCONNECT_CNF, srv_bt_dialer_disconnect_cnf_hdlr},
    {MSG_ID_BT_HF_ATA_CNF, srv_bt_dialer_ata_cnf_hdlr},
    {MSG_ID_BT_HF_ATD_NUM_CNF, srv_bt_dialer_atd_cnf_hdlr},
    {MSG_ID_BT_HF_ATD_MEM_CNF, srv_bt_dialer_atmem_cnf_hdlr},
    {MSG_ID_BT_HF_BLDN_CNF, srv_bt_dialer_atbldn_cnf_hdlr},
    {MSG_ID_BT_HF_CHUP_CNF, srv_bt_dialer_atchup_cnf_hdlr},
    {MSG_ID_BT_HF_CMEE_CNF, srv_bt_dialer_atcmee_cnf_hdlr},
    {MSG_ID_BT_HF_NREC_CNF, srv_bt_dialer_atnrec_cnf_hdlr},
    {MSG_ID_BT_HF_VTS_CNF, srv_bt_dialer_atvts_cnf_hdlr},
    {MSG_ID_BT_HF_VGS_CNF, srv_bt_dialer_vgs_cnf_hdlr},
    {MSG_ID_BT_HF_CHLD_CNF, srv_bt_dialer_atchld_cnf_hdlr},
    {MSG_ID_BT_HF_CLIP_CNF, srv_bt_dialer_atclip_cnf_hdlr},
    {MSG_ID_BT_HF_CCWA_CNF, srv_bt_dialer_atccwa_cnf_hdlr},
    {MSG_ID_BT_HF_COPS_SET_CNF, srv_bt_dialer_set_atcops_cnf_hdlr},
    {MSG_ID_BT_HF_COPS_CNF, srv_bt_dialer_atcops_cnf_hdlr},
    {MSG_ID_BT_HF_CNUM_CNF, srv_bt_dialer_atcnum_cnf_hdlr},
    {MSG_ID_BT_HF_BVRA_CNF, srv_bt_dialer_atbvra_cnf_hdlr},
    {MSG_ID_BT_HF_BINP_CNF, srv_bt_dialer_atbinp_cnf_hdlr},
    {MSG_ID_BT_HF_BTRH_READ_CNF, srv_bt_dialer_atbtrh_read_cnf_hdlr},
    {MSG_ID_BT_HF_BTRH_SET_CNF, srv_bt_dialer_atbtrh_set_cnf_hdlr},
#endif/*#if defined(__BT_HF_PROFILE__)*/
#if defined(__BT_HFG_PROFILE__)
    {MSG_ID_BCM_CHANGE_VOLUMN_IND, srv_bthf_change_vol_ind_hdlr},
#endif /*defined(__BT_HFG_PROFILE__)*/
#if defined(__MMI_BT_AUDIO_SUPPORT__) && (defined(__BT_HF_PROFILE__) || defined(__BT_HFG_PROFILE__))
    {MSG_ID_MEDIA_BT_AUDIO_CLOSE_CNF, mdi_audio_bt_close_stream_cnf},
    {MSG_ID_MEDIA_BT_AUDIO_CLOSE_IND, mdi_audio_bt_close_stream_ind},
    {MSG_ID_MEDIA_BT_AUDIO_OPEN_CNF, mdi_audio_bt_open_stream_cnf},
    {MSG_ID_MEDIA_BT_AUDIO_OPEN_IND, mdi_audio_bt_open_stream_ind},
#ifdef __GAIN_TABLE_SUPPORT__
    {MSG_ID_L4AUD_AUDIO_STATE_CHANGE_IND, mdi_audio_state_change_ind_hdlr},
#endif/*#ifdef __GAIN_TABLE_SUPPORT__*/
#endif /* __MMI_BT_AUDIO_SUPPORT__ */

};
const char* bcm_protocol_event_map_String[] =
{
    {"MSG_ID_BT_READ_RSSI_CNF"},
    {"MSG_ID_BT_POWERON_CNF"},
    {"MSG_ID_BT_POWEROFF_CNF"},
#if 0
    /* under construction !*/
#endif
    {"MSG_ID_BT_BM_LINK_ALLOW_CNF"},
    {"MSG_ID_BT_BM_LINK_DISALLOW_CNF"},
    {"MSG_ID_BT_RESET_REQ_IND"},
    {"MSG_ID_BT_MMI_RESET_CNF"},
    {"MSG_ID_BT_BM_DISCOVERY_RESULT_IND"},
    {"MSG_ID_BT_BM_DISCOVERY_UPDATE_IND"},
    {"MSG_ID_BT_BM_DISCOVERY_CNF"},
    {"MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF"},
    {"MSG_ID_BT_BM_WRITE_LOCAL_NAME_CNF"},
    {"MSG_ID_BT_BM_READ_LOCAL_ADDR_CNF"},
    {"MSG_ID_BT_BM_READ_REMOTE_NAME_CNF"},
    {"MSG_ID_BT_BM_SERVICE_SEARCH_RESULT_IND"},
    {"MSG_ID_BT_BM_SERVICE_SEARCH_CNF"},
    {"MSG_ID_BT_BM_LINK_CONNECT_ACCEPT_IND"},
    {"MSG_ID_BT_BM_BONDING_RESULT_IND"},
    {"MSG_ID_BT_BM_BONDING_CNF"},
    {"MSG_ID_BT_BM_DELETE_TRUST_CNF"},
    {"MSG_ID_BT_BM_PIN_CODE_IND"},
    {"MSG_ID_BT_BM_WRITE_AUTHENTICATION_MODE_CNF"},
    {"MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_CNF"},
    {"MSG_ID_BT_BM_LINK_STATE_IND"},
#ifdef __MMI_BT_SIMPLE_PAIR__
    {"MSG_ID_BT_BM_SECURITY_USER_CONFIRM_IND"},
    {"MSG_ID_BT_BM_SECURITY_PASSKEY_NOTIFY_IND"},
    {"MSG_ID_BT_BM_SECURITY_KEYPRESS_NOTIFY_IND"},
#endif /* __MMI_BT_SIMPLE_PAIR__ */
#ifdef __MMI_BT_AUTHORIZE__
    {"MSG_ID_BT_BM_BLOCK_ACTIVE_LINK_CNF"},
    {"MSG_ID_BT_BM_BLOCK_LIST_UPDATE_CNF"},
#endif /* __MMI_BT_AUTHORIZE__ */
#ifdef __BT_BOND_CANCEL__
    {"MSG_ID_BT_BM_BONDING_CANCEL_CNF"},
#endif
#ifdef __BT_SPP_PROFILE__
    {"MSG_ID_BT_SPP_ACTIVATE_CNF"},
    {"MSG_ID_BT_SPP_DEACTIVATE_CNF"},
    {"MSG_ID_BT_SPP_CONNECT_IND_REQ"},
    {"MSG_ID_BT_SPP_CONNECT_IND"},
    {"MSG_ID_BT_SPP_CONNECT_CNF"},
    {"MSG_ID_BT_SPP_DISCONNECT_CNF"},
    {"MSG_ID_BT_SPP_DISCONNECT_IND"},
    {"MSG_ID_UART_READY_TO_READ_IND"},
    {"MSG_ID_UART_READY_TO_WRITE_IND"},
    {"MSG_ID_UART_PLUGOUT_IND"},
    {"MSG_ID_BT_SPP_UART_OWNER_IND"},
#ifdef __MMI_SPP_SCO_SUPPORT__
    {"MSG_ID_BT_SPP_AUDIO_CONNECT_CNF"},
    {"MSG_ID_BT_SPP_AUDIO_CONNECT_IND"},
    {"MSG_ID_BT_SPP_AUDIO_DISCONNECT_CNF"},
    {"MSG_ID_BT_SPP_AUDIO_DISCONNECT_IND"},
#endif /*__MMI_SPP_SCO_SUPPORT__*/
#endif /* __BT_SPP_PROFILE__ */

#if defined(__BT_HF_PROFILE__)
    {"MSG_ID_BT_HF_ACTIVATE_CNF"},
    {"MSG_ID_BT_HF_CONNECT_IND_REQ"},
    {"MSG_ID_BT_HF_DISCONNECT_IND"},
    {"MSG_ID_BT_HF_VGS_IND"},
    {"MSG_ID_BT_HF_RING_IND"},
    {"MSG_ID_BT_HF_CIEV_CALL_IND"},
    {"MSG_ID_BT_HF_CIEV_CALLSETUP_IND"},
    {"MSG_ID_BT_HF_CIEV_CALLHELD_IND"},
    {"MSG_ID_BT_HF_CLIP_IND"},
    {"MSG_ID_BT_HF_CCWA_IND"},
    {"MSG_ID_BT_HF_CONNECT_CNF"},
#ifndef __MMI_BTBOX_NOLCD__
    {"MSG_ID_BT_HF_BSIR_IND"},
    {"MSG_ID_BT_HF_VGM_CNF"},
    {"MSG_ID_BT_HF_VGM_IND"},
    {"MSG_ID_BT_HF_CIEV_SERVICE_IND"},
    {"MSG_ID_BT_HF_CIEV_SIGNAL_IND"},
    {"MSG_ID_BT_HF_CIEV_ROAM_IND"},
    {"MSG_ID_BT_HF_CIEV_BATTCHG_IND"},
    {"MSG_ID_BT_HF_BVRA_IND"},
    {"MSG_ID_BT_HF_BTRH_IND"},
#endif /* __MMI_BTBOX_NOLCD__ */
    {"MSG_ID_BT_HF_CLCC_CNF"},
    {"MSG_ID_BT_HF_DEACTIVATE_CNF"},
    {"MSG_ID_BT_HF_DISCONNECT_CNF"},
    {"MSG_ID_BT_HF_ATA_CNF"},
    {"MSG_ID_BT_HF_ATD_NUM_CNF"},
    {"MSG_ID_BT_HF_ATD_MEM_CNF"},
    {"MSG_ID_BT_HF_BLDN_CNF"},
    {"MSG_ID_BT_HF_CHUP_CNF"},
    {"MSG_ID_BT_HF_CMEE_CNF"},
    {"MSG_ID_BT_HF_NREC_CNF"},
    {"MSG_ID_BT_HF_VTS_CNF"},
    {"MSG_ID_BT_HF_VGS_CNF"},
    {"MSG_ID_BT_HF_CHLD_CNF"},
    {"MSG_ID_BT_HF_CLIP_CNF"},
    {"MSG_ID_BT_HF_CCWA_CNF"},
    {"MSG_ID_BT_HF_COPS_SET_CNF"},
    {"MSG_ID_BT_HF_COPS_CNF"},
    {"MSG_ID_BT_HF_CNUM_CNF"},
    {"MSG_ID_BT_HF_BVRA_CNF"},
    {"MSG_ID_BT_HF_BINP_CNF"},
    {"MSG_ID_BT_HF_BTRH_READ_CNF"},
    {"MSG_ID_BT_HF_BTRH_SET_CNF"},
#endif/*#if defined(__BT_HF_PROFILE__)*/
#if defined(__BT_HFG_PROFILE__)
    {"MSG_ID_BCM_CHANGE_VOLUMN_IND"},
#endif /*defined(__BT_HFG_PROFILE__)*/
#if defined(__MMI_BT_AUDIO_SUPPORT__) && (defined(__BT_HF_PROFILE__) || defined(__BT_HFG_PROFILE__))
    {"MSG_ID_MEDIA_BT_AUDIO_CLOSE_CNF"},
    {"MSG_ID_MEDIA_BT_AUDIO_CLOSE_IND"},
    {"MSG_ID_MEDIA_BT_AUDIO_OPEN_CNF"},
    {"MSG_ID_MEDIA_BT_AUDIO_OPEN_IND"},
#ifdef __GAIN_TABLE_SUPPORT__
    {"MSG_ID_L4AUD_AUDIO_STATE_CHANGE_IND"},
#endif/*#ifdef __GAIN_TABLE_SUPPORT__*/
#endif /* __MMI_BT_AUDIO_SUPPORT__ */
};
#if defined(__BT_HFG_PROFILE__)
extern U8 bthf_msg_hdlr(void *para, U32 src_mod, ilm_struct *ilm);
//extern U8 btaud_service_hdlr(void *para, U32 src_mod, ilm_struct *ilm);
#endif /*#if defined(__BT_HFG_PROFILE__)*/


//TASK MSG HDLR  chengj
kal_bool process_bcm_req(ilm_struct* msg)
{
    kal_uint8 i = 0;
    kal_uint8 handler_num = 0;
    kal_bool is_handled = KAL_FALSE;
    handler_num = sizeof(cmd_map_to_hdlr) / (sizeof(cmd_map_to_hdlr_struct));

    ASSERT(msg);
    for(i = 0 ; i < handler_num; i++)
    {
        if(msg->msg_id == cmd_map_to_hdlr[i].msg_id)
        {

#if defined (__BLE_DEBUG_LOG__)
            {
                char testLog[128] = {0};
                sprintf(testLog, "CMD process_bcm_req(cmd_map_to_hdlr)[%d/%d]%s\r\n", i, handler_num, cmd_map_to_hdlr_string[i]);
                U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
            }
#endif /* __BLE_DEBUG_LOG__ */

            ((bcm_func_ptr)cmd_map_to_hdlr[i].msg_hdlr)(msg);
            is_handled = KAL_TRUE;
        }
    }
    if(is_handled == KAL_FALSE)
    {
        handler_num = sizeof(bcm_protocol_event_map) / (sizeof(bcm_protocol_event_map_struct));
        for(i = 0 ; i < handler_num; i++)
        {
            if(msg->msg_id == bcm_protocol_event_map[i].msg_id)
            {
#if defined (__BLE_DEBUG_LOG__)
			//-------------------------------------------------------------
			    {
			    //验证补丁添加的代码  chengjun  2017-05-18
                    char testLog[128] = {0};
                    sprintf(testLog, "EVENT process_bcm_req(bcm_protocol_event_map)[%d/%d]%s\r\n", i, handler_num, bcm_protocol_event_map_String[i]);
                    U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
                }
	    		//-------------------------------------------------------------
#endif /* __BLE_DEBUG_LOG__ */

                ((protocol_event_func_ptr)bcm_protocol_event_map[i].msg_hdlr)(msg->local_para_ptr);
                is_handled = KAL_TRUE;
            }
        }
    }
#if defined(__BT_HFG_PROFILE__)
//HFP
    if(!is_handled)
    {
        //if(msg->msg_id == MSG_ID_BT_BM_SERVICE_SEARCH_RESULT_IND || msg->msg_id == MSG_ID_BT_BM_SERVICE_SEARCH_CNF)
        {
            //btaud_service_hdlr(msg->local_para_ptr, MOD_BT, msg);
        }

        //MSG_ID_BT_HFG_ACTIVATE_CNF; i <= MSG_ID_BT_HFG_MIC_GAIN_CNF
        if(msg->msg_id == MSG_ID_BT_HFG_SPEAKER_GAIN_REQ ||
                msg->msg_id >= MSG_ID_BT_HFG_GROUP_START && msg->msg_id <= MSG_ID_BT_HFG_GROUP_END)
        {
            bthf_msg_hdlr(msg->local_para_ptr, msg->src_mod_id, msg);
            is_handled = KAL_TRUE;
#if defined (__BLE_DEBUG_LOG__)
            {
                char testLog[128] = {0};
                sprintf(testLog, "EVENT __BT_HFG_PROFILE__\r\n");
                U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
            }
#endif /* __BLE_DEBUG_LOG__ */
        }

    }
#endif/*#if defined(__BT_HFG_PROFILE__)*/
    if(is_handled == KAL_FALSE)
    {
        is_handled = bcm_execute_protocol_event_handler(msg->msg_id, msg->local_para_ptr, msg->src_mod_id);
    }
#if defined (__BLE_DEBUG_LOG__)
    if(!is_handled)
    {
        char testLog[128] = {0};
        sprintf(testLog, "CMD process_bcm_req NULL!!\r\n");
        U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
    }
#endif /* __BLE_DEBUG_LOG__ */
        
    return is_handled;
}


//#define __BCM_TEST__
#ifdef __BCM_TEST__
void TEST_timeout_bcm_adp(void *data)
{
    kal_uint8 *timer_id = (kal_uint8*) data;

    BCM_FUNC_ENTRY(MMI_BT_G7_BT_DEINIT);
    BCM_PTR->timer_pool[(kal_uint32)(timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32)(timer_id)].event_id = 0;

//    StopTimer(BT_RELEASE_ALL_CON_GUARD_TIMER);
}

#endif

void bcm_main(ilm_struct *ilm_ptr)
{
    if(process_bcm_req(ilm_ptr))
    {
        kal_prompt_trace(MOD_BCM, "process_bcm_req is true");
    }
    else
    {
        switch(ilm_ptr->msg_id)
        {
            case MSG_ID_TIMER_EXPIRY:
                bcm_timer_expiry_handler(ilm_ptr);
                break;

#ifdef __BCM_TEST__
            case MSG_ID_UART_PLUGOUT_IND:
                BCM_FUNC_ENTRY(FUNC_BCM_TEST_TRACE);
                {
                    srv_bt_cm_nvram_struct read_struct;
                    nvram_external_read_data(NVRAM_EF_BT_INFO_LID, 1, (kal_uint8*)&read_struct, sizeof(read_struct));
                    kal_prompt_trace(MOD_BCM, "NVRAM_EF_BT_INFO_LID 's value is %s", read_struct.host_dev.name);
                    StartTimer(
                        BT_TEMP_VISIBLE_TIMER,
                        5,
                        TEST_timeout);
                    StartTimer(
                        BT_RELEASE_ALL_CON_GUARD_TIMER,
                        8,
                        TEST_timeout);
                }
                break;
#endif
            default:
                break;
        }
    }
    comm_invoke_post_event();
}

#endif
