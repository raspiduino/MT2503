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
 *  PhoneBookGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PhoneBook global prototypes 
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef PHONEBOOKGPROT_H
#define PHONEBOOKGPROT_H

#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "Custom_events_notify.h"
#include "PhbSrvGprot.h"
#include "PhoneBookResDef.h"

/* auto add by kw_check begin */
#include "MMI_common_app_trc.h"
#include "gui_data_types.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "mmi_frm_events_gprot.h"
#include "UcmSrvGprot.h"
/* auto add by kw_check end */

#define MMI_PHB_BDAY_YEAR_STR L"0000"           /* Empty Birthday year*/
#define MMI_PHB_BDAY_MON_STR  L"00"             /* Empty Birthday month*/
#define MMI_PHB_BDAY_DAY_STR  L"00"             /* Empty Birthday day*/

#define MMI_PHB_TRACE_GROUP MMI_COMMON_TRC_G4_PHB
/* for quick search */
#define MMI_PHB_QUICK_SEARCH_INPUT_LENGTH 6

/** 
 * Typedef 
 */
typedef pBOOL(*GetItemPtr) (S32, UI_string_type, PU8 *, U8);
typedef S32(*GetHintPtr) (S32, UI_string_type *);
typedef void (*FunctionPtr) (void);
typedef void (*HighlightPtr) (S32);
typedef void (*MenucuiPtr) (MMI_ID);

/* phonebook address type enum */
typedef enum
{
    MMI_PHB_ADDRESS_TYPE_NUMBER,            /* number */
    MMI_PHB_ADDRESS_TYPE_EMAIL,             /* email */
    MMI_PHB_ADDRESS_TYPE_TOTAL_NUM          /* enum total */
} mmi_phb_address_type_enum;


#ifdef __MMI_URI_AGENT__
/* result enum for uri agent */
typedef enum
{
    MMI_PHB_URIAGENT_ERR_OK,                 /* success */
    MMI_PHB_URIAGENT_ERR_PHB_NOT_READY,      /* phonebook not ready */
    MMI_PHB_URIAGENT_ERR_PHB_PROCESS_USIM,   /* phonebook USIM processing */
    MMI_PHB_URIAGENT_ERR_PHB_IN_SYNC,        /* phonebook syncing */
    MMI_PHB_URIAGENT_ERR_URI_FORMAT_WRONG,   /* data format error */
    MMI_PHB_URIAGENT_ERR_NAME_TOO_LONG,      /* name too long */
    MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG,       /* number too long */
    MMI_PHB_URIAGENT_ERR_PHB_WRITE_ERROR,    /* save contact error */
    MMI_PHB_URIAGENT_ERR_FDN_ON_ERROR,       /* phonebook FDN on */
    MMI_PHB_URIAGENT_ERR_PHB_IS_FULL,        /* phonebook is full */
    MMI_PHB_URIAGENT_ERR_ENUM_TOTAL          /* enum total */
} mmi_phb_uriagent_err_enum;
#endif

/* phonebook field type enum */
typedef enum
{
    MMI_PHB_FIELDS_TYPE_NAME,                   /* name field */
    MMI_PHB_FIELDS_TYPE_NUMBER,                 /* number field */
    MMI_PHB_FIELDS_TYPE_HOME_NUMBER,            /* home number field */
    MMI_PHB_FIELDS_TYPE_COMPANY_NAME,           /* company name field */
    MMI_PHB_FIELDS_TYPE_EMAIL_ADDRESS,          /* email address field */
    MMI_PHB_FIELDS_TYPE_OFFICE_NUMBER,          /* office number field */
    MMI_PHB_FIELDS_TYPE_FAX_NUMBER,             /* fax number field */
    MMI_PHB_FIELDS_TYPE_BIRTHDAY,               /* birthday field */
    MMI_PHB_FIELDS_TYPE_TITLE,                  /* title field */
    MMI_PHB_FIELDS_TYPE_URL,                    /* url field */
    MMI_PHB_FIELDS_TYPE_ADDRESS,                /* address field */
    MMI_PHB_FIELDS_TYPE_NOTE,                   /* note field */
    MMI_PHB_FIELDS_TYPE_NICK_NAME,              /* nike name field */
    MMI_PHB_FIELDS_TYPE_ENUM_TOTAL              /* enum total */
}mmi_phb_fields_type_enum;

/* Owner number associate with Line ID */
typedef struct
{
    U8 name[(MMI_PHB_NAME_LENGTH + 1) *ENCODING_LENGTH];             /* name field */
    U8 number[(MMI_PHB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];     /* number field */
} MMI_PHB_OWNER_NUMBER_STRUCT;
#if 0
#ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

//TODO: 
/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  FuncPhbListCallback
 * DESCRIPTION
 *  phonebook list call back function 
 * PARAMETERS
 *  resut_entry       :    [IN]    phonebook contact's data
 * RETURNS
 *  void
 *****************************************************************************/
//typedef void (*FuncPhbListCallback) (mmi_phb_my_number_struct *resut_entry);

/* 
 * Extern Global Function
 */

/*
 * Initialization Application
 */
#ifdef __MMI_PHB_QUICK_SEARCH__
extern void mmi_phb_quick_search_change_input_mode(void);
#endif

/*
 *Phonebook List Screen
 */
#ifdef __MMI_PHB_QUICK_SEARCH__
extern void mmi_phb_quick_search_list_pre_entry(void);
#endif
/*
 *  Common Screen
 */


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  mmi_phb_send_address_to_others_callback_type
 * DESCRIPTION
 *  phonebook get address call back function for message
 * PARAMETERS
 *  index            :    [IN]     vcard file path
 *  type             :    [OUT]    output address type
 * RETURNS
 *  CHAR*
 * RETURN VALUES
 *  address          :             address data point
 *****************************************************************************/
typedef CHAR* (*mmi_phb_send_address_to_others_callback_type)(U16 index, U16* type);

#ifdef __MMI_MOBILE_SERVICE__
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dial_normal_call
 * DESCRIPTION
 *  make call to highlight contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_dial_normal_call(void);

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_editor_callback
 * DESCRIPTION
 *  convert date value to a string
 * PARAMETERS
 *  DateStr     :   [OUT]    Date string buffer         
 *  day         :   [IN]     Day value       
 *  month       :   [IN]     Month value       
 *  year        :   [IN]     Year value  
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_bday_editor_callback(U8 *DateStr, U8 *day, U8 *month, U8 *year);
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */




#ifdef __MMI_DIALER_SEARCH__
/* Dialler Search */

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_hint
 * DESCRIPTION
 *  get hint function for dail search
 * PARAMETERS
 *  item_index      :    [IN]     The index of menu item
 *  hint_array      :    [OUT]    A pointer of parameter to store the hint
 * RETURNS
 *  S32
 * RETURN VALUES
 *  The number of hints loaded :  Success to get the hints
 *  0                          :  Fail to get the hints
 *****************************************************************************/
extern S32 mmi_phb_ds_get_hint(S32 item_index, UI_string_type* hint_array);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_index
 * DESCRIPTION
 *  highlight function for dail search list
 * PARAMETERS
 *  item_index      :    [IN]     highlight item index
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_ds_get_index(S32 item_index);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_item
 * DESCRIPTION
 *  get item function for dail search
 * PARAMETERS
 *  item_index       :   [IN]     The index of menu item
 *  str_buff         :   [OUT]    The string buffer to store the text
 *  img_buff_p       :   [OUT]    A pointer of parameter to store the image 
 *  str_img_mask     :   [IN]     The mask of image
 * RETURNS
 *  pBOOL
 * RETURN VALUES
 *  MMI_TRUE         :            Return MMI_TRUE always
 *****************************************************************************/
extern pBOOL mmi_phb_ds_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_get_underline
 * DESCRIPTION
 *  Indicate how to draw the underline of menu item for dail search
 * PARAMETERS
 *  item_index        :   [IN]  The index of menu item
 *  underline_index   :   [OUT] A pointer of parameter to store the index of underline mark
 *  count             :   [OUT] A pointer of parameter to store the count of underline
 * RETURNS
 *  MMI_BOOL 
 * RETURN VALUES
 *  MMI_TRUE          :   Always return MMI_TRUE.
 *****************************************************************************/
extern MMI_BOOL mmi_phb_ds_get_underline(S32 item_index, S32 *underline_index, S32 *count);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_options
 * DESCRIPTION
 *  entry dail search options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_ds_entry_options(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_entry_op_dial
 * DESCRIPTION
 *  make call for dail search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_ds_entry_op_dial(srv_ucm_call_type_enum sim_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_sendkey_call_pre_entry
 * DESCRIPTION
 *  make call for dail search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_ds_sendkey_call_pre_entry(srv_ucm_call_type_enum sim_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_csk_call_pre_entry
 * DESCRIPTION
 *  make call for dail search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_ds_csk_call_pre_entry(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_find_entry
 * DESCRIPTION
 *  get entry function for dail search list
 * PARAMETERS
 *  keyword     :   [IN]   input keyword     
 * RETURNS
 *  S32 
 * RETURN VALUES
 *  count       :          entry count
 *****************************************************************************/
extern S32 mmi_phb_ds_find_entry(UI_buffer_type keyword);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_reset_result
 * DESCRIPTION
 *  reset dail search result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_ds_reset_result(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_delete_option_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_ds_delete_option_scr(void);

#ifndef __COSMOS_MMI_PACKAGE__

#ifdef __MMI_UNIFIED_COMPOSER__

extern void mmi_phb_ds_send_message_directly(U16* num_uri, grp_id_phb_enum gid);
#else

extern void mmi_phb_ds_send_sms_directly(U16* num_uri, grp_id_phb_enum gid);

#ifdef __MMI_MMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ds_send_mms_directly
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_ds_send_mms_directly(U16* num_uri, grp_id_phb_enum gid);

#endif
#endif
#endif

#endif /* __MMI_DIALER_SEARCH__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_sim_entry_by_location
 * DESCRIPTION
 *  Return the number to idle screen for quick access
 * PARAMETERS
 *  entryNum       :    [IN]        Location to be search
 * RETURNS
 *  U8
 * RETURN VALUES
 *  0              :    no entry
 *  1              :    have entry
 *****************************************************************************/
extern U8 mmi_phb_get_sim_entry_by_location(U16 entryNum);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fmgr_from_file_mgr
 * DESCRIPTION
 *  forward function for file manager application
 * PARAMETERS
 *  path        :    [IN]  resource path       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_fmgr_from_file_mgr(CHAR *path);

#if 0
#if defined(__MMI_VRSD_DIAL__)
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
#endif /* defined(__MMI_VRSD_DIAL__) */ 
#endif

#if 0
#if defined(__MMI_VRSI__) && defined(__MMI_VRSI_TRAIN_TAG__)
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
#endif /* defined(__MMI_VRSI__) && defined(__MMI_VRSI_TRAIN_TAG__) */ 
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_ready
 * DESCRIPTION
 *  test phonebook is ready
 * PARAMETERS
 *  not_ready_popup   :      [IN]          need popup not ready info or not
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE          :                    phonebook ready
 *  MMI_FALSE         :                    phonebook not ready
 *****************************************************************************/
extern MMI_BOOL mmi_phb_check_ready(MMI_BOOL not_ready_popup);

extern MMI_BOOL mmi_phb_check_ready_with_sg_cb(
            mmi_id sg_id,
            MMI_BOOL not_ready_popup);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_processing
 * DESCRIPTION
 *  check phonebook is processing
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE          :                    phonebook processing
 *  MMI_FALSE         :                    phonebook not processing
 *****************************************************************************/
extern MMI_BOOL mmi_phb_check_processing(void);

#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
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
#endif /* __MMI_PHB_ICE_CONTACT__ */
#endif

#ifdef __MMI_PHB_STARTUP_COPY_SIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim_check
 * DESCRIPTION
 *  start copy SIM to phone call back funtion for entry idle 
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 * RETURN VALUES
 *  1              :                    need copy
 *  0              :                    no need copy
 *****************************************************************************/
extern U8 mmi_phb_startup_copy_sim_check(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim_pre_entry
 * DESCRIPTION
 *  entry copy SIM to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_startup_copy_sim_pre_entry(void);
#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim2_check
 * DESCRIPTION
 *  start copy SIM2 to phone call back funtion for entry idle 
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 * RETURN VALUES
 *  1              :                    need copy
 *  0              :                    no need copy
 *****************************************************************************/
extern U8 mmi_phb_startup_copy_sim2_check(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim2_pre_entry
 * DESCRIPTION
 *  entry copy SIM2 to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_startup_copy_sim2_pre_entry(void);
#endif
#if (MMI_MAX_SIM_NUM >=3)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim3_check
 * DESCRIPTION
 *  start copy SIM2 to phone call back funtion for entry idle 
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 * RETURN VALUES
 *  1              :                    need copy
 *  0              :                    no need copy
 *****************************************************************************/
extern U8 mmi_phb_startup_copy_sim3_check(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim3_pre_entry
 * DESCRIPTION
 *  entry copy SIM2 to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_startup_copy_sim3_pre_entry(void);
#endif
#if (MMI_MAX_SIM_NUM >=4)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim4_check
 * DESCRIPTION
 *  start copy SIM2 to phone call back funtion for entry idle 
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 * RETURN VALUES
 *  1              :                    need copy
 *  0              :                    no need copy
 *****************************************************************************/
extern U8 mmi_phb_startup_copy_sim4_check(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_startup_copy_sim4_pre_entry
 * DESCRIPTION
 *  entry copy SIM2 to phone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_startup_copy_sim4_pre_entry(void);
#endif
#endif /* __MMI_PHB_STARTUP_COPY_SIM__ */

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_is_save_contact_notify_on
 * DESCRIPTION
 *  Check if the save contact notify on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_phb_is_save_contact_notify_on(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_is_num_in_phb
 * DESCRIPTION
 *  Check if the num is stored in phb or not
 * PARAMETERS
 *  ucs2_num      :      [IN]    ucs2 number
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_phb_is_num_in_phb(U16* ucs2_num);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_data_to_unsaved_list
 * DESCRIPTION
 *  save the data to the unsaved list
 * PARAMETERS
 *  storage        :      [IN]       phonebook storage to save contact
 *  show_type      :      [IN]       data type
 *  phb_data       :      [IN]       data info
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_add_data_to_unsaved_list(phb_storage_enum storage, U32 show_type, srv_phb_contact_data_struct *phb_data);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_unsaved_data
 * DESCRIPTION
 *  delete ith node and related screen after add new or replace a contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_delete_unsaved_data(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_unsaved_data_confirm
 * DESCRIPTION
 *  entry function for unsaved_data_confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_entry_unsaved_data_confirm(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_unsaved_data_confirm
 * DESCRIPTION
 *  pre_entry function for unsaved_data_confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_pre_entry_unsaved_data_confirm(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_add_unsaved_data_confirm_to_history
 * DESCRIPTION
 *  add unsaved conform screen to histoy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_add_unsaved_data_confirm_to_history(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_unsaved_data_num
 * DESCRIPTION
 *  get unsaved data num
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count         :       unsaved data count   
 *****************************************************************************/
extern U8 mmi_phb_get_unsaved_data_num(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_option
 * DESCRIPTION
 *  entry screen of save contact option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_entry_save_contact_option(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_unsaved_contact_list
 * DESCRIPTION
 *  entry function for unsaved contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_entry_unsaved_contact_list(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_opt_add
 * DESCRIPTION
 *  add new contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_unsaved_data_opt_add(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_opt_update
 * DESCRIPTION
 *  handler for update existed contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_unsaved_data_opt_update(void);
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_screen_present
 * DESCRIPTION
 *  check if any phonebook screen exist in history
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE               :                    present
 *  MMI_FALSE              :                    not present
 *****************************************************************************/
extern MMI_BOOL mmi_phb_screen_present(void);


#ifdef __MMI_UDX_VCARD_SUPPORT__
/****************************************************************************
 * FUNCTION
 *  mmi_phb_udx_set_processing
 * DESCRIPTION
 *  when udx is busy with phonebook, set phonebook processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_udx_set_processing(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_udx_reset_processing
 * DESCRIPTION
 *  after udx build or parse vcard, reset phonebook processing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_udx_reset_processing(void);
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
extern MMI_BOOL mmi_phb_edit_bday(void);
#endif

extern U16 mmi_phb_get_error_string(S32 result, mmi_event_notify_enum *popup_type, U16 store_index);
extern void mmi_phb_unsaved_data_init(srv_phb_contact_data_struct * contact);

#ifdef __MMI_DIALER_SEARCH__
#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_UNIFIED_COMPOSER__
extern void mmi_phb_ds_op_fte_send_message(void);
#else
extern void mmi_phb_ds_op_fte_send_sms(void);
#ifdef __MMI_MMS__
extern void mmi_phb_ds_op_fte_send_mms(void);
#endif /* __MMI_MMS__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */
extern void mmi_phb_ds_fte_entry_op_view(void);
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_DIALER_SEARCH__ */
extern void mmi_phb_entry_memory_status(void);
#if 0
#ifdef __OP01_FWPBW__
/* under construction !*/
#endif
#endif
#endif /* PHONEBOOKGPROT_H */ 

