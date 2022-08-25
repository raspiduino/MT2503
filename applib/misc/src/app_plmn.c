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
 *  app_plmn.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements common utilities related to PLMN.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "app_plmn.h"
#include "kal_general_types.h"
#include "string.h"

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef kal_bool (*app_plmn_compare_cb)(
    const kal_char *plmn1,
    const kal_char *plmn2,
    kal_int32 len);


/****************************************************************************
 * Function
 ****************************************************************************/

/* For the detail information, please refer to the app_plmn.h */
kal_bool applib_plmn_convert_bcd_2_string(
    const kal_uint8 *bcd,
    kal_int32 bcd_size,
    kal_char *string,
    kal_int32 string_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!bcd || !string ||
        bcd_size < APPLIB_PLMN_BCD_SIZE ||
        string_size < (APPLIB_PLMN_MAX_LEN + 1))
    {
        return KAL_FALSE; /* fail-safe */
    }

    string[0] = '0' + (bcd[0] & 0x0F);              /* MCC digit 1 */
    string[1] = '0' + ((bcd[0] & 0xF0) >> 4);       /* MCC digit 2 */
    string[2] = '0' + (bcd[1] & 0x0F);              /* MCC digit 3 */
    string[3] = '0' + (bcd[2] & 0x0F);              /* MNC digit 1 */
    string[4] = '0' + ((bcd[2] & 0xF0) >> 4);       /* MNC digit 2 */
    string[5] = '0' + ((bcd[1] & 0xF0) >> 4);

    if ((bcd[1] & 0xF0) == 0xF0)
    {
        string[5] = '\0';                           /* MNC only has 2 digits. */
    }
    else
    {
        string[5] = '0' + ((bcd[1] & 0xF0) >> 4);   /* MNC has 3 digits. */
        string[6] = '\0';
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_plmn_compare_with_wild_char
 * DESCRIPTION
 *  This function compares PLMN. It supports the wild char.
 *  Per EF_OPL, a BCD value of 'D' in any of the MCC and/or MNC digits should be
 *  used to indicate a 'wild' value for that corresponding MCC/MNC digit.
 * PARAMETERS
 *  plmn1           : [IN]          PLMN 1
 *  plmn2           : [IN]          PLMN 2
 *  len             : [IN]          Length of digits that will be compared
 * RETURNS
 *  On same, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
static kal_bool applib_plmn_compare_with_wild_char(
    const kal_char *plmn1,
    const kal_char *plmn2,
    kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        /*
         * If this is wild char, check the next one.
         *
         * Wild card is 0x0d, which will be '=' (0x0d + 0x30) after it is
         * converted from BCD to string.
         */
        if (plmn1[i] == '=' || plmn2[i] == '=')
        {
            continue; /* wild card. check the next one. */
        }

        if (plmn1[i] != plmn2[i])
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_plmn_compare
 * DESCRIPTION
 *  This function compare PLMN.
 * PARAMETERS
 *  plmn1           : [IN]          PLMN 1
 *  plmn2           : [IN]          PLMN 2
 *  len             : [IN]          Length of digits that will be compared
 * RETURNS
 *  On same, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
static kal_bool applib_plmn_compare(
    const kal_char *plmn1,
    const kal_char *plmn2,
    kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return strncmp(plmn1, plmn2, len) == 0 ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_plmn_is_pcs1900_for_north_america
 * DESCRIPTION
 *  This function checks if the BCCH PLMN is the PCS1900 for North America
 *  network. For this requirement, please refer to 23.122, AnnexA (normative):
 *  HPLMN Matching Criteria.
 * PARAMETERS
 *  plmn            : [IN]          PLMN
 * RETURNS
 *  On yes, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
static kal_bool applib_plmn_is_pcs1900_for_north_america(
    const kal_char *bcch_plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If the BCCH-MCC lies in the range 310-316. */
    if (bcch_plmn[0] == '3' &&
        bcch_plmn[1] == '1' &&
        bcch_plmn[2] >= '0' && bcch_plmn[2] <= '6')
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_plmn_is_0_suffix_rule_matched
 * DESCRIPTION
 *  This function checks if the "0" suffix rule is matched. For the "0" suffix
 *  rule, please refer to 23.122, AnnexA (normative): HPLMN Matching Criteria.
 * PARAMETERS
 *  sim_plmn        : [IN]          SIM PLMN
 * RETURNS
 *  On matched, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
static kal_bool applib_plmn_is_0_suffix_rule_matched(const kal_char *sim_plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(sim_plmn) == 6 && sim_plmn[5] == '0')
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/* For the detail information, please refer to the app_plmn.h */
kal_bool applib_plmn_is_matched_ex(
    const kal_char *sim_plmn,
    const kal_char *bcch_plmn,
    kal_bool is_band_pcs1900,
    kal_bool is_wild_char_supported)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_plmn_compare_cb compare;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Determine PLMN comparing function.
     */
    if (is_wild_char_supported)
    {
        compare = applib_plmn_compare_with_wild_char;
    }
    else
    {
        compare = applib_plmn_compare;
    }

    /*
     * Matching PLMN per 23.122, Annex A (normative).
     */
    if (!is_band_pcs1900)
    {
        if (compare(sim_plmn, bcch_plmn, 3))
        {
            if (strlen(bcch_plmn) == 5)
            {
                return compare(sim_plmn + 3, bcch_plmn + 3, 2);
            }
            else
            {
                return compare(sim_plmn + 3, bcch_plmn + 3, 3);
            }
        }
    }
    else
    {
        if (compare(sim_plmn, bcch_plmn, 3))
        {
            if (strlen(bcch_plmn) == 5)
            {
                if (applib_plmn_is_pcs1900_for_north_america(bcch_plmn))
                {
                    if (applib_plmn_is_0_suffix_rule_matched(sim_plmn))
                    {
                        return compare(sim_plmn + 3, bcch_plmn + 3, 2);
                    }
                }
                else
                {
                    return compare(sim_plmn + 3, bcch_plmn + 3, 2);
                }
            }
            else
            {
                return compare(sim_plmn + 3, bcch_plmn + 3, 3);
            }
        }
    }

    return KAL_FALSE;
}


/* For the detail information, please refer to the app_plmn.h */
kal_bool applib_plmn_is_matched(
    const kal_char *sim_plmn,
    const kal_char *bcch_plmn,
    kal_bool is_band_pcs1900)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_plmn_is_matched_ex(
            sim_plmn,
            bcch_plmn,
            is_band_pcs1900,
            KAL_FALSE);
}

