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
 *	l1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6223
 *
 * Description:
 * ------------
 *   AD6548 RF constance defintion
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_

#if !defined(AD6548_RF) 
   #error "rf files mismatch with compile option!"
#endif

/*--------------------------------------------------------*/
/*   Event Timing Define                                  */
/*--------------------------------------------------------*/

/*AD6548*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*AD6548*//*MT6225~*/ #define  QB_RX_FENA_2_FSYNC          48   /* this value shall be 4N+0 */
/*AD6548*//*MT6225~*/ #define  QB_RX_FSYNC_2_FENA           0
/*AD6548*//*MT6225~*/ #define  QB_TX_FENA_2_FSYNC         152   /* this value shall be 4N+0 */
/*AD6548*//*MT6225~*/ #define  QB_TX_FSYNC_2_FENA          20 //30
/*AD6548*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*AD6548*//*MT6218~*/ #define  QB_RX_FENA_2_FSYNC          40   /* this value shall be 4N+0 */
/*AD6548*//*MT6218~*/ #define  QB_RX_FSYNC_2_FENA           0
/*AD6548*//*MT6218~*/ #define  QB_TX_FENA_2_FSYNC         152   /* this value shall be 4N+0 */
/*AD6548*//*MT6218~*/ #define  QB_TX_FSYNC_2_FENA          30
/*AD6548*/ #else
/*AD6548*/ /*OTHERS*/ #define  QB_RX_FENA_2_FSYNC          35   /* this value shall be 4N+3 */
/*AD6548*/ /*OTHERS*/ #define  QB_RX_FSYNC_2_FENA           0
/*AD6548*/ /*OTHERS*/ #define  QB_TX_FENA_2_FSYNC         149   /* this value shall be 4N+1 */
/*AD6548*/ /*OTHERS*/ #define  QB_TX_FSYNC_2_FENA          30
/*AD6548*/ #endif
/*AD6548*/                                          /*           |--(N:SR3 data number)                     */
/*AD6548*/#define  QB_SR1                      226  /* Let the 6*N + 4(QB) distance exist between SR1 & SR3 */
/*AD6548*/#define  QB_SR2                       84
/*AD6548*/#define  QB_SR2M                      36
/*AD6548*/#define  QB_SR3                        0
/*AD6548*/#define  QB_PR1                      243
/*AD6548*/#define  QB_PR2                       35
/*AD6548*/#define  QB_PR3                        6
/*AD6548*/#define  QB_ST1                      236 //226/* send Power control and PLL setting*/
/*AD6548*/#define  QB_ST2                      136 //126/* TX on */
/*AD6548*/#define  QB_ST3                       35 //28
/*AD6548*/#define  QB_PT1                      236 //226
/*AD6548*/#define  QB_PT2                        4 //18
/*AD6548*/#define  QB_PT3                       35 //28
/*AD6548*/
/*AD6548*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*AD6548*/ #define  QB_APCON                    22 //17
/*AD6548*/ #define  QB_APCMID                   22
/*AD6548*/ #define  QB_APCOFF                    7 //9
/*AD6548*/ #else                                
/*AD6548*/ #define  QB_APCON                    21
/*AD6548*/ #define  QB_APCMID                   26
/*AD6548*/ #define  QB_APCOFF                    5
/*AD6548*/ #endif                               
/*AD6548*/ #define  QB_APCDACON                 99
/*AD6548*/
/*AD6548*/ #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*AD6548*//*MT6223~*/ #define  TX_PROPAGATION_DELAY         42
/*AD6548*/ #elif IS_CHIP_MT6225_AND_LATTER_VERSION||IS_CHIP_MT6229||IS_CHIP_MT6268T
/*AD6548*//*MT6225~*/ #define  TX_PROPAGATION_DELAY         45
/*AD6548*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*AD6548*//*MT6218~*/ #define  TX_PROPAGATION_DELAY         37
/*AD6548*/ #else
/*AD6548*//*OTHERS*/  #define  TX_PROPAGATION_DELAY         36
/*AD6548*/ #endif
/*AD6548*/
/*AD6548*/
/*AD6548*/
/*AD6548*/ #if IS_CHIP_MT6268T || IS_3G_CHIP
/*AD6548*///*MT6268*/*--------------------------------------------------------*/
/*AD6548*///*MT6268*/*   define  BPI data for (shall be modified by real case)*/
/*AD6548*///*MT6268*/*--------------------------------------------------------*/
/*AD6548*///*MT6268*/*    PRCB : bit   pin                                    */
/*AD6548*///*MT6268*/*              0    ASM_2G_EN                            */
/*AD6548*///*MT6268*/*              1    ASM_3G_EN                            */
/*AD6548*///*MT6268*/*              2    not used                             */
/*AD6548*///*MT6268*/*              3    not used                             */
/*AD6548*///*MT6268*/*              4    ASM_VDD                              */
/*AD6548*///*MT6268*/*              5    not used                             */
/*AD6548*///*MT6268*/*              6    PA_EN                                */
/*AD6548*///*MT6268*/*              7    BAND_SW                              */
/*AD6548*///*MT6268*/*--------------------------------------------------------*/
/*AD6548*//*MT6268*/ #define  PDATA_GSM850_PR1     0x11
/*AD6548*//*MT6268*/ #define  PDATA_GSM850_PR2     0x11
/*AD6548*//*MT6268*/ #define  PDATA_GSM850_PR3     0x00
/*AD6548*//*MT6268*/ #define  PDATA_GSM850_PT1     0x11
/*AD6548*//*MT6268*/ #define  PDATA_GSM850_PT2     0x51
/*AD6548*//*MT6268*/ #define  PDATA_GSM850_PT3     0x00
/*AD6548*//*MT6268*/ #define  PDATA_GSM_PR1        0x11
/*AD6548*//*MT6268*/ #define  PDATA_GSM_PR2        0x11
/*AD6548*//*MT6268*/ #define  PDATA_GSM_PR3        0x00
/*AD6548*//*MT6268*/ #define  PDATA_GSM_PT1        0x11
/*AD6548*//*MT6268*/ #define  PDATA_GSM_PT2        0x51
/*AD6548*//*MT6268*/ #define  PDATA_GSM_PT3        0x00
/*AD6548*//*MT6268*/ #define  PDATA_DCS_PR1        0x11
/*AD6548*//*MT6268*/ #define  PDATA_DCS_PR2        0x91
/*AD6548*//*MT6268*/ #define  PDATA_DCS_PR3        0x00
/*AD6548*//*MT6268*/ #define  PDATA_DCS_PT1        0x11
/*AD6548*//*MT6268*/ #define  PDATA_DCS_PT2        0xD1
/*AD6548*//*MT6268*/ #define  PDATA_DCS_PT3        0x00
/*AD6548*//*MT6268*/ #define  PDATA_PCS_PR1        0x11
/*AD6548*//*MT6268*/ #define  PDATA_PCS_PR2        0x91
/*AD6548*//*MT6268*/ #define  PDATA_PCS_PR3        0x00
/*AD6548*//*MT6268*/ #define  PDATA_PCS_PT1        0x11
/*AD6548*//*MT6268*/ #define  PDATA_PCS_PT2        0xD1
/*AD6548*//*MT6268*/ #define  PDATA_PCS_PT3        0x00
/*AD6548*//*MT6268*/ 
/*AD6548*//*MT6268*/ #define GSM_ERR_DET_ID           0
/*AD6548*/ #else
/*AD6548*/
/*AD6548*//*--------------------------------------------------------*/
/*AD6548*//*   define  BPI data for (shall be modified by real case)*/
/*AD6548*//*--------------------------------------------------------*/
/*AD6548*//*    PRCB : bit   pin                                    */
/*AD6548*//*              0    V_logic(Jumper)                      */
/*AD6548*//*              1    not used                             */
/*AD6548*//*              2    not used                             */
/*AD6548*//*              3    not used                             */
/*AD6548*//*              4    TXEN                                 */
/*AD6548*//*              5    BANDSW                               */
/*AD6548*//*--------------------------------------------------------*/
/*AD6548*/#define  PDATA_GSM850_PR1     0x01//0x00
/*AD6548*/#define  PDATA_GSM850_PR2     0x01//0x01
/*AD6548*/#define  PDATA_GSM850_PR3     0x00//0x00
/*AD6548*/#define  PDATA_GSM850_PT1     0x01//0x10
/*AD6548*/#define  PDATA_GSM850_PT2     0x11//0x11
/*AD6548*/#define  PDATA_GSM850_PT3     0x00//0x00
/*AD6548*/#define  PDATA_GSM_PR1        0x01//0x00
/*AD6548*/#define  PDATA_GSM_PR2        0x01//0x01
/*AD6548*/#define  PDATA_GSM_PR3        0x00//0x00
/*AD6548*/#define  PDATA_GSM_PT1        0x01//0x10
/*AD6548*/#define  PDATA_GSM_PT2        0x11//0x11
/*AD6548*/#define  PDATA_GSM_PT3        0x00//0x00
/*AD6548*/#define  PDATA_DCS_PR1        0x01//0x00
/*AD6548*/#define  PDATA_DCS_PR2        0x21//0x21
/*AD6548*/#define  PDATA_DCS_PR3        0x00//0x00
/*AD6548*/#define  PDATA_DCS_PT1        0x01//0x30
/*AD6548*/#define  PDATA_DCS_PT2        0x31//0x31
/*AD6548*/#define  PDATA_DCS_PT3        0x00//0x00
/*AD6548*/#define  PDATA_PCS_PR1        0x01//0x00
/*AD6548*/#define  PDATA_PCS_PR2        0x21//0x21
/*AD6548*/#define  PDATA_PCS_PR3        0x00//0x00
/*AD6548*/#define  PDATA_PCS_PT1        0x01//0x30
/*AD6548*/#define  PDATA_PCS_PT2        0x31//0x31
/*AD6548*/#define  PDATA_PCS_PT3        0x00//0x00
/*AD6548*/
/*AD6548*/ #endif
/*AD6548*/
/*AD6548*/#define  PDATA_INIT           0x00
/*AD6548*/#define  PDATA_IDLE           0x00
/*AD6548*/
/*AD6548*//*----------------------------------------------*/
/*AD6548*//*   APC Compensate Thresholds                  */
/*AD6548*//*----------------------------------------------*/
/*AD6548*/
/*AD6548*/#define    SECONDS2FRAME(n)        ((int)((n)*1000/4.165))
/*AD6548*/#define    VOLT2UVOLT(n)           ((int)((n)*1000000))
/*AD6548*/#define    TEMP2MTEMP(n)           ((int)((n)*1000))
/*AD6548*/
/*AD6548*/#define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*AD6548*/#define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*AD6548*/#define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*AD6548*/#define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*AD6548*/
/*AD6548*/#define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*AD6548*/#define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*AD6548*/#define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*AD6548*/#define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*AD6548*/
/*AD6548*//*----------------------------------------------*/
/*AD6548*//*   Crystal parameter                          */
/*AD6548*//*----------------------------------------------*/
/*AD6548*/#if  defined(AFC_VCXO)
/*AD6548*/   #define Custom_RF_XO_CapID  33                
/*AD6548*/#else
/*AD6548*/   #define Custom_RF_XO_CapID   0                /* For AD6549 (AD6548 with VCTCXO) */
/*AD6548*/#endif
/*AD6548*/
/*AD6548*//*======================================================================================== */
/*AD6548*/ 
/*AD6548*//*-------------------------------  Low Band Signal Swap  ----------------------------------*/
/*AD6548*//*   0:GSM850 Signal go through GSM850, GSM900 Signal go through GSM900  (default)         */
/*AD6548*//*   1:GSM850 Signal go through GSM900, GSM900 Signal go through GSM850                    */
/*AD6548*//*-----------------------------------------------------------------------------------------*/
/*AD6548*/#define GSM850_GSM900_SWAP   0
/*AD6548*//*-------------------------------  High Band Signal Swap  ---------------------------------*/
/*AD6548*//*   0:DCS1800 Signal go through DCS1800, PCS1900 Signal go through PCS1900(default)       */
/*AD6548*//*   1:DCS1800 Signal go through PCS1900, PCS1900 Signal go through DCS1800                */
/*AD6548*//*-----------------------------------------------------------------------------------------*/
/*AD6548*/#define DCS1800_PCS1900_SWAP  0
/*AD6548*/
/*AD6548*//*======================================================================================== */
/*AD6548*//* for BT co_clock support                                                                 */
/*AD6548*//*======================================================================================== */
/*AD6548*/ #define IS_BT_COCLOCK_SUPPORT 0
/*AD6548*/ /*----------------------------------------------*/
/*AD6548*/ /*   TX power rollback parameter                */
/*AD6548*/ /*----------------------------------------------*/
/*AD6548*/ /*Unit: 1/8 dB*/
/*AD6548*/ /*GSM850 GMSK*/
/*AD6548*/ #define GSM850_TX_ROLLBACK_2T_GMSK 8
/*AD6548*/ #define GSM850_TX_ROLLBACK_3T_GMSK 24
/*AD6548*/ #define GSM850_TX_ROLLBACK_4T_GMSK 32
/*AD6548*/ #define GSM850_TX_ROLLBACK_5T_GMSK 40
/*AD6548*/ 
/*AD6548*/ /*GSM GMSK*/
/*AD6548*/ #define GSM_TX_ROLLBACK_2T_GMSK 8
/*AD6548*/ #define GSM_TX_ROLLBACK_3T_GMSK 24
/*AD6548*/ #define GSM_TX_ROLLBACK_4T_GMSK 32
/*AD6548*/ #define GSM_TX_ROLLBACK_5T_GMSK 40
/*AD6548*/ 
/*AD6548*/ /*DCS GMSK*/
/*AD6548*/ #define DCS_TX_ROLLBACK_2T_GMSK 8
/*AD6548*/ #define DCS_TX_ROLLBACK_3T_GMSK 24
/*AD6548*/ #define DCS_TX_ROLLBACK_4T_GMSK 32
/*AD6548*/ #define DCS_TX_ROLLBACK_5T_GMSK 40
/*AD6548*/ 
/*AD6548*/ /*PCS GMSK*/
/*AD6548*/ #define PCS_TX_ROLLBACK_2T_GMSK 8
/*AD6548*/ #define PCS_TX_ROLLBACK_3T_GMSK 24
/*AD6548*/ #define PCS_TX_ROLLBACK_4T_GMSK 32
/*AD6548*/ #define PCS_TX_ROLLBACK_5T_GMSK 40
//*============================================================================== */

#endif












