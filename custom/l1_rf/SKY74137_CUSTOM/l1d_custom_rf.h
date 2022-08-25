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
 *   MT6229
 *
 * Description:
 * ------------
 *   Skyworks RF constance defintion
 *
 * Author:
 * -------
 * -------
 *

 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */
#if !defined(SKY74137_RF)
   #error "rf files mismatch with compile option!"
#endif

/*SKY74137*/
/*SKY74137*/ /*--------------------------------------------------------*/
/*SKY74137*/ /*   Event Timing Define                                  */
/*SKY74137*/ /*--------------------------------------------------------*/
/*SKY74137*/
/*SKY74137*/ #if  IS_CHIP_MT6218_AND_LATTER_VERSION 
/*SKY74137*//*MT6218~*/ #define  QB_RX_FENA_2_FSYNC          40   /* this value shall be 4N+0 */
/*SKY74137*//*MT6218~*/ #define  QB_RX_FSYNC_2_FENA          0
/*SKY74137*//*MT6218~*/ #define  QB_TX_FENA_2_FSYNC          152  /* this value shall be 4N+0 */
/*SKY74137*//*MT6218~*/ #define  QB_TX_FSYNC_2_FENA          30
/*SKY74137*/ #elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*SKY74137*//*MT6229~*/ #define  QB_RX_FENA_2_FSYNC          48   /* this value shall be 4N+0 */
/*SKY74137*//*MT6229~*/ #define  QB_RX_FSYNC_2_FENA          0
/*SKY74137*//*MT6229~*/ #define  QB_TX_FENA_2_FSYNC          164  /* this value shall be 4N+0 */
/*SKY74137*//*MT6229~*/ #define  QB_TX_FSYNC_2_FENA          30
/*SKY74137*/ #else
/*SKY74137*//*OTHERS*/  #define  QB_RX_FENA_2_FSYNC          35   /* this value shall be 4N+3 */
/*SKY74137*//*OTHERS*/  #define  QB_RX_FSYNC_2_FENA          0
/*SKY74137*//*OTHERS*/  #define  QB_TX_FENA_2_FSYNC          149  /* this value shall be 4N+1 */
/*SKY74137*//*OTHERS*/  #define  QB_TX_FSYNC_2_FENA          30
/*SKY74137*/ #endif
/*SKY74137*/
/*SKY74137*/                                           /*           |--(N:SR3 data number)                     */
/*SKY74137*/ #define  QB_SR1                      220  /* Let the 6*N + 4(QB) distance exist between SR1 & SR3 */
/*SKY74137*/ #define  QB_SR2                      180
/*SKY74137*/ #define  QB_SR2M                     40
/*SKY74137*/ #define  QB_SR3                      0
/*SKY74137*/ #define  QB_PR1                      220
/*SKY74137*/ #define  QB_PR2                      130
/*SKY74137*/ //#define  QB_PR2M1                    34
/*SKY74137*/ //#define  QB_PR2M2                    33
/*SKY74137*/ #define  QB_PR3                      6
/*SKY74137*/ #define  QB_PR3A                     8
/*SKY74137*/ #define  QB_ST1                      300
/*SKY74137*/ #define  QB_ST2                      260
/*SKY74137*/ //#define  QB_ST2B                    100
/*SKY74137*/ #define  QB_ST3                      0
/*SKY74137*/ #define  QB_PT1                      300
/*SKY74137*/ #define  QB_PT2                      109
/*SKY74137*/ #define  QB_PT2B                     1
/*SKY74137*/ #define  QB_PT3                      27

/*SKY74137*/ //#define  QB_ST2M_8G                  0
/*SKY74137*/ #define  QB_PT2M1_G8                 0
/*SKY74137*/ //#define  QB_PT2M2_G8                 0
/*SKY74137*/ //#define  QB_PT2M3_G8                 0
/*SKY74137*/ #define  QB_PT2M1_8G                 0
/*SKY74137*/ //#define  QB_PT2M2_8G                 0
/*SKY74137*/ //#define  QB_PT2M3_8G                 0
/*SKY74137*/ #define  QB_APCON                    21
/*SKY74137*/ #define  QB_APCMID                   22
/*SKY74137*/ #define  QB_APCOFF                   3
/*SKY74137*/ #define  QB_APCDACON                 99
/*SKY74137*/
/*SKY74137*/ #if  IS_CHIP_MT6218_AND_LATTER_VERSION
/*SKY74137*//*MT6218~*/ #define  TX_PROPAGATION_DELAY         41
/*SKY74137*/ #elif  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*SKY74137*//*MT6229~*/ #define  TX_PROPAGATION_DELAY         45
/*SKY74137*/ #else
/*SKY74137*//*OTHERS*/  #define  TX_PROPAGATION_DELAY         36
/*SKY74137*/ #endif
/*SKY74137*/
/*SKY74137*/ #if  IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*SKY74137*/ /*MT6205*/ /*--------------------------------------------------------*/
/*SKY74137*/ /*MT6205*/ /*   define  BPI data for SKY74045 (shall be modified by real case)    */
/*SKY74137*/ /*MT6205*/ /*--------------------------------------------------------*/
/*SKY74137*/ /*MT6205*/ /*    PRCB : bit   pin                                    */
/*SKY74137*/ /*MT6205*/ /*            0    VC2            VC2                     */
/*SKY74137*/ /*MT6205*/ /*            1    VC3            VC3                     */
/*SKY74137*/ /*MT6205*/ /*            2    VC1            VC1                     */
/*SKY74137*/ /*MT6205*/ /*            3    RX_EN          RXENA                   */
/*SKY74137*/ /*MT6205*/ /*            4    TX_EN          TXENA                   */
/*SKY74137*/ /*MT6205*/ /*            5    BANDSW         BAND                    */
/*SKY74137*/ /*MT6205*/ /*            6    PAC_EN                                 */
/*SKY74137*/ /*MT6205*/ /*            7    EDGE_MODE      EDGE_MODE               */
/*SKY74137*/ /*MT6205*/ /*            8    not used                               */
/*SKY74137*/ /*MT6205*/ /*            9    SYN_EN         SXENA                   */
/*SKY74137*/ /*MT6205*/ /*--------------------------------------------------------*/
/*SKY74137*/ /*MT6205*/
/*SKY74137*/ /*MT6205*/ #define  PDATA_GMSK               0x080
/*SKY74137*/ /*MT6205*/ #define  PDATA_EPSK               0x000
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PR1         0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PR2         0x20C
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PR3         0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PR3A        0x000
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM850_PR2M1       0x0     
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM850_PR2M2       0x0     
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PT1         0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PT2         0x250
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PT2B        0x251   // for TRSW
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PT3         0x000
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PT2M1_G8    0x251 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM850_PT2M2_G8    0x0 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM850_PT2M3_G8    0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM850_PT2M1_8G    0x2D1 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM850_PT2M2_8G    0x0 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM850_PT2M3_8G    0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PR1            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PR2            0x208
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PR3            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PR3A           0x000
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM_PR2M1          0x0
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM_PR2M2          0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PT1            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PT2            0x250
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PT2B           0x251   // for TRSW
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PT3            0x000
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PT2M1_G8       0x251 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM_PT2M2_G8       0x0 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM_PT2M3_G8       0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_GSM_PT2M1_8G       0x2D1 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM_PT2M2_8G       0x0 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_GSM_PT2M3_8G       0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PR1            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PR2            0x20C
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PR3            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PR3A           0x000
/*SKY74137*/ /*MT6205*/ //#define  PDATA_DCS_PR2M1          0x0
/*SKY74137*/ /*MT6205*/ //#define  PDATA_DCS_PR2M2          0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PT1            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PT2            0x270
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PT2B           0x272   // for TRSW
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PT3            0x000
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PT2M1_G8       0x272 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_DCS_PT2M2_G8       0x0 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_DCS_PT2M3_G8       0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_DCS_PT2M1_8G       0x2F2 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_DCS_PT2M2_8G       0x0 
/*SKY74137*/ /*MT6205*/ //#define  PDATA_DCS_PT2M3_8G       0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PR1            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PR2            0x208
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PR3            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PR3A           0x000
/*SKY74137*/ /*MT6205*/ //#define  PDATA_PCS_PR2M1          0x0
/*SKY74137*/ /*MT6205*/ //#define  PDATA_PCS_PR2M2          0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PT1            0x200
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PT2            0x270
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PT2B           0x272   // for TRSW
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PT3            0x000
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PT2M1_G8       0x272                                                  
/*SKY74137*/ /*MT6205*/ //#define  PDATA_PCS_PT2M2_G8       0x0                                                  
/*SKY74137*/ /*MT6205*/ //#define  PDATA_PCS_PT2M3_G8       0x0
/*SKY74137*/ /*MT6205*/ #define  PDATA_PCS_PT2M1_8G       0x2F2                                                  
/*SKY74137*/ /*MT6205*/ //#define  PDATA_PCS_PT2M2_8G       0x0                                                  
/*SKY74137*/ /*MT6205*/ //#define  PDATA_PCS_PT2M3_8G       0x0
/*SKY74137*/ /*MT6205*/                              


                                                     
/*SKY74137*/ /*MT6205*/ #define  PDATA_INIT        0x000
/*SKY74137*/ /*MT6205*/ #define  PDATA_IDLE        0x000
/*SKY74137*/ #endif
/*SKY74137*/
/*SKY74137*/ /*----------------------------------------------*/
/*SKY74137*/ /*   APC Compensate Thresholds                  */
/*SKY74137*/ /*----------------------------------------------*/
/*SKY74137*/
/*SKY74137*/ #define    SECONDS2FRAME(n)        ((int)((n)*1000/4.165))
/*SKY74137*/ #define    VOLT2UVOLT(n)           ((int)((n)*1000000))
/*SKY74137*/ #define    TEMP2MTEMP(n)           ((int)((n)*1000))
/*SKY74137*/
/*SKY74137*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*SKY74137*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*SKY74137*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*SKY74137*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*SKY74137*/
/*SKY74137*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*SKY74137*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*SKY74137*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*SKY74137*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*SKY74137*/
/*============================================================================== */

#endif
