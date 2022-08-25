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
 *  CallSetStructMgmt.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting application context management
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "CallSetProt.h"

#include "string.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "kal_non_specific_general_types.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static void mmi_callset_sim_early_init(mmi_sim_enum sim);

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
static mmi_callset_context_struct g_mmi_callset_context;
mmi_callset_context_struct *mmi_callset_p = &(g_mmi_callset_context);
mmi_callset_sim_cntx_struct *mmi_callset_sim_p;

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_early_init
 * DESCRIPTION
 *  call setting application early initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_early_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_AP_DCM_CALLSET__)
    if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
        mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif

    mmi_callset_sim_early_init(MMI_SIM1);
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_callset_sim_early_init(MMI_SIM2);
#if (MMI_MAX_SIM_NUM>=3)
    mmi_callset_sim_early_init(MMI_SIM3);
#if (MMI_MAX_SIM_NUM>=4)
    mmi_callset_sim_early_init(MMI_SIM4);
#endif /* MMI_MAX_SIM_NUM>=4*/
#endif /* MMI_MAX_SIM_NUM>=3*/
#endif /*  (MMI_MAX_SIM_NUM >= 2) */

#if defined (__MMI_AP_DCM_CALLSET__)
    if (!mmi_frm_app_is_launched(APP_SETTING_NEW))
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SETTINGS);
#endif
}


#ifdef __MMI_AP_DCM_CALLSET__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sim_cntx_set_ptr
 * DESCRIPTION
 *  reset sim context pointer (unlock sim context) 
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sim_cntx_set_ptr(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_callset_sim_p)
    {
        MMI_ASSERT(0);
    }

    /* lock mmi_callset_sim_p */

    switch (sim)
    {
        case MMI_SIM1:
            mmi_callset_sim_p = &(g_mmi_callset_context.sim1_cntx);
            break;

#if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            mmi_callset_sim_p = &(g_mmi_callset_context.sim2_cntx);
            break;

#if (MMI_MAX_SIM_NUM>=3)
		case MMI_SIM3:
            mmi_callset_sim_p = &(g_mmi_callset_context.sim3_cntx);
            break;

#if (MMI_MAX_SIM_NUM>=4)
		case MMI_SIM4:
            mmi_callset_sim_p = &(g_mmi_callset_context.sim4_cntx);
            break;

#endif /* MMI_MAX_SIM_NUM>=4*/
#endif /* MMI_MAX_SIM_NUM>=3*/
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            break;
    }

    // TODO: trace
    //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_mmi_callset_sim_cntx_set_ptr, sim);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sim_cntx_reset_ptr
 * DESCRIPTION
 *  reset sim context pointer (unlock sim context)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_callset_sim_cntx_reset_ptr(void)
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
    //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_mmi_callset_sim_cntx_reset_ptr);

    mmi_callset_sim_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_sim_cntx_is_locked
 * DESCRIPTION
 *  check if sim context is locked
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if it is locked
 *****************************************************************************/
MMI_BOOL mmi_callset_sim_cntx_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_callset_sim_p ? MMI_TRUE : MMI_FALSE;
}


void mmi_callset_sim_early_init(mmi_sim_enum sim)
{
    mmi_callset_sim_cntx_set_ptr(sim);
    mmi_callset_sim_p->sim = sim;

#ifdef __MMI_CALLSET_CUG__
    memset(mmi_callset_sim_p->cug_map, (U8)-1, sizeof(mmi_callset_sim_p->cug_map));
#endif /* __MMI_CALLSET_CUG__ */

    mmi_callset_sim_cntx_reset_ptr();
}

#ifdef __MMI_AP_DCM_CALLSET__
#pragma arm section rodata , code
#endif


