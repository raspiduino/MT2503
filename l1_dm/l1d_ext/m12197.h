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
 *   m12197.h
 *
 * Project:
 * --------
 *   MT6573
 *
 * Description:
 * ------------
 *   ModemBinUpdate feature
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
*******************************************************************************/
#include "m12190.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2

#define RFDEF       0xABCD
#define RFDEF_short 0xAB

typedef    unsigned char           uint8;
typedef    unsigned short          uint16;
typedef    unsigned long           uint64;
typedef      signed char           int8;
typedef      signed short          int16;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int16 xPDATA_GSM850_PR1;
   int16 xPDATA_GSM850_PR2;
   int16 xPDATA_GSM850_PR2B;
   int16 xPDATA_GSM850_PR3;
   int16 xPDATA_GSM850_PR3A;
   int16 xPDATA_GSM850_PT1;
   int16 xPDATA_GSM850_PT2;
   int16 xPDATA_GSM850_PT2B;
   int16 xPDATA_GSM850_PT3;
   int16 xPDATA_GSM850_PT3A;
   int16 xPDATA_GSM_PR1;
   int16 xPDATA_GSM_PR2;
   int16 xPDATA_GSM_PR2B;
   int16 xPDATA_GSM_PR3;
   int16 xPDATA_GSM_PR3A;
   int16 xPDATA_GSM_PT1;
   int16 xPDATA_GSM_PT2;
   int16 xPDATA_GSM_PT2B;
   int16 xPDATA_GSM_PT3;
   int16 xPDATA_GSM_PT3A;
   int16 xPDATA_DCS_PR1;
   int16 xPDATA_DCS_PR2;
   int16 xPDATA_DCS_PR2B;
   int16 xPDATA_DCS_PR3;
   int16 xPDATA_DCS_PR3A;
   int16 xPDATA_DCS_PT1;
   int16 xPDATA_DCS_PT2;
   int16 xPDATA_DCS_PT2B;
   int16 xPDATA_DCS_PT3;
   int16 xPDATA_DCS_PT3A;
   int16 xPDATA_PCS_PR1;
   int16 xPDATA_PCS_PR2;
   int16 xPDATA_PCS_PR2B;
   int16 xPDATA_PCS_PR3;
   int16 xPDATA_PCS_PR3A;
   int16 xPDATA_PCS_PT1;
   int16 xPDATA_PCS_PT2;
   int16 xPDATA_PCS_PT2B;
   int16 xPDATA_PCS_PT3;
   int16 xPDATA_PCS_PT3A;
   int16 xPDATA_GSM850_PR2M1;
   int16 xPDATA_GSM850_PR2M2;
   int16 xPDATA_GSM850_PR2M3;
   int16 xPDATA_GSM850_PT2M1_G8;
   int16 xPDATA_GSM850_PT2M2_G8;
   int16 xPDATA_GSM850_PT2M3_G8;
   int16 xPDATA_GSM850_PT2M1_8G;
   int16 xPDATA_GSM850_PT2M2_8G;
   int16 xPDATA_GSM850_PT2M3_8G;
   int16 xPDATA_GSM_PR2M1;
   int16 xPDATA_GSM_PR2M2;
   int16 xPDATA_GSM_PR2M3;
   int16 xPDATA_GSM_PT2M1_G8;
   int16 xPDATA_GSM_PT2M2_G8;
   int16 xPDATA_GSM_PT2M3_G8;
   int16 xPDATA_GSM_PT2M1_8G;
   int16 xPDATA_GSM_PT2M2_8G;
   int16 xPDATA_GSM_PT2M3_8G;
   int16 xPDATA_DCS_PR2M1;
   int16 xPDATA_DCS_PR2M2;
   int16 xPDATA_DCS_PR2M3;
   int16 xPDATA_DCS_PT2M1_G8;
   int16 xPDATA_DCS_PT2M2_G8;
   int16 xPDATA_DCS_PT2M3_G8;
   int16 xPDATA_DCS_PT2M1_8G;
   int16 xPDATA_DCS_PT2M2_8G;
   int16 xPDATA_DCS_PT2M3_8G;
   int16 xPDATA_PCS_PR2M1;
   int16 xPDATA_PCS_PR2M2;
   int16 xPDATA_PCS_PR2M3;
   int16 xPDATA_PCS_PT2M1_G8;
   int16 xPDATA_PCS_PT2M2_G8;
   int16 xPDATA_PCS_PT2M3_G8;
   int16 xPDATA_PCS_PT2M1_8G;
   int16 xPDATA_PCS_PT2M2_8G;
   int16 xPDATA_PCS_PT2M3_8G;
   int16 xPDATA_INIT;
   int16 xPDATA_IDLE;
   int16 xPDATA_GMSK;
   int16 xPDATA_8PSK;
}sRF_BPI_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int16 xQB_SR0;    //OH
   int16 xQB_SR1;
   int16 xQB_SR2;
   int16 xQB_SR3;
   int16 xQB_SR2M;
   int16 xQB_PR1;
   int16 xQB_PR2;
   int16 xQB_PR2B;
   int16 xQB_PR3;
   int16 xQB_PR3A;
   int16 xQB_PR2M1;
   int16 xQB_PR2M2;
   int16 xQB_ST0;  //OH
   int16 xQB_ST1;
   int16 xQB_ST2;
   int16 xQB_ST2B;
   int16 xQB_ST3;
   int16 xQB_ST2M_G8;
   int16 xQB_ST2M_8G;
   int16 xQB_PT1;
   int16 xQB_PT2;
   int16 xQB_PT2B;
   int16 xQB_PT3;
   int16 xQB_PT3A;
   int16 xQB_PT2M1_G8;
   int16 xQB_PT2M2_G8;
   int16 xQB_PT2M3_G8;
   int16 xQB_PT2M1_8G;
   int16 xQB_PT2M2_8G;
   int16 xQB_PT2M3_8G;
   int16 xQB_APCON;
   int16 xQB_APCMID;
   int16 xQB_APCOFF;
   int16 xQB_APCDACON; //OH
} sRF_TIMING_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int xBAT_VOLTAGE_SAMPLE_PERIOD;
   int xBAT_VOLTAGE_AVERAGE_COUNT;
   int xBAT_TEMPERATURE_SAMPLE_PERIOD;
   int xBAT_TEMPERATURE_AVERAGE_COUNT;
   int xBAT_LOW_VOLTAGE;
   int xBAT_HIGH_VOLTAGE;
   int xBAT_LOW_TEMPERATURE;
   int xBAT_HIGH_TEMPERATURE;
   int xRF_TEMPERATURE_SAMPLE_PERIOD;     //OH
   int xRF_TEMPERATURE_AVERAGE_COUNT;     //OH
} sRF_APC_COMPENSATE_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int16 txios_highpcl_850_GMSK;
   int16 txios_highpcl_900_GMSK;
   int16 txios_highpcl_DCS_GMSK;
   int16 txios_highpcl_PCS_GMSK;
   int16 txios_highpcl_850_EPSK;
   int16 txios_highpcl_900_EPSK;
   int16 txios_highpcl_DCS_EPSK;
   int16 txios_highpcl_PCS_EPSK;
   int16 txios_lowpcl_850_GMSK;
   int16 txios_lowpcl_900_GMSK;
   int16 txios_lowpcl_DCS_GMSK;
   int16 txios_lowpcl_PCS_GMSK;
   int16 txios_lowpcl_850_EPSK;
   int16 txios_lowpcl_900_EPSK;
   int16 txios_lowpcl_DCS_EPSK;
   int16 txios_lowpcl_PCS_EPSK;

}sRF_PCL_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int16 lbmod_gc_highpcl_850_GMSK;
   int16 lbmod_gc_highpcl_900_GMSK;
   int16 lbmod_gc_highpcl_DCS_GMSK;
   int16 lbmod_gc_highpcl_PCS_GMSK;
   int16 lbmod_gc_highpcl_850_EPSK;
   int16 lbmod_gc_highpcl_900_EPSK;
   int16 lbmod_gc_highpcl_DCS_EPSK;
   int16 lbmod_gc_highpcl_PCS_EPSK;
   int16 lbmod_gc_lowpcl_850_GMSK;
   int16 lbmod_gc_lowpcl_900_GMSK;
   int16 lbmod_gc_lowpcl_DCS_GMSK;
   int16 lbmod_gc_lowpcl_PCS_GMSK;
   int16 lbmod_gc_lowpcl_850_EPSK;
   int16 lbmod_gc_lowpcl_900_EPSK;
   int16 lbmod_gc_lowpcl_DCS_EPSK;
   int16 lbmod_gc_lowpcl_PCS_EPSK;
}sRF_LBMOD_GC_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int16 hbmod_gc_highpcl_850_GMSK;
   int16 hbmod_gc_highpcl_900_GMSK;
   int16 hbmod_gc_highpcl_DCS_GMSK;
   int16 hbmod_gc_highpcl_PCS_GMSK;
   int16 hbmod_gc_highpcl_850_EPSK;
   int16 hbmod_gc_highpcl_900_EPSK;
   int16 hbmod_gc_highpcl_DCS_EPSK;
   int16 hbmod_gc_highpcl_PCS_EPSK;
   int16 hbmod_gc_lowpcl_850_GMSK;
   int16 hbmod_gc_lowpcl_900_GMSK;
   int16 hbmod_gc_lowpcl_DCS_GMSK;
   int16 hbmod_gc_lowpcl_PCS_GMSK;
   int16 hbmod_gc_lowpcl_850_EPSK;
   int16 hbmod_gc_lowpcl_900_EPSK;
   int16 hbmod_gc_lowpcl_DCS_EPSK;
   int16 hbmod_gc_lowpcl_PCS_EPSK;

}sRF_HBMOD_GC_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int16 txitc_highpcl_850_GMSK;
   int16 txitc_highpcl_900_GMSK;
   int16 txitc_highpcl_DCS_GMSK;
   int16 txitc_highpcl_PCS_GMSK;
   int16 txitc_highpcl_850_EPSK;
   int16 txitc_highpcl_900_EPSK;
   int16 txitc_highpcl_DCS_EPSK;
   int16 txitc_highpcl_PCS_EPSK;
   int16 txitc_lowpcl_850_GMSK;
   int16 txitc_lowpcl_900_GMSK;
   int16 txitc_lowpcl_DCS_GMSK;
   int16 txitc_lowpcl_PCS_GMSK;
   int16 txitc_lowpcl_850_EPSK;
   int16 txitc_lowpcl_900_EPSK;
   int16 txitc_lowpcl_DCS_EPSK;
   int16 txitc_lowpcl_PCS_EPSK;
}sRF_ITC_PCL_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int8 xCLOSED_LOOP_TXPC_TYPE;      //OH
   int16 xQB_TX_SAMPLE_OFFSET_GMSK;   //OH
   int16 xQB_TX_SAMPLE_OFFSET_EPSK;   //OH
   int16 xTXPC_EPSK_TP_SLOPE_LB;      //OH
   int16 xTXPC_EPSK_TP_SLOPE_HB;      //OH
} sRF_TX_POWERFEEDBACK_VARIABLE;      //OH
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   int xXO_CapID;
   int16 xafc_dac_default;
   int16 xafc_inv_slope;
   int8 xEGSM_DISABLE;
   uint8 xGSM850_GSM900_SWAP;
   uint8 xDCS1800_PCS1900_SWAP;
   uint8 xGSM_ERR_DET_ID; //OH
   int16 xTX_PROPAGATION_DELAY;
   int16 xTQ_EPSK_TX_DELAY;
} sRF_OTHERS_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   unsigned long xGSM850_PATH_SEL;
   unsigned long xGSM_PATH_SEL;
   unsigned long xDCS_PATH_SEL;
   unsigned long xPCS_PATH_SEL;
}sRF_RX_BAND_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   uint8  xAFC_PREDICTION_ON;
   uint16 xAFC_PREDICTION_INTERVAL;
   uint8  xAFC_PREDICTION_DECAYING_FACTOR;
}sRF_AFC_TRACKING_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct
{
   uint8 xCLK1_EN;
   uint8 xCLK2_EN;
   uint8 xCLK3_EN;
}sRF_CLK_BUFFER_VARIABLE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

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
}sL1D_RF_CUSTOM_INPUT_DATA;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

extern sL1D_RF_CUSTOM_INPUT_DATA l1d_rf_custom_input_data;
extern void L1D_RF_Custom_Timing_DefaultValue_Handler(void);
extern void L1D_RF_Custom_BPI_DefaultValue_Handler(void);
extern void L1D_RF_Custom_TX_PCL_DefaultValue_Handler(void);
extern void L1D_RF_Custom_APC_Compensate_DefaultValue_Handler(void);
extern void L1D_RF_Custom_TX_Power_Control_DefaultValue_Handler(void);
extern void L1D_RF_Custom_RF_RX_Band_DefaultValue_Handler(void);
extern void L1D_RF_Custom_Others_DefaultValue_Handler(void);
extern void L1D_RF_Custom_AFC_Tracking_DefaultValue_Handler(void);
extern void L1D_RF_Custom_RF_CLK_Buffer_Variable_DefaultValue_Handler(void);
extern void BPI_Default_Setting(uint16 *dst, uint16 defaultvalue);
extern void Timing_Default_Setting(int16 *dst, int16 defaultvalue);
extern void TX_Default_Setting(int16 *dst, int16 defaultvalue);
extern void Default_Setting_uint8(uint8 *dst, uint8 defaultvalue);
extern void Default_Setting_int8(int8 *dst,int8 defaultvalue);
extern void Default_Setting_int16(int16 *dst, int16 defaultvalue);
extern void L1D_RF_Custom_Others_Update( void );
#endif


