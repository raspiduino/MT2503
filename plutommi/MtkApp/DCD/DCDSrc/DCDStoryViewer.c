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
*  DCDStoryViewer.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  DCD Story viewer
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*==============================================================================*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "app_str.h"
#include "Conversions.h"
#include "SmsAppGprot.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h" 
#endif

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#include "DCDGprot.h"
#include "DCDProt.h"
#include "DCDAgentInterface.h"
#include "ui_dcd_porting.h"
#include "MenuCUIGprot.h"
#include "mmi_rp_app_dcd_def.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "GlobalResDef.h"
#include "sdktypedef.h"
#include "dcdagentdefine.h"
#include "mmi_frm_scenario_gprot.h"
#include "plx_dcd_wrapper.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "CustDataRes.h"
#include "wgui_categories_op.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "AlertScreen.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "browser_api.h"
#include "CommonScreensResDef.h"
#include "smsal_l4c_enum.h"
#include "mms_api.h"
#include "stdio.h"
#include "FileMgrType.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "FileMgrCuiGProt.h"
#include "wgui_categories_list.h"
#include "mmi_res_range_def.h"
#include "FileMgrGProt.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_DCD_OBJECT_COUNT        (10)
#define MAX_DCD_OBJECT_ITEM_LEN     (20 + 1)
#define MAX_DCD_STORY_TITLE_LEN     (64 + 1)
#define MAX_DCD_STORY_SUMMARY_LEN   (512 + 1)
#define DCD_OBJECT_TYPE_IMAGE       "image/"

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    MMI_BOOL        normal_entry;
    MMI_BOOL        normal_exit;
    MMI_BOOL        is_back_from_viewer;
    S32             curr_object;
    S32             object_count;
    S32             objects_index[MAX_DCD_OBJECT_COUNT];
    U16             file_name[SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN + 1];
    S8              src_file_path[(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) *ENCODING_LENGTH];
    S8              drive_index;
} dcd_viewer_context_struct;

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static dcd_viewer_context_struct g_dcd_viewer;
static MMI_ID filename_editor_cui_id;

static void mmi_dcd_entry_story_viewer(void);
static void mmi_dcd_exit_story_viewer(void);
static void mmi_dcd_story_viewer_rsk_handler(void);
static void mmi_dcd_story_viewer_end_key_handler(void);
static void mmi_dcd_entry_viewer_option(void);
static void mmi_dcd_save_object_done(void);
static void mmi_dcd_entry_file_name_editor(void);
static void mmi_dcd_save_object(void);
static void mmi_dcd_save_object_ext(void);
static void mmi_dcd_object_list_get_item_index(S32 index);
static void mmi_dcd_entry_image_list(void);
static void mmi_dcd_get_images_folder_path(S8 *path);
static void mmi_dcd_entry_select_storage(void);
static S32  mmi_dcd_get_image_count(void);
static pBOOL mmi_dcd_get_object_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_viewer_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_dcd_story_viewer_leave_proc (mmi_event_struct *evt)
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
            BRINT  view_mode;
            view_mode = emDCDAgent_GetViewMode(g_dcd_agent.agent_handle);
            if (view_mode == eDCD_VIEW_STORY_FULL_CHANNEL ||
                view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL ||
                view_mode == eDCD_VIEW_SAVEDSTORY)
            {
                if (mmi_frm_scrn_get_active_id() == SCR_ID_DCD_STORY_VIEWER)
                {
                    ui_dcd_set_screen_exit_normal(MMI_TRUE);
                }
                else
                {
                    mmi_dcd_show_end();
                }
            }
            if (g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL || 
                g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL )
            {
                mmi_dcd_line_given();
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
 *  mmi_dcd_pre_entry_story_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_story_viewer(S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_viewer.normal_entry = MMI_TRUE;
    g_dcd_viewer.normal_exit = MMI_FALSE;
    
    g_dcd_agent.view_mode = mode;
    if (g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL ||
        g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL)
    {
        mmi_dcd_line_taken();
    }

    if (g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL)
    {
        mmi_dcd_create_root_gid();
    }
    mmi_dcd_entry_story_viewer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_story_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_story_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    BRCHAR saved_story_chan_id[5] = {'\0'};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_STORY_VIEWER, mmi_dcd_exit_story_viewer, mmi_dcd_entry_story_viewer, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    mmi_frm_scrn_set_leave_proc(g_dcd_grp_id, SCR_ID_DCD_STORY_VIEWER, mmi_dcd_story_viewer_leave_proc);
    
    if (g_dcd_viewer.normal_entry)
    {
        if (g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL ||
            g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL)
        {
            mmi_dcd_set_view_mode(g_dcd_agent.agent_handle, g_dcd_agent.view_mode);
            emDCDAgent_SetStoryID(g_dcd_agent.agent_handle, g_dcd_agent.channel_id, g_dcd_agent.entry_id);
        }
        else if (g_dcd_agent.view_mode == eDCD_VIEW_SAVEDSTORY)
        {        
            mmi_dcd_set_view_mode(g_dcd_agent.agent_handle, eDCD_VIEW_SAVEDSTORY);
            emDCDAgent_SetStoryID(g_dcd_agent.agent_handle, saved_story_chan_id, g_dcd_agent.entry_id);
        }
    }
    
    if (g_dcd_viewer.normal_entry)
    {
        g_dcd_viewer.normal_entry = MMI_FALSE;
        ui_dcd_set_screen_entry_normal(MMI_TRUE);
    }
    else
    {
        ui_dcd_set_screen_entry_normal(MMI_FALSE);
    }

    if (!(mmi_dcd_is_line_taken()))
    {
        if (g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL ||
            g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL)
        {
            mmi_dcd_line_taken();
        }
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);

#if defined(__MMI_TOUCH_SCREEN__)
    ShowCategory432Screen((UI_string_type) GetString(STR_ID_DCD_STORY_VIEWER),
        (PU8) GetImage(IMG_ID_DCD_SUB_ICON),
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK), (PU8) GetImage(IMG_GLOBAL_BACK),
        ui_dcd_pen_handler,
        (void*)g_dcd_agent.agent_handle, gui_buffer);
#else
    ShowCategory432Screen((UI_string_type) GetString(STR_ID_DCD_STORY_VIEWER),
        (PU8) GetImage(IMG_ID_DCD_SUB_ICON),
        (UI_string_type) GetString(STR_GLOBAL_OPTIONS),
        (PU8) GetImage(IMG_GLOBAL_OPTIONS),
        (UI_string_type) GetString(STR_GLOBAL_BACK), (PU8) GetImage(IMG_GLOBAL_BACK),
        NULL,
        (void*)g_dcd_agent.agent_handle, gui_buffer);
#endif

    SetLeftSoftkeyFunction(mmi_dcd_entry_viewer_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_dcd_story_viewer_rsk_handler, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_entry_viewer_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_dcd_story_viewer_end_key_handler, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dcd_idle_prev_channel, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dcd_idle_next_channel, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dcd_idle_prev_entry, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dcd_idle_next_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dcd_idle_prev_channel, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_dcd_idle_next_channel, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_exit_story_viewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_exit_story_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd_viewer.normal_exit)
    {
        ui_dcd_set_screen_exit_normal(MMI_TRUE);
    }
    else
    {
        ui_dcd_set_screen_exit_normal(MMI_FALSE);
    }

  
    /* Because the story is maybe shifted in the story viewer */
    if((g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL) || 
       (g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL))
    {
        emDCDAgent_GetStoryID(g_dcd_agent.agent_handle, g_dcd_agent.channel_id, g_dcd_agent.entry_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_viewer_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_story_viewer_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_viewer.normal_exit = MMI_TRUE;

    if (g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL)
    {
        mmi_dcd_set_back_state(MMI_TRUE);
        g_dcd_agent.update_flag = 0x00;
        emDCDAgent_GetStoryID(g_dcd_agent.agent_handle, g_dcd_agent.channel_id, g_dcd_agent.entry_id);
        mmi_dcd_entry_story_list_from_viewer();
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_viewer_end_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_story_viewer_end_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_viewer.normal_exit = MMI_TRUE;
    
    if ((g_dcd_grp_id != 0) && mmi_frm_group_is_present(g_dcd_grp_id))
    {
        mmi_frm_group_close(g_dcd_grp_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_viewer_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_viewer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BRSTR title, summary;
    S32 Object_count;
    BRBOOL a_pSyncPkg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = cui_menu_create(
                        g_dcd_grp_id,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        MENU_ID_DCD_VIEWER_OPTION,
                        MMI_TRUE,
                        NULL);

    if ((g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL) || 
        (g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL))
    {
        emDCDAgent_GetStoryID(g_dcd_agent.agent_handle, g_dcd_agent.channel_id, g_dcd_agent.entry_id);
        g_dcd_agent.channel_handle = emDCDAgent_GetChannelHandle(g_dcd_agent.agent_handle, g_dcd_agent.channel_id);
        g_dcd_agent.entry_handle = emDCDAgent_GetChannelEntryHandle(g_dcd_agent.channel_handle, g_dcd_agent.entry_id);
    }

    title = emDCDAgent_GetEntryTitle(g_dcd_agent.entry_handle);
    summary = emDCDAgent_GetEntrySummary(g_dcd_agent.entry_handle);
    Object_count = mmi_dcd_get_image_count();

    /**** judge whether the story is preload or not*****/
    emDCDAgent_IsSyncPkgData(g_dcd_agent.agent_handle, g_dcd_agent.channel_id, g_dcd_agent.entry_id, &a_pSyncPkg);
    if (a_pSyncPkg == BRFALSE && (g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL || 
                                  g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL ))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_GO_TO, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_STORY, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_DELETE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_GO_TO, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_STORY, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE, MMI_FALSE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_DELETE, MMI_FALSE);

        if(emDCDAgent_GetEntryLinkCount(g_dcd_agent.entry_handle) <= 0)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_GO_TO, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_GO_TO, MMI_FALSE);
        }

    #ifdef __USB_IN_NORMAL_MODE__
        if (srv_usb_is_in_mass_storage_mode())
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_TRUE);
        }
        else
        {
        #if (!defined(__MMI_MMS__) && !defined(__MMI_EMAIL__))
            if ((title == BRNULL) && (summary == BRNULL))
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_FALSE);
            }
        #else /* (!defined(__MMI_MMS__) && !defined(__MMI_EMAIL__)) */
            if ((title == BRNULL) && (summary == BRNULL) && (Object_count <= 0))
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_FALSE);
            }
        #endif /* (!defined(__MMI_MMS__) && !defined(__MMI_EMAIL__)) */
        }
    #else /* __USB_IN_NORMAL_MODE__ */
        #if (!defined(__MMI_MMS__) && !defined(__MMI_EMAIL__))
            if ((title == BRNULL) && (summary == BRNULL))
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_FALSE);
            }
        #else /* (!defined(__MMI_MMS__) && !defined(__MMI_EMAIL__)) */
            if ((title == BRNULL) && (summary == BRNULL) && (Object_count <= 0))
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_FORWARD, MMI_FALSE);
            }
        #endif /* (!defined(__MMI_MMS__) && !defined(__MMI_EMAIL__)) */
    #endif /* __USB_IN_NORMAL_MODE__ */

        if (g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL || 
            g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_DELETE, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_DELETE, MMI_FALSE);
        }

        if(g_dcd_agent.view_mode == eDCD_VIEW_SAVEDSTORY)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_STORY, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_STORY, MMI_FALSE);
        }

    #ifdef __USB_IN_NORMAL_MODE__
        if (srv_usb_is_in_mass_storage_mode())
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE, MMI_TRUE);
        }
        else
        {
            if(Object_count <= 0)
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE, MMI_FALSE);
            }
        }
    #else /* __USB_IN_NORMAL_MODE__ */
        if(Object_count <= 0)
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_gid, MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE, MMI_FALSE);
        }
    #endif /* __USB_IN_NORMAL_MODE__ */
    }

    if (menu_gid != GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(menu_gid, get_image(IMG_ID_DCD_SUB_ICON));
        cui_menu_run(menu_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_viewer_go_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_viewer_go_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BRINT      url_index;
    U8       * p_url;
    HDCD_Link  link_handle;
    U8       * ucs_url;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url_index = emDCDAgent_GetStoryViewerFocusingURLIndex(g_dcd_agent.agent_handle);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_URL_INDEX, url_index);

    /* Click the URL by pen in story viewer */
    if ((g_dcd_agent.view_mode == eDCD_VIEW_STORY_FULL_CHANNEL) || 
        (g_dcd_agent.view_mode == eDCD_VIEW_STORY_CURRENT_CHANNEL))
    {
        emDCDAgent_GetStoryID(g_dcd_agent.agent_handle, g_dcd_agent.channel_id, g_dcd_agent.entry_id);
        g_dcd_agent.channel_handle = emDCDAgent_GetChannelHandle(g_dcd_agent.agent_handle, g_dcd_agent.channel_id);
        g_dcd_agent.entry_handle = emDCDAgent_GetChannelEntryHandle(g_dcd_agent.channel_handle, g_dcd_agent.entry_id);
    }

    link_handle = emDCDAgent_GetEntryLinkAt(g_dcd_agent.entry_handle, url_index);
    if (link_handle == NULL)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_INVALID_URL), MMI_EVENT_FAILURE, NULL);
        return;
    }
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_ENTRY_LINK, link_handle);
    p_url = (U8*) emDCDAgent_GetLinkURL(link_handle);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_GET_LINKURL, p_url);
    ucs_url = OslMalloc((strlen((S8*) p_url) + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((S8*) ucs_url, (S8*) p_url);    
    wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8*) ucs_url);
    
    OslMfree(ucs_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_save_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_story_save_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    result = emDCDAgent_SavePermanenceEntry(g_dcd_agent.agent_handle, g_dcd_agent.entry_handle);
    switch (result)
    {
         case eDCD_SUCCESS:
             mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);
            break;
            
         case eDCD_ERR_MAX_PERMANENT_ENTRY_REACHED:
             mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_MEMORY_FULL), MMI_EVENT_FAILURE, NULL);
             break;
             
         case eDCD_ERR_WRITE_FILE:
             mmi_popup_display((WCHAR*)GetString(STR_ID_DCD_QUOTA_EXCEEDED), MMI_EVENT_FAILURE, NULL);
             break;
             
         case eDCD_ERR_PERM_ENTRY_DUPLICATION:
             mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_FILE_ALREADY_EXISTS), MMI_EVENT_FAILURE, NULL);
             break;
             
         default:
            break;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_story_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_save_story_confirm_callback(mmi_event_struct *evt)
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
                mmi_dcd_story_save_done();
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
 *  mmi_dcd_viewer_save_story
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_viewer_save_story(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_dcd_save_story_confirm_callback;
    mmi_confirm_display((WCHAR *)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_delete_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_story_delete_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = emDCDAgent_DeletePermanenceEntry(g_dcd_agent.agent_handle, g_dcd_agent.entry_handle);
    if (eDCD_SUCCESS == result)
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, NULL);
    }
    else
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, NULL);
    }

    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_STORY_VIEWER);
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_story_viewer_delete_story_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_story_viewer_delete_story_callback(mmi_event_struct *evt)
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
                mmi_dcd_story_delete_done();
                break;

            case MMI_ALERT_CNFM_NO:
                //mmi_dcd_story_delete_abort();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_viewer_delete_story
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_viewer_delete_story(void)
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
    arg.callback = (mmi_proc_func)mmi_dcd_story_viewer_delete_story_callback;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    mmi_confirm_display((WCHAR *)str, MMI_EVENT_QUERY, &arg);
    } while(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_forward_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_forward_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BRSTR title, summary;
    mmi_sms_write_msg_para_struct sms_write_struct;
    S8 *temp_buffer, *ucs_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    summary = emDCDAgent_GetEntrySummary(g_dcd_agent.entry_handle);
    title = emDCDAgent_GetEntryTitle(g_dcd_agent.entry_handle);

    temp_buffer = OslMalloc(MAX_DCD_STORY_SUMMARY_LEN * ENCODING_LENGTH);
    ucs_buffer = OslMalloc((MAX_DCD_STORY_TITLE_LEN + MAX_DCD_STORY_SUMMARY_LEN) * ENCODING_LENGTH);
    memset(ucs_buffer, 0, (MAX_DCD_STORY_TITLE_LEN + MAX_DCD_STORY_SUMMARY_LEN) * ENCODING_LENGTH);
    temp_buffer[0] = 0;
    temp_buffer[1] = 0;
    if (title != NULL)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) temp_buffer,
            MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH,
            (kal_uint8*) title);
    }
    else
    {       
        app_ucs2_strcat((kal_int8*) temp_buffer, (kal_int8*) L" ");
    }
    mmi_ucs2cat((S8*) ucs_buffer, (S8*) temp_buffer);
    mmi_asc_to_ucs2((S8*) temp_buffer, (S8*) "--");
    mmi_ucs2cat((S8*) ucs_buffer, (S8*) temp_buffer);
    temp_buffer[0] = 0;
    temp_buffer[1] = 0;
    if (summary !=NULL)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) temp_buffer,
            MAX_DCD_STORY_SUMMARY_LEN * ENCODING_LENGTH,
            (kal_uint8*) summary);
    }
    else
    {
        app_ucs2_strcat((kal_int8*) temp_buffer, (kal_int8*)L" ");
    }
    mmi_ucs2cat((S8*) ucs_buffer, (S8*) temp_buffer);

    sms_write_struct.srcport = 0;
    sms_write_struct.desport = 0;
    sms_write_struct.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    sms_write_struct.stringlength = mmi_ucs2strlen(ucs_buffer);
    sms_write_struct.string = ucs_buffer;
    sms_write_struct.filename = NULL;
    sms_write_struct.dcs = SMSAL_UCS2_DCS;
    sms_write_struct.dcs_class = 0;
    sms_write_struct.ascii_addr = NULL;
    mmi_sms_write_msg_lanch(0, &sms_write_struct);

    OslMfree(temp_buffer);
    OslMfree(ucs_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_image_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_dcd_get_image_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BRSTR object_type;
    HDCD_Content content_handle = NULL;
    EDCD_AGENT_RESULT result;
    U8 utf8_path[SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN];
    S32 total, i;
    S32 image_total = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    total = emDCDAgent_GetEntryContentCount(g_dcd_agent.entry_handle);
    if (total > 0)
    {
        for (i = 0; i < total; i++)
        {
            content_handle = emDCDAgent_GetEntryContentAt(g_dcd_agent.entry_handle, i);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONTENT_HANDLE, content_handle);
            result = emDCDAgent_GetContentFullPath(content_handle, (BRSTR) utf8_path);
            if (result != eDCD_FAIL)
            {
                object_type = emDCDAgent_GetContentType(content_handle);
                if (0 == strncmp((S8*) object_type, DCD_OBJECT_TYPE_IMAGE, strlen(DCD_OBJECT_TYPE_IMAGE)))
                {
                    image_total++;
                }
            }
        }
    }
    return image_total;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_forward_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_forward_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;
    BRSTR title, summary, object_type;
    HDCD_Content content_handle = NULL;
    mms_content_entry_struct mms_data;
    U8 *ucs2_title = NULL;
    U8 *ucs2_summary_p = NULL;
    U8 utf8_path[SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN];
    U8 *ucs2_path_p = NULL;
    S32 total, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    title = emDCDAgent_GetEntryTitle(g_dcd_agent.entry_handle);
    ucs2_title = (U8*) OslMalloc(MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH);
    ucs2_title[0] = 0;
    ucs2_title[1] = 0;
    if (title != NULL)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) ucs2_title,
            (MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH),
            (kal_uint8*) title);
    }    
    else
    {
        app_ucs2_strcat((kal_int8*) ucs2_title, (kal_int8*)L" ");
    }    
    mms_data.subject = (S8*) ucs2_title;

    summary = emDCDAgent_GetEntrySummary(g_dcd_agent.entry_handle);
    ucs2_summary_p = (U8*) OslMalloc(MAX_DCD_STORY_SUMMARY_LEN * ENCODING_LENGTH);
    ucs2_summary_p[0] = 0;
    ucs2_summary_p[1] = 0;
    if (summary != NULL)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) ucs2_summary_p,
            (MAX_DCD_STORY_SUMMARY_LEN * ENCODING_LENGTH),
            (kal_uint8*) summary);
    }  
    else
    {
        app_ucs2_strcat((kal_int8*) ucs2_summary_p, (kal_int8*)L" ");
    } 
    mms_data.text_buffer = (S8*) ucs2_summary_p;

    mms_data.file_path = NULL;
    ucs2_path_p = (U8*) OslMalloc((SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH);
    total = emDCDAgent_GetEntryContentCount(g_dcd_agent.entry_handle);
    if (total > 0)
    {
        for (i = 0; i < total; i++)
        {
            content_handle = emDCDAgent_GetEntryContentAt(g_dcd_agent.entry_handle, i);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONTENT_HANDLE, content_handle);
            object_type = emDCDAgent_GetContentType(content_handle);
            if (0 == strncmp((S8*) object_type, DCD_OBJECT_TYPE_IMAGE, strlen(DCD_OBJECT_TYPE_IMAGE)))
            {
                break;
            }
        }
        
        if (i < total)
        {            
            result = emDCDAgent_GetContentFullPath(content_handle, (BRSTR) utf8_path);
            if (result != eDCD_FAIL)
            {
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) ucs2_path_p,
                    (MAX_DCD_STORY_SUMMARY_LEN * ENCODING_LENGTH),
                    (kal_uint8*) utf8_path);
                mms_data.file_path = (S8*) ucs2_path_p;
            }
        }
        else
        {
            /* use default image */
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_IMAGE_IS);
        }
    }
    else
    {
        /* use default image. */
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_OBJECT_IS);
    }

    mms_data.mode = MMS_NEW_GENERAL;
    mms_data.addr = NULL;
    mms_data.callback = NULL;
    mms_data.callback_param = NULL;
    mms_general_insert_hdlr(&mms_data);

    OslMfree(ucs2_title);
    OslMfree(ucs2_summary_p);
    OslMfree(ucs2_path_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_forward_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_EMAIL__
void mmi_dcd_forward_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;
    BRSTR title, summary, object_type;
    HDCD_Content content_handle = NULL;
    U8 *ucs2_title = NULL;
    U8 *ucs2_summary_p = NULL;
    U8 utf8_path[SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN];
    U8 *ucs2_path_p = NULL;
    S32 total, i;

    U8  flag = 0;
    mmi_email_app_send_param_struct *email_param = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_param = (mmi_email_app_send_param_struct*) OslMalloc(sizeof(mmi_email_app_send_param_struct));
    mmi_email_app_send_init_param_to_null(email_param);
    
    /*Email subject*/
    title = emDCDAgent_GetEntryTitle(g_dcd_agent.entry_handle);
    ucs2_title = (U8*) OslMalloc(MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH);
    ucs2_title[0] = 0;
    ucs2_title[1] = 0;
    if (title != NULL)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) ucs2_title,
            (MAX_DCD_STORY_TITLE_LEN * ENCODING_LENGTH),
            (kal_uint8*) title);
        email_param->subj = (S8*) ucs2_title;
        flag |= EMAIL_SUBJ_FILL_FLAG;
    }
    
    /*Email content*/
    summary = emDCDAgent_GetEntrySummary(g_dcd_agent.entry_handle);
    ucs2_summary_p = (U8*) OslMalloc(MAX_DCD_STORY_SUMMARY_LEN * ENCODING_LENGTH);
    ucs2_summary_p[0] = 0;
    ucs2_summary_p[1] = 0;
    if (summary != NULL)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) ucs2_summary_p,
            (MAX_DCD_STORY_SUMMARY_LEN * ENCODING_LENGTH),
            (kal_uint8*) summary);
        email_param->cont = (S8*) ucs2_summary_p;
        flag |= EMAIL_CONT_FILL_FLAG;
    }  
    
    /*Email attachment file path*/
    ucs2_path_p = (U8*) OslMalloc((SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH);
    total = emDCDAgent_GetEntryContentCount(g_dcd_agent.entry_handle);
    if (total > 0)
    {
        for (i = 0; i < total; i++)
        {
            content_handle = emDCDAgent_GetEntryContentAt(g_dcd_agent.entry_handle, i);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONTENT_HANDLE, content_handle);
            object_type = emDCDAgent_GetContentType(content_handle);
            if (0 == strncmp((S8*) object_type, DCD_OBJECT_TYPE_IMAGE, strlen(DCD_OBJECT_TYPE_IMAGE)))
            {
                break;
            }
        }
        
        if (i < total)
        {            
            result = emDCDAgent_GetContentFullPath(content_handle, (BRSTR) utf8_path);
            if (result != eDCD_FAIL)
            {
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) ucs2_path_p,
                    (MAX_DCD_STORY_SUMMARY_LEN * ENCODING_LENGTH),
                    (kal_uint8*) utf8_path);
                email_param->attch_file_path = (S8*) ucs2_path_p;
                flag |= EMAIL_ATTCH_FILL_FLAG;
            }
        }
    }
    
    mmi_email_app_send(email_param, flag);
    
    OslMfree(ucs2_title);
    OslMfree(ucs2_summary_p);
    OslMfree(ucs2_path_p);
    OslMfree(email_param);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_images_folder_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_get_images_folder_path(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8)g_dcd_viewer.drive_index);
    mmi_asc_to_ucs2((S8*) path, drv);
    mmi_ucs2cat((S8*) path, (const S8*)FMGR_DEFAULT_FOLDER_IMAGES);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 * void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_save_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    U16 path[(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH];
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_get_images_folder_path((S8*)path);
    
    if (FS_GetDevStatus(path[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        mmi_popup_display((WCHAR*)GetString(FMGR_FS_DEVICE_BUSY_TEXT), MMI_EVENT_FAILURE, NULL);
        return;
    }

    file_handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        fs_ret = FS_CreateDir(path);
        if(fs_ret == FS_NO_ERROR)
        {
             mmi_dcd_save_object_ext();
        }
        else
        {
            mmi_popup_display((WCHAR*)GetString(FMGR_FS_ROOT_DIR_FULL_TEXT), MMI_EVENT_FAILURE, NULL);
        }
    }
    else
    {
        FS_Close(file_handle);
        mmi_dcd_save_object_ext();
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_file_copy_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  event     [IN]        Variable stores the result of copy
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_file_copy_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(event->evt_id)
    {
		case EVT_ID_SRV_FMGR_ASYNC_DONE:
		{		
			srv_fmgr_async_done_event_struct *async_evt = (srv_fmgr_async_done_event_struct *)event;
            if (async_evt->result >= 0)
            {
                mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, NULL);       
                cui_filename_editor_close(filename_editor_cui_id);
                mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_IMAGE_LIST);
            }
            else
            {
                mmi_popup_display((WCHAR*)GetString((U16) srv_fmgr_fs_error_get_string(async_evt->result)), srv_fmgr_fs_error_get_popup_type(async_evt->result), NULL);
                if (async_evt->result != FS_PATH_OVER_LEN_ERROR &&
                    async_evt->result != FS_FILE_EXISTS &&
                    async_evt->result != FS_INVALID_FILENAME)
                {
                    cui_filename_editor_close(filename_editor_cui_id);
                    mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_IMAGE_LIST);
                }
            }
			break;
		}

        default:
            break;
    }    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_object_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_save_object_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Content content_handle;
    BRSTR object_type;
    S8 *postfix;
    U16 *dest_file_path;
    U16 *temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_file_path = OslMalloc(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    temp = OslMalloc(SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);

    memset(g_dcd_viewer.src_file_path, 0, (SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH);
    content_handle = emDCDAgent_GetEntryContentAt(g_dcd_agent.entry_handle, g_dcd_viewer.objects_index[g_dcd_viewer.curr_object]);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONTENT_HANDLE, content_handle);

	emDCDAgent_GetContentFullPath(content_handle, (BRSTR) temp);
    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*) g_dcd_viewer.src_file_path,
        (SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH,
        (kal_uint8*) temp);

    mmi_dcd_get_images_folder_path((S8*)temp);
    mmi_wcscpy(dest_file_path, temp);
    mmi_wcscat(dest_file_path, g_dcd_viewer.file_name);
    mmi_asc_to_wcs(temp, ".");
    mmi_wcscat(dest_file_path, temp);
    object_type = emDCDAgent_GetContentType(content_handle);
    postfix = strchr(object_type, '/');
    postfix++;
    mmi_asc_to_wcs(temp, postfix);
    mmi_wcscat(dest_file_path, temp);

    srv_fmgr_async_copy(
        (WCHAR*)g_dcd_viewer.src_file_path,
        (WCHAR*)dest_file_path,
        0,
        mmi_dcd_file_copy_proc,
        NULL);

    OslMfree(dest_file_path);
    OslMfree(temp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_file_name_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_dcd_entry_file_name_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename_editor_cui_id = cui_filename_editor_create(
                                g_dcd_grp_id, 
                                (WCHAR *)g_dcd_viewer.file_name, 
                                ((SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN + 1)*ENCODING_LENGTH),
                                SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN,
                                NULL,
                                NULL);

    if (filename_editor_cui_id != GRP_ID_INVALID)
    {
        cui_filename_editor_set_title(filename_editor_cui_id, STR_GLOBAL_FILENAME, IMG_ID_DCD_SUB_ICON);
        cui_filename_editor_run(filename_editor_cui_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_cui_filename_editor_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_cui_filename_editor_proc(cui_filename_editor_result_event_struct *result_event)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (result_event->result > 0)
    {
        mmi_dcd_save_object_done();
    }
    else
    {
        cui_filename_editor_close(result_event->sender_id);
        mmi_frm_scrn_close(g_dcd_grp_id, SCR_ID_DCD_IMAGE_LIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_save_object_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDCD_Content content_handle;
    BRSTR content_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_dcd_viewer.file_name, 0, sizeof(g_dcd_viewer.file_name));
    content_handle = emDCDAgent_GetEntryContentAt(g_dcd_agent.entry_handle, g_dcd_viewer.objects_index[g_dcd_viewer.curr_object]);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONTENT_HANDLE, content_handle);
    content_id = emDCDAgent_GetContentID(content_handle);
    mmi_asc_to_ucs2((S8*) g_dcd_viewer.file_name, (S8*) content_id);

    mmi_dcd_entry_file_name_editor();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_object_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         [?]         [?]
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pBOOL mmi_dcd_get_object_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[MAX_DCD_OBJECT_ITEM_LEN * ENCODING_LENGTH];
    HDCD_Content content_handle;
    BRSTR content_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (item_index < g_dcd_viewer.object_count)
    {
        memset(temp, 0, (MAX_DCD_OBJECT_ITEM_LEN * ENCODING_LENGTH));
        content_handle = emDCDAgent_GetEntryContentAt(g_dcd_agent.entry_handle, g_dcd_viewer.objects_index[item_index]);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONTENT_HANDLE, content_handle);
        content_id = emDCDAgent_GetContentID(content_handle);
        mmi_asc_to_ucs2((S8*) temp, (S8*) content_id);
        mmi_ucs2cpy((S8*) str_buff, (S8*) temp);
        
        *img_buff_p = get_image((MMI_ID_TYPE) (IMG_GLOBAL_L1 + item_index)); /* gIndexIconsImageList */
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_ITEM_INDEX);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_object_list_get_item_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_object_list_get_item_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_viewer.curr_object = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_pre_entry_object_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_pre_entry_object_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total;
    HDCD_Content content_handle;
    BRSTR object_type;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_viewer.object_count = -1;
    memset(g_dcd_viewer.objects_index, -1, MAX_DCD_OBJECT_COUNT);
    g_dcd_viewer.curr_object = 0;
   
    total = emDCDAgent_GetEntryContentCount(g_dcd_agent.entry_handle);
    if (total > 0)
    {
        g_dcd_viewer.object_count = 0;
        for (i = 0; i < total; i++)
        {
            content_handle = emDCDAgent_GetEntryContentAt(g_dcd_agent.entry_handle, i);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONTENT_HANDLE, content_handle);
            object_type = emDCDAgent_GetContentType(content_handle);
            if (0 == strncmp((S8*) object_type, DCD_OBJECT_TYPE_IMAGE, strlen(DCD_OBJECT_TYPE_IMAGE)))
            {
                g_dcd_viewer.objects_index[g_dcd_viewer.object_count] = i;
                g_dcd_viewer.object_count++;
            }
        }

        mmi_dcd_entry_image_list();
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_OBJECT_IS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_image_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_image_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(g_dcd_grp_id, SCR_ID_DCD_IMAGE_LIST, NULL, mmi_dcd_entry_image_list, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    SetParentHandler(SCR_ID_DCD_IMAGE_LIST);
    RegisterHighlightHandler(mmi_dcd_object_list_get_item_index);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory184Screen(
        STR_GLOBAL_PICTURE,
        IMG_ID_DCD_SUB_ICON,
        STR_GLOBAL_SAVE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_dcd_viewer.object_count,
        mmi_dcd_get_object_item,
        NULL,
        g_dcd_viewer.curr_object,
        gui_buffer);

    g_dcd_viewer.drive_index = 0; /* insure highlight item is the first one in storage select screen */
    
    SetLeftSoftkeyFunction(mmi_dcd_entry_select_storage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_dcd_entry_select_storage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_entry_select_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_entry_select_storage(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_id, string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid = cui_storage_selector_create(
                        g_dcd_grp_id,
                        g_dcd_viewer.drive_index,
                        0);
    
    if (menu_gid != GRP_ID_INVALID)
    {
        mmi_fmgr_get_app_title_info(APP_DCD, &string_id, &icon_id, NULL);
        cui_storage_selector_set_title(menu_gid, string_id, IMG_ID_DCD_SUB_ICON);
        cui_storage_selector_run(menu_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_cui_storage_selector_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_cui_storage_selector_proc(cui_storage_selector_result_event_struct *result_event)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (result_event->result > 0)
    {
        g_dcd_viewer.drive_index = (S8)result_event->result;
        mmi_dcd_save_object();
    }
    cui_storage_selector_close(result_event->sender_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_set_back_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_set_back_state(MMI_BOOL back_state)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_dcd_viewer.is_back_from_viewer = back_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_back_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_get_back_state(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return g_dcd_viewer.is_back_from_viewer;
}

#endif /* __MMI_OP01_DCD__ */
