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
 *  PhoneBookMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Phonebook Application Initialization.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef PHONEBOOKMAIN_C
#define PHONEBOOKMAIN_C

#include "CommonScreens.h"
#include "PhonebookResDef.h"
#include "PhoneBookCore.h"
#include "PhoneBookTypes.h"
#include "PhonebookProt.h"
#include "SettingGprots.h"
#include "GpioSrvGprot.h"

#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "IdleGprot.h"
#include "PhbCuiGprot.h"
#if 0
#ifdef __MMI_IMPS__
/* under construction !*/
#endif
#endif

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "sim_common_enums.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "smu_common_enums.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "ps_public_enum.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_app_phonebook_def.h"
#include "GlobalConstants.h"
/* auto add by kw_check end */

#define MMI_PHB_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init
 * DESCRIPTION
 *  Initialize phonebook applications.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __COSMOS_MMI_PACKAGE__

#else /* __COSMOS_MMI_PACKAGE__ */

#ifdef __MMI_TELEPHONY_SUPPORT__

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    mmi_phb_sos_list_init();
#endif

#ifdef __MMI_URI_AGENT__
    mmi_phb_init_uri_agent_registration();
#endif

#endif /*__MMI_TELEPHONY_SUPPORT__*/

#ifdef __MMI_PHONEBOOK_MEM_SLIM__
	mmi_phonebook_app_mem_init();
#endif
#endif /* __COSMOS_MMI_PACKAGE__ */
}

#ifdef __COSMOS_MMI_PACKAGE__

void mmi_phb_entry_main_menu(void)
{}

void mmi_phb_mark_several_for_msg_get_number(U8 *dest, U8 max_dest_len, U16 PhbIndex, U8 num_type)
{}


void mmi_phb_cntx_mgr_sim_refresh(U8 storage)
{}

void mmi_phb_cntx_mgr_init(void)
{}

void mmi_phb_startup_copy_sim2_pre_entry(void)
{}

U8 mmi_phb_startup_copy_sim2_check(void)
{
return 0;
}

void mmi_phb_cntx_mgr_at(U8 operation)
{}

void mmi_phb_startup_copy_sim_pre_entry(void)
{}

U8 mmi_phb_startup_copy_sim_check(void)
{
    return 0;
}

MMI_BOOL mmi_phb_image_check_valid_image(CHAR *path, MMI_BOOL auto_resize)
{
    return 0;
}

CHAR* mmi_phb_speed_dial_get_number(U16 key_id)
{
    return 0;
}

U8 mmi_phb_get_speed_dial_status(void)
{
    return 0;
}

void mmi_phb_op_email_custom_function(void)
{}

void mmi_phb_highlight_setting(void)
{}

mmi_ret mmi_phb_update_mass_processing(mmi_event_struct* param)
{
    return MMI_RET_OK;
}

mmi_ret mmi_phb_ready_hdlr(mmi_event_struct* para)
{
    return MMI_RET_OK;
}

mmi_ret mmi_phb_cntx_mgr_sim_profile(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

mmi_ret mmi_phb_processing_hdlr(mmi_event_struct* para)
{
    return MMI_RET_OK;
}

void mmi_phb_sc_sim2_owner_number_entry(void)
{}

void mmi_phb_sc_owner_number_entry(void)
{}

void mmi_phb_sc_add_new_entry(void)
{}

void mmi_phb_res_use_as_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{}

void mmi_phb_res_use_as_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{}


/*
 * Initialization Application
 */
#ifdef __MMI_PHB_QUICK_SEARCH__
void mmi_phb_quick_search_change_input_mode(void)
{}
#endif

/*
 *Phonebook List Screen
 */
#ifdef __MMI_PHB_QUICK_SEARCH__
void mmi_phb_quick_search_list_pre_entry(void)
{}
#endif
/*
 *  Common Screen
 */


/*
 *Phonebook List Screen
 */
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_list_pre_entry
 * DESCRIPTION
 *  enter phonebook normal list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_list_pre_entry(void)
{}

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
void mmi_phb_dial_normal_call(void)
{}

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
void mmi_phb_bday_editor_callback(U8 *DateStr, U8 *day, U8 *month, U8 *year)
{}
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */


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
U8 mmi_phb_get_sim_entry_by_location(U16 entryNum)
{
    return 0;
}


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
void mmi_phb_fmgr_from_file_mgr(CHAR *path)
{}

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
MMI_BOOL mmi_phb_check_ready(MMI_BOOL not_ready_popup)
{
    return MMI_TRUE;
}

MMI_BOOL mmi_phb_check_ready_with_sg_cb(
            mmi_id sg_id,
            MMI_BOOL not_ready_popup)
{
    return MMI_TRUE;
}

U16 mmi_phb_get_preferred_storage(void)
{
    return 0;
}


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
MMI_BOOL mmi_phb_check_processing(void)
{
    return MMI_TRUE;
}


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
MMI_BOOL mmi_phb_is_save_contact_notify_on(void)
{
    return MMI_TRUE;
}


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
MMI_BOOL mmi_phb_is_num_in_phb(U16* ucs2_num)
{
    return MMI_TRUE;
}


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
void mmi_phb_add_data_to_unsaved_list(phb_storage_enum storage, U32 show_type, srv_phb_contact_data_struct *phb_data)
{
}


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
void mmi_phb_delete_unsaved_data(void)
{}


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
void mmi_phb_entry_unsaved_data_confirm(void)
{}


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
void mmi_phb_pre_entry_unsaved_data_confirm(void)
{}


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
void mmi_phb_add_unsaved_data_confirm_to_history(void)
{}


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
U8 mmi_phb_get_unsaved_data_num(void)
{}


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
void mmi_phb_entry_save_contact_option(void)
{}


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
void mmi_phb_entry_unsaved_contact_list(void)
{}


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
void mmi_phb_unsaved_data_opt_add(void)
{}


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
void mmi_phb_unsaved_data_opt_update(void)
{}
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
MMI_BOOL mmi_phb_screen_present(void)
{
	return MMI_FALSE;
}

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
MMI_BOOL mmi_phb_edit_bday(void)
{
    return MMI_FALSE;
}
#endif

U16 mmi_phb_get_error_string(S32 result, mmi_event_notify_enum *popup_type, U16 store_index)
{
    return 0;
}

void mmi_phb_unsaved_data_init(srv_phb_contact_data_struct * contact)
{}

void cui_phb_save_contact_set_type(MMI_ID phb_save_sg_id, U32 type)
{}
U32 cui_phb_save_contact_get_support_type(void)
{
return 0;
}
    
/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_user_data
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is to set caller's user data
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]       screen group id
 *  user_data               :         [IN]       parent group's user data
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_user_data(mmi_id phb_save_sg_id, U32 user_data)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_get_user_data
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is to get caller's user data
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]       screen group id
 * RETURNS
 *  U32
 *****************************************************************************/
U32 cui_phb_save_contact_get_user_data(mmi_id phb_save_sg_id)
{
    return 0;

}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_store_index
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is for call phonebook editor CUI
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]       screen group id
 *  store_index             :         [IN]       edit contact's store index
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_store_index(mmi_id phb_save_sg_id, U16 store_index)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_action
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is only for phonebook to use
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]           phonebook save sg id
 *  action                  :         [IN]           operation: add/edit
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_action(mmi_id phb_save_sg_id, U8 action)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_storage
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook: this api is to set storage
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]           phonebook save sg id
 *  storage                 :         [IN]           phonebook storage
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_storage(mmi_id phb_save_sg_id, U8 storage)
{}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_create
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id             :                    GRP_ID_INVALID: Can not use CUI
 *****************************************************************************/
mmi_id cui_phb_save_contact_create(mmi_id parent_id)
{
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_data
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook
 * PARAMETERS
 *  phb_save_sg_id         :          [IN]          phonebook save sg id
 *  contact                :          [IN]          contact info to be saved
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_data(mmi_id phb_save_sg_id, srv_phb_contact_data_struct* contact)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_name
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save name info
 * PARAMETERS
 *  phb_save_sg_id          :         [IN]           phonebook save sg id
 *  first_name              :         [IN]           first name
 *  last_name               :         [IN]           last name if support
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_name(mmi_id phb_save_sg_id, U16* first_name, U16* last_name)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_number
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save number info
 * PARAMETERS
 *  phb_save_sg_id              :     [IN]          phonebook save sg id
 *  number                      :     [IN]          mobile number
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_number(mmi_id phb_save_sg_id, U16* number)
{}

#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_email
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, save email info
 * PARAMETERS
 *  phb_save_sg_id              :     [IN]            phonebook save sg id
 *  email                       :     [IN]            email address
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_email(mmi_id phb_save_sg_id, U16* email)
{}
#endif
#if 0
#if defined(__MMI_VOIP__)
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
/* under construction !*/
#if defined(__MMI_VOIP__)
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
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_need_popup
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, popup
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              phonebook save sg  id
 *  is_popup                   :      [IN]              MMI_TRUE: need popup by phonebook
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_need_popup(mmi_id phb_save_sg_id, MMI_BOOL is_popup)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_highlight_type
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, set first highlight item
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              phonebook save sg  id
 *  highlight_type             :      [IN]              item type
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_highlight_type(mmi_id phb_save_sg_id, U8 highlight_type)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_set_res
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, popup
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              phonebook save sg  id
 *  path                       :      [IN]              res path
 *  res_id                     :      [IN]              res id
 *  res_from                   :      [IN]              res from
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_set_res(mmi_id phb_save_sg_id, U16 *path, U16 res_id, U8 res_from)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_run
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, run function
 * PARAMETERS
 *  phb_save_sg_id             :      [IN]              save contact cui sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_run(mmi_id phb_save_sg_id)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_save_contact_close
 * DESCRIPTION
 *  Phonebook Cui - save a contact info to phonebook, close function
 * PARAMETERS
 *  phb_save_sg_id                :      [IN]           save contact sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_save_contact_close(mmi_id phb_save_sg_id)
{}


/** 
  * CUI: entry phonebook list to select a contact
  */

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - select list contact, creat function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id             :                    GRP_ID_INVALID: Can not use CUI
 *****************************************************************************/
mmi_id cui_phb_list_select_contact_create(mmi_id parent_id)
{
    return 0;

}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_user_data
 * DESCRIPTION
 *  Phonebook Cui - select list contact: this api is to set caller's user data
 * PARAMETERS
 *  phb_select_sg_id        :         [IN]       screen group id
 *  user_data               :         [IN]       parent group's user data
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_user_data(mmi_id phb_select_sg_id, U32 user_data)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_get_user_data
 * DESCRIPTION
 *  Phonebook Cui - select list contact: this api is to get caller's user data
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       screen group id
 * RETURNS
 *  U32
 *****************************************************************************/
U32 cui_phb_list_select_contact_get_user_data(mmi_id phb_select_sg_id)
{
return 0;
}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_field_filter
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set contact's field filter
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  filter                    :         [IN]       phonebook field filter
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_field_filter(mmi_id phb_select_sg_id, U32 filter)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_storage
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set contact's storage
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  storage                   :         [IN]       phonebook storage, default is preffered storage
 *                                                 PHB_STORAGE_MAX/PHB_STORAGE_NVRAM/PHB_STORAGE_SIM
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_storage(mmi_id phb_select_sg_id, U8 storage)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_group
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set caller group id
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  group_id                  :         [IN]       Caller group id. for show caller group member list
 *  is_equal                  :         [IN]       group id filter
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_group(mmi_id phb_select_sg_id, U8 group_id, MMI_BOOL is_equal)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_lsk_icon
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set lsk icon
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  lsk_img                   :         [IN]       set lsk label/image
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_lsk_icon(mmi_id phb_select_sg_id, U16 lsk_img)
{}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_contact_set_first_highlight_index
 * DESCRIPTION
 *  Phonebook Cui - select list contact, set first highlight
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  index                     :         [IN]       highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_contact_set_first_highlight_index(mmi_id phb_select_sg_id, S32 index)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_run
 * DESCRIPTION
 *  Phonebook Cui - select list contact, run function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_run(mmi_id phb_select_sg_id)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_close
 * DESCRIPTION
 *  Phonebook Cui - select list contact, close function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_close(mmi_id phb_select_sg_id)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_emit
 * DESCRIPTION
 *  Phonebook Cui - select list contact, emit event
 * PARAMETERS
 *  parent_id          :         [IN]       List sg id
 *  evt_id             :         [IN]       event id
 *  name               :         [IN]       contact name
 *  select_data        :         [IN]       select data
 *  data_type          :         [IN]       data type
 *  store_index        :         [IN]       store index
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_emit(
                mmi_id parent_id,
                U16 evt_id,
                U16 *name,
                U16 *select_data,
                U32 data_type,
                U16 store_index)
{}


/** 
  * CUI: entry phonebook list to select contacts
  */

/**
  * Cui multi select result event structure
  */
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_select_contact_set_count
 * DESCRIPTION
 *  Phonebook Cui - multi select contact set max select count
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 *  select_count              :         [IN]       max select count
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_select_contact_set_count(mmi_id phb_select_sg_id, U16 select_count)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - multi select contact create function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id             :                    GRP_ID_INVALID: Can not use CUI
 *****************************************************************************/
mmi_id cui_phb_list_multi_select_contact_create(mmi_id parent_id)
{
return 0;
}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_run
 * DESCRIPTION
 *  Phonebook Cui - multi select contact, run function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_multi_select_contact_run(mmi_id phb_select_sg_id)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_close
 * DESCRIPTION
 *  Phonebook Cui - multi select contact, close funtion
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_multi_select_contact_close(mmi_id phb_select_sg_id)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_create
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, create function
 * PARAMETERS
 *  parent_id          :         [IN]       Caller screen group id
 * RETURNS
 *  mmi_id             :                    GRP_ID_INVALID: Can not use CUI
 *****************************************************************************/
mmi_id cui_phb_list_group_select_contact_create(mmi_id parent_id)
{
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_run
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, run function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_group_select_contact_run(mmi_id phb_select_sg_id)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_group_select_contact_close
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, close function
 * PARAMETERS
 *  phb_select_sg_id          :         [IN]       List sg id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_group_select_contact_close(mmi_id phb_select_sg_id)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_list_multi_select_contact_emit
 * DESCRIPTION
 *  Phonebook Cui - tab multi select contact, emit event
 * PARAMETERS
 *  parent_id          :         [IN]       List sg id
 *  evt_id             :         [IN]       event id
 *  count              :         [IN]       contact count
 *  store_index        :         [IN]       contact store index array
 *  field_index        :         [IN]       field type array
 *  is_group           :         [IN]       is selected from group
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_list_multi_select_contact_emit(
                 mmi_id parent_id,
                 U16 evt_id,
                 U16 count,
                 U16 *store_index,
                 U8 *field_index,
                 MMI_BOOL is_group)
{}
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */

/*****************************************************************************
 * FUNCTION
 *  cui_phb_send_data_to_sa
 * DESCRIPTION
 *  Phonebook Cui - send result to Caller group proc function
 * PARAMETERS
 *  parent_id              :         [IN]       Caller group sg id
 *  data                   :         [IN]       CUI result data
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_send_data_to_sa(mmi_id parent_id, void* data)
{}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_launch
 * DESCRIPTION
 *  Phonebook Cui - launch phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_launch(void)
{}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_idle_launch
 * DESCRIPTION
 *  Phonebook Cui - launch phonebook from idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_idle_launch(void)
{}

/*****************************************************************************
 * FUNCTION
 *  cui_phb_view_contact
 * DESCRIPTION
 *  Phonebook Cui - view one contact
 * PARAMETERS
 *  parent_id              :        [IN]        parent group id
 *  store_index            :        [IN]        contact store index
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id cui_phb_view_contact(mmi_id parent_id, U16 store_index)
{
    return 0;
}

#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
MMI_ID cui_phb_select_image_create(MMI_ID group_id, U32 type)
{
    return 0;
}
void cui_phb_select_image_run(MMI_ID group_id)
{}
void cui_phb_select_image_close(MMI_ID sg_id)
{}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_init
 * DESCRIPTION
 *  Phonebook Cui - init structure
 * PARAMETERS
 *  cui_phb_search_contact_struct   [IN]    search filter, see struct: cui_phb_search_contact_struct
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
void cui_phb_search_contact_init(cui_phb_search_contact_struct *search)
{}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_create
 * DESCRIPTION
 *  Phonebook Cui - create function
 * PARAMETERS
 *  parent_id                       [IN]    parent group id
 *  cui_phb_search_contact_struct   [IN]    search filter, see struct: cui_phb_search_contact_struct
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
MMI_ID cui_phb_search_contact_create(MMI_ID parent_id, cui_phb_search_contact_struct *search)
{
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_get_data
 * DESCRIPTION
 *  Phonebook Cui - get selected data
 * PARAMETERS
 *  group_id                        [IN]    cui group id
 *  id                              [IN]    selected contact id
 *  field_mask                      [IN]    selected field mask
 *  buf                             [OUT]   selected data
 *  buf_length                      [OUT]   buf length
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_search_contact_get_data(MMI_ID group_id, U16 id, U32 field_mask, U16 *buf, U16 buf_length, MMI_BOOL more)
{}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_pre_run
 * DESCRIPTION
 *  Phonebook Cui - pre run function, maybe no screen to show
 * PARAMETERS
 *  group_id                        [IN]    cui group id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_search_contact_pre_run(MMI_ID group_id)
{}


/*****************************************************************************
 * FUNCTION
 *  cui_phb_search_contact_run
 * DESCRIPTION
 *  Phonebook Cui - run the cui
 * PARAMETERS
 *  group_id                        [IN]    cui group id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_phb_search_contact_run(MMI_ID group_id)
{}


/*****************************************************************************
 * FUNCTION
 *  cui_pbh_search_contact_close
 * DESCRIPTION
 *  Phonebook Cui - close the cui
 * PARAMETERS
 *  group_id                        [IN]    cui group id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_pbh_search_contact_close(MMI_ID group_id)
{}

#endif

#endif /* PHONEBOOKMAIN_C */

