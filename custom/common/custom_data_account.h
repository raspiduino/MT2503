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
 * customer_data_account.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for include file of PS customization parameters. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_DATA_ACCOUNT_H
#define _CUSTOM_DATA_ACCOUNT_H

#include "kal_general_types.h"
#if defined(__TCPIP__) && defined(__APP_STATIC_QOS_PROFILE_SUPPORT__)
#include "nvram_editor_data_item.h"
#endif
#include "cbm_consts.h"
#include "custom_qos_def.h"
/*******************************************
 * Following are added for PS DATA ACCOUNT 
 *******************************************/

/*************************************************************************
* Constant values
*************************************************************************/
/* DCD profile name and APN */
#ifdef __DCD_SUPPORT__
#define DCD_DEFAULT_APN            "CMWAP"
#define DCD_DEFAULT_NAME           "CHINA MOBILE GPRS"
#endif /* __DCD_SUPPORT__ */

/* PS MAX profile number */
#ifdef __OP01_GPRS_DATACFG__
#define MAX_GPRS_PROFILE_NUM (11)
#else
#ifdef __SLIM_NWK_PROFILE__
#define MAX_GPRS_PROFILE_NUM (5)
#else
#define MAX_GPRS_PROFILE_NUM (10)
#endif
#endif

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#define MAX_GPRS_SIM_PROV_NUM    4
#define MAX_GPRS_SIM_PROV_NUM_PER_SIM    1

#else
#define MAX_GPRS_SIM_PROV_NUM    0
#define MAX_GPRS_SIM_PROV_NUM_PER_SIM    0
#endif

/* PS total profile number */
#ifdef __PS_SERVICE__   

#ifdef __GEMINI__
#define GPRS_TOTAL_PROFILE_NUM  (MAX_GPRS_PROFILE_NUM+(MAX_GPRS_SIM_PROV_NUM*2)+1)
#else
#define GPRS_TOTAL_PROFILE_NUM  (MAX_GPRS_PROFILE_NUM+MAX_GPRS_SIM_PROV_NUM+1)
#endif

#else /* __PS_SERVICE__ */
#define GPRS_TOTAL_PROFILE_NUM  (6)
#endif /* !__PS_SERVICE__ */

/* Internal use only. Please do not modify codes below */
#ifdef __WIFI_SUPPORT__
#define MAX_WIFI_PROFILE_NUM    1
#else
#define MAX_WIFI_PROFILE_NUM    0
#endif

#ifdef __OP01_GPRS_DATACFG__
#define MAX_OP01_PS_PROFILE_NUM   1
#else
#define MAX_OP01_PS_PROFILE_NUM   0
#endif

#ifdef __SATCE__
#define MAX_SATCE_PROFILE_NUM   2
#else
#define MAX_SATCE_PROFILE_NUM   0
#endif

#ifdef __DCD_SUPPORT__
#define MAX_DCD_PROFILE_NUM 1
#else
#define MAX_DCD_PROFILE_NUM 0
#endif

#ifdef __EXT_MODEM__
/* under construction !*/
#else
#define MAX_EXT_MODEM_PROFILE_NUM   0
#endif
/* Internal use only. Please do not modify codes above */

/*************************************************************************
* Enums
*************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*************************************************************************
* Extern
*************************************************************************/
/* get DCD APN and profile name */
#ifdef __DCD_SUPPORT__
extern void custom_get_dcd_default_apn_and_name(kal_uint8 *apn, kal_uint32 max_apn_len, 
                                                kal_uint8 *name, kal_uint32 max_name_len, 
                                                kal_uint32 *apn_len, kal_uint32 *name_len);
#endif /* __DCD_SUPPORT__ */

/* get the G+C profile id */
extern kal_uint8 custom_get_ext_modem_profile_id(void);
/* get loopback account id */
extern kal_uint8 custom_get_loopback_profile_id(void);
/* get ps qos profile number */
extern kal_uint8 custom_get_ps_qos_profile_num(void);

/* Internal use ABM table */
#if defined(__TCPIP__) && defined(__APP_STATIC_QOS_PROFILE_SUPPORT__)
extern nvram_ef_abm_ps_qos_profile_struct abm_ps_qos_profile[];
#endif

/********************************************
* Following are added for WiFi handover timeout
*********************************************/
#define WLAN_HANDOVER_TIMEOUT      (30)           /* in second(s), for normal, WPA/WPA2 connection */
#define WLAN_HANDOVER_TIMEOUT_WPS  (30)          /* in second(s), for WPS connection */
#define WLAN_HANDOVER_TIMEOUT_WAPI (30)          /* in second(s), for WAPI connection */


/*******************************************
 * Following are added for CSD DATA ACCOUNT 
 *******************************************/

/*************************************************************************
* Constant values
*************************************************************************/
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#define MAX_CSD_SIM_PROV_NUM (4)
#define MAX_CSD_SIM_PROV_NUM_PER_SIM (1)
#else
#define MAX_CSD_SIM_PROV_NUM (0)
#define MAX_CSD_SIM_PROV_NUM_PER_SIM (0)
#endif /*__DTCNT_SIM_PROFILES_SUPPORT__*/

/* Define the max length of proxy*/
#define CUSTOM_MAX_PROXY_ADDR_LEN    (63) 

/*Define the total number of csd data account*/
#define CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM  (10)
/*
 * we only support 10 profiles per bearer due to following reasons
 * 1) max control buffer size is 2K
 * 2) default profile name string only define for 1~10.
 */
#if (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM > 10)
#error currently, we only support 10 CSD profiles for each bearer
#endif

/*************************************************************************
* Extern
*************************************************************************/

/*******************************************
 * Following are added for POC ACCOUNT
 *******************************************/
#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_POC_DTCNT_ID    CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else  
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_POC_DTCNT_ID    (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM + MAX_GPRS_PROFILE_NUM)
#else
#define CUSTOM_DEFAULT_POC_DTCNT_ID     0
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_GPRS_FEATURES__ */

/*******************************************
 * Following are added for DM ACCOUNT
 *******************************************/
#ifdef __OP01_GPRS_DATACFG__
#define CUSTOM_DEFAULT_DM_DTCNT_ID      20
#else  
#ifdef __OP02_GPRS_DATACFG__
#define CUSTOM_DEFAULT_DM_DTCNT_ID      10
#else
#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_DM_DTCNT_ID      CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else
#define CUSTOM_DEFAULT_DM_DTCNT_ID      -1
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __OP02_GPRS_DATACFG__ */
#endif /* __OP01_GPRS_DATACFG__ */

/*******************************************
 * Following are added for SYNCML ACCOUNT
 *******************************************/
#ifdef __OP01_GPRS_DATACFG__
#define CUSTOM_DEFAULT_SYNCML_DTCNT_ID    CBM_DEFAULT_ACCT_ID
#else  
#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_SYNCML_DTCNT_ID    CBM_DEFAULT_ACCT_ID
#else  /* __MMI_GPRS_FEATURES__ */
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_SYNCML_DTCNT_ID    CBM_WIFI_ACCT_ID
#else
#define CUSTOM_DEFAULT_SYNCML_DTCNT_ID    CBM_DEFAULT_ACCT_ID
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_GPRS_FEATURES__ */
#endif
 
/*******************************************
 * Following are added for VOIP ACCOUNT
 *******************************************/
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_VOIP_DTCNT_ID    (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM + MAX_GPRS_PROFILE_NUM)
#else
#define CUSTOM_DEFAULT_VOIP_DTCNT_ID     0
#endif /* __MMI_WLAN_FEATURES__ */

/*******************************************
 * Following are added for IMPS ACCOUNT
 *******************************************/
#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_IMPS_DTCNT_ID    CBM_DEFAULT_ACCT_ID
#else  
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_IMPS_DTCNT_ID    CBM_WIFI_ACCT_ID
#else
#define CUSTOM_DEFAULT_IMPS_DTCNT_ID     0
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_GPRS_FEATURES__ */

/*******************************************
 * Following are added for STREAMING ACCOUNT
 *******************************************/
#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_STREAM_DTCNT_ID    CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else  
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_STREAM_DTCNT_ID    (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM + MAX_GPRS_PROFILE_NUM)
#else
#define CUSTOM_DEFAULT_STREAM_DTCNT_ID     0
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_GPRS_FEATURES__ */

/*******************************************
 * Following are added for WAP PROFILE
 *******************************************/
#ifdef __OP01_GPRS_DATACFG__
#define CUSTOM_DEFAULT_WAP_PROFILE1     	    10
#define CUSTOM_DEFAULT_WAP_PROFILE2     	    11
#define CUSTOM_DEFAULT_WAP_PROFILE3     	    0
#define CUSTOM_DEFAULT_WAP_PROFILE4     	    1
#define CUSTOM_DEFAULT_WAP_PROFILE_EMPTY     	10
#else
#define CUSTOM_DEFAULT_WAP_PROFILE1     	    10
#define CUSTOM_DEFAULT_WAP_PROFILE2     	    11
#define CUSTOM_DEFAULT_WAP_PROFILE3     	    12
#define CUSTOM_DEFAULT_WAP_PROFILE4     	    13
#define CUSTOM_DEFAULT_WAP_PROFILE5     	    14
#define CUSTOM_DEFAULT_WAP_PROFILE6     	    10
#define CUSTOM_DEFAULT_WAP_PROFILE7     	    15
#define CUSTOM_DEFAULT_WAP_PROFILE_EMPTY     	10
#endif

/*******************************************
 * Following are added for MMS PROFILE
 *******************************************/
#ifdef __OP01_GPRS_DATACFG__
#define CUSTOM_DEFAULT_MMS_PROFILE1     	    10
#define CUSTOM_DEFAULT_MMS_PROFILE2     	    11
#define CUSTOM_DEFAULT_MMS_PROFILE3     	    0
#define CUSTOM_DEFAULT_MMS_PROFILE4     	    1
#define CUSTOM_DEFAULT_MMS_PROFILE_EMPTY     	10
#else
#define CUSTOM_DEFAULT_MMS_PROFILE1     	    10
#define CUSTOM_DEFAULT_MMS_PROFILE2     	    11
#define CUSTOM_DEFAULT_MMS_PROFILE3     	    12
#define CUSTOM_DEFAULT_MMS_PROFILE4     	    13
#define CUSTOM_DEFAULT_MMS_PROFILE5     	    14
#define CUSTOM_DEFAULT_MMS_PROFILE6     	    16
#define CUSTOM_DEFAULT_MMS_PROFILE7         	15
#define CUSTOM_DEFAULT_MMS_PROFILE_EMPTY     	10
#endif

/******************************************************
 * Add its APP type for data account registration here
 ******************************************************/
#define DTCNT_APPTYPE_SKIP_CSD          (0x10000000)
#define DTCNT_APPTYPE_NO_PX             (0x20000000)
#define DTCNT_APPTYPE_SPECIFIC_PROFILE  (0x40000000)
#define DTCNT_APPTYPE_SKIP_WIFI         (0x80000000)
#define DTCNT_APPTYPE_NEED_PX           (0x08000000)
#define DTCNT_APPTYPE_NO_SCR            (0x04000000)

typedef enum
{
    DTCNT_APPTYPE_NONE              = 0x0000,
    DTCNT_APPTYPE_DEF               = 0x0001,
    DTCNT_APPTYPE_BRW_WAP           = 0x0002,
    DTCNT_APPTYPE_BRW_HTTP          = 0x0004,
    DTCNT_APPTYPE_MMS               = 0x0008,
    DTCNT_APPTYPE_EMAIL             = 0x0010,
    DTCNT_APPTYPE_IMPS              = 0x0020,
    DTCNT_APPTYPE_DM                = 0x0040,
    DTCNT_APPTYPE_SYNCML            = (0x0080 | DTCNT_APPTYPE_SKIP_CSD),
    DTCNT_APPTYPE_JAVA              = 0x0100,
    DTCNT_APPTYPE_PLAYER            = 0x0200,
    DTCNT_APPTYPE_MRE_WAP           = (0x0400 | DTCNT_APPTYPE_SKIP_CSD),
    DTCNT_APPTYPE_MRE_NET           = (0x0800 | DTCNT_APPTYPE_SKIP_CSD),
    DTCNT_APPTYPE_TETHERING         = 0x1000,
    DTCNT_APPTYPE_WIFI_TETHERING    = 0x2000,
    DTCNT_APPTYPE_USB_TETHERING     = 0x4000,
    DTCNT_APPTYPE_NTP               = (0x8000 | DTCNT_APPTYPE_SKIP_CSD),
    DTCNT_APPTYPE_GPS               = 0x10000,
    DTCNT_APPTYPE_WIDGET            = 0x20000,
    DTCNT_APPTYPE_PUSH              = 0x40000,

    /* APP add its app type here, must below the max number 40 */ 
    DTCNT_APPTYPE_MAX

}dtcnt_apptype_enum;

#endif /* _CUSTOM_DATA_ACCOUNT_H */

