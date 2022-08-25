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
* Shortcuts.c
*
* Project:
* --------
* MAUI
*
* Description:
* ------------
* This file implements Shortcuts application.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/**
* Copyright Notice
* ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
* Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
*  (It is illegal to remove this copyright notice from this software or any
*  portion of it)
*/
/**************************************************************

  FILENAME : Shortcuts.c
  
    PURPOSE     : Shortcuts Application
    
      REMARKS     : nil
      
        AUTHOR      : NEERAJ SHARMA
        
          DATE     : May 12,03
          
**************************************************************/
#ifdef SHORTCUTS_APP
#include "MMI_features.h"

#ifndef __DISABLE_SHORTCUTS_IMPL__
/*  Include: MMI header file */
#include "menucuigprot.h"
#include "BootupSrvGprot.h"
#include "ShortcutsProts.h"
#include "ShortcutsGProts.h"
#include "mmi_rp_app_shortcuts_def.h"
#include "mmi_rp_menu_shortcut_def.h"

#if defined(__MMI_OP12_TOOLBAR__)
#include "IdleToolbarGprot.h"
#endif

#ifdef __MMI_OP01_DCD__
#include "DCDGprot.h"
#endif

#include "SearchWebGProt.h"

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
#include "ShellApp\panel\Shortcuts\vadp_shell_shortcuts.h"
    #if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
    #include "BookmarkCuiGprot.h"
    #include "browser_api.h"
    #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */

    #ifdef __J2ME__
    #include "JavaAgencyGprot.h"
    #endif
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */

#if defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__)
#include "amgprot.h"
#include "mmi_rp_app_mre_def.h"
#endif /* defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__) */

#include "MMIDataType.h"
#include "ShortcutsDefs.h"
#include "CustMenuRes.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "string.h"
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_uiframework_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CustDataProts.h"
#include "gui_typedef.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "CommonScreensResDef.h"
#include "wgui_categories.h"
#include "wgui_include.h"
#include "Unicodexdcl.h"
#include "mmi_frm_input_gprot.h"
#include "kal_public_api.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_history_gprot.h"
#include "conversions.h"
#include "CommonScreens.h"
#if (MMI_MAX_SIM_NUM >= 3)
#include "SimSpaceGprot.h" // simspace bind
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if defined(__MMI_MRE_APP_OPERA_MINI__) && defined(__MRE_AM__)
#include "amgprot.h" // mre bind
#include "mmi_rp_app_mre_def.h"
#endif /* defined(__MMI_MRE_APP_OPERA_MINI__) && defined(__MRE_AM__) */
/*
* Define
*/

/* 
* Typedef 
*/
#ifdef __MMI_VUI_SHELL_SHORTCUTS__
    #if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
    typedef struct
    {
        MMI_ID brw_bkm_id;
        U8 title[SHCT_BRW_BKM_MAX_TITLE_LEN];
        U8 url[CUI_BKM_MAX_URL_LEN];
    } mmi_shct_brw_bkm_map_struct;
    #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
/* 
* Global Variable
*/
shct_context_struct g_shct_cntx;
extern CUSTOM_MENU *nCustMenus;

/* 
* Global Function
*/

/*
* Local Variable
*/
extern CUSTOM_MENU *nCustMenus;
U32 g_mmi_shct_max_cand_list;

/* 
* Local Function
*/
void EntryShctOptionScreen(void);
void ShctDeleteItem(void);
void ShctSetOrder(void);

/*****************************************************************************
* FUNCTION
*  mmi_shct_init
* DESCRIPTION
*  Initialises variables & Protocol Handlers for Shortcuts
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_shct_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
        {
            g_mmi_shct_max_cand_list =
                mmi_shct_get_candidate_menu_list_num();
        #ifdef __MMI_VUI_SHELL_SHORTCUTS__
            mmi_shct_create_folder();
        #endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
            break;
        }

        case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
        {
            break;
        }

        case EVT_ID_SRV_BOOTUP_COMPLETED:
        {
            ShctReadFromNvram();
        #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
            ShctReadDedicatedListFromNVRAM();
        #endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  ShctWriteToNvram
* DESCRIPTION
*  Write shortcut data to NVRAM.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctWriteToNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvramData[SHCT_NVRAM_SIZE];
    //S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvramData, 0xff, sizeof(nvramData));
    nvramData[SHCT_COUNT_BYTE] = g_shct_cntx.NumSelShct;
    nvramData[SHCT_INTEGRITY_BYTE] = 1;

    memcpy(
        (void*)&nvramData[SHCT_DATA_BYTE],
        (void*)&g_shct_cntx.SelShctList,
        sizeof(MMI_MENU_ID) * g_shct_cntx.NumSelShct);

    //WriteRecord(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
	WriteRecordSlim(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE);
}


/*****************************************************************************
* FUNCTION
*  ShctReadFromNvram
* DESCRIPTION
*  Read shortcut data from NVRAM and initialize selected shortcut list.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctReadFromNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total = 0;
    S32 i;
    U8 nvramData[SHCT_NVRAM_SIZE];
    S16 error;
    MMI_MENU_ID *nvram_shct_list = (MMI_MENU_ID*)(nvramData + SHCT_DATA_BYTE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ReadRecord(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
	ReadRecordSlim(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE);

    if (nvramData[1] == 1) // load from nvram
    {
        g_shct_cntx.Integrity = nvramData[SHCT_INTEGRITY_BYTE];

        for (i = 0; i < nvramData[SHCT_COUNT_BYTE]; i++)
        {
            MMI_MENU_ID curr_menu = nvram_shct_list[i];
            // check data available
            if (mmi_shct_get_menu_launch_func(curr_menu) != NULL &&
                mmi_shct_get_menu_string(curr_menu) != NULL)
            {
                g_shct_cntx.SelShctList[total++] = curr_menu;
            }
        }

        if (total != nvramData[SHCT_COUNT_BYTE])
        {
            nvramData[SHCT_COUNT_BYTE] = total;
            nvramData[SHCT_INTEGRITY_BYTE] = 1;
            g_shct_cntx.Integrity = 1;
            
            memcpy(
                (void*)&nvramData[SHCT_DATA_BYTE],
                (void*)&g_shct_cntx.SelShctList,
                sizeof(g_shct_cntx.SelShctList[0]) * total);
           /*
            WriteRecord(
                NVRAM_EF_SHORTCUTS_LID,
                1,
                (void*)nvramData,
                SHCT_NVRAM_SIZE,
                &error);
			*/
			WriteRecordSlim(NVRAM_EF_SHORTCUTS_LID,
                1,
                (void*)nvramData,
                SHCT_NVRAM_SIZE);
        }
    }
    else // first init, reset default
    {
        /* then copy default list to g_shct_cntx.SelShctList[] */
        for (i = 0; i < g_mmi_shct_quick_menu_default_list_num; i++)
        {
            if (mmi_shct_get_menu_launch_func(g_mmi_shct_quick_menu_default_list[i]) != NULL &&
                mmi_shct_get_menu_string(g_mmi_shct_quick_menu_default_list[i]) != NULL)
            {
                g_shct_cntx.SelShctList[total++] = g_mmi_shct_quick_menu_default_list[i];
            }
            else
            {
                continue;
            }
        }

        /* first write default list to NVRAM */
        nvramData[SHCT_COUNT_BYTE] = total;
        nvramData[SHCT_INTEGRITY_BYTE] = 1;
        g_shct_cntx.Integrity = 1;

        memcpy(
            (void*)&nvramData[SHCT_DATA_BYTE],
            (void*)&g_shct_cntx.SelShctList,
            sizeof(g_shct_cntx.SelShctList[0]) * total);
        //WriteRecord(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
		WriteRecordSlim(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE);
    }

    g_shct_cntx.NumSelShct = total;
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_launch_quick_menu_cfg
* DESCRIPTION
*  entry shortcuts screen group
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_shct_launch_quick_menu_cfg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_SHCT_QUICK_MENU_CFG,
        mmi_shct_quick_menu_cfg_scr_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    EntryShctInMainMenu();
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_launch_quick_menu_cfg_ext
* DESCRIPTION
*  entry shortcuts screen group
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_shct_launch_quick_menu_cfg_ext(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_SHCT_QUICK_MENU_CFG,
        mmi_shct_quick_menu_cfg_scr_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    EntryShctInMainMenu();
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_launch_shortcuts
* DESCRIPTION
*  entry shortcuts screen group
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_shct_quick_menu_cfg_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            g_shct_cntx.edit_list = OslMalloc(g_mmi_shct_max_cand_list * sizeof(MMI_MENU_ID));
            break;

        case EVT_ID_GROUP_EXIT:
            OslMfree(g_shct_cntx.edit_list);
            g_shct_cntx.CurrSelShct = 0;
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case EXTRA_SHORTCUTS_OPTION_ADD_MENUID:
                {
                    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_ADD;
                    if (g_shct_cntx.NumSelShct < MMI_SHCT_MAX_QUICK_MENU_LIST)
                    {
                        EntryShctEditScreen();
                    }
                    else
                    {
                        mmi_popup_display_simple_ext(
                            SHORTCUTS_FULL_MSG_STRING_ID,
                            MMI_EVENT_FAILURE,
                            GRP_ID_SHCT_QUICK_MENU_CFG,
                            NULL);
                    }
                    break;
                }

                case EXTRA_SHORTCUTS_OPTION_EDIT_MENUID:
                {
                    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_EDIT;
                    EntryShctEditScreen();
                    break;
                }

                case EXTRA_SHORTCUTS_OPTION_DELETE_MENUID:
                {
                    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_DELETE;
                    EntryShctDeleteScreen();
                    break;
                }

                case EXTRA_SHORTCUTS_OPTION_DELETEALL_MENUID:
                {
                    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_DELETE_ALL;
                    EntryShctDeleteScreen();
                    break;
                }

                case EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID:
                {
                    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_CHANGE_ORDER;
                    ShctSetOrder();
                    break;
                }

                default:
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_highlight_shortcuts
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_highlight_shortcuts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_shct_launch_quick_menu_cfg, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_shct_launch_quick_menu_cfg, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  EntryShctInMainMenu
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctInMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer;
    MMI_STR_ID ShortcutList[MMI_SHCT_MAX_QUICK_MENU_LIST];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_SHCT_QUICK_MENU_CFG, 
                        SCR_ID_SHCT_MAIN_MENU,
                        NULL,
                        (FuncPtr)EntryShctInMainMenu, 
                        MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        for (i = 0; i < g_shct_cntx.NumSelShct; i++)
        {
            ShortcutList[i] = mmi_shct_get_menu_string(g_shct_cntx.SelShctList[i]);
        }

        if (g_shct_cntx.CurrSelShct > g_shct_cntx.NumSelShct - 1)
        {
            g_shct_cntx.CurrSelShct = 0;
        }

        if(guiBuffer == NULL)
        {
            g_shct_cntx.CurrSelShct = 0;
        }

        if (g_shct_cntx.NumSelShct == 0)
        {
            g_shct_cntx.CurrOptionShct = SHR_OPTIONS_ADD;

            ShowCategory52Screen(
                MAIN_MENU_SHORTCUTS_TEXT,
                GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
                STR_GLOBAL_ADD,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                0,
                NULL,
                NULL,
                NULL,
                0,
                0,
                guiBuffer);
            SetLeftSoftkeyFunction(EntryShctEditScreen, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(EntryShctEditScreen, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
        else
        {
            RegisterHighlightHandler(ShortcutsMenuIndex);

            ShowCategory52Screen(
                MAIN_MENU_SHORTCUTS_TEXT,
                GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_shct_cntx.NumSelShct,
                ShortcutList,
                (U16*)gIndexIconsImageList,
                NULL,
                0,
                g_shct_cntx.CurrSelShct,
                guiBuffer);

            SetLeftSoftkeyFunction(EntryShctOptionScreen, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(EntryShctOptionScreen, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  ShortcutsMenuIndex
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void ShortcutsMenuIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrSelShct = (U8) index;
}


/*****************************************************************************
* FUNCTION
*  EntryShctOptionScreen
* DESCRIPTION
*  Entry the option screen of shortcuts
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctOptionScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.cui_menu_quick_menu_cfg_id = cui_menu_create_and_run(
                                                GRP_ID_SHCT_QUICK_MENU_CFG,
                                                CUI_MENU_SRC_TYPE_RESOURCE,
                                                CUI_MENU_TYPE_OPTION,
                                                EXTRA_SHORTCUTS_OPTION_MENUID,
                                                MMI_TRUE,
                                                NULL);
    cui_menu_set_default_title_image_by_id(
        g_shct_cntx.cui_menu_quick_menu_cfg_id,
        EXTRA_SHORTCUTS_MENUID);
}


/*****************************************************************************
* FUNCTION
*  EntryShctEditScreen
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctEditScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, valid_item_num;
    U8 highlighted = 0;
    U16 EditShortcutsIds[MMI_SHCT_MAX_DISPLAY_LIST];
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_shct_max_cand_list == 0)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_EMPTY,
            MMI_EVENT_FAILURE,
            GRP_ID_SHCT_QUICK_MENU_CFG,
            NULL);
        return;
    }

    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_SHCT_QUICK_MENU_CFG, 
                        SCR_ID_SHCT_EDIT,
                        NULL,
                        (FuncPtr)EntryShctEditScreen, 
                        MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        
        for (i = 0, valid_item_num = 0; i < g_mmi_shct_max_cand_list; i++)
        {
            if (mmi_shct_candidate_menu[i].menu_id != 0)
            {
                MMI_BOOL is_unreg_menu = MMI_FALSE;
                S32 j;
                for (j = 0; j < MMI_SHCT_MAX_DYNAMIC_REG_LIST; j++)
                {
                    if (g_shct_cntx.dynamic_reg_list.menu_id[j] == mmi_shct_candidate_menu[i].menu_id)
                    {
                        is_unreg_menu = MMI_TRUE;
                        break;
                    }
                }
                
                if (is_unreg_menu == MMI_TRUE)
                {
                    continue;
                }

                EditShortcutsIds[valid_item_num] = mmi_shct_get_menu_string(mmi_shct_candidate_menu[i].menu_id);
                g_shct_cntx.edit_list[valid_item_num] = mmi_shct_candidate_menu[i].menu_id;
                if (g_shct_cntx.CurrOptionShct == SHR_OPTIONS_EDIT)
                {
                    if (guiBuffer == NULL)
                    {
                        if (mmi_shct_candidate_menu[i].menu_id == mmi_shct_candidate_menu[g_shct_cntx.CurrSelShct].menu_id)
                        {
                            highlighted = valid_item_num;
                        }
                    }
                }
                valid_item_num++;
            }
        }

        RegisterHighlightHandler(HighlightShctEdit);
        ShowCategory1Screen(
            MAIN_MENU_SHORTCUTS_TEXT,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            valid_item_num,
            EditShortcutsIds,
            highlighted,
            guiBuffer);

        switch (g_shct_cntx.CurrOptionShct)
        {
            case SHR_OPTIONS_EDIT:
                g_shct_cntx.Order = g_shct_cntx.CurrSelShct + 1;
                SetLeftSoftkeyFunction(ShctSaveChanges, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(ShctSaveChanges, KEY_EVENT_UP);
                break;

            case SHR_OPTIONS_ADD:
                SetLeftSoftkeyFunction(ShctSetOrder, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(ShctSetOrder, KEY_EVENT_UP);
                break;

            default:
                break;
        }
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
}


/*****************************************************************************
* FUNCTION
*  HighlightShctEdit
* DESCRIPTION
*  Highlight handler for edit shortcut screen
* PARAMETERS
*  index           [IN]        
*  menu_id(?)      [IN]        Index of a menu item.
* RETURNS
*  string index(?)
*****************************************************************************/
void HighlightShctEdit(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrEditShct = g_shct_cntx.edit_list[index];
}


/*****************************************************************************
* FUNCTION
*  EntryShctDeleteScreen
* DESCRIPTION
*  Display confirmation screen for deleting one shortcut item.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctDeleteScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    MMI_STR_ID str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.CurrOptionShct == SHR_OPTIONS_DELETE)
    {
        str = STR_GLOBAL_DELETE_ASK;
    }
    else
    {
        str = STR_GLOBAL_DELETE_ALL_ASK;
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_SHCT_QUICK_MENU_CFG;
    arg.callback = mmi_shct_del_cnf_cb;
#ifndef __MMI_MAINLCD_96X64__
    arg.f_auto_map_empty_softkey = MMI_FALSE; 
#endif

    mmi_confirm_display_ext(
        str,
        MMI_EVENT_QUERY,
        &arg);
}


mmi_ret mmi_shct_del_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                ShctDeleteItem();
                break;

            case MMI_ALERT_CNFM_NO:
                break;

            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  ShctSetOrder
* DESCRIPTION
*  Set the shortcuts order
* PARAMETERS
*  void
*  index(?)        [IN]        List of shortcut index
* RETURNS
*  string index(?)
*****************************************************************************/
void ShctSetOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 u_limit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.Order = g_shct_cntx.CurrSelShct + 1;
    
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_SHCT_QUICK_MENU_CFG, 
                        SCR_ID_SHCT_ORDER,
                        NULL,
                        (FuncPtr)ShctSetOrder, 
                        MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        if (g_shct_cntx.CurrOptionShct == SHR_OPTIONS_ADD)
        {
            u_limit = g_shct_cntx.NumSelShct + 1;
        }
        else
        {
            u_limit = g_shct_cntx.NumSelShct;
        }
        ShowCategory87Screen(
            SHORTCUTS_CHANGE_ORDER_STRING_ID,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            u_limit,
            &g_shct_cntx.Order,
            guiBuffer);
        SetLeftSoftkeyFunction(ShctSaveChanges, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(ShctSaveChanges, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }    
}


/*****************************************************************************
* FUNCTION
*  EntryShctInIdle
* DESCRIPTION
*  entry shortcuts screen group
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctInIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OP01_FWPBW__
    mmi_popup_display_simple(
        (WCHAR*)GetString(STR_GLOBAL_EMPTY),
        MMI_EVENT_FAILURE,
        GRP_ID_SHCT_QUICK_MENU_CFG,
        NULL);
    return;
#endif /* __OP01_FWPBW__ */

    mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_SHCT_QUICK_MENU,
            NULL,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_shct_entry_quick_menu();
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_entry_quick_menu
* DESCRIPTION
*  Display shorcut list in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_shct_entry_quick_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *guiBuffer;
    MMI_STR_ID ShortcutList[MMI_SHCT_MAX_QUICK_MENU_LIST];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_SHCT_QUICK_MENU, 
                        SCR_ID_SHCT_IDLE_SHORTCUT,
                        NULL,
                        (FuncPtr)mmi_shct_entry_quick_menu, 
                        MMI_FRM_FULL_SCRN))
    {
        if (g_shct_cntx.CurrSelShct > g_shct_cntx.NumSelShct - 1)
        {
            g_shct_cntx.CurrSelShct = 0;
        }

        for (i = 0; i < g_shct_cntx.NumSelShct; i++)
        {
            ShortcutList[i] = mmi_shct_get_menu_string(g_shct_cntx.SelShctList[i]);
        }

        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        
        RegisterHighlightHandler(HighlightShctSelShortcut);

        if (g_shct_cntx.NumSelShct > 0)
        {
            ShowCategory52Screen(
                MAIN_MENU_SHORTCUTS_TEXT,
                GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_shct_cntx.NumSelShct,
                ShortcutList,
                (U16*)gIndexIconsImageList,
                NULL,
                0,
                0,
                guiBuffer);
            SetLeftSoftkeyFunction(mmi_shct_launch_app_by_quick_menu, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_shct_launch_app_by_quick_menu, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            register_menu_shortcut_selected(ShctMenuShortcut);
        }
        else
        {
            ShowCategory52Screen(
                MAIN_MENU_SHORTCUTS_TEXT,
                GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                0,
                NULL,
                NULL,
                NULL,
                0,
                0,
                guiBuffer);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  HighlightShctSelShortcut
* DESCRIPTION
*  Highlight handler for IDLE screen shortcut.
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void HighlightShctSelShortcut(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrSelShct = (U8) index;
}


/*****************************************************************************
* FUNCTION
*  ShctMenuShortcut
* DESCRIPTION
*  Shortcut handler of selected menu item
* PARAMETERS
*  index       [IN]        
*  a(?)        [IN]        Index of menu item
* RETURNS
*  void
*****************************************************************************/
void ShctMenuShortcut(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 0 && index <= g_shct_cntx.NumSelShct)
    {
        execute_left_softkey_function(KEY_EVENT_UP);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_launch_app_by_quick_menu
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_shct_launch_app_by_quick_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr launch;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    launch = mmi_shct_get_menu_launch_func(g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct]);
    if (launch != NULL)
    {
        (*launch)();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_launch_app
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_shct_launch_app(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr launch;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    launch = mmi_shct_get_menu_launch_func(menu_id);
    if (launch != NULL)
    {
        (*launch)();
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_EMPTY),
            MMI_EVENT_FAILURE,
            GRP_ID_SHCT_QUICK_MENU_CFG,
            NULL);
    }
}


/*****************************************************************************
* FUNCTION
*  ShctDeleteItem
* DESCRIPTION
*  Display confirmation screen for deleting one shortcut item.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctDeleteItem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.Integrity == 1)
    {
        switch (g_shct_cntx.CurrOptionShct)
        {
            case SHR_OPTIONS_DELETE:
                memcpy(
                    &g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct],
                    &g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct + 1],
                    (g_shct_cntx.NumSelShct - g_shct_cntx.CurrSelShct - 1) * sizeof(MMI_MENU_ID));
                g_shct_cntx.NumSelShct--;
                break;

            case SHR_OPTIONS_DELETE_ALL:
                g_shct_cntx.NumSelShct = 0;
                break;

            default:
                break;
        }
        ShctWriteToNvram();
    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE,
            GRP_ID_SHCT_QUICK_MENU_CFG,
            NULL);
    }
}


/*****************************************************************************
* FUNCTION
*  ATSetShortcuts
* DESCRIPTION
*  Set shortcutfrom AT command
* PARAMETERS
*  index       [?]         
*  inde(?)     [IN]        List of shortcut index
* RETURNS
*  string index
*****************************************************************************/
BOOL ATSetShortcuts(U8 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 ID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == NULL)
    {
        return MMI_FALSE;
    }
    
    for (i = 0; i < MMI_SHCT_MAX_QUICK_MENU_LIST; i++)
    {
        ID = index[i] - 1;
        if (ID < g_mmi_shct_max_cand_list)
        {
            g_shct_cntx.SelShctList[i] = mmi_shct_candidate_menu[ID].menu_id;
        }
    }
    
    ShctWriteToNvram();
    
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  ShctSaveChanges
* DESCRIPTION
*  Save change of shorcut
* PARAMETERS
*  void
*  index(?)        [IN]        List of shortcut index
* RETURNS
*  string index(?)
*****************************************************************************/
void ShctSaveChanges(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_MENU_ID temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_shct_cntx.CurrOptionShct)
    {
    case SHR_OPTIONS_EDIT:
        g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct] = g_shct_cntx.CurrEditShct;
        break;
        
    case SHR_OPTIONS_CHANGE_ORDER:
        temp = g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct];
        if (g_shct_cntx.Order < g_shct_cntx.CurrSelShct + 1)
        {
            /* move (order-1) ~ (current select item-1) to next position */
            for (i = g_shct_cntx.CurrSelShct; i >= g_shct_cntx.Order; i--)
            {
                memcpy(&g_shct_cntx.SelShctList[i], &g_shct_cntx.SelShctList[i - 1], sizeof(MMI_MENU_ID));
            }
        }
        else
        {
            memcpy(
                &g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct],
                &g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct + 1],
                sizeof(MMI_MENU_ID) * (g_shct_cntx.Order - (g_shct_cntx.CurrSelShct + 1)));
        }
        g_shct_cntx.SelShctList[g_shct_cntx.Order - 1] = temp;
        g_shct_cntx.CurrSelShct = g_shct_cntx.Order - 1;
        break;
        
    case SHR_OPTIONS_ADD:
        for (i = g_shct_cntx.NumSelShct - 1; i >= g_shct_cntx.Order - 1; i--)
        {
            memcpy(&g_shct_cntx.SelShctList[i + 1], &g_shct_cntx.SelShctList[i], sizeof(MMI_MENU_ID));
        }
        
        g_shct_cntx.SelShctList[g_shct_cntx.Order - 1] =g_shct_cntx.CurrEditShct;
        
        g_shct_cntx.NumSelShct++;
        g_shct_cntx.CurrSelShct = g_shct_cntx.Order -1;
        break;
    default:
        break;
    }
    ShctWriteToNvram();
    mmi_frm_close_to_root_screen(GRP_ID_SHCT_QUICK_MENU_CFG);
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_get_item_string
* DESCRIPTION
*  Display popup screen with corresponding messages.
* PARAMETERS
*  Msg     [IN]        Enum value of message type.
* RETURNS
*  void
*****************************************************************************/
MMI_STR_ID mmi_shct_get_menu_string(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetStringIdOfItem(menu_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_get_item_icon
* DESCRIPTION
*  Display popup screen with corresponding messages.
* PARAMETERS
*  Msg     [IN]        Enum value of message type.
* RETURNS
*  void
*****************************************************************************/
MMI_IMG_ID mmi_shct_get_menu_icon(MMI_MENU_ID menu_id, mmi_shct_display_type_enum display_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_IMG_ID img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (display_type)
    {
        case MMI_SHCT_DISPLAY_TYPE_CANDIDATE:
        case MMI_SHCT_DISPLAY_TYPE_QUICK_MENU:
            for (i = 0; i < g_mmi_shct_max_cand_list; i++)
            {
                if (menu_id == mmi_shct_candidate_menu[i].menu_id)
                {
                    return mmi_shct_candidate_menu[i].img_id;
                }
            }
            break;

        case MMI_SHCT_DISPLAY_TYPE_VENUS_SHELL:
            break;
    }

    img_id = (MMI_IMG_ID)GetImageIdOfItem(menu_id);
    if (img_id > 0)
    {
        return img_id;
    }

    img_id = (MMI_IMG_ID)GetImageIdOfItem(GetParentItemId(menu_id));
    if (img_id > 0)
    {
        return img_id;
    }

    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_get_item_launch_func
* DESCRIPTION
*  Display popup screen with corresponding messages.
* PARAMETERS
*  Msg     [IN]        Enum value of message type.
* RETURNS
*  void
*****************************************************************************/
FuncPtr mmi_shct_get_menu_launch_func(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_id == 0)
    {
        return NULL;
    }
    for (i = 0; i < MMI_SHCT_MAX_DYNAMIC_REG_LIST; i++)
    {
        if (g_shct_cntx.dynamic_reg_list.menu_id[i] == menu_id)
        {
            return NULL;
        }
    }

    for (i = 0; i < g_mmi_shct_max_cand_list; i++)
    {
        if (menu_id == mmi_shct_candidate_menu[i].menu_id)
        {
            return mmi_shct_candidate_menu[i].launch_func;
        }
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_menu_handler
* DESCRIPTION
*  Handle the phone setting shortcut menu CUI
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_shct_menu_handler(cui_menu_event_struct *event, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_CUI_MENU_ITEM_SELECT &&
        event->highlighted_menu_id == EXTRA_SHORTCUTS_MENUID)
    {
        mmi_shct_launch_quick_menu_cfg_ext(parent_gid);
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_DONT_CARE;
    }
}


#ifdef __MMI_VRSI__
U32 mmi_shct_get_candidate_list_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_shct_max_cand_list;
}


MMI_STR_ID mmi_shct_get_str_by_candidate_list_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < g_mmi_shct_max_cand_list)
    {
        return mmi_shct_candidate_menu[index].str_id;
    }
    else
    {
        return 0;
    }
}


void mmi_shct_launch_app_by_candidate_list_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_shct_launch_app(mmi_shct_candidate_menu[index].menu_id);
}
#endif /* __MMI_VRSI__ */

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
void mmi_shct_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_hdl = FS_Open(SHCT_FOLDER_NAME, FS_READ_ONLY | FS_OPEN_DIR);

    if (fs_hdl >= FS_NO_ERROR)
    {
        FS_Close(fs_hdl);
    }
    else
    {
        FS_CreateDir(SHCT_FOLDER_NAME);
    }
}


void mmi_shct_del_system_maping_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __J2ME__
    FS_Delete(SHCT_JAVA_MID_MAP_FILE_NAME);
#endif
#if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
    FS_Delete(SHCT_BRW_BKM_MAP_FILE_NAME);
#endif
}


#ifdef __J2ME__
void mmi_shct_entry_java_sel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_entry_sel_list_screen(mmi_shct_java_sel_cb);
}


void mmi_shct_java_sel_cb(mmi_java_select_mids_info_struct *sel_mids_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID java_mid_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((SHCT_JAVA_MID_STORAGE_NAME_LEN-2)/2 > mmi_wcslen(sel_mids_info->storage_name));
    java_mid_id = mmi_shct_add_java_mid_id_to_map_file((CHAR*)sel_mids_info->storage_name);
#ifdef __MMI_VUI_SHELL_SHORTCUTS__
    vadp_shell_shct_java_sel_cb(java_mid_id);
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
}


void mmi_shct_java_del_notify(CHAR *java_mid_storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID java_mid_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    java_mid_id = mmi_shct_get_java_mid_id_from_map_file(java_mid_storage_name);
#ifdef __MMI_VUI_SHELL_SHORTCUTS__
    vadp_shell_shct_java_del_notify(java_mid_id);
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
}


void mmi_shct_java_launch_midlet(MMI_ID java_mid_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR java_mid_storage_name[SHCT_JAVA_MID_STORAGE_NAME_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_shct_get_java_storage_name_from_map_file(java_mid_id, java_mid_storage_name);
    mmi_java_launch_midlet(java_mid_storage_name);
}


WCHAR *mmi_shct_get_java_midlet_str(MMI_ID java_mid_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR java_mid_storage_name[SHCT_JAVA_MID_STORAGE_NAME_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_shct_get_java_storage_name_from_map_file(java_mid_id, java_mid_storage_name);
    return (WCHAR*)mmi_java_get_name_from_storage_name(java_mid_storage_name);
}


CHAR *mmi_shct_get_java_midlet_icon(MMI_ID java_mid_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR java_mid_storage_name[SHCT_JAVA_MID_STORAGE_NAME_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_shct_get_java_storage_name_from_map_file(java_mid_id, java_mid_storage_name);
    return mmi_java_get_icon_from_storage_name(java_mid_storage_name);
}


MMI_ID mmi_shct_add_java_mid_id_to_map_file(CHAR *mids_storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shct_java_mid_map_struct *mid_map;
    FS_HANDLE mid_map_hdl;
    MMI_ID mid_id = 0;
    U32 fs_read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mid_map_hdl = FS_Open(SHCT_JAVA_MID_MAP_FILE_NAME, FS_READ_WRITE | FS_CREATE);
    if (mid_map_hdl < 0)
    {
        FS_Delete(SHCT_JAVA_MID_MAP_FILE_NAME);
        return 0;
    }
    mid_map = (mmi_shct_java_mid_map_struct*)OslMalloc(sizeof(mmi_shct_java_mid_map_struct));
    memset(
        mid_map,
        0x00,
        sizeof(mmi_shct_java_mid_map_struct));

    if (FS_NO_ERROR == FS_Read(
                        mid_map_hdl,
                        mid_map,
                        sizeof(mmi_shct_java_mid_map_struct),
                        &fs_read_len))
    {
        /* empty file */
        if (fs_read_len < sizeof(mmi_shct_java_mid_map_struct) ||
            (fs_read_len == sizeof(mmi_shct_java_mid_map_struct) && mid_map->java_mid_id == 0))
        {
            mid_id = 1;
            mmi_wcscpy(
                (WCHAR*)mid_map->java_mid_storage_name,
                (WCHAR*)mids_storage_name);
            mid_map->java_mid_id = mid_id;
            FS_Seek(
                mid_map_hdl,
                0,
                FS_FILE_BEGIN);
            FS_Write(
                mid_map_hdl,
                mid_map,
                sizeof(mmi_shct_java_mid_map_struct),
                NULL);
        }
        else /* not empty */
        {
            FS_Seek(
                mid_map_hdl,
                0,
                FS_FILE_BEGIN);
            while (FS_NO_ERROR == FS_Read(
                                mid_map_hdl,
                                mid_map,
                                sizeof(mmi_shct_java_mid_map_struct),
                                &fs_read_len))
            {
                if (fs_read_len < sizeof(mmi_shct_java_mid_map_struct) || mid_map->java_mid_id == 0)
                {
                    /* find out the last item */
                    FS_Seek(
                        mid_map_hdl,
                        0 - fs_read_len - sizeof(mmi_shct_java_mid_map_struct),
                        FS_FILE_CURRENT);

                    if (FS_NO_ERROR == FS_Read(
                                        mid_map_hdl,
                                        mid_map,
                                        sizeof(mmi_shct_java_mid_map_struct),
                                        &fs_read_len))
                    {
                        mid_id = mid_map->java_mid_id + 1;
                        mmi_wcscpy(
                            (WCHAR*)mid_map->java_mid_storage_name,
                            (WCHAR*)mids_storage_name);
                        mid_map->java_mid_id = mid_id;
                        
                        FS_Write(
                            mid_map_hdl,
                            mid_map,
                            sizeof(mmi_shct_java_mid_map_struct),
                            NULL);
                        break;
                    }
                    else
                    {
                        FS_Close(mid_map_hdl);
                        FS_Delete(SHCT_JAVA_MID_MAP_FILE_NAME);
                        OslMfree(mid_map);
                        return 0;
                    }
                    break;
                }
                else if (0 == mmi_wcscmp((WCHAR*)mids_storage_name, (WCHAR*)mid_map->java_mid_storage_name))
                {
                    mid_id = mid_map->java_mid_id;
                    FS_Close(mid_map_hdl);
                    OslMfree(mid_map);
                    return mid_id;
                }
            }
        }
    }
    else
    {
        FS_Close(mid_map_hdl);
        FS_Delete(SHCT_JAVA_MID_MAP_FILE_NAME);
        OslMfree(mid_map);
        return 0;
    }

    FS_Close(mid_map_hdl);
    OslMfree(mid_map);
    return mid_id;
}


void mmi_shct_get_java_storage_name_from_map_file(const MMI_ID java_mid_id, CHAR *mids_storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shct_java_mid_map_struct *mid_map;
    FS_HANDLE mid_map_hdl;
    U32 fs_read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mid_map_hdl = FS_Open(SHCT_JAVA_MID_MAP_FILE_NAME, FS_READ_ONLY);
    if (mid_map_hdl < 0)
    {
        FS_Delete(SHCT_JAVA_MID_MAP_FILE_NAME);
        return;
    }

    mid_map = (mmi_shct_java_mid_map_struct*)OslMalloc(sizeof(mmi_shct_java_mid_map_struct));
    memset(
        mid_map,
        0x00,
        sizeof(mmi_shct_java_mid_map_struct));

    while (FS_NO_ERROR == FS_Read(
                        mid_map_hdl,
                        mid_map,
                        sizeof(mmi_shct_java_mid_map_struct),
                        &fs_read_len))
    {
        if (fs_read_len < sizeof(mmi_shct_java_mid_map_struct))
        {
            break;
        }

        if (mid_map->java_mid_id == java_mid_id)
        {
            mmi_wcscpy(
                (WCHAR*)mids_storage_name,
                (WCHAR*)mid_map->java_mid_storage_name);
            break;
        }
    }

    FS_Close(mid_map_hdl);
    OslMfree(mid_map);
    return;
}


MMI_ID mmi_shct_get_java_mid_id_from_map_file(CHAR *mids_storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shct_java_mid_map_struct *mid_map;
    FS_HANDLE mid_map_hdl;
    U32 fs_read_len;
    MMI_ID mid_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mid_map_hdl = FS_Open(SHCT_JAVA_MID_MAP_FILE_NAME, FS_READ_ONLY);
    if (mid_map_hdl < 0)
    {
        return 0;
    }

    mid_map = (mmi_shct_java_mid_map_struct*)OslMalloc(sizeof(mmi_shct_java_mid_map_struct));
    memset(
        mid_map,
        0x00,
        sizeof(mmi_shct_java_mid_map_struct));

    while (FS_NO_ERROR == FS_Read(
                        mid_map_hdl,
                        mid_map,
                        sizeof(mmi_shct_java_mid_map_struct),
                        &fs_read_len))
    {
        if (fs_read_len < sizeof(mmi_shct_java_mid_map_struct))
        {
            mid_id = 0;
            break;
        }

        if (0 == mmi_wcscmp((WCHAR*)mids_storage_name, (WCHAR*)mid_map->java_mid_storage_name))
        {
            mid_id = mid_map->java_mid_id;
            break;
        }
    }

    FS_Close(mid_map_hdl);
    OslMfree(mid_map);
    return mid_id;
}


void mmi_shct_del_java_mid_id_in_map_file(MMI_ID mid_id)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shct_java_mid_map_struct *mid_map;
    FS_HANDLE mid_map_hdl;
    U32 fs_read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mid_map_hdl = FS_Open(SHCT_JAVA_MID_MAP_FILE_NAME, FS_READ_WRITE);
    if (mid_map_hdl < 0)
    {
        return;
    }

    mid_map = (mmi_shct_java_mid_map_struct*)OslMalloc(sizeof(mmi_shct_java_mid_map_struct));
    memset(
        mid_map,
        0x00,
        sizeof(mmi_shct_java_mid_map_struct));

    while (FS_NO_ERROR == FS_Read(
                        mid_map_hdl,
                        mid_map,
                        sizeof(mmi_shct_java_mid_map_struct),
                        &fs_read_len))
    {
        if (fs_read_len < sizeof(mmi_shct_java_mid_map_struct) ||
            mid_map->java_mid_id == 0)
        {
            break;
        }

        if (mid_id == mid_map->java_mid_id)
        {
            /* replace */
            while (FS_NO_ERROR == FS_Read(
                        mid_map_hdl,
                        mid_map,
                        sizeof(mmi_shct_java_mid_map_struct),
                        &fs_read_len))
            {
                if (fs_read_len < sizeof(mmi_shct_java_mid_map_struct) ||
                    mid_map->java_mid_id == 0)
                {
                    FS_Seek(
                        mid_map_hdl,
                        0 - sizeof(mmi_shct_java_mid_map_struct) - fs_read_len,
                        FS_FILE_CURRENT);
                    memset(mid_map, 0x00, sizeof(mmi_shct_java_mid_map_struct));
                    FS_Write(
                        mid_map_hdl,
                        mid_map,
                        sizeof(mmi_shct_java_mid_map_struct),
                        NULL);
                    break;
                }
    
                FS_Seek(
                    mid_map_hdl,
                    0 - 2 * sizeof(mmi_shct_java_mid_map_struct),
                    FS_FILE_CURRENT);

                FS_Write(
                    mid_map_hdl,
                    mid_map,
                    sizeof(mmi_shct_java_mid_map_struct),
                    NULL);

                FS_Seek(
                    mid_map_hdl,
                    sizeof(mmi_shct_java_mid_map_struct),
                    FS_FILE_CURRENT);
            }
            break;
        }
    }

    /* remove the maping file if it's empty */
    FS_Seek(
        mid_map_hdl,
        0,
        FS_FILE_BEGIN);
    FS_Read(
        mid_map_hdl,
        mid_map,
        sizeof(mmi_shct_java_mid_map_struct),
        &fs_read_len);
    if (mid_map->java_mid_id == 0)
    {
        FS_Close(mid_map_hdl);
        FS_Delete(SHCT_JAVA_MID_MAP_FILE_NAME);
    }
    else
    {
        FS_Close(mid_map_hdl);
    }

    OslMfree(mid_map);
    return;
}
#endif /* __J2ME__ */


#if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
void mmi_shct_entry_brw_bkm_sel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    MMI_ID bkm_sel_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN,
            mmi_shct_brw_bkm_sel_cb,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    bkm_sel_id = cui_bkm_sel_bkm_create(gid);
    if (bkm_sel_id != GRP_ID_INVALID)
    {
        cui_bkm_sel_bkm_run(bkm_sel_id);
    }
    else
    {
        mmi_frm_group_close(gid);
    }
}


mmi_ret mmi_shct_brw_bkm_sel_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_bkm_sel_bkm_result_evt_struct *bmk_evt = (cui_bkm_sel_bkm_result_evt_struct*)evt;
    MMI_ID brw_bkm_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_BKM_ADD_BKM_CLOSE:
            cui_bkm_sel_bkm_close(bmk_evt->sender_id);
            break;

        case EVT_ID_CUI_BKM_SEL_BKM_RESULT:
        {
            if (bmk_evt->selected_utf8_url != NULL)
            {
                brw_bkm_id = mmi_shct_brw_bkm_save(bmk_evt->selected_utf8_title, bmk_evt->selected_utf8_url);
            #ifdef __MMI_VUI_SHELL_SHORTCUTS__
                vadp_shell_shct_brw_bkm_sel_cb(brw_bkm_id);
            #endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
            }

            cui_bkm_sel_bkm_close(bmk_evt->sender_id);
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


MMI_ID mmi_shct_brw_bkm_save(U8 *title, U8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shct_brw_bkm_map_struct brw_bkm_map_info;
    FS_HANDLE fs_hdl;
    U32 fs_read_len;
    S32 title_len = strlen(title) < SHCT_BRW_BKM_MAX_TITLE_LEN ? strlen(title) : SHCT_BRW_BKM_MAX_TITLE_LEN;
    S32 url_len = strlen(url) < CUI_BKM_MAX_URL_LEN ? strlen(url) : CUI_BKM_MAX_URL_LEN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the bkm id */
    fs_hdl = FS_Open(SHCT_BRW_BKM_MAP_FILE_NAME, FS_READ_WRITE | FS_CREATE);
    if (fs_hdl < 0)
    {
        FS_Delete(SHCT_BRW_BKM_MAP_FILE_NAME);
        return 0;
    }
    memset(
        &brw_bkm_map_info,
        0x00,
        sizeof(mmi_shct_brw_bkm_map_struct));

    if (FS_NO_ERROR == FS_Read(
                        fs_hdl,
                        &brw_bkm_map_info,
                        sizeof(mmi_shct_brw_bkm_map_struct),
                        &fs_read_len))
    {
        /* empty file */
        if (fs_read_len < sizeof(mmi_shct_brw_bkm_map_struct) ||
            (fs_read_len == sizeof(mmi_shct_brw_bkm_map_struct) && brw_bkm_map_info.brw_bkm_id == 0))
        {
            brw_bkm_map_info.brw_bkm_id = 1;
            strncpy(brw_bkm_map_info.title, title, title_len);
            strncpy(brw_bkm_map_info.url, url, url_len);
            FS_Seek(
                fs_hdl,
                0,
                FS_FILE_BEGIN);
            FS_Write(
                fs_hdl,
                &brw_bkm_map_info,
                sizeof(mmi_shct_brw_bkm_map_struct),
                NULL);
        }
        else /* not empty */
        {
            FS_Seek(
                fs_hdl,
                0,
                FS_FILE_BEGIN);
            while (FS_NO_ERROR == FS_Read(
                                    fs_hdl,
                                    &brw_bkm_map_info,
                                    sizeof(mmi_shct_brw_bkm_map_struct),
                                    &fs_read_len))
            {
                if (fs_read_len < sizeof(mmi_shct_brw_bkm_map_struct) || brw_bkm_map_info.brw_bkm_id == 0)
                {
                    /* find out the last non-empty item */
                    FS_Seek(
                        fs_hdl,
                        0 - fs_read_len - sizeof(mmi_shct_brw_bkm_map_struct),
                        FS_FILE_CURRENT);

                    if (FS_NO_ERROR == FS_Read(
                                        fs_hdl,
                                        &brw_bkm_map_info,
                                        sizeof(mmi_shct_brw_bkm_map_struct),
                                        &fs_read_len))
                    {
                        mmi_shct_brw_bkm_map_struct map_info;
                        memset(&map_info, 0x00, sizeof(mmi_shct_brw_bkm_map_struct));
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
                        #endif
                        map_info.brw_bkm_id = ++brw_bkm_map_info.brw_bkm_id;
                        strncpy(map_info.title, title, title_len);
                        strncpy(map_info.url, url, url_len);
                        
                        FS_Write(
                            fs_hdl,
                            &map_info,
                            sizeof(mmi_shct_brw_bkm_map_struct),
                            NULL);
                        break;
                    }
                    else
                    {
                        FS_Close(fs_hdl);
                        FS_Delete(SHCT_BRW_BKM_MAP_FILE_NAME);
                        return 0;
                    }
                    break;
                }
                else if (0 == strncmp(brw_bkm_map_info.title, title, SHCT_BRW_BKM_MAX_TITLE_LEN) &&
                         0 == strncmp(brw_bkm_map_info.url, url, CUI_BKM_MAX_URL_LEN))
                {
                    break;
                }
            }
        }
    }
    else
    {
        FS_Close(fs_hdl);
        FS_Delete(SHCT_BRW_BKM_MAP_FILE_NAME);
        return 0;
    }

    FS_Close(fs_hdl);
    return brw_bkm_map_info.brw_bkm_id;
}


void mmi_shct_brw_bkm_del_url(MMI_ID brw_bkm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shct_brw_bkm_map_struct brw_bkm_map_info;
    FS_HANDLE fs_hdl;
    U32 fs_read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_hdl = FS_Open(SHCT_BRW_BKM_MAP_FILE_NAME, FS_READ_WRITE);
    if (fs_hdl < 0)
    {
        return;
    }

    memset(
        &brw_bkm_map_info,
        0x00,
        sizeof(mmi_shct_brw_bkm_map_struct));

    while (FS_NO_ERROR == FS_Read(
                            fs_hdl,
                            &brw_bkm_map_info,
                            sizeof(mmi_shct_brw_bkm_map_struct),
                            &fs_read_len))
    {
        if (fs_read_len < sizeof(mmi_shct_brw_bkm_map_struct) ||
            brw_bkm_map_info.brw_bkm_id == 0)
        {
            break;
        }

        if (brw_bkm_id == brw_bkm_map_info.brw_bkm_id)
        {
            /* replace with emtpy buffer */
            while (FS_NO_ERROR == FS_Read(
                                    fs_hdl,
                                    &brw_bkm_map_info,
                                    sizeof(mmi_shct_brw_bkm_map_struct),
                                    &fs_read_len))
            {
                /* end of */
                if (fs_read_len < sizeof(mmi_shct_brw_bkm_map_struct) ||
                    brw_bkm_map_info.brw_bkm_id == 0)
                {
                    FS_Seek(
                        fs_hdl,
                        0 - sizeof(mmi_shct_brw_bkm_map_struct) - fs_read_len,
                        FS_FILE_CURRENT);
                    memset(&brw_bkm_map_info, 0x00, sizeof(mmi_shct_brw_bkm_map_struct));
                    FS_Write(
                        fs_hdl,
                        &brw_bkm_map_info,
                        sizeof(mmi_shct_brw_bkm_map_struct),
                        NULL);
                    break;
                }

                /* fill up the empty space with the following items */
                FS_Seek(
                    fs_hdl,
                    0 - 2 * sizeof(mmi_shct_brw_bkm_map_struct),
                    FS_FILE_CURRENT);

                FS_Write(
                    fs_hdl,
                    &brw_bkm_map_info,
                    sizeof(mmi_shct_brw_bkm_map_struct),
                    NULL);

                FS_Seek(
                    fs_hdl,
                    sizeof(mmi_shct_brw_bkm_map_struct),
                    FS_FILE_CURRENT);
            }
            break;
        }
    }

    /* remove the file if it's emtpy */
    FS_Seek(
        fs_hdl,
        0,
        FS_FILE_BEGIN);
    FS_Read(
        fs_hdl,
        &brw_bkm_map_info,
        sizeof(mmi_shct_brw_bkm_map_struct),
        &fs_read_len);
    if (brw_bkm_map_info.brw_bkm_id == 0)
    {
        FS_Close(fs_hdl);
        FS_Delete(SHCT_BRW_BKM_MAP_FILE_NAME);
    }
    else
    {
        FS_Close(fs_hdl);
    }

    return;
}


void mmi_shct_brw_bkm_get_title(MMI_ID brw_bkm_id, U8 *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shct_brw_bkm_map_struct brw_bkm_map_info;
    FS_HANDLE fs_hdl;
    U32 fs_read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_hdl = FS_Open(SHCT_BRW_BKM_MAP_FILE_NAME, FS_READ_ONLY);
    if (fs_hdl < 0)
    {
        FS_Delete(SHCT_BRW_BKM_MAP_FILE_NAME);
        return;
    }

    memset(
        &brw_bkm_map_info,
        0x00,
        sizeof(mmi_shct_brw_bkm_map_struct));

    while (FS_NO_ERROR == FS_Read(
                            fs_hdl,
                            &brw_bkm_map_info,
                            sizeof(mmi_shct_brw_bkm_map_struct),
                            &fs_read_len))
    {
        if (fs_read_len < sizeof(mmi_shct_brw_bkm_map_struct))
        {
            break;
        }

        if (brw_bkm_map_info.brw_bkm_id == brw_bkm_id)
        {
            strncpy(title, brw_bkm_map_info.title, SHCT_BRW_BKM_MAX_TITLE_LEN);
            break;
        }
    }

    FS_Close(fs_hdl);
    return;
}


void mmi_shct_brw_bkm_get_url(MMI_ID brw_bkm_id, U8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shct_brw_bkm_map_struct brw_bkm_map_info;
    FS_HANDLE fs_hdl;
    U32 fs_read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_hdl = FS_Open(SHCT_BRW_BKM_MAP_FILE_NAME, FS_READ_ONLY);
    if (fs_hdl < 0)
    {
        FS_Delete(SHCT_BRW_BKM_MAP_FILE_NAME);
        return;
    }

    memset(
        &brw_bkm_map_info,
        0x00,
        sizeof(mmi_shct_brw_bkm_map_struct));

    while (FS_NO_ERROR == FS_Read(
                            fs_hdl,
                            &brw_bkm_map_info,
                            sizeof(mmi_shct_brw_bkm_map_struct),
                            &fs_read_len))
    {
        if (fs_read_len < sizeof(mmi_shct_brw_bkm_map_struct))
        {
            break;
        }

        if (brw_bkm_map_info.brw_bkm_id == brw_bkm_id)
        {
            strncpy(url, brw_bkm_map_info.url, CUI_BKM_MAX_URL_LEN);
            break;
        }
    }

    FS_Close(fs_hdl);
    return;
}


void mmi_shct_brw_bkm_get_display_str(MMI_ID brw_bkm_id, WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 utf8_title[SHCT_BRW_BKM_MAX_TITLE_LEN];
    U8 utf8_url[CUI_BKM_MAX_URL_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(utf8_title, 0x00, SHCT_BRW_BKM_MAX_TITLE_LEN);
    memset(utf8_url, 0x00, CUI_BKM_MAX_URL_LEN);
    mmi_shct_brw_bkm_get_title(brw_bkm_id, utf8_title);
    if (utf8_title[0] != 0)
    {
        mmi_chset_utf8_to_ucs2_string((U8*)string, SHCT_BRW_BKM_MAX_DISPLAY_LEN, utf8_title);
    }
    else
    {
        mmi_shct_brw_bkm_get_url(brw_bkm_id, utf8_url);
        mmi_chset_utf8_to_ucs2_string((U8*)string, SHCT_BRW_BKM_MAX_DISPLAY_LEN, utf8_url);
    }
}


void mmi_shct_brw_bkm_launch_url(MMI_ID brw_bkm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_url[CUI_BKM_MAX_URL_LEN];
    WCHAR url[CUI_BKM_MAX_URL_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_url, 0x00, CUI_BKM_MAX_URL_LEN);
    mmi_shct_brw_bkm_get_url(brw_bkm_id, temp_url);
    mmi_asc_to_wcs(url, temp_url);
    wap_start_browser(WAP_BROWSER_GOTO_URL, (U8*)url);
}
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */


#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
/*****************************************************************************
* FUNCTION
*  mmi_shct_launch_dedicated_key
* DESCRIPTION
*  Shortcut handler of selected menu item
* PARAMETERS
*  index       [IN]        
*  a(?)        [IN]        Index of menu item
* RETURNS
*  void
*****************************************************************************/
void mmi_shct_launch_dedicated_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_shct_launch_dedicated_key_ext(GRP_ID_ROOT);
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_launch_dedicated_key_ext
* DESCRIPTION
*  Shortcut handler of selected menu item
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void mmi_shct_launch_dedicated_key_ext(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_SHCT_DEDICATED_KEY_CFG,
        mmi_shct_dedicated_key_cfg_scr_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
#ifdef __MMI_OP01_DCD__
    if(mmi_dcd_is_switch_on() && mmi_dcd_is_idle_on())
    {
        mmi_popup_display_simple_ext(
            SHORTCUTS_DCD_CONFLICT_WARNING_ID,
            MMI_EVENT_FAILURE,
            GRP_ID_SHCT_DEDICATED_KEY_CFG,
            NULL);
        return;
    }
#endif
    cui_menu_id = cui_menu_create_and_run(
                GRP_ID_SHCT_DEDICATED_KEY_CFG,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_APPMAIN,
                MENU_SETTING_DEDICATED_KEYS,
                MMI_TRUE,
                NULL);

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    cui_menu_set_item_hidden(
        cui_menu_id,
        MENU_SETTING_DEDICATED_UP_KEY,
        MMI_TRUE);
    cui_menu_set_item_hidden(
        cui_menu_id,
        MENU_SETTING_DEDICATED_DOWN_KEY,
        MMI_TRUE);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_dedicated_key_cfg_scr_group_proc
* DESCRIPTION
*  entry shortcuts screen group
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_shct_dedicated_key_cfg_scr_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            g_shct_cntx.edit_list = OslMalloc((g_mmi_shct_max_cand_list+1) * sizeof(MMI_MENU_ID));
            break;

        case EVT_ID_GROUP_EXIT:
            OslMfree(g_shct_cntx.edit_list);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_default_title_image_by_id(
                menu_evt->sender_id,
                GetRootTitleIcon(MENU_SETTING_DEDICATED_KEYS));

            cui_menu_set_currlist_left_softkey(
                menu_evt->sender_id,
                (WCHAR*)GetString(STR_GLOBAL_EDIT));
        #ifdef __OP01_FWPBW__
            wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
            cui_menu_set_item_string(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_UP_KEY,
                mmi_shct_get_nav_key_str(DEDICATED_KEY_UP));

        #ifdef __MMI_SEARCH_WEB__
            if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY) &&
                mmi_search_web_get_application_name(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY) != NULL)
            {
            #ifdef __MMI_SEARCH_WEB_GOOGLE__
                cui_menu_set_item_hidden(
                    menu_evt->sender_id,
                    MENU_SETTING_DEDICATED_DOWN_KEY,
                    MMI_TRUE);
            #else /* __MMI_SEARCH_WEB_GOOGLE__ */
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MENU_SETTING_DEDICATED_DOWN_KEY,
                    (WCHAR*)mmi_search_web_get_application_name(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY));
            #endif /* __MMI_SEARCH_WEB_GOOGLE__ */
            }
            else
            {
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    MENU_SETTING_DEDICATED_DOWN_KEY,
                    mmi_shct_get_nav_key_str(DEDICATED_KEY_DOWN));
            }
        #else /* __MMI_SEARCH_WEB__ */
            cui_menu_set_item_string(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_DOWN_KEY,
                mmi_shct_get_nav_key_str(DEDICATED_KEY_DOWN));
        #endif /* __MMI_SEARCH_WEB__ */

        #if (MMI_MAX_SIM_NUM >= 3)
            cui_menu_set_item_string(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_LEFT_KEY,
                (WCHAR*)GetString(STR_ID_SIM_SPACE));
        #else /* MMI_MAX_SIM_NUM >= 3 */
            cui_menu_set_item_string(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_LEFT_KEY,
                mmi_shct_get_nav_key_str(DEDICATED_KEY_LEFT));
        #endif /* MMI_MAX_SIM_NUM >= 3 */

        #if defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__)
            cui_menu_set_item_string(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_RIGHT_KEY,
                (WCHAR*)GetString(STR_MRE_OPERA_MINI));
        #else /* defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__) */
            cui_menu_set_item_string(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_RIGHT_KEY,
                mmi_shct_get_nav_key_str(DEDICATED_KEY_RIGHT));
        #endif /* defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__) */
        #else /* __OP01_FWPBW__ */
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_UP_KEY,
                mmi_shct_get_nav_key_str(DEDICATED_KEY_UP));

        #ifdef __MMI_SEARCH_WEB__
            if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY) &&
                mmi_search_web_get_application_name(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY) != NULL)
            {
            #ifdef __MMI_SEARCH_WEB_GOOGLE__
                cui_menu_set_item_hidden(
                    menu_evt->sender_id,
                    MENU_SETTING_DEDICATED_DOWN_KEY,
                    MMI_TRUE);
            #else /* __MMI_SEARCH_WEB_GOOGLE__ */
                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_SETTING_DEDICATED_DOWN_KEY,
                    (WCHAR*)mmi_search_web_get_application_name(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY));
            #endif /* __MMI_SEARCH_WEB_GOOGLE__ */
            }
            else
            {
                cui_menu_set_item_hint(
                    menu_evt->sender_id,
                    MENU_SETTING_DEDICATED_DOWN_KEY,
                    mmi_shct_get_nav_key_str(DEDICATED_KEY_DOWN));
            }
        #else /* __MMI_SEARCH_WEB__ */
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_DOWN_KEY,
                mmi_shct_get_nav_key_str(DEDICATED_KEY_DOWN));
        #endif /* __MMI_SEARCH_WEB__ */

        #if (MMI_MAX_SIM_NUM >= 3)
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_LEFT_KEY,
                (WCHAR*)GetString(STR_ID_SIM_SPACE));
        #else /* MMI_MAX_SIM_NUM >= 3 */
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_LEFT_KEY,
                mmi_shct_get_nav_key_str(DEDICATED_KEY_LEFT));
        #endif /* MMI_MAX_SIM_NUM >= 3 */

        #if defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__)
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_RIGHT_KEY,
                (WCHAR*)GetString(STR_MRE_OPERA_MINI));
        #else /* defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__) */
            cui_menu_set_item_hint(
                menu_evt->sender_id,
                MENU_SETTING_DEDICATED_RIGHT_KEY,
                mmi_shct_get_nav_key_str(DEDICATED_KEY_RIGHT));
        #endif /* defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__) */
        #endif /* __OP01_FWPBW__ */
            break;
        }

    #ifdef __OP01_FWPBW__
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {
            wgui_restore_list_menu_slim_style();
            break;
        }
    #endif /* __OP01_FWPBW__ */

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            SetCenterSoftkeyFunction(EntryShctEditDedicatedKey, KEY_EVENT_UP);
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_SETTING_DEDICATED_UP_KEY:
                    g_shct_cntx.CurrSelArrow = DEDICATED_KEY_UP;
                    break;
                    
                case MENU_SETTING_DEDICATED_DOWN_KEY:
                    g_shct_cntx.CurrSelArrow = DEDICATED_KEY_DOWN;
                    break;
                    
                case MENU_SETTING_DEDICATED_LEFT_KEY:
                    g_shct_cntx.CurrSelArrow = DEDICATED_KEY_LEFT;
                    break;
                    
                case MENU_SETTING_DEDICATED_RIGHT_KEY:
                    g_shct_cntx.CurrSelArrow = DEDICATED_KEY_RIGHT;
                    break;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            EntryShctEditDedicatedKey();
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            g_shct_cntx.CurrSelArrow = 0;
            cui_menu_close(menu_evt->sender_id);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  ShctReadDedicatedListFromNVRAM
* DESCRIPTION
*  Read dedicated key shortcut list and initialized.
* PARAMETERS
*  void
*  index(?)        [IN]        List of shortcut index
* RETURNS
*  void
*****************************************************************************/
void ShctReadDedicatedListFromNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 nvramData[SHCT_NVRAM_SIZE];
    //S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ReadRecord(NVRAM_EF_SHORTCUTS_LID, 2, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
	ReadRecordSlim(NVRAM_EF_SHORTCUTS_LID, 2, (void*)nvramData, SHCT_NVRAM_SIZE);
    
    for (i = 0; i < TOTAL_DEDICATED_KEYS; i++)
    {
        if (nvramData[i] == 0xffff)
        {
            memcpy((void*)&nvramData, (void*)&g_mmi_shct_nav_key_default_list, TOTAL_DEDICATED_KEYS * 2);
            break;
        }
    }
    
    for (i = 0; i < TOTAL_DEDICATED_KEYS; i++)
    {
        if (mmi_shct_get_menu_launch_func(nvramData[i]) == NULL)
        {
            g_shct_cntx.DediShctList[i] = SHCT_DEFAULT_MENU_ID;
        }
        else
        {
            memcpy((void*)&g_shct_cntx.DediShctList[i], (void*)&nvramData[i], 2);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  ShctWriteDedicatedListToNVRAM
* DESCRIPTION
*  Write dedicated key shortcut list to NVRAM.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctWriteDedicatedListToNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvramData[SHCT_NVRAM_SIZE];
    //S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvramData, 0xff, sizeof(nvramData));
    
    memcpy((void*)&nvramData, (void*)&g_shct_cntx.DediShctList, sizeof(g_shct_cntx.DediShctList));
    
    //WriteRecord(NVRAM_EF_SHORTCUTS_LID, 2, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
	WriteRecordSlim(NVRAM_EF_SHORTCUTS_LID, 2, (void*)nvramData, SHCT_NVRAM_SIZE);
}


/*****************************************************************************
* FUNCTION
*  HighlightDedicatedKeys
* DESCRIPTION
*  Highlight handler of dedicated key shortcut item in Phonesetup
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightDedicatedKeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_shct_launch_dedicated_key, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  EntryShctEditDedicatedKey
* DESCRIPTION
*  Entry edit dedicated key shortcut screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctEditDedicatedKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, valid_item_num = 0;
    U8 highlighted = 0;
    U16 EditShortcutsIds[MMI_SHCT_MAX_DISPLAY_LIST];
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SEARCH_WEB__
    if (g_shct_cntx.CurrSelArrow == DEDICATED_KEY_DOWN &&
        mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY))
    {
        mmi_search_web_entry_dedicated_key_setting(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY);
        return;
    }
#endif

#if (MMI_MAX_SIM_NUM >= 3)
    if (g_shct_cntx.CurrSelArrow == DEDICATED_KEY_LEFT)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            GRP_ID_SHCT_DEDICATED_KEY_CFG,
            NULL);
        return;
    }
#endif

#if defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__)
    if (g_shct_cntx.CurrSelArrow == DEDICATED_KEY_RIGHT)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            GRP_ID_SHCT_DEDICATED_KEY_CFG,
            NULL);
        return;
    }
#endif // defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__)

    if (g_mmi_shct_max_cand_list == 0)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_EMPTY,
            MMI_EVENT_FAILURE,
            GRP_ID_SHCT_DEDICATED_KEY_CFG,
            NULL);
        return;
    }

    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_SHCT_DEDICATED_KEY_CFG, 
                        SCR_ID_SHCT_EDIT_DEDICATED_KEYS,
                        NULL,
                        (FuncPtr)EntryShctEditDedicatedKey, 
                        MMI_FRM_FULL_SCRN))
    {
        /* the first item == Shortcuts */
        g_shct_cntx.edit_list[0] = SHCT_DEFAULT_MENU_ID;
    #ifndef __OP01_FWPBW__
        EditShortcutsIds[0] = MAIN_MENU_SHORTCUTS_TEXT;
        valid_item_num++;
    #endif /* __OP01_FWPBW__ */
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        
        for (i = 0; i < g_mmi_shct_max_cand_list; i++)
        {
            MMI_BOOL is_unreg_menu = MMI_FALSE;
            S32 j;
            for (j = 0; j < MMI_SHCT_MAX_DYNAMIC_REG_LIST; j++)
            {
                if (g_shct_cntx.dynamic_reg_list.menu_id[j] == mmi_shct_candidate_menu[i].menu_id)
                {
                    is_unreg_menu = MMI_TRUE;
                    break;
                }
            }
            
            if (is_unreg_menu == MMI_TRUE)
            {
                continue;
            }

            if (mmi_shct_candidate_menu[i].menu_id != 0)
            {
                EditShortcutsIds[valid_item_num] = mmi_shct_get_menu_string(mmi_shct_candidate_menu[i].menu_id);
                g_shct_cntx.edit_list[valid_item_num] = mmi_shct_candidate_menu[i].menu_id;

                if (guiBuffer == NULL)
                {
                    if (mmi_shct_candidate_menu[i].menu_id == g_shct_cntx.DediShctList[g_shct_cntx.CurrSelArrow])
                    {
                        highlighted = valid_item_num;
                    }
                }
                valid_item_num++;
            }
        }
        
        RegisterHighlightHandler(HighlightShctEdit);
        
        ShowCategory1Screen(
            MAIN_MENU_SHORTCUTS_TEXT,
            GetRootTitleIcon(MENU_SETTING_DEDICATED_KEYS),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            valid_item_num,
            EditShortcutsIds,
            highlighted,
            guiBuffer);
        SetLeftSoftkeyFunction(ShctSaveDedicated, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(ShctSaveDedicated, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
}


/*****************************************************************************
* FUNCTION
*  ShctSaveDedicated
* DESCRIPTION
*  Save dedicated key shortcut.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctSaveDedicated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.DediShctList[g_shct_cntx.CurrSelArrow] = g_shct_cntx.CurrEditShct;
    
    ShctWriteDedicatedListToNVRAM();

    if (g_shct_cntx.sel_chct_cb != NULL)
    {
        (*(mmi_shct_sel_shct_cb)g_shct_cntx.sel_chct_cb)((mmi_shct_nav_key_enum)g_shct_cntx.CurrSelArrow);
    }
    mmi_frm_scrn_close(GRP_ID_SHCT_DEDICATED_KEY_CFG, SCR_ID_SHCT_EDIT_DEDICATED_KEYS);
}


/*****************************************************************************
* FUNCTION
*  ShctExecuteUpKey
* DESCRIPTION
*  Up key handler in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecuteUpKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.DediShctList[DEDICATED_KEY_UP] != SHCT_DEFAULT_MENU_ID)
    {
        mmi_shct_launch_app_by_nav_key(DEDICATED_KEY_UP);
    }
    else
    {
        EntryShctInIdle();
    }
}


/*****************************************************************************
* FUNCTION
*  ShctExecuteDownKey
* DESCRIPTION
*  Down key handler in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecuteDownKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SEARCH_WEB__
    if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY))
    {
        mmi_search_web_trigger_by_hot_key(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY);
        return;
    }
#endif

    if (g_shct_cntx.DediShctList[DEDICATED_KEY_DOWN] != SHCT_DEFAULT_MENU_ID)
    {
        mmi_shct_launch_app_by_nav_key(DEDICATED_KEY_DOWN);
    }
    else
    {
        EntryShctInIdle();
    }
    
}


/*****************************************************************************
* FUNCTION
*  ShctExecuteLeftKey
* DESCRIPTION
*  Left key handler in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecuteLeftKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 3)
    mmi_sim_space_launch();
    return;
#endif

    if (g_shct_cntx.DediShctList[DEDICATED_KEY_LEFT] != SHCT_DEFAULT_MENU_ID)
    {
        mmi_shct_launch_app_by_nav_key(DEDICATED_KEY_LEFT);
    }
    else
    {
        EntryShctInIdle();
    }
}


/*****************************************************************************
* FUNCTION
*  ShctExecuteRightKey
* DESCRIPTION
*  Right key handler in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecuteRightKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__)
    mmi_am_start_from_mm(APPID_OPERA);
    return;
#endif // defined(__MMI_MRE_APP_OPERA_MINI__) && (__MRE_AM__)

    if (g_shct_cntx.DediShctList[DEDICATED_KEY_RIGHT] != SHCT_DEFAULT_MENU_ID)
    {
        mmi_shct_launch_app_by_nav_key(DEDICATED_KEY_RIGHT);
    }
    else
    {
        EntryShctInIdle();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_launch_app_by_nav_key
* DESCRIPTION
*  Register arrow key handlers in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_shct_launch_app_by_nav_key(mmi_shct_nav_key_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_shct_launch_app(g_shct_cntx.DediShctList[key]);
}


/*****************************************************************************
* FUNCTION
*  RegisterDedicatedKeyHandlers
* DESCRIPTION
*  Register arrow key handlers in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void RegisterDedicatedKeyHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !(defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    SetKeyHandler(ShctExecuteUpKey, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ShctExecuteDownKey, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
#endif
    SetKeyHandler(ShctExecuteLeftKey, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ShctExecuteRightKey, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_get_nav_key_str
* DESCRIPTION
*  Interface for homescreen to get the navigation key string.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
WCHAR* mmi_shct_get_nav_key_str(mmi_shct_nav_key_enum nav_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *string;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SHCT_MAX_DYNAMIC_REG_LIST; i++)
    {
        if (g_shct_cntx.dynamic_reg_list.menu_id[i] == g_shct_cntx.DediShctList[nav_key])
        {
            string = (WCHAR*)GetString(STR_GLOBAL_EMPTY);
            return string;
        }
    }
    
    if (g_shct_cntx.DediShctList[nav_key] == SHCT_DEFAULT_MENU_ID)
    {
        string = (WCHAR*)GetString(MAIN_MENU_SHORTCUTS_TEXT);
    }
    else
    {
        string = (WCHAR*)GetString(mmi_shct_get_menu_string(g_shct_cntx.DediShctList[nav_key]));
    }

    return string;
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_interface_sel_nav_key_shct
* DESCRIPTION
*  Interface for select shortcut.
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE:  reg success
*  MMI_FALSE: reg fail
*****************************************************************************/
MMI_BOOL mmi_shct_interface_sel_nav_key_shct(mmi_shct_nav_key_enum nav_key, mmi_shct_sel_shct_cb cb_func)
{
    g_shct_cntx.CurrSelArrow = nav_key;
    EntryShctEditDedicatedKey();
    g_shct_cntx.sel_chct_cb = (void*)cb_func;
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_shct_dedicated_key_menu_handler
* DESCRIPTION
*  Handle the phone setting dedicated key menu CUI
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_shct_dedicated_key_menu_handler(cui_menu_event_struct *event, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_CUI_MENU_ITEM_SELECT &&
        event->highlighted_menu_id == MENU_SETTING_DEDICATED_KEYS)
    {
        mmi_shct_launch_dedicated_key_ext(parent_gid);
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_DONT_CARE;
    }
}
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */ // #ifdef __MMI_DEDICATED_KEY_SHORTCUTS__


void mmi_shct_dynamic_register(MMI_ID menu_id, MMI_BOOL register_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, empty_index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SHCT_MAX_DYNAMIC_REG_LIST; i++)
    {
        if (g_shct_cntx.dynamic_reg_list.menu_id[i] == 0)
        {
            if (empty_index == -1)
            {
                empty_index = 0;
            }

            if (g_shct_cntx.dynamic_reg_list.menu_id[empty_index] == 0)
            {
                empty_index = (empty_index < i) ? empty_index : i;
            }
            else
            {
                empty_index = i;
            }
        }

        if (g_shct_cntx.dynamic_reg_list.menu_id[i] == menu_id &&
            register_flag == MMI_TRUE)
        {
            g_shct_cntx.dynamic_reg_list.menu_id[i] = 0;
            g_shct_cntx.dynamic_reg_list.unreg_count--;
            return;
        }
    }

    if (i == MMI_SHCT_MAX_DYNAMIC_REG_LIST &&
        register_flag == MMI_FALSE &&
        empty_index != -1)
    {
        g_shct_cntx.dynamic_reg_list.menu_id[empty_index] = menu_id;
        g_shct_cntx.dynamic_reg_list.unreg_count++;
        MMI_ASSERT(g_shct_cntx.dynamic_reg_list.unreg_count <= MMI_SHCT_MAX_DYNAMIC_REG_LIST);
    }
}

MMI_BOOL mmi_shct_check_dynamic_unreg_menu(MMI_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < MMI_SHCT_MAX_DYNAMIC_REG_LIST; i++)
    {
        if (menu_id == g_shct_cntx.dynamic_reg_list.menu_id[i])
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


#endif /* __DISABLE_SHORTCUTS_IMPL__ */ /* #if !defined (__MMI_FOURWAYS_KEY_DISABLE__) || defined (__MMI_VRSD_SHORTCUT__) || defined (__MMI_VRSI__) */
#endif /* SHORTCUTS_APP */ 
