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
 *	tls_app_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains enums for TLS API.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _TLS_APP_ENUMS_H_
#define _TLS_APP_ENUMS_H_

/***************************************************************************
 * <GROUP Enums>
 *
 * SSL alert levels.
 ***************************************************************************/
typedef enum {
    TLS_ALERT_LV_WARNING = 1, /* Warning alert. */
    TLS_ALERT_LV_FATAL = 2    /* Fatal alert, application MUST terminate the connection immediately. */
} tls_alert_level_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * SSL alert descriptions. Ref. RFC 4346, section 7.2.2.
 ***************************************************************************/
typedef enum {
    TLS_ALERT_CLOSE_NOTIFY                = 0,  /* Peer shuts down the connection. */
    TLS_ALERT_UNEXPECTED_MESSAGE          = 10, /* Received an unexped mesage, always a fatal. */
    TLS_ALERT_BAD_RECORD_MAC              = 20, /* Bad MAC, always a fatal. */
    TLS_ALERT_DECRYPTION_FAILED           = 21, /* Decryption failed, always a fatal. */
    TLS_ALERT_RECORD_OVERFLOW             = 22, /* Record size exceeds the limitation, always a fatal. */
    TLS_ALERT_DECOMPRESSION_FAILURE       = 30, /* Deccompression failed, always a fatal. */
    TLS_ALERT_HANDSHAKE_FAILURE           = 40, /* Handshake failed, fatal. */
    TLS_ALERT_NOCERTIFICATE_RESERVED      = 41, /* Response to a certification request if no appropriate certificate is available, SSLv3 only. */
    TLS_ALERT_BAD_CERTIFICATE             = 42, /* A certificate was corrupt, signatures that did not verify correctly. */
    TLS_ALERT_UNSUPPORTED_CERTIFICATE     = 43, /* Unsupported certificate type. */
    TLS_ALERT_CERTIFICATE_REVOKED         = 44, /* Received a revoked certificate from peer. */
    TLS_ALERT_CERTIFICATE_EXPIRED         = 45, /* A certificate has expired or not yet valid. */
    TLS_ALERT_CERTIFICATE_UNKNOWN         = 46, /* Some unspecificate issue in processing the certificate.  */
    TLS_ALERT_ILLEGAL_PARAMETER           = 47, /* Illegal parameter in the message, always a fatal. */
    TLS_ALERT_UNKNOWN_CA                  = 48, /* The certificate chain cannot be verified successfully due to untrusted CA, always a fatal. */
    TLS_ALERT_ACCESS_DENIED               = 49, /* sender decided not to proceed with negotiation when access control was applied, always a fatal. */
    TLS_ALERT_DECODE_ERROR                = 50, /* The field in a message is incorrect, always a fatal. */
    TLS_ALERT_DECRYPT_ERROR               = 51, /* a handshake cryptographic operation failed, including verify a signature, decrypt a key exchange, or validate a finished mesasge. */
    TLS_ALERT_EXPORT_RESTRICTION_RESERVED = 60, /* A negotiation not in compliance with export restrictions was detected. */
    TLS_ALERT_PROTOCOL_VERSION            = 70, /* The protocol version proposed by client is not supported by server side, always a fatal. */
    TLS_ALERT_INSUFFICIENT_SECURITY       = 71, /* The server requires cphers more secure than those supported by the client, always a fatal. */
    TLS_ALERT_INTERNAL_ERROR              = 80, /* An internal error unrelated to the peer, always a fatal. */
    TLS_ALERT_USER_CANCELLED              = 90, /* The handshake is canceled for some reason unrelated to a protocol failure, generally a warning. */
    TLS_ALERT_NO_RENEGOTIATION            = 100 /* When peer suggest to renegotiate again but local rejects it, always a warning. */
} tls_alert_desc_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * SSL versions.
 * Ref. tls_new_ctx().
 ***************************************************************************/
typedef enum {
    TLS_ALL_VERSIONS = 0, /* ALL supported SSL/TLS versions */
    SSLv2 = 0x01u << 0,   /* SSLv2 */
    SSLv3 = 0x01u << 1,   /* SSLv3 */
    TLSv1 = 0x01u << 2,   /* TLSv1 */
    TLS_UNKNOWN_VERSION = 0xffu /* Unknown */
} tls_version_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * SSL side.
 * Ref. tls_new_ctx().
 ***************************************************************************/
typedef enum {
    TLS_CLIENT_SIDE = 0, /* Client side */
    TLS_SERVER_SIDE = 1  /* Server side */
} tls_side_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * Encoding of certificate files.
 * Ref. tls_set_verify().
 ***************************************************************************/
typedef enum {
    TLS_FILETYPE_PEM = 0, /* PEM encoding */
    TLS_FILETYPE_DER      /* DER encoding */
} tls_filetype_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * Client authentication modes.
 * Ref. tls_auth_mode_enum().
 ***************************************************************************/
typedef enum {
    TLS_CLIENT_AUTH_BEGIN,
    TLS_CLIENT_AUTH_RSA_CLIENT, /* RSA client side */
    TLS_CLIENT_AUTH_RSA_SERVER, /* RSA server side */
    TLS_CLIENT_AUTH_DSS_CLIENT, /* DSS(DSA) cient side */
    TLS_CLIENT_AUTH_DSS_SERVER, /* DSS(DSA) server side */
    TLS_CLIENT_AUTH_END = 0xff
} tls_auth_mode_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * Error codes of TLS operations.
 ***************************************************************************/
typedef enum {
    TLS_ERR_NONE                   = 0,   /* No error. */
    TLS_ERR_WOULDBLOCK             = -1,  /* Operation cannot complete now. */
    TLS_ERR_NO_FREE_CTX            = -2,  /* No free global context slots. */
    TLS_ERR_NO_MEMORY              = -3,  /* Allocate memory failed. */
    TLS_ERR_INVALID_CONTEXT        = -4,  /* Invalid global context id. */
    TLS_ERR_INVALID_CIPHER         = -5,  /* Invalid cipher enum value. */
    TLS_ERR_EXCESS_MAX_CIPHERS     = -6,  /* Too many ciphers. */
    TLS_ERR_INVALID_PARAMS         = -7,  /* Invalid parameter. */
    TLS_ERR_INVALID_ROOT_CERT      = -8,  /* Invalid root certificate id. */
    TLS_ERR_INVALID_PRIV_KEY       = -9,  /* Invalid private key id. */
    TLS_ERR_INVALID_PERSONAL_CERT  = -10, /* Invalid personal certificate id. */
    TLS_ERR_INVALID_FILE_TYPE      = -11, /* Invalid file encoding type. */
    TLS_ERR_INVALID_AUTH_MODE      = -12, /* Invalid client auth mode. */
    TLS_ERR_EXCESS_MAX_AUTH_MODES  = -13, /* Too many client auth modes. */
    TLS_ERR_ALREADY                = -14, /* The operation is progressing. */
    TLS_ERR_HANDSHAKED             = -15, /* Handshaked completed. */
    TLS_ERR_INVALID_SOCK_ID        = -16, /* Invalid socket id. */
    TLS_ERR_NO_CONN_CTX            = -17, /* No associated connection context. */
    TLS_ERR_HANDSHAKING            = -18, /* Opreation denied when connection is handshaking. */
    TLS_ERR_REHANDSHAKING          = -19, /* Connection is rehandshaking. */
    TLS_ERR_REHANDSHAKED           = -20, /* TLS auto re-handshaked completed. */
    TLS_ERR_SHUTDOWNED             = -21, /* Opreation denied when connection is shutdowned. */
    TLS_ERR_REQ_HANDSHAKE          = -22, /* TLS peer requested handshake. */
    TLS_ERR_NEED_HANDSHAKE         = -23, /* Need handshake first. */
    TLS_ERR_REHANDSHAKE_REJ        = -24, /* Peer rejects our renegotiation, connection still valid. */
    TLS_ERR_CONN_CLOSED            = -25, /* Connection closed by peer. */
    TLS_ERR_IO_ERROR               = -26, /* Lower-layer IO error. */
    TLS_ERR_OP_DENIED              = -27, /* Operation denied due to incorrect state. */
    TLS_ERR_READ_REQUIRED          = -28, /* Application data need to be read before processing rehandshake. */
    TLS_ERR_CERT_VALIDATE          = -29, /* Certificate validation failed. */
    TLS_ERR_PRNG_FAIL              = -30, /* Set PRNG failed. */
    TLS_ERR_WAITING_CERT           = -32, /* Waiting certificate confirm from CERTMAN. */
    TLS_ERR_FILESYS                = -33, /* File system operation failed. */
    TLS_ERR_TASK_NOT_READY         = -34, /* TLS task not ready, waiting for CERTMAN confirm message. */
    TLS_ERR_SSL_INTERNAL           = -100,/* SSL layer internal error. */
    TLS_ERR_SOC_INTERNAL           = -101,/* Socket layer internal error. */
    TLS_ERR_CERTMAN_INTERNAL       = -102 /* Certman internal error. */
} tls_error_enum;



/***************************************************************************
 * <GROUP Enums>
 *
 * TLS events.
 * Ref. app_tls_notify_ind_struct.
 ***************************************************************************/
typedef enum {
    TLS_HANDSHAKE_READY    = 0x01u << 0, /* The connection is ready for performing handshake. */
    TLS_HANDSHAKE_DONE     = 0x01u << 1, /* Handshake procedure is finished, success or failure. */
    TLS_READ               = 0x01u << 2, /* There is data for reading. */
    TLS_WRITE              = 0x01u << 3, /* There is buffer for writing. */
    TLS_CLOSE              = 0x01u << 4  /* The SSL connection is closed. */
} tls_event_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * User decision of handling the received invalid certificate.
 * Ref. app_tls_invalid_cert_ind_struct.
 ***************************************************************************/
typedef enum {
    TLS_USER_REJECT          = 0, /* User rejects the invalid certificate. */
    TLS_USER_ACCEPT_ONCE     = 1, /* User accepts the invalid certificate for this time */
    TLS_USER_ACCEPT_FOREVER  = 2  /* User accepts the invalid cert forever */
} tls_inval_cert_action;


/***************************************************************************
 * <GROUP Enums>
 *
 * Suppoerted ciphers.
 * Ref. tls_set_ciphers().
 * <i>Note</i>:
 * (*) TLS 1.1 implementations MUST NOT negotiate these cipher suites in TLS
 *     1.1 mode. For backward compatibility, they may be offered in the
 *     ClientHello for use with TLS 1.0 or SSLv3-only servers.
 *     TLS 1.1 clients MUST check that the server did not choose one of these
 *     cipher suites during the handshake.
 ***************************************************************************/
typedef enum {
    TLS_NULL_MD5                = 0,  /* 0x0001, TLS_RSA_WITH_NULL_MD5. */
    TLS_EXP_RC4_MD5             = 1,  /* 0x0003, TLS_RSA_EXPORT_WITH_RC4_40_MD5.(*) */
    TLS_RC4_MD5                 = 2,  /* 0x0004, TLS_RSA_WITH_RC4_128_MD5. */
    TLS_RC4_SHA                 = 3,  /* 0x0005, TLS_RSA_WITH_RC4_128_SHA, TLS Profile MUST. */
    TLS_EXP_DES_CBC_SHA         = 4,  /* 0x0008, TLS_RSA_EXPORT_WITH_DES40_CBC_SHA.(*) */
    TLS_DES_CBC_SHA             = 5,  /* 0x0009, TLS_RSA_WITH_DES_CBC_SHA. */
    TLS_DES_CBC3_SHA            = 6,  /* 0x000A, TLS_RSA_WITH_3DES_EDE_CBC_SHA, TLS Profile MUST. */
    TLS_EXP_EDH_DSS_DES_CBC_SHA = 7,  /* 0x0011, TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA.(*) */
    TLS_EDH_DSS_CBC_SHA         = 8,  /* 0x0012, TLS_DHE_DSS_WITH_DES_CBC_SHA. */
    TLS_EDH_DSS_DES_CBC3_SHA    = 9,  /* 0x0013, TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA. */
    TLS_EXP_EDH_RSA_DES_CBC_SHA = 10, /* 0x0014, TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA.(*) */
    TLS_EDH_RSA_DES_CBC_SHA     = 11, /* 0x0015, TLS_DHE_RSA_WITH_DES_CBC_SHA. */
    TLS_EDH_RSA_DES_CBC3_SHA    = 12, /* 0x0016, TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA. */
    TLS_EXP_ADH_RC4_MD5         = 13, /* 0x0017, TLS_DH_anon_EXPORT_WITH_RC4_40_MD5.(*) */
    TLS_ADH_RC4_MD5             = 14, /* 0x0018, TLS_DH_anon_WITH_RC4_128_MD5. */
    TLS_EXP_ADH_DES_CBC_SHA     = 15, /* 0x0019, TLS_DH_anon_EXPORT_WITH_DES40_CBC_SHA.(*) */
    TLS_ADH_DES_CBC_SHA         = 16, /* 0x001A, TLS_DH_anon_WITH_DES_CBC_SHA. */
    TLS_ADH_DES_CBC3_SHA        = 17, /* 0x001B, TLS_DH_anon_WITH_3DES_EDE_CBC_SHA. */
 
    TLS_AES128_SHA              = 18, /* 0x002F, TLS_RSA_WITH_AES_128_CBC_SHA. */
    TLS_AES256_SHA              = 19, /* 0x0035, TLS_RSA_WITH_AES_256_CBC_SHA. */

    TLS_EXP1024_DES_CBC_SHA     = 20, /* 0x0062, TLS_RSA_EXPORT1024_WITH_DES_CBC_SHA. */
    TLS_EXP1024_RC4_SHA         = 21, /* 0x0064, TLS_RSA_EXPORT1024_WITH_RC4_56_SHA. */
    TLS_DHE_DSS_RC4_SHA         = 22, /* 0x0066, TLS_DHE_DSS_WITH_RC4_128_SHA. */

    TLS_ECDH_SECT163K1_RC4_SHA  = 23, /* 0xC002 in RFC 4492, TLS_ECDH_ECDSA_WITH_RC4_128_SHA. */
    TLS_ECDH_SECT163K1_NULL_SHA = 24, /* 0xC001 in RFC 4492, TLS_ECDH_ECDSA_WITH_NULL_SHA. */

    TLS_PSK_AES128_SHA          = 25, /* 0x008C in RFC 4279, TLS_PSK_WITH_AES_128_CBC_SHA. */
    TLS_PSK_DES_CBC3_SHA        = 26, /* 0x008B in RFC 4279, TLS_PSK_WITH_3DES_EDE_CBC_SHA. */
    TLS_UNKNOWN_CIPHER,
    TLS_TOTAL_CIPHER_NUM = TLS_UNKNOWN_CIPHER
} tls_cipher_enum ;


/***************************************************************************
 * <GROUP Enums>
 *
 * To represent negotiated ciphersuites, which are composed by a tuple of
 * authentication algorithm, encryption algorithm, and hash algorithm.
 * Ref. tls_get_cipher().
 ***************************************************************************/
typedef enum {
    TLS_NULL_WITH_NULL_NULL                = 0x0000, /* (NULL, NULL, NULL)*/

    TLS_RSA_WITH_NULL_MD5                  = 0x0001, /* (RSA, NULL, MD5) */
    TLS_RSA_WITH_NULL_SHA                  = 0x0002, /* (RSA, NULL, SHA) */
    TLS_RSA_EXPORT_WITH_RC4_40_MD5         = 0x0003, /* (RSA_EXPORT, RC4_40), MD5, TLS 1.0 */
    TLS_RSA_WITH_RC4_128_MD5               = 0x0004, /* (RSA, RC4_128, MD5) */
    TLS_RSA_WITH_RC4_128_SHA               = 0x0005, /* (RSA, RC4_128, SHA) */
    TLS_RSA_EXPORT_WITH_RC2_CBC_40_MD5     = 0x0006, /* (RSA_EXPORT, RC2_CBC_40, MD5), TLS 1.0 */
    TLS_RSA_WITH_IDEA_CBC_SHA              = 0x0007, /* (RSA, IDEA_CBC, SHA) */
    TLS_RSA_EXPORT_WITH_DES40_CBC_SHA      = 0x0008, /* (RSA_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    TLS_RSA_WITH_DES_CBC_SHA               = 0x0009, /* (RSA, DES_CBC, SHA) */
    TLS_RSA_WITH_3DES_EDE_CBC_SHA          = 0x000A, /* (RSA, 3DES_EDE_CBC, SHA) */

    TLS_DH_DSS_EXPORT_WITH_DES40_CBC_SHA   = 0x000B, /* (DH_DSS_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    TLS_DH_DSS_WITH_DES_CBC_SHA            = 0x000C, /* (DH_DSS, DES_CBC, SHA) */
    TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA       = 0x000D, /* (DH_DSS, 3DES_EDE_CBC, SHA) */
    TLS_DH_RSA_EXPORT_WITH_DES40_CBC_SHA   = 0x000E, /* (DH_RSA_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    TLS_DH_RSA_WITH_DES_CBC_SHA            = 0x000F, /* (DH_RSA, DES_CBC, SHA) */
    TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA       = 0x0010, /* (DH_RSA, 3DES_EDE_CBC, SHA) */
    TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA  = 0x0011, /* (DHE_DSS_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    TLS_DHE_DSS_WITH_DES_CBC_SHA           = 0x0012, /* (DHE_DSS, DES_CBCi, SHA) */
    TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA      = 0x0013, /* (DHE_DSS, 3DES_EDE_CBC, SHA) */
    TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA  = 0x0014, /* (DHE_RSA_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    TLS_DHE_RSA_WITH_DES_CBC_SHA           = 0x0015, /* (DHE_RSA, DES_CBCi, SHA) */
    TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA      = 0x0016, /* (DHE_RSA, 3DES_EDE_CBC, SHA) */

    TLS_DH_anon_EXPORT_WITH_RC4_40_MD5     = 0x0017, /* (DH_anon_EXPORT, RC4_40, MD5), TLS 1.0 */
    TLS_DH_anon_WITH_RC4_128_MD5           = 0x0018, /* (DH_anon, RC4_128, MD5) */
    TLS_DH_anon_EXPORT_WITH_DES40_CBC_SHA  = 0x0019, /* (DH_anon, DES40_CBC, SHA), TLS 1.0 */
    TLS_DH_anon_WITH_DES_CBC_SHA           = 0x001A, /* (DH_anon, DES_CBC, SHA) */
    TLS_DH_anon_WITH_3DES_EDE_CBC_SHA      = 0x001B, /* (DH_anon, DES_CBC, SHA) */

    TLS_KRB5_WITH_DES_CBC_SHA              = 0x001E, /* (Kerberos, DES_CBC, SHA) */
    TLS_KRB5_WITH_3DES_EDE_CBC_SHA         = 0x001F, /* (Kerberos, 3DES_EDE_CBC, SHA) */
    TLS_KRB5_WITH_RC4_128_SHA              = 0x0020, /* (Kerberos, RC4_128, SHA) */
    TLS_KRB5_WITH_IDEA_CBC_SHA             = 0x0021, /* (Kerberos, IDEA_CBC, SHA) */
    TLS_KRB5_WITH_DES_CBC_MD5              = 0x0022, /* (Kerberos, DES_CBC, MD5) */
    TLS_KRB5_WITH_3DES_EDE_CBC_MD5         = 0x0023, /* (Kerberos, 3DES_EDE_CBC, MD5) */
    TLS_KRB5_WITH_RC4_128_MD5              = 0x0024, /* (Kerberos, RC4_128, MD5) */
    TLS_KRB5_WITH_IDEA_CBC_MD5             = 0x0025, /* (Kerberos, IDEA_CBC, MD5) */

    TLS_KRB5_EXPORT_WITH_DES_CBC_40_SHA    = 0x0026, /* (Kerberos, DES_CBC_40, SHA), MUST NOT */
    TLS_KRB5_EXPORT_WITH_RC2_CBC_40_SHA    = 0x0027, /* (Kerberos, RC2_CBC_40, SHA),  MUST NOT */
    TLS_KRB5_EXPORT_WITH_RC4_40_SHA        = 0x0028, /* (Kerberos, RC4_40, SHA), MUST NOT */
    TLS_KRB5_EXPORT_WITH_DES_CBC_40_MD5    = 0x0029, /* (Kerberos, DES_DBC_40, MD5), MUST NOT */
    TLS_KRB5_EXPORT_WITH_RC2_CBC_40_MD5    = 0x002A, /* (Kerberos, RC2_CBC_40, MD5),  MUST NOT */
    TLS_KRB5_EXPORT_WITH_RC4_40_MD5        = 0x002B, /* (Kerberos, RC4_40, MD5),  MUST NOT */

    TLS_RSA_WITH_AES_128_CBC_SHA           = 0x002F, /* (RSA, AES_128_CBC, SHA) */
    TLS_DH_DSS_WITH_AES_128_CBC_SHA        = 0x0030, /* (DH_DSS, AES_128_CBC, SHA) */
    TLS_DH_RSA_WITH_AES_128_CBC_SHA        = 0x0031, /* (DH_RSA, AES_128_CBC, SHA) */
    TLS_DHE_DSS_WITH_AES_128_CBC_SHA       = 0x0032, /* (DHE_DSS, AES_128_CBC, SHA)  */
    TLS_DHE_RSA_WITH_AES_128_CBC_SHA       = 0x0033, /* (DHE_RSA, AES_128_CBC, SHA) */
    TLS_DH_anon_WITH_AES_128_CBC_SHA       = 0x0034, /* (DH_anon, AES_128_CBC, SHA) */
    TLS_RSA_WITH_AES_256_CBC_SHA           = 0x0035, /* (RSA, AES_256_CBC, SHA) */
    TLS_DH_DSS_WITH_AES_256_CBC_SHA        = 0x0036, /* (DH_DSS, AES_256_CBC, SHA) */
    TLS_DH_RSA_WITH_AES_256_CBC_SHA        = 0x0037, /* (DHE_RSA, AES_256_CBC, SHA) */
    TLS_DHE_DSS_WITH_AES_256_CBC_SHA       = 0x0038, /* (DHE_RSA, AES_256_CBC, SHA) */
    TLS_DHE_RSA_WITH_AES_256_CBC_SHA       = 0x0039, /* (DH_anon, AES_256_CBC, SHA) */
    TLS_DH_anon_WITH_AES_256_CBC_SHA       = 0x003A, /* (DH_anon, AES_256_CBC, SHA) */
    TLS_CIPHER_UNKNOWN                     = 0xFFFF
} tls_ciphersuites_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * Bulk data encryption algorithms.
 * Ref. tls_cipher_info_struct returned by tls_get_cipher_info().
 ***************************************************************************/
typedef enum {
    TLS_ENC_ALGO_UNKNOWN,
    TLS_ENC_ALGO_NULL,      /* NULL */

    TLS_ENC_ALGO_DES_40,    /* DES 40 */
    TLS_ENC_ALGO_DES,       /* DES(56) */
    TLS_ENC_ALGO_3DES,      /* 3DES */

    TLS_ENC_ALGO_RC5,       /* RC5 */
    TLS_ENC_ALGO_RC5_56,    /* RC5_56 */

    TLS_ENC_ALGO_AES_128,   /* AES_128 */
    TLS_ENC_ALGO_AES_192,   /* AES_192,  new for OpenSSL */
    TLS_ENC_ALGO_AES_256,   /* AES_256 */

    TLS_ENC_ALGO_ARC4_40,   /* RC4_40 */
    TLS_ENC_ALGO_ARC4_56,   /* RC4_56, new for OpenSSL */
    TLS_ENC_ALGO_ARC4_64,   /* RC4_64, new for OpenSSL */
    TLS_ENC_ALGO_ARC4_128,  /* RC4_128 */

    TLS_ENC_ALGO_ARC2_40,   /* RC2_40 */
    TLS_ENC_ALGO_ARC2_56,   /* RC2_56, new for OpenSSL */
    TLS_ENC_ALGO_ARC2_64,   /* RC4_64 */
    TLS_ENC_ALGO_ARC2_128   /* RC2_128 */
} tls_encryption_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * Key exchange algorithms.
 * Ref. tls_cipher_info_struct returned by tls_get_cipher_info().
 ***************************************************************************/
typedef enum {
    TLS_KEY_ALGO_UNKNOWN,
    TLS_KEY_ALGO_RSA,            /* RSA */
    TLS_KEY_ALGO_RSA_EXPORT,     /* RSA_EXPORT */
    TLS_KEY_ALGO_DH,             /* DH */
    TLS_KEY_ALGO_DH_EXPORT,      /* DH_EXPORT */
    TLS_KEY_ALGO_DHE,            /* DH */
    TLS_KEY_ALGO_DHE_EXPORT,     /* DH_EXPORT */
    TLS_KEY_ALGO_ECDH,           /* ECDH */
    TLS_KEY_ALGO_ECDHE,          /* ECDHE */
    TLS_KEY_ALGO_ECMQV,          /* ECMQV */
    TLS_KEY_ALGO_DSA,            /* DSA */
    TLS_KEY_ALGO_PSK,            /* PSK */
    TLS_KEY_ALGO_DHE_PSK,        /* DHE_PSK */
    TLS_KEY_ALGO_RSA_PSK,        /* RSA_PSK */
    TLS_KEY_ALGO_MAX
} tls_key_exchange_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * Server authentication algorithms.
 * Ref. tls_cipher_info_struct returned by tls_get_cipher_info().
 ***************************************************************************/
typedef enum {
    TLS_AUTH_ALGO_UNKNOWN,
    TLS_AUTH_ALGO_ANON,      /* ANON */
    TLS_AUTH_ALGO_RSA,       /* RSA */
    TLS_AUTH_ALGO_DSS,       /* DSS */
    TLS_AUTH_ALGO_ECDSA,     /* ECDSA */
    TLS_AUTH_ALGO_PSK        /* PSK */
} tls_auth_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * Message digest algorithms.
 * Ref. tls_cipher_info_struct returned by tls_get_cipher_info().
 ***************************************************************************/
typedef enum {
    TLS_HASH_UNKNOWN,
    TLS_HASH_MD2,       /* MD2 */
    TLS_HASH_MD4,       /* MD4 */
    TLS_HASH_MD5,       /* MD5 */
    TLS_HASH_SHA1,      /* SHA1 */
    TLS_HASH_SHA224,    /* SHA224 */
    TLS_HASH_SHA256,    /* SHA256 */
    TLS_HASH_SHA384,    /* SHA384 */
    TLS_HASH_SHA512     /* SHA512 */
} tls_hash_enum;

#endif /* !_TLS_APP_ENUMS_H_ */


