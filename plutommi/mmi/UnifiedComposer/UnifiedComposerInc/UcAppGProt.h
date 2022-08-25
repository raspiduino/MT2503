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
 * UcAppGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines global enum, constant and prototypes for Unified Composer
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMI_UNIFIED_COMPOSER_GPROT_H
#define _MMI_UNIFIED_COMPOSER_GPROT_H

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

#include "gui_config.h" /* For GUI_INPUT_BOX_MAX_LENGTH */

#include "custom_mmi_default_value.h"   /* For MMI_PHB_NAME_LENGTH */
#ifdef __MMI_MMS_2__
#include "custom_wap_config.h"
#include "custom_uc_config.h"   /* For MMI_UC_CUSTOM_MAX_ADDR_LEN */
#endif /* __MMI_MMS_2__ */ 

//#include "customer_ps_inc.h"
//#include "UMGprot.h"
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
#include "smssrvgprot.h"
#endif
#include "UcSrvGprot.h"
#include "UcSrvIprot.h"
//suggested add
    #include "MMI_features.h"
    #include "customer_email_num.h"
    #include "custom_phb_config.h"
    //#include "kal_general_types.h"
    #include "MMIDataType.h"
    #include "stack_ltlcom.h"

/* DOM-NOT_FOR_SDK-BEGIN */
#if defined (__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined (__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
/* UC own wrapper compile option for WAP max size support feature. */
#define __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__
#endif /* defined (__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined (__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__) */ 
/* DOM-NOT_FOR_SDK-END */
/* DOM-NOT_FOR_SDK-BEGIN */
// #define OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
/* DOM-NOT_FOR_SDK-END */

/* Max length of subject UC supports, to compatable with UM subject. */
#define MMI_UC_MAX_SUBJECT_LEN SRV_UC_MAX_SUBJECT_LEN

/* Max Email length UC supports. */
#define MMI_UC_MAX_EMAIL_LEN SRV_UC_MAX_EMAIL_LEN

/* Max Phone number length UC supports. */
#define MMI_UC_MAX_PHONE_NUMBER_LEN SRV_UC_MAX_PHONE_NUMBER_LEN
#if MMI_UC_MAX_EMAIL_LEN < MMI_UC_MAX_PHONE_NUMBER_LEN
#error email len shall not smaller than phone number
#endif 
/* Max UTF8 char/text buffer size UC supports on single slide. */
#define MMI_UC_UTF8_TEXT_BUFFER_SIZE SRV_UC_UTF8_TEXT_BUFFER_SIZE

typedef void (*uc_func_ptr) (void *);
typedef void (*uc_confirm_func_ptr) (void);
typedef kal_int8 *(*uc_func_ptr_general_insert_get_addr_fn) (kal_uint16 index, kal_uint16 *type);

/* This enum is used to define message type modes supported in UC. This is decided before start composer and will inform UC that it can be switchable inside composer operation or its fixed to one type. */
typedef srv_uc_msg_type_enum mmi_uc_msg_type_enum;

#define MMI_UC_MSG_TYPE_DEFAULT SRV_UC_MSG_TYPE_DEFAULT /* Default type. */
#define MMI_UC_MSG_TYPE_SMS_PREFER SRV_UC_MSG_TYPE_SMS_PREFER   /* Default mode SMS. Try to change to SMS if content say can be SMS. */
#define MMI_UC_MSG_TYPE_MMS_PREFER SRV_UC_MSG_TYPE_MMS_PREFER   /* Default mode MMS. */
#define MMI_UC_MSG_TYPE_SMS_ONLY SRV_UC_MSG_TYPE_SMS_ONLY       /* Only SMS mode support. Msg will not change to MMS. */
#define MMI_UC_MSG_TYPE_MMS_ONLY SRV_UC_MSG_TYPE_MMS_ONLY       /* Only MMS mode support. Can not be changed to SMS. */
#define MMI_UC_MSG_TYPE_TOTAL_NUM SRV_UC_MSG_TYPE_TOTAL_NUM     /* Max number of type modes UC supports. */

#if (defined (__MMI_MMS_POSTCARD__)||defined(__MMI_OP02_LEMEI__)) 
/* This enum is used to define MMS edit mode types supported in UC. This is decided when launch editor for edit a MMS/Postcard/lemei. Values currently used to tell composer difference between normal, postcard and lemei MMS. */
typedef srv_uc_MMS_edit_mode_enum mmi_uc_MMS_edit_mode_enum;

#define MMI_UC_MMS_EDIT_MODE_NORMAL_MMS      SRV_UC_MMS_EDIT_MODE_NORMAL_MMS    /* Normal MMS mode. */
#define MMI_UC_MMS_EDIT_MODE_POSTCARD_MMS SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS     /* Postcard MMS mode. */
#define MMI_UC_MMS_EDIT_MODE_LEMEI_MMS SRV_UC_MMS_EDIT_MODE_LEMEI_MMS     /* lemei MMS mode. */
#define MMI_UC_MMS_EDIT_MODE_TOTAL_NUM    SRV_UC_MMS_EDIT_MODE_TOTAL_NUM        /* Max number of MMS modes UC supports. */
#endif /* (defined (__MMI_MMS_POSTCARD__)||defined(__MMI_OP02_LEMEI__) */ 

/* This enum is used to define message info type modes supported in UC. Filled when want to launch UC editor to inform about the requester message application. */
typedef srv_uc_info_type_enum mmi_uc_info_type_enum;

#define MMI_UC_INFO_TYPE_SMS     SRV_UC_INFO_TYPE_SMS   /* Info type SMS. */
#define MMI_UC_INFO_TYPE_MMS     SRV_UC_INFO_TYPE_MMS   /* Info type MMS. */
#define MMI_UC_INFO_TYPE_NORMAL_MMS    SRV_UC_INFO_TYPE_NORMAL_MMS      /* Info type MMS. for backward conpatiblity. */
#define MMI_UC_INFO_TYPE_POSTCARD_MMS     SRV_UC_INFO_TYPE_POSTCARD_MMS /* Info type Postcard. */
#define MMI_UC_INFO_TYPE_LEMEI_MMS     SRV_UC_INFO_TYPE_LEMEI_MMS /* Info type Postcard. */
#define MMI_UC_INFO_TYPE_TOTAL_NUM     SRV_UC_INFO_TYPE_TOTAL_NUM       /* Max number of msg info UC supports. */

/* This enum is used to define UC current state of operation. It will be need to set when launch UC. As each state have different type of flow. */
typedef srv_uc_state_enum mmi_uc_state_enum;

#define MMI_UC_STATE_WRITE_NEW_MSG     SRV_UC_STATE_WRITE_NEW_MSG       /* Writing new msg state. */
#define MMI_UC_STATE_EDIT_EXISTED_MSG     SRV_UC_STATE_EDIT_EXISTED_MSG /* Edit existing msg state. */
#define MMI_UC_STATE_FORWARD           SRV_UC_STATE_FORWARD     /* Forward existing msg state. Only for inbox and sent box msgs. */
#define MMI_UC_STATE_SEND        SRV_UC_STATE_SEND      /* Send existing msg state. Only for outbox and draft box msgs. */
#define MMI_UC_STATE_REPLY       SRV_UC_STATE_REPLY     /* Reply existing msg state. */
#define MMI_UC_STATE_REPLY_ALL      SRV_UC_STATE_REPLY_ALL      /* Reply all existing msg state. */
#define MMI_UC_STATE_TOTAL_NUM      SRV_UC_STATE_TOTAL_NUM      /* Max number of msg states in UC. */

typedef mmi_uc_state_enum mmi_uc_done_type_enum;

/* This enum is used to specify the type of address. Email or number. */
typedef srv_uc_address_type_enum mmi_uc_address_type_enum;

#define MMI_UC_ADDRESS_TYPE_PHONE_NUMBER  SRV_UC_ADDRESS_TYPE_PHONE_NUMBER      /* Phone number. */
#define MMI_UC_ADDRESS_TYPE_EMAIL         SRV_UC_ADDRESS_TYPE_EMAIL     /* Email address. */
#define MMI_UC_ADDRESS_TYPE_IP            SRV_UC_ADDRESS_TYPE_IP        /* IP address. */
#define MMI_UC_ADDRESS_TYPE_TOTAL_NUM     SRV_UC_ADDRESS_TYPE_TOTAL_NUM /* Max number of address type. */

/* This enum is used to specify the group types of addresses. */
typedef srv_uc_address_group_type_enum mmi_uc_address_group_type_enum;

#define MMI_UC_ADDRESS_GROUP_TYPE_TO   SRV_UC_ADDRESS_GROUP_TYPE_TO     /* To group. */
#define MMI_UC_ADDRESS_GROUP_TYPE_CC   SRV_UC_ADDRESS_GROUP_TYPE_CC     /* Cc group. */
#define MMI_UC_ADDRESS_GROUP_TYPE_BCC  SRV_UC_ADDRESS_GROUP_TYPE_BCC    /* Bcc group. */
#define MMI_UC_ADDRESS_GROUP_TYPE_FROM SRV_UC_ADDRESS_GROUP_TYPE_FROM   /* From group. */
#define MMI_UC_ADDRESS_GROUP_TYPE_TOTAL_NUM     SRV_UC_ADDRESS_GROUP_TYPE_TOTAL_NUM     /* Max number of address group. */

/* This enum is used to specify sim in use. Its designed for two sim only. */
typedef srv_uc_sim_id mmi_uc_sim_id;

#define UC_SIM_ID_UNCLASSIFIED   SRV_UC_SIM_ID_UNCLASSIFIED     /* Unclassified message */
#define UC_SIM_ID_GSM_SIM1    SRV_UC_SIM_ID_GSM_SIM1    /* SIM1 card message */
#define UC_SIM_ID_GSM_SIM2    SRV_UC_SIM_ID_GSM_SIM2 
#define UC_SIM_ID_GSM_SIM3   SRV_UC_SIM_ID_GSM_SIM3
#define UC_SIM_ID_GSM_SIM4   SRV_UC_SIM_ID_GSM_SIM4   /* SIM2 card message */

typedef enum
{
/*    MMI_UC_OPERATION_WRITE_NEW_MSG, */        /* Writing new msg operation. */
    MMI_UC_OPERATION_EDIT_EXISTED_MSG,      /* Edit existing msg operation. */        
    MMI_UC_OPERATION_FORWARD,               /* Forward existing msg operation. Only for inbox and sent box msgs currently.*/
    MMI_UC_OPERATION_SEND,                  /* Send existing msg operation. Only for outbox and draft box msgs currently.*/
    MMI_UC_OPERATION_REPLY,                 /* Reply existing msg operation. New msg type controlled by UC */
    MMI_UC_OPERATION_REPLY_BY_SMS,                 /* Reply existing msg operation. New msg type controlled by caller app. */
    MMI_UC_OPERATION_REPLY_BY_MMS,                 /* Reply existing msg operation. New msg type controlled by caller app. */
    MMI_UC_OPERATION_REPLY_ALL,             /* Reply all existing msg operation. */
    MMI_UC_OPERATION_TOTAL_NUM              /* Max number of msg operations in UC. */
} mmi_uc_msg_operation_enum;

/* This structure contains the data to be filled by launching application. This information further use to fill UC internal used variables and states. */

typedef srv_uc_addr_struct mmi_uc_addr_struct;
typedef struct
{
    srv_uc_addr_struct *addr;           /* Addresses linklist */
	kal_uint8 *file_path;               /* File path */
    kal_uint8 *text_buffer;             /* File path */
	kal_uint8 *subject;                 /* File path */
	void *info;                         /* Info. SMS use msg ID/Index to pass */
    uc_func_ptr callback;               /* Callback function specified by caller of object forward, for calling after use of object */
    void *callback_para;                /* Input paramter to callback function above */
	uc_func_ptr_general_insert_get_addr_fn get_address_callback;        /* Callback function specified by caller to call if multiple addresses forwarded */
	kal_uint16 text_num;				/* File path */
	kal_uint8 addr_num;                 /* Max addresses */
	mmi_uc_msg_type_enum msg_type;      /* srv_uc_msg_type_enum */
	mmi_uc_info_type_enum info_type;    /* srv_uc_info_type_enum */
	mmi_uc_sim_id sim_id;               /* srv_uc_sim_id */
    kal_uint8 media_num;
    uc_func_ptr_general_insert_get_img_fn  get_img_callback;        /* Callback function specified by caller to call if multiple addresses forwarded */
} mmi_uc_entry_write_struct;

/* This structure contains the data to be passed to UC when other (MMS) application want to launch the UC composer. */
typedef srv_uc_start_struct mmi_uc_start_struct;

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_init
 * DESCRIPTION
 *  This function initialize Unified Composer application. Its getting call when all MMI app start initialization.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_init(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_pre_entry_write_msg
 * DESCRIPTION
 *  This function is a pre entry function of unified composer. Its for internal use not for external call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_pre_entry_write_msg(void);

/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_address_from_phb_ext
 * DESCRIPTION
 *  This function is to get addresses from phonebook. Callback register to phonebook interface.
 * PARAMETERS
 *  name : [IN]        Name
 *  addr : [IN]        Address email + number
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_get_address_from_phb_ext(S8 *name, S8 *addr);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_write_msg_with_content
 * DESCRIPTION
 *  This function is to enter unified composer with content filled by other applications. UC will launch itself after getting call.
 * PARAMETERS
 *  type : [IN]        mmi_uc_done_type_enum
 *  data : [IN]        mmi_uc_entry_write_struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_entry_write_msg_with_content(mmi_uc_done_type_enum type, mmi_uc_entry_write_struct *data);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_sd_plug_in_hdlr
 * DESCRIPTION
 *  This function is used when memory card is removed. This callback is hooked with card operation handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_sd_plug_in_hdlr(void);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_sd_plug_out_hdlr
 * DESCRIPTION
 *  This function is used when memory card is removed. This callback is hooked with card operation handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_sd_plug_out_hdlr(void);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_sd_plug_in_hdlr
 * DESCRIPTION
 *  This function is used when memory card is inserted. This callback is hooked with card operation handlers.
 * PARAMETERS
 *  param : [IN]        mmi_event_struct
 * RETURNS
 *  mmi event return type
 *****************************************************************************/
extern mmi_ret mmi_uc_sd_card_plug_in_hdlr_cb(mmi_event_struct *param);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_sd_plug_out_hdlr
 * DESCRIPTION
 *  This function is used when memory card is removed. This callback is hooked with card operation handlers.
 * PARAMETERS
 *  param : [IN]        mmi_event_struct
 * RETURNS
 *  mmi event return type
 *****************************************************************************/
extern mmi_ret mmi_uc_sd_card_plug_out_hdlr_cb (mmi_event_struct *param);


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_usb_ms_plug_in_hdlr
 * DESCRIPTION
 *  This function is used when USB is inserted and mass storage is selected
 * PARAMETERS
 *  evt : [IN]        mmi_event_struct
 * RETURNS
 *  mmi event return type
 *****************************************************************************/
extern mmi_ret mmi_uc_usb_ms_plug_in_hdlr(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_max_recipient_count
 * DESCRIPTION
 *  This function is to return the max number of recipient UC will support. It will return the final customized value.
 * PARAMETERS
 *  void
 * RETURNS
 *  Max UC recipient number
 *****************************************************************************/
extern U32 mmi_uc_get_max_recipient_count(void);

#if defined(__MMI_MESSAGES_TEMPLATE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_insert_text_template
 * DESCRIPTION
 *  This function is to insert text template. It will also check for userdefined and default templates.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_insert_text_template(void);
#endif /* defined(__MMI_MESSAGES_TEMPLATE__) */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_uc_screen_in_history
 * DESCRIPTION
 *  This functions return true if unified composer screen is in the history.
 * PARAMETERS
 *  void        
 * RETURNS
 *   KAL_FALSE  : not present.
 *   KAL_TRUE  : present.
 *****************************************************************************/
extern kal_bool mmi_uc_is_uc_screen_in_history(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_pending_action
 * DESCRIPTION
 *  This function returns true if UC have pending action. Used by other application to know UC status.
 * PARAMETERS
 *  void
 * RETURNS
 *   KAL_FALSE  : no pending action.
 *   KAL_TRUE  : pending action.
 *****************************************************************************/
extern kal_bool mmi_uc_is_pending_action(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_delete_all_uc_screens
 * DESCRIPTION
 *  This function delete UC screens if present. It will delete the complete UC screens from history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_delete_all_uc_screens(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_mms_in_use
 * DESCRIPTION
 *  Check if the msg_id is in used (Other application need to check for this before use a msg.
 *  Because same message can not be used by two applications simultaneously)
 *  Current user of this API are BGSR and JSR.
 * PARAMETERS
 *  msg_id : [IN] Msg id.
 * RETURNS
 *   KAL_FALSE  : Not in use.
 *   KAL_TRUE  : In use.
 *****************************************************************************/
extern kal_bool mmi_uc_is_mms_in_use(kal_uint32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_sms_in_use
 * DESCRIPTION
 *  Check if the msg_id is in used (Other application need to check for this before use a msg.
 *  Because same message can not be used by two applications simultaneously)
 *  msg_id : [IN] Msg id.
 * RETURNS
 *   KAL_FALSE  : Not in use.
 *   KAL_TRUE  : In use.
 *****************************************************************************/
extern kal_bool mmi_uc_is_sms_in_use(kal_uint32 msg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_reset_msg
 * DESCRIPTION
 *  This function is to reset msg info in UC context. Need to use when want to clear the context of UC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_reset_msg(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_no_recepient
 * DESCRIPTION
 *  This function returns true if there is no recepient in the message. Must to check before trigger to send.
 * PARAMETERS
 *  void
 * RETURNS
 *   FALSE  : recipient present.
 *   TRUE  : no recipient.
 *****************************************************************************/
extern BOOL mmi_uc_is_no_recepient(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms_from_previewer
 * DESCRIPTION
 *  This function need to call when user select send item in previewer screen.
 * PARAMETERS
 *  sim_id : [IN] mmi_uc_sim_id
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_send_mms_from_previewer(mmi_uc_sim_id sim_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_edit_mms_content_from_previewer
 * DESCRIPTION
 *  This function need to call when user select edit item in previewer screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_edit_mms_content_from_previewer(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_battery_low_callback
 * DESCRIPTION
 *  This function is pre evnet handler when battery is low. This callback need to call by framework low battery indication handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_battery_low_callback(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_launch
 * DESCRIPTION
 *  This function is to trigger request for start UC. If any MMI application need to start UC. Like MMS app currentely.
 * PARAMETERS
 *  msg_req : [IN] mmi_uc_start_struct
 * RETURNS
 *  mma_result_enum to check result
 *****************************************************************************/
extern U32 mmi_uc_launch(mmi_uc_start_struct *msg_req);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_collect_object_ind_data
 * DESCRIPTION
 *  This function is to collect the multiple objects information in one unit to pass to UC in one go. Currently used for phonebook interface.
 * PARAMETERS
 *  peer_buffer_p : [IN]    peerbuffer data passed by application
 *  num_of_object : [IN]    number of object passed
 *  more : [IN]     More req need to come
 *  uc_data : [OUT] UC context filled to collect complete req data to one unit
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_collect_object_ind_data(
                peer_buff_struct *peer_buffer_p,
                kal_uint32 num_of_object,
                kal_bool more,
                mmi_uc_entry_write_struct **uc_data);
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_free_collected_object_ind_data
 * DESCRIPTION
 *  This function is to free the UC context, created to help other application, used in multi object forward request to UC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_free_collected_object_ind_data(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_show_progress_entry_composer_write_msg
 * DESCRIPTION
 *  This function is to show process screen of entering unified composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_show_progress_entry_composer_write_msg(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_multi_object_insert_req
 * DESCRIPTION
 *  This function is to start request and show progress for multiple object forward to composer request.
 * PARAMETERS
 *  void
 * RETURNS
 *   KAL_FALSE  : not available.
 *   KAL_TRUE  : available.
 *****************************************************************************/
extern kal_bool mmi_uc_multi_object_insert_req(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_multi_object_req_is_in_process
 * DESCRIPTION
 *  This function is to check if multiple object forward request already in process.
 * PARAMETERS
 *  void
 * RETURNS
 *   KAL_FALSE  : not in process.
 *   KAL_TRUE  : in process.
 *****************************************************************************/
extern kal_bool mmi_uc_is_multi_object_req_is_in_process(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_show_progress_entry_composer_write_msg
 * DESCRIPTION
 *  This function is to show process when entering unified composer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_show_progress_entry_composer_write_msg(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_uc_ready
 * DESCRIPTION
 *  This function is to tell about UC ready or not to accept and process data. This depend on SMS and MMS ready.
 * PARAMETERS
 *  void
 * RETURNS
 *   MMI_FALSE  : not ready.
 *   MMI_TRUE  : ready.
 *****************************************************************************/
extern MMI_BOOL mmi_uc_is_uc_ready(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_uc_reenter
 * DESCRIPTION
 *  This function is to tell other MMI app that UC/MMS/SMS existence is already in history. As UC from its side not allowed reentry.
 * PARAMETERS
 *  void
 * RETURNS
 *   MMI_FALSE  : first entry.
 *   MMI_TRUE  : reentry.
 *****************************************************************************/
extern MMI_BOOL mmi_uc_is_uc_reenter(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_is_send_message_menu_hidden
 * DESCRIPTION
 *  This function is for other MMI app to know to show
 *   direct launch UC "Send message" option or not.
 * PARAMETERS
 *  void
 * RETURNS
 *   MMI_FALSE  : no need to hide.
 *   MMI_TRUE  : need to hide.
 *****************************************************************************/
extern MMI_BOOL mmi_uc_is_send_message_menu_hidden(void);

#ifdef __MMI_PHOTOEDITOR__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_edit_image_for_phoart_callback_to_asm
 * DESCRIPTION
 *  This function is to use by photoeditor to launch UC when there is not enough memory and control will be at ASM application side.
 *   Its required as there is no callback to photoeditor to contol flow in back key press.
 *   And photoeditor itseld unable to judge that user select Ok or back on that release memory selection screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_edit_image_for_phoart_callback_to_asm(void);
#endif /* __MMI_PHOTOEDITOR__ */ 

/* DOM-NOT_FOR_SDK-BEGIN */
#if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_handle_sms_msg_del_event
 * DESCRIPTION
 *  Callback to register to handle the sms delete case. update the UC status according to last state.
 * PARAMETERS
 *  event_data : [IN]    event data passed by the sms core in callback        
 * RETURNS
 *   MMI_FALSE  : others can also handle.
 *   MMI_TRUE  : for UC only.
 *****************************************************************************/
extern mmi_ret mmi_uc_handle_sms_msg_del_event(mmi_event_struct *event_data);
#endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */
/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_msg_operation_launch
 * DESCRIPTION
 *  Api to launch the operation via UC over a SMS, MMS or Postcard.
 *  Here possible operations are edit, forward, reply and reply to all.
 * PARAMETERS
 *  msg_id : [IN]    msg_id for the msg operated
 *  msg_type : [IN]    msg type sms/mms passed by caller application
 *  operation : [IN]    type of operation passed by caller application
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL mmi_uc_entry_msg_operation_launch( U32 msg_id, U16 msg_type, mmi_uc_msg_operation_enum operation);
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_write_msg_launch
 * DESCRIPTION
 *  Api to provide UI options to launch UC editor for msg or postcard.
 *  
 * PARAMETERS
 *  parent_cui_gid : [IN]    screen group parent id passed by caller application
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_write_msg_launch(mmi_id parent_cui_gid);

#ifdef __MMI_MMS_POSTCARD__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_write_msg_selection_launch
 * DESCRIPTION
 *  Api to provide UI options to launch UC message and postcard with parent id.
 *  
 * PARAMETERS
 *  parent_cui_gid : [IN]    screen group parent id passed by caller application
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_uc_entry_write_msg_selection_launch(mmi_id parent_cui_gid);
#endif /*#ifdef __MMI_MMS_POSTCARD__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_handle_sms_msg_del_event
 * DESCRIPTION
 *  Callback to register to handle the sms delete case. update the UC status according to last state.
 * PARAMETERS
 *  evt : [IN]    event data passed by the sms core in callback        
 * RETURNS
 *   MMI_RET      Always OK
 *****************************************************************************/
extern mmi_ret mmi_uc_force_close(mmi_event_struct *evt);
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _MMI_UNIFIED_COMPOSER_GPROT_H */ 
