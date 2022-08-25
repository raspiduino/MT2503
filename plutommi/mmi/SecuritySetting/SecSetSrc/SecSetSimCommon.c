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
 *  SecSetSimCommon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Common utility for SIM UI
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

#include "SecSetProt.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "mmi_rp_app_security_setting_def.h"
#include "SimCtrlSrvGprot.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"


/****************************************************************************
 * Configurations
 ****************************************************************************/

typedef enum
{
    MMI_SECSET_CHV1_INDEX = 0,
    MMI_SECSET_CHV2_INDEX,

    MMI_SECSET_CHV_INDEX_TOTAL
} mmi_secset_chv_index_enum;

typedef struct
{
    MMI_STR_ID chv[MMI_SECSET_CHV_INDEX_TOTAL][MMI_SECSET_STR_TOTAL];
} mmi_secset_sim_string_struct;


#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
#ifdef __MMI_SECSET_APP_WITH_BWUI__
static const mmi_secset_sim_string_struct mmi_secset_sim_string_single =
{
    {{ /* CHV1 */
        STR_ID_SECSET_INPUT_CHV1_BWUI,
        STR_ID_SECSET_WRONG_CHV1,
        STR_ID_SECSET_OLD_CHV1_BWUI,
        STR_ID_SECSET_NEW_CHV1_BWUI,
        STR_ID_SECSET_CONFIRM_NEW_CHV1_BWUI,
        STR_ID_SECSET_ENABLE_CHV1_PROMPT,
        
        STR_ID_SECSET_CHV1_BLOCKED,
        STR_ID_SECSET_INPUT_UBCHV1_BWUI,
        STR_ID_SECSET_WRONG_UBCHV1,
        STR_ID_SECSET_UBCHV1_BLOCKED,
        STR_ID_SECSET_UBCHV1_BLOCKED_ONLY,

        STR_ID_SECSET_SIM_ERROR
    },
    { /* CHV2 */
        STR_ID_SECSET_INPUT_CHV2_BWUI,
        STR_ID_SECSET_WRONG_CHV2,
        STR_ID_SECSET_OLD_CHV2_BWUI,
        STR_ID_SECSET_NEW_CHV2_BWUI,
        STR_ID_SECSET_CONFIRM_NEW_CHV2_BWUI,
        STR_ID_SECSET_CHV2_DISABLED,
        
        STR_ID_SECSET_CHV2_BLOCKED,
        STR_ID_SECSET_INPUT_UBCHV2_BWUI,
        STR_ID_SECSET_WRONG_UBCHV2,
        STR_ID_SECSET_UBCHV2_BLOCKED,
        STR_ID_SECSET_UBCHV2_BLOCKED,

        STR_ID_SECSET_SIM_ERROR
    }}
};

#else
static const mmi_secset_sim_string_struct mmi_secset_sim_string_single =
{
    {{ /* CHV1 */
        STR_ID_SECSET_INPUT_CHV1,
        STR_ID_SECSET_WRONG_CHV1,
        STR_ID_SECSET_OLD_CHV1,
        STR_ID_SECSET_NEW_CHV1,
        STR_ID_SECSET_CONFIRM_NEW_CHV1,
        STR_ID_SECSET_ENABLE_CHV1_PROMPT,
        
        STR_ID_SECSET_CHV1_BLOCKED,
        STR_ID_SECSET_INPUT_UBCHV1,
        STR_ID_SECSET_WRONG_UBCHV1,
        STR_ID_SECSET_UBCHV1_BLOCKED,
        STR_ID_SECSET_UBCHV1_BLOCKED_ONLY,

        STR_ID_SECSET_SIM_ERROR
    },
    { /* CHV2 */
        STR_ID_SECSET_INPUT_CHV1,
        STR_ID_SECSET_WRONG_CHV2,
        STR_ID_SECSET_OLD_CHV1,
        STR_ID_SECSET_NEW_CHV1,
        STR_ID_SECSET_CONFIRM_NEW_CHV1,
        STR_ID_SECSET_CHV2_DISABLED,
        
        STR_ID_SECSET_CHV2_BLOCKED,
        STR_ID_SECSET_INPUT_UBCHV1,
        STR_ID_SECSET_WRONG_UBCHV2,
        STR_ID_SECSET_UBCHV2_BLOCKED,
        STR_ID_SECSET_UBCHV2_BLOCKED,

        STR_ID_SECSET_SIM_ERROR
    }}
};
#endif /*__MMI_SECSET_APP_WITH_BWUI__*/
#endif /* MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */

#if (MMI_MAX_SIM_NUM >= 2)
#ifdef __MMI_SECSET_APP_WITH_BWUI__
static const mmi_secset_sim_string_struct mmi_secset_sim_string_multiple =
{
    {{ /* CHV1 */
        STR_ID_SECSET_SIMX_INPUT_CHV1_BWUI,
        STR_ID_SECSET_WRONG_CHV1,
        STR_ID_SECSET_SIMX_OLD_CHV1_BWUI,
        STR_ID_SECSET_SIMX_NEW_CHV1_BWUI,
        STR_ID_SECSET_CONFIRM_NEW_CHV1_BWUI,
        STR_ID_SECSET_ENABLE_CHV1_PROMPT,
        
        STR_ID_SECSET_SIMX_CHV1_BLOCKED,
        STR_ID_SECSET_SIMX_INPUT_UBCHV1_BWUI,
        STR_ID_SECSET_WRONG_UBCHV1,
        STR_ID_SECSET_SIMX_UBCHV1_BLOCKED,
        STR_ID_SECSET_SIMX_UBCHV1_BLOCKED_ONLY,

        STR_ID_SECSET_SIM_ERROR
    },
    { /* CHV2 */
        STR_ID_SECSET_SIMX_INPUT_CHV1_BWUI,
        STR_ID_SECSET_WRONG_CHV2,
        STR_ID_SECSET_SIMX_OLD_CHV1_BWUI,
        STR_ID_SECSET_SIMX_NEW_CHV1_BWUI,
        STR_ID_SECSET_CONFIRM_NEW_CHV2_BWUI,
        STR_ID_SECSET_CHV2_DISABLED,
        
        STR_ID_SECSET_SIMX_CHV2_BLOCKED,
        STR_ID_SECSET_SIMX_INPUT_UBCHV1_BWUI,
        STR_ID_SECSET_WRONG_UBCHV2,
        STR_ID_SECSET_SIMX_UBCHV2_BLOCKED,
        STR_ID_SECSET_SIMX_UBCHV2_BLOCKED,

        STR_ID_SECSET_SIM_ERROR
    }}
};

#else
static const mmi_secset_sim_string_struct mmi_secset_sim_string_multiple =
{
    {{ /* CHV1 */
        STR_ID_SECSET_SIMX_INPUT_CHV1,
        STR_ID_SECSET_WRONG_CHV1,
        STR_ID_SECSET_SIMX_OLD_CHV1,
        STR_ID_SECSET_SIMX_NEW_CHV1,
        STR_ID_SECSET_CONFIRM_NEW_CHV1,
        STR_ID_SECSET_ENABLE_CHV1_PROMPT,
        
        STR_ID_SECSET_SIMX_CHV1_BLOCKED,
        STR_ID_SECSET_SIMX_INPUT_UBCHV1,
        STR_ID_SECSET_WRONG_UBCHV1,
        STR_ID_SECSET_SIMX_UBCHV1_BLOCKED,
        STR_ID_SECSET_SIMX_UBCHV1_BLOCKED_ONLY,

        STR_ID_SECSET_SIM_ERROR
    },
    { /* CHV2 */
        STR_ID_SECSET_SIMX_INPUT_CHV1,
        STR_ID_SECSET_WRONG_CHV2,
        STR_ID_SECSET_SIMX_OLD_CHV1,
        STR_ID_SECSET_SIMX_NEW_CHV1,
        STR_ID_SECSET_CONFIRM_NEW_CHV1,
        STR_ID_SECSET_CHV2_DISABLED,
        
        STR_ID_SECSET_SIMX_CHV2_BLOCKED,
        STR_ID_SECSET_SIMX_INPUT_UBCHV1,
        STR_ID_SECSET_WRONG_UBCHV2,
        STR_ID_SECSET_SIMX_UBCHV2_BLOCKED,
        STR_ID_SECSET_SIMX_UBCHV2_BLOCKED,

        STR_ID_SECSET_SIM_ERROR
    }}
};
#endif
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/****************************************************************************
 * Functions
 ****************************************************************************/

WCHAR* mmi_secset_sim_get_string(
            mmi_sim_enum sim,
            srv_sim_ctrl_pwd_type_enum chv_type,
            mmi_secset_sim_string_enum str_type,
            WCHAR *out_str_buffer,
            S32 max_str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 chv_index;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chv_index = 0;
    if (chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ||
        chv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
    {
        chv_index = MMI_SECSET_CHV1_INDEX;
    }
    else
    {
        chv_index = MMI_SECSET_CHV2_INDEX;
    }

#if (MMI_MAX_SIM_NUM == 1)

    str_id = mmi_secset_sim_string_single.chv[chv_index][str_type];
    mmi_wcsncpy(out_str_buffer, get_string(str_id), max_str_len);
    if(MMI_SECSET_CHV2_INDEX == chv_index && mmi_secset_sim_string_single.chv[MMI_SECSET_CHV1_INDEX][str_type] == str_id)
    {
        mmi_wcscat(out_str_buffer,L"2");
    }
    
#else /* (MMI_MAX_SIM_NUM == 1) */

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    if (srv_sim_ctrl_get_num_of_inserted() <= 1)
    {
        str_id = mmi_secset_sim_string_single.chv[chv_index][str_type];
        mmi_wcsncpy(out_str_buffer, get_string(str_id), max_str_len);
        if(MMI_SECSET_CHV2_INDEX == chv_index && mmi_secset_sim_string_single.chv[MMI_SECSET_CHV1_INDEX][str_type] == str_id)
        {
            mmi_wcscat(out_str_buffer,L"2");
        }
    }
    else
#endif
    {
        str_id = mmi_secset_sim_string_multiple.chv[chv_index][str_type];
        mmi_sim_ctrl_gen_str(out_str_buffer, max_str_len, str_id, sim);
        if(MMI_SECSET_CHV2_INDEX == chv_index && mmi_secset_sim_string_multiple.chv[MMI_SECSET_CHV1_INDEX][str_type] == str_id)
        {
            mmi_wcscat(out_str_buffer,L"2");
        }
    }
    
#endif /* (MMI_MAX_SIM_NUM == 1) */

    return out_str_buffer;
}


mmi_id mmi_secset_sim_display_error_popup(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum chv_type,
        srv_sim_ctrl_fail_cause_enum cause,
        mmi_id grp_id,
        void *user_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id popup_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    popup_ret = 0;
    
    switch (cause)
    {
        case SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED:
            popup_ret = mmi_secset_sim_display_popup(
                sim,
                chv_type,
                MMI_SECSET_STR_CHV_BLOCKED,
                MMI_EVENT_FAILURE,
                grp_id,
                user_tag);
            break;

        case SRV_SIM_CTRL_FAIL_CAUSE_TEMP_FAIL:
            popup_ret = mmi_popup_display_simple(
                get_string(STR_ID_SECSET_TEMP_FAIL),
                MMI_EVENT_FAILURE,
                grp_id,
                user_tag);
            break;

        case SRV_SIM_CTRL_FAIL_CAUSE_SIM_ERROR:
            popup_ret = mmi_secset_sim_display_popup(
                sim,
                chv_type,
                MMI_SECSET_STR_SIM_ERROR,
                MMI_EVENT_FAILURE,
                grp_id,
                user_tag);
            break;

        default:
            popup_ret = mmi_popup_display_simple(
                get_string(STR_GLOBAL_ERROR),
                MMI_EVENT_FAILURE,
                grp_id,
                user_tag);
            break;
    }

    return popup_ret;
}


mmi_id mmi_secset_sim_display_popup(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum chv_type,
        mmi_secset_sim_string_enum str_type,
        mmi_event_notify_enum event_type,
        mmi_id grp_id,
        void *user_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id popup_ret;
    WCHAR *message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    popup_ret = 0;

    message = (WCHAR*)mmi_malloc((MMI_SECSET_SIM_MAX_STR_LEN + 1) * sizeof(WCHAR));
    mmi_secset_sim_get_string(
        sim,
        chv_type,
        str_type,
        message,
        MMI_SECSET_SIM_MAX_STR_LEN);
    
    popup_ret = mmi_popup_display_simple(
        message,
        event_type,
        grp_id,
        user_tag);

    mmi_mfree(message);

    return popup_ret;
}


