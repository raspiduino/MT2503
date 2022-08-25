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
*  DCDChannelList.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  DCD channel list
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "Conversions.h"
#include "app_str.h"
#include "IdleGprot.h"
#include "UcmSrvGprot.h"
#include "DCDGProt.h"
#include "DCDProt.h"
#include "custom_dcd.h"
#include "MenuCUIGprot.h"
#include "mmi_rp_app_dcd_def.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "dcdagentdefine.h"
#include "sdktypedef.h"
#include "dcdagentinterface.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "wgui_categories_list_op.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "string.h"
#include "app_mem.h"
#include "stdio.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "AlertScreen.h"
#include "plx_dcd_wrapper.h"
#include "browser_api.h"
#include "wgui_categories_text_viewer.h"
#include "Unicodexdcl.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_history_gprot.h"
#include "CommonScreensResDef.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static S8                **g_title_list_pp = NULL;
static U8                g_mmi_dcd_url_type = MMI_DCD_URL_ADD_CHAN;
static MMI_BOOL          g_isUserAbort;
static MMI_BOOL          g_isManSyncStopped;
static MMI_BOOL          g_isManSyncFailRetry;
static mmi_dcd_refresh_cnxt  g_dcd_manual_update;
mmi_dcd_refresh_cnxt  * g_dcd_manual_update_p = &g_dcd_manual_update;   

static void mmi_dcd_exit_channel_list_screen(void);
static void mmi_dcd_channel_item_highlight_hdlr(S32 item_index);
static void mmi_dcd_entry_channel_list_option(void);
static void mmi_dcd_entry_manual_update(void);
static void mmi_dcd_manual_update_callback(MMI_BOOL success);
static void mmi_dcd_abort_manual_update(void);
static void mmi_dcd_entry_manual_update_prompt(void);
static void mmi_dcd_entry_manual_update_roaming_prompt(void);
static void mmi_dcd_option_manual_update_handler(void);
static void mmi_dcd_manual_update_failure(void);
static void mmi_dcd_manual_update_success(void);
static void mmi_dcd_update_sync_info_str(EDCD_MSG_CODE a_eMsgCode);
static void mmi_dcd_manual_update_storage_full(void);
static void mmi_dcd_entry_chan_ext(void);
static S32  mmi_dcd_get_chan_list_index(BRSTR hChannelID);
static S32  mmi_dcd_get_channel_title_list(HDCD_Agent agent);
static MMI_BOOL mmi_dcd_channel_get_icon_path(HDCD_Agent agent, S32 index, S8 * buf, S32 buflen);
static MMI_BOOL mmi_dcd_channel_list_get_icon(S32 item_index, S8* path);
static MMI_BOOL mmi_dcd_refresh_failure_prompt_is_call_interrupt_allow(void);
static void mmi_dcd_refresh_failure_prompt_add_history(U16 scrnId, FuncPtr entryFuncPtr);
static void mmi_dcd_pre_entry_manual_update_failure_prompt(void);
static void mmi_dcd_entry_channel_list_screen_int(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_list_screen
 * DESCRIPTION
 *  entry channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_channel_list_screen(void)
{
    mmi_dcd_create_root_gid();
    mmi_dcd_entry_channel_list_screen_int();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_list_screen
 * DESCRIPTION
 *  entry channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_channel_list_screen_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *gui_buffer = NULL;
    S32 channel_cnt;
    U8  read_state_list[MMI_DCD_MAX_STORY_COUNT] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_CHANNEL_LIST, mmi_dcd_exit_channel_list_screen, mmi_dcd_entry_channel_list_screen_int, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (gui_buffer == NULL)
    {
        g_dcd_agent.update_flag = g_dcd_agent.update_flag & (~MMI_DCD_CHANNEL_LIST_UPDATE_MASK);
    }
    else
    {
        if (g_dcd_agent.update_flag & MMI_DCD_CHANNEL_LIST_UPDATE_MASK)
        {
            gui_buffer = NULL;
            g_dcd_agent.update_flag = g_dcd_agent.update_flag & (~MMI_DCD_CHANNEL_LIST_UPDATE_MASK);
        }
    }

    mmi_dcd_set_back_state(MMI_FALSE);
    mmi_dcd_set_manual_updte_scr_id(SCR_ID_DCD_CHANNEL_LIST);
    channel_cnt = mmi_dcd_get_channel_title_list(g_dcd_agent.agent_handle);
    
    RegisterHighlightHandler(mmi_dcd_channel_item_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory182Screen(
        (UI_string_type)GetString(STR_ID_DCD_CHANNEL_LIST),
        (PU8)GetImage(IMG_ID_DCD_SUB_ICON),
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        channel_cnt,
        (U8**)g_title_list_pp,
        mmi_dcd_channel_list_get_icon,
        read_state_list,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_channel_list_option, KEY_EVENT_UP);    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_entry_story_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_channel_list_option
 * DESCRIPTION
 *  entry channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_channel_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = cui_menu_create(
                        g_dcd_grp_id,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_DCD_CHANNEL_LIST_OPTION,
                        MMI_TRUE,
                        NULL);

    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(menu_gid, get_image(IMG_ID_DCD_SUB_ICON));
        cui_menu_run(menu_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_channel_item_highlight_hdlr
 * DESCRIPTION
 *  channel item highlight handler
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_channel_item_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_agent.channel_index = item_index;
    g_dcd_agent.channel_handle = emDCDAgent_GetChannelAt(g_dcd_agent.agent_handle, g_dcd_agent.channel_index);
    strcpy(g_dcd_agent.channel_id, emDCDAgent_GetChannelID(g_dcd_agent.channel_handle));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_channel_list_screen
 * DESCRIPTION
 *  exit channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_title_list_pp)
    {
        applib_mem_screen_free(g_title_list_pp);
    }
    g_title_list_pp = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_channel_list_get_icon
 * DESCRIPTION
 *  get icon of specific channel
 * PARAMETERS
 *  item_index  [in]    item index
 *  path        [out]   icon path
 * RETURNS
 * TRUE/FALSE
 *****************************************************************************/
MMI_BOOL mmi_dcd_channel_list_get_icon(S32 item_index, S8* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    result;
    S32         buflen = SRV_FMGR_PATH_MAX_LEN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_dcd_channel_get_icon_path(g_dcd_agent.agent_handle, item_index, path, buflen);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_channel_title_list
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  agent               [IN] dcd agent handle  
 *  index               [IN] channel index
 *  buf                 [IN] channel title buffer
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_dcd_get_channel_title_list(HDCD_Agent agent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32             entry_cnt, channel_cnt,unread_cnt;
    S8  *           title;
    HDCD_Channel    hChannel;
    HDCD_Entry      entry_handle;
    BRBOOL          read_state;
    S8              asc_buf[8];
    S8              ucs_buf[16];
    S32             len, char_num, chan_index,story_index;
    MMI_BOOL        is_truncated = MMI_FALSE;
    S32             buflen, offset;
    S8  *           buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_cnt = emDCDAgent_GetChannelCount(agent);
    if (channel_cnt <= 0)
    {
        return -1;
    }
    else if (channel_cnt > MMI_DCD_MAX_CHANNEL_COUNT)
    {
        channel_cnt = MMI_DCD_MAX_CHANNEL_COUNT;
    }

    buflen = (sizeof(S8*) + MMI_DCD_CHANNEL_TITLE_LEN) * channel_cnt;
    g_title_list_pp = (S8 **) applib_mem_screen_alloc(buflen);

    for (chan_index = 0; chan_index < channel_cnt; chan_index++)
    {
        hChannel = emDCDAgent_GetChannelAt(agent, chan_index);
        entry_cnt = emDCDAgent_GetChannelEntryCount(hChannel);
        if (entry_cnt > MMI_DCD_MAX_STORY_COUNT)
        {    
            entry_cnt = MMI_DCD_MAX_STORY_COUNT;
        }    
        
        unread_cnt = 0;
        for (story_index = 0; story_index < entry_cnt; story_index++)
        {
            entry_handle = emDCDAgent_GetChannelEntryAt(hChannel, story_index);
            emDCDAgent_IsReadedEntry(entry_handle, &read_state);
            if (read_state != BRTRUE) unread_cnt++;
        }
        
	    sprintf(asc_buf, "(%d/%d)", unread_cnt,entry_cnt);

        offset = sizeof(S8*) * channel_cnt + MMI_DCD_CHANNEL_TITLE_LEN * chan_index;
        buf = g_title_list_pp[chan_index] = (S8*)g_title_list_pp + offset;
        
        buflen = MMI_DCD_CHANNEL_TITLE_LEN;
        buflen -= strlen(asc_buf) * 2;

	    title = emDCDAgent_GetChannelTitle(hChannel);
        /* title = emDCDAgent_GetChannelSummary(hChannel); */
        char_num = mmi_chset_utf8_strlen((kal_uint8*)title);
        is_truncated = MMI_FALSE;
        if ( char_num >= buflen / 2)
        {
            is_truncated = MMI_TRUE;
            buflen -= 4;
        }
	    /* include null terminal */
        len = mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buf, buflen, (kal_uint8 *)title );
        if (is_truncated)
        {
            app_ucs2_strcat((kal_int8 *)buf, (kal_int8 *)L"..");
        }

        app_asc_str_to_ucs2_str((kal_int8 *)ucs_buf, (kal_int8 *)asc_buf);
        app_ucs2_strcat((kal_int8 *)buf, (kal_int8 *)ucs_buf);
    }

    return channel_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_channel_get_icon_path
 * DESCRIPTION
 *  get dcd channel icon
 * PARAMETERS
 *  agent       [IN]        dcd agent handle
 *  index       [IN]        channel index
 *  buf         [IN]        channel title buffer
 *  buflen      [IN]        buffer len
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_channel_get_icon_path(HDCD_Agent agent, S32 index, S8 * buf, S32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL        is_image_exist = MMI_FALSE;
    HDCD_Channel    hChannel;
    EDCD_AGENT_RESULT result;
    S32             nChannelCnt;
    S32             i, nContentCnt, len;
    HDCD_Content    pContent;
    const S8 *      content_type;
    S8 *            path_buf = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nChannelCnt = emDCDAgent_GetChannelCount(agent);
    if (index >= nChannelCnt)
    {
        return MMI_FALSE;
    }
    
    hChannel = emDCDAgent_GetChannelAt(agent, index);
    nContentCnt = emDCDAgent_GetChannelContentCount(hChannel);
    path_buf = OslMalloc(SRV_FMGR_PATH_MAX_LEN);
    for( i = 0; i < nContentCnt; i++)
    {
        pContent = emDCDAgent_GetChannelContentAt(hChannel, i);
        content_type = emDCDAgent_GetContentType(pContent);
        if (mmi_dcd_strnicmp(content_type, "image/", 6) == 0)
        {
			result = emDCDAgent_GetContentFullPath(pContent, path_buf);
            if (result == eDCD_SUCCESS)
            {
                is_image_exist = MMI_TRUE;
                break; 
            }
        }
    }
 
	if (!is_image_exist)
    {
		emDCDAgent_GetDefaultImageFullPath(path_buf);
	}

    len = mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buf, buflen, (kal_uint8 *)path_buf);

    if (path_buf)
    {
        OslMfree(path_buf);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_prompt
 * DESCRIPTION
 *  prompt user after sync.
 * PARAMETERS
 * success
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_sync_prompt(MMI_BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SYNC_RESULT_PROMPT, success);

    if ( success &&
		  ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_CHANNEL_LIST)
         ||(mmi_frm_scrn_get_active_id() == SCR_ID_DCD_STORY_LIST)) )
    {
        UI_string_type string = (UI_string_type)GetString(STR_ID_DCD_CONTENT_UPDATED);
        mmi_popup_display((WCHAR*)(string), MMI_EVENT_INFO, NULL);
    }
    if (success)
    {
        g_dcd_agent.update_flag = 0xFF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sleepin_hdlr
 * DESCRIPTION
 *  called when into sleep
 * PARAMETERS
 * success
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_sleepin_hdlr(mmi_event_struct * arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32      view_mode;
    U16      scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_ENTER_SLEEPIN_HDLR);

    if (! mmi_dcd_is_switch_on())
        return MMI_RET_OK;

    view_mode = mmi_dcd_get_view_mode(g_dcd_agent.agent_handle);  
    scr_id    = mmi_frm_scrn_get_active_id();
    
    if ((view_mode == eDCD_VIEW_IDLE) && (mmi_idle_is_active()) && mmi_dcd_is_idle_on())
    {
        mmi_dcd_set_pause_mode(0);
        mmi_dcd_show_pause(0);
    }
    else if ((((view_mode == eDCD_VIEW_STORY_FULL_CHANNEL)||(view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL)) && 
    	(scr_id == SCR_ID_DCD_STORY_VIEWER))
       ||((view_mode == eDCD_VIEW_SAVEDSTORY) && (scr_id == SCR_ID_DCD_STORY_VIEWER)))
    {
        mmi_dcd_set_pause_mode(1);
        mmi_dcd_show_pause(1);
    }

    mmi_dcd_shift_timer_into_sleep();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sleepout_hdlr
 * DESCRIPTION
 *  called when into sleep
 * PARAMETERS
 * success
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_sleepout_hdlr(mmi_event_struct * arg)
{ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32      view_mode;
    U16      scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_ENTER_SLEEPOUT_HDLR);
    mmi_dcd_set_pause_mode(1);

    if (! mmi_dcd_is_switch_on())
        return MMI_RET_OK;

    view_mode = mmi_dcd_get_view_mode(g_dcd_agent.agent_handle);  
    scr_id    = mmi_frm_scrn_get_active_id();
    
    if ( ((view_mode == eDCD_VIEW_IDLE) && (mmi_idle_is_active()) && (mmi_dcd_is_idle_on()) )
       ||(((view_mode == eDCD_VIEW_STORY_FULL_CHANNEL)||(view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL)) && (scr_id == SCR_ID_DCD_STORY_VIEWER))
       ||((view_mode == eDCD_VIEW_SAVEDSTORY) && (scr_id == SCR_ID_DCD_STORY_VIEWER)))
    {
        mmi_dcd_show_resume();
    }

    mmi_dcd_shift_timer_out_sleep();  

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_launch_wap_browser
 * DESCRIPTION
 *  dcd launch wap browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_launch_wap_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 * url = NULL;
    U8         url_ucs2[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_dcd_url_type == MMI_DCD_URL_ADD_CHAN)
    {
        url = (kal_int8 *)dcd_custom_get_url_add_channel();
    } 
    else if (g_mmi_dcd_url_type == MMI_DCD_URL_DEL_CHAN)
    {
        url = (kal_int8 *)dcd_custom_get_url_del_channel();
    }
    else if (g_mmi_dcd_url_type == MMI_DCD_URL_HELP)
    {
        url = (kal_int8 *)dcd_custom_get_url_help();
    }

    app_asc_str_to_ucs2_str((kal_int8 *)url_ucs2, url);
    wap_start_browser(WAP_BROWSER_GOTO_URL, url_ucs2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_url_type
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_url_type(U8 url_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (url_type)
    {
        case MMI_DCD_URL_ADD_CHAN:
            g_mmi_dcd_url_type = MMI_DCD_URL_ADD_CHAN;
            break;

        case MMI_DCD_URL_DEL_CHAN:
            g_mmi_dcd_url_type = MMI_DCD_URL_DEL_CHAN;
            break;

        case MMI_DCD_URL_HELP:
            g_mmi_dcd_url_type = MMI_DCD_URL_HELP;
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_manual_update
 * DESCRIPTION
 *  mmi_dcd_pre_entry_manual_update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_manual_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_isManSyncFailRetry = MMI_FALSE;
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_UPDATE_PROGRESS);
    
    if (g_mmi_dcd_setting_cntx_p->dcd_conn_mode == DCD_CONN_MODE_MANUAL)
    {
        mmi_dcd_entry_manual_update_prompt();
    }
    else if ((g_mmi_dcd_setting_cntx_p->dcd_conn_mode == DCD_CONN_MODE_HOME) && (mmi_dcd_is_roaming()))
    {
        mmi_dcd_entry_manual_update_roaming_prompt();
    }
    else
    {
        mmi_dcd_option_manual_update_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_manual_update_prompt
 * DESCRIPTION
 *  mmi_dcd_entry_manual_update_prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_manual_update_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_PROMPT, NULL, mmi_dcd_entry_manual_update_prompt, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory21Screen(
        STR_ID_DCD_REFRESH,
        IMG_ID_DCD_SUB_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        STR_ID_DCD_MANUAL_UPDATE_PROMPT,
        gui_buffer);

    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_FAIL_PROMPT);
    SetLeftSoftkeyFunction(mmi_dcd_option_manual_update_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_option_manual_update_handler, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_manual_update_roaming_prompt
 * DESCRIPTION
 *  mmi_dcd_entry_manual_update_roaming_prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_manual_update_roaming_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_ROAMING_PROMPT, NULL, mmi_dcd_entry_manual_update_roaming_prompt, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory21Screen(
        STR_ID_DCD_REFRESH,
        IMG_ID_DCD_SUB_ICON,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_DCD_MAN_UPDATE_WHEN_ROAMING_PROMPT,
        gui_buffer);

    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_FAIL_PROMPT);
    SetLeftSoftkeyFunction(mmi_dcd_option_manual_update_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_abort_manual_update, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_option_manual_update_handler, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 * mmi_dcd_option_manual_update_handler
 * DESCRIPTION
 *  mmi_dcd_option_manual_update_handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_option_manual_update_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL isSyncing = MMI_FALSE;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_dcd_user_to_sync(&isSyncing, mmi_dcd_manual_update_callback);
    
    if(isSyncing == MMI_TRUE)
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_BACKGROUND_SYNC_PROGRESS), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
	    if (MMI_TRUE == result)
        {
            mmi_dcd_entry_manual_update();
            g_isManSyncStopped = MMI_FALSE;
            g_isUserAbort = MMI_FALSE;
        }
        else
        {
         	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
        }
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_screen_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dcd_manual_update_screen_leave_proc (mmi_event_struct *evt)
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
            break;
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_MANUAL_UPDATE_STOP, g_isManSyncStopped);          
            if(g_isManSyncStopped == MMI_FALSE)
            {
                g_isUserAbort = MMI_TRUE;
                MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_MANUAL_UPDATE_ABORT, g_isUserAbort);
            
                mmi_dcd_stop_sync();
            }
            break;
        }

        default:
            return MMI_RET_ERR;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_manual_update
 * DESCRIPTION
 *  mmi_dcd_entry_manual_update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_manual_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_UPDATE_PROGRESS, NULL, mmi_dcd_entry_manual_update, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(g_dcd_grp_id, SCR_ID_DCD_UPDATE_PROGRESS, mmi_dcd_manual_update_screen_leave_proc);

    mmi_ucs2cpy((S8*) g_dcd_manual_update_p->info_str, GetString(STR_GLOBAL_CONNECTING));
    
    ShowCategory66Screen(
        STR_ID_DCD_REFRESH,
        IMG_ID_DCD_SUB_ICON,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        g_dcd_manual_update_p->info_str,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_FAIL_PROMPT);
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_PROMPT);
    SetRightSoftkeyFunction(mmi_dcd_abort_manual_update, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_callback
 * DESCRIPTION
 *  mmi_dcd_manual_update_callback
 * PARAMETERS
 *  IsSuccess       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_manual_update_callback(MMI_BOOL IsSuccess)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_MANUAL_UPDATE_CALLBACK_ENTER);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_MANUAL_UPDATE_ABORT, g_isUserAbort);
    
    if ((g_isUserAbort == MMI_FALSE) && ((mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS) || (IsScreenPresent(SCR_ID_DCD_UPDATE_PROGRESS) == MMI_TRUE)))
    {
        if(IsSuccess == MMI_TRUE)
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_MANUAL_UPDATE_CALLBACK_SUCCESS);
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
            
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_MANUAL_UPDATE_CALLBACK_ERROR);
            mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
        }        

        g_isManSyncStopped = MMI_TRUE;
        mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_UPDATE_PROGRESS);
        mmi_dcd_disconnect_bearer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_abort_manual_update
 * DESCRIPTION
 *  mmi_dcd_abort_manual_update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_abort_manual_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_isUserAbort = MMI_TRUE;
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_UPDATE_PROGRESS);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_display_manual_update_info
 * DESCRIPTION
 *  mmi_dcd_display_manual_update_info
 * PARAMETERS
 *  IsSuccess       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_display_manual_update_info(EDCD_MSG_CODE a_eMsgCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_dcd_is_manual_updte())
    {     
        switch(a_eMsgCode)
        {
            case eDCD_MSG_CONNECT_SERVER_SUCCESS:
                mmi_dcd_update_sync_info_str(eDCD_MSG_CONNECT_SERVER_SUCCESS);
                break;

            case eDCD_MSG_SYNCPKG_PARSING_SUCCESS:
                mmi_dcd_update_sync_info_str(eDCD_MSG_SYNCPKG_PARSING_SUCCESS);
                break;

            case eDCD_MSG_SYNC_COMPLETE:
                mmi_dcd_manual_update_success();
                break;

            case eDCD_MSG_ERR_SYNC:
                mmi_dcd_pre_entry_manual_update_failure_prompt();
                break;

            case eDCD_MSG_ERR_STORAGE_FULL:
                mmi_dcd_manual_update_storage_full();
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_success
 * DESCRIPTION
 *  mmi_dcd_manual_update_success
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_manual_update_success()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
    g_isManSyncStopped = MMI_TRUE;
    g_dcd_agent.update_flag = 0xFF;
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_UPDATE_PROGRESS);
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_PROMPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_failure_screen_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dcd_manual_update_failure_screen_leave_proc (mmi_event_struct *evt)
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
            break;
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            if (g_isManSyncFailRetry)
            {
                mmi_dcd_user_sync_fail_abort();
            }
            break;
        }

        default:
            return MMI_RET_ERR;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_failure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_manual_update_failure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_FAIL_PROMPT, NULL, mmi_dcd_manual_update_failure, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    mmi_frm_scrn_set_leave_proc(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_FAIL_PROMPT, mmi_dcd_manual_update_failure_screen_leave_proc);

    g_isManSyncFailRetry = MMI_TRUE;

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) GetString(STR_ID_DCD_MANUAL_UPDATE_AGAIN),
        (U16) mmi_get_event_based_image(MMI_EVENT_QUERY),
        gui_buffer);
        
    g_isManSyncStopped = MMI_TRUE;
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_PROMPT);
    SetLeftSoftkeyFunction(mmi_dcd_pre_entry_manual_update, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_abort_manual_update, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_pre_entry_manual_update, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_manual_update_storage_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_manual_update_storage_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_MANUAL_UPDATE_STORAGE_FULL_PROMPT, NULL, mmi_dcd_manual_update_storage_full, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory21Screen(
        STR_ID_DCD_REFRESH,
        IMG_ID_DCD_SUB_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        STR_ID_DCD_MANUAL_UPDATE_STORAGE_FULL,
        gui_buffer);

    g_isManSyncStopped = MMI_TRUE;
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_UPDATE_PROGRESS);
    SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_update_sync_info_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_update_sync_info_str(EDCD_MSG_CODE a_eMsgCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(a_eMsgCode)
    {
        case eDCD_MSG_CONNECT_SERVER_SUCCESS:
            mmi_ucs2cpy((S8*) g_dcd_manual_update_p->info_str, GetString(STR_GLOBAL_DOWNLOADING));
            break;

        case eDCD_MSG_SYNCPKG_PARSING_SUCCESS:
            mmi_ucs2cpy((S8*) g_dcd_manual_update_p->info_str, GetString(STR_GLOBAL_DOWNLOADING));
            break;

        default:
            break;
    }

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DCD_UPDATE_PROGRESS)
    {
        cat66_update_progress_string();
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_manual_updte_scr_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_manual_updte_scr_id(U16 update_scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_manual_update_p->scr_id = update_scr_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_on_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_switch_on_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {        
        mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
        
        switch (alert->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_dcd_entry_chan_ext();
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_chan_from_mobile_service
 * DESCRIPTION
 *  Enter DCD channel list screen from china mobile service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_chan_from_mobile_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_dcd_is_bt_access_profile_mode())
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    if (!mmi_dcd_is_switch_on())
    {
        do {
        mmi_confirm_property_struct arg;
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.callback = (mmi_proc_func)mmi_dcd_switch_on_confirm_callback;
        mmi_confirm_display((WCHAR *)get_string(STR_ID_DCD_SWITCH_ON), MMI_EVENT_QUERY, &arg);
        } while(0);
    }
    else
    {
        mmi_dcd_entry_channel_list_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_chan_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_chan_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_dcd_setting_cntx_p->dcd_switch = DCD_ENABLE_ON;
    mmi_dcd_write_setting_value();
    mmi_dcd_switch(DCD_ENABLE_ON);
    do {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_dcd_entry_channel_list_screen);
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &arg);
	} while(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_chan_from_story_list
 * DESCRIPTION
 *  entry channel list screen from story list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_chan_from_story_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer = NULL;
    S32 channel_cnt, highlighted_item = 0;
    U8  read_state_list[MMI_DCD_MAX_STORY_COUNT] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_CHANNEL_LIST, mmi_dcd_exit_channel_list_screen, mmi_dcd_entry_chan_from_story_list, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_STORY_LIST);

    if (gui_buffer == NULL)
    {
        if (g_dcd_agent.update_flag & MMI_DCD_CHANNEL_LIST_UPDATE_MASK)
        {
            highlighted_item = 0;
        }
        else
        {
            highlighted_item = mmi_dcd_get_chan_list_index(g_dcd_agent.channel_id);
        }
        g_dcd_agent.update_flag = g_dcd_agent.update_flag & (~MMI_DCD_CHANNEL_LIST_UPDATE_MASK);
    }
    else
    {
        if (g_dcd_agent.update_flag & MMI_DCD_CHANNEL_LIST_UPDATE_MASK)
        {
            gui_buffer = NULL;
            g_dcd_agent.update_flag = g_dcd_agent.update_flag & (~MMI_DCD_CHANNEL_LIST_UPDATE_MASK);
            highlighted_item = 0;
        }
    }

    mmi_dcd_set_manual_updte_scr_id(SCR_ID_DCD_CHANNEL_LIST);
    channel_cnt = mmi_dcd_get_channel_title_list(g_dcd_agent.agent_handle);
    RegisterHighlightHandler(mmi_dcd_channel_item_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory182Screen(
        (UI_string_type)GetString(STR_ID_DCD_CHANNEL_LIST),
        (PU8)GetImage(IMG_ID_DCD_SUB_ICON),
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        (PU8)GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        channel_cnt,
        (U8**)g_title_list_pp,
        mmi_dcd_channel_list_get_icon,
        read_state_list,
        highlighted_item,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_channel_list_option, KEY_EVENT_UP);    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_entry_story_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_chan_list_index
 * DESCRIPTION
 *  mmi_dcd_get_chan_list_index
 * PARAMETERS
 *  hChannel        [IN]        
 *  agent(?)        [IN]        dcd channel handle(?)
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_dcd_get_chan_list_index(BRSTR hChannelID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Channel hChan;
    S32          index, chan_count;
    BRCHAR       hChan_id[MMI_DCD_MAX_CTXT_ID_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chan_count = emDCDAgent_GetChannelCount(g_dcd_agent.agent_handle);
    if (chan_count <= 0)
    {
        return 0;
    }
    else if (chan_count > MMI_DCD_MAX_CHANNEL_COUNT)
    {
        chan_count = MMI_DCD_MAX_CHANNEL_COUNT;
    }
    
    for (index = 0; index < chan_count; index++)
    {
        hChan = emDCDAgent_GetChannelAt(g_dcd_agent.agent_handle, index);
        strcpy(hChan_id, emDCDAgent_GetChannelID(hChan));
        if (strcmp(hChan_id, hChannelID) == 0) 
        {
            return index;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_main_option
 * DESCRIPTION
 *  mmi_dcd_entry_main_option
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_main_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_entry_channel_list_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_refresh_failure_prompt_is_call_interrupt_allow
 * DESCRIPTION
 *  To determine if interrupt from call is allowed
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if screen can be displayed; otherwise, FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_dcd_refresh_failure_prompt_is_call_interrupt_allow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) ||
            srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
    else
#endif /* __MMI_BACKGROUND_CALL__ */
    {
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_refresh_failure_prompt_add_history
 * DESCRIPTION
 *  Common function to add history node when exiting a screen.
 *  This flag determines if the screen shall be added to history or inserted before CM screen
 * PARAMETERS
 *  scrnId              [IN]        Screen index
 *  entryFuncPtr        [IN]        Pointer of the screen entry function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_refresh_failure_prompt_add_history(U16 scrnId, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct new_node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_node_info_init (&new_node_info);
    new_node_info.id = scrnId;
    new_node_info.entry_proc = (mmi_proc_func) entryFuncPtr;

    mmi_frm_scrn_insert(g_dcd_grp_id, SCR_ID_INVALID, &new_node_info, MMI_FRM_NODE_AT_LATEST_FLAG);
    mmi_frm_scrn_set_attribute (g_dcd_grp_id, scrnId, MMI_SCRN_ATTRIB_SMALL_SCRN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_manual_update_failure_prompt
 * DESCRIPTION
 *  This function is used to prepare for entering refresh fail confirm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_pre_entry_manual_update_failure_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* close update progress screen */
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_UPDATE_PROGRESS);
    
    if (!mmi_dcd_refresh_failure_prompt_is_call_interrupt_allow())
    {
        mmi_dcd_refresh_failure_prompt_add_history(
            SCR_ID_DCD_MANUAL_UPDATE_FAIL_PROMPT,
            mmi_dcd_manual_update_failure);
    }
    else
    {
        mmi_dcd_manual_update_failure();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_running_conflict_prompt
 * DESCRIPTION
 *  This function is used to other app which conflicts with DCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_running_conflict_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_CONFLICT_PROMPT), MMI_EVENT_FAILURE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_error_info
 * DESCRIPTION
 *  Function to get the error information includes popup type and string
 * PARAMETERS
 *  error_result:   [IN]    error result type
 *  popup_type:     [OUT]   get the error popup type
 * RETURNS
 *  Get the error popup string id.
 *****************************************************************************/
MMI_STR_ID mmi_dcd_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID  str_id = STR_ID_DCD_CONFLICT_PROMPT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    if (error_result == MMI_DCD_ERR_IS_SYNCING)
    {
        str_id = STR_ID_DCD_CONFLICT_PROMPT;
    }
    return str_id;
}


#endif /* __MMI_OP01_DCD__*/
