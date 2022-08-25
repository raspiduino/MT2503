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
 *  SmsAppCommonUI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application Common UI screen, 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "TimerEvents.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_sms_def.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "NotificationGprot.h"
#include "Wgui_categories.h"

#include "SmsAppProt.h"
#include "PhbCuiGprot.h"
#include "MessagesMiscell.h"
#include "UcmSrvGprot.h"
#include "MenucuiGprot.h"

typedef struct
{
    FuncPtr lsk_func;
    FuncPtr rsk_func;
} mmi_sms_confirm_data_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/


/**************************************************************
* Global Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static S16 process_body_str_id;
static U16 process_rsk_str_id;
static MMI_ID process_gid = GRP_ID_INVALID;


/**************************************************************
* Static Function Declaration
**************************************************************/
static void mmi_sms_exit_processing_generic(void);
static mmi_ret mmi_sms_confirm_display_hdlr(mmi_event_struct *evt);
static void mmi_sms_entry_confirm_internal(
        MMI_ID parent_id,
        U16 str_id,
        FuncPtr lsk_func,
        FuncPtr rsk_func,
        MMI_BOOL is_enable_csk,
        MMI_BOOL is_entry_history);

/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
* FUNCTION
*  mmi_sms_entry_confirm_generic
* DESCRIPTION
*  Set string and function for MSG confirmation screen
* PARAMETERS
*  id          [IN]         String ID 
*  lskfunc     [IN]         Right soft key function
*  rskfunc     [IN]         Left soft key function
* RETURNS
*  void
*****************************************************************************/
void mmi_sms_entry_confirm_generic(U16 text_id, FuncPtr lskfunc, FuncPtr rskfunc)
{
    mmi_sms_entry_confirm(GRP_ID_ROOT, text_id, lskfunc, rskfunc, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_confirm
 * DESCRIPTION
 *  Entry MSG generic confirmation screen group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_confirm(
        MMI_ID parent_id,
        U16 str_id,
        FuncPtr lsk_func,
        FuncPtr rsk_func,
        MMI_BOOL is_enable_csk)
{
    /* according to new UE rule, CSK is always be enabled */
    mmi_sms_entry_confirm_internal(
            parent_id,
            str_id,
            lsk_func,
            rsk_func,
            MMI_TRUE,
            MMI_FALSE);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_confirm_internal
 * DESCRIPTION
 *  Entry MSG generic confirmation screen group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_confirm_internal(
        MMI_ID parent_id,
        U16 str_id,
        FuncPtr lsk_func,
        FuncPtr rsk_func,
        MMI_BOOL is_enable_csk,
        MMI_BOOL is_entry_history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_sms_confirm_data_struct *confirm_data = OslMalloc(sizeof(mmi_sms_confirm_data_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_sms_confirm_display_hdlr;
    arg.parent_id = parent_id;
    arg.f_auto_map_empty_softkey = is_enable_csk;
    confirm_data->lsk_func = lsk_func;
    confirm_data->rsk_func = rsk_func;
    arg.user_tag = confirm_data;
    arg.f_enter_history = is_entry_history;
    mmi_confirm_display_ext(str_id, MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_confirm_enter_history
 * DESCRIPTION
 *  Entry MSG generic confirmation screen, if this screen is covered, will enter history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_confirm_enter_history(
        MMI_ID parent_id,
        U16 str_id,
        FuncPtr lsk_func,
        FuncPtr rsk_func,
        MMI_BOOL is_enable_csk)
{
    mmi_sms_entry_confirm_internal(
            parent_id,
            str_id,
            lsk_func,
            rsk_func,
            is_enable_csk,
            MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_confirm_sg
 * DESCRIPTION
 *  Entry MSG generic confirmation screen group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_confirm_sg(
        MMI_ID parent_id,
        U16 str_id,
        FuncPtr lsk_func,
        FuncPtr rsk_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_confirm(
        parent_id,
        str_id,
        lsk_func,
        rsk_func,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_confirm_sg_ext
 * DESCRIPTION
 *  Entry MSG generic confirmation screen group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_confirm_sg_ext(
        MMI_ID parent_id,
        WCHAR* text,
        FuncPtr lsk_func,
        FuncPtr rsk_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_sms_confirm_data_struct *confirm_data = OslMalloc(sizeof(mmi_sms_confirm_data_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_sms_confirm_display_hdlr;
    arg.parent_id = parent_id;
    confirm_data->lsk_func = lsk_func;
    confirm_data->rsk_func = rsk_func;
    arg.user_tag = confirm_data;
    
    mmi_confirm_display(text, MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_confirm_display_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alert_result    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_confirm_display_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*)evt;
    mmi_sms_confirm_data_struct *confirm_data = (mmi_sms_confirm_data_struct*) alert_result->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
            break;

        case EVT_ID_SCRN_DEINIT:
            break;

        case EVT_ID_ALERT_QUIT:
            switch (alert_result->result)
            {
        	    case MMI_ALERT_CNFM_YES:
                    (confirm_data->lsk_func)();
                    break;

                case MMI_ALERT_CNFM_NO:
                    (confirm_data->rsk_func)();
                    break;

                case MMI_ALERT_NORMAL_EXIT:
                case MMI_ALERT_INTERRUPT_EXIT:
                case MMI_ALERT_NO_SHOW:
                    if (confirm_data != NULL)
                    {
                        OslMfree(confirm_data);
                	    alert_result->user_tag = NULL;
                    }
                    break;

                default:
                    break;
            }
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_display_popupcallback_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *               
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_display_popupcallback_sg(
    MMI_ID parent_id,
    WCHAR* string,
    mmi_event_notify_enum event_id,
    mmi_proc_func receiver_proc,
    void *user_data,
    U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    WCHAR * title = string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.callback = receiver_proc;
    arg.user_tag = user_data;
    arg.parent_id = parent_id;

    if (GRP_ID_INVALID != mmi_popup_display(title, event_id, &arg))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  event_id    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_display_popup(UI_string_type text, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display((WCHAR*)text, event_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_display_popup_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  event_id    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_display_popup_ext(MMI_STR_ID title, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(title, event_id, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_nmgr_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  event_id    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_nmgr_display_popup(UI_string_type text, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, event_id,(WCHAR*)text);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_processing_generic
 * DESCRIPTION
 *  Exit MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_exit_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_processing_screen_sg
 * DESCRIPTION
 *  Set string and image for MSG processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_processing_screen_sg(mmi_id sms_gid, U16 bodyStrId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process_body_str_id = bodyStrId;
    process_rsk_str_id = rskStrId;
    process_gid = sms_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_processing_generic_time_out
 * DESCRIPTION
 *  Time out call back of processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_processing_generic_time_out_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_PROCESSING)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
    }

    mmi_frm_scrn_close(process_gid, SCR_ID_SMS_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_processing_generic_sg
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_processing_generic_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 process_image_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            process_gid,
            SCR_ID_SMS_PROCESSING,
            mmi_sms_exit_processing_generic,
            mmi_sms_entry_processing_generic_sg,
            MMI_FRM_FULL_SCRN))
    {
        process_image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
	#endif

        /*do not set title and title icon, otherwise processing screen will be a full screen*/
        ShowCategory8Screen(
            0,
            0,
            0,
            0,
            process_rsk_str_id,
            0,
            process_body_str_id,
            process_image_id,
            NULL);


        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        if (process_rsk_str_id == 0)
        {
            StartTimer(MESSAGES_INPROGRESS_TIMER_ID, MMI_SMS_PROGRESS_TIME_OUT, mmi_sms_processing_generic_time_out_sg);
        }

        if (process_rsk_str_id != 0)
        {
            //SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyDownHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW);
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);       
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_and_entry_processing_sg
 * DESCRIPTION
 *  Set string and image for MSG processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_and_entry_processing_sg(mmi_id sms_gid, U16 bodyStrId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_processing_screen_sg(sms_gid, bodyStrId, rskStrId);
    mmi_sms_entry_processing_generic_sg();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_menu_cui_options_generic
 * DESCRIPTION
 *  Go back two screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_menu_cui_options_generic(MMI_ID parent_gid, MMI_MENU_ID menu_id, U16 title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        parent_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        menu_id,
                        MMI_FALSE,
                        NULL);

    if (title_id != 0)
    {
        cui_menu_set_default_title_string_by_id(menu_cui_gid, title_id);
    }
#ifndef __MMI_SMS_SLIM__
    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SMS_ENTRY_SCRN_CAPTION);
#endif

    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_menu_cui_appsub_generic
 * DESCRIPTION
 *  Go back two screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_menu_cui_appsub_generic(MMI_ID parent_gid, MMI_MENU_ID menu_id, U16 title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        parent_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_APPSUB,
                        menu_id,
                        MMI_FALSE,
                        NULL);

    if (title_id != 0)
    {
        cui_menu_set_default_title_string_by_id(menu_cui_gid, title_id);
    }
#ifndef __MMI_SMS_SLIM__
    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SMS_ENTRY_SCRN_CAPTION);
#endif
    cui_menu_run(menu_cui_gid);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_save_number_to_phonebook
 * DESCRIPTION
 *  SMS save number to phonebook
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_sms_save_number_to_phonebook(MMI_ID parent_gid, U16* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID phb_gid = GRP_ID_INVALID;
    MMI_ID save_to_phb_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_gid = mmi_frm_group_create_ex(
                parent_gid,
                GRP_ID_AUTO_GEN,
                mmi_sms_save_to_phb_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

    save_to_phb_cui_id = cui_phb_save_contact_create(phb_gid);

    if (save_to_phb_cui_id != GRP_ID_INVALID)
    {
        cui_phb_save_contact_set_number(save_to_phb_cui_id, number);

        cui_phb_save_contact_run(save_to_phb_cui_id);
    }
    else
    {
        save_to_phb_cui_id = GRP_ID_INVALID;
        mmi_frm_group_close(phb_gid);
        phb_gid = GRP_ID_INVALID;
    }

    return phb_gid;
}


#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_save_email_to_phonebook
 * DESCRIPTION
 *  SMS save email to phonebook
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_save_email_to_phonebook(MMI_ID parent_gid, U16* email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID phb_gid;
    MMI_ID save_to_phb_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_gid = mmi_frm_group_create_ex(
                parent_gid,
                GRP_ID_AUTO_GEN,
                mmi_sms_save_to_phb_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

    save_to_phb_cui_id = cui_phb_save_contact_create(phb_gid);

    if (save_to_phb_cui_id != GRP_ID_INVALID)
    {
        cui_phb_save_contact_set_email(save_to_phb_cui_id, email);

        cui_phb_save_contact_run(save_to_phb_cui_id);
    }
    else
    {
        save_to_phb_cui_id = GRP_ID_INVALID;
        mmi_frm_group_close(phb_gid);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_save_to_phb_proc
 * DESCRIPTION
 *  SMS save number or email to phonebook proc function
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_save_to_phb_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            {
                mmi_group_event_struct *group_evt = (mmi_group_event_struct *)evt;
                cui_phb_save_contact_close(group_evt->sender_id);
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

