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
 *  supc_abm_msgs.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Private header file of WLAN Network driver
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifndef SUPC_ABM_MSGS_H
#define SUPC_ABM_MSGS_H

//#include "kal_non_specific_general_types.h"
#include "wndrv_cnst.h"
#include "wndrv_supc_types.h"
#include "kal_general_types.h"
#define SUPC_MAC_ADDR_LEN 6


typedef enum
{
    SUPC_ABM_TIMEOUT,
    SUPC_ABM_LOST_COVERAGE,
    SUPC_ABM_NORMAL_REJ,
    SUPC_ABM_CONNECT_FAIL,
    SUPC_ABM_AUTH_FAIL,
    SUPC_ABM_CAUSE_COUNT,
    SUPC_ABM_UNSUPPORTED_EAP_TYPE, //add for WiFi UE enhancement
    SUPC_ABM_WRONG_USER_INFO,      //add for WiFi UE enhancement
    SUPC_ABM_LOW_RSSI, // when RSSI < -85dBm . indicate this cause
    SUPC_ABM_INVALID_CAUSE
} supc_abm_cause_enum;

typedef enum
{
    WLAN_EAP_TLS              = 0x00000001,
    WLAN_EAP_MD5              = 0x00000002,
    WLAN_EAP_PEAP             = 0x00000004,
    WLAN_EAP_TTLS                 = 0x00000008,
    WLAN_EAP_SIM                = 0x00000010,
    WLAN_EAP_FAST              = 0x00000020,
    WLAN_EAP_MSCHAV2       = 0x00000040,
    WLAN_EAP_GTC                = 0x00000080,
    WLAN_PAP                        = 0x00000100,
    WLAN_CHAP                      = 0x00000200,
    WLAN_MSCHAP                  = 0x00000400,
    WLAN_MSCHAPV2             = 0x00000800,
    WLAN_EAP_AKA              = 0x00001000      /* Jau Add */
} supc_abm_eap_type_enum;
    
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   mac_addr[SUPC_MAC_ADDR_LEN];
} supc_abm_wifi_init_cnf_struct;


typedef enum
{
    AP_MANUAL_SELECT,
    AP_AUTOMATIC_SELECT
} supc_ap_selection_mode_enum;

typedef enum
{
    ALL_PROFILE_ENABLE,
    ONE_PROFILE_SELECT,
    START_WPS_PIN,
    START_WPS_PBC
} supc_connection_type_enum;

typedef enum
{
    /* for peap */
    SUPC_PHASE1_PEAP_0  = 0x00000001,
    SUPC_PHASE1_PEAP_1 = 0x00000002,   
    SUPC_PHASE1_LABLEL_0 = 0X00000010,
    SUPC_PHASE1_LABLEL_1 = 0X00000020,
    SUPC_PHASE1_OUTER_SUCCESS_0 = 0x00000100,
    SUPC_PHASE1_OUTER_SUCCESS_1 = 0x00000200,
    SUPC_PHASE1_OUTER_SUCCESS_2 = 0x00000400,
    SUPC_PHASE1_TTLS
} supc_phase1_mothod_enum;

#define SUPC_PEAP_VERSION_MASK (0x0000000F)
#define SUPC_PEAP_LABEL_MASK (0x000000F0)
#define SUPC_PEAP_OUTER_SUCCESS_MASK (0x00000F00)


typedef enum
{
    SUPC_PHASE2_EAP_TLS              = 0x00000001,
    SUPC_PHASE2_EAP_MD5              = 0x00000002,
    SUPC_PHASE2_EAP_PEAP             = 0x00000004,
    SUPC_PHASE2_EAP_TTLS                 = 0x00000008,
    SUPC_PHASE2_EAP_SIM                = 0x00000010,
    SUPC_PHASE2_EAP_FAST              = 0x00000020,
    SUPC_PHASE2_EAP_MSCHAV2       = 0x00000040,
    SUPC_PHASE2_EAP_GTC                = 0x00000080,
    SUPC_PHASE2_PAP                        = 0x00000100,
    SUPC_PHASE2_CHAP                      = 0x00000200,
    SUPC_PHASE2_MSCHAP                  = 0x00000400,
    SUPC_PHASE2_MSCHAPV2              = 0x00000800,
    SUPC_PHASE2_EAP_AKA               = 0x00001000
} supc_phase2_mothod_enum;

/* 
REFER TO dtcntsrvlprot.h
correspondence to srv_dtcnt_wlan_encrypt_mode_enum
and srv_dtcnt_wlan_auth_mode_enum. these value will be used 
in supc_abm_wifi_connect_cnf_struct.auth_type and encrypt_mode
*/

typedef enum
{ 
    SUPC_ENCRYPT_MODE_NONE,   /* unencrypt mode */
    SUPC_ENCRYPT_MODE_WEP,    /* WEP mode */
    SUPC_ENCRYPT_MODE_TKIP,   /* TKIP mode */
    SUPC_ENCRYPT_MODE_AES,    /* AES mode */
    SUPC_ENCRYPT_MODE_WPI,    /* WPI mode */
    SUPC_ENCRYPT_MODE_TOTAL
} supc_encrypt_mode_enum;

/*refer to srv_dtcnt_wlan_auth_mode_enum */
typedef enum
{
    SUPC_AUTH_MODE_OPEN,      /* authentication open */
    SUPC_AUTH_MODE_SHARED,    /* shared */
    SUPC_AUTH_MODE_IEEE8021X, /* 802.1x */
    SUPC_AUTH_MODE_WPA,       /* WPA Enterprise*/
    SUPC_AUTH_MODE_WPAPSK,    /* WPAPSK */
    SUPC_AUTH_MODE_WAPICERT,  /* WAPICERT */
    SUPC_AUTH_MODE_WAPIPSK,   /* WAPIPSK */

    SUPC_AUTH_MODE_WPA2, /*WPA2 enterprise*/
    SUPC_AUTH_MODE_WPA_WPA2_MIX, /*WPA/WPA2 enterprise*/
    SUPC_AUTH_MODE_WPA2PSK,  /*WPA2 PSK*/
    SUPC_AUTH_MODE_WPA_WPA2_PSK, /*WPA WPA2 PSK*/
    SUPC_AUTH_MODE_TOTAL
} supc_auth_mode_enum;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_bool    result;
    kal_uint8   cause; //supc_abm_cause_enum
    kal_uint8                        bssid[ WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
    kal_uint16                      ssid_len;
    kal_uint8                        ssid[ WNDRV_SSID_MAX_LEN ];    
    kal_uint32                       channel_number;
    kal_uint32                       profile_id;
    //add for WiFi UE enhancement
    supc_auth_mode_enum  auth_type;
    kal_uint32  eap_peap_auth_type;
    kal_uint32  eap_ttls_auth_type;
    supc_connection_type_enum  conn_type;
    supc_encrypt_mode_enum   encry_mode;
    kal_uint8   passphase[32]; // used to store PSK value
    kal_uint8   passphase_len; // always set to 32
    kal_int32   rssi;
}  supc_abm_wifi_connect_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8                        bssid[ WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
    kal_uint16                      ssid_len;
    kal_uint8                        ssid [ WNDRV_SSID_MAX_LEN ];    
    kal_uint32                       channel_number;
    kal_uint32                       profile_id;
	kal_int32   rssi;
} supc_abm_wifi_connect_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   cause; //supc_abm_cause_enum
}  supc_abm_wifi_disconnect_ind_struct;


#define NUM_WEP_KEYS 4
#define MAX_WEP_KEY_LEN 16

typedef struct
{
	kal_uint8 wep_key[NUM_WEP_KEYS][MAX_WEP_KEY_LEN];
	kal_uint16 wep_key_len[NUM_WEP_KEYS];
	kal_uint8 wep_tx_keyidx;
} supc_wep_keys;


#define FILE_PATH_LEN 32
typedef struct 
{

    kal_uint8                        ssid [ WNDRV_SSID_MAX_LEN ];    
    kal_uint8                       ssid_len;
    kal_bool                         scan_ssid;
    kal_bool                        bssid_p;
    kal_uint8                        bssid[ WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
    kal_uint8                       priority;
    kal_uint32                       profile_id;
    wndrv_supc_network_type_enum     network_type;    
    kal_uint8                        max_rate; 
    kal_uint32                      channel_number;
    
//WPA_PROTO_WPA/WPA_PROTO_RSN, default: WPA RSN
    kal_uint8                       proto; 
//WPA_KEY_MGMT_IEEE8021X/WPA_KEY_MGMT_PSK/WPA_KEY_MGMT_NONE/
//WPA_KEY_MGMT_IEEE8021X_NO_WPA, default: WAP-PSK WPA-EAP
    kal_uint8                       key_mgmt; 
//WPA_AUTH_ALG_OPEN/WPA_AUTH_ALG_SHARED/WPA_AUTH_ALG_LEAP
    kal_uint8                       auth_alg; 

    kal_uint8                       pairwise; //CCMP/TKIP/NONE, default: CCMP TKIP
    kal_uint8                       group; //CCMP/TKIP/WEP104/WEP40, default: CCMP TKIP WEP104 WEP40

    kal_bool                        psk_p;
    kal_uint8                       psk[32];
#ifdef __WAPI_SUPPORT__
    kal_uint8                     psk_type; // 0 for HEX format string, 1 for ASCII format string
#endif  
    kal_uint32                       eap;

    // WEP key information
    kal_bool                        wep_info_p;
    supc_wep_keys              wep_keys;

    kal_uint8                       identity[32]; /* EAP Identity */
    kal_uint16                      identity_len;
    kal_uint8                       anonymous_identity[32]; /* Anonymous EAP Identity (for unencrypted use
                                                            			 * with EAP types that support different
                                                            			 * tunnelled identity, e.g., EAP-TTLS) */
    kal_uint16                      anonymous_identity_len;
/*
    kal_uint8 *nai;
    kal_uint16 nai_len;
    kal_uint8 *server_nai;
    kal_uint16 server_nai_len;
*/    
    kal_uint8                       password[32];
    kal_uint16                      password_len;
#if 1//#ifdef __CERTMAN_SUPPORT__
    kal_uint32                       ca_cert;
    kal_uint32                       client_cert;
#ifdef __WAPI_SUPPORT__
    kal_uint32                      wapi_as_cert;
#endif
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    kal_uint8                       private_key_passwd[32];
    kal_uint16                       private_key_passwd_len;
/* ??    
    u8 *dh_file;
    u8 *subject_match;
*/    
#if 1//#ifdef __CERTMAN_SUPPORT__
    kal_uint32                       ca_cert2;
    kal_uint32                       client_cert2;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    kal_uint8                       private_key2_passwd[32];
    kal_uint16                       private_key2_passwd_len;
/* ??    
    u8 *dh_file2;
    u8 *subject_match2;
*/

/* TBD */
    kal_uint32                       phase1; 
    kal_uint32                       phase2;
        
} wifi_data_account_profile_struct;

//add for WiFi UE enhancement 20->30
#define MAX_NUM_PROFILE 30
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   selection_mode; //supc_ap_selection_mode_enum
    kal_uint8   handover_timer_value;
    kal_uint16  num_of_profile;
    kal_uint8   more_flag;
    kal_uint8   connect_type;
    wifi_data_account_profile_struct profile_header_ptr[2];
    //kal_uint32  profile_header_ptr;
}  supc_abm_wifi_connect_req_struct;

typedef struct
{
    int pairwise_cipher;
    int group_cipher;
    int key_mgmt;
} supc_ie_info_struct;

typedef struct
{
    kal_uint8                        bssid[ WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
    kal_uint8                        privacy;                        /* WEP encryption requirement */
    kal_uint16                       ssid_len;
    kal_uint8                        ssid [ WNDRV_SSID_MAX_LEN ];    
    kal_int32                        rssi;                           /* receive signal, in dBm */
    kal_uint32                       channel_number;    
    wndrv_supc_network_type_enum     network_type;    
    kal_uint8                        max_rate; 
    kal_bool                         wpa_ie_info_p;
    supc_ie_info_struct                    wpa_ie_info;
    kal_bool                         rsn_ie_info_p;
    supc_ie_info_struct                    rsn_ie_info;
#ifdef __WAPI_SUPPORT__
    kal_bool                         wapi_ie_info_p;
    supc_ie_info_struct              wapi_ie_info;
#endif
    kal_uint8                      num_of_ap; //Kinki: numbers of APs in a SSID [MAUI_00398552]	
} supc_abm_bss_info_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint16   num_of_bss;
    kal_uint8   more_flag;
    supc_abm_bss_info_struct bss_info[WNDRV_SCAN_RESULTS_NUM];
} supc_abm_wifi_ap_list_cnf_struct;

typedef struct 
{
    kal_uint8   action;  // 0: about countdown  1: about pin-code
    kal_uint32  value; // if action is countdown, it is seconds, 
                        // if action is pin, it is pincode value
    kal_bool show; // KAL_FALSE: un-visible, KAL_TRUE: visible
} wifi_wps_ui_info_struct;

typedef struct 
{
    kal_uint8  ref_count;
    kal_uint16  msg_len;
    kal_uint8 num; // the number of valid element(s) in  info
    wifi_wps_ui_info_struct info[2];
} supc_abm_wifi_wps_info_ind_struct;
#endif /* SUPC_ABM_MSGS_H */
