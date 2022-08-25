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
 *  SmsAppType.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application Type Declaration 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SMS_APP_TYPE_H__
#define __SMS_APP_TYPE_H__

#include "MMI_features.h"
#include "MMIDataType.h"

#include "SmsCuiGprot.h"
#include "mmi_msg_context.h"
#include "kal_general_types.h"
#include "ems.h"
#include "custom_mmi_default_value.h"
#include "UcSrvGprot.h"

#include "SmsSrvGprot.h"
#ifdef __MMI_UM_ITERATOR_VIEWER__
#include "UMGProt.h"
#endif

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "UcAppGprot.h"
#endif /* #if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */


#define MMI_SMS_MAX_RECIPIENTS_NUM      CUI_SMS_MAX_RECIPIENTS_NUM

#define MMI_SMS_MAX_NUM_LEN             MAX_DIGITS_SMS

#ifdef __MMI_MESSAGES_SMS_EMAIL__
#define MMI_SMS_MAX_EMAIL_ADDR_LEN      60
#define MMI_SMS_MAX_ADDR_LEN            MMI_SMS_MAX_EMAIL_ADDR_LEN
#else /* __MMI_MESSAGES_SMS_EMAIL__ */
#define MMI_SMS_MAX_ADDR_LEN            MMI_SMS_MAX_NUM_LEN
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#define MMI_SMS_MAX_REPORT_NUM          10

#define MMI_SMS_MAX_TIME_SIZE           12
#define MMI_SMS_MAX_DATE_SIZE           12
#define MMI_SMS_MAX_TIMESTAMP_SIZE      12

typedef enum
{
  MMI_SMS_LIST_NONE,
  MMI_SMS_LIST_INBOX,
  MMI_SMS_LIST_OUTBOX,
  MMI_SMS_LIST_DRAFTS,
  MMI_SMS_LIST_UNSENT,
  MMI_SMS_LIST_ARCHIVE,
  MMI_SMS_LIST_SIMBOX,
  MMI_SMS_LIST_REPORT,
  MMI_SMS_LIST_MESSAGING_DATA,
  MMI_SMS_LIST_RECENT_EVENT,
  MMI_SMS_LIST_TOOLBAR,
  MMI_SMS_LIST_TOTAL
}mmi_sms_list_enum;


typedef enum
{
	SMS_SEND_CASE_NONE,
	SMS_SEND_CASE_WRITE_NEW_MSG,
    SMS_SEND_CASE_REPLY,
    SMS_SEND_CASE_ARCHIVE_REPLY,
	SMS_SEND_CASE_EDIT_DRAFT,
	SMS_SEND_CASE_EDIT_UNSENT,
	SMS_SEND_CASE_FORWARD,
	SMS_SEND_CASE_RESEND,
	SMS_SEND_CASE_SEND_DRAFT,

	SMS_SEND_CASE_WRITE_FROM_OTHER_APP,
	SMS_SEND_CASE_SEND_FROM_OTHER_APP,
    SMS_SEND_CASE_SEND_DATA_MSG,

    SMS_SEND_CASE_TOTAL
}mmi_sms_send_case_enum;

typedef enum
{
    SMS_MSG_TYPE_TEXT,
    SMS_MSG_TYPE_EMAIL,
    SMS_MSG_TYPE_UNLIMITED,
    SMS_MSG_TYPE_TOTAL
}mmi_sms_msg_type_enum;


typedef enum
{
    SMS_RESULT_OK,
    SMS_RESULT_ERROR,
    SMS_RESULT_NOT_READY,
    SMS_RESULT_DATA_EXCEED,
    SMS_RESULT_DATA_INVALID,
    SMS_RESULT_MEM_FULL,
    SMS_RESULT_CANCEL,
    SMS_RESULT_SENT_AND_SAVED,
    SMS_RESULT_SENT_BUT_SAVE_FAIL,
    SMS_RESULT_SEND_FAIL_BUT_SAVED,
    SMS_RESULT_SEND_FAIL_AND_SAVE_FAIL,
    SMS_RESULT_TOTAL
}mmi_sms_result_enum;


typedef enum
{
    SMS_ADDR_TYPE_NUMBER,
    SMS_ADDR_TYPE_EMAIL_ADDR,
    SMS_ADDR_TYPE_TOTAL
}mmi_sms_address_type_enum;


typedef enum
{
    SMS_STORAGE_ME = 0,
    SMS_STORAGE_SIM,
    SMS_STORAGE_TOTAL
}mmi_sms_storage_type_enum;


typedef enum
{
    SMS_BOX_TYPE_NOBOX,
    SMS_BOX_TYPE_INBOX,
    SMS_BOX_TYPE_OUTBOX,
    SMS_BOX_TYPE_DRAFTS,
    SMS_BOX_TYPE_UNSENT,
    SMS_BOX_TYPE_ARCHIVE,    
    SMS_BOX_TYPE_TOTAL
}mmi_sms_box_type_enum;


typedef enum
{
    SMS_STATUS_UNREAD,
    SMS_STATUS_INBOX,
    SMS_STATUS_SENT,
    SMS_STATUS_UNSENT,
    SMS_STATUS_DRAFTS,
    SMS_STATUS_DELIVERY_REPORT,
    SMS_STATUS_PENDING_REPORT,
    SMS_STATUS_UNSUPPORT,
    SMS_STATUS_TOTAL
}mmi_sms_msg_status_enum;

typedef void (*FuncPtr) (void);
typedef void (*SmsCBFuncPtr) (mmi_sms_result_enum, void*);
typedef void (*SmsFullEditFuncPtr) (S8*);

typedef struct
{
    S8 *address;
    U16 reply_index;
    MMI_BOOL is_more;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_sms_msg_type_enum msg_type;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    MMI_BOOL is_bg_send;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
}mmi_sms_send_req_struct;


typedef struct
{
    S32 currHiliteIndex;
    U16 curr_msg_index;
    U16 curr_msg_type;

    U16 curr_msg_id;

    U16 ind_msg_index;

    EMSData *edit_ems_data;
    EMSData *view_ems_data;

    void *user_data;

    mmi_sms_list_enum curr_list_type;
    srv_sms_box_enum curr_box_type;
    mmi_sms_msg_status_enum curr_msg_status;

    MMI_BOOL msg_ind_in_idle;

    MMI_BOOL is_from_hs;

    U8 report_count;

#ifdef __MMI_MESSAGES_SMS_EMAIL__
	MMI_BOOL is_sms_email;
	S8 sms_email_addr[(MMI_SMS_MAX_EMAIL_ADDR_LEN + 1) * ENCODING_LENGTH];
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_send_status_enum send_status;
    U16 unsent_box_list_index;
#endif

#ifdef __MMI_UM_ITERATOR_VIEWER__
    mmi_id parent_grp_id;
    MMI_BOOL is_del_msg;
    mmi_um_iter_viewer_result_struct *iter_viewer_result;
#endif /*__MMI_UM_ITERATOR_VIEWER__*/

#ifdef __MMI_UM_REPORT_BOX__
    U16 curr_report_id;
#else /* __MMI_UM_REPORT_BOX__ */
    srv_sms_status_report_struct *report_data[MMI_SMS_MAX_REPORT_NUM];
#endif /* __MMI_UM_REPORT_BOX__ */
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
srv_sms_sim_enum tcard_sim_id;
#endif
} mmi_sms_context_struct;

typedef struct
{
    MYTIME timestamp;
    U8 fo;
    U8 sc_addr[SRV_SMS_MAX_ADDR_LEN + 1];
    U8 number[SRV_SMS_MAX_ADDR_LEN + 1];
} mmi_sms_class0_info_struct;


#if defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)
typedef struct
{
    U16 msg_index;
    U16 text_char_num;
    U8 *text_buff;
    S8 **ucs2_addr_list;
    U8 addr_count;
    mmi_uc_done_type_enum state_type; 
    mmi_uc_msg_type_enum msg_type;
    mmi_uc_info_type_enum info_type;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
}mmi_sms_uc_data_struct;
#endif /* defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__) */



#ifndef __UM_SUPPORT__

#define MMI_SMS_MAX_SUBJECT_LEN  40

typedef struct
{
	srv_sms_box_enum curr_box;
	U16 highlighted_item;
	U16 curr_msg_id;
}mmi_sms_list_data_struct;

typedef struct
{
    kal_uint32 msg_id;                              /* message index */
    kal_uint32 timestamp;                           /* message timestamp array */
    kal_uint8 address_length;                       /* Number of characters in address string */
    kal_uint8 subject_length;                       /* Number of characters in subject string */
    kal_wchar address[SRV_SMS_MAX_ADDR_LEN + 1];     /* sender address for MT msg; receiver address for MO msg */
    kal_wchar subject[MMI_SMS_MAX_SUBJECT_LEN + 1];  /* subject for MMS, WAP Push and E-mai; part of content for SMS */

    kal_uint16 icon_id;
    kal_uint16 csk_icon_id;
    kal_uint32 msg_status;

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif

} mmi_sms_msg_info_struct;


#endif

#endif /* __SMS_APP_TYPE_H__ */

