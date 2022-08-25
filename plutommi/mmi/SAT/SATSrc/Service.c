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
 * Service.c
 *
 * Project:
 * --------
 *   MAUI
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "SatAppGprot.h"
#include "SatSrvGprot.h"
#include "InfoNum.h"
#include "InfoNumResDef.h"
#include "ServiceDefs.h"
#include "Service.h"

#include "mmi_rp_app_mainmenu_def.h"
#include "ModeSwitchSrvGprot.h"
#include "mmi_rp_app_sat_def.h"
#include "mmi_rp_srv_sat_def.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "CustMenuRes.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "InfoNumResDef.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "GlobalResDef.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_list.h"
#include "CustDataProts.h"
#include "AlertScreen.h"
#include "IdleGprot.h"				// - MAUI_03310504

#ifdef __MMI_SNS_CENTER__
#include "SnsAppGprot.h"
#endif

static S32 g_hilit_index = 0;

extern void goto_mobile_suite_screen(void);
static void mmi_service_sat_menu_update(void);
static void mmi_service_hilit_hdlr(S32 hiliteid);

/*****************************************************************************
 * FUNCTION
 *  GoToServicesMenu
 * DESCRIPTION
 *  Pre displays Services Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToServicesMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_hilit_index = 0;
    mmi_serivce_main_menu_scrn();
}

extern U32 mmi_mre_shortcut_is_shortcut(U16 string_id);
extern U32 mmi_mre_shortcut_is_NA(U32 app_id, U8 * string);
extern U32 mmi_mre_shortcut_free(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_serivce_main_menu_scrn
 * DESCRIPTION
 *  Displays Services Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_serivce_main_menu_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *nStrItemList;
    U16 *nIconItemList;

    U8 **Strings;
    U16 nNumofItem;

    U8 i;
    U8 *guiBuffer;

    U16 menu_id;
    U16 *nMenuitems;
    S32 index;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SLIM_IMG_RES__
    if (!mmi_frm_scrn_enter(GRP_ID_ROOT, SERVICES_MAIN_MENU_SCREEN_ID, wgui_restore_list_menu_slim_style, (FuncPtr)GoToServicesMenu, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);

#else
    if (!mmi_frm_scrn_enter(GRP_ID_ROOT, SERVICES_MAIN_MENU_SCREEN_ID, NULL, (FuncPtr)GoToServicesMenu, MMI_FRM_FULL_SCRN))
    {
        return;
    }

#endif /* __MMI_SLIM_IMG_RES__ */

#if (defined __MMI_APP_MANAGER_SUPPORT__)/* && (defined __MMI_VUI_LAUNCHER__) */
    {


		//if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) != MMI_IDLE_TYPE_CLASSIC)    // - MAUI_03310504
		{
        /* hide all menu under the parent */
        S32 num_of_child = GetNumOfChild(MAIN_MENU_SERVICES_MENUID);

        while(num_of_child)
        {
            mmi_frm_hide_menu_item(GetSeqItemId(MAIN_MENU_SERVICES_MENUID, (U16)(num_of_child - 1)));
            num_of_child--;
        }
    }
}

#endif

#ifndef __MMI_OP12_MENU_12MATRIX__
    mmi_service_sat_menu_update();
#endif /* __MMI_OP12_MENU_12MATRIX__ */

    menu_id = GetSeqItemId_Ext(MAIN_MENU_SERVICES_MENUID, g_hilit_index);

    index = GetChildMenuIDIndexByParentMenuID_Ext(MAIN_MENU_SERVICES_MENUID, menu_id);

    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MAIN_MENU_SERVICES_MENUID);

    if (nNumofItem > 0)
    {
        nStrItemList = (U16 *)OslMalloc(sizeof(U16) * nNumofItem);
        nIconItemList = (U16 *)OslMalloc(sizeof(U16) * nNumofItem);
        Strings = (U8 **)OslMalloc(sizeof(U8 *) * nNumofItem);
        nMenuitems = (U16 *)OslMalloc(sizeof(U16) * nNumofItem);
    }
    else
    {
        nStrItemList = (U16 *)OslMalloc(sizeof(U16));
        nIconItemList = (U16 *)OslMalloc(sizeof(U16));
        Strings = (U8 **)OslMalloc(sizeof(U8 *));
        nMenuitems = (U16 *)OslMalloc(sizeof(U16));
    }

    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MAIN_MENU_SERVICES_MENUID, nStrItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_SERVICES_MENUID, nIconItemList);
    GetSequenceItemIds_Ext(MAIN_MENU_SERVICES_MENUID, nMenuitems);

    if (index == -1)
    {
        g_hilit_index = (g_hilit_index < nNumofItem) ? g_hilit_index : (nNumofItem -1);
    }
    else
    {
        g_hilit_index = index;
    }

    for (i = 0; i < nNumofItem; i++)
    {
        U32 app_id = 0;

        Strings[i] = (PU8) GetString(nStrItemList[i]);

    #ifndef __MMI_OP12_MENU_12MATRIX__
        sim_id = mmi_sat_menu_id_to_sim_id(nMenuitems[i]);
        if (sim_id != MMI_SIM_NONE)
        {
            Strings[i] = (PU8)srv_sat_get_menu_title(sim_id);
        }
    #endif /* __MMI_OP12_MENU_12MATRIX__ */
    
        app_id = mmi_mre_shortcut_is_shortcut(nStrItemList[i]);
        if (app_id)
        {
            Strings[i] = (PU8)mmi_mre_shortcut_is_NA(app_id, Strings[i]);
        }
    }

#ifdef __MMI_MERGE_SAT_TO_MAINMENU__
    if (nNumofItem == 0)
    {
        mmi_popup_display((WCHAR*) GetString(SERVICES_NOT_PROVIDED_STRING_ID), MMI_EVENT_FAILURE, NULL);
        return;
    }
    else if (nNumofItem == 1 && srv_sat_is_menu_present(MMI_SIM1))
    {
        mmi_sat_app_launch(mmi_frm_group_get_active_id(), MMI_SIM1);
        return;
    }
#endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

    SetParentHandler(MAIN_MENU_SERVICES_MENUID);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_service_hilit_hdlr);

#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_SERVICES_MENUID);
#endif 

    if (nNumofItem > 0)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    wgui_list_menu_enable_access_by_shortcut();

#if (defined __MMI_APP_MANAGER_SUPPORT__)/* && (defined __MMI_VUI_LAUNCHER__) */
  if(nNumofItem > 0)
    ShowCategory84Screen(
        STR_ID_SAT_MENU_TITLE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        Strings,
        nIconItemList,
        LIST_MENU,
        g_hilit_index,
        guiBuffer);

  else
	   mmi_frm_group_close(SERVICES_MAIN_MENU_SCREEN_ID);  //MAUI_03184885

#else
    ShowCategory84Screen(
        SERVICES_TITLE_STRING_ID,
        GetRootTitleIcon(MAIN_MENU_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        Strings,
        nIconItemList,
        LIST_MENU,
        g_hilit_index,
        guiBuffer);

#endif /* (defined __MMI_APP_MANAGER_SUPPORT__) && (defined __MMI_VUI_LAUNCHER__) */
    mmi_mre_shortcut_free();
    OslMfree(nStrItemList);
    OslMfree(nIconItemList);
    OslMfree(Strings);
    OslMfree(nMenuitems);
    
    if (nNumofItem == 0)
    {
        /* No menu item and no SAT in GSM only project */
        ChangeLeftSoftkey(0, 0);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


void mmi_service_hilit_hdlr(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_hilit_index = hiliteid;
    ExecuteCurrHiliteHandler(hiliteid);
}


#ifndef __MMI_OP12_MENU_12MATRIX__
/*****************************************************************************
 * FUNCTION
 *  mmi_service_sat_menu_update
 * DESCRIPTION
 *  SAT menu hide or unhide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_service_sat_menu_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_OP12_MENU_12MATRIX__
    if (!srv_sat_is_menu_present(MMI_SIM1))
    {
		if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) != MMI_IDLE_TYPE_CLASSIC)       // - MAUI_03310504
		{
        mmi_frm_hide_menu_item(MENU_ID_SAT1_ENTRY);   /* need hide SAT1 menu */
    }
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SAT1_ENTRY); /* need unhide SAT1 menu */
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (!srv_sat_is_menu_present(MMI_SIM2))
    {
		if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) != MMI_IDLE_TYPE_CLASSIC)         // - MAUI_03310504
		{
        mmi_frm_hide_menu_item(MENU_ID_SAT2_ENTRY);   /* need hide SAT2 menu */
    }
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SAT2_ENTRY); /* need unhide SAT2 menu */
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (!srv_sat_is_menu_present(MMI_SIM3))
    {
		if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) != MMI_IDLE_TYPE_CLASSIC)        // - MAUI_03310504
		{
        mmi_frm_hide_menu_item(MENU_ID_SAT3_ENTRY);   /* need hide SAT3 menu */
    }
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SAT3_ENTRY); /* need unhide SAT3 menu */
    }

#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    if (!srv_sat_is_menu_present(MMI_SIM4))
    {
		if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) != MMI_IDLE_TYPE_CLASSIC)          // - MAUI_03310504
		{
        mmi_frm_hide_menu_item(MENU_ID_SAT4_ENTRY);   /* need hide SAT4 menu */
    }
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SAT4_ENTRY); /* need unhide SAT4 menu */
    }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 2 */
#endif /* __MMI_OP12_MENU_12MATRIX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_service_hilite_sat_hdlr
 * DESCRIPTION
 *  Hilite Handler for SAT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_service_hilite_sat_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_service_launch_sat_app, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_service_launch_sat_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_service_launch_sat_app
 * DESCRIPTION
 *  Key handler for SAT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_service_launch_sat_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;
    U16 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = GetSeqItemId_Ext(MAIN_MENU_SERVICES_MENUID, GetCurrHiliteID());

    sim_id = mmi_sat_menu_id_to_sim_id(menu_id);

// MAUI_03331585 starts
    if (!srv_sat_is_menu_present((mmi_sim_enum)(sim_id)))
      {		
             mmi_popup_display(
                (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                MMI_EVENT_FAILURE,
                NULL);
            
	  }
// MAUI_03331585 ends  

	else if (sim_id != MMI_SIM_NONE)
    {
        mmi_sat_app_launch(mmi_frm_group_get_active_id(), sim_id);
    }
}
#endif


#ifdef __MMI_SNS_CENTER__
static void mmi_service_launch_sns_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sns_launch();
}


void mmi_service_hilite_sns_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_service_launch_sns_app, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_service_launch_sns_app, KEY_EVENT_UP);

}
#endif


/*****************************************************************************
 * FUNCTION
 *  WapHiliteHandler
 * DESCRIPTION
 *  Hilite Handler for WAP Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WapHiliteHandler(void)
{
#ifdef BROWSER_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(goto_mobile_suite_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(goto_mobile_suite_screen, KEY_EVENT_UP);
#endif /* BROWSER_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  InitService
 * DESCRIPTION
 *  Initialises variables & Protocol Handlers for SAT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitService(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SERVICES_WAP_MENU_ID use different highlight handler in Operator Version  */
#if 0
#ifndef __MMI_OP01_MENU_9MATRIX__
#ifdef BROWSER_SUPPORT
/* under construction !*/
#endif
#endif /* __MMI_OP01_MENU_9MATRIX__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_GPRS_FEATURES__
/* under construction !*/
#endif /* __MMI_GPRS_FEATURES__ */ 
#endif /* 0 */

#if 0
#ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
#endif 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  DataConnectGSMHiliteHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DataConnectGSMHiliteHandler(void)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    SetLeftSoftkeyFunction(InitializeDataAccountRecords, KEY_EVENT_UP);
//    SetKeyHandler(InitializeDataAccountRecords, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __TCPIP__ */ 
}


#if (defined __MMI_APP_MANAGER_SUPPORT__) /* && (defined __MMI_VUI_LAUNCHER__) */
/*****************************************************************************
 * FUNCTION
 *  mmi_service_sat_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param             [IN]
 *  param_size      [IN]
 * RETURNS
 *  group id
 *****************************************************************************/
mmi_ret mmi_service_sat_proc(mmi_app_launch_param_struct *param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num = 0;
    U32 i;
    mmi_sim_enum first_sim = MMI_SIM_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sat_is_menu_present((mmi_sim_enum)(1 << i)))
        {
            num++;

            if (first_sim == MMI_SIM_NONE)
            {
                first_sim = (mmi_sim_enum)(1 << i);
            }
        }
    }

    do
    {
        if (num == 0)
        {
            mmi_popup_display(
                (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                MMI_EVENT_FAILURE,
                NULL);

            break;
        }

        if (num == 1)
        {
            mmi_sat_app_launch(GRP_ID_ROOT, first_sim);
            break;
        }

        g_hilit_index = 0;
        mmi_serivce_main_menu_scrn();
    } while(0);

    return GRP_ID_ROOT;
}

#endif /* (defined __MMI_APP_MANAGER_SUPPORT__) && (defined __MMI_VUI_LAUNCHER__) */

