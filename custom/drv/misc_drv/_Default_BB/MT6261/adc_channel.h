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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    adc_channel.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for GPT driver.
 *
 * Author:
 * -------
 * -------
 * -------
 *============================================================================
 *             HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ADC_CHANNEL_H
#define _ADC_CHANNEL_H

#if defined (__NF2319__)||defined (__NF2318__)
/*voltage to temperature*/
#define ADC_TEMP_T1  -40*1000000   /*0C*/
#define ADC_TEMP_T2  55*1000000  /*25C*/
#define ADC_TEMP_T3  60*1000000  /*50C*/

#define ADC_TEMP_NTCR1 201879.0   /*resistor at 0C*/
#define ADC_TEMP_NTCR2 3531.0   /*resistor at 25C*/
#define ADC_TEMP_NTCR3 3016.0    /*resistor at 50C*/
#else
/*voltage to temperature*/
#define ADC_TEMP_T1  0*1000000   /*0C*/
#define ADC_TEMP_T2  25*1000000  /*25C*/
#define ADC_TEMP_T3  50*1000000  /*50C*/

#define ADC_TEMP_NTCR1 26490.0   /*resistor at 0C*/
#define ADC_TEMP_NTCR2 10000.0   /*resistor at 25C*/
#define ADC_TEMP_NTCR3 4171.0    /*resistor at 50C*/
#endif /* __NF2319__ */

#define ADC_TEMP_PUR 24000.0      /*orginal registor*/
#define ADC_TEMP_AVDD 2800000.0
#define ADC_TEMP_SCALE 10.0

#define ADC_TEMP_V1 (ADC_TEMP_AVDD*(ADC_TEMP_NTCR1/(ADC_TEMP_NTCR1+ADC_TEMP_PUR))) /*voltage at 0C*/
#define ADC_TEMP_V2 (ADC_TEMP_AVDD*(ADC_TEMP_NTCR2/(ADC_TEMP_NTCR2+ADC_TEMP_PUR))) /*voltage at 25C*/
#define ADC_TEMP_V3 (ADC_TEMP_AVDD*(ADC_TEMP_NTCR3/(ADC_TEMP_NTCR3+ADC_TEMP_PUR))) /*voltage at 50C*/

#define ADC_TEMP_M12 (((ADC_TEMP_T1-ADC_TEMP_T2)*ADC_TEMP_SCALE)/(ADC_TEMP_V1-ADC_TEMP_V2))  /*T1T2's slope */
#define ADC_TEMP_M23 (((ADC_TEMP_T2-ADC_TEMP_T3)*ADC_TEMP_SCALE)/(ADC_TEMP_V2-ADC_TEMP_V3))  /*T2T3's slppe*/

#define ADC_TEMPV2_FACTOR    ADC_TEMP_V2
#define ADC_TEMPA12_FACTOR   (ADC_TEMP_T1-ADC_TEMP_M12/ADC_TEMP_SCALE*ADC_TEMP_V1)
#define ADC_TEMPA23_FACTOR   (ADC_TEMP_T2-ADC_TEMP_M23/ADC_TEMP_SCALE*ADC_TEMP_V2)
#define ADC_TEMPM12_FACTOR   ADC_TEMP_M12
#define ADC_TEMPM23_FACTOR   ADC_TEMP_M23
#define ADC_TEMPSCALE_FACTOR ADC_TEMP_SCALE

#if defined (__NT17__)||defined(__NF2319__)||defined (__NF2318__)
#define ADC_ISENSE_FACTOR 5
#else
#define ADC_ISENSE_FACTOR (1/0.3) /*目前项目大都是用0.3 ，小容量电池项目除外      --    chengjun  2017-10-20*/
//#define ADC_ISENSE_FACTOR 5 //BMT ISENSE RESISTENCE FACTOR 5 = 1/0.2 --> resister use 0.2 Ohm
#endif
//only use channels < ADC_MAX_CHANNEL define in mcu\hal\drv_def\drv_features_adc.h
#define ADC_CALIBRATION_SLOPE_CH0  5434
#define ADC_CALIBRATION_SLOPE_CH1  5434
#define ADC_CALIBRATION_SLOPE_CH2  5434
#define ADC_CALIBRATION_SLOPE_CH3  5434
#define ADC_CALIBRATION_SLOPE_CH4  5434
#define ADC_CALIBRATION_SLOPE_CH5  5434
#define ADC_CALIBRATION_SLOPE_CH6  5434
#define ADC_CALIBRATION_SLOPE_CH7  5434
#define ADC_CALIBRATION_SLOPE_CH8  5434
#define ADC_CALIBRATION_SLOPE_CH9  5434
#define ADC_CALIBRATION_SLOPE_CH10 5434
#define ADC_CALIBRATION_SLOPE_CH11 5434
#define ADC_CALIBRATION_SLOPE_CH12 5434
#define ADC_CALIBRATION_SLOPE_CH13 5434
#define ADC_CALIBRATION_SLOPE_CH14 5434
#define ADC_CALIBRATION_SLOPE_CH15 5434
#define ADC_CALIBRATION_SLOPE_CH16 5434
#define ADC_CALIBRATION_SLOPE_CH17 5434
#define ADC_CALIBRATION_SLOPE_CH18 5434
#define ADC_CALIBRATION_SLOPE_CH19 5434

#define ADC_CALIBRATION_OFFSET_CH0  14466
#define ADC_CALIBRATION_OFFSET_CH1  14466
#define ADC_CALIBRATION_OFFSET_CH2  14466
#define ADC_CALIBRATION_OFFSET_CH3  14466
#define ADC_CALIBRATION_OFFSET_CH4  14466
#define ADC_CALIBRATION_OFFSET_CH5  14466
#define ADC_CALIBRATION_OFFSET_CH6  14466
#define ADC_CALIBRATION_OFFSET_CH7  14466
#define ADC_CALIBRATION_OFFSET_CH8  14466
#define ADC_CALIBRATION_OFFSET_CH9  14466
#define ADC_CALIBRATION_OFFSET_CH10 14466
#define ADC_CALIBRATION_OFFSET_CH11 14466
#define ADC_CALIBRATION_OFFSET_CH12 14466
#define ADC_CALIBRATION_OFFSET_CH13 14466
#define ADC_CALIBRATION_OFFSET_CH14 14466
#define ADC_CALIBRATION_OFFSET_CH15 14466
#define ADC_CALIBRATION_OFFSET_CH16 14466
#define ADC_CALIBRATION_OFFSET_CH17 14466
#define ADC_CALIBRATION_OFFSET_CH18 14466
#define ADC_CALIBRATION_OFFSET_CH19 14466

#define ADC_VOLT_FACTOR_CH0   50
#define ADC_VOLT_FACTOR_CH1   50
#define ADC_VOLT_FACTOR_CH2   50
#define ADC_VOLT_FACTOR_CH3   50
#define ADC_VOLT_FACTOR_CH4   50
#define ADC_VOLT_FACTOR_CH5   50
#define ADC_VOLT_FACTOR_CH6  100
#define ADC_VOLT_FACTOR_CH7  100
#define ADC_VOLT_FACTOR_CH8  100
#define ADC_VOLT_FACTOR_CH9  100
#define ADC_VOLT_FACTOR_CH10 100
#define ADC_VOLT_FACTOR_CH11 100
#define ADC_VOLT_FACTOR_CH12 100
#define ADC_VOLT_FACTOR_CH13 100
#define ADC_VOLT_FACTOR_CH14 100
#define ADC_VOLT_FACTOR_CH15 100
#define ADC_VOLT_FACTOR_CH16 100
#define ADC_VOLT_FACTOR_CH17 100
#define ADC_VOLT_FACTOR_CH18 100
#define ADC_VOLT_FACTOR_CH19 100

#endif   /*_ADC_H*/

