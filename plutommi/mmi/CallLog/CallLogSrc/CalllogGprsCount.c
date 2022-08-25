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
*  CallLogGprsCount.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
* This file is intends for show gprs counter 
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_CLOG_GPRS_COUNT__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "GlobalResDef.h"

#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "menucuigprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "GlobalConstants.h"
#include "CommonScreens.h"
#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogConfig.h"
#include "CallLogProt.h"
#include "mmi_rp_app_calllog_def.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_GPRS_MENU_ITEMS   (5) // total 5 menu items

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
    MMI_BOOL is_used;
    srv_clog_gprs_data_struct data[MMI_SIM_TOTAL];
    mmi_sim_enum sim_id;
    U16 get_data_ret[MMI_SIM_TOTAL];
    U16 hilite_menu_id;
    MMI_ID cui;
    MMI_ID parent_gid;
} mmi_clog_gprs_cntx_struct;


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
//static mmi_clog_gprs_cntx_struct g_mmi_clog_gprs_cntx;
static mmi_clog_gprs_cntx_struct *mmi_clog_gprs_cntx_p;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static MMI_RET mmi_clog_enter_gprs_proc(mmi_event_struct *evt);
/* Context */
static mmi_clog_gprs_cntx_struct *mmi_clog_gprs_new_cntx(void);
static void mmi_clog_gprs_free_cntx(void);
static mmi_clog_gprs_cntx_struct *mmi_clog_gprs_get_cntx(void);

/* Get */
static S32 mmi_clog_gprs_get_data_cb(
            void *user_data,
            srv_clog_gprs_get_req_struct *req_data,
            const srv_clog_gprs_data_struct *gprs_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);

/* UI */
static void mmi_clog_enter_gprs_counter_int(mmi_clog_gprs_cntx_struct *cntx);
/* Reset */
static S32 mmi_clog_gprs_reset_data_cb(
            void *user_data,
            srv_clog_gprs_reset_req_struct *req_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);

static void mmi_clog_gprs_display_popup(MMI_BOOL ok_flag);


/*----------------------------------------------------------------------------*/
/* Compiler Option                                                            */
/*----------------------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 3)

#include "wgui_categories_list.h"
#include "wgui_categories_util.h"
#include "CustMenuRes.h"

typedef enum
{
    MMI_CLOG_GPRS_TAB_ID_SIM1,
    MMI_CLOG_GPRS_TAB_ID_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_CLOG_GPRS_TAB_ID_SIM3,
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_CLOG_GPRS_TAB_ID_SIM4,
#endif
#endif
    MMI_CLOG_GPRS_TAB_ID_MAX_NUM
} mmi_clog_gprs_tab_id_enum;

typedef FuncPtr MMI_CLOG_GPRS_TAB_HDLR;

typedef struct
{
    mmi_clog_gprs_tab_id_enum lt_id;
    U16 scrn_id;
    MMI_STR_ID str_id;
    MMI_IMG_ID img_id;
} mmi_clog_gprs_tab_page_struct;

typedef struct
{
    U32 total_num;
    const mmi_clog_gprs_tab_page_struct *page[MMI_CLOG_GPRS_TAB_ID_MAX_NUM];
    MMI_CLOG_GPRS_TAB_HDLR page_hdlr;
} mmi_clog_gprs_tab_struct;

static const mmi_clog_gprs_tab_page_struct g_mmi_clog_gprs_tab_page_sim1 = 
{
    MMI_CLOG_GPRS_TAB_ID_SIM1,
    SCR_ID_CLOG_GPRS_COUNT_SIM1,
    STR_ID_CLOG_GPRS_COUNT,
    IMG_GLOBAL_SIM1
};

static const mmi_clog_gprs_tab_page_struct g_mmi_clog_gprs_tab_page_sim2 = 
{
    MMI_CLOG_GPRS_TAB_ID_SIM2,
    SCR_ID_CLOG_GPRS_COUNT_SIM2,
    STR_ID_CLOG_GPRS_COUNT,
    IMG_GLOBAL_SIM2
};

#if (MMI_MAX_SIM_NUM >= 3)

static const mmi_clog_gprs_tab_page_struct g_mmi_clog_gprs_tab_page_sim3 = 
{
    MMI_CLOG_GPRS_TAB_ID_SIM3,
    SCR_ID_CLOG_GPRS_COUNT_SIM3,
    STR_ID_CLOG_GPRS_COUNT,
    IMG_GLOBAL_SIM3
};
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM >= 4)
static const mmi_clog_gprs_tab_page_struct g_mmi_clog_gprs_tab_page_sim4 = 
{
    MMI_CLOG_GPRS_TAB_ID_SIM4,
    SCR_ID_CLOG_GPRS_COUNT_SIM4,
    STR_ID_CLOG_GPRS_COUNT,
    IMG_GLOBAL_SIM4
};
#endif /* (MMI_MAX_SIM_NUM >= 4) */

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static void mmi_clog_enter_gprs_tab(mmi_scrn_essential_struct *scr_info);
static void mmi_clog_gprs_fill_tab_info(mmi_frm_tab_struct *page_info);
static void mmi_clog_gprs_enter_tab_page(mmi_scrn_essential_struct *grp_data);
static void mmi_clog_gprs_show_tab_page(U32 index);
static void mmi_clog_gprs_hint(U32 tab_page_idx, U8 **hintArray);
static void mmi_clog_gprs_highlight(S32 index);
static void mmi_clog_gprs_reset_confirm(void);
static void mmi_clog_gprs_reset_hdlr(mmi_clog_gprs_cntx_struct *cntx);

static const mmi_clog_gprs_tab_struct g_mmi_clog_gprs_tab = 
{
    MMI_CLOG_GPRS_TAB_ID_MAX_NUM,
    {
        &g_mmi_clog_gprs_tab_page_sim1,
        &g_mmi_clog_gprs_tab_page_sim2,
#if (MMI_MAX_SIM_NUM >= 3)
        &g_mmi_clog_gprs_tab_page_sim3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        &g_mmi_clog_gprs_tab_page_sim4
#endif
    },
    (MMI_CLOG_GPRS_TAB_HDLR) mmi_clog_gprs_enter_tab_page
};


    
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_gprs_counter_int
 * DESCRIPTION
 *  entry gprs conter screen
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_gprs_counter_int(mmi_clog_gprs_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_GPRS_ENTER_CUI, GRP_ID_CLOG_GPRS_COUNT, mmi_frm_group_get_active_id());

    mmi_frm_scrn_first_enter(GRP_ID_CLOG_GPRS_COUNT, 
        SCR_ID_CLOG_GPRS_COUNT, 
        (FuncPtr) mmi_clog_enter_gprs_tab, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_gprs_proc
 * DESCRIPTION
 *  proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 * PARAMETERS
 *  evt     [IN]        Event structure pointer
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
static MMI_RET mmi_clog_enter_gprs_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_clog_gprs_free_cntx();
            break;
        
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                {
                    mmi_clog_gprs_cntx_struct *cntx = (mmi_clog_gprs_cntx_struct*)evt->user_data;
                    MMI_CLOG_ASSERT(cntx == mmi_clog_gprs_get_cntx());
                    mmi_clog_gprs_reset_hdlr(cntx);
                    break;
                }

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
 *  mmi_clog_enter_gprs
 * DESCRIPTION
 *  Entry screen for call times (at most include sim1 & sim2 & voip last/all sent/all recvd
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_gprs_tab(mmi_scrn_essential_struct *scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_ID parent_gid = *(scr_info->user_data);
    mmi_frm_tab_struct page_info[MMI_CLOG_GPRS_TAB_ID_MAX_NUM];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_gprs_fill_tab_info(page_info);
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_create(
        GRP_ID_CLOG_GPRS_COUNT,
        SCR_ID_CLOG_GPRS_COUNT,
        page_info,
        (U8) MMI_CLOG_GPRS_TAB_ID_MAX_NUM,
        (U8) cui_tab_get_select_index(SCR_ID_CLOG_GPRS_COUNT),
        scr_info->user_data);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    mmi_frm_scrn_tab_enter(
        GRP_ID_CLOG_GPRS_COUNT,
        SCR_ID_CLOG_GPRS_COUNT,
        NULL,
        (FuncPtr) mmi_clog_enter_gprs_tab,
        page_info,
        (U8) MMI_CLOG_GPRS_TAB_ID_MAX_NUM,
        0);
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
}


static void mmi_clog_gprs_fill_tab_info(mmi_frm_tab_struct *page_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    const mmi_clog_gprs_tab_page_struct *page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLOG_GPRS_TAB_ID_MAX_NUM; i++)
    {
        page = g_mmi_clog_gprs_tab.page[i];
        page_info[i].screen_id = page->scrn_id;
        page_info[i].tab_icon = (U8*) GetImage(page->img_id);
        page_info[i].tab_string = NULL;
        page_info[i].tab_entry_func = g_mmi_clog_gprs_tab.page_hdlr;
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
static void mmi_clog_gprs_enter_tab_page(mmi_scrn_essential_struct *grp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 index;

    const mmi_clog_gprs_tab_page_struct *page;
    mmi_clog_gprs_cntx_struct *cntx = mmi_clog_gprs_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    index = cui_tab_get_select_index(SCR_ID_CLOG_GPRS_COUNT);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    index = mmi_frm_scrn_tab_get_active_page_index();
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    cntx->sim_id = mmi_frm_index_to_sim(index);

    MMI_CLOG_IT_ASSERT(index < MMI_CLOG_GPRS_TAB_ID_MAX_NUM);

    page = g_mmi_clog_gprs_tab.page[index];
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    ret = cui_tab_enter(
            GRP_ID_CLOG_GPRS_COUNT,
            SCR_ID_CLOG_GPRS_COUNT,
            NULL,
            (FuncPtr) mmi_clog_gprs_enter_tab_page,
            MMI_FRM_FULL_SCRN);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    ret = mmi_frm_scrn_tab_page_enter(
            GRP_ID_CLOG_GPRS_COUNT,
            SCR_ID_CLOG_GPRS_COUNT,
            (MMI_ID)page->scrn_id,
            NULL,
            (FuncPtr) mmi_clog_gprs_enter_tab_page,
            MMI_FRM_TAB_PAGE);
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    if (!ret)
        return;

    mmi_clog_gprs_show_tab_page(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_show_tab_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_show_tab_page(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *gui_buff;
    U16 items_str_id[MMI_CLOG_GPRS_MENU_ITEMS];
    U8 *items[MMI_CLOG_GPRS_MENU_ITEMS];  // total 5 menu
    U8 *hints[MMI_CLOG_GPRS_MENU_ITEMS];
    const mmi_clog_gprs_tab_page_struct *page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    page = g_mmi_clog_gprs_tab.page[index];
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    gui_buff = cui_tab_get_screen_gui_buf(SCR_ID_CLOG_GPRS_COUNT, page.scrn_id);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    gui_buff = mmi_frm_scrn_tab_page_get_active_gui_buf();
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    
    RegisterHighlightHandler(mmi_clog_gprs_highlight);
    mmi_clog_gprs_hint(index, hints);

    GetSequenceStringIds(MENU_ID_CLOG_GPRS_COUNT, items_str_id);
    for (i = 0; i < MMI_CLOG_GPRS_MENU_ITEMS; i++)
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
        MMI_CLOG_GPRS_MENU_ITEMS,
        items,
        (U16*) gIndexIconsImageList,
        hints,
        0,
        0,
        index,
        gui_buff);
}


static void mmi_clog_gprs_hint(U32 tab_page_idx, U8 **hintArray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menu_idx = 0;
    U64 temp_data;
    mmi_clog_gprs_cntx_struct *cntx = mmi_clog_gprs_get_cntx();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_data = cntx->data[tab_page_idx].last_sent;
    kal_wsprintf((WCHAR *)hintData[menu_idx], "%d B", (U32) temp_data);
    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;

    temp_data = cntx->data[tab_page_idx].last_recved;
    kal_wsprintf((WCHAR *)hintData[menu_idx], "%d B", (U32) temp_data);
    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;

    temp_data = cntx->data[tab_page_idx].total_sent;
    kal_wsprintf((WCHAR *)hintData[menu_idx], "%d B", (U32) temp_data);
    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;

    temp_data = cntx->data[tab_page_idx].total_recved;
    kal_wsprintf((WCHAR *)hintData[menu_idx], "%d B", (U32) temp_data);
    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;

    hintArray[menu_idx] = NULL;
}

static void mmi_clog_close_gprs_scrn()
{
    mmi_frm_scrn_close_active_id();
    mmi_frm_group_close(GRP_ID_CLOG_GPRS_COUNT);    
}

void mmi_clog_gprs_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 4) // means Reset All menu
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        SetLeftSoftkeyFunction(mmi_clog_gprs_reset_confirm, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_clog_gprs_reset_confirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
    }

    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetRightSoftkeyFunction( mmi_clog_close_gprs_scrn, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_reset_confirm
 * DESCRIPTION
 *  gprs counter common reset confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_reset_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_gprs_cntx_struct *cntx = mmi_clog_gprs_get_cntx();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_confirm(
        CNFM_TYPE_YESNO,
        STR_ID_CLOG_IF_RESET_COUNT,
        MMI_EVENT_QUERY,
        GRP_ID_CLOG_GPRS_COUNT,
        cntx,
        MMI_CLOG_ALERT_FLAG_AUTO_DISMISS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_reset_hdlr
 * DESCRIPTION
 *  call time common reset counter value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_reset_hdlr(mmi_clog_gprs_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_gprs_reset_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_ASSERT(cntx == mmi_clog_gprs_get_cntx());
    
    req.sim_id = cntx->sim_id;

    req.fields = SRV_CLOG_GPRS_FIELD_ALL;
    srv_clog_gprs_reset_data((const srv_clog_gprs_reset_req_struct*)&req, cntx, mmi_clog_gprs_reset_data_cb);
}

#else /* (MMI_MAX_SIM_NUM >= 3) */


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
const static mmi_clog_sub_menu_map_struct g_clog_gprs_menu_map[] = 
{
    {MMI_SIM1, MENU_ID_CLOG_GPRS_LAST_SENT}
    , {MMI_SIM1, MENU_ID_CLOG_GPRS_LAST_RECVED}
    , {MMI_SIM1, MENU_ID_CLOG_GPRS_ALL_SENT}
    , {MMI_SIM1, MENU_ID_CLOG_GPRS_ALL_RECVED}
    , {MMI_SIM1, MENU_ID_CLOG_GPRS_RESET}
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */ 
};

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static void mmi_clog_gprs_counter_set_hint(mmi_clog_gprs_cntx_struct *cntx);
static void mmi_clog_gprs_set_lsk_str(mmi_clog_gprs_cntx_struct *cntx, MMI_MENU_ID menu_id);
static void mmi_clog_gprs_reset_confirm(mmi_clog_gprs_cntx_struct *cntx);
static void mmi_clog_gprs_reset_hdlr(mmi_clog_gprs_cntx_struct *cntx);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_gprs_counter_int
 * DESCRIPTION
 *  entry gprs conter screen
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_gprs_counter_int(mmi_clog_gprs_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_GPRS_ENTER_CUI, GRP_ID_CLOG_GPRS_COUNT, mmi_frm_group_get_active_id());

    cntx->cui = cui_menu_create(
                                GRP_ID_CLOG_GPRS_COUNT,
                                CUI_MENU_SRC_TYPE_RESOURCE,
                                CUI_MENU_TYPE_APPSUB,
                                MENU_ID_CLOG_GPRS_COUNT,
                                MMI_TRUE,
                                cntx);
    cui_menu_set_default_title_by_id(
        cntx->cui,
        STR_ID_CLOG_GPRS_COUNT,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG));

    cui_menu_run(cntx->cui);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_gprs_proc
 * DESCRIPTION
 *  proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 * PARAMETERS
 *  evt     [IN]        Event structure pointer
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
static MMI_RET mmi_clog_enter_gprs_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    mmi_clog_gprs_cntx_struct *cntx = (mmi_clog_gprs_cntx_struct*)evt->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_clog_gprs_free_cntx();
            break;
            
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            mmi_clog_gprs_counter_set_hint(cntx);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            mmi_clog_gprs_set_lsk_str(cntx, menu_evt->highlighted_menu_id);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_clog_gprs_reset_confirm(cntx);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
	        mmi_frm_group_close(GRP_ID_CLOG_GPRS_COUNT);
            break;
        }
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_clog_gprs_reset_hdlr(cntx);
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
 *  mmi_clog_gprs_counter_set_hint
 * DESCRIPTION
 *  gprs (sim1 and sim2) counter hint handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_counter_set_hint(mmi_clog_gprs_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR temp_str[MAX_SUBMENU_CHARACTERS];
    U64 temp_data;
    U16 sim = 0, menu_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sim = 0; sim < MMI_SIM_TOTAL; sim++)
    {
        temp_data = cntx->data[sim].last_sent;
        kal_wsprintf(temp_str, "%d B", (U32) temp_data);
        cui_menu_set_item_hint(cntx->cui, g_clog_gprs_menu_map[menu_idx++].menu_id, temp_str);

        temp_data = cntx->data[sim].last_recved;
        kal_wsprintf(temp_str, "%d B", (U32) temp_data);
        cui_menu_set_item_hint(cntx->cui, g_clog_gprs_menu_map[menu_idx++].menu_id, temp_str);

        temp_data = cntx->data[sim].total_sent;
        kal_wsprintf(temp_str, "%d B", (U32) temp_data);
        cui_menu_set_item_hint(cntx->cui, g_clog_gprs_menu_map[menu_idx++].menu_id, temp_str);

        temp_data = cntx->data[sim].total_recved;
        kal_wsprintf(temp_str, "%d B", (U32) temp_data);
        cui_menu_set_item_hint(cntx->cui, g_clog_gprs_menu_map[menu_idx++].menu_id, temp_str);

        /* menu_idx = 0; */
        menu_idx++; /* for Reset all menu */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_set_lsk_str
 * DESCRIPTION
 *  gprs (sim1 and sim2) counter hint handler
 * PARAMETERS
 *  menu_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_set_lsk_str(mmi_clog_gprs_cntx_struct *cntx, MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_gprs_data_struct *temp_data;
    MMI_BOOL reset_flag = MMI_FALSE;
    U16 sim = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->hilite_menu_id = menu_id;

    if (menu_id == MENU_ID_CLOG_GPRS_RESET)
    {
        sim = 0;    /* means sim1 */
    }
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */ 
    else
    {
        cui_menu_change_left_softkey_string(cntx->cui, NULL);
        cui_menu_change_center_softkey_content(cntx->cui, NULL, NULL);
        return;
    }

    temp_data = &cntx->data[sim];

    if (temp_data->last_recved != 0 || temp_data->last_sent != 0 ||
        temp_data->total_recved != 0 || temp_data->total_sent != 0)
        // For round up or down
        //if (temp_data->last_recved > 511 || temp_data->last_sent > 511 ||
        //    temp_data->total_recved > 511 || temp_data->total_sent > 511)
    {
        reset_flag = MMI_TRUE;
    }

    if (reset_flag)
    {
        cui_menu_change_left_softkey_string_by_id(cntx->cui, STR_GLOBAL_OK);
        cui_menu_change_center_softkey_content(cntx->cui, NULL, get_image(IMG_GLOBAL_COMMON_CSK));
    }
    else
    {
        cui_menu_change_left_softkey_string(cntx->cui, NULL);
        cui_menu_change_center_softkey_content(cntx->cui, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_reset_confirm
 * DESCRIPTION
 *  gprs counter common reset confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_reset_confirm(mmi_clog_gprs_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->hilite_menu_id == MENU_ID_CLOG_GPRS_RESET
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif 
        )
    {
        mmi_clog_confirm(
            CNFM_TYPE_YESNO,
            STR_ID_CLOG_IF_RESET_COUNT,
            MMI_EVENT_QUERY,
            GRP_ID_CLOG_GPRS_COUNT,
            cntx,
            MMI_CLOG_ALERT_FLAG_AUTO_DISMISS);
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_reset_hdlr
 * DESCRIPTION
 *  call time common reset counter value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_reset_hdlr(mmi_clog_gprs_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_gprs_reset_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_ASSERT(cntx == mmi_clog_gprs_get_cntx());
    
    if (cntx->hilite_menu_id == MENU_ID_CLOG_GPRS_RESET)
    {
        req.sim_id = MMI_SIM1;
    }
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */ 
    else
    {
        return;
    }

    req.fields = SRV_CLOG_GPRS_FIELD_ALL;
    srv_clog_gprs_reset_data((const srv_clog_gprs_reset_req_struct*)&req, cntx, mmi_clog_gprs_reset_data_cb);
}


#endif /* (MMI_MAX_SIM_NUM >= 3) */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_new_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_clog_gprs_cntx_struct *mmi_clog_gprs_new_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_clog_gprs_cntx_p)
        OslMfree(mmi_clog_gprs_cntx_p);
    mmi_clog_gprs_cntx_p = OslMalloc(sizeof(mmi_clog_gprs_cntx_struct));
    memset(mmi_clog_gprs_cntx_p, 0x0, sizeof(mmi_clog_gprs_cntx_struct));
    mmi_clog_gprs_cntx_p->is_used = MMI_TRUE;
    return mmi_clog_gprs_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_free_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_free_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_clog_gprs_cntx_p)
    {   
        OslMfree(mmi_clog_gprs_cntx_p);
        mmi_clog_gprs_cntx_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_clog_gprs_cntx_struct *mmi_clog_gprs_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clog_gprs_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_gprs_counter
 * DESCRIPTION
 *  Entry screen for gprs (at most include sim1 & sim2 last sent/last received/
 *  all sent/all recvd/reset counter
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_enter_gprs_counter(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_gprs_get_req_struct req;
    mmi_clog_gprs_cntx_struct *cntx = mmi_clog_gprs_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* re-entry case */
    if (cntx)
        return;
    cntx = mmi_clog_gprs_new_cntx();
    cntx->parent_gid = parent_gid;

    mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_GPRS_COUNT, mmi_clog_enter_gprs_proc, cntx, MMI_FRM_NODE_NONE_FLAG);//MMI_FRM_NODE_SMART_CLOSE_FLAG);

    req.sim_id = (mmi_sim_enum)MMI_SIM_ALL;

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_ENTRY_GPRS_COUNTER, parent_gid, req.sim_id);

    srv_clog_gprs_get_data((const srv_clog_gprs_get_req_struct*)&req, cntx, mmi_clog_gprs_get_data_cb);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_get_data_cb
 * DESCRIPTION
 *  gprs (sim1 and sim2) counter get data callback function
 * PARAMETERS
 *  user_data       [IN]         
 *  req_data        [IN]         
 *  gprs_data       [IN]        
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_clog_gprs_get_data_cb(
            void *user_data,
            srv_clog_gprs_get_req_struct *req_data,
            const srv_clog_gprs_data_struct *gprs_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index;
    MMI_BOOL ret_flag = MMI_FALSE;
    mmi_clog_gprs_cntx_struct *cntx = (mmi_clog_gprs_cntx_struct*)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx != mmi_clog_gprs_get_cntx() || !cntx->is_used)
        return SRV_CLOG_RET_STOP;

    index = mmi_frm_sim_to_index(req_data->sim_id);
    cntx->get_data_ret[index] = 1;
    if (ret != SRV_CLOG_RET_OK)
    {
        cntx->get_data_ret[index] = 0;
    }

    MMI_TRACE(
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_GPRS_GET_DATA_CB,
        req_data->sim_id,
        gprs_data->last_recved,
        gprs_data->last_sent,
        gprs_data->total_recved,
        gprs_data->total_sent); 

    memcpy(&cntx->data[index], gprs_data, sizeof(srv_clog_gprs_data_struct));

    if (more == MMI_FALSE)
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (cntx->get_data_ret[i] != 0)
                ret_flag = MMI_TRUE;
        }
        if (ret_flag == MMI_FALSE)
        {
            mmi_clog_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_CLOG_GPRS_COUNT, NULL);
            return SRV_CLOG_RET_STOP;
        }

        mmi_clog_enter_gprs_counter_int(cntx);
        return SRV_CLOG_RET_STOP;
    }
    else
    {
        return SRV_CLOG_RET_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_reset_data_cb
 * DESCRIPTION
 *  rest gprs counter callback function
 * PARAMETERS
 *  user_data       [IN]         
 *  req_data        [IN]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_clog_gprs_reset_data_cb(
            void *user_data,
            srv_clog_gprs_reset_req_struct *req_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    mmi_clog_gprs_cntx_struct *cntx = (mmi_clog_gprs_cntx_struct *)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx != mmi_clog_gprs_get_cntx() || !cntx->is_used)
        return SRV_CLOG_RET_STOP;
    
    if (ret == SRV_CLOG_RET_OK && more == MMI_FALSE)
    {
        index = mmi_frm_sim_to_index(req_data->sim_id);
        memset(&cntx->data[index], 0, sizeof(srv_clog_gprs_data_struct));
        mmi_clog_gprs_display_popup(MMI_TRUE);
    }
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_gprs_display_popup(MMI_FALSE);
    }
    return SRV_CLOG_RET_STOP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_gprs_display_popup
 * DESCRIPTION
 *  common popup function
 * PARAMETERS
 *  ok_flag     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_gprs_display_popup(MMI_BOOL ok_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ok_flag == MMI_TRUE)
    {
        mmi_clog_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_CLOG_GPRS_COUNT, NULL);
    }
    else
    {
        mmi_clog_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, GRP_ID_CLOG_GPRS_COUNT, NULL);
    }
}

#endif /* __MMI_CLOG_GPRS_COUNT__ */ 

