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
*   AMApp.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   AM App Src
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
#include "mmi_features.h"


//#ifdef __MRE_AM__
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "AMSwitch.h"
#ifdef AM_APP_MANAGEMENT_SUPPORT
#include "MMIDataType.h"
//#include "USBDeviceGprot.h"             /* mmi_usb_is_in_mass_storage_mode */
#include "USBSrvGProt.h"
#include "FileMgrSrvGProt.h"
#include "MenuCuiGprot.h"
#include "fs_type.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "MMI_mre_trc.h"
#include "stack_config.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "stdio.h"
#include "fs_func.h"
#include "gui.h"
#include "fs_errcode.h"
#include "gdi_include.h"
#include "wgui_categories_multimedia.h"
#include "gdi_const.h"
#include "med_struct.h"
#include "vmopt.h"
#include "MRESrvGProt.h"
#include "MREAppMgrSrvGprot.h"
#include "Conversions.h"

#include "AMConfig.h"
#include "AMDef.h"      /* Add AM head file */
#include "AMGprot.h"    /* Add AM head file */
#include "AMMainScreen.h"
#include "AMUtil.h"
#include "AMScreens.h"
#include "MRESrvDownloadGprot.h"
#include "AMProxy.h"
#include "mmi_rp_app_am_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "liblist.h"
#if defined (MMI_AM_SHORTCUT_ENABLE)
#include "AMShortcut.h"
#endif
/* lf added for dla 2010-11-25 -s */
#include "AMDLAgent.h"
/* lf added for dla 2010-11-25 -e */

/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
mmi_am_cntx_struct g_am_cntx;
//mmi_am_async_search_struct g_am_search_cntx;
extern mmi_am_ms_struct g_am_ms_cntx;
extern const U8 AM_App_Default[];
static U32 mmi_am_enter_am_flag;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static MMI_BOOL mmi_am_start_int(void);
static mmi_ret mmi_am_grp_proc(mmi_event_struct *evt);
static mmi_ret mmi_am_grp_active(void);
static mmi_ret mmi_am_grp_deinit(void);
static MMI_BOOL mmi_am_pre_start_check(void);
static void mmi_am_mre_cb(srv_mre_load_core_evt_enum evt);
static void mmi_am_close_group_by_too_many_files(void);
static void mmi_am_cntx_init(void);

#ifndef MMI_AM_USING_MRE_MEM
static void mmi_am_asm_stop_cb(void);
static void mmi_am_alloc_mem_cb(void);
static MMI_BOOL mmi_am_is_asm_enough(void);
#endif /* MMI_AM_USING_MRE_MEM */ 

static void mmi_am_app_init(void);
static void mmi_am_hold_mre_folder(void);

/* search vxp files */
static void mmi_am_search(void);
static void mmi_am_search_shortcut_apps(void);
static void mmi_am_search_appstore(void);
static void mmi_am_search_appstore_in_rom(void);
static MMI_BOOL mmi_am_search_rom_apps(void);
//static MMI_BOOL mmi_am_search_vxp_files(void);
//static void mmi_am_search_vxp_cb(void);
//static MMI_BOOL mmi_am_add_vxp_file_list(U16 *app_name, FS_DOSDateTime date_time);
static S32 mmi_am_binary_search(FS_DOSDateTime *modify_time);
static S32 mmi_am_search_same_time_pos(FS_DOSDateTime *modify_time, S32 pos);
static S32 mmi_am_compare_time(FS_DOSDateTime *time1, FS_DOSDateTime *time2);
static MMI_BOOL mmi_am_check_downloaded_app_by_as(void);

/* release operation */
static void mmi_am_release_shortcut_list_all_nodes(void);
static void mmi_am_release_shortcut_list(void);
static void mmi_am_release_rom_list(void);
static void mmi_am_release_vxp_list_all_nodes(void);
static void mmi_am_release_vxp_list(void);

static void mmi_am_delete_node_from_vxplist_by_path(U16 *app_path);
static MMI_BOOL mmi_am_is_too_many_app_install(void);
static void mmi_am_entry_loading_scrn(void);
void mmi_am_entry_loading_scrn_status_icon_bar_hide_callback(void);
extern void mmi_am_ms_release_applist_node(mmi_am_ms_app_struct *p_node);

static void mmi_am_enter_am(void);
static mmi_am_ms_app_struct * mmi_am_ms_get_appinfo_from_installed_info(mmi_app_package_char *app_name, srv_mre_appmgr_installed_info_struct *info,U32 app_unique_id);
static MMI_BOOL mmi_am_build_installed_app_list(void);

/***************************************************************************** 
* Extern Function
*****************************************************************************/
#ifdef __MMI_MRE_WORLD_CLOCK__
extern void mmi_wc_set_wc_enter_flag(MMI_BOOL flag);
#endif 
extern void vm_vam_unload_core_by_asm(void);
extern U32 vm_vam_get_core_asm_size(void);


/*****************************************************************************
* FUNCTION
*  mmi_am_start
* DESCRIPTION
*  AM entry point function.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_START_S, g_am_cntx.dyn_mem_pool, g_am_cntx.adm_pool_id);

    if (mmi_frm_group_is_present(GRP_ID_AM))
    {
        mmi_frm_group_close(GRP_ID_AM);
    }

    /* Check before AM start */
    if (!mmi_am_pre_start_check())
    {
        return;
    }

    /* enter screen group */
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AM, mmi_am_grp_proc, NULL);
    mmi_frm_group_enter(GRP_ID_AM, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);

    /* AM init */
    if (!mmi_am_start_int())
    {
        mmi_frm_group_close(GRP_ID_AM);
    }
    else
    {
        /* enter loading screen */
        mmi_am_entry_loading_scrn();
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_START_E, g_am_cntx.dyn_mem_pool, g_am_cntx.adm_pool_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_start_int
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmi_am_start_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_load_core_result_enum load_mre_core_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_START_INT_S);

#ifndef MMI_AM_USING_MRE_MEM
    if (!mmi_am_is_asm_enough())
    {
        return MMI_FALSE;
    }
#endif /* MMI_AM_USING_MRE_MEM */ 

    /* AM context init */
    mmi_am_cntx_init();

    /* MRE Core init */
    load_mre_core_ret = srv_mre_load_core(mmi_am_mre_cb, SRV_MRE_CALLER_AM);
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MRE_LOAD_RESULT, load_mre_core_ret);
    if (load_mre_core_ret == SRV_MRE_LOAD_CORE_ASYN_ALLOC_ASM)  /* MRE Core failed to initialize */
    {
        g_am_cntx.is_alloc_asm_fail = MMI_TRUE;
        return MMI_FALSE;
    }
    else if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)    /* MRE failed to initialize */
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_AM_MRE_INIT_FAILURE), MMI_EVENT_FAILURE, NULL);
        return MMI_FALSE;
    }

    if (load_mre_core_ret == SRV_MRE_LOAD_CORE_SUCCESS)
    {
#ifndef MMI_AM_USING_MRE_MEM
        /* application registeration & stop callback */
        applib_mem_ap_register(APPLIB_MEM_AP_ID_AM, MAIN_MENU_MRE_TEXT, IMG_ID_AM_TITLE, mmi_am_asm_stop_cb);

        /* allocate memory */
        if (g_am_cntx.dyn_mem_pool == NULL)
        {
#ifdef WIN32
            g_am_cntx.dyn_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AM, MMI_AM_MAX_DYN_MEM_SIZE);
#else 
            g_am_cntx.dyn_mem_pool = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_AM, MMI_AM_MAX_DYN_MEM_SIZE);
#endif 
            if (g_am_cntx.dyn_mem_pool == NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ALLOCATE_MEM_FAIL);

                /* register callback */
                mmi_frm_appmem_prompt_to_release_mem(
                    APPLIB_MEM_AP_ID_AM,
                    0,
                    MMI_AM_MAX_DYN_MEM_SIZE,
                    mmi_am_alloc_mem_cb);

                /* Unload MRE Core */
                //srv_mre_unload_core(SRV_MRE_CALLER_AM);

                return MMI_FALSE;
            }
        }
#else /* MMI_AM_USING_MRE_MEM */ 
        /* allocate memory */
        if (g_am_cntx.dyn_mem_pool == NULL)
        {
            g_am_cntx.dyn_mem_pool = mmi_am_mre_malloc(MMI_AM_MAX_DYN_MEM_SIZE);
            MMI_AM_ASSERT(g_am_cntx.dyn_mem_pool != NULL);
        }
#endif /* MMI_AM_USING_MRE_MEM */ 

        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_DYN_MEM_POOL, g_am_cntx.dyn_mem_pool);
        memset(g_am_cntx.dyn_mem_pool, 0, MMI_AM_MAX_DYN_MEM_SIZE);
    }

    mmi_am_app_init();

    /* Notify MRE Core */
    mmi_am_mre_set_am_state(MMI_AM_IN_USE);

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_START_INT_E);

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_pre_start_check
* DESCRIPTION
*  Pre check
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmi_am_pre_start_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PRE_START_CHECK_S);

    if (mmi_am_is_too_many_app_install())
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_AM_FILE_OVERFLOW), MMI_EVENT_FAILURE, NULL);
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PRE_START_CHECK_E1);
        return MMI_FALSE;
    }

#ifdef __MMI_USB_SUPPORT__
    /* is in storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, can't use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PRE_START_CHECK_E2);
        return MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PRE_START_CHECK_E3);
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_mre_cb
* DESCRIPTION
*  MRE Core load callback function.
* PARAMETERS
*  evt     [IN]        Event id.
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_mre_cb(srv_mre_load_core_evt_enum evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MRE_CB_S, evt, g_am_cntx.dyn_mem_pool);

    switch (evt)
    {
    case SRV_MRE_LOAD_CORE_EVT_SUCCESS:
        mmi_am_start();
        break;

    case SRV_MRE_LOAD_CORE_EVT_INTERNAL_ERROR:
        break;

    case SRV_MRE_LOAD_CORE_EVT_QUIT:
        if (g_am_cntx.dyn_mem_pool)
        {
            mmi_frm_group_close(GRP_ID_AM);
        }
        break;

    default:
        break;
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_MRE_CB_E);
}

#ifndef MMI_AM_USING_MRE_MEM


/*****************************************************************************
* FUNCTION
*  mmi_am_alloc_mem_cb
* DESCRIPTION
*  AM ASM success callback.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_alloc_mem_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ALLOC_MEM_CB_S, g_am_cntx.dyn_mem_pool);

    mmi_am_start();

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ALLOC_MEM_CB_E, g_am_cntx.dyn_mem_pool);
}
#endif /* MMI_AM_USING_MRE_MEM */ 


/*****************************************************************************
* FUNCTION
*  mmi_am_grp_proc
* DESCRIPTION
*  
* PARAMETERS
*  evt     [IN]        
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_GROUP_PROC_EVT_S, evt->evt_id);

    if ((evt->evt_id == EVT_ID_GROUP_ACTIVE) &&
        mmi_frm_scrn_get_count(GRP_ID_AM) == 0 && mmi_frm_is_in_backward_scenario())
    {
        mmi_frm_group_close(GRP_ID_AM);
        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_FOCUSED:
        ret = mmi_am_grp_active();
        break;
    case EVT_ID_GROUP_DEINIT:
        ret = mmi_am_grp_deinit();
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
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

            ret = mmi_am_option_menu_handler(evt);
        }
        break;
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_GROUP_PROC_EVT_E);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_cntx_init
* DESCRIPTION
*  AM context initialize.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init context struct */
    memset(&g_am_cntx, 0, sizeof(g_am_cntx));

    /* initialize am_search context */
    //g_am_search_cntx.search_hdl = -1;
    //g_am_search_cntx.search_state = SEARCH_NONE;
    //g_am_search_cntx.cur_driver = mmi_am_get_home_driver();

    /* initialize mre folder file handle */
    g_am_cntx.card_mre_folder_hdl = -1;
    g_am_cntx.phone_mre_folder_hdl = -1;
}

#ifndef MMI_AM_USING_MRE_MEM


/*****************************************************************************
* FUNCTION
*  mmi_am_asm_stop_cb
* DESCRIPTION
*  ASM stop callback function.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_asm_stop_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ASM_STOP_CB_S);

    mmi_frm_group_close(GRP_ID_AM);
    vm_vam_unload_core_by_asm();
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_AM, KAL_TRUE);

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ASM_STOP_CB_E);
}
#endif /* MMI_AM_USING_MRE_MEM */ 


/*****************************************************************************
* FUNCTION
*  mmi_am_app_init
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 applib_mem_pool_chunk_size[13] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 5120, 0xffffffff, 0};   /* for KAL ADM */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_APP_INIT_S, g_am_cntx.dyn_mem_pool);

    /* Create ADM */
    if (g_am_cntx.dyn_mem_pool != NULL)
    {
        g_am_cntx.adm_pool_id = kal_adm_create(
            (void*)g_am_cntx.dyn_mem_pool,
            MMI_AM_MAX_DYN_MEM_SIZE,
            applib_mem_pool_chunk_size,
            KAL_TRUE);
        MMI_AM_ASSERT(g_am_cntx.adm_pool_id != NULL);
    }

    /* lf added for dla 2010-11-25 -s */
#ifdef MRE_DOWNLOAD_SRV
    g_am_cntx.dla_h = mmi_am_dla_init();
    if (NULL == g_am_cntx.dla_h)
    {
        // TODO:
        ASSERT(0);
        return;
    }
#endif
    /* lf added for dla 2010-11-25 -e */

    /* allocate AM Shortcut App list memory */
    /*g_am_cntx.shortcut_app_num = mmi_am_config_get_am_sc_num();
    if (g_am_cntx.shortcut_app_num != 0
    && !(mmi_am_config_get_am_sc_info_by_appid(APPID_VAS) && g_am_cntx.shortcut_app_num == 1))
    {
    S32 sc_num;

    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
    sc_num = g_am_cntx.shortcut_app_num - 1;
    }
    else
    {
    sc_num = g_am_cntx.shortcut_app_num;
    }
    g_am_cntx.shortcut_app_list =
    (mmi_am_shortcut_app_struct*) mmi_am_calloc(sc_num * sizeof(mmi_am_shortcut_app_struct));
    if (!g_am_cntx.shortcut_app_list)
    {
    MMI_AM_ASSERT(g_am_cntx.shortcut_app_list != NULL);
    return;
    }
    }*/

    /* allocate Rom App list memory */
    g_am_cntx.vxp_app_num = 0;
    srv_mre_get_buildin_app_list(NULL, &g_am_cntx.rom_app_num);
    if (g_am_cntx.rom_app_num)
    {
        g_am_cntx.rom_app_list =
            (mmi_am_rom_app_struct*) mmi_am_calloc(g_am_cntx.rom_app_num * sizeof(mmi_am_rom_app_struct));
        if (!g_am_cntx.rom_app_list)
        {
            MMI_AM_ASSERT(g_am_cntx.rom_app_list != NULL);
            return;
        }
    }

    /* new list */
    // g_am_cntx.vxp_file_list = mre_single_list_new();

    /* check whether the system have small fonts */
    if (mmi_am_get_font_height() == MMI_AM_APP_NAME_H)
    {
        g_am_cntx.has_small_font = MMI_TRUE;
    }
    else
    {
        g_am_cntx.has_small_font = MMI_TRUE;
    }

    /* delete download_list.dat which created by AS */
    {
        S32 file_drv;
        U16 dl_app_list_path_w[30];

        memset(dl_app_list_path_w, 0, sizeof(dl_app_list_path_w));

        /* memory card */
        file_drv = mmi_am_get_removeable_driver();
        if (file_drv != 0)
        {
            kal_wsprintf(
                (WCHAR*) dl_app_list_path_w,
                "%c:\\%s\\%s",
                file_drv,
                MMI_AM_MRE_HOME_DIR,
                MMI_AM_DOWNLOAD_LIST);
            FS_Delete(dl_app_list_path_w);

            memset(dl_app_list_path_w, 0, sizeof(dl_app_list_path_w));
        }

        /* system driver */
        file_drv = mmi_am_get_system_driver();
        if (file_drv != 0)
        {
            kal_wsprintf(
                (WCHAR*) dl_app_list_path_w,
                "%c:\\%s\\%s",
                file_drv,
                MMI_AM_MRE_HOME_DIR,
                MMI_AM_DOWNLOAD_LIST);
            FS_Delete(dl_app_list_path_w);
        }
    }

    /* hold mre folder handle */
    mmi_am_hold_mre_folder();

#ifdef __MMI_MRE_WORLD_CLOCK__
    /* set worldclock start flag to false */
    mmi_wc_set_wc_enter_flag(MMI_FALSE);
#endif /* __MMI_MRE_WORLD_CLOCK__ */ 

    MMI_TRACE(
        MMI_MRE_TRC_G1_AM,
        TRC_MMI_AM_APP_INIT_E,
        g_am_cntx.adm_pool_id,
        g_am_cntx.shortcut_app_num,
        g_am_cntx.rom_app_num,
        g_am_cntx.has_small_font);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_search
* DESCRIPTION
*  Search applications, include shortcut app/rom app/vxp files.
* PARAMETERS
*  void
* RETURNS
*  void
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
#endif

/*****************************************************************************
* FUNCTION
*  mmi_am_grp_deinit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_grp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MRE_TRC_G1_AM,
        TRC_MMI_AM_DEINIT_S,
        g_am_cntx.card_mre_folder_hdl,
        g_am_cntx.phone_mre_folder_hdl,
        g_am_cntx.adm_pool_id,
        g_am_cntx.dyn_mem_pool);

    /* cancel vxp files search timer */
    //gui_cancel_timer(mmi_am_search_vxp_cb);

    /* cancel cdr update */
    srv_mre_update_cancel_sync_cdr();

    /* close vxp search file handle */
    //  if (g_am_search_cntx.search_hdl >= 0)
    //{
    //    FS_FindClose(g_am_search_cntx.search_hdl);
    //     g_am_search_cntx.search_hdl = -1;
    //}

    /* close mre folder file handle */
    if (g_am_cntx.card_mre_folder_hdl >= 0)
    {
        FS_Close(g_am_cntx.card_mre_folder_hdl);
        g_am_cntx.card_mre_folder_hdl = -1;
    }

    if (g_am_cntx.phone_mre_folder_hdl >= 0)
    {
        FS_Close(g_am_cntx.phone_mre_folder_hdl);
        g_am_cntx.phone_mre_folder_hdl = -1;
    }

    /* release lists */
    mmi_am_release_shortcut_list();
    mmi_am_release_rom_list();
    mmi_am_release_vxp_list();
    mmi_am_ms_release_app_list();

    /* lf added for dla 2010-11-25 -s */
#ifdef MRE_DOWNLOAD_SRV
    if (g_am_cntx.dla_h)
        mmi_am_dla_exit(g_am_cntx.dla_h);
#endif
    /* lf added for dla 2010-11-25 -e */

    /* Delete ADM */
    if (g_am_cntx.adm_pool_id)
    {
        ret = kal_adm_delete(g_am_cntx.adm_pool_id);

        MMI_AM_ASSERT(ret == KAL_SUCCESS);
        g_am_cntx.adm_pool_id = NULL;
    }

    /* release dynamic memory */
    if (g_am_cntx.dyn_mem_pool != NULL)
    {
#ifndef MMI_AM_USING_MRE_MEM
        applib_mem_ap_free(g_am_cntx.dyn_mem_pool);
#else 
        mmi_am_mre_free(g_am_cntx.dyn_mem_pool);
#endif 
        g_am_cntx.dyn_mem_pool = NULL;
    }

    /* Notify MRE Core */
    mmi_am_mre_set_am_state(MMI_AM_OUT_OF_USE);

    /* Unload MRE Core */
    //srv_mre_unload_core(SRV_MRE_CALLER_AM);

    /* deinit AM context */
    mmi_am_cntx_init();
    mmi_am_enter_am_flag = 0;

    MMI_TRACE(
        MMI_MRE_TRC_G1_AM,
        TRC_MMI_AM_DEINIT_E,
        //g_am_search_cntx.search_hdl,
        g_am_cntx.card_mre_folder_hdl,
        g_am_cntx.phone_mre_folder_hdl,
        g_am_cntx.adm_pool_id,
        g_am_cntx.dyn_mem_pool);
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_grp_active
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static mmi_ret mmi_am_grp_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.adm_pool_id && g_am_cntx.is_launch_app)
    {
        /* update app status */
        //if (!g_am_cntx.is_app_in_card)
        {
            mmi_am_ms_app_status_update(g_am_ms_cntx.hl_idx);
        }
        g_am_cntx.is_app_in_card = MMI_FALSE;

        /* check if there are downloaded apps from AS */
        if (g_am_cntx.is_launch_vas)
        {
            g_am_cntx.is_launch_vas = MMI_FALSE;
            if (mmi_am_check_downloaded_app_by_as())
            {
                /* Search shortcut apps */
                mmi_am_search_shortcut_apps();

                /* release all nodes in app_list */
                mmi_am_ms_release_app_list_all_nodes();
            }
        }
        g_am_cntx.is_launch_app = MMI_FALSE;
    }
    mmi_am_enter_am_flag = 1;
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_release_shortcut_list_all_nodes
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_release_shortcut_list_all_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
        if (g_am_cntx.appstore_list.p_name != NULL)
        {
            mmi_am_free(g_am_cntx.appstore_list.p_name);
            g_am_cntx.appstore_list.p_name = NULL;
        }

        max = g_am_cntx.shortcut_app_num - 1;
    }
    else
    {
        max = g_am_cntx.shortcut_app_num;
    }

    /* release every member */
    for (i = 0; i < max; i++)
    {
        if (g_am_cntx.shortcut_app_list[i].p_name != NULL)
        {
            /* 1. release app name */
            mmi_am_free(g_am_cntx.shortcut_app_list[i].p_name);
            g_am_cntx.shortcut_app_list[i].p_name = NULL;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_release_shortcut_list_nodes_in_memory_card
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_release_shortcut_list_nodes_in_memory_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
        if (((S8) (*g_am_cntx.appstore_list.path) != (S8) mmi_am_get_system_driver()) &&
            ((S8) (*g_am_cntx.appstore_list.path) != (S8) MMI_AM_ROM_DIR))
        {
            //if (g_am_cntx.appstore_list.p_name != NULL)
            //{
            //    mmi_am_free(g_am_cntx.appstore_list.p_name);
            //    g_am_cntx.appstore_list.p_name = NULL;
            //}
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_RELEASE_APPSTORE);

            g_am_cntx.appstore_list.is_downloaded = MMI_FALSE;
            g_am_cntx.appstore_list.is_hs_shortcut = MMI_FALSE;
            g_am_cntx.appstore_list.is_bg_started = MMI_FALSE;
        }

        max = g_am_cntx.shortcut_app_num - 1;
    }
    else
    {
        max = g_am_cntx.shortcut_app_num;
    }

    /* release app name buffer */
    for (i = 0; i < max; i++)
    {
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_RELEASE_SHORTCUT_PATH, i, (S8) (*g_am_cntx.shortcut_app_list[i].path));
        if (((S8) (*g_am_cntx.shortcut_app_list[i].path) != (S8) mmi_am_get_system_driver()) &&
            ((S8) (*g_am_cntx.shortcut_app_list[i].path) != (S8) MMI_AM_ROM_DIR))
        {
            //if (g_am_cntx.shortcut_app_list[i].p_name != NULL)
            //{
            //  /* 1. release app name */
            //    mmi_am_free(g_am_cntx.shortcut_app_list[i].p_name);
            //    g_am_cntx.shortcut_app_list[i].p_name = NULL;
            //}
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_RELEASE_SHORTCUT, i);

            g_am_cntx.shortcut_app_list[i].is_downloaded = MMI_FALSE;
            g_am_cntx.shortcut_app_list[i].is_hs_shortcut = MMI_FALSE;
            g_am_cntx.shortcut_app_list[i].is_bg_started = MMI_FALSE;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_release_shortcut_list
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_release_shortcut_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* release appstore name */
    if (g_am_cntx.appstore_list.p_name)
    {
        mmi_am_free(g_am_cntx.appstore_list.p_name);
        g_am_cntx.appstore_list.p_name = NULL;
    }

    /* release list */
    if (g_am_cntx.shortcut_app_list)
    {
        mmi_am_release_shortcut_list_all_nodes();

        mmi_am_free(g_am_cntx.shortcut_app_list);
        g_am_cntx.shortcut_app_list = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_release_rom_list
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_release_rom_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* release list */
    if (g_am_cntx.rom_app_list)
    {
        /* release every member */
        for (i = 0; i < g_am_cntx.rom_app_num; i++)
        {
            /* release icon */
            if (g_am_cntx.rom_app_list[i].p_icon != NULL)
            {
                mmi_am_free(g_am_cntx.rom_app_list[i].p_icon);
                g_am_cntx.rom_app_list[i].p_icon = NULL;
            }

            /* release ZiMo */
            if (g_am_cntx.rom_app_list[i].p_name &&
                mmi_wcscmp((PU16) g_am_cntx.rom_app_list[i].p_name, (PU16) GetString(STR_ID_AM_APP_NAME_MRE20)) &&
                mmi_wcscmp((PU16) g_am_cntx.rom_app_list[i].p_name, (PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT)))
            {
                mmi_am_free(g_am_cntx.rom_app_list[i].p_name);
                g_am_cntx.rom_app_list[i].p_name = NULL;
            }
        }

        mmi_am_free(g_am_cntx.rom_app_list);
        g_am_cntx.rom_app_list = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_release_vxp_list_all_nodes
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_release_vxp_list_all_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.vxp_file_list)
    {
        while (mre_single_list_get_size(g_am_cntx.vxp_file_list))
        {
            mmi_am_vxp_file_struct *p = mre_single_list_get_element(g_am_cntx.vxp_file_list, 0);

            mmi_am_free(p);
            p = NULL;
            mre_single_list_remove(g_am_cntx.vxp_file_list, 0);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_release_vxp_list_nodes_in_memory_card
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_release_vxp_list_nodes_in_memory_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 num_of_vxp_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.vxp_file_list)
    {
        num_of_vxp_list = mre_single_list_get_size(g_am_cntx.vxp_file_list);

        for (i = num_of_vxp_list - 1; i >= 0; i--)
        {
            mmi_am_vxp_file_struct *p = mre_single_list_get_element(g_am_cntx.vxp_file_list, i);

            if (((S8) (*(p->path)) != (S8) mmi_am_get_system_driver()) && ((S8) (*(p->path)) != (S8) MMI_AM_ROM_DIR))
            {
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_RELEASE_VXP_NODE);
                mmi_am_free(p);
                p = NULL;
                mre_single_list_remove(g_am_cntx.vxp_file_list, i);
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_release_vxp_list
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_release_vxp_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.vxp_file_list)
    {
        mmi_am_release_vxp_list_all_nodes();

        mre_single_list_free(g_am_cntx.vxp_file_list);
        g_am_cntx.vxp_file_list = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_redraw_content_cb
* DESCRIPTION
*  Loading screen draw callback.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_redraw_content_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width, img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw background */
    gdi_draw_solid_rect(0, 0, UI_device_width, UI_device_height, GDI_COLOR_BLACK);

    /* get image width and height */
    gdi_image_get_dimension_id(IMG_ID_AM_LOADING, &img_width, &img_height);

    /* draw mre icon in the center of screen */
    gdi_image_draw_id((UI_device_width - img_width) >> 1, (UI_device_height - img_height) >> 1, IMG_ID_AM_LOADING);
}

/*****************************************************************************
* FUNCTION
*  mmi_am_entry_loading_scrn_status_icon_bar_hide_callback
* DESCRIPTION
*  we must register an status icon bar hide callback function ,otherwise ,status bar will blink once.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_entry_loading_scrn_status_icon_bar_hide_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cx1, cy1, cx2, cy2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();

    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &cx1, &cy1, &cx2, &cy2);
    gdi_layer_set_clip(cx1, cy1, cx2, cy2);
    gdi_draw_solid_rect(cx1, cy1, cx2, cy2, GDI_COLOR_BLACK);
    gdi_layer_pop_clip();
}

/*****************************************************************************
* FUNCTION
*  mmi_am_entry_loading_scrn
* DESCRIPTION
*  When enter AM or plug in memory card in AM, enter loading screen firstly.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_entry_loading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MRE_TRC_G1_AM,
        TRC_MMI_AM_ENTRY_LOADING_SCRN_S,
        g_am_cntx.adm_pool_id,
        //  g_am_cntx.is_card_plug_in,
        //g_am_cntx.is_card_plug_out,
        g_am_cntx.is_launch_vas);

    // ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_LOADING, NULL, mmi_am_entry_loading_scrn, MMI_FRM_FULL_SCRN);

    // if (ret == MMI_FALSE)
    // {
    //     return;
    //  }

    /* show category */
    //wgui_status_icon_bar_register_hide_callback(WGUI_STATUS_ICON_BAR_H_BAR,mmi_am_entry_loading_scrn_status_icon_bar_hide_callback);

    //   ShowCategory221Screen(0, 0, 0, 0, 0, 0, GDI_COLOR_BLACK, mmi_am_redraw_content_cb);

    // if (mmi_am_is_too_many_app_install())
    // {
    //     gui_start_timer(0, mmi_am_close_group_by_too_many_files);
    //     return;
    // }

    /* start AM from main menu */
    mmi_am_enter_am();
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E);
    return;

}


/*****************************************************************************
* FUNCTION
*  mmi_am_close_group_by_too_many_files
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_close_group_by_too_many_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display((WCHAR*) GetString(STR_ID_AM_FILE_OVERFLOW), MMI_EVENT_FAILURE, NULL);
    mmi_frm_group_close(GRP_ID_AM);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_hold_mre_folder
* DESCRIPTION
*  Hold the mre folder in phone and memory card.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_hold_mre_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 mre_path_w[20];
    FS_HANDLE fd = -1;
    S8 file_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MRE_TRC_G1_AM,
        TRC_MMI_AM_HOLD_MRE_FOLDER_S,
        g_am_cntx.card_mre_folder_hdl,
        g_am_cntx.phone_mre_folder_hdl);

    /* Firstly, search mre folder in remove driver */
    file_drv = mmi_am_get_removeable_driver();
    if (file_drv != 0 && g_am_cntx.card_mre_folder_hdl < 0)
    {
        memset(mre_path_w, 0, sizeof(mre_path_w));
        kal_wsprintf((WCHAR*) mre_path_w, "%c:\\%s", file_drv, MMI_AM_MRE_HOME_DIR);

        /* search mre folder, if it exists, hold it. */
        if ((fd = FS_Open(mre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)   /* mre is not folder */
        {
            FS_Close(fd);
        }
        else if ((fd = FS_Open(mre_path_w, FS_OPEN_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            g_am_cntx.card_mre_folder_hdl = fd;
        }

        fd = -1;
    }

    /* Secondly, search mre folder in system driver */
    file_drv = mmi_am_get_system_driver();
    if (file_drv != 0 && g_am_cntx.phone_mre_folder_hdl < 0)
    {
        memset(mre_path_w, 0, sizeof(mre_path_w));
        kal_wsprintf((WCHAR*) mre_path_w, "%c:\\%s", file_drv, MMI_AM_MRE_HOME_DIR);

        /* search mre folder, if it exists, hold it. */
        if ((fd = FS_Open(mre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)   /* mre is not folder */
        {
            FS_Close(fd);
        }
        else if ((fd = FS_Open(mre_path_w, FS_OPEN_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            g_am_cntx.phone_mre_folder_hdl = fd;
        }
    }

    MMI_TRACE(
        MMI_MRE_TRC_G1_AM,
        TRC_MMI_AM_HOLD_MRE_FOLDER_E,
        g_am_cntx.card_mre_folder_hdl,
        g_am_cntx.phone_mre_folder_hdl);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_search_shortcut_apps
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_search_shortcut_apps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, max;
    S8 *app_name;

    /* S32 str_len; */

    mmi_am_shortcut_info_struct *sc_list = mmi_am_config_get_am_sc_list();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_SHORTCUT_APPS_S);

    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
        /* search AppStore */
        mmi_am_search_appstore();
    }

    max = g_am_cntx.shortcut_app_num;

    /* other shortcut apps exluding AppStore */
    for (i = 0, j = 0; i < max; i++)
    {
        if (sc_list[i].app_id == APPID_VAS) /* exlude AppStore */
        {
            continue;
        }
        g_am_cntx.shortcut_app_list[j].icon_id = sc_list[i].icon_id;
        g_am_cntx.shortcut_app_list[j].name_id = sc_list[i].name_id;
        g_am_cntx.shortcut_app_list[j].name_size = sc_list[i].name_size;

        if ((!g_am_cntx.has_small_font) && (sc_list[i].p_name))
        {
            // get ZiMo data
            //g_am_cntx.shortcut_app_list[j].p_name = sc_list[i].p_name;
            mmi_am_get_zimo_string_data(
                sc_list[i].p_name,
                &g_am_cntx.shortcut_app_list[j].p_name,
                (PS32) & g_am_cntx.shortcut_app_list[j].name_len);
        }

        /* Whether the application has been downloaded */
        app_name = mmi_am_config_get_am_sc_name_by_appid(sc_list[i].app_id);
        if (mmi_am_is_app_downloaded(app_name, g_am_cntx.shortcut_app_list[j].path))
        {
            g_am_cntx.shortcut_app_list[j].is_downloaded = MMI_TRUE;

            /* Whether the application is set to HS shortcut. */
#ifdef MMI_AM_SHORTCUT_ENABLE
            if (mmi_am_is_set_as_shortcut(g_am_cntx.shortcut_app_list[j].path))
            {
                g_am_cntx.shortcut_app_list[j].is_hs_shortcut = MMI_TRUE;
            }
            else
#endif /* MMI_AM_SHORTCUT_ENABLE */ 
            {
                g_am_cntx.shortcut_app_list[j].is_hs_shortcut = MMI_FALSE;
            }

            /* Whether the application is running in the background. */
            if (srv_mre_is_app_bg_running(g_am_cntx.shortcut_app_list[j].path))
            {
                g_am_cntx.shortcut_app_list[j].is_bg_started = MMI_TRUE;
            }
            else
            {
                g_am_cntx.shortcut_app_list[j].is_bg_started = MMI_FALSE;
            }

        }
        else
        {
            g_am_cntx.shortcut_app_list[j].is_downloaded = MMI_FALSE;
            g_am_cntx.shortcut_app_list[j].is_hs_shortcut = MMI_FALSE;
            g_am_cntx.shortcut_app_list[j].is_bg_started = MMI_FALSE;
        }

        j++;
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_SHORTCUT_APPS_E);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_search_appstore
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_search_appstore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_drv;
    U16 temp_path_w[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    U16 as_path_w[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    FS_HANDLE fd = -1;
    mmi_am_shortcut_info_struct *sc_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_APPSTORE_S);

    memset(temp_path_w, 0, sizeof(temp_path_w));
    memset(as_path_w, 0, sizeof(as_path_w));

    /* set icon and name info */
    sc_info = mmi_am_config_get_am_sc_info_by_appid(APPID_VAS);
    if (sc_info == NULL)
    {
        return;
    }
    g_am_cntx.appstore_list.icon_id = sc_info->icon_id;
    g_am_cntx.appstore_list.name_id = sc_info->name_id;
    g_am_cntx.appstore_list.name_size = sc_info->name_size;

    if ((!g_am_cntx.has_small_font) && (sc_info->p_name))
    {
        /* get ZiMo data */
        mmi_am_get_zimo_string_data(
            sc_info->p_name,
            &g_am_cntx.appstore_list.p_name,
            (PS32) & g_am_cntx.appstore_list.name_len);
    }

    /* Search remove driver */
    file_drv = mmi_am_get_removeable_driver();
    if (file_drv)
    {
        /* set phsh.pht path */
        kal_wsprintf((WCHAR*) temp_path_w, "%c:\\%s\\%s", file_drv, MMI_AM_MRE_HOME_DIR, MMI_AM_AS_TEMP_FILE_NAME);

        /* set phsh.vxp path */
        kal_wsprintf(
            (WCHAR*) as_path_w,
            "%c:\\%s\\%s",
            file_drv,
            MMI_AM_MRE_HOME_DIR,
            mmi_am_config_get_am_sc_name_by_appid(APPID_VAS));

        /* search phsh.pht */
        if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* phsh.pht exist */
            FS_Close(fd);

            /* search phsh.vxp */
            if ((fd = FS_Open(as_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
            {
                /* phsh.vxp exist */
                FS_Close(fd);
                FS_Delete(as_path_w);
                FS_Rename(temp_path_w, as_path_w);
            }
            else
            {
                FS_Rename(temp_path_w, as_path_w);
            }
        }

        /* search phsh.vxp */
        if ((fd = FS_Open(as_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* app exist */
            FS_Close(fd);

            mmi_wcscpy(g_am_cntx.appstore_list.path, as_path_w);
            g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

            /* Whether the application is set to HS shortcut. */
#ifdef MMI_AM_SHORTCUT_ENABLE
            if (mmi_am_is_set_as_shortcut(g_am_cntx.appstore_list.path))
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
            }
            else
#endif /* MMI_AM_SHORTCUT_ENABLE */ 
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_FALSE;
            }

            /* Whether the application is running in the background. */
            if (srv_mre_is_app_bg_running(g_am_cntx.appstore_list.path))
            {
                g_am_cntx.appstore_list.is_bg_started = MMI_TRUE;
            }

            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_APPSTORE_E1);
            return;
        }
    }

    /**********************************************************************/

    memset(temp_path_w, 0, sizeof(temp_path_w));
    memset(as_path_w, 0, sizeof(as_path_w));

    /* Search system driver */
    file_drv = mmi_am_get_system_driver();
    if (file_drv)
    {
        /* set phsh.pht path */
        kal_wsprintf((WCHAR*) temp_path_w, "%c:\\%s\\%s", file_drv, MMI_AM_MRE_HOME_DIR, MMI_AM_AS_TEMP_FILE_NAME);

        /* set phsh.vxp path */
        kal_wsprintf(
            (WCHAR*) as_path_w,
            "%c:\\%s\\%s",
            file_drv,
            MMI_AM_MRE_HOME_DIR,
            mmi_am_config_get_am_sc_name_by_appid(APPID_VAS));

        /* search phsh.pht */
        if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* phsh.pht exist */
            FS_Close(fd);

            /* search phsh.vxp */
            if ((fd = FS_Open(as_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
            {
                /* phsh.vxp exist */
                FS_Close(fd);
                FS_Delete(as_path_w);
                FS_Rename(temp_path_w, as_path_w);
            }
            else
            {
                FS_Rename(temp_path_w, as_path_w);
            }
        }

        /* search phsh.vxp */
        if ((fd = FS_Open(as_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* app exist */
            FS_Close(fd);

            mmi_wcscpy(g_am_cntx.appstore_list.path, as_path_w);
            g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

            /* Whether the application is set to HS shortcut. */
#ifdef MMI_AM_SHORTCUT_ENABLE
            if (mmi_am_is_set_as_shortcut(g_am_cntx.appstore_list.path))
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
            }
            else
#endif /* MMI_AM_SHORTCUT_ENABLE */ 
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_FALSE;
            }

            /* Whether the application is running in the background. */
            if (srv_mre_is_app_bg_running(g_am_cntx.appstore_list.path))
            {
                g_am_cntx.appstore_list.is_bg_started = MMI_TRUE;
            }

            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_APPSTORE_E2);
            return;
        }
    }

    /**********************************************************************/

    /* Search rom */
    mmi_am_search_appstore_in_rom();

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_APPSTORE_E3);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_search_appstore_in_rom
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_search_appstore_in_rom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 rom_app_path_w[MMI_AM_MAX_APP_FILE_PATH];
    S32 *app_array;
    S32 app_array_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_get_rom_app_array(&app_array, &app_array_len);

    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        memset(rom_app_path_w, 0, sizeof(rom_app_path_w));

        kal_wsprintf(
            (WCHAR*) rom_app_path_w,
            "%c:\\%s\\%u.rom",
            MMI_AM_ROM_DIR,
            MMI_AM_MRE_HOME_DIR,
            *(app_array + i));

        /* check if the application is AppStore */
        if (!mmi_am_is_appstore_in_rom((PU16) rom_app_path_w))
        {
            continue;
        }

        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_APPSTORE_IN_ROM);

        mmi_wcscpy(g_am_cntx.appstore_list.path, rom_app_path_w);
        g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

        /* Whether the application is set to HS shortcut. */
#ifdef MMI_AM_SHORTCUT_ENABLE
        if (mmi_am_is_set_as_shortcut(g_am_cntx.appstore_list.path))
        {
            g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
        }
        else
#endif /* MMI_AM_SHORTCUT_ENABLE */ 
        {
            g_am_cntx.appstore_list.is_hs_shortcut = MMI_FALSE;
        }

        /* Whether the application is running in the background. */
        if (srv_mre_is_app_bg_running(g_am_cntx.appstore_list.path))
        {
            g_am_cntx.appstore_list.is_bg_started = MMI_TRUE;
        }
    }

    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_search_rom_apps
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmi_am_search_rom_apps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 rom_app_path_w[MMI_AM_MAX_APP_FILE_PATH];
    S32 *app_array;
    S32 app_array_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_ROM_APPS_S);

    mmi_am_get_rom_app_array(&app_array, &app_array_len);

    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        memset(rom_app_path_w, 0, sizeof(rom_app_path_w));

        /* build app path */
        kal_wsprintf(
            (WCHAR*) rom_app_path_w,
            "%c:\\%s\\%u.rom",
            MMI_AM_ROM_DIR,
            MMI_AM_MRE_HOME_DIR,
            *(app_array + i));

        /* check if the application is AppStore */
        //if (mmi_am_is_appstore_in_rom((PU16) rom_app_path_w))
        //{
        //    continue;
        //}

        /* set rom app full path */
        mmi_wcscpy(g_am_cntx.rom_app_list[i].path, rom_app_path_w);

        /* get app icon */
        if (srv_mre_get_app_image(rom_app_path_w, NULL, &g_am_cntx.rom_app_list[i].icon_size))
        {
            g_am_cntx.rom_app_list[i].p_icon = mmi_am_calloc(g_am_cntx.rom_app_list[i].icon_size);
            srv_mre_get_app_image(
                rom_app_path_w,
                g_am_cntx.rom_app_list[i].p_icon,
                &g_am_cntx.rom_app_list[i].icon_size);
        }

        /* get app name */
        if (g_am_cntx.has_small_font)   /* support small font */
        {
            if (srv_mre_get_app_name(rom_app_path_w, NULL, &g_am_cntx.rom_app_list[i].name_size))
            {
                g_am_cntx.rom_app_list[i].p_name = mmi_am_calloc(g_am_cntx.rom_app_list[i].name_size);
                srv_mre_get_app_name(
                    rom_app_path_w,
                    (U16 *)g_am_cntx.rom_app_list[i].p_name,
                    &g_am_cntx.rom_app_list[i].name_size);
            }
            else
            {
                g_am_cntx.rom_app_list[i].p_name = (PU8) GetString(STR_ID_AM_APP_NAME_DEFAULT);
                g_am_cntx.rom_app_list[i].name_len = mmi_wcslen((PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT));
            }
        }
        else
        {
            if (srv_mre_get_app_zimo_name
                (rom_app_path_w, NULL, &g_am_cntx.rom_app_list[i].name_size, &g_am_cntx.rom_app_list[i].name_len))
            {
                g_am_cntx.rom_app_list[i].p_name = mmi_am_calloc(g_am_cntx.rom_app_list[i].name_size);
                srv_mre_get_app_zimo_name(
                    rom_app_path_w,
                    g_am_cntx.rom_app_list[i].p_name,
                    &g_am_cntx.rom_app_list[i].name_size,
                    &g_am_cntx.rom_app_list[i].name_len);
            }
            else
            {
                mmi_am_get_zimo_string_data(
                    (PU8) AM_App_Default,
                    &g_am_cntx.rom_app_list[i].p_name,
                    (PS32) & g_am_cntx.rom_app_list[i].name_len);
            }
        }

        /* Whether the application is set to HS shortcut. */
#ifdef MMI_AM_SHORTCUT_ENABLE
        if (mmi_am_is_set_as_shortcut(g_am_cntx.rom_app_list[i].path))
        {
            g_am_cntx.rom_app_list[i].is_hs_shortcut = MMI_TRUE;
        }
        else
#endif /* MMI_AM_SHORTCUT_ENABLE */ 
        {
            g_am_cntx.rom_app_list[i].is_hs_shortcut = MMI_FALSE;
        }

        /* Whether the application is running in the background. */
        if (srv_mre_is_app_bg_running(g_am_cntx.rom_app_list[i].path))
        {
            g_am_cntx.rom_app_list[i].is_bg_started = MMI_TRUE;
        }
        else
        {
            g_am_cntx.rom_app_list[i].is_bg_started = MMI_FALSE;
        }

        g_am_cntx.rom_app_list[i].idx = g_am_cntx.shortcut_app_num + i;
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_SEARCH_ROM_APPS_E);

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_get_rom_appinfo_by_idx
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
mmi_am_rom_app_struct *mmi_am_get_rom_appinfo_by_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        if (g_am_cntx.rom_app_list[i].idx == idx)
        {
            return &g_am_cntx.rom_app_list[i];
        }
    }

    return NULL;
}
/*****************************************************************************
* FUNCTION
*  mmi_am_entry_am
* DESCRIPTION
*  entry pluto AM
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/

static void mmi_am_enter_am(void)
{
    if (!mmi_am_search_rom_apps())
    {
        mmi_frm_group_close(GRP_ID_AM);
        return;
    }
    mmi_am_ms_init();

    if (mmi_am_build_installed_app_list() == MMI_FALSE)
    {
        mmi_frm_group_close(GRP_ID_AM);
        return;
    }
    /* enter Main Screen */
    if (mmi_frm_scrn_is_present(GRP_ID_AM, SCR_ID_AM_MAIN, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_am_entry_main_scrn();
    }

}
/*****************************************************************************
* FUNCTION
*  mmi_am_build_installed_app_list
* DESCRIPTION
*  build shortcut application list, rom application list, and local vxp appliction list
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_build_installed_app_list(void)
{       
    U32 install_app_num = 0;
    U32 i=0, idx = 0;
    WCHAR app_name_w[MMI_APP_NAME_MAX_LEN];
    //mmi_app_package_name_struct * install_app_list = NULL;
    mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN];
    U32 *install_app_unique_id = NULL;
    srv_mre_appmgr_installed_info_struct installed_info;
    mmi_am_ms_app_struct *app_p;
    install_app_num = srv_mre_appmgr_get_installed_app_num();
    if(0==install_app_num)
    {
        return MMI_TRUE;
    }
    else
    {
        //install_app_list = (mmi_app_package_name_struct *)mmi_am_calloc(sizeof(mmi_app_package_name_struct)*install_app_num);
        install_app_unique_id = (U32 *)mmi_am_calloc(sizeof(U32)*install_app_num);
        if(NULL==install_app_unique_id)
        {
            ASSERT(0);
        }
        else
        {      
            srv_mre_appmgr_get_unique_app_id_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE,install_app_unique_id,install_app_num);
            for(i=0;i<install_app_num;i++)
            {
                srv_mre_appmgr_get_package_name_by_unique_id(install_app_unique_id[i],app_name);
                mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);
                if(srv_mre_appmgr_get_installed_info(app_name_w,&installed_info)&&installed_info.app_size!=0&((installed_info.app_type!=SRV_MRE_APPMGR_APP_TYPE_ROM)||(installed_info.app_type!=SRV_MRE_APPMGR_APP_TYPE_SERVICE)))
                {
                    app_p = (mmi_am_ms_app_struct *)mmi_am_ms_get_appinfo_from_installed_info(app_name,&installed_info,install_app_unique_id[i]);
                    if (app_p)
                    {
                        /* set display index */
                        app_p->idx = idx + (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num);
                        /* add the app to app_list */
                        if (g_am_ms_cntx.app_list)
                        {
                            idx += 1;
                            g_am_cntx.vxp_app_num++;  //initialize g_am_cntx. vxp_app_num's value
                            mre_single_list_add(g_am_ms_cntx.app_list, app_p, -1);
                        }
                        else
                        {
                            mmi_am_ms_release_applist_node(app_p);
                        }

                    }
                }
            }
        }
        mmi_am_free(install_app_unique_id);
    }
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_am_ms_get_appinfo_from_installed_info
* DESCRIPTION
*  
* PARAMETERS
*  vxp_p       [IN]        
* RETURNS
*  
*****************************************************************************/
static mmi_am_ms_app_struct * mmi_am_ms_get_appinfo_from_installed_info(mmi_app_package_char *app_name, srv_mre_appmgr_installed_info_struct *info,U32 app_unique_id)
{
    S32 ret;
    S32 cache_size = MMI_AM_LOAD_RES_BUF_SIZE;
    CHAR *cache_buf = NULL;
    mmi_am_ms_app_struct *app_p;
    //mmi_image_src_struct image;
    // FS_HANDLE fd = -1;
    //S32 file_result;
    //U32 file_size;
    //U32 read_no = 0;



    app_p = mmi_am_calloc(sizeof(mmi_am_ms_app_struct));
    if (!app_p)
    {
        MMI_AM_ASSERT(app_p != NULL);
        // mmi_am_free(cache_buf);
        return NULL;
    }

    /* set app full path */
    mmi_wcscpy(app_p->path, info->app_path);

    /* get app icon */
    /*  if(srv_mre_appmgr_get_app_image(app_name,&image)==MMI_RET_OK)
    {
    if(image.type == MMI_IMAGE_SRC_TYPE_PATH)
    {
    if ((fd = FS_Open(image.data.path, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    {
    if((file_result = FS_GetFileSize(fd, &file_size))==FS_NO_ERROR)
    {
    app_p->icon_size = file_size;
    app_p->p_icon = mmi_am_calloc(app_p->icon_size);
    if(app_p->p_icon)
    FS_Read(fd, app_p->p_icon, app_p->icon_size, &read_no);
    if (read_no != app_p->icon_size)
    {
    ASSERT(0);
    }
    }
    }
    FS_Close(fd);
    }
    }*/
    app_p->icon_size = 0;
    app_p->p_icon = NULL;

    /* get app name */
    if (g_am_cntx.has_small_font)   /* support small font */
    {
        WCHAR string[MMI_APP_NAME_MAX_LEN] = {0};
        U8 appname[MMI_APP_NAME_MAX_LEN] = {0};
        if(srv_mre_appmgr_get_app_name(app_name,string)==MMI_RET_OK)
        {
            app_p->name_size = mmi_wcslen(string)<<1; 
            app_p->p_name = mmi_am_calloc(app_p->name_size + 2);
            mmi_wcsncpy((WCHAR *)app_p->p_name, (WCHAR *)string, app_p->name_size >> 1);
        }
        else
        {
            app_p->p_name = (PU8) GetString(STR_ID_AM_APP_NAME_DEFAULT);
            app_p->name_len = mmi_wcslen((PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT));
        }
    }
    else
    {
        /* allocate cache buffer */
        cache_buf = mmi_am_calloc(cache_size);
        if (!cache_buf)
        {
            MMI_AM_ASSERT(cache_buf != NULL);
            return NULL;
        }
        if (srv_mre_get_app_zimo_name(app_p->path, (CHAR*) cache_buf, &app_p->name_size, &app_p->name_len))
        {
            app_p->p_name = mmi_am_calloc(app_p->name_size);
            memcpy(app_p->p_name, cache_buf, app_p->name_size);
        }
        else
        {
            mmi_am_get_zimo_string_data((PU8) AM_App_Default, &app_p->p_name, (PS32) & app_p->name_len);
        }
        /* release cache buffer */
        mmi_am_free(cache_buf);
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
    //memcpy(app_p->app_identification,app_name,MMI_APP_NAME_MAX_LEN);
    app_p->app_unique_id = app_unique_id;


    return app_p;	
}



/*****************************************************************************
* FUNCTION
*  mmi_am_search_vxp_files
* DESCRIPTION
*  
* PARAMETERS
*  void
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
#endif

/*****************************************************************************
* FUNCTION
*  mmi_am_search_vxp_cb
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif
/*****************************************************************************
* FUNCTION
*  mmi_am_binary_search
* DESCRIPTION
*  
* PARAMETERS
*  modify_time     [IN]        
* RETURNS
*  
*****************************************************************************/
static S32 mmi_am_binary_search(FS_DOSDateTime *modify_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 low = 0;
    S32 high = mre_single_list_get_size(g_am_cntx.vxp_file_list) - 1;
    S32 mid = (low + high) >> 2;
    mmi_am_vxp_file_struct *p;
    S32 ret_cmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* search axis value */
    while (low <= high)
    {
        mid = (low + high) / 2;

        p = mre_single_list_get_element(g_am_cntx.vxp_file_list, mid);

        ret_cmp = mmi_am_compare_time(modify_time, &p->time);

        if (ret_cmp == -1)  /* modify_time < p->time */
        {
            low = mid + 1;
        }
        else if (ret_cmp == 1)  /* modify_time > p->time */
        {
            high = mid - 1;
        }
        else    /* modify_time = p->time */
        {
            if (mid == mre_single_list_get_size(g_am_cntx.vxp_file_list) - 1)
            {
                return mid + 1;
            }
            else
            {
                return mmi_am_search_same_time_pos(modify_time, mid + 1);
            }
        }
    }

    if (mid < 0)
    {
        return 0;
    }

    p = mre_single_list_get_element(g_am_cntx.vxp_file_list, mid);
    ret_cmp = mmi_am_compare_time(modify_time, &p->time);

    if (ret_cmp == -1)  /* modify_time < p->time */
    {
        if (mid != (mre_single_list_get_size(g_am_cntx.vxp_file_list) - 1))
        {
            return mid + 1;
        }
        else
        {
            return -1;
        }
    }
    else if (ret_cmp == 1)  /* modify_time > p->time */
    {
        return mid;
    }

    return mid;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_search_same_time_pos
* DESCRIPTION
*  
* PARAMETERS
*  modify_time     [IN]        
*  pos             [IN]        
* RETURNS
*  
*****************************************************************************/
static S32 mmi_am_search_same_time_pos(FS_DOSDateTime *modify_time, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_pos = pos;
    S32 cmp_ret;
    mmi_am_vxp_file_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cur_pos < mre_single_list_get_size(g_am_cntx.vxp_file_list))
    {
        p = mre_single_list_get_element(g_am_cntx.vxp_file_list, cur_pos);

        cmp_ret = mmi_am_compare_time(modify_time, &p->time);
        if (cmp_ret == 0)
        {
            cur_pos++;
            if (cur_pos == mre_single_list_get_size(g_am_cntx.vxp_file_list))
            {
                return -1;
            }
        }
        else
        {
            return cur_pos;
        }
    }

    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_compare_time
* DESCRIPTION
*  
* PARAMETERS
*  time1       [IN]        
*  time2       [IN]        
* RETURNS
*  
*****************************************************************************/
static S32 mmi_am_compare_time(FS_DOSDateTime *time1, FS_DOSDateTime *time2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (time1->Year1980 > time2->Year1980)
        return 1;
    else if (time1->Year1980 < time2->Year1980)
        return -1;

    if (time1->Month > time2->Month)
        return 1;
    else if (time1->Month < time2->Month)
        return -1;

    if (time1->Day > time2->Day)
        return 1;
    else if (time1->Day < time2->Day)
        return -1;

    if (time1->Hour > time2->Hour)
        return 1;
    else if (time1->Hour < time2->Hour)
        return -1;

    if (time1->Minute > time2->Minute)
        return 1;
    else if (time1->Minute < time2->Minute)
        return -1;

    if (time1->Second2 > time2->Second2)
        return 1;
    else if (time1->Second2 < time2->Second2)
        return -1;

    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_card_plug_in_hdlr
* DESCRIPTION
*  Memory card plug in handler.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_card_plug_in_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //  U16 scrn_id;
    //  mmi_frm_node_struct new_node = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  MMI_TRACE(
    MMI_MRE_TRC_G1_AM,
    TRC_MMI_AM_PLUG_IN_S,
    g_am_cntx.adm_pool_id,
    g_am_cntx.is_card_plug_out,
    g_am_search_cntx.search_state);*/

    /* lf added for dla 2010-12-23 -s */
    //#ifdef MRE_DOWNLOAD_SRV
    //    mmi_am_dla_tcard_plugin_hdlr();
    //#endif
    /* lf added for dla 2010-12-23 -e */

    /* hold mre folder handle */
    // mmi_am_hold_mre_folder();

    // g_am_cntx.is_card_plug_out = MMI_FALSE;
    // g_am_cntx.is_card_plug_in = MMI_TRUE;

    // scrn_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_AM, SCR_ID_AM_MAIN, MMI_FRM_NODE_AFTER_FLAG);

    // MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PLUG_IN_SCRN_ID, scrn_id);

    // TODO: verify this point
    // if (scrn_id != SCR_ID_AM_LOADING    /* && g_am_cntx.start_state == START_NONE */
    //    && g_am_search_cntx.search_state == SEARCH_NONE)
    // {
    /* close loading screen firstly, ex: loading screen is loacte below of main screen */
    //  mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);

    /* insert a loading screen */
    //   new_node.id = SCR_ID_AM_LOADING;
    //   new_node.entry_proc = (mmi_proc_func) mmi_am_entry_loading_scrn;
    //    mmi_frm_scrn_insert(GRP_ID_AM, SCR_ID_AM_MAIN, &new_node, MMI_FRM_NODE_AFTER_FLAG);

    /* stop scrolling text */
    //   mmi_am_ms_scrolling_text_stop();
    //}

    // MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PLUG_IN_E);
}

/*****************************************************************************
* FUNCTION
*  mmi_am_card_plug_out_hdlr
* DESCRIPTION
*  Memory card plug out handler.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_card_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // U16 *app_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(
    MMI_MRE_TRC_G1_AM,
    TRC_MMI_AM_PLUG_OUT_S,
    g_am_cntx.adm_pool_id,
    g_am_cntx.is_card_plug_in,
    g_am_ms_cntx.hl_idx,
    g_am_cntx.is_app_in_card);*/

    /* lf added for dla 2010-12-23 -s */
    /*#ifdef MRE_DOWNLOAD_SRV
    mmi_am_dla_tcard_plugout_hdlr();*/
    //#endif
    /* lf added for dla 2010-12-23 -e */

    /* close mre folder file handle */
    // if (g_am_cntx.card_mre_folder_hdl >= 0)
    // {
    //    FS_Close(g_am_cntx.card_mre_folder_hdl);
    //    g_am_cntx.card_mre_folder_hdl = -1;
    // }

    // TODO: verify this point
    // if (g_am_cntx.is_card_plug_in)  /* && g_am_cntx.start_state == START_NONE) */
    // {
    //     mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
    //  }
    //  g_am_cntx.is_card_plug_in = MMI_FALSE;
    //  g_am_cntx.is_card_plug_out = MMI_TRUE;

    /* Get the highlight application's storage driver */
    // if(g_am_ms_cntx.hl_idx < 0) // tongzhibo add for MAUI_02940442 (if( index<0) it's means here has no app in main screen)
    // {
    //     app_path = NULL;
    // }
    // else
    // {
    //     app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);
    // }

    /* if (app_path)
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PLUG_OUT_PATH, ((S8) * app_path));

    if (app_path && (((S8) * app_path) != (S8) mmi_am_get_system_driver()) &&
    (((S8) * app_path) != (S8) MMI_AM_ROM_DIR))
    {
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PLUG_OUT_IN_MEMORY_CARD);

    g_am_cntx.is_app_in_card = MMI_TRUE;    */// TODO: verify this point
    // #if 0
    //   if (g_am_cntx.start_state == START_NONE && g_am_search_cntx.search_state == SEARCH_NONE)    /* is not in the search vxp files */
    //  #else /* 0 */ 
    //     if (g_am_search_cntx.search_state == SEARCH_NONE)   /* is not in the search vxp files */
    // #endif /* 0 */ 
    //{
    //     mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
    //  }
    // mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DETAILS);
    // }

    /* release lists */
    // mmi_am_release_shortcut_list_nodes_in_memory_card();
    // mmi_am_release_vxp_list_nodes_in_memory_card();
    /* mmi_am_release_vxp_list_all_nodes(); */
    // mmi_am_ms_release_app_list_nodes_in_memory_card();

    /* search vxp files in system disk */
    /* mmi_am_search_vxp_files(); */

    /* update main screen highlight item */
    /* g_am_ms_cntx.hl_idx = 0; */

    // MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_PLUG_OUT_E, g_am_ms_cntx.hl_idx, g_am_cntx.is_app_in_card);
}

mmi_ret mmi_am_handle_event(mmi_event_struct *event)
{
    mmi_ret ret = MMI_RET_OK;

    switch (event->evt_id)
    {
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: 
    case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
    case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        if (mmi_am_enter_am_flag&&mmi_frm_group_is_present(GRP_ID_AM))
        {
            mmi_am_start();
        }

        break;
    default:
        break;
    }
    return ret;
}

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
* FUNCTION
*  mmi_am_enter_usb_mode
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_enter_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTER_USB_MODE_S, g_am_cntx.adm_pool_id);

    if (g_am_cntx.adm_pool_id)
    {
#if defined(__MMI_USB_SUPPORT__)
        if (srv_usb_is_in_mass_storage_mode())
        {
            mmi_frm_group_close(GRP_ID_AM);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTER_USB_MODE_CLOSE_AM);
        }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTER_USB_MODE_E);
}
#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_am_enter_usb_mode_ms_callback
* DESCRIPTION
*  Enter usb mode callback.
* PARAMETERS
*  evt     [IN]     Event id.
* RETURNS
*  mmi_ret
*****************************************************************************/
mmi_ret mmi_am_enter_usb_mode_ms_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTER_USB_MODE_S, g_am_cntx.adm_pool_id);

    if (g_am_cntx.adm_pool_id)
    {
#if defined(__MMI_USB_SUPPORT__)
        if (srv_usb_is_in_mass_storage_mode())
        {
            mmi_frm_group_close(GRP_ID_AM);
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTER_USB_MODE_CLOSE_AM);
        }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    }

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_ENTER_USB_MODE_E);
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_delete_node_from_vxplist_by_index
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_delete_node_from_vxplist_by_index(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    mmi_am_vxp_file_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return;
    }
    else
    {
        index = idx - (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num);
        p = mre_single_list_get_element(g_am_cntx.vxp_file_list, index);
        if (p)
        {
            /* delete the node */
            mmi_am_free(p);
            p = NULL;
            mre_single_list_remove(g_am_cntx.vxp_file_list, index);
        }
        else
        {
            MMI_AM_ASSERT(0);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_delete_node_from_vxplist_by_path
* DESCRIPTION
*  
* PARAMETERS
*  app_path        [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_delete_node_from_vxplist_by_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_pos;
    mmi_am_vxp_file_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_path)
    {
        return;
    }

    for (cur_pos = 0; cur_pos < mre_single_list_get_size(g_am_cntx.vxp_file_list); cur_pos++)
    {
        p = mre_single_list_get_element(g_am_cntx.vxp_file_list, cur_pos);

        if (p && mmi_wcscmp(app_path, p->path) == 0)
        {
            /* delete the node */
            mmi_am_free(p);
            p = NULL;
            mre_single_list_remove(g_am_cntx.vxp_file_list, cur_pos);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_check_downloaded_app_by_as
* DESCRIPTION
*  Check apps downloaded by AS.
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmi_am_check_downloaded_app_by_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_drv;
    FS_HANDLE fd = -1, app_fd = -1;
    FS_HANDLE fs_result;
    U16 dl_app_list_path_w[30];
    U16 app_path_w[MMI_AM_MAX_APP_FILE_PATH];   /* downloaded app file path */
    S32 i, num_of_list;
    U32 read_size;
    U32 app_path_len;
    FS_FileInfo info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_CHECK_DL_BY_AS_S, g_am_cntx.is_card_plug_in);
    memset(dl_app_list_path_w, 0, sizeof(dl_app_list_path_w));

    /* search list */
    /* if (g_am_cntx.is_card_plug_in) */
    {
        /* search memory card firstly */
        file_drv = mmi_am_get_removeable_driver();
        kal_wsprintf((WCHAR*) dl_app_list_path_w, "%c:\\%s\\%s", file_drv, MMI_AM_MRE_HOME_DIR, MMI_AM_DOWNLOAD_LIST);
        if ((fd = FS_Open(dl_app_list_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_CHECK_DL_BY_AS_PLUG_IN_1);

            /* search phone */
            memset(dl_app_list_path_w, 0, sizeof(dl_app_list_path_w));
            file_drv = mmi_am_get_system_driver();
            kal_wsprintf(
                (WCHAR*) dl_app_list_path_w,
                "%c:\\%s\\%s",
                file_drv,
                MMI_AM_MRE_HOME_DIR,
                MMI_AM_DOWNLOAD_LIST);
            if ((fd = FS_Open(dl_app_list_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
            {
                MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_CHECK_DL_BY_AS_PLUG_IN_2);

                return MMI_FALSE;
            }
        }
    }
    //else
    //{
    //    file_drv = mmi_am_get_home_driver();
    //    sprintf(dl_app_list_path, "%c:\\%s\\%s", file_drv, MMI_AM_MRE_HOME_DIR, MMI_AM_DOWNLOAD_LIST);
    //    mmi_asc_to_wcs(dl_app_list_path_w, (PS8) dl_app_list_path);
    //    if ((fd = FS_Open(dl_app_list_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
    //    {
    //        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_CHECK_DL_BY_AS_E1);
    //  /* list does not exist */
    //        return MMI_FALSE;
    //    }
    //}

    /* Read app list to vxp_list */
    if ((fs_result = FS_Read(fd, &num_of_list, 4, &read_size)) == FS_NO_ERROR && read_size == 4)
    {
        MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_CHECK_DL_BY_AS_LIST_NUM, num_of_list);
        for (i = 0; i < num_of_list; i++)
        {
            app_path_len = 0;
            read_size = 0;
            memset(app_path_w, 0, sizeof(app_path_w));
            memset(&info, 0, sizeof(info));
            if ((fs_result = FS_Read(fd, &app_path_len, 4, &read_size)) == FS_NO_ERROR && read_size == 4)
            {
                if ((fs_result = FS_Read(fd, &app_path_w, app_path_len << 1, &read_size)) == FS_NO_ERROR &&
                    read_size == (app_path_len << 1))
                {
                    /* check if the app_path has been in vxp_list, if exist, then delet it */
                    mmi_am_delete_node_from_vxplist_by_path(app_path_w);

                    /* open the downloaded app file */
                    if ((app_fd = FS_Open(app_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
                    {
                        break;
                    }
                    /* get file info */
                    if (FS_GetFileInfo(app_fd, &info) < 0)
                    {
                        FS_Close(app_fd);
                        break;
                    }

                    // g_am_search_cntx.cur_driver = (S8) (*app_path_w);
                    //if (!mmi_am_add_vxp_file_list(app_path_w + MMI_AM_MRE_FOLDER_SIZE, info.DirEntry->DateTime))
                    //{
                    /* close app file */
                    // FS_Close(app_fd);
                    // break;
                    //}

                    /* close app file */
                    FS_Close(app_fd);
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    /* delete the file */
    FS_Close(fd);
    FS_Delete(dl_app_list_path_w);
    //  g_am_search_cntx.cur_driver = mmi_am_get_home_driver();

    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_CHECK_DL_BY_AS_E2);

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_is_too_many_files_in_mre_folder
* DESCRIPTION
*  
* PARAMETERS
*  void
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
#endif
/*****************************************************************************
* FUNCTION
*  mmi_am_is_too_many_app_install
* DESCRIPTION
*  to see if too many application are installed
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmi_am_is_too_many_app_install(void)
{
    U32 install_app_num = 0;
    MMI_BOOL ret = MMI_FALSE;
    install_app_num = srv_mre_appmgr_get_installed_app_num();
    MMI_TRACE(MMI_MRE_TRC_G1_AM, TRC_MMI_AM_CHECK_FILE_NUMBER, install_app_num);
    if (install_app_num > MMI_AM_VXP_MAX_FILE_NUM)
    {
        ret = MMI_TRUE;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_fmgr_notify_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  param               [IN]        
* RETURNS
*  
*****************************************************************************/
mmi_ret mmi_am_fmgr_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.adm_pool_id)
    {
        switch (param->evt_id)
        {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            mmi_am_card_plug_out_hdlr();
            break;
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
            mmi_am_card_plug_in_hdlr();
            break;
        default:
            break;
        }
    }
    return MMI_RET_OK;
}

#ifndef MMI_AM_USING_MRE_MEM


/*****************************************************************************
* FUNCTION
*  mmi_am_is_asm_enough
* DESCRIPTION
*  Check whether memory is enough to launch AM.
*  If the memory is not enough, then enter OOM screen.
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmi_am_is_asm_enough()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mre_core_size;
    U32 memory_size;
    void *memory_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mre_core_size = vm_vam_get_core_asm_size();
    /* Memory size = AM + MRE Core + 50byte */
    memory_size = MMI_AM_MAX_DYN_MEM_SIZE + mre_core_size + 50;

    /* application registeration & stop callback */
    applib_mem_ap_register(APPLIB_MEM_AP_ID_AM, MAIN_MENU_MRE_TEXT, IMG_ID_AM_TITLE, mmi_am_asm_stop_cb);

    /* allocate memory */
#ifdef WIN32
    memory_ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AM, memory_size);
#else 
    memory_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_AM, memory_size);
#endif 
    if (memory_ptr == NULL)
    {
        /* register callback */
        mmi_frm_appmem_prompt_to_release_mem(APPLIB_MEM_AP_ID_AM, 0, memory_size, mmi_am_alloc_mem_cb);
        g_am_cntx.is_alloc_asm_fail = MMI_TRUE;
        return MMI_FALSE;
    }
    else
    {
        applib_mem_ap_free(memory_ptr);
    }

    return MMI_TRUE;
}
#endif /* MMI_AM_USING_MRE_MEM */ 

#endif /* AM_APP_MANAGEMENT_SUPPORT */ 
#endif /* __MRE_AM__ */ 

