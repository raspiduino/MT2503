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
 *
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */
#if !defined(MT6139E_RF)
   #error "rf files mismatch with compile option!"
#endif

/*MT6139E*/
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*   Event Timing Define                                  */
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/
/*MT6139E*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139E*/ /*MT6225~*/ #define  QB_RX_FENA_2_FSYNC          48   /* this value shall be 4N+0 */
/*MT6139E*/ /*MT6225~*/ #define  QB_RX_FSYNC_2_FENA          0
/*MT6139E*/ /*MT6225~*/ #define  QB_TX_FENA_2_FSYNC          152  /* this value shall be 4N+0 */
/*MT6139E*/ /*MT6225~*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6139E*/ /*MT6225~*/ /* #define  QB_TX_FSYNC_2_FENA          20  *//* SKY77518 */
/*MT6139E*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6139E*/ /*MT6218~*/ #define  QB_RX_FENA_2_FSYNC          40   /* this value shall be 4N+0 */
/*MT6139E*/ /*MT6218~*/ #define  QB_RX_FSYNC_2_FENA          0
/*MT6139E*/ /*MT6218~*/ #define  QB_TX_FENA_2_FSYNC          152  /* this value shall be 4N+0 */
/*MT6139E*/ /*MT6218~*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6139E*/ /*MT6218~*/ /* #define  QB_TX_FSYNC_2_FENA          20  *//* SKY77518*/
/*MT6139E*/ #else
/*MT6139E*/ /*OTHERS*/ #define  QB_RX_FENA_2_FSYNC           35   /* this value shall be 4N+3 */
/*MT6139E*/ /*OTHERS*/ #define  QB_RX_FSYNC_2_FENA           0
/*MT6139E*/ /*OTHERS*/ #define  QB_TX_FENA_2_FSYNC           149  /* this value shall be 4N+1 */
/*MT6139E*/ /*OTHERS*/ #define  QB_TX_FSYNC_2_FENA           30
/*MT6139E*/ /*OTHERS*/ /* #define  QB_TX_FSYNC_2_FENA          20  *//* SKY77518*/
/*MT6139E*/ #endif
/*MT6139E*/                                           /*           |--(N:SR3 data number)                     */
/*MT6139E*/ #define  QB_SR1                      217  /* Let the 6*N + 4(QB) distance exist between SR1 & SR3 */
/*MT6139E*/ #define  QB_SR2                      70
/*MT6139E*/ #define  QB_SR2M                     44
/*MT6139E*/ #define  QB_SR3                      0
/*MT6139E*/ #define  QB_PR1                      248
/*MT6139E*/ #define  QB_PR2                      30
/*MT6139E*/ #define  QB_PR3                      6
/*MT6139E*/ #define  QB_ST1                      304
/*MT6139E*/ #define  QB_ST2                      140
/*MT6139E*/ #define  QB_ST3                      23
/*MT6139E*/ /* #define  QB_ST3                   35 *//* SKY77518*/
/*MT6139E*/ #define  QB_PT2B                     335 
/*MT6139E*/ #define  QB_PT1                      18 
/*MT6139E*/ /* #define  QB_PT1                   6 *//* SKY77518*/
/*MT6139E*/ #define  QB_PT2                      6 // SKY77518 does not use this event.
/*MT6139E*/ #define  QB_PT3                      25
/*MT6139E*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139E*/ #define  QB_APCON                    17
/*MT6139E*/ #define  QB_APCMID                   22
/*MT6139E*/ #define  QB_APCOFF                   9
/*MT6139E*/ #else
/*MT6139E*/ #define  QB_APCON                    21
/*MT6139E*/ #define  QB_APCMID                   26
/*MT6139E*/ #define  QB_APCOFF                   5
/*MT6139E*/ #endif
/*MT6139E*/ #define  QB_APCDACON                 99
/*MT6139E*/
/*MT6139E*/ #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6139E*//*MT6223~*/ #define  TX_PROPAGATION_DELAY         43
/*MT6139E*/ #elif IS_CHIP_MT6225_AND_LATTER_VERSION||IS_CHIP_MT6229||IS_CHIP_MT6268T
/*MT6139E*//*MT6225~*/ #define  TX_PROPAGATION_DELAY         45
/*MT6139E*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6139E*//*MT6218~*/ #define  TX_PROPAGATION_DELAY         37
/*MT6139E*/ #else
/*MT6139E*//*OTHERS*/  #define  TX_PROPAGATION_DELAY         36
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/ #if  IS_CHIP_MT6208
/*MT6139E*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6208*/ /*   define  BPI data (shall be modified by real case)    */
/*MT6139E*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6208*/ /*    PRCB : bit   pin                                    */
/*MT6139E*/ /*MT6208*/ /*            0    HB_TX                                  */
/*MT6139E*/ /*MT6208*/ /*            1   *PCS_CTRL                               */
/*MT6139E*/ /*MT6208*/ /*            2    TX_EN                                  */
/*MT6139E*/ /*MT6208*/ /*            3   *GSM_BANDSW*                            */
/*MT6139E*/ /*MT6208*/ /*            4    LB_TX                                  */
/*MT6139E*/ /*MT6208*/ /*            5    DCS_BANDSW*                            */
/*MT6139E*/ /*MT6208*/ /*            6    PCS_RCTRL                              */
/*MT6139E*/ /*MT6208*/ /*            7    not used                               */
/*MT6139E*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6208*/
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PR1  0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PR2  0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PR3  0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PT1  0x08
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PT2  0x1C
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PT3  0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PR1     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PR2     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PR3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PT1     0x08
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PT2     0x1C
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PT3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PR1     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PR2     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PR3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PT1     0x20
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PT2     0x25
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PT3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PR1     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PR2     0x40
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PR3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PT1     0x60
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PT2     0x25
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PT3     0x00
/*MT6139E*/ /*MT6208*/
/*MT6139E*/ /*MT6208*/ #define  PDATA_INIT        0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_IDLE        0x00
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/ #if  IS_CHIP_MT6205
/*MT6139E*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6205*/ /*   define  BPI data                                     */
/*MT6139E*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6205*/ /*    PRCB : bit   pin                                    */
/*MT6139E*/ /*MT6205*/ /*            0    HBTX                                   */
/*MT6139E*/ /*MT6205*/ /*            1    LBTX                                   */
/*MT6139E*/ /*MT6205*/ /*            2    PCSRX                                  */
/*MT6139E*/ /*MT6205*/ /*            3    850RX                                  */
/*MT6139E*/ /*MT6205*/ /*            4    PAEN                                   */
/*MT6139E*/ /*MT6205*/ /*            5    DCS_BANDSW                             */
/*MT6139E*/ /*MT6205*/ /*            6    not used                               */
/*MT6139E*/ /*MT6205*/ /*            7    not used                               */
/*MT6139E*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6205*/                           /*muRata 465*/  /*Hitachi_Darfon*/  /*muRata QB 382*/    /* TDK  */   
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM850_PR1   0x00           /*  0x00  */      /*  0x0B  */     /*  0x02  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM850_PR2   0x00           /*  0x00  */      /*  0x01  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM850_PR3   0x00           /*  0x00  */      /*  0x00  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM850_PT1   0x10           /*  0x10  */      /*  0x01  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM850_PT2   0x12           /*  0x16  */      /*  0x1B  */     /*  0x12  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM850_PT3   0x00           /*  0x00  */      /*  0x00  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM_PR1      0x00           /*  0x00  */      /*  0x0B  */     /*  0x02  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM_PR2      0x00           /*  0x00  */      /*  0x05  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM_PR3      0x00           /*  0x00  */      /*  0x00  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM_PT1      0x10           /*  0x10  */      /*  0x01  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM_PT2      0x12           /*  0x16  */      /*  0x1B  */     /*  0x12  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_GSM_PT3      0x00           /*  0x00  */      /*  0x00  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_DCS_PR1      0x00           /*  0x00  */      /*  0x03  */     /*  0x05  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_DCS_PR2      0x00           /*  0x00  */      /*  0x09  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_DCS_PR3      0x00           /*  0x00  */      /*  0x00  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_DCS_PT1      0x30           /*  0x30  */      /*  0x21  */     /*  0x20  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_DCS_PT2      0x35           /*  0x35  */      /*  0x33  */     /*  0x35  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_DCS_PT3      0x00           /*  0x00  */      /*  0x00  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_PCS_PR1      0x00           /*  0x00  */      /*  0x03  */     /*  0x05  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_PCS_PR2      0x04           /*  0x04  */      /*  0x0D  */     /*  0x04  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_PCS_PR3      0x00           /*  0x00  */      /*  0x00  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_PCS_PT1      0x30           /*  0x30  */      /*  0x21  */     /*  0x20  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_PCS_PT2      0x35           /*  0x35  */      /*  0x33  */     /*  0x35  */  
/*MT6139E*/ /*MT6205*/ #define  PDATA_PCS_PT3      0x00           /*  0x00  */      /*  0x00  */     /*  0x00  */  
/*MT6139E*/ /*MT6205*/                                               
/*MT6139E*/ /*MT6205*/ #define  PDATA_INIT         0x00                
/*MT6139E*/ /*MT6205*/ #define  PDATA_IDLE         0x00                
/*MT6139E*/ #endif                                                   
/*MT6139E*/ #if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139E*/ /*MT6218B~*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6218B~*/ /*   define  BPI data                                     */
/*MT6139E*/ /*MT6218B~*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6218B~*/ /*    PRCB : bit   pin         pin (SKY77518)              */
/*MT6139E*/ /*MT6218B~*/ /*            0    HBTX        not used                    */
/*MT6139E*/ /*MT6218B~*/ /*            1    LBTX        not used                    */
/*MT6139E*/ /*MT6218B~*/ /*            2    PCSRX       not used                    */
/*MT6139E*/ /*MT6218B~*/ /*            3    850RX       Vlogic (for option)         */
/*MT6139E*/ /*MT6218B~*/ /*            4    PAEN        PAEN                        */
/*MT6139E*/ /*MT6218B~*/ /*            5    DCS_BANDSW  DCS BANDSW                  */
/*MT6139E*/ /*MT6218B~*/ /*            6    not used    not used                    */
/*MT6139E*/ /*MT6218B~*/ /*            7    not used    not used                    */
/*MT6139E*/ /*MT6218B~*/ /*            8    not used    not used                    */
/*MT6139E*/ /*MT6218B~*/ /*            9    RFVCOEN     RFVCXOEN                      */
/*MT6139E*/ /*MT6218B~*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6218B~*/                           /*muRata 465*/  /*Hitachi_Darfon*/  /*muRata QB 382*/    /* TDK  */     /*Sky77518*/
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM850_PR1   0x200           /*  0x200  */      /*  0x20B  */     /*  0x202  */    /*  0x200  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM850_PR2   0x200           /*  0x200  */      /*  0x201  */     /*  0x200  */    /*  0x200  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM850_PR3   0x000           /*  0x000  */      /*  0x000  */     /*  0x000  */    /*  0x000  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM850_PT2B  0x200           /*  0x200  */      /*  0x200  */     /*  0x200  */    /*  0x208  */                     
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM850_PT1   0x210           /*  0x210  */      /*  0x201  */     /*  0x200  */    /*  0x210  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM850_PT2   0x212           /*  0x216  */      /*  0x21B  */     /*  0x212  */    /*  0x210  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM850_PT3   0x000           /*  0x000  */      /*  0x000  */     /*  0x000  */    /*  0x000  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM_PR1      0x200           /*  0x200  */      /*  0x20B  */     /*  0x202  */    /*  0x200  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM_PR2      0x200           /*  0x200  */      /*  0x205  */     /*  0x200  */    /*  0x200  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM_PR3      0x000           /*  0x000  */      /*  0x000  */     /*  0x000  */    /*  0x000  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM_PT2B     0x200           /*  0x200  */      /*  0x200  */     /*  0x200  */    /*  0x208  */                     
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM_PT1      0x210           /*  0x210  */      /*  0x201  */     /*  0x200  */    /*  0x210  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM_PT2      0x212           /*  0x216  */      /*  0x21B  */     /*  0x212  */    /*  0x210  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_GSM_PT3      0x000           /*  0x000  */      /*  0x000  */     /*  0x000  */    /*  0x000  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_DCS_PR1      0x200           /*  0x200  */      /*  0x203  */     /*  0x205  */    /*  0x200  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_DCS_PR2      0x200           /*  0x200  */      /*  0x209  */     /*  0x200  */    /*  0x220  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_DCS_PR3      0x000           /*  0x000  */      /*  0x000  */     /*  0x000  */    /*  0x000  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_DCS_PT2B     0x200           /*  0x200  */      /*  0x200  */     /*  0x200  */    /*  0x208  */                     
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_DCS_PT1      0x230           /*  0x230  */      /*  0x221  */     /*  0x220  */    /*  0x230  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_DCS_PT2      0x235           /*  0x235  */      /*  0x233  */     /*  0x235  */    /*  0x230  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_DCS_PT3      0x000           /*  0x000  */      /*  0x000  */     /*  0x000  */    /*  0x000  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_PCS_PR1      0x200           /*  0x200  */      /*  0x203  */     /*  0x205  */    /*  0x200  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_PCS_PR2      0x204           /*  0x204  */      /*  0x20D  */     /*  0x204  */    /*  0x220  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_PCS_PR3      0x000           /*  0x000  */      /*  0x000  */     /*  0x000  */    /*  0x000  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_PCS_PT2B     0x200           /*  0x200  */      /*  0x200  */     /*  0x200  */    /*  0x208  */                    
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_PCS_PT1      0x230           /*  0x230  */      /*  0x221  */     /*  0x220  */    /*  0x230  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_PCS_PT2      0x235           /*  0x235  */      /*  0x233  */     /*  0x235  */    /*  0x230  */   
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_PCS_PT3      0x000           /*  0x000  */      /*  0x000  */     /*  0x000  */    /*  0x000  */   
/*MT6139E*/ /*MT6218B~*/                                                                                                               
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_INIT         0x000                                                                       
/*MT6139E*/ /*MT6218B~*/ #define  PDATA_IDLE         0x000                                                                       
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/ /*----------------------------------------------*/
/*MT6139E*/ /*   APC Compensate Thresholds                  */
/*MT6139E*/ /*----------------------------------------------*/
/*MT6139E*/
/*MT6139E*/ #define    SECONDS2FRAME(n)        ((int)((n)*1000/4.165))
/*MT6139E*/ #define    VOLT2UVOLT(n)           ((int)((n)*1000000))
/*MT6139E*/ #define    TEMP2MTEMP(n)           ((int)((n)*1000))
/*MT6139E*/
/*MT6139E*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*MT6139E*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6139E*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*MT6139E*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*MT6139E*/
/*MT6139E*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*MT6139E*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6139E*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*MT6139E*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*MT6139E*/
/*MT6139E*/
/*MT6139E*/ /*----------------------------------------------*/
/*MT6139E*/ /*   Crystal parameter                          */
/*MT6139E*/ /*----------------------------------------------*/
/*MT6139E*/ #define Custom_RF_XO_CapID  22
/*MT6139E*/
/*MT6139E*/
/*MT6139E*//*----------------------------------------------*/
/*MT6139E*//*   0:GSM850 Signal go through GSM850, GSM900 Signal go through GSM900  (default)         */
/*MT6139E*//*   1:GSM850 Signal go through GSM900, GSM900 Signal go through GSM850  (default)         */
/*MT6139E*//*----------------------------------------------*/
/*MT6139E*/#define GSM850_GSM900_SWAP  0
/*MT6139E*//*----------------------------------------------*/
/*MT6139E*//*   0:DCS1800 Signal go through DCS1800, PCS1900 Signal go through PCS1900(default)         */
/*MT6139E*//*   1:DCS1800 Signal go through PCS1900, PCS1900 Signal go through DCS1800                  */
/*MT6139E*//*----------------------------------------------*/
/*MT6139E*/#define DCS1800_PCS1900_SWAP    0
/*MT6139E*/
/*============================================================================== */
/*MT6139E*//*======================================================================================== */
/*MT6139E*//*------------  TX GAIN Setting  ------------------*/
/*MT6139E*//* 0: TXDIVGC:01; TXMODGAIN: 100 (Default)         */     
/*MT6139E*//* 1: TXDIVGC:00; TXMODGAIN: 010 (0.5dB and 40kHz) */     
/*MT6139E*//* 2: TXDIVGC:00; TXMODGAIN: 100 (1.5dB and 40kHz) */
/*MT6139E*//*-------------------------------------------------*/
/*MT6139E*/#define DCS_TX_GAIN_SETTING     1
/*MT6139E*/#define PCS_TX_GAIN_SETTING     0
/*MT6139E*//*======================================================================================== */
/*MT6139E*/ 
/*MT6139E*/ /*----------------------------------------------*/                                 
/*MT6139E*/ /*   TX power rollback parameter                */                                 
/*MT6139E*/ /*----------------------------------------------*/                                 
/*MT6139E*/ /*Unit: 1/8 dB*/                                                                                   
/*MT6139E*/ /*GSM850 GMSK*/                                                                    
/*MT6139E*/ #define GSM850_TX_ROLLBACK_2T_GMSK 8                                               
/*MT6139E*/ #define GSM850_TX_ROLLBACK_3T_GMSK 24                                              
/*MT6139E*/ #define GSM850_TX_ROLLBACK_4T_GMSK 32                                              
/*MT6139E*/ #define GSM850_TX_ROLLBACK_5T_GMSK 40                                              
/*MT6139E*/                                                                                    
/*MT6139E*/ /*GSM GMSK*/                                                                       
/*MT6139E*/ #define GSM_TX_ROLLBACK_2T_GMSK 8                                                  
/*MT6139E*/ #define GSM_TX_ROLLBACK_3T_GMSK 24                                                 
/*MT6139E*/ #define GSM_TX_ROLLBACK_4T_GMSK 32                                                 
/*MT6139E*/ #define GSM_TX_ROLLBACK_5T_GMSK 40                                                 
/*MT6139E*/                                                                                    
/*MT6139E*/ /*DCS GMSK*/                                                                       
/*MT6139E*/ #define DCS_TX_ROLLBACK_2T_GMSK 8                                                  
/*MT6139E*/ #define DCS_TX_ROLLBACK_3T_GMSK 24                                                 
/*MT6139E*/ #define DCS_TX_ROLLBACK_4T_GMSK 32                                                 
/*MT6139E*/ #define DCS_TX_ROLLBACK_5T_GMSK 40                                                 
/*MT6139E*/                                                                                    
/*MT6139E*/ /*PCS GMSK*/                                                                       
/*MT6139E*/ #define PCS_TX_ROLLBACK_2T_GMSK 8                                                  
/*MT6139E*/ #define PCS_TX_ROLLBACK_3T_GMSK 24                                                 
/*MT6139E*/ #define PCS_TX_ROLLBACK_4T_GMSK 32                                                 
/*MT6139E*/ #define PCS_TX_ROLLBACK_5T_GMSK 40                                                                               
/*============================================================================== */
#endif










