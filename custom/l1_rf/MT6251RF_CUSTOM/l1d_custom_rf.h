/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   l1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6251
 *
 * Description:
 * ------------
 *   MT6251 RF constance defintion
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *
 *******************************************************************************/
#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */

#if !defined(MT6251RF_RF)
   #error "rf files mismatch with compile option!"
#endif

/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/ /*   Event Timing Define                                  */
/*MT6251RF*/ /*--------------------------------------------------------*/
/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*/ #define  QB_RX_FENA_2_FSYNC          48   /* this value shall be 4N+0  */
/*MT6251RF*/ #define  QB_RX_FSYNC_2_FENA           3   /* ori: 0                    */
/*MT6251RF*/ #define  QB_TX_FENA_2_FSYNC         120   /* this value shall be 4N+0  */
/*MT6251RF*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6251RF*/ 
/*MT6251RF*/
/*MT6251RF*/ #define  QB_SR0                     216
/*MT6251RF*/ #define  QB_SR1                     184
/*MT6251RF*/ #define  QB_SR2                      60   //must be 12QB earlier than QB_RX_FENA_2_FSYNC
/*MT6251RF*/ #define  QB_SR3                       6
/*MT6251RF*/ #define  QB_PR1                     245
/*MT6251RF*/ #define  QB_PR2                      33
/*MT6251RF*/ #define  QB_PR3                       6
/*MT6251RF*/ #if IS_MT6251_E1_FT
/*MT6251RF*/ #define  QB_ST0               (292+900)
/*MT6251RF*/ #else
/*MT6251RF*/ #define  QB_ST0                     325
/*MT6251RF*/ #endif
/*MT6251RF*/ #define  QB_ST1                     292
/*MT6251RF*/ #define  QB_ST2B                     92
/*MT6251RF*/ #define  QB_ST2                     138   //must be 18QB earlier than QB_TX_FENA_2_FSYNC
/*MT6251RF*/ #define  QB_ST3                      36   
/*MT6251RF*/ #define  QB_PT1                     245 
/*MT6251RF*/ #define  QB_PT2                      20 
/*MT6251RF*/ #define  QB_PT2B                     12    
/*MT6251RF*/ #define  QB_PT3                      25 
/*MT6251RF*/ #define  QB_APCON                    14   
/*MT6251RF*/ #define  QB_APCMID                   26 
/*MT6251RF*/ #define  QB_APCOFF                    9   
/*MT6251RF*/ #define  QB_APCDACON                 99
/*MT6251RF*/ #define  TX_PROPAGATION_DELAY        46
/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*//*--------------------------------------------------------*/
/*MT6251RF*//*   define  BPI data for MT6251                          */
/*MT6251RF*//*--------------------------------------------------------*/
/*MT6251RF*//*    PRCB : bit   pin                                    */
/*MT6251RF*//*            0    VC1     (GpCtrl0)                      */
/*MT6251RF*//*            1    VC2                                    */
/*MT6251RF*//*            2    PAEN                                   */
/*MT6251RF*//*            3    BANDSW  (GpCtrl1)                      */
/*MT6251RF*//*            4    not used                               */
/*MT6251RF*//*            5    not used                               */
/*MT6251RF*//*            6    not used                               */
/*MT6251RF*//*            7    not used                               */
/*MT6251RF*//*            8    not used                               */
/*MT6251RF*//*            9    not used                               */
/*MT6251RF*//*--------------------------------------------------------*/
/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*//*--------------------------------------------------------*/
/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*/ #define  PDATA_GSM850_PR1          0x009
/*MT6251RF*/ #define  PDATA_GSM850_PR2          0x009
/*MT6251RF*/ #define  PDATA_GSM850_PR3          0x000
/*MT6251RF*/ #define  PDATA_GSM850_PT1          0x000
/*MT6251RF*/ #define  PDATA_GSM850_PT2          0x009
/*MT6251RF*/ #define  PDATA_GSM850_PT2B         0x00C
/*MT6251RF*/ #define  PDATA_GSM850_PT3          0x000
/*MT6251RF*/ #define  PDATA_GSM_PR1             0x009
/*MT6251RF*/ #define  PDATA_GSM_PR2             0x009
/*MT6251RF*/ #define  PDATA_GSM_PR3             0x000
/*MT6251RF*/ #define  PDATA_GSM_PT1             0x000
/*MT6251RF*/ #define  PDATA_GSM_PT2             0x009
/*MT6251RF*/ #define  PDATA_GSM_PT2B            0x00C
/*MT6251RF*/ #define  PDATA_GSM_PT3             0x000
/*MT6251RF*/ #define  PDATA_DCS_PR1             0x008
/*MT6251RF*/ #define  PDATA_DCS_PR2             0x008
/*MT6251RF*/ #define  PDATA_DCS_PR3             0x000
/*MT6251RF*/ #define  PDATA_DCS_PT1             0x000
/*MT6251RF*/ #define  PDATA_DCS_PT2             0x008
/*MT6251RF*/ #define  PDATA_DCS_PT2B            0x00D
/*MT6251RF*/ #define  PDATA_DCS_PT3             0x000
/*MT6251RF*/ #define  PDATA_PCS_PR1             0x008
/*MT6251RF*/ #define  PDATA_PCS_PR2             0x008
/*MT6251RF*/ #define  PDATA_PCS_PR3             0x000
/*MT6251RF*/ #define  PDATA_PCS_PT1             0x000
/*MT6251RF*/ #define  PDATA_PCS_PT2             0x008
/*MT6251RF*/ #define  PDATA_PCS_PT2B            0x00D
/*MT6251RF*/ #define  PDATA_PCS_PT3             0x000
/*MT6251RF*/ #define  PDATA_INIT                0x000
/*MT6251RF*/ #define  PDATA_IDLE                0x000
/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*/ /*----------------------------------------------*/
/*MT6251RF*/ /*   APC Compensate Thresholds                  */
/*MT6251RF*/ /*----------------------------------------------*/
/*MT6251RF*/
/*MT6251RF*/ #define  SECONDS2FRAME(n)                     ((int)((n)*1000/4.615))
/*MT6251RF*/ #define  VOLT2UVOLT(n)                        ((int)((n)*1000000))
/*MT6251RF*/ #define  TEMP2MTEMP(n)                        ((int)((n)*1000))
/*MT6251RF*/
/*MT6251RF*/ #define  BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*MT6251RF*/ #define  BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6251RF*/ #define  BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*MT6251RF*/ #define  BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*MT6251RF*/
/*MT6251RF*/ #define  BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*MT6251RF*/ #define  BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6251RF*/ #define  BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*MT6251RF*/ #define  BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*MT6251RF*/
/*MT6251RF*/
/*MT6251RF*/ /*----------------------------------------------*/
/*MT6251RF*/ /*   Crystal parameter                          */
/*MT6251RF*/ /*----------------------------------------------*/
/*MT6251RF*/
/*MT6251RF*/ #define Custom_RF_XO_CapID      180
/*MT6251RF*/ /*----------------------------------------------*/
/*MT6251RF*/ /*   0:GSM850 Signal go through GSM850, GSM900 Signal go through GSM900  (default)     */
/*MT6251RF*/ /*   1:GSM850 Signal go through GSM900, GSM900 Signal go through GSM850  (default)     */
/*MT6251RF*/ /*----------------------------------------------*/
/*MT6251RF*/ #define GSM850_GSM900_SWAP      0
/*MT6251RF*/ /*----------------------------------------------*/
/*MT6251RF*/ /*   0:DCS1800 Signal go through DCS1800, PCS1900 Signal go through PCS1900(default)   */
/*MT6251RF*/ /*   1:DCS1800 Signal go through PCS1900, PCS1900 Signal go through DCS1800            */
/*MT6251RF*/ /*----------------------------------------------*/
/*MT6251RF*/ #define DCS1800_PCS1900_SWAP    0

#endif /* _L1D_CUSTOM_RF_H_ */

