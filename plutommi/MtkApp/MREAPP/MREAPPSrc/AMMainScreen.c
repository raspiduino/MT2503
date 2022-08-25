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
*   AMMainScreen.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   AM Main Screen Src
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
//#ifdef __MRE_AM__
#include "mmi_features.h"
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "AMSwitch.h"
#include "CustThemesRes.h"
#include "MMIDataType.h"
#include "gui_fixed_menus.h"
#include "wgui_touch_screen.h"
#include "DebugInitDef_Int.h"
#include "MMI_mre_trc.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_fmgr.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "wgui_categories.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "gui.h"
#include "string.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "gui_windows.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "stack_config.h"
#include "wgui_draw_manager.h"
#include "gui_themes.h"
#include "gui_data_types.h"
#include "gui_switch.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "stdio.h"
#include "Conversions.h"
#include "fs_gprot.h"
#include "med_struct.h"
#include "AMDef.h"      /* Add AM head file */
#include "AMGprot.h"    /* Add AM head file */
#include "AMUtil.h"
#include "AMConfig.h"
#include "AMMainScreen.h"
#include "AMScreens.h"
#include "liblist.h"
#include "AMProxy.h"
#include "MRESrvGProt.h"
#include "MREAppMgrSrvGprot.h"
#include "mmi_rp_app_am_def.h"
#if defined (MMI_AM_SHORTCUT_ENABLE)
#include "AMShortcut.h"
#endif
#include "MRESrvDownloadGprot.h"

/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
mmi_am_ms_struct g_am_ms_cntx;
extern mmi_am_cntx_struct g_am_cntx;
extern MMI_theme *current_MMI_theme;
extern const U8 AM_App_Default[];
extern char AM_App_MRE20[];
extern fixed_matrix_menu MMI_fixed_matrix_menu;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_am_eixt_main_scrn(void);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_am_intuitive_cb(mmi_tap_type_enum tap_type, S32 index);
#endif 

static mmi_ret mmi_am_leave_main_scrn(mmi_event_struct *evt);
static mmi_ret mmi_am_ms_deinit(void);
void mmi_am_ms_release_applist_node(mmi_am_ms_app_struct *p_node);
static void mmi_am_ms_release_applist_node_ex(S32 idx);
static void mmi_am_ms_download_prompt(void);
static void mmi_am_ms_draw_cb(
                              S32 idx,
                              S32 page_start_idx,
                              S32 page_end_idx,
                              BOOL is_hilighted,
                              BOOL is_need_update,
                              BOOL is_new_page,
                              S32 x1,
                              S32 y1,
                              S32 x2,
                              S32 y2);
static void mmi_am_ms_draw_app_icon(S32 idx, S32 page_start_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_am_ms_draw_status_icon(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_am_ms_draw_app_name(S32 idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_am_ms_get_app_name_size(S32 idx, S32 *str_w, S32 *str_h);
static void mmi_am_ms_draw_default_app_name(S32 x, S32 y);
static void mmi_am_ms_draw_app_name_int(S32 idx, S32 x, S32 y, S32 str_w, S32 str_h);
static U16 *mmi_am_ms_get_app_name_by_idx(S32 idx);
static U8 *mmi_am_ms_get_app_zimo_by_idx(S32 idx, S32 *str_len);
static void mmi_am_ms_draw_app_name_scrolling(S32 idx, S32 x, S32 y, S32 width, S32 height);
static void mmi_am_ms_scroll_handler(void);
static void mmi_am_ms_scroll_draw_bg(S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_am_ms_zimo_scroll_cb(void);
static void mmi_am_ms_hide_cb(S32 index);
static U16 mmi_am_ms_get_icon_resid(S32 idx);
static U8 *mmi_am_ms_get_icon_ptr(S32 idx, S32 page_start_idx, U32 *icon_size);

/* Update App list */
//static MMI_BOOL mmi_am_ms_update_app_list(S32 page_start_idx, S32 page_end_idx);
static mmi_am_ms_app_struct *mmi_am_ms_get_appinfo_from_vxplist(mmi_am_vxp_file_struct *vxp_p);

/* Update MRE CDR */
static void mmi_am_ms_update_cdr(void);

extern U8 PhnsetGetDefEncodingType(void);
extern MMI_BOOL gui_screen_smooth_scrolling_by_pen(void);
//extern mmi_ret srv_mre_launch_app_confirm_popup_proc (mmi_alert_result_evt_struct *evt);
extern  mmi_am_ms_app_struct *  mmi_am_ms_get_vxp_by_index(const mre_list_t * list,U32 index);

//extern mmi_ret srv_mre_install_app_confirm_popup_proc (mmi_alert_result_evt_struct *evt);
//extern srv_mre_write_app_path(U16 *app_path);
static U32 mmi_am_ms_get_unique_id(S32 idx, S32 page_start_idx);



/*****************************************************************************
* FUNCTION
*  mmi_am_entry_main_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_entry_main_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U16 num_of_items;
    U8 *gui_buffer;
    U16 left_softkey, left_softkey_icon;
    S32 category_error_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTRY_MAIN_SCRN_S);

    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_MAIN, mmi_am_eixt_main_scrn, mmi_am_entry_main_scrn, MMI_FRM_FULL_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

    //mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);

    num_of_items = mre_single_list_get_size(g_am_ms_cntx.app_list) + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MS_ENTRY_SCREEN, num_of_items);

    //if (num_of_items == g_am_ms_cntx.hl_idx)
    if ((num_of_items == g_am_ms_cntx.hl_idx) && (g_am_ms_cntx.hl_idx != 0))
    {
        gui_buffer = NULL;
        g_am_ms_cntx.hl_idx--;
    }

    if ((!g_am_ms_cntx.is_able_to_download) && (g_am_cntx.shortcut_app_num > 0) && !mmi_am_ms_is_app_download(0))
    {
        left_softkey = STR_GLOBAL_OK;
        left_softkey_icon = IMG_GLOBAL_OK;
    }
    else if (num_of_items == 0)
    {
        left_softkey = 0;
        left_softkey_icon = 0;
    }
    else
    {
        left_softkey = STR_GLOBAL_OPTIONS;
        left_softkey_icon = IMG_GLOBAL_OPTIONS;
    }

    if (g_am_cntx.is_card_plug_in || g_am_cntx.is_card_plug_out)
    {
        g_am_cntx.is_card_plug_in = MMI_FALSE;
        g_am_cntx.is_card_plug_out = MMI_FALSE;
        gui_buffer = NULL;
        g_am_ms_cntx.hl_idx = 0;
    }

    wgui_cat214_disable_draw_highlight();

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
  //  ShowCategory214Screen(MAIN_MENU_MRE_TEXT,   /* STR_ID_AM_NAME, */
    //    0,
    //    left_softkey, left_softkey_icon, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, num_of_items,      /* num of item */
     //   mmi_am_ms_draw_cb,    /* draw color callback */
     //   mmi_am_ms_hide_cb,    /* hide color callback */
     //   g_am_ms_cntx.cfg->app_num_per_col,    /* number of app per col */
     //   g_am_ms_cntx.cfg->app_num_per_row,    /* number of app per row */
     //   g_am_ms_cntx.hl_idx,  /* hilighted item */
     //   (U8*) gui_buffer);
        ShowCategory219Screen(MAIN_MENU_MRE_TEXT,   /* STR_ID_AM_NAME, */
        0,
        left_softkey, STR_GLOBAL_BACK, num_of_items,      /* num of item */
        mmi_am_ms_draw_cb,    /* draw color callback */
        mmi_am_ms_hide_cb,    /* hide color callback */
        g_am_ms_cntx.cfg->app_num_per_col,    /* number of app per col */
        g_am_ms_cntx.cfg->app_num_per_row,    /* number of app per row */
        g_am_ms_cntx.hl_idx,  /* hilighted item */
        (U8*) gui_buffer,
        &category_error_flag);
#else 
    //ShowCategory214Screen(MAIN_MENU_MRE_TEXT,   /* STR_ID_AM_NAME, */
     //   IMG_ID_AM_TITLE, 
      //  left_softkey, left_softkey_icon, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, num_of_items,      /* num of item */
      //  mmi_am_ms_draw_cb,    /* draw color callback */
      //  mmi_am_ms_hide_cb,    /* hide color callback */
      //  g_am_ms_cntx.cfg->app_num_per_col,    /* number of app per col */
      //  g_am_ms_cntx.cfg->app_num_per_row,    /* number of app per row */
      //  g_am_ms_cntx.hl_idx,  /* hilighted item */
      //  (U8*) gui_buffer);
      ShowCategory219Screen(MAIN_MENU_MRE_TEXT,   /* STR_ID_AM_NAME, */
        IMG_ID_AM_TITLE, 
        left_softkey,STR_GLOBAL_BACK, num_of_items,      /* num of item */
        mmi_am_ms_draw_cb,    /* draw color callback */
        mmi_am_ms_hide_cb,    /* hide color callback */
        g_am_ms_cntx.cfg->app_num_per_col,    /* number of app per col */
        g_am_ms_cntx.cfg->app_num_per_row,    /* number of app per row */
        g_am_ms_cntx.hl_idx,  /* hilighted item */
        (U8*) gui_buffer,
        &category_error_flag);
#endif


    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_MAIN, mmi_am_leave_main_scrn);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_am_intuitive_cb);
#endif 

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

#ifdef MMI_AM_SUPPORT_UPDATE_CDR
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MS_ENTRY_SCREEN_CDR, g_am_cntx.is_prompt_update_cdr);
    /* Update MRE CDR */
    if (mmi_am_is_network_service_available() && !g_am_cntx.is_prompt_update_cdr)
    {
        gui_start_timer(1, mmi_am_ms_update_cdr);   /* For 09B FW issue */
    }
#endif /* MMI_AM_SUPPORT_UPDATE_CDR */ 

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTRY_MAIN_SCRN_E);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_eixt_main_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_eixt_main_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_am_ms_update_cdr);

    mmi_am_ms_scrolling_text_stop();
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_am_intuitive_cb
* DESCRIPTION
*  
* PARAMETERS
*  tap_type        [IN]        
*  index           [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_intuitive_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        if ((!g_am_ms_cntx.is_able_to_download) && !mmi_am_ms_is_app_download(index))
        {
            mmi_am_ms_download_prompt();
        }
        else if ((g_am_ms_cntx.is_able_to_download) && !mmi_am_ms_is_app_download(index))
        {
            mmi_am_os_download();
        }
        else
        {
            mmi_am_os_app_launch();
        }
    }
}
#endif /* __MMI_FTE_SUPPORT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_init
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_ms_cntx.hl_idx = 0;
    /* g_am_ms_cntx.app_list = NULL; */
    g_am_ms_cntx.sc_app_num = 0;
    g_am_ms_cntx.rom_app_num = 0;
    g_am_ms_cntx.vxp_app_num = 0;

    /* check if it can download app */
    if (!mmi_am_is_network_service_available())
    {
        g_am_ms_cntx.is_able_to_download = MMI_FALSE;
    }
    else
    {
        g_am_ms_cntx.is_able_to_download = MMI_TRUE;
    }

    /* get Main Screen configure data */
    g_am_ms_cntx.cfg = mmi_am_config_get_am_ms_info();

    /* new list */
    if (g_am_ms_cntx.app_list == NULL)
    {
        g_am_ms_cntx.app_list = mre_single_list_new();
    }

    memset(&g_am_ms_cntx.scrolling_app_name, 0, sizeof(g_am_ms_cntx.scrolling_app_name));
}


/*****************************************************************************
* FUNCTION
*  mmi_am_leave_main_scrn
* DESCRIPTION
*  
* PARAMETERS
*  evt     [IN]        
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_leave_main_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    mmi_alert_result_evt_struct *alert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MS_LEAVE_SCREEN, evt->evt_id);

    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
        break;

    case EVT_ID_SCRN_DEINIT:
        mmi_am_ms_deinit();
        break;

    case EVT_ID_ALERT_QUIT:
        alert = (mmi_alert_result_evt_struct*) evt;
        switch (alert->result)
        {
        case MMI_ALERT_CNFM_3:
            mmi_frm_scrn_close_active_id();
            break;
        }
        break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_deinit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_ms_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_am_ms_update_cdr);
    mmi_am_ms_scrolling_text_stop();
    mmi_am_ms_release_app_list();
    g_am_ms_cntx.hl_idx = 0;

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_release_applist_node
* DESCRIPTION
*  
* PARAMETERS
*  p_node      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_release_applist_node(mmi_am_ms_app_struct *p_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!p_node)
    {
        return;
    }

    /* delete the node */
    if (p_node->p_icon)
    {
        mmi_am_free(p_node->p_icon);
        p_node->p_icon = NULL;
    }

    if ((p_node->p_name) &&
        mmi_wcscmp((PU16) p_node->p_name, (PU16) GetString(STR_ID_AM_APP_NAME_MRE20)) &&
        mmi_wcscmp((PU16) p_node->p_name, (PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT)))
    {
        mmi_am_free(p_node->p_name);
        p_node->p_name = NULL;
    }

    mmi_am_free(p_node);

    p_node = NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_release_applist_node_ex
* DESCRIPTION
*  release node and update idx after this node in app_list
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_release_applist_node_ex(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_am_ms_app_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = mre_single_list_get_element(g_am_ms_cntx.app_list, idx);

    mmi_am_ms_release_applist_node(p);
    mre_single_list_remove(g_am_ms_cntx.app_list, idx);

    /* update index of every app_list node after deleted node */
    for (i = idx; i < mre_single_list_get_size(g_am_ms_cntx.app_list); i++)
    {
        mmi_am_ms_app_struct *q = mre_single_list_get_element(g_am_ms_cntx.app_list, i);

        q->idx--;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_release_app_list_all_nodes
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_release_app_list_all_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_ms_cntx.app_list)
    {
        while (mre_single_list_get_size(g_am_ms_cntx.app_list))
        {
            mmi_am_ms_app_struct *p = mre_single_list_get_element(g_am_ms_cntx.app_list, 0);

            mmi_am_ms_release_applist_node(p);
            mre_single_list_remove(g_am_ms_cntx.app_list, 0);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_release_app_list_nodes_in_memory_card
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_release_app_list_nodes_in_memory_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 num_of_app_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_ms_cntx.app_list)
    {
        num_of_app_list = mre_single_list_get_size(g_am_ms_cntx.app_list);

        for (i = num_of_app_list - 1; i >= 0; i--)
        {
            mmi_am_ms_app_struct *p = mre_single_list_get_element(g_am_ms_cntx.app_list, i);

            if (((S8) (*(p->path)) != (S8) mmi_am_get_system_driver()) && ((S8) (*(p->path)) != (S8) MMI_AM_ROM_DIR))
            {
                //if (p->idx <= g_am_ms_cntx.hl_idx)
                if ((p->idx <= g_am_ms_cntx.hl_idx) && (g_am_ms_cntx.hl_idx != 0))
                {
                    g_am_ms_cntx.hl_idx--;
                }
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_RELEASE_APP_LIST_NODE, g_am_ms_cntx.hl_idx);
                mmi_am_ms_release_applist_node_ex(i);
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_release_app_list
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_release_app_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_ms_cntx.app_list)
    {
        mmi_am_ms_release_app_list_all_nodes();
        mre_single_list_free(g_am_ms_cntx.app_list);
        g_am_ms_cntx.app_list = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_download_prompt
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_download_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(
        (WCHAR*) get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
        MMI_EVENT_FAILURE,
        GRP_ID_AM,
        NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_scrolling_text_stop
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_scrolling_text_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.has_small_font)
    {
        gui_scrolling_text_stop(&g_am_ms_cntx.scrolling_app_name);
    }
    else
    {
        gui_cancel_timer(mmi_am_ms_zimo_scroll_cb);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_draw_cb
* DESCRIPTION
*  
* PARAMETERS
*  idx                 [IN]        
*  page_start_idx      [IN]        
*  page_end_idx        [IN]        
*  is_hilighted        [IN]        
*  is_need_update      [IN]        
*  is_new_page         [IN]        
*  x1                  [IN]        
*  y1                  [IN]        
*  x2                  [IN]        
*  y2                  [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_draw_cb(
                              S32 idx,    /* start from 0 */
                              S32 page_start_idx,
                              S32 page_end_idx,
                              BOOL is_hilighted,
                              BOOL is_need_update,    /* invalid */
                              BOOL is_new_page,   /* invalid */
                              S32 x1,
                              S32 y1,
                              S32 x2,
                              S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MS_DRAW_CB_S);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MS_DRAW_CB, idx, page_start_idx, page_end_idx, is_hilighted);
    //MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MS_DRAW_CB_POS, x1, y1, x2, y2);

    /* if idx is invalid, do nothing */
    if (idx >= (g_am_cntx.vxp_app_num+ g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        /* stop scrolling when the highlight app does not exist */
        if (is_hilighted)
        {
            mmi_am_ms_scrolling_text_stop();
        }
        return;
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)      /* support smooth scrolling */
    page_end_idx += MMI_fixed_matrix_menu.n_columns;
    if (page_end_idx >= MMI_fixed_matrix_menu.n_items)
    {
        page_end_idx = MMI_fixed_matrix_menu.n_items - 1;
    }
#endif /* __MMI_FTE_SUPPORT__ */ 

    g_am_ms_cntx.page_start_idx = page_start_idx;
    g_am_ms_cntx.page_end_idx = page_end_idx;

    /* if the idx is the first index on the current screen */
    if (idx == page_start_idx)
    {
        /* update Shortcut_App_num and Rom_App_num */
        if (idx < g_am_cntx.shortcut_app_num)
        {
            /* update Shortcut_App_num and Rom_App_num */
            g_am_ms_cntx.sc_app_num = g_am_cntx.shortcut_app_num - idx;
            g_am_ms_cntx.rom_app_num = g_am_cntx.rom_app_num;
        }
        else if(idx <(g_am_cntx.shortcut_app_num+g_am_cntx.rom_app_num))
        {
            g_am_ms_cntx.sc_app_num = 0;
            // if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
            // {
            /* update Shortcut_App_num and Rom_App_num */
            g_am_ms_cntx.rom_app_num = (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num) - idx;
            g_am_ms_cntx.vxp_app_num = g_am_cntx.vxp_app_num;
            // }
        }
        else
        {
            g_am_ms_cntx.rom_app_num = 0;
            g_am_ms_cntx.vxp_app_num = (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num + g_am_cntx.vxp_app_num) - idx;
        }
        // }
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MS_DRAW_CB_APP_NUM, g_am_ms_cntx.sc_app_num, g_am_ms_cntx.rom_app_num,g_am_ms_cntx.vxp_app_num);

        // update app_list
        //page_end = page_start_idx + (g_am_ms_cntx.cfg->app_num_per_col * g_am_ms_cntx.cfg->app_num_per_row) -1;
        /*if (mmi_am_ms_update_app_list(page_start_idx, page_end_idx) == MMI_FALSE)
        {
        mmi_frm_scrn_close_active_id();
        return;
        }*/
    }

    /*************************************************************
    * draw Highlight ICON
    *************************************************************/
    if (is_hilighted)
    {
        g_am_ms_cntx.hl_x1 = x1;
        g_am_ms_cntx.hl_y1 = y1;
        g_am_ms_cntx.hl_x2 = x2;
        g_am_ms_cntx.hl_y2 = y2;

        /* change left soft key */
        if ((!g_am_ms_cntx.is_able_to_download) && !mmi_am_ms_is_app_download(idx))
        {
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            SetLeftSoftkeyFunction(mmi_am_ms_download_prompt, KEY_EVENT_UP);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_am_entry_option_scrn, KEY_EVENT_UP);
        }

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        if ((!g_am_ms_cntx.is_able_to_download) && !mmi_am_ms_is_app_download(idx))
        {
            SetCenterSoftkeyFunction(mmi_am_ms_download_prompt, KEY_EVENT_UP);
        }
        else if ((g_am_ms_cntx.is_able_to_download) && !mmi_am_ms_is_app_download(idx))
        {
            SetCenterSoftkeyFunction(mmi_am_os_download, KEY_EVENT_UP);
        }
        else
        {
            SetCenterSoftkeyFunction(mmi_am_os_app_launch, KEY_EVENT_UP);
        }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)      /* support smooth scrolling */
        /* draw highlight image */
        gdi_image_draw_resized_id(
            x1,
            y1,
            MMI_fixed_matrix_menu.item_width,
            MMI_fixed_matrix_menu.item_height,
            g_am_ms_cntx.cfg->hl_icon_id);
#else /* __MMI_FTE_SUPPORT__ */ 
        /* update highlight icon */
        mmi_am_config_update_am_ms_info();

        /* draw highlight image */
        gdi_image_draw_id(x1, y1, g_am_ms_cntx.cfg->hl_icon_id);
#endif /* __MMI_FTE_SUPPORT__ */ 

        mmi_am_ms_scrolling_text_stop();

        g_am_ms_cntx.hl_idx = idx;
    }

    /*************************************************************
    * draw App ICON
    *************************************************************/
    mmi_am_ms_draw_app_icon(idx, page_start_idx, is_hilighted, x1, y1, x2, y2);

    /*************************************************************
    * draw Status ICON
    *************************************************************/
    mmi_am_ms_draw_status_icon(idx, x1, y1, x2, y2);

    /*************************************************************
    * draw App Name
    *************************************************************/
    mmi_am_ms_draw_app_name(idx, is_hilighted, x1, y1, x2, y2);

    /* MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MS_DRAW_CB_E); */
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_hide_cb
* DESCRIPTION
*  
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_hide_cb(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_draw_app_icon
* DESCRIPTION
*  
* PARAMETERS
*  idx                 [IN]        
*  page_start_idx      [IN]        
*  x1                  [IN]        
*  y1                  [IN]        
*  x2                  [IN]        
*  y2                  [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_draw_app_icon(S32 idx, S32 page_start_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE dest_layer_hdl;
    S32 grid_w; /* grid width */

    // S32 grid_h;  /* grid height */
    S32 img_w;      /* image width */
    S32 img_h;      /* image width */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_hilighted)
    {
        /* get and set source layer */
        gdi_layer_get_active(&dest_layer_hdl);
        gdi_push_and_set_alpha_blending_source_layer(dest_layer_hdl);
    }

    grid_w = (x2 - x1) + 1;
    /* grid_h = (y2 - y1) + 1; */

    if (idx < g_am_cntx.shortcut_app_num)   /* Shortcut app */
    {
        U16 res_id;

        res_id = mmi_am_ms_get_icon_resid(idx);

        /* draw ICON */
        gdi_image_get_dimension_id(res_id, &img_w, &img_h);
        if ((img_w == MMI_AM_APP_ICON_W) && (img_h == MMI_AM_APP_ICON_H))       /* 45*45 */
        {
            gdi_image_draw_id(x1 + ((grid_w - img_w) >> 1), y1 + g_am_ms_cntx.cfg->icon_top_size, res_id);
        }
        else
        {
            /* use default icon */
            gdi_image_draw_id(
                x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                y1 + g_am_ms_cntx.cfg->icon_top_size,
                IMG_ID_AM_APP_DEFAULT);
        }
    }
    else  if (idx < g_am_cntx.rom_app_num + g_am_cntx.shortcut_app_num)
    {
        U8 *res_ptr;
        U32 icon_size = 0;
        U8 icon_type;

        res_ptr = mmi_am_ms_get_icon_ptr(idx, page_start_idx, &icon_size);
        if(res_ptr!=NULL)
        {
            icon_type = gdi_image_get_type_from_mem(res_ptr);
            if (icon_type == GDI_IMAGE_TYPE_INVALID)
            {
                icon_type = GDI_IMAGE_TYPE_AB2;
            }
            gdi_image_get_dimension_mem(icon_type, res_ptr, icon_size, &img_w, &img_h);

            if ((img_w <= MMI_AM_APP_ICON_W) && (img_h <= MMI_AM_APP_ICON_H))       /* 45*45 */
            {
                MMI_AM_ASSERT(res_ptr != NULL);
                gdi_image_draw_mem(
                    x1 + ((grid_w - img_w) >> 1),
                    y1 + g_am_ms_cntx.cfg->icon_top_size + ((MMI_AM_APP_ICON_H - img_h) >> 1),
                    res_ptr,
                    icon_type,
                    icon_size);
            }
            else
            {
                gdi_image_draw_resized_mem(
                    x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                    y1 + g_am_ms_cntx.cfg->icon_top_size,
                    MMI_AM_APP_ICON_W,
                    MMI_AM_APP_ICON_H,
                    res_ptr,
                    icon_type,
                    icon_size);

                /* use default icon */
                /*gdi_image_draw_id(
                x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                y1 + g_am_ms_cntx.cfg->icon_top_size,
                IMG_ID_AM_APP_DEFAULT);*/
            }
        }
        else
        {
            gdi_image_draw_id(
                x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                y1 + g_am_ms_cntx.cfg->icon_top_size,
                IMG_ID_AM_APP_DEFAULT);
        }
    }
    /* is not shortcut app */
    else
    {
        //U8 *res_ptr;
        //U32 icon_size;
        //U8 icon_type;
        mmi_image_src_struct image;
        char app_name[MMI_APP_NAME_MAX_LEN];
        U32 unique_id = 0;
        //change to use draw from file.
        //gdi_image_draw_file(OFFSET_X,OFFSET_Y,IMAGE_NAME);
        //gdi_image_draw_resized_file(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME);
        unique_id = mmi_am_ms_get_unique_id(idx,page_start_idx);
        srv_mre_appmgr_get_package_name_by_unique_id(unique_id,app_name);
        if(srv_mre_appmgr_get_app_image(app_name,&image)==MMI_RET_OK)
            //res_ptr = mmi_am_ms_get_icon_ptr(idx, page_start_idx, &icon_size);
            //if(res_ptr!=NULL)
        {
            // icon_type = gdi_image_get_type_from_mem(res_ptr);
            // if (icon_type == GDI_IMAGE_TYPE_INVALID)
            // {
            //    icon_type = GDI_IMAGE_TYPE_AB2;
            //}
            //gdi_image_get_dimension_mem(icon_type, res_ptr, icon_size, &img_w, &img_h);

            // if ((img_w <= MMI_AM_APP_ICON_W) && (img_h <= MMI_AM_APP_ICON_H))       /* 45*45 */
            // {
            // MMI_AM_ASSERT(res_ptr != NULL);
            // gdi_image_draw_mem(
            //     x1 + ((grid_w - img_w) >> 1),
            //      y1 + g_am_ms_cntx.cfg->icon_top_size + ((MMI_AM_APP_ICON_H - img_h) >> 1),
            //    res_ptr,
            //    icon_type,
            //    icon_size);
            //  }
            // else
            // {
            if(image.type ==MMI_IMAGE_SRC_TYPE_PATH )
            {
                gdi_image_draw_resized_file(
                    x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                    y1 + g_am_ms_cntx.cfg->icon_top_size,
                    MMI_AM_APP_ICON_W,
                    MMI_AM_APP_ICON_W,
                    image.data.path);
            }
            else
            {
                gdi_image_draw_id(
                    x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                    y1 + g_am_ms_cntx.cfg->icon_top_size,
                    IMG_ID_AM_APP_DEFAULT);
            }

            /* use default icon */
            /*gdi_image_draw_id(
            x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
            y1 + g_am_ms_cntx.cfg->icon_top_size,
            IMG_ID_AM_APP_DEFAULT);*/
        }
        //}
        else
        {
            gdi_image_draw_id(
                x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                y1 + g_am_ms_cntx.cfg->icon_top_size,
                IMG_ID_AM_APP_DEFAULT);
        }
    }

    if (is_hilighted)
    {
        /* restore source layer */
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_draw_status_icon
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
*  x1      [IN]        
*  y1      [IN]        
*  x2      [IN]        
*  y2      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_draw_status_icon(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE active_layer_hdl;            /* active layer */
    GDI_HANDLE scr_bg_layer;                /* background image layer */
    S32 index = idx;
    S32 shortcut_icon_w, shortcut_icon_h;   /* shortcut status icon dimension */
    S32 status_icon_w, status_icon_h;       /* BG running status and download status icon dimension */
    S32 grid_w;                             /* grid dimension */
    #ifdef MMI_AM_SHORTCUT_ENABLE
    S32 shortcut_icon_x, shortcut_icon_y;
    #endif
    S32 status_icon_x, status_icon_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&active_layer_hdl);
    scr_bg_layer = dm_get_scr_bg_layer();

    /* get and set source layer */
    gdi_push_and_set_alpha_blending_source_layer(active_layer_hdl);

    /* Flatten: bottom-to-up order 1. background layer; 2. base layer */
    gdi_layer_flatten_with_clipping(scr_bg_layer, active_layer_hdl, 0, 0);

    /* get icon dimension */
    gdi_image_get_dimension_id(IMG_ID_AM_STATE_SHORTCUT, &shortcut_icon_w, &shortcut_icon_h);
    gdi_image_get_dimension_id(IMG_ID_AM_STATE_BG, &status_icon_w, &status_icon_h);
    grid_w = x2 - x1 + 1;
    /* grid_h = y2 - y1 + 1; */

    /* get draw x and y */
    #ifdef MMI_AM_SHORTCUT_ENABLE
    shortcut_icon_x = x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1);
    shortcut_icon_y = y1 + g_am_ms_cntx.cfg->icon_top_size + MMI_AM_APP_ICON_H - shortcut_icon_h;
    #endif
    status_icon_x = x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1) + MMI_AM_APP_ICON_W - status_icon_w + 5;
    status_icon_y = y1 + g_am_ms_cntx.cfg->icon_top_size + MMI_AM_APP_ICON_H - status_icon_h + 8;

    if (index < g_am_cntx.shortcut_app_num)
    {
        /*-------------------------------------------------------------------
        - draw undownload status icon
        --------------------------------------------------------------------*/
        if (!mmi_am_ms_is_app_download(idx))
        {
            gdi_image_draw_id_blend2layers(status_icon_x, status_icon_y, IMG_ID_AM_STATE_UNDOWNLOAD);

            /* restore source layer */
            gdi_pop_and_restore_alpha_blending_source_layer();

            return;
        }
    }

    /*************************************************************
    * draw bg_running & hs_shortcut status icon
    *************************************************************/
#ifdef MMI_AM_SHORTCUT_ENABLE
    if (mmi_am_ms_is_app_set_hs_shortcut(idx))
    {
        gdi_image_draw_id(shortcut_icon_x, shortcut_icon_y, IMG_ID_AM_STATE_SHORTCUT);
    }
#endif /* MMI_AM_SHORTCUT_ENABLE */ 

    if (mmi_am_ms_is_app_bg_running(idx))
    {
        gdi_image_draw_id_blend2layers(status_icon_x, status_icon_y, IMG_ID_AM_STATE_BG);
    }

    /* restore source layer */
    gdi_pop_and_restore_alpha_blending_source_layer();
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_draw_app_name
* DESCRIPTION
*  
* PARAMETERS
*  idx                 [IN]        
*  is_hilighted        [IN]        
*  x1                  [IN]        
*  y1                  [IN]        
*  x2                  [IN]        
*  y2                  [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_draw_app_name(S32 idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* GDI_HANDLE src_layer_hdl, dest_layer_hdl; */
    S32 grid_w; /* grid dimension */
    S32 str_w, str_h, disp_zone_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grid_w = x2 - x1 + 1;
    /* grid_h = y2 - y1 + 1; */
    disp_zone_size = grid_w - (g_am_ms_cntx.cfg->name_indent << 1);

    mmi_am_ms_get_app_name_size(idx, &str_w, &str_h);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        x1 + g_am_ms_cntx.cfg->name_indent,
        y2 - g_am_ms_cntx.cfg->name_below_size - str_h,
        x2 - g_am_ms_cntx.cfg->name_indent,
        y2 - g_am_ms_cntx.cfg->name_below_size);

    if (str_w == 0 && g_am_cntx.has_small_font) /* get app name failure, use default name */
    {
        gui_set_font(&MMI_small_font);
        gui_measure_string((UI_string_type) GetString(STR_ID_AM_APP_NAME_DEFAULT), &str_w, &str_h);
        mmi_am_ms_draw_default_app_name(
            /* x1 + ((grid_w - disp_zone_size) >> 1), */ x1 + ((grid_w - str_w) >> 1),
            y2 - g_am_ms_cntx.cfg->name_below_size - str_h);
        gui_set_font(&MMI_medium_font);
        gdi_layer_pop_clip();

        return;
    }

    if (str_w < disp_zone_size)    /* be able to show all */
    {
        mmi_am_ms_draw_app_name_int(
            idx,
            x1 + ((grid_w - str_w) >> 1),
            y2 - g_am_ms_cntx.cfg->name_below_size - str_h,
            str_w,
            str_h);
    }
    else    /* cant show all */
    {
        /* 
        why we call gui_screen_smooth_scrolling_by_pen() is because when text is scrolling.
        pen_move out of ours matrix box.We can't get the right coordinate.
        our callback function will draw text out of control scope.
        So when the pen_move out of ours matrix box,we will not draw scrolling text.
        you can refer to CR MAUI_03099922.
        */
        if ((!is_hilighted)||gui_screen_smooth_scrolling_by_pen())  /* show app name in the order */
        {
            mmi_am_ms_draw_app_name_int(
                idx,
                x1 + g_am_ms_cntx.cfg->name_indent,
                y2 - g_am_ms_cntx.cfg->name_below_size - str_h,
                str_w,
                str_h);
        }
        else    /* scrolling */
        {
            mmi_am_ms_draw_app_name_scrolling(
                idx,
                x1 + g_am_ms_cntx.cfg->name_indent,
                y2 - g_am_ms_cntx.cfg->name_below_size - str_h,
                disp_zone_size,
                str_h);
        }
    }

    gdi_layer_pop_clip();
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_app_name_size
* DESCRIPTION
*  
* PARAMETERS
*  idx         [IN]        
*  str_w       [OUT]       
*  str_h       [OUT]       
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_get_app_name_size(S32 idx, S32 *str_w, S32 *str_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * Support small font
    *************************************************************/
    *str_w = 0;
    *str_h = 0;
    if (g_am_cntx.has_small_font)
    {
        gui_set_font(&MMI_small_font);
        if (index < g_am_cntx.shortcut_app_num) /* AM Shortcut app */
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))       /* AppStore Support */
            {
                if (index == 0) /* AppStore */
                {
                    gui_measure_string((UI_string_type) GetString(g_am_cntx.appstore_list.name_id), str_w, str_h);
                }
                else    /* Other AM Shortcut App */
                {
                    index--;
                    gui_measure_string(
                        (UI_string_type) GetString(g_am_cntx.shortcut_app_list[index].name_id),
                        str_w,
                        str_h);
                }
            }
            else    /* AppStore dont support */
            {
                gui_measure_string(
                    (UI_string_type) GetString(g_am_cntx.shortcut_app_list[index].name_id),
                    str_w,
                    str_h);
            }
            /* gui_measure_string(GetString(shortcut_info_list[idx].name_id), &str_w, &str_h); */
        }
        else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))    /* Rom app */
        {
            index = idx - g_am_cntx.shortcut_app_num;
            gui_measure_string((UI_string_type) g_am_cntx.rom_app_list[index].p_name, str_w, str_h);
        }
        else    /* download app */
        {
            /* gui_measure_string(g_am_ms_cntx.app_list[index], &str_w, &str_h); */
            mmi_am_ms_app_struct *p;

            //index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            p = mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,index);
            if (p)
            {
                gui_measure_string((UI_string_type) p->p_name, str_w, str_h);
            }
        }
        gui_set_font(&MMI_medium_font);

        if (*str_h == 0)
        {
            *str_h = MMI_AM_APP_NAME_H;
        }

    }
    /*************************************************************
    * Support ZiMo
    *************************************************************/
    else
    {
        if (index < g_am_cntx.shortcut_app_num) /* AM Shortcut app */
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))       /* AppStore Support */
            {
                if (index == 0) /* AppStore */
                {
                    *str_w = mmi_am_measure_zimo(g_am_cntx.appstore_list.p_name, g_am_cntx.appstore_list.name_len);
                }
                else    /* Other AM Shortcut App */
                {
                    index--;
                    *str_w = mmi_am_measure_zimo(
                        g_am_cntx.shortcut_app_list[index].p_name,
                        g_am_cntx.shortcut_app_list[index].name_len);
                }
            }
            else    /* AppStore dont support */
            {
                *str_w = mmi_am_measure_zimo(
                    g_am_cntx.shortcut_app_list[index].p_name,
                    g_am_cntx.shortcut_app_list[index].name_len);
            }
        }
        else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))    /* Rom app */
        {
            index = idx - g_am_cntx.shortcut_app_num;
            *str_w = mmi_am_measure_zimo(g_am_cntx.rom_app_list[index].p_name, g_am_cntx.rom_app_list[index].name_len);
        }
        else    /* download app */
        {
            mmi_am_ms_app_struct *p;

            index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
            if (p)
            {
                *str_w = mmi_am_measure_zimo(p->p_name, p->name_len);
            }
        }

        *str_h = MMI_AM_APP_NAME_H;

    }

}

/*****************************************************************************
* FUNCTION
*  mmi_am_ms_draw_default_app_name
* DESCRIPTION
*  
* PARAMETERS
*  x       [IN]        
*  y       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_draw_default_app_name(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * Support small font
    *************************************************************/
    if (g_am_cntx.has_small_font)
    {
        /* draw */
        gui_set_text_color(*current_MMI_theme->list_normal_text_color);
        gui_move_text_cursor(x, y);
        gui_print_text((UI_string_type) GetString(STR_ID_AM_APP_NAME_DEFAULT));
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_draw_app_name_int
* DESCRIPTION
*  
* PARAMETERS
*  idx         [IN]        
*  x           [IN]        
*  y           [IN]        
*  str_w       [IN]        
*  str_h       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_draw_app_name_int(S32 idx, S32 x, S32 y, S32 str_w, S32 str_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p;
    S32 str_len;
    gdi_color font_color;
    color cur_color = *current_MMI_theme->list_normal_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * Support small font
    *************************************************************/
    if (g_am_cntx.has_small_font)
    {
        gui_set_font(&MMI_small_font);

        /* draw */
        gui_set_text_color(cur_color);
        gui_move_text_cursor(x, y);
        gui_print_text(mmi_am_ms_get_app_name_by_idx(idx));

        gui_set_font(&MMI_medium_font);
    }
    /*************************************************************
    * Support ZiMo
    *************************************************************/
    else
    {
        p = mmi_am_ms_get_app_zimo_by_idx(idx, &str_len);
        font_color = gdi_act_color_from_rgb(255, cur_color.r, cur_color.g, cur_color.b);
        mmi_am_draw_zimo(x, y, 0, str_len, p, str_len, MMI_AM_APP_NAME_H, font_color);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_app_name_by_idx
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
static U16 *mmi_am_ms_get_app_name_by_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;
    U16 res_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * Support small font
    *************************************************************/
    if (g_am_cntx.has_small_font)
    {
        if (index < g_am_cntx.shortcut_app_num) /* AM Shortcut app */
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))       /* AppStore Support */
            {
                if (index == 0) /* AppStore */
                {
                    res_id = g_am_cntx.appstore_list.name_id;
                }
                else    /* Other AM Shortcut App */
                {
                    index--;
                    res_id = g_am_cntx.shortcut_app_list[index].name_id;
                }
            }
            else    /* AppStore dont support */
            {
                res_id = g_am_cntx.shortcut_app_list[index].name_id;
            }
            return (PU16) GetString(res_id);
        }
        else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))    /* Rom app */
        {
            index = idx - g_am_cntx.shortcut_app_num;

            return (PU16) g_am_cntx.rom_app_list[index].p_name;
        }
        else    /* download app */
        {
            mmi_am_ms_app_struct *p;

            //index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            // p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
            p = mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,index);

            if (p)
            {
                return (PU16) p->p_name;
            }
            else
            {
                return NULL;
            }
        }
    }

    return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_app_zimo_by_idx
* DESCRIPTION
*  
* PARAMETERS
*  idx         [IN]        
*  str_len     [OUT]       
* RETURNS
*  
*****************************************************************************/
static U8 *mmi_am_ms_get_app_zimo_by_idx(S32 idx, S32 *str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * Support ZiMo
    *************************************************************/
    if (!g_am_cntx.has_small_font)
    {
        if (index < g_am_cntx.shortcut_app_num) /* AM Shortcut app */
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))       /* AppStore Support */
            {
                if (index == 0) /* AppStore */
                {
                    *str_len = (S32) g_am_cntx.appstore_list.name_len;
                    return g_am_cntx.appstore_list.p_name;
                }
                else    /* Other AM Shortcut App */
                {
                    index--;
                    *str_len = (S32) g_am_cntx.shortcut_app_list[index].name_len;
                    return g_am_cntx.shortcut_app_list[index].p_name;
                }
            }
            else    /* AppStore dont support */
            {
                *str_len = (S32) g_am_cntx.shortcut_app_list[index].name_len;
                return g_am_cntx.shortcut_app_list[index].p_name;
            }
        }
        else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))    /* Rom app */
        {
            index = idx - g_am_cntx.shortcut_app_num;

            *str_len = g_am_cntx.rom_app_list[index].name_len;
            return g_am_cntx.rom_app_list[index].p_name;
        }
        else    /* download app */
        {
            mmi_am_ms_app_struct *p;

            //index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            //p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
            p = mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,index);

            if (p)
            {
                *str_len = p->name_len;
                return p->p_name;
            }
            else
            {
                return NULL;
            }
        }
    }

    return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_draw_app_name_scrolling
* DESCRIPTION
*  
* PARAMETERS
*  idx         [IN]        
*  x           [IN]        
*  y           [IN]        
*  width       [IN]        
*  height      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_draw_app_name_scrolling(S32 idx, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color border_color = gui_color(0, 0, 0);
    color cur_clor = *current_MMI_theme->list_normal_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if beyond the draw zone */
    if (y <= MMI_fixed_matrix_menu.y)
    {
        return;
    }

    /*************************************************************
    * Support small font
    *************************************************************/
    if (g_am_cntx.has_small_font)
    {
        /* create scrolling text */
        gui_create_scrolling_text(
            &g_am_ms_cntx.scrolling_app_name,
            x,
            y,
            width,
            height,
            (UI_string_type) mmi_am_ms_get_app_name_by_idx(idx),
            mmi_am_ms_scroll_handler,
            mmi_am_ms_scroll_draw_bg,
            cur_clor,
            border_color);

        g_am_ms_cntx.scrolling_app_name.text_font = MMI_small_font;
        gui_show_scrolling_text(&g_am_ms_cntx.scrolling_app_name);
    }
    /*************************************************************
    * Support ZiMo
    *************************************************************/
    else
    {
        U8 *p;
        S32 str_len;
        gdi_color color;

        g_am_ms_cntx.scroll_x = 0;
        g_am_ms_cntx.scroll_zone_x1 = x;
        g_am_ms_cntx.scroll_zone_y1 = y;
        g_am_ms_cntx.scroll_zone_x2 = x + width - 1;
        g_am_ms_cntx.scroll_zone_y2 = y + height - 1;
        g_am_ms_cntx.scroll_counter = MMI_AM_MS_TEXT_SCROLL_PAUSE;
        color = gdi_act_color_from_rgb(255, cur_clor.r, cur_clor.g, cur_clor.b);

        p = mmi_am_ms_get_app_zimo_by_idx(idx, &str_len);
        gdi_layer_set_clip(
            g_am_ms_cntx.scroll_zone_x1,
            g_am_ms_cntx.scroll_zone_y1,
            g_am_ms_cntx.scroll_zone_x2,
            g_am_ms_cntx.scroll_zone_y2);
        mmi_am_draw_zimo(x, y, 0, str_len, p, str_len, MMI_AM_APP_NAME_H, color);
        gdi_layer_reset_clip();

        /* start scroll timer */
        gui_start_timer(MMI_AM_MS_SCROLL_TIME, mmi_am_ms_zimo_scroll_cb);
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_scroll_handler
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_scroll_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&g_am_ms_cntx.scrolling_app_name);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_scroll_draw_bg
* DESCRIPTION
*  
* PARAMETERS
*  x1      [IN]        
*  y1      [IN]        
*  x2      [IN]        
*  y2      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_scroll_draw_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)      /* support smooth scrolling */
    gdi_image_draw_resized_id(
        g_am_ms_cntx.hl_x1,
        g_am_ms_cntx.hl_y1,
        MMI_fixed_matrix_menu.item_width,
        MMI_fixed_matrix_menu.item_height,
        g_am_ms_cntx.cfg->hl_icon_id);
#else /* __MMI_FTE_SUPPORT__ */ 
    /* draw highlight image */
    gdi_image_draw_id(g_am_ms_cntx.hl_x1, g_am_ms_cntx.hl_y1, g_am_ms_cntx.cfg->hl_icon_id);
#endif /* __MMI_FTE_SUPPORT__ */ 

    mmi_am_ms_draw_app_icon(
        g_am_ms_cntx.hl_idx,
        g_am_ms_cntx.page_start_idx,
        MMI_FALSE,
        g_am_ms_cntx.hl_x1,
        g_am_ms_cntx.hl_y1,
        g_am_ms_cntx.hl_x2,
        g_am_ms_cntx.hl_y2);
    mmi_am_ms_draw_status_icon(
        g_am_ms_cntx.hl_idx,
        g_am_ms_cntx.hl_x1,
        g_am_ms_cntx.hl_y1,
        g_am_ms_cntx.hl_x2,
        g_am_ms_cntx.hl_y2);
    gdi_layer_blt_previous(g_am_ms_cntx.hl_x1, g_am_ms_cntx.hl_y1, g_am_ms_cntx.hl_x2, g_am_ms_cntx.hl_y2);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_zimo_scroll_cb
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_zimo_scroll_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width = g_am_ms_cntx.scroll_zone_x2 - g_am_ms_cntx.scroll_zone_x1 + 1;
    color cur_color = *current_MMI_theme->list_normal_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_ms_cntx.scroll_counter)
    {
        g_am_ms_cntx.scroll_counter--;
    }
    else
    {
        g_am_ms_cntx.scroll_x -= MMI_AM_MS_TEXT_SCROLL_SIZE;
        if (g_am_ms_cntx.scroll_x <= -(text_width + MMI_AM_MS_TEXT_SCROLL_GAP))
        {
            g_am_ms_cntx.scroll_x = text_width;
        }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)      /* support smooth scrolling */
        gdi_image_draw_resized_id(
            g_am_ms_cntx.hl_x1,
            g_am_ms_cntx.hl_y1,
            MMI_fixed_matrix_menu.item_width,
            MMI_fixed_matrix_menu.item_height,
            g_am_ms_cntx.cfg->hl_icon_id);
#else /* __MMI_FTE_SUPPORT__ */ 
        /* draw highlight image */
        gdi_image_draw_id(g_am_ms_cntx.hl_x1, g_am_ms_cntx.hl_y1, g_am_ms_cntx.cfg->hl_icon_id);
#endif /* __MMI_FTE_SUPPORT__ */ 

        /* draw app icon */
        mmi_am_ms_draw_app_icon(
            g_am_ms_cntx.hl_idx,
            g_am_ms_cntx.page_start_idx,
            MMI_FALSE,
            g_am_ms_cntx.hl_x1,
            g_am_ms_cntx.hl_y1,
            g_am_ms_cntx.hl_x2,
            g_am_ms_cntx.hl_y2);

        /* draw status icon */
        mmi_am_ms_draw_status_icon(
            g_am_ms_cntx.hl_idx,
            g_am_ms_cntx.hl_x1,
            g_am_ms_cntx.hl_y1,
            g_am_ms_cntx.hl_x2,
            g_am_ms_cntx.hl_y2);

        /* draw zimo */
        {
            U8 *p;
            S32 str_len;
            gdi_color color;

            color = gdi_act_color_from_rgb(255, cur_color.r, cur_color.g, cur_color.b);
            p = mmi_am_ms_get_app_zimo_by_idx(g_am_ms_cntx.hl_idx, &str_len);
            gdi_layer_set_clip(
                g_am_ms_cntx.scroll_zone_x1,
                g_am_ms_cntx.scroll_zone_y1,
                g_am_ms_cntx.scroll_zone_x2,
                g_am_ms_cntx.scroll_zone_y2);
            mmi_am_draw_zimo(
                g_am_ms_cntx.scroll_zone_x1 + g_am_ms_cntx.scroll_x,
                g_am_ms_cntx.scroll_zone_y1,
                0,
                str_len,
                p,
                str_len,
                MMI_AM_APP_NAME_H,
                color);
            gdi_layer_reset_clip();
        }

        /* blt */
        gdi_layer_blt_previous(g_am_ms_cntx.hl_x1, g_am_ms_cntx.hl_y1, g_am_ms_cntx.hl_x2, g_am_ms_cntx.hl_y2);
    }
    /* start scroll timer */
    gui_start_timer(MMI_AM_MS_SCROLL_TIME, mmi_am_ms_zimo_scroll_cb);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_icon_resid
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
static U16 mmi_am_ms_get_icon_resid(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AppStore support */
    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
        if (idx == 0)
        {
            return g_am_cntx.appstore_list.icon_id;
        }
        else
        {
            idx--;
            return g_am_cntx.shortcut_app_list[idx].icon_id;
        }
    }
    else
    {
        return g_am_cntx.shortcut_app_list[idx].icon_id;
    }
}


void mmi_am_update_vxp_list_index(mre_list_t * list)
{
    mmi_am_ms_app_struct*	p = NULL;
    __mre_node_t*  ntmp= NULL;
    U32 index = 0;
    if (NULL == list)
    {
        return ;
    }
    ntmp =(__mre_node_t* )( list->node);    /* exist because nb_elt>0 */
    if(ntmp != NULL)
    {
        p =(mmi_am_ms_app_struct *)( ntmp->element);
    }
    else
    {
        return;
    }

    while (ntmp!=NULL&& p!=NULL)
    {
        p->idx = g_am_cntx.shortcut_app_num+g_am_cntx.rom_app_num + index;
        index++;
        ntmp = ntmp->next;
        if(ntmp!=NULL)
        {
            p =(mmi_am_ms_app_struct *)( ntmp->element);
        }
    }
    return ;	
}

mmi_am_ms_app_struct *  mmi_am_ms_get_vxp_by_index(const mre_list_t * list,U32 index)
{
    mmi_am_ms_app_struct*	p = NULL;
    __mre_node_t*  ntmp= NULL;
    if (NULL == list)
    {
        return NULL;
    }
    ntmp =(__mre_node_t* )( list->node);    /* exist because nb_elt>0 */
    if(ntmp != NULL)
    {
        p =(mmi_am_ms_app_struct *)( ntmp->element);
    }
    else
    {
        return NULL;
    }

    while (ntmp!=NULL&& p!=NULL&&  p->idx !=index)
    {
        ntmp = ntmp->next;
        if(ntmp!=NULL)
        {
            p =(mmi_am_ms_app_struct *)( ntmp->element);
        }
    }

    if(ntmp==NULL)
        return NULL;

    return p;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_icon_ptr
* DESCRIPTION
*  
* PARAMETERS
*  idx                 [IN]        
*  page_start_idx      [IN]        
*  icon_size           [OUT]       
* RETURNS
*  
*****************************************************************************/
static U8 *mmi_am_ms_get_icon_ptr(S32 idx, S32 page_start_idx, U32 *icon_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < g_am_cntx.shortcut_app_num)
    {
        return NULL;
    }

    /* Rom App */
    if (idx < g_am_cntx.rom_app_num + g_am_cntx.shortcut_app_num)
    {
        mmi_am_rom_app_struct *p = mmi_am_get_rom_appinfo_by_idx(idx);

        if (p)
        {
            *icon_size = p->icon_size;
            return p->p_icon;
        }
    }
    /* Download App */
    else
    {
        mmi_am_ms_app_struct *p;

        //index = idx - (page_start_idx + g_am_ms_cntx.rom_app_num + g_am_ms_cntx.sc_app_num);
        p = mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,idx);
        //p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
        if (p)
        {
            *icon_size = p->icon_size;
            return p->p_icon;
        }
    }

    return NULL;
}

static U32 mmi_am_ms_get_unique_id(S32 idx, S32 page_start_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < g_am_cntx.shortcut_app_num)
    {
        return 0;
    }

    /* Rom App */
    if (idx < g_am_cntx.rom_app_num + g_am_cntx.shortcut_app_num)
    {
        return 0;
    }
    /* Download App */
    else
    {
        mmi_am_ms_app_struct *p;

        //index = idx - (page_start_idx + g_am_ms_cntx.rom_app_num + g_am_ms_cntx.sc_app_num);
        p = mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,idx);
        //p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
        if (p)
        {
            // *icon_size = p->icon_size;
            return p->app_unique_id;
        }
    }

    return 0;
}



/*****************************************************************************
* FUNCTION
*  mmi_am_ms_build_app_list
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_ms_build_app_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, num;
    S32 n_per_row;
    S32 n_per_col;
    mmi_am_vxp_file_struct *vxp_p;
    mmi_am_ms_app_struct *app_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_per_row = g_am_ms_cntx.cfg->app_num_per_row;
    n_per_col = g_am_ms_cntx.cfg->app_num_per_col;

    /* get the number of apps which need to add to app list */
    num = (n_per_row * n_per_col)       /* number per screen */
        - g_am_cntx.shortcut_app_num    /* number of shortcut apps displayed on the cur screen */
        - g_am_cntx.rom_app_num         /* number of rom apps */
#ifdef AM_MS_CACHE
        + n_per_row;                    /* cache one row */
#else 
        ;
#endif 

    for (i = 0; (i < num) && (i < mre_single_list_get_size(g_am_cntx.vxp_file_list)); i++)
    {
        S8 vxp_path_log[MMI_AM_MAX_APP_FILE_PATH];

        memset(vxp_path_log, 0, sizeof(vxp_path_log));
        vxp_p = mre_single_list_get_element(g_am_cntx.vxp_file_list, i);
        mmi_wcs_to_asc((PS8) vxp_path_log, (PU16) vxp_p->path);

        /* if file does not exist, then update vxp list */
        if (FS_GetAttributes((PS16) vxp_p->path) < FS_NO_ERROR)
        {
            mmi_am_free(vxp_p);
            vxp_p = NULL;
            mre_single_list_remove(g_am_cntx.vxp_file_list, i);
            i--;
            continue;
        }

        app_p = mmi_am_ms_get_appinfo_from_vxplist(vxp_p);
        if (app_p)
        {
            /* set display index */
            app_p->idx = i + (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num);

            /* add the app to app_list */
            if (g_am_ms_cntx.app_list)
            {
                mre_single_list_add(g_am_ms_cntx.app_list, app_p, -1);
            }
            else
            {
                mmi_am_ms_release_applist_node(app_p);
            }
        }
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_update_app_list
* DESCRIPTION
*  
* PARAMETERS
*  page_start_idx      [IN]        
*  page_end_idx        [IN]        
* RETURNS
*  
*****************************************************************************/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
*  mmi_am_ms_get_appinfo_from_vxplist
* DESCRIPTION
*  
* PARAMETERS
*  vxp_p       [IN]        
* RETURNS
*  
*****************************************************************************/
static mmi_am_ms_app_struct *mmi_am_ms_get_appinfo_from_vxplist(mmi_am_vxp_file_struct *vxp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 ret;
    S32 cache_size = MMI_AM_LOAD_RES_BUF_SIZE;
    S8 *cache_buf = NULL;
    mmi_am_ms_app_struct *app_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate cache buffer */
    cache_buf = mmi_am_calloc(cache_size);
    if (!cache_buf)
    {
        MMI_AM_ASSERT(cache_buf != NULL);
        return NULL;
    }

    app_p = mmi_am_calloc(sizeof(mmi_am_ms_app_struct));
    if (!app_p)
    {
        MMI_AM_ASSERT(app_p != NULL);
        mmi_am_free(cache_buf);
        return NULL;
    }

    /* set app full path */
    mmi_wcscpy(app_p->path, vxp_p->path);

    /* get app icon */
    if (srv_mre_get_app_image(app_p->path, cache_buf, &app_p->icon_size))
    {
        app_p->p_icon = mmi_am_calloc(app_p->icon_size);
        if (app_p->p_icon)
            memcpy(app_p->p_icon, cache_buf, app_p->icon_size);
    }

    /* get app name */
    if (g_am_cntx.has_small_font)   /* support small font */
    {
        if (srv_mre_get_app_name(app_p->path, (U16*) cache_buf, &app_p->name_size))
        {
            app_p->p_name = mmi_am_calloc(app_p->name_size + 2);
            //memcpy(app_p->p_name, cache_buf, app_p->name_size);
            mmi_wcsncpy((WCHAR *)app_p->p_name, (WCHAR *)cache_buf, app_p->name_size >> 1);
        }
        else
        {
            app_p->p_name = (PU8) GetString(STR_ID_AM_APP_NAME_DEFAULT);
            app_p->name_len = mmi_wcslen((PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT));
        }
    }
    else
    {
        if (srv_mre_get_app_zimo_name(app_p->path, (S8*) cache_buf, &app_p->name_size, &app_p->name_len))
        {
            app_p->p_name = mmi_am_calloc(app_p->name_size);
            memcpy(app_p->p_name, cache_buf, app_p->name_size);
        }
        else
        {
            mmi_am_get_zimo_string_data((PU8) AM_App_Default, &app_p->p_name, (PS32) & app_p->name_len);
        }
    }

    /* Whether the application is set to HS shortcut. */
#ifdef MMI_AM_SHORTCUT_ENABLE
    if (mmi_am_is_set_as_shortcut(app_p->path))
    {
        app_p->is_hs_shortcut = MMI_TRUE;
    }
    else
#endif /* MMI_AM_SHORTCUT_ENABLE */ 
    {
        app_p->is_hs_shortcut = MMI_FALSE;
    }

    /* Whether the application is running in the background. */
    if (srv_mre_is_app_bg_running(app_p->path))
    {
        app_p->is_bg_started = MMI_TRUE;
    }
    else
    {
        app_p->is_bg_started = MMI_FALSE;
    }

    /* release cache buffer */
    mmi_am_free(cache_buf);

    return app_p;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_is_app_download
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_ms_is_app_download(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_download = MMI_FALSE;
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                if (g_am_cntx.appstore_list.is_downloaded)  /* AppStore downloaded */
                {
                    is_download = MMI_TRUE;
                }
                else    /* AppStore dont download */
                {
                    is_download = MMI_FALSE;
                }
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    is_download = MMI_TRUE;
                }
                else    /* shortcut app dont download */
                {
                    is_download = MMI_FALSE;
                }
            }
        }
        else    /* dont support AppStore */
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                is_download = MMI_TRUE;
            }
            else    /* shortcut app dont download */
            {
                is_download = MMI_FALSE;
            }
        }
    }
    else
    {
        is_download = MMI_TRUE;
    }

    return is_download;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_is_app_bg_running
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_ms_is_app_bg_running(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_bg_running = MMI_FALSE;
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                if (g_am_cntx.appstore_list.is_downloaded)  /* AppStore downloaded */
                {
                    if (g_am_cntx.appstore_list.is_bg_started)  /* BG running? */
                    {
                        is_bg_running = MMI_TRUE;
                    }
                    else
                    {
                        is_bg_running = MMI_FALSE;
                    }
                }
                else    /* AppStore dont download */
                {
                    is_bg_running = MMI_FALSE;
                }
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    if (g_am_cntx.shortcut_app_list[index].is_bg_started)       /* BG running? */
                    {
                        is_bg_running = MMI_TRUE;
                    }
                    else
                    {
                        is_bg_running = MMI_FALSE;
                    }
                }
                else    /* shortcut app dont download */
                {
                    is_bg_running = MMI_FALSE;
                }
            }
        }
        /* dont support AppStore */
        else
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                if (g_am_cntx.shortcut_app_list[index].is_bg_started)   /* BG running? */
                {
                    is_bg_running = MMI_TRUE;
                }
                else
                {
                    is_bg_running = MMI_FALSE;
                }
            }
            else    /* shortcut app dont download */
            {
                is_bg_running = MMI_FALSE;
            }
        }
    }
    /*************************************************************
    * Rom app
    *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        if (g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_bg_started)     /* BG running? */
        {
            is_bg_running = MMI_TRUE;
        }
        else
        {
            is_bg_running = MMI_FALSE;
        }
    }
    /*************************************************************
    * download app
    *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        // index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,index);
        if (!p)
        {
            is_bg_running = MMI_FALSE;
        }
        else
        {
            if (p->is_bg_started)   /* BG running? */
            {
                is_bg_running = MMI_TRUE;
            }
            else
            {
                is_bg_running = MMI_FALSE;
            }
        }
    }

    return is_bg_running;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_is_rom_app
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_ms_is_rom_app(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx >= g_am_cntx.shortcut_app_num && idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

#ifdef MMI_AM_SHORTCUT_ENABLE


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_is_app_set_hs_shortcut
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_ms_is_app_set_hs_shortcut(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_hs_shortcut = MMI_FALSE;
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                if (g_am_cntx.appstore_list.is_downloaded)  /* AppStore downloaded */
                {
                    if (g_am_cntx.appstore_list.is_hs_shortcut) /* HS shortcut? */
                    {
                        is_hs_shortcut = MMI_TRUE;
                    }
                    else
                    {
                        is_hs_shortcut = MMI_FALSE;
                    }
                }
                else    /* AppStore dont download */
                {
                    is_hs_shortcut = MMI_FALSE;
                }
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    if (g_am_cntx.shortcut_app_list[index].is_hs_shortcut)      /* HS shortcut? */
                    {
                        is_hs_shortcut = MMI_TRUE;
                    }
                    else
                    {
                        is_hs_shortcut = MMI_FALSE;
                    }
                }
                else    /* shortcut app dont download */
                {
                    is_hs_shortcut = MMI_FALSE;
                }
            }
        }
        else    /* dont support AppStore */
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                if (g_am_cntx.shortcut_app_list[index].is_hs_shortcut)  /* HS shortcut? */
                {
                    is_hs_shortcut = MMI_TRUE;
                }
                else
                {
                    is_hs_shortcut = MMI_FALSE;
                }
            }
            else    /* shortcut app dont download */
            {
                is_hs_shortcut = MMI_FALSE;
            }
        }
    }
    /*************************************************************
    * Rom app
    *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        if (g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_hs_shortcut)    /* HS shortcut? */
        {
            is_hs_shortcut = MMI_TRUE;
        }
        else
        {
            is_hs_shortcut = MMI_FALSE;
        }
    }
    /*************************************************************
    * download app
    *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        //index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,index);
        if (p)
        {
            if (p->is_hs_shortcut)  /* HS shortcut? */
            {
                is_hs_shortcut = MMI_TRUE;
            }
            else
            {
                is_hs_shortcut = MMI_FALSE;
            }
        }
    }

    return is_hs_shortcut;
}
#endif /* MMI_AM_SHORTCUT_ENABLE */ 


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_app_path_by_index
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
U16 *mmi_am_ms_get_app_path_by_index(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_am_cntx.is_card_plug_out)    /* When starting app, plug out memory card */
    {
        if ((idx < g_am_ms_cntx.page_start_idx) || (idx > g_am_ms_cntx.page_end_idx))
        {
            return NULL;
        }
    }
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                if (g_am_cntx.appstore_list.is_downloaded)
                {
                    return g_am_cntx.appstore_list.path;
                }
                else
                {
                    return NULL;
                }
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    return g_am_cntx.shortcut_app_list[index].path;
                }
                else    /* shortcut app dont download */
                {
                    return NULL;
                }
            }
        }
        else    /* dont support AppStore */
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                return g_am_cntx.shortcut_app_list[index].path;
            }
            else    /* shortcut app dont download */
            {
                return NULL;
            }
        }
    }
    /*************************************************************
    * Rom app
    *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].path;
    }
    /*************************************************************
    * download app
    *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        // index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        //p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
        p = mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,index);
        if (p==NULL)
        {
            return NULL;
        }

        return p->path;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_app_icon_by_index
* DESCRIPTION
*  
* PARAMETERS
*  idx             [IN]        
*  icon_size       [OUT]       
* RETURNS
*  
*****************************************************************************/
U8 *mmi_am_ms_get_app_icon_by_index(S32 idx, U32 *icon_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((idx < g_am_ms_cntx.page_start_idx) || (idx > g_am_ms_cntx.page_end_idx))
    {
        return NULL;
    }

    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                *icon_size = (U32) gdi_image_get_buf_len((PU8) GetImage(g_am_cntx.appstore_list.icon_id));
                return (PU8) gdi_image_get_buf_ptr((U8*) GetImage(g_am_cntx.appstore_list.icon_id));
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    *icon_size =
                        (U32) gdi_image_get_buf_len((PU8) GetImage(g_am_cntx.shortcut_app_list[index].icon_id));
                    return (PU8) gdi_image_get_buf_ptr((U8*) GetImage(g_am_cntx.shortcut_app_list[index].icon_id));
                }
                else    /* shortcut app dont download */
                {
                    return NULL;
                }
            }
        }
        else    /* dont support AppStore */
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                *icon_size = (U32) gdi_image_get_buf_len((PU8) GetImage(g_am_cntx.shortcut_app_list[index].icon_id));
                return (PU8) gdi_image_get_buf_ptr((U8*) GetImage(g_am_cntx.shortcut_app_list[index].icon_id));
            }
            else    /* shortcut app dont download */
            {
                return NULL;
            }
        }
    }
    /*************************************************************
    * Rom app
    *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        *icon_size = (U32) g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].icon_size;
        return g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].p_icon;
    }
    /*************************************************************
    * download app
    *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            return NULL;
        }

        *icon_size = (U32) p->icon_size;
        return p->p_icon;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_delete_node_from_applist_by_index
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_delete_node_from_applist_by_index(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return;
    }
    else
    {
        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);

        /* delete the node */
        mmi_am_ms_release_applist_node_ex(index);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_set_app_download
* DESCRIPTION
*  
* PARAMETERS
*  idx         [IN]        
*  driver      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_set_app_download(S32 idx, S8 driver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                /* AppStore downloaded */
                g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

                /* Set app path */
                kal_wsprintf(
                    (WCHAR*) g_am_cntx.appstore_list.path,
                    "%c:\\%s\\%s",
                    driver,
                    MMI_AM_MRE_HOME_DIR,
                    MMI_AM_AS_FILE_NAME);
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                /* shortcut app downloaded */
                index--;
                g_am_cntx.shortcut_app_list[index].is_downloaded = MMI_TRUE;

                /* Set app path */
                kal_wsprintf(
                    (WCHAR*) g_am_cntx.shortcut_app_list[index].path,
                    "%c:\\%s\\%s",
                    driver,
                    MMI_AM_MRE_HOME_DIR,
                    mmi_am_config_get_am_sc_name_by_idx(idx));
            }
        }
        else    /* dont support AppStore */
        {
            /* shortcut app downloaded */
            g_am_cntx.shortcut_app_list[index].is_downloaded = MMI_TRUE;

            /* Set app path */
            kal_wsprintf(
                (WCHAR*) g_am_cntx.appstore_list.path,
                "%c:\\%s\\%s",
                driver,
                MMI_AM_MRE_HOME_DIR,
                mmi_am_config_get_am_sc_name_by_idx(index));
        }
    }
    /*************************************************************
    * Rom app or download app
    *************************************************************/
    else
    {
        return;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_set_app_hs_shortcut
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_set_app_hs_shortcut(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                index--;
                g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_TRUE;
            }
        }
        else    /* dont support AppStore */
        {
            g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_TRUE;
        }
    }
    /*************************************************************
    * Rom app
    *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_hs_shortcut = MMI_TRUE;
    }
    /*************************************************************
    * download app
    *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
        if (p)
        {
            p->is_hs_shortcut = MMI_TRUE;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_set_app_bg_running
* DESCRIPTION
*  
* PARAMETERS
*  idx                 [IN]        
*  is_bg_running       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_set_app_bg_running(S32 idx, MMI_BOOL is_bg_running)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (idx < 0)
    {
        return;
    }
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                g_am_cntx.appstore_list.is_bg_started = is_bg_running;
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                index--;
                g_am_cntx.shortcut_app_list[index].is_bg_started = is_bg_running;
            }
        }
        else    /* dont support AppStore */
        {
            g_am_cntx.shortcut_app_list[index].is_bg_started = is_bg_running;
        }
    }
    /*************************************************************
    * Rom app
    *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_bg_started = is_bg_running;
    }
    /*************************************************************
    * download app
    *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
        if (p)
        {
            p->is_bg_started = is_bg_running;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_app_status_update
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_app_status_update(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Whether the application is running in the background. */
    if (srv_mre_is_app_bg_running(mmi_am_ms_get_app_path_by_index(idx)))
    {
        mmi_am_ms_set_app_bg_running(idx, MMI_TRUE);
    }
    else
    {
        mmi_am_ms_set_app_bg_running(idx, MMI_FALSE);
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_remove_app_hs_shortcut
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_remove_app_hs_shortcut(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
            - AppStore
            --------------------------------------------------------------------*/
            if (index == 0)
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_FALSE;
            }
            /*-------------------------------------------------------------------
            - other AM Shortcut app
            --------------------------------------------------------------------*/
            else
            {
                index--;
                g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_FALSE;
            }
        }
        else    /* dont support AppStore */
        {
            g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_FALSE;
        }
    }
    /*************************************************************
    * Rom app
    *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_hs_shortcut = MMI_FALSE;
    }
    /*************************************************************
    * download app
    *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
        if (p)
        {
            p->is_hs_shortcut = MMI_FALSE;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_update_cdr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ms_update_cdr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 state;
    //U32 balance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_cntx.is_prompt_update_cdr = MMI_TRUE;

    state = srv_mre_update_is_sync_cdr();
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_UPDATE_CDR_STATE, state);

    switch (state)
    {
    case MRE_SRV_CDR_NVRAM_NEED_FOR_SYNC_CDR:
    case MRE_SRV_CDR_TIME_NEED_FOR_SYNC_CDR:
        mmi_am_entry_update_cdr_scrn();
        return;

    default:
        return;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_am_ms_update_cdr
* DESCRIPTION
*  After download an application, call this API to update app download status.
* PARAMETERS
*  appid     [IN]      Application download id.
*  app_path     [IN]      Application file path.
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_shortcut_app_download_suc(S32 appid, U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_shortcut_info_struct *sc_info;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL)
    {
        return;
    }

    sc_info = mmi_am_config_get_am_sc_list();
    for (index = 0; index < mmi_am_config_get_am_sc_num(); index++)
    {
        if (sc_info[index].dl_app_id == appid)
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
            {
                /*-------------------------------------------------------------------
                - AppStore
                --------------------------------------------------------------------*/
                if (0 == index) /* AppStore downloaded */
                {
                    g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;
                    mmi_wcsncpy(g_am_cntx.appstore_list.path, app_path, MMI_AM_MAX_SHORTCUT_APP_FILE_PATH);
#ifdef MMI_AM_SHORTCUT_ENABLE
                    if (mmi_am_is_set_as_shortcut(app_path))
                    {
                        g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
                    }
#endif /* MMI_AM_SHORTCUT_ENABLE */ 

                }
                /*-------------------------------------------------------------------
                - other AM Shortcut app
                --------------------------------------------------------------------*/
                else
                {
                    /* shortcut app downloaded */
                    index--;
                    g_am_cntx.shortcut_app_list[index].is_downloaded = MMI_TRUE;
                    mmi_wcsncpy(g_am_cntx.shortcut_app_list[index].path, app_path, MMI_AM_MAX_SHORTCUT_APP_FILE_PATH);
#ifdef MMI_AM_SHORTCUT_ENABLE
                    if (mmi_am_is_set_as_shortcut(app_path))
                    {
                        g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_TRUE;
                    }
#endif /* MMI_AM_SHORTCUT_ENABLE */ 
                }
            }
            else    /* dont support AppStore */
            {
                g_am_cntx.shortcut_app_list[index].is_downloaded = MMI_TRUE;
                mmi_wcsncpy(g_am_cntx.shortcut_app_list[index].path, app_path, MMI_AM_MAX_SHORTCUT_APP_FILE_PATH);
#ifdef MMI_AM_SHORTCUT_ENABLE
                if (mmi_am_is_set_as_shortcut(app_path))
                {
                    g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_TRUE;
                }
#endif /* MMI_AM_SHORTCUT_ENABLE */ 
            }

            /* Update main screen */
            if (mmi_frm_scrn_get_active_id() == SCR_ID_AM_MAIN)
            {
                mmi_am_entry_main_scrn();
            }

            break;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_index_by_app_path
* DESCRIPTION
*  
* PARAMETERS
*  app_path     [IN]        
* RETURNS
*  
*****************************************************************************/
S32 mmi_am_ms_get_index_by_app_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    FS_HANDLE findfirst_hdl;
    FS_DOSDirEntry info;
    U16 app_name_temp[MMI_AM_MAX_APP_FILE_NAME + 1];
    U16 app_file_path[MMI_AM_MAX_APP_FILE_PATH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (!app_path)
    {
        return;
    }

    findfirst_hdl = FS_FindFirst(app_path, 0, FS_ATTR_DIR, &info, app_name_temp, MMI_AM_MAX_APP_FILE_NAME * ENCODE_BYTE);
    if (findfirst_hdl >= 0)
    {
        /* check short file name */
        if (info.NTReserved == FS_SFN_MATCH)
        {
            mmi_chset_mixed_text_to_ucs2_str(
                (PU8) app_file_path,
                MMI_AM_MAX_APP_FILE_PATH * ENCODING_LENGTH,
                (PU8)app_path,
                (mmi_chset_enum) PhnsetGetDefEncodingType());
        }
        else
        {
            mmi_wcsncpy(app_file_path, app_path, MMI_AM_MAX_APP_FILE_PATH);
        }
        FS_FindClose(findfirst_hdl);
        findfirst_hdl = 0;
    }
    /*************************************************************
    * AM Shortcut app
    *************************************************************/
    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
    {
        /*-------------------------------------------------------------------
        - AppStore
        --------------------------------------------------------------------*/
        if (g_am_cntx.appstore_list.path && mmi_wcscmp(app_file_path, g_am_cntx.appstore_list.path) == 0)
        {
            return 0;
        }
        /*-------------------------------------------------------------------
        - other AM Shortcut app
        --------------------------------------------------------------------*/
        else
        {
            for (i = 0; i < g_am_cntx.shortcut_app_num - 1; i++)
            {
                if (g_am_cntx.shortcut_app_list[i].path && mmi_wcscmp(app_file_path, g_am_cntx.shortcut_app_list[i].path) == 0)
                {
                    return i + 1;
                }
            }
        }
    }
    else    /* dont support AppStore */
    {
        for (i = 0; i < g_am_cntx.shortcut_app_num; i++)
        {
            if (g_am_cntx.shortcut_app_list[i].path && mmi_wcscmp(app_file_path, g_am_cntx.shortcut_app_list[i].path) == 0)
            {
                return i;
            }
        }
    }
    /*************************************************************
    * Rom app
    *************************************************************/
    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        if (g_am_cntx.rom_app_list[i].path && mmi_wcscmp(app_file_path, g_am_cntx.rom_app_list[i].path) == 0)
        {
            return i + g_am_cntx.shortcut_app_num;
        }
    }
    /*************************************************************
    * download app
    *************************************************************/
    for (i = 0; i < mre_single_list_get_size(g_am_ms_cntx.app_list); i++)
    {
        mmi_am_ms_app_struct *p;
        p = mre_single_list_get_element(g_am_ms_cntx.app_list, i);
        if (p && p->path && mmi_wcscmp(app_file_path, p->path) == 0)
        {
            return i + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ms_app_status_update_by_path
* DESCRIPTION
*  
* PARAMETERS
*  app_path     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_ms_app_status_update_by_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (!app_path)
    {
        return;
    }
    /* Whether the application is running in the background. */
    if (srv_mre_is_app_bg_running(app_path))
    {
        mmi_am_ms_set_app_bg_running(mmi_am_ms_get_index_by_app_path(app_path), MMI_TRUE);
    }
    else
    {
        mmi_am_ms_set_app_bg_running(mmi_am_ms_get_index_by_app_path(app_path), MMI_FALSE);
    }

}

#endif /* __MRE_AM__ */ 

