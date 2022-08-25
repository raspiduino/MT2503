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
 *  FrogCandy.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  FrogCandy Game
 *
 * Author:
 * -------
 * -------
 * -------
 *                      
 ****************************************************************************/

#include "mmi_features.h"
#include "GameDefs.h"

#ifdef __MMI_GAME_FROGCANDY__
#include "GameInc.h"
#include "mmi_rp_app_games_def.h"
#include "FrogCandyProts.h"

#include <stdlib.h>

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__      //added for multi-language
#include "GameProts.h"
#endif
/************************************************************************/
/* Game Defines                                                         */
/************************************************************************/
#ifdef __MMI_MAINLCD_128X128__
#define MMI_GX_FROGCANDY_LCD_HEIGHT           (128)
#define MMI_GX_FROGCANDY_LCD_WIDTH            (128)
#define MMI_GX_FROGCANDY_OBJECT_WIDTH      (22)
#define MMI_GX_FROGCANDY_OBJECT_HEIGHT     (22)
#define MMI_GX_FROGCANDY_MAX_COLUMN  (4)
#define MMI_GX_FROGCANDY_GRADE_X           (92)
#define MMI_GX_FROGCANDY_GRADE_Y           (45)
#define MMI_GX_FROGCANDY_BASKET_WIDTH    (22)
#define MMI_GX_FROGCANDY_BASKET_HEIGHT   (22)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_X        (98)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_Y        (74)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_WIDTH    (20)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_HEIGHT   (52)
#define MMI_GX_FROGCANDY_ENERGY_BAR_X          (100)
#define MMI_GX_FROGCANDY_ENERGY_BAR_Y          (120)
#define MMI_GX_FROGCANDY_ENERGY_BAR_WIDTH      (18)
#define MMI_GX_FROGCANDY_ENERGY_BAR_HEIGHT     (5)
#define MMI_GX_FROGCANDY_MAX_SCORE_HEIGHT      (24)
#define MMI_GX_FROGCANDY_MAX_DROP_DISTANCE        (16)
#define MMI_GX_FROGCANDY_INFO_IMG_X (93)
#define MMI_GX_FROGCANDY_INFO_IMG_Y (2)
#define MMI_GX_FROGCANDY_INFO_HEIGHT (40)
#define MMI_GX_FROGCANDY_INFO_STR_X (91)
#define MMI_GX_FROGCANDY_INFO_STR_Y (17)
#define MMI_GX_FROGCANDY_LEVEL_ICON_WIDTH (12)
#define MMI_GX_FROGCANDY_LEVEL_ICON_HEIGHT (12)

#define MMI_GX_FROGCANDY_INITIAL_FROGCANDY_COL_IDX (2)
#define MMI_GX_FROGCANDY_FROGCANDY_COL_VALUE    {0, 22, 44, 66}

#define MMI_GX_FROGCANDY_MAX_DROPPING_OBJECTS  (8)

#elif defined(__MMI_MAINLCD_128X160__)
#define MMI_GX_FROGCANDY_LCD_HEIGHT           (160)
#define MMI_GX_FROGCANDY_LCD_WIDTH            (128)
#define MMI_GX_FROGCANDY_OBJECT_WIDTH      (22)
#define MMI_GX_FROGCANDY_OBJECT_HEIGHT     (22)
#define MMI_GX_FROGCANDY_MAX_COLUMN  (4)
#define MMI_GX_FROGCANDY_GRADE_X           (92)
#define MMI_GX_FROGCANDY_GRADE_Y           (59)
#define MMI_GX_FROGCANDY_BASKET_WIDTH    (22)
#define MMI_GX_FROGCANDY_BASKET_HEIGHT   (22)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_X        (98)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_Y        (94)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_WIDTH    (22)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_HEIGHT   (62)
#define MMI_GX_FROGCANDY_ENERGY_BAR_X          (99)
#define MMI_GX_FROGCANDY_ENERGY_BAR_Y          (149)
#define MMI_GX_FROGCANDY_ENERGY_BAR_WIDTH      (20)
#define MMI_GX_FROGCANDY_ENERGY_BAR_HEIGHT     (6)
#define MMI_GX_FROGCANDY_MAX_SCORE_HEIGHT      (24)
#define MMI_GX_FROGCANDY_MAX_DROP_DISTANCE        (16)
#define MMI_GX_FROGCANDY_INFO_IMG_X (94)
#define MMI_GX_FROGCANDY_INFO_IMG_Y (4)
#define MMI_GX_FROGCANDY_INFO_HEIGHT (40)
#define MMI_GX_FROGCANDY_INFO_STR_X (91)
#define MMI_GX_FROGCANDY_INFO_STR_Y (23)
#define MMI_GX_FROGCANDY_LEVEL_ICON_WIDTH (12)
#define MMI_GX_FROGCANDY_LEVEL_ICON_HEIGHT (12)

#define MMI_GX_FROGCANDY_INITIAL_FROGCANDY_COL_IDX (2)
#define MMI_GX_FROGCANDY_FROGCANDY_COL_VALUE    {0, 22, 44, 66}

#define MMI_GX_FROGCANDY_MAX_DROPPING_OBJECTS  (8)

#elif defined(__MMI_MAINLCD_176X220__)
#define MMI_GX_FROGCANDY_LCD_HEIGHT           (220)
#define MMI_GX_FROGCANDY_LCD_WIDTH            (176)
#define MMI_GX_FROGCANDY_OBJECT_WIDTH      (25)
#define MMI_GX_FROGCANDY_OBJECT_HEIGHT     (25)
#define MMI_GX_FROGCANDY_MAX_COLUMN  (5)
#define MMI_GX_FROGCANDY_GRADE_X           (127)
#define MMI_GX_FROGCANDY_GRADE_Y           (81)
#define MMI_GX_FROGCANDY_BASKET_WIDTH    (25)
#define MMI_GX_FROGCANDY_BASKET_HEIGHT   (25)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_X        (138)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_Y        (132)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_WIDTH    (29)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_HEIGHT   (82)
#define MMI_GX_FROGCANDY_ENERGY_BAR_X          (139)
#define MMI_GX_FROGCANDY_ENERGY_BAR_Y          (205)
#define MMI_GX_FROGCANDY_ENERGY_BAR_WIDTH      (27)
#define MMI_GX_FROGCANDY_ENERGY_BAR_HEIGHT     (8)
#define MMI_GX_FROGCANDY_MAX_SCORE_HEIGHT      (24)
#define MMI_GX_FROGCANDY_MAX_DROP_DISTANCE        (16)
#define MMI_GX_FROGCANDY_INFO_IMG_X (131)
#define MMI_GX_FROGCANDY_INFO_IMG_Y (7)
#define MMI_GX_FROGCANDY_INFO_HEIGHT (40)
#define MMI_GX_FROGCANDY_INFO_STR_X (128)
#define MMI_GX_FROGCANDY_INFO_STR_Y (26)
#define MMI_GX_FROGCANDY_LEVEL_ICON_WIDTH (16)
#define MMI_GX_FROGCANDY_LEVEL_ICON_HEIGHT (17)

#define MMI_GX_FROGCANDY_INITIAL_FROGCANDY_COL_IDX (2)
#define MMI_GX_FROGCANDY_FROGCANDY_COL_VALUE    {0, 25, 50, 75, 100}

#define MMI_GX_FROGCANDY_MAX_DROPPING_OBJECTS  (10)

#elif defined(__MMI_MAINLCD_240X320__)
#define MMI_GX_FROGCANDY_LCD_HEIGHT           (320)
#define MMI_GX_FROGCANDY_LCD_WIDTH            (240)
#define MMI_GX_FROGCANDY_OBJECT_WIDTH      (35)
#define MMI_GX_FROGCANDY_OBJECT_HEIGHT     (35)
#define MMI_GX_FROGCANDY_MAX_COLUMN  (5)
#define MMI_GX_FROGCANDY_GRADE_X              (180)
#define MMI_GX_FROGCANDY_GRADE_Y              (111)
#define MMI_GX_FROGCANDY_BASKET_WIDTH    (34)
#define MMI_GX_FROGCANDY_BASKET_HEIGHT   (34)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_X        (188)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_Y        (200)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_WIDTH    (40)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_HEIGHT   (144)
#define MMI_GX_FROGCANDY_ENERGY_BAR_X          (189)
#define MMI_GX_FROGCANDY_ENERGY_BAR_Y          (301)
#define MMI_GX_FROGCANDY_ENERGY_BAR_WIDTH      (38)
#define MMI_GX_FROGCANDY_ENERGY_BAR_HEIGHT     (11)
#define MMI_GX_FROGCANDY_MAX_SCORE_HEIGHT      (24)
#define MMI_GX_FROGCANDY_MAX_DROP_DISTANCE        (16)
#define MMI_GX_FROGCANDY_INFO_IMG_X (182)
#define MMI_GX_FROGCANDY_INFO_IMG_Y (6)
#define MMI_GX_FROGCANDY_INFO_HEIGHT (50)
#define MMI_GX_FROGCANDY_INFO_STR_X (178)
#define MMI_GX_FROGCANDY_INFO_STR_Y (36)
#define MMI_GX_FROGCANDY_LEVEL_ICON_WIDTH (20)
#define MMI_GX_FROGCANDY_LEVEL_ICON_HEIGHT (20)

#define MMI_GX_FROGCANDY_INITIAL_FROGCANDY_COL_IDX (2)
#define MMI_GX_FROGCANDY_FROGCANDY_COL_VALUE    {0, 35, 70, 105, 140}

#define MMI_GX_FROGCANDY_MAX_DROPPING_OBJECTS  (10)

#endif

#define MMI_GX_FROGCANDY_OBJECT_LEVEL_GAP (1)

#define MMI_GX_FROGCANDY_WINDOW_X2            (MMI_GX_FROGCANDY_OBJECT_WIDTH*MMI_GX_FROGCANDY_MAX_COLUMN)
#define MMI_GX_FROGCANDY_BASKET_Y               (LCD_HEIGHT - MMI_GX_FROGCANDY_BASKET_HEIGHT)

#define MMI_GX_FROGCANDY_GRADE_X2             (LCD_WIDTH)
#define MMI_GX_FROGCANDY_GRADE_Y2             (MMI_GX_FROGCANDY_GRADE_Y+MMI_GX_FROGCANDY_MAX_SCORE_HEIGHT)

#define MMI_GX_FROGCANDY_ENERGY_BARBG_X2      (MMI_GX_FROGCANDY_ENERGY_BARBG_X+MMI_GX_FROGCANDY_ENERGY_BARBG_WIDTH)
#define MMI_GX_FROGCANDY_ENERGY_BARBG_Y2      (MMI_GX_FROGCANDY_ENERGY_BARBG_Y+MMI_GX_FROGCANDY_ENERGY_BARBG_HEIGHT)

#ifdef __MMI_TOUCH_SCREEN__
#define MMI_GX_FROGCANDY_PEN_MOVE_COLUMN_THREADSHOLD (MMI_GX_FROGCANDY_OBJECT_WIDTH/2)
#endif

#define MMI_GX_FROGCANDY_MAX_LEVEL      3
#define MMI_GX_FROGCANDY_DONE_TIMEROUT         1000
#define MMI_GX_FROGCANDY_OBJECT_DROP_TIME      200
#define MMI_GX_FROGCANDY_MAX_DROP_OBJECT       6

#define MMI_GX_FROGCANDY_MAX_HIGHEST_GRADE     5

#define MMI_GX_FROGCANDY_BONUS_TIMER_COUNT     1000

#define MMI_GX_FROGCANDY_BOUNSTIMEINSEC        15
#define MMI_GX_FROGCANDY_POPUP_FROGCANDY_DURATION 1000

#define MMI_GX_FROGCANDY_GIFT_WEIGHT       10
#define MMI_GX_FROGCANDY_GOLDNOTE_WEIGHT   8
#define MMI_GX_FROGCANDY_BOMB_WEIGHT       20
#define MMI_GX_FROGCANDY_APPLE_WEIGHT      5
#define MMI_GX_FROGCANDY_SPIDER_WEIGHT     14
#define MMI_GX_FROGCANDY_BATTER20_WEIGHT   1
#define MMI_GX_FROGCANDY_BATTERY_WEIGHT    1
#define MMI_GX_FROGCANDY_ANGLE_WEIGHT      2
#define MMI_GX_FROGCANDY_THEIF_WEIGHT      6
#define MMI_GX_FROGCANDY_DENONATOR_WEIGHT  12
#define MMI_GX_FROGCANDY_MONEY_WEIGHT      15
#define MMI_GX_FROGCANDY_BAT_WEIGHT        20
#define MMI_GX_FROGCANDY_DEAMON_WEIGHT     5

/************************************************************************/
/* Structure                                             */
/************************************************************************/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
//added for multi-language support
typedef enum
{
    MMI_FROGCANDY_STRING_BACKGROUND,
    MMI_FROGCANDY_STRING_BACKGROUND_TIMER,
    MMI_FROGCANDY_STRING_BACKGROUND_LEVEL,
    MMI_FROGCANDY_STRING_TOTAL
}mmi_frogcandy_string_enum;
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

typedef struct
{
    U8 objWeight;
    S32 scoreRate;
    U8 dropLevel;
} FROGCANDY_OBJECT_IMAGE_STRUCT;

typedef enum
{
    /* return 0 for Alive, 1 for Half Clash, 2 for Full Cash, 3 for Dead */
    FROGCANDY_OBJECT_STATUS_ALIVE,
    FROGCANDY_OBJECT_STATUS_HALF_CRASH,
    FROGCANDY_OBJECT_STATUS_FULL_CRASH,
    FROGCANDY_OBJECT_STATUS_DEAD
} FROGCANDY_OBJECT_STATUS_ENUM;

typedef enum
{
    FROGCANDY_GIFT = 0,
    FROGCANDY_GOLDNOTE,
    FROGCANDY_BOMB,
    FROGCANDY_APPLE,
    FROGCANDY_SPIDER,  //FROGCANDY_STONE
    FROGCANDY_BATTER20,
    FROGCANDY_BATTERY,
    FROGCANDY_ANGLE,
    FROGCANDY_THEIF,
    FROGCANDY_DENONATOR,
    FROGCANDY_MONEY,
    FROGCANDY_BAT,
    FROGCANDY_DEAMON,
    FROGCANDY_TOTAL_OBJECTS    /* Dont Remove This Keeping The Count */
} FROGCANDY_OBJECT_ENUM;

typedef enum
{
    FROGCANDY_BONUS_FLAG_NONE,
    FROGCANDY_BONUS_FLAG_ANGLE,
    FROGCANDY_BONUS_FLAG_DENONATOR
} FROGCANDY_BONUS_FLAG_ENUM;

typedef struct
{
    FROGCANDY_OBJECT_ENUM objectType;  /* One of the FROGCANDY_OBJECT_IMAGE_STRUCT Type */
    U16 X;
    U16 Y;
} FROGCANDY_FLOATING_OBJECT_STRUCT;

/* game context */
typedef struct
{
    MMI_BOOL is_game_over;
    MMI_BOOL is_new_game;
    MMI_BOOL is_bound_time_out;
    MMI_BOOL flag_angle_denonator;
    U8 game_level;
    U8 energy_counter;
    U16 timer_elapse;
    S32 energy;
    S16 game_grade;
    U8 runtime_object_num;
    U8 current_drop_object;
    FROGCANDY_BONUS_FLAG_ENUM bonus_flag;
    U8 basket_position;  /* column */
    U16 drop_timer;
    U8 bouns_timer;
    
    mmi_gfx_position basket_pos;
#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL is_pen_hit;
#endif

    gdi_handle background;
    gdi_handle foreground;
} gx_frogcandy_context_struct;

/************************************************************************/
/* Golbal Varable [Const]                                   */
/************************************************************************/
const static U8 frogcandy_column[MMI_GX_FROGCANDY_MAX_COLUMN] = MMI_GX_FROGCANDY_FROGCANDY_COL_VALUE;

/************************************************************************/
/* Audio [Const]                                         */
/************************************************************************/
#define FROGCANDYEATGOOD         138
#define FROGCANDYEATBAD          133

__align(2)
     const U8 FrogCandyEatGood[138] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x74, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67,
         0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00,
         0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59,
         0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x05, 0x24, 0xB7, 0x00, 0xC0, 0x0A, 0x00, 0xB0, 0x07,
         0x60, 0x00, 0x90, 0x48, 0x64, 0x00, 0xC1, 0x61, 0x00, 0xB1, 0x07, 0x7C, 0x00, 0x91, 0x48, 0x64,
         0x81, 0x70, 0x90, 0x48, 0x00, 0x00, 0x4A, 0x64, 0x81, 0x70, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x81,
         0x70, 0x4C, 0x00, 0x00, 0x4F, 0x64, 0x81, 0x70, 0x4F, 0x00, 0x00, 0x54, 0x64, 0x81, 0x70, 0x54,
         0x00, 0x00, 0x91, 0x48, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

__align(2)
     const U8 FrogCandyEatBad[133] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x6F, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67,
         0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00,
         0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59,
         0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x09, 0x27, 0xC0, 0x00, 0xB9, 0x07, 0x7D, 0x00, 0x99,
         0x4F, 0x7D, 0x00, 0xC0, 0x10, 0x00, 0xB0, 0x07, 0x62, 0x00, 0x90, 0x42, 0x7A, 0x00, 0x41, 0x7A,
         0x05, 0x40, 0x7A, 0x00, 0x43, 0x7A, 0x73, 0x99, 0x4E, 0x7D, 0x83, 0x5C, 0x90, 0x41, 0x00, 0x00,
         0x42, 0x00, 0x05, 0x40, 0x00, 0x00, 0x99, 0x4F, 0x00, 0x00, 0x4E, 0x00, 0x00, 0x90, 0x43, 0x00,
         0x00, 0xFF, 0x2F, 0x00
     };

/************************************************************************/
/* Golbal Varable [295 Byte]                                */
/************************************************************************/
static U8 frogcandy_object_weight[MMI_GX_FROGCANDY_GIFT_WEIGHT + MMI_GX_FROGCANDY_GOLDNOTE_WEIGHT + MMI_GX_FROGCANDY_BOMB_WEIGHT
                               + MMI_GX_FROGCANDY_APPLE_WEIGHT + MMI_GX_FROGCANDY_SPIDER_WEIGHT + MMI_GX_FROGCANDY_BATTER20_WEIGHT
                               + MMI_GX_FROGCANDY_BATTERY_WEIGHT + MMI_GX_FROGCANDY_ANGLE_WEIGHT + MMI_GX_FROGCANDY_THEIF_WEIGHT
                               + MMI_GX_FROGCANDY_DENONATOR_WEIGHT + MMI_GX_FROGCANDY_MONEY_WEIGHT + MMI_GX_FROGCANDY_BAT_WEIGHT +
                               MMI_GX_FROGCANDY_DEAMON_WEIGHT];

static FROGCANDY_OBJECT_IMAGE_STRUCT frogcandy_dropping_object[FROGCANDY_TOTAL_OBJECTS];
static FROGCANDY_FLOATING_OBJECT_STRUCT frogcandy_object_on_screen[MMI_GX_FROGCANDY_MAX_DROPPING_OBJECTS];

#ifdef  __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /*added for game multi-language*/
static U16 mmi_frogcandy_language_index;
#define MMI_FROGCANDY_STRING_COUNT MMI_FROGCANDY_STRING_TOTAL
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

static color FROGCANDY_SCORE_TEXT_COLOR = {73,74,9,255};

static gx_frogcandy_context_struct g_gx_frogcandy_context = 
{
    MMI_FALSE,
    MMI_TRUE,
    MMI_FALSE,
    MMI_FALSE,
    0,
    0,
    100,
    10,
    0,
    0,
    0,
    FROGCANDY_BONUS_FLAG_NONE,
    MMI_GX_FROGCANDY_INITIAL_FROGCANDY_COL_IDX
};
/************************************************************************/
/* Function Declare                                      */
/************************************************************************/
/* Game framework related functions */
void mmi_gx_frogcandy_draw_gameover(void);
void mmi_gx_frogcandy_enter_game(void);
void mmi_gx_frogcandy_exit_game(void);
S16 mmi_gx_frogcandy_calc_best_grade(S16 old_grade, S16 new_grade);

/* Game play functions */
void mmi_gx_frogcandy_enter_new_game(void);
void mmi_gx_frogcandy_enter_resume_game(void);
void mmi_gx_frogcandy_init_app(void);

void mmi_gx_frogcandy_init_falling_object(void);
void mmi_gx_frogcandy_move_left(void);
void mmi_gx_frogcandy_move_right(void);
void mmi_gx_frogcandy_show_timer_text(void);
void mmi_gx_frogcandy_create_object(void);
void mmi_gx_frogcandy_drop_object_timer_callback(void);
void mmi_gx_frogcandy_check_object_status(void);
void mmi_gx_frogcandy_cyclic_timer(void);
void mmi_gx_frogcandy_render(void);
void mmi_gx_frogcandy_draw_energy_level(void);
void mmi_gx_frogcandy_kill_running_object(U8 ID);
FROGCANDY_OBJECT_STATUS_ENUM mmi_gx_frogcandy_check_object_crash(U8 i);
void mmi_gx_frogcandy_full_crash(U8 i);
void mmi_gx_frogcandy_action_angle(void);
void mmi_gx_frogcandy_action_denonator(void);
void mmi_gx_frogcandy_reset_running_object(void);
void mmi_gx_frogcandy_bonus_time_out(void);
void mmi_gx_frogcandy_end_game(void);
void mmi_gx_frogcandy_draw_level(void);

#ifdef __MMI_TOUCH_SCREEN__
void mmi_gx_frogcandy_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_gx_frogcandy_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_gx_frogcandy_pen_move_hdlr(mmi_pen_point_struct pos);
#endif  //__MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_enter_gfx
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_enter_gfx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    //GFX.game_data.game_img_id = IMG_GX_FROGCANDY_GAME_ICON;    /* game icon img ID */
    GFX.game_data.game_str_id = STR_GX_FROGCANDY_GAME_NAME;    /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME;     /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;           /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_GAME_LEVEL;       /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;       /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP;         /* "Game Help string ID */

    /* level / grade */
    GFX.game_data.level_count = 3;  /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GX_FROGCANDY_EASY;    /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_GX_FROGCANDY_NORMAL;  /* level string ID */
    GFX.game_data.level_str_id_list[2] = STR_GX_FROGCANDY_HARD;    /* level string ID */

    GFX.game_data.grade_nvram_id_list[0] = NVRAM_FROGCANDY_EASY_SCORE;     /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[1] = NVRAM_FROGCANDY_NORMAL_SCORE;   /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[2] = NVRAM_FROGCANDY_HARD_SCORE;     /* grade slot in NVRAM */
    GFX.game_data.level_nvram_id = NVRAM_GAME_FROGCANDY_STATUS;    /* current lvl idnex stored in NVRAM */

    /* help */
    #ifndef __MMI_TOUCH_SCREEN__
    GFX.game_data.help_str_id = STR_GX_FROGCANDY_HELP_DESCRIPTION; /* help desciption string id */
    #else
    GFX.game_data.help_str_id = STR_GX_FROGCANDY_HELP_DESCRIPTION_TOUCH; /* help desciption string id */
    #endif

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&g_gx_frogcandy_context.game_grade);       /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&g_gx_frogcandy_context.game_level);        /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) & g_gx_frogcandy_context.is_new_game;  /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = mmi_gx_frogcandy_calc_best_grade; /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = mmi_gx_frogcandy_enter_game;  /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = mmi_gx_frogcandy_exit_game;    /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = mmi_gx_frogcandy_draw_gameover;        /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = MMI_FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_calc_best_grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 mmi_gx_frogcandy_calc_best_grade(S16 old_grade, S16 new_grade)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_grade > old_grade)
    {
        return new_grade;
    }
    else
    {
        return old_grade;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_draw_gameover
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_draw_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_GAMEOVER();

    g_gx_frogcandy_context.is_game_over = MMI_TRUE;
    g_gx_frogcandy_context.is_new_game = MMI_TRUE;

    /* call this function to draw standard gameover screen */
    mmi_gfx_draw_gameover_screen(NULL, NULL, IMG_GX_FROGCANDY_OBJECT_EVIL, g_gx_frogcandy_context.game_grade);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_enter_game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_enter_game()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //used for multilanguage
    mmi_frogcandy_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_frogcandy_language_index, 
        IMG_GX_FROGCANDY_BACKGROUND_LANGUAGE0, 
        MMI_FROGCANDY_STRING_COUNT);
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    if (g_gx_frogcandy_context.is_new_game == MMI_TRUE)
    {
        mmi_gx_frogcandy_enter_new_game();
        g_gx_frogcandy_context.is_new_game = MMI_FALSE;
    }
    else
    {
        mmi_gx_frogcandy_enter_resume_game();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_exit_game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_exit_game(void)
{
    gui_cancel_timer(mmi_gx_frogcandy_bonus_time_out);
    gui_cancel_timer(mmi_gx_frogcandy_drop_object_timer_callback);
    gui_cancel_timer(mmi_gx_frogcandy_cyclic_timer);
    
    //gdi_layer_flatten_to_base(g_gx_frogcandy_context.background, g_gx_frogcandy_context.foreground, 0, 0);
    gdi_layer_free(g_gx_frogcandy_context.foreground);
    gdi_layer_multi_layer_disable();
}

/************************************************************************/
/************************************************************************/
/* BELOW THIS LINE IS GAME KERNAL IMPLMENTED BY PIXTEL.              */
/************************************************************************/
/************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_enter_resume_game
 * DESCRIPTION
 *  Entry Function On Game Resume. Set The Game Running Flag TRUE and Enter
 *  FrogCandy Init Application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_enter_resume_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_frogcandy_context.is_game_over = MMI_FALSE;
    clear_screen();

    #ifdef __MMI_TOUCH_SCREEN__
    if (g_gx_frogcandy_context.basket_pos.x % MMI_GX_FROGCANDY_OBJECT_WIDTH != 0)
    {
        //move basket to column
        for (i = 0; i < MMI_GX_FROGCANDY_MAX_COLUMN; i++)
        {
            if (g_gx_frogcandy_context.basket_pos.x-frogcandy_column[i] < MMI_GX_FROGCANDY_PEN_MOVE_COLUMN_THREADSHOLD)
            {
                g_gx_frogcandy_context.basket_pos.x = frogcandy_column[i];
                g_gx_frogcandy_context.basket_position = i;
                break;
            }
        }
    }
    #endif  //__MMI_TOUCH_SCREEN__
        
    mmi_gx_frogcandy_init_app();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_enter_new_game
 * DESCRIPTION
 *  FrogCandy New Game Entry Function, Reinit Various Flags, Enter FrogCandy Init
 *  Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_enter_new_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 CurrentLevel;
    U8 dropTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_frogcandy_context.is_game_over = MMI_FALSE;
    g_gx_frogcandy_context.game_grade = 0;
    g_gx_frogcandy_context.energy = 10;
    g_gx_frogcandy_context.current_drop_object = 0;
    g_gx_frogcandy_context.bonus_flag = FROGCANDY_BONUS_FLAG_NONE;
    g_gx_frogcandy_context.bouns_timer = 0;
    g_gx_frogcandy_context.basket_position = MMI_GX_FROGCANDY_INITIAL_FROGCANDY_COL_IDX;
    CurrentLevel = g_gx_frogcandy_context.game_level;
    dropTime = MMI_GX_FROGCANDY_OBJECT_DROP_TIME / (CurrentLevel + 1);

    memset(&frogcandy_object_on_screen[i], 0, sizeof(FROGCANDY_FLOATING_OBJECT_STRUCT) * MMI_GX_FROGCANDY_MAX_DROPPING_OBJECTS);

    clear_screen();
    mmi_gx_frogcandy_init_app();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_init_app
 * DESCRIPTION
 *  Init FrogCandy Games, Allocate Bit Buffer, Initalize Objects, Draw Background,
 *  Get DS Values In Case Of Resume, Set Key Handlers, Enter Game Kernal
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_disable_alignment_timers();
    
    clear_screen();

    /* Set The Drop Time Depending On Game Level */
    g_gx_frogcandy_context.drop_timer = 2 * (MMI_GX_FROGCANDY_OBJECT_DROP_TIME - g_gx_frogcandy_context.game_level * 50);

    /* Screen render timer */
    g_gx_frogcandy_context.timer_elapse = 100;

    /* Init Falling Objects Data */
    mmi_gx_frogcandy_init_falling_object();

    /* Set The Energy Counter To Zero */
    g_gx_frogcandy_context.energy_counter = 0;

    /* In Case Of New Game, Get Bucket Size And Default Cordinates */
    if (g_gx_frogcandy_context.is_new_game)    /* New Game */
    {
        g_gx_frogcandy_context.basket_pos.x = frogcandy_column[MMI_GX_FROGCANDY_INITIAL_FROGCANDY_COL_IDX];
    }
    g_gx_frogcandy_context.basket_pos.y = MMI_GX_FROGCANDY_BASKET_Y;

    gdi_layer_multi_layer_enable();

    gdi_layer_get_base_handle(&g_gx_frogcandy_context.background);

    /* Draw The Game Background */    
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gdi_image_draw_id(0, 0, IMG_GX_FROGCANDY_BACKGROUND);
#else
    gdi_image_draw_id(
        0, 
        0, 
        mmi_gfx_get_multilanguage_image_ID(
            mmi_frogcandy_language_index, 
            IMG_GX_FROGCANDY_BACKGROUND_LANGUAGE0, 
            MMI_FROGCANDY_STRING_COUNT, 
            MMI_FROGCANDY_STRING_BACKGROUND));
#endif

    gdi_layer_create(
        0,
        0,
        MMI_GX_FROGCANDY_LCD_WIDTH,
        MMI_GX_FROGCANDY_LCD_HEIGHT,
        &g_gx_frogcandy_context.foreground);
    gdi_layer_push_and_set_active(g_gx_frogcandy_context.foreground);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT); /* set pure-blue as the transparent color in foreground */
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);     /* clean foreground layer */

    gdi_layer_pop_and_restore_active();
    
    /* If Resume Game Was On Bonus Start The Bonus Timer Callback */
    if (g_gx_frogcandy_context.bonus_flag != FROGCANDY_BONUS_FLAG_NONE && g_gx_frogcandy_context.bouns_timer < MMI_GX_FROGCANDY_BOUNSTIMEINSEC)
    {
        //g_gx_frogcandy_context.is_bound_time_out = MMI_TRUE;
        mmi_gx_frogcandy_bonus_time_out();
    }
    
    mmi_gx_frogcandy_cyclic_timer();

    gdi_layer_blt(
        g_gx_frogcandy_context.background, /* layer 0 */
        g_gx_frogcandy_context.foreground, /* layer 1 */
        0,                                  /* layer 2 */
        0,                                  /* layer 3 */
        0,                                  /* offset x */
        0,                                  /* offset y */
        MMI_GX_FROGCANDY_LCD_WIDTH - 1,    /* width */
        MMI_GX_FROGCANDY_LCD_HEIGHT - 1);  /* height */
    
    /* Set Various Key Handlers */
    SetKeyHandler(mmi_gx_frogcandy_move_left, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_frogcandy_move_right, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_frogcandy_move_left, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_frogcandy_move_right, KEY_6, KEY_EVENT_DOWN);

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_register_pen_down_handler(mmi_gx_frogcandy_pen_down_hdlr);    /* function to pen down event */
    wgui_register_pen_up_handler(mmi_gx_frogcandy_pen_up_hdlr);        /* function to pen up event */
    wgui_register_pen_move_handler(mmi_gx_frogcandy_pen_move_hdlr);    /* function to pen up event */
#endif  //__MMI_TOUCH_SCREEN__

    /* If Game End Flag Is False Start The Game Kernal */
    if (!g_gx_frogcandy_context.is_game_over)
    {
        gui_start_timer(g_gx_frogcandy_context.drop_timer, mmi_gx_frogcandy_drop_object_timer_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_move_left
 * DESCRIPTION
 *  Move FrogCandy Basket To Left
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_move_left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_frogcandy_context.basket_position == 0)
    {
        return;
    }
    g_gx_frogcandy_context.basket_pos.x = frogcandy_column[--g_gx_frogcandy_context.basket_position];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_move_right
 * DESCRIPTION
 *  Move FrogCandy Basket To Right
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_move_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_frogcandy_context.basket_position == (MMI_GX_FROGCANDY_MAX_COLUMN - 1))
    {
        return;
    }
    g_gx_frogcandy_context.basket_pos.x = frogcandy_column[++g_gx_frogcandy_context.basket_position];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_drop_object_timer_callback
 * DESCRIPTION
 *  FrogCandy Game Main Kernal
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_drop_object_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If Game Over Then Return. */
    if (g_gx_frogcandy_context.is_game_over)
    {
        return;
    }

    if (g_gx_frogcandy_context.current_drop_object < MMI_GX_FROGCANDY_MAX_DROPPING_OBJECTS)
    {
        mmi_gx_frogcandy_create_object();
    }

    /* Drop The Object Depending Upon their , drop level less means object is faster. */
    for (i = 0; i < g_gx_frogcandy_context.current_drop_object; i++)
    {
        frogcandy_object_on_screen[i].Y +=
            (MMI_GX_FROGCANDY_MAX_DROP_DISTANCE / frogcandy_dropping_object[frogcandy_object_on_screen[i].objectType].dropLevel);
    }

    /* Redraw Screen. */
    //mmi_gx_frogcandy_render();

    /* Reset the timer. */
    if (!g_gx_frogcandy_context.is_game_over)
    {
        if (g_gx_frogcandy_context.bonus_flag != FROGCANDY_BONUS_FLAG_NONE)
        {
            g_gx_frogcandy_context.drop_timer = 30;
        }
        else
        {
            g_gx_frogcandy_context.drop_timer = 2 * (MMI_GX_FROGCANDY_OBJECT_DROP_TIME - g_gx_frogcandy_context.game_level * 50);
        }
        gui_start_timer(g_gx_frogcandy_context.drop_timer, mmi_gx_frogcandy_drop_object_timer_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_create_object
 * DESCRIPTION
 *  FrogCandy New Objects Are Created In This API.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_create_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 randnum = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* In This Loop Object is created and its X value is determined on the Basis of no other slower in that colomn */
    while (1)
    {

        switch (g_gx_frogcandy_context.bonus_flag)
        {
            case FROGCANDY_BONUS_FLAG_ANGLE:
                randnum = rand() % 2;
                if (randnum == 0)
                {
                    frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].objectType = FROGCANDY_MONEY;
                }
                else
                {
                    frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].objectType = FROGCANDY_GIFT;
                }
                break;
            case FROGCANDY_BONUS_FLAG_DENONATOR:
                if (randnum == 0)
                {
                    frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].objectType = FROGCANDY_BAT;
                }
                else
                {
                    frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].objectType = FROGCANDY_DENONATOR;
                }
                break;
            default:
            {
                randnum = rand() % g_gx_frogcandy_context.runtime_object_num;
                frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].objectType =
                    frogcandy_object_weight[randnum];
            }
        }

        randnum = rand() % MMI_GX_FROGCANDY_MAX_COLUMN;
        frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].X = frogcandy_column[randnum];

        for (i = 0; i < g_gx_frogcandy_context.current_drop_object; i++)
        {
            if (frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].X == frogcandy_object_on_screen[i].X)
                if (frogcandy_dropping_object[frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].objectType].dropLevel <= frogcandy_dropping_object[frogcandy_object_on_screen[i].objectType].dropLevel)      /* Drop level less means object is faster. */
                    if (((LCD_HEIGHT -
                          frogcandy_object_on_screen[i].Y) *
                         frogcandy_dropping_object[frogcandy_object_on_screen[i].objectType].dropLevel) + 60 >=
                        (LCD_HEIGHT *
                         frogcandy_dropping_object[frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].objectType].dropLevel))
                    {
                        i = 0xFF;
                        break;
                    }
        }
        if (i == 0xFF)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    /* Set the object Y to zero */
    frogcandy_object_on_screen[g_gx_frogcandy_context.current_drop_object].Y = 0;

    /* Allocate Bit Buffer from the Pool */

    /* Increment Droping Object */
    g_gx_frogcandy_context.current_drop_object++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_check_object_status
 * DESCRIPTION
 *  Check FrogCandy Falling Object Status
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_check_object_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    MMI_BOOL flagKilled = MMI_FALSE;
    U8 tempRunningObjects = g_gx_frogcandy_context.current_drop_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < tempRunningObjects; i++)
    {
        /* Check The Object For Crash With Basket */
        FROGCANDY_OBJECT_STATUS_ENUM crashResult = mmi_gx_frogcandy_check_object_crash(i);

        switch (crashResult)    /* return 0 for Alive, 1 for Half Clash, 2 for Full Cash, 3 for Dead */
        {
            case FROGCANDY_OBJECT_STATUS_ALIVE:
                break;

            case FROGCANDY_OBJECT_STATUS_HALF_CRASH: /* halfCrash(i); */
                mmi_gx_frogcandy_full_crash(i);
                if (g_gx_frogcandy_context.is_game_over)
                {
                    return;
                }
                /* Remove The Fallinf Object From Data Structure */
                mmi_gx_frogcandy_kill_running_object(i);
                if (g_gx_frogcandy_context.current_drop_object != 0)
                {
                    g_gx_frogcandy_context.current_drop_object--;
                }
                flagKilled = MMI_TRUE;
                break;

            case FROGCANDY_OBJECT_STATUS_FULL_CRASH:
                mmi_gx_frogcandy_full_crash(i);
                if (g_gx_frogcandy_context.is_game_over)
                {
                    return;
                }
                if (g_gx_frogcandy_context.flag_angle_denonator)
                {
                    g_gx_frogcandy_context.flag_angle_denonator = MMI_FALSE;
                    return;
                }
                mmi_gx_frogcandy_kill_running_object(i);
                if (g_gx_frogcandy_context.current_drop_object != 0)
                {
                    g_gx_frogcandy_context.current_drop_object--;
                }
                flagKilled = MMI_TRUE;
                break;

            case FROGCANDY_OBJECT_STATUS_DEAD:
                mmi_gx_frogcandy_kill_running_object(i);
                if (g_gx_frogcandy_context.current_drop_object != 0)
                {
                    g_gx_frogcandy_context.current_drop_object--;
                }
                flagKilled = MMI_TRUE;
                break;

            default:
                break;
        }
    }

    /* If Any Of The Objects Is Removed From Data Structure, Re Seqence The FrogCandy Object Data Structure */
    if (flagKilled == MMI_TRUE)
    {
        for (i = 0; i < tempRunningObjects; i++)
        {
            if (i == g_gx_frogcandy_context.current_drop_object)
            {
                break;
            }
            if (frogcandy_object_on_screen[i].objectType == 0 && frogcandy_object_on_screen[i].X == 0 &&
                frogcandy_object_on_screen[i].Y == 0)
            {
                U8 j = i + 1;

                memcpy(
                    (void*)(frogcandy_object_on_screen + i),
                    (void*)(frogcandy_object_on_screen + j),
                    sizeof(FROGCANDY_FLOATING_OBJECT_STRUCT) * (MMI_GX_FROGCANDY_MAX_DROPPING_OBJECTS - j));
                --i;
            }
        }
        flagKilled = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_cyclic_timer
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_cyclic_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_gx_frogcandy_cyclic_timer);
    if (!g_gx_frogcandy_context.is_game_over)
    {
        mmi_gx_frogcandy_render();
    }

    gui_start_timer(g_gx_frogcandy_context.timer_elapse, mmi_gx_frogcandy_cyclic_timer);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_render
 * DESCRIPTION
 *  Redraw The Modified Portion Of FrogCandy Game Screen
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 displayString[20];
    U8 tempString[10];
    S32 strWidth;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check for Crash */
    mmi_gx_frogcandy_check_object_status();
    
    if (g_gx_frogcandy_context.is_game_over != MMI_FALSE)
    {
        return;
    }
    
    gdi_layer_push_and_set_active(g_gx_frogcandy_context.foreground);
    gui_push_and_set_clip(0, 0, MMI_GX_FROGCANDY_WINDOW_X2, MMI_GX_FROGCANDY_LCD_HEIGHT);
    gdi_draw_solid_rect(0, 0, MMI_GX_FROGCANDY_WINDOW_X2, MMI_GX_FROGCANDY_LCD_HEIGHT, GDI_COLOR_TRANSPARENT);
    /* Draw The Falling FrogCandy Objects */
    for (i = 0; i < g_gx_frogcandy_context.current_drop_object; i++)
    {
        U8 objectType = frogcandy_object_on_screen[i].objectType;
        
        if (frogcandy_object_on_screen[i].X != 0 || frogcandy_object_on_screen[i].Y != 0)
        {
            gdi_image_draw_id(
                frogcandy_object_on_screen[i].X,
                frogcandy_object_on_screen[i].Y,
                IMG_GX_FROGCANDY_OBJECT_GIFT+objectType-FROGCANDY_GIFT);
        }
    }
    gdi_draw_solid_rect(g_gx_frogcandy_context.basket_pos.x, g_gx_frogcandy_context.basket_pos.y, g_gx_frogcandy_context.basket_pos.x+MMI_GX_FROGCANDY_BASKET_WIDTH,g_gx_frogcandy_context.basket_pos.y+MMI_GX_FROGCANDY_BASKET_HEIGHT,GDI_COLOR_TRANSPARENT);
    gdi_image_draw_id(g_gx_frogcandy_context.basket_pos.x, g_gx_frogcandy_context.basket_pos.y, IMG_GX_FROGCANDY_BASKET);
    gui_pop_clip();

    /* Draw The Energy Bar */
    mmi_gx_frogcandy_draw_energy_level();

    /* Draw Score */
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__)
    gui_set_font(&MMI_medium_font);
    #else
    gui_set_font(&MMI_small_font);
    #endif
    gui_set_text_color(FROGCANDY_SCORE_TEXT_COLOR);
    /* Fill The Back Ground Rectangle Of Score/Timer */
    gui_push_and_set_clip(MMI_GX_FROGCANDY_GRADE_X, MMI_GX_FROGCANDY_GRADE_Y, MMI_GX_FROGCANDY_GRADE_X2, MMI_GX_FROGCANDY_GRADE_Y2);
    gdi_draw_solid_rect(MMI_GX_FROGCANDY_GRADE_X, MMI_GX_FROGCANDY_GRADE_Y, MMI_GX_FROGCANDY_GRADE_X2, MMI_GX_FROGCANDY_GRADE_Y2, GDI_COLOR_TRANSPARENT);

    sprintf((PS8) tempString, "%d", g_gx_frogcandy_context.game_grade);
    mmi_asc_to_ucs2((PS8) displayString, (PS8) tempString);
    strWidth = gui_get_string_width((UI_string_type) displayString);
    strWidth /= 2;

    gui_move_text_cursor(MMI_GX_FROGCANDY_GRADE_X, MMI_GX_FROGCANDY_GRADE_Y);

    gui_print_text((UI_string_type) displayString);
    gui_pop_clip();

    if (g_gx_frogcandy_context.bouns_timer >= MMI_GX_FROGCANDY_BOUNSTIMEINSEC ||
        g_gx_frogcandy_context.bouns_timer <= 0)
    {
        if (g_gx_frogcandy_context.bouns_timer >= MMI_GX_FROGCANDY_BOUNSTIMEINSEC)
        {
            g_gx_frogcandy_context.bonus_flag = FROGCANDY_BONUS_FLAG_NONE;
            g_gx_frogcandy_context.bouns_timer = 0;
        }
        mmi_gx_frogcandy_draw_level();
    }
    
    if (g_gx_frogcandy_context.is_bound_time_out && g_gx_frogcandy_context.bouns_timer != 0)
    {
        mmi_gx_frogcandy_show_timer_text();
        gui_start_timer(MMI_GX_FROGCANDY_BONUS_TIMER_COUNT, mmi_gx_frogcandy_bonus_time_out);
    }
    
    g_gx_frogcandy_context.is_bound_time_out = MMI_FALSE;
    
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_blt(
        g_gx_frogcandy_context.background, /* layer 0 */
        g_gx_frogcandy_context.foreground, /* layer 1 */
        0,                                  /* layer 2 */
        0,                                  /* layer 3 */
        0,                                  /* offset x */
        0,                                  /* offset y */
        MMI_GX_FROGCANDY_LCD_WIDTH - 1,    /* width */
        MMI_GX_FROGCANDY_LCD_HEIGHT - 1);  /* height */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_draw_energy_level
 * DESCRIPTION
 *  Draw FrogCandy Energy On Side Bar
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_draw_energy_level(void) /* 0 - Down,        1 - Up */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_and_set_clip(MMI_GX_FROGCANDY_ENERGY_BARBG_X, MMI_GX_FROGCANDY_ENERGY_BARBG_Y, MMI_GX_FROGCANDY_ENERGY_BARBG_X2, MMI_GX_FROGCANDY_ENERGY_BARBG_Y2);
    gdi_draw_solid_rect(MMI_GX_FROGCANDY_ENERGY_BARBG_X, MMI_GX_FROGCANDY_ENERGY_BARBG_Y, MMI_GX_FROGCANDY_ENERGY_BARBG_X2, MMI_GX_FROGCANDY_ENERGY_BARBG_Y2, GDI_COLOR_TRANSPARENT);

    /* If Energy Is Reduces Draw Whole Energy Bar */
    if (g_gx_frogcandy_context.energy_counter >= g_gx_frogcandy_context.energy || g_gx_frogcandy_context.energy_counter == 0)
    {
        for (g_gx_frogcandy_context.energy_counter = 0; g_gx_frogcandy_context.energy_counter < g_gx_frogcandy_context.energy; g_gx_frogcandy_context.energy_counter++)
        {
            gdi_image_draw_id(
                MMI_GX_FROGCANDY_ENERGY_BAR_X,
                MMI_GX_FROGCANDY_ENERGY_BAR_Y - g_gx_frogcandy_context.energy_counter * MMI_GX_FROGCANDY_ENERGY_BAR_HEIGHT,
                IMG_GX_FROGCANDY_ENERGYBAR);
        }
    }
    /* Else Draw Only Energy Bars Which Are Added */
    else
    {
        for (; g_gx_frogcandy_context.energy_counter < g_gx_frogcandy_context.energy; g_gx_frogcandy_context.energy_counter++)
        {
            gdi_image_draw_id(
                MMI_GX_FROGCANDY_ENERGY_BAR_X,
                MMI_GX_FROGCANDY_ENERGY_BAR_Y - g_gx_frogcandy_context.energy_counter * MMI_GX_FROGCANDY_ENERGY_BAR_HEIGHT,
                IMG_GX_FROGCANDY_ENERGYBAR);
        }
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_init_falling_object
 * DESCRIPTION
 *  Initlize FrogCandy Object Data Structure
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_init_falling_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, k = 1; /* Temp Variables; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < FROGCANDY_TOTAL_OBJECTS; i++)
    {
        switch (i)
        {
            case FROGCANDY_GIFT:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_GIFT_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = 5;
                frogcandy_dropping_object[i].dropLevel = 2;
                break;  /* Predefined */

            case FROGCANDY_GOLDNOTE:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_GOLDNOTE_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = 20;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */

            case FROGCANDY_BOMB:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_BOMB_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = -5;
                frogcandy_dropping_object[i].dropLevel = 2;
                break;  /* Predefined */

            case FROGCANDY_APPLE:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_APPLE_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = 10;
                frogcandy_dropping_object[i].dropLevel = 2;
                break;  /* Predefined */

            case FROGCANDY_SPIDER:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_SPIDER_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = -4;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */

            case FROGCANDY_BATTER20:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_BATTER20_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = 1;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */

            case FROGCANDY_BATTERY:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_BATTERY_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = 3;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */

            case FROGCANDY_ANGLE:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_ANGLE_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = 0;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */

            case FROGCANDY_THEIF:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_THEIF_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = -100;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */

            case FROGCANDY_DENONATOR:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_DENONATOR_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = -2;
                frogcandy_dropping_object[i].dropLevel = 2;
                break;  /* Predefined */

            case FROGCANDY_MONEY:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_MONEY_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = 10;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */

            case FROGCANDY_BAT:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_BAT_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = -10;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */

            case FROGCANDY_DEAMON:
                frogcandy_dropping_object[i].objWeight = MMI_GX_FROGCANDY_DEAMON_WEIGHT;
                frogcandy_dropping_object[i].scoreRate = 0;
                frogcandy_dropping_object[i].dropLevel = 1;
                break;  /* Predefined */
        }
    }

    k = 0;
    for (i = 0; i < FROGCANDY_TOTAL_OBJECTS; i++)
    {
        for (j = 0; j < frogcandy_dropping_object[i].objWeight; j++)
        {
            frogcandy_object_weight[k++] = i;  /*  */
        }
    }

    g_gx_frogcandy_context.runtime_object_num = k - 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_kill_running_object
 * DESCRIPTION
 *  Remove The Object From The Data Structure
 * PARAMETERS
 *  ID      [IN]        id of the object to be removed.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_kill_running_object(U8 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    frogcandy_object_on_screen[ID].objectType = 0;
    frogcandy_object_on_screen[ID].X = 0;
    frogcandy_object_on_screen[ID].Y = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_check_object_crash
 * DESCRIPTION
 *  Check The Object Crash With Bucket
 * PARAMETERS
 *  i       [IN]        Object Id Need To Check For Crash With Basket
 * RETURNS
 *  void
 *****************************************************************************/
FROGCANDY_OBJECT_STATUS_ENUM mmi_gx_frogcandy_check_object_crash(U8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 objId = frogcandy_object_on_screen[i].objectType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (frogcandy_object_on_screen[i].Y + MMI_GX_FROGCANDY_OBJECT_HEIGHT > g_gx_frogcandy_context.basket_pos.y)
    {
        if (frogcandy_object_on_screen[i].X > g_gx_frogcandy_context.basket_pos.x)
        {
            if ((frogcandy_object_on_screen[i].X + MMI_GX_FROGCANDY_OBJECT_WIDTH) <=
                (g_gx_frogcandy_context.basket_pos.x + MMI_GX_FROGCANDY_BASKET_WIDTH))
            {
                return FROGCANDY_OBJECT_STATUS_FULL_CRASH;
            }
            else if ((frogcandy_object_on_screen[i].X + MMI_GX_FROGCANDY_OBJECT_WIDTH / 2 + 1) < g_gx_frogcandy_context.basket_pos.x + MMI_GX_FROGCANDY_BASKET_WIDTH)        /* If Object Right By Less Then 25% */
            {
                return FROGCANDY_OBJECT_STATUS_HALF_CRASH;
            }
        }
        else
        {
            if ((frogcandy_object_on_screen[i].X + MMI_GX_FROGCANDY_OBJECT_WIDTH / 2 - 1) > g_gx_frogcandy_context.basket_pos.x) /* If Object Left By Less Then 25% */
            {
                return FROGCANDY_OBJECT_STATUS_HALF_CRASH;
            }
        }
    }
    if (frogcandy_object_on_screen[i].Y >= LCD_HEIGHT)
    {
        return FROGCANDY_OBJECT_STATUS_DEAD;
    }
    
    return FROGCANDY_OBJECT_STATUS_ALIVE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_full_crash
 * TODO: time consume too long
 * DESCRIPTION
 *  Action Taken On FrogCandy Full Crash
 * PARAMETERS
 *  i       [IN]        Object Id Which Crashes
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_full_crash(U8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 objId = frogcandy_object_on_screen[i].objectType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (objId)
    {
/***********************************************/
        case FROGCANDY_GIFT:
        case FROGCANDY_GOLDNOTE:
        case FROGCANDY_APPLE:
        case FROGCANDY_MONEY:
        case FROGCANDY_THEIF:
        case FROGCANDY_BAT:
        {
            g_gx_frogcandy_context.game_grade = mmi_gfx_cal_grade(g_gx_frogcandy_context.game_grade, (S16) frogcandy_dropping_object[objId].scoreRate);

            if (g_gx_frogcandy_context.game_grade < 0)
            {
                g_gx_frogcandy_context.game_grade = 0;
            }

            if (frogcandy_dropping_object[objId].scoreRate > 0)
            {
                GFX_PLAY_AUDIO_MIDI(FrogCandyEatGood, FROGCANDYEATGOOD, DEVICE_AUDIO_PLAY_ONCE);
            }
            else if (frogcandy_dropping_object[objId].scoreRate < 0)
            {
                GFX_PLAY_AUDIO_MIDI(FrogCandyEatBad, FROGCANDYEATBAD, DEVICE_AUDIO_PLAY_ONCE);
            }
            break;
        }
/***********************************************/
        case FROGCANDY_BOMB:
        case FROGCANDY_SPIDER:
        {
            GFX_PLAY_VIBRATION();
        }
        case FROGCANDY_DENONATOR:
        case FROGCANDY_BATTER20:
        case FROGCANDY_BATTERY:
        {
            g_gx_frogcandy_context.energy += frogcandy_dropping_object[objId].scoreRate;
            if (frogcandy_dropping_object[objId].scoreRate > 0)
            {
                GFX_PLAY_AUDIO_MIDI(FrogCandyEatGood, FROGCANDYEATGOOD, DEVICE_AUDIO_PLAY_ONCE);
            }
            else if (frogcandy_dropping_object[objId].scoreRate < 0)
            {
                GFX_PLAY_AUDIO_MIDI(FrogCandyEatBad, FROGCANDYEATBAD, DEVICE_AUDIO_PLAY_ONCE);
            }

            if (g_gx_frogcandy_context.energy <= 0)
            {
                g_gx_frogcandy_context.is_game_over = MMI_TRUE;
                mmi_gx_frogcandy_end_game();
                return;
            }
            else if (g_gx_frogcandy_context.energy > 10)
            {
                g_gx_frogcandy_context.energy = 10;
            }

            break;
        }
/***********************************************/
        case FROGCANDY_ANGLE:
        {
            mmi_gx_frogcandy_action_angle();
            GFX_PLAY_AUDIO_MIDI(FrogCandyEatGood, FROGCANDYEATGOOD, DEVICE_AUDIO_PLAY_ONCE);

            break;
        }

/***********************************************/
        case FROGCANDY_DEAMON:
        {
            mmi_gx_frogcandy_action_denonator();
            GFX_PLAY_AUDIO_MIDI(FrogCandyEatBad, FROGCANDYEATBAD, DEVICE_AUDIO_PLAY_ONCE);
            break;
        }
    }   /* switch */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_action_angle
 * DESCRIPTION
 *  Action Taken In Case Of Angle Crash.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_action_angle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_gx_frogcandy_context.is_game_over)
    {
        g_gx_frogcandy_context.bonus_flag = FROGCANDY_BONUS_FLAG_ANGLE;
    	g_gx_frogcandy_context.bouns_timer = 0;
        mmi_gx_frogcandy_reset_running_object();
        mmi_gx_frogcandy_bonus_time_out();
        g_gx_frogcandy_context.flag_angle_denonator = MMI_TRUE;
        gui_cancel_timer(mmi_gx_frogcandy_cyclic_timer);
        mmi_gx_frogcandy_cyclic_timer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_action_denonator
 * DESCRIPTION
 *  Action Taken On Deamon Crash With Basket
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_action_denonator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_gx_frogcandy_context.is_game_over)
    {
        g_gx_frogcandy_context.bonus_flag = FROGCANDY_BONUS_FLAG_DENONATOR;
    	g_gx_frogcandy_context.bouns_timer = 0;
        mmi_gx_frogcandy_reset_running_object();
        mmi_gx_frogcandy_bonus_time_out();
        g_gx_frogcandy_context.flag_angle_denonator = MMI_TRUE;
        gui_cancel_timer(mmi_gx_frogcandy_cyclic_timer);
        mmi_gx_frogcandy_cyclic_timer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_reset_running_object
 * DESCRIPTION
 *  Reset All Running Objects On Deamon Or Angle Crash.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_reset_running_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_gx_frogcandy_context.current_drop_object; i++)
    {
        mmi_gx_frogcandy_kill_running_object(i);
    }
    g_gx_frogcandy_context.current_drop_object = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_bonus_time_out
 * DESCRIPTION
 *  Reset The Timer Text To Score On Bonus Time Out.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_bonus_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_frogcandy_context.bouns_timer++;
    g_gx_frogcandy_context.is_bound_time_out = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_end_game
 * DESCRIPTION
 *  Set FrogCandy Game End Flags, Enter Game End Screen.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_end_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_gx_frogcandy_bonus_time_out);
    gui_cancel_timer(mmi_gx_frogcandy_drop_object_timer_callback);

    g_gx_frogcandy_context.is_new_game = MMI_TRUE;
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_show_timer_text
 * DESCRIPTION
 *  This API Called After 1 Sec When Bonus Time Is Running To Display Remaining
 *  Bonus Time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_show_timer_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bufferCount[64];
    U8 bufferUcs2[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_and_set_clip(MMI_GX_FROGCANDY_INFO_STR_X, MMI_GX_FROGCANDY_INFO_IMG_Y, LCD_WIDTH, MMI_GX_FROGCANDY_INFO_IMG_Y+MMI_GX_FROGCANDY_INFO_HEIGHT);
    gdi_draw_solid_rect(MMI_GX_FROGCANDY_INFO_STR_X, MMI_GX_FROGCANDY_INFO_IMG_Y, LCD_WIDTH, MMI_GX_FROGCANDY_INFO_IMG_Y+MMI_GX_FROGCANDY_INFO_HEIGHT, GDI_COLOR_TRANSPARENT);

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gdi_image_draw_id(MMI_GX_FROGCANDY_INFO_IMG_X, MMI_GX_FROGCANDY_INFO_IMG_Y, IMG_GX_FROGCANDY_BACKGROUND_TIMER);
#else
    gdi_image_draw_id(
        MMI_GX_FROGCANDY_INFO_IMG_X, 
        MMI_GX_FROGCANDY_INFO_IMG_Y,
        mmi_gfx_get_multilanguage_image_ID(
             mmi_frogcandy_language_index, 
             IMG_GX_FROGCANDY_BACKGROUND_LANGUAGE0, 
             MMI_FROGCANDY_STRING_COUNT, 
             MMI_FROGCANDY_STRING_BACKGROUND_TIMER));
#endif

    sprintf((PS8) bufferCount, "%d", MMI_GX_FROGCANDY_BOUNSTIMEINSEC - g_gx_frogcandy_context.bouns_timer);
    mmi_asc_to_ucs2((PS8) bufferUcs2, (PS8) bufferCount);

    gui_move_text_cursor(MMI_GX_FROGCANDY_INFO_STR_X+2, MMI_GX_FROGCANDY_INFO_STR_Y);
    gui_print_text((UI_string_type) bufferUcs2);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_draw_level
 * DESCRIPTION
 *  Show Games Level After Bouns Timer Is Complete.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_draw_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_and_set_clip(MMI_GX_FROGCANDY_INFO_STR_X, MMI_GX_FROGCANDY_INFO_IMG_Y, LCD_WIDTH, MMI_GX_FROGCANDY_INFO_IMG_Y+MMI_GX_FROGCANDY_INFO_HEIGHT);
    gdi_draw_solid_rect(MMI_GX_FROGCANDY_INFO_STR_X, MMI_GX_FROGCANDY_INFO_IMG_Y, LCD_WIDTH, MMI_GX_FROGCANDY_INFO_IMG_Y+MMI_GX_FROGCANDY_INFO_HEIGHT, GDI_COLOR_TRANSPARENT);
    
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gdi_image_draw_id(MMI_GX_FROGCANDY_INFO_IMG_X, MMI_GX_FROGCANDY_INFO_IMG_Y, IMG_GX_FROGCANDY_BACKGROUND_LEVEL);
#else
    gdi_image_draw_id(
        MMI_GX_FROGCANDY_INFO_IMG_X, 
        MMI_GX_FROGCANDY_INFO_IMG_Y,
        mmi_gfx_get_multilanguage_image_ID(
             mmi_frogcandy_language_index, 
             IMG_GX_FROGCANDY_BACKGROUND_LANGUAGE0, 
             MMI_FROGCANDY_STRING_COUNT, 
             MMI_FROGCANDY_STRING_BACKGROUND_LEVEL));
#endif

    for (i = 0; i <= g_gx_frogcandy_context.game_level; i++)
    {
        gdi_image_draw_id(MMI_GX_FROGCANDY_INFO_STR_X+(MMI_GX_FROGCANDY_LEVEL_ICON_WIDTH+MMI_GX_FROGCANDY_OBJECT_LEVEL_GAP)*i, MMI_GX_FROGCANDY_INFO_STR_Y, IMG_GX_FROGCANDY_OBJECT_LEVEL);
    }
    gui_pop_clip();
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_pen_down_hdlr
 * DESCRIPTION
 *  pen down event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos.x >= g_gx_frogcandy_context.basket_pos.x && pos.x <= g_gx_frogcandy_context.basket_pos.x + MMI_GX_FROGCANDY_BASKET_WIDTH &&
        pos.y >= g_gx_frogcandy_context.basket_pos.y && pos.y <= g_gx_frogcandy_context.basket_pos.y + MMI_GX_FROGCANDY_BASKET_HEIGHT)
    {
        g_gx_frogcandy_context.is_pen_hit = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_pen_up_hdlr
 * DESCRIPTION
 *  pen up event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //move basket to column
    if (g_gx_frogcandy_context.is_pen_hit && (g_gx_frogcandy_context.basket_pos.x % MMI_GX_FROGCANDY_OBJECT_WIDTH != 0))
    {
        for (i = 0; i < MMI_GX_FROGCANDY_MAX_COLUMN; i++)
        {
            if (g_gx_frogcandy_context.basket_pos.x-frogcandy_column[i] < MMI_GX_FROGCANDY_PEN_MOVE_COLUMN_THREADSHOLD)
            {
                g_gx_frogcandy_context.basket_pos.x = frogcandy_column[i];
                g_gx_frogcandy_context.basket_position = i;
                //mmi_gx_frogcandy_cyclic_timer();
                break;
            }
        }
    }
    g_gx_frogcandy_context.is_pen_hit = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_frogcandy_pen_move_hdlr
 * DESCRIPTION
 *  pen move event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_frogcandy_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_frogcandy_context.is_pen_hit)
    {
        g_gx_frogcandy_context.basket_pos.x = pos.x - MMI_GX_FROGCANDY_BASKET_WIDTH/2;
        if (g_gx_frogcandy_context.basket_pos.x < 0)
            g_gx_frogcandy_context.basket_pos.x = 0;
        else if (g_gx_frogcandy_context.basket_pos.x + MMI_GX_FROGCANDY_BASKET_WIDTH > MMI_GX_FROGCANDY_WINDOW_X2)
            g_gx_frogcandy_context.basket_pos.x = MMI_GX_FROGCANDY_WINDOW_X2 - MMI_GX_FROGCANDY_BASKET_WIDTH;
        
        //move basket to column
        if (g_gx_frogcandy_context.basket_pos.x % MMI_GX_FROGCANDY_OBJECT_WIDTH != 0)
        {
            for (i = 0; i < MMI_GX_FROGCANDY_MAX_COLUMN; i++)
            {
                if (g_gx_frogcandy_context.basket_pos.x-frogcandy_column[i] < MMI_GX_FROGCANDY_PEN_MOVE_COLUMN_THREADSHOLD)
                {
                    g_gx_frogcandy_context.basket_pos.x = frogcandy_column[i];
                    g_gx_frogcandy_context.basket_position = i;
                    break;
                }
            }
        }
        
        //mmi_gx_frogcandy_cyclic_timer();
    }
}

#endif  //__MMI_TOUCH_SCREEN__

#endif  //__MMI_GAME_FROGCANDY__ 

