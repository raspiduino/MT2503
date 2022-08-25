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
 *   MT6261
 *
 * Description:
 * ------------
 *   MT6261 RF constance definition
 *
 * Author:
 * -------
 *
 *
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */

#if( (!defined(MT2503RF_RF)) )
   #error "rf files mismatch with compile option!"
#endif

/*MT6261RF*/
/*MT6261RF*/ /*--------------------------------------------------------*/
/*MT6261RF*/ /*   Event Timing Define                                  */
/*MT6261RF*/ /*--------------------------------------------------------*/
/*MT6261RF*/ #define  QB_SR0                     213 /* QB_PR1 and QB_PR2 should be larger than (QB_SR0 - 30)  */
/*MT6261RF*/ #define  QB_SR1                     140
/*MT6261RF*/ #define  QB_SR2                      70 /* QB_RX_FENA_2_FSYNC (48) should be <= (QB_SR2 -12)      */
/*MT6261RF*/ #define  QB_SR3                       4 /* QB_RX_FSYNC_2_FENA ( 3) should be <= (QB_SR3    )      */
/*MT6261RF*/ #define  QB_SR2M                     44
/*MT6261RF*/ #define  QB_PR1                     188 /* QB_PR1 should be larger than (QB_SR0 - 30)             */
/*MT6261RF*/ #define  QB_PR2                     185 /* QB_PR2 should be larger than (QB_SR0 - 30)             */
/*MT6261RF*/ #define  QB_PR3                       6
/*MT6261RF*/
/*MT6261RF*/ #define  QB_ST0                     325
/*MT6261RF*/ #define  QB_ST1                     280
/*MT6261RF*/ #define  QB_ST2B                     52 /* QB_TX_FENA_2_FSYNC (40) should be <= (QB_ST2B-12)      */ /* QB_ST2B should be < 75 */
/*MT6261RF*/ #define  QB_ST3                      38 /* QB_TX_FSYNC_2_FENA (27) should be <= (QB_ST3 -11)      */
/*MT6261RF*/ #define  QB_PT1                     245
/*MT6261RF*/ #define  QB_PT2                      20
/*MT6261RF*/ #define  QB_PT2B                     17
/*MT6261RF*/ #define  QB_PT3                      28
/*MT6261RF*/
/*MT6261RF*/ #define  QB_APCON                    14
/*MT6261RF*/ #define  QB_APCMID                   26
/*MT6261RF*/ #define  QB_APCOFF                   14
/*MT6261RF*/ #define  QB_APCDACON                 18
/*MT6261RF*/ #define  TX_PROPAGATION_DELAY        50
/*MT6261RF*/
/*MT6261RF*/ /*--------------------------------------------------------*/
/*MT6261RF*/ /*   define BPI data for MT6261                           */
/*MT6261RF*/ /*--------------------------------------------------------*/
/*MT6261RF*/ /*    PRCB : bit   pin                                    */
/*MT6261RF*/ /*            0    BANDSW   - RF7176 GpCtrl0              */
/*MT6261RF*/ /*            1    TX_EN    - RF7176 TX ENABLE            */
/*MT6261RF*/ /*            2    not used                               */
/*MT6261RF*/ /*            3    not used                               */
/*MT6261RF*/ /*            4    not used                               */
/*MT6261RF*/ /*            5    not used                               */
/*MT6261RF*/ /*            6    not used                               */
/*MT6261RF*/ /*            7    not used                               */
/*MT6261RF*/ /*            8    not used                               */
/*MT6261RF*/ /*            9    not used                               */
/*MT6261RF*/ /*--------------------------------------------------------*/
/*MT6261RF*/
#if defined(__RF_6625E__)
/*MT6261RF                      */
/*MT6261RF*/ /*--------------------------------------------------------*/
/*MT6261RF*/
/*MT6261RF*/ #define GSM_TX                                0x06
/*MT6261RF*/ #define GSM_RX                                0x05

/*MT6261RF*/ #define DCS_TX                                0x07
/*MT6261RF*/ #define DCS_RX                                0x04

/*MT6261RF*/ #define  PDATA_GSM850_PR1          0x005           
/*MT6261RF*/ #define  PDATA_GSM850_PR2          0x005
/*MT6261RF*/ #define  PDATA_GSM850_PR3          0x000
/*MT6261RF*/ #define  PDATA_GSM850_PT1          0x000
/*MT6261RF*/ #define  PDATA_GSM850_PT2          0x005           
/*MT6261RF*/ #define  PDATA_GSM850_PT2B         0x006
/*MT6261RF*/ #define  PDATA_GSM850_PT3          0x000
/*MT6261RF*/
/*MT6261RF*/ #define  PDATA_GSM_PR1             0x005                
/*MT6261RF*/ #define  PDATA_GSM_PR2             0x005
/*MT6261RF*/ #define  PDATA_GSM_PR3             0x000
/*MT6261RF*/ #define  PDATA_GSM_PT1             0x000
/*MT6261RF*/ #define  PDATA_GSM_PT2             0x005                
/*MT6261RF*/ #define  PDATA_GSM_PT2B            0x006
/*MT6261RF*/ #define  PDATA_GSM_PT3             0x000
/*MT6261RF*/
/*MT6261RF*/ #define  PDATA_DCS_PR1             0x004             
/*MT6261RF*/ #define  PDATA_DCS_PR2             0x004
/*MT6261RF*/ #define  PDATA_DCS_PR3             0x000
/*MT6261RF*/ #define  PDATA_DCS_PT1             0x000
/*MT6261RF*/ #define  PDATA_DCS_PT2             0x004
/*MT6261RF*/ #define  PDATA_DCS_PT2B            0x007
/*MT6261RF*/ #define  PDATA_DCS_PT3             0x000
/*MT6261RF*/
/*MT6261RF*/ #define  PDATA_PCS_PR1             0x004
/*MT6261RF*/ #define  PDATA_PCS_PR2             0x004
/*MT6261RF*/ #define  PDATA_PCS_PR3             0x000
/*MT6261RF*/ #define  PDATA_PCS_PT1             0x000
/*MT6261RF*/ #define  PDATA_PCS_PT2             0x004
/*MT6261RF*/ #define  PDATA_PCS_PT2B            0x007
/*MT6261RF*/ #define  PDATA_PCS_PT3             0x000
/*MT6261RF*/
/*MT6261RF*/ #define  PDATA_INIT                0x000
/*MT6261RF*/ #define  PDATA_IDLE                0x000

#else
/*MT6261RF*/ #define  PDATA_GSM850_PR1          0x000           
/*MT6261RF*/ #define  PDATA_GSM850_PR2          0x000           
/*MT6261RF*/ #define  PDATA_GSM850_PR3          0x000           
/*MT6261RF*/ #define  PDATA_GSM850_PT1          0x000         
/*MT6261RF*/ #define  PDATA_GSM850_PT2          0x002           
/*MT6261RF*/ #define  PDATA_GSM850_PT2B         0x002           
/*MT6261RF*/ #define  PDATA_GSM850_PT3          0x000           
/*MT6261RF*/
/*MT6261RF*/ #define  PDATA_GSM_PR1             0x000                
/*MT6261RF*/ #define  PDATA_GSM_PR2             0x000                
/*MT6261RF*/ #define  PDATA_GSM_PR3             0x000                
/*MT6261RF*/ #define  PDATA_GSM_PT1             0x000                
/*MT6261RF*/ #define  PDATA_GSM_PT2             0x002                
/*MT6261RF*/ #define  PDATA_GSM_PT2B            0x002                      
/*MT6261RF*/ #define  PDATA_GSM_PT3             0x000                
/*MT6261RF*/
/*MT6261RF*/ #define  PDATA_DCS_PR1             0x001             
/*MT6261RF*/ #define  PDATA_DCS_PR2             0x001            
/*MT6261RF*/ #define  PDATA_DCS_PR3             0x000             
/*MT6261RF*/ #define  PDATA_DCS_PT1             0x000
/*MT6261RF*/ #define  PDATA_DCS_PT2             0x003
/*MT6261RF*/ #define  PDATA_DCS_PT2B            0x003
/*MT6261RF*/ #define  PDATA_DCS_PT3             0x000
/*MT6261RF*/
/*MT6261RF*/ #define  PDATA_PCS_PR1             0x001
/*MT6261RF*/ #define  PDATA_PCS_PR2             0x001
/*MT6261RF*/ #define  PDATA_PCS_PR3             0x000
/*MT6261RF*/ #define  PDATA_PCS_PT1             0x000
/*MT6261RF*/ #define  PDATA_PCS_PT2             0x003
/*MT6261RF*/ #define  PDATA_PCS_PT2B            0x003
/*MT6261RF*/ #define  PDATA_PCS_PT3             0x000
/*MT6261RF*/
/*MT6261RF*/ #define  PDATA_INIT                0x000
/*MT6261RF*/ #define  PDATA_IDLE                0x000
/*MT6261RF*/
#endif
/*MT6261RF*/ /*----------------------------------------------*/
/*MT6261RF*/ /*   APC Compensate Thresholds                  */
/*MT6261RF*/ /*----------------------------------------------*/
/*MT6261RF*/
/*MT6261RF*/ #define    SECONDS2FRAME(n)                     ((int)((n)*1000/4.615))
/*MT6261RF*/ #define    VOLT2UVOLT(n)                        ((int)((n)*1000000))
/*MT6261RF*/ #define    TEMP2MTEMP(n)                        ((int)((n)*1000))
/*MT6261RF*/
/*MT6261RF*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD_SECOND     180
/*MT6261RF*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(BAT_VOLTAGE_SAMPLE_PERIOD_SECOND)
/*MT6261RF*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6261RF*/ #define    BAT_LOW_VOLTAGE_TRHESHOLD            (3.5)
/*MT6261RF*/ #define    BAT_HIGH_VOLTAGE_TRHESHOLD           (4.0)
/*MT6261RF*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(BAT_LOW_VOLTAGE_TRHESHOLD)
/*MT6261RF*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(BAT_HIGH_VOLTAGE_TRHESHOLD)
/*MT6261RF*/
/*MT6261RF*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND 180
/*MT6261RF*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND)
/*MT6261RF*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6261RF*/ #define    BAT_LOW_TEMPERATURE_TRHESHOLD        (0)
/*MT6261RF*/ #define    BAT_HIGH_TEMPERATURE_TRHESHOLD       (50)
/*MT6261RF*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(BAT_LOW_TEMPERATURE_TRHESHOLD)
/*MT6261RF*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(BAT_HIGH_TEMPERATURE_TRHESHOLD)
/*MT6261RF*/
/*MT6261RF*/ /*----------------------------------------------*/
/*MT6261RF*/ /*   Crystal parameter                          */
/*MT6261RF*/ /*----------------------------------------------*/
/*MT6261RF*/ #define Custom_RF_XO_CapID      16
/*MT6261RF*/
/*MT6261RF*/ /*------------------------------------------------------------------------------------*/
/*MT6261RF*/ /*   0: GSM850 Signal go through GSM850, GSM900 Signal go through GSM900  (default)   */
/*MT6261RF*/ /*   1: GSM850 Signal go through GSM900, GSM900 Signal go through GSM850  (default)   */
/*MT6261RF*/ /*------------------------------------------------------------------------------------*/
/*MT6261RF*/ #define GSM850_GSM900_SWAP      0
/*MT6261RF*/ /*------------------------------------------------------------------------------------*/
/*MT6261RF*/ /*   0: DCS1800 Signal go through DCS1800, PCS1900 Signal go through PCS1900(default) */
/*MT6261RF*/ /*   1: DCS1800 Signal go through PCS1900, PCS1900 Signal go through DCS1800          */
/*MT6261RF*/ /*------------------------------------------------------------------------------------*/
/*MT6261RF*/ #define DCS1800_PCS1900_SWAP    0
/*MT6261RF*/ /*------------------------------------------------------------------------------------*/
/*MT6261RF*/
/*MT6261RF*/ /*----------------------------------------------*/
/*MT6261RF*/ /*   TX power rollback parameter                */
/*MT6261RF*/ /*----------------------------------------------*/
/*MT6261RF*/ /*Unit: 1/8 dB*/
/*MT6261RF*/ /*GSM850 GMSK*/
/*MT6261RF*/ #define GSM850_TX_ROLLBACK_2T_GMSK 8   /* 1dBm*/
/*MT6261RF*/ #define GSM850_TX_ROLLBACK_3T_GMSK 24  /* 3dBm*/
/*MT6261RF*/ #define GSM850_TX_ROLLBACK_4T_GMSK 32  /* 4dBm*/
/*MT6261RF*/ #define GSM850_TX_ROLLBACK_5T_GMSK 40  /* 5dBm*/
/*MT6261RF*/
/*MT6261RF*/ /*GSM GMSK*/
/*MT6261RF*/ #define GSM_TX_ROLLBACK_2T_GMSK 8      /* 1dBm*/
/*MT6261RF*/ #define GSM_TX_ROLLBACK_3T_GMSK 24     /* 3dBm*/
/*MT6261RF*/ #define GSM_TX_ROLLBACK_4T_GMSK 32     /* 4dBm*/
/*MT6261RF*/ #define GSM_TX_ROLLBACK_5T_GMSK 40     /* 5dBm*/
/*MT6261RF*/
/*MT6261RF*/ /*DCS GMSK*/
/*MT6261RF*/ #define DCS_TX_ROLLBACK_2T_GMSK 8      /* 1dBm*/
/*MT6261RF*/ #define DCS_TX_ROLLBACK_3T_GMSK 24     /* 3dBm*/
/*MT6261RF*/ #define DCS_TX_ROLLBACK_4T_GMSK 32     /* 4dBm*/
/*MT6261RF*/ #define DCS_TX_ROLLBACK_5T_GMSK 40     /* 5dBm*/
/*MT6261RF*/
/*MT6261RF*/ /*PCS GMSK*/
/*MT6261RF*/ #define PCS_TX_ROLLBACK_2T_GMSK 8      /* 1dBm*/
/*MT6261RF*/ #define PCS_TX_ROLLBACK_3T_GMSK 24     /* 3dBm*/
/*MT6261RF*/ #define PCS_TX_ROLLBACK_4T_GMSK 32     /* 4dBm*/
/*MT6261RF*/ #define PCS_TX_ROLLBACK_5T_GMSK 40     /* 5dBm*/

/*MT6261RF*/ /*----------------------------------------------*/
/*MT6261RF*/ /*   DCXO LPM parameter                         */
/*MT6261RF*/ /*----------------------------------------------*/
/*MT6261RF*/ #define CUSTOM_CLOAD_FREQ_OFFSET   66976 /*in unit of Hz*/

//*============================================================================== */
/*MT6261RF*/ /* If you want to use calibration data in m12193.c, please DO NOT define __SLIM_CALIBRATION_DATA__ in l1d_custom_rf.h */
/*MT6261RF*/ #define __SLIM_CALIBRATION_DATA__

#endif

