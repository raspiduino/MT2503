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
 *    keypad_def.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for keypad table
 *
 * Author:
 * -------
 * -------
 *
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
#ifndef TOUCH_PANEL_CUSTOM_H
#define TOUCH_PANEL_CUSTOM_H
 
#include "lcd_sw_inc.h"
#define CTP_I2C_LDO         PMU_LDO_BUCK_MAX //MT6276E2 use VACMA, MT6276E1 use VCAMD
#define CTP_I2C_LDO_VOLTAGE PMU_VOLT_02_800000_V

#define TOUCH_PANEL_COORD_X_START 0
#define TOUCH_PANEL_COORD_X_END   (LCD_WIDTH -1)
#define TOUCH_PANEL_COORD_Y_START 0
#define TOUCH_PANEL_COORD_Y_END   (LCD_HEIGHT -1)

#if defined(__TOUCH_PANEL_CAPACITY__)
#if defined(__MMI_MAINLCD_240X400__) //WQVGA
#define TOUCH_PANEL_ADC_X_START   0 
#define TOUCH_PANEL_ADC_X_END     240
#define TOUCH_PANEL_ADC_Y_START   54
#define TOUCH_PANEL_ADC_Y_END     453
#elif defined(__MMI_MAINLCD_128X160__) //QVGA
#define TOUCH_PANEL_ADC_X_START   0
#define TOUCH_PANEL_ADC_X_END     128
#define TOUCH_PANEL_ADC_Y_START   54
#define TOUCH_PANEL_ADC_Y_END     214
#elif defined(__MMI_MAINLCD_240X320__) //QVGA
#define TOUCH_PANEL_ADC_X_START   0
#define TOUCH_PANEL_ADC_X_END     240
#define TOUCH_PANEL_ADC_Y_START   54
#define TOUCH_PANEL_ADC_Y_END     375
#elif defined(__MMI_MAINLCD_176X220__) //QCIF+
#define TOUCH_PANEL_ADC_X_START   0
#define TOUCH_PANEL_ADC_X_END     176
#define TOUCH_PANEL_ADC_Y_START   54
#define TOUCH_PANEL_ADC_Y_END     274
#elif defined(__MMI_MAINLCD_320X240__) //QVGA
#define TOUCH_PANEL_ADC_X_START   0
#define TOUCH_PANEL_ADC_X_END     320
#define TOUCH_PANEL_ADC_Y_START   54
#define TOUCH_PANEL_ADC_Y_END     294
#elif defined(__MMI_MAINLCD_480X800__) //WVGA
#define TOUCH_PANEL_ADC_X_START   0
#define TOUCH_PANEL_ADC_X_END     480
#define TOUCH_PANEL_ADC_Y_START   0
#define TOUCH_PANEL_ADC_Y_END     800
#elif defined(__MMI_MAINLCD_240X240__) 
#define TOUCH_PANEL_ADC_X_START   0
#define TOUCH_PANEL_ADC_X_END     240
#define TOUCH_PANEL_ADC_Y_START   0
#define TOUCH_PANEL_ADC_Y_END     240
#else
#define TOUCH_PANEL_ADC_X_START   0 
#define TOUCH_PANEL_ADC_X_END     LCD_WIDTH
#define TOUCH_PANEL_ADC_Y_START   (LCD_HEIGHT/9)
#define TOUCH_PANEL_ADC_Y_END     (LCD_HEIGHT+LCD_HEIGHT/9)
#endif //#if defined(__MMI_MAINLCD_240X400__)
#else
#if defined(__TOUCH_PANEL_MULTITOUCH__) //single end mode has smaller range
#define TOUCH_PANEL_ADC_X_START   230
#define TOUCH_PANEL_ADC_X_END     3867
#define TOUCH_PANEL_ADC_Y_START   287
#define TOUCH_PANEL_ADC_Y_END     3853
#else //#if defined(__TOUCH_PANEL_MULTITOUCH__)
#define TOUCH_PANEL_ADC_X_START   230 
#define TOUCH_PANEL_ADC_X_END     3867
#define TOUCH_PANEL_ADC_Y_START   287 
#define TOUCH_PANEL_ADC_Y_END     3853
#endif
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)


#define TOUCH_PANEL_X_MILLIMETER 42
#define TOUCH_PANEL_Y_MILLIMETER 70
#define TOUCH_PANEL_EINT_DOWN_LEVEL  LEVEL_HIGH //GOODIX default use rising edge trigger


/*touch panel control*/
#define TOUCH_PANEL_START_BIT    0x80

#define TOUCH_PANEL_TEMP0        0x00
#define TOUCH_PANEL_X_PLUS       0x10
#define TOUCH_PANEL_VBAT         0x20
#define TOUCH_PANEL_Z1_POS       0x30
#define TOUCH_PANEL_Z2_POS       0x40
#define TOUCH_PANEL_Y_PLUS       0x50
#define TOUCH_PANEL_TEMP1        0x70

#define TOUCH_PANEL_ADC3         0x20
#define TOUCH_PANEL_ADC4         0x60
#define TOUCH_PANEL_12BIT_SAMPLE 0x0
#define TOUCH_PANEL_8BIT_SAMPLE  0x8
#define TOUCH_PANEL_DIFF_MODE    0x0
#define TOUCH_PANEL_SINGLE_MODE  0x4

#define TOUCH_PANEL_PWD_ENBLE    0x0
#define TOUCH_PANEL_IRQ_DISABLE  0x1
#define TOUCH_PANEL_PWD_DISABLE  0x3
#define TOUCH_PANEL_PWD_RESET    0x2

/*retry and filter*/
#ifdef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_RETRY 1
   #define TOUCH_PANEL_FILTER_THRESOLD 10000
   #define   TOUCH_PRESSURE_THRESHOLD_LOW     1
#else /*TOUCH_PANEL_PRESSURE*/
   #define TOUCH_PANEL_RETRY 4
   #define TOUCH_PANEL_FILTER_THRESOLD 50
#endif /*TOUCH_PANEL_PRESSURE*/ 
   #define   TOUCH_PRESSURE_THRESHOLD_HIGH     4000 

#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER) 
#define TS_DEBOUNCE_TIME 36*32 
#define TOUCH_PANEL_CALI_CHECK_OFFSET 6 
#define MIN_PEN_MOVE_OFFSET  8 
#define HAND_WRITING_MAX_OFFSET (TOUCH_PANEL_COORD_X_END>TOUCH_PANEL_COORD_Y_END)?(TOUCH_PANEL_COORD_X_END>>2):(TOUCH_PANEL_COORD_Y_END>>2)
#define NONHAND_WRITING_MAX_OFFSET  200 
#define MAX_STROKE_MOVE_OFFSET 1 
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK) 
#define MULTIPLE_POINT_SELECTION 7 
#endif /*#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)*/ 
#if defined(__DRV_TP_DISCARD_SHIFTING__) 
#define PRESSURE_CHECK_BOUNDARY 2000 
#define PRESSURE_SHIFTING_BOUNDARY 800 
#endif /*#if defined(__DRV_TP_DISCARD_SHIFTING__)*/ 
#endif /*#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)*/ 

#define NEGATIVE_LOW_BOUND -730
#define NEGATIVE_UP_BOUND   -55
#define POSITIVE_UP_BOUND   730
#define POSITIVE_LOW_BOUND   55

#define X_PLATE 280
#define Y_PLATE 690
   
#define MIN_Y_LOW_BOUND   2 
#define MIN_Y_UP_BOUND   10 
#define MAX_Y_LOW_BOUND   50
#define MAX_Y_UP_BOUND   130
#define MIN_X_LOW_BOUND     83
#define MIN_X_UP_BOUND     170
#define MAX_X_LOW_BOUND     83
#define MAX_X_UP_BOUND     165

#define POINT_LOW_BOUND 300
#define AVERAGE_NUMBER 10
#define TP_RANGE 6 
#define TP_STEP 32
#define MIN_DELTA 30
/*************************************************************************
 * [Define the cailbration point only for HAND_WRITING feature ]
 *************************************************************************/

/* top-left point */

#define TOUCH_PANEL_CALIBRATION_X_1   (LCD_WIDTH/4)

#define TOUCH_PANEL_CALIBRATION_Y_1   (LCD_HEIGHT/4)

/* bottom-right point */

#define TOUCH_PANEL_CALIBRATION_X_2   (3*LCD_WIDTH/4)

#define TOUCH_PANEL_CALIBRATION_Y_2   (3*LCD_HEIGHT/4)

/* 3rd point should be different from the ceter point 

 * such that driver can check it's ADC value

 */

#define TOUCH_PANEL_CALIBRATION_X_3   (LCD_WIDTH/2 + 30)

#define TOUCH_PANEL_CALIBRATION_Y_3   (LCD_HEIGH/2 + 10)


/*************************************************************************
 * [handwriting pad information setting]
 * 1. Define the enum of the control areas
 * 
 * The flag for control areas or handwriting areas...
 *
 * #define TP_MAPPING_KEY        (0x00000100)
 * #define TP_CUSTOM_HANDLE      (0x00000200)
 * #define TP_CONTROL_AREA       (0x80000000)
 * #define TP_HANDWRITING_AREA   (0x40000000)
 * #define TP_HANDWRITING_SUPPORTS_FULL_AREA   (0x20000000)
 *
 * 2.
 *************************************************************************/
typedef enum
{
   TP_AREA_HANDWRITING,
   TP_CONTROL_AREA_LSK,
   TP_CONTROL_AREA_UP_ARROW,
   TP_CONTROL_AREA_RSK,
   TP_CONTROL_AREA_DOWN_ARROW,
   TP_CONTROL_AREA_LEFT_ARROW,
   TP_CONTROL_AREA_RIGHT_ARROW,

   TP_CONTROL_AREA_SEND,
   TP_CONTROL_AREA_CLEAN,
   TP_CONTROL_AREA_END,

   TP_CONTROL_AREA_1,
   TP_CONTROL_AREA_2,
   TP_CONTROL_AREA_3,

   TP_CONTROL_AREA_4,
   TP_CONTROL_AREA_5,
   TP_CONTROL_AREA_6,

   TP_CONTROL_AREA_7,
   TP_CONTROL_AREA_8,
   TP_CONTROL_AREA_9,

   TP_CONTROL_AREA_STAR,
   TP_CONTROL_AREA_0,
   TP_CONTROL_AREA_HASH,   
   
   TP_CONTROL_AREA_EXTRA_FUNC,
   
   /* don't add the enum after this line */
   TP_AREA_MAX_NUM
}tp_area_id_enum;

#if defined(__TOUCH_PANEL_CAPACITY__)
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__)  || defined(__MMI_MAINLCD_128X160__)
#define CTP_X_RES                 320
#define CTP_Y_RES                 533
#else //#if defined(__MMI_MAINLCD_240X400__) //WQVGA
#define CTP_X_RES                 TOUCH_PANEL_ADC_X_END
#define CTP_Y_RES                 TOUCH_PANEL_ADC_Y_END
#endif//#if defined(__MMI_MAINLCD_240X400__) //WQVGA
#define CTP_CONFIG_LENGTH         106

enum
{
    CTP_CONFIG_NORMAL,
    CTP_CONFIG_REDUCE_CMN,
    CTP_CONFIG_FM_DESENCE,
    CTP_CONFIG_PROXIMITY,
    CTP_CONFIG_MAX
};

#define TPD_WARP_X( x ) ( x )
#define TPD_WARP_Y( y )	( CTP_Y_RES - (y) - 1 )

extern kal_uint8 ctp_config_list[CTP_CONFIG_MAX][CTP_CONFIG_LENGTH];
#define GET_CTP_CONFIG( cfg ) ctp_config_list[cfg]
#endif

#endif
