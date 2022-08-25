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
 * PushMsgUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination User interface display of service messages.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "MMI_include.h"
#include "MMI_features.h"
 #include "MMIDataType.h"
 #include "pmg_struct.h"
#ifdef __WAP_PUSH_SUPPORT__
//#include "CommonScreens.h"
#include "WAPPushUIProts.h"
#include "mmi_frm_scenario_gprot.h"
    #include "wgui_categories_text_viewer.h"
    #include "MsgViewerCuiGProt.h"
    #include "mmi_frm_gestures_gprot.h"

#ifdef __MMI_PUSH_IN_UM__
#include "UMGProt.h"

    #include "WAPPushSrvProts.h"
    #include "mmi_rp_app_mmi_wap_push_def.h"
    #include "WAPPushUITypes.h"
    
    #include "WAPPushSrvTypes.h"
    #include "kal_general_types.h"
    #include "WAPPushScreenHdlr.h"
    #include "UMDefs.h"
    #include "kal_public_api.h"
    #include "UmSrvStruct.h"
    #include "wgui_categories_util.h"
    #include "GlobalResDef.h"
    #include "GlobalConstants.h"
    #include "UmSrvDefs.h"



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_um_delete_all
 * DESCRIPTION
 *  delete the selected message from UM inbox.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_um_delete_all (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_all_queue_entry();
    srv_wap_push_send_um_delete_all_ind();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_um_delete_all_msgs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_um_delete_all_msgs (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_event_based_confirm (
        STR_ID_PUSH_DELETE_ALL_INBOX_MSG,
        mmi_wap_push_um_delete_all,
        mmi_push_close_active_screen,
		NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_um_delete_msgs
 * DESCRIPTION
 *  delete the selected message from UM inbox.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_um_delete_msgs (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_delete_message_generic(g_push_cntxt->um_msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_delete_message_from_um_option
 * DESCRIPTION
 *  delete the selected message from UM inbox.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_delete_message_from_um_option (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wap_push_event_based_confirm (
        STR_ID_BRW_PUSH_DELETE_CONFIRM,
        mmi_wap_push_um_delete_msgs,
        mmi_push_close_active_screen,
		mmi_wap_push_um_delete_msgs);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_read_message_from_um_option
 * DESCRIPTION
 *  Open the selected message from UM inbox.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wap_push_read_message_from_um_option (mmi_id parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_wap_push_cntxt->selected_message.msg_type = WAP_PMG_MSGTYPE_NULL;
    g_srv_wap_push_cntxt->read_from_um = MMI_TRUE;
    g_srv_wap_push_cntxt->selected_message_id = g_push_cntxt->um_msg_id;
    mmi_wap_push_scrhdlr_entry_message_display_group(parent_grp_id);
}

mmi_ret mmi_push_option_cb_hdlr(mmi_event_struct *menu_cui_evt, mmi_um_opt_para_struct * um_option_para)
{
    mmi_wap_push_scrhdlr_lsk_um_list_opt_menu(menu_cui_evt, um_option_para);
}


#ifdef __MMI_UM_ITERATOR_VIEWER__

void mmi_wap_push_um_get_slide_buttons_data (U16 *current_index, U16 *total_num)
{
    if ((g_push_cntxt->um_index_success.index_number == 0) && (g_push_cntxt->um_index_success.total_number == 0))
    {
        ASSERT(0);
    }
    else
    {
        *current_index = g_push_cntxt->um_index_success.index_number;
        *total_num = g_push_cntxt->um_index_success.total_number;
    }
}


void mmi_wap_push_um_query_indexing_fail_handler (void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL um_index_result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntxt->um_index_fail.msg_id = g_push_cntxt->um_msg_id;
    g_push_cntxt->um_index_fail.msg_type = SRV_UM_MSG_WAP_PUSH;
    g_push_cntxt->um_index_fail.user_data = NULL;
    g_push_cntxt->um_index_fail.func_cb = mmi_wap_push_um_query_indexing_fail_handler;

    srv_wap_push_update_service_msg_req (g_push_cntxt->um_msg_id);

    um_index_result = mmi_um_query_indexing (&(g_push_cntxt->um_index_fail), &(g_push_cntxt->um_index_success), g_push_cntxt->um_user_data);
    if (um_index_result == MMI_TRUE)
    {
        if ((g_push_cntxt->um_index_success.index_number == 0) && (g_push_cntxt->um_index_success.total_number == 0))
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_READ_SERVICE_MESSAGE)
            {
                mmi_frm_scrn_close_active_id();
            }
            else
            {
                mmi_wap_push_delete_screen_if_present(SCR_ID_BRW_READ_SERVICE_MESSAGE);
            }

            if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
            {
                mmi_frm_scrn_close_active_id();
            }
            else
            {
                mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
            }
        }
        else
        {
            if (g_push_cntxt->need_indexing_update)
            {
                if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
                {
                    mmi_frm_scrn_close_active_id();
                }
                if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_READ_SERVICE_MESSAGE)
                {
                    mmi_wap_push_update_viewer_slide_button_data();
                    wgui_cat_text_viewer_change_slide_buttons_string ();
                }
            }
            else
            {
                mmi_wap_push_delete_screen_if_present(SCR_ID_PUSH_GENERIC_PROCESSING);
            }
        }
    }
    else
    {
        if (!(mmi_wap_push_is_screen_present(SCR_ID_PUSH_GENERIC_PROCESSING) || (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)))
        {
            mmi_wap_push_scrhdlr_entry_generic_processing();
        }
    }
}


mmi_ret mmi_wap_push_update_indexing_data_from_um(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL um_index_result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntxt->um_index_fail.msg_id = g_push_cntxt->um_msg_id;
    g_push_cntxt->um_index_fail.msg_type = SRV_UM_MSG_WAP_PUSH;
    g_push_cntxt->um_index_fail.user_data = NULL;
    g_push_cntxt->um_index_fail.func_cb = mmi_wap_push_um_query_indexing_fail_handler;

    if ((mmi_wap_push_is_screen_present(SCR_ID_BRW_READ_SERVICE_MESSAGE) ||
        mmi_frm_scrn_get_active_id() == SCR_ID_BRW_READ_SERVICE_MESSAGE) && (MMI_TRUE == g_srv_wap_push_cntxt->read_from_um))
    {
        g_push_cntxt->need_indexing_update = MMI_TRUE;
        srv_wap_push_update_service_msg_req (g_push_cntxt->um_msg_id);
        um_index_result = mmi_um_query_indexing (&(g_push_cntxt->um_index_fail), &(g_push_cntxt->um_index_success), g_push_cntxt->um_user_data);
    }
    else
    {
        g_push_cntxt->need_indexing_update = MMI_FALSE;
        return MMI_RET_OK;
    }
    if (um_index_result == MMI_TRUE)
    {
        if ((g_push_cntxt->um_index_success.index_number == 0) && (g_push_cntxt->um_index_success.total_number == 0))
        {
            if (g_srv_wap_push_cntxt->read_from_um)
            {
                mmi_brw_push_delete_previous_instance_of_push();
                if (mmi_wap_push_is_push_scr_is_current_active_screen())
                {
                    mmi_frm_scrn_close_active_id();
                }
            }
        }
        else
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_READ_SERVICE_MESSAGE)
            {
                mmi_wap_push_update_viewer_slide_button_data();
                wgui_cat_text_viewer_change_slide_buttons_string ();
            }
            else if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
            {
                mmi_frm_scrn_close_active_id();
            }
            else
            {
                mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
            }
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_READ_SERVICE_MESSAGE)
        {
            if (!(mmi_wap_push_is_screen_present(SCR_ID_PUSH_GENERIC_PROCESSING) || (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)))
            {
                mmi_wap_push_scrhdlr_entry_generic_processing();
            }
        }
    }
    return MMI_RET_OK;
}


void mmi_wap_push_display_viewer (void)
{
   // if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
    {
        srv_wap_push_update_service_msg_req(g_srv_wap_push_cntxt->selected_message.msg_id);
        srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
        mmi_wap_push_scrhdlr_entry_message_display();
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
    }
   // else
    /*
    {
        if (mmi_wap_push_is_screen_present (SCR_ID_PUSH_GENERIC_PROCESSING))
        {
            srv_wap_push_update_service_msg_req(g_push_cntxt->selected_message.msg_id);
            HistoryReplace (SCR_ID_PUSH_GENERIC_PROCESSING, SCR_ID_BRW_READ_SERVICE_MESSAGE, mmi_wap_push_scrhdlr_entry_message_display);
            srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
        }
    }*/
    //mmi_frm_cb_reg_event(EVT_ID_MMI_UM_REFRESH, mmi_wap_push_update_indexing_data_from_um, NULL);
}


void mmi_wap_push_um_draw_viewer_screen (void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL um_index_result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_push_cntxt->um_user_data = user_data; /* Vikas -- commenting as UM passes NULL as fail response*/

    g_push_cntxt->um_index_fail.msg_id = g_push_cntxt->um_msg_id;
    g_push_cntxt->um_index_fail.msg_type = SRV_UM_MSG_WAP_PUSH;
    g_push_cntxt->um_index_fail.user_data = NULL;
    g_push_cntxt->um_index_fail.func_cb = mmi_wap_push_um_draw_viewer_screen;

    srv_wap_push_update_service_msg_req (g_push_cntxt->um_msg_id);

    um_index_result = mmi_um_query_indexing (&(g_push_cntxt->um_index_fail), &(g_push_cntxt->um_index_success), g_push_cntxt->um_user_data);
    if (um_index_result == MMI_TRUE)
    {
        if ((g_push_cntxt->um_index_success.index_number == 0) && (g_push_cntxt->um_index_success.total_number == 0))
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)
            {
                mmi_frm_scrn_close_active_id();
            }
            else
            {
                mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
            }
        }
        else
        {
            mmi_wap_push_display_viewer ();
        }
    }
    else
    {
        if (!(mmi_wap_push_is_screen_present(SCR_ID_PUSH_GENERIC_PROCESSING) || (mmi_frm_scrn_get_active_id() == SCR_ID_PUSH_GENERIC_PROCESSING)))
        {
            mmi_wap_push_scrhdlr_entry_generic_processing();
        }
    }
}


MMI_BOOL mmi_wap_push_launch_next_viewer (void)
{
    if (g_srv_wap_push_cntxt->read_from_um)
    {
        if ((g_push_cntxt->um_index_success.next_msg_type != 0) && (g_push_cntxt->um_index_success.next_launch_func_ptr != NULL))
        {
            srv_wap_push_send_um_refresh_ind(g_push_cntxt->um_msg_id,SRV_UM_REFRESH_MSG_STATUS_CHANGED ,NULL);
            g_push_cntxt->um_index_success.next_launch_func_ptr (g_push_cntxt->um_parent_group_id, g_push_cntxt->um_index_success.next_msg_id, g_push_cntxt->um_user_data, CUI_MSG_VIEWER_TYPE_ITERATOR);
            mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE);
            return MMI_TRUE;
        }
        else
        {
            mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
            return MMI_FALSE;
        }
    }
    else
    {
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
        return MMI_FALSE;
    }
}


MMI_BOOL mmi_wap_push_launch_prev_viewer (void)
{
    if (g_srv_wap_push_cntxt->read_from_um)
    {
        if ((g_push_cntxt->um_index_success.prev_msg_type != 0) && (g_push_cntxt->um_index_success.prev_launch_func_ptr != NULL))
        {
            
			srv_wap_push_send_um_refresh_ind(g_push_cntxt->um_msg_id,SRV_UM_REFRESH_MSG_STATUS_CHANGED ,NULL);
            g_push_cntxt->um_index_success.prev_launch_func_ptr (g_push_cntxt->um_parent_group_id, g_push_cntxt->um_index_success.prev_msg_id, g_push_cntxt->um_user_data, CUI_MSG_VIEWER_TYPE_ITERATOR);
            mmi_wap_push_delete_screen_if_present( SCR_ID_BRW_READ_SERVICE_MESSAGE);
            return MMI_TRUE;
        }
        else
        {
            mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
            return MMI_FALSE;
        }
    }
    else
    {
        mmi_wap_push_delete_screen_if_present( SCR_ID_PUSH_GENERIC_PROCESSING);
        return MMI_FALSE;
    }
}


void mmi_wap_push_handle_msg_deleted (U32 msg_id)
{
    if (mmi_frm_scrn_get_active_id() == SCR_ID_BRW_READ_SERVICE_MESSAGE)
    {
        if (!mmi_wap_push_launch_next_viewer())
        {
            if (!mmi_wap_push_launch_prev_viewer())
            {
                mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_INFO, STR_ID_PUSH_INBOX_MODIFIED);
            }
        }
    }
    else
    {
        mmi_wap_push_event_based_display_popup(SRV_WAP_PUSH_EVENT_INFO, STR_ID_PUSH_INBOX_MODIFIED);
    }
}


void mmi_wap_push_hanndle_lnk_on_viewer (void)
{
    if (mmi_wap_push_launch_prev_viewer())
    {
    }
}

void mmi_wap_push_hanndle_rnk_on_viewer (void)
{
    if (mmi_wap_push_launch_next_viewer())
    {
    }
}


#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
void mmi_wap_push_display_next_viewer_through_swipe(mmi_frm_gesture_event_enum gesture_event)
{
    mmi_wap_push_launch_next_viewer();
}

void mmi_wap_push_display_prev_viewer_through_swipe(mmi_frm_gesture_event_enum gesture_event)
{
    mmi_wap_push_launch_prev_viewer();
}
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */

#endif /* __MMI_UM_ITERATOR_VIEWER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_push_handle_entry_msg_wap_push
 * DESCRIPTION
 * UM sends the msgID to push application to display the content. 
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_push_handle_entry_msg_wap_push(mmi_um_entry_msg_struct *entry_msg_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_inbox_ctxt->title_icon_id = 0;
    mmi_brw_push_delete_previous_instance_of_push();
    srv_wap_push_delete_all_queue_entry();
    g_push_cntxt->um_msg_id = entry_msg_param->msg_id;
    g_srv_wap_push_cntxt->read_from_um = MMI_TRUE;
    g_push_cntxt->um_parent_group_id = entry_msg_param->parent_grp_id;

#ifdef __MMI_UM_ITERATOR_VIEWER__
    g_push_cntxt->um_user_data = entry_msg_param->user_data;
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

	if (entry_msg_param->key_code == MMI_UM_UI_ENTRY_KEY_CSK ||
        entry_msg_param->key_code == MMI_UM_UI_ENTRY_INTUITIVE_CMD)
    {
        g_srv_wap_push_cntxt->selected_message.msg_type = WAP_PMG_MSGTYPE_NULL;
        g_srv_wap_push_cntxt->selected_message_id = g_push_cntxt->um_msg_id;
        mmi_wap_push_scrhdlr_entry_message_display_group(entry_msg_param->parent_grp_id);
    }
    else if((entry_msg_param->key_code == MMI_UM_UI_ENTRY_KEY_LSK))
    {
        ASSERT(0);
    }
    return MMI_TRUE;
}


void mmi_wap_push_handle_msg_display_from_um (pmg_detailed_msg_struct *new_msg, S8 *url, MMI_BOOL read_from_um)
{
#ifdef __MMI_UM_ITERATOR_VIEWER__
    g_srv_wap_push_cntxt->read_from_um = read_from_um;
    srv_wap_push_copy_data_to_selected_message(new_msg, url);
    mmi_wap_push_um_draw_viewer_screen (g_push_cntxt->um_user_data);
#else
    mmi_wap_push_handle_display_msg (new_msg, url, read_from_um);
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
}

#if 0
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
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
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
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
/* under construction !*/
/* under construction !*/
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ 
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
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ 
/* under construction !*/
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__  */
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
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__  */
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
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
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
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
/* under construction !*/
/* under construction !*/
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
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
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
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
#endif /* 0 */

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_push_check_um_delete
 * DESCRIPTION
 * 
 * PARAMETERS
 *  msg_type      [IN]
 *  msg_id        [IN]
 * RETURNS
 *  TRUE if delete can activated, false otherwise.
 *****************************************************************************/
MMI_BOOL srv_push_check_um_delete (srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_UM_MSG_WAP_PUSH == msg_type)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_push_activated_um_delete
 * DESCRIPTION
 * 
 * PARAMETERS
 *  msg_type      [IN]
 *  msg_id        [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_push_activated_um_delete (mmi_id scr_grp_id, srv_um_msg_enum msg_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_UM_MSG_WAP_PUSH == msg_type)
    {
        g_push_cntxt->um_msg_id = msg_id;
        mmi_wap_push_delete_message_from_um_option();
    }
}
#endif /* __MMI_FTE_SUPPORT__ */

S32 mmi_wap_push_get_um_option_menu_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MENU_ID_PUSH_INBOX_OPTION;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_um_enter_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_wap_push_handle_um_enter_folder(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_entry_folder_evt_struct *event_data = (mmi_um_entry_folder_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((event_data->msg_box == SRV_UM_MSG_BOX_INBOX) || (event_data->msg_box == SRV_UM_MSG_BOX_CONVERSATION))
    { 
//         g_push_cntxt->notify_nmgr = MMI_BRW_PUSH_NOTIFY_NMGR_NOT_NOTIFY;
            srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY);
            srv_wap_push_delete_all_queue_entry();

    }
    return MMI_RET_OK;
}

#endif /* __MMI_PUSH_IN_UM__ */

#endif /* WAP_SUPPORT */
