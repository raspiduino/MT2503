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
 * DataAccountDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to define const variable.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _PIXTEL_DATA_ACCOUNT_DEF_H
#define _PIXTEL_DATA_ACCOUNT_DEF_H
#include "DtcntSrvGprot.h"

#include "custom_data_account.h"
#include "MMI_features.h"

#define MMI_DTCNT_DEFAULT_URL                       "http://"
#define MMI_DTCNT_DEFAULT_URL_SIZE                  strlen(MMI_WAP_PROF_DEFAULT_URL)

#define DATA_ACCOUNT_PRESET_XML_PATH    L"z:\\da_config.xml"

#define DTCNT_READY_CHECK_NUM 10

#define MAX_DIAL_NUM_LEN                    (SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN)
#define MAX_USER_LEN                        (SRV_DTCNT_PROF_MAX_USER_LEN)
#define MAX_PASSWD_LEN                      (SRV_DTCNT_PROF_MAX_PW_LEN)
#define MAX_IPADDRES_LEN                    (SRV_DTCNT_PROF_MAX_IP_ADDR_LEN)
#define MAX_PROXY_USER_LEN                  (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN)
#define MAX_PROXY_PASSWD_LEN                (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN)
#ifdef CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#define MAX_DATA_ACCOUNT_GSM_LIMIT           CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else /* CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM */
#define MAX_DATA_ACCOUNT_GSM_LIMIT           5
#endif /* CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM */
#define MAX_PART_IP_ADDRESS                  4
#define DATA_ACCOUNT_HILITED_ITEM            0
#define DATA_ACCOUNT_UCS                  0x08
#define DATA_ACCOUNT_ASCII                0x00
#define MITEM_DATA_ACCOUNT_PARENT_ZERO       0
#define MAX_INLINE_ITEM_DATA_ACCOUNT_LIST    16
#define DATA_ACCOUNT_INLINE_DATA_RATE_OPTION 5
#define DATA_ACCOUNT_INLINE_DIAL_TYPE_OPTION 2
#define DATA_ACCOUNT_INLINE_AUTH_TYPE_OPTION 2
#define DATA_ACCOUNT_INLINE_CONNECTION_TYPE_OPTION 2
#define DATA_ACCOUNT_INLINE_USE_PROXY_OPTION 2
#define DATA_ACCOUNT_INLINE_WAP_PORT_OPTION  2
#define DATA_ACCOUNT_INLINE_INTERVAL_OPTION  3

#if (MMI_MAX_SIM_NUM >= 2)
#if (MMI_MAX_SIM_NUM == 4)
#define DATA_ACCOUNT_INLINE_SIM_SELECTION    4
#elif (MMI_MAX_SIM_NUM == 3)
#define DATA_ACCOUNT_INLINE_SIM_SELECTION    3
#else
#define DATA_ACCOUNT_INLINE_SIM_SELECTION    2
#endif /* MMI_MAX_SIM_NUM */
#else /* MMI_MAX_SIM_NUM >= 2 */
#define DATA_ACCOUNT_INLINE_SIM_SELECTION    2
#endif /* MMI_MAX_SIM_NUM >= 2 */

#define DATA_ACCOUNT_NOTIFY_TIMEOUT          UI_POPUP_NOTIFYDURATION_TIME

#define DATA_RATE_2400    2400
#define DATA_RATE_4800    4800
#define DATA_RATE_9600    9600
#define DATA_RATE_14400   14400


#define MMI_DTCNT_GENERAL_STRING_LEN    (20)
#define MMI_DTCNT_MAX_PORT_LENGTH       (5)
#define MMI_DTCNT_MAX_PORT_NUM       (65535)
#define MMI_DTCNT_PROVURL_HASH_LEN      (SRV_DTCNT_PROVURL_HASH_LEN)
#define MMI_DTCNT_NAPID_HASH_LEN        (SRV_DTCNT_NAPID_HASH_LEN)



#define MAX_DATA_ACCOUN_CUI_FIX_ITEM     (0)

#ifdef MAX_GPRS_PROFILE_NUM
#define MAX_DATA_ACCOUNT_GPRS_LIMIT     MAX_GPRS_PROFILE_NUM
#else /* MAX_GPRS_PROFILE_NUM */
#define MAX_DATA_ACCOUNT_GPRS_LIMIT     5
#endif /* MAX_GPRS_PROFILE_NUM */


#ifdef __OP01_GPRS_DATACFG__
#define MMI_DTCNT_DISP_GPRS_NUM     (MAX_DATA_ACCOUNT_GPRS_LIMIT - 1)
#else /* __OP01_GPRS_DATACFG__ */
#define MMI_DTCNT_DISP_GPRS_NUM     (MAX_DATA_ACCOUNT_GPRS_LIMIT)
#endif /* __OP01_GPRS_DATACFG__ */

#define MAX_INLINE_ITEM_GPRSDATA_ACCOUNT_LIST         14
#define GPRS_DATA_ACCOUNT_INLINE_AUTH_TYPE_OPTION     2
#define MAX_GPRS_DATAACCOUNT_NAME                  31

#define MAX_GPRS_USERNAME                       (SRV_DTCNT_PROF_MAX_USER_LEN)
#define MAX_GPRS_USERPASSWD                     (SRV_DTCNT_PROF_MAX_PW_LEN)
#define MAX_GPRS_MMI_APN_LEN                    (SRV_DTCNT_PROF_MAX_APN_LEN)



#ifdef __MMI_WLAN_FEATURES__
#define MMI_WLAN_ADVANCE_FIELD (SRV_DTCNT_WLAN_PROF_FIELD_HOME | SRV_DTCNT_WLAN_PROF_FIELD_USE_PX | SRV_DTCNT_WLAN_PROF_FIELD_PX_ADDR | SRV_DTCNT_WLAN_PROF_FIELD_PX_PORT | SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH_ID | SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH_PW)
#define MMI_DTCNT_WIFI_FILE_LIMIT 100*1024
#ifdef __MMI_OP01_WIFI__
#define BACKGROUND_SEARCH_DELAY_TIME    5000    /* 5 seconds */
#define AUTO_SEARCH_DELAY_TEN_SECS      10000   /* 10 seconds */
#define AUTO_SEARCH_DELAY_HALF_MIN      30000   /* 30 seconds */
#define AUTO_SEARCH_DELAY_ONE_MIN       60000   /* 60 seconds */
#define ASK_TO_TRANSFER_NETWORK_DELAY_ONE_HOUE   3600000    /* 1 hour */
#define MMI_WLAN_EXCLUSIVE_ADD_INLINE_CAPTION1 (CUI_INLINE_ITEM_ID_BASE + 0)
#define MMI_WLAN_EXCLUSIVE_ADD_INLINE_IP1      (CUI_INLINE_ITEM_ID_BASE + 1)
#endif

#define MAX_CHANNEL_NUMBER          15
#ifdef __WIFI_SLIM__
#define MAX_WLAN_DATA_ACCOUNT_NUM   10
#else
#define MAX_WLAN_DATA_ACCOUNT_NUM   30
#endif
#define MAX_SSID_LEN                (32+1)
#define MAX_SCAN_RESULT_NUM         8
#define MAX_PASSPHRASE_LEN          (63)
#define MAX_WEP_KEYSTR_LEN          (26+1)
#define MAX_WEP_KEY_NUM             4
#define MAX_USERNAME_LEN            (32+1)
#define MAX_PASSWORD_LEN            (32+1)
#define MAX_CR_PATH_LEN             32
#define MAX_MAC_ADDR_LEN            6
#define MAX_BSSID_LEN               6
#define MAX_WLAN_PROF_NAME_LEN      MAX_SSID_LEN
#define MAX_WAPI_PSK_LEN            32
#define DTCNT_WIFI_ID               20


#define MMI_WLAN_BIT(n)             ( (kal_uint32)1 << (n) )

#define MMI_WLAN_WPA_CIPHER_TKIP             MMI_WLAN_BIT(3)
#define MMI_WLAN_WPA_CIPHER_CCMP             MMI_WLAN_BIT(4)
#define MMI_WLAN_WPA_KEY_MGMT_PSK            MMI_WLAN_BIT(1)
#define MMI_WLAN_WPA_KEY_MGMT_WPA_NONE       MMI_WLAN_BIT(4)
#define MMI_WLAN_WAPI_CIPHER_SMS4            MMI_WLAN_BIT(5)
#define MMI_WLAN_WAPI_KEY_MGMT_WAI           MMI_WLAN_BIT(6)

#define WLAN_EAP_TLS_SUPPORT
//#define WLAN_EAP_MD5_SUPPORT
#define WLAN_EAP_PEAP_SUPPORT
#define WLAN_EAP_TTLS_SUPPORT
// #ifndef __MMI_DUAL_SIM__
#define WLAN_EAP_SIM_SUPPORT
// #endif
// #define WLAN_EAP_FAST_SUPPORT
#define WLAN_EAP_MSCHAP2_SUPPORT
#define WLAN_EAP_GTC_SUPPORT
#define WLAN_PAP_SUPPORT
#define WLAN_CHAP_SUPPORT
#define WLAN_MSCHAP_SUPPORT
#define WLAN_MSCHAP2_SUPPORT


#define DEFAULT_PEAP_PHASE1_PARAM SUPC_PHASE1_LABLEL_0 | SUPC_PHASE1_OUTER_SUCCESS_0 
#define DEFAULT_ANONYMOUS_IDENTITY "anonymous"


#define MAX_WLAN_EVENT_REGISTRAR_NUM 10

#define WLAN_MAC_ADDRESS_INVALID(x) (x[0] == 0x00 &&\
                                     x[1] == 0x0C &&\
                                     x[2] == 0xE7 &&\
                                     x[3] == 0x00 &&\
                                     x[4] == 0x00 &&\
                                     x[5] == 0x00)
#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

#define MMI_WLAN_MIN_PASSPHRASE_LEN      (8)
#define MAX_NODE_ID_LEN         (64 + 1)
#define MAX_WLAN_OTA_PROF_NUM   (6)

/* Change max OTA profile# according to max WLAN profile# */
#if MAX_WLAN_OTA_PROF_NUM > MAX_WLAN_DATA_ACCOUNT_NUM
    #undef  MAX_WLAN_OTA_PROF_NUM
    #define MAX_WLAN_OTA_PROF_NUM MAX_WLAN_DATA_ACCOUNT_NUM
#endif

#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

#endif /* __MMI_WLAN_FEATURES__ */ 

#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)

#define DTCNT_ITEM_GPRS_NODE_ID		"CHT GPRS"
#define DTCNT_ITEM_CSD_NODE_ID		"CHT CSD"
#define DTCNT_DM_CHECK              2

#endif /* defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */

#define MMI_DTCNT_WLAN_AUTH_TYPE_END 0xFF


#ifndef __MMI_DTCNT_SLIM__
#define __MMI_DTCNT_ADVANCE_SETTINGS__
#define __MMI_DTCNT_READ_ONLY_DTCNT_SUPPORT__
#endif

#endif /* _PIXTEL_DATA_ACCOUNT_DEF_H */ 

