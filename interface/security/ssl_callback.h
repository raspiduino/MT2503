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
 *   ssl_callback.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains callback type definitions of SSL API.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SSL_CALLBACK_H
#define _SSL_CALLBACK_H

#include "kal_general_types.h"
#include "ssl_structs.h"
#include "ssl_enums.h"
 
/*****************************************************************************
 * <GROUP Callback Functions>
 *
 * FUNCTION
 *  ssl_password_cb
 *
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
 *   sec_ssl_ctx_set_default_passwd_cb
 * EXAMPLE
 *   <code>
 *   int pem_passwd_cb(char *buf, int size, kal_int32 rwflag, void *password)
 *   {
 *        if (!password) return 0;
 *
 *        strncpy(buf, (char *)password, size);
 *        buf[size - 1] = '\0';
 *        return strlen(buf);
 * }
 * </code>
 *****************************************************************************/
typedef kal_int32 (*ssl_password_cb)(kal_char *buf, kal_int32 size,
                                     kal_int32 rwflag, void *userdata);


/*****************************************************************************
 * <GROUP Callback Functions>
 * Function
 *   sec_ssl_cert_verify_callback
 * DESCRIPTION
 *   Prototype of verification function which is called whenever a certificate
 *   is verified during a SSL/TLS handshake.
 * PARAMETERS
 *   x509    : [IN] A data structure holding cerficiate information and
 *                  verification result.
 *   arg     : [IN] User-specified pointer.
 * RETURN VALUES
 *   1 : Application verifies the certification successfully.
 *   0 : Application verifies the certification failed.
 * SEE ALSO
 *  sec_ssl_ctx_set_cert_verify_callback
 * EXAMPLE
 * <code>
 * </code>
 *****************************************************************************/
typedef kal_int32 (*sec_ssl_cert_verify_callback)(sec_x509_store_ctx *x509, void *arg);


/*****************************************************************************
 * <GROUP Callback Functions>
 * Function
 *  sec_ssl_read_cb
 * DESCRIPTION
 *   The callback function for library to transfer data on an SSL connection.
 * PARAMETERS
 *   buf      : [OUT] Buffer for reading data.
 *   buflen   : [IN]  Size of buffer for reading in bytes.
 *   io_state : [IN]  Set by SSL library if the outgoing message is a SSL
 *                    "Finished" message.
 *   conn_ref : [IN]  Optional user reference parameter
 * RETURN VALUES
 *   >= 0                    : Number of bytes read successfully.
 *   SEC_ERROR_WOULD_BLOCK   : The I/O operation cannot be completed right away.
 *   SEC_ERROR_IO            : I/O error.
 *   SEC_ERROR_CONNECTION_CLOSED_GRACEFUL : I/O is closed, override the goodbye kiss.
 * SEE ALSO
 *  sec_ssl_set_io_func
 * EXAMPLE
 * <code>
 * </code>
 *****************************************************************************/
typedef
kal_int32 (*sec_ssl_read_cb) (
    const kal_char *buf,	    /* buffer for storing incoming data */
    const kal_uint32 buflen,	/* buffer for storing incoming data */
    kal_uint8 io_state,
    void *const conn_ref
);


/*****************************************************************************
 * <GROUP Callback Functions>
 * Function
 *   sec_ssl_write_cb
 * DESCRIPTION
 *   The callback function for library to transfer data on an SSL connection.
 * PARAMETERS
 *   buf       : [IN] Buffer holds data to be written.
 *   buflen    : [IN] Size of buffer for written in bytes.
 *   io_state  : [IN] Set by SSL library if the outgoing messsage is a SSL
 *                    "Finished" message.
 *   connRef   : [IN] Optional user reference parameter.
 * RETURN VALUES
 *   >= 0                    : Number of bytes written successfully.
 *   SEC_ERROR_WOULD_BLOCK   : The I/O operation cannot be completed right away.
 *   SEC_ERROR_IO            : I/O error.
 * SEE ALSO
 *  sec_ssl_set_io_func
 * EXAMPLE
 * <code>
 * </code>
 *****************************************************************************/
typedef
kal_int32 (*sec_ssl_write_cb) (
    const kal_char *buf,	    /* buffer for storing outgoing data */
    const kal_uint32 buflen,	/* buffer for storing outgoing data */
    kal_uint8 io_state,
    void *const conn_ref
);


/*****************************************************************************
 * <GROUP Callback Functions>
 * Function
 *  sec_ssl_alert_func
 * DESCRIPTION
 *   Application handler of handling received alert message from peer.
 * PARAMETERS
 *   conn_ctx    : [IN] SSL connection context received SSL alert
 *   level       : [IN] Alert level in the received alert message.
 *   code        : [IN] Alert description in the received alert message.
 *   alert_ref   : [IN] User-specified pointer.
 * RETURNS
 *   This function should always return SEC_ERROR_NONE to let library
 *   clean up the connection gracefully.
 * SEE ALSO
 *  sec_ssl_ctx_set_alert_func
 *****************************************************************************/
typedef
kal_int32 (*sec_ssl_alert_func)(
    ssl_conn *conn_ctx,
    const ssl_alert_level level,
    const ssl_alert_desc code,
    void *const alert_ref
);

#endif /* !_SSL_CALLBACK_H */


