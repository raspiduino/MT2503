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
//#ifdef __MRE_AM__

/*****************************************************************************
*
* Filename:
* ---------
*   AMScreens.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   AM Other Screens in addition to Main Screen.
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
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "mmi_features.h"
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
#include "AMSwitch.h"
#include "MMIDataType.h"
#include "CommonScreens.h"
#include "CustMenuRes.h"
#include "Conversions.h"
#include "MenuCuiGprot.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "DebugInitDef_Int.h"
#include "MMI_mre_trc.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalConstants.h"
#include "fs_type.h"
#include "string.h"
#include "PixcomFontEngine.h"
#include "med_struct.h"
#include "stdio.h"
#include "kal_release.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_list.h"
#include "CustDataProts.h"
#include "gui_data_types.h"
#include "MMI_features.h"
#include "wgui_touch_screen.h"
#include "wgui_categories.h"
#include "wgui_categories_popup.h"
#include "MREAppMgrSrvGprot.h"


#include "AMDef.h"      /* Add AM head file */
#include "AMGprot.h"    /* Add AM head file */
#include "AMUtil.h"
#include "AMMainScreen.h"
#include "AMScreens.h"
#include "AMProxy.h"
#include "AMConfig.h"
#include "AMProt.h"
#include "mmi_rp_app_am_def.h"
#if defined (MMI_AM_SHORTCUT_ENABLE)
#include "AMShortcut.h"
#endif
#include "MRESrvGProt.h"
#include "MRESrvDownloadGprot.h"
#include "MRESrvDownload.h"

// lf changed for dla 2010-11-25 -s
#include "AMDLAgent.h"
// lf changed for dla 2010-11-25 -e
// lf added for pm 2011-01-18 -s
#include "mmi_rp_app_am_def.h"
#include "GlobalResDef.h"
#include "CommonScreensResDef.h"
#include "wgui_touch_screen.h"
#include "AlertScreen.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "MMI_mre_trc.h"
#include "mmi_rp_app_am_def.h"
// lf added for pm 2011-01-18 -s

/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
static U8 *g_ds_str_buf;
extern mmi_am_ms_struct g_am_ms_cntx;
extern mmi_am_cntx_struct g_am_cntx;

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* options screen */

#if defined (MMI_AM_SHORTCUT_ENABLE)
static void mmi_am_os_create_hs_shortcut(void);
static void mmi_am_os_delete_hs_shortcut(void);
static void mmi_am_os_delete_hs_shortcut_accept(void);
#endif /* defined (MMI_AM_SHORTCUT_ENABLE) */ 
static void mmi_am_os_app_details(void);
static void mmi_am_os_app_delete(void);
static void mmi_am_os_app_delete_accept(void);
static void mmi_am_os_app_uninstall(void);

/* details screen */
static void mmi_am_entry_details_scrn(void);
static mmi_ret mmi_am_leave_details_scrn(mmi_event_struct *evt);
static void mmi_am_ds_prepare_data(U8 **str_buf, S32 *buf_size);

/* Update MRE CDR */
static void mmi_am_cdr_update_accept(void);
static void mmi_am_entry_update_cdr_wait_scrn(void);
static void mmi_am_exit_update_cdr_wait_scrn(void);
static void mmi_am_cdr_update_cb(S32 nResult);
// lf added for psmgr 2011-01-04 -s
/* process manager */
static void mmi_am_pm_entry(void);
// lf added for psmgr 2011-01-04 -e

/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern U8 PhnsetGetDefEncodingType(void);
extern void mmi_am_update_vxp_list_index(mre_list_t * list);
extern  mmi_am_ms_app_struct *  mmi_am_ms_get_vxp_by_index(const mre_list_t * list,U32 index);


/*****************************************************************************
* FUNCTION
*  mmi_am_entry_option_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_entry_option_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_id = cui_menu_create(
        GRP_ID_AM,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_AM_OPTIONS,
        MMI_FALSE,
        NULL);

    cui_menu_run(cui_menu_id);
}


mmi_ret mmi_am_option_menu_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    // lf added for dla 2010-11-12 -s
    mmi_menu_id  menu_ids[/*5*/6];    
    // lf added for dla 2010-11-12 -e
    S32 index;  /* index in app list */
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    index = g_am_ms_cntx.hl_idx;
    i = 0;

    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            /* build menu list */
#ifdef MRE_DOWNLOAD_SRV
            if ((index < g_am_cntx.shortcut_app_num) && !mmi_am_ms_is_app_download(index) && 
                // lf changed for dla 2010-11-25 -s
                !mmi_am_dla_get_elem_sts(g_am_cntx.dla_h, mmi_am_dla_hl2id(g_am_cntx.dla_h, index)))
                // lf changed for dla 2010-11-25 -e
            {
                menu_ids[i++] = MENU_ID_AM_OPTION_DOWNLOAD;
                // TODO: add settings in MRE4.0
                //if ((mmi_am_get_sim_card_num() == 2) || ((mmi_am_get_sim_card_num() == 1) && mmi_am_is_support_wifi()))
                //{
                //    menu_ids[i++] = MENU_ID_AM_OPTION_SETTINGS;
                //}
            }
            else if (!mmi_am_ms_is_app_download(index) && 
                // lf changed for dla 2010-11-25 -s
                DLA_ELEM_STS_NONE != mmi_am_dla_get_elem_sts(g_am_cntx.dla_h, mmi_am_dla_hl2id(g_am_cntx.dla_h, index)))
            {
                menu_ids[i++] = MENU_ID_DLA_OPTION_MAIN_DETAIL;
            }
            // lf changed for dla 2010-11-25 -e
            else
#endif /* #ifdef MRE_DOWNLOAD_SRV */

            {
                menu_ids[i++] = MENU_ID_AM_OPTION_OPEN;
#if defined MMI_AM_SHORTCUT_ENABLE
                if (mmi_am_is_need_to_set_shortcut(index))
                {
                    if (mmi_am_ms_is_app_set_hs_shortcut(index))
                    {
                        menu_ids[i++] = MENU_ID_AM_OPTION_DELETE_SHORTCUT;
                    }
                    else
                    {
                        menu_ids[i++] = MENU_ID_AM_OPTION_CREATE_SHORTCUT;
                    }
                }                
#endif
                if (index >= (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
                {
                    menu_ids[i++] = MENU_ID_AM_OPTION_UNINSTALL;
                    //menu_ids[i++] = MENU_ID_AM_OPTION_DELETE;
                }         
                menu_ids[i++] = MENU_ID_AM_OPTION_DETAILS;
                // lf changed for bug of pm 2011-02-09 -s
                // lf changed for pm 2011-01-18 -s
                //menu_ids[i++] = MENU_ID_AM_OPTION_PSMGR;
                // lf changed for pm 2011-01-18 -e
                // lf changed for bug of pm 2011-02-09 -e
                // TODO: add settings in MRE4.0
                //if ((mmi_am_get_sim_card_num() == 2) || ((mmi_am_get_sim_card_num() == 1) && mmi_am_is_support_wifi()))
                //{
                //    menu_ids[i++] = MENU_ID_AM_OPTION_SETTINGS;
                //}
            }
            // lf added for dla 2010-11-25 -s
#ifdef MRE_DOWNLOAD_SRV
            menu_ids[i++] = MENU_ID_DLA_OPTION_MAIN_LIST;
#endif
            // lf added for dla 2010-11-25 -e
            // lf changed for pm 2011-01-18 -s
            menu_ids[i++] = MENU_ID_AM_OPTION_PSMGR;
            // lf changed for pm 2011-01-18 -s

            cui_menu_set_currlist(menu_evt->sender_id, i, menu_ids);
            cui_menu_set_default_title_string(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_DOWNLOAD, (WCHAR*)GetString(STR_GLOBAL_DOWNLOAD));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_OPEN, (WCHAR*)GetString(STR_GLOBAL_OPEN));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_CREATE_SHORTCUT, (WCHAR*)GetString(STR_ID_AM_OPTION_CREATE_SHORTCUT));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_DELETE_SHORTCUT, (WCHAR*)GetString(STR_ID_AM_OPTION_DELETE_SHORTCUT));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_UNINSTALL, (WCHAR*)GetString(STR_ID_AM_UNINSTALL));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_DELETE, (WCHAR*)GetString(STR_GLOBAL_DELETE));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_DETAILS, (WCHAR*)GetString(STR_GLOBAL_DETAILS));
            // lf changed for pm 2011-01-18 -s
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_PSMGR, (WCHAR*)GetString(STR_ID_AM_PSMGR_TXT_TITLE));
            // lf changed for pm 2011-01-18 -e
            // TODO: add settings in MRE4.0
            //cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_OPTION_SETTINGS, (WCHAR*)GetString(STR_GLOBAL_SETTINGS));
            // lf changed for dla 2010-11-25 -s
#ifdef MRE_DOWNLOAD_SRV
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_DLA_OPTION_MAIN_DETAIL, (WCHAR*)GetString(STR_ID_AM_DLA_OPTION_DOWNLOAD_STATUS));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_DLA_OPTION_MAIN_LIST, (WCHAR*)GetString(STR_ID_AM_DLA_OPTION_DOWNLOAD_LIST));
#endif
            // lf changed for dla 2010-11-25 -e

            break;
        }
    case EVT_ID_CUI_MENU_ITEM_HILITE:
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        switch (menu_evt->highlighted_menu_id)
        {
        case MENU_ID_AM_OPTION_DOWNLOAD:
            mmi_am_os_download();
            break;
        case MENU_ID_AM_OPTION_OPEN:
            mmi_am_os_app_launch();
            break;
#if defined MMI_AM_SHORTCUT_ENABLE
        case MENU_ID_AM_OPTION_CREATE_SHORTCUT:
            mmi_am_os_create_hs_shortcut();
            break;
        case MENU_ID_AM_OPTION_DELETE_SHORTCUT:
            mmi_am_os_delete_hs_shortcut();
            break;
#endif
        case  MENU_ID_AM_OPTION_UNINSTALL:
            mmi_am_os_app_uninstall();
            break;
        case MENU_ID_AM_OPTION_DELETE:
            mmi_am_os_app_delete();
            break;
        case MENU_ID_AM_OPTION_DETAILS:
            mmi_am_os_app_details();
            break;
        case MENU_ID_AM_OPTION_SETTINGS:
            // TODO: add dataaccount settings in MRE4.0
            break;            
            // lf changed for dla 2010-11-25 -s
#ifdef MRE_DOWNLOAD_SRV
        case MENU_ID_DLA_OPTION_MAIN_DETAIL:
            {
                mmi_am_dla_option_show_status(g_am_cntx.dla_h, 
                    mmi_am_dla_hl2id(g_am_cntx.dla_h, g_am_ms_cntx.hl_idx));
            }break;
        case MENU_ID_DLA_OPTION_MAIN_LIST:
            {
                mmi_am_dla_option_list_entry(g_am_cntx.dla_h);
            }break;
#endif /* #ifdef MRE_DOWNLOAD_SRV */
            // lf changed for dla 2010-11-25 -e
            // lf changed for pm 2011-01-18 -s
        case MENU_ID_AM_OPTION_PSMGR:
            {
                mmi_am_pm_entry();
            }break;
            // lf changed for pm 2011-01-18 -e
        default:
            break;
        }
        break;

    case EVT_ID_CUI_MENU_LIST_EXIT:
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_os_download
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_os_download(void)
{
#ifdef MRE_DOWNLOAD_SRV
    // lf changed for dla 2010-11-25 -s
    if (mmi_am_dla_get_elem_sts(g_am_cntx.dla_h, mmi_am_dla_hl2id(g_am_cntx.dla_h, g_am_ms_cntx.hl_idx)) != DLA_ELEM_STS_NONE)
    {
        mmi_am_dla_option_show_status(g_am_cntx.dla_h, mmi_am_dla_hl2id(g_am_cntx.dla_h, g_am_ms_cntx.hl_idx));
    }
    else
    {
        mmi_am_dla_option_download(g_am_cntx.dla_h, mmi_am_dla_hl2id(g_am_cntx.dla_h, g_am_ms_cntx.hl_idx));
    }
    // lf changed for dla 2010-11-25 -e
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_am_os_app_launch
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_os_app_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U16 *app_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* launch AppStore */
    if ((g_am_ms_cntx.hl_idx == 0) && (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS)))
    {
        app_path = g_am_cntx.appstore_list.path;
        g_am_cntx.is_launch_vas = MMI_TRUE;
    }
    else
    {
        app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);
    }

    if (app_path && app_path[0])
    {
        mmi_am_launch_app_by_path(app_path);
    }
}
/*****************************************************************************
* FUNCTION
*  mmi_am_os_app_uninstall
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_os_app_uninstall(void)
{

    U16 *app_path;
    mmi_am_ms_app_struct *p = NULL;
    mmi_am_ms_app_struct *ptemp = NULL;
    U32 index=0,i=0;

    MMI_BOOL ret = MMI_FALSE;
    mmi_app_package_char app_identification[MMI_APP_NAME_MAX_LEN];
    if(g_am_ms_cntx.hl_idx>= (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        //index = g_am_ms_cntx.hl_idx - ( g_am_ms_cntx.rom_app_num + g_am_ms_cntx.sc_app_num);
        //p = mre_single_list_get_element(g_am_ms_cntx.app_list, index);
        p = (mmi_am_ms_app_struct *)mmi_am_ms_get_vxp_by_index(g_am_ms_cntx.app_list,g_am_ms_cntx.hl_idx);
        if (p)
        {
            if(p->is_bg_started)
                mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE, NULL);
            else
            {
                srv_mre_appmgr_get_package_name_by_unique_id(p->app_unique_id,app_identification);
                ret = srv_mre_appmgr_app_uninstall(app_identification);
                if(ret==MMI_TRUE)
                {
                    /**/
                    if (g_am_ms_cntx.app_list)
                    {
                        index = mre_single_list_get_size(g_am_ms_cntx.app_list);
                        for(i=0;i<index;i++)
                        {
                            ptemp = (mmi_am_ms_app_struct *)mre_single_list_get_element(g_am_ms_cntx.app_list, i);
                            if(ptemp&&(ptemp->idx ==g_am_ms_cntx.hl_idx))
                                break;
                        }
                    }
                    mmi_am_ms_release_applist_node(p);
                    mre_single_list_remove(g_am_ms_cntx.app_list, i);
                    mmi_am_update_vxp_list_index(g_am_ms_cntx.app_list);
                    g_am_cntx.vxp_app_num--;
                    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE),MMI_EVENT_SUCCESS,NULL);
                }
                else
                {
                    mmi_popup_display((WCHAR*)(UI_string_type)GetString(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE, NULL);
                }
            }
        }

    }
}

#if defined (MMI_AM_SHORTCUT_ENABLE)
/*****************************************************************************
* FUNCTION
*  mmi_am_os_create_hs_shortcut
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_os_create_hs_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U16 *app_path;
    U8 *p_icon;
    U32 icon_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);
    p_icon = mmi_am_ms_get_app_icon_by_index(g_am_ms_cntx.hl_idx, &icon_size);

    ret = mmi_am_set_as_shortcut(app_path, p_icon, icon_size);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SCREENS_SET_SHORTCUT, ret);

    switch (ret)
    {
    case MMI_AM_SHORTCUT_SET_SUCCESS:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_SHORTCUT_SET_DONE),
            MMI_EVENT_SUCCESS,
            GRP_ID_AM,
            NULL);
        mmi_am_ms_set_app_hs_shortcut(g_am_ms_cntx.hl_idx);
        break;
    case MMI_AM_SHORTCUT_OVER_NUMBER:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_SHORTCUT_SET_MAX),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    case MMI_AM_SHORTCUT_DUPLICATE_ID:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_SHORTCUT_SET_DUPLICATE),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    case MMI_AM_SHORTCUT_ICON_SIZE_FAIL:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_SHORTCUT_OLD_VER_SET_FAILURE),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    case MMI_AM_SHORTCUT_FILE_NOT_FOUND:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_FILE_NOT_EXIST),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    case MMI_AM_SHORTCUT_CERT_EXPIRED:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_CERT_EXPIRED_FAIL_TO_START),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    case MMI_AM_SHORTCUT_WRONG_DATE:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_DATE_ERR_FAIL_TO_START),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    case MMI_AM_SHORTCUT_IMSI_DISMATCH:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_INVALID_SIM_FAIL_TO_START),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    case MMI_AM_SHORTCUT_WRONG_PLATFORM:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_TAG_ERR_FAIL_TO_START),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    case MMI_AM_SHORTCUT_STRUCTURE_FAIL:
    case MMI_AM_SHORTCUT_FILE_FAIL:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_SHORTCUT_SET_FAILURE),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;
    default:
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_SHORTCUT_SET_FAILURE),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
        break;

    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_os_delete_shortcut_confirm_cb
* DESCRIPTION
*  
* PARAMETERS
*  evt     [IN]        
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_os_delete_shortcut_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_am_os_delete_hs_shortcut_accept();
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_os_delete_hs_shortcut
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_os_delete_hs_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ask user if wish to delete the home screen shortcut settings */
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func) mmi_am_os_delete_shortcut_confirm_cb;
    arg.parent_id = GRP_ID_AM;
    mmi_confirm_display((WCHAR*) (get_string(STR_ID_AM_SHORTCUT_DEL_QUERY)), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_os_delete_hs_shortcut_accept
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_os_delete_hs_shortcut_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *app_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);
    mmi_am_cancel_shortcut(app_path);

    mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_SHORTCUT_DEL_DONE), MMI_EVENT_SUCCESS, GRP_ID_AM, NULL);

    mmi_am_ms_remove_app_hs_shortcut(g_am_ms_cntx.hl_idx);
}
#endif /* defined (MMI_AM_SHORTCUT_ENABLE) */ 


/*****************************************************************************
* FUNCTION
*  mmi_am_os_app_details
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_os_app_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_entry_details_scrn();
}


/*****************************************************************************
* FUNCTION
*  mmi_am_os_app_delete_confirm_cb
* DESCRIPTION
*  
* PARAMETERS
*  evt     [IN]        
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_os_app_delete_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_am_os_app_delete_accept();
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_os_app_delete
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_os_app_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ask user if wish to delete the app */
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func) mmi_am_os_app_delete_confirm_cb;
    arg.parent_id = GRP_ID_AM;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
    mmi_confirm_display((WCHAR*) (get_string(STR_ID_AM_DELETE_APP_QUERY)), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_os_app_delete_accept
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_os_app_delete_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Delete((PU16) mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx));
    if (ret == FS_NO_ERROR)
    {
        mmi_am_ms_delete_node_from_applist_by_index(g_am_ms_cntx.hl_idx);
        mmi_am_delete_node_from_vxplist_by_index(g_am_ms_cntx.hl_idx);
        mmi_popup_display_simple((WCHAR*) get_string(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, GRP_ID_AM, NULL);
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*) get_string(STR_ID_AM_DELETE_APP_FAILURE),
            MMI_EVENT_FAILURE,
            GRP_ID_AM,
            NULL);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_entry_details_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_entry_details_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    S32 buf_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DETAILS_SCRN_ENTRY_S, g_ds_str_buf);

    if (g_ds_str_buf == NULL)
    {
        mmi_am_ds_prepare_data(&g_ds_str_buf, &buf_size);
        if (g_ds_str_buf == NULL)
        {
            return;
        }
    }

    ret = mmi_frm_scrn_enter(
        GRP_ID_AM,
        SCR_ID_AM_DETAILS,
        NULL,
        mmi_am_entry_details_scrn,
        MMI_FRM_FULL_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_DETAILS, mmi_am_leave_details_scrn);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    ShowCategory74Screen(STR_GLOBAL_DETAILS,
        0,
        0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (U8*) g_ds_str_buf, buf_size, gui_buffer);
#else 
    ShowCategory74Screen(STR_GLOBAL_DETAILS,
        IMG_ID_AM_TITLE,
        0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (U8*) g_ds_str_buf, buf_size, gui_buffer);
#endif 

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DETAILS_SCRN_ENTRY_E);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_leave_details_scrn
* DESCRIPTION
*  
* PARAMETERS
*  evt     [IN]        
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_leave_details_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
        break;

    case EVT_ID_SCRN_DEINIT:
        mmi_am_free(g_ds_str_buf);
        g_ds_str_buf = NULL;
        break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_ds_prepare_data
* DESCRIPTION
*  
* PARAMETERS
*  str_buf         [OUT]       
*  buf_size        [OUT]       
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_ds_prepare_data(U8 **str_buf, S32 *buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U16 app_name_temp[MMI_AM_MAX_APP_FILE_NAME];
    U16 app_file_name[MMI_AM_MAX_APP_FILE_NAME];
    U16 *desc_buf = NULL;
    U32 desc_size;
    U32 CRLF_size;
    U16 *app_path = NULL;
    U16 *temp_desc_buf = NULL, *p_desc = NULL, *p_phone = NULL, *p_rank = NULL;
    U32 temp_desc_size = 0;
    U16 *temp_developer_buf = NULL;
    U32 temp_developer_size = 0;
    FS_HANDLE file_hdl;
    S32 file_result;
    U32 file_size = 0;
    U16 file_size_buf_w[10];
    U16 semi[2];
    U16 semi_full[] = {0XFF1A, 0};
    FS_DOSDirEntry info;
    U8 *lang = NULL;
    U16 tel_num[20+1];

    U16* app_name_buf = NULL;
    U32 app_name_size;

#ifdef AM_TEST
    U16 time_buf_w[40];
#endif /* AM_TEST */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(app_name_temp, 0, sizeof(app_name_temp));
    memset(app_file_name, 0, sizeof(app_file_name));
    memset(file_size_buf_w, 0, sizeof(file_size_buf_w));
    memset(semi, 0, sizeof(semi));
    memset(tel_num, 0, sizeof(tel_num));

    lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        mmi_wcscpy(semi, (PU16) MMI_AM_DETAILS_SEMI);
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        mmi_wcscpy(semi, (PU16) semi_full);
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        mmi_wcscpy(semi, (PU16) semi_full);
    }

    CRLF_size = (mmi_ucs2strlen((PS8) semi)
        + mmi_ucs2strlen((PS8) MMI_AM_DETAILS_NEWLINE) + mmi_ucs2strlen((PS8) MMI_AM_DETAILS_SPACES)) << 1;
    app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);
    if(srv_mre_get_app_name(app_path,NULL,&app_name_size))
    {
        app_name_buf = mmi_am_calloc(app_name_size+2);
        ret = srv_mre_get_app_name(app_path,app_name_buf,&app_name_size);
    }
    /* get desc info and phone number by vxp file */
    if (srv_mre_get_app_description(app_path, NULL, &temp_desc_size))
    {
        temp_desc_buf = mmi_am_calloc(temp_desc_size + 2);
        ret = srv_mre_get_app_description(app_path, temp_desc_buf, &temp_desc_size);
    }
    /* Get app size */
    file_hdl = FS_Open(app_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
    if (file_hdl >= FS_NO_ERROR)
    {
        file_result = FS_GetFileSize(file_hdl, &file_size);
        if (file_result != FS_NO_ERROR)
        {
            file_size = 0; 
        }
    }
    FS_Close(file_hdl);
    file_hdl = 0;
    file_size = file_size >> 10;    /* in KB as the unit */
    kal_wsprintf((WCHAR *)file_size_buf_w, "%d k", file_size);
    /* get developer name by vxp file */
    if (srv_mre_get_app_developer(app_path, NULL, &temp_developer_size))
    {
        temp_developer_buf = mmi_am_calloc(temp_developer_size + 2);
        ret = srv_mre_get_app_developer(app_path, temp_developer_buf, &temp_developer_size);
    }

    /* get developer tel by vxp file */
    srv_mre_get_app_tel(app_path, tel_num);

    /* allocate memory using in details screen */
    desc_size =
        (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_APP_NAME)) << 1) + CRLF_size
        + app_name_size+ CRLF_size
        /*#ifdef AM_TEST
        + (mmi_ucs2strlen((PS8) GetString(STR_GLOBAL_DATE)) << 1) + CRLF_size +
        (mmi_ucs2strlen((PS8) time_buf_w) << 1) + CRLF_size
        #endif /* AM_TEST */ 
        + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_INFO)) << 1) + CRLF_size 
        + temp_desc_size + CRLF_size 
        + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_SIZE)) << 1) + CRLF_size 
        + (mmi_ucs2strlen((PS8) file_size_buf_w) << 1) + CRLF_size 
        + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_PATH)) << 1) + CRLF_size 
        + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_STORAGE_MEMORY_CARD)) << 1) + CRLF_size 
        + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_DEVELOPER)) << 1) + CRLF_size 
        + temp_developer_size + CRLF_size
        + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_TEL)) << 1) + CRLF_size
        + (mmi_ucs2strlen((PS8) tel_num) << 1) + CRLF_size;
    desc_buf = (PU16) mmi_am_calloc(desc_size);
    if (!desc_buf)
    {
        mmi_am_free(temp_desc_buf);
        mmi_am_free(temp_developer_buf);
        mmi_am_free(app_name_buf);
        MMI_AM_ASSERT(0);
        return;
    }
    /*1.1*/
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_APP_NAME));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /*1.2*/
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    if (app_name_buf)
    {
        mmi_wcscat(desc_buf, app_name_buf);
    }
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);

    /* 2.1 build string - App Info title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_INFO));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 2.2 build string - App Info content */
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    if (temp_desc_buf)
    {
        mmi_wcscat(desc_buf, temp_desc_buf);
    }    
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);

    /* 3.1 build string - App size title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_SIZE));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 3.2 build string - App size content */
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    mmi_wcscat(desc_buf, file_size_buf_w);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);

    /* 4.1 build string - App store path title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_PATH));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 4.2 build string - App store path content */
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    {
        if ((S8) (*app_path) == (S8) mmi_am_get_system_driver())
        {
            mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_STORAGE_PHONE));
        }
        else if ((S8) (*app_path) == (S8) mmi_am_get_removeable_driver())
        {
            mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_STORAGE_MEMORY_CARD));
        }
        else
        {
            mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_STORAGE_ROM));
        }
    }
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);

    /* 5.1 build string - Developer name title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_DEVELOPER));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 5.2 build string - Developer name content */
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    if (temp_developer_buf)
    {
        mmi_wcscat(desc_buf, temp_developer_buf);
    }
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);

    /* 6.1 build string - Developer tel title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_TEL));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 6.2 build string - Developer tel content */
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    mmi_wcscat(desc_buf, tel_num);
    mmi_wcscat(desc_buf, L"\0");

    /* release the temp memory */
    mmi_am_free(temp_desc_buf);
    mmi_am_free(temp_developer_buf);
    mmi_am_free(app_name_buf);

    /* return buffer pointer and buffer size */
    *str_buf = (PU8) desc_buf;
    *buf_size = (S32) mmi_ucs2strlen((PS8) desc_buf);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_entry_update_cdr_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_entry_update_cdr_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
        GRP_ID_AM, 
        SCR_ID_AM_UPDATE_CDR, 
        NULL, 
        mmi_am_entry_update_cdr_scrn, 
        MMI_FRM_FG_ONLY_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

    ShowCategory165Screen_ext(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        get_string(STR_ID_AM_CDR_NEW_VERSION),
        IMG_GLOBAL_INFO,
        5,
        NULL);

    SetCat165TimerExpireFunc(mmi_am_cdr_update_accept);

    SetLeftSoftkeyFunction(mmi_am_cdr_update_accept, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_am_cdr_update_accept, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_cdr_update_accept
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_cdr_update_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_am_mre_sync_cdr(mmi_am_cdr_update_cb);
    if (ret == 0)//MMI_AM_DL_OK
    {
        mmi_am_entry_update_cdr_wait_scrn();
    }
    else
    {
        mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_CDR_UPDATE_FAIL), MMI_EVENT_FAILURE, GRP_ID_AM, NULL);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_entry_update_cdr_wait_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_entry_update_cdr_wait_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
        GRP_ID_AM, 
        SCR_ID_AM_UPDATE_CDR_WAIT, 
        mmi_am_exit_update_cdr_wait_scrn, 
        mmi_am_entry_update_cdr_wait_scrn, 
        MMI_FRM_FG_ONLY_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

    ShowCategory63Screen((U8*) GetString(STR_GLOBAL_PLEASE_WAIT), IMG_GLOBAL_PROGRESS, NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_exit_update_cdr_wait_scrn
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_exit_update_cdr_wait_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel cdr update */
    srv_mre_update_cancel_sync_cdr();
}


/*****************************************************************************
* FUNCTION
*  mmi_am_cdr_update_cb
* DESCRIPTION
*  
* PARAMETERS
*  nResult     [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_cdr_update_cb(S32 nResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_UPDATE_CDR_CB, nResult);
    if (nResult == 0)
    {
        mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_CDR_UPDATE_SUCC), MMI_EVENT_SUCCESS, GRP_ID_AM, NULL);
    }
    else
    {
        mmi_popup_display_simple((WCHAR*) get_string(STR_ID_AM_CDR_UPDATE_FAIL), MMI_EVENT_FAILURE, GRP_ID_AM, NULL);
    }
}





/***************************************************************************** 
* process manager data
*****************************************************************************/
#include "inlinecuigprot.h"
#include "MRESrvGProt.h"

#define MAX_BG_NUMS 4
#define MAX_OP_NUMS 2

typedef struct _PMNODE PMNODE;
struct _PMNODE
{
    void * data;
    PMNODE* next_p;
};

typedef struct
{
    PMNODE* head_p;
    S32 size;
}PMLIST_CTX;

typedef struct
{
    PMLIST_CTX pmlist_ctx;
    S32 idx_hl;
}mmi_am_psmgr_ctx;

mmi_am_psmgr_ctx sg_am_pm_ctx;

/***************************************************************************** 
*  process manager function
*****************************************************************************/
/* process manager */
static void mmi_am_pm_entry(void);
static void mmi_am_pm_entry_again(void);
static void mmi_am_pm_exit(void);
static mmi_ret mmi_am_pm_list_grp_cb(mmi_event_struct *evt);
static mmi_ret mmi_am_pm_list_option_menu_cb(mmi_event_struct *evt);
//static mmi_ret mmi_am_pm_list_option_launch_confirm_cb(mmi_alert_result_evt_struct *evt);
static mmi_ret mmi_am_pm_list_option_exit_confirm_cb(mmi_alert_result_evt_struct *evt);
static void mmi_am_pm_launch_app_cb(U16 *app_path, srv_mre_launch_app_evt_enum evt);

#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_am_pm_tap_cb(mmi_tap_type_enum tap_type, S32 index);
#endif



static MMI_BOOL pmlist_insert(S32 idx, void * data);
static MMI_BOOL pmlist_delete(S32 idx);
static void pmlist_clear();
static void* pmlist_get_data(S32 idx);

static void mmi_am_pm_popup(UI_string_type str_ptr, mmi_event_notify_enum type);
static pBOOL mmi_am_pm_getitem_cb(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void mmi_am_pm_list_option(void);
static void mmi_am_pm_list_item_hl_cb(S32 index);



/*****************************************************************************
* FUNCTION
*  mmi_am_psmgr_entry
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/

static void mmi_am_pm_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_ID      parent_grp_id;
    MMI_ID      ret_mmi_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    


    parent_grp_id = mmi_frm_group_get_active_id(); 
    parent_grp_id = GRP_ID_ROOT;

    ret_mmi_id = mmi_frm_group_create(
        parent_grp_id, 
        SCR_ID_AM_PSMGR_APP, 
        mmi_am_pm_list_grp_cb,
        NULL);

    if (!ret_mmi_id)  
    {
        mmi_am_pm_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                 
        DS_OUTLOG("[F] mmi_frm_group_create SCR_ID_AM_PSMGR_APP");
        return;
    }

    ret_mmi_id = mmi_frm_group_enter(ret_mmi_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (!ret_mmi_id)  
    {
        mmi_am_pm_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
        DS_OUTLOG("[F] mmi_frm_group_enter SCR_ID_AM_PSMGR_APP");
        return;
    }



    mmi_am_pm_entry_again();
}

static void mmi_am_pm_entry_again(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prcs_num = 0;    
    MMI_BOOL ret_b = MMI_FALSE;
    U8 *guiBuffer = NULL;
    S32 i  = 0;
    U16* pathame_wsz = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_S, 0);
    pmlist_clear();

    prcs_num = srv_mre_get_bg_app_num(); // TODO: get current bg prcs nums.

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 0, prcs_num, 0);
    for (i = 0; i < prcs_num; i++)
    {
        pathame_wsz = mmi_am_malloc(sizeof(U16) * 260);
        ret_b = srv_mre_get_bg_filename(i, pathame_wsz, sizeof(U16) * 260);
        {
            CHAR szTst[128] = {0};
            mmi_wcs_to_asc(szTst, pathame_wsz);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 0, ret_b, 0);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG_STR, 0, szTst);
        }
        pmlist_insert(i, (void*)pathame_wsz);
    }
    /*
    if (0 >= sg_am_pm_ctx.pmlist_ctx.size)
    {
    mmi_am_pm_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    return;
    }
    */
    // test only -s
    /*
    {
    static int j = 0;
    pathame_wsz = mmi_am_malloc(sizeof(U16) * 260);
    kal_wsprintf(pathame_wsz, "%s", "abc");
    pmlist_insert(j++, (void*)pathame_wsz);
    }
    */
    // test only -e
    ret_b = mmi_frm_scrn_enter(SCR_ID_AM_PSMGR_APP, 
        SCR_ID_AM_PSMGR_MAIN, 
        mmi_am_pm_exit, 
        mmi_am_pm_entry_again, 
        MMI_FRM_UNKNOW_SCRN);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if (!ret_b)
    {
        mmi_am_pm_popup((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);                    
        return;
    }

    if (sg_am_pm_ctx.pmlist_ctx.size > 0 && 
        (sg_am_pm_ctx.idx_hl >= sg_am_pm_ctx.pmlist_ctx.size))
    {
        sg_am_pm_ctx.idx_hl = sg_am_pm_ctx.pmlist_ctx.size - 1;
    }

    if (0 < prcs_num)
    {
        ShowCategory284Screen(STR_ID_AM_PSMGR_TXT_TITLE,
            0,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            sg_am_pm_ctx.pmlist_ctx.size,
            mmi_am_pm_getitem_cb,
            NULL,
            sg_am_pm_ctx.idx_hl,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_am_pm_list_option, KEY_EVENT_UP);   
    }
    else
    {
        ShowCategory284Screen(STR_ID_AM_PSMGR_TXT_TITLE,
            0,
            NULL,
            NULL,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            sg_am_pm_ctx.pmlist_ctx.size,
            mmi_am_pm_getitem_cb,
            NULL,
            sg_am_pm_ctx.idx_hl,
            guiBuffer);
    }

    RegisterHighlightHandler(mmi_am_pm_list_item_hl_cb);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);    
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_am_pm_tap_cb);
#endif

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_E, 0);
}
static void mmi_am_pm_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

static mmi_ret mmi_am_pm_list_grp_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 i;
    mmi_ret ret = MMI_RET_OK;
    cui_menu_event_struct *evt_menu = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(evt);

    evt_menu = (cui_menu_event_struct*)evt;

    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_FIRST_ENTRY:
        //ret = mmi_am_grp_first_entry();
        break;

    case EVT_ID_GROUP_ACTIVE:
        //ret = mmi_am_grp_active();
        break;

    case EVT_ID_GROUP_INACTIVE:
        //ret = mmi_am_grp_inactive();
        break;

    case EVT_ID_GROUP_DEINIT:

        //ret = mmi_am_grp_deinit();

        pmlist_clear();
        break;

        /************************* Menu CUI event *****************************/
    case EVT_ID_CUI_MENU_LIST_ENTRY:
    case EVT_ID_CUI_MENU_LIST_EXIT:
    case EVT_ID_CUI_MENU_ITEM_HILITE:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
    case EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE:
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            ret = mmi_am_pm_list_option_menu_cb(evt);
        }
        break;


    }

    return MMI_RET_OK;
}

static mmi_ret mmi_am_pm_list_option_menu_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    cui_event_inline_submit_struct *submit_struct_p = NULL;
    //mmi_confirm_property_struct arg;
    mmi_menu_id  menu_ids[MAX_OP_NUMS] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/




    menu_evt = (cui_menu_event_struct *)evt;

    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            menu_ids[0] = MENU_ID_AM_PSMGR_OPTION_BG_LIST_LAUNCH;
            menu_ids[1] = MENU_ID_AM_PSMGR_OPTION_BG_LIST_EXIT;


            cui_menu_set_currlist(menu_evt->sender_id, MAX_OP_NUMS, menu_ids);
            cui_menu_set_default_title_string(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));

            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_PSMGR_OPTION_BG_LIST_LAUNCH, (WCHAR*)GetString(STR_ID_AM_PSMGR_TXT_OPTION_LAUNCH));
            cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_AM_PSMGR_OPTION_BG_LIST_EXIT, (WCHAR*)GetString(STR_GLOBAL_EXIT));


        }break;
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            submit_struct_p = (cui_event_inline_submit_struct *)evt;
            switch (submit_struct_p->item_id)
            {


            }
        }break;
    case EVT_ID_CUI_MENU_ITEM_HILITE:
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
            case MENU_ID_AM_PSMGR_OPTION_BG_LIST_LAUNCH:
                {
                    /*
                    mmi_confirm_property_struct arg;
                    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
                    arg.callback = (mmi_proc_func) mmi_am_pm_list_option_launch_confirm_cb;
                    arg.parent_id = SCR_ID_AM_PSMGR_APP;
                    mmi_confirm_display((WCHAR*) get_string(STR_GLOBAL_RESUME), MMI_EVENT_QUERY, &arg);
                    */
                    // TODO: launch app
#if 1
                    srv_mre_launch_app_result_enum e;
                    U16 * pathname_wsz = NULL;
                    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_S, 5);
                    pathname_wsz = pmlist_get_data(sg_am_pm_ctx.idx_hl);
                    e = srv_mre_launch_app(pathname_wsz, mmi_am_pm_launch_app_cb);
                    if (SRV_MRE_LAUNCH_APP_SUCCESS != e)
                    {
                        CHAR szTst[128] = {0};
                        mmi_wcs_to_asc(szTst, pathname_wsz);
                        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 5, e, 0);
                        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG_STR, 5, szTst);
                        break;
                    }
                    mmi_am_free(pathname_wsz);
                    pmlist_delete(sg_am_pm_ctx.idx_hl);    
                    mmi_frm_group_close(SCR_ID_AM_PSMGR_APP);
                    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_E, 5);
#endif
                }
                break;
            case MENU_ID_AM_PSMGR_OPTION_BG_LIST_EXIT:
                {
                    mmi_confirm_property_struct arg;
                    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_S, 4);
                    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
                    arg.callback = (mmi_proc_func) mmi_am_pm_list_option_exit_confirm_cb;
                    arg.parent_id = SCR_ID_AM_PSMGR_APP;
                    mmi_confirm_display((WCHAR*) get_string(STR_GLOBAL_EXIT), MMI_EVENT_QUERY, &arg);

                    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_E, 4);

                }
                break;
            default:
                {
                    ASSERT(0);
                }
                break;
            }

            cui_inline_close(menu_evt->sender_id);
        }
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *inline_abort_event = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(inline_abort_event->sender_id);
        }break;

    case EVT_ID_CUI_MENU_LIST_EXIT:
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        break;
    }
    return MMI_RET_OK;
}

/*
static mmi_ret mmi_am_pm_list_option_launch_confirm_cb(mmi_alert_result_evt_struct *evt)
{



if (evt->evt_id == EVT_ID_ALERT_QUIT)
{
switch (evt->result)
{
case MMI_ALERT_CNFM_YES:
{
// TODO: resume the bg app.

pmlist_delete(sg_am_pm_ctx.idx_hl);    
mmi_frm_group_close(SCR_ID_AM_PSMGR_APP);
}
break;
case MMI_ALERT_CNFM_NO:
mmi_frm_scrn_close_active_id();
break;
}
}
return MMI_RET_OK;
}
*/

static mmi_ret mmi_am_pm_list_option_exit_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_S, 3);
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                // TODO: stop the bg app.
                U16 * pathname_wsz = NULL;
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 3, 31, 0);
                pathname_wsz = pmlist_get_data(sg_am_pm_ctx.idx_hl);
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 3, 32, 0);
                srv_mre_close_app(pathname_wsz);
                {
                    CHAR szTst[128] = {0};
                    mmi_wcs_to_asc(szTst, pathname_wsz);
                    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG_STR, 3, szTst);
                }
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 3, 33, 0);
                mmi_am_free(pathname_wsz);
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 3, 34, 0);
                pmlist_delete(sg_am_pm_ctx.idx_hl);
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 3, 35, 0);
                mmi_am_ms_app_status_update_by_path(pathname_wsz);
                //mmi_frm_group_close(SCR_ID_AM_PSMGR_APP);

                //srv_mre_close_app(U16 * app_path);
            }
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_E, 3);
    return MMI_RET_OK;
}

static void mmi_am_pm_launch_app_cb(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt)
    {
    case SRV_MRE_LAUNCH_APP_EVT_SUCCESS:
        //#ifdef __MRE_AM__
        //#include "mmi_features.h"
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
        g_am_cntx.is_launch_app = MMI_TRUE;
#endif
        break;

    default:
        break;
    }	
}

#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_am_pm_tap_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 * pathname_wsz = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    if (ENUM_TAP_ON_HIGHLIGHTED_ITEM == tap_type)
    {
        // lf changed for bug of pm 2011-02-09 -s
        // TODO: launch app
#if 1
        srv_mre_launch_app_result_enum e;
        U16 * pathname_wsz = NULL;
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_S, 2);
        pathname_wsz = pmlist_get_data(sg_am_pm_ctx.idx_hl);
        e = srv_mre_launch_app(pathname_wsz, mmi_am_pm_launch_app_cb);
        if (SRV_MRE_LAUNCH_APP_SUCCESS != e)
        {
            CHAR szTst[128] = {0};
            mmi_wcs_to_asc(szTst, pathname_wsz);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 2, e, 0);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG_STR, 2, szTst);
            return;
        }
        mmi_am_free(pathname_wsz);
        pmlist_delete(sg_am_pm_ctx.idx_hl);    
        mmi_frm_group_close(SCR_ID_AM_PSMGR_APP);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_E, 2);
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        // lf changed for bug of pm 2011-02-09 -e
    }
}

#endif

static pBOOL mmi_am_pm_getitem_cb(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR wszBuf[128] = {0};
    U32 size = 128;
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_S, 1);
    // TODO: list the name of current bg processes.
    ret_b = srv_mre_get_app_name((U16 *)pmlist_get_data(item_index), wszBuf, &size);
    {
        CHAR szTst[128] = {0};
        mmi_wcs_to_asc(szTst, wszBuf);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG, 1, ret_b, 0);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_LOG_STR, 1, szTst);
    }
    //kal_wstrcpy(wszBuf, wszBuf);
    mmi_ucs2ncpy(
        (S8*) str_buff,
        (S8*) wszBuf, /* GetString((U16) (STR_GLOBAL_0 + item_index)), */
        128);

    *img_buff_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PM_E, 1);
    return TRUE;
}

static void mmi_am_pm_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id = 0;
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = MENU_ID_AM_PSMGR_OPTION_BG_LIST;
    cui_gid = cui_menu_create(SCR_ID_AM_PSMGR_APP,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        menu_id,
        MMI_FALSE, 
        NULL);	                            
    cui_menu_set_default_title(cui_gid,
        (UI_string_type)GetString(STR_GLOBAL_OPTIONS),
        NULL//(UI_image_type)get_image(GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID))
        );
    cui_menu_run(cui_gid);
}

static void mmi_am_pm_list_item_hl_cb(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    sg_am_pm_ctx.idx_hl = index;
}


static void mmi_am_pm_popup(UI_string_type str_ptr, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_gid;
    mmi_popup_property_struct arg;   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_gid = mmi_frm_group_get_active_id();


    mmi_popup_property_init(&arg);              
    arg.callback = NULL;       
    arg.user_tag = NULL;          
    arg.parent_id = parent_gid; 
    arg.rotation = MMI_FRM_SCREEN_ROTATE_270;
    mmi_popup_display(                          
        str_ptr,                                
        type,                                   
        &arg);  

}

static MMI_BOOL pmlist_insert(S32 idx, void * data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PMNODE* tmp = NULL;
    PMNODE* tmp1 = NULL;
    S32 i = idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sg_am_pm_ctx.pmlist_ctx.size >= 0);
    ASSERT(sg_am_pm_ctx.pmlist_ctx.size >= idx && 0 <= idx);

    // first node
    if (0 == sg_am_pm_ctx.pmlist_ctx.size)
    {
        sg_am_pm_ctx.pmlist_ctx.head_p = mmi_am_malloc(sizeof(PMNODE));
        if (NULL == sg_am_pm_ctx.pmlist_ctx.head_p)
        {
            return MMI_FALSE;
        }
        sg_am_pm_ctx.pmlist_ctx.head_p->data = data;
        sg_am_pm_ctx.pmlist_ctx.head_p->next_p = NULL;
        sg_am_pm_ctx.pmlist_ctx.size = 1;
    }
    else
    {


        if (0 == idx)
        {
            tmp = mmi_am_malloc(sizeof(PMNODE));
            if (NULL == sg_am_pm_ctx.pmlist_ctx.head_p)
            {
                return MMI_FALSE;
            }
            tmp->data = data;
            tmp->next_p = sg_am_pm_ctx.pmlist_ctx.head_p;
            sg_am_pm_ctx.pmlist_ctx.head_p = tmp;
        }
        else
        {
            tmp = sg_am_pm_ctx.pmlist_ctx.head_p;
            while (tmp)
            {
                if (0 == --i)
                {
                    tmp1 = tmp->next_p;
                    tmp->next_p = mmi_am_malloc(sizeof(PMNODE));
                    if (NULL == sg_am_pm_ctx.pmlist_ctx.head_p)
                    {
                        return MMI_FALSE;
                    }
                    tmp->next_p->data = data;
                    tmp->next_p->next_p = tmp1;
                    break;
                }
                tmp = tmp->next_p;
            }
        }

        ++sg_am_pm_ctx.pmlist_ctx.size;
    }

    return MMI_TRUE;
}

static MMI_BOOL pmlist_delete(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PMNODE* tmp = NULL;
    PMNODE* tmp1 = NULL;
    S32 i = idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(sg_am_pm_ctx.pmlist_ctx.size >= 0 && idx < sg_am_pm_ctx.pmlist_ctx.size && 0 <= idx);

    if (0 == idx)
    {
        tmp = sg_am_pm_ctx.pmlist_ctx.head_p->next_p;
        mmi_am_free(sg_am_pm_ctx.pmlist_ctx.head_p);
        sg_am_pm_ctx.pmlist_ctx.head_p = tmp;
    }
    else
    {
        tmp = sg_am_pm_ctx.pmlist_ctx.head_p;
        while (tmp)
        {
            if (0 == --i)
            {
                tmp1 = tmp->next_p;
                tmp->next_p = tmp1->next_p;
                mmi_am_free(tmp1);
                break;
            }
            tmp = tmp->next_p;
        }
    }

    --sg_am_pm_ctx.pmlist_ctx.size;

    return MMI_TRUE;
}

static void pmlist_clear()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PMNODE* tmp = sg_am_pm_ctx.pmlist_ctx.head_p;
    PMNODE* tmp1 = NULL;
    S32 i = sg_am_pm_ctx.pmlist_ctx.size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    while (tmp)
    {
        tmp1 = tmp;
        tmp = tmp->next_p;
        if (tmp1->data)
            mmi_am_free(tmp1->data);
        mmi_am_free(tmp1);
    }
    sg_am_pm_ctx.pmlist_ctx.head_p = NULL;
    sg_am_pm_ctx.pmlist_ctx.size = 0;
}

static void* pmlist_get_data(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PMNODE* tmp = sg_am_pm_ctx.pmlist_ctx.head_p;
    S32 i = idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    ASSERT(0 <= idx && idx < sg_am_pm_ctx.pmlist_ctx.size);

    while (i--)
    {
        tmp = tmp->next_p;
    }

    return tmp->data;
}




#endif /* __MRE_AM__ */ 

