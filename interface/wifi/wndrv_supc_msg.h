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
 *  wndrv_supc_msg.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Message struct prototypes exported by WLAN network driver
 *  These messages are used between WNDRV and SUPC Tasks
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#ifndef _WNDRV_SUPC_MSG_H
#define _WNDRV_SUPC_MSG_H

#include "wndrv_supc_types.h"
//#include "kal_non_specific_general_types.h"
#include "wndrv_cnst.h"
#include "kal_general_types.h"

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_data_req_struct
*
*  DESCRIPTION
*     Request data transmission.
***************************************************************************/
typedef struct
{
   kal_uint8	ref_count;
   kal_uint16	msg_len;
   kal_uint8	src_mac_addr[ WNDRV_MAC_ADDRESS_LEN ];
   kal_uint8	dest_mac_addr[ WNDRV_MAC_ADDRESS_LEN ];
   kal_uint16	proto_type;
} wndrv_supc_data_req_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_data_ind_struct
*
*  DESCRIPTION
*     Indicate data received.
***************************************************************************/
typedef struct
{
   kal_uint8	ref_count;
   kal_uint16	msg_len;
   kal_uint8	src_mac_addr[ WNDRV_MAC_ADDRESS_LEN ];
   kal_uint8	dest_mac_addr[ WNDRV_MAC_ADDRESS_LEN ];
   kal_uint16	proto_type;
} wndrv_supc_data_ind_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_init_cnf_struct
*
*  DESCRIPTION
*     After network driver initiates itself, it sends this message to upper layer.
***************************************************************************/
typedef struct
{
   kal_uint8                           ref_count;
   kal_uint16                          msg_len;
   wndrv_supc_param_capability_struct  capability;
   kal_uint8                           mac_addr[ WNDRV_MAC_ADDRESS_LEN ]; /* Our MAC address */
} wndrv_supc_init_cnf_struct;

#define ATTR_MAX_MANUFACTORY_NAME_LEN  64
#define ATTR_MAX_DEV_NAME_LEN   32
#define ATTR_MAX_MODEL_NAME_LEN  32
#define ATTR_MAX_MODEL_NUM_LEN   32

/**********************************************************************
* WFA's VENDOR IE in probe
*
***********************************************************************/

typedef struct 
{
    kal_uint8                   wps_ver;
    kal_int8                    req_type;
    kal_uint16                  cfg_method;
    kal_uint8                   uuid[16];
    kal_uint16                  categ;
    kal_uint32                  oui;
    kal_uint16                  sub_cate;
    kal_uint8                   rf_bands;
    kal_uint16                  assoc_stat;
    kal_uint16                  cfg_err;
    kal_uint16                  dev_pswd_id;
    /*for wps 2.0*/
    kal_char                    manufact[ATTR_MAX_MANUFACTORY_NAME_LEN];
    kal_uint8                   manuf_len;
    kal_char                    model_name[ATTR_MAX_MODEL_NAME_LEN];
    kal_uint8                   model_name_len;
    kal_char                    model_num[ATTR_MAX_MODEL_NUM_LEN];
    kal_uint8                   model_num_len;
    kal_char                    dev_name[ATTR_MAX_DEV_NAME_LEN];
    kal_uint8                   dev_name_len;
    kal_uint8                   version2;
} wndrv_supc_wps_probe_ie;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_site_survey_req_struct
*
*  DESCRIPTION
*     explicit scan.
***************************************************************************/
typedef struct
{
   kal_uint8	               ref_count;
   kal_uint16	               msg_len;
   kal_uint16                  ssid_len;
   kal_uint8                   ssid[WNDRV_SSID_MAX_LEN];
   kal_bool                    has_wps_ie;

   wndrv_supc_wps_probe_ie     vendor_ie;

} wndrv_supc_site_survey_req_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_site_survey_ind_struct
*
*  DESCRIPTION
*     Sent due to explicit scan.
***************************************************************************/
typedef struct
{
   kal_uint8	               ref_count;
   kal_uint16	               msg_len;
   kal_uint32                  num;       /* Could be zero. */
   kal_uint8                   more_flag;
   wndrv_supc_bss_info_struct  bss_info[ WNDRV_SCAN_RESULTS_NUM ];
} wndrv_supc_site_survey_ind_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_join_network_req_struct
*
*  DESCRIPTION
*     Assign network type (infrastructure or IBSS mode), authentication mode, 
*     encryption mode and SSID to associate a network.
***************************************************************************/
typedef struct
{
   kal_uint8	                      ref_count;
   kal_uint16	                      msg_len;
   
   kal_uint32                         session_id;
   /* Configure the network driver for operating within infrastructure or 
      ad hoc networks. */   
   wndrv_supc_network_type_enum       network_type;
   
   /* To set channel number used in IBSS mode.That means this field is 
      useful when network_type is WNDRV_SUPC_NETWORK_IBSS. */
   kal_uint32                         channel_number;
    
   wndrv_supc_auth_mode_enum          auth_mode;
   wndrv_supc_encryption_status_enum  encryption;
   
   /* Specify which key is enable and set the pre-share keys. */   
   kal_uint8                          key_enable;
   wndrv_wep_info_struct              wep_info[4];
   
   /* Set the SSID (Service Set Identifier) of the network that the network 
      driver associates with. */
      
   kal_uint16                         ssid_len;
   kal_uint8                          ssid[ WNDRV_SSID_MAX_LEN ];
   kal_bool                           has_wps_ie;

   kal_uint8                          wps_version;

} wndrv_supc_join_network_req_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_network_connect_ind_struct
*
*  DESCRIPTION
*     After the upper layer calls WNDRV_SUPC_NETWORK_CONNECT_REQ (specify SSID 
*     to be associated), this message just could be generated.
*     This message is sent when MS associates or reassociates (roaming to 
*     another AP) with a BSS.
***************************************************************************/
typedef struct
{
   kal_uint8	               ref_count;
   kal_uint16	               msg_len;
   kal_uint32                  session_id;
   wndrv_supc_bss_info_struct  bss_info;
   kal_uint16                  assoc_ie_len;
   kal_uint8                   assoc_ie[ WNDRV_MAX_ASSOC_IE_LEN ];
#ifdef WIFI_BLACKLIST // Kinki change for the blacklist
   kal_uint32                   bssid_list_num;
   wndrv_supc_bssid_list_struct  bssid_list[WNDRV_BSSID_MAX_NUM];
#endif
   
} wndrv_supc_network_connect_ind_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_network_connect_fail_ind_struct
*
*  DESCRIPTION
*     This message is sent when MS fails to associate 
*     or reassociate (roaming to another AP) with a BSS.
***************************************************************************/
typedef struct
{
   kal_uint8	               ref_count;
   kal_uint16	               msg_len;
   kal_uint32                  session_id;
#ifdef WIFI_BLACKLIST // Kinki change for the blacklist
   kal_uint32                   bssid_list_num;
   wndrv_supc_bssid_list_struct  bssid_list[WNDRV_BSSID_MAX_NUM];
#endif
} wndrv_supc_network_connect_fail_ind_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_network_disconnect_ind_struct
*
*  DESCRIPTION
*     Lost of coverage of a BSS, this message will be sent to upper layer.
***************************************************************************/
typedef struct
{
   kal_uint8	               ref_count;
   kal_uint16	               msg_len;
   kal_uint32                  session_id;
#ifdef WIFI_BLACKLIST // Kinki change for the blacklist
   kal_uint32                   bssid_list_num;
   wndrv_supc_bssid_list_struct  bssid_list[WNDRV_BSSID_MAX_NUM];
#endif
} wndrv_supc_network_disconnect_ind_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_network_statistics_ind_struct
*
*  DESCRIPTION
*     This message is periodically sent to upper layer. Let it know the receive 
*     and transmission statistics of network driver.
***************************************************************************/
typedef struct
{
   kal_uint8	                 ref_count;
   kal_uint16	                 msg_len;
   wndrv_supc_statistics_struct  statistics;
} wndrv_supc_network_statistics_ind_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_country_setting_req_struct
*
*  DESCRIPTION
*     This message is used to set the regulation domain.
***************************************************************************/
typedef struct
{
   kal_uint8   ref_count;
   kal_uint16  msg_len;
   kal_uint16  country_code;
} wndrv_supc_country_setting_req_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_remove_key_req_struct
*
*  DESCRIPTION
*     Remove Key.
***************************************************************************/
typedef struct
{
   kal_uint8    ref_count;
   kal_uint16   msg_len;

   /* Remove the key at a specified key index for the current association.
   
      The key index occupies the first 8 bits and ranges from 0 through 255. 
      Bit 31 must be 0.If bit 30 is set to 1, the key is a pairwise key. 
      Otherwise, the key is a group key. If the transmit key is removed for a 
      BSSID, no transmit key exists for the key type for a BSSID, until a 
      transmit key is specified. */      
   kal_uint32   key_index;
   
   kal_uint8    bssid[WNDRV_MAC_ADDRESS_LEN];
} wndrv_supc_remove_key_req_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_add_key_req_struct
*
*  DESCRIPTION
*     This message requests that the network driver set a key to a specified 
*     value. Keys are used for authentication or encryption or both. A key 
*     can be pre-shared (in other words, provided to the device before use).
***************************************************************************/
typedef struct
{
   kal_uint8    ref_count;
   kal_uint16   msg_len;
   kal_uint32   key_index;
   
   /* 5, 13, 16 or 32. 
      The length, in bytes, of the KeyMaterial array. The maximum value is 32. */
   kal_uint32   key_length;
   
   /* The MAC address of the BSSID that the key applies to. The field is set 
      to 0xFFFFFFFFFFFF if the BSSID is unknown. */
   kal_uint8    bssid[ WNDRV_MAC_ADDRESS_LEN ];
   
   /* If bit 29 of KeyIndex is set, KeyRSC contains the initial value of the 
      key's receive sequence counter (RSC). If the encryption cipher requires 
      fewer bytes than KeyRSC supplies, the network driver must use the least 
      significant bytes. For example, if 6 bytes are required, the network 
      driver uses KeyRSC[0-5]. */
   kal_uint32   key_rsc[2];
   kal_uint8    key_material[WNDRV_KEY_MAX_LEN];
#ifdef __WAPI_SUPPORT__
   kal_uint8                  eKeyType; /* 0 ENUM_WPI_PAIRWISE_KEY 1 ENUM_WPI_GROUP_KEY */
   kal_uint8                  eDirection; /* 0 ENUM_WPI_NONE 1 ENUM_WPI_RX 2 ENUM_WPI_TX */
   kal_uint8                  ucKeyID;
   kal_uint8                  aucRsv[3];
   kal_uint8                  aucAddrIndex[12];
   kal_uint32                 u4LenWPIEK;
   kal_uint8                  aucWPIEK[16];
   kal_uint32                 u4LenWPICK;
   kal_uint8                  aucWPICK[16];
   kal_uint8                  aucPN[16];
#endif
} wndrv_supc_add_key_req_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_pmkid_update_req_struct
*
*  DESCRIPTION
*     This message is used to set the list of WPA2 pre-authentication PMKIDs 
*     within the network driver's pairwise master key (PMK) cache.
***************************************************************************/
typedef struct
{
   kal_uint8                      ref_count;
   kal_uint16                     msg_len;
   kal_uint32                     num;
   wndrv_supc_pmkid_param_struct  pmkid_param[ WNDRV_PMKID_CACHE_NUM ];
} wndrv_supc_pmkid_update_req_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_pmkid_candidate_ind_struct
*
*  DESCRIPTION
*     The network driver sends this indication to supply the 802.1X supplicant 
*     with a list of PMKID candidates.
***************************************************************************/
typedef struct
{
   kal_uint8                          ref_count;
   kal_uint16                         msg_len;
   kal_uint32                         num;
   wndrv_supc_pmkid_candidate_struct  list[ WNDRV_PMKID_CACHE_NUM ];
} wndrv_supc_pmkid_candidate_ind_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_status_ind_struct
*
*  DESCRIPTION
*     The network driver send this message to report data integrity errors. It is also
*     used to request pre-authentication for a BSSID before it roams to that BSSID.
***************************************************************************/
typedef struct
{
   kal_uint8    ref_count;
   kal_uint16   msg_len;
   kal_uint8    bssid[ WNDRV_MAC_ADDRESS_LEN ];
   kal_uint32   flags;
} wndrv_supc_status_ind_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_auth_state_update_req_struct
*
*  DESCRIPTION
*     The supplicant sends the message to update the state of authentication
***************************************************************************/
typedef struct
{
   kal_uint8	  ref_count;
   kal_uint16	  msg_len;
   kal_bool      in_progress;
} wndrv_supc_auth_state_update_req_struct;

#ifdef WIFI_BLACKLIST // Kinki change for the blacklist
/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_blacklist_update_req_struct
*
*  DESCRIPTION
*     The supplicant sends the message to update the blacklist
***************************************************************************/
typedef struct
{
   kal_uint8	  ref_count;
   kal_uint16	  msg_len;
   kal_uint32     blacklist_num;
   wndrv_supc_blacklist_struct blacklist[WNDRV_BSSID_MAX_NUM];  
} wndrv_supc_blacklist_update_req_struct;
#endif

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_query_capability_req_struct
*
*  DESCRIPTION
*     The supplicant sends the message to query capability

***************************************************************************/
typedef struct
{
    kal_uint8      ref_count;
    kal_uint16     msg_len;
    kal_uint32     challenge[4];
} wndrv_supc_query_capability_req_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_supc_query_capability_ind_struct
*
*  DESCRIPTION
*     The network driver sends this indication to confirm capability

***************************************************************************/
typedef struct
{
    kal_uint8      ref_count;
    kal_uint16     msg_len;
    kal_uint32     response[4];
} wndrv_supc_query_capability_ind_struct;
#endif /* end of _WNDRV_SUPC_MSG_H */
