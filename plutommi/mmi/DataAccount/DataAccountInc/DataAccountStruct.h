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
 * DataAccountStruct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to define data structure.
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
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#ifndef _PIXTEL_DATA_ACCOUNT_STRUCT_H
#define _PIXTEL_DATA_ACCOUNT_STRUCT_H

#include "DataAccountGprot.h"
#include "DataAccountEnum.h"
#include "DataAccountDef.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "MMIDataType.h"
#include "cbm_consts.h"
#include "kal_general_types.h"
#include "custom_data_account.h"
#include "stack_config.h"
#include "MMI_features.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "supc_abm_msgs.h"
#include "wndrv_cnst.h"
#include "gui_data_types.h"
#include "FileMgrSrvGProt.h"

/****************************************** data account UE struct ****************************************************/
#if MAX_GPRS_MMI_APN_LEN + 1 > MAX_DIAL_NUM_LEN + 1
    #define MAX_DTCNT_LIST_ADDR_LEN  (MAX_GPRS_MMI_APN_LEN + 1)
#else 
    #define MAX_DTCNT_LIST_ADDR_LEN  (MAX_DIAL_NUM_LEN + 1)
#endif

#define MAX_ADDRESS_NAME_LEN 256
#define MMI_DTCNT_MAX_PROXY_URL_LEN (CUSTOM_MAX_PROXY_ADDR_LEN)


typedef struct
{
    U32 profile_id;
    U8 connection_type;
    U8 sim_info;
    U8 bearer_type;
    U8 read_only;
    srv_dtcnt_prof_acc_type_enum account_type;
}mmi_dtcnt_list_disp_struct;
    
    
/* this struct is used to define common data block to store account name and address */
typedef struct
{
    U8 data_account_name[(MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1) * ENCODING_LENGTH];	
    U8 data_account_addr[MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH];
} mmi_dtcnt_comm_disp_name_addr; 


// hotswap only
typedef struct
{
    U8 num_ids;                                 /* the number of profile id need to be deleted after deatived */
    U8 ids[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM];     /* profile ids need to be deleted after deatived */
} mmi_dtcnt_hotswap_del_prof_struct;


typedef struct
{    
    U8 check_status;
    U8 acct_type;
    //U8 sim_info;
    U8 connection_type;
    U8 use_proxy;
    U8 wap_port_index;
    U8 read_only;
    U8 curr_select_item;
    U8 gprs_curr_select_item;

    dtcnt_set_profile_enum set_type;
    srv_dtcnt_bearer_enum bearer;
    mmi_id common_inline_group_id;
    mmi_id advanced_inline_group_id;
    mmi_id option_group_id;
    mmi_id sim_list_group_id;
    srv_dtcnt_sim_type_enum curr_sim_type; // available SIM will be always existed

    U16 main_list_icon[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM]; // icons for default account id
    // unicode
    U8 data_account_name[(MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH];
    U8 user_name[(MAX_USER_LEN + 1) * ENCODING_LENGTH];
    U8 home_page[MAX_ADDRESS_NAME_LEN * ENCODING_LENGTH];
    U8 proxy_port_str[(MMI_DTCNT_MAX_PORT_LENGTH + 1) * ENCODING_LENGTH];
    U8 proxy_user_name[(MAX_PROXY_USER_LEN + 1) * ENCODING_LENGTH];
    U8 proxy_password[(MAX_PROXY_PASSWD_LEN + 1) * ENCODING_LENGTH];
    U8 dns1_ip[MAX_PART_IP_ADDRESS];
    U8 dns1_ip_address_display[(MAX_IPADDRES_LEN * 4) * ENCODING_LENGTH];
    U8 dns2_ip[MAX_PART_IP_ADDRESS];
    U8 dns2_ip_address_display[(MAX_IPADDRES_LEN * 4) * ENCODING_LENGTH];
    U8 ip[MAX_PART_IP_ADDRESS];
    U8 ip_address_display[(MAX_IPADDRES_LEN * 4) * ENCODING_LENGTH];
    U8 submask_ip[MAX_PART_IP_ADDRESS];
    U8 submask_ip_address_display[(MAX_IPADDRES_LEN * 4) * ENCODING_LENGTH];
    U8 proxy_ip[(MMI_DTCNT_MAX_PROXY_URL_LEN + 1) * ENCODING_LENGTH];
    U8 proxy_ip_address_display[(MAX_IPADDRES_LEN * 4) * ENCODING_LENGTH];
    U8 addr[MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH];
    U8 password[(MAX_PASSWD_LEN + 1) * ENCODING_LENGTH];

    S32 dial_type;
    S32 dial_rate;    
    S32 auth_type;
    U32 proxy_port;   
    U32 list_number;
    U32 cur_profile_id;
    U32 cur_index;
    MMI_BOOL advanced_modified;
    MMI_BOOL profile_setted;
    mmi_dtcnt_list_disp_struct profile_list[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM]; 
}mmi_dtcnt_node_display_struct;


/**********************************************************************************************************/


#ifdef __MMI_WLAN_FEATURES__

typedef struct wlan_action_st
{
    struct wlan_action_st *next;
    wlan_action_enum action;
    void *data;
} wlan_action_struct;

typedef struct
{
    U8 index;
    U8 ssid_len;
    U8 ssid[SRV_DTCNT_PROF_MAX_SSID_LEN + 1];           /* SSID ASCII string (MAX: 32 + 1) */
    U8 name[(SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN + 1) * ENCODING_LENGTH];
    U8 priority;
    U8  privacy;
    S32 rssi;
    U32 channel;                                        /* channel info */
    U32 profile_id;                                     /* associated profile ID */
    MMI_BOOL wpa_ie_info_p;
    MMI_BOOL rsn_ie_info_p;
    
    srv_dtcnt_wlan_network_type_enum    network_type;   /* profile network type */
    srv_dtcnt_wlan_auth_mode_enum       auth_mode;      /* profile auth.mode */   
    srv_dtcnt_wlan_encrypt_mode_enum    encrypt_mode;   /* profile encrypt mode */
    
#ifdef __CERTMAN_SUPPORT__
    U32 root_ca_id;                                     /* root ca id */
    U32 client_ca_id;                                   /* user cert id */
#else
    kal_wchar root_ca_path[SRV_FMGR_PATH_MAX_LEN + 2];
    kal_wchar client_ca_path[SRV_FMGR_PATH_MAX_LEN + 2];
    kal_wchar private_key_path[SRV_FMGR_PATH_MAX_LEN + 2];
#endif /* __CERTMAN_SUPPORT__ */

#ifdef __WAPI_SUPPORT__
    U32 wapi_ase_id;
    U32 wapi_client_id;
    S32 wapi_psk_format;
    U8 wapi_psk_str[SRV_DTCNT_WAPI_PSK_STR_LEN];            /* wapi pre-shared key string */
    CHAR wapi_private_key_passwd_str[MAX_PASSWORD_LEN + 1];   /* wapi private key passwd string (ASCII, MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */
#endif
    srv_dtcnt_wlan_ap_type_enum ap_type;
    U8 wep_key_index;
    U8 wep_key_len;
    U8 wep_key_format;
    U8 wep_key[SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1];         /* wep key string (MAX: 26 + 1) */
    U8 passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1];   /* passphrase string (MAX: 63 + 1 ) */
    U32 passphrase_len;
    U8 psk[SRV_DTCNT_PROF_MAX_PSK_LEN];                     /* pre-shared key for passphrase (MAX: 34) */
    U8 username[MAX_USERNAME_LEN];              /* 32 + 1 */
    U8 password[MAX_PASSWORD_LEN];              /* 32 + 1 */
    U8 private_key_passwd[MAX_PASSWORD_LEN];    /* 32 + 1 */
    
    U8 peap_version;
    U32 auth_type1;
    U32 eap_peap_auth_type;
    U32 eap_ttls_auth_type;
    
    U8 ip_addr[MAX_IPADDRES_LEN];   /* IP address */
    U8 netmask[MAX_IPADDRES_LEN];   /* Netmask */
    U8 gateway[MAX_IPADDRES_LEN];   /* Gateway */
    U8 dns1[MAX_IPADDRES_LEN];      /* Primary DNS */
    U8 dns2[MAX_IPADDRES_LEN];      /* Secondary DNS */
    
    BOOL use_dhcp;
    BOOL use_anonymous;
    
    MMI_BOOL is_search_matched;
    MMI_BOOL is_connected;
    MMI_BOOL always_ask_connect_flag;
    MMI_BOOL always_ask_before_connect_flag;
} mmi_wlan_profile_struct;

typedef struct
{
    mmi_wlan_profile_struct *p_sa;
    supc_abm_bss_info_struct *p_se;
#ifdef __MMI_OP01_WIFI__
    wlan_ap_mgr_type_enum ap_mgr_type;
#endif
    wlan_match_type_enum type;
    U32 priority;
    U32 search_index;
} mmi_wlan_wizard_list_struct;

typedef struct
{
    U8 index;
} mmi_wlan_trust_list_struct;

typedef struct
{
    U8 ssid_len;
    U8 ssid[SRV_DTCNT_PROF_MAX_SSID_LEN + 1];          /* 32 + 1 */
    U8 name[MAX_WLAN_PROF_NAME_LEN * 2];
    U8 network_type;
    U8 auth_mode;
    U8 encrypt_mode;
    MMI_BOOL is_in_black_list;
} mmi_wlan_black_list_struct;

typedef struct
{
    supc_abm_bss_info_struct        search_ap_p;
    mmi_wlan_profile_struct         *saved_ap_p;
    MMI_BOOL                        is_saved;
} mmi_wlan_auto_conn_list_struct;

typedef struct
{
    U8 dummy;
    BOOL start_on_bootup;
    U16 dummy_1;
    U32 profile_id_count;
} mmi_wlan_setting_struct;

typedef struct
{
    mmi_id inline_wep_cui_id;
    mmi_id inline_setting_cui_id;
    mmi_id inline_tcp_ip_cui_id;
    mmi_id inline_wapi_cert_cui_id;
    mmi_id inline_wapi_psk_cui_id;
    mmi_id inline_eap_ttls_cui_id;
    mmi_id inline_eap_peap_cui_id;
    mmi_id inline_eap_tls_cui_id;
    mmi_id inline_eap_user_info_cui_id;
    mmi_id inline_default_eap_cui_id;
    mmi_id wlan_editor_cui_id;
    mmi_id wlan_inline_editor_cui_id;
    mmi_id wlan_advan_cui_id;
    mmi_id wlan_prefer_setting_id;
    MMI_ID waiting_screen_id;
    mmi_id inline_trust_list_cui_id;
    mmi_id inline_find_ap;
	MMI_ID delete_confirm_id;
    
    U16 top_screen;
    BOOL insert_mode;
    BOOL modified;
    BOOL modified2;
    BOOL wpa_psk_modified;
    BOOL notification_pending;
    BOOL play_tone_flag;
    MMI_BOOL init_by_always_ask;
    MMI_BOOL search_connect_need_save;
    MMI_BOOL entry_wizard_new_list;
    MMI_BOOL wizard_profile_changed;
    MMI_BOOL wizard_priority_changed;
    MMI_BOOL send_conn_req_ing;
	MMI_BOOL deinit_when_connected;
    U8 prof_num;    /* Defined profile number */
    U8 infra_prof_num;
    U8 adhoc_prof_num;

    U8 wizard_list_se_sa_num;
    U8 wizard_list_se_num;
    U8 wizard_list_sa_num;
    U8 wizard_cur_profile_list_index;
    U8 network_list_hilt_idx;
    wlan_match_type_enum wizard_list_option;
    
    wlan_scan_state_enum scan_state;
    MMI_BOOL pre_connect_by_always_ask;
    U8 mac_addr[MAX_MAC_ADDR_LEN];
    S32 rssi;
    S32 channel_number;
    U16 current_data_rate;

    S32 curr_channel_number;
    U8 curr_ip_addr[MAX_IPADDRES_LEN];                       /* IP address */
    U8 curr_netmask[MAX_IPADDRES_LEN];                       /* Netmask */
    U8 curr_gateway[MAX_IPADDRES_LEN];                       /* Gateway */
    U8 curr_dns1[MAX_IPADDRES_LEN];                          /* Primary DNS */
    U8 curr_dns2[MAX_IPADDRES_LEN];                          /* Secondary DNS */

    mmi_wlan_profile_struct temp_profile;

    mmi_wlan_profile_struct *connected_wlan_profile;
    mmi_wlan_profile_struct *active_wlan_profile_p;
    mmi_wlan_profile_struct *change_priority_profile_p;
    U8 change_priority_profile_index;
    U8 active_wlan_profile_index;

    U8 bssid[MAX_MAC_ADDR_LEN];
    U8 ssid_len;
    U8 ssid[SRV_DTCNT_PROF_MAX_SSID_LEN + 1];
    U8 name[MAX_WLAN_PROF_NAME_LEN *ENCODING_LENGTH];

    supc_abm_bss_info_struct *active_ap;
    supc_abm_bss_info_struct ap_list[WNDRV_MAX_SCAN_RESULTS_NUM];
    U8 ap_list_num;

    S32 new_priority;

    S32 use_dhcp;
    S32 use_dhcp_dummy;                                 /* Associate with inline select only */

    UI_character_type ip_addr_str[4][MAX_IPADDRES_LEN]; /* IP address */
    UI_character_type netmask_str[4][MAX_IPADDRES_LEN]; /* Netmask */
    UI_character_type gateway_str[4][MAX_IPADDRES_LEN]; /* Gateway */
    UI_character_type dns1_str[4][MAX_IPADDRES_LEN];    /* Primary DNS */
    UI_character_type dns2_str[4][MAX_IPADDRES_LEN];    /* Secondary DNS */
    U8 ip_addr[MAX_IPADDRES_LEN];                       /* IP address */
    U8 netmask[MAX_IPADDRES_LEN];                       /* Netmask */
    U8 gateway[MAX_IPADDRES_LEN];                       /* Gateway */
    U8 dns1[MAX_IPADDRES_LEN];                          /* Primary DNS */
    U8 dns2[MAX_IPADDRES_LEN];                          /* Secondary DNS */

    srv_dtcnt_wlan_network_type_enum network_type;
    srv_dtcnt_wlan_auth_mode_enum    auth_mode;
    srv_dtcnt_wlan_encrypt_mode_enum encrypt_mode;
    S32 network_type_dummy;
    U8 ssid_str[(SRV_DTCNT_PROF_MAX_SSID_LEN + 1) * ENCODING_LENGTH];

    U32 auth_type1;
    U8 sel_auth_type1;

    U32 eap_peap_auth_type;
    U8 sel_eap_peap_auth_type;

    U32 eap_ttls_auth_type;
    U8 sel_eap_ttls_auth_type;

    U8 sel_auth_mode;
    U8 sel_encrypt_mode;
    S32 sel_wep_key_index;
    S32 sel_wep_key_len;
    S32 sel_wep_key_format;
    U8 sel_wep_key_str[MAX_WEP_KEYSTR_LEN *ENCODING_LENGTH];
    U8 wep_key_str[MAX_WEP_KEYSTR_LEN *ENCODING_LENGTH];
    U8 passphrase_str[(SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH];
    U8 cui_passphrase_str[(SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH];
    U8 psk[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1];
    S16 keylen;
    U16 pass_len;

    S32 wep_key_index;
    S32 wep_key_len;
    S32 wep_key_format;
#ifdef __CERTMAN_SUPPORT__
    U32 root_ca_id;
    U32 root_trans_id;
    U32 client_ca_id;
    U32 client_ca_trans_id;
    CHAR private_key_name[(MAX_USERNAME_LEN + 1) *ENCODING_LENGTH];
    CHAR root_ca_name[(MAX_USERNAME_LEN + 1) *ENCODING_LENGTH];
    CHAR client_user_name[(MAX_USERNAME_LEN + 1) *ENCODING_LENGTH];
#else
    CHAR private_key_path[SRV_FMGR_PATH_BUFFER_SIZE];
    CHAR root_ca_path[SRV_FMGR_PATH_BUFFER_SIZE];
    CHAR client_ca_path[SRV_FMGR_PATH_BUFFER_SIZE];
#endif /* __CERTMAN_SUPPORT__ */
    CHAR private_key_passwd_str[MAX_PASSWORD_LEN *ENCODING_LENGTH];
    U8 username_str[MAX_USERNAME_LEN *ENCODING_LENGTH];
    U8 password_str[MAX_PASSWORD_LEN *ENCODING_LENGTH];
    U8 passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1];
    U8 is_key_input_invalid;
    S32 allow_peap0;
    S32 allow_peap1;
//#ifdef __WAPI_SUPPORT__
    S32 wapi_psk_format;
    U16 wapi_psk_format_opt[WLAN_WEP_KEY_FORMAT_TOTAL];
    U8 wapi_psk_str[(31 + 1) * ENCODING_LENGTH];
    U32 wapi_ase_id;
    U32 wapi_client_id;
    CHAR wapi_ase_name[(MAX_USERNAME_LEN + 1) *ENCODING_LENGTH];
    CHAR wapi_client_name[(MAX_USERNAME_LEN + 1) *ENCODING_LENGTH];    
    CHAR wapi_private_key_passwd_str[(MAX_PASSWORD_LEN + 1) *ENCODING_LENGTH];
    MMI_BOOL wapi_is_cert_changed;
    MMI_BOOL wapi_is_auto_connect;
//#endif

    U32 scan_job_id;

    U8 home_page[MAX_ADDRESS_NAME_LEN * ENCODING_LENGTH];
    U8 home_page_buf[MAX_ADDRESS_NAME_LEN * ENCODING_LENGTH];
    U8 use_proxy;
    U32	proxy_port;
    U8 proxy_port_str[(MMI_DTCNT_MAX_PORT_LENGTH + 1) * ENCODING_LENGTH];
    U8 proxy_user_name[(MAX_USER_LEN + 1) * ENCODING_LENGTH];
    U8 proxy_password[(MAX_PASSWD_LEN + 1) * ENCODING_LENGTH];
    U8 proxy_ip[MAX_PART_IP_ADDRESS];
    U8 proxy_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN * ENCODING_LENGTH];
	U8 proxy_addr_buf[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN * ENCODING_LENGTH];

    S32 confirm_type;
    S32 conn_num;
    mmi_id option_menu_cui_id;
    mmi_wlan_ui_flow_enum   ui_flow;
    supc_abm_bss_info_struct *cui_search_hilt_ap;
    mmi_wlan_profile_struct  *cui_saved_hilt_ap;

    /* WPS */
    wlan_wps_conn_type conn_type_index;
    supc_connection_type_enum conn_type;
    U32 left_time;
    U32 pin_code;
    BOOL is_to_define_ap;
#ifdef __MMI_OP01_WIFI__    
    MMI_BOOL is_auto_search;
    MMI_BOOL is_auto_conn;
    MMI_BOOL is_ssid_switch;
    mmi_id wlan_auto_search_setting_cui_id;
    mmi_id wlan_find_ap_setting_cui_id;
    mmi_id wlan_transfer_network_no_ask_confirm_id;
    mmi_id portal_cert_setting_gid;
    mmi_id portal_cert_login_gid;
    mmi_id portal_cert_logout_gid;
    U8 trust_list_num;
    U8 black_list_num;
    U8 display_ap_num;
    U8 total_ap_num;
    U8 ssid_list_num;
    U8 auto_search_interval_idx;
    U8 network_switch_idx;
    U8 cellular_switch_idx;
    U8 auto_portal_switch_idx;
    mmi_wlan_power_saving_mode_enum power_saving_mode;
    U8 find_ap_ssid[(SRV_DTCNT_PROF_MAX_SSID_LEN + 1) * ENCODING_LENGTH];
    U32 trust_list_hilt_index;
    U32 black_list_hilt_index;   
    U32 find_res_list_hilt_index;
    U32 auto_search_interval;
    mmi_wlan_profile_struct *trust_list_hilt_profile_p;    
#endif
} mmi_wlan_display_struct;

typedef struct
{
    MMI_BOOL is_auto_search;
    U32 auto_search_interval;
    MMI_BOOL is_auto_conn;
    U32 network_switch;
    MMI_BOOL is_ssid_switch;
    U32 cellular_switch;
    U32 auto_portal_switch;
    U32 power_saving_mode;
} mmi_wlan_auto_search_struct;

typedef kal_bool(*EncodeFunc) (wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase);

typedef struct auth_plugin_st
{
    U32 val;
    U16 name_string_id;
    FuncPtr entry_func;
} auth_plugin_struct;


#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

/*
 * Slim WLAN profile used during OTA provisioning to save memory space. It will
 * be allocated from 512-bytes control buffer pool.
 */
typedef struct
{
    U8 node_id[MAX_NODE_ID_LEN];                        /* UTF-8, 0-ended   */
    U8 name[MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH];  /* UCS2, 0-ended    */
    U8 ssid[MAX_SSID_LEN];                              /* ASCII, 0-ended   */
    U8 ssid_len;
    U8 network_type;
    U8 encrypt_mode;
    U8 auth_mode;
    U32 auth_type1;
    U8 username[MAX_USERNAME_LEN];
    U8 password[MAX_PASSWORD_LEN];
    U8 wep_key_index;
    U8 wep_key_len;
    U8 wep_key_format;
    U8 wep_key[MAX_WEP_KEYSTR_LEN];
    U8 passphrase[MAX_PASSPHRASE_LEN + 1];
    U8 psk[32 + 1];                         /* Last byte: whether PSK is set */
} mmi_wlan_slim_profile_struct;

/*
 * Control block for WLAN OTA provisioning. It will be allocated from 256-
 * bytes control buffer pool. 
 */
typedef struct
{
    /* conf_id and doc_hdl are indicated by CCA. And we need to pass these two
       variable back to CCA when we send the response message. */
    U16 conf_id;        /* Configuration ID                                 */
    S32 doc_hdl;        /* Configuration document handle                    */
    
    /* node_id stores the id of a NAPDEF node. It is used to inform CCA that 
       this NAPDEF node has been installed. name is the profile name of a 
       NAPDEF node. It is possible there are multiple WLAN nodes in a NAPDEF 
       node such that we need to remember the name that will become the prefix
       of all such WLAN profiles. */
    U8 node_id[MAX_NODE_ID_LEN];                        /* UTF-8, 0-ended   */
    U8 name[MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH];  /* UCS2, 0-ended    */

    MMI_BOOL is_active; /* Enable to process node/param                     */
    U8 num_profiles;    /* Num of processed profiles                        */
    U8 iter;            /* Used to traverse profiles                        */
    S16 in_use;         /* The index of the profile that is used currently  */
    S16 choice;         /* The index of the profile that is to be replaced  */

    /* The variables 'src_idx' and 'dst_idx' provide linkage between 
       this->profile[] and g_wlan_prof_list[]. */
    S16 src_idx[MAX_WLAN_DATA_ACCOUNT_NUM];
    S16 dst_idx[MAX_WLAN_OTA_PROF_NUM];
    S16 sel_dst_idx[MAX_WLAN_DATA_ACCOUNT_NUM];

    /* Storage for incoming profiles. */
    mmi_wlan_slim_profile_struct *profile[MAX_WLAN_OTA_PROF_NUM];
    U8 cur_status;
} mmi_wlan_otap_struct;

#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

#endif /* __MMI_WLAN_FEATURES__ */ 
#endif /* _PIXTEL_DATA_ACCOUNT_STRUCT_H */ 

