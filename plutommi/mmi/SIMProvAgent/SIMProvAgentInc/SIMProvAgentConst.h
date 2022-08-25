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
 *  SIMProvAgentConst.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SIM Provisioning Agent Header File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_SPA_CONST_H
#define MMI_SPA_CONST_H

#include "MMI_features.h"

#ifdef __SPA_SUPPORT__

#include "SIMProvAgentConfig.h"

/* define constants */
/* Unused byte in EF files */
#define MMI_SPA_UNUSED_BYTE 0xFF

/* EFmmsicp tags */
#define MMI_SPA_TAG_MMICP_MMS_UNKNOWN       0xFF
#define MMI_SPA_TAG_MMICP_MMS_CONN_PARAM    0xAB
#define MMI_SPA_TAG_MMICP_MMS_IMPL          0x80
#define MMI_SPA_TAG_MMICP_MMS_RELAY         0x81
#define MMI_SPA_TAG_MMICP_NETWORK_INFO      0x82
#define MMI_SPA_TAG_MMICP_GATEWAY           0x83

/* EFmmsicp parameters */
#define MMI_SPA_PARAM_NAME                  0x07
#define MMI_SPA_PARAM_BEARER                0x10
#define MMI_SPA_PARAM_NAPADDRESS            0x08
#define MMI_SPA_PARAM_NAPADDRTYPE           0x09
#define MMI_SPA_PARAM_LINKSPEED             0x25
#define MMI_SPA_PARAM_CALLTYPE              0x0A
#define MMI_SPA_PARAM_AUTHTYPE              0x0C
#define MMI_SPA_PARAM_AUTHNAME              0x0D
#define MMI_SPA_PARAM_AUTHSECRET            0x0E
#define MMI_SPA_PARAM_PXADDR                0x20
#define MMI_SPA_PARAM_PXADDRTYPE            0x21
#define MMI_SPA_PARAM_TO_NAPID              0x22
#define MMI_SPA_PARAM_PORTNBR               0x23
#define MMI_SPA_PARAM_PXAUTH_TYPE           0x19
#define MMI_SPA_PARAM_PXAUTH_IDM            0x1A
#define MMI_SPA_PARAM_PXAUTH_PW             0x1B
#define MMI_SPA_PARAM_PROXY_ID              0x15
#define MMI_SPA_PARAM_PROXY_PROVIDE_ID      0x16
#define MMI_SPA_PARAM_SERVICE               0x24

/* EFmmsicp values */
#define MMI_SPA_VALUE_BEARER_GSM_USSD                           0xA2
#define MMI_SPA_VALUE_BEARER_GSM_SMS                            0xA3
#define MMI_SPA_VALUE_BEARER_ANSI_136_GUTS                      0xA4
#define MMI_SPA_VALUE_BEARER_IS_95_CDMA_SMS                     0xA5
#define MMI_SPA_VALUE_BEARER_IS_95_CDMA_CSD                     0xA6
#define MMI_SPA_VALUE_BEARER_IS_95_CDMA_PACKET                  0xA7
#define MMI_SPA_VALUE_BEARER_ANSI_136_CSD                       0xA8
#define MMI_SPA_VALUE_BEARER_ANSI_136_GPRS                      0xA9
#define MMI_SPA_VALUE_BEARER_GSM_CSD                            0xAA
#define MMI_SPA_VALUE_BEARER_GSM_GPRS                           0xAB
#define MMI_SPA_VALUE_BEARER_AMPS_CDPD                          0xAC
#define MMI_SPA_VALUE_BEARER_PDC_CSD                            0xAD
#define MMI_SPA_VALUE_BEARER_PDC_PACKET                         0xAE
#define MMI_SPA_VALUE_BEARER_IDEN_SMS                           0xAF
#define MMI_SPA_VALUE_BEARER_IDEN_CSD                           0xB0
#define MMI_SPA_VALUE_BEARER_IDEN_PACKET                        0xB1
#define MMI_SPA_VALUE_BEARER_FLEX_REFLEX                        0xB2
#define MMI_SPA_VALUE_BEARER_PHS_SMS                            0xB3
#define MMI_SPA_VALUE_BEARER_PHS_CSD                            0xB4
#define MMI_SPA_VALUE_BEARER_TETRA_SDS                          0xB5
#define MMI_SPA_VALUE_BEARER_TETRA_PACKET                       0xB6
#define MMI_SPA_VALUE_BEARER_ANSI_136_GHOST                     0xB7
#define MMI_SPA_VALUE_BEARER_MOBITEX_MPAK                       0xB8
#define MMI_SPA_VALUE_BEARER_CDMA2000_1X_SIMPLE_IP              0xB9
#define MMI_SPA_VALUE_BEARER_CDMA2000_1X_MOBILE_IP              0xBA
#define MMI_SPA_VALUE_ADDTYPE_IPV4                              0x85
#define MMI_SPA_VALUE_ADDTYPE_IPV6                              0x86
#define MMI_SPA_VALUE_ADDTYPE_E164                              0x87
#define MMI_SPA_VALUE_ADDTYPE_ALPHA                             0x88
#define MMI_SPA_VALUE_ADDTYPE_APN                               0x89
#define MMI_SPA_VALUE_ADDTYPE_SCODE                             0x8A
#define MMI_SPA_VALUE_ADDTYPE_TETRA_ITSI                        0x8B
#define MMI_SPA_VALUE_ADDTYPE_MAN                               0x8C

#define MMI_SPA_VALUE_SPEED_AUTOBAUDING                         0xC5
#define MMI_SPA_VALUE_CALLTYPE_ANALOG_MODEM                     0x90
#define MMI_SPA_VALUE_CALLTYPE_V120                             0x91
#define MMI_SPA_VALUE_CALLTYPE_V110                             0x92
#define MMI_SPA_VALUE_CALLTYPE_X31                              0x93
#define MMI_SPA_VALUE_CALLTYPE_BIT_TRANSPARENT                  0x94
#define MMI_SPA_VALUE_CALLTYPE_DIRECT_ASYNCHRONOUS_DATA_SERVICE 0x95

#define MMI_SPA_VALUE_AUTHTYPE_PAP                              0x9A
#define MMI_SPA_VALUE_AUTHTYPE_CHAP                             0x9B
#define MMI_SPA_VALUE_AUTHTYPE_HTTP_BASIC                       0x9C
#define MMI_SPA_VALUE_AUTHTYPE_HTTP_DIGEST                      0x9D
#define MMI_SPA_VALUE_AUTHTYPE_WTLS_SS                          0x9E
#define MMI_SPA_VALUE_AUTHTYPE_MD5                              0x9F
#define MMI_SPA_VALUE_SERVICE_CL_WSP                            0xCA
#define MMI_SPA_VALUE_SERVICE_CO_WSP                            0xCB
#define MMI_SPA_VALUE_SERVICE_CL_SEC_WSP                        0xCC
#define MMI_SPA_VALUE_SERVICE_CO_SEC_WSP                        0xCD
#define MMI_SPA_VALUE_SERVICE_CL_SEC_WTA                        0xCE
#define MMI_SPA_VALUE_SERVICE_CO_SEC_WTA                        0xCF
#define MMI_SPA_VALUE_SERVICE_OTA_HTTP_TO                       0xD0
#define MMI_SPA_VALUE_SERVICE_OTA_HTTP_TLS_TO                   0xD1
#define MMI_SPA_VALUE_SERVICE_OTA_HTTP_PO                       0xD2
#define MMI_SPA_VALUE_SERVICE_OTA_HTTP_TLS_PO                   0xD3

/* MMS App id */
#define MMI_SPA_VALUE_APP_ID_MMS          "w4"
/* The max value of single byte encoded length */
#define MMI_SPA_VALUE_MAX_ONE_BYTE_LEN    127
/* If EF table is empty? */
#define MMI_SPA_EMPTY_EF_TABLE_SIZE       1

/* Bit mask flag for SIM status */
/*
 * Get by check_sim_status
 * App need to check if to activate the first SIM profile
 * Send to CCA
 */
#define MMI_SPA_FLAG_SIM1_CHANGED   0x0001
#define MMI_SPA_FLAG_SIM2_CHANGED   0x0002

/*
 * Judged by setting mode and sim status info, 
 * App need to check if to show the SIM profile
 * Send to CCA
 */
#define MMI_SPA_FLAG_SIM1_SHOW      0x0004
#define MMI_SPA_FLAG_SIM2_SHOW      0x0008

/* used to check whether need to read SIM file */
#define MMI_SPA_FLAG_SIM1_READ      0x0010
#define MMI_SPA_FLAG_SIM2_READ      0x0020

/*
 * Co-work with read flag
 * If read fail, check whether retry next time
 */
#define MMI_SPA_FLAG_SIM1_READ_FAIL 0x0040
#define MMI_SPA_FLAG_SIM2_READ_FAIL 0x0080

/* SIM can read? */
#define MMI_SPA_FLAG_SIM1_CAN_READ  0x0100
#define MMI_SPA_FLAG_SIM2_CAN_READ  0x0200

/* EF processed flag */
#define MMI_SPA_FLAG_EF_MMSICP_PROCESSED    0x0001

/* For NVRAM storage */
#define MMI_SPA_FLAG_SIM1_INSERT_NOT_INSERT     0x0001
#define MMI_SPA_FLAG_SIM1_INSERT_BLOCK          0x0002
#define MMI_SPA_FLAG_SIM1_INSERT_OK             0x0004
#define MMI_SPA_FLAG_SIM1_CHANGE_NO_IMSI        0x0008
#define MMI_SPA_FLAG_SIM1_CHANGE_NOT_CHANGED    0x0010
#define MMI_SPA_FLAG_SIM1_CHANGE_CHANGED        0x0020
#define MMI_SPA_FLAG_SIM2_INSERT_NOT_INSERT     0x0040
#define MMI_SPA_FLAG_SIM2_INSERT_BLOCK          0x0080
#define MMI_SPA_FLAG_SIM2_INSERT_OK             0x0100
#define MMI_SPA_FLAG_SIM2_CHANGE_NO_IMSI        0x0200
#define MMI_SPA_FLAG_SIM2_CHANGE_NOT_CHANGED    0x0400
#define MMI_SPA_FLAG_SIM2_CHANGE_CHANGED        0x0800
#define MMI_SPA_FLAG_LAST_SIM1_STATUS_OK        0x1000
#define MMI_SPA_FLAG_LAST_SIM2_STATUS_OK        0x2000

#define MMI_SPA_MASK_SIM1_FLAGS                 0x003F
#define MMI_SPA_MASK_SIM2_FLAGS                 0x0FC0

/* ENUMs */
typedef enum
{
    MMI_SPA_PROCESS_STATE_IDLE = 0,
    MMI_SPA_PROCESS_STATE_WAIT_NEW_SETTING_RSP,
    MMI_SPA_PROCESS_STATE_WAIT_SIM2_NEW_SETTING_RSP,
    MMI_SPA_PROCESS_STATE_WAIT_NEW_DOC_RSP,
    MMI_SPA_PROCESS_STATE_MAX_ITEM
} mmi_spa_process_state_enum;

typedef enum
{
    MMI_SPA_EF_PARSER_STATE_IDLE = 0,
    MMI_SPA_EF_PARSER_STATE_PARSING,
    MMI_SPA_EF_PARSER_STATE_MAX_ITEM
} mmi_spa_ef_parser_state_enum;

typedef enum
{
    MMI_SPA_EF_TYPE_TRANSPARENT = 0,
    MMI_SPA_EF_TYPE_LINEAR_FIXED,
    MMI_SPA_EF_TYPE_CYLIC,
    MMI_SPA_EF_TYPE_MAX_ITEM
} mmi_spa_ef_type_enum;

typedef enum
{
    MMI_SPA_CHECK_EF_STATUS_RESULT_ACTIVATED = 0,
    MMI_SPA_CHECK_EF_STATUS_RESULT_INACTIVATED,
    /* MMI_SPA_CHECK_EF_STATUS_RESULT_SIM_NOMATCH, */
    MMI_SPA_CHECK_EF_STATUS_RESULT_MAX_ITEM
} mmi_spa_check_ef_status_result_enum;

typedef enum
{
    /* General results */
    MMI_SPA_RESULT_OK = 0,
    MMI_SPA_RESULT_FAIL,    /* Fatal error, can't continue process */

    /* Handle results */
    MMI_SPA_RESULT_NOT_ALL_PROCESSED,   /* A success result, need read again next time. */
    MMI_SPA_RESULT_NO_ACTIVATED_EF,     /* No activated EF in SIM */
    MMI_SPA_RESULT_MEM_FULL,            /* SPA alloc fail */
    MMI_SPA_RESULT_FAIL_IN_FINALIZE,

    /* Read EF results */
    MMI_SPA_RESULT_TEMP_FAIL,                       /* EF can't read temporarily, should retry */
    MMI_SPA_RESULT_IGNORE_THIS_FILE,                /* EF is not accessed, no retr needed */
    MMI_SPA_RESULT_SIM_BUSY,                        /* SIM access module busy, assert now */
    MMI_SPA_RESULT_SIM_FILE_ACCESS_ERROR_STATUS,    /* Error status while reading, assert now */
    MMI_SPA_RESULT_EMPTY_EF,

    /* Parse results */
    MMI_SPA_RESULT_PARSE_ERROR,
    MMI_SPA_RESULT_PARSE_ERROR_LENGTH,  /* Get tag length fail, abort parsing this EF */
    MMI_SPA_RESULT_PARSE_ERROR_PARAM,   /* Parse error param to parser function */
    MMI_SPA_RESULT_PARSE_INVALID_DATA,
    MMI_SPA_RESULT_PARSE_CCA_ERROR,     /* Call CCA interface return fail */
    MMI_SPA_RESULT_PARSE_CCA_MEM_FULL,  /* CCA mem full, need retry */
    MMI_SPA_RESULT_PARSE_EMPTY_ROOT,    /* Empty root, need retry */
    MMI_SPA_RESULT_PARSE_UNSUPPORT_PARAM,

    /* ProvBox results */
    MMI_SPA_RESULT_PROVBOX_OP_CANCELLED,
    MMI_SPA_RESULT_PROVBOX_UNSUPPORTED_SETTING,
    MMI_SPA_RESULT_PROVBOX_READ_BOX_FILE_FAIL,
    MMI_SPA_RESULT_PROVBOX_EMPTY_BOX_FILE,
    MMI_SPA_RESULT_PROVBOX_INVALID_MSG_DATA,

    MMI_SPA_RESULT_MSG_HANDLED,
    MMI_SPA_RESULT_MSG_NOT_HANDLED,
    //MMI_SPA_RESULT_PARSE_UNSUPPORTED_MMS_VER,
    //MMI_SPA_RESULT_GET_FILE_INFO_FAIL,
    //MMI_SPA_RESULT_READ_FILE_FAIL,
    //MMI_SPA_RESULT_ABORT,
    //MMI_SPA_RESULT_SIM_ACCESS_OK = 0, /* SIM Access callbacks use 0 as success*/
    MMI_SPA_RESULT_MAX_ITEM
} mmi_spa_result_enum;

typedef enum
{
    MMI_SPA_CONVERT_TYPE_INT = 0,
    MMI_SPA_CONVERT_TYPE_STR,
    MMI_SPA_CONVERT_TYPE_ENUM,
    MMI_SPA_CONVERT_TYPE_MAX_ITEM
} mmi_spa_convt_type_enum;

typedef enum
{
    MMI_SPA_EF_READ_STATE_IDLE = 0,
    MMI_SPA_EF_READ_STATE_GETTING_INFO,
    MMI_SPA_EF_READ_STATE_READING,
    MMI_SPA_EF_READ_STATE_MAX_ITEM
} mmi_spa_ef_read_state_enum;

typedef enum
{
    MMI_SPA_SIM_NEED_READ_STATE_NONE = 0,
    MMI_SPA_SIM_NEED_READ_STATE_ONE,
    MMI_SPA_SIM_NEED_READ_STATE_DUAL,
    MMI_SPA_SIM_NEED_READ_STATE_MAX_ITEM
} mmi_spa_sim_need_read_state_enum;

typedef enum
{
    MMI_SPA_SIM_CHANGED_STATUS_NOT_INSERT = 0,
    MMI_SPA_SIM_CHANGED_STATUS_INSERT_BLOCKED,
    MMI_SPA_SIM_CHANGED_STATUS_INSERT_NO_IMSI,
    MMI_SPA_SIM_CHANGED_STATUS_INSERT_NORMAL,
    MMI_SPA_SIM_CHANGED_STATUS_NOT_CHANGED,
    MMI_SPA_SIM_CHANGED_STATUS_CHANGED,
    MMI_SPA_SIM_CHANGED_STATUS_MAX_ITEM
} mmi_spa_sim_changed_status;

/* temp here */
/*
 * typedef enum
 * {
 * MMI_SPA_SIM_STATE_DEFAULT = 0,
 * MMI_SPA_SIM_STATE_SIM1,
 * MMI_SPA_SIM_STATE_SIM2,
 * MMI_SPA_SIM_STATE_MAX_ITEM
 * }mmi_spa_sim_state_enum;
 */

#ifdef MMI_SPA_JOB_SUPPORT

typedef enum
{
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    MMI_SPA_JOB_TYPE_SAVE_TO_BOX = 0,
#endif 
    MMI_SPA_JOB_TYPE_INSTALL_SIM_PROFILE,
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    MMI_SPA_JOB_TYPE_INSTALL_BOX_PROFILE,
#endif 
    MMI_SPA_JOB_TYPE_MAX_ITEM
} mmi_spa_job_type_enum;

typedef enum
{
    MMI_SPA_JOB_STATE_IDLE = 0,
    MMI_SPA_JOB_STATE_WATING_NEW_SETTING_RSP,
    MMI_SPA_JOB_STATE_WATING_NEW_DOC_RSP,
    MMI_SPA_JOB_STATE_READING_EF,
    MMI_SPA_JOB_STATE_SAVING_MSG_DATA,
    MMI_SPA_JOB_STATE_GETTING_MSG_DATA,
    MMI_SPA_JOB_STATE_INSTALLING,
    MMI_SPA_JOB_STATE_UPDATING_BOX_INFO,
    MMI_SPA_JOB_STATE_CANCELLING,
    MMI_SPA_JOB_STATE_MAX_ITEM
} mmi_spa_job_state_enum;

/* For ef_processed_flag in ef info table */
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#define MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_SAVED  0x0001
#define MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_SAVED  0x0002
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
#define MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_INSTALLED  0x0004
#define MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_INSTALLED  0x0008
#define MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM1_PROCESSED_COUNT_MASK   0x30
#define MMI_SPA_FLAG_EF_PROCESSED_STATE_SIM2_PROCESSED_COUNT_MASK   0xC0

/* For ef_job_state_flag in ef info table */
#define MMI_SPA_FLAG_EF_JOB_STATE_SIM1_INSTALLING   0x0001
#define MMI_SPA_FLAG_EF_JOB_STATE_SIM2_INSTALLING   0x0004
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#define MMI_SPA_FLAG_EF_JOB_STATE_SIM1_SAVING       0x0002
#define MMI_SPA_FLAG_EF_JOB_STATE_SIM2_SAVING       0x0008
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

/* SIM EF saved flag, used to store state in NVRAM */
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#define MMI_SPA_FLAG_SIM1_MMSICP_SAVED_FLAG  0x0001
#define MMI_SPA_FLAG_SIM2_MMSICP_SAVED_FLAG  0x0002
#define MMI_SPA_FLAG_ALL_SIM1_SAVED_FLAGS   (MMI_SPA_FLAG_SIM1_MMSICP_SAVED_FLAG)
#define MMI_SPA_FLAG_ALL_SIM2_SAVED_FLAGS   (MMI_SPA_FLAG_SIM2_MMSICP_SAVED_FLAG)
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

// #define MMI_SPA_NVRAM_FLAG_BUF_LEN           2

#endif /* MMI_SPA_JOB_SUPPORT */ 

typedef enum
{
    MMI_SPA_SIM_TYPE_VALID_SIM = 0,
    MMI_SPA_SIM_TYPE_INVALID_SIM,
    MMI_SPA_SIM_TYPE_BLOCKED_SIM,
    MMI_SPA_SIM_TYPE_UNKNOWN,
    /* MMI_SPA_SIM_TYPE_LOCKED_SIM, */
    MMI_SPA_SIM_TYPE_MAX_ITEM
} mmi_spa_sim_type_enum;

typedef enum
{
    MMI_SPA_SIM_ID_DEFAULT = 0,
    MMI_SPA_SIM_ID_SIM1,
    MMI_SPA_SIM_ID_SIM2,
    MMI_SPA_SIM_ID_DUAL_SIM,
    MMI_SPA_SIM_ID_NO_SIM,
    MMI_SPA_SIM_ID_FLIGHT_MODE,
    MMI_SPA_SIM_ID_MAX_ITEM
} mmi_spa_sim_id_enum;

#endif /* __SPA_SUPPORT__ */ 
#endif /* MMI_SPA_CONST_H */ 

