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
 *  EmailSrvGport.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to define the Email service functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef EMAILSRVGPORT_H
#define EMAILSRVGPORT_H

#include "customer_ps_inc.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_utility_gprot.h"

/* The Email account id type */
typedef U32     EMAIL_ACCT_ID;

/* The Email folder id type */
typedef U32     EMAIL_FLDR_ID;

/* The Email message id type */
typedef U32     EMAIL_MSG_ID;

/* The Email message state type */
typedef U32     EMAIL_MSG_STATE;

/* The Email message attach id type */
typedef U64     EMAIL_ATTCH_ID;

/* The asynchronous request id type */
typedef U32     EMAIL_REQ_ID;

/* The Email service handle type */
typedef U32     EMAIL_SRV_HANDLE;

/* The Email account handle type */
typedef U32     EMAIL_ACCT_HANDLE;

/* The Email folder handle type */
typedef U32     EMAIL_FLDR_HANDLE;

/* The Email message handle type */
typedef U32     EMAIL_MSG_HANDLE;

/* The Email OTAP handle type */
typedef U32     EMAIL_OTAP_HANDLE;

/* The invalid Email account id */
#define EMAIL_ACCT_INVALID_ID           (0)

/* The invalid Email folder id */
#define EMAIL_FLDR_INVALID_ID           (0)

/* The invalid Email message id */
#define EMAIL_MSG_INVALID_ID            (0)

/* The invalid Email attachment id */
#define EMAIL_ATTCH_INVALID_ID          (0)

/* The invalid Email request id */
#define EMAIL_REQ_INVALID_ID            (0)

/* The invalid Email service handle */
#define EMAIL_SRV_INVALID_HANDLE        (0)

/* The invalid Email account handle */
#define EMAIL_ACCT_INVALID_HANDLE       (0)

/* The invalid Email folder handle */
#define EMAIL_FLDR_INVALID_HANDLE       (0)

/* The invalid Email message handle */
#define EMAIL_MSG_INVALID_HANDLE        (0)

/* The max attachment filename length */
#define EMAIL_ATTCH_FILE_NAME_LEN       (40)

/* The max folder name length */
#define SRV_EMAIL_FLDR_NAME_LEN         (128)

/* The max text length when listing messages */
#ifdef __COSMOS_MMI_PACKAGE__
#define SRV_EMAIL_FLDR_MSG_LIST_TEXT_LEN    (140)
#else
#define SRV_EMAIL_FLDR_MSG_LIST_TEXT_LEN    (40)
#endif /* __COSMOS_MMI_PACKAGE__ */

/* The max MSG number in each folder */
#ifdef __MMI_EMAIL_SUPPORT_1000_MAILS__
#define SRV_EMAIL_GLOBAL_MAX_MSG_NUM    (1000)
#else
#define SRV_EMAIL_GLOBAL_MAX_MSG_NUM    (100)
#endif

/* The max file name length (not include null) */
#define SRV_EMAIL_MAX_FILE_NAME_LEN     (260)

/* The max account name length */
#define SRV_EMAIL_MAX_ACCT_NAME_LEN     (30)

/* The max username length */
#define SRV_EMAIL_MAX_USERNAME_LEN      (MMI_EMAIL_MAX_ADDR_LEN)

/* The max password length */
#define SRV_EMAIL_MAX_PASSWORD_LEN      (50)

/* The max server name length */
#define SRV_EMAIL_MAX_SERVER_NAME_LEN   (50)

/* The max folder name length */
#define SRV_EMAIL_MAX_FOLDER_NAME_LEN   (128)

/* The max display name length */
#define SRV_EMAIL_MAX_DISP_NAME_LEN     (15)

/* The max email address length */
#define SRV_EMAIL_MAX_ADDR_LEN          (MMI_EMAIL_MAX_ADDR_LEN)

/* The MD5 digest length */
#define SRV_EMAIL_MD5_DIGEST_LEN        (16)

/* The CID maximum length */
#define SRV_EMAIL_CID_MAX_LEN           (128)

/* The major error type: Email related errors */
#define SRV_EMAIL_MAIL_ERROR            (-1)

/* The major error type: Socket related errors */
#define SRV_EMAIL_SOCKET_ERROR          (-2)

/* The major error type: File system related errors */
#define SRV_EMAIL_FS_ERROR              (-3)

/* The major error type: SSL/TLS related errors */
#define SRV_EMAIL_TLS_ERROR             (-4)

/* The major error type: DRM related errors */
#define SRV_EMAIL_DRM_ERROR             (-5)

/* The Email message flag type */
typedef U8 EMAIL_MSG_FLAG;

/* The seen flag of the Email message */
#define EMAIL_MSG_FLAG_SEEN             (0x01)

/* The answered flag of the Email message */
#define EMAIL_MSG_FLAG_ANSWERED         (0x02)

/* The flagged flag of the Email message */
#define EMAIL_MSG_FLAG_FLAGGED          (0x04)

/* The Email message priority type */
typedef U8 EMAIL_MSG_PRIO;

/* The Email message priority: Medium */
#define EMAIL_MSG_PRIO_MED              (0)

/* The Email message priority: Low */
#define EMAIL_MSG_PRIO_LOW              (1)

/* The Email message priority: High */
#define EMAIL_MSG_PRIO_HIGH             (2)

/* The Email message plain text download size for IMAP4 */
#define EMAIL_MSG_TEXT_DOWNLOAD_SIZE_FOR_IMAP4 (200)

/* The Email message text download size for POP3  */
#define EMAIL_MSG_TEXT_DOWNLOAD_SIZE_FOR_POP3 (10) //           (2)

/* Email service operation result enum */
typedef enum
{
    SRV_EMAIL_RESULT_SUCC                           = 0,    /* Success */
    SRV_EMAIL_RESULT_FAIL                           = 1,    /* Fail */
    SRV_EMAIL_RESULT_WOULDBLOCK                     = 2,    /* The operation will be wouldblock */
    SRV_EMAIL_RESULT_INPROGRESS                     = 3,    /* Any other operation is in progress */
    SRV_EMAIL_RESULT_FS_ERROR                       = 4,    /* file system error */
    SRV_EMAIL_RESULT_NO_MEMORY                      = 5,    /* failed to allocate memory */
    SRV_EMAIL_RESULT_NO_MORE_RESULT                 = 6,    /* no more result */
    SRV_EMAIL_RESULT_ACCT_ID_REACH_MAX_NUM          = 7,    /* account id reach max number */
    SRV_EMAIL_RESULT_FLDR_ID_REACH_MAX_NUM          = 8,    /* folder id reach max number */
    SRV_EMAIL_RESULT_MSG_REACH_MAX_NUM              = 9,    /* msg in one box can not be more than SRV_EMAIL_GLOBAL_MAX_MSG_NUM */
    SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE             = 10,   /* storage is not available now */
    SRV_EMAIL_RESULT_COMP_INSTANCE_REACH_MAX_NUM    = 11,   /* composer's instance reach max num */
    SRV_EMAIL_RESULT_COMP_HANDLE_INVALID            = 12,   /* composer's handle is invalid */
    SRV_EMAIL_RESULT_COMP_BUSY                      = 13,   /* composer's state, an object have already been started. */
    SRV_EMAIL_RESULT_CREATE_INSTANCE_FAIL           = 14,   /* The instance limitation is reached */
    SRV_EMAIL_RESULT_INCOMPLETE_ACCT                = 15,   /* The account is incomplete */
    SRV_EMAIL_RESULT_INVALID_ACCT                   = 16,   /* The account is invalid */
    SRV_EMAIL_RESULT_INVALID_MSG                    = 17,   /* The message is invalid */
    SRV_EMAIL_RESULT_INVALID_FLDR                   = 18,   /* The folder is invalid */
    SRV_EMAIL_RESULT_INVALID_HANDLE                 = 19,   /* The handle is invalid */
    SRV_EMAIL_RESULT_INVALID_PARAMETER              = 20,   /* The parameter is invalid */
    SRV_EMAIL_RESULT_INVALID_STATE                  = 21,   /* The state is invalid */
    SRV_EMAIL_RESULT_INVALID_OPERATION              = 22,   /* The operation is invalid */
    SRV_EMAIL_RESULT_MSG_NOT_EXIST                  = 23,   /* The message does not exist */
    SRV_EMAIL_RESULT_MSG_IN_LOCAL                   = 24,   /* The message is in local */
    SRV_EMAIL_RESULT_CONT_NOT_EXIST                 = 25,   /* The content does not exist */
    SRV_EMAIL_RESULT_CONT_IN_LOCAL                  = 26,   /* The content is in local */
    SRV_EMAIL_RESULT_ATTACH_NOT_EXIST               = 27,   /* The attachment does not exist */
    SRV_EMAIL_RESULT_ATTACH_IN_LOCAL                = 28,   /* The attachment is in local */
    SRV_EMAIL_RESULT_FLDR_EMPTY                     = 29,   /* The folder is empty */
    SRV_EMAIL_RESULT_INVALID_USERNAME               = 30,   /* The username is invalid */
    SRV_EMAIL_RESULT_INVALID_PASSWORD               = 31,   /* The password is invalid */
    SRV_EMAIL_RESULT_ACTIVATE_BEARER_FAIL           = 32,   /* Activate the bearer unsuccessfully */
    SRV_EMAIL_RESULT_AUTH_FAIL                      = 33,   /* Authorize with server unsuccessfully */
    SRV_EMAIL_RESULT_SERVER_NOT_SUPPORT_STARTTLS    = 34,   /* The server does not support STARTTLS */
    SRV_EMAIL_RESULT_SERVER_NOT_SUPPORT_APOP        = 35,   /* The server does not support APOP */
    SRV_EMAIL_RESULT_SERVER_ERROR                   = 36,   /* The server error occurs */
    SRV_EMAIL_RESULT_CAPABILITY_LIMITATION          = 37,   /* The capability limitation is reached */
    SRV_EMAIL_RESULT_INVALID_FORMAT                 = 38,   /* The message format is invalid */
    SRV_EMAIL_RESULT_SELECT_FOLDER_ERROR            = 39,   /* Select the server folder unsuccessfully */
    SRV_EMAIL_RESULT_RECIPIENTS_ERROR               = 40,   /* The recipient error occurs */
    SRV_EMAIL_RESULT_SMTP_CMD_ERROR                 = 41,   /* The SMTP command error occurs */
    SRV_EMAIL_RESULT_POP3_CMD_ERROR                 = 45,   /* The POP3 command error occurs */
    SRV_EMAIL_RESULT_IMAP4_CMD_ERROR                = 46,   /* The IMAP4 command error occurs */
    SRV_EMAIL_RESULT_NETWORK_ERROR                  = 47,   /* The network error occurs */
    SRV_EMAIL_RESULT_NETWORK_TIMEOUT                = 48,   /* The network timeout occurs */
    SRV_EMAIL_RESULT_INTERNAL_ERROR                 = 49,   /* The internal error occurs */
    SRV_EMAIL_RESULT_MSG_EXCEED_DOWNLOAD_SIZE       = 50,   /* The message is too large */
    SRV_EMAIL_RESULT_INVALID_AUTH_COOKIE            = 51,   /* The authentication cookie is invalid */
    SRV_EMAIL_RESULT_TOTAL                          /* The total result value */
} srv_email_result_enum;

/* The Email account type */
typedef enum
{
    SRV_EMAIL_ACCT_NONE,                /* None */
    SRV_EMAIL_ACCT_USER_CONFIGURED,     /* The account is configured by user */
    SRV_EMAIL_ACCT_OTAP_CONFIGURED,     /* The account is configured with OTAP */
    SRV_EMAIL_ACCT_FACTORY_CONFIGURED,  /* The account is configured by factory */
    SRV_EMAIL_ACCT_TOTAL                /* The total account type */
} srv_email_acct_type_enum;

/* The Email protocol type */
typedef enum
{
    SRV_EMAIL_PROT_NONE,    /* None */
    SRV_EMAIL_PROT_SMTP,    /* The SMTP protocol */
    SRV_EMAIL_PROT_POP3,    /* The POP3 protocol */
    SRV_EMAIL_PROT_IMAP4,   /* The IMAP4 protocol */
    SRV_EMAIL_PROT_TOTAL    /* The total protocol type */
} srv_email_prot_type_enum;

/* The Email authentication type */
typedef enum
{
    SRV_EMAIL_AUTH_NONE,    /* No authentication */
    SRV_EMAIL_AUTH_USER,    /* User/Pass authentication */
    SRV_EMAIL_AUTH_APOP,    /* APOP authentication */
    SRV_EMAIL_AUTH_TOTAL    /* To check the authentication's validity */
} srv_email_auth_type_enum;

/* The Email security mode */
typedef enum
{
    SRV_EMAIL_SEC_NONE,     /* No security mode */
    SRV_EMAIL_SEC_SSL_TLS,  /* SSL/TLS security mode */
    SRV_EMAIL_SEC_STARTTLS, /* STARTTLS security mode */
    SRV_EMAIL_SEC_TOTAL     /* To check the security mode's validity */
} srv_email_sec_mode_enum;

/* The Email sending option */
typedef enum
{
    SRV_EMAIL_SEND_IMMEDIATELY, /* Send immediately */
    SRV_EMAIL_SEND_SEND_COPY,   /* Send copy */
    SRV_EMAIL_SEND_TOTAL        /* To check the send option's validity */
} srv_email_send_option_enum;

/* The Email download option */
typedef enum
{
    SRV_EMAIL_DOWNLOAD_HEADER,      /* Download header only */
    SRV_EMAIL_DOWNLOAD_HEADER_TEXT, /* Download header and text */
    SRV_EMAIL_DOWNLOAD_ALL,         /* Download whole email */
    SRV_EMAIL_DOWNLOAD_TOTAL        /* To check the download option's validity */
} srv_email_download_option_enum;

/* The Email notify option */
typedef enum
{
    SRV_EMAIL_NOTIFY_OFF,               /* Notify Off */
    SRV_EMAIL_NOTIFY_ON,                /* Notify On */
    SRV_EMAIL_NOTIFY_HOME_NETWORK_ONLY, /* Notify On in home network only */
    SRV_EMAIL_NOTIFY_TOTAL              /* To check the notify option's validity */
} srv_email_notify_option_enum;

/* The Email delete option */
typedef enum
{
    SRV_EMAIL_DELETE_ALWAYS_ASK,        /* Always ask when deletion */
    SRV_EMAIL_DELETE_PHONE_ONLY,        /* Delete from local only */
    SRV_EMAIL_DELETE_PHONE_AND_SERVER,  /* Delete from local and server */
    SRV_EMAIL_DELETE_TOTAL              /* To check the delete option's validity */
} srv_email_delete_option_enum;

/* The Email account and folder receive option */
typedef enum
{
    SRV_EMAIL_RECEIVE_NEW_EMAIL,    /* Receive new emails only */
    SRV_EMAIL_RECEIVE_ALL_EMAIL,    /* Receive all emails */
    SRV_EMAIL_RECEIVE_TOTAL         /* To check the receive option's validity */
} srv_email_receive_option_enum;

/* The field mask used for list messages */
typedef enum
{
    SRV_EMAIL_FIELD_SENDER      = 0x0001,   /* Display the sender (From) */
    SRV_EMAIL_FIELD_RECIPIENT   = 0x0002,   /* Display the recipient (To/Cc/Bcc),
                                             * alternative with SRV_EMAIL_FIELD_SENDER
                                             */
    SRV_EMAIL_FIELD_MAIL_TIME   = 0x0004,   /* Display the mail time (Date) */
    SRV_EMAIL_FIELD_RECV_TIME   = 0x0008,   /* Display the received time,
                                             * alternative with SRV_EMAIL_FIELD_MAIL_TIME
                                             */
    SRV_EMAIL_FIELD_SUBJECT     = 0x0040,   /* Display the subject */
    SRV_EMAIL_FIELD_CONTENT     = 0x0080,   /* Display the content,
                                             * alternative with SRV_EMAIL_FIELD_SUBJECT
                                             */
    SRV_EMAIL_FIELD_STATE       = 0x0100,   /* Display the state */
    SRV_EMAIL_FIELD_TOTAL                   /* The total field */
} srv_email_list_field_enum;

/* The Email address type */
typedef enum
{
    SRV_EMAIL_ADDR_TYPE_FROM = 0,   /* The address in From field */
    SRV_EMAIL_ADDR_TYPE_TO,         /* The address in To field */
    SRV_EMAIL_ADDR_TYPE_CC,         /* The address in Cc field */
    SRV_EMAIL_ADDR_TYPE_BCC,        /* The address in Bcc field */
    SRV_EMAIL_ADDR_TYPE_REPLY_TO,   /* The address in Reply-to field */
    SRV_EMAIL_ADDR_TYPE_TOTAL       /* To check the address type's validity */
} srv_email_addr_type_enum;

/* The Email message state value */
typedef enum
{
    SRV_EMAIL_MSG_STATE_HEADER_ONLY = 0x0001,   /* header only, download header only */
    SRV_EMAIL_MSG_STATE_DEL_SERVER = 0x0002,    /* header only, delete from phone */
    SRV_EMAIL_MSG_STATE_DELAY_SEND = 0x0004,    /* header only, wait for deletion from sever */
    SRV_EMAIL_MSG_STATE_SEND_FAIL = 0x0008,     /* The delay send state mask */
    SRV_EMAIL_MSG_STATE_DOWN_ALL = 0x0010,      /* All parts have been downloaded */
    SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH = 0x0020,/*there still have plain text to be doenloaded*/
    SRV_EMAIL_MSG_STATE_TOTAL                   /* The total message state */
} srv_email_state_enum;

/* The Email retrieve option */
typedef enum
{
    SRV_EMAIL_RETRIEVE_ALL_PARTS,           /* Retrieve whole email */
    SRV_EMAIL_RETRIEVE_TEXT_CONTENT,        /* Retrieve the email's text content */
    SRV_EMAIL_RETRIEVE_HTML_CONTENT,        /* Retrieve the email's html content */
    SRV_EMAIL_RETRIEVE_ALL_CONTENT,         /* Retrieve the email's all content */
    SRV_EMAIL_RETRIEVE_SINGLE_ATTACHMENT,   /* Retrieve the email's specified attachment */
    SRV_EMAIL_RETRIEVE_ALL_ATTACHMENT,      /* Retrieve the email's all attachments */
    SRV_EMAIL_RETRIEVE_TOTAL                /* To check the retrieve option's validity */
} srv_email_retrieve_option_enum;

/* The type for getting folder message number */
typedef enum
{
    SRV_EMAIL_FLDR_MSG,                     /* Get all messages */
    SRV_EMAIL_FLDR_MSG_UNREAD,              /* Get the unread messages only */
    SRV_EMAIL_FLDR_MSG_UNREAD_FROM_MARKED,  /* Get the unread and marked messages only */
    SRV_EMAIL_FLDR_MSG_MARKED,              /* Get the marked messages only */
    SRV_EMAIL_FLDR_MSG_TOTAL                /* The total type */
} srv_email_fldr_get_msg_num_type_enum;

/* The Email network state */
typedef enum
{
    SRV_EMAIL_NWK_DISCONNECTED,     /* Disconnected with server, no data structure */
    SRV_EMAIL_NWK_CBM_QUERYING,     /* Querying the CBM info, srv_email_cbm_querying_struct */
    SRV_EMAIL_NWK_CONNECTING,       /* Connecting server, no data structure */
    SRV_EMAIL_NWK_AUTHORIZING,      /* Authorizing with server, no data structure */
    SRV_EMAIL_NWK_QUERYING,         /* Querying the username/password, srv_email_querying_data_struct */
    SRV_EMAIL_NWK_UPDATING,         /* Updating the selected folder information */
    SRV_EMAIL_NWK_SENDING,          /* Sending email(s) to server, srv_email_sending_data_struct */
    SRV_EMAIL_NWK_SEND_DONE,        /* Send emails done, srv_email_send_done_data_struct */
    SRV_EMAIL_NWK_RECEIVING,        /* Receiving email(s) from server, srv_email_receiving_data_struct */
    SRV_EMAIL_NWK_RECEIVE_DONE,     /* Receive emails done, srv_email_receive_done_data_struct */
    SRV_EMAIL_NWK_SYNCING,          /* Syncing flag of email(s) with server, srv_email_syncing_data_struct */
    SRV_EMAIL_NWK_DELETING,         /* Deleting email(s) from server, srv_email_deleting_data_struct */
    SRV_EMAIL_NWK_LISTING_FOLDER,   /* Listing remote folder from server, no data structure */
    SRV_EMAIL_NWK_DISCONNECTING,    /* Disconnecting server, no data structure */
    SRV_EMAIL_NWK_NEED_REFRESH,     /* Need refresh the connection, srv_email_need_refresh_data_struct */
    SRV_EMAIL_NWK_REFRESHED,        /* The connection is refreshed, no data structure */
    SRV_EMAIL_NWK_TOTAL_STATE       /* The total network state */
} srv_email_nwk_status_enum;

/* The part for indicate which part of message app want to update */
typedef enum
{
    SRV_EMAIL_MSG_SAVE_ADDR_TO,         /* Save TO address */
    SRV_EMAIL_MSG_SAVE_ADDR_CC,         /* Save CC address */
    SRV_EMAIL_MSG_SAVE_ADDR_BCC,        /* Save BCC address */
    SRV_EMAIL_MSG_SAVE_SUBJECT,         /* Save subject */
    SRV_EMAIL_MSG_SAVE_CONTENT,         /* Save text content */
    SRV_EMAIL_MSG_SAVE_ATTACHMENT_INFO, /* Save attachment information */
    SRV_EMAIL_MSG_SAVE_HTML,            /* Save HTML content */
    SRV_EMAIL_MSG_SAVE_ENVELOP_TMP,
    SRV_EMAIL_MSG_SAVE_CONTENT_TMP,
    SRV_EMAIL_MSG_SAVE_EXTRA_SMS_UID,   /* Save HTML content */
    SRV_EMAIL_MSG_SAVE_EXTRA_SMS_ADDR,  /* Save HTML content */
    SRV_EMAIL_MSG_SAVE_EXTRA_SMS_DATA,  /* Save HTML content */
    SRV_EMAIL_MSG_SAVE_ALL,             /* Save all parts */
    SRV_EMAIL_MSG_SAVE_TOTAL            /* The total part */
} srv_email_msg_save_part_enum;

/* The mailbox's type */
typedef enum
{
    SRV_EMAIL_FLDR_TYPE_INVALID = -1,   /* Invalid type */
    SRV_EMAIL_FLDR_TYPE_INBOX   = 0,    /* Inbox */
    SRV_EMAIL_FLDR_TYPE_OUTBOX  = 1,    /* Outbox */
    SRV_EMAIL_FLDR_TYPE_SENT    = 2,    /* Sent */
    SRV_EMAIL_FLDR_TYPE_DRAFT   = 3,    /* Draft */
    SRV_EMAIL_FLDR_TYPE_TRASH   = 4,    /* Trash, reserved type, NOT supported now */
    SRV_EMAIL_FLDR_TYPE_BASICS_BGN = SRV_EMAIL_FLDR_TYPE_INBOX, /* First basics box is inbox */
    SRV_EMAIL_FLDR_TYPE_BASICS_END = SRV_EMAIL_FLDR_TYPE_DRAFT, /* Last basics box is draft */
    SRV_EMAIL_FLDR_TYPE_BASICS_CNT = SRV_EMAIL_FLDR_TYPE_BASICS_END - SRV_EMAIL_FLDR_TYPE_BASICS_BGN + 1, /* Basic folder count */
    SRV_EMAIL_FLDR_TYPE_BASICS,         /* Basics folder type */
    SRV_EMAIL_FLDR_TYPE_REMOTE,         /* Remote folder type */
    SRV_EMAIL_FLDR_TYPE_ALL,            /* All folder type */
    SRV_EMAIL_FLDR_TYPE_TOTAL           /* The total folder type */
} srv_email_fldr_type_enum;

/* The folder set type */
typedef enum
{
    SRV_EMAIL_ACCT_FLDR_TYPE_BASIC,     /* The basic folders set */
    SRV_EMAIL_ACCT_FLDR_TYPE_LOCAL,     /* The remote folders set in local */
    SRV_EMAIL_ACCT_FLDR_TYPE_TOTAL      /* The total folder type */
} srv_email_acct_fldr_type_enum;

/* The message sort mode */
typedef enum
{
    SRV_EMAIL_FLDR_SORT_MSG_MODE_NONE = 0,      /* */
    SRV_EMAIL_FLDR_SORT_MSG_MODE_TIME,          /* Sort message with date and time */
    SRV_EMAIL_FLDR_SORT_MSG_MODE_SERVER_SIZE,   /* Sort message with server size */
    SRV_EMAIL_FLDR_SORT_MSG_MODE_LOCAL_SIZE,    /* Sort message with local size */
    SRV_EMAIL_FLDR_SORT_MSG_MODE_BUFFER,        /* Sort message with buffer data (subject or content) */
    SRV_EMAIL_FLDR_SORT_MSG_MODE_ADDR,          /* Sort message with address */
    SRV_EMAIL_FLDR_SORT_MSG_MODE_FLAG,          /* Sort message with read/unread */
    SRV_EMAIL_FLDR_SORT_MSG_MODE_TOTAL          /* The total sort mode */
} srv_email_fldr_sort_msg_mode_enum;

/* The message text type */
typedef enum
{
    SRV_EMAIL_MSG_TEXT_SUBJ = 0,        /* Get the subject */
    SRV_EMAIL_MSG_TEXT_CONT_TEXT,       /* Get the text content */
    SRV_EMAIL_MSG_TEXT_CONT_HTML,       /* Get the html content */
    SRV_EMAIL_MSG_TEXT_TYPE_TOTAL       /* The total text type */
} srv_eamil_msg_text_type_enum;

/* The message date type */
typedef enum
{
    SRV_EMAIL_MSG_CREATED_DATE = 0,     /* Get the created date */
    SRV_EMAIL_MSG_RECEIVED_DATE,        /* Get the received/internal date */
    SRV_EMAIL_MSG_DATE_TYPE_TOTAL       /* The total date type */
} srv_email_msg_date_type_enum;

/* The Email service init state */
typedef enum
{
    SRV_EMAIL_INIT_STATE_NOT_STARTED    = 2,    /* The service is not started */
    SRV_EMAIL_INIT_STATE_INITING        = 1,    /* The service is initializing */
    SRV_EMAIL_INIT_STATE_READY          = 0,    /* The service is ready */
    SRV_EMAIL_INIT_STATE_ERROR          = -1,   /* The service is initialized unsuccessfully */
    SRV_EMAIL_INIT_STATE_TOTAL                  /* The total state */
} srv_email_init_state_enum;

/* The field mask used for account attribute */
typedef enum
{
    SRV_EMAIL_ACCT_ATTR_SMTP   = 0x00000001,    /* This account includes SMTP */
    SRV_EMAIL_ACCT_ATTR_POP3   = 0x00000002,    /* This account includes POP3 */
    SRV_EMAIL_ACCT_ATTR_IMAP4  = 0x00000004,    /* This account includes IMAP4 */
    SRV_EMAIL_ACCT_ATTR_TOTAL                   /* The total attribute */
} srv_email_acct_attr_enum;

/* The flag used for message content */
typedef enum
{
    SRV_EMAIL_MSG_CONT_PART_EXIST = 0x01,       /* This content exists */
    SRV_EMAIL_MSG_CONT_DOWNLOADED = 0x02        /* This content has been downloaded */
} srv_email_msg_cont_exit_enum;

/* The comman result structure */
typedef struct
{
    MMI_BOOL result;        /* The result */
    MMI_BOOL sub_result;    /* The sub-result */
    S32 major;              /* The major error, valid when result is MMI_FALSE */
    S32 minor;              /* The minor error, valid when result is MMI_FALSE */
    CHAR err_string[128];   /* The error string, not support now */
} srv_email_result_struct;

/* The structure used to query the app info */
typedef struct
{
    EMAIL_ACCT_ID acct_id;  /* The account id */
    MMI_BOOL is_incoming;   /* Query the incoming info or not */
    U32 dataacct_id;        /* The data account id */
    U8 app_id;
} srv_email_app_info_query_struct;

/* The address structure */
typedef struct
{
    S32 disp_charset;       /* The charset of the display name */
    S32 disp_name_len;      /* The length of the display name */
    WCHAR disp_name[SRV_EMAIL_MAX_DISP_NAME_LEN + 1];   /* The display name */
    WCHAR email_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];       /* The email address */
} srv_email_addr_struct;

/* The authentication structure */
typedef struct
{
    WCHAR username[SRV_EMAIL_MAX_USERNAME_LEN + 1]; /* The username (WCHAR string) */
    WCHAR password[SRV_EMAIL_MAX_PASSWORD_LEN + 1]; /* The password (WCHAR string) */
    srv_email_auth_type_enum auth_type;             /* The authentication type */
} srv_email_auth_struct;

/* The server information structure */
typedef struct
{
    WCHAR server_name[SRV_EMAIL_MAX_SERVER_NAME_LEN + 1];   /* The server name (WCHAR string) */
    U16 port_num;                       /* The part number, 0 means using the default value */
    U16 sec_port_num;                   /* security port num */
    srv_email_sec_mode_enum sec_mode;   /* The security mode */
    MMI_BOOL wifi_only;                 /* Whether is wifi only */
    U32 data_acct[MMI_SIM_TOTAL];
} srv_email_server_struct;

/* The account information structure */
typedef struct
{
    EMAIL_ACCT_ID acct_id;                  /* The account id */
    srv_email_acct_type_enum acct_type;     /* The account type */
    MMI_BOOL is_cloud_acct;                 /* If it's cloud acct, some info could NOT be modified by user.
                                               And Y/T-cookies are needed from SSO service */
    MMI_BOOL read_only;                     /* If this account is readed only or not */
    srv_email_prot_type_enum protocol;      /* The protocol type */
    srv_email_addr_struct email_addr;       /* The email address */
    srv_email_addr_struct reply_to_addr;    /* The reply-to address */
    srv_email_server_struct in_server;      /* The incoming server info */
    srv_email_server_struct out_server;     /* The outgoing server info */
    srv_email_auth_struct in_auth;          /* The incoming authentication */
    srv_email_auth_struct out_auth;         /* The outgoing authentication */
    srv_email_send_option_enum send_option; /* The send option */
    srv_email_download_option_enum download_option;     /* The download option */
    srv_email_notify_option_enum notify_option;         /* The notify option */
    MMI_BOOL new_email_alert;                           /* The new email alert */
    srv_email_delete_option_enum delete_option;         /* The delete option */
    S32 download_size;                                  /* The download size */
    S32 retrieve_amount;                                /* The retrieve amount */
    U8 provurl_hash[SRV_EMAIL_MD5_DIGEST_LEN];          /* Used for bootstrap */
    U8 napid_hash[SRV_EMAIL_MD5_DIGEST_LEN];            /* Used for bootstrap */
    WCHAR acct_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];   /* The account name (WCHAR string) */
    U32 acct_attr;                                      /* The account attribute */
} srv_email_acct_info_struct;

/* The folder information structure */
typedef struct
{
    WCHAR folder_name[SRV_EMAIL_FLDR_NAME_LEN + 1]; /* The folder name (WCHAR string) */
    WCHAR fldr_name_separator;                      /* The folder name separator */
    S32 msg_count;                                  /* The email's number in this folder */
    S32 unread_count;                               /* The unread email's number in this folder */
    srv_email_acct_fldr_type_enum fldr_type;        /* The folder type */
} srv_email_acct_folder_struct;

/* The remote folder information structure */
typedef struct
{
    WCHAR folder_name[SRV_EMAIL_FLDR_NAME_LEN + 1]; /* The folder name */
    WCHAR fldr_name_separator;                      /* The folder name separator */
    MMI_BOOL subscribed;                            /* If this folder has been subscribed or not */
} srv_email_acct_remote_fldr_info_strcut;

/* The basic information app can get from folder handle */
typedef struct
{
    EMAIL_ACCT_ID acct_id;                          /* The account id */
    EMAIL_FLDR_ID fldr_id;                          /* The folder id */
    srv_email_fldr_sort_msg_mode_enum sort_mode;    /* The sort mode */
    MMI_BOOL sort_order;                            /* The sort order */
    U32 list_field;                                 /* The list flag set */
} srv_email_fldr_basic_info_struct;

/* The message information structure displayed when list */
typedef struct
{
    EMAIL_MSG_ID msg_id;            /* Used to store the message id */
    srv_email_addr_struct addr;     /* Used to store the sender / first of to address list */
    WCHAR buff[SRV_EMAIL_FLDR_MSG_LIST_TEXT_LEN + 1];             /* Used to store the partial subject or content */
    U32 server_size;                /* The server size of the email */
    U32 local_size;                 /* The local size of the email */
    U32 has_attach;                 /* If the message has attachment or not */
    U32 time;                       /* Used to store the mail date or receive size */
    S32 state;                      /* Used to store the message state
                                     * Can be used to store check box mark for batch processing
                                     */
    U8  priority;                   /* Used to store the message priority */
    EMAIL_MSG_FLAG flag;            /* Used to store the message flag */
    MMI_BOOL marked;                /* If this message has been marked or not */
} srv_email_fldr_msg_info_struct;

/* Information used for create a folder handle
 * Use srv_email_list_field_enum to compose list_field
 */
typedef struct
{
    EMAIL_ACCT_ID acct_id;                          /* The account id */
    EMAIL_FLDR_ID fldr_id;                          /* The folder id */
    srv_email_fldr_sort_msg_mode_enum sort_mode;    /* The sort mode */
    MMI_BOOL sort_order;                            /* The sort order */
    U32 list_field;                                 /* The list flag set */
} srv_email_fldr_create_info_struct;

/* Information used for create a folder handle by folder type
 * Use srv_email_list_field_enum to compose list_field
 */
typedef struct
{
    srv_email_fldr_type_enum fldr_type;             /* The folder type */
    srv_email_fldr_sort_msg_mode_enum sort_mode;    /* The sort mode */
    MMI_BOOL sort_order;                            /* The sort order */
    U32 list_field;                                 /* The list flag set */
} srv_email_fldr_create_by_type_info_struct;

/* The parameter structure of sort emails */
typedef struct
{
    srv_email_fldr_sort_msg_mode_enum sort_mode;    /* The sort mode */
    MMI_BOOL sort_order;                            /* The sort order, MMI_TRUE is ascending */
    EMAIL_MSG_ID msg_id;                            /* The message id */
    S32 msg_index;                                  /* The new index of the msg_id after sorting */
} srv_email_fldr_sort_msg_struct;

/* The parameter structure of set emails state */
typedef struct
{
    MMI_BOOL set_all;           /* Set all emails or not */
    MMI_BOOL set_all_marked;    /* Set all marked emails or not */
    EMAIL_MSG_ID msg_id;        /* Set the state of the specified message,
                                 * valid when set_all_marked is MMI_FALSE
                                 */
    U8 msg_flag;                /* The new state */
    U8 flag_mask;               /* The mask of the valid state */
} srv_email_fldr_set_msg_flag_struct;

/* The parameter structure of delete emails */
typedef struct
{
    MMI_BOOL delete_all;        /* Delete all emails in this folder */
    MMI_BOOL delete_all_marked; /* Delete all marked emails in this folder,
                                 * valid when delete_all is MMI_FALSE
                                 */
    EMAIL_MSG_ID msg_id;        /* Delete the specified message,
                                 * valid when delete_all and delete_all_marked are MMI_FALSE
                                 */
    MMI_BOOL delete_header;     /* Delete the header or not */
    MMI_BOOL delete_server;     /* Delete server email or not */
} srv_email_fldr_delete_msg_struct;

/* The message information structure displayed when list */
typedef struct _srv_email_fldr_msg_info_node_struct
{
    /* filled by storage */
    EMAIL_MSG_ID msg_id;            /* Used to store the message id */
    srv_email_addr_struct addr;     /* Used to store the sender / first of to address list */
    WCHAR buff[SRV_EMAIL_FLDR_MSG_LIST_TEXT_LEN + 1];   /* Used to store the partial subject or content */
    U32 server_size;                /* The server size of the email */
    U32 local_size;                 /* The local size of the email */
    U32 has_attach;                 /* If the message has attachment or not */
    U32 time;                       /* Used to store the mail date or receive size */
    S32 state;                      /* Used to store the message state
                                     * Can be used to store check box mark for batch processing
                                     */
    U8  priority;                   /* Used to store the message priority */
    EMAIL_MSG_FLAG flag;            /* Used to store the message flag */
    MMI_BOOL marked;                /* If this message has been marked or not */
    struct _srv_email_fldr_msg_info_node_struct *pre;   /* The pointer points to the previous message node */
    struct _srv_email_fldr_msg_info_node_struct *next;  /* The pointer points to the next message node */
} srv_email_fldr_msg_info_node_struct;

/* The email subject structure */
typedef struct
{
    S32 len;        /* Length of subject */
    S32 charset;    /* The charset of the subject */
    WCHAR filepath[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];    /* The subject file path (WCHAR string) */
} srv_email_subject_struct;

/* The email content structure */
typedef struct
{
    S32 charset;            /* The charset of the content */
    S32 len;                /* The size of the content */
    S32 mime_type;          /* The mime type of the content */
    S32 mime_subtype;       /* The mime subtype of the content */
    MMI_BOOL downloaded;    /* The content has been downloaded or not */
    WCHAR filepath[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];    /* The content file path (WCHAR string) in local */
} srv_email_content_struct;

/* The email attachment structure */
typedef struct
{
    EMAIL_ATTCH_ID attach_id;                       /* The attachment id */
    S32 charset;                                    /* The charset of the attachment */
    S32 name_len;                                   /* Length of attachment display name buffer */
    WCHAR name[EMAIL_ATTCH_FILE_NAME_LEN + 1];      /* Buffer to store the attachment display name */
    WCHAR path[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];    /* The filepath of the attachment */
    S32 size;                                       /* The size of the attachment */
    S32 mime_type;                                  /* The mime type of the content */
    S32 mime_subtype;                               /* The mime subtype of the content */
    MMI_BOOL drm_object;                            /* The attachment is the DRM object or not */
    S32 drm_type;                                   /* The mime type of the DRM object */
    S32 drm_subtype;                                /* The mime subtype of the DRM object */
    CHAR cid[SRV_EMAIL_CID_MAX_LEN + 1];            /* The Content ID digest of the attachment */
    MMI_BOOL downloaded;                            /* The attachment has been downloaded or not */
} srv_email_attach_struct;

/* The basic information struct used for app to get from and set to a message handle */
typedef struct
{
    EMAIL_ACCT_ID acct_id;      /* The account id */
    EMAIL_FLDR_ID fldr_id;      /* The folder id */
    EMAIL_MSG_ID msg_id;        /* The message id */
    S32 to_addr_num;            /* The address number in TO field */
    S32 cc_addr_num;            /* The address number in CC field */
    S32 bcc_addr_num;           /* The address number in BCC field */
    S32 attach_num;             /* The attachment number */
    S32 remain_to_addr_num;     /* The remain address number in TO field */
    S32 remain_cc_addr_num;     /* The remain address number in CC field */
    S32 remain_bcc_addr_num;    /* The remain address number in BCC field */
    S32 remain_attach_num;      /* The remail attachment number */
    U8 priority;                /* The message priority */
    S32 server_size;            /* The message server size */
    S32 local_size;             /* The message local size */
    U32 mail_date;              /* The message date time */
    U32 recv_date;              /* The message received date time */
    S32 state;                  /* The message state */
    EMAIL_MSG_FLAG flag;        /* The message flag */
} srv_email_msg_get_basic_info_struct;

/* The structure used to update the basic information of message */
typedef struct
{
    EMAIL_ACCT_ID acct_id;      /* The account id */
    EMAIL_FLDR_ID fldr_id;      /* The folder id */
    U8 priority;                /* The message priority */
    EMAIL_MSG_FLAG flag;        /* The message flag */
} srv_email_msg_update_basic_info_struct;

/* The parameter structure of get recipient */
typedef struct
{
    srv_email_addr_type_enum type;      /* To, cc or bcc */
    srv_email_addr_struct *addr_list;   /* Buffer used to store address list */
    U32 start_index;                    /* Start index of address */
    U32 number;                         /* How many app wants and service given */
} srv_email_msg_get_recipient_struct;

/* The parameter structure of update content */
typedef struct
{
    MMI_BOOL buff_type;     /* If the content is in the buffer directly or not */
    void *buff;             /* The content buffer or the content filepath */
    S32 charset;            /* The content charset */
    U32 buff_len;           /* The buffer length */
} srv_email_msg_update_content_struct;

/* The parameter structure of copy message */
typedef struct
{
    EMAIL_ACCT_ID dst_acct_id;      /* The destination account id */
    EMAIL_FLDR_ID dst_fldr_id;      /* The destination folder id */
    EMAIL_MSG_ID dst_msg_id;        /* Used to store the new email id after coping successfully */
} srv_email_msg_copy_struct;


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_query_cnf_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of querying username/password.
 * PARAMETERS
 *  result      : [IN]      The query result
 *  username    : [IN]      The new username
 *  password    : [IN]      The new password
 *  user_data   : [IN]      The user data
 * RETURNS
 *  The result code.
 *****************************************************************************/
typedef srv_email_result_enum (*srv_email_query_cnf_funcptr_type)(
                                    MMI_BOOL result,
                                    const WCHAR *username,
                                    const WCHAR *password,
                                    void *user_data);

/* The CBM querying state data structure */
typedef struct
{
    void *cbm_data;     /* The pointer of srv_cbm_bearer_event_struct */
} srv_email_cbm_querying_struct;

/* The querying state data structure */
typedef struct 
{
    WCHAR username[SRV_EMAIL_MAX_USERNAME_LEN + 1]; /* The username */
    WCHAR password[SRV_EMAIL_MAX_PASSWORD_LEN + 1]; /* The password */
    srv_email_query_cnf_funcptr_type callback;      /* The callback function */
    void *user_data;                                /* The callback user_data */
} srv_email_querying_data_struct;

/* The sending state data structure */
typedef struct
{
    S32 total_num;              /* The total number of the emails that need to be sent */
    S32 sent_num;               /* The number of the emails that have been sent */
    S32 fail_num;               /* The number of the emails that send unsuccessfully */
    S32 total_size;             /* The total size of the sending email, not support now */
    S32 sent_size;              /* The sent size of the sending email, not support now */
    EMAIL_MSG_ID msg_id;        /* The id of the next email waiting to send */
    MMI_BOOL result;            /* The sending result of the previous email */
} srv_email_sending_data_struct;

/* The send done state data structure */
typedef struct
{
    S32 total_num;              /* The total number of the emails that need to be sent */
    S32 sent_num;               /* The number of the emails that have been sent */
    S32 fail_num;               /* The number of the emails that send unsuccessfully */

    MMI_BOOL result;            /* The sending result */
    S32 major;                  /* The major error, valid when result is MMI_FALSE */
    S32 minor;                  /* The minor error, valid when result is MMI_FALSE */
} srv_email_send_done_data_struct;

/* The receiving state data structure */
typedef struct
{
    EMAIL_FLDR_ID fldr_id;      /* The id of the folder in which the new email will be saved */

    S32 total_num;              /* The total number of the emails that can be received */
    S32 received_num;           /* The number of the emails that have been received */
    S32 fail_num;               /* The number of the emails that receive unsuccessfully */
    S32 total_size;             /* The total size of the recieving email, not support now */
    S32 received_size;          /* The received size of the receiving email, not support now */

    MMI_BOOL new_msg_received;  /* If new email is received or not */
    EMAIL_MSG_ID new_msg_id;    /* The id of the new email, valid when new_msg_received is MMI_TRUE */
    U16 new_msg_flag;           /* The flag of the new email, valid when new_msg_received is MMI_TRUE */
} srv_email_receiving_data_struct;

/* The receive done state data structure */
typedef struct
{
    EMAIL_FLDR_ID fldr_id;      /* The id of the folder that has finished the receiving */

    S32 fldr_count;             /* The count of the folders that need to receive emails */
    S32 fldr_index;             /* The index of the current receiving folder, start from 1 */

    S32 total_num;              /* The total number of the emails that can be received */
    S32 received_num;           /* The number of the emails that have been received */
    S32 fail_num;               /* The number of the emails that receive unsuccessfully */

    MMI_BOOL result;            /* The receiving result */
    S32 major;                  /* The major error, valid when result is MMI_FALSE */
    S32 minor;                  /* The minor error, valid when result is MMI_FALSE */
} srv_email_receive_done_data_struct;

/* The syncing state data structure */
typedef struct
{
    EMAIL_FLDR_ID fldr_id;      /* The id of the folder in which the emails are syncing */
    S32 total_num;              /* The total number of the emails that need to sync */
    S32 sync_num;               /* The number of the emails that have been synced */
} srv_email_syncing_data_struct;

/* The deleting state data structure */
typedef struct
{
    EMAIL_FLDR_ID fldr_id;      /* The id of the folder from which the emails are deleting */
    S32 total_num;              /* The toatl number of the emails that need to be deleted */
    S32 deleted_num;            /* The number of the emails that have been deleted */
} srv_email_deleting_data_struct;

/* The refresh type */
typedef enum
{
    SRV_EMAIL_NWK_REFRESH_MSG_NUMBER    = 0x01, /* The email number has been changed */
    SRV_EMAIL_NWK_REFRESH_NEW_MSG       = 0x02, /* There are new emails */
    SRV_EMAIL_NWK_REFRESH_MSG_DELETED   = 0x04, /* There are some emails deleted from server */
    SRV_EMAIL_NWK_REFRESH_MSG_CHANGED   = 0x08, /* There are some emails which flags are changed, not support now */
    SRV_EMAIL_NWK_REFRESH_TOTAL                 /* The total refresh type */
} srv_email_nwk_refresh_type_enum;

/* The need refresh state data structure */
typedef struct
{
    U32 refresh_type;           /* The refresh type */
} srv_email_need_refresh_data_struct;

/* The Email operation process callback data structure */
typedef struct
{
    srv_email_nwk_status_enum status;   /* The network status */
    void *status_data;                  /* The related data */
    void *user_data;                    /* The related user_data */
} srv_email_nwk_proc_struct;

/* The skip cause enum */
typedef enum
{
    SRV_EMAIL_SKIP_NORMAL,      /* The normal skip, skip by user */
    SRV_EMAIL_SKIP_ENDKEY,      /* Skip by endkey */
    SRV_EMAIL_SKIP_ERROR,       /* Skip by error */
    SRV_EMAIL_SKIP_TOTAL        /* The total skip cause */
} srv_email_skip_cause_enum;

/* The provisioning structure */
typedef struct
{
    WCHAR prof_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];       /* The profile name */
    WCHAR from[SRV_EMAIL_MAX_ADDR_LEN + 1];                 /* The email address */
    WCHAR out_server[SRV_EMAIL_MAX_SERVER_NAME_LEN + 1];    /* The outgoing server address */
    WCHAR in_server[SRV_EMAIL_MAX_SERVER_NAME_LEN + 1];     /* The incoming server address */
    srv_email_prot_type_enum in_protocol;                   /* The protocol type */
    MMI_BOOL updatable;             /* If this profile is updatable or not */
    EMAIL_ACCT_ID update_acct_id;   /* Valid when updatable is true */
    MMI_BOOL have_dtcnt;            /* If the new data account is in this profile or not */
    U32 dtcnt_id;                   /* When have_dtcnt is true, it is the new dataaccount id, otherwise, the default dataaccount id */
} srv_email_otap_prof_info_struct;

/* The provisioning option structure */
typedef struct
{
    MMI_BOOL same_dtcnt;        /* If the outgoing username/password are same as incoming or not */
} srv_email_otap_option_struct;

/* The structure used to list message information */
typedef struct
{
    srv_eamil_msg_text_type_enum text_type;     /* The text type */
    srv_email_msg_date_type_enum date_type;     /* The date type */
    EMAIL_REQ_ID req_id;                        /* The request id */
} srv_email_fldr_list_msg_info_struct;

/* The INBOX index message structure */
typedef struct
{
    EMAIL_MSG_ID msg_id;        /* The message id */
    U32 date;                   /* The message created date time */
} srv_email_inbox_index_msg_struct;

/* The Email read/unread notification type */
typedef enum
{
    SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_NONE,      /* There is no unread email */
    SRV_EMAIL_ALL_MSG_UNREAD_NONE_TO_SOME,       /* There is unread email */
    SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_SOME       /* There is unread email */
} srv_email_all_msg_unread_notify_type;

/* The account information for cache structure */
typedef struct
{
    MMI_BOOL is_cloud_acct;
    srv_email_prot_type_enum protocol;                  /* The protocol type */
    WCHAR acct_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];   /* The account name (WCHAR string) */
    WCHAR acct_addr[MMI_EMAIL_MAX_ADDR_LEN + 1];        /* The email address of account */
    U32 unread_num;                                     /* Unread number of Inbox */
} srv_email_acct_info_cache_struct;

/* The object management's notify type */
typedef enum
{
    SRV_EMAIL_OM_NOTIFY_MSG_ADD = 0,        /* notify FLDR */
    SRV_EMAIL_OM_NOTIFY_MSG_DEL,            /* notify FLDR, MSG */
    SRV_EMAIL_OM_NOTIFY_MSG_UPDATE,         /* notify FLDR, MSG, need to update FLAG & STATE & ATTCH NUM & PRIORITY */    
    SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG,   /* notify FLDR, MSG NUM change */
    SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG,   /* notify ACCT, MSG NUM change (INBOX) */
    SRV_EMAIL_OM_NOTIFY_TOTAL               /* The total notify type */
} srv_email_om_notify_enum;

/* The object management's notify of MSG's change */
typedef enum
{
    SRV_EMAIL_OM_NOTIFY_MSG_CHG_FLAG  = 0x01,   /* Message flag changed */
    SRV_EMAIL_OM_NOTIFY_MSG_CHG_STATE = 0x02,   /* Message state changed */
    SRV_EMAIL_OM_NOTIFY_MSG_CHG_ATTCH = 0x04,   /* Message attachment changed */
    SRV_EMAIL_OM_NOTIFY_MSG_CHG_PRIO  = 0x08,   /* Message priority changed */
    SRV_EMAIL_OM_NOTIFY_MSG_CHG_CONT  = 0x10,    /* Message content changed */
    SRV_EMAIL_OM_NOTIFY_MSG_CHG_SIZE  = 0x20,   /* Message size changed */
} srv_email_om_notify_msg_chg_enum;

/* The object management's notify date */
typedef struct
{
    srv_email_om_notify_enum notify_type;   /* The notify type */
    void *data;                             /* The notify data */
} srv_email_om_notify_struct;

/* The object management's notify date of MSG */
typedef struct  
{
    EMAIL_MSG_ID msg_id;        /* MSG id */
    U8 chg_mask;                /* Change mask, please reference srv_email_om_notify_msg_chg_enum */
    U8 attch_num;               /* MSG attach number */
    EMAIL_MSG_PRIO  priority;   /* MSG priority */
    EMAIL_MSG_FLAG  flag;       /* MSG flag */
    EMAIL_MSG_STATE state;      /* MSG state */
    U32 server_size;            /* MSG server size */
    U32 local_size;             /* MSG local size */
} srv_email_om_notify_msg_struct;

/* The object management's notify date of Folder */
typedef struct  
{
    EMAIL_ACCT_ID acct_id;  /* account id */
    EMAIL_FLDR_ID fldr_id;  /* folder id */
    U32 msg_unread_num;     /* this FLDR's unread number */
    U32 msg_total_num;      /* this FLDR's total number */
} srv_email_om_notify_fldr_struct;

/* The object management's notify date of Account */
typedef struct  
{
    EMAIL_ACCT_ID acct_id;  /* account id */
    U32 msg_unread_num;     /* INBOX's unread MSG number */
    U32 msg_total_num;      /* INBOX's total MSG number  */
} srv_email_om_notify_acct_struct;


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_app_init_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of initialization.
 * PARAMETERS
 *  state       : [IN]      The initialization state
 *  err_type    : [IN]      The error type
 *  user_data   : [IN]      The user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_app_init_funcptr_type)(
                srv_email_init_state_enum state,
                S32 err_type,
                void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_malloc_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of memory alloc.
 * PARAMETERS
 *  size        : [IN]      The alloc size
 * RETURNS
 *  The pointer points to the memory.
 *****************************************************************************/
typedef void *(*srv_email_malloc_funcptr_type)(U32 size);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_mfree_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of memory free.
 * PARAMETERS
 *  p           : [IN]      The pointer points to the memory
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_mfree_funcptr_type)(void *p);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_acct_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of account operation.
 * PARAMETERS
 *  result      : [IN]      The operation result
 *  req_id      : [IN]      The async request id
 *  user_data   : [IN]      The user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_acct_funcptr_type)(
                srv_email_result_struct *result,
                EMAIL_REQ_ID req_id,
                void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_fldr_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of folder operation.
 * PARAMETERS
 *  result      : [IN]      The operation result
 *  req_id      : [IN]      The async request id
 *  user_data   : [IN]      The user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_fldr_funcptr_type)(
                srv_email_result_struct *result,
                EMAIL_REQ_ID req_id,
                void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_msg_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of message operation.
 * PARAMETERS
 *  result      : [IN]      The operation result
 *  req_id      : [IN]      The async request id
 *  user_data   : [IN]      The user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_msg_funcptr_type)(
                srv_email_result_struct *result,
                EMAIL_REQ_ID req_id,
                void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_notify_func
 * DESCRIPTION
 *  This type is used to define the callback function of object management.
 * PARAMETERS
 *  notify_data : [IN]      The pointer points to the notify data
 *  user_data   : [IN]      The user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_notify_func)(srv_email_om_notify_struct *notify_data, void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_async_save_acct_callback
 * DESCRIPTION
 *  This type is used to define the callback function of saving account asynchronously.
 * PARAMETERS
 *  res         : [IN]      The saving result
 *  user_data   : [IN]      The user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_async_save_acct_callback)(srv_email_result_enum res, void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_comp_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of composing message size.
 * PARAMETERS
 *  succ        : [IN]      The composing result
 *  err_major   : [IN]      The major error, valid when succ is MMI_FALSE
 *  err_minor   : [IN]      The minor error, valid when succ is MMI_FALSE
 *  size        : [IN]      The message size, valid when succ is MMI_TRUE
 *  user_data   : [IN]      The user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_comp_funcptr_type)(MMI_BOOL succ, S32 err_major, S32 err_minor, U32 size, void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_all_msg_unread_notify_funcptr
 * DESCRIPTION
 *  This type is used to define the callback function of read/unread modification.
 * PARAMETERS
 *  type        : [IN]      The notification type
 *  num         : [IN]      The number of the unread emails
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_all_msg_unread_notify_funcptr)(
    srv_email_all_msg_unread_notify_type type, U32 num, void* userdata);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of common notification.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_funcptr_type)(void);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_otap_notify_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of new OTAP.
 * PARAMETERS
 *  prof_num    : [IN]      The profile number in this OTAP
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_otap_notify_funcptr_type)(U32 prof_num);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_otap_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of OTAP operation.
 * PARAMETERS
 *  result      : [IN]      The operation result
 *  acct_id     : [IN]      The new account id
 *  req_id      : [IN]      The async request id
 *  user_data   : [IN]      The user data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_otap_funcptr_type)(
                srv_email_result_struct *result,
                EMAIL_ACCT_ID acct_id,
                EMAIL_REQ_ID req_id,
                void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_emn_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of new EMN.
 * PARAMETERS
 *  acct_id     : [IN]      The account id related with this EMN
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_emn_funcptr_type)(EMAIL_ACCT_ID acct_id);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_nwk_proc_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of network operation process.
 * PARAMETERS
 *  data        : [IN]      The process data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_nwk_proc_funcptr_type)(srv_email_nwk_proc_struct *data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_app_info_query_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of querying app info.
 * PARAMETERS
 *  app_inf_p   : [IN]      The pointer point to the account info
 *  str_id      : [OUT]     Return the string id
 *  icon_id     : [OUT]     Return the icon id
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
typedef MMI_BOOL (*srv_email_app_info_query_funcptr_type)(
                    srv_email_app_info_query_struct *app_info_p,
                    U16 *str_id,
                    U16 *icon_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_init
 * DESCRIPTION
 *  This function is used to initialize the Email service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
extern void srv_email_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_email_create
 * DESCRIPTION
 *  This function is used to create a new service instance.
 * PARAMETERS
 *  srv_handle      : [OUT]     Used to store the service instance handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_create(EMAIL_SRV_HANDLE *srv_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified service instance.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_destroy(EMAIL_SRV_HANDLE srv_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_set_mem_func
 * DESCRIPTION
 *  This function is used to set the memory alloc/free functions for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 *  mem_alloc_func  : [IN]      The memory alloc function
 *  mem_free_func   : [IN]      The memory free function
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_set_mem_func(
                                EMAIL_SRV_HANDLE srv_handle,
                                srv_email_malloc_funcptr_type mem_alloc_func,
                                srv_email_mfree_funcptr_type mem_free_func);


/*****************************************************************************
 * FUNCTION
 *  srv_email_register_otap_notify
 * DESCRIPTION
 *  This function is used to register the OTAP notify function for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 *  otap_callback   : [IN]      The OTAP notify function
 *  clear_callback  : [IN]      The OTAP clear notify function
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_register_otap_notify(
                                EMAIL_SRV_HANDLE srv_handle,
                                srv_email_otap_notify_funcptr_type otap_callback,
                                srv_email_funcptr_type clear_callback);


/*****************************************************************************
 * FUNCTION
 *  srv_email_clear_otap_notify
 * DESCRIPTION
 *  This function is used to clear the OTAP notify function for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_clear_otap_notify(EMAIL_SRV_HANDLE srv_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_register_emn_notify
 * DESCRIPTION
 *  This function is used to register the EMN notify function for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 *  emn_callback    : [IN]      The EMN notify function
 *  clear_callback  : [IN]      The EMN clear notify function
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_register_emn_notify(
                                EMAIL_SRV_HANDLE srv_handle,
                                srv_email_emn_funcptr_type emn_callback,
                                srv_email_funcptr_type clear_callback);


/*****************************************************************************
 * FUNCTION
 *  srv_email_clear_emn_notify
 * DESCRIPTION
 *  This function is used to clear the EMN notify function for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_clear_emn_notify(EMAIL_SRV_HANDLE srv_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_start_install
 * DESCRIPTION
 *  This function is used to start installing the OTAP.
 * PARAMETERS
 *  handle          : [OUT]     Used to store the OTAP handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_start_install(EMAIL_OTAP_HANDLE *handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_set_option
 * DESCRIPTION
 *  This function is used to set the OTAP option.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  option_p        : [IN]      The pointer point to the OTAP option
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_set_option(
                                EMAIL_OTAP_HANDLE handle,
                                srv_email_otap_option_struct *option_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_get_prof_num
 * DESCRIPTION
 *  This function is used to get the profile's number in the specified OTAP.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  prof_num        : [OUT]     Used to store the profile's number
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_get_prof_num(EMAIL_OTAP_HANDLE handle, U32 *prof_num);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_get_prof_info
 * DESCRIPTION
 *  This function is used to get the specified profile's information.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  prof_index      : [IN]      The profile's index
 *  prof_info_p     : [OUT]     Used to store the profile's information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_get_prof_info(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                srv_email_otap_prof_info_struct *prof_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_add_prof
 * DESCRIPTION
 *  This function is used to create a new account with the specified profile.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  prof_index      : [IN]      The profile's index
 *  prof_name       : [IN]      The profile name
 *  acct_id         : [OUT]     Used to store the new account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_add_prof(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                const WCHAR *prof_name,
                                EMAIL_ACCT_ID *acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_add_prof_async
 * DESCRIPTION
 *  This function is used to create a new account with the specified profile asynchronously.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  prof_index      : [IN]      The profile's index
 *  prof_name       : [IN]      The profile name
 *  acct_id         : [OUT]     Used to store the new account id
 *  req_id          : [OUT]     Used to store the request id
 *  callback        : [IN]      The pointer point to the callback function
 *  user_data       : [IN]      The pointer point to the user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_add_prof_async(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                const WCHAR *prof_name,
                                EMAIL_ACCT_ID *acct_id,
                                EMAIL_REQ_ID *req_id,
                                srv_email_otap_funcptr_type callback,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_modify_prof
 * DESCRIPTION
 *  This function is used to modify the existing account with the specified profile.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  prof_index      : [IN]      The profile's index
 *  prof_name       : [IN]      The profile name
 *  acct_id         : [IN]      The account id needed to be modified
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_modify_prof(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                const WCHAR *prof_name,
                                EMAIL_ACCT_ID acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_replace_prof
 * DESCRIPTION
 *  This function is used to replace the existing account with the specified profile.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  prof_index      : [IN]      The profile's index
 *  prof_name       : [IN]      The profile name
 *  src_acct_id     : [IN]      The account id needed to be replaced
 *  dst_acct_id     : [OUT]     Used to store the new account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_replace_prof(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                const WCHAR *prof_name,
                                EMAIL_ACCT_ID src_acct_id,
                                EMAIL_ACCT_ID *dst_acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_replace_prof_async
 * DESCRIPTION
 *  This function is used to replace the existing account with the specified profile asynchronously.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  prof_index      : [IN]      The profile's index
 *  prof_name       : [IN]      The profile name
 *  src_acct_id     : [IN]      The account id needed to be replaced
 *  dst_acct_id     : [OUT]     Used to store the new account id
 *  req_id          : [OUT]     Used to store the request id
 *  callback        : [IN]      The pointer point to the callback function
 *  user_data       : [IN]      The pointer point to the user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_replace_prof_async(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                const WCHAR *prof_name,
                                EMAIL_ACCT_ID src_acct_id,
                                EMAIL_ACCT_ID *dst_acct_id,
                                EMAIL_REQ_ID *req_id,
                                srv_email_otap_funcptr_type callback,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_update_prof
 * DESCRIPTION
 *  This function is used to update the matched account.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  prof_index      : [IN]      The profile's index
 *  prof_name       : [IN]      The profile name
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_update_prof(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                const WCHAR *prof_name);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_skip_prof
 * DESCRIPTION
 *  This function is used to skip the specified profile or all left profiles.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 *  skip_all_left   : [IN]      Skip all left profiles or not
 *  prof_index      : [IN]      The profile's index
 *  cause           : [IN]      The skip cause
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_skip_prof(
                                EMAIL_OTAP_HANDLE handle,
                                MMI_BOOL skip_all_left,
                                U32 prof_index,
                                srv_email_skip_cause_enum cause);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_finish_install
 * DESCRIPTION
 *  This function is used to finish the installing.
 * PARAMETERS
 *  handle          : [IN]      The OTAP handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_otap_finish_install(EMAIL_OTAP_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_init_acct_info
 * DESCRIPTION
 *  This function is used to initialize the account information.
 * PARAMETERS
 *  acct_info_p     : [OUT]     The pointer point to the account information structure
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_init_acct_info(srv_email_acct_info_struct *acct_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_check_valid
 * DESCRIPTION
 *  This function is used to check if the account is valid.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  is_valid        : [OUT]     Return the validity
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_check_valid(EMAIL_ACCT_ID acct_id, MMI_BOOL *is_valid);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_num
 * DESCRIPTION
 *  This function is used to get the number of email account.
 * PARAMETERS
 *  acct_num        : [OUT]     Return the account's number
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_num(U32 *acct_num);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_acct_id
 * DESCRIPTION
 *  This function is used to get the account's id in the specified scope.
 * PARAMETERS
 *  start_index     : [IN]      The account index start to get (from 1)
 *  acct_cnt        : [IN/OUT]  IN  - The length of account id buffer
 *                              OUT - The account number returned
 *  acct_id         : [OUT]     The pointer point to the account id buffer
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_acct_id(S32 start_index, S32 *acct_cnt, EMAIL_ACCT_ID *acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_name
 * DESCRIPTION
 *  This function is used to get the name of the specified account.
 * PARAMETERS
 *  acct_id         : [IN]      The account index start to get (from 1)
 *  acct_count      : [OUT]     Used to store the account name (WCHAR string)
 *  name_len        : [IN]      The length of the account name buffer (WCHAR)
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_name(EMAIL_ACCT_ID acct_id, WCHAR *acct_name, S32 name_len);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_set_default
 * DESCRIPTION
 *  This function is used to set an account as default account.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_set_default(EMAIL_ACCT_ID acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_del_default
 * DESCRIPTION
 *  This function is used to remove the default account.
 * PARAMETERS
 *
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_del_default(void);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_default
 * DESCRIPTION
 *  This function is used to get the default account.
 * PARAMETERS
 *  acct_id         : [OUT]     Return the account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_default(EMAIL_ACCT_ID *acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_create
 * DESCRIPTION
 *  This function is used to create a new account instance for the specified account.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 *  acct_handle     : [OUT]     Used to store the account instance handle
 * RETURNS
 *  The account handle.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_create(EMAIL_SRV_HANDLE srv_handle, EMAIL_ACCT_HANDLE *acct_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified account instance.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_destroy(EMAIL_ACCT_HANDLE acct_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_new
 * DESCRIPTION
 *  This function is used to create a new account.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  acct_id         : [OUT]     Return the new account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_new(EMAIL_ACCT_HANDLE acct_handle, EMAIL_ACCT_ID *acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_cancel
 * DESCRIPTION
 *  This function is used to cancel creating an account (MUST called before acct_save).
 * PARAMETERS
 *  acct_id         : [OUT]     Return the new account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_cancel(EMAIL_ACCT_ID acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_open
 * DESCRIPTION
 *  This function is used to open the specified account.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  acct_id         : [IN]      The account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_open(EMAIL_ACCT_HANDLE acct_handle, EMAIL_ACCT_ID acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_register_callback
 * DESCRIPTION
 *  This function is used to register the callback function
 *  for the specified account instance.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  callback        : [IN]      The callback function
 *  user_data       : [IN]      The user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_register_callback(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_funcptr_type callback,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_clear_callback
 * DESCRIPTION
 *  This function is used to register the callback function
 *  of the specified account instance.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_clear_callback(EMAIL_ACCT_HANDLE acct_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_register_proc_callback
 * DESCRIPTION
 *  This function is used to register the process callback function.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  proc_callback   : [IN]      The callback function
 *  proc_user_data  : [IN]      The callback user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_register_proc_callback(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_nwk_proc_funcptr_type proc_callback,
                                void *proc_user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_clear_proc_callback
 * DESCRIPTION
 *  This function is used to clear the process callback function.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_clear_proc_callback(EMAIL_ACCT_HANDLE acct_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_permission
 * DESCRIPTION
 *  This function is used to get the editable permission.
 *  If the instance wants to get the permission,
 *  the account in it must meet the following conditions at the same time:
 *   1. it is opened by this instance only.
 *   2. it is not used now.
 *  After getting successfully, the permission can not be released until the handle is destroyed.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_permission(EMAIL_ACCT_HANDLE acct_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_edit
 * DESCRIPTION
 *  This function is used to edit the account information.
 *  The instance with the permission can edit the account's information only.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  acct_info_p     : [IN]      The pointer point to the parameter struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_edit(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_info_struct *acct_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_save
 * DESCRIPTION
 *  This function is used to save the account information into storage.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_save(EMAIL_ACCT_HANDLE acct_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_save_async
 * DESCRIPTION
 *  This function is used to save the account information into storage.
 * PARAMETERS
 *  acct_handle                 : [IN]      The account handle
 *  async_save_acct_callback    : [IN]      The callback function
 *  async_save_acct_user_data   : [IN]      The callback user_data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_save_async(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_async_save_acct_callback async_save_acct_callback,
                                void *async_save_acct_user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_save_async_abort
 * DESCRIPTION
 *  This function is used to abort the saving account.
 * PARAMETERS
 * 
 * RETURNS
 *  void
 ****************************************************************************/
extern void srv_email_acct_save_async_abort(void);

/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_read
 * DESCRIPTION
 *  This function is used to read the information of the specified account.
 *  The instance without the permission can also read the account's information.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  acct_info_p     : [OUT]     Used to store the account information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_read(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_info_struct *acct_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_nwk_test
 * DESCRIPTION
 *  This function is used to test the incoming/outgoing connection for the new account created.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  incoming_server : [IN]      Test the incoming/outgoing connection
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_nwk_test(
                                EMAIL_ACCT_HANDLE acct_handle,
                                MMI_BOOL incoming_server,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_connect
 * DESCRIPTION
 *  This function is used to connect the incoming/outgoing server.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  incoming_server : [IN]      Connect the incoming/outgoing server
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_connect(
                                EMAIL_ACCT_HANDLE acct_handle,
                                MMI_BOOL incoming_server,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_disconnect
 * DESCRIPTION
 *  This function is used to disconnect the incoming/outgoing server.
 * PARAMETERS
 *  acct_handle         : [IN]      The account handle
 *  incoming_server     : [IN]      Disconnect the incoming/outgoing server
 *  force_disconnect    : [IN]      Disconnect forcedly or not
 *  req_id              : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_disconnect(
                                EMAIL_ACCT_HANDLE acct_handle,
                                MMI_BOOL incoming_server,
                                MMI_BOOL force_disconnect,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_send
 * DESCRIPTION
 *  This function is used to send the emails in the outbox of this account.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  move_to_sent    : [IN]      Move to sent box or not after send successfully
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_send(
                                EMAIL_ACCT_HANDLE acct_handle,
                                MMI_BOOL move_to_sent,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_receive
 * DESCRIPTION
 *  This function is used to receive the emails of this account from server.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  recv_opt        : [IN]      The receive option
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_receive(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_receive_option_enum recv_opt,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_sync
 * DESCRIPTION
 *  This function is used to sync the emails of this account with server.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_sync(
                                EMAIL_ACCT_HANDLE acct_handle,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_refresh
 * DESCRIPTION
 *  This function is used to refresh the inbox.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  recv_opt        : [IN]      The receive option
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_refresh(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_receive_option_enum recv_opt,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_cache_notify_set
 * DESCRIPTION
 *  This function is used to register the unread modification callback function.
 * PARAMETERS
 *  callback        : [IN]      The callback function
 *  userdata        : [IN]      The userdata pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_email_acct_cache_notify_set(
    srv_email_all_msg_unread_notify_funcptr callback, void* userdata);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_total_unread_num_get
 * DESCRIPTION
 *  This function is used to get the total number of the unread emails
 * PARAMETERS
 *  total_unread_num    : [OUT]     Return the total number
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_acct_total_unread_num_get(U32 *total_unread_num);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_cache_get
 * DESCRIPTION
 *  This function is used to get the cached account information.
 *  IT IS RECOMMANDED to use this function to get account information.
 * PARAMETERS
 *  acct_id         : [In]      The account id
 *  acct_info_cache : [OUT]     Return the account information
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_email_acct_cache_get(EMAIL_ACCT_ID acct_id, srv_email_acct_info_cache_struct *acct_info_cache);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_list_remote_fldr
 * DESCRIPTION
 *  This function is used to list the remote folders.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  fldr_cnt        : [IN]      The count of the folder can be listed
 *  req_id          : [OUT]     Return the request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_list_remote_fldr(
                                EMAIL_ACCT_HANDLE acct_handle,
                                S32 fldr_cnt,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_remote_fldr_num
 * DESCRIPTION
 *  This function is used to get the number of the remote folders.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  num             : [OUT]     Return the number of the remote folders.
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_remote_fldr_num(
                                EMAIL_ACCT_HANDLE acct_handle,
                                U32 *num);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_remote_fldr_info
 * DESCRIPTION
 *  This function is used to get the information of the remote folders.
 * PARAMETERS
 *  acct_handle             : [IN]      The account handle
 *  start_index             : [IN]      The start index, start from 0
 *  fldr_cnt                : [IN/OUT]  The folder count
 *  remote_fldr_info_list   : [OUT]     Return the information of the remote folders.
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_remote_fldr_info(
                                EMAIL_ACCT_HANDLE acct_handle,
                                U32 start_index,
                                U32 *fldr_cnt,
                                srv_email_acct_remote_fldr_info_strcut *remote_fldr_info_list);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_subscribe_remote_fldr
 * DESCRIPTION
 *  This function is used to subscribe the IMAP4 remote folders
 *  (used for IMAP4 remote folder only).
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  index           : [IN]      The folder index
 *  subscribe       : [IN]      Subscribe/Unsubscribe the folder
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_subscribe_remote_fldr(
                                EMAIL_ACCT_HANDLE acct_handle,
                                U32 index,
                                MMI_BOOL subscribe);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_remote_fldr_submit_subscribe
 * DESCRIPTION
 *  This function is used to submit the subscribing for the remote folders.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_remote_fldr_submit_subscribe(EMAIL_ACCT_HANDLE acct_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_fldr_num
 * DESCRIPTION
 *  This function is used to get the folder's number.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  fldr_type       : [IN]      The folder type
 *  fldr_num        : [OUT]     Return the folder's number
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_fldr_num(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_fldr_type_enum fldr_type,
                                S32 *fldr_num);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_fldr_id
 * DESCRIPTION
 *  This function is used to get the folder's id.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  local_fldr      : [IN]      The local folder or not
 *  start_index     : [IN]      The folder index start to get (from 1)
 *  fldr_cnt        : [IN/OUT]  IN  - The length of folder id buffer
 *                              OUT - The folder number returned
 *  fldr_id         : [OUT]     The pointer point to the folder id buffer
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_fldr_id(
                                EMAIL_ACCT_HANDLE acct_handle,
                                srv_email_acct_fldr_type_enum fldr_type,
                                S32 start_index,
                                S32 *fldr_cnt,
                                EMAIL_FLDR_ID *fldr_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_get_fldr_info
 * DESCRIPTION
 *  This function is used to get the folder's information.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  local_fldr      : [IN]      The local folder or not
 *  fldr_id         : [IN]      The folder id
 *  fldr_info_p     : [OUT]     Used to store the folder's information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_get_fldr_info(
                                EMAIL_ACCT_HANDLE acct_handle,
                                EMAIL_FLDR_ID fldr_id,
                                srv_email_acct_folder_struct *fldr_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_delete
 * DESCRIPTION
 *  This function is used to delete the specified account.
 *  The account must meet the following conditions at the same time:
 *   1. it is not opened by any instance.
 *   2. it is not used now.
 *  When deleting account, all emails in it will be deleted at the same time.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  req_id          : [OUT]     Return the request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_delete(EMAIL_ACCT_ID acct_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_abort
 * DESCRIPTION
 *  This function is used to abort async request for the specified account instance.
 * PARAMETERS
 *  acct_handle     : [IN]      The account handle
 *  req_id          : [IN]      The async request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_abort(EMAIL_ACCT_HANDLE acct_handle, EMAIL_REQ_ID req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_create
 * DESCRIPTION
 *  This function is used to create a folder instance for the following operations.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 *  fldr_create_p   : [IN]      Information used for create folder handle
 *  fldr_handle     : [OUT]     Used to store the folder instance handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_create(
                                EMAIL_SRV_HANDLE srv_handle,
                                srv_email_fldr_create_info_struct *fldr_create_p,
                                EMAIL_FLDR_HANDLE *fldr_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_create_by_type
 * DESCRIPTION
 *  This function is used to create a folder instance by type for the following operations.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 *  fldr_create_p   : [IN]      Information used for create folder handle
 *  fldr_handle     : [OUT]     Used to store the folder instance handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_create_by_type(
                                EMAIL_SRV_HANDLE srv_handle,
                                srv_email_fldr_create_by_type_info_struct *fldr_create_p,
                                EMAIL_FLDR_HANDLE *fldr_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified folder instance.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_destroy(EMAIL_FLDR_HANDLE fldr_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_regist_callback
 * DESCRIPTION
 *  This function is used to regist callback function for async operation.
 * PARAMETERS
 *  fldr_handle     : [IN]      This callback is for witch folder object
 *  callback        : [IN]      Callback function for async operation
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_regist_callback(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_funcptr_type callback,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_clear_callback
 * DESCRIPTION
 *  This function is used to clear callback function for async operation.
 * PARAMETERS
 *  fldr_handle     : [IN]      Clear witch folder object's callback
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_clear_callback(EMAIL_FLDR_HANDLE fldr_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_regist_notify
 * DESCRIPTION
 *  This function is used to register the notify callback function.
 * PARAMETERS
 *  fldr_handle         : [IN]      The folder handle
 *  notify_func         : [IN]      The callback function
 *  notify_user_data    : [IN]      The callback user data
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_regist_notify(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_notify_func notify_func,
                                void *notify_user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_clear_notify
 * DESCRIPTION
 *  This function is used to clear the notify callback function.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_clear_notify(EMAIL_FLDR_HANDLE fldr_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_regist_proc_callback
 * DESCRIPTION
 *  This function is used to register the process callback function.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  proc_callback   : [IN]      The callback function
 *  proc_user_data  : [IN]      The callback user data
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_regist_proc_callback(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_nwk_proc_funcptr_type proc_callback,
                                void *proc_user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_clear_proc_callback
 * DESCRIPTION
 *  This function is used to clear the process callback function.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_clear_proc_callback(EMAIL_FLDR_HANDLE fldr_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_list_msg
 * DESCRIPTION
 *  This function is used to list the messages in this instance from storage.
 *  If sorting when listing message, it will take more time than just in order of storage.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  text_type       : [IN]      The text type
 *  date_type       : [IN]      The date time type
 *  req_id          : [OUT]     Used to store the async request id
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_list_msg(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_eamil_msg_text_type_enum text_type,
                                srv_email_msg_date_type_enum date_type,
                                EMAIL_REQ_ID *req_id);


extern srv_email_result_enum srv_email_fldr_list_msg_ext(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_eamil_msg_text_type_enum text_type,
                                srv_email_msg_date_type_enum date_type,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_msg_list
 * DESCRIPTION
 *  This function is used to get the message list from this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  start_index     : [IN]      The start index, start from 0
 *  msg_count       : [IN/OUT]  The message count
 *  msg_info_p      : [IN]      Return the message information
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_get_msg_list(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                U32 start_index,
                                U32 *msg_count,
                                srv_email_fldr_msg_info_struct *msg_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_basic_info
 * DESCRIPTION
 *  This function is used to get the basic information of this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  basic_info_p    : [OUT]     Used to store basic information of folder
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_get_basic_info(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_basic_info_struct *basic_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_name
 * DESCRIPTION
 *  This function is used to get name of this folder
 *  It is used for only IMAP4 remote folder or user define folder
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  buff_len        : [IN/OUT]  Length of buffer for name
 *  name            : [OUT]     Buffer for name
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_get_name(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                WCHAR *name,
                                U32 len);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_get_msg_num
 * DESCRIPTION
 *  This function is used to get the message number in this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  msg_num_type    : [IN]      All message, unread message or marked message.
 *  number          : [OUT]     Used to store the number
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_get_msg_num(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_get_msg_num_type_enum msg_num_type,
                                S32 *number);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_sort_msg
 * DESCRIPTION
 *  This function is used to sort the message in this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  sort_msg_p      : [IN]      The pointer point to the parameter structure
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_sort_msg(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_sort_msg_struct *sort_msg_p);



/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_sort_msg_async
 * DESCRIPTION
 *  This function is used to sort the message in this instance.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  sort_msg_p      : [IN]      The pointer point to the parameter structure
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_sort_msg_async(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_sort_msg_struct *sort_msg_p,
                                EMAIL_REQ_ID *req_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_mark_msg
 * DESCRIPTION
 *  This function is used to mark or unmark one message in this instance.
 *  The mark here is used for multiple selection.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  mark_all        : [IN]      Mark all messages or not
 *  msg_id          : [IN]      The message id
 *  msrk_msg        : [IN]      Mark or unmark
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_fldr_mark_msg(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                MMI_BOOL mark_all,
                                EMAIL_MSG_ID msg_id,
                                MMI_BOOL mark_msg);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_set_msg_flag
 * DESCRIPTION
 *  This function is used to set the flags of the specified emails.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  set_flag_p      : [IN]      The pointer point to the set flag structure
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_set_msg_flag(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_set_msg_flag_struct *set_flag_p,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_delete_msg
 * DESCRIPTION
 *  This function is used to delete the specified emails.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  delete_msg_p    : [IN]      The pointer point to the delete message structure
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_delete_msg(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_fldr_delete_msg_struct *delete_msg_p,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_send
 * DESCRIPTION
 *  This function is used to send the emails in this instance.
 *  It is used for outbox instance only, and will send all message in outbox.
 *  No such function like mark some message and send them and if send one message in message list screen,
 *  app have to create handle of that message and use message handle send function
 * PARAMETERS
 *  fldr_handle      : [IN]     The folder handle
 *  move_to_sent     : [IN]     Move to sent box or not after send successfully
 *  req_id           : [OUT]    Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_send(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                MMI_BOOL move_to_sent,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_receive
 * DESCRIPTION
 *  This function is used to receive the emails for this instance.
 *  It is used for inbox and IMAP4 remote folder instance only.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  recv_opt        : [IN]      The receive option
 *  req_id          : [OUT]     Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_receive(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                srv_email_receive_option_enum recv_opt,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_sync
 * DESCRIPTION
 *  This function is used to sync the emails in this instance with server.
 *  It is used for inbox and IMAP4 remote folder instance only.
 * PARAMETERS
 *  fldr_handle     : [IN]      The account handle
 *  req_id          : [OUT]     Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_sync(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_abort
 * DESCRIPTION
 *  This function is used to abort async request for the specified folder instance.
 * PARAMETERS
 *  fldr_handle     : [IN]      The folder handle
 *  req_id          : [IN]      The async request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_abort(
                                EMAIL_FLDR_HANDLE fldr_handle,
                                EMAIL_REQ_ID req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_inbox_get_recent_list
 * DESCRIPTION
 *  This function is used to get the id list of the recent emails form inbox.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  start_index     : [IN]      The start index, start from 0
 *  count           : [IN/OUT]  The count of the email ids
 *  flag_mask       : [IN]      The mask set of the flag
 *  matched_flag    : [IN]      The flags should be matched
 *  msg_array       : [OUT]     Used to store the email ids
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_fldr_inbox_get_recent_list(
                                EMAIL_ACCT_ID acct_id,
                                S32 start_index, 
                                U32 *count,
                                U8 flag_mask, 
                                EMAIL_MSG_FLAG matched_flag,
                                srv_email_inbox_index_msg_struct *msg_array);

extern srv_email_result_enum srv_email_fldr_get_all_msg_id(
                                EMAIL_ACCT_ID acct_id,
                                EMAIL_FLDR_ID fldr_id,
                                U8 flag_mask, 
                                EMAIL_MSG_FLAG matched_flag,
                                U32 *count,
                                EMAIL_MSG_ID *msg_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_check_valid
 * DESCRIPTION
 *  This function is used to check if the message id is valid or not.
 * PARAMETERS
 *  msg_id          : [IN]      The message id
 *  is_valid        : [OUT]     The validity of the message id
 *                              MMI_TRUE: valid; MMI_FALSE: invalid
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_check_valid(EMAIL_MSG_ID msg_id, MMI_BOOL *is_valid);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_create
 * DESCRIPTION
 *  This function is used to create a new message instance.
 * PARAMETERS
 *  srv_handle       : [IN]     The service handle
 *  msg_handle       : [OUT]    Return the message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_create(
                                EMAIL_SRV_HANDLE srv_handle,
                                EMAIL_MSG_HANDLE *msg_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_set_new
 * DESCRIPTION
 *  This function is used to create a new message.
 * PARAMETERS
 *  msg_handle       : [IN]     The message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_set_new(EMAIL_MSG_HANDLE msg_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_parse_file
 * DESCRIPTION
 *  This function is used to parse the specified email file.
 * PARAMETERS
 *  msg_handle       : [IN]     The message handle
 *  file_path        : [IN]     The pointer point to the parameter struct
 *  get_attach_info  : [IN]     Parse the attachment information or not
 *  save_attach      : [IN]     Save the attachment or not
 *  req_id           : [OUT]    Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_parse_file(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *file_path,
                                MMI_BOOL get_attach_info,
                                MMI_BOOL save_attach,
                                EMAIL_REQ_ID *req_id);



/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_parse_file
 * DESCRIPTION
 *  This function is used to parse the specified email file.
 * PARAMETERS
 *  msg_handle       : [IN]     The message handle
 *  file_path        : [IN]     The pointer point to the parameter struct
 *  get_attach_info  : [IN]     Parse the attachment information or not
 *  save_attach      : [IN]     Save the attachment or not
 *  req_id           : [OUT]    Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_parse_partial_file(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *file_path,
                                MMI_BOOL get_attach_info,
                                MMI_BOOL save_attach,
                                EMAIL_REQ_ID *req_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_open
 * DESCRIPTION
 *  This function is used to open the specified message.
 * PARAMETERS
 *  msg_handle       : [IN]     Used to store the message instance handle
 *  acct_id          : [IN]     Whitch account is the message belongs to
 *  fldr_id          : [IN]     Whitch folder is the message belongs to
 *  msg_id           : [IN]     The message id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_open(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_ACCT_ID acct_id,
                                EMAIL_FLDR_ID fldr_id,
                                EMAIL_MSG_ID msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_regist_callback
 * DESCRIPTION
 *  This function is used to regist callback function for async operation.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  callback        : [IN]      The callback function
 *  user_data       : [IN]      The callback user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_regist_callback(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_funcptr_type callback,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_clear_callback
 * DESCRIPTION
 *  This function is used to clear callback function for async operation.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_clear_callback(EMAIL_MSG_HANDLE msg_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_regist_proc_callback
 * DESCRIPTION
 *  This function is used to register the process callback function.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  proc_callback   : [IN]      The callback function
 *  Proc_user_data  : [IN]      The callback user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_regist_proc_callback(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_nwk_proc_funcptr_type proc_callback,
                                void *proc_user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_clear_proc_callback
 * DESCRIPTION
 *  This function is used to clear the process callback function.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_clear_proc_callback(EMAIL_MSG_HANDLE msg_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_regist_notify
 * DESCRIPTION
 *  This function is used to register the notify callback function.
 * PARAMETERS
 *  notify_func         : [IN]      The callback function
 *  notify_user_data    : [IN]      The callback user data
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_msg_regist_notify(
                                srv_email_notify_func notify_func,
                                void *notify_user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_clear_notify
 * DESCRIPTION
 *  This function is used to clear the notify callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  The result code.
 *****************************************************************************/
extern srv_email_result_enum srv_email_msg_clear_notify(void);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_basic_info
 * DESCRIPTION
 *  This function is used get the basic information of the specified message.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  basic_info_p    : [OUT]     Return the basic information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_basic_info(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_get_basic_info_struct *basic_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_sender
 * DESCRIPTION
 *  This function is used to get the address of the sender.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  addr_info_p     : [OUT]     The pointer point to the sender's address struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_sender(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_struct *addr_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_reply_to
 * DESCRIPTION
 *  This function is used to get the address of the reply-to.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  addr_info_p     : [OUT]     The pointer point to the reply to's address struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_reply_to(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_struct *addr_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_recipient
 * DESCRIPTION
 *  This function is used to get the address of the recipient.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  get_recipient_p : [OUT]     The pointer point to the get recipient struct
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_recipient(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_get_recipient_struct *get_recipient_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_subject_len
 * DESCRIPTION
 *  This function is used to get length of subject.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  len             : [OUT]     Return the length of subject in bytes
 *  charset         : [OUT]     Return the charset of the subject
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_subject_len(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 *len,
                                S32 *charset);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_subject
 * DESCRIPTION
 *  This function is used to get the partial subject string.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  buff            : [IN]      Buffer to store subject or file path
 *  len             : [IN/OUT]  The leng of subject
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_subject(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *subject,
                                U32 *len);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_content_len
 * DESCRIPTION
 *  This function is used to get the length of content.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  len             : [OUT]     Return the length of content in bytes
 *  charset         : [OUT]     Return the charset of the content
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_content_len(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 *len,
                                S32 *charset);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_content
 * DESCRIPTION
 *  This function is used to get the partial content string.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  buff_type       : [IN]      Real buffer for content or file path
 *  buff            : [OUT]     Return the content string
 *  len             : [IN/OUT]  The leng of content
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_content(
                                EMAIL_MSG_HANDLE msg_handle,
                                MMI_BOOL buff_type,
                                WCHAR *buff,
                                U32 *len);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_cont_status
 * DESCRIPTION
 *  This function is used to check the status of the content.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  text_status     : [OUT]     Return the status of the text content
 *  html_status     : [OUT]     Return the status of the HTML content
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_cont_status(
                                EMAIL_MSG_HANDLE msg_handle,
                                S8 *text_status,
                                S8 *html_status);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_cont_size
 * DESCRIPTION
 *  This function is used to check the status of the content.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  text_size     : [OUT]     Return the status of the text content
 *  html_size     : [OUT]     Return the status of the HTML content
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_cont_size(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 *text_size,
                                U32 *html_size);


/*****************************************************************************
 * FUNCTION
 *  srv_email_cbm_hold
 * DESCRIPTION
 *  This function is used to check the status of the content.
 * PARAMETERS
 *  acct_id      : [IN]      
 *  hold_outgoing : [IN]     
 *  hold_incoming : [IN]     
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_cbm_hold(
                                EMAIL_ACCT_ID acct_id,
                                MMI_BOOL hold_outgoing,
                                MMI_BOOL hold_incoming);


/*****************************************************************************
 * FUNCTION
 *  srv_email_cbm_release
 * DESCRIPTION
 *  This function is used to check the status of the content.
 * PARAMETERS
 *  acct_id      : [IN]      
 *  hold_outgoing : [IN]     
 *  hold_incoming : [IN]     
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_cbm_release(
                                EMAIL_ACCT_ID acct_id,
                                MMI_BOOL hold_outgoing,
                                MMI_BOOL hold_incoming);

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_html_file
 * DESCRIPTION
 *  This function is used to get file of html.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  path            : [IN]      The path of html file
 *  len             : [IN/OUT]  Leng of buffer to store path
 *  charset         : [OUT]     Return the charset of the HTML content
 *  get_src_file    : [IN]      If get the source file or not
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_html_file(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *path,
                                U32 *len,
                                CHAR *charset,
                                MMI_BOOL get_src_file);

/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_html_file_async
 * DESCRIPTION
 *  This function is used to get the content path asynchronily, please register
 *  callback before call this function.
 * PARAMETERS
 *  msg_handle      : [IN]  The message handle
 *  path            : [IN]  Path of html file
 *  len             : [IN]  Length of buffer to store path
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_html_path_async(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *path,
                                U32 len,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_attachment_info
 * DESCRIPTION
 *  This function is used to get path of certian attachment.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  start_index     : [IN]      Index of attachment app want to get
 *  number          : [IN/OUT]  How much app want and how mucn service given
 *  attach_info_p   : [OUT]     Array to store the attachment information
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_attachment_info(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 start_index,
                                S32 *number,
                                srv_email_attach_struct *attach_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_attachment_path
 * DESCRIPTION
 *  This function is used to get path of certian attachment.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  attach_id       : [IN]      The attachment id
 *  attach_path_p   : [IN/OUT]  Buffer to set parameter and get attachment path
 *  path_len        : [IN]      The buffer length
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_attachment_path(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_ATTCH_ID attach_id,
                                WCHAR *attach_path_p,
                                U32 path_len);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_get_permission
 * DESCRIPTION
 *  This function is used to get the editable permission.
 *  The instance can get the permission only when the email is opened by this instance only.
 *  After getting successfully, the permission can not be released until the handle is destroyed.
 *  The operations need to get permission are as follow:
 *  srv_email_msg_edi();
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_get_permission(EMAIL_MSG_HANDLE msg_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_basic_info
 * DESCRIPTION
 *  This function is used to update the basic information.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  basic_info_p    : [IN]      The pointer point to the basic information structure
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_basic_info(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_update_basic_info_struct *basic_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_reply_to
 * DESCRIPTION
 *  This function is used to update the reply-to address.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  addr_info_p     : [IN]      The pointer point to the reply-to address
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_reply_to(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_struct *addr_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_sender
 * DESCRIPTION
 *  This function is used to update the sender address.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  addr_info_p     : [IN]      The pointer point to the sender address
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_sender(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_struct *addr_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_recipient
 * DESCRIPTION
 *  This function is used to update the recipient address.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  addr_type       : [IN]      The recipient type
 *  addr_num        : [IN]      The address number
 *  addr_list       : [IN]      The address list
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_recipient(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_addr_type_enum addr_type,
                                U32 addr_num,
                                srv_email_addr_struct *addr_list);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_attach
 * DESCRIPTION
 *  This function is used to update the attachment information.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  attach_num      : [IN]      The attachment number
 *  attach_info_p   : [IN]      The attachment info list
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_attach(
                                EMAIL_MSG_HANDLE msg_handle,
                                U32 attach_num,
                                srv_email_attach_struct *attach_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_subject
 * DESCRIPTION
 *  This function is used to update the subject.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  subject         : [IN]      Buffer to store subject
 *  charset         : [IN]      The charset of subject
 *  len             : [IN]      The length of subject
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_subject(
                                EMAIL_MSG_HANDLE msg_handle,
                                WCHAR *subject,
                                S32 charset,
                                U32 len);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_update_content
 * DESCRIPTION
 *  This function is used to update the content information.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  content_info_p  : [IN]      The pointer point to the content info
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_update_content(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_update_content_struct *content_info_p);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_set_flag
 * DESCRIPTION
 *  This function is used to set the message flag.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  flag_mask       : [IN]      The mask of the flags
 *  flag            : [IN]      The message flags
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_set_flag(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 flag_mask,
                                EMAIL_MSG_FLAG flag);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_save
 * DESCRIPTION
 *  This function is used to update the email information of handle into storage.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  save_part       : [IN]      Indicate which part app want to save to storage
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_save(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_save_part_enum save_part,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_save_new
 * DESCRIPTION
 *  This function is used to create a new message with the information of current msg object
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  dest_acct_id    : [IN]      The destination account id
 *  dest_fldr_id    : [IN]      The destination folder id
 *  new_msg_id      : [OUT]     The message id
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_save_new(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_ACCT_ID dest_acct_id,
                                EMAIL_FLDR_ID dest_fldr_id,
                                EMAIL_MSG_ID *msg_id,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_send
 * DESCRIPTION
 *  This function is used to send the specified email.
 *  The email in outbox can be sent only.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  move_to_sent    : [IN]      Move to sent box or not after send successfully
 *  req_id          : [IN]      Used to store the request id when async
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_send(
                                EMAIL_MSG_HANDLE msg_handle,
                                MMI_BOOL move_to_sent,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_retrieve
 * DESCRIPTION
 *  This function is used to retrieve the specified email.
 *  The instance with the permission can retrieve the email only.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  retrieve_opt    : [IN]      Send related options
 *  attach_id       : [IN]      This parameter is valid only when
 *                              retrieve_opt == SRV_EMAIL_RETRIEVE_SINGLE_ATTACHMENT
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_retrieve(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_retrieve_option_enum retrieve_opt,
                                EMAIL_ATTCH_ID attach_id,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_delete
 * DESCRIPTION
 *  This function is used to delete the specified email.
 *  The email only used by this instance can be deleted.
 *  After operation, msg handle will be invalid
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  delete_header   : [IN]      Delete the email header from local or not
 *  delete_server   : [IN]      Delete the email from local and server together or not
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_delete(
                                EMAIL_MSG_HANDLE msg_handle,
                                MMI_BOOL delete_header,
                                MMI_BOOL delete_server);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_move
 * DESCRIPTION
 *  This function is used to move the specified email into the specified account and folder.
 *  The email only used by this instance can be moved.
 *  If operation success, msg handle will be invalid
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  dst_acct_id     : [IN]      The destination account id
 *  dst_fldr_id     : [IN]      The destination folder id
 *  new_msg_id      : [OUT]     The new message id after moving
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_move(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_ACCT_ID dst_acct_id,
                                EMAIL_FLDR_ID dst_fldr_id,
                                EMAIL_MSG_ID *new_msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_move
 * DESCRIPTION
 *  This function is used to copy the specified email into the specified account and folder.
 *  The email's information in this instance will be stored as a new email.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  msg_copy_p      : [IN]      The pointer point to the parameter struct
 *  req_id          : [OUT]     Return the request id when wouldblock
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_copy(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_msg_copy_struct *msg_copy_p,
                                EMAIL_REQ_ID *req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified message instance.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_destroy(EMAIL_MSG_HANDLE msg_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_abort
 * DESCRIPTION
 *  This function is used to abort the async request for the specified message instance.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  req_id          : [IN]      The async request id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_msg_abort(
                                EMAIL_MSG_HANDLE msg_handle,
                                EMAIL_REQ_ID req_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_app_init_set_callback
 * DESCRIPTION
 *  This function is used to set APP initialization callback.
 * PARAMETERS
 *  callback        : [IN]      The callback function
 *  user_data       : [IN]      The callback user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_app_init_set_callback(
                                srv_email_app_init_funcptr_type callback,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_srv_init_state
 * DESCRIPTION
 *  This function is used to query SRV initialization state.
 * PARAMETERS
 *  void
 * RETURNS
 *  The initialization state.
 ****************************************************************************/
extern srv_email_init_state_enum srv_email_get_srv_init_state(void);


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_root_path
 * DESCRIPTION
 *  This function is used to get Email root path.
 * PARAMETERS
 *  void
 * RETURNS
 *  The root path pointer.
 ****************************************************************************/
extern CHAR* srv_email_get_root_path(void);


/*****************************************************************************
 * FUNCTION
 *  srv_email_set_drive
 * DESCRIPTION
 *  This function is used to set Email drive.
 * PARAMETERS
 *  drive            : [IN]      The dirve
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_set_drive(CHAR drive);


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_drive
 * DESCRIPTION
 *  This function is used to set Email drive.
 * PARAMETERS
 *  void
 * RETURNS
 *  The drive.
 ****************************************************************************/
extern CHAR srv_email_get_drive(void);


/*****************************************************************************
 * FUNCTION
 *  srv_email_register_app_id_query_callback
 * DESCRIPTION
 *  This function is used to register the app id query callback function.
 * PARAMETERS
 *  srv_handle      : [IN]      The service handle
 *  callback        : [IN]      The query callback function
 * RETURNS
 *  The error code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_register_app_id_query_callback(
                                EMAIL_SRV_HANDLE srv_handle,
                                srv_email_app_info_query_funcptr_type callback);


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_id_to_fldr_type
 * DESCRIPTION
 *  This function is used to convert folder id to folder type.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  fldr_id         : [IN]      The folder type
 * RETURNS
 *  The folder type.
 ****************************************************************************/
extern srv_email_fldr_type_enum srv_email_fldr_id_to_fldr_type(
                                EMAIL_ACCT_ID acct_id,
                                EMAIL_FLDR_ID fldr_id);

/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_type_to_fldr_id
 * DESCRIPTION
 *  This function is used to convert an account's basic folder type to folder id.
 * PARAMETERS
 *  acct_id         : [IN]      The account id
 *  fldr_type       : [IN]      The folder type (only Basic folder type supported)
 * RETURNS
 *  Folder id, if not valid type, return EMAIL_FLDR_INVALID_ID.
 ****************************************************************************/
extern EMAIL_FLDR_ID srv_email_fldr_type_to_fldr_id(
                                EMAIL_ACCT_ID acct_id,
                                srv_email_fldr_type_enum fldr_type);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_pre_install_open
 * DESCRIPTION
 *  This function is used to get a handle for create pre-install account.
 * PARAMETERS
 *  handle          : [OUT]     The account pre-install handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_pre_install_open(EMAIL_SRV_HANDLE *handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_pre_install_create
 * DESCRIPTION
 *  This function is used to create a pre-install account.
 * PARAMETERS
 *  handle          : [IN]      The account pre-install handle
 *  acct_info       : [IN]      The account infomation
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_pre_install_create(
                                EMAIL_SRV_HANDLE handle,
                                srv_email_acct_info_struct *acct_info);


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_pre_install_close
 * DESCRIPTION
 *  This function is used to free pre-install account's handle.
 * PARAMETERS
 *  handle          : [IN]]      The account pre-install handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_acct_pre_install_close(EMAIL_SRV_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_msg_size
 * DESCRIPTION
 *  This function is used to compose Email's size by handle.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 *  callback        : [IN]      The callback function
 *  user_data       : [IN]      The callback user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_comp_msg_size(
                                EMAIL_MSG_HANDLE msg_handle,
                                srv_email_comp_funcptr_type callback,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_msg_size_abort
 * DESCRIPTION
 *  This function is used to stop composing Email's size by handle.
 * PARAMETERS
 *  msg_handle      : [IN]      The message handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_comp_msg_size_abort(EMAIL_MSG_HANDLE msg_handle);


/*****************************************************************************
 * FUNCTION
 *  srv_email_errno_get
 * DESCRIPTION
 *  This function is used to get Service's detail errno.
 *  Now it's only used to get File System's detail errno.
 * PARAMETERS
 *  void
 * RETURNS
 *  The detail error code.
 ****************************************************************************/
extern S32 srv_email_errno_get(void);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_recent_list_query_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of querying recent list MSG id.
 * PARAMETERS
 *  ids             : [OUT]     MSG id array pointer
 *  num             : [OUT]     array size
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_recent_list_query_funcptr_type)(EMAIL_MSG_ID **ids, U32 *num);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_recent_list_answer_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of answering recent list query.
 * PARAMETERS
 *  ids             : [OUT]     MSG id array pointer
 *  chg             : [IN]      whether MSG id's info has changed
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_recent_list_answer_funcptr_type)(EMAIL_MSG_ID *ids, MMI_BOOL chg);


/*****************************************************************************
 * FUNCTION
 *  srv_email_recent_list_notify_set
 * DESCRIPTION
 *  This function is used to set recent list nofity callback function.
 * PARAMETERS
 *  query           : [IN]      query function
 *  answer          : [IN]      answer function
 * RETURNS
 *  void
 ****************************************************************************/
extern void srv_email_recent_list_notify_set(
                srv_email_recent_list_query_funcptr_type query,
                srv_email_recent_list_answer_funcptr_type answer);


/*****************************************************************************
 * FUNCTION
 *  srv_email_recent_envent_unread_query
 * DESCRIPTION
 *  This function is used to query unread MSG id for recent list.
 * PARAMETERS
 *  count           : [IN]      MSG id count
 *  msg_id          : [OUT]     MSG id array pointer
 *  unread          : [OUT]     unread number
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 ****************************************************************************/
extern MMI_BOOL srv_email_recent_envent_unread_query(U32 count, EMAIL_MSG_ID *msg_id, S8 *unread);


/* The message basic status structure */
typedef struct
{
    EMAIL_MSG_ID msg_id;    /* The message id */
    EMAIL_MSG_PRIO prio;    /* The priority */
    MMI_BOOL unread;        /* The read/unread status */
    MMI_BOOL has_attch;     /* If has attachment or not */
    void *userdata;         /* The user data */
} srv_email_msg_prio_read_struct;


/*****************************************************************************
 * FUNCTION
 *  srv_email_recent_envent_unread_query
 * DESCRIPTION
 *  This function is used to query MSG basic info with MSG id for recent event.
 * PARAMETERS
 *  msg             : [IN]      the pointer of this struct array
 *  count           : [IN]      the MSG number for this query
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_recent_envent_info_query(srv_email_msg_prio_read_struct *msg, U32 count);


/*****************************************************************************
 * FUNCTION
 *  srv_email_storage_is_reset_during_init
 * DESCRIPTION
 *  This function is used to get whether storage has been reset during INIT.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 ****************************************************************************/
extern MMI_BOOL srv_email_storage_is_reset_during_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_id_to_acct_id
 * DESCRIPTION
 *  This function is used to get the account id from the message id.
 * PARAMETERS
 *  msg_id          : [IN]      The message id
 * RETURNS
 *  The account id.
 ****************************************************************************/
extern EMAIL_ACCT_ID srv_email_msg_id_to_acct_id(EMAIL_MSG_ID msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_msg_id_to_fldr_id
 * DESCRIPTION
 *  This function is used to get the folder id from the message id.
 * PARAMETERS
 *  msg_id          : [IN]      The message id
 * RETURNS
 *  The folder id.
 ****************************************************************************/
extern EMAIL_FLDR_ID srv_email_msg_id_to_fldr_id(EMAIL_MSG_ID msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_attch_id_to_msg_id
 * DESCRIPTION
 *  This function is used to get the message id from the attachment id.
 * PARAMETERS
 *  attch_id        : [IN]      The attachment id
 * RETURNS
 *  The message id.
 ****************************************************************************/
extern EMAIL_MSG_ID srv_email_attch_id_to_msg_id(EMAIL_ATTCH_ID attch_id);


/* The object management's notify type */
typedef enum
{
    SRV_EMAIL_OM_NOTIFY_OBJ_ACCT = 0,   /* The account object */
    SRV_EMAIL_OM_NOTIFY_OBJ_FLDR,       /* The folder object */
    SRV_EMAIL_OM_NOTIFY_OBJ_MSG,        /* The message object */
    SRV_EMAIL_OM_NOTIFY_OBJ_TOTAL       /* The total type */
} srv_email_om_notify_obj_type_enum;


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_email_om_notify_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function of the object notification.
 * PARAMETERS
 *  data            : [IN]      The notify data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_email_om_notify_funcptr_type)(const srv_email_om_notify_struct *data);


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_set_notify
 * DESCRIPTION
 *  This function is used to set the object related notification callback function.
 * PARAMETERS
 *  type            : [IN]      The notify type
 *  callback        : [IN]      The callback function
 *  notify_id       : [OUT]     Return the notify id
 * RETURNS
 *  The result code.
 ****************************************************************************/
extern srv_email_result_enum srv_email_om_set_notify(
                                srv_email_om_notify_obj_type_enum type,
                                srv_email_om_notify_funcptr_type callback,
                                S32 *notify_id);


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_unset_notify
 * DESCRIPTION
 *  This function is used to clear the object notification callback function.
 * PARAMETERS
 *  type            : [IN]      The notify type
 *  notify_id       : [IN]      The notify id
 * RETURNS
 *  void
 ****************************************************************************/
extern void srv_email_om_unset_notify(
                srv_email_om_notify_obj_type_enum type,
                S32 notify_id);


#endif /* EMAILSRVGPORT_H */

