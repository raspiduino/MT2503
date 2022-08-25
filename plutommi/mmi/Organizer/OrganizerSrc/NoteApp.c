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
 * NoteApp.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements To Note application.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"

#ifdef __MMI_NOTE_APP__

#define __MMI_NOTE_SORT_BY_MODIFY_TIME__

#include "MMIDataType.h"
#include "common_nvram_editor_data_item.h"
#include "wgui_touch_screen.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "custom_mmi_default_value.h"
#include "string.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "Unicodexdcl.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "gui_data_types.h"
#include "wgui_categories_text_viewer.h"
#include "AlertScreen.h"
#include "ImeGprot.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"   
#include "App_datetime.h"
#include "Conversions.h"
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
#include "SyncmlGprot.h"
#include "mmi_rp_srv_syncml_def.h"
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#include "NoteGprot.h"
#include "NoteProt.h"
#include "mmi_rp_app_note_def.h"
#include "menucuigprot.h"
#include "fseditorcuigprot.h"
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
#define MMI_NOTE_SYNC_FILE_SIZE (MMI_MAX_NOTE_LEN * 3)
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */


#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
#define MMI_NOTE_CHECK_SYNCML                       \
	do {	                                        \
        if (mmi_syncml_is_note_sync_now())	        \
		{	                                        \
			mmi_popup_display_simple(               \
    			(WCHAR*)get_string(STR_ID_SYNC_CODE_FORBIDDEN),\
    			MMI_EVENT_FAILURE,                  \
    			GRP_ID_ROOT,                        \
    			NULL);                              \
    		return;	                                \
    	}	                                        \
    }                                               \
	while(0);
#else
#define MMI_NOTE_CHECK_SYNCML	{}
#endif

/***************************************************************************** 
* Static Declaration
*****************************************************************************/
static mmi_note_list_struct g_mmi_note_cntx;			/* context of global note application */

static mmi_note_edit_struct g_mmi_note_edit_cntx;
static mmi_note_mark_list_struct g_mmi_note_mark_cntx;	/* context of note list mark screen */

/* External Functions */
/* note list screen */
static void mmi_note_group_entry_note_main(void);
static mmi_ret mmi_note_group_note_main_proc(mmi_event_struct *param);
static void mmi_note_menu_cui_select_evt_hdlr(mmi_event_struct *param);
static void mmi_note_menu_cui_entry_evt_hdlr(mmi_event_struct *param);
static void mmi_note_menu_cui_close_request_evt_hdlr(mmi_event_struct *param);
static void mmi_note_menu_cui_highlight_evt_hdlr(mmi_event_struct *param);
static void mmi_note_menu_cui_exit_evt_hdlr(mmi_event_struct *param);
static void mmi_note_menu_cui_item_tap_evt_hdlr(mmi_event_struct *param);
static void mmi_note_menu_cui_item_csk_evt_hdlr(mmi_event_struct *param);

static void mmi_note_entry_list_screen(void);
static void mmi_note_list_highlight_hdlr(S32 index);
static void mmi_note_entry_list_option_screen(void);
static void mmi_note_list_option_entry_evt_hdlr(cui_menu_event_struct *evt);

/* view screen */
static void mmi_note_entry_view_screen(void);
static void mmi_note_entry_view_option_screen(void);
static void mmi_note_view_option_entry_evt_hdlr(cui_menu_event_struct* evt);

/* add and edit screen */
static void mmi_note_entry_add_screen(void);
static void mmi_note_entry_edit_screen(void);
static void mmi_note_edit_option_done(cui_fseditor_evt_struct *evt);

/* mark screen and mark option screen functions */
static void mmi_note_entry_mark_several_screen(void);
static void mmi_note_mark_several_highlight_hdlr(S32 index);
static void mmi_note_update_mark_several_option_menu(mmi_id cui_id);
static void mmi_note_entry_mark_several_option_screen(void);
static void mmi_note_mark_several_change_mark_state(void);
static void mmi_note_mark_several_mark_option_item(mmi_menu_id menu_id);
#ifdef __MMI_TOUCH_SCREEN__
static void mmi_note_mark_several_pen_down(void);
#endif

/* delete confirm screen */
static void mmi_note_entry_delete_confirm(mmi_menu_id menu_id);
static void mmi_note_entry_delete_confirm_ok(void);
static void mmi_note_entry_marked_delete_confirm_ok(void);
static mmi_ret mmi_note_delete_confirm_proc(mmi_event_struct *evt);

/* logical functions */
static U16 mmi_note_check_pos_note_list(U32 curr_time, U16 nvram_index);
static U16 mmi_note_get_valid_storage_index(void);

static void mmi_note_sort_list(void);

/* get high light index with NVRAM position */
static U16 mmi_note_get_hilite_index(U16 nvram_index);

/* get NVRAM index with hilite index */
static U16 mmi_note_get_nvram_index(U16 hilite);

/* update note content with hilite index */
static U16 mmi_note_update_content_hilite_cntx(U16 hilite, 
											  nvram_ef_note_app_node_struct *node_cntx, 
											  mmi_note_operation_enum note_op);


/* update note content with each operator */
static U16 mmi_note_update_content_note_record(mmi_note_operation_enum note_opt, 
											   U16 update_node, 
											   nvram_ef_note_app_node_struct *node_cntx);

static U16 mmi_note_get(U16 index, nvram_ef_note_app_node_struct *node_cntx);
static U16 mmi_note_add(U16 index, nvram_ef_note_app_node_struct *node_cntx);
static U16 mmi_note_edit(U16 index, nvram_ef_note_app_node_struct *node_cntx);
static U16 mmi_note_delete(U16 index);


/* load high light note content */
static U16 mmi_note_load_text(U16 hilite);    /* load current item text and return length if success */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
static S32 mmi_note_sync_update_sync_file(U8 action, CHAR* path, U8* note_node);
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_note_entry_list_screen_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif

/**************************************************************************************************
***************************************	ONLY FOR DEBUG ********************************************
**************************************************************************************************/
//#define __MMI_NOTE_DEBUG__

static void mmi_note_print_all(U32 line, U8 nvram_lid);
static void mmi_note_debug_check_queue(U32 line);
static void mmi_note_debug_print_time_info(U32 line, U32 time);

#define MMI_NOTE_PRINT_TIME_INFO(time)	mmi_note_debug_print_time_info(__LINE__, time);
#define MMI_NOTE_CHECK_LIST				mmi_note_debug_check_queue(__LINE__);
#define MMI_NOTE_PRINT_ALL(nvram_lid)	mmi_note_print_all(__LINE__, nvram_lid);

/**************************************************************************************************
***************************************	ONLY FOR DEBUG ********************************************
**************************************************************************************************/

/*****************************************************************************
* FUNCTION
*  mmi_note_highlight_main
* DESCRIPTION
*  This function is high light function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
void mmi_note_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    
    SetLeftSoftkeyFunction(mmi_note_group_entry_note_main, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_note_group_entry_note_main, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_note_app_launch_func
 * DESCRIPTION
 *  Launch note app in app mgr
 * PARAMETERS
 *  param
 *  param_size
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
MMI_ID mmi_note_app_launch_func(void* param, U32 param_size)
{
    MMI_ID gid = GRP_ID_INVALID;
    
    gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_NOTE_MAIN, mmi_note_group_note_main_proc, NULL);
    
    mmi_frm_group_enter(GRP_ID_NOTE_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_note_entry_list_screen();

    return gid;
}

/*****************************************************************************
* FUNCTION
*  mmi_note_launch
* DESCRIPTION
*  for shortcut
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
void mmi_note_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_note_group_entry_note_main();
}


/*****************************************************************************
* FUNCTION
*  mmi_note_group_entry_note_main
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_group_entry_note_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_NOTE_CHECK_SYNCML

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_NOTE_MAIN, mmi_note_group_note_main_proc, NULL);

    mmi_frm_group_enter(GRP_ID_NOTE_MAIN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_note_entry_list_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_note_group_note_main_proc
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static mmi_ret mmi_note_group_note_main_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        /* menu cui event hdlr */
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_note_menu_cui_select_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_note_menu_cui_entry_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_note_menu_cui_close_request_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
            mmi_note_menu_cui_exit_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            mmi_note_menu_cui_highlight_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_TAP:
        {
            mmi_note_menu_cui_item_tap_evt_hdlr(param);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            mmi_note_menu_cui_item_csk_evt_hdlr(param);
            break;
        }
        /* fseditor cui event hdlr */
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            cui_fseditor_evt_struct *evt = (cui_fseditor_evt_struct*) param;
            mmi_note_edit_option_done(evt);
            cui_fseditor_close(evt->sender_id);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_evt_struct *evt = (cui_fseditor_evt_struct*) param;
            cui_fseditor_close(evt->sender_id);
            break;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_menu_cui_select_evt_hdlr
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_menu_cui_select_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* evt = (cui_menu_event_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->highlighted_menu_id)
    {
        case MENU_ID_NOTE_LIST_VIEW:
            mmi_note_entry_view_screen();
            break;
        case MENU_ID_NOTE_LIST_EDIT:
        case MENU_ID_NOTE_VIEW_OPT_EDIT:
            mmi_note_entry_edit_screen();
            break;
        case MENU_ID_NOTE_LIST_NEW_NOTE:
            mmi_note_entry_add_screen();
            break;
        case MENU_ID_NOTE_LIST_MARK_SEVERAL:
            memset(g_mmi_note_mark_cntx.mark_flag, 0x00, MMI_MAX_NOTE_ITEM);
            mmi_note_entry_mark_several_screen();
            break;
        case MENU_ID_NOTE_LIST_DELETE:
        case MENU_ID_NOTE_VIEW_OPT_DEL:
            mmi_note_entry_delete_confirm(evt->highlighted_menu_id);
            break;
        case MENU_ID_NOTE_MARK:
        case MENU_ID_NOTE_MARK_ALL:
        case MENU_ID_NOTE_UNMARK:
        case MENU_ID_NOTE_UNMARK_ALL:
        case MENU_ID_NOTE_MARKED_DEL:
            mmi_note_mark_several_mark_option_item(evt->highlighted_menu_id);
            break;
        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_note_menu_cui_entry_evt_hdlr
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_menu_cui_entry_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* evt = (cui_menu_event_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
        case MENU_ID_NOTE_LIST_OPTION:
            mmi_note_list_option_entry_evt_hdlr(evt);
            break;
        case MENU_ID_NOTE_VIEW_OPTION:
            mmi_note_view_option_entry_evt_hdlr(evt);
            break;
        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_note_menu_cui_exit_evt_hdlr
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_menu_cui_exit_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* evt = (cui_menu_event_struct*)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_note_menu_cui_highlight_evt_hdlr
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_menu_cui_highlight_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* evt = (cui_menu_event_struct*)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
        default:
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_note_menu_cui_item_tap_evt_hdlr
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_menu_cui_item_tap_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* evt = (cui_menu_event_struct*)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {

    }
}


/*****************************************************************************
* FUNCTION
*  mmi_note_menu_cui_item_csk_evt_hdlr
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_menu_cui_item_csk_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* evt = (cui_menu_event_struct*)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->parent_menu_id)
    {
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_note_menu_cui_close_request_evt_hdlr
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_menu_cui_close_request_evt_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* evt = (cui_menu_event_struct*)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_close(evt->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_list_screen
* DESCRIPTION
*  This function is entry function of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 node_index = 0;
    U8 *gui_buffer;
    U16 empty_icon[MMI_MAX_NOTE_ITEM] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ENTRY_NOTE_LIST_SCREEN);
    
    if(!mmi_frm_scrn_enter(
              GRP_ID_NOTE_MAIN, 
              SCR_ID_NOTE_LIST, 
              NULL, 
              mmi_note_entry_list_screen, 
              MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }	
        
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ITEM_INFO, __LINE__, g_mmi_note_cntx.item_num, g_mmi_note_edit_cntx.curr_item);

    if (gui_buffer)
    {
        change_list_menu_category_history(gui_buffer, g_mmi_note_edit_cntx.curr_item, g_mmi_note_cntx.item_num, 0);
    }
    else
    {
        g_mmi_note_edit_cntx.curr_item = 0;
    }

    /* set curr_edit to empty */
    memset(g_mmi_note_edit_cntx.curr_edit, 0x00, (MMI_MAX_NOTE_LEN + 1) * ENCODING_LENGTH);

    RegisterHighlightHandler(mmi_note_list_highlight_hdlr);
    
    if (g_mmi_note_cntx.item_num)
    {
        node_index = g_mmi_note_cntx.note_list[0].next_node;

        for (i = 0; i < g_mmi_note_cntx.item_num; i++)
        {
            memset((CHAR*)subMenuDataPtrs[i], 0x00, MAX_SUB_MENU_SIZE);
            mmi_ucs2ncpy((CHAR*)subMenuDataPtrs[i], (CHAR*)g_mmi_note_cntx.note_list[node_index].note_node, MMI_NOTE_NODE_LEN);
            node_index = g_mmi_note_cntx.note_list[node_index].next_node;
        }

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory89Screen(
            STR_ID_NOTE_APP,
            GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_mmi_note_cntx.item_num,
            subMenuDataPtrs,
            NULL,
            0,
            g_mmi_note_edit_cntx.curr_item,
            gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_note_entry_list_screen_fte_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */

        SetLeftSoftkeyFunction(mmi_note_entry_list_option_screen, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_note_entry_view_screen, KEY_EVENT_UP);
    }
    else
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        
        ShowCategory84Screen(
            STR_ID_NOTE_APP,
            GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN),
            STR_GLOBAL_ADD,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            subMenuDataPtrs,
            (U16*)empty_icon,
            LIST_MENU,
            0,
            NULL);

        SetLeftSoftkeyFunction(mmi_note_entry_add_screen, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_note_entry_add_screen, KEY_EVENT_UP);
    }
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); 
}


/*****************************************************************************
* FUNCTION
*  mmi_note_list_highlight_hdlr
* DESCRIPTION
*  This function is high light handler of note list
* PARAMETERS
*  S32         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_note_edit_cntx.curr_item = index;
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_note_entry_list_screen_fte_tap_callback
* DESCRIPTION
*  note list screen tap callback function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_note_entry_list_screen_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
		mmi_note_entry_view_screen();
    }
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_list_option_screen
* DESCRIPTION
*  This function is entry note list option screen of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_list_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ENTRY_NOTE_LIST_OPTION_SCREEN);
	
	MMI_NOTE_CHECK_SYNCML

    menu_cui_id = cui_menu_create(
                        GRP_ID_NOTE_MAIN, 
                        CUI_MENU_SRC_TYPE_APPCREATE, 
                        CUI_MENU_TYPE_OPTION, 
                        MENU_ID_NOTE_LIST_OPTION, 
                        MMI_FALSE, 
                        NULL);

    cui_menu_enable_center_softkey(menu_cui_id, 0, IMG_GLOBAL_COMMON_CSK);

    cui_menu_run(menu_cui_id);

}


/*****************************************************************************
* FUNCTION
*  mmi_note_list_option_entry_evt_hdlr
* DESCRIPTION
*  This function is entry note list option screen of note application
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_list_option_entry_evt_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[MENU_ID_NOTE_LIST_TOTAL - 1];
    U16 list_of_str[MENU_ID_NOTE_LIST_TOTAL - 1] = 
    {
        STR_GLOBAL_VIEW, 
        STR_GLOBAL_EDIT, 
        STR_ID_NOTE_NEW_NOTE, 
        STR_ID_NOTE_MARK_SEVERAL, 
        STR_GLOBAL_DELETE
    };
    U8 submenu_num;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	submenu_num = MENU_ID_NOTE_LIST_TOTAL - 1;

    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR *)get_string(STR_GLOBAL_OPTIONS), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN)));
    
    for(i = 0; i < submenu_num; i++)
    {
        list_of_ids[i] = MENU_ID_NOTE_LIST_VIEW + i;
    }
    
    cui_menu_set_currlist(evt->sender_id, submenu_num, list_of_ids);

    for(i = 0; i < submenu_num; i++)
    {
        cui_menu_set_item_string(evt->sender_id, list_of_ids[i], (WCHAR*)get_string(list_of_str[i]));
    }
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_note_entry_view_screen_fte_tap_callback
* DESCRIPTION
*  note view screen tap callback function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_note_entry_view_screen_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM) && wgui_category_if_pop_option_menu())
    {
		mmi_note_entry_view_option_screen();
    }

}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_view_screen
* DESCRIPTION
*  This function is used to view note 
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
	U16 cur_text_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ENTRY_NOTE_VIEW_SCREEN);
	
	MMI_NOTE_CHECK_SYNCML
	
    if(!mmi_frm_scrn_enter(
              GRP_ID_NOTE_MAIN, 
              SCR_ID_NOTE_VIEW, 
              NULL, 
              mmi_note_entry_view_screen, 
              MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }	
        
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ITEM_INFO, __LINE__, g_mmi_note_cntx.item_num, g_mmi_note_edit_cntx.curr_item);
	mmi_note_load_text(g_mmi_note_edit_cntx.curr_item);

	cur_text_len = mmi_ucs2strlen((CHAR*)g_mmi_note_edit_cntx.curr_edit);

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_CONTENT_VIEW_LENGTH, cur_text_len);

	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		
	ShowCategory74Screen(
		STR_GLOBAL_VIEW,
		GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN),
		STR_GLOBAL_OPTIONS,
		IMG_GLOBAL_OPTIONS,
		STR_GLOBAL_BACK,
		IMG_GLOBAL_BACK,
		(PU8)g_mmi_note_edit_cntx.curr_edit,
		cur_text_len + 1,
        gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_note_entry_view_screen_fte_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */

    SetLeftSoftkeyFunction(mmi_note_entry_view_option_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_note_entry_edit_screen, KEY_EVENT_UP);   
}


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_view_option_screen
* DESCRIPTION
*  This function is enter note view option screen
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_view_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ENTRY_NOTE_VIEW_OPTION_SCREEN);
	
	MMI_NOTE_CHECK_SYNCML
        
    menu_cui_id = cui_menu_create(
                        GRP_ID_NOTE_MAIN, 
                        CUI_MENU_SRC_TYPE_APPCREATE, 
                        CUI_MENU_TYPE_OPTION, 
                        MENU_ID_NOTE_VIEW_OPTION, 
                        MMI_FALSE, 
                        NULL);
    
    cui_menu_run(menu_cui_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_note_view_option_entry_evt_hdlr
* DESCRIPTION
*  This function is high light handler of view option screen
* PARAMETERS
*  S32 [IN]         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_view_option_entry_evt_hdlr(cui_menu_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_of_str[2] = {STR_GLOBAL_EDIT, STR_GLOBAL_DELETE};
    mmi_menu_id list_of_ids[2] = {MENU_ID_NOTE_VIEW_OPT_EDIT,
                                  MENU_ID_NOTE_VIEW_OPT_DEL};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_title(
         evt->sender_id, 
         (WCHAR *)get_string(STR_GLOBAL_OPTIONS), 
         (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN)));

    cui_menu_set_currlist(evt->sender_id, 2, list_of_ids);

    cui_menu_set_item_string(evt->sender_id, list_of_ids[0], (WCHAR*)get_string(list_of_str[0]));
    cui_menu_set_item_string(evt->sender_id, list_of_ids[1], (WCHAR*)get_string(list_of_str[1]));
}


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_add_screen
* DESCRIPTION
*  This function is used to enter add note screen 
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_add_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ENTRY_NOTE_ADD_SCREEN);
	if (g_mmi_note_cntx.item_num == MMI_MAX_NOTE_ITEM)	/* limitation item pop up and return */
	{
        mmi_popup_display_simple(       
            (WCHAR*)get_string(STR_ID_NOTE_ITEM_LIMIT),
            MMI_EVENT_FAILURE,            
            GRP_ID_ROOT,               
            NULL);                

        return;
	}

	g_mmi_note_edit_cntx.curr_item = (U16)(-1);

	mmi_note_entry_edit_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_edit_screen
* DESCRIPTION
*  This function is enter note edit screen
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_edit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fs_editor_cui;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ENTRY_NOTE_EDIT_SCREEN);
	
	MMI_NOTE_CHECK_SYNCML

    fs_editor_cui = cui_fseditor_create(GRP_ID_NOTE_MAIN);

    if (fs_editor_cui != GRP_ID_INVALID)
    {

		if (g_mmi_note_edit_cntx.curr_item == (U16)(-1))
		{
			MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_EDIT_SCREEN_ADD_BRANCH);
			memset(g_mmi_note_edit_cntx.curr_edit, 0x00, (MMI_MAX_NOTE_LEN + 1) * ENCODING_LENGTH);
            cui_fseditor_set_title(fs_editor_cui, STR_ID_NOTE_NEW_NOTE, GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN));
        }
		else
		{
			MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_EDIT_SCREEN_EDIT_BRANCH);
			mmi_note_load_text(g_mmi_note_edit_cntx.curr_item);
            cui_fseditor_set_title(fs_editor_cui, STR_GLOBAL_EDIT, GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN));
        }

        cui_fseditor_set_buffer(
            fs_editor_cui, 
            g_mmi_note_edit_cntx.curr_edit, 
            (MMI_MAX_NOTE_LEN + 1) * ENCODING_LENGTH,
            MMI_MAX_NOTE_LEN);
        
        cui_fseditor_set_input_method(
            fs_editor_cui, 
            IMM_INPUT_TYPE_SENTENCE, 
            NULL,
            0);       
        
        cui_fseditor_run(fs_editor_cui);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_note_content_option_done
* DESCRIPTION
*  This function is to save content success and pop up "done"
* PARAMETERS
*  S32 [IN]         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_edit_option_done(cui_fseditor_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_EDIT_OPTION_DONE);

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ITEM_INFO, __LINE__, g_mmi_note_cntx.item_num, g_mmi_note_edit_cntx.curr_item);

    cui_fseditor_get_text(evt->sender_id, (WCHAR *)g_mmi_note_edit_cntx.curr_edit, (MMI_MAX_NOTE_LEN + 1) * ENCODING_LENGTH);
    
	/* no content to save */
	if (mmi_ucs2strlen((CHAR*)g_mmi_note_edit_cntx.curr_edit) == 0)
	{
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_EDIT_OPTION_DONE_EMPTY_CONTENT);

		/* user new a note with empty content back to note list screen */
		if (g_mmi_note_edit_cntx.curr_item == (U16)(-1))
		{
		    /* do nothing, and goback note list */
		    return;
		}
		else	/* user clean valid note item to empty */
		{
			mmi_note_update_content_hilite_cntx(g_mmi_note_edit_cntx.curr_item, NULL, MMI_NOTE_OP_DELETE);

            mmi_popup_display_simple(       
                (WCHAR*)get_string(STR_ID_NOTE_NOTE_DELETED),
                MMI_EVENT_SUCCESS,            
                GRP_ID_ROOT,               
                NULL); 

			mmi_frm_scrn_close(GRP_ID_NOTE_MAIN, SCR_ID_NOTE_VIEW);
		}
	}
	else
	{
	    /* from addition */
		if (g_mmi_note_edit_cntx.curr_item == (U16)(-1))
		{
			/* save new note */
			U16 hilite = 0;
			nvram_ef_note_app_node_struct nvram_buf;
			
			memset(&nvram_buf, 0x00, sizeof(nvram_ef_note_app_node_struct));
			
			mmi_ucs2cpy((CHAR*)nvram_buf.node_record, (CHAR*)g_mmi_note_edit_cntx.curr_edit);
			
			hilite = mmi_note_update_content_hilite_cntx((U16)(-1), &nvram_buf, MMI_NOTE_OP_ADD);
			
			g_mmi_note_edit_cntx.curr_item = hilite;
		}
        /* from modification */
		else
		{
			U16 hilite = 0;
			nvram_ef_note_app_node_struct nvram_buf;
			
			memset(&nvram_buf, 0x00, sizeof(nvram_ef_note_app_node_struct));
			
			mmi_ucs2cpy((CHAR*)nvram_buf.node_record, (CHAR*)g_mmi_note_edit_cntx.curr_edit);
			
			hilite = mmi_note_update_content_hilite_cntx(g_mmi_note_edit_cntx.curr_item, &nvram_buf, MMI_NOTE_OP_EDIT);

			g_mmi_note_edit_cntx.curr_item = hilite;
		}
		
        mmi_popup_display_simple(       
             (WCHAR*)get_string(STR_GLOBAL_DONE),
             MMI_EVENT_SUCCESS,            
             GRP_ID_ROOT,               
             NULL); 
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_note_mark_several_pen_down
* DESCRIPTION
*  This function is to register pen down on mark several screen
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_mark_several_pen_down(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_note_mark_several_change_mark_state();
}
#endif /* __MMI_TOUCH_SCREEN__ */


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_note_entry_mark_several_screen_fte_tap_callback
* DESCRIPTION
*  note application mark several screen tap callback function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_note_entry_mark_several_screen_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*if ((tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM))
    {
        if (wgui_category_if_pop_option_menu())
        {
    		mmi_note_entry_mark_several_option_screen();
        }
        else
        {
            mmi_note_mark_several_pen_down();
        }
    }*/
    mmi_note_mark_several_pen_down();
}
#endif /* __MMI_FTE_SUPPORT__ */

/*****************************************************************************
* FUNCTION
*  mmi_note_entry_mark_several_screen
* DESCRIPTION
*  This function is to enter mark several screen
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_mark_several_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 *gui_buffer;
    U16 node_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ENTRY_MARK_SEVERAL_SCREEN);
	
	MMI_NOTE_CHECK_SYNCML
              
    if(!mmi_frm_scrn_enter(
              GRP_ID_NOTE_MAIN, 
              SCR_ID_NOTE_MARK, 
              NULL, 
              mmi_note_entry_mark_several_screen, 
              MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }	
        
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    
    RegisterHighlightHandler(mmi_note_mark_several_highlight_hdlr);

    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ITEM_INFO, __LINE__, g_mmi_note_cntx.item_num, g_mmi_note_edit_cntx.curr_item);

    node_index = g_mmi_note_cntx.note_list[0].next_node;

    for (i = 0; i < g_mmi_note_cntx.item_num; i++)
    {
        memset((CHAR*)subMenuDataPtrs[i], 0x00, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((CHAR*)subMenuDataPtrs[i], (CHAR*)g_mmi_note_cntx.note_list[node_index].note_node, MMI_NOTE_NODE_LEN);
        node_index = g_mmi_note_cntx.note_list[node_index].next_node;

        if (node_index == 0)
        {
            break;
        }
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
    
    ShowCategory12Screen(
        STR_ID_NOTE_MARK_SEVERAL,
        GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        g_mmi_note_cntx.item_num,
        (U8 **) subMenuDataPtrs,
        (U8*)g_mmi_note_mark_cntx.mark_flag,
        g_mmi_note_edit_cntx.curr_item,
        gui_buffer);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_note_entry_mark_several_screen_fte_tap_callback);
#else
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(mmi_note_mark_several_pen_down);
    #endif
#endif

    SetLeftSoftkeyFunction(mmi_note_entry_mark_several_option_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_note_mark_several_change_mark_state, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_note_mark_several_highlight_hdlr
* DESCRIPTION
*  This function is to get current high light item in mark several list
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_mark_several_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_mmi_note_mark_cntx.hilite_item = index;
}

    
/*****************************************************************************
* FUNCTION
*  mmi_note_entry_mark_several_option_screen
* DESCRIPTION
*  This function is enter function of mark several option screen 
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_mark_several_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id menu_cui_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ENTRY_MARK_SEVERAL_OPTION_SCREEN);
	
	MMI_NOTE_CHECK_SYNCML

    menu_cui_id = cui_menu_create(
                        GRP_ID_NOTE_MAIN, 
                        CUI_MENU_SRC_TYPE_RESOURCE, 
                        CUI_MENU_TYPE_OPTION, 
                        MENU_ID_NOTE_MARK_SEVERAL_OPTION, 
                        MMI_FALSE, 
                        NULL);
  cui_menu_set_default_title(menu_cui_id, 
		                       (WCHAR*)(GetString(STR_GLOBAL_OPTIONS)),
                           get_image(GetRootTitleIcon(MENU_ID_NOTE_APP_MAIN)));  
	mmi_note_update_mark_several_option_menu(menu_cui_id);

    cui_menu_run(menu_cui_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_note_update_mark_several_option_menu
* DESCRIPTION
*  This function is update mark several option screen with current mark flag state
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_update_mark_several_option_menu(mmi_id cui_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_UPDATE_MARK_SEVERAL_OPTION_MENU);

    cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_MARK, MMI_FALSE);
    cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_UNMARK, MMI_FALSE);
    cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_MARK_ALL, MMI_FALSE);
    cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_UNMARK_ALL, MMI_FALSE);
    cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_MARKED_DEL, MMI_FALSE);
   
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_ITEM_INFO, __LINE__, g_mmi_note_cntx.item_num, g_mmi_note_edit_cntx.curr_item);

	/* current item is marked */
	if (g_mmi_note_mark_cntx.mark_flag[g_mmi_note_mark_cntx.hilite_item])
	{
        cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_MARK, MMI_TRUE);
	}
	else
	{
        cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_UNMARK, MMI_TRUE);
	}
	
	{
		U8 i = 0, mark_item = 0, unmark_item = 0;
		
		/* if all item unmarked, hide unmarked all menu and delete menu */
		for (i = 0; i < g_mmi_note_cntx.item_num; i++)
		{
			if (g_mmi_note_mark_cntx.mark_flag[i])
			{
				mark_item++;
			}
			else
			{
				unmark_item++;
			}
		}
		
		if (mark_item == 0)		/* no item marked */
		{
            cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_UNMARK_ALL, MMI_TRUE);
            cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_MARKED_DEL, MMI_TRUE);
		}
		
		if (unmark_item == 0)	/* all item marked */
		{
            cui_menu_set_item_hidden(cui_id, MENU_ID_NOTE_MARK_ALL, MMI_TRUE);
		}

		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_MARK_SEVERAL_NUM, mark_item, unmark_item);		
	}	
}


/*****************************************************************************
* FUNCTION
*  mmi_note_mark_several_mark
* DESCRIPTION
*  This function is high light function of delete marked note items
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_mark_several_mark_option_item(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_MARK_SEVERAL_MENU_FUNC);

	switch(menu_id)
	{
        case MENU_ID_NOTE_MARK:
        case MENU_ID_NOTE_UNMARK:
			g_mmi_note_mark_cntx.mark_flag[g_mmi_note_mark_cntx.hilite_item] = !g_mmi_note_mark_cntx.mark_flag[g_mmi_note_mark_cntx.hilite_item];
            mmi_frm_scrn_close_active_id();
            break;
            
        case MENU_ID_NOTE_MARK_ALL:
            memset(g_mmi_note_mark_cntx.mark_flag, 0x01, MMI_MAX_NOTE_ITEM);
            mmi_frm_scrn_close_active_id();
            break;

        case MENU_ID_NOTE_UNMARK_ALL:
			memset(g_mmi_note_mark_cntx.mark_flag, 0x00, MMI_MAX_NOTE_ITEM);
            mmi_frm_scrn_close_active_id();
            break;
            
        case MENU_ID_NOTE_MARKED_DEL:
            mmi_note_entry_delete_confirm(menu_id);
            break;
    	default:
    	    break;
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_note_mark_several_change_mark_state
* DESCRIPTION
*  This function is used to change mark state in mark list screen
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_mark_several_change_mark_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_CHANGE_MARK_STATE);

	g_mmi_note_mark_cntx.mark_flag[g_mmi_note_mark_cntx.hilite_item] = !g_mmi_note_mark_cntx.mark_flag[g_mmi_note_mark_cntx.hilite_item];

	standard_check_list_handle_left_softkey_up();
}


/*****************************************************************************
* FUNCTION
*  mmi_note_delete_confirm_proc
* DESCRIPTION
*  This function is used to delete selected note both for view screen and list screen
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static mmi_ret mmi_note_delete_confirm_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            switch(alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    if ((mmi_menu_id)(U32)(alert->user_tag) == MENU_ID_NOTE_MARKED_DEL)
                    {
                        mmi_note_entry_marked_delete_confirm_ok();
                    }
                    else
                    {
                        mmi_note_entry_delete_confirm_ok();
                    }
                    break;
                case MMI_ALERT_CNFM_NO:
                    mmi_frm_scrn_close_active_id();
                    break;
                default:
                    break;
            }
        }
		default:
			break;
    }

	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_list_option_delete
* DESCRIPTION
*  This function is used to delete selected note both for view screen and list screen
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_delete_confirm(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
	U16 str_id_conf = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_DEL_CONFIRM);

	if (menu_id == MENU_ID_NOTE_MARKED_DEL)
	{
		str_id_conf = STR_ID_NOTE_DELETE_MARKED_ASK;
    }
	else
	{
		str_id_conf = STR_ID_NOTE_DELETE_NOTE_ASK;
	}

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    arg.user_tag = (void*)menu_id;
    arg.callback = mmi_note_delete_confirm_proc;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    
    mmi_confirm_display(
        (WCHAR*)get_string(str_id_conf), 
        MMI_EVENT_QUERY, 
        &arg);
}


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_list_option_delete_ok
* DESCRIPTION
*  This function is used to pop up after delete note success
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_delete_confirm_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_DEL_CONFIRM_OK);
    
    /* only delete one */
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_DEL_NOTE, g_mmi_note_edit_cntx.curr_item);

	mmi_note_update_content_hilite_cntx(g_mmi_note_edit_cntx.curr_item, NULL, MMI_NOTE_OP_DELETE);

    mmi_popup_display_simple(       
         (WCHAR*)get_string(STR_GLOBAL_DELETED),
         MMI_EVENT_SUCCESS,            
         GRP_ID_ROOT,               
         NULL); 
    
	/* return to list screen */
    mmi_frm_scrn_close(GRP_ID_NOTE_MAIN, SCR_ID_NOTE_VIEW);
}


/*****************************************************************************
* FUNCTION
*  mmi_note_entry_marked_delete_confirm_ok
* DESCRIPTION
*  This function is used to pop up after delete note success
* PARAMETERS
*  void         
* RETURNS
*  void
 *****************************************************************************/
static void mmi_note_entry_marked_delete_confirm_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0, del_num = 0;
    U16 total_num = g_mmi_note_cntx.item_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* mark screen exist and delete several */
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_DEL_MARKED);

    for (i = 0; i < total_num; i++)
    {
    	if (g_mmi_note_mark_cntx.mark_flag[i] == 1)
    	{
    		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_DEL_MARKED_ITEM, i);

    		mmi_note_update_content_hilite_cntx((U16)(i - del_num), NULL, MMI_NOTE_OP_DELETE);

    		del_num++;
    	}
    }

    mmi_popup_display_simple(       
         (WCHAR*)get_string(STR_GLOBAL_DELETED),
         MMI_EVENT_SUCCESS,            
         GRP_ID_ROOT,               
         NULL);
    
	/* return to list screen */
    mmi_frm_scrn_close(GRP_ID_NOTE_MAIN, SCR_ID_NOTE_VIEW);
    mmi_frm_scrn_close(GRP_ID_NOTE_MAIN, SCR_ID_NOTE_MARK);
}


/*****************************************************************************
* FUNCTION
*  mmi_note_app_init
* DESCRIPTION
*  This function is used to init note application data from NVRAM
* PARAMETERS
*  void         
* RETURNS
*  total note list item 
 *****************************************************************************/
U8 mmi_note_app_init(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 count = 0;
	U16 i = 0;
	S16 error;
    nvram_ef_note_app_node_struct *nvram_buf = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_APP_INIT);
	memset(&g_mmi_note_cntx, 0x00, sizeof(mmi_note_list_struct));

	nvram_buf = OslMalloc(sizeof(nvram_ef_note_app_node_struct));
		
	memset(nvram_buf, 0x00, sizeof(nvram_ef_note_app_node_struct));

	/* read record of all note items information */
	for (i = 1; i <= MMI_MAX_NOTE_ITEM; i++)
	{
		/* read all items from NVRAM */
		ReadRecord(NVRAM_EF_NOTE_APP_LID, i, (void*)nvram_buf, sizeof(nvram_ef_note_app_node_struct), &error);  

		/* node time and record len to check empty record */
		if (nvram_buf->create_time)
		{
			/* save record of content and NVRAM index */
			mmi_ucs2ncpy((CHAR*)g_mmi_note_cntx.note_list[i].note_node, (CHAR*)nvram_buf->node_record, MMI_NOTE_NODE_LEN);
			g_mmi_note_cntx.note_list[i].modify_time = nvram_buf->modify_time;
			g_mmi_note_cntx.note_list[i].create_time = nvram_buf->create_time;

			count++;
		}
	}

	g_mmi_note_cntx.item_num = count;

    mmi_note_sort_list();

	if (nvram_buf)
	{
		OslMfree(nvram_buf);
		nvram_buf = NULL;
	}

	return count;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_sort_list
* DESCRIPTION
*  This function is used to sort note list in initialize 
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static void mmi_note_sort_list(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, count = 0, j, temp;
    U16 *sort_list = NULL, *p;
	U32 i_time, j_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_note_cntx.item_num == 0)
	{
        g_mmi_note_cntx.note_list[0].next_node = 0;
        g_mmi_note_cntx.note_list[0].prior_node = 0;
        return;
    }
	
    /* sizeof(U16)* g_mmi_note_cntx.item_numn  must be less than 2k */
    sort_list = (U16*)OslMalloc((U32)(sizeof(U16) * g_mmi_note_cntx.item_num));
    MMI_ASSERT(sort_list);
    p = sort_list;
	
    /* set value of sort_list with init valid note index */
    for (i = 1; i <= MMI_MAX_NOTE_ITEM; i++)
    {
        if (count == g_mmi_note_cntx.item_num)
        {
            break;
        }
        if (g_mmi_note_cntx.note_list[i].create_time)
		{
            *p = i;
            p++;
            count++;
        }
		}

	
    /* sort not list */
    for (i = 0; i < g_mmi_note_cntx.item_num; i++)
    {
        for (j = i + 1 ; j < g_mmi_note_cntx.item_num; j++)
        {
			
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
			i_time = g_mmi_note_cntx.note_list[sort_list[i]].modify_time;
			j_time = g_mmi_note_cntx.note_list[sort_list[j]].modify_time;
#else
			i_time = g_mmi_note_cntx.note_list[sort_list[i]].create_time;
			j_time = g_mmi_note_cntx.note_list[sort_list[j]].create_time;
#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */

			if ((i_time < j_time) ||
				(i_time == j_time && sort_list[i] > sort_list[j])) /* equal time, the one with greater nvarm index should be sorted into the behind position */
            {
                temp = sort_list[i];
                sort_list[i] = sort_list[j];
                sort_list[j] = temp;
            }
        }
    }
	
    /* set value for g_mmi_note_cntx link */
    g_mmi_note_cntx.note_list[0].next_node = sort_list[0];
    
    for (i = 0; i < g_mmi_note_cntx.item_num; i++)
    {
        /* set next node of link */
        if (i == g_mmi_note_cntx.item_num - 1)
        {
            /* for the last node */
            g_mmi_note_cntx.note_list[sort_list[i]].next_node = 0;
            g_mmi_note_cntx.note_list[0].prior_node = sort_list[i];
        }
        else
        {
            g_mmi_note_cntx.note_list[sort_list[i]].next_node = sort_list[i + 1];
        }
		
        /* set previous node of link */
        if (i == 0)
        {
            /* for the first node */
            g_mmi_note_cntx.note_list[sort_list[i]].prior_node = 0;
        }
        else
        {
            g_mmi_note_cntx.note_list[sort_list[i]].prior_node = sort_list[i - 1];
        }
    }
    
	
    OslMfree(sort_list);
	
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_load_text
* DESCRIPTION
*  This function is used to load text with high light index from NVRAM
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_load_text(U16 hilite)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 node_pos = 0;
    nvram_ef_note_app_node_struct *nvram_buf = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_LOAD_FUNC, hilite);

	nvram_buf = OslMalloc(sizeof(nvram_ef_note_app_node_struct));

    memset(nvram_buf, 0x00, sizeof(nvram_ef_note_app_node_struct));
	
	node_pos = mmi_note_get_nvram_index(hilite);

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_LOAD_POS, node_pos);

	mmi_note_update_content_note_record(MMI_NOTE_OP_GET, node_pos, nvram_buf);

	mmi_ucs2ncpy((CHAR*)g_mmi_note_edit_cntx.curr_edit, (CHAR*)nvram_buf->node_record, MMI_MAX_NOTE_LEN);

	if (nvram_buf)
	{
		OslMfree(nvram_buf);
		nvram_buf = NULL;
	}

    return node_pos;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_get_valid_storage_index
* DESCRIPTION
*  This function is used to get a valid NVRAM index to save a new note
* PARAMETERS
*  void         
* RETURNS
* U16
 *****************************************************************************/
static U16 mmi_note_get_valid_storage_index(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_GET_NVRAM_INDEX);

	/* find a valid NVRAM index to save new note */
	for (i = 1; i <= MMI_MAX_NOTE_ITEM; i++)
	{		
		if (g_mmi_note_cntx.note_list[i].create_time == 0)
		{
			return i;
		}
	}

	return i;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_update_content_note_record
* DESCRIPTION
*  This function is used to update a note record
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_update_content_note_record(mmi_note_operation_enum note_opt, 
											  U16 update_node, 
											  nvram_ef_note_app_node_struct *node_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 result = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(note_opt)
	{
	case MMI_NOTE_OP_EDIT:
		{
			MMI_ASSERT(node_cntx);

			/* delete and add note node */
			result = mmi_note_edit(update_node, node_cntx);

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
			if (result == MMI_NOTE_ACTION_SUCCESS)
			{
				mmi_syncml_note_data_changed_notification(SYNCML_RECORD_MODIFY, (U16)(update_node - 1));
			}
#endif
		}
		break;

	case MMI_NOTE_OP_ADD:
		{
			MMI_ASSERT(node_cntx);
						
			result = mmi_note_add(update_node, node_cntx);

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
			if (result == MMI_NOTE_ACTION_SUCCESS)
			{
				mmi_syncml_note_data_changed_notification(SYNCML_RECORD_ADD, (U16)(update_node - 1));
			}
#endif
		}
		break;

	case MMI_NOTE_OP_GET:
		{
			MMI_ASSERT(node_cntx);

			if (mmi_note_get_hilite_index(update_node) != (U16)(-1))
			{
				result = mmi_note_get(update_node, node_cntx);
			}
			else
			{
				result = MMI_NOTE_ACTION_NOT_FOUND;
				break;
			}
		}
	    break;

	case MMI_NOTE_OP_DELETE:
		{
			if (mmi_note_get_hilite_index(update_node) != (U16)(-1))
			{
				result = mmi_note_delete(update_node);
			}
			else
			{
				result = MMI_NOTE_ACTION_NOT_FOUND;
				break;
			}

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
			if (result == MMI_NOTE_ACTION_SUCCESS)
			{
				mmi_syncml_note_data_changed_notification(SYNCML_RECORD_DELETE, (U16)(update_node - 1));
			}
#endif
		}
	    break;

	default:
		{
			MMI_ASSERT(0);
		}
	    break;
	}

	MMI_NOTE_CHECK_LIST
		MMI_NOTE_PRINT_ALL(0)
		
	return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_edit
* DESCRIPTION
*  This function is used to edit a note 
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_edit(U16 index, nvram_ef_note_app_node_struct *node_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 prior_note = 0;
	U16 next_note = 0;
	U16 insert_pos = 0;
	S16 error = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* remove this node from note list */
	{
		prior_note = g_mmi_note_cntx.note_list[index].prior_node;
		next_note = g_mmi_note_cntx.note_list[index].next_node;
		
		g_mmi_note_cntx.note_list[prior_note].next_node = next_note;
		g_mmi_note_cntx.note_list[next_note].prior_node = prior_note;
		
		g_mmi_note_cntx.item_num--;
	}

	/* find index position to insert note item */
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
	insert_pos = mmi_note_check_pos_note_list(node_cntx->modify_time, index);
#else /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
	insert_pos = mmi_note_check_pos_note_list(node_cntx->create_time, index);
#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */

	WriteRecord(NVRAM_EF_NOTE_APP_LID, 
		index, 
		(void*)node_cntx, 
		sizeof(nvram_ef_note_app_node_struct), 
		&error);

	/* insert update node item to note list */
	{
		/* set update node information */
		g_mmi_note_cntx.note_list[index].create_time = node_cntx->create_time;
		g_mmi_note_cntx.note_list[index].modify_time = node_cntx->modify_time;
		g_mmi_note_cntx.note_list[index].prior_node = insert_pos;
		g_mmi_note_cntx.note_list[index].next_node = g_mmi_note_cntx.note_list[insert_pos].next_node;
		mmi_ucs2ncpy((CHAR*)g_mmi_note_cntx.note_list[index].note_node, 
			(CHAR*)node_cntx->node_record, MMI_NOTE_NODE_LEN);

		g_mmi_note_cntx.item_num++;
		
		/* set prior node information */
		g_mmi_note_cntx.note_list[insert_pos].next_node = index;
		
		/* set next node information */
		g_mmi_note_cntx.note_list[g_mmi_note_cntx.note_list[index].next_node].prior_node = index;
	}

	return MMI_NOTE_ACTION_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_add
* DESCRIPTION
*  This function is used to add a note 
* PARAMETERS
*  U16 update_node : must valid
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_add(U16 index, nvram_ef_note_app_node_struct *node_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 insert_pos = 0;
	S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* need find a new NVRAM index */
	if (index == (U16)(-1))
	{
		MMI_ASSERT(0);
	}

	if ((node_cntx->create_time == 0) || (node_cntx->modify_time == 0))
	{
		MMI_ASSERT(0);
	}
	
	/* find index position to insert note item */
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
	insert_pos = mmi_note_check_pos_note_list(node_cntx->modify_time, index);
#else /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
	insert_pos = mmi_note_check_pos_note_list(node_cntx->create_time, index);
#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_UPDATE_CONTENT_ADD_INFO, index, insert_pos);
	
	WriteRecord(NVRAM_EF_NOTE_APP_LID, 
		index, 
		(void*)node_cntx, 
		sizeof(nvram_ef_note_app_node_struct), 
		&error);

	/* insert update node item to note list */
	{
		/* set update node information */
		g_mmi_note_cntx.note_list[index].create_time = node_cntx->create_time;
		g_mmi_note_cntx.note_list[index].modify_time = node_cntx->modify_time;
		g_mmi_note_cntx.note_list[index].prior_node = insert_pos;
		g_mmi_note_cntx.note_list[index].next_node = g_mmi_note_cntx.note_list[insert_pos].next_node;
		mmi_ucs2ncpy((CHAR*)g_mmi_note_cntx.note_list[index].note_node, 
					(CHAR*)node_cntx->node_record, MMI_NOTE_NODE_LEN);
		
		/* set prior node information */
		g_mmi_note_cntx.note_list[insert_pos].next_node = index;

		/* set next node information */
		g_mmi_note_cntx.note_list[g_mmi_note_cntx.note_list[index].next_node].prior_node = index;
	}

	/* total item num add 1 */
	g_mmi_note_cntx.item_num++;

	return MMI_NOTE_ACTION_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_delete
* DESCRIPTION
*  This function is used to delete a note 
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_delete(U16 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 prior_note = 0;
	U16 next_note = 0;
	nvram_ef_note_app_node_struct *note_node = NULL;
	S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(index);
	
	note_node = OslMalloc(sizeof(nvram_ef_note_app_node_struct));

	/* set update node NVRAM content to empty */
	memset(note_node, 0x00, sizeof(nvram_ef_note_app_node_struct));
	
	WriteRecord(NVRAM_EF_NOTE_APP_LID, 
		index, 
		(void*)note_node, 
		sizeof(nvram_ef_note_app_node_struct), 
		&error);
	
	if (note_node)
	{
		OslMfree(note_node);
		note_node = NULL;
	}

	/* set prior node and next node */
	{
		prior_note = g_mmi_note_cntx.note_list[index].prior_node;
		next_note = g_mmi_note_cntx.note_list[index].next_node;

		g_mmi_note_cntx.note_list[prior_note].next_node = next_note;
		g_mmi_note_cntx.note_list[next_note].prior_node = prior_note;
	}

	memset(&g_mmi_note_cntx.note_list[index], 0x00, sizeof(mmi_note_node_struct));
	
	g_mmi_note_cntx.item_num--;

	return MMI_NOTE_ACTION_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_get
* DESCRIPTION
*  This function is used to get a note 
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_get(U16 index, nvram_ef_note_app_node_struct *node_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(index);
	MMI_ASSERT(node_cntx);

	ReadRecord(NVRAM_EF_NOTE_APP_LID, 
		index, 
		(void*)node_cntx, 
		sizeof(nvram_ef_note_app_node_struct), 
		&error);
	
	return MMI_NOTE_ACTION_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_update_content_hilite_cntx
* DESCRIPTION
*  This function is used to update content of note 
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_update_content_hilite_cntx(U16 hilite, nvram_ef_note_app_node_struct *node_cntx, mmi_note_operation_enum note_op)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 note_pos = 0;
	U16 nvram_index = 0;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_UPDATE_CONTENT);

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_UPDATE_CONTENT_INFO, hilite, note_op);

	switch(note_op)
	{
	case MMI_NOTE_OP_EDIT:
		{
			/* first valid note position */
			note_pos = mmi_note_get_nvram_index(hilite);

			/* set current modify time */
			node_cntx->create_time = g_mmi_note_cntx.note_list[note_pos].create_time;
			node_cntx->modify_time = app_getcurrtime();

			MMI_NOTE_PRINT_TIME_INFO(node_cntx->modify_time)

			mmi_note_update_content_note_record(MMI_NOTE_OP_EDIT, note_pos, node_cntx);

			/* return note hilite index */
			return mmi_note_get_hilite_index(note_pos);
		}
		break;

	case MMI_NOTE_OP_ADD:
		{
			if (hilite != (U16)(-1))
			{
				MMI_ASSERT(0);
			}

			/* get empty NVRAM index */
			nvram_index = mmi_note_get_valid_storage_index();

			/* save create time and modify time */
			node_cntx->create_time = app_getcurrtime();
			node_cntx->modify_time = node_cntx->create_time;

			mmi_note_update_content_note_record(MMI_NOTE_OP_ADD, nvram_index, node_cntx);

			return mmi_note_get_hilite_index(nvram_index);
		}
		break;

	case MMI_NOTE_OP_DELETE:
		{
			note_pos = mmi_note_get_nvram_index(hilite);

			mmi_note_update_content_note_record(MMI_NOTE_OP_DELETE, note_pos, node_cntx);

		}
	    break;

	default:
	    break;
	}

	return (U16)(-1);

}


/*****************************************************************************
* FUNCTION
*  mmi_note_check_pos_note_list
* DESCRIPTION
*  This function is used to get position of note by current time
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_check_pos_note_list(U32 curr_time, U16 nvram_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 insert_pos = 0; /* init with first header node , insert after insert_pose */
    U16 j = 0;
	U8 count = 0;
	U32 cmp_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* get next node index from first note node */
	j = g_mmi_note_cntx.note_list[0].next_node;

    /* insert_pos is the previous node, j is the current node to compare with */
	for (count = 0; count < g_mmi_note_cntx.item_num; count++)
	{
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
		cmp_time = g_mmi_note_cntx.note_list[j].modify_time;
#else /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
		cmp_time = g_mmi_note_cntx.note_list[j].create_time;
#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
		
		/* time > cmp_time insert new note */
		if (curr_time > cmp_time)
		{
			/* return note node index and insert to index.next */
			return insert_pos;
		}
        else if (curr_time == cmp_time)
        {
		    /* if cmp_time's index is greater then input nvram index,
			   the target node should be previous to the j */
            if (j > nvram_index)
            {
			/* insert before this equal node, 
			the node with small nvram index and equal time value 
				should be sorted in prior position */
                return insert_pos; 
            }
			else
			{
				insert_pos = j;
				j = g_mmi_note_cntx.note_list[j].next_node;
			}
		}
		else
		{
			insert_pos = j;
			j = g_mmi_note_cntx.note_list[j].next_node;
		}
	}

	return insert_pos;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_get_hilite_index
* DESCRIPTION
*  This function is used to get high light with NVRAM index
* PARAMETERS
*  U16          
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_get_hilite_index(U16 nvram_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0;
	U8 hilite = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_NOTEAPP_TRACE_007, nvram_index);
	for (hilite = 0; hilite < g_mmi_note_cntx.item_num; hilite++)
	{
		/* time > cmp_time insert new note */
		if (g_mmi_note_cntx.note_list[i].next_node == nvram_index)
		{
			return hilite;
		}
		else
		{
			i = g_mmi_note_cntx.note_list[i].next_node;
		}
	}
	
	return (U16)(-1);
}


/*****************************************************************************
* FUNCTION
*  mmi_note_get_nvram_index
* DESCRIPTION
*  This function is used to get high light with NVRAM index
* PARAMETERS
*  U16          
* RETURNS
*  U8
 *****************************************************************************/
static U16 mmi_note_get_nvram_index(U16 hilite)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0;
	U16 next_note = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	next_note = g_mmi_note_cntx.note_list[0].next_node;

	for (i = 0; i < hilite; i++)
	{
		MMI_ASSERT(next_note);
		next_note = g_mmi_note_cntx.note_list[next_note].next_node;
	}
	
	return next_note;
}


#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mmi_note_get_total_record_index_array
* DESCRIPTION
*  This function is used to get current record count and their index list array
* PARAMETERS
*  U16 *
* RETURNS
*  U16
 *****************************************************************************/
U16 mmi_note_get_total_record_index_array(U16 *luid_array)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0;
	U16 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (luid_array)
	{
		while (g_mmi_note_cntx.note_list[i].next_node)
		{
			/* index set from 0 for SYNCML */
			luid_array[j] = g_mmi_note_cntx.note_list[i].next_node - 1;
			i = g_mmi_note_cntx.note_list[i].next_node;
			j++;
		}
		MMI_ASSERT(j == g_mmi_note_cntx.item_num);
	}


	return g_mmi_note_cntx.item_num;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_get_record_size
* DESCRIPTION
*  This function is used to get max note length
* PARAMETERS
*  void          
* RETURNS
*  U16
 *****************************************************************************/
U16 mmi_note_get_record_size(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return MMI_NOTE_SYNC_FILE_SIZE;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_is_busy
* DESCRIPTION
*  This function is used to get current note application status
* PARAMETERS
*  void          
* RETURNS
*  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_note_is_busy(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_NOTE_MAIN))
    {
        return MMI_TRUE;
    }
    
	return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_sync_update_sync_file
* DESCRIPTION
*  This function is used to get or set data to SyncML file
* PARAMETERS
*  U16          
* RETURNS
*  S32 :  file operator error code
 *****************************************************************************/
static S32 mmi_note_sync_update_sync_file(U8 action, CHAR* path, U8* note_node)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh = 0;
	U32 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(action)
	{
	case SYNCML_RECORD_GET:	/* write note content to file */
		{
			U32 file_size = 0;
			fh = FS_Open((U16 *)path, FS_READ_WRITE | FS_CREATE_ALWAYS);

			if (fh <= 0)
			{
				return fh;
			}

			file_size = strlen((const char*)note_node);
			
			FS_Write(fh, (void*)note_node, file_size, &length);

			FS_Close(fh);
		}
		break;

	case SYNCML_RECORD_ADD:	/* read note from file */
	case SYNCML_RECORD_MODIFY:
		{
			fh = FS_Open((U16 *)path, FS_READ_ONLY);

			if (fh <= 0)
			{
				return fh;
			}

			FS_Read(fh, (void*)note_node, MMI_NOTE_SYNC_FILE_SIZE, &length);

			FS_Close(fh);
		}
	    break;

	default:
		MMI_ASSERT(0);
	    break;
	}

	return 1;
}


/*****************************************************************************
* FUNCTION
*  mmi_note_sync_pnote
* DESCRIPTION
*  This function is used to get or set data with SYNCML
* PARAMETERS
*  U16          
* RETURNS
*  U8
 *****************************************************************************/
U16 mmi_note_sync_pnote(U8 action, CHAR* path, U16 *index, U8 sync_charset)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 result = MMI_NOTE_ACTION_SUCCESS;
    nvram_ef_note_app_node_struct *sync_note = NULL;
	U8 *sync_content = NULL;
    U16 note_index = *index + 1;	/* sync index is  0 ~ 49, but note is 1 ~ 50 so need +1 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (index == NULL 
		|| ((action != SYNCML_RECORD_DELETE) && (path == NULL))
		|| ((action != SYNCML_RECORD_ADD) && (*index == (U16)(-1))))
	{
		return MMI_NOTE_ACTION_ERROR;
	}

	sync_note = OslMalloc(sizeof(nvram_ef_note_app_node_struct));
	sync_content = OslMalloc(MMI_NOTE_SYNC_FILE_SIZE + 1);

	memset(sync_note, 0x00, sizeof(nvram_ef_note_app_node_struct));
	memset(sync_content, 0x00, MMI_NOTE_SYNC_FILE_SIZE + 1);
	
	switch (action)
	{
	case SYNCML_RECORD_GET:
		{
		    if (mmi_note_get_hilite_index(note_index) == (U16)(-1))
		    {
		        result = MMI_NOTE_ACTION_NOT_FOUND;
		        break;
		    }
		    
			/* get note content */
			result = mmi_note_update_content_note_record(MMI_NOTE_OP_GET, note_index, sync_note);

			/* ucs2 -> utf8 */
			mmi_chset_convert(
				CHSET_UCS2,
				CHSET_UTF8, 
				(char*)sync_note->node_record, 
				(char*)sync_content, 
                MMI_NOTE_SYNC_FILE_SIZE + 1);

			/* write note content to sync note file */
			mmi_note_sync_update_sync_file(SYNCML_RECORD_GET, path, sync_content);
		}
		break;

	case SYNCML_RECORD_ADD:
		{
			/* note list is full */
			if (g_mmi_note_cntx.item_num >= MMI_MAX_NOTE_ITEM)
			{
				result = MMI_NOTE_ACTION_MEMORY_FULL;
				break;
			}
			else
			{
				mmi_note_sync_update_sync_file(SYNCML_RECORD_ADD, path, sync_content);

				/* note sync add an empty note */
				if (strlen((const char *)sync_content) == 0)
				{
					result = MMI_NOTE_ACTION_NO_CONTENT;
					break;
				}

				/* utf8 -> ucs2 */
				mmi_chset_convert(
					CHSET_UTF8,
					CHSET_UCS2, 
					(char*)sync_content, 
					(char*)sync_note->node_record, 
					(MMI_MAX_NOTE_LEN + 1) * ENCODING_LENGTH);
				
				/* get valid NVRAM index */
				{
					note_index = mmi_note_get_valid_storage_index();
                    *index = note_index - 1;
				}

				/* set create time and modify time */
				{
					sync_note->create_time = app_getcurrtime();
					sync_note->modify_time = sync_note->create_time;
				}

				result = mmi_note_update_content_note_record(MMI_NOTE_OP_ADD, note_index, sync_note);
			}
		}
		break;

	case SYNCML_RECORD_MODIFY:
		{
		    if (mmi_note_get_hilite_index(note_index) == (U16)(-1))
		    {
		        result = MMI_NOTE_ACTION_NOT_FOUND;
		        break;
		    }
		    		    
			mmi_note_sync_update_sync_file(SYNCML_RECORD_MODIFY, path, sync_content);

			/* note sync add an empty note */
			if (strlen((const char *)sync_content) == 0)
			{
				result = MMI_NOTE_ACTION_NO_CONTENT;
				break;
			}

			/* utf8 -> ucs2 */
			mmi_chset_convert(
				CHSET_UTF8,
				CHSET_UCS2, 
				(char*)sync_content, 
				(char*)sync_note->node_record, 
				(MMI_MAX_NOTE_LEN + 1) * ENCODING_LENGTH);

			/* set create time and modify time */
			{
				sync_note->create_time = g_mmi_note_cntx.note_list[note_index].create_time;
				sync_note->modify_time = app_getcurrtime();
			}

			result = mmi_note_update_content_note_record(MMI_NOTE_OP_EDIT, note_index, sync_note);
		}
	    break;

	case SYNCML_RECORD_DELETE:
		{
            if (mmi_note_get_hilite_index(note_index) == (U16)(-1))
		    {
		        result = MMI_NOTE_ACTION_NOT_FOUND;
		        break;
		    }

            result = mmi_note_update_content_note_record(MMI_NOTE_OP_DELETE, note_index, NULL);
		}
	    break;
		
	default:
	    break;
	}

	if (sync_note)
	{
		OslMfree(sync_note);
		sync_note = NULL;
	}

	if (sync_content)
	{
		OslMfree(sync_content);
		sync_content = NULL;
	}

	return result;
}

#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */


/* NOTE APPLICATION DEBUG FUNCTION */
static void mmi_note_print_all(U32 line, U8 nvram_lid)
{
#ifdef __MMI_NOTE_DEBUG__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	U16 next_node = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] LINE[%d] mmi_note_print_all() ----", line);
	
	if (nvram_lid == 0 || nvram_lid > MMI_MAX_NOTE_ITEM)
	{
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] mmi_note_print_all() -- 1 ----");
		
		next_node = g_mmi_note_cntx.note_list[0].next_node;
		
		while (next_node)
		{
			MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, 
				"----[NoteApp.c] NVRAM_LID[%d] CREATE[%d] MODIFY[%d] PRIOR[%d] NEXT[%d]----",
				next_node, 
				g_mmi_note_cntx.note_list[next_node].create_time,
				g_mmi_note_cntx.note_list[next_node].modify_time,
				g_mmi_note_cntx.note_list[next_node].prior_node,
				g_mmi_note_cntx.note_list[next_node].next_node);
			
				/*
				mmi_wprintf(MOD_MMI_COMMON_APP, 
				"----[NoteApp.c] NVRAM_LID[%d] CONTENT[%s]----",
				next_node,
				g_mmi_note_cntx.note_list[next_node].note_node);
			*/
			
			next_node = g_mmi_note_cntx.note_list[next_node].next_node;
		}
	}
	else
	{
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] mmi_note_print_all() -- 2 ----");
		
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, 
			"----[NoteApp.c] NVRAM_LID[%d] CREATE[%d] MODIFY[%d] PRIOR[%d] NEXT[%d]----",
			nvram_lid, 
			g_mmi_note_cntx.note_list[nvram_lid].create_time,
			g_mmi_note_cntx.note_list[nvram_lid].modify_time,
			g_mmi_note_cntx.note_list[nvram_lid].prior_node,
			g_mmi_note_cntx.note_list[nvram_lid].next_node);
	}
	
#endif /* __MMI_NOTE_DEBUG__ */
	
}


static void mmi_note_debug_check_queue(U32 line)
{
#ifdef __MMI_NOTE_DEBUG__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	U8 count = 0;
	U16 prior_node = 0, next_node = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	next_node = g_mmi_note_cntx.note_list[prior_node].next_node;
	
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] LINE[%d] mmi_note_debug_check_queue() ----", line);
	
	while (next_node)
	{
		/* check prior and next */
		{
			if (g_mmi_note_cntx.note_list[prior_node].next_node != next_node)
			{
				MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] LINE[%d] next_code not match ----", __LINE__);
#ifdef __MTK_TARGET__
				kal_sleep_task(50);
#endif
				MMI_ASSERT(0);
			}
			
			if (g_mmi_note_cntx.note_list[next_node].prior_node != prior_node)
			{
				MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] LINE[%d] prior not match ----", __LINE__);
#ifdef __MTK_TARGET__
				kal_sleep_task(50);
#endif
				MMI_ASSERT(0);
			}
		}
		
		/* check content */
		{
			if (mmi_ucs2strlen((const CHAR*)(g_mmi_note_cntx.note_list[next_node].note_node)) == 0)
			{
				MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] LINE[%d] empty content ----", __LINE__);
#ifdef __MTK_TARGET__
				kal_sleep_task(50);
#endif
				MMI_ASSERT(0);
			}
		}
		
		/* check num */
		{
			prior_node = next_node;
			next_node = g_mmi_note_cntx.note_list[next_node].next_node;
			count++;
		}
	}
	
	if (g_mmi_note_cntx.item_num != count)
	{
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] LINE[%d] count error ----", __LINE__);
#ifdef __MTK_TARGET__
		kal_sleep_task(50);
#endif
		MMI_ASSERT(0);
	}
	
#endif /* __MMI_NOTE_DEBUG__ */
	
}

void mmi_note_debug_print_time_info(U32 line, U32 time)
{
#ifdef __MMI_NOTE_DEBUG__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	kal_char temp_string[200];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	memset(temp_string, 0x00, 200);
	
	applib_dt_time2rfc1123dateString((U32)time, temp_string);
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G2_ORG, "----[NoteApp.c] LINE[%d] time[%s] ----", line, temp_string);
#endif /* __MMI_NOTE_DEBUG__ */
}

#endif /* __MMI_NOTE_APP__ */


