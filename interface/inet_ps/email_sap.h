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
#ifdef __BUILD_DOM__
/***********************************
* <GROUP  Messages>        
*
* Email SAP PRIMITIVE
 ********************************/
typedef enum {
#endif

    MSG_ID_EMAIL_PS_SAP_DEFINE_BEGIN = MSG_ID_EMAIL_CODE_BEGIN, /* Begin */

    MSG_ID_EMAIL_PS_CREATE_INSTANCE_REQ, /* This request is to create one instance of email protocol 

                                            Direction: MMI-> EMAIL
                                            Local parameter: email_ps_create_instance_req_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_CREATE_INSTANCE_RSP, /* This is the response for the email protocol instance create.

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_create_instance_rsp_struct
                                            Peer buffer: None */

    MSG_ID_EMAIL_PS_DESTROY_INSTANCE_REQ,/* This request is to destory the instance of email protocol 

                                            Direction: MMI -> EMAIL
                                            Local parameter: email_ps_destroy_instance_req_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_DESTROY_INSTANCE_RSP, /* This is the response for email protocol instance destroy.

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_create_instance_rsp_struct
                                            Peer buffer: None */  

    MSG_ID_EMAIL_PS_CONN_REQ,             /* This request is to connect to server including capability negotiation 

                                            Direction: MMI -> EMAIL
                                            Local parameter: email_ps_conn_req_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_CONN_RSP,             /* This request is the response for connect server 

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_conn_rsp_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_CONN_IND,             /* This is the connecting progress indication, see email_ps_connect_ind_enum 

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_conn_ind_struct
                                            Peer buffer: None */

    MSG_ID_EMAIL_PS_DISCONN_REQ,          /* This request is to disconnect from server

                                            Direction: MMI -> EMAIL
                                            Local parameter: email_ps_disconn_req_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_DISCONN_RSP,         /* This is the response for disconnect from server 

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_disconn_rsp_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_DISCONN_IND,         /* This is the netwokr disconnected indiaction, including network broken in IDLE or shuting down network after timeout, abort action etc

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_disconn_ind_struct
                                            Peer buffer: None */

    MSG_ID_EMAIL_PS_AUTH_REQ,            /* This request is to authenicate to server with username & password, this is optional command for SMTP protocol.

                                            Direction: MMI -> EMAIL
                                            Local parameter: email_ps_auth_req_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_AUTH_RSP,            /* This is the response for authenicate to server 

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_auth_rsp_struct
                                            Peer buffer: None */

    MSG_ID_EMAIL_PS_ABORT_REQ,          /* This request is to abort current action. This command will cause the network be shutdown immediately, and a disconnect indication will be sent.

                                            Direction: MMI -> EMAIL
                                            Local parameter: email_ps_abort_req_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_ABORT_RSP,          /* This is the response for abort current action.

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_abort_rsp_struct
                                            Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_SEND_REQ,       /* This request is to send rfc822 format message to server.

                                            Direction: MMI -> EMAIL
                                            Local parameter: email_ps_msg_send_req_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_SEND_RSP,       /* This is the response for send rfc822 format message to server.

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_msg_send_rsp_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_SEND_IND,       /* This is the send progress indication in periodic

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_msg_send_ind_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_SEND_CNF,       /* This is the send progress confirm, SMTP will not send next progress indication until receive last's confirm.

                                            Direction: MMI -> EMAIL
                                            Local parameter: email_ps_msg_send_cnf_struct
                                            Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_STATE_REQ,      /* This request is to get the total message number of mailbox without opening it.

                                            Direction: MMI -> EMAIL
                                            Local parameter: email_ps_fld_state_req_struct
                                            Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_STATE_RSP,     /* This is the response for get the total message number of mailbox.
                                           This command is for IMAP4 only

                                            Direction: EMAIL -> MMI
                                            Local parameter: email_ps_fld_state_rsp_struct
                                            Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_OPEN_REQ,      /* This request is to open folder.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_fld_open_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_OPEN_RSP,      /* This is the response for open folder

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_fld_open_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_CLOSE_REQ,     /* This request is to close folder, all messages with \delete flag will be expunged.
                                          This command is for IMAP4 only.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_fld_close_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_CLOSE_RSP,     /* This is the response for close folder

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_fld_close_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_LIST_REQ,     /* This request is to list folders in server.
                                         This command is for IMAP4 only.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_fld_list_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_LIST_RSP,     /* This is the response for list folders.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_fld_list_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_SUBSCRIBE_REQ,/* This request is to subscribe folder in server.
                                         This command is for IMAP4 only.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_fld_subscribe_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_SUBSCRIBE_RSP,/* This is the response for subscribe folder.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_fld_subscribe_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_UNSUBSCRIBE_REQ,/* This request is to unsubscribe folder in server.
                                         This command is for IMAP4 only.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_fld_unsubscribe_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_UNSUBSCRIBE_RSP,/* This is the response for unsubscribe folder.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_fld_unsubscribe_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_CREATE_REQ,/* This request is to create new folder in server.
                                         This command is for IMAP4 only.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_fld_create_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_CREATE_RSP,/* This is the response for create new folder.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_fld_create_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_DELETE_REQ,/* This request is to delete folder in server.
                                         This command is for IMAP4 only.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_fld_delete_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_DELETE_RSP,/* This is the response for deletefolder.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_fld_delete_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_FLD_RENAME_REQ,/* This request is to rename folder in server.
                                         This command is for IMAP4 only.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_fld_rename_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_FLD_RENAME_RSP,/* This is the response for rename folder.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_fld_rename_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_SIZE_LIST_REQ,/* This request is to list messages size.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_size_list_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_SIZE_LIST_RSP,/* This is the response for list messages size.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_size_list_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_UID_LIST_REQ,/* This request is to list messages UID.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_uid_list_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_UID_LIST_RSP,/* This is the response for list messages UID.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_uid_list_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_FETCH_REQ,/* This request is to fetch message including message header, whole message or IMAP EVENLOPMENT, BODYSTRUCTURE.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_fetch_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_FETCH_RSP,/* This is the response for list fetch message.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_fetch_rsp_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_FETCH_IND,/* This is the indication of fetch message.
                                     User must confirm this indication, otherwise, no following indication will be issued again.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_fetch_ind_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_FETCH_CNF,/* This is the confirm of message indication.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_fetch_cnf_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_DELETE_REQ,/* This request is to delete message.
                                      This request is only for POP3.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_delete_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_DELETE_RSP,/* This is the response for delete message.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_delete_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_FLAGS_GET_REQ,/* This request is to get messages flag.
                                         This request is only for IMAP4.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_flags_get_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_FLAGS_GET_RSP,/* This is the response for get messages flag.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_flags_get_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_FLAGS_SET_REQ,/* This request is to set messages flag.
                                         This request is only for IMAP4.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_flags_set_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_FLAGS_SET_RSP,/* This is the response for set messages flag.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_flags_set_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_APPEND_REQ,/* This request is to append message to server.
                                         This request is only for IMAP4.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_append_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_APPEND_RSP,/* This is the response for append message to server.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_append_rsp_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_APPEND_IND,/* This is the indication of append message.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_append_ind_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_APPEND_CNF,/* This is the confirmation of append message.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_append_cnf_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_COPY_REQ,/* This request is to copy message(s) to folder in server.
                                         This request is only for IMAP4.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_copy_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_COPY_RSP,/* This is the response for copy message(s).

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_copy_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_SEARCH_REQ,/* This request is to search messages in server.
                                         This request is only for IMAP4.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_search_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_SEARCH_RSP,/* This is the response for search message.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_search_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_MSG_EXPUNGE_REQ,/* This request is to expunge messages marked as deleted.
                                         This request is only for IMAP4.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_msg_expunge_req_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_MSG_EXPUNGE_RSP,/* This is the response for expunge message.

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_msg_expunge_rsp_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_IMAP_PUSH_IND,/* This is the indication of push (new message arrives, message flags changed, message deleted).

                                           Direction: EMAIL -> MMI
                                           Local parameter: email_ps_imap_push_ind_struct
                                           Peer buffer: None */
    MSG_ID_EMAIL_PS_IMAP_PUSH_CNF,/* This is the confirmation of IMAP push.

                                           Direction: MMI -> EMAIL
                                           Local parameter: email_ps_imap_push_cnf_struct
                                           Peer buffer: None */

    MSG_ID_EMAIL_PS_SAP_DEFINE_END,/* Not used, only for check */

#ifdef __BUILD_DOM__
}sap_filename_enum ; 
#endif
