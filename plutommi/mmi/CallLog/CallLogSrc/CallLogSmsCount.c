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
*  CallLogList.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file is intends for display sms counter
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_CLOG_SMS_COUNT__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "menucuigprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "GlobalResDef.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "GlobalConstants.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreens.h"

#include "SmsSrvGprot.h"

#include "CallLogProt.h"
#include "mmi_rp_app_calllog_def.h"
/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_SMS_MENU_ITEMS   (2) // total 2 menu items

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static S32 g_clog_sim_info = SRV_SMS_SIM_1;
static S32 g_clog_sms_type;
static MMI_ID g_clog_sms_cui;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static MMI_RET mmi_clog_enter_sms_proc(mmi_event_struct *evt);
static void mmi_clog_sms_reset_confirm(void);
static void mmi_clog_sms_reset_hdlr(void);


#if (MMI_MAX_SIM_NUM >= 3)

#include "wgui_categories_list.h"
typedef enum
{
    MMI_CLOG_SMS_TAB_ID_SIM1,
    MMI_CLOG_SMS_TAB_ID_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_CLOG_SMS_TAB_ID_SIM3,
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_CLOG_SMS_TAB_ID_SIM4,
#endif
#endif
    MMI_CLOG_SMS_TAB_ID_MAX_NUM
} mmi_clog_sms_tab_id_enum;

typedef FuncPtr MMI_CLOG_SMS_TAB_HDLR;

typedef struct
{
    mmi_clog_sms_tab_id_enum lt_id;
    U16 scrn_id;
    MMI_STR_ID str_id;
    MMI_IMG_ID img_id;
} mmi_clog_sms_tab_page_struct;

typedef struct
{
    U32 total_num;
    const mmi_clog_sms_tab_page_struct *page[MMI_CLOG_SMS_TAB_ID_MAX_NUM];
    MMI_CLOG_SMS_TAB_HDLR page_hdlr;
} mmi_clog_sms_tab_struct;

static const mmi_clog_sms_tab_page_struct g_mmi_clog_sms_tab_page_sim1 = 
{
    MMI_CLOG_SMS_TAB_ID_SIM1,
    SCR_ID_MMI_CLOG_SMS_COUNT_SIM1,
    STR_ID_CLOG_SMS_COUNT,
    IMG_GLOBAL_SIM1
};

static const mmi_clog_sms_tab_page_struct g_mmi_clog_sms_tab_page_sim2 = 
{
    MMI_CLOG_SMS_TAB_ID_SIM2,
    SCR_ID_MMI_CLOG_SMS_COUNT_SIM2,
    STR_ID_CLOG_SMS_COUNT,
    IMG_GLOBAL_SIM2
};

#if (MMI_MAX_SIM_NUM >= 3)

static const mmi_clog_sms_tab_page_struct g_mmi_clog_sms_tab_page_sim3 = 
{
    MMI_CLOG_SMS_TAB_ID_SIM3,
    SCR_ID_MMI_CLOG_SMS_COUNT_SIM3,
    STR_ID_CLOG_SMS_COUNT,
    IMG_GLOBAL_SIM3
};
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM >= 4)
static const mmi_clog_sms_tab_page_struct g_mmi_clog_sms_tab_page_sim4 = 
{
    MMI_CLOG_SMS_TAB_ID_SIM4,
    SCR_ID_MMI_CLOG_SMS_COUNT_SIM4,
    STR_ID_CLOG_SMS_COUNT,
    IMG_GLOBAL_SIM4
};
#endif /* (MMI_MAX_SIM_NUM >= 4) */

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static mmi_sim_enum g_mmi_clog_sms_curr_sim;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static void mmi_clog_enter_sms_tab(mmi_scrn_essential_struct *scr_info);
static void mmi_clog_sms_fill_tab_info(mmi_frm_tab_struct *page_info);
static void mmi_clog_sms_enter_tab_page(mmi_scrn_essential_struct *grp_data);
static void mmi_clog_sms_show_tab_page(U32 index);
static void mmi_clog_sms_hint(U32 tab_page_idx, U8 **hintArray);
static void mmi_clog_sms_highlight(S32 index);

static const mmi_clog_sms_tab_struct g_mmi_clog_sms_tab = 
{
    MMI_CLOG_SMS_TAB_ID_MAX_NUM,
    {
        &g_mmi_clog_sms_tab_page_sim1,
        &g_mmi_clog_sms_tab_page_sim2,
#if (MMI_MAX_SIM_NUM >= 3)
        &g_mmi_clog_sms_tab_page_sim3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        &g_mmi_clog_sms_tab_page_sim4
#endif
    },
    (MMI_CLOG_SMS_TAB_HDLR) mmi_clog_sms_enter_tab_page
};


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_sms_counter
 * DESCRIPTION
 *  Entry function to display sms counter screen
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_enter_sms_counter(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_SMS_COUNT, mmi_clog_enter_sms_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_scrn_first_enter(GRP_ID_CLOG_SMS_COUNT, 
        SCR_ID_MMI_CLOG_SMS_COUNT, 
        (FuncPtr) mmi_clog_enter_sms_tab, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_sms_proc
 * DESCRIPTION
 *  proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 * PARAMETERS
 *  evt     [IN]        Event structure pointer
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
static MMI_RET mmi_clog_enter_sms_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_clog_sms_reset_hdlr();
                    break;

                case MMI_ALERT_CNFM_NO:
                case MMI_ALERT_NORMAL_EXIT:
                default:
                    break;
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_sms_tab(mmi_scrn_essential_struct *scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_tab_struct page_info[MMI_CLOG_SMS_TAB_ID_MAX_NUM];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_sms_fill_tab_info(page_info);
    
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_create(
        GRP_ID_CLOG_SMS_COUNT,
        SCR_ID_MMI_CLOG_SMS_COUNT,
        page_info,
        (U8) MMI_CLOG_SMS_TAB_ID_MAX_NUM,
        (U8) cui_tab_get_select_index(SCR_ID_MMI_CLOG_SMS_COUNT),
        scr_info->user_data);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    mmi_frm_scrn_tab_enter(
        GRP_ID_CLOG_SMS_COUNT,
        SCR_ID_MMI_CLOG_SMS_COUNT,
        NULL,
        (FuncPtr) mmi_clog_enter_sms_tab,
        page_info,
        (U8) MMI_CLOG_SMS_TAB_ID_MAX_NUM,
        0);
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
}


static void mmi_clog_sms_fill_tab_info(mmi_frm_tab_struct *page_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    const mmi_clog_sms_tab_page_struct *page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLOG_SMS_TAB_ID_MAX_NUM; i++)
    {
        page = g_mmi_clog_sms_tab.page[i];
        page_info[i].screen_id = page->scrn_id;
        page_info[i].tab_icon = (U8*) GetImage(page->img_id);
        page_info[i].tab_string = NULL;
        page_info[i].tab_entry_func = g_mmi_clog_sms_tab.page_hdlr;
        page_info[i].user_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_lt_enter_tab_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  grp_data        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_sms_enter_tab_page(mmi_scrn_essential_struct *grp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 index;

    const mmi_clog_sms_tab_page_struct *page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    index = cui_tab_get_select_index(SCR_ID_MMI_CLOG_SMS_COUNT);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    index = mmi_frm_scrn_tab_get_active_page_index();
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    MMI_CLOG_ASSERT(index < MMI_CLOG_SMS_TAB_ID_MAX_NUM);

    page = g_mmi_clog_sms_tab.page[index];
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    ret = cui_tab_enter(
            GRP_ID_CLOG_SMS_COUNT,
            SCR_ID_MMI_CLOG_SMS_COUNT,
            NULL,
            (FuncPtr) mmi_clog_sms_enter_tab_page,
            MMI_FRM_FULL_SCRN);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    ret = mmi_frm_scrn_tab_page_enter(
            GRP_ID_CLOG_SMS_COUNT,
            SCR_ID_MMI_CLOG_SMS_COUNT,
            (MMI_ID)page->scrn_id,
            NULL,
            (FuncPtr) mmi_clog_sms_enter_tab_page,
            MMI_FRM_TAB_PAGE);
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    if (!ret)
        return;

    mmi_clog_sms_show_tab_page(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_sms_show_tab_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_sms_show_tab_page(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *gui_buff;
    U16 items_str_id[MMI_CLOG_SMS_MENU_ITEMS];
    U8 *items[MMI_CLOG_SMS_MENU_ITEMS];  // total 2 menu
    U8 *hints[MMI_CLOG_SMS_MENU_ITEMS];
    const mmi_clog_sms_tab_page_struct *page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    page = g_mmi_clog_sms_tab.page[index];
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    gui_buff = cui_tab_get_screen_gui_buf(SCR_ID_MMI_CLOG_SMS_COUNT, page->scrn_id);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    gui_buff = mmi_frm_scrn_tab_page_get_active_gui_buf();
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    RegisterHighlightHandler(mmi_clog_sms_highlight);
    mmi_clog_sms_hint(index, hints);

    GetSequenceStringIds(MENU_ID_CLOG_SMS_COUNT, items_str_id);
    for (i = 0; i < MMI_CLOG_SMS_MENU_ITEMS; i++)
    {
        kal_wsprintf((WCHAR *)subMenuData[i], "%w", get_string(items_str_id[i]));
        items[i] = subMenuData[i];
    }
    
    ShowCategory626Screen(
        (U8 *)GetString(page->str_id),
        0,
        STR_GLOBAL_RESET,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_CLOG_SMS_MENU_ITEMS,
        items,
        (U16*) gIndexIconsImageList,
        hints,
        0,
        0,
        index,
        gui_buff);
/*
    wgui_cat1033_show(
        get_string(page->str_id),
        NULL,
        get_string(STR_GLOBAL_RESET),
        NULL,
        get_string(STR_GLOBAL_BACK),
        GetImage(IMG_GLOBAL_BACK),
		2,
        items,
        hints,
        (U16*) gIndexIconsImageList,
        0,
        index,
        gui_buff);
*/
}


static void mmi_clog_sms_hint(U32 tab_page_idx, U8 **hintArray)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    U16 menu_idx = 0;
    mmi_sim_enum sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_frm_index_to_sim(tab_page_idx);
    g_mmi_clog_sms_curr_sim = sim_id;
    // to do for sim3/sim4
    if (MMI_SIM1 == sim_id)
        g_clog_sim_info = SRV_SMS_SIM_1;
    else if (MMI_SIM2 == sim_id)
        g_clog_sim_info = SRV_SMS_SIM_2;
#if (MMI_MAX_SIM_NUM >= 3)
    else if (MMI_SIM3 == sim_id)
        g_clog_sim_info = SRV_SMS_SIM_3;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else
        g_clog_sim_info = SRV_SMS_SIM_4;
#endif
    
    count = srv_sms_get_sms_counter(g_clog_sim_info, SRV_SMS_COUNT_SENT);
    if (count == 0)
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%w", get_string(STR_ID_CLOG_SMS_NO_MESSAGE));
    else if (count == 1)
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%d %w", count, get_string(STR_ID_CLOG_SMS_MESSAGE));
    else
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%d %w", count, get_string(STR_ID_CLOG_SMS_MESSAGES));

    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;

    count = srv_sms_get_sms_counter(g_clog_sim_info, SRV_SMS_COUNT_RECV);
    if (count == 0)
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%w", get_string(STR_ID_CLOG_SMS_NO_MESSAGE));
    else if (count == 1)
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%d %w", count, get_string(STR_ID_CLOG_SMS_MESSAGE));
    else
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%d %w", count, get_string(STR_ID_CLOG_SMS_MESSAGES));

    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;
    
}


void mmi_clog_sms_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == index)
        g_clog_sms_type = SRV_SMS_COUNT_SENT;
    else
        g_clog_sms_type = SRV_SMS_COUNT_RECV;

	SetLeftSoftkeyFunction(mmi_clog_sms_reset_confirm, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_clog_sms_reset_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_sms_update_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_RET mmi_clog_sms_update_counter(mmi_event_struct *event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_MMI_CLOG_SMS_COUNT == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_display_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
    
    return MMI_RET_OK;
}


#else /* (MMI_MAX_SIM_NUM >= 3) */


/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static void mmi_clog_sms_menu_item_hilite(S32 sim_info, S32 sms_type, MMI_MENU_ID menu_item_id);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_sms_counter
 * DESCRIPTION
 *  Entry function to display sms counter screen
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_enter_sms_counter(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create group */
    mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_SMS_COUNT, mmi_clog_enter_sms_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_clog_sms_cui = cui_menu_create(
                        GRP_ID_CLOG_SMS_COUNT,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_APPSUB,
                        MENU_ID_CLOG_SMS_COUNT,
                        MMI_TRUE,
                        NULL);

    cui_menu_set_default_title_by_id(
        g_clog_sms_cui,
        STR_ID_CLOG_SMS_COUNT,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG));

    cui_menu_run(g_clog_sms_cui);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_sms_proc
 * DESCRIPTION
 *  proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 * PARAMETERS
 *  evt     [IN]        Event structure pointer
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
static MMI_RET mmi_clog_enter_sms_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(g_clog_sms_cui, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            if (menu_evt->highlighted_menu_id == MENU_ID_CLOG_SMS_SENT)
            {
                mmi_clog_sms_menu_item_hilite(SRV_SMS_SIM_1, SRV_SMS_COUNT_SENT, MENU_ID_CLOG_SMS_SENT);
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_CLOG_SMS_RECVED)
            {
                mmi_clog_sms_menu_item_hilite(SRV_SMS_SIM_1, SRV_SMS_COUNT_RECV, MENU_ID_CLOG_SMS_RECVED);
            }
        #ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_DUAL_SIM__ */ 
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_clog_sms_reset_confirm();
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            g_clog_sms_cui = GRP_ID_INVALID;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_clog_sms_reset_hdlr();
                    break;

                case MMI_ALERT_CNFM_NO:
                case MMI_ALERT_NORMAL_EXIT:
                default:
                    break;
            }
            break;
        }
        default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_sms_menu_item_hilite
 * DESCRIPTION
 *  sms (sim1 and sim2) counter highlight handler for menu cui
 * PARAMETERS
 *  sim_info            [IN]        
 *  sms_type            [IN]        
 *  menu_item_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_sms_menu_item_hilite(S32 sim_info, S32 sms_type, MMI_MENU_ID menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    WCHAR str[MAX_SUBMENU_CHARACTERS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_clog_sim_info = sim_info;
    g_clog_sms_type = sms_type;

    count = srv_sms_get_sms_counter((srv_sms_sim_enum)sim_info, (srv_sms_count_type_enum)sms_type);
    if (count == 0)
    {
        kal_wsprintf(str, "%w", get_string(STR_ID_CLOG_SMS_NO_MESSAGE));
        cui_menu_change_left_softkey_string(g_clog_sms_cui, NULL);
        cui_menu_change_center_softkey_content(g_clog_sms_cui, NULL, NULL);
    }
    else
    {
        if (count == 1)
            kal_wsprintf(str, "%d %w", count, get_string(STR_ID_CLOG_SMS_MESSAGE));
        else
            kal_wsprintf(str, "%d %w", count, get_string(STR_ID_CLOG_SMS_MESSAGES));

        cui_menu_change_left_softkey_string_by_id(g_clog_sms_cui, STR_GLOBAL_RESET);
        cui_menu_change_center_softkey_content(g_clog_sms_cui, NULL, get_image(IMG_GLOBAL_COMMON_CSK));
    }
    cui_menu_set_item_hint(g_clog_sms_cui, menu_item_id, str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_sms_update_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_RET mmi_clog_sms_update_counter(mmi_event_struct *event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clog_sms_cui != GRP_ID_INVALID)
        cui_menu_refresh_currlist(g_clog_sms_cui);

    return MMI_RET_OK;
}

#endif /* (MMI_MAX_SIM_NUM >= 3) */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_sms_reset_confirm
 * DESCRIPTION
 *  SMS counter common reset confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_sms_reset_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_confirm(
        CNFM_TYPE_YESNO,
        STR_ID_CLOG_IF_RESET_COUNT,
        MMI_EVENT_QUERY,
        GRP_ID_CLOG_SMS_COUNT,
        NULL,
        MMI_CLOG_ALERT_FLAG_AUTO_DISMISS);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_clog_sms_reset_hdlr
 * DESCRIPTION
 *  sms common reset counter value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_sms_reset_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_reset_sms_counter((srv_sms_sim_enum)g_clog_sim_info, (srv_sms_count_type_enum)g_clog_sms_type);

    //mmi_clog_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_CLOG_SMS_COUNT, NULL);
}


#endif /* __MMI_CLOG_SMS_COUNT__ */


