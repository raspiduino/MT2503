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
 *   tls2app_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file describes the common struct of TLS and applications.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _TLS2APP_STRUCT_H_
#define	_TLS2APP_STRUCT_H_

#ifndef _TLS_CONST_H_
#error	"tls_const.h should be included before tls2app_struct.h"
#endif	/* !_TFTP_CONST_H_ */

#ifndef _TLS_APP_ENUMS_H_
#error	"tls_app_enums.h should be included before tls2app_struct.h"
#endif	/* !_TLS_APP_ENUMS_H_ */

#include "tls_const.h"
#include "tls_app_enums.h"
#include "kal_general_types.h"

/***************************************************************************
 * <GROUP Structures>
 *
 * Indication to app for a common event.
 * Local parameter of MSG_ID_APP_TLS_NOTIFY_IND.
 ***************************************************************************/
typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_int8        sock_id;       /* Socket id to handle this notification. */
    tls_event_enum  event;         /* Reported event from TLS task.
    Applications should verifiy the event type and calls the corresponding
    handler.

    * TLS_HANDSHAKE_READY is an indication of the result of connection context
    creation procedure. tls_new_conn() might return TLS_ERR_WAITING_CERT for
    loading certificates and waiting response from MOD_CERTMAN. After received
    this message, application can then call tls_handshake() to start TLS
    handshake procedure.

    * TLS_HANDSHAKE_DONE is an indication of the handshake result procedure.
    Application can call tls_read() to receive data from or call tls_write() to
    send data to the peer.

    * For TLS_READ, application should call tls_read() repeatedly until
    WOULDBLOCK returned.

    * For TLS_WRITE, application is allowed to transmit the holding data by
    calling tls_write().

    * For TLS_CLOSE, application should call tls_delete_conn() to de-associate
    the connection with a socket id.
    */
    kal_bool        result;        /* Success or failure of the notification. */
    kal_int32       error;         /* Error code. */
    kal_int32       detail_cause;  /* Detail error cause. */
} app_tls_notify_ind_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Indication to app for received an alert from peer.
 * Local parameter of MSG_ID_APP_TLS_ALERT_IND.
 ***************************************************************************/
typedef struct
{
    kal_uint8             ref_count;
    kal_uint16            msg_len;
    kal_int8              sock_id;      /* Socket id received SSL alert message. */
    tls_alert_level_enum  alert_level;  /* Alert level. */
    tls_alert_desc_enum   alert_desc;   /* Alert description. */
    kal_int32             error;        /* Error code. */
    kal_int32             cause;        /* Detail error cause. */
} app_tls_alert_ind_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Indication of invalid certificate.
 * Local parameter of MSG_ID_APP_TLS_INVALID_CERT_IND.
 ***************************************************************************/
typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_int8        sock_id;       /* Socket id received an invalid certificate during handshake */
    kal_bool        result;        /* TRUE: user confirms to proceed the handshake against the received invalid certificate */
    tls_inval_cert_action action;  /* User's decision */
} app_tls_invalid_cert_ind_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Indication of client authentication request freom server.
 * Local parameter of MSG_ID_APP_TLS_CLIENT_AUTH_IND.
 ***************************************************************************/
typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    kal_int8            sock_id;   /* Socket id request for client authentication during handshake. */
    kal_bool            result;    /* TRUE: user selects a positive answer to the client authentication */
    kal_uint8           auth_mode_num; /* auth modes in the following auth_modes array */
    tls_auth_mode_enum  auth_modes[TLS_MAX_CLIENT_AUTH]; /* authmodes in the certificate request message from server */
    kal_uint32          identity_id;   /* user selected certificate id.  This field would be zero if no user certificate meets the criteria in the certificate request message. */
} app_tls_client_auth_ind_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Structure describes a negotiated SSL connection.
 * Ref. tls_get_cipher_info().
 ***************************************************************************/
typedef struct {
    tls_version_enum version;     /* SSL version number */
    tls_encryption_enum enc;      /* bulk encryption algrotithm */
    tls_key_exchange_enum key_ex; /* key exchange algorithm */
    tls_auth_enum auth;           /* authentication algorithm */
    tls_hash_enum hash;           /* message digest algorithm */
} tls_cipher_info_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Data structure holding a certificate in DER.
 * Ref. tls_get_peer_cert() and callback function tls_cert_verify_callback().
 ***************************************************************************/
typedef struct {
    kal_uint32 len;   /* The size of the certificate in bytes */
    kal_uint8 *data;  /* Data of the certficate in DER format */
} tls_cert_struct;

#endif /* !_TLS2APP_STRUCT_H_ */


