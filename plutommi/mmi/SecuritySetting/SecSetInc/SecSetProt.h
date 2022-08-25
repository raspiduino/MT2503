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
 *  SecSetSim.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal header of security setting
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

#ifndef __MMI_SEC_SET_PROT_H__
#define __MMI_SEC_SET_PROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SimCtrlSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
//#include "mmi_rp_app_bootup_def.h"
//#include "mmi_rp_app_security_setting_def.h"
#include "mmi_frm_events_gprot.h"
#ifndef __RESOURCE_GEN_
#include "SimCtrlGprot.h" /* mmi_sim_ctrl_gen_str */
#include "mmi_rp_app_bootup_def.h"
#ifdef __MMI_SECSET_APP_SUPPORT__
#include "mmi_rp_app_security_setting_def.h"
#endif/*__MMI_SECSET_APP_SUPPORT__*/
#endif/*__RESOURCE_GEN_*/

#if (defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_SECSET_APP_WITH_BWUI__
	#define __MMI_SECSET_APP_WITH_BWUI__
	#endif
#endif

#define MMI_SECSET_TRC_GROUP MMI_COMMON_TRC_G7_SETTING


/****************************************************************************
 * Constants
 ****************************************************************************/

#define MMI_SECSET_MIN_CHV_LEN      4
#define MMI_SECSET_MAX_CHV_LEN      8
#define MMI_SECSET_MIN_UBCHV_LEN    8
#define MMI_SECSET_MAX_UBCHV_LEN    8

#define MMI_SECSET_MIN_PHONE_PASSWORD_LEN 4
#define MMI_SECSET_MAX_PHONE_PASSWORD_LEN 8


/****************************************************************************
 * [Utility]
 *
 ****************************************************************************/

typedef enum
{
    MMI_SECSET_STR_INPUT_CHV = 0,
    MMI_SECSET_STR_WRONG_CHV,
    MMI_SECSET_STR_OLD_CHV,
    MMI_SECSET_STR_NEW_CHV,
    MMI_SECSET_STR_CONFIRM_CHV,
    MMI_SECSET_STR_CHV_DISABLED,

    MMI_SECSET_STR_CHV_BLOCKED,
    MMI_SECSET_STR_INPUT_UBCHV,
    MMI_SECSET_STR_WRONG_UBCHV,
    MMI_SECSET_STR_UBCHV_BLOCKED,
    MMI_SECSET_STR_UBCHV_BLOCKED_ONLY,

    MMI_SECSET_STR_SIM_ERROR,

    MMI_SECSET_STR_TOTAL
} mmi_secset_sim_string_enum;

#define MMI_SECSET_SIM_MAX_STR_LEN 66

WCHAR* mmi_secset_sim_get_string(
            mmi_sim_enum sim,
            srv_sim_ctrl_pwd_type_enum chv_type,
            mmi_secset_sim_string_enum str_type,
            WCHAR *out_str_buffer,
            S32 max_str_len);

WCHAR *mmi_secset_n_attempts_to_str(
            S32 n_remaining_attempts,
            WCHAR *out_str_buffer,
            S32 max_str_len);

mmi_id mmi_secset_sim_display_error_popup(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum chv_type,
        srv_sim_ctrl_fail_cause_enum cause,
        mmi_id grp_id,
        void *user_tag);

mmi_id mmi_secset_sim_display_popup(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum chv_type,
        mmi_secset_sim_string_enum str_type,
        mmi_event_notify_enum event_type,
        mmi_id grp_id,
        void *user_tag);

MMI_BOOL mmi_secset_make_emergency_call(mmi_id grp_id, const WCHAR* number);
mmi_ret mmi_secset_make_emergency_call_on_yes(mmi_event_struct *evt);

mmi_id mmi_secset_show_waiting(mmi_id grp_id);
void mmi_secset_close_waiting(mmi_id grp_id);


/****************************************************************************
 * [UBCHV]
 *
 ****************************************************************************/

#define MMI_SECSET_DONT_CLOSE (-1)
#define MMI_SECSET_UBCHV_INVALID_HANDLE (NULL)

typedef void *mmi_secset_ubchv_handle;


mmi_secset_ubchv_handle mmi_secset_ubchv_create(
    mmi_id grp_id,
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum type,
    mmi_proc_func proc,
    void *user_data);

void mmi_secset_ubchv_run(mmi_secset_ubchv_handle handle);
void mmi_secset_ubchv_close(mmi_secset_ubchv_handle handle);
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
void mmi_secset_ubchv_update_prompt(mmi_secset_ubchv_handle handle);
#endif


/****************************************************************************
 * Events
 ****************************************************************************/

typedef enum
{
  #ifdef __MMI_SECSET_APP_SUPPORT__
    EVT_ID_SECSET_UBCHV_UNBLOCKED = APP_SECURITY_SETTING_BASE,
  #else
    EVT_ID_SECSET_UBCHV_UNBLOCKED,
  #endif
    EVT_ID_SECSET_UBCHV_CANCEL,
    EVT_ID_SECSET_UBCHV_PASSIVE_CLOSING,
    EVT_ID_SECSET_UBCHV_BLOCKED,
    EVT_ID_SECSET_UBCHV_SIM_ERROR,

    EVT_ID_SECSET_END_OF_ENUM
} mmi_secset_event_enum;


typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_secset_ubchv_handle instance;
} mmi_secset_ubchv_unblocked_evt_struct,
  mmi_secset_ubchv_cancel_evt_struct,
  mmi_secset_ubchv_passive_closing_evt_struct,
  mmi_secset_ubchv_blocked_evt_struct,
  mmi_secset_ubchv_sim_error_evt_struct;


/****************************************************************************
 * Module callbacks
 ****************************************************************************/

extern mmi_ret mmi_secset_sim_main_menu_proc(mmi_event_struct *evt);
extern mmi_ret mmi_secset_phone_menu_proc(mmi_event_struct *evt);

extern mmi_ret mmi_secset_hpveri_on_sim_availability_changed(mmi_event_struct *evt);

extern void mmi_secset_hpveri_display_ubchv1(mmi_id grp_id, mmi_sim_enum sim);
extern void mmi_secset_sim_close_screens_of_type(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum type);

extern mmi_ret mmi_secset_hpveri_on_sim_number_changed(mmi_event_struct *evt);


/****************************************************************************
 * Resource for slim project
 ****************************************************************************/

#define STR_ID_SECSET_CONFIRM_NEW_CHV1      STR_ID_BOOTUP_CONFIRM_NEW_CHV1
#define STR_ID_SECSET_WRONG_PHONE_PASSWORD  STR_ID_BOOTUP_WRONG_PHONE_PASSWORD
#define STR_ID_SECSET_EMERGENCY_CALL_ASK    STR_ID_BOOTUP_EMERGENCY_CALL_ASK
#define STR_ID_SECSET_REMAINING_TRIALS_PROMPT STR_ID_BOOTUP_REMAINING_TRIALS_PROMPT
#define STR_ID_SECSET_SOFTKEY_EMERGENCY     STR_ID_BOOTUP_SOFTKEY_EMERGENCY
#define STR_ID_SECSET_INPUT_PHONE_PASSWORD  STR_ID_BOOTUP_INPUT_PHONE_PASSWORD
#define STR_ID_SECSET_CHV1_NOT_MATCH        STR_ID_BOOTUP_CHV1_NOT_MATCH
#define STR_ID_SECSET_INPUT_CHV1            STR_ID_BOOTUP_INPUT_CHV1
#define STR_ID_SECSET_WRONG_CHV1            STR_ID_BOOTUP_WRONG_CHV1
#define STR_ID_SECSET_INPUT_UBCHV1          STR_ID_BOOTUP_INPUT_UBCHV1
#define STR_ID_SECSET_WRONG_UBCHV1          STR_ID_BOOTUP_WRONG_UBCHV1
#define STR_ID_SECSET_NEW_CHV1              STR_ID_BOOTUP_NEW_CHV1
#define STR_ID_SECSET_CHV1_BLOCKED          STR_ID_BOOTUP_SIM_CHV1_BLOCKED
#define STR_ID_SECSET_UBCHV1_BLOCKED        STR_ID_BOOTUP_SIM_BLOCKED

#define STR_ID_SECSET_SIMX_INPUT_CHV1       STR_ID_BOOTUP_SIMX_INPUT_CHV1
#define STR_ID_SECSET_WRONG_CHV1            STR_ID_BOOTUP_WRONG_CHV1
#define STR_ID_SECSET_SIMX_INPUT_UBCHV1     STR_ID_BOOTUP_SIMX_INPUT_UBCHV1
#define STR_ID_SECSET_WRONG_UBCHV1          STR_ID_BOOTUP_WRONG_UBCHV1
#define STR_ID_SECSET_SIMX_NEW_CHV1         STR_ID_BOOTUP_SIMX_NEW_CHV1
#define STR_ID_SECSET_SIMX_CHV1_BLOCKED     STR_ID_BOOTUP_SIMX_CHV1_BLOCKED
#define STR_ID_SECSET_SIMX_UBCHV1_BLOCKED   STR_ID_BOOTUP_SIMX_BLOCKED


#endif /* __MMI_SEC_SET_PROT_H__ */

