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
 * UcScrUICtrl.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements generic handling of screen controler, resource controller, Db handling, key handling for Unified Composer application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

#ifndef _UC_POSTCARD_APP_C
#define _UC_POSTCARD_APP_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#ifdef __MMI_MMS_POSTCARD__
//suggested add    
#include "mmi_rp_app_unifiedcomposer_def.h"
//end
#include "PhbCuiGprot.h"
#include "PhbSrvGprot.h"
//#include "PhoneBookResDef.h"

#include "Commonscreens.h"
#include "wapadp.h"
#include "UcResDef.h"
//#include "Custom_events_notify.h"
//#include "UmGprot.h"
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#endif
#include "UcAppGprot.h"
#include "FileMgr.h"
#include "FileMgrGProt.h"
#include "UcAppProt.h"
#include "UcPcrdProt.h"
#include "UcScrUIProt.h"
//suggested add
    #include "MMI_features.h"
    #include "UcSrvGprot.h"
    #include "MMIDataType.h"
    #include "Unicodexdcl.h"
    #include "mmi_frm_mem_gprot.h"
    //#include "kal_public_api.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_frm_events_gprot.h"
    //#include "kal_general_types.h"
    #include "wgui_categories_util.h"
    #include "AlertScreen.h"
    #include "string.h"
    #include "mmi_frm_history_gprot.h"
    #include "gui_data_types.h"
    #include "CustDataRes.h"
    #include "GlobalResDef.h"
    #include "custom_phb_config.h"
    #include "mmi_res_range_def.h"
    #include "DebugInitDef_Int.h"
    #include "wgui_inline_edit.h"
    #include "GlobalConstants.h"
    #include "ImeGprot.h"
   // #include "MMI_common_app_trc.h"
    #include "kal_trace.h"
    //#include "mmi_common_app_trc.h"
    #include "PhoneBookGprot.h"
    //#include "ps_public_enum.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef __MMI_UC_POSTCARD_INTERNAL_TESTING__
#define TW_MMS_POSTCARD_NUMBER "+886910148670"
#define CN_MMS_POSTCARD_NUMBER "+8613823151446"
#define IN_MMS_POSTCARD_NUMBER "+919873255563"
#endif /* __MMI_UC_POSTCARD_INTERNAL_TESTING__ */ 
/****************************************************************************
* Constants
*****************************************************************************/
/****************************************************************************
 * Type definitions
 ****************************************************************************/
/***************************************************************************** 
* Extern Function
*****************************************************************************/

/***************************************************************************** 
* Local static Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sh_postcard_exit_recipient_address_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_sh_postcard_exit_recipient_address_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sh_postcard_exit_recipient_address_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_entry_multiple_recipient_option(void)
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
 *  mmi_postcard_validate_recipient_address_data
 * DESCRIPTION
 *  Validation of input address data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_validate_recipient_address_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *new_recipient;
    srv_postcard_recipient_struct *index_recipient;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_name) == 0 &&
        mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_additional) == 0 &&
        mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_street) == 0 &&
        mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_city) == 0 &&
        mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_postalcode) == 0 &&
        mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_state) == 0 &&
        mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_country) == 0)
    {
        /* address fields have been edited but finally keep empty data */
        if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward != NULL)
        {
            OslMfree(g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward);
            g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward = NULL;
        }
        if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation == SRV_POSTCARD_ADDRESS_EDIT &&
            g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total != 0)
        {
            mmi_postcard_delete_one_recipient_without_popup();
        }
        else
        {
            if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, mmi_uc_get_recipient_screen_id(), MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                if(g_uc_p->main.inline_cui_id)
                {
                   mmi_frm_group_close(g_uc_p->main.inline_cui_id);
                }
                else if(g_uc_p->main.inline_child_cui_id)
                {
                   mmi_frm_group_close(g_uc_p->main.inline_child_cui_id);
                }
                mmi_uc_set_group_id();
            }
            else
            {
                if(g_uc_p->main.inline_cui_id)
                {
                   mmi_frm_group_close(g_uc_p->main.inline_cui_id);
                }
                else if(g_uc_p->main.inline_child_cui_id)
                {
                   mmi_frm_group_close(g_uc_p->main.inline_child_cui_id);
                }
            }
        }
        return;
    }

    /* name, street, and city are mandatory for postal address */
    if (mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_name) == 0)
    {
        mmi_popup_display((WCHAR*)(get_string(STR_ID_POSTCARD_RECIPIENT_NAME_MANDATORY)), MMI_EVENT_ERROR, NULL);
        return;
    }

    if (mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_street) == 0)
    {
        mmi_popup_display((WCHAR*)(get_string(STR_ID_POSTCARD_RECIPIENT_STREET_MANDATORY)), MMI_EVENT_ERROR, NULL);
        return;
    }

    if (mmi_ucs2strlen((S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_city) == 0)
    {
        mmi_popup_display((WCHAR*)(get_string(STR_ID_POSTCARD_RECIPIENT_CITY_MANDATORY)), MMI_EVENT_ERROR, NULL);
        return;
    }

    new_recipient =
        (srv_postcard_recipient_struct*) kal_adm_alloc(
                                            g_uc_p->main.mem_pool_id,
                                            sizeof(srv_postcard_recipient_struct));
    memset(new_recipient, 0, sizeof(srv_postcard_recipient_struct));

    mmi_ucs2cpy(
        (S8*) new_recipient->address.postcard_name,
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_name);
    mmi_ucs2cpy(
        (S8*) new_recipient->address.postcard_additional,
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_additional);
    mmi_ucs2cpy(
        (S8*) new_recipient->address.postcard_street,
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_street);
    mmi_ucs2cpy(
        (S8*) new_recipient->address.postcard_city,
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_city);
    mmi_ucs2cpy(
        (S8*) new_recipient->address.postcard_postalcode,
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_postalcode);
    mmi_ucs2cpy(
        (S8*) new_recipient->address.postcard_state,
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_state);
    mmi_ucs2cpy(
        (S8*) new_recipient->address.postcard_country,
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_country);

    new_recipient->address.phonebook_index = g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->phonebook_index;

#ifdef __MMI_PHB_INFO_FIELD__
    if (new_recipient->address.phonebook_index != 0xFF)
    {
        /* compare with the original phonebook data if this entry is modified */
        new_recipient->update = srv_postcard_check_if_import_data_changed(new_recipient->address);
    }
    else
#endif /* __MMI_PHB_INFO_FIELD__ */ 
    {
        new_recipient->update = MMI_TRUE;
    }

    OslMfree(g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor);
    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor = NULL;

    SetDelScrnIDCallbackHandler(SCR_ID_POSTCARD_ADDRESS, (HistoryDelCBPtr) NULL);

    /* operations: init, add, or edit */
    switch (g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation)
    {
        case SRV_POSTCARD_ADDRESS_INIT:
            g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_head = new_recipient;
            g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total++;
            mmi_uc_set_recipient_index();
            mmi_uc_replace_recipient_screen();
            if(g_uc_p->main.inline_cui_id)
            {
               mmi_frm_group_close(g_uc_p->main.inline_cui_id);
            }
            else if(g_uc_p->main.inline_child_cui_id)
            {
               mmi_frm_group_close(g_uc_p->main.inline_child_cui_id);
            }
            if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward != NULL)
            {
                OslMfree(g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward);
                g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward = NULL;
            }
            else
            {
                mmi_uc_set_group_id();
            }
            break;

        case SRV_POSTCARD_ADDRESS_ADD:
            index = g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index - 1;
            index_recipient = srv_postcard_get_recipient_pointer_by_index(g_uc_p->main.instance, index);
            index_recipient->next = new_recipient;
            new_recipient->previous = index_recipient;
            g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total++;
            mmi_uc_replace_recipient_screen();
            mmi_uc_set_recipient_index();
            if(g_uc_p->main.inline_cui_id)
            {
               mmi_frm_group_close(g_uc_p->main.inline_cui_id);
            }
            else if(g_uc_p->main.inline_child_cui_id)
            {
               mmi_frm_group_close(g_uc_p->main.inline_child_cui_id);
            }
            mmi_uc_set_group_id();
            break;

        case SRV_POSTCARD_ADDRESS_EDIT:
            index = g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index;
            index_recipient = srv_postcard_get_recipient_pointer_by_index(g_uc_p->main.instance, index);
            memcpy(&index_recipient->address, &new_recipient->address, sizeof(srv_postcard_address_struct));
            kal_adm_free(g_uc_p->main.mem_pool_id, new_recipient);
            mmi_uc_replace_recipient_screen();
            if(g_uc_p->main.inline_cui_id)
            {
               mmi_frm_group_close(g_uc_p->main.inline_cui_id);
            }
            else if(g_uc_p->main.inline_child_cui_id)
            {
               mmi_frm_group_close(g_uc_p->main.inline_child_cui_id);
            }
            mmi_uc_set_group_id();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_get_recipient_name_to_list
 * DESCRIPTION
 *  Highlight handler to return the recipient name
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_postcard_get_recipient_name_to_list(
        S32 item_index,
        UI_string_type str_buff,
        PU8 *img_buff_p,
        U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) str_buff,
        (S8*) srv_postcard_get_recipient_name_by_index(g_uc_p->main.instance, (U8) item_index));
    *img_buff_p = (PU8) GetImage((U16) (gIndexIconsImageList[item_index]));

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_delete_address_editor_callback
 * DESCRIPTION
 *  Callback function if address editor screen is deleted
 * PARAMETERS
 *  p       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
mmi_ret mmi_postcard_delete_address_editor_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
    case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        mmi_uc_frm_sh_delete_screen_context(MMI_UC_FLOW_INSTANCE_ID_POSTCARD_ADDRESS);

        break;
    case EVT_ID_SCRN_GOBACK:
    case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        mmi_uc_frm_sh_delete_screen_context(MMI_UC_FLOW_INSTANCE_ID_POSTCARD_ADDRESS);

        break;
    case EVT_ID_SCRN_DEINIT:
        srv_postcard_delete_address_editor_handler(g_uc_p->main.instance, evt->user_data);

        break;
    default:
        return MMI_RET_ERR;
    }
    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_entry_import_manual
 * DESCRIPTION
 *  Entry function of import address manually
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_entry_import_manual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total >= SRV_POSTCARD_MAX_RECIPIENTS)
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_UC_RECIPIENT_NUMBER_EXCEED_ID)), MMI_EVENT_ERROR, NULL);
        return;
    }
    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index = g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total;
    if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total)
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation = SRV_POSTCARD_ADDRESS_ADD;
    }
    else
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation = SRV_POSTCARD_ADDRESS_INIT;
    }
    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor =
        (srv_postcard_address_struct*) OslMalloc(sizeof(srv_postcard_address_struct));
    memset(g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor, 0, sizeof(srv_postcard_address_struct));

    if (srv_postcard_is_recipient_forward(g_uc_p->main.instance))
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->phonebook_index = g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->phonebook_index;       /* from phonebook */
    }
    else
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->phonebook_index = 0xFF;      /* not from phonebook */
    }

#ifdef __MMI_PHB_INFO_FIELD__
    if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward != NULL)
    {
        srv_postcard_copy_phb_forward_data_to_editor(g_uc_p->main.instance);
    }
#endif /* __MMI_PHB_INFO_FIELD__ */ 

    mmi_uc_entry_recipient_address_inline_editor_cui();
    /* SetDelScrnIDCallbackHandler(SCR_ID_POSTCARD_ADDRESS, (HistoryDelCBPtr) mmi_postcard_delete_address_editor_callback); */

    // DeleteScreenIfPresent(SCR_ID_POSTCARD_ADD_RECIPIENT);  /* check this */
}

#ifdef __MMI_PHB_INFO_FIELD__


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_return_address_by_phb_index
 * DESCRIPTION
 *  Return function of import address from phonebook
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_return_address_by_phb_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_address_struct phb_info_field_address = {0,};
    U16 name[MMI_PHB_NAME_FIELD_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_phb_check_entry_exist(store_index))
    {
        srv_phb_get_name(store_index, name, MMI_PHB_NAME_FIELD_LENGTH);
        srv_phb_remove_invalid_name(name);
        srv_phb_get_address(store_index, 
                            NULL,
                            phb_info_field_address.extension,
                            phb_info_field_address.street,
                            phb_info_field_address.city,
                            phb_info_field_address.state,
                            phb_info_field_address.postalcode,
                            phb_info_field_address.country);

    }
    else
    {
        memset(&phb_info_field_address, 0, sizeof(mmi_phb_address_struct));
    }

    if (!srv_postcard_check_if_phonebook_data_with_star(store_index, &phb_info_field_address))
    {
        mmi_popup_display((WCHAR*)(get_string(STR_ID_POSTCARD_RECIPIENT_STAR_PROHIBITED)), MMI_EVENT_ERROR, NULL);
        return;
    }

    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor =
        (srv_postcard_address_struct*) OslMalloc(sizeof(srv_postcard_address_struct));
    memset(g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor, 0, sizeof(srv_postcard_address_struct));

    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_name,
        (S8*) name);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_additional,
        (S8*) phb_info_field_address.extension);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_street,
        (S8*) phb_info_field_address.street);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_city,
        (S8*) phb_info_field_address.city);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_postalcode,
        (S8*) phb_info_field_address.postalcode);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_state,
        (S8*) phb_info_field_address.state);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_country,
        (S8*) phb_info_field_address.country);

    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->phonebook_index = store_index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_cui_event_handler_group_proc
 * DESCRIPTION
 *  Function for postcard composer to process the result of cui events
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  process result of msg
 *****************************************************************************/
static mmi_ret mmi_postcard_cui_event_handler_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_SELECT_CONTACT:
            {
                cui_phb_select_contact_result_struct* select_contact_result = (cui_phb_select_contact_result_struct*)evt;

                mmi_postcard_return_address_by_phb_index( select_contact_result->store_index);
                cui_phb_list_select_contact_close(g_uc_p->srv_msg->msg_body.postcard_recipient_info.select_contact_cui_gid);
                mmi_uc_entry_recipient_address_inline_editor_cui();
            }
            break;
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            {
                cui_phb_list_select_contact_close(g_uc_p->srv_msg->msg_body.postcard_recipient_info.select_contact_cui_gid);
            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_entry_import_phonebook
 * DESCRIPTION
 *  Entry function of import address from phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_entry_import_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total >= SRV_POSTCARD_MAX_RECIPIENTS)
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_UC_RECIPIENT_NUMBER_EXCEED_ID)), MMI_EVENT_ERROR, NULL);
        return;
    }
    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index = g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total;
    if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total)
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation = SRV_POSTCARD_ADDRESS_ADD;
    }
    else
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation = SRV_POSTCARD_ADDRESS_INIT;
    }

    /*
     * invoke PHB interface to select an entry
     * after selection, PHB will return to postcard application
     */
    //mmi_frm_group_entry_ex(GRP_ID_ROOT, APP_MMS_POSTCARD, mmi_postcard_cui_event_handler_group_proc, NULL, NULL);
    mmi_frm_group_create(GRP_ID_ROOT, APP_MMS_POSTCARD, mmi_postcard_cui_event_handler_group_proc, NULL);
    mmi_frm_group_enter(APP_MMS_POSTCARD, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_uc_p->srv_msg->msg_body.postcard_recipient_info.select_contact_cui_gid = cui_phb_list_select_contact_create(APP_MMS_POSTCARD);
    if(g_uc_p->srv_msg->msg_body.postcard_recipient_info.select_contact_cui_gid != GRP_ID_INVALID)
    {
        cui_phb_list_select_contact_set_field_filter(g_uc_p->srv_msg->msg_body.postcard_recipient_info.select_contact_cui_gid, SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_ADDRESS);        
        cui_phb_list_select_contact_run(g_uc_p->srv_msg->msg_body.postcard_recipient_info.select_contact_cui_gid);
    }
    else
    {
        mmi_frm_group_close(APP_MMS_POSTCARD);
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_entry_to_option_edit
 * DESCRIPTION
 *  Edit function of a recipients
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_entry_to_option_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor =
        (srv_postcard_address_struct*) OslMalloc(sizeof(srv_postcard_address_struct));
    memset(g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor, 0, sizeof(srv_postcard_address_struct));

    /* prepare edit data */
    index_recipient = srv_postcard_get_recipient_pointer_by_index(
                        g_uc_p->main.instance,
                        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index);

    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_name,
        (S8*) index_recipient->address.postcard_name);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_additional,
        (S8*) index_recipient->address.postcard_additional);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_street,
        (S8*) index_recipient->address.postcard_street);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_city,
        (S8*) index_recipient->address.postcard_city);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_postalcode,
        (S8*) index_recipient->address.postcard_postalcode);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_state,
        (S8*) index_recipient->address.postcard_state);
    mmi_ucs2cpy(
        (S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_editor->postcard_country,
        (S8*) index_recipient->address.postcard_country);

    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_operation = SRV_POSTCARD_ADDRESS_EDIT;

    mmi_uc_entry_recipient_address_inline_editor_cui();
    /* SetDelScrnIDCallbackHandler(SCR_ID_POSTCARD_ADDRESS, (HistoryDelCBPtr) mmi_postcard_delete_address_editor_callback); */

    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_POSTCARD_RECIPIENT_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_delete_one_recipient
 * DESCRIPTION
 *  Deletion of an recipient
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_delete_one_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *previous_recipient;
    srv_postcard_recipient_struct *current_recipient;
    srv_postcard_recipient_struct *next_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_recipient = srv_postcard_get_recipient_pointer_by_index(
                            g_uc_p->main.instance,
                            g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index);
    previous_recipient = current_recipient->previous;
    next_recipient = current_recipient->next;

    if (previous_recipient != NULL)
    {
        previous_recipient->next = next_recipient;
    }

    if (next_recipient != NULL)
    {
        next_recipient->previous = previous_recipient;
    }

    if (current_recipient == g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_head)
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_head = next_recipient;
    }

    kal_adm_free(g_uc_p->main.mem_pool_id, current_recipient);
    current_recipient = NULL;

    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total--;

    /* go back to send option screen if no recipient is left */
    if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total == 0)
    {
        /* DeleteScreenIfPresent(SCR_ID_POSTCARD_RECIPIENT_LIST); */
    }
    else
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index = 0;
    }

    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_UC_REMOVED_ID)), MMI_EVENT_SUCCESS, NULL);
    if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, mmi_uc_get_recipient_screen_id(), MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) || 
		mmi_frm_scrn_is_present(g_uc_p->main.parent_grp_id, mmi_uc_get_recipient_screen_id(), MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) )
    {
        {
            U16 next_scrn_id = 0, top_scrn_id = 0;
            top_scrn_id = mmi_frm_scrn_get_neighbor_id(g_uc_p->main.uc_cui_gid, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG); 
            next_scrn_id = mmi_frm_scrn_get_neighbor_id(g_uc_p->main.uc_cui_gid, mmi_uc_get_recipient_screen_id(), MMI_FRM_NODE_AFTER_FLAG); 
            mmi_frm_scrn_multiple_close (g_uc_p->main.uc_cui_gid, top_scrn_id, 1, 0, next_scrn_id, 1);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_delete_one_recipient_without_popup
 * DESCRIPTION
 *  Deletion of an recipient
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_delete_one_recipient_without_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *previous_recipient;
    srv_postcard_recipient_struct *current_recipient;
    srv_postcard_recipient_struct *next_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_recipient = srv_postcard_get_recipient_pointer_by_index(
                            g_uc_p->main.instance,
                            g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index);
    previous_recipient = current_recipient->previous;
    next_recipient = current_recipient->next;

    if (previous_recipient != NULL)
    {
        previous_recipient->next = next_recipient;
    }

    if (next_recipient != NULL)
    {
        next_recipient->previous = previous_recipient;
    }

    if (current_recipient == g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_head)
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_head = next_recipient;
    }

    kal_adm_free(g_uc_p->main.mem_pool_id, current_recipient);
    current_recipient = NULL;

    g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total--;

    /* go back to send option screen if no recipient is left */
    if (g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total == 0)
    {
        /* DeleteScreenIfPresent(SCR_ID_POSTCARD_RECIPIENT_LIST); */
    }
    else
    {
        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index = 0;
    }

    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_POSTCARD_RECIPIENT_OPTION);
    {
        U16 next_scrn_id = 0, top_scrn_id = 0;
        top_scrn_id = mmi_frm_scrn_get_neighbor_id(g_uc_p->main.uc_cui_gid, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG); 
        next_scrn_id = mmi_frm_scrn_get_neighbor_id(g_uc_p->main.uc_cui_gid, mmi_uc_get_recipient_screen_id(), MMI_FRM_NODE_AFTER_FLAG); 
        mmi_frm_scrn_multiple_close (g_uc_p->main.uc_cui_gid, top_scrn_id, 1, 0, next_scrn_id, 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_reset_all_recipients
 * DESCRIPTION
 *  Deletion of all recipients
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_reset_all_recipients(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_postcard_clear_all_context(g_uc_p->main.instance);

    /* go back to send option screen */
    /* DeleteScreenIfPresent(SCR_ID_POSTCARD_RECIPIENT_LIST); */
    mmi_uc_replace_recipient_screen();
    //mmi_uc_set_recipient_index();
    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_UC_REMOVED_ID)), MMI_EVENT_SUCCESS, NULL);
    if (mmi_frm_scrn_is_present(g_uc_p->main.uc_cui_gid, mmi_uc_get_recipient_screen_id(), MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        {
            U16 next_scrn_id = 0, top_scrn_id = 0;
            top_scrn_id = mmi_frm_scrn_get_neighbor_id(g_uc_p->main.uc_cui_gid, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG); 
            next_scrn_id = mmi_frm_scrn_get_neighbor_id(g_uc_p->main.uc_cui_gid, mmi_uc_get_recipient_screen_id(), MMI_FRM_NODE_AFTER_FLAG); 
            mmi_frm_scrn_multiple_close (g_uc_p->main.uc_cui_gid, top_scrn_id, 1, 0, next_scrn_id, 1);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_set_recipient_address_custom_function
 * DESCRIPTION
 *  Custom function of recipient's address editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_set_recipient_address_custom_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(mmi_postcard_return_menu_root_icon());

    /* not allow to input '*' in address fields */
    mmi_imm_set_characters(MMI_FALSE, (UI_character_type*) SRV_POSTCARD_FORBIDDEN_CHAR);
}

#ifdef __MMI_PHB_INFO_FIELD__


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_forward_from_phonebook_entry
 * DESCRIPTION
 *  Export function of recipients address data
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_forward_from_phonebook_entry(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *new_recipient;
    mmi_phb_address_struct phb_info_field_address = {0,};
    U16 name[MMI_PHB_NAME_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_POSTCARD_FORWARD_FROM_PHONEBOOK);
    if (g_uc_p->main.uc_cui_gid != GRP_ID_INVALID)
	{
		if (srv_phb_check_entry_exist(store_index))
		{
	        
			srv_phb_get_name(store_index, name, MMI_PHB_NAME_LENGTH);

			srv_phb_get_address(store_index, 
								NULL,
								phb_info_field_address.extension,
								phb_info_field_address.street,
								phb_info_field_address.city,
								phb_info_field_address.state,
								phb_info_field_address.postalcode,
								phb_info_field_address.country);
	            
		}
		else
		{
			memset(&phb_info_field_address, 0, sizeof(mmi_phb_address_struct));
		}

		if (!srv_postcard_check_if_phonebook_data_with_star(store_index, &phb_info_field_address))
		{
			mmi_popup_display((WCHAR*)(get_string(STR_ID_POSTCARD_RECIPIENT_STAR_PROHIBITED)), MMI_EVENT_ERROR, NULL);
			mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_UC_PROCESSING);
			return;
		}

		if (mmi_ucs2strlen((S8*) name) != 0 &&
			mmi_ucs2strlen((S8*) phb_info_field_address.street) != 0 &&
			mmi_ucs2strlen((S8*) phb_info_field_address.city) != 0)
		{
			/* this entry forwarded from phonebook is complete */
			new_recipient =
				(srv_postcard_recipient_struct*) kal_adm_alloc(
													g_uc_p->main.mem_pool_id,
													sizeof(srv_postcard_recipient_struct));
			memset(new_recipient, 0, sizeof(srv_postcard_recipient_struct));

			mmi_ucs2cpy((S8*) new_recipient->address.postcard_name, (S8*) name);
			mmi_ucs2cpy((S8*) new_recipient->address.postcard_additional, (S8*) phb_info_field_address.extension);
			mmi_ucs2cpy((S8*) new_recipient->address.postcard_street, (S8*) phb_info_field_address.street);
			mmi_ucs2cpy((S8*) new_recipient->address.postcard_city, (S8*) phb_info_field_address.city);
			mmi_ucs2cpy((S8*) new_recipient->address.postcard_postalcode, (S8*) phb_info_field_address.postalcode);
			mmi_ucs2cpy((S8*) new_recipient->address.postcard_state, (S8*) phb_info_field_address.state);
			mmi_ucs2cpy((S8*) new_recipient->address.postcard_country, (S8*) phb_info_field_address.country);

			new_recipient->address.phonebook_index = store_index;

			g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_head = new_recipient;
			g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total = 1;
		}
		else
		{
			/* this entry forwarded from phonebook is fragmentary */
			g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward =
				(srv_postcard_address_struct*) OslMalloc(sizeof(srv_postcard_address_struct));
			memset(g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward, 0, sizeof(srv_postcard_address_struct));

			mmi_ucs2cpy(
				(S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->postcard_name,
				(S8*) name);
			mmi_ucs2cpy(
				(S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->postcard_additional,
				(S8*) phb_info_field_address.extension);
			mmi_ucs2cpy(
				(S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->postcard_street,
				(S8*) phb_info_field_address.street);
			mmi_ucs2cpy(
				(S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->postcard_city,
				(S8*) phb_info_field_address.city);
			mmi_ucs2cpy(
				(S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->postcard_postalcode,
				(S8*) phb_info_field_address.postalcode);
			mmi_ucs2cpy(
				(S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->postcard_state,
				(S8*) phb_info_field_address.state);
			mmi_ucs2cpy(
				(S8*) g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->postcard_country,
				(S8*) phb_info_field_address.country);
			g_uc_p->srv_msg->msg_body.postcard_recipient_info.phonebook_forward->phonebook_index = store_index;
		}
	}
}


mmi_ret mmi_postcard_cui_event_handler_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_save_contact_result_struct* save_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
            {
                save_result = (cui_phb_save_contact_result_struct*)evt;

                cui_phb_save_contact_close(g_uc_p->srv_msg->msg_body.postcard_recipient_info.save_contact_cui_gid);
            }
            break;
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            {
                cui_phb_save_contact_close(g_uc_p->srv_msg->msg_body.postcard_recipient_info.save_contact_cui_gid);
            }
            break;
        default:
            break;
    }
    
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_export_address_to_phonebook_manual
 * DESCRIPTION
 *  Export function of recipients address data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_export_address_to_phonebook_manual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct *index_recipient;
    srv_phb_contact_data_struct *recipient_phb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_POSTCARD_EXPORT_ADDRESS_TO_PHONEBOOK_MANUAL);
    index_recipient = srv_postcard_get_recipient_pointer_by_index(
                        g_uc_p->main.instance,
                        g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_index);

    recipient_phb = (srv_phb_contact_data_struct *) OslMalloc (sizeof(srv_phb_contact_data_struct));
    memset(recipient_phb, 0, sizeof(srv_phb_contact_data_struct));
    recipient_phb->name =(U16*) index_recipient->address.postcard_name;
    recipient_phb->extension = (U16*) index_recipient->address.postcard_additional;
    recipient_phb->street = (U16*) index_recipient->address.postcard_street;
    recipient_phb->city = (U16*) index_recipient->address.postcard_city;
    recipient_phb->state = (U16*) index_recipient->address.postcard_state;
    recipient_phb->postalcode = (U16*) index_recipient->address.postcard_postalcode;
    recipient_phb->country = (U16*) index_recipient->address.postcard_country;

    //mmi_frm_group_entry_ex(GRP_ID_ROOT, APP_MMS_POSTCARD, mmi_postcard_cui_event_handler_proc, NULL, NULL);
    mmi_frm_group_create(GRP_ID_ROOT, APP_MMS_POSTCARD, mmi_postcard_cui_event_handler_proc, NULL);
    mmi_frm_group_enter(APP_MMS_POSTCARD, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_uc_p->srv_msg->msg_body.postcard_recipient_info.save_contact_cui_gid = cui_phb_save_contact_create(APP_MMS_POSTCARD);
    if(g_uc_p->srv_msg->msg_body.postcard_recipient_info.save_contact_cui_gid != GRP_ID_INVALID)
    {
        cui_phb_save_contact_set_data(g_uc_p->srv_msg->msg_body.postcard_recipient_info.save_contact_cui_gid, recipient_phb);
        cui_phb_save_contact_run(g_uc_p->srv_msg->msg_body.postcard_recipient_info.save_contact_cui_gid);
    }
    else
    {
        mmi_frm_group_close(APP_MMS_POSTCARD);
    }
    OslMfree(recipient_phb);
    mmi_frm_scrn_close(g_uc_p->main.uc_cui_gid, SCR_ID_POSTCARD_RECIPIENT_OPTION);
}

#ifdef __MMI_PHB_INFO_FIELD__


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_entry_to_option_save
 * DESCRIPTION
 *  Entry function of delete all query popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_postcard_entry_to_option_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_postcard_export_address_to_phonebook_manual();
}

#endif /* __MMI_PHB_INFO_FIELD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_export_address_to_phonebook_auto
 * DESCRIPTION
 *  Export function of recipients address data
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *  return 0: no need to export and no following screen
 *  return non-zero: how many recipients to export and start to PHB screens
 *****************************************************************************/
U8 mmi_postcard_export_address_to_phonebook_auto(void)
{
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 recipient_export = 0, i;
    srv_postcard_recipient_struct *index_recipient;
    srv_phb_contact_data_struct *recipient_phb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_POSTCARD_EXPORT_ADDRESS_TO_PHONEBOOK_AUTO);
    /*
     * After the user send postcard message, unified composer will always invoke this function to export address data.
     * After the user save postcard message to draft, unified composer will clear postcard context directly.
     */

    index_recipient = g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_head;
    for (i = 0; i < g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total; i++)
    {
        if (index_recipient->update)
        {
            recipient_export++;
        }
        index_recipient = index_recipient->next;
    }

    /* 1. check if need to export address data */
    if (recipient_export == 0 || mmi_phb_is_save_contact_notify_on() == MMI_FALSE)
    {
        srv_postcard_clear_all_context(g_uc_p->main.instance);  /* free all linked list address data from memory if no need to export */
        return 0;
    }

    /* 2. add address data into phonebook memory */
    index_recipient = g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_head;
    for (i = 0; i < g_uc_p->srv_msg->msg_body.postcard_recipient_info.recipient_total; i++)
    {
        if (index_recipient->update)
        {
            recipient_phb = (srv_phb_contact_data_struct *) OslMalloc (sizeof(srv_phb_contact_data_struct));
            memset(recipient_phb, 0, sizeof(srv_phb_contact_data_struct));
            mmi_phb_unsaved_data_init(recipient_phb);
            recipient_phb->name =(U16*) index_recipient->address.postcard_name;
            recipient_phb->extension = (U16*) index_recipient->address.postcard_additional;
            recipient_phb->street = (U16*) index_recipient->address.postcard_street;
            recipient_phb->city = (U16*) index_recipient->address.postcard_city;
            recipient_phb->state = (U16*) index_recipient->address.postcard_state;
            recipient_phb->postalcode = (U16*) index_recipient->address.postcard_postalcode;
            recipient_phb->country = (U16*) index_recipient->address.postcard_country;
            mmi_phb_add_data_to_unsaved_list(PHB_STORAGE_NVRAM, SRV_PHB_ENTRY_FIELD_NAME, recipient_phb);
            OslMfree(recipient_phb);
        }
        index_recipient = index_recipient->next;
    }

    /* 3. invoke phonebook application to export */
    mmi_phb_pre_entry_unsaved_data_confirm();

    srv_postcard_clear_all_context(g_uc_p->main.instance);  /* free all linked list address data from memory after add them to phonebook */

    return recipient_export;

#else /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

    srv_postcard_clear_all_context(g_uc_p->main.instance);
    return 0;

#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
}
#endif /* __MMI_PHB_INFO_FIELD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_return_menu_root_icon
 * DESCRIPTION
 *  Utility function to get root icon for postcard screen title
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_postcard_return_menu_root_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IMG_UC_ENTRY_SCRN_CAPTION_ID;
}

#ifdef __MMI_UC_POSTCARD_INTERNAL_TESTING__
#include "SimCtrlSrvGprot.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_postcard_get_mms_postcard_server_addr
 * DESCRIPTION
 *  Utility function to get root icon for postcard screen title
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
const kal_uint8 *mmi_postcard_get_mms_postcard_server_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 out_plmn_buffer[SRV_MAX_PLMN_LEN + 1] = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_nw_info_get_nw_plmn( MMI_SIM1, 
                               out_plmn_buffer,
                               SRV_MAX_PLMN_LEN + 1);
    if (memcmp(out_plmn_buffer, "460", 3) == 0)
    {
        return (const kal_uint8*)CN_MMS_POSTCARD_NUMBER;
    }

    if (memcmp(out_plmn_buffer, "404", 3) == 0 || memcmp(out_plmn_buffer, "405", 3) == 0)
    {
        return (const kal_uint8*)IN_MMS_POSTCARD_NUMBER;
    }

    return (const kal_uint8*)TW_MMS_POSTCARD_NUMBER;
}
#endif /* __MMI_UC_POSTCARD_INTERNAL_TESTING__ */ 

#endif /* __MMI_MMS_POSTCARD__ */ 
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UC_POSTCARD_APP_C */ 

#endif /* __MMI_TELEPHONY_SUPPORT__ */
