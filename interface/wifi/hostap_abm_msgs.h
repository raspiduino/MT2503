/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*******************************************************************************
 * Filename:
 * ---------
 *  hostap_abm_msg.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  HOSTAP/ABM Message Structure
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef HOSTAP_ABM_MSG_H
#define HOSTAP_ABM_MSG_H

#define HOSTAP_SSID_MAX_LEN	32
#define HOSTAP_PSK_MIN_LEN	8
#define HOSTAP_PSK_MAX_LEN	63
#define HOSTAP_STA_MAX_NUM	8
#define HOSTAP_SUPP_RATES_MAX 32

#define HOSTAP_NUM_WEP_KEYS 4
#define HOSTAP_MAX_WEP_KEY_LEN 16

typedef enum
{
	HOSTAP_AUTH_ALG_NONE = 0,
	HOSTAP_AUTH_ALG_WEP40,
	HOSTAP_AUTH_ALG_WEP104,
	HOSTAP_AUTH_ALG_WPA_PSK,
	HOSTAP_AUTH_ALG_WPA2_PSK,
	HOSTAP_AUTH_ALG_WPA_WPA2_PSK
} hostap_auth_alg_enum;

typedef struct
{
	/* for WEP40: wep_key[]: 5 ASCII characters, for WEP104: wep_key[]: 13 ASCII characters */
	kal_uint8	wep_key[HOSTAP_NUM_WEP_KEYS][HOSTAP_MAX_WEP_KEY_LEN];
	kal_uint8	wep_key_len[HOSTAP_NUM_WEP_KEYS];
	kal_uint8	wep_tx_keyidx;	/* index of which wep key used */
} hostap_wep_key_struct;

typedef struct
{
	kal_uint8 ssid_len;
	kal_uint8 ssid[ HOSTAP_SSID_MAX_LEN ];
	hostap_auth_alg_enum auth_alg;
	kal_bool fgIsPsk;     /* TRUE: PSK, FALSE: not PSK*/
	kal_uint8 psk_len;
	kal_uint8 psk[ HOSTAP_PSK_MAX_LEN  ];     /* pre-share key (for WPA/WPA2-PSK: psk[]: 8~63 ASCII characters) */
	kal_bool fgIsWep;     /* TRUE: WEP, FALSE: not WEP*/
	hostap_wep_key_struct wep_keys;
	kal_uint8 channel;     /* AP selected channel (if set auto-select: the channel is set to '0') */
	kal_uint8 max_sta_num;  /* Max supported STA num */
} hostap_profile_struct;

typedef struct
{
	kal_uint8	addr[6];
	kal_uint16	aid; /* STA's unique AID (1 .. 2007) or 0 if not yet assigned */
	kal_uint16	capability;
	kal_uint16	listen_interval; /* or beacon_int for APs */
	kal_uint16 	highest_supp_rates;	/* unit of 500kbps */
	kal_uint8	supported_phy;	/* bit0:11a, bit1:11b, bit2:11g, bit3:11n */	
} hostap_sta_info_struct;


/****************************************************************************
 *  AMB -> HOSTAP Indication Message
 ****************************************************************************/

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     hostap_abm_init_req_struct
*
*  DESCRIPTION
*     Request data transmission.
***************************************************************************/
typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   hostap_profile_struct	hostap_config_profile;
} hostap_abm_init_req_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     hostap_abm_deinit_req_struct
*
*  DESCRIPTION
*     Request data transmission.
***************************************************************************/
typedef struct
{
   kal_uint8	ref_count;
   kal_uint16	msg_len;
} hostap_abm_deinit_req_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     hostap_abm_sta_list_req_struct
*
*  DESCRIPTION
*     Request data transmission.
***************************************************************************/
typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;  
} hostap_abm_sta_list_req_struct;


/***************************************************************************
*  HOSTAP -> ABM Indication Message
***************************************************************************/

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     hostap_abm_init_cnf_struct
*
*  DESCRIPTION
*     Request data transmission.
***************************************************************************/
typedef struct
{
   kal_uint8	ref_count;
   kal_uint16	msg_len;
   kal_uint8    status;		/* 1:success  0:failed */
   kal_uint8 	reason;		/* if status==0, reason codes (TBD.) */
   kal_uint8	ap[6];		/* AP MAC addr */
   kal_uint32	mtu;		/* max transmission unit  */
} hostap_abm_init_cnf_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     hostap_abm_deinit_cnf_struct
*
*  DESCRIPTION
*     Request data transmission.
***************************************************************************/
typedef struct
{
   kal_uint8	ref_count;
   kal_uint16	msg_len;
} hostap_abm_deinit_cnf_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     hostap_abm_sta_list_cnf_struct
*
*  DESCRIPTION
*     Request data transmission.
***************************************************************************/
typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   kal_uint8				sta_num;
   hostap_sta_info_struct	sta_info[ HOSTAP_STA_MAX_NUM ];
} hostap_abm_sta_list_cnf_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     hostap_abm_update_sta_list_ind_struct
*
*  DESCRIPTION
*     Update sta list info from hostap to ABM.
***************************************************************************/
typedef struct
{
   kal_uint8				ref_count;
   kal_uint16				msg_len;
   kal_uint8				sta_num;
   hostap_sta_info_struct	sta_info[ HOSTAP_STA_MAX_NUM ];
} hostap_abm_update_sta_list_ind_struct;

#endif /* HOSTAP_ABM_MSG_H */ 
