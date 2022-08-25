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
 * Organizer.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements main menu screen of Oranizer applications.
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

/**********************************************************************************
   Filename:      Organizer.c
   Author:        Gautam
   Date Created:
   Contains:      Organizer Main Screen
**********************************************************************************/
#include "MMI_features.h"
#ifndef _MMI_ORGANIZER_C
#define _MMI_ORGANIZER_C

/*  Include: MMI header file */

#include "AlarmGProt.h" /* for alarm */
#include "worldclock.h" /* for world clock */

#ifdef __MMI_INDICAL__
#include "IndianCalendarProt.h"
#endif

/* add header file start */
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_organizer_def.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CustMenuRes.h"
#include "CustDataRes.h"
#include "wgui_categories_util.h"
#include "string.h"
#include "wgui_fixed_menus.h"
#include "GlobalResDef.h"
#include "wgui_categories_list.h"
/* add header file end */

#include "GlobalMenuItems.h"
#include "AlarmProt.h"
#include "AlarmDef.h"
/* 
 * Define
 */
#define APR_TEXT_CHARCTERS    3

/* 
 * Typedef 
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern U16 gIndexIconsImageList[];

#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif 
/*#ifdef __MMI_INDICAL__
extern void	InitIndianCalendar(void);
#endif*/
/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  OrgInit
 * DESCRIPTION
 *  Initialize each applications in Organizer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void OrgInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to do list */
#ifndef __MMI_DEV_NEW_SLIM__
    /* alarm */
    AlmInit();
#endif
    /* world clock */
#if defined (__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)
    WcInit();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  OrgDeInit
 * DESCRIPTION
 *  Deinitialize each application of Organizer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void OrgDeInit(void)
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
 *  EntryOrganizer
 * DESCRIPTION
 *  Entry Organizer menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryOrganizer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 *guiBuffer;
    S32 num_of_items = 0;
    U16 item_list[MAX_SUB_MENUS];
    U8 *item_string[MAX_SUB_MENUS];
    U16 item_icon[MAX_SUB_MENUS];
    U8 *pop_up_organizer[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_ORG, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_ORG, MMI_FRM_NODE_SMART_CLOSE_FLAG);
 
    if(!mmi_frm_scrn_enter(GRP_ID_ORG,
                       ORGANIZER_SCREENID,
                       NULL,
                       EntryOrganizer,
                       MMI_FRM_FULL_SCRN))
   {
       return;
   };
    
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    SetParentHandler(MAIN_MENU_ORGANIZER_MENUID);

    num_of_items = GetNumOfChild_Ext(MAIN_MENU_ORGANIZER_MENUID);

    GetSequenceStringIds_Ext(MAIN_MENU_ORGANIZER_MENUID, item_list);
    GetSequenceImageIds_Ext(MAIN_MENU_ORGANIZER_MENUID, item_icon);

    for (i = 0; i < num_of_items; i++)
    {
        item_string[i] = (U8*) GetString(item_list[i]);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    memset(pop_up_organizer, 0, sizeof(pop_up_organizer));

#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_APHORISM__) */ 

    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_ORGANIZER_MENUID);
#endif 
    /* MTK Leo end */
    wgui_list_menu_enable_access_by_shortcut();

	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory53Screen(
        MAIN_MENU_ORGANIZER_TEXT,
        ORGANIZER_TITLE_IMAGEID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        item_string,
        item_icon,
        pop_up_organizer,
        0,
        /* currHiliteItemOrg */ 0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#if defined(__MMI_OP01_MENU_NOSIM_LIST__) || defined(__MMI_OP02_0100__)
/*****************************************************************************
 * FUNCTION
 *  EntryOrganizerNoSim
 * DESCRIPTION
 *  Entry Organizer menu screen without sim card
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryOrganizerNoSim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 *guiBuffer;
    S32 num_of_items = 0;
    U16 item_list[MAX_SUB_MENUS];
    U8 *item_string[MAX_SUB_MENUS];
    U16 item_icon[MAX_SUB_MENUS];
    U8 *pop_up_organizer[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_ORG, NULL, NULL);
     mmi_frm_group_enter(GRP_ID_ORG, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
     if(!mmi_frm_scrn_enter(GRP_ID_ORG,
                        ORGANIZER_SCREENID,
                        NULL,
                        EntryOrganizer,
                        MMI_FRM_FULL_SCRN))
    {
        return;
    };
     
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    SetParentHandler(MAIN_MENU_ORGANIZER_NO_SIM_MENUID);

    num_of_items = GetNumOfChild_Ext(MAIN_MENU_ORGANIZER_NO_SIM_MENUID);

    GetSequenceStringIds_Ext(MAIN_MENU_ORGANIZER_NO_SIM_MENUID, item_list);
    GetSequenceImageIds_Ext(MAIN_MENU_ORGANIZER_NO_SIM_MENUID, item_icon);

    for (i = 0; i < num_of_items; i++)
    {
        item_string[i] = (U8*) GetString(item_list[i]);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    memset(pop_up_organizer, 0, sizeof(pop_up_organizer));

#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_APHORISM__) */ 

    /* add mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_ORGANIZER_NO_SIM_MENUID);
#endif 
  
    wgui_list_menu_enable_access_by_shortcut();
    ShowCategory53Screen(
        MAIN_MENU_ORGANIZER_TEXT,
       GetRootTitleIcon(MAIN_MENU_ORGANIZER_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        item_string,
        item_icon,
        pop_up_organizer,
        0,
        /* currHiliteItemOrg */ 0,
        guiBuffer);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* __MMI_OP01_MENU_NOSIM_LIST__ || __MMI_OP02_0100__ */

#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_APHORISM__) */ 

#endif /* _MMI_ORGANIZER_C */ // #ifndef _MMI_ORGANIZER_C

