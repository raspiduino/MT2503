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
 *  Voicemail.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application main UI screen and menu, 
 *  inlcude the SMS folder List, Editor, Viewer and their options
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifdef __MMI_TELEPHONY_SUPPORT__

/*  Include: MMI header file */
/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "gui_data_types.h" 
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "wgui_touch_screen.h"
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "l4c2abm_struct.h"
#include "mmi_frm_history_gprot.h"
#include "DebugInitDef_Int.h"
#ifdef __MMI_WLAN_FEATURES__
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#endif
#include "CustMenuRes.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "mmi_frm_input_gprot.h"
#include "PhbSrvGprot.h"
#include "ps_public_enum.h"
#include "ProfilesSrvGprot.h"
#include "string.h"
#include "stdio.h"
#include "SmsAppGprot.h"
#include "MessagesMiscell.h"
#include "custom_mmi_default_value.h"
#include "CommonScreens.h"
#include "PhoneBookGprot.h"
#include "SmsGuiInterfaceType.h"
#include "IdleNotificationManagerGprot.h"
#include "SmsSrvGprot.h"
#include "Voicemail.h"
#include "SmsAppProt.h"
#include "CphsSrvGprot.h"
#include "CallSetSrvGprot.h"

#if (MMI_MAX_SIM_NUM >= 2)
#include "UCMGProt.h"
#endif

#include "CommonScreens.h"
#include "App_usedetails.h"

#ifdef __MMI_UCM__
#include "UCMGprot.h"
#endif /* __MMI_UCM__ */

#include "UcmSrvGprot.h"
#include "InlineCuiGprot.h"
#include "MenuCuiGprot.h"
#include "mmi_rp_app_sms_def.h"
#include "SimCtrlSrvGProt.h"
#ifdef __MMI_WLAN_FEATURES__
#include "NetSetSrvGprot.h"
#endif /* __MMI_WLAN_FEATURES__ */
#include "SsSrvGprot.h"
#include "SmsAppUtil.h"
#include "mmi_frm_utility_gprot.h"
#include "SimCtrlSrvGProt.h"
#include "CallSetSrvIprot.h"

typedef struct
{
    U32 currHiliteIndex;
    MMI_ID list_gid;
    MMI_ID edit_gid;
    srv_sms_sim_enum sim_id;
    mmi_sim_enum mmi_sim;
    MMI_BOOL is_from_idle;
} mmi_sms_vm_set_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/
extern msg_context_struct g_msg_cntx;

/**************************************************************
* Global Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static mmi_id mmi_sms_vm_gid = GRP_ID_INVALID;
static mmi_sms_vm_set_struct vm_user_data;
static const srv_sms_mailbox_struct *mailbox;

static const srv_ucm_call_type_enum call_type[] =
{
    SRV_UCM_VOICE_CALL_TYPE
#if (MMI_MAX_SIM_NUM >= 2)
    ,SRV_UCM_VOICE_CALL_TYPE_SIM2
#endif 
#if (MMI_MAX_SIM_NUM >= 3)
    ,SRV_UCM_VOICE_CALL_TYPE_SIM3
#endif 
#if (MMI_MAX_SIM_NUM >= 4)
    ,SRV_UCM_VOICE_CALL_TYPE_SIM4
#endif 
};

static cui_inline_item_caption_struct voicemai_name = 
{
    STR_ID_SMS_VM_VOICE_MAIL_NAME
};
static const cui_inline_item_text_edit_struct voicemai_name_data = 
{
    0,
    STR_ID_SMS_VM_VOICE_MAIL_NAME,
    SRV_SMS_MAX_PROFILE_NAME_LEN + 1,
    INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_GSM_EXTENDED_HANDLING,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    NULL
};
static cui_inline_item_caption_struct number_name = 
{
    STR_ID_SMS_VM_VOICE_MAIL_NUM
};
static const cui_inline_item_text_edit_struct voicemai_num_data = 
{
    0,
    STR_ID_SMS_VM_VOICE_MAIL_NUM,
    MAX_CC_ADDR_LEN + 1,
    IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
    0,
    NULL
};

static const cui_inline_set_item_struct voicemail_items[] = 
{
#ifdef __MMI_SLIM_IMG_RES__
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, &voicemai_name},
#else
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_NAME, &voicemai_name},
#endif
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &voicemai_name_data},
#ifdef __MMI_SLIM_IMG_RES__
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, &number_name},
#else
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_SC, &number_name},
#endif
    {CUI_INLINE_ITEM_ID_BASE + 3, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &voicemai_num_data}
};

/**************************************************************
* Extern Function Declaration
**************************************************************/

/**************************************************************
* Static Function Declaration
**************************************************************/
static void mmi_sms_vm_set_mailbox_inline_item_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_vm_set_mailbox_inline_item_req(mmi_group_event_struct *inline_evt);
#if (MMI_MAX_SIM_NUM >= 2)
static void mmi_sms_vm_dm_entry(void);
static void mmi_sms_vm_dm_select_hdlr(mmi_menu_id highlighted_menu_id);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
static void mmi_sms_vm_dial_mailbox(mmi_sim_enum mmi_sim);
static void mmi_sms_vm_entry_set_voicemail_number_confirm(mmi_sim_enum mmi_sim, U8 mailboxNameDcs);
static void mmi_sms_vm_goback_from_set_vm_confirm(void);
#ifndef __MMI_SMS_SLIM__
static pBOOL mmi_sms_vm_server_get_item(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
#endif
static S32 mmi_sms_vm_server_get_hint(S32 item_index, UI_string_type *hint_array);
static void mmi_sms_vm_entry_voice_mail_server_edit(void);
static MMI_BOOL mmi_sms_vm_pre_entry_voice_mail_server(mmi_sim_enum mmi_sim);
static void mmi_sms_vm_entry_voice_mail_server(void);
static void mmi_sms_vm_server_option_pre_entry_hdlr(void);
#ifdef __MMI_MSG_REL4_SUPPORT__
static void mmi_sms_vm_server_option_entry_hdlr(mmi_id menu_gid);
#endif
static void mmi_sms_vm_server_option_select_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_sms_vm_dial_cur_mailbox_address(void);
static MMI_ID mmi_sms_vm_create_gid(MMI_ID parent_gid);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_sms_fte_voicemail_server_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

#ifdef __MMI_MSG_REL4_SUPPORT__
static void mmi_sms_vm_set_as_default_mailbox_hdlr(void);
static void mmi_sms_vm_select_default_mailbox_rsp(srv_sms_callback_struct* callback_data);
#endif /* __MMI_MSG_REL4_SUPPORT__ */ 

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
static void mmi_sms_vm_nmgr_message_waiting_handle_notification(void *user_data);
#endif


/**************************************************************
* Function Defination
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_save_result
 * DESCRIPTION
 *  Dial voice mail server number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_save_result(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_SAVED,
            MMI_EVENT_EXPLICITLY_SAVED);
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_set_mailbox_inline_item_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mailboxdetail       [?]         [?]
 *  mod                 [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_set_mailbox_inline_item_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_save_result(callback_data->result);

    cui_inline_close(vm_user_data.edit_gid);

#ifdef __MMI_MSG_REL4_SUPPORT__
    //if (!is_edit_voicemail_num_from_idle)
    {
        //mmi_sms_vm_get_mailbox_list_req();
    }
#endif /* __MMI_MSG_REL4_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_set_mailbox_inline_item_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_set_mailbox_inline_item_req(mmi_group_event_struct *inline_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name[SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
    WCHAR number[MAX_CC_ADDR_LEN + 1];
    mmi_id inline_gid = inline_evt->sender_id;
    srv_sms_mailbox_edit_struct set_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + 1, name);

    memcpy(set_info.mailbox_name, name, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*ENCODING_LENGTH);

    if (srv_phb_check_ucs2_character(name))
    {
        set_info.mailbox_name_dcs= PHB_UCS2;
    }
    else
    {
        set_info.mailbox_name_dcs = PHB_ASCII;
    }


    cui_inline_get_value(inline_gid, CUI_INLINE_ITEM_ID_BASE + 3, number);

    memcpy(set_info.mailbox_address, number, (MAX_CC_ADDR_LEN + 1)*ENCODING_LENGTH);

    if ((number[0]!='\0') 
        && ((applib_is_valid_number_unicode(number) == APPLIB_INVALID_NUMBER)
            || srv_ss_is_valid_ss_string(vm_user_data.mmi_sim, (U8)mmi_ucs2strlen((CHAR*)number), number)
            )
        )
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_INVALID_NUMBER,
            MMI_EVENT_FAILURE);
    }
    else
    {
        mailbox = srv_sms_get_mailbox_setting(vm_user_data.sim_id);

        set_info.malbox_name_len = mailbox->mailbox_name_len;
        set_info.mailbox_number_len = mailbox->mailbox_number_len;
        set_info.mailbox_index = vm_user_data.currHiliteIndex;
    #ifdef __MMI_MSG_REL4_SUPPORT__
        set_info.is_support_r4 = mailbox->is_support_r4;
        set_info.default_index = mailbox->default_index;
    #endif

        mmi_frm_display_dummy_screen();

        srv_sms_set_setting_para(
            SRV_SMS_VOICEMAIL_NUM, 
            (void*)&set_info, 
            vm_user_data.sim_id, 
            mmi_sms_vm_set_mailbox_inline_item_rsp, 
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_dial_cur_mailbox_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_dial_cur_mailbox_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct sendkey_makecall_para; 
    U32 index;
    U16 mailbox_addr[MAX_CC_ADDR_LEN +1 ];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mailbox =  srv_sms_get_mailbox_setting(vm_user_data.sim_id);
    mmi_ucs2cpy((CHAR*)mailbox_addr, (CHAR*)mailbox->p_mailbox_number[vm_user_data.currHiliteIndex]);

    mmi_ucm_init_call_para(&sendkey_makecall_para);
    sendkey_makecall_para.ucs2_num_uri = mailbox_addr;   
    index = mmi_frm_sim_to_index(vm_user_data.mmi_sim);
    sendkey_makecall_para.dial_type = call_type[index];
    sendkey_makecall_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_VOICE_MAIL;

    mmi_ucm_call_launch(mmi_sms_vm_gid, &sendkey_makecall_para);
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  Before entry voice mail server list, get mailbox address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_selct_server(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (!mmi_sms_is_vm_available(mmi_sim))
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
        return;
    }
#endif

    if (g_msg_cntx.msg_dial_voicemail_from_idle_longpress)
    {
        mmi_sms_vm_dial_mailbox(mmi_sim);
    }
    else
    {
        mmi_sms_vm_pre_entry_voice_mail_server(mmi_sim);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_dm_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_dm_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_vm_create_gid(GRP_ID_ROOT) != GRP_ID_INVALID)
    {
        mmi_sms_entry_menu_cui_appsub_generic(
            mmi_sms_vm_gid,
            MENU_ID_SMS_DM_VM_VMAIL_MENUID,
            STR_ID_SMS_VM_VMAIL_MENUENTRY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_dm_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_dm_entry_hdlr(mmi_id menu_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    mmi_sim_enum mmi_sim;
    U16 menu_item[] =
    {
        MENU_ID_SMS_VM_SIM1_VMAIL_MENUID
        ,MENU_ID_SMS_VM_SIM2_VMAIL_MENUID
    #if (MMI_MAX_SIM_NUM >= 3)
        ,MENU_ID_SMS_VM_SIM3_VMAIL_MENUID
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        ,MENU_ID_SMS_VM_SIM4_VMAIL_MENUID
    #endif
    };
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    U32 inserted_num = 0;
    U16 sim_str[] = 
    {
        STR_GLOBAL_SIM_1
        ,STR_GLOBAL_SIM_2
    #if (MMI_MAX_SIM_NUM >= 3)
        ,STR_GLOBAL_SIM_3
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        ,STR_GLOBAL_SIM_4
    #endif
    };
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
        mmi_sim = mmi_frm_index_to_sim(index);

        if(srv_sim_ctrl_is_inserted(mmi_sim)
            && srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_VPS, mmi_sim)
            )
        {
            inserted_num++;
        }
    }
#endif

    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
        mmi_sim = mmi_frm_index_to_sim(index);

    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (!srv_sim_ctrl_is_inserted(mmi_sim)
            || !srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_VPS, mmi_sim)
            || ((g_msg_cntx.msg_dial_voicemail_from_idle_longpress == MMI_TRUE) && (!mmi_sms_is_vm_available(mmi_sim) || !srv_callset_is_available(mmi_sim)))
            )
        {
            cui_menu_set_item_hidden(menu_cui_gid, menu_item[index], MMI_TRUE);
        }
        else
        {
            WCHAR sim_name[MMI_NEW_MSG_WAITING_INFO_LEN];
            U16 str_id = 0;

            if (inserted_num == 1)
            {
                str_id = STR_GLOBAL_SIM;
            }
            else
            {
                str_id = sim_str[index];
            }

            if (mmi_netset_get_sim_name(mmi_frm_index_to_sim(index)) != NULL)
            {
                kal_wsprintf(sim_name, 
                    "%w%w%w%w",
                    GetString(str_id),
                    (S8*) L"(",
                    mmi_netset_get_sim_name(mmi_frm_index_to_sim(index)),
                    (S8*) L")");
                cui_menu_set_item_string(menu_cui_gid, menu_item[index], sim_name);
            }
            else
            {
                cui_menu_set_item_string(menu_cui_gid, menu_item[index], (WCHAR*)GetString(str_id));
            }
        }
    #else
        if (!mmi_sms_is_vm_available(mmi_sim)
            ||(g_msg_cntx.msg_dial_voicemail_from_idle_longpress && !srv_callset_is_available(mmi_sim))
            )
        {
            cui_menu_set_item_hidden(menu_cui_gid, menu_item[index], MMI_TRUE);
        }
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_dm_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_dm_select_hdlr(mmi_menu_id highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (highlighted_menu_id)
    {
        case MENU_ID_SMS_VM_SIM1_VMAIL_MENUID:
            mmi_sms_vm_selct_server(MMI_SIM1);
            break;

        case MENU_ID_SMS_VM_SIM2_VMAIL_MENUID:
            mmi_sms_vm_selct_server(MMI_SIM2);
            break;

    #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_SMS_VM_SIM3_VMAIL_MENUID:
            mmi_sms_vm_selct_server(MMI_SIM3);
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_SMS_VM_SIM4_VMAIL_MENUID:
            mmi_sms_vm_selct_server(MMI_SIM4);
            break;
    #endif

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_set_send_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_set_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    mmi_sms_vm_selct_server(vm_user_data.mmi_sim);
    cui_menu_close(vm_user_data.edit_gid);
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_dial_mailbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_dial_mailbox(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 mailbox_addr[MAX_CC_ADDR_LEN +1 ];
    U8 mailbox_num;
    U8 cur_vm_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mailbox = srv_sms_get_mailbox_setting(SRV_SMS_MMI_SIM_TO_SMS(mmi_sim));
    mailbox_num = mailbox->mailbox_number;

    if (mailbox_num == 0)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_EMPTY,
            MMI_EVENT_FAILURE);
    }
    else
    {
    #ifdef __MMI_MSG_REL4_SUPPORT__
        if (mailbox->is_support_r4)
        {
            cur_vm_index = mailbox->default_index;
        }
        else
    #endif /* __MMI_MSG_REL4_SUPPORT__ */ 
        if (!g_msg_cntx.msg_dial_voicemail_from_idle_longpress
            && g_msg_cntx.msg_waiting_line_number < MAX_WAITING_LINE_NUM
            )
        {
            cur_vm_index = g_msg_cntx.msg_waiting_line_number;
        }
        else
        {
            cur_vm_index = 0;

            if (mailbox_num >= MMI_MSG_MIN_MAILBOX_NUM)
            {
                if (srv_callset_line_switch_get_id(mmi_sim) == SRV_CALLSET_LINE2)
                {
                    cur_vm_index = 1;
                }
            }
        }

        mmi_ucs2cpy((CHAR*) mailbox_addr, (CHAR*) mailbox->p_mailbox_number[cur_vm_index]);

        if (mailbox_addr[0])
        {
            mmi_ucm_make_call_para_struct make_call_para; 
            U32 index;

            mmi_ucm_init_call_para(&make_call_para);
            index = mmi_frm_sim_to_index(mmi_sim);
            make_call_para.dial_type = call_type[index];
            make_call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_VOICE_MAIL;
            make_call_para.ucs2_num_uri = mailbox_addr;
            mmi_ucm_call_launch(0, &make_call_para);
        }
        else
        {
            mmi_sms_vm_entry_set_voicemail_number_confirm(
                mmi_sim,
                cur_vm_index);
        }
    }
}


#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_call_voicemail
 * DESCRIPTION
 *  Dial voice mail server number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_call_voicemail(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sms_is_vm_available(mmi_sim)
    #ifdef __MMI_WLAN_FEATURES__
        || (srv_netset_get_pref_mode() == SRV_NETSET_PREF_MODE_WLAN_ONLY)
    #endif 
        )
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
    else if (!mmi_sms_is_sms_ready())
    {
        mmi_sms_display_popup_ext(
            STR_ID_SMS_VM_VOICE_MAIL_NOT_READY_YET,
            MMI_EVENT_FAILURE);
    }
    else
    {
        mmi_sms_vm_dial_mailbox(mmi_sim);
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_speed_dial_voicemail
 * DESCRIPTION
 *  Dial voice mail server number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_vm_speed_dial_voicemail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    U8 menuitems = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    if (srv_netset_get_pref_mode() == SRV_NETSET_PREF_MODE_WLAN_ONLY)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
        return;
    }
#endif

    if (!mmi_sms_is_sms_ready())
    {
        mmi_sms_display_popup_ext(
            STR_ID_SMS_VM_VOICE_MAIL_NOT_READY_YET,
            MMI_EVENT_FAILURE);
        return;
    }

    g_msg_cntx.msg_dial_voicemail_from_idle_longpress = MMI_TRUE;

#if (MMI_MAX_SIM_NUM == 1)
    if (mmi_sms_is_vm_available(MMI_SIM1))
    {
        mmi_sms_vm_dial_mailbox(MMI_SIM1);
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }
#else /* (MMI_MAX_SIM_NUM >= 2) */ 
    {
        U32 index;
        mmi_sim_enum mmi_sim;
        mmi_sim_enum valid_vm_sim = MMI_SIM1;
        U16 menu_item[] = 
        {
            MENU_ID_SMS_VM_SIM1_VMAIL_MENUID,
            MENU_ID_SMS_VM_SIM2_VMAIL_MENUID
        #if (MMI_MAX_SIM_NUM >= 3)
            ,MENU_ID_SMS_VM_SIM3_VMAIL_MENUID
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            ,MENU_ID_SMS_VM_SIM4_VMAIL_MENUID
        #endif
        };

        for (index = 0; index < MMI_SIM_TOTAL; index++)
        {
            mmi_sim = mmi_frm_index_to_sim(index);

            if (mmi_sms_is_vm_available(mmi_sim)
                && srv_callset_is_available(mmi_sim)
                )
            {
                mmi_frm_unhide_menu_item(menu_item[index]);
                menuitems++;
                valid_vm_sim = mmi_sim;
            }
            else
            {
                mmi_frm_hide_menu_item(menu_item[index]);
            }
        }

        if (menuitems > 1)
        {
            mmi_sms_vm_dm_entry();
        }
        else if (menuitems == 1)
        {
            mmi_sms_vm_dial_mailbox(valid_vm_sim);
        } 
        else
        {
            mmi_sms_display_popup_ext(
                STR_GLOBAL_NOT_AVAILABLE,
                MMI_EVENT_FAILURE);
        }
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_entry_set_voicemail_number_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mailboxIndex        [IN]        
 *  mailboxNameDcs      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_entry_set_voicemail_number_confirm(mmi_sim_enum mmi_sim, U8 mailboxIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_vm_gid == GRP_ID_INVALID)
    {
        mmi_sms_vm_create_gid(GRP_ID_ROOT);
    }

    if (mmi_sms_vm_gid != GRP_ID_INVALID)
    {
        vm_user_data.sim_id = SRV_SMS_MMI_SIM_TO_SMS(mmi_sim);
        vm_user_data.mmi_sim = mmi_sim;
        vm_user_data.currHiliteIndex = mailboxIndex;
        vm_user_data.is_from_idle = MMI_TRUE;

        mmi_sms_entry_confirm_enter_history(
            mmi_sms_vm_gid,
            STR_ID_SMS_VM_SET_VOICEMAIL_QUERY_ID,
            mmi_sms_vm_entry_voice_mail_server_edit,
            mmi_sms_vm_goback_from_set_vm_confirm,
            MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_goback_from_set_vm_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_goback_from_set_vm_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();

    if (!mmi_frm_scrn_get_count(mmi_sms_vm_gid))
    {
        mmi_frm_group_close(mmi_sms_vm_gid);
    }
}


#ifdef __MMI_SMS_SLIM__
static S32 mmi_sms_vm_server_get_1032_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *mailbox_name;
    CHAR *mailbox_number;
    CHAR *content;
    S32 index;
    S32 cur_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < num_item; index++)
    {
        cur_index = start_indx + index;

        mailbox = srv_sms_get_mailbox_setting(vm_user_data.sim_id);

        mailbox_name = (CHAR*)mailbox->p_mailbox_name[cur_index];
        mailbox_number = (CHAR*)mailbox->p_mailbox_number[cur_index];

        if (mailbox_name[0] || mailbox_name[1])
        {
            content = mailbox_name;
        }
        else if (mailbox_number[0] || mailbox_number[1])
        {
            content = mailbox_number;
        }
        else
        {
            content = GetString(STR_GLOBAL_EMPTY_LIST);
        }

        mmi_ucs2ncpy((CHAR*) menuData[index].item_list[0], content, MAX_SUBMENU_CHARACTERS);
        
        #ifdef __MMI_SMS_VOICEMAIL_SLIM__
        menuData[index].image_list[0] = wgui_get_list_menu_icon(cur_index,0);
        #else
        menuData[index].image_list[0] = get_image(gIndexIconsImageList[cur_index]);
        #endif
    }

    return num_item;
}

#else

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_server_get_item
 * DESCRIPTION
 *  Display voice mail server item
 * PARAMETERS
 *  item_index          [IN]            Current item index
 *  str_buff            [IN]            Current item string
 *  img_buff_p          [?]             Current item icon
 *  str_img_mask        [IN]            Current item mask
 * RETURNS
 * MMI_TRUE
 *****************************************************************************/
static pBOOL mmi_sms_vm_server_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *mailbox_name;
    CHAR *mailbox_number;
    CHAR *content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mailbox = srv_sms_get_mailbox_setting(vm_user_data.sim_id);
    mailbox_name = (CHAR*)mailbox->p_mailbox_name[item_index];
    mailbox_number = (CHAR*)mailbox->p_mailbox_number[item_index];

    if (mailbox_name[0] || mailbox_name[1])
    {
        content = mailbox_name;
    }
    else if (mailbox_number[0] || mailbox_number[1])
    {
        content = mailbox_number;
    }
    else
    {
        content = GetString(STR_GLOBAL_EMPTY_LIST);
    }

    mmi_ucs2cpy((CHAR*) str_buff, content);

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);

    return MMI_TRUE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_server_get_hint
 * DESCRIPTION
 *  Display voice mail server hint
 * PARAMETERS
 *  item_index      [IN]        Current item index
 *  hint_array      [?]         Current item hint
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
static S32 mmi_sms_vm_server_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *mailbox_name;
    CHAR *mailbox_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mailbox = srv_sms_get_mailbox_setting(vm_user_data.sim_id);
    mailbox_name = (CHAR*)mailbox->p_mailbox_name[item_index];
    mailbox_number = (CHAR*)mailbox->p_mailbox_number[item_index];

    if ((mailbox_name[0] || mailbox_name[1])
        && (mailbox_number[0] || mailbox_number[1])
        )
    {
        mmi_ucs2cpy((CHAR*) hint_array[0], mailbox_number);
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_vm_pre_entry_hdlr(MMI_ID parent_gid, mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_VM_LAUNCH, parent_gid);

    if (mmi_sms_vm_create_gid(parent_gid) != GRP_ID_INVALID)
    {
        if (!mmi_sms_vm_pre_entry_voice_mail_server(mmi_sim))
        {
            mmi_frm_group_close(mmi_sms_vm_gid);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_pre_entry_voice_mail_server
 * DESCRIPTION
 *  Before entry voice mail server list, get mailbox address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_vm_pre_entry_voice_mail_server(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = SRV_SMS_MMI_SIM_TO_SMS(mmi_sim);
    vm_user_data.sim_id = sim_id;
    vm_user_data.mmi_sim = mmi_sim;

    mailbox = srv_sms_get_mailbox_setting(sim_id);

    if (mailbox->mailbox_number == 0)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_EMPTY,
            MMI_EVENT_FAILURE);

        return MMI_FALSE;
    }
    else
    {
        mmi_sms_vm_entry_voice_mail_server();
        return MMI_TRUE;
    }
}

void mmi_sms_hilite_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GET_HILITE_INDEX, nIndex);

    vm_user_data.currHiliteIndex = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_entry_voice_mail_server
 * DESCRIPTION
 *  Entry voice mail server list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_entry_voice_mail_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    S32 mailbox_num = 0;
#ifdef __MMI_SMS_SLIM__
    S32 error;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            mmi_sms_vm_gid,
            SCR_ID_SMS_VM_VOICE_MAIL_LIST,
            NULL,
            mmi_sms_vm_entry_voice_mail_server,
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_sms_vm_gid, SCR_ID_SMS_VM_VOICE_MAIL_LIST);

        mailbox = srv_sms_get_mailbox_setting(vm_user_data.sim_id);
        mailbox_num = mailbox->mailbox_number;

        if (guiBuffer != NULL)
        {
            hiliteitem = (vm_user_data.currHiliteIndex < mailbox_num) ? vm_user_data.currHiliteIndex  : 0;
        }

        RegisterHighlightHandler(mmi_sms_hilite_hdlr);

        EnableCenterSoftkey(0, IMG_GLOBAL_CALL_CSK);

    #ifdef __MMI_SMS_SLIM__
        wgui_cat1032_show(
                (WCHAR*)GetString(STR_ID_SMS_VM_VMAIL_MENUENTRY),
                NULL,
                (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
                NULL,
                (WCHAR*)GetString(STR_GLOBAL_BACK),
                NULL,
                mailbox_num,
                mmi_sms_vm_server_get_1032_async_items,
                mmi_sms_vm_server_get_hint,
                hiliteitem,
                0,    
                IMG_GLOBAL_L1,
                0,
                guiBuffer,
                &error);
    #else
        ShowCategory184Screen(
            STR_ID_SMS_VM_VMAIL_MENUENTRY,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mailbox_num,
            mmi_sms_vm_server_get_item,
            mmi_sms_vm_server_get_hint,
            hiliteitem,
            guiBuffer);
    #endif

        mmi_ucm_handle_sendkeys_for_call(mmi_sms_vm_dial_cur_mailbox_address, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_sms_vm_server_option_pre_entry_hdlr, KEY_EVENT_UP);
        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_sms_vm_dial_cur_mailbox_address, KEY_EVENT_UP);
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_list_tap_callback(mmi_sms_fte_voicemail_server_tap_callback);
    #endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_server_option_pre_entry_hdlr
 * DESCRIPTION
 *  Entry voice mail server option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_server_option_pre_entry_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_menu_cui_options_generic(
        mmi_sms_vm_gid,
        MENU_ID_SMS_VM_ITEM_VOICE_MAIL_OPTION,
        STR_GLOBAL_OPTIONS);
}


#ifdef __MMI_MSG_REL4_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_server_option_entry_hdlr
 * DESCRIPTION
 *  Entry voice mail server option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_server_option_entry_hdlr(mmi_id menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mailbox = srv_sms_get_mailbox_setting(vm_user_data.sim_id);

    if (mailbox->is_support_r4 && (mailbox->mailbox_number > 1))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VM_DEFAULT_VM_MAILBOX, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_SMS_VM_DEFAULT_VM_MAILBOX, MMI_TRUE);
    }
}
#endif /* __MMI_MSG_REL4_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_server_option_select_hdlr
 * DESCRIPTION
 *  Entry voice mail server option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_server_option_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_item_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_item_id)
    {
        case MENU_ID_SMS_VM_ITEM_VM_1_EDIT:
            mmi_sms_vm_entry_voice_mail_server_edit();
            break;

        case MENU_ID_SMS_VM_ITEM_VM_3_CONNECT_TO_VOICE:
           mmi_sms_vm_dial_cur_mailbox_address();
            break;

    #ifdef __MMI_MSG_REL4_SUPPORT__
        case MENU_ID_SMS_VM_DEFAULT_VM_MAILBOX:
            mmi_sms_vm_set_as_default_mailbox_hdlr();
            break;
    #endif

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_entry_voice_mail_server_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_entry_voice_mail_server_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr_vm_index;
    U16 mailbox_name[MAX_PROFILE_NAME_LEN + 1];
    U16 mailbox_number[MAX_CC_ADDR_LEN + 1];
    MMI_ID edit_gid;
    cui_inline_struct inline_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mailbox = srv_sms_get_mailbox_setting(vm_user_data.sim_id);
    curr_vm_index = vm_user_data.currHiliteIndex;
    mmi_ucs2cpy((CHAR*)mailbox_name, (CHAR*)mailbox->p_mailbox_name[curr_vm_index]);
    mmi_ucs2cpy((CHAR*)mailbox_number, (CHAR*)mailbox->p_mailbox_number[curr_vm_index]);

    inline_data.items_count = 4;
    inline_data.title = STR_ID_SMS_VM_EDIT_VM;
    inline_data.title_icon = IMG_SMS_ENTRY_SCRN_CAPTION;
    inline_data.screen_flag = CUI_INLINE_SCREEN_DEFAULT_TEXT;
    inline_data.softkey = NULL;
    inline_data.items = voicemail_items;

    edit_gid = cui_inline_create(
                    mmi_sms_vm_gid,
                    &inline_data);

    if (edit_gid != GRP_ID_INVALID)
    {
        vm_user_data.edit_gid = edit_gid;

        if (mailbox->mailbox_name_len < SRV_SMS_MAX_PROFILE_NAME_LEN)
        {
            cui_inline_set_text_len(
                edit_gid,
                CUI_INLINE_ITEM_ID_BASE + 1,
                mailbox->mailbox_name_len + 1);
        }
        cui_inline_set_value(
            edit_gid,
            CUI_INLINE_ITEM_ID_BASE + 1,
            mailbox_name);

        if (mailbox->mailbox_number_len < MAX_CC_ADDR_LEN)
        {
            cui_inline_set_text_len(
                edit_gid,
                CUI_INLINE_ITEM_ID_BASE + 3,
                mailbox->mailbox_number_len + 1);
        }

        cui_inline_set_value(
            edit_gid,
            CUI_INLINE_ITEM_ID_BASE + 3,
            mailbox_number);

        cui_inline_run (edit_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_template_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_vm_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            {
                mmi_sms_vm_gid = GRP_ID_INVALID;
                g_msg_cntx.currBoxIndex = SRV_SMS_INVALID_LIST_INDEX;
            }
            break;

    #if (MMI_MAX_SIM_NUM >= 2) || defined(__MMI_MSG_REL4_SUPPORT__)
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

            #ifdef __MMI_MSG_REL4_SUPPORT__
                if (menu_evt->parent_menu_id == MENU_ID_SMS_VM_ITEM_VOICE_MAIL_OPTION)
                {
                    mmi_sms_vm_server_option_entry_hdlr(menu_evt->sender_id);
                }
            #endif

            #if (MMI_MAX_SIM_NUM >= 2)
                if (menu_evt->parent_menu_id == MENU_ID_SMS_DM_VM_VMAIL_MENUID)
                {
                    mmi_sms_vm_dm_entry_hdlr(menu_evt->sender_id);
					#ifdef __MMI_SMS_SLIM__
						cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_LIST_WITH_NO_ICON);
					#endif
                }
            #endif
            }
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

                if ((menu_evt->parent_menu_id == MENU_ID_SMS_DM_VM_VMAIL_MENUID)
                    && g_msg_cntx.msg_dial_voicemail_from_idle_longpress
                    )
                {
                    
                    switch (menu_evt->highlighted_menu_id)
                    {
                        case MENU_ID_SMS_VM_SIM1_VMAIL_MENUID:
                            vm_user_data.mmi_sim = MMI_SIM1;
                            break;
                    
                        case MENU_ID_SMS_VM_SIM2_VMAIL_MENUID:
                            vm_user_data.mmi_sim = MMI_SIM2;
                            break;
                    
                    #if (MMI_MAX_SIM_NUM >= 3)
                        case MENU_ID_SMS_VM_SIM3_VMAIL_MENUID:
                            vm_user_data.mmi_sim = MMI_SIM3;
                            break;
                    #endif
                    
                    #if (MMI_MAX_SIM_NUM >= 4)
                        case MENU_ID_SMS_VM_SIM4_VMAIL_MENUID:
                            vm_user_data.mmi_sim = MMI_SIM4;
                            break;
                    #endif
                    
                        default:
                            break;
                    }
                    
                    vm_user_data.edit_gid = menu_evt->sender_id;
                    //SetKeyHandler(mmi_sms_vm_set_send_key_hdlr, KEY_SEND, KEY_EVENT_UP);
                    SetKeyUpHandler(mmi_sms_vm_set_send_key_hdlr, KEY_SEND);
                }
            }
            break;
    #endif

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

                switch (menu_evt->parent_menu_id)
                {
                    case MENU_ID_SMS_VM_ITEM_VOICE_MAIL_OPTION:
                        mmi_sms_vm_server_option_select_hdlr(menu_evt);
                        break;

                #if (MMI_MAX_SIM_NUM >= 2)
                    case MENU_ID_SMS_DM_VM_VMAIL_MENUID:
                        mmi_sms_vm_dm_select_hdlr(menu_evt->highlighted_menu_id);
                        cui_menu_close(menu_evt->sender_id);
                        break;
                #endif /* (MMI_MAX_SIM_NUM >= 2) */

                    default:
                        break;
                }
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                mmi_group_event_struct *menu_evt = (mmi_group_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            {
                mmi_group_event_struct *inline_evt = (mmi_group_event_struct*)evt;
                cui_inline_close(inline_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_INLINE_SUBMIT :
             mmi_sms_vm_set_mailbox_inline_item_req((mmi_group_event_struct*)evt);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_create_template_gid
 * DESCRIPTION
 *  Entry message settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID mmi_sms_vm_create_gid(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    U32 menuitems = 0;
    U32 index;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
        if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index)))
        {
            menuitems++;
        }
    }

    if (menuitems == 0)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_INSERT_SIM_CARD,
            MMI_EVENT_FAILURE);

        return GRP_ID_INVALID;
    }
#else
    if (mmi_sms_get_valid_sim_op_count(mmi_sms_is_vm_available) == 0)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);

        return GRP_ID_INVALID;
    }
#endif
    else if (!mmi_sms_is_sms_ready())
    {
        mmi_sms_display_popup_ext(
            STR_ID_SMS_VM_VOICE_MAIL_NOT_READY_YET,
            MMI_EVENT_FAILURE);

        return GRP_ID_INVALID;
    }

    if (mmi_sms_vm_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(mmi_sms_vm_gid);
    }

    mmi_sms_vm_gid = mmi_frm_group_create_ex(
                            parent_gid,
                            GRP_ID_AUTO_GEN,
                            mmi_sms_vm_group_proc,
                            NULL,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_VM_GROUP_ENTRY, mmi_sms_vm_gid);

    return mmi_sms_vm_gid;
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_fte_voicemail_server_tap_callback
 * DESCRIPTION
 *  Set intuitive command function for voicemail server Screen
 * PARAMETERS
 *  tap_type: [IN]   The current tap menu status highlight or not
 *  index   : [IN]   The tap menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_fte_voicemail_server_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_sms_vm_dial_cur_mailbox_address();
    }
}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


#ifdef __MMI_MSG_REL4_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_set_as_default_mailbox_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_set_as_default_mailbox_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_set_setting_para(SRV_SMS_MSP, 
                             (void *)&vm_user_data.currHiliteIndex, 
                             vm_user_data.sim_id, 
                             mmi_sms_vm_select_default_mailbox_rsp, 
                             NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_select_default_mailbox_rsp
 * DESCRIPTION
 *  select the default voicemail number response
 * PARAMETERS
 *  data        [IN]        Dummy
 *  mod         [IN]        Module
 *  result      [IN]        SMS Framework result type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_select_default_mailbox_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_set_save_result(callback_data->result);
}
#endif /* __MMI_MSG_REL4_SUPPORT__ */ 

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_nmgr_message_waiting_handle_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_vm_nmgr_message_waiting_handle_notification(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.msg_dial_voicemail_from_idle_longpress = MMI_FALSE;

#if (MMI_MAX_SIM_NUM >= 2)
    {
        mmi_sim_enum mmi_sim = g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim;
        mmi_sms_vm_call_voicemail(mmi_sim);
    }
#else
    mmi_sms_vm_call_voicemail(MMI_SIM1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_nmgr_msg_waiting_by_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_vm_nmgr_msg_waiting_by_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.msg_waiting_ind = 0;
    g_msg_cntx.msg_dial_voicemail_from_idle_longpress = MMI_FALSE;

#if (MMI_MAX_SIM_NUM >= 2)
    {
        mmi_sim_enum mmi_sim = g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim;

        mmi_sms_vm_call_voicemail(mmi_sim);
    }
#else
    mmi_sms_vm_call_voicemail(MMI_SIM1);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_nmgr_query_message_waiting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_vm_nmgr_query_message_waiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sms_is_sms_ready())
    {
        mmi_nmgr_answer(
            MMI_NMGR_APP_MESSAGE_WAITING,
            MMI_NMGR_RESULT_NOT_READY,
            NULL,
            NULL);
        return;
    }
    else
    {
        mmi_nmgr_info_struct info;
        mmi_nmgr_hdlr_func_t hdlr;

        memset(&info, 0, sizeof(mmi_nmgr_info_struct));

        if (g_msg_cntx.msg_waiting_ind == 0)    /* clear popup */
        {
            hdlr = NULL;
        }
        else
        {
            U16 text1_buffer[MMI_NEW_MSG_WAITING_INFO_LEN];

            info.idle_text1 = (CHAR*)text1_buffer;
            mmi_sms_vm_get_msg_waiting_msg((U16*)info.idle_text1, MMI_NEW_MSG_WAITING_INFO_LEN);

            info.idle_text2 = NULL;

        #ifdef __LOW_COST_SUPPORT_COMMON__
            info.image = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
        #else
            info.image = IMG_ID_SMS_VM_NEW_VOICEMAIL_NOTIFICATION_MSG;
        #endif /* __LOW_COST_SUPPORT_COMMON__ */
            info.icon = (U16)(g_msg_cntx.msg_waiting_line_number == 0 ? IMG_MSG_TB_ICON_VOICEMAIL_L1 : IMG_MSG_TB_ICON_VOICEMAIL_L2);

            info.total_num =
                g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].number[g_msg_cntx.msg_waiting_ind - 1];

            if (g_msg_cntx.msg_waiting_ind == MSG_NEW_VOICEMAIL)
            {
                info.left_softkey = STR_GLOBAL_DIAL;
            }
            else
            {
                info.left_softkey = 0;
            }

            info.user_data = NULL;
            
            hdlr = mmi_sms_vm_nmgr_message_waiting_handle_notification;
        }

        mmi_nmgr_answer(
            MMI_NMGR_APP_MESSAGE_WAITING,
            MMI_NMGR_RESULT_OK,
            &info,
            hdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_nmgr_cancel_message_waiting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_vm_nmgr_cancel_message_waiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.msg_waiting_ind = 0;
}
#endif
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_get_single_sim_waiting_info
 * DESCRIPTION
 *  Get msg waiting msg
 * PARAMETERS
 *  void
 * RETURNS
 *  string for msg waiting indication
 *****************************************************************************/
void mmi_sms_vm_get_single_sim_waiting_info(U16 *ucs2_str_buff, U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tempStrId = 0;
    U8 ascii_num[8];
    U16 ucs2_num[8];
    U16 num = g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].number[g_msg_cntx.msg_waiting_ind - 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_waiting_is_show_number)
    {
        sprintf((CHAR*) ascii_num, "%d ", num);

        mmi_asc_to_ucs2((CHAR*) ucs2_num, (CHAR*) ascii_num);
        mmi_ucs2cpy((CHAR*) ucs2_str_buff, (CHAR*) ucs2_num);

        switch (g_msg_cntx.msg_waiting_ind)
        {
            case MSG_NEW_FAX:
                tempStrId = num > 1 ? STR_ID_SMS_VM_FAX_NUM_IND_PLURAL : STR_ID_SMS_VM_FAX_NUM_IND;            
                break;

            case MSG_NEW_EMAIL:
                tempStrId = num > 1 ? STR_ID_SMS_VM_EMAIL_NUM_IND_PLURAL : STR_ID_SMS_VM_EMAIL_NUM_IND;
                break;

            case MSG_NEW_NETOTHER:
                tempStrId = num > 1 ? STR_ID_SMS_VM_NET_OTHER_NUM_IND_PLURAL : STR_ID_SMS_VM_NET_OTHER_NUM_IND;
                break;

            case MSG_NEW_VIDEO:
                tempStrId = num > 1 ? STR_ID_SMS_VM_VIDEO_NUM_IND_PLURAL : STR_ID_SMS_VM_VIDEO_NUM_IND;
                break;

            case MSG_NEW_VOICEMAIL:
            default:
                tempStrId = num > 1 ? STR_ID_SMS_VM_VOICEMAIL_NUM_IND_PLURAL : STR_ID_SMS_VM_VOICEMAIL_NUM_IND;
                break;
        }

        mmi_ucs2cat((CHAR*) ucs2_str_buff, (CHAR*) GetString(tempStrId));
    }
    else
    {
        switch (g_msg_cntx.msg_waiting_ind)
        {
            case MSG_NEW_FAX:
                tempStrId = STR_ID_SMS_VM_FAX_IND;
                break;

            case MSG_NEW_EMAIL:
                tempStrId = STR_ID_SMS_VM_EMAIL_IND;
                break;

            case MSG_NEW_NETOTHER:
                tempStrId = STR_ID_SMS_VM_NET_OTHER_IND;
                break;

            case MSG_NEW_VIDEO:
                tempStrId = STR_ID_SMS_VM_VIDEO_IND;
                break;

            case MSG_NEW_VOICEMAIL:
            default:
                tempStrId = STR_ID_SMS_VM_VOICEMAIL_IND;
                break;
        }

        mmi_ucs2cpy((CHAR*) ucs2_str_buff, (CHAR*) GetString(tempStrId));
    }
}
#endif


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_get_multi_sim_waiting_info
 * DESCRIPTION
 *  Get msg waiting msg
 * PARAMETERS
 *  void
 * RETURNS
 *  string for msg waiting indication
 *****************************************************************************/
void mmi_sms_vm_get_multi_sim_waiting_info(U16 *ucs2_str_buff, U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 simStrId = 0;
    U16 tempStrId = 0;
    msg_waiting_ind_struct *info = &(g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number]);
    U16 num = info->number[g_msg_cntx.msg_waiting_ind - 1];
    mmi_sim_enum mmi_sim = info->curr_sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_str_buff[0] = '\0';

    simStrId = mmi_sms_get_sim_str_id(mmi_sim);

    if (g_msg_cntx.msg_waiting_is_show_number)
    {
        switch (g_msg_cntx.msg_waiting_ind)
        {
            case MSG_NEW_FAX:
                tempStrId = num > 1 ? STR_ID_SMS_VM_SIM_FAX_NUM_IND_PLURAL : STR_ID_SMS_VM_SIM_FAX_NUM_IND;            
                break;

            case MSG_NEW_EMAIL:
                tempStrId = num > 1 ? STR_ID_SMS_VM_SIM_EMAIL_NUM_IND_PLURAL : STR_ID_SMS_VM_SIM_EMAIL_NUM_IND;
                break;

            case MSG_NEW_NETOTHER:
                tempStrId = num > 1 ? STR_ID_SMS_VM_SIM_NET_OTHER_NUM_IND_PLURAL : STR_ID_SMS_VM_SIM_NET_OTHER_NUM_IND;
                break;

            case MSG_NEW_VIDEO:
                tempStrId = num > 1 ? STR_ID_SMS_VM_SIM_VIDEO_NUM_IND_PLURAL : STR_ID_SMS_VM_SIM_VIDEO_NUM_IND;
                break;

            case MSG_NEW_VOICEMAIL:
            default:
                tempStrId = num > 1 ? STR_ID_SMS_VM_SIM_VOICEMAIL_NUM_IND_PLURAL : STR_ID_SMS_VM_SIM_VOICEMAIL_NUM_IND;
                break;
        }

        if (num > 1)
        {
            mmi_wsprintf(ucs2_str_buff, buff_size, tempStrId, num, (WCHAR*)GetString(simStrId));
        }
        else
        {
            mmi_wsprintf(ucs2_str_buff, buff_size, tempStrId, (WCHAR*)GetString(simStrId));
        }
    }
    else
    {
        switch (g_msg_cntx.msg_waiting_ind)
        {
            case MSG_NEW_FAX:
                tempStrId = STR_ID_SMS_VM_SIM_FAX_IND;
                break;

            case MSG_NEW_EMAIL:
                tempStrId = STR_ID_SMS_VM_SIM_EMAIL_IND;
                break;

            case MSG_NEW_NETOTHER:
                tempStrId = STR_ID_SMS_VM_SIM_NET_OTHER_IND;
                break;

            case MSG_NEW_VIDEO:
                tempStrId = STR_ID_SMS_VM_SIM_VIDEO_IND;
                break;

            case MSG_NEW_VOICEMAIL:
            default:
                tempStrId = STR_ID_SMS_VM_SIM_VOICEMAIL_IND;
                break;
        }

        mmi_wsprintf(ucs2_str_buff, buff_size, tempStrId, (WCHAR*)GetString(simStrId));
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_get_msg_waiting_msg
 * DESCRIPTION
 *  Get msg waiting msg
 * PARAMETERS
 *  void
 * RETURNS
 *  string for msg waiting indication
 *****************************************************************************/
void mmi_sms_vm_get_msg_waiting_msg(U16 *ucs2_str_buff, U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_sim_enum mmi_sim;
    U32 inserted_num = 0;
    U32 index;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    mmi_sms_vm_get_single_sim_waiting_info(ucs2_str_buff, buff_size);
#else
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
        mmi_sim = mmi_frm_index_to_sim(index);

        if(srv_sim_ctrl_is_inserted(mmi_sim)
            && srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_VPS, mmi_sim)
            )
        {
            inserted_num++;
        }
    }

    if (inserted_num == 1)
    {
        mmi_sms_vm_get_single_sim_waiting_info(ucs2_str_buff, buff_size);
    }
    else 
#endif
    {
        mmi_sms_vm_get_multi_sim_waiting_info(ucs2_str_buff, buff_size);
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        mmi_sim = g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim;

        if (mmi_netset_get_sim_name(mmi_sim) != NULL)
        {
            kal_wsprintf((WCHAR*)ucs2_str_buff, 
                "%w%w%w%w",
                ucs2_str_buff,
                L"(",
                mmi_netset_get_sim_name(mmi_sim),
                L")");
            MMI_ASSERT(mmi_ucs2strlen((CHAR*)ucs2_str_buff) < buff_size/2);
        }
    #endif
    }
#endif
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_vm_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.msg_dial_voicemail_from_idle_longpress = MMI_FALSE;

#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sms_vm_dm_entry();
#else
    mmi_sms_vm_pre_entry_hdlr(GRP_ID_ROOT, MMI_SIM1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_vm_group_close
 * DESCRIPTION
 *  Entry message settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_vm_group_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_INVALID != mmi_sms_vm_gid)
    {
        mmi_frm_group_close(mmi_sms_vm_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_settings_entry_hdlr
 * DESCRIPTION
 *  Entry message settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_is_vm_available(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_display_voice = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sim_ctrl_is_available(mmi_sim)
        || !srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_VPS, mmi_sim)
        )
    {
        is_display_voice = MMI_FALSE;
    }

    return is_display_voice;
}

#endif /* __MMI_TELEPHONY_SUPPORT__ */ 
