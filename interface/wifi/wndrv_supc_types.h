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
 *  wndrv_supc_types.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Common data structures provided by WLAN network driver task to 
 *  Supplicant task
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _WNDRV_SUPC_TYPES_H
#define _WNDRV_SUPC_TYPES_H

//#include "kal_release.h"
#include "wndrv_cnst.h"
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
/*******************************************************************************
*
*  Enums
*
*******************************************************************************/
typedef enum 
{
  WNDRV_SUPC_NETWORK_IBSS,
  WNDRV_SUPC_NETWORK_INFRASTRUCTURE,       
  WNDRV_SUPC_NETWORK_AUTO_UNKNOWN,
  WNDRV_SUPC_NETWORK_INFRASTRUCTURE_MAX 
} wndrv_supc_network_type_enum;


typedef enum
{
  WNDRV_SUPC_AUTH_MODE_OPEN,
  WNDRV_SUPC_AUTH_MODE_SHARED,
  WNDRV_SUPC_AUTH_MODE_AUTO_SWITCH,
  WNDRV_SUPC_AUTH_MODE_WPA,
  WNDRV_SUPC_AUTH_MODE_WPA_PSK,
  WNDRV_SUPC_AUTH_MODE_WPA_NONE,
  WNDRV_SUPC_AUTH_MODE_WPA2,
  WNDRV_SUPC_AUTH_MODE_WPA2_PSK,
#ifdef __WAPI_SUPPORT__
  WNDRV_SUPC_AUTH_MODE_WAPI,
  WNDRV_SUPC_AUTH_MODE_WAPI_PSK,
#endif
  WNDRV_SUPC_AUTH_MODE_MAX
} wndrv_supc_auth_mode_enum;


typedef enum
{
  WNDRV_SUPC_WEP_ENABLED,
  WNDRV_SUPC_ENCRYPTION1_ENABLED = WNDRV_SUPC_WEP_ENABLED,
  
  WNDRV_SUPC_WEP_DISABLED,
  WNDRV_SUPC_ENCRYPTION_DISABLED = WNDRV_SUPC_WEP_DISABLED,
  
  WNDRV_SUPC_WEP_KEY_ABSENT,
  WNDRV_SUPC_ENCRYPTION1_KEY_ABSENT = WNDRV_SUPC_WEP_KEY_ABSENT,
  
  WNDRV_SUPC_WEP_NOT_SUPPORTED,
  WNDRV_SUPC_ENCRYPTION_NOT_SUPPORTED = WNDRV_SUPC_WEP_NOT_SUPPORTED,
  
  WNDRV_SUPC_ENCRYPTION2_ENABLED,
  WNDRV_SUPC_ENCRYPTION2_KEY_ABSENT,
  
  WNDRV_SUPC_ENCRYPTION3_ENABLED,
  WNDRV_SUPC_ENCRYPTION3_KEY_ABSENT
#ifdef __WAPI_SUPPORT__
  ,
  WNDRV_SUPC_WPI_ENABLED,
  WNDRV_SUPC_WPI_KEY_ABSENT
#endif /*__WAPI_SUPPORT__*/
} wndrv_supc_encryption_status_enum;


typedef enum
{    
  WNDRV_SUPC_FH,    
  WNDRV_SUPC_DS,    
  WNDRV_SUPC_OFDM_5,    
  WNDRV_SUPC_OFDM_24,    
  WNDRV_SUPC_AUTO_MODE,    
  WNDRV_SUPC_MODULATION_TYPE_MAX /* not a real type, defined as an upper bound */
} wndrv_supc_modulation_type_enum;


/*******************************************************************************
*
*  Structs
*
*******************************************************************************/
typedef struct
{    
  kal_uint8    bssid[ WNDRV_MAC_ADDRESS_LEN ];    
  kal_uint8    pmkid[16];
} wndrv_supc_pmkid_param_struct;


typedef struct
{
  wndrv_supc_auth_mode_enum          auth_mode;
  wndrv_supc_encryption_status_enum  encryption;
} wndrv_supc_auth_encry_struct;


typedef struct 
{     
  kal_uint8                     version;     /* 2 = WPA2 */     
  kal_uint8                     num_pmkids;  /* refer to wndrv_supc_pmkid_struct. */ 
  kal_uint8                     num_auth_encry_pairs_supported;    
  wndrv_supc_auth_encry_struct  auth_encry_supported[ WNDRV_PMKID_CACHE_NUM ];
} wndrv_supc_param_capability_struct;


typedef struct wndrv_supc_bss_info_struct
{    
  kal_uint8                        bssid[ WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
  kal_uint8                        privacy;                        /* WEP encryption requirement */
  kal_uint16                       ssid_len;
  kal_uint8                        ssid [ WNDRV_SSID_MAX_LEN ];    
  kal_int32                        rssi;                           /* receive signal, in dBm */
  kal_uint32                       linkQuality;
  wndrv_supc_modulation_type_enum  modulation_type;    
  kal_uint32                       channel_number;    
  wndrv_supc_network_type_enum     network_type;    
  kal_uint8                        max_rate; 
  kal_uint16                       wpa_ie_len;
  kal_uint8                        wpa_ie[ WNDRV_MAX_WPA_IE_LEN ];
  kal_uint16                       rsn_ie_len;
  kal_uint8                        rsn_ie[ WNDRV_MAX_RSN_IE_LEN ];
#ifdef __WAPI_SUPPORT__
  kal_uint16                       wapi_ie_len;
  kal_uint8                        wapi_ie[ WNDRV_MAX_WAPI_IE_LEN ];  
#endif
  /*   Windows:    
  kal_uint32                     ie_length;    
  kal_uint8                      ies[?];*/
  
  /*  Linux:	
  size_t     wpa_ie_len;	
  u8         wpa_ie[SSID_MAX_WPA_IE_LEN];	
  size_t     rsn_ie_len;	
  u8         rsn_ie[SSID_MAX_WPA_IE_LEN];
  int freq; // MHz 	
  int caps; // e.g. privacy 
  int qual; // signal quality 
  int noise; */
  kal_bool                        has_wps_ie;

  kal_uint8                        wps_ie_len;
  kal_uint8                        wps_ie[ELEM_WPS_PROBE_RESP_IE_LEN];

} wndrv_supc_bss_info_struct;


typedef struct
{  
  kal_uint8  bssid[ WNDRV_MAC_ADDRESS_LEN ];  
  kal_bool   preauth_enabled;   
} wndrv_supc_pmkid_candidate_struct;


typedef struct
{    
  kal_int32   rssi;    
  kal_uint32  linkQuality;
  kal_uint8   current_data_rate;    
  kal_int32   transmitted_fragment_count;    
  kal_int32   multicast_transmitted_frame_count;    
  kal_int32   failed_count;    
  kal_int32   retry_count;    
  kal_int32   multiple_retry_count;    
  kal_int32   RTS_success_count;    
  kal_int32   RTS_failure_count;    
  kal_int32   ACK_failure_count;    
  kal_int32   frame_duplicate_count;    
  kal_int32   received_fragment_count;    
  kal_int32   multicast_received_frame_count;    
  kal_int32   FCS_error_count;    
  kal_int32   TKIP_local_MIC_failures;    
  kal_int32   TKIP_remote_MIC_errors;    
  kal_int32   TKIP_ICV_errors;    
  kal_int32   TKIP_counter_measures_invoked;    
  kal_int32   TKIP_replays;    
  kal_int32   CCMP_format_errors;    
  kal_int32   CCMP_replays;    
  kal_int32   CCMP_decrypt_errors;    
  kal_int32   four_way_handshake_failures;
  kal_uint16  ht_current_data_rate;
} wndrv_supc_statistics_struct;

typedef struct
{ 
    kal_uint32   key_index;
    kal_uint32   key_length;
    kal_uint8    key_material[WNDRV_WEP_MAX_LEN];
} wndrv_wep_info_struct;

#ifdef WIFI_BLACKLIST // Kinki change for the blacklist

typedef struct
{
    kal_uint8    bssid[ WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
    kal_bool                     is_reason_code_present;
    kal_uint32                   reason_code;
    kal_bool                     is_status_code_present;
    kal_uint32                   status_code;
}wndrv_supc_bssid_list_struct;

typedef struct
{
    kal_uint8    bssid[ WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
}wndrv_supc_blacklist_struct;
#endif

#endif /* _WNDRV_SUPC_TYPES_H */

