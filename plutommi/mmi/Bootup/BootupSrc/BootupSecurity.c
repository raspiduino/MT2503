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
 *  BootupSecurity.c
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "BootupAppGprot.h"
#include "BootupAppProt.h"
#include "SimCtrlSrvGprot.h"
#include "UCMGprot.h"
#include "UcmSrvGprot.h"
#include "custom_ecc.h"         /* ecc_custom_verify_emergency_number */
#include "ProcedureGprot.h"
#include "MMIDataType.h"
#include "BootupSrvGprot.h"
#include "kal_general_types.h"
#include "BootupScrUtil.h"
#include "mmi_rp_app_bootup_def.h"
#include "kal_public_api.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreensResDef.h"
#include "DebugInitDef_Int.h"
#include "BootupSrvIprot.h"
#include "custom_nvram_sec.h"
#include "custom_events_notify.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "GlobalConstants.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "ShutdownSrvGprot.h"
#include "SecSetSrvGprot.h"
#include "PwdCuiGprot.h"
#include "SmlMenuGprot.h"


#define MMI_BOOTUP_SEC_MAX_PWD_LEN 8

/*
 * For CTA spec 6.1.2.1
 * If this value is defined and user fails to try the phone password
 * for given number of times, shutdown directly.
 */
#define MMI_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS 3

#define MMI_BOOTUP_CUI_NULL 0

#define MMI_BOOTUP_SEC_MAX_SIM_STR_LEN 66


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_id grp_id;
    srv_bootup_verification_type_enum veri_type;
    S32 n_remaining_attempts;
    MMI_BOOL is_displaying_sim_screen;
    mmi_sim_enum sim_displaying;
    mmi_id password_screen;
    mmi_id ubchv1_screen;

    mmi_proc_func proc;
    void *user_data;
} mmi_bootup_security_cntx_struct;

typedef struct
{
    srv_bootup_verification_type_enum type;
    S8 min;
    S8 max;
} mmi_bootup_pwd_length_struct;


typedef struct
{
    srv_sim_ctrl_ua_cause_enum cause;
    U16 sim_error_str;
} mmi_bootup_sim_error_string_struct;

typedef void (*mmi_bootup_sec_continue_func)(mmi_bootup_security_cntx_struct *cntx);


/****************************************************************************
 * Configurations
 ****************************************************************************/
 
/* If user selects make emergency call, the default number to make call */
#define MMI_BOOTUP_SEC_DEFAULT_EMERGENCY_CALL_NUM   L"112"

/* Initial timeout of the retrial of personalization lock */
#define MMI_BOOTUP_WRONG_PERSON_PWD_INIT_TIMEOUT_SEC 30 /* sec */

/* Minimum length & maximum length of passwords */
static const mmi_bootup_pwd_length_struct g_mmi_bootup_sec_pwd_length[] =
{
    { SRV_BOOTUP_VERI_PHONE_LOCK, SRV_SECSET_MIN_PHONE_PASSWORD_LEN, SRV_SECSET_MAX_PHONE_PASSWORD_LEN },
    { SRV_BOOTUP_VERI_CHV1,     SRV_SIM_CTRL_MIN_CHV_LEN, SRV_SIM_CTRL_MAX_CHV_LEN },
    { SRV_BOOTUP_VERI_UBCHV1,   SRV_SIM_CTRL_MIN_UBCHV_LEN, SRV_SIM_CTRL_MAX_UBCHV_LEN },
#ifdef __SIM_ME_LOCK__
    { SRV_BOOTUP_VERI_NP,       8, 16 },
    { SRV_BOOTUP_VERI_NSP,      8, 16 },
    { SRV_BOOTUP_VERI_SP,       8, 16 },
    { SRV_BOOTUP_VERI_CP,       8, 16 },
    { SRV_BOOTUP_VERI_SIMP,     6, 16 }, /* Min length of PCK should be 6 digits by TS 22.022 */
    { SRV_BOOTUP_VERI_NSSP,     8, 16 },
    { SRV_BOOTUP_VERI_SIMCP,    8, 16 },
#endif /* #ifdef __SIM_ME_LOCK__ */
    /* ------------------------------------------------------------------------------ */
    { SRV_BOOTUP_VERI_END_OF_ENUM, 0, 0 }
};


/* If SIM error detected, the string we want to prompt user */
#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
static const mmi_bootup_sim_error_string_struct g_mmi_bootup_sec_sim_errors_single[] =
{
#ifdef __SIM_RECOVERY_ENHANCEMENT__
    { SRV_SIM_CTRL_UA_CAUSE_RECOVERY, STR_ID_BOOTUP_SIM_CAME_OFF },
#endif /* __SIM_RECOVERY_ENHANCEMENT__ */
#ifdef  __SIM_HOT_SWAP_SUPPORT__
    { SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED, STR_ID_BOOTUP_SIM_REMOVED },
#else
    { SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED, STR_ID_BOOTUP_SIM_CAME_OFF },
#endif
    { SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR, STR_ID_BOOTUP_SIM_ACCESS_ERROR },
    { SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED, STR_ID_BOOTUP_SIM_CHV1_BLOCKED },
    { SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED, STR_ID_BOOTUP_SIM_BLOCKED },
    { SRV_SIM_CTRL_UA_CAUSE_PERSON_BLOCKED, STR_ID_BOOTUP_SIM_BLOCKED },
    /* --------------------------------------------------------------------- */
    { SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM, 0 }
};
#endif /* (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)*/


#if (MMI_MAX_SIM_NUM >= 2)
static const mmi_bootup_sim_error_string_struct g_mmi_bootup_sec_sim_errors_multiple[] =
{
#ifdef __SIM_RECOVERY_ENHANCEMENT__
    { SRV_SIM_CTRL_UA_CAUSE_RECOVERY, STR_ID_BOOTUP_SIMX_CAME_OFF },
#endif /* __SIM_RECOVERY_ENHANCEMENT__ */
#ifdef  __SIM_HOT_SWAP_SUPPORT__
    { SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED, STR_ID_BOOTUP_SIMX_REMOVED },
#else /* __SIM_HOT_SWAP_SUPPORT__ */
    { SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED, STR_ID_BOOTUP_SIMX_CAME_OFF },
#endif /* __SIM_HOT_SWAP_SUPPORT__ */
    { SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR, STR_ID_BOOTUP_SIMX_ACCESS_ERROR },
    { SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED, STR_ID_BOOTUP_SIMX_CHV1_BLOCKED},
    { SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED, STR_ID_BOOTUP_SIMX_BLOCKED },
    { SRV_SIM_CTRL_UA_CAUSE_PERSON_BLOCKED, STR_ID_BOOTUP_SIMX_BLOCKED },
    /* ----------------------------------------- */
    { SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM, 0 }
};
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/****************************************************************************
 * Global variables
 ****************************************************************************/

static mmi_bootup_security_cntx_struct g_mmi_bootup_security_cntx =
{
    GRP_ID_INVALID /* Not occupied by any group */
};


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_bootup_sec_continue_verification(
                mmi_bootup_security_cntx_struct *cntx);

static mmi_ret mmi_bootup_sec_key_proc(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_n_attempts_to_str
 * DESCRIPTION
 *  Convert the number of remaining attempts to string representation.
 * PARAMETERS
 *  out_str_buffer          [OUT] Output string representation. Caller should
 *                                prepare enough space for the buffer.
 *  n_remaining_attempts    [IN]  The number to be converted.
 * RETURNS
 *  Pointer of out_str_buffer
 *****************************************************************************/
static WCHAR *mmi_bootup_sec_n_attempts_to_str(
                WCHAR *out_str_buffer,
                S32 max_str_len,
                S32 n_remaining_attempts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_str_buffer[0] = L'\0';
    
    if (n_remaining_attempts == SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER)
    {
        out_str_buffer[0] = L'\0';
    }
    else
    {
        mmi_wsprintf(
            out_str_buffer,
            (max_str_len + 1) * sizeof(WCHAR),
            STR_ID_BOOTUP_REMAINING_TRIALS_PROMPT,
            n_remaining_attempts);
    }

    return out_str_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_get_length_restriction
 * DESCRIPTION
 *  Get the length restriction of the password.
 * PARAMETERS
 *  type        [IN]  Password type
 *  min_length  [OUT] Minimum length
 *  max_length  [OUT] Maximum length
 * RETURNS
 *  Length configuration is found or not. If not found, the length outputs
 *  will be given default values.
 *****************************************************************************/
static MMI_BOOL mmi_bootup_sec_get_length_restriction(
                    srv_bootup_verification_type_enum type,
                    S16 *min_length,
                    S16 *max_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_bootup_pwd_length_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (entry = g_mmi_bootup_sec_pwd_length;
         entry->type != SRV_BOOTUP_VERI_END_OF_ENUM;
         entry++)
    {
        if (entry->type == type)
        {
            *min_length = entry->min;
            *max_length = entry->max;
            
            return MMI_TRUE;
        }
    }

    *min_length = 4;
    *max_length = MMI_BOOTUP_SEC_MAX_PWD_LEN;

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_execute_ssc_or_make_ecc
 * DESCRIPTION
 *  Execute SSC handler or make emergency call by given number
 * PARAMETERS
 *  number      [IN] Number
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_execute_ssc_or_make_ecc(const WCHAR *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U16 number_to_call[SRV_UCM_MAX_NUM_URI_LEN + 1];
    mmi_ucm_make_call_para_struct make_call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (ecc_custom_verify_emergency_number(
            (kal_uint8*)number,
            mmi_wcslen(number),
            ECC_ENCODING_UCS2,
            ECC_ALL_CALL,
            NULL,
            NULL,
            NULL))
    {
        //mmi_ucm_app_make_call(SRV_UCM_VOICE_CALL_TYPE_ALL, (U8*)number);

		mmi_ucs2cpy((CHAR*)number_to_call, (const CHAR *)number);
	    mmi_ucm_init_call_para(&make_call_para);

	    make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
	    make_call_para.ucs2_num_uri = number_to_call;
        mmi_ucm_call_launch(0, &make_call_para);
    }
    else
    {
        mmi_popup_display_simple(
            get_string(srv_ucm_query_error_message(SRV_UCM_RESULT_SOS_NUMBER_ONLY)),
            MMI_EVENT_FAILURE,
            g_mmi_bootup_security_cntx.grp_id,
            &g_mmi_bootup_security_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_make_emergency_call
 * DESCRIPTION
 *  Make emergency call and clean the input of active password screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_make_emergency_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct makecall_para;
    mmi_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_security_cntx);

    mmi_ucm_init_call_para(&makecall_para);
    makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
    makecall_para.ucs2_num_uri = (U16*)MMI_BOOTUP_SEC_DEFAULT_EMERGENCY_CALL_NUM;
    mmi_ucm_call_launch(0, &makecall_para);  

    if (cntx->password_screen != MMI_BOOTUP_CUI_NULL)
    {
        /* Don't assert here, because it is emergency call! */
        cui_pwd_basic_clear_input(cntx->password_screen);
    }
    else if (cntx->ubchv1_screen != MMI_BOOTUP_CUI_NULL)
    {
        cui_pwd_guard_clear_input_of_active(cntx->ubchv1_screen);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_ec_confirm_proc
 * DESCRIPTION
 *  Event proc of emergency call confirm
 * PARAMETERS
 *  evt     [IN] mmi_alert_result_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_ec_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        mmi_alert_result_evt_struct *result_evt;

        result_evt = (mmi_alert_result_evt_struct*)evt;
        if (result_evt->result == MMI_ALERT_CNFM_YES)
        {
            mmi_bootup_sec_make_emergency_call();
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_confirm_emergency_call
 * DESCRIPTION
 *  Show a confirm dialog for emergency call.
 * PARAMETERS
 *  user_data       [IN] mmi_bootup_security_cntx_struct*
 *  handle          [IN] Password screen handle
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_confirm_emergency_call(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->user_data != NULL);
    cntx = (mmi_bootup_security_cntx_struct*)evt->user_data;

    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
    confirm_arg.parent_id = cntx->grp_id;
    confirm_arg.callback = mmi_bootup_sec_ec_confirm_proc;
    confirm_arg.user_tag = cntx;
    confirm_arg.f_auto_dismiss = 1;
    mmi_confirm_display(
        get_string(STR_ID_BOOTUP_EMERGENCY_CALL_ASK),
        MMI_EVENT_QUERY,
        &confirm_arg);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_popup_callback
 * DESCRIPTION
 *  Callback of popup.
 *  Continue execution after the popop.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_popup_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *popup_evt;
    mmi_bootup_sec_continue_func continue_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_POPUP_QUIT)
    {
        popup_evt = (mmi_alert_result_evt_struct*)evt;
        continue_func = (mmi_bootup_sec_continue_func)(popup_evt->user_tag);
        MMI_ASSERT(continue_func != NULL);
        continue_func(&(g_mmi_bootup_security_cntx));
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_popup_and_continue
 * DESCRIPTION
 *  Popup an message then continue to execute continue_func().
 * PARAMETERS
 *  message         [IN] Message
 *  popup_type      [IN] Popup type
 *  continue_func   [IN] The function to be triggered after the popup
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_popup_and_continue(
                mmi_bootup_security_cntx_struct *cntx,
                const WCHAR* message,
                mmi_event_notify_enum popup_type,
                mmi_bootup_sec_continue_func continue_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(continue_func != NULL);

    cntx->veri_type = SRV_BOOTUP_VERI_NONE;
    cntx->n_remaining_attempts = 0;
    /* Set to false to avoid another popup on SIM fatal error event */
    cntx->is_displaying_sim_screen = MMI_FALSE;
    cntx->sim_displaying = MMI_SIM_NONE;

    mmi_popup_property_init(&property);
    property.callback = mmi_bootup_sec_popup_callback;
    property.parent_id = cntx->grp_id;
    property.user_tag = (void*)continue_func;
    
    if (mmi_popup_display(
            (WCHAR*)message,
            popup_type,
            &property) != GRP_ID_INVALID)
    {
        /* Do nothing, continue after callback */
    }
    else
    {
        continue_func(cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_popup_sim_error_and_continue
 * DESCRIPTION
 *  Get the unavailable cause of the SIM, popup proper string and continue
 *  to execute continue_func()
 * PARAMETERS
 *  cntx            [IN] Context
 *  sim             [IN] For which SIM
 *  continue_func   [IN] The function to be triggered after the popup
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_popup_sim_error_and_continue(
                mmi_bootup_security_cntx_struct *cntx,
                mmi_sim_enum sim,
                mmi_bootup_sec_continue_func continue_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_ua_cause_enum cause;
    U16 error_str_id;
    WCHAR error_str[MMI_BOOTUP_SEC_MAX_SIM_STR_LEN + 1];
    const mmi_bootup_sim_error_string_struct *str_entry = NULL;
    mmi_event_notify_enum popup_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_str_id = STR_GLOBAL_ERROR;

    cause = srv_sim_ctrl_get_unavailable_cause(sim);
    popup_type = MMI_EVENT_FAILURE;

#if (MMI_MAX_SIM_NUM == 1)
    str_entry = g_mmi_bootup_sec_sim_errors_single;
#else /* (MMI_MAX_SIM_NUM == 1) */
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    if (srv_sim_ctrl_get_num_of_inserted() <= 1)
    {
        str_entry = g_mmi_bootup_sec_sim_errors_single;
    }
    else
#endif
    {
        str_entry = g_mmi_bootup_sec_sim_errors_multiple;
    }
#endif /* (MMI_MAX_SIM_NUM == 1) */

    for ( ;
         str_entry->cause != SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM;
         str_entry++)
    {
        if (str_entry->cause == cause)
        {
            error_str_id = str_entry->sim_error_str;
            break;
        }
    }

#if (MMI_MAX_SIM_NUM == 1)

    mmi_wcsncpy(error_str, get_string(error_str_id), MMI_BOOTUP_SEC_MAX_SIM_STR_LEN);
    
#else /* (MMI_MAX_SIM_NUM == 1) */
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    if (srv_sim_ctrl_get_num_of_inserted() <= 1)
    {
        mmi_wcsncpy(error_str, get_string(error_str_id), MMI_BOOTUP_SEC_MAX_SIM_STR_LEN);
    }
    else
#endif
    {
        mmi_sim_ctrl_gen_str(
            error_str,
            MMI_BOOTUP_SEC_MAX_SIM_STR_LEN,
            error_str_id,
            sim);
    }
#endif /* (MMI_MAX_SIM_NUM == 1) */

#ifdef __SIM_HOT_SWAP_SUPPORT__
    if (cause == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
    {
        popup_type = MMI_EVENT_INFO;
    }
#endif

    mmi_bootup_sec_popup_and_continue(
        cntx,
        error_str,
        popup_type,
        continue_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_close_password_screen_and_continue
 * DESCRIPTION
 *  Close password screen and continue next verification.
 * PARAMETERS
 *  cntx            [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_close_password_screen_and_continue(
                mmi_bootup_security_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_pwd_basic_close(cntx->password_screen);
    cntx->password_screen = MMI_BOOTUP_CUI_NULL;
    
    mmi_bootup_sec_continue_verification(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_close_password_screen_and_continue
 * DESCRIPTION
 *  Close UBCHV1 screen and continue next verification.
 * PARAMETERS
 *  cntx            [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_close_ubchv1_screen_and_continue(
                mmi_bootup_security_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_pwd_guard_close(cntx->ubchv1_screen);
    cntx->ubchv1_screen = MMI_BOOTUP_CUI_NULL;
    
    mmi_bootup_sec_continue_verification(cntx);
}


#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__ /* wrapped under __MMI_SML_MENU__, which is dependent upon __SIM_ME_LOCK__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_is_personalization_type
 * DESCRIPTION
 *  Query whether the type is personalization lock.
 * PARAMETERS
 *  type    [IN] Verification type
 * RETURNS
 *  MMI_TRUE for personalization type
 *****************************************************************************/
static MMI_BOOL mmi_bootup_sec_is_personalization_type(
                    srv_bootup_verification_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_BOOTUP_VERI_NP:
        case SRV_BOOTUP_VERI_NSP:
        case SRV_BOOTUP_VERI_SP:
        case SRV_BOOTUP_VERI_CP:
        case SRV_BOOTUP_VERI_SIMP:
        case SRV_BOOTUP_VERI_NSSP:
        case SRV_BOOTUP_VERI_SIMCP:
            return MMI_TRUE;

        default:
            break;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_per_on_waiting_close
 * DESCRIPTION
 *  To control the close of personalization waiting screen.
 *  Allow to close only if timeout.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_BOOTUP_SCR_ALLOW_TO_CLOSE only if timeout.
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_per_on_waiting_close(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_MMI_BOOTUP_SCR_TIMEOUT)
    {
        return MMI_BOOTUP_SCR_ALLOW_TO_CLOSE;
    }

    return MMI_BOOTUP_SCR_DONT_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_per_show_waiting
 * DESCRIPTION
 *  Show count-down waiting for wrong personalization password input after
 *  popup quited.
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_per_show_waiting(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;
    mmi_alert_result_evt_struct *popup_evt;
    S32 n_remaining_attempts;
    S32 n_already_trials;
    S32 duration_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id != EVT_ID_POPUP_QUIT)
    {
        return MMI_RET_OK; /* Ignore, we only wait for QUIT event */
    }

    popup_evt = (mmi_alert_result_evt_struct*)evt;
    cntx = (mmi_bootup_security_cntx_struct*)popup_evt->user_tag;

    srv_bootup_get_verification_info(cntx->sim_displaying, &n_remaining_attempts);

    n_already_trials = SRV_BOOTUP_MAX_PERSONALIZATION_TRIAL_NUM - 1 - n_remaining_attempts;
    duration_sec = (1 << n_already_trials) * MMI_BOOTUP_WRONG_PERSON_PWD_INIT_TIMEOUT_SEC;
    
	#if 0
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

    return MMI_RET_OK;
}
#endif /* __MMI_SML_UNLOCK_RETRY_TIMER__ */


#ifdef MMI_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_shutdown_after_popup
 * DESCRIPTION
 *  Launch shutdown after popup exits.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_shutdown_after_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_POPUP_QUIT)
    {
        srv_shutdown_normal_start(APP_BOOTUP);
    }

    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_verify_result
 * DESCRIPTION
 *  Result callback for verfication of phone lock, CHV1 and personalizeion.
 * PARAMETERS
 *  user_data   [IN] mmi_bootup_security_cntx_struct*
 *  result      [IN] Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_verify_result(
                void *user_data,
                const srv_bootup_verify_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(user_data != NULL);
    cntx = (mmi_bootup_security_cntx_struct*)user_data;
    
    if (result->success)
    {
        mmi_bootup_sec_popup_and_continue(
            cntx,
            get_string(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS,
            mmi_bootup_close_password_screen_and_continue);
    }
    else if (!result->fatal_error && result->n_remaining_attempts > 0)
    {
        WCHAR *str_buffer;

#ifdef MMI_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS
        if (result->type == SRV_BOOTUP_VERI_PHONE_LOCK)
        {
            cntx->n_remaining_attempts--;
            if (cntx->n_remaining_attempts == 0)
            {
                /* Popup then shutdown */
                mmi_popup_property_struct property;

                mmi_popup_property_init(&property);
                property.callback = mmi_bootup_sec_shutdown_after_popup;
                property.parent_id = cntx->grp_id;
                property.user_tag = cntx;
                mmi_popup_display(
                    get_string(STR_ID_BOOTUP_WRONG_PHONE_PASSWORD),
                    MMI_EVENT_FAILURE,
                    &property);

                return;
            }
        }
        else
        {
            cntx->n_remaining_attempts = result->n_remaining_attempts;
        }
#else
        cntx->n_remaining_attempts = result->n_remaining_attempts;
#endif

        str_buffer = (WCHAR*)mmi_malloc(
            (MMI_BOOTUP_SEC_MAX_SIM_STR_LEN + 1) * sizeof(WCHAR));

#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
        if (mmi_bootup_sec_is_personalization_type(result->type))
        {
            mmi_popup_property_struct property;
            
            mmi_popup_property_init(&property);
            property.callback = mmi_bootup_sec_per_show_waiting;
            property.parent_id = cntx->grp_id;
            property.user_tag = cntx;
            mmi_popup_display(
                mmi_bootup_sec_get_message_of_result(result, str_buffer, MMI_BOOTUP_SEC_MAX_SIM_STR_LEN),
                MMI_EVENT_FAILURE,
                &property);
        }
        else
#endif
        {
            mmi_popup_display_simple(
                mmi_bootup_sec_get_message_of_result(result, str_buffer, MMI_BOOTUP_SEC_MAX_SIM_STR_LEN),
                MMI_EVENT_FAILURE,
                cntx->grp_id,
                cntx);
        }

        /* Update the prompt of the number of remaining attempts */
        mmi_bootup_sec_n_attempts_to_str(
            str_buffer,
            MMI_BOOTUP_SEC_MAX_SIM_STR_LEN,
            cntx->n_remaining_attempts);
        cui_pwd_basic_set_extra_msg(
            cntx->password_screen,
            str_buffer);
        mmi_mfree(str_buffer);
        
        cui_pwd_basic_clear_input(cntx->password_screen);
    }
    else if (result->type == SRV_BOOTUP_VERI_PHONE_LOCK)
    {
        /* We can try phone lock infinitely */
        MMI_ASSERT(MMI_FALSE);
    }
    else /* Error on SIM or entered other state(e.g. CHV1 -> UBCHV1) */
    {
        mmi_bootup_popup_sim_error_and_continue(
            cntx,
            result->sim,
            mmi_bootup_close_password_screen_and_continue);
    }

    mmi_bootup_waiting_screen_close(cntx->grp_id);
}


static mmi_ret mmi_bootup_sec_verify_phone_lock_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->user_data != NULL);
    cntx = (mmi_bootup_security_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            cui_pwd_basic_done_evt_struct *done_evt;

            done_evt = (cui_pwd_basic_done_evt_struct*)evt;
            mmi_bootup_waiting_screen_show(
                cntx->grp_id,
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                STR_GLOBAL_PLEASE_WAIT);

            srv_bootup_verify(
				MMI_SIM1,
                done_evt->input,
                NULL,
                mmi_bootup_sec_verify_result,
                cntx);

            break;
        }
        case EVT_ID_CUI_PWD_BASIC_KEY:
            return mmi_bootup_sec_key_proc(evt);

        case EVT_ID_CUI_PWD_BASIC_AUX:
            return mmi_bootup_sec_confirm_emergency_call(evt);
            
        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
            return CUI_PWD_DONT_CLOSE;
    }

    return MMI_RET_OK;
}


#ifdef __CANCEL_LOCK_POWERON__
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_cancel_veri_result_callback
 * DESCRIPTION
 *  Result callback of cancelling verification of the SIM.
 * PARAMETERS
 *  user_data   [IN] mmi_bootup_security_cntx_struct*
 *  result      [IN] Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_cancel_veri_result_callback(
                void *user_data,
                const srv_bootup_cancel_verification_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(user_data != NULL);
    cntx = (mmi_bootup_security_cntx_struct*)user_data;

    if (result->success)
    {
        /*
         * We don't need to input the password if the verification
         * is cancelled successfully.
         */
        if (cntx->password_screen != MMI_BOOTUP_CUI_NULL)
        {
            mmi_bootup_close_password_screen_and_continue(cntx);
        }
        else if (cntx->ubchv1_screen != MMI_BOOTUP_CUI_NULL)
        {
            mmi_bootup_close_ubchv1_screen_and_continue(cntx);
        }
    }
    else
    {
        // TODO: Display a more suitable prompt, e.g. "Please input password"
        mmi_popup_display_simple(
            get_string(STR_GLOBAL_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            cntx->grp_id,
            cntx);
    }

    mmi_bootup_waiting_screen_close(cntx->grp_id);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_verify_chv1_or_per_proc
 * DESCRIPTION
 *  Verify phone lock.
 * PARAMETERS
 *  user_data   [IN] mmi_bootup_security_cntx_struct*
 *  input       [IN] Input information of the password screen
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_verify_chv1_or_per_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->user_data != NULL);
    cntx = (mmi_bootup_security_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_BASIC_DONE:
        {
            cui_pwd_basic_done_evt_struct *done_evt;

            done_evt = (cui_pwd_basic_done_evt_struct*)evt;
        
            mmi_bootup_waiting_screen_show(
                cntx->grp_id,
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                STR_GLOBAL_PLEASE_WAIT);

            srv_bootup_verify(
                cntx->sim_displaying,
                done_evt->input,
                NULL,
                mmi_bootup_sec_verify_result,
                cntx);
                
            break;
        }
        case EVT_ID_CUI_PWD_BASIC_KEY:
            return mmi_bootup_sec_key_proc(evt);

        case EVT_ID_CUI_PWD_BASIC_AUX:
            return mmi_bootup_sec_confirm_emergency_call(evt);
            
        case EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING:
            return CUI_PWD_DONT_CLOSE;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_key_proc
 * DESCRIPTION
 *  Key proc to detect keys on password screen.
 *  Execute SSC or make call for Send key.
 *  Cancel verification for End key if possible.
 * PARAMETERS
 *  evt     [IN] cui_pwd_general_key_evt_struct*
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;
    cui_pwd_general_key_evt_struct *key_evt;
    const WCHAR *input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    key_evt = (cui_pwd_general_key_evt_struct*)evt;
    cntx = (mmi_bootup_security_cntx_struct*)evt->user_data;

    if (key_evt->key_type != KEY_EVENT_DOWN)
    {
        return MMI_RET_OK;
    }

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_SEC_KEY_ON_PASSWORD,
        key_evt->key_code, key_evt->key_type);

    switch (key_evt->key_code)
    {
        case KEY_SEND:
        case KEY_SEND1:
        case KEY_SEND2:
            input = NULL;
            
            if (key_evt->sender_id == cntx->password_screen)
            {
                input = cui_pwd_basic_get_input(cntx->password_screen);
            }
            else if (key_evt->sender_id == cntx->ubchv1_screen)
            {
                input = cui_pwd_guard_get_input_of_active(cntx->ubchv1_screen);
            }
            
            if (input != NULL && input[0] != L'\0')
            {
                mmi_bootup_sec_execute_ssc_or_make_ecc(input);
            }
            
            if (key_evt->sender_id == cntx->password_screen)
            {
                cui_pwd_basic_clear_input(cntx->password_screen);
                return MMI_RET_KEY_HANDLED;
            }
            else if (key_evt->sender_id == cntx->ubchv1_screen)
            {
                cui_pwd_guard_clear_input_of_active(cntx->ubchv1_screen);
                return MMI_RET_KEY_HANDLED;
            }
            
            break;

#ifdef __CANCEL_LOCK_POWERON__
        case KEY_END:
            if (cntx->is_displaying_sim_screen &&
                srv_bootup_veri_can_be_cancelled(cntx->sim_displaying))
            {
                mmi_bootup_waiting_screen_show(
                    cntx->grp_id,
                    mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                    STR_GLOBAL_PLEASE_WAIT);
                
                srv_bootup_cancel_verification(
                    cntx->sim_displaying,
                    mmi_bootup_sec_cancel_veri_result_callback,
                    cntx);

                return MMI_RET_KEY_HANDLED;
            }
            break;
#endif

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_show_sim_password
 * DESCRIPTION
 *  Show password screen for the SIM.
 * PARAMETERS
 *  cntx                    [IN] Context
 *  sim                     [IN] Which SIM
 *  veri_type               [IN] Password type
 *  n_remaining_attempts    [IN] Number of remaining attempts
 *  str_buffer              [IN] Buffer for temporary strings
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_show_sim_password(
                mmi_bootup_security_cntx_struct *cntx,
                mmi_sim_enum sim,
                srv_bootup_verification_type_enum veri_type,
                S32 n_remaining_attempts,
                WCHAR *str_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR input_prompt[MMI_BOOTUP_SEC_MAX_SIM_STR_LEN + 1];
    S16 min_pwd_length;
    S16 max_pwd_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bootup_sec_get_input_prompt(
        sim,
        veri_type,
        input_prompt,
        sizeof(input_prompt) / sizeof(input_prompt[0]) - 1);
    
    mmi_bootup_sec_n_attempts_to_str(
        str_buffer,
        MMI_BOOTUP_SEC_MAX_SIM_STR_LEN,
        n_remaining_attempts);

    mmi_bootup_sec_get_length_restriction(
        veri_type,
        &min_pwd_length,
        &max_pwd_length);

    cntx->password_screen = cui_pwd_basic_create_dynamic_str(
        cntx->grp_id,
        input_prompt,
        min_pwd_length,
        max_pwd_length);
    cui_pwd_basic_set_extra_msg(cntx->password_screen, str_buffer);
    cui_pwd_basic_set_action_str(cntx->password_screen, STR_GLOBAL_OK, 0);
    cui_pwd_basic_set_auxiliary(
        cntx->password_screen,
        CUI_PWD_AUXILIARY_BASIC_DEFAULT,
        MMI_TRUE,
        STR_ID_BOOTUP_SOFTKEY_EMERGENCY);
    cui_pwd_basic_set_proc(cntx->password_screen, mmi_bootup_sec_verify_chv1_or_per_proc, cntx);

    cui_pwd_basic_run(cntx->password_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_verify_ubchv1_result
 * DESCRIPTION
 *  Result of verifying UBCHV1.
 * PARAMETERS
 *  user_data   [IN] mmi_bootup_security_cntx_struct
 *  result      [IN] Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_verify_ubchv1_result(
                void *user_data,
                const srv_bootup_verify_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(user_data != NULL);
    cntx = (mmi_bootup_security_cntx_struct*)user_data;
    
    if (result->success)
    {
        mmi_bootup_sec_popup_and_continue(
            cntx,
            get_string(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS,
            mmi_bootup_close_ubchv1_screen_and_continue);
    }
    else if (!result->fatal_error)
    {
        WCHAR *str_buffer;

        cntx->n_remaining_attempts = result->n_remaining_attempts;

        str_buffer = (WCHAR*)mmi_malloc(
            (MMI_BOOTUP_SEC_MAX_SIM_STR_LEN + 20) * sizeof(WCHAR));

        mmi_popup_display_simple(
            mmi_bootup_sec_get_message_of_result(result, str_buffer, MMI_BOOTUP_SEC_MAX_SIM_STR_LEN),
            MMI_EVENT_FAILURE,
            cntx->grp_id,
            cntx);

        /* Update the prompt of the number of remaining attempts */
        mmi_bootup_sec_n_attempts_to_str(
            str_buffer,
            MMI_BOOTUP_SEC_MAX_SIM_STR_LEN,
            result->n_remaining_attempts);;
        cui_pwd_guard_set_guard_extra_msg(
            cntx->ubchv1_screen,
            str_buffer);
        mmi_mfree(str_buffer);
            
        cui_pwd_guard_reset(cntx->ubchv1_screen);
    }
    else /* Unrecoverable error on SIM */
    {
        mmi_bootup_popup_sim_error_and_continue(
            cntx,
            result->sim,
            mmi_bootup_close_ubchv1_screen_and_continue);
    }

    mmi_bootup_waiting_screen_close(cntx->grp_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_verify_ubchv1
 * DESCRIPTION
 *  Verify UBCHV1.
 * PARAMETERS
 *  user_data   [IN] mmi_bootup_security_cntx_struct
 *  input       [IN] Input information from the change password screen
 *                   sequence.
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_bootup_sec_verify_ubchv1_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->user_data != NULL);
    cntx = (mmi_bootup_security_cntx_struct*)evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PWD_GUARD_DONE:
        {
            cui_pwd_guard_done_evt_struct *done_evt;

            done_evt = (cui_pwd_guard_done_evt_struct*)evt;
        
            mmi_bootup_waiting_screen_show(
                cntx->grp_id,
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                STR_GLOBAL_PLEASE_WAIT);

            srv_bootup_verify(
                cntx->sim_displaying,
                done_evt->guard,
                done_evt->input,
                mmi_bootup_sec_verify_ubchv1_result,
                cntx);
                
            break;
        }
        case EVT_ID_CUI_PWD_GUARD_KEY:
            return mmi_bootup_sec_key_proc(evt);

        case EVT_ID_CUI_PWD_GUARD_AUX:
            return mmi_bootup_sec_confirm_emergency_call(evt);
            
        case EVT_ID_CUI_PWD_GUARD_PASSIVE_CLOSING:
            return CUI_PWD_DONT_CLOSE;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_show_sim_ubchv1
 * DESCRIPTION
 *  Show screen sequence for UBCHV1.
 * PARAMETERS
 *  cntx                    [IN] Context
 *  sim                     [IN] Which SIM
 *  n_remaining_attempts    [IN] Number of remaining attempts of UBCHV1
 *  str_buffer              [IN] Buffer for temporary strings
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_show_sim_ubchv1(
                mmi_bootup_security_cntx_struct *cntx,
                mmi_sim_enum sim,
                S32 n_remaining_attempts,
                WCHAR *str_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *guard_input_prompt_str;
    WCHAR *new_pwd_prompt_str;
    S16 guard_min_pwd_len, guard_max_pwd_len;
    S16 new_pwd_min_pwd_len, new_pwd_max_pwd_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guard_input_prompt_str = mmi_malloc((MMI_BOOTUP_SEC_MAX_SIM_STR_LEN + 1) * 2 * sizeof(WCHAR));
    new_pwd_prompt_str = guard_input_prompt_str + MMI_BOOTUP_SEC_MAX_SIM_STR_LEN + 1;
    
    mmi_bootup_sec_get_input_prompt(
        sim,
        SRV_BOOTUP_VERI_UBCHV1,
        guard_input_prompt_str,
        MMI_BOOTUP_SEC_MAX_SIM_STR_LEN - 1);

#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sim_ctrl_gen_str(
        new_pwd_prompt_str,
        MMI_BOOTUP_SEC_MAX_SIM_STR_LEN,
        STR_ID_BOOTUP_SIMX_NEW_CHV1,
        sim);
#else
    mmi_wcsncpy(new_pwd_prompt_str, get_string(STR_ID_BOOTUP_NEW_CHV1), MMI_BOOTUP_SEC_MAX_SIM_STR_LEN);
#endif

    mmi_bootup_sec_get_length_restriction(
        SRV_BOOTUP_VERI_UBCHV1,
        &(guard_min_pwd_len),
        &(guard_max_pwd_len));
    mmi_bootup_sec_get_length_restriction(
        SRV_BOOTUP_VERI_CHV1,
        &(new_pwd_min_pwd_len),
        &(new_pwd_max_pwd_len));
    mmi_bootup_sec_n_attempts_to_str(
        str_buffer,
        MMI_BOOTUP_SEC_MAX_SIM_STR_LEN,
        n_remaining_attempts);

    cntx->ubchv1_screen = cui_pwd_guard_create_dynamic_str(
        cntx->grp_id,
        guard_input_prompt_str,
        new_pwd_prompt_str,
        get_string(STR_ID_BOOTUP_CONFIRM_NEW_CHV1),
        guard_min_pwd_len,
        guard_max_pwd_len,
        new_pwd_min_pwd_len,
        new_pwd_max_pwd_len);
    cui_pwd_guard_set_guard_extra_msg(cntx->ubchv1_screen, str_buffer);
    cui_pwd_guard_set_action_str(cntx->ubchv1_screen, STR_GLOBAL_OK, 0);
    cui_pwd_guard_set_auxiliary(
        cntx->ubchv1_screen,
        CUI_PWD_AUXILIARY_GUARD_DEFAULT,
        MMI_TRUE,
        STR_ID_BOOTUP_SOFTKEY_EMERGENCY);
    cui_pwd_guard_set_diff_input_prompt(cntx->ubchv1_screen, STR_ID_BOOTUP_CHV1_NOT_MATCH);
    cui_pwd_guard_set_proc(cntx->ubchv1_screen, mmi_bootup_sec_verify_ubchv1_proc, cntx);

    cui_pwd_guard_run(cntx->ubchv1_screen);

    mmi_mfree(guard_input_prompt_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_do_verification_of_sim
 * DESCRIPTION
 *  Do verification of SIM.
 * PARAMETERS
 *  cntx            [IN] Context
 *  sim             [IN] Which SIM
 *  str_buffer      [IN] Buffer for temporary strings
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_do_verification_of_phone(
                mmi_bootup_security_cntx_struct *cntx,
                WCHAR *str_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 min_pwd_len, max_pwd_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_PHONE_VERIFICATION);

    cntx->veri_type = SRV_BOOTUP_VERI_PHONE_LOCK;
#ifdef MMI_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS
    cntx->n_remaining_attempts = MMI_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS;
#else
    cntx->n_remaining_attempts = SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER;
#endif
    cntx->is_displaying_sim_screen = MMI_FALSE;
    cntx->sim_displaying = MMI_SIM_NONE;
    
    mmi_bootup_sec_n_attempts_to_str(
        str_buffer,
        MMI_BOOTUP_SEC_MAX_SIM_STR_LEN,
        cntx->n_remaining_attempts),

    mmi_bootup_sec_get_length_restriction(
        SRV_BOOTUP_VERI_PHONE_LOCK,
        &min_pwd_len,
        &max_pwd_len);

    cntx->password_screen = cui_pwd_basic_create(
        cntx->grp_id,
        STR_ID_BOOTUP_INPUT_PHONE_PASSWORD,
        min_pwd_len,
        max_pwd_len);
    cui_pwd_basic_set_extra_msg(cntx->password_screen, str_buffer);
    cui_pwd_basic_set_action_str(cntx->password_screen, STR_GLOBAL_OK, 0);
    cui_pwd_basic_set_auxiliary(
        cntx->password_screen,
        CUI_PWD_AUXILIARY_BASIC_DEFAULT,
        MMI_TRUE,
        STR_ID_BOOTUP_SOFTKEY_EMERGENCY);
    cui_pwd_basic_set_proc(cntx->password_screen, mmi_bootup_sec_verify_phone_lock_proc, cntx);
    
    cui_pwd_basic_run(cntx->password_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_do_verification_of_sim
 * DESCRIPTION
 *  Do verification of SIM.
 * PARAMETERS
 *  cntx            [IN] Context
 *  sim             [IN] Which SIM
 *  str_buffer      [IN] Buffer for temporary strings
 * RETURNS
 *  MMI_TRUE if SIM verification is required
 *****************************************************************************/
static MMI_BOOL mmi_bootup_sec_do_verification_of_sim(
                    mmi_bootup_security_cntx_struct *cntx,
                    mmi_sim_enum sim,
                    WCHAR *str_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_remaining_attempts;
    srv_bootup_verification_type_enum veri_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    veri_type = srv_bootup_get_verification_info(sim, &n_remaining_attempts);

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_SIM_VERIFICATION, sim, veri_type);

    if (veri_type == SRV_BOOTUP_VERI_NONE)
    {
        return MMI_FALSE;
    }

    cntx->veri_type = veri_type;
    cntx->n_remaining_attempts = n_remaining_attempts;
    cntx->is_displaying_sim_screen = MMI_TRUE;
    cntx->sim_displaying = sim;

    switch (veri_type)
    {
        case SRV_BOOTUP_VERI_CHV1:
             mmi_bootup_sec_show_sim_password(
                cntx,
                sim,
                veri_type,
                n_remaining_attempts,
                str_buffer);
             break;

#ifdef __SIM_ME_LOCK__
        case SRV_BOOTUP_VERI_NP:
        case SRV_BOOTUP_VERI_NSP:
        case SRV_BOOTUP_VERI_SP:
        case SRV_BOOTUP_VERI_CP:
        case SRV_BOOTUP_VERI_SIMP:
        case SRV_BOOTUP_VERI_NSSP:
        case SRV_BOOTUP_VERI_SIMCP:
            mmi_bootup_sec_show_sim_password(
                cntx,
                sim,
                veri_type,
                n_remaining_attempts,
                str_buffer);
                
#ifdef __MMI_SML_UNLOCK_RETRY_TIMER__
            // TODO: Show waiting for power-off while previous counting-down
#endif

            break;
#endif /* __SIM_ME_LOCK__ */

        case SRV_BOOTUP_VERI_UBCHV1:
            mmi_bootup_sec_show_sim_ubchv1(
                cntx,
                sim,
                n_remaining_attempts,
                str_buffer);
            break;

        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_on_sim_status_changed
 * DESCRIPTION
 *  Handler for SIM status changed.
 *  If we are verifying SIM, displaying password screen and an fatal error
 *  occurred on SIM, we shall close the password screen and continue next
 *  valid verification.
 * PARAMETERS
 *  evt     [IN] srv_bootup_sim_status_changed_evt_struct
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_bootup_sec_on_sim_status_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;
    srv_bootup_sim_status_changed_evt_struct *status_changed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED);

    status_changed_evt = (srv_bootup_sim_status_changed_evt_struct*)evt;
    cntx = &(g_mmi_bootup_security_cntx);

    if (cntx->is_displaying_sim_screen &&
        status_changed_evt->sim == cntx->sim_displaying)
    {
        if (status_changed_evt->fatal_error)
        {
#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
            if (srv_bootup_is_completed()) /* Verification request from SecSet */
            {
                srv_sim_ctrl_ua_cause_enum ua_cause;

                ua_cause = srv_sim_ctrl_get_unavailable_cause(status_changed_evt->sim);
                switch (ua_cause)
                {
                    case SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED:
                    case SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR:
                    case SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE:
                    case SRV_SIM_CTRL_UA_CAUSE_DISCONNECTED:
                    case SRV_SIM_CTRL_UA_CAUSE_RECOVERY:
                        /* Popup by SimCtrl app, we only need to go next step */
                        if (cntx->password_screen != MMI_BOOTUP_CUI_NULL)
                        {
                            mmi_bootup_close_password_screen_and_continue(cntx);
                        }
                        else if (cntx->ubchv1_screen != MMI_BOOTUP_CUI_NULL)
                        {
                            mmi_bootup_close_ubchv1_screen_and_continue(cntx);
                        }
                        return MMI_RET_OK;
                        
                    default:
                        /* Popup by ourselves*/
                        break;
                }
            }
#endif
        
            /* Close the verification screen and do another verification */
            if (cntx->password_screen != MMI_BOOTUP_CUI_NULL)
            {
                MMI_ASSERT(cntx->ubchv1_screen == MMI_BOOTUP_CUI_NULL);
                mmi_bootup_popup_sim_error_and_continue(
                    cntx,
                    status_changed_evt->sim,
                    mmi_bootup_close_password_screen_and_continue);
            }
            else if (cntx->ubchv1_screen != MMI_BOOTUP_CUI_NULL)
            {
                mmi_bootup_popup_sim_error_and_continue(
                    cntx,
                    status_changed_evt->sim,
                    mmi_bootup_close_ubchv1_screen_and_continue);
            }
        }
        else
        {
            srv_bootup_verify_result_struct veri_result;
            srv_bootup_verification_type_enum veri_type;
            S32 n_remaining_attempts;

            /*
             * [MAUI_02283184] Feature: verify CHV1/UBCHV1 via AT command
             * Generate a result for current verification, to trigger
             * following UI actions.
             */
            veri_type = srv_bootup_get_verification_info(
                cntx->sim_displaying,
                &n_remaining_attempts);
                
            veri_result.sim = cntx->sim_displaying;
            veri_result.type = cntx->veri_type;
            veri_result.success = MMI_FALSE;
            veri_result.fatal_error = status_changed_evt->fatal_error;
            veri_result.n_remaining_attempts = n_remaining_attempts;
            
            if (cntx->veri_type != veri_type)
            {
                if (veri_type == SRV_BOOTUP_VERI_NONE)
                {
                    veri_result.success = MMI_TRUE;
                }
                else if (veri_type == SRV_BOOTUP_VERI_UBCHV1 &&
                    cntx->veri_type == SRV_BOOTUP_VERI_CHV1)
                {
                    veri_result.success = MMI_FALSE;
                    veri_result.n_remaining_attempts = 0;
                }
                else
                {
                    /* Another veri_type is required */
                    veri_result.success = MMI_TRUE;
                }
            }
            else if (n_remaining_attempts < cntx->n_remaining_attempts)
            {
                veri_result.success = MMI_FALSE;
            }
            else if (n_remaining_attempts == cntx->n_remaining_attempts)
            {
                /* Do nothing */
                return MMI_RET_OK;
            }
            else
            {
                /* Impossible: veri_type is the same, but n_remaining_attempts increased */
                MMI_ASSERT(MMI_FALSE);
            }

            if (cntx->veri_type == SRV_BOOTUP_VERI_UBCHV1)
            {
                mmi_bootup_sec_verify_ubchv1_result(cntx, &veri_result);
            }
            else
            {
                mmi_bootup_sec_verify_result(cntx, &veri_result);
            }
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_next_verification
 * DESCRIPTION
 *  Check the verification status and show correspoinding password screen if
 *  necessary.
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURN VALUES
 *  MMI_FRM_PROC_RESULT_NOTIFY_LATER : Verification is required and the 
 *                                     password screen has been shown.
 *  MMI_FRM_PROC_RESULT_COMPLETED : If no verification is required.
 *****************************************************************************/
static MMI_BOOL mmi_bootup_sec_next_verification(
                    mmi_bootup_security_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *str_buffer;
    mmi_sim_enum sim;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_buffer = (WCHAR*)OslMalloc((MMI_BOOTUP_SEC_MAX_SIM_STR_LEN + 20) * sizeof(WCHAR));

    cntx->veri_type = SRV_BOOTUP_VERI_NONE;
    cntx->n_remaining_attempts = 0;
    cntx->sim_displaying = MMI_SIM_NONE;
    cntx->is_displaying_sim_screen = MMI_FALSE;
    
    if (srv_bootup_phone_lock_is_required())
    {
        mmi_bootup_sec_do_verification_of_phone(
            cntx,
            str_buffer);

        OslMfree(str_buffer);
        return MMI_TRUE;
    }
#ifdef __MMI_TELEPHONY_SUPPORT__
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        sim = mmi_frm_index_to_sim(i);

        if (!srv_bootup_veri_is_cancelled(sim))
        {
            if (mmi_bootup_sec_do_verification_of_sim(
                    cntx,
                    sim,
                    str_buffer))
            {
                OslMfree(str_buffer);
                return MMI_TRUE;
            }
        }
    }
#endif
    OslMfree(str_buffer);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_continue_verification
 * DESCRIPTION
 *  Continue next verification. If no verification is required, it calls
 *  mmi_frm_proc_notify_completed to continue the booting flow.
 * PARAMETERS
 *  cntx    [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sec_continue_verification(
                    mmi_bootup_security_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_veri_completed_evt_struct completed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_sec_next_verification(cntx))
    {
        MMI_FRM_INIT_EVENT(&completed_evt, EVT_ID_MMI_BOOTUP_VERIFICATION_COMPLETED);
        MMI_FRM_SEND_EVENT(&completed_evt, cntx->proc, cntx->user_data);
        cntx->grp_id = GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sec_do_verification
 * DESCRIPTION
 *  Do verificaitons via bootup security interface. This API is also provided
 *  for SIM reinit.
 * PARAMETERS
 *  grp_id      [IN] Group ID
 *  proc        [IN] Complete event proc. Will be invoked only if returns
 *                   MMI_TRUE.
 *  user_data   [IN] To be passed into proc
 * RETURNS
 *  MMI_TRUE if the verification screen is shown. If returns MMI_FALSE,
 *  no verification is required and the proc will never be invoked.
 *****************************************************************************/
MMI_BOOL mmi_bootup_sec_do_verification(
            mmi_id grp_id,
            mmi_proc_func proc,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_security_cntx_struct *cntx;
    MMI_BOOL displayed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_security_cntx);

    /* Only one instance is available */
    MMI_EXT_ASSERT(cntx->grp_id == GRP_ID_INVALID, cntx->grp_id, grp_id, 0);
    
    cntx->grp_id = grp_id;
    cntx->password_screen = MMI_BOOTUP_CUI_NULL;
    cntx->ubchv1_screen = MMI_BOOTUP_CUI_NULL;
    cntx->is_displaying_sim_screen = MMI_FALSE;

    cntx->proc = proc;
    cntx->user_data = user_data;

    displayed = mmi_bootup_sec_next_verification(cntx);
    if (!displayed)
    {
        cntx->grp_id = GRP_ID_INVALID;
    }

    return displayed;
}



/*****************************************************************************
 * [Bootup flow - security procecure]
 *
 *
 *****************************************************************************/

typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
} mmi_bootup_sec_flow_cntx_struct;

static mmi_bootup_sec_flow_cntx_struct g_mmi_bootup_sec_flow_cntx;


static mmi_ret mmi_bootup_flow_security_on_completed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_notify_completed(g_mmi_bootup_sec_flow_cntx.id_info);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_security
 * DESCRIPTION
 *  Enter security check phase of bootup.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed().
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bootup_flow_security(
                            void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL displayed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_FLOW_SECURITY);
    
    g_mmi_bootup_sec_flow_cntx.id_info = id_info;

    displayed = mmi_bootup_sec_do_verification(
        GRP_ID_BOOTUP,
        mmi_bootup_flow_security_on_completed,
        &g_mmi_bootup_sec_flow_cntx);

    return (displayed ?
                MMI_FRM_PROC_RESULT_NOTIFY_LATER :
                MMI_FRM_PROC_RESULT_COMPLETED);
}


