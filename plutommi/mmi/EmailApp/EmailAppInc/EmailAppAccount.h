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
 *  EmailAppAccount.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email account function.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EMAILACCOUNTLIST_H__
#define __EMAILACCOUNTLIST_H__

#include "MMI_features.h"
#include "Inlinecuigprot.h"
#include "EmailAppCore.h"
#include "DataAccountGprot.h"
#include "CbmSrvGprot.h"
#include "emailsrvgprot.h"
#include "customer_ps_inc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"
#include "DtcntSrvGprot.h"
#include "customer_email_num.h"

#if (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__))
#ifndef __MMI_EMAIL_EMN__
#define __MMI_EMAIL_EMN__
#endif /* __MMI_EMAIL_EMN__ */
#endif /* (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)) */

#define MMI_EMAIL_MAX_PORT_NUMBER                    (5)
//#define MMI_EMAIL_MAX_PORT                           (65535)
//#define MMI_EMAIL_MIN_PORT                           (1)

#define MMI_EMAIL_MAX_DOWNLOAD_SIZE                  (15)
#define MMI_EMAIL_DOWNLOAD_SIZE_ERROR_STRING_LEN     (60)

#define MMI_EMAIL_CHECK_INTERVAL_DAY_BEGIN           (0)
#define MMI_EMAIL_CHECK_INTERVAL_DAY_END             (6)

#define MMI_EMAIL_CHECK_INTERVAL_DAY_START_TIME      (0)
#define MMI_EMAIL_CHECK_INTERVAL_DAY_END_TIME        (24 * 60 *60 - 1)

#define MMI_EMAIL_CHECK_INTERVAL_5_MIN_TIME          (5 * 60)
#define MMI_EMAIL_CHECK_INTERVAL_30_MIN_TIME         (30 * 60)
#define MMI_EMAIL_CHECK_INTERVAL_1_HOUR_TIME         (60 * 60)
#define MMI_EMAIL_CHECK_INTERVAL_2_HOUR_TIME         (2 * 60 * 60)

#define MMI_EMAIL_RETRIVE_AMOUNT_MAX                 SRV_EMAIL_GLOBAL_MAX_MSG_NUM
#define MMI_EMAIL_DOWNLOAD_SIZE_MAX                  (MMI_EMAIL_MAX_MSG_SIZE) // customer_email_nu.h
#define MMI_EMAIL_DOWNLOAD_SIZE_MIN                  (MMI_EMAIL_MIN_MSG_SIZE) // customer_email_nu.h

#define MMI_EMAIL_POP3_PORT_NUMBER                   (110)
#define MMI_EMAIL_POP3_SECURITY_PORT_NUMBER          (995)

#define MMI_EMAIL_IMAP_PORT_NUMBER                   (143)
#define MMI_EMAIL_IMAP_SECURITY_PORT_NUMBER          (993)

#define MMI_EMAIL_SMTP_PORT_NUMBER                   (25)
#define MMI_EMAIL_SMTP_SECURITY_PORT_NUMBER          (465)

#define MMI_EMAIL_IMAP_REMOTE_FOLDER_NUMBER          MMI_EMAIL_MAX_REMOTE_FOLDER_NUM
#define MMI_EMAIL_IMAP_REMOTE_FOLDER_LIST_STRING_NUMBER   (2)
#define MMI_EMAIL_IMAP_REMOTE_FOLDER_LIST_ICON_NUMBER     (1)

typedef enum
{
    MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_OFF,
    MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_5_MIN,
    MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_30_MIN,
    MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_1_HOUR,
    MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_2_HOUR,
    MMI_EMAIL_ACCOUNT_CHECK_INTERVAL_TOTAL
} mmi_email_account_check_interval_enum;

typedef enum
{
    MMI_EMAIL_ACCOUNT_EDIT_EMAIL_ADDRESS_CAPTION_ID = (CUI_INLINE_ITEM_ID_BASE + 0),
    MMI_EMAIL_ACCOUNT_EDIT_EMAIL_ADDRESS_CONTENT_ID,
    
    MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_NAME_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_NAME_CONTENT_ID,
    
    MMI_EMAIL_ACCOUNT_EDIT_USER_NAME_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_EDIT_USER_NAME_CONTENT_ID,
    
    MMI_EMAIL_ACCOUNT_EDIT_PASSWORD_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_EDIT_PASSWORD_CONTENT_ID,
    
    MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_EDIT_OUTGOING_SERVER_CONTENT_ID,
    
    MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_EDIT_INCOMING_SERVER_CONTENT_ID,
    
    MMI_EMAIL_ACCOUNT_EDIT_ADVANCE_SETTINGS_CAPTION_ID,

    MMI_EMAIL_ACCOUNT_EDIT_TOTAL
}mmi_email_account_edit_enum;
#define MMI_EMAIL_ACCOUNT_EDIT_ITEMS_NUMBER                     (MMI_EMAIL_ACCOUNT_EDIT_TOTAL - MMI_EMAIL_ACCOUNT_EDIT_EMAIL_ADDRESS_CAPTION_ID)
#define MMI_EMAIL_ACCOUNT_EDIT_CAPTION_ITEMS_NUMBER             (6)
#define MMI_EMAIL_ACCOUNT_EDIT_FULL_SCREEN_ITEMS_NUMBER         (6)
#define MMI_EMAIL_ACCOUNT_EDIT_DISPLAY_ONLY_ITEMS_NUMBER        (1)

typedef enum
{
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_ACCOUNT_NAME_CAPTION_ID = MMI_EMAIL_ACCOUNT_EDIT_TOTAL,
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_ACCOUNT_NAME_CONTENT_ID,

    MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_DATA_ACCOUNT_CONTENT_ID,

    MMI_EMAIL_ACCOUNT_SETTING_EDIT_PROTOCOL_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_PROTOCOL_CONTENT_ID,
    
#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_CHECK_INTERVAL_CONTENT_ID,
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

#ifdef __MMI_EMAIL_EMN__
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_EMN_CONTENT_ID,
#endif /* __MMI_EMAIL_EMN__ */

    MMI_EMAIL_ACCOUNT_SETTING_EDIT_DOWNLOAD_SIZE_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_DOWNLOAD_SIZE_CONTENT_ID,

    MMI_EMAIL_ACCOUNT_SETTING_EDIT_RETRIVE_AMOUNT_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_RETRIVE_AMOUNT_CONTENT_ID,

    MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CAPTION_ID,
    MMI_EMAIL_ACCOUNT_SETTING_EDIT_REPLY_TO_ADDRESS_CONTENT_ID,

    MMI_EMAIL_ACCOUNT_SETTING_EDIT_TOTAL
}mmi_email_account_setting_edit_enum;
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_ITEMS_NUMBER                (MMI_EMAIL_ACCOUNT_SETTING_EDIT_TOTAL - MMI_EMAIL_ACCOUNT_SETTING_EDIT_ACCOUNT_NAME_CAPTION_ID)
#if (defined(__MMI_EMAIL_EMN__) && !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__))
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_CAPTION_ITEMS_NUMBER        (8)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_FULL_SCREEN_ITEMS_NUMBER    (1)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_SELECT_ITEMS_NUMBER         (3)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_TEXT_ITEMS_NUMBER           (2)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_DISPLAY_ONLY_ITEMS_NUMBER   (2)
#elif (defined(__MMI_EMAIL_EMN__) && defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__))
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_CAPTION_ITEMS_NUMBER        (7)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_FULL_SCREEN_ITEMS_NUMBER    (1)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_SELECT_ITEMS_NUMBER         (2)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_TEXT_ITEMS_NUMBER           (2)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_DISPLAY_ONLY_ITEMS_NUMBER   (2)
#elif (!defined(__MMI_EMAIL_EMN__) && !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__))
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_CAPTION_ITEMS_NUMBER        (7)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_FULL_SCREEN_ITEMS_NUMBER    (1)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_SELECT_ITEMS_NUMBER         (2)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_TEXT_ITEMS_NUMBER           (2)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_DISPLAY_ONLY_ITEMS_NUMBER   (2)
#else
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_CAPTION_ITEMS_NUMBER        (6)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_FULL_SCREEN_ITEMS_NUMBER    (1)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_SELECT_ITEMS_NUMBER         (1)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_TEXT_ITEMS_NUMBER           (2)
#define MMI_EMAIL_ACCOUNT_SETTING_EDIT_DISPLAY_ONLY_ITEMS_NUMBER   (2)
#endif

typedef enum
{
    MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CAPTION_ID = MMI_EMAIL_ACCOUNT_SETTING_EDIT_TOTAL,
    MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CONTENT_ID,

#ifdef __SSL_SUPPORT__
    MMI_EMAIL_OUTGOING_SERVER_EDIT_SECURITY_CAPTION_ID,
    MMI_EMAIL_OUTGOING_SERVER_EDIT_SECURITY_CONTENT_ID,
#endif /* __SSL_SUPPORT__ */

    MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CAPTION_ID,
    MMI_EMAIL_OUTGOING_SERVER_EDIT_AUTHENTICATION_CONTENT_ID,

    MMI_EMAIL_OUTGOING_SERVER_EDIT_SAVE_SENT_MAILS_CAPTION_ID,
    MMI_EMAIL_OUTGOING_SERVER_EDIT_SAVE_SENT_MAILS_CONTENT_ID,
   
    MMI_EMAIL_OUTGOING_SERVER_EDIT_TOTAL
}mmi_email_outgoing_server_edit_enum;
#define MMI_EMAIL_OUTGOING_SERVER_EDIT_ITEMS_NUMBER              (MMI_EMAIL_OUTGOING_SERVER_EDIT_TOTAL - MMI_EMAIL_OUTGOING_SERVER_EDIT_PORT_CAPTION_ID)
#ifdef __SSL_SUPPORT__
#define MMI_EMAIL_OUTGOING_SERVER_EDIT_CAPTION_ITEMS_NUMBER      (4)
#define MMI_EMAIL_OUTGOING_SERVER_EDIT_SELECT_ITEMS_NUMBER       (3)
#else /* __SSL_SUPPORT__ */
#define MMI_EMAIL_OUTGOING_SERVER_EDIT_CAPTION_ITEMS_NUMBER      (3)
#define MMI_EMAIL_OUTGOING_SERVER_EDIT_SELECT_ITEMS_NUMBER       (2)
#endif /* __SSL_SUPPORT__ */
#define MMI_EMAIL_OUTGOING_SERVER_EDIT_TEXT_ITEMS_NUMBER         (1)

typedef enum
{
    MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_USERNAME_CAPTION_ID = MMI_EMAIL_OUTGOING_SERVER_EDIT_TOTAL,
    MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_USERNAME_CONTENT_ID,

    MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_PASSWORD_CAPTION_ID,
    MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_PASSWORD_CONTENT_ID,

    MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_TOTAL
}mmi_email_outgoing_server_auth_edit_enum;
#define MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_ITEMS_NUMBER                  (MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_TOTAL - MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_USERNAME_CAPTION_ID)
#define MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_CAPTION_ITEMS_NUMBER          (2)
#define MMI_EMAIL_OUTGOING_SERVER_AUTH_EDIT_FULL_SCREEN_ITEMS_NUMBER      (2)

typedef enum
{
    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CAPTION_ID = MMI_EMAIL_OUTGOING_SERVER_EDIT_TOTAL,
    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CONTENT_ID,

#ifdef __SSL_SUPPORT__
    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CAPTION_ID,
    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SECURITY_CONTENT_ID,
#endif /* __SSL_SUPPORT__ */

    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_APOP_STATUS_CAPTION_ID,
    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_APOP_STATUS_CONTENT_ID,

    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_DOWNLOAD_CAPTION_ID,
    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_DOWNLOAD_CONTENT_ID,

    MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_TOTAL
}mmi_email_incoming_server_pop3_edit_enum;

#define MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_ITEMS_NUMBER \
            (MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_TOTAL - MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_PORT_CAPTION_ID)

#ifdef __SSL_SUPPORT__
#define MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_CAPTION_ITEMS_NUMBER          (4)
#define MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SELECT_ITEMS_NUMBER           (3)
#else /* __SSL_SUPPORT__ */
#define MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_CAPTION_ITEMS_NUMBER          (3)
#define MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_SELECT_ITEMS_NUMBER           (2)
#endif /* __SSL_SUPPORT__ */

#define MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_TEXT_ITEMS_NUMBER             (1)

typedef enum
{
    MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CAPTION_ID = MMI_EMAIL_INCOMING_SERVER_POP3_EDIT_TOTAL,
    MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CONTENT_ID,

#ifdef __SSL_SUPPORT__
    MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SECURITY_CAPTION_ID,
    MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SECURITY_CONTENT_ID,
#endif /* __SSL_SUPPORT__ */

    MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_DOWNLOAD_CAPTION_ID,
    MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_DOWNLOAD_CONTENT_ID,

#ifdef __MMI_EMAIL_REMOTE_FOLDER__
    MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_FOLDER_SUBSCRIPTION_CAPTION_ID,
#endif /* __MMI_EMAIL_REMOTE_FOLDER__ */

    MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_TOTAL
}mmi_email_incoming_server_imap_edit_enum;
#define MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_ITEMS_NUMBER                  (MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_TOTAL - MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_PORT_CAPTION_ID)
#ifdef __SSL_SUPPORT__
#define MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_CAPTION_ITEMS_NUMBER          (4)
#define MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SELECT_ITEMS_NUMBER           (2)
#else /* __SSL_SUPPORT__ */
#define MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_CAPTION_ITEMS_NUMBER          (3)
#define MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_SELECT_ITEMS_NUMBER           (1)
#endif /* __SSL_SUPPORT__ */
#define MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_TEXT_ITEMS_NUMBER             (1)
#ifdef __MMI_EMAIL_REMOTE_FOLDER__
#define MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_DISPLAY_ONLY_ITEMS_NUMBER     (1)
#endif /* __MMI_EMAIL_REMOTE_FOLDER__ */

typedef enum
{
    MMI_EMAIL_SIGNATURE_EDIT_STATUS_CAPTION_ID = MMI_EMAIL_INCOMING_SERVER_IMAP_EDIT_TOTAL,
    MMI_EMAIL_SIGNATURE_EDIT_STATUS_CONTENT_ID,

    MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CAPTION_ID,
    MMI_EMAIL_SIGNATURE_EDIT_IMAGE_CONTENT_ID,

    MMI_EMAIL_SIGNATURE_EDIT_TEXT_CAPTION_ID,
    MMI_EMAIL_SIGNATURE_EDIT_TEXT_CONTENT_ID,

    MMI_EMAIL_SIGNATURE_EDIT_TOTAL
} mmi_email_signature_edit_enum;

#define MMI_EMAIL_SIGNATURE_EDIT_ITEMS_NUMBER                  (MMI_EMAIL_SIGNATURE_EDIT_TOTAL - MMI_EMAIL_SIGNATURE_EDIT_STATUS_CAPTION_ID)
#define MMI_EMAIL_SIGNATURE_EDIT_CAPTION_ITEMS_NUMBER          (3)
#define MMI_EMAIL_SIGNATURE_EDIT_SELECT_ITEMS_NUMBER           (1)
#define MMI_EMAIL_SIGNATURE_EDIT_FULL_SCREEN_ITEMS_NUMBER      (1)


typedef enum
{
    MMI_EMAIL_TEMPLATE_EDIT_EMAIL_ADDRESS_CAPTION_ID = MMI_EMAIL_SIGNATURE_EDIT_TOTAL,
    MMI_EMAIL_TEMPLATE_EDIT_EMAIL_ADDRESS_CONTENT_ID,

    MMI_EMAIL_TEMPLATE_EDIT_USER_PASSWORD_CAPTION_ID,
    MMI_EMAIL_TEMPLATE_EDIT_USER_PASSWORD_CONTENT_ID,

    MMI_EMAIL_TEMPLATE_EDIT_TOTAL
} mmi_email_template_edit_enum;
#define MMI_EMAIL_TEMPLATE_EDIT_ITEMS_NUMBER                   (MMI_EMAIL_TEMPLATE_EDIT_TOTAL - MMI_EMAIL_TEMPLATE_EDIT_EMAIL_ADDRESS_CAPTION_ID)
#define MMI_EMAIL_TEMPLATE_EDIT_CAPTION_ITEMS_NUMBER           (2)
#define MMI_EMAIL_TEMPLATE_EDIT_TEXT_ITEMS_NUMBER              (2)


typedef enum
{
    MMI_EMAIL_ACCOUNT_LIST_STATE_IDLE,

    MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_MAIN_SCREEN,
    MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_ADVANCE_SCREEN,
    MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_ACCOUNT_SETTING,
    MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_OUTGOING_SERVER,
    MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_INCOMING_SERVER,
    MMI_EMAIL_ACCOUNT_LIST_STATE_EDIT_ACCOUNT_SIGNATURE,
    
    MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_EMAIL_ADDR,
    MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_PROTOCOL,
    MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_DATA_ACCOUNT,
    MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_INCOMING_SERVER,
    MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_OUTGOING_SERVER,
    MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_USER_NAME,
    MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_PASSWORD,
    MMI_EMAIL_ACCOUNT_LIST_STATE_WIZARD_ACCOUNT_NAME,

    MMI_EMAIL_ACCOUNT_LIST_STATE_DELETE_ACCOUNT,

    MMI_EMAIL_ACCOUNT_LIST_STATE_UPDATE_FOLDER_LIST,
    MMI_EMAIL_ACCOUNT_LIST_STATE_SUBSCRIBE_FOLDER,
    
    MMI_EMAIL_ACCOUNT_LIST_STATE_TOTAL
} mmi_email_account_list_state_enum;

typedef enum
{
    MMI_EMAIL_ACCOUNT_ALERT_NEW_ACCOUNT_LAUNCH = 1,/* 0 is for display popup simple */
    MMI_EMAIL_ACCOUNT_ALERT_WIZARD_CANCEL,
    MMI_EMAIL_ACCOUNT_ALERT_SAVE_MAIN_ACCOUNT_SETTING,
    MMI_EMAIL_ACCOUNT_ALERT_SAVE_ACCOUNT_SETTING,
    MMI_EMAIL_ACCOUNT_ALERT_SAVE_OUTGOING_SERVER,
    MMI_EMAIL_ACCOUNT_ALERT_SAVE_INCOMING_SERVER,
    MMI_EMAIL_ACCOUNT_ALERT_SAVE_SIGNATURE,
    MMI_EMAIL_ACCOUNT_ALERT_DELETE_ACCOUNT,
    
    MMI_EMAIL_ACCOUNT_ALERT_TOTAL
} mmi_email_account_alert_enum;

typedef enum
{
    MMI_EMAIL_ASYNC_CREATE_ACCOUNT_TYPE_FROM_WIZRAD = 0,
    MMI_EMAIL_ASYNC_CREATE_ACCOUNT_TYPE_FROM_TEMPLATE,
    MMI_EMAIL_ASYNC_CREATE_ACCOUNT_TYPE_TOTAL
} mmi_email_async_create_account_type_enum;

typedef enum
{
    MMI_EMAIL_OPERATE_RESULT_FAILED = 0,
    MMI_EMAIL_OPERATE_RESULT_SUCCESS,
    MMI_EMAIL_OPERATE_RESULT_WOULD_BLOCK,
    MMI_EMAIL_OPERATE_RESULT_TOTAL
} mmi_email_operate_result_enum;

typedef enum
{
    MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_SERVICE = 0,
    MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_APP_CORE,
    MMI_EMAIL_ACCOUNT_ERROR_CODE_TYPE_MMI
} mmi_email_account_error_code_type_enum;

#define MMI_EMAIL_ACCOUNT_EXTRA_INFO_FILE_CHECK_SUM  (0)
/* structure declaration */
typedef struct
{
    EMAIL_ACCT_ID account_id;
    MMI_BOOL save_sent_emails;
} mmi_email_account_extra_info_struct;

typedef struct
{
    MMI_BOOL is_valid;
    mmi_email_account_extra_info_struct extra_info;
} mmi_email_account_extra_info_file_node_struct;

typedef struct
{
    U32 check_sum;
    mmi_email_account_extra_info_file_node_struct extra_info_array[MMI_EMAIL_MAX_ACCTS];
} mmi_email_account_extra_info_file;

typedef struct
{
    WCHAR acct_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
    srv_email_prot_type_enum protocol;
} mmi_email_account_template_display_struct;

typedef struct
{
    MMI_BOOL select_from_phb; /* identify whether select address from phonebook */
    srv_email_addr_struct email_addr;
} mmi_email_account_select_email_addr_from_phb_struct;

#ifdef __OP12__
typedef struct
{
    WCHAR email_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];
    srv_email_auth_struct in_auth;
} mmi_email_input_template_screen_struct;
#endif /* __OP12__ */

typedef struct
{
    mmi_email_account_list_state_enum state;

    mmi_id group_id; /* the parent group id for loading the edit, new process */ 

    mmi_id new_account_template_group_id;
    mmi_id new_account_group_id;
    mmi_id new_account_protocol_group_id;
    mmi_id new_account_data_account_group_id;
    
    mmi_id edit_account_group_id;
    mmi_id edit_account_main_setting_group_id;
    mmi_id edit_account_setting_group_id;
    mmi_id edit_account_outgoing_server_group_id;
    mmi_id edit_account_incoming_server_group_id;
    mmi_id edit_account_signature_group_id;
    
    mmi_id delete_account_group_id;

    mmi_id select_storage_group_id;
    
    mmi_id current_inline_id;
    mmi_id current_fseditor_id; /* now only use in asynchronous */

    mmi_id account_main_setting_id;
    mmi_id account_setting_id;
    mmi_id account_incoming_server_id;
    mmi_id account_outgoing_server_id;
    mmi_id account_signature_id;
    
    S32 account_num;
    EMAIL_ACCT_ID account_id_array[MMI_EMAIL_MAX_ACCTS];
    WCHAR account_name[MMI_EMAIL_MAX_ACCTS][SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];

    EMAIL_SRV_HANDLE srv_handle;
    EMAIL_REQ_ID current_req_id;
    EMAIL_ACCT_HANDLE current_account_handle;
    EMAIL_ACCT_ID current_account_id;
    EMAIL_ACCT_ID current_edit_account_id; /* current edit account's id */
    MMI_BOOL first_new_account; /* this flag identifies whether to create account in the first time */

    /* account setting related */
    srv_email_acct_info_struct current_account;
    mmi_email_account_extra_info_struct current_account_extra_info;
    WCHAR account_file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_email_account_check_interval_enum check_interval_value;
    WCHAR data_account_name[MAX_DATA_ACCOUNT_NAME_LEN + 1];
    mmi_email_account_select_email_addr_from_phb_struct select_email_addr_from_phb;
    //U32 edit_dataacct_id; /* the account id which is in edit */
    U32 edit_dataacct_id[MMI_SIM_TOTAL];
    MMI_BOOL dtcnt_changed;
    srv_email_addr_struct edit_reply_to_addr; /* the edit reply_to address */
    srv_email_auth_struct *p_outgoing_server_auth; /* the outgoing server auth information */
#ifdef  __OP12__
    mmi_email_input_template_screen_struct input_template;
#endif /* __OP12__ */

    /* template related */
    S32 template_num;
    S32 highlight_template_index;
    mmi_email_account_template_display_struct *p_account_temp_display_info;
    
    /* signature related */
    mmi_email_sig_struct current_account_signature_info;
    MMI_BOOL current_account_signature_status;
    WCHAR sig_text[MMI_EMAIL_SIG_MAX_TEXT_LEN + 1];
    srv_fmgr_fileinfo_struct sig_file_info;
    WCHAR sig_file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    WCHAR *p_image_file_title; /* points to the signature image file title */

    /* remote folder related */
    srv_cbm_bearer_event_type_enum cbm_bearer_query_type;
    U32 remote_folder_num;
    U32 remote_folder_highlight_index;
    EMAIL_FLDR_ID remote_folder_id_array[MMI_EMAIL_IMAP_REMOTE_FOLDER_NUMBER];
} mmi_email_account_list_cntx_struct;

typedef struct
{
    U16 title_string_id;
    U16 title_icon_id;
    S32 menu_item_number;
    mmi_menu_id *menu_id_array;
    U16 *menu_id_string_array;
    U16 *menu_id_image_array;
} mmi_email_menu_screen_struct;

typedef struct
{
    S32 account_num;
    srv_email_acct_info_struct *p_account_info;
} mmi_email_pre_defined_account_struct;

typedef struct
{
    mmi_email_async_create_account_type_enum type;
    EMAIL_ACCT_HANDLE account_handle;
    mmi_email_account_list_cntx_struct *p_account_list_cntx;
} mmi_email_asyc_create_account_struct;

typedef struct
{
    mmi_email_account_error_code_type_enum error_type;
    union 
    {
        srv_email_result_enum srv_error;
        mmi_email_app_core_result_enum app_core_error;
    } error_code;
} mmi_email_account_error_code_struct;

/* function declaration */
extern void mmi_email_account_list_init(void);
extern void mmi_email_account_list_init_wait_app_core_ready(void);
extern void mmi_email_account_list_init_wait_service_ready(void);

extern void mmi_email_entry_account_list_launch(mmi_id parent_id);
extern void mmi_email_wizard_new_account_launch(mmi_id parent_id);
extern void mmi_email_entry_edit_account_launch(mmi_id parent_id, EMAIL_ACCT_ID account_id);
extern MMI_BOOL mmi_email_entry_edit_account_add_account_extra_info(mmi_email_account_extra_info_struct *p_extra_info, S32 *p_fs_error);
extern MMI_BOOL mmi_email_entry_edit_account_delete_account_extra_info(EMAIL_ACCT_ID account_id, S32 *p_fs_error);
extern void mmi_email_account_start_auto_check_service(void);
extern MMI_BOOL mmi_email_account_is_in_edit(EMAIL_ACCT_ID account_id);


extern void mmi_email_entry_edit_account_sim_quit(void);
#endif /* __EMAILACCOUNTLIST_H__ */
