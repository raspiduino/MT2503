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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   l1cal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The structure definition of L1 calibration data
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef L1CAL_H
#define L1CAL_H

#include "m12190.h"
#include "m12197.h"
#include "kal_general_types.h"

/* ------------------------------------------------------------------------- */
typedef struct
{
   sAGCGAINOFFSET     agcPathLoss[FrequencyBandCount][PLTABLE_SIZE];
}l1cal_agcPathLoss_T;

typedef struct
{
   sLNAGAINOFFSET     lnaPathLoss[FrequencyBandCount][PLTABLE_SIZE];
}l1cal_lnaPathLoss_T;

typedef struct
{
   sRAMPDATA          rampData;
}l1cal_rampTable_T;

typedef struct
{
   kal_uint16         dacValue;
   kal_int32          slopeInv;
}l1cal_afcData_T;

typedef struct
{
   kal_int16 filter_coefficient[60];
}l1spfc_T;

typedef struct
{
   sBBTXParameters BBTXParameters;
}l1cal_txiq_T;
      
typedef struct
{   
   kal_uint8    interRampData[16];
}l1cal_interRampData_T;
         
#if defined(__EPSK_TX__) 
typedef struct
{   
   kal_uint8    EPSK_interRampData[4][16];
}l1cal_EPSK_interRampData_T;
#endif//(__EPSK_TX__) 
         
typedef struct
{  
   XO_SLOPE_AREA_DATA  XO_SlopeAreaData[XO_SlopeArea_Num]; 
}l1cal_crystalAfcData_T;

typedef struct
{  
   kal_int32 cap_id; 
}l1cal_crystalCapData_T;         
      
typedef struct
{
   sRFSpecialCoef RFSpecialCoef;
}l1cal_rfspecialcoef_T;

typedef struct
{   
   sTX_POWER_ROLLBACK   rollback_data[FrequencyBandCount];
}l1cal_tx_power_rollback_T;

typedef sTXPC_L1CAL l1cal_txpc_T;

/* API for meta DCS 2nd path TX power check */ 
void L1D_RF_Set_TX_Notch_Path( kal_uint8 notch_en );

#if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
typedef struct
{
   int start;                      // the special pattern of start position
   int version;                    // Struct Version ID
   int RF_Type;                    // RF type
   char is_data_update;            // default is false, and will be changed  as true after tool update
   sRF_BPI_VARIABLE                RF_BPI_Variable;
   sRF_TIMING_VARIABLE             RF_Timing_Variable;
   sRF_APC_COMPENSATE_VARIABLE     RF_APC_Compensate_Variable;
   sRF_PCL_VARIABLE                RF_PCL_Varaible;
   sRF_LBMOD_GC_VARIABLE           RF_Lbmod_GC_Variable;
   sRF_HBMOD_GC_VARIABLE           RF_Hbmod_GC_Variable;
   sRF_ITC_PCL_VARIABLE            RF_ITC_PCL_Variable;
   sRF_TX_POWERFEEDBACK_VARIABLE   RF_TX_PowerFeedback_Variable;
   sRF_RX_BAND_VARIABLE            RF_RX_Band_Variable;
   sRF_OTHERS_VARIABLE             RF_Others_Variable;
   sRF_AFC_TRACKING_VARIABLE       RF_AFC_Tracking_Variable;
   sRF_CLK_BUFFER_VARIABLE         RF_CLK_Buffer_Variable;
   int end;                        // the special pattern of end1 position
}l1d_rf_custom_input_data_T;
#endif

typedef sTEMPERATURE_ADC_L1CAL l1cal_temperatureADC_T;

/*****************************************************************************
* Typedef     : L1CalDataDlStatusQueryResult
* Group       : Real target, Internals, L1D/UL1D common operation
* Type        : enumeration
* Description : Define the constant value of return value for calibration
*               data item download status query function
*****************************************************************************/
typedef enum
{
   L1_CAL_DATA_CHECK_CODE_NOT_DOWNLOADED = 0,
   L1_CAL_DATA_CHECK_CODE_SUCCESS_DOWNLOADED,
   L1_CAL_DATA_CHECK_CODE_NO_NVRAM_LID_MATCHED,
   L1_CAL_DATA_CHECK_CODE_MAX

} L1CalDataDLStatusQueryResult;

typedef struct
{  
   kal_int32 cload_freq_offset; 
}l1cal_cload_freq_offset_T;

#endif
