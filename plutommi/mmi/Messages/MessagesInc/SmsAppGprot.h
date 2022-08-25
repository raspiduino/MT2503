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
 *  SmsAppGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application Global prototype declaration
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
#ifndef __SMS_APP_GPROT_H__
#define __SMS_APP_GPROT_H__
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "UmSrvDefs.h"

#include "UMGProt.h"
#include "MsgViewerCuiGProt.h"
#include "wgui_categories_uce.h"

#if (defined( __MMI_FTE_SUPPORT__) && defined(__MMI_UNIFIED_COMPOSER__))
#include "UCAppGprot.h"
#endif /* defined( __MMI_FTE_SUPPORT__) && defined(__MMI_UNIFIED_COMPOSER__) */

typedef enum
{
    MMI_SMS_ENTRY_WRITE_PORT = 0x0001,
    MMI_SMS_ENTRY_WRITE_CLASS = 0x0002,
    MMI_SMS_ENTRY_WRITE_REPLY = 0x0004,
#if defined ( __MMI_DUAL_SIM_MASTER__) && defined (__MMI_UNIFIED_COMPOSER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined ( __MMI_DUAL_SIM_MASTER__) && defined (__MMI_UNIFIED_COMPOSER__) */
    MMI_SMS_ENTRY_WRITE_END
} mmi_sms_write_msg_enum;

typedef struct
{
    U16 srcport;
    U16 desport;

    U16 stringlength;
    U8 dcs; //srv_sms_dcs_enum
    U8 dcs_class; //srv_sms_class_enum

    S8 *string;
    S8 *filename;
    U8 *ascii_addr; /* max number of digit is (MAX_DIGITS_SMS - 1). Must contain NULL terminator. */

    mmi_sms_write_msg_enum flag;
} mmi_sms_write_msg_para_struct;

typedef struct
{
    U16 result;             /* srv_sms_cause_enum */
    U16 request_type;       /* mmi_sms_request_type_enum */
    U8 number[21 + 1];          /* Optional. Destination phone number. Needed in send case. Must contain NULL terminator */
    MMI_BOOL display_popup;     /* TRUE to display popup. Please set TRUE in general cases */
    MMI_BOOL delete_sms_screen; /* TRUE to delete SMS framework screens in history.  Please set TRUE in general cases */
    /* Note: if is_display_pupup is FALSE, then current screen would not be deleted even if it belongs to SMS framwork screens because it is not in history.  */
} mmi_sms_api_result_handler_struct;

typedef enum
{
    MMI_SMS_REQ_SEND,
    MMI_SMS_REQ_SAVE,
    MMI_SMS_REQ_TOTAL
} mmi_sms_request_type_enum;

/* SMS Application SIM Card ID Enum */
typedef enum
{
    /* SIM Card 1 */
    SMS_SIM_1 = 0,
    /* SIM Card 2 */
    SMS_SIM_2,
    /* SIM Card 2 */
    SMS_SIM_3,
    /* SIM Card 2 */
    SMS_SIM_4,
    /* Total SIM Card Number */
    SMS_SIM_TOTAL,
    /* Unspecific SIM Card */
    SMS_SIM_UNSPECIFIC
}mmi_sms_sim_enum;



#ifdef __MMI_MESSAGES_TEMPLATE__

/* Return value of function mmi_sms_get_sms_template */
typedef enum
{
    SMS_GET_TEMPLATE_NULL = 0, /* template empty, sms will not call callback function */
    SMS_GET_TEMPLATE_SUCCESS   /* templte not empty, sms will call callback function */
} mmi_sms_tmpl_get_template_return_value_enum;

/* Parameter of mmi_sms_get_template_hdlr_func_t to indicate user action */
typedef enum
{
    SMS_GET_TEMPLATE_RESULT_BACK = 0, /* user select RSK back, the will return NULL in call back function */
    SMS_GET_TEMPLATE_RESULT_SELECT,   /* user select LSK*/
    SMS_GET_TEMPLATE_RESULT_DELETE_BY_OTHER,   /* the screen deleted by other app*/
    SMS_GET_TEMPLATE_RESULT_OTHER     /* other error*/
} mmi_sms_tmpl_get_template_result_enum;

/* Parameter for function mmi_sms_get_sms_template to indicate sms template type that want to list */
typedef enum
{
    MMI_SMS_LIST_TEMPLATE_USER_DEFINED, /* if suppport user defined template, only list user defined template, if not support, return SMS_GET_TEMPLATE_NULL */
    MMI_SMS_LIST_TEMPLATE_DEFAULT,      /* if suppport predefined template, only list predefined template, if not support, return SMS_GET_TEMPLATE_NULL */
    MMI_SMS_LIST_TEMPLATE_ALL           /* list all the template supported*/
} mmi_sms_tmpl_list_template_type_enum;

/*****************************************************************************
 * <GROUP  CallBackFunctions>		
 *
 * FUNCTION
 *  mmi_sms_get_template_hdlr_func_t
 * DESCRIPTION
 *  call back function for mmi_sms_get_sms_template to indicate user selection
 * PARAMETERS
 *  template :  [IN] the user selected template if result is SMS_GET_TEMPLATE_RESULT_SELECT
 *  result   :  [IN] User action of select sms template.
 * RETURNS
 *  void
*****************************************************************************/
typedef void (*mmi_sms_get_template_hdlr_func_t)(const void *content, mmi_sms_tmpl_get_template_result_enum result);

#endif

#ifdef __MMI_BT_MAP_CLIENT__
extern MMI_ID mmi_sms_group_entry(mmi_id parent_gid);
extern void mmi_sms_box_list_opt_pre_view(void);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_write_text_msg
 * DESCRIPTION
 *  Entry SMS Editor to write a Text message.
 * PARAMETERS
 *  ucs2_addr_list  :   [IN]    Address List (UCS2 Format)
 *  addr_count      :   [IN]    The input address total number
 *  ucs2_content    :   [IN]    The default UCS2 content will be input to the Editor 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_entry_write_text_msg(
                S8 **ucs2_addr_list,
                U16 addr_count,
                S8 *ucs2_content);


#ifdef __MMI_DUAL_SIM_MASTER__
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
#else

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_text_msg
 * DESCRIPTION
 *  Send Text Message in the foreground;
 *  In this API, it will do error handling, and popup corresponding notification screen.
 * PARAMETERS
 *  ucs2_addr_list  :   [IN]    Address List, UCS2 Format
 *  addr_count      :   [IN]    The input address total number
 *  ucs2_content    :   [IN]    The default UCS2 content will be input to the Editor 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_send_text_msg(
                S8 **ucs2_addr_list,
                U16 addr_count,
                S8 *ucs2_content);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_data_msg
 * DESCRIPTION
 *  Send Data SMS in the foreground;
 *  In this API, it will do error handling, and popup corresponding notification screen.
 * PARAMETERS
 *  src_port        :   [IN]    Source port number
 *  dest_port       :   [IN]    Destination port number
 *  ucs2_addr_list  :   [IN]    Address List, UCS2 Format
 *  addr_count      :   [IN]    The input address total number
 *  file_path       :   [IN]    File path of the content, UC2 Format 
 *  content_buff    :   [IN]    The buffer of content, 8-Bit Format
 *  buff_size       :   [IN]    The buffer size of content_buff
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_send_data_msg(
                U16 src_port,
                U16 dest_port,
                S8 **ucs2_addr_list,
                U16 addr_count,
                S8 *file_path,
                S8 *content_buff,
                U32 buff_size);


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_write_msg_from_phb
 * DESCRIPTION
 *  Entry SMS Editor to write a Text message, only for Phonebook application.
 * PARAMETERS
 *  count               :   [IN]    Phone number count
 *  get_phb_num_func    :   [IN]    Get Phonebook number function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_entry_write_msg_from_phb(
                U16 count,
                void *get_phb_num_func);


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_max_recipient_num
 * DESCRIPTION
 *  Get SMS application maximum recipient number.
 * PARAMETERS
 *  void
 * RETURNS
 *  Maximum recipient number
 *****************************************************************************/
extern U16 mmi_sms_get_max_recipient_num(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_sms_ready
 * DESCRIPTION
 *  Check whether SMS is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  Result of Whether SMS is ready or not
 * RETURN VALUES
 *  MMI_TRUE    :   SMS is ready
 *  MMI_FALSE   :   SMS is not ready
 *****************************************************************************/
extern MMI_BOOL mmi_sms_is_sms_ready(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_hide_send_sms_menu
 * DESCRIPTION
 *  Check whether need to hide the send SMS menu item;
 *  If it can't send SMS, it should hide the Send SMS menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  Result of Whether need to hide Send SMS menu item
 * RETURN VALUES
 *  MMI_TRUE    :   Need to hide Send SMS menu item
 *  MMI_FALSE   :   Needn't hide Send SMS menu item
 *****************************************************************************/
extern MMI_BOOL mmi_sms_hide_send_sms_menu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_allow_send_sms
 * DESCRIPTION
 *  Check whether allow to send SMS;
 *  The below cases is not allow to SMS:
 *  1> SIM Card is invalid;
 *  2> SMS is not ready;
 *  3> It is existed scenario related to sending SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  Result of Whether allow to send SMS
 * RETURN VALUES
 *  MMI_TRUE    :   Allow to send SMS
 *  MMI_FALSE   :   Don't allow to send SMS
 *****************************************************************************/
extern MMI_BOOL mmi_sms_is_allow_send_sms(void);


#if defined(__MMI_MESSAGES_TEMPLATE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_deInit_templates
 * DESCRIPTION
 *  This function deinit sms template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_deInit_templates(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_entry_template
 * DESCRIPTION
 *  This function is entry function for sms template used by um.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_entry_template(void);
#endif

#if defined(__MMI_MESSAGES_TEMPLATE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_sms_template
 * DESCRIPTION
 *  This function used to call sms to show tempalte list and get the user select one
 * PARAMETERS
 *	left_softkey      : [IN] LSK string value
 *	left_softkey_icon : [IN] LSK icon
 *	template_type     : [IN] value in mmi_sms_tmpl_list_template_type_enum, indicate which type of template caller want to list.
 *	callback          : [IN] call back function of caller
 * RETURNS
 *  Value in mmi_sms_tmpl_get_template_return_value_enum
 *****************************************************************************/
extern U8 mmi_sms_get_sms_template(U16 left_softkey, U16 left_softkey_icon, U8 template_type, mmi_sms_get_template_hdlr_func_t callback);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_abort_get_sms_template
 * DESCRIPTION
 *  This function is for call sms to delete template list screen and free resources related
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_abort_get_sms_template(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_init_templates
 * DESCRIPTION
 *  This function is for init sms template.
 * PARAMETERS
 *  void
 * RETURNS
 *  The result of init sms template.
 *****************************************************************************/
extern U8 mmi_sms_init_templates(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_template_list
 * DESCRIPTION
 *  This function is for entry template list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_entry_template_list(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_curr_template
 * DESCRIPTION
 *  Get Current Highlight Template String 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern CHAR* mmi_sms_get_curr_template(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_reenter_message
 * DESCRIPTION
 *  When send sms, before enter editor screen, check if SMS application is reentered
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: MSG application is reentered,will show popup;FALSE: MSG application is not reentered
 *****************************************************************************/
extern MMI_BOOL mmi_sms_is_reenter_message(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_write_msg_lanch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern void mmi_sms_write_msg_lanch(mmi_id parent_gid, mmi_sms_write_msg_para_struct *para);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_api_send_result_handler
 * DESCRIPTION
 *  Handler for applications to process post SMS request actions, such as
 *  display result popup, delete SMS framework screens, and enable SPOF
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_api_send_result_handler(mmi_sms_api_result_handler_struct *result);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_re_entry_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_is_re_entry_send(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_write_new_msg
 * DESCRIPTION
 *  pre-entry write new sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_msg_pre_entry_write_new_msg(void);
#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_reply
 * DESCRIPTION
 *  For um toolbar to launch the reply icon functon. 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_activate_reply(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id);
#endif
#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_reply
 * DESCRIPTION
 *  For um toolbar to check whether reply icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_um_check_reply(srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_forward
 * DESCRIPTION
 *  For um toolbar to check whether forward icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_um_check_forward(srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_send
 * DESCRIPTION
 *  For um toolbar to check whether send icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_um_check_send(srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_edit
 * DESCRIPTION
 *  For um toolbar to check whether edit icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_um_check_edit(srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_resend
 * DESCRIPTION
 *  For um toolbar to check whether resend icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_um_check_resend(srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_copy
 * DESCRIPTION
 *  For um toolbar to check whether copy icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_um_check_copy(srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_move
 * DESCRIPTION
 *  For um toolbar to check whether move icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_um_check_move(srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_delete
 * DESCRIPTION
 *  For um toolbar to check whether delete icon dim or not 
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_sms_um_check_delete(srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_forward
 * DESCRIPTION
 *  For um toolbar to launch the forward icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_activate_forward(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_send
 * DESCRIPTION
 *  For um toolbar to launch the send icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_activate_send(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_edit
 * DESCRIPTION
 *  For um toolbar to launch the edit icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_activate_edit(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_resend
 * DESCRIPTION
 *  For um toolbar to launch the resend icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_activate_resend(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id);

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_check_copy
 * DESCRIPTION
 *  For um toolbar to launch the copy icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_activate_copy(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_move
 * DESCRIPTION
 *  For um toolbar to launch the move icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_activate_move(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_activate_delete
 * DESCRIPTION
 *  For um toolbar to launch the delete icon functon.  
 * PARAMETERS
 *  msg_type : [IN] Hilight msg's message type
 *  msg_id   : [IN] Hilight msg's message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_um_activate_delete(MMI_ID parent_grp_id, srv_um_msg_enum msg_type, U32 msg_id);
#endif /* __MMI_ICON_BAR_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_is_display_cphs_menu_items
 * DESCRIPTION
 *  This function is check whether need to hide cphs sms menu itmes for UM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_msg_is_display_cphs_menu_items(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_template_list_entry
 * DESCRIPTION
 *  Entry template list.
 *  This API is for SMS internal template Common UI entry, other AP can't use.
 * PARAMETERS
 *  vod
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_template_list_entry(void);

/*FM_ITER*/
#ifdef __MMI_UM_ITERATOR_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_query_indexing_callback
 * DESCRIPTION
 *  If um return fail when sms query indexing, this is the callback
 * PARAMETERS
 *  user_data     [IN]:   sms user data
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_iter_viewer_query_indexing_callback(void *user_data);

#endif /* __MMI_UM_ITERATOR_VIEWER__ */

#ifdef __MMI_MESSAGES_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_templates_launch
 * DESCRIPTION
 *  Launch SMS templates
 * PARAMETERS
 *  parent_grp_id      :    [IN]       preant group id
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sms_templates_launch(MMI_ID parent_grp_id);
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_sms_setting_launch
 * DESCRIPTION
 *  Launch SMS setting
 * PARAMETERS
 *  parent_grp_id   :   [IN]        parent group id             
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sms_setting_launch(MMI_ID parent_grp_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_write_launch
 * DESCRIPTION
 *  Launch write new SMS, entry SMS editor 
 * PARAMETERS
 *  parent_grp_id   :   [IN]        parent group id
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sms_write_launch(mmi_id parent_grp_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_list_opt_menu_id
 * DESCRIPTION
 *  Get message list option MENU ID
 * PARAMETERS
 *  msg_id      :       [IN]            message ID
 * RETURNS
 *  MMI_MENU_ID
 *****************************************************************************/
extern MMI_MENU_ID mmi_sms_get_list_opt_menu_id(U32 msg_id);

#ifdef __UM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_list_opt_cb_hdlr
 * DESCRIPTION
 *  Response to UM list options menu cui event
 * PARAMETERS
 *  evt       :     [IN]        mmi_evt_struct
 *  msg_id    :     [IN]        message ID
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret mmi_sms_um_list_opt_cb_hdlr(mmi_event_struct *evt, mmi_um_opt_para_struct *para);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_query_um_msg_box
 * DESCRIPTION
 *  query UM box type according msg id
 * PARAMETERS
 *  msg_id    :     [IN]        message ID
 * RETURNS
 *  srv_um_msg_box_enum
 *****************************************************************************/
extern srv_um_msg_box_enum mmi_sms_query_um_msg_box(U32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_entry_msg
 * DESCRIPTION
 *  entry sms msg
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_ID mmi_sms_um_entry_msg(mmi_um_entry_msg_struct *entry_msg_param);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_launch_viewer
 * DESCRIPTION
 *  Launch SMS viewer screen
 * PARAMETERS
 *  parent_grp_id   :       [IN]   other application will give the parent grp id
 *  msg_id          :       [IN]   the msg id which will be displayed
 *  user_data       :       [IN]   UM's user data
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_launch_viewer(mmi_id parent_grp_id, U32 msg_id, void *user_data, cui_msg_viewer_type_enum type);
#endif

extern MMI_BOOL mmi_sms_is_allow_reentry(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_need_delivery_report_ind
 * DESCRIPTION
 *  Check Whether need to show Delivery Report Indication in Idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
extern U8 mmi_sms_need_delivery_report_ind(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_delivery_report_ind
 * DESCRIPTION
 *  Entry Delivery Report Indication Screen in Idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_entry_delivery_report_ind(void);


#ifdef  __GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_tts_play_msg_by_id
 * DESCRIPTION
 *  Play the content of one SMS
 * PARAMETERS
 *  msg_id   :       [IN]   SMS message id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_tts_play_msg_by_id(U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_tts_stop_play
 * DESCRIPTION
 *  Stop play SMS content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_tts_stop_play(void);

#endif /* __GENERAL_TTS__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_validate_number
 * DESCRIPTION
 *  Remove chars('-','(',')') from the highlight phone number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_validate_number(S8* srcNumber, S8* desNumber, S32 len);

#ifdef __MMI_SMS_SLIM__
extern void mmi_sms_set_hilite_msg_addr(CHAR *address);
extern void mmi_sms_get_hilite_msg_addr(CHAR *address);
#endif

#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
#define MMI_SMS_UM_CONTENT_CACHE_CHARACTOR_NUMBER 300
void mmi_sms_update_content_according_to_message_id(U16 msg_id, CHAR *content_buffer);
#endif


#ifndef __UM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_main_message_menu
 * DESCRIPTION
 *  Entry function for the SMS main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_entry_main_message_menu(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_enter_write_msg
 * DESCRIPTION
 *  Entry function for the write message option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sms_enter_write_msg(void);


#endif

#ifdef __ULC_SLIM_EMS__
extern U32 mmi_sms_editor_get_message_size_callback(wgui_uce_text_info_struct *current_text_info, wgui_uce_msg_type_enum uce_msg_type);
extern wgui_uce_text_change_result_enum mmi_sms_editor_text_change_callback(wgui_uce_text_info_struct *new_text_info);
extern wgui_uce_display_enum mmi_sms_editor_display_type_callback(void);
extern U32 mmi_sms_editor_remaining_char_count(wgui_uce_text_info_struct *current_text_info);
extern U32 mmi_sms_editor_segment_count(wgui_uce_text_info_struct *current_text_info);
extern void mmi_sms_update_editor_info(CHAR* text_buff);
#endif /* __ULC_SLIM_EMS__ */

#endif /* __SMS_APP_GPROT_H__ */ 

