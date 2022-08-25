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
 * FactoryModeConfig.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file define macro and so on.
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
 ********************************************************************************/
 
#ifndef _FACTORY_MODE_CONFIG_H
#define _FACTORY_MODE_CONFIG_H


#include "MMI_features.h"


/*-------------------------------------FM TRACE CONFIG  BEGIN-----------------------------------*/

#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif 

#ifdef __MMI_FM_DEBUG__
//#define some sub option here

#endif /* __MMI_FM_DEBUG__ */ 

/* 
 * Please note: 
 *
 * 1) Commonly not allow use ASSERT, TRACE in FM to save code size as FM is unseless to end users.,
 *
 * 2) To provide these just to speed your IT work and issue solving only,
 * all ASSERT and TRACE should be turned off in custom release load, 
 * and you can ask customer to turn on it here for e-service issue quickly.
 *
 * 3) FORBID to use MMI_ASSERT, MMI_TRACE, MMI_PRINT ... in FM 
 * Please use the ones defined as below as then can be turned off freely to save code size.
 * 
 * MMI_FM_ASSERT:   
 *      Used to check those important cases which can help for issue solving greatly, be very carefully to use it
 * MMI_FM_IT_ASSERT:
 *      User to check common case which is valuable mainly in IT stage and bring little value on MP version
 *
 * MMI_FM_TRACE:
 *      For those trace can bring important value and can speed issue solving in long term.
 * MMI_FM_IT_TRACE:
 *      For IT stage only, unuseless almostly after feature MP
 *
 * MMI_FM_PARAM_CHECK: 
 *      Not use this for normally parame check which can be true according to your design. 
 *      just use it to remove those "useless" ones which not harm the quilty even remove it. 
 *      ex. MMI_FM_PARAM_CHECK(X); it can work only becaus the RD set it to wrong value himself.
 *      
 *      To check if parameter is valid called by programming skill which has valuable only in IT stage
 *      As lots of parameter check code is to avoid facitious techical programming error, 
 *      these error can be solved foever after IT or SQC while the check code is exist and waste code size forever,
 *      use it can help to remove these waste easily.
 *
 *
*/

/* Please apply these macro to those code which can be removed on customer release */

#ifdef __MMI_FM_DEBUG__

#define MMI_FM_ASSERT(X)                            MMI_ASSERT(X)
#define MMI_FM_IT_ASSERT(X)                         MMI_ASSERT(X)

#define MMI_FM_TRACE(X)                             MMI_TRACE X
#define MMI_FM_IT_TRACE(X)                          MMI_TRACE X

#define MMI_FM_PARAM_CHECK(X, Y)                    MMI_FM_ASSERT(!(X))

#else /* __MMI_FM_DEBUG__ */

/*Turn off them to save code size */
#define MMI_FM_ASSERT(X)                            do{}while(0)
#define MMI_FM_IT_ASSERT(X)                         do{}while(0)

#define MMI_FM_TRACE(X)                             do{}while(0)
#define MMI_FM_IT_TRACE(X)                          do{}while(0)

#define MMI_FM_PARAM_CHECK(X, Y)                    do{}while(0)
#endif /* __MMI_FM_DEBUG__ */


/*----------------------------------------------------------------------------*/
/* Trace                                                                      */
/*----------------------------------------------------------------------------*/
/*
 *  Trace group, easy to change it, please use this define.
 *  The trace style should be:
 *
 *      TRC_MSG(TRC_MMI_FM_[L1 menu]_xxx, "[FM][L1 menu] xxx xxx xxx")
 * ex.
 *      TRC_MSG(TRC_MMI_FM_VERSION_XXX, "[FM][Version]xxx")
 *
 *
 */

#define MMI_FM_TRC_INFO                               MMI_COMMON_TRC_G8_FM
#define MMI_FM_TRC_WARNING                            MMI_COMMON_TRC_G8_FM
#define MMI_FM_TRC_ERROR                              MMI_COMMON_TRC_G8_FM

/*-------------------------------------FM TRACE CONFIG  END-------------------------------------*/








/*--------------------- Define ---------------------*/
/*---------- common -----------*/
#define MAX_TEST_ITEM               sizeof(g_fm_test_item_tab)/sizeof(mmi_fm_test_item_struct)
#define MAX_ENTRY_ITEM              sizeof(g_fm_entry_test_item_tab)/sizeof(mmi_fm_entry_test_item_struct)
#define INVALID_MENU_ITEM     99


/*------------ FactoryModeMedia.c : Camera preview --------------*/

#define FM_CAMERA_OSD_BUFFER_SIZE   (((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))     /* single buffer */

#if defined (__MMI_FM_CAMERA_PREVIEW__)

#if defined(__DIRECT_SENSOR_SUPPORT__)
#include "image_sensor.h"

#if defined(CAMERA_FACTORY_PREVIEW_WIDTH)
#undef CAMERA_FACTORY_PREVIEW_WIDTH
#endif

#if defined(CAMERA_FACTORY_PREVIEW_HEIGHT)
#undef CAMERA_FACTORY_PREVIEW_HEIGHT
#endif

#define CAMERA_FACTORY_PREVIEW_WIDTH    (IMAGE_SENSOR_PREVIEW_WIDTH)
#define CAMERA_FACTORY_PREVIEW_HEIGHT   (IMAGE_SENSOR_PREVIEW_HEIGHT)

#define CAMERA_FACTORY_IMAGESIZE_WIDTH      (IMAGE_SENSOR_PREVIEW_WIDTH)
#define CAMERA_FACTORY_IMAGESIZE_HEIGHT     (IMAGE_SENSOR_PREVIEW_HEIGHT)

#endif /* __DIRECT_SENSOR_SUPPORT__ */

#endif /* __MMI_FM_CAMERA_PREVIEW__ */ 

/* ------------ FactoryModeMisc.c: version ----------------*/
#define MAX_TEST_STRING_BUF                 80
#define MAX_VERSION_HINT_ITEM_NUM           8
#define MAX_RES_BIN_HINT_ITEM_NUM           2

/* --------------FactorymodeNxMPoint.c : N Cross M Points Test ----------*/
#ifdef __MMI_TOUCH_SCREEN__
#define TOUCH_N_ROWS 4  /* Number of Rows of Points */
#define TOUCH_N_COLS 5  /* Number of Columns of Points */
#define IMAGE_HIDE      0       /* Hide image of Point */
#define IMAGE_SHOW      1       /* Show image of Point */
// TODO: dynamic compute margin
#define TOUCH_ROW_MARGIN   30   /* Horizontal Margin between points */
#define TOUCH_COL_MARGIN   15   /* Vertical Margin between points */
#endif


/*------------- keypad ------------------------*/
#ifdef __MMI_FM_KEYPAD_TEST__
#define FM_KEYPAD_SPACE_STR             L" "
#define FM_KEYPAD_NEW_LINE_STR          L"\n"
#define FM_KEYPAD_TEST_PASS_STR         L"Pass"
#define FM_KEYPAD_TALBLE_SIZE           (mmi_fm_keypad_get_keypad_table_size())
#define FM_KEYPAD_ORDER_TABLE_SIZE      (mmi_fm_keypad_get_order_table_size())
#define FM_KEYPAD_BIT_SHIFT             5
#define FM_KEYPAD_BIT_MASK              0x1F
#define FM_KEYPAD_SET_BIT(f, i)         (f[(i)>>FM_KEYPAD_BIT_SHIFT] |= (1<<((i) & FM_KEYPAD_BIT_MASK)))
#define FM_KEYPAD_CLEAR_BIT(f, i)       (f[(i)>>FM_KEYPAD_BIT_SHIFT] &= ~(1<<((i) & FM_KEYPAD_BIT_MASK)))
#define FM_KEYPAD_TEST_BIT(f, i)        (f[(i)>>FM_KEYPAD_BIT_SHIFT] & ((1<<((i) & FM_KEYPAD_BIT_MASK))))
#define FM_KEYPAD_TEST_STRING           ((U16*)g_fm_keypad_context->key_test_string)
#define FM_KEYPAD_KEY_PRESSED_FLAG      (g_fm_keypad_context->key_pressed_flag)
#define FM_KEYPAD_CONTEXT_SIZE          (FM_KEYPAD_ORDER_TABLE_SIZE * 12 + 4 * FM_KEYPAD_KEY_PRESSED_FLAG_LEN)
#endif /*__MMI_FM_KEYPAD_TEST__*/

/* --------------- Radio --------------- */
#ifdef __MMI_FM_RADIO__
#ifdef __COSMOS_MMI_PACKAGE__
    #define MMI_FM_RADIO_INDICATE "Fre+:  END\nFre-:  SEND\nVol+:  VOL UP\nVol-:  VOL DOWN"
    #define MMI_FM_RADIO_INDICATE_LEN   150
    #define MMI_FM_RADIO_STRING_LEN 110 + MMI_FM_RADIO_INDICATE_LEN
#else
    #define MMI_FM_RADIO_STRING_LEN 110
#endif /* __COSMOS_MMI_PACKAGE__ */
#endif 



/* -------------FactoryModeDef.h------------------ */
/* Defination */
/* Lisen 0921 */
#define MAX_VER_NUM    9
// #define MAX_LED_MENU_NUM     6
#define MAX_CONTRAST_NUM   15
#define MIN_CONTRAST_NUM   0
#define CONTRAST_STEP      1

/* Marco */
#define FM_IS_SET(b, a)       ((b & (0x1 << a)) >> a)
#define FM_STATE_SET(b, a)    (b |= (0x1 << a))
#define FM_STATE_UNSET(b, a)  (b &= ~(0x1 << a))
#define FM_STATE_TOGGLE(b, a) (b ^= (0x1 << a))

/*===== Auto Testing Settings ===== */
#define MAX_TEST_ITEM_NAME_LEN   20
#define MAX_TEST_STRING_BUF         80

#define VBAT_LOWER_BOUNDARY      3.3
#define VBAT_UPPER_BOUNDARY         4.2
#define TEMP_LOWER_BOUNDARY         15
#define TEMP_UPPER_BOUNDARY         35
#define CURR__LOWER_BOUNDARY        0.3

#define LED_DURATION             2000
#define CLAM_DURATION            5000
#define LCM_CONSTRAST_DURATION   100
#define VERSION_DURATION         1500
#define BACKLIGHT_DURATION       500
#define RECEIVER_DURATION        3000
#define MIC_DURATION          3000
#define HEADSET_DURATION         3000
#define SPEAKER_DURATION         3000
#define VIB_DURATION          500
#define ADC_DURATION          1000
#define MELODY_DURATION       3000
/* Lisen 01262005 */
#define CAMERA_DURATION       5000
#define MEMORYCARD_DURATION          6000

typedef enum
{
#ifdef __SUPPORT_LED_FEATURE__
    FM_TEST_LED = 0,
    FM_TEST_CLAM_DETECT,
#else
    FM_TEST_CLAM_DETECT = 0,
#endif
#ifdef __MMI_FM_LCD_CONTRAST__
    FM_TEST_SUBLCM,
#endif
    FM_TEST_SW_VERSION,
    FM_TEST_BACKLIGHT,
#ifndef __MMI_MAINLCD_96X64__
    FM_TEST_LCD,
#endif
    FM_TEST_KEYPAD,
    FM_TEST_RECEIVER,
    FM_TEST_MIC,
    FM_TEST_SPEAKER,
    FM_TEST_HEADSET,
    FM_TEST_VIB,
    FM_TEST_BATTERY,
    FM_TEST_MELODY,
    FM_TEST_NAND,
#ifdef __MMI_FM_UART_TEST__
    FM_TEST_UART,
#endif
    /* Lisen 01262005 */
    FM_TEST_DOUBLE_SPEAKER,
#ifndef __MMI_MAINLCD_96X64__
    FM_TEST_CAMERA,
#endif
    FM_TEST_MEMORYCARD,
#ifdef __MMI_TOUCH_SCREEN__
    FM_TEST_PEN_PARALLEL_LINES,
    FM_TEST_PEN_N_CROSS_M_POINTS,
#endif /* __MMI_TOUCH_SCREEN__ */ 
    MAX_AUTO_TEST_ITEMS
} EM_AUTO_TESTS_ENUM;

typedef enum
{
    FM_TEST_UNTESTED = 0,
    FM_TEST_FAILED,
    FM_TEST_PASSED
} FM_AUTO_TEST_RESULT_ENUM;

#define FM_ADC_BATTERY  0


typedef enum
{
#ifdef __SUPPORT_LED_FEATURE__
    FM_AUTOTEST_LED = 0,
    FM_AUTOTEST_CLAM,
#else
    FM_AUTOTEST_CLAM = 0,
#endif    
#ifdef __FM_LCD_CONTRAST__
    FM_AUTOTEST_SUBLCM,
#endif
    FM_AUTOTEST_VERSION,
    FM_AUTOTEST_BACKLIGHT,
#ifndef __MMI_MAINLCD_96X64__
    FM_AUTOTEST_LCD,
#endif
    FM_AUTOTEST_KEYPAD,
    FM_AUTOTEST_RECEIVER,
    FM_AUTOTEST_MIC,
    FM_AUTOTEST_SPEAKER,
    FM_AUTOTEST_HEADSET,
    FM_AUTOTEST_BATTERY,
    FM_AUTOTEST_MELODY,
    FM_AUTOTEST_VIB,
    FM_AUTOTEST_NAND,
#ifdef __MMI_FM_UART_TEST__
    FM_AUTOTEST_UART,
#endif
    /* Lisen 01262005 */
    FM_AUTOTEST_DOUBLE_SPEAKER,
#ifndef __MMI_MAINLCD_96X64__
    FM_AUTOTEST_CAMERA,
#endif
    FM_AUTOTEST_MEMORYCARD,
#ifdef __MMI_TOUCH_SCREEN__
    FM_AUTOTEST_PARALLEL_LINE,
    FM_AUTOTEST_N_CROSS_M_POINTS,
#endif /* __MMI_TOUCH_SCREEN__ */ 
    FM_AUTOTEST_MAX_ITEMS
} FM_AUTO_TEST_ENUM;

typedef void (*AUTO_TEST_FUNC) (void);

typedef struct
{
    CHAR *name;//[MAX_TEST_ITEM_NAME_LEN *ENCODING_LENGTH];
    AUTO_TEST_FUNC func;
} testlet;

typedef struct
{
    U8 count;
    U8 priority[MAX_AUTO_TEST_ITEMS];   /* for example, priority[0] = 8 means that the first one is test item 8 */
} AutoTestItemArray;

typedef struct
{
    U8 count;
    FM_AUTO_TEST_RESULT_ENUM result[MAX_AUTO_TEST_ITEMS];   /* for example, result[0] = FM_TEST_PASSED means that the first test item passed the test */
} AutoTestResultArray;

/*===== MTBF ===== */
#define FM_MTBF_PERIOD        1000      /* in milli seconds */

/* Cycle in milli seconds */
#define FM_MTBF_LCD_CYCLE  2000
#define FM_MTBF_LED_CYCLE  1000
#define FM_MTBF_VIB_CYCLE  1000

#define FM_MTBF_AUDIO_GAP               20
#define FM_MTBF_SPK_UNIT   3000
#define FM_MTBF_REV_UNIT   3000
#define FM_MTBF_SPK_UNIT_CYCLE   (FM_MTBF_SPK_UNIT - FM_MTBF_AUDIO_GAP)
#define FM_MTBF_REV_UNIT_CYCLE   (FM_MTBF_REV_UNIT - FM_MTBF_AUDIO_GAP)
#define FM_MTBF_SPK_CYCLE  (FM_MTBF_SPK_UNIT*FM_MTBF_SPK_MAX)
#define FM_MTBF_REV_CYCLE  (FM_MTBF_REV_UNIT*FM_MTBF_REV_MAX)

typedef enum
{
    FM_MTBF_LCD_START = 0,
    FM_MTBF_LCD_R = 0,
    FM_MTBF_LCD_G,
    FM_MTBF_LCD_B,
    FM_MTBF_LCD_W,
    FM_MTBF_LCD_END = FM_MTBF_LCD_W
} FM_MTBF_LCD_ENUM;

typedef enum
{
    FM_MTBF_LED_START = 0,
    FM_MTBF_LED_KEYPAD = 0,
    FM_MTBF_LED_R,
    FM_MTBF_LED_G,
    FM_MTBF_LED_B,
    FM_MTBF_LED_END = FM_MTBF_LED_B
} FM_MTBF_LED_ENUM;

typedef enum
{
    FM_MTBF_VIB_START = 0,
    FM_MTBF_VIB_ON = 0,
    FM_MTBF_VIB_OFF,
    FM_MTBF_VIB_END = FM_MTBF_VIB_OFF
} FM_MTBF_VIB_ENUM;

typedef enum
{
    FM_MTBF_SPK_START = 0,
    FM_MTBF_SPK_400 = 0,
    FM_MTBF_SPK_600,
    FM_MTBF_SPK_800,
    FM_MTBF_SPK_850_1,
    FM_MTBF_SPK_850_2,
    FM_MTBF_SPK_900,
    FM_MTBF_SPK_1000,
    FM_MTBF_SPK_2000,
    FM_MTBF_SPK_4000,
    FM_MTBF_SPK_8000,
    FM_MTBF_SPK_END = FM_MTBF_SPK_8000,
    FM_MTBF_SPK_MAX
} FM_MTBF_SPK_ENUM;

typedef enum
{
    FM_MTBF_REV_START = 0,
    FM_MTBF_REV_400 = 0,
    FM_MTBF_REV_500,
    FM_MTBF_REV_600_1,
    FM_MTBF_REV_600_2,
    FM_MTBF_REV_700,
    FM_MTBF_REV_800,
    FM_MTBF_REV_1000,
    FM_MTBF_REV_1500,
    FM_MTBF_REV_2000,
    FM_MTBF_REV_3000,
    FM_MTBF_REV_END = FM_MTBF_REV_3000,
    FM_MTBF_REV_MAX
} FM_MTBF_REV_ENUM;

typedef enum
{
    FM_MTBF_AUD_START = 0,
    FM_MTBF_AUD_SPK = 0,
    FM_MTBF_AUD_REV,
    FM_MTBF_AUD_END = FM_MTBF_AUD_REV
} FM_MTBF_AUD_ALTERNATION_ENUM;






#endif /*_FACTORY_MODE_CONFIG_H*/
