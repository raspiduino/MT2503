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
 *     MT6140D RF constance defintion
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */

#if !defined(MT6140D_RF)
   #error "rf files mismatch with compile option!"
#endif

/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*   PA option                                            */
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ #if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && (!IS_CHIP_MT6223)
/*MT6140D*/ //#define  HM090FD_RF3159
/*MT6140D*/ //#define  MURA541_RF3159
/*MT6140D*/ #define  MURA465_RF3159
/*MT6140D*/ //#define  MURA465_SKY77344
/*MT6140D*/ //#define  MURA382_RF3159
/*MT6140D*/ //#define  TQM6M5001_FEM
/*MT6140D*/ //#define  HM085TB_RF3159
/*MT6140D*/ //#define  RF9810
/*MT6140D*/ //#define  RPF89009B
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*   Event Timing Define                                  */
/*MT6140D*/ /*--------------------------------------------------------*/
/*MT6140D*/
/*MT6140D*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*//*MT6225~*/ #define  QB_RX_FENA_2_FSYNC          48   /* this value shall be 4N+0 */
/*MT6140D*//*MT6225~*/ #define  QB_RX_FSYNC_2_FENA           0
/*MT6140D*//*MT6225~*/ #define  QB_TX_FENA_2_FSYNC         152   /* this value shall be 4N+0 */
/*MT6140D*//*MT6225~*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6140D*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6140D*//*MT6218~*/ #define  QB_RX_FENA_2_FSYNC          40   /* this value shall be 4N+0 */
/*MT6140D*//*MT6218~*/ #define  QB_RX_FSYNC_2_FENA           0
/*MT6140D*//*MT6218~*/ #define  QB_TX_FENA_2_FSYNC         152   /* this value shall be 4N+0 */
/*MT6140D*//*MT6218~*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6140D*/ #else
/*MT6140D*/ /*OTHERS*/ #define  QB_RX_FENA_2_FSYNC          35   /* this value shall be 4N+3 */
/*MT6140D*/ /*OTHERS*/ #define  QB_RX_FSYNC_2_FENA           0
/*MT6140D*/ /*OTHERS*/ #define  QB_TX_FENA_2_FSYNC         149   /* this value shall be 4N+1 */
/*MT6140D*/ /*OTHERS*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6140D*/ #endif
/*MT6140D*/                                           /*           |--(N:SR3 data number)                     */
/*MT6140D*/ #ifdef MURA465_SKY77344
/*MT6140D*/ #define  QB_SR1                     212   /* Let the 6*N + 4(QB) distance exist between SR1 & SR3 */
/*MT6140D*/ #define  QB_SR2                      65
/*MT6140D*/ #define  QB_SR3                       0
/*MT6140D*/ #define  QB_SR2M                     44
/*MT6140D*/ #define  QB_PR1                     243
/*MT6140D*/ #define  QB_PR2                      25
/*MT6140D*/ #define  QB_PR3                       6
/*MT6140D*/ #define  QB_PR2M1                    36
/*MT6140D*/ #define  QB_PR2M2                    36
/*MT6140D*/ #define  QB_ST1                     304
/*MT6140D*/ #define  QB_ST2                     140
/*MT6140D*/ #define  QB_ST2B                    120
/*MT6140D*/ #define  QB_ST3                      23
/*MT6140D*/ #define  QB_ST2M_G8                   6
/*MT6140D*/ #define  QB_ST2M_8G                  20
/*MT6140D*/ #define  QB_PT1                     335
/*MT6140D*/ #define  QB_PT2                      12
/*MT6140D*/ #define  QB_PT2B                      2
/*MT6140D*/ #define  QB_PT3                      25
/*MT6140D*/ #define  QB_PT2M1_G8                  4
/*MT6140D*/ #define  QB_PT2M2_G8                  0
/*MT6140D*/ #define  QB_PT2M3_G8                 -1
/*MT6140D*/ #define  QB_PT2M1_8G                 15
/*MT6140D*/ #define  QB_PT2M2_8G                 14
/*MT6140D*/ #define  QB_PT2M3_8G                 13
/*MT6140D*/
/*MT6140D*/ #else /*default setting*/
/*MT6140D*/ #define  QB_SR1                     212   /* Let the 6*N + 4(QB) distance exist between SR1 & SR3 */
/*MT6140D*/ #define  QB_SR2                      65
/*MT6140D*/ #define  QB_SR3                       0
/*MT6140D*/ #define  QB_SR2M                     44
/*MT6140D*/ #define  QB_PR1                     243
/*MT6140D*/ #define  QB_PR2                      25
/*MT6140D*/ #define  QB_PR3                       6
/*MT6140D*/ #define  QB_PR2M1                    36
/*MT6140D*/ #define  QB_PR2M2                    36
/*MT6140D*/ #define  QB_ST1                     304
/*MT6140D*/ #define  QB_ST2                     140
/*MT6140D*/ #define  QB_ST2B                    120
/*MT6140D*/ #define  QB_ST3                      23
/*MT6140D*/ #define  QB_ST2M_G8                  11
/*MT6140D*/ #define  QB_ST2M_8G                  11
/*MT6140D*/ #define  QB_PT1                     335
/*MT6140D*/ #define  QB_PT2                      18   /*RF3159*/
/*MT6140D*/ #define  QB_PT2B                      6   /*RF3159*/
/*MT6140D*/ /*#define  QB_PT2                      30 SKY77340 */
/*MT6140D*/ /*#define  QB_PT2B                      3 SKY77340 */
/*MT6140D*/ #define  QB_PT3                      25
/*MT6140D*/ #define  QB_PT2M1_G8                  4
/*MT6140D*/ #define  QB_PT2M2_G8                  3
/*MT6140D*/ #define  QB_PT2M3_G8                  2
/*MT6140D*/ #define  QB_PT2M1_8G                 11
/*MT6140D*/ #define  QB_PT2M2_8G                 10
/*MT6140D*/ #define  QB_PT2M3_8G                  9
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*/ #define  QB_APCON                    18
/*MT6140D*/ #define  QB_APCMID                   24
/*MT6140D*/ #define  QB_APCOFF                    6
/*MT6140D*/ #else
/*MT6140D*/ #define  QB_APCON                    22
/*MT6140D*/ #define  QB_APCMID                   29
/*MT6140D*/ #define  QB_APCOFF                    2
/*MT6140D*/ #endif
/*MT6140D*/ #define  QB_APCDACON                 99//21
/*MT6140D*/
/*MT6140D*/ #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6140D*//*MT6223~*/ #define  TX_PROPAGATION_DELAY         43
/*MT6140D*/ #elif IS_CHIP_MT6225_AND_LATTER_VERSION||IS_CHIP_MT6229||IS_CHIP_MT6268T
/*MT6140D*//*MT6225~*/ #define  TX_PROPAGATION_DELAY         45
/*MT6140D*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6140D*//*MT6218~*/ #define  TX_PROPAGATION_DELAY         39
/*MT6140D*/ #else
/*MT6140D*//*OTHERS*/  #define  TX_PROPAGATION_DELAY         36
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/
/*MT6140D*/ #if  IS_CHIP_MT6205
/*MT6140D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*MT6205*/ /*   define  BPI data for MT6140 (shall be modified by real case)    */
/*MT6140D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*MT6205*/ /*    PRCB : bit   pin                                    */
/*MT6140D*/ /*MT6205*/ /*            0    VDD                                    */
/*MT6140D*/ /*MT6205*/ /*            1    VC3                                    */
/*MT6140D*/ /*MT6205*/ /*            2    VC1                                    */
/*MT6140D*/ /*MT6205*/ /*            3    VC2                                    */
/*MT6140D*/ /*MT6205*/ /*            4    PAEN                                   */
/*MT6140D*/ /*MT6205*/ /*            5    DCS BANDSW                             */
/*MT6140D*/ /*MT6205*/ /*            6    not used                               */
/*MT6140D*/ /*MT6205*/ /*            7    not used                               */
/*MT6140D*/ /*MT6205*/ /*            8    not used                               */
/*MT6140D*/ /*MT6205*/ /*            9    not used                               */
/*MT6140D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GMSK    0x000
/*MT6140D*/ /*MT6205*/ #define  PDATA_8PSK    0x000  /* not support 8PSK */
/*MT6140D*/ /*MT6205*/ #define  PDATA_RFDOO   0x000  /* not support RFDOO */
/*MT6140D*/ /*MT6205*/                                 /*Murata 382ASM + RF3159*/    /*  TQM6M5001   */             /* HITACHI C085 + RF3159  */
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PR1        ( 0x001 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x006 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PR2        ( 0x001 | PDATA_RFDOO )  /*( 0x002 | PDATA_RFDOO  ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PR3        ( 0x001               )  /*( 0x000                ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PR2M1      ( 0x001 | PDATA_RFDOO )  /*( 0x002 | PDATA_RFDOO  ) */    /*( 0x006 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PR2M2      ( 0x001 | PDATA_RFDOO )  /*( 0x002 | PDATA_RFDOO  ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PT1        ( 0x001 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x010 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PT2        ( 0x011 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x016 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PT2B       ( 0x01B | PDATA_RFDOO )  /*( 0x012 | PDATA_RFDOO  ) */    /*( 0x016 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM850_PT3        ( 0x001               )  /*( 0x000                ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PR1           ( 0x005 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x006 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PR2           ( 0x005 | PDATA_RFDOO )  /*( 0x00A | PDATA_RFDOO  ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PR3           ( 0x001               )  /*( 0x000                ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PR2M1         ( 0x005 | PDATA_RFDOO )  /*( 0x00A | PDATA_RFDOO  ) */    /*( 0x006 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PR2M2         ( 0x005 | PDATA_RFDOO )  /*( 0x00A | PDATA_RFDOO  ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PT1           ( 0x001 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x010 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PT2           ( 0x011 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x016 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PT2B          ( 0x01B | PDATA_RFDOO )  /*( 0x012 | PDATA_RFDOO  ) */    /*( 0x016 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_GSM_PT3           ( 0x001               )  /*( 0x000                ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PR1           ( 0x009 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x00A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PR2           ( 0x009 | PDATA_RFDOO )  /*( 0x006 | PDATA_RFDOO  ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PR3           ( 0x001               )  /*( 0x000                ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PR2M1         ( 0x009 | PDATA_RFDOO )  /*( 0x006 | PDATA_RFDOO  ) */    /*( 0x00A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PR2M2         ( 0x009 | PDATA_RFDOO )  /*( 0x006 | PDATA_RFDOO  ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PT1           ( 0x001 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x030 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PT2           ( 0x031 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x03A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PT2B          ( 0x033 | PDATA_RFDOO )  /*( 0x016 | PDATA_RFDOO  ) */    /*( 0x03A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_DCS_PT3           ( 0x001               )  /*( 0x000                ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PR1           ( 0x00D | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x00A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PR2           ( 0x00D | PDATA_RFDOO )  /*( 0x00E | PDATA_RFDOO  ) */    /*( 0x002 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PR3           ( 0x001               )  /*( 0x000                ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PR2M1         ( 0x00D | PDATA_RFDOO )  /*( 0x00E | PDATA_RFDOO  ) */    /*( 0x00A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PR2M2         ( 0x00D | PDATA_RFDOO )  /*( 0x00E | PDATA_RFDOO  ) */    /*( 0x002 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PT1           ( 0x001 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x030 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PT2           ( 0x031 | PDATA_RFDOO )  /*( 0x000 | PDATA_RFDOO  ) */    /*( 0x03A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PT2B          ( 0x033 | PDATA_RFDOO )  /*( 0x016 | PDATA_RFDOO  ) */    /*( 0x03A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_PCS_PT3           ( 0x001               )  /*( 0x000                ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6205*/ #define  PDATA_INIT                0x001                  /*  0x000                  */    /*  0x000                */
/*MT6140D*/ /*MT6205*/ #define  PDATA_IDLE                0x001                  /*  0x000                  */    /*  0x000                */
/*MT6140D*/ #endif
/*MT6140D*/ #if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_CHIP_MT6223
/*MT6140D*/ /*MT6218~*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*MT6218~*/ /*   define  BPI data for MT6140 (shall be modified by real case)    */
/*MT6140D*/ /*MT6218~*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*MT6218~*/ /*    PRCB : bit   pin                                    */
/*MT6140D*/ /*MT6218~*/ /*            0    VDD                                    */
/*MT6140D*/ /*MT6218~*/ /*            1    VC3                                    */
/*MT6140D*/ /*MT6218~*/ /*            2    VC1                                    */
/*MT6140D*/ /*MT6218~*/ /*            3    VC2                                    */
/*MT6140D*/ /*MT6218~*/ /*            4    PAEN                                   */
/*MT6140D*/ /*MT6218~*/ /*            5    DCS BANDSW                             */
/*MT6140D*/ /*MT6218~*/ /*            6    not used                               */
/*MT6140D*/ /*MT6218~*/ /*            7    not used                               */
/*MT6140D*/ /*MT6218~*/ /*            8    not used                               */
/*MT6140D*/ /*MT6218~*/ /*            9    RFVCOEN                                */
/*MT6140D*/ /*MT6218~*/ /*--------------------------------------------------------*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GMSK    0x000
/*MT6140D*/ /*MT6218~*/ #define  PDATA_8PSK    0x000   /* not support 8PSK */
/*MT6140D*/ /*MT6218~*/ #define  PDATA_RFDOO   0x200
/*MT6140D*/ /*MT6218~*/                                 /*Murata 382ASM + RF3159*/        /*  TQM6M5001   */              /* HITACHI C085 + RF3159  */
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PR1        ( 0x001 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x006 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PR2        ( 0x001 | PDATA_RFDOO    )  /* ( 0x002 | PDATA_RFDOO   ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PR3        ( 0x001                  )  /* ( 0x000                 ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PR2M1      ( 0x001 | PDATA_RFDOO    )  /* ( 0x002 | PDATA_RFDOO   ) */    /*( 0x006 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PR2M2      ( 0x001 | PDATA_RFDOO    )  /* ( 0x002 | PDATA_RFDOO   ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PT1        ( 0x001 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x010 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PT2        ( 0x011 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x016 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PT2B       ( 0x01B | PDATA_RFDOO    )  /* ( 0x012 | PDATA_RFDOO   ) */    /*( 0x016 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM850_PT3        ( 0x001                  )  /* ( 0x000                 ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PR1           ( 0x005 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x006 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PR2           ( 0x005 | PDATA_RFDOO    )  /* ( 0x00A | PDATA_RFDOO   ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PR3           ( 0x001                  )  /* ( 0x000                 ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PR2M1         ( 0x005 | PDATA_RFDOO    )  /* ( 0x00A | PDATA_RFDOO   ) */    /*( 0x006 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PR2M2         ( 0x005 | PDATA_RFDOO    )  /* ( 0x00A | PDATA_RFDOO   ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PT1           ( 0x001 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x010 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PT2           ( 0x011 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x016 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PT2B          ( 0x01B | PDATA_RFDOO    )  /* ( 0x012 | PDATA_RFDOO   ) */    /*( 0x016 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_GSM_PT3           ( 0x001                  )  /* ( 0x000                 ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PR1           ( 0x009 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x00A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PR2           ( 0x009 | PDATA_RFDOO    )  /* ( 0x006 | PDATA_RFDOO   ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PR3           ( 0x001                  )  /* ( 0x000                 ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PR2M1         ( 0x009 | PDATA_RFDOO    )  /* ( 0x006 | PDATA_RFDOO   ) */    /*( 0x00A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PR2M2         ( 0x009 | PDATA_RFDOO    )  /* ( 0x006 | PDATA_RFDOO   ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PT1           ( 0x001 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x030 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PT2           ( 0x031 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x03A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PT2B          ( 0x033 | PDATA_RFDOO    )  /* ( 0x016 | PDATA_RFDOO   ) */    /*( 0x03A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_DCS_PT3           ( 0x001                  )  /* ( 0x000                 ) */    /*( 0x000 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PR1           ( 0x00D | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x00A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PR2           ( 0x00D | PDATA_RFDOO    )  /* ( 0x00E | PDATA_RFDOO   ) */    /*( 0x002 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PR3           ( 0x001                  )  /* ( 0x000                 ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PR2M1         ( 0x00D | PDATA_RFDOO    )  /* ( 0x00E | PDATA_RFDOO   ) */    /*( 0x00A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PR2M2         ( 0x00D | PDATA_RFDOO    )  /* ( 0x00E | PDATA_RFDOO   ) */    /*( 0x002 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PT1           ( 0x001 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x030 | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PT2           ( 0x031 | PDATA_RFDOO    )  /* ( 0x000 | PDATA_RFDOO   ) */    /*( 0x03A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PT2B          ( 0x033 | PDATA_RFDOO    )  /* ( 0x016 | PDATA_RFDOO   ) */    /*( 0x03A | PDATA_RFDOO )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_PCS_PT3           ( 0x001                  )  /* ( 0x000                 ) */    /*( 0x000               )*/
/*MT6140D*/ /*MT6218~*/ #define  PDATA_INIT                0x001                     /*   0x000                   */    /*  0x000                */
/*MT6140D*/ /*MT6218~*/ #define  PDATA_IDLE                0x001                     /*   0x000                   */    /*  0x000                */
/*MT6140D*/ #endif
/*MT6140D*/ #if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION && (!IS_CHIP_MT6223)
/*MT6140D*/ /*MT6229~*/ /*------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*   define  BPI data for MT6140 (shall be modified by real case)   */
/*MT6140D*/ /*MT6229~*/ /*------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*    PRCB : bit   pin(MURATA 382)  pin (others)                    */
/*MT6140D*/ /*MT6229~*/ /*            0    VDD              VC2                             */
/*MT6140D*/ /*MT6229~*/ /*            1    VC3              VC3                             */
/*MT6140D*/ /*MT6229~*/ /*            2    VC1              VC1                             */
/*MT6140D*/ /*MT6229~*/ /*            3    VC2              not used                        */
/*MT6140D*/ /*MT6229~*/ /*            4    PAEN             PAEN                            */
/*MT6140D*/ /*MT6229~*/ /*            5    DCS BANDSW       DCS BANDSW                      */
/*MT6140D*/ /*MT6229~*/ /*            6    not used         not used                        */
/*MT6140D*/ /*MT6229~*/ /*            7    PA EDGE MODE     PA EDGE MODE                    */
/*MT6140D*/ /*MT6229~*/ /*            8    not used         not used                        */
/*MT6140D*/ /*MT6229~*/ /*            9    RFVCOEN          RFVCOEN                         */
/*MT6140D*/ /*MT6229~*/ /*------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ #define  PDATA_GMSK    0x000
/*MT6140D*/ /*MT6229~*/ #define  PDATA_8PSK    0x080    /*!!! 0x040 For RACHEL35 and DESHENG35 */
/*MT6140D*/ /*MT6229~*/ #define  PDATA_RFDOO   0x200
/*MT6140D*/ /*MT6229~*/
/*MT6140D*/ /*MT6229~*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #ifdef  MURA465_SKY77344
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PR1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PR2        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PR3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PR2M1      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PR2M2      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT2        ( 0x010 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT2B       ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT2M1_G8   ( 0x001 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT2M2_G8   ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT2M3_G8   ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT2M1_8G   ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT2M2_8G   ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM850_PT2M3_8G   ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT2           ( 0x010 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT2B          ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT2M1_G8      ( 0x001 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT2M2_G8      ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT2M3_G8      ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT2M1_8G      ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT2M2_8G      ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_GSM_PT2M3_8G      ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT2           ( 0x030 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT2B          ( 0x036 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT2M1_G8      ( 0x026 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT2M2_G8      ( 0x036 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT2M3_G8      ( 0x036 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT2M1_8G      ( 0x026 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT2M2_8G      ( 0x036 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_DCS_PT2M3_8G      ( 0x036 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PR1           ( 0x004 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PR2           ( 0x004 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PR2M1         ( 0x004 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PR2M2         ( 0x004 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT2           ( 0x030 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT2B          ( 0x036 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT2M1_G8      ( 0x026 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT2M2_G8      ( 0x036 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT2M3_G8      ( 0x036 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT2M1_8G      ( 0x026 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT2M2_8G      ( 0x036 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_PCS_PT2M3_8G      ( 0x036 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_INIT                0x000
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #define  PDATA_IDLE                0x000
/*MT6140D*/ /*MT6229~*//*MURA465_SKY77344*/ #endif
/*MT6140D*/ /*MT6229~*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #ifdef  HM090FD_RF3159
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PR1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PR2        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PR3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PR2M1      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PR2M2      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT2        ( 0x010 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT2B       ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT2M1_G8   ( 0x004 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT2M2_G8   ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT2M3_G8   ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT2M1_8G   ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT2M2_8G   ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM850_PT2M3_8G   ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT2           ( 0x010 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT2B          ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT2M1_G8      ( 0x004 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT2M2_G8      ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT2M3_G8      ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT2M1_8G      ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT2M2_8G      ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_GSM_PT2M3_8G      ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT2           ( 0x030 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT2B          ( 0x031 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT2M1_G8      ( 0x021 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT2M2_G8      ( 0x031 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT2M3_G8      ( 0x031 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT2M1_8G      ( 0x031 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT2M2_8G      ( 0x031 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_DCS_PT2M3_8G      ( 0x031 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT2           ( 0x030 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT2B          ( 0x031 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT2M1_G8      ( 0x021 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT2M2_G8      ( 0x031 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT2M3_G8      ( 0x031 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT2M1_8G      ( 0x031 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT2M2_8G      ( 0x031 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_PCS_PT2M3_8G      ( 0x031 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_INIT                0x000
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #define  PDATA_IDLE                0x000
/*MT6140D*/ /*MT6229~*/ /*HM090FD_RF3159*/ #endif
/*MT6140D*/ /*MT6229~*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #ifdef  MURA541_RF3159
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PR1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PR2        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PR3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PR2M1      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PR2M2      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT2        ( 0x010 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT2B       ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT2M1_G8   ( 0x001 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT2M2_G8   ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT2M3_G8   ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT2M1_8G   ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT2M2_8G   ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM850_PT2M3_8G   ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT2           ( 0x010 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT2B          ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT2M1_G8      ( 0x001 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT2M2_G8      ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT2M3_G8      ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT2M1_8G      ( 0x011 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT2M2_8G      ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_GSM_PT2M3_8G      ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT2           ( 0x030 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT2B          ( 0x034 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT2M1_G8      ( 0x024 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT2M2_G8      ( 0x034 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT2M3_G8      ( 0x034 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT2M1_8G      ( 0x034 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT2M2_8G      ( 0x034 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_DCS_PT2M3_8G      ( 0x034 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT2           ( 0x030 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT2B          ( 0x034 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT2M1_G8      ( 0x024 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT2M2_G8      ( 0x034 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT2M3_G8      ( 0x034 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT2M1_8G      ( 0x034 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT2M2_8G      ( 0x034 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_PCS_PT2M3_8G      ( 0x034 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_INIT                0x000
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #define  PDATA_IDLE                0x000
/*MT6140D*/ /*MT6229~*/ /*MURA541_RF3159*/ #endif
/*MT6140D*/ /*MT6229~*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #ifdef  MURA465_RF3159
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PR1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PR2        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PR3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PR2M1      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PR2M2      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT2        ( 0x010 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT2B       ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT2M1_G8   ( 0x004 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT2M2_G8   ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT2M3_G8   ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT2M1_8G   ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT2M2_8G   ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM850_PT2M3_8G   ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT2           ( 0x010 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT2B          ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT2M1_G8      ( 0x004 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT2M2_G8      ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT2M3_G8      ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT2M1_8G      ( 0x014 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT2M2_8G      ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_GSM_PT2M3_8G      ( 0x014 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PR2M1         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT2           ( 0x030 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT2B          ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT2M1_G8      ( 0x023 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT2M2_G8      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT2M3_G8      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT2M1_8G      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT2M2_8G      ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_DCS_PT2M3_8G      ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PR1           ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PR2           ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PR2M1         ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PR2M2         ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT2           ( 0x030 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT2B          ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT2M1_G8      ( 0x023 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT2M2_G8      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT2M3_G8      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT2M1_8G      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT2M2_8G      ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_PCS_PT2M3_8G      ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_INIT                0x000
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #define  PDATA_IDLE                0x000
/*MT6140D*/ /*MT6229~*/ /*MURA465_RF3159*/ #endif
/*MT6140D*/ /*MT6229~*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #ifdef  MURA382_RF3159
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PR1        ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PR2        ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PR3        ( 0x001                            )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PR2M1      ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PR2M2      ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT1        ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT2        ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT2B       ( 0x01B | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT3        ( 0x001                            )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT2M1_G8   ( 0x00B | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT2M2_G8   ( 0x01B | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT2M3_G8   ( 0x01B | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT2M1_8G   ( 0x01B | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT2M2_8G   ( 0x01B | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM850_PT2M3_8G   ( 0x01B | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PR1           ( 0x005 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PR2           ( 0x005 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PR3           ( 0x001                            )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PR2M1         ( 0x005 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PR2M2         ( 0x005 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT1           ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT2           ( 0x011 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT2B          ( 0x01B | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT3           ( 0x001                            )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT2M1_G8      ( 0x00B | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT2M2_G8      ( 0x01B | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT2M3_G8      ( 0x01B | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT2M1_8G      ( 0x01B | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT2M2_8G      ( 0x01B | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_GSM_PT2M3_8G      ( 0x01B | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PR1           ( 0x009 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PR2           ( 0x009 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PR3           ( 0x001                            )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PR2M1         ( 0x009 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PR2M2         ( 0x009 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT1           ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT2           ( 0x031 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT2B          ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT3           ( 0x001                            )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT2M1_G8      ( 0x023 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT2M2_G8      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT2M3_G8      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT2M1_8G      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT2M2_8G      ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_DCS_PT2M3_8G      ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PR1           ( 0x00D | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PR2           ( 0x00D | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PR3           ( 0x001                            )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PR2M1         ( 0x00D | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PR2M2         ( 0x00D | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT1           ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT2           ( 0x031 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT2B          ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT3           ( 0x001                            )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT2M1_G8      ( 0x023 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT2M2_G8      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT2M3_G8      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT2M1_8G      ( 0x033 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT2M2_8G      ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_PCS_PT2M3_8G      ( 0x033 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_INIT                0x001
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #define  PDATA_IDLE                0x001
/*MT6140D*/ /*MT6229~*/ /*MURA382_RF3159*/ #endif
/*MT6140D*/ /*MT6229~*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #ifdef  TQM6M5001_FEM
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PR1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PR2        ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PR3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PR2M1      ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PR2M2      ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT2        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT2B       ( 0x012 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT2M1_G8   ( 0x012 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT2M2_G8   ( 0x012 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT2M3_G8   ( 0x012 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT2M1_8G   ( 0x012 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT2M2_8G   ( 0x012 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM850_PT2M3_8G   ( 0x012 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PR2           ( 0x00A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PR2M1         ( 0x00A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PR2M2         ( 0x00A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT2B          ( 0x012 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT2M1_G8      ( 0x012 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT2M2_G8      ( 0x012 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT2M3_G8      ( 0x012 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT2M1_8G      ( 0x012 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT2M2_8G      ( 0x012 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_GSM_PT2M3_8G      ( 0x012 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PR2           ( 0x006 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PR2M1         ( 0x006 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PR2M2         ( 0x006 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT2B          ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT2M1_G8      ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT2M2_G8      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT2M3_G8      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT2M1_8G      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT2M2_8G      ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_DCS_PT2M3_8G      ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PR1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PR2           ( 0x00E | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PR2M1         ( 0x00E | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PR2M2         ( 0x00E | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT2B          ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT2M1_G8      ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT2M2_G8      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT2M3_G8      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT2M1_8G      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT2M2_8G      ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_PCS_PT2M3_8G      ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_INIT                0x000
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #define  PDATA_IDLE                0x000
/*MT6140D*/ /*MT6229~*/ /*TQM6M5001_FEM*/  #endif
/*MT6140D*/ /*MT6229~*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #ifdef  HM085TB_RF3159
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PR1        ( 0x006 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PR2        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PR3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PR2M1      ( 0x006 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PR2M2      ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT1        ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT2        ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT2B       ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT2M1_G8   ( 0x006 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT2M2_G8   ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT2M3_G8   ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT2M1_8G   ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT2M2_8G   ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM850_PT2M3_8G   ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PR1           ( 0x006 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PR2M1         ( 0x006 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT2           ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT2B          ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT2M1_G8      ( 0x006 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT2M2_G8      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT2M3_G8      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT2M1_8G      ( 0x016 | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT2M2_8G      ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_GSM_PT2M3_8G      ( 0x016 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PR1           ( 0x00A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PR2           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PR2M1         ( 0x00A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PR2M2         ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT2           ( 0x03A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT2B          ( 0x03A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT2M1_G8      ( 0x02A | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT2M2_G8      ( 0x03A | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT2M3_G8      ( 0x03A | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT2M1_8G      ( 0x03A | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT2M2_8G      ( 0x03A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_DCS_PT2M3_8G      ( 0x03A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PR1           ( 0x00A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PR2           ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PR2M1         ( 0x00A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PR2M2         ( 0x002 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT1           ( 0x000 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT2           ( 0x03A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT2B          ( 0x03A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT2M1_G8      ( 0x02A | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT2M2_G8      ( 0x03A | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT2M3_G8      ( 0x03A | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT2M1_8G      ( 0x03A | PDATA_RFDOO | PDATA_8PSK )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT2M2_8G      ( 0x03A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_PCS_PT2M3_8G      ( 0x03A | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_INIT                0x000
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #define  PDATA_IDLE                0x000
/*MT6140D*/ /*MT6229~*/ /*HM085TB_RF3159*/ #endif
/*MT6140D*/ /*MT6229~*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #ifdef  RF9810
/*MT6140D*/ /*MT6229~*/ /*RF9810*/
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PR1        ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PR2        ( 0x108 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PR3        ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PR2M1      ( 0x108 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PR2M2      ( 0x108 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT1        ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT2        ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT2B       ( 0x121 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT3        ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT2M1_G8   ( 0x121 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT2M2_G8   ( 0x121 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT2M3_G8   ( 0x121 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT2M1_8G   ( 0x121 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT2M2_8G   ( 0x121 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM850_PT2M3_8G   ( 0x121 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PR1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PR2           ( 0x108 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PR3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PR2M1         ( 0x108 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PR2M2         ( 0x108 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT2           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT2B          ( 0x101 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT2M1_G8      ( 0x101 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT2M2_G8      ( 0x101 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT2M3_G8      ( 0x101 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT2M1_8G      ( 0x101 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT2M2_8G      ( 0x101 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_GSM_PT2M3_8G      ( 0x101 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PR1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PR2           ( 0x104 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PR3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PR2M1         ( 0x104 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PR2M2         ( 0x104 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT2           ( 0x002 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT2B          ( 0x103 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT3           ( 0x000                            )       
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT2M1_G8      ( 0x103 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT2M2_G8      ( 0x103 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT2M3_G8      ( 0x103 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT2M1_8G      ( 0x103 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT2M2_8G      ( 0x103 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_DCS_PT2M3_8G      ( 0x103 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PR1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PR2           ( 0x104 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PR3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PR2M1         ( 0x104 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PR2M2         ( 0x104 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT2           ( 0x002 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT2B          ( 0x103 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT2M1_G8      ( 0x103 | PDATA_RFDOO | PDATA_8PSK )             
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT2M2_G8      ( 0x103 | PDATA_RFDOO | PDATA_8PSK )             
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT2M3_G8      ( 0x103 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT2M1_8G      ( 0x103 | PDATA_RFDOO | PDATA_8PSK )             
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT2M2_8G      ( 0x103 | PDATA_RFDOO              )             
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_PCS_PT2M3_8G      ( 0x103 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_INIT                0x000                              
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #define  PDATA_IDLE                0x000                              
/*MT6140D*/ /*MT6229~*/ /*RF9810*/         #endif 
/*MT6140D*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #ifdef  RPF89009B
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PR1        ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PR2        ( 0x10C | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PR3        ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PR2M1      ( 0x10C | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PR2M2      ( 0x10C | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT1        ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT2        ( 0x001 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT2B       ( 0x161 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT3        ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT2M1_G8   ( 0x161 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT2M2_G8   ( 0x161 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT2M3_G8   ( 0x161 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT2M1_8G   ( 0x161 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT2M2_8G   ( 0x161 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM850_PT2M3_8G   ( 0x161 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PR1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PR2           ( 0x10C | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PR3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PR2M1         ( 0x10C | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PR2M2         ( 0x10C | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT2           ( 0x001 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT2B          ( 0x141 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT2M1_G8      ( 0x141 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT2M2_G8      ( 0x141 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT2M3_G8      ( 0x141 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT2M1_8G      ( 0x141 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT2M2_8G      ( 0x141 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_GSM_PT2M3_8G      ( 0x141 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PR1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PR2           ( 0x10E | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PR3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PR2M1         ( 0x10E | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PR2M2         ( 0x10E | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT2           ( 0x003 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT2B          ( 0x143 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT3           ( 0x000                            )       
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT2M1_G8      ( 0x143 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT2M2_G8      ( 0x143 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT2M3_G8      ( 0x143 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT2M1_8G      ( 0x143 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT2M2_8G      ( 0x143 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_DCS_PT2M3_8G      ( 0x143 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PR1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PR2           ( 0x10E | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PR3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PR2M1         ( 0x10E | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PR2M2         ( 0x10E | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT1           ( 0x000 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT2           ( 0x003 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT2B          ( 0x143 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT3           ( 0x000                            ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT2M1_G8      ( 0x143 | PDATA_RFDOO | PDATA_8PSK )             
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT2M2_G8      ( 0x143 | PDATA_RFDOO | PDATA_8PSK )             
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT2M3_G8      ( 0x143 | PDATA_RFDOO | PDATA_8PSK ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT2M1_8G      ( 0x143 | PDATA_RFDOO | PDATA_8PSK )             
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT2M2_8G      ( 0x143 | PDATA_RFDOO              )             
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_PCS_PT2M3_8G      ( 0x143 | PDATA_RFDOO              ) 
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_INIT                0x000                              
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #define  PDATA_IDLE                0x000                              
/*MT6140D*/ /*MT6229~*/ /*RPF89009B*/      #endif 
/*MT6140D*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #ifdef SKY77616
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PR1        ( 0x000 | PDATA_RFDOO | PDATA_RX   )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PR2        ( 0x100 | PDATA_RFDOO | PDATA_RX   )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PR3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT1        ( 0x042 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT2        ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT2B       ( 0x161 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT3        ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT2M1_G8   ( 0x161 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT2M2_G8   ( 0x161 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT2M3_G8   ( 0x161 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT2M1_8G   ( 0x042 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT2M2_8G   ( 0x161 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM850_PT2M3_8G   ( 0x161 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PR1           ( 0x000 | PDATA_RFDOO | PDATA_RX   )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PR2           ( 0x100 | PDATA_RFDOO | PDATA_RX   )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT1           ( 0x042 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT2           ( 0x001 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT2B          ( 0x141 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT2M1_G8      ( 0x141 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT2M2_G8      ( 0x141 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT2M3_G8      ( 0x141 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT2M1_8G      ( 0x042 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT2M2_8G      ( 0x141 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_GSM_PT2M3_8G      ( 0x141 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PR1           ( 0x004 | PDATA_RFDOO | PDATA_RX   )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PR2           ( 0x104 | PDATA_RFDOO | PDATA_RX   )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT1           ( 0x040 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT2           ( 0x003 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT2B          ( 0x143 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT2M1_G8      ( 0x143 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT2M2_G8      ( 0x143 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT2M3_G8      ( 0x143 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT2M1_8G      ( 0x003 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT2M2_8G      ( 0x143 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_DCS_PT2M3_8G      ( 0x143 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PR1           ( 0x004 | PDATA_RFDOO | PDATA_RX   )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PR2           ( 0x104 | PDATA_RFDOO | PDATA_RX   )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PR3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT1           ( 0x040 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT2           ( 0x003 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT2B          ( 0x143 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT3           ( 0x000                            )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT2M1_G8      ( 0x143 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT2M2_G8      ( 0x143 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT2M3_G8      ( 0x143 | PDATA_RFDOO              )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT2M1_8G      ( 0x003 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT2M2_8G      ( 0x143 | PDATA_RFDOO | PDATA_GMSK )
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_PCS_PT2M3_8G      ( 0x143 | PDATA_RFDOO | PDATA_GMSK )                         
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_INIT                0x000                                      
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #define  PDATA_IDLE                0x000                                      
/*MT6140D*/ /*MT6229~*/ /*SKY77616*/       #endif                                                                   
/*MT6140D*/ /*-------------------------------------------------------------------------------------*/
/*MT6140D*/ #endif
/*MT6140D*/ 
/*MT6140D*/ /*----------------------------------------------*/
/*MT6140D*/ /*   APC Compensate Thresholds                  */
/*MT6140D*/ /*----------------------------------------------*/
/*MT6140D*/
/*MT6140D*/ #define    SECONDS2FRAME(n)        ((int)((n)*1000/4.165))
/*MT6140D*/ #define    VOLT2UVOLT(n)           ((int)((n)*1000000))
/*MT6140D*/ #define    TEMP2MTEMP(n)           ((int)((n)*1000))
/*MT6140D*/
/*MT6140D*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*MT6140D*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6140D*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*MT6140D*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*MT6140D*/
/*MT6140D*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*MT6140D*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6140D*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*MT6140D*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*MT6140D*/
/*----------------------------------------------*/
/*   Crystal parameter                                                   */
/*----------------------------------------------*/

#define Custom_RF_XO_CapID  35
/*MT6140D*//*----------------------------------------------*/
/*MT6140D*//*   0:GSM850 Signal go through GSM850, GSM900 Signal go through GSM900  (default)         */
/*MT6140D*//*   1:GSM850 Signal go through GSM900, GSM900 Signal go through GSM850  (default)         */
/*MT6140D*//*----------------------------------------------*/
/*MT6140D*/#define GSM850_GSM900_SWAP  0
/*MT6140D*//*----------------------------------------------*/
/*MT6140D*//*   0:DCS1800 Signal go through DCS1800, PCS1900 Signal go through PCS1900(default)         */
/*MT6140D*//*   1:DCS1800 Signal go through PCS1900, PCS1900 Signal go through DCS1800                  */
/*MT6140D*//*----------------------------------------------*/
/*MT6140D*/#define DCS1800_PCS1900_SWAP    0
/*MT6140D*/
/*MT6140D*/ /*----------------------------------------------*/
/*MT6140D*/ /*   TX power rollback parameter                */
/*MT6140D*/ /*----------------------------------------------*/
/*MT6140D*/ /*Unit: 1/8 dB*/
/*MT6140D*/ /*GSM850 GMSK*/
/*MT6140D*/ #define GSM850_TX_ROLLBACK_2T_GMSK 8
/*MT6140D*/ #define GSM850_TX_ROLLBACK_3T_GMSK 24
/*MT6140D*/ #define GSM850_TX_ROLLBACK_4T_GMSK 32
/*MT6140D*/ #define GSM850_TX_ROLLBACK_5T_GMSK 40
/*MT6140D*/ 
/*MT6140D*/ /*GSM GMSK*/
/*MT6140D*/ #define GSM_TX_ROLLBACK_2T_GMSK 8
/*MT6140D*/ #define GSM_TX_ROLLBACK_3T_GMSK 24
/*MT6140D*/ #define GSM_TX_ROLLBACK_4T_GMSK 32
/*MT6140D*/ #define GSM_TX_ROLLBACK_5T_GMSK 40
/*MT6140D*/ 
/*MT6140D*/ /*DCS GMSK*/
/*MT6140D*/ #define DCS_TX_ROLLBACK_2T_GMSK 8
/*MT6140D*/ #define DCS_TX_ROLLBACK_3T_GMSK 24
/*MT6140D*/ #define DCS_TX_ROLLBACK_4T_GMSK 32
/*MT6140D*/ #define DCS_TX_ROLLBACK_5T_GMSK 40
/*MT6140D*/ 
/*MT6140D*/ /*PCS GMSK*/
/*MT6140D*/ #define PCS_TX_ROLLBACK_2T_GMSK 8
/*MT6140D*/ #define PCS_TX_ROLLBACK_3T_GMSK 24
/*MT6140D*/ #define PCS_TX_ROLLBACK_4T_GMSK 32
/*MT6140D*/ #define PCS_TX_ROLLBACK_5T_GMSK 40
/*MT6140D*/ 
/*MT6140D*/ /*GSM850 EPSK*/
/*MT6140D*/ #define GSM850_TX_ROLLBACK_2T_EPSK 8
/*MT6140D*/ #define GSM850_TX_ROLLBACK_3T_EPSK 24
/*MT6140D*/ #define GSM850_TX_ROLLBACK_4T_EPSK 32
/*MT6140D*/ #define GSM850_TX_ROLLBACK_5T_EPSK 40
/*MT6140D*/ 
/*MT6140D*/ /*GSM EPSK*/
/*MT6140D*/ #define GSM_TX_ROLLBACK_2T_EPSK 8
/*MT6140D*/ #define GSM_TX_ROLLBACK_3T_EPSK 24
/*MT6140D*/ #define GSM_TX_ROLLBACK_4T_EPSK 32
/*MT6140D*/ #define GSM_TX_ROLLBACK_5T_EPSK 40
/*MT6140D*/ 
/*MT6140D*/ /*DCS EPSK*/
/*MT6140D*/ #define DCS_TX_ROLLBACK_2T_EPSK 8
/*MT6140D*/ #define DCS_TX_ROLLBACK_3T_EPSK 24
/*MT6140D*/ #define DCS_TX_ROLLBACK_4T_EPSK 32
/*MT6140D*/ #define DCS_TX_ROLLBACK_5T_EPSK 40
/*MT6140D*/ 
/*MT6140D*/ /*PCS EPSK*/
/*MT6140D*/ #define PCS_TX_ROLLBACK_2T_EPSK 8
/*MT6140D*/ #define PCS_TX_ROLLBACK_3T_EPSK 24
/*MT6140D*/ #define PCS_TX_ROLLBACK_4T_EPSK 32
/*MT6140D*/ #define PCS_TX_ROLLBACK_5T_EPSK 40
/*============================================================================== */
#endif
