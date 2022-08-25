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
 *	l1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   MT6129D RF constance defintion
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */
#if !defined(MT6129D_RF)
   #error "rf files mismatch with compile option!"
#endif

/*MT6129D*/
/*MT6129D*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*   Event Timing Define                                  */
/*MT6129D*/ /*--------------------------------------------------------*/
/*MT6129D*/
/*MT6129D*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129D*/ /*MT6225~*/#define  QB_RX_FENA_2_FSYNC          48   /* this value shall be 4N+0 */
/*MT6129D*/ /*MT6225~*/#define  QB_RX_FSYNC_2_FENA          0
/*MT6129D*/ /*MT6225~*/#define  QB_TX_FENA_2_FSYNC          152  /* this value shall be 4N+0 */
/*MT6129D*/ /*MT6225~*/#define  QB_TX_FSYNC_2_FENA          30
/*MT6129D*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6129D*//*MT6218~*/ #define  QB_RX_FENA_2_FSYNC          40   /* this value shall be 4N+0 */
/*MT6129D*//*MT6218~*/ #define  QB_RX_FSYNC_2_FENA          0
/*MT6129D*//*MT6218~*/ #define  QB_TX_FENA_2_FSYNC          152  /* this value shall be 4N+0 */
/*MT6129D*//*MT6218~*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6129D*/ #else
/*MT6129D*/ #define  QB_RX_FENA_2_FSYNC          35   /* this value shall be 4N+3 */
/*MT6129D*/ #define  QB_RX_FSYNC_2_FENA          0
/*MT6129D*/ #define  QB_TX_FENA_2_FSYNC          149  /* this value shall be 4N+1 */
/*MT6129D*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6129D*/ #endif
/*MT6129D*/                                           /*           |--(N:SR3 data number)                     */
/*MT6129D*/ #define  QB_SR1                      230  /* Let the 6*N + 4(QB) distance exist between SR1 & SR3 */
/*MT6129D*/ #define  QB_SR2                      100
/*MT6129D*/ #define  QB_SR2M                     40
/*MT6129D*/ #define  QB_SR3                      0
/*MT6129D*/ #define  QB_PR1                      250
/*MT6129D*/ #define  QB_PR2                      100
/*MT6129D*/ #define  QB_PR3                      6
/*MT6129D*/ #define  QB_ST1                      335
/*MT6129D*/ #define  QB_ST2                      140
/*MT6129D*/ #define  QB_ST3                      23
/*MT6129D*/ #define  QB_PT1                      136
/*MT6129D*/ #define  QB_PT2                      8
/*MT6129D*/ #define  QB_PT3                      23
/*MT6139E*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129D*/ #define  QB_APCON                    19
/*MT6129D*/ #define  QB_APCMID                   22
/*MT6129D*/ #define  QB_APCOFF                   7
/*MT6129D*/ #else
/*MT6129D*/ #define  QB_APCON                    23 /* advance 2QB */
/*MT6129D*/ #define  QB_APCMID                   26
/*MT6129D*/ #define  QB_APCOFF                   3 /* advance 2QB */
/*MT6129D*/ #endif
/*MT6129D*/ #define  QB_APCDACON                 99
/*MT6129D*/
/*MT6129D*/ #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6129D*//*MT6223~*/ #define  TX_PROPAGATION_DELAY         45
/*MT6129D*/ #elif IS_CHIP_MT6225_AND_LATTER_VERSION||IS_CHIP_MT6229||IS_CHIP_MT6268T
/*MT6129D*//*MT6225~*/ #define  TX_PROPAGATION_DELAY         47
/*MT6129D*/ #elif IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6129D*//*MT6218~*/ #define  TX_PROPAGATION_DELAY         39
/*MT6129D*/ #else
/*MT6129D*//*OTHERS*/  #define  TX_PROPAGATION_DELAY         36
/*MT6129D*/ #endif
/*MT6129D*/
/*MT6129D*/ #if  IS_CHIP_MT6208
/*MT6129D*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6208*/ /*   define  BPI data (shall be modified by real case)    */
/*MT6129D*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6208*/ /*    PRCB : bit   pin                                    */
/*MT6129D*/ /*MT6208*/ /*            0    HB_TX                                  */
/*MT6129D*/ /*MT6208*/ /*            1   *PCS_CTRL                               */
/*MT6129D*/ /*MT6208*/ /*            2    TX_EN                                  */
/*MT6129D*/ /*MT6208*/ /*            3   *GSM_BANDSW*                            */
/*MT6129D*/ /*MT6208*/ /*            4    LB_TX                                  */
/*MT6129D*/ /*MT6208*/ /*            5    DCS_BANDSW*                            */
/*MT6129D*/ /*MT6208*/ /*            6    PCS_RCTRL                              */
/*MT6129D*/ /*MT6208*/ /*            7    not used                               */
/*MT6129D*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6208*/
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM850_PR1  0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM850_PR2  0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM850_PR3  0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM850_PT1  0x08
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM850_PT2  0x1C
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM850_PT3  0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM_PR1     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM_PR2     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM_PR3     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM_PT1     0x08
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM_PT2     0x1C
/*MT6129D*/ /*MT6208*/ #define  PDATA_GSM_PT3     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_DCS_PR1     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_DCS_PR2     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_DCS_PR3     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_DCS_PT1     0x20
/*MT6129D*/ /*MT6208*/ #define  PDATA_DCS_PT2     0x25
/*MT6129D*/ /*MT6208*/ #define  PDATA_DCS_PT3     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_PCS_PR1     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_PCS_PR2     0x40
/*MT6129D*/ /*MT6208*/ #define  PDATA_PCS_PR3     0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_PCS_PT1     0x60
/*MT6129D*/ /*MT6208*/ #define  PDATA_PCS_PT2     0x25
/*MT6129D*/ /*MT6208*/ #define  PDATA_PCS_PT3     0x00
/*MT6129D*/ /*MT6208*/
/*MT6129D*/ /*MT6208*/ #define  PDATA_INIT        0x00
/*MT6129D*/ /*MT6208*/ #define  PDATA_IDLE        0x00
/*MT6129D*/ #endif
/*MT6129D*/
/*MT6129D*/ #if  IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/ /*   define  BPI data for FOUNTAIN2 (shall be modified by real case)    */
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/ /*    PRCB : bit   pin                                    */
/*MT6129D*/ /*MT6205*/ /*            0    HB_TX                                  */
/*MT6129D*/ /*MT6205*/ /*            1    LB_TX                                  */
/*MT6129D*/ /*MT6205*/ /*            2    PCS_RCTRL                              */
/*MT6129D*/ /*MT6205*/ /*            3    850_RX                                 */
/*MT6129D*/ /*MT6205*/ /*            4    TX_EN                                  */
/*MT6129D*/ /*MT6205*/ /*            5    DCS BANDSW                             */
/*MT6129D*/ /*MT6205*/ /*            6    not used                               */
/*MT6129D*/ /*MT6205*/ /*            7    not used                               */
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR1  0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR2  0x08
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR3  0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT1  0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT2  0x12
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT3  0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR1     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR2     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR3     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT1     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT2     0x12
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT3     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR1     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR2     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR3     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT1     0x20
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT2     0x31
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT3     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR1     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR2     0x04
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR3     0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT1     0x24
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT2     0x31
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT3     0x00
/*MT6129D*/ /*MT6205*/
/*MT6129D*/ /*MT6205*/ #define  PDATA_INIT        0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_IDLE        0x00
/*MT6129D*/ #endif
/*MT6129D*/
/*MT6129D*/ /*----------------------------------------------*/
/*MT6129D*/ /*   APC Compensate Thresholds                  */
/*MT6129D*/ /*----------------------------------------------*/
/*MT6129D*/
/*MT6129D*/ #define    SECONDS2FRAME(n)        ((int)((n)*1000/4.165))
/*MT6129D*/ #define    VOLT2UVOLT(n)           ((int)((n)*1000000))
/*MT6129D*/ #define    TEMP2MTEMP(n)           ((int)((n)*1000))
/*MT6129D*/
/*MT6129D*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*MT6129D*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6129D*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*MT6129D*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*MT6129D*/
/*MT6129D*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*MT6129D*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6129D*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*MT6129D*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*MT6129D*/

/*============================================================================== */

#endif













