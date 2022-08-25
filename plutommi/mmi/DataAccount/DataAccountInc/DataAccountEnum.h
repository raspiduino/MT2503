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
 * DataAccountEnum.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#ifndef _PIXTEL_DATA_ACCOUNT_ENUM_H
#define _PIXTEL_DATA_ACCOUNT_ENUM_H
#include "inlinecuigprot.h"

#include "MMI_features.h"
#include "DataAccountDef.h"

typedef enum
{
    MMI_SIM1_TYPE,
    MMI_SIM2_TYPE
}mmi_sim_type_enum1;

typedef enum
{
    DIAL_TYPE_ANALOGUE,
    DIAL_TYPE_ISDN
} DATA_ACCOUNT_DIAL_TYPE_ENUM;

typedef enum
{
    ARRANGE_ACCT_TYPE_ALPHABET,
    ARRANGE_ACCT_TYPE_OTHER
} DATA_ACCOUNT_ARRANGE_TYPE_ENUM;

typedef enum
{
    MMI_DTCNT_PREPARE_DATA_FOR_PROV = 0,
    MMI_DTCNT_PREPARE_DATA_FOR_SETTING
} mmi_dtcnt_prepare_data_enum;


typedef enum
{
    DATA_RATE_TWO_FOUR,
    DATA_RATE_FOUR_EIGHT,
    DATA_RATE_NINE_SIX,
    DATA_RATE_FOURTEEN_FOUR,
    DATA_RATE_AUTO
} DATA_ACCOUNT_DATA_RATE_ENUM;


/* GPRS inline item id */
typedef enum
{
    COMMON_NAME_CAPTION_ID = CUI_INLINE_ITEM_ID_BASE + 1,
    COMMON_NAME_TEXTEDIT_ID, 
    COMMON_ADDR_CAPTION_ID,
    COMMON_ADDR_TEXTEDIT_ID,
    COMMON_USERNAME_CAPTION_ID,
    COMMON_USERNAME_TEXTEDIT_ID,
    COMMON_PASSWD_CAPTION_ID,
    COMMON_PASSWD_TEXTEDIT_ID
} COMMON_DTCNT_INLINE_ITEM_ID;


typedef enum
{
    GPRS_AUTH_CAPTION_ID = COMMON_PASSWD_TEXTEDIT_ID + 1,
    GPRS_AUTH_SELECT_ID,
//    GPRS_SIM_CAPTION_ID,
//    GPRS_SIM_SELECT_ID,
    GPRS_ADVANCE_DISPLAY_ID
} GPRS_DTCNT_INLINE_ITEM_ID;


/* CSD inline item id */
typedef enum
{
    CSD_DIAL_TYPE_CAPTION_ID  = COMMON_PASSWD_TEXTEDIT_ID + 1,
    CSD_DIAL_TYPE_SELECT_ID,
    CSD_DATA_RATE_CAPTION_ID,
    CSD_DATA_RATE_SELECT_ID,
//    CSD_SIM_CAPTION_ID,
//    CSD_SIM_SELECT_ID,
    CSD_ADVANCE_DISPLAY_ID
} CSD_DTCNT_INLINE_ITEM_ID;


/* Advanced inline item id */
typedef enum
{
    ADVANCED_HOMEPAGE_CAPTION_ID = CUI_INLINE_ITEM_ID_BASE + 1,
    ADVANCED_HOMEPAGE_FSEDIT_ID,
    ADVANCED_CONN_TYPE_CAPTION_ID,
    ADVANCED_CONN_TYPE_SELECT_ID,
    ADVANCED_USER_PROXY_CAPTION_ID,
    ADVANCED_USER_PROXY_SELECT_ID,
    ADVANCED_PROXY_ADDR_CAPTION_ID,
    ADVANCED_PROXY_ADDR_IP4_ID,
    ADVANCED_PROXY_PORT_CAPTION_ID,
    ADVANCED_PROXY_PORT_TEXTEDIT_ID,
    ADVANCED_PROXY_USERNAME_CAPTION_ID,
    ADVANCED_PROXY_USERNAME_FSEDIT_ID,
    ADVANCED_PROXY_PASSWD_CAPTION_ID,
    ADVANCED_PROXY_PASSWD_FSEDIT_ID,
#ifdef __MMI_DTCNT_ADVANCE_SETTINGS__
    ADVANCED_DNS1_CAPTION_ID,
    ADVANCED_DNS1_IP4_ID,
    ADVANCED_DNS2_CAPTION_ID,
    ADVANCED_DNS2_IP4_ID,
    ADVANCED_IP_CAPTION_ID,
    ADVANCED_IP_IP4_ID,
    ADVANCED_SUBNET_CAPTION_ID,
    ADVANCED_SUBNET_IP4_ID,
#endif
    ADVANCED_SUBNET_END
} ADVANCED_DTCNT_INLINE_ITEM_ID;


typedef enum
{
    MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT = 0,
    MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT,
    MMI_DTCNT_BEARER_FALLBACK_ACCOUNT_NUMBER_TOTAL
} mmi_dtcnt_bearer_fallback_account_enum;


typedef enum
{
    MMI_DTCNT_PROFILE_ADD = 0,
    MMI_DTCNT_PROFILE_EDIT,
    MMI_DTCNT_PROFILE_DELETE,
    MMI_DTCNT_PROFILE_VIEW
} dtcnt_set_profile_enum;

typedef enum
{
    MMI_DTCNT_CONN_TYPE,
    MMI_DTCNT_APP_TYPE,
    MMI_DTCNT_DIAL_TYPE,
    MMI_DTCNT_DATA_RATE_TYPE,
    MMI_DTCNT_AUTH_TYPE,
    MMI_DTCNT_TYPE_TOTAL
} mmi_dtcnt_type_enum;

// used to sort gprs/csd account
typedef enum
{
    MMI_DTCNT_LIST_TYPE_GPRS_USER,
    MMI_DTCNT_LIST_TYPE_CSD_USER,
    MMI_DTCNT_LIST_TYPE_GPRS_FACTORY,
    MMI_DTCNT_LIST_TYPE_CSD_FACTORY,
    MMI_DTCNT_LIST_TYPE_TOTAL
} mmi_dtcnt_list_type_enum;

typedef enum
{
    MMI_DTCNT_REGISTER_OK = 0,
    MMI_DTCNT_DEREGISTER_OK,
    MMI_DTCNT_DEREGISTER_ERROR,
    MMI_DTCNT_MAX_NUM_REGISTER,
    MMI_DTCNT_REGISTER_CALLBACK_ALREADY
} dtcnt_deletion_registration_error_enum;

typedef enum
{
    MMI_DTCNT_CALLBACK_NOTIFICATION = 0,
    MMI_DTCNT_PRIMITIVE_NOTIFICATION

}dtcnt_deletion_registration_type_enum;

typedef enum
{
    MMI_DTCNT_INIT = 0x01,
    MMI_DTCNT_PLMN = 0x02,
    MMI_DTCNT_INIT_PLMN = 0x04,
    MMI_DTCNT_INIT_PLMN_TOTAL
} mmi_dtcnt_init_plnm;


#ifdef __MMI_CCA_SUPPORT__

typedef enum
{
    MMI_DTCNT_UCS2_UTF8 = 0,
    MMI_DTCNT_UTF8_UCS2,
    MMI_DTCNT_TOTAL
} dtcnt_string_convert_enum;

typedef enum
{
    DTCNT_FOR_DM,
    DTCNT_FOR_PROVISIONING,
    DTCNT_FOR_SIM_PROV,
    DTCNT_FOR_NULL
}dtacc_func_enum;

#endif /* __MMI_CCA_SUPPORT__ */

#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)

/* Bearer type enum */
typedef enum 
{
    DTCNT_BEARER_IP_ANY,
    DTCNT_BEARER_GSM_CSD,
    DTCNT_BEARER_GSM_GPRS,
    DTCNT_BEARER_WIFI
} dtcnt_bearer_enum;

#endif /* SYNCML_DM_SUPPORT */

/* Bearer type enum */
typedef enum 
{
    DTCNT_LIST_BEARER_CSD,
    DTCNT_LIST_BEARER_GPRS,
    DTCNT_LIST_BEARER_GPRS_CSD,
    DTCNT_LIST_BEARER_WIFI,
#ifdef __MMI_CBM_ALWAYS_ASK__
    DTCNT_LIST_BEARER_ALWAYS_ASK,
#endif /* __MMI_CBM_ALWAYS_ASK__ */ 
    DTCNT_LIST_BEARER_TOTAL
} dtcnt_list_bearer_enum;
typedef enum
{
    DTCNT_CSMCC_DEFAULT_ADDR_TYPE = 129,    /* deafault number */
    DTCNT_CSMCC_INTERNATIONAL_ADDR = 145    /* international number */
} DTCNT_CSMCC_ADDR_TYPE;


#ifdef __MMI_WLAN_FEATURES__

typedef enum
{
    WLAN_TCPIP_USEDHCP_STR = 0,
    WLAN_TCPIP_USEDHCP,
    WLAN_TCPIP_IPADDR_STR,
    WLAN_TCPIP_IPADDR,
    WLAN_TCPIP_NETMASK_STR,
    WLAN_TCPIP_NETMASK,
    WLAN_TCPIP_GATEWAY_STR,
    WLAN_TCPIP_GATEWAY,
    WLAN_TCPIP_DNS1_STR,
    WLAN_TCPIP_DNS1,
    WLAN_TCPIP_DNS2_STR,
    WLAN_TCPIP_DNS2,
    WLAN_TCPIP_INLINE_TOTAL
} wlan_tcpip_settings_inline_enum;

typedef enum
{
    WLAN_NETWORK_EDIT_NAME_STR = 0,
    WLAN_NETWORK_EDIT_NAME,
    WLAN_NETWORK_EDIT_SSID_STR,
    WLAN_NETWORK_EDIT_SSID,
    WLAN_NETWORK_EDIT_NETWORK_TYPE_STR,
    WLAN_NETWORK_EDIT_NETWORK_TYPE,
    WLAN_NETWORK_EDIT_AUTH_MODE_STR,
    WLAN_NETWORK_EDIT_AUTH_MODE,
    WLAN_NETWORK_EDIT_SECURITY_SETTINGS,
    WLAN_NETWORK_EDIT_TCPIP_SETTINGS,
    WLAN_NETWORK_EDIT_INLINE_TOTAL
} wlan_network_edit_inline_enum;

typedef enum
{
    WLAN_WEP_EDIT_WEP_KEY_ID_STR = 0,
    WLAN_WEP_EDIT_WEP_KEY_ID,
    WLAN_WEP_EDIT_WEP_KEY_ENCRYPT_STR,
    WLAN_WEP_EDIT_WEP_KEY_ENCRYPT,
    WLAN_WEP_EDIT_WEP_KEY_FORMAT_STR,
    WLAN_WEP_EDIT_WEP_KEY_FORMAT,
    WLAN_WEP_EDIT_WEP_KEY_STR,
    WLAN_WEP_EDIT_WEP_KEY,
    WLAN_WEP_EDIT_INLINE_TOTAL
} wlan_wep_edit_inline_enum;

typedef enum
{
    WLAN_WAPI_PSK_EDIT_KEY_FORMAT_STR = 0,
    WLAN_WAPI_PSK_EDIT_KEY_FORMAT,
    WLAN_WAPI_PSK_EDIT_KEY_STR,
    WLAN_WAPI_PSK_EDIT_KEY,
    WLAN_WAPI_PSK_EDIT_INLINE_TOTAL
} wlan_wapi_psk_edit_inline_enum;

typedef enum
{
    WLAN_WAPI_EDIT_ASE_CERT_STR = 0,
    WLAN_WAPI_EDIT_ASE_CERT,
    WLAN_WAPI_EDIT_USER_CERT_STR,
    WLAN_WAPI_EDIT_USER_CERT,
    WLAN_WAPI_EDIT_PRIV_KEY_PASSWD_STR,
    WLAN_WAPI_EDIT_PRIV_KEY_PASSWD,
    WLAN_WAPI_EDIT_INLINE_TOTAL
} wlan_wapi_edit_inline_enum;

typedef enum
{
    WLAN_USER_INFO_USERNAME_STR = 0,
    WLAN_USER_INFO_USERNAME,
    WLAN_USER_INFO_PASSWORD_STR,
    WLAN_USER_INFO_PASSWORD,
    WLAN_USER_INFO_INLINE_TOTAL
} wlan_user_info_inline_enum;

typedef enum
{
    WLAN_EAP_TLS_SETTINGS_CA_CERT_STR = 0,
    WLAN_EAP_TLS_SETTINGS_CA_CERT,
    WLAN_EAP_TLS_SETTINGS_USER_CERT_STR,
    WLAN_EAP_TLS_SETTINGS_USER_CERT,
#ifndef __CERTMAN_SUPPORT__
    WLAN_EAP_TLS_SETTINGS_PRIV_KEY_STR,
    WLAN_EAP_TLS_SETTINGS_PRIV_KEY,
#endif /* __CERTMAN_SUPPORT__ */
    WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD_STR,
    WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD,
    WLAN_EAP_TLS_SETTINGS_USERNAME_STR,
    WLAN_EAP_TLS_SETTINGS_USERNAME,
    WLAN_EAP_TLS_SETTINGS_INLINE_TOTAL
} wlan_eap_tls_settings_inline_enum;

typedef enum
{
    WLAN_EAP_PEAP_SETTINGS_CA_CERT_STR = 0,
    WLAN_EAP_PEAP_SETTINGS_CA_CERT,
    WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL,
    WLAN_EAP_PEAP_SETTINGS_INLINE_TOTAL
} wlan_eap_peap_settings_inline_enum;

typedef enum
{
    WLAN_EAP_TTLS_SETTINGS_CA_CERT_STR = 0,
    WLAN_EAP_TTLS_SETTINGS_CA_CERT,
    WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL,
    WLAN_EAP_TTLS_SETTINGS_INLINE_TOTAL
} wlan_eap_ttls_settings_inline_enum;

typedef enum
{
    WLAN_CUINLINE_TCPIP_USEDHCP_STR = 0,
    WLAN_CUINLINE_TCPIP_USEDHCP,
    WLAN_CUINLINE_TCPIP_IPADDR_STR,
    WLAN_CUINLINE_TCPIP_IPADDR,
    WLAN_CUINLINE_TCPIP_NETMASK_STR,
    WLAN_CUINLINE_TCPIP_NETMASK,
    WLAN_CUINLINE_TCPIP_GATEWAY_STR,
    WLAN_CUINLINE_TCPIP_GATEWAY,
    WLAN_CUINLINE_TCPIP_DNS1_STR,
    WLAN_CUINLINE_TCPIP_DNS1,
    WLAN_CUINLINE_TCPIP_DNS2_STR,
    WLAN_CUINLINE_TCPIP_DNS2,
    WLAN_CUINLINE_TCPIP_INLINE_TOTAL
} wlan_cuinline_tcpip_settings_inline_enum;

typedef enum
{
    WLAN_CUINLINE_NETWORK_EDIT_NAME_STR = 0,
    WLAN_CUINLINE_NETWORK_EDIT_NAME,
    WLAN_CUINLINE_NETWORK_EDIT_SSID_STR,
    WLAN_CUINLINE_NETWORK_EDIT_SSID,
    WLAN_CUINLINE_NETWORK_EDIT_NETWORK_TYPE_STR,
    WLAN_CUINLINE_NETWORK_EDIT_NETWORK_TYPE,
    WLAN_CUINLINE_NETWORK_EDIT_AUTH_MODE_STR,
    WLAN_CUINLINE_NETWORK_EDIT_AUTH_MODE,
    WLAN_CUINLINE_NETWORK_EDIT_SECURITY_SETTINGS,
    WLAN_CUINLINE_NETWORK_EDIT_TCPIP_SETTINGS,
    WLAN_CUINLINE_NETWORK_EDIT_ADVAN_SETTINGS,      /* advance setting */
    WLAN_CUINLINE_NETWORK_EDIT_INLINE_TOTAL
} wlan_cuinline_network_edit_inline_enum;

typedef enum
{
    WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ID_STR = 0,
    WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ID,
    WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ENCRYPT_STR,
    WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ENCRYPT,
    WLAN_CUINLINE_WEP_EDIT_WEP_KEY_FORMAT_STR,
    WLAN_CUINLINE_WEP_EDIT_WEP_KEY_FORMAT,
    WLAN_CUINLINE_WEP_EDIT_WEP_KEY_STR,
    WLAN_CUINLINE_WEP_EDIT_WEP_KEY,
    WLAN_CUINLINE_WEP_EDIT_INLINE_TOTAL
} wlan_cuinline_wep_edit_inline_enum;

typedef enum
{
    WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_FORMAT_STR = 0,
    WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_FORMAT,
    WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_STR,
    WLAN_CUINLINE_WAPI_PSK_EDIT_KEY,
    WLAN_CUINLINE_WAPI_PSK_EDIT_INLINE_TOTAL
} wlan_cuinline_wapi_psk_edit_inline_enum;

typedef enum
{
    WLAN_CUINLINE_WAPI_EDIT_ASE_CERT_STR = 0,
    WLAN_CUINLINE_WAPI_EDIT_ASE_CERT,
    WLAN_CUINLINE_WAPI_EDIT_USER_CERT_STR,
    WLAN_CUINLINE_WAPI_EDIT_USER_CERT,
    WLAN_CUINLINE_WAPI_EDIT_PRIV_KEY_PASSWD_STR,
    WLAN_CUINLINE_WAPI_EDIT_PRIV_KEY_PASSWD,
    WLAN_CUINLINE_WAPI_EDIT_INLINE_TOTAL
} wlan_cuinline_wapi_edit_inline_enum;

typedef enum
{
    WLAN_CUINLINE_USER_INFO_USERNAME_STR = 0,
    WLAN_CUINLINE_USER_INFO_USERNAME,
    WLAN_CUINLINE_USER_INFO_PASSWORD_STR,
    WLAN_CUINLINE_USER_INFO_PASSWORD,
    WLAN_CUINLINE_USER_INFO_INLINE_TOTAL
} wlan_cuinline_user_info_inline_enum;

typedef enum
{
    WLAN_CUINLINE_EAP_TLS_SETTINGS_CA_CERT_STR = 0,
    WLAN_CUINLINE_EAP_TLS_SETTINGS_CA_CERT,
    WLAN_CUINLINE_EAP_TLS_SETTINGS_USER_CERT_STR,
    WLAN_CUINLINE_EAP_TLS_SETTINGS_USER_CERT,
#ifndef __CERTMAN_SUPPORT__
    WLAN_CUINLINE_EAP_TLS_SETTINGS_PRIV_KEY_STR,
    WLAN_CUINLINE_EAP_TLS_SETTINGS_PRIV_KEY,
#endif /* __CERTMAN_SUPPORT__ */
    WLAN_CUINLINE_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD_STR,
    WLAN_CUINLINE_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD,
    WLAN_CUINLINE_EAP_TLS_SETTINGS_USERNAME_STR,
    WLAN_CUINLINE_EAP_TLS_SETTINGS_USERNAME,
    WLAN_CUINLINE_EAP_TLS_SETTINGS_INLINE_TOTAL
} wlan_cuinline_eap_tls_settings_inline_enum;

typedef enum
{
    WLAN_CUINLINE_EAP_PEAP_SETTINGS_CA_CERT_STR = 0,
    WLAN_CUINLINE_EAP_PEAP_SETTINGS_CA_CERT,
    WLAN_CUINLINE_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL,
    WLAN_CUINLINE_EAP_PEAP_SETTINGS_INLINE_TOTAL
} wlan_cuinline_eap_peap_settings_inline_enum;

typedef enum
{
    WLAN_CUINLINE_EAP_TTLS_SETTINGS_CA_CERT_STR = 0,
    WLAN_CUINLINE_EAP_TTLS_SETTINGS_CA_CERT,
    WLAN_CUINLINE_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL,
    WLAN_CUINLINE_EAP_TTLS_SETTINGS_INLINE_TOTAL
} wlan_cuinline_eap_ttls_settings_inline_enum;

typedef enum
{
    WLAN_SETTINGS_AUTO_CONNECT_CATPION_STR,
    WLAN_SETTINGS_AUTO_CONNECT_SELECTOR,
#ifdef __CBM_BEARER_SWITCH__
    WLAN_SETTINGS_NETWORK_SWITCH_STR,
    WLAN_SETTINGS_NETWORK_SWITCH_SELECTOR,
#endif
#ifdef __MMI_OP01_WIFI__
    WLAN_SETTING_CELLULAR_SWITCH_STR,
    WLAN_SETTING_CELLULAR_SWICCH_SELECTOR,
    WLAN_SETTING_AUTO_PORTAL_SWITCH_STR,
    WLAN_SETTING_AUTO_PORTAL_SWITCH_SELECTOR,
#else
	WLAN_SETTINGS_POWER_SAVE_STR,
	WLAN_SETTINGS_POWER_SAVE_SELECTOR,
#endif
    WLAN_SETTINGS_INLINE_ITEM_TOTAL
} wlan_settings_inline_item_enum;

typedef enum
{
    WLAN_STATE_NULL,
    WLAN_STATE_DEINIT_WAIT,
    WLAN_STATE_INIT_WAIT,
    WLAN_STATE_INIT,
    WLAN_STATE_DISCONNECT_WAIT,
    WLAN_STATE_CONNECT_WAIT,
    WLAN_STATE_CONNECTED,
    WLAN_STATE_SCANNING,
    WLAN_STATE_SCANNING_ABORT,
    WLAN_STATE_TOTAL
} wlan_state_enum;

typedef enum
{
    WLAN_SCAN_STATE_NULL,
    WLAN_SCAN_STATE_WAITING,
    WLAN_SCAN_STATE_ABORTING,
    WLAN_SCAN_STATE_TOTAL
} wlan_scan_state_enum;

typedef enum
{
    WLAN_WEP_KEY_ENCRYPT_64,
    WLAN_WEP_KEY_ENCRYPT_128,
    /*WLAN_WEP_KEY_ENCRYPT_256,*/
    WLAN_WEP_KEY_ENCRYPT_TOTAL
} mmi_wlan_wep_key_encrypt_enum;

typedef enum
{
    WLAN_WEP_KEY_FORMAT_HEX,
    WLAN_WEP_KEY_FORMAT_ASCII,
    WLAN_WEP_KEY_FORMAT_TOTAL
} mmi_wlan_wep_key_format_enum;

typedef enum
{
#ifdef WLAN_EAP_TLS_SUPPORT
    WLAN_AUTH_TYPE_EAP_TLS,
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    WLAN_AUTH_TYPE_EAP_MD5,
#endif 
#ifdef WLAN_EAP_PEAP_SUPPORT
    WLAN_AUTH_TYPE_EAP_PEAP,
#endif 
#ifdef WLAN_EAP_TTLS_SUPPORT
    WLAN_AUTH_TYPE_EAP_TTLS,
#endif 
#ifdef WLAN_EAP_SIM_SUPPORT
    WLAN_AUTH_TYPE_EAP_SIM,
#endif 
#ifdef WLAN_EAP_FAST_SUPPORT
    WLAN_AUTH_TYPE_EAP_FAST,
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    WLAN_AUTH_TYPE_EAP_MSCHAP2,
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    WLAN_AUTH_TYPE_EAP_GTC,
#endif 
#ifdef WLAN_PAP_SUPPORT
    WLAN_AUTH_TYPE_PAP,
#endif 
#ifdef WLAN_CHAP_SUPPORT
    WLAN_AUTH_TYPE_CHAP,
#endif 
#ifdef WLAN_MSCHAP_SUPPORT
    WLAN_AUTH_TYPE_MSCHAP,
#endif 
#ifdef WLAN_MSCHAP2_SUPPORT
    WLAN_AUTH_TYPE_MSCHAP2,
#endif 
    WLAN_AUTH_TYPE_TOTAL
} wlan_auth_type_enum;

#define WLAN_AUTH_TYPE_END 0xFF

typedef enum
{
    WLAN_ACTION_NULL = 0,
    WLAN_ACTION_INIT,
    WLAN_ACTION_CONNECT,
    WLAN_ACTION_DISCONNECT,
    WLAN_ACTION_DEINIT,
    WLAN_ACTION_SCAN,
    WLAN_ACTION_TOTAL
} wlan_action_enum;

typedef enum
{
    WLAN_MATCH_SA,
    WLAN_MATCH_SE,
    WLAN_MATCH_SE_SA,
    WLAN_MATCH_SE_SA_C,
    WLAN_MATCH_SA_C
}wlan_match_type_enum;

typedef enum
{
    WLAN_ADVANCED_HOME_PAGE_STR = 0,
    WLAN_ADVANCED_HOME_PAGE,
    WLAN_ADVANCED_USE_PROXY_STR,
    WLAN_ADVANCED_USE_PROXY,
    WLAN_ADVANCED_PROXY_ADDRESS_STR,
    WLAN_ADVANCED_PROXY_ADDRESS,
    WLAN_ADVANCED_PROXY_PORT_STR,
    WLAN_ADVANCED_PROXY_PORT,
    WLAN_ADVANCED_PROXY_USER_NAME_STR,
    WLAN_ADVANCED_PROXY_USER_NAME,
    WLAN_ADVANCED_PROXY_PASSWORD_STR,
    WLAN_ADVANCED_PROXY_PASSWORD,
    WLAN_ADVANCED_TOTAL
} wlan_advanced_inline;


/* Advanced inline item id */
typedef enum
{
    WLAN_ADVAN_HOMEPAGE_CAPTION_ID = CUI_INLINE_ITEM_ID_BASE,
    WLAN_ADVAN_HOMEPAGE_FSEDIT_ID,

    WLAN_ADVAN_USER_PROXY_CAPTION_ID,
    WLAN_ADVAN_USER_PROXY_SELECT_ID,
    WLAN_ADVAN_PROXY_ADDR_CAPTION_ID,
    WLAN_ADVAN_PROXY_ADDR_IP4_ID,
    WLAN_ADVAN_PROXY_PORT_CAPTION_ID,
    WLAN_ADVAN_PROXY_PORT_TEXTEDIT_ID,
    WLAN_ADVAN_PROXY_USERNAME_CAPTION_ID,
    WLAN_ADVAN_PROXY_USERNAME_FSEDIT_ID,
    WLAN_ADVAN_PROXY_PASSWD_CAPTION_ID,
    WLAN_ADVAN_PROXY_PASSWD_FSEDIT_ID,
} wlan_advan_inline_item_id;

typedef enum    /* WPS Connection Type */
{
    WLAN_WPS_PBC,
    WLAN_WPS_PIN,
    WLAN_WPS_TOTAL
} wlan_wps_conn_type;

typedef enum
{
    WLAN_EXCLUSIVE_URL_CAPTION,
    WLAN_EXCLUSIVE_URL_EDITOR,    
    WLAN_EXCLUSIVE_URL_TOTAL
} wlan_exclusive_url_inline;

typedef enum
{
    WLAN_EXCLUSIVE_URL_CAPTION_ID = CUI_INLINE_ITEM_ID_BASE,
    WLAN_EXCLUSIVE_URL_EDITOR_ID
} wlan_exclusive_url_inline_item_id;

/* UI Status Machine */
typedef enum
{
    MMI_WLAN_UI_NONE,
    MMI_WLAN_UI_AUTO_CONN,          /* Connect to AP automatically in CMCC project */
    MMI_WLAN_UI_CONNECT_BY_CUI,     /* Connection triggered in WLAN CUI */
    MMI_WLAN_UI_CONNECT_BY_APP,     /* Connection triggered in WLAN APP */
    MMI_WLAN_UI_CONNECT_BY_WPS,     /* WPS connection */
    MMI_WLAN_UI_CONNECT_BY_API,     /* Triggered by invoking auto conn. API */
    MMI_WLAN_UI_SCANNING,           /* Scanning */
    MMI_WLAN_UI_ABORT_SCAN,
    MMI_WLAN_UI_ABORT_CONNECT,      /* Abort connecting */
    MMI_WLAN_UI_WAIT_FOR_IP_UPDATE, /* Waiting for IP update event */
    MMI_WLAN_UI_DISC_AFTER_LOGIN_FAILED,    /* CMCC: disconnect if login failed */
    MMI_WLAN_UI_PORTAL_LOGIN,               /* CMCC: login to portal server */
    MMI_WLAN_UI_PORTAL_LOGOUT,              /* CMCC: logout */
    MMI_WLAN_UI_TOTAL    
} mmi_wlan_ui_flow_enum;

#ifdef __MMI_OP01_WIFI__
/* Auto searching settings */
typedef enum
{
    WLAN_AUTO_SEARCH_SWITCH_STR,
    WLAN_AUTO_SEARCH_SWITCH,
    WLAN_AUTO_SEARCH_INTERVAL_STR,
    WLAN_AUTO_SEARCH_INTERVAL,
    WLAN_AUTO_CONN_SWITCH_STR,      // Auto conn
    WLAN_AUTO_CONN_SWITCH,
    WLAN_NETWORK_SWITCH_STR,        // Network switch  
    WLAN_NETWORK_SWITCH,
    WLAN_SSID_SWITCH_STR,           // SSID
    WLAN_SSID_SWITCH,
    WLAN_CELLULAR_SWITCH_STR,       // Cellular network switch
    WLAN_CELLULAR_SWITCH,
    WLAN_AUTO_PORTAL_SWITCH_STR,    // Auto portal switch
    WLAN_AUTO_PORTAL_SWITCH,
    WLAN_AUTO_SEARCH_TOTAL    
} wlan_auto_search_setting_inline;

typedef enum
{
    WLAN_AUTO_SEARCH_CAPTION_ID = CUI_INLINE_ITEM_ID_BASE,
    WLAN_AUTO_SEARCH_SELECT_ID,
    WLAN_AUTO_SEARCH_INTERVAL_CAPTION_ID,
    WLAN_AUTO_SEARCH_INTERVAL_SELECT_ID,
    WLAN_AUTO_CONN_CAPTION_ID,          // Auto conn
    WLAN_AUTO_CONN_SELECT_ID,
    WLAN_NETWORK_SWITCH_CAPTION_ID,     // Network switch
    WLAN_NETWORK_SWITCH_SELECT_ID,
    WLAN_SSID_SWITCH_CAPTION_ID,     // SSID switch
    WLAN_SSID_SWITCH_SELECT_ID,
    WLAN_CELLULAR_SWITCH_CAPTION_ID,     // Cellular switch
    WLAN_CELLULAR_SWITCH_SELECT_ID,
    WLAN_AUTO_PORTAL_SWITCH_CAPTION_ID,     // Auto portal switch
    WLAN_AUTO_PORTAL_SWITCH_SELECT_ID
} wlan_auto_search_setting_inline_item_id;


/* Find Specific AP settings */
typedef enum
{
    WLAN_FIND_AP_STR,
    WLAN_FIND_AP_EDITOR,
    WLAN_FIND_AP_TOTAL
} wlan_find_ap_setting_inline;

typedef enum
{
    WLAN_FIND_AP_CAPTION_ID = CUI_INLINE_ITEM_ID_BASE,
    WLAN_FIND_AP_EDITOR_ID
} wlan_find_ap_setting_inline_item_id;


/* Access Point CLASSIFICATION */
typedef enum
{
    WLAN_AP_MGR_TYPE_DEFAULT,
    WLAN_AP_MGR_TYPE_USER_DEFINE,
    WLAN_AP_MGR_TYPE_UNKNOWN,
    WLAN_AP_MGR_TYPE_BLACK_LIST,
    WLAN_AP_MGR_TYPE_END
} wlan_ap_mgr_type_enum;

/* Exclusive Proxy List */
typedef enum
{
    MMI_WLAN_EXCLUSIVE_IP_OPTION_ADD,
    MMI_WLAN_EXCLUSIVE_IP_OPTION_DELETE,

    MMI_WLAN_EXCLUSIVE_IP_OPTION_TOTAL
} mmi_wlan_exclusive_ip_option_enum;

/* Power saving mode */
typedef enum
{
    MMI_WLAN_POWER_SAVING_MODE_NORMAL = 0,
    MMI_WLAN_POWER_SAVING_MODE_CTIA,
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    MMI_WLAN_POWER_SAVING_MODE_TOTAL
} mmi_wlan_power_saving_mode_enum;

/* AP Mgr Screen Menu Items ID */
#endif /* __MMI_OP01_WIFI__ */
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* _PIXTEL_DATA_ACCOUNT_ENUM_H */ 
