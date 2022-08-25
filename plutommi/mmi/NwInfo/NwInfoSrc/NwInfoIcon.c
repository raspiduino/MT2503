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
 *  NwInfoIcon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Icons of network information
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "NwInfoProt.h"
#include "IdleGprot.h"
#include "MMIDataType.h"
#include "SimCtrlSrvGprot.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "NwInfoSrvGprot.h"
#include "wgui_categories_util.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_list.h"
#include "BootupSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "NetSetSrvGprot.h"
#include "mmi_rp_srv_status_icons_def.h"

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
#include "CnmgrSrvGprot.h"

#ifdef __TCPIP__
#include "mmi_rp_srv_cnmgr_def.h"
#endif /* __TCPIP__ */

#include "mmi_rp_srv_status_icons_def.h"
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    MMI_NW_INFO_DN_ICON_GPRS,
    MMI_NW_INFO_DN_ICON_UMTS = MMI_NW_INFO_DN_ICON_GPRS,
    MMI_NW_INFO_DN_ICON_EDGE,
    MMI_NW_INFO_DN_ICON_TD,
    MMI_NW_INFO_DN_ICON_HSPA,

    MMI_NW_INFO_DN_ICON_END_OF_ENUM
} mmi_nw_info_dn_icon_type_enum;

typedef struct
{
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
    S32 attached_icon;
#endif
    S32 activated_icon;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
	S32 uplink_icon;
	S32 downlink_icon;
	S32 up_and_downlink_icon;
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
} mmi_nw_dn_sim_icon_struct;


#ifdef __MMI_NW_INFO_DN_STATUS_SLIM__
	#define NW_INFO_SIM_COUNT 1
#else
	#define NW_INFO_SIM_COUNT SRV_SIM_CTRL_MAX_SIM_NUM
#endif /* __MMI_NW_INFO_DN_STATUS_SLIM__ */

typedef struct
{
    mmi_nw_info_dn_icon_type_enum type;
    mmi_nw_dn_sim_icon_struct sim_icon[NW_INFO_SIM_COUNT];
} mmi_nw_info_dn_icon_config_struct;


/****************************************************************************
 * Configurations
 ****************************************************************************/

static const mmi_nw_info_dn_icon_config_struct g_mmi_nw_info_dn_icon_config[] =
{
    {
        MMI_NW_INFO_DN_ICON_GPRS,
        { { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
            STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, 
	#endif
            STATUS_ICON_GPRS_SERVICE
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_GPRS_UPLINK, STATUS_ICON_GPRS_DOWNLINK, STATUS_ICON_GPRS_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    #if (MMI_MAX_SIM_NUM >= 2)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
            STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR, 
	#endif
            STATUS_ICON_SLAVE_GPRS_SERVICE
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_SLAVE_GPRS_UPLINK, STATUS_ICON_SLAVE_GPRS_DOWNLINK, STATUS_ICON_SLAVE_GPRS_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #if (MMI_MAX_SIM_NUM >= 3)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
            STATUS_ICON_SIM3_GPRS_ATT_NO_PDP_INDICATOR, 
	#endif
            STATUS_ICON_SIM3_GPRS_SERVICE
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ 
        	,STATUS_ICON_SIM3_GPRS_UPLINK, STATUS_ICON_SIM3_GPRS_DOWNLINK, STATUS_ICON_SIM3_GPRS_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #if (MMI_MAX_SIM_NUM >= 4)
        , {
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
            STATUS_ICON_SIM4_GPRS_ATT_NO_PDP_INDICATOR, 
    #endif
            STATUS_ICON_SIM4_GPRS_SERVICE
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ 
        	,STATUS_ICON_SIM4_GPRS_UPLINK, STATUS_ICON_SIM4_GPRS_DOWNLINK, STATUS_ICON_SIM4_GPRS_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #endif
    #endif
    #endif
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
        }
    },
    {
        MMI_NW_INFO_DN_ICON_EDGE,
        { { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        STATUS_ICON_EDGEC, 
	#endif
        STATUS_ICON_EDGE
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_EDGE_UPLINK, STATUS_ICON_EDGE_DOWNLINK, STATUS_ICON_EDGE_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    #if (MMI_MAX_SIM_NUM >= 2)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
            STATUS_ICON_SLAVE_EDGEC, 
	#endif
            STATUS_ICON_SLAVE_EDGE
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_SLAVE_EDGE_UPLINK, STATUS_ICON_SLAVE_EDGE_DOWNLINK, STATUS_ICON_SLAVE_EDGE_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #if (MMI_MAX_SIM_NUM >= 3)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
            STATUS_ICON_SIM3_EDGEC, 
	#endif
            STATUS_ICON_SIM3_EDGE
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_SIM3_EDGE_UPLINK, STATUS_ICON_SIM3_EDGE_DOWNLINK, STATUS_ICON_SIM3_EDGE_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #if (MMI_MAX_SIM_NUM >= 4)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
            STATUS_ICON_SIM4_EDGEC, 
	#endif
            STATUS_ICON_SIM4_EDGE
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_SIM4_EDGE_UPLINK, STATUS_ICON_SIM4_EDGE_DOWNLINK, STATUS_ICON_SIM4_EDGE_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #endif
    #endif
    #endif
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
        }
    },
#ifdef __OP01_3G__ /* TD does not support Gemini+ yet */
    {
        MMI_NW_INFO_DN_ICON_TD,
        { { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
STATUS_ICON_TD_NO_PDP, 
	#endif
STATUS_ICON_TD_PDP_ACTIVATED
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ 
        	,STATUS_ICON_TD_UPLINK, STATUS_ICON_TD_DOWNLINK, STATUS_ICON_TD_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    #if (MMI_MAX_SIM_NUM >= 2)
        , { 
		#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
STATUS_ICON_TD_NO_PDP, 
		#endif
STATUS_ICON_TD_PDP_ACTIVATED
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_TD_UPLINK, STATUS_ICON_TD_DOWNLINK, STATUS_ICON_TD_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #if (MMI_MAX_SIM_NUM >= 3)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
STATUS_ICON_TD_NO_PDP, 
	#endif
STATUS_ICON_TD_PDP_ACTIVATED
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_TD_UPLINK, STATUS_ICON_TD_DOWNLINK, STATUS_ICON_TD_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #if (MMI_MAX_SIM_NUM >= 4)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
STATUS_ICON_TD_NO_PDP, 
	#endif
STATUS_ICON_TD_PDP_ACTIVATED
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ 
        	,STATUS_ICON_TD_UPLINK, STATUS_ICON_TD_DOWNLINK, STATUS_ICON_TD_UPDOWNLINK
		#endif
          }
    #endif
    #endif
    #endif
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
        }
    },
#endif
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
    {
        MMI_NW_INFO_DN_ICON_HSPA,
        { { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
STATUS_ICON_HSPA_NO_PDP, 
	#endif
STATUS_ICON_HSPA_PDP_ACTIVATED
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_HSPA_UPLINK, STATUS_ICON_HSPA_DOWNLINK, STATUS_ICON_HSPA_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    #if (MMI_MAX_SIM_NUM >= 2)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
STATUS_ICON_SLAVE_HSPA_NO_PDP, 
	#endif
STATUS_ICON_SLAVE_HSPA_PDP_ACTIVATED
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ 
        	STATUS_ICON_SLAVE_HSPA_UPLINK, STATUS_ICON_SLAVE_HSPA_DOWNLINK, STATUS_ICON_SLAVE_HSPA_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #if (MMI_MAX_SIM_NUM >= 3)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
STATUS_ICON_SIM3_HSPA_NO_PDP, 
	#endif
STATUS_ICON_SIM3_HSPA_PDP_ACTIVATED
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_HSPA_UPLINK, STATUS_ICON_HSPA_DOWNLINK, STATUS_ICON_HSPA_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #if (MMI_MAX_SIM_NUM >= 4)
        , { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
STATUS_ICON_SIM4_HSPA_NO_PDP, 
	#endif
STATUS_ICON_SIM4_HSPA_PDP_ACTIVATED
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        	,STATUS_ICON_HSPA_UPLINK, STATUS_ICON_HSPA_DOWNLINK, STATUS_ICON_HSPA_UPDOWNLINK
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
          }
    #endif
    #endif
    #endif
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
        }
    },
#endif

    /* ------------------------------------------------------------------------------------- */
    {
        MMI_NW_INFO_DN_ICON_END_OF_ENUM,
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { 
        #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        	{0, 0, 0, 0, 0}
	#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    #if (MMI_MAX_SIM_NUM >= 2)
        , {0, 0, 0, 0, 0}
    #if (MMI_MAX_SIM_NUM >= 3)
        , {0, 0, 0, 0, 0}
    #if (MMI_MAX_SIM_NUM >= 4)
        , {0, 0, 0, 0, 0}
    #endif
    #endif
    #endif
	#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
	#else/* __MMI_COSMOS_STATUS_BAR_SLIM__ */
		{0, 0, 0, 0}
	#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
	#if (MMI_MAX_SIM_NUM >= 2)
	        , {0, 0, 0, 0}
	#if (MMI_MAX_SIM_NUM >= 3)
	        , { 0, 0 , 0, 0}
	#if (MMI_MAX_SIM_NUM >= 4)
	        , { 0, 0, 0, 0 }
	#endif
	#endif
	#endif
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
		#endif
        }
#else
        { 
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        	{0, 0}
	#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
	    #if (MMI_MAX_SIM_NUM >= 2)
	        , {0, 0}
	    #if (MMI_MAX_SIM_NUM >= 3)
	        , { 0, 0 }
	    #if (MMI_MAX_SIM_NUM >= 4)
	        , { 0, 0 }
	    #endif
	    #endif
	    #endif
	#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
	#else /* __MMI_COSMOS_STATUS_BAR_SLIM__ */	
		{0}
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
	#if (MMI_MAX_SIM_NUM >= 2)
	        , {0}
	#if (MMI_MAX_SIM_NUM >= 3)
	        , { 0 }
	#if (MMI_MAX_SIM_NUM >= 4)
	        , { 0 }
	#endif
	#endif
	#endif
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
	#endif
        }
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
    }
};


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_update_roaming_icon
 * DESCRIPTION
 *  Update roaming icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_signal_strength_changed_evt_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_update_roaming_icon(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    icon_id = STATUS_ICON_INVALID_ID;

    if (sim == MMI_SIM1)
    {
        icon_id = STATUS_ICON_ROAMING;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    else if (sim == MMI_SIM2)
    {
        icon_id = STATUS_ICON_SLAVE_ROAMING;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim == MMI_SIM3)
    {
        icon_id = STATUS_ICON_SIM3_ROAMING;
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim == MMI_SIM4)
    {
        icon_id = STATUS_ICON_SIM4_ROAMING;
    }
#endif
#endif
#endif


    MMI_ASSERT(icon_id != STATUS_ICON_INVALID_ID);
    
    if (srv_nw_info_is_roaming(sim))
    {
        wgui_status_icon_bar_set_icon_display(icon_id);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(icon_id);
    }

    /* Icon bar will be updated by mmi_nw_info_on_status_changed() */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_update_protocol_icon
 * DESCRIPTION
 *  Update protocol icon.
 * PARAMETERS
 *  sim
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
static void mmi_nw_info_update_protocol_icon(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_network_enum protocol = MMI_NETWORK_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__UMTS_RAT__) && defined(__OP02__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (MMI_MAX_SIM_NUM >= 2) */
/* under construction !*/
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
#else /* __OP02__ */

#if defined(__GSM_RAT__) && (defined(__UMTS_RAT__) || defined(__OP01_3G__))

#ifdef __MMI_3G_SWITCH__
    if (sim == srv_netset_get_3g_capability_sim())
#else
    if (sim == MMI_SIM1)
#endif
    {
        /*
         * We only support 3G+2G now, so we have only to update the 3G/2G
         * icon of 3G-capable network.
         */
        protocol = srv_nw_info_get_protocol(sim);
        if (protocol == MMI_GSM)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_2G);
        }
        else
        {
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_2G);
        }
        
        if (protocol == MMI_WCDMA)
        {
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
            if (srv_nw_info_cell_supports(sim, MMI_HSDPA) ||
                srv_nw_info_cell_supports(sim, MMI_HSUPA))
            {
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_35G);
                wgui_status_icon_bar_reset_icon_display(STATUS_ICON_3G);
            }
            else
            {
                wgui_status_icon_bar_reset_icon_display(STATUS_ICON_35G);
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_3G);
            }
#else
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_3G);
#endif
        }
        else
        {
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__)
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_35G);
#endif
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_3G);
        }
    }

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__

#if (MMI_MAX_SIM_NUM >= 2) && defined(__OP01_3G__)
    if (sim == MMI_SIM2)
    {
        protocol = srv_nw_info_get_protocol(sim);
        if (protocol == MMI_GSM)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SLAVE_2G);
        }
        else
        {
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SLAVE_2G);
        }
    }
#endif
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */

    /* Icon bar will be updated by mmi_nw_info_on_status_changed() */
#endif

#endif /* Operator customization */
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_update_sim_dn_status_icon
 * DESCRIPTION
 *  Update the icon of SIM data network status.
 * PARAMETERS
 *  sim
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static void mmi_nw_info_update_sim_dn_status_icon(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_sim_dn_status_bit_set dn_status;
    mmi_nw_info_dn_icon_type_enum icon_type;
    const mmi_nw_info_dn_icon_config_struct *icon_entry;
    static S32 current_sim_icon[SRV_SIM_CTRL_MAX_SIM_NUM] = { 0 };
    S32 sim_index;
    mmi_network_enum protocol;

    static const srv_nw_info_sim_dn_status_bit_set

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
		SHOW_UPLINK_COND_BITS =
            (SRV_NW_INFO_SIM_DN_STATUS_COVERAGE |
             SRV_NW_INFO_SIM_DN_STATUS_ATTACHED |
             SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED |
             SRV_NW_INFO_SIM_DN_STATUS_UPLINK),
        SHOW_DOWNLINK_COND_BITS =
            (SRV_NW_INFO_SIM_DN_STATUS_COVERAGE |
             SRV_NW_INFO_SIM_DN_STATUS_ATTACHED |
             SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED |
             SRV_NW_INFO_SIM_DN_STATUS_DOWNLINK),
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        SHOW_ACTIVATED_COND_BITS =
            (SRV_NW_INFO_SIM_DN_STATUS_COVERAGE |
             SRV_NW_INFO_SIM_DN_STATUS_ATTACHED |
             SRV_NW_INFO_SIM_DN_STATUS_PDP_ACTIVATED),
        SHOW_ATTACHED_COND_BITS =
            (SRV_NW_INFO_SIM_DN_STATUS_COVERAGE |
             SRV_NW_INFO_SIM_DN_STATUS_ATTACHED);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_type = MMI_NW_INFO_DN_ICON_GPRS;

    /* Get correct icon setting */
    protocol = srv_nw_info_get_protocol(sim);
    if (protocol == MMI_GSM)
    {
        if (srv_nw_info_cell_supports(sim, MMI_EDGE))
        {
            icon_type = MMI_NW_INFO_DN_ICON_EDGE;
        }
        else
        {
            icon_type = MMI_NW_INFO_DN_ICON_GPRS;
        }
    }
    else if (protocol == MMI_WCDMA)
    {
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__)
        if (srv_nw_info_cell_supports(sim, MMI_HSDPA) ||
            srv_nw_info_cell_supports(sim, MMI_HSUPA) ||
            srv_nw_info_channel_supports(sim, MMI_HSDPA) ||
            srv_nw_info_channel_supports(sim, MMI_HSUPA))
        {
            icon_type = MMI_NW_INFO_DN_ICON_HSPA;
        }
        else
#endif
        {
#ifdef __OP01_3G__
            icon_type = MMI_NW_INFO_DN_ICON_TD;
#else
            icon_type = MMI_NW_INFO_DN_ICON_UMTS;
#endif
        }
    }

    /* Look up icon config entry */
    for (icon_entry = g_mmi_nw_info_dn_icon_config;
         icon_entry->type != MMI_NW_INFO_DN_ICON_END_OF_ENUM;
         icon_entry++)
    {
        if (icon_entry->type == icon_type)
        {
            break;
        }
    }

	if (icon_entry->type == MMI_NW_INFO_DN_ICON_END_OF_ENUM)
    {
        return;
    }

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    sim_index = mmi_frm_sim_to_index(sim);
#else
	sim_index = 0; /* for SIM1 */
#endif /* __MMI_NW_INFO_DN_STATUS_SLIM__ */

    /* Reset the icon of old status */
    if (current_sim_icon[sim_index] != 0)
    {
        wgui_status_icon_bar_reset_icon_display(current_sim_icon[sim_index]);
        current_sim_icon[sim_index] = 0;
    }

    /* Set the icon for new status */
    dn_status = srv_nw_info_get_sim_dn_status(sim);

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
	MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_DN_STATUS, dn_status);
	/*Uplink and Downlink Both*/
	if (((dn_status & SHOW_UPLINK_COND_BITS) == SHOW_UPLINK_COND_BITS) && 
		((dn_status & SHOW_DOWNLINK_COND_BITS) == SHOW_DOWNLINK_COND_BITS))
	{
		current_sim_icon[sim_index] = icon_entry->sim_icon[sim_index].up_and_downlink_icon;
		
		MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_DN_STATUS_ICON,
			sim, 5, current_sim_icon[sim_index]);
	}
	/*Uplink*/
	else if ((dn_status & SHOW_UPLINK_COND_BITS) == SHOW_UPLINK_COND_BITS)
    {
	    current_sim_icon[sim_index] = icon_entry->sim_icon[sim_index].uplink_icon;
        
        MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_DN_STATUS_ICON,
            sim, 4, current_sim_icon[sim_index]);
    }
	/*Downlink*/
    else if ((dn_status & SHOW_DOWNLINK_COND_BITS) == SHOW_DOWNLINK_COND_BITS)
    {
        current_sim_icon[sim_index] = icon_entry->sim_icon[sim_index].downlink_icon;
        
        MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_DN_STATUS_ICON,
            sim, 3, current_sim_icon[sim_index]);
    }
	/*PDP Activated*/
    else 
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
    if ((dn_status & SHOW_ACTIVATED_COND_BITS) == SHOW_ACTIVATED_COND_BITS)
    {
        current_sim_icon[sim_index] = icon_entry->sim_icon[sim_index].activated_icon;
        
        MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_DN_STATUS_ICON,
            sim, 2, current_sim_icon[sim_index]);
    }
	/*Attached*/
	
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
    else if ((dn_status & SHOW_ATTACHED_COND_BITS) == SHOW_ATTACHED_COND_BITS)
    {
        current_sim_icon[sim_index] = icon_entry->sim_icon[sim_index].attached_icon;

        MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_DN_STATUS_ICON,
            sim, 1, current_sim_icon[sim_index]);
    }
#endif
    else
    {
        /* No icon */
        MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_DN_STATUS_ICON,
            sim, 0, current_sim_icon[sim_index]);
    }

    if (current_sim_icon[sim_index] != 0)
    {
        wgui_status_icon_bar_set_icon_display(current_sim_icon[sim_index]);
    }

    /* Icon bar will be updated by mmi_nw_info_on_status_changed() */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_on_status_changed
 * DESCRIPTION
 *  Handler for network status changed.
 *  Update network status icons.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_status_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_on_status_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_status_changed_evt_struct *status_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_STATUS_CHANGED);

    status_evt = (srv_nw_info_status_changed_evt_struct*)evt;

    MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_ON_STATUS_CHANGED,
        status_evt->sim, status_evt->service_availability_changed,
        status_evt->protocol_changed, status_evt->capability_changed,
        status_evt->dn_status_changed, status_evt->location_changed);

#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
    if (status_evt->service_availability_changed ||
        status_evt->protocol_changed ||
        status_evt->capability_changed)
    {
        mmi_nw_info_update_protocol_icon(status_evt->sim);
    }
#endif

    if (status_evt->service_availability_changed ||
        status_evt->protocol_changed ||
        status_evt->capability_changed ||
        status_evt->dn_status_changed)
    {
        mmi_nw_info_update_sim_dn_status_icon(status_evt->sim);
    }

    if (status_evt->service_availability_changed ||
        status_evt->location_changed)
    {
        mmi_nw_info_update_roaming_icon(status_evt->sim);
    }
    
    /*
     * We didn't call icon_bar_update() on each event handler, but
     * update the icon bar at once after set all of them.
     */
    wgui_status_icon_bar_update();

    return MMI_RET_OK;
}


#ifdef __HOMEZONE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_on_homezone_status_changed
 * DESCRIPTION
 *  Handler for homezone status changed.
 *  Update homezone icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_homezone_status_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_on_homezone_status_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_homezone_status_changed_evt_struct *homezone_evt;
    S32 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_HOMEZONE_STATUS_CHANGED);

    icon_id = STATUS_ICON_HOMEZONE;

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__

#if (MMI_MAX_SIM_NUM >= 2)
    if (homezone_evt->sim == MMI_SIM2)
    {
        icon_id = STATUS_ICON_SLAVE_HOMEZONE;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (homezone_evt->sim == MMI_SIM3)
    {
        icon_id = STATUS_ICON_SIM3_HOMEZONE;
    }
#if (MMI_MAX_SIM_NUM >= 4)
    if (homezone_evt->sim == MMI_SIM4)
    {
        icon_id = STATUS_ICON_SIM4_HOMEZONE;
    }
#endif
#endif
#endif

#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */

    if (homezone_evt->notify_user && homezone_evt->info.is_in_homezone)
    {
        wgui_status_icon_bar_set_icon_display(icon_id);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(icon_id);
    }

    wgui_status_icon_bar_update();

    return MMI_RET_OK;
}
#endif /* __HOMEZONE_SUPPORT__ */

/*Added so that COSMOS project can also use this function. 
	Because COSMOS project uses this file. COSMOS support Dynamic sim dynamic Ui feature by default.
	So there is no macro for Dynamic sim dynamic Ui. This macro only used in PLUTO.
 */
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__COSMOS_MMI_PACKAGE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_set_icons_as_single_sim
 * DESCRIPTION
 *  Set icons of specific SIM to single SIM style
 * PARAMETERS
 *  sim     [IN] SIM
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nw_info_set_icons_as_single_sim(mmi_sim_enum sim)
{
    typedef struct 
    {
        S16 icon_id;
        U16 single_sim_image;
    } icon_image_config_struct;

    static const icon_image_config_struct SIM1_ICON_IMAGE_CONFIG[] =
    {
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_GPRS_UPLINK, IMG_SI_GPRS_UPLINK},
        { STATUS_ICON_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK},
        { STATUS_ICON_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_EDGEC, IMG_SI_EDGEC },
	#endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_EDGE, IMG_SI_EDGE },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_EDGE_UPLINK, IMG_SI_EDGE_UPLINK},
        { STATUS_ICON_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK},
        { STATUS_ICON_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
#ifdef __OP01_3G__
        /* TD gemini only supports SIM1 now */
        { STATUS_ICON_TD_NO_PDP, IMG_SI_TDC },
        { STATUS_ICON_TD_PDP_ACTIVATED, IMG_SI_TD },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_TD_UPLINK, IMG_SI_TD_UPLINK},
        { STATUS_ICON_TD_DOWNLINK, IMG_SI_TD_DOWNLINK},
        { STATUS_ICON_TD_UPDOWNLINK, IMG_SI_TD_UPDOWNLINK},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
#endif
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
        { STATUS_ICON_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP },
        { STATUS_ICON_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_HSPA_UPLINK, IMG_SI_HSPA_UPLINK,},
        { STATUS_ICON_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK},
        { STATUS_ICON_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
#endif
        { STATUS_ICON_ROAMING, IMG_SI_ROAMING_INDICATOR },
#ifdef __HOMEZONE_SUPPORT__
        { STATUS_ICON_HOMEZONE, IMG_SI_HZONE },
#endif
        { STATUS_ICON_INVALID_ID, 0 }
    };

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__

	#if (MMI_MAX_SIM_NUM >= 2)
    static const icon_image_config_struct SIM2_ICON_IMAGE_CONFIG[] =
    {
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SLAVE_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR },
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SLAVE_GPRS_UPLINK, IMG_SI_GPRS_UPLINK},
        { STATUS_ICON_SLAVE_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK},
        { STATUS_ICON_SLAVE_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK},
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SLAVE_EDGEC, IMG_SI_EDGEC },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SLAVE_EDGE, IMG_SI_EDGE },
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SLAVE_EDGE_UPLINK, IMG_SI_EDGE_UPLINK},
        { STATUS_ICON_SLAVE_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK},
        { STATUS_ICON_SLAVE_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK},
	#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
        { STATUS_ICON_SLAVE_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP },
        { STATUS_ICON_SLAVE_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED },
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SLAVE_HSPA_UPLINK, IMG_SI_HSPA_UPLINK },
        { STATUS_ICON_SLAVE_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK},
        { STATUS_ICON_SLAVE_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK},
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
#endif
        { STATUS_ICON_SLAVE_ROAMING, IMG_SI_ROAMING_INDICATOR },
#ifdef __HOMEZONE_SUPPORT__
        { STATUS_ICON_SLAVE_HOMEZONE, IMG_SI_HZONE },
#endif
        { STATUS_ICON_INVALID_ID, 0 }
    };
	#endif

#if (MMI_MAX_SIM_NUM >= 3)
    static const icon_image_config_struct SIM3_ICON_IMAGE_CONFIG[] =
    {
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SIM3_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SIM3_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR },
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SIM3_GPRS_UPLINK, IMG_SI_GPRS_UPLINK},
        { STATUS_ICON_SIM3_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK},
        { STATUS_ICON_SIM3_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK},
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SIM3_EDGEC, IMG_SI_EDGEC },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SIM3_EDGE, IMG_SI_EDGE },
	#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SIM3_EDGE_UPLINK, IMG_SI_EDGE_UPLINK},
        { STATUS_ICON_SIM3_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK},
        { STATUS_ICON_SIM3_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK},
	#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
        { STATUS_ICON_SIM3_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP },
        { STATUS_ICON_SIM3_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED },
#endif
        { STATUS_ICON_SIM3_ROAMING, IMG_SI_ROAMING_INDICATOR },
        { STATUS_ICON_INVALID_ID, 0 }
    };
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    static const icon_image_config_struct SIM4_ICON_IMAGE_CONFIG[] =
    {
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SIM4_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SIM4_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR },
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SIM4_GPRS_UPLINK, IMG_SI_GPRS_UPLINK},
        { STATUS_ICON_SIM4_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK},
        { STATUS_ICON_SIM4_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK},
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SIM4_EDGEC, IMG_SI_EDGEC },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SIM4_EDGE, IMG_SI_EDGE },
		#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SIM4_EDGE_UPLINK, IMG_SI_EDGE_UPLINK},
        { STATUS_ICON_SIM4_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK},
        { STATUS_ICON_SIM4_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK},
		#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
        { STATUS_ICON_SIM4_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP },
        { STATUS_ICON_SIM4_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED },
#endif
        { STATUS_ICON_SIM4_ROAMING, IMG_SI_ROAMING_INDICATOR },
        { STATUS_ICON_INVALID_ID, 0 }
    };
#endif

#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const icon_image_config_struct *icon_image_config;
    const icon_image_config_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    icon_image_config = NULL;

    switch (sim)
    {
        case MMI_SIM1:
            icon_image_config = SIM1_ICON_IMAGE_CONFIG;
            break;
	#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
        #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            icon_image_config = SIM2_ICON_IMAGE_CONFIG;
            break;
		#endif
#if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            icon_image_config = SIM3_ICON_IMAGE_CONFIG;
            break;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            icon_image_config = SIM4_ICON_IMAGE_CONFIG;
            break;
#endif
	#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */
        default:
            return;
    }

    for (entry = icon_image_config; entry->icon_id != STATUS_ICON_INVALID_ID; entry++)
    {
        wgui_status_icon_bar_change_icon_image(entry->icon_id, entry->single_sim_image);
    }
}


#ifdef __SIM_HOT_SWAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_set_icons_as_multiple_sim
 * DESCRIPTION
 *  Set icons to multiple SIM style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nw_info_set_icons_as_multiple_sim(void)
{
    typedef struct 
    {
        S16 icon_id;
        U16 multiple_sim_image;
    } icon_image_config_struct;

    static const icon_image_config_struct MULTIPLE_SIM_IMAGES[] =
    {
        /* SIM1 */
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1 },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM1 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM1},
        { STATUS_ICON_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM1},
        { STATUS_ICON_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM1},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_EDGEC, IMG_SI_EDGEC_SIM1 },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_EDGE, IMG_SI_EDGE_SIM1 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM1},
        { STATUS_ICON_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM1},
        { STATUS_ICON_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM1},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
#ifdef __OP01_3G__
        /* TD gemini only supports SIM1 now */
        { STATUS_ICON_TD_NO_PDP, IMG_SI_TDC_SIM1 },
        { STATUS_ICON_TD_PDP_ACTIVATED, IMG_SI_TD_SIM1 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_TD_UPLINK, IMG_SI_TD_UPLINK_SIM1},
        { STATUS_ICON_TD_DOWNLINK, IMG_SI_TD_DOWNLINK_SIM1},
        { STATUS_ICON_TD_UPDOWNLINK, IMG_SI_TD_UPDOWNLINK_SIM1},        
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */        
#endif
    #if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
        { STATUS_ICON_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM1 },
        { STATUS_ICON_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_NO_PDP_SIM1 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_HSPA_UPLINK, IMG_SI_HSPA_UPLINK_SIM1},
        { STATUS_ICON_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK_SIM1},
        { STATUS_ICON_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK_SIM1},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
    #endif
	#ifdef __COSMOS_MMI_PACKAGE__
        { STATUS_ICON_ROAMING, IMG_SI_MASTER_ROAMING_INDICATOR },
    #else
		#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
		{ STATUS_ICON_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM1 },
		#else
		{ STATUS_ICON_ROAMING, IMG_SI_ROAMING_INDICATOR },
		#endif /* __MMI_NW_INFO_DN_STATUS_SLIM__ */
	#endif
	
    #ifdef __HOMEZONE_SUPPORT__
        { STATUS_ICON_HOMEZONE, IMG_SI_HZONE_SIM1 },
    #endif

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
	#if (MMI_MAX_SIM_NUM >= 2)
		/* SIM2 */
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2 },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SLAVE_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM2 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SLAVE_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM2},
        { STATUS_ICON_SLAVE_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM2},
        { STATUS_ICON_SLAVE_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM2},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SLAVE_EDGEC, IMG_SI_EDGEC_SIM2 },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SLAVE_EDGE, IMG_SI_EDGE_SIM2 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SLAVE_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM2},
        { STATUS_ICON_SLAVE_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM2},
        { STATUS_ICON_SLAVE_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM2},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
    #if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
        { STATUS_ICON_SLAVE_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM2 },
        { STATUS_ICON_SLAVE_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM2 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SLAVE_HSPA_UPLINK, IMG_SI_HSPA_UPLINK_SIM2},
        { STATUS_ICON_SLAVE_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK_SIM2},
        { STATUS_ICON_SLAVE_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK_SIM2},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
    #endif
	
	#ifdef __COSMOS_MMI_PACKAGE__
        { STATUS_ICON_SLAVE_ROAMING, IMG_SI_SLAVE_ROAMING_INDICATOR },
    #else
		{ STATUS_ICON_SLAVE_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM2 },
	#endif

    #ifdef __HOMEZONE_SUPPORT__
        { STATUS_ICON_SLAVE_HOMEZONE, IMG_SI_HZONE_SIM2 },
    #endif

	#endif /* #if (MMI_MAX_SIM_NUM >= 2) */

		/* SIM3 */
    #if (MMI_MAX_SIM_NUM >= 3)
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SIM3_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM3 },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SIM3_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM3 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SIM3_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM3},
        { STATUS_ICON_SIM3_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM3},
        { STATUS_ICON_SIM3_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM3},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SIM3_EDGEC, IMG_SI_EDGEC_SIM3 },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SIM3_EDGE, IMG_SI_EDGE_SIM3 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SIM3_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM3},
        { STATUS_ICON_SIM3_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM3},
        { STATUS_ICON_SIM3_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM3},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
    #if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
        { STATUS_ICON_SIM3_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM3 },
        { STATUS_ICON_SIM3_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM3 },
    #endif
	
	#ifdef __COSMOS_MMI_PACKAGE__
        { STATUS_ICON_SIM3_ROAMING, IMG_SI_SIM3_ROAMING_INDICATOR },
    #else
		{ STATUS_ICON_SIM3_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM3 },
	#endif

        /* SIM3 does not support homezone icon yet */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */

		/* SIM4 */
    #if (MMI_MAX_SIM_NUM >= 4)
    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SIM4_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM4 },
    #endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SIM4_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM4 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SIM4_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM4},
        { STATUS_ICON_SIM4_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM4},
        { STATUS_ICON_SIM4_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM4},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */        
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
        { STATUS_ICON_SIM4_EDGEC, IMG_SI_EDGEC_SIM4 },
	#endif /* #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__ */
        { STATUS_ICON_SIM4_EDGE, IMG_SI_EDGE_SIM4 },
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
        { STATUS_ICON_SIM4_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM4},
        { STATUS_ICON_SIM4_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM4},
        { STATUS_ICON_SIM4_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM4},
#endif /* #ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
        
    #if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) 
        { STATUS_ICON_SIM4_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM4 },
        { STATUS_ICON_SIM4_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM4 },
    #endif

#ifdef __COSMOS_MMI_PACKAGE__
        { STATUS_ICON_SIM4_ROAMING, IMG_SI_SIM4_ROAMING_INDICATOR },
#else
		{ STATUS_ICON_SIM4_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM4 },
#endif

        /* SIM4 does not support homezone icon yet */
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
	
#endif /* #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ */	

		/* END of SIM */
        { STATUS_ICON_INVALID_ID, 0 }
    };

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const icon_image_config_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (entry = MULTIPLE_SIM_IMAGES; entry->icon_id != STATUS_ICON_INVALID_ID; entry++)
    {
        wgui_status_icon_bar_change_icon_image(entry->icon_id, entry->multiple_sim_image);
    }
    
}
#endif /* __SIM_HOT_SWAP_SUPPORT__ */

#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__COSMOS_MMI_PACKAGE__) */

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ // slim_icon
#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_on_sim_slot_ready
 * DESCRIPTION
 *  Update icons style by SIM slot status
 * PARAMETERS
 *  evt     [IN] srv_bootup_sim_slot_ready_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_on_sim_slot_ready(mmi_event_struct *evt)
{
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_slot_ready_evt_struct *slot_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slot_evt = (srv_bootup_sim_slot_ready_evt_struct*)evt;

    if (slot_evt->n_inserted <= 1)
    {
        mmi_sim_enum sim_to_show = MMI_SIM1;
        
        if (slot_evt->n_inserted == 1)
        {
            sim_to_show = (mmi_sim_enum)slot_evt->inserted_sims;
        }

        mmi_nw_info_set_icons_as_single_sim(sim_to_show);
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    return MMI_RET_OK;
}
#endif
#endif // slim_icon

#if ((defined(__SIM_HOT_SWAP_SUPPORT__) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)) || (defined(__SIM_HOT_SWAP_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)))
/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_icon_on_sim_event
 * DESCRIPTION
 *  Update icons style on SIM event detected
 * PARAMETERS
 *  evt     [IN] srv_sim_ctrl_event_detected_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_icon_on_sim_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *sim_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;

    if (srv_bootup_is_booting())
    {
        return MMI_RET_OK;
    }

    if (sim_evt->type == SRV_SIM_CTRL_EVENT_DET_REMOVED ||
        sim_evt->type == SRV_SIM_CTRL_EVENT_DET_RECOVERY_START)
    {
        if (srv_sim_ctrl_get_num_of_inserted() == 1)
        {
            S32 i;
            mmi_sim_enum remain_sim = MMI_SIM1;

            for (i = 0; i < MMI_SIM_TOTAL; i++)
            {
                remain_sim = mmi_frm_index_to_sim(i);
                if (srv_sim_ctrl_is_inserted(remain_sim))
                {
                    break;
                }
            }
        
            mmi_nw_info_set_icons_as_single_sim(remain_sim);
        }
    }
    else if (sim_evt->type == SRV_SIM_CTRL_EVENT_DET_INSERTED ||
             sim_evt->type == SRV_SIM_CTRL_EVENT_DET_RECOVERY_END ||
             sim_evt->type == SRV_SIM_CTRL_EVENT_DET_BOOTUP_WITH_SIM)
    {
        if (srv_sim_ctrl_get_num_of_inserted() >= 2)
        {
            mmi_nw_info_set_icons_as_multiple_sim();
        }
		// Maybe there is no SIM before interted this SIM
		else
		{
			mmi_nw_info_set_icons_as_single_sim(MMI_SIM1);
		}
    }

    return MMI_RET_OK;
}
#endif /*(defined(__SIM_HOT_SWAP_SUPPORT__) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
|| (defined(__SIM_HOT_SWAP_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__))*/

