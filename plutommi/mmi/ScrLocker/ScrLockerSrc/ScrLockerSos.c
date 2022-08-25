/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrLockerSos.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the SOS call for the screen locker.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "DialerGprot.h"
#include "custom_ecc.h"
#include "UcmSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

// auto add by kw_check begin
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "ScrLockerMain.h"
#include "Unicodexdcl.h"
#include "ScrLockerObject.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "DialerCuiGprot.h"
#include "GlobalConstants.h"
#include "custom_phb_config.h"
#ifdef __MMI_BT_CALL_SUPPORT__
#include "BtcmSrvGprot.h"
#endif // __MMI_BT_CALL_SUPPORT__
// auto add by kw_check end 

#include "MMI_ap_dcm_config.h"
#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata = "DYNAMIC_CODE_SCRLOCK_RODATA" , code = "DYNAMIC_CODE_SCRLOCK_ROCODE"
#endif

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_sos_is_ecc
 * DESCRIPTION
 *  This function checks if the dial string is an emergency number. Note that to
 *  check the ECC number, we should first check if UCM can dial call in this SIM
 *  card.
 * PARAMETERS
 *  dial_string             : [IN]          Dial string
 * RETURNS
 *  ecc_verify_detail_enum
 *****************************************************************************/
static ecc_verify_detail_enum mmi_slk_sos_is_ecc(const WCHAR *dial_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum ucm_type[] =
    {
        SRV_UCM_VOICE_CALL_TYPE,
        SRV_UCM_VOICE_CALL_TYPE_SIM2,
        SRV_UCM_VOICE_CALL_TYPE_SIM3,
        SRV_UCM_VOICE_CALL_TYPE_SIM4
    };

    ecc_call_type_enum ecc_type[] =
    {
        ECC_SIM1_CALL,
        ECC_SIM2_CALL,
        ECC_SIM3_CALL,
        ECC_SIM4_CALL
    };

    kal_uint8 verify_detail, final_result = ECC_NOT_MATCH;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(MMI_SLK_GET_SIZE(ucm_type) == MMI_SLK_GET_SIZE(ecc_type));
    MMI_ASSERT(MMI_SLK_GET_SIZE(ucm_type) >= MMI_SIM_TOTAL);
#ifdef __MMI_TELEPHONY_SUPPORT__
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        /* First check if UCM can dial ECC in this call type. On yes, we can
           verify if this dial string is an ECC number or not. */
        if (srv_ucm_is_call_srv_available(ucm_type[i]))
        {
            ecc_custom_verify_emergency_number(
                (kal_uint8 *)dial_string,
                (kal_uint8)mmi_wcslen(dial_string),
                ECC_ENCODING_UCS2,
                ecc_type[i],
                NULL,
                NULL,
                &verify_detail);

            if (verify_detail == ECC_FULLY_MATCH)
            {
                return ECC_FULLY_MATCH;
            }
            else if (verify_detail == ECC_PARTIALLY_MATCH)
            {
                final_result = ECC_PARTIALLY_MATCH;
            }
        }
    }
#elif defined(__MMI_BT_CALL_SUPPORT__)
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
    {
        ecc_custom_verify_emergency_number(
            (kal_uint8 *)dial_string,
            (kal_uint8)mmi_wcslen(dial_string),
            ECC_ENCODING_UCS2,
            ECC_ALL_CALL,
            NULL,
            NULL,
            &verify_detail);

        if (verify_detail == ECC_FULLY_MATCH)
        {
            return ECC_FULLY_MATCH;
        }
        else if (verify_detail == ECC_PARTIALLY_MATCH)
        {
            final_result = ECC_PARTIALLY_MATCH;
        }
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    return (ecc_verify_detail_enum)final_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_sos_reset
 * DESCRIPTION
 *  This function resets the context.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_sos_reset(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    kal_wsprintf(obj->dial_string, "");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_sos_shift_left
 * DESCRIPTION
 *  This function shifts one digits in the dial string.
 * PARAMETERS
 *  dial_string             : [IN]          Dial string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_sos_shift_left(WCHAR *dial_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *tmp_str;
    S32 str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_wcslen(dial_string);
    if (str_len <= 0)
    {
        return; /* fail-safe. */
    }

    tmp_str = (WCHAR *)mmi_malloc((str_len + 1) * sizeof(WCHAR));

    mmi_wcsncpy(tmp_str, dial_string + 1, str_len);
    mmi_wcscpy(dial_string, tmp_str);

    mmi_mfree(tmp_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_sos_parse_string
 * DESCRIPTION
 *  This function parses the dial string.
 * PARAMETERS
 *  dial_string             : [IN]          Dial string
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_sos_parse_string(WCHAR *dial_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ecc_verify_detail_enum verify_detail;
    S32 str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (str_len = mmi_wcslen(dial_string);
         str_len > 0;
         str_len = mmi_wcslen(dial_string))
    {
        verify_detail = mmi_slk_sos_is_ecc(dial_string);

        switch (verify_detail)
        {
            case ECC_PARTIALLY_MATCH:
                /* Partially matched. Do nothing. Wait for the next input. */
                return MMI_RET_OK;

            case ECC_FULLY_MATCH:
                /* Matched. Stop key routing and launch the SOS dialer. */
                return MMI_RET_STOP_KEY_HANDLE;

            case ECC_NOT_MATCH: /* fall through */
            default:
                /* Not matched. Shift left and check the remained string. */
                mmi_slk_sos_shift_left(dial_string);
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_sos_launch
 * DESCRIPTION
 *  This function launches the SOS dialer.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_sos_launch(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
#ifdef __MMI_DIALER_CUI_SUPPORT__
    mmi_dialer_launch_by_string_ex(CUI_DIALER_TYPE_SOS, obj->dial_string);
#endif
    mmi_slk_sos_reset(obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_sos_on_key
 * DESCRIPTION
 *  This function handles the key event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  key_evt         : [IN]          Key event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_slk_sos_on_key(
    mmi_slk_obj_struct *obj,
    mmi_frm_key_evt_struct *key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR dial_str[32]; /* 32 is large enough for any 32-bits integer. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (key_evt->key_type != KEY_EVENT_DOWN)
    {
        return MMI_RET_OK;
    }

    if (key_evt->key_code > (U8)KEY_9)
    {
        mmi_slk_sos_reset(obj);
        return MMI_RET_OK;
    }

    kal_wsprintf(dial_str, "%d", key_evt->key_code);

    mmi_wcsncat(obj->dial_string, dial_str, CUI_DIALER_MAX_DIAL_STR_LEN);

    return mmi_slk_sos_parse_string(obj->dial_string);
}

#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata , code
#endif


