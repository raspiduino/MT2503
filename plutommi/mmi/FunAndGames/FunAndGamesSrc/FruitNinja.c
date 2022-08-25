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
*  THE TRANSACTION CONFRUITD HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 * Filename:
 * ---------
 * FruitNinja.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  Game FruitNinja function.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 ****************************************************************************/

#include "mmi_features.h"

#include "GameDefs.h"

#ifdef __MMI_GAME_FRUITNINJA__
#include "GameInc.h"
#include "FruitNinjaProts.h"
#include "mmi_rp_app_games_def.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__      //added for multi-language
#include "GameProts.h"
#endif

/* gdi */
#include "lcd_sw_rnd.h"
/* gdi */

/*****************************************************************************
* Define
*****************************************************************************/

#ifdef __MMI_MAINLCD_176X220__
#define MMI_GX_FRUITNINJA_LCD_WIDTH (176)
#define MMI_GX_FRUITNINJA_LCD_HEIGHT (220)

#define TREASURE_WIDTH     (21)
#define TREASURE_HEIGHT    (21)
#define TREASUREBAR_POS_X  (150)
#define TREASUREBAR_POS_Y  (172)
#define TREASUREBAR_HEIGHT (5)
#define COMBOBAR_X (149)
#define COMBOBAR_Y (47)
#define SWORDWAVE_MARGIN_X (2)  /* make MARGIN_X/Y pixels overlap ,btw ninja and swd wave */
#define SWORDWAVE_MARGIN_Y (5)
#define SWORDWAVE_KICKMARGIN_X (2)
#define SWORDWAVE_KICKMARGIN_Y (25)
#define POWERBAR_POS_X     (157)
#define POWERBAR_POS_Y     (78)
#define POWERBAR_HEIGHT (76)
#define POWERBAR_WIDTH  (2)
#define MONSTER_POS_Y    (180)
#define MONSTER_HEIGHT    (35)
#define SWORDWAVE_HEIGHT      (30)
#define SWORDWAVE_KICKHEIGHT  (20)
#define ITEM_HEIGHT_VAL  {36,25,22,22}
#define ITEM_WIDTH_VAL   {24,19,31,23}
#define NINJA_HEIGHT  (53)
#define NINJA_WIDTH   (33)
#define NINJA_POS_Y   (118)
#define NINJA_ACTUAL_POS_Y_OFFSET (25)
#define WORKER_POS_Y (200)
#define WORKER_WIDTH (19)
#define MAINWINDOW_WIDTH   (132)
#define SCOREBAR_POS_X (138)
#define SCOREBAR_POS_Y (10)
#define MONSTER_POS_X_CNT (3)
#define MONSTER_POS_X_VAL {4, 64, 124}
#define ONTRACK_POS_X_CNT (3)
#define ONTRACK_POS_X_VAL {8, 68, 128}
#define ONTRACK_POS_Y_CNT (3)
#define ONTRACK_POS_Y_VAL {0, 0, 0}
#define SWORDWAVE_WIDTH_CNT (2)
#define SWORDWAVE_WIDTH_VAL {30, 60}
#define SWORDWAVE_KICKWIDTH_CNT (2)
#define SWORDWAVE_KICKWIDTH_VAL {30, 60}
#define NINJA_SPEED_CNT (3)
#define NINJA_SPEED_VAL {6, 7, 9}
#define ITEM_SPEED_CNT  (3)
#define ITEM_SPEED_VAL  {2, 3, 4}

/* charge time in frames for low~mid~max, kick need */
#define POWERBAR_LOW    (61)    /* mid cut:0-4-7, 3 for no bonus charge amount */
#define POWERBAR_KICKMID   (40) /* max cut:0-3-5, 2  after score powerbar-treasure */
#define POWERBAR_MAX    (POWERBAR_HEIGHT)


#elif defined(__MMI_MAINLCD_240X320__)
#define MMI_GX_FRUITNINJA_LCD_WIDTH (240)
#define MMI_GX_FRUITNINJA_LCD_HEIGHT (320)

#define TREASURE_WIDTH     (23)
#define TREASURE_HEIGHT    (25)
#define TREASUREBAR_POS_X  (206)
#define TREASUREBAR_POS_Y  (286)
#define TREASUREBAR_HEIGHT (4)
#define COMBOBAR_X (202)
#define COMBOBAR_Y (64)
#define SWORDWAVE_MARGIN_X (2)  /* make MARGIN_X/Y pixels overlap ,btw ninja and swd wave */
#define SWORDWAVE_MARGIN_Y (5)
#define SWORDWAVE_KICKMARGIN_X (2)
#define SWORDWAVE_KICKMARGIN_Y (25)
#define POWERBAR_POS_X     (217)
#define POWERBAR_POS_Y     (160)
#define POWERBAR_HEIGHT (106)
#define POWERBAR_WIDTH  (3)
#define MONSTER_POS_Y    (276)
#define MONSTER_HEIGHT    (39)
#define SWORDWAVE_HEIGHT      (40)
#define SWORDWAVE_KICKHEIGHT  (40)
#define ITEM_HEIGHT_VAL  {40,35,30,24}
#define ITEM_WIDTH_VAL   {28,27,39,27}
#define NINJA_HEIGHT  (65)
#define NINJA_WIDTH   (39)
#define NINJA_POS_Y   (196)
#define NINJA_ACTUAL_POS_Y_OFFSET (28)
#define WORKER_POS_Y (304)
#define WORKER_WIDTH (21)
#define MAINWINDOW_WIDTH   (180)
#define SCOREBAR_POS_X (184)
#define SCOREBAR_POS_Y (15)
#define MONSTER_POS_X_CNT (3)
#define MONSTER_POS_X_VAL {6, 80, 154}  
#define ONTRACK_POS_X_CNT (3)
#define ONTRACK_POS_X_VAL {12, 86, 160}
#define ONTRACK_POS_Y_CNT (3)
#define ONTRACK_POS_Y_VAL {0, 0, 0}
#define SWORDWAVE_WIDTH_CNT (2)
#define SWORDWAVE_WIDTH_VAL {40, 80}
#define SWORDWAVE_KICKWIDTH_CNT (2)
#define SWORDWAVE_KICKWIDTH_VAL {40, 80}
#define NINJA_SPEED_CNT (3)
#define NINJA_SPEED_VAL {7, 8, 10}
#define ITEM_SPEED_CNT  (3)
#define ITEM_SPEED_VAL  {3, 4, 5}

/* charge time in frames for low~mid~max, kick need */
#define POWERBAR_LOW    (61)    /* mid cut:0-4-7, 3 for no bonus charge amount */
#define POWERBAR_KICKMID   (40) /* max cut:0-3-5, 2  after score powerbar-treasure */
#define POWERBAR_MAX    (POWERBAR_HEIGHT)

#endif

#define MONSTER_NUM      (3)
#define ITEM_TYPE_CNT   (4)

#define DUALKNIFE_DURATION (300)        /* double attack length bonus duration */
#define DUALKICK_DURATION  (600)

#define BONUS_GRADE (500)       /* worker shows up every BONUS_GRADE score get,5000,10000,15000... */
#define TREASURE_COMBO (10)     /* generate treasure when combo num reach TREASURE_COMBO */

#define TREASURE_FALLSPEED (1)

#define TREASUREBAR_FRAME  (1)

#define NINJA_DELAY_CUT (3)      /* ninja delay frame number for different moves */
#define NINJA_DELAY_KICK (2)
#define NINJA_DELAY_HITHEAD_FRUIT (2)
#define NINJA_DELAY_HITHEAD_ROCK (10)
#define NINJA_DELAY_COUNTER_ROCK (5)     /* ninja delay when knife attack hit a rock */

#define WORKER_DELAY (20)       /* total frames worker fix a monster */

#define TIMEBLOCK (1800)        /* (3 min) per game become harder after per TIMEBLOCK period */
/* total 3 level for generate_time and max_showitem now */

#define ITEM_MAX     (10)       /* total item structure to make */
const U8 MAX_SHOWITEM[3] = {4, 7, 10};      /* max shown item at a time on scr */
const U8 GENERATE_TIME[3] = {15, 10, 8};    /* period system attempts to generate a item */

const U8 NINJA_MOVESPEED[NINJA_SPEED_CNT] = NINJA_SPEED_VAL; /* speeds up when get a speed-treasure */

const U8 MONSTER_POS_X[MONSTER_POS_X_CNT] = MONSTER_POS_X_VAL;
const U8 ONTRACK_POS_X[ONTRACK_POS_X_CNT] = ONTRACK_POS_X_VAL;
const U8 ONTRACK_POS_Y[ONTRACK_POS_Y_CNT] = ONTRACK_POS_Y_VAL;

const U8 SWORDWAVE_WIDTH[SWORDWAVE_WIDTH_CNT] = SWORDWAVE_WIDTH_VAL;
const U8 SWORDWAVE_KICKWIDTH[SWORDWAVE_KICKWIDTH_CNT] = SWORDWAVE_KICKWIDTH_VAL;

const U8 ITEM_WIDTH[ITEM_TYPE_CNT] = ITEM_WIDTH_VAL;
const U8 ITEM_HEIGHT[ITEM_TYPE_CNT] = ITEM_HEIGHT_VAL;

#define SCORE_2P (2)
#define SCORE_3P (6)
#define SCORE_MPLV0 (10)
#define SCORE_MPLV1 (13)
#define SCORE_MPLV2 (16)
#define SCORE_MPLV3 (20)

#define COMBO_LV1 (5)
#define COMBO_LV2 (10)
#define COMBO_LV3 (15)

const U8 ITEM_FALLSPEED[ITEM_SPEED_CNT] = ITEM_SPEED_VAL; /* freefall speed for easy,normal,hard */

#define ITEM_FALLCUT_SPEED (15) /* fall speed after fruit is cut */
#define HIT_MARGIN (5)  /* btw ninja and item only,considered collision iff overlap > HIT_MARGIN */

#define MONSTER_LIFE (10)        /* monster max life */
#define MONSTER_LIFEA (7)
#define MONSTER_LIFEB (4)

#define MONSTER_DAMAGE_ROCK (3)
#define MONSTER_DAMAGE_FRUIT (1)

#define NINJA_MOVESIDE_MARGIN (8)        /* max pixels ninja away from stage edge */

const U8 POWERBAR_UNIT[2] = {8, 10};

#define MMI_GX_FRUITNINJA_SCOREBARFRAME_COLOR     (gdi_act_color_from_rgb(255,167,155,10))
#define MMI_GX_FRUITNINJA_POWERBARFRAME_COLOR     (gdi_act_color_from_rgb(255,26,155,225))
#define MMI_GX_FRUITNINJA_INSIDEFRAME_COLOR       (gdi_act_color_from_rgb(255,202,136,136))
/*****************************************************************************
* Typedef
*****************************************************************************/

/* enum  */

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
//added for multi-language support
typedef enum
{
    MMI_FRUITNINJA_STRING_BACKGROUND,
    MMI_FRUITNINJA_STRING_TOTAL
}mmi_fruitninja_string_enum;
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

typedef enum
{
    ITEM_BASE,
    ITEM_FOODA,
    ITEM_FOODB,
    ITEM_FOODC,
    ITEM_ROCK
} gx_fruitninja_item_type_enum;

typedef enum
{
    ITEM_1P = 0,
    ITEM_2P,
    ITEM_3P,
    ITEM_MP
} gx_fruitninja_item_status_enum;

typedef enum
{
    ITEM_OFF = 0,
    ITEM_FALL,
    ITEM_CUT_FALL,
    ITEM_HIT_NINJA,
    ITEM_KICK_AWAY_LEFT,
    ITEM_KICK_AWAY_RIGHT
} gx_fruitninja_item_mission_enum;

typedef enum
{
    NINJA_IDLE = 0,  /* img_id of NINJA_BASE */
    NINJA_RIGHT_CUTPREP,
    NINJA_RIGHT_CUT,
    NINJA_RIGHT_KICKPREP,
    NINJA_RIGHT_KICK,

    NINJA_LEFT_CUTPREP,
    NINJA_LEFT_CUT,
    NINJA_LEFT_KICKPREP,
    NINJA_LEFT_KICK,

    NINJA_LEFT_WALK,
    NINJA_RIGHT_WALK,
    NINJA_FAINT,
    NINJA_GAMEOVER
} gx_fruitninja_ninja_status_enum;

typedef enum
{
    WORKER_OFF = 0,
    WORKER_STEP,
    WORKER_FIX
} gx_fruitninja_worker_status_enum;

typedef enum
{
    SKER_OFF = 0,
    SKER_OK,
    SKER_PBLVA,
    SKER_PBLVB,
    SKER_BROKEN
} gx_fruitninja_monster_status_enum;

typedef enum
{
    SWORDWAVE_OFF = 0,
    SWORDWAVE_LOW,
    SWORDWAVE_MID,
    SWORDWAVE_MAX,
    SWORDWAVE_KICK
} gx_fruitninja_swordwave_status_enum;

typedef enum
{
    KEY_LEFT = 0,
    KEY_RIGHT,
    KEY_UP,
    KEY_DOWN,
    KEY_OFF
} gx_fruitninja_keyhandler_enum;

typedef enum
{
    TREASURE_OFF = 0,
    TREASURE_KNIFE,
    TREASURE_KICK,
    TREASURE_ALLCUT,
    TREASURE_SPEED,
    TREASURE_POWER
} gx_fruitninja_treasure_type_enum;

/* basic game variable struct */
typedef struct
{
    BOOL is_gameover;
    BOOL is_new_game;
    U8 game_level;
    S16 game_grade;
    S16 timer_elapse;

    gdi_handle background;
    gdi_handle foreground;


} gx_fruitninja_context_struct;

typedef struct
{
    gx_fruitninja_item_type_enum type;       /* item type (fruit,rock) */
    gx_fruitninja_item_status_enum piece;    /* current piece */
    gx_fruitninja_item_mission_enum mission; /* current status */
    U8 column;
    S16 x;
    S16 y;
    U8 tick;                            /* for multi-frame moves */

} gx_fruitninja_item_struct;

typedef struct
{
    gx_fruitninja_ninja_status_enum status;
    S16 x;
    S16 y;
    U8 speed;
    U8 delay;
    BOOL is_left;
    BOOL just_turn;
} gx_fruitninja_ninja_struct;

typedef struct
{
    gx_fruitninja_worker_status_enum status;
    S16 x;
    S16 y;
    U8 delay;
} gx_fruitninja_worker_struct;

typedef struct
{
    gx_fruitninja_swordwave_status_enum status;
    U8 step;
    S16 x;
    S16 y;
    U8 width;
    U8 kickwidth;
    BOOL knifedouble;
    BOOL kickdouble;
    BOOL is_left;
} gx_fruitninja_swordwave_struct;

typedef struct
{
    gx_fruitninja_treasure_type_enum type;
    S16 x;
    S16 y;
    U16 kickleft;
    U16 knifeleft;
    U8 nextcombo;
} gx_fruitninja_treasure_struct;

/*****************************************************************************
* Local Function
*****************************************************************************/
/* Game framework related functions */
S16 mmi_gx_fruitninja_calc_best_grade(S16 old_grade, S16 new_grade); /* descide which is best grade */
void mmi_gx_fruitninja_enter_game(void);     /* entry function of the game */
void mmi_gx_fruitninja_exit_game(void);      /* exit function - usually will stop timer and release buffer */
void mmi_gx_fruitninja_draw_gameover(void);  /* draw gameover screen */
void mmi_gx_fruitninja_gameover(void);
void mmi_gx_fruitninja_cyclic_timer(void);
void mmi_gx_fruitninja_init_game(void);

void mmi_gx_fruitninja_framemove(void);
void mmi_gx_fruitninja_framemove_ninja(void);
void mmi_gx_fruitninja_framemove_item(void);
void mmi_gx_fruitninja_framemove_worker(void);
void mmi_gx_fruitninja_framemove_swordwave(void);
void mmi_gx_fruitninja_framemove_monster(void);
void mmi_gx_fruitninja_framemove_treasure(void);
void mmi_gx_fruitninja_render(void);
void mmi_gx_fruitninja_render_ninja(void);
void mmi_gx_fruitninja_render_item(S16 i);
void mmi_gx_fruitninja_render_swordwave(S16 x);
void mmi_gx_fruitninja_render_worker(void);
void mmi_gx_fruitninja_render_powerbar(void);
void mmi_gx_fruitninja_render_monster(void);
void mmi_gx_fruitninja_render_generalframe(void);
void mmi_gx_fruitninja_render_combo(void);
void mmi_gx_fruitninja_render_treasurebar(void);
void mmi_gx_fruitninja_render_treasure(void);

/* Game play functions */
void mmi_gx_fruitninja_generate_item(void);
void mmi_gx_fruitninja_draw_digits(S16, S16, U16, U16);
void mmi_gx_fruitninja_powerbar_charge(void);
void mmi_gx_fruitninja_item_check(S16);
void mmi_gx_fruitninja_notescore(S16);
BOOL mmi_gx_fruitninja_collision(
    S16 a_x,
    S16 a_y,
    U8 a_width,
    U8 a_height,
    S16 b_x,
    S16 b_y,
    U8 b_width,
    U8 b_height,
    U8 x_margin,
    U8 y_margin);

void mmi_gx_fruitninja_bgm_play(void);

/* key functions */
void mmi_gx_fruitninja_key_left_press(void);
void mmi_gx_fruitninja_key_right_press(void);
void mmi_gx_fruitninja_key_left_release(void);
void mmi_gx_fruitninja_key_right_release(void);
void mmi_gx_fruitninja_key_up_press(void);
void mmi_gx_fruitninja_key_down_press(void);
void mmi_gx_fruitninja_key_up_release(void);
void mmi_gx_fruitninja_key_down_release(void);

void mmi_gx_fruitninja_key_1_press(void);
void mmi_gx_fruitninja_key_3_press(void);
void mmi_gx_fruitninja_key_1_release(void);
void mmi_gx_fruitninja_key_3_release(void);
void mmi_gx_fruitninja_key_7_press(void);
void mmi_gx_fruitninja_key_9_press(void);
void mmi_gx_fruitninja_key_7_release(void);
void mmi_gx_fruitninja_key_9_release(void);

/* key functions */

/************************************************************************/
/* Audio [Const]                                         */
/************************************************************************/
#define FRUITNINJA_BACKGROUND_MUSIC_MID  (3114)

__align(2)
const unsigned char fruitninja_background_music_mid[3114] =
{
    0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54,
    0x72, 0x6B, 0x00, 0x00, 0x0C, 0x14, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69,
    0x67, 0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x34, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43,
    0x00, 0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x06, 0x03, 0x0C, 0x08, 0x00, 0xFF,
    0x59, 0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x06, 0x8A, 0x1B, 0x00, 0xC0, 0x72, 0x00, 0xB0,
    0x07, 0x7C, 0x00, 0x5B, 0x01, 0x00, 0x90, 0x54, 0x64, 0x00, 0xC1, 0x38, 0x00, 0xB1, 0x07, 0x50,
    0x00, 0xC2, 0x50, 0x00, 0xB2, 0x07, 0x70, 0x00, 0x92, 0x48, 0x64, 0x00, 0xC3, 0x6C, 0x00, 0xB3,
    0x07, 0x3A, 0x00, 0xC4, 0x3D, 0x00, 0xB4, 0x07, 0x5A, 0x00, 0x94, 0x3C, 0x6F, 0x0F, 0x91, 0x48,
    0x64, 0x81, 0x61, 0x90, 0x54, 0x00, 0x00, 0x53, 0x64, 0x0F, 0x91, 0x48, 0x00, 0x00, 0x47, 0x64,
    0x81, 0x61, 0x92, 0x48, 0x00, 0x00, 0x90, 0x53, 0x00, 0x00, 0x54, 0x64, 0x00, 0x93, 0x48, 0x78,
    0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x47, 0x00, 0x00, 0x48, 0x64, 0x69, 0x93, 0x43,
    0x00, 0x00, 0x48, 0x00, 0x00, 0x40, 0x00, 0x78, 0x90, 0x54, 0x00, 0x00, 0x56, 0x64, 0x0F, 0x91,
    0x48, 0x00, 0x00, 0x4A, 0x64, 0x81, 0x61, 0x90, 0x56, 0x00, 0x00, 0x58, 0x64, 0x00, 0x93, 0x48,
    0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x69, 0x93,
    0x43, 0x00, 0x00, 0x48, 0x00, 0x00, 0x40, 0x00, 0x78, 0x90, 0x58, 0x00, 0x00, 0x59, 0x64, 0x0F,
    0x91, 0x4C, 0x00, 0x00, 0x4D, 0x64, 0x69, 0x94, 0x3C, 0x00, 0x78, 0x90, 0x59, 0x00, 0x00, 0x5B,
    0x64, 0x00, 0x92, 0x43, 0x64, 0x00, 0x94, 0x3C, 0x6F, 0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4F, 0x64,
    0x81, 0x61, 0x90, 0x5B, 0x00, 0x00, 0x5A, 0x64, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x4E, 0x64, 0x81,
    0x61, 0x90, 0x5A, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x5B, 0x64, 0x00, 0x93, 0x48, 0x78,
    0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x4E, 0x00, 0x00, 0x4F, 0x64, 0x69, 0x93, 0x43,
    0x00, 0x00, 0x48, 0x00, 0x00, 0x40, 0x00, 0x78, 0x90, 0x5B, 0x00, 0x00, 0x5D, 0x64, 0x00, 0x93,
    0x48, 0x78, 0x00, 0x40, 0x78, 0x00, 0x43, 0x78, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x51, 0x64, 0x69,
    0x93, 0x40, 0x00, 0x00, 0x48, 0x00, 0x00, 0x43, 0x00, 0x78, 0x90, 0x5D, 0x00, 0x00, 0x5B, 0x64,
    0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x51, 0x00, 0x00, 0x4F,
    0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x40, 0x00, 0x78, 0x48, 0x00, 0x00, 0x90, 0x5B, 0x00, 0x00,
    0x58, 0x64, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x4C, 0x64, 0x69, 0x94, 0x3C, 0x00, 0x78, 0x90, 0x58,
    0x00, 0x00, 0x59, 0x64, 0x00, 0x92, 0x47, 0x64, 0x00, 0x94, 0x43, 0x6F, 0x0F, 0x91, 0x4C, 0x00,
    0x00, 0x4D, 0x64, 0x81, 0x61, 0x90, 0x59, 0x00, 0x0F, 0x91, 0x4D, 0x00, 0x81, 0x61, 0x92, 0x47,
    0x00, 0x00, 0x90, 0x58, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x0F,
    0x91, 0x4C, 0x64, 0x69, 0x93, 0x3E, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x78, 0x90, 0x58,
    0x00, 0x0F, 0x91, 0x4C, 0x00, 0x81, 0x61, 0x90, 0x56, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x3E,
    0x78, 0x00, 0x43, 0x78, 0x0F, 0x91, 0x4A, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x3E, 0x00, 0x00,
    0x47, 0x00, 0x78, 0x90, 0x56, 0x00, 0x0F, 0x91, 0x4A, 0x00, 0x69, 0x94, 0x43, 0x00, 0x78, 0x92,
    0x43, 0x64, 0x00, 0x94, 0x37, 0x6F, 0x83, 0x60, 0x92, 0x43, 0x00, 0x00, 0x93, 0x47, 0x78, 0x00,
    0x43, 0x78, 0x00, 0x3E, 0x78, 0x78, 0x3E, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x78, 0x47,
    0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x78, 0x3E, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00,
    0x78, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x78, 0x3E, 0x00, 0x00, 0x43, 0x00, 0x00,
    0x47, 0x00, 0x78, 0x90, 0x4F, 0x64, 0x0F, 0x91, 0x43, 0x64, 0x69, 0x94, 0x37, 0x00, 0x78, 0x90,
    0x4F, 0x00, 0x00, 0x53, 0x64, 0x00, 0x92, 0x47, 0x64, 0x00, 0x94, 0x43, 0x6F, 0x0F, 0x91, 0x43,
    0x00, 0x00, 0x47, 0x64, 0x81, 0x61, 0x90, 0x53, 0x00, 0x00, 0x52, 0x64, 0x0F, 0x91, 0x47, 0x00,
    0x00, 0x46, 0x64, 0x81, 0x61, 0x90, 0x52, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x90, 0x53, 0x64,
    0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x0F, 0x91, 0x46, 0x00, 0x00, 0x47,
    0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x3E, 0x00, 0x78, 0x90, 0x53, 0x00, 0x00,
    0x54, 0x64, 0x0F, 0x91, 0x47, 0x00, 0x00, 0x48, 0x64, 0x81, 0x61, 0x90, 0x54, 0x00, 0x00, 0x56,
    0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x0F, 0x91, 0x48, 0x00, 0x00,
    0x4A, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x3E, 0x00, 0x78, 0x90, 0x56, 0x00,
    0x00, 0x58, 0x64, 0x0F, 0x91, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x69, 0x94, 0x43, 0x00, 0x78, 0x90,
    0x58, 0x00, 0x00, 0x59, 0x64, 0x00, 0x92, 0x43, 0x64, 0x00, 0x94, 0x37, 0x6F, 0x0F, 0x91, 0x4C,
    0x00, 0x00, 0x4D, 0x64, 0x81, 0x61, 0x90, 0x59, 0x00, 0x00, 0x58, 0x64, 0x0F, 0x91, 0x4D, 0x00,
    0x00, 0x4C, 0x64, 0x81, 0x61, 0x90, 0x58, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x59, 0x64,
    0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x0F, 0x91, 0x4C, 0x00, 0x00, 0x4D,
    0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x3E, 0x00, 0x78, 0x90, 0x59, 0x00, 0x00,
    0x5B, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x0F, 0x91, 0x4D, 0x00,
    0x00, 0x4F, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x3E, 0x00, 0x78, 0x90, 0x5B,
    0x00, 0x00, 0x59, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x3E, 0x78, 0x00, 0x43, 0x78, 0x0F, 0x91,
    0x4F, 0x00, 0x00, 0x4D, 0x64, 0x69, 0x93, 0x3E, 0x00, 0x00, 0x47, 0x00, 0x00, 0x43, 0x00, 0x78,
    0x90, 0x59, 0x00, 0x00, 0x56, 0x64, 0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4A, 0x64, 0x69, 0x94, 0x37,
    0x00, 0x78, 0x90, 0x56, 0x00, 0x00, 0x58, 0x64, 0x00, 0x92, 0x48, 0x64, 0x00, 0x94, 0x3C, 0x6F,
    0x0F, 0x91, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x81, 0x61, 0x90, 0x58, 0x00, 0x0F, 0x91, 0x4C, 0x00,
    0x81, 0x61, 0x92, 0x48, 0x00, 0x00, 0x90, 0x56, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78,
    0x00, 0x40, 0x78, 0x0F, 0x91, 0x4A, 0x64, 0x69, 0x93, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x48,
    0x00, 0x78, 0x90, 0x56, 0x00, 0x0F, 0x91, 0x4A, 0x00, 0x81, 0x61, 0x90, 0x54, 0x64, 0x00, 0x93,
    0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x48, 0x64, 0x69, 0x93, 0x40, 0x00,
    0x00, 0x43, 0x00, 0x00, 0x48, 0x00, 0x78, 0x90, 0x54, 0x00, 0x0F, 0x91, 0x48, 0x00, 0x69, 0x94,
    0x3C, 0x00, 0x78, 0x92, 0x43, 0x64, 0x00, 0x94, 0x3C, 0x6F, 0x83, 0x60, 0x92, 0x43, 0x00, 0x00,
    0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x78, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00,
    0x48, 0x00, 0x78, 0x48, 0x78, 0x00, 0x40, 0x78, 0x00, 0x43, 0x78, 0x78, 0x43, 0x00, 0x00, 0x40,
    0x00, 0x00, 0x48, 0x00, 0x78, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x78, 0x40, 0x00,
    0x00, 0x43, 0x00, 0x78, 0x48, 0x00, 0x00, 0x90, 0x4F, 0x64, 0x0F, 0x91, 0x43, 0x64, 0x69, 0x94,
    0x3C, 0x00, 0x78, 0x90, 0x4F, 0x00, 0x00, 0x54, 0x64, 0x00, 0x92, 0x48, 0x64, 0x00, 0x94, 0x3C,
    0x6F, 0x0F, 0x91, 0x43, 0x00, 0x00, 0x48, 0x64, 0x81, 0x61, 0x90, 0x54, 0x00, 0x00, 0x53, 0x64,
    0x0F, 0x91, 0x48, 0x00, 0x00, 0x47, 0x64, 0x81, 0x61, 0x90, 0x53, 0x00, 0x00, 0x92, 0x48, 0x00,
    0x00, 0x90, 0x54, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x40, 0x78, 0x00, 0x43, 0x78, 0x0F, 0x91,
    0x47, 0x00, 0x00, 0x48, 0x64, 0x69, 0x93, 0x40, 0x00, 0x00, 0x48, 0x00, 0x00, 0x43, 0x00, 0x78,
    0x90, 0x54, 0x00, 0x00, 0x56, 0x64, 0x0F, 0x91, 0x48, 0x00, 0x00, 0x4A, 0x64, 0x81, 0x61, 0x90,
    0x56, 0x00, 0x00, 0x58, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F,
    0x91, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x48, 0x00, 0x00, 0x40, 0x00,
    0x78, 0x90, 0x58, 0x00, 0x00, 0x59, 0x64, 0x0F, 0x91, 0x4C, 0x00, 0x00, 0x4D, 0x64, 0x69, 0x94,
    0x3C, 0x00, 0x78, 0x90, 0x59, 0x00, 0x00, 0x5B, 0x64, 0x00, 0x92, 0x43, 0x64, 0x00, 0x94, 0x3C,
    0x6F, 0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4F, 0x64, 0x81, 0x61, 0x90, 0x5B, 0x00, 0x00, 0x5A, 0x64,
    0x0F, 0x91, 0x4F, 0x00, 0x00, 0x4E, 0x64, 0x81, 0x61, 0x90, 0x5A, 0x00, 0x00, 0x92, 0x43, 0x00,
    0x00, 0x90, 0x5B, 0x64, 0x00, 0x93, 0x40, 0x78, 0x00, 0x48, 0x78, 0x00, 0x43, 0x78, 0x0F, 0x91,
    0x4E, 0x00, 0x00, 0x4F, 0x64, 0x69, 0x93, 0x48, 0x00, 0x00, 0x40, 0x00, 0x00, 0x43, 0x00, 0x78,
    0x90, 0x5B, 0x00, 0x00, 0x5D, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x40, 0x78, 0x00, 0x43, 0x78,
    0x0F, 0x91, 0x4F, 0x00, 0x00, 0x51, 0x64, 0x69, 0x93, 0x40, 0x00, 0x00, 0x48, 0x00, 0x00, 0x43,
    0x00, 0x78, 0x90, 0x5D, 0x00, 0x00, 0x5B, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x40, 0x78, 0x00,
    0x43, 0x78, 0x0F, 0x91, 0x51, 0x00, 0x00, 0x4F, 0x64, 0x69, 0x93, 0x40, 0x00, 0x00, 0x48, 0x00,
    0x00, 0x43, 0x00, 0x78, 0x90, 0x5B, 0x00, 0x00, 0x58, 0x64, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x4C,
    0x64, 0x69, 0x94, 0x3C, 0x00, 0x78, 0x90, 0x58, 0x00, 0x00, 0x59, 0x64, 0x00, 0x92, 0x47, 0x64,
    0x00, 0x94, 0x43, 0x6F, 0x0F, 0x91, 0x4C, 0x00, 0x00, 0x4D, 0x64, 0x81, 0x61, 0x90, 0x59, 0x00,
    0x0F, 0x91, 0x4D, 0x00, 0x81, 0x61, 0x92, 0x47, 0x00, 0x00, 0x90, 0x58, 0x64, 0x00, 0x93, 0x47,
    0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x0F, 0x91, 0x4C, 0x64, 0x69, 0x93, 0x3E, 0x00, 0x00,
    0x43, 0x00, 0x00, 0x47, 0x00, 0x78, 0x90, 0x58, 0x00, 0x0F, 0x91, 0x4C, 0x00, 0x81, 0x61, 0x90,
    0x56, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x0F, 0x91, 0x4A, 0x64,
    0x69, 0x93, 0x3E, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x78, 0x90, 0x56, 0x00, 0x0F, 0x91,
    0x4A, 0x00, 0x69, 0x94, 0x43, 0x00, 0x78, 0x92, 0x43, 0x64, 0x00, 0x94, 0x37, 0x6F, 0x83, 0x60,
    0x92, 0x43, 0x00, 0x00, 0x93, 0x47, 0x78, 0x00, 0x3E, 0x78, 0x00, 0x43, 0x78, 0x78, 0x43, 0x00,
         0x00, 0x3E, 0x00, 0x00, 0x47, 0x00, 0x78, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x78,
         0x3E, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x78, 0x47, 0x78, 0x00, 0x3E, 0x78, 0x00, 0x43,
         0x78, 0x78, 0x43, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x47, 0x00, 0x78, 0x90, 0x4F, 0x64, 0x0F, 0x91,
         0x43, 0x64, 0x69, 0x94, 0x37, 0x00, 0x78, 0x90, 0x4F, 0x00, 0x00, 0x53, 0x64, 0x00, 0x92, 0x47,
         0x64, 0x00, 0x94, 0x43, 0x6F, 0x0F, 0x91, 0x43, 0x00, 0x00, 0x47, 0x64, 0x81, 0x61, 0x90, 0x53,
         0x00, 0x00, 0x52, 0x64, 0x0F, 0x91, 0x47, 0x00, 0x00, 0x46, 0x64, 0x81, 0x61, 0x90, 0x52, 0x00,
         0x00, 0x92, 0x47, 0x00, 0x00, 0x90, 0x53, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00,
         0x3E, 0x78, 0x0F, 0x91, 0x46, 0x00, 0x00, 0x47, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00,
         0x00, 0x3E, 0x00, 0x78, 0x90, 0x53, 0x00, 0x00, 0x54, 0x64, 0x0F, 0x91, 0x47, 0x00, 0x00, 0x48,
         0x64, 0x81, 0x61, 0x90, 0x54, 0x00, 0x00, 0x56, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78,
         0x00, 0x3E, 0x78, 0x0F, 0x91, 0x48, 0x00, 0x00, 0x4A, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47,
         0x00, 0x00, 0x3E, 0x00, 0x78, 0x90, 0x56, 0x00, 0x00, 0x58, 0x64, 0x0F, 0x91, 0x4A, 0x00, 0x00,
         0x4C, 0x64, 0x69, 0x94, 0x43, 0x00, 0x78, 0x90, 0x58, 0x00, 0x00, 0x59, 0x64, 0x00, 0x92, 0x43,
         0x64, 0x00, 0x94, 0x37, 0x6F, 0x0F, 0x91, 0x4C, 0x00, 0x00, 0x4D, 0x64, 0x81, 0x61, 0x90, 0x59,
         0x00, 0x00, 0x58, 0x64, 0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4C, 0x64, 0x81, 0x61, 0x90, 0x58, 0x00,
         0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x59, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00,
         0x3E, 0x78, 0x0F, 0x91, 0x4C, 0x00, 0x00, 0x4D, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00,
         0x00, 0x3E, 0x00, 0x78, 0x90, 0x59, 0x00, 0x00, 0x5B, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43,
         0x78, 0x00, 0x3E, 0x78, 0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4F, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00,
         0x47, 0x00, 0x00, 0x3E, 0x00, 0x78, 0x90, 0x5B, 0x00, 0x00, 0x59, 0x64, 0x00, 0x93, 0x47, 0x78,
         0x00, 0x43, 0x78, 0x00, 0x3E, 0x78, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x4D, 0x64, 0x69, 0x93, 0x43,
         0x00, 0x00, 0x47, 0x00, 0x00, 0x3E, 0x00, 0x78, 0x90, 0x59, 0x00, 0x00, 0x56, 0x64, 0x0F, 0x91,
         0x4D, 0x00, 0x00, 0x4A, 0x64, 0x69, 0x94, 0x37, 0x00, 0x78, 0x90, 0x56, 0x00, 0x00, 0x58, 0x64,
         0x00, 0x92, 0x48, 0x64, 0x00, 0x94, 0x3C, 0x6F, 0x0F, 0x91, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x81,
         0x61, 0x90, 0x58, 0x00, 0x0F, 0x91, 0x4C, 0x00, 0x81, 0x61, 0x92, 0x48, 0x00, 0x00, 0x90, 0x56,
         0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x4A, 0x64, 0x69,
         0x93, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x48, 0x00, 0x78, 0x90, 0x56, 0x00, 0x0F, 0x91, 0x4A,
         0x00, 0x81, 0x61, 0x90, 0x54, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78,
         0x0F, 0x91, 0x48, 0x64, 0x69, 0x93, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x48, 0x00, 0x78, 0x90,
         0x54, 0x00, 0x0F, 0x91, 0x48, 0x00, 0x69, 0x94, 0x3C, 0x00, 0x78, 0x92, 0x43, 0x64, 0x00, 0x94,
         0x3C, 0x6F, 0x83, 0x60, 0x92, 0x43, 0x00, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40,
         0x78, 0x78, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x48, 0x00, 0x78, 0x48, 0x78, 0x00, 0x43, 0x78,
         0x00, 0x40, 0x78, 0x78, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x48, 0x00, 0x78, 0x90, 0x58, 0x64,
         0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x4C, 0x64, 0x69, 0x93,
         0x40, 0x00, 0x00, 0x43, 0x00, 0x78, 0x48, 0x00, 0x00, 0x90, 0x58, 0x00, 0x0F, 0x91, 0x4C, 0x00,
         0x69, 0x94, 0x3C, 0x00, 0x78, 0x90, 0x59, 0x64, 0x00, 0x92, 0x45, 0x64, 0x00, 0x94, 0x41, 0x6F,
         0x0F, 0x91, 0x4D, 0x64, 0x81, 0x61, 0x90, 0x59, 0x00, 0x00, 0x58, 0x64, 0x0F, 0x91, 0x4D, 0x00,
         0x00, 0x4C, 0x64, 0x81, 0x61, 0x92, 0x45, 0x00, 0x00, 0x90, 0x58, 0x00, 0x00, 0x59, 0x64, 0x00,
         0x93, 0x48, 0x78, 0x00, 0x45, 0x78, 0x00, 0x41, 0x78, 0x0F, 0x91, 0x4C, 0x00, 0x00, 0x4D, 0x64,
         0x69, 0x93, 0x45, 0x00, 0x00, 0x48, 0x00, 0x00, 0x41, 0x00, 0x78, 0x90, 0x59, 0x00, 0x00, 0x5B,
         0x64, 0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4F, 0x64, 0x81, 0x61, 0x90, 0x5B, 0x00, 0x00, 0x5D, 0x64,
         0x00, 0x93, 0x48, 0x78, 0x00, 0x45, 0x78, 0x00, 0x41, 0x78, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x51,
         0x64, 0x69, 0x93, 0x45, 0x00, 0x00, 0x48, 0x00, 0x00, 0x41, 0x00, 0x78, 0x90, 0x5D, 0x00, 0x00,
         0x59, 0x64, 0x0F, 0x91, 0x51, 0x00, 0x00, 0x4D, 0x64, 0x69, 0x94, 0x41, 0x00, 0x78, 0x90, 0x59,
         0x00, 0x00, 0x54, 0x64, 0x00, 0x92, 0x41, 0x64, 0x00, 0x94, 0x39, 0x6F, 0x0F, 0x91, 0x4D, 0x00,
         0x00, 0x48, 0x64, 0x81, 0x61, 0x90, 0x54, 0x00, 0x0F, 0x91, 0x48, 0x00, 0x81, 0x61, 0x92, 0x41,
         0x00, 0x00, 0x93, 0x48, 0x78, 0x00, 0x45, 0x78, 0x00, 0x41, 0x78, 0x78, 0x41, 0x00, 0x00, 0x45,
         0x00, 0x00, 0x48, 0x00, 0x82, 0x68, 0x90, 0x5D, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x45, 0x78,
         0x00, 0x41, 0x78, 0x0F, 0x91, 0x51, 0x64, 0x69, 0x93, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x48,
         0x00, 0x78, 0x90, 0x5D, 0x00, 0x0F, 0x91, 0x51, 0x00, 0x69, 0x94, 0x39, 0x00, 0x78, 0x90, 0x5B,
         0x64, 0x00, 0x92, 0x40, 0x64, 0x00, 0x94, 0x3C, 0x6F, 0x0F, 0x91, 0x4F, 0x64, 0x81, 0x61, 0x90,
         0x5B, 0x00, 0x00, 0x5A, 0x64, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x4E, 0x64, 0x81, 0x61, 0x92, 0x40,
         0x00, 0x00, 0x90, 0x5A, 0x00, 0x00, 0x5B, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00,
         0x40, 0x78, 0x0F, 0x91, 0x4E, 0x00, 0x00, 0x4F, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x48, 0x00,
         0x00, 0x40, 0x00, 0x78, 0x90, 0x5B, 0x00, 0x00, 0x59, 0x64, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x4D,
         0x64, 0x81, 0x61, 0x90, 0x59, 0x00, 0x00, 0x58, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78,
         0x00, 0x40, 0x78, 0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4C, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x48,
         0x00, 0x00, 0x40, 0x00, 0x78, 0x90, 0x58, 0x00, 0x00, 0x57, 0x64, 0x0F, 0x91, 0x4C, 0x00, 0x00,
         0x4B, 0x64, 0x69, 0x94, 0x3C, 0x00, 0x78, 0x90, 0x57, 0x00, 0x00, 0x58, 0x64, 0x00, 0x92, 0x48,
         0x64, 0x00, 0x94, 0x37, 0x6F, 0x0F, 0x91, 0x4B, 0x00, 0x00, 0x4C, 0x64, 0x81, 0x61, 0x90, 0x58,
         0x00, 0x0F, 0x91, 0x4C, 0x00, 0x81, 0x61, 0x92, 0x48, 0x00, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43,
         0x78, 0x00, 0x40, 0x78, 0x78, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x48, 0x00, 0x82, 0x68, 0x90,
         0x54, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x48, 0x64,
         0x69, 0x93, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x48, 0x00, 0x78, 0x90, 0x54, 0x00, 0x0F, 0x91,
         0x48, 0x00, 0x69, 0x94, 0x37, 0x00, 0x78, 0x90, 0x56, 0x64, 0x00, 0x92, 0x41, 0x64, 0x00, 0x94,
         0x3B, 0x6F, 0x0F, 0x91, 0x4A, 0x64, 0x81, 0x61, 0x90, 0x56, 0x00, 0x00, 0x55, 0x64, 0x0F, 0x91,
         0x4A, 0x00, 0x00, 0x49, 0x64, 0x81, 0x61, 0x92, 0x41, 0x00, 0x00, 0x90, 0x55, 0x00, 0x00, 0x56,
         0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x41, 0x78, 0x0F, 0x91, 0x49, 0x00, 0x00,
         0x4A, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x41, 0x00, 0x78, 0x90, 0x56, 0x00,
         0x00, 0x58, 0x64, 0x0F, 0x91, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x81, 0x61, 0x90, 0x58, 0x00, 0x00,
         0x59, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x41, 0x78, 0x0F, 0x91, 0x4C, 0x00,
         0x00, 0x4D, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x41, 0x00, 0x78, 0x90, 0x59,
         0x00, 0x00, 0x56, 0x64, 0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4A, 0x64, 0x69, 0x94, 0x3B, 0x00, 0x78,
         0x90, 0x56, 0x00, 0x00, 0x53, 0x64, 0x00, 0x92, 0x43, 0x64, 0x00, 0x94, 0x3E, 0x6F, 0x0F, 0x91,
         0x4A, 0x00, 0x00, 0x47, 0x64, 0x81, 0x61, 0x90, 0x53, 0x00, 0x00, 0x52, 0x64, 0x0F, 0x91, 0x47,
         0x00, 0x00, 0x46, 0x64, 0x81, 0x61, 0x90, 0x52, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x53,
         0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x41, 0x78, 0x00, 0x43, 0x78, 0x0F, 0x91, 0x46, 0x00, 0x00,
         0x47, 0x64, 0x69, 0x93, 0x41, 0x00, 0x00, 0x47, 0x00, 0x00, 0x43, 0x00, 0x78, 0x90, 0x53, 0x00,
         0x00, 0x54, 0x64, 0x0F, 0x91, 0x47, 0x00, 0x00, 0x48, 0x64, 0x81, 0x61, 0x90, 0x54, 0x00, 0x00,
         0x56, 0x64, 0x00, 0x93, 0x47, 0x78, 0x00, 0x43, 0x78, 0x00, 0x41, 0x78, 0x0F, 0x91, 0x48, 0x00,
         0x00, 0x4A, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x41, 0x00, 0x78, 0x90, 0x56,
         0x00, 0x00, 0x59, 0x64, 0x0F, 0x91, 0x4A, 0x00, 0x00, 0x4D, 0x64, 0x69, 0x94, 0x3E, 0x00, 0x78,
         0x90, 0x59, 0x00, 0x00, 0x58, 0x64, 0x00, 0x92, 0x48, 0x64, 0x00, 0x94, 0x3C, 0x6F, 0x0F, 0x91,
         0x4D, 0x00, 0x00, 0x4C, 0x64, 0x81, 0x61, 0x90, 0x58, 0x00, 0x00, 0x57, 0x64, 0x0F, 0x91, 0x4C,
         0x00, 0x00, 0x4B, 0x64, 0x81, 0x61, 0x90, 0x57, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x90, 0x58,
         0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x0F, 0x91, 0x4B, 0x00, 0x00,
         0x4C, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x48, 0x00, 0x00, 0x40, 0x00, 0x78, 0x90, 0x58, 0x00,
         0x00, 0x59, 0x64, 0x0F, 0x91, 0x4C, 0x00, 0x00, 0x4D, 0x64, 0x81, 0x61, 0x90, 0x59, 0x00, 0x00,
         0x5B, 0x64, 0x00, 0x92, 0x40, 0x64, 0x00, 0x93, 0x48, 0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x78,
         0x0F, 0x91, 0x4D, 0x00, 0x00, 0x4F, 0x64, 0x69, 0x93, 0x43, 0x00, 0x00, 0x48, 0x00, 0x00, 0x40,
         0x00, 0x78, 0x90, 0x5B, 0x00, 0x00, 0x5A, 0x64, 0x0F, 0x91, 0x4F, 0x00, 0x00, 0x4E, 0x64, 0x69,
         0x94, 0x3C, 0x00, 0x78, 0x90, 0x5A, 0x00, 0x00, 0x92, 0x40, 0x00, 0x00, 0x90, 0x5B, 0x64, 0x00,
         0x92, 0x43, 0x64, 0x00, 0x94, 0x3C, 0x6F, 0x0F, 0x91, 0x4E, 0x00, 0x00, 0x4F, 0x64, 0x81, 0x61,
         0x90, 0x5B, 0x00, 0x0F, 0x91, 0x4F, 0x00, 0x81, 0x61, 0x92, 0x43, 0x00, 0x00, 0x93, 0x48, 0x78,
         0x00, 0x43, 0x78, 0x00, 0x40, 0x78, 0x78, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x48, 0x00, 0x82,
         0x68, 0x48, 0x78, 0x00, 0x40, 0x78, 0x00, 0x43, 0x78, 0x78, 0x43, 0x00, 0x00, 0x40, 0x00, 0x00,
         0x48, 0x00, 0x78, 0x90, 0x4F, 0x64, 0x0F, 0x91, 0x43, 0x64, 0x69, 0x94, 0x3C, 0x00, 0x78, 0x90,
         0x4F, 0x00, 0x0F, 0x91, 0x43, 0x00, 0x00, 0xFF, 0x2F, 0x00
};

/*****************************************************************************
* Local Variable
*****************************************************************************/

gx_fruitninja_context_struct g_gx_fruitninja_context =
{
    FALSE,  /* is_gameover */
    TRUE,   /* is_new_game */
    0,      /* game_level */
    0,      /* game_grade */
    150      /* timer_elapse */
};

/* gameplay */

/* structure for item,monster,swordwave,ninja,worker,pwrbar */

gx_fruitninja_item_struct gx_fruitninja_item[ITEM_MAX];

gx_fruitninja_monster_status_enum gx_fruitninja_monster_status[MONSTER_NUM];
gx_fruitninja_ninja_struct gx_fruitninja_ninja;
gx_fruitninja_worker_struct gx_fruitninja_worker;
gx_fruitninja_swordwave_struct gx_fruitninja_swordwave;
gx_fruitninja_keyhandler_enum gx_fruitninja_key;
gx_fruitninja_treasure_struct gx_fruitninja_treasure;

S16 gx_fruitninja_overscore = BONUS_GRADE;
S16 gx_fruitninja_monster_life[MONSTER_NUM];
U8 gx_fruitninja_monster_damage_tick[MONSTER_NUM];
U8 gx_fruitninja_powerbar_unit;
U8 gx_fruitninja_powerbar_count;
U8 gx_fruitninja_powerbar_shining;
U8 gx_fruitninja_max_showitem;
U8 gx_fruitninja_generate_time;
S16 gx_fruitninja_timer = 0;
U8 gx_fruitninja_combo;
U8 gx_fruitninja_gen_lastcolumn[2];
gx_fruitninja_item_type_enum gx_fruitninja_gen_lasttype;
U8 gx_fruitninja_item_fallspeed;

#ifdef  __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /*added for game multi-language*/
static U16 mmi_fruitninja_language_index;
#define MMI_FRUITNINJA_STRING_COUNT MMI_FRUITNINJA_STRING_TOTAL
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_enter_gfx
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_enter_gfx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = 0;//IMG_ID_GX_FRUITNINJA_GAME_ICON;  /* game icon img ID */
    GFX.game_data.game_str_id = STR_ID_GX_FRUITNINJA_GAME_NAME;  /* game name string ID */

    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME; /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;       /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_GAME_LEVEL;   /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;   /* "Best Grade" string ID */

    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP; /* "Game Help" string ID */

    /* level / grade */
    GFX.game_data.level_count = 3;  /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_ID_GX_FRUITNINJA_LEVEL_EASY;    /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_ID_GX_FRUITNINJA_LEVEL_NORMAL;  /* level string ID */
    GFX.game_data.level_str_id_list[2] = STR_ID_GX_FRUITNINJA_LEVEL_HARD;    /* level string ID */

    /* add slot in NVRAMEnum.h */
    GFX.game_data.grade_nvram_id_list[0] = NVRAM_GX_FRUITNINJA_EASY_SCORE;   /* grade slot in NVRAM (short) */
    GFX.game_data.grade_nvram_id_list[1] = NVRAM_GX_FRUITNINJA_NORMAL_SCORE; /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[2] = NVRAM_GX_FRUITNINJA_HARD_SCORE;   /* grade slot in NVRAM */
    GFX.game_data.level_nvram_id = NVRAM_GX_FRUITNINJA_LEVEL;    /* current lvl idnex  in NVRAM (byte) */

    /* help */
    GFX.game_data.help_str_id = STR_ID_GX_FRUITNINJA_HELP_DESCRIPTION;       /* help description string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&g_gx_fruitninja_context.game_grade);   /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&g_gx_fruitninja_context.game_level);    /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) (&g_gx_fruitninja_context.is_new_game);     /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = mmi_gx_fruitninja_calc_best_grade;   /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = mmi_gx_fruitninja_enter_game;        /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = mmi_gx_fruitninja_exit_game;  /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = mmi_gx_fruitninja_draw_gameover;  /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_calc_best_grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]
 *  new_grade       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_gx_fruitninja_calc_best_grade(S16 old_grade, S16 new_grade)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (old_grade > new_grade)
    {
        return old_grade;
    }
    else
    {
        return new_grade;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_draw_gameover
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_draw_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_GAMEOVER();
    mmi_gfx_draw_gameover_screen(
        NULL,
        NULL,
        IMG_ID_GX_FRUITNINJA_MONSTER_BROKEN,
        g_gx_fruitninja_context.game_grade);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_enter_game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_enter_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //used for multilanguage
    mmi_fruitninja_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_fruitninja_language_index,
        IMG_ID_GX_FRUITNINJA_BGROUND_LANGUAGE0,
        MMI_FRUITNINJA_STRING_COUNT);
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    gdi_layer_multi_layer_enable();

    gdi_layer_get_base_handle(&g_gx_fruitninja_context.background);

    gdi_layer_create(
        0,
        0,
        MMI_GX_FRUITNINJA_LCD_WIDTH,
        MMI_GX_FRUITNINJA_LCD_HEIGHT,
        &g_gx_fruitninja_context.foreground);
    gdi_layer_set_active(g_gx_fruitninja_context.foreground);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_BLUE); /* set pure-blue as the transparent color in foreground */
    gdi_layer_clear_background(GDI_COLOR_BLUE);     /* clean foreground layer */

    gdi_layer_set_active(g_gx_fruitninja_context.background);
    mmi_gx_fruitninja_render_generalframe();

    gdi_layer_set_active(g_gx_fruitninja_context.foreground);

    if (g_gx_fruitninja_context.is_new_game == TRUE)
    {
        mmi_gx_fruitninja_init_game();   /* is new game, otherwise resume game */
    }

    g_gx_fruitninja_context.is_new_game = FALSE;
    g_gx_fruitninja_context.is_gameover = FALSE;

    gx_fruitninja_key = KEY_OFF;

    /* keyhandler */
    SetKeyHandler(mmi_gx_fruitninja_key_left_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_right_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_left_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_right_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_up_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_down_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_up_release, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_down_release, KEY_DOWN_ARROW, KEY_EVENT_UP);

    SetKeyHandler(mmi_gx_fruitninja_key_left_press, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_right_press, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_left_release, KEY_4, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_right_release, KEY_6, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_up_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_down_press, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_up_release, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_down_release, KEY_8, KEY_EVENT_UP);

    SetKeyHandler(mmi_gx_fruitninja_key_1_press, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_3_press, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_1_release, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_3_release, KEY_3, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_7_press, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_9_press, KEY_9, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_fruitninja_key_7_release, KEY_7, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_fruitninja_key_9_release, KEY_9, KEY_EVENT_UP);

    /* keyhandler */
    mmi_gx_fruitninja_bgm_play();

    mmi_gx_fruitninja_cyclic_timer();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_exit_game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_exit_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_gx_fruitninja_cyclic_timer);    /* cancle the looping timer */
    gdi_layer_multi_layer_disable();
    gdi_layer_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_free(g_gx_fruitninja_context.foreground);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_init_game
 * DESCRIPTION
 *  Game initilization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_init_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;  /* counter */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_fruitninja_context.is_new_game = FALSE;
    g_gx_fruitninja_context.is_gameover = FALSE;
    g_gx_fruitninja_context.game_grade = 0;

    gx_fruitninja_max_showitem = MAX_SHOWITEM[0];
    gx_fruitninja_generate_time = GENERATE_TIME[0];
    gx_fruitninja_item_fallspeed = ITEM_FALLSPEED[g_gx_fruitninja_context.game_level];

    /* set initial value */
    gx_fruitninja_overscore = g_gx_fruitninja_context.game_grade + BONUS_GRADE;
    gx_fruitninja_timer = 0;

    for (i = 0; i < ITEM_MAX; i++)
    {
        gx_fruitninja_item[i].mission = ITEM_OFF;
    }

    for (i = 0; i < MONSTER_NUM; i++)
    {
        gx_fruitninja_monster_status[i] = SKER_OK;
        gx_fruitninja_monster_life[i] = MONSTER_LIFE;
        gx_fruitninja_monster_damage_tick[i] = 0;
    }

    gx_fruitninja_gen_lastcolumn[0] = 0;
    gx_fruitninja_gen_lastcolumn[1] = 0;
    gx_fruitninja_gen_lasttype = ITEM_ROCK;

    gx_fruitninja_ninja.status = NINJA_RIGHT_WALK;
    gx_fruitninja_ninja.x = MONSTER_POS_X[1];
    gx_fruitninja_ninja.y = NINJA_POS_Y;
    gx_fruitninja_ninja.delay = 0;
    gx_fruitninja_ninja.speed = NINJA_MOVESPEED[0];

    gx_fruitninja_treasure.type = TREASURE_OFF;
    gx_fruitninja_treasure.kickleft = 0;
    gx_fruitninja_treasure.knifeleft = 0;
    gx_fruitninja_treasure.nextcombo = TREASURE_COMBO;

    gx_fruitninja_swordwave.status = SWORDWAVE_OFF;
    gx_fruitninja_swordwave.width = SWORDWAVE_WIDTH[0];
    gx_fruitninja_swordwave.kickwidth = SWORDWAVE_KICKWIDTH[0];
    gx_fruitninja_swordwave.kickdouble = FALSE;
    gx_fruitninja_swordwave.knifedouble = FALSE;

    gx_fruitninja_worker.status = WORKER_OFF;
    gx_fruitninja_worker.x = 0 - WORKER_WIDTH;
    gx_fruitninja_worker.y = WORKER_POS_Y;

    gx_fruitninja_powerbar_unit = POWERBAR_UNIT[0];
    gx_fruitninja_powerbar_count = 0;

    gx_fruitninja_combo = 0;

    gx_fruitninja_key = KEY_OFF;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_framemove
 * DESCRIPTION
 *  Framemove - process the game logic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_framemove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gx_fruitninja_timer == TIMEBLOCK)    /* change game level every TIMEBLOCK frame */
    {
        gx_fruitninja_timer = 0;

        if (gx_fruitninja_generate_time == GENERATE_TIME[0])
        {
            gx_fruitninja_generate_time = GENERATE_TIME[1];
        }
        else if (gx_fruitninja_generate_time == GENERATE_TIME[1])
        {
            gx_fruitninja_generate_time = GENERATE_TIME[2];
        }

        if (gx_fruitninja_max_showitem == MAX_SHOWITEM[0])
        {
            gx_fruitninja_max_showitem = MAX_SHOWITEM[1];
        }
        else if (gx_fruitninja_max_showitem == MAX_SHOWITEM[1])
        {
            gx_fruitninja_max_showitem = MAX_SHOWITEM[2];
        }

    }

    if (gx_fruitninja_timer % gx_fruitninja_generate_time == 0)
    {
        mmi_gx_fruitninja_generate_item();
    }

    mmi_gx_fruitninja_framemove_swordwave(); /* first swordwave then ninja otherwise swd will miss step1 */
    mmi_gx_fruitninja_framemove_ninja();
    mmi_gx_fruitninja_framemove_item();
    mmi_gx_fruitninja_framemove_worker();
    mmi_gx_fruitninja_framemove_monster();
    mmi_gx_fruitninja_framemove_treasure();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_framemove_swordwave
 * DESCRIPTION
 *  swd wave framemove
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_framemove_swordwave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gx_fruitninja_swordwave.step)
    {
        case 0:
            break;

        case 1:
            gx_fruitninja_swordwave.step = 2;
            break;

        case 2:
            gx_fruitninja_swordwave.step = 0;
            gx_fruitninja_swordwave.status = SWORDWAVE_OFF;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_framemove_ninja
 * DESCRIPTION
 *  ninja-framemove
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_framemove_ninja(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gx_fruitninja_ninja.status)
    {
        case NINJA_IDLE:
            /* useless */
            break;

        case NINJA_RIGHT_WALK:
            switch (gx_fruitninja_key)
            {
                case KEY_LEFT:
                    gx_fruitninja_ninja.just_turn = TRUE;
                    gx_fruitninja_ninja.is_left = TRUE;
                    gx_fruitninja_ninja.status = NINJA_LEFT_WALK;
                    break;
                case KEY_RIGHT:
                    break;
                case KEY_UP:
                    /*
                     * GFX_PLAY_AUDIO_WAV(powerbar_charge_wav,
                     * POWERBAR_CHARGE_WAV, DEVICE_AUDIO_PLAY_ONCE);
                     */
                    if (gx_fruitninja_ninja.is_left == FALSE)
                    {
                        gx_fruitninja_ninja.status = NINJA_RIGHT_CUTPREP;
                    }
                    else
                    {
                        gx_fruitninja_ninja.status = NINJA_LEFT_CUTPREP;
                    }
                    break;

                case KEY_DOWN:
                    /*
                     * GFX_PLAY_AUDIO_WAV(powerbar_charge_wav,
                     * POWERBAR_CHARGE_WAV, DEVICE_AUDIO_PLAY_ONCE);
                     */
                    if (gx_fruitninja_ninja.is_left == FALSE)
                    {
                        gx_fruitninja_ninja.status = NINJA_RIGHT_KICKPREP;
                    }
                    else
                    {
                        gx_fruitninja_ninja.status = NINJA_LEFT_KICKPREP;
                    }
                    break;
                case KEY_OFF:
                    break;
            }
            break;

        case NINJA_LEFT_WALK:
            switch (gx_fruitninja_key)
            {
                case KEY_LEFT:
                    break;
                case KEY_RIGHT:
                    gx_fruitninja_ninja.just_turn = TRUE;
                    gx_fruitninja_ninja.is_left = FALSE;
                    gx_fruitninja_ninja.status = NINJA_RIGHT_WALK;
                    break;
                case KEY_UP:
                    /*
                     * GFX_PLAY_AUDIO_WAV(powerbar_charge_wav,
                     * POWERBAR_CHARGE_WAV, DEVICE_AUDIO_PLAY_ONCE);
                     */
                    if (gx_fruitninja_ninja.is_left == TRUE)
                    {
                        gx_fruitninja_ninja.status = NINJA_LEFT_CUTPREP;
                    }
                    else
                    {
                        gx_fruitninja_ninja.status = NINJA_RIGHT_CUTPREP;
                    }
                    break;
                case KEY_DOWN:
                    /*
                     * GFX_PLAY_AUDIO_WAV(powerbar_charge_wav,
                     * POWERBAR_CHARGE_WAV, DEVICE_AUDIO_PLAY_ONCE);
                     */
                    if (gx_fruitninja_ninja.is_left == TRUE)
                    {
                        gx_fruitninja_ninja.status = NINJA_LEFT_KICKPREP;
                    }
                    else
                    {
                        gx_fruitninja_ninja.status = NINJA_RIGHT_KICKPREP;
                    }
                    break;
                case KEY_OFF:
                    break;
            }
            break;

        case NINJA_RIGHT_CUTPREP:
            switch (gx_fruitninja_key)
            {
                case KEY_LEFT:
                    break;
                case KEY_RIGHT:
                    break;
                case KEY_UP:
                    break;
                case KEY_DOWN:
                    break;
                case KEY_OFF:   /* cut */
                    gx_fruitninja_ninja.delay = NINJA_DELAY_CUT;
                    gx_fruitninja_ninja.status = NINJA_RIGHT_CUT;
                    gx_fruitninja_swordwave.x = gx_fruitninja_ninja.x + NINJA_WIDTH - SWORDWAVE_MARGIN_X;
                    gx_fruitninja_swordwave.y = gx_fruitninja_ninja.y - SWORDWAVE_MARGIN_Y;
                    gx_fruitninja_swordwave.step = 1;
                    if (gx_fruitninja_powerbar_count < POWERBAR_LOW)
                    {
                        gx_fruitninja_swordwave.status = SWORDWAVE_LOW;
                        /*
                         * GFX_PLAY_AUDIO_MIDI(cut_lv1_mid,
                         * CUT_LV1_MID, DEVICE_AUDIO_PLAY_ONCE);
                         */
                    }
                    else if (gx_fruitninja_powerbar_count < POWERBAR_MAX)
                    {
                        gx_fruitninja_swordwave.status = SWORDWAVE_MID;
                        /*
                         * GFX_PLAY_AUDIO_WAV(cut_lv2_wav,
                         * CUT_LV2_WAV, DEVICE_AUDIO_PLAY_ONCE);
                         */
                    }
                    else if (gx_fruitninja_powerbar_count == POWERBAR_MAX)
                    {
                        gx_fruitninja_swordwave.status = SWORDWAVE_MAX;
                        /*
                         * GFX_PLAY_AUDIO_WAV(cut_lv3_wav,
                         * CUT_LV3_WAV, DEVICE_AUDIO_PLAY_ONCE);
                         */
                    }

                    gx_fruitninja_swordwave.is_left = FALSE;
                    gx_fruitninja_powerbar_count = 0;
                    break;
            }
            break;

        case NINJA_RIGHT_KICKPREP:
            switch (gx_fruitninja_key)
            {
                case KEY_LEFT:
                    break;
                case KEY_RIGHT:
                    break;
                case KEY_UP:
                    break;
                case KEY_DOWN:
                    break;
                case KEY_OFF:
                    if (gx_fruitninja_powerbar_count >= POWERBAR_KICKMID)
                    {
                        gx_fruitninja_ninja.status = NINJA_RIGHT_KICK;
                        gx_fruitninja_swordwave.status = SWORDWAVE_KICK;
                        gx_fruitninja_swordwave.x = gx_fruitninja_ninja.x + NINJA_WIDTH - SWORDWAVE_KICKMARGIN_X;
                        gx_fruitninja_swordwave.y = gx_fruitninja_ninja.y + NINJA_HEIGHT - SWORDWAVE_KICKMARGIN_Y;
                        gx_fruitninja_swordwave.step = 1;
                        gx_fruitninja_ninja.delay = NINJA_DELAY_KICK;
                        /*
                         * GFX_PLAY_AUDIO_WAV(kick_wav,
                         * KICK_WAV, DEVICE_AUDIO_PLAY_ONCE);
                         */

                    }
                    else    /* charge not enough ,cancel the kick */
                    {
                        gx_fruitninja_ninja.status = NINJA_RIGHT_WALK;
                    }
                    gx_fruitninja_swordwave.is_left = FALSE;
                    gx_fruitninja_powerbar_count = 0;
                    break;
            }
            break;

        case NINJA_LEFT_CUTPREP:
            switch (gx_fruitninja_key)
            {
                case KEY_LEFT:
                    break;
                case KEY_RIGHT:
                    break;
                case KEY_UP:
                    break;
                case KEY_DOWN:
                    break;
                case KEY_OFF:
                    gx_fruitninja_ninja.delay = NINJA_DELAY_CUT;
                    gx_fruitninja_ninja.status = NINJA_LEFT_CUT;
                    gx_fruitninja_swordwave.x = gx_fruitninja_ninja.x - gx_fruitninja_swordwave.width + SWORDWAVE_MARGIN_X;
                    gx_fruitninja_swordwave.y = gx_fruitninja_ninja.y - SWORDWAVE_MARGIN_Y;
                    gx_fruitninja_swordwave.step = 1;

                    if (gx_fruitninja_powerbar_count < POWERBAR_LOW)
                    {
                        gx_fruitninja_swordwave.status = SWORDWAVE_LOW;
                        /*
                         * GFX_PLAY_AUDIO_MIDI(cut_lv1_mid,
                         * CUT_LV1_MID, DEVICE_AUDIO_PLAY_ONCE);
                         */
                    }
                    else if (gx_fruitninja_powerbar_count < POWERBAR_MAX)
                    {
                        gx_fruitninja_swordwave.status = SWORDWAVE_MID;
                        /*
                         * GFX_PLAY_AUDIO_WAV(cut_lv2_wav,
                         * CUT_LV2_WAV, DEVICE_AUDIO_PLAY_ONCE);
                         */
                    }
                    else if (gx_fruitninja_powerbar_count == POWERBAR_MAX)
                    {
                        gx_fruitninja_swordwave.status = SWORDWAVE_MAX;
                        /*
                         * GFX_PLAY_AUDIO_WAV(cut_lv3_wav,
                         * CUT_LV2_WAV, DEVICE_AUDIO_PLAY_ONCE);
                         */
                    }

                    gx_fruitninja_swordwave.is_left = TRUE;
                    gx_fruitninja_powerbar_count = 0;
                    break;
            }
            break;

        case NINJA_LEFT_KICKPREP:
            switch (gx_fruitninja_key)
            {
                case KEY_LEFT:
                    break;
                case KEY_RIGHT:
                    break;
                case KEY_UP:
                    break;
                case KEY_DOWN:
                    break;
                case KEY_OFF:
                    if (gx_fruitninja_powerbar_count >= POWERBAR_KICKMID)
                    {
                        gx_fruitninja_ninja.status = NINJA_LEFT_KICK;
                        gx_fruitninja_swordwave.status = SWORDWAVE_KICK;
                        gx_fruitninja_swordwave.x = gx_fruitninja_ninja.x - gx_fruitninja_swordwave.kickwidth + SWORDWAVE_KICKMARGIN_X;
                        gx_fruitninja_swordwave.y = gx_fruitninja_ninja.y + NINJA_HEIGHT - SWORDWAVE_KICKMARGIN_Y;
                        gx_fruitninja_swordwave.step = 1;
                        gx_fruitninja_ninja.delay = NINJA_DELAY_KICK;
                        /*
                         * GFX_PLAY_AUDIO_WAV(kick_wav,
                         * KICK_WAV, DEVICE_AUDIO_PLAY_ONCE);
                         */
                    }
                    else    /* charge not enough, cancel the kick */
                    {
                        gx_fruitninja_ninja.status = NINJA_LEFT_WALK;
                    }

                    gx_fruitninja_swordwave.is_left = TRUE;
                    gx_fruitninja_powerbar_count = 0;
                    break;
            }
            break;

        case NINJA_RIGHT_CUT:
        case NINJA_RIGHT_KICK:
        case NINJA_LEFT_CUT:
        case NINJA_LEFT_KICK:
        case NINJA_FAINT:
            switch (gx_fruitninja_key)
            {
                case KEY_LEFT:
                    gx_fruitninja_ninja.is_left = TRUE;
                    break;
                case KEY_RIGHT:
                    gx_fruitninja_ninja.is_left = FALSE;
                    break;
                case KEY_UP:
                    break;
                case KEY_DOWN:
                    break;
                case KEY_OFF:
                    break;
            }
            break;
    }

    /* second part */
    switch (gx_fruitninja_ninja.status)
    {
        case NINJA_IDLE:
            /* useless */
            break;

        case NINJA_RIGHT_WALK:
            switch (gx_fruitninja_key)
            {
                case KEY_RIGHT:
                    if (gx_fruitninja_ninja.x < MAINWINDOW_WIDTH - NINJA_WIDTH + NINJA_MOVESIDE_MARGIN)
                    {
                        if (gx_fruitninja_ninja.just_turn == FALSE)
                        {
                            gx_fruitninja_ninja.x = gx_fruitninja_ninja.x + gx_fruitninja_ninja.speed;
                        }
                        else
                        {
                            gx_fruitninja_ninja.just_turn = FALSE;
                        }
                    }
                    break;

                case KEY_LEFT:
                case KEY_UP:
                case KEY_DOWN:
                case KEY_OFF:
                    break;
            }
            break;

        case NINJA_LEFT_WALK:
            switch (gx_fruitninja_key)
            {
                case KEY_LEFT:
                    if (gx_fruitninja_ninja.x > - NINJA_MOVESIDE_MARGIN)
                    {
                        if (gx_fruitninja_ninja.just_turn == FALSE)
                        {
                            gx_fruitninja_ninja.x = gx_fruitninja_ninja.x - gx_fruitninja_ninja.speed;
                        }
                        else
                        {
                            gx_fruitninja_ninja.just_turn = FALSE;
                        }
                    }
                    break;
                case KEY_RIGHT:
                case KEY_UP:
                case KEY_DOWN:
                case KEY_OFF:
                    break;
            }
            break;

        case NINJA_LEFT_CUTPREP:
        case NINJA_RIGHT_CUTPREP:
            switch (gx_fruitninja_key)
            {
                case KEY_UP:
                    mmi_gx_fruitninja_powerbar_charge();
                    break;
                case KEY_RIGHT:
                case KEY_LEFT:
                case KEY_DOWN:
                case KEY_OFF:
                    break;
            }
            break;

        case NINJA_LEFT_CUT:
        case NINJA_LEFT_KICK:
        case NINJA_RIGHT_CUT:
        case NINJA_RIGHT_KICK:
        case NINJA_FAINT:
            if (gx_fruitninja_ninja.delay > 0)
            {
                gx_fruitninja_ninja.delay -= 1;
            }
            else
            {
                if (gx_fruitninja_ninja.is_left == TRUE)
                {
                    gx_fruitninja_ninja.status = NINJA_LEFT_WALK;
                }
                else
                {
                    gx_fruitninja_ninja.status = NINJA_RIGHT_WALK;
                }
            }
            break;

        case NINJA_RIGHT_KICKPREP:
        case NINJA_LEFT_KICKPREP:
            switch (gx_fruitninja_key)
            {
                case KEY_DOWN:
                    mmi_gx_fruitninja_powerbar_charge();
                    break;
                case KEY_RIGHT:
                case KEY_LEFT:
                case KEY_UP:
                case KEY_OFF:
                    break;
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_framemove_item
 * DESCRIPTION
 *  item-framemove
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_framemove_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < gx_fruitninja_max_showitem; i++)
    {
        mmi_gx_fruitninja_item_check(i);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_framemove_worker
 * DESCRIPTION
 *  worker-framemove
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_framemove_worker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gx_fruitninja_worker.status)
    {
        case WORKER_OFF:
            if (g_gx_fruitninja_context.game_grade > gx_fruitninja_overscore && g_gx_fruitninja_context.game_grade < 0xFFFF )
            {
                gx_fruitninja_worker.status = WORKER_STEP;
                gx_fruitninja_worker.x = 0 - WORKER_WIDTH;
                gx_fruitninja_overscore = gx_fruitninja_overscore + BONUS_GRADE;
            }
            break;

        case WORKER_STEP:
            if (gx_fruitninja_worker.x != MONSTER_POS_X[0] &&
                    gx_fruitninja_worker.x != MONSTER_POS_X[1] && gx_fruitninja_worker.x != MONSTER_POS_X[2])
            {
                gx_fruitninja_worker.x = gx_fruitninja_worker.x + 1;
            }
            else    /* start the fix */
            {
                gx_fruitninja_worker.status = WORKER_FIX;
                gx_fruitninja_worker.delay = WORKER_DELAY;
            }

            if (gx_fruitninja_worker.x > MMI_GX_FRUITNINJA_LCD_WIDTH) /* leaving screen */
            {
                gx_fruitninja_worker.status = WORKER_OFF;
            }
            break;

        case WORKER_FIX:
            if (gx_fruitninja_worker.delay != 0)
            {
                gx_fruitninja_worker.delay = gx_fruitninja_worker.delay - 1;
                /*
                 * GFX_PLAY_AUDIO_WAV(worker_fixing_wav,
                 * WORKER_FIXING_WAV, DEVICE_AUDIO_PLAY_ONCE);
                 */
            }
            else    /* just finish repair */
            {
                if (gx_fruitninja_worker.x == MONSTER_POS_X[0])
                {
                    gx_fruitninja_monster_life[0] = MONSTER_LIFE;
                }
                else if (gx_fruitninja_worker.x == MONSTER_POS_X[1])
                {
                    gx_fruitninja_monster_life[1] = MONSTER_LIFE;
                }
                else if (gx_fruitninja_worker.x == MONSTER_POS_X[2])
                {
                    gx_fruitninja_monster_life[2] = MONSTER_LIFE;
                }
                gx_fruitninja_worker.status = WORKER_STEP;
                gx_fruitninja_worker.x = gx_fruitninja_worker.x + 1;
            }
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_framemove_monster
 * DESCRIPTION
 *  monster-framemove
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_framemove_monster()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MONSTER_NUM; i++)
    {

        /* Warning : do not cancel MONSTER_LIFE >= gx....[i] term if using S8 to store monster_life
           having problem when using S8 to store monster_life(when value crossing zero)
           ,ex life=2,  life - 3 =>result is 255,       now using S16 */

        if (MONSTER_LIFE >= gx_fruitninja_monster_life[i] && gx_fruitninja_monster_life[i] > MONSTER_LIFEA)
        {
            gx_fruitninja_monster_status[i] = SKER_OK;
        }

        else if (gx_fruitninja_monster_life[i] > MONSTER_LIFEB)
        {
            gx_fruitninja_monster_status[i] = SKER_PBLVA;
        }
        else if (gx_fruitninja_monster_life[i] > 0)
        {
            gx_fruitninja_monster_status[i] = SKER_PBLVB;
        }
        else
        {
            gx_fruitninja_monster_status[i] = SKER_BROKEN;
            /* play monster break sound here */
            /* play monster break sound here */
            g_gx_fruitninja_context.is_gameover = TRUE;
            gx_fruitninja_timer = 0;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_framemove_treasure
 * DESCRIPTION
 *  treasure framemove
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_framemove_treasure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gx_fruitninja_swordwave.kickdouble)
    {
        gx_fruitninja_treasure.kickleft--;
        if (gx_fruitninja_treasure.kickleft == 0)
        {
            gx_fruitninja_swordwave.kickdouble = FALSE;
            gx_fruitninja_swordwave.kickwidth = SWORDWAVE_KICKWIDTH[0];
        }
    }

    if (gx_fruitninja_swordwave.knifedouble)
    {
        gx_fruitninja_treasure.knifeleft--;
        if (gx_fruitninja_treasure.knifeleft == 0)
        {
            gx_fruitninja_swordwave.knifedouble = FALSE;
            gx_fruitninja_swordwave.width = SWORDWAVE_WIDTH[0];
        }
    }

    if (gx_fruitninja_treasure.type != TREASURE_OFF) /* is falling */
    {
        /* reach ninja code here */
        if (mmi_gx_fruitninja_collision(
                    gx_fruitninja_ninja.x,
                    gx_fruitninja_ninja.y + NINJA_ACTUAL_POS_Y_OFFSET,
                    NINJA_WIDTH,
                    NINJA_HEIGHT - NINJA_ACTUAL_POS_Y_OFFSET,
                    gx_fruitninja_treasure.x,
                    gx_fruitninja_treasure.y,
                    TREASURE_WIDTH,
                    TREASURE_HEIGHT,
                    HIT_MARGIN,
                    HIT_MARGIN))
        {
            /*
             * GFX_PLAY_AUDIO_MIDI(get_treasure_mid,
             * GET_TREASURE_MID, DEVICE_AUDIO_PLAY_ONCE);
             */
            switch (gx_fruitninja_treasure.type)
            {
                case TREASURE_SPEED:
                    if (gx_fruitninja_ninja.speed == NINJA_MOVESPEED[0])
                    {
                        gx_fruitninja_ninja.speed = NINJA_MOVESPEED[1];
                    }
                    else if (gx_fruitninja_ninja.speed == NINJA_MOVESPEED[1])
                    {
                        gx_fruitninja_ninja.speed = NINJA_MOVESPEED[2];
                    }
                    break;
                case TREASURE_KICK:
                    gx_fruitninja_swordwave.kickwidth = SWORDWAVE_KICKWIDTH[1];
                    gx_fruitninja_swordwave.kickdouble = TRUE;
                    gx_fruitninja_treasure.kickleft = DUALKICK_DURATION;
                    break;
                case TREASURE_KNIFE:
                    gx_fruitninja_swordwave.width = SWORDWAVE_WIDTH[1];
                    gx_fruitninja_swordwave.knifedouble = TRUE;
                    gx_fruitninja_treasure.knifeleft = DUALKNIFE_DURATION;
                    break;
                case TREASURE_POWER:
                    gx_fruitninja_powerbar_unit = POWERBAR_UNIT[1];
                    break;
                case TREASURE_ALLCUT:   /* will turn every item on screen to full-cut one */
                {
                    S16 i;

                    for (i = 0; i < gx_fruitninja_max_showitem; i++)
                    {
                        if (gx_fruitninja_item[i].mission != ITEM_OFF)
                        {
                            gx_fruitninja_item[i].piece = ITEM_MP;
                            gx_fruitninja_item[i].mission = ITEM_CUT_FALL;
                            gx_fruitninja_item[i].type = 1 + rand() % 2;
                        }
                    }
                }
                break;
            }
            gx_fruitninja_treasure.type = TREASURE_OFF;
        }
        /* reach ninja code here */

        else    /* keep falling */
        {
            /* about treasure type:
               limit the first 3 treasure player get
               in this order: speed1,speed2,and powerbar
               in the first 3 min of the game, player should try high combo to get at least
               these 3  treasures, then it'll be a lot easier to survive level 2 and 3
               if treasure are made all by random,
               hard & level3 might = gameover in 10 sec */

            if (gx_fruitninja_ninja.speed != NINJA_MOVESPEED[2])
            {
                gx_fruitninja_treasure.type = TREASURE_SPEED;
            }
            else if (gx_fruitninja_powerbar_unit != POWERBAR_UNIT[1])
            {
                gx_fruitninja_treasure.type = TREASURE_POWER;
            }
            else
            {
                if (gx_fruitninja_treasure.type >= TREASURE_ALLCUT )
                {
                    gx_fruitninja_treasure.type = TREASURE_KNIFE;
                }
                else
                {
                    gx_fruitninja_treasure.type = gx_fruitninja_treasure.type + 1;
                }
                /* no more speed and power */
            }

            gx_fruitninja_treasure.y = gx_fruitninja_treasure.y + TREASURE_FALLSPEED;

            if (gx_fruitninja_treasure.y > MMI_GX_FRUITNINJA_LCD_HEIGHT)  /* out screen */
            {
                gx_fruitninja_treasure.type = TREASURE_OFF;
            }
        }
    }
    else if (gx_fruitninja_combo >= gx_fruitninja_treasure.nextcombo)
    {
        if (gx_fruitninja_ninja.speed != NINJA_MOVESPEED[2])
        {
            gx_fruitninja_treasure.type = TREASURE_SPEED;
        }
        else if (gx_fruitninja_powerbar_unit != POWERBAR_UNIT[1])
        {
            gx_fruitninja_treasure.type = TREASURE_POWER;
        }
        else
        {
            gx_fruitninja_treasure.type = TREASURE_KNIFE + rand() % 3;    /* no more speed and power */
        }

        gx_fruitninja_treasure.x = rand() % (MAINWINDOW_WIDTH - NINJA_MOVESIDE_MARGIN);
        gx_fruitninja_treasure.y = 0 - TREASURE_HEIGHT;
        gx_fruitninja_treasure.nextcombo += TREASURE_COMBO;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_clear_background(GDI_COLOR_BLUE);     /* clean foreground layer */

    /* draw score digits */
    mmi_gx_fruitninja_draw_digits(
        SCOREBAR_POS_X,
        SCOREBAR_POS_Y,
        g_gx_fruitninja_context.game_grade,
        5);

    mmi_gx_fruitninja_render_powerbar();
    mmi_gx_fruitninja_render_ninja();
    mmi_gx_fruitninja_render_treasure();

    mmi_gx_fruitninja_render_monster();

    for (i = 0; i < gx_fruitninja_max_showitem; i++) /* skip ITEM_HIT_NINJA one */
    {
        if (gx_fruitninja_item[i].mission != ITEM_HIT_NINJA && gx_fruitninja_item[i].mission != ITEM_OFF)
        {
            mmi_gx_fruitninja_render_item(i);
        }
    }

    mmi_gx_fruitninja_render_swordwave(gx_fruitninja_swordwave.x);

    /* if swordwave is in double size right now,draw another one */
    if (gx_fruitninja_swordwave.status != SWORDWAVE_KICK && gx_fruitninja_swordwave.knifedouble == TRUE)
    {
        mmi_gx_fruitninja_render_swordwave((S16) (gx_fruitninja_swordwave.x + SWORDWAVE_WIDTH[0]));
    }

    else if (gx_fruitninja_swordwave.status == SWORDWAVE_KICK && gx_fruitninja_swordwave.kickdouble == TRUE)
    {
        mmi_gx_fruitninja_render_swordwave((S16) (gx_fruitninja_swordwave.x + SWORDWAVE_KICKWIDTH[0]));
    }
    /* if swordwave is in double size right now,draw another one */

    mmi_gx_fruitninja_render_treasurebar();
    mmi_gx_fruitninja_render_worker();
    mmi_gx_fruitninja_render_combo();

    for (i = 0; i < gx_fruitninja_max_showitem; i++) /* draw ITEM_HIT_NINJA one here */
        /* so hit_ninja item don't get in monster on screen */
    {
        if (gx_fruitninja_item[i].mission == ITEM_HIT_NINJA)
        {
            mmi_gx_fruitninja_render_item(i);
        }
    }

    gdi_layer_blt(
        g_gx_fruitninja_context.background, /* layer 0 */
        g_gx_fruitninja_context.foreground, /* layer 1 */
        0,                                  /* layer 2 */
        0,                                  /* layer 3 */
        0,                                  /* offset x */
        0,                                  /* offset y */
        MMI_GX_FRUITNINJA_LCD_WIDTH - 1,    /* width */
        MMI_GX_FRUITNINJA_LCD_HEIGHT - 1);  /* height */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_ninja
 * DESCRIPTION
 *  Render ninja img,
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_ninja(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL fgRet = TRUE;    
    U16 imageID = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gx_fruitninja_ninja.status)
    {
        case NINJA_RIGHT_WALK:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_WALKA;
            break;

        case NINJA_LEFT_WALK:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_LEFT_WALKA;
            break;

        case NINJA_FAINT:
            if ( (gx_fruitninja_timer % 2) == 0 )
            {
                imageID = (U16)((gx_fruitninja_ninja.is_left == TRUE) ? IMG_ID_GX_FRUITNINJA_NINJA_LEFT_WALKA : IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_WALKA);
            }
            else
            {
                imageID = 0;
            }
            break;
        case NINJA_RIGHT_CUTPREP:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_CUTPREP;
            break;
        case NINJA_RIGHT_CUT:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_CUT;
            break;
        case NINJA_RIGHT_KICKPREP:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_KICKPREP;
            break;
        case NINJA_RIGHT_KICK:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_CUT;
            break;
        case NINJA_LEFT_CUTPREP:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_LEFT_CUTPREP;
            break;
        case NINJA_LEFT_CUT:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_LEFT_CUT;
            break;
        case NINJA_LEFT_KICKPREP:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_LEFT_KICKPREP;
            break;
        case NINJA_LEFT_KICK:
            imageID = (U16)IMG_ID_GX_FRUITNINJA_NINJA_LEFT_CUT;
            break;

        default:
            fgRet = FALSE;    
            break;

    }

    if ( fgRet == TRUE && imageID != 0 )
    {
#ifdef __MMI_MAINLCD_176X220__
            gdi_image_draw_id(
                gx_fruitninja_ninja.x + 3,
                gx_fruitninja_ninja.y + NINJA_HEIGHT,
                IMG_ID_GX_FRUITNINJA_NINJA_SHADOW);
#endif
#ifdef __MMI_MAINLCD_240X320__        
        gdi_image_draw_id(
            gx_fruitninja_ninja.x + 1,
            gx_fruitninja_ninja.y + NINJA_HEIGHT - 2,
            IMG_ID_GX_FRUITNINJA_NINJA_SHADOW);
#endif
        gdi_image_draw_id(
            gx_fruitninja_ninja.x,
            gx_fruitninja_ninja.y,
            imageID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_item
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  i       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_item(S16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gx_fruitninja_item[i].type)
    {
        case ITEM_FOODA:
            gdi_image_draw_id(
                gx_fruitninja_item[i].x,
                gx_fruitninja_item[i].y,
                (U16) (IMG_ID_GX_FRUITNINJA_FOODA_ONE_PIECE + (gx_fruitninja_item[i].piece)));
            break;

        case ITEM_FOODB:
            gdi_image_draw_id(
                gx_fruitninja_item[i].x,
                gx_fruitninja_item[i].y,
                (U16) (IMG_ID_GX_FRUITNINJA_FOODB_ONE_PIECE + (gx_fruitninja_item[i].piece)));
            break;

        case ITEM_FOODC:
            gdi_image_draw_id(
                gx_fruitninja_item[i].x,
                gx_fruitninja_item[i].y,
                (U16) (IMG_ID_GX_FRUITNINJA_FOODC_ONE_PIECE + (gx_fruitninja_item[i].piece)));
            break;

        case ITEM_ROCK:
            gdi_image_draw_id(gx_fruitninja_item[i].x, gx_fruitninja_item[i].y, IMG_ID_GX_FRUITNINJA_ROCK_ONEPIECE);
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_monster
 * DESCRIPTION
 *  Render 3 monsters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_monster(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw monster */
    for (i = 0; i < MONSTER_NUM; i++)
    {
        if (gx_fruitninja_monster_damage_tick[i] > 0)
        {
            gx_fruitninja_monster_damage_tick[i] = gx_fruitninja_monster_damage_tick[i] - 1;        /* used to show monster damaged ani */
        }

        
#ifdef __MMI_MAINLCD_176X220__
        gdi_image_draw_id(
            MONSTER_POS_X[i] - 3,
            MONSTER_POS_Y + MONSTER_HEIGHT - 6,
            IMG_ID_GX_FRUITNINJA_MONSTER_SHADOW);
#endif
        
#ifdef __MMI_MAINLCD_240X320__
        gdi_image_draw_id(
            MONSTER_POS_X[i] - 5,
            MONSTER_POS_Y + MONSTER_HEIGHT - 8,
            IMG_ID_GX_FRUITNINJA_MONSTER_SHADOW);
#endif

        switch (gx_fruitninja_monster_status[i])
        {
            case SKER_OK:
                gdi_image_draw_id(
                    MONSTER_POS_X[i],
                    MONSTER_POS_Y,
                    IMG_ID_GX_FRUITNINJA_MONSTER_OKA);
                break;
            case SKER_PBLVA:
                gdi_image_draw_id(
                    MONSTER_POS_X[i],
                    MONSTER_POS_Y,
                    IMG_ID_GX_FRUITNINJA_MONSTER_PBLVA_A);
                break;
            case SKER_PBLVB:
                gdi_image_draw_id(
                    MONSTER_POS_X[i],
                    MONSTER_POS_Y,
                    IMG_ID_GX_FRUITNINJA_MONSTER_PBLVB_A);
                break;
            case SKER_BROKEN:
                gdi_image_draw_id(
                    MONSTER_POS_X[i],
                    MONSTER_POS_Y,
                    IMG_ID_GX_FRUITNINJA_MONSTER_BROKEN);
                break;
        }
    }

    /* draw monster */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_treasurebar
 * DESCRIPTION
 *  Render treasure images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_treasurebar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bar color change with left duration,bright ->dark */
    if (gx_fruitninja_swordwave.knifedouble == TRUE)
    {
        gdi_draw_solid_rect(
            TREASUREBAR_POS_X,
            TREASUREBAR_POS_Y + TREASUREBAR_FRAME,
            TREASUREBAR_POS_X + 1 + gx_fruitninja_treasure.knifeleft / 15,
            TREASUREBAR_POS_Y + TREASUREBAR_HEIGHT - TREASUREBAR_FRAME,
            gdi_act_color_from_rgb(255, 100 + gx_fruitninja_treasure.knifeleft / 3, 100 + gx_fruitninja_treasure.knifeleft / 3, 155 + gx_fruitninja_treasure.knifeleft / 3));
    }

    if (gx_fruitninja_swordwave.kickdouble == TRUE)
    {
        gdi_draw_solid_rect(
            TREASUREBAR_POS_X,
            TREASUREBAR_POS_Y + TREASUREBAR_FRAME + TREASUREBAR_HEIGHT,
            TREASUREBAR_POS_X + 1 + gx_fruitninja_treasure.kickleft / 30,
            TREASUREBAR_POS_Y + 2 * TREASUREBAR_HEIGHT - TREASUREBAR_FRAME,
            gdi_act_color_from_rgb(255, 255, 128 + gx_fruitninja_treasure.kickleft / 6, 64 + gx_fruitninja_treasure.kickleft / 6));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_treasure
 * DESCRIPTION
 *  Render the treasure images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_treasure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gx_fruitninja_treasure.type != TREASURE_OFF)
    {
        gdi_image_draw_id(
            gx_fruitninja_treasure.x,
            gx_fruitninja_treasure.y,
            (U16) (IMG_ID_GX_FRUITNINJA_TREASURE_1 + gx_fruitninja_treasure.type - 1));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_swordwave
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  x           [IN]
 *  pos(?)      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_swordwave(S16 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gx_fruitninja_swordwave.is_left == TRUE)
    {
        switch (gx_fruitninja_swordwave.status)
        {
            case SWORDWAVE_OFF:
                break;

            case SWORDWAVE_LOW:
            case SWORDWAVE_MID:
            case SWORDWAVE_MAX:
                gdi_image_draw_id(
                    x,
                    gx_fruitninja_swordwave.y,
                    (U16) (IMG_ID_GX_FRUITNINJA_SWDWAVELOW_LEFT_A + gx_fruitninja_swordwave.step - 1));
                break;

            case SWORDWAVE_KICK:
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                break;
        }
    }
    else
    {
        switch (gx_fruitninja_swordwave.status)
        {
            case SWORDWAVE_OFF:
                break;

            case SWORDWAVE_LOW:
            case SWORDWAVE_MID:
            case SWORDWAVE_MAX:
                gdi_image_draw_id(
                    x,
                    gx_fruitninja_swordwave.y,
                    (U16) (IMG_ID_GX_FRUITNINJA_SWDWAVELOW_RIGHT_A + gx_fruitninja_swordwave.step - 1));
                break;

            case SWORDWAVE_KICK:
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                break;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_worker
 * DESCRIPTION
 *  draw workder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_worker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gx_fruitninja_worker.status)
    {
        case WORKER_OFF:
            break;

        case WORKER_STEP:
            gdi_image_draw_id(
                gx_fruitninja_worker.x,
                gx_fruitninja_worker.y,
                (U16) (IMG_ID_GX_FRUITNINJA_WORKER_STEPA + (gx_fruitninja_timer % 2)));
            break;

        case WORKER_FIX:
            gdi_image_draw_id(
                gx_fruitninja_worker.x,
                gx_fruitninja_worker.y,
                (U16) (IMG_ID_GX_FRUITNINJA_WORKER_FIXA + (gx_fruitninja_timer % 2)));
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_powerbar
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_powerbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* handle all the shining stuff */
    if (gx_fruitninja_timer % 20 < 10)
    {
        gx_fruitninja_powerbar_shining = (gx_fruitninja_timer % 20) * 4;
    }
    else
    {
        gx_fruitninja_powerbar_shining = (20 - gx_fruitninja_timer % 20) * 4;
    }
    /* handle all the shining stuff */

    /* draw powerbar energy */
    gdi_draw_solid_rect(
        POWERBAR_POS_X,
        POWERBAR_POS_Y + POWERBAR_MAX - gx_fruitninja_powerbar_count,
        POWERBAR_POS_X + POWERBAR_WIDTH,
        POWERBAR_POS_Y + POWERBAR_MAX,
        gdi_act_color_from_rgb(255, 40 + gx_fruitninja_powerbar_count + gx_fruitninja_powerbar_shining, 100 + gx_fruitninja_powerbar_count + gx_fruitninja_powerbar_shining, gx_fruitninja_powerbar_count * 4 + gx_fruitninja_powerbar_shining));
    /* draw powerbar energy */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_combo
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_combo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (gx_fruitninja_combo >= COMBO_LV1)
    {
        /* for,better performance use bigger font img,when combo reach 5,10,15...etc
           use original img,else use gdi to show smaller img */
        mmi_gx_fruitninja_draw_digits(COMBOBAR_X, COMBOBAR_Y, gx_fruitninja_combo, 3);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_gameover
 * DESCRIPTION
 *  Gameover function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_fruitninja_context.is_gameover = TRUE;
    g_gx_fruitninja_context.is_new_game = TRUE;

    /* call this function to draw gameover screen */
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_cyclic_timer
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_cyclic_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(g_gx_fruitninja_context.timer_elapse, mmi_gx_fruitninja_cyclic_timer);

    gx_fruitninja_timer = gx_fruitninja_timer + 1;

    if (g_gx_fruitninja_context.is_gameover == FALSE)
    {
        mmi_gx_fruitninja_framemove();
        mmi_gx_fruitninja_render();
    }
    else
    {
        if (gx_fruitninja_timer > 20)    /* idle 1 sec before gameover */
        {
            mmi_gx_fruitninja_gameover();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_generate_item
 * DESCRIPTION
 *  try to generate an item every GENERATE_TIME frames
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_generate_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i != gx_fruitninja_max_showitem)
    {
        if (gx_fruitninja_item[i].mission == ITEM_OFF)   /* found a empty place */
        {
            break;
        }
        i++;
    };

    if (i < gx_fruitninja_max_showitem)  /* generate a new item if found a empty place */
    {

        while (1)
        {
            gx_fruitninja_item[i].type = 1 + rand() % (ITEM_TYPE_CNT);
            if (gx_fruitninja_gen_lasttype != gx_fruitninja_item[i].type)
            {
                break;
            }
        }

        /* lower continuous same column and all-column hor chance */
        while (1)
        {
            gx_fruitninja_item[i].column = rand() % (MONSTER_NUM);
            if (gx_fruitninja_item[i].column != gx_fruitninja_gen_lastcolumn[0])
            {
                if (gx_fruitninja_item[i].column != gx_fruitninja_gen_lastcolumn[1])
                    if (rand() % 5 > 1)
                    {
                        break;
                    }
            }
            else if (rand() % 2 == 0)
            {
                break;
            }
        }
        gx_fruitninja_gen_lastcolumn[1] = gx_fruitninja_gen_lastcolumn[0];
        gx_fruitninja_gen_lastcolumn[0] = gx_fruitninja_item[i].column;
        gx_fruitninja_gen_lasttype = gx_fruitninja_item[i].type;
        /* lower continuous same column chance and all-column hor chance  */

        gx_fruitninja_item[i].piece = ITEM_1P;
        gx_fruitninja_item[i].x = ONTRACK_POS_X[gx_fruitninja_item[i].column];
        gx_fruitninja_item[i].y = ONTRACK_POS_Y[gx_fruitninja_item[i].column];
        gx_fruitninja_item[i].mission = ITEM_FALL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_draw_digits
 * DESCRIPTION
 *  used to draw score,combo and debug digits
 * PARAMETERS
 *  x           [IN]        X position for images
 *  y           [IN]        Y position for images
 *  number      [IN]        The number to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_draw_digits(S16 x, S16 y, U16 number, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 buf[20];
    S8 buf_USC2[40];
    S32 str_width;
    S32 str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_small_font);

    gui_set_text_color(gui_color(255, 255, 255));
    gui_set_text_border_color(gui_color(0, 0, 0));

    sprintf(buf, "%d", number);
    mmi_asc_to_ucs2(buf_USC2, buf);

    gui_measure_string((UI_string_type) buf_USC2, &str_width, &str_height);
    gui_move_text_cursor(x, y);
    gui_print_bordered_text((UI_string_type) buf_USC2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_render_generalframe
 * DESCRIPTION
 *  draw still objects on screen (except item,ninja
 *  ,worker,swdwave,speedwave)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_render_generalframe(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gdi_image_draw_id(0, 0, IMG_ID_GX_FRUITNINJA_BGROUND);
#else
    gdi_image_draw_id(
        0,
        0,
        mmi_gfx_get_multilanguage_image_ID(
            mmi_fruitninja_language_index,
            IMG_ID_GX_FRUITNINJA_BGROUND_LANGUAGE0,
            MMI_FRUITNINJA_STRING_COUNT,
            MMI_FRUITNINJA_STRING_BACKGROUND));
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_left_press
 * DESCRIPTION
 *  key handler-left arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_left_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_LEFT;

    /*
     * if (gx_fruitninja_ninja.is_left==FALSE)
     * {
     * gx_fruitninja_ninja.just_turn=TRUE;
     * }
     *
     * gx_fruitninja_keyhandler.right_press=FALSE;
     * gx_fruitninja_keyhandler.left_press=TRUE;
     * gx_fruitninja_ninja.is_left=TRUE;
     *
     * if (gx_fruitninja_ninja.status!=NINJA_LEFT_CUTPREP &&
     * gx_fruitninja_ninja.status!=NINJA_RIGHT_CUTPREP &&
     * gx_fruitninja_ninja.status!=NINJA_LEFT_KICKPREP &&
     * gx_fruitninja_ninja.status!=NINJA_RIGHT_KICKPREP &&
     * gx_fruitninja_ninja.delay == 0)
     * {
     * gx_fruitninja_ninja.status=NINJA_LEFT_WALK;
     * }
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_right_press
 * DESCRIPTION
 *  key handler-right arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_right_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_RIGHT;
    /*
     * if (gx_fruitninja_ninja.is_left==TRUE)
     * {
     * gx_fruitninja_ninja.just_turn=TRUE;
     * }
     *
     * gx_fruitninja_keyhandler.left_press=FALSE;
     * gx_fruitninja_keyhandler.right_press=TRUE;
     * gx_fruitninja_ninja.is_left=FALSE;
     *
     * if (gx_fruitninja_ninja.status!=NINJA_LEFT_CUTPREP &&
     * gx_fruitninja_ninja.status!=NINJA_RIGHT_CUTPREP &&
     * gx_fruitninja_ninja.status!=NINJA_LEFT_KICKPREP &&
     * gx_fruitninja_ninja.status!=NINJA_RIGHT_KICKPREP &&
     * gx_fruitninja_ninja.delay == 0)
     * {
     * gx_fruitninja_ninja.status=NINJA_RIGHT_WALK;
     * }
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_left_release
 * DESCRIPTION
 *  key handler-left arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_left_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_right_release
 * DESCRIPTION
 *  key handler-right arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_right_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_up_press
 * DESCRIPTION
 *  key handler-left arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_up_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_UP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_down_press
 * DESCRIPTION
 *  key handler-right arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_down_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_DOWN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_up_release
 * DESCRIPTION
 *  key handler-left arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_up_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_down_release
 * DESCRIPTION
 *  key handler-right arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_down_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_7_press
 * DESCRIPTION
 *  key handler-dl arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_7_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_ninja.is_left = TRUE;
    gx_fruitninja_key = KEY_DOWN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_9_press
 * DESCRIPTION
 *  key handler-dr arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_9_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_ninja.is_left = FALSE;
    gx_fruitninja_key = KEY_DOWN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_7_release
 * DESCRIPTION
 *  key handler-ld arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_7_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_9_release
 * DESCRIPTION
 *  key handler-rd arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_9_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_1_press
 * DESCRIPTION
 *  key handler-ul arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_1_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_ninja.is_left = TRUE;
    gx_fruitninja_key = KEY_UP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_3_press
 * DESCRIPTION
 *  key handler-ur arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_3_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_ninja.is_left = FALSE;
    gx_fruitninja_key = KEY_UP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_1_release
 * DESCRIPTION
 *  key handler-ul_arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_1_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_key_3_release
 * DESCRIPTION
 *  key handler-ur arrow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_key_3_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_key = KEY_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_powerbar_charge
 * DESCRIPTION
 *  charge powerbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_powerbar_charge(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gx_fruitninja_powerbar_count += gx_fruitninja_powerbar_unit;
    if (gx_fruitninja_powerbar_count >= POWERBAR_MAX)
    {
        gx_fruitninja_powerbar_count = POWERBAR_MAX;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_item_check
 * DESCRIPTION
 *  make framvemove of each item
 * PARAMETERS
 *  i           [IN]
 *  item(?)     [IN]        No.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_item_check(S16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gx_fruitninja_item[i].mission)
    {
        case ITEM_OFF:
            break;

        case ITEM_FALL:
            if ((gx_fruitninja_item[i].y + ITEM_HEIGHT[gx_fruitninja_item[i].type -1]) > MONSTER_POS_Y)  /* reach monster */
            {
                mmi_gx_fruitninja_notescore(i);
                gx_fruitninja_item[i].mission = ITEM_OFF;
            }
            else if (mmi_gx_fruitninja_collision(
                         gx_fruitninja_ninja.x,
                         gx_fruitninja_ninja.y + NINJA_ACTUAL_POS_Y_OFFSET,
                         NINJA_WIDTH,
                         HIT_MARGIN,
                         gx_fruitninja_item[i].x,
                         (S16) (gx_fruitninja_item[i].y + ITEM_HEIGHT[gx_fruitninja_item[i].type -1] - HIT_MARGIN),
                         ITEM_WIDTH[gx_fruitninja_item[i].type -1],
                         HIT_MARGIN,
                         HIT_MARGIN,
                         0))
            {   /* item hit ninja, only occur when buttom of item encounter ninja top */

                /*
                 * GFX_PLAY_AUDIO_WAV(hit_head_wav,
                 * HIT_HEAD_WAV, DEVICE_AUDIO_PLAY_ONCE);
                 */

                if (gx_fruitninja_item[i].type != ITEM_ROCK)
                {
                    gx_fruitninja_ninja.delay = NINJA_DELAY_HITHEAD_FRUIT;
                }
                else
                {
                    gx_fruitninja_ninja.delay = NINJA_DELAY_HITHEAD_ROCK;
                }

                gx_fruitninja_ninja.status = NINJA_FAINT;
                gx_fruitninja_powerbar_count = 0;
                gx_fruitninja_item[i].mission = ITEM_HIT_NINJA;
                gx_fruitninja_item[i].tick = 0;
            }
            else if (gx_fruitninja_swordwave.status != SWORDWAVE_OFF && gx_fruitninja_swordwave.status != SWORDWAVE_KICK)
            {
                if (mmi_gx_fruitninja_collision(
                            gx_fruitninja_item[i].x,
                            gx_fruitninja_item[i].y,
                            ITEM_WIDTH[gx_fruitninja_item[i].type -1],
                            ITEM_HEIGHT[gx_fruitninja_item[i].type -1],
                            gx_fruitninja_swordwave.x,
                            gx_fruitninja_swordwave.y,
                            gx_fruitninja_swordwave.width,
                            SWORDWAVE_HEIGHT,
                            0,
                            0))
                {
                    if (gx_fruitninja_item[i].type != ITEM_ROCK) /* the item is fruit */
                    {
                        gx_fruitninja_item[i].mission = ITEM_CUT_FALL;
                        switch (gx_fruitninja_swordwave.status)
                        {
                            case SWORDWAVE_LOW:
                                gx_fruitninja_item[i].piece = ITEM_2P;
                                break;
                            case SWORDWAVE_MID:
                                gx_fruitninja_item[i].piece = ITEM_3P;
                                break;
                            case SWORDWAVE_MAX:
                                gx_fruitninja_item[i].piece = ITEM_MP;
                                break;
                        }
                    }
                    else    /* rock counter swordwave */
                    {
                        gx_fruitninja_ninja.status = NINJA_FAINT;
                        gx_fruitninja_ninja.delay = NINJA_DELAY_COUNTER_ROCK;
                        gx_fruitninja_powerbar_count = 0;
                    }
                }
            }
            else if (gx_fruitninja_swordwave.status == SWORDWAVE_KICK)
            {
                if (mmi_gx_fruitninja_collision(
                            gx_fruitninja_item[i].x,
                            gx_fruitninja_item[i].y,
                            ITEM_WIDTH[gx_fruitninja_item[i].type -1],
                            ITEM_HEIGHT[gx_fruitninja_item[i].type -1],
                            gx_fruitninja_swordwave.x,
                            gx_fruitninja_swordwave.y,
                            gx_fruitninja_swordwave.kickwidth,
                            SWORDWAVE_HEIGHT,
                            0,
                            0))
                {
                    if (gx_fruitninja_item[i].x > gx_fruitninja_ninja.x)
                    {
                        gx_fruitninja_item[i].mission = ITEM_KICK_AWAY_RIGHT;
                    }
                    else
                    {
                        gx_fruitninja_item[i].mission = ITEM_KICK_AWAY_LEFT;
                    }
                }
            }
            if ( gx_fruitninja_item[i].mission == ITEM_FALL )
            {
                gx_fruitninja_item[i].y = gx_fruitninja_item[i].y + gx_fruitninja_item_fallspeed;
            }
            break;

        case ITEM_CUT_FALL:

            if (gx_fruitninja_item[i].y + (MONSTER_HEIGHT>>1) > MONSTER_POS_Y)
            {
                mmi_gx_fruitninja_notescore(i);
                gx_fruitninja_item[i].mission = ITEM_OFF;
            }
            gx_fruitninja_item[i].y = gx_fruitninja_item[i].y + ITEM_FALLCUT_SPEED;

            break;

        case ITEM_HIT_NINJA:
            if (gx_fruitninja_item[i].y > MMI_GX_FRUITNINJA_LCD_HEIGHT)   /* leave screen */
            {
                gx_fruitninja_item[i].mission = ITEM_OFF;
            }

            else if (gx_fruitninja_item[i].tick < 5)
            {
                gx_fruitninja_item[i].x = gx_fruitninja_item[i].x + 1;
                gx_fruitninja_item[i].y = gx_fruitninja_item[i].y - 2;
            }
            else if (gx_fruitninja_item[i].tick < 10)
            {
                gx_fruitninja_item[i].x = gx_fruitninja_item[i].x + 1;
                gx_fruitninja_item[i].y = gx_fruitninja_item[i].y + 1;
            }
            else    /* back to  falling */
            {
                if (gx_fruitninja_item[i].tick == 10)
                {
                    /*
                     * if (gx_fruitninja_item[i].type == ITEM_ROCK)
                     * GFX_PLAY_AUDIO_WAV(rock_hithead_fall_wav,
                     * ROCK_HITHEAD_FALL_WAV, DEVICE_AUDIO_PLAY_ONCE);
                     * else
                     * GFX_PLAY_AUDIO_WAV(item_hithead_fall_wav,
                     * ITEM_HITHEAD_FALL_WAV, DEVICE_AUDIO_PLAY_ONCE);
                     */
                }
                gx_fruitninja_item[i].y = gx_fruitninja_item[i].y + ITEM_FALLCUT_SPEED;
            }

            gx_fruitninja_item[i].tick += 1;
            break;

        case ITEM_KICK_AWAY_LEFT:
            if (gx_fruitninja_item[i].x < 0) /* leave screen */
            {
                gx_fruitninja_item[i].mission = ITEM_OFF;
            }
            else
            {
                gx_fruitninja_item[i].x = gx_fruitninja_item[i].x - 8;
                gx_fruitninja_item[i].y = gx_fruitninja_item[i].y - 4;
            }
            break;

        case ITEM_KICK_AWAY_RIGHT:
            if (gx_fruitninja_item[i].x > MMI_GX_FRUITNINJA_LCD_WIDTH)    /* out screen */
            {
                gx_fruitninja_item[i].mission = ITEM_OFF;
            }
            else
            {
                gx_fruitninja_item[i].x = gx_fruitninja_item[i].x + 8;
                gx_fruitninja_item[i].y = gx_fruitninja_item[i].y - 4;
            }
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_notescore
 * DESCRIPTION
 *  handle score/damage issue for item reached the monster
 * PARAMETERS
 *  i       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_notescore(S16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gx_fruitninja_item[i].piece) /* note score */
    {
        case ITEM_1P:
            if (gx_fruitninja_item[i].type != ITEM_ROCK)
            {
                gx_fruitninja_monster_life[gx_fruitninja_item[i].column] -= MONSTER_DAMAGE_FRUIT;
            }
            else
            {
                gx_fruitninja_monster_life[gx_fruitninja_item[i].column] -= MONSTER_DAMAGE_ROCK;
            }

            gx_fruitninja_combo = 0;
            gx_fruitninja_treasure.nextcombo = TREASURE_COMBO;
            gx_fruitninja_monster_damage_tick[gx_fruitninja_item[i].column] = 10;
            GFX_PLAY_VIBRATION();

            break;

        case ITEM_2P:
            g_gx_fruitninja_context.game_grade = mmi_gfx_cal_grade(g_gx_fruitninja_context.game_grade, SCORE_2P);
            gx_fruitninja_combo = 0;
            gx_fruitninja_treasure.nextcombo = TREASURE_COMBO;
            break;

        case ITEM_3P:
            g_gx_fruitninja_context.game_grade = mmi_gfx_cal_grade(g_gx_fruitninja_context.game_grade, SCORE_3P);
            break;

        case ITEM_MP:
            if (gx_fruitninja_combo < COMBO_LV1)
            {
                g_gx_fruitninja_context.game_grade = mmi_gfx_cal_grade(g_gx_fruitninja_context.game_grade, SCORE_MPLV0);
            }
            else if (gx_fruitninja_combo < COMBO_LV2)
            {
                g_gx_fruitninja_context.game_grade = mmi_gfx_cal_grade(g_gx_fruitninja_context.game_grade, SCORE_MPLV1);
            }
            else if (gx_fruitninja_combo < COMBO_LV3)
            {
                g_gx_fruitninja_context.game_grade = mmi_gfx_cal_grade(g_gx_fruitninja_context.game_grade, SCORE_MPLV2);
            }
            else
            {
                g_gx_fruitninja_context.game_grade = mmi_gfx_cal_grade(g_gx_fruitninja_context.game_grade, SCORE_MPLV3);
            }

            gx_fruitninja_combo = (gx_fruitninja_combo < 0xFF)?(gx_fruitninja_combo + 1):0xFF;
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_collision
 * DESCRIPTION
 *  return if the two item encounter
 * PARAMETERS
 *  a_x             [IN]
 *  a_y             [IN]
 *  a_width         [IN]
 *  a_height        [IN]
 *  b_x             [IN]
 *  b_y             [IN]
 *  b_width         [IN]
 *  b_height        [IN]
 *  x_margin        [IN]
 *  y_margin        [IN]
 *  position(?)     [IN]        Width,height and two-way margin
 * RETURNS
 * BOOL
 *
 *****************************************************************************/
BOOL mmi_gx_fruitninja_collision(
    S16 a_x,
    S16 a_y,
    U8 a_width,
    U8 a_height,
    S16 b_x,
    S16 b_y,
    U8 b_width,
    U8 b_height,
    U8 x_margin,
    U8 y_margin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (a_x + x_margin < b_x + b_width)
        if (a_x + a_width - x_margin > b_x)
            if (a_y + y_margin < b_y + b_height)
                if (a_y + a_height - y_margin > b_y)
                {
                    return TRUE;
                }

    /* else */
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_fruitninja_bgm_play
 * DESCRIPTION
 *  play background music
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_fruitninja_bgm_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_fruitninja_context.is_gameover == FALSE)
    {
        GFX_PLAY_AUDIO_MIDI(fruitninja_background_music_mid, FRUITNINJA_BACKGROUND_MUSIC_MID, DEVICE_AUDIO_PLAY_INFINITE);
    }

}

#endif  //__MMI_GAME_FRUITNINJA__ 

