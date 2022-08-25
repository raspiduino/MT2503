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
 * NetSetAppNWSelect.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is UI flow of network setup -> network selection 
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

#include "MMIDataType.h"

/***************************************************************************** 
* Include
*****************************************************************************/
#include "NetSetAppProt.h"

#include "NetSetSrvProt.h"
#include "NetSetSrvGprot.h"

#include "L3_inc_enums.h"   /* AUTOMATIC_MODE & MANUAL_MODE enum */
#include "custom_events_notify.h"   /* Display popup event enum */
#include "UCMSrvGprot.h"
#include "plmnenum.h"   /* for STR_PLMN_1 string */

#include "NWInfoSrvGprot.h"
#include "mmi_rp_app_netset_def.h"

#include "MENUCuiGprot.h"
#include "UcmSrvGprot.h" //for background call checking

/* auto add by kw_check begin */
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "mmi_msg_struct.h"
#include "ps_public_enum.h"
#include "l4crac_enums.h"
#include "ps_public_struct.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "l4c_aux_struct.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "string.h"
#include "SimCtrlSrvGprot.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "wgui_categories_list.h"
#include "mmi_frm_history_gprot.h"
#include "gui_data_types.h"
/* auto add by kw_check end */
#include "NetSetAppGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "UcmGProt.h"
#include "UcmSrvGprot.h"
#include "app_plmn.h"
#include "NwUsabSrvGprot.h"
#ifdef __REL7__
#include "EonsSrvGprot.h"
#endif
 #include "ModeSwitchAppGprot.h"   
#include "DmSrvGprot.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern const U16 gIndexIconsImageList[];

static mmi_netset_nw_search_disp_cntx_struct g_netset_nw_search_disp_cntx;    /* SIM1 and SIM2 use same context */
static MMI_BOOL g_netset_netsel_is_progressing;
#ifdef  __MMI_NETSET_SLIM__
static MMI_BOOL g_netset_is_auto;
#endif

#define  PLMN_NAME_LENGTH     30    /* PLMN string length */

/***************************************************************************** 
* Local Function
*****************************************************************************/

/* Auto Network Register */
#ifndef __MMI_NETSET_SLIM__
static mmi_ret mmi_set_netsel_auto_rsp(mmi_event_struct* ptr_rsp);
#endif
static void mmi_entry_netsel_progress(void);

/* Manual Network Operation */
static void mmi_entry_netsel_manual_search_progress(void);
static mmi_ret mmi_netset_get_plmn_rsp(mmi_event_struct *ptr_rsp);

static void mmi_entry_netsel_manual_search_show_plmn_list(void);
static void mmi_set_netsel_manual_with_idx(U8 index);
static void mmi_set_netsel_manual(void);
static mmi_ret mmi_set_netsel_manual_rsp(mmi_event_struct *ptr_rsp);


#ifndef __MMI_NETSET_SLIM__
/* forbid PLMN list */
static void mmi_netsel_add_to_forbid_plmn_list(U8* plmn_id, U8 rat);
static void mmi_netsel_remove_from_forbid_plmn_list(U8* plmn_id, U8 rat);
static U8 mmi_netsel_find_in_forbid_plmn_list(U8* plmn_id, U8 rat);
#endif

/* network selection mode */
#ifdef __MANUAL_MODE_NW_SEL__
static mmi_ret mmi_set_netsel_select_mode_rsp(mmi_event_struct *ptr_rsp);
#endif /* __MANUAL_MODE_NW_SEL__ */

#ifdef __REL7__
static void mmi_netsel_entry_plmn_option(void);
static mmi_ret mmi_netsel_plmn_option_proc(mmi_event_struct *evt);
static mmi_ret mmi_netsel_additional_information_leave_proc(mmi_event_struct *evt);
static void mmi_netsel_get_additional_information_progress(void);
static void mmi_netsel_entry_empty_additional_information_display(void);
static void mmi_netsel_pre_entry_additional_information(U16 highlight_id);
static void mmi_netsel_prepare_additional_information_data(const srv_eons_name_struct *name, void *user_data);
static void mmi_netsel_entry_additional_information_display(WCHAR *data);
#endif
/***************************************************************************** 
* External Function
*****************************************************************************/

/* temp extern functions */
/* Network Setup Network Selection */
#ifdef __REL7__
static U16 g_netset_nwsel_highlight_idx;
static WCHAR *g_netset_nwsel_additional_info_buf;
#endif
#ifndef __MMI_NETSET_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netsel_auto
 * DESCRIPTION
 *  This function is entry function of Network Setup -> Network selection -> New Search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_netsel_auto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_AUTO, "[NetSetAppNWSelect.c] mmi_entry_netsel_auto()");
    if (!mmi_netsel_is_available_to_entry())
	{
	    return;
	}
    
    mmi_entry_netsel_progress();    
    g_netset_netsel_is_progressing = MMI_TRUE;
    srv_netset_set_plmn_auto(MMI_NETSET_CURRENT_SIM, mmi_set_netsel_auto_rsp, NULL);
    #if (MMI_MAX_SIM_NUM >= 2)
    {
        U8 i;
        MMI_BOOL check_service = MMI_TRUE;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
    	{
    		mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            if (sim == MMI_NETSET_CURRENT_SIM)
        	{
        	    continue;
        	}
            if (srv_nw_info_get_service_availability(sim) == SRV_NW_INFO_SA_FULL_SERVICE)
        	{
        	    check_service = MMI_FALSE;
        	}
    	}
        
        if (check_service)
    	{
            mmi_mode_switch_query_enable_check_service(MMI_NETSET_CURRENT_SIM); // for SIM network service status checking	
    	}
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_set_netsel_auto_rsp
 * DESCRIPTION
 *  This function is response function of Network Setup -> Network selection -> New Search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_set_netsel_auto_rsp(mmi_event_struct* ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_rsp_struct *rsp_msg = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.set_plmn_rsp_data;
    g_netset_netsel_is_progressing = MMI_FALSE;
    if ((rsp_msg->result.flag == L4C_OK) && (rsp_msg->status == L4C_RAC_OK))
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS)
        {
            mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS);
            mmi_popup_display_simple_ext(STR_GLOBAL_DONE,  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS)
        {
            mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS);            
            mmi_popup_display_simple_ext(STR_GLOBAL_UNFINISHED,  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        }
    }
    /* close the screen again to avoid the screen is not closed when get the response the progress screen is not on top */
    mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS);
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netsel_progress
 * DESCRIPTION
 *  This function is entry function of New Search Progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_netsel_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_AUTO_PROGRESS, "[NetSetAppNWSelect.c] mmi_entry_netsel_progress()");
#ifdef __MMI_BACKGROUND_CALL__
    if (mmi_frm_is_in_backward_scenario() && srv_ucm_is_background_call())
    {
        if (mmi_frm_scrn_is_present(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS);    	
    	}
        if (mmi_frm_scrn_is_present(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN);
    	}
        NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_AUTO_PROGRESS, "[NetSetAppNWSelect.c] mmi_entry_netsel_progress() close because of background call");
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */


	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_MAIN, 
		SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS, 
		NULL, 
		mmi_entry_netsel_progress, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    ShowCategory66Screen(
        STR_ID_NETSET_NETWORK_SELECTION,
        GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_ID_NETSET_REGISTERING_NW),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

}
/* Network Setup Auto Register */



/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netsel_manual
 * DESCRIPTION
 *  This function is entry function of Network Setup -> Network selection -> Select Network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_netsel_manual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_netsel_is_available_to_entry())
	{
	    return;
	}    
    NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_MANUAL, "[NetSetAppNWSelect.c] mmi_entry_netsel_manual()");
    mmi_entry_netsel_manual_search_progress();
    srv_netset_get_plmn(MMI_NETSET_CURRENT_SIM, mmi_netset_get_plmn_rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netsel_manual
 * DESCRIPTION
 *  This function is response function of get PLMN list 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_get_plmn_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
	CHAR home_plmn_num[MAX_PLMN_LEN + 1];
    l4c_plmn_info_struct tempPLMNList;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS, NULL);

#ifdef __DM_LAWMO_SUPPORT__ 
    if (mmi_dmui_is_phone_lock())
    {
        return MMI_RET_OK;   
    }
#endif /* __DM_LAWMO_SUPPORT__ */

	if (!mmi_frm_scrn_is_present(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS, MMI_FRM_NODE_ALL_FLAG))
	{
		NETSET_TRACE0(0, "[NetSetAppNWSelect.c] SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS not exist");
		return MMI_RET_OK;
	}

    if (((srv_netset_rsp_event_struct*)ptr_rsp)->result == SRV_NETSET_RSP_RESULT_BUSY)
    {
	mmi_popup_display_simple_ext(STR_GLOBAL_BUSY_TRY_LATER, MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
        return MMI_RET_OK;
    }

    if (g_netset_cntx_ptr->plmn_list)
    {
        OslMfree(g_netset_cntx_ptr->plmn_list);
        g_netset_cntx_ptr->plmn_list = NULL;
    }

    g_netset_cntx_ptr->plmn_list = OslMalloc(sizeof(mmi_nw_get_plmn_list_rsp_struct));

    memcpy(g_netset_cntx_ptr->plmn_list, ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.get_plmn_rsp_data, sizeof(mmi_nw_get_plmn_list_rsp_struct));
    
	if (!srv_sim_ctrl_get_home_plmn(MMI_NETSET_CURRENT_SIM, home_plmn_num, MAX_PLMN_LEN + 1))
	{
		memset(home_plmn_num, 0x00, MAX_PLMN_LEN + 1);
	}
#ifndef  __MMI_NETSET_DISABLE_OPERATOR_CHECK__	
    /* CMCC 46002 special case */
    if (memcmp(home_plmn_num, "46002", 5) == 0)
    {
        for (i = 0; i < g_netset_cntx_ptr->plmn_list->length; i++)
        {
            if (memcmp(g_netset_cntx_ptr->plmn_list->list[i].plmn_id, "46000", 5) == 0)
            {
                memcpy(&tempPLMNList, &(g_netset_cntx_ptr->plmn_list->list[0]), sizeof(l4c_plmn_info_struct));
                memcpy(
                    &(g_netset_cntx_ptr->plmn_list->list[0]),
                    &(g_netset_cntx_ptr->plmn_list->list[i]),
                    sizeof(l4c_plmn_info_struct));
                memcpy(&(g_netset_cntx_ptr->plmn_list->list[i]), &tempPLMNList, sizeof(l4c_plmn_info_struct));
            }
        }
    }
#endif
    if (g_netset_cntx_ptr->plmn_list->result.flag != L4C_OK || g_netset_cntx_ptr->plmn_list->length == 0 
        || srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        if (g_netset_cntx_ptr->plmn_list)
        {
            OslMfree(g_netset_cntx_ptr->plmn_list);
            g_netset_cntx_ptr->plmn_list = NULL;
        }
        mmi_popup_display_simple((WCHAR*) GetString(STR_ID_NETSET_NW_LIST_FAIL),  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
    else
    {
        for (i = 0; i < g_netset_cntx_ptr->plmn_list->length; ++i)
        {
            if (g_netset_nw_search_disp_cntx.plmn_name[i] != NULL)
            {
                OslMfree(g_netset_nw_search_disp_cntx.plmn_name[i]);
                g_netset_nw_search_disp_cntx.plmn_name[i] = NULL;
            }
            g_netset_nw_search_disp_cntx.plmn_name[i] = OslMalloc(PLMN_NAME_LENGTH * ENCODING_LENGTH);
            memset((void*)g_netset_nw_search_disp_cntx.plmn_name[i], 0, PLMN_NAME_LENGTH * ENCODING_LENGTH);
            
            /* Get plmn string from PLMN list */
            mmi_netset_retrieve_opname_from_plmn(
                g_netset_cntx_ptr->plmn_list->list[i].plmn_id,
                g_netset_nw_search_disp_cntx.plmn_name[i]);
#ifndef __MMI_NETSET_DISABLE_OPERATOR_CHECK__            
            if (mmi_netset_is_t_mobile_us_sim() && memcmp(g_netset_cntx_ptr->plmn_list->list[i].plmn_id, "31017", 5) == 0)
            {
                mmi_ucs2cpy((CHAR*) g_netset_nw_search_disp_cntx.plmn_name[i], (CHAR*) L"T-Mobile");
            }
#endif		
        }

        mmi_entry_netsel_manual_search_show_plmn_list();
    }

    mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS);
    return MMI_RET_OK;
}

#ifndef __MMI_NETSET_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_abort_manual_search_rsp
 * DESCRIPTION
 *  This function is response function of Network selection -> Select Network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_netset_abort_manual_search_rsp(mmi_event_struct *ptr_rsp)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((srv_netset_rsp_event_struct*)ptr_rsp)->result == SRV_NETSET_RSP_RESULT_SUCCESS)
    {
    	mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS, NULL);
    	mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS);
    }
    return MMI_RET_OK;    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_exit_netsel_manual_search_progress_back
 * DESCRIPTION
 *  This function is Back key function of Network selection -> Select Network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_exit_netsel_manual_search_progress_back(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_exit_netsel_manual_search_progress_end
 * DESCRIPTION
 *  This function is END key function of Network selection -> Select Network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_exit_netsel_manual_search_progress_end(mmi_event_struct *info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_NETSET_SLIM__
	if (info->evt_id == EVT_ID_SCRN_DEINIT ||
        info->evt_id == EVT_ID_SCRN_GOBACK ||
        info->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
		info->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        info->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
	{
	    srv_netset_abort_plmn(MMI_NETSET_CURRENT_SIM, mmi_netset_abort_manual_search_rsp, NULL);
	}
#endif
    if (!srv_nw_usab_is_usable(MMI_NETSET_CURRENT_SIM))
	{
        /* It is closed because the SIM or RF is not avilable */
	    return MMI_RET_ALLOW_CLOSE;
	}
	return MMI_RET_PROHIBIT_SCRN_ENTER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netsel_manual_search_progress
 * DESCRIPTION
 *  This function is entry function of Network Setup -> Network selection -> Select Network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_netsel_manual_search_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_MANUAL_SEARCH_PROGRESS, "[NetSetAppNWSelect.c] mmi_entry_netsel_manual_search_progress()");
	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_MAIN, 
		SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS, 
		NULL, 
		mmi_entry_netsel_manual_search_progress, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
#ifndef __MMI_NETSET_SLIM__
    ShowCategory66Screen(
        STR_ID_NETSET_NETWORK_SELECTION,
        GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_GLOBAL_SEARCHING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
#else
    ShowCategory66Screen(
        STR_ID_NETSET_NETWORK_SELECTION,
        GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_SEARCHING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
#endif

	SetRightSoftkeyFunction(mmi_exit_netsel_manual_search_progress_back, KEY_EVENT_UP);
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS, mmi_exit_netsel_manual_search_progress_end);
}


static void mmi_exit_netsel_manual_search_show_plmn_free_mem(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_ENTRY_MANUAL_PLMN_LIST, "[NetSetAppNWSelect.c] mmi_exit_netsel_manual_search_show_plmn_free_mem()");

	if (g_netset_nw_search_disp_cntx.plmn_mark_icons)
    {
        OslMfree(g_netset_nw_search_disp_cntx.plmn_mark_icons);
        g_netset_nw_search_disp_cntx.plmn_mark_icons = NULL;
    }
	
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
	if (g_netset_cntx_ptr->plmn_list)
	{
	for (i = 0; i < g_netset_cntx_ptr->plmn_list->length; i++)
	{
		if (g_netset_nw_search_disp_cntx.plmn_name[i])
		{
			OslMfree(g_netset_nw_search_disp_cntx.plmn_name[i]);
			g_netset_nw_search_disp_cntx.plmn_name[i] = NULL;
		}
	}
	
		OslMfree(g_netset_cntx_ptr->plmn_list);
		g_netset_cntx_ptr->plmn_list = NULL;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_exit_netsel_manual_search_show_plmn_list_back
 * DESCRIPTION
 *  This function is exit plmn list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_exit_netsel_manual_search_show_plmn_list_back(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_ENTRY_MANUAL_PLMN_LIST, "[NetSetAppNWSelect.c] mmi_exit_netsel_manual_search_show_plmn_list_back()");
	mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN);
}

static mmi_ret mmi_netsel_plmn_list_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
	{
		case EVT_ID_SCRN_DEINIT:
	mmi_exit_netsel_manual_search_show_plmn_free_mem();
			break;

		default:
	        break;		
}

    return MMI_RET_ALLOW_CLOSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netsel_manual_search_show_plmn_list
 * DESCRIPTION
 *  This function is entry function of display PLMN screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_netsel_manual_search_show_plmn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
	U8 current_plmn[MAX_PLMN_LEN + 1];
	CHAR home_plmn_num[MAX_PLMN_LEN + 1];
    U8 *gui_buffer = NULL;
    U8 is_band_1900 = srv_nw_info_get_camp_on_band(MMI_NETSET_CURRENT_SIM) == SRV_NW_BAND_PCS1900 ? 1 : 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_ENTRY_MANUAL_PLMN_LIST, "[NetSetAppNWSelect.c] mmi_entry_netsel_manual_search_show_plmn_list()");

	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_MAIN, 
		SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN, 
		NULL, 
		mmi_entry_netsel_manual_search_show_plmn_list, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;   
    }	

	gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN);

	if (!srv_nw_info_get_nw_plmn(MMI_NETSET_CURRENT_SIM, (CHAR*)current_plmn, MAX_PLMN_LEN + 1))
	{
		memset(current_plmn, 0x00, MAX_PLMN_LEN + 1);
	}

	if (!srv_sim_ctrl_get_home_plmn(MMI_NETSET_CURRENT_SIM, home_plmn_num, MAX_PLMN_LEN + 1))
	{
		memset(home_plmn_num, 0x00, MAX_PLMN_LEN + 1);
	}

    if (g_netset_nw_search_disp_cntx.plmn_mark_icons)
    {
        OslMfree(g_netset_nw_search_disp_cntx.plmn_mark_icons);
        g_netset_nw_search_disp_cntx.plmn_mark_icons = NULL;
    }
    g_netset_nw_search_disp_cntx.plmn_mark_icons = OslMalloc((g_netset_cntx_ptr->plmn_list->length * sizeof(U16)));

    /* malloc RAT icon memory */
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */ 

    for (i = 0; i < g_netset_cntx_ptr->plmn_list->length; i++)
    {
        l4c_rat_plmn_info_struct curr_item;

        memcpy(&curr_item, &g_netset_cntx_ptr->plmn_list->list[i], sizeof(l4c_rat_plmn_info_struct));
#ifndef __MMI_NETSET_SLIM__ 	
        /* Check status for forbidden PLMN */
        if (curr_item.status == 3)
        {
            g_netset_nw_search_disp_cntx.plmn_mark_icons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
        }
        else
        {
        	NETSET_TRACE1(0, "[NetSetAppNWSelect.c] reg_fail_flag[%d]", g_netset_cntx_ptr->reg_fail_flag);            
            /* Check if camp on a forbidden PLMN but it can work, will remove it from local forbidden PLMN list */
            if ((strcmp((CHAR*)current_plmn, (CHAR*)curr_item.plmn_id) == 0)
				&& (srv_nw_info_get_service_availability(MMI_NETSET_CURRENT_SIM) == SRV_NW_INFO_SA_FULL_SERVICE))
            {
                mmi_netsel_remove_from_forbid_plmn_list(curr_item.plmn_id, curr_item.rat);
                g_netset_nw_search_disp_cntx.plmn_mark_icons[i] = 0;
            }
            /* Add register fail PLMN into local forbidden PLMN */
            else if (g_netset_cntx_ptr->reg_fail_flag == 1 
                && (strcmp((CHAR*)g_netset_cntx_ptr->sel_plmn.plmn_id, (CHAR*)curr_item.plmn_id) == 0)
		#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)                
/* under construction !*/
		#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */                
                )
            {
                mmi_netsel_add_to_forbid_plmn_list(curr_item.plmn_id, curr_item.rat);
                g_netset_nw_search_disp_cntx.plmn_mark_icons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
            }
            /* Check if this PLMN is in local forbidden list */
            else if (mmi_netsel_find_in_forbid_plmn_list(curr_item.plmn_id, curr_item.rat) == 1)
            {
                g_netset_nw_search_disp_cntx.plmn_mark_icons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
            }
            /* Else consider it is an unknow PLMN */
            else
#endif			
            {
                g_netset_nw_search_disp_cntx.plmn_mark_icons[i] = (U16) IMG_ID_NETSET_UNKNOWN_PLMN;
            }
#ifndef __MMI_NETSET_SLIM__
        }
#endif		
        if (i < g_netset_cntx_ptr->plmn_list->num_of_hplmn)
    	{
    	    g_netset_nw_search_disp_cntx.plmn_mark_icons[i] = (U16) IMG_ID_NETSET_HOME_PLMN;
    	}
        /* Set RAT icon */
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */ 
    }

#ifndef __MMI_NETSET_DISABLE_OPERATOR_CHECK__
    /* reset this flag after setting PLMNListIcons */
    g_netset_cntx_ptr->reg_fail_flag = 0;

    /* compare PLMN numbers instead of mapped strings because the string may be NULL if the PLMN cannot be found in the list */
    if (applib_plmn_is_matched((CHAR*)home_plmn_num, (CHAR*)g_netset_cntx_ptr->plmn_list->list[0].plmn_id, (kal_bool)is_band_1900) ||
       ((memcmp(home_plmn_num, "46002", 5) == 0 || memcmp(home_plmn_num, "46007", 5) == 0) 
       && memcmp(g_netset_cntx_ptr->plmn_list->list[0].plmn_id, "46000", 5) == 0))
    {
        g_netset_nw_search_disp_cntx.plmn_mark_icons[0] = (U16) IMG_ID_NETSET_HOME_PLMN;
    }

	#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */ 
#endif	

    /* more than one PLMN in current network */
    if (g_netset_nw_search_disp_cntx.plmn_name[0] != '\0')
    {
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
/* under construction !*/
    #else /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */ 
        ShowCategory84Screen(
            STR_ID_NETSET_NETSEL_NETWORK_LIST,
            GetRootTitleIcon(MENU_ID_NETSET_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_netset_cntx_ptr->plmn_list->length,
            g_netset_nw_search_disp_cntx.plmn_name,
            g_netset_nw_search_disp_cntx.plmn_mark_icons,
            1,
            0,
            gui_buffer);
    #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */ 
    }
    else
    {
        ShowCategory84Screen(
            STR_ID_NETSET_NETSEL_NETWORK_LIST,
            GetRootTitleIcon(MENU_ID_NETSET_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            g_netset_nw_search_disp_cntx.plmn_name,
            g_netset_nw_search_disp_cntx.plmn_mark_icons,
            1,
            0,
            gui_buffer);
    }

	mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN, mmi_netsel_plmn_list_leave_proc);

    SetRightSoftkeyFunction(mmi_exit_netsel_manual_search_show_plmn_list_back, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_set_netsel_manual, KEY_EVENT_UP);
    #ifdef __REL7__
    SetLeftSoftkeyFunction(mmi_netsel_entry_plmn_option, KEY_EVENT_UP);
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    #else
    SetLeftSoftkeyFunction(mmi_set_netsel_manual, KEY_EVENT_UP);
    #endif /* __REL7__ */
    
}

#ifdef __REL7__
/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_entry_plmn_option
 * DESCRIPTION
 *  Entry manual network selection option menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netsel_entry_plmn_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	NETSET_TRACE0(0, "[NetSetAppPrefList.c] mmi_entry_netset_pref_list_option()");
    g_netset_nwsel_highlight_idx = GetHighlightedItem();
    mmi_frm_group_create(
        GRP_ID_NETSET_MAIN, 
        GRP_ID_NETSET_NW_SELECT,
        mmi_netsel_plmn_option_proc,
        NULL);
    mmi_frm_group_enter(GRP_ID_NETSET_NW_SELECT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	menu_cui_id = cui_menu_create(
		GRP_ID_NETSET_NW_SELECT, 
		CUI_MENU_SRC_TYPE_RESOURCE, 
		CUI_MENU_TYPE_OPTION, 
		MENU_ID_NETSET_NETSEL_OPTION, 
		MMI_FALSE, 
		NULL);

    cui_menu_run(menu_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_plmn_option_proc
 * DESCRIPTION
 *  Proc function for option menu of manual network select 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netsel_plmn_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menucui_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menucui_evt->evt_id)
	{
	case EVT_ID_CUI_MENU_LIST_ENTRY:
        cui_menu_set_default_title_image(menucui_evt->sender_id, GetImage(GetRootTitleIcon(MENU_ID_NETSET_MAIN)));
        return MMI_RET_OK;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        switch (menucui_evt->highlighted_menu_id)
    	{
    	case MENU_ID_NETSET_NETSEL_SELECT:
    		mmi_set_netsel_manual_with_idx(g_netset_nwsel_highlight_idx);
            return MMI_RET_OK;
            
    	case MENU_ID_NETSET_NETSEL_ADDITIONAL_INFO:
    		mmi_netsel_pre_entry_additional_information(g_netset_nwsel_highlight_idx);
            return MMI_RET_OK;
            
    	default:
    		break;
    	}
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menucui_evt->sender_id);
        return MMI_RET_OK;
        
	default:
		break;
	}
    if (!cui_menu_is_menu_event(evt->evt_id))
	{
	    return MMI_RET_OK;
	}
    return MMI_RET_DONT_CARE;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_get_additional_information_progress
 * DESCRIPTION
 *  Progressing screen for get additional information, will stop the operation 
 *  and free the buffer when canceled.
 * PARAMETERS
 *  void
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netsel_get_additional_information_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_AUTO_PROGRESS, "[NetSetAppNWSelect.c] mmi_netsel_get_additional_information_progress()");
	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_NW_SELECT, 
		SCR_ID_NETSEL_ADDTIONAL_INFORMATION_PROGRESS, 
		NULL, 
		mmi_netsel_get_additional_information_progress, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    
    ShowCategory66Screen(
        STR_ID_NETSET_NETWORK_SELECTION,
        GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_pre_entry_additional_information
 * DESCRIPTION
 *  Entry addtional information of select PLMN 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netsel_pre_entry_additional_information(U16 highlight_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *plmn;
    U16 lac;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plmn = g_netset_cntx_ptr->plmn_list->list[highlight_id].plmn_id;
    lac = ((U16)(g_netset_cntx_ptr->plmn_list->list[highlight_id].lac[0]) << 8) + (U16)(g_netset_cntx_ptr->plmn_list->list[highlight_id].lac[1]);
    NETSET_TRACE1(0, "[NetSetAppNWSelect.c] mmi_netsel_pre_entry_additional_information() lac %d", lac);
    if (!srv_eons_get_name(MMI_NETSET_CURRENT_SIM, plmn, lac, mmi_netsel_prepare_additional_information_data, NULL))
	{
	    mmi_netsel_entry_empty_additional_information_display();
		return;
	}
    mmi_netsel_get_additional_information_progress();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_prepare_additional_information_data
 * DESCRIPTION
 *  Prepare the data for additional information display 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static void mmi_netsel_prepare_additional_information_data(const srv_eons_name_struct *name, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_netset_rsp_event_struct *additional_info_evt; 
    U8 length;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_is_present(
        GRP_ID_NETSET_NW_SELECT,
        SCR_ID_NETSEL_ADDTIONAL_INFORMATION_PROGRESS,
        MMI_FRM_NODE_ALL_FLAG))
	{
	    return;
	}

    if (name->plmn_info[0] == 0)
	{
        mmi_netsel_entry_empty_additional_information_display();
        return;
	}
    else
    {
        length = app_ucs2_strlen(name->plmn_info); 
        NETSET_TRACE1(0, "[NetSetAppNWSelect.c] mmi_netsel_prepare_additional_information_data() length %d", length);
        
		g_netset_nwsel_additional_info_buf = (WCHAR*)OslMalloc((length + 1) * sizeof(WCHAR));
        memset(g_netset_nwsel_additional_info_buf, 0, ((length + 1) * sizeof(WCHAR)));
		memcpy(g_netset_nwsel_additional_info_buf, name->plmn_info, length * sizeof(WCHAR));
    }   
    mmi_netsel_entry_additional_information_display(g_netset_nwsel_additional_info_buf);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_entry_empty_additional_information_display
 * DESCRIPTION
 *  Display <Empty> screen for additional information 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_netsel_entry_empty_additional_information_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 length;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //It will display: <Empty>
    NETSET_TRACE0(TRC_MMI_NETSET_NETSEL_AUTO_PROGRESS, "[NetSetAppNWSelect.c] mmi_netsel_entry_empty_additional_information_display()");    
    length = mmi_ucs2strlen((const CHAR*)GetString(STR_GLOBAL_EMPTY)) + 3; // Additional space for <>
    g_netset_nwsel_additional_info_buf = (WCHAR*)OslMalloc(length * sizeof(WCHAR));
    memset(g_netset_nwsel_additional_info_buf, 0, (length * sizeof(WCHAR)));
    
    mmi_ucs2cpy((CHAR*)g_netset_nwsel_additional_info_buf, (const CHAR*)L"<");
    mmi_ucs2cat((CHAR*)g_netset_nwsel_additional_info_buf, (const CHAR*)GetString(STR_GLOBAL_EMPTY)); 
    mmi_ucs2cat((CHAR*)g_netset_nwsel_additional_info_buf, (const CHAR*)L">");
    mmi_netsel_entry_additional_information_display(g_netset_nwsel_additional_info_buf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_entry_additional_information_display
 * DESCRIPTION
 *  Display addtional information, will display empty if can not get additional information 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static void mmi_netsel_entry_additional_information_display(WCHAR *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *gui_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_frm_scrn_enter(
		GRP_ID_NETSET_NW_SELECT, 
		SCR_ID_NETSEL_ADDTIONAL_INFORMATION, 
		NULL, 
		mmi_netsel_entry_additional_information_display, 
		MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }
    mmi_frm_scrn_close(GRP_ID_NETSET_NW_SELECT, SCR_ID_NETSEL_ADDTIONAL_INFORMATION_PROGRESS);
	gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_NETSET_NW_SELECT, SCR_ID_NETSET_NETWORK_INFO);    

    
    ShowCategory74Screen(
        STR_ID_NETSET_NETSEL_ADDITIONAL_INFO,
        GetRootTitleIcon(MENU_ID_NETSET_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)data,
        mmi_ucs2strlen((const CHAR*)data),
        gui_buffer);    
    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    mmi_frm_scrn_set_leave_proc(GRP_ID_NETSET_NW_SELECT, SCR_ID_NETSEL_ADDTIONAL_INFORMATION, mmi_netsel_additional_information_leave_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_additional_information_leave_proc
 * DESCRIPTION
 *  Free the buffer for additional information 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_netsel_additional_information_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
	{
	case EVT_ID_SCRN_DEINIT:
        if (g_netset_nwsel_additional_info_buf)
    	{
    	    OslMfree(g_netset_nwsel_additional_info_buf);
            g_netset_nwsel_additional_info_buf = NULL;
    	}		
		break;
	default:
        break;		
	}
    return MMI_RET_ALLOW_CLOSE;
}

#endif /* __REL7__ */
#ifndef __MMI_NETSET_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_find_in_forbid_plmn_list
 * DESCRIPTION
 *  This function is query plmn in forbid plmn or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_netsel_find_in_forbid_plmn_list(U8* plmn_id, U8 rat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (strcmp((CHAR*)g_netset_cntx_ptr->forbid_plmn[i].plmn_id, (CHAR*)plmn_id) == 0 &&
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)            
/* under construction !*/
#endif            
            g_netset_cntx_ptr->forbid_mark[i] == 1)
        {
            NETSET_TRACE2(TRC_MMI_NETSET_NETSEL_FIND_FORBID_PLMN, "[NetSetAppNWSelect.c] find forbid_plmn[%s] forbid_rat[%d]", plmn_id, rat);
            return 1;
        }
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_add_to_forbid_plmn_list
 * DESCRIPTION
 *  This function is to add plmn to forbid plmn list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netsel_add_to_forbid_plmn_list(U8* plmn_id, U8 rat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (g_netset_cntx_ptr->forbid_mark[i] == 0)
        {
            memcpy((CHAR*)g_netset_cntx_ptr->forbid_plmn[i].plmn_id, (CHAR*)plmn_id, MAX_PLMN_LEN + 1);
            g_netset_cntx_ptr->forbid_mark[i] = 1;
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)            
/* under construction !*/
#endif
            NETSET_TRACE2(TRC_MMI_NETSET_NETSEL_ADD_FORBID_PLMN, "[NetSetAppNWSelect.c] add forbid_plmn[%s] forbid_rat[%d]", plmn_id, rat);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_remove_from_forbid_plmn_list
 * DESCRIPTION
 *  This function is to remove plmn from forbid plmn list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netsel_remove_from_forbid_plmn_list(U8* plmn_id, U8 rat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (strcmp((CHAR*)g_netset_cntx_ptr->forbid_plmn[i].plmn_id, (CHAR*)plmn_id) == 0 &&
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)            
/* under construction !*/
#endif
            g_netset_cntx_ptr->forbid_mark[i] == 1)
        {
            g_netset_cntx_ptr->forbid_mark[i] = 0;
            memset(&(g_netset_cntx_ptr->forbid_plmn[i]), 0, sizeof(l4c_rat_plmn_info_struct));
            NETSET_TRACE2(TRC_MMI_NETSET_NETSEL_DEL_FORBID_PLMN, "[NetSetAppNWSelect.c] del forbid_plmn[%s] forbid_rat[%d]", plmn_id, rat);
            return;
        }
    }

}
#endif
/* Network Setup Manual Search */


/* Network Setup Manual Register */
/*****************************************************************************
 * FUNCTION
 *  mmi_set_netsel_manual_with_idx
 * DESCRIPTION
 *  Manual set PLMN with input index 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_set_netsel_manual_with_idx(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_netsel_is_available_to_entry())
	{
	    return;
	}
    mmi_entry_netsel_progress();    
    g_netset_netsel_is_progressing = MMI_TRUE;    
    NETSET_TRACE1(TRC_MMI_NETSET_NETSEL_SET_MANUAL, "[NetSetAppNWSelect.c] mmi_set_netsel_manual(hilite[%d])", index);

    memcpy((CHAR*) g_netset_cntx_ptr->sel_plmn.plmn_id,
         (CHAR*) g_netset_cntx_ptr->plmn_list->list[index].plmn_id,
         MAX_PLMN_LEN + 1);

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

    g_netset_cntx_ptr->sel_plmn_index = index;

    srv_netset_set_plmn_manual(MMI_NETSET_CURRENT_SIM, (CHAR*)g_netset_cntx_ptr->sel_plmn.plmn_id, 
        (srv_netset_rat_mode_enum)g_netset_cntx_ptr->sel_plmn.rat, mmi_set_netsel_manual_rsp, NULL);

    #if (MMI_MAX_SIM_NUM >= 2)
    {
        U8 i;
        MMI_BOOL check_service = MMI_TRUE;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
    	{
    		mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            if (sim == MMI_NETSET_CURRENT_SIM)
        	{
        	    continue;
        	}
            if (srv_nw_info_get_service_availability(sim) == SRV_NW_INFO_SA_FULL_SERVICE)
        	{
        	    check_service = MMI_FALSE;
        	}
    	}
        
        if (check_service)
    	{
            mmi_mode_switch_query_enable_check_service(MMI_NETSET_CURRENT_SIM); // for SIM network service status checking	
    	}
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_set_netsel_manual
 * DESCRIPTION
 *  This function is set network plmn manual
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_set_netsel_manual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_set_netsel_manual_with_idx((U8)GetHighlightedItem());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_set_netsel_manual_rsp
 * DESCRIPTION
 *  This function is response of set network plmn manual
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_set_netsel_manual_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_nw_set_plmn_rsp_struct *rsp_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.set_plmn_rsp_data;
    g_netset_netsel_is_progressing = MMI_FALSE;
    if (rsp_msg->result.flag == L4C_OK && rsp_msg->status == L4C_RAC_OK
        && !strcmp((CHAR*) g_netset_cntx_ptr->sel_plmn.plmn_id, (CHAR*) rsp_msg->plmn)
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif 
        )
    {
        for (i = 0; i < g_netset_cntx_ptr->plmn_list->length; i++)
        {
            if (g_netset_nw_search_disp_cntx.plmn_name[i])
            {
                OslMfree(g_netset_nw_search_disp_cntx.plmn_name[i]);
                g_netset_nw_search_disp_cntx.plmn_name[i] = NULL;
            }
        }

        if (g_netset_cntx_ptr->plmn_list)
        {
            OslMfree(g_netset_cntx_ptr->plmn_list);
            g_netset_cntx_ptr->plmn_list = NULL;
        }

        if (mmi_frm_scrn_get_active_id() == SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS)
        {
            mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS);
            mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN);
            mmi_popup_display_simple_ext(STR_GLOBAL_DONE,  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        }
        /* Registration screen may be not activated, close the list screen to avoid display empty list when back to screen */
        else if (mmi_frm_scrn_is_present(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS);
            mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN);    	    
    	}
		#ifdef __MMI_NETSET_SLIM__
		if(srv_netset_get_nw_selection_mode(mmi_netset_get_active_sim()))
		{
			srv_netset_set_nw_selection_mode(MMI_NETSET_CURRENT_SIM, SRV_NETSET_MANUAL_SEL, mmi_set_netsel_select_mode_rsp, NULL);
			//cui_menu_close(mmi_netset_get_sub_menu_id());
		}
		#endif
    }
    else
    {
        NETSET_TRACE1(0, "[NetSetAppNWSelect.c] mmi_set_netsel_manual_rsp rsp_msg->status[%d]", rsp_msg->status);                    
        /* restore network string from "Searching" to original network */
        if (mmi_frm_scrn_get_active_id() == SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS)
        {
            mmi_popup_display_simple_ext(STD_ID_NETSET_NW_SELECT_FAIL,  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        }
        
        if ((rsp_msg->status == L4C_RAC_LIMITED_SERVICE)
            || (rsp_msg->status == L4C_RAC_ATTEMPT_TO_UPDATE)
            || (rsp_msg->status == L4C_RAC_INVALID_SIM))
        {
            g_netset_cntx_ptr->reg_fail_flag = 1;
        }
    }
    mmi_frm_scrn_close(GRP_ID_NETSET_MAIN, SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netsel_is_available_to_entry
 * DESCRIPTION
 *  Check if network selection can be entry, if lower layer has not finished 
 *  its job, a popup will be displayed 
 * PARAMETERS
 *  
 * RETURNS
 *  static MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_netsel_is_available_to_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_netset_netsel_is_progressing)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_BUSY_TRY_LATER,
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
        NULL);
	    return MMI_FALSE;
	}
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
		mmi_ucm_app_entry_error_message();
        return MMI_FALSE;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    return MMI_TRUE;
}
/* Network Setup Manual Register */


/* Network Setup Selection Mode */
#ifdef __MANUAL_MODE_NW_SEL__
/*****************************************************************************
 * FUNCTION
 *  mmi_highlight_netsel_selection_mode
 * DESCRIPTION
 *  This function is high light handler of Network Setup -> Network selection -> Selection Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 #ifndef __MMI_MAINLCD_96X64__
CHAR* mmi_hint_netsel_select_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (srv_netset_get_nw_selection_mode(mmi_netset_get_active_sim()) == AUTOMATIC_MODE)
    {
        return (CHAR*) GetString(STR_GLOBAL_AUTOMATIC);
    }
    else
    {
        return (CHAR*) GetString(STR_GLOBAL_MANUAL);
    }

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netsel_select_mode
 * DESCRIPTION
 *  This function is entry function of Network Setup -> Network selection -> Selection Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_netsel_select_mode(cui_menu_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id list_of_ids[2];
	mmi_menu_id i = 0;
	U8 hilite = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < 2; i++) 
    {
        list_of_ids[i] = i;
    }
    
    cui_menu_set_currlist(
        evt->sender_id, 
        2, 
        list_of_ids);
    
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
	
    cui_menu_set_currlist_title(
        evt->sender_id, 
        (WCHAR*)get_string(STR_ID_NETSET_NETSEL_SELECTION_MODE), 
        (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_NETSET_MAIN)));
	
    {
        cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)0,
            (WCHAR*)get_string((U16)STR_GLOBAL_AUTOMATIC));

		cui_menu_set_item_string(
            evt->sender_id, 
            (mmi_menu_id)1,
            (WCHAR*)get_string((U16)STR_GLOBAL_MANUAL));
    }
    
    cui_menu_set_currlist_left_softkey(
        evt->sender_id, 
        (WCHAR*)get_string(STR_GLOBAL_OK));
    
	if (srv_netset_get_nw_selection_mode(mmi_netset_get_active_sim()) == AUTOMATIC_MODE)
    {
        hilite = 0;
    }
    else
    {
        hilite = 1;
    }
    if (!mmi_frm_is_in_backward_scenario())
    {
        cui_menu_set_currlist_highlighted_id(evt->sender_id, (mmi_menu_id)hilite);	
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_netsel_select_mode
 * DESCRIPTION
 *  This function is left soft key function of Selection Mode Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_set_netsel_select_mode(mmi_menu_id mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_netsel_is_available_to_entry())
	{
	    return;
	}     
    curr_mode = srv_netset_get_nw_selection_mode(mmi_netset_get_active_sim());
    NETSET_TRACE1(TRC_MMI_NETSET_NETSEL_SET_SELECT_MODE, "[NetSetAppNWSelect.c] mmi_set_netsel_select_mode curr_mode[%d]", curr_mode);

    /* switch to same mode */
	#ifndef __MMI_NETSET_SLIM__
    if (((curr_mode == AUTOMATIC_MODE) && (mode == 0))
        || ((curr_mode == MANUAL_MODE) && (mode == 1)))
    {
		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE),  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        cui_menu_close(mmi_netset_get_sub_menu_id());
        return;
    }

    if (mode)
    {
        srv_netset_set_nw_selection_mode(MMI_NETSET_CURRENT_SIM, SRV_NETSET_MANUAL_SEL, mmi_set_netsel_select_mode_rsp, NULL);
    }
    else
    {
        srv_netset_set_nw_selection_mode(MMI_NETSET_CURRENT_SIM, SRV_NETSET_AUTO_SEL, mmi_set_netsel_select_mode_rsp, NULL);
    }
#else
	 if (((curr_mode == AUTOMATIC_MODE) && (mode == 0)))
    {
		mmi_popup_display_simple_ext(STR_GLOBAL_DONE,  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        cui_menu_close(mmi_netset_get_sub_menu_id());
        return;
    }

    if (mode == 1)
    {
        g_netset_is_auto=MMI_FALSE;
        mmi_entry_netsel_manual();
    }
    else
    {
    	g_netset_is_auto=MMI_TRUE;
        srv_netset_set_nw_selection_mode(MMI_NETSET_CURRENT_SIM, SRV_NETSET_AUTO_SEL, mmi_set_netsel_select_mode_rsp, NULL);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_set_netsel_select_mode_rsp
 * DESCRIPTION
 *  This function is left soft key function of Selection Mode Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_set_netsel_select_mode_rsp(mmi_event_struct *ptr_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_select_mode_rsp_struct *rsp_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = ((srv_netset_rsp_event_struct*)ptr_rsp)->rsp_data.set_nw_selection_mode_rsp_data;

    NETSET_TRACE1(TRC_MMI_NETSET_NETSEL_SET_SELECT_MODE_RSP, "[NetSetAppNWSelect.c] mmi_set_netsel_select_mode_rsp result [%d]", rsp_msg->result);
#ifndef  __MMI_NETSET_SLIM__
    if (rsp_msg->result)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE,  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
		cui_menu_close(mmi_netset_get_sub_menu_id());
    }
    else
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_UNFINISHED,  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
#else
	if (rsp_msg->result)
    {
        if(g_netset_is_auto)
        {
        	mmi_popup_display_simple_ext(STR_GLOBAL_DONE,  MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
			g_netset_is_auto=MMI_FALSE;
        }	
        cui_menu_close(mmi_netset_get_sub_menu_id());
    }
    else
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_UNFINISHED,  MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }

#endif
    return MMI_RET_OK;
}
#endif /* __MANUAL_MODE_NW_SEL__ */
/* Network Setup Selection Mode */

/* Network Setup Network Selection */


/* External Interface to Other Application */
#ifndef __MMI_NETSET_SLIM__

/*****************************************************************************
* FUNCTION
*  mmi_netset_is_t_mobile_us_sim
* DESCRIPTION
*  Check if the inserted SIM is T-Mobile
* PARAMETERS
*  void
* RETURNS
*  pBOOL
*****************************************************************************/
pBOOL mmi_netset_is_t_mobile_us_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 plmn_idx;
	CHAR home_plmn_num[MAX_PLMN_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!srv_sim_ctrl_get_home_plmn(MMI_SIM1, home_plmn_num, MAX_PLMN_LEN + 1))
	{
		memset(home_plmn_num, 0x00, MAX_PLMN_LEN + 1);
	}
	
    if (memcmp(home_plmn_num, "310", 3) != 0)
    {
        return MMI_FALSE; /* not in United States */
    }
    
    plmn_idx = mmi_netset_retrieve_opname_from_plmn((PU8) home_plmn_num, NULL);
    
    if (mmi_ucs2cmp(GetString((U16)(STR_PLMN_NAME_1 + plmn_idx)), (CHAR*) L"T-Mobile") == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE; /* not T-Mobile SIM */
    }
}
#endif

void NETSETCheckAndRestoreNetwork(void)
{
    
}

