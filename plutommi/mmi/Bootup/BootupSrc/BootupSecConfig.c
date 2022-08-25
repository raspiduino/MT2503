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
 *  BootupSecConfig.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Security control of bootup app part.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "BootupAppProt.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_bootup_def.h"
#include "mmi_frm_gprot.h"
#include "wgui_categories_util.h"
#include "SimCtrlSrvGprot.h"


/****************************************************************************
 * Configurations
 ****************************************************************************/


typedef struct
{
    srv_bootup_verification_type_enum type;
    U16 sim_input_prompt;
    U16 wrong_msg;
} mmi_bootup_sim_prompt_string_struct;


/* Prompt strings on SIM verification */
#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
static const mmi_bootup_sim_prompt_string_struct g_mmi_bootup_sec_sim_prompts_single[] =
{
    { SRV_BOOTUP_VERI_CHV1, STR_ID_BOOTUP_INPUT_CHV1, STR_ID_BOOTUP_WRONG_CHV1 },
    { SRV_BOOTUP_VERI_UBCHV1, STR_ID_BOOTUP_INPUT_UBCHV1, STR_ID_BOOTUP_WRONG_UBCHV1 },
#ifdef __SIM_ME_LOCK__
    { SRV_BOOTUP_VERI_NP, STR_ID_BOOTUP_INPUT_NP, STR_ID_BOOTUP_WRONG_NP },
    { SRV_BOOTUP_VERI_NSP, STR_ID_BOOTUP_INPUT_NSP, STR_ID_BOOTUP_WRONG_NSP },
    { SRV_BOOTUP_VERI_SP, STR_ID_BOOTUP_INPUT_SP, STR_ID_BOOTUP_WRONG_SP },
    { SRV_BOOTUP_VERI_CP, STR_ID_BOOTUP_INPUT_CP, STR_ID_BOOTUP_WRONG_CP },
    { SRV_BOOTUP_VERI_SIMP, STR_ID_BOOTUP_INPUT_SIMP, STR_ID_BOOTUP_WRONG_SIMP },
#ifdef __MMI_SML_MENU__
    { SRV_BOOTUP_VERI_NSSP, STR_ID_BOOTUP_INPUT_NSSP, STR_ID_BOOTUP_WRONG_NSSP },
    { SRV_BOOTUP_VERI_SIMCP, STR_ID_BOOTUP_INPUT_SIMCP, STR_ID_BOOTUP_WRONG_SIMCP },
#endif
#endif /* __SIM_ME_LOCK__ */
    /* ------------------------------------------------------------------------------ */
    { SRV_BOOTUP_VERI_END_OF_ENUM, 0, 0 }
};
#endif /* (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */


#if (MMI_MAX_SIM_NUM >= 2)
static const mmi_bootup_sim_prompt_string_struct g_mmi_bootup_sec_sim_prompts_multiple[] =
{
	#ifndef __MMI_MAINLCD_96X64__
    { SRV_BOOTUP_VERI_CHV1, STR_ID_BOOTUP_SIMX_INPUT_CHV1, STR_ID_BOOTUP_WRONG_CHV1 },
	#else
	{ SRV_BOOTUP_VERI_CHV1, STR_ID_BOOTUP_SIMX_INPUT_CHV1_BWUI, STR_ID_BOOTUP_WRONG_CHV1 },
	#endif /* #ifndef __MMI_MAINLCD_96X64__ */
    { SRV_BOOTUP_VERI_UBCHV1, STR_ID_BOOTUP_SIMX_INPUT_UBCHV1, STR_ID_BOOTUP_WRONG_UBCHV1 },
#ifdef __SIM_ME_LOCK__
    { SRV_BOOTUP_VERI_NP, STR_ID_BOOTUP_SIMX_INPUT_NP, STR_ID_BOOTUP_WRONG_NP },
    { SRV_BOOTUP_VERI_NSP, STR_ID_BOOTUP_SIMX_INPUT_NSP, STR_ID_BOOTUP_WRONG_NSP },
    { SRV_BOOTUP_VERI_SP, STR_ID_BOOTUP_SIMX_INPUT_SP, STR_ID_BOOTUP_WRONG_SP },
    { SRV_BOOTUP_VERI_CP, STR_ID_BOOTUP_SIMX_INPUT_CP, STR_ID_BOOTUP_WRONG_CP },
    { SRV_BOOTUP_VERI_SIMP, STR_ID_BOOTUP_SIMX_INPUT_SIMP, STR_ID_BOOTUP_WRONG_SIMP },
#ifdef __MMI_SML_MENU__
    { SRV_BOOTUP_VERI_NSSP, STR_ID_BOOTUP_SIMX_INPUT_NSSP, STR_ID_BOOTUP_WRONG_NSSP },
    { SRV_BOOTUP_VERI_SIMCP, STR_ID_BOOTUP_SIMX_INPUT_SIMCP, STR_ID_BOOTUP_WRONG_SIMCP },
#endif /* __MMI_SML_MENU__ */
#endif /* __SIM_ME_LOCK__ */
    /* ------------------------------------------ */
    { SRV_BOOTUP_VERI_END_OF_ENUM, 0, 0 }
};
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/****************************************************************************
 * Functions
 ****************************************************************************/

static const mmi_bootup_sim_prompt_string_struct *mmi_bootup_sec_get_prompt_entry(
    srv_bootup_verification_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_bootup_sim_prompt_string_struct *entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    entry = g_mmi_bootup_sec_sim_prompts_single;
#else
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    if (srv_sim_ctrl_get_num_of_inserted() <= 1)
    {
        entry = g_mmi_bootup_sec_sim_prompts_single;
    }
    else
#endif
    {
        entry = g_mmi_bootup_sec_sim_prompts_multiple;
    }
#endif
    
    for ( ;
         entry->type != SRV_BOOTUP_VERI_END_OF_ENUM;
         entry++)
    {
        if (entry->type == type)
        {
            break;
        }
    }

    MMI_ASSERT(entry->type != SRV_BOOTUP_VERI_END_OF_ENUM);

    return entry;
}


static WCHAR* mmi_bootup_sec_compose_sim_str(
        mmi_sim_enum sim,
        U32 msg_id,
        WCHAR *out_buffer,
        S32 max_n_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    mmi_wcsncpy(out_buffer, get_string(msg_id), max_n_chars);
#else
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    if (srv_sim_ctrl_get_num_of_inserted() <= 1)
    {
        mmi_wcsncpy(out_buffer, get_string(msg_id), max_n_chars);
    }
    else
#endif
    {
        mmi_sim_ctrl_gen_str(out_buffer, max_n_chars, msg_id, sim);
    }
#endif

    return out_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_get_input_prompt
 * DESCRIPTION
 *  Get the input prompt of the verification type.
 * PARAMETERS
 *  sim         [IN] Which SIM
 *  veri_type   [IN] Verification type
 * RETURNS
 *  String ID of the prompt
 *****************************************************************************/
WCHAR* mmi_bootup_sec_get_input_prompt(
        mmi_sim_enum sim,
        srv_bootup_verification_type_enum veri_type,
        WCHAR *out_buffer,
        S32 max_n_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;
    const mmi_bootup_sim_prompt_string_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = mmi_bootup_sec_get_prompt_entry(veri_type);
    msg_id = entry->sim_input_prompt;

    mmi_bootup_sec_compose_sim_str(sim, msg_id, out_buffer, max_n_chars);

    return out_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_get_message_of_result
 * DESCRIPTION
 *  Get the prompt string of verification result.
 * PARAMETERS
 *  result   [IN] Result
 * RETURNS
 *  String ID of the prompt
 *****************************************************************************/
WCHAR* mmi_bootup_sec_get_message_of_result(
        const srv_bootup_verify_result_struct *result,
        WCHAR *out_buffer,
        S32 max_n_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = STR_GLOBAL_ERROR;
    
    if (result->success)
    {
        msg_id = STR_GLOBAL_DONE;
    }
    else if (result->type == SRV_BOOTUP_VERI_PHONE_LOCK)
    {
        msg_id = STR_ID_BOOTUP_WRONG_PHONE_PASSWORD;
    }
    else
    {
        const mmi_bootup_sim_prompt_string_struct *entry;

        entry = mmi_bootup_sec_get_prompt_entry(result->type);
        msg_id = entry->wrong_msg;
    }

    mmi_bootup_sec_compose_sim_str(result->sim, msg_id, out_buffer, max_n_chars);

    return out_buffer;
}

