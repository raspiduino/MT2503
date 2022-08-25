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
 * EmailGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines global enum, constant and prototypes for Email application
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_EMAILGPROT_H
#define _MMI_EMAILGPROT_H

#include "MMI_features.h"

#ifdef __MMI_EMAIL__
/*---------------------------------------------------------------------------*/
/* Header files */
/*---------------------------------------------------------------------------*/
#include "customer_ps_inc.h"  /*for MMI_EMAIL_MAX_LEN_ADDR_LIST*/
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"  /* for Homescreen 3.x */
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#include "emailsrvgprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"


#if (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__))
#ifndef __MMI_EMAIL_EMN__
#define __MMI_EMAIL_EMN__
#endif /* __MMI_EMAIL_EMN__ */
#endif /* (defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)) */

/*---------------------------------------------------------------------------*/
/* Definition */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Enum */
/*---------------------------------------------------------------------------*/

/* Email MMI start/stop procedure status enum */
typedef enum
{
    EMAIL_STOP_NONE = 0,            /* Email MMI stop status */
    EMAIL_STOP_REQ,                 /* Email MMI requiring stop status */
    EMAIL_STOP_BACK_HIST,           /* Email MMI back from main list to stop status */
    EMAIL_STOP_GOTO_IDLE,           /* Email MMI go to IDLE to stop status */
    EMAIL_STOP_BACK_FROM_OTHER,     /* Email MMI stop after APP send status */
    EMAIL_STOP_EMN_INBOX,           /* Email MMI exit EMN list Inbox status */
    EMAIL_STOP_HS_INBOX,            /* Email MMI exit HS Inbox and activate the original account */
    EMAIL_START_REQ,                /* Email MMI requiring start status */
    EMAIL_MODULE_ACTIVE_NOW         /* Email MMI start status */
} email_stop_cause_enum;

/*---------------------------------------------------------------------------*/
/* Struct */
/*---------------------------------------------------------------------------*/

/* structure to support email send interface for other applications */
typedef enum
{
    EMAIL_NONE_FILL_FLAG = 0x00,        /* None value for initialize */
    EMAIL_TO_FILL_FLAG = 0x01,          /* Send address to To field */
    EMAIL_CC_FILL_FLAG = 0x02,          /* Send address to Cc field */
#ifdef __MMI_EMAIL_BCC__
    EMAIL_BCC_FILL_FLAG = 0x04,         /* Send address to Bcc field */
#endif /*__MMI_EMAIL_BCC__*/
    EMAIL_SUBJ_FILL_FLAG = 0x08,        /* Send data to subject field */
    EMAIL_ATTCH_FILL_FLAG = 0x10,       /* Send file to attachment field */
    EMAIL_PRIOR_FILL_FLAG = 0x20,       /* Send Email using APP defined priority */
    EMAIL_CONT_FILL_FLAG = 0x40,        /* Send data to content field */
    EMAIL_NEW_FILL_FLAG = 0x80          /* Enter new Email screen from APP */
} email_app_send_param_fill_enum;

/* structure of send address to recipients field */
typedef struct
{
    CHAR *addr_mail;          /* Email address field(UCS2) */
    CHAR *addr_name;          /* Email display field(UCS2) */
} mmi_email_app_send_addr_struct;

/* structure of APP send data by Email */
typedef struct
{
    mmi_email_app_send_addr_struct addr[MMI_EMAIL_MAX_ADDR_NUM];                /* To information array */
    EMAIL_ACCT_ID acct_id;                                                      /* the account ID used to send the mail */
    mmi_id parent_id;                                                           /* the parent screen group ID */
    U32 to_num;                                                                 /* To address number */
    U32 cc_num;                                                                 /* Cc address number */
    U32 bcc_num;                                                                /* Bcc address number */
    CHAR *subj;                                                                   /* subject string pointer(UCS2) */
    CHAR *attch_file_path;                                                        /* attachment file path string pointer(UCS2) */
    U8 priority;                                                                /* APP defined priority */
    CHAR *cont;                                                                   /* content data pointer(UCS2) */
    MMI_BOOL is_save_to_draft;                                                  /* save the Email directly to Drafts without screens */
    MMI_BOOL is_to_addr;                                                        /* send file as attachment by Email and edit one address to send */
} mmi_email_app_send_param_struct;

/* Email priority type enum */
typedef enum
{
    MMI_EMAIL_PRIOR_NORMAL = 0,             /* normal priority */
    MMI_EMAIL_PRIOR_LOW = 1,                /* low priority */
    MMI_EMAIL_PRIOR_HIGH = 2                /* high priority */
} mmi_email_app_prior_enum;


typedef enum
{
    MMI_EMAIL_APP_MRE_ERROR_CODE_SUCCESS,
    MMI_EMAIL_APP_MRE_ERROR_CODE_WOULDBLOCK,
    MMI_EMAIL_APP_MRE_ERROR_CODE_INVLAID_PARAM,     /* Invalid parameter, such as NO receptions */
    MMI_EMAIL_APP_MRE_ERROR_CODE_NO_RECIPIENT,      /* No recipient provided */
    MMI_EMAIL_APP_MRE_ERROR_CODE_NO_EMAIL_ACCOUNT,  /* No email account in system */
    MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_AVAIABLE,/* Email is NOT avaiable currently, such as phone is in FLIGHT mode, USB mode etc. */
    MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY,   /* Email is during in progress of initilization */
    MMI_EMAIL_APP_MRE_ERROR_CODE_EMAIL_BUSY,        /* Email is busy on receiving or sending */
    MMI_EMAIL_APP_MRE_ERROR_CODE_NETWORK_ERROR,     /* Network error happen during sending */
    MMI_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR,  /* Filesystem error happen during sending */

    MMI_EMAIL_APP_MRE_ERROR_CODE_DRM_FORBIDDEN ,    /* DRM forbidden attachment */
    MMI_EMAIL_APP_MRE_ERROR_CODE_ATT_TOO_LARGE,     /* Max size MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE reached */
    MMI_EMAIL_APP_MRE_ERROR_CODE_SAVE_FAIL,         /* Save message into OUTBOX fail */
    MMI_EMAIL_APP_MRE_ERROR_CODE_SEND_FAIL,         /* Save message into OUTBOX fail */
    MMI_EMAIL_APP_MRE_ERROR_CODE_UNKNOWN_ERROR,     /* Other unknown error happen during sending */
}mmi_email_app_mre_send_error_code_enum;

typedef struct
{
    mmi_email_app_send_addr_struct *from;               /* From address, could be NULL */
    U32 to_num;                                         /* To address number */
    mmi_email_app_send_addr_struct *to;                 /* To address list */
    U32 cc_num;                                         /* Cc address number */
    mmi_email_app_send_addr_struct *cc;                 /* Cc address list */
    U32 bcc_num;                                        /* Bcc address number */
    mmi_email_app_send_addr_struct *bcc;                /* Bcc address list */
    WCHAR *subject;                                     /* Subject string pointer(UCS2) */
    WCHAR *content;                                     /* Content data pointer(UCS2) */
    S32 attach_file_num;                                /* Attachment file number */
    WCHAR **attch_file_list;                            /* Attachment file path string pointer(UCS2) list */
    mmi_email_app_prior_enum priority;                  /* APP defined priority */
    MMI_BOOL is_save_to_sent;                           /* Save the Email to SENT box after sent successfully */
} mmi_email_app_mre_send_param_struct;

/* Callback function define 
 *   mmi_email_app_mre_send_error_code_enum errcode. See mmi_email_app_mre_send_error_code_enum
 */
typedef void (*mmi_email_app_mre_send_result_callback)(mmi_email_app_mre_send_error_code_enum errcode, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mre_send
 * DESCRIPTION
 *  Send one EMAIL message directly without UI. Current default EMAIL account in system will be used.
 * PARAMETERS
 *  mmi_email_app_mre_send_param_struct *para [IN] See mmi_email_app_mre_send_param_struct
 *  mmi_email_app_mre_send_result_callback* cb [IN] To receive the result notify if return WOULDBLOCK. 
 *    See mmi_email_app_mre_send_result_callback
 *  S32* req_id [OUT] Request ID assigned by EMAIL for this action which can be used to abort this SEND progress.
 * RETURNS
 *  mmi_email_app_mre_send_error_code_enum
 *    MMI_EMAIL_APP_MRE_ERROR_CODE_WOULDBLOCK : 
 *         action taken, result will be notified by mmi_email_app_mre_send_result_callback.
 *****************************************************************************/
extern 
mmi_email_app_mre_send_error_code_enum 
mmi_email_app_mre_send(
    mmi_email_app_mre_send_param_struct *para, 
    mmi_email_app_mre_send_result_callback cb, 
    void* user_data,
    S32* req_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_mre_send_abort
 * DESCRIPTION
 *  Abort current sending progress by request ID.
 * PARAMETERS
 *  S32 req_id [IN] Request ID assigned by mmi_email_app_mre_send
 * RETURNS
 *  MMI_BOOL
 *   MMI_TRUE : Abort successfully
 *   MMI_FALSE: Abort failed, wrong request ID provided or the SEND action has finished.
 *****************************************************************************/
extern MMI_BOOL mmi_email_app_mre_send_abort(S32 req_id);


/*---------------------------------------------------------------------------*/
/* Variables */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Prototypes */
/*---------------------------------------------------------------------------*/

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_init_usb
 * DESCRIPTION
 *  This function is used to initialize the Email application for the USB mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_init_usb(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_init
 * DESCRIPTION
 *  This function is used to initialize the Email application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_init(void);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_enter_usb_ms_callback
 * DESCRIPTION
 *  This function is used to deinitialize the Email application for the USB mode.
 * PARAMETERS
 *  event       : [IN]  The event structure of this indication.
 * RETURNS
 *  MMI_RET_OK.
 *****************************************************************************/
extern mmi_ret mmi_email_enter_usb_ms_callback(mmi_event_struct *event);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_exit_usb_ms_callback
 * DESCRIPTION
 *  This function is used to initialize the Email application for the USB mode.
 * PARAMETERS
 *  event       : [IN]  The event structure of this indication.
 * RETURNS
 *  MMI_RET_OK.
 *****************************************************************************/
extern mmi_ret mmi_email_exit_usb_ms_callback(mmi_event_struct *event);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_entry_inbox
 * DESCRIPTION
 *  This function is used to entry Email Inbox directly from other application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_entry_inbox(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_entry_from_shortcut
 * DESCRIPTION
 *  This function is used to entry Email directly from shortcut.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_main_entry_from_shortcut(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_pre_entry_from_menu
 * DESCRIPTION
 *  This function is used to entry Email directly from main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_main_pre_entry_from_menu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_pre_entry_from_message
 * DESCRIPTION
 *  This function is used to entry Email Inbox directly from other application.
 * PARAMETERS
 *  parent_id    : [IN]  The parent group ID of Email application screens.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_main_pre_entry_from_message(mmi_id parent_id);


extern mmi_id mmi_email_entry_main_screen_from_cosmos(void* param, U32 param_size);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_check_show_idle_data
 * DESCRIPTION
 *  This function is used to check if there are any Email data can be shown in idle screen.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE    : The idle data can be shown.
 *  FALSE   : The idle data can not be shown.
 *****************************************************************************/
extern BOOL mmi_email_check_show_idle_data(void);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_show_idle_data
 * DESCRIPTION
 *  This function is used to show the Email data in idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_show_idle_data(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_stop_cause
 * DESCRIPTION
 *  This function is used to get the stop cause of Email.
 * PARAMETERS
 *  void
 * RETURNS
 *  The stop cause (email_stop_cause_enum) of Email.
 *****************************************************************************/
extern U8 mmi_email_util_get_stop_cause(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_is_email_can_forward
 * DESCRIPTION
 *  This function is used to check whether the Email can forward the object or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE    : The Email can forward the object.
 *  FALSE   : The Email can not forward the object.
 *****************************************************************************/
extern BOOL mmi_email_is_email_can_forward(void);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_main_goto_idle
 * DESCRIPTION
 *  This function is used to stop the Email application and go to the idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_main_goto_idle(void);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_highlight_main_menu
 * DESCRIPTION
 *  This function is the highlight handler of the Email main menu in the message center.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_highlight_main_menu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fmgr_send
 * DESCRIPTION
 *  This function is provided to file manager to send a file via Email.
 * PARAMETERS
 *  filePath    : [IN]  The complete file path and name of the selected file.
 *  is_short    : [IN]  Need convert the file name or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_fmgr_send(CHAR *filePath, BOOL is_short);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fmgr_reset_status_icon
 * DESCRIPTION
 *  This function is provided to file manager to reset the Email status icons
 *  when formatting the file system.
 * PARAMETERS
 *  event       : [IN]  The event structure of this indication.
 * RETURNS
 *  should return MMI_RET_OK
 *****************************************************************************/
extern mmi_ret mmi_email_fmgr_reset_status_icon(mmi_event_struct *event);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_init_param_to_null
 * DESCRIPTION
 *  This function is used to initialize the data structure.
 * PARAMETERS
 *  mail_param  : [IN]  Point to the data structure of the mail.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_init_param_to_null(mmi_email_app_send_param_struct *mail_param);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send
 * DESCRIPTION
 *  This function is provided to other application to send the Email.
 * PARAMETERS
 *  mail_param              : [IN]  Point to the data structure of the mail.
 *  mail_param_fill_flag    : [IN]  The fill flag mask of the mail_param
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send(
                mmi_email_app_send_param_struct *mail_param,
                email_app_send_param_fill_enum mail_param_fill_flag);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_entry_comp
 * DESCRIPTION
 *  This function is provided to other application
 *  to enter Email to create a new Email
 * PARAMETERS
 *  acct_id         : [IN]  The account ID to compose the mail.
 *  parent_id       : [IN]  The parent group ID.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_entry_comp(EMAIL_ACCT_ID acct_id, mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_cont
 * DESCRIPTION
 *  This function is provided to other application
 *  to send a UCS2 string as the Email content.
 * PARAMETERS
 *  cont    : [IN]  Point to the UCS2 string content.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_cont(const CHAR *cont);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_to_ext
 * DESCRIPTION
 *  This function is provided to other application
 *  to use a UCS2 string as the Email recipient.
 * PARAMETERS
 *  to_addr : [IN]  Point to the UCS2 string recipient address.
 *  to_name : [IN]  Point to the UCS2 string recipient display name.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_to_ext(const CHAR *to_addr, const CHAR *to_name);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_to
 * DESCRIPTION
 *  This function is provided to other application
 *  to use a UCS2 string as the Email recipient.
 * PARAMETERS
 *  to_addr : [IN]  Point to the UCS2 string recipient address.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_to(const CHAR *to_addr);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_attch
 * DESCRIPTION
 *  This function is provided to other application
 *  to use a UCS2 string as the attachment file path to send an Email.
 * PARAMETERS
 *  file_path   : [IN]  The complete file path and name of the selected file.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_attch(const CHAR *file_path);

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_attch_for_browser
 * DESCRIPTION
 *  This function is provided for Opera
 *  to use a UCS2 string as the attachment file path to send an Email.
 *  Only for COSMOS Email
 * PARAMETERS
 *  file_path   : [IN]  The complete file path and name of the selected file.
 *  del_file    : [IN]  If MMI_TRUE, Email will delete this file after sending
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_attch_for_opera(const CHAR *file_path);

#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_attch
 * DESCRIPTION
 *  This function is provided to other application
 *  to use a UCS2 string as the attachment file path to send an Email.
 *  Only for COSMOS Email
 * PARAMETERS
 *  file_path   : [IN]  The complete file path and name of the selected file.
 *  del_file    : [IN]  If MMI_TRUE, Email will delete this file after sending
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_attch_ext(const CHAR *file_path, MMI_BOOL del_file);
#endif /* __COSMOS_MMI_PACKAGE__ */

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  vobj_email_cb
 * DESCRIPTION
 *  This type is used to define the callback function of sending attach via Email.
 * PARAMETERS
 *  param   : [IN]  The parameter of the callback function.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*vobj_email_cb) (void *param);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_attch_from_vobj
 * DESCRIPTION
 *  This function is provided to other application
 *  to use a UCS2 string as the attachment file path to send an Email.
 *  At the same time, it also provides a callback function to notify the application
 *  after copying the attachment.
 * PARAMETERS
 *  file_path   : [IN]  The complete file path and name of the file.
 *  callback    : [IN]  The callback function used to notify the application.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_attch_from_vobj(const CHAR *file_path, vobj_email_cb callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_attch_to_addr
 * DESCRIPTION
 *  This function is provided to other application
 *  to use a UCS2 string as the attachment file path to send to an address via Email.
 * PARAMETERS
 *  file_path   : [IN]  The complete file path and name of the selected file.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_send_attch_to_addr(const CHAR *file_path);

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_entry_inbox_by_acct
 * DESCRIPTION
 *  This function is used to entry Email Inbox (activate the account)
 *  directly from other application.
 * PARAMETERS
 *  acct_id   : [IN]  Email account ID that need to activate and enter.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_app_entry_inbox_by_acct(EMAIL_ACCT_ID acct_id);


#if (defined(__SYNCML_SUPPORT__) && defined(__MMI_SYNCML_SYNC_EMAIL_SUPPORT__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* ((__SYNCML_SUPPORT__) && (__MMI_SYNCML_SYNC_EMAIL_SUPPORT__)) */


#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_hs_query_email_shct_info
 * DESCRIPTION
 *  This function is the handler of the shortcut query.
 * PARAMETERS
 *  sidebar_id     : [IN]  Side bar ID.
 *  shct_id        : [IN]  Shortcut ID.
 *  shct_data_p    : [IN]  Shortcut data buffer pointer.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_hs_query_email_shct_info(
                S32 sidebar_id,
                S32 shct_id,
                void *shct_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_hs_query_sidebar_info
 * DESCRIPTION
 *  This function is the handler of the side bar query.
 * PARAMETERS
 *  sidebar_id     : [IN]  Side bar ID.
 *  indctr_id      : [IN]  Indicator ID.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_hs_query_sidebar_info(S32 sidebar_id, S32 indctr_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hs_pre_set_shct_acct
 * DESCRIPTION
 *  This function is used to set the favorite account in Home screen
 * PARAMETERS
 *  index     : [IN]  The favorite account index.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_hs_pre_set_shct_acct(U8 index);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hs_remove_shct_acct
 * DESCRIPTION
 *  This function is used to remove the favorite account in Home screen
 * PARAMETERS
 *  index     : [IN]  The favorite account index to be removed.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_hs_remove_shct_acct(U8 index);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_get_account_name_by_id
 * DESCRIPTION
 *  This function is used to get the Email account name using account ID.
 * PARAMETERS
 *  acct_id             : [IN]  Email account ID.
 *  name                : [IN]  Destiny buffer pointer.
 *  buff_len_in_ucs2    : [IN]  The buffer length count in UCS2 character.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_get_account_name_by_id(EMAIL_ACCT_ID acct_id, WCHAR *name, U16 buff_len_in_ucs2);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hs_entry_comp_select
 * DESCRIPTION
 *  This function is used to entry write Email (activate the account)
 *  directly from other application. If there are more than one
 *  shortcut accounts, should show account list to let user to select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_hs_entry_comp_select(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hs_entry_inbox_select
 * DESCRIPTION
 *  This function is used to entry Email Inbox (activate the account)
 *  directly from other application. If there are more than one
 *  shortcut accounts, should show account list to let user to select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_hs_entry_inbox_select(void);
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */


#ifdef __MMI_OP12_TOOLBAR__
/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_tb_evnt_query_email
 * DESCRIPTION
 *  This function is the handler of the toolbar query.
 * PARAMETERS
 *  num     : [IN]  The number of the query.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tb_evnt_query_email(S32 num);
#endif /* __MMI_OP12_TOOLBAR__ */


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_nmgr_query
 * DESCRIPTION
 *  This function is the handler of the notification manager query.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_nmgr_query(void);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_nmgr_cancel
 * DESCRIPTION
 *  This function is the handler of the notification manager cancel.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_nmgr_cancel(void);


#ifdef __MMI_EMAIL_EMN__
/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_emn_set_flightmode
 * DESCRIPTION
 *  Set flight mode flag of the Email notification.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_emn_set_flightmode(void);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_emn_reset_flightmode
 * DESCRIPTION
 *  Reset flight mode flag and start timer for retrieve of the Email notification.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_email_emn_reset_flightmode(void);
#endif /* __MMI_EMAIL_EMN__ */


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_notify_unmount_memory_card_hdlr
 * DESCRIPTION
 *  The handler of memory card pluged out.
 * PARAMETERS
 *  event       : [IN]  The event structure of this indication.
 * RETURNS
 *  should return MMI_RET_OK
 *****************************************************************************/
extern mmi_ret mmi_email_notify_unmount_memory_card_hdlr(mmi_event_struct *event);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_email_notify_mount_memory_card_hdlr
 * DESCRIPTION
 *  The handler of memory card pluged in.
 * PARAMETERS
 *  event       : [IN]  The event structure of this indication.
 * RETURNS
 *  should return MMI_RET_OK
 *****************************************************************************/
extern mmi_ret mmi_email_notify_mount_memory_card_hdlr(mmi_event_struct *event);

extern void mmi_email_cmcc_new_email_hdlr(void);

extern mmi_ret mmi_email_sim_ctrl_sim_ctrl_change_detected_hdlr(mmi_event_struct* para);

#endif /* __MMI_EMAIL__ */
#endif /* _MMI_EMAILGPROT_H */

