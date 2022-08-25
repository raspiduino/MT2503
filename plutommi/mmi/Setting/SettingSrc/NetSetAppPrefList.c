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
 * NetSetAppPrefList.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is UI flow of network setup prefer network list
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_PREF_NETWORK__
#include "MMIDataType.h"

/***************************************************************************** 
* Include
*****************************************************************************/
#include "NetSetAppProt.h"

#include "NetSetSrvProt.h"
#include "NetSetSrvGprot.h"

#include "plmnenum.h"

#include "GlobalResDef.h"
#include "mmi_rp_app_netset_def.h"
#include "MENUCuiGprot.h"
#include "InlineCUIGprot.h"

/* auto add by kw_check begin */
#include "ps_public_enum.h"
#include "custom_mmi_default_value.h"
#include "ImeGprot.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "sim_common_enums.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_msg_struct.h"
#include "l4crac_enums.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "gui.h"
#include "CommonScreensResDef.h"
#include "NetSetAppGprot.h"
/* auto add by kw_check end */
/***************************************************************************** 
* External Variable
*****************************************************************************/
typedef struct
{
    U8 pref_plmn[MAX_PLMN_LEN + 1];
    U8 rat;
    U8 index;
    U8 unused[3];
} mmi_netset_pref_info_cntx_struct;

typedef struct 
{
    U16 state;
    U16 pref_list_size;
    U16 sim_file_idx;
    U16 sel_add_plmn_idx;   //selected network item of plmn list
    U16 sel_pref_item;      //high light item of main prefer network

    mmi_netset_pref_info_cntx_struct pref_info[MAX_PREFFERED_PLMN]; //all valid prefer network
    mmi_netset_pref_info_cntx_struct add_pref;  //save need add prefer network information
    mmi_netset_pref_info_cntx_struct del_pref;  //save need delete prefer network information
} mmi_netset_pref_list_cntx_struct;

typedef struct 
{
    /* prefer network list for SIM */
    U16 pref_icon[MAX_PREFFERED_PLMN];      //prefer network list icon
    U8* plmn_str_ptr[MAX_PREFFERED_PLMN];   //prefer network list string 
    U8 pref_plmn_display[MAX_PREFFERED_PLMN][MAX_NW_NAME_LEN * ENCODING_LENGTH];
    U8 pref_plmn_index[MAX_PREFFERED_PLMN]; /* index of PLMN list */

    /* temp prefer network */
    U8 add_plmn[(MAX_PLMN_LEN + 1) * ENCODING_LENGTH];  //add plmn UCS2 buffer
    U8 NewNwPriorityDisplay[MAX_PREFFERED_PLMN];
    S32 priority_value;     //selected priority 
    S32 rat_value;  //selected RAT 
} mmi_netset_disp_pref_list_struct;

typedef enum
{
    MMI_NETSET_PREF_LIST_IDLE,
    MMI_NETSET_PREF_LIST_GET,
    MMI_NETSET_PREF_LIST_SET_ADD,
    MMI_NETSET_PREF_LIST_SET_NEW,
    MMI_NETSET_PREF_LIST_SET_DEL,
    MMI_NETSET_PREF_LIST_SET_EDIT,
    MMI_NETSET_PREF_LIST_CHECK,
    MMI_NETSET_PREF_LIST_MAX
} mmi_netset_pref_list_state_enum;

static mmi_netset_pref_list_cntx_struct g_netset_pref_list_cntx;
static mmi_netset_disp_pref_list_struct g_netset_disp_pref_list;

/* Inline CUI */
static MMI_ID g_netset_pref_list_inline_gid;
static cui_inline_item_caption_struct g_netset_pref_list_mcc_mnc_str_id = {STR_ID_NETSET_PREF_LIST_MCC_MNC};
static cui_inline_item_caption_struct g_netset_pref_list_priority_str_id = {STR_GLOBAL_PRIORITY};
static cui_inline_item_text_edit_struct g_netset_pref_list_mcc_mnc_edit = 
{
    0,
    0,
    MAX_PLMN_LEN + 1, 
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
static cui_inline_set_item_struct g_netset_pref_list_new_inline_data[] =
{
    {(CUI_INLINE_ITEM_ID_BASE + 1), CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_netset_pref_list_mcc_mnc_str_id},
    {(CUI_INLINE_ITEM_ID_BASE + 2), CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_netset_pref_list_mcc_mnc_edit},
    {(CUI_INLINE_ITEM_ID_BASE + 3), CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_netset_pref_list_priority_str_id},
    {(CUI_INLINE_ITEM_ID_BASE + 4), CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT, 0, NULL},
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
#endif
};
static const cui_inline_struct g_netset_pref_list_new_inline = 
{
    sizeof(g_netset_pref_list_new_inline_data)/sizeof(cui_inline_set_item_struct),
    STR_ID_NETSET_PREF_LIST,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_netset_pref_list_new_inline_data    
};
static cui_inline_set_item_struct g_netset_pref_list_edit_inline_data[] =
{
    {(CUI_INLINE_ITEM_ID_BASE + 1), CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_netset_pref_list_priority_str_id},
    {(CUI_INLINE_ITEM_ID_BASE + 2), CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT, 0, NULL}
};
static const cui_inline_struct g_netset_pref_list_edit_inline = 
{
    sizeof(g_netset_pref_list_edit_inline_data)/sizeof(cui_inline_set_item_struct),
    STR_ID_NETSET_PREF_LIST,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_netset_pref_list_edit_inline_data    
};
static cui_inline_set_item_struct g_netset_pref_list_other_inline_data[] =
{
    {(CUI_INLINE_ITEM_ID_BASE + 1), CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_netset_pref_list_priority_str_id},
    {(CUI_INLINE_ITEM_ID_BASE + 2), CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT, 0, NULL},
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)    
/* under construction !*/
/* under construction !*/
#endif
};
static const cui_inline_struct g_netset_pref_list_other_inline = 
{
    sizeof(g_netset_pref_list_other_inline_data)/sizeof(cui_inline_set_item_struct),
    STR_ID_NETSET_PREF_LIST,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_netset_pref_list_other_inline_data    
};

static MMI_BOOL g_netset_is_processing;
static MMI_BOOL g_netset_inline_is_initialized; /* When inline is not initialized, priority will be loaded */
static mmi_id g_change_priority_popup_id;
/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
extern mmi_netset_cntx_struct *g_netset_cntx_ptr;
CHAR *gServiceString[3];

#define  PLMN_NAME_LENGTH     30    /* PLMN string length */

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* Network Setup Preferred Network List */
static void mmi_pre_entry_netset_pref_list(void);
static void mmi_entry_netset_pref_list_scr(void);
static void mmi_netset_fill_pref_list_info(void *info);
static mmi_ret mmi_netset_get_pref_list_rsp(mmi_event_struct *ptr_rsp);
static pBOOL mmi_netset_get_preferred_networks_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 mmi_netset_get_preferred_networks_hint(S32 item_index, UI_string_type *hint_array);

static void mmi_netset_pref_list_entry_add_network_common_info(void);
/*static void mmi_netset_pref_list_fill_add_network_common_info(void);*/

/* get network name with plmn */
static U16 mmi_netset_get_pref_nw_name_from_plmn(void);

/* Entry Network Setup Preferred Network List Option Screen */
static void mmi_entry_netset_pref_list_option(void);

static mmi_ret mmi_netset_pref_list_change_network_rsp(mmi_event_struct *ptr_rsp);
static void mmi_netset_pref_list_change_network_check(void);

/* Entry Network Setup Preferred Network List Opt Add flow */
static void mmi_entry_netset_pref_list_opt_add_show_plmn_list(void);
static pBOOL mmi_netset_pref_list_opt_add_get_nwk_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 mmi_netset_pref_list_opt_add_get_nwk_list_hint(S32 item_index, UI_string_type *hint_array);


/* Entry Network Setup Preferred Network List Opt New flow */
/*static void mmi_exit_netset_pref_list_opt_new(void);*/

/* Entry Network Setup Preferred Network List Opt Edit flow */

/* Entry Network Setup Preferred Network List Opt Delete flow */
static void mmi_entry_netset_pref_list_opt_del_confirm(void);
static void mmi_entry_netset_pref_list_opt_del_confirm_ok(void);
static mmi_ret mmi_netset_pref_list_opt_del_rsp(mmi_event_struct *ptr_rsp);

static U8 *InLinePriorityMinusOne(void);
static U8 *InLinePriorityDefault(void);
static U8 *InLinePriorityAddOne(void);

/***************************************************************************** 
* External Function
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_init_netset_pref_list
 * DESCRIPTION
 *  This function is initial function of Network Setup -> Preferred Network List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_init_netset_pref_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    g_netset_pref_list_cntx.state = MMI_NETSET_PREF_LIST_IDLE;
}

/* Network Setup Prefer Network List */
/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netset_pref_list
 * DESCRIPTION
 *  Entry Preferred network setting from network setting 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_netset_pref_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_idx = mmi_netset_get_active_sim();
       
    if(srv_netset_get_noof_plmn_supported(sim_idx)==0)
    {
        mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNFINISHED),  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        return;
    }
    g_netset_disp_pref_list.priority_value = 0;
    mmi_pre_entry_netset_pref_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pre_entry_netset_pref_list
 * DESCRIPTION
 *  This function is function to get prefer list before enter preferred network list
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pre_entry_netset_pref_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE1(0, "[NetSetAppPrefList.c] mmi_pre_entry_netset_pref_list PLMN support num is [%d]", srv_netset_get_noof_plmn_supported(mmi_netset_get_active_sim()));

    g_netset_pref_list_cntx.state = MMI_NETSET_PREF_LIST_GET;
    srv_netset_get_pref_list(MMI_NETSET_CURRENT_SIM, mmi_netset_get_pref_list_rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_pref_list
 * DESCRIPTION
 *  This function is to get high light inex of prefer network list
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_highlight_pref_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_netset_pref_list_cntx.sel_pref_item = (U16)index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netset_pref_list_scr
 * DESCRIPTION
 *  This function is to enter preferred network list
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_netset_pref_list_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *gui_buffer = NULL;
	S32 highlight_idx = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_scr()");
	
	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_MAIN, 
		SCR_ID_NETSET_PREF_LIST, 
		NULL, 
		mmi_entry_netset_pref_list_scr, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

	gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_PREF_LIST);

    g_netset_pref_list_cntx.state = MMI_NETSET_PREF_LIST_IDLE;
	
    RegisterHighlightHandler(mmi_netset_highlight_pref_list);
    if (g_netset_disp_pref_list.priority_value != 0)
	{
	    highlight_idx = g_netset_disp_pref_list.priority_value - 1;
	}
    if (!g_netset_pref_list_cntx.pref_list_size)
    {
        g_netset_disp_pref_list.plmn_str_ptr[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        ShowCategory6Screen(
            STR_ID_NETSET_PREF_LIST,
            GetRootTitleIcon(MENU_ID_NETSET_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            g_netset_disp_pref_list.plmn_str_ptr,
            NULL,
            0,
            gui_buffer);
    }
    else
    {
        if (g_netset_pref_list_cntx.sim_file_idx != FILE_PLMNSEL_IDX)
        {
            ShowCategory184Screen(
                STR_ID_NETSET_PREF_LIST,
                GetRootTitleIcon(MENU_ID_NETSET_MAIN),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_netset_pref_list_cntx.pref_list_size,
                mmi_netset_get_preferred_networks_item,
                mmi_netset_get_preferred_networks_hint,
                highlight_idx,
                gui_buffer);
        }
        else
        {
            ShowCategory284Screen(
                STR_ID_NETSET_PREF_LIST,
                GetRootTitleIcon(MENU_ID_NETSET_MAIN),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_netset_pref_list_cntx.pref_list_size,
                mmi_netset_get_preferred_networks_item,
                mmi_netset_get_preferred_networks_hint,
                highlight_idx,
                gui_buffer);
        }
    }
    
#ifdef __MMI_FTE_SUPPORT__
    //wgui_register_tap_callback(mmi_netset_show_pref_list_screen_fte_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */
    
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(mmi_entry_netset_pref_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	
	ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
	SetCenterSoftkeyFunction(mmi_entry_netset_pref_list_option, KEY_EVENT_UP);
    /* Add for prohibit highlight move when delete PLMN, MAUI_02442020 */
    if (g_netset_is_processing)
	{
	    ClearInputEventHandler(MMI_DEVICE_ALL);
	}
}	


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_pref_list_rsp
 * DESCRIPTION
 *  This function is response function of get prefer network list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_get_pref_list_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_preferred_oper_list_rsp_struct *rsp_msg = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    rsp_msg = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.get_pref_list_rsp_data;
	NETSET_TRACE1(0, "[NetSetAppPrefList.c] mmi_netset_get_pref_list_rsp(%d)", rsp_msg->result);    
    if (rsp_msg->retnum == 0 || rsp_msg->result == MMI_FALSE)
    {
        mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNFINISHED),  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        return MMI_RET_OK;
    }
    else
    {
        mmi_netset_fill_pref_list_info(rsp_msg);
        mmi_entry_netset_pref_list_scr();
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_fill_pref_list_info
* DESCRIPTION
*  This function fills prefer network list
* PARAMETERS
*  void
*  Number(?)       [OUT]       Of elements in the array
* RETURNS
*  U16
*****************************************************************************/
static void mmi_netset_fill_pref_list_info(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0, index = 0;
    mmi_smu_get_preferred_oper_list_rsp_struct *pref_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_netset_fill_pref_list_info()");
    pref_info = (mmi_smu_get_preferred_oper_list_rsp_struct*) info;

    g_netset_pref_list_cntx.sim_file_idx = pref_info->file_idx_rsp;

    for (count = 0, g_netset_pref_list_cntx.pref_list_size = 0; count < pref_info->retnum; count++)
    {
        if (g_netset_pref_list_cntx.pref_list_size >= MAX_PREFFERED_PLMN)
        {
            break;
        }

        /* oper_list item is valid */
        if ((pref_info->oper_list[count * (MAX_PLMN_LEN + 1)] != 0X3F) &&
            (pref_info->oper_list[count * (MAX_PLMN_LEN + 1)] != 0X00))
        {
            U8 rat = 0;
            U16 icon = 0;

            /* save prefer network list item real index */
            g_netset_pref_list_cntx.pref_info[g_netset_pref_list_cntx.pref_list_size].index = count;

            /* save plmn id to local */
            for (index = 0; index < (MAX_PLMN_LEN + 1); index++)
            {
                g_netset_pref_list_cntx.pref_info[g_netset_pref_list_cntx.pref_list_size].pref_plmn[index] =
                    pref_info->oper_list[index + count * (MAX_PLMN_LEN + 1)];
            }

            g_netset_pref_list_cntx.pref_info[g_netset_pref_list_cntx.pref_list_size].pref_plmn[MAX_PLMN_LEN] = 0;

            /* get rat type and prefer network item icon */
            if ((pref_info->rat_list[count * 2] & 0x80) == 0x80 &&
                (pref_info->rat_list[count * 2 + 1] & 0x80) == 0x00)
            {
                rat = L4C_RAT_UMTS;
                icon = IMG_SI_3G;
            }
            else if ((pref_info->rat_list[count * 2] & 0x80) == 0x00 &&
                (pref_info->rat_list[count * 2 + 1] & 0x80) == 0x80)
            {
                rat = L4C_RAT_GSM;
                icon = IMG_SI_2G;
            }
            else if ((pref_info->rat_list[count * 2] & 0x80) == 0x80 &&
                (pref_info->rat_list[count * 2 + 1] & 0x80) == 0x80)
            {
                rat = L4C_RAT_GSM_UMTS;
                icon = IMG_SI_GPRS_INDICATOR;
            }
            else
            {
                rat = L4C_RAT_NONE;
                icon = IMG_NONE;
            }

            g_netset_pref_list_cntx.pref_info[g_netset_pref_list_cntx.pref_list_size].rat = rat;

            /* set preferred network list icon */
            if (g_netset_pref_list_cntx.sim_file_idx != FILE_PLMNSEL_IDX)
            {
                g_netset_disp_pref_list.pref_icon[g_netset_pref_list_cntx.pref_list_size] = icon;
            }

            g_netset_pref_list_cntx.pref_list_size++;
        }
    }

    /* get preferred network list display name with plmn */
    mmi_netset_get_pref_nw_name_from_plmn();
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_get_pref_nw_name_from_plmn
* DESCRIPTION
*  This function fills up the array for preferred network name of numbers
* PARAMETERS
*  void
* RETURNS
*  U16
*****************************************************************************/
static U16 mmi_netset_get_pref_nw_name_from_plmn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U16 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_netset_get_pref_nw_name_from_plmn()");
    if (g_netset_pref_list_cntx.pref_list_size > MAX_PREFFERED_PLMN)
    {
        g_netset_pref_list_cntx.pref_list_size = MAX_PREFFERED_PLMN;
    }
    
    for (count = 0; count < g_netset_pref_list_cntx.pref_list_size; count++)
    {
        g_netset_disp_pref_list.plmn_str_ptr[count] = NULL;
    }
    
    for (count = 0; count < g_netset_pref_list_cntx.pref_list_size; count++, index++)
    {
        mmi_netset_retrieve_opname_from_plmn(g_netset_pref_list_cntx.pref_info[count].pref_plmn, 
            (U8*)g_netset_disp_pref_list.pref_plmn_display[count]);

        g_netset_disp_pref_list.plmn_str_ptr[count] = (PU8) g_netset_disp_pref_list.pref_plmn_display[count];
    }

    return count;
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_get_preferred_networks_item
* DESCRIPTION
*  Dynamically get preferred networks items
* PARAMETERS
*  item_index          [IN]        
*  str_buff            [IN]        
*  img_buff_p          [?]         
*  str_img_mask        [IN]        
* RETURNS
*  pBOOL
*****************************************************************************/
static pBOOL mmi_netset_get_preferred_networks_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) str_buff, (CHAR*) g_netset_disp_pref_list.plmn_str_ptr[item_index]);
    /* Only when FILE_PLMNWACT_IDX availabe will display RAT icon */
    *img_buff_p = 0;
    if (g_netset_pref_list_cntx.sim_file_idx == FILE_PLMNWACT_IDX)
    {
    *img_buff_p = get_image(g_netset_disp_pref_list.pref_icon[item_index]);
    }
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_netset_get_preferred_networks_hint
* DESCRIPTION
*  Dynamically get preferred networks items
* PARAMETERS
*  item_index      [IN]        
*  hint_array      [?]         
*  UI_string_type str_buff(?)
* RETURNS
*  S32
*****************************************************************************/
S32 mmi_netset_get_preferred_networks_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempDislpay[MAX_NW_NAME_LEN * ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((CHAR*) tempDislpay, (CHAR*) g_netset_pref_list_cntx.pref_info[item_index].pref_plmn);
    
    /* Skip the hint if the item data and hint data are the same as plmn number */
    if (mmi_ucs2cmp((CHAR*) g_netset_disp_pref_list.plmn_str_ptr[item_index], (CHAR*) tempDislpay) == 0)
    {
        return MMI_FALSE;
    }
    
    mmi_ucs2cpy((CHAR*) * hint_array, (CHAR*) tempDislpay);
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_option
* DESCRIPTION
*  Function to entry preferred network list option screen
* PARAMETERS
* 
* RETURNS
*  
*****************************************************************************/
static void mmi_entry_netset_pref_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_option()");

	menu_cui_id = cui_menu_create(
		GRP_ID_NETSET_MAIN, 
		CUI_MENU_SRC_TYPE_RESOURCE, 
		CUI_MENU_TYPE_OPTION, 
		MENU_ID_NETSET_PREF_LIST_OPTION, 
		MMI_FALSE, 
		NULL);
    
    cui_menu_run(menu_cui_id);
}


void mmi_update_pref_list_option_menu(cui_menu_event_struct *evt)
{
    cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST_OPTION_ADD, MMI_FALSE);
    cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST_OPTION_NEW, MMI_FALSE);
    cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST_OPTION_EDIT, MMI_FALSE);
    cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST_OPTION_DELETE, MMI_FALSE);
    // TODO: Remove checks, not needed
    if (g_netset_pref_list_cntx.pref_list_size >= MAX_PREFFERED_PLMN
        || g_netset_pref_list_cntx.pref_list_size >= srv_netset_get_noof_plmn_supported(mmi_netset_get_active_sim()))
    {
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST_OPTION_ADD, MMI_TRUE);
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST_OPTION_NEW, MMI_TRUE);
    }

    if (g_netset_pref_list_cntx.pref_list_size == 0)
    {
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST_OPTION_EDIT, MMI_TRUE);
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_NETSET_PREF_LIST_OPTION_DELETE, MMI_TRUE);
    }
    cui_menu_set_default_title_image(evt->sender_id, (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_NETSET_MAIN)));
}

/* Network Setup -> Preferred Network List -> Option -> Add */
/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_opt_add
* DESCRIPTION
*  Entry function of preferred network list option add menu
* PARAMETERS
*  void   
* RETURNS
*  
*****************************************************************************/
void mmi_entry_netset_pref_list_opt_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_opt_add()");

    memset(&g_netset_pref_list_cntx.add_pref, 0x00, sizeof(mmi_netset_pref_info_cntx_struct));
    memset(&g_netset_pref_list_cntx.del_pref, 0x00, sizeof(mmi_netset_pref_info_cntx_struct));

    g_netset_pref_list_cntx.state = MMI_NETSET_PREF_LIST_SET_ADD;

    mmi_entry_netset_pref_list_opt_add_show_plmn_list();
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_highlight_add_plmn_list
* DESCRIPTION
*  Entry function of sort plmn list by default
* PARAMETERS
*  void   
* RETURNS
*  
*****************************************************************************/
static void mmi_netset_highlight_add_plmn_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_netset_pref_list_cntx.sel_add_plmn_idx = (U16)index;
}


/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_opt_add_show_plmn_list
* DESCRIPTION
*  Entry function of preferred network list option add
* PARAMETERS
*  void   
* RETURNS
*  
*****************************************************************************/
static void mmi_entry_netset_pref_list_opt_add_show_plmn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U8 *gui_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_opt_add_show_plmn_list()");
	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_MAIN, 
		SCR_ID_NETSET_PREF_LIST_OPT_ADD_NWK_LIST, 
		NULL, 
		mmi_entry_netset_pref_list_opt_add_show_plmn_list, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
	gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_PREF_LIST_OPT_ADD_NWK_LIST);

    /* get high light index of plmn list */
    RegisterHighlightHandler(mmi_netset_highlight_add_plmn_list);

    index =  srv_netset_get_system_plmn_number();
    
    ShowCategory284Screen(
        STR_ID_NETSET_PRF_ADD_SHW_NWK_TITLE,
        GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        STR_GLOBAL_SELECT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        mmi_netset_pref_list_opt_add_get_nwk_list_item,
        mmi_netset_pref_list_opt_add_get_nwk_list_hint,
        0,
        gui_buffer);

#ifdef __MMI_FTE_SUPPORT__
    //wgui_register_tap_callback(mmi_netset_add_pref_list_screen_fte_tap_callback);
#endif /* __MMI_FTE_SUPPORT__ */

    SetLeftSoftkeyFunction(mmi_netset_pref_list_entry_add_network_common_info, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_netset_pref_list_entry_add_network_common_info, KEY_EVENT_UP);

}



/*****************************************************************************
* FUNCTION
*  mmi_netset_pref_list_opt_add_get_nwk_list_item
* DESCRIPTION
*  Return Item for dynamic category screen
* PARAMETERS
*  item_index          [IN]        
*  str_buff            [IN]        
*  img_buff_p          [?]         
*  str_img_mask        [IN]        
* RETURNS
*  void
*****************************************************************************/
static pBOOL mmi_netset_pref_list_opt_add_get_nwk_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }
    /* 20 is the max length for operator name */
    srv_netset_get_sys_plmn_opname(item_index, (WCHAR*)str_buff, 20);
    *img_buff_p = NULL;
    
    return TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_pref_list_opt_add_get_nwk_list_hint
* DESCRIPTION
*  Return Hint for dynamic category screen
* PARAMETERS
*  item_index      [IN]        
*  hint_array      [?]         
* RETURNS
*  void
*****************************************************************************/
static S32 mmi_netset_pref_list_opt_add_get_nwk_list_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buffer[MAX_PLMN_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }
    srv_netset_get_sys_plmn_mccmnc(item_index, (CHAR*)buffer, MAX_PLMN_LEN + 1);
    mmi_asc_to_wcs((WCHAR*)(*hint_array), buffer);
    return TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_pref_list_entry_add_network_common_info
* DESCRIPTION
*  Entry function of preferred network list add from list or new
* PARAMETERS
*  void   
* RETURNS
*  void
*****************************************************************************/
static void mmi_netset_pref_list_entry_add_network_common_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_netset_pref_list_entry_add_network_common_info()");

    switch (g_netset_pref_list_cntx.state)
	{
	case MMI_NETSET_PREF_LIST_SET_NEW:
        g_netset_pref_list_inline_gid = cui_inline_create(GRP_ID_NETSET_MAIN, &g_netset_pref_list_new_inline);
        memset(g_netset_disp_pref_list.add_plmn, 0x00, (MAX_PLMN_LEN + 1) * ENCODING_LENGTH);
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
        #endif
        cui_inline_set_title_string(g_netset_pref_list_inline_gid, (UI_string_type)GetString(STR_ID_NETSET_PRF_NWK_NEW));
        /* Hide RAT type if SIM file is not PLMNWACT */
        if (g_netset_pref_list_cntx.sim_file_idx != FILE_PLMNWACT_IDX)
    	{
    	    cui_inline_delete_item(g_netset_pref_list_inline_gid, (CUI_INLINE_ITEM_ID_BASE + 5));
    	    cui_inline_delete_item(g_netset_pref_list_inline_gid, (CUI_INLINE_ITEM_ID_BASE + 6));
    	}        
		break;

    case MMI_NETSET_PREF_LIST_SET_EDIT:
        g_netset_pref_list_inline_gid = cui_inline_create(GRP_ID_NETSET_MAIN, &g_netset_pref_list_edit_inline);        
        cui_inline_set_title_string(g_netset_pref_list_inline_gid, (UI_string_type)GetString(STR_GLOBAL_PRIORITY));	    
		break;

	default:
        g_netset_pref_list_inline_gid = cui_inline_create(GRP_ID_NETSET_MAIN, &g_netset_pref_list_other_inline);        		
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
        #endif
        if (g_netset_pref_list_cntx.state == MMI_NETSET_PREF_LIST_SET_ADD)
    	{
            cui_inline_set_title_string(g_netset_pref_list_inline_gid, (UI_string_type)GetString(STR_GLOBAL_PRIORITY));	    
    	}        
        /* Hide RAT type if SIM file is not PLMNWACT */
        if (g_netset_pref_list_cntx.sim_file_idx != FILE_PLMNWACT_IDX)
    	{
    	    cui_inline_delete_item(g_netset_pref_list_inline_gid, (CUI_INLINE_ITEM_ID_BASE + 3));
    	    cui_inline_delete_item(g_netset_pref_list_inline_gid, (CUI_INLINE_ITEM_ID_BASE + 4));
    	}            
        break;
	}
    cui_inline_run(g_netset_pref_list_inline_gid);
}


static U8 mmi_netset_pref_plmn_is_duplicated(mmi_smu_set_preferred_oper_list_req_struct *add_pref)
{
	U8 index = 0;

	for (index = 0; index < g_netset_pref_list_cntx.pref_list_size; index++)
	{
		if (strcmp((CHAR*)add_pref->oper, (CHAR*)g_netset_pref_list_cntx.pref_info[index].pref_plmn) == 0)
		{
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
			{
				return 1;
			}
		}
	}

	return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_pref_list_change_network_check
* DESCRIPTION
*  Check function of preferred network list add from list and select 
* PARAMETERS
*  void   
* RETURNS
*  void
*****************************************************************************/
static void mmi_netset_pref_list_change_network_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_req_struct *add_pref_req = NULL;
    mmi_smu_set_preferred_oper_list_req_struct *del_pref_req = NULL;
    mmi_popup_property_struct progress_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_netset_pref_list_change_network_check()");
    //if (g_netset_pref_list_cntx.sim_file_idx != FILE_PLMNSEL_IDX)
    {
        //CloseCategory57Screen(); // cong zhou
    }

	NETSET_TRACE1(0, "[NetSetAppPrefList.c] g_netset_pref_list_cntx.state is %d", g_netset_pref_list_cntx.state);
    if (g_netset_is_processing)
	{
	    return;
	}
    g_netset_is_processing = MMI_TRUE;

    switch(g_netset_pref_list_cntx.state)
    {
    case MMI_NETSET_PREF_LIST_SET_ADD:
        {
            add_pref_req = OslMalloc(sizeof(mmi_smu_set_preferred_oper_list_req_struct));

            memset(add_pref_req, 0x00, sizeof(mmi_smu_set_preferred_oper_list_req_struct));

            add_pref_req->index = g_netset_disp_pref_list.priority_value - 1;

            srv_netset_get_sys_plmn_mccmnc(g_netset_pref_list_cntx.sel_add_plmn_idx, (CHAR*)add_pref_req->oper, (MAX_PLMN_LEN + 1));
            
            #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
            #endif            
            
            add_pref_req->rat = (g_netset_pref_list_cntx.sim_file_idx == FILE_PLMNSEL_IDX) ? \
                0 : (U8) g_netset_disp_pref_list.rat_value + 1;

        }
    	break;

    case MMI_NETSET_PREF_LIST_SET_NEW:
        {
            add_pref_req = OslMalloc(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
            
            memset(add_pref_req, 0x00, sizeof(mmi_smu_set_preferred_oper_list_req_struct));
            
            add_pref_req->index = g_netset_disp_pref_list.priority_value - 1;

            memset(g_netset_disp_pref_list.add_plmn, 0, (MAX_PLMN_LEN + 1) * ENCODING_LENGTH);
            
            cui_inline_get_value(g_netset_pref_list_inline_gid, (CUI_INLINE_ITEM_ID_BASE + 2), (void*)g_netset_disp_pref_list.add_plmn);            
            
            mmi_ucs2_to_asc((CHAR*) add_pref_req->oper, (CHAR*) g_netset_disp_pref_list.add_plmn);

            add_pref_req->oper[MAX_PLMN_LEN] = 0;

            #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
            #endif  
            
            add_pref_req->rat = (g_netset_pref_list_cntx.sim_file_idx == FILE_PLMNSEL_IDX) ? \
                0 : (U8) g_netset_disp_pref_list.rat_value + 1;

        }
    	break;

    case MMI_NETSET_PREF_LIST_SET_EDIT:
        {
            U16 hilite_item = 0;

            hilite_item = g_netset_pref_list_cntx.sel_pref_item;

            add_pref_req = OslMalloc(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
            del_pref_req = OslMalloc(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
            
            memset(add_pref_req, 0x00, sizeof(mmi_smu_set_preferred_oper_list_req_struct));
            memset(del_pref_req, 0x00, sizeof(mmi_smu_set_preferred_oper_list_req_struct));
            
            add_pref_req->index = g_netset_pref_list_cntx.pref_info[g_netset_disp_pref_list.priority_value - 1].index;
            del_pref_req->index = g_netset_pref_list_cntx.pref_info[hilite_item].index;
            
            memcpy(add_pref_req->oper, g_netset_pref_list_cntx.pref_info[hilite_item].pref_plmn, (MAX_PLMN_LEN + 1));
            memcpy(del_pref_req->oper, g_netset_pref_list_cntx.pref_info[hilite_item].pref_plmn, (MAX_PLMN_LEN + 1));
            add_pref_req->oper[MAX_PLMN_LEN] = 0;
            del_pref_req->oper[MAX_PLMN_LEN] = 0;

            add_pref_req->rat = g_netset_pref_list_cntx.pref_info[hilite_item].rat;
            del_pref_req->rat = add_pref_req->rat;
        }
        break;

    default:
        break;
    }

	if ((g_netset_pref_list_cntx.state == MMI_NETSET_PREF_LIST_SET_ADD)
		|| (g_netset_pref_list_cntx.state == MMI_NETSET_PREF_LIST_SET_NEW))
	{
		
		if (strlen((CHAR*)add_pref_req->oper) < (MAX_PLMN_LEN - 1))
		{
			if (add_pref_req)
			{
				OslMfree(add_pref_req);
				add_pref_req = NULL;
			}
                        g_netset_is_processing = MMI_FALSE;
			mmi_popup_display_simple_ext(STR_ID_NETSET_PRF_NWK_INVALID_MCCMNC,  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
			return;
		}

		if (mmi_netset_pref_plmn_is_duplicated(add_pref_req))
		{
			if (add_pref_req)
			{
				OslMfree(add_pref_req);
				add_pref_req = NULL;
			}
                        g_netset_is_processing = MMI_FALSE;
			mmi_popup_display_simple_ext(STR_ID_NETSET_PRF_NWK_ADDED_ERR,  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
			return;
		}
	}

    if (add_pref_req)
    {
        g_netset_pref_list_cntx.add_pref.index = add_pref_req->index;
        memcpy(g_netset_pref_list_cntx.add_pref.pref_plmn, add_pref_req->oper, (MAX_PLMN_LEN + 1));
        g_netset_pref_list_cntx.add_pref.rat = add_pref_req->rat;
    }

    if (del_pref_req)
    {
        g_netset_pref_list_cntx.del_pref.index = del_pref_req->index;
        memcpy(g_netset_pref_list_cntx.del_pref.pref_plmn, del_pref_req->oper, (MAX_PLMN_LEN + 1));
        g_netset_pref_list_cntx.del_pref.rat = del_pref_req->rat;
    }
    /* Change priority, may cost more time, display processing screen for MAUI_02442346 */
    mmi_popup_property_init(&progress_popup);
    progress_popup.parent_id = GRP_ID_ROOT;
    progress_popup.callback = NULL;
    progress_popup.f_auto_dismiss = MMI_FALSE;
    g_change_priority_popup_id = mmi_popup_display_ext(STR_GLOBAL_PLEASE_WAIT, MMI_EVENT_PROGRESS, &progress_popup);
    
    srv_netset_set_pref_list(MMI_NETSET_CURRENT_SIM, del_pref_req, add_pref_req, mmi_netset_pref_list_change_network_rsp, NULL);
    
    if (add_pref_req)
    {
        OslMfree(add_pref_req);
        add_pref_req = NULL;
    }

    if (del_pref_req)
    {
        OslMfree(del_pref_req);
        del_pref_req = NULL;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_netset_pref_list_change_network_rsp
* DESCRIPTION
*  network setup add prefer network list response
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_netset_pref_list_change_network_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_rsp_struct *local = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.set_pref_list_rsp_data;
	NETSET_TRACE1(0, "[NetSetAppPrefList.c] mmi_netset_pref_list_change_network_rsp(%d)", local->result);    
    if (g_change_priority_popup_id)
    {
        mmi_alert_dismiss(g_change_priority_popup_id);
	g_change_priority_popup_id = 0;
    }
    if (local->result == MMI_FALSE)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_UNFINISHED,  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
    else
#if 0
#ifdef __MMI_NETSET_PREF_LIST_CHECK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_NETSET_PREF_LIST_CHECK__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_NETSET_PREF_LIST_CHECK__ */
#endif
    g_netset_is_processing = MMI_FALSE;
    mmi_pre_entry_netset_pref_list();

    cui_inline_close(g_netset_pref_list_inline_gid);
    mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_PREF_LIST_OPT_ADD_NWK_LIST);
    mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_PREF_LIST);
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  InLinePriorityDefault
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 *InLinePriorityDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_netset_inline_is_initialized)
    {
        if (g_netset_pref_list_cntx.state == MMI_NETSET_PREF_LIST_SET_EDIT)
	{
            g_netset_disp_pref_list.priority_value = g_netset_pref_list_cntx.sel_pref_item + 1;
            ASSERT(g_netset_disp_pref_list.priority_value <= g_netset_pref_list_cntx.pref_list_size + 1);
	}
        else
        {
            g_netset_disp_pref_list.priority_value = g_netset_pref_list_cntx.pref_list_size + 1;
        }
        g_netset_inline_is_initialized = MMI_TRUE;
    }
    gui_itoa(g_netset_disp_pref_list.priority_value, (UI_string_type) g_netset_disp_pref_list.NewNwPriorityDisplay, 10);
    return g_netset_disp_pref_list.NewNwPriorityDisplay;
}


/*****************************************************************************
* FUNCTION
*  InLinePriorityMinusOne
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 *InLinePriorityMinusOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 priority_maximum;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_netset_pref_list_cntx.state == MMI_NETSET_PREF_LIST_SET_EDIT)
	{
        priority_maximum = g_netset_pref_list_cntx.pref_list_size;
    }   
    else
    {
        priority_maximum = g_netset_pref_list_cntx.pref_list_size + 1;
    }
    
    g_netset_disp_pref_list.priority_value--;
    if (g_netset_disp_pref_list.priority_value <= 0)
    {
        g_netset_disp_pref_list.priority_value = priority_maximum;
    }
    
    gui_itoa(g_netset_disp_pref_list.priority_value, (UI_string_type)g_netset_disp_pref_list.NewNwPriorityDisplay, 10);
    return g_netset_disp_pref_list.NewNwPriorityDisplay;
}


/*****************************************************************************
* FUNCTION
*  InLinePriorityAddOne
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 *InLinePriorityAddOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 priority_maximum;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_netset_pref_list_cntx.state == MMI_NETSET_PREF_LIST_SET_EDIT)
	{
        priority_maximum = g_netset_pref_list_cntx.pref_list_size;
    }   
    else
    {
        priority_maximum = g_netset_pref_list_cntx.pref_list_size + 1;
    }
    
    if (g_netset_disp_pref_list.priority_value < priority_maximum)
    {
        g_netset_disp_pref_list.priority_value++;
    }
    else
    {
        g_netset_disp_pref_list.priority_value = 1;
    }
    gui_itoa(g_netset_disp_pref_list.priority_value, (UI_string_type) g_netset_disp_pref_list.NewNwPriorityDisplay, 10);    
    return g_netset_disp_pref_list.NewNwPriorityDisplay;
}


/* Network Setup -> Prefer Network Option -> New */
/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_opt_new
* DESCRIPTION
*  Entry function of prefer network list option New Menu
* PARAMETERS
*  plmn        [?]     
*  opname      [?]     
* RETURNS
*  
*****************************************************************************/
void mmi_entry_netset_pref_list_opt_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_opt_new()");
    memset(&g_netset_pref_list_cntx.add_pref, 0x00, sizeof(mmi_netset_pref_info_cntx_struct));
    memset(&g_netset_pref_list_cntx.del_pref, 0x00, sizeof(mmi_netset_pref_info_cntx_struct));

    g_netset_pref_list_cntx.state = MMI_NETSET_PREF_LIST_SET_NEW;

    mmi_netset_pref_list_entry_add_network_common_info();
}
/* Network Setup -> Prefer Network Option -> New */


/* Network Setup -> Prefer Network Option -> Edit */
/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_opt_edit
* DESCRIPTION
*  Entry function of prefer network list option Edit Menu
* PARAMETERS
*  plmn        [?]     
*  opname      [?]     
* RETURNS
*  
*****************************************************************************/
void mmi_entry_netset_pref_list_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_opt_edit()");
    memset(&g_netset_pref_list_cntx.add_pref, 0x00, sizeof(mmi_netset_pref_info_cntx_struct));
    memset(&g_netset_pref_list_cntx.del_pref, 0x00, sizeof(mmi_netset_pref_info_cntx_struct));

    g_netset_pref_list_cntx.state = MMI_NETSET_PREF_LIST_SET_EDIT;
    
    mmi_netset_pref_list_entry_add_network_common_info();
}
/* Network Setup -> Prefer Network Option -> Edit */


/* Network Setup -> Prefer Network Option -> Delete */
/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_opt_del
* DESCRIPTION
*  Entry function of prefer network list option Delete Menu
* PARAMETERS
*  plmn        [?]     
*  opname      [?]     
* RETURNS
*  
*****************************************************************************/
void mmi_entry_netset_pref_list_opt_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_opt_del()");
    memset(&g_netset_pref_list_cntx.add_pref, 0x00, sizeof(mmi_netset_pref_info_cntx_struct));
    memset(&g_netset_pref_list_cntx.del_pref, 0x00, sizeof(mmi_netset_pref_info_cntx_struct));
    
    g_netset_pref_list_cntx.state = MMI_NETSET_PREF_LIST_SET_DEL;
    
    mmi_entry_netset_pref_list_opt_del_confirm();
}


/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_opt_del_confirm
* DESCRIPTION
*  Entry confirm screen of prefer network list option Delete Menu
* PARAMETERS
*  plmn        [?]     
*  opname      [?]     
* RETURNS
*  
*****************************************************************************/
static void mmi_entry_netset_pref_list_opt_del_confirm(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_opt_del_confirm()");
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
    confirm_arg.callback = NULL;
    confirm_arg.parent_id = GRP_ID_NETSET_MAIN;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_NETSET_DELETE_QUERY),
        MMI_EVENT_QUERY,
        &confirm_arg); 
	
	ChangeCenterSoftkey(0, 0);
}


/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_opt_del_confirm_ok
* DESCRIPTION
*  Function to remove selected prefer network from list
* PARAMETERS
*  void   
* RETURNS
*  void
*****************************************************************************/
static void mmi_entry_netset_pref_list_opt_del_confirm_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilite_item = 0;
    mmi_smu_set_preferred_oper_list_req_struct *del_pref_req = NULL;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_opt_del_confirm_ok()");

	ClearInputEventHandler(MMI_DEVICE_ALL);
    g_netset_is_processing = MMI_TRUE;

    hilite_item = g_netset_pref_list_cntx.sel_pref_item;
    
    del_pref_req = OslMalloc(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    
    memset(del_pref_req, 0x00, sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    
    del_pref_req->index = g_netset_pref_list_cntx.pref_info[hilite_item].index;
    
    memcpy(del_pref_req->oper, g_netset_pref_list_cntx.pref_info[hilite_item].pref_plmn, (MAX_PLMN_LEN + 1));
    del_pref_req->oper[MAX_PLMN_LEN] = 0;
    
    del_pref_req->rat = g_netset_pref_list_cntx.pref_info[hilite_item].rat;

    if (del_pref_req)
    {
        g_netset_pref_list_cntx.del_pref.index = del_pref_req->index;
        memcpy(g_netset_pref_list_cntx.del_pref.pref_plmn, del_pref_req->oper, (MAX_PLMN_LEN + 1));
        g_netset_pref_list_cntx.del_pref.rat = del_pref_req->rat;
    }

    srv_netset_set_pref_list(MMI_NETSET_CURRENT_SIM, del_pref_req, NULL, mmi_netset_pref_list_opt_del_rsp, NULL);

    if (del_pref_req)
    {
        OslMfree(del_pref_req);
        del_pref_req = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_entry_netset_pref_list_opt_del_confirm_ok
* DESCRIPTION
*  Function to remove selected prefer network from list
* PARAMETERS
*  void   
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_netset_pref_list_opt_del_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_rsp_struct *del_pref_rsp = NULL;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    del_pref_rsp = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.set_pref_list_rsp_data;
	NETSET_TRACE1(0, "[NetSetAppPrefList.c] mmi_netset_pref_list_opt_del_rsp(%d)", del_pref_rsp->result);
    g_netset_is_processing = MMI_FALSE;
        if (del_pref_rsp->result)
        {
            mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DELETED),  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        }
        else
        {
            mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNFINISHED),  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        }

    mmi_pre_entry_netset_pref_list();
    return MMI_RET_OK;
}
/* Network Setup Prefer Network List */

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pref_list_proc
 * DESCRIPTION
 *  Proc function for netset preferred list 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
mmi_ret mmi_netset_pref_list_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
	{
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        mmi_netset_pref_list_change_network_check();
        return MMI_RET_OK;
        
    case EVT_ID_CUI_INLINE_ABORT:
        if (!g_netset_is_processing)
    	{
            cui_inline_close(g_netset_pref_list_inline_gid);
    	}
        return MMI_RET_OK;
        
    case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)param;
            switch (confirm_evt->result)
        	{
        	case MMI_ALERT_CNFM_YES:
                mmi_entry_netset_pref_list_opt_del_confirm_ok();
                break;
                
            case MMI_ALERT_CNFM_NO:    		
                mmi_frm_scrn_close_active_id();
        		break;
                
        	default:
        		break;
        	}
            return MMI_RET_OK;	        
        }
    
	case EVT_ID_CUI_INLINE_NOTIFY:
		{
			cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)param;		
			if (notify_evt->event_type == CUI_INLINE_NOTIFY_USER_DEFINED_SELECT_SET_FOCUS)
			{
				switch(notify_evt->param)
                {
                case CUI_INLINE_USERDEFINEDSELECT_NEXT:
                    return (mmi_ret)InLinePriorityAddOne();

				case CUI_INLINE_USERDEFINEDSELECT_PRE:
					return (mmi_ret)InLinePriorityMinusOne();

                case CUI_INLINE_USERDEFINEDSELECT_CUR:
			        return (mmi_ret)InLinePriorityDefault();

                default:
                    ASSERT(0);
				}
    		}
            return MMI_RET_OK;
    	}    
    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        /* reset the flag */
        g_netset_inline_is_initialized = MMI_FALSE; 
        break;
        
    default:
        break;
    }
    return MMI_RET_DONT_CARE;
}

#endif /* __MMI_PREF_NETWORK__ */

