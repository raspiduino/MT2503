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
 * customer_config_account.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for include file of Data account customization parameters. 
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

#ifndef _CUSTOM_CONFIG_ACCOUNT_H
#define _CUSTOM_CONFIG_ACCOUNT_H

#include "mmi_features.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "custom_data_account.h"
/****************************************************************************/
/* Definitions                                                              */
/****************************************************************************/
/* Maximum length of username attribute in Data account profile */
#define CUSTOM_DTCNT_PROF_MAX_USER_LEN (MAX_GPRS_USER_NAME_LEN - 1)
/* Maximum length of password attribute in Data account profile */
#define CUSTOM_DTCNT_PROF_MAX_PW_LEN (MAX_GPRS_PASSWORD_LEN - 1)
/* Maximum length of homepage attribute in Data account profile */
#define CUSTOM_DTCNT_PROF_MAX_HOMEPAGE_LEN (256)
/* Maximum length of proxy ID attribute in Data account profile */
#define CUSTOM_DTCNT_PROF_MAX_PX_ID_LEN (40)
/* Maximum length of proxy name attribute in Data account profile */
#define CUSTOM_DTCNT_PROF_MAX_PX_NAME_LEN (40)
/* Maximum length of profile IP address length in Data account profile */
#define CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN (4)
/* Maximum length of proxy auth ID attribute in Data account profile */
#define CUSTOM_DTCNT_PROF_MAX_PX_AUTH_ID_LEN (40)
/* Maximum length of proxy auth password attribute in Data account profile */
#define CUSTOM_DTCNT_PROF_MAX_PX_AUTH_PW_LEN (40)
/* Maximum length of prvisioning profile NAPID hash length in Data account profile */
#define CUSTOM_DTCNT_NAPID_HASH_LEN (16)
/* Maximum length of prvisioning profile URL hash length in Data account profile */
#define CUSTOM_DTCNT_PROVURL_HASH_LEN (16)
/* Maximum length of proxy domain name length in Data account profile */
#define CUSTOM_DTCNT_MAX_PROXY_URL_LEN (CUSTOM_MAX_PROXY_ADDR_LEN)

/* For CSD type profile */
#define CUSTOM_DATA_ACCOUNT_BEARER_CSD  0x01

/* For GPRS type profile */
#define CUSTOM_DATA_ACCOUNT_BEARER_GPRS 0x02

/****************************************************************************/
/* Typedef                                                                  */
/****************************************************************************/
/* used for CAT2.0 */
enum
{
    CUSTOM_DTCNT_SUPPORT_DOMAIN_NAME_INPUT = CUSTOM_DTCNT_MAX_PROXY_URL_LEN
} ;

/* Data Account profile proxy service type enum */
typedef enum
{
    /*
     * CL-WSP               9200  WAP
     * CO-WSP               9201  WAP
     * CL-SEC-WSP           9202  WAP + Security ON
     * CO-SEC-WSP           9203  WAP + Security ON
     * CO-SEC-WTA           not supported
     * CL-SEC-WTA           not supported
     * OTA-HTTP-TO/PO       80    HTTP
     * OTA-HTTP-TLS-TO/PO   443   HTTP + Security ON
     */
     
    CUSTOM_DTCNT_PROF_PX_SRV_NONE  = 0,    /* Not specified */
    CUSTOM_DTCNT_PROF_PX_SRV_CL_WSP,       /* WSP, Connection less */
    CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,       /* WSP, Connection oriented */
    CUSTOM_DTCNT_PROF_PX_SRV_CL_SEC_WSP,   /* WSP, Connection less, security mode */
    CUSTOM_DTCNT_PROF_PX_SRV_CO_SEC_WSP,   /* WSP, Connection oriented, security mode */
    CUSTOM_DTCNT_PROF_PX_SRV_CL_SEC_WTA,   /* WTA, Connection less, security mode */
    CUSTOM_DTCNT_PROF_PX_SRV_CO_SEC_WTA,   /* WTA, Connection oriented, security mode */
    CUSTOM_DTCNT_PROF_PX_SRV_HTTP,         /* HTTP type */
    CUSTOM_DTCNT_PROF_PX_SRV_HTTP_TLS,     /* HTTP type, enable TLS */
    CUSTOM_DTCNT_PROF_PX_SRV_STARTTLS,     /* STARTTLS type */
    CUSTOM_DTCNT_PROF_PX_SRV_TOTAL
} custom_dtcnt_prof_px_srv_enum;

/* Data Account profile type enum */
typedef enum
{
    CUSTOM_DTCNT_PROF_TYPE_USER_CONF = 0,  /* user configured account */
    CUSTOM_DTCNT_PROF_TYPE_OTA_CONF,       /* OTA configured account */
    CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF,   /* Factory default */
    CUSTOM_DTCNT_PROF_TYPE_SIM_PROF,       /* SIM provisioning account */
    CUSTOM_DTCNT_PROF_TYPE_DM_CONF,        /* DM configured account */
    CUSTOM_DTCNT_PROF_TYPE_TOTAL
} custom_dtcnt_prof_acc_type_enum;

/* Data Account profile sim type enum */
typedef enum
{
    CUSTOM_DTCNT_SIM_TYPE_1 = 1,   /* sim 1 */
    CUSTOM_DTCNT_SIM_TYPE_2,       /* sim 2 */
    CUSTOM_DTCNT_SIM_TYPE_3,       /* sim 3 */
    CUSTOM_DTCNT_SIM_TYPE_4,       /* sim 4 */
    CUSTOM_DTCNT_SIM_TYPE_TOTAL
} custom_dtcnt_sim_type_enum;

/* Data Account GRPS profile authentication type enum */
typedef enum
{
    CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,       /* auth. type : normal */
    CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_SECURE,       /* auth. type : secure */
    CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_TOTAL    
} custom_dtcnt_prof_gprs_auth_type_enum;

/* Data Account CSD profile dial type enum */
typedef enum
{
    CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE,       /* dial type : analogue */
    CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,           /* dial type : ISDN */
    CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_TOTAL    
} custom_dtcnt_prof_csd_dial_type_enum;

/* Data Account CSD profile data rate enum */
typedef enum
{
    CUSTOM_DTCNT_PROF_CSD_RATE_TWO_FOUR,       /* csd data rate : 2400 */
    CUSTOM_DTCNT_PROF_CSD_RATE_FOUR_EIGHT,     /* csd data rate : 4800 */
    CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX,       /* csd data rate : 9600 */
    CUSTOM_DTCNT_PROF_CSD_RATE_FOURTEEN_FOUR,  /* csd data rate : 14400 */
    CUSTOM_DTCNT_PROF_CSD_RATE_AUTO,           /* csd data rate : auto */
    CUSTOM_DTCNT_PROF_CSD_RATE_TOTAL
} custom_dtcnt_prof_csd_rate_enum;

/* this struct is designed for profile authentication info struct settings for GSM/GPRS profiles */
typedef struct
{    
    custom_dtcnt_prof_gprs_auth_type_enum  AuthType;   /* GPRS Authentication Type */
    kal_uint8 UserName[CUSTOM_DTCNT_PROF_MAX_USER_LEN+1];     /* User string of a Data Account (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_USER_LEN) */
    kal_uint8 Passwd[CUSTOM_DTCNT_PROF_MAX_PW_LEN+1];         /* Password for a Data Account (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_PW_LEN) */
} custom_dtcnt_prof_auth_struct;

/* this struct is designed for common profile struct settings for GSM/GPRS profiles */
typedef struct
{
    kal_uint8 acc_id;              /* The account ID */                                           
    kal_uint8 read_only;           /* read only property */
    custom_dtcnt_prof_acc_type_enum acct_type;                /* Account type */
    custom_dtcnt_sim_type_enum sim_info;                      /* SIM1/SIM2 */

    const kal_uint8 *AccountName;    /* ASCII Name of a Data Account (MAX: CUSTOM_DTCNT_PROF_MAX_ACC_NAME_LEN) */    
    kal_uint8 HomePage[CUSTOM_DTCNT_PROF_MAX_HOMEPAGE_LEN+1];       /* Homepage string (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_HOMEPAGE_LEN) */
    custom_dtcnt_prof_auth_struct Auth_info;       /* authentication info */

    kal_uint8 use_proxy;   /* use proxy flag */
    custom_dtcnt_prof_px_srv_enum  px_service;         /* proxy service type */
    kal_uint16 px_port;        /* proxy port */
    kal_uint8 px_addr[CUSTOM_DTCNT_MAX_PROXY_URL_LEN + 1];        /* proxy addr string domain name format */
    kal_uint8 px_authid[CUSTOM_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1];  /* proxy auth. ID string (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_PX_AUTH_ID_LEN) */
    kal_uint8 px_authpw[CUSTOM_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1];  /* proxy auth. PW (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_PX_AUTH_PW_LEN) */

    kal_uint8 StaicIPAddr[CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN];     /* Static IP Address (MAX: CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    kal_uint8 NetMask[CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN];         /* Subnet Mask (MAX: CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    kal_uint8 PrimaryAddr[CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN];     /* Primary DNS IP Address (MAX: CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    kal_uint8 SecondaryAddr[CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN];   /* Secondary DNS IP Address (MAX: CUSTOM_DTCNT_PROF_MAX_IP_ADDR_LEN) */

    kal_uint8 napid_hash_val[CUSTOM_DTCNT_NAPID_HASH_LEN];        /* hash value of napid */
    kal_uint8 provurl_hash_val[CUSTOM_DTCNT_PROVURL_HASH_LEN];    /* hash value of PROVURL */
    
    kal_uint64 AppType;           /* Application Type bit mask */
    const void *user_data;        /* assoicated user_data */
}custom_dtcnt_prof_common_header_struct;


/* this struct is designed for Data accont CSD profile settings for DA APP */
typedef struct
{
    custom_dtcnt_prof_common_header_struct prof_common_header;/* common profile attributes struct */    
    const kal_uint8 *APN;               /* GPRS APN string (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_APN_LEN) */
} custom_dtcnt_prof_gprs_struct;

/* this struct is designed for Data accont CSD profile settings for DA APP */
typedef struct
{
    custom_dtcnt_prof_common_header_struct prof_common_header;/* common profile attributes struct */    
    const kal_uint8 *DialNumber;   /* CSD profile dial number(ASCII) (MAX: SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN) */
    custom_dtcnt_prof_csd_dial_type_enum   DialType;   /* CSD dial type */
    custom_dtcnt_prof_csd_rate_enum        DataRate;   /* CSD data rate */
} custom_dtcnt_prof_csd_struct;

//#if defined(__GPS_TRACK__)
typedef struct
{
    char *APN;               /* GPRS APN string (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_APN_LEN) */
    char *UserName;     /* User string of a Data Account (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_USER_LEN) */
    char *Passwd;         /* Password for a Data Account (ASCII) (MAX: CUSTOM_DTCNT_PROF_MAX_PW_LEN) */
} track_custom_gprs_apn_struct;

typedef struct apn_struct {
   char		*MCC_MNC;
   char		*APN;
   char		*Name;
   char		*Password;
} apn_struct;

//#endif

#endif

