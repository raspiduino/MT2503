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
 *  SmsAppEms.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application relative EMS Handler, 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_SMS_APP_EMS_SUPPORT__

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "SmsAppEms.h"
#include "EmsMiscell.h"
#include "mmi_rp_app_sms_def.h"
#include "MessagesExDcl.h"
#include "wgui_ems.h"
#include "ems.h"
#include "MenuCuiGprot.h"
#include "FileMgrCuiGProt.h"
#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_rp_file_type_def.h"
#include "SmsSrvGprot.h"
#include "CustMenuRes.h"
#include "SmsAppProt.h"


/**************************************************************
* Global Variables Declaration
**************************************************************/

/**************************************************************
* Global Function Declaration
**************************************************************/

/**************************************************************
* Static Variables Defination
**************************************************************/
static MMI_ID mmi_ems_gid = GRP_ID_INVALID;
static MMI_MENU_ID highlighted_menu_id;

/**************************************************************
* Extern Function Declaration
**************************************************************/

/**************************************************************
* Static Function Declaration
**************************************************************/
static mmi_ret mmi_ems_group_proc(mmi_event_struct *evt);

/**************************************************************
* Function Defination
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ems_insert_object_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_insert_object_entry_hdlr(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_FILE_MANAGER__)
    cui_menu_set_item_hidden(menu_gid, EMS_INS_OBJ_MY_PICTURE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, EMS_INS_OBJ_MY_ANIMATION, MMI_TRUE);
#if defined(__MMI_IMELODY_SUPPORT__)
    cui_menu_set_item_hidden(menu_gid, EMS_INS_OBJ_MY_MELODY, MMI_TRUE);
#endif /* defined(__MMI_IMELODY_SUPPORT__) */
#endif /* defined(__MMI_FILE_MANAGER__) */

    cui_menu_set_currlist_flags(menu_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_insert_object_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_insert_object_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ems_set_group_id(mmi_ems_gid);

    switch ((menu_evt->highlighted_menu_id))
    {
        case MENU_ID_SMS_EMS_PICTURE:
            mmi_msg_entry_ems_picture();
            break;

        case MENU_ID_SMS_EMS_MY_PICTURE:
            mmi_msg_entry_ems_my_picture();
            break;

        case MENU_ID_SMS_EMS_PREDEF_ANIMATION:
            mmi_msg_entry_ems_predef_animation();
            break;

        case MENU_ID_SMS_EMS_MY_ANIMATION:
            mmi_msg_entry_ems_my_animation();
            break;

    #ifdef __MMI_IMELODY_SUPPORT__
        case MENU_ID_SMS_EMS_MELODY:
            mmi_msg_entry_ems_melody();
            break;

        case MENU_ID_SMS_EMS_MY_MELODY:
            mmi_msg_entry_ems_my_melody();
            break;
    #endif /* __MMI_IMELODY_SUPPORT__ */

        case MENU_ID_SMS_EMS_PREDEF_SOUND:
            mmi_msg_entry_ems_predef_sound();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


#ifndef __MMI_TEXT_FORMAT_WITHOUT_SIZE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_size_pre_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_text_size_pre_entry_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_menu_cui_appsub_generic(
        mmi_ems_gid,
        MENU_ID_SMS_EMS_TEXT_SIZE,
        STR_EMS_TEXT_SIZE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_size_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_size_entry_hdlr(MMI_ID menu_gid, MMI_BOOL is_from_history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(cui_menu_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    if (is_from_history)
    {
        cui_menu_set_radio_list_item(cui_menu_gid, highlighted_menu_id);
    }
    else
    {   
        MMI_MENU_ID hilite_menu_id = MENU_ID_SMS_EMS_TEXT_SIZE_NORMAL;

        switch (EMS_inputbox_get_text_size())
        {
            case EMS_FONTSIZE_SMALL:
                hilite_menu_id = MENU_ID_SMS_EMS_TEXT_SIZE_SMALL;
                break;

            case EMS_FONTSIZE_NORMAL:
                hilite_menu_id = MENU_ID_SMS_EMS_TEXT_SIZE_NORMAL;
                break;
                
        #ifndef __MMI_DIALLING_FONT__
            case EMS_FONTSIZE_LARGE:
                hilite_menu_id = MENU_ID_SMS_EMS_TEXT_SIZE_LARGE;
                break;
        #endif /* MENU_ID_SMS_EMS_TEXT_SIZE_LARGE */

            default:
                hilite_menu_id = MENU_ID_SMS_EMS_TEXT_SIZE_SMALL;
                break;
        }
        cui_menu_set_radio_list_item(cui_menu_gid, hilite_menu_id);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_size_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_size_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((menu_evt->highlighted_menu_id))
    {
        case MENU_ID_SMS_EMS_TEXT_SIZE_SMALL:
            EMS_inputbox_set_text_size(EMS_FONTSIZE_SMALL);
            break;

        case MENU_ID_SMS_EMS_TEXT_SIZE_NORMAL:
            EMS_inputbox_set_text_size(EMS_FONTSIZE_NORMAL);
            break;

    #ifndef __MMI_DIALLING_FONT__
        case MENU_ID_SMS_EMS_TEXT_SIZE_LARGE:
            EMS_inputbox_set_text_size(EMS_FONTSIZE_LARGE);
            break;
    #endif /* MENU_ID_SMS_EMS_TEXT_SIZE_LARGE */

        default:
            break;
    }

    mmi_frm_group_close(mmi_ems_gid);
    return MMI_RET_OK;
}
#endif /* __MMI_TEXT_FORMAT_WITHOUT_SIZE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_style_pre_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_text_style_pre_entry_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_menu_cui_appsub_generic(
        mmi_ems_gid,
        MENU_ID_SMS_EMS_TEXT_STYLE,
        STR_EMS_TEXT_STYLE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_style_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_style_entry_hdlr(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_gid;
    U8 list_of_states[4] = {0, 0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TEXT_FORMAT_WITHOUT_BOLD__
    EMS_inputbox_get_text_style(
        &list_of_states[0],
        &list_of_states[1],
        &list_of_states[2],
        &list_of_states[3]);
#else /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 
    EMS_inputbox_get_text_style(
        &list_of_states[3],
        &list_of_states[0],
        &list_of_states[1],
        &list_of_states[2]);
#endif /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 

    cui_menu_set_currlist_flags(cui_menu_gid, CUI_MENU_NORMAL_CHECK_BOX_LIST);

    cui_menu_set_checkbox_state(cui_menu_gid, list_of_states);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_style_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_style_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 list_of_states[4] = {0, 0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_get_checkbox_state(menu_evt->sender_id, list_of_states);

#ifndef __MMI_TEXT_FORMAT_WITHOUT_BOLD__
    EMS_inputbox_set_text_style(
        list_of_states[0],
        list_of_states[1],
        list_of_states[2],
        list_of_states[3]);
#else /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 
    EMS_inputbox_set_text_style(
        list_of_states[3],
        list_of_states[0],
        list_of_states[1],
        list_of_states[2]);
#endif /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */

    mmi_frm_group_close(mmi_ems_gid);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_size_pre_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_text_alignment_pre_entry_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_menu_cui_appsub_generic(
        mmi_ems_gid,
        MENU_ID_SMS_EMS_ALIGNMENT,
        STR_EMS_ALIGNMENT_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_alignment_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_alignment_entry_hdlr(MMI_ID menu_gid, MMI_BOOL is_from_history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(cui_menu_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    if (is_from_history)
    {
        cui_menu_set_radio_list_item(cui_menu_gid, highlighted_menu_id);
    }
    else
    {   
        MMI_MENU_ID hilite_menu_id = MENU_ID_SMS_EMS_ALIGNMENT_AUTOMATIC;

        switch (EMS_inputbox_get_text_alignment())
        {
            case EMS_ALIGN_LANG_DEP:
                hilite_menu_id = MENU_ID_SMS_EMS_ALIGNMENT_AUTOMATIC;
                break;

            case EMS_ALIGN_LEFT:
                hilite_menu_id = MENU_ID_SMS_EMS_ALIGNMENT_LEFT;
                break;
                
            case EMS_ALIGN_CENTER:
                hilite_menu_id = MENU_ID_SMS_EMS_ALIGNMENT_CENTER;
                break;

            case EMS_ALIGN_RIGHT:
                hilite_menu_id = MENU_ID_SMS_EMS_ALIGNMENT_RIGHT;
                break;

            default:
                hilite_menu_id = MENU_ID_SMS_EMS_ALIGNMENT_AUTOMATIC;
                break;
        }

        cui_menu_set_radio_list_item(cui_menu_gid, hilite_menu_id);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_size_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_alignment_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((menu_evt->highlighted_menu_id))
    {
        case MENU_ID_SMS_EMS_ALIGNMENT_AUTOMATIC:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_LANG_DEP);
            break;

        case MENU_ID_SMS_EMS_ALIGNMENT_LEFT:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_LEFT);
            break;

        case MENU_ID_SMS_EMS_ALIGNMENT_CENTER:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_CENTER);
            break;

        case MENU_ID_SMS_EMS_ALIGNMENT_RIGHT:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_RIGHT);
            break;

        default:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_LANG_DEP);
            break;
    }

    mmi_ems_insert_object_error_hdlr(emsObjectStatus); /* check whetehr it is inserted or not. */

    mmi_frm_group_close(mmi_ems_gid);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_new_paragraph_pre_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_text_new_paragraph_pre_entry_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_menu_cui_appsub_generic(
        mmi_ems_gid,
        MENU_ID_SMS_EMS_NEW_PARAGRAPH,
        STR_EMS_NEW_PARAGRAPH_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_new_paragraph_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_new_paragraph_entry_hdlr(MMI_ID menu_gid, MMI_BOOL is_from_history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid = menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(cui_menu_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    if (is_from_history)
    {
        cui_menu_set_radio_list_item(cui_menu_gid, highlighted_menu_id);
    }
    else
    {   
        MMI_MENU_ID hilite_menu_id = MENU_ID_SMS_EMS_ALIGNMENT_AUTOMATIC;

        switch (EMS_inputbox_get_text_alignment())
        {
            case EMS_ALIGN_LANG_DEP:
                hilite_menu_id = MENU_ID_SMS_EMS_NEW_PARAGRAPH_AUTOMATIC;
                break;

            case EMS_ALIGN_LEFT:
                hilite_menu_id = MENU_ID_SMS_EMS_NEW_PARAGRAPH_LEFT;
                break;

            case EMS_ALIGN_CENTER:
                hilite_menu_id = MENU_ID_SMS_EMS_NEW_PARAGRAPH_CENTER;
                break;

            case EMS_ALIGN_RIGHT:
                hilite_menu_id = MENU_ID_SMS_EMS_NEW_PARAGRAPH_RIGHT;
                break;

            default:
                hilite_menu_id = MENU_ID_SMS_EMS_NEW_PARAGRAPH_AUTOMATIC;
                break;
        }

        cui_menu_set_radio_list_item(cui_menu_gid, hilite_menu_id);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_new_paragraph_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_new_paragraph_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((menu_evt->highlighted_menu_id))
    {
        case MENU_ID_SMS_EMS_NEW_PARAGRAPH_AUTOMATIC:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_LANG_DEP);
            break;

        case MENU_ID_SMS_EMS_NEW_PARAGRAPH_LEFT:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_LEFT);
            break;

        case MENU_ID_SMS_EMS_NEW_PARAGRAPH_CENTER:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_CENTER);
            break;

        case MENU_ID_SMS_EMS_NEW_PARAGRAPH_RIGHT:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_RIGHT);
            break;

        default:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_LANG_DEP);
            break;
    }

    mmi_ems_insert_object_error_hdlr(emsObjectStatus); /* check whetehr it is inserted or not. */

    mmi_frm_group_close(mmi_ems_gid);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_format_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_format_entry_hdlr(MMI_ID menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(menu_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_text_format_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_text_format_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((menu_evt->highlighted_menu_id))
    {
    #ifndef __MMI_TEXT_FORMAT_WITHOUT_SIZE__
        case MENU_ID_SMS_EMS_TEXT_SIZE:
            mmi_ems_text_size_pre_entry_hdlr();
            break;
    #endif /* __MMI_TEXT_FORMAT_WITHOUT_SIZE__ */

        case MENU_ID_SMS_EMS_TEXT_STYLE:
            mmi_ems_text_style_pre_entry_hdlr();
            break;

        case MENU_ID_SMS_EMS_ALIGNMENT:
            mmi_ems_text_alignment_pre_entry_hdlr();
            break;

        case MENU_ID_SMS_EMS_NEW_PARAGRAPH:
            mmi_ems_text_new_paragraph_pre_entry_hdlr();
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID mmi_ems_group_entry(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ems_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(mmi_ems_gid);
    }

    mmi_ems_gid = mmi_frm_group_create_ex(
                    parent_gid,
                    GRP_ID_AUTO_GEN,
                    mmi_ems_group_proc,
                    NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    return mmi_ems_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_ems_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_GROUP_INACTIVE:
            if (!mmi_frm_scrn_get_count(mmi_ems_gid))
            {
                mmi_frm_group_close(mmi_ems_gid);
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

                switch (menu_evt->parent_menu_id)
                {
                #ifndef __MMI_TEXT_FORMAT_WITHOUT_SIZE__
                    case MENU_ID_SMS_EMS_TEXT_SIZE:
                #endif /* __MMI_TEXT_FORMAT_WITHOUT_SIZE__ */
                    case MENU_ID_SMS_EMS_ALIGNMENT:
                    case MENU_ID_SMS_EMS_NEW_PARAGRAPH:
                        highlighted_menu_id = menu_evt->highlighted_menu_id;

                    case MENU_ID_SMS_EMS_TEXT_STYLE:
                    default:
                        break;
                }
            }
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                MMI_BOOL is_from_history = MMI_FALSE;
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                if (menu_evt->cui_menu_event_flags & CUI_MENU_LIST_FROM_HISTORY)
                {
                    is_from_history = MMI_TRUE;
                }

                switch (menu_evt->parent_menu_id)
                {
                    case MENU_ID_SMS_ED_OPT_INSERT_OBJECT:
                        mmi_ems_insert_object_entry_hdlr(menu_evt->sender_id);
                        break;

                    case MENU_ID_SMS_ED_OPT_TEXT_FORMAT:
                        mmi_ems_text_format_entry_hdlr(menu_evt->sender_id);
                        break;

                #ifndef __MMI_TEXT_FORMAT_WITHOUT_SIZE__
                    case MENU_ID_SMS_EMS_TEXT_SIZE:
                        mmi_ems_text_size_entry_hdlr(menu_evt->sender_id, is_from_history);
                        break;
                #endif /* __MMI_TEXT_FORMAT_WITHOUT_SIZE__ */
                
                    case MENU_ID_SMS_EMS_TEXT_STYLE:
                        mmi_ems_text_style_entry_hdlr(menu_evt->sender_id);
                        break;
                
                    case MENU_ID_SMS_EMS_ALIGNMENT:
                        mmi_ems_text_alignment_entry_hdlr(menu_evt->sender_id, is_from_history);
                        break;
                
                    case MENU_ID_SMS_EMS_NEW_PARAGRAPH:
                        mmi_ems_text_new_paragraph_entry_hdlr(menu_evt->sender_id, is_from_history);
                        break;

                    default:
                        break;
                }
            }
            break;
        
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

                switch (menu_evt->parent_menu_id)
                {
                    case MENU_ID_SMS_ED_OPT_INSERT_OBJECT:
                        mmi_ems_insert_object_select_hdlr(menu_evt);
                        break;

                    case MENU_ID_SMS_ED_OPT_TEXT_FORMAT:
                        mmi_ems_text_format_select_hdlr(menu_evt);
                        break;

                #ifndef __MMI_TEXT_FORMAT_WITHOUT_SIZE__
                    case MENU_ID_SMS_EMS_TEXT_SIZE:
                        mmi_ems_text_size_select_hdlr(menu_evt);
                        break;
                #endif /* __MMI_TEXT_FORMAT_WITHOUT_SIZE__ */
                
                    case MENU_ID_SMS_EMS_TEXT_STYLE:
                        mmi_ems_text_style_select_hdlr(menu_evt);
                        break;
                
                    case MENU_ID_SMS_EMS_ALIGNMENT:
                        mmi_ems_text_alignment_select_hdlr(menu_evt);
                        break;
                
                    case MENU_ID_SMS_EMS_NEW_PARAGRAPH:
                        mmi_ems_text_new_paragraph_select_hdlr(menu_evt);
                        break;

                    default:
                        break;
                }
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
            {
                cui_file_selector_result_event_struct *fmgr_evt = (cui_file_selector_result_event_struct *)evt;

                if(fmgr_evt->result < 0)
                {
                    cui_file_selector_close(fmgr_evt->sender_id);
                }
                else if(fmgr_evt->result > 0) /*success to get a file */
                {
                    WCHAR temp_path[SRV_FMGR_PATH_MAX_LEN + 1];

                    cui_file_selector_get_selected_filepath(
                        fmgr_evt->sender_id,
                        NULL,
                        temp_path,
                        (SRV_FMGR_PATH_MAX_LEN * ENCODING_LENGTH));

                #ifdef __MMI_FILE_MANAGER__
                    mmi_ems_preview_object_from_fm((PU16)temp_path, 0);
                #endif
                }
                else if(0 == fmgr_evt->result)
                {
                    cui_file_selector_close(fmgr_evt->sender_id);
                }
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_insert_object
 * DESCRIPTION
 *  Entry insert object screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_entry_insert_object(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ems_group_entry(parent_gid);

    mmi_sms_entry_menu_cui_appsub_generic(
        mmi_ems_gid,
        MENU_ID_SMS_ED_OPT_INSERT_OBJECT,
        STR_OPT_INS_OBJECT_MENUENTRY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_insert_object
 * DESCRIPTION
 *  Entry insert object screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_entry_text_format(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ems_group_entry(parent_gid);

    mmi_sms_entry_menu_cui_appsub_generic(
        mmi_ems_gid,
        MENU_ID_SMS_ED_OPT_TEXT_FORMAT,
        STR_EMS_FORMATING_TEXT_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_pre_entry_save_object_list
 * DESCRIPTION
 *  Entry insert object screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_pre_entry_save_object_list(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ems_group_entry(parent_gid);

    mmi_ems_set_group_id(mmi_ems_gid);
    mmi_ems_entry_save_object_list();
}


#ifdef __MMI_FILE_MANAGER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ems_fmgr_send_by_ems_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_fmgr_send_by_ems_hdlr(MMI_MENU_ID item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct *fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_type = fileinfo->type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_type == FMGR_TYPE_IMY)
    {
        mmi_ems_fm_send_by_ems((S8*)filepath, EMS_OBJECT_MY_MELODY_STATE);
    }
    else if (file_type == FMGR_TYPE_ANM)
    {
        mmi_ems_fm_send_by_ems((S8*)filepath, EMS_OBJECT_MY_ANIMATION_STATE);
    }
    else if (file_type == FMGR_TYPE_EMS)
    {
        mmi_ems_fm_send_by_ems((S8*)filepath, EMS_OBJECT_MY_PICTURE_STATE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_fmgr_send_by_ems_enabler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_fmgr_send_by_ems_enabler(MMI_MENU_ID item_id, const WCHAR *filepath, const srv_fmgr_fileinfo_struct *fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_type = fileinfo->type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only enable when file is IMY/EMS/ANM and have SIM */
    if (((file_type != FMGR_TYPE_IMY) &&
         (file_type != FMGR_TYPE_EMS) &&
         (file_type != FMGR_TYPE_ANM)) ||
         srv_sms_is_hide_send_sms_menu_item())
    {
        mmi_frm_hide_menu_item(item_id);
        return;
    }

#if defined(__MMI_UNIFIED_COMPOSER__)
    /*if defined UC, always hide this option */
    /* Hide it if file is IMY/EMS/ANM */
    if ((file_type == FMGR_TYPE_IMY) ||
        (file_type == FMGR_TYPE_EMS) ||
        (file_type == FMGR_TYPE_ANM))
    {
        mmi_frm_hide_menu_item(item_id);
        return;
    }
#endif
}
#endif /* __MMI_FILE_MANAGER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_pre_entry_save_object_name
 * DESCRIPTION
 *  Entry insert object screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_pre_entry_save_object_name(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SMS_APP_EMS_SUPPORT__
    mmi_ems_group_entry(parent_gid);

    mmi_ems_set_group_id(mmi_ems_gid);

    mmi_ems_pre_entry_edit_object_name();
#else
    mmi_sms_display_popup_ext(
        STR_GLOBAL_NOT_SUPPORTED,
        MMI_EVENT_FAILURE);
#endif
}

#endif /* __MMI_SMS_APP_EMS_SUPPORT__) */ 
