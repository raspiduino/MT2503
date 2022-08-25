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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   tls_sap.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   tls related message identity definition
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*---------------TLS_MSG_CODE_BEGIN---------------------------*/
#ifdef __BUILD_DOM__
/*********************************************************************
 * <GROUP Messages> 
 *
 * Messages of TLS SAP
 *********************************************************************/
typedef enum {
#endif /* __BUILD_DOM__ */

    /* app_tls_notify_ind_struct,
       Notification to application for some events, e.g., SSL connection is
       established or closed, etc. 

       Application verifies the event type and calls the corresponding handler:
       1. <b>TLS_HANDSHAKE_READY</b> is an indication of the result of 
          connection context creation procedure. tls_new_conn() might return
          TLS_ERR_WAITING_CERT for loading certificates and waiting response
          from MOD_CERTMAN. After received this message, application can then
          call tls_handshake() to start TLS handshake procedure.
       2. <b>TLS_HANDSHAKE_DONE</b> is an indication of the handshake result
          procedure. Application can call tls_read() to receive data from or
          call tls_write() to send data to the peer.
       3. For <b>TLS_READ</b>, application should call tls_read() repeatedly
          until TLS_ERR_WOULDBLOCK returned.
       4. For <b>TLS_WRITE</b>, application is allowed to transmit the holding
          data by calling tls_write().
       5. For <b>TLS_CLOSE</b>, application should call tls_delete_conn() to
          de-associate the connection with a socket id.

       Direction: TLS -> APP
       Local parameter: app_tls_notify_ind_struct
       Peer buffer: None 
     */
    MSG_ID_APP_TLS_NOTIFY_IND = MSG_ID_TLS_CODE_BEGIN,


    /* app_tls_alert_ind_struct,
       Notifications sent to application for TLS alert events. This message
       is sent when an alert happened in the library. RFC 4346 claims that
       "alert message with a level of fatal result in the immediate termination
       of the connection", therefore, application received a indication with
       level set to TLS_ALERT_LV_FATAL should terminate the connection
       immediately.

       Direction: TLS -> APP
       Local parameter: app_tls_alert_ind_struct
       Peer buffer: None 
     */
    MSG_ID_APP_TLS_ALERT_IND,

    /* app_tls_invalid_cert_ind_struct,
       Notifications sent to application for the result of user decision to
       the received invalid certificate. For receiving an invalid certificate,
       user could either
       a) reject the connection,
       b) accept the invalid certificate only for this session,
       c) install the invalid certificate to trust it forever.

       Direction: TLS -> APP
       Local parameter: app_tls_invalid_cert_ind_struct
       Peer buffer: None 
     */
    MSG_ID_APP_TLS_INVALID_CERT_IND,

    /* app_tls_client_auth_ind_struct,
       Notifications sent to application for sending the result of user
       decision of handling TLS client authentication request from peer.
       On receiving an client authentication, the server sends us
       a) acceptable client authentication mode, and
       b) a list of trusted issuers. Certificate Manager will be responsible
          for filtering all personal certificate in the system meet the
          criteria, the filtered list could be empty.
       User can decide to
       a) decline the connection,
       b) use a filtered personal certificate to proceed the connection, or
       c) try to continue the connection without loading personal certificate.

       Direction: TLS -> APP
       Local parameter: app_tls_client_auth_ind_struct
       Peer buffer: None 
     */
    MSG_ID_APP_TLS_CLIENT_AUTH_IND,

    MSG_ID_TLS_CODE_END = MSG_ID_APP_TLS_CLIENT_AUTH_IND,

#ifdef __BUILD_DOM__
} sap_tls_enum;
#endif /* __BUILD_DOM__ */
/*---------------TLS_MSG_CODE_END---------------------------*/

