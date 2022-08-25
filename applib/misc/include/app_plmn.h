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
 *  app_plmn.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the PLMN utilities.
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

#ifndef APP_PLMN_H
#define APP_PLMN_H

#include "kal_general_types.h"

/****************************************************************************
 * Define
 ****************************************************************************/

/* Size of a PLMN BCD entry. */
#define APPLIB_PLMN_BCD_SIZE        (3)

/* Max. length of the PLMN. */
#define APPLIB_PLMN_MAX_LEN         (6)


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_plmn_convert_bcd_2_string
 * DESCRIPTION
 *  This function converts the PLMN in BCD format to string.
 *
 *  Please refer to 3GPP TS 24.008.
 *
 *      Octet 1:    MCC digit 2         MCC digit 1
 *      Octet 2:    MNC digit 3         MCC digit 3
 *      Octet 3:    MNC digit 2         MNC digit 1
 *
 *  If the MNC contains only 2 digits, bits 5 to 8 of octet 2 shall be coded as
 *  '1111'.
 *
 * PARAMETERS
 *  bcd                 : [IN]          BCD buffer
 *  bcd_size            : [IN]          BCD buffer size
 *  string              : [OUT]         String buffer
 *  string_size         : [IN]          String buffer size
 * RETURNS
 *  void
 *****************************************************************************/
extern kal_bool applib_plmn_convert_bcd_2_string(
    const kal_uint8 *bcd,
    kal_int32 bcd_size,
    kal_char *string,
    kal_int32 string_size);


/*****************************************************************************
 * FUNCTION
 *  applib_plmn_is_matched_ex
 * DESCRIPTION
 *  This function matches the SIM PLMN and BCCH PLMN according to the 23.122,
 *  AnnexA (normative): HPLMN Matching Criteria. Additionally, it also
 *  considers the wild card mentioned in EF_OPL.
 * PARAMETERS
 *  sim_plmn                    : [IN]      PLMN read from SIM
 *  bcch_plmn                   : [IN]      PLMN from network
 *  is_band_pcs1900             : [IN]      Camp on PCS1900 or not
 *  is_wild_char_supported      : [IN]      Support wild char or not
 * RETURNS
 *  If matched, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
extern kal_bool applib_plmn_is_matched_ex(
    const kal_char *sim_plmn,
    const kal_char *bcch_plmn,
    kal_bool is_band_pcs1900,
    kal_bool is_wild_char_supported);


/*****************************************************************************
 * FUNCTION
 *  applib_plmn_is_matched
 * DESCRIPTION
 *  This function matches the SIM PLMN and BCCH PLMN according to the 23.122,
 *  AnnexA (normative): HPLMN Matching Criteria. Additionally, it also
 *  considers the wild card mentioned in EF_OPL.
 * PARAMETERS
 *  sim_plmn            : [IN]      PLMN read from SIM
 *  bcch_plmn           : [IN]      PLMN from network
 *  is_band_pcs1900     : [IN]      Camp on PCS1900 or not
 * RETURNS
 *  On matched, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
extern kal_bool applib_plmn_is_matched(
    const kal_char *sim_plmn,
    const kal_char *bcch_plmn,
    kal_bool is_band_pcs1900);


#endif /* APP_PLMN_H */

