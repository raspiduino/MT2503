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
 *  mtvsmseditor.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  mtvsmseditor.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/************************************
 * Header Files Include
 **************************************************************/
#include "MMI_include.h"
#ifdef __ATV_SMS_SUPPORT__


#include "mtvsmsiprot.h"
#include "commonscreens.h"
#include "Wgui_ems.h"
#include "wgui_categories_inputs.h"
#include "Gui_inputs_internal.h"
#include "mmi_rp_app_sms_def.h"
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

/**************************************************************
 * Const define
 **************************************************************/

/**************************************************************
 * Global Variables Declaration
 **************************************************************/


/**************************************************************
 * Global Function Declaration
 **************************************************************/


/**************************************************************
 * Static Variables Defination
 **************************************************************/


/**************************************************************
 * Static Function Declaration
 **************************************************************/
static void mmi_mtv_sms_entry_editor(void);
static void mmi_mtv_sms_exit_editor(void);
static void mmi_mtv_sms_entry_editor_options(void);
static void mmi_mtv_sms_ed_send(void);
static void mmi_mtv_sms_save_to_drafts_background_callback(srv_sms_callback_struct *callback_data);
static U8 mmi_mtv_sms_editor_scrn_del_callback(void *dummy);


static void mmi_mtv_sms_save_to_drafts_bg_del_rsp(srv_sms_callback_struct * callback_data);
static void mmi_mtv_sms_save_to_drafts_background(void);
static void mmi_mtv_sms_ed_insert_temp(void);
static void mmi_mtv_sms_ed_insert_name(void);

static void mmi_mtv_sms_ed_insert_number(void);
static void mmi_mtv_sms_ed_save(void);

static void mmi_mtv_sms_insert_text(S8* text_buff);
static MMI_BOOL mmi_mtv_sms_insert_text_to_editor(S8* text_buff);
static void mmi_mtv_sms_editor_delete_callback(srv_sms_callback_struct* callback_data);
static void mmi_mtv_sms_editor_pre_save(void);
static void mmi_mtv_sms_editor_save_handle(srv_sms_callback_struct *callback_data);
static void mmi_mtv_sms_editor_save_msg_req(SrvSmsCallbackFunc callback_func);
static void mmi_mtv_sms_editor_save(void);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static MMI_BOOL mmi_mtv_sms_is_ems_content_empty(EMSData *ems_data);
static void mmi_mtv_msg_ems_remove_escape_char(EMSData *pEms);
static void mmi_mtv_msg_ems_add_escape_char(EMSData *pEms);
static MMI_BOOL mmi_mtv_msg_ems_need_add_or_remove_escape_char(EMSData *pEms);
static void mmi_mtv_sms_get_number_from_phb(U16 index);
static void mmi_mtv_sms_get_name_from_phb(U16 index);

/**************************************************************
 * Function Definition
 **************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_pre_entry_editor
 * DESCRIPTION
 *  Pre-Entry SMS/EMS Editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_pre_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_mtv_sms_display_popup(
            (STR_ID_MTV_SMS_NOT_AVAIABLE),
            MMI_MTV_SMS_NOTIFY_FAILURE);
    }
    else
   	{
        EMSData *pEMS;
        MtvGetEMSDataForEdit(&pEMS, 0);
        if (pEMS)
        {
            if (pEMS->dcs == SMSAL_DEFAULT_DCS)
            {
                if (mmi_mtv_msg_ems_need_add_or_remove_escape_char(pEMS) == MMI_TRUE)
                {
                    mmi_mtv_msg_ems_remove_escape_char(pEMS);
                    mmi_mtv_msg_ems_add_escape_char(pEMS);
                }
            }
            mmi_mtv_sms_set_is_recipient_modify(MMI_FALSE);
            mmi_mtv_sms_set_is_sent_false();
            g_mtv_sms_cntx.sim_id = SRV_SMS_SIM_1;
            mmi_mtv_sms_entry_editor();
        }
        else
        {
            mmi_mtv_sms_display_popup(STR_ID_MTV_SMS_NOT_AVAIABLE, MMI_MTV_SMS_NOTIFY_FAILURE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_editor
 * DESCRIPTION
 *  Entry SMS/EMS editor Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    EMSData *ems_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTV_SMS_EDITOR, mmi_mtv_sms_exit_editor, mmi_mtv_sms_entry_editor, NULL);

    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);
    
    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_MTV_SMS_EDITOR;
    
   /* AlmDisableSPOF(); */
    gui_buffer = GetCurrGuiBuffer(SCR_ID_MTV_SMS_EDITOR);
   
    if (srv_sms_is_sms_valid())
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
    }
    MtvGetEMSDataForEdit(&ems_data, 0);
    MMI_ASSERT(ems_data);
    wgui_cat9006_show(
        (WCHAR *)(get_string(STR_ID_MTV_SMS_MAIN_WRITE_MESSAGE)),
        (WCHAR *)(get_string(STR_GLOBAL_OPTIONS)),
        NULL,
        (WCHAR *)(get_string(STR_GLOBAL_BACK)),
        NULL,
        IMM_INPUT_TYPE_SENTENCE ,
        ems_data,
        gui_buffer,
        NULL);
    /* RegisterInputMethodScreenCloseFunction(GoBackHistory); */
    SetCategory28RightSoftkeyFunction(mmi_mtv_sms_scrn_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_mtv_sms_entry_editor_options, KEY_EVENT_UP);
    if (srv_sms_is_sms_valid())
    {
        SetCenterSoftkeyFunction(mmi_mtv_sms_ed_send, KEY_EVENT_UP);
    }
    SetDelScrnIDCallbackHandler(
        SCR_ID_MTV_SMS_EDITOR,
        (HistoryDelCBPtr)mmi_mtv_sms_editor_scrn_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_editor_options
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_editor_options(void)
{
    if (!srv_sms_is_sms_valid())
    {
        mmi_frm_hide_menu_item(MENU_ID_MTV_SMS_EDITOR_SEND);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_MTV_SMS_EDITOR_SEND);
    }
    mmi_mtv_sms_entry_common_options(SCR_ID_MTV_SMS_EDITOR_OPTIONS, MENU_ID_MTV_SMS_EDITOR_ROOT);
}


#ifdef  __MMI_MESSAGES_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_option_insert_template_hilite
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen set hilite insert template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_editor_option_insert_template_hilite(void)
{
    
    SetLeftSoftkeyFunction(mmi_mtv_sms_ed_insert_temp, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_ed_insert_temp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_ed_insert_temp
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen insert template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_ed_insert_temp(void)
{
    mmi_mtv_sms_register_get_template_callback(mmi_mtv_sms_insert_text);
    mmi_mtv_sms_entry_template_list();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_option_insert_name_hilite
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen set hilite insert name from phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_editor_option_insert_name_hilite(void)
{
    
    SetLeftSoftkeyFunction(mmi_mtv_sms_ed_insert_name, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_ed_insert_name, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_option_insert_name_hilite
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen insert name from phb entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_ed_insert_name(void)
{
    if (mmi_matv_sms_entry_phb_list_group((MMI_MTV_SMS_PHB_NAME_REQ)))
    {
        mmi_matv_sms_register_phb_list_callback(mmi_mtv_sms_get_name_from_phb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_get_name_from_phb
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen insert name from phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_get_name_from_phb(U16 index)
{
    U16 temp_buff[MMI_PHB_NAME_LENGTH + 1];
    srv_phb_get_name(index, temp_buff , MMI_PHB_NAME_LENGTH);
    if (!mmi_mtv_sms_insert_text_to_editor((S8*)temp_buff))
    {
        mmi_mtv_sms_display_popup(
            (STR_NO_SPACE_TO_INSERT_OBJECT),
            MMI_MTV_SMS_NOTIFY_FAILURE);
    }
    mmi_matv_sms_phb_list_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_option_insert_number_hilite
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen hilite insert number from phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_editor_option_insert_number_hilite(void)
{
    
    SetLeftSoftkeyFunction(mmi_mtv_sms_ed_insert_number, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_ed_insert_number, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_ed_insert_number
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen hilite insert number from phb entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_ed_insert_number(void)
{
    if (mmi_matv_sms_entry_phb_list_group((MMI_MTV_SMS_PHB_NUMBER_REQ)))
    {
        mmi_matv_sms_register_phb_list_callback(mmi_mtv_sms_get_number_from_phb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_ed_insert_number
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen insert number from phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_get_number_from_phb(U16 index)
{
    U16 temp_buff[MMI_PHB_NUMBER_LENGTH + 1];
    srv_phb_get_number(index, temp_buff , MMI_PHB_NUMBER_LENGTH);
    if (!mmi_mtv_sms_insert_text_to_editor((S8*)temp_buff))
    {
        mmi_mtv_sms_display_popup(
            (STR_NO_SPACE_TO_INSERT_OBJECT),
            MMI_MTV_SMS_NOTIFY_FAILURE);
    }
    mmi_matv_sms_phb_list_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_option_save_hilite
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen hilite save 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_editor_option_save_hilite(void)
{
    
    SetLeftSoftkeyFunction(mmi_mtv_sms_ed_save, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_ed_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_ed_save
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen save 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_ed_save(void)
{
    mmi_mtv_sms_editor_pre_save();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_option_send_hilite
 * DESCRIPTION
 *  SMS/EMS Editor Options Screen send hilite 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_editor_option_send_hilite(void)
{
    SetLeftSoftkeyFunction(mmi_mtv_sms_ed_send, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_mtv_sms_ed_send, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mtv_mmi_sms_ed_opt_input_method_hilite
 * DESCRIPTION
 *  Hilite input method 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mtv_mmi_sms_ed_opt_input_method_hilite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(0);
    EntryInputMethodScreen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_exit_editor
 * DESCRIPTION
 *  Exit SMS/EMS editor Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_exit_editor(void)
{
    ResetCenterSoftkey();
    mmi_mtv_sms_common_screen_exit();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_scrn_del_callback
 * DESCRIPTION
 *  SMS/EMS Editor Screen Delete Callback Function
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_mtv_sms_editor_scrn_del_callback(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *ems_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AlmEnableSPOF(); */
    
    kal_prompt_trace(MOD_MMI, "mmi_mtv_sms_editor_scrn_del_callback() ems_data = %d", g_mtv_sms_cntx.edit_ems_data);
    if(g_mtv_sms_cntx.edit_ems_data)
    {
        MtvGetEMSDataForEdit(&ems_data, 0);
        MMI_ASSERT(ems_data);
        if(mmi_mtv_sms_get_is_sent() == MMI_TRUE)
        {
            MTVReleaseEMSEditBuffer();
            mmi_mtv_sms_reset_recipient_data();
        }
        else if (mmi_mtv_sms_is_ems_content_empty(ems_data) == MMI_FALSE)
        {
            mmi_mtv_sms_send_case_enum send_case = mmi_mtv_sms_get_send_msg_case();
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
        
           if ((send_case == MTV_SMS_SEND_CASE_EDIT_DRAFT)
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
            )
            {
                srv_sms_delete_msg(
                    g_mtv_sms_cntx.curr_msg_id,
                    mmi_mtv_sms_save_to_drafts_bg_del_rsp,
                    NULL);
            }
            else
            {
                mmi_mtv_sms_save_to_drafts_background();
            }

    	    return MMI_FALSE;
        }
        else
        {
            MTVReleaseEMSEditBuffer();
        }
    }
    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_is_ems_content_empty
 * DESCRIPTION
 *  Check whether the EMS Data is empty
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_mtv_sms_is_ems_content_empty(EMSData *ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_mtv_sms_is_ems_content_empty() ems_data = %d", ems_data);
    if ((ems_data->textLength == 0) && (ems_data->listHead == NULL))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
    kal_prompt_trace(MOD_MMI, "mmi_mtv_sms_is_ems_content_empty() result = %d", result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_ed_send
 * DESCRIPTION
 *  The Editor CSK Handler Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_ed_send(void)
{
    mmi_mtv_sms_edit_send_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_save_to_drafts_bg_del_rsp
 * DESCRIPTION
 *  Delete the Edited Drafts's Msg Background Response
 * PARAMETERS
 *  data        [IN]    Dummy
 *  mod         [IN]    Module Type
 *  result      [IN]    SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_save_to_drafts_bg_del_rsp(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback_data->result == MMI_TRUE)
    {
        mmi_mtv_sms_save_to_drafts_background();
    }
    else
    {
        srv_sms_callback_struct data;
        data.result = MMI_FALSE;
        mmi_mtv_sms_save_to_drafts_background_callback(&data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_save_to_drafts_background_callback
 * DESCRIPTION
 *  Callback Function Of Save message in the editor to drafts background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_save_to_drafts_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE sms_handle;
    MMI_BOOL is_sim1_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "mmi_mtv_sms_save_to_drafts_background ems_data = %d", g_mtv_sms_cntx.edit_ems_data);
    if (g_mtv_sms_cntx.edit_ems_data)
    {
        sms_handle = srv_sms_get_save_handle();

        srv_sms_set_status(sms_handle, SRV_SMS_STATUS_DRAFT);

        is_sim1_valid = srv_sim_ctrl_is_available(MMI_SIM1);
        /* The default SIM is SIM1 */
        if (is_sim1_valid == MMI_TRUE)
        {
            srv_sms_set_sim_id(sms_handle, SRV_SMS_SIM_1);
        }
        else
        {
            srv_sms_set_sim_id(sms_handle, SRV_SMS_SIM_2);
        }

        srv_sms_set_content_ems(sms_handle, g_mtv_sms_cntx.edit_ems_data);

        srv_sms_save_msg(sms_handle, mmi_mtv_sms_save_to_drafts_background_callback, NULL);
   }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_save_to_drafts_background_callback
 * DESCRIPTION
 *  result process Function Of Save message in the editor to drafts background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_save_to_drafts_background_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTVReleaseEMSEditBuffer();
    mmi_mtv_sms_reset_recipient_data();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_insert_text
 * DESCRIPTION
 *  insert text to ems data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_insert_text(S8* text_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_mtv_sms_insert_text_to_editor(text_buff);

    GoBackToHistory(SCR_ID_MTV_SMS_EDITOR);
    if (result == MMI_FALSE)
    {
        mmi_mtv_sms_display_popup(
                (STR_NO_SPACE_TO_INSERT_OBJECT),
                MMI_MTV_SMS_NOTIFY_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_insert_text_to_editor
 * DESCRIPTION
 *  Insert Text to the SMS Editor
 * PARAMETERS
 *  text_buff       [IN] the Input Text Buffer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_mtv_sms_insert_text_to_editor(S8* text_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 char_num;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    char_num = (U16)mmi_ucs2strlen(text_buff);

    if (char_num > 0)
    {
        EMSData *pEMS;
        history temp_history;
        historyNode *cat28_history;
        MMI_BOOL is_ucs2_char;
        U8 append_result;
        S8 *insert_ucs2_buff = NULL;
        
        memset(&temp_history, 0, sizeof(history));
        GetHistory(SCR_ID_MTV_SMS_EDITOR, &temp_history);

        pEMS = MtvGetEMSDataForEdit(0, 0);
    
        if (pEMS->dcs == SMSAL_UCS2_DCS)
        {
            is_ucs2_char = MMI_TRUE;
        }
        else
        {
            is_ucs2_char = srv_sms_check_ucs2(text_buff, char_num);
        }

        if (is_ucs2_char == MMI_FALSE)
        {
            insert_ucs2_buff = OslMalloc((char_num * 2 + 1) * ENCODING_LENGTH);
            srv_sms_add_escape_char(insert_ucs2_buff, text_buff, char_num);
        }
        else
        {
            insert_ucs2_buff = text_buff;
        }

        append_result = AppendCategory28String(
                            IMM_INPUT_TYPE_SENTENCE,
                            pEMS,
                            (U8*)insert_ucs2_buff,
                            temp_history.guiBuffer);

        if (append_result == 0)
        {
            result = MMI_FALSE;
        }

        if (GetHistoryScrID(SCR_ID_MTV_SMS_EDITOR, &cat28_history) == ST_SUCCESS)
        {
            S32 size = wgui_cat9006_get_history_size();
            memcpy(cat28_history->guiBuffer, temp_history.guiBuffer, size);
        }

        if (is_ucs2_char == MMI_FALSE)
        {
            OslMfree(insert_ucs2_buff);
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_EDITOR_INSERT, char_num, pEMS->dcs, result);
    }
    return result;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_delete_callback
 * DESCRIPTION
 *  Send Msg Request
 * PARAMETERS
 *  callback_data        [IN]    result Data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_editor_delete_callback(srv_sms_callback_struct* callback_data)
{
    MMI_BOOL delete_result = callback_data->result;
    if (delete_result)
    {
        mmi_mtv_sms_editor_save_msg_req(mmi_mtv_sms_editor_save_handle);
    }
    else
    {
        mmi_mtv_sms_display_popup((STR_GLOBAL_FAILED_TO_SAVE), MMI_MTV_SMS_NOTIFY_FAILURE);
        mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_SAVING);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_pre_save
 * DESCRIPTION
 *  Send Msg Request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_editor_pre_save(void)
{

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else
    g_mtv_sms_cntx.sim_id = SRV_SMS_SIM_1;
    mmi_mtv_sms_editor_save();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_pre_save
 * DESCRIPTION
 *  Save Msg Request delete older one if needed
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_editor_save(void)
{
    mmi_mtv_sms_pre_entry_processing_screen(
        SCR_ID_MTV_SMS_POPUP_SAVING,
        0,
        0, 
        NULL, 
        0, 
        NULL, 
        STR_GLOBAL_SAVING);
    if ((MTV_SMS_SEND_CASE_EDIT_DRAFT == mmi_mtv_sms_get_send_msg_case()) &&
        (srv_sms_get_msg_sim_id(g_mtv_sms_cntx.curr_msg_id) == g_mtv_sms_cntx.sim_id))
    {
        srv_sms_delete_msg(g_mtv_sms_cntx.curr_msg_id, mmi_mtv_sms_editor_delete_callback, NULL);
    }
    else
    {
        mmi_mtv_sms_editor_save_msg_req(mmi_mtv_sms_editor_save_handle);
    }
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_save_handle
 * DESCRIPTION
 *  Send Msg Request
 * PARAMETERS
 *  callback_data        [IN]    save result Data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_editor_save_handle(srv_sms_callback_struct *callback_data)
{
    
    MMI_BOOL save_result = callback_data->result;
    srv_sms_cause_enum cause = callback_data->cause;
    
    if (save_result) /* send */
    {
        mmi_mtv_sms_set_is_sent_true();
        mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_EDITOR);
        mmi_mtv_sms_display_popup((STR_GLOBAL_SAVED), MMI_MTV_SMS_NOTIFY_OK);
    }
    else /* send failed */
    {
        switch (cause)
        {
            case SRV_SMS_CAUSE_MEM_FULL:
            {
                mmi_mtv_sms_display_popup(
                    (STR_GLOBAL_MEMORY_FULL),
                    MMI_MTV_SMS_NOTIFY_FAILURE);
                break;
            }

            case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
            {
                mmi_mtv_sms_display_popup(
                    (STR_GLOBAL_NOT_ENOUGH_MEMORY),
                    MMI_MTV_SMS_NOTIFY_FAILURE);
                break;
            }

            case SRV_SMS_CAUSE_NOT_READY:
            {
                mmi_mtv_sms_display_popup(
                    (STR_ID_MTV_SMS_NOT_AVAIABLE),
                    MMI_MTV_SMS_NOTIFY_FAILURE);
                break;
            }

            case SRV_SMS_CAUSE_NUMBER_INVALID:
            {
                mmi_mtv_sms_display_popup(
                    (STR_GLOBAL_INVALID_NUMBER),
                    MMI_MTV_SMS_NOTIFY_FAILURE);
                break;
            }

            case SRV_SMS_CAUSE_DATA_INVALID:
            {
                mmi_mtv_sms_display_popup(
                    (STR_GLOBAL_FAILED_TO_SAVE),
                    MMI_MTV_SMS_NOTIFY_FAILURE);
                break;
            }

            case SRV_SMS_CAUSE_DATA_EXCEED:
            {
                mmi_mtv_sms_display_popup(
                    (STR_GLOBAL_FAILED_TO_SAVE),
                    MMI_MTV_SMS_NOTIFY_FAILURE);
                break;
            }

            case SRV_SMS_CAUSE_SC_EMPTY:
            {
                mmi_mtv_sms_display_popup(
                    (STR_ID_MTV_SMS_EMPTY_SC),
                    MMI_MTV_SMS_NOTIFY_FAILURE);
                break;
            }

            default:
            {
                mmi_mtv_sms_display_popup(
                    (STR_GLOBAL_FAILED_TO_SAVE),
                    MMI_MTV_SMS_NOTIFY_FAILURE);
                break;
            }
        }
    } 
    mmi_mtv_sms_scrn_close(SCR_ID_MTV_SMS_POPUP_SAVING);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_editor_save_msg_req
 * DESCRIPTION
 *  Send Msg Request
 * PARAMETERS
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_editor_save_msg_req(SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE srv_save_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_save_handle = srv_sms_get_save_handle();
    srv_sms_set_status(srv_save_handle, SRV_SMS_STATUS_DRAFT);
    srv_sms_set_content_ems(srv_save_handle, (void*)g_mtv_sms_cntx.edit_ems_data);
    srv_sms_set_sim_id(srv_save_handle, g_mtv_sms_cntx.sim_id);
    srv_sms_save_msg(srv_save_handle, callback_func, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_msg_ems_remove_escape_char
 * DESCRIPTION
 *  remove the escape char in the EMS data
 * PARAMETERS
 *  pEms        [IN]    EMSData
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_msg_ems_remove_escape_char(EMSData *pEms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pEms->textLength > 0)
    {
        U16 c;
        U16 OffsetToText;
        U8 *textBuffer = pEms->textBuffer;
        U16 textBufferLength = pEms->textLength;

        ResetCurrentPosition(pEms);

        while ((OffsetToText = pEms->CurrentPosition.OffsetToText) < textBufferLength)
        {
        #if (EMS_BYTE_ORDER_BIG_ENDIAN)
            c = (U16)(textBuffer[OffsetToText + 1] | (textBuffer[OffsetToText] << 8));
        #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */
            c = (U16)(textBuffer[OffsetToText] | (textBuffer[OffsetToText + 1] << 8));
        #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */
        
            if (c == EMS_ESCAPE_CHARACTER)
            {
                EMSPosition dummyposition;
                U16 ret_char;
                EMSObject *ret_object;

                dummyposition = pEms->CurrentPosition;

                while (EMSGetNextObject(pEms, &dummyposition, &ret_char, &ret_object) == 2)
                {
                    ForwardCurrentPosition(pEms, 1);
                    dummyposition = pEms->CurrentPosition;

                    if (ret_object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        if (EMSGetPreviousObject(pEms, &dummyposition, &ret_char, &ret_object) == 1)
                        {
                            BackwardCurrentPosition(pEms, 1);
                            break;
                        }

                        dummyposition = pEms->CurrentPosition;
                    }
                }

            #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                if (ForwardCurrentPosition(pEms, 1) != 1)
                {
                    break;
                }

                CancelCurrentPosition(pEms, 1);

                OffsetToText = pEms->CurrentPosition.OffsetToText;
                textBufferLength -= ENCODING_LENGTH;
            #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                if (ForwardCurrentPosition(pEms, 1) != 1)
                {
                    break;
                }

                CancelCurrentPosition(pEms, 1);

                c = (U16)(textBuffer[pEms->CurrentPosition.OffsetToText] | (textBuffer[pEms->CurrentPosition.OffsetToText + 1] << 8));
                
                OffsetToText = pEms->CurrentPosition.OffsetToText;
                textBufferLength -= ENCODING_LENGTH;
            #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            }
            
            if (ForwardCurrentPosition(pEms, 1) != 1)
            {
                break;
            }
        }
        GoToEndPosition(pEms);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_msg_ems_add_escape_char
 * DESCRIPTION
 *  Add the escape char to the EMS data
 * PARAMETERS
 *  pEms        [IN]    EMSData
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_msg_ems_add_escape_char(EMSData *pEms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pEms->textLength > 0)
    {
        U16 c;
        U16 OffsetToText;
        U8 *textBuffer = pEms->textBuffer;
        U16 textBufferLength = pEms->textLength;
		EMSTextFormat *txt_fmt_p = NULL;
		EMSObject *ret_object;
		EMSPosition dummyposition; 
		U16 ret_char;
		U16 curr_object_offset = 0;
		U16 curr_object_len = 0;

        ResetCurrentPosition(pEms);

        while ((OffsetToText = pEms->CurrentPosition.OffsetToText) < textBufferLength)
        {
        #if (EMS_BYTE_ORDER_BIG_ENDIAN)
            c = (U16)(textBuffer[OffsetToText + 1] | (textBuffer[OffsetToText] << 8));
        #else /* EMS_BYTE_ORDER_BIG_ENDIAN */
            c = (U16)(textBuffer[OffsetToText] | (textBuffer[OffsetToText + 1] << 8));
        #endif /* EMS_BYTE_ORDER_BIG_ENDIAN */

			dummyposition = pEms->CurrentPosition;
			if (EMSGetNextObject(pEms, &dummyposition, &ret_char, &ret_object) == 2)
			{
				curr_object_offset = dummyposition.OffsetToText;
				curr_object_len = dummyposition.Object->data->text_format.textLength;
			}
            if (mmi_7bit_check_gsm_ext_character(c))
            {
                EMSTextFormat txt_fmt;
                U8 ret = EMS_OK;
            #if (EMS_BYTE_ORDER_BIG_ENDIAN)
                U8 ESC_string[] = {0x00, 0x1B};
            #else /* EMS_BYTE_ORDER_BIG_ENDIAN */
                U8 ESC_string[] = {0x1B, 0x00};
            #endif /* EMS_BYTE_ORDER_BIG_ENDIAN */

                dummyposition = pEms->CurrentPosition;
        		if (curr_object_offset + curr_object_len <= pEms->CurrentPosition.OffsetToText)
				{
					ResetTextFormat(&txt_fmt);
					txt_fmt_p = &txt_fmt;
				}			
                
                while (EMSGetNextObject(pEms, &dummyposition, &ret_char, &ret_object) == 2)
                {
                    ForwardCurrentPosition(pEms, 1);
                    dummyposition = pEms->CurrentPosition;

                    if (ret_object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        if (EMSGetPreviousObject(pEms, &dummyposition, &ret_char, &ret_object) == 1)
                        {
                            if (pEms->CurrentTextFormatObj)
                            {
                                txt_fmt = pEms->CurrentTextFormatObj->data->text_format;
                                txt_fmt.textLength = 2;
                                txt_fmt_p = &txt_fmt;
                            }

                            BackwardCurrentPosition(pEms, 1);
                            break;
                        }

                        dummyposition = pEms->CurrentPosition;
                    }
                }

                ret = AddString(pEms, ESC_string, 1, txt_fmt_p);

                if (ret != EMS_OK)
                {
                    EMSPosition add_position;

                    add_position = pEms->CurrentPosition;

                    ForwardCurrentPosition(pEms, 1);

                    dummyposition = pEms->CurrentPosition;

                    //If it is the last character, remove it.
                    if (EMSGetNextObject(pEms, &dummyposition, &ret_char, &ret_object) == 0)
                    {
                        CancelCurrentPosition(pEms, 1);
                    }
                    else
                    {
                        GoToEndPosition(pEms);
                        CancelCurrentPosition(pEms, 1);
                        MoveCursorToPosition(pEms, &add_position);
                        ret = AddString(pEms, ESC_string, 1, txt_fmt_p);

                        if (ret != EMS_OK)
                        {
                            break;
                        }
                    }
                }

                OffsetToText = pEms->CurrentPosition.OffsetToText;

                textBufferLength = pEms->textLength;
            }

            if (ForwardCurrentPosition(pEms, 1) != 1)
            {
                break;
            }
        }

        GoToEndPosition(pEms);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_msg_ems_need_add_or_remove_escape_char
 * DESCRIPTION
 *  Check whether the ems data have unused escape char or add escape char
 * PARAMETERS
 *  pEms        [IN]    EMSData
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_mtv_msg_ems_need_add_or_remove_escape_char(EMSData *pEms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *text_buff = (U16*)pEms->textBuffer;
    U16 char_num = pEms->textLength / ENCODING_LENGTH;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < char_num)
    {
        U16 c = text_buff[i++];

        if (c == EMS_ESCAPE_CHARACTER)
        {
            c = text_buff[i++];

            //Unused escape character, need to remove
            if (!mmi_7bit_check_gsm_ext_character(c))
            {
                return MMI_TRUE;
            }
        }
        else
        {
            //Need to add a escape character
            if (mmi_7bit_check_gsm_ext_character(c))
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}


#endif /*  _MMI_ATV_SMS_SUPPORT__ */
