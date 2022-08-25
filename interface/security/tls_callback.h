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
 *   tls_callback.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains callback prototypes of TLS
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _TLS_CALLBACK_H_
#define _TLS_CALLBACK_H_

#ifndef _SSL_API_H
#include "ssl_api.h"
#endif /* !_SSL_API_H */

#ifndef _TLS2APP_STRUCT_H_
#include "tls2app_struct.h"
#endif /* _TLS2APP_STRUCT_H_ */

#include "kal_general_types.h"
 
/*****************************************************************************
 * <GROUP Structures>
 *
 * A data structure storing information of cerficiate from peer and
 * the verify result.
 *****************************************************************************/
typedef struct {
    kal_int8         sock_id;      /* Socket id of the SSL connection. */
    tls_cert_struct  **cert_chain; /* Certificate chain sent from peer in array.
                                      Application can extracts the certificate
                                      chain from this parameter if needed in
                                      tls_cert_verify_callback(). */
    kal_uint32       *warnings;    /* Warning list of each cert in cert_chain. */
    kal_int32        error;        /* Certificate validation result. */
} tls_x509_struct;


/*****************************************************************************
 * <GROUP Callback Functions>
 *
 * Function
 *   tls_cert_verify_callback
 * DESCRIPTION
 *   Prototype of verification function which is called whenever a certificate
 *   is verified during a SSL/TLS handshake.
 * PARAMETERS
 *   x509     : [IN] A data structure holding cerficiate information and
 *                   verification result.
 *   arg      : [IN] User-specified pointer to be passed to this callback.
 * RETURN VALUES
 *   TLS_ERR_NONE          : If application want to override the validation
 *                           error and continue normally.
 *   TLS_ERR_CERT_VALIDATE : If application want the library to abort the 
 *                           handshake process.
 * SEE ALSO
 *   tls_set_verify()
 * EXAMPLE
 *   <code>
 *   kal_int32 app_cert_verify_callback(tls_x509_struct* x509, void* arg)
 *   {
 *       int i = 0;
 *       kal_uint32 cert_len = 0;
 *       kal_uint8 *cert_data = NULL;
 *       kal_uint32 cert_warn = 0;
 *
 *       if (x509->sock_id != valid_socket_id)
 *           error_handling();
 *
 *       for (x509->cert_chain[i]; x509->cert_chain[i]; i++)
 *       {
 *            cert_len = x509->cert_chain[i].len;
 *            cert_data = x509->cert_chain[i].data;
 *            cert_warn = x509->warnings[i];
 *            process_cert(cert_len, cert_data, cert_warn);
 *       }
 *
 *       if (force_success)
 *           return TLS_ERR_NONE;
 *       else
 *           return TLS_ERR_CERT_VALIDATE;
 *   }
 *   </code>
 *****************************************************************************/
typedef
kal_int32 (*tls_cert_verify_callback)(tls_x509_struct* x509, void* arg);



/*****************************************************************************
 * <GROUP Callback Functions>
 *
 * Function
 *   tls_passwd_callback
 * DESCRIPTION
 *   The callback function provided by application to return password for
 *   decrypting the private key file.
 * PARAMETERS
 *   buf      : [OUT] Buffer to return the password.
 *   size     : [IN]  Size of the allocated buffer size when the TLS library
 *                    calls this callback function.
 *   rwflag   : [IN]  The callback is used for reading/decryption (rwflag=0),
 *                    or writing/encryption (rwflag=1).
 *   userdata : [IN]  User-specified pointer to be passed to this callback.
 * RETURNS
 *   Return the actual occupied bytes of the password.
 * SEE ALSO
 *   tls_set_passwd_callback()
 * 
 * EXAMPLE
 *   TLS library calls this callback function as below:
 *   <code>
 *   passwd = malloc(SSL_PASSWORD_BUF_LEN);
 *   passwd_len = ctx->passwd_cb(passwd, SSL_PASSWORD_BUF_LEN, 0,
 *                               ctx->passwd_callback_userdata);
 *   </code>
 *
 *   Application can implement this callback function if the password is
 *   stored in app_passwd:
 *   <code>
 *   int pem_passwd_cb(char *buf, int size, int rwflag, void *password)
 *   {
 *       strncpy(buf, (char *)(app_passwd), size);
 *       buf[size - 1] = '\0';
 *       return(strlen(buf));
 *   }
 *   </code>
 *****************************************************************************/
typedef kal_int32 (*tls_passwd_callback)(kal_char* buf, kal_int32 size,
                                         kal_int32 rwflag, void* userdata);


#endif /* !_TLS_CALLBACK_H_ */


