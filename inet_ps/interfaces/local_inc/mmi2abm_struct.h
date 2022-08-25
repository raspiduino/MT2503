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
 * MMI2ABM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of data passed from MMI to ABM.
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
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI2ABM_STRUCT_H
#define _MMI2ABM_STRUCT_H

#include "abm2soc_struct.h"
#include "cbm_api.h"
#include "abm_api.h"
#ifdef __WIFI_SUPPORT__
#include "wndrv_cnst.h"
#include "wndrv_supc_types.h"
#include "wndrv_api.h"
#include "supc_abm_msgs.h"
#include "wndrv_abm_msg.h"
#endif /* __WIFI_SUPPORT__ */
#include "kal_general_types.h"
#include "cbm_consts.h"
#include "stack_config.h"
#include "hostap_abm_msgs.h"
#include "ps_public_enum.h"
#if defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__)
#include "ps_public_ups_enum.h"
#endif

/* connection management request number */
#define MAX_LOCAL_BEARER_NUM     MAX_ACTIVE_BEARER_NUM
#define MAX_DIALUP_BEARER_NUM    MAX_GPRS_DIALUP_NUM


#define MAX_TOTAL_BEARER_NUM    (MAX_LOCAL_BEARER_NUM+MAX_DIALUP_BEARER_NUM)

/* max update account number */
#ifdef __ABM_CBM_SLIM__
#ifdef __GEMINI__
#define MAX_ACCOUNT_UPDATE_NUM  26
#else
#define MAX_ACCOUNT_UPDATE_NUM  14
#endif
#else /* __ABM_CBM_SLIM__ */
#define MAX_ACCOUNT_UPDATE_NUM  64
#endif /* __ABM_CBM_SLIM__ */

#define MAX_GPRS_USER_NAME_LEN 32
#define MAX_GPRS_PASSWORD_LEN  32
#define MAX_GPRS_APN_LEN       100
#define MAX_GPRS_IP_ADDR       4 /* IP address length */

// network service action
typedef enum
{
    MMI_ABM_NWK_SRV_ACTION_NONE, /* none */
    MMI_ABM_NWK_SRV_ACTION_ALLOW, /* allow network service */
    MMI_ABM_NWK_SRV_ACTION_DISALLOW, /* disallow network service */
    MMI_ABM_NWK_SRV_ACTION_TOTAL
} mmi_abm_nwk_srv_action_enum;

typedef enum
{
    MMI_ABM_BEARER_STATE_INIT,
    MMI_ABM_BEARER_STATE_REINIT,
    MMI_ABM_BEARER_STATE_TOTAL
} mmi_abm_bearer_state_enum;

typedef enum
{
    MMI_ABM_PROFILE_ADD,
    MMI_ABM_PROFILE_MODIFY,
    MMI_ABM_PROFILE_DEL,
    MMI_ABM_PROFILE_ACT_TOTAL
} mmi_abm_profile_update_act_enum;

typedef enum
{
    MMI_ABM_NWK_SRV_NONE,
    MMI_ABM_NWK_SRV_LOCAL = 0x01,
    MMI_ABM_NWK_SRV_DIALUP = 0x02,
    MMI_ABM_NWK_SRV_TOTAL
} mmi_abm_nwk_srv_type_enum;

#if defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__)
typedef enum
{
   MMI_ABM_SHARE_BEARER_DISCONNECT = ABM_RNDIS_DEACT_TYPE_DETACH,
   MMI_ABM_SHARE_BEARER_SUSPEND = ABM_RNDIS_DEACT_TYPE_SUSPEND,
   MMI_ABM_SHARE_BEARER_DEACT_TYPE_TOTAL
} mmi_abm_share_bearer_deact_type_enum;
#endif /* defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__) */

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 bearer[CBM_SIM_ID_TOTAL];
    mmi_abm_nwk_srv_type_enum type;
    mmi_abm_nwk_srv_action_enum action;
} mmi_abm_nwk_srv_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 bearer[CBM_SIM_ID_TOTAL];
    mmi_abm_nwk_srv_action_enum action;
    kal_bool result;
} mmi_abm_nwk_srv_cnf_struct;

#ifdef __WIFI_SUPPORT__
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mac_addr[WNDRV_MAC_ADDRESS_LEN];
} mmi_abm_wifi_init_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool need_portal_verify;
    kal_bool use_dhcp;
    kal_uint8 ip_addr[IP_ADDR_LEN ];
    kal_uint8 gateway[IP_ADDR_LEN ];
    kal_uint8 netmask[IP_ADDR_LEN ];
    kal_uint8 pri_dns_addr[IP_ADDR_LEN ];
    kal_uint8 sec_dns_addr[IP_ADDR_LEN ];
} mmi_abm_ipaddr_change_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 num_of_profile;
    kal_uint8 selection_mode; //supc_ap_selection_mode_enum
    kal_uint8 more_flag;
    kal_uint8 connect_type;
    kal_uint8   handover_timer_value;
    kal_uint8 always_ask_connect_flag;
    kal_uint8 always_ask_before_connect_flag;
    wifi_data_account_profile_struct profile_header_ptr[2];
} mmi_abm_wifi_connect_req_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  channel_number;
    kal_uint32  profile_id;
    kal_uint32  auth_type;
    kal_uint32  eap_peap_auth_type;
    kal_uint32  eap_ttls_auth_type;
    kal_uint16  ssid_len;
    kal_bool    result;
    kal_uint8   cause;
    kal_uint8   bssid[ WNDRV_MAC_ADDRESS_LEN ];
    kal_uint8   ssid[ WNDRV_SSID_MAX_LEN ];
    supc_connection_type_enum  conn_type;
    kal_uint16   encry_mode; /*defaultly, it is WPS_ENCR_TYPES, 
                             and now we don't to parse encry_mode in M2 */
    kal_uint8   passphase[32];
    kal_uint8   passphase_len;
    kal_int32   rssi;
} mmi_abm_wifi_connect_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8 num; 
    wifi_wps_ui_info_struct info[2];
} mmi_abm_wifi_wps_info_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  channel_number;
    kal_uint32  profile_id;
    kal_uint16  ssid_len;
    kal_uint8   bssid[ WNDRV_MAC_ADDRESS_LEN ];
    kal_uint8   ssid[ WNDRV_SSID_MAX_LEN ];
    kal_int32   rssi;
} mmi_abm_wifi_connect_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_uint8 cause;
    kal_uint8 ip_addr[4];
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];
    kal_uint8 gateway[4];
    kal_uint8 netmask[4];
} mmi_abm_ipaddr_update_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 cause;
    kal_uint8 num;
    kal_uint8 more_flag;
    supc_abm_bss_info_struct ap_list[WNDRV_SCAN_RESULTS_NUM];
} mmi_abm_wifi_ap_list_cnf_struct;

typedef enum
{
    WLAN_NOT_AVAILABLE,
    WLAN_CONNECTING
} activate_req_rej_cause_enum;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    activate_req_rej_cause_enum cause;
} mmi_abm_wifi_activate_req_rej_struct;

typedef struct
{
   kal_uint8                   ref_count;
   kal_uint16                  msg_len;
   wndrv_ps_mode_enum          ps_mode;
} mmi_abm_wifi_set_ps_mode_req_struct;

typedef struct
{
   kal_uint8                   ref_count;
   kal_uint16                  msg_len;
   wndrv_ps_mode_enum          ps_mode;
   kal_bool                    status;
} mmi_abm_wifi_set_ps_mode_cnf_struct;

/* Roaming Parameter */
typedef struct
{
   kal_uint8                   ref_count;
   kal_uint16                  msg_len;
   kal_bool                    fgEnableRoaming; //TRUE: enable roaming, FALSE:disable roaming
} mmi_abm_wifi_set_roaming_para_req_struct;

typedef struct
{
   kal_uint8                   ref_count;
   kal_uint16                  msg_len;
   kal_bool                    status;
} mmi_abm_wifi_set_scan_para_cnf_struct;

typedef mmi_abm_wifi_set_scan_para_cnf_struct mmi_abm_wifi_set_roaming_para_cnf_struct;

/* Dwell Time */
typedef struct
{
   kal_uint8                   ref_count;
   kal_uint16                  msg_len;
   kal_uint16                  u2ChannelDwellTime; //0: driver use default dwell time; other : dwell time in TU  
} mmi_abm_wifi_set_scan_dwell_time_req_struct;

typedef mmi_abm_wifi_set_scan_para_cnf_struct mmi_abm_wifi_set_scan_dwell_time_cnf_struct;

typedef struct
{
    kal_uint8 ssid_len;
    kal_uint8 ssid[WNDRV_SSID_MAX_LEN];
}mmi_abm_wifi_ssid_struct;

/* Desired SSID List */
typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint8                   ssid_list_num;  //number of ssid in ssid_list. maximum is WNDRV_MAX_SSID_LIST_NUM
    mmi_abm_wifi_ssid_struct    ssid_list[WNDRV_MAX_SSID_LIST_NUM];
} mmi_abm_wifi_set_scan_desired_ssid_list_req_struct;

typedef mmi_abm_wifi_set_scan_para_cnf_struct mmi_abm_wifi_set_scan_desired_ssid_list_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    sniffer_mode_onoff_enum   ucOnOffSwitch;
    kal_uint32  ucSnifferFilterOptions;
    kal_uint8   ucChannelNum;
    kal_int32   cMinRssi;
    kal_int32   cMaxRssi;
    kal_uint16  u2MinPacketLength;
    kal_uint16  u2MaxPacketLength;    
}mmi_abm_wifi_set_sniffer_mode_req_struct;

// Define temporitly
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    sniffer_status_enum status; 
    kal_uint8   OnOffStatus;//0:off , non-zero:on
}mmi_abm_wifi_set_sniffer_mode_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   ssid_len;
    kal_uint8   ssid[WNDRV_SSID_MAX_LEN];
    kal_uint8   password_len;
    kal_uint8   password[WNDRV_PASSWORD_MAX_LEN];
    kal_uint8   auth_mode;
}mmi_abm_iot_listened_ap_info_ind_struct;

#endif /* __WIFI_SUPPORT__ */

/* CBM Struct */
typedef struct
{
    kal_uint8  bearer_type; /* GPRS or CSD */
    kal_uint8  sim_id;
    kal_uint8  call_id;
    kal_uint8  context_id;
} mmi_abm_dialup_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 profile_id;
    mmi_abm_dialup_struct dialup_info;
    kal_uint8  qos_profile_id;
    kal_uint8  connect_type;
} mmi_abm_active_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 profile_id;
    mmi_abm_dialup_struct dialup_info;
    kal_uint8  connect_type;
} mmi_abm_deactive_ind_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 profile_id;
    mmi_abm_dialup_struct dialup_info;
    kal_uint8  qos_profile_id;
    kal_uint8  connect_type;
} mmi_abm_disconnect_req_struct;

typedef struct  
{
    kal_uint32 profile_id;
    mmi_abm_dialup_struct dialup_info;
    kal_uint8  connect_type;
    kal_uint8  result;
} mmi_abm_bearer_req_count_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    mmi_abm_bearer_req_count_struct bearer_req_count[MAX_TOTAL_BEARER_NUM];
    kal_uint8  count;
    kal_uint8  serial_number;
} mmi_abm_get_bearer_info_req_struct;

typedef struct
{
    kal_uint32  profile_id;
    kal_bool    reset_tx; /* reset certain profile's send data */
    kal_bool    reset_rx; /* reset certain profile's recv data */  
} mmi_abm_reset_bearer_struct;

typedef struct
{
    mmi_abm_dialup_struct           dialup_info;
    kal_bool     reset_tx; /* send data belongs to certain connection */
    kal_bool     reset_rx; /* recv data belongs to certain connection */
} mmi_abm_reset_dialup_bearer_struct;

typedef struct
{
    kal_uint8    ref_count;
    kal_uint16   msg_len;
    mmi_abm_reset_bearer_struct local[MAX_LOCAL_BEARER_NUM];
    mmi_abm_reset_dialup_bearer_struct dialup[MAX_DIALUP_BEARER_NUM];
    kal_bool    reset_all_tx; /* reset all send data */
    kal_bool    reset_all_rx; /* reset all recv data */
    
    kal_uint8    connect_type;
    kal_uint8    count;
} mmi_abm_reset_bearer_info_req_struct;

typedef struct
{
    kal_uint32  account_id;
    kal_uint8   ap_id;
} mmi_abm_cm_disc_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 profile_id;
    mmi_abm_cm_disc_struct cm_disc_info[MAX_TOTAL_BEARER_NUM];
    mmi_abm_dialup_struct dialup_info;
    kal_uint8  result;
    kal_uint8  qos_profile_id;
    kal_uint8  connect_type;
} mmi_abm_disconnect_cnf_struct;


typedef struct  
{
    kal_uint64 send_data_size;
    kal_uint64 receive_data_size; 
    kal_uint32 profile_id;
    mmi_abm_dialup_struct dialup_info;
    kal_uint8  result;
} mmi_abm_bearer_cnf_count_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    mmi_abm_bearer_cnf_count_struct bearer_cnf_count[MAX_TOTAL_BEARER_NUM];
    kal_uint8  count;
    kal_uint8  connect_type;
} mmi_abm_get_bearer_info_cnf_struct;

typedef struct  
{
    kal_uint8   ref_count;
    kal_uint16  msg_len; 
    mmi_abm_reset_bearer_struct local[MAX_LOCAL_BEARER_NUM];
    mmi_abm_reset_dialup_bearer_struct dialup[MAX_DIALUP_BEARER_NUM];  
    kal_uint8   connect_type;
}mmi_abm_reset_bearer_info_cnf_struct;


typedef struct
{
   hostap_sta_info_struct	sta_info[ HOSTAP_STA_MAX_NUM ];
   kal_uint8				sta_num;
} mmi_abm_hotspot_info_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint64 recv_data_size;    
    kal_uint64 send_data_size;
    kal_uint32 profile_id;
    mmi_abm_dialup_struct dialup_info;
    mmi_abm_hotspot_info_struct share_bearer_info;
    kal_uint8  connect_type;
    cbm_bearer_state_enum  status;
    cbm_bearer_enum bearer_type;
    cbm_result_error_enum cause;
} mmi_abm_bearer_info_ind_struct;


#ifdef __UCM_SUPPORT__

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8     prof_id;
    kal_uint8 call_num_len;
    kal_uint8  call_num_type;
#define ABM_MAX_CC_ADDR_LEN          41
    kal_uint8 call_num[ABM_MAX_CC_ADDR_LEN];    
    kal_uint8	sim_info;
} mmi_abm_csd_call_approve_req_struct;


typedef struct
{
	kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8     prof_id; 
	kal_uint8	sim_info;
    kal_bool result;
} mmi_abm_csd_call_approve_cnf_struct;

#endif /* __UCM_SUPPORT__ */

typedef struct  
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} mmi_abm_allow_activate_gprs_csd_rsp_struct;

typedef struct  
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} mmi_abm_disallow_activate_gprs_csd_rsp_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_uint32          account_id;
    module_type         mod_id;
    abm_app_status_enum status;
    kal_uint8           next_acct_num;
} mmi_abm_ask_acct_ind_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_uint32          account_id;
    module_type         mod_id;
    kal_bool            result;
    abm_app_status_enum status;
} mmi_abm_ask_acct_rsp_struct;

typedef struct
{
    kal_uint8                         ref_count;
    kal_uint16                        msg_len;
    kal_uint32                        account_id;
    mmi_abm_bearer_state_enum         state;
} mmi_abm_bearer_init_ind_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_uint32          ori_acct_id;
    kal_uint32          rel_acct_id;
    kal_bool            result;
    cbm_bearer_enum     bearer_type;
    kal_int32           cause;
} mmi_abm_bearer_init_rsp_struct;

typedef enum
{
    MMI_ABM_DEINIT_CAUSE_APP_DEINIT = 0,
    MMI_ABM_DEINIT_CAUSE_WLAN_POWER_SAVE,
    MMI_ABM_DEINIT_CAUSE_TOTAL
} mmi_abm_deinit_cause_enum;

typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32                  account_id;
    mmi_abm_deinit_cause_enum   cause;
} mmi_abm_bearer_deinit_ind_struct;

typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32                  account_id;
    mmi_abm_deinit_cause_enum   cause;
} mmi_abm_bearer_deinit_rsp_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_uint32          account_id;
} mmi_abm_profile_query_ind_struct;

typedef struct {
    kal_uint8 addr_str[23];
    kal_uint8 csd_ur;
    kal_uint8 csd_type;
    kal_uint8 csd_module;
} csd_account_info_struct;

typedef struct {
    kal_uint8 apn[MAX_GPRS_APN_LEN];
    kal_uint8 apn_length;
    kal_uint8 dcomp_algo; // Fixed value: SND_NO_DCOMP
    kal_uint8 hcomp_algo; // Fixed value: SND_NO_PCOMP
    kal_uint8 pdp_type; // Fixed value: IPV4_ADDR_TYPE 0x21 for IPv4
    kal_uint8 pdp_addr_len; // Fixed value: NULL_PDP_ADDR_LEN = 0x01, if use fixed IP address, this should be IPV4_ADDR_LEN = 0x04
    kal_uint8 pdp_addr_val[MAX_GPRS_IP_ADDR]; // should be all 0
} ps_account_info_struct;

typedef struct {
  kal_uint8 authentication_type;
  kal_uint8 user_name[MAX_GPRS_USER_NAME_LEN];
  kal_uint8 password[MAX_GPRS_PASSWORD_LEN];
  kal_uint8 dns[MAX_GPRS_IP_ADDR];
  kal_uint8 sec_dns[MAX_GPRS_IP_ADDR];
  ps_account_info_struct ps_account_info;
  csd_account_info_struct csd_account_info;  
} mmi_abm_account_info_struct;

typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32                  account_id;
    mmi_abm_account_info_struct content;
    kal_bool                    result;
} mmi_abm_profile_query_rsp_struct;

typedef struct {
    kal_uint16 app_str_id; /* applicaiton string id used to identify itself */
    kal_uint16 app_icon_id; /* application icon id used to identify itself */
    kal_uint8 account_id[CBM_MAX_ACCT_NUM];
} mmi_abm_update_app_info_struct;

typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32          account_id;
    mmi_abm_profile_update_act_enum action;
    cbm_bearer_enum     bearer_type;
} mmi_abm_update_account_info_req_struct;

typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    mmi_abm_update_app_info_struct invalid_app_info[ABM_MAX_APP_NUM];
} mmi_abm_update_app_info_req_struct;

typedef enum
{
    MMI_ABM_BEARER_EVENT_CANCEL,
    MMI_ABM_BEARER_EVENT_ACCEPT_THIS_TIME,
    MMI_ABM_BEARER_EVENT_TOTAL
} mmi_abm_bearer_event_result_enum;

typedef enum
{
    MMI_ABM_BEARER_EVT_ALWAYS_ASK,
    MMI_ABM_BEARER_EVT_FALLBACK,
    MMI_ABM_BEARER_EVT_WIFI_PS_FALLBACK,
    MMI_ABM_BEARER_EVT_DISCONNECT,
    MMI_ABM_BEARER_EVT_SWITCH,
    MMI_ABM_BEARER_EVT_TOTAL
} mmi_abm_bearer_event_enum;

typedef struct
{
    kal_uint8                           ref_count;
    kal_uint16                          msg_len;
    kal_uint32                          ori_acct_id;
    kal_uint32                          sel_acct_id;
    mmi_abm_bearer_event_result_enum    user_result;
    mmi_abm_bearer_event_enum           event;
} mmi_abm_bearer_event_connect_req_struct;

typedef struct
{
    kal_uint8                           ref_count;
    kal_uint16                          msg_len;
    kal_uint32                          ori_acct_id;
    kal_bool                            result;
    mmi_abm_bearer_event_enum           event;
} mmi_abm_bearer_event_connect_cnf_struct;

#if defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__)

typedef struct 
{
    kal_uint8                           ref_count;
    kal_uint16                         msg_len;
    kal_uint32                         account_id;
    cbm_bearer_enum             share_bearer;
    mmi_abm_account_info_struct usb_tr_profile;
    hostap_profile_struct hostap_config_profile;
} mmi_abm_share_bearer_activate_req_struct;

typedef struct 
{
    kal_uint8                           ref_count;
    kal_uint16                         msg_len;
    kal_uint32                         account_id;
    cbm_bearer_enum             share_bearer;
    mmi_abm_share_bearer_deact_type_enum deact_type;
} mmi_abm_share_bearer_deactivate_req_struct;

typedef struct 
{
    kal_uint8                           ref_count;
    kal_uint16                         msg_len;
    kal_bool                            result;
    cbm_bearer_enum             share_bearer;
} mmi_abm_share_bearer_activate_cnf_struct;


typedef struct 
{
    kal_uint8                           ref_count;
    kal_uint16                         msg_len;
    kal_bool                            result;
    cbm_bearer_enum             share_bearer;
} mmi_abm_share_bearer_deactivate_cnf_struct;


typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   cbm_bearer_enum             share_bearer;
} mmi_abm_share_bearer_query_req_struct;


typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   mmi_abm_hotspot_info_struct ap_info;
   cbm_bearer_enum            share_bearer;
} mmi_abm_share_bearer_query_cnf_struct;

#endif /* defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__) */

typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   kal_uint32                        ap_num;
} mmi_abm_wifi_ap_list_query_rsp_struct; 

typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   kal_uint8                          app_id;
} mmi_abm_wifi_portal_login_start_req_struct;

typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   kal_bool                           result;
} mmi_abm_wifi_portal_login_stop_req_struct;

typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   kal_uint16               status;
} mmi_abm_net_status_ind_struct;

typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   kal_uint8                mode;
   kal_int8                 power;
} mmi_abm_set_tx_pwr_req_struct;

typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   kal_uint8                status;
} mmi_abm_set_tx_pwr_cnf_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_bool                result;
    cbm_bearer_enum         bearer_type;
    kal_int32               cause;
} mmi_abm_bearer_connect_result_ind_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              bearer;
    cbm_sim_id_enum         sim_id;
} mmi_abm_bearer_disconnect_req_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_bool                result;
    kal_uint32              bearer;
    cbm_sim_id_enum         sim_id;
} mmi_abm_bearer_disconnect_cnf_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    cbm_bearer_enum         bearer;
    cbm_sim_id_enum         sim_id;
    kal_uint32              status;
} mmi_abm_bearer_status_ind_struct;

#endif /* _MMI2ABM_STRUCT_H */

