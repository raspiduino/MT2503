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
 *  wndrv_cal.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  WLAN network driver calibration data structures
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _WNDRV_CAL_H
#define _WNDRV_CAL_H
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
typedef struct
{
   kal_uint8  mac_addr[ 6 ];
} wndrv_cal_mac_addr_struct;

typedef struct
{
   kal_uint8 CCKTxPWR[ 14 ];
   kal_uint8 OFDMTxPWR[ 14 ];
} wndrv_cal_txpwr_2400M_struct;

typedef struct
{
   kal_uint8 TxPWR[ 34 ];
} wndrv_cal_txpwr_5000M_struct;

typedef struct
{
   kal_uint8  i_ch_offset;
   kal_uint8  q_ch_offset;
} wndrv_cal_dac_dc_offset_struct;

typedef struct
{
    kal_uint8 txAlcCCK[14];
    kal_uint8 txOutputPowerDBCCK[14];
    kal_uint8 txAlcOFDM[8][14];
    kal_uint8 txOutputPowerDBOFDM[8][14];
} wndrv_cal_tx_ALC_2400M_struct;

typedef struct
{
    kal_uint8 alcSlop1Divider;
    kal_uint8 alcSlop1Dividend;
    kal_uint8 alcSlop2Divider;
    kal_uint8 alcSlop2Dividend;
} wndrv_cal_ALC_Slope_2400M_struct;

//20081117 add by saker
typedef struct
{
   kal_int8   cAbsTemp;
   kal_uint8  ucThermoValue; 
   kal_uint8  ucXtalTrim;
} wndrv_cal_setting_trim_thermo_struct;

typedef struct
{
   kal_uint8 ucTargetGainCCKInHalfDBm;	// in half dBm, ex. target gain CCK 17.5 dBm, this value should be 35
   kal_uint8 ucTargetGainOFDMInHalfDBm;	// in half dBm. ex. target gain OFDM 14 dBm, this value should be 28
   kal_uint8 ucBiasCCK2OFDMInHalfDBm;
   kal_uint8 ucInitalRefCodeword;
   kal_uint8 ucFirstRowPoutInHalfDBm;	// ex. the first row is 8.0 dBm, this value should be 8x2 = 16
   kal_uint8 ucTotalValidRows;	// Total number of valid rows
   kal_uint8 ucAlcAdcSwing; // ACDR1(0x0078h) bits[21-19] RG_VSRVDIFF[2:0]
   kal_uint8 ucAlcAdcDCbias;  // ACDR0(0x0074h) bits[23-20] RG_VSRVCM[3:0]
   kal_uint8 PAOutAlcAdcValue[30][3];	// Max 30 rows for CH1, CH7, CH13
} wndrv_cal_txpwr_cal_free_flow_struct;
#endif /* _WNDRV_CAL_H */
