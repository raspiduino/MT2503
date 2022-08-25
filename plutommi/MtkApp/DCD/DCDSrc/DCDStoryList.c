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
*  DCDStoryList.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  DCD Story List and Saved Story List
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*==============================================================================*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "MenuCUIGprot.h"
#include "Conversions.h"
#include "app_str.h"
#include "mmi_rp_app_dcd_def.h"
#include "DCDGprot.h"
#include "DCDProt.h"
#include "DCDAgentInterface.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"
#include "sdktypedef.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list_op.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "app_mem.h"
#include "dcdagentdefine.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "string.h"
#include "CommonScreensResDef.h"
#include "Unicodexdcl.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    S8 **title_list_pp;
    S32 total_number;
    S32 saved_story_index;
    S32 saved_story_number;
} mmi_dcd_story_list_struct;

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static S8 *story_list_scr_title_p = NULL;
static U8 read_state_list[MMI_DCD_MAX_STORY_COUNT];
static mmi_dcd_story_list_struct g_story_list_context;

void mmi_dcd_enter_story_viewer(void);
static void mmi_dcd_get_story_title_list(HDCD_Channel hChannel);
static void mmi_dcd_exit_story_list_screen(void);
static void mmi_dcd_exit_saved_story_list_screen(void);
static void mmi_dcd_story_list_highlight_hdlr(S32 index);
static void mmi_dcd_saved_story_list_highlight_hdlr(S32 index);
static void mmi_dcd_get_saved_story_title_list(HDCD_Agent agent);
static void mmi_dcd_entry_saved_story_list(void);
static void mmi_dcd_enter_saved_story_list_option(void);
static void mmi_dcd_saved_story_list_delete_done(void);
static void mmi_dcd_saved_story_list_delete_all_done(void);
//static void mmi_dcd_saved_story_list_delete_abort(void);
static void mmi_dcd_saved_story_list_delete_callback(void);
static void mmi_dcd_get_story_read_state_list(void);
static void mmi_dcd_entry_story_list_option(void);
static void mmi_dcd_get_story_default_image(S8 *path);
static void mmi_dcd_entry_story_list_from_viewer_ext(void);
static void mmi_dcd_entry_story_list_ext(void);
static S8*  mmi_dcd_get_story_list_scr_title(void);
static S32  mmi_dcd_get_story_list_index(HDCD_Channel hChannel, BRSTR hEntryID);
static MMI_BOOL mmi_dcd_story_list_get_icon(S32 item_index, S8 *path);
static MMI_BOOL mmi_dcd_story_get_icon_path(HDCD_Channel hChannel, S32 index, S8 *buf, S32 buflen);
static MMI_BOOL mmi_dcd_saved_story_get_icon_path(S32 index, S8 *buf, S32 buflen);
static MMI_BOOL mmi_dcd_saved_story_list_get_icon(S32 item_index, S8 *path);
static void mmi_dcd_get_saved_story_default_image(S8 *path, HDCD_Entry hEntry);

extern MMI_ID  g_dcd_grp_id;
/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_list
 * DESCRIPTION
 *  entry story list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_story_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_agent.channel_handle = emDCDAgent_GetChannelHandle(g_dcd_agent.agent_handle, g_dcd_agent.channel_id);
    if (g_dcd_agent.channel_handle == NULL)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    g_story_list_context.total_number = emDCDAgent_GetChannelEntryCount(g_dcd_agent.channel_handle);
    if (g_story_list_context.total_number > MMI_DCD_MAX_STORY_COUNT)
    {
        g_story_list_context.total_number = MMI_DCD_MAX_STORY_COUNT;
    }
    else if (g_story_list_context.total_number == 0)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        return;
    }

    mmi_dcd_entry_story_list_ext();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_list_ext
 * DESCRIPTION
 *  entry story list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_story_list_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    S8 *title;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_STORY_LIST, mmi_dcd_exit_story_list_screen, mmi_dcd_entry_story_list_ext, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf(); 

    if (gui_buffer == NULL)
    {
        g_dcd_agent.update_flag = g_dcd_agent.update_flag & (~MMI_DCD_STORY_LIST_UPDATE_MASK);
    }
    else
    {
        if (g_dcd_agent.update_flag & MMI_DCD_STORY_LIST_UPDATE_MASK)
        {            
            gui_buffer = NULL;
            g_dcd_agent.update_flag = g_dcd_agent.update_flag & (~MMI_DCD_STORY_LIST_UPDATE_MASK);

            g_dcd_agent.channel_handle = emDCDAgent_GetChannelHandle(g_dcd_agent.agent_handle, g_dcd_agent.channel_id);
            if (g_dcd_agent.channel_handle == NULL)
            {
                mmi_frm_scrn_close_active_id();
                return;
            }

            g_story_list_context.total_number = emDCDAgent_GetChannelEntryCount(g_dcd_agent.channel_handle);
            if (g_story_list_context.total_number > MMI_DCD_MAX_STORY_COUNT)
            {
                g_story_list_context.total_number = MMI_DCD_MAX_STORY_COUNT;
            }
            else if (g_story_list_context.total_number == 0)
            {
    		    mmi_frm_scrn_close_active_id();
                return;
            }
        }
    }

    mmi_dcd_set_manual_updte_scr_id(SCR_ID_DCD_STORY_LIST);
    mmi_dcd_get_story_title_list(g_dcd_agent.channel_handle);
    mmi_dcd_get_story_read_state_list();
    
    title = mmi_dcd_get_story_list_scr_title();
    if (title == NULL)
    {
        title = GetString(STR_ID_DCD_STORY_LIST);
    }
    
    RegisterHighlightHandler(mmi_dcd_story_list_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory182Screen(
        (UI_string_type) title,
        (PU8) GetImage(IMG_ID_DCD_SUB_ICON),
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(STR_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        g_story_list_context.total_number,
        (U8 **) g_story_list_context.title_list_pp,
        mmi_dcd_story_list_get_icon,
        read_state_list,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_story_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_enter_story_viewer, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_dcd_get_story_list_scr_title
* DESCRIPTION
*  get dcd story list screen title
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static S8* mmi_dcd_get_story_list_scr_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *title;
    MMI_BOOL is_truncated;
    S32 buflen,char_num;
    S8 *buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buflen = MMI_DCD_MAX_CHANNEL_TITLE_LEN;
    story_list_scr_title_p = (S8 *) applib_mem_screen_alloc(buflen);
    
    title = emDCDAgent_GetChannelTitle(g_dcd_agent.channel_handle);
    char_num = mmi_chset_utf8_strlen((kal_uint8*)title);
    is_truncated = MMI_FALSE;
    if ( char_num >= buflen / 2)
    {
        is_truncated = MMI_TRUE;
        buflen -= 4;
    }
    /* include null terminal */
    buf = story_list_scr_title_p;
    mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buf, buflen, (kal_uint8 *)title );
    if (is_truncated)
    {
        app_ucs2_strcat((kal_int8 *)buf, (kal_int8 *)L"..");
    }

    return story_list_scr_title_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_story_list_screen
 * DESCRIPTION
 *  exit story list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_story_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_story_list_context.title_list_pp != NULL)
    {
        for (index = 0; index < g_story_list_context.total_number; index++)
        {
            if (g_story_list_context.title_list_pp[index] != NULL)
                applib_mem_screen_free(g_story_list_context.title_list_pp[index]);
        }
        applib_mem_screen_free(g_story_list_context.title_list_pp);
        g_story_list_context.title_list_pp = NULL;
    }

    if (story_list_scr_title_p !=NULL)
    {
        applib_mem_screen_free(story_list_scr_title_p);
        story_list_scr_title_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_story_title_list
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  hChannel        [IN]        
 *  agent(?)        [IN]        dcd channel handle(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_get_story_title_list(HDCD_Channel hChannel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *title;
    HDCD_Entry hEntry;
    S32 len, char_num, index;
    S8 *end_pos;
    MMI_BOOL is_truncated = MMI_FALSE;
    S32 buflen;
    S8 *buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_story_list_context.title_list_pp = (S8 **) applib_mem_screen_alloc(sizeof(S8*) * g_story_list_context.total_number);

    for (index = 0; index < g_story_list_context.total_number; index++)
    {
        hEntry = emDCDAgent_GetChannelEntryAt(hChannel, index);
        title = emDCDAgent_GetEntryTitle(hEntry);
        buflen = MMI_DCD_MAX_STORY_TITLE_LEN;
        buf = g_story_list_context.title_list_pp[index] = (S8*) applib_mem_screen_alloc(buflen);
        
        is_truncated = MMI_FALSE;
        if(title != NULL)
        {
            char_num = mmi_chset_utf8_strlen((kal_uint8*) title);
            if (char_num > buflen / 2)
            {
                is_truncated = MMI_TRUE;
                buflen -= 4;
            }

            len = EncodingDecoding(UTF8_TO_UCS2, buf, title, buflen, (kal_uint32*) & end_pos);
            if (is_truncated)
            {
                app_ucs2_strcat((kal_int8*) buf, (kal_int8*) L"..");
            }
        }
        else
        {
            buf[0] = 0;
            buf[1] = 0;
            app_ucs2_strcat((kal_int8*) buf, (kal_int8*) L" ");
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_list_get_icon
 * DESCRIPTION
 *  get dcd story icon
 * PARAMETERS
 *  item_index      [IN]        [in]    item index
 *  path            [?]         [?]         [out]   icon path
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
static MMI_BOOL mmi_dcd_story_list_get_icon(S32 item_index, S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 buflen = SRV_FMGR_PATH_MAX_LEN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_dcd_story_get_icon_path(g_dcd_agent.channel_handle, item_index, path, buflen);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_get_icon_path
 * DESCRIPTION
 *  get dcd story icon
 * PARAMETERS
 *  hChannel        [IN]        
 *  index           [IN]        Channel index
 *  buf             [IN]        Channel title buffer
 *  buflen          [IN]        Buffer len
 *  agent(?)        [IN]        dcd agent handle(?)
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_story_get_icon_path(HDCD_Channel hChannel, S32 index, S8 *buf, S32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_image_exist = MMI_FALSE;
    HDCD_Entry hEntry;
    S32 i, nContentCnt, len;
    HDCD_Content pContent;
    const S8 *content_type;
    S8 *path_buf = NULL;
    EDCD_AGENT_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > g_story_list_context.total_number)
    {
        return MMI_FALSE;
    }
    
    hEntry = emDCDAgent_GetChannelEntryAt(hChannel, index);
    nContentCnt = emDCDAgent_GetEntryContentCount(hEntry);
    path_buf = OslMalloc(SRV_FMGR_PATH_MAX_LEN);
    for (i = 0; i < nContentCnt; i++)
    {
        pContent = emDCDAgent_GetEntryContentAt(hEntry, i);
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
        //emDCDAgent_GetDefaultImageFullPath(path_buf);
        mmi_dcd_get_story_default_image(path_buf);
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
 *  mmi_dcd_get_story_default_image
 * DESCRIPTION
 *  mmi_dcd_get_story_default_image
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_get_story_default_image(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL        is_image_exist = MMI_FALSE;
    HDCD_Channel    hChannel;
    EDCD_AGENT_RESULT result;
    S32             i, nContentCnt;
    HDCD_Content    pContent;
    const S8 *      content_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hChannel = emDCDAgent_GetChannelHandle(g_dcd_agent.agent_handle, g_dcd_agent.channel_id);
    nContentCnt = emDCDAgent_GetChannelContentCount(hChannel);

    for( i = 0; i < nContentCnt; i++)
    {
        pContent = emDCDAgent_GetChannelContentAt(hChannel, i);
        content_type = emDCDAgent_GetContentType(pContent);
        if (mmi_dcd_strnicmp(content_type, "image/", 6) == 0)
        {
            result = emDCDAgent_GetContentFullPath(pContent, path);
            if (result == eDCD_SUCCESS)
            {
                is_image_exist = MMI_TRUE;
                break; 
            }
        }
    }
    
    if (!is_image_exist)
    {
        emDCDAgent_GetDefaultImageFullPath(path);
	}   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_list_highlight_hdlr
 * DESCRIPTION
 *  story list highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_story_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_agent.entry_index = index;
    g_dcd_agent.entry_handle = emDCDAgent_GetChannelEntryAt(g_dcd_agent.channel_handle, g_dcd_agent.entry_index);
    strcpy(g_dcd_agent.entry_id, emDCDAgent_GetEntryID(g_dcd_agent.entry_handle));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_enter_story_viewer
 * DESCRIPTION
 *  story list highlight handler
 * PARAMETERS
 *  void
 *  index(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_enter_story_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_agent.channel_handle = emDCDAgent_GetChannelHandle(g_dcd_agent.agent_handle, g_dcd_agent.channel_id);
    if (g_dcd_agent.channel_handle == NULL)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);   
        return;
    }

    g_dcd_agent.entry_handle = emDCDAgent_GetChannelEntryHandle(g_dcd_agent.channel_handle, g_dcd_agent.entry_id); 
    if (g_dcd_agent.entry_handle == NULL)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);    
        return;
    } 
    
    mmi_dcd_pre_entry_story_viewer(eDCD_VIEW_STORY_CURRENT_CHANNEL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_saved_story_list
 * DESCRIPTION
 *  entry story list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_saved_story_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_story_list_context.saved_story_number = emDCDAgent_GetPermanenceEntryCount(g_dcd_agent.agent_handle);
    if (g_story_list_context.saved_story_number == 0)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        return;
    }
    else if (g_story_list_context.saved_story_number > MMI_DCD_MAX_SAVED_STORY_COUNT)
    {
        g_story_list_context.saved_story_number = MMI_DCD_MAX_SAVED_STORY_COUNT;
    }       
    
    mmi_dcd_entry_saved_story_list();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_saved_story_list
 * DESCRIPTION
 *  entry story list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_saved_story_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *gui_buffer = NULL; 
   	U16 pre_story_total;
    U8  read_state_list[MMI_DCD_MAX_SAVED_STORY_COUNT] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    pre_story_total =  g_story_list_context.saved_story_number;
    g_story_list_context.saved_story_number = emDCDAgent_GetPermanenceEntryCount(g_dcd_agent.agent_handle); 
    if (g_story_list_context.saved_story_number == 0)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        return;
    }
    else if (g_story_list_context.saved_story_number > MMI_DCD_MAX_SAVED_STORY_COUNT)
    {
        g_story_list_context.saved_story_number = MMI_DCD_MAX_SAVED_STORY_COUNT;
    }

    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_SAVED_STORY_LIST, mmi_dcd_exit_saved_story_list_screen, mmi_dcd_entry_saved_story_list, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if((g_story_list_context.saved_story_number < pre_story_total) && (gui_buffer != NULL))
    {
		gui_buffer = NULL;
    }

    RegisterHighlightHandler(mmi_dcd_saved_story_list_highlight_hdlr);
    mmi_dcd_get_saved_story_title_list(g_dcd_agent.agent_handle);    

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory182Screen(
        (UI_string_type) GetString(STR_ID_DCD_SAVED_STORY),
        (PU8) GetImage(IMG_ID_DCD_SUB_ICON),
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        g_story_list_context.saved_story_number,
        (U8 **) g_story_list_context.title_list_pp,
        mmi_dcd_saved_story_list_get_icon,
        read_state_list,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_enter_saved_story_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_enter_saved_story_viewer, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_saved_story_title_list
 * DESCRIPTION
 *  get dcd channel title
 * PARAMETERS
 *  agent       [IN]        Dcd channel handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_get_saved_story_title_list(HDCD_Agent agent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *title;
    HDCD_Entry hEntry;
    S32 len, char_num, index;
    S8 *end_pos;
    MMI_BOOL is_truncated = MMI_FALSE;
    S32 buflen = 0;
    S8 *buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_story_list_context.title_list_pp = (S8 **) applib_mem_screen_alloc(sizeof(S8*) * g_story_list_context.saved_story_number);

    for (index = 0; index < g_story_list_context.saved_story_number; index++)
    {
        hEntry = emDCDAgent_GetPermanenceEntryAt(agent, index);
        title = emDCDAgent_GetEntryTitle(hEntry);
        buflen = MMI_DCD_MAX_STORY_TITLE_LEN;
        buf = g_story_list_context.title_list_pp[index] = (S8*) applib_mem_screen_alloc(buflen);

        is_truncated = MMI_FALSE;
        if(title != NULL)
        {
            char_num = mmi_chset_utf8_strlen((kal_uint8*) title);
            if (char_num > buflen / 2)
            {
                is_truncated = MMI_TRUE;
                buflen -= 4;
            }

            len = EncodingDecoding(UTF8_TO_UCS2, buf, title, buflen, (kal_uint32*) & end_pos);
            if (is_truncated)
            {
                app_ucs2_strcat((kal_int8*) buf, (kal_int8*) L"..");
            }
        }
        else
        {
            buf[0] = 0;
            buf[1] = 0;
            app_ucs2_strcat((kal_int8*) buf, (kal_int8*) L" ");
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_list_get_icon
 * DESCRIPTION
 *  get dcd story icon
 * PARAMETERS
 *  item_index      [IN]        [in]    item index
 *  path            [?]         [?]         [out]   icon path
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
static MMI_BOOL mmi_dcd_saved_story_list_get_icon(S32 item_index, S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 buflen = SRV_FMGR_PATH_MAX_LEN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_dcd_saved_story_get_icon_path(item_index, path, buflen);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_get_icon_path
 * DESCRIPTION
 *  get dcd story icon
 * PARAMETERS
 *  agent       [IN]        Dcd agent handle
 *  index       [IN]        Channel index
 *  buf         [IN]        Channel title buffer
 *  buflen      [IN]        Buffer len
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_saved_story_get_icon_path(S32 index, S8 *buf, S32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_image_exist = MMI_FALSE;
    HDCD_Entry hEntry;
    S32 i, nContentCnt, len;
    HDCD_Content pContent;
    const S8 *content_type;
    S8 *path_buf = NULL;
    EDCD_AGENT_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hEntry = emDCDAgent_GetPermanenceEntryAt(g_dcd_agent.agent_handle, index);
    nContentCnt = emDCDAgent_GetEntryContentCount(hEntry);
    path_buf = OslMalloc(SRV_FMGR_PATH_MAX_LEN);
    
    for (i = 0; i < nContentCnt; i++)
    {
        pContent = emDCDAgent_GetEntryContentAt(hEntry, i);
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
		//emDCDAgent_GetDefaultImageFullPath(path_buf);
        mmi_dcd_get_saved_story_default_image(path_buf, hEntry);
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
*  mmi_dcd_get_saved_story_default_image
* DESCRIPTION
*  mmi_dcd_get_saved_story_default_image
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_dcd_get_saved_story_default_image(S8 *path, HDCD_Entry hEntry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL        is_image_exist = MMI_FALSE;
    HDCD_Channel    hChannel;
    EDCD_AGENT_RESULT result;
    S32             i, nContentCnt;
    HDCD_Content    pContent;
    const S8 *      content_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hChannel = emDCDAgent_GetEntryChannelAt(g_dcd_agent.agent_handle, hEntry);
    nContentCnt = emDCDAgent_GetChannelContentCount(hChannel);

    for( i = 0; i < nContentCnt; i++)
    {
        pContent = emDCDAgent_GetChannelContentAt(hChannel, i);
        content_type = emDCDAgent_GetContentType(pContent);
        if (mmi_dcd_strnicmp(content_type, "image/", 6) == 0)
        {
            result = emDCDAgent_GetContentFullPath(pContent, path);
            if (result == eDCD_SUCCESS)
            {
                is_image_exist = MMI_TRUE;
                break; 
            }
        }
    }
    
    if (!is_image_exist)
    {
        emDCDAgent_GetDefaultImageFullPath(path);
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_list_highlight_hdlr
 * DESCRIPTION
 *  story list highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_saved_story_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_story_list_context.saved_story_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_enter_saved_story_viewer
 * DESCRIPTION
 *  story list highlight handler
 * PARAMETERS
 *  void
 *  index(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_enter_saved_story_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_agent.entry_handle = emDCDAgent_GetPermanenceEntryAt(g_dcd_agent.agent_handle, g_story_list_context.saved_story_index);
    strcpy(g_dcd_agent.entry_id, emDCDAgent_GetEntryID(g_dcd_agent.entry_handle));
    mmi_dcd_pre_entry_story_viewer(eDCD_VIEW_SAVEDSTORY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_enter_saved_story_list_option
 * DESCRIPTION
 *  saved storylist option menu
 * PARAMETERS
 *  void
 *  index(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_enter_saved_story_list_option(void)
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
                        MENU_ID_DCD_SAVED_STORY_LIST_OPTION,
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
 *  mmi_dcd_saved_story_delete_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_saved_story_delete_confirm_callback(mmi_event_struct *evt)
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
                mmi_dcd_saved_story_list_delete_done();
                break;

            case MMI_ALERT_CNFM_NO:
                //mmi_dcd_saved_story_list_delete_abort();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_list_delete_confirm
 * DESCRIPTION
 *  pop up delete story confirm window
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_saved_story_list_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8)get_string(STR_GLOBAL_DELETE));
    mmi_ucs2cat((PS8) str, (PS8)get_string(STR_ID_DCD_QUESTION_MARK));

    do {
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_saved_story_delete_confirm_callback;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    mmi_confirm_display((WCHAR *)str, MMI_EVENT_QUERY, &arg);
    } while(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_delete_all_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_saved_story_delete_all_confirm_callback(mmi_event_struct *evt)
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
                mmi_dcd_saved_story_list_delete_all_done();
                break;

            case MMI_ALERT_CNFM_NO:
                //mmi_dcd_saved_story_list_delete_abort();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_list_delete_all_confirm
 * DESCRIPTION
 *  pop up delete story confirm window
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_saved_story_list_delete_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S8 str[64];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8)get_string(STR_GLOBAL_DELETE_ALL));
    mmi_ucs2cat((PS8) str, (PS8)L"?");

    do {
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_saved_story_delete_all_confirm_callback;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    mmi_confirm_display((WCHAR *)str, MMI_EVENT_QUERY, &arg);
    } while(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_list_delete_done
 * DESCRIPTION
 *  delete current saved story
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_saved_story_list_delete_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Entry entry_handle;
    EDCD_AGENT_RESULT result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_handle = emDCDAgent_GetPermanenceEntryAt(g_dcd_agent.agent_handle, g_story_list_context.saved_story_index);
    result = emDCDAgent_DeletePermanenceEntry(g_dcd_agent.agent_handle, entry_handle);

    do {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_dcd_saved_story_list_delete_callback);
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, &arg);
	} while(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_list_delete_all_done
 * DESCRIPTION
 *  delete all saved stories
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_saved_story_list_delete_all_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = emDCDAgent_DeleteAllPermanenceEntry(g_dcd_agent.agent_handle);
    do {
	mmi_popup_property_struct arg;
	mmi_popup_property_init(&arg);
	arg.callback = mmi_alert_normal_exit_helper;
	arg.user_tag = (void *)(mmi_dcd_saved_story_list_delete_callback);
	mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_DELETED)), MMI_EVENT_SUCCESS, &arg);
	} while(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_saved_story_list_delete_callback
 * DESCRIPTION
 *  delete saved story popup callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_saved_story_list_delete_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total = emDCDAgent_GetPermanenceEntryCount(g_dcd_agent.agent_handle);
    if(total == 0)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, NULL);
        mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_SAVED_STORY_LIST);
    }
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_story_read_state_list
 * DESCRIPTION
 *  get dcd story state list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_get_story_read_state_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BRBOOL read_state;
    HDCD_Entry entry_handle;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < g_story_list_context.total_number; index++)
    {
        entry_handle = emDCDAgent_GetChannelEntryAt(g_dcd_agent.channel_handle, index);
        emDCDAgent_IsReadedEntry(entry_handle, &read_state);
        read_state_list[index] = read_state;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_list_option
 * DESCRIPTION
 *  entry story list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_story_list_option(void)
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
                        MENU_ID_DCD_STORY_LIST_OPTION,
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
 *  mmi_dcd_entry_story_list_from_viewer
 * DESCRIPTION
 *  entry story list from story viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_entry_story_list_from_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_agent.channel_handle = emDCDAgent_GetChannelHandle(g_dcd_agent.agent_handle, g_dcd_agent.channel_id);

    g_story_list_context.total_number = emDCDAgent_GetChannelEntryCount(g_dcd_agent.channel_handle);    
    if (g_story_list_context.total_number > MMI_DCD_MAX_STORY_COUNT)
    {
        g_story_list_context.total_number = MMI_DCD_MAX_STORY_COUNT;
    }

    mmi_dcd_entry_story_list_from_viewer_ext();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_list_from_viewer_ext
 * DESCRIPTION
 *  entry story list from story viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_story_list_from_viewer_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    S8 *title;
    S32 highlighted_item = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_STORY_LIST, mmi_dcd_exit_story_list_screen, mmi_dcd_entry_story_list_from_viewer_ext, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_STORY_VIEWER);

    if (gui_buffer == NULL)
    {
        g_dcd_agent.update_flag = g_dcd_agent.update_flag & (~MMI_DCD_STORY_LIST_UPDATE_MASK);
        highlighted_item = mmi_dcd_get_story_list_index(g_dcd_agent.channel_handle, g_dcd_agent.entry_id);
    }
    else
    {
        if (g_dcd_agent.update_flag & MMI_DCD_STORY_LIST_UPDATE_MASK)
        {
            gui_buffer = NULL;
            highlighted_item = 0;
            g_dcd_agent.update_flag = g_dcd_agent.update_flag & (~MMI_DCD_STORY_LIST_UPDATE_MASK);

            g_dcd_agent.channel_handle = emDCDAgent_GetChannelHandle(g_dcd_agent.agent_handle, g_dcd_agent.channel_id);
            if (g_dcd_agent.channel_handle == NULL)
            {
                mmi_dcd_entry_channel_list_screen();
                mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_STORY_LIST);
                return;
            }
            
            g_story_list_context.total_number = emDCDAgent_GetChannelEntryCount(g_dcd_agent.channel_handle);
            if (g_story_list_context.total_number > MMI_DCD_MAX_STORY_COUNT)
            {
                g_story_list_context.total_number = MMI_DCD_MAX_STORY_COUNT;
            }
            else if (g_story_list_context.total_number == 0)
            {
    		    mmi_dcd_entry_channel_list_screen();
                mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_STORY_LIST);
                return;
            }
        }
    }

    mmi_dcd_set_manual_updte_scr_id(SCR_ID_DCD_STORY_LIST);
    mmi_dcd_get_story_title_list(g_dcd_agent.channel_handle);
    mmi_dcd_get_story_read_state_list();
    
    title = mmi_dcd_get_story_list_scr_title();
    if (title == NULL)
    {
        title = GetString(STR_ID_DCD_STORY_LIST);
    }
    
    RegisterHighlightHandler(mmi_dcd_story_list_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory182Screen(
        (UI_string_type) title,
        (PU8) GetImage(IMG_ID_DCD_SUB_ICON),
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(STR_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        g_story_list_context.total_number,
        (U8 **) g_story_list_context.title_list_pp,
        mmi_dcd_story_list_get_icon,
        read_state_list,
        highlighted_item,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_dcd_entry_story_list_option, KEY_EVENT_UP); 
    SetRightSoftkeyFunction(mmi_dcd_entry_chan_from_story_list, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_enter_story_viewer, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_story_list_index
 * DESCRIPTION
 *  mmi_dcd_get_story_list_index
 * PARAMETERS
 *  hChannel        [IN]        
 *  agent(?)        [IN]        dcd channel handle(?)
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_dcd_get_story_list_index(HDCD_Channel hChannel, BRSTR hEntryID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Entry hEntry;
    S32        index;
    BRCHAR     hEntry_id[MMI_DCD_MAX_CTXT_ID_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < g_story_list_context.total_number; index++)
    {
        hEntry = emDCDAgent_GetChannelEntryAt(hChannel, index);
        strcpy(hEntry_id, emDCDAgent_GetEntryID(hEntry));
        if (strcmp(hEntry_id,hEntryID) == 0) 
        {
            return index;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_saved_story_list_screen
 * DESCRIPTION
 *  exit story list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_saved_story_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_story_list_context.title_list_pp != NULL)
    {
        for (index = 0; index < g_story_list_context.saved_story_number; index++)
        {
            if (g_story_list_context.title_list_pp[index] != NULL)
                applib_mem_screen_free(g_story_list_context.title_list_pp[index]);
        }
        applib_mem_screen_free(g_story_list_context.title_list_pp);
        g_story_list_context.title_list_pp = NULL;
    }

    if (story_list_scr_title_p !=NULL)
    {
        applib_mem_screen_free(story_list_scr_title_p);
        story_list_scr_title_p = NULL;
    }
}

#endif /* __MMI_OP01_DCD__ */
