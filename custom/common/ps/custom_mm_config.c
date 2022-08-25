/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_mm_config.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the MM configuration.
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "custom_mm_config.h"
#include "stdlib.h"

/*****************************************************************************
* FUNCTION
*  mm_custom_stay_on_la_of_regional_provisional_service
* DESCRIPTION
*  This function is for customize MM behavior when entering forbidden LA of #12
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE for following spec (enter limited service and stay on forbidden LA of #12)
*  KAL_FALSE will allow MS retry other PLMN/RAT for normal service
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool mm_custom_stay_on_la_of_regional_provisional_service(void)
{
  //suggest to use default setting [KAL_TRUE], change this setting might affect the result of FTA or IOT.
  //may only be changed on production version of software after pass all lab test
   return KAL_TRUE;
}  

/*****************************************************************************
* FUNCTION
*  mm_custom_allow_rplmn_hplmn_combined_search
* DESCRIPTION
*  This function is used to configure whether search RPLMN and HPLMN together.
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_allow_rplmn_hplmn_combined_search(void)
{
    /*if search RPLMN and HPLMN together, it is more quickly to camp on HPLMN,
    and no need to do high priority plmn search later.
    But it may disobey test case 6.2.1.1 in spec 34.123. 
    */
    #ifdef __UMTS_TDD128_MODE__  /*for TDD project, this compile option is open*/
        return KAL_FALSE;
    #else
        return KAL_TRUE;
    #endif
} 

/* MAUI_03014009 Russia Operator BeeLine request to use ECC with IMEI */
/*****************************************************************************
* FUNCTION
*  mm_custom_force_ecc_with_imei
* DESCRIPTION
*  This function configures emergency call force to use IMEI during phone lock period.
*  default: KAL_FALSE (using TMSI->IMSI->IMEI)
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_force_ecc_with_imei(void)
{
    return KAL_FALSE;
}

/*************************************************************************
 * International Higher Priorirty PLMN Search
 * 
 * [Important!] Enable this option will violate TS23.122 and thus fail FTA cases
 *
 * - RPLMN_MCC_LIST / HPPLMN_MCC_LIST:
 *   - The UE is allowed to perform international HPPLMN search when the UE
 *     1. registers on a PLMN belonging to one of the MCCs defined in RPLMN_MCC_LIST, and
 *     2. the HPPLMN belongs to one of the MCCs defined in HPPLMN_MCC_LIST
 *
 * - If the MCC of RPLMN or HPPLMN is not restricted
 *   - RPLMN_MCC_LIST or HPPLMN_MCC_LIST shall contain only one entry {ALL_MCC_ALLOWED}
 *
 * - If the UE is not allowed to perform international HPPLMN search
 *   - RPLMN_MCC_LIST and HPPLMN_MCC_LIST shall contain only one entry {NO_MCC_ALLOWED}
 *************************************************************************/

/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to any MCC, and 
 *  2. the HPPLMN belongs to any MCC
 */
#if defined (__HPPLMN_REGARDLESS_ANY_MCC__)
const kal_uint32 RPLMN_MCC_LIST[] = {ALL_MCC_ALLOWED};
const kal_uint32 HPPLMN_MCC_LIST[] = {ALL_MCC_ALLOWED};

/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to US/Canada/Mexico/British Virgin Islands, and 
 *  2. the HPPLMN belongs to any MCC
 */
#elif defined(__ATNT_HPPLMN_SEARCH__)
const kal_uint32 RPLMN_MCC_LIST[] = {310, 311, 312, 313, 314, 315, 316, 302, 334, 348};
const kal_uint32 HPPLMN_MCC_LIST[] = {ALL_MCC_ALLOWED};

/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to US, and 
 *  2. the HPPLMN belongs to Canada
 */
#elif defined(__MM_INTERNATIONAL_HPPLMN_SEARCH__)
const kal_uint32 RPLMN_MCC_LIST[] = {310, 311, 312, 313, 314, 315, 316};
const kal_uint32 HPPLMN_MCC_LIST[] = {302};

/* The UE is not allowed to perform international HPPLMN search */
#else
const kal_uint32 RPLMN_MCC_LIST[] = {NO_MCC_ALLOWED};
const kal_uint32 HPPLMN_MCC_LIST[] = {NO_MCC_ALLOWED};
#endif

const kal_uint32 RPLMN_MCC_NUM = sizeof(RPLMN_MCC_LIST)/sizeof(kal_uint32);
const kal_uint32 HPPLMN_MCC_NUM = sizeof(HPPLMN_MCC_LIST)/sizeof(kal_uint32);

/*****************************************************************************
* FUNCTION
*   mm_custom_state_after_lu_abnormal
*
* DESCRIPTION
*   According to 3GPP TS24.008 4.4.4.9, the UE may enter the MM IDLE sub-state ATTEMPTING TO UPDATE or
*   optionally the MM IDLE sub-state PLMN SEARCH after LU abnormal 4 times.
*
* PARAMETERS
*   none
*
* RETURNS
*   MM_ENTER_STATE_DEPEND_ON_CONDITION  - Default behavior
*   MM_ENTER_STATE_PLMN_SEARCH          - Always enter MM IDLE sub-state PLMN SEARCH and perform PLMN selection
*   MM_ENTER_STATE_ATTEMPTING_TO_UPDATE - Always enter MM IDLE sub-state ATTEMPTING TO UPDATE and stay on current cell
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
mm_state_after_lu_abnormal_enum mm_custom_state_after_lu_abnormal(void)
{
#ifdef __MM_PERFORM_PLMN_SEARCH_AFTER_LU_ABNORMAL__
    return MM_ENTER_STATE_PLMN_SEARCH;
#else
    return MM_ENTER_STATE_DEPEND_ON_CONDITION;
#endif
}


/*****************************************************************************
* FUNCTION
*   mm_custom_is_try_abnormal_lai_once_more
* DESCRIPTION
*   If abnormal LU 4 times happen, MS will try to search other available and allowable PLMNs. If no other PLMN is found,
*   MS will go back to the abnormal-4-times PLMN and do registration with another 4 attempts.
*
* PARAMETERS
*   none
* RETURNS
*   kal_bool - indicate if "try abnormal lai once more" is enabled.
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mm_custom_is_try_abnormal_lai_once_more(void)
{
#ifdef __MM_TRY_ABNORMAL_LAI_ONCE_MORE__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

/*****************************************************************************
* FUNCTION
*   mm_custom_disable_display_roaming_hplmn_in_eplmn
* DESCRIPTION
*   If TRUE - disable displaying "R" when HPLMN is in EPLMN list
*   If FALSE - display "R" when HPLMN is in EPLMN list
*
* PARAMETERS
*   none
* RETURNS
*   kal_bool - indicate if "disable display roaming when hplmn is in eplmn" is enabled.
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mm_custom_disable_display_roaming_hplmn_in_eplmn(void)
{
#ifdef __DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

/*****************************************************************************
* FUNCTION
*   mm_custom_disable_rplmn_from_gloci
* DESCRIPTION
*   If TRUE - do not consider RPLMN information from GLOCI file
*   If FALSE - consider GLOCI file to derive RPLMN information
*
* PARAMETERS
*   none
* RETURNS
*   kal_bool - indicate if need to consider the GLOCI file for RPLMN information
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mm_custom_disable_rplmn_from_gloci(void)
{
#ifdef __DISABLE_RPLMN_FROM_GLOCI__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

/*****************************************************************************
* FUNCTION
*  mm_custom_start_t3240_for_page
* DESCRIPTION
*  This function is used to configure whether start T3240 for page.
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool mm_custom_start_t3240_for_page(void)
{
    /*work around CMCC 3G network issue
    1. PS signaling exist, receive page for CS domain
    2. send page response, enter MM_WAIT_FOR_NETWORK_COMMAND
    3. handover to another LA, then no MM or CM message from network
    4. can not process CM request until cs signaling or RRC release
    */
    return KAL_TRUE;
}

/*************************************************************************
 * HPLMN matching criteria enhance and customized equivalent PLMN definition
 * 
 * [Important!] Inappropriate setting may violate spec and thus fail FTA cases
 *
 * - CUSTOM_EQ_PLMN[]
 *   Ex: CUSTOM_EQ_PLMN[] = 
 *           {"001010", "00101F", "00202F", CUSTOM_EQ_PLMN_SET_END, //the first 3 PLMNs are regarded as eqivalent to each other
 *            "100011", "10002F", CUSTOM_EQ_PLMN_SET_END}           //100011 and 10002F are regarded as equivalent. 
 *************************************************************************/
#ifdef __TMO_PLMN_MATCHING__
/*  Regards 31026F and 310260 as eqivalent. To allow cell reselection between 310260 and 31026F (T-Mobile)  */
const char *CUSTOM_EQ_PLMN[] = {"31026F", "310260", CUSTOM_EQ_PLMN_SET_END};

#else
/* Default. Follows TS23.122 Annex A. Eg. In 310260, MS can reselect to 31026F. 
 * But if in 31026F, MS can't reselect to 310260. 
 */
const char *CUSTOM_EQ_PLMN[] = {CUSTOM_EQ_PLMN_SET_END};
#endif

const kal_uint32 CUSTOM_EQ_PLMN_NUM = sizeof(CUSTOM_EQ_PLMN)/sizeof(char *);


/*************************************************************************
 * After abnormal LU 4 times, UE should wait T3212 timeout and then start next LU attempt round.
 * Customization can be done here. Config the RETRY_ABNORMAL_LAI timer value as below. UE will 
 * start the next LU attempt when the RETRY_ABNORMAL_LAI timer expires.
 *************************************************************************/
#if defined(__MM_DISABLE_RETRY_ABNORMAL_LAI__)
/* do not perform LU until T3212 timeout */
const kal_uint32 MM_RETRY_ABNORMAL_LAI_TIMER_PERIOD = MM_INVALID_TIMER_VALUE;

#else
/* default value: 10 minutes */
const kal_uint32 MM_RETRY_ABNORMAL_LAI_TIMER_PERIOD = 10 * KAL_TICKS_1_MIN;
#endif


kal_uint8 mm_custom_get_max_attach_attempt_count()
{
    kal_uint8 max_attach_attempt_count = 5;
#ifdef __MM_FAST_RETRY_ON_LOWER_LAYER_FAILURE__
    max_attach_attempt_count = 10;
#endif
    return max_attach_attempt_count;
}

kal_uint32 mm_custom_get_t3311_timer_period_for_attach()
{
    kal_uint32 t3311_timer_period_for_attach = 15;
#ifdef __MM_FAST_RETRY_ON_LOWER_LAYER_FAILURE__
    // Random value between 3 to 7
    t3311_timer_period_for_attach = (rand() % 5) + 3;
#endif
    return t3311_timer_period_for_attach * KAL_TICKS_1_SEC;
}

