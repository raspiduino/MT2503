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
 *  tls_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains function prototypes, constants and enum for TLS
 *   API used for socket applications.
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
#ifndef _TLS_API_H_
#define _TLS_API_H_

#ifndef _SOC_API_H
#include "soc_api.h"
#endif /* _SOC_API_H */

#ifndef _SSL_API_H
#include "ssl_api.h"
#endif /* _SSL_API_H */

#ifndef _TLS_CONST_H_
#include "tls_const.h"
#endif /* _TLS_CONST_H_ */

#ifndef _TLS_APP_ENUMS_H
#include "tls_app_enums.h"
#endif /* _TLS_APP_ENUMS_H */

#ifndef _TLS_CALLBACK_H_
#include "tls_callback.h"
#endif /* _TLS_CALLBACK_H_ */

#ifndef _TLS2APP_STRUCT_H_
#include "tls2app_struct.h"
#endif /* _TLS2APP_STRUCT_H_ */

#include "kal_general_types.h"
#include "stack_config.h"
 
#define _TLS_CTX_API_PROTOTYPES_

/*****************************************************************************
 * <GROUP TLS Context APIs>
 * FUNCTION
 *  tls_new_ctx
 * DESCRIPTION
 *   Create TLS global context.
 *
 *   This is a mandatory function.
 *
 *  To the ver argument, only these combinations are allowed
 *  1. SSL2
 *  2. SSL3
 *  3. TLS1
 *  4. SSL3 | SSL2
 *  5. TLS1 | SSL3
 *  6. TLS1 | SSL3 | SSL2 (support all SSL versions)
 *  If the given version does not in the above combinations, TLS enables all
 *  possible versions for negotiation. In this case, a warning trace will be
 *  logged. Application can set this parameter to TLS_ALL_VERSIONS, TLS task
 *  will version to TLS_DEFAULT_VERSION (TLSv1 | SSLv3).
 *   
 * PARAMETERS
 *  ver         : [IN] Supported SSL/TLS versions
 *  side        : [IN] Client or server side
 *  mod_id      : [IN] Module id to receive TLS notifications
 *  app_str_id  : [IN] String id to display in MMI on error
 *
 * RETURN VALUES
 *  >=0                      : Created global context id (in kal_uint8)
 *  TLS_ERR_INVALID_PARAMS   : Invalid parameters
 *  TLS_ERR_NO_FREE_CTX      : All context are occupied
 *  TLS_ERR_PRNG_FAIL        : Set PRNG failed
 *  TLS_ERR_NO_MEMORY        : No memory available for allocating global context
 *  TLS_ERR_SSL_INTERNAL     : SSL layer internal error
 * SEE ALSO
 *   tls_delete_ctx().
 *****************************************************************************/
extern kal_int32
tls_new_ctx(tls_version_enum ver, tls_side_enum side,
            module_type mod_id, kal_uint16 app_str_id);



/*****************************************************************************
 * <GROUP TLS Context APIs>
 * FUNCTION
 *  tls_delete_ctx
 * DESCRIPTION
 *   Delete TLS global context.
 *
 *   This is a mandatory function.
 * 
 *   The settings are stored in the TLS context and applied to the new TLS
 *   connections created associated with it. Several TLS connection can be
 *   initiated by a TLS context. Therefore, as long as the TLS is not deleted,
 *   new TLS connection can be created with the TLS context.
 *   If application attempts to delete a global context with associate
 *   connection context, the associated connection context will be deleted as
 *   well.
 *  
 * PARAMETERS
 *   ctx_id   : [IN] Global context id to be freed
 * RETURN VALUES
 *   TLS_ERR_NONE            : Delete global context successfully
 *   TLS_ERR_INVALID_CONTEXT : Attempt to delete context with invalid id
 * SEE ALSO
 *   tls_new_ctx().
 *****************************************************************************/
extern kal_int32 tls_delete_ctx(kal_uint8 ctx_id);



/*****************************************************************************
 * <GROUP TLS Context APIs>
 * FUNCTION
 *   tls_set_ciphers
 * DESCRIPTION
 *   Set acceptable ciphersuites of the global context.
 *
 *   This is an optional function, if not called by application, defualt
 *   cipher suite is used.
 * 
 *   Refer to the sample code below to set cipher suites. If this API is not
 *   invoked, the ciphersuites is set as default value in TLS task when the
 *   first connection context associated to the global context is created.
 *   The cipher list in this example is current default ciphersuits applied.
 * PARAMETERS
 *   ctx_id   : [IN] Global context id to set cipher list
 *   ciphers  : [IN] List of supported cipher suites. Put the higher priority
 *                   cipher first.
 *   num      : [IN] Number of ciphes in the ciphers list
 * RETURN VALUES
 *   TLS_ERR_NONE               : Set ciphers successfully
 *   TLS_ERR_INVALID_CONTEXT    : Attempt to set cipher to context with invalid id
 *   TLS_ERR_EXCESS_MAX_CIPHERS : Number of ciphers larger than TLS_MAX_CIPHERS
 *   TLS_ERR_INVALID_CIPHER     : Given invalid cipher in the list
 *   TLS_ERR_SSL_INTERNAL       : SSL layer internal error
 * EXAMPLE
 * <code>
 *  tls_cipher_enum ciphers[] = {RC4_MD5,
 *                               RC4_SHA,
 *                               AES128_SHA,
 *                               EDH_RSA_DES_CBC3_SHA,
 *                               EDH_DSS_DES_CBC3_SHA,
 *                               DES_CBC3_SHA,
 *                               DES_CBC_SHA};
 *  rc = tls_set_ciphers(ctx, ciphers, sizeof(ciphers) / sizeof(tls_cipher_enum));
 * </code>
 *
 *****************************************************************************/
extern kal_int32
tls_set_ciphers(kal_uint8 ctx_id,
                const tls_cipher_enum ciphers[], const kal_int32 num);



/*****************************************************************************
 * <GROUP TLS Context APIs>
 * FUNCTION
 *   tls_set_verify
 * DESCRIPTION
 *   Set verification certificates and callback function.
 *
 *   This is an optional function, if not called by application, default
 *   trusted certificate pool and verify callback implemented by TLS is used
 *   by SSL library.
 *
 *   This is an optional API to configure the root certificate and the
 *   verification call back to verify the certificate provided by the peer.
 *
 *   If this function is not called by application, TLS loads all root
 *   certificates and use the default verification function implemented in SSL
 *   library to check the peer's certificate.
 *
 *   The callback argument is used for applications to change the default
 *   certificate verification behavior.
 *
 *   Application sets cert_num to TLS_ALL_ROOT_CERTS indicating it would like
 *   to set verification callback but loading all root certificates.
 *
 * PARAMETERS
 *   ctx_id       : [IN]  Global context id to configure verification mechanism.
 *   cert_id      : [IN]  List of root certificate ids returned from
 *                        certificate manager.
 *   cert_num     : [IN]  Number of certificates in the cert_id list .
 *   type         : [IN]  The certificate file encoding type.
 *   callback     : [IN]  Optional user-specified certificate verification
 *                        callback to change the default verification behavior.
 *   callback_arg : [IN]  User-specified argument passed to the application
 *                        verification callback.
 * RETURN VALUES
 *   TLS_ERR_NONE              : Set verification successfully.
 *   TLS_ERR_INVALID_CONTEXT   : Application gives a context with invalid id.
 *   TLS_ERR_INVALID_PARAMS    : Problems in the given parameters.
 *   TLS_ERR_INVALID_ROOT_CERT : Passed an invalid file id.
 *   TLS_ERR_INVALID_FILE_TYPE : Passed an invalid certificate file type.
 *   TLS_ERR_FILESYS           : Access file system error.
 *   TLS_ERR_NO_MEMORY         : No memory to complete this operation.
 *****************************************************************************/
extern kal_int32
tls_set_verify(kal_uint8 ctx_id,
               kal_uint32 cert_id[], kal_uint8 cert_num,
               tls_filetype_enum type,
               tls_cert_verify_callback callback, void *callback_arg);



/*****************************************************************************
 * <GROUP TLS Context APIs>
 * FUNCTION
 *   tls_set_client_auth
 * DESCRIPTION
 *   Set supported client authentication modes.
 *
 *   This is an optional function, an application should only invoke this
 *   function when it would like to perform client authentication.
 *
 *   Ref. Handler of APP_TLS_CLIENT_AUTH_IND in Sample Code chapter.
 * PARAMETERS
 *   ctx_id      : [IN] Global context id to set client authentication modes 
 *   modes       : [IN] List of client authentication modes
 *   num         : [IN] Number of given client authentication modes
 * RETURN VALUES
 *   TLS_ERR_NONE                  : Set client auth modes successfully
 *   TLS_ERR_INVALID_CONTEXT       : Application gives a context with invalid id
 *   TLS_ERR_INVALID_AUTH_MODE     : Invalid authentication mode is pased
 *                                   in the modes list
 *   TLS_ERR_EXCESS_MAX_AUTH_MODES : Num > TLS_MAX_CLIENT_AUTH_MODES
 *   TLS_ERR_SSL_INTERNAL          : SSL layer internal error
 * SEE ALSO
 *   tls_set_identity(), tls_set_null_client_auth().
 *****************************************************************************/
extern kal_int32
tls_set_client_auth(kal_uint8 ctx_id,
                    tls_auth_mode_enum modes[], kal_uint8 num);



/*****************************************************************************
 * <GROUP TLS Context APIs>
 * FUNCTION
 *   tls_set_passwd_callback
 * DESCRIPTION
 *   Set password callback functions for decrypting the privatekey file at
 *   CERTMAN, which is used for retrieving privatekey from certman.
 *
 *   This is an optional function, the password callback is only invoked
 *   when decrypting a private key file for loading identity.
 *   If the private key file is encrypted by user password, this function
 *   should be issued before tls_use_privatekey_file().
 *
 *   It might be practical to ask for the password once, then keep it in memory
 *   and use it several times. In this case, the password could be stored into
 *   the userdata storage and the password callback only returns the password
 *   already stored.
 * PARAMETERS
 *   ctx_id   : [IN] Global context id to set password callback
 *   callback : [IN] The password callback called when loading/storing
 *                   an encrypted certificate
 *   userdata : [IN] A pointer which will be provided to the password
 *                   callback on invocation.
 * RETURN VALUES
 *   TLS_ERR_NONE            : Set password callback successfully
 *   TLS_ERR_INVALID_CONTEXT : Attempt to set password callback to
 *                             invalid context
 *****************************************************************************/
extern kal_int32
tls_set_passwd_callback(kal_uint8 ctx_id,
                        tls_passwd_callback callback, void* userdata);



/*****************************************************************************
 * <GROUP TLS Context APIs>
 * FUNCTION
 *   tls_set_identity
 * DESCRIPTION
 *   Set local identity to be validated by peer.
 *
 *   This is an optional function for client application, client applicatoins
 *   commonly set identity when server request for client authentication.
 *   Server applications SHOULD ALWAYS load this for sending server certificate.
 *
 *   Ref. Handler of APP_TLS_CLIENT_AUTH_IND in Sample Code chapter.
 * PARAMETERS
 *   ctx_id   : [IN] Global context id to set local identity
 *   cert_id  : [IN] Personal certificate id
 * RETURN VALUES
 *   TLS_ERR_NONE                  : Set password callback successfully
 *   TLS_ERR_INVALID_PARAMS        : Problems in the given parameters
 *   TLS_ERR_INVALID_CONTEXT       : Attempt to set password callback to
 *                                   invalid context
 *   TLS_ERR_INVALID_PRIV_KEY      : Passed an invalid privatekey id
 *   TLS_ERR_INVALID_PERSONAL_CERT : Passed an invalid personal cert id
 *   TLS_ERR_INVALID_FILE_TYPE     : Passed an invalid certificate file type
 * SEE ALSO
 *   tls_set_client_auth(), tls_set_null_client_auth().
 *****************************************************************************/
extern kal_int32 tls_set_identity(kal_uint8 ctx_id, kal_uint32 cert_id);



#define _TLS_CONN_CTX_API_PROTOTYPES_

/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_new_conn
 * DESCRIPTION
 *   Create TLS connection context associated with given socket id.
 *
 *   This is a mandatory function.
 * PARAMETERS
 *   ctx_id  : [IN] Global context id storing the setting to create connection
 *                  ctx
 *   sock_id : [IN] Socket id to associate with the newly created connection ctx
 *   faddr   : [IN] Destination address to be connected to, used as session
 *                  database key
 * RETURN VALUES
 *   TLS_ERR_NONE            : Create connection ocntext successfully
 *   TLS_ERR_INVALID_CONTEXT : Given an invalid global context id
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_ALREADY         : The socket id is already associated to a ctx
 *   TLS_ERR_SSL_INTERNAL    : SSL layer internal error
 *   TLS_ERR_WAITING_CERT    : Loading certificate from CERTMAN, 
 *                             application should wait for
 *                             TLS_HANDSHAKE_READY notification
 * SEE ALSO
 *   tls_delete_conn().
 *****************************************************************************/
extern kal_int32 tls_new_conn(kal_uint8 ctx_id, kal_int8 sock_id, sockaddr_struct *faddr);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_delete_conn
 * DESCRIPTION
 *   Delete TLS connection context.
 * 
 *   This is a mandatory function.
 * PARAMETERS
 *   sock_id  : [IN] Socket id associated with the connection ctx to be freed
 * RETURN VALUES
 *   TLS_ERR_NONE            : Connection context deleted successfully
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 * SEE ALSO
 *   tls_new_conn().
 *****************************************************************************/
extern kal_int32 tls_delete_conn(kal_int8 sock_id);


/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_get_cipher
 * DESCRIPTION
 *   Get negotiated ciphersuite.
 * 
 *   This is an optional function.
 * PARAMETERS
 *   sock_id   : [IN] Socket id associate with the connection ctx to retrieve
 *                    negotiated ciphersuite
 *   cipher    : [OUT] Output parameter to returning ciphersuite
 * RETURN VALUES
 *   TLS_ERR_NONE            : Retrieve negotiated ciphersuite successfully
 *   TLS_ERR_NEED_HANDSHAKE  : Not handshake complete yet
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *****************************************************************************/
extern kal_int32 tls_get_cipher(kal_int8 sock_id, tls_ciphersuites_enum *cipher);


/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_get_cipher_info
 * DESCRIPTION
 *   Get negotiated cipher info.
 *
 *   This is an optional function.
 * PARAMETERS
 *   sock_id     : [IN]  Socket id associate with the connection ctx to retrieve
 *                       cipher info.
 *   cipher_info : [OUT] Output parameter to returning cipher info.
 * RETURN VALUES
 *   TLS_ERR_NONE            : Set the property successfully
 *   TLS_ERR_NEED_HANDSHAKE  : Not handshake complete yet
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *****************************************************************************/
extern kal_int32
tls_get_cipher_info(const kal_int8 sock_id, tls_cipher_info_struct *cipher_info);


/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_get_peer_cert
 * DESCRIPTION
 *   Get peer certificate.
 *
 *   This is an optional function.
 * PARAMETERS
 *   sock_id    : [IN]  Socket id associate with the connection ctx to retrieve
 *                      cipher info.
 *   cert       : [OUT] Output parameter to return peer certificate.
 * RETURN VALUES
 *   TLS_ERR_NONE            : Set the property successfully
 *   TLS_ERR_NEED_HANDSHAKE  : Not handshake complete yet
 *   TLS_ERR_INVALID_SOCK_ID : An invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *   TLS_ERR_SSL_INTERNAL    : Error in SSL library.
 *****************************************************************************/
extern kal_int32
tls_get_peer_cert(const kal_int8 sock_id, tls_cert_struct *cert);


/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_check_invalid_certificate
 * DESCRIPTION
 *   Enalbe/Disable checking invalid certificate from peer.
 *
 *   This is an optional function, applicatoin should invoke this function
 *   before performing handshake if user decide to continue the handshake when
 *   received an invalid certificate.
 *
 *   This API is used for application to skip checking an invalid certificate
 *   sent from peer. For the case that an invalid certificate received, user
 *   might decide to continue the connection, application can create a new
 *   connection context and invoke this API to skip checking received
 *   certificate and start handshake again. Disabling the invalid certificate
 *   verification will not trigger notification to bother user in the next
 *   round.
 *
 *   This function applies only to the given socket id. Refer to the sample
 *   code in app_tls_invalid_cert_hdlr().
 *
 * PARAMETERS
 *   sock_id : [IN] Socket id associate with the connection ctx to
 *                  enable/disable the invalid certificate check
 *   onoff   : [IN] Checking an invlid certificate or not
 * RETURN VALUES
 *   TLS_ERR_NONE            : Set the property successfully
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *****************************************************************************/
extern kal_int32 tls_check_invalid_cert(kal_int8 sock_id, kal_bool onoff);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_set_null_client_auth
 * DESCRIPTION
 *   Skip checking client authentication request.
 * 
 *   This is an optional function invoked when no personal certificate mets
 *   the critria in the client authentication request, but user decided
 *   to continue the handshake procedure.
 *
 *   When user attempts to connect to server with client authentication without
 *   loading local identity. This property is associated with connection
 *   context. Therefore, it must be invoked AFTER the connection context is
 *   created successfully.
 *
 *   This API should be invoked when application received client authentication
 *   indication with identity_id field set to 0.
 *   Refer to app_tls_client_auth_ind_hdlr.
 *
 *   Ref. Handler of APP_TLS_CLIENT_AUTH_IND in Sample Code chapter.
 * PARAMETERS
 *   sock_id    : [IN] Socket id associate with the connection ctx to skip
 *                     checking client authentication
 * RETURN VALUES
 *   TLS_ERR_NONE            : Set the property successfully
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 * SEE ALSO
 *   tls_set_client_auth(), tls_set_identity().
 *****************************************************************************/
extern kal_int32 tls_set_null_client_auth(kal_int8 sock_id);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_check_peer_name
 * DESCRIPTION
 *   Enalbe/Disable checking common name in the certificate from peer.
 * 
 *   This is an optional function to check the common namein certificate
 *   against the specified name.
 * PARAMETERS
 *   sock_id    : [IN] Socket id associate with the connection ctx to be checked
 *   name       : [IN] String of the server name
 * RETURN VALUES
 *   TLS_ERR_NONE            : Set the property successfully
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *****************************************************************************/
extern kal_int32 tls_check_peer_name(kal_int8 sock_id, const kal_char *const name);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_auto_rehandshake
 * DESCRIPTION
 *   Enalbe/Disable TLS auto rehandshake property.
 *   Set the property to enable/disable TLS to auto respond to a handshake
 *   request. 
 *
 *   This is an optional function to let TLS task help react to rehandshake
 *   request from peer. The default setting is off, therefore, application
 *   should call this API if it would like to let TLS accomplish the rehandshake
 *   automatically.
 * 
 *   For the case the TLS peer initiate a rehandshake, a TLS_ERR_REQ_HANDSHAKE
 *   will be returned by tls_read(). If the auto-rehandshake is not turned on,
 *   application must call tls_rehandshake() to finish this rehandshake request.
 *   Ref. TLS_READ section in Sample Code chapter.
 * 
 *   If auto-rehandshake is set, tls_read() rethrns TLS_ERR_REHANDSHAKING, and
 *   application should wait for the HANDSHAKE_DONE notification.
 * PARAMETERS
 *   sock_id   : [IN] Socket id associate with the connection ctx to set
 *                    the auto-rehandshake property
 *   onoff     : [IN] Switching auto-rehandshake on/off, KAL_TRUE will enable
 *                    auto rehandshake. 
 * RETURN VALUES
 *   TLS_ERR_NONE            : Set the property successfully
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 * SEE ALSO
 *   tls_rehandshake().
 *****************************************************************************/
extern kal_int32 tls_auto_rehandshake(kal_int8 sock_id, kal_bool onoff);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_handshake
 * DESCRIPTION
 *   Initiate TLS handshake process.
 *
 *   This is a mandatory function.
 * 
 *   This operation completes after a handshake procedure with the peer.
 *   Normally, a TLS_ERR_WOULDBLOCK will return, and after the procedure
 *   finished, TLS task sends a notification message to application.
 * PARAMETERS
 *   sock_id   : [IN] Socket id associate with the connection ctx to
 *                    perform handshake
 * RETURN VALUES
 *   TLS_ERR_NONE            : Handshake completes successfully
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_WOULDBLOCK      : The operation can not be complete currently,
 *                             please wait for notification indication
 *   TLS_ERR_ALREADY         : The handshake process is progressing
 *   TLS_ERR_HANDSHAKED      : tLS connection is handshaked.
 *                             tls_handshake() can only be called before
 *                             handshaked, application should call
 *                             tls_rehandshake() to initiate re-handshake
 *   TLS_ERR_SSL_INTERNAL    : SSL layer internal error
 *   TLS_ERR_OP_DENIED       : Operation denied for incorrect connection state
 *****************************************************************************/
extern kal_int32 tls_handshake(kal_int8 sock_id);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_rehandshake
 * DESCRIPTION
 *   Perfrom TLS rehandshake process.
 *
 *   This is an optional function to initiate re-handshake with peer.
 *
 *   Either nodes can initiate a rehandshake on a connected SSL/TLS connection.
 *   Applications performs a re-handshake by calling this API and wait for
 *   result notification.
 * PARAMETERS
 *   sock_id  : [IN] Socket id associate with the connection ctx to
 *                   perform re-handshake
 * RETURN VALUES
 *   TLS_ERR_NONE            : Re-handshake completes successfully
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_WOULDBLOCK      : The operation can not be complete currently,
 *                             please wait for notification indication
 *   TLS_ERR_ALREADY         : The re-handshake process is progressing
 *   TLS_ERR_SSL_INTERNAL    : SSL layer internal error
 *   TLS_ERR_OP_DENIED       : Operation denied for incorrect connection state
 * SEE ALSO
 *   tls_auto_rehandshake().
 *****************************************************************************/
extern kal_int32 tls_rehandshake(kal_int8 sock_id);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_read
 * DESCRIPTION
 *   Read data from established TLS connection.
 *
 *   This is a mandatory function to read data from TLS connection.
 * PARAMETERS
 *   sock_id  : [IN]  Socket id associate with the connection ctx to read data
 *   buf      : [OUT] Buffer to store received data
 *   len      : [IN]  Number of bytes to be read from the connection
 * RETURN VALUES
 *   >0                      : Bytes of successful read data
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *   TLS_ERR_WOULDBLOCK      : The lower-layer returns WOULDBLOCK
 *   TLS_ERR_HANDSHAKING     : The connection is handshaking
 *   TLS_ERR_REHANDSHAKING   : The connection is re-handshaking
 *   TLS_ERR_REHANDSHAKED    : Auto rehandshaked, application can read again
 *   TLS_ERR_REQ_HANDSHAKE   : Peer requestes re-handshake over a connected
 *                             connection
 *   TLS_ERR_IO_ERROR        : Lower-layer socket IO error
 *   TLS_ERR_NEED_HANDSHAKE  : Need to perform handshake before reading data
 *   TLS_ERR_REHANDSHAKE_REJ : Peer rejects our renegotiation request, but the
 *                             connection is still valid
 *   TLS_ERR_CONN_CLOSED     : Connection closed by peer
 *   TLS_ERR_SSL_INTERNAL    : SSL layer internal error
 *   TLS_ERR_OP_DENIED       : Operation denied for incorrect connection state
 *****************************************************************************/
extern kal_int32 tls_read(kal_int8 sock_id, void* buf, kal_int32 len);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_write
 * DESCRIPTION
 *   Write data to established TLS connection.
 *
 *   This is a mandatory function to write data to TLS connection.
 * PARAMETERS
 *   sock_id  : [IN] Socket id associate with the connection ctx to write data
 *   buf      : [IN] Buffer storing the outgoing data
 *   len      : [IN] Number of bytes to be write to the connection
 * RETURN VALUES
 *   >0                      : Bytes of successful written data
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *   TLS_ERR_WOULDBLOCK      : The lower-layer returns WOULDBLOCK
 *   TLS_ERR_HANDSHAKING     : The connection is handshaking
 *   TLS_ERR_REHANDSHAKING   : The connection is re-handshaking
 *   TLS_ERR_IO_ERROR        : Lower-layer socket IO error
 *   TLS_ERR_REHANDSHAKE_REJ : Peer rejects our renegotiation request, but the
 *                             connection is still valid
 *   TLS_ERR_CONN_CLOSED     : Connection closed by peer
 *   TLS_ERR_NEED_HANDSHAKE  : Need to perform handshake before reading data
 *   TLS_ERR_SSL_INTERNAL    : SSL layer internal error
 *   TLS_ERR_OP_DENIED       : Operation denied for incorrect connection state
 *****************************************************************************/
extern kal_int32 tls_write(kal_int8 sock_id, const void* buf, kal_int32 len);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_shutdown
 * DESCRIPTION
 *   Close TLS connection.
 *
 *   This is a mandatory function to shutdown the TLS.
 *   It sends a close_notify to the peer. This message notifies the recipient
 *   that the sender will not send any more messages on this connection.
 * PARAMETERS
 *   sock_id  : [IN] Socket id associate with the connection ctx to be closed
 * RETURN VALUES
 *   TLS_ERR_NONE            : Close the TLS connection successfully
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *   TLS_ERR_SSL_INTERNAL    : SSL layer internal error
 *   TLS_ERR_OP_DENIED       : Operation denied for incorrect connection state
 *****************************************************************************/
extern kal_int32 tls_shutdown(kal_int8 sock_id);



/*****************************************************************************
 * <GROUP TLS Connection APIs>
 * FUNCTION
 *   tls_connect
 * DESCRIPTION
 *   Establish TCP connection and perform TLS handshake.
 *
 *   This is an optional function to establish TCP connection and then
 *   perform TLS handshake.
 *
 *   This function is a compound command of soc_connent() and tls_handshake().
 *   Application can call tls_connect() and wait for a HANDSHAKE_DONE
 *   notification.
 *
 * PARAMETERS
 *   sock_id   : [IN] Socket id associate with the connection ctx to set up
 *                    connection and initiate TLS handshake
 *   addr      : [IN] Remot socket address including IP address and port number.
 * RETURN VALUES
 *   TLS_ERR_NONE            : The action completes without any error
 *   TLS_ERR_INVALID_SOCK_ID : Given an invalid socket id
 *   TLS_ERR_NO_CONN_CTX     : No associated connection context
 *   TLS_ERR_WOULDBLOCK      : The lower-layer returns WOULDBLOCK
 *   TLS_ERR_SOC_INTERNAL    : Socket layer internal error
 *   TLS_ERR_SSL_INTERNAL    : SSL layer internal error
 *   TLS_ERR_OP_DENIED       : Operation denied for incorrect connection state
 *****************************************************************************/
extern kal_int32 tls_connect(kal_int8 sock_id, sockaddr_struct *addr);



/*****************************************************************************
 * <GROUP Utility Functions>
 * FUNCTION
 *   tls_log_plaintext
 *
 *   This is an optional function.
 * DESCRIPTION
 *   Enable/disable plaintext logging mechanism, default if off.
 *
 *   This API is used designed for debugging SSL/TLS applications.
 *   Because all applications over SSL/TLS send and receive encrypted data in
 *   the network, application can invoke this API to turn on the logging
 *   mechanism to check the plaintext content in the application layer.
 *
 *   For security consideration, This API will only be effective when the
 *   global compile __PRODUCTION_RELEASE__ is not defined.
 *
 *   As long as this API is invoked to turn on the logging mechanism, all data
 *   flow over SSL/TLS in the system will be logged.
 *
 *   The message will be logged as MSG_ID_APP_SSL_DATA_INPUT_MSG and
 *   MSG_ID_APP_SSL_DATA_OUTPUT_MSG to MOD_SOC.
 *
 *   Note:
 *     1. the ILMs only be sent when a successful TLS read()/write() is invoked.
 *     2. the ret field in the message is the number of data been read/write.
 *     3. the len field in the message is the peer buffer allocated for
 *        sending/recving data, if the buffer called in the API is too large
 *        (> 2048-peer_buff_struct), multiple messages will be sent in the log
 *     4. the mf field in the message indicates whether there are more fragments
 *        for this read/write operation
 * PARAMETERS
 *   onoff  : [IN] Turning on/off the plaintext logging mechanism
 * RETURNS
 *   This function returns no diagnostic information.
 *****************************************************************************/ 
void tls_log_plaintext(const kal_bool onoff);


#endif /* !_TLS_API_H */


