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
 *  DCDIdle.c
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "MenuCUIGprot.h"
#include "inlinecuigprot.h"
#include "DCDGprot.h"
#include "mmi_rp_app_dcd_def.h"
#include "DCDProt.h"
#include "plDefine.h"
#include "DCDAgentInterface.h"
#include "ui_dcd_porting.h"
#include "IdleGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wgui_categories_idlescreen.h"
#include "dcdagentdefine.h"
#include "plx_dcd_wrapper.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "pl_ishell.h"
#include "GlobalConstants.h"
#include "mmi_frm_scenario_gprot.h"
#include "sdktypedef.h"
#include "FileMgrCuiGProt.h"

static MMI_BOOL g_dcd_idle_normal_entry;
static MMI_BOOL g_dcd_idle_normal_exit;

#define IS_SHIFT_STORY    1
#define IS_NO_SHIFT_STORY 0


MMI_ID  g_dcd_grp_id;
static mmi_ret mmi_dcd_grp_proc(mmi_event_struct *evt);

extern mmi_dcd_setting_data_struct  * g_mmi_dcd_setting_cntx_p;

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_enable_idle_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_dcd_enable_idle_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_dcd_is_switch_on() && MMI_TRUE == mmi_dcd_is_idle_on())
    {
        idle_screen_enable_dcd_display(mmi_dcd_get_agent_handle());
#if defined(__MMI_TOUCH_SCREEN__)
        idle_screen_register_dcd_pen_handler(ui_dcd_pen_handler);
#endif /* defined(__MMI_TOUCH_SCREEN__)  */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_idlescreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dcd_entry_idlescreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_set_view_mode(mmi_dcd_get_agent_handle(), eDCD_VIEW_IDLE);

    if (MMI_FALSE == mmi_dcd_get_normal_entry())
    {
        ui_dcd_set_screen_entry_normal(MMI_FALSE);
    }
    else
    {
        mmi_dcd_set_normal_entry(MMI_FALSE);
        ui_dcd_set_screen_entry_normal(MMI_TRUE);
    }

    mmi_dcd_enable_idle_display();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_idlescreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_dcd_exit_idlescreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_dcd_is_switch_on())
    {
        if (mmi_idle_is_active())
        {
            mmi_dcd_set_pause_mode(IS_NO_SHIFT_STORY); /* not shift story */
        }
        else
        {               
            mmi_dcd_set_pause_mode(IS_SHIFT_STORY); /* shift story */
        }

        if (MMI_FALSE == mmi_dcd_get_normal_exit())
        {
            ui_dcd_set_screen_exit_normal(MMI_FALSE);
        }
        else
        {
            ui_dcd_set_screen_exit_normal(MMI_TRUE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_idle_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_idle_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DCD_IDLE_DISPLAY_ON == g_mmi_dcd_setting_cntx_p->dcd_idle_display)
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
 *  mmi_dcd_get_normal_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_get_normal_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dcd_idle_normal_entry;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_normal_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  normal      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_normal_entry(MMI_BOOL normal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_idle_normal_entry = normal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_normal_first_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  normal      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_set_normal_first_entry(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_idle_normal_entry = MMI_TRUE;
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_normal_first_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  normal      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_set_normal_first_exit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_idle_normal_exit = MMI_FALSE;
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_normal_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_get_normal_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dcd_idle_normal_exit;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_normal_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  normal      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_normal_exit(MMI_BOOL normal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_idle_normal_exit = normal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_idle_to_story_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_idle_to_story_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_VIEW_MODE view_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    view_mode = emDCDAgent_GetViewMode(g_dcd_agent.agent_handle);

    if (view_mode == eDCD_VIEW_IDLE_NO_STORY)
    {
        mmi_dcd_entry_channel_list_screen();
    }
    else
    {
        g_dcd_agent.channel_id[0] = 0;
        g_dcd_agent.entry_id[0] = 0;

        emDCDAgent_GetStoryID(g_dcd_agent.agent_handle, g_dcd_agent.channel_id, g_dcd_agent.entry_id);
        if (g_dcd_agent.entry_id[0]== '\0')
        {
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
            return;
        }
        
        mmi_dcd_pre_entry_story_viewer(eDCD_VIEW_STORY_FULL_CHANNEL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_idle_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_idle_key_handler(U32 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    emEventType dcd_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dcd_event.EventType = eMSG_KEYDOWN;

    dcd_event.nParam1 = key_code;

    dcd_event.nPlatformType = 0;
    dcd_event.nParam2 = 0;

    emDCDAgent_PostMessage(g_dcd_agent.agent_handle, (PL_SHELL_EVENT*) & dcd_event);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_idle_prev_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_idle_prev_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_idle_key_handler(KEY_UP_ARROW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_idle_next_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_idle_next_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_idle_key_handler(KEY_DOWN_ARROW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_idle_prev_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_idle_prev_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_idle_key_handler(KEY_LEFT_ARROW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_idle_next_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_idle_next_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_idle_key_handler(KEY_RIGHT_ARROW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_wakeup_prompt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_wakeup_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_SWITCH_ON_PROMPT), MMI_EVENT_INFO, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op11_hs_create_root_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_create_root_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_dcd_grp_id != 0) && mmi_frm_group_is_present(g_dcd_grp_id))
    {
        mmi_frm_group_close(g_dcd_grp_id);
    }

    g_dcd_grp_id = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_dcd_grp_proc, NULL);
    mmi_frm_group_enter(g_dcd_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_grp_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dcd_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct   *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {  
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            menu_evt = (cui_menu_event_struct *)evt;
            cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
            if (menu_evt->parent_menu_id == MENU_ID_DCD_VIEWER_OPTION_FORWARD)
            {
                BRSTR title, summary;
                title = emDCDAgent_GetEntryTitle(g_dcd_agent.entry_handle);
                summary = emDCDAgent_GetEntrySummary(g_dcd_agent.entry_handle);
                if((title == BRNULL) && (summary == BRNULL))
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_DCD_FORWARD_TO_SMS, MMI_TRUE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_DCD_FORWARD_TO_SMS, MMI_FALSE);
                }

            #ifndef __MMI_MMS__ /* __MMI_MMS__ */
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_DCD_FORWARD_TO_MMS, MMI_TRUE);
            #else /* __MMI_MMS__ */
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_DCD_FORWARD_TO_MMS, MMI_FALSE);
            #endif /* __MMI_MMS__ */

            #ifndef __MMI_EMAIL__ /* __MMI_EMAIL__ */
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_DCD_FORWARD_TO_EMAIL, MMI_TRUE);
            #else /* __MMI_EMAIL__ */
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_DCD_FORWARD_TO_EMAIL, MMI_FALSE);
            #endif /* __MMI_EMAIL__ */                
            }

            break;
        }

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            menu_evt = (cui_menu_event_struct *)evt;
            /* channel list options menu */
            if (menu_evt->highlighted_menu_id == MENU_ID_DCD_CHANNEL_OPTION_VIEW)
            {
                mmi_dcd_entry_story_list();
			}
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_CHANNEL_OPTION_REFRESH)
            {
                mmi_dcd_pre_entry_manual_update();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_CHANNEL_OPTION_ADD_CHANNEL)
            {
                mmi_dcd_set_url_type(MMI_DCD_URL_ADD_CHAN);
                mmi_dcd_launch_wap_browser();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_CHANNEL_OPTION_DEL_CHANNEL)
            {
                mmi_dcd_set_url_type(MMI_DCD_URL_DEL_CHAN);
                mmi_dcd_launch_wap_browser();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_CHANNEL_OPTION_SAVED_STORY)
            {
                mmi_dcd_pre_entry_saved_story_list();
            }
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            /* settings menu */
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SETTING_IDLE_DISPLAY)
            {
                mmi_dcd_entry_idle_display_settings_screen();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SETTING_CONN_MODE)
            {
                mmi_dcd_entry_setting_conn_mode();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_CONN_MODE_ALWAYS)
            {
                mmi_dcd_setting_conn_mode_save(0);
                cui_menu_close(menu_evt->sender_id);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_CONN_MODE_HOME_ONLY)
            {
                mmi_dcd_setting_conn_mode_save(1);
                cui_menu_close(menu_evt->sender_id);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_CONN_MODE_MANUAL)
            {
                mmi_dcd_setting_conn_mode_save(2);
                cui_menu_close(menu_evt->sender_id);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SETTING_SWITCH)
            {
                mmi_dcd_entry_switch_off_prompt();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SETTING_UPDATE_LOG)
            {
                mmi_dcd_entry_setting_update_log();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SETTING_RESET)
            {
                mmi_dcd_settings_reset_confirm();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SETTING_HELP)
            {
                mmi_dcd_entry_help_info();
            }
            /* story list options menu */
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_STORY_LIST_OPTION_VIEW)
            {
                mmi_dcd_enter_story_viewer();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_STORY_LIST_OPTION_REFRESH)
            {
                mmi_dcd_pre_entry_manual_update();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_STORY_LIST_OPTION_SAVED_STORY)
            {
                mmi_dcd_pre_entry_saved_story_list();
            }
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            /* saved story list options menu */
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SAVED_STORY_LIST_OPTION_VIEW)
            {
                mmi_dcd_enter_saved_story_viewer();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SAVED_STORY_LIST_OPTION_DELETE)
            {
                mmi_dcd_saved_story_list_delete_confirm();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_SAVED_STORY_LIST_OPTION_DELETE_ALL)
            {
                mmi_dcd_saved_story_list_delete_all_confirm();
            }
            /* story viewer options menu */
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_VIEWER_OPTION_GO_TO)
            {
                mmi_dcd_viewer_go_to();
			}
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_VIEWER_OPTION_SAVE_STORY)
            {
                mmi_dcd_viewer_save_story();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE)
            {
                mmi_dcd_pre_entry_object_list();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_VIEWER_OPTION_DELETE)
            {
                mmi_dcd_viewer_delete_story();
            }
            /* forward menu */
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_FORWARD_TO_SMS)
            {
                mmi_dcd_forward_sms();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_FORWARD_TO_MMS)
            {
                mmi_dcd_forward_mms();
            }
        #ifdef __MMI_EMAIL__
            else if (menu_evt->highlighted_menu_id == MENU_ID_DCD_FORWARD_TO_EMAIL)
            {
                mmi_dcd_forward_email();
            }
        #endif
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            menu_evt = (cui_menu_event_struct *)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            S32 select_index;
            cui_event_inline_csk_press_struct* inline_csk_press_p = (cui_event_inline_csk_press_struct *)evt;

            cui_inline_get_value(inline_csk_press_p->sender_id, DCD_APP_INLINE_SELECT_SCROLL_SPEED, &select_index);
            g_mmi_dcd_setting_cntx_p->dcd_scroll_speed = (U8)select_index;

            cui_inline_get_value(inline_csk_press_p->sender_id, DCD_APP_INLINE_SELECT_READ_DISPLAY, &select_index);
            g_mmi_dcd_setting_cntx_p->dcd_read_item_display = (U8)select_index;

            mmi_dcd_idle_display_settings_save();

            cui_inline_close(inline_csk_press_p->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            S32 select_index;
            cui_event_inline_submit_struct * inline_submit_p = (cui_event_inline_submit_struct *)evt;

            cui_inline_get_value(inline_submit_p->sender_id, DCD_APP_INLINE_SELECT_SCROLL_SPEED, &select_index);
            g_mmi_dcd_setting_cntx_p->dcd_scroll_speed = (U8)select_index;

            cui_inline_get_value(inline_submit_p->sender_id, DCD_APP_INLINE_SELECT_READ_DISPLAY, &select_index);
            g_mmi_dcd_setting_cntx_p->dcd_read_item_display = (U8)select_index;

            mmi_dcd_idle_display_settings_save();

            cui_inline_close(inline_submit_p->sender_id);
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct * inline_abort_p = (cui_event_inline_abort_struct *)evt;
            cui_inline_close(inline_abort_p->sender_id);
            break;
        }

	    case EVT_ID_CUI_INLINE_NOTIFY:
		    break;

        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            mmi_dcd_cui_storage_selector_proc((cui_storage_selector_result_event_struct *)evt);
            break;
        }

        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            mmi_dcd_cui_filename_editor_proc((cui_filename_editor_result_event_struct *)evt);
            break;
        }

        default:
            break;
    }
    
    return MMI_RET_OK;
}


#endif /* __MMI_OP01_DCD__ */ 

