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
 * custom_gas_config.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the GAS configuration.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_general_types.h"

/* For customer define the L2 fill bits randomization setting, TRUE: enable, FALSE: disable(default setting) */
#define L2_FILL_BITS_RANDOMIZATION_SETTING  KAL_FALSE

/* STORED List will be update in NVRAM every time there is change in stored List */
kal_bool gas_custom_update_nvram_ba_always = KAL_FALSE;

/* This is the time duration for which a Cell remains bar due to IMA REJ */
/* In unit of SECONDS , range 1 to 600, 300 = 5 minute */
kal_uint16 gas_custom_ima_rej_bar_duration = 300;

/* This value will set the maximum number of IMA_REJ before RR bar a cell */
/* range 1 to 10 */
kal_uint8 gas_custom_max_ima_rej_block_for_cell_bar = 2;

kal_uint16 gas_custom_ima_rej_monitor_duration = 60;




/* This is the time duration for which a Cell remains bar due to T3168 T3164 failures */
/* In unit of SECONDS , range 1 to 600, 300 = 5 minute */
kal_uint16 gas_custom_t3168_t3164_exp_bar_duration = 300;

/* This value will set the maximum number of T3168 T3164 failures before RR bar a cell */
/* range 1 to 10 */
kal_uint8 gas_custom_max_t3168_t3164_exp_cnt_for_cell_bar = 4;

kal_uint16 gas_custom_t3168_t3164_exp_monitor_duration = 60;



/* This is the time duration for which a Cell remains bar due to rACH failure */
/* In unit of SECONDS , range 1 to 60 , 30 = 30 seconds */
kal_uint16 gas_custom_rach_fail_bar_duration = 30;

/* This value will set the maximum number of RACH failures before RR bar a cell */
/* range 1 to 10 */
kal_uint8 gas_custom_max_rach_fail_cnt_for_cell_bar = 3;

kal_uint16 gas_custom_rach_fail_monitor_duration = 60;

/* customer can set whether enable avoid fake cell feature. */
#define ENABLE_AVOID_FAKE_CELL_FEATURE KAL_TRUE
#define DISABLE_AVOID_FAKE_CELL_FEATURE KAL_FALSE
kal_bool gas_custom_fake_cell_feature = DISABLE_AVOID_FAKE_CELL_FEATURE;

/* Customer can set the total number of frequencies which are scanned for full band PLMN search/list. */
kal_uint16 gas_custom_max_arfcn_to_try = 100;

/* Customer can set the number of GSM cells of each GSM band to decode for PLMN search
* or PLMN List procedure. The impact is that the larger the number, the result will be more
* sensative under that environment, but it will spend longer time to finish the procedure.
* Please do not assign each value more than 255.
*/
kal_uint8 gas_custom_max_decoded_cell_a_band[] =
{
    32, /* PGSM900 */
    32, /* EGSM900 */
    32, /* RGSM900 */
    32, /* DCS1800 */
    32, /* PCS1900 */
    32, /* GSM450  */
    32, /* GSM480  */
    32  /* GSM850  */
};


/*If this flag is set to FULL_BAND_SCAN_PREFERED then RR will always perform Full Band Scan, 
 *Working Band scans will not be performed */
#define WORKING_BAND_SCAN_PREFERED 0x00
#define FULL_BAND_SCAN_PREFERED    0x01
kal_uint8 gas_custom_prefered_band_scan_mode = WORKING_BAND_SCAN_PREFERED;

/*****************************************************************************
* FUNCTION
*  rr_get_l2_fill_bits_randomization_setting
* DESCRIPTION
*   This function is used to define the L2 fill bits randomization setting
*   TRUE: enable L2 randomization, FALSE: disable L2 randomization
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool rr_get_l2_fill_bits_randomization_setting (void)
{
   return (L2_FILL_BITS_RANDOMIZATION_SETTING);
}

/*****************************************************************************
* FUNCTION
*  gas_custom_get_fake_cell_feature_mode
* DESCRIPTION
*   The function get fake cell feature mode.
*
* PARAMETERS
*   Void
* RETURNS
*   kal_bool
*   TRUE: enable fake cell feature, FALSE: disable fake cell feature.
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool gas_custom_get_fake_cell_feature_mode (void)
{
    return gas_custom_fake_cell_feature;
}

//#if defined(__GPS_TRACK__)
/******************************************************************************
 *  Function    -  track_custom_fake_cell_feature_enable
 * 
 *  Purpose     -  伪基站使能接口
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2016-09-27,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_bool track_custom_fake_cell_feature_enable (kal_uint8 enable)
{
    if(enable ==0)
    {
        gas_custom_fake_cell_feature =DISABLE_AVOID_FAKE_CELL_FEATURE;
    }
    else if (enable ==1)
    {
        gas_custom_fake_cell_feature =ENABLE_AVOID_FAKE_CELL_FEATURE;
    }

    return gas_custom_fake_cell_feature;
}

extern void track_cust_fake_cell_msg(kal_uint16 arfcn);
//#endif
void gas_custom_fakecell_to_user(kal_uint16 arfcn)
{

/* the code shall be added by the customer */
//#if defined(__GPS_TRACK__)

    track_cust_fake_cell_msg(arfcn);
//#endif
}

/*****************************************************************************
* FUNCTION
*  gas_custom_is_working_band_scan_allowed
* DESCRIPTION
*   The function get fake cell feature mode.
*
* PARAMETERS
*   Void
* RETURNS
*   kal_bool
*   TRUE: .
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool gas_custom_is_working_band_scan_allowed(void)
{
    if (gas_custom_prefered_band_scan_mode == FULL_BAND_SCAN_PREFERED)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}


