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
 *  SsUi.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS (Supplementary Service) application structure management
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#include "SsProt.h"
#include "MMIDataType.h"
#include "string.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "kal_non_specific_general_types.h"
#include "SsSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_utility_gprot.h"   /* For MMI_SIM_TOTAL & MMI_SIM_ALL */


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
static mmi_ss_cntx_struct g_mmi_ss_cntx;
#if (MMI_MAX_SIM_NUM >= 2)
static mmi_ss_cntx_struct g_mmi_ss_cntx_2;
#if (MMI_MAX_SIM_NUM >= 3)
static mmi_ss_cntx_struct g_mmi_ss_cntx_3;
#if (MMI_MAX_SIM_NUM == 4)
static mmi_ss_cntx_struct g_mmi_ss_cntx_4;
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
mmi_ss_cntx_struct *mmi_ss_p;


/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_init
 * DESCRIPTION
 *  call setting application initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        mmi_ss_cntx_set_ptr(sim_id);
        memset(mmi_ss_p, 0, sizeof(mmi_ss_cntx_struct));
        mmi_ss_p->sim = sim_id;
        mmi_ss_cntx_reset_ptr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_set_ptr
 * DESCRIPTION
 *  set context pointer (lock sim context) 
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_set_ptr(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_ss_p)
    {
        MMI_ASSERT(0);
    }

    /* lock mmi_ss_p */

    switch (sim)
    {
        case MMI_SIM1:
            mmi_ss_p = &g_mmi_ss_cntx;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            mmi_ss_p = &g_mmi_ss_cntx_2;
           break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            mmi_ss_p = &g_mmi_ss_cntx_3;
           break;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            mmi_ss_p = &g_mmi_ss_cntx_4;
           break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            break;
    }


    // TODO: trace
    //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_CNTX_SET_PTR, sim);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_reset_ptr
 * DESCRIPTION
 *  reset context pointer (unlock context)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_reset_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* unlock */
    /* Shall reset cntxt ptr after all cntxt related operation is done */

    // TODO: trace
    //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_CNTX_RESET_PTR);

    mmi_ss_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_is_locked
 * DESCRIPTION
 *  check if context is locked
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if it is locked
 *****************************************************************************/
MMI_BOOL mmi_ss_cntx_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_ss_p ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_get_curr_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  
 *****************************************************************************/
srv_ss_act_enum mmi_ss_cntx_get_curr_op(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allow to get is_in_call no matter cntx ptr is lock or not */

    switch (sim)
    {
        case MMI_SIM1:
            return g_mmi_ss_cntx.curr_op;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return g_mmi_ss_cntx_2.curr_op;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return g_mmi_ss_cntx_3.curr_op;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return g_mmi_ss_cntx_4.curr_op;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            return SRV_SS_ACT_TOTAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_set_curr_op
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim     [IN]        target sim
 *  op      [IN]        current operation code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_set_curr_op(mmi_sim_enum sim, srv_ss_act_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_set_ptr(sim);
    mmi_ss_p->curr_op = op;
    mmi_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_get_connected_call_num
 * DESCRIPTION
 *  check if it is need to adjust screen
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  MMI_TRUE if it is need to adjust screen
 *****************************************************************************/
S32 mmi_ss_cntx_get_connected_call_num(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allow to get need_to_adj no matter cntx ptr is lock or not */

    switch (sim)
    {
        case MMI_SIM1:
            return g_mmi_ss_cntx.ctd_call_num;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return g_mmi_ss_cntx_2.ctd_call_num;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return g_mmi_ss_cntx_3.ctd_call_num;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return g_mmi_ss_cntx_4.ctd_call_num;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            return 0xff;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_set_connected_call_num
 * DESCRIPTION
 *  Set the number of active and held call 
 * PARAMETERS
 *  sim     [IN]        target sim
 *  ctd_call_num   [IN]    active and held call number
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_set_connected_call_num(mmi_sim_enum sim, S32 ctd_call_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_set_ptr(sim);
    mmi_ss_p->ctd_call_num = ctd_call_num;
    mmi_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_get_scr_proceed
 * DESCRIPTION
 *  get screen proceeding information
 * PARAMETERS
 *  sim     [IN]    target sim
 *  info    [OUT]   screen proceed information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_get_scr_proceed(mmi_sim_enum sim, mmi_ss_scr_proceed_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info)
    {
        return;
    }

    /* allow to get is_in_call no matter cntx ptr is lock or not */
    switch (sim)
    {
        case MMI_SIM1:
            memcpy(info, &(g_mmi_ss_cntx.scr_proceed), sizeof(mmi_ss_scr_proceed_struct));
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            memcpy(info, &(g_mmi_ss_cntx_2.scr_proceed), sizeof(mmi_ss_scr_proceed_struct));
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            memcpy(info, &(g_mmi_ss_cntx_3.scr_proceed), sizeof(mmi_ss_scr_proceed_struct));
            break;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            memcpy(info, &(g_mmi_ss_cntx_4.scr_proceed), sizeof(mmi_ss_scr_proceed_struct));
            break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            memset(info, 0, sizeof(mmi_ss_scr_proceed_struct));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_set_scr_proceed
 * DESCRIPTION
 *  set screen proceeding information
 * PARAMETERS
 *  sim     [IN]        target sim
 *  user_data   [IN]    user data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_set_scr_proceed(mmi_sim_enum sim, mmi_ss_scr_proceed_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(info);

    mmi_ss_cntx_set_ptr(sim);
    memcpy(&(mmi_ss_p->scr_proceed), info, sizeof(mmi_ss_scr_proceed_struct));
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_SS_CNTX_SET_SCR_PROCEED, info->proceeding, info->from_grp, info->from_id);
    mmi_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_get_scr_defer
 * DESCRIPTION
 *  get screen defer information
 * PARAMETERS
 *  sim     [IN]    target sim
 *  info    [OUT]   screen defer information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_get_scr_defer(mmi_sim_enum sim, mmi_ss_scr_defer_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info)
    {
        return;
    }

    /* allow to get no matter cntx ptr is lock or not */
    switch (sim)
    {
        case MMI_SIM1:
            memcpy(info, &(g_mmi_ss_cntx.scr_defer), sizeof(mmi_ss_scr_defer_struct));
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            memcpy(info, &(g_mmi_ss_cntx_2.scr_defer), sizeof(mmi_ss_scr_defer_struct));
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            memcpy(info, &(g_mmi_ss_cntx_3.scr_defer), sizeof(mmi_ss_scr_defer_struct));
            break;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            memcpy(info, &(g_mmi_ss_cntx_4.scr_defer), sizeof(mmi_ss_scr_defer_struct));
            break;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            memset(info, 0, sizeof(mmi_ss_scr_defer_struct));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_set_scr_defer
 * DESCRIPTION
 *  set screen defer information
 * PARAMETERS
 *  sim     [IN]        target sim
 *  user_data   [IN]    user data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_set_scr_defer(mmi_sim_enum sim, mmi_ss_scr_defer_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(info);

    mmi_ss_cntx_set_ptr(sim);
    memcpy(&(mmi_ss_p->scr_defer), info, sizeof(mmi_ss_scr_defer_struct));
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_SS_CNTX_SET_SCR_DEFER, info->deferring, info->defer_entry_func, info->defer_user_data);
    mmi_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_get_adj_grp_user_data
 * DESCRIPTION
 *  check if there are active / held calls
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  user data for adjusting group
 *****************************************************************************/
void *mmi_ss_cntx_get_adj_grp_user_data(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allow to get adj_grp_user_data no matter cntx ptr is lock or not */

    switch (sim)
    {
        case MMI_SIM1:
            return g_mmi_ss_cntx.adj_grp_user_data;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return g_mmi_ss_cntx_2.adj_grp_user_data;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return g_mmi_ss_cntx_3.adj_grp_user_data;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return g_mmi_ss_cntx_4.adj_grp_user_data;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_cntx_set_adj_grp_user_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim     [IN]        target sim
 *  user_data   [IN]    user data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_cntx_set_adj_grp_user_data(mmi_sim_enum sim, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_set_ptr(sim);
    mmi_ss_p->adj_grp_user_data = user_data;
    mmi_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_set_hilight_idx
 * DESCRIPTION
 *  Set the hilight index of ussd screen
 * PARAMETERS
 *  sim     [IN]        SIM ID
 *  idx     [IN]        hilight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_set_hilight_idx(mmi_sim_enum sim, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ss_cntx_set_ptr(sim);
    mmi_ss_p->hilight_idx = idx;
    mmi_ss_cntx_reset_ptr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_get_hilight_idx
 * DESCRIPTION
 *  Get the hilight index of ussd screen
 * PARAMETERS
 *  sim     [IN]        SIM ID
 * RETURNS
 *  Hilight index
 *****************************************************************************/
S32 mmi_ss_get_hilight_idx(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim)
    {
        case MMI_SIM1:
            return g_mmi_ss_cntx.hilight_idx;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return g_mmi_ss_cntx_2.hilight_idx;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return g_mmi_ss_cntx_3.hilight_idx;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return g_mmi_ss_cntx_4.hilight_idx;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            return 0xff;
    }
}



