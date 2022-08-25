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
*  CallLogCallCost.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file is intends for show call cost
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

#ifdef __MMI_CLOG_CALL_COST__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "menucuigprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "GlobalConstants.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "gui_typedef.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "gui_inputs.h"
#include "CommonScreens.h"
#include "Fseditorcuigprot.h"
#include "Inlinecuigprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwUsabSrvGprot.h"
#include "Secsetcuigprot.h"

#include "CallLogConfig.h"
#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogProt.h"
#include "mmi_rp_app_calllog_def.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

#define MMI_CLOG_CCOST_MAX_COST              (16777215)  /* 2^13 + 2^12 + 2^11 + 2^1 + 2^0 */
#define MMI_CLOG_CCOST_MAX_LEN               (10)

/* Inline CUI Revise */
#define MMI_PPU_PRICE_CAPTION_ID0            (CUI_INLINE_ITEM_ID_BASE + 0)
#define MMI_PPU_PRICE_EDIT_ID1               (CUI_INLINE_ITEM_ID_BASE + 1)
#define MMI_PPU_UNIT_CAPTION_ID2             (CUI_INLINE_ITEM_ID_BASE + 2)
#define MMI_PPU_UNIT_EDIT_ID3                (CUI_INLINE_ITEM_ID_BASE + 3)

#define MMI_CLOG_CCOST_MENU_ITEMS   (5) // total 5 menu items

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    MMI_PPU_PRICE_CAPTION = 0,
    MMI_PPU_PRICE_EDIT,
    MMI_PPU_UNIT_CAPTION,
    MMI_PPU_UNIT_EDIT,
    MMI_PPU_INLINE_TOTAL
} mmi_clog_ccost_ppu_enum;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

typedef struct
{
    MMI_BOOL is_used;
    srv_clog_ccost_data_struct data[MMI_SIM_TOTAL];
    WCHAR max_cost[MMI_SIM_TOTAL][MMI_CLOG_CCOST_MAX_LEN];
    WCHAR price[MMI_SIM_TOTAL][20];
    WCHAR unit[MMI_SIM_TOTAL][4];
    U16 get_data_ret[MMI_SIM_TOTAL];

    mmi_sim_enum sim_id;
    U16 hilite_menu_id;
    U16 hilite_sim; /* 0 means sim1, 1 means sim2 */
    MMI_ID cui;
    MMI_ID editor_cui;
    MMI_ID inline_cui;
    MMI_ID parent_gid;
} mmi_clog_ccost_cntx_struct;

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static mmi_clog_ccost_cntx_struct *mmi_clog_ccost_cntx_p;

mmi_id g_pin2_cui;


/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static mmi_clog_ccost_cntx_struct *mmi_clog_ccost_new_cntx(void);
static void mmi_clog_ccost_free_cntx(void);
static mmi_clog_ccost_cntx_struct *mmi_clog_ccost_get_cntx(void);

static S32 mmi_clog_ccost_get_data_cb(
            void *user_data,
            mmi_sim_enum sim_id,
            U32 fields,
            const srv_clog_ccost_data_struct *data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);
static void mmi_clog_enter_ccost_counter_int(MMI_ID parent_gid);

static MMI_RET mmi_clog_enter_ccost_proc(mmi_event_struct *evt);
static void mmi_clog_ccost_pass_pin2_cb(void);
static S32 mmi_clog_ccost_reset_cost_cb(void *user_data, mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret);
static void mmi_clog_ccost_entry_set_max_cost(void);
static void mmi_clog_ccost_menu_select(void);
static void mmi_clog_ccost_verfiy_max_cost(void);
static void mmi_clog_ccost_entry_set_ppu(void);
static void mmi_clog_ccost_verfiy_ppu(void);
static void mmi_clog_ccost_save_confirm(void);
static void mmi_clog_ccost_save_hdlr(void);
static S32 mmi_clog_ccost_save_cb(void *user_data, mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret);
static void mmi_clog_ccost_close_editor_inline_cui(void);
static void mmi_clog_ccost_display_popup(MMI_BOOL ok_flag);


/*----------------------------------------------------------------------------*/
/* Compiler option for Gemini Pluse                                           */
/*----------------------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 3)

#include "wgui_categories_list.h"
typedef enum
{
    MMI_CLOG_CCOST_TAB_ID_SIM1,
    MMI_CLOG_CCOST_TAB_ID_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_CLOG_CCOST_TAB_ID_SIM3,
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_CLOG_CCOST_TAB_ID_SIM4,
#endif
#endif
    MMI_CLOG_CCOST_TAB_ID_MAX_NUM
} mmi_clog_ccost_tab_id_enum;

typedef FuncPtr MMI_CLOG_CCOST_TAB_HDLR;

typedef struct
{
    mmi_clog_ccost_tab_id_enum lt_id;
    U16 scrn_id;
    MMI_STR_ID str_id;
    MMI_IMG_ID img_id;
} mmi_clog_ccost_tab_page_struct;

typedef struct
{
    U32 total_num;
    const mmi_clog_ccost_tab_page_struct *page[MMI_CLOG_CCOST_TAB_ID_MAX_NUM];
    MMI_CLOG_CCOST_TAB_HDLR page_hdlr;
} mmi_clog_ccost_tab_struct;

static const mmi_clog_ccost_tab_page_struct g_mmi_clog_ccost_tab_page_sim1 = 
{
    MMI_CLOG_CCOST_TAB_ID_SIM1,
    SCR_ID_CLOG_CALL_COST_SIM1,
    STR_ID_CLOG_CALL_COST,
    IMG_GLOBAL_SIM1
};

static const mmi_clog_ccost_tab_page_struct g_mmi_clog_ccost_tab_page_sim2 = 
{
    MMI_CLOG_CCOST_TAB_ID_SIM2,
    SCR_ID_CLOG_CALL_COST_SIM2,
    STR_ID_CLOG_CALL_COST,
    IMG_GLOBAL_SIM2
};

#if (MMI_MAX_SIM_NUM >= 3)

static const mmi_clog_ccost_tab_page_struct g_mmi_clog_ccost_tab_page_sim3 = 
{
    MMI_CLOG_CCOST_TAB_ID_SIM3,
    SCR_ID_CLOG_CALL_COST_SIM3,
    STR_ID_CLOG_CALL_COST,
    IMG_GLOBAL_SIM3
};
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM >= 4)
static const mmi_clog_ccost_tab_page_struct g_mmi_clog_ccost_tab_page_sim4 = 
{
    MMI_CLOG_CCOST_TAB_ID_SIM4,
    SCR_ID_CLOG_CALL_COST_SIM4,
    STR_ID_CLOG_CALL_COST,
    IMG_GLOBAL_SIM4
};
#endif /* (MMI_MAX_SIM_NUM >= 4) */


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static void mmi_clog_enter_ccost_tab(mmi_scrn_essential_struct *scr_info);
static void mmi_clog_ccost_fill_tab_info(mmi_frm_tab_struct *page_info);
static void mmi_clog_ccost_enter_tab_page(mmi_scrn_essential_struct *grp_data);
static void mmi_clog_ccost_show_tab_page(U32 index);
static void mmi_clog_ccost_hint(U32 tab_page_idx, U8 **hintArray);
static void mmi_clog_ccost_highlight(S32 index);

static const mmi_clog_ccost_tab_struct g_mmi_clog_ccost_tab = 
{
    MMI_CLOG_CCOST_TAB_ID_MAX_NUM,
    {
        &g_mmi_clog_ccost_tab_page_sim1,
        &g_mmi_clog_ccost_tab_page_sim2,
#if (MMI_MAX_SIM_NUM >= 3)
        &g_mmi_clog_ccost_tab_page_sim3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
       &g_mmi_clog_ccost_tab_page_sim4
#endif
    },
    (MMI_CLOG_CCOST_TAB_HDLR) mmi_clog_ccost_enter_tab_page
};


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ccost_counter_int
 * DESCRIPTION
 *  entry ccost conter screen
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_ccost_counter_int(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_CCOST_SHOW_MENU_CUI,
        GRP_ID_CLOG_CALL_COST,
        mmi_frm_group_get_active_id());

    mmi_frm_scrn_first_enter(GRP_ID_CLOG_CALL_COST, 
        SCR_ID_CLOG_CALL_COST, 
        (FuncPtr) mmi_clog_enter_ccost_tab, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ccost_proc
 * DESCRIPTION
 *  proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 *  It needs to handle the inline cui event
 * PARAMETERS
 *  evt     [IN]        Event structure pointer
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
static MMI_RET mmi_clog_enter_ccost_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_clog_ccost_free_cntx();
            break;
        

        /* Set max cost */
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        {
            cui_fseditor_get_text(
                cntx->editor_cui,
                cntx->max_cost[cntx->hilite_sim],
                20);
            mmi_clog_ccost_verfiy_max_cost();
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT: /* ? abort maybe have issue */
        {
            cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct*) evt;

            cui_fseditor_close(editor_evt->sender_id);
            cntx->editor_cui = GRP_ID_INVALID;
            break;
        }

        /* PPU Inline event start */
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct*) evt;

            cui_inline_get_value(
                inline_evt->sender_id,
                MMI_PPU_PRICE_EDIT_ID1,
                cntx->price[cntx->hilite_sim]);

            cui_inline_get_value(
                inline_evt->sender_id,
                MMI_PPU_UNIT_EDIT_ID3,
                cntx->unit[cntx->hilite_sim]);

            mmi_clog_ccost_verfiy_ppu();
            /* cui_inline_close(inline_evt->sender_id);  need to verify */
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *inline_abort_event;

            inline_abort_event = (cui_event_inline_abort_struct*) evt;
            cui_inline_close(inline_abort_event->sender_id);
            cntx->inline_cui = GRP_ID_INVALID;
            break;
        }
        
        /* PIN2 input screen event start */
        case EVT_ID_CUI_VERIFY_RESULT:
        {
            cui_verify_result_evt_struct *result_evt;
            result_evt = (cui_verify_result_evt_struct*) evt;
        
            if (result_evt->success)
            {
                mmi_clog_ccost_pass_pin2_cb();
            }            
            cui_verify_close(result_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_VERIFY_CANCEL:
        {
            cui_verify_cancel_evt_struct *cancel_evt;
            cancel_evt = (cui_verify_cancel_evt_struct*) evt;
            cui_verify_close(cancel_evt->sender_id);
            break;
        }
	case EVT_ID_GROUP_ACTIVE:
	{	
			/* SIM1 SIM2 SIM3 SIM4*/
			if (!srv_nw_usab_is_usable(MMI_SIM1)
	                        #ifdef __MMI_DUAL_SIM__
/* under construction !*/
				#endif
				#if (MMI_MAX_SIM_NUM >= 3)
				&& !srv_nw_usab_is_usable(MMI_SIM3)
				#endif
				#if (MMI_MAX_SIM_NUM >= 4)
				&& !srv_nw_usab_is_usable(MMI_SIM4)
				#endif
				 )
            {
                cui_verify_close(g_pin2_cui);	
            }

	    break;		
	}

        /* Popup or Confirm event start */
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_clog_ccost_save_hdlr();
                    break;

                case MMI_ALERT_CNFM_NO:
                    mmi_clog_ccost_close_editor_inline_cui();
                    break;

                case MMI_ALERT_NORMAL_EXIT:
                {
                    if (cntx->hilite_menu_id == MENU_ID_CLOG_CCOST_PPU)
                    {
                        srv_clog_ccost_get_data(
                        (mmi_sim_enum)MMI_SIM_ALL,
                            SRV_CLOG_CCOST_FIELD_ALL,
                            cntx,
                            mmi_clog_ccost_get_data_cb);
                        memset(
                            &cntx->data[cntx->hilite_sim],
                            0,
                            sizeof(srv_clog_ccost_data_struct));
                    }
		   else if (cntx->hilite_menu_id == 0)
		   {
		       mmi_frm_group_close(GRP_ID_CLOG_CALL_COST);
		   }
                    break;
                }

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
 *  mmi_clog_enter_ccost
 * DESCRIPTION
 *  Entry screen for call times (at most include sim1 & sim2 & voip last/all sent/all recvd
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_ccost_tab(mmi_scrn_essential_struct *scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_tab_struct page_info[MMI_CLOG_CCOST_TAB_ID_MAX_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_fill_tab_info(page_info);
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_create(
        GRP_ID_CLOG_CALL_COST,
        SCR_ID_CLOG_CALL_COST,
        page_info,
        (U8) MMI_CLOG_CCOST_TAB_ID_MAX_NUM,
        (U8) cui_tab_get_select_index(SCR_ID_CLOG_CALL_COST),
        scr_info->user_data);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    mmi_frm_scrn_tab_enter(
        GRP_ID_CLOG_CALL_COST,
        SCR_ID_CLOG_CALL_COST,
        NULL,
        (FuncPtr) mmi_clog_enter_ccost_tab,
        page_info,
        (U8) MMI_CLOG_CCOST_TAB_ID_MAX_NUM,
        0);
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
}


static void mmi_clog_ccost_fill_tab_info(mmi_frm_tab_struct *page_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    const mmi_clog_ccost_tab_page_struct *page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLOG_CCOST_TAB_ID_MAX_NUM; i++)
    {
        page = g_mmi_clog_ccost_tab.page[i];
        page_info[i].screen_id = page->scrn_id;
        page_info[i].tab_icon = (U8*) GetImage(page->img_id);
        page_info[i].tab_string = NULL;
        page_info[i].tab_entry_func = g_mmi_clog_ccost_tab.page_hdlr;
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
static void mmi_clog_ccost_enter_tab_page(mmi_scrn_essential_struct *grp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 index;
    const mmi_clog_ccost_tab_page_struct *page;
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    index = cui_tab_get_select_index(SCR_ID_CLOG_CALL_COST);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    index = mmi_frm_scrn_tab_get_active_page_index();
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    cntx->sim_id = mmi_frm_index_to_sim(index);

    MMI_CLOG_IT_ASSERT(index < MMI_CLOG_CCOST_TAB_ID_MAX_NUM);

    page = g_mmi_clog_ccost_tab.page[index];
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    ret = cui_tab_enter(
            GRP_ID_CLOG_CALL_COST,
            SCR_ID_CLOG_CALL_COST,
            NULL,
            (FuncPtr) mmi_clog_ccost_enter_tab_page,
            MMI_FRM_FULL_SCRN);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    ret = mmi_frm_scrn_tab_page_enter(
            GRP_ID_CLOG_CALL_COST,
            SCR_ID_CLOG_CALL_COST,
            (MMI_ID)page->scrn_id,
            NULL,
            (FuncPtr) mmi_clog_ccost_enter_tab_page,
            MMI_FRM_TAB_PAGE);
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */

    if (!ret)
        return;

    mmi_clog_ccost_show_tab_page(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_show_tab_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inst        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_show_tab_page(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *gui_buff;
    U16 items_str_id[MMI_CLOG_CCOST_MENU_ITEMS];
    U8 *items[MMI_CLOG_CCOST_MENU_ITEMS];  // total 5 menu
    U8 *hints[MMI_CLOG_CCOST_MENU_ITEMS];
    const mmi_clog_ccost_tab_page_struct *page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    page = g_mmi_clog_ccost_tab.page[index];
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    gui_buff = cui_tab_get_screen_gui_buf(SCR_ID_CLOG_CALL_COST, page.scrn_id);
#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    gui_buff = mmi_frm_scrn_tab_page_get_active_gui_buf();
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
    
    RegisterHighlightHandler(mmi_clog_ccost_highlight);
    mmi_clog_ccost_hint(index, hints);

    GetSequenceStringIds(MENU_ID_CLOG_CALL_COST, items_str_id);
    for (i = 0; i < MMI_CLOG_CCOST_MENU_ITEMS; i++)
    {
        kal_wsprintf((WCHAR *)subMenuData[i], "%w", get_string(items_str_id[i]));
        items[i] = subMenuData[i];
    }
    
    ShowCategory626Screen(
        (U8 *)GetString(page->str_id),
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_CLOG_CCOST_MENU_ITEMS,
        items,
        (U16*) gIndexIconsImageList,
        hints,
        0,
        0,
        index,
        gui_buff);
}


static void mmi_clog_ccost_hint(U32 tab_page_idx, U8 **hintArray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menu_idx = 0;
    U32 temp_data;
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cntx->data[tab_page_idx].last % 1000) != 0)
    {
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%u.%u",
            cntx->data[tab_page_idx].last / 1000,
            cntx->data[tab_page_idx].last % 1000);
    }
    else
    {
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%u", cntx->data[tab_page_idx].last / 1000);
    }
    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;

    temp_data = cntx->data[tab_page_idx].total;
    kal_wsprintf((WCHAR *)hintData[menu_idx], "%d", temp_data);
    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;

    hintArray[menu_idx] = NULL;
    menu_idx++; /* For menu Reset cost */

    temp_data = cntx->data[tab_page_idx].max;
    kal_wsprintf((WCHAR *)hintData[menu_idx], "%d", temp_data);
    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;

    if (cntx->data[tab_page_idx].currency[0] != 0)
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%w %w", cntx->data[tab_page_idx].ppu, cntx->data[tab_page_idx].currency);
    else
        kal_wsprintf((WCHAR *)hintData[menu_idx], "%w", cntx->data[tab_page_idx].ppu);
    hintArray[menu_idx] = hintData[menu_idx];
    menu_idx++;
}


static void mmi_clog_close_ccost_scrn()
{
    mmi_frm_scrn_close_active_id();
    mmi_frm_group_close(GRP_ID_CLOG_CALL_COST);    
}

void mmi_clog_ccost_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 2) // means Reset All menu
    {
        cntx->hilite_menu_id = MENU_ID_CLOG_CCOST_RESET;
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        SetLeftSoftkeyFunction(mmi_clog_ccost_menu_select, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_clog_ccost_menu_select, KEY_EVENT_UP);
    }
    else if (index == 3 || index == 4) // means Set Mas or Set PPU menu
    {
        if (index == 3)
            cntx->hilite_menu_id = MENU_ID_CLOG_CCOST_MAX;
        else
            cntx->hilite_menu_id = MENU_ID_CLOG_CCOST_PPU;
        
        ChangeLeftSoftkey(STR_ID_CLOG_CCOST_SET, 0);
        SetLeftSoftkeyFunction(mmi_clog_ccost_menu_select, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_clog_ccost_menu_select, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
    }

    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetRightSoftkeyFunction( mmi_clog_close_ccost_scrn, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_menu_select
 * DESCRIPTION
 *  ccost menu item select handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_menu_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();
    U16 menu_id = cntx->hilite_menu_id;
    MMI_ID pin2_cui;
    mmi_sim_enum sim = MMI_SIM1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_id == MENU_ID_CLOG_CCOST_RESET || menu_id == MENU_ID_CLOG_CCOST_MAX || menu_id == MENU_ID_CLOG_CCOST_PPU)
    {
        if (!srv_nw_usab_is_usable(cntx->sim_id))
        {
            mmi_clog_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_CLOG_CALL_COST, NULL);
            return;
        }

        cntx->hilite_sim = mmi_frm_sim_to_index(cntx->sim_id);
        if (srv_sim_ctrl_pwd_is_enabled(cntx->sim_id, SRV_SIM_CTRL_PWD_TYPE_CHV2))
        {
            sim = cntx->sim_id;
        }
        else
        {
            mmi_clog_ccost_pass_pin2_cb();
            return;
        }
            
    }

    g_pin2_cui = pin2_cui = cui_verify_create(GRP_ID_CLOG_CALL_COST, CUI_VERIFY_TYPE_CHV2);
    cui_verify_set_sim(pin2_cui, sim);
    cui_verify_run(pin2_cui);
}

#else /* (MMI_MAX_SIM_NUM >= 3) */


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

const static mmi_clog_sub_menu_map_struct g_clog_ccost_menu_map[] = 
{
    {MMI_SIM1, MENU_ID_CLOG_CCOST_LAST}
    , {MMI_SIM1, MENU_ID_CLOG_CCOST_TOTAL}
    , {MMI_SIM1, MENU_ID_CLOG_CCOST_RESET}
    , {MMI_SIM1, MENU_ID_CLOG_CCOST_MAX}
    , {MMI_SIM1, MENU_ID_CLOG_CCOST_PPU}
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
static void mmi_clog_ccost_set_menu_hidden(void);
static void mmi_clog_ccost_counter_set_hint(void);
static void mmi_clog_ccost_set_lsk_str(MMI_MENU_ID menu_id);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/




/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ccost_counter_int
 * DESCRIPTION
 *  entry ccost conter screen
 * PARAMETERS
 *  parent_gid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_ccost_counter_int(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_CCOST_SHOW_MENU_CUI,
        GRP_ID_CLOG_CALL_COST,
        mmi_frm_group_get_active_id());

    cntx->cui = cui_menu_create(
                                    GRP_ID_CLOG_CALL_COST,
                                    CUI_MENU_SRC_TYPE_RESOURCE,
                                    CUI_MENU_TYPE_APPSUB,
                                    MENU_ID_CLOG_CALL_COST,
                                    MMI_TRUE,
                                    NULL);
    cui_menu_set_default_title_by_id(
        cntx->cui,
        STR_ID_CLOG_CALL_COST,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG));
    mmi_clog_ccost_set_menu_hidden();
    cui_menu_run(cntx->cui);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ccost_proc
 * DESCRIPTION
 *  proc of menu cui.
 *  It needs to handle the menu cui event like entry, select and exit.
 *  It needs to handle the inline cui event
 * PARAMETERS
 *  evt     [IN]        Event structure pointer
 * RETURNS
 *  MMI_RET_OK: process successfully
 *  Others: process fail
 *****************************************************************************/
static MMI_RET mmi_clog_enter_ccost_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_clog_ccost_free_cntx();
            break;
            
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_set_currlist_flags(cntx->cui, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            mmi_clog_ccost_counter_set_hint();

            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            mmi_clog_ccost_set_lsk_str(menu_evt->highlighted_menu_id);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_clog_ccost_menu_select();
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            cntx->cui = GRP_ID_INVALID;

            mmi_frm_group_close(GRP_ID_CLOG_CALL_COST);
            break;
        }

        /* Set max cost */
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        {
            cui_fseditor_get_text(
                cntx->editor_cui,
                cntx->max_cost[cntx->hilite_sim],
                20);
            mmi_clog_ccost_verfiy_max_cost();
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT: /* ? abort maybe have issue */
        {
            cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct*) evt;

            cui_fseditor_close(editor_evt->sender_id);
            cntx->editor_cui = GRP_ID_INVALID;
            break;
        }

        /* PPU Inline event start */
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct*) evt;

            cui_inline_get_value(
                inline_evt->sender_id,
                MMI_PPU_PRICE_EDIT_ID1,
                cntx->price[cntx->hilite_sim]);

            cui_inline_get_value(
                inline_evt->sender_id,
                MMI_PPU_UNIT_EDIT_ID3,
                cntx->unit[cntx->hilite_sim]);

            mmi_clog_ccost_verfiy_ppu();
            /* cui_inline_close(inline_evt->sender_id); // need to verify */
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *inline_abort_event;

            inline_abort_event = (cui_event_inline_abort_struct*) evt;
            cui_inline_close(inline_abort_event->sender_id);
            cntx->inline_cui = GRP_ID_INVALID;
            break;
        }
        
        /* PIN2 input screen event start */
        case EVT_ID_CUI_VERIFY_RESULT:
        {
            cui_verify_result_evt_struct *result_evt;
            result_evt = (cui_verify_result_evt_struct*) evt;
        
            if (result_evt->success)
            {
                mmi_clog_ccost_pass_pin2_cb();
            }            
            cui_verify_close(result_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_VERIFY_CANCEL:
        {
            cui_verify_cancel_evt_struct *cancel_evt;
            cancel_evt = (cui_verify_cancel_evt_struct*) evt;
            cui_verify_close(cancel_evt->sender_id);
            break;
        }

	case EVT_ID_GROUP_ACTIVE:
	{
			/* SIM 1 and sim 2 */
			if (!srv_nw_usab_is_usable(MMI_SIM1)
	        #ifdef __MMI_DUAL_SIM__
/* under construction !*/
                #endif
				)
            {
                cui_verify_close(g_pin2_cui);	
            }
			
	    break;		
	}

        /* Popup or Confirm event start */
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;

            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_clog_ccost_save_hdlr();
                    break;

                case MMI_ALERT_CNFM_NO:
                    mmi_clog_ccost_close_editor_inline_cui();
                    break;

                case MMI_ALERT_NORMAL_EXIT:
                {
                    
                     if (
		          cntx->hilite_menu_id == MENU_ID_CLOG_CCOST_PPU
	                  #ifdef __MMI_DUAL_SIM__
/* under construction !*/
			#endif /*__MMI_DUAL_SIM__*/
			)
                    {
                    srv_clog_ccost_get_data(
                        (mmi_sim_enum)MMI_SIM_ALL,
                        SRV_CLOG_CCOST_FIELD_ALL,
                        cntx,
                        mmi_clog_ccost_get_data_cb);
                    memset(
                        &cntx->data[cntx->hilite_sim],
                        0,
                        sizeof(srv_clog_ccost_data_struct));
                      }
			else if (cntx->hilite_menu_id == 0)
			{
			    mmi_frm_group_close(GRP_ID_CLOG_CALL_COST);
			}
                    break;
                }

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
 *  mmi_clog_ccost_set_menu_hidden
 * DESCRIPTION
 *  call cost (sim1 and sim2) counter menu hidden or unhidden handler
 * PARAMETERS
 *  void
 *  index(?)        [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_set_menu_hidden(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menu_count;
    S32 i;
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_count = sizeof(g_clog_ccost_menu_map) / sizeof(mmi_clog_sub_menu_map_struct);

    for (i = 0; i < menu_count; i++)
    {
        if (cntx->get_data_ret[g_clog_ccost_menu_map[i].sim_id - 1] == 0)
        {
            cui_menu_set_item_hidden(cntx->cui, g_clog_ccost_menu_map[i].menu_id, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(cntx->cui, g_clog_ccost_menu_map[i].menu_id, MMI_FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_counter_set_hint
 * DESCRIPTION
 *  ccost (sim1 and sim2) counter hint handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_counter_set_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sim;
    U16 menu_idx;
    U32 temp_data;
    WCHAR temp_str[MAX_SUBMENU_CHARACTERS];
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sim = 0, menu_idx = 0; sim < MMI_SIM_TOTAL; sim++)
    {
        if ((cntx->data[sim].last % 1000) != 0)
        {
            kal_wsprintf(temp_str, "%u.%u",
                cntx->data[sim].last / 1000,
                cntx->data[sim].last % 1000);
        }
        else
        {
            kal_wsprintf(temp_str, "%u", cntx->data[sim].last / 1000);
        }
        cui_menu_set_item_hint(cntx->cui, g_clog_ccost_menu_map[menu_idx++].menu_id, temp_str);

        temp_data = cntx->data[sim].total;
        kal_wsprintf(temp_str, "%d", temp_data);
        cui_menu_set_item_hint(cntx->cui, g_clog_ccost_menu_map[menu_idx++].menu_id, temp_str);

        menu_idx++; /* For menu Reset cost */

        temp_data = cntx->data[sim].max;
        kal_wsprintf(temp_str, "%d", temp_data);
        cui_menu_set_item_hint(cntx->cui, g_clog_ccost_menu_map[menu_idx++].menu_id, temp_str);

        if (cntx->data[sim].currency[0] != 0)
            kal_wsprintf(temp_str, "%w %w", cntx->data[sim].ppu, cntx->data[sim].currency);
        else
            kal_wsprintf(temp_str, "%w", cntx->data[sim].ppu);
        cui_menu_set_item_hint(cntx->cui, g_clog_ccost_menu_map[menu_idx++].menu_id, temp_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_set_lsk_str
 * DESCRIPTION
 *  ccost (sim1 and sim2) counter hint handler
 * PARAMETERS
 *  menu_id         [IN]        
 *  index(?)        [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_set_lsk_str(MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->hilite_menu_id = menu_id;

    cui_menu_change_center_softkey_content(cntx->cui, NULL, get_image(IMG_GLOBAL_COMMON_CSK));

    switch (menu_id)
    {
        case MENU_ID_CLOG_CCOST_RESET:
            cui_menu_change_left_softkey_string_by_id(cntx->cui, STR_GLOBAL_OK);
            break;

        case MENU_ID_CLOG_CCOST_MAX:
        case MENU_ID_CLOG_CCOST_PPU:
            cui_menu_change_left_softkey_string_by_id(cntx->cui, STR_ID_CLOG_CCOST_SET);
            break;

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

        default:
            cui_menu_change_left_softkey_string(cntx->cui, NULL);
            cui_menu_change_center_softkey_content(cntx->cui, NULL, NULL);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_menu_select
 * DESCRIPTION
 *  ccost menu item select handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_menu_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();
    U16 menu_id = cntx->hilite_menu_id;
    MMI_ID pin2_cui;
    mmi_sim_enum sim = MMI_SIM1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_id == MENU_ID_CLOG_CCOST_RESET || menu_id == MENU_ID_CLOG_CCOST_MAX || menu_id == MENU_ID_CLOG_CCOST_PPU)
    {
        cntx->sim_id = MMI_SIM1;
        if (!srv_nw_usab_is_usable(MMI_SIM1))
        {
            mmi_clog_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_CLOG_CALL_COST, NULL);
            return;
        }

        cntx->hilite_sim = 0;   /* means sim1 */
        if (srv_sim_ctrl_pwd_is_enabled(MMI_SIM1, SRV_SIM_CTRL_PWD_TYPE_CHV2))
        {
            sim = MMI_SIM1;
        }
        else
        {
            mmi_clog_ccost_pass_pin2_cb();
            return;
        }
            
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */
    else
    {
        return;
    }

    g_pin2_cui = pin2_cui = cui_verify_create(GRP_ID_CLOG_CALL_COST, CUI_VERIFY_TYPE_CHV2);
    cui_verify_set_sim(pin2_cui, sim);
    cui_verify_run(pin2_cui);
}


#endif /* (MMI_MAX_SIM_NUM >= 3) */


/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

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
static mmi_clog_ccost_cntx_struct *mmi_clog_ccost_new_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_clog_ccost_cntx_p)
        OslMfree(mmi_clog_ccost_cntx_p);
    mmi_clog_ccost_cntx_p = OslMalloc(sizeof(mmi_clog_ccost_cntx_struct));
    memset(mmi_clog_ccost_cntx_p, 0x0, sizeof(mmi_clog_ccost_cntx_struct));
    mmi_clog_ccost_cntx_p->is_used = MMI_TRUE;
    return mmi_clog_ccost_cntx_p;
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
static void mmi_clog_ccost_free_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_clog_ccost_cntx_p)
    {   
        OslMfree(mmi_clog_ccost_cntx_p);
        mmi_clog_ccost_cntx_p = NULL;
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
static mmi_clog_ccost_cntx_struct *mmi_clog_ccost_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clog_ccost_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ccost
 * DESCRIPTION
 *  Entry screen for ccost (at most include sim1 & sim2 last sent/last received/
 *  all sent/all recvd/reset counter
 * PARAMETERS
 *  parent_gid      [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_enter_ccost(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;
    mmi_clog_ccost_cntx_struct *cntx = mmi_clog_ccost_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*re-entry case */
    if (cntx)
        return;
    
    cntx = mmi_clog_ccost_new_cntx();
    cntx->parent_gid = parent_gid;
    cntx->cui = GRP_ID_INVALID;

    mmi_frm_group_create_ex(parent_gid, GRP_ID_CLOG_CALL_COST, mmi_clog_enter_ccost_proc, cntx, MMI_FRM_NODE_NONE_FLAG);//MMI_FRM_NODE_SMART_CLOSE_FLAG

    sim_id = (mmi_sim_enum)MMI_SIM_ALL;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_CCOST_ENTRER_CCOST, parent_gid, sim_id);

    srv_clog_ccost_get_data(sim_id, SRV_CLOG_CCOST_FIELD_ALL, cntx, mmi_clog_ccost_get_data_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_get_data_cb
 * DESCRIPTION
 *  ccost (sim1 and sim2) counter get data callback function
 * PARAMETERS
 *  user_data       [?]         
 *  sim_id          [IN]        
 *  fields          [IN]        
 *  data            [IN]        
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_clog_ccost_get_data_cb(
            void *user_data,
            mmi_sim_enum sim_id,
            U32 fields,
            const srv_clog_ccost_data_struct *data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index;
    MMI_BOOL ret_flag = MMI_FALSE;
    mmi_clog_ccost_cntx_struct *cntx  = (mmi_clog_ccost_cntx_struct*)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx != mmi_clog_ccost_get_cntx() || !cntx->is_used)
        return SRV_CLOG_RET_STOP;
    
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_CCOST_GET_DATA_CB, sim_id, fields, more, ret);

    index = mmi_frm_sim_to_index(sim_id);
    cntx->get_data_ret[index] = 1;
    if (ret != SRV_CLOG_RET_OK)
    {
        cntx->get_data_ret[index] = 0;
    }
 
    memcpy(&cntx->data[index], data, sizeof(srv_clog_ccost_data_struct));
    kal_wsprintf(cntx->max_cost[index], "%u", cntx->data[index].max);

    if (more == MMI_FALSE)
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (cntx->get_data_ret[i] != 0)
                ret_flag = MMI_TRUE;
        }
        if (ret_flag == MMI_FALSE)
        {
            mmi_clog_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);//GRP_ID_CLOG_CALL_COST
            mmi_frm_group_close(GRP_ID_CLOG_CALL_COST);
            return SRV_CLOG_RET_STOP;
        }
    
    #if (MMI_MAX_SIM_NUM >= 3)
        if (SCR_ID_CLOG_CALL_COST == mmi_frm_scrn_get_active_id())
        {
            mmi_frm_display_dummy_screen();
            mmi_frm_scrn_close_active_id();
            return;
        }
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    
        if (cntx->cui != GRP_ID_INVALID)
        {
        #if (MMI_MAX_SIM_NUM >= 3)
            // to refresh screen
        #else
            cui_menu_refresh_currlist(cntx->cui);
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        }
        else
            mmi_clog_enter_ccost_counter_int(GRP_ID_CLOG_CALL_COST);

        return SRV_CLOG_RET_STOP;
    }
    else
    {
        return SRV_CLOG_RET_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_pass_pin2_cb
 * DESCRIPTION
 *  handler function after input right PIN2 code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_pass_pin2_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();
    U16 menu_id = cntx->hilite_menu_id;
    srv_clog_ccost_data_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
        case MENU_ID_CLOG_CCOST_RESET:
            /* data.last = 0; */
            data.total = 0;
            srv_clog_ccost_set_data(
                cntx->sim_id,
                SRV_CLOG_CCOST_FIELD_TOTAL,
                (const srv_clog_ccost_data_struct*)&data,
                NULL,
                cntx,
                mmi_clog_ccost_reset_cost_cb);
            break;

        case MENU_ID_CLOG_CCOST_MAX:
            mmi_clog_ccost_entry_set_max_cost();
            break;

        case MENU_ID_CLOG_CCOST_PPU:
            mmi_clog_ccost_entry_set_ppu();
            break;
            
    #if (MMI_MAX_SIM_NUM >= 3)
    #else /* (MMI_MAX_SIM_NUM >= 3) */
    #ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_DUAL_SIM__ */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */

        default:
            break;
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_reset_cost_cb
 * DESCRIPTION
 *  ccost counter common reset handler function
 * PARAMETERS
 *  user_data       [?]         
 *  sim_id          [IN]        
 *  fields          [IN]        
 *  ret             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_clog_ccost_reset_cost_cb(void *user_data, mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_ccost_data_struct *data;
    mmi_clog_ccost_cntx_struct *cntx  = (mmi_clog_ccost_cntx_struct*)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx != mmi_clog_ccost_get_cntx() || !cntx->is_used)
        return SRV_CLOG_RET_STOP;
    
    data = &cntx->data[cntx->hilite_sim];   

    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_ccost_display_popup(MMI_FALSE);
        return SRV_CLOG_RET_FAIL;
    }
    else
    {
        /* data->last = 0; */
        data->total = 0;
        mmi_clog_ccost_display_popup(MMI_TRUE);
        return SRV_CLOG_RET_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_entry_set_max_cost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_entry_set_max_cost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 fseditor_gid;
    U16 title_icon;
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fseditor_gid = cui_fseditor_create(GRP_ID_CLOG_CALL_COST);

    if (fseditor_gid != GRP_ID_INVALID)
    {
        title_icon = GetRootTitleIcon(MAIN_MENU_CALL_LOG);

        cui_fseditor_set_title(fseditor_gid, STR_ID_CLOG_CCOST_SET_MAX, title_icon);

    #if (MMI_MAX_SIM_NUM >= 3)
        kal_wsprintf(cntx->max_cost[cntx->hilite_sim], "%u", cntx->data[cntx->hilite_sim].max);
    #endif
        cui_fseditor_set_text(fseditor_gid, cntx->max_cost[cntx->hilite_sim], 20, 8);

        cui_fseditor_set_input_method(
            /* how to input 0 in begin ? */ fseditor_gid,
            IMM_INPUT_TYPE_NUMERIC,
            NULL,
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

        cui_fseditor_set_softkey_text(fseditor_gid, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
        cui_fseditor_set_softkey_icon(fseditor_gid, MMI_LEFT_SOFTKEY, IMG_GLOBAL_OK);
        cui_fseditor_set_softkey_text(fseditor_gid, MMI_CENTER_SOFTKEY, 0);
        cui_fseditor_set_softkey_icon(fseditor_gid, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);

        cntx->editor_cui = fseditor_gid;

        cui_fseditor_run(fseditor_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_verfiy_max_cost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_verfiy_max_cost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();
    CHAR acsii_max_cost_str[MMI_CLOG_CCOST_MAX_LEN];
    U32 max_cost_value;
    MMI_BOOL is_valid_input = MMI_TRUE;
    WCHAR *max_p = cntx->max_cost[cntx->hilite_sim];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_wcslen((const WCHAR*)max_p) == 0)
    {
        is_valid_input = MMI_FALSE;
    }
    else
    {
        mmi_ucs2_to_asc(acsii_max_cost_str, (CHAR*) max_p);
        max_cost_value = atoi(acsii_max_cost_str);
        if (max_cost_value > MMI_CLOG_CCOST_MAX_COST)
        {
            is_valid_input = MMI_FALSE;
        }
    }

    if (is_valid_input == MMI_FALSE)
    {
        /* mmi_display_popup_with_sg(GRP_ID_CLOG_CALL_COST, get_string(STR_GLOBAL_INVALID_INPUT), MMI_EVENT_FAILURE, 0); */
        mmi_clog_popup(STR_GLOBAL_INVALID_INPUT, MMI_EVENT_FAILURE, GRP_ID_CLOG_CALL_COST, NULL);
        return;
    }
    else
    {
        mmi_clog_ccost_save_confirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_entry_set_ppu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_entry_set_ppu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cui_inline_item_caption_struct price_caption;
    cui_inline_item_text_edit_struct price_edit;
    cui_inline_item_caption_struct unit_caption;
    cui_inline_item_text_edit_struct unit_edit;
    cui_inline_set_item_struct ppu_inline_items[MMI_PPU_INLINE_TOTAL];
    cui_inline_struct inline_struct;
    MMI_ID ppu_inline_cui_id;
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cui inline struct define */
    set_leading_zero(FALSE);

    price_caption.string_id = STR_ID_CLOG_CCOST_PRICE;

    price_edit.string_id = 0;
    price_edit.default_text_id = 0;
    price_edit.buffer_size = 20;
    price_edit.input_type = IMM_INPUT_TYPE_DECIMAL_NUMERIC;
    price_edit.input_extended_type = 0;
    price_edit.required_input_mode_set = NULL;

    unit_caption.string_id = STR_ID_CLOG_CCOST_UNIT;

    unit_edit.string_id = 0;
    unit_edit.default_text_id = 0;
    unit_edit.buffer_size = 4;
    unit_edit.input_type = IMM_INPUT_TYPE_ENGLISH_SENTENCE;
    unit_edit.input_extended_type = 0;
    unit_edit.required_input_mode_set = NULL;

    ppu_inline_items[0].item_id = MMI_PPU_PRICE_CAPTION_ID0;
    ppu_inline_items[0].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
    ppu_inline_items[0].image_id = 0;
    ppu_inline_items[0].item_data = &price_caption;

    ppu_inline_items[1].item_id = MMI_PPU_PRICE_EDIT_ID1;
    ppu_inline_items[1].item_flag =
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_LEFT_JUSTIFY |
        CUI_INLINE_ITEM_NO_LEADING_ZERO | CUI_INLINE_ITEM_FULL_WIDTH;
    ppu_inline_items[1].image_id = 0;
    ppu_inline_items[1].item_data = &price_edit;

    ppu_inline_items[2].item_id = MMI_PPU_UNIT_CAPTION_ID2;
    ppu_inline_items[2].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_FULL_WIDTH;
    ppu_inline_items[2].image_id = 0;
    ppu_inline_items[2].item_data = &unit_caption;

    ppu_inline_items[3].item_id = MMI_PPU_UNIT_EDIT_ID3;
    ppu_inline_items[3].item_flag =
        CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_BOUNDARY | CUI_INLINE_ITEM_LEFT_JUSTIFY |
        CUI_INLINE_ITEM_FULL_WIDTH;
    ppu_inline_items[3].image_id = 0;
    ppu_inline_items[3].item_data = &unit_edit;

    inline_struct.items_count = 4;
    inline_struct.title = STR_ID_CLOG_CCOST_SET_PPU;
    inline_struct.title_icon = GetRootTitleIcon(MAIN_MENU_CALL_LOG);
    inline_struct.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE;
    inline_struct.softkey = NULL;
    inline_struct.items = ppu_inline_items;

    ppu_inline_cui_id = cui_inline_create(GRP_ID_CLOG_CALL_COST, &inline_struct);
    cui_inline_set_value(
        ppu_inline_cui_id,
        MMI_PPU_PRICE_EDIT_ID1,
        cntx->data[cntx->hilite_sim].ppu);
    cui_inline_set_value(
        ppu_inline_cui_id,
        MMI_PPU_UNIT_EDIT_ID3,
        cntx->data[cntx->hilite_sim].currency);

    cntx->inline_cui = ppu_inline_cui_id;

    cui_inline_run(ppu_inline_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_verfiy_ppu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_verfiy_ppu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0, num = 0;
    CHAR temp_ppu[40];
    MMI_BOOL is_valid_str = MMI_TRUE;
    CHAR first_four_digit_ppu[5];
    U32 first_four_digit_value;
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();
    WCHAR *price_p = cntx->price[cntx->hilite_sim];
    WCHAR *unit_p = cntx->unit[cntx->hilite_sim];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(temp_ppu, (CHAR*) price_p);

    while (count < 40 && temp_ppu[count] != 0)
    {
        if (temp_ppu[count] <= '9' && temp_ppu[count] >= '0')
        {
            num++;
        }
        if (temp_ppu[count++] == '.')
        {
            break;
        }
    }
    /* overflow */
    if ((count > 11 && num > 11) || count == 0)
    {
        is_valid_str = MMI_FALSE;
    }
    else if (num == 11)
    {
        memset(first_four_digit_ppu, 0x00, 5);
        for (count = 0; count < 4; count++)
        {
            first_four_digit_ppu[count] = temp_ppu[count];
        }
        first_four_digit_value = atoi(first_four_digit_ppu);
        /* according to spec 11.11, max value of first four digit will be 4095 = 2^11 + 2^10 + ... _ 2^0 */
        if (first_four_digit_value > 4095)
        {
            is_valid_str = MMI_FALSE;
        }
    }

    if (!is_valid_str)
    {
        mmi_clog_popup(STR_GLOBAL_INVALID_INPUT, MMI_EVENT_FAILURE, GRP_ID_CLOG_CALL_COST, NULL);
        return;
    }

    /* check price unit */
    for (count = 0; count < 3; count++)
    {
        if (unit_p[count] == '\0')
        {
            break;
        }
        if ((unit_p[count] == '.') || (unit_p[count] == ',') ||
            (unit_p[count] == '-') || (unit_p[count] == '?') ||
            (unit_p[count] == '!') || (unit_p[count] == '\'') ||
            (unit_p[count] == '@') || (unit_p[count] == ':') ||
            (unit_p[count] == '#') || (unit_p[count] == '/') ||
            (unit_p[count] == '_') || ((unit_p[count] >= '0') && (unit_p[count] <= '9')))
        {
            is_valid_str = MMI_FALSE;
            break;
        }
    }

    if (!is_valid_str)
    {
        mmi_clog_popup(STR_GLOBAL_INVALID_INPUT, MMI_EVENT_FAILURE, GRP_ID_CLOG_CALL_COST, NULL);
        return;
    }
    else
    {
        mmi_clog_ccost_save_confirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_save_confirm
 * DESCRIPTION
 *  ccost counter common set confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_save_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_save_hdlr
 * DESCRIPTION
 *  call time common reset counter value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_save_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;
    U32 save_field;
    srv_clog_ccost_data_struct req_data;
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->hilite_menu_id == MENU_ID_CLOG_CCOST_MAX)
    {
        CHAR acsii_max_cost_str[MMI_CLOG_CCOST_MAX_LEN];
        WCHAR *max_p = cntx->max_cost[cntx->hilite_sim];

        mmi_ucs2_to_asc(acsii_max_cost_str, (CHAR*) max_p);
        req_data.max = atoi(acsii_max_cost_str);

        sim_id = cntx->sim_id;
        save_field = SRV_CLOG_CCOST_FIELD_MAX;
    }
    else if (cntx->hilite_menu_id == MENU_ID_CLOG_CCOST_PPU)
    {
        WCHAR *price_p = cntx->price[cntx->hilite_sim];
        WCHAR *unit_p = cntx->unit[cntx->hilite_sim];

        mmi_wcscpy(req_data.ppu, price_p);
        mmi_wcscpy(req_data.currency, unit_p);
        sim_id = cntx->sim_id;
        save_field = SRV_CLOG_CCOST_FIELD_PUC;
    }

#if (MMI_MAX_SIM_NUM >= 3)
#else /* (MMI_MAX_SIM_NUM >= 3) */
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */ 
#endif /* (MMI_MAX_SIM_NUM >= 3) */

    else
    {
        return;
    }

    srv_clog_ccost_set_data(
        sim_id,
        save_field,
        (const srv_clog_ccost_data_struct*)&req_data,
        NULL,
        cntx,
        mmi_clog_ccost_save_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_save_cb
 * DESCRIPTION
 *  common popup function
 * PARAMETERS
 *  user_data       [?]         
 *  sim_id          [IN]        
 *  fields          [IN]        
 *  ret             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_clog_ccost_save_cb(void *user_data, mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cntx  != mmi_clog_ccost_get_cntx() || !cntx->is_used)
        return SRV_CLOG_RET_STOP;
    
    if (ret != SRV_CLOG_RET_OK)
    {
        mmi_clog_ccost_display_popup(MMI_FALSE);
        mmi_clog_ccost_close_editor_inline_cui();
        return SRV_CLOG_RET_FAIL;
    }

    if (cntx->hilite_menu_id == MENU_ID_CLOG_CCOST_MAX)
    {
        CHAR acsii_max_cost_str[MMI_CLOG_CCOST_MAX_LEN];
        WCHAR *max_p = cntx->max_cost[cntx->hilite_sim];

        mmi_ucs2_to_asc(acsii_max_cost_str, (CHAR*) max_p);
        cntx->data[cntx->hilite_sim].max = atoi(acsii_max_cost_str);
    }
    else if (cntx->hilite_menu_id == MENU_ID_CLOG_CCOST_PPU)
    {
        WCHAR *price_p = cntx->price[cntx->hilite_sim];
        WCHAR *unit_p = cntx->unit[cntx->hilite_sim];

        mmi_wcscpy(cntx->data[cntx->hilite_sim].ppu, price_p);
        mmi_wcscpy(cntx->data[cntx->hilite_sim].currency, unit_p);
    }

#if (MMI_MAX_SIM_NUM >= 3)
#else /* (MMI_MAX_SIM_NUM >= 3) */
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */ 
#endif /* (MMI_MAX_SIM_NUM >= 3) */

    else
    {
        return SRV_CLOG_RET_FAIL;
    }
    mmi_clog_ccost_close_editor_inline_cui();
    return SRV_CLOG_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_close_editor_inline_cui
 * DESCRIPTION
 *  In editor/inline cui, show save confrim, then after press Yes/No both to close
 *  this two cui, and back to call cost main menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_close_editor_inline_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_ccost_cntx_struct *cntx  = mmi_clog_ccost_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->inline_cui != GRP_ID_INVALID)
    {
        cui_inline_close(cntx->inline_cui);
        cntx->inline_cui = GRP_ID_INVALID;
    }
    if (cntx->editor_cui != GRP_ID_INVALID)
    {
        kal_wsprintf(
            cntx->max_cost[cntx->hilite_sim],
            "%u",
            cntx->data[cntx->hilite_sim].max);

        cui_fseditor_close(cntx->editor_cui);
        cntx->editor_cui = GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_ccost_display_popup
 * DESCRIPTION
 *  common popup function
 * PARAMETERS
 *  ok_flag     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_ccost_display_popup(MMI_BOOL ok_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ok_flag == MMI_TRUE)
    {
        mmi_clog_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_CLOG_CALL_COST, NULL);
    }
    else
    {
        mmi_clog_popup(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, GRP_ID_CLOG_CALL_COST, NULL);
    }
}

#endif /* __MMI_CLOG_CALL_COST__ */

