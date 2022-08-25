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
 *  SecSetUbchv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  UBCHV of SIM
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SecSetProt.h"
#include "SimCtrlSrvGprot.h"
#include "PwdCuiGprot.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "AlertScreen.h"
#include "mmi_rp_app_security_setting_def.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"


/****************************************************************************
 * Context
 ****************************************************************************/
#if defined(__MMI_TELEPHONY_SUPPORT__)

#define MMI_SECSET_UBCHV_VALID_MAGIC 0x20405080

typedef struct
{
    U32 valid_magic;
    mmi_id parent_grp_id;
    mmi_id this_grp_id;
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum type;
    mmi_id ubchv_cui;   /* cui_pwd_guard */
    mmi_proc_func proc;
    void *user_data;
} mmi_secset_ubchv_cntx;


/****************************************************************************
 * Functions
 ****************************************************************************/

static mmi_ret mmi_secset_ubchv_result_proc(mmi_event_struct *evt);

static mmi_ret mmi_secset_ubchv_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ubchv_cntx *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {
        cntx = (mmi_secset_ubchv_cntx*)evt->user_data;

        MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_UBCHV_GROUP_DEINIT, (U32)cntx);
        
        cntx->valid_magic = 0;
        mmi_mfree(cntx);
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_secset_ubchv_input_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ubchv_cntx *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_ubchv_cntx*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_GUARD_DONE:
        {
            cui_pwd_guard_done_evt_struct *done_evt;

            done_evt = (cui_pwd_guard_done_evt_struct*)evt;
            if (srv_sim_ctrl_verify_ubchv(
                    cntx->sim,
                    cntx->type,
                    done_evt->guard,
                    done_evt->input,
                    mmi_secset_ubchv_result_proc,
                    cntx) > 0)
            {
                mmi_secset_show_waiting(cntx->this_grp_id);
            }
            else
            {
                mmi_popup_display_simple(
                    get_string(STR_ID_SECSET_TEMP_FAIL),
                    MMI_EVENT_FAILURE,
                    cntx->parent_grp_id,
                    cntx);
            }
        
            break;
        }

        case EVT_ID_CUI_PWD_GUARD_KEY:
        {
            cui_pwd_guard_key_evt_struct *key_evt;
            const WCHAR *number;

            key_evt = (cui_pwd_guard_key_evt_struct*)evt;

            if (cntx->type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1 &&
                key_evt->key_type == KEY_EVENT_DOWN)
            {
                if (key_evt->key_code == KEY_SEND ||
                    key_evt->key_code == KEY_SEND1 ||
                    key_evt->key_code == KEY_SEND2)
                {
                    number = cui_pwd_guard_get_input_of_active(cntx->ubchv_cui);
                    if (number[0] != L'\0')
                    {
                        mmi_secset_make_emergency_call(cntx->this_grp_id, number);
                        cui_pwd_guard_clear_input_of_active(cntx->ubchv_cui);
                    }
                }
            }
            
            break;
        }

        case EVT_ID_CUI_PWD_GUARD_CANCEL:
            if (cntx->type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
            {
                MMI_ASSERT(0);
            }
            else
            {
                mmi_secset_ubchv_cancel_evt_struct cancel_evt;
                
                MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_SECSET_UBCHV_CANCEL);
                cancel_evt.instance = cntx;
                MMI_FRM_SEND_EVENT(&cancel_evt, cntx->proc, cntx->user_data);
            }
            break;
            
        case EVT_ID_CUI_PWD_GUARD_PASSIVE_CLOSING:
            if (cntx->type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
            {
                return CUI_PWD_DONT_CLOSE;
            }
            else
            {
                mmi_secset_ubchv_passive_closing_evt_struct closing_evt;
                mmi_ret ret;
                
                MMI_FRM_INIT_EVENT(&closing_evt, EVT_ID_SECSET_UBCHV_PASSIVE_CLOSING);
                closing_evt.instance = cntx;
                ret = MMI_FRM_SEND_EVENT(&closing_evt, cntx->proc, cntx->user_data);
                
                if (ret == MMI_SECSET_DONT_CLOSE)
                {
                    return CUI_PWD_DONT_CLOSE;
                }
            }
            break;

        case EVT_ID_CUI_PWD_GUARD_AUX:
        {
            cui_pwd_guard_aux_evt_struct *aux_evt;

            aux_evt = (cui_pwd_guard_aux_evt_struct*)evt;
            if (aux_evt->type == CUI_PWD_AUXILIARY_GUARD_DEFAULT)
            {
                mmi_confirm_property_struct confirm_arg;

                mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
                confirm_arg.parent_id = cntx->this_grp_id;
                confirm_arg.callback = mmi_secset_make_emergency_call_on_yes;
                confirm_arg.user_tag = NULL;

                mmi_confirm_display(
                    get_string(STR_ID_SECSET_EMERGENCY_CALL_ASK),
                    MMI_EVENT_QUERY,
                    &confirm_arg);
            }
        
            break;
        }
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_secset_ubchv_result_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ubchv_cntx *cntx;
    srv_sim_ctrl_verify_result_evt_struct *result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_ubchv_cntx*)evt->user_data;

    if (cntx->valid_magic != MMI_SECSET_UBCHV_VALID_MAGIC ||
        !mmi_frm_group_is_present(cntx->this_grp_id))
    {
        /* Session screen is already cancelled during verifying */
        return MMI_RET_OK;
    }

    mmi_secset_close_waiting(cntx->this_grp_id);

    if (evt->evt_id == EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT)
    {
        result_evt = (srv_sim_ctrl_verify_result_evt_struct*)evt;

        if (result_evt->success)
        {
            mmi_secset_ubchv_unblocked_evt_struct unblocked_evt;
            
            MMI_FRM_INIT_EVENT(&unblocked_evt, EVT_ID_SECSET_UBCHV_UNBLOCKED);
            unblocked_evt.instance = cntx;
            MMI_FRM_SEND_EVENT(&unblocked_evt, cntx->proc, cntx->user_data);
        }
        else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
        {
            if (srv_sim_ctrl_pwd_is_blocked(result_evt->sim, cntx->type))
            {
                mmi_secset_ubchv_blocked_evt_struct blocked_evt;

                MMI_FRM_INIT_EVENT(&blocked_evt, EVT_ID_SECSET_UBCHV_BLOCKED);
                blocked_evt.instance = cntx;
                MMI_FRM_SEND_EVENT(&blocked_evt, cntx->proc, cntx->user_data);
            }
            else
            {
                WCHAR *remaining_attempts_prompt;
            
                /* Update # of remaining attempts message */
                remaining_attempts_prompt = (WCHAR*)mmi_malloc(
                    (CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 30) * sizeof(WCHAR));
                mmi_secset_n_attempts_to_str(
                    srv_sim_ctrl_get_n_remaining_attempts(cntx->sim, cntx->type),
                    remaining_attempts_prompt,
                    CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
                cui_pwd_guard_set_guard_extra_msg(cntx->ubchv_cui, remaining_attempts_prompt);
                mmi_mfree(remaining_attempts_prompt);

                mmi_secset_sim_display_popup(
                    cntx->sim,
                    cntx->type,
                    MMI_SECSET_STR_WRONG_UBCHV,
                    MMI_EVENT_FAILURE,
                    cntx->this_grp_id,
                    cntx);

                cui_pwd_guard_reset(cntx->ubchv_cui);
            }
        }
        else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED)
        {
            mmi_secset_ubchv_blocked_evt_struct blocked_evt;

            MMI_FRM_INIT_EVENT(&blocked_evt, EVT_ID_SECSET_UBCHV_BLOCKED);
            blocked_evt.instance = cntx;
            MMI_FRM_SEND_EVENT(&blocked_evt, cntx->proc, cntx->user_data);
        }
        else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_TEMP_FAIL)
        {
            mmi_popup_display_simple(
                get_string(STR_ID_SECSET_TEMP_FAIL),
                MMI_EVENT_FAILURE,
                cntx->this_grp_id,
                cntx);
        }
        else
        {
            mmi_secset_ubchv_sim_error_evt_struct sim_error_evt;

            MMI_FRM_INIT_EVENT(&sim_error_evt, EVT_ID_SECSET_UBCHV_SIM_ERROR);
            sim_error_evt.instance = cntx;
            MMI_FRM_SEND_EVENT(&sim_error_evt, cntx->proc, cntx->user_data);
        }
    }

    return MMI_RET_OK;
}


mmi_secset_ubchv_handle mmi_secset_ubchv_create(
    mmi_id grp_id,
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum type,
    mmi_proc_func proc,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ubchv_cntx *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1||
        type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2);

    cntx = (mmi_secset_ubchv_cntx*)mmi_malloc(sizeof(mmi_secset_ubchv_cntx));
    cntx->valid_magic = MMI_SECSET_UBCHV_VALID_MAGIC;
    cntx->parent_grp_id = grp_id;
    cntx->sim = sim;
    cntx->type = type;
    cntx->ubchv_cui = 0;
    cntx->proc = proc;
    cntx->user_data = user_data;

    cntx->this_grp_id = mmi_frm_group_create(
        grp_id,
        GRP_ID_AUTO_GEN,
        mmi_secset_ubchv_grp_proc,
        cntx);

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_UBCHV_CREATE, (U32)cntx, cntx->this_grp_id);

    return cntx;
}


void mmi_secset_ubchv_run(mmi_secset_ubchv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ubchv_cntx *cntx;
    WCHAR *remaining_attempts_prompt;
    WCHAR *old_chv_prompt, *new_chv_prompt, *confirm_chv_prompt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(handle != MMI_SECSET_UBCHV_INVALID_HANDLE);
    
    cntx = (mmi_secset_ubchv_cntx*)handle;

    MMI_ASSERT(cntx->valid_magic == MMI_SECSET_UBCHV_VALID_MAGIC);

    mmi_frm_group_enter(cntx->this_grp_id, MMI_FRM_NODE_NONE_FLAG);

    old_chv_prompt = (WCHAR*)mmi_malloc((MMI_SECSET_SIM_MAX_STR_LEN + 1) * 3 * sizeof(WCHAR));
    new_chv_prompt = old_chv_prompt + MMI_SECSET_SIM_MAX_STR_LEN + 1;
    confirm_chv_prompt = new_chv_prompt + MMI_SECSET_SIM_MAX_STR_LEN + 1;
    mmi_secset_sim_get_string(
        cntx->sim,
        cntx->type,
        MMI_SECSET_STR_INPUT_UBCHV,
        old_chv_prompt,
        MMI_SECSET_SIM_MAX_STR_LEN);
    mmi_secset_sim_get_string(
        cntx->sim,
        cntx->type,
        MMI_SECSET_STR_NEW_CHV,
        new_chv_prompt,
        MMI_SECSET_SIM_MAX_STR_LEN);
    mmi_secset_sim_get_string(
        cntx->sim,
        cntx->type,
        MMI_SECSET_STR_CONFIRM_CHV,
        confirm_chv_prompt,
        MMI_SECSET_SIM_MAX_STR_LEN);
    
    cntx->ubchv_cui = cui_pwd_guard_create_dynamic_str(
        cntx->this_grp_id,
        old_chv_prompt,
        new_chv_prompt,
        confirm_chv_prompt,
        MMI_SECSET_MIN_UBCHV_LEN,
        MMI_SECSET_MAX_UBCHV_LEN,
        MMI_SECSET_MIN_CHV_LEN,
        MMI_SECSET_MAX_CHV_LEN);

    if (cntx->type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
    {
        cui_pwd_guard_set_cancel_enabled(cntx->ubchv_cui, MMI_FALSE);
        cui_pwd_guard_set_auxiliary(
            cntx->ubchv_cui,
            CUI_PWD_AUXILIARY_GUARD_DEFAULT,
            MMI_TRUE,
            STR_ID_SECSET_SOFTKEY_EMERGENCY);
    }

    if (cntx->type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || cntx->type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
    {
        cui_pwd_guard_set_diff_input_prompt(cntx->ubchv_cui, STR_ID_SECSET_CHV1_NOT_MATCH);
    }
    else
    {
        cui_pwd_guard_set_diff_input_prompt(cntx->ubchv_cui, STR_ID_SECSET_CHV2_NOT_MATCH);
    }
    cui_pwd_guard_set_proc(cntx->ubchv_cui, mmi_secset_ubchv_input_proc, cntx);
    
    /* Set # of remaining attempts message */
    remaining_attempts_prompt = (WCHAR*)mmi_malloc(
        (CUI_PWD_MAX_EXTRA_MSG_STR_LEN + 30) * sizeof(WCHAR));
    mmi_secset_n_attempts_to_str(
        srv_sim_ctrl_get_n_remaining_attempts(cntx->sim, cntx->type),
        remaining_attempts_prompt,
        CUI_PWD_MAX_EXTRA_MSG_STR_LEN);
    cui_pwd_guard_set_guard_extra_msg(cntx->ubchv_cui, remaining_attempts_prompt);
    mmi_mfree(remaining_attempts_prompt);

    cui_pwd_guard_run(cntx->ubchv_cui);

    mmi_mfree(old_chv_prompt);
}


void mmi_secset_ubchv_close(mmi_secset_ubchv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ubchv_cntx *cntx;
    mmi_id ubchv_cui;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_ubchv_cntx*)handle;

    MMI_TRACE(MMI_SECSET_TRC_GROUP, TRC_MMI_SECSET_UBCHV_CLOSE, (U32)cntx);

    if (cntx == NULL ||
        cntx->valid_magic != MMI_SECSET_UBCHV_VALID_MAGIC ||
        !mmi_frm_group_is_present(cntx->this_grp_id))
    {
        return;
    }

    ubchv_cui = cntx->ubchv_cui;
    cntx->ubchv_cui = 0;
    cui_pwd_guard_close(ubchv_cui);

    mmi_frm_group_close(cntx->this_grp_id);
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
void mmi_secset_ubchv_update_prompt(mmi_secset_ubchv_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_secset_ubchv_cntx *cntx;
    WCHAR *ubchv_prompt, *new_chv_prompt, *confirm_chv_prompt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_secset_ubchv_cntx*)handle;

    if (cntx == NULL ||
        cntx->valid_magic != MMI_SECSET_UBCHV_VALID_MAGIC ||
        cntx->ubchv_cui == 0)
    {
        return;
    }

    ubchv_prompt = (WCHAR*)mmi_malloc((MMI_SECSET_SIM_MAX_STR_LEN + 1) * 3 * sizeof(WCHAR));
    new_chv_prompt = ubchv_prompt + MMI_SECSET_SIM_MAX_STR_LEN + 1;
    confirm_chv_prompt = new_chv_prompt + MMI_SECSET_SIM_MAX_STR_LEN + 1;
    mmi_secset_sim_get_string(
        cntx->sim,
        cntx->type,
        MMI_SECSET_STR_INPUT_UBCHV,
        ubchv_prompt,
        MMI_SECSET_SIM_MAX_STR_LEN);
    mmi_secset_sim_get_string(
        cntx->sim,
        cntx->type,
        MMI_SECSET_STR_NEW_CHV,
        new_chv_prompt,
        MMI_SECSET_SIM_MAX_STR_LEN);
    mmi_secset_sim_get_string(
        cntx->sim,
        cntx->type,
        MMI_SECSET_STR_CONFIRM_CHV,
        confirm_chv_prompt,
        MMI_SECSET_SIM_MAX_STR_LEN);

    cui_pwd_guard_set_prompt_strings(
        cntx->ubchv_cui,
        ubchv_prompt,
        new_chv_prompt,
        confirm_chv_prompt);

    mmi_mfree(ubchv_prompt);
}
#endif

#endif/*#if defined(__MMI_TELEPHONY_SUPPORT__)*/
