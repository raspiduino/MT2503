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
 *  EmailAppOTAP.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email provisioning function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__

#ifdef __MMI_EMAIL_OTAP__

#include "Conversions.h"
#include "Menucuigprot.h"
#include "CommonScreens.h"
#include "mmi_rp_app_email_def.h"
#include "EmailAppProt.h"
#include "emailsrvgprot.h"
#include "EmailAppOtap.h"
#include "CentralConfigAgentGprot.h"

#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "mmi_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_rp_app_cca_def.h"
#include "Unicodexdcl.h"
#include "customer_ps_inc.h"
#include "DataAccountGProt.h"
#include "cbm_consts.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_input_gprot.h"

#include "EmailAppLib.h"
#include "EmailAppDtcnt.h"
#include "EmailAppStateMgr.h"
#include "EmailAppAccountData.h"
#include "EmailAppStateMgr.h"

/* function declaration */
static mmi_ret mmi_email_otap_proc(mmi_event_struct *p_event);
static void mmi_email_otap_proc_handle_end_key_message(mmi_event_struct *p_event);
static void mmi_email_otap_proc_handle_group_deinit_message(mmi_event_struct *p_event);
static void mmi_email_otap_proc_handle_menu_entry_message(cui_menu_event_struct *p_event);
static void mmi_email_otap_proc_handle_menu_select_message(cui_menu_event_struct *p_event);
static void mmi_email_otap_proc_handle_menu_close_message(cui_menu_event_struct *p_event);
static mmi_ret mmi_email_otap_get_profile_info_popup_callback(mmi_event_struct *p_event);
static void mmi_email_otap_get_profile_info(mmi_email_app_otap_struct *p_email_app_otap_cntx);
static mmi_ret mmi_email_otap_entry_display_profile_screen(mmi_scrn_essential_struct* p_screen_data);
static void mmi_email_otap_prepeare_profile_info(CHAR *p_otap_info, mmi_email_app_otap_struct *p_email_app_otap_cntx);
static void mmi_email_otap_entry_account_list_process(mmi_email_app_otap_struct *p_email_app_otap_cntx);
static mmi_ret mmi_email_otap_entry_account_list_screen(mmi_scrn_essential_struct* p_screen_data);
static void mmi_email_otap_entry_account_list_screen_lsk(void);
static void mmi_email_otap_entry_account_list_screen_rsk(void);
static void mmi_email_otap_entry_account_list_highlight_handler(S32 index);
static pBOOL mmi_email_otap_get_account_name(S32 account_index, UI_string_type account_name, PU8 *account_image, U8 str_img_mask);
static void mmi_email_otap_install_profile(void);
static void mmi_email_otap_display_skip_profile_confirm(void);
static void mmi_email_otap_skip_profile(void);
static void mmi_email_otap_modify_profile(void);
static void mmi_email_otap_replace_profile(void);
static MMI_BOOL mmi_email_otap_account_can_be_modified(srv_email_acct_info_struct *p_account_info);
static srv_email_result_enum mmi_email_otap_read_account_info(
                                EMAIL_SRV_HANDLE srv_handle,
                                EMAIL_ACCT_HANDLE *p_acct_handle,
                                EMAIL_ACCT_ID acct_id,
                                srv_email_acct_info_struct *p_acct_info);
static void mmi_email_otap_account_set_menu_screen(mmi_id screen_id, mmi_email_otap_menu_screen_struct *p_menu_screen_struct);
static srv_email_result_enum mmi_email_otap_get_existed_account_name(S32 account_num, EMAIL_ACCT_ID *p_account_id_array, WCHAR (*p_account_name)[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1]);
static MMI_BOOL mmi_email_otap_change_account_data_account_id(
                    srv_email_acct_info_struct *p_acct_info,
                    U32 new_data_account_id,
                    MMI_BOOL has_data_account);
static mmi_ret mmi_email_otap_wait_screen(mmi_scrn_essential_struct* p_screen_data);
static mmi_ret mmi_email_otap_wait_screen_key_proc(mmi_event_struct *p_event);
static void mmi_email_otap_async_add_profile_callback(
                srv_email_result_struct *result,
                EMAIL_ACCT_ID acct_id,
                EMAIL_REQ_ID req_id,
                void *user_data);
static void mmi_email_otap_async_replace_profile_callback(
                srv_email_result_struct *p_result,
                EMAIL_ACCT_ID acct_id,
                EMAIL_REQ_ID req_id,
                void *user_data);

/* variable declaration */
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
static mmi_email_app_otap_struct g_mmi_email_app_otap_cntx;
mmi_email_app_otap_struct *mmi_email_app_otap_p = &g_mmi_email_app_otap_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_init
 * DESCRIPTION
 *  Init email otap application 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_otap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_register_otap_notify(
                        mmi_email_app_otap_p->srv_handle, 
                        mmi_email_otap_main_process, 
                        NULL);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_INIT_LOG1, srv_op_result);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_main_process
 * DESCRIPTION
 *  The email otap main process 
 * PARAMETERS
 *  prof_num  [IN] The profile's number
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_otap_main_process(U32 profile_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    srv_email_otap_option_struct otap_option;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    otap_option.same_dtcnt = MMI_TRUE;
    srv_op_result = srv_email_otap_start_install(&(mmi_email_app_otap_p->otap_handle));
    srv_email_otap_set_option(mmi_email_app_otap_p->otap_handle, &otap_option);
    
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_MAIN_PROCESS_LOG1, profile_num, mmi_email_app_otap_p->otap_handle, srv_op_result);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        mmi_email_util_display_error_popup(mmi_cca_get_root_group(), srv_op_result);
        srv_op_result = srv_email_otap_finish_install(mmi_email_app_otap_p->otap_handle);
        mmi_email_app_otap_p->otap_handle = NULL;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_MAIN_PROCESS_LOG2, srv_op_result);
        goto MMI_EMAIL_OTAP_MAIN_PROCESS_END;
    }

    if (!mmi_email_smgr_show_ui_check(NULL))
    {
        srv_op_result = srv_email_otap_finish_install(mmi_email_app_otap_p->otap_handle);
        mmi_email_app_otap_p->otap_handle = NULL;
        goto MMI_EMAIL_OTAP_MAIN_PROCESS_END;
    }

    mmi_email_app_otap_p->profile_index = 0;
    mmi_email_app_otap_p->profile_num = profile_num;
    mmi_email_app_otap_p->close_group_type = MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_OTHER;
    
    mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
MMI_EMAIL_OTAP_MAIN_PROCESS_END:
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_proc
 * DESCRIPTION
 *  The proc of GRP_ID_EMAIL_OTAP
 * PARAMETERS
 *  p_event  [IN] The event sent to GRP_ID_EMAIL_OTAP
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_email_otap_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->evt_id)
    {
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        mmi_email_otap_proc_handle_end_key_message(p_event);
        break;

    case EVT_ID_GROUP_DEINIT:
        mmi_email_otap_proc_handle_group_deinit_message(p_event);
        break;

    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_email_otap_proc_handle_menu_entry_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        mmi_email_otap_proc_handle_menu_select_message((cui_menu_event_struct*)p_event);
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        mmi_email_otap_proc_handle_menu_close_message((cui_menu_event_struct*)p_event);
        break;

    default:
        break;
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_proc_handle_end_key_message
 * DESCRIPTION
 *  proc function
 * PARAMETERS
 *  p_event  [IN] The event 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_proc_handle_end_key_message(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_otap_struct *p_email_app_otap_cntx = NULL;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_email_app_otap_cntx = p_event->user_data;

    p_email_app_otap_cntx->close_group_type = MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_END_KEY;
    srv_op_result = srv_email_otap_skip_prof(
                        p_email_app_otap_cntx->otap_handle, 
                        MMI_TRUE, 
                        p_email_app_otap_cntx->profile_index, 
                        SRV_EMAIL_SKIP_ENDKEY);
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_PROC_HANDLE_END_KEY_MESSAGE_LOG1, 
        p_email_app_otap_cntx->otap_handle, 
        p_email_app_otap_cntx->profile_index,
        srv_op_result);
    srv_op_result = srv_email_otap_finish_install(p_email_app_otap_cntx->otap_handle);
    p_email_app_otap_cntx->otap_handle = NULL;
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_PROC_HANDLE_END_KEY_MESSAGE_LOG2, srv_op_result);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_proc_handle_group_deinit_message
 * DESCRIPTION
 *  proc function
 * PARAMETERS
 *  p_event  [IN] The event 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_proc_handle_group_deinit_message(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_otap_struct *p_email_app_otap_cntx = NULL;
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_email_app_otap_cntx = p_event->user_data;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_PROC_HANDLE_GROUP_DEINIT_MESSAGE_LOG1,
        p_email_app_otap_cntx->close_group_type);
    if (MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_MYSELF == p_email_app_otap_cntx->close_group_type)
    {
    }
    else if (MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_END_KEY == p_email_app_otap_cntx->close_group_type)
    {
    }
    else
    {
        srv_op_result = srv_email_otap_skip_prof(
                            p_email_app_otap_cntx->otap_handle, 
                            MMI_TRUE, 
                            p_email_app_otap_cntx->profile_index, 
                            SRV_EMAIL_SKIP_ENDKEY);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_PROC_HANDLE_GROUP_DEINIT_MESSAGE_LOG2, srv_op_result);

        srv_op_result = srv_email_otap_finish_install(p_email_app_otap_cntx->otap_handle);
        p_email_app_otap_cntx->otap_handle = NULL;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_PROC_HANDLE_GROUP_DEINIT_MESSAGE_LOG3, srv_op_result);
    }
    p_email_app_otap_cntx->close_group_type = MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_OTHER;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_proc_handle_menu_entry_message
 * DESCRIPTION
 *  proc function
 * PARAMETERS
 *  p_event  [IN] The event sent to EVT_ID_CUI_MENU_LIST_ENTRY
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_proc_handle_menu_entry_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_otap_struct *p_email_app_otap_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_email_app_otap_cntx = p_event->user_data;

    switch (p_event->parent_menu_id)
    {
        case MENU_ID_EMAIL_OTAP_ACCT_OPT:
        {
            mmi_menu_id otap_option_menu_id_array[] = {MENU_ID_EMAIL_OTAP_ACCT_REPLACE, MENU_ID_EMAIL_OTAP_ACCT_MODIFY};
            U16 otap_option_menu_id_string_array[] = {STR_GLOBAL_REPLACE, STR_EMAIL_ACCT_MODIFY_ID};
            mmi_menu_id otap_option_menu_id_array_replace[] = {MENU_ID_EMAIL_OTAP_ACCT_REPLACE};
            U16 otap_option_menu_id_string_array_replace[] = {STR_GLOBAL_REPLACE};
            mmi_email_otap_menu_screen_struct menu_screen;
            srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
            
            srv_op_result = mmi_email_otap_read_account_info(
                                p_email_app_otap_cntx->srv_handle, 
                                &(p_email_app_otap_cntx->acct_handle), 
                                p_email_app_otap_cntx->account_id_array[p_email_app_otap_cntx->select_account_index], 
                                &(p_email_app_otap_cntx->current_account_info));
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_PROC_HANDLE_MENU_ENTRY_MESSAGE_LOG1, srv_op_result);

            menu_screen.title_string_id = STR_GLOBAL_OPTIONS;
            menu_screen.title_icon_id = GetRootTitleIcon(MENU_ID_EMAIL_MAIN);

            if (MMI_TRUE == mmi_email_otap_account_can_be_modified(&(p_email_app_otap_cntx->current_account_info)))
            {
                menu_screen.menu_item_number = sizeof(otap_option_menu_id_array) / sizeof(mmi_menu_id);
                menu_screen.menu_id_array = otap_option_menu_id_array;
                menu_screen.menu_id_string_array = otap_option_menu_id_string_array;
            }
            else
            {
                menu_screen.menu_item_number = sizeof(otap_option_menu_id_array_replace) / sizeof(mmi_menu_id);
                menu_screen.menu_id_array = otap_option_menu_id_array_replace;
                menu_screen.menu_id_string_array = otap_option_menu_id_string_array_replace;                
            }
            menu_screen.menu_id_image_array = (U16*)gIndexIconsImageList;
            mmi_email_otap_account_set_menu_screen(p_event->sender_id, &menu_screen);
            break;
        }
        default:
            break;
        }
    return;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_proc_handle_menu_select_message
 * DESCRIPTION
 *  proc function
 * PARAMETERS
 *  p_event  [IN] The event sent to EVT_ID_CUI_MENU_ITEM_SELECT
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_proc_handle_menu_select_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_event->highlighted_menu_id)
    {
        case MENU_ID_EMAIL_OTAP_ACCT_REPLACE:
            mmi_email_otap_replace_profile();
            break;

        case MENU_ID_EMAIL_OTAP_ACCT_MODIFY:
            mmi_email_otap_modify_profile();
            break;

        default:
            break;
        }
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_proc_handle_menu_close_message
 * DESCRIPTION
 *  proc function
 * PARAMETERS
 *  p_event  [IN] The event sent to EVT_ID_CUI_MENU_CLOSE_REQUEST
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_proc_handle_menu_close_message(cui_menu_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(p_event->sender_id);
    return;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_get_profile_info_popup_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_email_otap_get_profile_info_popup_callback(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_otap_popup_info_struct *p_popup_arg = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_popup_arg = ((mmi_alert_result_evt_struct*)p_event)->user_tag;

    switch (p_popup_arg->popup_type)
    {
        case MMI_EMAIL_OTAP_POPUP_INFO_TYPE_GET_PROFILE_INFO_ERROR:
        {
            mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
            break;
        }
        default:
        {
            break;
        }
    }

    OslMfree(p_popup_arg);
    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_get_profile_info
 * DESCRIPTION
 *  Get the profile's information
 * PARAMETERS
 *  p_email_app_otap_cntx  [IN] The context of mmi_email_app_otap_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_get_profile_info(mmi_email_app_otap_struct *p_email_app_otap_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    mmi_popup_property_struct popup_struct;
    mmi_email_otap_popup_info_struct *p_popup_arg = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_GET_PROFILE_INFO_LOG1, 
        p_email_app_otap_cntx->otap_group_id,
        p_email_app_otap_cntx->profile_index,
        p_email_app_otap_cntx->profile_num);
    p_email_app_otap_cntx->close_group_type = MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_MYSELF;
    mmi_frm_group_close(p_email_app_otap_cntx->otap_group_id);
    
    if ((p_email_app_otap_cntx->profile_index + 1) <= p_email_app_otap_cntx->profile_num)
    {
        p_email_app_otap_cntx->otap_group_id = GRP_ID_EMAIL_OTAP;
        mmi_frm_group_create(
            mmi_cca_get_root_group(), 
            p_email_app_otap_cntx->otap_group_id, 
            mmi_email_otap_proc, 
            p_email_app_otap_cntx);
        mmi_frm_group_enter(p_email_app_otap_cntx->otap_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        srv_op_result = srv_email_otap_get_prof_info(
                            p_email_app_otap_cntx->otap_handle, 
                            p_email_app_otap_cntx->profile_index, 
                            &(p_email_app_otap_cntx->current_profile_info));
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_GET_PROFILE_INFO_LOG2, p_email_app_otap_cntx->otap_handle, srv_op_result);
            p_popup_arg = OslMalloc(sizeof(mmi_email_otap_popup_info_struct));
            p_popup_arg->popup_type = MMI_EMAIL_OTAP_POPUP_INFO_TYPE_GET_PROFILE_INFO_ERROR;
            
            mmi_popup_property_init(&popup_struct);
            popup_struct.callback = mmi_email_otap_get_profile_info_popup_callback;
            popup_struct.user_tag = p_popup_arg;

            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, &popup_struct);
            srv_op_result = srv_email_otap_skip_prof(
                                p_email_app_otap_cntx->otap_handle, 
                                MMI_FALSE, 
                                p_email_app_otap_cntx->profile_index, 
                                SRV_EMAIL_SKIP_ERROR);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_GET_PROFILE_INFO_LOG3, p_email_app_otap_cntx->otap_handle, srv_op_result);
            p_email_app_otap_cntx->profile_index++;
            
            goto MMI_EMAIL_OTAP_GET_PROFILE_INFO_END;
        }
        
        mmi_frm_scrn_first_enter(
            p_email_app_otap_cntx->otap_group_id, 
            SCR_ID_EMAIL_OTAP_INSTALL_PROFILE, 
            (FuncPtr)mmi_email_otap_entry_display_profile_screen, 
            p_email_app_otap_cntx);
    }
    else
    {
        srv_op_result = srv_email_otap_finish_install(p_email_app_otap_cntx->otap_handle);
        p_email_app_otap_cntx->otap_handle = NULL;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_GET_PROFILE_INFO_LOG4, p_email_app_otap_cntx->otap_handle, srv_op_result);
    }
    
MMI_EMAIL_OTAP_GET_PROFILE_INFO_END:
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_entry_display_profile_screen
 * DESCRIPTION
 *  Display the profile's information
 * PARAMETERS
 *  p_screen_data  [IN] The screen data
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_email_otap_entry_display_profile_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    CHAR *p_otap_info = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                p_screen_data->group_id, 
                p_screen_data->scrn_id, 
                NULL, 
                (FuncPtr)mmi_email_otap_entry_display_profile_screen, 
                MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        p_otap_info = (CHAR*)subMenuData;
        mmi_email_otap_prepeare_profile_info(p_otap_info, p_screen_data->user_data);

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ShowCategory74Screen(
            STR_ID_CCA_INSTALL_SETTING,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            STR_GLOBAL_INSTALL,
            IMG_GLOBAL_YES,
            STR_ID_CCA_SKIP,
            IMG_GLOBAL_NO,
            (U8*)p_otap_info,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_email_otap_install_profile, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_email_otap_install_profile, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_email_otap_display_skip_profile_confirm, KEY_EVENT_UP);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_prepeare_profile_info
 * DESCRIPTION
 *  Prepare the profile's information for display
 * PARAMETERS
 *  p_otap_info           [IN/OUT] The buffer which stores the profile information
 *  p_email_app_otap_cntx [IN]     The context of mmi_email_app_otap_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_email_otap_prepeare_profile_info(CHAR *p_otap_info, mmi_email_app_otap_struct *p_email_app_otap_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR tmp_ucs2_buf[20];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* E-Mail */
    mmi_ucs2cpy(p_otap_info, GetString(STR_GLOBAL_EMAIL));
    mmi_ucs2cat(p_otap_info, (CHAR*)L"\n");

    /* Profile: 1/3 */
    mmi_ucs2cat(p_otap_info, GetString(STR_ID_CCA_PROFILE));
    mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_COLON_ID));
    mmi_ucs2cat(p_otap_info, (CHAR*)L" ");
    kal_wsprintf(tmp_ucs2_buf, "%d/%d", (p_email_app_otap_cntx->profile_index + 1), p_email_app_otap_cntx->profile_num);
    mmi_ucs2cat(p_otap_info, (CHAR*)tmp_ucs2_buf);
    mmi_ucs2cat(p_otap_info, (CHAR*)L"\n");

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (MMI_TRUE == p_email_app_otap_cntx->current_profile_info.updatable)
    {
        mmi_ucs2cat(p_otap_info, GetString(STR_ID_CCA_UPDATE_PROFILE));
        mmi_ucs2cat(p_otap_info, (CHAR*)L"\n");
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    /* Account name */
    if (mmi_ucs2strlen((const CHAR*)(p_email_app_otap_cntx->current_profile_info.prof_name)))
    {
        mmi_ucs2cat(p_otap_info, (CHAR*)L"\n");
        mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_ACCT_NAME_ID));
        mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_COLON_ID));
        mmi_ucs2cat(p_otap_info, (CHAR*)L" ");
        mmi_ucs2cat(p_otap_info, (CHAR*)(p_email_app_otap_cntx->current_profile_info.prof_name));
    }

    /* From */
    if (mmi_ucs2strlen((const CHAR*)(p_email_app_otap_cntx->current_profile_info.from)))
    {
        mmi_ucs2cat(p_otap_info, (CHAR*)L"\n");
        mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_FROM_ID));
        mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_COLON_ID));
        mmi_ucs2cat(p_otap_info, (CHAR*)L" ");
        mmi_ucs2cat(p_otap_info, (CHAR*)(p_email_app_otap_cntx->current_profile_info.from));
    }

    /* Outgoing Server */
    if (mmi_ucs2strlen((const CHAR*)(p_email_app_otap_cntx->current_profile_info.out_server)))
    {
        mmi_ucs2cat(p_otap_info, (CHAR*)L"\n");
        mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_OUTGOING_SERVER_ID));
        mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_COLON_ID));
        mmi_ucs2cat(p_otap_info, (CHAR*)L" ");
        mmi_ucs2cat(p_otap_info, (CHAR*)(p_email_app_otap_cntx->current_profile_info.out_server));
    }

    /* Incoming Server */
    if (mmi_ucs2strlen((const CHAR*)(p_email_app_otap_cntx->current_profile_info.in_server)))
    {
        mmi_ucs2cat(p_otap_info, (CHAR*)L"\n");
        mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_INCOMING_SERVER_ID));
        mmi_ucs2cat(p_otap_info, GetString(STR_EMAIL_COLON_ID));
        mmi_ucs2cat(p_otap_info, (CHAR*)L" ");
        mmi_ucs2cat(p_otap_info, (CHAR*)(p_email_app_otap_cntx->current_profile_info.in_server));
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_entry_account_list_process
 * DESCRIPTION
 *  Entry the account list process
 * PARAMETERS
 *  p_email_app_otap_cntx [IN]     The context of mmi_email_app_otap_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_entry_account_list_process(mmi_email_app_otap_struct *p_email_app_otap_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_acct_get_num((U32*)&(p_email_app_otap_cntx->account_num));
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_ENTRY_ACCOUNT_LIST_PROGRESS_LOG1,
        srv_op_result,
        p_email_app_otap_cntx->account_num);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        goto MMI_EMAIL_OTAP_ENTRY_ACCOUNT_LIST_PROCESS_ERROR_END;
    }
    if (p_email_app_otap_cntx->account_num > 0)
    {
        srv_op_result = mmi_email_otap_get_existed_account_name(
                            p_email_app_otap_cntx->account_num, 
                            p_email_app_otap_cntx->account_id_array, 
                            p_email_app_otap_cntx->account_name);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            goto MMI_EMAIL_OTAP_ENTRY_ACCOUNT_LIST_PROCESS_ERROR_END;
        }
    }
    mmi_frm_scrn_first_enter(
            p_email_app_otap_cntx->otap_group_id, 
            SCR_ID_EMAIL_PROF, 
            (FuncPtr)mmi_email_otap_entry_account_list_screen, 
            p_email_app_otap_cntx);
    return;
    
MMI_EMAIL_OTAP_ENTRY_ACCOUNT_LIST_PROCESS_ERROR_END:
    mmi_email_util_display_error_popup(p_email_app_otap_cntx->otap_group_id, srv_op_result);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_entry_account_list_screen
 * DESCRIPTION
 *  Entry the account list screen
 * PARAMETERS
 *  p_screen_data  [IN] The screen data * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_email_otap_entry_account_list_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    mmi_email_app_otap_struct *p_email_app_otap_cntx = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                    p_screen_data->group_id, 
                    p_screen_data->scrn_id, 
                    NULL, 
                    (FuncPtr)mmi_email_otap_entry_account_list_screen, 
                    MMI_FRM_FULL_SCRN))
    {
        p_email_app_otap_cntx = p_screen_data->user_data;
        
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        RegisterHighlightHandler(mmi_email_otap_entry_account_list_highlight_handler);

        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        ShowCategory184Screen(
            STR_EMAIL_EMAIL_ACCTS_ID, 
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN), 
            STR_GLOBAL_OPTIONS, 
            IMG_GLOBAL_OPTIONS, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK, 
            p_email_app_otap_cntx->account_num, 
            mmi_email_otap_get_account_name, 
            NULL, 
            0, 
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_email_otap_entry_account_list_screen_lsk, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_email_otap_entry_account_list_screen_rsk, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_email_otap_entry_account_list_screen_lsk, KEY_EVENT_UP);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_entry_account_list_screen_lsk
 * DESCRIPTION
 *  Entry the account list screen
 * PARAMETERS
 *  p_screen_data  [IN] The screen data * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_entry_account_list_screen_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id account_list_option_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_list_option_id = cui_menu_create(
                                mmi_email_app_otap_p->otap_group_id, 
                                CUI_MENU_SRC_TYPE_APPCREATE, 
                                CUI_MENU_TYPE_OPTION, 
                                MENU_ID_EMAIL_OTAP_ACCT_OPT, 
                                MMI_FALSE, 
                                mmi_email_app_otap_p);
    cui_menu_run(account_list_option_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_entry_account_list_screen_rsk
 * DESCRIPTION
 *  Entry the account list screen
 * PARAMETERS
 *  p_screen_data  [IN] The screen data * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_entry_account_list_screen_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_entry_account_list_highlight_handler
 * DESCRIPTION
 *  The highlight handler of otap account list
 * PARAMETERS
 *  index  [IN] The account index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_entry_account_list_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_ENTRY_ACCOUNT_LIST_HIGHLIGHT_HANDLER_LOG1, index);
    mmi_email_app_otap_p->select_account_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_get_account_name
 * DESCRIPTION
 *  Call back to get the book mark names
 * PARAMETERS
 *  account_index       [IN]        
 *  account_name        [OUT]        
 *  account_image       [OUT]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static pBOOL mmi_email_otap_get_account_name(S32 account_index, UI_string_type account_name, PU8 *account_image, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID default_acct_id = EMAIL_ACCT_INVALID_ID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcsncpy(account_name, (const WCHAR*)mmi_email_app_otap_p->account_name[account_index], MAX_SUBMENU_CHARACTERS);
    //*account_image = get_image(gIndexIconsImageList[account_index]);
    srv_email_acct_get_default(&default_acct_id);
    if (mmi_email_app_otap_p->account_id_array[account_index] == default_acct_id)
    {
        *account_image = get_image(IMG_VICON);
    }
    else
    {
        *account_image = NULL;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_install_profile
 * DESCRIPTION
 *  Install the profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_install_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    EMAIL_ACCT_ID acct_id;
    EMAIL_REQ_ID req_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_email_get_srv_init_state() != SRV_EMAIL_INIT_STATE_READY)
    {
        goto MMI_EMAIL_OTAP_INSTALL_PROFILE_ERROR_END;
    }
    if (MMI_TRUE == mmi_email_app_otap_p->current_profile_info.updatable)
    {
        srv_op_result = srv_email_otap_update_prof(
                            mmi_email_app_otap_p->otap_handle, 
                            mmi_email_app_otap_p->profile_index, 
                            mmi_email_app_otap_p->current_profile_info.prof_name);
        MMI_TRACE(
            MMI_INET_TRC_G9_EMAIL, 
            MMI_EMAIL_OTAP_INSTALL_PROFILE_LOG1, 
            srv_op_result,
            mmi_email_app_otap_p->otap_handle,
            mmi_email_app_otap_p->profile_index);
        
        if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
        {
            srv_op_result = mmi_email_otap_read_account_info(
                                mmi_email_app_otap_p->srv_handle, 
                                &(mmi_email_app_otap_p->acct_handle), 
                                mmi_email_app_otap_p->current_profile_info.update_acct_id, 
                                &(mmi_email_app_otap_p->current_account_info));
            if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
            {
                mmi_email_otap_change_account_data_account_id(
                    &(mmi_email_app_otap_p->current_account_info), 
                    mmi_email_app_otap_p->current_profile_info.dtcnt_id, 
                    mmi_email_app_otap_p->current_profile_info.have_dtcnt);
            }
            mmi_email_app_otap_p->profile_index++;
            mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
        }
        else
        {
            //goto MMI_EMAIL_OTAP_INSTALL_PROFILE_ERROR_END;
            mmi_email_app_otap_p->profile_index++;
            mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
        }
    }
    else
    {
        srv_op_result = srv_email_acct_get_num((U32*)&(mmi_email_app_otap_p->account_num));
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_INSTALL_PROFILE_LOG2, srv_op_result, (mmi_email_app_otap_p->account_num));

        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {       
            goto MMI_EMAIL_OTAP_INSTALL_PROFILE_ERROR_END;
        }
        
        if (mmi_email_app_otap_p->account_num < MMI_EMAIL_MAX_ACCTS)
        {
            if (0 == mmi_email_app_otap_p->current_profile_info.prof_name[0])
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_INSTALL_PROFILE_LOG3);
                if (mmi_email_app_otap_p->account_num > 0)
                {
                    srv_op_result = mmi_email_otap_get_existed_account_name(
                                        mmi_email_app_otap_p->account_num, 
                                        mmi_email_app_otap_p->account_id_array, 
                                        mmi_email_app_otap_p->account_name);
                    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
                    {
                        goto MMI_EMAIL_OTAP_INSTALL_PROFILE_ERROR_END;
                    }
                }
                if (mmi_wcslen(mmi_email_app_otap_p->current_profile_info.from) != 0)
                {
                    mmi_wcsncpy(mmi_email_app_otap_p->current_profile_info.prof_name, mmi_email_app_otap_p->current_profile_info.from,SRV_EMAIL_MAX_ACCT_NAME_LEN);
                }
                else
                {
                    mmi_wcsncpy(mmi_email_app_otap_p->current_profile_info.prof_name, mmi_email_app_otap_p->current_profile_info.in_server,SRV_EMAIL_MAX_ACCT_NAME_LEN);
                }
                mmi_email_generate_default_acct_name(
                    mmi_email_app_otap_p->current_profile_info.prof_name, 
                    mmi_email_app_otap_p->account_num, 
                    mmi_email_app_otap_p->account_name);
            }

            srv_op_result = srv_email_otap_add_prof_async(
                                mmi_email_app_otap_p->otap_handle, 
                                mmi_email_app_otap_p->profile_index, 
                                mmi_email_app_otap_p->current_profile_info.prof_name,
                                &acct_id, 
                                &req_id, 
                                mmi_email_otap_async_add_profile_callback, 
                                mmi_email_app_otap_p);
            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL, 
                MMI_EMAIL_OTAP_INSTALL_PROFILE_LOG4, 
                srv_op_result,
                mmi_email_app_otap_p->otap_handle,
                mmi_email_app_otap_p->profile_index,
                acct_id);
            
            if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
            {
                if (MMI_TRUE == mmi_email_store_acct_misc_info(acct_id))
                {
                    mmi_email_smgr_account_add(acct_id);
                    if (0 == mmi_email_app_otap_p->account_num)
                    {
                        //srv_email_acct_set_default(acct_id);
                        email_mmi_account_data_set_default(acct_id);
                    }
                }
                else
                {
                    srv_op_result = SRV_EMAIL_RESULT_SUCC;//srv_email_acct_delete(acct_id);
                    email_mmi_account_data_set_default(EMAIL_ACCT_INVALID_ID);
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_INSTALL_PROFILE_LOG5, srv_op_result);
                    goto MMI_EMAIL_OTAP_INSTALL_PROFILE_ERROR_END;
                }              
            }
            else if (SRV_EMAIL_RESULT_WOULDBLOCK == srv_op_result)
            {
                mmi_frm_scrn_first_enter(
                    mmi_email_app_otap_p->otap_group_id, 
                    SCR_ID_EMAIL_PROGRESS, 
                    (FuncPtr)mmi_email_otap_wait_screen, 
                    mmi_email_app_otap_p);
                goto MMI_EMAIL_OTAP_ASYNC_INSTALL_PROFILE_ERROR_END;
            }
            else
            {
                //goto MMI_EMAIL_OTAP_INSTALL_PROFILE_ERROR_END;
            }
            mmi_email_app_otap_p->profile_index++;
            mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
        }
        else
        {
            mmi_email_otap_entry_account_list_process(mmi_email_app_otap_p);
        }
    }
    
    return;
    
 MMI_EMAIL_OTAP_INSTALL_PROFILE_ERROR_END:

    srv_op_result = srv_email_otap_skip_prof(
                        mmi_email_app_otap_p->otap_handle, 
                        MMI_FALSE, 
                        mmi_email_app_otap_p->profile_index, 
                        SRV_EMAIL_SKIP_ERROR);
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_INSTALL_PROFILE_LOG6, 
        srv_op_result,
        mmi_email_app_otap_p->otap_handle,
        mmi_email_app_otap_p->profile_index);
    mmi_email_app_otap_p->profile_index++;
    mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
    return;

 MMI_EMAIL_OTAP_ASYNC_INSTALL_PROFILE_ERROR_END:
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_display_skip_profile_confirm
 * DESCRIPTION
 *  Skip the profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_display_skip_profile_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel_with_sg(mmi_email_app_otap_p->otap_group_id, STR_ID_CCA_SKIP_PROFILE, mmi_email_otap_skip_profile);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_skip_profile
 * DESCRIPTION
 *  Skip the profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_skip_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_otap_skip_prof(
                        mmi_email_app_otap_p->otap_handle, 
                        MMI_FALSE, 
                        mmi_email_app_otap_p->profile_index, 
                        SRV_EMAIL_SKIP_NORMAL);
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_SKIP_PROFILE_LOG1, 
        srv_op_result,
        mmi_email_app_otap_p->otap_handle,
        mmi_email_app_otap_p->profile_index);
    mmi_email_app_otap_p->profile_index++;
    mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_modify_profile
 * DESCRIPTION
 *  Modify the profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_modify_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_op_result = srv_email_otap_modify_prof(
                        mmi_email_app_otap_p->otap_handle, 
                        mmi_email_app_otap_p->profile_index, 
                        mmi_email_app_otap_p->current_profile_info.prof_name,
                        mmi_email_app_otap_p->account_id_array[mmi_email_app_otap_p->select_account_index]);
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_MODIFY_PROFILE_LOG1, 
        srv_op_result,
        mmi_email_app_otap_p->otap_handle,
        mmi_email_app_otap_p->profile_index,
        mmi_email_app_otap_p->select_account_index);
    if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
    {
        srv_op_result = mmi_email_otap_read_account_info(
                            mmi_email_app_otap_p->srv_handle, 
                            &(mmi_email_app_otap_p->acct_handle), 
                            mmi_email_app_otap_p->account_id_array[mmi_email_app_otap_p->select_account_index], 
                            &(mmi_email_app_otap_p->current_account_info));
        if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
        {
            mmi_email_otap_change_account_data_account_id(
                &(mmi_email_app_otap_p->current_account_info), 
                mmi_email_app_otap_p->current_profile_info.dtcnt_id, 
                mmi_email_app_otap_p->current_profile_info.have_dtcnt);
        }
    }
    mmi_email_app_otap_p->profile_index++;
    mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_replace_profile
 * DESCRIPTION
 *  Replace the profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_otap_replace_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_FAIL;
    EMAIL_ACCT_ID origin_account_id;
    EMAIL_ACCT_ID replaced_account_id;
    EMAIL_REQ_ID req_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    origin_account_id = mmi_email_app_otap_p->account_id_array[mmi_email_app_otap_p->select_account_index];
    if (0 == mmi_email_app_otap_p->current_profile_info.prof_name[0])
    {
        if (mmi_wcslen(mmi_email_app_otap_p->current_profile_info.from) != 0)
        {
            mmi_wcsncpy(mmi_email_app_otap_p->current_profile_info.prof_name, mmi_email_app_otap_p->current_profile_info.from,SRV_EMAIL_MAX_ACCT_NAME_LEN);
        }
        else
        {
            mmi_wcsncpy(mmi_email_app_otap_p->current_profile_info.prof_name, mmi_email_app_otap_p->current_profile_info.in_server,SRV_EMAIL_MAX_ACCT_NAME_LEN);
        }

        mmi_email_generate_default_acct_name(
            mmi_email_app_otap_p->current_profile_info.prof_name, 
            MMI_EMAIL_MAX_ACCTS, 
            mmi_email_app_otap_p->account_name);
    }

    srv_op_result = srv_email_otap_replace_prof_async(
                        mmi_email_app_otap_p->otap_handle, 
                        mmi_email_app_otap_p->profile_index,
                        mmi_email_app_otap_p->current_profile_info.prof_name,
                        origin_account_id,
                        &replaced_account_id,
                        &req_id,
                        mmi_email_otap_async_replace_profile_callback, 
                        mmi_email_app_otap_p);
    
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_REPLACE_PROFILE_LOG1, 
        srv_op_result, 
        mmi_email_app_otap_p->otap_handle,
        mmi_email_app_otap_p->profile_index,
        mmi_email_app_otap_p->select_account_index,
        replaced_account_id);
    if (SRV_EMAIL_RESULT_SUCC == srv_op_result)
    {
        mmi_email_destroy_acct_misc_info(origin_account_id);
        mmi_email_smgr_account_del(origin_account_id);
        if (MMI_TRUE == mmi_email_store_acct_misc_info(replaced_account_id))
        {
            mmi_email_smgr_account_add(replaced_account_id);
        }
        else
        {
            srv_op_result = srv_email_acct_delete(replaced_account_id);
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_REPLACE_PROFILE_LOG2, srv_op_result);
        }   
    }
    else if (SRV_EMAIL_RESULT_WOULDBLOCK == srv_op_result)
    {
        mmi_frm_scrn_first_enter(
            mmi_email_app_otap_p->otap_group_id, 
            SCR_ID_EMAIL_PROGRESS, 
            (FuncPtr)mmi_email_otap_wait_screen, 
            mmi_email_app_otap_p);
        goto MMI_EMAIL_OTAP_REPLACE_PROFILE_END;
    }
    mmi_email_app_otap_p->profile_index++;
    mmi_email_otap_get_profile_info(mmi_email_app_otap_p);
MMI_EMAIL_OTAP_REPLACE_PROFILE_END:
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_account_can_be_modified
 * DESCRIPTION
 *  Whether the profile can be modified
 * PARAMETERS
 *  p_account_info
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_email_otap_account_can_be_modified(srv_email_acct_info_struct *p_account_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL return_value = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((p_account_info->acct_attr & SRV_EMAIL_ACCT_ATTR_POP3) && (SRV_EMAIL_PROT_IMAP4 == mmi_email_app_otap_p->current_profile_info.in_protocol)) ||
        ((p_account_info->acct_attr & SRV_EMAIL_ACCT_ATTR_IMAP4) && (SRV_EMAIL_PROT_POP3 == mmi_email_app_otap_p->current_profile_info.in_protocol)))
    {
        return_value = MMI_FALSE;
    }
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_ACCOUNT_CAN_BE_MODIFIED_LOG1, 
        p_account_info->acct_attr,
        mmi_email_app_otap_p->current_profile_info.in_protocol,
        return_value);
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_read_account_info
 * DESCRIPTION
 *  Whether the profile can be modified
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static srv_email_result_enum mmi_email_otap_read_account_info(
                                EMAIL_SRV_HANDLE srv_handle,
                                EMAIL_ACCT_HANDLE *p_acct_handle,
                                EMAIL_ACCT_ID acct_id,
                                srv_email_acct_info_struct *p_acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_LOG1, 
        srv_handle,
        p_acct_handle,
        acct_id,
        p_acct_info);
    srv_op_result = srv_email_acct_create(srv_handle, p_acct_handle);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_LOG2, srv_op_result);
        goto MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END;
    }

    srv_op_result = srv_email_acct_open(*p_acct_handle, acct_id);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_LOG3, srv_op_result);
        goto MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END;
    }
    
    srv_op_result = srv_email_acct_read(*p_acct_handle, p_acct_info);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_LOG4, srv_op_result);
        goto MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END;
    }

    srv_op_result = srv_email_acct_destroy(*p_acct_handle);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_LOG5, srv_op_result);
        goto MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END;
    }
    return srv_op_result;

MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END:
    srv_email_acct_destroy(*p_acct_handle);
    return srv_op_result;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_otap_account_set_menu_screen
* DESCRIPTION
*  Set the menu screen
* PARAMETERS
*  screen_id  [IN] The screen's id
*  p_menu_screen_struct [IN] The structure of menu screen
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_otap_account_set_menu_screen(mmi_id screen_id, mmi_email_otap_menu_screen_struct *p_menu_screen_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_title(screen_id, (WCHAR*)GetString(p_menu_screen_struct->title_string_id), (UI_image_type)GetImage(p_menu_screen_struct->title_icon_id));
    cui_menu_set_currlist(screen_id, p_menu_screen_struct->menu_item_number, p_menu_screen_struct->menu_id_array);
    for (i = 0; i < p_menu_screen_struct->menu_item_number; i++)
    {
        cui_menu_set_item_string(screen_id, p_menu_screen_struct->menu_id_array[i], (WCHAR*)GetString(p_menu_screen_struct->menu_id_string_array[i]));
        cui_menu_set_item_image(screen_id, p_menu_screen_struct->menu_id_array[i], p_menu_screen_struct->menu_id_image_array[i]);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_otap_get_existed_account_name
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static srv_email_result_enum mmi_email_otap_get_existed_account_name(S32 account_num, EMAIL_ACCT_ID *p_account_id_array, WCHAR (*p_account_name)[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum srv_op_result = SRV_EMAIL_RESULT_SUCC;
    srv_email_result_enum return_value = SRV_EMAIL_RESULT_SUCC;
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_GET_EXISTED_ACCOUNT_NAME_LOG1, account_num);
    srv_op_result = srv_email_acct_get_acct_id(0, &account_num, p_account_id_array);
    if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_GET_EXISTED_ACCOUNT_NAME_LOG2, srv_op_result, account_num);
        return_value = srv_op_result;
        goto MMI_EMAIL_OTAP_GET_EXISTED_ACCOUNT_NAME_END;
    }

    for (i = 0; i < account_num; i++)
    {
        srv_op_result = srv_email_acct_get_name(
                            p_account_id_array[i],
                            p_account_name[i],
                            SRV_EMAIL_MAX_ACCT_NAME_LEN + 1);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_GET_EXISTED_ACCOUNT_NAME_LOG3, srv_op_result, i, p_account_id_array[i]);
        if (SRV_EMAIL_RESULT_SUCC != srv_op_result)
        {
            return_value = srv_op_result;
            goto MMI_EMAIL_OTAP_GET_EXISTED_ACCOUNT_NAME_END;
        }
    }

MMI_EMAIL_OTAP_GET_EXISTED_ACCOUNT_NAME_END:
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_GET_EXISTED_ACCOUNT_NAME_LOG4, return_value);
    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_otap_change_account_data_account_id
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_email_otap_change_account_data_account_id(
                    srv_email_acct_info_struct *p_acct_info,
                    U32 new_data_account_id,
                    MMI_BOOL has_data_account)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 app_string_id = 0;
    U16 app_icon_id = 0;
    MMI_BOOL return_value = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == has_data_account)
    {
        if (MMI_TRUE == mmi_email_datacct_get_app_info(
                                p_acct_info->acct_id, 
                                MMI_TRUE, 
                                &app_string_id, 
                                &app_icon_id))
        {
            return_value = MMI_TRUE;
        }
        else
        {
            return_value = MMI_FALSE;
        }
    }

    return return_value;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_otap_wait_screen
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_otap_wait_screen(mmi_scrn_essential_struct* p_screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        p_screen_data->group_id,
                        p_screen_data->scrn_id,
                        NULL,
                        (FuncPtr)mmi_email_otap_wait_screen,
                        MMI_FRM_FULL_SCRN))
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_WAIT_SCREEN_LOG1, p_screen_data->group_id, p_screen_data->scrn_id);
        mmi_frm_scrn_set_key_proc(
            p_screen_data->group_id, 
            p_screen_data->scrn_id, 
            mmi_email_otap_wait_screen_key_proc);
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        ShowCategory66Screen(
            STR_GLOBAL_EMAIL,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            0,
            0,
            (U8*)GetString(STR_GLOBAL_LOADING),
            mmi_email_lib_get_progress_img_id(),
            guiBuffer);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_otap_wait_screen_key_proc
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
static mmi_ret mmi_email_otap_wait_screen_key_proc(mmi_event_struct *p_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_KEY_HANDLED;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_otap_async_add_profile_callback
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_otap_async_add_profile_callback(
                srv_email_result_struct *p_result,
                EMAIL_ACCT_ID acct_id,
                EMAIL_REQ_ID req_id,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_otap_struct *p_email_app_otap_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_email_app_otap_cntx = (mmi_email_app_otap_struct*)user_data;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL, 
        MMI_EMAIL_OTAP_ASYNC_ADD_PROFILE_CALLBACK_LOG1, 
        p_result->result,
        p_email_app_otap_cntx->account_num,
        p_email_app_otap_cntx->profile_index,
        p_email_app_otap_cntx->current_profile_info.dtcnt_id);
    if (MMI_TRUE == p_result->result)
    {
        if (MMI_TRUE == mmi_email_store_acct_misc_info(acct_id))
        {
            mmi_email_smgr_account_add(acct_id);
            if (0 == p_email_app_otap_cntx->account_num)
            {
                //srv_email_acct_set_default(acct_id);
                email_mmi_account_data_set_default(acct_id);
            }
        }
        else
        {
            //srv_email_acct_delete(acct_id);
            email_mmi_account_data_set_default(EMAIL_ACCT_INVALID_ID);
        }              
    }
    else
    {
        srv_email_otap_skip_prof(
                            p_email_app_otap_cntx->otap_handle, 
                            MMI_FALSE, 
                            p_email_app_otap_cntx->profile_index, 
                            SRV_EMAIL_SKIP_ERROR);
    }
    
    p_email_app_otap_cntx->profile_index++;
    mmi_email_otap_get_profile_info(p_email_app_otap_cntx);

    mmi_frm_scrn_close(p_email_app_otap_cntx->otap_group_id, SCR_ID_EMAIL_PROGRESS);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_otap_async_replace_profile_callback
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_otap_async_replace_profile_callback(
                srv_email_result_struct *p_result,
                EMAIL_ACCT_ID acct_id,
                EMAIL_REQ_ID req_id,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_otap_struct *p_email_app_otap_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_email_app_otap_cntx = (mmi_email_app_otap_struct*)user_data;

    MMI_TRACE(
        MMI_INET_TRC_G9_EMAIL,
        MMI_EMAIL_OTAP_ASYNC_REPLACE_PROFILE_CALLBACK_LOG1,
        p_result->result,
        p_email_app_otap_cntx->profile_index,
        p_email_app_otap_cntx->current_profile_info.dtcnt_id,
        p_email_app_otap_cntx->account_id_array[p_email_app_otap_cntx->select_account_index],
        acct_id);
    if (MMI_TRUE == p_result->result)
    {
        mmi_email_destroy_acct_misc_info(p_email_app_otap_cntx->account_id_array[p_email_app_otap_cntx->select_account_index]);
        mmi_email_smgr_account_del(p_email_app_otap_cntx->account_id_array[p_email_app_otap_cntx->select_account_index]);
        if (MMI_TRUE == mmi_email_store_acct_misc_info(acct_id))
        {
            mmi_email_smgr_account_add(acct_id);
        }
        else
        {
            srv_email_acct_delete(acct_id);
        }
    }
    else
    {
        if (MMI_TRUE == p_result->sub_result)
        {
            mmi_email_destroy_acct_misc_info(p_email_app_otap_cntx->account_id_array[p_email_app_otap_cntx->select_account_index]);
            mmi_email_smgr_account_del(p_email_app_otap_cntx->account_id_array[p_email_app_otap_cntx->select_account_index]);
        }
    }
    p_email_app_otap_cntx->profile_index++;
    mmi_email_otap_get_profile_info(p_email_app_otap_cntx);

    mmi_frm_scrn_close(p_email_app_otap_cntx->otap_group_id, SCR_ID_EMAIL_PROGRESS);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_otap_deinit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_otap_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_OTAP_DEINIT);
    mmi_email_app_otap_p->close_group_type = MMI_EMAIL_OTAP_CLOAE_GROUP_TYPE_UNMOUNT;
    mmi_frm_group_close(mmi_email_app_otap_p->otap_group_id);
    srv_email_otap_finish_install(mmi_email_app_otap_p->otap_handle);
    mmi_email_app_otap_p->otap_handle = NULL;
}
#endif /* __MMI_EMAIL_OTAP__ */

#endif /* __MMI_EMAIL__ */
