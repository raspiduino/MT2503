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
 * MMSAppUIController.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#if defined (__MMI_MMS_2__) && defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)

/* Include Files */
#include "MMIDataType.h"
#include "wgui_softkeys.h"
#include "MMSAppComposerUILE.h"
#include "MmsContextSrvLE.h"
#include "FileMgrCUIGProt.h"
#include "PhbCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mma_struct.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "MMSAppDataManager.h"
#include "MMSAppInterfaceGprot.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "MMSAppResDef.h"
#include "MmsMemoryManagerSrv.h"
#include "MMSAppResourceDB.h"
#include "MMSAppSrvHdlr.h"
#include "mmi_rp_app_sms_def.h"
#include "MMSAppUIDraw.h"
#include "MMSAppUIPlugin.h"
#include "MMSAppScrHdlr.h"
#include "MMSAppScrHdlrEx.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __MMI_USB_SUPPORT__ */ 
#include "MMSAppUICallback.h"
#include "Conversions.h"
#include "Wgui_categories_util.h"
#include "SmsSrvGProt.h"
#include "MMSAppUIdrawEx.h"
/* Variables */
mmi_imm_input_mode_enum g_mms_required_input_modes[] = 
{
    IMM_INPUT_MODE_PHONE_NUMBER,
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC,
    IMM_INPUT_MODE_NONE
};

extern srv_mms_uc_main_struct g_srv_mms_uc_supp;
static mmi_umms_app_ui_plug_in_status_action_enum g_action_enum;
U16 g_umms_card_phone_str_id = 0;
static mmi_umms_uc_entry_write_struct *g_uc_start_context;
/* Functions */
static mmi_ret mmi_umms_uc_delete_addr_confirm_popup_group_proc(mmi_alert_result_evt_struct *evt);
static void mmi_umms_uc_select_fmgr_object(mmi_id menu_id);
static void mmi_umms_uc_process_entry_delete_slide(void);
extern kal_uint32 applib_get_file_size(kal_wchar *filename);
static void mmi_umms_app_ui_plug_in_handle_saving_sending_mms_cb(
                srv_mms_result_enum result,
                void *rsp_data,
                void *user_data);
static void mmi_umms_set_prefer_storage(void);
extern srv_mms_uc_main_struct g_srv_mms_uc_supp;
extern mmi_ret mmi_umms_proc_func(mmi_event_struct *evt);
static MMI_UMMS_ERROR mmi_umms_get_data(U8 mode);
static void mmi_umms_get_data_cb(srv_mms_result_enum result, void *msgrsp, void *user_data);
static mmi_ret mmi_umms_dummy_func(mmi_event_struct *evt);
/* Function Definitions */

/* Function Definitions */


/*****************************************************************************
 * FUNCTION
 *  cui_uc_write_msg_launch
 * DESCRIPTION
 *  Launch editor from UM.
 * PARAMETERS
 *  parent_grp_id       [IN]        
 *  instance(?)         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_uc_write_msg_launch(mmi_id parent_grp_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Crucual Point need to set parent and set memory and many more please handle carefully */
    mmi_umms_app_if_start_composer_from_cui(parent_grp_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_entry_validation_checks_for_recipient
 * DESCRIPTION
 *  Entry unified composer address validation checks.
 * PARAMETERS
 *  addr        [IN]        
 *  MMI_BOOL(?)     [IN](?)
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_umms_uc_entry_validation_checks_for_recipient(mma_mms_addr_list_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = STR_GLOBAL_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((addr->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER) &&
        srv_mms_uc_is_phone_number_valid((S8*) addr->address) == KAL_FALSE)
    {
        string_id = STR_GLOBAL_INVALID_NUMBER;
    }
    else if ((addr->addr_type == MMA_ADDR_TYPE_EMAIL) &&
             (mmi_ucs2strlen((S8*) addr->address) > SRV_MMS_UC_MAX_PHONE_NUMBER_LEN))
    {
        string_id = STR_UMMS_UC_NUMBER_LENGTH_EXCEED_ID;
    }
    else if ((addr->addr_type == MMA_ADDR_TYPE_EMAIL) &&
             applib_is_valid_email_address_unicode((kal_wchar*) addr->address) == KAL_FALSE)
    {
        string_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
    }
    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_select_fmgr_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_select_fmgr_object(mmi_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
        case MENU_ID_UMMS_INSERT_IMAGE:
        {
            mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE);
            g_srv_mms_uc_supp.highlighted_object_type = MMA_INSERT_IMAGE;
        }
            break;
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
        case MENU_ID_UMMS_INSERT_SOUND:
        {
            mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE);
            g_srv_mms_uc_supp.highlighted_object_type = MMA_INSERT_AUDIO;
        }
            break;
#endif
        case MENU_ID_UMMS_INSERT_VIDEO:
        {
            mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE);
            g_srv_mms_uc_supp.highlighted_object_type = MMA_INSERT_VIDEO;
        }
            break;
            /* kuldeep_attachment */
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
        case MENU_ID_UMMS_INSERT_ATTACHMENT:
        {
            mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE);
            g_srv_mms_uc_supp.highlighted_object_type = MMA_INSERT_ATTACHMENT;
        }
            break;
#endif
            

        default:
        {
            /* MMI_ASSERT(0); */
        }
            break;
    }
    {
        mmi_id cui_fmgr_gid;
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
        /* kuldeep_attachment */
        if (g_srv_mms_uc_supp.highlighted_object_type == MMA_INSERT_ATTACHMENT)
        {
            cui_fmgr_gid = cui_file_selector_create(
                            mmi_umms_dtmgr_get_group_id(),
                            (WCHAR*) L"root",
                            &filter,
                            CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                            CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER);
        }
        else
#endif
        {
            cui_fmgr_gid = cui_file_selector_create(
                            mmi_umms_dtmgr_get_group_id(),
                            (WCHAR*) L"root",
                            &filter,
                            CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                            CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE);
        }
        mmi_umms_app_dtmgr_set_common_cui_id(cui_fmgr_gid);

    }
    if (mmi_umms_app_dtmgr_get_common_cui_id() > 0)
    {
        /* cui_file_selector_set_title(mmi_umms_app_dtmgr_get_common_cui_id(),
           0, IMG_UC_ENTRY_SCRN_CAPTION_ID); */
        cui_file_selector_run(mmi_umms_app_dtmgr_get_common_cui_id());
    }
    else
    {
        /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_launch_phb_for_recipient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_launch_phb_for_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_phb_gid;
    mma_mms_header_struct *header = srv_mms_container_get_header();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_uc_supp.srv_msg.total_address_num = (header->to_num + header->cc_num + header->bcc_num);
    if (g_srv_mms_uc_supp.srv_msg.total_address_num >= SRV_MMS_UC_MAX_ADDRESS_NUM)
    {
        /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_UMMS_UC_RECIPIENT_NUMBER_EXCEED_ID)), MMI_EVENT_ERROR, NULL); */
        mmi_umms_app_dtmgr_set_popup_screen_para(
            (U16*) GetString(STR_ID_UMMS_UC_RECIPIENT_NUMBER_EXCEED_ID),
            MMI_EVENT_ERROR);
        mmi_umms_app_if_show_display_popup_screen();
        return;
    }
    cui_phb_gid = cui_phb_list_select_contact_create(mmi_umms_dtmgr_get_group_id());
    mmi_umms_app_dtmgr_set_common_cui_id(cui_phb_gid);
    if (mmi_umms_app_dtmgr_get_common_cui_id() != GRP_ID_INVALID)
    {
        {
            cui_phb_list_select_contact_set_field_filter(
                mmi_umms_app_dtmgr_get_common_cui_id(),
                SRV_PHB_ENTRY_FIELD_NUMBER | SRV_PHB_ENTRY_FIELD_EMAIL);
        }

        cui_phb_list_select_contact_run(mmi_umms_app_dtmgr_get_common_cui_id());

    }
    else
    {
        mmi_frm_group_close(mmi_umms_app_dtmgr_get_common_cui_id());
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_launch_subject_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_launch_subject_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_subject_gid;
    mma_mms_header_struct *header = srv_mms_container_get_header();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* getting the subject buffer for editor */
    g_srv_mms_uc_supp.srv_msg.fseditor_buffer =
        (U16*) srv_mms_mem_mgr_viewer_asm_alloc(sizeof(U16) * (SRV_MMS_UC_MAX_SUBJECT_LEN + 1));
    memset(g_srv_mms_uc_supp.srv_msg.fseditor_buffer, 0, (sizeof(U16) * (SRV_MMS_UC_MAX_SUBJECT_LEN + 1)));

    /* copy here the subject in buffer if present to show on editor screen */
    if (header->subject.text)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_srv_mms_uc_supp.srv_msg.fseditor_buffer,
            (kal_int32) (sizeof(U16) * (SRV_UM_MAX_SUBJECT_LEN + 1)),
            (kal_uint8*) header->subject.text);
    }
    if ((cui_subject_gid = cui_fseditor_create(mmi_umms_dtmgr_get_group_id())) != NULL)
    {
        mmi_umms_app_dtmgr_set_common_cui_id(cui_subject_gid);
        /* set here the title [title string and title image] */
        cui_fseditor_set_title(mmi_umms_app_dtmgr_get_common_cui_id(), STR_GLOBAL_SUBJECT, NULL);

        cui_fseditor_set_buffer(
            mmi_umms_app_dtmgr_get_common_cui_id(),
            (PU8) g_srv_mms_uc_supp.srv_msg.fseditor_buffer,
            (SRV_MMS_UC_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH,
            SRV_MMS_UC_MAX_SUBJECT_LEN);

        cui_fseditor_set_input_method(
            mmi_umms_app_dtmgr_get_common_cui_id(),
            IMM_INPUT_TYPE_SENTENCE,
            NULL,
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        cui_fseditor_set_parent_data(mmi_umms_app_dtmgr_get_common_cui_id(), MENU_ID_UMMS_EDIT_SUBJECT);
        cui_fseditor_run(mmi_umms_app_dtmgr_get_common_cui_id());
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_app_get_recipient_editor_filters_for_input_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static S32 *mmi_umms_uc_app_get_recipient_editor_filters_for_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const UI_string_type allowed_characters = mmi_imm_get_allowed_email_address_characters();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imm_set_characters(MMI_TRUE, allowed_characters);
    return (S32*) g_mms_required_input_modes;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_enter_recipient_manual
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_enter_recipient_manual(mmi_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_header_struct *header = srv_mms_container_get_header();
    mmi_id cui_recipient_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_uc_supp.srv_msg.total_address_num = (header->to_num + header->cc_num + header->bcc_num);
    if (menu_id == MENU_ID_UMMS_ADD_ADDRESS)
    {
        g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_ADD_NUMBER;
        if (g_srv_mms_uc_supp.srv_msg.total_address_num >= SRV_MMS_UC_MAX_ADDRESS_NUM)
        {
            /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_UMMS_UC_RECIPIENT_NUMBER_EXCEED_ID)), MMI_EVENT_ERROR, NULL); */
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_UC_RECIPIENT_NUMBER_EXCEED_ID),
                MMI_EVENT_ERROR);
            mmi_umms_app_if_show_display_popup_screen();
            return;
        }
    }
    memset(g_srv_mms_uc_supp.srv_msg.addr, 0, (SRV_MMS_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
    if (menu_id == MENU_ID_UMMS_EDIT_ADDRESS)
    {
        U16 addr_index;
        mma_mms_addr_list_struct *highlight_addr = NULL;

        g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_EDIT_NUMBER;

        /* here find the number to be edit. suppose it is addr */
        addr_index = mmi_umms_app_ui_plug_in_get_hilite_item(SCR_ID_UMMS_ADD_RECIPIENT);
        highlight_addr = srv_mms_get_address_from_index(addr_index, g_srv_mms_uc_supp.srv_msg.curr_addr_type);

        if (highlight_addr->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_EDIT_NUMBER;
            mmi_asc_n_to_ucs2(
                (CHAR*)g_srv_mms_uc_supp.srv_msg.addr,
                (S8*) highlight_addr->address,
                SRV_MMS_UC_MAX_PHONE_NUMBER_LEN);
        }
        else if (highlight_addr->addr_type == MMA_ADDR_TYPE_EMAIL)
        {
            g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_EDIT_EMAIL;
			mmi_asc_n_to_ucs2(
                (CHAR*)g_srv_mms_uc_supp.srv_msg.addr,
                (S8*) highlight_addr->address,
                SRV_MMS_MAX_EMAIL_LEN);
        }
    }
    mmi_imm_set_app_desired_input_mode(IMM_INPUT_MODE_PHONE_NUMBER);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    if ((cui_recipient_gid = cui_fseditor_create(mmi_umms_dtmgr_get_group_id())) != NULL)
    {
        mmi_umms_app_dtmgr_set_common_cui_id(cui_recipient_gid);
        cui_fseditor_set_title(mmi_umms_app_dtmgr_get_common_cui_id(), STR_GLOBAL_ADDRESS, NULL);
        cui_fseditor_set_buffer(
            mmi_umms_app_dtmgr_get_common_cui_id(),
            (PU8) g_srv_mms_uc_supp.srv_msg.addr,
            (SRV_MMS_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH,
            SRV_MMS_UC_MAX_EMAIL_LEN);
        cui_fseditor_set_input_method(
            mmi_umms_app_dtmgr_get_common_cui_id(),
            IMM_INPUT_TYPE_USER_SPECIFIC,
            (mmi_imm_input_mode_enum*) mmi_umms_uc_app_get_recipient_editor_filters_for_input_mode(),
            NULL);
        cui_fseditor_set_characters_filter(
            mmi_umms_app_dtmgr_get_common_cui_id(),
            MMI_TRUE,
            (const UI_character_type*)mmi_imm_get_allowed_email_address_characters());
        cui_fseditor_set_parent_data(mmi_umms_app_dtmgr_get_common_cui_id(), MENU_ID_UMMS_ADD_ADDRESS);
        cui_fseditor_run(mmi_umms_app_dtmgr_get_common_cui_id());
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_edit_mms_text_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_edit_mms_text_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* getting the subject buffer for editor */
    mmi_id cui_content_editor_gid;
    mma_mms_description_struct *des = srv_mms_container_get_content();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* getting the subject buffer for editor */

    g_srv_mms_uc_supp.srv_msg.fseditor_buffer = (U16*) srv_mms_get_slide_txt_buffer();

    if (des->body->curr_slide->txt.object)
    {
        MMI_BOOL result;

        /* Following API opens/closes file Handle(s) */
        result = srv_mms_viewer_load_ucs2_txt_to_buffer(
                    (PU8) g_srv_mms_uc_supp.srv_msg.fseditor_buffer,
                    MMI_MMS_TXT_BUF_UCS2_SIZE,
                    &des->body->curr_slide->txt);

        if (result == MMI_FALSE)
        {
            srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_OK, 0);
            return;
        }
    }
    if ((cui_content_editor_gid = cui_fseditor_create(mmi_umms_dtmgr_get_group_id())) != NULL)
    {
        mmi_umms_app_dtmgr_set_common_cui_id(cui_content_editor_gid);
        /* set here the title [title string and title image] */
        cui_fseditor_set_title(mmi_umms_app_dtmgr_get_common_cui_id(), STR_GLOBAL_CONTENT, NULL);

        cui_fseditor_set_buffer(
            mmi_umms_app_dtmgr_get_common_cui_id(),
            (PU8) g_srv_mms_uc_supp.srv_msg.fseditor_buffer,
            (SRV_MMS_UC_MAX_CHAR_NUM_IN_ONE_SLIDE + 1) * ENCODING_LENGTH,
            SRV_MMS_UC_MAX_CHAR_NUM_IN_ONE_SLIDE);

        cui_fseditor_set_input_method(mmi_umms_app_dtmgr_get_common_cui_id(), IMM_INPUT_TYPE_SENTENCE, NULL, 0);
        cui_fseditor_set_parent_data(mmi_umms_app_dtmgr_get_common_cui_id(), MENU_ID_UMMS_EDIT_TEXT);
        cui_fseditor_run(mmi_umms_app_dtmgr_get_common_cui_id());
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_enter_recipient_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_uc_enter_recipient_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_srv_mms_uc_supp.srv_msg.addr) == 0)
    {
        /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_EMPTY)), MMI_EVENT_ERROR, NULL); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_EMPTY), MMI_EVENT_ERROR);
        mmi_umms_app_if_show_display_popup_screen();
        return MMI_FALSE;
    }
    /* check the validity of recipient for email first */
    if (srv_mms_uc_is_email_addr_valid((U8*) g_srv_mms_uc_supp.srv_msg.addr))
    {
        if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_NUMBER ||
            g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_EMAIL)
        {
            g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_EDIT_EMAIL;
        }
        else
        {
            g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_ADD_EMAIL;
        }
    }
    /* check the validity for the number */
    else if (srv_mms_uc_is_phone_number_valid((S8*) g_srv_mms_uc_supp.srv_msg.addr))
    {
        if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_NUMBER ||
            g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_EMAIL)
        {
            g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_EDIT_NUMBER;
        }
        else
        {
            g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_ADD_NUMBER;
        }
    }
    else
    {
        /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_INPUT)), MMI_EVENT_ERROR, NULL); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_INVALID_INPUT), MMI_EVENT_ERROR);
        mmi_umms_app_if_show_display_popup_screen();
        return MMI_FALSE;
    }
    return mmi_umms_uc_add_recipient_done();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_add_recipient_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_uc_add_recipient_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_description_struct *dst_header = srv_mms_container_get_content();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_uc_insert_sig_result_enum pass_sig_check = MMI_UC_INSERT_SIG_RESULT_PASS; */

    if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_ADD_NUMBER ||
        g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_ADD_EMAIL)
    {
        /* Check if the msg size exceeds the MMS limitation */
        U32 addr_size = mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar*)g_srv_mms_uc_supp.srv_msg.addr);
        MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

        if (srv_mms_check_if_exceed_MMS_size_limitation
            (NULL, addr_size + g_srv_mms_uc_supp.srv_msg.total_msg_size, &fail_in_restricted_size_check))
        {
            /* (fail_in_restricted_size_check) ? mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS) :
               mmi_uc_display_popup(SRV_UC_SIZE_EXCEEDS); */
            /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_FAILED_TO_SAVE)), MMI_EVENT_ERROR, NULL); */
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_UC_MSG_SIZE_EXCEED_ID),
                MMI_EVENT_ERROR);
            mmi_umms_app_if_show_display_popup_screen();

            return MMI_FALSE;
        }
        /* add the contact into the list finally */
        if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_ADD_NUMBER)
        {
            srv_mms_add_address_ext(
                dst_header->header,
                g_srv_mms_uc_supp.srv_msg.addr,
                MMA_ADDR_TYPE_PHONE_NUMBER,
                g_srv_mms_uc_supp.srv_msg.curr_addr_type,
                srv_mms_mem_mgr_viewer_asm_alloc_userdata,
                srv_mms_mem_mgr_viewer_asm_free_userdata,
                NULL);
            g_srv_mms_uc_supp.srv_msg.total_address_num++;
        }
        else
        {
            srv_mms_add_address_ext(
                dst_header->header,
                g_srv_mms_uc_supp.srv_msg.addr,
                MMA_ADDR_TYPE_EMAIL,
                g_srv_mms_uc_supp.srv_msg.curr_addr_type,
                srv_mms_mem_mgr_viewer_asm_alloc_userdata,
                srv_mms_mem_mgr_viewer_asm_free_userdata,
                NULL);
            g_srv_mms_uc_supp.srv_msg.total_address_num++;
        }

        mmi_umms_app_ui_plug_in_set_hilite_item(
            SCR_ID_UMMS_ADD_RECIPIENT,
            (mmi_umms_app_ui_plug_in_recipient_items_number() - 1));
    }

    else if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_NUMBER
		|| g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_EMAIL)
    {
        U16 addr_index;
        mma_mms_addr_list_struct *highlight_addr = NULL;

        addr_index = mmi_umms_app_ui_plug_in_get_hilite_item(SCR_ID_UMMS_ADD_RECIPIENT);
        highlight_addr = srv_mms_get_address_from_index(addr_index, g_srv_mms_uc_supp.srv_msg.curr_addr_type);

        if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_NUMBER
			|| g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_EMAIL)
        {
            U16 ori_addr_len = strlen((char*)highlight_addr->address);
			U8 ascii_addr[SRV_MMS_MAX_PHONE_NUMBER_LEN + 1];
            U8 *ori_ucs2_addr = srv_mms_mem_mgr_viewer_asm_alloc((ori_addr_len + 1) * ENCODING_LENGTH);

            U32 addr_size = mma_uc_calc_header_attribute_size(
                                MMA_HEADER_ADDRESS,
                                (const kal_wchar*)g_srv_mms_uc_supp.srv_msg.addr);
            U32 ori_addr_size = 0;
            MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

            memset(ori_ucs2_addr, 0, (ori_addr_len + 1) * ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) ori_ucs2_addr,
                ((ori_addr_len + 1) * ENCODING_LENGTH),
                (kal_uint8*) highlight_addr->address);
            ori_addr_size = mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar*)ori_ucs2_addr);
            srv_mms_mem_mgr_viewer_asm_free(ori_ucs2_addr);

            if (srv_mms_check_if_exceed_MMS_size_limitation
                (NULL, (addr_size + g_srv_mms_uc_supp.srv_msg.total_msg_size - ori_addr_size),
                 &fail_in_restricted_size_check))
            {
                /* (fail_in_restricted_size_check) ? mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS) :
                   mmi_uc_display_popup(SRV_UC_SIZE_EXCEEDS); */
                /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_ERROR, NULL); */
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_ID_UMMS_UC_MSG_SIZE_EXCEED_ID),
                    MMI_EVENT_ERROR);
                mmi_umms_app_if_show_display_popup_screen();
                return MMI_FALSE;
            }
            memset(ascii_addr, 0, sizeof(ascii_addr));
            mmi_ucs2_n_to_asc(
                (S8*) ascii_addr,
                (S8*) g_srv_mms_uc_supp.srv_msg.addr,
                SRV_MMS_MAX_PHONE_NUMBER_LEN * ENCODING_LENGTH);

            srv_mms_mem_mgr_viewer_asm_free(highlight_addr->address);
			highlight_addr->address = NULL ;
            highlight_addr->address = srv_mms_mem_mgr_viewer_asm_alloc(strlen((char*)ascii_addr) + 1);
            /* MMI_ASSERT(addr->addr); */

			memset(highlight_addr->address, 0, strlen((char*)ascii_addr)+1);
            memcpy(highlight_addr->address, ascii_addr, strlen((char*)ascii_addr));
            if(g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_NUMBER)
			{
            highlight_addr->addr_type = MMA_ADDR_TYPE_PHONE_NUMBER;
    }
    else if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_EDIT_EMAIL)
    {
        highlight_addr->addr_type = MMA_ADDR_TYPE_EMAIL;
			}
        mmi_umms_app_ui_plug_in_set_hilite_item(SCR_ID_UMMS_ADD_RECIPIENT, addr_index);
    }
    }
    srv_mms_update_msg_size();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_delete_addr_confirm_popup_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_umms_uc_delete_addr_confirm_popup_group_proc(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
            case MMI_ALERT_CNFM_YES:
            {
                //srv_uc_addr_struct *addr = mmi_uc_get_highlighted_addr();
                //srv_uc_delete_addr(g_uc_p->main.instance, addr);
                srv_mms_update_msg_size();
                /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_ID_UMMS_UC_REMOVED_ID)), MMI_EVENT_SUCCESS, NULL); */
                mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_UC_REMOVED_ID), MMI_EVENT_ERROR);
                mmi_umms_app_if_show_display_popup_screen();
            }
                break;
            case MMI_ALERT_CNFM_NO:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_entry_delete_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_entry_delete_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func) mmi_umms_uc_delete_addr_confirm_popup_group_proc;
    arg.parent_id = mmi_umms_dtmgr_get_group_id();
    mmi_confirm_display((WCHAR*) (get_string(STR_GLOBAL_DELETE)), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_input_method_and_done_go_back_to_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_input_method_and_done_go_back_to_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_subject_buffer[SRV_UM_MAX_SUBJECT_LEN * 3 + 3] = {0, };
    MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;
    mma_mms_header_struct *dest_header = srv_mms_container_get_header();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if subject is already present copy it into temp buffer */
    if (mmi_chset_utf8_strlen((kal_uint8 *)dest_header->subject.text) > 0)
    {
        memcpy(temp_subject_buffer, dest_header->subject.text, 3 * (SRV_UM_MAX_SUBJECT_LEN + 1));
    }
    /* if editor buffer has some content then copy it into subject buffer */
    if (g_srv_mms_uc_supp.srv_msg.fseditor_buffer)
    {
        if (!dest_header->subject.text)
        {
            dest_header->subject.text = (char*)srv_mms_mem_mgr_viewer_asm_alloc(3 * (SRV_UM_MAX_SUBJECT_LEN + 1));
            memset(dest_header->subject.text, 0, (3 * (SRV_UM_MAX_SUBJECT_LEN + 1)));
        }
        mmi_chset_ucs2_to_utf8_string(
            (U8*) dest_header->subject.text,
            (3 * (SRV_UM_MAX_SUBJECT_LEN + 1)),
            (U8*) g_srv_mms_uc_supp.srv_msg.fseditor_buffer);
        dest_header->subject.charset = MMA_CHARSET_UTF8;
    }

    if (g_srv_mms_uc_supp.srv_msg.msg_type == SRV_MMS_MSG_TYPE_MMS_PREFER &&
        (g_srv_mms_uc_supp.srv_msg.msg_state == SRV_MMS_STATE_FORWARD ||
         g_srv_mms_uc_supp.srv_msg.msg_state == SRV_MMS_STATE_SEND))
    {
        /*
         * TODO: mma_uc_calc_header_size api is srv_uc_msg_struct dependent [make it generic]
         * g_srv_mms_uc_supp.srv_msg.total_msg_size = mma_uc_calc_header_size(
         * g_mms_message_data,
         * MMA_MMS_TYPE_SMIL_MMS + g_srv_mms_uc_supp.srv_msg.msg_body_size;
         */
    }
    else
    {
        /*
         * same here make it generic
         * g_srv_mms_uc_supp.srv_msg.total_msg_size = mma_uc_calc_msg_size(g_mms_message_data, MMA_MMS_TYPE_SMIL_MMS);
         */
    }

    if (srv_mms_check_if_exceed_MMS_size_limitation
        (NULL, g_srv_mms_uc_supp.srv_msg.total_msg_size, &fail_in_restricted_size_check))
    {
        memcpy(dest_header->subject.text, temp_subject_buffer, sizeof(U8) * (SRV_UM_MAX_SUBJECT_LEN + 1));
        srv_mms_update_msg_size();
        /* (fail_in_restricted_size_check) ? mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS) :
           mmi_uc_display_popup(SRV_UC_SIZE_EXCEEDS); */
        /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_ERROR, NULL); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_UC_MSG_SIZE_EXCEED_ID), MMI_EVENT_ERROR);
        mmi_umms_app_if_show_display_popup_screen();
    }
    else
    {
        srv_mms_update_msg_size();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_entry_insert_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_entry_insert_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* temp code added to get the total_slide_num when edit msg */
    mma_mms_description_struct *des = srv_mms_container_get_content();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (des->body->slides)
    {
        while (des->body->slides->next)
        {
            des->body->slides = des->body->slides->next;
        }
        g_srv_mms_uc_supp.total_slide_num = des->body->slides->slide_num;

        while (des->body->slides->prev)
        {
            des->body->slides = des->body->slides->prev;
        }
    }
    /* temp code added to get the total_slide_num when edit msg */

    if (des->body->slide_no < SRV_MMS_UC_MAX_MMS_SLIDE_NUM)
    {
        U32 new_slide_size = 0;
        mma_mms_slide_struct *slide;

        /* mmi_uc_insert_sig_result_enum pass_sig_check = MMI_UC_INSERT_SIG_RESULT_PASS; */
        MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

#ifndef __MMI_MMS_NO_SMIL_SUPPORT__
        new_slide_size = mma_uc_calc_slide_smil_size(10 /* slide_timing */ );
#endif
        if (!srv_mms_check_if_exceed_MMS_size_limitation
            (NULL, new_slide_size + g_srv_mms_uc_supp.srv_msg.total_msg_size, &fail_in_restricted_size_check))
        {

            slide = srv_mms_insert_slide();
            des->body->curr_slide = slide;
            srv_mms_update_msg_size();
        }

        else
        {
            //(fail_in_restricted_size_check) ? mmi_uc_display_popup(SRV_UC_CREATION_MODE_SIZE_EXCEEDS) :
            // mmi_uc_display_popup(SRV_UC_SIZE_EXCEEDS);
            //mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_ERROR, NULL);
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_UC_MSG_SIZE_EXCEED_ID),
                MMI_EVENT_ERROR);
            mmi_umms_app_if_show_display_popup_screen();
            return;
        }
    }
    else
    {
        /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_ERROR, NULL); */
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_ERROR), MMI_EVENT_ERROR);
        mmi_umms_app_if_show_display_popup_screen();
    }
    /* srv_mms_insert_slide(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_process_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_process_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_remove_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_remove_object(mmi_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_description_struct *des = srv_mms_container_get_content();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
        case MENU_ID_UMMS_DELETE_IMAGE:
        {
            if (des->body->curr_slide->img.object->reference_count > 1)
            {
                des->body->curr_slide->img.object->reference_count--;
            }
            else
            {
                srv_mms_delete_object_from_list(des->body->curr_slide->img.object);
            }
            memset(&(des->body->curr_slide->img), 0, sizeof(mma_mms_slide_object_struct));
            srv_mms_reset_layout_if_needed();

        }
            break;
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
        case MENU_ID_UMMS_DELETE_SOUND:
        {
            if (des->body->curr_slide->aud.object->reference_count > 1)
            {
                des->body->curr_slide->aud.object->reference_count--;
            }
            else
            {
                srv_mms_delete_object_from_list(des->body->curr_slide->aud.object);
            }
            memset(&(des->body->curr_slide->aud), 0, sizeof(mma_mms_slide_object_struct));
            break;
        }
#endif
        case MENU_ID_UMMS_DELETE_VIDEO:
        {
            if (des->body->curr_slide->vid.object->reference_count > 1)
            {
                des->body->curr_slide->vid.object->reference_count--;
            }
            else
            {
                srv_mms_delete_object_from_list(des->body->curr_slide->vid.object);
            }
            memset(&(des->body->curr_slide->vid), 0, sizeof(mma_mms_slide_object_struct));
            srv_mms_reset_layout_if_needed();
            break;
        }

        default:
        {
            break;
        }

    }
    srv_mms_update_msg_size();
    /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_REMOVED)), MMI_EVENT_EXPLICITLY_DELETED, NULL); */
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_REMOVED), MMI_EVENT_ERROR);
    mmi_umms_app_if_show_display_popup_screen();
    if (g_srv_mms_uc_supp.srv_msg.msg_edit_mode == SRV_MMS_FORWARD_WITHOUT_EDIT_MODE)
    {
        g_srv_mms_uc_supp.srv_msg.msg_edit_mode = SRV_MMS_FORWARD_WITH_EDIT_MODE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_add_selected_address_from_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [?]     
 *  number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_umms_uc_sd_card_plug_out_hdlr_cb (mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
	U8 drive_counter = 0;
	srv_fmgr_notification_dev_plug_event_struct *plug_in_info;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(param->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
			
			plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)param;

			for (i = 0; i < plug_in_info->count; i++)
			{
				if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
				{
					drive_counter++;
				}
			}
			if(drive_counter)
			{
				srv_mms_composer_sd_plug_out_hdlr();
			}
			
			break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_add_selected_address_from_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [?]     
 *  number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_add_selected_address_from_phb(S8 *name, S8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 addr_len = mmi_ucs2strlen(number);
    U16 i = 0;
    U16 *addr = (U16*) number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_ADD_NUMBER;
    for (; i < addr_len; i++)
    {
        if (mmi_ucs2ncmp((S8*) & addr[i], (S8*) L"@", 1) == 0)
        {
            g_srv_mms_uc_supp.recipient_state = MMI_MMS_DONE_STATE_ADD_EMAIL;
            break;
        }
    }

    if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_ADD_NUMBER)
    {
        if (!srv_mms_uc_is_phone_number_valid(number)
            || (mmi_ucs2strlen((PS8) number) > (SRV_MMS_UC_MAX_PHONE_NUMBER_LEN)))
        {
            /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_NUMBER)), MMI_EVENT_ERROR, NULL); */
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_INVALID_NUMBER), MMI_EVENT_ERROR);
            mmi_umms_app_if_show_display_popup_screen();
            return;
        }
    }
    else if (g_srv_mms_uc_supp.recipient_state == MMI_MMS_DONE_STATE_ADD_EMAIL)
    {
        if (!srv_mms_uc_is_email_addr_valid((U8*) number) ||
            (mmi_ucs2strlen((PS8) number) > (SRV_MMS_UC_MAX_EMAIL_LEN)))
        {
            /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_EMAIL_ADDRESS)), MMI_EVENT_ERROR, NULL); */
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_GLOBAL_INVALID_EMAIL_ADDRESS),
                MMI_EVENT_ERROR);
            mmi_umms_app_if_show_display_popup_screen();
            return;
        }
    }

    memset(g_srv_mms_uc_supp.srv_msg.addr, 0, (SRV_MMS_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
    if (number)
    {
        mmi_ucs2ncpy((S8*) g_srv_mms_uc_supp.srv_msg.addr, (PS8) number, SRV_MMS_UC_MAX_EMAIL_LEN);
    }
    mmi_umms_uc_enter_recipient_done();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_process_entry_delete_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_process_entry_delete_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_entry_delete_slide();
    //mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);
    //mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_DONE),MMI_EVENT_SUCCESS);
    //mmi_umms_app_if_show_display_popup_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_event_handler_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_uc_event_handler_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    mmi_id menu_id;
	mma_mms_header_struct *header = NULL;
	U16 string_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *fmgr_evt = (cui_file_selector_result_event_struct*) evt;
            srv_fmgr_fileinfo_struct info;
            WCHAR *path_buffer = NULL;
            mma_insert_check_struct check_result;
            FS_HANDLE handle;

            if (fmgr_evt->result > 0)
            {
                path_buffer = (U16*) srv_mms_mem_mgr_viewer_asm_alloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
                cui_file_selector_get_selected_filepath(
                    mmi_umms_app_dtmgr_get_common_cui_id(),
                    &info,
                    path_buffer,
                    (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
                if ((handle = FS_GetAttributes((PU16) path_buffer)) < 0)
                {
                    /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(handle))), MMI_EVENT_FAILURE, NULL); */
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(srv_fmgr_fs_error_get_string(handle)),
                        MMI_EVENT_FAILURE);
                    mmi_umms_app_if_show_display_popup_screen();
                    return MMI_RET_OK;
                }

				string_id = mmi_fmgr_util_file_limit_check2(FMGR_LIMIT_MMS_CATEGORY, (CHAR*)path_buffer, NULL);
				if(string_id)
				{
					mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(string_id), MMI_EVENT_FAILURE);
					mmi_umms_app_if_show_display_popup_screen();
					srv_mms_mem_mgr_viewer_asm_free(path_buffer);
					break;
				}

                check_result = srv_mms_select_object_response_from_fm_to_insert((PU16) path_buffer, 0);
                if (!check_result.result)
                {
                    mmi_umms_uc_show_error_and_exit(&check_result);
                }
				
                else
                {
                    cui_file_selector_close(mmi_umms_app_dtmgr_get_common_cui_id());
                    srv_mms_mem_mgr_viewer_asm_free(path_buffer);
                }
            }
            else
            {
                cui_file_selector_close(mmi_umms_app_dtmgr_get_common_cui_id());
            }

            break;
        }

        case EVT_ID_PHB_SELECT_CONTACT:
        {
            cui_phb_select_contact_result_struct *select_contact_result = (cui_phb_select_contact_result_struct*) evt;

            mmi_umms_uc_add_selected_address_from_phb(
                (S8*) select_contact_result->name,
                (S8*) select_contact_result->select_data);
            cui_phb_list_select_contact_close(mmi_umms_app_dtmgr_get_common_cui_id());
            memset(g_srv_mms_uc_supp.srv_msg.addr, 0, (SRV_MMS_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            break;
        }

        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
        {
            cui_phb_list_select_contact_close(mmi_umms_app_dtmgr_get_common_cui_id());
            memset(g_srv_mms_uc_supp.srv_msg.addr, 0, (SRV_MMS_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            break;
        }

        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            menu_id = cui_fseditor_get_parent_data(mmi_umms_app_dtmgr_get_common_cui_id());
            switch (menu_id)
            {
                case MENU_ID_UMMS_EDIT_SUBJECT:
                {
                    cui_fseditor_get_text(
                        mmi_umms_app_dtmgr_get_common_cui_id(),
                        (WCHAR*) g_srv_mms_uc_supp.srv_msg.fseditor_buffer,
                        (SRV_MMS_UC_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);
                    cui_fseditor_close(mmi_umms_app_dtmgr_get_common_cui_id());
                    mmi_umms_uc_input_method_and_done_go_back_to_option();
                    srv_mms_mem_mgr_viewer_asm_free(g_srv_mms_uc_supp.srv_msg.fseditor_buffer);
                    g_srv_mms_uc_supp.srv_msg.fseditor_buffer = NULL;

                    break;
                }
                case MENU_ID_UMMS_EDIT_TEXT:
                {
                    S32 char_len = 0;
                    srv_mms_uc_error_type_enum result = SRV_MMS_UC_NO_ERROR;

					
					U32 utf8_buffer_size;
					U8 *utf8_buffer ;
					U32 utf8_len = 0;

                    cui_fseditor_get_text(
                        mmi_umms_app_dtmgr_get_common_cui_id(),
                        (WCHAR*) g_srv_mms_uc_supp.srv_msg.fseditor_buffer,
                        (SRV_MMS_UC_MAX_CHAR_NUM_IN_ONE_SLIDE + 1) * ENCODING_LENGTH);
                    char_len = cui_fseditor_get_text_len(mmi_umms_app_dtmgr_get_common_cui_id());

					if(char_len)
					{
						/*utf8_buffer_size = (char_len + 1) * ENCODING_LENGTH;
						utf8_buffer = (U8*) srv_mms_mem_mgr_viewer_asm_alloc(utf8_buffer_size);
						memset(utf8_buffer, 0, utf8_buffer_size);
						utf8_len = mmi_chset_ucs2_to_utf8_string(utf8_buffer, utf8_buffer_size, (U8*)g_srv_mms_uc_supp.srv_msg.fseditor_buffer);
						
						srv_mms_mem_mgr_viewer_asm_free(utf8_buffer);*/
						utf8_len = (char_len + 1) * ENCODING_LENGTH;
						result = srv_mms_hanlde_text_buffer_of_current_slide(utf8_len);
					}
                    if (result == SRV_MMS_UC_INVALID_HANDLE_ERROR)
                    {

                        /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_ERROR, NULL); */
                        mmi_umms_app_dtmgr_set_popup_screen_para(
                            (U16*) GetString(STR_GLOBAL_ERROR),
                            MMI_EVENT_FAILURE);
                        mmi_umms_app_if_show_display_popup_screen();
                        cui_fseditor_close(mmi_umms_app_dtmgr_get_common_cui_id());
                        break;
                    }
                    else if (result == SRV_MMS_UC_MESSAGE_SIZE_EXCEED_ERROR)
                    {

                        /* mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_ERROR, NULL); */
                        mmi_umms_app_dtmgr_set_popup_screen_para(
                            (U16*) GetString(STR_ID_UMMS_UC_MSG_SIZE_EXCEED_ID),
                            MMI_EVENT_FAILURE);
                        mmi_umms_app_if_show_display_popup_screen();
                        break;
                    }
                    else if (result == SRV_MMS_UC_NO_ERROR)
                    {
                        cui_fseditor_close(mmi_umms_app_dtmgr_get_common_cui_id());
                    }
                    break;
                }
                    /* case MENU_ID_UMMS_ADD_RECIPIENT_TO: */
                case MENU_ID_UMMS_ADD_ADDRESS:
                {
                    MMI_BOOL result = MMI_FALSE;

                    cui_fseditor_get_text(
                        mmi_umms_app_dtmgr_get_common_cui_id(),
                        (WCHAR*) g_srv_mms_uc_supp.srv_msg.addr,
                        (SRV_MMS_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
                    result = mmi_umms_uc_enter_recipient_done();
                    if (result == MMI_TRUE)
                    {
                        cui_fseditor_close(mmi_umms_app_dtmgr_get_common_cui_id());
                    }
                    memset(g_srv_mms_uc_supp.srv_msg.addr, 0, (SRV_MMS_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
                    break;
                }
                default:
                    break;
            }
            break;
        case EVT_ID_CUI_FSEDITOR_ABORT:
            memset(g_srv_mms_uc_supp.srv_msg.addr, 0, (SRV_MMS_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            cui_fseditor_close(mmi_umms_app_dtmgr_get_common_cui_id());
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_evt->highlighted_menu_id)
            {
                case MENU_ID_UMMS_EDIT_TEXT:
                    mmi_umms_uc_edit_mms_text_content();
                    break;
                case MENU_ID_UMMS_INSERT_SLIDE:
                    mmi_umms_uc_entry_insert_slide();
                    cui_menu_close(menu_evt->sender_id);
                    break;
                case MENU_ID_UMMS_INSERT_IMAGE:
                case MENU_ID_UMMS_INSERT_VIDEO:
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
                case MENU_ID_UMMS_INSERT_SOUND:
#endif
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
                case MENU_ID_UMMS_INSERT_ATTACHMENT:
#endif
                    mmi_umms_uc_select_fmgr_object(menu_evt->highlighted_menu_id);
                    break;
                case MENU_ID_UMMS_DELETE_SLIDE:
                    mmi_umms_uc_process_entry_delete_slide();
                    cui_menu_close(menu_evt->sender_id);
                    break;
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
                case MENU_ID_UMMS_DELETE_SOUND:
                    mmi_umms_uc_remove_object(MENU_ID_UMMS_DELETE_SOUND);
                    break;
#endif
                case MENU_ID_UMMS_DELETE_IMAGE:
                    mmi_umms_uc_remove_object(MENU_ID_UMMS_DELETE_IMAGE);
                    break;
                case MENU_ID_UMMS_DELETE_VIDEO:
                    mmi_umms_uc_remove_object(MENU_ID_UMMS_DELETE_VIDEO);
                    break;
                case MENU_ID_UMMS_EDIT_SUBJECT:
                    mmi_umms_uc_launch_subject_editor();
                    break;
                case MENU_ID_UMMS_ADD_ADDRESS:
                    /* g_srv_mms_uc_supp.current_editor_action = MMS_EDITOR_ACTION_EDIT_RECIPIENT ; */
                    mmi_umms_uc_enter_recipient_manual(MENU_ID_UMMS_ADD_ADDRESS);
                    break;
                case MENU_ID_UMMS_EDIT_ADDRESS:
                    mmi_umms_uc_enter_recipient_manual(MENU_ID_UMMS_EDIT_ADDRESS);
                    break;
                case MENU_ID_UMMS_ADD_FROM_PHONEBOOK_MMS:
                    mmi_umms_uc_launch_phb_for_recipient();
                    break;
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
                case MENU_ID_UMMS_DELETE_ATTACHMENT:
                    mmi_umms_app_if_show_save_objects_attchement_list();
                    break;
#endif
                case MENU_ID_UMMS_OPTIONS_EDIT_MESSAGE:
                    mmi_umms_app_ui_plug_in_launch_slim(MMA_MODE_EDIT);
                    break;

                case MENU_ID_UMMS_COMPOSER_OPTIONS:
                    mmi_umms_app_if_show_composer_option();
                case MENU_ID_UMMS_ADD_RECIPIENT_TO:
                    mmi_umms_app_ui_plug_in_create_dynamic_scrn_data(menu_evt->highlighted_menu_id);
                    /* mmi_umms_app_dtmgr_set_add_to_recipient(TRUE); */
                    mmi_umms_app_if_show_recipient_list();
                    g_srv_mms_uc_supp.srv_msg.curr_addr_type = MMA_MMS_ADDRESS_GROUP_TYPE_TO;
                    break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                case MENU_ID_UMMS_ADD_RECIPIENT_CC:
                    mmi_umms_app_ui_plug_in_create_dynamic_scrn_data(menu_evt->highlighted_menu_id);
                    /* mmi_umms_app_dtmgr_set_add_cc_recipient(TRUE); */
                    mmi_umms_app_if_show_recipient_list();
                    g_srv_mms_uc_supp.srv_msg.curr_addr_type = MMA_MMS_ADDRESS_GROUP_TYPE_CC;
                    break;
                case MENU_ID_UMMS_ADD_RECIPIENT_BCC:
                    mmi_umms_app_ui_plug_in_create_dynamic_scrn_data(menu_evt->highlighted_menu_id);
                    /* mmi_umms_app_dtmgr_set_add_bcc_recipient(TRUE); */
                    mmi_umms_app_if_show_recipient_list();
                    g_srv_mms_uc_supp.srv_msg.curr_addr_type = MMA_MMS_ADDRESS_GROUP_TYPE_BCC;
                    break;
#endif
                case MENU_ID_UMMS_SAVE_TO_DRAFT:
                    mmi_umms_app_ui_plug_in_handle_saving_sending_mms(MENU_ID_UMMS_SAVE_TO_DRAFT);
                    break;
            #if(MMI_MAX_SIM_NUM == 2)
                case MENU_ID_UMMS_FROM_SIM1:
					if(menu_evt->parent_menu_id == MENU_ID_UMMS_OPTIONS_SLIM_SEND)
					{
                    srv_mms_set_selected_sim_id(MMA_SIM_ID_SIM1);
                    mmi_umms_app_ui_plug_in_handle_saving_sending_mms(MENU_ID_UMMS_OPTIONS_SLIM_SEND);
					}
                    break;
                case MENU_ID_UMMS_FROM_SIM2:
					if(menu_evt->parent_menu_id == MENU_ID_UMMS_OPTIONS_SLIM_SEND)
					{
                    srv_mms_set_selected_sim_id(MMA_SIM_ID_SIM2);
                    mmi_umms_app_ui_plug_in_handle_saving_sending_mms(MENU_ID_UMMS_OPTIONS_SLIM_SEND);
					}
                    break;
            #endif /* (MMI_MAX_SIM_NUM == 2) */ 
                case MENU_ID_UMMS_OPTIONS_SLIM_SEND:
                    header = srv_mms_container_get_header();
                    if (header->to_num == 0 && header->cc_num == 0 && header->bcc_num == 0)
                    {
                        mmi_umms_app_dtmgr_set_popup_screen_para(
                            (U16*) GetString(STR_UMMS_NO_RECIPIENT),
                            MMI_EVENT_PROPLEM);

                        mmi_umms_app_if_show_display_popup_screen();
                        return MMI_RET_OK;
                    }
                  mmi_umms_slim_decide_before_send();

                    break;
                case MENU_ID_UMMS_REMOVE_ADDRESS:
                    /*
                     * part has to done when control comes from kuldeep
                     * temp=mmi_umms_app_dtmgr_get_hilite_item();
                     * mmi_umms_app_dtmgr_set_hilite_item(temp+1);
                     */
                    mmi_umms_app_dtmgr_set_confirm_screen_para(
                        STR_GLOBAL_YES,
                        IMG_GLOBAL_YES,
                        STR_GLOBAL_NO,
                        IMG_GLOBAL_NO,
                        (U16*) GetString(STR_UMMS_REMOVE_ASK_ID),
                        MMI_EVENT_QUERY,
                        MMI_FALSE,
                        MMI_FALSE,
                        mmi_umms_app_ui_plug_in_remove_address_from_list,      /* mmi_umms_entry_cancel_dwnld, */
                        mmi_frm_scrn_close_active_id,
                        NULL,
                        NULL);
                    mmi_umms_app_if_show_display_confirm_screen();

                    mmi_umms_app_dummy_entry_function();
                    break;

            }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_plug_in_launch_slim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_plug_in_launch_slim(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    U32 msg_id = data->msg_id;
    mmi_id parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();
    mma_result_enum result_mma = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* framework enhacement  changes */
    mmi_frm_group_create_ex(
                parent_id,
                GRP_ID_UMMS_DUMMY_GRP,
                mmi_umms_dummy_func,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
    srv_mms_container_reset_context();  /* First Entry Reset is Must */
    result_mma = srv_mms_container_set_message_id(msg_id);
    if (result_mma == MMA_RESULT_OK)
    {
        srv_mms_set_open_mode(mode);
    #ifdef __MMI_UMMS_UT__
        ASSERT(parent_id);
    #endif 
        if (parent_id == GRP_ID_INVALID)
        {
            parent_id = GRP_ID_ROOT;
        }
        mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);
        mmi_umms_app_if_show_option_screen_slim();
    }
    else
    {
        mmi_umms_app_if_show_error_pop_up(result_mma);
    }
	mmi_frm_group_close(GRP_ID_UMMS_DUMMY_GRP);
}

mmi_ret mmi_umms_dummy_func(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_plug_in_handle_saving_sending_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_plug_in_handle_saving_sending_mms(mmi_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    srv_mms_create_req_struct msg_req;
    mma_mms_header_struct *header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_id == MENU_ID_UMMS_OPTIONS_SLIM_SEND)
    {
        g_action_enum = MMI_UMMS_APP_UI_PLUG_IN_SEND;
        header = srv_mms_container_get_header();
        if (header->to_num == 0 && header->cc_num == 0 && header->bcc_num == 0)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_UMMS_NO_RECIPIENT), MMI_EVENT_PROPLEM);

            mmi_umms_app_if_show_display_popup_screen();
            return;
        }
    }
    else
        g_action_enum = MMI_UMMS_APP_UI_PLUG_IN_CREATE;
    memset(&msg_req, 0, sizeof(srv_mms_create_req_struct));
    msg_req.msg_id = 0;
    msg_req.app_id = MMA_APP_ID_VIEWER;
    msg_req.mode = MMA_MODE_EDIT;
	if(g_srv_mms_uc_supp.srv_msg.msg_state == SRV_MMS_STATE_EDIT_EXISTED_MSG &&  mma_get_box(data->msg_id) == MMA_FOLDER_DRAFT)
	{
		msg_req.msg_id = data->msg_id;
	}
    msg_req.user_data = (void*)&g_action_enum;
    srv_mms_container_change_struct_for_mma();
    msg_req.content_info = srv_mms_container_get_content();
    msg_req.call_back = (srv_mms_funcptr_type) mmi_umms_app_ui_plug_in_handle_saving_sending_mms_cb;
    srv_mms_create(&msg_req);
    if (menu_id != MENU_ID_UMMS_OPTIONS_SLIM_SEND)

    {
        mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_SAVING);
        mmi_umms_app_if_show_progress_screen();
        
    }
    else if (menu_id == MENU_ID_UMMS_OPTIONS_SLIM_SEND)

    {
        mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_PLEASE_WAIT);
        mmi_umms_app_if_show_progress_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_plug_in_handle_saving_sending_mms_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_plug_in_handle_saving_sending_mms_cb(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    srv_mms_send_req_struct req;
    U8 is_send_and_save = 0;
    U8 sim_selection_screen = 0;
    U8 *action_enum = (U8*) user_data;
    srv_mms_save_req_struct save_req;
U8 loc_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(action_enum);
    
     if((*action_enum) == MMI_UMMS_APP_UI_PLUG_IN_CREATE  || (*action_enum) == MMI_UMMS_APP_UI_PLUG_IN_SEND )
	  {
		   srv_mms_create_rsp_struct *rsp_mma = (srv_mms_create_rsp_struct*) rsp_data;
           
		   if(g_srv_mms_uc_supp.srv_msg.msg_state == SRV_MMS_STATE_EDIT_EXISTED_MSG &&  mma_get_box(data->msg_id) == MMA_FOLDER_DRAFT && rsp_mma->result == MMA_RESULT_OK)
			{
			    srv_mms_delete_msg(data->msg_id, &loc_result);
                srv_mms_um_refresh_ind(MMA_FOLDER_DRAFT);
			}
        if (rsp_mma->result != MMA_RESULT_OK)
        {
       if ((rsp_mma->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) && (rsp_mma->min_fs_space_required != 0))
        {
            mmi_umms_app_sh_display_working_space_popup(rsp_mma->min_fs_space_required);
		}
       else
				{   
					if(rsp_mma->result == MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_MEM_CARD)
					{
						g_umms_card_phone_str_id = STR_UMMS_MAX_MSG_CARD_CONFIRM;
							
					}
					else if(rsp_mma->result  == MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_USE_PHONE)
					{
						 g_umms_card_phone_str_id = STR_UMMS_CARD_NOT_PRESENT_CONFIRM ;
							
					}
					else if( rsp_mma->result ==  MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_PHONE_MEMORY)
					{
						 g_umms_card_phone_str_id = STR_UMMS_MAX_MSG_PHONE_CONFIRM ;
							
					}
					
					else
        {
            mmi_umms_app_if_show_error_pop_up(rsp_mma->result);
        }
					if(g_umms_card_phone_str_id)
					{
						 mmi_umms_app_dtmgr_set_confirm_screen_para(
								STR_GLOBAL_YES,
								IMG_GLOBAL_YES,
								STR_GLOBAL_NO,
								IMG_GLOBAL_NO,
								(U16*) GetString(g_umms_card_phone_str_id),
								MMI_EVENT_QUERY,
								MMI_FALSE,
								MMI_TRUE,
								mmi_umms_set_prefer_storage,
								mmi_umms_app_sh_mms_option_save_rsk_handler,
								NULL,
								NULL);
						 mmi_umms_app_if_show_display_confirm_screen();
						 mmi_umms_app_sh_delete_progress_screen();
						 return ;
            
        }

				 }
	          
				/*Layout Invert and dont close group. If error comes, let user close composer*/
				cui_menu_close(mmi_umms_app_dtmgr_get_menu_cui_id());
				mmi_umms_app_if_show_option_screen_slim();
				mmi_umms_app_sh_delete_progress_screen();
				srv_mms_container_invert_layput();
				return;
			}
	  }
    if ((*action_enum) == MMI_UMMS_APP_UI_PLUG_IN_CREATE)
    {
        srv_mms_create_rsp_struct *rsp_mma = (srv_mms_create_rsp_struct*) rsp_data;
        g_action_enum = MMI_UMMS_APP_UI_PLUG_IN_SAVE;
        save_req.box = MMA_FOLDER_DRAFT;
        save_req.user_data = (void*)&g_action_enum;
        save_req.no_of_msg = 1;
        save_req.msg_id[0] = rsp_mma->msg_id;
        save_req.app_id = MMA_APP_ID_VIEWER;
        save_req.call_back = (srv_mms_funcptr_type) mmi_umms_app_ui_plug_in_handle_saving_sending_mms_cb;
        srv_mms_save(&save_req);
    }
    else if ((*action_enum) == MMI_UMMS_APP_UI_PLUG_IN_SEND)
    {
        srv_mms_create_rsp_struct *rsp_mma = (srv_mms_create_rsp_struct*) rsp_data;

        if (rsp_mma->result != MMA_RESULT_OK)
        {
            mmi_umms_app_if_show_error_pop_up(rsp_mma->result);
            mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
            
            return;
        }
        is_send_and_save = srv_mms_sending_settings_send_and_save();
        
        #if(MMI_MAX_SIM_NUM >= 2)
        sim_selection_screen = srv_mms_get_selected_sim_id();
        #else
        sim_selection_screen=MMA_SIM_ID_SIM1;
         #endif
        if (is_send_and_save > 0)
            req.send_setting = SRV_MMS_SETTING_SAVE_AND_SEND;   /* SRV_MMS_SETTING_SAVE_AND_SEND; */
        else
            req.send_setting = SRV_MMS_SETTING_SEND_ONLY;
        req.msg_id = rsp_mma->msg_id;
        req.is_rr = (MMI_BOOL)srv_mms_sending_settings_read_report();
        req.storage_type = rsp_mma->storage;
        req.sim_id = sim_selection_screen;
        srv_mms_send(&req);
        mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
    }

    else if (*action_enum == MMI_UMMS_APP_UI_PLUG_IN_SAVE)
    {
        srv_mms_save_rsp_struct *save_rsp = (srv_mms_save_rsp_struct*) rsp_data;

        
        if (save_rsp->result[0] != MMA_RESULT_OK)
        {
            
            mmi_umms_app_if_show_error_pop_up(save_rsp->result[0]);
            mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
            return;
        }
        else
        {
            
            srv_mms_msg_update_count_and_status_icon();
            mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        }

    }
}

void mmi_umms_set_prefer_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_prefer_storage_enum mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_umms_card_phone_str_id == STR_UMMS_CARD_NOT_PRESENT_CONFIRM ||
        g_umms_card_phone_str_id == STR_UMMS_MAX_MSG_CARD_CONFIRM)
    {
        mode = E_PREFER_STORAGE_MODE_PHONE;
    }
    else
    {
        mode = E_PREFER_STORAGE_MODE_CARD;
    }
    g_umms_card_phone_str_id = 0;
    srv_mms_set_prefered_storage((U8) mode, MMI_TRUE);
	if( g_action_enum != MMI_UMMS_APP_UI_PLUG_IN_SEND)
	{
      mmi_umms_app_ui_plug_in_handle_saving_sending_mms(MENU_ID_UMMS_SAVE_TO_DRAFT);
    }
   else
    {
      mmi_umms_app_ui_plug_in_handle_saving_sending_mms(MENU_ID_UMMS_OPTIONS_SLIM_SEND);
	}
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_entry_write_msg_with_content
 * DESCRIPTION
 *  Entry unified composer with content
 * PARAMETERS
 *  type        [IN]        
 *  data        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_entry_write_msg_with_content(srv_mms_state_enum type, mmi_umms_uc_entry_write_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 addr_num = 0;
    mma_mms_addr_list_struct *addr = data->addr;
    mma_mms_object_struct *object;
    U8 *mmi_uc_text_path = NULL;
    S32 result;
	
    mmi_id group_id = 0;
    kal_uint32 current_tick_count;
    kal_uint32 tick_count_at_start;
    kal_uint32 time_gap;
    PU8 txt_buffer = NULL;
    mma_mms_description_body_struct *body;
    mma_mms_description_struct *des = srv_mms_container_get_content();
    MMI_UMMS_ERROR asm_error = MMI_UMMS_FALSE;
    srv_mms_xml_parse_req_struct req = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
    srv_mms_container_reset_context();  /* First Time Reset */
    mmi_umms_init_pools();

	if(mmi_mms_get_uc_start_context())
	{
		//Do nothing -- Rediredted from ASM MEM FREE success callback.
	}
	else
	{
		mmi_mms_make_uc_start_context(data);
	}

    asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX);
    if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
        /* Reset Data and Exit */
        //srv_mms_container_reset_context();
        return;
    }
    /* This will initialize Overall context with dummy values */
    /* TO provide data addresses and memory to app */
    srv_mms_container_dummy_initializer();
    des = srv_mms_container_get_content();
    kal_get_time(&tick_count_at_start);
    body = des->body;
#if defined(__MMI_MMS_STANDALONE_COMPOSER__)
    if (data->info_type == SRV_MMS_UC_INFO_TYPE_SMS)
    {
        MMI_ASSERT(0);
        return;
    }
#endif /* defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 

    if (!(srv_mms_ready()) || mmi_umms_app_if_is_viewer_in_history())
    {
        mmi_popup_display((WCHAR*) ((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_EVENT_FAILURE, NULL);
        if (data->callback != NULL)
        {
            data->callback((void*)data->callback_para);
        }
        if (!mmi_umms_app_if_is_viewer_in_history())
        {
            mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
            mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
        }
        return;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode() && mma_is_storage_exported_to_pc())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) SRV_MMS_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            if (data->callback != NULL)
            {
                data->callback((void*)data->callback_para);
            }
            mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
            mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    /* if caller only give one phone number, and the number exceed its max digit limitaton, popup here */
    /* if there are many addresses, will continue, but the number which exceed number digit limitation will not be added */
    if (data->get_address_callback)
    {
        // Skip here do operation later */
        /* Addr should be NULL if there is callback register for getting input. */
        MMI_ASSERT(data->addr == NULL);
    }
    else
    {
        if (data->addr_num == 1)
        {
            U16 string_id = mmi_umms_uc_entry_validation_checks_for_recipient(data->addr);

            if (string_id != STR_GLOBAL_OK)
            {
                mmi_popup_display((WCHAR*) ((UI_string_type) GetString(string_id)), MMI_EVENT_ERROR, NULL);
                if (data->callback != NULL)
                {
                    data->callback((void*)data->callback_para);
                }
                mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
                mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
                return;
            }
        }
    }
    

    /* Is this code is necessary?? */
    /*
     * if (mmi_frm_group_get_active_id() == mmi_umms_dtmgr_get_group_id()
     * &&  mmi_umms_dtmgr_get_group_id() == GRP_ID_UMMS_LIST_OPTION_SLIM)
     * {
     * group_id = mmi_umms_dtmgr_get_group_id();
     * mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
     * }
     * else 
     * {
     * mmi_frm_group_close (mmi_umms_dtmgr_get_group_id());
     * mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
     * }
     */
    result = srv_mms_uc_check_uc_folder();

    if (result < 0)
    {
        mmi_popup_display(
            (WCHAR*) ((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))),
            MMI_EVENT_FAILURE,
            NULL);
        if (data->callback != NULL)
        {
            data->callback((void*)data->callback_para);
        }
        mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        mmi_frm_group_close(group_id);
        group_id = GRP_ID_INVALID;
        mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
        return;
    }
    g_srv_mms_uc_supp.srv_msg.msg_state = type;
    /* g_uc_p->send_info.highlight_sim_id = srv_uc_convert_sim_id(data->sim_id); */

    if (type != SRV_MMS_STATE_WRITE_NEW_MSG)
    {
        /* impossible case */
    }

    for (; addr_num < data->addr_num; addr_num++)
    {
        mma_mms_addr_list_struct *addr_node = NULL;

        if (data->get_address_callback)
        {
            kal_int8 *temp_address_string = NULL;
            S32 str_length = 0;
            U16 address_type = 0;

            MMI_ASSERT(addr == NULL);
            addr_node = (mma_mms_addr_list_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_addr_list_struct));
            memset(addr_node, 0, sizeof(mma_mms_addr_list_struct));
            temp_address_string = data->get_address_callback((kal_uint16) addr_num, &address_type);
            str_length = mmi_ucs2strlen((S8*) temp_address_string);
            addr_node->address = srv_mms_mem_mgr_app_adm_alloc((str_length + 1) * ENCODING_LENGTH);
            memset(addr_node->address, 0, (str_length + 1) * ENCODING_LENGTH);
            memcpy(addr_node->address, temp_address_string, (str_length + 1) * ENCODING_LENGTH);
            addr_node->addr_type =
                (address_type == MMI_PHB_ADDRESS_TYPE_NUMBER) ? MMA_ADDR_TYPE_PHONE_NUMBER : MMA_ADDR_TYPE_EMAIL;
            addr_node->group = MMA_MMS_ADDRESS_GROUP_TYPE_TO;
            addr = addr_node;
        }

        MMI_ASSERT(addr);
        /* because pbh has valid number +(40 digit), but current UC only handle 40 digits or +(39 digits)
           so if the total digit > 40, will not allow user to add, because intercept number is meaningless */
        if (data->addr_num == 1)
        {
            U16 local_flag = mmi_umms_uc_entry_validation_checks_for_recipient(addr);

            if (local_flag != STR_GLOBAL_OK)
            {
                mmi_popup_display((WCHAR*) ((UI_string_type) GetString(local_flag)), MMI_EVENT_ERROR, NULL);
                if (addr_node)
                {
                    srv_mms_mem_mgr_app_adm_free(addr_node->address);
                    srv_mms_mem_mgr_app_adm_free(addr_node);
                    addr_node = NULL;
                }
                if (data->callback != NULL)
                {
                    data->callback((void*)data->callback_para);
                }
                mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
                mmi_frm_group_close(group_id);
                group_id = GRP_ID_INVALID;
                mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
                return;
            }
        }
        if (mmi_umms_uc_entry_validation_checks_for_recipient(addr) != STR_GLOBAL_OK)
        {
            /* will not added without showing popup */
        }
        else
        {

            srv_mms_add_address_ext(
                des->header,
                (U8*)addr->address,
                (mma_addr_type_enum)addr->addr_type,
                (mma_mms_address_group_type_enum)addr->group,
                srv_mms_mem_mgr_viewer_asm_alloc_userdata,
                srv_mms_mem_mgr_viewer_asm_free_userdata,
                NULL);
            g_srv_mms_uc_supp.srv_msg.total_address_num++;
        }
        if ((des->header->header->to_num) >= SRV_MMS_UC_MAX_ADDRESS_NUM)
        {
            /* the recipient limitation is SRV_MMS_UC_MAX_ADDRESS_NUM */
            break;
        }
        addr = addr->next;
        if (addr_node)
        {
            srv_mms_mem_mgr_app_adm_free(addr_node->address);
            srv_mms_mem_mgr_app_adm_free(addr_node);
            addr_node = NULL;
        }
    }

    des->body->curr_slide = srv_mms_insert_slide();
    des->body->bgColor = mma_get_default_smil_bg_color() ;
    memset(des->header->header->subject.text, 0, mmi_chset_utf8_strlen((kal_uint8*)des->header->header->subject.text));
    if (mmi_ucs2strlen((S8*) data->subject))
    {
        mmi_chset_ucs2_to_utf8_string(
            (U8*) des->header->header->subject.text,
            sizeof(U16) * (SRV_MMS_UC_MAX_SUBJECT_ARRAY_LEN + 1),
            (U8*) data->subject);
    }

    /* text file */
    if (data->text_num)
    {
        {
            U32 buffer_size = 0;
            U8 *buffer = NULL;
            U32 buffer_len = 0;
            /* Discard the exceeding part */
			 
		    txt_buffer = srv_mms_mem_mgr_viewer_asm_alloc(SRV_MMS_TXT_COMPOSE_BUF_UCS2_SIZE);
			memset(txt_buffer, 0, SRV_MMS_TXT_COMPOSE_BUF_UCS2_SIZE);
			buffer_size = (data->text_num + 1) * ENCODING_LENGTH;
			buffer = srv_mms_mem_mgr_viewer_asm_alloc(buffer_size);
			memset(buffer, 0, buffer_size);
			srv_sms_remove_escape_char(
                (S8*) buffer,
                (S8*) data->text_buffer,
                (U16) data->text_num);
            buffer_len = mmi_ucs2strlen((S8*) buffer);

            if (data->text_num > SRV_MMS_UC_MAX_CHAR_NUM_IN_ONE_SLIDE)
            {
                data->text_num = SRV_MMS_UC_MAX_CHAR_NUM_IN_ONE_SLIDE;
            }
            if (buffer_len <= (SRV_MMS_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1)
            {
                mmi_ucs2ncpy((S8*) txt_buffer, (S8*) data->text_buffer, buffer_len);
            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) txt_buffer,
                    (S8*) buffer,
                    (SRV_MMS_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1);
            }

            srv_mms_mem_mgr_viewer_asm_free(buffer);
        }

        mmi_uc_text_path = srv_mms_mem_mgr_app_adm_alloc(SRV_MMS_MAX_TEMP_FILE_LEN);
        memset(mmi_uc_text_path, 0, SRV_MMS_MAX_TEMP_FILE_LEN);
        SRV_MMS_MAKE_TEXT_FILE_PATH(mmi_uc_text_path, body->curr_slide->slide_num, 0);

			result = srv_mms_save_buffer_to_file(
                    mmi_uc_text_path,
                    txt_buffer,
                    (mmi_ucs2strlen((PS8) txt_buffer) + 1)* ENCODING_LENGTH);

         srv_mms_mem_mgr_viewer_asm_free(txt_buffer);
        if (result == FS_NO_ERROR)
        {
            if (body->curr_slide->txt.object == NULL)
            {
                object = srv_mms_insert_object((S8*) mmi_uc_text_path, MMA_INSERT_TEXT);
                srv_mms_insert_object_to_slide(object, body->curr_slide, MMA_INSERT_TEXT, 0);
            }
            else
            {
                body->curr_slide->txt.object->size = applib_get_file_size((kal_wchar*) mmi_uc_text_path);
            }
            body->curr_slide->txt.object->encoding = MMA_CHARSET_UTF8;  /* because the text's encode already UTF8 when mmi_uc_save_buffer_to_file to file *//* because the text's encode already UTF8 when mmi_uc_save_buffer_to_file to file */
        }
        else
        {
            mmi_popup_display(
                (WCHAR*) ((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)),
                MMI_EVENT_FAILURE,
                NULL);

            if (data->callback != NULL)
            {
                data->callback((void*)data->callback_para);
            }
            srv_mms_mem_mgr_app_adm_free(mmi_uc_text_path);
            mmi_uc_text_path = NULL;
            mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
            mmi_frm_group_close(group_id);
            mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
            return;
        }
        srv_mms_mem_mgr_app_adm_free(mmi_uc_text_path);
        mmi_uc_text_path = NULL;
    }

    /* srv_uc_update_msg_size(g_uc_p->main.instance);Kuldeep */

    if (data->info_type == SRV_MMS_UC_INFO_TYPE_SMS)
    {
        MMI_ASSERT(data->file_path == NULL);
    }

    if (data->file_path)
    {
        U32 flie_path_len = mmi_ucs2strlen((S8*) data->file_path);

        if (g_srv_mms_uc_supp.file_path)
        {
            srv_mms_mem_mgr_app_adm_free(g_srv_mms_uc_supp.file_path);
        }

        g_srv_mms_uc_supp.file_path = srv_mms_mem_mgr_app_adm_alloc((flie_path_len + 1) * ENCODING_LENGTH);

        MMI_ASSERT(g_srv_mms_uc_supp.file_path);

        mmi_ucs2ncpy((S8*) g_srv_mms_uc_supp.file_path, (S8*) data->file_path, flie_path_len);
    }
    g_srv_mms_uc_supp.srv_msg.msg_type = SRV_MMS_MSG_TYPE_MMS_PREFER;
    srv_mms_process_data_init(des, &req);
    mmi_umms_uc_process_entry_write_msg(MMA_MODE_EDIT);
	 if(g_srv_mms_uc_supp.file_path)
	  {
         srv_mms_mem_mgr_app_adm_free(g_srv_mms_uc_supp.file_path);
         g_srv_mms_uc_supp.file_path = NULL;
	  }
    kal_get_time(&current_tick_count);
    time_gap = (current_tick_count) - (tick_count_at_start);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_EXIT_ENTRY_WRITE_MSG_WITH_CONTENT, time_gap);

	mmi_mms_reset_uc_start_context();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_process_entry_write_msg
 * DESCRIPTION
 *  Process function of entering unified composer
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_process_entry_write_msg(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    mma_insert_check_struct result_check;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_mms_uc_check_uc_folder();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_PROCESS_ENTRY_WRITE_MSG_P1, result);
    if (result < 0)
    {
        mmi_popup_display(
            (WCHAR*) ((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))),
            MMI_EVENT_FAILURE,
            NULL);
        mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        return;
    }
    /* send get setting request to MMS */
    result_check = srv_mms_get_mms_setting();
    if (result_check.detail_result == MMA_RESULT_OK)
    {
        if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
        {
            mmi_id parent_id = GRP_ID_ROOT;

            mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);
            mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_COMM_SLIM_OPTIONS);
            /* framework enhacement  changes */
            mmi_frm_group_create_ex(
                mmi_umms_app_dtmgr_get_parent_grp_id(),
                mmi_umms_dtmgr_get_group_id(),
                mmi_umms_proc_func,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
            mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
        }
        srv_mms_set_open_mode(mode);
        mmi_umms_app_ui_plug_in_option_slim_menu_pre_func(SCR_ID_UMMS_MMS_OPTION_SLIM);
        mmi_umms_app_ui_draw_cui_static_list_draw_func(SCR_ID_UMMS_MMS_OPTION_SLIM);
        mmi_umms_app_ui_plug_in_option_slim_menu_post_func(SCR_ID_UMMS_MMS_OPTION_SLIM);
    }
    else
    {
        mmi_umms_uc_show_error_and_exit(&result_check);
		srv_mms_container_reset_context();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_uc_show_error_and_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  check_result        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_uc_show_error_and_exit(mma_insert_check_struct *check_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__
    if (check_result->detail_result == MMA_RESULT_FAIL_WAP_CONN_MAX_MSG_SIZE_REACHED)
    {
        str_id = STR_ID_UMMS_UC_MSG_SIZE_EXCEED_ID;
    }
    else
#endif /* __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__ */ 
    if ((check_result->oversize) && (check_result->detail_result == MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED))
    {
        str_id = STR_ID_UMMS_UC_MSG_SIZE_EXCEED_ID;
    }
    else if ((check_result->oversize) &&
             (check_result->detail_result == MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED))
    {
        str_id = STR_ID_UMMS_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID;
    }
    else if (check_result->creation_mode_violate)
    {
        str_id = STR_ID_UMMS_UC_PROHIBIT_BY_CREATION_MODE_ID;
    }
    else if (check_result->drm_type == MMA_DRM_FL_CD || check_result->drm_type == MMA_DRM_SD_NO_RIGHT)
    {
        str_id = STR_GLOBAL_DRM_PROHIBITED;
    }
    else if (check_result->detail_result == MMA_RESULT_FAIL_FILE_CORRUPTED)
    {
        str_id = STR_UMMS_FAILED_TO_ADD_MEDIA_ID;
    }
    else
    {
        mmi_umms_app_if_show_error_pop_up(check_result->detail_result);
    }
    if (str_id)
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(str_id), MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();
    }
}

/* this is dummy controller */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_dummy_controller
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_dummy_controller(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    srv_mms_app_result_enum error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (scr_id)
    {
        case SCR_ID_UMMS_MMS_VIEWER:
        {
            if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
            {
                mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_VIEW);
                /* frmaework enhancement  changes */
                mmi_frm_group_create_ex(
                    mmi_umms_app_dtmgr_get_parent_grp_id(),
                    mmi_umms_dtmgr_get_group_id(),
                    mmi_umms_proc_func,
                    NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);
                mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
            }
            error = mmi_umms_get_data(data->open_mode);
            if (error == MMI_UMMS_TRUE)
            {
                srv_mms_app_result_enum result;

                result = mmi_umms_app_ui_plug_in_viewer_pre_func(SCR_ID_UMMS_MMS_VIEWER);
                if (result == MMI_UMMS_TRUE)
                {
                    result = mmi_umms_app_ui_draw_viewer_screen(SCR_ID_UMMS_MMS_VIEWER);
                    if (result == MMI_UMMS_TRUE)
                    {
                        mmi_umms_app_ui_plug_in_viewer_post_func(SCR_ID_UMMS_MMS_VIEWER);
                    }
                }
            }
            else if (error == MMI_UMMS_FALSE)
            {
                mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_PLEASE_WAIT);
                mmi_umms_app_if_show_progress_screen();
            }
            else
            {
                /* do nothing */
            }
        }
            break;
        case SCR_ID_UMMS_PROGRESS:
        {
            mmi_umms_app_ui_draw_progress_screen_draw_func(scr_id);
        }
            break;
        case SCR_ID_UMMS_MMS_OPTION_SLIM:
        {
            if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
            {
                mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_COMM_SLIM_OPTIONS);
                /* framework enhancement for slim  changes */
                mmi_frm_group_create_ex(
                    mmi_umms_app_dtmgr_get_parent_grp_id(),
                    mmi_umms_dtmgr_get_group_id(),
                    mmi_umms_proc_func,
                    NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);
                mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
            }
            error = mmi_umms_get_data(data->open_mode);
            if (error == MMI_UMMS_TRUE)
            {
                mmi_umms_uc_process_entry_write_msg(data->open_mode);
            }
            else if (error == MMI_UMMS_FALSE)
            {
                mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_PLEASE_WAIT);
                mmi_umms_app_if_show_progress_screen();
            }
            else
            {
                /* do nothing */
            }
        }
            break;
        case SCR_ID_UMMS_ADD_RECIPIENT:
        {
            mmi_umms_app_ui_plug_in_add_recipient_list_pre_func(SCR_ID_UMMS_ADD_RECIPIENT);
            mmi_umms_app_ui_dyncmic_list_draw_func(SCR_ID_UMMS_ADD_RECIPIENT);
            mmi_umms_app_ui_plug_in_add_recipient_list_post_func(SCR_ID_UMMS_ADD_RECIPIENT);
        }
            break;
        case SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES:
        {
            mmi_umms_app_ui_plug_in_properties_pre_func(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
            mmi_umms_app_ui_property_status_screen_draw_func(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);
        }
            break;
        case SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST:
        {
            mmi_umms_app_ui_plug_in_save_objects_attachment_list_pre_func(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
            mmi_umms_app_ui_dyncmic_list_draw_func(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
            mmi_umms_app_ui_plug_in_save_objects_attachment_list_post_func(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
        }
            break;
        case SCR_ID_UMMS_DISPLAY_POPUP:
        {
            mmi_umms_app_ui_draw_display_popup_screen(0);
        }
            break;
        case SCR_ID_UMMS_CONFIRM:
        {
            mmi_umms_app_ui_draw_display_confirm_screen(SCR_ID_UMMS_CONFIRM);
        }
            break;
#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
        case SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE:
        {
			
            error = mmi_umms_app_ui_plug_in_memory_status_pre_func(SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE);
			 if (error != MMI_UMMS_FAIL)
              {
            mmi_umms_app_ui_property_status_screen_draw_func(SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE);
        }
			 else
			 {
				 return;
			 }
        }
            break;
#endif
        case SCR_ID_UMMS_MESSAGE_STATUS:
        {
            mmi_umms_app_ui_plug_in_show_message_status_screen_pre_func(SCR_ID_UMMS_MESSAGE_STATUS);
            mmi_umms_app_ui_property_status_screen_draw_func(SCR_ID_UMMS_MESSAGE_STATUS);
            mmi_umms_app_ui_plug_in_message_status_post_func(SCR_ID_UMMS_MESSAGE_STATUS);
        }
            break;
        case SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN:
        {
            MMI_UMMS_ERROR asm_error = MMI_UMMS_FALSE;
            mmi_id parent_id = GRP_ID_ROOT;

            mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);

            if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
            {
                mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_LIST_VIEW);
                /* framework enhancement  changes */
                mmi_frm_group_create_ex(
                    mmi_umms_app_dtmgr_get_parent_grp_id(),
                    mmi_umms_dtmgr_get_group_id(),
                    mmi_umms_proc_func,
                    NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);
                mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
            }
            mmi_umms_init_pools();
                        asm_error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX);
                        
                        if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
                        {
                            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
                            mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
                            mmi_umms_dtmgr_set_group_flag(MMI_FALSE);
                            mmi_umms_app_dtmgr_set_progress_scrn_data(STR_MMS_MENUENTRY, STR_GLOBAL_PLEASE_WAIT);
                            mmi_umms_app_if_show_progress_screen();
                            return;
                        }
            srv_mms_initialize_header_for_special_mms();

            mmi_umms_app_ui_plug_in_abnormal_view_pre_func(SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN);
            mmi_umms_app_ui_property_status_screen_draw_func(SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN);
            mmi_umms_app_ui_plug_in_abnormal_view_post_func(SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN);
        }
            break;

        case SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD:
        {
            if (mmi_umms_app_ui_plug_in_memory_status_pre_func(SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD) != MMI_UMMS_FAIL)
            {
                mmi_umms_app_ui_property_status_screen_draw_func(SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD);
            }
            else
            {
                return;
            }
        }
            break;

        case SCR_ID_UMMS_DISPLAY_INFINITE_POPUP:
        {

        }
            break;
    #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
        case SCR_ID_UMMS_MMS_PREFER_STORAGE:
        {
			if(mmi_umms_app_ui_plug_in_pref_storage_pre_func(SCR_ID_UMMS_MMS_PREFER_STORAGE) != MMI_UMMS_FAIL)
			{
            mmi_umms_ui_radio_selection_list_draw_func(SCR_ID_UMMS_MMS_PREFER_STORAGE);
            mmi_umms_app_ui_plug_in_pref_storage_post_func(SCR_ID_UMMS_MMS_PREFER_STORAGE);
        }
            else
            {
                return;
            }
            
        }
            break;
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
		case SCR_ID_UMMS_CALLBACK_DISPLAY_POPUP:
        {
			mmi_umms_app_ui_draw_display_callback_popup_screen(SCR_ID_UMMS_CALLBACK_DISPLAY_POPUP);
            
        }
            break;

        default:
        {
            mmi_umms_app_ui_draw_cui_static_list_draw_func(scr_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_dummy_screen_db
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_umms_app_screenDB_struct *mmi_umms_app_if_dummy_screen_db(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this is dummy */
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_dummy_reset_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_dummy_reset_data(void)
{
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *op_data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    U32 msg_id = 0;
    U8 sim_id = 0;
    U8 need_read_report = 0, set_readmark = 0;
    U8 storage_location = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op_data && op_data->msg_info && op_data->is_already_viewed == MMI_TRUE)
    {
        msg_id = op_data->msg_id;
        sim_id = op_data->msg_info->msg_sim_id;
        set_readmark = op_data->set_read_mark;
        need_read_report = op_data->msg_info->need_read_report;
        storage_location = op_data->msg_info->msg_storage;
    }
    if (need_read_report)
    {
#ifndef __MMI_MMS_NO_REPORT_SUPPORT__
        srv_mms_bgsr_set_rr_flag(msg_id);
        mmi_umms_app_dtmgr_send_read_report(msg_id, sim_id, storage_location);
#endif
        if (set_readmark)
        {
            mmi_umms_app_dtmgr_set_readmark(msg_id, MMI_TRUE);
        }
    }
    srv_mms_container_reset_context();
	#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
	mmi_umms_app_dtmgr_gdi_close_decoder(WGUI_MV_IMAGE_DECODED_FAILED, NULL, MMI_FALSE);
	memset(&g_umms_viewer_image_decoder_struct, 0, sizeof(mmi_umms_app_dtmgr_image_decode_struct));
   #endif
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_start_composer_from_cui
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_if_start_composer_from_cui(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_UMMS_ERROR error = MMI_UMMS_FALSE;
    mma_mms_description_struct *des;
    srv_mms_xml_parse_req_struct req = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) SRV_MMS_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
   #endif /* __USB_IN_NORMAL_MODE__ */ 
    if (mmi_umms_dtmgr_check_group_flag() == MMI_TRUE)
    {
        mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        mmi_umms_dtmgr_set_group_id(GRP_ID_INVALID);
        mmi_umms_dtmgr_set_group_flag(MMI_FALSE);
    }
    srv_mms_container_reset_context();  /* First Entry Reset */
    mmi_umms_app_dtmgr_set_parent_grp_id(parent_id);
    mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_COMM_SLIM_OPTIONS);
    /* This function will intialize and register for ASM */
    /* We will allocate ASM Later when press any suitable option like view, edit, reply */
    /* Forward etc. For basic operations 10K ADM is enough */
    mmi_umms_init_pools();
    error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX);
    if (error == MMI_UMMS_ASM_DRAW_SCR)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
        /* Reset Data and Exit */
        srv_mms_container_reset_context();
        return;
    }
    /* This will kick off composer with one slide */
    srv_mms_container_dummy_initializer();
    des = srv_mms_container_get_content();
    des->body->curr_slide = srv_mms_insert_slide();
    des->body->layout = SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP;
    des->body->bgColor = mma_get_default_smil_bg_color();
    des->body->fgColor = mma_get_default_smil_fg_color();
    srv_mms_process_data_init(des, &req);
    if (mmi_umms_dtmgr_check_group_flag() == MMI_FALSE)
    {
        //mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);
        mmi_umms_dtmgr_set_group_id(GRP_ID_UMMS_COMM_SLIM_OPTIONS);
        /*  changes framework enhancement */
        mmi_frm_group_create_ex(
            mmi_umms_app_dtmgr_get_parent_grp_id(),
            mmi_umms_dtmgr_get_group_id(),
            mmi_umms_proc_func,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_umms_dtmgr_set_group_flag(MMI_TRUE);
    }
    mmi_umms_uc_process_entry_write_msg(MMA_MODE_EDIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_if_dummy_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_umms_app_if_dummy_get_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mms_get_mms_info_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_init_pools
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_init_pools(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct asm_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_ID_MMS_VIEWER_APP;
    asm_cntx.success_cb = mmi_umms_app_core_mms_app_asm_success_callback;
    asm_cntx.stop_cb = mmi_ummsapp_core_mms_app_asm_stop_callback;
    asm_cntx.cancel_cb = mmi_umms_app_core_asm_viewer_cancel_callback;
    srv_mms_mem_mgr_init_app_asm_pool(APPLIB_MEM_AP_ID_UMMS, SRV_MMS_INSTANCE_DEFAULT_INDEX, &asm_cntx);
    memset(&asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
    asm_cntx.img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx.str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
    asm_cntx.success_cb = mmi_umms_app_core_asm_viewer_success_callback;
    asm_cntx.stop_cb = mmi_umms_app_core_asm_viewer_stop_callback;
    asm_cntx.cancel_cb = mmi_umms_app_core_asm_viewer_cancel_callback;
    srv_mms_mem_mgr_init_viewer_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX, &asm_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_get_data(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_content_req_struct msg_req;
    srv_mms_result_enum srv_result = SRV_MMS_RESULT_OK;
    MMI_UMMS_ERROR asm_error = MMI_UMMS_FALSE;
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_set_open_mode(mode);
    if (srv_mms_get_data_ready() == MMI_FALSE)
    {
        if (data->msg_info->msg_type == MMA_MSG_TYPE_READ_REPORT
            || data->msg_info->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT
            || data->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
        {
            mmi_umms_app_core_handle_view();
            return MMI_UMMS_FAIL;
        }
        mmi_umms_init_pools();
        asm_error = srv_mms_mem_mgr_check_asm_total_pool(
                    mmi_umms_app_core_asm_viewer_success_callback,
                    SRV_MMS_INSTANCE_DEFAULT_INDEX);

        if (asm_error == MMI_UMMS_ASM_DRAW_SCR)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
            return MMI_UMMS_FALSE;
        }
        memset(&msg_req, 0, sizeof(srv_mms_get_content_req_struct));
        msg_req.msg_id = data->msg_id;
        msg_req.call_back = (srv_mms_funcptr_type) mmi_umms_get_data_cb;
        msg_req.app_id = MMA_APP_ID_VIEWER;
        msg_req.mode = (mode == MMA_MODE_FORWARD) ? MMA_MODE_EDIT : mode;
        srv_result =(srv_mms_result_enum)srv_mms_get_content(&msg_req);
        if (srv_result != SRV_MMS_RESULT_OK)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, srv_result);
            ASSERT(0);
        }
        return MMI_UMMS_FALSE;
    }
    return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_data_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_get_data_cb(srv_mms_result_enum result, void *msgrsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_content_rsp_struct *rsp_content;
    srv_mms_xml_parse_req_struct xml_req = {0, };
    srv_mms_result_enum srv_result = SRV_MMS_RESULT_OK;
    MMI_UMMS_ERROR error = MMI_UMMS_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_content = (srv_mms_get_content_rsp_struct*) msgrsp;
    if (rsp_content->result != MMA_RESULT_OK)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_MV_TRACE_GET_CONTENT_RSP_ERR);
        srv_mms_viewer_send_event_to_exit(SRV_MMS_VIEWER_OK, 0);
        return;
    }
    error = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER, SRV_MMS_INSTANCE_DEFAULT_INDEX);
    if (error == MMI_UMMS_ASM_DRAW_SCR)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_ASM_ERROR);
        /* Close Group is a far better */
        mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        return;
    }
    /* prepare xml parser data */
    /* Application need one API */
    xml_req.mma_rsp = rsp_content->content_info;
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_VIEW_MODE_FOR_XML_PARSE, xml_req.mode);

    srv_result = (srv_mms_result_enum)srv_mms_container_prepare_context(&xml_req);
    if (srv_result != SRV_MMS_RESULT_OK)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_ERROR_FRM_SERVICE, srv_result);
        srv_mms_viewer_send_event_to_exit((srv_mms_viewer_result_enum)srv_result, 0);
        mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        return;
    }
#ifdef __MMI_MMS_BGSR_SUPPORT__
    if (srv_mms_container_get_folder() == MMA_FOLDER_OUTBOX)
    {
        if (srv_mms_container_set_bgsr_info() != SRV_MMS_RESULT_OK)
        {
            mmi_umms_app_sh_return_to_um_list();
            return;
        }
        mmi_umms_app_core_handle_view();
    }
    else
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
    {
        mmi_umms_app_core_handle_view();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_plug_in_remove_address_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_plug_in_remove_address_from_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_draw_dynamic_screen_struct *use_detail_scr =
        (mmi_umms_app_ui_draw_dynamic_screen_struct*) mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_ADD_RECIPIENT);
    mma_mms_addr_list_struct *current = NULL ;
	mma_mms_addr_list_struct **header_ext = NULL ;
    U16 index = use_detail_scr->hilighted_item;
    mma_mms_header_struct *header = srv_mms_container_get_header();
    U8 *curr_count = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (use_detail_scr->highlighted_menu)
    {
        case MENU_ID_UMMS_ADD_RECIPIENT_TO:
            current = header->to;
            header_ext = &(header->to);
            curr_count = &(header->to_num);
            break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case MENU_ID_UMMS_ADD_RECIPIENT_CC:
            current = header->cc;
            header_ext = &(header->cc);
            curr_count = &(header->cc_num);
            break;
        case MENU_ID_UMMS_ADD_RECIPIENT_BCC:
            current = header->bcc;
            header_ext = &(header->bcc);
            curr_count = &(header->bcc_num);
            break;
#endif
        default:
            ASSERT(0);

    }
    while (index != 0)
    {
        current = current->next;
        index--;
    }
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        *header_ext = current->next;
    }
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    srv_mms_mem_mgr_viewer_asm_free(current->address);
    srv_mms_mem_mgr_viewer_asm_free(current);
    current = NULL;
    g_srv_mms_uc_supp.srv_msg.total_address_num = (header->to_num + header->cc_num + header->bcc_num);
    (*curr_count)--;
    if (g_srv_mms_uc_supp.srv_msg.total_address_num == 0)
    {
        MMI_ASSERT(0);
    }
    else
    {
        g_srv_mms_uc_supp.srv_msg.total_address_num--;
    }
    if (use_detail_scr->hilighted_item > 0)
        (use_detail_scr->hilighted_item)--;
    srv_mms_update_msg_size();
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_REMOVED), MMI_EVENT_SUCCESS);
    mmi_umms_app_if_show_display_popup_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_plug_in_delete_attachmant_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_ui_plug_in_delete_attachmant_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
    mmi_umms_app_ui_draw_dynamic_screen_struct *dynamic_scr =
        (mmi_umms_app_ui_draw_dynamic_screen_struct*)
        mmi_umms_app_sh_get_scr_context(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
    U16 index = dynamic_scr->hilighted_item;
    mma_mms_description_struct *desc = srv_mms_container_get_content();
    mma_mms_attachment_info_struct *att = desc->body->attachment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (index != 0)
    {
        att = att->next;
        index--;
    }
    if (att->prev != NULL)
    {
        att->prev->next = att->next;
    }
    else
    {
        desc->body->attachment = att->next;
    }
    if (att->next != NULL)
    {
        att->next->prev = att->prev;
    }

    srv_mms_delete_object_from_list(att->object);
    srv_mms_mem_mgr_viewer_asm_free(att);
    att = NULL;
    srv_mms_update_msg_size();
    if (dynamic_scr->hilighted_item > 0)
        dynamic_scr->hilighted_item--;
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_REMOVED), MMI_EVENT_SUCCESS);
    mmi_umms_app_if_show_display_popup_screen();
    if (!(desc->body->attachment))
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_make_uc_start_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mms_make_uc_start_context(mmi_umms_uc_entry_write_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(data)
	{
		g_uc_start_context = (mmi_umms_uc_entry_write_struct *)srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_umms_uc_entry_write_struct));
		if(g_uc_start_context == NULL)
		{
			return MMI_FALSE;
		}
		memset(g_uc_start_context, 0, sizeof(mmi_umms_uc_entry_write_struct));
		if(data->addr)
		{
			g_uc_start_context->addr = (mma_mms_addr_list_struct *)srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_addr_list_struct));
			if(g_uc_start_context->addr == NULL)
			{
				return MMI_FALSE;
			}
			memset(g_uc_start_context->addr, 0, sizeof(mma_mms_addr_list_struct));
			if(data->addr->address)
			{
				U32 addr_len = strlen(data->addr->address);
				g_uc_start_context->addr->address = (kal_char *)srv_mms_mem_mgr_app_adm_alloc(addr_len + 1);
				if(g_uc_start_context->addr->address == NULL)
				{
					return MMI_FALSE;
				}
				memset(g_uc_start_context->addr->address, 0, addr_len + 1);
				memcpy(g_uc_start_context->addr->address, data->addr->address, addr_len);
			}
			g_uc_start_context->addr->addr_type = data->addr->addr_type;
			g_uc_start_context->addr->group = data->addr->group;
		}
		if(data->file_path)
		{
			U32 flie_path_len = mmi_ucs2strlen((S8*) data->file_path);
			g_uc_start_context->file_path = (kal_uint8 *)srv_mms_mem_mgr_app_adm_alloc(flie_path_len * ENCODING_LENGTH + 2);
			if(g_uc_start_context->file_path == NULL)
			{
				return MMI_FALSE;
			}
			memset(g_uc_start_context->file_path, 0, flie_path_len * ENCODING_LENGTH + 2);
			mmi_ucs2ncpy((CHAR*)g_uc_start_context->file_path, (CHAR*)data->file_path, flie_path_len);
		}
		if(data->text_buffer)
		{
			U32 buffer_len = strlen((S8*) data->text_buffer);
			g_uc_start_context->text_buffer = (kal_uint8 *)srv_mms_mem_mgr_app_adm_alloc(buffer_len + 1);
			if(g_uc_start_context->text_buffer == NULL)
			{
				return MMI_FALSE;
			}
			memset(g_uc_start_context->text_buffer, 0, buffer_len + 1);
			memcpy(g_uc_start_context->text_buffer, data->text_buffer, buffer_len);
		}
		g_uc_start_context->text_num = data->text_num;
		g_uc_start_context->addr_num = data->addr_num;
		g_uc_start_context->sim_id = data->sim_id;
		g_uc_start_context->msg_type = data->msg_type;
		g_uc_start_context->info_type = data->info_type;
	}

	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_get_uc_start_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_umms_uc_entry_write_struct *mmi_mms_get_uc_start_context(void)
{
	if(g_uc_start_context != NULL)
	{
		return g_uc_start_context;
	}
	else
	{
		return NULL ;
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mms_reset_uc_start_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_reset_uc_start_context(void)
{
	if(g_uc_start_context != NULL)
	{
		if(g_uc_start_context->addr)
		{
			if(g_uc_start_context->addr->address)
			{
				srv_mms_mem_mgr_app_adm_free(g_uc_start_context->addr->address);
				g_uc_start_context->addr->address = NULL;
			}
			srv_mms_mem_mgr_app_adm_free(g_uc_start_context->addr);
			g_uc_start_context->addr = NULL;
		}
		if(g_uc_start_context->file_path)
		{
			srv_mms_mem_mgr_app_adm_free(g_uc_start_context->file_path);
			g_uc_start_context->file_path = NULL;
		}
		if(g_uc_start_context->text_buffer)
		{
			srv_mms_mem_mgr_app_adm_free(g_uc_start_context->text_buffer);
			g_uc_start_context->text_buffer = NULL;
		}
		srv_mms_mem_mgr_app_adm_free(g_uc_start_context);
		g_uc_start_context = NULL;
	}
}



 void mmi_umms_slim_decide_before_send()
 {
        #if(MMI_MAX_SIM_NUM >2)

            MMI_ID sim_sel_cui_id;
            MMI_ID sim_sel_parent_id;

        #endif

                    if (1 == srv_mms_num_valid_sim())
                    {
#if(MMI_MAX_SIM_NUM >= 2)
                        srv_mms_set_selected_sim_id(srv_mms_get_sim_valid_flag());
#endif
                        mmi_umms_app_ui_plug_in_handle_saving_sending_mms(MENU_ID_UMMS_OPTIONS_SLIM_SEND);
                    return;
                    }

	   #if(MMI_MAX_SIM_NUM == 2)
			else
                    {
                        return;
                    }

       #endif /* (MMI_MAX_SIM_NUM == 2) */ 
       #if(MMI_MAX_SIM_NUM >2)
			else
			{
                    sim_sel_parent_id = mmi_frm_group_create_ex(
                                            GRP_ID_ROOT,
                                            GRP_ID_AUTO_GEN,
                                            mmi_umms_app_ui_callback_slim_sim_sel_proc,
                                            NULL,
                                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
                    sim_sel_cui_id = cui_sim_sel_create(sim_sel_parent_id, srv_mms_get_sim_valid_flag(), NULL);
                    if (sim_sel_cui_id != GRP_ID_INVALID)
                    {
                        mmi_umms_app_dtmgr_set_sim_sel_cui_id(sim_sel_cui_id);
                        cui_sim_sel_set_highlight_sim(MMA_SIM_ID_SIM1);
                        cui_sim_sel_run(sim_sel_cui_id);
                    }
                    return;
			 }
		#endif /* (MMI_MAX_SIM_NUM >2) */ 
                    
                

 }
#if defined(__MMI_FTE_SUPPORT__)

 void mmi_umms_app_if_slim_send ()
 {
	 mmi_id child_menu_gid;

     mma_mms_header_struct *header = srv_mms_container_get_header();

  

    if(header->bcc_num || header->cc_num || header->to_num)
	{
      #if(MMI_MAX_SIM_NUM == 2)
                    if (1 <  srv_mms_num_valid_sim())
				{
  child_menu_gid = cui_menu_create(
                        mmi_umms_dtmgr_get_group_id(),
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,  /* Option menu */
                        MENU_ID_UMMS_OPTIONS_SLIM_SEND,    /* parent menu */
                        MMI_TRUE,
                        NULL);
					 cui_menu_run(child_menu_gid);   /* start to run this cui */
					 return;
					}
#endif
		mmi_umms_slim_decide_before_send();
      
	}
	else
	{
		if (srv_mms_num_valid_sim() != 0)
		{
     	 cui_menu_set_currlist_highlighted_id(mmi_umms_app_dtmgr_get_menu_cui_id() ,MENU_ID_UMMS_OPTIONS_SLIM_SEND) ;
	    }
        GoBackHistory();
	}


				}

 void mmi_umms_app_slim_insert_object ()
	 {
	 mmi_id child_menu_gid;

   child_menu_gid = cui_menu_create(
                        mmi_umms_dtmgr_get_group_id(),
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,  /* Option menu */
                        MENU_ID_UMMS_INSERT,    /* parent menu */
                        MMI_TRUE,
                        NULL);
					 cui_menu_run(child_menu_gid);   /* start to run this cui */
	 
 }
#endif

#endif /* defined (__MMI_MMS_2__) && defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__) */ 

