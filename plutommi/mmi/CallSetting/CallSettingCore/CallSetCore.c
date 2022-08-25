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
 *  CallSetCore.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting application core
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "CallSetSrvGprot.h"
#include "CallSetSrvIprot.h"
#include "CallSetCore.h"
#include "CallSetProt.h"
#include "Mmi_rp_app_callset_def.h"

#include "CallSetSrvGprot.h"

#if (MMI_MAX_SIM_NUM >= 2)
#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_get_current_mode */
#endif /*  (MMI_MAX_SIM_NUM >= 2) */

#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "gui_typedef.h"
#include "mmi_rp_srv_status_icons_def.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
#ifdef __MMI_STATUS_ICON_BAR_SLIM__
srv_callset_cfu_status_enum g_mmi_callset_cfu_status[MMI_MAX_SIM_NUM];
#endif /* __MMI_STATUS_ICON_BAR_SLIM__ */

/***************************************************************************** 
 * Function
 *****************************************************************************/

#ifdef __IP_NUMBER__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_util_ip_number_activate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_util_ip_number_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_callset_ip_number_activate(mmi_callset_p->target_sim, (U8)(mmi_callset_p->ip_number_input));

    switch (result)
    {
        case SRV_CALLSET_RESULT_OK:
            mmi_popup_display_simple_ext(STR_GLOBAL_ACTIVATED, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
            break;

        default:
            mmi_popup_display_simple_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_util_ip_number_deactivate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_util_ip_number_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_callset_ip_number_deactivate(mmi_callset_p->target_sim, (U8)(mmi_callset_p->ip_number_input));

    switch (result)
    {
        case SRV_CALLSET_RESULT_OK:
            mmi_popup_display_simple_ext(STR_ID_CALLSET_DEACTIVATED, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
            break;

        default:
            mmi_popup_display_simple_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
            break;
    }
}
#endif /* __IP_NUMBER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sel_lsw_cb
 * DESCRIPTION
 *  callback handler for line switch result
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_util_lsw_update_status_icon(mmi_sim_enum sim, srv_callset_line_id_enum line_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_CALLSET_UTIL_LSW_UPDATE_STATUS_ICON, sim, line_id);

#ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
#if (MMI_MAX_SIM_NUM >= 2)
    /* not support */
    return;
#else /*  (MMI_MAX_SIM_NUM >= 2) */
    if (line_id == SRV_CALLSET_LINE1)
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_ALTERNATE_LINE_L2);
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALTERNATE_LINE_L1);
    }
    else if (line_id == SRV_CALLSET_LINE2)
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_ALTERNATE_LINE_L1);
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALTERNATE_LINE_L2);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_ALTERNATE_LINE_L1);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_ALTERNATE_LINE_L2);
    }
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 

    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_util_cf_update_status_icon
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_util_cf_update_status_icon(mmi_sim_enum sim, srv_callset_cfu_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICON_BAR_SLIM__
    srv_callset_cfu_status_enum temp_status;
#endif /* __MMI_STATUS_ICON_BAR_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_CALLSET_UTIL_CF_UPDATE_STATUS_ICON, sim, status);

#ifdef __MMI_STATUS_ICON_BAR_SLIM__

    if(sim == MMI_SIM1)
    {
        g_mmi_callset_cfu_status[0] = status;
    }
  #if (MMI_MAX_SIM_NUM >= 2)
    else if(sim == MMI_SIM2)
    {
        g_mmi_callset_cfu_status[1] = status;
    }
  #if (MMI_MAX_SIM_NUM >= 3)
    else if(sim == MMI_SIM3)
    {
        g_mmi_callset_cfu_status[2] = status;
    }
  #if (MMI_MAX_SIM_NUM >= 4)
    else if(sim == MMI_SIM4)
    {
        g_mmi_callset_cfu_status[3] = status;
    }
  #endif /* MMI_MAX_SIM_NUM >= 4 */
  #endif /* MMI_MAX_SIM_NUM >= 3 */
  #endif /* MMI_MAX_SIM_NUM >= 2 */

    temp_status = g_mmi_callset_cfu_status[0]
            #if (MMI_MAX_SIM_NUM >= 2)
                | g_mmi_callset_cfu_status[1]
            #if (MMI_MAX_SIM_NUM >= 3)
                | g_mmi_callset_cfu_status[2]
            #if (MMI_MAX_SIM_NUM >= 4)
                | g_mmi_callset_cfu_status[3]
            #endif /* MMI_MAX_SIM_NUM >= 4 */
            #endif /* MMI_MAX_SIM_NUM >= 3 */
            #endif /* MMI_MAX_SIM_NUM >= 2 */
                ;
    
#ifdef __MMI_CFU_SEPARATE_LINE__
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_DIVERT_L1L2);
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_DIVERT_L1);
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_DIVERT_L2);
    if ((temp_status & SRV_CALLSET_CFU_LINE1_ACTIVATED) &&
        (temp_status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_DIVERT_L1L2);
    }
    else if (temp_status & SRV_CALLSET_CFU_LINE1_ACTIVATED)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_DIVERT_L1);
    }
    else if (temp_status & SRV_CALLSET_CFU_LINE2_ACTIVATED)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_DIVERT_L2);
    }
#else /* __MMI_CFU_SEPARATE_LINE__ */
    if ((temp_status & SRV_CALLSET_CFU_LINE1_ACTIVATED) ||
        (temp_status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_DIVERT_L1L2);
    }
    else
    {
        /* not support or both sim1 and sim2 cfu are deactivated */
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_DIVERT_L1L2);
    }
#endif /* __MMI_CFU_SEPARATE_LINE__ */

#else /* __MMI_STATUS_ICON_BAR_SLIM__ */

    if (sim == MMI_SIM1)
    {
    #ifdef __MMI_CFU_SEPARATE_LINE__
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_DIVERT_L1L2);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_DIVERT_L1);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_DIVERT_L2);
        if ((status & SRV_CALLSET_CFU_LINE1_ACTIVATED) &&
            (status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_DIVERT_L1L2);
        }
        else if (status & SRV_CALLSET_CFU_LINE1_ACTIVATED)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_DIVERT_L1);
        }
        else if (status & SRV_CALLSET_CFU_LINE2_ACTIVATED)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_DIVERT_L2);
        }
    #else /* __MMI_CFU_SEPARATE_LINE__ */
        if ((status & SRV_CALLSET_CFU_LINE1_ACTIVATED) ||
            (status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_DIVERT_L1L2);
        }
        else
        {
            /* not support or both sim1 and sim2 cfu are deactivated */
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_DIVERT_L1L2);
        }
    #endif /* __MMI_CFU_SEPARATE_LINE__ */
    }
#if (MMI_MAX_SIM_NUM >= 2) && !defined(__MMI_STATUS_ICON_BAR_SLIM__)
    else if (sim == MMI_SIM2)
    {
    #ifdef __MMI_CFU_SEPARATE_LINE__
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SLAVE_CALLFORWARD);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SLAVE_CALLFORWARD_L1);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SLAVE_CALLFORWARD_L2);
        if ((status & SRV_CALLSET_CFU_LINE1_ACTIVATED) &&
            (status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SLAVE_CALLFORWARD);
        }
        else if (status & SRV_CALLSET_CFU_LINE1_ACTIVATED)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SLAVE_CALLFORWARD_L1);
        }
        else if (status & SRV_CALLSET_CFU_LINE2_ACTIVATED)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SLAVE_CALLFORWARD_L2);
        }
    #else /* __MMI_CFU_SEPARATE_LINE__ */
        if ((status & SRV_CALLSET_CFU_LINE1_ACTIVATED) ||
            (status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SLAVE_CALLFORWARD);
        }
        else
        {
            /* not support or both sim1 and sim2 cfu are deactivated */
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SLAVE_CALLFORWARD);
        }
    #endif /* __MMI_CFU_SEPARATE_LINE__ */
    }
#if (MMI_MAX_SIM_NUM>=3)
	else if(sim == MMI_SIM3)
	{
		#ifdef __MMI_CFU_SEPARATE_LINE__
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM3_CALL_DIVERT);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM3_CALL_DIVERT_L1);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM3_CALL_DIVERT_L2);
        if ((status & SRV_CALLSET_CFU_LINE1_ACTIVATED) &&
            (status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM3_CALL_DIVERT);
        }
        else if (status & SRV_CALLSET_CFU_LINE1_ACTIVATED)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM3_CALL_DIVERT_L1);
        }
        else if (status & SRV_CALLSET_CFU_LINE2_ACTIVATED)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM3_CALL_DIVERT_L2);
        }
    #else /* __MMI_CFU_SEPARATE_LINE__ */
        if ((status & SRV_CALLSET_CFU_LINE1_ACTIVATED) ||
            (status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM3_CALL_DIVERT);
        }
        else
        {
            /* not support or both sim1 and sim2 cfu are deactivated */
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM3_CALL_DIVERT);
        }
    #endif /* __MMI_CFU_SEPARATE_LINE__ */
	}
#if (MMI_MAX_SIM_NUM>=4)
	else if(sim == MMI_SIM4)
	{
		#ifdef __MMI_CFU_SEPARATE_LINE__
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM4_CALL_DIVERT);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM4_CALL_DIVERT_L1);
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM4_CALL_DIVERT_L2);
        if ((status & SRV_CALLSET_CFU_LINE1_ACTIVATED) &&
            (status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM4_CALL_DIVERT);
        }
        else if (status & SRV_CALLSET_CFU_LINE1_ACTIVATED)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM4_CALL_DIVERT_L1);
        }
        else if (status & SRV_CALLSET_CFU_LINE2_ACTIVATED)
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM4_CALL_DIVERT_L2);
        }
    #else /* __MMI_CFU_SEPARATE_LINE__ */
        if ((status & SRV_CALLSET_CFU_LINE1_ACTIVATED) ||
            (status & SRV_CALLSET_CFU_LINE2_ACTIVATED))
        {
            wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM4_CALL_DIVERT);
        }
        else
        {
            /* not support or both sim1 and sim2 cfu are deactivated */
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM4_CALL_DIVERT);
        }
    #endif /* __MMI_CFU_SEPARATE_LINE__ */
	}
#endif /* MMI_MAX_SIM_NUM>=4*/
#endif /* MMI_MAX_SIM_NUM>=3 */
#endif /*  (MMI_MAX_SIM_NUM >= 2) && !defined(__MMI_STATUS_ICON_BAR_SLIM__) */

#endif  /* __MMI_STATUS_ICON_BAR_SLIM__ */

    wgui_status_icon_bar_update();
}


