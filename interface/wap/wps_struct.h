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

/*******************************************************************************
 * Filename:
 * ---------
 *   wps_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about WAP sap
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _WPS_STRUCT_H
#define _WPS_STRUCT_H 

#include "kal_general_types.h"

#define WPS_MAX_AUTH_USERNAME_LENGTH	129 /* Max. length of the username for authentication */
#define WPS_MAX_AUTH_PASSWORD_LENGTH	41  /* Max. length of the password for authentication */
#define MAX_WPS_CERTIFICATE_NUM         20  /* max certificate chain length in verify request */
#define WPS_DOMAIN_NAME_PROXY_ADDR_LEN  64

/************************************************************
 * Constants
 ************************************************************/
 
#define WPS_DEFAULT_PRX_PORT            8080
#define WPS_DEFAULT_WSP_CO_PORT         9201
#define WPS_DEFAULT_WSP_CL_PORT         9200
#define WPS_DEFAULT_READ_BUFF_SIZE      512
#define WPS_DEFAULT_FOLDER              "/wps"
#define WPS_PEER_BUF_MAX_SIZE           2000
#define WPS_SEGMENT_MIN_SIZE            128
#define WPS_DEFAULT_DL_BUFF_LEN         512

/************************************************************
 * Macro
 ************************************************************/
 
#define WPS_MAX_REPLY_FILE_PATH_LEN     256
#define WPS_MAX_POST_FILE_PATH_LEN      256
#define WPS_MAX_PUSH_FILE_PATH_LEN      256
#define WPS_MAX_USERNAME_LEN            41
#define WPS_MAX_PASSWORD_LEN            41
#define WPS_MAX_CONTENT_TYPE_LEN        256
#define WPS_COOKIE_HEADER_LEN		256
#define WPS_COOKIE_PORT_NUM              16

#define WPS_DEFAULT_STK_AUTH_OPTIONS    1


/* Connection type constants */

#define WPS_CONN_TYPE_HTTP    1         /* STK_CONNECTION_TYPE_HTTP */
#define WPS_CONN_TYPE_WSP_CL  2         /* STK_CONNECTION_TYPE_WSP_CL */
#define WPS_CONN_TYPE_WSP_CO  3         /* STK_CONNECTION_TYPE_WSP_CO */
#define WPS_CONN_TYPE_TLS     4         /* STK_CONNECTION_TYPE_TLS */


/* HTTP method constants */

#define WPS_HTTP_METHOD_GET     0x40    /* STK_METHOD_GET */
#define WPS_HTTP_METHOD_HEAD    0x42    /* STK_METHOD_HEAD */
#define WPS_HTTP_METHOD_POST    0x60    /* STK_METHOD_POST */
#define WPS_HTTP_METHOD_PUT     0x61    /* STK_METHOD_PUT */
#define WPS_HTTP_METHOD_DELETE  0x43    /* STK_METHOD_DELETE */

#define WPS_HTTP_METHOD_PROPFIND      0X90
#define WPS_HTTP_METHOD_PROPPATCH     0X91
#define  WPS_HTTP_METHOD_MKCOL        0X92
#define WPS_HTTP_METHOD_COPY          0X93
#define WPS_HTTP_METHOD_MOVE          0X94
#define WPS_HTTP_METHOD_LOCK          0X95
#define WPS_HTTP_METHOD_REPORT        0X96
#define WPS_HTTP_METHOD_UNLOCK        0X97


/* WPS Channel Options*/
#define WPS_CHANNEL_OPTION_PERSISTENT_CONNECTION	0x0001


/* HTTP request options */

#if defined(OBIGO_Q05A)
#define WPS_HTTP_OPTION_NO_CACHE                  0x00000001  /* STK_OPTION_NO_CACHE */
#define WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY        0x00000004  /* STK_OPTION_DO_NOT_CACHE_REPLY */
#define WPS_HTTP_OPTION_ALWAYS_CACHE              0x00000008  /* STK_OPTION_ALWAYS_CACHE */
#define WPS_HTTP_OPTION_CACHE_ONLY                0x00000010  /* STK_OPTION_CACHE_ONLY */
#define WPS_HTTP_OPTION_STALE_CACHE               0x00000020  /* STK_OPTION_STALE_CACHE */
#define WPS_HTTP_OPTION_DO_NOT_HANDLE_SERVER_AUTH 0x00008000  /* STK_OPTION_DO_NOT_HANDLE_SERVER_AUTH */
#define WPS_HTTP_OPTION_DO_NOT_HANDLE_PROXY_AUTH  0x00010000  /* STK_OPTION_DO_NOT_HANDLE_PROXY_AUTH */
#define WPS_HTTP_OPTION_DO_NOT_REDIRECT           0x00020000  /* STK_OPTION_DO_NOT_REDIRECT */
#define WPS_HTTP_OPTION_USE_LARGE_PIPE            0x40000000  /* Use large pipe to read reply content. */
#define WPS_HTTP_OPTION_FS_COMMIT                 0x80000000  /* FS_Commit for each file write operation. */
#define WPS_HTTP_OPTION_DO_NOT_ADD_COOKIE         0x00400000  /* No need to add cookie info at WPS level */
#define WPS_HTTP_OPTION_USE_PGDL_DOWNLOAD         0x00800000  /* No need to add cookie info at WPS level */
#else /* OBIGO_Q05A */
#define WPS_HTTP_OPTION_NO_CACHE                  0x00000001  /* STK_OPTION_NO_CACHE */
#define WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY        0x00000002  /* STK_OPTION_DO_NOT_CACHE_REPLY */
#define WPS_HTTP_OPTION_ALWAYS_CACHE              0x00000004  /* STK_OPTION_ALWAYS_CACHE */
#define WPS_HTTP_OPTION_CACHE_ONLY                0x00000008  /* STK_OPTION_CACHE_ONLY */
#define WPS_HTTP_OPTION_STALE_CACHE               0x00000010  /* STK_OPTION_STALE_CACHE */
#define WPS_HTTP_OPTION_DO_NOT_HANDLE_SERVER_AUTH 0x00008000  /* STK_OPTION_DO_NOT_HANDLE_SERVER_AUTH */
#define WPS_HTTP_OPTION_DO_NOT_HANDLE_PROXY_AUTH  0x00010000  /* STK_OPTION_DO_NOT_HANDLE_PROXY_AUTH */
#define WPS_HTTP_OPTION_DO_NOT_REDIRECT           0x00020000  /* STK_OPTION_DO_NOT_REDIRECT */
#define WPS_HTTP_OPTION_DO_NOT_SEND_WWW_AUTH      0x00080000  /* STK_OPTION_DO_NOT_SEND_WWW_AUTH*/
#define WPS_HTTP_OPTION_DO_NOT_SEND_PROXY_AUTH    0x00100000  /* STK_OPTION_DO_NOT_SEND_PROXY_AUTH*/
#define WPS_HTTP_OPTION_USE_LARGE_PIPE            0x40000000  /* Use large pipe to read reply content. */
#define WPS_HTTP_OPTION_FS_COMMIT                 0x80000000  /* FS_Commit for each file write operation. */
#define WPS_HTTP_OPTION_DO_NOT_ADD_COOKIE         0x00400000  /* No need to add cookie info at WPS level */
#define WPS_HTTP_OPTION_USE_PGDL_DOWNLOAD         0x00800000  /* No need to add cookie info at WPS level */
#endif /* OBIGO_Q05A */


/* HTTP authentication constants */

#define WPS_HTTP_AUTH_SERVER                 1  /* STK_AUTH_SERVER */
#define WPS_HTTP_AUTH_PROXY                  2  /* STK_AUTH_PROXY */

#define WPS_HTTP_AUTH_TYPE_BASIC             1
#define WPS_HTTP_AUTH_TYPE_DIGEST            2

/* Clear operation constants */

#define WPS_CLEAR_CACHE_URL_MATCH   1   /* STK_CLEAR_CACHE_URL_MATCH */
#define WPS_CLEAR_CACHE_URL_PREFIX  2   /* STK_CLEAR_CACHE_URL_PREFIX */
#define WPS_CLEAR_CACHE_ALL         3   /* STK_CLEAR_CACHE_ALL */
#define WPS_CLEAR_AUTH_HOST         4   /* STK_CLEAR_AUTH_HOST */
#define WPS_CLEAR_AUTH_PROXY        5   /* STK_CLEAR_AUTH_PROXY */
#define WPS_CLEAR_AUTH_ALL          6   /* STK_CLEAR_AUTH_ALL */
#define WPS_CLEAR_COOKIES_ALL       7   /* STK_CLEAR_COOKIES_ALL */


/* Protocol constants */

#define WPS_PROTOCOL_WSP_CL         1   /* STK_PROTOCOL_WSP_CL */
#define WPS_PROTOCOL_WSP_CL_WTLS    2   /* STK_PROTOCOL_WSP_CL_WTLS */
#define WPS_PROTOCOL_WSP_CO         3   /* STK_PROTOCOL_WSP_CO */
#define WPS_PROTOCOL_WSP_CO_WTLS    4   /* STK_PROTOCOL_WSP_CO_WTLS */
#define WPS_PROTOCOL_HTTP           5   /* STK_PROTOCOL_HTTP */
#define WPS_PROTOCOL_HTTP_TLS       6   /* STK_PROTOCOL_HTTP_TLS */
#define WPS_PROTOCOL_HTTP_SSL       7   /* STK_PROTOCOL_HTTP_SSL */
#define WPS_PROTOCOL_CACHE          8   /* STK_PROTOCOL_CACHE */
#define WPS_PROTOCOL_FILE           9   /* STK_PROTOCOL_FILE */
#define WPS_PROTOCOL_OTHER          10  /* STK_PROTOCOL_OTHER */


/* The WTLS key exchange of cipher suite */

#define WPS_SEC_WTLS_KEY_EXCH_NULL              0   /* WTLS_KEY_EXCH_NULL */
#define WPS_SEC_WTLS_KEY_EXCH_SHARED_SECRET     1   /* WTLS_KEY_EXCH_SHARED_SECRET */
#define WPS_SEC_WTLS_KEY_EXCH_DH_ANON           2   /* WTLS_KEY_EXCH_DH_ANON */
#define WPS_SEC_WTLS_KEY_EXCH_DH_ANON_512       3   /* WTLS_KEY_EXCH_DH_ANON_512 */
#define WPS_SEC_WTLS_KEY_EXCH_DH_ANON_768       4   /* WTLS_KEY_EXCH_DH_ANON_768 */
#define WPS_SEC_WTLS_KEY_EXCH_RSA_ANON          5   /* WTLS_KEY_EXCH_RSA_ANON */
#define WPS_SEC_WTLS_KEY_EXCH_RSA_ANON_512      6   /* WTLS_KEY_EXCH_RSA_ANON_512 */
#define WPS_SEC_WTLS_KEY_EXCH_RSA_ANON_768      7   /* WTLS_KEY_EXCH_RSA_ANON_768 */
#define WPS_SEC_WTLS_KEY_EXCH_RSA               8   /* WTLS_KEY_EXCH_RSA */
#define WPS_SEC_WTLS_KEY_EXCH_RSA_512           9   /* WTLS_KEY_EXCH_RSA_512 */
#define WPS_SEC_WTLS_KEY_EXCH_RSA_768           10  /* WTLS_KEY_EXCH_RSA_768 */
#define WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON         11  /* WTLS_KEY_EXCH_ECDH_ANON */
#define WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON_113     12  /* WTLS_KEY_EXCH_ECDH_ANON_113 */
#define WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON_131     13  /* WTLS_KEY_EXCH_ECDH_ANON_131 */
#define WPS_SEC_WTLS_KEY_EXCH_ECDH_ECDSA        14  /* WTLS_KEY_EXCH_ECDH_ECDSA */

/* The TLS key exchange of cipher suite */

#define WPS_SEC_TLS_KEYEXCH_NULL                 0  /* TLS_KEYEXCH_NULL */
#define WPS_SEC_TLS_KEYEXCH_RSA                  1  /* TLS_KEYEXCH_RSA */
#define WPS_SEC_TLS_KEYEXCH_RSA_EXPORT           2  /* TLS_KEYEXCH_RSA_EXPORT */
#define WPS_SEC_TLS_KEYEXCH_DH_DSS_EXPORT        3  /* TLS_KEYEXCH_DH_DSS_EXPORT */
#define WPS_SEC_TLS_KEYEXCH_DH_DSS               4  /* TLS_KEYEXCH_DH_DSS */
#define WPS_SEC_TLS_KEYEXCH_DH_RSA_EXPORT        5  /* TLS_KEYEXCH_DH_RSA_EXPORT */
#define WPS_SEC_TLS_KEYEXCH_DH_RSA               6  /* TLS_KEYEXCH_DH_RSA */
#define WPS_SEC_TLS_KEYEXCH_DHE_DSS_EXPORT       7  /* TLS_KEYEXCH_DHE_DSS_EXPORT */
#define WPS_SEC_TLS_KEYEXCH_DHE_DSS              8  /* TLS_KEYEXCH_DHE_DSS */
#define WPS_SEC_TLS_KEYEXCH_DHE_RSA_EXPORT       9  /* TLS_KEYEXCH_DHE_RSA_EXPORT */
#define WPS_SEC_TLS_KEYEXCH_DHE_RSA             10  /* TLS_KEYEXCH_DHE_RSA */
#define WPS_SEC_TLS_KEYEXCH_DH_ANON_EXPORT      11  /* TLS_KEYEXCH_DH_ANON_EXPORT */
#define WPS_SEC_TLS_KEYEXCH_DH_ANON             12  /* TLS_KEYEXCH_DH_ANON */

/* The cipher algorithms of cipher suite */

#define WPS_SEC_CIPHER_NULL             0   /* CIPHER_NULL */
#define WPS_SEC_CIPHER_RC5_CBC_40       1   /* CIPHER_RC5_CBC_40 */
#define WPS_SEC_CIPHER_RC5_CBC_56       2   /* CIPHER_RC5_CBC_56 */
#define WPS_SEC_CIPHER_RC5_CBC          3   /* CIPHER_RC5_CBC */
#define WPS_SEC_CIPHER_DES_CBC_40       4   /* CIPHER_DES_CBC_40 */
#define WPS_SEC_CIPHER_DES_CBC          5   /* CIPHER_DES_CBC */
#define WPS_SEC_CIPHER_3DES_CBC_EDE     6   /* CIPHER_3DES_CBC_EDE */
#define WPS_SEC_CIPHER_IDEA_CBC_40      7   /* CIPHER_IDEA_CBC_40 */
#define WPS_SEC_CIPHER_IDEA_CBC_56      8   /* CIPHER_IDEA_CBC_56 */
#define WPS_SEC_CIPHER_IDEA_CBC         9   /* CIPHER_IDEA_CBC */
#define WPS_SEC_CIPHER_RC5_CBC_64      10   /* CIPHER_RC5_CBC_64 */
#define WPS_SEC_CIPHER_IDEA_CBC_64     11   /* CIPHER_IDEA_CBC_64 */
#define WPS_SEC_CIPHER_RC2_CBC_40      20   /* CIPHER_RC2_CBC_40 */
#define WPS_SEC_CIPHER_RC4_40          21   /* CIPHER_RC4_40 */
#define WPS_SEC_CIPHER_RC4_128         22   /* CIPHER_RC4_128 */
#define WPS_SEC_CIPHER_AES_CBC_128     30   /* CIPHER_AES_CBC_128 */

/* The hash algorithms of cipher suite */

#define WPS_SEC_HASH_NULL               0   /* HASH_NULL */
#define WPS_SEC_HASH_MD5                1   /* HASH_MD5 */
#define WPS_SEC_HASH_SHA                2   /* HASH_SHA */
#define WPS_SEC_HASH_MD2                3   /* HASH_MD2 */

#define WPS_SEC_CONNECTION_TYPE_TLS         1   /* SEC_CONNECTION_TYPE_TLS */
#define WPS_SEC_CONNECTION_TYPE_WTLS        2   /* SEC_CONNECTION_TYPE_WTLS */
#define WPS_SEC_CONNECTION_TYPE_SSL         3   /* SEC_CONNECTION_TYPE_WTLS */


#define WPS_SEC_CERT_FORMAT_WTLS              1 /* Certificate Format : WTLS */
#define WPS_SEC_CERT_FORMAT_X509              2 /* Certificate Format : X509 */

#define WPS_SEC_GET_USER_CERT	1       /* cert option for user certs */
#define WPS_SEC_GET_ROOT_CERT	2       /* cert option for root certs */

#define WPS_SEC_CERT_READ_ONLY  0

#define WPS_DLG_ERROR               0 /* SEC error dialog type */
#define WPS_DLG_INFO                1 /* SEC info dialog type */
#define WPS_DLG_ALERT               2 /* SEC alert dialog type */

#define WPS_DLG_OK                  0 /* SEC dialog confirm result : OK */
#define WPS_DLG_CANCEL              1 /* SEC dialog confirm result : Reject or Cancel */

#define WPS_DLG_BUTTON_OK           0 /* SEC dialog with only one button */
#define WPS_DLG_BUTTON_YESNO        1 /* SEC dialog with two buttons */
#define WPS_DLG_POPUP               2 /* SEC dialog with no buttons, Normal popup*/
/* The certificate key extension "key purpose" constants */

#define WPS_SEC_KP_SERVER_AUTH             0x0001   /* KP_SERVER_AUTH */
#define WPS_SEC_KP_CLIENT_AUTH             0x0002   /* KP_CLIENT_AUTH */
#define WPS_SEC_KP_CODE_SIGNING            0x0004   /* KP_CODE_SIGNING */
#define WPS_SEC_KP_EMAIL_PROTECTION        0x0008   /* KP_EMAIL_PROTECTION */
#define WPS_SEC_KP_IPSEC_ENDSYSTEM         0x0010   /* KP_IPSEC_ENDSYSTEM */
#define WPS_SEC_KP_IPSEC_TUNNEL            0x0020   /* KP_IPSEC_TUNNEL */
#define WPS_SEC_KP_IPSEC_USER              0x0040   /* KP_IPSEC_USER */
#define WPS_SEC_KP_TIME_STAMPING           0x0080   /* KP_TIME_STAMPING */
#define WPS_SEC_KP_OCSP_SIGNING            0x0100   /* KP_OCSP_SIGNING */


/**********************************************************************
 * Protocol error cause:
 **********************************************************************/

/* WTLS errors */
#define WPS_CAUSE_WTLS_BAD_RECORD           41  /* STK_ERR_WTLS_BAD_RECORD */
#define WPS_CAUSE_WTLS_HANDSHAKE_FAILURE    42  /* STK_ERR_WTLS_HANDSHAKE_FAILURE */ 
#define WPS_CAUSE_WTLS_TIMED_OUT            43  /* STK_ERR_WTLS_TIMED_OUT */
#define WPS_CAUSE_WTLS_UNSUPPORTED_CERT     44  /* STK_ERR_WTLS_UNSUPPORTED_CERT */
#define WPS_CAUSE_WTLS_UNKNOWN_CA           45  /* STK_ERR_WTLS_UNKNOWN_CA */
#define WPS_CAUSE_WTLS_BAD_CERTIFICATE      46  /* STK_ERR_WTLS_BAD_CERTIFICATE */
#define WPS_CAUSE_WTLS_CERTIFICATE_EXPIRED  47  /* STK_ERR_WTLS_CERTIFICATE_EXPIRED */
#define WPS_CAUSE_WTLS_CRYPTOLIB            48  /* STK_ERR_WTLS_CRYPTOLIB */
#define WPS_CAUSE_WTLS_FATAL_ALERT          49  /* STK_ERR_WTLS_FATAL_ALERT */
#define WPS_CAUSE_WTLS_CRITICAL_ALERT       50  /* STK_ERR_WTLS_CRITICAL_ALERT */
#define WPS_CAUSE_WTLS_TOO_MANY_WARNINGS    51  /* STK_ERR_WTLS_TOO_MANY_WARNINGS */
#define WPS_CAUSE_WTLS_INTERNAL_ERROR       52  /* STK_ERR_WTLS_INTERNAL_ERROR */
#define WPS_CAUSE_WTLS_CANCEL               53  /* STK_ERR_WTLS_CANCEL */

/* TLS errors */
#define WPS_CAUSE_TLS_BAD_RECORD            61  /* STK_ERR_TLS_BAD_RECORD */
#define WPS_CAUSE_TLS_DECRYPTION_FAILED     62  /* STK_ERR_TLS_DECRYPTION_FAILED */
#define WPS_CAUSE_TLS_RECEIVED_ALERT        63  /* STK_ERR_TLS_RECEIVED_ALERT */
#define WPS_CAUSE_TLS_HANDSHAKE_FAILURE     64  /* STK_ERR_TLS_HANDSHAKE_FAILURE */
#define WPS_CAUSE_TLS_UNSUPPORTED_CERT      65  /* STK_ERR_TLS_UNSUPPORTED_CERT */
#define WPS_CAUSE_TLS_UNKNOWN_CA            66  /* STK_ERR_TLS_UNKNOWN_CA */
#define WPS_CAUSE_TLS_BAD_CERTIFICATE       67  /* STK_ERR_TLS_BAD_CERTIFICATE */
#define WPS_CAUSE_TLS_CERTIFICATE_EXPIRED   68  /* STK_ERR_TLS_CERTIFICATE_EXPIRED */
#define WPS_CAUSE_TLS_INTERNAL_ERROR        69  /* STK_ERR_TLS_INTERNAL_ERROR */
#define WPS_CAUSE_TLS_CANCEL                70  /* STK_ERR_TLS_CANCEL */

/* 'Communication' errors */
#define WPS_CAUSE_COMM_NO_RESPONSE          21  /* STK_ERR_COMM_NO_RESPONSE */

#define WPS_HDR_CONTENT_DIGEST_MD5	    "wps-content-digest-md5"


#define WPS_CHARSET_UNKNOWN       0
#define WPS_CHARSET_ASCII         3
#define WPS_CHARSET_ISO_8859_1    4
#define WPS_CHARSET_LATIN_1       4
#define WPS_CHARSET_UCS_2         1000
#define WPS_CHARSET_UTF_16BE      1013
#define WPS_CHARSET_UTF_16LE      1014
#define WPS_CHARSET_UTF_16        1015
#define WPS_CHARSET_UTF_8         106

/*Enlarging the value of this macro from 3 to 7 as requested for SNS feature*/
#define WPS_MAX_MULTIPART_CONTENT_NUM 7

/* This enum is used to indicate the result and error code of a request. */
typedef enum
{
    WPS_OK,                             /* Success */
    WPS_ERROR_UNKNOWN,   	            /* Unknonw error */
    WPS_ERROR_SEND,                     /* Fail to write content */
    WPS_ERROR_INVALID_PARAM,            /* Invalid parameters */
    WPS_ERROR_INVALID_HEADER,           /* Invalid headers */
    WPS_ERROR_INVALID_CHANNEL_ID,       /* Invalid channel ID */
    WPS_ERROR_INVALID_REQUEST_ID,       /* Invalid request ID */
    WPS_ERROR_INVALID_SEQUENCE_NUM,     /* Incorrect sequence number in MSG_ID_WPS_READ_CONTENT_REQ and MSG_ID_WPS_POST_CONTENT_RES */
    WPS_ERROR_INVALID_DEFAULT_PROFILE,  /* Invalid default profile */   
    WPS_ERROR_INACTIVE_CHANNEL,         /* Inactive channel */
    WPS_ERROR_INVALID_CONN_TYPE,        /* Invalid connection type */
    WPS_ERROR_NO_RESOURCE,              /* Resource limitation */
    WPS_ERROR_ACCESS_DENY,              /* Access deny */
    WPS_ERROR_PENDING_REQ_EXIST,        /* Pending request exists */
    WPS_ERROR_FILE_ACCESS,              /* File system operation error */
    WPS_ERROR_REQ_ABORT,                /* Request aborted */
    WPS_ERROR_NOT_FOUND,                /* Not found */
    WPS_ERROR_REQ_MSG_TOO_LARGE,        /* Message header is too large */
    WPS_ERROR_REQ_NOT_SUPPORT,          /* Request is not supported */
    WPS_ERROR_DNS_RESOLVE,              /* DNS error */
    WPS_ERROR_USE_PROXY,                /* Proxy error */
    WPS_ERROR_NOT_READY                 /* WPS is not ready yet */
} wps_result_error_enum;


/* This enum is used to indicate the result and error code of a request. */
typedef enum
{
    WPS_SEC_OK,                                 /* Success */
    WPS_SEC_ERR_INSUFFICIENT_MEMORY,            /* Insufficient resource */
    WPS_SEC_ERR_INVALID_PARAMETER,              /* Invalid parameter */
    WPS_SEC_ERR_CRYPTOLIB_NOT_INITIALISED,      /* Cryptlib not ready*/
    WPS_SEC_ERR_INVALID_KEY,                    /* Invalid key */
    WPS_SEC_ERR_UNKNOWN_CERTIFICATE_TYPE,       /* Unsupported cert type */
    WPS_SEC_ERR_BAD_CERTIFICATE,                /* Bad certificate */
    WPS_SEC_ERR_CERTIFICATE_EXPIRED,            /* Certificate expired */
    WPS_SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE,   /* Can't find root certificate */
    WPS_SEC_ERR_GENERAL_ERROR,                  /* General error */
    WPS_SEC_ERR_NOT_READY                       /* WPS service isn't ready */
} wps_sec_result_error_enum;


/* This enum is used to specify the reply data format in a WSP/HTTP request. */
typedef enum
{
    /* Use peer buffer to convey replied content. */
    WPS_DATA_TYPE_BUFFER,

    /* Store replied content in  specified file path directly with downloading 
       progress indication while this is specified as reply_type of 
       MSG_ID_WPS_HTTP_REQ. */
    WPS_DATA_TYPE_FILE,

    /* Store replied content in specified file path directly without downloading 
       progress indication while this is specified as reply_type of 
       MSG_ID_WPS_HTTP_REQ. */
    WPS_DATA_TYPE_FILE_NO_PROG_IND,

    /* Resume a download previously. WPS will append the content in the file 
       specified in the request. */
    WPS_DATA_TYPE_FILE_RESUME,
    
    
    WPS_DATA_TYPE_MULTIPART,
    
	/*This data type helps application to provide filepath after receiving HTTP response,
	    parse the header and ask from user about file path*/
	WPS_DATA_TYPE_FILE_RECREATE
    
} wps_data_type_enum;


/* This enum is used to indicate the status of downloading replied content while
   the reply data type is file. */
typedef enum
{
    WPS_DL_STATUS_DOWNLOADING,  /* downloading is in progress */
    WPS_DL_STATUS_COMPLETE,     /* complete downloading */
    WPS_DL_STATUS_ABORT         /* downloading is aborted */
} wps_dl_status_enum;


/* This enum is used in wps_pun_var_part() to specifiy the operation. */
typedef enum
{
    /* Pack variable part of a primitive. */
    WPS_PUN_PACK,
    
    /* Unpack variable part of a primitive. */
    WPS_PUN_UNPACK,
    
    /* count the needed buffer length of packed variable part. */
    WPS_PUN_SIZE
} wps_pun_enum;


/* This enum is used for WPS status presentation. */
typedef enum
{
    WPS_READY_STATUS_NULL,  /* WPS is not ready to service */
    WPS_READY_STATUS_OK     /* WPS is ready to service */
} wps_ready_status_enum;

/* This is the local parameter structure for MSG_ID_WPS_SET_CHANNEL_REQ. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_bool use_default;       /* Use default channel or not */
    kal_uint8 conn_type;        /* Connection type */
    kal_uint32 req_id;          /* Request ID */
    kal_uint32 net_id;          /* Network ID */
    kal_uint32 timeout;         /* Timeout value (second) */
    kal_bool use_proxy;         /* Use proxy or not */
    kal_uint8 prx_addr[WPS_DOMAIN_NAME_PROXY_ADDR_LEN];      /* Proxy address in the form of domain name or IP address in the form of string */
    kal_uint16 prx_port;        /* Proxy port number. 0 means default proxy 8080. */
    kal_uint8 username[WPS_MAX_USERNAME_LEN];     /* Username for the proxy. Only ASCII is allowed and NULL terminated. */
    kal_uint8 password[WPS_MAX_PASSWORD_LEN];     /* Password for the proxy. Only ASCII is allowed and NULL terminated. */
    kal_uint8 server_auth_username[WPS_MAX_AUTH_USERNAME_LENGTH];   /* Username for the origin server. Only ASCII is allowed and NULL terminated. */
    kal_uint8 server_auth_password[WPS_MAX_AUTH_PASSWORD_LENGTH];   /* Password for the origin server. Only ASCII is allowed and NULL terminated. */
    kal_uint8 app_id;           /* Data account APP ID */
    kal_uint16 options;
} wps_set_channel_req_struct;

/* This is the peer buffer structure for MSG_ID_WPS_SET_CHANNEL_REQ. */
typedef struct
{
    kal_uint32 static_header_len;   /* The length of static header */
    kal_uint8* static_header;       /* static header */
} wps_set_channel_req_var_struct;

/* This is the local parameter structure for MSG_ID_WPS_SET_CHANNEL_RSP. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;           /* Channel ID */
    kal_uint8 result;               /* Result (wps_result_error_enum) */
    kal_uint32 req_id;              /* Request ID */
} wps_set_channel_rsp_struct;

/* This is the local parameter structure for MSG_ID_WPS_UNSET_CHANNEL_REQ. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;           /* Channel ID */
} wps_unset_channel_req_struct;

/* This is the local parameter structure for MSG_ID_WPS_UNSET_CHANNEL_RSP. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;           /* Channel ID */
    kal_uint8 result;               /* Result (wps_result_error_enum) */
} wps_unset_channel_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;   
    kal_bool use_default;
    kal_uint8 conn_type;
    kal_uint32 net_id;
    kal_uint32 timeout;
    kal_bool use_proxy;
    kal_uint8 prx_addr[WPS_DOMAIN_NAME_PROXY_ADDR_LEN];
    kal_uint16 prx_port;
    kal_uint8 username[WPS_MAX_USERNAME_LEN];
    kal_uint8 password[WPS_MAX_PASSWORD_LEN];
} wps_reconfig_channel_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
} wps_reconfig_channel_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 result;
} wps_release_all_rsp_struct;


typedef struct {
  
  kal_uint32    contentTypelen;     /* The content type length */
  /* These two fields correspond to the following header: *  Content-Type: contentType; charset="charset"  * In case of multipart/form-data, each part has such a header. */
  kal_uint8     contentType[32];

  kal_uint32    namelen;     /* The name length */
  /* These two fields are used in case of multipart/form-data,  * and are then included with each part as follows: *   Content-Disposition: form-data; name="name"; filename="fileName" */
  kal_uint8     name[32];
  kal_uint32    fileNamelen;     /* The fileName name length */
  kal_uint8     fileName[32];/* Its an attribute of Content-Disposition. But not the multipart file name */

  kal_uint32    charset;
  kal_uint32    dataType; /* One of WPS_DATA_TYPE_BUFFER, WPS_DATA_TYPE_FILE etc. */
  kal_uint32    dataLen;  
  kal_uint32    filepathNamelen;     /* The fileName name length */
  kal_wchar 		filepathName[32];/* Absolute multipart filepath along with its name. */

} wps_content_t;

/* This is the local parameter structure for MSG_ID_WPS_HTTP_REQ. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;           /* Channel ID */
    kal_uint16 request_id;          /* Request ID */
    kal_uint8 method;               /* HTTP Method Constant */
    kal_uint32 option;              /* HTTP request options */
    kal_uint8 reply_type;           /* Reply type (wps_data_type_enum) */

    /* The file path used to store replied content when reply_type is specified 
       as WPS_DATA_TYPE_FILE, WPS_DATA_TYPE_FILE_NO_PROG_IND or 
       WPS_DATA_TYPE_FILE_RESUME. */
    kal_wchar reply_path[256];

    /* Max. buffer size that reading side suggests when reply_type is specified 
       as WPS_DATA_TYPE_BUFFER. */
    kal_uint32 reply_segment_len;

    /* Post type (wps_data_type_enum). It is mandatory if method is POST/PUT. */
    kal_uint8 post_type;

    /* The file path to be post when post_type is specified as 
       WPS_DATA_TYPE_FILE. It is mandatory is method is POST/PUT and post_type 
       is WPS_DATA_TYPE_FILE. */
    kal_wchar post_path[256];

    /* The total length of data to be post. It is mandatory is method is 
       POST/PUT and value 0 means unknown. */
    kal_uint32 post_total_len;

    /* A flag to indicate if more post data is needed when post_type is 
       specified as WPS_DATA_TYPE_BUFFER. */
    kal_bool   more_post;
} wps_http_req_struct; 

/* This is the peer buffer structure for MSG_ID_WPS_HTTP_REQ. */
typedef struct
{
    kal_uint32 request_url_len;     /* The request URL length */
    kal_uint8* request_url;         /* The request URL */
    kal_uint32 request_header_len;  /* The request header length */
    kal_uint8* request_header;      /* The request header */

    /* The post segment buffer length when post_type is specified as 
       WPS_DATA_TYPE_BUFFER. It is mandatory is method is POST/PUT and post_type
       is WPS_DATA_TYPE_BUFFER. */
    kal_uint32 post_segment_len;

    /* The post data segment. It is mandatory is method is POST/PUT and 
       post_type is WPS_DATA_TYPE_BUFFER. */
    kal_uint8* post_segment;
    /*To support Posting of multipart data */
    kal_uint32 num_entries; /*no. of multipart entries*/
    wps_content_t content[WPS_MAX_MULTIPART_CONTENT_NUM]; /*application should allocate memory for each wps_content  and fill the info */   

	  
} wps_http_req_var_struct;

/* This is the local parameter structure for MSG_ID_WPS_HTTP_RSP. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint16 request_id;          /* request ID */
    kal_uint8 result;               /* Result (wps_result_error_enum) */
    kal_uint16 status;              /* HTTP response codes */
    kal_int32 cause;                /* Error cause if result is not ok */
    
    /* Network protocol used to retrieve content. Please refer to the Protocol 
       Constants */
    kal_uint8 protocol;

    /* The type of replied content. */
    kal_uint8 content_type[256];

    /* The length of replied content. The Content-Length header is not a
       mandatory header per HTTP specification. It is possible that the content
       length is unknown. Please use the more field to know whether there is
       more data. */
    kal_uint32 content_length;

    /* Indicate if more data is needed to be retrieved. */
    kal_bool more;
} wps_http_rsp_struct; 

/* This is the peer buffer structure for MSG_ID_WPS_HTTP_RSP. */
typedef struct
{
    kal_uint32 new_url_len;         /* The length of new redirected URL */
    kal_uint8* new_url;             /* The new redirected URL */
    kal_uint32 reply_header_len;    /* The length of replied header */
    kal_uint8* reply_header;        /* The replied header */

    /* The reply segment buffer length when reply_type is specified as 
       WPS_DATA_TYPE_BUFFER. It is mandatory when reply_type is 
       WPS_DATA_TYPE_BUFFER. */
    kal_uint32 reply_segment_len;

    /* The reply data segment. It is mandatory when reply_type is 
       WPS_DATA_TYPE_BUFFER. */
    kal_uint8* reply_segment;
} wps_http_rsp_var_struct;

/* This is the local parameter structure for MSG_ID_WPS_READ_CONTENT_REQ. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;           /* Channel ID */
    kal_uint16 request_id;          /* Request ID */
    kal_uint8 seq_num;              /* Sequence number (for debug purpose) */

    /* The suggested segment data length of replied data in the peer buffer of 
       response. 0 means use reply_segment_len in MSG_ID_WPS_HTTP_REQ or 
       read_segment_length in previous request. */
    kal_uint32 read_segnemtn_len;
} wps_read_content_req_struct;

/* This is the local parameter structure for MSG_ID_WPS_READ_CONTENT_RSP. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint16 request_id;          /* Request ID */
    kal_uint8 seq_num;              /* Sequence number (for debug purpose) */
    kal_uint8 result;               /* Result (wps_result_error_enum) */
    
    /* Indicate if more data is needed to be retrieved. */
    kal_bool more;
} wps_read_content_rsp_struct;

/* This is the peer buffer structure for MSG_ID_WPS_READ_CONTENT_RSP. */
typedef struct
{
    kal_uint32 reply_segment_len;   /* The reply segment buffer length */
    kal_uint8* reply_segment;       /* The reply segment buffer */
} wps_read_content_rsp_var_struct;

/* This is the local parameter structure for MSG_ID_WPS_POST_CONTENT_IND. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint16 request_id;          /* Request ID */
    kal_uint8 seq_num;              /* Sequence number */
    kal_uint8 result;               /* Result (wps_result_error_enum) */
} wps_post_content_ind_struct;

/* This is the local parameter structure for MSG_ID_WPS_POST_CONTENT_RES. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;           /* Channel ID */
    kal_uint16 request_id;          /* Request ID */
    kal_uint8 seq_num;              /* Sequence number (for debug purpose) */
    
    /* Indicate if more data is needed to be retrieved. */
    kal_bool more;
} wps_post_content_res_struct;

/* This is the peer buffer structure for MSG_ID_WPS_POST_CONTENT_RES. */
typedef struct
{
    kal_uint32 post_segment_len;    /* The post data segment length */
    kal_uint8* post_segment;        /* The post data segment */
} wps_post_content_res_var_struct;

/* This is the local parameter structure for MSG_ID_WPS_DL_PROGRESS_IND. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint16 request_id;          /* Request ID */
    kal_uint8 seq_num;              /* Sequence number */
    kal_uint8 status;               /* Downloading status (wps_dl_status_enum) */
    kal_int32 cause;                /* Error cause if status is aborted */
    kal_uint32 acc_size;            /* Accumulated size of the download */
    kal_uint32 dl_buff_len;         /*the actual length of buffer supplied by WPS*/
    kal_uint8 dl_buff[WPS_DEFAULT_DL_BUFF_LEN];
} wps_dl_progress_ind_struct;

/* This is the local parameter structure for MSG_ID_WPS_DL_PROGRESS_RES. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_uint8 channel_id;           /* Channel ID */
    kal_uint16 request_id;          /* Request ID */
    kal_uint8 seq_num;              /* Sequence number */
    /* The file path used to store replied content when reply_type is specified 
       as WPS_DATA_TYPE_FILE_RECREATE */
    kal_wchar reply_path[256];	
    kal_uint32 dl_buff_len;     /*the actual length of buffer supplied by App*/   	
    kal_uint8 dl_buff[WPS_DEFAULT_DL_BUFF_LEN];
} wps_dl_progress_res_struct;

/* This is the local parameter structure for MSG_ID_WPS_CANCEL_REQ. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_uint8 channel_id;           /* Channel ID */
    kal_uint16 request_id;          /* Request ID */
} wps_cancel_req_struct;

/* This is the local parameter structure for MSG_ID_WPS_CANCEL_RSP. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint16 request_id;          /* Request ID */
    kal_uint8 result;               /* Result (wps_result_error_enum) */
} wps_cancel_rsp_struct;

/* This is the local parameter structure for MSG_ID_WPS_PUSH_IND. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    /* Content type of the push document. Please also refer to 
       WPS_MAX_CONTENT_TYPE_LEN for the buffer length. */
    kal_uint8 content_type[256];

    /* Content length of the push document. */
    kal_uint32 content_length;

    /* The file path of storing push document. Please also refer to 
       WPS_MAX_PUSH_FILE_PATH_LEN for the buffer length. */
    kal_wchar data_path[256];
} wps_push_ind_struct;

/* This is the local parameter structure for MSG_ID_WPS_CLEAR_REQ. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;       /* Channel ID */
    kal_uint16 request_id;      /* Request ID */
    kal_uint8 operation;        /* Clear operation */
} wps_clear_req_struct;

/* This is the peer buffer structure for MSG_ID_WPS_CLEAR_REQ. */
typedef struct
{
    /* Mandatory If operation is WPS_CLEAR_CACHE_URL_MATCH or 
       WPS_CLEAR_CACHE_URL_PREFIX. */
    kal_uint32 cache_url_len;

    /* Mandatory If operation is WPS_CLEAR_CACHE_URL_MATCH or 
       WPS_CLEAR_CACHE_URL_PREFIX. */
    kal_uint8  *cache_url;
} wps_clear_req_var_struct;

/* This is the local parameter structure for MSG_ID_WPS_CLEAR_RSP. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint16 request_id;      /* Request ID */
    kal_uint8 result;           /* Result (wps_result_error_enum) */
} wps_clear_rsp_struct;

/* Used to get the current security session information of the existing secure connection by channel ID. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;   /* channel identifier */
} wps_sec_get_session_info_req_struct;

/* To send response to get session information request. If success, the response contains cipher suite constant and connection type. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;       /* channel identifier */
    kal_uint8 result;           /* get session info result (wps_result_error_enum) */
    kal_uint16 key_exchange_alg;    /* key exchange algorithm (key exchange algorithm constant of cipher suite) */
    kal_uint8 blk_encrypt_alg;      /* bulk encryption algorithm (bulk encryption algorithm constant of cipher suite) */
    kal_uint8 hash_alg;             /* hash algorithm (hash algorithm constant of cipher suite) */
    kal_uint8 sec_conn_type;        /* security connection type (security connection type constant) */
} wps_sec_get_session_info_rsp_struct;

/* To send get the current used server certificate information of the existing secure connection by channel ID. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;       /* channel identifier */
} wps_sec_get_current_cert_req_struct;

/* To send response to get current used server certificate request. If success, the response contains the detail information of the server certificate. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;       /* channel identifier */
    kal_uint8 result;           /* get session info result (wps_result_error_enum) */
    kal_uint8 issuer[256];      /* issuer */
    kal_uint16 issuer_len;      /* issuer length */
    kal_uint32 not_after;       /* Valid Not After */
    kal_uint32 not_before;      /* Valid Not Before */
    kal_uint8 serial_num[128];  /* serial number */
    kal_uint16 serial_num_len;  /* serial number length */
    kal_uint8 sig_alg_name[128];/* signature algorithm name */
    kal_uint16 sig_alg_name_len;/* signature algorithm name length */
    kal_uint8 subject[256];     /* subject */
    kal_uint16 subject_len;     /* subject length */
    kal_uint8 type;             /* certificate type */
    kal_uint8 version;          /* certificate vesion */
} wps_sec_get_current_cert_rsp_struct;

/* This is the local parameter structure for MSG_ID_WPS_HTTP_AUTH_IND. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;       /* Channel ID */
    kal_uint16 request_id;      /* Request ID */
    kal_uint8 auth_type;        /* Authentication type (HTTP authentication constant) */
    kal_uint8 realm_len;        /* Realm string length */
    kal_uint8 realm[256];       /* Realm string */
    kal_uint8 username_len;     /* Username string length */
    kal_uint8 username[256];    /* Username string */
} wps_http_auth_ind_struct;

/* This is the local parameter structure for MSG_ID_WPS_HTTP_AUTH_IND. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;       /* Channel ID */
    kal_uint16 request_id;      /* Request ID */

    /* NULL termianted username. */
    kal_uint8 username[WPS_MAX_AUTH_USERNAME_LENGTH];

    /* NULL terminated password. */
    kal_uint8 password[WPS_MAX_AUTH_PASSWORD_LENGTH];
} wps_http_auth_res_struct;

/* This is the local parameter structure for MSG_ID_WPS_HTTP_AUTH_INFO. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8  auth_type;        
    kal_uint8 auth_option; 
    kal_uint8 prx_addr[WPS_DOMAIN_NAME_PROXY_ADDR_LEN];      /* Proxy address in the form of domain name or IP address in the form of string */
    kal_uint16 port;
} wps_http_auth_info_struct;

/* This is the peer buffer structure for MSG_ID_WPS_HTTP_AUTH_INFO. */
typedef struct
{
    kal_uint32 url_len;
    kal_uint8  *url;                  
    kal_uint32 realm_len;    
    kal_uint8  *realm;
    kal_uint32 username_len;    
    kal_uint8  *username;
    kal_uint32 password_len;    
    kal_uint8  *password;
	/*These below listed fields are required when auth_type is Digest*/
    kal_uint32 nonce_len;    
    kal_uint8  *nonce;  
    kal_uint32 opaque_len;    
    kal_uint8  *opaque;
    kal_uint32 algorithm_len;        
    kal_uint8  *algorithm;
    kal_uint32 qop_len;        
    kal_uint8  *qop;
} wps_http_auth_info_var_struct;

/* This is the local parameter structure for MSG_ID_WPS_HTTP_AUTH_RES. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 status;           /* Status (wps_ready_status_enum) */
} wps_status_query_rsp_struct;
/* WPS SAP end */

/* This is the structure of the certificate content object in wps security module */
typedef struct
{
    kal_uint8 issuer[256];          /* issuer name */
    kal_uint16 issuer_len;          /* issuer name length */
    kal_uint32 not_after;           /* Valid not after */
    kal_uint32 not_before;          /* Valid not before */
    kal_uint8 serial_num[128];      /* serial */
    kal_uint16 serial_num_len;      /* serial number length */
    kal_uint8 sig_alg_name[128];    /* signature algorithm */
    kal_uint16 sig_alg_name_len;    /* signature algorithm length */
    kal_uint8 subject[256];         /* subject name */
    kal_uint16 subject_len;         /* subject name length */
    kal_uint8 type;                 /* X.509 or WTLS  */
    kal_uint8 version;              /* The version of the certificate */
    kal_uint8 cert_attribute; 		
} wps_sec_cert_content_struct;

/* This is the structure of the rsa public key in wps security module */
typedef struct
{
    kal_uint8 *rsa_modulus;     /* The pointer of rsa modulus */
    kal_uint16 mod_len;         /* The length of modulus */
    kal_uint8 *rsa_exponent;    /* The pointer of rsa exponent */
    kal_uint16 exp_len;         /* The length of  exponent*/
} wps_sec_rsa_public_key_struct;

/* This is the root ca structure for sending MSG_ID_WPS_SEC_GET_X509_CA_CERT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 idx;                                  /* The index of the X.509 root ca certificate */
    wps_sec_cert_content_struct root_ca;            /* The content of the X.509 root ca certificate */
    wps_sec_rsa_public_key_struct rsa_public_key;   /* The rsa public key associated with the X.509 rot ca certificate */
} wps_sec_get_x509_ca_cert_ind_struct;

/* This is the get x509 ca cert response structure for sending MSG_ID_WPS_SEC_GET_X509_CA_CERT_RSP */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 total;            /* The total number of X.509 root CA certificate */
    kal_uint8 result;           /* get X509 CA certificate result (wps_result_error_enum) */
} wps_sec_get_x509_ca_cert_rsp_struct;

/* This is the structure of the certificate in wps security module */
typedef struct
{
    kal_uint8 format;       /* WPS_SEC_CERT_FORMAT_X509 / WPS_SEC_CERT_FORMAT_WTLS */
    kal_uint32 cert_len;    /* certificate length */
    unsigned char *cert;    /* certificate data */
} wps_sec_certificate_struct;

#ifdef __HTTP_INTERFACE__
/* To verify a certificate chain, the result is returned in MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 cert_num;     /* Number of certificates */
    wps_sec_certificate_struct certs[MAX_WPS_CERTIFICATE_NUM]; /* array of certicicates */
} wps_sec_verify_cert_chain_req_struct;

/* This is the structure to send the response for MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_REQ. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 root_len;        /* root_cert file size */
    kal_uint16 root_cert[261];  /* root_cert file patch in UCS2 with null terminator */
    kal_uint8 result;           /* wps_sec_result_error_enum */
    kal_uint8 format;           /* The root certificate format, X509 or WTLS */
} wps_sec_verify_cert_chain_rsp_struct;
#endif /* __HTTP_INTERFACE__ */

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 status;
    kal_uint8 bearer_type;
} wap_bearer_status_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_uint8 title[82];
    kal_uint8 dcs;
    kal_uint8 url[256];
} wap_select_bookmark_rsp_struct;

typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;
   kal_uint8  sim_status;        /* Which SIM card in slot */
   kal_uint8  setting_mode;      /*  Which SIM card is enabled in Setting */
   kal_uint8 sim1_type;
   kal_uint8 sim2_type;
}wap_sim_info_notify_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_bool use_default;
    kal_uint32 net_id;
    kal_uint8 addr[4];
    kal_uint16 port;
    kal_uint8 conn_type;
    char domain[256];
} wps_create_stream_connection_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
    kal_int16 error_cause;
} wps_create_stream_connection_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_int16 error_cause;
} wps_stream_connection_closed_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
} wps_close_stream_connection_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 result;
} wps_close_stream_connection_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
} wps_stream_data_send_req_struct;

typedef struct
{
    kal_uint32 length;
    kal_uint8* data;
} wps_stream_data_send_req_var_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
    kal_uint8 result;
} wps_stream_data_send_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
} wps_stream_data_recv_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
    kal_uint32 read_length;
} wps_stream_data_read_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 channel_id;
    kal_uint8 seq_num;
    kal_uint8 result;
    kal_bool more;
} wps_stream_data_read_rsp_struct;

typedef struct
{
    kal_uint32 length;
    kal_uint8* data;
} wps_stream_data_read_rsp_var_struct;

/* To send request of deleting the specified root CA stored in the device. */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 idx;   /* Index of certificate to be deleted. */
} wps_sec_delete_ca_cert_req_struct;

/* To send response of deleting operation */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 idx;       /* Index of certificate to be deleted. */
   kal_uint8 result;    /* operation result (wps_result_error_enum) */
} wps_sec_delete_ca_cert_rsp_struct;

/* To notify the application that security package requires user interaction to continue. */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 request_id;    /* request identifier */
   kal_uint8 dialog_type;   /* dialog type (Dialog type Constant) */
   kal_uint8 buttons;       /* One button or two button dialogs (Dialog button type constant) */
   kal_uint32 title_id;     /* Resource id of title */
   kal_uint32 text_id;      /* Resource id of message */
} wps_show_confirm_dialog_ind_struct;

/* To send the response to the notification of show dialog request. */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 request_id;    /* request identifier */
   kal_uint8 result;        /* Result of user respone (Dialog response constant) */
} wps_show_confirm_dialog_res_struct;

/* This structure is used to get the list of certificate stored in certificated storage. */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cert_options;  /* Type of certificate, Which certificate type to get. WPS_SEC_GET_USER_CERT, WPS_SES_GET_ROOT_CERT, or both bitwise ORed can be used. */
   kal_uint8 key_purpose;   /* not used now */
} wps_sec_get_cert_ids_req_struct;

/* This structure is used to return the list of certificate stored in certificated storage. */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 total;             /* The total number of certificate ids returned */
   kal_uint8 result;            /* cet cert IDS operation result (wps_result_error_enum) */
   kal_uint32 cert_ids[256];    /* List of certificate ids */
} wps_sec_get_cert_ids_rsp_struct;

/* This structure is used to get the certificate with certificate identifier provided. */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;   
   kal_uint32 cert_id;      /* The certificate identifier */
   kal_uint8 key_purpose;   /* not used now */
} wps_sec_get_cert_req_struct;

/* This struct is used to response to MSG_ID_WPS_SEC_GET_ CERT_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;   
   kal_uint32 cert_id;      /* The certificate identifier */
   kal_uint8 result;        /* wps_sec_result_error_enum */
   wps_sec_cert_content_struct cert;    /* The content of the certificate */
   wps_sec_rsa_public_key_struct rsa_public_key;    /* The rsa public key associated with the X.509 rot ca certificate */
} wps_sec_get_cert_rsp_struct;

/*******************************************************************/
/*How to send cookie information*/
/*If the server sends cookie information in this format,i.e only one cookie*/
/*Set-Cookie: NO_MOBILE=; path=/; domain=.youtube.com; expires=Thu, 01-Jan-1970 00:00:00*/
/*the message will be sent once*/

/*or where in it set two cookies*/
/*Cookie: VISITOR_INFO1_LIVE=lxqDuJATmzw; PREF=f1=40000000; GPS=1
  Cookie2: $Version=1*/
/*when server sends two cookies, Opera need to send each cookie with this message*/  
/*so effectively, the message will be sent twice*/

/******************************************************************/
/* This is the local parameter structure for MSG_ID_WPS_SET_COOKIE_REQ. */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 cookie_header[WPS_COOKIE_HEADER_LEN]; /*cookie header represent Cookie or Cookie2 string, NULL terminated string*/
    kal_uint32 maxage;        /*age of cookie, 0 if expires immediately/expired in seconds*/
    kal_uint16 portlist[WPS_COOKIE_PORT_NUM];          /*port number specified by the server, 0 if doesn't exist*/
    kal_uint32 secure;        /*TRUE if cookie should be sent on secure conneciton, specified by server*/
    kal_uint8 version_major;  /*major version of the cookie*/
    kal_uint8 version_minor;  /*minor version of the cookie*/        
} wps_set_cookie_req_struct;

/* This is the peer buffer structure for MSG_ID_WPS_SET_COOKIE_REQ. */
typedef struct  
{
  kal_uint32 url_len;       /*URL length*/
  kal_uint8* url;          /*URL*/
  kal_uint32 name_len;
  kal_uint8* name;          /*name of the cookie*/
  kal_uint32 value_len;  
  kal_uint8* value;         /*value of the cookie*/
  kal_uint32 domain_len;  
  kal_uint8* domain;        /*domain of the cookie as specified by the server, NULL if it doesn't exist*/
  kal_uint32 path_len;
  kal_uint8* path;          /*path of the cookie as specified by the server, NULL if it doesn't exist*/
} wps_set_cookie_req_var_struct;

/**********************************************************************************************************************************************************************************
 * FUNCTION
 *  wps_pun_var_part
 * DESCRIPTION
 *  This function is used to pack/unpack the following peer buffer struct of
 *  those primitives with variable length parameter:
 * 
 *      1) MSG_ID_WPS_SET_CHANNEL_REQ : wps_set_channel_req_var_struct
 *      2) MSG_ID_WPS_HTTP_REQ : wps_http_req_var_struct
 *      3) MSG_ID_WPS_HTTP_RSP : wps_http_rsp_var_struct
 *      4) MSG_ID_WPS_READ_CONTENT_RSP : wps_read_content_rsp_var_struct
 *      5) MSG_ID_WPS_POST_CONTENT_RES : wps_post_content_res_var_struct
 *      6) MSG_ID_WPS_CLEAR_REQ : wps_clear_req_var_struct
 * 
 * PARAMETERS
 *  op          : [IN]         Operation (wps_pun_enum)
 *  msg_id      : [IN]         Message ID
 *  p           : [IN]         Structure pointer
 *  buf         : [IN]         Buffer pointer 
 * RETURNS
 *  The number of the octets packed or unpacked or counted.
 * 
 * EXAMPLE
 * <code>
 *
 *  void wps_send_http_req(void) // send MSG_ID_WPS_HTTP_REQ
 *  {
 *      ilm_struct *ilm_ptr = NULL;
 *      wps_http_req_struct *http_req;
 *      peer_buff_struct *peer_buff_ptr;
 *      wps_http_req_var_struct http_req_var;
 *      kal_uint16 pdu_length;
 *      
 *      char url[] = "http://www.kimo.com.tw/";
 *   
 *      http_req = (wps_http_req_struct*)construct_local_para(sizeof(wps_http_req_struct), TD_CTRL);
 *      http_req->channel_id = 0;
 *      http_req->request_id = 0;
 *      http_req->method = WPS_HTTP_METHOD_GET;
 *      http_req->more_post = KAL_FALSE;
 *      http_req->option = WPS_HTTP_OPTION_NO_CACHE| WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY;
 *      http_req->reply_path[0] = '\0';
 *      http_req->reply_path[1] = '\0';
 *      http_req->reply_type = WPS_DATA_TYPE_BUFFER;
 *      http_req->reply_segment_len = 1024;
 *      
 *      // fill url in the wps_http_req_var_struct first
 *      http_req_var.request_header_len = 0;
 *      http_req_var.request_header = NULL;
 *      http_req_var.post_segment_len = 0;
 *      http_req_var.post_segment = NULL;
 *      http_req_var.request_url_len = strlen(url);
 *      http_req_var.request_url = (kal_uint8*)get_ctrl_buffer((kal_uint16)(http_req_var.request_url_len+1));
 *      strcpy((char*)http_req_var.request_url, url);
 *      
 *      // then get the size of the buffer which needs for the packing
 *      pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);
 *      peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
 *    
 *      // then pack the wps_http_req_var_struct into the peer buffer
 *      wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, get_pdu_ptr(peer_buff_ptr, &pdu_length));
 *      free_ctrl_buffer(http_req_var.request_url);
 *    
 *      ilm_ptr = allocate_ilm(MOD_MMI);
 *      ilm_ptr->local_para_ptr = (local_para_struct *)http_req;
 *      ilm_ptr->msg_id         = MSG_ID_WPS_HTTP_REQ;
 *      ilm_ptr->peer_buff_ptr  = peer_buff_ptr;
 *    
 *      SEND_ILM(MOD_MMI, MOD_WAP, 0, ilm_ptr)  
 *  }
 *    
 *  void wps_handle_wsp_rsp(ilm_struct *ilm_ptr) // process MSG_ID_WPS_HTTP_RSP 
 *  {
 *      wps_http_rsp_struct *http_rsp;
 *      wps_http_rsp_var_struct http_rsp_var;    
 *      kal_uint16 pdu_length;
 *    
 *      http_rsp = (wps_http_rsp_struct*)ilm_ptr->local_para_ptr;
 *      if(http_rsp->result == WPS_OK && ilm_ptr->peer_buff_ptr)
 *      {
 *          if(wps_pun_var_part(WPS_PUN_UNPACK, ilm_ptr->msg_id, &http_rsp_var, get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len)) > 0)
 *          {
 *              HDIa_fileWrite(fd, http_rsp_var.reply_segment);
 *          }
 *      }
 *  }
 *
 * </code>                                                                                                                                                                        
 **********************************************************************************************************************************************************************************/
extern kal_int32 wps_pun_var_part(kal_uint8 op, kal_uint32 msg_id, void *p, kal_uint8 *buf);

#endif /* _WPS_STRUCT_H */

