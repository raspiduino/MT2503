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
 *   AD6546 RF constance defintion
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* --------------------------------------------------------------------------- */

#if !defined(AD6546_RF) 
   #error "rf files mismatch with compile option!"
#endif

/*--------------------------------------------------------*/
/*   Event Timing Define                                  */
/*--------------------------------------------------------*/
/*AD6546*/ #define FEM_SKY77523 
/*AD6546*/ //#define QB_ASM_TQM7M5008
/*AD6546*/ //#define LMSP4DNA_SKY77336                          /* For LIPTON Project */
/*AD6546*/ //#define PAM_RF7166

/*AD6546*/ #if IS_CHIP_MT6276 || IS_CHIP_MT6573
/*AD6546*//*MT6276 */ #define  QB_RX_FENA_2_FSYNC          64   /* this value shall be 4N+0                                        */  
/*AD6546*//*MT6276 */ #define  QB_RX_FSYNC_2_FENA           0                                                                         
/*AD6546*//*MT6276 */ #define  QB_TX_FENA_2_FSYNC         152   /* this value shall be 4N+0                                        */ 
/*AD6546*//*MT6276 */ #define  QB_TX_FSYNC_2_FENA          26   /* Update by RFWS timing fine tune 20090330                        */ 
/*AD6546*/ #elif IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*AD6546*//*MT6225~*/ #define  QB_RX_FENA_2_FSYNC          48   /* this value shall be 4N+0                                        */
/*AD6546*//*MT6225~*/ #define  QB_RX_FSYNC_2_FENA           0
/*AD6546*//*MT6225~*/ #define  QB_TX_FENA_2_FSYNC         152   /* this value shall be 4N+0                                        */
/*AD6546*//*MT6225~*/ #define  QB_TX_FSYNC_2_FENA          26   /* Update by RFWS timing fine tune 20090330                        */
/*AD6546*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*AD6546*//*MT6218~*/ #define  QB_RX_FENA_2_FSYNC          40   /* this value shall be 4N+0                                        */
/*AD6546*//*MT6218~*/ #define  QB_RX_FSYNC_2_FENA           0
/*AD6546*//*MT6218~*/ #define  QB_TX_FENA_2_FSYNC         152   /* this value shall be 4N+0                                        */
/*AD6546*//*MT6218~*/ #define  QB_TX_FSYNC_2_FENA          26   /* Update by RFWS timing fine tune 20090330                        */
/*AD6546*/ #else
/*AD6546*/ /*OTHERS*/ #define  QB_RX_FENA_2_FSYNC          35   /* this value shall be 4N+3                                        */
/*AD6546*/ /*OTHERS*/ #define  QB_RX_FSYNC_2_FENA           0
/*AD6546*/ /*OTHERS*/ #define  QB_TX_FENA_2_FSYNC         149   /* this value shall be 4N+1                                        */
/*AD6546*/ /*OTHERS*/ #define  QB_TX_FSYNC_2_FENA          26   /* Update by RFWS timing fine tune 20090330                        */
/*AD6546*/ #endif
/*AD6546*/         
/*AD6546*/ #if defined(QB_ASM_TQM7M5008)
/*TQM7M5008*//*AD6546*/   
/*TQM7M5008*//*AD6546*/#define  QB_SR1                     226             /* Let the 6*N + 4(QB) distance exist between SR1 & SR3              */     
/*TQM7M5008*//*AD6546*/#define  QB_SR2                     84              /* 44 */                                                                     
/*TQM7M5008*//*AD6546*/#define  QB_SR2M                    36              /* RX Interslot set Gain                                             */                                      
/*TQM7M5008*//*AD6546*/#define  QB_SR3                     0                                                                                   
/*TQM7M5008*//*AD6546*/#define  QB_PR1                     243                                                                                 
/*TQM7M5008*//*AD6546*/#define  QB_PR2                     35              /* 25 */                                                                     
/*TQM7M5008*//*AD6546*/#define  QB_PR3                     6                                                                                   
/*TQM7M5008*//*AD6546*/#define  QB_ST1                     226             /* send Power control and PLL setting                                */                         
/*TQM7M5008*//*AD6546*/#define  QB_PT2                     14              //13/* PA_EN must opened 19 QB after ST2B for AM Feedback loop stability */
/*TQM7M5008*//*AD6546*/#define  QB_ST2B                    (QB_PT2 +13)    //19/* ST2B must opened 115 QB after ST2 for enough OE internal feedback acquisition time, we must let VAPC on 2 us after PA_EN*/ /*Start PCL Calibration, the setting should 5us before APC on*/
/*TQM7M5008*//*AD6546*/#define  QB_ST2                     (QB_PT2 +143)   //144/* TX on should be more than 100us before ST2B                       */                                                      
/*TQM7M5008*//*AD6548*/#define  QB_ST3                     23              /*28*/
/*TQM7M5008*//*AD6548*/#define  QB_ST2M_G8                 22              /* Change mode GMSK->8PSK                                            */                                     
/*TQM7M5008*//*AD6548*/#define  QB_ST2M_8G                 22              /* Change mode 8PSK->GMSK                                            */ 
/*TQM7M5008*//*AD6548*/#define  QB_PT1                     248             //335
/*TQM7M5008*//*AD6548*/#define  QB_PT2B                    -4              //-6 /* Update by RFWS timing fine tune 20090330                          */
/*TQM7M5008*//*AD6548*/#define  QB_PT3                     25              //21/* Update by RFWS timing fine tune 20090330                          */
/*TQM7M5008*//*AD6546*/#define  QB_PT2M1_G8                18              /* TRSW Off when modulation mode is changing                         */                  
/*TQM7M5008*//*AD6546*/#define  QB_PT2M2_G8                2               /* TRSW On  when modulation mode change done                         */                  
/*TQM7M5008*//*AD6546*/#define  QB_PT2M1_8G                18              /* TRSW Off when modulation mode is changing                         */                  
/*TQM7M5008*//*AD6546*/#define  QB_PT2M2_8G                2               /* TRSW On  when modulation mode change done                         */                  
/*TQM7M5008*//*AD6546*/
/*AD6546*/ #elif defined(FEM_SKY77523)
/*SKY77523*//*AD6546*/
/*SKY77523*//*AD6546*/#define  QB_SR1                      226             /* Let the 6*N + 4(QB) distance exist between SR1 & SR3 */     
/*SKY77523*//*AD6546*/#define  QB_SR2                      84              /* 44  */                                                    
/*SKY77523*//*AD6546*/#define  QB_SR2M                     36              /*RX Interslot set Gain*/                                      
/*SKY77523*//*AD6546*/#define  QB_SR3                      0                                                                   
/*SKY77523*//*AD6546*/#define  QB_PR1                      243                                                                 
/*SKY77523*//*AD6546*/#define  QB_PR2                      35              /* 25 */                                                   
/*SKY77523*//*AD6546*/#define  QB_PR3                      6                                                                   
/*SKY77523*//*AD6546*/#define  QB_ST1                      226             /*send Power control and PLL setting*/                         
/*SKY77523*//*AD6546*/#define  QB_PT2                      4               //10/*PA_EN must opened 18 QB after ST2B for AM Feedback loop stability*/
/*SKY77523*//*AD6546*/#define  QB_ST2B                     (QB_PT2 +18)    //28 /*ST2B must opened 115 QB after ST2 for enough OE internal feedback acquisition time // we must let VAPC on 2 us after PA_EN  /*Start PCL Calibration, the setting should 5us before APC on*/
/*SKY77523*//*AD6546*/#define  QB_ST2                      (QB_PT2 +144)   //157// should be more than 100us before ST2B  /*TX on*/                                                      
/*SKY77523*//*AD6548*/#define  QB_ST3                      23
/*SKY77523*//*AD6548*/#define  QB_ST2M_G8                  10              /*Change mode GMSK->8PSK*/                                     
/*SKY77523*//*AD6548*/#define  QB_ST2M_8G                  10              /*Change mode 8PSK->GMSK*/                                     
/*SKY77523*//*AD6548*/#define  QB_PT1                      248
/*SKY77523*//*AD6548*/#define  QB_PT2B                     -7              //-6/* Update by RFWS timing fine tune 20090330                          */
/*SKY77523*//*AD6548*/#define  QB_PT3                      22              /* Update by RFWS timing fine tune 20090330                          */                                            
/*SKY77523*//*AD6546*/#define  QB_PT2M1_G8                 6               /* TRSW Off when modulation mode is changing                         */
/*SKY77523*//*AD6546*/#define  QB_PT2M2_G8                 2               /* TRSW On  when modulation mode change done                         */
/*SKY77523*//*AD6546*/#define  QB_PT2M1_8G                 6               /* TRSW Off when modulation mode is changing                         */
/*SKY77523*//*AD6546*/#define  QB_PT2M2_8G                 2               /* TRSW On  when modulation mode change done                         */
/*SKY77523*//*AD6546*/
/*AD6546*/ #elif defined(LMSP4DNA_SKY77336)
/*SKY77336*//*AD6546*/                   
/*SKY77336*//*AD6546*/#define  QB_SR1                      226            /* Let the 6*N + 4(QB) distance exist between SR1 & SR3              */     
/*SKY77336*//*AD6546*/#define  QB_SR2                      84             /* 44 */                                                                     
/*SKY77336*//*AD6546*/#define  QB_SR2M                     36             /* RX Interslot set Gain                                             */                                      
/*SKY77336*//*AD6546*/#define  QB_SR3                      0                                                                                   
/*SKY77336*//*AD6546*/#define  QB_PR1                      243                                                                                 
/*SKY77336*//*AD6546*/#define  QB_PR2                      35             /* 25 */                                                                     
/*SKY77336*//*AD6546*/#define  QB_PR3                      6                                                                                   
/*SKY77336*//*AD6546*/#define  QB_ST1                      226            /* send Power control and PLL setting                                */                         
/*SKY77336*//*AD6546*/#define  QB_PT2                      14             //10/* PA_EN must opened 19 QB after ST2B for AM Feedback loop stability */
/*SKY77336*//*AD6546*/#define  QB_ST2B                     (QB_PT2 +13)   //18/* ST2B must opened 115 QB after ST2 for enough OE internal feedback acquisition time, we must let VAPC on 2 us after PA_EN*/ /*Start PCL Calibration, the setting should 5us before APC on*/
/*SKY77336*//*AD6546*/#define  QB_ST2                      (QB_PT2 +143)  //144/* TX on should be more than 100us before ST2B                       */                                                      
/*SKY77336*//*AD6548*/#define  QB_ST3                      23             //27/*28*/
/*SKY77336*//*AD6548*/#define  QB_ST2M_G8                  10             /* Change mode GMSK->8PSK                                            */                                     
/*SKY77336*//*AD6548*/#define  QB_ST2M_8G                  10             /* Change mode 8PSK->GMSK                                            */ 
/*SKY77336*//*AD6548*/#define  QB_PT1                      248            //335
/*SKY77336*//*AD6548*/#define  QB_PT2B                     -6             //-4//-6
/*SKY77336*//*AD6548*/#define  QB_PT3                      22             //30//21
/*SKY77336*//*AD6546*/#define  QB_PT2M1_G8                 6              /* TRSW Off when modulation mode is changing                         */                  
/*SKY77336*//*AD6546*/#define  QB_PT2M2_G8                 2              /* TRSW On  when modulation mode change done                         */                  
/*SKY77336*//*AD6546*/#define  QB_PT2M1_8G                 6              /* TRSW Off when modulation mode is changing                         */                  
/*SKY77336*//*AD6546*/#define  QB_PT2M2_8G                 2              /* TRSW On  when modulation mode change done                         */                  
/*SKY77336*//*AD6546*/
/*AD6546*/ #elif defined(PAM_RF7166)
/*PAM_RF7166*//*AD6546*/
/*PAM_RF7166*//*AD6546*/#define  QB_SR1                    226            /* Let the 6*N + 4(QB) distance exist between SR1 & SR3              */
/*PAM_RF7166*//*AD6546*/#define  QB_SR2                    84             /* 44 */
/*PAM_RF7166*//*AD6546*/#define  QB_SR2M                   36             /* RX Interslot set Gain                                             */
/*PAM_RF7166*//*AD6546*/#define  QB_SR3                    0
/*PAM_RF7166*//*AD6546*/#define  QB_PR1                    243
/*PAM_RF7166*//*AD6546*/#define  QB_PR2                    35             /* 25 */
/*PAM_RF7166*//*AD6546*/#define  QB_PR3                    6
/*PAM_RF7166*//*AD6546*/#define  QB_ST1                    226            /* send Power control and PLL setting                                */
/*PAM_RF7166*//*AD6546*/#define  QB_PT2                    10             /* PA_EN must opened 19 QB after ST2B for AM Feedback loop stability */
/*PAM_RF7166*//*AD6546*/#define  QB_ST2B                   (QB_PT2 +18)   /* ST2B must opened 115 QB after ST2 for enough OE internal feedback acquisition time, we must let VAPC on 2 us after PA_EN*/ /*Start PCL Calibration, the setting should 5us before APC on*/
/*PAM_RF7166*//*AD6546*/#define  QB_ST2                    (QB_PT2 +144)  /* TX on should be more than 100us before ST2B                       */
/*PAM_RF7166*//*AD6548*/#define  QB_ST3                    23             /*28*/
/*PAM_RF7166*//*AD6548*/#define  QB_ST2M_G8                10             /* Change mode GMSK->8PSK                                            */
/*PAM_RF7166*//*AD6548*/#define  QB_ST2M_8G                10             /* Change mode 8PSK->GMSK                                            */
/*PAM_RF7166*//*AD6548*/#define  QB_PT1                    248            //335
/*PAM_RF7166*//*AD6548*/#define  QB_PT2B                   -6             //-4//-6
/*PAM_RF7166*//*AD6548*/#define  QB_PT3                    22             //21
/*PAM_RF7166*//*AD6546*/#define  QB_PT2M1_G8               6              /* TRSW Off when modulation mode is changing                         */
/*PAM_RF7166*//*AD6546*/#define  QB_PT2M2_G8               2              /* TRSW On  when modulation mode change done                         */
/*PAM_RF7166*//*AD6546*/#define  QB_PT2M1_8G               6              /* TRSW Off when modulation mode is changing                         */
/*PAM_RF7166*//*AD6546*/#define  QB_PT2M2_8G               2              /* TRSW On  when modulation mode change done                         */
/*PAM_RF7166*//*AD6546*/
/*AD6546*/ #endif
/*AD6546*/
/*AD6546*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*AD6548*/ #define  QB_APCON                    16   //17
/*AD6548*/ #define  QB_APCMID                   22
/*AD6548*/ #define  QB_APCOFF                    8   //9
/*AD6546*/ #else                                
/*AD6546*/ #define  QB_APCON                    21
/*AD6546*/ #define  QB_APCMID                   26
/*AD6546*/ #define  QB_APCOFF                    5
/*AD6546*/ #endif                               
/*AD6546*/ #define  QB_APCDACON                 99
/*AD6546*/
/*AD6546*/ #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
/*AD6546*//*MT6223~*/ #define  TX_PROPAGATION_DELAY         43
/*AD6546*/ #elif IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*AD6546*//*MT6223~*/ #define  TX_PROPAGATION_DELAY         42
/*AD6546*/ #elif IS_CHIP_MT6225_AND_LATTER_VERSION||IS_CHIP_MT6229||IS_CHIP_MT6268T
/*AD6546*//*MT6225~*/ #define  TX_PROPAGATION_DELAY         43//45
/*AD6546*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*AD6546*//*MT6218~*/ #define  TX_PROPAGATION_DELAY         39
/*AD6546*/ #else
/*AD6546*//*OTHERS*/  #define  TX_PROPAGATION_DELAY         36
/*AD6546*/ #endif
/*AD6546*/
   #ifndef __AST_TL1_TDD__
/*AD6546*/ #if IS_CHIP_MT6268T || IS_CHIP_MT6268H || IS_3G_CHIP || IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION
/*AD6546*/    #ifdef QB_ASM_TQM7M5008
/*AD6546*/ /*MT6268~*/ /*-------------------------------------*/
/*AD6546*/ /*MT6268~*/ /*   define  BPI data for AD6546       */
/*AD6546*/ /*MT6268~*/ /*-------------------------------------*/
/*AD6546*/ /*MT6268~*/ /*     PRCB : bit   pin                */
/*AD6546*/ /*MT6268~*/ /*             0    VC1                */
/*AD6546*/ /*MT6268~*/ /*             1    VC2                */
/*AD6546*/ /*MT6268~*/ /*             2    VC3                */
/*AD6546*/ /*MT6268~*/ /*             3    VC4                */
/*AD6546*/ /*MT6268~*/ /*             4    VDD                */
/*AD6546*/ /*MT6268~*/ /*             5    not used           */
/*AD6546*/ /*MT6268~*/ /*             6    PAEN               */
/*AD6546*/ /*MT6268~*/ /*             7    BANDSW             */
/*AD6546*/ /*MT6268~*/ /*             8    EDGE_MODE(not used)*/
/*AD6546*/ /*MT6268~*/ /*             9    RFVCOEN(used as GSM_ERR_DET_ID)*/
/*AD6546*/ /*MT6268~*/ /*            10    not used           */
/*AD6546*/ /*MT6268~*/ /*-------------------------------------*/
/*AD6546*/ /*MT6268~*/                                                 
/*AD6546*/ /*MT6268~*/ #if IS_CHIP_MT6268T_FC4
/*AD6546*/ /*MT6268~*/ /* Shift one bit for BPI5~9 in MT6268T_FC4 */
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR1        0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR2        0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR3        0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT1        0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2        0x130//0x50
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2B       0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT3        0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M1_G8   0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M2_G8   0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M1_8G   0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M2_8G   0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR1           0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR2           0x114//0x14
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT1           0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2           0x130//0x50
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2B          0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M1_G8      0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M2_G8      0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M1_8G      0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M2_8G      0x133//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR1           0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR2           0x096//0x16
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT1           0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2           0x170//0xD0
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2B          0x171//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M1_G8      0x171//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M2_G8      0x171//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M1_8G      0x171//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M2_8G      0x171//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR1           0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR2           0x112//0x12
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT1           0x110//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2           0x170//0xD0
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2B          0x171//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M1_G8      0x171//0xD1    
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M2_G8      0x171//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M1_8G      0x171//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M2_8G      0x171//0xD1
/*AD6546*/ /*MT6268~*/
/*AD6546*/ /*MT6268~*/ #elif IS_CHIP_MT6270A || IS_CHIP_MT6268H || IS_CHIP_MT6276 || IS_CHIP_MT6573
/*AD6546*/ /*MT6268~*/ /* ORI: BPI[6]=PAEN, BPI[7]=BANDSW, BPI[8]=EDGE_MODE, BPI[9]=RFVCOEN */
/*AD6546*/ /*MT6268~*/ /*  76: BPI[5]=PAEN, BPI[6]=BANDSW, BPI[7]=EDGE_MODE, BPI[9]=RFVCOEN */
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR1        0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR2        0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR3        0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT1        0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2        0x230//0x250//0x50
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2B       0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT3        0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M1_G8   0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M2_G8   0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M1_8G   0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M2_8G   0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR2           0x214//0x14
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2           0x230//0x250//0x50
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2B          0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M1_G8      0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M2_G8      0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M1_8G      0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M2_8G      0x233//0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR2           0x216//0x16
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2           0x270//0x2D0//0xD0
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2B          0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M1_G8      0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M2_G8      0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M1_8G      0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M2_8G      0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR2           0x212//0x12
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2           0x270//0x2D0//0xD0
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2B          0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M1_G8      0x271//0x2D1//0xD1    
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M2_G8      0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M1_8G      0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M2_8G      0x271//0x2D1//0xD1
/*AD6546*/ /*MT6268~*/
/*AD6546*/ /*MT6268~*/ #else
/*AD6546*/ /*MT6268~*/
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR1        0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR2        0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR3        0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT1        0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2        0x250//0x50
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2B       0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT3        0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M1_G8   0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M2_G8   0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M1_8G   0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M2_8G   0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR2           0x214//0x14
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2           0x250//0x50
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2B          0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M1_G8      0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M2_G8      0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M1_8G      0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M2_8G      0x253//0x53
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR2           0x216//0x16
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2           0x2D0//0xD0
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2B          0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M1_G8      0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M2_G8      0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M1_8G      0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M2_8G      0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR2           0x212//0x12
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT1           0x210//0x10
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2           0x2D0//0xD0
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2B          0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT3           0x000//0x00
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M1_G8      0x2D1//0xD1    
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M2_G8      0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M1_8G      0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M2_8G      0x2D1//0xD1
/*AD6546*/ /*MT6268~*/ #endif
/*AD6546*/ /*MT6268~*/
/*AD6546*/ /*MT6268~*/ #define  PDATA_INIT              0x000//0x00                             
/*AD6546*/ /*MT6268~*/ #define  PDATA_IDLE              0x000//0x00
/*AD6546*/ /*MT6268~*/ #define GSM_ERR_DET_ID  9
/*AD6546*/    #endif
/*AD6546*/    #ifdef FEM_SKY77523
/*AD6546*/ /*MT6268~*/ /*-------------------------------------*/
/*AD6546*/ /*MT6268~*/ /*   define  BPI data for AD6546       */
/*AD6546*/ /*MT6268~*/ /*-------------------------------------*/
/*AD6546*/ /*MT6268~*/ /*     PRCB : bit   pin                */
/*AD6546*/ /*MT6268~*/ /*             0    ASM_2G_EN          */
/*AD6546*/ /*MT6268~*/ /*             1    ASM_3G_EN          */
/*AD6546*/ /*MT6268~*/ /*             2    VC2 TR_EN          */
/*AD6546*/ /*MT6268~*/ /*             3    VC3 BS0            */
/*AD6546*/ /*MT6268~*/ /*             4    ASM_VDD            */
/*AD6546*/ /*MT6268~*/ /*             5    GPS_FS             */
/*AD6546*/ /*MT6268~*/ /*             6    PAEN               */
/*AD6546*/ /*MT6268~*/ /*             7    BANDSW             */
/*AD6546*/ /*MT6268~*/ /*             8    EDGE_MODE(not used)*/
/*AD6546*/ /*MT6268~*/ /*             9    RFVCOEN(used as GSM_ERR_DET_ID)*/
/*AD6546*/ /*MT6268~*/ /*            10    not used           */
/*AD6546*/ /*MT6268~*/ /*-------------------------------------*/
/*AD6546*/ /*MT6268~*/                                                 
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR1        0x211
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR2        0x215
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PR3        0x000
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT1        0x211
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2        0x259
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2B       0x25D
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT3        0x000
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M1_G8   0x259
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M2_G8   0x25D
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M1_8G   0x259
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM850_PT2M2_8G   0x25D
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR1           0x211
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR2           0x215
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PR3           0x000
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT1           0x211
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2           0x259
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2B          0x25D
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT3           0x000
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M1_G8      0x259
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M2_G8      0x25D
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M1_8G      0x259
/*AD6546*/ /*MT6268~*/ #define  PDATA_GSM_PT2M2_8G      0x25D
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR1           0x211
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR2           0x295
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PR3           0x000
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT1           0x211
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2           0x2D9
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2B          0x2DD
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT3           0x000
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M1_G8      0x2D9
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M2_G8      0x2DD
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M1_8G      0x2D9
/*AD6546*/ /*MT6268~*/ #define  PDATA_DCS_PT2M2_8G      0x2DD
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR1           0x211
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR2           0x295
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PR3           0x000
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT1           0x211
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2           0x2D9
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2B          0x2DD
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT3           0x000
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M1_G8      0x2D9    
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M2_G8      0x2DD
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M1_8G      0x2D9
/*AD6546*/ /*MT6268~*/ #define  PDATA_PCS_PT2M2_8G      0x2DD
/*AD6546*/ /*MT6268~*/ #define  PDATA_INIT              0x000                             
/*AD6546*/ /*MT6268~*/ #define  PDATA_IDLE              0x000
/*AD6546*/ /*MT6268~*/ #define GSM_ERR_DET_ID  9
/*AD6546*/    #endif
/*AD6546*/
/*AD6546*/ #else
/*AD6546*/
/*AD6546*/    #ifdef FEM_SKY77523
/*AD6546*//*FEM_SKY77523*//*-----------------------------------------------------------*/
/*AD6546*//*FEM_SKY77523*//*   define  BPI data for (shall be modified by real case)   */
/*AD6546*//*FEM_SKY77523*//*-----------------------------------------------------------*/
/*AD6546*//*FEM_SKY77523*//*      PRCB : bit   pin                                     */
/*AD6546*//*FEM_SKY77523*//*              0    TR_EN                                   */
/*AD6546*//*FEM_SKY77523*//*              1    BS0 (High/low sub-band select)          */
/*AD6546*//*FEM_SKY77523*//*              2    not used                                */
/*AD6546*//*FEM_SKY77523*//*              3    not used                                */
/*AD6546*//*FEM_SKY77523*//*              4    PA_EN                                   */
/*AD6546*//*FEM_SKY77523*//*              5    BS1 (High/low band select)              */
/*AD6546*//*FEM_SKY77523*//*-----------------------------------------------------------*/
/*AD6546*//*FEM_SKY77523*/
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PR1             0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PR2             0x01
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PR3             0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PT1             0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PT2             0x12
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PT2B            0x13
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PT2M1_G8        0x12
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PT2M2_G8        0x13
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PT2M1_8G        0x12
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PT2M2_8G        0x13
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM850_PT3             0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PR1                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PR2                0x03
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PR3                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PT1                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PT2                0x12
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PT2B               0x13
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PT2M1_G8           0x12
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PT2M2_G8           0x13
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PT2M1_8G           0x12
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PT2M2_8G           0x13
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_GSM_PT3                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PR1                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PR2                0x21
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PR3                0x00      
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PT1                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PT2                0x32
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PT2B               0x33
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PT2M1_G8           0x32
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PT2M2_G8           0x33
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PT2M1_8G           0x32
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PT2M2_8G           0x33
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_DCS_PT3                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PR1                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PR2                0x23
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PR3                0x00   
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PT1                0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PT2                0x32
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PT2B               0x33
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PT2M1_G8           0x32
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PT2M2_G8           0x33
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PT2M1_8G           0x32
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PT2M2_8G           0x33
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_PCS_PT3                0x00
/*AD6546*//*FEM_SKY77523*/ 
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_INIT                   0x00
/*AD6546*//*FEM_SKY77523*/ #define  PDATA_IDLE                   0x00
/*AD6546*/    #endif
/*AD6546*/
/*AD6546*/    #ifdef QB_ASM_TQM7M5008
/*AD6546*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*QB_ASM_TQM7M5008*//*   define  BPI data for (shall be modified by real case)   */
/*AD6546*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*QB_ASM_TQM7M5008*//*      PRCB : bit   pin                                     */
/*AD6546*//*QB_ASM_TQM7M5008*//*              0    VC2                                     */
/*AD6546*//*QB_ASM_TQM7M5008*//*              1    VC3                                     */
/*AD6546*//*QB_ASM_TQM7M5008*//*              2    VC1                                     */
/*AD6546*//*QB_ASM_TQM7M5008*//*              3    VDD                                     */
/*AD6546*//*QB_ASM_TQM7M5008*//*              4    PA_EN                                   */
/*AD6546*//*QB_ASM_TQM7M5008*//*              5    BANDSW                                  */
/*AD6546*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*QB_ASM_TQM7M5008*/
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR1             0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR2             0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR3             0x00
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT1             0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2             0x18
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2B            0x1B
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M1_G8        0x1B//0x19//0x18
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M2_G8        0x1B
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M1_8G        0x1B//0x19//0x18
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M2_8G        0x1B
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT3             0x00
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR1                0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR2                0x0C
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR3                0x00
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT1                0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2                0x18
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2B               0x1B
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M1_G8           0x1B//0x18
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M2_G8           0x1B
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M1_8G           0x1B//0x18
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M2_8G           0x1B
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT3                0x00
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR1                0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR2                0x09
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR3                0x00
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT1                0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2                0x38   
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2B               0x3A
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M1_G8           0x3A//0x38
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M2_G8           0x3A
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M1_8G           0x3A//0x38
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M2_8G           0x3A
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT3                0x00
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR1                0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR2                0x0D
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR3                0x00
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT1                0x08
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2                0x38
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2B               0x3A
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M1_G8           0x3A//0x38
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M2_G8           0x3A
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M1_8G           0x3A//0x38
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M2_8G           0x3A
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT3                0x00
/*AD6546*//*QB_ASM_TQM7M5008*/
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_INIT                   0x00
/*AD6546*//*QB_ASM_TQM7M5008*/ #define  PDATA_IDLE                   0x00
/*AD6546*/    #endif
/*AD6546*/
/*AD6546*/    #ifdef LMSP4DNA_SKY77336
/*AD6546*//*LMSP4DNA_SKY77336*//*-----------------------------------------------------------*/
/*AD6546*//*LMSP4DNA_SKY77336*//*   define  BPI data for (shall be modified by real case)   */
/*AD6546*//*LMSP4DNA_SKY77336*//*-----------------------------------------------------------*/
/*AD6546*//*LMSP4DNA_SKY77336*//*      PRCB : bit   pin                                     */
/*AD6546*//*LMSP4DNA_SKY77336*//*              0    BANDSW                                  */
/*AD6546*//*LMSP4DNA_SKY77336*//*              1    ANT_SW2                                 */
/*AD6546*//*LMSP4DNA_SKY77336*//*              2                                            */
/*AD6546*//*LMSP4DNA_SKY77336*//*              3                                            */
/*AD6546*//*LMSP4DNA_SKY77336*//*              4    PA_EN                                   */
/*AD6546*//*LMSP4DNA_SKY77336*//*              5    ANT_SW1                                 */
/*AD6546*//*LMSP4DNA_SKY77336*//*-----------------------------------------------------------*/
/*AD6546*//*LMSP4DNA_SKY77336*/
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PR1             0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PR2             0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PR3             0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PT1             0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PT2             0x10
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PT2B            0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PT2M1_G8        0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PT2M2_G8        0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PT2M1_8G        0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PT2M2_8G        0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM850_PT3             0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PR1                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PR2                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PR3                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PT1                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PT2                0x10
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PT2B               0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PT2M1_G8           0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PT2M2_G8           0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PT2M1_8G           0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PT2M2_8G           0x30
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_GSM_PT3                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PR1                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PR2                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PR3                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PT1                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PT2                0x11   
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PT2B               0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PT2M1_G8           0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PT2M2_G8           0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PT2M1_8G           0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PT2M2_8G           0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_DCS_PT3                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PR1                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PR2                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PR3                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PT1                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PT2                0x11
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PT2B               0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PT2M1_G8           0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PT2M2_G8           0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PT2M1_8G           0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PT2M2_8G           0x13
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_PCS_PT3                0x00
/*AD6546*//*LMSP4DNA_SKY77336*/
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_INIT                   0x00
/*AD6546*//*LMSP4DNA_SKY77336*/ #define  PDATA_IDLE                   0x00
/*AD6546*/    #endif
/*AD6546*/    #ifdef PAM_RF7166
/*AD6546*//*PAM_RF7166*//*-----------------------------------------------------------*/
/*AD6546*//*PAM_RF7166*//*   define  BPI data for (shall be modified by real case)   */
/*AD6546*//*PAM_RF7166*//*-----------------------------------------------------------*/
/*AD6546*//*PAM_RF7166*//*      PRCB : bit   pin                                     */
/*AD6546*//*PAM_RF7166*//*              0    VDD                                     */
/*AD6546*//*PAM_RF7166*//*              1    not used                                */
/*AD6546*//*PAM_RF7166*//*              2    not used                                */
/*AD6546*//*PAM_RF7166*//*              3    not used                                */
/*AD6546*//*PAM_RF7166*//*              4    PA_EN                                   */
/*AD6546*//*PAM_RF7166*//*              5    BS1 (High/low band select)              */
/*AD6546*//*PAM_RF7166*//*-----------------------------------------------------------*/
/*AD6546*//*PAM_RF7166*/
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PR1             0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PR2             0x01
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PR3             0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PT1             0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PT2             0x12
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PT2B            0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PT3             0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PT2M1_G8        0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PT2M2_G8        0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PT2M1_8G        0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM850_PT2M2_8G        0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PR1                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PR2                0x03
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PR3                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PT1                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PT2                0x12
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PT2B               0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PT3                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PT2M1_G8           0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PT2M2_G8           0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PT2M1_8G           0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_GSM_PT2M2_8G           0x11
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PR1                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PR2                0x21
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PR3                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PT1                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PT2                0x32
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PT2B               0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PT3                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PT2M1_G8           0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PT2M2_G8           0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PT2M1_8G           0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_DCS_PT2M2_8G           0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PR1                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PR2                0x21
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PR3                0x00   
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PT1                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PT2                0x32
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PT2B               0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PT3                0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PT2M1_G8           0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PT2M2_G8           0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PT2M1_8G           0x31
/*AD6546*//*PAM_RF7166*/ #define  PDATA_PCS_PT2M2_8G           0x31
/*AD6546*//*PAM_RF7166*/
/*AD6546*//*PAM_RF7166*/ #define  PDATA_INIT                   0x00
/*AD6546*//*PAM_RF7166*/ #define  PDATA_IDLE                   0x00
/*AD6546*/    #endif
/*AD6546*/ #endif //end of MT6268
   #else
/*AD6546*//*AST_TL1_TDD*//*AST1001*/ #ifdef __AST1001__
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*   define  BPI data for (shall be modified by real case)   */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*      PRCB : bit   pin                                     */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              0    VC1                                     */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              1    VC2                                     */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              2    VC3                                     */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              3    VC4                                     */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              4    PA_EN                                   */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              5    BANDSW                                  */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              6    VDD                                     */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              7    IterRAT Sync.                           */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              8    RF Conflict                             */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*              9    NC                                      */
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR1             0x040
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR2             0x140
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR3             0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT1             0x040
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2             0x050
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2B            0x153
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M1_G8        0x150
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M2_G8        0x153
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M1_8G        0x150
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M2_8G        0x153
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT3             0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR1                0x040
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR2                0x144
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT1                0x040
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2                0x050
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2B               0x153
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M1_G8           0x150
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M2_G8           0x153
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M1_8G           0x150
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M2_8G           0x153
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR1                0x040
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR2                0x146
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT1                0x040
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2                0x070   
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2B               0x171
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M1_G8           0x170
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M2_G8           0x171
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M1_8G           0x170
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M2_8G           0x171
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR1                0x040
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR2                0x142
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT1                0x040
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2                0x070
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2B               0x171
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M1_G8           0x170
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M2_G8           0x171
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M1_8G           0x170
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M2_8G           0x171
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_INIT                   0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*//*QB_ASM_TQM7M5008*/ #define  PDATA_IDLE                   0x000
/*AD6546*//*AST_TL1_TDD*//*AST1001*/ #endif
/*AD6546*//*AST_TL1_TDD*//*AST2001*/ #ifdef __AST2001__
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #if IS_CHIP_MT6573
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*   define  BPI data for (shall be modified by real case)   */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*      PRCB : bit   pin                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              0    VC1                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              1    VC2                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              2    VC3                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              3    VC4                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              4    BANDSW                                  */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              5    PA_EN                                   */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              6    VDD                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              7    NC                                      */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              8    NC                                      */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              9    Conflict_2G                             */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR1             0x040//0x10
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR2             0x240//0x10
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR3             0x000//0x00       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT1             0x040//0x10       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2             0x060//0x250//0x50
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2B            0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M1_G8        0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M2_G8        0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M1_8G        0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M2_8G        0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT3             0x000//0x00       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR1                0x040//0x10       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR2                0x244//0x14       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR3                0x000//0x00       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT1                0x040//0x10       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2                0x060//0x250//0x50
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2B               0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M1_G8           0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M2_G8           0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M1_8G           0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M2_8G           0x263//0x253//0x53
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT3                0x000//0x00       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR1                0x040//0x10       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR2                0x246//0x16       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR3                0x000//0x00       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT1                0x040//0x10       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2                0x070//0x2D0//0xD0   
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2B               0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M1_G8           0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M2_G8           0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M1_8G           0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M2_8G           0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT3                0x000//0x00       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR1                0x040//0x10       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR2                0x242//0x12       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR3                0x000//0x00       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT1                0x040//0x10       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2                0x070//0x2D0//0xD0
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2B               0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M1_G8           0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M2_G8           0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M1_8G           0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M2_8G           0x271//0x2D1//0xD1
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT3                0x000//0x00       
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_IDLE                   0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_INIT                   0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #else // MT6236
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*   define  BPI data for (shall be modified by real case)   */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*      PRCB : bit   pin                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              0    VDD                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              1    VC1                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              2    VC2                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              3    VC3                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              4    PA_EN                                   */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              5    BANDSW                                  */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              6    VC4                                     */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              7    IterRAT Sync.                           */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              8    RF Conflict                             */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*              9    NC                                      */
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*//*-----------------------------------------------------------*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR1             0x001
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR2             0x101
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PR3             0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT1             0x001
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2             0x011
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2B            0x117
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M1_G8        0x111
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M2_G8        0x117
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M1_8G        0x111
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT2M2_8G        0x117
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM850_PT3             0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR1                0x001
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR2                0x109
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PR3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT1                0x001
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2                0x011
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2B               0x117
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M1_G8           0x111
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M2_G8           0x117
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M1_8G           0x111
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT2M2_8G           0x117
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_GSM_PT3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR1                0x001
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR2                0x10D
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PR3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT1                0x001
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2                0x031   
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2B               0x133
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M1_G8           0x131
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M2_G8           0x133
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M1_8G           0x131
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT2M2_8G           0x133
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_DCS_PT3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR1                0x001
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR2                0x105
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PR3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT1                0x001
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2                0x031
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2B               0x133
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M1_G8           0x131
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M2_G8           0x133
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M1_8G           0x131
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT2M2_8G           0x133
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_PCS_PT3                0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_INIT                   0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #define  PDATA_IDLE                   0x000
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/
/*AD6546*//*AST_TL1_TDD*//*AST2001*//*QB_ASM_TQM7M5008*/ #endif
/*AD6546*//*AST_TL1_TDD*//*AST2001*/ #endif
   #endif
/*AD6546*/
/*AD6546*//*----------------------------------------------*/
/*AD6546*//*   APC Compensate Thresholds                  */
/*AD6546*//*----------------------------------------------*/
/*AD6546*/
/*AD6546*/ #define    SECONDS2FRAME(n)                     ((int)((n)*1000/4.615))
/*AD6546*/ #define    VOLT2UVOLT(n)                        ((int)((n)*1000000))
/*AD6546*/ #define    TEMP2MTEMP(n)                        ((int)((n)*1000))
/*AD6546*/
/*AD6546*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*AD6546*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*AD6546*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*AD6546*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*AD6546*/
/*AD6546*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*AD6546*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*AD6546*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*AD6546*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*AD6546*/
/*AD6546*//*----------------------------------------------*/
/*AD6546*//*   Crystal parameter                          */
/*AD6546*//*----------------------------------------------*/
/*AD6546*/ #if  defined(AFC_VCXO)
/*AD6546*/ #define Custom_RF_XO_CapID  36	// 0318 Vito RF SOP
/*AD6546*/ #else
/*AD6546*/ #define Custom_RF_XO_CapID   0    // For AD6546 (AD6546 with VCTCXO)
/*AD6546*/ #endif
/*AD6546*/
/*AD6546*//*------------------------------------------------------------*/
/*AD6546*//*   0:Low band signal through PIN RX900 and RX900B (default) */
/*AD6546*//*   1:Low band signal through PIN RX850 and RX850B           */
/*AD6546*//*------------------------------------------------------------*/
/*AD6546*/ #define LOW_BAND_PATH 0
/*AD6546*/
/*AD6546*//*---------------------------------------------------------------*/
/*AD6546*//*   0:High band signal through PIN RX1800 and RX1800B (default) */
/*AD6546*//*   1:High band signal through PIN RX1900 and RX1900B           */
/*AD6546*//*---------------------------------------------------------------*/
/*AD6546*/ #define HIGH_BAND_PATH 0
/*AD6546*/
/*AD6546*//*======================================================================================== */
/*AD6546*//* for BT co_clock support                                                                 */
/*AD6546*//*======================================================================================== */
/*AD6546*/ #define IS_BT_COCLOCK_SUPPORT 0
/*AD6546*/
/*AD6546*//*======================================================================================== */
/*AD6546*//* for RF HW Disable EPSK TX support                                                       */
/*AD6546*//*======================================================================================== */
/*AD6546*/ #if defined __EPSK_TX__
/*AD6546*/ #define IS_HW_DISABLE_EPSK_TX_SUPPORT 0 /* 0: Don't modify HW */
/*AD6546*/ #else
/*AD6546*/ #define IS_HW_DISABLE_EPSK_TX_SUPPORT 1 /* 0: Don't modify HW, 1:modify HW*/
/*AD6546*/ #endif
/*AD6546*/
/*AD6546*/ /*----------------------------------------------*/
/*AD6546*/ /*   TX power rollback parameter                */
/*AD6546*/ /*----------------------------------------------*/
/*AD6546*/ /*Unit: 1/8 dB*/
/*AD6546*/ /*GSM850 GMSK*/
/*AD6546*/ #define GSM850_TX_ROLLBACK_2T_GMSK 8
/*AD6546*/ #define GSM850_TX_ROLLBACK_3T_GMSK 24
/*AD6546*/ #define GSM850_TX_ROLLBACK_4T_GMSK 32
/*AD6546*/ #define GSM850_TX_ROLLBACK_5T_GMSK 40
/*AD6546*/ 
/*AD6546*/ /*GSM GMSK*/
/*AD6546*/ #define GSM_TX_ROLLBACK_2T_GMSK 8
/*AD6546*/ #define GSM_TX_ROLLBACK_3T_GMSK 24
/*AD6546*/ #define GSM_TX_ROLLBACK_4T_GMSK 32
/*AD6546*/ #define GSM_TX_ROLLBACK_5T_GMSK 40
/*AD6546*/ 
/*AD6546*/ /*DCS GMSK*/
/*AD6546*/ #define DCS_TX_ROLLBACK_2T_GMSK 8
/*AD6546*/ #define DCS_TX_ROLLBACK_3T_GMSK 24
/*AD6546*/ #define DCS_TX_ROLLBACK_4T_GMSK 32
/*AD6546*/ #define DCS_TX_ROLLBACK_5T_GMSK 40
/*AD6546*/ 
/*AD6546*/ /*PCS GMSK*/
/*AD6546*/ #define PCS_TX_ROLLBACK_2T_GMSK 8
/*AD6546*/ #define PCS_TX_ROLLBACK_3T_GMSK 24
/*AD6546*/ #define PCS_TX_ROLLBACK_4T_GMSK 32
/*AD6546*/ #define PCS_TX_ROLLBACK_5T_GMSK 40
/*AD6546*/ 
/*AD6546*/ /*GSM850 EPSK*/
/*AD6546*/ #define GSM850_TX_ROLLBACK_2T_EPSK 8
/*AD6546*/ #define GSM850_TX_ROLLBACK_3T_EPSK 24
/*AD6546*/ #define GSM850_TX_ROLLBACK_4T_EPSK 32
/*AD6546*/ #define GSM850_TX_ROLLBACK_5T_EPSK 40
/*AD6546*/ 
/*AD6546*/ /*GSM EPSK*/
/*AD6546*/ #define GSM_TX_ROLLBACK_2T_EPSK 8
/*AD6546*/ #define GSM_TX_ROLLBACK_3T_EPSK 24
/*AD6546*/ #define GSM_TX_ROLLBACK_4T_EPSK 32
/*AD6546*/ #define GSM_TX_ROLLBACK_5T_EPSK 40
/*AD6546*/ 
/*AD6546*/ /*DCS EPSK*/
/*AD6546*/ #define DCS_TX_ROLLBACK_2T_EPSK 8
/*AD6546*/ #define DCS_TX_ROLLBACK_3T_EPSK 24
/*AD6546*/ #define DCS_TX_ROLLBACK_4T_EPSK 32
/*AD6546*/ #define DCS_TX_ROLLBACK_5T_EPSK 40
/*AD6546*/ 
/*AD6546*/ /*PCS EPSK*/
/*AD6546*/ #define PCS_TX_ROLLBACK_2T_EPSK 8
/*AD6546*/ #define PCS_TX_ROLLBACK_3T_EPSK 24
/*AD6546*/ #define PCS_TX_ROLLBACK_4T_EPSK 32
/*AD6546*/ #define PCS_TX_ROLLBACK_5T_EPSK 40
/*AD6546*/ /*============================================================================== */
#endif

